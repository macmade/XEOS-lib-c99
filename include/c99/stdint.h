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

#ifndef __LIBC_STDINT_H__
#define __LIBC_STDINT_H__
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <system/types/int8_t.h>
#include <system/types/int16_t.h>
#include <system/types/int32_t.h>
#include <system/types/int64_t.h>

#include <system/types/uint8_t.h>
#include <system/types/uint16_t.h>
#include <system/types/uint32_t.h>
#include <system/types/uint64_t.h>

#include <system/types/int_least8_t.h>
#include <system/types/int_least16_t.h>
#include <system/types/int_least32_t.h>
#include <system/types/int_least64_t.h>

#include <system/types/uint_least8_t.h>
#include <system/types/uint_least16_t.h>
#include <system/types/uint_least32_t.h>
#include <system/types/uint_least64_t.h>

#include <system/types/int_fast8_t.h>
#include <system/types/int_fast16_t.h>
#include <system/types/int_fast32_t.h>
#include <system/types/int_fast64_t.h>

#include <system/types/uint_fast8_t.h>
#include <system/types/uint_fast16_t.h>
#include <system/types/uint_fast32_t.h>
#include <system/types/uint_fast64_t.h>

#include <system/types/intptr_t.h>
#include <system/types/uintptr_t.h>

#include <system/types/intmax_t.h>
#include <system/types/uintmax_t.h>

#define INT8_MAX                0x7F
#define INT16_MAX               0x7FFF
#define INT32_MAX               0x7FFFFFFF
#define INT64_MAX               0x7FFFFFFFFFFFFFFFLL

#define INT8_MIN                -0x80
#define INT16_MIN               -0x8000
#define INT32_MIN               ( -INT32_MAX - 1 )
#define INT64_MIN               ( -INT64_MAX - 1 )

#define UINT8_MAX               0xFF
#define UINT16_MAX              0xFFFF
#define UINT32_MAX              0xFFFFFFFFU
#define UINT64_MAX              0xFFFFFFFFFFFFFFFFULL

#define INT_LEAST8_MIN          INT8_MIN
#define INT_LEAST16_MIN         INT16_MIN
#define INT_LEAST32_MIN         INT32_MIN
#define INT_LEAST64_MIN         INT64_MIN

#define INT_LEAST8_MAX          INT8_MAX
#define INT_LEAST16_MAX         INT16_MAX
#define INT_LEAST32_MAX         INT32_MAX
#define INT_LEAST64_MAX         INT64_MAX

#define UINT_LEAST8_MAX         UINT8_MAX
#define UINT_LEAST16_MAX        UINT16_MAX
#define UINT_LEAST32_MAX        UINT32_MAX
#define UINT_LEAST64_MAX        UINT64_MAX

#define INT_FAST8_MIN           INT8_MIN
#define INT_FAST16_MIN          INT16_MIN
#define INT_FAST32_MIN          INT32_MIN
#define INT_FAST64_MIN          INT64_MIN

#define INT_FAST8_MAX           INT8_MAX
#define INT_FAST16_MAX          INT16_MAX
#define INT_FAST32_MAX          INT32_MAX
#define INT_FAST64_MAX          INT64_MAX

#define UINT_FAST8_MAX          UINT8_MAX
#define UINT_FAST16_MAX         UINT16_MAX
#define UINT_FAST32_MAX         UINT32_MAX
#define UINT_FAST64_MAX         UINT64_MAX

#define INTMAX_MIN              INT64_MIN
#define INTMAX_MAX              INT64_MAX
#define UINTMAX_MAX             UINT64_MAX

#ifdef __LP64__
    
    #define INTPTR_MIN          INT64_MIN
    #define INTPTR_MAX          INT64_MAX
    #define UINTPTR_MAX         UINT64_MAX
    
    #define SIZE_MAX            UINT64_MAX
    
    #define PTRDIFF_MIN         INT64_MIN
    #define PTRDIFF_MAX         INT64_MAX
    
#else
    
    #define INTPTR_MIN          INT32_MIN
    #define INTPTR_MAX          INT32_MAX
    #define UINTPTR_MAX         UINT32_MAX
    
    #define SIZE_MAX            UINT32_MAX
    
    #define PTRDIFF_MIN         INT32_MIN
    #define PTRDIFF_MAX         INT32_MAX
    
#endif

#ifdef __WCHAR_MAX__
    
    #define WCHAR_MAX           __WCHAR_MAX__
    
#else

    #define WCHAR_MAX           0x7FFFFFFF
    
#endif

#if WCHAR_MAX == 0xFFFF
    
    #define WCHAR_MIN           0
    
#else
    
    #define WCHAR_MIN           ( -WCHAR_MAX - 1 )
    
#endif

#define WINT_MIN                INT32_MIN
#define WINT_MAX                INT32_MAX

#define SIG_ATOMIC_MIN          INT32_MIN
#define SIG_ATOMIC_MAX          INT32_MAX

#define INT8_C( _v_ )           ( _v_ )
#define INT16_C( _v_ )          ( _v_ )
#define INT32_C( _v_ )          ( _v_ )
#define INT64_C( _v_ )          ( _v_  ## LL )

#define UINT8_C( _v_ )          ( _v_  ## U )
#define UINT16_C( _v_ )         ( _v_  ## U )
#define UINT32_C( _v_ )         ( _v_  ## U )
#define UINT64_C( _v_ )         ( _v_  ## ULL )

#define INTMAX_C( _v_ )         ( _v_  ## LL )
#define UINTMAX_C( _v_ )        ( _v_  ## ULL )

#ifdef __cplusplus
}
#endif

#endif /* __LIBC_STDINT_H__ */
