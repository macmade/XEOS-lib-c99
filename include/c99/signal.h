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

#ifndef __LIBC_SIGNAL_H__
#define __LIBC_SIGNAL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <system/types/sig_atomic_t.h>

#define SIG_DFL         ( ( void ( * )( int ) )0 )
#define SIG_ERR         ( ( void ( * )( int ) )-1 )
#define SIG_IGN         ( ( void ( * )( int ) )1 )

#define SIGINT          1
#define SIGILL          4
#define SIGABRT         6
#define SIGFPE          8
#define SIGSEGV         11
#define SIGTERM         15

void ( * signal( int sig, void ( * func )( int ) ) )( int );

int raise( int sig );

/*******************************************************************************
 # POSIX definitions
 ******************************************************************************/

#ifdef _POSIX_C_SOURCE

#include <time.h>
#include <system/types/pthread_t.h>
#include <system/types/pthread_attr_t.h>
#include <system/types/size_t.h>
#include <system/types/uid_t.h>
#include <system/types/pid_t.h>
#include <system/types/struct_timespec.h>
#include <system/types/sigset_t.h>
#include <system/types/struct_sigevent.h>
#include <system/types/struct_sigaction.h>
#include <system/types/union_sigval.h>
#include <system/types/mcontext_t.h>
#include <system/types/ucontext_t.h>
#include <system/types/stack_t.h>
#include <system/types/siginfo_t.h>

#define SIG_HOLD        ( ( void ( * )( int ) )5 )

#define SIGEV_NONE      0
#define SIGEV_SIGNAL    1
#define SIGEV_THREAD    2

#define SIGRTMIN        0
#define SIGRTMAX        0

#define SIGHUP          1
#define SIGQUIT         3
#define SIGTRAP         5
#define SIGPOLL         7
#define SIGKILL         9
#define SIGBUS          10
#define SIGSYS          12
#define SIGPIPE         13
#define SIGALRM         14
#define SIGURG          16
#define SIGSTOP         17
#define SIGTSTP         18
#define SIGCONT         19
#define SIGCHLD         20
#define SIGTTIN         21
#define SIGTTOU         22
#define SIGXFSZ         25
#define SIGXCPU         24
#define SIGVTALRM       26
#define SIGPROF         27
#define SIGUSR1         30
#define SIGUSR2         31

#define SIG_BLOCK       0
#define SIG_UNBLOCK     0
#define SIG_SETMASK     0
#define SA_NOCLDSTOP    0
#define SA_ONSTACK      0
#define SA_RESETHAND    0
#define SA_RESTART      0
#define SA_SIGINFO      0
#define SA_NOCLDWAIT    0
#define SA_NODEFER      0
#define SS_ONSTACK      0
#define SS_DISABLE      0
#define MINSIGSTKSZ     0
#define SIGSTKSZ        0

#define ILL_ILLOPC      0
#define ILL_ILLOPN      0
#define ILL_ILLADR      0
#define ILL_ILLTRP      0
#define ILL_PRVOPC      0
#define ILL_PRVREG      0
#define ILL_COPROC      0
#define ILL_BADSTK      0

#define FPE_INTDIV      0
#define FPE_INTOVF      0
#define FPE_FLTDIV      0
#define FPE_FLTOVF      0
#define FPE_FLTUND      0
#define FPE_FLTRES      0
#define FPE_FLTINV      0
#define FPE_FLTSUB      0

#define SEGV_MAPERR     0
#define SEGV_ACCERR     0

#define BUS_ADRALN      0
#define BUS_ADRERR      0
#define BUS_OBJERR      0

#define TRAP_BRKPT      0
#define TRAP_TRACE      0

#define CLD_EXITED      0
#define CLD_KILLED      0
#define CLD_DUMPED      0
#define CLD_TRAPPED     0
#define CLD_STOPPED     0
#define CLD_CONTINUED   0

#define POLL_IN         0
#define POLL_OUT        0
#define POLL_MSG        0
#define POLL_ERR        0
#define POLL_PRI        0
#define POLL_HUP        0

#define SI_USER         0
#define SI_QUEUE        0
#define SI_TIMER        0
#define SI_ASYNCIO      0
#define SI_MESGQ        0

int     kill( pid_t, int );
int     killpg( pid_t, int );
void    psiginfo( const siginfo_t *, const char * );
void    psignal( int, const char * );
int     pthread_kill( pthread_t, int );
int     pthread_sigmask( int, const sigset_t * restrict, sigset_t * restrict );
int     sigaction( int, const struct sigaction * restrict, struct sigaction * restrict );
int     sigaddset( sigset_t *, int);
int     sigaltstack( const stack_t * restrict, stack_t * restrict );
int     sigdelset( sigset_t *, int );
int     sigemptyset( sigset_t * );
int     sigfillset( sigset_t * );
int     sighold( int );
int     sigignore( int );
int     siginterrupt( int, int );
int     sigismember( const sigset_t *, int );
int     sigpause( int );
int     sigpending( sigset_t * );
int     sigprocmask( int, const sigset_t * restrict, sigset_t * restrict );
int     sigqueue( pid_t, int, const union sigval );
int     sigrelse( int );
void    ( * sigset( int, void ( * )( int ) ) )( int );
int     sigsuspend( const sigset_t * );
int     sigtimedwait( const sigset_t * restrict, siginfo_t * restrict, const struct timespec * restrict );
int     sigwait( const sigset_t * restrict, int * restrict );
int     sigwaitinfo( const sigset_t * restrict, siginfo_t * restrict );

#endif /* _POSIX_C_SOURCE */

#ifdef __cplusplus
}
#endif

#endif /* __LIBC_SIGNAL_H__ */
