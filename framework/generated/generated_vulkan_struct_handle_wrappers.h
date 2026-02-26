/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2026 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc.
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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#ifndef  GFXRECON_GENERATED_VULKAN_STRUCT_HANDLE_WRAPPERS_H
#define  GFXRECON_GENERATED_VULKAN_STRUCT_HANDLE_WRAPPERS_H

#include "encode/custom_vulkan_struct_handle_wrappers.h"
#include "encode/handle_unwrap_memory.h"
#include "encode/vulkan_handle_wrapper_util.h"
#include "format/platform_types.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)
GFXRECON_BEGIN_NAMESPACE(vulkan_wrappers)

void UnwrapStructHandles(VkBufferMemoryBarrier* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageMemoryBarrier* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryBarrier* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkApplicationInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkInstanceCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceQueueCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSubmitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMappedMemoryRange* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryAllocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSparseMemoryBind* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSparseBufferMemoryBindInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSparseImageOpaqueMemoryBindInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSparseImageMemoryBind* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSparseImageMemoryBindInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindSparseInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkFenceCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSemaphoreCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkQueryPoolCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBufferCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageViewCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCommandPoolCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCommandBufferAllocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCommandBufferInheritanceInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCommandBufferBeginInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkEventCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBufferViewCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkShaderModuleCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineCacheCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineShaderStageCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkComputePipelineCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineLayoutCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSamplerCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyDescriptorSet* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorBufferInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorPoolCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorSetAllocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorSetLayoutBinding* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorSetLayoutCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineVertexInputStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineInputAssemblyStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineTessellationStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineViewportStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineRasterizationStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineMultisampleStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineDepthStencilStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineColorBlendStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineDynamicStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGraphicsPipelineCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkFramebufferCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassBeginInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindBufferMemoryInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindImageMemoryInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryDedicatedRequirements* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryDedicatedAllocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryAllocateFlagsInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceGroupCommandBufferBeginInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceGroupSubmitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceGroupBindSparseInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindBufferMemoryDeviceGroupInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindImageMemoryDeviceGroupInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceGroupProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceGroupDeviceCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBufferMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageSparseMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryRequirements2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSparseImageMemoryRequirements2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFeatures2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceProperties2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkFormatProperties2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageFormatProperties2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImageFormatInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkQueueFamilyProperties2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMemoryProperties2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSparseImageFormatProperties2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSparseImageFormatInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageViewUsageCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceProtectedMemoryFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceProtectedMemoryProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceQueueInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkProtectedSubmitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindImagePlaneMemoryInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImagePlaneMemoryRequirementsInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceExternalImageFormatInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExternalImageFormatProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceExternalBufferInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExternalBufferProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceIDProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExternalMemoryImageCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExternalMemoryBufferCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExportMemoryAllocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceExternalFenceInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExternalFenceProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExportFenceCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExportSemaphoreCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceExternalSemaphoreInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExternalSemaphoreProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSubgroupProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevice16BitStorageFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVariablePointersFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorUpdateTemplateCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMaintenance3Properties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorSetLayoutSupport* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSamplerYcbcrConversionCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSamplerYcbcrConversionInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSamplerYcbcrConversionFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSamplerYcbcrConversionImageFormatProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceGroupRenderPassBeginInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePointClippingProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassInputAttachmentAspectCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineTessellationDomainOriginStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassMultiviewCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMultiviewFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMultiviewProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderDrawParametersFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVulkan11Features* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVulkan11Properties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVulkan12Features* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVulkan12Properties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageFormatListCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDriverProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVulkanMemoryModelFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceHostQueryResetFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceTimelineSemaphoreFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceTimelineSemaphoreProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSemaphoreTypeCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkTimelineSemaphoreSubmitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSemaphoreWaitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSemaphoreSignalInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceBufferDeviceAddressFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBufferDeviceAddressInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBufferOpaqueCaptureAddressCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryOpaqueCaptureAddressAllocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceMemoryOpaqueCaptureAddressInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevice8BitStorageFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderAtomicInt64Features* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderFloat16Int8Features* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFloatControlsProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorSetLayoutBindingFlagsCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDescriptorIndexingFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDescriptorIndexingProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorSetVariableDescriptorCountAllocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorSetVariableDescriptorCountLayoutSupport* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceScalarBlockLayoutFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSamplerReductionModeCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSamplerFilterMinmaxProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceUniformBufferStandardLayoutFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAttachmentDescription2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAttachmentReference2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSubpassDescription2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSubpassDependency2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassCreateInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSubpassBeginInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSubpassEndInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSubpassDescriptionDepthStencilResolve* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDepthStencilResolveProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageStencilUsageCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImagelessFramebufferFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkFramebufferAttachmentImageInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkFramebufferAttachmentsCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassAttachmentBeginInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAttachmentReferenceStencilLayout* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAttachmentDescriptionStencilLayout* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVulkan13Features* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVulkan13Properties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceToolProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePrivateDataFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDevicePrivateDataCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPrivateDataSlotCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryBarrier2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBufferMemoryBarrier2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageMemoryBarrier2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDependencyInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSemaphoreSubmitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCommandBufferSubmitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSubmitInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSynchronization2Features* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBufferCopy2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyBufferInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageCopy2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyImageInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBufferImageCopy2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyBufferToImageInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyImageToBufferInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceTextureCompressionASTCHDRFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkFormatProperties3* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMaintenance4Features* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMaintenance4Properties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceBufferMemoryRequirements* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceImageMemoryRequirements* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineCreationFeedbackCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderTerminateInvocationFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePipelineCreationCacheControlFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImageRobustnessFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSubgroupSizeControlFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSubgroupSizeControlProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineShaderStageRequiredSubgroupSizeCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceInlineUniformBlockFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceInlineUniformBlockProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkWriteDescriptorSetInlineUniformBlock* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorPoolInlineUniformBlockCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderIntegerDotProductFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderIntegerDotProductProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceTexelBufferAlignmentProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageBlit2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBlitImageInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageResolve2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkResolveImageInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderingAttachmentInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderingInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineRenderingCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDynamicRenderingFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCommandBufferInheritanceRenderingInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVulkan14Features* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVulkan14Properties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceQueueGlobalPriorityCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceGlobalPriorityQueryFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkQueueFamilyGlobalPriorityProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceIndexTypeUint8Features* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryMapInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryUnmapInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMaintenance5Features* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMaintenance5Properties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageSubresource2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceImageSubresourceInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSubresourceLayout2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBufferUsageFlags2CreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMaintenance6Features* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMaintenance6Properties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindMemoryStatus* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceHostImageCopyFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceHostImageCopyProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyImageToImageInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkHostImageLayoutTransitionInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSubresourceHostMemcpySize* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkHostImageCopyDevicePerformanceQuery* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderSubgroupRotateFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderFloatControls2Features* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderExpectAssumeFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineCreateFlags2CreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePushDescriptorProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindDescriptorSetsInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPushConstantsInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPushDescriptorSetInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePipelineProtectedAccessFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePipelineRobustnessFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePipelineRobustnessProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineRobustnessCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceLineRasterizationFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceLineRasterizationProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineRasterizationLineStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVertexAttributeDivisorProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineVertexInputDivisorStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVertexAttributeDivisorFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderingAreaInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDynamicRenderingLocalReadFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderingAttachmentLocationInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderingInputAttachmentIndexInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSwapchainCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPresentInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageSwapchainCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindImageMemorySwapchainInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAcquireNextImageInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceGroupPresentCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceGroupPresentInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceGroupSwapchainCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayModeCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayModePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayPlanePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplaySurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayPresentInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkXlibSurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkXcbSurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkWaylandSurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAndroidSurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkWin32SurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkQueueFamilyQueryResultStatusPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkQueueFamilyVideoPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoProfileInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoProfileListInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVideoFormatInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoFormatPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoPictureResourceInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoReferenceSlotInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoSessionMemoryRequirementsKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindVideoSessionMemoryInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoSessionCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoSessionParametersCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoSessionParametersUpdateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoBeginCodingInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEndCodingInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoCodingControlInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoDecodeCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoDecodeUsageInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoDecodeInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeH264CapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeH264QualityLevelPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeH264SessionCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeH264SessionParametersAddInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeH264SessionParametersCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeH264SessionParametersGetInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeH264SessionParametersFeedbackInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeH264NaluSliceInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeH264PictureInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeH264DpbSlotInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeH264ProfileInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeH264RateControlInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeH264RateControlLayerInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeH264GopRemainingFrameInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoDecodeH264ProfileInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoDecodeH264CapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoDecodeH264SessionParametersAddInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoDecodeH264SessionParametersCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoDecodeH264PictureInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoDecodeH264DpbSlotInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportMemoryWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExportMemoryWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryWin32HandlePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportMemoryFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryFdPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkWin32KeyedMutexAcquireReleaseInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportSemaphoreWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExportSemaphoreWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkD3D12FenceSubmitInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSemaphoreGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportSemaphoreFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSemaphoreGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPresentRegionsKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSharedPresentSurfaceCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportFenceWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExportFenceWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkFenceGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportFenceFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkFenceGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePerformanceQueryFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePerformanceQueryPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPerformanceCounterKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPerformanceCounterDescriptionKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkQueryPoolPerformanceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAcquireProfilingLockInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPerformanceQuerySubmitInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSurfaceInfo2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSurfaceCapabilities2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSurfaceFormat2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayProperties2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayPlaneProperties2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayModeProperties2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayPlaneInfo2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayPlaneCapabilities2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderBfloat16FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePortabilitySubsetFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePortabilitySubsetPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderClockFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkFragmentShadingRateAttachmentInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineFragmentShadingRateStateCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentShadingRateFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentShadingRatePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentShadingRateKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderingFragmentShadingRateAttachmentInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderQuadControlFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSurfaceProtectedCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePresentWaitFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineExecutablePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineExecutableInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineExecutableStatisticKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineExecutableInternalRepresentationKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineLibraryCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPresentIdKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePresentIdFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkQueryPoolVideoEncodeFeedbackCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeUsageInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeRateControlLayerInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeRateControlInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeQualityLevelPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeQualityLevelInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeSessionParametersGetInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeSessionParametersFeedbackInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderUntypedPointersFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSurfaceCapabilitiesPresentId2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPresentId2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePresentId2FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSurfaceCapabilitiesPresentWait2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePresentWait2FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPresentWait2InfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePipelineBinaryFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePipelineBinaryPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDevicePipelineBinaryInternalCacheControlKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineBinaryKeyKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineBinaryCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineBinaryInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkReleaseCapturedPipelineDataInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineBinaryDataInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineBinaryHandlesInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSurfacePresentModeKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSurfacePresentScalingCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSurfacePresentModeCompatibilityKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSwapchainPresentFenceInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSwapchainPresentModesCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSwapchainPresentModeInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSwapchainPresentScalingCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkReleaseSwapchainImagesInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCooperativeMatrixPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCooperativeMatrixFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCooperativeMatrixPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoDecodeAV1ProfileInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoDecodeAV1CapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoDecodeAV1SessionParametersCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoDecodeAV1PictureInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoDecodeAV1DpbSlotInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVideoEncodeAV1FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeAV1CapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeAV1QualityLevelPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeAV1SessionCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeAV1SessionParametersCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeAV1PictureInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeAV1DpbSlotInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeAV1ProfileInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeAV1GopRemainingFrameInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeAV1RateControlInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeAV1RateControlLayerInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVideoDecodeVP9FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoDecodeVP9ProfileInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoDecodeVP9CapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoDecodeVP9PictureInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVideoMaintenance1FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoInlineQueryInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAttachmentFeedbackLoopInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCalibratedTimestampInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSetDescriptorBufferOffsetsInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindDescriptorBufferEmbeddedSamplersInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyMemoryIndirectInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyMemoryToImageIndirectInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeIntraRefreshCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeSessionIntraRefreshCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeIntraRefreshInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoReferenceIntraRefreshInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeQuantizationMapCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoFormatQuantizationMapPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeQuantizationMapInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeH264QuantizationMapCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeH265QuantizationMapCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoFormatH265QuantizationMapPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeAV1QuantizationMapCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoFormatAV1QuantizationMapPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMaintenance7FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMaintenance7PropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceLayeredApiPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceLayeredApiPropertiesListKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceLayeredApiVulkanPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryBarrierAccessFlags3KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMaintenance8FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderFmaFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMaintenance9FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMaintenance9PropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkQueueFamilyOwnershipTransferPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDepthClampZeroOneFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRobustness2FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRobustness2PropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMaintenance10FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMaintenance10PropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderingEndInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderingAttachmentFlagsInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkResolveImageModeInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDebugReportCallbackCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineRasterizationStateRasterizationOrderAMD* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDebugMarkerObjectNameInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDebugMarkerObjectTagInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDebugMarkerMarkerInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDedicatedAllocationImageCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDedicatedAllocationBufferCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDedicatedAllocationMemoryAllocateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceTransformFeedbackFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceTransformFeedbackPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineRasterizationStateStreamCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageViewHandleInfoNVX* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageViewAddressPropertiesNVX* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkTextureLODGatherFormatPropertiesAMD* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkStreamDescriptorSurfaceCreateInfoGGP* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCornerSampledImageFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExternalMemoryImageCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExportMemoryAllocateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportMemoryWin32HandleInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExportMemoryWin32HandleInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkWin32KeyedMutexAcquireReleaseInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkValidationFlagsEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkViSurfaceCreateInfoNN* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageViewASTCDecodeModeEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceASTCDecodeFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkConditionalRenderingBeginInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceConditionalRenderingFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCommandBufferInheritanceConditionalRenderingInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineViewportWScalingStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSurfaceCapabilities2EXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayPowerInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceEventInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayEventInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSwapchainCounterCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPresentTimesInfoGOOGLE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMultiviewPerViewAttributesInfoNVX* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineViewportSwizzleStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDiscardRectanglePropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineDiscardRectangleStateCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceConservativeRasterizationPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineRasterizationConservativeStateCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDepthClipEnableFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineRasterizationDepthClipStateCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkHdrMetadataEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkIOSSurfaceCreateInfoMVK* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMacOSSurfaceCreateInfoMVK* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDebugUtilsLabelEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDebugUtilsObjectNameInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDebugUtilsMessengerCallbackDataEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDebugUtilsMessengerCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDebugUtilsObjectTagInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAndroidHardwareBufferUsageANDROID* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAndroidHardwareBufferPropertiesANDROID* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAndroidHardwareBufferFormatPropertiesANDROID* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportAndroidHardwareBufferInfoANDROID* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryGetAndroidHardwareBufferInfoANDROID* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExternalFormatANDROID* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAndroidHardwareBufferFormatProperties2ANDROID* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAttachmentSampleCountInfoAMD* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSampleLocationsInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassSampleLocationsBeginInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineSampleLocationsStateCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSampleLocationsPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMultisamplePropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineColorBlendAdvancedStateCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineCoverageToColorStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineCoverageModulationStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDrmFormatModifierPropertiesListEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImageDrmFormatModifierInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageDrmFormatModifierListCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageDrmFormatModifierExplicitCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageDrmFormatModifierPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDrmFormatModifierPropertiesList2EXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkValidationCacheCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkShaderModuleValidationCacheCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineViewportShadingRateImageStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShadingRateImageFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShadingRateImagePropertiesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRayTracingShaderGroupCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRayTracingPipelineCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeometryTrianglesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeometryAABBNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeometryDataNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeometryNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindAccelerationStructureMemoryInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkWriteDescriptorSetAccelerationStructureNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureMemoryRequirementsInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRayTracingPropertiesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineRepresentativeFragmentTestStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImageViewImageFormatInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkFilterCubicImageViewImageFormatPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportMemoryHostPointerInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryHostPointerPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceExternalMemoryHostPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineCompilerControlCreateInfoAMD* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderCorePropertiesAMD* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceMemoryOverallocationCreateInfoAMD* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPresentFrameTokenGGP* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMeshShaderFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMeshShaderPropertiesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderImageFootprintFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineViewportExclusiveScissorStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceExclusiveScissorFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkQueueFamilyCheckpointPropertiesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCheckpointDataNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkQueueFamilyCheckpointProperties2NV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCheckpointData2NV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePresentTimingFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPresentTimingSurfaceCapabilitiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSwapchainCalibratedTimestampInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSwapchainTimingPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSwapchainTimeDomainPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPastPresentationTimingInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPastPresentationTimingEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPastPresentationTimingPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPresentTimingInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPresentTimingsInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkInitializePerformanceApiInfoINTEL* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkQueryPoolPerformanceQueryCreateInfoINTEL* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPerformanceMarkerInfoINTEL* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPerformanceStreamMarkerInfoINTEL* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPerformanceOverrideInfoINTEL* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPerformanceConfigurationAcquireInfoINTEL* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePCIBusInfoPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayNativeHdrSurfaceCapabilitiesAMD* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSwapchainDisplayNativeHdrCreateInfoAMD* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImagePipeSurfaceCreateInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMetalSurfaceCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentDensityMapFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentDensityMapPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassFragmentDensityMapCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderingFragmentDensityMapAttachmentInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderCoreProperties2AMD* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCoherentMemoryFeaturesAMD* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMemoryBudgetPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMemoryPriorityFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryPriorityAllocateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBufferDeviceAddressCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkValidationFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCooperativeMatrixPropertiesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCooperativeMatrixFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCooperativeMatrixPropertiesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCoverageReductionModeFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineCoverageReductionStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkFramebufferMixedSamplesCombinationNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceProvokingVertexFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceProvokingVertexPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineRasterizationProvokingVertexStateCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSurfaceFullScreenExclusiveInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSurfaceCapabilitiesFullScreenExclusiveEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSurfaceFullScreenExclusiveWin32InfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkHeadlessSurfaceCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMapMemoryPlacedFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMapMemoryPlacedPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryMapPlacedInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGraphicsShaderGroupCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGraphicsPipelineShaderGroupsCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkIndirectCommandsStreamNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkIndirectCommandsLayoutTokenNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkIndirectCommandsLayoutCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeneratedCommandsInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeneratedCommandsMemoryRequirementsInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceInheritedViewportScissorFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCommandBufferInheritanceViewportScissorInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassTransformBeginInfoQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCommandBufferInheritanceRenderPassTransformInfoQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDepthBiasControlFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDepthBiasInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDepthBiasRepresentationInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceMemoryReportCallbackDataEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceDeviceMemoryReportCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSamplerCustomBorderColorCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCustomBorderColorPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCustomBorderColorFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePresentBarrierFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSurfaceCapabilitiesPresentBarrierNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSwapchainPresentBarrierCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDiagnosticsConfigFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceDiagnosticsConfigCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceTileShadingFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceTileShadingPropertiesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassTileShadingCreateInfoQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPerTileBeginInfoQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPerTileEndInfoQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDispatchTileInfoQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkQueryLowLatencySupportNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDescriptorBufferPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDescriptorBufferFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorAddressInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorBufferBindingInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorBufferBindingPushDescriptorBufferHandleEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBufferCaptureDescriptorDataInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageCaptureDescriptorDataInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageViewCaptureDescriptorDataInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSamplerCaptureDescriptorDataInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkOpaqueCaptureDescriptorDataCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureCaptureDescriptorDataInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGraphicsPipelineLibraryCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineFragmentShadingRateEnumStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureGeometryMotionTrianglesDataNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureMotionInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentDensityMap2PropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyCommandTransformInfoQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImageCompressionControlFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageCompressionControlEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageCompressionPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevice4444FormatsFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFaultFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceFaultCountsEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceFaultInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDirectFBSurfaceCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMutableDescriptorTypeCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVertexInputBindingDescription2EXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVertexInputAttributeDescription2EXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDrmPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceAddressBindingReportFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceAddressBindingCallbackDataEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDepthClipControlFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineViewportDepthClipControlCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportMemoryZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryZirconHandlePropertiesFUCHSIA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryGetZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportSemaphoreZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSemaphoreGetZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryGetRemoteAddressInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFrameBoundaryFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkFrameBoundaryEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSubpassResolvePerformanceQueryEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMultisampledRenderToSingleSampledInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkScreenSurfaceCreateInfoQNX* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceColorWriteEnableFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineColorWriteCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeRgbConversionCapabilitiesVALVE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeProfileRgbConversionInfoVALVE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeSessionRgbConversionCreateInfoVALVE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImageViewMinLodFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageViewMinLodCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMultiDrawFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMultiDrawPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderTileImageFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderTileImagePropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMicromapBuildInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMicromapCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceOpacityMicromapFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceOpacityMicromapPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMicromapVersionInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyMicromapToMemoryInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyMemoryToMicromapInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyMicromapInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMicromapBuildSizesInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureTrianglesOpacityMicromapEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDisplacementMicromapFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDisplacementMicromapPropertiesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureTrianglesDisplacementMicromapNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSamplerBorderColorComponentMappingCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderCorePropertiesARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceQueueShaderCoreControlCreateInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSchedulingControlsFeaturesARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSchedulingControlsPropertiesARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageViewSlicedCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorSetBindingReferenceVALVE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorSetLayoutHostMappingInfoVALVE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRenderPassStripedFeaturesARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRenderPassStripedPropertiesARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassStripeInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassStripeBeginInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassStripeSubmitInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassFragmentDensityMapOffsetEndInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkComputePipelineIndirectBufferInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineIndirectDeviceAddressInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureGeometryLinearSweptSpheresDataNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureGeometrySpheresDataNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceLinearColorAttachmentFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageViewSampleWeightCreateInfoQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImageProcessingFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImageProcessingPropertiesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceNestedCommandBufferFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceNestedCommandBufferPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExternalMemoryAcquireUnmodifiedEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceExtendedDynamicState3PropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassCreationControlEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassCreationFeedbackCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassSubpassFeedbackCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDirectDriverLoadingInfoLUNARG* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDirectDriverLoadingListLUNARG* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineShaderStageModuleIdentifierCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkShaderModuleIdentifierEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceOpticalFlowFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceOpticalFlowPropertiesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkOpticalFlowImageFormatInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkOpticalFlowImageFormatPropertiesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkOpticalFlowSessionCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkOpticalFlowSessionCreatePrivateDataInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkOpticalFlowExecuteInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceLegacyDitheringFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceExternalFormatResolveFeaturesANDROID* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceExternalFormatResolvePropertiesANDROID* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAndroidHardwareBufferFormatResolvePropertiesANDROID* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceAntiLagFeaturesAMD* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAntiLagPresentationInfoAMD* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAntiLagDataAMD* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderObjectFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderObjectPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkShaderCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceTilePropertiesFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkTilePropertiesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceAmigoProfilingFeaturesSEC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAmigoProfilingSubmitInfoSEC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCooperativeVectorPropertiesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCooperativeVectorFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCooperativeVectorPropertiesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkConvertCooperativeVectorMatrixInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkLayerSettingsCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkLatencySleepModeInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkLatencySleepInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSetLatencyMarkerInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkLatencyTimingsFrameReportNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGetLatencyMarkerInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkLatencySubmissionPresentIdNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSwapchainLatencyCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkOutOfBandQueueTypeInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkLatencySurfaceCapabilitiesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDataGraphFeaturesARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDataGraphPipelineConstantARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDataGraphPipelineResourceInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDataGraphPipelineCompilerControlCreateInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDataGraphPipelineCreateInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDataGraphPipelineShaderModuleCreateInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDataGraphPipelineSessionCreateInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDataGraphPipelineSessionBindPointRequirementsInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDataGraphPipelineSessionBindPointRequirementARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDataGraphPipelineSessionMemoryRequirementsInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindDataGraphPipelineSessionMemoryInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDataGraphPipelineInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDataGraphPipelinePropertyQueryResultARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDataGraphPipelineIdentifierCreateInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDataGraphPipelineDispatchInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkQueueFamilyDataGraphPropertiesARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDataGraphProcessingEngineCreateInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkQueueFamilyDataGraphProcessingEnginePropertiesARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePerStageDescriptorSetFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImageProcessing2FeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImageProcessing2PropertiesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSamplerBlockMatchWindowCreateInfoQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCubicWeightsFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSamplerCubicWeightsCreateInfoQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBlitImageCubicWeightsInfoQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceYcbcrDegammaFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCubicClampFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceLayeredDriverPropertiesMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceTileMemoryHeapFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceTileMemoryHeapPropertiesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkTileMemoryRequirementsQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkTileMemoryBindInfoQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkTileMemorySizeInfoQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDecompressMemoryInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMemoryDecompressionFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMemoryDecompressionPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplaySurfaceStereoCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayModeStereoPropertiesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRawAccessChainsFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCommandBufferInheritanceFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderFloat8FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRayTracingValidationFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPartitionedAccelerationStructureFlagsNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkWriteDescriptorSetPartitionedAccelerationStructureNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPartitionedAccelerationStructureInstancesInputNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBuildPartitionedAccelerationStructureInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureBuildSizesInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeneratedCommandsMemoryRequirementsInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkIndirectExecutionSetPipelineInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkIndirectExecutionSetShaderLayoutInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkIndirectExecutionSetShaderInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeneratedCommandsInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkWriteIndirectExecutionSetPipelineEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkIndirectCommandsLayoutCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeneratedCommandsPipelineInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeneratedCommandsShaderInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkWriteIndirectExecutionSetShaderEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImageAlignmentControlFeaturesMESA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImageAlignmentControlPropertiesMESA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageAlignmentControlCreateInfoMESA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPushConstantBankInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePushConstantBankFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePushConstantBankPropertiesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDepthClampControlFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineViewportDepthClampControlCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceHdrVividFeaturesHUAWEI* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkHdrVividDynamicMetadataHUAWEI* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCooperativeMatrixFlexibleDimensionsPropertiesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCooperativeMatrix2FeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCooperativeMatrix2PropertiesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePipelineOpacityMicromapFeaturesARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportMemoryMetalHandleInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryMetalHandlePropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryGetMetalHandleInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePerformanceCountersByRegionFeaturesARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePerformanceCountersByRegionPropertiesARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPerformanceCounterARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPerformanceCounterDescriptionARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassPerformanceCountersByRegionBeginInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFormatPackFeaturesARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineFragmentDensityMapLayeredCreateInfoVALVE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSetPresentConfigNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePresentMeteringFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShader64BitIndexingFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCustomResolveFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBeginCustomResolveInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCustomResolveCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDataGraphPipelineBuiltinModelCreateInfoQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDataGraphModelFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderLongVectorFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderLongVectorPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkComputeOccupancyPriorityParametersNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureGeometryTrianglesDataKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureGeometryAabbsDataKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureGeometryInstancesDataKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkWriteDescriptorSetAccelerationStructureKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceAccelerationStructureFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceAccelerationStructurePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureDeviceAddressInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureVersionInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyAccelerationStructureToMemoryInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyMemoryToAccelerationStructureInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyAccelerationStructureInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRayTracingShaderGroupCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRayTracingPipelineInterfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRayTracingPipelineCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRayTracingPipelineFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRayTracingPipelinePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRayQueryFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMeshShaderFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMeshShaderPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

VkBaseInStructure* CopyPNextStruct(const VkBaseInStructure* base, HandleUnwrapMemory* unwrap_memory);

const void* UnwrapPNextStructHandles(const void* value, HandleUnwrapMemory* unwrap_memory);

template <typename ParentWrapper, typename CoParentWrapper, typename T>
void CreateWrappedStructArrayHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, T* value, size_t len, PFN_GetHandleId get_id);

