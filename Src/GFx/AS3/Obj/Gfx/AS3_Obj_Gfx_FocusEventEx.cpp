//##protect##"disclaimer"
/**************************************************************************

Filename    :   AS3_Obj_Gfx_FocusEventEx.cpp
Content     :   
Created     :   Jan, 2010
Authors     :   Sergey Sikorskiy

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/
//##protect##"disclaimer"

#include "AS3_Obj_Gfx_FocusEventEx.h"
#include "../../AS3_VM.h"
#include "../../AS3_Marshalling.h"
//##protect##"includes"
#include "../../AS3_MovieRoot.h"
//##protect##"includes"


namespace Scaleform { namespace GFx { namespace AS3 
{

//##protect##"methods"
//##protect##"methods"

// Values of default arguments.
namespace Impl
{

} // namespace Impl

namespace Instances { namespace fl_gfx
{
    FocusEventEx::FocusEventEx(InstanceTraits::Traits& t)
    : Instances::fl_events::FocusEvent(t)
    , controllerIdx()
//##protect##"instance::FocusEventEx::FocusEventEx()$data"
//##protect##"instance::FocusEventEx::FocusEventEx()$data"
    {
//##protect##"instance::FocusEventEx::FocusEventEx()$code"
//##protect##"instance::FocusEventEx::FocusEventEx()$code"
    }


//##protect##"instance$methods"
    AS3::Object* FocusEventEx::GetEventClass() const 
    { 
        return static_cast<ASVM&>(GetVM()).FocusEventExClass; 
    }

    SPtr<Instances::fl_events::Event> FocusEventEx::Clone() const
    {
        SPtr<Instances::fl_events::Event> p = Event::Clone();
        FocusEventEx* pe = static_cast<FocusEventEx*>(p.GetPtr());
        pe->RelatedObj = RelatedObj;
        pe->ShiftKey   = ShiftKey;
        pe->KeyCode    = KeyCode;
        pe->controllerIdx = controllerIdx;
        return p;
    }
//##protect##"instance$methods"

}} // namespace Instances

namespace InstanceTraits { namespace fl_gfx
{
    const MemberInfo FocusEventEx::mi[FocusEventEx::MemberInfoNum] = {
        {"controllerIdx", NULL, OFFSETOF(Instances::fl_gfx::FocusEventEx, controllerIdx), Abc::NS_Public, SlotInfo::BT_UInt, 0},
    };


    FocusEventEx::FocusEventEx(VM& vm, const ClassInfo& ci)
    : CTraits(vm, ci)
    {
//##protect##"InstanceTraits::FocusEventEx::FocusEventEx()"
//##protect##"InstanceTraits::FocusEventEx::FocusEventEx()"
        SetMemSize(sizeof(Instances::fl_gfx::FocusEventEx));

    }

    void FocusEventEx::MakeObject(Value& result, Traits& t)
    {
        result = MakeInstance(static_cast<FocusEventEx&>(t));
    }

//##protect##"instance_traits$methods"
//##protect##"instance_traits$methods"

}} // namespace InstanceTraits


namespace ClassTraits { namespace fl_gfx
{
    FocusEventEx::FocusEventEx(VM& vm)
    : Traits(vm, AS3::fl_gfx::FocusEventExCI)
    {
//##protect##"ClassTraits::FocusEventEx::FocusEventEx()"
//##protect##"ClassTraits::FocusEventEx::FocusEventEx()"
        MemoryHeap* mh = vm.GetMemoryHeap();

        Pickable<InstanceTraits::Traits> it(SF_HEAP_NEW_ID(mh, StatMV_VM_ITraits_Mem) InstanceTraits::fl_gfx::FocusEventEx(vm, AS3::fl_gfx::FocusEventExCI));
        SetInstanceTraits(it);

        // There is no problem with Pickable not assigned to anything here. Class constructor takes care of this.
        Pickable<Class> cl(SF_HEAP_NEW_ID(mh, StatMV_VM_Class_Mem) Class(*this));

    }

    Pickable<Traits> FocusEventEx::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(SF_HEAP_NEW_ID(vm.GetMemoryHeap(), StatMV_VM_CTraits_Mem) FocusEventEx(vm));
    }
//##protect##"ClassTraits$methods"
//##protect##"ClassTraits$methods"

}} // namespace ClassTraits

namespace fl_gfx
{
    const TypeInfo FocusEventExTI = {
        TypeInfo::CompileTime | TypeInfo::Final,
        "FocusEventEx", "scaleform.gfx", &fl_events::FocusEventTI,
        TypeInfo::None
    };

    const ClassInfo FocusEventExCI = {
        &FocusEventExTI,
        ClassTraits::fl_gfx::FocusEventEx::MakeClassTraits,
        0,
        0,
        0,
        InstanceTraits::fl_gfx::FocusEventEx::MemberInfoNum,
        NULL,
        NULL,
        NULL,
        InstanceTraits::fl_gfx::FocusEventEx::mi,
    };
}; // namespace fl_gfx


}}} // namespace Scaleform { namespace GFx { namespace AS3

