Source: sf_video_4.6.33_windows_msvc11_lib.zip

Changes:
- removed expiration check & other annoying checks
- patched encoder/muxer to allow 4K encoding
- applied 4GB patch to all executables so they can use more than 2GB of RAM.

Modified files:
- Bin\Tools\VideoEncoder\crispeee_tgt_sofdec2.dll
- Bin\Tools\VideoEncoder\crispeee_x264.dll
- Bin\Tools\VideoEncoder\medianoche.exe
- Bin\Tools\VideoEncoder\medianocheH264.exe
- Bin\Tools\VideoEncoder\ScaleformVideoEncoder.exe

Removed files:
- Bin\Tools\VideoEncoder\CriFlexGuard.dll
- Bin\Tools\VideoEncoder\crispeee_x264.cfg
- Bin\Tools\VideoEncoder\crispeee_x264.lic
- Bin\Tools\VideoEncoder\medianoche.lic

Interesting things:
- medianocheH264.exe only handles H264 encoding, for muxing into USM container it calls medianoche.exe - this means that you can actually encode your video into H264 using any encoder (eg. a newer H264 encoder than the ~2017 version used here), and medianoche.exe will usually mux most H264 videos into USM format without issue
- medianocheH264.exe calls into crispeee_x264.dll as if it was an EXE file - you can actually run that file from inside command-prompt like a normal EXE file too
- I'd guess the expiration/license stuff is likely why SFVideo / CriMana tools have rarely shown up in recent years, fortunately the protection used here was very weak, if you have access to any SF/CriMana things maybe consider sharing with the rest of us :)
