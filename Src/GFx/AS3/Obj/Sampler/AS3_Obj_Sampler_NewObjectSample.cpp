//##protect##"disclaimer"
/**************************************************************************

Filename    :   AS3_Obj_Sampler_NewObjectSample.cpp
Content     :   
Created     :   Jan, 2010
Authors     :   Sergey Sikorskiy

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/
//##protect##"disclaimer"

#include "AS3_Obj_Sampler_NewObjectSample.h"
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

namespace Instances { namespace fl_sampler
{
    NewObjectSample::NewObjectSample(InstanceTraits::Traits& t)
    : Instances::fl_sampler::Sample(t)
    , id()
    , type()
//##protect##"instance::NewObjectSample::NewObjectSample()$data"
//##protect##"instance::NewObjectSample::NewObjectSample()$data"
    {
//##protect##"instance::NewObjectSample::NewObjectSample()$code"
//##protect##"instance::NewObjectSample::NewObjectSample()$code"
    }


//##protect##"instance$methods"
//##protect##"instance$methods"

}} // namespace Instances

namespace InstanceTraits { namespace fl_sampler
{
    const ThunkInfo NewObjectSample::ti[NewObjectSample::ThunkInfoNum] = {
        {ThunkInfo::EmptyFunc, NULL, "object", NULL, Abc::NS_Public, CT_Get, 0, 0},
    };
    const MemberInfo NewObjectSample::mi[NewObjectSample::MemberInfoNum] = {
        {"id", NULL, OFFSETOF(Instances::fl_sampler::NewObjectSample, id), Abc::NS_Public, SlotInfo::BT_Number, 1},
        {"type", NULL, OFFSETOF(Instances::fl_sampler::NewObjectSample, type), Abc::NS_Public, SlotInfo::BT_ObjectCpp, 1},
    };


    NewObjectSample::NewObjectSample(VM& vm, const ClassInfo& ci)
    : CTraits(vm, ci)
    {
//##protect##"InstanceTraits::NewObjectSample::NewObjectSample()"
//##protect##"InstanceTraits::NewObjectSample::NewObjectSample()"
        SetMemSize(sizeof(Instances::fl_sampler::NewObjectSample));

    }

    void NewObjectSample::MakeObject(Value& result, Traits& t)
    {
        result = MakeInstance(static_cast<NewObjectSample&>(t));
    }

//##protect##"instance_traits$methods"
//##protect##"instance_traits$methods"

}} // namespace InstanceTraits


namespace ClassTraits { namespace fl_sampler
{
    NewObjectSample::NewObjectSample(VM& vm)
    : Traits(vm, AS3::fl_sampler::NewObjectSampleCI)
    {
//##protect##"ClassTraits::NewObjectSample::NewObjectSample()"
//##protect##"ClassTraits::NewObjectSample::NewObjectSample()"
        MemoryHeap* mh = vm.GetMemoryHeap();

        Pickable<InstanceTraits::Traits> it(SF_HEAP_NEW_ID(mh, StatMV_VM_ITraits_Mem) InstanceTraits::fl_sampler::NewObjectSample(vm, AS3::fl_sampler::NewObjectSampleCI));
        SetInstanceTraits(it);

        // There is no problem with Pickable not assigned to anything here. Class constructor takes care of this.
        Pickable<Class> cl(SF_HEAP_NEW_ID(mh, StatMV_VM_Class_Mem) Class(*this));

    }

    Pickable<Traits> NewObjectSample::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(SF_HEAP_NEW_ID(vm.GetMemoryHeap(), StatMV_VM_CTraits_Mem) NewObjectSample(vm));
    }
//##protect##"ClassTraits$methods"
//##protect##"ClassTraits$methods"

}} // namespace ClassTraits

namespace fl_sampler
{
    const TypeInfo NewObjectSampleTI = {
        TypeInfo::CompileTime | TypeInfo::Final | TypeInfo::NotImplemented,
        "NewObjectSample", "flash.sampler", &fl_sampler::SampleTI,
        TypeInfo::None
    };

    const ClassInfo NewObjectSampleCI = {
        &NewObjectSampleTI,
        ClassTraits::fl_sampler::NewObjectSample::MakeClassTraits,
        0,
        0,
        InstanceTraits::fl_sampler::NewObjectSample::ThunkInfoNum,
        InstanceTraits::fl_sampler::NewObjectSample::MemberInfoNum,
        NULL,
        NULL,
        InstanceTraits::fl_sampler::NewObjectSample::ti,
        InstanceTraits::fl_sampler::NewObjectSample::mi,
    };
}; // namespace fl_sampler


}}} // namespace Scaleform { namespace GFx { namespace AS3

