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

void encode_struct(format::ParameterEncoder* encoder, const VkApplicationInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkInstanceCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkAllocationCallbacks& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceFeatures& value);
void encode_struct(format::ParameterEncoder* encoder, const VkFormatProperties& value);
void encode_struct(format::ParameterEncoder* encoder, const VkExtent3D& value);
void encode_struct(format::ParameterEncoder* encoder, const VkImageFormatProperties& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceLimits& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceSparseProperties& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceProperties& value);
void encode_struct(format::ParameterEncoder* encoder, const VkQueueFamilyProperties& value);
void encode_struct(format::ParameterEncoder* encoder, const VkMemoryType& value);
void encode_struct(format::ParameterEncoder* encoder, const VkMemoryHeap& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceMemoryProperties& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDeviceQueueCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDeviceCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkExtensionProperties& value);
void encode_struct(format::ParameterEncoder* encoder, const VkLayerProperties& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSubmitInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkMemoryAllocateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkMappedMemoryRange& value);
void encode_struct(format::ParameterEncoder* encoder, const VkMemoryRequirements& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSparseImageFormatProperties& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSparseImageMemoryRequirements& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSparseMemoryBind& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSparseBufferMemoryBindInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSparseImageOpaqueMemoryBindInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkImageSubresource& value);
void encode_struct(format::ParameterEncoder* encoder, const VkOffset3D& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSparseImageMemoryBind& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSparseImageMemoryBindInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkBindSparseInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkFenceCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSemaphoreCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkEventCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkQueryPoolCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkBufferCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkBufferViewCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkImageCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSubresourceLayout& value);
void encode_struct(format::ParameterEncoder* encoder, const VkComponentMapping& value);
void encode_struct(format::ParameterEncoder* encoder, const VkImageSubresourceRange& value);
void encode_struct(format::ParameterEncoder* encoder, const VkImageViewCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkShaderModuleCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPipelineCacheCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSpecializationMapEntry& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSpecializationInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPipelineShaderStageCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkVertexInputBindingDescription& value);
void encode_struct(format::ParameterEncoder* encoder, const VkVertexInputAttributeDescription& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPipelineVertexInputStateCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPipelineInputAssemblyStateCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPipelineTessellationStateCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkViewport& value);
void encode_struct(format::ParameterEncoder* encoder, const VkOffset2D& value);
void encode_struct(format::ParameterEncoder* encoder, const VkExtent2D& value);
void encode_struct(format::ParameterEncoder* encoder, const VkRect2D& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPipelineViewportStateCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPipelineRasterizationStateCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPipelineMultisampleStateCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkStencilOpState& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPipelineDepthStencilStateCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPipelineColorBlendAttachmentState& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPipelineColorBlendStateCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPipelineDynamicStateCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkGraphicsPipelineCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkComputePipelineCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPushConstantRange& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPipelineLayoutCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSamplerCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDescriptorSetLayoutBinding& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDescriptorSetLayoutCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDescriptorPoolSize& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDescriptorPoolCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDescriptorSetAllocateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDescriptorImageInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDescriptorBufferInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkWriteDescriptorSet& value);
void encode_struct(format::ParameterEncoder* encoder, const VkCopyDescriptorSet& value);
void encode_struct(format::ParameterEncoder* encoder, const VkFramebufferCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkAttachmentDescription& value);
void encode_struct(format::ParameterEncoder* encoder, const VkAttachmentReference& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSubpassDescription& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSubpassDependency& value);
void encode_struct(format::ParameterEncoder* encoder, const VkRenderPassCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkCommandPoolCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkCommandBufferAllocateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkCommandBufferInheritanceInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkCommandBufferBeginInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkBufferCopy& value);
void encode_struct(format::ParameterEncoder* encoder, const VkImageSubresourceLayers& value);
void encode_struct(format::ParameterEncoder* encoder, const VkImageCopy& value);
void encode_struct(format::ParameterEncoder* encoder, const VkImageBlit& value);
void encode_struct(format::ParameterEncoder* encoder, const VkBufferImageCopy& value);
void encode_struct(format::ParameterEncoder* encoder, const VkClearDepthStencilValue& value);
void encode_struct(format::ParameterEncoder* encoder, const VkClearAttachment& value);
void encode_struct(format::ParameterEncoder* encoder, const VkClearRect& value);
void encode_struct(format::ParameterEncoder* encoder, const VkImageResolve& value);
void encode_struct(format::ParameterEncoder* encoder, const VkMemoryBarrier& value);
void encode_struct(format::ParameterEncoder* encoder, const VkBufferMemoryBarrier& value);
void encode_struct(format::ParameterEncoder* encoder, const VkImageMemoryBarrier& value);
void encode_struct(format::ParameterEncoder* encoder, const VkRenderPassBeginInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDispatchIndirectCommand& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDrawIndexedIndirectCommand& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDrawIndirectCommand& value);

