/*
 * Copyright © 2007 Luca Barbato
 * Copyright © 2011 Electronic Arts, Inc.
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of Luca Barbato not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  Luca Barbato makes no representations about the
 * suitability of this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS
 * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS, IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING
 * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 *
 * Author:  Luca Barbato (lu_zero@gentoo.org)
 *
 * Based on fbmmx.c by Owen Taylor, Søren Sandmann and Nicholas Miell
 * 
 * Author: Arpit Baldeva
 * Based on pixman-vmx.c
 */

#ifdef HAVE_CONFIG_H 
#include <config.h>
#endif

#ifdef USE_VMX128
#include <comdecl.h>
#include <stdint.h>
#include <stdio.h>
#include "pixman-private.h"
#include "pixman-combine32.h"


static __vector4i vmx128i_splat_alpha_vector =  {0x00000000, 0x04040404,0x08080808, 0x0C0C0C0C};
static __vector4i zeroVectori = {0x00,0x00,0x00,0x00};
static __vector4i zeroEightVectori = {0x00800080,0x00800080,0x00800080,0x00800080};

static __vector4i permVecLoi	= {0x10100001,0x10100203,0x10100405,0x10100607};
static __vector4i permVecHii	= {0x10100809,0x10100A0B,0x10100C0D,0x10100E0F};
static __vector4i permVec1Vec2i = {0x02030607,0x0A0B0E0F,0x12131617,0x1A1B1E1F};

static  force_inline __vector4
splat_alpha (__vector4 pix)
{
	return __vperm (pix, pix, *(__vector4*)(&vmx128i_splat_alpha_vector));
}

static force_inline __vector4
pix_multiply (__vector4 p, __vector4 a)
{
	__vector4 hi, lo, mod;
	
	__vector4 hiLow, hiHigh, modLow, modHigh, loLow, loHigh;
	__vector4 hiLowFP, hiHighFP, modLowFP, modHighFP, loLowFP, loHighFP;
	__vector4 himodLow, himodHigh, lomodLow, lomodHigh;
	
 	__vector4 zeroVector = *(__vector4*)(&zeroVectori);
 	__vector4 zeroEightVector = *(__vector4*)(&zeroEightVectori);
	__vector4 permVecLo = *(__vector4*)(&permVecLoi);
	__vector4 permVecHi = *(__vector4*)(&permVecHii);
	__vector4 permVec1Vec2 = *(__vector4*)(&permVec1Vec2i);

	/* unpack to short */
	hi  = __vmrghb(zeroVector,p);
	mod = __vmrghb(zeroVector,a);
	
	//+ What we want to do here is to multiply 8 unsigned shorts of the hi with 8 unsigned shorts of mod.
	/* Extract the hi vector into 4 Unsigned int by using 4 Lower unsigned shorts*/
	hiLow	= __vperm(hi,zeroVector, permVecLo);
	/* Extract the hi vector into 4 Unsigned int by using 4 Upper unsigned shorts*/
	hiHigh	= __vperm(hi,zeroVector, permVecHi);

	/* Extract the mod vector into 4 Unsigned int by using 4 Lower unsigned shorts*/
	modLow	= __vperm(mod,zeroVector, permVecLo);
	/* Extract the mod vector into 4 Unsigned int by using 4 Upper unsigned shorts*/
	modHigh = __vperm(mod,zeroVector, permVecHi);

	/* Convert the 4 unsigned ints to floating point by treating them as Fixed point*/ 
	hiLowFP		= __vcfux(hiLow,0);
	hiHighFP	= __vcfux(hiHigh,0);
	modLowFP	= __vcfux(modLow,0);
	modHighFP	= __vcfux(modHigh,0);

	/* Multiply the floating points */
	himodLow	= __vmaddfp(hiLowFP, modLowFP,zeroVector);
	himodHigh	= __vmaddfp(hiHighFP, modHighFP,zeroVector);
	
	/* Convert the floating points to Fixed Point with zero digits after radix point - Effectively an unsigned int*/
	himodLow	= __vctuxs(himodLow,0);
	himodHigh	= __vctuxs(himodHigh,0);

	/* Fuse the multiplication together to get the final product*/
	hi = __vperm(himodLow,himodHigh,permVec1Vec2);

	//-



	hi = __vadduhm(hi,zeroEightVector);
	
	hi = __vadduhs(hi, __vsrh(hi, __vspltish (8)));
	hi = __vsrh (hi, __vspltish (8));


	/* unpack to short */
	lo  = __vmrglb(zeroVector,p);
	mod = __vmrglb(zeroVector,a);
	
	//+ Comments from few lines above applicable here.
	loLow	= __vperm(lo,zeroVector,permVecLo);
	loHigh	= __vperm(lo,zeroVector, permVecHi); 

	modLow	= __vperm(mod,zeroVector, permVecLo);
	modHigh = __vperm(mod,zeroVector, permVecHi);

	loLowFP		= __vcfux(loLow,0);
	loHighFP	= __vcfux(loHigh,0);
	modLowFP	= __vcfux(modLow,0);
	modHighFP	= __vcfux(modHigh,0);

	lomodLow	= __vmaddfp(loLowFP, modLowFP,zeroVector);
	lomodHigh	= __vmaddfp(loHighFP, modHighFP,zeroVector);
	
	lomodLow	= __vctuxs(lomodLow,0);
	lomodHigh	= __vctuxs(lomodHigh,0);

	lo = __vperm(lomodLow,lomodHigh,permVec1Vec2);
	//-

	lo = __vadduhm(lo,zeroEightVector);
	
	lo = __vadduhs (lo, __vsrh (lo, __vspltish (8)));
	lo = __vsrh (lo, __vspltish (8));

	return __vpkuhus (hi, lo);
}

