###############################################################################
# Copyright (c) 2018-2020 LunarG, Inc.
# Copyright (c) 2021-2023 Advanced Micro Devices, Inc.
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
# Description: CMake script for layer d3d12_capture target
###############################################################################

add_library(d3d12_capture SHARED "")
target_sources(d3d12_capture PRIVATE
                ${CMAKE_CURRENT_LIST_DIR}/dll_main.cpp
                ${CMAKE_CURRENT_LIST_DIR}/d3d12_capture.def
                $<$<BOOL:WIN32>:${PROJECT_SOURCE_DIR}/version.rc>)

target_include_directories(d3d12_capture 
                           PUBLIC 
                               ${CMAKE_BINARY_DIR} 
                               ${PROJECT_SOURCE_DIR}
                               $<$<BOOL:${D3D12_SUPPORT}>:${D3D12_INCLUDE_DIRECTORIES}>)

target_link_libraries(d3d12_capture gfxrecon_encode gfxrecon_format gfxrecon_util platform_specific)
common_build_directives(d3d12_capture)

install(FILES $<TARGET_FILE_DIR:d3d12_capture>/d3d12_capture.dll DESTINATION ${CMAKE_INSTALL_BINDIR}/d3d12_capture)
