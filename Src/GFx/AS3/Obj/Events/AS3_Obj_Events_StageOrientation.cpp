//##protect##"disclaimer"
/**************************************************************************

Filename    :   AS3_Obj_Events_StageOrientation.cpp
Content     :   
Created     :   Jan, 2010
Authors     :   Sergey Sikorskiy

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/
//##protect##"disclaimer"

#include "AS3_Obj_Events_StageOrientation.h"
#include "../../AS3_VM.h"
#include "../../AS3_Marshalling.h"
//##protect##"includes"
//##protect##"includes"


namespace Scaleform { namespace GFx { namespace AS3 
{

//##protect##"methods"
//##protect##"methods"

namespace Classes { namespace fl_events
{
    StageOrientation::StageOrientation(ClassTraits::Traits& t)
    : Class(t)
    , DEFAULT("default")
    , ROTATED_LEFT("rotatedLeft")
    , ROTATED_RIGHT("rotatedRight")
    , UNKNOWN("unknown")
    , UPSIDE_DOWN("upsideDown")
    {
//##protect##"class_::StageOrientation::StageOrientation()"
//##protect##"class_::StageOrientation::StageOrientation()"
    }
//##protect##"class_$methods"
//##protect##"class_$methods"

}} // namespace Classes


namespace ClassTraits { namespace fl_events
{
    const MemberInfo StageOrientation::mi[StageOrientation::MemberInfoNum] = {
        {"DEFAULT", NULL, OFFSETOF(Classes::fl_events::StageOrientation, DEFAULT), Abc::NS_Public, SlotInfo::BT_ConstChar, 1},
        {"ROTATED_LEFT", NULL, OFFSETOF(Classes::fl_events::StageOrientation, ROTATED_LEFT), Abc::NS_Public, SlotInfo::BT_ConstChar, 1},
        {"ROTATED_RIGHT", NULL, OFFSETOF(Classes::fl_events::StageOrientation, ROTATED_RIGHT), Abc::NS_Public, SlotInfo::BT_ConstChar, 1},
        {"UNKNOWN", NULL, OFFSETOF(Classes::fl_events::StageOrientation, UNKNOWN), Abc::NS_Public, SlotInfo::BT_ConstChar, 1},
        {"UPSIDE_DOWN", NULL, OFFSETOF(Classes::fl_events::StageOrientation, UPSIDE_DOWN), Abc::NS_Public, SlotInfo::BT_ConstChar, 1},
    };

    StageOrientation::StageOrientation(VM& vm)
    : Traits(vm, AS3::fl_events::StageOrientationCI)
    {
//##protect##"ClassTraits::StageOrientation::StageOrientation()"
//##protect##"ClassTraits::StageOrientation::StageOrientation()"
        MemoryHeap* mh = vm.GetMemoryHeap();

        Pickable<InstanceTraits::Traits> it(SF_HEAP_NEW_ID(mh, StatMV_VM_ITraits_Mem) InstanceTraits::fl::Object(vm, AS3::fl_events::StageOrientationCI));
        SetInstanceTraits(it);

        // There is no problem with Pickable not assigned to anything here. Class constructor takes care of this.
        Pickable<Class> cl(SF_HEAP_NEW_ID(mh, StatMV_VM_Class_Mem) Classes::fl_events::StageOrientation(*this));

    }

    Pickable<Traits> StageOrientation::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(SF_HEAP_NEW_ID(vm.GetMemoryHeap(), StatMV_VM_CTraits_Mem) StageOrientation(vm));
    }
//##protect##"ClassTraits$methods"
//##protect##"ClassTraits$methods"

}} // namespace ClassTraits

namespace fl_events
{
    const TypeInfo StageOrientationTI = {
        TypeInfo::CompileTime | TypeInfo::Final,
        "StageOrientation", "flash.events", &fl::ObjectTI,
        TypeInfo::None
    };

    const ClassInfo StageOrientationCI = {
        &StageOrientationTI,
        ClassTraits::fl_events::StageOrientation::MakeClassTraits,
        0,
        ClassTraits::fl_events::StageOrientation::MemberInfoNum,
        0,
        0,
        NULL,
        ClassTraits::fl_events::StageOrientation::mi,
        NULL,
        NULL,
    };
}; // namespace fl_events


}}} // namespace Scaleform { namespace GFx { namespace AS3