void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceSubgroupProperties& value);
void encode_struct(format::ParameterEncoder* encoder, const VkBindBufferMemoryInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkBindImageMemoryInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDevice16BitStorageFeatures& value);
void encode_struct(format::ParameterEncoder* encoder, const VkMemoryDedicatedRequirements& value);
void encode_struct(format::ParameterEncoder* encoder, const VkMemoryDedicatedAllocateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkMemoryAllocateFlagsInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupRenderPassBeginInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupCommandBufferBeginInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupSubmitInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupBindSparseInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkBindBufferMemoryDeviceGroupInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkBindImageMemoryDeviceGroupInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceGroupProperties& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupDeviceCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkBufferMemoryRequirementsInfo2& value);
void encode_struct(format::ParameterEncoder* encoder, const VkImageMemoryRequirementsInfo2& value);
void encode_struct(format::ParameterEncoder* encoder, const VkImageSparseMemoryRequirementsInfo2& value);
void encode_struct(format::ParameterEncoder* encoder, const VkMemoryRequirements2& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSparseImageMemoryRequirements2& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceFeatures2& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceProperties2& value);
void encode_struct(format::ParameterEncoder* encoder, const VkFormatProperties2& value);
void encode_struct(format::ParameterEncoder* encoder, const VkImageFormatProperties2& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceImageFormatInfo2& value);
void encode_struct(format::ParameterEncoder* encoder, const VkQueueFamilyProperties2& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceMemoryProperties2& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSparseImageFormatProperties2& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceSparseImageFormatInfo2& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDevicePointClippingProperties& value);
void encode_struct(format::ParameterEncoder* encoder, const VkInputAttachmentAspectReference& value);
void encode_struct(format::ParameterEncoder* encoder, const VkRenderPassInputAttachmentAspectCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkImageViewUsageCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPipelineTessellationDomainOriginStateCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkRenderPassMultiviewCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceMultiviewFeatures& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceMultiviewProperties& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceVariablePointerFeatures& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceProtectedMemoryFeatures& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceProtectedMemoryProperties& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDeviceQueueInfo2& value);
void encode_struct(format::ParameterEncoder* encoder, const VkProtectedSubmitInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSamplerYcbcrConversionCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSamplerYcbcrConversionInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkBindImagePlaneMemoryInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkImagePlaneMemoryRequirementsInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceSamplerYcbcrConversionFeatures& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSamplerYcbcrConversionImageFormatProperties& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDescriptorUpdateTemplateEntry& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDescriptorUpdateTemplateCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkExternalMemoryProperties& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceExternalImageFormatInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkExternalImageFormatProperties& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceExternalBufferInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkExternalBufferProperties& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceIDProperties& value);
void encode_struct(format::ParameterEncoder* encoder, const VkExternalMemoryImageCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkExternalMemoryBufferCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkExportMemoryAllocateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceExternalFenceInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkExternalFenceProperties& value);
void encode_struct(format::ParameterEncoder* encoder, const VkExportFenceCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkExportSemaphoreCreateInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceExternalSemaphoreInfo& value);
void encode_struct(format::ParameterEncoder* encoder, const VkExternalSemaphoreProperties& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceMaintenance3Properties& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDescriptorSetLayoutSupport& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceShaderDrawParameterFeatures& value);

void encode_struct(format::ParameterEncoder* encoder, const VkSurfaceCapabilitiesKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSurfaceFormatKHR& value);

void encode_struct(format::ParameterEncoder* encoder, const VkSwapchainCreateInfoKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPresentInfoKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkImageSwapchainCreateInfoKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkBindImageMemorySwapchainInfoKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkAcquireNextImageInfoKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupPresentCapabilitiesKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupPresentInfoKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupSwapchainCreateInfoKHR& value);

void encode_struct(format::ParameterEncoder* encoder, const VkDisplayPropertiesKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDisplayModeParametersKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDisplayModePropertiesKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDisplayModeCreateInfoKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDisplayPlaneCapabilitiesKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDisplayPlanePropertiesKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDisplaySurfaceCreateInfoKHR& value);

void encode_struct(format::ParameterEncoder* encoder, const VkDisplayPresentInfoKHR& value);

#ifdef VK_USE_PLATFORM_XLIB_KHR
void encode_struct(format::ParameterEncoder* encoder, const VkXlibSurfaceCreateInfoKHR& value);
#endif /* VK_USE_PLATFORM_XLIB_KHR */

#ifdef VK_USE_PLATFORM_XCB_KHR
void encode_struct(format::ParameterEncoder* encoder, const VkXcbSurfaceCreateInfoKHR& value);
#endif /* VK_USE_PLATFORM_XCB_KHR */

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
void encode_struct(format::ParameterEncoder* encoder, const VkWaylandSurfaceCreateInfoKHR& value);
#endif /* VK_USE_PLATFORM_WAYLAND_KHR */

#ifdef VK_USE_PLATFORM_MIR_KHR
void encode_struct(format::ParameterEncoder* encoder, const VkMirSurfaceCreateInfoKHR& value);
#endif /* VK_USE_PLATFORM_MIR_KHR */

#ifdef VK_USE_PLATFORM_ANDROID_KHR
void encode_struct(format::ParameterEncoder* encoder, const VkAndroidSurfaceCreateInfoKHR& value);
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
void encode_struct(format::ParameterEncoder* encoder, const VkWin32SurfaceCreateInfoKHR& value);
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
void encode_struct(format::ParameterEncoder* encoder, const VkImportMemoryWin32HandleInfoKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkExportMemoryWin32HandleInfoKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkMemoryWin32HandlePropertiesKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkMemoryGetWin32HandleInfoKHR& value);
#endif /* VK_USE_PLATFORM_WIN32_KHR */

void encode_struct(format::ParameterEncoder* encoder, const VkImportMemoryFdInfoKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkMemoryFdPropertiesKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkMemoryGetFdInfoKHR& value);

#ifdef VK_USE_PLATFORM_WIN32_KHR
void encode_struct(format::ParameterEncoder* encoder, const VkWin32KeyedMutexAcquireReleaseInfoKHR& value);
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
void encode_struct(format::ParameterEncoder* encoder, const VkImportSemaphoreWin32HandleInfoKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkExportSemaphoreWin32HandleInfoKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkD3D12FenceSubmitInfoKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSemaphoreGetWin32HandleInfoKHR& value);
#endif /* VK_USE_PLATFORM_WIN32_KHR */

void encode_struct(format::ParameterEncoder* encoder, const VkImportSemaphoreFdInfoKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSemaphoreGetFdInfoKHR& value);

void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDevicePushDescriptorPropertiesKHR& value);

void encode_struct(format::ParameterEncoder* encoder, const VkRectLayerKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPresentRegionKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPresentRegionsKHR& value);

void encode_struct(format::ParameterEncoder* encoder, const VkAttachmentDescription2KHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkAttachmentReference2KHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSubpassDescription2KHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSubpassDependency2KHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkRenderPassCreateInfo2KHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSubpassBeginInfoKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSubpassEndInfoKHR& value);

void encode_struct(format::ParameterEncoder* encoder, const VkSharedPresentSurfaceCapabilitiesKHR& value);

#ifdef VK_USE_PLATFORM_WIN32_KHR
void encode_struct(format::ParameterEncoder* encoder, const VkImportFenceWin32HandleInfoKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkExportFenceWin32HandleInfoKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkFenceGetWin32HandleInfoKHR& value);
#endif /* VK_USE_PLATFORM_WIN32_KHR */

void encode_struct(format::ParameterEncoder* encoder, const VkImportFenceFdInfoKHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkFenceGetFdInfoKHR& value);

void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceSurfaceInfo2KHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSurfaceCapabilities2KHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSurfaceFormat2KHR& value);

void encode_struct(format::ParameterEncoder* encoder, const VkDisplayProperties2KHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDisplayPlaneProperties2KHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDisplayModeProperties2KHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDisplayPlaneInfo2KHR& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDisplayPlaneCapabilities2KHR& value);

void encode_struct(format::ParameterEncoder* encoder, const VkImageFormatListCreateInfoKHR& value);

