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

#include "format/format.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

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

// clang-format off
struct InstanceInfo                      : public VulkanObjectInfo<VkInstance> {};
struct PhysicalDeviceInfo                : public VulkanObjectInfo<VkPhysicalDevice> {};
struct DeviceInfo                        : public VulkanObjectInfo<VkDevice> {};
struct QueueInfo                         : public VulkanObjectInfo<VkQueue> {};
struct SemaphoreInfo                     : public VulkanObjectInfo<VkSemaphore> {};
struct CommandBufferInfo                 : public VulkanObjectInfo<VkCommandBuffer> {};
struct FenceInfo                         : public VulkanObjectInfo<VkFence> {};
struct DeviceMemoryInfo                  : public VulkanObjectInfo<VkDeviceMemory> {};
struct BufferInfo                        : public VulkanObjectInfo<VkBuffer> {};
struct ImageInfo                         : public VulkanObjectInfo<VkImage> {};
struct EventInfo                         : public VulkanObjectInfo<VkEvent> {};
struct QueryPoolInfo                     : public VulkanObjectInfo<VkQueryPool> {};
struct BufferViewInfo                    : public VulkanObjectInfo<VkBufferView> {};
struct ImageViewInfo                     : public VulkanObjectInfo<VkImageView> {};
struct ShaderModuleInfo                  : public VulkanObjectInfo<VkShaderModule> {};
struct PipelineCacheInfo                 : public VulkanObjectInfo<VkPipelineCache> {};
struct PipelineLayoutInfo                : public VulkanObjectInfo<VkPipelineLayout> {};
struct RenderPassInfo                    : public VulkanObjectInfo<VkRenderPass> {};
struct PipelineInfo                      : public VulkanObjectInfo<VkPipeline> {};
struct DescriptorSetLayoutInfo           : public VulkanObjectInfo<VkDescriptorSetLayout> {};
struct SamplerInfo                       : public VulkanObjectInfo<VkSampler> {};
struct DescriptorPoolInfo                : public VulkanObjectInfo<VkDescriptorPool> {};
struct DescriptorSetInfo                 : public VulkanObjectInfo<VkDescriptorSet> {};
struct FramebufferInfo                   : public VulkanObjectInfo<VkFramebuffer> {};
struct CommandPoolInfo                   : public VulkanObjectInfo<VkCommandPool> {};
struct SamplerYcbcrConversionInfo        : public VulkanObjectInfo<VkSamplerYcbcrConversion> {};
struct DescriptorUpdateTemplateInfo      : public VulkanObjectInfo<VkDescriptorUpdateTemplate> {};
struct SurfaceKHRInfo                    : public VulkanObjectInfo<VkSurfaceKHR> {};
struct SwapchainKHRInfo                  : public VulkanObjectInfo<VkSwapchainKHR> {};
struct DisplayKHRInfo                    : public VulkanObjectInfo<VkDisplayKHR> {};
struct DisplayModeKHRInfo                : public VulkanObjectInfo<VkDisplayModeKHR> {};
struct DebugReportCallbackEXTInfo        : public VulkanObjectInfo<VkDebugReportCallbackEXT> {};
struct ObjectTableNVXInfo                : public VulkanObjectInfo<VkObjectTableNVX> {};
struct IndirectCommandsLayoutNVXInfo     : public VulkanObjectInfo<VkIndirectCommandsLayoutNVX> {};
struct DebugUtilsMessengerEXTInfo        : public VulkanObjectInfo<VkDebugUtilsMessengerEXT> {};
struct ValidationCacheEXTInfo            : public VulkanObjectInfo<VkValidationCacheEXT> {};
struct AccelerationStructureNVInfo       : public VulkanObjectInfo<VkAccelerationStructureNV> {};
struct PerformanceConfigurationINTELInfo : public VulkanObjectInfo<VkPerformanceConfigurationINTEL> {};
// clang-format on

//
// Declarations for Vulkan objects with additional replay state info.
//

// Handle alias types for extension handle types that have been promoted to core types.
typedef SamplerYcbcrConversionInfo   SamplerYcbcrConversionKHRInfo;
typedef DescriptorUpdateTemplateInfo DescriptorUpdateTemplateKHRInfo;

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_OBJECT_INFO_H
