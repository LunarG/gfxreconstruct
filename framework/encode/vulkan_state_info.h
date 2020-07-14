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

// Active query state information to be stored with the VkCommandBuffer handle when recorded and transferred to the
// VkQueryPool handle when the command buffer is submitted for execution.
struct QueryInfo
{
    static const uint32_t kInvalidIndex = std::numeric_limits<uint32_t>::max();

    bool                active{ false };
    VkQueryControlFlags flags{ 0 };
    uint32_t            query_type_index{ 0 }; // Query type sepcific value (e.g. transform feedback vertex stream).
    uint32_t            queue_family_index{ kInvalidIndex }; // Queue family index for last command buffer submission.
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
    std::unique_ptr<format::HandleId[]>       handle_ids;  // Image, buffer, or buffer view IDs depending on type.
    std::unique_ptr<format::HandleId[]>       sampler_ids; // Sampler IDs for image type.
    std::unique_ptr<VkDescriptorImageInfo[]>  images;
    std::unique_ptr<VkDescriptorBufferInfo[]> buffers;
    std::unique_ptr<VkBufferView[]>           texel_buffer_views;
};

struct CreateDependencyInfo
{
    format::HandleId  handle_id{ format::kNullHandleId };
    format::ApiCallId create_call_id{ format::ApiCallId::ApiCall_Unknown };
    CreateParameters  create_parameters;
};

// Create info for all descriptor set layouts required by a pipeline layout.
// Referenced with a shared pointer by VkPipelineLayout and VkPipeline handles.
struct PipelineLayoutDependencies
{
    std::vector<CreateDependencyInfo> layouts;
};

struct ImageAcquiredInfo
{
    bool             is_acquired{ false };
    uint32_t         acquired_device_mask{ 0 };
    format::HandleId acquired_semaphore_id{ format::kNullHandleId };
    format::HandleId acquired_fence_id{ format::kNullHandleId };
    VkQueue          last_presented_queue{ VK_NULL_HANDLE };
};

// Types for Vulkan object handles that are recorded to command buffers.
enum CommandHandleType : uint32_t
{
    BufferHandle = 0,
    BufferViewHandle,
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
    SamplerHandle,
    AccelerationStructureKHRHandle,
    AccelerationStructureNVHandle,
    IndirectCommandsLayoutNVHandle,
    DeferredOperationKHRHandle,
    NumHandleTypes
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_STATE_INFO_H