void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDevice8BitStorageFeaturesKHR& value);

void encode_struct(format::ParameterEncoder* encoder, const VkDebugReportCallbackCreateInfoEXT& value);

void encode_struct(format::ParameterEncoder* encoder, const VkPipelineRasterizationStateRasterizationOrderAMD& value);

void encode_struct(format::ParameterEncoder* encoder, const VkDebugMarkerObjectNameInfoEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDebugMarkerObjectTagInfoEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDebugMarkerMarkerInfoEXT& value);

void encode_struct(format::ParameterEncoder* encoder, const VkDedicatedAllocationImageCreateInfoNV& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDedicatedAllocationBufferCreateInfoNV& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDedicatedAllocationMemoryAllocateInfoNV& value);

void encode_struct(format::ParameterEncoder* encoder, const VkTextureLODGatherFormatPropertiesAMD& value);

void encode_struct(format::ParameterEncoder* encoder, const VkShaderResourceUsageAMD& value);
void encode_struct(format::ParameterEncoder* encoder, const VkShaderStatisticsInfoAMD& value);

void encode_struct(format::ParameterEncoder* encoder, const VkExternalImageFormatPropertiesNV& value);

void encode_struct(format::ParameterEncoder* encoder, const VkExternalMemoryImageCreateInfoNV& value);
void encode_struct(format::ParameterEncoder* encoder, const VkExportMemoryAllocateInfoNV& value);

#ifdef VK_USE_PLATFORM_WIN32_KHR
void encode_struct(format::ParameterEncoder* encoder, const VkImportMemoryWin32HandleInfoNV& value);
void encode_struct(format::ParameterEncoder* encoder, const VkExportMemoryWin32HandleInfoNV& value);
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
void encode_struct(format::ParameterEncoder* encoder, const VkWin32KeyedMutexAcquireReleaseInfoNV& value);
#endif /* VK_USE_PLATFORM_WIN32_KHR */

void encode_struct(format::ParameterEncoder* encoder, const VkValidationFlagsEXT& value);

#ifdef VK_USE_PLATFORM_VI_NN
void encode_struct(format::ParameterEncoder* encoder, const VkViSurfaceCreateInfoNN& value);
#endif /* VK_USE_PLATFORM_VI_NN */

void encode_struct(format::ParameterEncoder* encoder, const VkConditionalRenderingBeginInfoEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceConditionalRenderingFeaturesEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkCommandBufferInheritanceConditionalRenderingInfoEXT& value);

void encode_struct(format::ParameterEncoder* encoder, const VkDeviceGeneratedCommandsFeaturesNVX& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDeviceGeneratedCommandsLimitsNVX& value);
void encode_struct(format::ParameterEncoder* encoder, const VkIndirectCommandsTokenNVX& value);
void encode_struct(format::ParameterEncoder* encoder, const VkIndirectCommandsLayoutTokenNVX& value);
void encode_struct(format::ParameterEncoder* encoder, const VkIndirectCommandsLayoutCreateInfoNVX& value);
void encode_struct(format::ParameterEncoder* encoder, const VkCmdProcessCommandsInfoNVX& value);
void encode_struct(format::ParameterEncoder* encoder, const VkCmdReserveSpaceForCommandsInfoNVX& value);
void encode_struct(format::ParameterEncoder* encoder, const VkObjectTableCreateInfoNVX& value);
void encode_struct(format::ParameterEncoder* encoder, const VkObjectTablePipelineEntryNVX& value);
void encode_struct(format::ParameterEncoder* encoder, const VkObjectTableDescriptorSetEntryNVX& value);
void encode_struct(format::ParameterEncoder* encoder, const VkObjectTableVertexBufferEntryNVX& value);
void encode_struct(format::ParameterEncoder* encoder, const VkObjectTableIndexBufferEntryNVX& value);
void encode_struct(format::ParameterEncoder* encoder, const VkObjectTablePushConstantEntryNVX& value);

void encode_struct(format::ParameterEncoder* encoder, const VkViewportWScalingNV& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPipelineViewportWScalingStateCreateInfoNV& value);

void encode_struct(format::ParameterEncoder* encoder, const VkSurfaceCapabilities2EXT& value);

void encode_struct(format::ParameterEncoder* encoder, const VkDisplayPowerInfoEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDeviceEventInfoEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDisplayEventInfoEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSwapchainCounterCreateInfoEXT& value);

