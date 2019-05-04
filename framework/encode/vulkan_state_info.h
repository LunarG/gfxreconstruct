/*
** Copyright (c) 2019 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_VULKAN_STATE_INFO_H
#define GFXRECON_ENCODE_VULKAN_STATE_INFO_H

#include "format/format.h"
#include "util/defines.h"
#include "util/memory_output_stream.h"

#include "vulkan/vulkan.h"

#include <limits>
#include <memory>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

//
// Types for state tracking.
//

typedef std::shared_ptr<util::MemoryOutputStream> CreateParameters;

// Active query state information stored with VkQueryPool handle.
struct QueryInfo
{
    static const uint32_t kInvalidIndex = std::numeric_limits<uint32_t>::max();

    VkQueryControlFlags flags{ 0 };
    uint32_t            index{ kInvalidIndex };           // Pool index for active query.
    VkCommandBuffer     command_buffer{ VK_NULL_HANDLE }; // Command buffer for query begin.
    format::HandleId    command_buffer_id{ 0 };
    VkRenderPass        render_pass{ VK_NULL_HANDLE }; // Optional render pass containing query.
    format::HandleId    render_pass_id{ 0 };
};

struct DescriptorBindingInfo
{
    uint32_t         binding_index{ 0 };
    uint32_t         count{ 0 };
    VkDescriptorType type;
};

struct DescriptorInfo
{
    VkDescriptorType                          type;
    uint32_t                                  count{ 0 };
    std::unique_ptr<bool[]>                   written;
    std::unique_ptr<VkDescriptorImageInfo[]>  images;
    std::unique_ptr<VkDescriptorBufferInfo[]> buffers;
    std::unique_ptr<VkBufferView[]>           texel_buffer_views;
};

// VkDescriptorSetLayout create info stored with VkPipelineLayout handle.
struct DescriptorSetLayoutInfo
{
    VkDescriptorSetLayout handle{ VK_NULL_HANDLE };
    format::HandleId      handle_id{ 0 };
    format::ApiCallId     create_call_id{ format::ApiCallId::ApiCall_Unknown };
    CreateParameters      create_parameters;
};

// Create info for all descriptor set layouts required by a pipeline layout.
// Referenced with a shared pointer by VkPipelineLayout and VkPipeline handles.
struct PipelineLayoutDependencies
{
    std::vector<DescriptorSetLayoutInfo> layouts;
};

// VkShaderModule create info stored with VkPipeline handle.
struct ShaderModuleInfo
{
    VkShaderModule    handle{ VK_NULL_HANDLE };
    format::HandleId  handle_id{ 0 };
    format::ApiCallId create_call_id{ format::ApiCallId::ApiCall_Unknown };
    CreateParameters  create_parameters;
};

struct ImageAcquiredInfo
{
    bool        is_acquired{ true };
    VkSemaphore acquired_semaphore{ VK_NULL_HANDLE };
    VkFence     acquired_fence{ VK_NULL_HANDLE };
    VkQueue     last_presented_queue{ VK_NULL_HANDLE };
};

// Types for Vulkan object handles that are recorded to command buffers.
enum CommandHandleType : uint32_t
{
    BufferHandle = 0,
    CommandBufferHandle,
    DescriptorSetHandle,
    EventHandle,
    FramebufferHandle,
    ImageHandle,
    ImageViewHandle,
    PipelineHandle,
    PipelineLayoutHandle,
    QueryPoolHandle,
    RenderPassHandle,
    AccelerationStructureNVHandle,
    IndirectCommandsLayoutNVXHandle,
    ObjectTableNVXHandle,
    NumHandleTypes
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_STATE_INFO_H
