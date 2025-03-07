//##protect##"disclaimer"
/**************************************************************************

Filename    :   AS3_Obj_Display_Graphics.cpp
Content     :   
Created     :   Jan, 2010
Authors     :   Sergey Sikorskiy, Artem Bolgar, Prasad Silva

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/
//##protect##"disclaimer"

#include "AS3_Obj_Display_Graphics.h"
#include "../../AS3_VM.h"
#include "../../AS3_Marshalling.h"
//##protect##"includes"
#include "../AS3_Obj_Array.h"
#include "AS3_Obj_Display_BitmapData.h"
#include "../Geom/AS3_Obj_Geom_Matrix.h"
#include <math.h>
#include "../../../../Kernel/SF_Math.h"
#include "../../../../Render/Render_ShapeDataDefs.h"
//##protect##"includes"


namespace Scaleform { namespace GFx { namespace AS3 
{

//##protect##"methods"
//##protect##"methods"

// Values of default arguments.
namespace Impl
{

    template <>
    SF_INLINE
    bool GetMethodDefArg<Instances::fl_display::Graphics, Instances::fl_display::Graphics::mid_beginBitmapFill, 2, bool>(AS3::StringManager&)
    {
        return true;
    }

    template <>
    SF_INLINE
    Value::Number GetMethodDefArg<Instances::fl_display::Graphics, Instances::fl_display::Graphics::mid_beginFill, 1, Value::Number>(AS3::StringManager&)
    {
        return 1.0;
    }

} // namespace Impl
typedef ThunkFunc4<Instances::fl_display::Graphics, Instances::fl_display::Graphics::mid_beginBitmapFill, const Value, Instances::fl_display::BitmapData*, Instances::fl_geom::Matrix*, bool, bool> TFunc_Instances_Graphics_beginBitmapFill;
typedef ThunkFunc2<Instances::fl_display::Graphics, Instances::fl_display::Graphics::mid_beginFill, const Value, UInt32, Value::Number> TFunc_Instances_Graphics_beginFill;
typedef ThunkFunc2<Instances::fl_display::Graphics, Instances::fl_display::Graphics::mid_beginGradientFill, Value, unsigned, const Value*> TFunc_Instances_Graphics_beginGradientFill;
typedef ThunkFunc0<Instances::fl_display::Graphics, Instances::fl_display::Graphics::mid_clear, const Value> TFunc_Instances_Graphics_clear;
typedef ThunkFunc4<Instances::fl_display::Graphics, Instances::fl_display::Graphics::mid_curveTo, const Value, Value::Number, Value::Number, Value::Number, Value::Number> TFunc_Instances_Graphics_curveTo;
typedef ThunkFunc3<Instances::fl_display::Graphics, Instances::fl_display::Graphics::mid_drawCircle, const Value, Value::Number, Value::Number, Value::Number> TFunc_Instances_Graphics_drawCircle;
typedef ThunkFunc4<Instances::fl_display::Graphics, Instances::fl_display::Graphics::mid_drawEllipse, const Value, Value::Number, Value::Number, Value::Number, Value::Number> TFunc_Instances_Graphics_drawEllipse;
typedef ThunkFunc4<Instances::fl_display::Graphics, Instances::fl_display::Graphics::mid_drawRect, const Value, Value::Number, Value::Number, Value::Number, Value::Number> TFunc_Instances_Graphics_drawRect;
typedef ThunkFunc6<Instances::fl_display::Graphics, Instances::fl_display::Graphics::mid_drawRoundRect, const Value, Value::Number, Value::Number, Value::Number, Value::Number, Value::Number, Value::Number> TFunc_Instances_Graphics_drawRoundRect;
typedef ThunkFunc2<Instances::fl_display::Graphics, Instances::fl_display::Graphics::mid_drawRoundRectComplex, Value, unsigned, const Value*> TFunc_Instances_Graphics_drawRoundRectComplex;
typedef ThunkFunc0<Instances::fl_display::Graphics, Instances::fl_display::Graphics::mid_endFill, const Value> TFunc_Instances_Graphics_endFill;
typedef ThunkFunc2<Instances::fl_display::Graphics, Instances::fl_display::Graphics::mid_lineGradientStyle, Value, unsigned, const Value*> TFunc_Instances_Graphics_lineGradientStyle;
typedef ThunkFunc2<Instances::fl_display::Graphics, Instances::fl_display::Graphics::mid_lineStyle, Value, unsigned, const Value*> TFunc_Instances_Graphics_lineStyle;
typedef ThunkFunc2<Instances::fl_display::Graphics, Instances::fl_display::Graphics::mid_lineTo, const Value, Value::Number, Value::Number> TFunc_Instances_Graphics_lineTo;
typedef ThunkFunc2<Instances::fl_display::Graphics, Instances::fl_display::Graphics::mid_moveTo, const Value, Value::Number, Value::Number> TFunc_Instances_Graphics_moveTo;

template <> const TFunc_Instances_Graphics_beginBitmapFill::TMethod TFunc_Instances_Graphics_beginBitmapFill::Method = &Instances::fl_display::Graphics::beginBitmapFill;
template <> const TFunc_Instances_Graphics_beginFill::TMethod TFunc_Instances_Graphics_beginFill::Method = &Instances::fl_display::Graphics::beginFill;
template <> const TFunc_Instances_Graphics_beginGradientFill::TMethod TFunc_Instances_Graphics_beginGradientFill::Method = &Instances::fl_display::Graphics::beginGradientFill;
template <> const TFunc_Instances_Graphics_clear::TMethod TFunc_Instances_Graphics_clear::Method = &Instances::fl_display::Graphics::clear;
template <> const TFunc_Instances_Graphics_curveTo::TMethod TFunc_Instances_Graphics_curveTo::Method = &Instances::fl_display::Graphics::curveTo;
template <> const TFunc_Instances_Graphics_drawCircle::TMethod TFunc_Instances_Graphics_drawCircle::Method = &Instances::fl_display::Graphics::drawCircle;
template <> const TFunc_Instances_Graphics_drawEllipse::TMethod TFunc_Instances_Graphics_drawEllipse::Method = &Instances::fl_display::Graphics::drawEllipse;
template <> const TFunc_Instances_Graphics_drawRect::TMethod TFunc_Instances_Graphics_drawRect::Method = &Instances::fl_display::Graphics::drawRect;
template <> const TFunc_Instances_Graphics_drawRoundRect::TMethod TFunc_Instances_Graphics_drawRoundRect::Method = &Instances::fl_display::Graphics::drawRoundRect;
template <> const TFunc_Instances_Graphics_drawRoundRectComplex::TMethod TFunc_Instances_Graphics_drawRoundRectComplex::Method = &Instances::fl_display::Graphics::drawRoundRectComplex;
template <> const TFunc_Instances_Graphics_endFill::TMethod TFunc_Instances_Graphics_endFill::Method = &Instances::fl_display::Graphics::endFill;
template <> const TFunc_Instances_Graphics_lineGradientStyle::TMethod TFunc_Instances_Graphics_lineGradientStyle::Method = &Instances::fl_display::Graphics::lineGradientStyle;
template <> const TFunc_Instances_Graphics_lineStyle::TMethod TFunc_Instances_Graphics_lineStyle::Method = &Instances::fl_display::Graphics::lineStyle;
template <> const TFunc_Instances_Graphics_lineTo::TMethod TFunc_Instances_Graphics_lineTo::Method = &Instances::fl_display::Graphics::lineTo;
template <> const TFunc_Instances_Graphics_moveTo::TMethod TFunc_Instances_Graphics_moveTo::Method = &Instances::fl_display::Graphics::moveTo;

namespace Instances { namespace fl_display
{
    Graphics::Graphics(InstanceTraits::Traits& t)
    : Instances::fl::Object(t)
//##protect##"instance::Graphics::Graphics()$data"
    , pDispObj(NULL)
//##protect##"instance::Graphics::Graphics()$data"
    {
//##protect##"instance::Graphics::Graphics()$code"
//##protect##"instance::Graphics::Graphics()$code"
    }

    void Graphics::beginBitmapFill(const Value& result, Instances::fl_display::BitmapData* bitmap, Instances::fl_geom::Matrix* matrix, bool repeat, bool smooth)
    {
//##protect##"instance::Graphics::beginBitmapFill()"
        SF_UNUSED5(result, bitmap, matrix, repeat, smooth);

        if (!bitmap)
            return;

        ImageResource* pimageRes = bitmap->GetImageResource();
        if (!pimageRes)
            return;

        Render::Matrix2F mtxF;

        if (matrix)
        {
            mtxF = matrix->GetMatrixF();  
        }
        FillType fillType;
        if (smooth)
        {
            if (repeat) fillType = Fill_TiledSmoothImage;
            else        fillType = Fill_ClippedSmoothImage;
        }
        else
        {
            if (repeat) fillType = Fill_TiledImage;
            else        fillType = Fill_ClippedImage;
        }        

        pDrawing->AcquirePath(true);
        pDrawing->BeginBitmapFill(fillType, pimageRes, mtxF);
//##protect##"instance::Graphics::beginBitmapFill()"
    }
    void Graphics::beginFill(const Value& result, UInt32 color, Value::Number alpha)
    {
//##protect##"instance::Graphics::beginFill()"
        SF_UNUSED(result);
        SF_ASSERT(pDrawing);
        AcquirePath(true);
        pDrawing->BeginSolidFill(color | ((unsigned(alpha*255) & 0xFF) << 24));
//##protect##"instance::Graphics::beginFill()"
    }
    void Graphics::beginGradientFill(Value& result, unsigned argc, const Value* const argv)
    {
//##protect##"instance::Graphics::beginGradientFill()"

        // beginGradientFill(type:String, colors:Array, alphas:Array, ratios:Array, 
        //                   matrix:Matrix  = null, spreadMethod:String  = "pad", 
        //                   interpolationMethod:String  = "rgb", focalPointRatio:Number  = 0)

        SF_UNUSED(result);
        SF_ASSERT(pDrawing);
        CreateGradientHelper(argc, argv, pDrawing->CreateNewComplexFill());
        pDrawing->BeginFill();

//##protect##"instance::Graphics::beginGradientFill()"
    }
    void Graphics::clear(const Value& result)
    {
//##protect##"instance::Graphics::clear()"
        SF_UNUSED(result);
        SF_ASSERT(pDrawing && pDispObj);
        pDrawing->Clear();
        pDispObj->InvalidateHitResult();
        pDispObj->SetDirtyFlag();
//##protect##"instance::Graphics::clear()"
    }
    void Graphics::curveTo(const Value& result, Value::Number controlX, Value::Number controlY, Value::Number anchorX, Value::Number anchorY)
    {
//##protect##"instance::Graphics::curveTo()"
        SF_UNUSED(result);
        SF_ASSERT(pDrawing && pDispObj);
        pDrawing->CurveTo(            
            PixelsToTwips((float)controlX), 
            PixelsToTwips((float)controlY),
            PixelsToTwips((float)anchorX), 
            PixelsToTwips((float)anchorY));
        pDispObj->InvalidateHitResult();
//##protect##"instance::Graphics::curveTo()"
    }
    void Graphics::drawCircle(const Value& result, Value::Number x, Value::Number y, Value::Number radius)
    {
//##protect##"instance::Graphics::drawCircle()"
        SF_UNUSED(result);
        SF_ASSERT(pDrawing && pDispObj);

        // http://www.adobe.com/livedocs/flash/9.0/main/wwhelp/wwhimpl/common/html/wwhelp.htm?context=LiveDocs_Parts&file=00000995.html

        float fx = (float)x, fy = (float)y, fradius = (float)radius;
        const float tanPIover8 = (float)SF_MATH_TAN_PI_8, sinPIover4 = (float)SF_MATH_SIN_PI_4;

        pDrawing->MoveTo(PixelsToTwips(fx + fradius), PixelsToTwips(fy));
        pDrawing->CurveTo(PixelsToTwips(fx + fradius), 
                          PixelsToTwips(tanPIover8 * fradius + fy),
                          PixelsToTwips(sinPIover4 * fradius + fx),
                          PixelsToTwips(sinPIover4 * fradius + fy));
        pDrawing->CurveTo(PixelsToTwips(tanPIover8 * fradius + fx), 
                          PixelsToTwips(fy + fradius),
                          PixelsToTwips(fx),
                          PixelsToTwips(fy + fradius));
        pDrawing->CurveTo(PixelsToTwips(-tanPIover8 * fradius + fx), 
                          PixelsToTwips(fy + fradius),
                          PixelsToTwips(-sinPIover4 * fradius + fx),
                          PixelsToTwips(sinPIover4 * fradius + fy));
        pDrawing->CurveTo(PixelsToTwips(fx - fradius), 
                          PixelsToTwips(tanPIover8 * fradius + fy),
                          PixelsToTwips(fx - fradius),
                          PixelsToTwips(fy));
        pDrawing->CurveTo(PixelsToTwips(fx - fradius), 
                          PixelsToTwips(-tanPIover8 * fradius + fy),
                          PixelsToTwips(-sinPIover4 * fradius + fx),
                          PixelsToTwips(-sinPIover4 * fradius + fy));
        pDrawing->CurveTo(PixelsToTwips(-tanPIover8 * fradius + fx), 
                          PixelsToTwips(fy - fradius),
                          PixelsToTwips(fx),
                          PixelsToTwips(fy - fradius));
        pDrawing->CurveTo(PixelsToTwips(tanPIover8 * fradius + fx), 
                          PixelsToTwips(fy - fradius),
                          PixelsToTwips(sinPIover4 * fradius + fx),
                          PixelsToTwips(-sinPIover4 * fradius + fy));
        pDrawing->CurveTo(PixelsToTwips(fx + fradius), 
                          PixelsToTwips(-tanPIover8 * fradius + fy),
                          PixelsToTwips(fx + fradius),
                          PixelsToTwips(fy));

        pDispObj->InvalidateHitResult();
//##protect##"instance::Graphics::drawCircle()"
    }
    void Graphics::drawEllipse(const Value& result, Value::Number x, Value::Number y, Value::Number width, Value::Number height)
    {
//##protect##"instance::Graphics::drawEllipse()"
        SF_UNUSED(result);
        SF_ASSERT(pDrawing && pDispObj);

        float fx = (float)x, fy = (float)y, fxradius = (float)width * 0.5f, fyradius = (float)height * 0.5f;
        const float tanPIover8 = (float)SF_MATH_TAN_PI_8, sinPIover4 = (float)SF_MATH_SIN_PI_4;

        fx = fx + fxradius;
        fy = fy + fyradius;
        pDrawing->MoveTo(PixelsToTwips(fx + fxradius), PixelsToTwips(fy));
        pDrawing->CurveTo(PixelsToTwips(fx + fxradius), 
                          PixelsToTwips(tanPIover8 * fyradius + fy),
                          PixelsToTwips(sinPIover4 * fxradius + fx),
                          PixelsToTwips(sinPIover4 * fyradius + fy));
        pDrawing->CurveTo(PixelsToTwips(tanPIover8 * fxradius + fx), 
                          PixelsToTwips(fy + fyradius),
                          PixelsToTwips(fx),
                          PixelsToTwips(fy + fyradius));
        pDrawing->CurveTo(PixelsToTwips(-tanPIover8 * fxradius + fx), 
                          PixelsToTwips(fy + fyradius),
                          PixelsToTwips(-sinPIover4 * fxradius + fx),
                          PixelsToTwips(sinPIover4 * fyradius + fy));
        pDrawing->CurveTo(PixelsToTwips(fx - fxradius), 
                          PixelsToTwips(tanPIover8 * fyradius + fy),
                          PixelsToTwips(fx - fxradius),
                          PixelsToTwips(fy));
        pDrawing->CurveTo(PixelsToTwips(fx - fxradius), 
                          PixelsToTwips(-tanPIover8 * fyradius + fy),
                          PixelsToTwips(-sinPIover4 * fxradius + fx),
                          PixelsToTwips(-sinPIover4 * fyradius + fy));
        pDrawing->CurveTo(PixelsToTwips(-tanPIover8 * fxradius + fx), 
                          PixelsToTwips(fy - fyradius),
                          PixelsToTwips(fx),
                          PixelsToTwips(fy - fyradius));
        pDrawing->CurveTo(PixelsToTwips(tanPIover8 * fxradius + fx), 
                          PixelsToTwips(fy - fyradius),
                          PixelsToTwips(sinPIover4 * fxradius + fx),
                          PixelsToTwips(-sinPIover4 * fyradius + fy));
        pDrawing->CurveTo(PixelsToTwips(fx + fxradius), 
                          PixelsToTwips(-tanPIover8 * fyradius + fy),
                          PixelsToTwips(fx + fxradius),
                          PixelsToTwips(fy));

        pDispObj->InvalidateHitResult();
//##protect##"instance::Graphics::drawEllipse()"
    }
    void Graphics::drawRect(const Value& result, Value::Number x, Value::Number y, Value::Number width, Value::Number height)
    {
//##protect##"instance::Graphics::drawRect()"
        SF_UNUSED(result);
        SF_ASSERT(pDrawing && pDispObj);
        if (NumberUtil::IsNaN(width))
            return GetVM().ThrowArgumentError(VM::Error(VM::eInvalidArgumentError, GetVM() SF_DEBUG_ARG("width")));
        if (NumberUtil::IsNaN(height))
            return GetVM().ThrowArgumentError(VM::Error(VM::eInvalidArgumentError, GetVM() SF_DEBUG_ARG("height")));
        float x0 = (float)PixelsToTwips(x);
        float y0 = (float)PixelsToTwips(y);
        float x1 = (float)PixelsToTwips(x + width);
        float y1 = (float)PixelsToTwips(y + height);
        pDrawing->MoveTo(x0, y0);
        pDrawing->LineTo(x1, y0);
        pDrawing->LineTo(x1, y1);
        pDrawing->LineTo(x0, y1);
        pDrawing->LineTo(x0, y0);
        pDispObj->InvalidateHitResult();
//##protect##"instance::Graphics::drawRect()"
    }
    void Graphics::drawRoundRect(const Value& result, Value::Number x, Value::Number y, Value::Number width, Value::Number height, Value::Number ellipseWidth, Value::Number ellipseHeight)
    {
//##protect##"instance::Graphics::drawRoundRect()"
        SF_UNUSED(result);
        SF_ASSERT(pDrawing && pDispObj);

        if (NumberUtil::IsNaN(width))
            return GetVM().ThrowArgumentError(VM::Error(VM::eInvalidArgumentError, GetVM() SF_DEBUG_ARG("width")));
        if (NumberUtil::IsNaN(height))
            return GetVM().ThrowArgumentError(VM::Error(VM::eInvalidArgumentError, GetVM() SF_DEBUG_ARG("height")));
        if (NumberUtil::IsNaN(ellipseWidth))
            return GetVM().ThrowArgumentError(VM::Error(VM::eInvalidArgumentError, GetVM() SF_DEBUG_ARG("ellipseWidth")));
        if (NumberUtil::IsNaN(ellipseHeight))
            ellipseHeight = ellipseWidth;

        float fx = (float)x, fy = (float)y;
        float fx1 = fx + (float)width, fy1 = fy + (float)height;
        float fhalfWidth = (float)width * 0.5f, fhalfHeight = (float)height * 0.5f;
        float fexradius = Alg::Min((float)ellipseWidth * 0.5f, fhalfWidth), feyradius = Alg::Min((float)ellipseHeight * 0.5f, fhalfHeight);
        float fexcenter = fx1 - fexradius, feycenter = fy1 - feyradius;
        const float tanPIover8 = (float)SF_MATH_TAN_PI_8, sinPIover4 = (float)SF_MATH_SIN_PI_4;

        // http://www.adobe.com/livedocs/flash/9.0/main/wwhelp/wwhimpl/common/html/wwhelp.htm?context=LiveDocs_Parts&file=00000995.html

        pDrawing->MoveTo(PixelsToTwips(fx1), PixelsToTwips(fy1 - feyradius));

        pDrawing->CurveTo(PixelsToTwips(fexcenter + fexradius), 
                          PixelsToTwips(tanPIover8 * feyradius + feycenter),
                          PixelsToTwips(sinPIover4 * fexradius + fexcenter),
                          PixelsToTwips(sinPIover4 * feyradius + feycenter));
        pDrawing->CurveTo(PixelsToTwips(tanPIover8 * fexradius + fexcenter), 
                          PixelsToTwips(feycenter + feyradius),
                          PixelsToTwips(fexcenter),
                          PixelsToTwips(feycenter + feyradius));

        pDrawing->LineTo(PixelsToTwips(fx + fexradius), PixelsToTwips(fy1));
        fexcenter = fx + fexradius;

        pDrawing->CurveTo(PixelsToTwips(-tanPIover8 * fexradius + fexcenter), 
                          PixelsToTwips(feycenter + feyradius),
                          PixelsToTwips(-sinPIover4 * fexradius + fexcenter),
                          PixelsToTwips(sinPIover4 * feyradius + feycenter));
        pDrawing->CurveTo(PixelsToTwips(fexcenter - fexradius), 
                          PixelsToTwips(tanPIover8 * feyradius + feycenter),
                          PixelsToTwips(fexcenter - fexradius),
                          PixelsToTwips(feycenter));

        pDrawing->LineTo(PixelsToTwips(fx), PixelsToTwips(fy + feyradius));
        feycenter = fy + feyradius;

        pDrawing->CurveTo(PixelsToTwips(fexcenter - fexradius), 
                          PixelsToTwips(-tanPIover8 * feyradius + feycenter),
                          PixelsToTwips(-sinPIover4 * fexradius + fexcenter),
                          PixelsToTwips(-sinPIover4 * feyradius + feycenter));
        pDrawing->CurveTo(PixelsToTwips(-tanPIover8 * fexradius + fexcenter), 
                          PixelsToTwips(feycenter - feyradius),
                          PixelsToTwips(fexcenter),
                          PixelsToTwips(feycenter - feyradius));

        pDrawing->LineTo(PixelsToTwips(fx1 - fexradius), PixelsToTwips(fy));
        fexcenter = fx1 - fexradius;

        pDrawing->CurveTo(PixelsToTwips(tanPIover8 * fexradius + fexcenter), 
                          PixelsToTwips(feycenter - feyradius),
                          PixelsToTwips(sinPIover4 * fexradius + fexcenter),
                          PixelsToTwips(-sinPIover4 * feyradius + feycenter));
        pDrawing->CurveTo(PixelsToTwips(fexcenter + fexradius), 
                          PixelsToTwips(-tanPIover8 * feyradius + feycenter),
                          PixelsToTwips(fexcenter + fexradius),
                          PixelsToTwips(feycenter));

        pDispObj->InvalidateHitResult();
//##protect##"instance::Graphics::drawRoundRect()"
    }
    void Graphics::drawRoundRectComplex(Value& result, unsigned argc, const Value* const argv)
    {
//##protect##"instance::Graphics::drawRoundRectComplex()"
        SF_UNUSED(result);
        SF_ASSERT(pDrawing && pDispObj);
        /**
        * Draws a rounded rectangle using the size of a radius to draw the rounded corners. 
        * You must set the line style, fill, or both 
        * on the Graphics object before 
        * you call the <code>drawRoundRectComplex()</code> method 
        * by calling the <code>linestyle()</code>, 
        * <code>lineGradientStyle()</code>, <code>beginFill()</code>, 
        * <code>beginGradientFill()</code>, or 
        * <code>beginBitmapFill()</code> method.
        * 
        * @param graphics The Graphics object that draws the rounded rectangle.
        *
        * @param x The horizontal position relative to the 
        * registration point of the parent display object, in pixels.
        * 
        * @param y The vertical position relative to the 
        * registration point of the parent display object, in pixels.
        * 
        * @param width The width of the round rectangle, in pixels.
        * 
        * @param height The height of the round rectangle, in pixels.
        * 
        * @param topLeftRadius The radius of the upper-left corner, in pixels.
        * 
        * @param topRightRadius The radius of the upper-right corner, in pixels.
        * 
        * @param bottomLeftRadius The radius of the bottom-left corner, in pixels.
        * 
        * @param bottomRightRadius The radius of the bottom-right corner, in pixels.
        *
        *  
        *  @langversion 3.0
        *  @playerversion Flash 9
        *  @playerversion AIR 1.1
        *  @productversion Flex 3
        */
        if (argc < 8)
            return GetVM().ThrowArgumentError(VM::Error(VM::eWrongArgumentCountError, GetVM()
                SF_DEBUG_ARG("drawRoundRectComplex")
                SF_DEBUG_ARG(8)
                SF_DEBUG_ARG(8)
                SF_DEBUG_ARG(argc)
                ));

        Value::Number x, y, width, height, topLeftRadius, topRightRadius, bottomLeftRadius, bottomRightRadius;
        argv[0].Convert2Number(x).DoNotCheck();
        argv[1].Convert2Number(y).DoNotCheck();
        argv[2].Convert2Number(width).DoNotCheck();
        argv[3].Convert2Number(height).DoNotCheck();
        argv[4].Convert2Number(topLeftRadius).DoNotCheck();
        argv[5].Convert2Number(topRightRadius).DoNotCheck();
        argv[6].Convert2Number(bottomLeftRadius).DoNotCheck();
        argv[7].Convert2Number(bottomRightRadius).DoNotCheck();
            
        if (NumberUtil::IsNaN(width))
            return GetVM().ThrowArgumentError(VM::Error(VM::eInvalidArgumentError, GetVM() SF_DEBUG_ARG("width")));
        if (NumberUtil::IsNaN(height))
            return GetVM().ThrowArgumentError(VM::Error(VM::eInvalidArgumentError, GetVM() SF_DEBUG_ARG("height")));
        if (NumberUtil::IsNaN(topLeftRadius))
            return GetVM().ThrowArgumentError(VM::Error(VM::eInvalidArgumentError, GetVM() SF_DEBUG_ARG("topLeftRadius")));
        if (NumberUtil::IsNaN(topRightRadius))
            return GetVM().ThrowArgumentError(VM::Error(VM::eInvalidArgumentError, GetVM() SF_DEBUG_ARG("topRightRadius")));
        if (NumberUtil::IsNaN(bottomLeftRadius))
            return GetVM().ThrowArgumentError(VM::Error(VM::eInvalidArgumentError, GetVM() SF_DEBUG_ARG("bottomLeftRadius")));
        if (NumberUtil::IsNaN(bottomRightRadius))
            return GetVM().ThrowArgumentError(VM::Error(VM::eInvalidArgumentError, GetVM() SF_DEBUG_ARG("bottomRightRadius")));

        Value::Number xw = x + width, yh = y + height;

        Value::Number minSize = (width < height) ? width * 2 : height * 2;
        topLeftRadius = (topLeftRadius < minSize) ? topLeftRadius : minSize;
        topRightRadius = (topRightRadius < minSize) ? topRightRadius : minSize;
        bottomLeftRadius = (bottomLeftRadius < minSize) ? bottomLeftRadius : minSize;
        bottomRightRadius = (bottomRightRadius < minSize) ? bottomRightRadius : minSize;

        const Value::Number r1 = 1.0 - SF_MATH_SIN_PI_4; // 0.292893218813453 
        const Value::Number r2 = 1.0 - SF_MATH_TAN_PI_8; // 0.585786437626905

        // bottom-right corner
        Value::Number a = bottomRightRadius * r1;    // radius - anchor pt;
        Value::Number s = bottomRightRadius * r2;    // radius - control pt;

        float xwft = (float)PixelsToTwips(xw);

        pDrawing->MoveTo(xwft, (float)PixelsToTwips(yh - bottomRightRadius));
        pDrawing->CurveTo(xwft, 
                         (float)PixelsToTwips(yh - s),
                         (float)PixelsToTwips(xw - a),
                         (float)PixelsToTwips(yh - a));
        pDrawing->CurveTo((float)PixelsToTwips(xw - s), 
                         (float)PixelsToTwips(yh),
                         (float)PixelsToTwips(xw - bottomRightRadius),
                         (float)PixelsToTwips(yh));


        // bottom-left corner
        a = bottomLeftRadius * r1;
        s = bottomLeftRadius * r2;

        pDrawing->LineTo((float)PixelsToTwips(x + bottomLeftRadius), (float)PixelsToTwips(yh));
        pDrawing->CurveTo((float)PixelsToTwips(x + s), 
                          (float)PixelsToTwips(yh),
                          (float)PixelsToTwips(x + a),
                          (float)PixelsToTwips(yh - a));
        pDrawing->CurveTo((float)PixelsToTwips(x), 
                          (float)PixelsToTwips(yh - s),
                          (float)PixelsToTwips(x),
                          (float)PixelsToTwips(yh - bottomLeftRadius));

        // top-left corner
        a = topLeftRadius * r1;
        s = topLeftRadius * r2;

        pDrawing->LineTo((float)PixelsToTwips(x), (float)PixelsToTwips(y + topLeftRadius));
        pDrawing->CurveTo((float)PixelsToTwips(x), 
                          (float)PixelsToTwips(y + s),
                          (float)PixelsToTwips(x + a),
                          (float)PixelsToTwips(y + a));
        pDrawing->CurveTo((float)PixelsToTwips(x + s), 
                          (float)PixelsToTwips(y),
                          (float)PixelsToTwips(x + topLeftRadius),
                          (float)PixelsToTwips(y));

        // top-right corner
        a = topRightRadius * r1;
        s = topRightRadius * r2;
        pDrawing->LineTo((float)PixelsToTwips(xw - topRightRadius), (float)PixelsToTwips(y));
        pDrawing->CurveTo((float)PixelsToTwips(xw - s), 
                          (float)PixelsToTwips(y),
                          (float)PixelsToTwips(xw - a),
                          (float)PixelsToTwips(y + a));
        pDrawing->CurveTo((float)PixelsToTwips(xw), 
                          (float)PixelsToTwips(y + s),
                          (float)PixelsToTwips(xw),
                          (float)PixelsToTwips(y + topRightRadius));
        pDrawing->LineTo((float)PixelsToTwips(xw), (float)PixelsToTwips(yh - bottomRightRadius));

        pDispObj->InvalidateHitResult();
