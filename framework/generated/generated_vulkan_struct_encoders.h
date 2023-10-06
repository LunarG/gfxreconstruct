/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2023 LunarG, Inc.
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

#ifndef  GFXRECON_GENERATED_VULKAN_STRUCT_ENCODERS_H
#define  GFXRECON_GENERATED_VULKAN_STRUCT_ENCODERS_H

#include "encode/parameter_encoder.h"
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

#include <cstdint>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void EncodePNextStruct(ParameterEncoder* encoder, const void* value);

void EncodeStruct(ParameterEncoder* encoder, const StdVideoH264SpsVuiFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH264HrdParameters& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH264SequenceParameterSetVui& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH264SpsFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH264ScalingLists& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH264SequenceParameterSet& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH264PpsFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH264PictureParameterSet& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoDecodeH264PictureInfoFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoDecodeH264PictureInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoDecodeH264ReferenceInfoFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoDecodeH264ReferenceInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH264WeightTableFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH264WeightTable& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH264SliceHeaderFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH264PictureInfoFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH264ReferenceInfoFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH264ReferenceListsInfoFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH264RefListModEntry& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH264RefPicMarkingEntry& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH264ReferenceListsInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH264PictureInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH264ReferenceInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH264SliceHeader& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH265ProfileTierLevelFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH265ProfileTierLevel& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH265DecPicBufMgr& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH265SubLayerHrdParameters& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH265HrdFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH265HrdParameters& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH265VpsFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH265VideoParameterSet& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH265ScalingLists& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH265ShortTermRefPicSetFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH265ShortTermRefPicSet& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH265LongTermRefPicsSps& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH265SpsVuiFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH265SequenceParameterSetVui& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH265PredictorPaletteEntries& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH265SpsFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH265SequenceParameterSet& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH265PpsFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoH265PictureParameterSet& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoDecodeH265PictureInfoFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoDecodeH265PictureInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoDecodeH265ReferenceInfoFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoDecodeH265ReferenceInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH265WeightTableFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH265WeightTable& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH265LongTermRefPics& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH265SliceSegmentHeaderFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH265SliceSegmentHeader& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH265ReferenceListsInfoFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH265ReferenceListsInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH265PictureInfoFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH265PictureInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH265ReferenceInfoFlags& value);
void EncodeStruct(ParameterEncoder* encoder, const StdVideoEncodeH265ReferenceInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExtent2D& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExtent3D& value);
void EncodeStruct(ParameterEncoder* encoder, const VkOffset2D& value);
void EncodeStruct(ParameterEncoder* encoder, const VkOffset3D& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRect2D& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBufferMemoryBarrier& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDispatchIndirectCommand& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDrawIndexedIndirectCommand& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDrawIndirectCommand& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageSubresourceRange& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageMemoryBarrier& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryBarrier& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineCacheHeaderVersionOne& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAllocationCallbacks& value);
void EncodeStruct(ParameterEncoder* encoder, const VkApplicationInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkFormatProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageFormatProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkInstanceCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryHeap& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryType& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceLimits& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMemoryProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSparseProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkQueueFamilyProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceQueueCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExtensionProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkLayerProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubmitInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMappedMemoryRange& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryAllocateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryRequirements& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSparseMemoryBind& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSparseBufferMemoryBindInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSparseImageOpaqueMemoryBindInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageSubresource& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSparseImageMemoryBind& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSparseImageMemoryBindInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindSparseInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSparseImageFormatProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSparseImageMemoryRequirements& value);
void EncodeStruct(ParameterEncoder* encoder, const VkFenceCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSemaphoreCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkEventCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkQueryPoolCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBufferCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBufferViewCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubresourceLayout& value);
void EncodeStruct(ParameterEncoder* encoder, const VkComponentMapping& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageViewCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkShaderModuleCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineCacheCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSpecializationMapEntry& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSpecializationInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineShaderStageCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkComputePipelineCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVertexInputBindingDescription& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVertexInputAttributeDescription& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineVertexInputStateCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineInputAssemblyStateCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineTessellationStateCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkViewport& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineViewportStateCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineRasterizationStateCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineMultisampleStateCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkStencilOpState& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineDepthStencilStateCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineColorBlendAttachmentState& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineColorBlendStateCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineDynamicStateCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkGraphicsPipelineCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPushConstantRange& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineLayoutCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSamplerCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCopyDescriptorSet& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorBufferInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorPoolSize& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorPoolCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorSetAllocateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorSetLayoutBinding& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorSetLayoutCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAttachmentDescription& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAttachmentReference& value);
void EncodeStruct(ParameterEncoder* encoder, const VkFramebufferCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubpassDescription& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubpassDependency& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCommandPoolCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCommandBufferAllocateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCommandBufferInheritanceInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCommandBufferBeginInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBufferCopy& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageSubresourceLayers& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBufferImageCopy& value);
void EncodeStruct(ParameterEncoder* encoder, const VkClearDepthStencilValue& value);
void EncodeStruct(ParameterEncoder* encoder, const VkClearAttachment& value);
void EncodeStruct(ParameterEncoder* encoder, const VkClearRect& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageBlit& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageCopy& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageResolve& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassBeginInfo& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSubgroupProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindBufferMemoryInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindImageMemoryInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevice16BitStorageFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryDedicatedRequirements& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryDedicatedAllocateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryAllocateFlagsInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceGroupRenderPassBeginInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceGroupCommandBufferBeginInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceGroupSubmitInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceGroupBindSparseInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindBufferMemoryDeviceGroupInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindImageMemoryDeviceGroupInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceGroupProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceGroupDeviceCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBufferMemoryRequirementsInfo2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageMemoryRequirementsInfo2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageSparseMemoryRequirementsInfo2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryRequirements2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSparseImageMemoryRequirements2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFeatures2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceProperties2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkFormatProperties2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageFormatProperties2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceImageFormatInfo2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkQueueFamilyProperties2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMemoryProperties2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSparseImageFormatProperties2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSparseImageFormatInfo2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePointClippingProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkInputAttachmentAspectReference& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassInputAttachmentAspectCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageViewUsageCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineTessellationDomainOriginStateCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassMultiviewCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMultiviewFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMultiviewProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceVariablePointersFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceProtectedMemoryFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceProtectedMemoryProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceQueueInfo2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkProtectedSubmitInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSamplerYcbcrConversionCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSamplerYcbcrConversionInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindImagePlaneMemoryInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImagePlaneMemoryRequirementsInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSamplerYcbcrConversionFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSamplerYcbcrConversionImageFormatProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorUpdateTemplateEntry& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorUpdateTemplateCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExternalMemoryProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceExternalImageFormatInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExternalImageFormatProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceExternalBufferInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExternalBufferProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceIDProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExternalMemoryImageCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExternalMemoryBufferCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExportMemoryAllocateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceExternalFenceInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExternalFenceProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExportFenceCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExportSemaphoreCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceExternalSemaphoreInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExternalSemaphoreProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMaintenance3Properties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorSetLayoutSupport& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderDrawParametersFeatures& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceVulkan11Features& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceVulkan11Properties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceVulkan12Features& value);
void EncodeStruct(ParameterEncoder* encoder, const VkConformanceVersion& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceVulkan12Properties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageFormatListCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAttachmentDescription2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAttachmentReference2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubpassDescription2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubpassDependency2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassCreateInfo2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubpassBeginInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubpassEndInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevice8BitStorageFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDriverProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderAtomicInt64Features& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderFloat16Int8Features& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFloatControlsProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorSetLayoutBindingFlagsCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDescriptorIndexingFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDescriptorIndexingProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorSetVariableDescriptorCountAllocateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorSetVariableDescriptorCountLayoutSupport& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubpassDescriptionDepthStencilResolve& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDepthStencilResolveProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceScalarBlockLayoutFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageStencilUsageCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSamplerReductionModeCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSamplerFilterMinmaxProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceVulkanMemoryModelFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceImagelessFramebufferFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkFramebufferAttachmentImageInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkFramebufferAttachmentsCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassAttachmentBeginInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceUniformBufferStandardLayoutFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAttachmentReferenceStencilLayout& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAttachmentDescriptionStencilLayout& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceHostQueryResetFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceTimelineSemaphoreFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceTimelineSemaphoreProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSemaphoreTypeCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkTimelineSemaphoreSubmitInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSemaphoreWaitInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSemaphoreSignalInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceBufferDeviceAddressFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBufferDeviceAddressInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBufferOpaqueCaptureAddressCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryOpaqueCaptureAddressAllocateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceMemoryOpaqueCaptureAddressInfo& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceVulkan13Features& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceVulkan13Properties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineCreationFeedback& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineCreationFeedbackCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderTerminateInvocationFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceToolProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePrivateDataFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDevicePrivateDataCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPrivateDataSlotCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePipelineCreationCacheControlFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryBarrier2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBufferMemoryBarrier2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageMemoryBarrier2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDependencyInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSemaphoreSubmitInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCommandBufferSubmitInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubmitInfo2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSynchronization2Features& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceImageRobustnessFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBufferCopy2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCopyBufferInfo2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageCopy2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCopyImageInfo2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBufferImageCopy2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCopyBufferToImageInfo2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCopyImageToBufferInfo2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageBlit2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBlitImageInfo2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageResolve2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkResolveImageInfo2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSubgroupSizeControlFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSubgroupSizeControlProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineShaderStageRequiredSubgroupSizeCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceInlineUniformBlockFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceInlineUniformBlockProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkWriteDescriptorSetInlineUniformBlock& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorPoolInlineUniformBlockCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceTextureCompressionASTCHDRFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderingAttachmentInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderingInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineRenderingCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDynamicRenderingFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCommandBufferInheritanceRenderingInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderIntegerDotProductFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderIntegerDotProductProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceTexelBufferAlignmentProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkFormatProperties3& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMaintenance4Features& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMaintenance4Properties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceBufferMemoryRequirements& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceImageMemoryRequirements& value);

