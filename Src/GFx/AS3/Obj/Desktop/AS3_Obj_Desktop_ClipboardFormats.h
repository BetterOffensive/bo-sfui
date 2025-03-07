//##protect##"disclaimer"
/**************************************************************************

Filename    :   AS3_Obj_Desktop_ClipboardFormats.h
Content     :   
Created     :   Jan, 2010
Authors     :   Sergey Sikorskiy

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/
//##protect##"disclaimer"

#ifndef INC_AS3_Obj_Desktop_ClipboardFormats_H
#define INC_AS3_Obj_Desktop_ClipboardFormats_H

#include "../AS3_Obj_Object.h"
//##protect##"includes"
//##protect##"includes"


namespace Scaleform { namespace GFx { namespace AS3 
{
// Forward declaration.
namespace fl_desktop
{
    extern const TypeInfo ClipboardFormatsTI;
    extern const ClassInfo ClipboardFormatsCI;
} // namespace fl_desktop

namespace ClassTraits { namespace fl_desktop
{
    class ClipboardFormats;
}}

namespace InstanceTraits { namespace fl_desktop
{
    class ClipboardFormats;
}}

namespace Classes { namespace fl_desktop
{
    class ClipboardFormats;
}}

//##protect##"forward_declaration"
//##protect##"forward_declaration"
    
namespace ClassTraits { namespace fl_desktop
{
    class ClipboardFormats : public Traits
    {
#ifdef GFX_AS3_VERBOSE
    private:
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ClipboardFormats"; }
#endif
    public:
        typedef Classes::fl_desktop::ClipboardFormats ClassType;

    public:
        ClipboardFormats(VM& vm);
        static Pickable<Traits> MakeClassTraits(VM& vm);
        enum { MemberInfoNum = 2 };
        static const MemberInfo mi[MemberInfoNum];
//##protect##"ClassTraits$methods"
//##protect##"ClassTraits$methods"

    };
}}

namespace Classes { namespace fl_desktop
{
    class ClipboardFormats : public Class
    {
        friend class ClassTraits::fl_desktop::ClipboardFormats;
        static const TypeInfo& GetTypeInfo() { return AS3::fl_desktop::ClipboardFormatsTI; }
        
#ifdef GFX_AS3_VERBOSE
    private:
        virtual const char* GetAS3ObjectType() const { return "Classes::ClipboardFormats"; }
#endif
    public:
        typedef ClipboardFormats SelfType;
        typedef ClipboardFormats ClassType;
        
    private:
        ClipboardFormats(ClassTraits::Traits& t);
       
    private:
        SelfType& GetSelf()
        {
            return *this;
        }

//##protect##"class_$methods"
//##protect##"class_$methods"

    public:
        // AS3 API members.
        const char* HTML_FORMAT;
        const char* TEXT_FORMAT;

//##protect##"class_$data"
//##protect##"class_$data"

    };
}}

//##protect##"methods"
//##protect##"methods"

}}} // namespace Scaleform { namespace GFx { namespace AS3

#endif