//##protect##"instance::Graphics::drawRoundRectComplex()"
    }
    void Graphics::endFill(const Value& result)
    {
//##protect##"instance::Graphics::endFill()"
        SF_UNUSED(result);
        SF_ASSERT(pDrawing);
        AcquirePath(true);
        pDrawing->EndFill();
//##protect##"instance::Graphics::endFill()"
    }
    void Graphics::lineGradientStyle(Value& result, unsigned argc, const Value* const argv)
    {
//##protect##"instance::Graphics::lineGradientStyle()"
        
        // lineGradientStyle(type:String, colors:Array, alphas:Array, ratios:Array, 
        //                   matrix:Matrix = null, spreadMethod:String = "pad", 
        //                   interpolationMethod:String = "rgb", focalPointRatio:Number = 0)

        SF_UNUSED(result);
        SF_ASSERT(pDrawing);

        CreateGradientHelper(argc, argv, pDrawing->CreateLineComplexFill());
//##protect##"instance::Graphics::lineGradientStyle()"
    }
    void Graphics::lineStyle(Value& result, unsigned argc, const Value* const argv)
    {
//##protect##"instance::Graphics::lineStyle()"
        SF_ASSERT(pDrawing); 
        SF_UNUSED(result);

        Value::Number r             = 0;
        float thickness             = 0;
        UInt32 color                = 0;
        float alpha                 = 1.0;
        bool   pixelHinting         = false;
        unsigned scaleMode          = Render::StrokeScaling_Normal;
        unsigned caps               = Render::StrokeCap_Round | Render::StrokeEndCap_Round;
        unsigned joints             = Render::StrokeJoin_Round;
        float miterLimit            = 3.0;

        if (argc == 0)
            return;

        if (!argv[0].Convert2Number(r))
            return;
        thickness = (float)r;

        if (argc > 1)
            if (!argv[1].Convert2UInt32(color))
                return;

        if (argc > 2)
        {
            if (!argv[2].Convert2Number(r))
                return;
            alpha = (float)r;
        }
        if (argc > 3)
            pixelHinting = argv[3].Convert2Boolean();
        if (argc > 4)
        {
            ASString sm = GetVM().GetStringManager().CreateEmptyString();
            if (!argv[4].Convert2String(sm))
                return;

            if (sm == "vertical")
                scaleMode = Render::StrokeScaling_Vertical;
            else if (sm == "horizontal")
                scaleMode = Render::StrokeScaling_Horizontal;
            else if (sm == "none")
                scaleMode = Render::StrokeScaling_None;
        }
        if (argc > 5)
        {
            ASString sm = GetVM().GetStringManager().CreateEmptyString();
            if (!argv[5].Convert2String(sm))
                return;

            if (sm == "none")
                caps = Render::StrokeCap_None | Render::StrokeEndCap_None;
            else if (sm == "square")
                caps = Render::StrokeCap_Square | Render::StrokeEndCap_Square;
        }
        if (argc > 6)
        {
            ASString sm = GetVM().GetStringManager().CreateEmptyString();
            if (!argv[6].Convert2String(sm))
                return;

            if (sm == "miter")
                joints = Render::StrokeJoin_Miter;
            else if (sm == "bevel")
                joints = Render::StrokeJoin_Bevel;
        }
        if (argc > 7)
        {
            if (!argv[7].Convert2Number(r))
                return;
            miterLimit = (float)r;
        }
        
        UInt32 rgba = ((unsigned(alpha * 255) & 0xFF) << 24) | (color & 0xFFFFFF);
        pDrawing->ChangeLineStyle(PixelsToTwips(thickness), rgba, pixelHinting, 
            scaleMode, caps, joints, miterLimit);
//##protect##"instance::Graphics::lineStyle()"
    }
    void Graphics::lineTo(const Value& result, Value::Number x, Value::Number y)
    {
//##protect##"instance::Graphics::lineTo()"
        SF_UNUSED(result);

        SF_ASSERT(pDrawing && pDispObj);
        pDrawing->LineTo(
            (float)PixelsToTwips(x), 
            (float)PixelsToTwips(y));
        pDispObj->InvalidateHitResult();
//##protect##"instance::Graphics::lineTo()"
    }
    void Graphics::moveTo(const Value& result, Value::Number x, Value::Number y)
    {
//##protect##"instance::Graphics::moveTo()"
        SF_UNUSED(result);

        SF_ASSERT(pDrawing && pDispObj);
        AcquirePath(false);
        pDrawing->MoveTo((float)PixelsToTwips(x), (float)PixelsToTwips(y));
        pDispObj->InvalidateHitResult();
//##protect##"instance::Graphics::moveTo()"
    }