template <typename T>
T* MakeUnwrapStructs(const T* values, size_t len, HandleUnwrapMemory* unwrap_memory)
{
    assert((values != nullptr) && (len > 0) && (unwrap_memory != nullptr));

    const uint8_t* bytes     = reinterpret_cast<const uint8_t*>(values);
    size_t         num_bytes = len * sizeof(T);

    return reinterpret_cast<T*>(unwrap_memory->GetFilledBuffer(bytes, num_bytes));
}

template <typename T>
const T* UnwrapStructPtrHandles(const T* value, HandleUnwrapMemory* unwrap_memory)
{
    T* unwrapped_struct = nullptr;

    if (value != nullptr)
    {
        unwrapped_struct = MakeUnwrapStructs(value, 1, unwrap_memory);
        UnwrapStructHandles(unwrapped_struct, unwrap_memory);
    }

    return unwrapped_struct;
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, VkPhysicalDeviceGroupProperties* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        vulkan_wrappers::CreateWrappedHandles<ParentWrapper, CoParentWrapper, vulkan_wrappers::PhysicalDeviceWrapper>(parent, co_parent, value->physicalDevices, value->physicalDeviceCount, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, VkDisplayPropertiesKHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        vulkan_wrappers::CreateWrappedHandle<ParentWrapper, CoParentWrapper, vulkan_wrappers::DisplayKHRWrapper>(parent, co_parent, &value->display, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, VkDisplayPlanePropertiesKHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        vulkan_wrappers::CreateWrappedHandle<ParentWrapper, CoParentWrapper, vulkan_wrappers::DisplayKHRWrapper>(parent, co_parent, &value->currentDisplay, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, VkDisplayModePropertiesKHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        vulkan_wrappers::CreateWrappedHandle<ParentWrapper, CoParentWrapper, vulkan_wrappers::DisplayModeKHRWrapper>(parent, co_parent, &value->displayMode, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, VkDisplayProperties2KHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        vulkan_wrappers::CreateWrappedStructHandles<ParentWrapper, CoParentWrapper>(parent, co_parent, &value->displayProperties, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, VkDisplayPlaneProperties2KHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        vulkan_wrappers::CreateWrappedStructHandles<ParentWrapper, CoParentWrapper>(parent, co_parent, &value->displayPlaneProperties, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, VkDisplayModeProperties2KHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        vulkan_wrappers::CreateWrappedStructHandles<ParentWrapper, CoParentWrapper>(parent, co_parent, &value->displayModeProperties, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, VkPipelineBinaryHandlesInfoKHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        vulkan_wrappers::CreateWrappedHandles<ParentWrapper, CoParentWrapper, vulkan_wrappers::PipelineBinaryKHRWrapper>(parent, co_parent, value->pPipelineBinaries, value->pipelineBinaryCount, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper, typename T>
void CreateWrappedStructArrayHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, T* value, size_t len, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        for (size_t i = 0; i < len; ++i)
        {
            CreateWrappedStructHandles<ParentWrapper, CoParentWrapper>(parent, co_parent, &value[i], get_id);
        }
    }
}

template <typename T>
const T* UnwrapStructArrayHandles(const T* values, size_t len, HandleUnwrapMemory* unwrap_memory)
{
    if ((values != nullptr) && (len > 0))
    {
        auto unwrapped_structs = MakeUnwrapStructs(values, len, unwrap_memory);

        for (size_t i = 0; i < len; ++i)
        {
            UnwrapStructHandles(&unwrapped_structs[i], unwrap_memory);
        }

        return unwrapped_structs;
    }

    // Leave the original memory in place when the pointer is not null, but size is zero.
    return values;
}

template <typename T>
void UnwrapStructStaticArrayHandles(T* values, size_t len, HandleUnwrapMemory* unwrap_memory)
{
    // Fill directly in (no need to alloc)
    for (size_t i = 0; i < len; ++i)
    {
        UnwrapStructHandles(&values[i], unwrap_memory);
    }
}

template <typename T>
T* UnwrapStructPtrArrayHandles(T* values, size_t len, HandleUnwrapMemory* unwrap_memory)
{
    if ((values != nullptr) && (len > 0))
    {
        auto unwrapped_structs = MakeUnwrapStructs(values, len, unwrap_memory);

        for (size_t i = 0; i < len; ++i)
        {
            UnwrapStructHandles(unwrapped_structs[i], unwrap_memory);
        }

        return unwrapped_structs;
    }

    // Leave the original memory in place when the pointer is not null, but size is zero.
    return values;
}

GFXRECON_END_NAMESPACE(vulkan_wrappers)
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_VULKAN_STRUCT_HANDLE_WRAPPERS_H
