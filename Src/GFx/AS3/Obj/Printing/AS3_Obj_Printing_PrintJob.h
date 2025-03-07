//##protect##"disclaimer"
/**************************************************************************

Filename    :   AS3_Obj_Printing_PrintJob.h
Content     :   
Created     :   Jan, 2010
Authors     :   Sergey Sikorskiy

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/
//##protect##"disclaimer"

#ifndef INC_AS3_Obj_Printing_PrintJob_H
#define INC_AS3_Obj_Printing_PrintJob_H

#include "../Events/AS3_Obj_Events_EventDispatcher.h"
//##protect##"includes"
//##protect##"includes"


namespace Scaleform { namespace GFx { namespace AS3 
{
// Forward declaration.
namespace fl_printing
{
    extern const TypeInfo PrintJobTI;
    extern const ClassInfo PrintJobCI;
} // namespace fl_printing
namespace fl
{
    extern const TypeInfo StringTI;
    extern const ClassInfo StringCI;
    extern const TypeInfo int_TI;
    extern const ClassInfo int_CI;
    extern const TypeInfo BooleanTI;
    extern const ClassInfo BooleanCI;
} // namespace fl

namespace ClassTraits { namespace fl_printing
{
    class PrintJob;
}}

namespace InstanceTraits { namespace fl_printing
{
    class PrintJob;
}}

namespace Classes { namespace fl_printing
{
    class PrintJob;
}}

//##protect##"forward_declaration"
namespace Instances
{
    namespace fl_display
    {
        class Sprite;
    }
    namespace fl_geom
    {
        class Rectangle;
    }
    namespace fl_printing
    {
        class PrintJobOptions;
    }
}
//##protect##"forward_declaration"
    
namespace ClassTraits { namespace fl_printing
{
    class PrintJob : public Traits
    {
#ifdef GFX_AS3_VERBOSE
    private:
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::PrintJob"; }
#endif
    public:
        typedef Classes::fl_printing::PrintJob ClassType;

    public:
        PrintJob(VM& vm);
        static Pickable<Traits> MakeClassTraits(VM& vm);
//##protect##"ClassTraits$methods"
//##protect##"ClassTraits$methods"

    };
}}
//##protect##"methods"
//##protect##"methods"

}}} // namespace Scaleform { namespace GFx { namespace AS3

#endif

