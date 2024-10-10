/*
** Copyright (c) 2022-2023 LunarG, Inc.
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
#ifndef GFXRECON_DECODE_CUSTOM_VULKAN_STRUCT_TO_JSON_H
#define GFXRECON_DECODE_CUSTOM_VULKAN_STRUCT_TO_JSON_H

#include "decode/custom_vulkan_struct_decoders.h"
#include "generated/generated_vulkan_enum_to_json.h"
#include "generated/generated_vulkan_struct_to_json.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "decode/decode_json_util.h"

#include "util/defines.h"
#include "util/json_util.h"
#include "util/to_string.h"

#include "nlohmann/json.hpp"
#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class DescriptorUpdateTemplateDecoder;

void FieldToJson(nlohmann::ordered_json&     jdata,
                 const Decoded_VkClearValue* data,
                 const util::JsonOptions&    options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&          jdata,
                 const Decoded_VkClearColorValue* data,
                 const util::JsonOptions&         options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&                      jdata,
                 int                                          discriminant,
                 const Decoded_VkDeviceOrHostAddressConstKHR* data,
                 const util::JsonOptions&                     options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&                      jdata,
                 const Decoded_VkDeviceOrHostAddressConstKHR* data,
                 const util::JsonOptions&                     options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&                 jdata,
                 int                                     discriminant,
                 const Decoded_VkDeviceOrHostAddressKHR* data,
                 const util::JsonOptions&                options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&                 jdata,
                 const Decoded_VkDeviceOrHostAddressKHR* data,
                 const util::JsonOptions&                options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&                              jdata,
                 VkPipelineExecutableStatisticFormatKHR               discriminant,
                 const Decoded_VkPipelineExecutableStatisticValueKHR* data,
                 const util::JsonOptions&                             options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&                         jdata,
                 const Decoded_VkPipelineExecutableStatisticKHR* data,
                 const util::JsonOptions&                        options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&            jdata,
                 const Decoded_SECURITY_ATTRIBUTES* data,
                 const util::JsonOptions&           options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&                               jdata,
                 const Decoded_VkAccelerationStructureGeometryDataKHR* data,
                 const util::JsonOptions&                              options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&                           jdata,
                 const Decoded_VkAccelerationStructureGeometryKHR* data,
                 const util::JsonOptions&                          options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&              jdata,
                 const Decoded_VkDescriptorImageInfo* data,
                 const util::JsonOptions&             options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&             jdata,
                 const Decoded_VkWriteDescriptorSet* data,
                 const util::JsonOptions&            options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&                jdata,
                 const Decoded_VkPerformanceValueINTEL* data,
                 const util::JsonOptions&               options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&                 jdata,
                 const Decoded_VkShaderModuleCreateInfo* data,
                 const util::JsonOptions&                options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&                  jdata,
                 const Decoded_VkPipelineCacheCreateInfo* data,
                 const util::JsonOptions&                 options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&                      jdata,
                 const DescriptorUpdateTemplateDecoder* const pData,
                 const util::JsonOptions&                     options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&                                     jdata,
                 const Decoded_VkPushDescriptorSetWithTemplateInfoKHR* const pData,
                 const util::JsonOptions&                                    options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&                                  jdata,
                 const Decoded_VkIndirectExecutionSetCreateInfoEXT* const pData,
                 const util::JsonOptions&                                 options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&                               jdata,
                 const Decoded_VkIndirectCommandsLayoutTokenEXT* const pData,
                 const util::JsonOptions&                              options = util::JsonOptions());

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_CUSTOM_VULKAN_STRUCT_TO_JSON_H
