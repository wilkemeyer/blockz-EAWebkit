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

#if ENABLE(DOM_STORAGE)

#include "JSStorage.h"

#include "ExceptionCode.h"
#include "JSDOMBinding.h"
#include "JSStorageCustom.h"
#include "KURL.h"
#include "Storage.h"
#include "wtf/text/AtomicString.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSStorage);

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSStorageTableValues[] =
{
    { "length", DontDelete | DontEnum | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsStorageLength), (intptr_t)0 THUNK_GENERATOR(0) },
    { "constructor", DontEnum | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsStorageConstructor), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSStorageTable = { 5, 3, JSStorageTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSStorageConstructorTableValues[] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSStorageConstructorTable = { 1, 0, JSStorageConstructorTableValues, 0 };
class JSStorageConstructor : public DOMConstructorObject {
private:
    JSStorageConstructor(JSC::Structure*, JSDOMGlobalObject*);
    void finishCreation(JSC::ExecState*, JSDOMGlobalObject*);

public:
    typedef DOMConstructorObject Base;
    static JSStorageConstructor* create(JSC::ExecState* exec, JSC::Structure* structure, JSDOMGlobalObject* globalObject)
    {
        JSStorageConstructor* ptr = new (JSC::allocateCell<JSStorageConstructor>(*exec->heap())) JSStorageConstructor(structure, globalObject);
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

const ClassInfo JSStorageConstructor::s_info = { "StorageConstructor", &DOMConstructorObject::s_info, &JSStorageConstructorTable, 0 };

JSStorageConstructor::JSStorageConstructor(Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(structure, globalObject)
{
}

void JSStorageConstructor::finishCreation(ExecState* exec, JSDOMGlobalObject* globalObject)
{
    Base::finishCreation(exec->globalData());
    ASSERT(inherits(&s_info));
    putDirect(exec->globalData(), exec->propertyNames().prototype, JSStoragePrototype::self(exec, globalObject), DontDelete | ReadOnly);
}

bool JSStorageConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSStorageConstructor, JSDOMWrapper>(exec, &JSStorageConstructorTable, this, propertyName, slot);
}

bool JSStorageConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSStorageConstructor, JSDOMWrapper>(exec, &JSStorageConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSStoragePrototypeTableValues[] =
{
    { "key", DontDelete | DontEnum | Function, (intptr_t)static_cast<NativeFunction>(jsStoragePrototypeFunctionKey), (intptr_t)1 THUNK_GENERATOR(0) },
    { "getItem", DontDelete | DontEnum | Function, (intptr_t)static_cast<NativeFunction>(jsStoragePrototypeFunctionGetItem), (intptr_t)1 THUNK_GENERATOR(0) },
    { "setItem", DontDelete | DontEnum | Function, (intptr_t)static_cast<NativeFunction>(jsStoragePrototypeFunctionSetItem), (intptr_t)2 THUNK_GENERATOR(0) },
    { "removeItem", DontDelete | DontEnum | Function, (intptr_t)static_cast<NativeFunction>(jsStoragePrototypeFunctionRemoveItem), (intptr_t)1 THUNK_GENERATOR(0) },
    { "clear", DontDelete | DontEnum | Function, (intptr_t)static_cast<NativeFunction>(jsStoragePrototypeFunctionClear), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSStoragePrototypeTable = { 17, 15, JSStoragePrototypeTableValues, 0 };
const ClassInfo JSStoragePrototype::s_info = { "StoragePrototype", &JSC::JSNonFinalObject::s_info, &JSStoragePrototypeTable, 0 };

JSObject* JSStoragePrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSStorage>(exec, globalObject);
}

bool JSStoragePrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSStoragePrototypeTable, this, propertyName, slot);
}

bool JSStoragePrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSStoragePrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSStorage::s_info = { "Storage", &JSDOMWrapper::s_info, &JSStorageTable, 0 };

JSStorage::JSStorage(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<Storage> impl)
    : JSDOMWrapper(structure, globalObject)
    , m_impl(impl)
{
}

void JSStorage::finishCreation(JSGlobalData& globalData)
{
    Base::finishCreation(globalData);
    ASSERT(inherits(&s_info));
}

JSObject* JSStorage::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return JSStoragePrototype::create(exec->globalData(), globalObject, JSStoragePrototype::createStructure(globalObject->globalData(), globalObject, globalObject->objectPrototype()));
}

bool JSStorage::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    const HashEntry* entry = JSStorageTable.entry(exec, propertyName);
    if (entry) {
        slot.setCustom(this, entry->propertyGetter());
        return true;
    }
    if (canGetItemsForName(exec, static_cast<Storage*>(impl()), propertyName)) {
        slot.setCustom(this, nameGetter);
        return true;
    }
    return getStaticValueSlot<JSStorage, Base>(exec, &JSStorageTable, this, propertyName, slot);
}

bool JSStorage::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    const HashEntry* entry = JSStorageTable.entry(exec, propertyName);
    if (entry) {
        PropertySlot slot;
        slot.setCustom(this, entry->propertyGetter());
        descriptor.setDescriptor(slot.getValue(exec, propertyName), entry->attributes());
        return true;
    }
    if (canGetItemsForName(exec, static_cast<Storage*>(impl()), propertyName)) {
        PropertySlot slot;
        slot.setCustom(this, nameGetter);
        descriptor.setDescriptor(slot.getValue(exec, propertyName), ReadOnly | DontDelete | DontEnum);
        return true;
    }
    return getStaticValueDescriptor<JSStorage, Base>(exec, &JSStorageTable, this, propertyName, descriptor);
}

