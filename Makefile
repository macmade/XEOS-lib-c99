#-------------------------------------------------------------------------------
# Copyright (c) 2010-2013, Jean-David Gadina - www.xs-labs.com
# All rights reserved.
# 
# XEOS Software License - Version 1.0 - December 21, 2012
# 
# Permission is hereby granted, free of charge, to any person or organisation
# obtaining a copy of the software and accompanying documentation covered by
# this license (the "Software") to deal in the Software, with or without
# modification, without restriction, including without limitation the rights
# to use, execute, display, copy, reproduce, transmit, publish, distribute,
# modify, merge, prepare derivative works of the Software, and to permit
# third-parties to whom the Software is furnished to do so, all subject to the
# following conditions:
# 
#       1.  Redistributions of source code, in whole or in part, must retain the
#           above copyright notice and this entire statement, including the
#           above license grant, this restriction and the following disclaimer.
# 
#       2.  Redistributions in binary form must reproduce the above copyright
#           notice and this entire statement, including the above license grant,
#           this restriction and the following disclaimer in the documentation
#           and/or other materials provided with the distribution, unless the
#           Software is distributed by the copyright owner as a library.
#           A "library" means a collection of software functions and/or data
#           prepared so as to be conveniently linked with application programs
#           (which use some of those functions and data) to form executables.
# 
#       3.  The Software, or any substancial portion of the Software shall not
#           be combined, included, derived, or linked (statically or
#           dynamically) with software or libraries licensed under the terms
#           of any GNU software license, including, but not limited to, the GNU
#           General Public License (GNU/GPL) or the GNU Lesser General Public
#           License (GNU/LGPL).
# 
#       4.  All advertising materials mentioning features or use of this
#           software must display an acknowledgement stating that the product
#           includes software developed by the copyright owner.
# 
#       5.  Neither the name of the copyright owner nor the names of its
#           contributors may be used to endorse or promote products derived from
#           this software without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT OWNER AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
# THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE, TITLE AND NON-INFRINGEMENT ARE DISCLAIMED.
# 
# IN NO EVENT SHALL THE COPYRIGHT OWNER, CONTRIBUTORS OR ANYONE DISTRIBUTING
# THE SOFTWARE BE LIABLE FOR ANY CLAIM, DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
# OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
# WHETHER IN ACTION OF CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF OR IN CONNECTION WITH
# THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE, EVEN IF ADVISED
# OF THE POSSIBILITY OF SUCH DAMAGE.
#-------------------------------------------------------------------------------

# $Id$

include ../../../Makefile-Config.mk

#-------------------------------------------------------------------------------
# Display
#-------------------------------------------------------------------------------

PROMPT              := "    ["$(COLOR_GREEN)" XEOS "$(COLOR_NONE)"]> ["$(COLOR_GREEN)" SRC  "$(COLOR_NONE)"]> ["$(COLOR_GREEN)" LIB  "$(COLOR_NONE)"]> ["$(COLOR_GREEN)" LIBC "$(COLOR_NONE)"]> *** "

#-------------------------------------------------------------------------------
# Paths
#-------------------------------------------------------------------------------

DIR_SRC_ASSERT      = $(PATH_SRC_LIB_LIBC)assert/
DIR_SRC_COMPLEX     = $(PATH_SRC_LIB_LIBC)complex/
DIR_SRC_CTYPE       = $(PATH_SRC_LIB_LIBC)ctype/
DIR_SRC_ERRNO       = $(PATH_SRC_LIB_LIBC)errno/
DIR_SRC_FENV        = $(PATH_SRC_LIB_LIBC)fenv/
DIR_SRC_INTTYPES    = $(PATH_SRC_LIB_LIBC)inttypes/
DIR_SRC_LOCALE      = $(PATH_SRC_LIB_LIBC)locale/
DIR_SRC_MATH        = $(PATH_SRC_LIB_LIBC)math/
DIR_SRC_SETJMP      = $(PATH_SRC_LIB_LIBC)setjmp/
DIR_SRC_SIGNAL      = $(PATH_SRC_LIB_LIBC)signal/
DIR_SRC_STDARG      = $(PATH_SRC_LIB_LIBC)stdarg/
DIR_SRC_STDIO       = $(PATH_SRC_LIB_LIBC)stdio/
DIR_SRC_STDLIB      = $(PATH_SRC_LIB_LIBC)stdlib/
DIR_SRC_STRING      = $(PATH_SRC_LIB_LIBC)string/
DIR_SRC_TGMATH      = $(PATH_SRC_LIB_LIBC)tgmath/
DIR_SRC_TIME        = $(PATH_SRC_LIB_LIBC)time/
DIR_SRC_WCHAR       = $(PATH_SRC_LIB_LIBC)wchar/
DIR_SRC_WCTYPE      = $(PATH_SRC_LIB_LIBC)wctype/

#-------------------------------------------------------------------------------
# Software arguments
#-------------------------------------------------------------------------------

