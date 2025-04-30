###############################################################################
# Copyright (c) 2024-2025 LunarG, Inc.
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
# Description: CMake script for VK_KHR_external_memory_fd export test app
###############################################################################

add_library(gfxrecon-testapp-external-memory-fd-export "")

target_sources(gfxrecon-testapp-external-memory-fd-export
               PRIVATE
               ${CMAKE_CURRENT_LIST_DIR}/app.cpp)

target_include_directories(gfxrecon-testapp-external-memory-fd-export PUBLIC
                           PUBLIC
                               ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(gfxrecon-testapp-external-memory-fd-export
                      PUBLIC
                          gfxrecon-testapp-base)

common_build_directives(gfxrecon-testapp-external-memory-fd-export)

install(TARGETS gfxrecon-testapp-external-memory-fd-export
        RUNTIME DESTINATION ${GFXRECON_INSTALL_TESTAPPDIR}/external-memory-fd-export)
install(DIRECTORY ${GFXRECON_TESTAPPS_RES_DIR}/external-memory-fd-export DESTINATION ${GFXRECON_INSTALL_TESTAPPDIR})

add_dependencies(gfxrecon-testapps gfxrecon-testapp-external-memory-fd-export)
