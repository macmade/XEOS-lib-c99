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

#ifndef __LIBC_TIME_H__
#define __LIBC_TIME_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <system/types/null.h>
#include <system/types/size_t.h>
#include <system/types/clock_t.h>
#include <system/types/time_t.h>
#include <system/types/struct_tm.h>

#define CLOCKS_PER_SEC 1000000

char      * asctime( const struct tm * timeptr );
clock_t     clock( void );
char      * ctime( const time_t * timer );
double      difftime( time_t time1, time_t time0 );
struct tm * gmtime( const time_t * timer );
struct tm * localtime( const time_t * timer );
time_t      mktime( struct tm * timeptr );
size_t      strftime( char * restrict s, size_t maxsize, const char * restrict format, const struct tm * restrict timeptr );
time_t      time( time_t * timer );

#ifdef __cplusplus
}
#endif

#endif /* __LIBC_TIME_H__ */

/*******************************************************************************
 # POSIX definitions
 ******************************************************************************/

#ifdef _POSIX_C_SOURCE

#ifndef __LIBC_TIME_POSIX_H__
#define __LIBC_TIME_POSIX_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <signal.h>
#include <system/types/pid_t.h>
#include <system/types/clockid_t.h>
#include <system/types/timer_t.h>
#include <system/types/struct_timespec.h>
#include <system/types/struct_itimerspec.h>

struct sigevent;

#define TIMER_ABSTIME               0
#define CLOCK_REALTIME              0
#define CLOCK_MONOTONIC             0
#define CLOCK_PROCESS_CPUTIME_ID    0
#define CLOCK_THREAD_CPUTIME_ID     0

extern int          getdate_err;
extern int          daylight;
extern long int     timezone;
extern char       * tzname[];

char      * asctime_r( const struct tm * restrict timeptr, char * restrict buf );
int         clock_getres( clockid_t clock_id, struct timespec * res );
int         clock_gettime( clockid_t clock_id, struct timespec * tp );
int         clock_settime( clockid_t clock_id, const struct timespec * tp );
char      * ctime_r( const time_t *, char * buf );
struct tm * getdate( const char * str );
struct tm * gmtime_r( const time_t * restrict timer, struct tm * restrict result );
struct tm * localtime_r( const time_t * restrict timer, struct tm * restrict result );
int         nanosleep( const struct timespec * rqtp, struct timespec * rmtp );
char      * strptime( const char * restrict buf, const char * restrict format, struct tm * restrict tm );
int         timer_create( clockid_t clockid, struct sigevent * restrict evp, timer_t * restrict timerid );
int         timer_delete( timer_t timerid );
int         timer_getoverrun( timer_t timerid );
int         timer_gettime( timer_t timerid, struct itimerspec * value );
int         timer_settime( timer_t timerid, int flags, const struct itimerspec * restrict value, struct itimerspec * restrict ovalue );
void        tzset( void );

#ifdef __cplusplus
}
#endif

#endif /* __LIBC_TIME_POSIX_H__ */

#endif /* _POSIX_C_SOURCE */
