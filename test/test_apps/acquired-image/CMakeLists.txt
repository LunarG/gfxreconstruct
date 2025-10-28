###############################################################################
# Copyright (c) 2018-2024 LunarG, Inc.
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
# Description: CMake script for acquired image test app
###############################################################################

set(TEST_NAME acquired-image)
add_library(gfxrecon-testapp-${TEST_NAME} app.cpp)

target_include_directories(gfxrecon-testapp-${TEST_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(gfxrecon-testapp-${TEST_NAME} gfxrecon-testapp-base gfxrecon_util)

common_build_directives(gfxrecon-testapp-${TEST_NAME})

if(NOT CMAKE_SYSTEM_NAME MATCHES "Android")
    install(TARGETS gfxrecon-testapp-${TEST_NAME} RUNTIME DESTINATION ${GFXRECON_INSTALL_TESTAPPDIR}/${TEST_NAME})
endif()