//##protect##"instance$methods"
    void Graphics::AcquirePath(bool newShapeFlag)
    {
        SF_ASSERT(pDrawing && pDispObj);
        pDispObj->SetDirtyFlag();
        pDispObj->InvalidateHitResult();
        pDrawing->AcquirePath(newShapeFlag);
    }

    void Graphics::CreateGradientHelper(unsigned argc, const Value* const argv, Render::ComplexFill* complexFill)
    {
        if (argc < 4) return;
        // type:String
        ASString fillTypeStr(argv[0].AsString());
        if (fillTypeStr != "linear" && fillTypeStr != "radial")
        {
            GetVM().ThrowArgumentError(VM::Error(VM::eInvalidEnumError, GetVM() SF_DEBUG_ARG("type")));
            return;
        }
        // colors:Array
        if (!argv[1].IsObject() || 
            argv[1].GetObject()->GetTraitsType() != Traits_Array || 
            argv[1].GetObject()->GetTraits().IsClassTraits()) 
            return;
        Instances::fl::Array* colors = static_cast<Instances::fl::Array*>(argv[1].GetObject());
        // alphas:Array
        if (!argv[2].IsObject() || 
            argv[2].GetObject()->GetTraitsType() != Traits_Array || 
            argv[2].GetObject()->GetTraits().IsClassTraits()) 
            return;
        Instances::fl::Array* alphas = static_cast<Instances::fl::Array*>(argv[2].GetObject());
        // ratios:Array
        if (!argv[3].IsObject() || 
            argv[3].GetObject()->GetTraitsType() != Traits_Array || 
            argv[3].GetObject()->GetTraits().IsClassTraits()) 
            return;
        Instances::fl::Array* ratios = static_cast<Instances::fl::Array*>(argv[3].GetObject());
        // matrix:Matrix = null
        Matrix2DDouble matrix;
        if (argc > 4 && GetVM().IsOfType(argv[4], "flash.geom.Matrix", GetVM().GetCurrentAppDomain()))
        {
            matrix = static_cast<Instances::fl_geom::Matrix*>(argv[4].GetObject())->GetMatrix();
        }

        int spreadMethod = 0; // pad
        bool linearRGB = false;
        float focalPointRatio = 0;
        if (argc > 5)
        {
            // spreadMethod:String
            ASString str(argv[5].AsString());
            if (str == "reflect") spreadMethod = 1;
            if (str == "repeat") spreadMethod = 2;
            if (argc > 6)
            {
                // interpolationMethod:String
                linearRGB = argv[6].AsString() == "linearRGB";
                if (argc > 7)
                {
                    // focalPointRatio:Number
                    focalPointRatio = (float)argv[7].AsNumber();
                    if (NumberUtil::IsNaN(focalPointRatio))
                        focalPointRatio = 0;
                    else if (focalPointRatio < -1) focalPointRatio = -1;
                    else if (focalPointRatio > 1) focalPointRatio = 1;
                }
            }
        }

        // Create Gradient itself
        Render::GradientType gradType = Render::GradientLinear;
        if (fillTypeStr == "radial")
        {
            gradType = Render::GradientRadial;
            if (focalPointRatio != 0) 
                gradType = Render::GradientFocalPoint;
        }
        // Gradient data must live in a global heap since it is used as a key in ResourceLib.
        complexFill->pGradient = *SF_NEW Render::GradientData(gradType, (UInt16)colors->GetSize(), linearRGB);

        if (complexFill->pGradient)
        {
            complexFill->pGradient->SetFocalRatio(focalPointRatio);

            for (UPInt i = 0; i < colors->GetSize(); i++)
            {
                UInt32 color;
                colors->At(i).Convert2UInt32(color).DoNotCheck();
                unsigned rgba = unsigned(color | 0xFF000000);

                Value::Number a;
                alphas->At(i).Convert2Number(a).DoNotCheck();
                unsigned alpha = Alg::Clamp<unsigned>((unsigned)(a * 255.0), 0, 255); 
                rgba &= 0xFFFFFF;            
                rgba |= alpha << 24;

                Value::Number r;
                ratios->At(i).Convert2Number(r).DoNotCheck();
                float ratio = (float)r;
                ratio = Alg::Clamp(ratio, 0.0f, 255.0f);

                GradientRecord& record = complexFill->pGradient->At(static_cast<unsigned>(i));
                record.Ratio = (UByte)ratio;
                record.ColorV = rgba;
            }

            AcquirePath(true);
            Render::Matrix2F matF;
            matF.Sx() = (float)matrix.Sx();
            matF.Shy() = (float)matrix.Shy();
            matF.Shx() = (float)matrix.Shx();
            matF.Sy() = (float)matrix.Sy();
            matF.Tx() = (float)PixelsToTwips(matrix.Tx());
            matF.Ty() = (float)PixelsToTwips(matrix.Ty());
            complexFill->ImageMatrix.SetIdentity();

            if (gradType == Render::GradientLinear)
            {
                complexFill->ImageMatrix.AppendScaling(1.0f / 32768.F);
                complexFill->ImageMatrix.AppendTranslation(0.5F, 0.F);
            }
            else
            {
                complexFill->ImageMatrix.AppendScaling(1.0f / 32768.F);
                complexFill->ImageMatrix.AppendTranslation(0.5F, 0.5F);
                // gradient's square size is 32768x32768 (-16,384 - 16,384)
            }
            complexFill->ImageMatrix.Prepend(matF.GetInverse());
        }
    }