JSValue jsStorageLength(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSStorage* castedThis = static_cast<JSStorage*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    Storage* imp = static_cast<Storage*>(castedThis->impl());
    JSValue result = jsNumber(imp->length());
    return result;
}


JSValue jsStorageConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSStorage* domObject = static_cast<JSStorage*>(asObject(slotBase));
    return JSStorage::getConstructor(exec, domObject->globalObject());
}

void JSStorage::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    if (putDelegate(exec, propertyName, value, slot))
        return;
    Base::put(exec, propertyName, value, slot);
}

JSValue JSStorage::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSStorageConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

EncodedJSValue JSC_HOST_CALL jsStoragePrototypeFunctionKey(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSStorage::s_info))
        return throwVMTypeError(exec);
    JSStorage* castedThis = static_cast<JSStorage*>(asObject(thisValue));
    ASSERT_GC_OBJECT_INHERITS(castedThis, &JSStorage::s_info);
    Storage* imp = static_cast<Storage*>(castedThis->impl());
    unsigned index(exec->argument(0).toUInt32(exec));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());


    JSC::JSValue result = jsStringOrNull(exec, imp->key(index));
    return JSValue::encode(result);
}

EncodedJSValue JSC_HOST_CALL jsStoragePrototypeFunctionGetItem(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSStorage::s_info))
        return throwVMTypeError(exec);
    JSStorage* castedThis = static_cast<JSStorage*>(asObject(thisValue));
    ASSERT_GC_OBJECT_INHERITS(castedThis, &JSStorage::s_info);
    Storage* imp = static_cast<Storage*>(castedThis->impl());
    const String& key(ustringToString(exec->argument(0).toString(exec)));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());


    JSC::JSValue result = jsStringOrNull(exec, imp->getItem(key));
    return JSValue::encode(result);
}

EncodedJSValue JSC_HOST_CALL jsStoragePrototypeFunctionSetItem(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSStorage::s_info))
        return throwVMTypeError(exec);
    JSStorage* castedThis = static_cast<JSStorage*>(asObject(thisValue));
    ASSERT_GC_OBJECT_INHERITS(castedThis, &JSStorage::s_info);
    Storage* imp = static_cast<Storage*>(castedThis->impl());
    ExceptionCode ec = 0;
    const String& key(ustringToString(exec->argument(0).toString(exec)));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    const String& data(ustringToString(exec->argument(1).toString(exec)));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());

    imp->setItem(key, data, ec);
    setDOMException(exec, ec);
    return JSValue::encode(jsUndefined());
}

EncodedJSValue JSC_HOST_CALL jsStoragePrototypeFunctionRemoveItem(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSStorage::s_info))
        return throwVMTypeError(exec);
    JSStorage* castedThis = static_cast<JSStorage*>(asObject(thisValue));
    ASSERT_GC_OBJECT_INHERITS(castedThis, &JSStorage::s_info);
    Storage* imp = static_cast<Storage*>(castedThis->impl());
    const String& key(ustringToString(exec->argument(0).toString(exec)));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());

    imp->removeItem(key);
    return JSValue::encode(jsUndefined());
}

EncodedJSValue JSC_HOST_CALL jsStoragePrototypeFunctionClear(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSStorage::s_info))
        return throwVMTypeError(exec);
    JSStorage* castedThis = static_cast<JSStorage*>(asObject(thisValue));
    ASSERT_GC_OBJECT_INHERITS(castedThis, &JSStorage::s_info);
    Storage* imp = static_cast<Storage*>(castedThis->impl());

    imp->clear();
    return JSValue::encode(jsUndefined());
}

static inline bool isObservable(JSStorage* jsStorage)
{
    if (jsStorage->hasCustomProperties())
        return true;
    return false;
}

bool JSStorageOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, SlotVisitor& visitor)
{
    JSStorage* jsStorage = static_cast<JSStorage*>(handle.get().asCell());
    if (!isObservable(jsStorage))
        return false;
    Frame* root = jsStorage->impl()->frame();
    if (!root)
        return false;
    return visitor.containsOpaqueRoot(root);
}

void JSStorageOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    JSStorage* jsStorage = static_cast<JSStorage*>(handle.get().asCell());
    DOMWrapperWorld* world = static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, jsStorage->impl(), jsStorage);
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, Storage* impl)
{
    return wrap<JSStorage>(exec, globalObject, impl);
}

Storage* toStorage(JSC::JSValue value)
{
    return value.inherits(&JSStorage::s_info) ? static_cast<JSStorage*>(asObject(value))->impl() : 0;
}

}

#endif // ENABLE(DOM_STORAGE)
