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

#ifndef JSWebGLActiveInfo_h
#define JSWebGLActiveInfo_h

#if ENABLE(WEBGL)

#include "JSDOMBinding.h"
#include "WebGLActiveInfo.h"
#include <runtime/JSGlobalObject.h>
#include <runtime/JSObject.h>
#include <runtime/ObjectPrototype.h>

namespace WebCore {

class JSWebGLActiveInfo : public JSDOMWrapper {
public:
    typedef JSDOMWrapper Base;
    static JSWebGLActiveInfo* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<WebGLActiveInfo> impl)
    {
        JSWebGLActiveInfo* ptr = new (JSC::allocateCell<JSWebGLActiveInfo>(globalObject->globalData().heap)) JSWebGLActiveInfo(structure, globalObject, impl);
        ptr->finishCreation(globalObject->globalData());
        return ptr;
    }

    static JSC::JSObject* createPrototype(JSC::ExecState*, JSC::JSGlobalObject*);
    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertyDescriptor&);
    static const JSC::ClassInfo s_info;

    static JSC::Structure* createStructure(JSC::JSGlobalData& globalData, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(globalData, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), &s_info);
    }

    static JSC::JSValue getConstructor(JSC::ExecState*, JSC::JSGlobalObject*);
    WebGLActiveInfo* impl() const { return m_impl.get(); }

private:
    RefPtr<WebGLActiveInfo> m_impl;
protected:
    JSWebGLActiveInfo(JSC::Structure*, JSDOMGlobalObject*, PassRefPtr<WebGLActiveInfo>);
    void finishCreation(JSC::JSGlobalData&);
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, WebGLActiveInfo*);
WebGLActiveInfo* toWebGLActiveInfo(JSC::JSValue);

class JSWebGLActiveInfoPrototype : public JSC::JSNonFinalObject {
public:
    typedef JSC::JSNonFinalObject Base;
    static JSC::JSObject* self(JSC::ExecState*, JSC::JSGlobalObject*);
    static JSWebGLActiveInfoPrototype* create(JSC::JSGlobalData& globalData, JSC::JSGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSWebGLActiveInfoPrototype* ptr = new (JSC::allocateCell<JSWebGLActiveInfoPrototype>(globalData.heap)) JSWebGLActiveInfoPrototype(globalData, globalObject, structure);
        ptr->finishCreation(globalData);
        return ptr;
    }

    static const JSC::ClassInfo s_info;
    static JSC::Structure* createStructure(JSC::JSGlobalData& globalData, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(globalData, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), &s_info);
    }

private:
    JSWebGLActiveInfoPrototype(JSC::JSGlobalData& globalData, JSC::JSGlobalObject*, JSC::Structure* structure) : JSC::JSNonFinalObject(globalData, structure) { }
protected:
    static const unsigned StructureFlags = Base::StructureFlags;
};

// Attributes

JSC::JSValue jsWebGLActiveInfoSize(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsWebGLActiveInfoType(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsWebGLActiveInfoName(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsWebGLActiveInfoConstructor(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);

} // namespace WebCore

#endif // ENABLE(WEBGL)

#endif
