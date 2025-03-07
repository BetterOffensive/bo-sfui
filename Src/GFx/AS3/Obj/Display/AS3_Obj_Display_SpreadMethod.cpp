//##protect##"disclaimer"
/**************************************************************************

Filename    :   AS3_Obj_Display_SpreadMethod.cpp
Content     :   
Created     :   Jan, 2010
Authors     :   Sergey Sikorskiy

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/
//##protect##"disclaimer"

#include "AS3_Obj_Display_SpreadMethod.h"
#include "../../AS3_VM.h"
#include "../../AS3_Marshalling.h"
//##protect##"includes"
//##protect##"includes"


namespace Scaleform { namespace GFx { namespace AS3 
{

//##protect##"methods"
//##protect##"methods"

namespace Classes { namespace fl_display
{
    SpreadMethod::SpreadMethod(ClassTraits::Traits& t)
    : Class(t)
    , PAD("pad")
    , REFLECT("reflect")
    , REPEAT("repeat")
    {
//##protect##"class_::SpreadMethod::SpreadMethod()"
//##protect##"class_::SpreadMethod::SpreadMethod()"
    }
//##protect##"class_$methods"
//##protect##"class_$methods"

}} // namespace Classes


namespace ClassTraits { namespace fl_display
{
    const MemberInfo SpreadMethod::mi[SpreadMethod::MemberInfoNum] = {
        {"PAD", NULL, OFFSETOF(Classes::fl_display::SpreadMethod, PAD), Abc::NS_Public, SlotInfo::BT_ConstChar, 1},
        {"REFLECT", NULL, OFFSETOF(Classes::fl_display::SpreadMethod, REFLECT), Abc::NS_Public, SlotInfo::BT_ConstChar, 1},
        {"REPEAT", NULL, OFFSETOF(Classes::fl_display::SpreadMethod, REPEAT), Abc::NS_Public, SlotInfo::BT_ConstChar, 1},
    };

    SpreadMethod::SpreadMethod(VM& vm)
    : Traits(vm, AS3::fl_display::SpreadMethodCI)
    {
//##protect##"ClassTraits::SpreadMethod::SpreadMethod()"
//##protect##"ClassTraits::SpreadMethod::SpreadMethod()"
        MemoryHeap* mh = vm.GetMemoryHeap();

        Pickable<InstanceTraits::Traits> it(SF_HEAP_NEW_ID(mh, StatMV_VM_ITraits_Mem) InstanceTraits::fl::Object(vm, AS3::fl_display::SpreadMethodCI));
        SetInstanceTraits(it);

        // There is no problem with Pickable not assigned to anything here. Class constructor takes care of this.
        Pickable<Class> cl(SF_HEAP_NEW_ID(mh, StatMV_VM_Class_Mem) Classes::fl_display::SpreadMethod(*this));

    }

    Pickable<Traits> SpreadMethod::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(SF_HEAP_NEW_ID(vm.GetMemoryHeap(), StatMV_VM_CTraits_Mem) SpreadMethod(vm));
    }
//##protect##"ClassTraits$methods"
//##protect##"ClassTraits$methods"

}} // namespace ClassTraits

namespace fl_display
{
    const TypeInfo SpreadMethodTI = {
        TypeInfo::CompileTime | TypeInfo::Final,
        "SpreadMethod", "flash.display", &fl::ObjectTI,
        TypeInfo::None
    };

    const ClassInfo SpreadMethodCI = {
        &SpreadMethodTI,
        ClassTraits::fl_display::SpreadMethod::MakeClassTraits,
        0,
        ClassTraits::fl_display::SpreadMethod::MemberInfoNum,
        0,
        0,
        NULL,
        ClassTraits::fl_display::SpreadMethod::mi,
        NULL,
        NULL,
    };
}; // namespace fl_display


}}} // namespace Scaleform { namespace GFx { namespace AS3

