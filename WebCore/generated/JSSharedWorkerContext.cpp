/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"

#if ENABLE(SHARED_WORKERS)

#include "JSSharedWorkerContext.h"

#include "EventListener.h"
#include "JSEventListener.h"
#include "KURL.h"
#include "SharedWorkerContext.h"
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSSharedWorkerContext);

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSharedWorkerContextTableValues[] =
{
    { "name", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSharedWorkerContextName), (intptr_t)0 THUNK_GENERATOR(0) },
    { "onconnect", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSharedWorkerContextOnconnect), (intptr_t)setJSSharedWorkerContextOnconnect THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSharedWorkerContextTable = { 4, 3, JSSharedWorkerContextTableValues, 0 };
/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSharedWorkerContextPrototypeTableValues[] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSharedWorkerContextPrototypeTable = { 1, 0, JSSharedWorkerContextPrototypeTableValues, 0 };
static const HashTable* getJSSharedWorkerContextPrototypeTable(ExecState* exec)
{
    return getHashTableForGlobalData(exec->globalData(), &JSSharedWorkerContextPrototypeTable);
}

const ClassInfo JSSharedWorkerContextPrototype::s_info = { "SharedWorkerContextPrototype", &JSC::JSNonFinalObject::s_info, 0, getJSSharedWorkerContextPrototypeTable };

static const HashTable* getJSSharedWorkerContextTable(ExecState* exec)
{
    return getHashTableForGlobalData(exec->globalData(), &JSSharedWorkerContextTable);
}

const ClassInfo JSSharedWorkerContext::s_info = { "SharedWorkerContext", &JSWorkerContext::s_info, 0, getJSSharedWorkerContextTable };

JSSharedWorkerContext::JSSharedWorkerContext(JSGlobalData& globalData, Structure* structure, PassRefPtr<SharedWorkerContext> impl)
    : JSWorkerContext(globalData, structure, impl)
{
}

bool JSSharedWorkerContext::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    return getStaticValueSlot<JSSharedWorkerContext, Base>(exec, getJSSharedWorkerContextTable(exec), this, propertyName, slot);
}

bool JSSharedWorkerContext::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    return getStaticValueDescriptor<JSSharedWorkerContext, Base>(exec, getJSSharedWorkerContextTable(exec), this, propertyName, descriptor);
}

JSValue jsSharedWorkerContextName(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSharedWorkerContext* castedThis = static_cast<JSSharedWorkerContext*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SharedWorkerContext* imp = static_cast<SharedWorkerContext*>(castedThis->impl());
    JSValue result = jsString(exec, imp->name());
    return result;
}


JSValue jsSharedWorkerContextOnconnect(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSharedWorkerContext* castedThis = static_cast<JSSharedWorkerContext*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SharedWorkerContext* imp = static_cast<SharedWorkerContext*>(castedThis->impl());
    if (EventListener* listener = imp->onconnect()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp))
                return jsFunction;
        }
    }
    return jsNull();
}


void JSSharedWorkerContext::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    lookupPut<JSSharedWorkerContext, Base>(exec, propertyName, value, getJSSharedWorkerContextTable(exec), this, slot);
}

void setJSSharedWorkerContextOnconnect(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    JSSharedWorkerContext* castedThis = static_cast<JSSharedWorkerContext*>(thisObject);
    SharedWorkerContext* imp = static_cast<SharedWorkerContext*>(castedThis->impl());
    imp->setOnconnect(createJSAttributeEventListener(exec, value, thisObject));
}


SharedWorkerContext* toSharedWorkerContext(JSC::JSValue value)
{
    return value.inherits(&JSSharedWorkerContext::s_info) ? static_cast<JSSharedWorkerContext*>(asObject(value))->impl() : 0;
}

}

#endif // ENABLE(SHARED_WORKERS)
