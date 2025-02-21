//##protect##"disclaimer"
/**********************************************************************

Filename    :   AS3_Obj_Media_Video.cpp
Content     :   
Created     :   Jan, 2010
Authors     :   Sergey Sikorskiy

Copyright   :   (c) 2010 Scaleform Corp. All Rights Reserved.

Notes       :   

Licensees may use this file in accordance with the valid Scaleform
Commercial License Agreement provided with the software.

This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING 
THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR ANY PURPOSE.

**********************************************************************/
//##protect##"disclaimer"

#include "AS3_Obj_Media_Video.h"
#include "../../AS3_VM.h"
//##protect##"includes"
#include "AS3_Obj_Media_Camera.h"
#include "../Net/AS3_Obj_Net_NetStream.h"
//##protect##"includes"


namespace Scaleform { namespace GFx { namespace AS3 
{
//##protect##"methods"
//##protect##"methods"

// Values of default arguments.
namespace Impl
{

} // namespace Impl

namespace Instances
{
    Video::Video(InstanceTraits::Traits& t)
    : Instances::DisplayObject(t)
//##protect##"instance::Video::Video()$data"
//##protect##"instance::Video::Video()$data"
    {
//##protect##"instance::Video::Video()$code"
//##protect##"instance::Video::Video()$code"
    }

    void Video::deblockingGet(SInt32& result)
    {
//##protect##"instance::Video::deblockingGet()"
        SF_UNUSED1(result);
        NOT_IMPLEMENTED("Video::deblockingGet()");
//##protect##"instance::Video::deblockingGet()"
    }
    void Video::deblockingSet(Value& result, SInt32 value)
    {
//##protect##"instance::Video::deblockingSet()"
        SF_UNUSED2(result, value);
        NOT_IMPLEMENTED("Video::deblockingSet()");
//##protect##"instance::Video::deblockingSet()"
    }
    void Video::smoothingGet(bool& result)
    {
//##protect##"instance::Video::smoothingGet()"
        SF_UNUSED1(result);
        NOT_IMPLEMENTED("Video::smoothingGet()");
//##protect##"instance::Video::smoothingGet()"
    }
    void Video::smoothingSet(Value& result, bool value)
    {
//##protect##"instance::Video::smoothingSet()"
        SF_UNUSED2(result, value);
        NOT_IMPLEMENTED("Video::smoothingSet()");
//##protect##"instance::Video::smoothingSet()"
    }
    void Video::videoHeightGet(SInt32& result)
    {
//##protect##"instance::Video::videoHeightGet()"
        SF_UNUSED1(result);
        NOT_IMPLEMENTED("Video::videoHeightGet()");
//##protect##"instance::Video::videoHeightGet()"
    }
    void Video::videoWidthGet(SInt32& result)
    {
//##protect##"instance::Video::videoWidthGet()"
        SF_UNUSED1(result);
        NOT_IMPLEMENTED("Video::videoWidthGet()");
//##protect##"instance::Video::videoWidthGet()"
    }
    void Video::attachCamera(Value& result, Instances::Camera* camera)
    {
//##protect##"instance::Video::attachCamera()"
        SF_UNUSED2(result, camera);
        NOT_IMPLEMENTED("Video::attachCamera()");
//##protect##"instance::Video::attachCamera()"
    }
    void Video::attachNetStream(Value& result, Instances::NetStream* netStream)
    {
//##protect##"instance::Video::attachNetStream()"
        SF_UNUSED2(result, netStream);
        NOT_IMPLEMENTED("Video::attachNetStream()");
//##protect##"instance::Video::attachNetStream()"
    }
    void Video::clear(Value& result)
    {
//##protect##"instance::Video::clear()"
        SF_UNUSED1(result);
        NOT_IMPLEMENTED("Video::clear()");
//##protect##"instance::Video::clear()"
    }

//##protect##"instance$methods"
//##protect##"instance$methods"

} // namespace Instances

namespace InstanceTraits
{
    Video::Video(VM& vm, const ASString& n, Pickable<Instances::Namespace> ns, Class& c)
    : Traits(vm, n, ns, c)
    {
//##protect##"InstanceTraits::Video::Video()"
//##protect##"InstanceTraits::Video::Video()"
        static ThunkInfo ti[] = {
            {MakeThunkFunc<Instances::Video::mid_deblockingGet>(&Instances::Video::deblockingGet), "media", "Video", "deblocking", NULL, CT_Get, 0, 0},
            {MakeThunkFunc<Instances::Video::mid_deblockingSet>(&Instances::Video::deblockingSet), "media", "Video", "deblocking", NULL, CT_Set, 1, 1},
            {MakeThunkFunc<Instances::Video::mid_smoothingGet>(&Instances::Video::smoothingGet), "media", "Video", "smoothing", NULL, CT_Get, 0, 0},
            {MakeThunkFunc<Instances::Video::mid_smoothingSet>(&Instances::Video::smoothingSet), "media", "Video", "smoothing", NULL, CT_Set, 1, 1},
            {MakeThunkFunc<Instances::Video::mid_videoHeightGet>(&Instances::Video::videoHeightGet), "media", "Video", "videoHeight", NULL, CT_Get, 0, 0},
            {MakeThunkFunc<Instances::Video::mid_videoWidthGet>(&Instances::Video::videoWidthGet), "media", "Video", "videoWidth", NULL, CT_Get, 0, 0},
            {MakeThunkFunc<Instances::Video::mid_attachCamera>(&Instances::Video::attachCamera), "media", "Video", "attachCamera", NULL, CT_Method, 1, 1},
            {MakeThunkFunc<Instances::Video::mid_attachNetStream>(&Instances::Video::attachNetStream), "media", "Video", "attachNetStream", NULL, CT_Method, 1, 1},
            {MakeThunkFunc<Instances::Video::mid_clear>(&Instances::Video::clear), "media", "Video", "clear", NULL, CT_Method, 0, 0},
        };
        for (unsigned i = 0; i < NUMBEROF(ti); ++i)
            Add2VT(ti[i]);

    }