ARGS_CC_32          := -iquote $(PATH_SRC_LIB_LIBC)include/c99/ $(ARGS_CC_32)
ARGS_CC_64          := -iquote $(PATH_SRC_LIB_LIBC)include/c99/ $(ARGS_CC_64)

#-------------------------------------------------------------------------------
# Search paths
#-------------------------------------------------------------------------------

# Define the search paths for source files
vpath %$(EXT_C) $(PATH_SRC_LIB_LIBC)
vpath %$(EXT_C) $(DIR_SRC_ASSERT)
vpath %$(EXT_C) $(DIR_SRC_COMPLEX)
vpath %$(EXT_C) $(DIR_SRC_CTYPE)
vpath %$(EXT_C) $(DIR_SRC_ERRNO)
vpath %$(EXT_C) $(DIR_SRC_FENV)
vpath %$(EXT_C) $(DIR_SRC_INTTYPES)
vpath %$(EXT_C) $(DIR_SRC_LOCALE)
vpath %$(EXT_C) $(DIR_SRC_MATH)
vpath %$(EXT_C) $(DIR_SRC_SETJMP)
vpath %$(EXT_C) $(DIR_SRC_SIGNAL)
vpath %$(EXT_C) $(DIR_SRC_STDIO)
vpath %$(EXT_C) $(DIR_SRC_STDLIB)
vpath %$(EXT_C) $(DIR_SRC_STRING)
vpath %$(EXT_C) $(DIR_SRC_TGMATH)
vpath %$(EXT_C) $(DIR_SRC_TIME)
vpath %$(EXT_C) $(DIR_SRC_WCHAR)
vpath %$(EXT_C) $(DIR_SRC_WCTYPE)

#-------------------------------------------------------------------------------
# File suffixes
#-------------------------------------------------------------------------------

# Adds the suffixes used in this file
.SUFFIXES:  $(EXT_C)    \
            $(EXT_H)    \
            $(EXT_OBJ)  \
            $(EXT_BIN)

#-------------------------------------------------------------------------------
# Files
#-------------------------------------------------------------------------------

_FILES_C_OBJ_BUILD          = $(call XEOS_FUNC_C_OBJ,$(PATH_BUILD_32_LIB_OBJ_LIBC),$(PATH_SRC_LIB_LIBC))
_FILES_C_OBJ_BUILD_ASSERT   = $(call XEOS_FUNC_C_OBJ,$(PATH_BUILD_32_LIB_OBJ_LIBC),$(DIR_SRC_ASSERT))
_FILES_C_OBJ_BUILD_COMPLEX  = $(call XEOS_FUNC_C_OBJ,$(PATH_BUILD_32_LIB_OBJ_LIBC),$(DIR_SRC_COMPLEX))
_FILES_C_OBJ_BUILD_CTYPE    = $(call XEOS_FUNC_C_OBJ,$(PATH_BUILD_32_LIB_OBJ_LIBC),$(DIR_SRC_CTYPE))
_FILES_C_OBJ_BUILD_ERRNO    = $(call XEOS_FUNC_C_OBJ,$(PATH_BUILD_32_LIB_OBJ_LIBC),$(DIR_SRC_ERRNO))
_FILES_C_OBJ_BUILD_FENV     = $(call XEOS_FUNC_C_OBJ,$(PATH_BUILD_32_LIB_OBJ_LIBC),$(DIR_SRC_FENV))
_FILES_C_OBJ_BUILD_INTTYPES = $(call XEOS_FUNC_C_OBJ,$(PATH_BUILD_32_LIB_OBJ_LIBC),$(DIR_SRC_INTTYPES))
_FILES_C_OBJ_BUILD_LOCALE   = $(call XEOS_FUNC_C_OBJ,$(PATH_BUILD_32_LIB_OBJ_LIBC),$(DIR_SRC_LOCALE))
_FILES_C_OBJ_BUILD_MATH     = $(call XEOS_FUNC_C_OBJ,$(PATH_BUILD_32_LIB_OBJ_LIBC),$(DIR_SRC_MATH))
_FILES_C_OBJ_BUILD_SETJMP   = $(call XEOS_FUNC_C_OBJ,$(PATH_BUILD_32_LIB_OBJ_LIBC),$(DIR_SRC_SETJMP))
_FILES_C_OBJ_BUILD_SIGNAL   = $(call XEOS_FUNC_C_OBJ,$(PATH_BUILD_32_LIB_OBJ_LIBC),$(DIR_SRC_SIGNAL))
_FILES_C_OBJ_BUILD_STDIO    = $(call XEOS_FUNC_C_OBJ,$(PATH_BUILD_32_LIB_OBJ_LIBC),$(DIR_SRC_STDIO))
_FILES_C_OBJ_BUILD_STDLIB   = $(call XEOS_FUNC_C_OBJ,$(PATH_BUILD_32_LIB_OBJ_LIBC),$(DIR_SRC_STDLIB))
_FILES_C_OBJ_BUILD_STRING   = $(call XEOS_FUNC_C_OBJ,$(PATH_BUILD_32_LIB_OBJ_LIBC),$(DIR_SRC_STRING))
_FILES_C_OBJ_BUILD_TGMATH   = $(call XEOS_FUNC_C_OBJ,$(PATH_BUILD_32_LIB_OBJ_LIBC),$(DIR_SRC_TGMATH))
_FILES_C_OBJ_BUILD_TIME     = $(call XEOS_FUNC_C_OBJ,$(PATH_BUILD_32_LIB_OBJ_LIBC),$(DIR_SRC_TIME))
_FILES_C_OBJ_BUILD_WCHAR    = $(call XEOS_FUNC_C_OBJ,$(PATH_BUILD_32_LIB_OBJ_LIBC),$(DIR_SRC_WCHAR))
_FILES_C_OBJ_BUILD_WCTYPE   = $(call XEOS_FUNC_C_OBJ,$(PATH_BUILD_32_LIB_OBJ_LIBC),$(DIR_SRC_WCTYPE))