static force_inline __vector4
pix_add (__vector4 a, __vector4 b)
{
	return __vaddubs(a,b);
}


static  force_inline __vector4
pix_add_mul (__vector4 x,
			 __vector4 a,
			 __vector4 y,
			 __vector4 b)
{
	__vector4 t1, t2;

    t1 = pix_multiply (x, a);
    t2 = pix_multiply (y, b);

    return pix_add (t1, t2);
}

static force_inline __vector4
negate (__vector4 src)
{
	return __vnor (src, src);
}

/* dest*~srca + src */
static force_inline __vector4
over (__vector4 src,
	  __vector4 srca,
	  __vector4 dest)
{
	__vector4 tmp = pix_multiply (dest, negate (srca));

	tmp = __vaddubs (src, tmp);
	return tmp;
}

/* in == pix_multiply */
#define in_over(src, srca, mask, dest)					\
    over (pix_multiply (src, mask),					\
          pix_multiply (srca, mask), dest)


#define COMPUTE_SHIFT_MASK(source)					\
	source ## _mask = __lvsl (source, 0);

#define COMPUTE_SHIFT_MASKS(dest, source)				\
    dest ## _mask = __lvsl (dest, 0);					\
    source ## _mask = __lvsl (source, 0);				\
    store_mask = __lvsr (dest, 0);

#define COMPUTE_SHIFT_MASKC(dest, source, mask)				\
    mask ## _mask = __lvsl (mask,0);					\
    dest ## _mask = __lvsl (dest,0);					\
    source ## _mask = __lvsl (source,0);				\
    store_mask = __lvsr (dest,0);

/* notice you have to declare temp vars...
 * Note: tmp3 and tmp4 must remain untouched!
 */

