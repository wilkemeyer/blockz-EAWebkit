/*
 * Copyright (C) 2007, 2008 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#include "config.h"
#include "WebKitAnimationEvent.h"

#include "EventNames.h"

namespace WebCore {

WebKitAnimationEventInit::WebKitAnimationEventInit()
    : animationName()
    , elapsedTime(0.0)
{
}

WebKitAnimationEvent::WebKitAnimationEvent()
    : m_elapsedTime(0.0)
{
}

WebKitAnimationEvent::WebKitAnimationEvent(const AtomicString& type, const WebKitAnimationEventInit& initializer)
    : Event(type, initializer)
    , m_animationName(initializer.animationName)
    , m_elapsedTime(initializer.elapsedTime)
{
}

WebKitAnimationEvent::WebKitAnimationEvent(const AtomicString& type, const String& animationName, double elapsedTime)
    : Event(type, true, true)
    , m_animationName(animationName)
    , m_elapsedTime(elapsedTime)
{
}

WebKitAnimationEvent::~WebKitAnimationEvent()
{
}

void WebKitAnimationEvent::initWebKitAnimationEvent(const AtomicString& type, 
                                        bool canBubbleArg,
                                        bool cancelableArg,
                                        const String& animationName,
                                        double elapsedTime)
{
    if (dispatched())
        return;
    
    initEvent(type, canBubbleArg, cancelableArg);
    
    m_animationName = animationName;
    m_elapsedTime = elapsedTime;
}

const String& WebKitAnimationEvent::animationName() const
{
    return m_animationName;
}

double WebKitAnimationEvent::elapsedTime() const
{
    return m_elapsedTime;
}

} // namespace WebCore