    Pickable<Instances::Video> Video::MakeInstance()
    {
        return Pickable<Instances::Video>(SF_HEAP_NEW(GetVM().GetMemoryHeap()) Instances::Video(*this));
    }

    void Video::MakeObject(Value& result)
    {
        result = MakeInstance();
    }

//##protect##"instance_traits$methods"
//##protect##"instance_traits$methods"

} // namespace InstanceTraits

namespace Classes
{
    Video::Video(const ASString& n,
                 ClassTraits::Traits& t, Class& parent)
    : Class(n, t, &parent)
    {
        SF_ASSERT(t.SlotsAreBound2Values());
//##protect##"class_::Video::Video()"
//##protect##"class_::Video::Video()"
    }

    const char* Info<Video>::GetName() { return "Video"; }
    const char* Info<Video>::GetPkgName() { return "flash.media"; }
    const char* Info<Video>::GetParentName() { return Info<ParentType>::GetName(); }
    const char* Info<Video>::GetParentPkgName() { return Info<ParentType>::GetPkgName(); }
    Pickable<ClassTraits::Traits> Info<Video>::MakeClassTraits(VM& vm, const ClassTraits::Traits& parent)
    {
        SF_UNUSED(parent);
        return Pickable<ClassTraits::Traits>(SF_HEAP_NEW(vm.GetMemoryHeap()) ClassTraits::Video(vm, parent));
    }
//##protect##"class_$methods"
//##protect##"class_$methods"

} // namespace Classes

namespace ClassTraits
{
    Video::Video(VM& vm, const ClassTraits::Traits& pt)
    : Traits(vm, &pt)
    {

        SPtr<Class> cl(MakePickable(SF_HEAP_NEW(vm.GetMemoryHeap()) Classes::Video(
            GetStringManager().CreateConstString(Classes::Info<Classes::Video>::GetName()),
            *this,
            pt.GetInstanceTraits().GetClass())));
        Pickable<InstanceTraits::Video> it(SF_HEAP_NEW(vm.GetMemoryHeap()) InstanceTraits::Video(GetVM(), GetStringManager().CreateConstString(Classes::Info<Classes::Video>::GetName()), GetVM().MakeInternedNamespace(Abc::NS_Public, Classes::Info<Classes::Video>::GetPkgName()), *cl));
        SetInstanceTraits(it);

    }
//##protect##"ClassTraits$methods"
//##protect##"ClassTraits$methods"

} // namespace ClassTraits

}}} // namespace Scaleform { namespace GFx { namespace AS3

