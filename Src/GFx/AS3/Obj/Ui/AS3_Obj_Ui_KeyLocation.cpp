//##protect##"disclaimer"
/**************************************************************************

Filename    :   AS3_Obj_Ui_KeyLocation.cpp
Content     :   
Created     :   Jan, 2010
Authors     :   Sergey Sikorskiy

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/
//##protect##"disclaimer"

#include "AS3_Obj_Ui_KeyLocation.h"
#include "../../AS3_VM.h"
#include "../../AS3_Marshalling.h"
//##protect##"includes"
//##protect##"includes"


namespace Scaleform { namespace GFx { namespace AS3 
{

//##protect##"methods"
//##protect##"methods"

namespace Classes { namespace fl_ui
{
    KeyLocation::KeyLocation(ClassTraits::Traits& t)
    : Class(t)
    , LEFT(1)
    , NUM_PAD(3)
    , RIGHT(2)
    , STANDARD(0)
    {
//##protect##"class_::KeyLocation::KeyLocation()"
//##protect##"class_::KeyLocation::KeyLocation()"
    }
//##protect##"class_$methods"
//##protect##"class_$methods"

}} // namespace Classes


namespace ClassTraits { namespace fl_ui
{
    const MemberInfo KeyLocation::mi[KeyLocation::MemberInfoNum] = {
        {"LEFT", NULL, OFFSETOF(Classes::fl_ui::KeyLocation, LEFT), Abc::NS_Public, SlotInfo::BT_UInt, 1},
        {"NUM_PAD", NULL, OFFSETOF(Classes::fl_ui::KeyLocation, NUM_PAD), Abc::NS_Public, SlotInfo::BT_UInt, 1},
        {"RIGHT", NULL, OFFSETOF(Classes::fl_ui::KeyLocation, RIGHT), Abc::NS_Public, SlotInfo::BT_UInt, 1},
        {"STANDARD", NULL, OFFSETOF(Classes::fl_ui::KeyLocation, STANDARD), Abc::NS_Public, SlotInfo::BT_UInt, 1},
    };

    KeyLocation::KeyLocation(VM& vm)
    : Traits(vm, AS3::fl_ui::KeyLocationCI)
    {
//##protect##"ClassTraits::KeyLocation::KeyLocation()"
//##protect##"ClassTraits::KeyLocation::KeyLocation()"
        MemoryHeap* mh = vm.GetMemoryHeap();

        Pickable<InstanceTraits::Traits> it(SF_HEAP_NEW_ID(mh, StatMV_VM_ITraits_Mem) InstanceTraits::fl::Object(vm, AS3::fl_ui::KeyLocationCI));
        SetInstanceTraits(it);

        // There is no problem with Pickable not assigned to anything here. Class constructor takes care of this.
        Pickable<Class> cl(SF_HEAP_NEW_ID(mh, StatMV_VM_Class_Mem) Classes::fl_ui::KeyLocation(*this));

    }

    Pickable<Traits> KeyLocation::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(SF_HEAP_NEW_ID(vm.GetMemoryHeap(), StatMV_VM_CTraits_Mem) KeyLocation(vm));
    }
//##protect##"ClassTraits$methods"
//##protect##"ClassTraits$methods"

}} // namespace ClassTraits

namespace fl_ui
{
    const TypeInfo KeyLocationTI = {
        TypeInfo::CompileTime | TypeInfo::Final,
        "KeyLocation", "flash.ui", &fl::ObjectTI,
        TypeInfo::None
    };

    const ClassInfo KeyLocationCI = {
        &KeyLocationTI,
        ClassTraits::fl_ui::KeyLocation::MakeClassTraits,
        0,
        ClassTraits::fl_ui::KeyLocation::MemberInfoNum,
        0,
        0,
        NULL,
        ClassTraits::fl_ui::KeyLocation::mi,
        NULL,
        NULL,
    };
}; // namespace fl_ui


}}} // namespace Scaleform { namespace GFx { namespace AS3

