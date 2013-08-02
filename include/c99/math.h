/*******************************************************************************
 * XEOS - X86 Experimental Operating System
 * 
 * Copyright (c) 2010-2013, Jean-David Gadina - www.xs-labs.com
 * All rights reserved.
 * 
 * XEOS Software License - Version 1.0 - December 21, 2012
 * 
 * Permission is hereby granted, free of charge, to any person or organisation
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to deal in the Software, with or without
 * modification, without restriction, including without limitation the rights
 * to use, execute, display, copy, reproduce, transmit, publish, distribute,
 * modify, merge, prepare derivative works of the Software, and to permit
 * third-parties to whom the Software is furnished to do so, all subject to the
 * following conditions:
 * 
 *      1.  Redistributions of source code, in whole or in part, must retain the
 *          above copyright notice and this entire statement, including the
 *          above license grant, this restriction and the following disclaimer.
 * 
 *      2.  Redistributions in binary form must reproduce the above copyright
 *          notice and this entire statement, including the above license grant,
 *          this restriction and the following disclaimer in the documentation
 *          and/or other materials provided with the distribution, unless the
 *          Software is distributed by the copyright owner as a library.
 *          A "library" means a collection of software functions and/or data
 *          prepared so as to be conveniently linked with application programs
 *          (which use some of those functions and data) to form executables.
 * 
 *      3.  The Software, or any substancial portion of the Software shall not
 *          be combined, included, derived, or linked (statically or
 *          dynamically) with software or libraries licensed under the terms
 *          of any GNU software license, including, but not limited to, the GNU
 *          General Public License (GNU/GPL) or the GNU Lesser General Public
 *          License (GNU/LGPL).
 * 
 *      4.  All advertising materials mentioning features or use of this
 *          software must display an acknowledgement stating that the product
 *          includes software developed by the copyright owner.
 * 
 *      5.  Neither the name of the copyright owner nor the names of its
 *          contributors may be used to endorse or promote products derived from
 *          this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT OWNER AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE, TITLE AND NON-INFRINGEMENT ARE DISCLAIMED.
 * 
 * IN NO EVENT SHALL THE COPYRIGHT OWNER, CONTRIBUTORS OR ANYONE DISTRIBUTING
 * THE SOFTWARE BE LIABLE FOR ANY CLAIM, DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN ACTION OF CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF OR IN CONNECTION WITH
 * THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

/* $Id$ */

#ifndef __XEOS_LIB_C99_MATH_H__
#define __XEOS_LIB_C99_MATH_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <system/types/flt_eval_method.h>
#include <system/types/float_t.h>
#include <system/types/double_t.h>

#define HUGE_VAL                1e500
#define HUGE_VALF               1e50f
#define HUGE_VALL               1e5000L
#define INFINITY                HUGE_VALF
#define FP_INFINITE             1
#define FP_NAN                  2
#define FP_NORMAL               3
#define FP_SUBNORMAL            4
#define FP_ZERO                 5
#define FP_ILOGB0               ( -2147483647 - 1 )
#define FP_ILOGBNAN             ( -2147483647 - 1 )
#define MATH_ERRNO              1
#define MATH_ERREXCEPT          2
#define math_errhandling        ( __xeos_lib_c99_math_errhandling() )

extern int __xeos_lib_c99_math_errhandling( void );

#define NAN                     ( nanf() )
#undef  FP_FAST_FMA
#undef  FP_FAST_FMAF
#undef  FP_FAST_FMAL

#define fpclassify( _x_ )                                                                   \
    (                                                                                       \
        ( sizeof( _x_ ) == sizeof( float  ) ) ? __xeos_lib_c99_math_fpclassify_f( _x_ ) :   \
        ( sizeof( _x_ ) == sizeof( double ) ) ? __xeos_lib_c99_math_fpclassify_d( _x_ ) :   \
                                                __xeos_lib_c99_math_fpclassify_l( _x_ )     \
    )

extern int __xeos_lib_c99_math_fpclassify_f( float x );
extern int __xeos_lib_c99_math_fpclassify_d( double x );
extern int __xeos_lib_c99_math_fpclassify_l( long double x );

#define isfinite( _x_ )                                                                     \
    (                                                                                       \
        ( sizeof( _x_ ) == sizeof( float  ) ) ? __xeos_lib_c99_math_isfinite_f( _x_ ) :     \
        ( sizeof( _x_ ) == sizeof( double ) ) ? __xeos_lib_c99_math_isfinite_d( _x_ ) :     \
                                                __xeos_lib_c99_math_isfinite_l( _x_ )       \
    )

