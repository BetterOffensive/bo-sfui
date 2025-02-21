/**************************************************************************

Filename    :   VideoBGLoad.cpp
Content     :   Video background loading demo
                 Playing video while loading arbitrary data in the background
Created     :   Oct, 2009
Authors     :   Maxim Didenko, Vladislav Merker

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/

#include "FxPlayerAppBase.h"
#include "GameDataLoader.h"

#ifdef GFX_AS3_SUPPORT
#include "GFx/AS3/AS3_Global.h"
#endif

#include "Video/Video_Video.h"
#if defined(SF_OS_WIN32) && !defined(SF_OS_DURANGO)
#include "Video/Video_VideoWinAPI.h"
#elif defined(SF_OS_XBOX360)
#include "Video/Video_VideoXbox360.h"
#elif defined(SF_OS_PS3)
#include "Video/Video_VideoPS3.h"
#elif defined(SF_OS_DURANGO)
#include "Video/Video_VideoXboxOne.h"
#elif defined(SF_OS_ORBIS)
#include "Video/Video_VideoPS4.h"
#elif defined(SF_OS_WIIU)
#include "Video/Video_VideoWiiU.h"
#endif

using namespace Scaleform;
using namespace GFx;

//////////////////////////////////////////////////////////////////////////
//
class VideoReadCallback;

class VideoBGLoadApp : public FxPlayerAppBase
{
public:
    VideoBGLoadApp();

    virtual String GetAppTitle() const;
    virtual String GetFilePath() const;

    virtual bool   OnInit(Platform::ViewConfig& config);
    virtual void   OnUpdateFrame(bool needRepaint);
    virtual void   OnShutdown();
    virtual void   OnSizeEnter(bool enterFlag);

    virtual bool   OnArgs(const Platform::Args& args, Platform::Args::ParseResult parseResult);
    virtual void   InitArgDescriptions(Platform::Args* args);

    virtual void   InstallHandlers();

    int     ReadBufferSize;
    float   BufferTime;
    float   ReloadThreashold;
    bool    NoBGLoading;
    bool    NoReadCallBack;

#ifdef GFX_ENABLE_VIDEO
    Ptr<Video::Video>       pVideo;
    Ptr<VideoReadCallback>  pVideoReadCallback;
    Video::VideoDecoder*    pVideoDecoder;
#endif
    GameDataLoader*         pDataLoader;

    String  DataFileName;
};

//////////////////////////////////////////////////////////////////////////
//

// Restart game data loading command handler
class CommandReloadData : public FxPlayerCommand
{
public:
    virtual void Execute(FxPlayerAppBase* app, unsigned controllerIdx, bool keyDown) const
    {
        SF_UNUSED2(controllerIdx, keyDown);

        VideoBGLoadApp* videoApp = (VideoBGLoadApp*)app;
        if (videoApp && videoApp->pDataLoader)
            videoApp->pDataLoader->Restart();
    }
    virtual String GetHelpString() const
    {
        return "Restart game data loading";
    }
};

// FSCommand handler
class FSCallback : public FSCommandHandler
{
public:
    FSCallback(FxPlayerAppBase* papp) : pApp(papp) {}
    virtual void Callback(Movie* pmovie, const char* pcommand, const char* parg)
    {
        Ptr<GFx::Log> plog = pmovie->GetLog();
        if (plog)
        {
            plog->LogMessage("FsCallback: '");
            plog->LogMessage("%s", pcommand);
            plog->LogMessage("' '");
            plog->LogMessage("%s", parg);
            plog->LogMessage("'\n");
        }
        if (SFstrcmp(pcommand, "LoadingRestart") == 0)
        {
            VideoBGLoadApp* videoApp = (VideoBGLoadApp*)pApp;
            if (videoApp && videoApp->pDataLoader)
                videoApp->pDataLoader->Restart();
        }
        pApp->HandleFsCommand(pcommand, parg);
    }

protected:
    FxPlayerAppBase* pApp;
};

// Read callback implementation for the video system
#ifdef GFX_ENABLE_VIDEO
class VideoReadCallback : public Video::VideoBase::ReadCallback
{
public:
    VideoReadCallback(GameDataLoader* pdataLoader) : pDataLoader(pdataLoader)
    {
        VideoReadStart = Timer::GetTicks();
        GameReadStart  = Timer::GetTicks();
    }
    virtual ~VideoReadCallback() {}

    virtual void OnReadRequested()
    {
        // Video read started
        if (pDataLoader)
            pDataLoader->Enable(false);
        VideoReadStart = Timer::GetTicks();
    }
    virtual void OnReadCompleted()
    {
        // Video read completed
        GameReadStart = Timer::GetTicks();
        if (pDataLoader)
            pDataLoader->Enable(true);
    }

    void SetDataLoader(GameDataLoader* ploader) { pDataLoader = ploader; }

    GameDataLoader* pDataLoader;
    UInt64 VideoReadStart;
    UInt64 GameReadStart;
};
#endif // GFX_ENABLE_VIDEO

//////////////////////////////////////////////////////////////////////////
//

VideoBGLoadApp::VideoBGLoadApp() : FxPlayerAppBase()
{
    ReadBufferSize   = 128 * 1024;
    BufferTime       = 2.0f;
    ReloadThreashold = 1.0f;
    NoBGLoading      = false;
    NoReadCallBack   = false;
#ifdef GFX_ENABLE_VIDEO
    pVideoDecoder    = NULL;
#endif
    pDataLoader      = NULL;

    String filePath = GetFilePath();
    DataFileName = filePath.GetPath() + "big_data.dat";

    UInt32 ctrlMask = (KeyModifiers::Key_CtrlPressed << 16);
    KeyCommandMap.Set(Key::R|ctrlMask, *SF_NEW CommandReloadData());

#if defined(SF_OS_XBOX360) || defined(SF_OS_WIN32)
    KeyCommandMap.Set(Pad_Y, *SF_NEW CommandReloadData());
#elif defined(SF_OS_PS3)
    KeyCommandMap.Set(Pad_T, *SF_NEW CommandReloadData());
#endif
}

String VideoBGLoadApp::GetAppTitle() const
{
    // Demo title & version
    String title("Video Background Loading Demo");
    title += " v " GFX_VERSION_STRING;
    return title;
}

String VideoBGLoadApp::GetFilePath() const
{
#if defined(SF_OS_WIN32)
    return "..\\..\\..\\..\\Data\\AS2\\Video\\VideoBGLoad.swf";
#elif defined(SF_OS_MAC)
    return String(GetDefaultFilePath()) + "/Contents/VideoBGLoad.swf";
#elif defined(SF_OS_LINUX) && !defined(SF_OS_ANDROID)
    return "Bin/Data/AS2/Video/VideoBGLoad.swf";
#elif defined(SF_OS_XBOX360)
    return "D:\\Video\\VideoBGLoad.swf";
#elif defined(SF_OS_PS3)
    return SYS_APP_HOME "/VideoBGLoad.swf";
#else
    return String(GetDefaultFilePath()) + "VideoBGLoad.swf";
#endif
}

bool VideoBGLoadApp::OnInit(Platform::ViewConfig& config)
{
    if (!FxPlayerAppBase::OnInit(config))
        return false;

#ifdef GFX_ENABLE_VIDEO
    // Set video state
#if defined(SF_OS_WIN32) && !defined(SF_OS_DURANGO)
    UInt32 affinityMasks[] = {
        DEFAULT_VIDEO_DECODING_AFFINITY_MASK,
        DEFAULT_VIDEO_DECODING_AFFINITY_MASK,
        DEFAULT_VIDEO_DECODING_AFFINITY_MASK
    };
    pVideo = *new Video::VideoPC(Video::VideoVMSupportAS2(),
                                 Thread::NormalPriority, MAX_VIDEO_DECODING_THREADS, affinityMasks);
#elif defined(SF_OS_XBOX360)
    pVideo = *new Video::VideoXbox360(Video::VideoVMSupportAS2(),
                                      Video::Xbox360_Proc3|Video::Xbox360_Proc4|Video::Xbox360_Proc5,
                                      Thread::NormalPriority, Video::Xbox360_Proc2);
#elif defined(SF_OS_PS3)
    UInt8 spursPrios[] = {0, 0, 1, 1, 0, 0, 0, 0};
    pVideo = *new Video::VideoPS3(Video::VideoVMSupportAS2(),
                                  GetSpurs(), 1, Thread::NormalPriority, 2, spursPrios);
#elif defined(SF_OS_DURANGO)
    DWORD_PTR affinityMasks[] = {
        Video::XboxOneAffinityMask::CPU2,
        Video::XboxOneAffinityMask::CPU3 | Video::XboxOneAffinityMask::CPU4,
        Video::XboxOneAffinityMask::AllCPUs
    };
    pVideo = *new Video::VideoXboxOne(Video::VideoVMSupportAll(),
                                      Thread::NormalPriority, 3, affinityMasks);
#elif defined(SF_OS_ORBIS)
    SceKernelCpumask affinityMasks[] = {
        Video::PS4AffinityMask::CPU2,
        Video::PS4AffinityMask::CPU3 | Video::PS4AffinityMask::CPU4,
        Video::PS4AffinityMask::AllCPUs
    };
    pVideo = *new Video::VideoPS4(Video::VideoVMSupportAll(),
                                  Thread::NormalPriority, 3, affinityMasks);
#elif defined(SF_OS_WIIU)
    u16 affinityMasks[] = {
        OS_THREAD_ATTR_AFFINITY_CORE1,
        OS_THREAD_ATTR_AFFINITY_CORE2
    };
    pVideo = *new Video::VideoWiiU(Video::VideoVMSupportAll(),
                                   Thread::NormalPriority, 2, affinityMasks);
#else
    pVideo = *new Video::Video(Video::VideoVMSupportAS2(), Thread::NormalPriority);
#endif

    // Init data loader and set video read callback
    pDataLoader = new GameDataLoader;
    pVideoReadCallback = *new VideoReadCallback(pDataLoader);
    if (!NoReadCallBack)
        pVideo->SetReadCallback(pVideoReadCallback);
    mLoader.SetVideo(pVideo);

    // Set texture manager
    pVideo->SetTextureManager(GetRenderThread()->GetTextureManager());

    // Set audio state
#ifdef GFX_ENABLE_SOUND
    Sound::SoundRenderer* psoundRenderer = GetSoundRenderer();
    if (psoundRenderer)
    {
        Ptr<Audio> paudio = *new Audio(psoundRenderer);
        mLoader.SetAudio(paudio);
        pVideo->SetSoundSystem(psoundRenderer);
    }
#endif

    // Start loading game data
    if (!NoBGLoading)
        pDataLoader->LoadFile(DataFileName, ReadBufferSize);

#endif // GFX_ENABLE_VIDEO

    // Enable cursor on consoles
#if defined(SF_OS_XBOX360) || defined(SF_OS_PS3)
    EnableCursor(true);
    if (pMovie)
        pMovie->SetMouseCursorCount(1);
#endif

    return true;
}

void VideoBGLoadApp::OnUpdateFrame(bool needRepaint)
{
    FxPlayerAppBase::OnUpdateFrame(needRepaint);

    static bool bPlaybackStarted = false;
    if (!bPlaybackStarted && pMovie)
    {
        pMovie->Invoke("_root.SetReadBufferParam", "%f %f", BufferTime, ReloadThreashold);
        pMovie->Invoke("_root.StartVideo", "");
        bPlaybackStarted = true;
    }

#ifdef GFX_ENABLE_VIDEO
    // Update game data loading progress bar
    if (!NoBGLoading)
    {
        int progress = (int)pDataLoader->GetProcess();
        if (pMovie)
            pMovie->Invoke("_root.OnProgressChanged", "%d", progress);
    }

    if (!pVideoDecoder)
        pVideoDecoder = pVideo->GetDecoder();

    // Update input buffer information display
    if (pVideoDecoder)
    {
        Array<Video::VideoPlayer::ReadBufferInfo> info;
        pVideoDecoder->GetReadBufferInfo(info);
        if(info.GetSize() > 0 && pMovie)
            pMovie->Invoke("_root.UpdateBufferInfo", "%d %d %d",
            info[0].DataSize,
            info[0].BufferSize,
            info[0].ReloadThreshold);
    }

    // If no video read callback set we can separate loading of game data
    // and video by using Video::IsIORequired()
    static bool gameDataLoading = false;
    if (NoReadCallBack && !NoBGLoading)
    {
        if (gameDataLoading)
        {
            if(pVideo->IsIORequired())
            {
                gameDataLoading = false;
                pDataLoader->Enable(false);
                pVideo->EnableIO(true);
            }
        }
        else {
            if (!pVideo->IsIORequired())
            {
                pVideo->EnableIO(false);
                pDataLoader->Enable(true);
                gameDataLoading = true;
            }
        }
    }
#endif // GFX_ENABLE_VIDEO
}

void VideoBGLoadApp::OnShutdown()
{
    FxPlayerAppBase::OnShutdown();

#ifdef GFX_ENABLE_VIDEO
    pVideoReadCallback->SetDataLoader(NULL);
#endif
    delete pDataLoader;
    pDataLoader = NULL;
}

void VideoBGLoadApp::OnSizeEnter(bool enterFlag)
{
#ifdef GFX_ENABLE_VIDEO
    if (pVideoDecoder)
        pVideoDecoder->PauseDecoding(enterFlag);
#endif

    FxPlayerAppBase::OnSizeEnter(enterFlag);
}

bool VideoBGLoadApp::OnArgs(const Platform::Args& args, Platform::Args::ParseResult parseResult)
{
    if (!FxPlayerAppBase::OnArgs(args, parseResult))
        return false;

    // Game data file
    if (args.HasValue("DataFile"))
        DataFileName = args.GetString("DataFile");

    ReadBufferSize   = args.GetInt("bs");
    BufferTime       = args.GetFloat("bt");
    ReloadThreashold = args.GetFloat("rh");
    NoBGLoading      = args.GetBool("noBGL");
    NoReadCallBack   = args.GetBool("noRC");

    return true;
}

void VideoBGLoadApp::InitArgDescriptions(Platform::Args* args)
{
    using namespace Platform;
    FxPlayerAppBase::InitArgDescriptions(args);

    ArgDesc options[] = {
        {"",      "DataFile",        Args::StringOption|Args::Positional, NULL, "Data file to load"},
        {"bt",    "BufferTime",      Args::FloatOption, "2.0",    "Buffer time (2.0s)" },
        {"rh",    "ReloadThreshold", Args::FloatOption, "1.0",    "Reload threshold (1.0s)" },
        {"bs",    "ReadBufferSize",  Args::IntOption,   "131072", "Size of read buffer (128k)"},
        {"nobgl", "noBGL",           Args::Flag, "", "No background loading"},
        {"norc",  "noRC",            Args::Flag, "", "No read callback"},
        {"", "", Args::ArgEnd, "", ""},
    };
    args->AddDesriptions(options);
}

void VideoBGLoadApp::InstallHandlers()
{
    pMovie->SetFSCommandHandler(Ptr<FSCommandHandler>(*new FSCallback(this)));
}

//////////////////////////////////////////////////////////////////////////
//

SF_PLATFORM_SYSTEM_APP(VideoBGLoad, Scaleform::GFx::System, VideoBGLoadApp)
