###############################################################################
# Copyright (c) 2018-2022 LunarG, Inc.
# Copyright (c) 2019-2023 Advanced Micro Devices, Inc.
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

add_library(gfxrecon_encode STATIC "")

target_sources(gfxrecon_encode
               PRIVATE
                    ${CMAKE_CURRENT_LIST_DIR}/api_capture_manager.h
                    ${CMAKE_CURRENT_LIST_DIR}/api_capture_manager.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/capture_manager.h
                    ${CMAKE_CURRENT_LIST_DIR}/capture_manager.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/capture_settings.h
                    ${CMAKE_CURRENT_LIST_DIR}/capture_settings.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/custom_openxr_encoder_commands.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_openxr_api_call_encoders.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_openxr_api_call_encoders.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/custom_openxr_struct_encoders.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_openxr_struct_encoders.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/custom_openxr_struct_handle_wrappers.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_openxr_struct_handle_wrappers.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_encoder_commands.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_api_call_encoders.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_api_call_encoders.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_array_size_2d.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_command_buffer_util.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_encoders.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_encoders.cpp
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/custom_dx12_api_call_encoders.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/custom_dx12_api_call_encoders.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/custom_dx12_array_size_2d.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/custom_dx12_wrapper_commands.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/custom_dx12_struct_encoders.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/custom_dx12_struct_encoders.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/custom_dx12_struct_unwrappers.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/custom_dx12_struct_unwrappers.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/custom_dx12_command_list_util.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/custom_dx12_command_list_util.cpp>
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_handle_wrappers.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_handle_wrappers.cpp
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/d3d12_capture_manager.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/d3d12_capture_manager.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/d3d12_dispatch_table.h>
                    ${CMAKE_CURRENT_LIST_DIR}/descriptor_update_template_info.h
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_dll_initializer.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_object_wrapper_info.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_object_wrapper_resources.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_object_wrapper_resources.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_object_wrapper_util.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_object_wrapper_util.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_state_table_base.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_state_tracker.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_state_tracker.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_state_tracker_initializers.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_state_writer.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_state_writer.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dxgi_dispatch_table.h>
                    $<$<BOOL:${GFXRECON_AGS_SUPPORT_FINAL}>:${CMAKE_CURRENT_LIST_DIR}/ags_dispatch_table.h>
                    $<$<BOOL:${GFXRECON_AGS_SUPPORT_FINAL}>:${CMAKE_CURRENT_LIST_DIR}/custom_ags_wrappers.h>
                    $<$<BOOL:${GFXRECON_AGS_SUPPORT_FINAL}>:${CMAKE_CURRENT_LIST_DIR}/custom_ags_wrappers.cpp>
                    $<$<BOOL:${GFXRECON_AGS_SUPPORT_FINAL}>:${CMAKE_CURRENT_LIST_DIR}/custom_ags_api_call_encoders.h>
                    $<$<BOOL:${GFXRECON_AGS_SUPPORT_FINAL}>:${CMAKE_CURRENT_LIST_DIR}/custom_ags_api_call_encoders.cpp>
                    $<$<BOOL:${GFXRECON_AGS_SUPPORT_FINAL}>:${CMAKE_CURRENT_LIST_DIR}/custom_ags_state_table.h>
                    $<$<BOOL:${GFXRECON_AGS_SUPPORT_FINAL}>:${CMAKE_CURRENT_LIST_DIR}/custom_ags_state_table.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/iunknown_wrapper.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/iunknown_wrapper.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_rv_annotator.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_rv_annotator.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_rv_annotation_util.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_rv_annotation_util.cpp>
                    ${CMAKE_CURRENT_LIST_DIR}/handle_unwrap_memory.h
                    ${CMAKE_CURRENT_LIST_DIR}/openxr_capture_manager.h
                    ${CMAKE_CURRENT_LIST_DIR}/openxr_capture_manager.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/openxr_handle_wrappers.h
                    ${CMAKE_CURRENT_LIST_DIR}/openxr_handle_wrapper_util.h
                    ${CMAKE_CURRENT_LIST_DIR}/openxr_handle_wrapper_util.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/openxr_state_info.h
                    ${CMAKE_CURRENT_LIST_DIR}/openxr_state_table_base.h
                    ${CMAKE_CURRENT_LIST_DIR}/openxr_state_tracker.h
                    ${CMAKE_CURRENT_LIST_DIR}/openxr_state_tracker.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/openxr_state_writer.h
                    ${CMAKE_CURRENT_LIST_DIR}/openxr_state_writer.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/parameter_buffer.h
                    ${CMAKE_CURRENT_LIST_DIR}/parameter_encoder.h
                    ${CMAKE_CURRENT_LIST_DIR}/scoped_destroy_lock.h
                    ${CMAKE_CURRENT_LIST_DIR}/scoped_destroy_lock.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/struct_pointer_encoder.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_capture_manager.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_capture_manager.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_handle_wrappers.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_handle_wrapper_util.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_handle_wrapper_util.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_state_info.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_state_table_base.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_state_tracker.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_state_tracker.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_state_tracker_initializers.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_state_writer.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_state_writer.cpp
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_api_call_encoders.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_api_call_encoders.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_struct_unwrappers.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_struct_wrappers.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_struct_wrappers.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_struct_unwrappers.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_wrappers.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_wrappers.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_wrapper_creators.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_wrapper_creators.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_add_entries.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_state_table.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_command_list_util.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_command_list_util.cpp>
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_openxr_api_call_encoders.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_openxr_api_call_encoders.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_openxr_base_header_struct_encoders.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_openxr_struct_encoders.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_openxr_struct_encoders.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_openxr_struct_handle_wrappers.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_openxr_struct_handle_wrappers.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_openxr_struct_next_encoder.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_openxr_struct_trackers.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_openxr_struct_trackers.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_openxr_state_table.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_encode_pnext_struct.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_api_call_encoders.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_api_call_encoders.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_command_buffer_util.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_command_buffer_util.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_dispatch_table.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_encoders.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_encoders.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_handle_wrappers.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_handle_wrappers.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_trackers.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_trackers.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_state_table.h

)

