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
# Description: CMake script for Test launcher app
###############################################################################

cmake_minimum_required(VERSION 3.4.1)

get_filename_component(GFXRECON_SOURCE_DIR ../../../.. ABSOLUTE)
set(GFXRECON_ANDROID_DIR ${GFXRECON_SOURCE_DIR}/android)
include(${GFXRECON_ANDROID_DIR}/framework/cmake-config/PlatformConfig.cmake)

project(gfxrecon-test-launcher)

set(GFXRECON_ANDROID_TEST_APPS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/..)

set(COMMON_DIR ${GFXRECON_ANDROID_TEST_APPS_DIR}/common)
add_subdirectory(${COMMON_DIR} ${COMMON_DIR}/build/${ANDROID_ABI})


add_library(${PROJECT_NAME}
            SHARED
                ${GFXRECON_SOURCE_DIR}/test/test_apps/launcher/test_launcher.cpp)

target_include_directories(${PROJECT_NAME}
                           PUBLIC
                               ${GFXRECON_SOURCE_DIR}/external/precompiled/android/include
                               ${CMAKE_BINARY_DIR})

set(GFXRECON_TEST_LAUNCHER_LINK_LIBRARIES
    gfxrecon-testapp-acquired-image
    gfxrecon-testapp-host-image-copy
    gfxrecon-testapp-multisample-depth
    gfxrecon-testapp-pipeline-binaries
    gfxrecon-testapp-shader-objects
    gfxrecon-testapp-sparse-resources
    gfxrecon-testapp-triangle
    gfxrecon-testapp-external-memory-fd-export
    gfxrecon-testapp-external-memory-fd-import
    gfxrecon-testapp-wait-for-present
    gfxrecon-testapp-ahb)

target_link_libraries(${PROJECT_NAME}
                      ${GFXRECON_TEST_LAUNCHER_LINK_LIBRARIES})

target_link_options(${PROJECT_NAME}
    PRIVATE
        LINKER:--version-script=${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}.map)
