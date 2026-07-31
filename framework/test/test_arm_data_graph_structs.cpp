/*
** Copyright (c) 2026 LunarG, Inc.
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

#include <catch2/catch.hpp>

#include "decode/decode_allocator.h"
#include "decode/struct_pointer_decoder.h"
#include "encode/parameter_buffer.h"
#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "generated/generated_vulkan_struct_encoders.h"
#include "util/logging.h"

#include "vulkan/vulkan.h"

#include <iterator>
#include <memory>

TEST_CASE("VkBaseOutStructure decodes to the appropriate returned ARM type", "[enc/dec]")
{
    using namespace gfxrecon;
    using namespace gfxrecon::decode;
    gfxrecon::util::Log::Init(gfxrecon::util::LoggingSeverity::kError);
    auto parameter_buffer  = std::make_unique<encode::ParameterBuffer>();
    auto parameter_encoder = std::make_unique<encode::ParameterEncoder>(parameter_buffer.get());

    VkQueueFamilyDataGraphOpticalFlowPropertiesARM optical_flow_properties{
        VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_OPTICAL_FLOW_PROPERTIES_ARM,
        nullptr,
        VK_DATA_GRAPH_OPTICAL_FLOW_GRID_SIZE_4X4_BIT_ARM,
        VK_DATA_GRAPH_OPTICAL_FLOW_GRID_SIZE_4X4_BIT_ARM,
        VK_TRUE,
        VK_TRUE,
        64,
        32,
        4096,
        2160
    };

    gfxrecon::encode::EncodeStructPtr(parameter_encoder.get(),
                                      reinterpret_cast<const VkBaseOutStructure*>(&optical_flow_properties));

    DecodeAllocator::Begin();

    StructPointerDecoder<Decoded_VkBaseOutStructure> wrapper;
    wrapper.DecodeBaseHeader(parameter_buffer->GetData(), parameter_buffer->GetDataSize());

    auto* decoded_properties =
        reinterpret_cast<const VkQueueFamilyDataGraphOpticalFlowPropertiesARM*>(wrapper.GetPointer());
    REQUIRE(decoded_properties != nullptr);
    REQUIRE(decoded_properties->sType == optical_flow_properties.sType);
    REQUIRE(decoded_properties->supportedOutputGridSizes == optical_flow_properties.supportedOutputGridSizes);
    REQUIRE(decoded_properties->supportedHintGridSizes == optical_flow_properties.supportedHintGridSizes);
    REQUIRE(decoded_properties->hintSupported == optical_flow_properties.hintSupported);
    REQUIRE(decoded_properties->costSupported == optical_flow_properties.costSupported);
    REQUIRE(decoded_properties->minWidth == optical_flow_properties.minWidth);
    REQUIRE(decoded_properties->minHeight == optical_flow_properties.minHeight);
    REQUIRE(decoded_properties->maxWidth == optical_flow_properties.maxWidth);
    REQUIRE(decoded_properties->maxHeight == optical_flow_properties.maxHeight);

    DecodeAllocator::End();
    gfxrecon::util::Log::Release();
}

TEST_CASE("VkDataGraphPipelineCreateInfoARM with optical flow structs can be encoded and decoded", "[enc/dec]")
{
    using namespace gfxrecon;
    using namespace gfxrecon::decode;
    gfxrecon::util::Log::Init(gfxrecon::util::LoggingSeverity::kError);
    auto parameter_buffer  = std::make_unique<encode::ParameterBuffer>();
    auto parameter_encoder = std::make_unique<encode::ParameterEncoder>(parameter_buffer.get());

    auto* encoder = parameter_encoder.get();

    VkDataGraphPipelineResourceInfoImageLayoutARM image_layouts[] = {
        { VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_IMAGE_LAYOUT_ARM,
          nullptr,
          VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL },
        { VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_IMAGE_LAYOUT_ARM,
          nullptr,
          VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL },
        { VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_IMAGE_LAYOUT_ARM,
          nullptr,
          VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL },
        { VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_IMAGE_LAYOUT_ARM, nullptr, VK_IMAGE_LAYOUT_GENERAL },
        { VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_IMAGE_LAYOUT_ARM, nullptr, VK_IMAGE_LAYOUT_GENERAL }
    };

    VkDataGraphPipelineResourceInfoARM resources[] = {
        { VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_ARM, &image_layouts[0], 0, 0, 0 },
        { VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_ARM, &image_layouts[1], 0, 1, 0 },
        { VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_ARM, &image_layouts[2], 0, 2, 0 },
        { VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_ARM, &image_layouts[3], 0, 3, 0 },
        { VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_ARM, &image_layouts[4], 0, 4, 0 }
    };

    VkDataGraphPipelineSingleNodeConnectionARM connections[] = {
        { VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SINGLE_NODE_CONNECTION_ARM,
          nullptr,
          0,
          0,
          VK_DATA_GRAPH_PIPELINE_NODE_CONNECTION_TYPE_OPTICAL_FLOW_INPUT_ARM },
        { VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SINGLE_NODE_CONNECTION_ARM,
          nullptr,
          0,
          1,
          VK_DATA_GRAPH_PIPELINE_NODE_CONNECTION_TYPE_OPTICAL_FLOW_REFERENCE_ARM },
        { VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SINGLE_NODE_CONNECTION_ARM,
          nullptr,
          0,
          2,
          VK_DATA_GRAPH_PIPELINE_NODE_CONNECTION_TYPE_OPTICAL_FLOW_HINT_ARM },
        { VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SINGLE_NODE_CONNECTION_ARM,
          nullptr,
          0,
          3,
          VK_DATA_GRAPH_PIPELINE_NODE_CONNECTION_TYPE_OPTICAL_FLOW_FLOW_VECTOR_ARM },
        { VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SINGLE_NODE_CONNECTION_ARM,
          nullptr,
          0,
          4,
          VK_DATA_GRAPH_PIPELINE_NODE_CONNECTION_TYPE_OPTICAL_FLOW_COST_ARM }
    };

    VkDataGraphPipelineSingleNodeCreateInfoARM single_node_info{
        VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SINGLE_NODE_CREATE_INFO_ARM,
        nullptr,
        VK_DATA_GRAPH_PIPELINE_NODE_TYPE_OPTICAL_FLOW_ARM,
        static_cast<uint32_t>(std::size(connections)),
        connections
    };

    VkDataGraphPipelineOpticalFlowCreateInfoARM optical_flow_info{
        VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_OPTICAL_FLOW_CREATE_INFO_ARM,
        nullptr,
        1920,
        1080,
        VK_FORMAT_R8_UNORM,
        VK_FORMAT_R16G16_SFLOAT,
        VK_FORMAT_R8_UNORM,
        VK_DATA_GRAPH_OPTICAL_FLOW_GRID_SIZE_4X4_BIT_ARM,
        VK_DATA_GRAPH_OPTICAL_FLOW_GRID_SIZE_4X4_BIT_ARM,
        VK_DATA_GRAPH_OPTICAL_FLOW_PERFORMANCE_LEVEL_FAST_ARM,
        VK_DATA_GRAPH_OPTICAL_FLOW_CREATE_ENABLE_HINT_BIT_ARM | VK_DATA_GRAPH_OPTICAL_FLOW_CREATE_ENABLE_COST_BIT_ARM
    };

    VkDataGraphPipelineCreateInfoARM pipeline_info{
        VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CREATE_INFO_ARM, &single_node_info, 0, VK_NULL_HANDLE,
        static_cast<uint32_t>(std::size(resources)),           resources
    };

    single_node_info.pNext = &optical_flow_info;

    gfxrecon::encode::EncodeStruct(encoder, pipeline_info);

    DecodeAllocator::Begin();

    Decoded_VkDataGraphPipelineCreateInfoARM wrapper;
    VkDataGraphPipelineCreateInfoARM         decoded_value;
    wrapper.decoded_value = &decoded_value;

    DecodeStruct(parameter_buffer->GetData(), parameter_buffer->GetDataSize(), &wrapper);

    REQUIRE(decoded_value.sType == pipeline_info.sType);
    REQUIRE(decoded_value.flags == pipeline_info.flags);
    REQUIRE(decoded_value.layout == VK_NULL_HANDLE);
    REQUIRE(decoded_value.resourceInfoCount == pipeline_info.resourceInfoCount);
    REQUIRE(decoded_value.pResourceInfos != nullptr);

    for (uint32_t i = 0; i < decoded_value.resourceInfoCount; ++i)
    {
        const auto& decoded_resource = decoded_value.pResourceInfos[i];
        const auto& input_resource   = resources[i];
        REQUIRE(decoded_resource.sType == input_resource.sType);
        REQUIRE(decoded_resource.descriptorSet == input_resource.descriptorSet);
        REQUIRE(decoded_resource.binding == input_resource.binding);
        REQUIRE(decoded_resource.arrayElement == input_resource.arrayElement);
        REQUIRE(decoded_resource.pNext != nullptr);

        auto* decoded_layout =
            reinterpret_cast<const VkDataGraphPipelineResourceInfoImageLayoutARM*>(decoded_resource.pNext);
        auto* input_layout =
            reinterpret_cast<const VkDataGraphPipelineResourceInfoImageLayoutARM*>(input_resource.pNext);
        REQUIRE(decoded_layout->sType == input_layout->sType);
        REQUIRE(decoded_layout->layout == input_layout->layout);
    }

    auto* decoded_single_node =
        reinterpret_cast<const VkDataGraphPipelineSingleNodeCreateInfoARM*>(decoded_value.pNext);
    REQUIRE(decoded_single_node != nullptr);
    REQUIRE(decoded_single_node->sType == single_node_info.sType);
    REQUIRE(decoded_single_node->nodeType == single_node_info.nodeType);
    REQUIRE(decoded_single_node->connectionCount == single_node_info.connectionCount);
    REQUIRE(decoded_single_node->pConnections != nullptr);

    auto* decoded_optical_flow =
        reinterpret_cast<const VkDataGraphPipelineOpticalFlowCreateInfoARM*>(decoded_single_node->pNext);
    REQUIRE(decoded_optical_flow != nullptr);
    REQUIRE(decoded_optical_flow->sType == optical_flow_info.sType);
    REQUIRE(decoded_optical_flow->width == optical_flow_info.width);
    REQUIRE(decoded_optical_flow->height == optical_flow_info.height);
    REQUIRE(decoded_optical_flow->imageFormat == optical_flow_info.imageFormat);
    REQUIRE(decoded_optical_flow->flowVectorFormat == optical_flow_info.flowVectorFormat);
    REQUIRE(decoded_optical_flow->costFormat == optical_flow_info.costFormat);
    REQUIRE(decoded_optical_flow->outputGridSize == optical_flow_info.outputGridSize);
    REQUIRE(decoded_optical_flow->hintGridSize == optical_flow_info.hintGridSize);
    REQUIRE(decoded_optical_flow->performanceLevel == optical_flow_info.performanceLevel);
    REQUIRE(decoded_optical_flow->flags == optical_flow_info.flags);

    for (uint32_t i = 0; i < decoded_single_node->connectionCount; ++i)
    {
        const auto& decoded_connection = decoded_single_node->pConnections[i];
        const auto& input_connection   = connections[i];
        REQUIRE(decoded_connection.sType == input_connection.sType);
        REQUIRE(decoded_connection.set == input_connection.set);
        REQUIRE(decoded_connection.binding == input_connection.binding);
        REQUIRE(decoded_connection.connection == input_connection.connection);
    }

    DecodeAllocator::End();
    gfxrecon::util::Log::Release();
}
