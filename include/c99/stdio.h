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

#ifndef __XEOS_LIB_C99_STDIO_H__
#define __XEOS_LIB_C99_STDIO_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <system/types/null.h>
#include <system/types/size_t.h>
#include <system/types/va_list.h>
#include <system/types/fpos_t.h>
#include <system/types/file.h>

#define _IOFBF                      0
#define _IOLBF                      1
#define _IONBF                      2

#define BUFSIZ                      1024
#define EOF                         ( -1 )

#define FOPEN_MAX                   20
#define FILENAME_MAX                1024

#define L_tmpnam                    1024

#include <system/types/seek_set.h>
#include <system/types/seek_cur.h>
#include <system/types/seek_end.h>

#define TMP_MAX                     0xFFFF

#define stderr                      __xeos_lib_c99_stderr_p
#define stdin                       __xeos_lib_c99_stdin_p
#define stdout                      __xeos_lib_c99_stdout_p

extern FILE * __xeos_lib_c99_stderr_p;
extern FILE * __xeos_lib_c99_stdin_p;
extern FILE * __xeos_lib_c99_stdout_p;

int         remove( const char * filename );
int         rename( const char * old, const char * new );
FILE      * tmpfile( void );
char      * tmpnam( char * s );
int         fclose( FILE * stream );
int         fflush( FILE * stream );
FILE      * fopen( const char * restrict filename, const char * restrict mode );
FILE      * freopen( const char * restrict filename, const char * restrict mode, FILE * restrict stream );
void        setbuf( FILE * restrict stream, char * restrict buf );
int         setvbuf( FILE * restrict stream, char * restrict buf, int mode, size_t size );
int         fprintf( FILE * restrict stream, const char * restrict format, ... );
int         fscanf( FILE * restrict stream, const char * restrict format, ... );
int         printf( const char * restrict format, ... );
int         scanf( const char * restrict format, ... );
int         snprintf( char * restrict s, size_t n, const char * restrict format, ... );
int         sprintf( char * restrict s, const char * restrict format, ... );
int         sscanf( const char * restrict s, const char * restrict format, ... );
int         vfprintf( FILE * restrict stream, const char * restrict format, va_list arg );
int         vfscanf( FILE * restrict stream, const char * restrict format, va_list arg );
int         vprintf( const char * restrict format, va_list arg );
int         vscanf( const char * restrict format, va_list arg );
int         vsnprintf( char * restrict s, size_t n, const char * restrict format, va_list arg );
int         vsprintf( char * restrict s, const char * restrict format, va_list arg );
int         vsscanf( const char * restrict s, const char * restrict format, va_list arg );
int         fgetc( FILE * stream );
char      * fgets( char * restrict s, int n, FILE * restrict stream );
int         fputc( int c, FILE * stream );
int         fputs( const char * restrict s, FILE * restrict stream );
int         getc( FILE * stream );
int         getchar( void );
char      * gets( char * s );
int         putc( int c, FILE * stream );
int         putchar( int c );
int         puts( const char * s );
int         ungetc( int c, FILE * stream );
size_t      fread( void * restrict ptr, size_t size, size_t nmemb, FILE * restrict stream );
size_t      fwrite( const void * restrict ptr, size_t size, size_t nmemb, FILE * restrict stream );
int         fgetpos( FILE * restrict stream, fpos_t * restrict pos );
int         fseek( FILE * stream, long int offset, int whence );
int         fsetpos( FILE * stream, const fpos_t * pos );
long int    ftell( FILE * stream );
void        rewind( FILE * stream );
void        clearerr( FILE * stream );
int         feof( FILE * stream );
int         ferror( FILE * stream );
void        perror( const char * s );

#ifdef __cplusplus
}
#endif

#endif /* __XEOS_LIB_C99_STDIO_H__ */
