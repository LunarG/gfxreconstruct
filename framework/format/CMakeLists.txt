###############################################################################
# Copyright (c) 2018-2020 LunarG, Inc.
# Copyright (c) 2019-2020 Advanced Micro Devices, Inc.
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

add_library(gfxrecon_format STATIC "")

target_sources(gfxrecon_format
               PRIVATE
                    ${CMAKE_CURRENT_LIST_DIR}/api_call_id.h
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_subobject_types.h>
                    ${CMAKE_CURRENT_LIST_DIR}/format.h
                    ${CMAKE_CURRENT_LIST_DIR}/format_json.h
                    ${CMAKE_CURRENT_LIST_DIR}/format_util.h
                    ${CMAKE_CURRENT_LIST_DIR}/format_util.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/platform_types.h
                    ${CMAKE_CURRENT_LIST_DIR}/platform_types_d3d_overrides.h
              )

target_include_directories(gfxrecon_format
                           PUBLIC
                               ${CMAKE_SOURCE_DIR}/framework
                               $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/external/AgilitySDK/inc>)

target_link_libraries(gfxrecon_format gfxrecon_util vulkan_registry platform_specific)

common_build_directives(gfxrecon_format)

if (${RUN_TESTS})
    add_executable(gfxrecon_format_test "")
    target_sources(gfxrecon_format_test PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/test/main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/../../tools/platform_debug_helper.cpp)
    target_link_libraries(gfxrecon_format_test PRIVATE gfxrecon_format)
    if (MSVC)
        # Force inclusion of "gfxrecon_disable_popup_result" variable in linking.
        # On 32-bit windows, MSVC prefixes symbols with "_" but on 64-bit windows it doesn't.
        if(CMAKE_SIZEOF_VOID_P EQUAL 4)
            target_link_options(gfxrecon_format_test PUBLIC "LINKER:/Include:_gfxrecon_disable_popup_result")
        else()
            target_link_options(gfxrecon_format_test PUBLIC "LINKER:/Include:gfxrecon_disable_popup_result")
        endif()
    endif()
    common_build_directives(gfxrecon_format_test)
    common_test_directives(gfxrecon_format_test)
endif()

