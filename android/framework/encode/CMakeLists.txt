###############################################################################
# Copyright (c) 2018-2021 LunarG, Inc.
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
                   ${GFXRECON_SOURCE_DIR}/framework/encode/capture_manager.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/capture_manager.cpp               
                   ${GFXRECON_SOURCE_DIR}/framework/encode/capture_settings.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/capture_settings.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_encoder_commands.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_api_call_encoders.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_api_call_encoders.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_array_size_2d.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_struct_encoders.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_struct_encoders.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_struct_handle_wrappers.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_struct_handle_wrappers.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/encode/descriptor_update_template_info.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/handle_unwrap_memory.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/parameter_buffer.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/parameter_encoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/struct_pointer_encoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/deferred_operation.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/deferred_operation_create_ray_tracing_pipelines.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/deferred_operation_manager.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/deferred_operation.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_capture_manager.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_capture_manager.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_handle_wrappers.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_handle_wrapper_util.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_handle_wrapper_util.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_state_info.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_state_table_base.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_state_tracker.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_state_tracker.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_state_writer.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_state_writer.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_encode_pnext_struct.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_api_call_encoders.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_api_call_encoders.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_command_buffer_util.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_command_buffer_util.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_dispatch_table.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_encoders.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_encoders.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_handle_wrappers.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_handle_wrappers.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_state_table.h
              )

target_include_directories(gfxrecon_encode
                           PUBLIC
                               ${CMAKE_BINARY_DIR}
                               ${GFXRECON_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_encode gfxrecon_graphics gfxrecon_format gfxrecon_util vulkan_registry platform_specific android)
