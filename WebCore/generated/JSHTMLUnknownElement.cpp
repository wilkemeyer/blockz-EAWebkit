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
#include "JSHTMLUnknownElement.h"

#include "HTMLUnknownElement.h"
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSHTMLUnknownElement);

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLUnknownElementTableValues[] =
{
    { "constructor", DontEnum | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLUnknownElementConstructor), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLUnknownElementTable = { 2, 1, JSHTMLUnknownElementTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLUnknownElementConstructorTableValues[] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLUnknownElementConstructorTable = { 1, 0, JSHTMLUnknownElementConstructorTableValues, 0 };
class JSHTMLUnknownElementConstructor : public DOMConstructorObject {
private:
    JSHTMLUnknownElementConstructor(JSC::Structure*, JSDOMGlobalObject*);
    void finishCreation(JSC::ExecState*, JSDOMGlobalObject*);

public:
    typedef DOMConstructorObject Base;
    static JSHTMLUnknownElementConstructor* create(JSC::ExecState* exec, JSC::Structure* structure, JSDOMGlobalObject* globalObject)
    {
        JSHTMLUnknownElementConstructor* ptr = new (JSC::allocateCell<JSHTMLUnknownElementConstructor>(*exec->heap())) JSHTMLUnknownElementConstructor(structure, globalObject);
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

const ClassInfo JSHTMLUnknownElementConstructor::s_info = { "HTMLUnknownElementConstructor", &DOMConstructorObject::s_info, &JSHTMLUnknownElementConstructorTable, 0 };

JSHTMLUnknownElementConstructor::JSHTMLUnknownElementConstructor(Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(structure, globalObject)
{
}

void JSHTMLUnknownElementConstructor::finishCreation(ExecState* exec, JSDOMGlobalObject* globalObject)
{
    Base::finishCreation(exec->globalData());
    ASSERT(inherits(&s_info));
    putDirect(exec->globalData(), exec->propertyNames().prototype, JSHTMLUnknownElementPrototype::self(exec, globalObject), DontDelete | ReadOnly);
}

bool JSHTMLUnknownElementConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLUnknownElementConstructor, JSDOMWrapper>(exec, &JSHTMLUnknownElementConstructorTable, this, propertyName, slot);
}

bool JSHTMLUnknownElementConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSHTMLUnknownElementConstructor, JSDOMWrapper>(exec, &JSHTMLUnknownElementConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLUnknownElementPrototypeTableValues[] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLUnknownElementPrototypeTable = { 1, 0, JSHTMLUnknownElementPrototypeTableValues, 0 };
const ClassInfo JSHTMLUnknownElementPrototype::s_info = { "HTMLUnknownElementPrototype", &JSC::JSNonFinalObject::s_info, &JSHTMLUnknownElementPrototypeTable, 0 };

JSObject* JSHTMLUnknownElementPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSHTMLUnknownElement>(exec, globalObject);
}

const ClassInfo JSHTMLUnknownElement::s_info = { "HTMLUnknownElement", &JSHTMLElement::s_info, &JSHTMLUnknownElementTable, 0 };

JSHTMLUnknownElement::JSHTMLUnknownElement(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<HTMLUnknownElement> impl)
    : JSHTMLElement(structure, globalObject, impl)
{
}

void JSHTMLUnknownElement::finishCreation(JSGlobalData& globalData)
{
    Base::finishCreation(globalData);
    ASSERT(inherits(&s_info));
}

JSObject* JSHTMLUnknownElement::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return JSHTMLUnknownElementPrototype::create(exec->globalData(), globalObject, JSHTMLUnknownElementPrototype::createStructure(exec->globalData(), globalObject, JSHTMLElementPrototype::self(exec, globalObject)));
}

bool JSHTMLUnknownElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    return getStaticValueSlot<JSHTMLUnknownElement, Base>(exec, &JSHTMLUnknownElementTable, this, propertyName, slot);
}

bool JSHTMLUnknownElement::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    return getStaticValueDescriptor<JSHTMLUnknownElement, Base>(exec, &JSHTMLUnknownElementTable, this, propertyName, descriptor);
}

JSValue jsHTMLUnknownElementConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLUnknownElement* domObject = static_cast<JSHTMLUnknownElement*>(asObject(slotBase));
    return JSHTMLUnknownElement::getConstructor(exec, domObject->globalObject());
}

JSValue JSHTMLUnknownElement::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSHTMLUnknownElementConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}


}
