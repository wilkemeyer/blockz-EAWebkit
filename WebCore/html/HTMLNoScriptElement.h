/*
 * Copyright (C) 2009 Torch Mobile Inc. All rights reserved. (http://www.torchmobile.com/)
 * Copyright (C) 2010 Apple Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#ifndef HTMLNoScriptElement_h
#define HTMLNoScriptElement_h

#if ENABLE(XHTMLMP)
#include "HTMLElement.h"

namespace WebCore {

class HTMLNoScriptElement : public HTMLElement {
public:
    static PassRefPtr<HTMLNoScriptElement> create(const QualifiedName&, Document*);

private:
    HTMLNoScriptElement(const QualifiedName&, Document*);

    virtual void attach();
    virtual bool willRecalcStyle(StyleChange);
    virtual bool childShouldCreateRenderer(Node*) const;
    virtual bool rendererIsNeeded(const NodeRenderingContext&) {  return true; }
#if ENABLE(XHTMLMP)
    virtual PassRefPtr<RenderStyle> customStyleForRenderer();
#endif
};

} //namespace

#endif
#endif
