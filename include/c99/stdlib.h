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

#ifndef __LIBC_STDLIB_H__
#define __LIBC_STDLIB_H__
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <system/types/null.h>
#include <system/types/size_t.h>
#include <system/types/wchar_t.h>
#include <system/types/div_t.h>
#include <system/types/ldiv_t.h>
#include <system/types/lldiv_t.h>

#define EXIT_FAILURE            1
#define EXIT_SUCCESS            0

#define RAND_MAX                0x7FFFFFFF
#define	MB_CUR_MAX              __LIBC_MB_CUR_MAX

extern int __LIBC_MB_CUR_MAX;

double                  atof( const char * nptr );
int                     atoi( const char * nptr );
long int                atol( const char * nptr );
long long int           atoll( const char * nptr );
double                  strtod( const char * restrict nptr, char ** restrict endptr );
float                   strtof( const char * restrict nptr, char ** restrict endptr );
long double             strtold( const char * restrict nptr, char ** restrict endptr );
long int                strtol( const char * restrict nptr, char ** restrict endptr, int base );
long long int           strtoll( const char * restrict nptr, char ** restrict endptr, int base );
unsigned long int       strtoul( const char * restrict nptr, char ** restrict endptr, int base );
unsigned long long int  strtoull( const char * restrict nptr, char ** restrict endptr, int base );
int                     rand( void );
void                    srand( unsigned int seed );
void                  * calloc( size_t nmemb, size_t size );
void                    free( void * ptr );
void                  * malloc( size_t size );
void                  * realloc( void * ptr, size_t size );
void                    abort( void );
int                     atexit( void ( * func )( void ) );
void                    exit( int status );
void                    _Exit( int status );
char                  * getenv( const char * name );
int                     system( const char * string );
void                  * bsearch( const void * key, const void * base, size_t nmemb, size_t size, int ( * compar )( const void *, const void * ) );
void                    qsort( void * base, size_t nmemb, size_t size, int ( * compar )( const void *, const void * ) );
int                     abs( int j );
long int                labs( long int j );
long long int           llabs( long long int j );
div_t                   div( int numer, int denom );
ldiv_t                  ldiv( long int numer, long int denom );
lldiv_t                 lldiv( long long int numer, long long int denom );
int                     mblen( const char * s, size_t n );
int                     mbtowc( wchar_t * restrict pwc, const char * restrict s, size_t n );
int                     wctomb( char * s, wchar_t wc );
size_t                  mbstowcs( wchar_t * restrict pwcs, const char * restrict s, size_t n );
size_t                  wcstombs( char * restrict s, const wchar_t * restrict pwcs, size_t n );

#ifdef __cplusplus
}
#endif

#endif /* __LIBC_STDLIB_H__ */
