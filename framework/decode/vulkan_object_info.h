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
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename T>
struct VulkanObjectInfo
{
    typedef T HandleType;

    // Standard info stored for all Vulkan objects.
    HandleType       handle{ VK_NULL_HANDLE }; // Handle created for the object during replay.
    format::HandleId capture_id{ 0 };          // ID assigned to the object at capture.
};

//
// Declarations for Vulkan objects without additional replay state info.
//

typedef VulkanObjectInfo<VkInstance>                      InstanceInfo;
typedef VulkanObjectInfo<VkQueue>                         QueueInfo;
typedef VulkanObjectInfo<VkSemaphore>                     SemaphoreInfo;
typedef VulkanObjectInfo<VkCommandBuffer>                 CommandBufferInfo;
typedef VulkanObjectInfo<VkFence>                         FenceInfo;
typedef VulkanObjectInfo<VkEvent>                         EventInfo;
typedef VulkanObjectInfo<VkQueryPool>                     QueryPoolInfo;
typedef VulkanObjectInfo<VkBufferView>                    BufferViewInfo;
typedef VulkanObjectInfo<VkImageView>                     ImageViewInfo;
typedef VulkanObjectInfo<VkShaderModule>                  ShaderModuleInfo;
typedef VulkanObjectInfo<VkPipelineCache>                 PipelineCacheInfo;
typedef VulkanObjectInfo<VkPipelineLayout>                PipelineLayoutInfo;
typedef VulkanObjectInfo<VkRenderPass>                    RenderPassInfo;
typedef VulkanObjectInfo<VkPipeline>                      PipelineInfo;
typedef VulkanObjectInfo<VkDescriptorSetLayout>           DescriptorSetLayoutInfo;
typedef VulkanObjectInfo<VkSampler>                       SamplerInfo;
typedef VulkanObjectInfo<VkDescriptorPool>                DescriptorPoolInfo;
typedef VulkanObjectInfo<VkDescriptorSet>                 DescriptorSetInfo;
typedef VulkanObjectInfo<VkFramebuffer>                   FramebufferInfo;
typedef VulkanObjectInfo<VkCommandPool>                   CommandPoolInfo;
typedef VulkanObjectInfo<VkSamplerYcbcrConversion>        SamplerYcbcrConversionInfo;
typedef VulkanObjectInfo<VkDisplayKHR>                    DisplayKHRInfo;
typedef VulkanObjectInfo<VkDisplayModeKHR>                DisplayModeKHRInfo;
typedef VulkanObjectInfo<VkDebugReportCallbackEXT>        DebugReportCallbackEXTInfo;
typedef VulkanObjectInfo<VkObjectTableNVX>                ObjectTableNVXInfo;
typedef VulkanObjectInfo<VkIndirectCommandsLayoutNVX>     IndirectCommandsLayoutNVXInfo;
typedef VulkanObjectInfo<VkDebugUtilsMessengerEXT>        DebugUtilsMessengerEXTInfo;
typedef VulkanObjectInfo<VkValidationCacheEXT>            ValidationCacheEXTInfo;
typedef VulkanObjectInfo<VkAccelerationStructureNV>       AccelerationStructureNVInfo;
typedef VulkanObjectInfo<VkPerformanceConfigurationINTEL> PerformanceConfigurationINTELInfo;

//
// Declarations for Vulkan objects with additional replay state info.
//

struct PhysicalDeviceInfo : public VulkanObjectInfo<VkPhysicalDevice>
{
    VkPhysicalDeviceMemoryProperties capture_memory_properties{};
    VkPhysicalDeviceMemoryProperties replay_memory_properties{};
};

struct DeviceInfo : public VulkanObjectInfo<VkDevice>
{
    VkPhysicalDevice                         parent{ VK_NULL_HANDLE };
    std::unique_ptr<VulkanResourceAllocator> allocator;
    const VkPhysicalDeviceMemoryProperties*  capture_memory_properties{ nullptr };
    const VkPhysicalDeviceMemoryProperties*  replay_memory_properties{ nullptr };

    // The following values are only used when loading the initial state for trimmed files.
    std::vector<std::string>                   extensions;
    std::unique_ptr<VulkanResourceInitializer> resource_initializer;
};

struct DeviceMemoryInfo : public VulkanObjectInfo<VkDeviceMemory>
{
    void* mapped_memory{ nullptr };

    // The following values are only used when loading the initial state for trimmed files.
    VkMemoryPropertyFlags property_flags{ 0 };
};

struct BufferInfo : public VulkanObjectInfo<VkBuffer>
{
    // The following values are only used when loading the initial state for trimmed files.
    VkDeviceMemory        memory{ VK_NULL_HANDLE };
    VkMemoryPropertyFlags memory_property_flags{ 0 };
    VkDeviceSize          bind_offset{ 0 };
    VkBufferUsageFlags    usage{ 0 };
    uint32_t              queue_family_index{ 0 };
};

struct ImageInfo : public VulkanObjectInfo<VkImage>
{
    // The following values are only used when loading the initial state for trimmed files.
    VkDeviceMemory        memory{ VK_NULL_HANDLE };
    VkMemoryPropertyFlags memory_property_flags{ 0 };
    VkDeviceSize          bind_offset{ 0 };
    VkImageUsageFlags     usage{ 0 };
    VkImageType           type{};
    VkFormat              format{};
    VkExtent3D            extent{ 0, 0, 0 };
    VkImageTiling         tiling{};
    VkSampleCountFlagBits sample_count{};
    VkImageLayout         initial_layout{};
    uint32_t              layer_count{ 0 };
    uint32_t              level_count{ 0 };
    uint32_t              queue_family_index{ 0 };
};

struct DescriptorUpdateTemplateInfo : public VulkanObjectInfo<VkDescriptorUpdateTemplate>
{
    std::vector<VkDescriptorType> descriptor_image_types;
};

struct SurfaceKHRInfo : public VulkanObjectInfo<VkSurfaceKHR>
{
    Window* window{ nullptr };
};

struct SwapchainKHRInfo : public VulkanObjectInfo<VkSwapchainKHR>
{
    VkSurfaceKHR surface{ VK_NULL_HANDLE };

    // The following values are only used when loading the initial state for trimmed files.
    uint32_t queue_family_index{ 0 };
};

//
// Handle alias types for extension handle types that have been promoted to core types.
//

typedef SamplerYcbcrConversionInfo   SamplerYcbcrConversionKHRInfo;
typedef DescriptorUpdateTemplateInfo DescriptorUpdateTemplateKHRInfo;

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_OBJECT_INFO_H
