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

#ifndef GFXRECON_ENCODE_HANDLE_WRAPPERS_H
#define GFXRECON_ENCODE_HANDLE_WRAPPERS_H

#include "format/format.h"
#include "util/defines.h"
#include "util/memory_output_stream.h"

#include "vulkan/vulkan.h"

#include <limits>
#include <memory>
#include <unordered_map>
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

//
// Handle wrappers for storing object state information with object handles.
//

template <typename T>
struct HandleWrapper
{
    typedef T HandleType;

    // Standard state info required for all handles.
    T                 handle{ VK_NULL_HANDLE };
    format::HandleId  handle_id{ 0 };
    format::ApiCallId create_call_id{ format::ApiCallId::ApiCall_Unknown };
    CreateParameters  create_parameters;
};

//
// Type definitions for handle wrappers that do not require additional state info.
//

// clang-format off
struct QueueWrapper                     : public HandleWrapper<VkQueue> {};
struct FenceWrapper                     : public HandleWrapper<VkFence> {};
struct EventWrapper                     : public HandleWrapper<VkEvent> {};
struct BufferViewWrapper                : public HandleWrapper<VkBufferView> {};
struct ShaderModuleWrapper              : public HandleWrapper<VkShaderModule> {};
struct PipelineCacheWrapper             : public HandleWrapper<VkPipelineCache> {};
struct SamplerWrapper                   : public HandleWrapper<VkSampler> {};
struct SamplerYcbcrConversionWrapper    : public HandleWrapper<VkSamplerYcbcrConversion> {};
struct DescriptorUpdateTemplateWrapper  : public HandleWrapper<VkDescriptorUpdateTemplate> {};
struct SurfaceKHRWrapper                : public HandleWrapper<VkSurfaceKHR> {};
struct DebugReportCallbackEXTWrapper    : public HandleWrapper<VkDebugReportCallbackEXT> {};
struct DebugUtilsMessengerEXTWrapper    : public HandleWrapper<VkDebugUtilsMessengerEXT> {};
struct ValidationCacheEXTWrapper        : public HandleWrapper<VkValidationCacheEXT> {};
struct IndirectCommandsLayoutNVXWrapper : public HandleWrapper<VkIndirectCommandsLayoutNVX> {};

// This handle type has a create function, but no destroy function. The handle wrapper will be owned by the VkDisplay
// handle wrapper, which will ensure it is destroyed when the VkDisplay handle wrapper is destroyed.
struct DisplayModeKHRWrapper            : public HandleWrapper<VkDisplayModeKHR> {};
// clang-format on

// Handle alias types for extension handle types that have been promoted to core types.
typedef VkSamplerYcbcrConversionKHR   SamplerYcbcrConversionKHRWrapper;
typedef VkDescriptorUpdateTemplateKHR DescriptorUpdateTemplateKHRWrapper;

//
// Declarations for handle wrappers that require additional state info.
//

// This handle type is retrieved and has no destroy function. The handle wrapper will be owned by the VkPhysicalDevice
// handle wrapper, which will ensure it is destroyed when the VkPhysicalDevice handle wrapper is destroyed.
struct DisplayKHRWrapper : public HandleWrapper<VkDisplayKHR>
{
    std::vector<DisplayModeKHRWrapper*> display_modes;
};

// This handle type is retrieved and has no destroy function. The handle wrapper will be owned by the VkInstance
// handle wrapper, which will ensure it is destroyed when the VkInstance handle wrapper is destroyed.
struct PhysicalDeviceWrapper : public HandleWrapper<VkPhysicalDevice>
{
    std::vector<VkMemoryType>                            memory_types;
    std::unordered_map<VkDisplayKHR, DisplayKHRWrapper*> displays;
};

struct InstanceWrapper : public HandleWrapper<VkInstance>
{
    std::unordered_map<VkPhysicalDevice, PhysicalDeviceWrapper*> physical_devices;
};

