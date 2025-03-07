//##protect##"disclaimer"
/**************************************************************************

Filename    :   AS3_Obj_Media_SoundLoaderContext.cpp
Content     :   
Created     :   Jan, 2010
Authors     :   Sergey Sikorskiy

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/
//##protect##"disclaimer"

#include "AS3_Obj_Media_SoundLoaderContext.h"
#include "../../AS3_VM.h"
#include "../../AS3_Marshalling.h"
//##protect##"includes"
//##protect##"includes"


namespace Scaleform { namespace GFx { namespace AS3 
{

//##protect##"methods"
//##protect##"methods"

// Values of default arguments.
namespace Impl
{

} // namespace Impl

namespace Instances { namespace fl_media
{
    SoundLoaderContext::SoundLoaderContext(InstanceTraits::Traits& t)
    : Instances::fl::Object(t)
    , bufferTime(1000)
    , checkPolicyFile(false)
//##protect##"instance::SoundLoaderContext::SoundLoaderContext()$data"
//##protect##"instance::SoundLoaderContext::SoundLoaderContext()$data"
    {
//##protect##"instance::SoundLoaderContext::SoundLoaderContext()$code"
//##protect##"instance::SoundLoaderContext::SoundLoaderContext()$code"
    }


//##protect##"instance$methods"
//##protect##"instance$methods"

}} // namespace Instances

namespace InstanceTraits { namespace fl_media
{
    const MemberInfo SoundLoaderContext::mi[SoundLoaderContext::MemberInfoNum] = {
        {"bufferTime", NULL, OFFSETOF(Instances::fl_media::SoundLoaderContext, bufferTime), Abc::NS_Public, SlotInfo::BT_Number, 0},
        {"checkPolicyFile", NULL, OFFSETOF(Instances::fl_media::SoundLoaderContext, checkPolicyFile), Abc::NS_Public, SlotInfo::BT_Boolean, 0},
    };


    SoundLoaderContext::SoundLoaderContext(VM& vm, const ClassInfo& ci)
    : CTraits(vm, ci)
    {
//##protect##"InstanceTraits::SoundLoaderContext::SoundLoaderContext()"
//##protect##"InstanceTraits::SoundLoaderContext::SoundLoaderContext()"
        SetMemSize(sizeof(Instances::fl_media::SoundLoaderContext));

    }

    void SoundLoaderContext::MakeObject(Value& result, Traits& t)
    {
        result = MakeInstance(static_cast<SoundLoaderContext&>(t));
    }

//##protect##"instance_traits$methods"
//##protect##"instance_traits$methods"

}} // namespace InstanceTraits


namespace ClassTraits { namespace fl_media
{
    SoundLoaderContext::SoundLoaderContext(VM& vm)
    : Traits(vm, AS3::fl_media::SoundLoaderContextCI)
    {
//##protect##"ClassTraits::SoundLoaderContext::SoundLoaderContext()"
//##protect##"ClassTraits::SoundLoaderContext::SoundLoaderContext()"
        MemoryHeap* mh = vm.GetMemoryHeap();

        Pickable<InstanceTraits::Traits> it(SF_HEAP_NEW_ID(mh, StatMV_VM_ITraits_Mem) InstanceTraits::fl_media::SoundLoaderContext(vm, AS3::fl_media::SoundLoaderContextCI));
        SetInstanceTraits(it);

        // There is no problem with Pickable not assigned to anything here. Class constructor takes care of this.
        Pickable<Class> cl(SF_HEAP_NEW_ID(mh, StatMV_VM_Class_Mem) Class(*this));

    }

    Pickable<Traits> SoundLoaderContext::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(SF_HEAP_NEW_ID(vm.GetMemoryHeap(), StatMV_VM_CTraits_Mem) SoundLoaderContext(vm));
    }
//##protect##"ClassTraits$methods"
//##protect##"ClassTraits$methods"

}} // namespace ClassTraits

namespace fl_media
{
    const TypeInfo SoundLoaderContextTI = {
        TypeInfo::CompileTime | TypeInfo::NotImplemented,
        "SoundLoaderContext", "flash.media", &fl::ObjectTI,
        TypeInfo::None
    };

    const ClassInfo SoundLoaderContextCI = {
        &SoundLoaderContextTI,
        ClassTraits::fl_media::SoundLoaderContext::MakeClassTraits,
        0,
        0,
        0,
        InstanceTraits::fl_media::SoundLoaderContext::MemberInfoNum,
        NULL,
        NULL,
        NULL,
        InstanceTraits::fl_media::SoundLoaderContext::mi,
    };
}; // namespace fl_media


}}} // namespace Scaleform { namespace GFx { namespace AS3

