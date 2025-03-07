//##protect##"disclaimer"
/**************************************************************************

Filename    :   AS3_Obj_Filters_DropShadowFilter.cpp
Content     :   
Created     :   Jan, 2010
Authors     :   Sergey Sikorskiy

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/
//##protect##"disclaimer"

#include "AS3_Obj_Filters_DropShadowFilter.h"
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
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_alphaGet, Value::Number> TFunc_Instances_DropShadowFilter_alphaGet;
typedef ThunkFunc1<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_alphaSet, const Value, Value::Number> TFunc_Instances_DropShadowFilter_alphaSet;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_angleGet, Value::Number> TFunc_Instances_DropShadowFilter_angleGet;
typedef ThunkFunc1<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_angleSet, const Value, Value::Number> TFunc_Instances_DropShadowFilter_angleSet;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_blurXGet, Value::Number> TFunc_Instances_DropShadowFilter_blurXGet;
typedef ThunkFunc1<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_blurXSet, const Value, Value::Number> TFunc_Instances_DropShadowFilter_blurXSet;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_blurYGet, Value::Number> TFunc_Instances_DropShadowFilter_blurYGet;
typedef ThunkFunc1<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_blurYSet, const Value, Value::Number> TFunc_Instances_DropShadowFilter_blurYSet;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_colorGet, UInt32> TFunc_Instances_DropShadowFilter_colorGet;
typedef ThunkFunc1<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_colorSet, const Value, UInt32> TFunc_Instances_DropShadowFilter_colorSet;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_distanceGet, Value::Number> TFunc_Instances_DropShadowFilter_distanceGet;
typedef ThunkFunc1<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_distanceSet, const Value, Value::Number> TFunc_Instances_DropShadowFilter_distanceSet;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_hideObjectGet, bool> TFunc_Instances_DropShadowFilter_hideObjectGet;
typedef ThunkFunc1<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_hideObjectSet, const Value, bool> TFunc_Instances_DropShadowFilter_hideObjectSet;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_innerGet, bool> TFunc_Instances_DropShadowFilter_innerGet;
typedef ThunkFunc1<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_innerSet, const Value, bool> TFunc_Instances_DropShadowFilter_innerSet;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_knockoutGet, bool> TFunc_Instances_DropShadowFilter_knockoutGet;
typedef ThunkFunc1<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_knockoutSet, const Value, bool> TFunc_Instances_DropShadowFilter_knockoutSet;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_qualityGet, SInt32> TFunc_Instances_DropShadowFilter_qualityGet;
typedef ThunkFunc1<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_qualitySet, const Value, SInt32> TFunc_Instances_DropShadowFilter_qualitySet;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_strengthGet, Value::Number> TFunc_Instances_DropShadowFilter_strengthGet;
typedef ThunkFunc1<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_strengthSet, const Value, Value::Number> TFunc_Instances_DropShadowFilter_strengthSet;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, Instances::fl_filters::DropShadowFilter::mid_clone, SPtr<Instances::fl_filters::BitmapFilter> > TFunc_Instances_DropShadowFilter_clone;

template <> const TFunc_Instances_DropShadowFilter_alphaGet::TMethod TFunc_Instances_DropShadowFilter_alphaGet::Method = &Instances::fl_filters::DropShadowFilter::alphaGet;
template <> const TFunc_Instances_DropShadowFilter_alphaSet::TMethod TFunc_Instances_DropShadowFilter_alphaSet::Method = &Instances::fl_filters::DropShadowFilter::alphaSet;
template <> const TFunc_Instances_DropShadowFilter_angleGet::TMethod TFunc_Instances_DropShadowFilter_angleGet::Method = &Instances::fl_filters::DropShadowFilter::angleGet;
template <> const TFunc_Instances_DropShadowFilter_angleSet::TMethod TFunc_Instances_DropShadowFilter_angleSet::Method = &Instances::fl_filters::DropShadowFilter::angleSet;
template <> const TFunc_Instances_DropShadowFilter_blurXGet::TMethod TFunc_Instances_DropShadowFilter_blurXGet::Method = &Instances::fl_filters::DropShadowFilter::blurXGet;
template <> const TFunc_Instances_DropShadowFilter_blurXSet::TMethod TFunc_Instances_DropShadowFilter_blurXSet::Method = &Instances::fl_filters::DropShadowFilter::blurXSet;
template <> const TFunc_Instances_DropShadowFilter_blurYGet::TMethod TFunc_Instances_DropShadowFilter_blurYGet::Method = &Instances::fl_filters::DropShadowFilter::blurYGet;
template <> const TFunc_Instances_DropShadowFilter_blurYSet::TMethod TFunc_Instances_DropShadowFilter_blurYSet::Method = &Instances::fl_filters::DropShadowFilter::blurYSet;
template <> const TFunc_Instances_DropShadowFilter_colorGet::TMethod TFunc_Instances_DropShadowFilter_colorGet::Method = &Instances::fl_filters::DropShadowFilter::colorGet;
template <> const TFunc_Instances_DropShadowFilter_colorSet::TMethod TFunc_Instances_DropShadowFilter_colorSet::Method = &Instances::fl_filters::DropShadowFilter::colorSet;
template <> const TFunc_Instances_DropShadowFilter_distanceGet::TMethod TFunc_Instances_DropShadowFilter_distanceGet::Method = &Instances::fl_filters::DropShadowFilter::distanceGet;
template <> const TFunc_Instances_DropShadowFilter_distanceSet::TMethod TFunc_Instances_DropShadowFilter_distanceSet::Method = &Instances::fl_filters::DropShadowFilter::distanceSet;
template <> const TFunc_Instances_DropShadowFilter_hideObjectGet::TMethod TFunc_Instances_DropShadowFilter_hideObjectGet::Method = &Instances::fl_filters::DropShadowFilter::hideObjectGet;
template <> const TFunc_Instances_DropShadowFilter_hideObjectSet::TMethod TFunc_Instances_DropShadowFilter_hideObjectSet::Method = &Instances::fl_filters::DropShadowFilter::hideObjectSet;
template <> const TFunc_Instances_DropShadowFilter_innerGet::TMethod TFunc_Instances_DropShadowFilter_innerGet::Method = &Instances::fl_filters::DropShadowFilter::innerGet;
template <> const TFunc_Instances_DropShadowFilter_innerSet::TMethod TFunc_Instances_DropShadowFilter_innerSet::Method = &Instances::fl_filters::DropShadowFilter::innerSet;
template <> const TFunc_Instances_DropShadowFilter_knockoutGet::TMethod TFunc_Instances_DropShadowFilter_knockoutGet::Method = &Instances::fl_filters::DropShadowFilter::knockoutGet;
template <> const TFunc_Instances_DropShadowFilter_knockoutSet::TMethod TFunc_Instances_DropShadowFilter_knockoutSet::Method = &Instances::fl_filters::DropShadowFilter::knockoutSet;
template <> const TFunc_Instances_DropShadowFilter_qualityGet::TMethod TFunc_Instances_DropShadowFilter_qualityGet::Method = &Instances::fl_filters::DropShadowFilter::qualityGet;
template <> const TFunc_Instances_DropShadowFilter_qualitySet::TMethod TFunc_Instances_DropShadowFilter_qualitySet::Method = &Instances::fl_filters::DropShadowFilter::qualitySet;
template <> const TFunc_Instances_DropShadowFilter_strengthGet::TMethod TFunc_Instances_DropShadowFilter_strengthGet::Method = &Instances::fl_filters::DropShadowFilter::strengthGet;
template <> const TFunc_Instances_DropShadowFilter_strengthSet::TMethod TFunc_Instances_DropShadowFilter_strengthSet::Method = &Instances::fl_filters::DropShadowFilter::strengthSet;
template <> const TFunc_Instances_DropShadowFilter_clone::TMethod TFunc_Instances_DropShadowFilter_clone::Method = &Instances::fl_filters::DropShadowFilter::clone;

namespace Instances { namespace fl_filters
{
    DropShadowFilter::DropShadowFilter(InstanceTraits::Traits& t)
    : Instances::fl_filters::BitmapFilter(t)
//##protect##"instance::DropShadowFilter::DropShadowFilter()$data"
//##protect##"instance::DropShadowFilter::DropShadowFilter()$data"
    {
//##protect##"instance::DropShadowFilter::DropShadowFilter()$code"
        FilterData = *SF_NEW Render::ShadowFilter();
//##protect##"instance::DropShadowFilter::DropShadowFilter()$code"
    }

    void DropShadowFilter::alphaGet(Value::Number& result)
    {
//##protect##"instance::DropShadowFilter::alphaGet()"
        result = GetShadowFilterData()->GetParams().Colors[0].GetAlpha() / 255.0;
//##protect##"instance::DropShadowFilter::alphaGet()"
    }
    void DropShadowFilter::alphaSet(const Value& result, Value::Number value)
    {
//##protect##"instance::DropShadowFilter::alphaSet()"
        SF_UNUSED(result);
        GetShadowFilterData()->GetParams().Colors[0].SetAlpha((UByte)(value * 255));
//##protect##"instance::DropShadowFilter::alphaSet()"
    }
    void DropShadowFilter::angleGet(Value::Number& result)
    {
//##protect##"instance::DropShadowFilter::angleGet()"
        result = SF_RADTODEG(GetShadowFilterData()->GetAngle());
//##protect##"instance::DropShadowFilter::angleGet()"
    }
    void DropShadowFilter::angleSet(const Value& result, Value::Number value)
    {
//##protect##"instance::DropShadowFilter::angleSet()"
        SF_UNUSED(result);
        GetShadowFilterData()->SetAngleDistance((float)SF_DEGTORAD((float)value), GetShadowFilterData()->GetDistance());
//##protect##"instance::DropShadowFilter::angleSet()"
    }
    void DropShadowFilter::blurXGet(Value::Number& result)
    {
//##protect##"instance::DropShadowFilter::blurXGet()"
        result = TwipsToPixels(GetShadowFilterData()->GetParams().BlurX);
//##protect##"instance::DropShadowFilter::blurXGet()"
    }
    void DropShadowFilter::blurXSet(const Value& result, Value::Number value)
    {
//##protect##"instance::DropShadowFilter::blurXSet()"
        SF_UNUSED(result);
        GetShadowFilterData()->GetParams().BlurX = PixelsToTwips((float)value);
//##protect##"instance::DropShadowFilter::blurXSet()"
    }
    void DropShadowFilter::blurYGet(Value::Number& result)
    {
//##protect##"instance::DropShadowFilter::blurYGet()"
        result = TwipsToPixels(GetShadowFilterData()->GetParams().BlurY);
//##protect##"instance::DropShadowFilter::blurYGet()"
    }
    void DropShadowFilter::blurYSet(const Value& result, Value::Number value)
    {
//##protect##"instance::DropShadowFilter::blurYSet()"
        SF_UNUSED(result);
        GetShadowFilterData()->GetParams().BlurY = PixelsToTwips((float)value);
//##protect##"instance::DropShadowFilter::blurYSet()"
    }
    void DropShadowFilter::colorGet(UInt32& result)
    {
//##protect##"instance::DropShadowFilter::colorGet()"
        Render::Color& c = GetShadowFilterData()->GetParams().Colors[0];
        result = c.GetColorRGB().Raw;
//##protect##"instance::DropShadowFilter::colorGet()"
    }
    void DropShadowFilter::colorSet(const Value& result, UInt32 value)
    {
//##protect##"instance::DropShadowFilter::colorSet()"
        SF_UNUSED(result);
        Render::Color& c = GetShadowFilterData()->GetParams().Colors[0];
        c.SetColor(value, c.GetAlpha());
//##protect##"instance::DropShadowFilter::colorSet()"
    }
    void DropShadowFilter::distanceGet(Value::Number& result)
    {
//##protect##"instance::DropShadowFilter::distanceGet()"
        result = TwipsToPixels(GetShadowFilterData()->GetDistance());
//##protect##"instance::DropShadowFilter::distanceGet()"
    }
    void DropShadowFilter::distanceSet(const Value& result, Value::Number value)
    {
//##protect##"instance::DropShadowFilter::distanceSet()"
        SF_UNUSED(result);
        GetShadowFilterData()->SetAngleDistance( GetShadowFilterData()->GetAngle(), PixelsToTwips((float)value));
//##protect##"instance::DropShadowFilter::distanceSet()"
    }
    void DropShadowFilter::hideObjectGet(bool& result)
    {
//##protect##"instance::DropShadowFilter::hideObjectGet()"
        result = (GetShadowFilterData()->GetParams().Mode & Render::BlurFilterParams::Mode_HideObject) != 0;
//##protect##"instance::DropShadowFilter::hideObjectGet()"
    }
    void DropShadowFilter::hideObjectSet(const Value& result, bool value)
    {
//##protect##"instance::DropShadowFilter::hideObjectSet()"
        SF_UNUSED(result);
        GetShadowFilterData()->GetParams().Mode |= (value ? Render::BlurFilterParams::Mode_HideObject : 0);
//##protect##"instance::DropShadowFilter::hideObjectSet()"
    }
    void DropShadowFilter::innerGet(bool& result)
    {
//##protect##"instance::DropShadowFilter::innerGet()"
        result = (GetShadowFilterData()->GetParams().Mode & Render::BlurFilterParams::Mode_Inner) != 0;
//##protect##"instance::DropShadowFilter::innerGet()"
    }
    void DropShadowFilter::innerSet(const Value& result, bool value)
    {
//##protect##"instance::DropShadowFilter::innerSet()"
        SF_UNUSED(result);
        GetShadowFilterData()->GetParams().Mode |= (value ? Render::BlurFilterParams::Mode_Inner : 0);
//##protect##"instance::DropShadowFilter::innerSet()"
    }
    void DropShadowFilter::knockoutGet(bool& result)
    {
//##protect##"instance::DropShadowFilter::knockoutGet()"
        result = (GetShadowFilterData()->GetParams().Mode & Render::BlurFilterParams::Mode_Knockout) != 0;
//##protect##"instance::DropShadowFilter::knockoutGet()"
    }
    void DropShadowFilter::knockoutSet(const Value& result, bool value)
    {
//##protect##"instance::DropShadowFilter::knockoutSet()"
        SF_UNUSED(result);
        GetShadowFilterData()->GetParams().Mode |= (value ? Render::BlurFilterParams::Mode_Knockout : 0);
//##protect##"instance::DropShadowFilter::knockoutSet()"
    }
    void DropShadowFilter::qualityGet(SInt32& result)
    {
//##protect##"instance::DropShadowFilter::qualityGet()"
        result = (GetShadowFilterData()->GetParams().Passes);
//##protect##"instance::DropShadowFilter::qualityGet()"
    }
    void DropShadowFilter::qualitySet(const Value& result, SInt32 value)
    {
//##protect##"instance::DropShadowFilter::qualitySet()"
        SF_UNUSED(result);
        GetShadowFilterData()->GetParams().Passes = Alg::Clamp<unsigned>(value, 0, 15);
//##protect##"instance::DropShadowFilter::qualitySet()"
    }
    void DropShadowFilter::strengthGet(Value::Number& result)
    {
//##protect##"instance::DropShadowFilter::strengthGet()"
        result = GetShadowFilterData()->GetParams().Strength;
//##protect##"instance::DropShadowFilter::strengthGet()"
    }
    void DropShadowFilter::strengthSet(const Value& result, Value::Number value)
    {
//##protect##"instance::DropShadowFilter::strengthSet()"
        SF_UNUSED(result);
        GetShadowFilterData()->GetParams().Strength = (float)value;
//##protect##"instance::DropShadowFilter::strengthSet()"
    }
    void DropShadowFilter::clone(SPtr<Instances::fl_filters::BitmapFilter>& result)
    {
//##protect##"instance::DropShadowFilter::clone()"
        InstanceTraits::fl_filters::DropShadowFilter& itr = static_cast<InstanceTraits::fl_filters::DropShadowFilter&>(GetTraits());
        Pickable<DropShadowFilter> r = itr.MakeInstance(itr);

        Value::Number dist, angl;
        UInt32 color;
        Value::Number alpha, blurX, blurY, stren;
        SInt32 qual;
        bool inner, knock, hide;
        distanceGet(dist);
        angleGet(angl);
        colorGet(color);
        alphaGet(alpha);
        blurXGet(blurX);
        blurYGet(blurY);
        strengthGet(stren);
        qualityGet(qual);
        innerGet(inner);
        knockoutGet(knock);
        hideObjectGet(hide);

        Value tempResult;
        r->distanceSet(tempResult, dist);
        r->angleSet(tempResult, angl);
        r->colorSet(tempResult, color);
        r->alphaSet(tempResult, alpha);
        r->blurXSet(tempResult, blurX);
        r->blurYSet(tempResult, blurY);
        r->strengthSet(tempResult, stren);
        r->qualitySet(tempResult, qual);
        r->innerSet(tempResult, inner);
        r->knockoutSet(tempResult, knock);
        r->hideObjectSet(tempResult, hide);
        result = r;
//##protect##"instance::DropShadowFilter::clone()"
    }

    SPtr<Instances::fl_filters::BitmapFilter> DropShadowFilter::clone()
    {
        SPtr<Instances::fl_filters::BitmapFilter> result;
        clone(result);
        return result;
    }
//##protect##"instance$methods"
    void DropShadowFilter::AS3Constructor(unsigned argc, const Value* argv)
    {
        Value::Number dist(4), angl(45);
        UInt32 color(0);
        Value::Number alpha(1), blurX(4), blurY(4), stren(1);
        SInt32 qual(1);
        bool inner(false), knock(false), hide(false);

        if ( argc >= 1 && !argv[0].Convert2Number(dist)) return;
        if ( argc >= 2 && !argv[1].Convert2Number(angl)) return;
        if ( argc >= 3 && !argv[2].Convert2UInt32(color)) return;
        if ( argc >= 4 && !argv[3].Convert2Number(alpha)) return;
        if ( argc >= 5 && !argv[4].Convert2Number(blurX)) return;
        if ( argc >= 6 && !argv[5].Convert2Number(blurY)) return;
        if ( argc >= 7 && !argv[6].Convert2Number(stren)) return;
        if ( argc >= 8 && !argv[7].Convert2Int32(qual)) return;
        if ( argc >= 7 ) inner = argv[6].Convert2Boolean();
        if ( argc >= 8 ) knock = argv[7].Convert2Boolean();

        Value result;
        distanceSet(result, dist);
        angleSet(result, angl);
        colorSet(result, color);
        alphaSet(result, alpha);
        blurXSet(result, blurX);
        blurYSet(result, blurY);
        strengthSet(result, stren);
        qualitySet(result, qual);
        innerSet(result, inner);
        knockoutSet(result, knock);
        hideObjectSet(result, hide);
    }
//##protect##"instance$methods"

}} // namespace Instances

namespace InstanceTraits { namespace fl_filters
{
    const ThunkInfo DropShadowFilter::ti[DropShadowFilter::ThunkInfoNum] = {
        {TFunc_Instances_DropShadowFilter_alphaGet::Func, &AS3::fl::NumberTI, "alpha", NULL, Abc::NS_Public, CT_Get, 0, 0},
        {TFunc_Instances_DropShadowFilter_alphaSet::Func, NULL, "alpha", NULL, Abc::NS_Public, CT_Set, 1, 1},
        {TFunc_Instances_DropShadowFilter_angleGet::Func, &AS3::fl::NumberTI, "angle", NULL, Abc::NS_Public, CT_Get, 0, 0},
        {TFunc_Instances_DropShadowFilter_angleSet::Func, NULL, "angle", NULL, Abc::NS_Public, CT_Set, 1, 1},
        {TFunc_Instances_DropShadowFilter_blurXGet::Func, &AS3::fl::NumberTI, "blurX", NULL, Abc::NS_Public, CT_Get, 0, 0},
        {TFunc_Instances_DropShadowFilter_blurXSet::Func, NULL, "blurX", NULL, Abc::NS_Public, CT_Set, 1, 1},
        {TFunc_Instances_DropShadowFilter_blurYGet::Func, &AS3::fl::NumberTI, "blurY", NULL, Abc::NS_Public, CT_Get, 0, 0},
        {TFunc_Instances_DropShadowFilter_blurYSet::Func, NULL, "blurY", NULL, Abc::NS_Public, CT_Set, 1, 1},
        {TFunc_Instances_DropShadowFilter_colorGet::Func, &AS3::fl::uintTI, "color", NULL, Abc::NS_Public, CT_Get, 0, 0},
        {TFunc_Instances_DropShadowFilter_colorSet::Func, NULL, "color", NULL, Abc::NS_Public, CT_Set, 1, 1},
        {TFunc_Instances_DropShadowFilter_distanceGet::Func, &AS3::fl::NumberTI, "distance", NULL, Abc::NS_Public, CT_Get, 0, 0},
        {TFunc_Instances_DropShadowFilter_distanceSet::Func, NULL, "distance", NULL, Abc::NS_Public, CT_Set, 1, 1},
        {TFunc_Instances_DropShadowFilter_hideObjectGet::Func, &AS3::fl::BooleanTI, "hideObject", NULL, Abc::NS_Public, CT_Get, 0, 0},
        {TFunc_Instances_DropShadowFilter_hideObjectSet::Func, NULL, "hideObject", NULL, Abc::NS_Public, CT_Set, 1, 1},
        {TFunc_Instances_DropShadowFilter_innerGet::Func, &AS3::fl::BooleanTI, "inner", NULL, Abc::NS_Public, CT_Get, 0, 0},
        {TFunc_Instances_DropShadowFilter_innerSet::Func, NULL, "inner", NULL, Abc::NS_Public, CT_Set, 1, 1},
        {TFunc_Instances_DropShadowFilter_knockoutGet::Func, &AS3::fl::BooleanTI, "knockout", NULL, Abc::NS_Public, CT_Get, 0, 0},
        {TFunc_Instances_DropShadowFilter_knockoutSet::Func, NULL, "knockout", NULL, Abc::NS_Public, CT_Set, 1, 1},
        {TFunc_Instances_DropShadowFilter_qualityGet::Func, &AS3::fl::int_TI, "quality", NULL, Abc::NS_Public, CT_Get, 0, 0},
        {TFunc_Instances_DropShadowFilter_qualitySet::Func, NULL, "quality", NULL, Abc::NS_Public, CT_Set, 1, 1},
        {TFunc_Instances_DropShadowFilter_strengthGet::Func, &AS3::fl::NumberTI, "strength", NULL, Abc::NS_Public, CT_Get, 0, 0},
        {TFunc_Instances_DropShadowFilter_strengthSet::Func, NULL, "strength", NULL, Abc::NS_Public, CT_Set, 1, 1},
        {TFunc_Instances_DropShadowFilter_clone::Func, &AS3::fl_filters::BitmapFilterTI, "clone", NULL, Abc::NS_Public, CT_Method, 0, 0},
    };

    DropShadowFilter::DropShadowFilter(VM& vm, const ClassInfo& ci)
    : CTraits(vm, ci)
    {
//##protect##"InstanceTraits::DropShadowFilter::DropShadowFilter()"
//##protect##"InstanceTraits::DropShadowFilter::DropShadowFilter()"
        SetMemSize(sizeof(Instances::fl_filters::DropShadowFilter));

    }

    void DropShadowFilter::MakeObject(Value& result, Traits& t)
    {
        result = MakeInstance(static_cast<DropShadowFilter&>(t));
    }

//##protect##"instance_traits$methods"
//##protect##"instance_traits$methods"

}} // namespace InstanceTraits


namespace ClassTraits { namespace fl_filters
{
    DropShadowFilter::DropShadowFilter(VM& vm)
    : Traits(vm, AS3::fl_filters::DropShadowFilterCI)
    {
//##protect##"ClassTraits::DropShadowFilter::DropShadowFilter()"
//##protect##"ClassTraits::DropShadowFilter::DropShadowFilter()"
        MemoryHeap* mh = vm.GetMemoryHeap();

        Pickable<InstanceTraits::Traits> it(SF_HEAP_NEW_ID(mh, StatMV_VM_ITraits_Mem) InstanceTraits::fl_filters::DropShadowFilter(vm, AS3::fl_filters::DropShadowFilterCI));
        SetInstanceTraits(it);

        // There is no problem with Pickable not assigned to anything here. Class constructor takes care of this.
        Pickable<Class> cl(SF_HEAP_NEW_ID(mh, StatMV_VM_Class_Mem) Class(*this));

    }

    Pickable<Traits> DropShadowFilter::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(SF_HEAP_NEW_ID(vm.GetMemoryHeap(), StatMV_VM_CTraits_Mem) DropShadowFilter(vm));
    }
//##protect##"ClassTraits$methods"
//##protect##"ClassTraits$methods"

}} // namespace ClassTraits

namespace fl_filters
{
    const TypeInfo DropShadowFilterTI = {
        TypeInfo::CompileTime | TypeInfo::Final,
        "DropShadowFilter", "flash.filters", &fl_filters::BitmapFilterTI,
        TypeInfo::None
    };

    const ClassInfo DropShadowFilterCI = {
        &DropShadowFilterTI,
        ClassTraits::fl_filters::DropShadowFilter::MakeClassTraits,
        0,
        0,
        InstanceTraits::fl_filters::DropShadowFilter::ThunkInfoNum,
        0,
        NULL,
        NULL,
        InstanceTraits::fl_filters::DropShadowFilter::ti,
        NULL,
    };
}; // namespace fl_filters


}}} // namespace Scaleform { namespace GFx { namespace AS3

