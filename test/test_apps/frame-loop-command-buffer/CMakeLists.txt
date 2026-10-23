###############################################################################
# Copyright (c) 2018-2026 LunarG, Inc.
# All rights reserved
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to
# deal in the Software without restriction, including without limitation the
# rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.
#
# Author: LunarG Team
# Description: CMake script for frame-loop-command-buffer test app
###############################################################################

add_library(gfxrecon-testapp-frame-loop-command-buffer app.cpp)

target_include_directories(gfxrecon-testapp-frame-loop-command-buffer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(gfxrecon-testapp-frame-loop-command-buffer gfxrecon-testapp-base)

common_build_directives(gfxrecon-testapp-frame-loop-command-buffer)

if(NOT CMAKE_SYSTEM_NAME MATCHES "Android")
    install(TARGETS gfxrecon-testapp-frame-loop-command-buffer RUNTIME DESTINATION ${GFXRECON_INSTALL_TESTAPPDIR}/frame-loop-command-buffer)
endif()
