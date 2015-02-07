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

#if ENABLE(FILE_SYSTEM)

#include "JSFileWriter.h"

#include "EventListener.h"
#include "ExceptionCode.h"
#include "FileError.h"
#include "FileWriter.h"
#include "JSBlob.h"
#include "JSDOMBinding.h"
#include "JSEventListener.h"
#include "JSFileError.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSFileWriter);

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSFileWriterTableValues[] =
{
    { "readyState", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsFileWriterReadyState), (intptr_t)0 THUNK_GENERATOR(0) },
    { "error", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsFileWriterError), (intptr_t)0 THUNK_GENERATOR(0) },
    { "position", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsFileWriterPosition), (intptr_t)0 THUNK_GENERATOR(0) },
    { "length", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsFileWriterLength), (intptr_t)0 THUNK_GENERATOR(0) },
    { "onwritestart", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsFileWriterOnwritestart), (intptr_t)setJSFileWriterOnwritestart THUNK_GENERATOR(0) },
    { "onprogress", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsFileWriterOnprogress), (intptr_t)setJSFileWriterOnprogress THUNK_GENERATOR(0) },
    { "onwrite", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsFileWriterOnwrite), (intptr_t)setJSFileWriterOnwrite THUNK_GENERATOR(0) },
    { "onabort", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsFileWriterOnabort), (intptr_t)setJSFileWriterOnabort THUNK_GENERATOR(0) },
    { "onerror", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsFileWriterOnerror), (intptr_t)setJSFileWriterOnerror THUNK_GENERATOR(0) },
    { "onwriteend", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsFileWriterOnwriteend), (intptr_t)setJSFileWriterOnwriteend THUNK_GENERATOR(0) },
    { "constructor", DontEnum | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsFileWriterConstructor), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSFileWriterTable = { 34, 31, JSFileWriterTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSFileWriterConstructorTableValues[] =
{
    { "INIT", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsFileWriterINIT), (intptr_t)0 THUNK_GENERATOR(0) },
    { "WRITING", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsFileWriterWRITING), (intptr_t)0 THUNK_GENERATOR(0) },
    { "DONE", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsFileWriterDONE), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSFileWriterConstructorTable = { 8, 7, JSFileWriterConstructorTableValues, 0 };

COMPILE_ASSERT(0 == FileWriter::INIT, FileWriterEnumINITIsWrongUseDontCheckEnums);
COMPILE_ASSERT(1 == FileWriter::WRITING, FileWriterEnumWRITINGIsWrongUseDontCheckEnums);
COMPILE_ASSERT(2 == FileWriter::DONE, FileWriterEnumDONEIsWrongUseDontCheckEnums);

class JSFileWriterConstructor : public DOMConstructorObject {
private:
    JSFileWriterConstructor(JSC::Structure*, JSDOMGlobalObject*);
    void finishCreation(JSC::ExecState*, JSDOMGlobalObject*);

public:
    typedef DOMConstructorObject Base;
    static JSFileWriterConstructor* create(JSC::ExecState* exec, JSC::Structure* structure, JSDOMGlobalObject* globalObject)
    {
        JSFileWriterConstructor* ptr = new (JSC::allocateCell<JSFileWriterConstructor>(*exec->heap())) JSFileWriterConstructor(structure, globalObject);
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

const ClassInfo JSFileWriterConstructor::s_info = { "FileWriterConstructor", &DOMConstructorObject::s_info, &JSFileWriterConstructorTable, 0 };

JSFileWriterConstructor::JSFileWriterConstructor(Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(structure, globalObject)
{
}

void JSFileWriterConstructor::finishCreation(ExecState* exec, JSDOMGlobalObject* globalObject)
{
    Base::finishCreation(exec->globalData());
    ASSERT(inherits(&s_info));
    putDirect(exec->globalData(), exec->propertyNames().prototype, JSFileWriterPrototype::self(exec, globalObject), DontDelete | ReadOnly);
}

bool JSFileWriterConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSFileWriterConstructor, JSDOMWrapper>(exec, &JSFileWriterConstructorTable, this, propertyName, slot);
}

bool JSFileWriterConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSFileWriterConstructor, JSDOMWrapper>(exec, &JSFileWriterConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSFileWriterPrototypeTableValues[] =
{
    { "INIT", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsFileWriterINIT), (intptr_t)0 THUNK_GENERATOR(0) },
    { "WRITING", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsFileWriterWRITING), (intptr_t)0 THUNK_GENERATOR(0) },
    { "DONE", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsFileWriterDONE), (intptr_t)0 THUNK_GENERATOR(0) },
    { "write", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsFileWriterPrototypeFunctionWrite), (intptr_t)1 THUNK_GENERATOR(0) },
    { "seek", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsFileWriterPrototypeFunctionSeek), (intptr_t)1 THUNK_GENERATOR(0) },
    { "truncate", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsFileWriterPrototypeFunctionTruncate), (intptr_t)1 THUNK_GENERATOR(0) },
    { "abort", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsFileWriterPrototypeFunctionAbort), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSFileWriterPrototypeTable = { 18, 15, JSFileWriterPrototypeTableValues, 0 };
