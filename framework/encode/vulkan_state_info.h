/*
** Copyright (c) 2019 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_VULKAN_STATE_INFO_H
#define GFXRECON_ENCODE_VULKAN_STATE_INFO_H

#include "format/format.h"
#include "util/defines.h"
#include "util/memory_output_stream.h"
#include "encode/handle_unwrap_memory.h"

#include "vulkan/vulkan.h"

#include <limits>
#include <memory>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)
GFXRECON_BEGIN_NAMESPACE(vulkan_state_info)

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
    bool             immutable_samplers{ 0 };
};

struct DescriptorInfo
{
    VkDescriptorType                              type;
    uint32_t                                      count{ 0 };
    bool                                          immutable_samplers{ false };
    std::unique_ptr<bool[]>                       written;
    std::unique_ptr<format::HandleId[]>           handle_ids;  // Image, buffer, or buffer view IDs depending on type.
    std::unique_ptr<format::HandleId[]>           sampler_ids; // Sampler IDs for image type.
    std::unique_ptr<VkDescriptorImageInfo[]>      images;
    std::unique_ptr<VkDescriptorImageInfo[]>      storage_images;
    std::unique_ptr<VkDescriptorBufferInfo[]>     buffers;
    std::unique_ptr<VkDescriptorBufferInfo[]>     storage_buffers;
    std::unique_ptr<VkBufferView[]>               uniform_texel_buffer_views;
    std::unique_ptr<VkBufferView[]>               storage_texel_buffer_views;
    std::unique_ptr<VkAccelerationStructureKHR[]> acceleration_structures;
    std::unique_ptr<uint8_t[]>                    inline_uniform_block;
    std::unique_ptr<VkDescriptorType[]>           mutable_type;
};

struct ShaderReflectionDescriptorInfo
{
    ShaderReflectionDescriptorInfo(
        VkDescriptorType type, bool readonly, uint32_t accessed, uint32_t count, bool is_array) :
        type(type),
        readonly(readonly), accessed(accessed), count(count), is_array(is_array)
    {}

    ShaderReflectionDescriptorInfo(const ShaderReflectionDescriptorInfo& other) :
        type(other.type), readonly(other.readonly), accessed(other.accessed), count(other.count),
        is_array(other.is_array)
    {}

    VkDescriptorType type;
    bool             readonly;
    uint32_t         accessed;
    uint32_t         count;
    bool             is_array;
};

// One entry per descriptor binding
using ShaderReflectionDescriptorSetInfo = std::unordered_map<uint32_t, ShaderReflectionDescriptorInfo>;

// One entry per descriptor set
using ShaderReflectionDescriptorSetsInfos = std::unordered_map<uint32_t, ShaderReflectionDescriptorSetInfo>;

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
    MicromapEXTHandle,
    OpticalFlowSessionNVHandle,
    VideoSessionKHRHandle,
    VideoSessionParametersKHRHandle,
    ShaderEXTHandle,
    DescriptorSetLayoutHandle,
    DescriptorUpdateTemplateHandle,

    NumHandleTypes // THIS MUST BE THE LAST ENUM VALUE !
};

GFXRECON_END_NAMESPACE(vulkan_state_info)
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_STATE_INFO_H