#define LOAD_VECTORS(dest, source)			  \
    tmp1 = __lvx (source,0);		  \
    tmp2 = __lvx (source,15);		  \
    tmp3 = __lvx (dest,0);		  \
    v ## source = 			  \
	__vperm (tmp1, tmp2, source ## _mask);		  \
    tmp4 = __lvx (dest,15);		  \
    v ## dest = 			  \
	__vperm (tmp3, tmp4, dest ## _mask);

#define LOAD_VECTORSC(dest, source, mask)		  \
    tmp1 = __lvx (source,0);		  \
    tmp2 = __lvx (source,15);		  \
    tmp3 = __lvx (dest,0);		  \
    v ## source = 			  \
	__vperm (tmp1, tmp2, source ## _mask);		  \
    tmp4 = __lvx (dest,15);		  \
    tmp1 = __lvx (mask,0);		  \
    v ## dest = 			  \
	__vperm (tmp3, tmp4, dest ## _mask);		  \
    tmp2 = __lvx (mask,15);		  \
    v ## mask = 			  \
	__vperm (tmp1, tmp2, mask ## _mask);

#define LOAD_VECTORSM(dest, source, mask)				\
    LOAD_VECTORSC (dest, source, mask)					\
    v ## source = pix_multiply (v ## source,				\
                                splat_alpha (v ## mask));

#define STORE_VECTOR(dest)						\
    edges = __vperm (tmp4, tmp3, dest ## _mask);			\
    tmp3 = __vperm (v ## dest, edges, store_mask); \
    tmp1 = __vperm (edges, v ## dest, store_mask); \
    __stvx ( tmp3, dest,15);			\
    __stvx ( tmp1, dest, 0);


static void
vmx128_combine_over_u_no_mask (uint32_t *      dest,
                            const uint32_t *src,
                            int             width)
{
    int i;
	__vector4 vdest, vsrc;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, src_mask, store_mask;

    COMPUTE_SHIFT_MASKS (dest, src);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {

	LOAD_VECTORS (dest, src);

	vdest = over (vsrc, splat_alpha (vsrc), vdest);

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t s = src[i];
	uint32_t d = dest[i];
	uint32_t ia = ALPHA_8 (~s);

	UN8x4_MUL_UN8_ADD_UN8x4 (d, ia, s);

	dest[i] = d;
    }
}

static void
vmx128_combine_over_u_mask (uint32_t *      dest,
                         const uint32_t *src,
                         const uint32_t *mask,
                         int             width)
{
    int i;
	__vector4 vdest, vsrc, vmask;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, src_mask, mask_mask, store_mask;

    COMPUTE_SHIFT_MASKC (dest, src, mask);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORSM (dest, src, mask);

	vdest = over (vsrc, splat_alpha (vsrc), vdest);

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
	mask += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t m = ALPHA_8 (mask[i]);
	uint32_t s = src[i];
	uint32_t d = dest[i];
	uint32_t ia;

	UN8x4_MUL_UN8 (s, m);

	ia = ALPHA_8 (~s);

	UN8x4_MUL_UN8_ADD_UN8x4 (d, ia, s);
	dest[i] = d;
    }
}

static void
vmx128_combine_over_u (pixman_implementation_t *imp,
                    pixman_op_t              op,
                    uint32_t *               dest,
                    const uint32_t *         src,
                    const uint32_t *         mask,
                    int                      width)
{
    if (mask)
	vmx128_combine_over_u_mask (dest, src, mask, width);
    else
	vmx128_combine_over_u_no_mask (dest, src, width);
}

static void
vmx128_combine_over_reverse_u_no_mask (uint32_t *      dest,
                                    const uint32_t *src,
                                    int             width)
{
    int i;
	__vector4 vdest, vsrc;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, src_mask, store_mask;

    COMPUTE_SHIFT_MASKS (dest, src);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {

	LOAD_VECTORS (dest, src);

	vdest = over (vdest, splat_alpha (vdest), vsrc);

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t s = src[i];
	uint32_t d = dest[i];
	uint32_t ia = ALPHA_8 (~dest[i]);

	UN8x4_MUL_UN8_ADD_UN8x4 (s, ia, d);
	dest[i] = s;
    }
}

static void
vmx128_combine_over_reverse_u_mask (uint32_t *      dest,
                                 const uint32_t *src,
                                 const uint32_t *mask,
                                 int             width)
{
    int i;
	__vector4 vdest, vsrc, vmask;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, src_mask, mask_mask, store_mask;

    COMPUTE_SHIFT_MASKC (dest, src, mask);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {

	LOAD_VECTORSM (dest, src, mask);

	vdest = over (vdest, splat_alpha (vdest), vsrc);

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
	mask += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t m = ALPHA_8 (mask[i]);
	uint32_t s = src[i];
	uint32_t d = dest[i];
	uint32_t ia = ALPHA_8 (~dest[i]);

	UN8x4_MUL_UN8 (s, m);

	UN8x4_MUL_UN8_ADD_UN8x4 (s, ia, d);
	dest[i] = s;
    }
}

static void
vmx128_combine_over_reverse_u (pixman_implementation_t *imp,
                            pixman_op_t              op,
                            uint32_t *               dest,
                            const uint32_t *         src,
                            const uint32_t *         mask,
                            int                      width)
{
    if (mask)
	vmx128_combine_over_reverse_u_mask (dest, src, mask, width);
    else
	vmx128_combine_over_reverse_u_no_mask (dest, src, width);
}

static void
vmx128_combine_in_u_no_mask (uint32_t *      dest,
                          const uint32_t *src,
                          int             width)
{
    int i;
	__vector4 vdest, vsrc;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, src_mask, store_mask;

    COMPUTE_SHIFT_MASKS (dest, src);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORS (dest, src);

	vdest = pix_multiply (vsrc, splat_alpha (vdest));

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t s = src[i];
	uint32_t a = ALPHA_8 (dest[i]);

	UN8x4_MUL_UN8 (s, a);
	dest[i] = s;
    }
}

static void
vmx128_combine_in_u_mask (uint32_t *      dest,
                       const uint32_t *src,
                       const uint32_t *mask,
                       int             width)
{
    int i;
	__vector4 vdest, vsrc, vmask;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, src_mask, mask_mask, store_mask;

    COMPUTE_SHIFT_MASKC (dest, src, mask);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORSM (dest, src, mask);

	vdest = pix_multiply (vsrc, splat_alpha (vdest));

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
	mask += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t m = ALPHA_8 (mask[i]);
	uint32_t s = src[i];
	uint32_t a = ALPHA_8 (dest[i]);

	UN8x4_MUL_UN8 (s, m);
	UN8x4_MUL_UN8 (s, a);

	dest[i] = s;
    }
}

static void
vmx128_combine_in_u (pixman_implementation_t *imp,
                  pixman_op_t              op,
                  uint32_t *               dest,
                  const uint32_t *         src,
                  const uint32_t *         mask,
                  int                      width)
{
    if (mask)
	vmx128_combine_in_u_mask (dest, src, mask, width);
    else
	vmx128_combine_in_u_no_mask (dest, src, width);
}

static void
vmx128_combine_in_reverse_u_no_mask (uint32_t *      dest,
                                  const uint32_t *src,
                                  int             width)
{
    int i;
	__vector4 vdest, vsrc;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, src_mask, store_mask;

    COMPUTE_SHIFT_MASKS (dest, src);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORS (dest, src);

	vdest = pix_multiply (vdest, splat_alpha (vsrc));

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t d = dest[i];
	uint32_t a = ALPHA_8 (src[i]);

	UN8x4_MUL_UN8 (d, a);

	dest[i] = d;
    }
}

static void
vmx128_combine_in_reverse_u_mask (uint32_t *      dest,
                               const uint32_t *src,
                               const uint32_t *mask,
                               int             width)
{
    int i;
	__vector4 vdest, vsrc, vmask;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, src_mask, mask_mask, store_mask;

    COMPUTE_SHIFT_MASKC (dest, src, mask);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORSM (dest, src, mask);

	vdest = pix_multiply (vdest, splat_alpha (vsrc));

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
	mask += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t m = ALPHA_8 (mask[i]);
	uint32_t d = dest[i];
	uint32_t a = src[i];

	UN8x4_MUL_UN8 (a, m);
	a = ALPHA_8 (a);
	UN8x4_MUL_UN8 (d, a);

	dest[i] = d;
    }
}

static void
vmx128_combine_in_reverse_u (pixman_implementation_t *imp,
                          pixman_op_t              op,
                          uint32_t *               dest,
                          const uint32_t *         src,
                          const uint32_t *         mask,
                          int                      width)
{
    if (mask)
	vmx128_combine_in_reverse_u_mask (dest, src, mask, width);
    else
	vmx128_combine_in_reverse_u_no_mask (dest, src, width);
}

static void
vmx128_combine_out_u_no_mask (uint32_t *      dest,
                           const uint32_t *src,
                           int             width)
{
    int i;
	__vector4 vdest, vsrc;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, src_mask, store_mask;

    COMPUTE_SHIFT_MASKS (dest, src);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORS (dest, src);

	vdest = pix_multiply (vsrc, splat_alpha (negate (vdest)));

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t s = src[i];
	uint32_t a = ALPHA_8 (~dest[i]);

	UN8x4_MUL_UN8 (s, a);

	dest[i] = s;
    }
}

static void
vmx128_combine_out_u_mask (uint32_t *      dest,
                        const uint32_t *src,
                        const uint32_t *mask,
                        int             width)
{
    int i;
	__vector4 vdest, vsrc, vmask;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, src_mask, mask_mask, store_mask;

    COMPUTE_SHIFT_MASKC (dest, src, mask);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORSM (dest, src, mask);

	vdest = pix_multiply (vsrc, splat_alpha (negate (vdest)));

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
	mask += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t m = ALPHA_8 (mask[i]);
	uint32_t s = src[i];
	uint32_t a = ALPHA_8 (~dest[i]);

	UN8x4_MUL_UN8 (s, m);
	UN8x4_MUL_UN8 (s, a);

	dest[i] = s;
    }
}

static void
vmx128_combine_out_u (pixman_implementation_t *imp,
                   pixman_op_t              op,
                   uint32_t *               dest,
                   const uint32_t *         src,
                   const uint32_t *         mask,
                   int                      width)
{
    if (mask)
	vmx128_combine_out_u_mask (dest, src, mask, width);
    else
	vmx128_combine_out_u_no_mask (dest, src, width);
}

static void
vmx128_combine_out_reverse_u_no_mask (uint32_t *      dest,
                                   const uint32_t *src,
                                   int             width)
{
    int i;
	__vector4 vdest, vsrc;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, src_mask, store_mask;

    COMPUTE_SHIFT_MASKS (dest, src);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {

	LOAD_VECTORS (dest, src);

	vdest = pix_multiply (vdest, splat_alpha (negate (vsrc)));

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t d = dest[i];
	uint32_t a = ALPHA_8 (~src[i]);

	UN8x4_MUL_UN8 (d, a);

	dest[i] = d;
    }
}

static void
vmx128_combine_out_reverse_u_mask (uint32_t *      dest,
                                const uint32_t *src,
                                const uint32_t *mask,
                                int             width)
{
    int i;
	__vector4 vdest, vsrc, vmask;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, src_mask, mask_mask, store_mask;

    COMPUTE_SHIFT_MASKC (dest, src, mask);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORSM (dest, src, mask);

	vdest = pix_multiply (vdest, splat_alpha (negate (vsrc)));

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
	mask += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t m = ALPHA_8 (mask[i]);
	uint32_t d = dest[i];
	uint32_t a = src[i];

	UN8x4_MUL_UN8 (a, m);
	a = ALPHA_8 (~a);
	UN8x4_MUL_UN8 (d, a);

	dest[i] = d;
    }
}

static void
vmx128_combine_out_reverse_u (pixman_implementation_t *imp,
                           pixman_op_t              op,
                           uint32_t *               dest,
                           const uint32_t *         src,
                           const uint32_t *         mask,
                           int                      width)
{
    if (mask)
	vmx128_combine_out_reverse_u_mask (dest, src, mask, width);
    else
	vmx128_combine_out_reverse_u_no_mask (dest, src, width);
}

static void
vmx128_combine_atop_u_no_mask (uint32_t *      dest,
                            const uint32_t *src,
                            int             width)
{
    int i;
	__vector4 vdest, vsrc;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, src_mask, store_mask;

    COMPUTE_SHIFT_MASKS (dest, src);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORS (dest, src);

	vdest = pix_add_mul (vsrc, splat_alpha (vdest),
			     vdest, splat_alpha (negate (vsrc)));

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t s = src[i];
	uint32_t d = dest[i];
	uint32_t dest_a = ALPHA_8 (d);
	uint32_t src_ia = ALPHA_8 (~s);

	UN8x4_MUL_UN8_ADD_UN8x4_MUL_UN8 (s, dest_a, d, src_ia);

	dest[i] = s;
    }
}

