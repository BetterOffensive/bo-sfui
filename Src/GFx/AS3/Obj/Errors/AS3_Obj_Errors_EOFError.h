//##protect##"disclaimer"
/**************************************************************************

Filename    :   AS3_Obj_Errors_EOFError.h
Content     :   
Created     :   Jan, 2010
Authors     :   Sergey Sikorskiy

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/
//##protect##"disclaimer"

#ifndef INC_AS3_Obj_Errors_EOFError_H
#define INC_AS3_Obj_Errors_EOFError_H

#include "AS3_Obj_Errors_IOError.h"
//##protect##"includes"
//##protect##"includes"


namespace Scaleform { namespace GFx { namespace AS3 
{
// Forward declaration.
namespace fl_errors
{
    extern const TypeInfo EOFErrorTI;
    extern const ClassInfo EOFErrorCI;
} // namespace fl_errors

namespace ClassTraits { namespace fl_errors
{
    class EOFError;
}}

namespace InstanceTraits { namespace fl_errors
{
    class EOFError;
}}

namespace Classes { namespace fl_errors
{
    class EOFError;
}}

//##protect##"forward_declaration"
//##protect##"forward_declaration"
    
namespace ClassTraits { namespace fl_errors
{
    class EOFError : public Traits
    {
#ifdef GFX_AS3_VERBOSE
    private:
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::EOFError"; }
#endif
    public:
        typedef Classes::fl_errors::EOFError ClassType;

    public:
        EOFError(VM& vm);
        static Pickable<Traits> MakeClassTraits(VM& vm);
//##protect##"ClassTraits$methods"
//##protect##"ClassTraits$methods"

    };
}}
//##protect##"methods"
//##protect##"methods"

}}} // namespace Scaleform { namespace GFx { namespace AS3

#endif

