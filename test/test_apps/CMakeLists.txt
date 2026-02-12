###############################################################################
# Copyright (c) 2018-2025 LunarG, Inc.
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
# Description: CMake script for test apps
###############################################################################

SET(GFXRECON_INSTALL_TESTAPPDIR ${GFXRECON_INSTALL_TESTDIR}/test_apps)
set(GFXRECON_TESTAPPS_RES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/res)

if(NOT CMAKE_SYSTEM_NAME MATCHES "Android")
    install(DIRECTORY ${GFXRECON_TESTAPPS_RES_DIR} DESTINATION ${GFXRECON_INSTALL_TESTDIR})
endif()

add_subdirectory(common)
add_subdirectory(triangle)
add_subdirectory(triangle-extra-device)
add_subdirectory(multisample-depth)
add_subdirectory(pipeline-binaries)
add_subdirectory(host-image-copy)
add_subdirectory(shader-objects)
add_subdirectory(sparse-resources)
add_subdirectory(acquired-image)
add_subdirectory(set-environment)
add_subdirectory(ahb)
if(CMAKE_SYSTEM_NAME MATCHES "Linux|BSD|GNU")
    add_subdirectory(external-memory-fd-export)
    add_subdirectory(external-memory-fd-import)
    add_subdirectory(wait-for-present)
    add_subdirectory(trigger-trimming)
endif()
add_subdirectory(launcher)