//##protect##"instance$methods"

}} // namespace Instances

namespace InstanceTraits { namespace fl_display
{
    const ThunkInfo Graphics::ti[Graphics::ThunkInfoNum] = {
        {TFunc_Instances_Graphics_beginBitmapFill::Func, NULL, "beginBitmapFill", NULL, Abc::NS_Public, CT_Method, 1, 4},
        {TFunc_Instances_Graphics_beginFill::Func, NULL, "beginFill", NULL, Abc::NS_Public, CT_Method, 1, 2},
        {TFunc_Instances_Graphics_beginGradientFill::Func, NULL, "beginGradientFill", NULL, Abc::NS_Public, CT_Method, 0, SF_AS3_VARARGNUM},
        {TFunc_Instances_Graphics_clear::Func, NULL, "clear", NULL, Abc::NS_Public, CT_Method, 0, 0},
        {TFunc_Instances_Graphics_curveTo::Func, NULL, "curveTo", NULL, Abc::NS_Public, CT_Method, 4, 4},
        {TFunc_Instances_Graphics_drawCircle::Func, NULL, "drawCircle", NULL, Abc::NS_Public, CT_Method, 3, 3},
        {TFunc_Instances_Graphics_drawEllipse::Func, NULL, "drawEllipse", NULL, Abc::NS_Public, CT_Method, 4, 4},
        {TFunc_Instances_Graphics_drawRect::Func, NULL, "drawRect", NULL, Abc::NS_Public, CT_Method, 4, 4},
        {TFunc_Instances_Graphics_drawRoundRect::Func, NULL, "drawRoundRect", NULL, Abc::NS_Public, CT_Method, 5, 6},
        {TFunc_Instances_Graphics_drawRoundRectComplex::Func, NULL, "drawRoundRectComplex", NULL, Abc::NS_Public, CT_Method, 0, SF_AS3_VARARGNUM},
        {TFunc_Instances_Graphics_endFill::Func, NULL, "endFill", NULL, Abc::NS_Public, CT_Method, 0, 0},
        {TFunc_Instances_Graphics_lineGradientStyle::Func, NULL, "lineGradientStyle", NULL, Abc::NS_Public, CT_Method, 0, SF_AS3_VARARGNUM},
        {TFunc_Instances_Graphics_lineStyle::Func, NULL, "lineStyle", NULL, Abc::NS_Public, CT_Method, 0, SF_AS3_VARARGNUM},
        {TFunc_Instances_Graphics_lineTo::Func, NULL, "lineTo", NULL, Abc::NS_Public, CT_Method, 2, 2},
        {TFunc_Instances_Graphics_moveTo::Func, NULL, "moveTo", NULL, Abc::NS_Public, CT_Method, 2, 2},
    };

