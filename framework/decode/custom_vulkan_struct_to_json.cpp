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

#include "nlohmann/json.hpp"
#include "vulkan/vulkan.h"
#include <span>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

using util::FieldToJson;
using util::FieldToJsonAsHex;
using util::HandleToJson;
using util::RepresentBinaryFile;

void FieldToJson(nlohmann::ordered_json&                               jdata,
                 VkGeometryTypeKHR                                     discriminant,
                 const Decoded_VkAccelerationStructureGeometryDataKHR* data)
{
    if (data)
    {
        switch (discriminant)
        {
            case VkGeometryTypeKHR::VK_GEOMETRY_TYPE_TRIANGLES_KHR:
                FieldToJson(jdata["triangles"], data->triangles);
                break;
            case VkGeometryTypeKHR::VK_GEOMETRY_TYPE_AABBS_KHR:
                FieldToJson(jdata["aabbs"], data->aabbs);
                break;
            case VkGeometryTypeKHR::VK_GEOMETRY_TYPE_INSTANCES_KHR:
                FieldToJson(jdata["instances"], data->instances);
                break;
            default:
                jdata = "Unknown GeometryType: " + std::to_string(discriminant);
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureGeometryKHR* data)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType);
        FieldToJson(jdata["geometryType"], decoded_value.geometryType);
        FieldToJson(jdata["geometry"], decoded_value.geometryType, meta_struct.geometry);
        FieldToJson(jdata["pNext"], meta_struct.pNext);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkClearValue* data)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["color"], meta_struct.color);
        FieldToJson(jdata["depthStencil"]["depth"], decoded_value.depthStencil.depth);
        FieldToJson(jdata["depthStencil"]["stencil"], decoded_value.depthStencil.stencil);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkClearColorValue* data)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["float32"], decoded_value.float32, 4);
        FieldToJson(jdata["int32"], decoded_value.int32, 4);
        FieldToJson(jdata["uint32"], decoded_value.uint32, 4);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, int discriminant, const Decoded_VkDeviceOrHostAddressConstKHR* data)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        switch (discriminant)
        {
            case 0:
                FieldToJsonAsHex(jdata["deviceAddress"], decoded_value.deviceAddress);
                break;
            case 1:
                FieldToJsonAsHex(jdata["hostAddress"], decoded_value.hostAddress);
                break;
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceOrHostAddressConstKHR* data)
{
    FieldToJson(jdata, 0, data);
}

void FieldToJson(nlohmann::ordered_json& jdata, int discriminant, const Decoded_VkDeviceOrHostAddressKHR* data)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        switch (discriminant)
        {
            case 0:
                FieldToJsonAsHex(jdata["deviceAddress"], decoded_value.deviceAddress);
                break;
            case 1:
                FieldToJsonAsHex(jdata["hostAddress"], decoded_value.hostAddress);
                break;
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceOrHostAddressKHR* data)
{
    FieldToJson(jdata, 0, data);
}

