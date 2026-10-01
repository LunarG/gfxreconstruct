/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2026 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc.
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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#include "generated_vulkan_enum_to_json.h"
#include "generated_vulkan_schema_enumerants.h"
#include "util/to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
using util::JsonOptions;
using util::to_hex_fixed_width;

template<typename TFlags, typename ToStringFunctionType>
std::string ExpandFlags(TFlags flags, ToStringFunctionType toString)
{
    if (flags == 0)
    {
        return to_hex_fixed_width(flags);
    }
    uint32_t bit_number = 0;
    bool first = true;
    std::ostringstream ostr;
    while (flags != 0)
    {
        if (flags & 1)
        {
            if (!first) ostr << "|";
            ostr << toString((flags & 1) << bit_number);
            first = false;
        }
        bit_number++;
        flags = flags >> 1;
    }
    return ostr.str();
}


void to_json(nlohmann::ordered_json& jdata, const VkAccessFlagBits2_t& value)
{
    switch (static_cast<VkAccessFlagBits2>(value)) {
        case VK_ACCESS_2_NONE:
            jdata = "VK_ACCESS_2_NONE";
            break;
        case VK_ACCESS_2_INDIRECT_COMMAND_READ_BIT:
            jdata = "VK_ACCESS_2_INDIRECT_COMMAND_READ_BIT";
            break;
        case VK_ACCESS_2_INDEX_READ_BIT:
            jdata = "VK_ACCESS_2_INDEX_READ_BIT";
            break;
        case VK_ACCESS_2_VERTEX_ATTRIBUTE_READ_BIT:
            jdata = "VK_ACCESS_2_VERTEX_ATTRIBUTE_READ_BIT";
            break;
        case VK_ACCESS_2_UNIFORM_READ_BIT:
            jdata = "VK_ACCESS_2_UNIFORM_READ_BIT";
            break;
        case VK_ACCESS_2_INPUT_ATTACHMENT_READ_BIT:
            jdata = "VK_ACCESS_2_INPUT_ATTACHMENT_READ_BIT";
            break;
        case VK_ACCESS_2_SHADER_READ_BIT:
            jdata = "VK_ACCESS_2_SHADER_READ_BIT";
            break;
        case VK_ACCESS_2_SHADER_WRITE_BIT:
            jdata = "VK_ACCESS_2_SHADER_WRITE_BIT";
            break;
        case VK_ACCESS_2_COLOR_ATTACHMENT_READ_BIT:
            jdata = "VK_ACCESS_2_COLOR_ATTACHMENT_READ_BIT";
            break;
        case VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT:
            jdata = "VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT";
            break;
        case VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_READ_BIT:
            jdata = "VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_READ_BIT";
            break;
        case VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT:
            jdata = "VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT";
            break;
        case VK_ACCESS_2_TRANSFER_READ_BIT:
            jdata = "VK_ACCESS_2_TRANSFER_READ_BIT";
            break;
        case VK_ACCESS_2_TRANSFER_WRITE_BIT:
            jdata = "VK_ACCESS_2_TRANSFER_WRITE_BIT";
            break;
        case VK_ACCESS_2_HOST_READ_BIT:
            jdata = "VK_ACCESS_2_HOST_READ_BIT";
            break;
        case VK_ACCESS_2_HOST_WRITE_BIT:
            jdata = "VK_ACCESS_2_HOST_WRITE_BIT";
            break;
        case VK_ACCESS_2_MEMORY_READ_BIT:
            jdata = "VK_ACCESS_2_MEMORY_READ_BIT";
            break;
        case VK_ACCESS_2_MEMORY_WRITE_BIT:
            jdata = "VK_ACCESS_2_MEMORY_WRITE_BIT";
            break;
        case VK_ACCESS_2_SHADER_SAMPLED_READ_BIT:
            jdata = "VK_ACCESS_2_SHADER_SAMPLED_READ_BIT";
            break;
        case VK_ACCESS_2_SHADER_STORAGE_READ_BIT:
            jdata = "VK_ACCESS_2_SHADER_STORAGE_READ_BIT";
            break;
        case VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT:
            jdata = "VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT";
            break;
        case VK_ACCESS_2_VIDEO_DECODE_READ_BIT_KHR:
            jdata = "VK_ACCESS_2_VIDEO_DECODE_READ_BIT_KHR";
            break;
        case VK_ACCESS_2_VIDEO_DECODE_WRITE_BIT_KHR:
            jdata = "VK_ACCESS_2_VIDEO_DECODE_WRITE_BIT_KHR";
            break;
        case VK_ACCESS_2_SAMPLER_HEAP_READ_BIT_EXT:
            jdata = "VK_ACCESS_2_SAMPLER_HEAP_READ_BIT_EXT";
            break;
        case VK_ACCESS_2_RESOURCE_HEAP_READ_BIT_EXT:
            jdata = "VK_ACCESS_2_RESOURCE_HEAP_READ_BIT_EXT";
            break;
        case VK_ACCESS_2_VIDEO_ENCODE_READ_BIT_KHR:
            jdata = "VK_ACCESS_2_VIDEO_ENCODE_READ_BIT_KHR";
            break;
        case VK_ACCESS_2_VIDEO_ENCODE_WRITE_BIT_KHR:
            jdata = "VK_ACCESS_2_VIDEO_ENCODE_WRITE_BIT_KHR";
            break;
        case VK_ACCESS_2_SHADER_TILE_ATTACHMENT_READ_BIT_QCOM:
            jdata = "VK_ACCESS_2_SHADER_TILE_ATTACHMENT_READ_BIT_QCOM";
            break;
        case VK_ACCESS_2_SHADER_TILE_ATTACHMENT_WRITE_BIT_QCOM:
            jdata = "VK_ACCESS_2_SHADER_TILE_ATTACHMENT_WRITE_BIT_QCOM";
            break;
        case VK_ACCESS_2_TRANSFORM_FEEDBACK_WRITE_BIT_EXT:
            jdata = "VK_ACCESS_2_TRANSFORM_FEEDBACK_WRITE_BIT_EXT";
            break;
        case VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT:
            jdata = "VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT";
            break;
        case VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT:
            jdata = "VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT";
            break;
        case VK_ACCESS_2_CONDITIONAL_RENDERING_READ_BIT_EXT:
            jdata = "VK_ACCESS_2_CONDITIONAL_RENDERING_READ_BIT_EXT";
            break;
        case VK_ACCESS_2_COMMAND_PREPROCESS_READ_BIT_EXT:
            jdata = "VK_ACCESS_2_COMMAND_PREPROCESS_READ_BIT_EXT";
            break;
        case VK_ACCESS_2_COMMAND_PREPROCESS_WRITE_BIT_EXT:
            jdata = "VK_ACCESS_2_COMMAND_PREPROCESS_WRITE_BIT_EXT";
            break;
        case VK_ACCESS_2_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR:
            jdata = "VK_ACCESS_2_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR";
            break;
        case VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR:
            jdata = "VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR";
            break;
        case VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR:
            jdata = "VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR";
            break;
        case VK_ACCESS_2_FRAGMENT_DENSITY_MAP_READ_BIT_EXT:
            jdata = "VK_ACCESS_2_FRAGMENT_DENSITY_MAP_READ_BIT_EXT";
            break;
        case VK_ACCESS_2_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT:
            jdata = "VK_ACCESS_2_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT";
            break;
        case VK_ACCESS_2_DESCRIPTOR_BUFFER_READ_BIT_EXT:
            jdata = "VK_ACCESS_2_DESCRIPTOR_BUFFER_READ_BIT_EXT";
            break;
        case VK_ACCESS_2_INVOCATION_MASK_READ_BIT_HUAWEI:
            jdata = "VK_ACCESS_2_INVOCATION_MASK_READ_BIT_HUAWEI";
            break;
        case VK_ACCESS_2_SHADER_BINDING_TABLE_READ_BIT_KHR:
            jdata = "VK_ACCESS_2_SHADER_BINDING_TABLE_READ_BIT_KHR";
            break;
        case VK_ACCESS_2_MICROMAP_READ_BIT_EXT:
            jdata = "VK_ACCESS_2_MICROMAP_READ_BIT_EXT";
            break;
        case VK_ACCESS_2_MICROMAP_WRITE_BIT_EXT:
            jdata = "VK_ACCESS_2_MICROMAP_WRITE_BIT_EXT";
            break;
        case VK_ACCESS_2_OPTICAL_FLOW_READ_BIT_NV:
            jdata = "VK_ACCESS_2_OPTICAL_FLOW_READ_BIT_NV";
            break;
        case VK_ACCESS_2_OPTICAL_FLOW_WRITE_BIT_NV:
            jdata = "VK_ACCESS_2_OPTICAL_FLOW_WRITE_BIT_NV";
            break;
        case VK_ACCESS_2_DATA_GRAPH_READ_BIT_ARM:
            jdata = "VK_ACCESS_2_DATA_GRAPH_READ_BIT_ARM";
            break;
        case VK_ACCESS_2_DATA_GRAPH_WRITE_BIT_ARM:
            jdata = "VK_ACCESS_2_DATA_GRAPH_WRITE_BIT_ARM";
            break;
        case VK_ACCESS_2_MEMORY_DECOMPRESSION_READ_BIT_EXT:
            jdata = "VK_ACCESS_2_MEMORY_DECOMPRESSION_READ_BIT_EXT";
            break;
        case VK_ACCESS_2_MEMORY_DECOMPRESSION_WRITE_BIT_EXT:
            jdata = "VK_ACCESS_2_MEMORY_DECOMPRESSION_WRITE_BIT_EXT";
            break;
        default:
            jdata = gfxrecon::decode::to_hex_fixed_width(static_cast<VkAccessFlagBits2>(value));
            break;
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkAccessFlagBits3KHR_t& value)
{
    switch (static_cast<VkAccessFlagBits3KHR>(value)) {
        case VK_ACCESS_3_NONE_KHR:
            jdata = "VK_ACCESS_3_NONE_KHR";
            break;
        default:
            jdata = gfxrecon::decode::to_hex_fixed_width(static_cast<VkAccessFlagBits3KHR>(value));
            break;
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkBufferUsageFlagBits2_t& value)
{
    switch (static_cast<VkBufferUsageFlagBits2>(value)) {
        case VK_BUFFER_USAGE_2_TRANSFER_SRC_BIT:
            jdata = "VK_BUFFER_USAGE_2_TRANSFER_SRC_BIT";
            break;
        case VK_BUFFER_USAGE_2_TRANSFER_DST_BIT:
            jdata = "VK_BUFFER_USAGE_2_TRANSFER_DST_BIT";
            break;
        case VK_BUFFER_USAGE_2_UNIFORM_TEXEL_BUFFER_BIT:
            jdata = "VK_BUFFER_USAGE_2_UNIFORM_TEXEL_BUFFER_BIT";
            break;
        case VK_BUFFER_USAGE_2_STORAGE_TEXEL_BUFFER_BIT:
            jdata = "VK_BUFFER_USAGE_2_STORAGE_TEXEL_BUFFER_BIT";
            break;
        case VK_BUFFER_USAGE_2_UNIFORM_BUFFER_BIT:
            jdata = "VK_BUFFER_USAGE_2_UNIFORM_BUFFER_BIT";
            break;
        case VK_BUFFER_USAGE_2_STORAGE_BUFFER_BIT:
            jdata = "VK_BUFFER_USAGE_2_STORAGE_BUFFER_BIT";
            break;
        case VK_BUFFER_USAGE_2_INDEX_BUFFER_BIT:
            jdata = "VK_BUFFER_USAGE_2_INDEX_BUFFER_BIT";
            break;
        case VK_BUFFER_USAGE_2_VERTEX_BUFFER_BIT:
            jdata = "VK_BUFFER_USAGE_2_VERTEX_BUFFER_BIT";
            break;
        case VK_BUFFER_USAGE_2_INDIRECT_BUFFER_BIT:
            jdata = "VK_BUFFER_USAGE_2_INDIRECT_BUFFER_BIT";
            break;
        case VK_BUFFER_USAGE_2_SHADER_DEVICE_ADDRESS_BIT:
            jdata = "VK_BUFFER_USAGE_2_SHADER_DEVICE_ADDRESS_BIT";
            break;
        case VK_BUFFER_USAGE_2_EXECUTION_GRAPH_SCRATCH_BIT_AMDX:
            jdata = "VK_BUFFER_USAGE_2_EXECUTION_GRAPH_SCRATCH_BIT_AMDX";
            break;
        case VK_BUFFER_USAGE_2_DESCRIPTOR_HEAP_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_2_DESCRIPTOR_HEAP_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_2_MICROMAP_BUILD_INPUT_READ_ONLY_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_2_MICROMAP_BUILD_INPUT_READ_ONLY_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_2_MICROMAP_STORAGE_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_2_MICROMAP_STORAGE_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_2_CONDITIONAL_RENDERING_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_2_CONDITIONAL_RENDERING_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_2_SHADER_BINDING_TABLE_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_SHADER_BINDING_TABLE_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_2_VIDEO_DECODE_SRC_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_VIDEO_DECODE_SRC_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_VIDEO_DECODE_DST_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_VIDEO_DECODE_DST_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_VIDEO_ENCODE_DST_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_VIDEO_ENCODE_DST_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_VIDEO_ENCODE_SRC_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_VIDEO_ENCODE_SRC_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_SAMPLER_DESCRIPTOR_BUFFER_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_2_SAMPLER_DESCRIPTOR_BUFFER_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_2_RESOURCE_DESCRIPTOR_BUFFER_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_2_RESOURCE_DESCRIPTOR_BUFFER_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_2_PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_2_PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_2_COMPRESSED_DATA_DGF1_BIT_AMDX:
            jdata = "VK_BUFFER_USAGE_2_COMPRESSED_DATA_DGF1_BIT_AMDX";
            break;
        case VK_BUFFER_USAGE_2_DATA_GRAPH_FOREIGN_DESCRIPTOR_BIT_ARM:
            jdata = "VK_BUFFER_USAGE_2_DATA_GRAPH_FOREIGN_DESCRIPTOR_BIT_ARM";
            break;
        case VK_BUFFER_USAGE_2_TILE_MEMORY_BIT_QCOM:
            jdata = "VK_BUFFER_USAGE_2_TILE_MEMORY_BIT_QCOM";
            break;
        case VK_BUFFER_USAGE_2_MEMORY_DECOMPRESSION_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_2_MEMORY_DECOMPRESSION_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_2_PREPROCESS_BUFFER_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_2_PREPROCESS_BUFFER_BIT_EXT";
            break;
        default:
            jdata = gfxrecon::decode::to_hex_fixed_width(static_cast<VkBufferUsageFlagBits2>(value));
            break;
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDataGraphPipelineDispatchFlagBitsARM_t& value)
{
    jdata = gfxrecon::decode::to_hex_fixed_width(static_cast<VkDataGraphPipelineDispatchFlagBitsARM>(value));
}

void to_json(nlohmann::ordered_json& jdata, const VkDataGraphPipelineSessionCreateFlagBitsARM_t& value)
{
    switch (static_cast<VkDataGraphPipelineSessionCreateFlagBitsARM>(value)) {
        case VK_DATA_GRAPH_PIPELINE_SESSION_CREATE_PROTECTED_BIT_ARM:
            jdata = "VK_DATA_GRAPH_PIPELINE_SESSION_CREATE_PROTECTED_BIT_ARM";
            break;
        case VK_DATA_GRAPH_PIPELINE_SESSION_CREATE_OPTICAL_FLOW_CACHE_BIT_ARM:
            jdata = "VK_DATA_GRAPH_PIPELINE_SESSION_CREATE_OPTICAL_FLOW_CACHE_BIT_ARM";
            break;
        default:
            jdata = gfxrecon::decode::to_hex_fixed_width(static_cast<VkDataGraphPipelineSessionCreateFlagBitsARM>(value));
            break;
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkFormatFeatureFlagBits2_t& value)
{
    switch (static_cast<VkFormatFeatureFlagBits2>(value)) {
        case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT:
            jdata = "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT";
            break;
        case VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT:
            jdata = "VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT";
            break;
        case VK_FORMAT_FEATURE_2_STORAGE_IMAGE_ATOMIC_BIT:
            jdata = "VK_FORMAT_FEATURE_2_STORAGE_IMAGE_ATOMIC_BIT";
            break;
        case VK_FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT:
            jdata = "VK_FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT";
            break;
        case VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_BIT:
            jdata = "VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_BIT";
            break;
        case VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_ATOMIC_BIT:
            jdata = "VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_ATOMIC_BIT";
            break;
        case VK_FORMAT_FEATURE_2_VERTEX_BUFFER_BIT:
            jdata = "VK_FORMAT_FEATURE_2_VERTEX_BUFFER_BIT";
            break;
        case VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BIT:
            jdata = "VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BIT";
            break;
        case VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BLEND_BIT:
            jdata = "VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BLEND_BIT";
            break;
        case VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT:
            jdata = "VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT";
            break;
        case VK_FORMAT_FEATURE_2_BLIT_SRC_BIT:
            jdata = "VK_FORMAT_FEATURE_2_BLIT_SRC_BIT";
            break;
        case VK_FORMAT_FEATURE_2_BLIT_DST_BIT:
            jdata = "VK_FORMAT_FEATURE_2_BLIT_DST_BIT";
            break;
        case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_BIT:
            jdata = "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_BIT";
            break;
        case VK_FORMAT_FEATURE_2_TRANSFER_SRC_BIT:
            jdata = "VK_FORMAT_FEATURE_2_TRANSFER_SRC_BIT";
            break;
        case VK_FORMAT_FEATURE_2_TRANSFER_DST_BIT:
            jdata = "VK_FORMAT_FEATURE_2_TRANSFER_DST_BIT";
            break;
        case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_MINMAX_BIT:
            jdata = "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_MINMAX_BIT";
            break;
        case VK_FORMAT_FEATURE_2_MIDPOINT_CHROMA_SAMPLES_BIT:
            jdata = "VK_FORMAT_FEATURE_2_MIDPOINT_CHROMA_SAMPLES_BIT";
            break;
        case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT:
            jdata = "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT";
            break;
        case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT:
            jdata = "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT";
            break;
        case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT:
            jdata = "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT";
            break;
        case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT:
            jdata = "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT";
            break;
        case VK_FORMAT_FEATURE_2_DISJOINT_BIT:
            jdata = "VK_FORMAT_FEATURE_2_DISJOINT_BIT";
            break;
        case VK_FORMAT_FEATURE_2_COSITED_CHROMA_SAMPLES_BIT:
            jdata = "VK_FORMAT_FEATURE_2_COSITED_CHROMA_SAMPLES_BIT";
            break;
        case VK_FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT:
            jdata = "VK_FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT";
            break;
        case VK_FORMAT_FEATURE_2_STORAGE_WRITE_WITHOUT_FORMAT_BIT:
            jdata = "VK_FORMAT_FEATURE_2_STORAGE_WRITE_WITHOUT_FORMAT_BIT";
            break;
        case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_DEPTH_COMPARISON_BIT:
            jdata = "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_DEPTH_COMPARISON_BIT";
            break;
        case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT:
            jdata = "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT";
            break;
        case VK_FORMAT_FEATURE_2_HOST_IMAGE_TRANSFER_BIT:
            jdata = "VK_FORMAT_FEATURE_2_HOST_IMAGE_TRANSFER_BIT";
            break;
        case VK_FORMAT_FEATURE_2_VIDEO_DECODE_OUTPUT_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_2_VIDEO_DECODE_OUTPUT_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_2_VIDEO_DECODE_DPB_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_2_VIDEO_DECODE_DPB_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_2_FRAGMENT_DENSITY_MAP_BIT_EXT:
            jdata = "VK_FORMAT_FEATURE_2_FRAGMENT_DENSITY_MAP_BIT_EXT";
            break;
        case VK_FORMAT_FEATURE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_2_VIDEO_ENCODE_INPUT_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_2_VIDEO_ENCODE_INPUT_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_2_VIDEO_ENCODE_DPB_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_2_VIDEO_ENCODE_DPB_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_2_BLOCK_MATCHING_SXD_BIT_QCOM:
            jdata = "VK_FORMAT_FEATURE_2_BLOCK_MATCHING_SXD_BIT_QCOM";
            break;
        case VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_RADIUS_BUFFER_BIT_NV:
            jdata = "VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_RADIUS_BUFFER_BIT_NV";
            break;
        case VK_FORMAT_FEATURE_2_LINEAR_COLOR_ATTACHMENT_BIT_NV:
            jdata = "VK_FORMAT_FEATURE_2_LINEAR_COLOR_ATTACHMENT_BIT_NV";
            break;
        case VK_FORMAT_FEATURE_2_WEIGHT_IMAGE_BIT_QCOM:
            jdata = "VK_FORMAT_FEATURE_2_WEIGHT_IMAGE_BIT_QCOM";
            break;
        case VK_FORMAT_FEATURE_2_WEIGHT_SAMPLED_IMAGE_BIT_QCOM:
            jdata = "VK_FORMAT_FEATURE_2_WEIGHT_SAMPLED_IMAGE_BIT_QCOM";
            break;
        case VK_FORMAT_FEATURE_2_BLOCK_MATCHING_BIT_QCOM:
            jdata = "VK_FORMAT_FEATURE_2_BLOCK_MATCHING_BIT_QCOM";
            break;
        case VK_FORMAT_FEATURE_2_BOX_FILTER_SAMPLED_BIT_QCOM:
            jdata = "VK_FORMAT_FEATURE_2_BOX_FILTER_SAMPLED_BIT_QCOM";
            break;
        case VK_FORMAT_FEATURE_2_TENSOR_SHADER_BIT_ARM:
            jdata = "VK_FORMAT_FEATURE_2_TENSOR_SHADER_BIT_ARM";
            break;
        case VK_FORMAT_FEATURE_2_TENSOR_IMAGE_ALIASING_BIT_ARM:
            jdata = "VK_FORMAT_FEATURE_2_TENSOR_IMAGE_ALIASING_BIT_ARM";
            break;
        case VK_FORMAT_FEATURE_2_OPTICAL_FLOW_IMAGE_BIT_NV:
            jdata = "VK_FORMAT_FEATURE_2_OPTICAL_FLOW_IMAGE_BIT_NV";
            break;
        case VK_FORMAT_FEATURE_2_OPTICAL_FLOW_VECTOR_BIT_NV:
            jdata = "VK_FORMAT_FEATURE_2_OPTICAL_FLOW_VECTOR_BIT_NV";
            break;
        case VK_FORMAT_FEATURE_2_OPTICAL_FLOW_COST_BIT_NV:
            jdata = "VK_FORMAT_FEATURE_2_OPTICAL_FLOW_COST_BIT_NV";
            break;
        case VK_FORMAT_FEATURE_2_TENSOR_DATA_GRAPH_BIT_ARM:
            jdata = "VK_FORMAT_FEATURE_2_TENSOR_DATA_GRAPH_BIT_ARM";
            break;
        case VK_FORMAT_FEATURE_2_COPY_IMAGE_INDIRECT_DST_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_2_COPY_IMAGE_INDIRECT_DST_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_2_VIDEO_ENCODE_QUANTIZATION_DELTA_MAP_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_2_VIDEO_ENCODE_QUANTIZATION_DELTA_MAP_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_2_VIDEO_ENCODE_EMPHASIS_MAP_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_2_VIDEO_ENCODE_EMPHASIS_MAP_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_2D_BIT_IMG:
            jdata = "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_2D_BIT_IMG";
            break;
        case VK_FORMAT_FEATURE_2_DEPTH_COPY_ON_COMPUTE_QUEUE_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_2_DEPTH_COPY_ON_COMPUTE_QUEUE_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_2_DEPTH_COPY_ON_TRANSFER_QUEUE_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_2_DEPTH_COPY_ON_TRANSFER_QUEUE_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_2_STENCIL_COPY_ON_COMPUTE_QUEUE_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_2_STENCIL_COPY_ON_COMPUTE_QUEUE_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_2_STENCIL_COPY_ON_TRANSFER_QUEUE_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_2_STENCIL_COPY_ON_TRANSFER_QUEUE_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_2_DATA_GRAPH_OPTICAL_FLOW_IMAGE_BIT_ARM:
            jdata = "VK_FORMAT_FEATURE_2_DATA_GRAPH_OPTICAL_FLOW_IMAGE_BIT_ARM";
            break;
        case VK_FORMAT_FEATURE_2_DATA_GRAPH_OPTICAL_FLOW_VECTOR_BIT_ARM:
            jdata = "VK_FORMAT_FEATURE_2_DATA_GRAPH_OPTICAL_FLOW_VECTOR_BIT_ARM";
            break;
        case VK_FORMAT_FEATURE_2_DATA_GRAPH_OPTICAL_FLOW_COST_BIT_ARM:
            jdata = "VK_FORMAT_FEATURE_2_DATA_GRAPH_OPTICAL_FLOW_COST_BIT_ARM";
            break;
        default:
            jdata = gfxrecon::decode::to_hex_fixed_width(static_cast<VkFormatFeatureFlagBits2>(value));
            break;
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkFormatFeatureFlagBits4KHR_t& value)
{
    jdata = gfxrecon::decode::to_hex_fixed_width(static_cast<VkFormatFeatureFlagBits4KHR>(value));
}

void to_json(nlohmann::ordered_json& jdata, const VkImageCreateFlagBits2KHR_t& value)
{
    switch (static_cast<VkImageCreateFlagBits2KHR>(value)) {
        case VK_IMAGE_CREATE_2_SPARSE_BINDING_BIT_KHR:
            jdata = "VK_IMAGE_CREATE_2_SPARSE_BINDING_BIT_KHR";
            break;
        case VK_IMAGE_CREATE_2_SPARSE_RESIDENCY_BIT_KHR:
            jdata = "VK_IMAGE_CREATE_2_SPARSE_RESIDENCY_BIT_KHR";
            break;
        case VK_IMAGE_CREATE_2_SPARSE_ALIASED_BIT_KHR:
            jdata = "VK_IMAGE_CREATE_2_SPARSE_ALIASED_BIT_KHR";
            break;
        case VK_IMAGE_CREATE_2_MUTABLE_FORMAT_BIT_KHR:
            jdata = "VK_IMAGE_CREATE_2_MUTABLE_FORMAT_BIT_KHR";
            break;
        case VK_IMAGE_CREATE_2_CUBE_COMPATIBLE_BIT_KHR:
            jdata = "VK_IMAGE_CREATE_2_CUBE_COMPATIBLE_BIT_KHR";
            break;
        case VK_IMAGE_CREATE_2_ALIAS_SINGLE_LAYER_DESCRIPTOR_BIT_KHR:
            jdata = "VK_IMAGE_CREATE_2_ALIAS_SINGLE_LAYER_DESCRIPTOR_BIT_KHR";
            break;
        case VK_IMAGE_CREATE_2_2D_ARRAY_COMPATIBLE_BIT_KHR:
            jdata = "VK_IMAGE_CREATE_2_2D_ARRAY_COMPATIBLE_BIT_KHR";
            break;
        case VK_IMAGE_CREATE_2_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR:
            jdata = "VK_IMAGE_CREATE_2_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR";
            break;
        case VK_IMAGE_CREATE_2_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT_KHR:
            jdata = "VK_IMAGE_CREATE_2_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT_KHR";
            break;
        case VK_IMAGE_CREATE_2_EXTENDED_USAGE_BIT_KHR:
            jdata = "VK_IMAGE_CREATE_2_EXTENDED_USAGE_BIT_KHR";
            break;
        case VK_IMAGE_CREATE_2_DISJOINT_BIT_KHR:
            jdata = "VK_IMAGE_CREATE_2_DISJOINT_BIT_KHR";
            break;
        case VK_IMAGE_CREATE_2_ALIAS_BIT_KHR:
            jdata = "VK_IMAGE_CREATE_2_ALIAS_BIT_KHR";
            break;
        case VK_IMAGE_CREATE_2_PROTECTED_BIT_KHR:
            jdata = "VK_IMAGE_CREATE_2_PROTECTED_BIT_KHR";
            break;
        case VK_IMAGE_CREATE_2_SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_BIT_EXT:
            jdata = "VK_IMAGE_CREATE_2_SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_BIT_EXT";
            break;
        case VK_IMAGE_CREATE_2_CORNER_SAMPLED_BIT_NV:
            jdata = "VK_IMAGE_CREATE_2_CORNER_SAMPLED_BIT_NV";
            break;
        case VK_IMAGE_CREATE_2_SUBSAMPLED_BIT_EXT:
            jdata = "VK_IMAGE_CREATE_2_SUBSAMPLED_BIT_EXT";
            break;
        case VK_IMAGE_CREATE_2_FRAGMENT_DENSITY_MAP_OFFSET_BIT_EXT:
            jdata = "VK_IMAGE_CREATE_2_FRAGMENT_DENSITY_MAP_OFFSET_BIT_EXT";
            break;
        case VK_IMAGE_CREATE_2_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT:
            jdata = "VK_IMAGE_CREATE_2_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT";
            break;
        case VK_IMAGE_CREATE_2_2D_VIEW_COMPATIBLE_BIT_EXT:
            jdata = "VK_IMAGE_CREATE_2_2D_VIEW_COMPATIBLE_BIT_EXT";
            break;
        case VK_IMAGE_CREATE_2_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_BIT_EXT:
            jdata = "VK_IMAGE_CREATE_2_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_BIT_EXT";
            break;
        case VK_IMAGE_CREATE_2_VIDEO_PROFILE_INDEPENDENT_BIT_KHR:
            jdata = "VK_IMAGE_CREATE_2_VIDEO_PROFILE_INDEPENDENT_BIT_KHR";
            break;
        default:
            jdata = gfxrecon::decode::to_hex_fixed_width(static_cast<VkImageCreateFlagBits2KHR>(value));
            break;
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkImageUsageFlagBits2KHR_t& value)
{
    switch (static_cast<VkImageUsageFlagBits2KHR>(value)) {
        case VK_IMAGE_USAGE_2_TRANSFER_SRC_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_2_TRANSFER_SRC_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_2_TRANSFER_DST_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_2_TRANSFER_DST_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_2_SAMPLED_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_2_SAMPLED_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_2_STORAGE_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_2_STORAGE_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_2_COLOR_ATTACHMENT_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_2_COLOR_ATTACHMENT_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_2_DEPTH_STENCIL_ATTACHMENT_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_2_DEPTH_STENCIL_ATTACHMENT_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_2_TRANSIENT_ATTACHMENT_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_2_TRANSIENT_ATTACHMENT_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_2_INPUT_ATTACHMENT_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_2_INPUT_ATTACHMENT_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_2_FRAGMENT_DENSITY_MAP_BIT_EXT:
            jdata = "VK_IMAGE_USAGE_2_FRAGMENT_DENSITY_MAP_BIT_EXT";
            break;
        case VK_IMAGE_USAGE_2_VIDEO_DECODE_DST_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_2_VIDEO_DECODE_DST_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_2_VIDEO_DECODE_SRC_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_2_VIDEO_DECODE_SRC_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_2_VIDEO_DECODE_DPB_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_2_VIDEO_DECODE_DPB_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_2_VIDEO_ENCODE_DST_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_2_VIDEO_ENCODE_DST_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_2_VIDEO_ENCODE_SRC_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_2_VIDEO_ENCODE_SRC_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_2_VIDEO_ENCODE_DPB_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_2_VIDEO_ENCODE_DPB_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_2_INVOCATION_MASK_BIT_HUAWEI:
            jdata = "VK_IMAGE_USAGE_2_INVOCATION_MASK_BIT_HUAWEI";
            break;
        case VK_IMAGE_USAGE_2_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT:
            jdata = "VK_IMAGE_USAGE_2_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT";
            break;
        case VK_IMAGE_USAGE_2_SAMPLE_WEIGHT_BIT_QCOM:
            jdata = "VK_IMAGE_USAGE_2_SAMPLE_WEIGHT_BIT_QCOM";
            break;
        case VK_IMAGE_USAGE_2_SAMPLE_BLOCK_MATCH_BIT_QCOM:
            jdata = "VK_IMAGE_USAGE_2_SAMPLE_BLOCK_MATCH_BIT_QCOM";
            break;
        case VK_IMAGE_USAGE_2_HOST_TRANSFER_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_2_HOST_TRANSFER_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_2_TENSOR_ALIASING_BIT_ARM:
            jdata = "VK_IMAGE_USAGE_2_TENSOR_ALIASING_BIT_ARM";
            break;
        case VK_IMAGE_USAGE_2_VIDEO_ENCODE_QUANTIZATION_DELTA_MAP_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_2_VIDEO_ENCODE_QUANTIZATION_DELTA_MAP_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_2_VIDEO_ENCODE_EMPHASIS_MAP_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_2_VIDEO_ENCODE_EMPHASIS_MAP_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_2_TILE_MEMORY_BIT_QCOM:
            jdata = "VK_IMAGE_USAGE_2_TILE_MEMORY_BIT_QCOM";
            break;
        default:
            jdata = gfxrecon::decode::to_hex_fixed_width(static_cast<VkImageUsageFlagBits2KHR>(value));
            break;
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkMemoryDecompressionMethodFlagBitsEXT_t& value)
{
    switch (static_cast<VkMemoryDecompressionMethodFlagBitsEXT>(value)) {
        case VK_MEMORY_DECOMPRESSION_METHOD_GDEFLATE_1_0_BIT_EXT:
            jdata = "VK_MEMORY_DECOMPRESSION_METHOD_GDEFLATE_1_0_BIT_EXT";
            break;
        default:
            jdata = gfxrecon::decode::to_hex_fixed_width(static_cast<VkMemoryDecompressionMethodFlagBitsEXT>(value));
            break;
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPhysicalDeviceSchedulingControlsFlagBitsARM_t& value)
{
    switch (static_cast<VkPhysicalDeviceSchedulingControlsFlagBitsARM>(value)) {
        case VK_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_SHADER_CORE_COUNT_ARM:
            jdata = "VK_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_SHADER_CORE_COUNT_ARM";
            break;
        case VK_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_DISPATCH_PARAMETERS_ARM:
            jdata = "VK_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_DISPATCH_PARAMETERS_ARM";
            break;
        default:
            jdata = gfxrecon::decode::to_hex_fixed_width(static_cast<VkPhysicalDeviceSchedulingControlsFlagBitsARM>(value));
            break;
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineCreateFlagBits2_t& value)
{
    switch (static_cast<VkPipelineCreateFlagBits2>(value)) {
        case VK_PIPELINE_CREATE_2_DISABLE_OPTIMIZATION_BIT:
            jdata = "VK_PIPELINE_CREATE_2_DISABLE_OPTIMIZATION_BIT";
            break;
        case VK_PIPELINE_CREATE_2_ALLOW_DERIVATIVES_BIT:
            jdata = "VK_PIPELINE_CREATE_2_ALLOW_DERIVATIVES_BIT";
            break;
        case VK_PIPELINE_CREATE_2_DERIVATIVE_BIT:
            jdata = "VK_PIPELINE_CREATE_2_DERIVATIVE_BIT";
            break;
        case VK_PIPELINE_CREATE_2_VIEW_INDEX_FROM_DEVICE_INDEX_BIT:
            jdata = "VK_PIPELINE_CREATE_2_VIEW_INDEX_FROM_DEVICE_INDEX_BIT";
            break;
        case VK_PIPELINE_CREATE_2_DISPATCH_BASE_BIT:
            jdata = "VK_PIPELINE_CREATE_2_DISPATCH_BASE_BIT";
            break;
        case VK_PIPELINE_CREATE_2_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT:
            jdata = "VK_PIPELINE_CREATE_2_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT";
            break;
        case VK_PIPELINE_CREATE_2_EARLY_RETURN_ON_FAILURE_BIT:
            jdata = "VK_PIPELINE_CREATE_2_EARLY_RETURN_ON_FAILURE_BIT";
            break;
        case VK_PIPELINE_CREATE_2_NO_PROTECTED_ACCESS_BIT:
            jdata = "VK_PIPELINE_CREATE_2_NO_PROTECTED_ACCESS_BIT";
            break;
        case VK_PIPELINE_CREATE_2_PROTECTED_ACCESS_ONLY_BIT:
            jdata = "VK_PIPELINE_CREATE_2_PROTECTED_ACCESS_ONLY_BIT";
            break;
        case VK_PIPELINE_CREATE_2_EXECUTION_GRAPH_BIT_AMDX:
            jdata = "VK_PIPELINE_CREATE_2_EXECUTION_GRAPH_BIT_AMDX";
            break;
        case VK_PIPELINE_CREATE_2_DESCRIPTOR_HEAP_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_2_DESCRIPTOR_HEAP_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_2_RAY_TRACING_ALLOW_SPHERES_AND_LINEAR_SWEPT_SPHERES_BIT_NV:
            jdata = "VK_PIPELINE_CREATE_2_RAY_TRACING_ALLOW_SPHERES_AND_LINEAR_SWEPT_SPHERES_BIT_NV";
            break;
        case VK_PIPELINE_CREATE_2_ENABLE_LEGACY_DITHERING_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_2_ENABLE_LEGACY_DITHERING_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_2_DEFER_COMPILE_BIT_NV:
            jdata = "VK_PIPELINE_CREATE_2_DEFER_COMPILE_BIT_NV";
            break;
        case VK_PIPELINE_CREATE_2_CAPTURE_STATISTICS_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_CAPTURE_STATISTICS_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_LINK_TIME_OPTIMIZATION_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_2_LINK_TIME_OPTIMIZATION_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_2_RETAIN_LINK_TIME_OPTIMIZATION_INFO_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_2_RETAIN_LINK_TIME_OPTIMIZATION_INFO_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_2_LIBRARY_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_LIBRARY_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_AABBS_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_AABBS_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_INDIRECT_BINDABLE_BIT_NV:
            jdata = "VK_PIPELINE_CREATE_2_INDIRECT_BINDABLE_BIT_NV";
            break;
        case VK_PIPELINE_CREATE_2_RAY_TRACING_ALLOW_MOTION_BIT_NV:
            jdata = "VK_PIPELINE_CREATE_2_RAY_TRACING_ALLOW_MOTION_BIT_NV";
            break;
        case VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_2_COLOR_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_2_COLOR_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_2_DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_2_DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_2_RAY_TRACING_DISPLACEMENT_MICROMAP_BIT_NV:
            jdata = "VK_PIPELINE_CREATE_2_RAY_TRACING_DISPLACEMENT_MICROMAP_BIT_NV";
            break;
        case VK_PIPELINE_CREATE_2_DESCRIPTOR_BUFFER_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_2_DESCRIPTOR_BUFFER_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_2_DISALLOW_OPACITY_MICROMAP_BIT_ARM:
            jdata = "VK_PIPELINE_CREATE_2_DISALLOW_OPACITY_MICROMAP_BIT_ARM";
            break;
        case VK_PIPELINE_CREATE_2_INSTRUMENT_SHADERS_BIT_ARM:
            jdata = "VK_PIPELINE_CREATE_2_INSTRUMENT_SHADERS_BIT_ARM";
            break;
        case VK_PIPELINE_CREATE_2_CAPTURE_DATA_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_CAPTURE_DATA_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_INDIRECT_BINDABLE_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_2_INDIRECT_BINDABLE_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_2_PER_LAYER_FRAGMENT_DENSITY_BIT_VALVE:
            jdata = "VK_PIPELINE_CREATE_2_PER_LAYER_FRAGMENT_DENSITY_BIT_VALVE";
            break;
        case VK_PIPELINE_CREATE_2_RAY_TRACING_OPACITY_MICROMAP_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_RAY_TRACING_OPACITY_MICROMAP_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_OPACITY_MICROMAP_DISALLOW_MIXED_SPECIAL_INDEX_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_OPACITY_MICROMAP_DISALLOW_MIXED_SPECIAL_INDEX_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_64_BIT_INDEXING_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_2_64_BIT_INDEXING_BIT_EXT";
            break;
        default:
            jdata = gfxrecon::decode::to_hex_fixed_width(static_cast<VkPipelineCreateFlagBits2>(value));
            break;
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineStageFlagBits2_t& value)
{
    switch (static_cast<VkPipelineStageFlagBits2>(value)) {
        case VK_PIPELINE_STAGE_2_NONE:
            jdata = "VK_PIPELINE_STAGE_2_NONE";
            break;
        case VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT:
            jdata = "VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT";
            break;
        case VK_PIPELINE_STAGE_2_DRAW_INDIRECT_BIT:
            jdata = "VK_PIPELINE_STAGE_2_DRAW_INDIRECT_BIT";
            break;
        case VK_PIPELINE_STAGE_2_VERTEX_INPUT_BIT:
            jdata = "VK_PIPELINE_STAGE_2_VERTEX_INPUT_BIT";
            break;
        case VK_PIPELINE_STAGE_2_VERTEX_SHADER_BIT:
            jdata = "VK_PIPELINE_STAGE_2_VERTEX_SHADER_BIT";
            break;
        case VK_PIPELINE_STAGE_2_TESSELLATION_CONTROL_SHADER_BIT:
            jdata = "VK_PIPELINE_STAGE_2_TESSELLATION_CONTROL_SHADER_BIT";
            break;
        case VK_PIPELINE_STAGE_2_TESSELLATION_EVALUATION_SHADER_BIT:
            jdata = "VK_PIPELINE_STAGE_2_TESSELLATION_EVALUATION_SHADER_BIT";
            break;
        case VK_PIPELINE_STAGE_2_GEOMETRY_SHADER_BIT:
            jdata = "VK_PIPELINE_STAGE_2_GEOMETRY_SHADER_BIT";
            break;
        case VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT:
            jdata = "VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT";
            break;
        case VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT:
            jdata = "VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT";
            break;
        case VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT:
            jdata = "VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT";
            break;
        case VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT:
            jdata = "VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT";
            break;
        case VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT:
            jdata = "VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT";
            break;
        case VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT:
            jdata = "VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT";
            break;
        case VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT:
            jdata = "VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT";
            break;
        case VK_PIPELINE_STAGE_2_HOST_BIT:
            jdata = "VK_PIPELINE_STAGE_2_HOST_BIT";
            break;
        case VK_PIPELINE_STAGE_2_ALL_GRAPHICS_BIT:
            jdata = "VK_PIPELINE_STAGE_2_ALL_GRAPHICS_BIT";
            break;
        case VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT:
            jdata = "VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT";
            break;
        case VK_PIPELINE_STAGE_2_COPY_BIT:
            jdata = "VK_PIPELINE_STAGE_2_COPY_BIT";
            break;
        case VK_PIPELINE_STAGE_2_RESOLVE_BIT:
            jdata = "VK_PIPELINE_STAGE_2_RESOLVE_BIT";
            break;
        case VK_PIPELINE_STAGE_2_BLIT_BIT:
            jdata = "VK_PIPELINE_STAGE_2_BLIT_BIT";
            break;
        case VK_PIPELINE_STAGE_2_CLEAR_BIT:
            jdata = "VK_PIPELINE_STAGE_2_CLEAR_BIT";
            break;
        case VK_PIPELINE_STAGE_2_INDEX_INPUT_BIT:
            jdata = "VK_PIPELINE_STAGE_2_INDEX_INPUT_BIT";
            break;
        case VK_PIPELINE_STAGE_2_VERTEX_ATTRIBUTE_INPUT_BIT:
            jdata = "VK_PIPELINE_STAGE_2_VERTEX_ATTRIBUTE_INPUT_BIT";
            break;
        case VK_PIPELINE_STAGE_2_PRE_RASTERIZATION_SHADERS_BIT:
            jdata = "VK_PIPELINE_STAGE_2_PRE_RASTERIZATION_SHADERS_BIT";
            break;
        case VK_PIPELINE_STAGE_2_VIDEO_DECODE_BIT_KHR:
            jdata = "VK_PIPELINE_STAGE_2_VIDEO_DECODE_BIT_KHR";
            break;
        case VK_PIPELINE_STAGE_2_VIDEO_ENCODE_BIT_KHR:
            jdata = "VK_PIPELINE_STAGE_2_VIDEO_ENCODE_BIT_KHR";
            break;
        case VK_PIPELINE_STAGE_2_TRANSFORM_FEEDBACK_BIT_EXT:
            jdata = "VK_PIPELINE_STAGE_2_TRANSFORM_FEEDBACK_BIT_EXT";
            break;
        case VK_PIPELINE_STAGE_2_CONDITIONAL_RENDERING_BIT_EXT:
            jdata = "VK_PIPELINE_STAGE_2_CONDITIONAL_RENDERING_BIT_EXT";
            break;
        case VK_PIPELINE_STAGE_2_COMMAND_PREPROCESS_BIT_EXT:
            jdata = "VK_PIPELINE_STAGE_2_COMMAND_PREPROCESS_BIT_EXT";
            break;
        case VK_PIPELINE_STAGE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR:
            jdata = "VK_PIPELINE_STAGE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
            break;
        case VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR:
            jdata = "VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR";
            break;
        case VK_PIPELINE_STAGE_2_RAY_TRACING_SHADER_BIT_KHR:
            jdata = "VK_PIPELINE_STAGE_2_RAY_TRACING_SHADER_BIT_KHR";
            break;
        case VK_PIPELINE_STAGE_2_FRAGMENT_DENSITY_PROCESS_BIT_EXT:
            jdata = "VK_PIPELINE_STAGE_2_FRAGMENT_DENSITY_PROCESS_BIT_EXT";
            break;
        case VK_PIPELINE_STAGE_2_TASK_SHADER_BIT_EXT:
            jdata = "VK_PIPELINE_STAGE_2_TASK_SHADER_BIT_EXT";
            break;
        case VK_PIPELINE_STAGE_2_MESH_SHADER_BIT_EXT:
            jdata = "VK_PIPELINE_STAGE_2_MESH_SHADER_BIT_EXT";
            break;
        case VK_PIPELINE_STAGE_2_SUBPASS_SHADER_BIT_HUAWEI:
            jdata = "VK_PIPELINE_STAGE_2_SUBPASS_SHADER_BIT_HUAWEI";
            break;
        case VK_PIPELINE_STAGE_2_INVOCATION_MASK_BIT_HUAWEI:
            jdata = "VK_PIPELINE_STAGE_2_INVOCATION_MASK_BIT_HUAWEI";
            break;
        case VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_COPY_BIT_KHR:
            jdata = "VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_COPY_BIT_KHR";
            break;
        case VK_PIPELINE_STAGE_2_MICROMAP_BUILD_BIT_EXT:
            jdata = "VK_PIPELINE_STAGE_2_MICROMAP_BUILD_BIT_EXT";
            break;
        case VK_PIPELINE_STAGE_2_CLUSTER_CULLING_SHADER_BIT_HUAWEI:
            jdata = "VK_PIPELINE_STAGE_2_CLUSTER_CULLING_SHADER_BIT_HUAWEI";
            break;
        case VK_PIPELINE_STAGE_2_OPTICAL_FLOW_BIT_NV:
            jdata = "VK_PIPELINE_STAGE_2_OPTICAL_FLOW_BIT_NV";
            break;
        case VK_PIPELINE_STAGE_2_CONVERT_COOPERATIVE_VECTOR_MATRIX_BIT_NV:
            jdata = "VK_PIPELINE_STAGE_2_CONVERT_COOPERATIVE_VECTOR_MATRIX_BIT_NV";
            break;
        case VK_PIPELINE_STAGE_2_DATA_GRAPH_BIT_ARM:
            jdata = "VK_PIPELINE_STAGE_2_DATA_GRAPH_BIT_ARM";
            break;
        case VK_PIPELINE_STAGE_2_COPY_INDIRECT_BIT_KHR:
            jdata = "VK_PIPELINE_STAGE_2_COPY_INDIRECT_BIT_KHR";
            break;
        case VK_PIPELINE_STAGE_2_MEMORY_DECOMPRESSION_BIT_EXT:
            jdata = "VK_PIPELINE_STAGE_2_MEMORY_DECOMPRESSION_BIT_EXT";
            break;
        default:
            jdata = gfxrecon::decode::to_hex_fixed_width(static_cast<VkPipelineStageFlagBits2>(value));
            break;
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkTensorCreateFlagBitsARM_t& value)
{
    switch (static_cast<VkTensorCreateFlagBitsARM>(value)) {
        case VK_TENSOR_CREATE_MUTABLE_FORMAT_BIT_ARM:
            jdata = "VK_TENSOR_CREATE_MUTABLE_FORMAT_BIT_ARM";
            break;
        case VK_TENSOR_CREATE_PROTECTED_BIT_ARM:
            jdata = "VK_TENSOR_CREATE_PROTECTED_BIT_ARM";
            break;
        case VK_TENSOR_CREATE_DESCRIPTOR_HEAP_CAPTURE_REPLAY_BIT_ARM:
            jdata = "VK_TENSOR_CREATE_DESCRIPTOR_HEAP_CAPTURE_REPLAY_BIT_ARM";
            break;
        case VK_TENSOR_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_ARM:
            jdata = "VK_TENSOR_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_ARM";
            break;
        default:
            jdata = gfxrecon::decode::to_hex_fixed_width(static_cast<VkTensorCreateFlagBitsARM>(value));
            break;
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkTensorUsageFlagBitsARM_t& value)
{
    switch (static_cast<VkTensorUsageFlagBitsARM>(value)) {
        case VK_TENSOR_USAGE_SHADER_BIT_ARM:
            jdata = "VK_TENSOR_USAGE_SHADER_BIT_ARM";
            break;
        case VK_TENSOR_USAGE_TRANSFER_SRC_BIT_ARM:
            jdata = "VK_TENSOR_USAGE_TRANSFER_SRC_BIT_ARM";
            break;
        case VK_TENSOR_USAGE_TRANSFER_DST_BIT_ARM:
            jdata = "VK_TENSOR_USAGE_TRANSFER_DST_BIT_ARM";
            break;
        case VK_TENSOR_USAGE_IMAGE_ALIASING_BIT_ARM:
            jdata = "VK_TENSOR_USAGE_IMAGE_ALIASING_BIT_ARM";
            break;
        case VK_TENSOR_USAGE_DATA_GRAPH_BIT_ARM:
            jdata = "VK_TENSOR_USAGE_DATA_GRAPH_BIT_ARM";
            break;
        default:
            jdata = gfxrecon::decode::to_hex_fixed_width(static_cast<VkTensorUsageFlagBitsARM>(value));
            break;
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkTensorViewCreateFlagBitsARM_t& value)
{
    switch (static_cast<VkTensorViewCreateFlagBitsARM>(value)) {
        case VK_TENSOR_VIEW_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_ARM:
            jdata = "VK_TENSOR_VIEW_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_ARM";
            break;
        default:
            jdata = gfxrecon::decode::to_hex_fixed_width(static_cast<VkTensorViewCreateFlagBitsARM>(value));
            break;
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkAccelerationStructureCreateFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkAccelerationStructureCreateFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkAccelerationStructureCreateFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkAccelerationStructureCreateFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkAccelerationStructureMotionInfoFlagsNV_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkAccelerationStructureMotionInfoFlagsNV>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkAccelerationStructureMotionInstanceFlagsNV_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkAccelerationStructureMotionInstanceFlagsNV>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkAccessFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkAccessFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkAccessFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkAccessFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkAccessFlags2_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkAccessFlags2>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkAccessFlags2>(flags), [](VkFlags64 flags)
    {
        switch (flags)
        {
            case VK_ACCESS_2_NONE:
                return std::string("VK_ACCESS_2_NONE");
            case VK_ACCESS_2_INDIRECT_COMMAND_READ_BIT:
                return std::string("VK_ACCESS_2_INDIRECT_COMMAND_READ_BIT");
            case VK_ACCESS_2_INDEX_READ_BIT:
                return std::string("VK_ACCESS_2_INDEX_READ_BIT");
            case VK_ACCESS_2_VERTEX_ATTRIBUTE_READ_BIT:
                return std::string("VK_ACCESS_2_VERTEX_ATTRIBUTE_READ_BIT");
            case VK_ACCESS_2_UNIFORM_READ_BIT:
                return std::string("VK_ACCESS_2_UNIFORM_READ_BIT");
            case VK_ACCESS_2_INPUT_ATTACHMENT_READ_BIT:
                return std::string("VK_ACCESS_2_INPUT_ATTACHMENT_READ_BIT");
            case VK_ACCESS_2_SHADER_READ_BIT:
                return std::string("VK_ACCESS_2_SHADER_READ_BIT");
            case VK_ACCESS_2_SHADER_WRITE_BIT:
                return std::string("VK_ACCESS_2_SHADER_WRITE_BIT");
            case VK_ACCESS_2_COLOR_ATTACHMENT_READ_BIT:
                return std::string("VK_ACCESS_2_COLOR_ATTACHMENT_READ_BIT");
            case VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT:
                return std::string("VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT");
            case VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_READ_BIT:
                return std::string("VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_READ_BIT");
            case VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT:
                return std::string("VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT");
            case VK_ACCESS_2_TRANSFER_READ_BIT:
                return std::string("VK_ACCESS_2_TRANSFER_READ_BIT");
            case VK_ACCESS_2_TRANSFER_WRITE_BIT:
                return std::string("VK_ACCESS_2_TRANSFER_WRITE_BIT");
            case VK_ACCESS_2_HOST_READ_BIT:
                return std::string("VK_ACCESS_2_HOST_READ_BIT");
            case VK_ACCESS_2_HOST_WRITE_BIT:
                return std::string("VK_ACCESS_2_HOST_WRITE_BIT");
            case VK_ACCESS_2_MEMORY_READ_BIT:
                return std::string("VK_ACCESS_2_MEMORY_READ_BIT");
            case VK_ACCESS_2_MEMORY_WRITE_BIT:
                return std::string("VK_ACCESS_2_MEMORY_WRITE_BIT");
            case VK_ACCESS_2_SHADER_SAMPLED_READ_BIT:
                return std::string("VK_ACCESS_2_SHADER_SAMPLED_READ_BIT");
            case VK_ACCESS_2_SHADER_STORAGE_READ_BIT:
                return std::string("VK_ACCESS_2_SHADER_STORAGE_READ_BIT");
            case VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT:
                return std::string("VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT");
            case VK_ACCESS_2_VIDEO_DECODE_READ_BIT_KHR:
                return std::string("VK_ACCESS_2_VIDEO_DECODE_READ_BIT_KHR");
            case VK_ACCESS_2_VIDEO_DECODE_WRITE_BIT_KHR:
                return std::string("VK_ACCESS_2_VIDEO_DECODE_WRITE_BIT_KHR");
            case VK_ACCESS_2_SAMPLER_HEAP_READ_BIT_EXT:
                return std::string("VK_ACCESS_2_SAMPLER_HEAP_READ_BIT_EXT");
            case VK_ACCESS_2_RESOURCE_HEAP_READ_BIT_EXT:
                return std::string("VK_ACCESS_2_RESOURCE_HEAP_READ_BIT_EXT");
            case VK_ACCESS_2_VIDEO_ENCODE_READ_BIT_KHR:
                return std::string("VK_ACCESS_2_VIDEO_ENCODE_READ_BIT_KHR");
            case VK_ACCESS_2_VIDEO_ENCODE_WRITE_BIT_KHR:
                return std::string("VK_ACCESS_2_VIDEO_ENCODE_WRITE_BIT_KHR");
            case VK_ACCESS_2_SHADER_TILE_ATTACHMENT_READ_BIT_QCOM:
                return std::string("VK_ACCESS_2_SHADER_TILE_ATTACHMENT_READ_BIT_QCOM");
            case VK_ACCESS_2_SHADER_TILE_ATTACHMENT_WRITE_BIT_QCOM:
                return std::string("VK_ACCESS_2_SHADER_TILE_ATTACHMENT_WRITE_BIT_QCOM");
            case VK_ACCESS_2_TRANSFORM_FEEDBACK_WRITE_BIT_EXT:
                return std::string("VK_ACCESS_2_TRANSFORM_FEEDBACK_WRITE_BIT_EXT");
            case VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT:
                return std::string("VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT");
            case VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT:
                return std::string("VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT");
            case VK_ACCESS_2_CONDITIONAL_RENDERING_READ_BIT_EXT:
                return std::string("VK_ACCESS_2_CONDITIONAL_RENDERING_READ_BIT_EXT");
            case VK_ACCESS_2_COMMAND_PREPROCESS_READ_BIT_EXT:
                return std::string("VK_ACCESS_2_COMMAND_PREPROCESS_READ_BIT_EXT");
            case VK_ACCESS_2_COMMAND_PREPROCESS_WRITE_BIT_EXT:
                return std::string("VK_ACCESS_2_COMMAND_PREPROCESS_WRITE_BIT_EXT");
            case VK_ACCESS_2_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR:
                return std::string("VK_ACCESS_2_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR");
            case VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR:
                return std::string("VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR");
            case VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR:
                return std::string("VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR");
            case VK_ACCESS_2_FRAGMENT_DENSITY_MAP_READ_BIT_EXT:
                return std::string("VK_ACCESS_2_FRAGMENT_DENSITY_MAP_READ_BIT_EXT");
            case VK_ACCESS_2_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT:
                return std::string("VK_ACCESS_2_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT");
            case VK_ACCESS_2_DESCRIPTOR_BUFFER_READ_BIT_EXT:
                return std::string("VK_ACCESS_2_DESCRIPTOR_BUFFER_READ_BIT_EXT");
            case VK_ACCESS_2_INVOCATION_MASK_READ_BIT_HUAWEI:
                return std::string("VK_ACCESS_2_INVOCATION_MASK_READ_BIT_HUAWEI");
            case VK_ACCESS_2_SHADER_BINDING_TABLE_READ_BIT_KHR:
                return std::string("VK_ACCESS_2_SHADER_BINDING_TABLE_READ_BIT_KHR");
            case VK_ACCESS_2_MICROMAP_READ_BIT_EXT:
                return std::string("VK_ACCESS_2_MICROMAP_READ_BIT_EXT");
            case VK_ACCESS_2_MICROMAP_WRITE_BIT_EXT:
                return std::string("VK_ACCESS_2_MICROMAP_WRITE_BIT_EXT");
            case VK_ACCESS_2_OPTICAL_FLOW_READ_BIT_NV:
                return std::string("VK_ACCESS_2_OPTICAL_FLOW_READ_BIT_NV");
            case VK_ACCESS_2_OPTICAL_FLOW_WRITE_BIT_NV:
                return std::string("VK_ACCESS_2_OPTICAL_FLOW_WRITE_BIT_NV");
            case VK_ACCESS_2_DATA_GRAPH_READ_BIT_ARM:
                return std::string("VK_ACCESS_2_DATA_GRAPH_READ_BIT_ARM");
            case VK_ACCESS_2_DATA_GRAPH_WRITE_BIT_ARM:
                return std::string("VK_ACCESS_2_DATA_GRAPH_WRITE_BIT_ARM");
            case VK_ACCESS_2_MEMORY_DECOMPRESSION_READ_BIT_EXT:
                return std::string("VK_ACCESS_2_MEMORY_DECOMPRESSION_READ_BIT_EXT");
            case VK_ACCESS_2_MEMORY_DECOMPRESSION_WRITE_BIT_EXT:
                return std::string("VK_ACCESS_2_MEMORY_DECOMPRESSION_WRITE_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkAccessFlags3KHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkAccessFlags3KHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkAccessFlags3KHR>(flags), [](VkFlags64 flags)
    {
        switch (flags)
        {
            case VK_ACCESS_3_NONE_KHR:
                return std::string("VK_ACCESS_3_NONE_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkAcquireProfilingLockFlagsKHR_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkAcquireProfilingLockFlagsKHR>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkAddressCommandFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkAddressCommandFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkAddressCommandFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkAddressCommandFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkAddressCopyFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkAddressCopyFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkAddressCopyFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkAddressCopyFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkAndroidSurfaceCreateFlagsKHR_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkAndroidSurfaceCreateFlagsKHR>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkAttachmentDescriptionFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkAttachmentDescriptionFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkAttachmentDescriptionFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkAttachmentDescriptionFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkBufferCreateFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkBufferCreateFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkBufferCreateFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkBufferCreateFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkBufferUsageFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkBufferUsageFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkBufferUsageFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkBufferUsageFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkBufferUsageFlags2_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkBufferUsageFlags2>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkBufferUsageFlags2>(flags), [](VkFlags64 flags)
    {
        switch (flags)
        {
            case VK_BUFFER_USAGE_2_TRANSFER_SRC_BIT:
                return std::string("VK_BUFFER_USAGE_2_TRANSFER_SRC_BIT");
            case VK_BUFFER_USAGE_2_TRANSFER_DST_BIT:
                return std::string("VK_BUFFER_USAGE_2_TRANSFER_DST_BIT");
            case VK_BUFFER_USAGE_2_UNIFORM_TEXEL_BUFFER_BIT:
                return std::string("VK_BUFFER_USAGE_2_UNIFORM_TEXEL_BUFFER_BIT");
            case VK_BUFFER_USAGE_2_STORAGE_TEXEL_BUFFER_BIT:
                return std::string("VK_BUFFER_USAGE_2_STORAGE_TEXEL_BUFFER_BIT");
            case VK_BUFFER_USAGE_2_UNIFORM_BUFFER_BIT:
                return std::string("VK_BUFFER_USAGE_2_UNIFORM_BUFFER_BIT");
            case VK_BUFFER_USAGE_2_STORAGE_BUFFER_BIT:
                return std::string("VK_BUFFER_USAGE_2_STORAGE_BUFFER_BIT");
            case VK_BUFFER_USAGE_2_INDEX_BUFFER_BIT:
                return std::string("VK_BUFFER_USAGE_2_INDEX_BUFFER_BIT");
            case VK_BUFFER_USAGE_2_VERTEX_BUFFER_BIT:
                return std::string("VK_BUFFER_USAGE_2_VERTEX_BUFFER_BIT");
            case VK_BUFFER_USAGE_2_INDIRECT_BUFFER_BIT:
                return std::string("VK_BUFFER_USAGE_2_INDIRECT_BUFFER_BIT");
            case VK_BUFFER_USAGE_2_SHADER_DEVICE_ADDRESS_BIT:
                return std::string("VK_BUFFER_USAGE_2_SHADER_DEVICE_ADDRESS_BIT");
            case VK_BUFFER_USAGE_2_EXECUTION_GRAPH_SCRATCH_BIT_AMDX:
                return std::string("VK_BUFFER_USAGE_2_EXECUTION_GRAPH_SCRATCH_BIT_AMDX");
            case VK_BUFFER_USAGE_2_DESCRIPTOR_HEAP_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_2_DESCRIPTOR_HEAP_BIT_EXT");
            case VK_BUFFER_USAGE_2_MICROMAP_BUILD_INPUT_READ_ONLY_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_2_MICROMAP_BUILD_INPUT_READ_ONLY_BIT_EXT");
            case VK_BUFFER_USAGE_2_MICROMAP_STORAGE_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_2_MICROMAP_STORAGE_BIT_EXT");
            case VK_BUFFER_USAGE_2_CONDITIONAL_RENDERING_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_2_CONDITIONAL_RENDERING_BIT_EXT");
            case VK_BUFFER_USAGE_2_SHADER_BINDING_TABLE_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_SHADER_BINDING_TABLE_BIT_KHR");
            case VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT");
            case VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT");
            case VK_BUFFER_USAGE_2_VIDEO_DECODE_SRC_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_VIDEO_DECODE_SRC_BIT_KHR");
            case VK_BUFFER_USAGE_2_VIDEO_DECODE_DST_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_VIDEO_DECODE_DST_BIT_KHR");
            case VK_BUFFER_USAGE_2_VIDEO_ENCODE_DST_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_VIDEO_ENCODE_DST_BIT_KHR");
            case VK_BUFFER_USAGE_2_VIDEO_ENCODE_SRC_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_VIDEO_ENCODE_SRC_BIT_KHR");
            case VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR");
            case VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR");
            case VK_BUFFER_USAGE_2_SAMPLER_DESCRIPTOR_BUFFER_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_2_SAMPLER_DESCRIPTOR_BUFFER_BIT_EXT");
            case VK_BUFFER_USAGE_2_RESOURCE_DESCRIPTOR_BUFFER_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_2_RESOURCE_DESCRIPTOR_BUFFER_BIT_EXT");
            case VK_BUFFER_USAGE_2_PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_2_PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_BIT_EXT");
            case VK_BUFFER_USAGE_2_COMPRESSED_DATA_DGF1_BIT_AMDX:
                return std::string("VK_BUFFER_USAGE_2_COMPRESSED_DATA_DGF1_BIT_AMDX");
            case VK_BUFFER_USAGE_2_DATA_GRAPH_FOREIGN_DESCRIPTOR_BIT_ARM:
                return std::string("VK_BUFFER_USAGE_2_DATA_GRAPH_FOREIGN_DESCRIPTOR_BIT_ARM");
            case VK_BUFFER_USAGE_2_TILE_MEMORY_BIT_QCOM:
                return std::string("VK_BUFFER_USAGE_2_TILE_MEMORY_BIT_QCOM");
            case VK_BUFFER_USAGE_2_MEMORY_DECOMPRESSION_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_2_MEMORY_DECOMPRESSION_BIT_EXT");
            case VK_BUFFER_USAGE_2_PREPROCESS_BUFFER_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_2_PREPROCESS_BUFFER_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkBufferViewCreateFlags_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkBufferViewCreateFlags>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkBuildAccelerationStructureFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkBuildAccelerationStructureFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkBuildAccelerationStructureFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkBuildAccelerationStructureFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkBuildMicromapFlagsEXT_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkBuildMicromapFlagsEXT>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkBuildMicromapFlagsEXT>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkBuildMicromapFlagBitsEXT>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkColorComponentFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkColorComponentFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkColorComponentFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkColorComponentFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkCommandBufferResetFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkCommandBufferResetFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkCommandBufferResetFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkCommandBufferResetFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkCommandBufferUsageFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkCommandBufferUsageFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkCommandBufferUsageFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkCommandBufferUsageFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkCommandPoolCreateFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkCommandPoolCreateFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkCommandPoolCreateFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkCommandPoolCreateFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkCommandPoolResetFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkCommandPoolResetFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkCommandPoolResetFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkCommandPoolResetFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkCommandPoolTrimFlags_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkCommandPoolTrimFlags>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkCompositeAlphaFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkCompositeAlphaFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkCompositeAlphaFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkCompositeAlphaFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkConditionalRenderingFlagsEXT_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkConditionalRenderingFlagsEXT>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkConditionalRenderingFlagsEXT>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkConditionalRenderingFlagBitsEXT>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkCooperativeMatrixFlagsEXT_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkCooperativeMatrixFlagsEXT>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkCooperativeMatrixFlagsEXT>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkCooperativeMatrixFlagBitsEXT>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkCullModeFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkCullModeFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkCullModeFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkCullModeFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkDataGraphOpticalFlowCreateFlagsARM_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkDataGraphOpticalFlowCreateFlagsARM>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkDataGraphOpticalFlowCreateFlagsARM>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkDataGraphOpticalFlowCreateFlagBitsARM>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkDataGraphOpticalFlowExecuteFlagsARM_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkDataGraphOpticalFlowExecuteFlagsARM>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkDataGraphOpticalFlowExecuteFlagsARM>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkDataGraphOpticalFlowExecuteFlagBitsARM>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkDataGraphOpticalFlowGridSizeFlagsARM_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkDataGraphOpticalFlowGridSizeFlagsARM>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkDataGraphOpticalFlowGridSizeFlagsARM>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkDataGraphOpticalFlowGridSizeFlagBitsARM>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkDataGraphOpticalFlowImageUsageFlagsARM_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkDataGraphOpticalFlowImageUsageFlagsARM>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkDataGraphOpticalFlowImageUsageFlagsARM>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkDataGraphOpticalFlowImageUsageFlagBitsARM>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkDataGraphPipelineDispatchFlagsARM_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkDataGraphPipelineDispatchFlagsARM>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkDataGraphPipelineSessionCreateFlagsARM_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkDataGraphPipelineSessionCreateFlagsARM>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkDataGraphPipelineSessionCreateFlagsARM>(flags), [](VkFlags64 flags)
    {
        switch (flags)
        {
            case VK_DATA_GRAPH_PIPELINE_SESSION_CREATE_PROTECTED_BIT_ARM:
                return std::string("VK_DATA_GRAPH_PIPELINE_SESSION_CREATE_PROTECTED_BIT_ARM");
            case VK_DATA_GRAPH_PIPELINE_SESSION_CREATE_OPTICAL_FLOW_CACHE_BIT_ARM:
                return std::string("VK_DATA_GRAPH_PIPELINE_SESSION_CREATE_OPTICAL_FLOW_CACHE_BIT_ARM");
        }
        return to_hex_fixed_width(flags);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkDebugReportFlagsEXT_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkDebugReportFlagsEXT>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkDebugReportFlagsEXT>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkDebugReportFlagBitsEXT>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkDebugUtilsMessageSeverityFlagsEXT_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkDebugUtilsMessageSeverityFlagsEXT>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkDebugUtilsMessageSeverityFlagsEXT>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkDebugUtilsMessageSeverityFlagBitsEXT>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkDebugUtilsMessageTypeFlagsEXT_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkDebugUtilsMessageTypeFlagsEXT>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkDebugUtilsMessageTypeFlagsEXT>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkDebugUtilsMessageTypeFlagBitsEXT>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkDebugUtilsMessengerCallbackDataFlagsEXT_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkDebugUtilsMessengerCallbackDataFlagsEXT>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkDebugUtilsMessengerCreateFlagsEXT_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkDebugUtilsMessengerCreateFlagsEXT>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkDependencyFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkDependencyFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkDependencyFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkDependencyFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkDescriptorBindingFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkDescriptorBindingFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkDescriptorBindingFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkDescriptorBindingFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkDescriptorPoolCreateFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkDescriptorPoolCreateFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkDescriptorPoolCreateFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkDescriptorPoolCreateFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkDescriptorPoolResetFlags_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkDescriptorPoolResetFlags>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkDescriptorSetLayoutCreateFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkDescriptorSetLayoutCreateFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkDescriptorSetLayoutCreateFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkDescriptorSetLayoutCreateFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkDescriptorUpdateTemplateCreateFlags_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkDescriptorUpdateTemplateCreateFlags>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkDeviceAddressBindingFlagsEXT_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkDeviceAddressBindingFlagsEXT>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkDeviceAddressBindingFlagsEXT>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkDeviceAddressBindingFlagBitsEXT>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkDeviceCreateFlags_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkDeviceCreateFlags>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkDeviceDiagnosticsConfigFlagsNV_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkDeviceDiagnosticsConfigFlagsNV>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkDeviceDiagnosticsConfigFlagsNV>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkDeviceDiagnosticsConfigFlagBitsNV>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkDeviceFaultFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkDeviceFaultFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkDeviceFaultFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkDeviceFaultFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkDeviceGroupPresentModeFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkDeviceGroupPresentModeFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkDeviceGroupPresentModeFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkDeviceGroupPresentModeFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkDeviceMemoryReportFlagsEXT_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkDeviceMemoryReportFlagsEXT>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkDeviceQueueCreateFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkDeviceQueueCreateFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkDeviceQueueCreateFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkDeviceQueueCreateFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkDirectDriverLoadingFlagsLUNARG_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkDirectDriverLoadingFlagsLUNARG>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkDirectFBSurfaceCreateFlagsEXT_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkDirectFBSurfaceCreateFlagsEXT>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkDisplayModeCreateFlagsKHR_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkDisplayModeCreateFlagsKHR>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkDisplayPlaneAlphaFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkDisplayPlaneAlphaFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkDisplayPlaneAlphaFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkDisplayPlaneAlphaFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkDisplaySurfaceCreateFlagsKHR_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkDisplaySurfaceCreateFlagsKHR>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkEventCreateFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkEventCreateFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkEventCreateFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkEventCreateFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkExternalFenceFeatureFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkExternalFenceFeatureFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkExternalFenceFeatureFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkExternalFenceFeatureFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkExternalFenceHandleTypeFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkExternalFenceHandleTypeFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkExternalFenceHandleTypeFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkExternalFenceHandleTypeFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkExternalMemoryFeatureFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkExternalMemoryFeatureFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkExternalMemoryFeatureFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkExternalMemoryFeatureFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkExternalMemoryFeatureFlagsNV_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkExternalMemoryFeatureFlagsNV>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkExternalMemoryFeatureFlagsNV>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkExternalMemoryFeatureFlagBitsNV>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkExternalMemoryHandleTypeFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkExternalMemoryHandleTypeFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkExternalMemoryHandleTypeFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkExternalMemoryHandleTypeFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkExternalMemoryHandleTypeFlagsNV_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkExternalMemoryHandleTypeFlagsNV>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkExternalMemoryHandleTypeFlagsNV>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkExternalMemoryHandleTypeFlagBitsNV>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkExternalSemaphoreFeatureFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkExternalSemaphoreFeatureFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkExternalSemaphoreFeatureFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkExternalSemaphoreFeatureFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkExternalSemaphoreHandleTypeFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkExternalSemaphoreHandleTypeFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkExternalSemaphoreHandleTypeFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkExternalSemaphoreHandleTypeFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkFenceCreateFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkFenceCreateFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkFenceCreateFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkFenceCreateFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkFenceImportFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkFenceImportFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkFenceImportFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkFenceImportFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkFormatFeatureFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkFormatFeatureFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkFormatFeatureFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkFormatFeatureFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkFormatFeatureFlags2_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkFormatFeatureFlags2>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkFormatFeatureFlags2>(flags), [](VkFlags64 flags)
    {
        switch (flags)
        {
            case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT:
                return std::string("VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT");
            case VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT:
                return std::string("VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT");
            case VK_FORMAT_FEATURE_2_STORAGE_IMAGE_ATOMIC_BIT:
                return std::string("VK_FORMAT_FEATURE_2_STORAGE_IMAGE_ATOMIC_BIT");
            case VK_FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT:
                return std::string("VK_FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT");
            case VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_BIT:
                return std::string("VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_BIT");
            case VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_ATOMIC_BIT:
                return std::string("VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_ATOMIC_BIT");
            case VK_FORMAT_FEATURE_2_VERTEX_BUFFER_BIT:
                return std::string("VK_FORMAT_FEATURE_2_VERTEX_BUFFER_BIT");
            case VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BIT:
                return std::string("VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BIT");
            case VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BLEND_BIT:
                return std::string("VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BLEND_BIT");
            case VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT:
                return std::string("VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT");
            case VK_FORMAT_FEATURE_2_BLIT_SRC_BIT:
                return std::string("VK_FORMAT_FEATURE_2_BLIT_SRC_BIT");
            case VK_FORMAT_FEATURE_2_BLIT_DST_BIT:
                return std::string("VK_FORMAT_FEATURE_2_BLIT_DST_BIT");
            case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_BIT:
                return std::string("VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_BIT");
            case VK_FORMAT_FEATURE_2_TRANSFER_SRC_BIT:
                return std::string("VK_FORMAT_FEATURE_2_TRANSFER_SRC_BIT");
            case VK_FORMAT_FEATURE_2_TRANSFER_DST_BIT:
                return std::string("VK_FORMAT_FEATURE_2_TRANSFER_DST_BIT");
            case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_MINMAX_BIT:
                return std::string("VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_MINMAX_BIT");
            case VK_FORMAT_FEATURE_2_MIDPOINT_CHROMA_SAMPLES_BIT:
                return std::string("VK_FORMAT_FEATURE_2_MIDPOINT_CHROMA_SAMPLES_BIT");
            case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT:
                return std::string("VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT");
            case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT:
                return std::string("VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT");
            case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT:
                return std::string("VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT");
            case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT:
                return std::string("VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT");
            case VK_FORMAT_FEATURE_2_DISJOINT_BIT:
                return std::string("VK_FORMAT_FEATURE_2_DISJOINT_BIT");
            case VK_FORMAT_FEATURE_2_COSITED_CHROMA_SAMPLES_BIT:
                return std::string("VK_FORMAT_FEATURE_2_COSITED_CHROMA_SAMPLES_BIT");
            case VK_FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT:
                return std::string("VK_FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT");
            case VK_FORMAT_FEATURE_2_STORAGE_WRITE_WITHOUT_FORMAT_BIT:
                return std::string("VK_FORMAT_FEATURE_2_STORAGE_WRITE_WITHOUT_FORMAT_BIT");
            case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_DEPTH_COMPARISON_BIT:
                return std::string("VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_DEPTH_COMPARISON_BIT");
            case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT:
                return std::string("VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT");
            case VK_FORMAT_FEATURE_2_HOST_IMAGE_TRANSFER_BIT:
                return std::string("VK_FORMAT_FEATURE_2_HOST_IMAGE_TRANSFER_BIT");
            case VK_FORMAT_FEATURE_2_VIDEO_DECODE_OUTPUT_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_2_VIDEO_DECODE_OUTPUT_BIT_KHR");
            case VK_FORMAT_FEATURE_2_VIDEO_DECODE_DPB_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_2_VIDEO_DECODE_DPB_BIT_KHR");
            case VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR");
            case VK_FORMAT_FEATURE_2_FRAGMENT_DENSITY_MAP_BIT_EXT:
                return std::string("VK_FORMAT_FEATURE_2_FRAGMENT_DENSITY_MAP_BIT_EXT");
            case VK_FORMAT_FEATURE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR");
            case VK_FORMAT_FEATURE_2_VIDEO_ENCODE_INPUT_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_2_VIDEO_ENCODE_INPUT_BIT_KHR");
            case VK_FORMAT_FEATURE_2_VIDEO_ENCODE_DPB_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_2_VIDEO_ENCODE_DPB_BIT_KHR");
            case VK_FORMAT_FEATURE_2_BLOCK_MATCHING_SXD_BIT_QCOM:
                return std::string("VK_FORMAT_FEATURE_2_BLOCK_MATCHING_SXD_BIT_QCOM");
            case VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_RADIUS_BUFFER_BIT_NV:
                return std::string("VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_RADIUS_BUFFER_BIT_NV");
            case VK_FORMAT_FEATURE_2_LINEAR_COLOR_ATTACHMENT_BIT_NV:
                return std::string("VK_FORMAT_FEATURE_2_LINEAR_COLOR_ATTACHMENT_BIT_NV");
            case VK_FORMAT_FEATURE_2_WEIGHT_IMAGE_BIT_QCOM:
                return std::string("VK_FORMAT_FEATURE_2_WEIGHT_IMAGE_BIT_QCOM");
            case VK_FORMAT_FEATURE_2_WEIGHT_SAMPLED_IMAGE_BIT_QCOM:
                return std::string("VK_FORMAT_FEATURE_2_WEIGHT_SAMPLED_IMAGE_BIT_QCOM");
            case VK_FORMAT_FEATURE_2_BLOCK_MATCHING_BIT_QCOM:
                return std::string("VK_FORMAT_FEATURE_2_BLOCK_MATCHING_BIT_QCOM");
            case VK_FORMAT_FEATURE_2_BOX_FILTER_SAMPLED_BIT_QCOM:
                return std::string("VK_FORMAT_FEATURE_2_BOX_FILTER_SAMPLED_BIT_QCOM");
            case VK_FORMAT_FEATURE_2_TENSOR_SHADER_BIT_ARM:
                return std::string("VK_FORMAT_FEATURE_2_TENSOR_SHADER_BIT_ARM");
            case VK_FORMAT_FEATURE_2_TENSOR_IMAGE_ALIASING_BIT_ARM:
                return std::string("VK_FORMAT_FEATURE_2_TENSOR_IMAGE_ALIASING_BIT_ARM");
            case VK_FORMAT_FEATURE_2_OPTICAL_FLOW_IMAGE_BIT_NV:
                return std::string("VK_FORMAT_FEATURE_2_OPTICAL_FLOW_IMAGE_BIT_NV");
            case VK_FORMAT_FEATURE_2_OPTICAL_FLOW_VECTOR_BIT_NV:
                return std::string("VK_FORMAT_FEATURE_2_OPTICAL_FLOW_VECTOR_BIT_NV");
            case VK_FORMAT_FEATURE_2_OPTICAL_FLOW_COST_BIT_NV:
                return std::string("VK_FORMAT_FEATURE_2_OPTICAL_FLOW_COST_BIT_NV");
            case VK_FORMAT_FEATURE_2_TENSOR_DATA_GRAPH_BIT_ARM:
                return std::string("VK_FORMAT_FEATURE_2_TENSOR_DATA_GRAPH_BIT_ARM");
            case VK_FORMAT_FEATURE_2_COPY_IMAGE_INDIRECT_DST_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_2_COPY_IMAGE_INDIRECT_DST_BIT_KHR");
            case VK_FORMAT_FEATURE_2_VIDEO_ENCODE_QUANTIZATION_DELTA_MAP_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_2_VIDEO_ENCODE_QUANTIZATION_DELTA_MAP_BIT_KHR");
            case VK_FORMAT_FEATURE_2_VIDEO_ENCODE_EMPHASIS_MAP_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_2_VIDEO_ENCODE_EMPHASIS_MAP_BIT_KHR");
            case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_2D_BIT_IMG:
                return std::string("VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_2D_BIT_IMG");
            case VK_FORMAT_FEATURE_2_DEPTH_COPY_ON_COMPUTE_QUEUE_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_2_DEPTH_COPY_ON_COMPUTE_QUEUE_BIT_KHR");
            case VK_FORMAT_FEATURE_2_DEPTH_COPY_ON_TRANSFER_QUEUE_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_2_DEPTH_COPY_ON_TRANSFER_QUEUE_BIT_KHR");
            case VK_FORMAT_FEATURE_2_STENCIL_COPY_ON_COMPUTE_QUEUE_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_2_STENCIL_COPY_ON_COMPUTE_QUEUE_BIT_KHR");
            case VK_FORMAT_FEATURE_2_STENCIL_COPY_ON_TRANSFER_QUEUE_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_2_STENCIL_COPY_ON_TRANSFER_QUEUE_BIT_KHR");
            case VK_FORMAT_FEATURE_2_DATA_GRAPH_OPTICAL_FLOW_IMAGE_BIT_ARM:
                return std::string("VK_FORMAT_FEATURE_2_DATA_GRAPH_OPTICAL_FLOW_IMAGE_BIT_ARM");
            case VK_FORMAT_FEATURE_2_DATA_GRAPH_OPTICAL_FLOW_VECTOR_BIT_ARM:
                return std::string("VK_FORMAT_FEATURE_2_DATA_GRAPH_OPTICAL_FLOW_VECTOR_BIT_ARM");
            case VK_FORMAT_FEATURE_2_DATA_GRAPH_OPTICAL_FLOW_COST_BIT_ARM:
                return std::string("VK_FORMAT_FEATURE_2_DATA_GRAPH_OPTICAL_FLOW_COST_BIT_ARM");
        }
        return to_hex_fixed_width(flags);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkFormatFeatureFlags4KHR_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkFormatFeatureFlags4KHR>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkFrameBoundaryFlagsEXT_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkFrameBoundaryFlagsEXT>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkFrameBoundaryFlagsEXT>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkFrameBoundaryFlagBitsEXT>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkFramebufferCreateFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkFramebufferCreateFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkFramebufferCreateFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkFramebufferCreateFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkGeometryFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkGeometryFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkGeometryFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkGeometryFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkGeometryInstanceFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkGeometryInstanceFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkGeometryInstanceFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkGeometryInstanceFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkGpaPerfBlockPropertiesFlagsAMD_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkGpaPerfBlockPropertiesFlagsAMD>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkGpaSqShaderStageFlagsAMD_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkGpaSqShaderStageFlagsAMD>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkGpaSqShaderStageFlagsAMD>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkGpaSqShaderStageFlagBitsAMD>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkGraphicsPipelineLibraryFlagsEXT_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkGraphicsPipelineLibraryFlagsEXT>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkGraphicsPipelineLibraryFlagsEXT>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkGraphicsPipelineLibraryFlagBitsEXT>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkHeadlessSurfaceCreateFlagsEXT_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkHeadlessSurfaceCreateFlagsEXT>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkHostImageCopyFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkHostImageCopyFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkHostImageCopyFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkHostImageCopyFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkIOSSurfaceCreateFlagsMVK_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkIOSSurfaceCreateFlagsMVK>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkImageAspectFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkImageAspectFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkImageAspectFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkImageAspectFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkImageCompressionFixedRateFlagsEXT_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkImageCompressionFixedRateFlagsEXT>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkImageCompressionFixedRateFlagsEXT>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkImageCompressionFixedRateFlagBitsEXT>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkImageCompressionFlagsEXT_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkImageCompressionFlagsEXT>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkImageCompressionFlagsEXT>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkImageCompressionFlagBitsEXT>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkImageCreateFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkImageCreateFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkImageCreateFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkImageCreateFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkImageCreateFlags2KHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkImageCreateFlags2KHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkImageCreateFlags2KHR>(flags), [](VkFlags64 flags)
    {
        switch (flags)
        {
            case VK_IMAGE_CREATE_2_SPARSE_BINDING_BIT_KHR:
                return std::string("VK_IMAGE_CREATE_2_SPARSE_BINDING_BIT_KHR");
            case VK_IMAGE_CREATE_2_SPARSE_RESIDENCY_BIT_KHR:
                return std::string("VK_IMAGE_CREATE_2_SPARSE_RESIDENCY_BIT_KHR");
            case VK_IMAGE_CREATE_2_SPARSE_ALIASED_BIT_KHR:
                return std::string("VK_IMAGE_CREATE_2_SPARSE_ALIASED_BIT_KHR");
            case VK_IMAGE_CREATE_2_MUTABLE_FORMAT_BIT_KHR:
                return std::string("VK_IMAGE_CREATE_2_MUTABLE_FORMAT_BIT_KHR");
            case VK_IMAGE_CREATE_2_CUBE_COMPATIBLE_BIT_KHR:
                return std::string("VK_IMAGE_CREATE_2_CUBE_COMPATIBLE_BIT_KHR");
            case VK_IMAGE_CREATE_2_ALIAS_SINGLE_LAYER_DESCRIPTOR_BIT_KHR:
                return std::string("VK_IMAGE_CREATE_2_ALIAS_SINGLE_LAYER_DESCRIPTOR_BIT_KHR");
            case VK_IMAGE_CREATE_2_2D_ARRAY_COMPATIBLE_BIT_KHR:
                return std::string("VK_IMAGE_CREATE_2_2D_ARRAY_COMPATIBLE_BIT_KHR");
            case VK_IMAGE_CREATE_2_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR:
                return std::string("VK_IMAGE_CREATE_2_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR");
            case VK_IMAGE_CREATE_2_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT_KHR:
                return std::string("VK_IMAGE_CREATE_2_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT_KHR");
            case VK_IMAGE_CREATE_2_EXTENDED_USAGE_BIT_KHR:
                return std::string("VK_IMAGE_CREATE_2_EXTENDED_USAGE_BIT_KHR");
            case VK_IMAGE_CREATE_2_DISJOINT_BIT_KHR:
                return std::string("VK_IMAGE_CREATE_2_DISJOINT_BIT_KHR");
            case VK_IMAGE_CREATE_2_ALIAS_BIT_KHR:
                return std::string("VK_IMAGE_CREATE_2_ALIAS_BIT_KHR");
            case VK_IMAGE_CREATE_2_PROTECTED_BIT_KHR:
                return std::string("VK_IMAGE_CREATE_2_PROTECTED_BIT_KHR");
            case VK_IMAGE_CREATE_2_SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_BIT_EXT:
                return std::string("VK_IMAGE_CREATE_2_SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_BIT_EXT");
            case VK_IMAGE_CREATE_2_CORNER_SAMPLED_BIT_NV:
                return std::string("VK_IMAGE_CREATE_2_CORNER_SAMPLED_BIT_NV");
            case VK_IMAGE_CREATE_2_SUBSAMPLED_BIT_EXT:
                return std::string("VK_IMAGE_CREATE_2_SUBSAMPLED_BIT_EXT");
            case VK_IMAGE_CREATE_2_FRAGMENT_DENSITY_MAP_OFFSET_BIT_EXT:
                return std::string("VK_IMAGE_CREATE_2_FRAGMENT_DENSITY_MAP_OFFSET_BIT_EXT");
            case VK_IMAGE_CREATE_2_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT:
                return std::string("VK_IMAGE_CREATE_2_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT");
            case VK_IMAGE_CREATE_2_2D_VIEW_COMPATIBLE_BIT_EXT:
                return std::string("VK_IMAGE_CREATE_2_2D_VIEW_COMPATIBLE_BIT_EXT");
            case VK_IMAGE_CREATE_2_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_BIT_EXT:
                return std::string("VK_IMAGE_CREATE_2_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_BIT_EXT");
            case VK_IMAGE_CREATE_2_VIDEO_PROFILE_INDEPENDENT_BIT_KHR:
                return std::string("VK_IMAGE_CREATE_2_VIDEO_PROFILE_INDEPENDENT_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkImagePipeSurfaceCreateFlagsFUCHSIA_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkImagePipeSurfaceCreateFlagsFUCHSIA>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkImageUsageFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkImageUsageFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkImageUsageFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkImageUsageFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkImageUsageFlags2KHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkImageUsageFlags2KHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkImageUsageFlags2KHR>(flags), [](VkFlags64 flags)
    {
        switch (flags)
        {
            case VK_IMAGE_USAGE_2_TRANSFER_SRC_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_2_TRANSFER_SRC_BIT_KHR");
            case VK_IMAGE_USAGE_2_TRANSFER_DST_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_2_TRANSFER_DST_BIT_KHR");
            case VK_IMAGE_USAGE_2_SAMPLED_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_2_SAMPLED_BIT_KHR");
            case VK_IMAGE_USAGE_2_STORAGE_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_2_STORAGE_BIT_KHR");
            case VK_IMAGE_USAGE_2_COLOR_ATTACHMENT_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_2_COLOR_ATTACHMENT_BIT_KHR");
            case VK_IMAGE_USAGE_2_DEPTH_STENCIL_ATTACHMENT_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_2_DEPTH_STENCIL_ATTACHMENT_BIT_KHR");
            case VK_IMAGE_USAGE_2_TRANSIENT_ATTACHMENT_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_2_TRANSIENT_ATTACHMENT_BIT_KHR");
            case VK_IMAGE_USAGE_2_INPUT_ATTACHMENT_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_2_INPUT_ATTACHMENT_BIT_KHR");
            case VK_IMAGE_USAGE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR");
            case VK_IMAGE_USAGE_2_FRAGMENT_DENSITY_MAP_BIT_EXT:
                return std::string("VK_IMAGE_USAGE_2_FRAGMENT_DENSITY_MAP_BIT_EXT");
            case VK_IMAGE_USAGE_2_VIDEO_DECODE_DST_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_2_VIDEO_DECODE_DST_BIT_KHR");
            case VK_IMAGE_USAGE_2_VIDEO_DECODE_SRC_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_2_VIDEO_DECODE_SRC_BIT_KHR");
            case VK_IMAGE_USAGE_2_VIDEO_DECODE_DPB_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_2_VIDEO_DECODE_DPB_BIT_KHR");
            case VK_IMAGE_USAGE_2_VIDEO_ENCODE_DST_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_2_VIDEO_ENCODE_DST_BIT_KHR");
            case VK_IMAGE_USAGE_2_VIDEO_ENCODE_SRC_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_2_VIDEO_ENCODE_SRC_BIT_KHR");
            case VK_IMAGE_USAGE_2_VIDEO_ENCODE_DPB_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_2_VIDEO_ENCODE_DPB_BIT_KHR");
            case VK_IMAGE_USAGE_2_INVOCATION_MASK_BIT_HUAWEI:
                return std::string("VK_IMAGE_USAGE_2_INVOCATION_MASK_BIT_HUAWEI");
            case VK_IMAGE_USAGE_2_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT:
                return std::string("VK_IMAGE_USAGE_2_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT");
            case VK_IMAGE_USAGE_2_SAMPLE_WEIGHT_BIT_QCOM:
                return std::string("VK_IMAGE_USAGE_2_SAMPLE_WEIGHT_BIT_QCOM");
            case VK_IMAGE_USAGE_2_SAMPLE_BLOCK_MATCH_BIT_QCOM:
                return std::string("VK_IMAGE_USAGE_2_SAMPLE_BLOCK_MATCH_BIT_QCOM");
            case VK_IMAGE_USAGE_2_HOST_TRANSFER_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_2_HOST_TRANSFER_BIT_KHR");
            case VK_IMAGE_USAGE_2_TENSOR_ALIASING_BIT_ARM:
                return std::string("VK_IMAGE_USAGE_2_TENSOR_ALIASING_BIT_ARM");
            case VK_IMAGE_USAGE_2_VIDEO_ENCODE_QUANTIZATION_DELTA_MAP_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_2_VIDEO_ENCODE_QUANTIZATION_DELTA_MAP_BIT_KHR");
            case VK_IMAGE_USAGE_2_VIDEO_ENCODE_EMPHASIS_MAP_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_2_VIDEO_ENCODE_EMPHASIS_MAP_BIT_KHR");
            case VK_IMAGE_USAGE_2_TILE_MEMORY_BIT_QCOM:
                return std::string("VK_IMAGE_USAGE_2_TILE_MEMORY_BIT_QCOM");
        }
        return to_hex_fixed_width(flags);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkImageViewCreateFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkImageViewCreateFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkImageViewCreateFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkImageViewCreateFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkIndirectCommandsInputModeFlagsEXT_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkIndirectCommandsInputModeFlagsEXT>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkIndirectCommandsInputModeFlagsEXT>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkIndirectCommandsInputModeFlagBitsEXT>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkIndirectCommandsLayoutUsageFlagsEXT_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkIndirectCommandsLayoutUsageFlagsEXT>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkIndirectCommandsLayoutUsageFlagsEXT>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkIndirectCommandsLayoutUsageFlagBitsEXT>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkIndirectCommandsLayoutUsageFlagsNV_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkIndirectCommandsLayoutUsageFlagsNV>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkIndirectCommandsLayoutUsageFlagsNV>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkIndirectCommandsLayoutUsageFlagBitsNV>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkIndirectStateFlagsNV_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkIndirectStateFlagsNV>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkIndirectStateFlagsNV>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkIndirectStateFlagBitsNV>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkInstanceCreateFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkInstanceCreateFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkInstanceCreateFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkInstanceCreateFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkMacOSSurfaceCreateFlagsMVK_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkMacOSSurfaceCreateFlagsMVK>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkMemoryAllocateFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkMemoryAllocateFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkMemoryAllocateFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkMemoryAllocateFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkMemoryDecompressionMethodFlagsEXT_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkMemoryDecompressionMethodFlagsEXT>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkMemoryDecompressionMethodFlagsEXT>(flags), [](VkFlags64 flags)
    {
        switch (flags)
        {
            case VK_MEMORY_DECOMPRESSION_METHOD_GDEFLATE_1_0_BIT_EXT:
                return std::string("VK_MEMORY_DECOMPRESSION_METHOD_GDEFLATE_1_0_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkMemoryHeapFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkMemoryHeapFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkMemoryHeapFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkMemoryHeapFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkMemoryMapFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkMemoryMapFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkMemoryMapFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkMemoryMapFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkMemoryPropertyFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkMemoryPropertyFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkMemoryPropertyFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkMemoryPropertyFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkMemoryUnmapFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkMemoryUnmapFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkMemoryUnmapFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkMemoryUnmapFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkMetalSurfaceCreateFlagsEXT_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkMetalSurfaceCreateFlagsEXT>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkMicromapCreateFlagsEXT_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkMicromapCreateFlagsEXT>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkMicromapCreateFlagsEXT>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkMicromapCreateFlagBitsEXT>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkOpticalFlowExecuteFlagsNV_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkOpticalFlowExecuteFlagsNV>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkOpticalFlowExecuteFlagsNV>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkOpticalFlowExecuteFlagBitsNV>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkOpticalFlowGridSizeFlagsNV_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkOpticalFlowGridSizeFlagsNV>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkOpticalFlowGridSizeFlagsNV>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkOpticalFlowGridSizeFlagBitsNV>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkOpticalFlowSessionCreateFlagsNV_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkOpticalFlowSessionCreateFlagsNV>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkOpticalFlowSessionCreateFlagsNV>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkOpticalFlowSessionCreateFlagBitsNV>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkOpticalFlowUsageFlagsNV_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkOpticalFlowUsageFlagsNV>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkOpticalFlowUsageFlagsNV>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkOpticalFlowUsageFlagBitsNV>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkPartitionedAccelerationStructureInstanceFlagsNV_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkPartitionedAccelerationStructureInstanceFlagsNV>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkPartitionedAccelerationStructureInstanceFlagsNV>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkPartitionedAccelerationStructureInstanceFlagBitsNV>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkPastPresentationTimingFlagsEXT_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkPastPresentationTimingFlagsEXT>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkPastPresentationTimingFlagsEXT>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkPastPresentationTimingFlagBitsEXT>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkPeerMemoryFeatureFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkPeerMemoryFeatureFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkPeerMemoryFeatureFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkPeerMemoryFeatureFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkPerformanceCounterDescriptionFlagsARM_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkPerformanceCounterDescriptionFlagsARM>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkPerformanceCounterDescriptionFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkPerformanceCounterDescriptionFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkPerformanceCounterDescriptionFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkPerformanceCounterDescriptionFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkPhysicalDeviceGpaPropertiesFlagsAMD_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkPhysicalDeviceGpaPropertiesFlagsAMD>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkPhysicalDeviceSchedulingControlsFlagsARM_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkPhysicalDeviceSchedulingControlsFlagsARM>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkPhysicalDeviceSchedulingControlsFlagsARM>(flags), [](VkFlags64 flags)
    {
        switch (flags)
        {
            case VK_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_SHADER_CORE_COUNT_ARM:
                return std::string("VK_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_SHADER_CORE_COUNT_ARM");
            case VK_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_DISPATCH_PARAMETERS_ARM:
                return std::string("VK_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_DISPATCH_PARAMETERS_ARM");
        }
        return to_hex_fixed_width(flags);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineCacheCreateFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkPipelineCacheCreateFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkPipelineCacheCreateFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkPipelineCacheCreateFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineColorBlendStateCreateFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkPipelineColorBlendStateCreateFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkPipelineColorBlendStateCreateFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkPipelineColorBlendStateCreateFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineCompilerControlFlagsAMD_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkPipelineCompilerControlFlagsAMD>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineCoverageModulationStateCreateFlagsNV_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkPipelineCoverageModulationStateCreateFlagsNV>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineCoverageReductionStateCreateFlagsNV_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkPipelineCoverageReductionStateCreateFlagsNV>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineCoverageToColorStateCreateFlagsNV_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkPipelineCoverageToColorStateCreateFlagsNV>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineCreateFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkPipelineCreateFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkPipelineCreateFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkPipelineCreateFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineCreateFlags2_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkPipelineCreateFlags2>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkPipelineCreateFlags2>(flags), [](VkFlags64 flags)
    {
        switch (flags)
        {
            case VK_PIPELINE_CREATE_2_DISABLE_OPTIMIZATION_BIT:
                return std::string("VK_PIPELINE_CREATE_2_DISABLE_OPTIMIZATION_BIT");
            case VK_PIPELINE_CREATE_2_ALLOW_DERIVATIVES_BIT:
                return std::string("VK_PIPELINE_CREATE_2_ALLOW_DERIVATIVES_BIT");
            case VK_PIPELINE_CREATE_2_DERIVATIVE_BIT:
                return std::string("VK_PIPELINE_CREATE_2_DERIVATIVE_BIT");
            case VK_PIPELINE_CREATE_2_VIEW_INDEX_FROM_DEVICE_INDEX_BIT:
                return std::string("VK_PIPELINE_CREATE_2_VIEW_INDEX_FROM_DEVICE_INDEX_BIT");
            case VK_PIPELINE_CREATE_2_DISPATCH_BASE_BIT:
                return std::string("VK_PIPELINE_CREATE_2_DISPATCH_BASE_BIT");
            case VK_PIPELINE_CREATE_2_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT:
                return std::string("VK_PIPELINE_CREATE_2_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT");
            case VK_PIPELINE_CREATE_2_EARLY_RETURN_ON_FAILURE_BIT:
                return std::string("VK_PIPELINE_CREATE_2_EARLY_RETURN_ON_FAILURE_BIT");
            case VK_PIPELINE_CREATE_2_NO_PROTECTED_ACCESS_BIT:
                return std::string("VK_PIPELINE_CREATE_2_NO_PROTECTED_ACCESS_BIT");
            case VK_PIPELINE_CREATE_2_PROTECTED_ACCESS_ONLY_BIT:
                return std::string("VK_PIPELINE_CREATE_2_PROTECTED_ACCESS_ONLY_BIT");
            case VK_PIPELINE_CREATE_2_EXECUTION_GRAPH_BIT_AMDX:
                return std::string("VK_PIPELINE_CREATE_2_EXECUTION_GRAPH_BIT_AMDX");
            case VK_PIPELINE_CREATE_2_DESCRIPTOR_HEAP_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_2_DESCRIPTOR_HEAP_BIT_EXT");
            case VK_PIPELINE_CREATE_2_RAY_TRACING_ALLOW_SPHERES_AND_LINEAR_SWEPT_SPHERES_BIT_NV:
                return std::string("VK_PIPELINE_CREATE_2_RAY_TRACING_ALLOW_SPHERES_AND_LINEAR_SWEPT_SPHERES_BIT_NV");
            case VK_PIPELINE_CREATE_2_ENABLE_LEGACY_DITHERING_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_2_ENABLE_LEGACY_DITHERING_BIT_EXT");
            case VK_PIPELINE_CREATE_2_DEFER_COMPILE_BIT_NV:
                return std::string("VK_PIPELINE_CREATE_2_DEFER_COMPILE_BIT_NV");
            case VK_PIPELINE_CREATE_2_CAPTURE_STATISTICS_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_CAPTURE_STATISTICS_BIT_KHR");
            case VK_PIPELINE_CREATE_2_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR");
            case VK_PIPELINE_CREATE_2_LINK_TIME_OPTIMIZATION_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_2_LINK_TIME_OPTIMIZATION_BIT_EXT");
            case VK_PIPELINE_CREATE_2_RETAIN_LINK_TIME_OPTIMIZATION_INFO_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_2_RETAIN_LINK_TIME_OPTIMIZATION_INFO_BIT_EXT");
            case VK_PIPELINE_CREATE_2_LIBRARY_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_LIBRARY_BIT_KHR");
            case VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR");
            case VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_AABBS_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_AABBS_BIT_KHR");
            case VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR");
            case VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR");
            case VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR");
            case VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR");
            case VK_PIPELINE_CREATE_2_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR");
            case VK_PIPELINE_CREATE_2_INDIRECT_BINDABLE_BIT_NV:
                return std::string("VK_PIPELINE_CREATE_2_INDIRECT_BINDABLE_BIT_NV");
            case VK_PIPELINE_CREATE_2_RAY_TRACING_ALLOW_MOTION_BIT_NV:
                return std::string("VK_PIPELINE_CREATE_2_RAY_TRACING_ALLOW_MOTION_BIT_NV");
            case VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR");
            case VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT");
            case VK_PIPELINE_CREATE_2_COLOR_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_2_COLOR_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT");
            case VK_PIPELINE_CREATE_2_DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_2_DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT");
            case VK_PIPELINE_CREATE_2_RAY_TRACING_DISPLACEMENT_MICROMAP_BIT_NV:
                return std::string("VK_PIPELINE_CREATE_2_RAY_TRACING_DISPLACEMENT_MICROMAP_BIT_NV");
            case VK_PIPELINE_CREATE_2_DESCRIPTOR_BUFFER_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_2_DESCRIPTOR_BUFFER_BIT_EXT");
            case VK_PIPELINE_CREATE_2_DISALLOW_OPACITY_MICROMAP_BIT_ARM:
                return std::string("VK_PIPELINE_CREATE_2_DISALLOW_OPACITY_MICROMAP_BIT_ARM");
            case VK_PIPELINE_CREATE_2_INSTRUMENT_SHADERS_BIT_ARM:
                return std::string("VK_PIPELINE_CREATE_2_INSTRUMENT_SHADERS_BIT_ARM");
            case VK_PIPELINE_CREATE_2_CAPTURE_DATA_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_CAPTURE_DATA_BIT_KHR");
            case VK_PIPELINE_CREATE_2_INDIRECT_BINDABLE_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_2_INDIRECT_BINDABLE_BIT_EXT");
            case VK_PIPELINE_CREATE_2_PER_LAYER_FRAGMENT_DENSITY_BIT_VALVE:
                return std::string("VK_PIPELINE_CREATE_2_PER_LAYER_FRAGMENT_DENSITY_BIT_VALVE");
            case VK_PIPELINE_CREATE_2_RAY_TRACING_OPACITY_MICROMAP_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_RAY_TRACING_OPACITY_MICROMAP_BIT_KHR");
            case VK_PIPELINE_CREATE_2_OPACITY_MICROMAP_DISALLOW_MIXED_SPECIAL_INDEX_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_OPACITY_MICROMAP_DISALLOW_MIXED_SPECIAL_INDEX_BIT_KHR");
            case VK_PIPELINE_CREATE_2_64_BIT_INDEXING_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_2_64_BIT_INDEXING_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineCreationFeedbackFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkPipelineCreationFeedbackFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkPipelineCreationFeedbackFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkPipelineCreationFeedbackFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineDepthStencilStateCreateFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkPipelineDepthStencilStateCreateFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkPipelineDepthStencilStateCreateFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkPipelineDepthStencilStateCreateFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineDiscardRectangleStateCreateFlagsEXT_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkPipelineDiscardRectangleStateCreateFlagsEXT>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineDynamicStateCreateFlags_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkPipelineDynamicStateCreateFlags>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineInputAssemblyStateCreateFlags_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkPipelineInputAssemblyStateCreateFlags>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineLayoutCreateFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkPipelineLayoutCreateFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkPipelineLayoutCreateFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkPipelineLayoutCreateFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineMultisampleStateCreateFlags_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkPipelineMultisampleStateCreateFlags>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineRasterizationConservativeStateCreateFlagsEXT_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkPipelineRasterizationConservativeStateCreateFlagsEXT>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineRasterizationDepthClipStateCreateFlagsEXT_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkPipelineRasterizationDepthClipStateCreateFlagsEXT>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineRasterizationStateCreateFlags_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkPipelineRasterizationStateCreateFlags>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineRasterizationStateStreamCreateFlagsEXT_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkPipelineRasterizationStateStreamCreateFlagsEXT>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineShaderStageCreateFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkPipelineShaderStageCreateFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkPipelineShaderStageCreateFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkPipelineShaderStageCreateFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineStageFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkPipelineStageFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkPipelineStageFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkPipelineStageFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineStageFlags2_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkPipelineStageFlags2>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkPipelineStageFlags2>(flags), [](VkFlags64 flags)
    {
        switch (flags)
        {
            case VK_PIPELINE_STAGE_2_NONE:
                return std::string("VK_PIPELINE_STAGE_2_NONE");
            case VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT:
                return std::string("VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT");
            case VK_PIPELINE_STAGE_2_DRAW_INDIRECT_BIT:
                return std::string("VK_PIPELINE_STAGE_2_DRAW_INDIRECT_BIT");
            case VK_PIPELINE_STAGE_2_VERTEX_INPUT_BIT:
                return std::string("VK_PIPELINE_STAGE_2_VERTEX_INPUT_BIT");
            case VK_PIPELINE_STAGE_2_VERTEX_SHADER_BIT:
                return std::string("VK_PIPELINE_STAGE_2_VERTEX_SHADER_BIT");
            case VK_PIPELINE_STAGE_2_TESSELLATION_CONTROL_SHADER_BIT:
                return std::string("VK_PIPELINE_STAGE_2_TESSELLATION_CONTROL_SHADER_BIT");
            case VK_PIPELINE_STAGE_2_TESSELLATION_EVALUATION_SHADER_BIT:
                return std::string("VK_PIPELINE_STAGE_2_TESSELLATION_EVALUATION_SHADER_BIT");
            case VK_PIPELINE_STAGE_2_GEOMETRY_SHADER_BIT:
                return std::string("VK_PIPELINE_STAGE_2_GEOMETRY_SHADER_BIT");
            case VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT:
                return std::string("VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT");
            case VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT:
                return std::string("VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT");
            case VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT:
                return std::string("VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT");
            case VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT:
                return std::string("VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT");
            case VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT:
                return std::string("VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT");
            case VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT:
                return std::string("VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT");
            case VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT:
                return std::string("VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT");
            case VK_PIPELINE_STAGE_2_HOST_BIT:
                return std::string("VK_PIPELINE_STAGE_2_HOST_BIT");
            case VK_PIPELINE_STAGE_2_ALL_GRAPHICS_BIT:
                return std::string("VK_PIPELINE_STAGE_2_ALL_GRAPHICS_BIT");
            case VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT:
                return std::string("VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT");
            case VK_PIPELINE_STAGE_2_COPY_BIT:
                return std::string("VK_PIPELINE_STAGE_2_COPY_BIT");
            case VK_PIPELINE_STAGE_2_RESOLVE_BIT:
                return std::string("VK_PIPELINE_STAGE_2_RESOLVE_BIT");
            case VK_PIPELINE_STAGE_2_BLIT_BIT:
                return std::string("VK_PIPELINE_STAGE_2_BLIT_BIT");
            case VK_PIPELINE_STAGE_2_CLEAR_BIT:
                return std::string("VK_PIPELINE_STAGE_2_CLEAR_BIT");
            case VK_PIPELINE_STAGE_2_INDEX_INPUT_BIT:
                return std::string("VK_PIPELINE_STAGE_2_INDEX_INPUT_BIT");
            case VK_PIPELINE_STAGE_2_VERTEX_ATTRIBUTE_INPUT_BIT:
                return std::string("VK_PIPELINE_STAGE_2_VERTEX_ATTRIBUTE_INPUT_BIT");
            case VK_PIPELINE_STAGE_2_PRE_RASTERIZATION_SHADERS_BIT:
                return std::string("VK_PIPELINE_STAGE_2_PRE_RASTERIZATION_SHADERS_BIT");
            case VK_PIPELINE_STAGE_2_VIDEO_DECODE_BIT_KHR:
                return std::string("VK_PIPELINE_STAGE_2_VIDEO_DECODE_BIT_KHR");
            case VK_PIPELINE_STAGE_2_VIDEO_ENCODE_BIT_KHR:
                return std::string("VK_PIPELINE_STAGE_2_VIDEO_ENCODE_BIT_KHR");
            case VK_PIPELINE_STAGE_2_TRANSFORM_FEEDBACK_BIT_EXT:
                return std::string("VK_PIPELINE_STAGE_2_TRANSFORM_FEEDBACK_BIT_EXT");
            case VK_PIPELINE_STAGE_2_CONDITIONAL_RENDERING_BIT_EXT:
                return std::string("VK_PIPELINE_STAGE_2_CONDITIONAL_RENDERING_BIT_EXT");
            case VK_PIPELINE_STAGE_2_COMMAND_PREPROCESS_BIT_EXT:
                return std::string("VK_PIPELINE_STAGE_2_COMMAND_PREPROCESS_BIT_EXT");
            case VK_PIPELINE_STAGE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR:
                return std::string("VK_PIPELINE_STAGE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR");
            case VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR:
                return std::string("VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR");
            case VK_PIPELINE_STAGE_2_RAY_TRACING_SHADER_BIT_KHR:
                return std::string("VK_PIPELINE_STAGE_2_RAY_TRACING_SHADER_BIT_KHR");
            case VK_PIPELINE_STAGE_2_FRAGMENT_DENSITY_PROCESS_BIT_EXT:
                return std::string("VK_PIPELINE_STAGE_2_FRAGMENT_DENSITY_PROCESS_BIT_EXT");
            case VK_PIPELINE_STAGE_2_TASK_SHADER_BIT_EXT:
                return std::string("VK_PIPELINE_STAGE_2_TASK_SHADER_BIT_EXT");
            case VK_PIPELINE_STAGE_2_MESH_SHADER_BIT_EXT:
                return std::string("VK_PIPELINE_STAGE_2_MESH_SHADER_BIT_EXT");
            case VK_PIPELINE_STAGE_2_SUBPASS_SHADER_BIT_HUAWEI:
                return std::string("VK_PIPELINE_STAGE_2_SUBPASS_SHADER_BIT_HUAWEI");
            case VK_PIPELINE_STAGE_2_INVOCATION_MASK_BIT_HUAWEI:
                return std::string("VK_PIPELINE_STAGE_2_INVOCATION_MASK_BIT_HUAWEI");
            case VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_COPY_BIT_KHR:
                return std::string("VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_COPY_BIT_KHR");
            case VK_PIPELINE_STAGE_2_MICROMAP_BUILD_BIT_EXT:
                return std::string("VK_PIPELINE_STAGE_2_MICROMAP_BUILD_BIT_EXT");
            case VK_PIPELINE_STAGE_2_CLUSTER_CULLING_SHADER_BIT_HUAWEI:
                return std::string("VK_PIPELINE_STAGE_2_CLUSTER_CULLING_SHADER_BIT_HUAWEI");
            case VK_PIPELINE_STAGE_2_OPTICAL_FLOW_BIT_NV:
                return std::string("VK_PIPELINE_STAGE_2_OPTICAL_FLOW_BIT_NV");
            case VK_PIPELINE_STAGE_2_CONVERT_COOPERATIVE_VECTOR_MATRIX_BIT_NV:
                return std::string("VK_PIPELINE_STAGE_2_CONVERT_COOPERATIVE_VECTOR_MATRIX_BIT_NV");
            case VK_PIPELINE_STAGE_2_DATA_GRAPH_BIT_ARM:
                return std::string("VK_PIPELINE_STAGE_2_DATA_GRAPH_BIT_ARM");
            case VK_PIPELINE_STAGE_2_COPY_INDIRECT_BIT_KHR:
                return std::string("VK_PIPELINE_STAGE_2_COPY_INDIRECT_BIT_KHR");
            case VK_PIPELINE_STAGE_2_MEMORY_DECOMPRESSION_BIT_EXT:
                return std::string("VK_PIPELINE_STAGE_2_MEMORY_DECOMPRESSION_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineTessellationStateCreateFlags_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkPipelineTessellationStateCreateFlags>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineVertexInputStateCreateFlags_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkPipelineVertexInputStateCreateFlags>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineViewportStateCreateFlags_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkPipelineViewportStateCreateFlags>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineViewportSwizzleStateCreateFlagsNV_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkPipelineViewportSwizzleStateCreateFlagsNV>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkPresentGravityFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkPresentGravityFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkPresentGravityFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkPresentGravityFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkPresentScalingFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkPresentScalingFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkPresentScalingFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkPresentScalingFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkPresentStageFlagsEXT_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkPresentStageFlagsEXT>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkPresentStageFlagsEXT>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkPresentStageFlagBitsEXT>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkPresentTimingInfoFlagsEXT_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkPresentTimingInfoFlagsEXT>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkPresentTimingInfoFlagsEXT>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkPresentTimingInfoFlagBitsEXT>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkPrivateDataSlotCreateFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkPrivateDataSlotCreateFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkPrivateDataSlotCreateFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkPrivateDataSlotCreateFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkQueryControlFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkQueryControlFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkQueryControlFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkQueryControlFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkQueryPipelineStatisticFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkQueryPipelineStatisticFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkQueryPipelineStatisticFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkQueryPipelineStatisticFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkQueryPoolCreateFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkQueryPoolCreateFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkQueryPoolCreateFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkQueryPoolCreateFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkQueryResultFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkQueryResultFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkQueryResultFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkQueryResultFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkQueueFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkQueueFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkQueueFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkQueueFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkRenderPassCreateFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkRenderPassCreateFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkRenderPassCreateFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkRenderPassCreateFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkRenderingAttachmentFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkRenderingAttachmentFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkRenderingAttachmentFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkRenderingAttachmentFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkRenderingFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkRenderingFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkRenderingFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkRenderingFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkResolveImageFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkResolveImageFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkResolveImageFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkResolveImageFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkResolveModeFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkResolveModeFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkResolveModeFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkResolveModeFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkSampleCountFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkSampleCountFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkSampleCountFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkSampleCountFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkSamplerCreateFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkSamplerCreateFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkSamplerCreateFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkSamplerCreateFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkScreenSurfaceCreateFlagsQNX_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkScreenSurfaceCreateFlagsQNX>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkSemaphoreCreateFlags_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkSemaphoreCreateFlags>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkSemaphoreImportFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkSemaphoreImportFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkSemaphoreImportFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkSemaphoreImportFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkSemaphoreWaitFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkSemaphoreWaitFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkSemaphoreWaitFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkSemaphoreWaitFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkShaderCorePropertiesFlagsAMD_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkShaderCorePropertiesFlagsAMD>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkShaderCreateFlagsEXT_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkShaderCreateFlagsEXT>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkShaderCreateFlagsEXT>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkShaderCreateFlagBitsEXT>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkShaderModuleCreateFlags_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkShaderModuleCreateFlags>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkShaderStageFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkShaderStageFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkShaderStageFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkShaderStageFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkSparseImageFormatFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkSparseImageFormatFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkSparseImageFormatFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkSparseImageFormatFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkSparseMemoryBindFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkSparseMemoryBindFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkSparseMemoryBindFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkSparseMemoryBindFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkStencilFaceFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkStencilFaceFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkStencilFaceFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkStencilFaceFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkStreamDescriptorSurfaceCreateFlagsGGP_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkStreamDescriptorSurfaceCreateFlagsGGP>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkSubgroupFeatureFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkSubgroupFeatureFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkSubgroupFeatureFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkSubgroupFeatureFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkSubmitFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkSubmitFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkSubmitFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkSubmitFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkSubpassDescriptionFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkSubpassDescriptionFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkSubpassDescriptionFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkSubpassDescriptionFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkSurfaceCounterFlagsEXT_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkSurfaceCounterFlagsEXT>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkSurfaceCounterFlagsEXT>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkSurfaceCounterFlagBitsEXT>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkSurfaceTransformFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkSurfaceTransformFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkSurfaceTransformFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkSurfaceTransformFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkSwapchainCreateFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkSwapchainCreateFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkSwapchainCreateFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkSwapchainCreateFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkTensorCreateFlagsARM_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkTensorCreateFlagsARM>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkTensorCreateFlagsARM>(flags), [](VkFlags64 flags)
    {
        switch (flags)
        {
            case VK_TENSOR_CREATE_MUTABLE_FORMAT_BIT_ARM:
                return std::string("VK_TENSOR_CREATE_MUTABLE_FORMAT_BIT_ARM");
            case VK_TENSOR_CREATE_PROTECTED_BIT_ARM:
                return std::string("VK_TENSOR_CREATE_PROTECTED_BIT_ARM");
            case VK_TENSOR_CREATE_DESCRIPTOR_HEAP_CAPTURE_REPLAY_BIT_ARM:
                return std::string("VK_TENSOR_CREATE_DESCRIPTOR_HEAP_CAPTURE_REPLAY_BIT_ARM");
            case VK_TENSOR_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_ARM:
                return std::string("VK_TENSOR_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_ARM");
        }
        return to_hex_fixed_width(flags);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkTensorUsageFlagsARM_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkTensorUsageFlagsARM>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkTensorUsageFlagsARM>(flags), [](VkFlags64 flags)
    {
        switch (flags)
        {
            case VK_TENSOR_USAGE_SHADER_BIT_ARM:
                return std::string("VK_TENSOR_USAGE_SHADER_BIT_ARM");
            case VK_TENSOR_USAGE_TRANSFER_SRC_BIT_ARM:
                return std::string("VK_TENSOR_USAGE_TRANSFER_SRC_BIT_ARM");
            case VK_TENSOR_USAGE_TRANSFER_DST_BIT_ARM:
                return std::string("VK_TENSOR_USAGE_TRANSFER_DST_BIT_ARM");
            case VK_TENSOR_USAGE_IMAGE_ALIASING_BIT_ARM:
                return std::string("VK_TENSOR_USAGE_IMAGE_ALIASING_BIT_ARM");
            case VK_TENSOR_USAGE_DATA_GRAPH_BIT_ARM:
                return std::string("VK_TENSOR_USAGE_DATA_GRAPH_BIT_ARM");
        }
        return to_hex_fixed_width(flags);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkTensorViewCreateFlagsARM_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkTensorViewCreateFlagsARM>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkTensorViewCreateFlagsARM>(flags), [](VkFlags64 flags)
    {
        switch (flags)
        {
            case VK_TENSOR_VIEW_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_ARM:
                return std::string("VK_TENSOR_VIEW_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_ARM");
        }
        return to_hex_fixed_width(flags);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkTileShadingRenderPassFlagsQCOM_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkTileShadingRenderPassFlagsQCOM>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkTileShadingRenderPassFlagsQCOM>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkTileShadingRenderPassFlagBitsQCOM>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkToolPurposeFlags_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkToolPurposeFlags>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkToolPurposeFlags>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkToolPurposeFlagBits>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkValidationCacheCreateFlagsEXT_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkValidationCacheCreateFlagsEXT>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkViSurfaceCreateFlagsNN_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkViSurfaceCreateFlagsNN>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoBeginCodingFlagsKHR_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkVideoBeginCodingFlagsKHR>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoCapabilityFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoCapabilityFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoCapabilityFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoCapabilityFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoChromaSubsamplingFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoChromaSubsamplingFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoChromaSubsamplingFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoChromaSubsamplingFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoCodecOperationFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoCodecOperationFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoCodecOperationFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoCodecOperationFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoCodingControlFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoCodingControlFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoCodingControlFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoCodingControlFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoComponentBitDepthFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoComponentBitDepthFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoComponentBitDepthFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoComponentBitDepthFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoDecodeCapabilityFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoDecodeCapabilityFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoDecodeCapabilityFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoDecodeCapabilityFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoDecodeFlagsKHR_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkVideoDecodeFlagsKHR>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoDecodeH264PictureLayoutFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoDecodeH264PictureLayoutFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoDecodeH264PictureLayoutFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoDecodeH264PictureLayoutFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoDecodeUsageFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoDecodeUsageFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoDecodeUsageFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoDecodeUsageFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeAV1CapabilityFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoEncodeAV1CapabilityFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoEncodeAV1CapabilityFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoEncodeAV1CapabilityFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeAV1RateControlFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoEncodeAV1RateControlFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoEncodeAV1RateControlFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoEncodeAV1RateControlFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeAV1StdFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoEncodeAV1StdFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoEncodeAV1StdFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoEncodeAV1StdFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeAV1SuperblockSizeFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoEncodeAV1SuperblockSizeFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoEncodeAV1SuperblockSizeFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoEncodeAV1SuperblockSizeFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeCapabilityFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoEncodeCapabilityFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoEncodeCapabilityFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoEncodeCapabilityFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeContentFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoEncodeContentFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoEncodeContentFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoEncodeContentFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeFeedbackFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoEncodeFeedbackFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoEncodeFeedbackFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoEncodeFeedbackFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoEncodeFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoEncodeFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoEncodeFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeH264CapabilityFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoEncodeH264CapabilityFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoEncodeH264CapabilityFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoEncodeH264CapabilityFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeH264RateControlFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoEncodeH264RateControlFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoEncodeH264RateControlFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoEncodeH264RateControlFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeH264StdFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoEncodeH264StdFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoEncodeH264StdFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoEncodeH264StdFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeH265CtbSizeFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoEncodeH265CtbSizeFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoEncodeH265CtbSizeFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoEncodeH265CtbSizeFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeIntraRefreshModeFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoEncodeIntraRefreshModeFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoEncodeIntraRefreshModeFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoEncodeIntraRefreshModeFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodePerPartitionFeedbackFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoEncodePerPartitionFeedbackFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoEncodePerPartitionFeedbackFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoEncodePerPartitionFeedbackFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeRateControlFlagsKHR_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkVideoEncodeRateControlFlagsKHR>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeRateControlModeFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoEncodeRateControlModeFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoEncodeRateControlModeFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoEncodeRateControlModeFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeRgbChromaOffsetFlagsVALVE_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoEncodeRgbChromaOffsetFlagsVALVE>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoEncodeRgbChromaOffsetFlagsVALVE>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoEncodeRgbChromaOffsetFlagBitsVALVE>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeRgbModelConversionFlagsVALVE_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoEncodeRgbModelConversionFlagsVALVE>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoEncodeRgbModelConversionFlagsVALVE>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoEncodeRgbModelConversionFlagBitsVALVE>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeRgbRangeCompressionFlagsVALVE_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoEncodeRgbRangeCompressionFlagsVALVE>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoEncodeRgbRangeCompressionFlagsVALVE>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoEncodeRgbRangeCompressionFlagBitsVALVE>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeUsageFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoEncodeUsageFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoEncodeUsageFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoEncodeUsageFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEndCodingFlagsKHR_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkVideoEndCodingFlagsKHR>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoSessionCreateFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoSessionCreateFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoSessionCreateFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoSessionCreateFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoSessionParametersCreateFlagsKHR_t& flags)
{
    if (!JsonOptions::expand_flags)
    {
        jdata = to_hex_fixed_width(static_cast<VkVideoSessionParametersCreateFlagsKHR>(flags));
        return;
    }
    jdata = ExpandFlags(static_cast<VkVideoSessionParametersCreateFlagsKHR>(flags), [](VkFlags flags)
    {
        const std::string_view name = gfxrecon::util::NameOf(static_cast<VkVideoSessionParametersCreateFlagBitsKHR>(flags));
        return name.empty() ? to_hex_fixed_width(flags) : std::string(name);
    });
}

void to_json(nlohmann::ordered_json& jdata, const VkWaylandSurfaceCreateFlagsKHR_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkWaylandSurfaceCreateFlagsKHR>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkWin32SurfaceCreateFlagsKHR_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkWin32SurfaceCreateFlagsKHR>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkXcbSurfaceCreateFlagsKHR_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkXcbSurfaceCreateFlagsKHR>(flags));
}

void to_json(nlohmann::ordered_json& jdata, const VkXlibSurfaceCreateFlagsKHR_t& flags)
{
    jdata = to_hex_fixed_width(static_cast<VkXlibSurfaceCreateFlagsKHR>(flags));
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
void to_json(nlohmann::ordered_json& jdata, const StdVideoAV1ChromaSamplePosition& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoAV1ColorPrimaries& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoAV1FrameRestorationType& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoAV1FrameType& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoAV1InterpolationFilter& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoAV1Level& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoAV1MatrixCoefficients& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoAV1Profile& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoAV1ReferenceName& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoAV1TransferCharacteristics& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoAV1TxMode& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoDecodeH264FieldOrderCount& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoH264AspectRatioIdc& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoH264CabacInitIdc& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoH264ChromaFormatIdc& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoH264DisableDeblockingFilterIdc& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoH264LevelIdc& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoH264MemMgmtControlOp& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoH264ModificationOfPicNumsIdc& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoH264NonVclNaluType& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoH264PictureType& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoH264PocType& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoH264ProfileIdc& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoH264SliceType& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoH264WeightedBipredIdc& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoVP9ColorSpace& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoVP9FrameType& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoVP9InterpolationFilter& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoVP9Level& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoVP9Profile& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const StdVideoVP9ReferenceName& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkAccelerationStructureBuildTypeKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkAccelerationStructureCompatibilityKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkAccelerationStructureCreateFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkAccelerationStructureMemoryRequirementsTypeNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkAccelerationStructureMotionInstanceTypeNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkAccelerationStructureSerializedBlockTypeKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkAccelerationStructureTypeKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkAccessFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkAcquireProfilingLockFlagBitsKHR& value)
{
    jdata = gfxrecon::decode::to_hex_fixed_width(value);
}

void to_json(nlohmann::ordered_json& jdata, const VkAddressCommandFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkAddressCopyFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkAntiLagModeAMD& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkAntiLagStageAMD& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkAttachmentDescriptionFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkAttachmentLoadOp& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkAttachmentStoreOp& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkBlendFactor& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkBlendOp& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkBlendOverlapEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkBlockMatchWindowCompareModeQCOM& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkBorderColor& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkBufferCreateFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkBufferUsageFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkBuildAccelerationStructureFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkBuildAccelerationStructureModeKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkBuildMicromapFlagBitsEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkBuildMicromapModeEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkChromaLocation& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkCoarseSampleOrderTypeNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkColorComponentFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkColorSpaceKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkCommandBufferLevel& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkCommandBufferResetFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkCommandBufferUsageFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkCommandPoolCreateFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkCommandPoolResetFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkCompareOp& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkComponentSwizzle& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkComponentTypeKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkCompositeAlphaFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkConditionalRenderingFlagBitsEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkConservativeRasterizationModeEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkCooperativeMatrixFlagBitsEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkCooperativeVectorMatrixLayoutNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkCopyAccelerationStructureModeKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkCopyMicromapModeEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkCoverageModulationModeNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkCoverageReductionModeNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkCubicFilterWeightsQCOM& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkCullModeFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDataGraphModelCacheTypeQCOM& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDataGraphOpticalFlowCreateFlagBitsARM& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDataGraphOpticalFlowExecuteFlagBitsARM& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDataGraphOpticalFlowGridSizeFlagBitsARM& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDataGraphOpticalFlowImageUsageFlagBitsARM& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDataGraphOpticalFlowPerformanceLevelARM& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDataGraphPipelineNodeConnectionTypeARM& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDataGraphPipelineNodeTypeARM& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDataGraphPipelinePropertyARM& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDataGraphPipelineSessionBindPointARM& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDataGraphPipelineSessionBindPointTypeARM& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDebugReportFlagBitsEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDebugReportObjectTypeEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDebugUtilsMessageSeverityFlagBitsEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDebugUtilsMessageTypeFlagBitsEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDefaultVertexAttributeValueKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDependencyFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDepthBiasRepresentationEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDepthClampModeEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDescriptorBindingFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDescriptorPoolCreateFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDescriptorSetLayoutCreateFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDescriptorType& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDescriptorUpdateTemplateType& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDeviceAddressBindingFlagBitsEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDeviceAddressBindingTypeEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDeviceDiagnosticsConfigFlagBitsNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDeviceEventTypeEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDeviceFaultAddressTypeKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDeviceFaultFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDeviceFaultVendorBinaryHeaderVersionKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDeviceGroupPresentModeFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDeviceMemoryReportEventTypeEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDeviceQueueCreateFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDirectDriverLoadingModeLUNARG& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDiscardRectangleModeEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDisplacementMicromapFormatNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDisplayEventTypeEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDisplayPlaneAlphaFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDisplayPowerStateEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDisplaySurfaceStereoTypeNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDriverId& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkDynamicState& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkEventCreateFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkExternalFenceFeatureFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkExternalFenceHandleTypeFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkExternalMemoryFeatureFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkExternalMemoryFeatureFlagBitsNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkExternalMemoryHandleTypeFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkExternalMemoryHandleTypeFlagBitsNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkExternalSemaphoreFeatureFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkExternalSemaphoreHandleTypeFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkFenceCreateFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkFenceImportFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkFilter& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkFormat& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkFormatFeatureFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkFragmentShadingRateCombinerOpKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkFragmentShadingRateNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkFragmentShadingRateTypeNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkFrameBoundaryFlagBitsEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkFramebufferCreateFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkFrontFace& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkFullScreenExclusiveEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkGeometryFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkGeometryInstanceFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkGeometryTypeKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkGpaDeviceClockModeAMD& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkGpaPerfBlockAMD& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkGpaSampleTypeAMD& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkGpaSqShaderStageFlagBitsAMD& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkGraphicsPipelineLibraryFlagBitsEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkHostImageCopyFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkImageAspectFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkImageCompressionFixedRateFlagBitsEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkImageCompressionFlagBitsEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkImageCreateFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkImageLayout& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkImageTiling& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkImageTilingControlEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkImageType& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkImageUsageFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkImageViewCreateFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkImageViewType& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkIndexType& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkIndirectCommandsInputModeFlagBitsEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkIndirectCommandsLayoutUsageFlagBitsEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkIndirectCommandsLayoutUsageFlagBitsNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkIndirectCommandsTokenTypeEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkIndirectCommandsTokenTypeNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkIndirectExecutionSetInfoTypeEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkIndirectStateFlagBitsNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkInstanceCreateFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkInternalAllocationType& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkLatencyMarkerNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkLayerSettingTypeEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkLayeredDriverUnderlyingApiMSFT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkLineRasterizationMode& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkLogicOp& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkMemoryAllocateFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkMemoryHeapFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkMemoryMapFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkMemoryOverallocationBehaviorAMD& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkMemoryPropertyFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkMemoryUnmapFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkMicromapCreateFlagBitsEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkMicromapTypeEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkNeuralAcceleratorStatisticsModeARM& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkObjectType& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkOpacityMicromapFormatKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkOpacityMicromapSpecialIndexKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkOpticalFlowExecuteFlagBitsNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkOpticalFlowGridSizeFlagBitsNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkOpticalFlowPerformanceLevelNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkOpticalFlowSessionBindingPointNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkOpticalFlowSessionCreateFlagBitsNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkOpticalFlowUsageFlagBitsNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkOutOfBandQueueTypeNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPartitionedAccelerationStructureInstanceFlagBitsNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPartitionedAccelerationStructureOpTypeNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPastPresentationTimingFlagBitsEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPeerMemoryFeatureFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPerfHintTypeQCOM& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPerformanceConfigurationTypeINTEL& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPerformanceCounterDescriptionFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPerformanceCounterScopeKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPerformanceCounterStorageKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPerformanceCounterUnitKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPerformanceOverrideTypeINTEL& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPerformanceParameterTypeINTEL& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPerformanceValueTypeINTEL& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPhysicalDeviceDataGraphOperationTypeARM& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPhysicalDeviceDataGraphProcessingEngineTypeARM& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPhysicalDeviceLayeredApiKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPhysicalDeviceType& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineBindPoint& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineCacheCreateFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineCacheHeaderVersion& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineColorBlendStateCreateFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineCompilerControlFlagBitsAMD& value)
{
    jdata = gfxrecon::decode::to_hex_fixed_width(value);
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineCreateFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineCreationFeedbackFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineDepthStencilStateCreateFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineExecutableStatisticFormatKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineLayoutCreateFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineRobustnessBufferBehavior& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineRobustnessImageBehavior& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineShaderStageCreateFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPipelineStageFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPointClippingBehavior& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPolygonMode& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPresentGravityFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPresentModeKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPresentScalingFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPresentStageFlagBitsEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPresentTimingInfoFlagBitsEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPrimitiveTopology& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkPrivateDataSlotCreateFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkProvokingVertexModeEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkQueryControlFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkQueryPipelineStatisticFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkQueryPoolCreateFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkQueryPoolSamplingModeINTEL& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkQueryResultFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkQueryResultStatusKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkQueryType& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkQueueFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkQueueGlobalPriority& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkRasterizationOrderAMD& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkRayTracingInvocationReorderModeEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkRayTracingLssIndexingModeNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkRayTracingLssPrimitiveEndCapsModeNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkRayTracingShaderGroupTypeKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkRenderPassCreateFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkRenderingAttachmentFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkRenderingFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkResolveImageFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkResolveModeFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkResult& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkSampleCountFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkSamplerAddressMode& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkSamplerCreateFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkSamplerMipmapMode& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkSamplerReductionMode& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkSamplerYcbcrModelConversion& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkSamplerYcbcrRange& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkScopeKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkSemaphoreImportFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkSemaphoreType& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkSemaphoreWaitFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkShaderCodeTypeEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkShaderCorePropertiesFlagBitsAMD& value)
{
    jdata = gfxrecon::decode::to_hex_fixed_width(value);
}

void to_json(nlohmann::ordered_json& jdata, const VkShaderCreateFlagBitsEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkShaderFloatControlsIndependence& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkShaderGroupShaderKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkShaderInfoTypeAMD& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkShaderStageFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkShadingRatePaletteEntryNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkSharingMode& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkSparseImageFormatFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkSparseMemoryBindFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkStencilFaceFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkStencilOp& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkStructureType& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkSubgroupFeatureFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkSubmitFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkSubpassContents& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkSubpassDescriptionFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkSubpassMergeStatusEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkSurfaceCounterFlagBitsEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkSurfaceTransformFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkSwapchainCreateFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkSystemAllocationScope& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkTensorTilingARM& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkTessellationDomainOrigin& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkThrottleHintTypeSEC& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkTileShadingRenderPassFlagBitsQCOM& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkTimeDomainKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkToolPurposeFlagBits& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkValidationCacheHeaderVersionEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkValidationCheckEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkValidationFeatureDisableEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkValidationFeatureEnableEXT& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVendorId& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVertexInputRate& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoCapabilityFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoChromaSubsamplingFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoCodecOperationFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoCodingControlFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoComponentBitDepthFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoDecodeCapabilityFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoDecodeH264PictureLayoutFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoDecodeUsageFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeAV1CapabilityFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeAV1PredictionModeKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeAV1RateControlFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeAV1RateControlGroupKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeAV1StdFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeAV1SuperblockSizeFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeCapabilityFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeContentFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeFeedbackFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeH264CapabilityFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeH264RateControlFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeH264StdFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeH265CtbSizeFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeIntraRefreshModeFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodePerPartitionFeedbackFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeRateControlModeFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeRgbChromaOffsetFlagBitsVALVE& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeRgbModelConversionFlagBitsVALVE& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeRgbRangeCompressionFlagBitsVALVE& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeTuningModeKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoEncodeUsageFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoSessionCreateFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkVideoSessionParametersCreateFlagBitsKHR& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

void to_json(nlohmann::ordered_json& jdata, const VkViewportCoordinateSwizzleNV& value)
{
    const std::string_view name = gfxrecon::util::NameOf(value);
    if (name.empty())
    {
        jdata = gfxrecon::decode::to_hex_fixed_width(value);
    }
    else
    {
        jdata = std::string(name);
    }
}