void EncodeStruct(ParameterEncoder* encoder, const VkSurfaceCapabilitiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSurfaceFormatKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkSwapchainCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPresentInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageSwapchainCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindImageMemorySwapchainInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAcquireNextImageInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceGroupPresentCapabilitiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceGroupPresentInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceGroupSwapchainCreateInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDisplayModeParametersKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDisplayModeCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDisplayModePropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDisplayPlaneCapabilitiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDisplayPlanePropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDisplayPropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDisplaySurfaceCreateInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDisplayPresentInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkXlibSurfaceCreateInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkXcbSurfaceCreateInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkWaylandSurfaceCreateInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkAndroidSurfaceCreateInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkWin32SurfaceCreateInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkQueueFamilyQueryResultStatusPropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkQueueFamilyVideoPropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoProfileInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoProfileListInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoCapabilitiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceVideoFormatInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoFormatPropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoPictureResourceInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoReferenceSlotInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoSessionMemoryRequirementsKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindVideoSessionMemoryInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoSessionCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoSessionParametersCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoSessionParametersUpdateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoBeginCodingInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEndCodingInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoCodingControlInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkVideoDecodeCapabilitiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoDecodeUsageInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoDecodeInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkVideoDecodeH264ProfileInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoDecodeH264CapabilitiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoDecodeH264SessionParametersAddInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoDecodeH264SessionParametersCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoDecodeH264PictureInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoDecodeH264DpbSlotInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkRenderingFragmentShadingRateAttachmentInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderingFragmentDensityMapAttachmentInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAttachmentSampleCountInfoAMD& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMultiviewPerViewAttributesInfoNVX& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImportMemoryWin32HandleInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExportMemoryWin32HandleInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryWin32HandlePropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryGetWin32HandleInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImportMemoryFdInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryFdPropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryGetFdInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkWin32KeyedMutexAcquireReleaseInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImportSemaphoreWin32HandleInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExportSemaphoreWin32HandleInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkD3D12FenceSubmitInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSemaphoreGetWin32HandleInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImportSemaphoreFdInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSemaphoreGetFdInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePushDescriptorPropertiesKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkRectLayerKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPresentRegionKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPresentRegionsKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkSharedPresentSurfaceCapabilitiesKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImportFenceWin32HandleInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExportFenceWin32HandleInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkFenceGetWin32HandleInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImportFenceFdInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkFenceGetFdInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePerformanceQueryFeaturesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePerformanceQueryPropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPerformanceCounterKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPerformanceCounterDescriptionKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkQueryPoolPerformanceCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAcquireProfilingLockInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPerformanceQuerySubmitInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSurfaceInfo2KHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSurfaceCapabilities2KHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSurfaceFormat2KHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDisplayProperties2KHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDisplayPlaneProperties2KHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDisplayModeProperties2KHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDisplayPlaneInfo2KHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDisplayPlaneCapabilities2KHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePortabilitySubsetFeaturesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePortabilitySubsetPropertiesKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderClockFeaturesKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkVideoDecodeH265ProfileInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoDecodeH265CapabilitiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoDecodeH265SessionParametersAddInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoDecodeH265SessionParametersCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoDecodeH265PictureInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoDecodeH265DpbSlotInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDeviceQueueGlobalPriorityCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkQueueFamilyGlobalPriorityPropertiesKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkFragmentShadingRateAttachmentInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineFragmentShadingRateStateCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFragmentShadingRateFeaturesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFragmentShadingRatePropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFragmentShadingRateKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkSurfaceProtectedCapabilitiesKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePresentWaitFeaturesKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineExecutablePropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineExecutableInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineExecutableStatisticKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineExecutableInternalRepresentationKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkMemoryMapInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryUnmapInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPipelineLibraryCreateInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPresentIdKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePresentIdFeaturesKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeCapabilitiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkQueryPoolVideoEncodeFeedbackCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeUsageInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeRateControlLayerInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeRateControlInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeQualityLevelPropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeQualityLevelInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeSessionParametersGetInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeSessionParametersFeedbackInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkQueueFamilyCheckpointProperties2NV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCheckpointData2NV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkTraceRaysIndirectCommand2KHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMaintenance5FeaturesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMaintenance5PropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderingAreaInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageSubresource2KHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceImageSubresourceInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubresourceLayout2KHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineCreateFlags2CreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBufferUsageFlags2CreateInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkCooperativeMatrixPropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceCooperativeMatrixFeaturesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceCooperativeMatrixPropertiesKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDebugReportCallbackCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPipelineRasterizationStateRasterizationOrderAMD& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDebugMarkerObjectNameInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDebugMarkerObjectTagInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDebugMarkerMarkerInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDedicatedAllocationImageCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDedicatedAllocationBufferCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDedicatedAllocationMemoryAllocateInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceTransformFeedbackFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceTransformFeedbackPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineRasterizationStateStreamCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImageViewHandleInfoNVX& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageViewAddressPropertiesNVX& value);

void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH264CapabilitiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH264QpEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH264QualityLevelPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH264SessionCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH264SessionParametersAddInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH264SessionParametersCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH264SessionParametersGetInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH264SessionParametersFeedbackInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH264NaluSliceInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH264PictureInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH264DpbSlotInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH264ProfileInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH264RateControlInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH264FrameSizeEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH264RateControlLayerInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH264GopRemainingFrameInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH265CapabilitiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH265SessionCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH265QpEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH265QualityLevelPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH265SessionParametersAddInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH265SessionParametersCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH265SessionParametersGetInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH265SessionParametersFeedbackInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH265NaluSliceSegmentInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH265PictureInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH265DpbSlotInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH265ProfileInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH265RateControlInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH265FrameSizeEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH265RateControlLayerInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVideoEncodeH265GopRemainingFrameInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkTextureLODGatherFormatPropertiesAMD& value);

void EncodeStruct(ParameterEncoder* encoder, const VkShaderResourceUsageAMD& value);
void EncodeStruct(ParameterEncoder* encoder, const VkShaderStatisticsInfoAMD& value);

void EncodeStruct(ParameterEncoder* encoder, const VkStreamDescriptorSurfaceCreateInfoGGP& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceCornerSampledImageFeaturesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkExternalImageFormatPropertiesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkExternalMemoryImageCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExportMemoryAllocateInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImportMemoryWin32HandleInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExportMemoryWin32HandleInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkWin32KeyedMutexAcquireReleaseInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkValidationFlagsEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkViSurfaceCreateInfoNN& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImageViewASTCDecodeModeEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceASTCDecodeFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePipelineRobustnessFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePipelineRobustnessPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineRobustnessCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkConditionalRenderingBeginInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceConditionalRenderingFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCommandBufferInheritanceConditionalRenderingInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkViewportWScalingNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineViewportWScalingStateCreateInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkSurfaceCapabilities2EXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDisplayPowerInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceEventInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDisplayEventInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSwapchainCounterCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkRefreshCycleDurationGOOGLE& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPastPresentationTimingGOOGLE& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPresentTimeGOOGLE& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPresentTimesInfoGOOGLE& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX& value);