static const HashTable* getJSFileWriterPrototypeTable(ExecState* exec)
{
    return getHashTableForGlobalData(exec->globalData(), &JSFileWriterPrototypeTable);
}

const ClassInfo JSFileWriterPrototype::s_info = { "FileWriterPrototype", &JSC::JSNonFinalObject::s_info, 0, getJSFileWriterPrototypeTable };

JSObject* JSFileWriterPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSFileWriter>(exec, globalObject);
}

bool JSFileWriterPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticPropertySlot<JSFileWriterPrototype, JSObject>(exec, getJSFileWriterPrototypeTable(exec), this, propertyName, slot);
}

bool JSFileWriterPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticPropertyDescriptor<JSFileWriterPrototype, JSObject>(exec, getJSFileWriterPrototypeTable(exec), this, propertyName, descriptor);
}

static const HashTable* getJSFileWriterTable(ExecState* exec)
{
    return getHashTableForGlobalData(exec->globalData(), &JSFileWriterTable);
}

const ClassInfo JSFileWriter::s_info = { "FileWriter", &JSDOMWrapper::s_info, 0, getJSFileWriterTable };

JSFileWriter::JSFileWriter(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<FileWriter> impl)
    : JSDOMWrapper(structure, globalObject)
    , m_impl(impl)
{
}

void JSFileWriter::finishCreation(JSGlobalData& globalData)
{
    Base::finishCreation(globalData);
    ASSERT(inherits(&s_info));
}

JSObject* JSFileWriter::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return JSFileWriterPrototype::create(exec->globalData(), globalObject, JSFileWriterPrototype::createStructure(globalObject->globalData(), globalObject, globalObject->objectPrototype()));
}

bool JSFileWriter::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    return getStaticValueSlot<JSFileWriter, Base>(exec, getJSFileWriterTable(exec), this, propertyName, slot);
}

bool JSFileWriter::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    return getStaticValueDescriptor<JSFileWriter, Base>(exec, getJSFileWriterTable(exec), this, propertyName, descriptor);
}

JSValue jsFileWriterReadyState(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSFileWriter* castedThis = static_cast<JSFileWriter*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    FileWriter* imp = static_cast<FileWriter*>(castedThis->impl());
    JSValue result = jsNumber(imp->readyState());
    return result;
}


JSValue jsFileWriterError(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSFileWriter* castedThis = static_cast<JSFileWriter*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    FileWriter* imp = static_cast<FileWriter*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->error()));
    return result;
}


JSValue jsFileWriterPosition(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSFileWriter* castedThis = static_cast<JSFileWriter*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    FileWriter* imp = static_cast<FileWriter*>(castedThis->impl());
    JSValue result = jsNumber(imp->position());
    return result;
}


JSValue jsFileWriterLength(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSFileWriter* castedThis = static_cast<JSFileWriter*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    FileWriter* imp = static_cast<FileWriter*>(castedThis->impl());
    JSValue result = jsNumber(imp->length());
    return result;
}


