/*
** Copyright (c) 2019-2020 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_ENCODE_VULKAN_HANDLE_WRAPPERS_H
#define GFXRECON_ENCODE_VULKAN_HANDLE_WRAPPERS_H

#include "encode/descriptor_update_template_info.h"
#include "encode/vulkan_state_info.h"
#include "encode/handle_unwrap_memory.h"
#include "format/format.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "graphics/vulkan_device_util.h"
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
struct VulkanHandleWrapper
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
struct VulkanShaderModuleWrapper                  : public VulkanHandleWrapper<VkShaderModule> {};
struct VulkanPipelineCacheWrapper                 : public VulkanHandleWrapper<VkPipelineCache> {};
struct VulkanSamplerWrapper                       : public VulkanHandleWrapper<VkSampler> {};
struct VulkanSamplerYcbcrConversionWrapper        : public VulkanHandleWrapper<VkSamplerYcbcrConversion> {};
struct VulkanDebugReportCallbackEXTWrapper        : public VulkanHandleWrapper<VkDebugReportCallbackEXT> {};
struct VulkanDebugUtilsMessengerEXTWrapper        : public VulkanHandleWrapper<VkDebugUtilsMessengerEXT> {};
struct VulkanValidationCacheEXTWrapper            : public VulkanHandleWrapper<VkValidationCacheEXT> {};
struct VulkanIndirectCommandsLayoutNVWrapper      : public VulkanHandleWrapper<VkIndirectCommandsLayoutNV> {};
struct VulkanPerformanceConfigurationINTELWrapper : public VulkanHandleWrapper<VkPerformanceConfigurationINTEL> {};
struct VulkanMicromapEXTWrapper                   : public VulkanHandleWrapper<VkMicromapEXT> {};
struct VulkanOpticalFlowSessionNVWrapper          : public VulkanHandleWrapper<VkOpticalFlowSessionNV> {};
struct VulkanVideoSessionKHRWrapper               : public VulkanHandleWrapper<VkVideoSessionKHR> {};
struct VulkanVideoSessionParametersKHRWrapper     : public VulkanHandleWrapper<VkVideoSessionParametersKHR> {};
struct VulkanShaderEXTWrapper                     : public VulkanHandleWrapper<VkShaderEXT> {};

// This handle type has a create function, but no destroy function. The handle wrapper will be owned by its parent VkDisplayKHR
// handle wrapper, which will filter duplicate handle retrievals and ensure that the wrapper is destroyed.
struct VulkanDisplayModeKHRWrapper            : public VulkanHandleWrapper<VkDisplayModeKHR> {};
// clang-format on

//
// Declarations for handle wrappers that require additional state info.
//

// This handle type is retrieved and has no destroy function. The handle wrapper will be owned by its parent
// VkPhysicalDevice handle wrapper, which will filter duplicate handle retrievals and ensure that the wrapper is
// destroyed.
struct VulkanDisplayKHRWrapper : public VulkanHandleWrapper<VkDisplayKHR>
{
    std::vector<VulkanDisplayModeKHRWrapper*> child_display_modes;
};

// This handle type is retrieved and has no destroy function. The handle wrapper will be owned by its parent VkInstance
// handle wrapper, which will filter duplicate handle retrievals and ensure that the wrapper is destroyed.
struct VulkanPhysicalDeviceWrapper : public VulkanHandleWrapper<VkPhysicalDevice>
{
    VulkanInstanceTable*                  layer_table_ref{ nullptr };
    std::vector<VulkanDisplayKHRWrapper*> child_displays;
    uint32_t                              instance_api_version{ 0 };

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

struct VulkanInstanceWrapper : public VulkanHandleWrapper<VkInstance>
{
    VulkanInstanceTable                       layer_table;
    std::vector<VulkanPhysicalDeviceWrapper*> child_physical_devices;
    bool                                      have_device_properties{ false };
    uint32_t                                  api_version{ VK_MAKE_VERSION(1, 0, 0) };
};

struct VulkanQueueWrapper : public VulkanHandleWrapper<VkQueue>
{
    VulkanDeviceTable* layer_table_ref{ nullptr };
};

struct VulkanDeviceWrapper : public VulkanHandleWrapper<VkDevice>
{
    VulkanDeviceTable                layer_table;
    VulkanPhysicalDeviceWrapper*     physical_device{ nullptr };
    std::vector<VulkanQueueWrapper*> child_queues;

    // Physical device property & feature state at device creation
    graphics::VulkanDevicePropertyFeatureInfo              property_feature_info;
    std::unordered_map<uint32_t, VkDeviceQueueCreateFlags> queue_family_creation_flags;
};

struct VulkanFenceWrapper : public VulkanHandleWrapper<VkFence>
{
    // Signaled state at creation to be compared with signaled state at snapshot write. If states are different, the
    // create parameters will need to be modified to reflect the state at snapshot write.
    bool                 created_signaled{ false };
    VulkanDeviceWrapper* device{ nullptr };
};

struct VulkanEventWrapper : public VulkanHandleWrapper<VkEvent>
{
    VulkanDeviceWrapper* device{ nullptr };
};

struct VulkanDeviceMemoryWrapper : public VulkanHandleWrapper<VkDeviceMemory>
{
    uint32_t     memory_type_index{ std::numeric_limits<uint32_t>::max() };
    VkDeviceSize allocation_size{ 0 };
    // This is the device which was used to allocate the memory.
    // Spec states if the memory can be mapped, the mapping device must be this device.
    // The device wrapper will be initialized when allocating the memory. Some handling
    // like VulkanStateTracker::TrackTlasToBlasDependencies may use it before mapping
    // the memory.
    VulkanDeviceWrapper* parent_device{ nullptr };
    const void*          mapped_data{ nullptr };
    VkDeviceSize         mapped_offset{ 0 };
    VkDeviceSize         mapped_size{ 0 };
    VkMemoryMapFlags     mapped_flags{ 0 };
    void*                external_allocation{ nullptr };
    uintptr_t            shadow_allocation{ util::PageGuardManager::kNullShadowHandle };
    AHardwareBuffer*     hardware_buffer{ nullptr };
    format::HandleId     hardware_buffer_memory_id{ format::kNullHandleId };

    // State tracking info for memory with device addresses.
    format::HandleId device_id{ format::kNullHandleId };
    VkDeviceAddress  address{ 0 };
};

struct VulkanBufferWrapper : public VulkanHandleWrapper<VkBuffer>
{
    VulkanDeviceWrapper* bind_device{ nullptr };
    const void*          bind_pnext{ nullptr };
    HandleUnwrapMemory bind_pnext_memory; // Global HandleUnwrapMemory could be reset anytime, so it should have its own
                                          // HandleUnwrapMemory.
    format::HandleId bind_memory_id{ format::kNullHandleId };
    VkDeviceSize     bind_offset{ 0 };
    uint32_t         queue_family_index{ 0 };
    VkDeviceSize     created_size{ 0 };

    // State tracking info for buffers with device addresses.
    format::HandleId device_id{ format::kNullHandleId };
    VkDeviceAddress  address{ 0 };
};

struct VulkanImageWrapper : public VulkanHandleWrapper<VkImage>
{
    VulkanDeviceWrapper* bind_device{ nullptr };
    const void*          bind_pnext{ nullptr };
    HandleUnwrapMemory bind_pnext_memory; // Global HandleUnwrapMemory could be reset anytime, so it should have its own
                                          // HandleUnwrapMemory.
    format::HandleId         bind_memory_id{ format::kNullHandleId };
    VkDeviceSize             bind_offset{ 0 };
    uint32_t                 queue_family_index{ 0 };
    VkImageType              image_type{ VK_IMAGE_TYPE_2D };
    VkFormat                 format{ VK_FORMAT_UNDEFINED };
    VkExtent3D               extent{ 0, 0, 0 };
    uint32_t                 mip_levels{ 0 };
    uint32_t                 array_layers{ 0 };
    VkSampleCountFlagBits    samples{};
    VkImageTiling            tiling{};
    VkImageLayout            current_layout{ VK_IMAGE_LAYOUT_UNDEFINED };
    bool                     is_swapchain_image{ false };
    std::set<VkSwapchainKHR> parent_swapchains;
};

struct VulkanBufferViewWrapper : public VulkanHandleWrapper<VkBufferView>
{
    format::HandleId buffer_id{ format::kNullHandleId };
};

struct VulkanImageViewWrapper : public VulkanHandleWrapper<VkImageView>
{
    format::HandleId    image_id{ format::kNullHandleId };
    VulkanImageWrapper* image{ nullptr };
};

struct VulkanFramebufferWrapper : public VulkanHandleWrapper<VkFramebuffer>
{
    // Creation info for objects used to create the framebuffer, which may have been destroyed after creation.
    format::HandleId  render_pass_id{ format::kNullHandleId };
    format::ApiCallId render_pass_create_call_id{ format::ApiCallId::ApiCall_Unknown };
    CreateParameters  render_pass_create_parameters;

    std::vector<format::HandleId> image_view_ids;

    // Track handles of image attachments for processing render pass layout transitions.
    std::vector<VulkanImageWrapper*> attachments;
};

struct VulkanSemaphoreWrapper : public VulkanHandleWrapper<VkSemaphore>
{
    // Track semaphore signaled state. State is signaled when a sempahore is submitted to QueueSubmit, QueueBindSparse,
    // AcquireNextImageKHR, or AcquireNextImage2KHR as a signal semaphore. State is not signaled when a semaphore is
    // submitted to QueueSubmit, QueueBindSparse, or QueuePresentKHR as a wait semaphore. Initial state after creation
    // is not signaled.
    bool                 signaled{ false };
    VkSemaphoreType      type{ VK_SEMAPHORE_TYPE_BINARY_KHR };
    VulkanDeviceWrapper* device{ nullptr };
};

struct VulkanQueryPoolWrapper : public VulkanHandleWrapper<VkQueryPool>
{
    VulkanDeviceWrapper*   device{ nullptr };
    VkQueryType            query_type{};
    uint32_t               query_count{ 0 };
    std::vector<QueryInfo> pending_queries;
};

struct VulkanRenderPassWrapper : public VulkanHandleWrapper<VkRenderPass>
{
    // Final image attachment layouts to be used for processing image layout transitions after calls to
    // vkCmdEndRenderPass.
    std::vector<VkImageLayout> attachment_final_layouts;
};

struct VulkanAccelerationStructureKHRWrapper;
struct VulkanCommandPoolWrapper;
struct VulkanCommandBufferWrapper : public VulkanHandleWrapper<VkCommandBuffer>
{
    VulkanDeviceTable* layer_table_ref{ nullptr };

    // Members for general wrapper support.
    // Pool from which command buffer was allocated. The command buffer must be removed from the pool's allocation list
    // when destroyed.
    VulkanCommandPoolWrapper* parent_pool{ nullptr };

    // Members for trimming state tracking.
    VkCommandBufferLevel       level{ VK_COMMAND_BUFFER_LEVEL_PRIMARY };
    util::MemoryOutputStream   command_data;
    std::set<format::HandleId> command_handles[CommandHandleType::NumHandleTypes];

    // Image layout info tracked for image barriers recorded to the command buffer. To be updated on calls to
    // vkCmdPipelineBarrier and vkCmdEndRenderPass and applied to the image wrapper on calls to vkQueueSubmit. To be
    // transferred from secondary command buffers to primary command buffers on calls to vkCmdExecuteCommands.
    std::unordered_map<VulkanImageWrapper*, VkImageLayout> pending_layouts;

    // Active query info for queries that have been recorded to this command buffer, which will be transfered to the
    // QueryPoolWrapper as pending queries when the command buffer is submitted to a queue.
    std::unordered_map<VulkanQueryPoolWrapper*, std::unordered_map<uint32_t, QueryInfo>> recorded_queries;

    // Render pass object tracking for processing image layout transitions. Render pass and framebuffer values
    // for the active render pass instance will be set on calls to vkCmdBeginRenderPass and will be used to update the
    // pending image layout on calls to vkCmdEndRenderPass.
    VulkanRenderPassWrapper*  active_render_pass{ nullptr };
    VulkanFramebufferWrapper* render_pass_framebuffer{ nullptr };

    // Treat the sumbission of this command buffer as a frame boundary.
    bool is_frame_boundary{ false };

    // Corellation between TLASes that are being build in this command buffer and the device addresses
    // used to reference BLASes.
    struct tlas_build_info
    {
        // The device address that points to the VkAccelerationStructureInstanceKHR used to build this TLAS
        VkDeviceAddress address;

        // The number of BLASes this TLAS is using
        uint32_t blas_count;

        // The offset from the above address to start reading the VkAccelerationStructureInstanceKHR structures
        uint32_t offset;
    };
    std::vector<std::pair<VulkanAccelerationStructureKHRWrapper*, tlas_build_info>> tlas_build_info_map;
};

struct VulkanPipelineLayoutWrapper : public VulkanHandleWrapper<VkPipelineLayout>
{
    // Creation info for objects used to create the pipeline layout, which may have been destroyed after pipeline layout
    // creation.
    std::shared_ptr<PipelineLayoutDependencies> layout_dependencies;
};

struct VulkanPipelineWrapper : public VulkanHandleWrapper<VkPipeline>
{
    // Creation info for objects used to create the pipeline, which may have been destroyed after pipeline creation.
    std::vector<CreateDependencyInfo>           shader_module_dependencies;
    CreateDependencyInfo                        render_pass_dependency;
    CreateDependencyInfo                        layout_dependency;
    std::shared_ptr<PipelineLayoutDependencies> layout_dependencies; // Shared with PipelineLayoutWrapper

    // Ray tracing pipeline's shader group handle data
    format::HandleId     device_id{ format::kNullHandleId };
    std::vector<uint8_t> shader_group_handle_data;
    CreateDependencyInfo deferred_operation;

    // TODO: Base pipeline
    // TODO: Pipeline cache
};

struct VulkanDeferredOperationKHRWrapper : public VulkanHandleWrapper<VkDeferredOperationKHR>
{
    // Record CreateRayTracingPipelinesKHR parameters for safety.
    HandleUnwrapMemory                             handle_unwrap_memory;
    std::vector<VkRayTracingPipelineCreateInfoKHR> create_infos;
    VkAllocationCallbacks                          allocator{};
    VkAllocationCallbacks*                         p_allocator{ nullptr };
    std::vector<VkPipeline>                        pipelines;
    VkPipeline*                                    pPipelines;
    VkPipelineCache                                pipelineCache;
    bool                                           pending_state = false;
};

struct VulkanDescriptorUpdateTemplateWrapper : public VulkanHandleWrapper<VkDescriptorUpdateTemplate>
{
    // Members for general wrapper support.
    UpdateTemplateInfo info;
};

struct VulkanDescriptorSetLayoutWrapper : public VulkanHandleWrapper<VkDescriptorSetLayout>
{
    // Members for trimming state tracking.
    std::vector<DescriptorBindingInfo> binding_info;
};

struct VulkanDescriptorPoolWrapper;
struct VulkanDescriptorSetWrapper : public VulkanHandleWrapper<VkDescriptorSet>
{
    // Members for general wrapper support.
    // Pool from which set was allocated. The set must be removed from the pool's allocation list when destroyed.
    VulkanDescriptorPoolWrapper* parent_pool{ nullptr };

    // Members for trimming state tracking.
    VulkanDeviceWrapper* device{ nullptr };

    // Map for descriptor binding index to array of descriptor info.
    std::unordered_map<uint32_t, DescriptorInfo> bindings;

    // Creation info for objects used to allocate the descriptor set, which may have been destroyed after descriptor set
    // allocation.
    CreateDependencyInfo set_layout_dependency;
};

struct VulkanDescriptorPoolWrapper : public VulkanHandleWrapper<VkDescriptorPool>
{
    // Members for general wrapper support.
    // Track descriptor set info, which must be destroyed on descriptor pool reset.
    std::unordered_map<format::HandleId, VulkanDescriptorSetWrapper*> child_sets;
};

struct VulkanCommandPoolWrapper : public VulkanHandleWrapper<VkCommandPool>
{
    // Members for general wrapper support.
    // Track command buffer info, which must be destroyed on command pool reset.
    std::unordered_map<format::HandleId, VulkanCommandBufferWrapper*> child_buffers;

    // Members for trimming state tracking.
    uint32_t queue_family_index{ 0 };

    VulkanDeviceWrapper* device{ nullptr };
    bool                 trim_command_pool{ false };
};

// For vkGetPhysicalDeviceSurfaceCapabilitiesKHR
struct VulkanSurfaceCapabilities
{
    VkPhysicalDeviceSurfaceInfo2KHR surface_info;
    HandleUnwrapMemory              surface_info_pnext_memory;

    VkSurfaceCapabilities2KHR surface_capabilities;
    HandleUnwrapMemory        surface_capabilities_pnext_memory;
};

// For vkGetPhysicalDeviceSurfaceFormatsKHR
struct VulkanSurfaceFormats
{
    VkPhysicalDeviceSurfaceInfo2KHR surface_info;
    HandleUnwrapMemory              surface_info_pnext_memory;

    std::vector<VkSurfaceFormat2KHR> surface_formats;
    std::vector<HandleUnwrapMemory>  surface_formats_pnext_memory;
};

// For vkGetPhysicalDeviceSurfacePresentModesKHR
struct VulkanSurfacePresentModes
{
    std::vector<VkPresentModeKHR> present_modes;
    const void*                   surface_info_pnext{ nullptr };
    HandleUnwrapMemory            surface_info_pnext_memory;
};

// For vkGetDeviceGroupSurfacePresentModesKHR
struct VulkanGroupSurfacePresentModes
{
    VkDeviceGroupPresentModeFlagsKHR present_modes{ 0 };
    const void*                      surface_info_pnext{ nullptr };
    HandleUnwrapMemory               surface_info_pnext_memory;
};

struct VulkanSurfaceKHRWrapper : public VulkanHandleWrapper<VkSurfaceKHR>
{
    // Track results from calls to vkGetPhysicalDeviceSurfaceSupportKHR to write to the state snapshot after surface
    // creation. The call is only written to the state snapshot if it was previously called by the application.
    // Keys are the VkPhysicalDevice handle ID.
    std::unordered_map<format::HandleId, std::unordered_map<uint32_t, VkBool32>> surface_support;
    std::unordered_map<format::HandleId, VulkanSurfaceCapabilities>              surface_capabilities;
    std::unordered_map<format::HandleId, VulkanSurfaceFormats>                   surface_formats;
    std::unordered_map<format::HandleId, VulkanSurfacePresentModes>              surface_present_modes;

    // Keys are the VkDevice handle ID.
    std::unordered_map<format::HandleId, VulkanGroupSurfacePresentModes> group_surface_present_modes;
};

struct VulkanSwapchainKHRWrapper : public VulkanHandleWrapper<VkSwapchainKHR>
{
    // Members for general wrapper support.
    std::vector<VulkanImageWrapper*> child_images;

    // Members for trimming state tracking.
    VulkanDeviceWrapper*           device{ nullptr };
    VulkanSurfaceKHRWrapper*       surface{ nullptr };
    uint32_t                       queue_family_index{ 0 };
    VkFormat                       format{ VK_FORMAT_UNDEFINED };
    VkExtent3D                     extent{ 0, 0, 0 };
    VkSurfaceTransformFlagBitsKHR  pre_transform{ VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR };
    uint32_t                       array_layers{ 0 };
    uint32_t                       last_presented_image{ std::numeric_limits<uint32_t>::max() };
    std::vector<ImageAcquiredInfo> image_acquired_info;
    bool                           acquire_full_screen_exclusive_mode{ false };
    bool                           release_full_screen_exclusive_mode{ false };
    bool                           using_local_dimming_AMD{ false };
    VkBool32                       local_dimming_enable_AMD{ false };
};

struct VulkanAccelerationStructureKHRWrapper : public VulkanHandleWrapper<VkAccelerationStructureKHR>
{
    // State tracking info for buffers with device addresses.
    format::HandleId device_id{ format::kNullHandleId };
    VkDeviceAddress  address{ 0 };

    // List of BLASes this AS references. Used only while tracking.
    std::vector<VulkanAccelerationStructureKHRWrapper*> blas;
};

struct VulkanAccelerationStructureNVWrapper : public VulkanHandleWrapper<VkAccelerationStructureNV>
{
    // TODO: Determine what additional state tracking is needed.
};

struct VulkanPrivateDataSlotWrapper : public VulkanHandleWrapper<VkPrivateDataSlot>
{
    VulkanDeviceWrapper* device{ nullptr };
    VkObjectType         object_type{ VK_OBJECT_TYPE_UNKNOWN };
    uint64_t             object_handle{ 0 };
    uint64_t             data{ 0 };
};

struct PipelineCacheWrapper : public HandleWrapper<VkPipelineCache>
{
    DeviceWrapper*            device{ nullptr };
    VkPipelineCacheCreateInfo create_info;
    std::vector<uint8_t>      cache_data;
};

// Handle alias types for extension handle types that have been promoted to core types.
typedef VulkanSamplerYcbcrConversionWrapper   VulkanSamplerYcbcrConversionKHRWrapper;
typedef VulkanDescriptorUpdateTemplateWrapper VulkanDescriptorUpdateTemplateKHRWrapper;
typedef VulkanPrivateDataSlotWrapper          VulkanPrivateDataSlotEXTWrapper;

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_HANDLE_WRAPPERS_H