void encode_struct(format::ParameterEncoder* encoder, const VkRefreshCycleDurationGOOGLE& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPastPresentationTimingGOOGLE& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPresentTimeGOOGLE& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPresentTimesInfoGOOGLE& value);

void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX& value);

void encode_struct(format::ParameterEncoder* encoder, const VkViewportSwizzleNV& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPipelineViewportSwizzleStateCreateInfoNV& value);

void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceDiscardRectanglePropertiesEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPipelineDiscardRectangleStateCreateInfoEXT& value);

void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceConservativeRasterizationPropertiesEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPipelineRasterizationConservativeStateCreateInfoEXT& value);

void encode_struct(format::ParameterEncoder* encoder, const VkXYColorEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkHdrMetadataEXT& value);

#ifdef VK_USE_PLATFORM_IOS_MVK
void encode_struct(format::ParameterEncoder* encoder, const VkIOSSurfaceCreateInfoMVK& value);
#endif /* VK_USE_PLATFORM_IOS_MVK */

#ifdef VK_USE_PLATFORM_MACOS_MVK
void encode_struct(format::ParameterEncoder* encoder, const VkMacOSSurfaceCreateInfoMVK& value);
#endif /* VK_USE_PLATFORM_MACOS_MVK */

void encode_struct(format::ParameterEncoder* encoder, const VkDebugUtilsObjectNameInfoEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDebugUtilsObjectTagInfoEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDebugUtilsLabelEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDebugUtilsMessengerCallbackDataEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDebugUtilsMessengerCreateInfoEXT& value);

#ifdef VK_USE_PLATFORM_ANDROID_KHR
void encode_struct(format::ParameterEncoder* encoder, const VkAndroidHardwareBufferUsageANDROID& value);
void encode_struct(format::ParameterEncoder* encoder, const VkAndroidHardwareBufferPropertiesANDROID& value);
void encode_struct(format::ParameterEncoder* encoder, const VkAndroidHardwareBufferFormatPropertiesANDROID& value);
void encode_struct(format::ParameterEncoder* encoder, const VkImportAndroidHardwareBufferInfoANDROID& value);
void encode_struct(format::ParameterEncoder* encoder, const VkMemoryGetAndroidHardwareBufferInfoANDROID& value);
void encode_struct(format::ParameterEncoder* encoder, const VkExternalFormatANDROID& value);
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

void encode_struct(format::ParameterEncoder* encoder, const VkSamplerReductionModeCreateInfoEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT& value);

void encode_struct(format::ParameterEncoder* encoder, const VkSampleLocationEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSampleLocationsInfoEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkAttachmentSampleLocationsEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkSubpassSampleLocationsEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkRenderPassSampleLocationsBeginInfoEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPipelineSampleLocationsStateCreateInfoEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceSampleLocationsPropertiesEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkMultisamplePropertiesEXT& value);

void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPipelineColorBlendAdvancedStateCreateInfoEXT& value);

void encode_struct(format::ParameterEncoder* encoder, const VkPipelineCoverageToColorStateCreateInfoNV& value);

void encode_struct(format::ParameterEncoder* encoder, const VkPipelineCoverageModulationStateCreateInfoNV& value);

void encode_struct(format::ParameterEncoder* encoder, const VkValidationCacheCreateInfoEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkShaderModuleValidationCacheCreateInfoEXT& value);

void encode_struct(format::ParameterEncoder* encoder, const VkDescriptorSetLayoutBindingFlagsCreateInfoEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceDescriptorIndexingFeaturesEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceDescriptorIndexingPropertiesEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDescriptorSetVariableDescriptorCountAllocateInfoEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkDescriptorSetVariableDescriptorCountLayoutSupportEXT& value);

void encode_struct(format::ParameterEncoder* encoder, const VkDeviceQueueGlobalPriorityCreateInfoEXT& value);

void encode_struct(format::ParameterEncoder* encoder, const VkImportMemoryHostPointerInfoEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkMemoryHostPointerPropertiesEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceExternalMemoryHostPropertiesEXT& value);

void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceShaderCorePropertiesAMD& value);

void encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkVertexInputBindingDivisorDescriptionEXT& value);
void encode_struct(format::ParameterEncoder* encoder, const VkPipelineVertexInputDivisorStateCreateInfoEXT& value);

BRIMSTONE_END_NAMESPACE(brimstone)
