//##protect##"disclaimer"
/**************************************************************************

Filename    :   AS3_Obj_Filters_BitmapFilterQuality.cpp
Content     :   
Created     :   Jan, 2010
Authors     :   Sergey Sikorskiy

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/
//##protect##"disclaimer"

#include "AS3_Obj_Filters_BitmapFilterQuality.h"
#include "../../AS3_VM.h"
#include "../../AS3_Marshalling.h"
//##protect##"includes"
//##protect##"includes"


namespace Scaleform { namespace GFx { namespace AS3 
{

//##protect##"methods"
//##protect##"methods"

namespace Classes { namespace fl_filters
{
    BitmapFilterQuality::BitmapFilterQuality(ClassTraits::Traits& t)
    : Class(t)
    , HIGH(3)
    , LOW(1)
    , MEDIUM(2)
    {
//##protect##"class_::BitmapFilterQuality::BitmapFilterQuality()"
//##protect##"class_::BitmapFilterQuality::BitmapFilterQuality()"
    }
//##protect##"class_$methods"
//##protect##"class_$methods"

}} // namespace Classes


namespace ClassTraits { namespace fl_filters
{
    const MemberInfo BitmapFilterQuality::mi[BitmapFilterQuality::MemberInfoNum] = {
        {"HIGH", NULL, OFFSETOF(Classes::fl_filters::BitmapFilterQuality, HIGH), Abc::NS_Public, SlotInfo::BT_Int, 1},
        {"LOW", NULL, OFFSETOF(Classes::fl_filters::BitmapFilterQuality, LOW), Abc::NS_Public, SlotInfo::BT_Int, 1},
        {"MEDIUM", NULL, OFFSETOF(Classes::fl_filters::BitmapFilterQuality, MEDIUM), Abc::NS_Public, SlotInfo::BT_Int, 1},
    };

    BitmapFilterQuality::BitmapFilterQuality(VM& vm)
    : Traits(vm, AS3::fl_filters::BitmapFilterQualityCI)
    {
//##protect##"ClassTraits::BitmapFilterQuality::BitmapFilterQuality()"
//##protect##"ClassTraits::BitmapFilterQuality::BitmapFilterQuality()"
        MemoryHeap* mh = vm.GetMemoryHeap();

        Pickable<InstanceTraits::Traits> it(SF_HEAP_NEW_ID(mh, StatMV_VM_ITraits_Mem) InstanceTraits::fl::Object(vm, AS3::fl_filters::BitmapFilterQualityCI));
        SetInstanceTraits(it);

        // There is no problem with Pickable not assigned to anything here. Class constructor takes care of this.
        Pickable<Class> cl(SF_HEAP_NEW_ID(mh, StatMV_VM_Class_Mem) Classes::fl_filters::BitmapFilterQuality(*this));

    }

    Pickable<Traits> BitmapFilterQuality::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(SF_HEAP_NEW_ID(vm.GetMemoryHeap(), StatMV_VM_CTraits_Mem) BitmapFilterQuality(vm));
    }
//##protect##"ClassTraits$methods"
//##protect##"ClassTraits$methods"

}} // namespace ClassTraits

namespace fl_filters
{
    const TypeInfo BitmapFilterQualityTI = {
        TypeInfo::CompileTime | TypeInfo::Final,
        "BitmapFilterQuality", "flash.filters", &fl::ObjectTI,
        TypeInfo::None
    };

    const ClassInfo BitmapFilterQualityCI = {
        &BitmapFilterQualityTI,
        ClassTraits::fl_filters::BitmapFilterQuality::MakeClassTraits,
        0,
        ClassTraits::fl_filters::BitmapFilterQuality::MemberInfoNum,
        0,
        0,
        NULL,
        ClassTraits::fl_filters::BitmapFilterQuality::mi,
        NULL,
        NULL,
    };
}; // namespace fl_filters


}}} // namespace Scaleform { namespace GFx { namespace AS3