#-------------------------------------------------------------------------------
# Built-in targets
#-------------------------------------------------------------------------------

# Declaration for phony targets, to avoid problems with local files
.PHONY: all     \
        clean

#-------------------------------------------------------------------------------
# Phony targets
#-------------------------------------------------------------------------------

# Build the full project
all:    $(_FILES_C_OBJ_BUILD)           \
        $(_FILES_C_OBJ_BUILD_ASSERT)    \
        $(_FILES_C_OBJ_BUILD_COMPLEX)   \
        $(_FILES_C_OBJ_BUILD_CTYPE)     \
        $(_FILES_C_OBJ_BUILD_ERRNO)     \
        $(_FILES_C_OBJ_BUILD_FENV)      \
        $(_FILES_C_OBJ_BUILD_INTTYPES)  \
        $(_FILES_C_OBJ_BUILD_LOCALE)    \
        $(_FILES_C_OBJ_BUILD_MATH)      \
        $(_FILES_C_OBJ_BUILD_SETJMP)    \
        $(_FILES_C_OBJ_BUILD_SIGNAL)    \
        $(_FILES_C_OBJ_BUILD_STDIO)     \
        $(_FILES_C_OBJ_BUILD_STDLIB)    \
        $(_FILES_C_OBJ_BUILD_STRING)    \
        $(_FILES_C_OBJ_BUILD_TGMATH)    \
        $(_FILES_C_OBJ_BUILD_TIME)      \
        $(_FILES_C_OBJ_BUILD_WCHAR)     \
        $(_FILES_C_OBJ_BUILD_WCTYPE)
	
	@$(PRINT) $(PROMPT)$(COLOR_CYAN)"Generating the library archive"$(COLOR_NONE)" [ 32 bits ]: "$(COLOR_GRAY)"libc99.a"$(COLOR_NONE)
	@$(AR_32) $(ARGS_AR_32) $(PATH_BUILD_32_LIB_BIN)libc99.a $(PATH_BUILD_32_LIB_OBJ_LIBC)*$(EXT_OBJ)
	@$(RANLIB_32) $(PATH_BUILD_32_LIB_BIN)libc99.a
	
	@$(PRINT) $(PROMPT)$(COLOR_CYAN)"Generating the library archive"$(COLOR_NONE)" [ 64 bits ]: "$(COLOR_GRAY)"libc99.a"$(COLOR_NONE)
	@$(AR_64) $(ARGS_AR_64) $(PATH_BUILD_64_LIB_BIN)libc99.a $(PATH_BUILD_64_LIB_OBJ_LIBC)*$(EXT_OBJ)
	@$(RANLIB_64) $(PATH_BUILD_64_LIB_BIN)libc99.a
	
	@$(PRINT) $(PROMPT)$(COLOR_CYAN)"Generating the dynamic library"$(COLOR_NONE)" [ 32 bits ]: "$(COLOR_GRAY)"libc99.so"$(COLOR_NONE)
	@$(LD_32) $(ARGS_LD_SHARED_32) -o $(PATH_BUILD_32_LIB_BIN)libc99.so $(PATH_BUILD_32_LIB_OBJ_LIBC)*$(EXT_OBJ_PIC)
	
	@$(PRINT) $(PROMPT)$(COLOR_CYAN)"Generating the dynamic library"$(COLOR_NONE)" [ 64 bits ]: "$(COLOR_GRAY)"libc99.so"$(COLOR_NONE)
	@$(LD_64) $(ARGS_LD_SHARED_64) -o $(PATH_BUILD_64_LIB_BIN)libc99.so $(PATH_BUILD_64_LIB_OBJ_LIBC)*$(EXT_OBJ_PIC)
	
# Cleans the build files
clean:
	
	@$(PRINT) $(PROMPT)"Cleaning all build files"
	@$(RM) $(ARGS_RM) $(PATH_BUILD_32_LIB_OBJ_LIBC)*
	@$(RM) $(ARGS_RM) $(PATH_BUILD_64_LIB_OBJ_LIBC)*
	@$(RM) $(ARGS_RM) $(PATH_BUILD_32_LIB_BIN)libc.*
	@$(RM) $(ARGS_RM) $(PATH_BUILD_64_LIB_BIN)libc.*
