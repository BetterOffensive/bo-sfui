//##protect##"disclaimer"
/**************************************************************************

Filename    :   AS3_Obj_Display_StageAlign.h
Content     :   
Created     :   Jan, 2010
Authors     :   Sergey Sikorskiy

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/
//##protect##"disclaimer"

#ifndef INC_AS3_Obj_Display_StageAlign_H
#define INC_AS3_Obj_Display_StageAlign_H

#include "../AS3_Obj_Object.h"
//##protect##"includes"
//##protect##"includes"


namespace Scaleform { namespace GFx { namespace AS3 
{
// Forward declaration.
namespace fl_display
{
    extern const TypeInfo StageAlignTI;
    extern const ClassInfo StageAlignCI;
} // namespace fl_display

namespace ClassTraits { namespace fl_display
{
    class StageAlign;
}}

namespace InstanceTraits { namespace fl_display
{
    class StageAlign;
}}

namespace Classes { namespace fl_display
{
    class StageAlign;
}}

//##protect##"forward_declaration"
//##protect##"forward_declaration"
    
namespace ClassTraits { namespace fl_display
{
    class StageAlign : public Traits
    {
#ifdef GFX_AS3_VERBOSE
    private:
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::StageAlign"; }
#endif
    public:
        typedef Classes::fl_display::StageAlign ClassType;

    public:
        StageAlign(VM& vm);
        static Pickable<Traits> MakeClassTraits(VM& vm);
        enum { MemberInfoNum = 8 };
        static const MemberInfo mi[MemberInfoNum];
//##protect##"ClassTraits$methods"
//##protect##"ClassTraits$methods"

    };
}}

namespace Classes { namespace fl_display
{
    class StageAlign : public Class
    {
        friend class ClassTraits::fl_display::StageAlign;
        static const TypeInfo& GetTypeInfo() { return AS3::fl_display::StageAlignTI; }
        
#ifdef GFX_AS3_VERBOSE
    private:
        virtual const char* GetAS3ObjectType() const { return "Classes::StageAlign"; }
#endif
    public:
        typedef StageAlign SelfType;
        typedef StageAlign ClassType;
        
    private:
        StageAlign(ClassTraits::Traits& t);
       
    private:
        SelfType& GetSelf()
        {
            return *this;
        }

//##protect##"class_$methods"
//##protect##"class_$methods"

    public:
        // AS3 API members.
        const char* BOTTOM;
        const char* BOTTOM_LEFT;
        const char* BOTTOM_RIGHT;
        const char* LEFT;
        const char* RIGHT;
        const char* TOP;
        const char* TOP_LEFT;
        const char* TOP_RIGHT;

//##protect##"class_$data"
//##protect##"class_$data"

    };
}}

//##protect##"methods"
//##protect##"methods"

}}} // namespace Scaleform { namespace GFx { namespace AS3

#endif

