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

#if ENABLE(INPUT_SPEECH)

#include "JSSpeechInputResult.h"

#include "KURL.h"
#include "SpeechInputResult.h"
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSSpeechInputResult);

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSpeechInputResultTableValues[] =
{
    { "utterance", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSpeechInputResultUtterance), (intptr_t)0 THUNK_GENERATOR(0) },
    { "confidence", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSpeechInputResultConfidence), (intptr_t)0 THUNK_GENERATOR(0) },
    { "constructor", DontEnum | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSpeechInputResultConstructor), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSpeechInputResultTable = { 8, 7, JSSpeechInputResultTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSpeechInputResultConstructorTableValues[] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSpeechInputResultConstructorTable = { 1, 0, JSSpeechInputResultConstructorTableValues, 0 };
class JSSpeechInputResultConstructor : public DOMConstructorObject {
private:
    JSSpeechInputResultConstructor(JSC::Structure*, JSDOMGlobalObject*);
    void finishCreation(JSC::ExecState*, JSDOMGlobalObject*);

public:
    typedef DOMConstructorObject Base;
    static JSSpeechInputResultConstructor* create(JSC::ExecState* exec, JSC::Structure* structure, JSDOMGlobalObject* globalObject)
    {
        JSSpeechInputResultConstructor* ptr = new (JSC::allocateCell<JSSpeechInputResultConstructor>(*exec->heap())) JSSpeechInputResultConstructor(structure, globalObject);
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

const ClassInfo JSSpeechInputResultConstructor::s_info = { "SpeechInputResultConstructor", &DOMConstructorObject::s_info, &JSSpeechInputResultConstructorTable, 0 };

JSSpeechInputResultConstructor::JSSpeechInputResultConstructor(Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(structure, globalObject)
{
}

void JSSpeechInputResultConstructor::finishCreation(ExecState* exec, JSDOMGlobalObject* globalObject)
{
    Base::finishCreation(exec->globalData());
    ASSERT(inherits(&s_info));
    putDirect(exec->globalData(), exec->propertyNames().prototype, JSSpeechInputResultPrototype::self(exec, globalObject), DontDelete | ReadOnly);
}

bool JSSpeechInputResultConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSpeechInputResultConstructor, JSDOMWrapper>(exec, &JSSpeechInputResultConstructorTable, this, propertyName, slot);
}

bool JSSpeechInputResultConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSpeechInputResultConstructor, JSDOMWrapper>(exec, &JSSpeechInputResultConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSpeechInputResultPrototypeTableValues[] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSpeechInputResultPrototypeTable = { 1, 0, JSSpeechInputResultPrototypeTableValues, 0 };
const ClassInfo JSSpeechInputResultPrototype::s_info = { "SpeechInputResultPrototype", &JSC::JSNonFinalObject::s_info, &JSSpeechInputResultPrototypeTable, 0 };

JSObject* JSSpeechInputResultPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSSpeechInputResult>(exec, globalObject);
}

const ClassInfo JSSpeechInputResult::s_info = { "SpeechInputResult", &JSDOMWrapper::s_info, &JSSpeechInputResultTable, 0 };

JSSpeechInputResult::JSSpeechInputResult(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<SpeechInputResult> impl)
    : JSDOMWrapper(structure, globalObject)
    , m_impl(impl)
{
}

void JSSpeechInputResult::finishCreation(JSGlobalData& globalData)
{
    Base::finishCreation(globalData);
    ASSERT(inherits(&s_info));
}

JSObject* JSSpeechInputResult::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return JSSpeechInputResultPrototype::create(exec->globalData(), globalObject, JSSpeechInputResultPrototype::createStructure(globalObject->globalData(), globalObject, globalObject->objectPrototype()));
}

bool JSSpeechInputResult::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    return getStaticValueSlot<JSSpeechInputResult, Base>(exec, &JSSpeechInputResultTable, this, propertyName, slot);
}

bool JSSpeechInputResult::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    return getStaticValueDescriptor<JSSpeechInputResult, Base>(exec, &JSSpeechInputResultTable, this, propertyName, descriptor);
}

JSValue jsSpeechInputResultUtterance(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSpeechInputResult* castedThis = static_cast<JSSpeechInputResult*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SpeechInputResult* imp = static_cast<SpeechInputResult*>(castedThis->impl());
    JSValue result = jsString(exec, imp->utterance());
    return result;
}


JSValue jsSpeechInputResultConfidence(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSpeechInputResult* castedThis = static_cast<JSSpeechInputResult*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SpeechInputResult* imp = static_cast<SpeechInputResult*>(castedThis->impl());
    JSValue result = jsNumber(imp->confidence());
    return result;
}


JSValue jsSpeechInputResultConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSpeechInputResult* domObject = static_cast<JSSpeechInputResult*>(asObject(slotBase));
    return JSSpeechInputResult::getConstructor(exec, domObject->globalObject());
}

JSValue JSSpeechInputResult::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSSpeechInputResultConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, SpeechInputResult* impl)
{
    return wrap<JSSpeechInputResult>(exec, globalObject, impl);
}

SpeechInputResult* toSpeechInputResult(JSC::JSValue value)
{
    return value.inherits(&JSSpeechInputResult::s_info) ? static_cast<JSSpeechInputResult*>(asObject(value))->impl() : 0;
}

}

#endif // ENABLE(INPUT_SPEECH)
