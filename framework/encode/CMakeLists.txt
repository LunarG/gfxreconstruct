###############################################################################
# Copyright (c) 2018-2022 LunarG, Inc.
# Copyright (c) 2019-2021 Advanced Micro Devices, Inc.
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
                    ${CMAKE_CURRENT_LIST_DIR}/capture_manager.h
                    ${CMAKE_CURRENT_LIST_DIR}/capture_manager.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/capture_settings.h
                    ${CMAKE_CURRENT_LIST_DIR}/capture_settings.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_encoder_commands.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_api_call_encoders.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_api_call_encoders.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_array_size_2d.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_command_buffer_util.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_encoders.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_encoders.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_handle_wrappers.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_handle_wrappers.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/descriptor_update_template_info.h
                    ${CMAKE_CURRENT_LIST_DIR}/handle_unwrap_memory.h
                    ${CMAKE_CURRENT_LIST_DIR}/parameter_buffer.h
                    ${CMAKE_CURRENT_LIST_DIR}/parameter_encoder.h
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
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_state_table.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_wrapper_handle_list.h

)

if (MSVC AND (MSVC_VERSION LESS 1920))
    # This file may fail to compile with VS2017 and older, requiring the default section limit of 2^16 to be increased.
    set_source_files_properties(${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_api_call_encoders.cpp PROPERTIES COMPILE_FLAGS /bigobj)
endif()

target_include_directories(gfxrecon_encode
                           PUBLIC
                               ${CMAKE_BINARY_DIR}
                               ${CMAKE_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_encode gfxrecon_graphics gfxrecon_format gfxrecon_util vulkan_registry platform_specific)

common_build_directives(gfxrecon_encode)

if (${RUN_TESTS})
    add_executable(gfxrecon_encode_test "")
    target_sources(gfxrecon_encode_test PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/test/main.cpp)
    target_link_libraries(gfxrecon_encode_test PRIVATE gfxrecon_encode)
    common_build_directives(gfxrecon_encode_test)
    common_test_directives(gfxrecon_encode_test)
endif()