struct DeviceWrapper : public HandleWrapper<VkDevice>
{
    PhysicalDeviceWrapper*                     physical_device;
    std::unordered_map<VkQueue, QueueWrapper*> queues;
};

struct BufferWrapper : public HandleWrapper<VkBuffer>
{
    VkDevice       bind_device{ VK_NULL_HANDLE };
    VkDeviceMemory bind_memory{ VK_NULL_HANDLE };
    VkDeviceSize   bind_offset{ 0 };
    uint32_t       queue_family_index{ 0 };
    VkDeviceSize   created_size{ 0 };
};

struct ImageWrapper : public HandleWrapper<VkImage>
{
    VkDevice              bind_device{ VK_NULL_HANDLE };
    VkDeviceMemory        bind_memory{ VK_NULL_HANDLE };
    VkDeviceSize          bind_offset{ 0 };
    uint32_t              queue_family_index{ 0 };
    VkImageType           image_type{ VK_IMAGE_TYPE_2D };
    VkFormat              format{ VK_FORMAT_UNDEFINED };
    VkExtent3D            extent{ 0, 0, 0 };
    uint32_t              mip_levels{ 0 };
    uint32_t              array_layers{ 0 };
    VkSampleCountFlagBits samples{};
    VkImageTiling         tiling{};
    VkImageLayout         current_layout{ VK_IMAGE_LAYOUT_UNDEFINED };
};

struct ImageViewWrapper : public HandleWrapper<VkImageView>
{
    // Store handle to associated image for tracking render pass layout transitions.
    VkImage image{ VK_NULL_HANDLE };
};

struct FramebufferWrapper : public HandleWrapper<VkFramebuffer>
{
    // TODO: This only requires the unique sequence number once handles are fully wrapped.
    VkRenderPass      render_pass{ VK_NULL_HANDLE };
    format::HandleId  render_pass_id{ 0 };
    format::ApiCallId render_pass_create_call_id{ format::ApiCallId::ApiCall_Unknown };
    CreateParameters  render_pass_create_parameters;

    // Track handles of image attachments for processing render pass layout transitions.
    std::vector<VkImage> attachments;
};

struct SemaphoreWrapper : public HandleWrapper<VkSemaphore>
{
    // Track signal/wait: when submitted for signal, set a bit in a bitmask to identify signal source (queue submit,
    // acquire next image, etc). On wait, clear bitmask.  On state write, if mask is not 0, submit a signal operation.
};

struct CommandPoolWrapper;
struct CommandBufferWrapper : public HandleWrapper<VkCommandBuffer>
{
    VkCommandBufferLevel     level{ VK_COMMAND_BUFFER_LEVEL_PRIMARY };
    util::MemoryOutputStream command_data;

    // Pool from which command buffer was allocated. The command buffer must be removed from the pool's allocation list
    // when destroyed.
    CommandPoolWrapper* pool{ nullptr };

    // Image layout info tracked for image barriers recorded to the command buffer. To be updated on calls to
    // vkCmdPipelineBarrier and vkCmdEndRenderPass and applied to the image wrapper on calls to vkQueueSubmit. To be
    // transferred from secondary command buffers to primary command buffers on calls to vkCmdExecuteCommands.
    std::unordered_map<VkImage, VkImageLayout> pending_layouts;

    // Render pass object tracking for processing image layout transitions. Render pass and framebuffer values
    // for the active render pass instance will be set on calls to vkCmdBeginRenderPass and will be used to update the
    // pending image layout on calls to vkCmdEndRenderPass.
    VkRenderPass  active_render_pass{ VK_NULL_HANDLE };
    VkFramebuffer render_pass_framebuffer{ VK_NULL_HANDLE };
};

struct DeviceMemoryWrapper : public HandleWrapper<VkDeviceMemory>
{
    uint32_t     memory_type_index{ std::numeric_limits<uint32_t>::max() };
    VkDeviceSize allocation_size{ 0 };
    const void*  mapped_data{ nullptr };
    VkDeviceSize mapped_offset{ 0 };
    VkDeviceSize mapped_size{ 0 };
};

