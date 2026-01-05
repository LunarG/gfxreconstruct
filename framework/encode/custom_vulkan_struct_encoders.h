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

#ifndef GFXRECON_ENCODE_CUSTOM_STRUCT_ENCODERS_H
#define GFXRECON_ENCODE_CUSTOM_STRUCT_ENCODERS_H

#include "encode/parameter_encoder.h"
#include "format/platform_types.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// Unions.
void EncodeStruct(ParameterEncoder* encoder, const VkClearColorValue& value);
void EncodeStruct(ParameterEncoder* encoder, const VkClearValue& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineExecutableStatisticValueKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceOrHostAddressKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceOrHostAddressConstKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureMotionInstanceNV& value);

// Vulkan structures that require special processing that the code generator cannot infer from the XML registry.
void EncodeStruct(ParameterEncoder* encoder, VkDescriptorType type, const VkDescriptorImageInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkWriteDescriptorSet& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPerformanceValueINTEL& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureGeometryKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPushDescriptorSetWithTemplateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkIndirectExecutionSetCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkIndirectCommandsLayoutTokenEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCopyMemoryToImageInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCopyImageToMemoryInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkLayerSettingEXT& value);

// Platform defined structures that are external to Vulkan.
void EncodeStruct(ParameterEncoder* encoder, const ACL& value);
void EncodeStruct(ParameterEncoder* encoder, const SECURITY_DESCRIPTOR& value);
void EncodeStruct(ParameterEncoder* encoder, const SECURITY_ATTRIBUTES& value);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_CUSTOM_STRUCT_ENCODERS_H
