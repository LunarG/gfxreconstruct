/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
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
struct Decoded_VkAccelerationStructureMotionInstanceNV;
struct Decoded_VkPerformanceValueDataINTEL;

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkClearColorValue* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkClearValue* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineExecutableStatisticValueKHR* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceOrHostAddressKHR* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceOrHostAddressConstKHR* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAccelerationStructureGeometryDataKHR* wrapper);
size_t
DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAccelerationStructureMotionInstanceNV* wrapper);

// Decoded struct wrappers for Vulkan structures that require special processing.
struct Decoded_VkDescriptorImageInfo;
struct Decoded_VkWriteDescriptorSet;
struct Decoded_VkPerformanceValueINTEL;
struct Decoded_VkAccelerationStructureGeometryKHR;
struct Decoded_VkPushDescriptorSetWithTemplateInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorImageInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkWriteDescriptorSet* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPerformanceValueINTEL* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAccelerationStructureGeometryKHR* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPushDescriptorSetWithTemplateInfoKHR* wrapper);

// Decoded struct wrappers for SECURITY_ATTRIBUTES and related WIN32 structures.
struct Decoded_ACL;
struct Decoded_SECURITY_DESCRIPTOR;
struct Decoded_SECURITY_ATTRIBUTES;

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_ACL* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_SECURITY_DESCRIPTOR* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_SECURITY_ATTRIBUTES* wrapper);

// Preload
size_t PreloadDecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkClearColorValue* wrapper);
size_t PreloadDecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkClearValue* wrapper);
size_t
PreloadDecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineExecutableStatisticValueKHR* wrapper);
size_t PreloadDecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceOrHostAddressKHR* wrapper);
size_t PreloadDecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceOrHostAddressConstKHR* wrapper);
size_t
PreloadDecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAccelerationStructureGeometryDataKHR* wrapper);
size_t PreloadDecodeStruct(const uint8_t*                                   buffer,
                           size_t                                           buffer_size,
                           Decoded_VkAccelerationStructureMotionInstanceNV* wrapper);

size_t PreloadDecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorImageInfo* wrapper);
size_t PreloadDecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkWriteDescriptorSet* wrapper);
size_t
PreloadDecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPerformanceValueINTEL* wrapper);
size_t
PreloadDecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAccelerationStructureGeometryKHR* wrapper);
size_t
PreloadDecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPushDescriptorSetWithTemplateInfoKHR* wrapper);

size_t PreloadDecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_ACL* wrapper);
size_t PreloadDecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_SECURITY_DESCRIPTOR* wrapper);
size_t PreloadDecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_SECURITY_ATTRIBUTES* wrapper);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_CUSTOM_STRUCT_DECODER_DECLARATIONS_H
