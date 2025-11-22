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
# Description: CMake script for layer d3d12 target
###############################################################################

set(LINK_D3D12_OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/d3d12_ms.lib)

add_library(d3d12 SHARED "")
target_sources(d3d12 PRIVATE
                ${CMAKE_CURRENT_LIST_DIR}/dll_main.cpp
                ${CMAKE_CURRENT_LIST_DIR}/hook_d3d12.h
                ${CMAKE_CURRENT_LIST_DIR}/hook_d3d12.cpp
                ${CMAKE_CURRENT_LIST_DIR}/d3d12.def)

target_include_directories(d3d12
                           PUBLIC
                                ${CMAKE_BINARY_DIR}
                                ${PROJECT_SOURCE_DIR})
if (D3D12_SUPPORT)
    target_include_directories(d3d12 SYSTEM PUBLIC ${D3D12_INCLUDE_DIRECTORIES})
endif()

target_link_libraries(d3d12 gfxrecon_encode gfxrecon_util ${LINK_D3D12_OUTPUT})
common_build_directives(d3d12)
add_custom_command(TARGET d3d12 PRE_BUILD
                    COMMAND lib /def:${CMAKE_CURRENT_LIST_DIR}/d3d12_ms.def /out:${LINK_D3D12_OUTPUT} /machine:${LINK_ARCH}
                    DEPENDS ${CMAKE_CURRENT_LIST_DIR}/d3d12_ms.def)

install(FILES $<TARGET_FILE_DIR:d3d12>/d3d12.dll DESTINATION ${CMAKE_INSTALL_BINDIR}/d3d12_capture)