static void
vmx128_combine_atop_u_mask (uint32_t *      dest,
                         const uint32_t *src,
                         const uint32_t *mask,
                         int             width)
{
    int i;
	__vector4 vdest, vsrc, vmask;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, src_mask, mask_mask, store_mask;

    COMPUTE_SHIFT_MASKC (dest, src, mask);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORSM (dest, src, mask);

	vdest = pix_add_mul (vsrc, splat_alpha (vdest),
			     vdest, splat_alpha (negate (vsrc)));

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
	mask += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t m = ALPHA_8 (mask[i]);
	uint32_t s = src[i];
	uint32_t d = dest[i];
	uint32_t dest_a = ALPHA_8 (d);
	uint32_t src_ia;

	UN8x4_MUL_UN8 (s, m);

	src_ia = ALPHA_8 (~s);

	UN8x4_MUL_UN8_ADD_UN8x4_MUL_UN8 (s, dest_a, d, src_ia);

	dest[i] = s;
    }
}

static void
vmx128_combine_atop_u (pixman_implementation_t *imp,
                    pixman_op_t              op,
                    uint32_t *               dest,
                    const uint32_t *         src,
                    const uint32_t *         mask,
                    int                      width)
{
    if (mask)
	vmx128_combine_atop_u_mask (dest, src, mask, width);
    else
	vmx128_combine_atop_u_no_mask (dest, src, width);
}