void EncodeStruct(ParameterEncoder* encoder, const VkViewportSwizzleNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineViewportSwizzleStateCreateInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDiscardRectanglePropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineDiscardRectangleStateCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceConservativeRasterizationPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineRasterizationConservativeStateCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDepthClipEnableFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineRasterizationDepthClipStateCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkXYColorEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkHdrMetadataEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkIOSSurfaceCreateInfoMVK& value);

void EncodeStruct(ParameterEncoder* encoder, const VkMacOSSurfaceCreateInfoMVK& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDebugUtilsLabelEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDebugUtilsObjectNameInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDebugUtilsMessengerCallbackDataEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDebugUtilsMessengerCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDebugUtilsObjectTagInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkAndroidHardwareBufferUsageANDROID& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAndroidHardwareBufferPropertiesANDROID& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAndroidHardwareBufferFormatPropertiesANDROID& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImportAndroidHardwareBufferInfoANDROID& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryGetAndroidHardwareBufferInfoANDROID& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExternalFormatANDROID& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAndroidHardwareBufferFormatProperties2ANDROID& value);

void EncodeStruct(ParameterEncoder* encoder, const VkSampleLocationEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSampleLocationsInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAttachmentSampleLocationsEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubpassSampleLocationsEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassSampleLocationsBeginInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineSampleLocationsStateCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSampleLocationsPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMultisamplePropertiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineColorBlendAdvancedStateCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPipelineCoverageToColorStateCreateInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPipelineCoverageModulationStateCreateInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDrmFormatModifierPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDrmFormatModifierPropertiesListEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceImageDrmFormatModifierInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageDrmFormatModifierListCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageDrmFormatModifierExplicitCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageDrmFormatModifierPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDrmFormatModifierProperties2EXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDrmFormatModifierPropertiesList2EXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkValidationCacheCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkShaderModuleValidationCacheCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkShadingRatePaletteNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineViewportShadingRateImageStateCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShadingRateImageFeaturesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShadingRateImagePropertiesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCoarseSampleLocationNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCoarseSampleOrderCustomNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkRayTracingShaderGroupCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRayTracingPipelineCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkGeometryTrianglesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkGeometryAABBNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkGeometryDataNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkGeometryNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindAccelerationStructureMemoryInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkWriteDescriptorSetAccelerationStructureNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureMemoryRequirementsInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceRayTracingPropertiesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkTransformMatrixKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAabbPositionsKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureInstanceKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineRepresentativeFragmentTestStateCreateInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceImageViewImageFormatInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkFilterCubicImageViewImageFormatPropertiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImportMemoryHostPointerInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryHostPointerPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceExternalMemoryHostPropertiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPipelineCompilerControlCreateInfoAMD& value);

