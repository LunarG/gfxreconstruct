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
#include "graphics/vulkan_util.h"
#include "graphics/vulkan_device_util.h"
#include "graphics/vulkan_instance_util.h"
#include "graphics/vulkan_resources_util.h"
#include "util/defines.h"
#include "util/memory_output_stream.h"
#include "util/page_guard_manager.h"

#include "vulkan/vulkan.h"
#include "vulkan/vulkan_core.h"

#include <cstddef>
#include <limits>
#include <memory>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>
#include <optional>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)
GFXRECON_BEGIN_NAMESPACE(vulkan_wrappers)

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
    vulkan_state_info::CreateParameters create_parameters;
    vulkan_state_info::CreateParameters debug_name_create_parameters;
    vulkan_state_info::CreateParameters debug_tag_create_parameters;
};

//
// Type definitions for handle wrappers that do not require additional state info.
//

// clang-format off
struct ShaderModuleWrapper                            : public HandleWrapper<VkShaderModule> {};
struct SamplerYcbcrConversionWrapper                  : public HandleWrapper<VkSamplerYcbcrConversion> {};
struct DebugReportCallbackEXTWrapper                  : public HandleWrapper<VkDebugReportCallbackEXT> {};
struct DebugUtilsMessengerEXTWrapper                  : public HandleWrapper<VkDebugUtilsMessengerEXT> {};
struct ValidationCacheEXTWrapper                      : public HandleWrapper<VkValidationCacheEXT> {};
struct IndirectCommandsLayoutNVWrapper                : public HandleWrapper<VkIndirectCommandsLayoutNV> {};
struct PerformanceConfigurationINTELWrapper           : public HandleWrapper<VkPerformanceConfigurationINTEL> {};
struct MicromapEXTWrapper                             : public HandleWrapper<VkMicromapEXT> {};
struct OpticalFlowSessionNVWrapper                    : public HandleWrapper<VkOpticalFlowSessionNV> {};
struct VideoSessionKHRWrapper                         : public HandleWrapper<VkVideoSessionKHR> {};
struct VideoSessionParametersKHRWrapper               : public HandleWrapper<VkVideoSessionParametersKHR> {};
struct ShaderEXTWrapper                               : public HandleWrapper<VkShaderEXT> {};

struct PipelineBinaryKHRWrapper                       : public HandleWrapper<VkPipelineBinaryKHR> {};
struct PipelineBinaryCreateInfoKHRWrapper             : public HandleWrapper<VkPipelineBinaryCreateInfoKHR> {};
struct PipelineBinaryDataInfoKHRWrapper               : public HandleWrapper<VkPipelineBinaryDataInfoKHR> {};
struct PipelineBinaryDataKHRWrapper                   : public HandleWrapper<VkPipelineBinaryDataKHR> {};
struct PipelineBinaryHandlesInfoKHRWrapper            : public HandleWrapper<VkPipelineBinaryHandlesInfoKHR> {};
struct PipelineBinaryKeyKHRWrapper                    : public HandleWrapper<VkPipelineBinaryKeyKHR> {};
struct PipelineBinaryKeysAndDataKHRWrapper            : public HandleWrapper<VkPipelineBinaryKeysAndDataKHR> {};
struct ReleaseCapturedPipelineDataInfoKHRWrapper      : public HandleWrapper<VkReleaseCapturedPipelineDataInfoKHR> {};
struct DevicePipelineBinaryInternalCacheControlKHRWrapper      : public HandleWrapper<VkDevicePipelineBinaryInternalCacheControlKHR> {};
struct PipelineBinaryInfoKHRWrapper      : public HandleWrapper<VkPipelineBinaryInfoKHR> {};
struct PhysicalDevicePipelineBinaryFeaturesKHRWrapper      : public HandleWrapper<VkPhysicalDevicePipelineBinaryFeaturesKHR> {};
struct PhysicalDevicePipelineBinaryPropertiesKHRWrapper      : public HandleWrapper<VkPhysicalDevicePipelineBinaryPropertiesKHR> {};
struct IndirectCommandsLayoutEXTWrapper : public HandleWrapper<VkIndirectCommandsLayoutEXT> {};
struct IndirectExecutionSetEXTWrapper : public HandleWrapper<VkIndirectExecutionSetEXT> {};

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
    graphics::VulkanInstanceTable*   layer_table_ref{ nullptr };
    std::vector<DisplayKHRWrapper*>  child_displays;
    graphics::VulkanInstanceUtilInfo instance_info{};

    // Track memory types for use when creating snapshots of buffer and image resource memory content.
    VkPhysicalDeviceMemoryProperties memory_properties{};

    // Track queue family properties retrieval call data to write to state snapshot after physical device creation.
    // The queue family data is only written to the state snapshot if the application made the API call to retrieve it.
    format::ApiCallId                           queue_family_properties_call_id{ format::ApiCallId::ApiCall_Unknown };
    uint32_t                                    queue_family_properties_count{ 0 };
    std::unique_ptr<VkQueueFamilyProperties[]>  queue_family_properties;
    std::unique_ptr<VkQueueFamilyProperties2[]> queue_family_properties2;
    std::vector<std::unique_ptr<VkQueueFamilyCheckpointPropertiesNV>> queue_family_checkpoint_properties;

    // Track RayTracingPipeline / AccelerationStructure properties
    std::optional<VkPhysicalDeviceRayTracingPipelinePropertiesKHR>    ray_tracing_pipeline_properties;
    std::optional<VkPhysicalDeviceAccelerationStructurePropertiesKHR> acceleration_structure_properties;
};