static void
vmx128_combine_atop_reverse_u_no_mask (uint32_t *      dest,
                                    const uint32_t *src,
                                    int             width)
{
    int i;
	__vector4 vdest, vsrc;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, src_mask, store_mask;

    COMPUTE_SHIFT_MASKS (dest, src);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORS (dest, src);

	vdest = pix_add_mul (vdest, splat_alpha (vsrc),
			     vsrc, splat_alpha (negate (vdest)));

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t s = src[i];
	uint32_t d = dest[i];
	uint32_t src_a = ALPHA_8 (s);
	uint32_t dest_ia = ALPHA_8 (~d);

	UN8x4_MUL_UN8_ADD_UN8x4_MUL_UN8 (s, dest_ia, d, src_a);

	dest[i] = s;
    }
}

static void
vmx128_combine_atop_reverse_u_mask (uint32_t *      dest,
                                 const uint32_t *src,
                                 const uint32_t *mask,
                                 int             width)
{
    int i;
	__vector4 vdest, vsrc, vmask;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, src_mask, mask_mask, store_mask;

    COMPUTE_SHIFT_MASKC (dest, src, mask);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORSM (dest, src, mask);

	vdest = pix_add_mul (vdest, splat_alpha (vsrc),
			     vsrc, splat_alpha (negate (vdest)));

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
	mask += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t m = ALPHA_8 (mask[i]);
	uint32_t s = src[i];
	uint32_t d = dest[i];
	uint32_t src_a;
	uint32_t dest_ia = ALPHA_8 (~d);

	UN8x4_MUL_UN8 (s, m);

	src_a = ALPHA_8 (s);

	UN8x4_MUL_UN8_ADD_UN8x4_MUL_UN8 (s, dest_ia, d, src_a);

	dest[i] = s;
    }
}

static void
vmx128_combine_atop_reverse_u (pixman_implementation_t *imp,
                            pixman_op_t              op,
                            uint32_t *               dest,
                            const uint32_t *         src,
                            const uint32_t *         mask,
                            int                      width)
{
    if (mask)
	vmx128_combine_atop_reverse_u_mask (dest, src, mask, width);
    else
	vmx128_combine_atop_reverse_u_no_mask (dest, src, width);
}

static void
vmx128_combine_xor_u_no_mask (uint32_t *      dest,
                           const uint32_t *src,
                           int             width)
{
    int i;
	__vector4 vdest, vsrc;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, src_mask, store_mask;

    COMPUTE_SHIFT_MASKS (dest, src);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORS (dest, src);

	vdest = pix_add_mul (vsrc, splat_alpha (negate (vdest)),
			     vdest, splat_alpha (negate (vsrc)));

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t s = src[i];
	uint32_t d = dest[i];
	uint32_t src_ia = ALPHA_8 (~s);
	uint32_t dest_ia = ALPHA_8 (~d);

	UN8x4_MUL_UN8_ADD_UN8x4_MUL_UN8 (s, dest_ia, d, src_ia);

	dest[i] = s;
    }
}

static void
vmx128_combine_xor_u_mask (uint32_t *      dest,
                        const uint32_t *src,
                        const uint32_t *mask,
                        int             width)
{
    int i;
	__vector4 vdest, vsrc, vmask;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, src_mask, mask_mask, store_mask;

    COMPUTE_SHIFT_MASKC (dest, src, mask);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORSM (dest, src, mask);

	vdest = pix_add_mul (vsrc, splat_alpha (negate (vdest)),
			     vdest, splat_alpha (negate (vsrc)));

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
	mask += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t m = ALPHA_8 (mask[i]);
	uint32_t s = src[i];
	uint32_t d = dest[i];
	uint32_t src_ia;
	uint32_t dest_ia = ALPHA_8 (~d);

	UN8x4_MUL_UN8 (s, m);

	src_ia = ALPHA_8 (~s);

	UN8x4_MUL_UN8_ADD_UN8x4_MUL_UN8 (s, dest_ia, d, src_ia);

	dest[i] = s;
    }
}