if (MSVC)
    # Increase object size limit to handle large numbers of template function instantiations.
    set_source_files_properties(${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_api_call_encoders.cpp PROPERTIES COMPILE_FLAGS /bigobj)
    set_source_files_properties(${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_wrappers.cpp PROPERTIES COMPILE_FLAGS /bigobj)
    set_source_files_properties(${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_api_call_encoders.cpp PROPERTIES COMPILE_FLAGS /bigobj)
endif()

target_include_directories(gfxrecon_encode
                           PUBLIC
                               ${CMAKE_BINARY_DIR}
                               ${CMAKE_SOURCE_DIR}/framework
                               $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/external/AgilitySDK/inc>)

target_link_libraries(gfxrecon_encode
                        gfxrecon_graphics
                        gfxrecon_format
                        gfxrecon_util
                        vulkan_registry
                        openxr_headers
                        platform_specific)

common_build_directives(gfxrecon_encode)

if (${RUN_TESTS})
    add_executable(gfxrecon_encode_test "")
    target_sources(gfxrecon_encode_test PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/test/main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/../../tools/platform_debug_helper.cpp)
    target_link_libraries(gfxrecon_encode_test PRIVATE gfxrecon_encode)
    if (MSVC)
        # Force inclusion of "gfxrecon_disable_popup_result" variable in linking.
        # On 32-bit windows, MSVC prefixes symbols with "_" but on 64-bit windows it doesn't.
        if(CMAKE_SIZEOF_VOID_P EQUAL 4)
            target_link_options(gfxrecon_encode_test PUBLIC "LINKER:/Include:_gfxrecon_disable_popup_result")
        else()
            target_link_options(gfxrecon_encode_test PUBLIC "LINKER:/Include:gfxrecon_disable_popup_result")
        endif()
    endif()
    common_build_directives(gfxrecon_encode_test)
    common_test_directives(gfxrecon_encode_test)
endif()
