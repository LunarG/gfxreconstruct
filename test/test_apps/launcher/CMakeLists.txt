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
# Description: CMake script for Test Launcher
###############################################################################

set(TARGET_NAME gfxrecon-test-launcher)
add_executable(${TARGET_NAME} "")

target_sources(${TARGET_NAME}
               PRIVATE
                   ${CMAKE_CURRENT_LIST_DIR}/test_launcher.cpp)

target_include_directories(${TARGET_NAME}
                           PUBLIC
                               ${CMAKE_BINARY_DIR}
                               ${CMAKE_CURRENT_SOURCE_DIR}
                               ${CMAKE_SOURCE_DIR})

set(GFXRECON_TEST_LAUNCHER_LINK_LIBRARIES
    gfxrecon-testapp-acquired-image
    gfxrecon-testapp-host-image-copy
    gfxrecon-testapp-multisample-depth
    gfxrecon-testapp-pipeline-binaries
    gfxrecon-testapp-shader-objects
    gfxrecon-testapp-sparse-resources
    gfxrecon-testapp-triangle
    gfxrecon-testapp-triangle-extra-device
)

if(CMAKE_SYSTEM_NAME MATCHES "Linux|BSD|GNU")
    list(APPEND GFXRECON_TEST_LAUNCHER_LINK_LIBRARIES
            gfxrecon-testapp-external-memory-fd-export
            gfxrecon-testapp-external-memory-fd-import
            gfxrecon-testapp-wait-for-present)
endif()

target_link_libraries(${TARGET_NAME}
                      ${GFXRECON_TEST_LAUNCHER_LINK_LIBRARIES})

common_build_directives(${TARGET_NAME})

if(NOT CMAKE_SYSTEM_NAME MATCHES "Android")
    install(TARGETS ${TARGET_NAME} RUNTIME DESTINATION ${GFXRECON_INSTALL_TESTAPPDIR}/launcher)
endif()