static void
vmx128_combine_xor_u (pixman_implementation_t *imp,
                   pixman_op_t              op,
                   uint32_t *               dest,
                   const uint32_t *         src,
                   const uint32_t *         mask,
                   int                      width)
{
    if (mask)
	vmx128_combine_xor_u_mask (dest, src, mask, width);
    else
	vmx128_combine_xor_u_no_mask (dest, src, width);
}

static void
vmx128_combine_add_u_no_mask (uint32_t *      dest,
                           const uint32_t *src,
                           int             width)
{
    int i;
	__vector4 vdest, vsrc;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, src_mask, store_mask;

    COMPUTE_SHIFT_MASKS (dest, src);
    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORS (dest, src);

	vdest = pix_add (vsrc, vdest);

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t s = src[i];
	uint32_t d = dest[i];

	UN8x4_ADD_UN8x4 (d, s);

	dest[i] = d;
    }
}

static void
vmx128_combine_add_u_mask (uint32_t *      dest,
                        const uint32_t *src,
                        const uint32_t *mask,
                        int             width)
{
    int i;
	__vector4 vdest, vsrc, vmask;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, src_mask, mask_mask, store_mask;

    COMPUTE_SHIFT_MASKC (dest, src, mask);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORSM (dest, src, mask);

	vdest = pix_add (vsrc, vdest);

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
	mask += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t m = ALPHA_8 (mask[i]);
	uint32_t s = src[i];
	uint32_t d = dest[i];

	UN8x4_MUL_UN8 (s, m);
	UN8x4_ADD_UN8x4 (d, s);

	dest[i] = d;
    }
}

static void
vmx128_combine_add_u (pixman_implementation_t *imp,
                   pixman_op_t              op,
                   uint32_t *               dest,
                   const uint32_t *         src,
                   const uint32_t *         mask,
                   int                      width)
{
    if (mask)
	vmx128_combine_add_u_mask (dest, src, mask, width);
    else
	vmx128_combine_add_u_no_mask (dest, src, width);
}

static void
vmx128_combine_src_ca (pixman_implementation_t *imp,
                    pixman_op_t              op,
                    uint32_t *               dest,
                    const uint32_t *         src,
                    const uint32_t *         mask,
                    int                      width)
{
    int i;
	__vector4 vdest, vsrc, vmask;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, mask_mask, src_mask, store_mask;

    COMPUTE_SHIFT_MASKC (dest, src, mask);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORSC (dest, src, mask);

	vdest = pix_multiply (vsrc, vmask);

	STORE_VECTOR (dest);

	mask += 4;
	src += 4;
	dest += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t a = mask[i];
	uint32_t s = src[i];

	UN8x4_MUL_UN8x4 (s, a);

	dest[i] = s;
    }
}

static void
vmx128_combine_over_ca (pixman_implementation_t *imp,
                     pixman_op_t              op,
                     uint32_t *               dest,
                     const uint32_t *         src,
                     const uint32_t *         mask,
                     int                      width)
{
    int i;
	__vector4 vdest, vsrc, vmask;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, mask_mask, src_mask, store_mask;

    COMPUTE_SHIFT_MASKC (dest, src, mask);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORSC (dest, src, mask);

	vdest = in_over (vsrc, splat_alpha (vsrc), vmask, vdest);

	STORE_VECTOR (dest);

	mask += 4;
	src += 4;
	dest += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t a = mask[i];
	uint32_t s = src[i];
	uint32_t d = dest[i];
	uint32_t sa = ALPHA_8 (s);

	UN8x4_MUL_UN8x4 (s, a);
	UN8x4_MUL_UN8 (a, sa);
	UN8x4_MUL_UN8x4_ADD_UN8x4 (d, ~a, s);

	dest[i] = d;
    }
}