struct InstanceWrapper : public HandleWrapper<VkInstance>
{
    graphics::VulkanInstanceTable       layer_table;
    std::vector<PhysicalDeviceWrapper*> child_physical_devices;
    bool                                have_device_properties{ false };
    uint32_t                            api_version{ VK_MAKE_VERSION(1, 0, 0) };
};

struct QueueWrapper : public HandleWrapper<VkQueue>
{
    graphics::VulkanDeviceTable* layer_table_ref{ nullptr };
};

struct DeviceWrapper : public HandleWrapper<VkDevice>
{
    graphics::VulkanDeviceTable layer_table;
    PhysicalDeviceWrapper*      physical_device{ nullptr };
    std::vector<QueueWrapper*>  child_queues;

    // Physical device property & feature state at device creation
    graphics::VulkanDevicePropertyFeatureInfo              property_feature_info;
    std::unordered_map<uint32_t, VkDeviceQueueCreateFlags> queue_family_creation_flags;
    std::vector<uint32_t>                                  queue_family_indices;
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

struct DescriptorSetWrapper;
struct AssetWrapperBase
{
    DeviceWrapper*             bind_device{ nullptr };
    const void*                bind_pnext{ nullptr };
    std::unique_ptr<uint8_t[]> bind_pnext_memory;

    format::HandleId bind_memory_id{ format::kNullHandleId };
    VkDeviceSize     bind_offset{ 0 };
    uint32_t         queue_family_index{ 0 };

    VkDeviceSize                              size{ 0 };
    bool                                      dirty{ true };
    std::unordered_set<DescriptorSetWrapper*> descriptor_sets_bound_to;
};

struct BufferViewWrapper;
struct BufferWrapper : public HandleWrapper<VkBuffer>, AssetWrapperBase
{
    // State tracking info for buffers with device addresses.
    format::HandleId   device_id{ format::kNullHandleId };
    VkDeviceAddress    address{ 0 };
    VkDeviceAddress    opaque_address{ 0 };
    VkBufferUsageFlags usage{ 0 };

    std::set<BufferViewWrapper*> buffer_views;

    DeviceWrapper*             bind_device{ nullptr };
    const void*                bind_pnext{ nullptr };
    std::unique_ptr<uint8_t[]> bind_pnext_memory;

    bool                                       is_sparse_buffer{ false };
    std::map<VkDeviceSize, VkSparseMemoryBind> sparse_memory_bind_map;
    VkQueue                                    sparse_bind_queue;

    format::HandleId bind_memory_id{ format::kNullHandleId };
    VkDeviceSize     bind_offset{ 0 };
    uint32_t         queue_family_index{ 0 };
    VkDeviceSize     created_size{ 0 };
};

struct ImageViewWrapper;
struct ImageWrapper : public HandleWrapper<VkImage>, AssetWrapperBase
{
    VkImageType           image_type{ VK_IMAGE_TYPE_2D };
    VkFormat              format{ VK_FORMAT_UNDEFINED };
    bool                  external_format{ false };
    bool                  external_memory_android{ false };
    VkExtent3D            extent{ 0, 0, 0 };
    uint32_t              mip_levels{ 0 };
    uint32_t              array_layers{ 0 };
    VkSampleCountFlagBits samples{};
    VkImageTiling         tiling{};
    VkImageLayout         current_layout{ VK_IMAGE_LAYOUT_UNDEFINED };
    bool                  is_swapchain_image{ false };