JSValue jsFileWriterOnwritestart(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSFileWriter* castedThis = static_cast<JSFileWriter*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    FileWriter* imp = static_cast<FileWriter*>(castedThis->impl());
    if (EventListener* listener = imp->onwritestart()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}


JSValue jsFileWriterOnprogress(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSFileWriter* castedThis = static_cast<JSFileWriter*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    FileWriter* imp = static_cast<FileWriter*>(castedThis->impl());
    if (EventListener* listener = imp->onprogress()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}


JSValue jsFileWriterOnwrite(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSFileWriter* castedThis = static_cast<JSFileWriter*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    FileWriter* imp = static_cast<FileWriter*>(castedThis->impl());
    if (EventListener* listener = imp->onwrite()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}


JSValue jsFileWriterOnabort(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSFileWriter* castedThis = static_cast<JSFileWriter*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    FileWriter* imp = static_cast<FileWriter*>(castedThis->impl());
    if (EventListener* listener = imp->onabort()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}


JSValue jsFileWriterOnerror(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSFileWriter* castedThis = static_cast<JSFileWriter*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    FileWriter* imp = static_cast<FileWriter*>(castedThis->impl());
    if (EventListener* listener = imp->onerror()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}


JSValue jsFileWriterOnwriteend(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSFileWriter* castedThis = static_cast<JSFileWriter*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    FileWriter* imp = static_cast<FileWriter*>(castedThis->impl());
    if (EventListener* listener = imp->onwriteend()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}


JSValue jsFileWriterConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSFileWriter* domObject = static_cast<JSFileWriter*>(asObject(slotBase));
    return JSFileWriter::getConstructor(exec, domObject->globalObject());
}

void JSFileWriter::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    lookupPut<JSFileWriter, Base>(exec, propertyName, value, getJSFileWriterTable(exec), this, slot);
}

void setJSFileWriterOnwritestart(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    JSFileWriter* castedThis = static_cast<JSFileWriter*>(thisObject);
    FileWriter* imp = static_cast<FileWriter*>(castedThis->impl());
    imp->setOnwritestart(createJSAttributeEventListener(exec, value, thisObject));
}


void setJSFileWriterOnprogress(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    JSFileWriter* castedThis = static_cast<JSFileWriter*>(thisObject);
    FileWriter* imp = static_cast<FileWriter*>(castedThis->impl());
    imp->setOnprogress(createJSAttributeEventListener(exec, value, thisObject));
}


void setJSFileWriterOnwrite(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    JSFileWriter* castedThis = static_cast<JSFileWriter*>(thisObject);
    FileWriter* imp = static_cast<FileWriter*>(castedThis->impl());
    imp->setOnwrite(createJSAttributeEventListener(exec, value, thisObject));
}


void setJSFileWriterOnabort(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    JSFileWriter* castedThis = static_cast<JSFileWriter*>(thisObject);
    FileWriter* imp = static_cast<FileWriter*>(castedThis->impl());
    imp->setOnabort(createJSAttributeEventListener(exec, value, thisObject));
}


void setJSFileWriterOnerror(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    JSFileWriter* castedThis = static_cast<JSFileWriter*>(thisObject);
    FileWriter* imp = static_cast<FileWriter*>(castedThis->impl());
    imp->setOnerror(createJSAttributeEventListener(exec, value, thisObject));
}


void setJSFileWriterOnwriteend(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    JSFileWriter* castedThis = static_cast<JSFileWriter*>(thisObject);
    FileWriter* imp = static_cast<FileWriter*>(castedThis->impl());
    imp->setOnwriteend(createJSAttributeEventListener(exec, value, thisObject));
}


JSValue JSFileWriter::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSFileWriterConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

EncodedJSValue JSC_HOST_CALL jsFileWriterPrototypeFunctionWrite(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSFileWriter::s_info))
        return throwVMTypeError(exec);
    JSFileWriter* castedThis = static_cast<JSFileWriter*>(asObject(thisValue));
    ASSERT_GC_OBJECT_INHERITS(castedThis, &JSFileWriter::s_info);
    FileWriter* imp = static_cast<FileWriter*>(castedThis->impl());
    if (exec->argumentCount() < 1)
        return throwVMError(exec, createTypeError(exec, "Not enough arguments"));
    ExceptionCode ec = 0;
    Blob* data(toBlob(exec->argument(0)));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());

    imp->write(data, ec);
    setDOMException(exec, ec);
    return JSValue::encode(jsUndefined());
}

EncodedJSValue JSC_HOST_CALL jsFileWriterPrototypeFunctionSeek(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSFileWriter::s_info))
        return throwVMTypeError(exec);
    JSFileWriter* castedThis = static_cast<JSFileWriter*>(asObject(thisValue));
    ASSERT_GC_OBJECT_INHERITS(castedThis, &JSFileWriter::s_info);
    FileWriter* imp = static_cast<FileWriter*>(castedThis->impl());
    if (exec->argumentCount() < 1)
        return throwVMError(exec, createTypeError(exec, "Not enough arguments"));
    ExceptionCode ec = 0;
    long long position(static_cast<long long>(exec->argument(0).toInteger(exec)));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());

    imp->seek(position, ec);
    setDOMException(exec, ec);
    return JSValue::encode(jsUndefined());
}

