//##protect##"disclaimer"
/**************************************************************************

Filename    :   AS3_Obj_ReferenceError.h
Content     :   
Created     :   Jan, 2010
Authors     :   Sergey Sikorskiy

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/
//##protect##"disclaimer"

#ifndef INC_AS3_Obj_ReferenceError_H
#define INC_AS3_Obj_ReferenceError_H

#include "AS3_Obj_Error.h"
//##protect##"includes"
//##protect##"includes"


namespace Scaleform { namespace GFx { namespace AS3 
{
// Forward declaration.
namespace fl
{
    extern const TypeInfo ReferenceErrorTI;
    extern const ClassInfo ReferenceErrorCI;
} // namespace fl

namespace ClassTraits { namespace fl
{
    class ReferenceError;
}}

namespace InstanceTraits { namespace fl
{
    class ReferenceError;
}}

namespace Classes { namespace fl
{
    class ReferenceError;
}}

//##protect##"forward_declaration"
//##protect##"forward_declaration"
    
namespace ClassTraits { namespace fl
{
    class ReferenceError : public Traits
    {
#ifdef GFX_AS3_VERBOSE
    private:
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ReferenceError"; }
#endif
    public:
        typedef Classes::fl::ReferenceError ClassType;

    public:
        ReferenceError(VM& vm);
        static Pickable<Traits> MakeClassTraits(VM& vm);
//##protect##"ClassTraits$methods"
//##protect##"ClassTraits$methods"

    };
}}
//##protect##"methods"
//##protect##"methods"

}}} // namespace Scaleform { namespace GFx { namespace AS3

#endif

