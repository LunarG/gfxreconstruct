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

target_include_directories(${TARGET_NAME} PUBLIC
        ${CMAKE_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${TARGET_NAME}
                      gfxrecon-testapp-external-memory-fd-export
                      gfxrecon-testapp-external-memory-fd-import
                      gfxrecon-testapp-host-image-copy
                      gfxrecon-testapp-multisample-depth
                      gfxrecon-testapp-pipeline-binaries
                      gfxrecon-testapp-shader-objects
                      gfxrecon-testapp-triangle)

common_build_directives(${TARGET_NAME})

add_custom_command(
        TARGET ${TARGET_NAME}
        POST_BUILD
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE})
if (WIN32)
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_RUNTIME_DLLS:${TARGET_NAME}> $<TARGET_FILE_DIR:${TARGET_NAME}>
        COMMAND_EXPAND_LISTS)
endif ()

install(TARGETS ${TARGET_NAME} RUNTIME DESTINATION ${GFXRECON_INSTALL_TESTAPPDIR}/launcher)

add_dependencies(gfxrecon-testapps ${TARGET_NAME})
