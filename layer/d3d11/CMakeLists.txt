###############################################################################
# Copyright (c) 2018-2020 LunarG, Inc.
# Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
# Copyright (c) 2023 Qualcomm Technologies, Inc. and/or its subsidiaries.
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

# CMake adds gdi32.lib to the linker input by default. For 32-bit builds, there
# is a conflict between some D3DKMT exports from gdi32.lib and the d3d11_ms.lib,
# requiring that gdi32.lib to be removed from the link command.
string(REPLACE "gdi32.lib" "" CMAKE_CXX_STANDARD_LIBRARIES ${CMAKE_CXX_STANDARD_LIBRARIES})

set(LINK_D3D11_OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/d3d11_ms.lib)

add_library(d3d11 SHARED "")
target_sources(d3d11 PRIVATE
                ${CMAKE_CURRENT_LIST_DIR}/dll_main.cpp
                ${CMAKE_CURRENT_LIST_DIR}/hook_d3d11.h
                ${CMAKE_CURRENT_LIST_DIR}/hook_d3d11.cpp
                ${CMAKE_CURRENT_LIST_DIR}/d3d11.def)

target_include_directories(d3d11
                           PUBLIC
                                ${CMAKE_BINARY_DIR}
                                ${CMAKE_SOURCE_DIR})

target_link_libraries(d3d11 gfxrecon_encode gfxrecon_util ${LINK_D3D11_OUTPUT})
common_build_directives(d3d11)
add_custom_command(TARGET d3d11 PRE_BUILD
                    COMMAND lib /def:${CMAKE_CURRENT_LIST_DIR}/d3d11_ms.def /out:${LINK_D3D11_OUTPUT} /machine:${LINK_ARCH}
                    DEPENDS ${CMAKE_CURRENT_LIST_DIR}/d3d11_ms.def)

install(FILES $<TARGET_FILE_DIR:d3d11>/d3d11.dll DESTINATION ${CMAKE_INSTALL_BINDIR}/d3d12_capture)
