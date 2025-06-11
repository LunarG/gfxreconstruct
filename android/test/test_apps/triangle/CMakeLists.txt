##############################################################################
# Copyright (c) 2025 LunarG, Inc.
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
# Description: CMake script for Android triangle test app
###############################################################################

get_filename_component(GFXRECON_SOURCE_DIR ../../../.. ABSOLUTE)

set(TRIANGLE_DIR ${GFXRECON_SOURCE_DIR}/test/test_apps/triangle)
add_library(gfxrecon-testapp-triangle
            STATIC
                ${TRIANGLE_DIR}/app.cpp)

target_include_directories(gfxrecon-testapp-triangle
                           PUBLIC
                               ${TRIANGLE_DIR}
                               ${GFXRECON_SOURCE_DIR}/external/precompiled/android/include
                               ${CMAKE_BINARY_DIR})

target_link_libraries(
        gfxrecon-testapp-triangle
        gfxrecon-testapp-base
        native_app_glue
        android
        log)
