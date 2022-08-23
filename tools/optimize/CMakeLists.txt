###############################################################################
# Copyright (c) 2020 LunarG, Inc.
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

add_executable(gfxrecon-optimize "")

target_sources(gfxrecon-optimize
               PRIVATE
                   ${CMAKE_CURRENT_LIST_DIR}/main.cpp
                   ${CMAKE_CURRENT_LIST_DIR}/file_optimizer.h
                   ${CMAKE_CURRENT_LIST_DIR}/file_optimizer.cpp
                   $<$<BOOL:${BUILD_D3D12}>:${CMAKE_CURRENT_LIST_DIR}/dx12_file_optimizer.h>
                   $<$<BOOL:${BUILD_D3D12}>:${CMAKE_CURRENT_LIST_DIR}/dx12_file_optimizer.cpp>
                   $<$<BOOL:${BUILD_D3D12}>:${CMAKE_CURRENT_LIST_DIR}/dx12_optimize_util.h>
                   $<$<BOOL:${BUILD_D3D12}>:${CMAKE_CURRENT_LIST_DIR}/dx12_optimize_util.cpp>
                   $<$<BOOL:${BUILD_D3D12}>:${CMAKE_CURRENT_LIST_DIR}/block_skipping_file_processor.h>
                   $<$<BOOL:${BUILD_D3D12}>:${CMAKE_CURRENT_LIST_DIR}/block_skipping_file_processor.cpp>
              )

target_include_directories(gfxrecon-optimize PUBLIC ${CMAKE_BINARY_DIR})

target_link_libraries(gfxrecon-optimize
                          gfxrecon_application
                          gfxrecon_decode
                          gfxrecon_graphics
                          gfxrecon_format
                          gfxrecon_util
                          platform_specific
                          $<$<BOOL:${BUILD_D3D12}>:d3d12.lib>
                          $<$<BOOL:${BUILD_D3D12}>:dxgi.lib>)

common_build_directives(gfxrecon-optimize)

install(TARGETS gfxrecon-optimize RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
