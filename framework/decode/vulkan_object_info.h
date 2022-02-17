/*
** Copyright (c) 2019-2020 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_OBJECT_INFO_H
#define GFXRECON_DECODE_VULKAN_OBJECT_INFO_H

#include "decode/vulkan_resource_allocator.h"
#include "decode/vulkan_resource_initializer.h"
#include "decode/window.h"
#include "format/format.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "graphics/vulkan_device_util.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

//
// Enumerations defining index values for tables to track array counts reported by Vulkan API calls with variable length
// array parameters.
//
enum InstanceArrayIndices : uint32_t
{
    kInstanceArrayEnumeratePhysicalDevices      = 0,
    kInstanceArrayEnumeratePhysicalDeviceGroups = 1,
    // Aliases for extensions functions that were promoted to core.
    kInstanceArrayEnumeratePhysicalDeviceGroupsKHR = kInstanceArrayEnumeratePhysicalDeviceGroups
};

enum PhysicalDeviceArrayIndices : uint32_t
{
    kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties                          = 0,
    kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties                    = 1,
    kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2                         = 2,
    kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2                   = 3,
    kPhysicalDeviceArrayGetPhysicalDeviceDisplayPropertiesKHR                           = 4,
    kPhysicalDeviceArrayGetPhysicalDeviceDisplayPlanePropertiesKHR                      = 5,
    kPhysicalDeviceArrayGetDisplayPlaneSupportedDisplaysKHR                             = 6,
    kPhysicalDeviceArrayGetPhysicalDeviceSurfaceFormats2KHR                             = 7,
    kPhysicalDeviceArrayGetPhysicalDeviceDisplayProperties2KHR                          = 8,
    kPhysicalDeviceArrayGetPhysicalDeviceDisplayPlaneProperties2KHR                     = 9,
    kPhysicalDeviceArrayGetPhysicalDeviceCalibrateableTimeDomainsEXT                    = 10,
    kPhysicalDeviceArrayGetPhysicalDeviceCooperativeMatrixPropertiesNV                  = 11,
    kPhysicalDeviceArrayGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV = 12,
    kPhysicalDeviceArrayGetPhysicalDeviceSurfacePresentModes2EXT                        = 13,
    kPhysicalDeviceArrayEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR   = 14,
    kPhysicalDeviceArrayGetPhysicalDeviceToolProperties                                 = 15,
    kPhysicalDeviceArrayGetPhysicalDeviceFragmentShadingRatesKHR                        = 16,
    // Aliases for extensions functions that were promoted to core.
    kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2KHR =
        kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2,
    kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2KHR =
        kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2,
    kPhysicalDeviceArrayGetPhysicalDeviceToolPropertiesEXT = kPhysicalDeviceArrayGetPhysicalDeviceToolProperties
};

enum DeviceArrayIndices : uint32_t
{
    kDeviceArrayGetImageSparseMemoryRequirements2               = 0,
    kDeviceArrayGetPipelineExecutablePropertiesKHR              = 1,
    kDeviceArrayGetPipelineExecutableStatisticsKHR              = 2,
    kDeviceArrayGetPipelineExecutableInternalRepresentationsKHR = 3,
    kDeviceArrayGetDeviceImageSparseMemoryRequirements          = 4,
    // Aliases for extensions functions that were promoted to core.
    kDeviceArrayGetImageSparseMemoryRequirements2KHR      = kDeviceArrayGetImageSparseMemoryRequirements2,
    kDeviceArrayGetDeviceImageSparseMemoryRequirementsKHR = kDeviceArrayGetDeviceImageSparseMemoryRequirements
};

enum QueueArrayIndices : uint32_t
{
    kQueueArrayGetQueueCheckpointDataNV  = 0,
    kQueueArrayGetQueueCheckpointData2NV = 1
};

enum ImageArrayIndices : uint32_t
{
    kImageArrayGetImageSparseMemoryRequirements = 0
};

enum PipelineCacheArrayIndices : uint32_t
{
    kPipelineCacheArrayGetPipelineCacheData = 0
};

enum PipelineArrayIndices : uint32_t
{
    kPipelineArrayGetShaderInfoAMD = 0
};

enum DisplayKHRArrayIndices : uint32_t
{
    kDisplayKHRArrayGetDisplayModePropertiesKHR  = 0,
    kDisplayKHRArrayGetDisplayModeProperties2KHR = 1
};

enum SurfaceKHRArrayIndices : uint32_t
{
    kSurfaceKHRArrayGetPhysicalDeviceSurfaceFormatsKHR      = 0,
    kSurfaceKHRArrayGetPhysicalDeviceSurfacePresentModesKHR = 1,
    kSurfaceKHRArrayGetPhysicalDevicePresentRectanglesKHR   = 2
};

enum SwapchainKHRArrayIndices : uint32_t
{
    kSwapchainKHRArrayGetSwapchainImagesKHR           = 0,
    kSwapchainKHRArrayGetPastPresentationTimingGOOGLE = 1
};

enum ValidationCacheEXTArrayIndices : uint32_t
{
    kValidationCacheEXTArrayGetValidationCacheDataEXT = 0
};

//
// Structures for storing Vulkan object info.
//

struct ReplayDeviceInfo
{
    std::unique_ptr<VkPhysicalDeviceProperties>       properties;
    std::unique_ptr<VkPhysicalDeviceMemoryProperties> memory_properties;
};

template <typename T>
struct VulkanObjectInfo
{
    typedef T HandleType;

    // Standard info stored for all Vulkan objects.
    HandleType       handle{ VK_NULL_HANDLE };            // Handle created for the object during replay.
    format::HandleId capture_id{ format::kNullHandleId }; // ID assigned to the object at capture.
    format::HandleId parent_id{ format::kNullHandleId };  // ID of the object's parent instance/device object.
};

// Info for a pool object which other objects will be allocated from.
template <typename T>
struct VulkanPoolInfo : public VulkanObjectInfo<T>
{
    std::unordered_set<format::HandleId> child_ids; // IDs of objects allocated from the pool.
};

// Info for objects that are allocated from pools.
template <typename T>
struct VulkanPoolObjectInfo : public VulkanObjectInfo<T>
{
    format::HandleId pool_id{ format::kNullHandleId }; // ID of the pool that the object was allocated from.
};

//
// Declarations for Vulkan objects without additional replay state info.
//

typedef VulkanPoolObjectInfo<VkCommandBuffer>             CommandBufferInfo;
typedef VulkanObjectInfo<VkEvent>                         EventInfo;
typedef VulkanObjectInfo<VkQueryPool>                     QueryPoolInfo;
typedef VulkanObjectInfo<VkBufferView>                    BufferViewInfo;
typedef VulkanObjectInfo<VkImageView>                     ImageViewInfo;
typedef VulkanObjectInfo<VkShaderModule>                  ShaderModuleInfo;
typedef VulkanObjectInfo<VkPipelineLayout>                PipelineLayoutInfo;
typedef VulkanObjectInfo<VkPrivateDataSlot>               PrivateDataSlotInfo;
typedef VulkanObjectInfo<VkRenderPass>                    RenderPassInfo;
typedef VulkanObjectInfo<VkDescriptorSetLayout>           DescriptorSetLayoutInfo;
typedef VulkanObjectInfo<VkSampler>                       SamplerInfo;
typedef VulkanPoolObjectInfo<VkDescriptorSet>             DescriptorSetInfo;
typedef VulkanObjectInfo<VkFramebuffer>                   FramebufferInfo;
typedef VulkanPoolInfo<VkCommandPool>                     CommandPoolInfo;
typedef VulkanObjectInfo<VkSamplerYcbcrConversion>        SamplerYcbcrConversionInfo;
typedef VulkanObjectInfo<VkDisplayModeKHR>                DisplayModeKHRInfo;
typedef VulkanObjectInfo<VkDebugReportCallbackEXT>        DebugReportCallbackEXTInfo;
typedef VulkanObjectInfo<VkIndirectCommandsLayoutNV>      IndirectCommandsLayoutNVInfo;
typedef VulkanObjectInfo<VkDebugUtilsMessengerEXT>        DebugUtilsMessengerEXTInfo;
typedef VulkanObjectInfo<VkAccelerationStructureKHR>      AccelerationStructureKHRInfo;
typedef VulkanObjectInfo<VkAccelerationStructureNV>       AccelerationStructureNVInfo;
typedef VulkanObjectInfo<VkPerformanceConfigurationINTEL> PerformanceConfigurationINTELInfo;
typedef VulkanObjectInfo<VkDeferredOperationKHR>          DeferredOperationKHRInfo;
typedef VulkanObjectInfo<VkPrivateDataSlotEXT>            PrivateDataSlotEXTInfo;

//
// Declarations for Vulkan objects with additional replay state info.
//

struct InstanceInfo : public VulkanObjectInfo<VkInstance>
{
    uint32_t                             api_version{ VK_MAKE_VERSION(1, 0, 0) };
    std::vector<std::string>             enabled_extensions;
    std::unordered_map<uint32_t, size_t> array_counts;

    // Capture and replay devices sorted in the order that they were originally retrieved from
    // vkEnumeratePhysicalDevices.
    std::vector<format::HandleId> capture_devices;
    std::vector<VkPhysicalDevice> replay_devices;

    std::unordered_map<VkPhysicalDevice, ReplayDeviceInfo> replay_device_info;
};

struct PhysicalDeviceInfo : public VulkanObjectInfo<VkPhysicalDevice>
{
    VkInstance                           parent{ VK_NULL_HANDLE };
    uint32_t                             parent_api_version{ 0 };
    std::vector<std::string>             parent_enabled_extensions;
    std::unordered_map<uint32_t, size_t> array_counts;

    // Capture device properties.
    uint32_t                         capture_api_version{ 0 };
    uint32_t                         capture_driver_version{ 0 };
    uint32_t                         capture_vendor_id{ 0 };
    uint32_t                         capture_device_id{ 0 };
    VkPhysicalDeviceType             capture_device_type{ VK_PHYSICAL_DEVICE_TYPE_OTHER };
    uint8_t                          capture_pipeline_cache_uuid[format::kUuidSize]{};
    std::string                      capture_device_name;
    VkPhysicalDeviceMemoryProperties capture_memory_properties{};

    // Closest matching replay device.
    ReplayDeviceInfo* replay_device_info{ nullptr };
};

struct DeviceInfo : public VulkanObjectInfo<VkDevice>
{
    VkPhysicalDevice                         parent{ VK_NULL_HANDLE };
    std::unique_ptr<VulkanResourceAllocator> allocator;
    std::unordered_map<uint32_t, size_t>     array_counts;

    std::unordered_map<format::HandleId, uint64_t> opaque_addresses;

    // Map pipeline ID to ray tracing shader group handle capture replay data.
    std::unordered_map<format::HandleId, const std::vector<uint8_t>> shader_group_handles;

    // The following values are only used when loading the initial state for trimmed files.
    std::vector<std::string>                   extensions;
    std::unique_ptr<VulkanResourceInitializer> resource_initializer;

    // Physical device property & feature state at device creation
    graphics::VulkanDevicePropertyFeatureInfo property_feature_info;
};

struct QueueInfo : public VulkanObjectInfo<VkQueue>
{
    std::unordered_map<uint32_t, size_t> array_counts;
};

struct SemaphoreInfo : public VulkanObjectInfo<VkSemaphore>
{
    bool is_external{ false };

    // If a null-swapchain/surface interacts with a semaphore, replay needs to shadow signal it until a future call
    // waits on it.
    bool shadow_signaled{ false };
    // Fences can be reset, semaphores can't, so replay needs to know when a semaphore will not be submitted for a wait
    // operation to prevent validation errors around queue forward progress.
    bool forward_progress{ true };
};

struct FenceInfo : public VulkanObjectInfo<VkFence>
{
    // If a null-swapchain/surface interacts with a fence, replay needs to to shadow signal it until a future call waits
    // on it.
    bool shadow_signaled{ false };
};

struct DeviceMemoryInfo : public VulkanObjectInfo<VkDeviceMemory>
{
    VulkanResourceAllocator*            allocator{ nullptr };
    VulkanResourceAllocator::MemoryData allocator_data{ 0 };
};

struct BufferInfo : public VulkanObjectInfo<VkBuffer>
{
    // The following values are only used for memory portability.
    VulkanResourceAllocator::ResourceData allocator_data{ 0 };

    // The following values are only used when loading the initial state for trimmed files.
    VkMemoryPropertyFlags memory_property_flags{ 0 };
    VkBufferUsageFlags    usage{ 0 };
    uint32_t              queue_family_index{ 0 };
};

struct ImageInfo : public VulkanObjectInfo<VkImage>
{
    std::unordered_map<uint32_t, size_t> array_counts;

    bool is_swapchain_image{ false };

    // The following values are only used for memory portability.
    VulkanResourceAllocator::ResourceData allocator_data{ 0 };

    // The following values are used when loading the initial state for trimmed files, and for null-swapchain/surface
    // creation.
    VkDeviceMemory                      memory{ VK_NULL_HANDLE };
    VulkanResourceAllocator::MemoryData memory_allocator_data{ 0 };
    VkMemoryPropertyFlags               memory_property_flags{ 0 };
    VkImageUsageFlags                   usage{ 0 };
    VkImageType                         type{};
    VkFormat                            format{};
    VkExtent3D                          extent{ 0, 0, 0 };
    VkImageTiling                       tiling{};
    VkSampleCountFlagBits               sample_count{};
    VkImageLayout                       initial_layout{};
    uint32_t                            layer_count{ 0 };
    uint32_t                            level_count{ 0 };
    uint32_t                            queue_family_index{ 0 };
};

struct PipelineCacheInfo : public VulkanObjectInfo<VkPipelineCache>
{
    std::unordered_map<uint32_t, size_t> array_counts;
};

struct PipelineInfo : public VulkanObjectInfo<VkPipeline>
{
    std::unordered_map<uint32_t, size_t> array_counts;
};

struct DescriptorPoolInfo : public VulkanPoolInfo<VkDescriptorPool>
{
    VkDescriptorPoolCreateFlags       flags{};
    uint32_t                          max_sets{ 0 };
    uint32_t                          max_inline_uniform_block_bindings{ 0 }; // For VK_EXT_inline_uniform_block.
    std::vector<VkDescriptorPoolSize> pool_sizes;
    std::vector<VkDescriptorPool>     retired_pools;
};

struct DescriptorUpdateTemplateInfo : public VulkanObjectInfo<VkDescriptorUpdateTemplate>
{
    std::vector<VkDescriptorType> descriptor_image_types;
};

struct DisplayKHRInfo : public VulkanObjectInfo<VkDisplayKHR>
{
    std::unordered_map<uint32_t, size_t> array_counts;
};

struct SurfaceKHRInfo : public VulkanObjectInfo<VkSurfaceKHR>
{
    Window*                              window{ nullptr };
    std::unordered_map<uint32_t, size_t> array_counts;

    std::unordered_map<VkPhysicalDevice, VkSurfaceCapabilitiesKHR> surface_capabilities;
};

struct SwapchainKHRInfo : public VulkanObjectInfo<VkSwapchainKHR>
{
    VkSurfaceKHR                         surface{ VK_NULL_HANDLE };
    format::HandleId                     surface_id{ format::kNullHandleId };
    DeviceInfo*                          device_info{ nullptr };
    uint32_t                             width{ 0 };
    uint32_t                             height{ 0 };
    VkFormat                             format{ VK_FORMAT_UNDEFINED };
    std::vector<VkImage>                 images;
    std::vector<uint32_t>                acquired_indices;
    std::unordered_map<uint32_t, size_t> array_counts;

    // The following values are only used when loading the initial state for trimmed files.
    uint32_t queue_family_index{ 0 };

    // When replay is restricted to a specific surface, a dummy swapchain is created for the omitted surfaces, requiring
    // backing images.
    std::vector<ImageInfo>    image_infos;
    VkSwapchainCreateFlagsKHR image_flags;
    VkFormat                  image_format;
    VkExtent2D                image_extent;
    uint32_t                  image_array_layers;
    VkImageUsageFlags         image_usage;
    VkSharingMode             image_sharing_mode;
};

struct ValidationCacheEXTInfo : public VulkanObjectInfo<VkValidationCacheEXT>
{
    std::unordered_map<uint32_t, size_t> array_counts;
};

//
// Handle alias types for extension handle types that have been promoted to core types.
//

typedef SamplerYcbcrConversionInfo   SamplerYcbcrConversionKHRInfo;
typedef DescriptorUpdateTemplateInfo DescriptorUpdateTemplateKHRInfo;

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_OBJECT_INFO_H
