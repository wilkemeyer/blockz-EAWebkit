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

#if ENABLE(SVG_ANIMATION)

#include "JSSVGAnimateColorElement.h"

#include "SVGAnimateColorElement.h"
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSSVGAnimateColorElement);

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSVGAnimateColorElementTableValues[] =
{
    { "constructor", DontEnum | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGAnimateColorElementConstructor), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSVGAnimateColorElementTable = { 2, 1, JSSVGAnimateColorElementTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSVGAnimateColorElementConstructorTableValues[] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSVGAnimateColorElementConstructorTable = { 1, 0, JSSVGAnimateColorElementConstructorTableValues, 0 };
class JSSVGAnimateColorElementConstructor : public DOMConstructorObject {
private:
    JSSVGAnimateColorElementConstructor(JSC::Structure*, JSDOMGlobalObject*);
    void finishCreation(JSC::ExecState*, JSDOMGlobalObject*);

public:
    typedef DOMConstructorObject Base;
    static JSSVGAnimateColorElementConstructor* create(JSC::ExecState* exec, JSC::Structure* structure, JSDOMGlobalObject* globalObject)
    {
        JSSVGAnimateColorElementConstructor* ptr = new (JSC::allocateCell<JSSVGAnimateColorElementConstructor>(*exec->heap())) JSSVGAnimateColorElementConstructor(structure, globalObject);
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

const ClassInfo JSSVGAnimateColorElementConstructor::s_info = { "SVGAnimateColorElementConstructor", &DOMConstructorObject::s_info, &JSSVGAnimateColorElementConstructorTable, 0 };

JSSVGAnimateColorElementConstructor::JSSVGAnimateColorElementConstructor(Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(structure, globalObject)
{
}

void JSSVGAnimateColorElementConstructor::finishCreation(ExecState* exec, JSDOMGlobalObject* globalObject)
{
    Base::finishCreation(exec->globalData());
    ASSERT(inherits(&s_info));
    putDirect(exec->globalData(), exec->propertyNames().prototype, JSSVGAnimateColorElementPrototype::self(exec, globalObject), DontDelete | ReadOnly);
}

bool JSSVGAnimateColorElementConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGAnimateColorElementConstructor, JSDOMWrapper>(exec, &JSSVGAnimateColorElementConstructorTable, this, propertyName, slot);
}

bool JSSVGAnimateColorElementConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGAnimateColorElementConstructor, JSDOMWrapper>(exec, &JSSVGAnimateColorElementConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSVGAnimateColorElementPrototypeTableValues[] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSVGAnimateColorElementPrototypeTable = { 1, 0, JSSVGAnimateColorElementPrototypeTableValues, 0 };
const ClassInfo JSSVGAnimateColorElementPrototype::s_info = { "SVGAnimateColorElementPrototype", &JSC::JSNonFinalObject::s_info, &JSSVGAnimateColorElementPrototypeTable, 0 };

JSObject* JSSVGAnimateColorElementPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSSVGAnimateColorElement>(exec, globalObject);
}

const ClassInfo JSSVGAnimateColorElement::s_info = { "SVGAnimateColorElement", &JSSVGAnimationElement::s_info, &JSSVGAnimateColorElementTable, 0 };

JSSVGAnimateColorElement::JSSVGAnimateColorElement(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<SVGAnimateColorElement> impl)
    : JSSVGAnimationElement(structure, globalObject, impl)
{
}

void JSSVGAnimateColorElement::finishCreation(JSGlobalData& globalData)
{
    Base::finishCreation(globalData);
    ASSERT(inherits(&s_info));
}

JSObject* JSSVGAnimateColorElement::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return JSSVGAnimateColorElementPrototype::create(exec->globalData(), globalObject, JSSVGAnimateColorElementPrototype::createStructure(exec->globalData(), globalObject, JSSVGAnimationElementPrototype::self(exec, globalObject)));
}

bool JSSVGAnimateColorElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    return getStaticValueSlot<JSSVGAnimateColorElement, Base>(exec, &JSSVGAnimateColorElementTable, this, propertyName, slot);
}

bool JSSVGAnimateColorElement::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    return getStaticValueDescriptor<JSSVGAnimateColorElement, Base>(exec, &JSSVGAnimateColorElementTable, this, propertyName, descriptor);
}

JSValue jsSVGAnimateColorElementConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGAnimateColorElement* domObject = static_cast<JSSVGAnimateColorElement*>(asObject(slotBase));
    return JSSVGAnimateColorElement::getConstructor(exec, domObject->globalObject());
}

JSValue JSSVGAnimateColorElement::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSSVGAnimateColorElementConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}


}

#endif // ENABLE(SVG_ANIMATION)