extern int __xeos_lib_c99_math_isfinite_f( float x );
extern int __xeos_lib_c99_math_isfinite_d( double x );
extern int __xeos_lib_c99_math_isfinite_l( long double x );

#define isinf( _x_ )                                                                        \
    (                                                                                       \
        ( sizeof( _x_ ) == sizeof( float  ) ) ? __xeos_lib_c99_math_isinf_f( _x_ ) :        \
        ( sizeof( _x_ ) == sizeof( double ) ) ? __xeos_lib_c99_math_isinf_d( _x_ ) :        \
                                                __xeos_lib_c99_math_isinf_l( _x_ )          \
    )

extern int __xeos_lib_c99_math_isinf_f( float x );
extern int __xeos_lib_c99_math_isinf_d( double x );
extern int __xeos_lib_c99_math_isinf_l( long double x );

#define isnan( _x_ )                                                                        \
    (                                                                                       \
        ( sizeof( _x_ ) == sizeof( float  ) ) ? __xeos_lib_c99_math_isnan_f( _x_ ) :        \
        ( sizeof( _x_ ) == sizeof( double ) ) ? __xeos_lib_c99_math_isnan_d( _x_ ) :        \
                                                __xeos_lib_c99_math_isnan_l( _x_ )          \
    )

extern int __xeos_lib_c99_math_isnan_f( float x );
extern int __xeos_lib_c99_math_isnan_d( double x );
extern int __xeos_lib_c99_math_isnan_l( long double x );

#define isnormal( _x_ )                                                                     \
    (                                                                                       \
        ( sizeof( _x_ ) == sizeof( float  ) ) ? __xeos_lib_c99_math_isnormal_f( _x_ ) :     \
        ( sizeof( _x_ ) == sizeof( double ) ) ? __xeos_lib_c99_math_isnormal_d( _x_ ) :     \
                                                __xeos_lib_c99_math_isnormal_l( _x_ )       \
    )

extern int __xeos_lib_c99_math_isnormal_f( float x );
extern int __xeos_lib_c99_math_isnormal_d( double x );
extern int __xeos_lib_c99_math_isnormal_l( long double x );

#define signbit( _x_ )                                                                      \
    (                                                                                       \
        ( sizeof( _x_ ) == sizeof( float  ) ) ? __xeos_lib_c99_math_signbit_f( _x_ ) :      \
        ( sizeof( _x_ ) == sizeof( double ) ) ? __xeos_lib_c99_math_signbit_d( _x_ ) :      \
                                                __xeos_lib_c99_math_signbit_l( _x_ )        \
    )

extern int __xeos_lib_c99_math_signbit_f( float x );
extern int __xeos_lib_c99_math_signbit_d( double x );
extern int __xeos_lib_c99_math_signbit_l( long double x );

#define isgreater( _x_, _y_ )       __xeos_lib_c99_math_isgreater( ( long double )( _x_ ), ( long double )( _y_ ) )
#define isless( _x_, _y_ )          __xeos_lib_c99_math_isless( ( long double )( _x_ ), ( long double )( _y_ ) )
#define islessequal( _x_, _y_ )     __xeos_lib_c99_math_islessequal( ( long double )( _x_ ), ( long double )( _y_ ) )
#define islessgreater( _x_, _y_ )   __xeos_lib_c99_math_islessgreater( ( long double )( _x_ ), ( long double )( _y_ ) )
#define isunordered( _x_, _y_ )     __xeos_lib_c99_math_isunordered( ( long double )( _x_ ), ( long double )( _y_ ) )

extern int __xeos_lib_c99_math_isgreater( long double x, long double y );
extern int __xeos_lib_c99_math_isless( long double x, long double y );
extern int __xeos_lib_c99_math_islessequal( long double x, long double y );
extern int __xeos_lib_c99_math_islessgreater( long double x, long double y );
extern int __xeos_lib_c99_math_isunordered( long double x, long double y );

double          acos( double x );
float           acosf( float x );
long double     acosl( long double x );

double          asin( double x );
float           asinf( float x );
long double     asinl( long double x );

double          atan( double x );
float           atanf( float x );
long double     atanl( long double x );

double          atan2( double y, double x );
float           atan2f( float y, float x );
long double     atan2l( long double y, long double x );

double          cos( double x );
float           cosf( float x );
long double     cosl( long double x );

double          sin( double x );
float           sinf( float x );
long double     sinl( long double x );

double          tan( double x );
float           tanf( float x );
long double     tanl( long double x );

double          acosh( double x );
float           acoshf( float x );
long double     acoshl( long double x );

double          asinh( double x );
float           asinhf( float x );
long double     asinhl( long double x );

double          atanh( double x );
float           atanhf( float x );
long double     atanhl( long double x );

