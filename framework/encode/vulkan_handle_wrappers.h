/*
** Copyright (c) 2019-2020 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_VULKAN_HANDLE_WRAPPERS_H
#define GFXRECON_ENCODE_VULKAN_HANDLE_WRAPPERS_H

#include "encode/descriptor_update_template_info.h"
#include "encode/vulkan_state_info.h"
#include "format/format.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "util/defines.h"
#include "util/memory_output_stream.h"
#include "util/page_guard_manager.h"

#include "vulkan/vulkan.h"

#include <limits>
#include <memory>
#include <set>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

//
// Handle wrappers for storing object state information with object handles.
//

template <typename T>
struct HandleWrapper
{
    typedef T HandleType;

    // Dispatch table key for dispatchable handles. Must be the first struct member to be compatible with the
    // loader defined handles.
    void* dispatch_key{ nullptr };

    // Standard state info required for all handles.
    HandleType        handle{ VK_NULL_HANDLE };           // Original handle value provided by the driver.
    format::HandleId  handle_id{ format::kNullHandleId }; // Globally unique ID assigned to the handle by the layer.
    format::ApiCallId create_call_id{ format::ApiCallId::ApiCall_Unknown };
    CreateParameters  create_parameters;
};

//
// Type definitions for handle wrappers that do not require additional state info.
//

// clang-format off
struct ShaderModuleWrapper                  : public HandleWrapper<VkShaderModule> {};
struct PipelineCacheWrapper                 : public HandleWrapper<VkPipelineCache> {};
struct SamplerWrapper                       : public HandleWrapper<VkSampler> {};
struct SamplerYcbcrConversionWrapper        : public HandleWrapper<VkSamplerYcbcrConversion> {};
struct DebugReportCallbackEXTWrapper        : public HandleWrapper<VkDebugReportCallbackEXT> {};
struct DebugUtilsMessengerEXTWrapper        : public HandleWrapper<VkDebugUtilsMessengerEXT> {};
struct ValidationCacheEXTWrapper            : public HandleWrapper<VkValidationCacheEXT> {};
struct IndirectCommandsLayoutNVWrapper      : public HandleWrapper<VkIndirectCommandsLayoutNV> {};
struct PerformanceConfigurationINTELWrapper : public HandleWrapper<VkPerformanceConfigurationINTEL> {};
struct DeferredOperationKHRWrapper          : public HandleWrapper<VkDeferredOperationKHR> {};
struct PrivateDataSlotEXTWrapper            : public HandleWrapper<VkPrivateDataSlotEXT> {};

// This handle type has a create function, but no destroy function. The handle wrapper will be owned by its parent VkDisplayKHR
// handle wrapper, which will filter duplicate handle retrievals and ensure that the wrapper is destroyed.
struct DisplayModeKHRWrapper            : public HandleWrapper<VkDisplayModeKHR> {};
// clang-format on

//
// Declarations for handle wrappers that require additional state info.
//

// This handle type is retrieved and has no destroy function. The handle wrapper will be owned by its parent
// VkPhysicalDevice handle wrapper, which will filter duplicate handle retrievals and ensure that the wrapper is
// destroyed.
struct DisplayKHRWrapper : public HandleWrapper<VkDisplayKHR>
{
    std::vector<DisplayModeKHRWrapper*> child_display_modes;
};

// This handle type is retrieved and has no destroy function. The handle wrapper will be owned by its parent VkInstance
// handle wrapper, which will filter duplicate handle retrievals and ensure that the wrapper is destroyed.
struct PhysicalDeviceWrapper : public HandleWrapper<VkPhysicalDevice>
{
    InstanceTable*                  layer_table_ref{ nullptr };
    std::vector<DisplayKHRWrapper*> child_displays;

    // Track memory types for use when creating snapshots of buffer and image resource memory content.
    VkPhysicalDeviceMemoryProperties memory_properties{};

    // Track queue family properties retrieval call data to write to state snapshot after physical device creation.
    // The queue family data is only written to the state snapshot if the application made the API call to retrieve it.
    format::ApiCallId                           queue_family_properties_call_id{ format::ApiCallId::ApiCall_Unknown };
    uint32_t                                    queue_family_properties_count{ 0 };
    std::unique_ptr<VkQueueFamilyProperties[]>  queue_family_properties;
    std::unique_ptr<VkQueueFamilyProperties2[]> queue_family_properties2;
    std::vector<std::unique_ptr<VkQueueFamilyCheckpointPropertiesNV>> queue_family_checkpoint_properties;
};

struct InstanceWrapper : public HandleWrapper<VkInstance>
{
    InstanceTable                       layer_table;
    std::vector<PhysicalDeviceWrapper*> child_physical_devices;
    bool                                have_device_properties{ false };
};

struct QueueWrapper : public HandleWrapper<VkQueue>
{
    DeviceTable* layer_table_ref{ nullptr };
};

struct DeviceWrapper : public HandleWrapper<VkDevice>
{
    DeviceTable                layer_table;
    PhysicalDeviceWrapper*     physical_device{ nullptr };
    std::vector<QueueWrapper*> child_queues;
};

struct FenceWrapper : public HandleWrapper<VkFence>
{
    // Signaled state at creation to be compared with signaled state at snapshot write. If states are different, the
    // create parameters will need to be modified to reflect the state at snapshot write.
    bool           created_signaled{ false };
    DeviceWrapper* device{ nullptr };
};

struct EventWrapper : public HandleWrapper<VkEvent>
{
    DeviceWrapper* device{ nullptr };
};

struct DeviceMemoryWrapper : public HandleWrapper<VkDeviceMemory>
{
    uint32_t         memory_type_index{ std::numeric_limits<uint32_t>::max() };
    VkDeviceSize     allocation_size{ 0 };
    DeviceWrapper*   map_device{ nullptr };
    const void*      mapped_data{ nullptr };
    VkDeviceSize     mapped_offset{ 0 };
    VkDeviceSize     mapped_size{ 0 };
    VkMemoryMapFlags mapped_flags{ 0 };
    void*            external_allocation{ nullptr };
    uintptr_t        shadow_allocation{ util::PageGuardManager::kNullShadowHandle };
    AHardwareBuffer* hardware_buffer{ nullptr };
    format::HandleId hardware_buffer_memory_id{ format::kNullHandleId };
};

struct BufferWrapper : public HandleWrapper<VkBuffer>
{
    DeviceWrapper*   bind_device{ nullptr };
    format::HandleId bind_memory_id{ format::kNullHandleId };
    VkDeviceSize     bind_offset{ 0 };
    uint32_t         queue_family_index{ 0 };
    VkDeviceSize     created_size{ 0 };
};

struct ImageWrapper : public HandleWrapper<VkImage>
{
    DeviceWrapper*        bind_device{ nullptr };
    format::HandleId      bind_memory_id{ format::kNullHandleId };
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

struct BufferViewWrapper : public HandleWrapper<VkBufferView>
{
    format::HandleId buffer_id{ format::kNullHandleId };
};

struct ImageViewWrapper : public HandleWrapper<VkImageView>
{
    format::HandleId image_id{ format::kNullHandleId };
    ImageWrapper*    image{ nullptr };
};

struct FramebufferWrapper : public HandleWrapper<VkFramebuffer>
{
    // Creation info for objects used to create the framebuffer, which may have been destroyed after creation.
    format::HandleId  render_pass_id{ format::kNullHandleId };
    format::ApiCallId render_pass_create_call_id{ format::ApiCallId::ApiCall_Unknown };
    CreateParameters  render_pass_create_parameters;

    std::vector<format::HandleId> image_view_ids;

    // Track handles of image attachments for processing render pass layout transitions.
    std::vector<ImageWrapper*> attachments;
};

struct SemaphoreWrapper : public HandleWrapper<VkSemaphore>
{
    // Track semaphore signaled state. State is signaled when a sempahore is submitted to QueueSubmit, QueueBindSparse,
    // AcquireNextImageKHR, or AcquireNextImage2KHR as a signal semaphore. State is not signaled when a semaphore is
    // submitted to QueueSubmit, QueueBindSparse, or QueuePresentKHR as a wait semaphore. Initial state after creation
    // is not signaled.
    bool           signaled{ false };
    DeviceWrapper* device{ nullptr };
};

struct QueryPoolWrapper : public HandleWrapper<VkQueryPool>
{
    DeviceWrapper*         device{ nullptr };
    VkQueryType            query_type{};
    uint32_t               query_count{ 0 };
    std::vector<QueryInfo> pending_queries;
};

struct RenderPassWrapper : public HandleWrapper<VkRenderPass>
{
    // Final image attachment layouts to be used for processing image layout transitions after calls to
    // vkCmdEndRenderPass.
    std::vector<VkImageLayout> attachment_final_layouts;
};

struct CommandPoolWrapper;
struct CommandBufferWrapper : public HandleWrapper<VkCommandBuffer>
{
    DeviceTable* layer_table_ref{ nullptr };

    // Members for general wrapper support.
    // Pool from which command buffer was allocated. The command buffer must be removed from the pool's allocation list
    // when destroyed.
    CommandPoolWrapper* parent_pool{ nullptr };

    // Members for trimming state tracking.
    VkCommandBufferLevel       level{ VK_COMMAND_BUFFER_LEVEL_PRIMARY };
    util::MemoryOutputStream   command_data;
    std::set<format::HandleId> command_handles[CommandHandleType::NumHandleTypes];

    // Image layout info tracked for image barriers recorded to the command buffer. To be updated on calls to
    // vkCmdPipelineBarrier and vkCmdEndRenderPass and applied to the image wrapper on calls to vkQueueSubmit. To be
    // transferred from secondary command buffers to primary command buffers on calls to vkCmdExecuteCommands.
    std::unordered_map<ImageWrapper*, VkImageLayout> pending_layouts;

    // Active query info for queries that have been recorded to this command buffer, which will be transfered to the
    // QueryPoolWrapper as pending queries when the command buffer is submitted to a queue.
    std::unordered_map<QueryPoolWrapper*, std::unordered_map<uint32_t, QueryInfo>> recorded_queries;

    // Render pass object tracking for processing image layout transitions. Render pass and framebuffer values
    // for the active render pass instance will be set on calls to vkCmdBeginRenderPass and will be used to update the
    // pending image layout on calls to vkCmdEndRenderPass.
    RenderPassWrapper*  active_render_pass{ nullptr };
    FramebufferWrapper* render_pass_framebuffer{ nullptr };
};

struct PipelineLayoutWrapper : public HandleWrapper<VkPipelineLayout>
{
    // Creation info for objects used to create the pipeline layout, which may have been destroyed after pipeline layout
    // creation.
    std::shared_ptr<PipelineLayoutDependencies> layout_dependencies;
};

struct PipelineWrapper : public HandleWrapper<VkPipeline>
{
    // Creation info for objects used to create the pipeline, which may have been destroyed after pipeline creation.
    std::vector<CreateDependencyInfo>           shader_module_dependencies;
    CreateDependencyInfo                        render_pass_dependency;
    CreateDependencyInfo                        layout_dependency;
    std::shared_ptr<PipelineLayoutDependencies> layout_dependencies; // Shared with PipelineLayoutWrapper

    // TODO: Base pipeline
    // TODO: Pipeline cache
};

struct DescriptorUpdateTemplateWrapper : public HandleWrapper<VkDescriptorUpdateTemplate>
{
    // Members for general wrapper support.
    UpdateTemplateInfo info;
};

struct DescriptorSetLayoutWrapper : public HandleWrapper<VkDescriptorSetLayout>
{
    // Members for trimming state tracking.
    std::vector<DescriptorBindingInfo> binding_info;
};

struct DescriptorPoolWrapper;
struct DescriptorSetWrapper : public HandleWrapper<VkDescriptorSet>
{
    // Members for general wrapper support.
    // Pool from which set was allocated. The set must be removed from the pool's allocation list when destroyed.
    DescriptorPoolWrapper* parent_pool{ nullptr };

    // Members for trimming state tracking.
    DeviceWrapper* device{ nullptr };

    // Map for descriptor binding index to array of descriptor info.
    std::unordered_map<uint32_t, DescriptorInfo> bindings;

    // Creation info for objects used to allocate the descriptor set, which may have been destroyed after descriptor set
    // allocation.
    CreateDependencyInfo set_layout_dependency;
};

struct DescriptorPoolWrapper : public HandleWrapper<VkDescriptorPool>
{
    // Members for general wrapper support.
    // Track descriptor set info, which must be destroyed on descriptor pool reset.
    std::unordered_map<format::HandleId, DescriptorSetWrapper*> child_sets;
};

struct CommandPoolWrapper : public HandleWrapper<VkCommandPool>
{
    // Members for general wrapper support.
    // Track command buffer info, which must be destroyed on command pool reset.
    std::unordered_map<format::HandleId, CommandBufferWrapper*> child_buffers;

    // Members for trimming state tracking.
    uint32_t queue_family_index{ 0 };
};

struct SurfaceKHRWrapper : public HandleWrapper<VkSurfaceKHR>
{
    // Track results from calls to vkGetPhysicalDeviceSurfaceSupportKHR to write to the state snapshot after surface
    // creation. The call is only written to the state snapshot if it was previously called by the application.
    // Keys are the VkPhysicalDevice handle ID.
    std::unordered_map<format::HandleId, std::unordered_map<uint32_t, VkBool32>> surface_support;
    std::unordered_map<format::HandleId, VkSurfaceCapabilitiesKHR>               surface_capabilities;
    std::unordered_map<format::HandleId, std::vector<VkSurfaceFormatKHR>>        surface_formats;
    std::unordered_map<format::HandleId, std::vector<VkPresentModeKHR>>          surface_present_modes;
};

struct SwapchainKHRWrapper : public HandleWrapper<VkSwapchainKHR>
{
    // Members for general wrapper support.
    std::vector<ImageWrapper*> child_images;

    // Members for trimming state tracking.
    DeviceWrapper*                 device{ nullptr };
    SurfaceKHRWrapper*             surface{ nullptr };
    uint32_t                       queue_family_index{ 0 };
    VkFormat                       format{ VK_FORMAT_UNDEFINED };
    VkExtent3D                     extent{ 0, 0, 0 };
    VkSurfaceTransformFlagBitsKHR  pre_transform{ VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR };
    uint32_t                       array_layers{ 0 };
    uint32_t                       last_presented_image{ std::numeric_limits<uint32_t>::max() };
    std::vector<ImageAcquiredInfo> image_acquired_info;
};

struct AccelerationStructureKHRWrapper : public HandleWrapper<VkAccelerationStructureKHR>
{
    // TODO: Determine what additional state tracking is needed.
};

struct AccelerationStructureNVWrapper : public HandleWrapper<VkAccelerationStructureNV>
{
    // TODO: Determine what additional state tracking is needed.
};

// Handle alias types for extension handle types that have been promoted to core types.
typedef SamplerYcbcrConversionWrapper   SamplerYcbcrConversionKHRWrapper;
typedef DescriptorUpdateTemplateWrapper DescriptorUpdateTemplateKHRWrapper;

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_HANDLE_WRAPPERS_H