    std::set<ImageViewWrapper*> image_views;

    DeviceWrapper*             bind_device{ nullptr };
    const void*                bind_pnext{ nullptr };
    std::unique_ptr<uint8_t[]> bind_pnext_memory;

    bool                                                is_sparse_image{ false };
    std::map<VkDeviceSize, VkSparseMemoryBind>          sparse_opaque_memory_bind_map;
    graphics::VulkanSubresourceSparseImageMemoryBindMap sparse_subresource_memory_bind_map;
    VkQueue                                             sparse_bind_queue;

    format::HandleId         bind_memory_id{ format::kNullHandleId };
    VkDeviceSize             bind_offset{ 0 };
    uint32_t                 queue_family_index{ 0 };
    std::set<VkSwapchainKHR> parent_swapchains;
};

struct SamplerWrapper : public HandleWrapper<VkSampler>
{
    std::unordered_set<DescriptorSetWrapper*> descriptor_sets_bound_to;
};

struct DeviceMemoryWrapper : public HandleWrapper<VkDeviceMemory>
{
    uint32_t     memory_type_index{ std::numeric_limits<uint32_t>::max() };
    VkDeviceSize allocation_size{ 0 };
    // This is the device which was used to allocate the memory.
    // Spec states if the memory can be mapped, the mapping device must be this device.
    // The device wrapper will be initialized when allocating the memory. Some handling
    // like StateTracker::TrackCommandBuffersSubmision may use it before mapping
    // the memory.
    DeviceWrapper*   parent_device{ nullptr };
    const void*      mapped_data{ nullptr };
    VkDeviceSize     mapped_offset{ 0 };
    VkDeviceSize     mapped_size{ 0 };
    VkMemoryMapFlags mapped_flags{ 0 };
    void*            external_allocation{ nullptr };
    uintptr_t        shadow_allocation{ util::PageGuardManager::kNullShadowHandle };
    AHardwareBuffer* hardware_buffer{ nullptr };
    format::HandleId hardware_buffer_memory_id{ format::kNullHandleId };
    int              imported_fd{ -1 };

    // State tracking info for memory with device addresses.
    format::HandleId device_id{ format::kNullHandleId };
    VkDeviceAddress  address{ 0 };

    std::unordered_set<AssetWrapperBase*> bound_assets;
    std::mutex                            asset_map_lock;
};

struct BufferViewWrapper : public HandleWrapper<VkBufferView>
{
    format::HandleId buffer_id{ format::kNullHandleId };
    BufferWrapper*   buffer{ nullptr };

    std::unordered_set<DescriptorSetWrapper*> descriptor_sets_bound_to;
};

struct ImageViewWrapper : public HandleWrapper<VkImageView>
{
    format::HandleId image_id{ format::kNullHandleId };
    ImageWrapper*    image{ nullptr };

    std::unordered_set<DescriptorSetWrapper*> descriptor_sets_bound_to;
};

struct FramebufferWrapper : public HandleWrapper<VkFramebuffer>
{
    // Creation info for objects used to create the framebuffer, which may have been destroyed after creation.
    format::HandleId                    render_pass_id{ format::kNullHandleId };
    format::ApiCallId                   render_pass_create_call_id{ format::ApiCallId::ApiCall_Unknown };
    vulkan_state_info::CreateParameters render_pass_create_parameters;

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
    bool            signaled{ false };
    VkSemaphoreType type{ VK_SEMAPHORE_TYPE_BINARY_KHR };
    DeviceWrapper*  device{ nullptr };
};

struct QueryPoolWrapper : public HandleWrapper<VkQueryPool>
{
    DeviceWrapper*                            device{ nullptr };
    VkQueryType                               query_type{};
    uint32_t                                  query_count{ 0 };
    std::vector<vulkan_state_info::QueryInfo> pending_queries;
};

struct RenderPassWrapper : public HandleWrapper<VkRenderPass>
{
    struct
    {
        // Final image attachment layouts to be used for processing image layout transitions after calls to
        // vkCmdEndRenderPass.
        std::vector<VkImageLayout>       attachment_final_layouts;
        std::vector<VkAttachmentStoreOp> store_op;
        std::vector<VkAttachmentStoreOp> stencil_store_op;
    } attachment_info;
};

struct DescriptorUpdateTemplateWrapper : public HandleWrapper<VkDescriptorUpdateTemplate>
{
    // Members for general wrapper support.
    UpdateTemplateInfo info;
};

struct DescriptorSetLayoutWrapper : public HandleWrapper<VkDescriptorSetLayout>
{
    // Members for trimming state tracking.
    std::vector<vulkan_state_info::DescriptorBindingInfo> binding_info;
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
    std::unordered_map<uint32_t, vulkan_state_info::DescriptorInfo> bindings;

