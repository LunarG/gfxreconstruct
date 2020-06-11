/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef GFXRECON_DECODE_CUSTOM_STRUCT_DECODER_DECLARATIONS_H
#define GFXRECON_DECODE_CUSTOM_STRUCT_DECODER_DECLARATIONS_H

#include "format/platform_types.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Decoded unions.
struct Decoded_VkClearColorValue;
struct Decoded_VkClearValue;
struct Decoded_VkPipelineExecutableStatisticValueKHR;
struct Decoded_VkDeviceOrHostAddressKHR;
struct Decoded_VkDeviceOrHostAddressConstKHR;
struct Decoded_VkAccelerationStructureGeometryDataKHR;
struct Decoded_VkPerformanceValueDataINTEL;

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkClearColorValue* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkClearValue* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineExecutableStatisticValueKHR* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceOrHostAddressKHR* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceOrHostAddressConstKHR* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAccelerationStructureGeometryDataKHR* wrapper);

// Decoded struct wrappers for Vulkan structures that require special processing.
struct Decoded_VkDescriptorImageInfo;
struct Decoded_VkWriteDescriptorSet;
struct Decoded_VkPerformanceValueINTEL;
struct Decoded_VkAccelerationStructureBuildGeometryInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorImageInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkWriteDescriptorSet* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPerformanceValueINTEL* wrapper);
size_t DecodeStruct(const uint8_t*                                       parameter_buffer,
                    size_t                                               buffer_size,
                    Decoded_VkAccelerationStructureBuildGeometryInfoKHR* wrapper);

// Decoded struct wrappers for SECURITY_ATTRIBUTES and related WIN32 structures.
struct Decoded_ACL;
struct Decoded_SECURITY_DESCRIPTOR;
struct Decoded_SECURITY_ATTRIBUTES;

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_ACL* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_SECURITY_DESCRIPTOR* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_SECURITY_ATTRIBUTES* wrapper);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_CUSTOM_STRUCT_DECODER_DECLARATIONS_H
