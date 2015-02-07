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
#include "JSDocumentFragment.h"

#include "DocumentFragment.h"
#include "Element.h"
#include "ExceptionCode.h"
#include "JSDOMBinding.h"
#include "JSElement.h"
#include "JSNodeList.h"
#include "NameNodeList.h"
#include "NodeList.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSDocumentFragment);

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSDocumentFragmentTableValues[] =
{
    { "constructor", DontEnum | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsDocumentFragmentConstructor), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSDocumentFragmentTable = { 2, 1, JSDocumentFragmentTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSDocumentFragmentConstructorTableValues[] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSDocumentFragmentConstructorTable = { 1, 0, JSDocumentFragmentConstructorTableValues, 0 };
class JSDocumentFragmentConstructor : public DOMConstructorObject {
private:
    JSDocumentFragmentConstructor(JSC::Structure*, JSDOMGlobalObject*);
    void finishCreation(JSC::ExecState*, JSDOMGlobalObject*);

public:
    typedef DOMConstructorObject Base;
    static JSDocumentFragmentConstructor* create(JSC::ExecState* exec, JSC::Structure* structure, JSDOMGlobalObject* globalObject)
    {
        JSDocumentFragmentConstructor* ptr = new (JSC::allocateCell<JSDocumentFragmentConstructor>(*exec->heap())) JSDocumentFragmentConstructor(structure, globalObject);
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

const ClassInfo JSDocumentFragmentConstructor::s_info = { "DocumentFragmentConstructor", &DOMConstructorObject::s_info, &JSDocumentFragmentConstructorTable, 0 };

JSDocumentFragmentConstructor::JSDocumentFragmentConstructor(Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(structure, globalObject)
{
}

void JSDocumentFragmentConstructor::finishCreation(ExecState* exec, JSDOMGlobalObject* globalObject)
{
    Base::finishCreation(exec->globalData());
    ASSERT(inherits(&s_info));
    putDirect(exec->globalData(), exec->propertyNames().prototype, JSDocumentFragmentPrototype::self(exec, globalObject), DontDelete | ReadOnly);
}

bool JSDocumentFragmentConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSDocumentFragmentConstructor, JSDOMWrapper>(exec, &JSDocumentFragmentConstructorTable, this, propertyName, slot);
}

bool JSDocumentFragmentConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSDocumentFragmentConstructor, JSDOMWrapper>(exec, &JSDocumentFragmentConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSDocumentFragmentPrototypeTableValues[] =
{
    { "querySelector", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsDocumentFragmentPrototypeFunctionQuerySelector), (intptr_t)1 THUNK_GENERATOR(0) },
    { "querySelectorAll", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsDocumentFragmentPrototypeFunctionQuerySelectorAll), (intptr_t)1 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSDocumentFragmentPrototypeTable = { 4, 3, JSDocumentFragmentPrototypeTableValues, 0 };
const ClassInfo JSDocumentFragmentPrototype::s_info = { "DocumentFragmentPrototype", &JSC::JSNonFinalObject::s_info, &JSDocumentFragmentPrototypeTable, 0 };

JSObject* JSDocumentFragmentPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSDocumentFragment>(exec, globalObject);
}

bool JSDocumentFragmentPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSDocumentFragmentPrototypeTable, this, propertyName, slot);
}

bool JSDocumentFragmentPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSDocumentFragmentPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSDocumentFragment::s_info = { "DocumentFragment", &JSNode::s_info, &JSDocumentFragmentTable, 0 };

JSDocumentFragment::JSDocumentFragment(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<DocumentFragment> impl)
    : JSNode(structure, globalObject, impl)
{
}

void JSDocumentFragment::finishCreation(JSGlobalData& globalData)
{
    Base::finishCreation(globalData);
    ASSERT(inherits(&s_info));
}

JSObject* JSDocumentFragment::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return JSDocumentFragmentPrototype::create(exec->globalData(), globalObject, JSDocumentFragmentPrototype::createStructure(exec->globalData(), globalObject, JSNodePrototype::self(exec, globalObject)));
}

bool JSDocumentFragment::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    return getStaticValueSlot<JSDocumentFragment, Base>(exec, &JSDocumentFragmentTable, this, propertyName, slot);
}

bool JSDocumentFragment::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    return getStaticValueDescriptor<JSDocumentFragment, Base>(exec, &JSDocumentFragmentTable, this, propertyName, descriptor);
}

JSValue jsDocumentFragmentConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSDocumentFragment* domObject = static_cast<JSDocumentFragment*>(asObject(slotBase));
    return JSDocumentFragment::getConstructor(exec, domObject->globalObject());
}

JSValue JSDocumentFragment::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSDocumentFragmentConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

EncodedJSValue JSC_HOST_CALL jsDocumentFragmentPrototypeFunctionQuerySelector(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSDocumentFragment::s_info))
        return throwVMTypeError(exec);
    JSDocumentFragment* castedThis = static_cast<JSDocumentFragment*>(asObject(thisValue));
    ASSERT_GC_OBJECT_INHERITS(castedThis, &JSDocumentFragment::s_info);
    DocumentFragment* imp = static_cast<DocumentFragment*>(castedThis->impl());
    if (exec->argumentCount() < 1)
        return throwVMError(exec, createTypeError(exec, "Not enough arguments"));
    ExceptionCode ec = 0;
    const String& selectors(ustringToString(exec->argument(0).toString(exec)));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());


    JSC::JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->querySelector(selectors, ec)));
    setDOMException(exec, ec);
    return JSValue::encode(result);
}

EncodedJSValue JSC_HOST_CALL jsDocumentFragmentPrototypeFunctionQuerySelectorAll(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSDocumentFragment::s_info))
        return throwVMTypeError(exec);
    JSDocumentFragment* castedThis = static_cast<JSDocumentFragment*>(asObject(thisValue));
    ASSERT_GC_OBJECT_INHERITS(castedThis, &JSDocumentFragment::s_info);
    DocumentFragment* imp = static_cast<DocumentFragment*>(castedThis->impl());
    if (exec->argumentCount() < 1)
        return throwVMError(exec, createTypeError(exec, "Not enough arguments"));
    ExceptionCode ec = 0;
    const String& selectors(ustringToString(exec->argument(0).toString(exec)));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());


    JSC::JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->querySelectorAll(selectors, ec)));
    setDOMException(exec, ec);
    return JSValue::encode(result);
}


}