    // Creation info for objects used to allocate the descriptor set, which may have been destroyed after descriptor set
    // allocation.
    vulkan_state_info::CreateDependencyInfo set_layout_dependency;

    bool dirty{ true };
};

struct DescriptorPoolWrapper : public HandleWrapper<VkDescriptorPool>
{
    // Members for general wrapper support.
    // Track descriptor set info, which must be destroyed on descriptor pool reset.
    std::unordered_map<format::HandleId, DescriptorSetWrapper*> child_sets;
};

struct PipelineLayoutWrapper : public HandleWrapper<VkPipelineLayout>
{
    // Creation info for objects used to create the pipeline layout, which may have been destroyed after pipeline layout
    // creation.
    std::shared_ptr<vulkan_state_info::PipelineLayoutDependencies> layout_dependencies;
};

struct PipelineWrapper : public HandleWrapper<VkPipeline>
{
    // Creation info for objects used to create the pipeline, which may have been destroyed after pipeline creation.
    std::vector<vulkan_state_info::CreateDependencyInfo> shader_module_dependencies;
    vulkan_state_info::CreateDependencyInfo              render_pass_dependency;
    vulkan_state_info::CreateDependencyInfo              layout_dependency;
    std::shared_ptr<vulkan_state_info::PipelineLayoutDependencies>
        layout_dependencies; // Shared with PipelineLayoutWrapper

    // Ray tracing pipeline's shader group handle data
    format::HandleId                        device_id{ format::kNullHandleId };
    std::vector<uint8_t>                    shader_group_handle_data;
    uint32_t                                num_shader_group_handles{ 0 };
    vulkan_state_info::CreateDependencyInfo deferred_operation;

    // TODO: Base pipeline
    // TODO: Pipeline cache
};

struct AccelerationStructureKHRWrapper;
struct CommandPoolWrapper;
struct CommandBufferWrapper : public HandleWrapper<VkCommandBuffer>
{
    graphics::VulkanDeviceTable* layer_table_ref{ nullptr };

    // Members for general wrapper support.
    // Pool from which command buffer was allocated. The command buffer must be removed from the pool's allocation list
    // when destroyed.
    CommandPoolWrapper* parent_pool{ nullptr };

    // Members for trimming state tracking.
    VkCommandBufferLevel       level{ VK_COMMAND_BUFFER_LEVEL_PRIMARY };
    util::MemoryOutputStream   command_data;
    std::set<format::HandleId> command_handles[vulkan_state_info::CommandHandleType::NumHandleTypes];

    enum CommandBufferState
    {
        kInitial = 0,
        kRecording,
        kExecutable,
        kInvalid
    };

    CommandBufferState state{ kInitial };

    // This is set to true when a command buffer is began with VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT
    // Used to track command buffer life cycle
    bool one_time_submission{ false };

    // Image layout info tracked for image barriers recorded to the command buffer. To be updated on calls to
    // vkCmdPipelineBarrier and vkCmdEndRenderPass and applied to the image wrapper on calls to vkQueueSubmit. To be
    // transferred from secondary command buffers to primary command buffers on calls to vkCmdExecuteCommands.
    std::unordered_map<ImageWrapper*, VkImageLayout> pending_layouts;

    // Active query info for queries that have been recorded to this command buffer, which will be transfered to the
    // QueryPoolWrapper as pending queries when the command buffer is submitted to a queue.
    std::unordered_map<QueryPoolWrapper*, std::unordered_map<uint32_t, vulkan_state_info::QueryInfo>> recorded_queries;

    // Render pass object tracking for processing image layout transitions. Render pass and framebuffer values
    // for the active render pass instance will be set on calls to vkCmdBeginRenderPass and will be used to update the
    // pending image layout on calls to vkCmdEndRenderPass.
    RenderPassWrapper*  active_render_pass{ nullptr };
    FramebufferWrapper* render_pass_framebuffer{ nullptr };

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

    // TODO: Fabian, check wtf
    std::vector<std::pair<AccelerationStructureKHRWrapper*, tlas_build_info>> tlas_build_info_map;

