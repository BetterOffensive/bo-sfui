//##protect##"disclaimer"
/**************************************************************************

Filename    :   AS3_Obj_Utils_IDataOutput.h
Content     :   
Created     :   Jan, 2010
Authors     :   Sergey Sikorskiy

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/
//##protect##"disclaimer"

#ifndef INC_AS3_Obj_Utils_IDataOutput_H
#define INC_AS3_Obj_Utils_IDataOutput_H

#include "../AS3_Obj_Object.h"
//##protect##"includes"
//##protect##"includes"


namespace Scaleform { namespace GFx { namespace AS3 
{
// Forward declaration.
namespace fl_utils
{
    extern const TypeInfo IDataOutputTI;
    extern const ClassInfo IDataOutputCI;
} // namespace fl_utils
namespace fl
{
    extern const TypeInfo StringTI;
    extern const ClassInfo StringCI;
    extern const TypeInfo uintTI;
    extern const ClassInfo uintCI;
} // namespace fl

namespace ClassTraits { namespace fl_utils
{
    class IDataOutput;
}}

namespace InstanceTraits { namespace fl_utils
{
    class IDataOutput;
}}

namespace Classes { namespace fl_utils
{
    class IDataOutput;
}}

//##protect##"forward_declaration"
namespace Instances
{
    class ByteArray;
}
//##protect##"forward_declaration"
    
namespace ClassTraits { namespace fl_utils
{
    class IDataOutput : public Traits
    {
#ifdef GFX_AS3_VERBOSE
    private:
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::IDataOutput"; }
#endif
    public:
        typedef Classes::fl_utils::IDataOutput ClassType;

    public:
        IDataOutput(VM& vm);
        static Pickable<Traits> MakeClassTraits(VM& vm);
//##protect##"ClassTraits$methods"
//##protect##"ClassTraits$methods"

    };
}}
//##protect##"methods"
//##protect##"methods"

}}} // namespace Scaleform { namespace GFx { namespace AS3

#endif