void FieldToJson(nlohmann::ordered_json&                              jdata,
                 VkPipelineExecutableStatisticFormatKHR               discriminant,
                 const Decoded_VkPipelineExecutableStatisticValueKHR* data)
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

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineExecutableStatisticKHR* data)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType);
        FieldToJson(jdata["name"], &meta_struct.name);
        FieldToJson(jdata["description"], &meta_struct.description);
        FieldToJson(jdata["format"], decoded_value.format);
        FieldToJson(jdata["value"], decoded_value.format, meta_struct.value);
        FieldToJson(jdata["pNext"], meta_struct.pNext);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorImageInfo* data)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        HandleToJson(jdata["sampler"], meta_struct.sampler);
        HandleToJson(jdata["imageView"], meta_struct.imageView);
        HandleToJson(jdata["imageLayout"], decoded_value.imageLayout);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkWriteDescriptorSet* data)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType);
        HandleToJson(jdata["dstSet"], meta_struct.dstSet);
        FieldToJson(jdata["dstBinding"], decoded_value.dstBinding);
        FieldToJson(jdata["dstArrayElement"], decoded_value.dstArrayElement);
        FieldToJson(jdata["descriptorCount"], decoded_value.descriptorCount);
        FieldToJson(jdata["descriptorType"], decoded_value.descriptorType);
        switch (decoded_value.descriptorType)
        {
            case VK_DESCRIPTOR_TYPE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            case VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM:
            case VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM:
                FieldToJson(jdata["pImageInfo"], meta_struct.pImageInfo);
                break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                FieldToJson(jdata["pBufferInfo"], meta_struct.pBufferInfo);
                break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                HandleToJson(jdata["pTexelBufferView"], &meta_struct.pTexelBufferView);
                break;
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
            case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                // Nothing to do here for acceleration-structures and inline-uniform-blocks,
                // as the rest of the data is stored in the pNext chain
                break;
            case VK_DESCRIPTOR_TYPE_TENSOR_ARM:
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
            case VK_DESCRIPTOR_TYPE_MUTABLE_EXT:
            case VK_DESCRIPTOR_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_NV:
                GFXRECON_LOG_WARNING("Descriptor type not supported at " __FILE__ ", line: %d.", __LINE__);
                break;
            case VK_DESCRIPTOR_TYPE_MAX_ENUM:
                GFXRECON_LOG_WARNING("Invalid descriptor type: VK_DESCRIPTOR_TYPE_MAX_ENUM");
        }
        FieldToJson(jdata["pNext"], meta_struct.pNext);
    }
}

