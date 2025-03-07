//##protect##"disclaimer"
/**************************************************************************

Filename    :   AS3_Obj_Text_FontType.cpp
Content     :   
Created     :   Jan, 2010
Authors     :   Sergey Sikorskiy

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/
//##protect##"disclaimer"

#include "AS3_Obj_Text_FontType.h"
#include "../../AS3_VM.h"
#include "../../AS3_Marshalling.h"
//##protect##"includes"
//##protect##"includes"


namespace Scaleform { namespace GFx { namespace AS3 
{

//##protect##"methods"
//##protect##"methods"

namespace Classes { namespace fl_text
{
    FontType::FontType(ClassTraits::Traits& t)
    : Class(t)
    , DEVICE("device")
    , EMBEDDED("embedded")
    {
//##protect##"class_::FontType::FontType()"
//##protect##"class_::FontType::FontType()"
    }
//##protect##"class_$methods"
//##protect##"class_$methods"

}} // namespace Classes


namespace ClassTraits { namespace fl_text
{
    const MemberInfo FontType::mi[FontType::MemberInfoNum] = {
        {"DEVICE", NULL, OFFSETOF(Classes::fl_text::FontType, DEVICE), Abc::NS_Public, SlotInfo::BT_ConstChar, 1},
        {"EMBEDDED", NULL, OFFSETOF(Classes::fl_text::FontType, EMBEDDED), Abc::NS_Public, SlotInfo::BT_ConstChar, 1},
    };

    FontType::FontType(VM& vm)
    : Traits(vm, AS3::fl_text::FontTypeCI)
    {
//##protect##"ClassTraits::FontType::FontType()"
//##protect##"ClassTraits::FontType::FontType()"
        MemoryHeap* mh = vm.GetMemoryHeap();

        Pickable<InstanceTraits::Traits> it(SF_HEAP_NEW_ID(mh, StatMV_VM_ITraits_Mem) InstanceTraits::fl::Object(vm, AS3::fl_text::FontTypeCI));
        SetInstanceTraits(it);

        // There is no problem with Pickable not assigned to anything here. Class constructor takes care of this.
        Pickable<Class> cl(SF_HEAP_NEW_ID(mh, StatMV_VM_Class_Mem) Classes::fl_text::FontType(*this));

    }

    Pickable<Traits> FontType::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(SF_HEAP_NEW_ID(vm.GetMemoryHeap(), StatMV_VM_CTraits_Mem) FontType(vm));
    }
//##protect##"ClassTraits$methods"
//##protect##"ClassTraits$methods"

}} // namespace ClassTraits

namespace fl_text
{
    const TypeInfo FontTypeTI = {
        TypeInfo::CompileTime | TypeInfo::Final,
        "FontType", "flash.text", &fl::ObjectTI,
        TypeInfo::None
    };

    const ClassInfo FontTypeCI = {
        &FontTypeTI,
        ClassTraits::fl_text::FontType::MakeClassTraits,
        0,
        ClassTraits::fl_text::FontType::MemberInfoNum,
        0,
        0,
        NULL,
        ClassTraits::fl_text::FontType::mi,
        NULL,
        NULL,
    };
}; // namespace fl_text


}}} // namespace Scaleform { namespace GFx { namespace AS3

