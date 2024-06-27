###############################################################################
# Copyright (c) 2018-2023 LunarG, Inc.
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

add_library(gfxrecon_decode STATIC "")

target_sources(gfxrecon_decode
               PRIVATE
                    ${CMAKE_CURRENT_LIST_DIR}/annotation_handler.h
                    ${CMAKE_CURRENT_LIST_DIR}/api_decoder.h
                    ${CMAKE_CURRENT_LIST_DIR}/common_consumer_base.h
                    ${CMAKE_CURRENT_LIST_DIR}/common_handle_mapping_util.h
                    ${CMAKE_CURRENT_LIST_DIR}/common_object_info_table.h
                    ${CMAKE_CURRENT_LIST_DIR}/common_struct_handle_mappers.h
                    ${CMAKE_CURRENT_LIST_DIR}/copy_shaders.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_decoders.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_decoders.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_decoders_forward.h
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/custom_dx12_struct_decoders.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/custom_dx12_struct_decoders_forward.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/custom_dx12_struct_decoders.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/custom_dx12_struct_object_mappers.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/custom_dx12_struct_object_mappers.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/custom_dx12_replay_commands.h>
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_handle_mappers.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_handle_mappers.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_to_json.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_to_json.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/descriptor_update_template_decoder.h
                    ${CMAKE_CURRENT_LIST_DIR}/descriptor_update_template_decoder.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/decode_allocator.h
                    ${CMAKE_CURRENT_LIST_DIR}/decode_allocator.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/decode_api_detection.h
                    ${CMAKE_CURRENT_LIST_DIR}/decode_api_detection.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/info_consumer.h
                    ${CMAKE_CURRENT_LIST_DIR}/info_decoder.h
                    ${CMAKE_CURRENT_LIST_DIR}/info_decoder.cpp
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx_replay_options.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_optimize_options.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_object_info.h>
                    ${CMAKE_CURRENT_LIST_DIR}/file_processor.h
                    ${CMAKE_CURRENT_LIST_DIR}/file_processor.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/preload_file_processor.h
                    ${CMAKE_CURRENT_LIST_DIR}/preload_file_processor.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/file_transformer.h
                    ${CMAKE_CURRENT_LIST_DIR}/file_transformer.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/handle_pointer_decoder.h
                    ${CMAKE_CURRENT_LIST_DIR}/json_writer.h
                    ${CMAKE_CURRENT_LIST_DIR}/json_writer.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/decode_json_util.h
                    ${CMAKE_CURRENT_LIST_DIR}/decode_json_util.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/pointer_decoder_base.h
                    ${CMAKE_CURRENT_LIST_DIR}/pointer_decoder.h
                    ${CMAKE_CURRENT_LIST_DIR}/portability.h
                    ${CMAKE_CURRENT_LIST_DIR}/portability.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/referenced_resource_table.h
                    ${CMAKE_CURRENT_LIST_DIR}/referenced_resource_table.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/referenced_object_table.h
                    ${CMAKE_CURRENT_LIST_DIR}/referenced_object_table.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/replay_options.h
                    ${CMAKE_CURRENT_LIST_DIR}/resource_util.h
                    ${CMAKE_CURRENT_LIST_DIR}/resource_util.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/screenshot_handler.h
                    ${CMAKE_CURRENT_LIST_DIR}/screenshot_handler.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/screenshot_handler_base.h
                    ${CMAKE_CURRENT_LIST_DIR}/screenshot_handler_base.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/string_array_decoder.h
                    ${CMAKE_CURRENT_LIST_DIR}/string_decoder.h
                    ${CMAKE_CURRENT_LIST_DIR}/struct_pointer_decoder.h
                    ${CMAKE_CURRENT_LIST_DIR}/swapchain_image_tracker.h
                    ${CMAKE_CURRENT_LIST_DIR}/value_decoder.h
                    $<$<BOOL:${GFXRECON_TOCPP_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/vulkan_cpp_consumer_base.h>
                    $<$<BOOL:${GFXRECON_TOCPP_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/vulkan_cpp_consumer_base.cpp>
                    $<$<BOOL:${GFXRECON_TOCPP_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/vulkan_cpp_loader_generator.h>
                    $<$<BOOL:${GFXRECON_TOCPP_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/vulkan_cpp_loader_generator.cpp>
                    $<$<BOOL:${GFXRECON_TOCPP_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/vulkan_cpp_structs.h>
                    $<$<BOOL:${GFXRECON_TOCPP_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/vulkan_cpp_structs.cpp>
                    $<$<BOOL:${GFXRECON_TOCPP_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/vulkan_cpp_utilities.h>
                    $<$<BOOL:${GFXRECON_TOCPP_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/vulkan_cpp_utilities.cpp>
                    $<$<BOOL:${GFXRECON_TOCPP_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/vulkan_cpp_util_datapack.h>
                    $<$<BOOL:${GFXRECON_TOCPP_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/vulkan_cpp_util_datapack.cpp>
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_consumer_base.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_pnext_node.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_pnext_typed_node.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_stats_consumer.h
                    ${CMAKE_CURRENT_LIST_DIR}/stat_decoder_base.h
                    ${CMAKE_CURRENT_LIST_DIR}/stat_decoder_base.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/stat_consumer_base.h
                    ${CMAKE_CURRENT_LIST_DIR}/stat_consumer.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_detection_consumer.h
                    ${CMAKE_CURRENT_LIST_DIR}/decoder_util.h
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_acceleration_structure_builder.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_acceleration_structure_builder.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_stats_consumer.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_detection_consumer.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_decoder_base.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_decoder_base.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_consumer_base.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_replay_consumer_base.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_replay_consumer_base.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_resource_value_tracker.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_resource_value_tracker.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_experimental_resource_value_tracker.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_experimental_resource_value_tracker.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_resource_value_mapper.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_resource_value_mapper.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_json_consumer_base.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_json_consumer_base.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_object_mapping_util.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_object_mapping_util.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_enum_util.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_object_scanning_consumer_base.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_object_scanning_consumer.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_object_scanning_consumer.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_descriptor_map.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_descriptor_map.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_tracking_consumer.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_tracking_consumer.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_tracked_object_info_table.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_browse_consumer.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_dump_resources.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/dx12_dump_resources.cpp>
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_decoder_base.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_decoder_base.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_default_allocator.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_default_allocator.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_captured_swapchain.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_captured_swapchain.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_json_consumer_base.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_json_consumer_base.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/marker_json_consumer.h
                    ${CMAKE_CURRENT_LIST_DIR}/metadata_json_consumer.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_enum_util.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_feature_util.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_feature_util.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_handle_mapping_util.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_handle_mapping_util.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_object_cleanup_util.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_object_cleanup_util.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_object_info.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_object_info_table.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_object_info_table_base.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_realign_allocator.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_realign_allocator.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_rebind_allocator.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_rebind_allocator.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_referenced_resource_consumer_base.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_referenced_resource_consumer_base.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_remap_allocator.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_remap_allocator.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_replay_consumer_base.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_replay_consumer_base.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_replay_options.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_replay_dump_resources.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_replay_dump_resources.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_replay_dump_resources_common.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_replay_dump_resources_common.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_replay_dump_resources_draw_calls.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_replay_dump_resources_draw_calls.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_replay_dump_resources_compute_ray_tracing.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_replay_dump_resources_compute_ray_tracing.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_replay_dump_resources_json.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_replay_dump_resources_json.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_resource_allocator.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_resource_initializer.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_resource_initializer.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_resource_tracking_consumer.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_resource_tracking_consumer.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_swapchain.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_swapchain.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_tracked_object_info.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_tracked_object_info_table.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_tracked_object_info.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_tracked_object_info_table.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_virtual_swapchain.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_virtual_swapchain.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_offscreen_swapchain.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_offscreen_swapchain.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/window.h
                    $<$<BOOL:${GFXRECON_TOCPP_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_cpp_consumer.h>
                    $<$<BOOL:${GFXRECON_TOCPP_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_cpp_consumer.cpp>
                    $<$<BOOL:${GFXRECON_TOCPP_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_cpp_structs.h>
                    $<$<BOOL:${GFXRECON_TOCPP_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_cpp_structs.cpp>
                    $<$<BOOL:${GFXRECON_TOCPP_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_cpp_consumer_extension.h>
                    $<$<BOOL:${GFXRECON_TOCPP_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_cpp_consumer_extension.cpp>
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_consumer.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_decoder.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_decoder.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_enum_to_json.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_enum_to_json.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_json_consumer.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_json_consumer.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_feature_util.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_referenced_resource_consumer.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_referenced_resource_consumer.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_replay_consumer.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_replay_consumer.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_replay_dump_resources.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_replay_dump_resources.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_decoders_forward.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_decoders.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_decoders.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_handle_mappers.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_handle_mappers.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_decode_pnext_struct.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_to_json.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_to_json.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_object_info_table_base2.h
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_decoder.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_decoder.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_struct_decoders_forward.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_struct_decoders.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_struct_decoders.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_consumer.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_replay_consumer.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_replay_consumer.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_json_consumer.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_json_consumer.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_enum_to_string.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_enum_to_string.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_struct_object_mappers.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_struct_object_mappers.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_call_id_to_string.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_enum_to_json.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_struct_decoders_to_json.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_struct_decoders_to_json.cpp>
)

if (${GFXRECON_AGS_SUPPORT_FINAL})
target_sources(gfxrecon_decode
               PRIVATE
                    ${CMAKE_CURRENT_LIST_DIR}/custom_ags_decoder.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_ags_decoder.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/custom_ags_struct_decoders.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_ags_struct_decoders.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/custom_ags_consumer_base.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_ags_replay_consumer.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_ags_replay_consumer.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/ags_detection_consumer.h
               )
endif()

if (MSVC)
    # These files may fail to compile with VS2017 and older, requiring the default section limit of 2^16 to be increased.
    set_source_files_properties(${CMAKE_SOURCE_DIR}/framework/generated/generated_decode_pnext_struct.cpp PROPERTIES COMPILE_FLAGS /bigobj)
    set_source_files_properties(${CMAKE_SOURCE_DIR}/framework/generated/generated_dx12_json_consumer.cpp PROPERTIES COMPILE_FLAGS /bigobj)
    set_source_files_properties(${CMAKE_CURRENT_LIST_DIR}/test/main.cpp PROPERTIES COMPILE_FLAGS /bigobj)
    if (MSVC_VERSION LESS 1920)
        set_source_files_properties(${CMAKE_SOURCE_DIR}/framework/generated/generated_decode_pnext_struct.cpp PROPERTIES COMPILE_FLAGS /bigobj)
        set_source_files_properties(${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_replay_consumer.cpp PROPERTIES COMPILE_FLAGS /bigobj)
        set_source_files_properties(${CMAKE_CURRENT_LIST_DIR}/vulkan_object_cleanup_util.cpp PROPERTIES COMPILE_FLAGS /bigobj)
        set_source_files_properties(${CMAKE_CURRENT_LIST_DIR}/vulkan_replay_consumer_base.cpp PROPERTIES COMPILE_FLAGS /bigobj)
    endif()
endif()

if (TARGET ZLIB::ZLIB)
    target_compile_definitions(gfxrecon_decode
                               PUBLIC
                                   GFXRECON_ENABLE_PNG_SCREENSHOT)
endif()

if (WIN32)
    if (CMAKE_SIZEOF_VOID_P EQUAL 8)
        target_include_directories(gfxrecon_decode
                               PUBLIC
                                   ${CMAKE_BINARY_DIR}
                                   ${CMAKE_SOURCE_DIR}/framework
                                   ${CMAKE_SOURCE_DIR}/external
                                   ${CMAKE_SOURCE_DIR}/external/precompiled/win64/include/
                                   $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/external/AgilitySDK/inc>)
    else()
        target_include_directories(gfxrecon_decode
                               PUBLIC
                                   ${CMAKE_BINARY_DIR}
                                   ${CMAKE_SOURCE_DIR}/framework
                                   ${CMAKE_SOURCE_DIR}/external
                                   ${CMAKE_SOURCE_DIR}/external/precompiled/win32/include/
                                   $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/external/AgilitySDK/inc>)
    endif()
elseif(APPLE)
    target_include_directories(gfxrecon_decode
                           PRIVATE
                               ${CMAKE_BINARY_DIR}
                           PUBLIC
                               ${CMAKE_BINARY_DIR}
                               ${CMAKE_SOURCE_DIR}/framework
                               ${CMAKE_SOURCE_DIR}/external
                               ${CMAKE_SOURCE_DIR}/external/precompiled/macos/include/
                               $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/external/AgilitySDK/inc>)
else()
    target_include_directories(gfxrecon_decode
                           PRIVATE
                               ${CMAKE_BINARY_DIR}
                           PUBLIC
                               ${CMAKE_BINARY_DIR}
                               ${CMAKE_SOURCE_DIR}/framework
                               ${CMAKE_SOURCE_DIR}/external
                               ${CMAKE_SOURCE_DIR}/external/precompiled/linux/include/
                               $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/external/AgilitySDK/inc>)
endif()

if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    if (WIN32)
        target_link_directories(gfxrecon_decode
                                PUBLIC
                                    ${CMAKE_SOURCE_DIR}/external/precompiled/win64/lib)
    elseif(APPLE)
        target_link_directories(gfxrecon_decode
                                PUBLIC
                                    ${CMAKE_SOURCE_DIR}/external/precompiled/macos/lib)
    else()
        target_link_directories(gfxrecon_decode
                                PUBLIC
                                    ${CMAKE_SOURCE_DIR}/external/precompiled/linux/lib/x86_64)
    endif()
else (CMAKE_SIZEOF_VOID_P EQUAL 4)
    if (WIN32)
        target_link_directories(gfxrecon_decode
                                PUBLIC
                                    ${CMAKE_SOURCE_DIR}/external/precompiled/win32/lib)
    else()
        target_link_directories(gfxrecon_decode
                                PUBLIC
                                    ${CMAKE_SOURCE_DIR}/external/precompiled/linux/lib/x86)
    endif()
endif()

target_link_libraries(gfxrecon_decode
                        gfxrecon_graphics
                        gfxrecon_format
                        gfxrecon_util
                        vulkan_registry
                        vulkan_memory_allocator
                        platform_specific
                        spirv-reflect-static
                        nlohmann_json::nlohmann_json
                        $<$<BOOL:${D3D12_SUPPORT}>:dxguid.lib>)

common_build_directives(gfxrecon_decode)

if (${RUN_TESTS})
    add_executable(gfxrecon_decode_test "")
    target_sources(gfxrecon_decode_test PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}/test/main.cpp
            ${CMAKE_CURRENT_LIST_DIR}/../../tools/platform_debug_helper.cpp)
    target_link_libraries(gfxrecon_decode_test PRIVATE gfxrecon_decode)
    if (MSVC)
        # Force inclusion of "gfxrecon_disable_popup_result" variable in linking.
        # On 32-bit windows, MSVC prefixes symbols with "_" but on 64-bit windows it doesn't.
        if(CMAKE_SIZEOF_VOID_P EQUAL 4)
            target_link_options(gfxrecon_decode_test PUBLIC "LINKER:/Include:_gfxrecon_disable_popup_result")
        else()
            target_link_options(gfxrecon_decode_test PUBLIC "LINKER:/Include:gfxrecon_disable_popup_result")
        endif()
    endif()
    common_build_directives(gfxrecon_decode_test)
    common_test_directives(gfxrecon_decode_test)
endif()
