/*
** Copyright (c) 2022-2024 LunarG, Inc.
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

#include "custom_vulkan_struct_to_json.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "generated/generated_vulkan_struct_to_json.h"
#include "generated/generated_vulkan_enum_to_json.h"
#include "decode/descriptor_update_template_decoder.h"
#include "decode/custom_vulkan_struct_decoders.h"

#include "util/platform.h"
#include "util/defines.h"

#include "nlohmann/json.hpp"
#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

using util::JsonOptions;

void FieldToJson(nlohmann::ordered_json&                               jdata,
                 VkGeometryTypeKHR                                     discriminant,
                 const Decoded_VkAccelerationStructureGeometryDataKHR* data,
                 const JsonOptions&                                    options)
{
    if (data)
    {
        switch (discriminant)
        {
            case VkGeometryTypeKHR::VK_GEOMETRY_TYPE_TRIANGLES_KHR:
                FieldToJson(jdata["triangles"], data->triangles, options);
                break;
            case VkGeometryTypeKHR::VK_GEOMETRY_TYPE_AABBS_KHR:
                FieldToJson(jdata["aabbs"], data->aabbs, options);
                break;
            case VkGeometryTypeKHR::VK_GEOMETRY_TYPE_INSTANCES_KHR:
                FieldToJson(jdata["instances"], data->instances, options);
                break;
            default:
                jdata = "Unknown GeometryType: " + std::to_string(discriminant);
        }
    }
}

void FieldToJson(nlohmann::ordered_json&                           jdata,
                 const Decoded_VkAccelerationStructureGeometryKHR* data,
                 const JsonOptions&                                options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["geometryType"], decoded_value.geometryType, options);
        FieldToJson(jdata["geometry"], decoded_value.geometryType, meta_struct.geometry, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkClearValue* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["color"], meta_struct.color, options);
        FieldToJson(jdata["depthStencil"]["depth"], decoded_value.depthStencil.depth, options);
        FieldToJson(jdata["depthStencil"]["stencil"], decoded_value.depthStencil.stencil, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkClearColorValue* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["float32"], decoded_value.float32, 4, options);
        FieldToJson(jdata["int32"], decoded_value.int32, 4, options);
        FieldToJson(jdata["uint32"], decoded_value.uint32, 4, options);
    }
}

void FieldToJson(nlohmann::ordered_json&                      jdata,
                 int                                          discriminant,
                 const Decoded_VkDeviceOrHostAddressConstKHR* data,
                 const JsonOptions&                           options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        switch (discriminant)
        {
            case 0:
                FieldToJsonAsHex(jdata["deviceAddress"], decoded_value.deviceAddress, options);
                break;
            case 1:
                FieldToJsonAsHex(jdata["hostAddress"], decoded_value.hostAddress, options);
                break;
        }
    }
}

void FieldToJson(nlohmann::ordered_json&                      jdata,
                 const Decoded_VkDeviceOrHostAddressConstKHR* data,
                 const JsonOptions&                           options)
{
    FieldToJson(jdata, 0, data, options);
}

void FieldToJson(nlohmann::ordered_json&                 jdata,
                 int                                     discriminant,
                 const Decoded_VkDeviceOrHostAddressKHR* data,
                 const JsonOptions&                      options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        switch (discriminant)
        {
            case 0:
                FieldToJsonAsHex(jdata["deviceAddress"], decoded_value.deviceAddress, options);
                break;
            case 1:
                FieldToJsonAsHex(jdata["hostAddress"], decoded_value.hostAddress, options);
                break;
        }
    }
}

void FieldToJson(nlohmann::ordered_json&                 jdata,
                 const Decoded_VkDeviceOrHostAddressKHR* data,
                 const JsonOptions&                      options)
{
    FieldToJson(jdata, 0, data, options);
}

void FieldToJson(nlohmann::ordered_json&                              jdata,
                 VkPipelineExecutableStatisticFormatKHR               discriminant,
                 const Decoded_VkPipelineExecutableStatisticValueKHR* data,
                 const JsonOptions&                                   options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        switch (discriminant)
        {
            case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_BOOL32_KHR:
                jdata["b32"] = static_cast<bool>(decoded_value.b32);
                break;
            case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_INT64_KHR:
                jdata["i64"] = decoded_value.i64;
                break;
            case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_UINT64_KHR:
                jdata["u64"] = decoded_value.u64;
                break;
            case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_FLOAT64_KHR:
                jdata["f64"] = decoded_value.f64;
                break;
            case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_MAX_ENUM_KHR:
                GFXRECON_LOG_WARNING("Invalid format: VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_MAX_ENUM_KHR");
        }
    }
}

void FieldToJson(nlohmann::ordered_json&                         jdata,
                 const Decoded_VkPipelineExecutableStatisticKHR* data,
                 const JsonOptions&                              options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["name"], &meta_struct.name, options);
        FieldToJson(jdata["description"], &meta_struct.description, options);
        FieldToJson(jdata["format"], decoded_value.format, options);
        FieldToJson(jdata["value"], decoded_value.format, meta_struct.value, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorImageInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        HandleToJson(jdata["sampler"], meta_struct.sampler, options);
        HandleToJson(jdata["imageView"], meta_struct.imageView, options);
        HandleToJson(jdata["imageLayout"], decoded_value.imageLayout, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkWriteDescriptorSet* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        HandleToJson(jdata["dstSet"], meta_struct.dstSet, options);
        FieldToJson(jdata["dstBinding"], decoded_value.dstBinding, options);
        FieldToJson(jdata["dstArrayElement"], decoded_value.dstArrayElement, options);
        FieldToJson(jdata["descriptorCount"], decoded_value.descriptorCount, options);
        FieldToJson(jdata["descriptorType"], decoded_value.descriptorType, options);
        switch (decoded_value.descriptorType)
        {
            case VK_DESCRIPTOR_TYPE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            case VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM:
            case VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM:
                FieldToJson(jdata["pImageInfo"], meta_struct.pImageInfo, options);
                break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                FieldToJson(jdata["pBufferInfo"], meta_struct.pBufferInfo, options);
                break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                HandleToJson(jdata["pTexelBufferView"], &meta_struct.pTexelBufferView, options);
                break;
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
            case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                // Nothing to do here for acceleration-structures and inline-uniform-blocks,
                // as the rest of the data is stored in the pNext chain
                break;
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
            case VK_DESCRIPTOR_TYPE_MUTABLE_EXT:
                GFXRECON_LOG_WARNING("Descriptor type not supported at " __FILE__ ", line: %d.", __LINE__);
                break;
            case VK_DESCRIPTOR_TYPE_MAX_ENUM:
                GFXRECON_LOG_WARNING("Invalid descriptor type: VK_DESCRIPTOR_TYPE_MAX_ENUM");
        }
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json&                    jdata,
                 const VkPerformanceValueTypeINTEL          discriminant,
                 const Decoded_VkPerformanceValueDataINTEL* data,
                 const JsonOptions&                         options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        switch (discriminant)
        {
            case VK_PERFORMANCE_VALUE_TYPE_UINT32_INTEL:
                FieldToJson(jdata["value32"], decoded_value.value32, options);
                break;
            case VK_PERFORMANCE_VALUE_TYPE_UINT64_INTEL:
                FieldToJson(jdata["value64"], decoded_value.value64, options);
                break;
            case VK_PERFORMANCE_VALUE_TYPE_FLOAT_INTEL:
                FieldToJson(jdata["valueFloat"], decoded_value.valueFloat, options);
                break;
            case VK_PERFORMANCE_VALUE_TYPE_BOOL_INTEL:
                FieldToJson(jdata["valueBool"], decoded_value.valueBool, options);
                break;
            case VK_PERFORMANCE_VALUE_TYPE_STRING_INTEL:
                FieldToJson(jdata["valueString"], meta_struct.valueString, options);
                break;
            case VK_PERFORMANCE_VALUE_TYPE_MAX_ENUM_INTEL:
                GFXRECON_LOG_WARNING("Invalid performance value type: VK_PERFORMANCE_VALUE_TYPE_MAX_ENUM_INTEL");
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPerformanceValueINTEL* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["data"], decoded_value.type, meta_struct.data, options);
    }
}

void FieldToJson(nlohmann::ordered_json&                 jdata,
                 const Decoded_VkShaderModuleCreateInfo* data,
                 const JsonOptions&                      options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkShaderModuleCreateFlags_t(), jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["codeSize"], decoded_value.codeSize, options);
        // Use "[Binary data]" as placeholder. It will be replaced with a file path if the JSON
        // consumer decides to dump binaries in separate files.
        FieldToJson(jdata["pCode"], "[Binary data]", options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_SECURITY_ATTRIBUTES* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        jdata["bInheritHandle"]   = static_cast<bool>(decoded_value.bInheritHandle);
        FieldToJson(jdata["nLength"], decoded_value.nLength, options);
        FieldToJson(jdata["lpSecurityDescriptor"], meta_struct.lpSecurityDescriptor->GetAddress(), options);
    }
}

void FieldToJson(nlohmann::ordered_json&                  jdata,
                 const Decoded_VkPipelineCacheCreateInfo* data,
                 const JsonOptions&                       options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineCacheCreateFlags_t(), jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["initialDataSize"], decoded_value.initialDataSize, options);
        // Use "[Binary data]" as placeholder. It will be replaced with a file path if the JSON
        // consumer decides to dump binaries in separate files.
        FieldToJson(jdata["pInitialData"], "[Binary data]", options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json&                      jdata,
                 const DescriptorUpdateTemplateDecoder* const pData,
                 const JsonOptions&                           options)
{
    if (pData)
    {
        const size_t                        image_info_count = pData->GetImageInfoCount();
        std::vector<nlohmann::ordered_json> image_infos(image_info_count);

        for (size_t image_info_index = 0; image_info_index < image_info_count; ++image_info_index)
        {
            FieldToJson(
                image_infos[image_info_index], pData->GetImageInfoMetaStructPointer() + image_info_index, options);
        }
        jdata["imageInfos"] = image_infos;

        const size_t                        buffer_info_count = pData->GetBufferInfoCount();
        std::vector<nlohmann::ordered_json> buffer_infos(buffer_info_count);

        for (size_t buffer_info_index = 0; buffer_info_index < buffer_info_count; ++buffer_info_index)
        {
            FieldToJson(
                buffer_infos[buffer_info_index], pData->GetBufferInfoMetaStructPointer() + buffer_info_index, options);
        }
        jdata["bufferInfos"] = buffer_infos;

        const size_t texel_buffer_view_count = pData->GetTexelBufferViewCount();
        if (texel_buffer_view_count > 0)
        {
            HandleToJson(
                jdata["bufferViews"], pData->GetTexelBufferViewHandleIdsPointer(), texel_buffer_view_count, options);
        }

        const size_t acceleration_structure_count = pData->GetAccelerationStructureKHRCount();
        if (acceleration_structure_count > 0)
        {
            HandleToJson(jdata["accelStructViews"],
                         pData->GetAccelerationStructureKHRHandleIdsPointer(),
                         acceleration_structure_count,
                         options);
        }

        const size_t inline_uniform_block_num_bytes = pData->GetInlineUniformBlockCount();
        if (inline_uniform_block_num_bytes > 0)
        {
            jdata["inlineUniformBlock"] =
                std::vector<uint8_t>(pData->GetInlineUniformBlockPointer(),
                                     pData->GetInlineUniformBlockPointer() + inline_uniform_block_num_bytes);
        }
    }
    else
    {
        jdata = nullptr;
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