void FieldToJson(nlohmann::ordered_json&                    jdata,
                 const VkPerformanceValueTypeINTEL          discriminant,
                 const Decoded_VkPerformanceValueDataINTEL* data)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        switch (discriminant)
        {
            case VK_PERFORMANCE_VALUE_TYPE_UINT32_INTEL:
                FieldToJson(jdata["value32"], decoded_value.value32);
                break;
            case VK_PERFORMANCE_VALUE_TYPE_UINT64_INTEL:
                FieldToJson(jdata["value64"], decoded_value.value64);
                break;
            case VK_PERFORMANCE_VALUE_TYPE_FLOAT_INTEL:
                FieldToJson(jdata["valueFloat"], decoded_value.valueFloat);
                break;
            case VK_PERFORMANCE_VALUE_TYPE_BOOL_INTEL:
                FieldToJson(jdata["valueBool"], decoded_value.valueBool);
                break;
            case VK_PERFORMANCE_VALUE_TYPE_STRING_INTEL:
                FieldToJson(jdata["valueString"], meta_struct.valueString);
                break;
            case VK_PERFORMANCE_VALUE_TYPE_MAX_ENUM_INTEL:
                GFXRECON_LOG_WARNING("Invalid performance value type: VK_PERFORMANCE_VALUE_TYPE_MAX_ENUM_INTEL");
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPerformanceValueINTEL* data)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["type"], decoded_value.type);
        FieldToJson(jdata["data"], decoded_value.type, meta_struct.data);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkShaderModuleCreateInfo* data)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType);
        FieldToJson(jdata["flags"], VkShaderModuleCreateFlags_t{ decoded_value.flags });
        FieldToJson(jdata["codeSize"], decoded_value.codeSize);
        // Use "[Binary data]" as placeholder. It will be replaced with a file path if the JSON
        // consumer decides to dump binaries in separate files.
        FieldToJson(jdata["pCode"], "[Binary data]");
        FieldToJson(jdata["pNext"], meta_struct.pNext);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_SECURITY_ATTRIBUTES* data)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        jdata["bInheritHandle"]   = static_cast<bool>(decoded_value.bInheritHandle);
        FieldToJson(jdata["nLength"], decoded_value.nLength);
        FieldToJson(jdata["lpSecurityDescriptor"], meta_struct.lpSecurityDescriptor->GetAddress());
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineCacheCreateInfo* data)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType);
        FieldToJson(jdata["flags"], VkPipelineCacheCreateFlags_t{ decoded_value.flags });
        FieldToJson(jdata["initialDataSize"], decoded_value.initialDataSize);
        // Use "[Binary data]" as placeholder. It will be replaced with a file path if the JSON
        // consumer decides to dump binaries in separate files.
        FieldToJson(jdata["pInitialData"], "[Binary data]");
        FieldToJson(jdata["pNext"], meta_struct.pNext);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const DescriptorUpdateTemplateDecoder* const pData)
{
    if (pData)
    {
        const size_t                        image_info_count = pData->GetImageInfoCount();
        std::vector<nlohmann::ordered_json> image_infos(image_info_count);

        for (size_t image_info_index = 0; image_info_index < image_info_count; ++image_info_index)
        {
            FieldToJson(image_infos[image_info_index], pData->GetImageInfoMetaStructPointer() + image_info_index);
        }
        jdata["imageInfos"] = image_infos;

        const size_t                        buffer_info_count = pData->GetBufferInfoCount();
        std::vector<nlohmann::ordered_json> buffer_infos(buffer_info_count);

        for (size_t buffer_info_index = 0; buffer_info_index < buffer_info_count; ++buffer_info_index)
        {
            FieldToJson(buffer_infos[buffer_info_index], pData->GetBufferInfoMetaStructPointer() + buffer_info_index);
        }
        jdata["bufferInfos"] = buffer_infos;

        const size_t texel_buffer_view_count = pData->GetTexelBufferViewCount();
        if (texel_buffer_view_count > 0)
        {
            HandleToJson(jdata["bufferViews"], pData->GetTexelBufferViewHandleIdsPointer(), texel_buffer_view_count);
        }

        const size_t acceleration_structure_count = pData->GetAccelerationStructureKHRCount();
        if (acceleration_structure_count > 0)
        {
            HandleToJson(jdata["accelStructViews"],
                         pData->GetAccelerationStructureKHRHandleIdsPointer(),
                         acceleration_structure_count);
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

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPushDescriptorSetWithTemplateInfo* const pData)
{
    HandleToJson(jdata["descriptorUpdateTemplate"], pData->descriptorUpdateTemplate);
    HandleToJson(jdata["layout"], pData->layout);
    FieldToJson(jdata["set"], pData->decoded_value->set);
    FieldToJson(jdata["pData"], &pData->pData);
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkIndirectExecutionSetCreateInfoEXT* const pData)
{
    FieldToJson(jdata["type"], pData->decoded_value->type);
    switch (pData->decoded_value->type)
    {
        case VK_INDIRECT_EXECUTION_SET_INFO_TYPE_PIPELINES_EXT:
            FieldToJson(jdata["info"], pData->info->pPipelineInfo);
            break;
        case VK_INDIRECT_EXECUTION_SET_INFO_TYPE_SHADER_OBJECTS_EXT:
            FieldToJson(jdata["info"], pData->info->pShaderInfo);
            break;
        default:
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkIndirectCommandsLayoutTokenEXT* const pData)
{
    FieldToJson(jdata["type"], pData->decoded_value->type);
    switch (pData->decoded_value->type)
    {
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_EXT:
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_SEQUENCE_INDEX_EXT:
            FieldToJson(jdata["data"], pData->data->pPushConstant);
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_EXT:
            FieldToJson(jdata["data"], pData->data->pVertexBuffer);
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_EXT:
            FieldToJson(jdata["data"], pData->data->pIndexBuffer);
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_EXECUTION_SET_EXT:
            FieldToJson(jdata["data"], pData->data->pExecutionSet);
            break;
        default:
            break;
    }
    FieldToJson(jdata["offset"], pData->offset);
}

void FieldToJson(nlohmann::ordered_json& jdata, const format::DeviceMemoryType& data)
{
    FieldToJson(jdata["property_flags"], decode::VkMemoryPropertyFlags_t{ data.property_flags });
    FieldToJson(jdata["heap_index"], data.heap_index);
}

void FieldToJson(nlohmann::ordered_json& jdata, const format::DeviceMemoryHeap& data)
{
    FieldToJson(jdata["size"], data.size);
    FieldToJson(jdata["flags"], decode::VkMemoryHeapFlags_t{ data.flags });
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyMemoryToImageInfo* data)
{
    if (data && data->decoded_value)
    {
        const VkCopyMemoryToImageInfo&         decoded_value = *data->decoded_value;
        const Decoded_VkCopyMemoryToImageInfo& meta_struct   = *data;

        FieldToJson(jdata["sType"], decoded_value.sType);
        FieldToJson(jdata["flags"], VkHostImageCopyFlags_t{ decoded_value.flags });
        HandleToJson(jdata["dstImage"], meta_struct.dstImage);
        FieldToJson(jdata["dstImageLayout"], decoded_value.dstImageLayout);
        FieldToJson(jdata["regionCount"], decoded_value.regionCount);
        FieldToJson(jdata["pRegions"], meta_struct.pRegions);
        FieldToJson(jdata["pNext"], meta_struct.pNext);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryToImageCopy* data)
{
    if (data && data->decoded_value)
    {
        const VkMemoryToImageCopy&         decoded_value = *data->decoded_value;
        const Decoded_VkMemoryToImageCopy& meta_struct   = *data;

        FieldToJson(jdata["sType"], decoded_value.sType);

        static thread_local uint64_t VkMemoryToImageCopy_pHostPointer_counter = 0;
        const bool                   written = RepresentBinaryFile(jdata["pHostPointer"],
                                                 "memorytoimagecopy",
                                                 VkMemoryToImageCopy_pHostPointer_counter,
                                                 meta_struct.pHostPointer.GetLength(),
                                                 meta_struct.pHostPointer.GetPointer());
        VkMemoryToImageCopy_pHostPointer_counter += written;

        FieldToJson(jdata["memoryRowLength"], decoded_value.memoryRowLength);
        FieldToJson(jdata["memoryImageHeight"], decoded_value.memoryImageHeight);
        FieldToJson(jdata["imageSubresource"], meta_struct.imageSubresource);
        FieldToJson(jdata["imageOffset"], meta_struct.imageOffset);
        FieldToJson(jdata["imageExtent"], meta_struct.imageExtent);
        FieldToJson(jdata["pNext"], meta_struct.pNext);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyImageToMemoryInfo* data)
{
    if (data && data->decoded_value)
    {
        const VkCopyImageToMemoryInfo&         decoded_value = *data->decoded_value;
        const Decoded_VkCopyImageToMemoryInfo& meta_struct   = *data;

        FieldToJson(jdata["sType"], decoded_value.sType);
        FieldToJson(jdata["flags"], VkHostImageCopyFlags_t{ decoded_value.flags });
        HandleToJson(jdata["srcImage"], meta_struct.srcImage);
        FieldToJson(jdata["srcImageLayout"], decoded_value.srcImageLayout);
        FieldToJson(jdata["regionCount"], decoded_value.regionCount);
        FieldToJson(jdata["pRegions"], meta_struct.pRegions);
        FieldToJson(jdata["pNext"], meta_struct.pNext);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageToMemoryCopy* data)
{
    if (data && data->decoded_value)
    {
        const VkImageToMemoryCopy&         decoded_value = *data->decoded_value;
        const Decoded_VkImageToMemoryCopy& meta_struct   = *data;

        FieldToJson(jdata["sType"], decoded_value.sType);

        static thread_local uint64_t VkImageToMemoryCopy_pHostPointer_counter = 0;
        const bool                   written = RepresentBinaryFile(jdata["pHostPointer"],
                                                 "imagetomemorycopy",
                                                 VkImageToMemoryCopy_pHostPointer_counter,
                                                 meta_struct.pHostPointer.GetLength(),
                                                 meta_struct.pHostPointer.GetPointer());
        VkImageToMemoryCopy_pHostPointer_counter += written;

        FieldToJson(jdata["memoryRowLength"], decoded_value.memoryRowLength);
        FieldToJson(jdata["memoryImageHeight"], decoded_value.memoryImageHeight);
        FieldToJson(jdata["imageSubresource"], meta_struct.imageSubresource);
        FieldToJson(jdata["imageOffset"], meta_struct.imageOffset);
        FieldToJson(jdata["imageExtent"], meta_struct.imageExtent);
        FieldToJson(jdata["pNext"], meta_struct.pNext);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkLayerSettingEXT* data)
{
    if (data && data->decoded_value)
    {
        const VkLayerSettingEXT&         decoded_value = *data->decoded_value;
        const Decoded_VkLayerSettingEXT& meta_struct   = *data;

        FieldToJson(jdata["pLayerName"], &meta_struct.pLayerName);
        FieldToJson(jdata["pSettingName"], &meta_struct.pSettingName);
        FieldToJson(jdata["type"], decoded_value.type);
        FieldToJson(jdata["valueCount"], decoded_value.valueCount);

        auto typed_json_array = [](const auto* ptr, size_t num_elements) -> nlohmann::json {
            return nlohmann::json(std::span(ptr, ptr + num_elements));
        };

        auto& value_out_json = jdata["pValues"];

        switch (decoded_value.type)
        {
            case VK_LAYER_SETTING_TYPE_BOOL32_EXT:
                value_out_json =
                    typed_json_array(static_cast<const VkBool32*>(decoded_value.pValues), decoded_value.valueCount);
                break;
            case VK_LAYER_SETTING_TYPE_INT32_EXT:
                value_out_json =
                    typed_json_array(static_cast<const int32_t*>(decoded_value.pValues), decoded_value.valueCount);
                break;
            case VK_LAYER_SETTING_TYPE_UINT32_EXT:
                value_out_json =
                    typed_json_array(static_cast<const uint32_t*>(decoded_value.pValues), decoded_value.valueCount);
                break;
            case VK_LAYER_SETTING_TYPE_INT64_EXT:
                value_out_json =
                    typed_json_array(static_cast<const int64_t*>(decoded_value.pValues), decoded_value.valueCount);
                break;
            case VK_LAYER_SETTING_TYPE_UINT64_EXT:
                value_out_json =
                    typed_json_array(static_cast<const uint64_t*>(decoded_value.pValues), decoded_value.valueCount);
                break;
            case VK_LAYER_SETTING_TYPE_FLOAT32_EXT:
                value_out_json =
                    typed_json_array(static_cast<const float*>(decoded_value.pValues), decoded_value.valueCount);
                break;
            case VK_LAYER_SETTING_TYPE_FLOAT64_EXT:
                value_out_json =
                    typed_json_array(static_cast<const double*>(decoded_value.pValues), decoded_value.valueCount);
                break;
            case VK_LAYER_SETTING_TYPE_STRING_EXT:
            {
                const auto* string_array = static_cast<const char* const*>(decoded_value.pValues);
                value_out_json           = nlohmann::json::array();

                for (uint32_t i = 0; i < decoded_value.valueCount; ++i)
                {
                    auto str_view = std::string_view(string_array[i]);
                    value_out_json.push_back(str_view);
                }
            }
            break;
            case VK_LAYER_SETTING_TYPE_MAX_ENUM_EXT:
                GFXRECON_ASSERT(false);
                break;
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, VkDescriptorType discriminant, const Decoded_VkDescriptorDataEXT* data)
{
    if (data && data->decoded_value)
    {
        switch (discriminant)
        {
            case VK_DESCRIPTOR_TYPE_SAMPLER:
                HandleToJson(jdata["pSampler"], &data->pSampler);
                break;
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                FieldToJson(jdata["pCombinedImageSampler"], data->pCombinedImageSampler);
                break;
            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                FieldToJson(jdata["pInputAttachmentImage"], data->pInputAttachmentImage);
                break;
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                FieldToJson(jdata["pSampledImage"], data->pSampledImage);
                break;
            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                FieldToJson(jdata["pStorageImage"], data->pStorageImage);
                break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                FieldToJson(jdata["pUniformTexelBuffer"], data->pUniformTexelBuffer);
                break;
            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                FieldToJson(jdata["pStorageTexelBuffer"], data->pStorageTexelBuffer);
                break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                FieldToJson(jdata["pUniformBuffer"], data->pUniformBuffer);
                break;
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                FieldToJson(jdata["pStorageBuffer"], data->pStorageBuffer);
                break;
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                FieldToJsonAsHex(jdata["accelerationStructure"], data->decoded_value->accelerationStructure);
                break;
            default:
                jdata = "Invalid DescriptorType: " + std::to_string(discriminant);
                break;
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorGetInfoEXT* data)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType);
        FieldToJson(jdata["type"], decoded_value.type);
        FieldToJson(jdata["data"], decoded_value.type, meta_struct.data);
        FieldToJson(jdata["pNext"], meta_struct.pNext);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
