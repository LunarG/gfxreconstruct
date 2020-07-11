###############################################################################
# Copyright (c) 2018-2020 LunarG, Inc.
# Copyright (c) 2019-2020 Advanced Micro Devices, Inc.
# All rights reserved
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Author: LunarG Team
# Author: AMD Developer Tools Team
# Description: CMake script for framework util target
###############################################################################

add_library(gfxrecon_decode STATIC "")

target_sources(gfxrecon_decode
               PRIVATE
                    ${CMAKE_CURRENT_LIST_DIR}/api_decoder.h
                    ${CMAKE_CURRENT_LIST_DIR}/copy_shaders.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_decoders.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_decoders.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_decoders_forward.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_handle_mappers.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_handle_mappers.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/compression_converter.h
                    ${CMAKE_CURRENT_LIST_DIR}/compression_converter.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/descriptor_update_template_decoder.h
                    ${CMAKE_CURRENT_LIST_DIR}/descriptor_update_template_decoder.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/file_processor.h
                    ${CMAKE_CURRENT_LIST_DIR}/file_processor.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/handle_pointer_decoder.h
                    ${CMAKE_CURRENT_LIST_DIR}/pnext_node.h
                    ${CMAKE_CURRENT_LIST_DIR}/pnext_typed_node.h
                    ${CMAKE_CURRENT_LIST_DIR}/pointer_decoder_base.h
                    ${CMAKE_CURRENT_LIST_DIR}/pointer_decoder.h
                    ${CMAKE_CURRENT_LIST_DIR}/portability.h
                    ${CMAKE_CURRENT_LIST_DIR}/portability.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/resource_util.h
                    ${CMAKE_CURRENT_LIST_DIR}/resource_util.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/string_array_decoder.h
                    ${CMAKE_CURRENT_LIST_DIR}/string_decoder.h
                    ${CMAKE_CURRENT_LIST_DIR}/struct_pointer_decoder.h
                    ${CMAKE_CURRENT_LIST_DIR}/swapchain_image_tracker.h
                    ${CMAKE_CURRENT_LIST_DIR}/value_decoder.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_ascii_consumer_base.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_ascii_consumer_base.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_consumer_base.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_decoder_base.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_decoder_base.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_default_allocator.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_default_allocator.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_enum_util.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_handle_mapping_util.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_object_info.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_object_info_table.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_realign_allocator.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_realign_allocator.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_rebind_allocator.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_rebind_allocator.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_remap_allocator.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_remap_allocator.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_replay_consumer_base.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_replay_consumer_base.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_replay_options.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_resource_allocator.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_resource_initializer.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_resource_initializer.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_resource_tracking_consumer.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_resource_tracking_consumer.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_tracked_object_info.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_tracked_object_info_table.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_tracked_object_info.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_tracked_object_info_table.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/window.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_ascii_consumer.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_ascii_consumer.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_consumer.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_decoder.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_decoder.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_replay_consumer.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_replay_consumer.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_decoders_forward.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_decoders.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_decoders.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_handle_mappers.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_handle_mappers.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_decode_pnext_struct.cpp
)

if (MSVC AND (MSVC_VERSION LESS 1910))
    # This file fails to compile with VS2015, requiring the default section limit of 2^16 to be increased.
    set_source_files_properties(${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_replay_consumer.cpp PROPERTIES COMPILE_FLAGS /bigobj)
    set_source_files_properties(vulkan_replay_consumer_base.cpp PROPERTIES COMPILE_FLAGS /bigobj)
endif()

target_include_directories(gfxrecon_decode
                           PUBLIC
                               ${CMAKE_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_decode gfxrecon_format gfxrecon_util vulkan_registry vulkan_memory_allocator platform_specific)

common_build_directives(gfxrecon_decode)

if (${RUN_TESTS})
    add_executable(gfxrecon_decode_test "")
    target_sources(gfxrecon_decode_test PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}/test/main.cpp)
    common_build_directives(gfxrecon_decode_test)
    common_test_directives(gfxrecon_decode_test)
endif()
