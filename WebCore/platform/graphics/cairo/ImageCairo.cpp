/*
 * Copyright (C) 2004, 2005, 2006 Apple Computer, Inc.  All rights reserved.
 * Copyright (C) 2007 Alp Toker <alp@atoker.com>
 * Copyright (C) 2009 Dirk Schulze <krit@webkit.org>
 * Copyright (C) 2012, 2013 Electronic Arts, Inc. All rights reserved.
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
#include "BitmapImage.h"

#if USE(CAIRO)

#include "AffineTransform.h"
#include "CairoUtilities.h"
#include "Color.h"
#include "FloatRect.h"
#include "GraphicsContext.h"
#include "PlatformContextCairo.h"
#include "ImageBuffer.h"
#include "ImageObserver.h"
#include "RefPtrCairo.h"
#include <cairo.h>
#include <math.h>
#include <wtf/OwnPtr.h>

//+EAWebKitChange
//5/21/2012
#if ENABLE(IMAGE_COMPRESSION)
#include "ImageCompressionEA.h" 
#endif

// Also added checking for surface user data in order to detect a compressed surface.
// Images using compression need to be destroyed on exit.
//-EAWebKitChange

namespace WebCore {

bool FrameData::clear(bool clearMetadata)
{
    if (clearMetadata)
        m_haveMetadata = false;

//+EAWebKitChange
//5/17/2012
#if ENABLE(IMAGE_COMPRESSION)
    // When using image compression, we need to release the buffer that holds the compressed image.
    if (m_compressedDataBuffer)
    {
        ImageCompressionReleaseBuffer(m_compressedDataBuffer);
        m_compressedDataBuffer = 0;
        m_compressedSize = 0; 
    }
#endif
//-EAWebKitChange  

    if (m_frame) {
        cairo_surface_destroy(m_frame);
        m_frame = 0;
        return true;
    }
    return false;
}

BitmapImage::BitmapImage(cairo_surface_t* surface, ImageObserver* observer)
    : Image(observer)
    , m_currentFrame(0)
    , m_frames(0)
    , m_frameTimer(0)
    , m_repetitionCount(cAnimationNone)
    , m_repetitionCountStatus(Unknown)
    , m_repetitionsComplete(0)
    , m_isSolidColor(false)
    , m_checkedForSolidColor(false)
    , m_animationFinished(true)
    , m_allDataReceived(true)
    , m_haveSize(true)
    , m_sizeAvailable(true)
    , m_decodedSize(0)
    , m_haveFrameCount(true)
    , m_frameCount(1)
{
    initPlatformData();

    // TODO: check to be sure this is an image surface

    int width = cairo_image_surface_get_width(surface);
    int height = cairo_image_surface_get_height(surface);
    m_decodedSize = width * height * 4;
    m_size = IntSize(width, height);

    m_frames.grow(1);
    m_frames[0].m_frame = surface;
    m_frames[0].m_hasAlpha = cairo_surface_get_content(surface) != CAIRO_CONTENT_COLOR;
    m_frames[0].m_haveMetadata = true;
    checkForSolidColor();
}

void BitmapImage::draw(GraphicsContext* context, const FloatRect& dst, const FloatRect& src, ColorSpace styleColorSpace, CompositeOperator op)
{
    FloatRect srcRect(src);
    FloatRect dstRect(dst);

    if (dstRect.width() == 0.0f || dstRect.height() == 0.0f ||
        srcRect.width() == 0.0f || srcRect.height() == 0.0f)
        return;

    startAnimation();

    cairo_surface_t* image = frameAtIndex(m_currentFrame);
    if (!image) // If it's too early we won't have an image yet.
        return;

//+EAWebKitChange
//5/30/2012
#if ENABLE(IMAGE_COMPRESSION)
    // Check if this is a compressed surface. 
    const void* pCompressedSurfaceUserData = cairo_surface_get_user_data (image, (cairo_user_data_key_t*) ImageCompressionGetUserDataKey());
#endif
//-EAWebKitChange

    if (mayFillWithSolidColor()) {
        fillWithSolidColor(context, dstRect, solidColor(), styleColorSpace, op);
        
//+EAWebKitChange
//5/30/2012
#if ENABLE(IMAGE_COMPRESSION)
        if (pCompressedSurfaceUserData)
            cairo_surface_destroy(image);
#endif
//-EAWebKitChange
        return;
    }

    context->save();

    // Set the compositing operation.
    if (op == CompositeSourceOver && !frameHasAlphaAtIndex(m_currentFrame))
        context->setCompositeOperation(CompositeCopy);
    else
        context->setCompositeOperation(op);
    context->platformContext()->drawSurfaceToContext(image, dstRect, srcRect, context);

    context->restore();

    if (imageObserver())
        imageObserver()->didDraw(this);

//+EAWebKitChange
//5/30/2012
#if ENABLE(IMAGE_COMPRESSION)
    if (pCompressedSurfaceUserData)
        cairo_surface_destroy(image);   
#endif
//-EAWebKitChange
}

void Image::drawPattern(GraphicsContext* context, const FloatRect& tileRect, const AffineTransform& patternTransform,
                        const FloatPoint& phase, ColorSpace colorSpace, CompositeOperator op, const FloatRect& destRect)
{
    cairo_surface_t* image = nativeImageForCurrentFrame();
    if (!image) // If it's too early we won't have an image yet.
        return;

    cairo_t* cr = context->platformContext()->cr();
    drawPatternToCairoContext(cr, image, size(), tileRect, patternTransform, phase, toCairoOperator(op), destRect);

    if (imageObserver())
        imageObserver()->didDraw(this);

//+EAWebKitChange
//5/30/2012
#if ENABLE(IMAGE_COMPRESSION)
    // Check if this is a compressed surface.
    const void* pCompressedSurfaceUserData = cairo_surface_get_user_data (image, (cairo_user_data_key_t*) ImageCompressionGetUserDataKey());
    if (pCompressedSurfaceUserData)
        cairo_surface_destroy(image);
#endif
//-EAWebKitChange
}

void BitmapImage::checkForSolidColor()
{
    m_isSolidColor = false;
    m_checkedForSolidColor = true;

    if (frameCount() > 1)
        return;

    cairo_surface_t* frameSurface = frameAtIndex(0);
    if (!frameSurface)
        return;

//+EAWebKitChange
//5/30/2012
#if ENABLE(IMAGE_COMPRESSION)
    // Check if this is a compressed surface. 
    const void* pCompressedSurfaceUserData = cairo_surface_get_user_data (frameSurface, (cairo_user_data_key_t*) ImageCompressionGetUserDataKey());
#endif
//-EAWebKitChange


    ASSERT(cairo_surface_get_type(frameSurface) == CAIRO_SURFACE_TYPE_IMAGE);

    int width = cairo_image_surface_get_width(frameSurface);
    int height = cairo_image_surface_get_height(frameSurface);

    if (width != 1 || height != 1)
    {
    //+EAWebKitChange
    //5/30/2012
	#if ENABLE(IMAGE_COMPRESSION)
        if (pCompressedSurfaceUserData)
            cairo_surface_destroy(frameSurface);   
    #endif
     //-EAWebKitChange     
        return;
    }
    unsigned* pixelColor = reinterpret_cast<unsigned*>(cairo_image_surface_get_data(frameSurface));
    m_solidColor = colorFromPremultipliedARGB(*pixelColor);

    m_isSolidColor = true;

//+EAWebKitChange
//5/30/2012
#if ENABLE(IMAGE_COMPRESSION)
    if (pCompressedSurfaceUserData)
        cairo_surface_destroy(frameSurface);
#endif
//-EAWebKitChange     
}

}

#endif // USE(CAIRO)
