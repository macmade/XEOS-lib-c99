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

#ifndef __LIBC_FLOAT_H__
#define __LIBC_FLOAT_H__
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <system/types/flt_eval_method.h>

#define FLT_ROUNDS          1

#define FLT_RADIX           2

#define DECIMAL_DIG         10

#define FLT_MANT_DIG        24
#define DBL_MANT_DIG        53
#define LDBL_MANT_DIG       DBL_MANT_DIG

#define FLT_DIG             6
#define DBL_DIG             15
#define LDBL_DIG            DBL_DIG

#define FLT_MIN_EXP         ( -125 )
#define DBL_MIN_EXP         ( -1021 )
#define LDBL_MIN_EXP        DBL_MIN_EXP

#define FLT_MIN_10_EXP      ( -37 )
#define DBL_MIN_10_EXP      ( -307 )
#define LDBL_MIN_10_EXP     DBL_MIN_10_EXP

#define FLT_MAX_EXP         128
#define DBL_MAX_EXP         1024
#define LDBL_MAX_EXP        DBL_MAX_EXP

#define FLT_MAX_10_EXP      38
#define DBL_MAX_10_EXP      308
#define LDBL_MAX_10_EXP     DBL_MAX_10_EXP

#define FLT_MAX             3.40282347e+38F
#define DBL_MAX             1.7976931348623157e+308
#define LDBL_MAX            DBL_MAX

#define FLT_EPSILON         1.1920929e-07F
#define DBL_EPSILON         2.2204460492503131e-16
#define LDBL_EPSILON        DBL_EPSILON

#define FLT_MIN             1.17549435e-38F
#define DBL_MIN             2.2250738585072014e-308
#define LDBL_MIN            DBL_MIN

#ifdef __cplusplus
}
#endif

#endif /* __LIBC_FLOAT_H__ */