void EncodeStruct(ParameterEncoder* encoder, const VkCalibratedTimestampInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderCorePropertiesAMD& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDeviceMemoryOverallocationCreateInfoAMD& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVertexInputBindingDivisorDescriptionEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineVertexInputDivisorStateCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPresentFrameTokenGGP& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMeshShaderFeaturesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMeshShaderPropertiesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDrawMeshTasksIndirectCommandNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderImageFootprintFeaturesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPipelineViewportExclusiveScissorStateCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceExclusiveScissorFeaturesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkQueueFamilyCheckpointPropertiesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCheckpointDataNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL& value);

void EncodeStruct(ParameterEncoder* encoder, const VkInitializePerformanceApiInfoINTEL& value);
void EncodeStruct(ParameterEncoder* encoder, const VkQueryPoolPerformanceQueryCreateInfoINTEL& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPerformanceMarkerInfoINTEL& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPerformanceStreamMarkerInfoINTEL& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPerformanceOverrideInfoINTEL& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPerformanceConfigurationAcquireInfoINTEL& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePCIBusInfoPropertiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDisplayNativeHdrSurfaceCapabilitiesAMD& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSwapchainDisplayNativeHdrCreateInfoAMD& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImagePipeSurfaceCreateInfoFUCHSIA& value);

void EncodeStruct(ParameterEncoder* encoder, const VkMetalSurfaceCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFragmentDensityMapFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFragmentDensityMapPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassFragmentDensityMapCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderCoreProperties2AMD& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceCoherentMemoryFeaturesAMD& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMemoryBudgetPropertiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMemoryPriorityFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryPriorityAllocateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBufferDeviceAddressCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkValidationFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkCooperativeMatrixPropertiesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceCooperativeMatrixFeaturesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceCooperativeMatrixPropertiesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceCoverageReductionModeFeaturesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineCoverageReductionStateCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkFramebufferMixedSamplesCombinationNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceProvokingVertexFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceProvokingVertexPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkSurfaceFullScreenExclusiveInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSurfaceCapabilitiesFullScreenExclusiveEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSurfaceFullScreenExclusiveWin32InfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkHeadlessSurfaceCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceLineRasterizationFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceLineRasterizationPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineRasterizationLineStateCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceIndexTypeUint8FeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceHostImageCopyFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceHostImageCopyPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryToImageCopyEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageToMemoryCopyEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCopyMemoryToImageInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCopyImageToMemoryInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCopyImageToImageInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkHostImageLayoutTransitionInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubresourceHostMemcpySizeEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkHostImageCopyDevicePerformanceQueryEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkSurfacePresentModeEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSurfacePresentScalingCapabilitiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSurfacePresentModeCompatibilityEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSwapchainPresentFenceInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSwapchainPresentModesCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSwapchainPresentModeInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSwapchainPresentScalingCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkReleaseSwapchainImagesInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkGraphicsShaderGroupCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkGraphicsPipelineShaderGroupsCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindShaderGroupIndirectCommandNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindIndexBufferIndirectCommandNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindVertexBufferIndirectCommandNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSetStateFlagsIndirectCommandNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkIndirectCommandsStreamNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkIndirectCommandsLayoutTokenNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkIndirectCommandsLayoutCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkGeneratedCommandsInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkGeneratedCommandsMemoryRequirementsInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceInheritedViewportScissorFeaturesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCommandBufferInheritanceViewportScissorInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassTransformBeginInfoQCOM& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCommandBufferInheritanceRenderPassTransformInfoQCOM& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDepthBiasControlFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDepthBiasInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDepthBiasRepresentationInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceMemoryReportCallbackDataEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceDeviceMemoryReportCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceRobustness2FeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceRobustness2PropertiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkSamplerCustomBorderColorCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceCustomBorderColorPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceCustomBorderColorFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePresentBarrierFeaturesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSurfaceCapabilitiesPresentBarrierNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSwapchainPresentBarrierCreateInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDiagnosticsConfigFeaturesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceDiagnosticsConfigCreateInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkQueryLowLatencySupportNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkGraphicsPipelineLibraryCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineFragmentShadingRateEnumStateCreateInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureGeometryMotionTrianglesDataNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureMotionInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureMatrixMotionInstanceNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSRTDataNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureSRTMotionInstanceNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkCopyCommandTransformInfoQCOM& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceImageCompressionControlFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageCompressionControlEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageCompressionPropertiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevice4444FormatsFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFaultFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceFaultCountsEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceFaultAddressInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceFaultVendorInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceFaultInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceFaultVendorBinaryHeaderVersionOneEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDirectFBSurfaceCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMutableDescriptorTypeListEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMutableDescriptorTypeCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVertexInputBindingDescription2EXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVertexInputAttributeDescription2EXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDrmPropertiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceAddressBindingReportFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceAddressBindingCallbackDataEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDepthClipControlFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineViewportDepthClipControlCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImportMemoryZirconHandleInfoFUCHSIA& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryZirconHandlePropertiesFUCHSIA& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryGetZirconHandleInfoFUCHSIA& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImportSemaphoreZirconHandleInfoFUCHSIA& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSemaphoreGetZirconHandleInfoFUCHSIA& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI& value);