double          cosh( double x );
float           coshf( float x );
long double     coshl( long double x );

double          sinh( double x );
float           sinhf( float x );
long double     sinhl( long double x );

double          tanh( double x );
float           tanhf( float x );
long double     tanhl( long double x );

double          exp( double x );
float           expf( float x );
long double     expl( long double x );

double          exp2( double x );
float           exp2f( float x );
long double     exp2l( long double x );

double          expm1( double x );
float           expm1f( float x );
long double     expm1l( long double x );

double          frexp( double value, int * exp );
float           frexpf( float value, int * exp );
long double     frexpl( long double value, int * exp );

int             ilogb( double x );
int             ilogbf( float x );
int             ilogbl( long double x );

double          ldexp( double x, int exp );
float           ldexpf( float x, int exp );
long double     ldexpl( long double x, int exp );

double          log( double x );
float           logf( float x );
long double     logl( long double x );

double          log10( double x );
float           log10f( float x );
long double     log10l( long double x );

double          log1p( double x );
float           log1pf( float x );
long double     log1pl( long double x );

double          log2( double x );
float           log2f( float x );
long double     log2l( long double x );

double          logb( double x );
float           logbf( float x );
long double     logbl( long double x );

double          modf( double value, double * iptr );
float           modff( float value, float * iptr );
long double     modfl( long double value, long double * iptr );

double          scalbn( double x, int n );
float           scalbnf( float x, int n );
long double     scalbnl( long double x, int n );

double          scalbln( double x, long int n );
float           scalblnf( float x, long int n );
long double     scalblnl( long double x, long int n );

double          cbrt( double x );
float           cbrtf( float x );
long double     cbrtl( long double x );

double          fabs( double x );
float           fabsf( float x );
long double     fabsl( long double x );

double          hypot( double x, double y );
float           hypotf( float x, float y );
long double     hypotl( long double x, long double y );

double          pow( double x, double y );
float           powf( float x, float y );
long double     powl( long double x, long double y );

double          sqrt( double x );
float           sqrtf( float x );
long double     sqrtl( long double x );

double          erf( double x );
float           erff( float x );
long double     erfl( long double x );

double          erfc( double x );
float           erfcf( float x );
long double     erfcl( long double x );

double          lgamma( double x );
float           lgammaf( float x );
long double     lgammal( long double x );

double          tgamma( double x );
float           tgammaf( float x );
long double     tgammal( long double x );

double          ceil( double x );
float           ceilf( float x );
long double     ceill( long double x );

double          floor( double x );
float           floorf( float x );
long double     floorl( long double x );

double          nearbyint( double x );
float           nearbyintf( float x );
long double     nearbyintl( long double x );

double          rint( double x );
float           rintf( float x );
long double     rintl( long double x );

long int        lrint( double x );
long int        lrintf( float x );
long int        lrintl( long double x );

long long int   llrint( double x );
long long int   llrintf( float x );
long long int   llrintl( long double x );

double          round( double x );
float           roundf( float x );
long double     roundl( long double x );

long int        lround( double x );
long int        lroundf( float x );
long int        lroundl( long double x );

long long int   llround( double x );
long long int   llroundf( float x );
long long int   llroundl( long double x );

double          trunc( double x );
float           truncf( float x );
long double     truncl( long double x );

double          fmod( double x, double y );
float           fmodf( float x, float y );
long double     fmodl( long double x, long double y );

double          remainder( double x, double y );
float           remainderf( float x, float y );
long double     remainderl( long double x, long double y );

double          remquo( double x, double y, int * quo );
float           remquof( float x, float y, int * quo );
long double     remquol( long double x, long double y, int * quo );

double          copysign( double x, double y );
float           copysignf( float x, float y );
long double     copysignl( long double x, long double y );

double          nan( const char * tagp );
float           nanf( const char * tagp );
long double     nanl( const char * tagp );

double          nextafter( double x, double y );
float           nextafterf( float x, float y );
long double     nextafterl( long double x, long double y );

double          nexttoward( double x, long double y );
float           nexttowardf( float x, long double y );
long double     nexttowardl( long double x, long double y );

double          fdim( double x, double y );
float           fdimf( float x, float y );
long double     fdiml( long double x, long double y );

double          fmax( double x, double y );
float           fmaxf( float x, float y );
long double     fmaxl( long double x, long double y );

double          fmin( double x, double y );
float           fminf( float x, float y );
long double     fminl( long double x, long double y );

double          fma( double x, double y, double z );
float           fmaf( float x, float y, float z );
long double     fmal( long double x, long double y, long double z );

#ifdef __cplusplus
}
#endif

#endif /* __XEOS_LIB_C99_MATH_H__ */
