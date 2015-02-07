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

#if ENABLE(MEDIA_STREAM)

#include "JSMediaStreamEvent.h"

#include "ExceptionCode.h"
#include "JSDOMBinding.h"
#include "JSMediaStream.h"
#include "MediaStream.h"
#include "MediaStreamEvent.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSMediaStreamEvent);

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSMediaStreamEventTableValues[] =
{
    { "stream", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsMediaStreamEventStream), (intptr_t)0 THUNK_GENERATOR(0) },
    { "constructor", DontEnum | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsMediaStreamEventConstructor), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSMediaStreamEventTable = { 5, 3, JSMediaStreamEventTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSMediaStreamEventConstructorTableValues[] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSMediaStreamEventConstructorTable = { 1, 0, JSMediaStreamEventConstructorTableValues, 0 };
class JSMediaStreamEventConstructor : public DOMConstructorObject {
private:
    JSMediaStreamEventConstructor(JSC::Structure*, JSDOMGlobalObject*);
    void finishCreation(JSC::ExecState*, JSDOMGlobalObject*);

public:
    typedef DOMConstructorObject Base;
    static JSMediaStreamEventConstructor* create(JSC::ExecState* exec, JSC::Structure* structure, JSDOMGlobalObject* globalObject)
    {
        JSMediaStreamEventConstructor* ptr = new (JSC::allocateCell<JSMediaStreamEventConstructor>(*exec->heap())) JSMediaStreamEventConstructor(structure, globalObject);
        ptr->finishCreation(exec, globalObject);
        return ptr;
    }

    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier&, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier&, JSC::PropertyDescriptor&);
    static const JSC::ClassInfo s_info;
    static JSC::Structure* createStructure(JSC::JSGlobalData& globalData, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(globalData, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), &s_info);
    }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | JSC::ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSMediaStreamEventConstructor::s_info = { "MediaStreamEventConstructor", &DOMConstructorObject::s_info, &JSMediaStreamEventConstructorTable, 0 };

JSMediaStreamEventConstructor::JSMediaStreamEventConstructor(Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(structure, globalObject)
{
}

void JSMediaStreamEventConstructor::finishCreation(ExecState* exec, JSDOMGlobalObject* globalObject)
{
    Base::finishCreation(exec->globalData());
    ASSERT(inherits(&s_info));
    putDirect(exec->globalData(), exec->propertyNames().prototype, JSMediaStreamEventPrototype::self(exec, globalObject), DontDelete | ReadOnly);
}

bool JSMediaStreamEventConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSMediaStreamEventConstructor, JSDOMWrapper>(exec, &JSMediaStreamEventConstructorTable, this, propertyName, slot);
}

bool JSMediaStreamEventConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSMediaStreamEventConstructor, JSDOMWrapper>(exec, &JSMediaStreamEventConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSMediaStreamEventPrototypeTableValues[] =
{
    { "initMediaStreamEvent", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsMediaStreamEventPrototypeFunctionInitMediaStreamEvent), (intptr_t)4 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSMediaStreamEventPrototypeTable = { 2, 1, JSMediaStreamEventPrototypeTableValues, 0 };
const ClassInfo JSMediaStreamEventPrototype::s_info = { "MediaStreamEventPrototype", &JSC::JSNonFinalObject::s_info, &JSMediaStreamEventPrototypeTable, 0 };

JSObject* JSMediaStreamEventPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSMediaStreamEvent>(exec, globalObject);
}

bool JSMediaStreamEventPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSMediaStreamEventPrototypeTable, this, propertyName, slot);
}

bool JSMediaStreamEventPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSMediaStreamEventPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSMediaStreamEvent::s_info = { "MediaStreamEvent", &JSEvent::s_info, &JSMediaStreamEventTable, 0 };

JSMediaStreamEvent::JSMediaStreamEvent(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<MediaStreamEvent> impl)
    : JSEvent(structure, globalObject, impl)
{
}

void JSMediaStreamEvent::finishCreation(JSGlobalData& globalData)
{
    Base::finishCreation(globalData);
    ASSERT(inherits(&s_info));
}

JSObject* JSMediaStreamEvent::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return JSMediaStreamEventPrototype::create(exec->globalData(), globalObject, JSMediaStreamEventPrototype::createStructure(exec->globalData(), globalObject, JSEventPrototype::self(exec, globalObject)));
}

bool JSMediaStreamEvent::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    return getStaticValueSlot<JSMediaStreamEvent, Base>(exec, &JSMediaStreamEventTable, this, propertyName, slot);
}

bool JSMediaStreamEvent::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    return getStaticValueDescriptor<JSMediaStreamEvent, Base>(exec, &JSMediaStreamEventTable, this, propertyName, descriptor);
}

JSValue jsMediaStreamEventStream(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSMediaStreamEvent* castedThis = static_cast<JSMediaStreamEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    MediaStreamEvent* imp = static_cast<MediaStreamEvent*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->stream()));
    return result;
}


JSValue jsMediaStreamEventConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSMediaStreamEvent* domObject = static_cast<JSMediaStreamEvent*>(asObject(slotBase));
    return JSMediaStreamEvent::getConstructor(exec, domObject->globalObject());
}

JSValue JSMediaStreamEvent::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSMediaStreamEventConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

EncodedJSValue JSC_HOST_CALL jsMediaStreamEventPrototypeFunctionInitMediaStreamEvent(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSMediaStreamEvent::s_info))
        return throwVMTypeError(exec);
    JSMediaStreamEvent* castedThis = static_cast<JSMediaStreamEvent*>(asObject(thisValue));
    ASSERT_GC_OBJECT_INHERITS(castedThis, &JSMediaStreamEvent::s_info);
    MediaStreamEvent* imp = static_cast<MediaStreamEvent*>(castedThis->impl());
    const String& typeArg(ustringToString(exec->argument(0).toString(exec)));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    bool canBubbleArg(exec->argument(1).toBoolean(exec));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    bool cancelableArg(exec->argument(2).toBoolean(exec));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    MediaStream* streamArg(toMediaStream(exec->argument(3)));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());

    imp->initMediaStreamEvent(typeArg, canBubbleArg, cancelableArg, streamArg);
    return JSValue::encode(jsUndefined());
}


}

#endif // ENABLE(MEDIA_STREAM)
