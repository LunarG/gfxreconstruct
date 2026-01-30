###############################################################################
# Copyright (c) 2018-2026 LunarG, Inc.
# Copyright (c) 2020-2023 Advanced Micro Devices, Inc.
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
# Author: AMD Developer Tools Team
# Description: CMake script for framework util target
###############################################################################

if(BUILD_LAUNCHER_AND_INTERCEPTOR)
    add_executable(gfxrecon-launcher "")


    target_sources(gfxrecon-launcher
                   PRIVATE
                        ${CMAKE_CURRENT_LIST_DIR}/desktop_main.cpp
                        $<$<BOOL:WIN32>:${PROJECT_SOURCE_DIR}/version.rc>
                        $<$<BOOL:WIN32>:${GFXRECON_WIN_MANIFEST}>
    )

    target_include_directories(gfxrecon-launcher PUBLIC ${CMAKE_BINARY_DIR} ${PROJECT_SOURCE_DIR}/layer/d3d12_hook ${PROJECT_SOURCE_DIR}/framework/util ${PROJECT_SOURCE_DIR}/framework/interception_util)

    target_link_libraries(gfxrecon-launcher gfxrecon_util gfxrecon_graphics)

    common_build_directives(gfxrecon-launcher)

    install(TARGETS gfxrecon-launcher RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
    install(FILES ${CMAKE_BINARY_DIR}/layer/gfxrecon_interceptor/$<CONFIG>/gfxrecon_interceptor.dll DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()
