//##protect##"disclaimer"
/**************************************************************************

Filename    :   AS3_Obj_Net_LocalConnection.cpp
Content     :   
Created     :   Jan, 2010
Authors     :   Sergey Sikorskiy

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/
//##protect##"disclaimer"

#include "AS3_Obj_Net_LocalConnection.h"
#include "../../AS3_VM.h"
#include "../../AS3_Marshalling.h"
//##protect##"includes"
//##protect##"includes"


namespace Scaleform { namespace GFx { namespace AS3 
{

//##protect##"methods"
//##protect##"methods"

// Values of default arguments.
namespace Impl
{

} // namespace Impl

namespace InstanceTraits { namespace fl_net
{
    const ThunkInfo LocalConnection_ti[8] = {
        {ThunkInfo::EmptyFunc, &AS3::fl::ObjectTI, "client", NULL, Abc::NS_Public, CT_Get, 0, 0},
        {ThunkInfo::EmptyFunc, NULL, "client", NULL, Abc::NS_Public, CT_Set, 1, 1},
        {ThunkInfo::EmptyFunc, &AS3::fl::StringTI, "domain", NULL, Abc::NS_Public, CT_Get, 0, 0},
        {ThunkInfo::EmptyFunc, NULL, "allowDomain", NULL, Abc::NS_Public, CT_Method, 0, SF_AS3_VARARGNUM},
        {ThunkInfo::EmptyFunc, NULL, "allowInsecureDomain", NULL, Abc::NS_Public, CT_Method, 0, SF_AS3_VARARGNUM},
        {ThunkInfo::EmptyFunc, NULL, "close", NULL, Abc::NS_Public, CT_Method, 0, 0},
        {ThunkInfo::EmptyFunc, NULL, "connect", NULL, Abc::NS_Public, CT_Method, 1, 1},
        {ThunkInfo::EmptyFunc, NULL, "send", NULL, Abc::NS_Public, CT_Method, 0, SF_AS3_VARARGNUM},
    };

}} // namespace InstanceTraits


namespace ClassTraits { namespace fl_net
{
    LocalConnection::LocalConnection(VM& vm)
    : Traits(vm, AS3::fl_net::LocalConnectionCI)
    {
//##protect##"ClassTraits::LocalConnection::LocalConnection()"
//##protect##"ClassTraits::LocalConnection::LocalConnection()"
        MemoryHeap* mh = vm.GetMemoryHeap();

        Pickable<InstanceTraits::Traits> it(SF_HEAP_NEW_ID(mh, StatMV_VM_ITraits_Mem) InstanceTraits::fl_events::EventDispatcher(vm, AS3::fl_net::LocalConnectionCI));
        SetInstanceTraits(it);

        // There is no problem with Pickable not assigned to anything here. Class constructor takes care of this.
        Pickable<Class> cl(SF_HEAP_NEW_ID(mh, StatMV_VM_Class_Mem) Class(*this));

    }

    Pickable<Traits> LocalConnection::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(SF_HEAP_NEW_ID(vm.GetMemoryHeap(), StatMV_VM_CTraits_Mem) LocalConnection(vm));
    }
//##protect##"ClassTraits$methods"
//##protect##"ClassTraits$methods"

}} // namespace ClassTraits

namespace fl_net
{
    const TypeInfo LocalConnectionTI = {
        TypeInfo::CompileTime | TypeInfo::NotImplemented,
        "LocalConnection", "flash.net", &fl_events::EventDispatcherTI,
        TypeInfo::None
    };

    const ClassInfo LocalConnectionCI = {
        &LocalConnectionTI,
        ClassTraits::fl_net::LocalConnection::MakeClassTraits,
        0,
        0,
        8,
        0,
        NULL,
        NULL,
        InstanceTraits::fl_net::LocalConnection_ti,
        NULL,
    };
}; // namespace fl_net


}}} // namespace Scaleform { namespace GFx { namespace AS3

