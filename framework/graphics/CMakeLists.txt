###############################################################################
# Copyright (c) 2021 LunarG, Inc.
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
# Description: CMake script for framework graphics target
###############################################################################

add_library(gfxrecon_graphics STATIC "")

target_sources(gfxrecon_graphics
               PRIVATE
                    $<$<BOOL:${BUILD_D3D12}>:${CMAKE_CURRENT_LIST_DIR}/dx12_gpu_va_map.h>
                    $<$<BOOL:${BUILD_D3D12}>:${CMAKE_CURRENT_LIST_DIR}/dx12_gpu_va_map.cpp>
                    $<$<BOOL:${BUILD_D3D12}>:${CMAKE_CURRENT_LIST_DIR}/dx12_resource_data_util.h>
                    $<$<BOOL:${BUILD_D3D12}>:${CMAKE_CURRENT_LIST_DIR}/dx12_resource_data_util.cpp>
                    $<$<BOOL:${BUILD_D3D12}>:${CMAKE_CURRENT_LIST_DIR}/dx12_util.h>
                    $<$<BOOL:${BUILD_D3D12}>:${CMAKE_CURRENT_LIST_DIR}/dx12_util.cpp>
                    $<$<BOOL:${BUILD_D3D12}>:${CMAKE_CURRENT_LIST_DIR}/dx12_shader_id_map.h>
                    $<$<BOOL:${BUILD_D3D12}>:${CMAKE_CURRENT_LIST_DIR}/dx12_shader_id_map.cpp>
                    $<$<BOOL:${BUILD_D3D12}>:${CMAKE_CURRENT_LIST_DIR}/dx12_image_renderer.h>
                    $<$<BOOL:${BUILD_D3D12}>:${CMAKE_CURRENT_LIST_DIR}/dx12_image_renderer.cpp>
                    ${CMAKE_CURRENT_LIST_DIR}/fps_info.h
                    ${CMAKE_CURRENT_LIST_DIR}/fps_info.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_device_util.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_device_util.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_util.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_util.cpp
              )

target_include_directories(gfxrecon_graphics
                           PUBLIC
                               ${CMAKE_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_graphics gfxrecon_util vulkan_registry platform_specific $<$<BOOL:${BUILD_D3D12}>:D3DCompiler.lib>)

common_build_directives(gfxrecon_graphics)

if (${RUN_TESTS})
    add_executable(gfxrecon_graphics_test "")
    target_sources(gfxrecon_graphics_test PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/test/main.cpp)
    target_link_libraries(gfxrecon_graphics_test PRIVATE gfxrecon_graphics)
    common_build_directives(gfxrecon_graphics_test)
    common_test_directives(gfxrecon_graphics_test)
endif()