static void
vmx128_combine_over_reverse_ca (pixman_implementation_t *imp,
                             pixman_op_t              op,
                             uint32_t *               dest,
                             const uint32_t *         src,
                             const uint32_t *         mask,
                             int                      width)
{
    int i;
	__vector4 vdest, vsrc, vmask;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, mask_mask, src_mask, store_mask;

    COMPUTE_SHIFT_MASKC (dest, src, mask);

    /* printf("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORSC (dest, src, mask);

	vdest = over (vdest, splat_alpha (vdest), pix_multiply (vsrc, vmask));

	STORE_VECTOR (dest);

	mask += 4;
	src += 4;
	dest += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t a = mask[i];
	uint32_t s = src[i];
	uint32_t d = dest[i];
	uint32_t ida = ALPHA_8 (~d);

	UN8x4_MUL_UN8x4 (s, a);
	UN8x4_MUL_UN8_ADD_UN8x4 (s, ida, d);

	dest[i] = s;
    }
}

static void
vmx128_combine_in_ca (pixman_implementation_t *imp,
                   pixman_op_t              op,
                   uint32_t *               dest,
                   const uint32_t *         src,
                   const uint32_t *         mask,
                   int                      width)
{
    int i;
	__vector4 vdest, vsrc, vmask;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, mask_mask, src_mask, store_mask;

    COMPUTE_SHIFT_MASKC (dest, src, mask);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORSC (dest, src, mask);

	vdest = pix_multiply (pix_multiply (vsrc, vmask), splat_alpha (vdest));

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
	mask += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t a = mask[i];
	uint32_t s = src[i];
	uint32_t da = ALPHA_8 (dest[i]);

	UN8x4_MUL_UN8x4 (s, a);
	UN8x4_MUL_UN8 (s, da);

	dest[i] = s;
    }
}

static void
vmx128_combine_in_reverse_ca (pixman_implementation_t *imp,
                           pixman_op_t              op,
                           uint32_t *               dest,
                           const uint32_t *         src,
                           const uint32_t *         mask,
                           int                      width)
{
    int i;
	__vector4 vdest, vsrc, vmask;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, mask_mask, src_mask, store_mask;

    COMPUTE_SHIFT_MASKC (dest, src, mask);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {

	LOAD_VECTORSC (dest, src, mask);

	vdest = pix_multiply (vdest, pix_multiply (vmask, splat_alpha (vsrc)));

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
	mask += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t a = mask[i];
	uint32_t d = dest[i];
	uint32_t sa = ALPHA_8 (src[i]);

	UN8x4_MUL_UN8 (a, sa);
	UN8x4_MUL_UN8x4 (d, a);

	dest[i] = d;
    }
}

static void
vmx128_combine_out_ca (pixman_implementation_t *imp,
                    pixman_op_t              op,
                    uint32_t *               dest,
                    const uint32_t *         src,
                    const uint32_t *         mask,
                    int                      width)
{
    int i;
	__vector4 vdest, vsrc, vmask;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, mask_mask, src_mask, store_mask;

    COMPUTE_SHIFT_MASKC (dest, src, mask);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORSC (dest, src, mask);

	vdest = pix_multiply (
	    pix_multiply (vsrc, vmask), splat_alpha (negate (vdest)));

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
	mask += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t a = mask[i];
	uint32_t s = src[i];
	uint32_t d = dest[i];
	uint32_t da = ALPHA_8 (~d);

	UN8x4_MUL_UN8x4 (s, a);
	UN8x4_MUL_UN8 (s, da);

	dest[i] = s;
    }
}

static void
vmx128_combine_out_reverse_ca (pixman_implementation_t *imp,
                            pixman_op_t              op,
                            uint32_t *               dest,
                            const uint32_t *         src,
                            const uint32_t *         mask,
                            int                      width)
{
    int i;
	__vector4 vdest, vsrc, vmask;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, mask_mask, src_mask, store_mask;

    COMPUTE_SHIFT_MASKC (dest, src, mask);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORSC (dest, src, mask);

	vdest = pix_multiply (
	    vdest, negate (pix_multiply (vmask, splat_alpha (vsrc))));

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
	mask += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t a = mask[i];
	uint32_t s = src[i];
	uint32_t d = dest[i];
	uint32_t sa = ALPHA_8 (s);

	UN8x4_MUL_UN8 (a, sa);
	UN8x4_MUL_UN8x4 (d, ~a);

	dest[i] = d;
    }
}

static void
vmx128_combine_atop_ca (pixman_implementation_t *imp,
                     pixman_op_t              op,
                     uint32_t *               dest,
                     const uint32_t *         src,
                     const uint32_t *         mask,
                     int                      width)
{
    int i;
	__vector4 vdest, vsrc, vmask, vsrca;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, mask_mask, src_mask, store_mask;

    COMPUTE_SHIFT_MASKC (dest, src, mask);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORSC (dest, src, mask);

	vsrca = splat_alpha (vsrc);

	vsrc = pix_multiply (vsrc, vmask);
	vmask = pix_multiply (vmask, vsrca);

	vdest = pix_add_mul (vsrc, splat_alpha (vdest),
			     negate (vmask), vdest);

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
	mask += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t a = mask[i];
	uint32_t s = src[i];
	uint32_t d = dest[i];
	uint32_t sa = ALPHA_8 (s);
	uint32_t da = ALPHA_8 (d);

	UN8x4_MUL_UN8x4 (s, a);
	UN8x4_MUL_UN8 (a, sa);
	UN8x4_MUL_UN8x4_ADD_UN8x4_MUL_UN8 (d, ~a, s, da);

	dest[i] = d;
    }
}

static void
vmx128_combine_atop_reverse_ca (pixman_implementation_t *imp,
                             pixman_op_t              op,
                             uint32_t *               dest,
                             const uint32_t *         src,
                             const uint32_t *         mask,
                             int                      width)
{
    int i;
	__vector4 vdest, vsrc, vmask;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, mask_mask, src_mask, store_mask;

    COMPUTE_SHIFT_MASKC (dest, src, mask);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORSC (dest, src, mask);

	vdest = pix_add_mul (vdest,
			     pix_multiply (vmask, splat_alpha (vsrc)),
			     pix_multiply (vsrc, vmask),
			     negate (splat_alpha (vdest)));

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
	mask += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t a = mask[i];
	uint32_t s = src[i];
	uint32_t d = dest[i];
	uint32_t sa = ALPHA_8 (s);
	uint32_t da = ALPHA_8 (~d);

	UN8x4_MUL_UN8x4 (s, a);
	UN8x4_MUL_UN8 (a, sa);
	UN8x4_MUL_UN8x4_ADD_UN8x4_MUL_UN8 (d, a, s, da);

	dest[i] = d;
    }
}

static void
vmx128_combine_xor_ca (pixman_implementation_t *imp,
                    pixman_op_t              op,
                    uint32_t *               dest,
                    const uint32_t *         src,
                    const uint32_t *         mask,
                    int                      width)
{
    int i;
	__vector4 vdest, vsrc, vmask;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, mask_mask, src_mask, store_mask;

    COMPUTE_SHIFT_MASKC (dest, src, mask);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORSC (dest, src, mask);

	vdest = pix_add_mul (vdest,
			     negate (pix_multiply (vmask, splat_alpha (vsrc))),
			     pix_multiply (vsrc, vmask),
			     negate (splat_alpha (vdest)));

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
	mask += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t a = mask[i];
	uint32_t s = src[i];
	uint32_t d = dest[i];
	uint32_t sa = ALPHA_8 (s);
	uint32_t da = ALPHA_8 (~d);

	UN8x4_MUL_UN8x4 (s, a);
	UN8x4_MUL_UN8 (a, sa);
	UN8x4_MUL_UN8x4_ADD_UN8x4_MUL_UN8 (d, ~a, s, da);

	dest[i] = d;
    }
}

static void
vmx128_combine_add_ca (pixman_implementation_t *imp,
                    pixman_op_t              op,
                    uint32_t *               dest,
                    const uint32_t *         src,
                    const uint32_t *         mask,
                    int                      width)
{
    int i;
	__vector4 vdest, vsrc, vmask;
	__vector4 tmp1, tmp2, tmp3, tmp4, edges,
	dest_mask, mask_mask, src_mask, store_mask;

    COMPUTE_SHIFT_MASKC (dest, src, mask);

    /* printf ("%s\n",__PRETTY_FUNCTION__); */
    for (i = width / 4; i > 0; i--)
    {
	LOAD_VECTORSC (dest, src, mask);

	vdest = pix_add (pix_multiply (vsrc, vmask), vdest);

	STORE_VECTOR (dest);

	src += 4;
	dest += 4;
	mask += 4;
    }

    for (i = width % 4; --i >= 0;)
    {
	uint32_t a = mask[i];
	uint32_t s = src[i];
	uint32_t d = dest[i];

	UN8x4_MUL_UN8x4 (s, a);
	UN8x4_ADD_UN8x4 (s, d);

	dest[i] = s;
    }
}