struct QueryPoolWrapper : public HandleWrapper<VkQueryPool>
{
    // TODO: Check on 'vkCmdWriteTimestamp` requirements: do we track if timestamp was or was not written for active
    // queries, and then write timestamp with state.

    // vkCmdBeginQuery or vkCmdBeginQueryIndexedEXT parameters for active queries: query index to query flags and type
    // specific index (transform feedback vertex stream index).
    std::unordered_map<uint32_t, QueryInfo> active_queries;
};

struct PipelineLayoutWrapper : public HandleWrapper<VkPipelineLayout>
{
    // Creation info for objects used to create the pipeline layout, which may have been destroyed after pipeline layout
    // creation.
    std::shared_ptr<PipelineLayoutDependencies> layout_dependencies;
};

struct RenderPassWrapper : public HandleWrapper<VkRenderPass>
{
    // Final image attachment layouts to be used for processing image layout transitions after calls to
    // vkCmdEndRenderPass.
    std::vector<VkImageLayout> attachment_final_layouts;
};

struct PipelineWrapper : public HandleWrapper<VkPipeline>
{
    // Creation info for objects used to create the pipeline, which may have been destroyed after pipeline creation.
    std::vector<ShaderModuleInfo> shader_modules;

    // TODO: This only requires the unique sequence number once handles are fully wrapped.
    VkRenderPass      render_pass{ VK_NULL_HANDLE };
    format::HandleId  render_pass_id{ 0 };
    format::ApiCallId render_pass_create_call_id{ format::ApiCallId::ApiCall_Unknown };
    CreateParameters  render_pass_create_parameters;

    // TODO: This only requires the unique sequence number once handles are fully wrapped.
    VkPipelineLayout                            layout{ VK_NULL_HANDLE };
    format::HandleId                            layout_id{ 0 };
    format::ApiCallId                           layout_create_call_id{ format::ApiCallId::ApiCall_Unknown };
    CreateParameters                            layout_create_parameters;
    std::shared_ptr<PipelineLayoutDependencies> layout_dependencies;

    // TODO: Base pipeline
    // TODO: Pipeline cache
};

struct DescriptorSetLayoutWrapper : public HandleWrapper<VkDescriptorSetLayout>
{
    std::vector<DescriptorBindingInfo> binding_info;
};

struct DescriptorPoolWrapper;
struct DescriptorSetWrapper : public HandleWrapper<VkDescriptorSet>
{
    VkDevice device{ VK_NULL_HANDLE };

    // Map for descriptor binding index to array of descriptor info.
    std::unordered_map<uint32_t, DescriptorInfo> bindings;

    // Pool from which set was allocated. The set must be removed from the pool's allocation list when destroyed.
    DescriptorPoolWrapper* pool{ nullptr };
};

struct DescriptorPoolWrapper : public HandleWrapper<VkDescriptorPool>
{
    // Track descriptor set info, which must be destroyed on descriptor pool reset.
    std::unordered_map<VkDescriptorSet, DescriptorSetWrapper*> allocated_sets;
};

struct CommandPoolWrapper : public HandleWrapper<VkCommandPool>
{
    // Track command buffer info, which must be destroyed on command pool reset.
    std::unordered_map<VkCommandBuffer, CommandBufferWrapper*> allocated_buffers;
};

struct SwapchainKHRWrapper : public HandleWrapper<VkSwapchainKHR>
{
    std::vector<bool> image_needs_acquire;
};

struct ObjectTableNVXWrapper : public HandleWrapper<VkObjectTableNVX>
{
    // TODO: Determine what additional state tracking is needed.
};

struct AccelerationStructureNVWrapper : public HandleWrapper<VkAccelerationStructureNV>
{
    // TODO: Determine what additional state tracking is needed.
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
