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

#ifndef GFXRECON_DECODE_VULKAN_OBJECT_INFO_H
#define GFXRECON_DECODE_VULKAN_OBJECT_INFO_H

#include "decode/vulkan_resource_allocator.h"
#include "decode/vulkan_resource_initializer.h"
#include "decode/window.h"
#include "format/format.h"
#include "generated/generated_vulkan_dispatch_table.h"
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
    kPhysicalDeviceArrayGetPhysicalDeviceToolPropertiesEXT                              = 15,
    // Aliases for extensions functions that were promoted to core.
    kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2KHR =
        kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2,
    kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2KHR =
        kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2
};

enum DeviceArrayIndices : uint32_t
{
    kDeviceArrayGetImageSparseMemoryRequirements2               = 0,
    kDeviceArrayGetPipelineExecutablePropertiesKHR              = 1,
    kDeviceArrayGetPipelineExecutableStatisticsKHR              = 2,
    kDeviceArrayGetPipelineExecutableInternalRepresentationsKHR = 3,
    // Aliases for extensions functions that were promoted to core.
    kDeviceArrayGetImageSparseMemoryRequirements2KHR = kDeviceArrayGetImageSparseMemoryRequirements2
};

enum QueueArrayIndices : uint32_t
{
    kQueueArrayGetQueueCheckpointDataNV = 0
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
};

//
// Declarations for Vulkan objects without additional replay state info.
//

typedef VulkanObjectInfo<VkSemaphore>                     SemaphoreInfo;
typedef VulkanObjectInfo<VkCommandBuffer>                 CommandBufferInfo;
typedef VulkanObjectInfo<VkFence>                         FenceInfo;
typedef VulkanObjectInfo<VkEvent>                         EventInfo;
typedef VulkanObjectInfo<VkQueryPool>                     QueryPoolInfo;
typedef VulkanObjectInfo<VkBufferView>                    BufferViewInfo;
typedef VulkanObjectInfo<VkImageView>                     ImageViewInfo;
typedef VulkanObjectInfo<VkShaderModule>                  ShaderModuleInfo;
typedef VulkanObjectInfo<VkPipelineLayout>                PipelineLayoutInfo;
typedef VulkanObjectInfo<VkRenderPass>                    RenderPassInfo;
typedef VulkanObjectInfo<VkDescriptorSetLayout>           DescriptorSetLayoutInfo;
typedef VulkanObjectInfo<VkSampler>                       SamplerInfo;
typedef VulkanObjectInfo<VkDescriptorPool>                DescriptorPoolInfo;
typedef VulkanObjectInfo<VkDescriptorSet>                 DescriptorSetInfo;
typedef VulkanObjectInfo<VkFramebuffer>                   FramebufferInfo;
typedef VulkanObjectInfo<VkCommandPool>                   CommandPoolInfo;
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
    uint32_t                             api_version{ 0 };
    std::unordered_map<uint32_t, size_t> array_counts;

    // Capture and replay devices sorted in the order that they were originally retrieved from
    // vkEnumeratePhysicalDevices.
    std::vector<format::HandleId> capture_devices;
    std::vector<VkPhysicalDevice> replay_devices;

    std::unordered_map<VkPhysicalDevice, ReplayDeviceInfo> replay_device_info;

    // Ensure swapchains and surfaces are cleaned up on exit to avoid issues encountered when calling xcb_disconnect
    // with active xcb surfaces.
    std::unordered_set<VkSurfaceKHR> active_surfaces;
};

struct PhysicalDeviceInfo : public VulkanObjectInfo<VkPhysicalDevice>
{
    VkInstance                           parent{ VK_NULL_HANDLE };
    format::HandleId                     parent_id{ format::kNullHandleId };
    uint32_t                             parent_api_version{ 0 };
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

    // The following values are only used when loading the initial state for trimmed files.
    std::vector<std::string>                   extensions;
    std::unique_ptr<VulkanResourceInitializer> resource_initializer;

    // Ensure swapchains and surfaces are cleaned up on exit to avoid issues encountered when calling xcb_disconnect
    // with active xcb surfaces.
    std::unordered_set<VkSwapchainKHR> active_swapchains;
};

struct QueueInfo : public VulkanObjectInfo<VkQueue>
{
    std::unordered_map<uint32_t, size_t> array_counts;
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
    VkDeviceMemory                      memory{ VK_NULL_HANDLE };
    VulkanResourceAllocator::MemoryData memory_allocator_data{ 0 };
    VkMemoryPropertyFlags               memory_property_flags{ 0 };
    VkDeviceSize                        bind_offset{ 0 };
    VkBufferUsageFlags                  usage{ 0 };
    uint32_t                            queue_family_index{ 0 };
};

struct ImageInfo : public VulkanObjectInfo<VkImage>
{
    std::unordered_map<uint32_t, size_t> array_counts;

    // The following values are only used for memory portability.
    VulkanResourceAllocator::ResourceData allocator_data{ 0 };

    // The following values are only used when loading the initial state for trimmed files.
    VkDeviceMemory                      memory{ VK_NULL_HANDLE };
    VulkanResourceAllocator::MemoryData memory_allocator_data{ 0 };
    VkMemoryPropertyFlags               memory_property_flags{ 0 };
    VkDeviceSize                        bind_offset{ 0 };
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
};

struct SwapchainKHRInfo : public VulkanObjectInfo<VkSwapchainKHR>
{
    VkSurfaceKHR                         surface{ VK_NULL_HANDLE };
    std::unordered_map<uint32_t, size_t> array_counts;

    // The following values are only used when loading the initial state for trimmed files.
    uint32_t queue_family_index{ 0 };
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