    const PipelineWrapper* bound_pipelines[vulkan_state_info::PipelineBindPoints::kBindPoint_count]{ nullptr };

    std::unordered_map<uint32_t, const DescriptorSetWrapper*>
        bound_descriptors[vulkan_state_info::PipelineBindPoints::kBindPoint_count];

    std::unordered_set<AssetWrapperBase*> modified_assets;
    std::vector<CommandBufferWrapper*>    secondaries;
};

struct DeferredOperationKHRWrapper : public HandleWrapper<VkDeferredOperationKHR>
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

struct CommandPoolWrapper : public HandleWrapper<VkCommandPool>
{
    // Members for general wrapper support.
    // Track command buffer info, which must be destroyed on command pool reset.
    std::unordered_map<format::HandleId, CommandBufferWrapper*> child_buffers;

    // Members for trimming state tracking.
    uint32_t queue_family_index{ 0 };

    DeviceWrapper* device{ nullptr };
    bool           trim_command_pool{ false };
};

// For vkGetPhysicalDeviceSurfaceCapabilitiesKHR
struct SurfaceCapabilities
{
    VkSurfaceKHR             surface;
    VkSurfaceCapabilitiesKHR surface_capabilities;
};

// For vkGetPhysicalDeviceSurfaceCapabilities2KHR
struct SurfaceCapabilities2
{
    VkPhysicalDeviceSurfaceInfo2KHR surface_info;
    std::unique_ptr<uint8_t[]>      surface_info_pnext_memory;

    VkSurfaceCapabilities2KHR  surface_capabilities;
    std::unique_ptr<uint8_t[]> surface_capabilities_pnext_memory;
};

// For vkGetPhysicalDeviceSurfaceFormatsKHR
struct SurfaceFormats
{
    VkSurfaceKHR                    surface{ VK_NULL_HANDLE };
    std::vector<VkSurfaceFormatKHR> surface_formats;
};

// For vkGetPhysicalDeviceSurfaceFormats2KHR
struct SurfaceFormats2
{
    VkPhysicalDeviceSurfaceInfo2KHR surface_info;
    std::unique_ptr<uint8_t[]>      surface_info_pnext_memory;

    VkSurfaceFormat2KHR*       surface_formats;
    uint32_t                   surface_format_count;
    std::unique_ptr<uint8_t[]> surface_formats_memory;
};

// For vkGetPhysicalDeviceSurfacePresentModesKHR
struct SurfacePresentModes
{
    std::vector<VkPresentModeKHR> present_modes;
    const void*                   surface_info_pnext{ nullptr };
    std::unique_ptr<uint8_t[]>    surface_info_pnext_memory;
};

// For vkGetDeviceGroupSurfacePresentModesKHR
struct GroupSurfacePresentModes
{
    VkDeviceGroupPresentModeFlagsKHR present_modes{ 0 };
    const void*                      surface_info_pnext{ nullptr };
    std::unique_ptr<uint8_t[]>       surface_info_pnext_memory;
};

struct SurfaceKHRWrapper : public HandleWrapper<VkSurfaceKHR>
{
    // Track results from calls to vkGetPhysicalDeviceSurfaceSupportKHR to write to the state snapshot after surface
    // creation. The call is only written to the state snapshot if it was previously called by the application.
    // Keys are the VkPhysicalDevice handle ID.
    std::unordered_map<format::HandleId, std::unordered_map<uint32_t, VkBool32>>                  surface_support;
    std::unordered_map<format::HandleId, std::variant<SurfaceCapabilities, SurfaceCapabilities2>> surface_capabilities;
    std::unordered_map<format::HandleId, std::variant<SurfaceFormats, SurfaceFormats2>>           surface_formats;
    std::unordered_map<format::HandleId, SurfacePresentModes>                                     surface_present_modes;

    // Keys are the VkDevice handle ID.
    std::unordered_map<format::HandleId, GroupSurfacePresentModes> group_surface_present_modes;
};

struct SwapchainKHRWrapper : public HandleWrapper<VkSwapchainKHR>
{
    // Members for general wrapper support.
    std::vector<ImageWrapper*> child_images;
    bool                       retired{ false };