static const pixman_fast_path_t vmx128_fast_paths[] =
{
    {   PIXMAN_OP_NONE	},
};

pixman_implementation_t *
_pixman_implementation_create_vmx128 (pixman_implementation_t *fallback)
{
	pixman_implementation_t *imp = _pixman_implementation_create (fallback, vmx128_fast_paths);

    /* Set up function pointers */

    imp->combine_32[PIXMAN_OP_OVER] = vmx128_combine_over_u;
    imp->combine_32[PIXMAN_OP_OVER_REVERSE] = vmx128_combine_over_reverse_u;
    imp->combine_32[PIXMAN_OP_IN] = vmx128_combine_in_u;
    imp->combine_32[PIXMAN_OP_IN_REVERSE] = vmx128_combine_in_reverse_u;
    imp->combine_32[PIXMAN_OP_OUT] = vmx128_combine_out_u;
    imp->combine_32[PIXMAN_OP_OUT_REVERSE] = vmx128_combine_out_reverse_u;
    imp->combine_32[PIXMAN_OP_ATOP] = vmx128_combine_atop_u;
    imp->combine_32[PIXMAN_OP_ATOP_REVERSE] = vmx128_combine_atop_reverse_u;
    imp->combine_32[PIXMAN_OP_XOR] = vmx128_combine_xor_u;

    imp->combine_32[PIXMAN_OP_ADD] = vmx128_combine_add_u;

    imp->combine_32_ca[PIXMAN_OP_SRC] = vmx128_combine_src_ca;
    imp->combine_32_ca[PIXMAN_OP_OVER] = vmx128_combine_over_ca;
    imp->combine_32_ca[PIXMAN_OP_OVER_REVERSE] = vmx128_combine_over_reverse_ca;
    imp->combine_32_ca[PIXMAN_OP_IN] = vmx128_combine_in_ca;
    imp->combine_32_ca[PIXMAN_OP_IN_REVERSE] = vmx128_combine_in_reverse_ca;
    imp->combine_32_ca[PIXMAN_OP_OUT] = vmx128_combine_out_ca;
    imp->combine_32_ca[PIXMAN_OP_OUT_REVERSE] = vmx128_combine_out_reverse_ca;
    imp->combine_32_ca[PIXMAN_OP_ATOP] = vmx128_combine_atop_ca;
    imp->combine_32_ca[PIXMAN_OP_ATOP_REVERSE] = vmx128_combine_atop_reverse_ca;
    imp->combine_32_ca[PIXMAN_OP_XOR] = vmx128_combine_xor_ca;
    imp->combine_32_ca[PIXMAN_OP_ADD] = vmx128_combine_add_ca;

    return imp;
}
#endif
