###############################################################################
# Copyright (c) 2018-2020 LunarG, Inc.
# Copyright (c) 2021 Advanced Micro Devices, Inc.
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
# Description: CMake script for layer dxgi target
###############################################################################

set(LINK_DXGI_OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/dxgi_ms.lib)

add_library(dxgi SHARED "")
target_sources(dxgi PRIVATE
                ${CMAKE_CURRENT_LIST_DIR}/dll_main.cpp
                ${CMAKE_CURRENT_LIST_DIR}/hook_dxgi.h
                ${CMAKE_CURRENT_LIST_DIR}/hook_dxgi.cpp
                ${CMAKE_CURRENT_LIST_DIR}/dxgi.def)
target_include_directories(dxgi PUBLIC ${CMAKE_BINARY_DIR} ${PROJECT_SOURCE_DIR})
target_link_libraries(dxgi gfxrecon_encode gfxrecon_util ${LINK_DXGI_OUTPUT})
common_build_directives(dxgi)
add_custom_command(TARGET dxgi PRE_BUILD
                    COMMAND lib /def:${CMAKE_CURRENT_LIST_DIR}/dxgi_ms.def /out:${LINK_DXGI_OUTPUT} /machine:${LINK_ARCH})

install(FILES $<TARGET_FILE_DIR:dxgi>/dxgi.dll DESTINATION ${CMAKE_INSTALL_BINDIR}/d3d12_capture)