    // Members for trimming state tracking.
    DeviceWrapper*                                    device{ nullptr };
    SurfaceKHRWrapper*                                surface{ nullptr };
    uint32_t                                          queue_family_index{ 0 };
    VkFormat                                          format{ VK_FORMAT_UNDEFINED };
    VkExtent3D                                        extent{ 0, 0, 0 };
    VkSurfaceTransformFlagBitsKHR                     pre_transform{ VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR };
    uint32_t                                          array_layers{ 0 };
    uint32_t                                          last_presented_image{ std::numeric_limits<uint32_t>::max() };
    std::vector<vulkan_state_info::ImageAcquiredInfo> image_acquired_info;
    bool                                              acquire_full_screen_exclusive_mode{ false };
    bool                                              release_full_screen_exclusive_mode{ false };
    bool                                              using_local_dimming_AMD{ false };
    VkBool32                                          local_dimming_enable_AMD{ false };

    // This's for checking if WaitForPresent should or shouldn't be written. Its QueuePresent could be not written since
    // it's before trim frame range. In this case, skip writing the WaitForPresent.
    std::unordered_set<graphics::PresentId> record_queue_present_ids_not_written;
};

struct AccelerationStructureKHRWrapper : public HandleWrapper<VkAccelerationStructureKHR>
{
    // State tracking info for buffers with device addresses.
    DeviceWrapper*  device{ nullptr };
    VkDeviceAddress address{ 0 };

    // List of BLASes this AS references. Used only while tracking.
    std::vector<AccelerationStructureKHRWrapper*> blas;

    VkAccelerationStructureTypeKHR type;
    // Only used when tracking

    struct ASInputBuffer
    {
        // Required data to correctly create a buffer
        VkBuffer           handle{ VK_NULL_HANDLE };
        format::HandleId   handle_id{ format::kNullHandleId };
        DeviceWrapper*     bind_device{ nullptr };
        uint32_t           queue_family_index{ 0 };
        VkDeviceSize       created_size{ 0 };
        VkBufferUsageFlags usage{ 0 };

        bool destroyed{ false };

        VkDeviceAddress capture_address{ 0 };
        VkDeviceAddress actual_address{ 0 };

        std::vector<uint8_t> bytes;

        VkMemoryRequirements memory_requirements{};
        format::HandleId     bind_memory{};
        VkDeviceMemory       bind_memory_handle{ VK_NULL_HANDLE };
    };

    struct AccelerationStructureKHRBuildCommandData
    {
        VkAccelerationStructureBuildGeometryInfoKHR           geometry_info;
        std::unique_ptr<uint8_t[]>                            geometry_info_memory;
        std::vector<VkAccelerationStructureBuildRangeInfoKHR> build_range_infos;
        std::unordered_map<format::HandleId, ASInputBuffer>   input_buffers;
    };
    std::optional<AccelerationStructureKHRBuildCommandData> latest_build_command_{ std::nullopt };

    struct AccelerationStructureCopyCommandData
    {
        format::HandleId                   device;
        VkCopyAccelerationStructureInfoKHR info;
    };
    std::optional<AccelerationStructureCopyCommandData> latest_copy_command_{ std::nullopt };

    struct AccelerationStructureWritePropertiesCommandData
    {
        format::HandleId device;
        VkQueryType      query_type;
    };
    std::optional<AccelerationStructureWritePropertiesCommandData> latest_write_properties_command_{ std::nullopt };

    std::unordered_set<DescriptorSetWrapper*> descriptor_sets_bound_to;
};

struct AccelerationStructureNVWrapper : public HandleWrapper<VkAccelerationStructureNV>
{
    std::unordered_set<DescriptorSetWrapper*> descriptor_sets_bound_to;

    // TODO: Determine what additional state tracking is needed.
};

struct PrivateDataSlotWrapper : public HandleWrapper<VkPrivateDataSlot>
{
    DeviceWrapper* device{ nullptr };
    VkObjectType   object_type{ VK_OBJECT_TYPE_UNKNOWN };
    uint64_t       object_handle{ 0 };
    uint64_t       data{ 0 };
};

struct PipelineCacheWrapper : public HandleWrapper<VkPipelineCache>
{
    DeviceWrapper*            device{ nullptr };
    VkPipelineCacheCreateInfo create_info;
    std::vector<uint8_t>      cache_data;
};

// Handle alias types for extension handle types that have been promoted to core types.
typedef SamplerYcbcrConversionWrapper   SamplerYcbcrConversionKHRWrapper;
typedef DescriptorUpdateTemplateWrapper DescriptorUpdateTemplateKHRWrapper;
typedef PrivateDataSlotWrapper          PrivateDataSlotEXTWrapper;

GFXRECON_END_NAMESPACE(vulkan_wrappers)
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_HANDLE_WRAPPERS_H