    Graphics::Graphics(VM& vm, const ClassInfo& ci)
    : CTraits(vm, ci)
    {
//##protect##"InstanceTraits::Graphics::Graphics()"
//##protect##"InstanceTraits::Graphics::Graphics()"
        SetMemSize(sizeof(Instances::fl_display::Graphics));

    }

    void Graphics::MakeObject(Value& result, Traits& t)
    {
        result = MakeInstance(static_cast<Graphics&>(t));
    }

//##protect##"instance_traits$methods"
//##protect##"instance_traits$methods"

}} // namespace InstanceTraits


namespace ClassTraits { namespace fl_display
{
    Graphics::Graphics(VM& vm)
    : Traits(vm, AS3::fl_display::GraphicsCI)
    {
//##protect##"ClassTraits::Graphics::Graphics()"
//##protect##"ClassTraits::Graphics::Graphics()"
        MemoryHeap* mh = vm.GetMemoryHeap();

        Pickable<InstanceTraits::Traits> it(SF_HEAP_NEW_ID(mh, StatMV_VM_ITraits_Mem) InstanceTraits::fl_display::Graphics(vm, AS3::fl_display::GraphicsCI));
        SetInstanceTraits(it);

        // There is no problem with Pickable not assigned to anything here. Class constructor takes care of this.
        Pickable<Class> cl(SF_HEAP_NEW_ID(mh, StatMV_VM_Class_Mem) Class(*this));

    }

    Pickable<Traits> Graphics::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(SF_HEAP_NEW_ID(vm.GetMemoryHeap(), StatMV_VM_CTraits_Mem) Graphics(vm));
    }
//##protect##"ClassTraits$methods"
//##protect##"ClassTraits$methods"

}} // namespace ClassTraits

namespace fl_display
{
    const TypeInfo GraphicsTI = {
        TypeInfo::CompileTime | TypeInfo::Final,
        "Graphics", "flash.display", &fl::ObjectTI,
        TypeInfo::None
    };

    const ClassInfo GraphicsCI = {
        &GraphicsTI,
        ClassTraits::fl_display::Graphics::MakeClassTraits,
        0,
        0,
        InstanceTraits::fl_display::Graphics::ThunkInfoNum,
        0,
        NULL,
        NULL,
        InstanceTraits::fl_display::Graphics::ti,
        NULL,
    };
}; // namespace fl_display


}}} // namespace Scaleform { namespace GFx { namespace AS3