void EncodeStruct(ParameterEncoder* encoder, const VkMemoryGetRemoteAddressInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFrameBoundaryFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkFrameBoundaryEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubpassResolvePerformanceQueryEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMultisampledRenderToSingleSampledInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkScreenSurfaceCreateInfoQNX& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceColorWriteEnableFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineColorWriteCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceImageViewMinLodFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageViewMinLodCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMultiDrawFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMultiDrawPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMultiDrawInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMultiDrawIndexedInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderTileImageFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderTileImagePropertiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkMicromapUsageEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMicromapBuildInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMicromapCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceOpacityMicromapFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceOpacityMicromapPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMicromapVersionInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCopyMicromapToMemoryInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCopyMemoryToMicromapInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCopyMicromapInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMicromapBuildSizesInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureTrianglesOpacityMicromapEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMicromapTriangleEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDisplacementMicromapFeaturesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDisplacementMicromapPropertiesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureTrianglesDisplacementMicromapNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSamplerBorderColorComponentMappingCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderCorePropertiesARM& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageViewSlicedCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorSetBindingReferenceVALVE& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorSetLayoutHostMappingInfoVALVE& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDepthClampZeroOneFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubpassFragmentDensityMapOffsetEndInfoQCOM& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkComputePipelineIndirectBufferInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineIndirectDeviceAddressInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindPipelineIndirectCommandNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceLinearColorAttachmentFeaturesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImageViewSampleWeightCreateInfoQCOM& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceImageProcessingFeaturesQCOM& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceImageProcessingPropertiesQCOM& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceNestedCommandBufferFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceNestedCommandBufferPropertiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkExternalMemoryAcquireUnmodifiedEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceExtendedDynamicState3PropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkColorBlendEquationEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkColorBlendAdvancedEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassCreationControlEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassCreationFeedbackInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassCreationFeedbackCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassSubpassFeedbackInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassSubpassFeedbackCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDirectDriverLoadingInfoLUNARG& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDirectDriverLoadingListLUNARG& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineShaderStageModuleIdentifierCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkShaderModuleIdentifierEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceOpticalFlowFeaturesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceOpticalFlowPropertiesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkOpticalFlowImageFormatInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkOpticalFlowImageFormatPropertiesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkOpticalFlowSessionCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkOpticalFlowSessionCreatePrivateDataInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkOpticalFlowExecuteInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceLegacyDitheringFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePipelineProtectedAccessFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceExternalFormatResolveFeaturesANDROID& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceExternalFormatResolvePropertiesANDROID& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAndroidHardwareBufferFormatResolvePropertiesANDROID& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderObjectFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderObjectPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkShaderCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceTilePropertiesFeaturesQCOM& value);
void EncodeStruct(ParameterEncoder* encoder, const VkTilePropertiesQCOM& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceAmigoProfilingFeaturesSEC& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAmigoProfilingSubmitInfoSEC& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceImageProcessing2FeaturesQCOM& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceImageProcessing2PropertiesQCOM& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSamplerBlockMatchWindowCreateInfoQCOM& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceCubicWeightsFeaturesQCOM& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSamplerCubicWeightsCreateInfoQCOM& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBlitImageCubicWeightsInfoQCOM& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceYcbcrDegammaFeaturesQCOM& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceCubicClampFeaturesQCOM& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceLayeredDriverPropertiesMSFT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureBuildRangeInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureGeometryTrianglesDataKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureGeometryAabbsDataKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureGeometryInstancesDataKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureBuildGeometryInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkWriteDescriptorSetAccelerationStructureKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceAccelerationStructureFeaturesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceAccelerationStructurePropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureDeviceAddressInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureVersionInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCopyAccelerationStructureToMemoryInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCopyMemoryToAccelerationStructureInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCopyAccelerationStructureInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureBuildSizesInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkRayTracingShaderGroupCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRayTracingPipelineInterfaceCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRayTracingPipelineCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceRayTracingPipelineFeaturesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceRayTracingPipelinePropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkStridedDeviceAddressRegionKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkTraceRaysIndirectCommandKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceRayQueryFeaturesKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMeshShaderFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMeshShaderPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDrawMeshTasksIndirectCommandEXT& value);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
