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

#ifndef  GFXRECON_GENERATED_VULKAN_STRUCT_HANDLE_MAPPERS_H
#define  GFXRECON_GENERATED_VULKAN_STRUCT_HANDLE_MAPPERS_H

#include "decode/common_consumer_base.h"
#include "decode/common_object_info_table.h"
#include "decode/vulkan_pnext_node.h"
#include "format/platform_types.h"
#include "decode/custom_vulkan_struct_handle_mappers.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"
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
GFXRECON_BEGIN_NAMESPACE(decode)

void MapStructHandles(Decoded_StdVideoH264SpsVuiFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoH264HrdParameters* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoH264SequenceParameterSetVui* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoH264SpsFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoH264ScalingLists* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoH264SequenceParameterSet* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoH264PpsFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoH264PictureParameterSet* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoDecodeH264PictureInfoFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoDecodeH264PictureInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoDecodeH264ReferenceInfoFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoDecodeH264ReferenceInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoEncodeH264WeightTableFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoEncodeH264WeightTable* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoEncodeH264SliceHeaderFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoEncodeH264PictureInfoFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoEncodeH264ReferenceInfoFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoEncodeH264ReferenceListsInfoFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoEncodeH264RefListModEntry* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoEncodeH264RefPicMarkingEntry* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoEncodeH264ReferenceListsInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoEncodeH264PictureInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoEncodeH264ReferenceInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoEncodeH264SliceHeader* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoVP9ColorConfigFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoVP9ColorConfig* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoVP9LoopFilterFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoVP9LoopFilter* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoVP9SegmentationFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoVP9Segmentation* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoDecodeVP9PictureInfoFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoDecodeVP9PictureInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoAV1ColorConfigFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoAV1ColorConfig* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoAV1TimingInfoFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoAV1TimingInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoAV1SequenceHeaderFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoAV1SequenceHeader* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoAV1LoopFilterFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoAV1LoopFilter* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoAV1QuantizationFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoAV1Quantization* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoAV1Segmentation* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoAV1TileInfoFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoAV1TileInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoAV1CDEF* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoAV1LoopRestoration* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoAV1GlobalMotion* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoAV1FilmGrainFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoAV1FilmGrain* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoDecodeAV1PictureInfoFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoDecodeAV1PictureInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoDecodeAV1ReferenceInfoFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoDecodeAV1ReferenceInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoEncodeAV1ExtensionHeader* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoEncodeAV1DecoderModelInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoEncodeAV1OperatingPointInfoFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoEncodeAV1OperatingPointInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoEncodeAV1PictureInfoFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoEncodeAV1PictureInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoEncodeAV1ReferenceInfoFlags* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_StdVideoEncodeAV1ReferenceInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExtent2D* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExtent3D* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkOffset2D* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkOffset3D* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRect2D* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferMemoryBarrier* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageSubresourceRange* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageMemoryBarrier* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryBarrier* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAllocationCallbacks* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkApplicationInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFormatProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageFormatProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkInstanceCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryHeap* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryType* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceLimits* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMemoryProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSparseProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkQueueFamilyProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceQueueCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExtensionProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkLayerProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSubmitInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMappedMemoryRange* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryAllocateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryRequirements* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSparseMemoryBind* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSparseBufferMemoryBindInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSparseImageOpaqueMemoryBindInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageSubresource* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSparseImageMemoryBind* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSparseImageMemoryBindInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindSparseInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSparseImageFormatProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSparseImageMemoryRequirements* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFenceCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkQueryPoolCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSubresourceLayout* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkComponentMapping* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageViewCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCommandPoolCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCommandBufferAllocateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCommandBufferInheritanceInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCommandBufferBeginInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferCopy* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageSubresourceLayers* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferImageCopy* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageCopy* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDispatchIndirectCommand* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineCacheHeaderVersionOne* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkEventCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferViewCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkShaderModuleCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineCacheCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSpecializationMapEntry* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSpecializationInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineShaderStageCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkComputePipelineCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPushConstantRange* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineLayoutCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSamplerCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyDescriptorSet* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorBufferInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorPoolSize* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorPoolCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorSetAllocateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorSetLayoutBinding* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorSetLayoutCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDrawIndexedIndirectCommand* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDrawIndirectCommand* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVertexInputBindingDescription* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVertexInputAttributeDescription* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineVertexInputStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineInputAssemblyStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineTessellationStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkViewport* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineViewportStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineRasterizationStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineMultisampleStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkStencilOpState* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineDepthStencilStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineColorBlendAttachmentState* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineColorBlendStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineDynamicStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGraphicsPipelineCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAttachmentDescription* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAttachmentReference* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFramebufferCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSubpassDescription* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSubpassDependency* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkClearDepthStencilValue* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkClearAttachment* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkClearRect* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageBlit* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageResolve* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassBeginInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindBufferMemoryInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindImageMemoryInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryDedicatedRequirements* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryDedicatedAllocateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryAllocateFlagsInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceGroupCommandBufferBeginInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceGroupSubmitInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceGroupBindSparseInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindBufferMemoryDeviceGroupInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindImageMemoryDeviceGroupInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceGroupProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceGroupDeviceCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferMemoryRequirementsInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageMemoryRequirementsInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageSparseMemoryRequirementsInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryRequirements2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSparseImageMemoryRequirements2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFeatures2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceProperties2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFormatProperties2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageFormatProperties2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImageFormatInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkQueueFamilyProperties2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMemoryProperties2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSparseImageFormatProperties2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSparseImageFormatInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageViewUsageCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceProtectedMemoryFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceProtectedMemoryProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceQueueInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkProtectedSubmitInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindImagePlaneMemoryInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImagePlaneMemoryRequirementsInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExternalMemoryProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceExternalImageFormatInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExternalImageFormatProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceExternalBufferInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExternalBufferProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceIDProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExternalMemoryImageCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExternalMemoryBufferCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExportMemoryAllocateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceExternalFenceInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExternalFenceProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExportFenceCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExportSemaphoreCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceExternalSemaphoreInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExternalSemaphoreProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSubgroupProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevice16BitStorageFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVariablePointersFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorUpdateTemplateEntry* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorUpdateTemplateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance3Properties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorSetLayoutSupport* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSamplerYcbcrConversionCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSamplerYcbcrConversionInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSamplerYcbcrConversionImageFormatProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceGroupRenderPassBeginInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePointClippingProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkInputAttachmentAspectReference* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassInputAttachmentAspectCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineTessellationDomainOriginStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassMultiviewCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMultiviewFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMultiviewProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderDrawParametersFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVulkan11Features* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVulkan11Properties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVulkan12Features* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkConformanceVersion* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVulkan12Properties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageFormatListCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDriverProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceHostQueryResetFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceTimelineSemaphoreProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreTypeCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkTimelineSemaphoreSubmitInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreWaitInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreSignalInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferDeviceAddressInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferOpaqueCaptureAddressCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevice8BitStorageFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderAtomicInt64Features* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderFloat16Int8Features* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFloatControlsProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorIndexingFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorIndexingProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupport* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSamplerReductionModeCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSamplerFilterMinmaxProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAttachmentDescription2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAttachmentReference2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSubpassDescription2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSubpassDependency2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassCreateInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSubpassBeginInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSubpassEndInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSubpassDescriptionDepthStencilResolve* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDepthStencilResolveProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageStencilUsageCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImagelessFramebufferFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFramebufferAttachmentImageInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFramebufferAttachmentsCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassAttachmentBeginInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAttachmentReferenceStencilLayout* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAttachmentDescriptionStencilLayout* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVulkan13Features* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVulkan13Properties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceToolProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePrivateDataFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDevicePrivateDataCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPrivateDataSlotCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryBarrier2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferMemoryBarrier2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageMemoryBarrier2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDependencyInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreSubmitInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCommandBufferSubmitInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSubmitInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSynchronization2Features* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferCopy2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyBufferInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageCopy2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyImageInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferImageCopy2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyBufferToImageInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyImageToBufferInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFormatProperties3* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance4Features* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance4Properties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceBufferMemoryRequirements* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceImageMemoryRequirements* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineCreationFeedback* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineCreationFeedbackCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderTerminateInvocationFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePipelineCreationCacheControlFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImageRobustnessFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSubgroupSizeControlFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSubgroupSizeControlProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceInlineUniformBlockFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceInlineUniformBlockProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWriteDescriptorSetInlineUniformBlock* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorPoolInlineUniformBlockCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderIntegerDotProductFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderIntegerDotProductProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceTexelBufferAlignmentProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageBlit2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBlitImageInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageResolve2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkResolveImageInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingAttachmentInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineRenderingCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDynamicRenderingFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCommandBufferInheritanceRenderingInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVulkan14Features* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVulkan14Properties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceQueueGlobalPriorityCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceGlobalPriorityQueryFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkQueueFamilyGlobalPriorityProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceIndexTypeUint8Features* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryMapInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryUnmapInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance5Features* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance5Properties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageSubresource2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceImageSubresourceInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSubresourceLayout2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferUsageFlags2CreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance6Features* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance6Properties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindMemoryStatus* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceHostImageCopyFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceHostImageCopyProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyImageToImageInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkHostImageLayoutTransitionInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSubresourceHostMemcpySize* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkHostImageCopyDevicePerformanceQuery* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderSubgroupRotateFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderFloatControls2Features* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderExpectAssumeFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineCreateFlags2CreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePushDescriptorProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindDescriptorSetsInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPushConstantsInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPushDescriptorSetInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePipelineProtectedAccessFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePipelineRobustnessFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePipelineRobustnessProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineRobustnessCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceLineRasterizationFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceLineRasterizationProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineRasterizationLineStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVertexAttributeDivisorProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVertexInputBindingDivisorDescription* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineVertexInputDivisorStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVertexAttributeDivisorFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingAreaInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDynamicRenderingLocalReadFeatures* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingAttachmentLocationInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingInputAttachmentIndexInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSurfaceCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSurfaceFormatKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSwapchainCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPresentInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageSwapchainCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindImageMemorySwapchainInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAcquireNextImageInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceGroupPresentCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceGroupPresentInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceGroupSwapchainCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayModeParametersKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayModeCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayModePropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPlaneCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPlanePropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplaySurfaceCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPresentInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkXlibSurfaceCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkXcbSurfaceCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWaylandSurfaceCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAndroidSurfaceCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWin32SurfaceCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkQueueFamilyQueryResultStatusPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkQueueFamilyVideoPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoProfileInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoProfileListInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVideoFormatInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoFormatPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoPictureResourceInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoReferenceSlotInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoSessionMemoryRequirementsKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindVideoSessionMemoryInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoSessionCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoSessionParametersCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoSessionParametersUpdateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoBeginCodingInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEndCodingInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoCodingControlInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeUsageInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeH264CapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeH264QpKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeH264QualityLevelPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeH264SessionCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeH264SessionParametersAddInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeH264SessionParametersCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeH264SessionParametersGetInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeH264SessionParametersFeedbackInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeH264NaluSliceInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeH264PictureInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeH264DpbSlotInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeH264ProfileInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeH264RateControlInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeH264FrameSizeKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeH264RateControlLayerInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeH264GopRemainingFrameInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeH264ProfileInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeH264CapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeH264SessionParametersAddInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeH264SessionParametersCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeH264PictureInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeH264DpbSlotInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportMemoryWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExportMemoryWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryWin32HandlePropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryGetWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportMemoryFdInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryFdPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryGetFdInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportSemaphoreWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExportSemaphoreWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkD3D12FenceSubmitInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreGetWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportSemaphoreFdInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreGetFdInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRectLayerKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPresentRegionKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPresentRegionsKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSharedPresentSurfaceCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportFenceWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExportFenceWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFenceGetWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportFenceFdInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFenceGetFdInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePerformanceQueryFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePerformanceQueryPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPerformanceCounterKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPerformanceCounterDescriptionKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkQueryPoolPerformanceCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAcquireProfilingLockInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPerformanceQuerySubmitInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSurfaceInfo2KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSurfaceCapabilities2KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSurfaceFormat2KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayProperties2KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPlaneProperties2KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayModeProperties2KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPlaneInfo2KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPlaneCapabilities2KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderBfloat16FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePortabilitySubsetFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePortabilitySubsetPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderClockFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFragmentShadingRateAttachmentInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineFragmentShadingRateStateCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShadingRateFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShadingRatePropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShadingRateKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderQuadControlFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSurfaceProtectedCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePresentWaitFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineExecutablePropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineExecutableInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineExecutableStatisticKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineExecutableInternalRepresentationKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineLibraryCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPresentIdKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePresentIdFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeUsageInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeRateControlLayerInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeRateControlInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeQualityLevelPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeQualityLevelInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeSessionParametersGetInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeSessionParametersFeedbackInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkTraceRaysIndirectCommand2KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSurfaceCapabilitiesPresentId2KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPresentId2KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePresentId2FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSurfaceCapabilitiesPresentWait2KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePresentWait2FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPresentWait2InfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePipelineBinaryFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePipelineBinaryPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDevicePipelineBinaryInternalCacheControlKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineBinaryKeyKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineBinaryDataKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineBinaryKeysAndDataKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineBinaryCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineBinaryInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkReleaseCapturedPipelineDataInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineBinaryDataInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineBinaryHandlesInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSurfacePresentModeKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSurfacePresentScalingCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSurfacePresentModeCompatibilityKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSwapchainPresentFenceInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSwapchainPresentModesCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSwapchainPresentModeInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSwapchainPresentScalingCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkReleaseSwapchainImagesInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCooperativeMatrixPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeAV1ProfileInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeAV1CapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeAV1SessionParametersCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeAV1PictureInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeAV1DpbSlotInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVideoEncodeAV1FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeAV1CapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeAV1QIndexKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeAV1QualityLevelPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeAV1SessionCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeAV1SessionParametersCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeAV1PictureInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeAV1DpbSlotInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeAV1ProfileInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeAV1FrameSizeKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeAV1GopRemainingFrameInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeAV1RateControlInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeAV1RateControlLayerInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVideoDecodeVP9FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeVP9ProfileInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeVP9CapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeVP9PictureInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVideoMaintenance1FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoInlineQueryInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAttachmentFeedbackLoopInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCalibratedTimestampInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSetDescriptorBufferOffsetsInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkStridedDeviceAddressRangeKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMemoryIndirectCommandKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMemoryIndirectInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMemoryToImageIndirectCommandKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMemoryToImageIndirectInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeIntraRefreshCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeSessionIntraRefreshCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeIntraRefreshInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoReferenceIntraRefreshInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeQuantizationMapCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoFormatQuantizationMapPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeQuantizationMapInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeH264QuantizationMapCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeH265QuantizationMapCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoFormatH265QuantizationMapPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeAV1QuantizationMapCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoFormatAV1QuantizationMapPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance7FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance7PropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceLayeredApiPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceLayeredApiPropertiesListKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceLayeredApiVulkanPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryBarrierAccessFlags3KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance8FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderFmaFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance9FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance9PropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkQueueFamilyOwnershipTransferPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRobustness2FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRobustness2PropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance10FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance10PropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingEndInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingAttachmentFlagsInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkResolveImageModeInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDebugReportCallbackCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineRasterizationStateRasterizationOrderAMD* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDebugMarkerObjectNameInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDebugMarkerObjectTagInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDebugMarkerMarkerInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDedicatedAllocationImageCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDedicatedAllocationBufferCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDedicatedAllocationMemoryAllocateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageViewHandleInfoNVX* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageViewAddressPropertiesNVX* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkTextureLODGatherFormatPropertiesAMD* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkShaderResourceUsageAMD* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkShaderStatisticsInfoAMD* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkStreamDescriptorSurfaceCreateInfoGGP* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExternalImageFormatPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExternalMemoryImageCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExportMemoryAllocateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportMemoryWin32HandleInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExportMemoryWin32HandleInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkValidationFlagsEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkViSurfaceCreateInfoNN* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageViewASTCDecodeModeEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkConditionalRenderingBeginInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkViewportWScalingNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineViewportWScalingStateCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSurfaceCapabilities2EXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPowerInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceEventInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayEventInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSwapchainCounterCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRefreshCycleDurationGOOGLE* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPastPresentationTimingGOOGLE* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPresentTimeGOOGLE* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPresentTimesInfoGOOGLE* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMultiviewPerViewAttributesInfoNVX* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkViewportSwizzleNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineViewportSwizzleStateCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkXYColorEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkHdrMetadataEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIOSSurfaceCreateInfoMVK* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMacOSSurfaceCreateInfoMVK* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDebugUtilsLabelEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDebugUtilsObjectNameInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDebugUtilsMessengerCallbackDataEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDebugUtilsMessengerCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDebugUtilsObjectTagInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAndroidHardwareBufferUsageANDROID* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAndroidHardwareBufferPropertiesANDROID* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportAndroidHardwareBufferInfoANDROID* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExternalFormatANDROID* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAndroidHardwareBufferFormatProperties2ANDROID* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAttachmentSampleCountInfoAMD* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSampleLocationEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSampleLocationsInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAttachmentSampleLocationsEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSubpassSampleLocationsEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassSampleLocationsBeginInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineSampleLocationsStateCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMultisamplePropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineCoverageToColorStateCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineCoverageModulationStateCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDrmFormatModifierPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDrmFormatModifierPropertiesListEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageDrmFormatModifierListCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageDrmFormatModifierPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDrmFormatModifierProperties2EXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDrmFormatModifierPropertiesList2EXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkValidationCacheCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkShaderModuleValidationCacheCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkShadingRatePaletteNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCoarseSampleLocationNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCoarseSampleOrderCustomNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRayTracingShaderGroupCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRayTracingPipelineCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeometryTrianglesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeometryAABBNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeometryDataNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeometryNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindAccelerationStructureMemoryInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWriteDescriptorSetAccelerationStructureNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureMemoryRequirementsInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkTransformMatrixKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAabbPositionsKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureInstanceKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportMemoryHostPointerInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryHostPointerPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineCompilerControlCreateInfoAMD* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderCorePropertiesAMD* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceMemoryOverallocationCreateInfoAMD* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPresentFrameTokenGGP* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMeshShaderFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMeshShaderPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDrawMeshTasksIndirectCommandNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkQueueFamilyCheckpointPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCheckpointDataNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkQueueFamilyCheckpointProperties2NV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCheckpointData2NV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePresentTimingFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPresentTimingSurfaceCapabilitiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSwapchainCalibratedTimestampInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSwapchainTimingPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSwapchainTimeDomainPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPastPresentationTimingInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPresentStageTimeEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPastPresentationTimingEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPastPresentationTimingPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPresentTimingInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPresentTimingsInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkInitializePerformanceApiInfoINTEL* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPerformanceMarkerInfoINTEL* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPerformanceStreamMarkerInfoINTEL* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPerformanceOverrideInfoINTEL* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPerformanceConfigurationAcquireInfoINTEL* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayNativeHdrSurfaceCapabilitiesAMD* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSwapchainDisplayNativeHdrCreateInfoAMD* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMetalSurfaceCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderCoreProperties2AMD* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryPriorityAllocateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferDeviceAddressCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkValidationFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCooperativeMatrixPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineCoverageReductionStateCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFramebufferMixedSamplesCombinationNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceProvokingVertexFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceProvokingVertexPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSurfaceFullScreenExclusiveInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSurfaceCapabilitiesFullScreenExclusiveEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSurfaceFullScreenExclusiveWin32InfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkHeadlessSurfaceCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMapMemoryPlacedPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryMapPlacedInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGraphicsShaderGroupCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindShaderGroupIndirectCommandNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindIndexBufferIndirectCommandNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindVertexBufferIndirectCommandNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSetStateFlagsIndirectCommandNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectCommandsStreamNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectCommandsLayoutTokenNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectCommandsLayoutCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeneratedCommandsInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceInheritedViewportScissorFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCommandBufferInheritanceViewportScissorInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassTransformBeginInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCommandBufferInheritanceRenderPassTransformInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDepthBiasControlFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDepthBiasInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDepthBiasRepresentationInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceMemoryReportCallbackDataEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceDeviceMemoryReportCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSamplerCustomBorderColorCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCustomBorderColorPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePresentBarrierFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSurfaceCapabilitiesPresentBarrierNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSwapchainPresentBarrierCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceDiagnosticsConfigCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceTileShadingFeaturesQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceTileShadingPropertiesQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassTileShadingCreateInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPerTileBeginInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPerTileEndInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDispatchTileInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkQueryLowLatencySupportNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorBufferPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorBufferFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorAddressInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorBufferBindingInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorBufferBindingPushDescriptorBufferHandleEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferCaptureDescriptorDataInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageCaptureDescriptorDataInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageViewCaptureDescriptorDataInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSamplerCaptureDescriptorDataInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkOpaqueCaptureDescriptorDataCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureCaptureDescriptorDataInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGraphicsPipelineLibraryCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineFragmentShadingRateEnumStateCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureGeometryMotionTrianglesDataNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureMotionInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureMatrixMotionInstanceNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSRTDataNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureSRTMotionInstanceNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyCommandTransformInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImageCompressionControlFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageCompressionControlEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageCompressionPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevice4444FormatsFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFaultFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceFaultCountsEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceFaultAddressInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceFaultVendorInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceFaultInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceFaultVendorBinaryHeaderVersionOneEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDirectFBSurfaceCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMutableDescriptorTypeListEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMutableDescriptorTypeCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVertexInputBindingDescription2EXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVertexInputAttributeDescription2EXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDrmPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceAddressBindingReportFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceAddressBindingCallbackDataEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDepthClipControlFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineViewportDepthClipControlCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportMemoryZirconHandleInfoFUCHSIA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryZirconHandlePropertiesFUCHSIA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryGetZirconHandleInfoFUCHSIA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryGetRemoteAddressInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFrameBoundaryFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFrameBoundaryEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSubpassResolvePerformanceQueryEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMultisampledRenderToSingleSampledInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkScreenSurfaceCreateInfoQNX* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceColorWriteEnableFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineColorWriteCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeRgbConversionCapabilitiesVALVE* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeProfileRgbConversionInfoVALVE* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeSessionRgbConversionCreateInfoVALVE* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImageViewMinLodFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageViewMinLodCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMultiDrawFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMultiDrawPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMultiDrawInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMultiDrawIndexedInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderTileImageFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderTileImagePropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMicromapUsageEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMicromapBuildInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMicromapCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceOpacityMicromapFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceOpacityMicromapPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMicromapVersionInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMicromapToMemoryInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMemoryToMicromapInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMicromapInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMicromapBuildSizesInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMicromapTriangleEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDisplacementMicromapFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDisplacementMicromapPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureTrianglesDisplacementMicromapNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSamplerBorderColorComponentMappingCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderCorePropertiesARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceQueueShaderCoreControlCreateInfoARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSchedulingControlsFeaturesARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSchedulingControlsPropertiesARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageViewSlicedCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorSetBindingReferenceVALVE* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRenderPassStripedFeaturesARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRenderPassStripedPropertiesARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassStripeInfoARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassStripeBeginInfoARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassStripeSubmitInfoARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassFragmentDensityMapOffsetEndInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkComputePipelineIndirectBufferInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineIndirectDeviceAddressInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindPipelineIndirectCommandNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureGeometryLinearSweptSpheresDataNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureGeometrySpheresDataNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceLinearColorAttachmentFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageViewSampleWeightCreateInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImageProcessingFeaturesQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImageProcessingPropertiesQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceNestedCommandBufferFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceNestedCommandBufferPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExternalMemoryAcquireUnmodifiedEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkColorBlendEquationEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkColorBlendAdvancedEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassCreationControlEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassCreationFeedbackInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassCreationFeedbackCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassSubpassFeedbackInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassSubpassFeedbackCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDirectDriverLoadingInfoLUNARG* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDirectDriverLoadingListLUNARG* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineShaderStageModuleIdentifierCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkShaderModuleIdentifierEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceOpticalFlowFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceOpticalFlowPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkOpticalFlowImageFormatInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkOpticalFlowImageFormatPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkOpticalFlowSessionCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkOpticalFlowSessionCreatePrivateDataInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkOpticalFlowExecuteInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceLegacyDitheringFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAndroidHardwareBufferFormatResolvePropertiesANDROID* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceAntiLagFeaturesAMD* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAntiLagPresentationInfoAMD* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAntiLagDataAMD* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderObjectFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderObjectPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkShaderCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDepthClampRangeEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceTilePropertiesFeaturesQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkTilePropertiesQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceAmigoProfilingFeaturesSEC* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAmigoProfilingSubmitInfoSEC* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCooperativeVectorPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCooperativeVectorFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCooperativeVectorPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkConvertCooperativeVectorMatrixInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkLayerSettingsCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkLatencySleepModeInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkLatencySleepInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSetLatencyMarkerInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkLatencyTimingsFrameReportNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGetLatencyMarkerInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkLatencySubmissionPresentIdNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSwapchainLatencyCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkOutOfBandQueueTypeInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkLatencySurfaceCapabilitiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDataGraphFeaturesARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDataGraphPipelineConstantARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDataGraphPipelineResourceInfoARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDataGraphPipelineCompilerControlCreateInfoARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDataGraphPipelineCreateInfoARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDataGraphPipelineShaderModuleCreateInfoARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDataGraphPipelineSessionCreateInfoARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDataGraphPipelineSessionBindPointRequirementsInfoARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDataGraphPipelineSessionBindPointRequirementARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDataGraphPipelineSessionMemoryRequirementsInfoARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindDataGraphPipelineSessionMemoryInfoARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDataGraphPipelineInfoARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDataGraphPipelinePropertyQueryResultARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDataGraphPipelineIdentifierCreateInfoARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDataGraphPipelineDispatchInfoARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDataGraphProcessingEngineARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDataGraphOperationSupportARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkQueueFamilyDataGraphPropertiesARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDataGraphProcessingEngineCreateInfoARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkQueueFamilyDataGraphProcessingEnginePropertiesARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePerStageDescriptorSetFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImageProcessing2FeaturesQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImageProcessing2PropertiesQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSamplerBlockMatchWindowCreateInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCubicWeightsFeaturesQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSamplerCubicWeightsCreateInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBlitImageCubicWeightsInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCubicClampFeaturesQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceLayeredDriverPropertiesMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceTileMemoryHeapFeaturesQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceTileMemoryHeapPropertiesQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkTileMemoryRequirementsQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkTileMemoryBindInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkTileMemorySizeInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDecompressMemoryRegionEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDecompressMemoryInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMemoryDecompressionFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMemoryDecompressionPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplaySurfaceStereoCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayModeStereoPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRawAccessChainsFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCommandBufferInheritanceFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderFloat8FeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingValidationFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPartitionedAccelerationStructureFlagsNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkStridedDeviceAddressNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBuildPartitionedAccelerationStructureIndirectCommandNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPartitionedAccelerationStructureWriteInstanceDataNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPartitionedAccelerationStructureUpdateInstanceDataNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPartitionedAccelerationStructureWritePartitionTranslationDataNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWriteDescriptorSetPartitionedAccelerationStructureNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPartitionedAccelerationStructureInstancesInputNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBuildPartitionedAccelerationStructureInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureBuildSizesInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeneratedCommandsMemoryRequirementsInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectExecutionSetPipelineInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectExecutionSetShaderLayoutInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectExecutionSetShaderInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeneratedCommandsInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWriteIndirectExecutionSetPipelineEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectCommandsPushConstantTokenEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectCommandsVertexBufferTokenEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectCommandsIndexBufferTokenEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectCommandsExecutionSetTokenEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectCommandsLayoutCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDrawIndirectCountIndirectCommandEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindVertexBufferIndirectCommandEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindIndexBufferIndirectCommandEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeneratedCommandsPipelineInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeneratedCommandsShaderInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWriteIndirectExecutionSetShaderEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImageAlignmentControlFeaturesMESA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImageAlignmentControlPropertiesMESA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageAlignmentControlCreateInfoMESA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPushConstantBankInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePushConstantBankFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePushConstantBankPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDepthClampControlFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineViewportDepthClampControlCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceHdrVividFeaturesHUAWEI* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkHdrVividDynamicMetadataHUAWEI* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCooperativeMatrixFlexibleDimensionsPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCooperativeMatrix2FeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCooperativeMatrix2PropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePipelineOpacityMicromapFeaturesARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportMemoryMetalHandleInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryMetalHandlePropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryGetMetalHandleInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePerformanceCountersByRegionFeaturesARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePerformanceCountersByRegionPropertiesARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPerformanceCounterARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPerformanceCounterDescriptionARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassPerformanceCountersByRegionBeginInfoARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFormatPackFeaturesARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineFragmentDensityMapLayeredCreateInfoVALVE* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSetPresentConfigNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePresentMeteringFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShader64BitIndexingFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCustomResolveFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBeginCustomResolveInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCustomResolveCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineCacheHeaderVersionDataGraphQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDataGraphPipelineBuiltinModelCreateInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDataGraphModelFeaturesQCOM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderLongVectorFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderLongVectorPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkComputeOccupancyPriorityParametersNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureBuildRangeInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureGeometryTrianglesDataKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureGeometryAabbsDataKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureGeometryInstancesDataKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWriteDescriptorSetAccelerationStructureKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceAccelerationStructureFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceAccelerationStructurePropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureDeviceAddressInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureVersionInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyAccelerationStructureToMemoryInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMemoryToAccelerationStructureInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyAccelerationStructureInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRayTracingShaderGroupCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRayTracingPipelineInterfaceCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRayTracingPipelineCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingPipelineFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingPipelinePropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkStridedDeviceAddressRegionKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkTraceRaysIndirectCommandKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRayQueryFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMeshShaderFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMeshShaderPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDrawMeshTasksIndirectCommandEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapPNextStructHandles(PNextNode* value, const CommonObjectInfoTable& object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_VkPhysicalDeviceGroupProperties* id_wrapper, const VkPhysicalDeviceGroupProperties* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayPropertiesKHR* id_wrapper, const VkDisplayPropertiesKHR* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayPlanePropertiesKHR* id_wrapper, const VkDisplayPlanePropertiesKHR* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayModePropertiesKHR* id_wrapper, const VkDisplayModePropertiesKHR* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayProperties2KHR* id_wrapper, const VkDisplayProperties2KHR* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayPlaneProperties2KHR* id_wrapper, const VkDisplayPlaneProperties2KHR* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayModeProperties2KHR* id_wrapper, const VkDisplayModeProperties2KHR* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_VkPipelineBinaryHandlesInfoKHR* id_wrapper, const VkPipelineBinaryHandlesInfoKHR* handle_struct, CommonObjectInfoTable* object_info_table);

void PushRecaptureStructHandleIds(const Decoded_VkPhysicalDeviceGroupProperties* id_wrapper, CommonConsumerBase* consumer);

void PushRecaptureStructHandleIds(const Decoded_VkDisplayPropertiesKHR* id_wrapper, CommonConsumerBase* consumer);

void PushRecaptureStructHandleIds(const Decoded_VkDisplayPlanePropertiesKHR* id_wrapper, CommonConsumerBase* consumer);

void PushRecaptureStructHandleIds(const Decoded_VkDisplayModePropertiesKHR* id_wrapper, CommonConsumerBase* consumer);

void PushRecaptureStructHandleIds(const Decoded_VkDisplayProperties2KHR* id_wrapper, CommonConsumerBase* consumer);

void PushRecaptureStructHandleIds(const Decoded_VkDisplayPlaneProperties2KHR* id_wrapper, CommonConsumerBase* consumer);

void PushRecaptureStructHandleIds(const Decoded_VkDisplayModeProperties2KHR* id_wrapper, CommonConsumerBase* consumer);

void PushRecaptureStructHandleIds(const Decoded_VkPipelineBinaryHandlesInfoKHR* id_wrapper, CommonConsumerBase* consumer);

void SetStructHandleLengths(Decoded_VkPhysicalDeviceGroupProperties* wrapper);

void SetStructHandleLengths(Decoded_VkPipelineBinaryHandlesInfoKHR* wrapper);

#include "decode/common_struct_handle_mappers.h"
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_VULKAN_STRUCT_HANDLE_MAPPERS_H
