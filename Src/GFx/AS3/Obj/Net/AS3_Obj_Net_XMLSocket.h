//##protect##"disclaimer"
/**************************************************************************

Filename    :   AS3_Obj_Net_XMLSocket.h
Content     :   
Created     :   Jan, 2010
Authors     :   Sergey Sikorskiy

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/
//##protect##"disclaimer"

#ifndef INC_AS3_Obj_Net_XMLSocket_H
#define INC_AS3_Obj_Net_XMLSocket_H

#include "../Events/AS3_Obj_Events_EventDispatcher.h"
//##protect##"includes"
//##protect##"includes"


namespace Scaleform { namespace GFx { namespace AS3 
{
// Forward declaration.
namespace fl_net
{
    extern const TypeInfo XMLSocketTI;
    extern const ClassInfo XMLSocketCI;
} // namespace fl_net
namespace fl
{
    extern const TypeInfo BooleanTI;
    extern const ClassInfo BooleanCI;
} // namespace fl

namespace ClassTraits { namespace fl_net
{
    class XMLSocket;
}}

namespace InstanceTraits { namespace fl_net
{
    class XMLSocket;
}}

namespace Classes { namespace fl_net
{
    class XMLSocket;
}}

//##protect##"forward_declaration"
//##protect##"forward_declaration"
    
namespace ClassTraits { namespace fl_net
{
    class XMLSocket : public Traits
    {
#ifdef GFX_AS3_VERBOSE
    private:
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::XMLSocket"; }
#endif
    public:
        typedef Classes::fl_net::XMLSocket ClassType;

    public:
        XMLSocket(VM& vm);
        static Pickable<Traits> MakeClassTraits(VM& vm);
//##protect##"ClassTraits$methods"
//##protect##"ClassTraits$methods"

    };
}}
//##protect##"methods"
//##protect##"methods"

}}} // namespace Scaleform { namespace GFx { namespace AS3

#endif