EncodedJSValue JSC_HOST_CALL jsFileWriterPrototypeFunctionTruncate(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSFileWriter::s_info))
        return throwVMTypeError(exec);
    JSFileWriter* castedThis = static_cast<JSFileWriter*>(asObject(thisValue));
    ASSERT_GC_OBJECT_INHERITS(castedThis, &JSFileWriter::s_info);
    FileWriter* imp = static_cast<FileWriter*>(castedThis->impl());
    if (exec->argumentCount() < 1)
        return throwVMError(exec, createTypeError(exec, "Not enough arguments"));
    ExceptionCode ec = 0;
    long long size(static_cast<long long>(exec->argument(0).toInteger(exec)));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());

    imp->truncate(size, ec);
    setDOMException(exec, ec);
    return JSValue::encode(jsUndefined());
}

EncodedJSValue JSC_HOST_CALL jsFileWriterPrototypeFunctionAbort(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSFileWriter::s_info))
        return throwVMTypeError(exec);
    JSFileWriter* castedThis = static_cast<JSFileWriter*>(asObject(thisValue));
    ASSERT_GC_OBJECT_INHERITS(castedThis, &JSFileWriter::s_info);
    FileWriter* imp = static_cast<FileWriter*>(castedThis->impl());
    ExceptionCode ec = 0;

    imp->abort(ec);
    setDOMException(exec, ec);
    return JSValue::encode(jsUndefined());
}

void JSFileWriter::visitChildren(SlotVisitor& visitor)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    COMPILE_ASSERT(StructureFlags & OverridesVisitChildren, OverridesVisitChildrenWithoutSettingFlag);
    ASSERT(structure()->typeInfo().overridesVisitChildren());
    Base::visitChildren(visitor);
    impl()->visitJSEventListeners(visitor);
}

// Constant getters

JSValue jsFileWriterINIT(ExecState* exec, JSValue, const Identifier&)
{
    UNUSED_PARAM(exec);
    return jsNumber(static_cast<int>(0));
}

JSValue jsFileWriterWRITING(ExecState* exec, JSValue, const Identifier&)
{
    UNUSED_PARAM(exec);
    return jsNumber(static_cast<int>(1));
}

JSValue jsFileWriterDONE(ExecState* exec, JSValue, const Identifier&)
{
    UNUSED_PARAM(exec);
    return jsNumber(static_cast<int>(2));
}

static inline bool isObservable(JSFileWriter* jsFileWriter)
{
    if (jsFileWriter->hasCustomProperties())
        return true;
    if (jsFileWriter->impl()->hasEventListeners())
        return true;
    return false;
}

bool JSFileWriterOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, SlotVisitor& visitor)
{
    JSFileWriter* jsFileWriter = static_cast<JSFileWriter*>(handle.get().asCell());
    if (jsFileWriter->impl()->hasPendingActivity())
        return true;
    if (!isObservable(jsFileWriter))
        return false;
    UNUSED_PARAM(visitor);
    return false;
}

void JSFileWriterOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    JSFileWriter* jsFileWriter = static_cast<JSFileWriter*>(handle.get().asCell());
    DOMWrapperWorld* world = static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, jsFileWriter->impl(), jsFileWriter);
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, FileWriter* impl)
{
    return wrap<JSFileWriter>(exec, globalObject, impl);
}

FileWriter* toFileWriter(JSC::JSValue value)
{
    return value.inherits(&JSFileWriter::s_info) ? static_cast<JSFileWriter*>(asObject(value))->impl() : 0;
}

}

#endif // ENABLE(FILE_SYSTEM)