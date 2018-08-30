/*
** Copyright (c) 2018 LunarG, Inc.
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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#include <cstdint>

#include "vulkan/vulkan.h"

#include "util/defines.h"
#include "format/parameter_encoder.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)

size_t encode_struct(format::ParameterEncoder* encoder, const VkApplicationInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkInstanceCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkAllocationCallbacks& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceFeatures& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkFormatProperties& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkExtent3D& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkImageFormatProperties& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceLimits& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceSparseProperties& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceProperties& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkQueueFamilyProperties& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryType& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryHeap& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceMemoryProperties& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceQueueCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkExtensionProperties& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkLayerProperties& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSubmitInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryAllocateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkMappedMemoryRange& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryRequirements& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSparseImageFormatProperties& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSparseImageMemoryRequirements& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSparseMemoryBind& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSparseBufferMemoryBindInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSparseImageOpaqueMemoryBindInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkImageSubresource& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkOffset3D& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSparseImageMemoryBind& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSparseImageMemoryBindInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkBindSparseInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkFenceCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSemaphoreCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkEventCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkQueryPoolCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkBufferCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkBufferViewCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkImageCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSubresourceLayout& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkComponentMapping& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkImageSubresourceRange& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkImageViewCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkShaderModuleCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineCacheCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSpecializationMapEntry& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSpecializationInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineShaderStageCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkVertexInputBindingDescription& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkVertexInputAttributeDescription& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineVertexInputStateCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineInputAssemblyStateCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineTessellationStateCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkViewport& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkOffset2D& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkExtent2D& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkRect2D& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineViewportStateCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineRasterizationStateCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineMultisampleStateCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkStencilOpState& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineDepthStencilStateCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineColorBlendAttachmentState& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineColorBlendStateCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineDynamicStateCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkGraphicsPipelineCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkComputePipelineCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPushConstantRange& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineLayoutCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSamplerCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorSetLayoutBinding& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorSetLayoutCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorPoolSize& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorPoolCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorSetAllocateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorImageInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorBufferInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkWriteDescriptorSet& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkCopyDescriptorSet& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkFramebufferCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkAttachmentDescription& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkAttachmentReference& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSubpassDescription& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSubpassDependency& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkRenderPassCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkCommandPoolCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkCommandBufferAllocateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkCommandBufferInheritanceInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkCommandBufferBeginInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkBufferCopy& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkImageSubresourceLayers& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkImageCopy& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkImageBlit& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkBufferImageCopy& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkClearDepthStencilValue& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkClearAttachment& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkClearRect& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkImageResolve& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryBarrier& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkBufferMemoryBarrier& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkImageMemoryBarrier& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkRenderPassBeginInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDispatchIndirectCommand& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDrawIndexedIndirectCommand& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDrawIndirectCommand& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceSubgroupProperties& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkBindBufferMemoryInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkBindImageMemoryInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDevice16BitStorageFeatures& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryDedicatedRequirements& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryDedicatedAllocateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryAllocateFlagsInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupRenderPassBeginInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupCommandBufferBeginInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupSubmitInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupBindSparseInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkBindBufferMemoryDeviceGroupInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkBindImageMemoryDeviceGroupInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceGroupProperties& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupDeviceCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkBufferMemoryRequirementsInfo2& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkImageMemoryRequirementsInfo2& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkImageSparseMemoryRequirementsInfo2& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryRequirements2& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSparseImageMemoryRequirements2& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceFeatures2& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceProperties2& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkFormatProperties2& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkImageFormatProperties2& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceImageFormatInfo2& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkQueueFamilyProperties2& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceMemoryProperties2& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSparseImageFormatProperties2& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceSparseImageFormatInfo2& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDevicePointClippingProperties& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkInputAttachmentAspectReference& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkRenderPassInputAttachmentAspectCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkImageViewUsageCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineTessellationDomainOriginStateCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkRenderPassMultiviewCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceMultiviewFeatures& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceMultiviewProperties& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceVariablePointerFeatures& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceProtectedMemoryFeatures& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceProtectedMemoryProperties& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceQueueInfo2& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkProtectedSubmitInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSamplerYcbcrConversionCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSamplerYcbcrConversionInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkBindImagePlaneMemoryInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkImagePlaneMemoryRequirementsInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceSamplerYcbcrConversionFeatures& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSamplerYcbcrConversionImageFormatProperties& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorUpdateTemplateEntry& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorUpdateTemplateCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkExternalMemoryProperties& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceExternalImageFormatInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkExternalImageFormatProperties& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceExternalBufferInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkExternalBufferProperties& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceIDProperties& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkExternalMemoryImageCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkExternalMemoryBufferCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkExportMemoryAllocateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceExternalFenceInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkExternalFenceProperties& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkExportFenceCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkExportSemaphoreCreateInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceExternalSemaphoreInfo& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkExternalSemaphoreProperties& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceMaintenance3Properties& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorSetLayoutSupport& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceShaderDrawParameterFeatures& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkSurfaceCapabilitiesKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSurfaceFormatKHR& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkSwapchainCreateInfoKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPresentInfoKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkImageSwapchainCreateInfoKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkBindImageMemorySwapchainInfoKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkAcquireNextImageInfoKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupPresentCapabilitiesKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupPresentInfoKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupSwapchainCreateInfoKHR& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayPropertiesKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayModeParametersKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayModePropertiesKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayModeCreateInfoKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayPlaneCapabilitiesKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayPlanePropertiesKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplaySurfaceCreateInfoKHR& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayPresentInfoKHR& value);

#ifdef VK_USE_PLATFORM_XLIB_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkXlibSurfaceCreateInfoKHR& value);
#endif /* VK_USE_PLATFORM_XLIB_KHR */

