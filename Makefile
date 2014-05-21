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

PROMPT  := "    ["$(COLOR_GREEN)" XEOS "$(COLOR_NONE)"]> ["$(COLOR_GREEN)" SRC  "$(COLOR_NONE)"]> ["$(COLOR_GREEN)" LIB  "$(COLOR_NONE)"]> ["$(COLOR_GREEN)" C99  "$(COLOR_NONE)"]> *** "

#-------------------------------------------------------------------------------
# Files
#-------------------------------------------------------------------------------

_FILES  = $(call XEOS_FUNC_C_OBJ,$(PATH_SRC_LIB_C99))
_FILES += $(call XEOS_FUNC_C_OBJ,$(PATH_SRC_LIB_C99)assert/)
_FILES += $(call XEOS_FUNC_C_OBJ,$(PATH_SRC_LIB_C99)ctype/)
_FILES += $(call XEOS_FUNC_C_OBJ,$(PATH_SRC_LIB_C99)errno/)
_FILES += $(call XEOS_FUNC_C_OBJ,$(PATH_SRC_LIB_C99)fenv/)
_FILES += $(call XEOS_FUNC_C_OBJ,$(PATH_SRC_LIB_C99)locale/)
_FILES += $(call XEOS_FUNC_C_OBJ,$(PATH_SRC_LIB_C99)math/)
_FILES += $(call XEOS_FUNC_C_OBJ,$(PATH_SRC_LIB_C99)setjmp/)
_FILES += $(call XEOS_FUNC_C_OBJ,$(PATH_SRC_LIB_C99)signal/)
_FILES += $(call XEOS_FUNC_C_OBJ,$(PATH_SRC_LIB_C99)stdio/)
_FILES += $(call XEOS_FUNC_C_OBJ,$(PATH_SRC_LIB_C99)stdlib/)
_FILES += $(call XEOS_FUNC_C_OBJ,$(PATH_SRC_LIB_C99)string/)
_FILES += $(call XEOS_FUNC_C_OBJ,$(PATH_SRC_LIB_C99)time/)

#-------------------------------------------------------------------------------
# Built-in targets
#-------------------------------------------------------------------------------

# Declaration for phony targets, to avoid problems with local files
.PHONY: all clean

#-------------------------------------------------------------------------------
# Phony targets
#-------------------------------------------------------------------------------

# Build the full project
all: $(_FILES)
	
	@$(PRINT) $(PROMPT)$(COLOR_CYAN)"Generating the library archive"$(COLOR_NONE)" [ 32 bits ]: "$(COLOR_GRAY)"libc99.a"$(COLOR_NONE)
	@$(call XEOS_FUNC_LIB_STATIC_32,libc99,$^)
	
	@$(PRINT) $(PROMPT)$(COLOR_CYAN)"Generating the library archive"$(COLOR_NONE)" [ 64 bits ]: "$(COLOR_GRAY)"libc99.a"$(COLOR_NONE)
	@$(call XEOS_FUNC_LIB_STATIC_64,libc99,$^)
	
	@$(PRINT) $(PROMPT)$(COLOR_CYAN)"Generating the dynamic library"$(COLOR_NONE)" [ 32 bits ]: "$(COLOR_GRAY)"libc99.so"$(COLOR_NONE)
	@$(call XEOS_FUNC_LIB_DYNAMIC_32,libc99,$^)
	
	@$(PRINT) $(PROMPT)$(COLOR_CYAN)"Generating the dynamic library"$(COLOR_NONE)" [ 64 bits ]: "$(COLOR_GRAY)"libc99.so"$(COLOR_NONE)
	@$(call XEOS_FUNC_LIB_DYNAMIC_64,libc99,$^)

# Cleans the build files
clean:
	
	@$(PRINT) $(PROMPT)"Cleaning all build files"
	@$(RM) $(ARGS_RM) $(PATH_BUILD_32_OBJ)$(subst $(PATH_SRC),,$(PATH_SRC_LIB_C99))
	@$(RM) $(ARGS_RM) $(PATH_BUILD_64_OBJ)$(subst $(PATH_SRC),,$(PATH_SRC_LIB_C99))
	@$(RM) $(ARGS_RM) $(PATH_BUILD_32_BIN)libc99.*
	@$(RM) $(ARGS_RM) $(PATH_BUILD_64_BIN)libc99.*
