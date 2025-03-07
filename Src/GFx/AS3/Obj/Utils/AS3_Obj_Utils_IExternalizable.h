//##protect##"disclaimer"
/**************************************************************************

Filename    :   AS3_Obj_Utils_IExternalizable.h
Content     :   
Created     :   Jan, 2010
Authors     :   Sergey Sikorskiy

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/
//##protect##"disclaimer"

#ifndef INC_AS3_Obj_Utils_IExternalizable_H
#define INC_AS3_Obj_Utils_IExternalizable_H

#include "../AS3_Obj_Object.h"
//##protect##"includes"
//##protect##"includes"


namespace Scaleform { namespace GFx { namespace AS3 
{
// Forward declaration.
namespace fl_utils
{
    extern const TypeInfo IExternalizableTI;
    extern const ClassInfo IExternalizableCI;
} // namespace fl_utils

namespace ClassTraits { namespace fl_utils
{
    class IExternalizable;
}}

namespace InstanceTraits { namespace fl_utils
{
    class IExternalizable;
}}

namespace Classes { namespace fl_utils
{
    class IExternalizable;
}}

//##protect##"forward_declaration"
namespace Instances
{
    class IDataInput;
    class IDataOutput;
}
//##protect##"forward_declaration"
    
namespace ClassTraits { namespace fl_utils
{
    class IExternalizable : public Traits
    {
#ifdef GFX_AS3_VERBOSE
    private:
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::IExternalizable"; }
#endif
    public:
        typedef Classes::fl_utils::IExternalizable ClassType;

    public:
        IExternalizable(VM& vm);
        static Pickable<Traits> MakeClassTraits(VM& vm);
//##protect##"ClassTraits$methods"
//##protect##"ClassTraits$methods"

    };
}}
//##protect##"methods"
//##protect##"methods"

}}} // namespace Scaleform { namespace GFx { namespace AS3

#endif