#ifdef VK_USE_PLATFORM_XCB_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkXcbSurfaceCreateInfoKHR& value);
#endif /* VK_USE_PLATFORM_XCB_KHR */

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkWaylandSurfaceCreateInfoKHR& value);
#endif /* VK_USE_PLATFORM_WAYLAND_KHR */

#ifdef VK_USE_PLATFORM_MIR_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkMirSurfaceCreateInfoKHR& value);
#endif /* VK_USE_PLATFORM_MIR_KHR */

#ifdef VK_USE_PLATFORM_ANDROID_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkAndroidSurfaceCreateInfoKHR& value);
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkWin32SurfaceCreateInfoKHR& value);
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkImportMemoryWin32HandleInfoKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkExportMemoryWin32HandleInfoKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryWin32HandlePropertiesKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryGetWin32HandleInfoKHR& value);
#endif /* VK_USE_PLATFORM_WIN32_KHR */

size_t encode_struct(format::ParameterEncoder* encoder, const VkImportMemoryFdInfoKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryFdPropertiesKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryGetFdInfoKHR& value);

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkWin32KeyedMutexAcquireReleaseInfoKHR& value);
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkImportSemaphoreWin32HandleInfoKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkExportSemaphoreWin32HandleInfoKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkD3D12FenceSubmitInfoKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSemaphoreGetWin32HandleInfoKHR& value);
#endif /* VK_USE_PLATFORM_WIN32_KHR */

size_t encode_struct(format::ParameterEncoder* encoder, const VkImportSemaphoreFdInfoKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSemaphoreGetFdInfoKHR& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDevicePushDescriptorPropertiesKHR& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkRectLayerKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPresentRegionKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPresentRegionsKHR& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkAttachmentDescription2KHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkAttachmentReference2KHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSubpassDescription2KHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSubpassDependency2KHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkRenderPassCreateInfo2KHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSubpassBeginInfoKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSubpassEndInfoKHR& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkSharedPresentSurfaceCapabilitiesKHR& value);

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkImportFenceWin32HandleInfoKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkExportFenceWin32HandleInfoKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkFenceGetWin32HandleInfoKHR& value);
#endif /* VK_USE_PLATFORM_WIN32_KHR */

size_t encode_struct(format::ParameterEncoder* encoder, const VkImportFenceFdInfoKHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkFenceGetFdInfoKHR& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceSurfaceInfo2KHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSurfaceCapabilities2KHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSurfaceFormat2KHR& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayProperties2KHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayPlaneProperties2KHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayModeProperties2KHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayPlaneInfo2KHR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayPlaneCapabilities2KHR& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkImageFormatListCreateInfoKHR& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDevice8BitStorageFeaturesKHR& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkDebugReportCallbackCreateInfoEXT& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineRasterizationStateRasterizationOrderAMD& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkDebugMarkerObjectNameInfoEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDebugMarkerObjectTagInfoEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDebugMarkerMarkerInfoEXT& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkDedicatedAllocationImageCreateInfoNV& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDedicatedAllocationBufferCreateInfoNV& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDedicatedAllocationMemoryAllocateInfoNV& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkTextureLODGatherFormatPropertiesAMD& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkShaderResourceUsageAMD& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkShaderStatisticsInfoAMD& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkExternalImageFormatPropertiesNV& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkExternalMemoryImageCreateInfoNV& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkExportMemoryAllocateInfoNV& value);

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkImportMemoryWin32HandleInfoNV& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkExportMemoryWin32HandleInfoNV& value);
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkWin32KeyedMutexAcquireReleaseInfoNV& value);
#endif /* VK_USE_PLATFORM_WIN32_KHR */

