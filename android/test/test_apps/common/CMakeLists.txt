###############################################################################
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
# Description: CMake script for Android test app base
###############################################################################

add_library(gfxrecon-testapp-base STATIC ${GFXRECON_SOURCE_DIR}/test/test_apps/common/test_app_base.cpp)
target_include_directories(gfxrecon-testapp-base
                           PRIVATE
                               ${GFXRECON_SOURCE_DIR}/external)
target_include_directories(gfxrecon-testapp-base
                           PUBLIC
                               ${GFXRECON_SOURCE_DIR}/test/test_apps/common
                               ${GFXRECON_SOURCE_DIR}/test/icd)

set(FRAMEWORK_DIR ${GFXRECON_ANDROID_DIR}/framework)
set(GFXRECON_ANDROID_TEST_APPS_DIR ${CMAKE_SOURCE_DIR}/..)
add_subdirectory(${FRAMEWORK_DIR}/util ${FRAMEWORK_DIR}/util/build/${ANDROID_ABI})
add_subdirectory(${FRAMEWORK_DIR}/decode ${FRAMEWORK_DIR}/decode/build/${ANDROID_ABI})
add_subdirectory(${FRAMEWORK_DIR}/graphics ${FRAMEWORK_DIR}/graphics/build/${ANDROID_ABI})
add_subdirectory(${FRAMEWORK_DIR}/format ${FRAMEWORK_DIR}/format/build/${ANDROID_ABI})
add_subdirectory(${FRAMEWORK_DIR}/application ${FRAMEWORK_DIR}/application/build/${ANDROID_ABI})

target_link_libraries(gfxrecon-testapp-base
    PUBLIC
    gfxrecon_util
    gfxrecon_application)


macro(common_build_directives TARGET)
endmacro()

macro(add_test_app TEST_NAME)
    add_subdirectory(${GFXRECON_SOURCE_DIR}/test/test_apps/${TEST_NAME}
                     ${GFXRECON_ANDROID_TEST_APPS_DIR}/${TEST_NAME}/build/${ANDROID_ABI})
endmacro()

add_test_app(acquired-image)
add_test_app(external-memory-fd-export)
add_test_app(external-memory-fd-import)
add_test_app(host-image-copy)
add_test_app(multisample-depth)
add_test_app(pipeline-binaries)
add_test_app(triangle)
add_test_app(triangle-extra-device)
add_test_app(shader-objects)
add_test_app(sparse-resources)
add_test_app(wait-for-present)
add_test_app(trigger-trimming)
add_test_app(ahb)
