//##protect##"disclaimer"
/**************************************************************************

Filename    :   AS3_Obj_RangeError.h
Content     :   
Created     :   Jan, 2010
Authors     :   Sergey Sikorskiy

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/
//##protect##"disclaimer"

#ifndef INC_AS3_Obj_RangeError_H
#define INC_AS3_Obj_RangeError_H

#include "AS3_Obj_Error.h"
//##protect##"includes"
//##protect##"includes"


namespace Scaleform { namespace GFx { namespace AS3 
{
// Forward declaration.
namespace fl
{
    extern const TypeInfo RangeErrorTI;
    extern const ClassInfo RangeErrorCI;
} // namespace fl

namespace ClassTraits { namespace fl
{
    class RangeError;
}}

namespace InstanceTraits { namespace fl
{
    class RangeError;
}}

namespace Classes { namespace fl
{
    class RangeError;
}}

//##protect##"forward_declaration"
//##protect##"forward_declaration"
    
namespace ClassTraits { namespace fl
{
    class RangeError : public Traits
    {
#ifdef GFX_AS3_VERBOSE
    private:
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::RangeError"; }
#endif
    public:
        typedef Classes::fl::RangeError ClassType;

    public:
        RangeError(VM& vm);
        static Pickable<Traits> MakeClassTraits(VM& vm);
//##protect##"ClassTraits$methods"
//##protect##"ClassTraits$methods"

    };
}}
//##protect##"methods"
//##protect##"methods"

}}} // namespace Scaleform { namespace GFx { namespace AS3

#endif