size_t encode_struct(format::ParameterEncoder* encoder, const VkValidationFlagsEXT& value);

#ifdef VK_USE_PLATFORM_VI_NN
size_t encode_struct(format::ParameterEncoder* encoder, const VkViSurfaceCreateInfoNN& value);
#endif /* VK_USE_PLATFORM_VI_NN */

size_t encode_struct(format::ParameterEncoder* encoder, const VkConditionalRenderingBeginInfoEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceConditionalRenderingFeaturesEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkCommandBufferInheritanceConditionalRenderingInfoEXT& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceGeneratedCommandsFeaturesNVX& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceGeneratedCommandsLimitsNVX& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkIndirectCommandsTokenNVX& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkIndirectCommandsLayoutTokenNVX& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkIndirectCommandsLayoutCreateInfoNVX& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkCmdProcessCommandsInfoNVX& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkCmdReserveSpaceForCommandsInfoNVX& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkObjectTableCreateInfoNVX& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkObjectTableEntryNVX& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkObjectTablePipelineEntryNVX& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkObjectTableDescriptorSetEntryNVX& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkObjectTableVertexBufferEntryNVX& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkObjectTableIndexBufferEntryNVX& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkObjectTablePushConstantEntryNVX& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkViewportWScalingNV& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineViewportWScalingStateCreateInfoNV& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkSurfaceCapabilities2EXT& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayPowerInfoEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceEventInfoEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayEventInfoEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSwapchainCounterCreateInfoEXT& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkRefreshCycleDurationGOOGLE& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPastPresentationTimingGOOGLE& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPresentTimeGOOGLE& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPresentTimesInfoGOOGLE& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkViewportSwizzleNV& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineViewportSwizzleStateCreateInfoNV& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceDiscardRectanglePropertiesEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineDiscardRectangleStateCreateInfoEXT& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceConservativeRasterizationPropertiesEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineRasterizationConservativeStateCreateInfoEXT& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkXYColorEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkHdrMetadataEXT& value);

#ifdef VK_USE_PLATFORM_IOS_MVK
size_t encode_struct(format::ParameterEncoder* encoder, const VkIOSSurfaceCreateInfoMVK& value);
#endif /* VK_USE_PLATFORM_IOS_MVK */

#ifdef VK_USE_PLATFORM_MACOS_MVK
size_t encode_struct(format::ParameterEncoder* encoder, const VkMacOSSurfaceCreateInfoMVK& value);
#endif /* VK_USE_PLATFORM_MACOS_MVK */

size_t encode_struct(format::ParameterEncoder* encoder, const VkDebugUtilsObjectNameInfoEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDebugUtilsObjectTagInfoEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDebugUtilsLabelEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDebugUtilsMessengerCallbackDataEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDebugUtilsMessengerCreateInfoEXT& value);

#ifdef VK_USE_PLATFORM_ANDROID_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkAndroidHardwareBufferUsageANDROID& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkAndroidHardwareBufferPropertiesANDROID& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkAndroidHardwareBufferFormatPropertiesANDROID& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkImportAndroidHardwareBufferInfoANDROID& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryGetAndroidHardwareBufferInfoANDROID& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkExternalFormatANDROID& value);
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

size_t encode_struct(format::ParameterEncoder* encoder, const VkSamplerReductionModeCreateInfoEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkSampleLocationEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSampleLocationsInfoEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkAttachmentSampleLocationsEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkSubpassSampleLocationsEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkRenderPassSampleLocationsBeginInfoEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineSampleLocationsStateCreateInfoEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceSampleLocationsPropertiesEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkMultisamplePropertiesEXT& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineColorBlendAdvancedStateCreateInfoEXT& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineCoverageToColorStateCreateInfoNV& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineCoverageModulationStateCreateInfoNV& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkValidationCacheCreateInfoEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkShaderModuleValidationCacheCreateInfoEXT& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorSetLayoutBindingFlagsCreateInfoEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceDescriptorIndexingFeaturesEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceDescriptorIndexingPropertiesEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorSetVariableDescriptorCountAllocateInfoEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorSetVariableDescriptorCountLayoutSupportEXT& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceQueueGlobalPriorityCreateInfoEXT& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkImportMemoryHostPointerInfoEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryHostPointerPropertiesEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceExternalMemoryHostPropertiesEXT& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceShaderCorePropertiesAMD& value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkVertexInputBindingDivisorDescriptionEXT& value);
size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineVertexInputDivisorStateCreateInfoEXT& value);

BRIMSTONE_END_NAMESPACE(brimstone)
