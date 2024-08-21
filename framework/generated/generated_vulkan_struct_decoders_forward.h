/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2023 LunarG, Inc.
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

#ifndef  GFXRECON_GENERATED_VULKAN_STRUCT_DECODERS_FORWARD_H
#define  GFXRECON_GENERATED_VULKAN_STRUCT_DECODERS_FORWARD_H

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
GFXRECON_BEGIN_NAMESPACE(decode)

struct Decoded_StdVideoH264SpsVuiFlags;
struct Decoded_StdVideoH264HrdParameters;
struct Decoded_StdVideoH264SequenceParameterSetVui;
struct Decoded_StdVideoH264SpsFlags;
struct Decoded_StdVideoH264ScalingLists;
struct Decoded_StdVideoH264SequenceParameterSet;
struct Decoded_StdVideoH264PpsFlags;
struct Decoded_StdVideoH264PictureParameterSet;
struct Decoded_StdVideoDecodeH264PictureInfoFlags;
struct Decoded_StdVideoDecodeH264PictureInfo;
struct Decoded_StdVideoDecodeH264ReferenceInfoFlags;
struct Decoded_StdVideoDecodeH264ReferenceInfo;
struct Decoded_StdVideoEncodeH264WeightTableFlags;
struct Decoded_StdVideoEncodeH264WeightTable;
struct Decoded_StdVideoEncodeH264SliceHeaderFlags;
struct Decoded_StdVideoEncodeH264PictureInfoFlags;
struct Decoded_StdVideoEncodeH264ReferenceInfoFlags;
struct Decoded_StdVideoEncodeH264ReferenceListsInfoFlags;
struct Decoded_StdVideoEncodeH264RefListModEntry;
struct Decoded_StdVideoEncodeH264RefPicMarkingEntry;
struct Decoded_StdVideoEncodeH264ReferenceListsInfo;
struct Decoded_StdVideoEncodeH264PictureInfo;
struct Decoded_StdVideoEncodeH264ReferenceInfo;
struct Decoded_StdVideoEncodeH264SliceHeader;
struct Decoded_StdVideoH265ProfileTierLevelFlags;
struct Decoded_StdVideoH265ProfileTierLevel;
struct Decoded_StdVideoH265DecPicBufMgr;
struct Decoded_StdVideoH265SubLayerHrdParameters;
struct Decoded_StdVideoH265HrdFlags;
struct Decoded_StdVideoH265HrdParameters;
struct Decoded_StdVideoH265VpsFlags;
struct Decoded_StdVideoH265VideoParameterSet;
struct Decoded_StdVideoH265ScalingLists;
struct Decoded_StdVideoH265ShortTermRefPicSetFlags;
struct Decoded_StdVideoH265ShortTermRefPicSet;
struct Decoded_StdVideoH265LongTermRefPicsSps;
struct Decoded_StdVideoH265SpsVuiFlags;
struct Decoded_StdVideoH265SequenceParameterSetVui;
struct Decoded_StdVideoH265PredictorPaletteEntries;
struct Decoded_StdVideoH265SpsFlags;
struct Decoded_StdVideoH265SequenceParameterSet;
struct Decoded_StdVideoH265PpsFlags;
struct Decoded_StdVideoH265PictureParameterSet;
struct Decoded_StdVideoDecodeH265PictureInfoFlags;
struct Decoded_StdVideoDecodeH265PictureInfo;
struct Decoded_StdVideoDecodeH265ReferenceInfoFlags;
struct Decoded_StdVideoDecodeH265ReferenceInfo;
struct Decoded_StdVideoEncodeH265WeightTableFlags;
struct Decoded_StdVideoEncodeH265WeightTable;
struct Decoded_StdVideoEncodeH265LongTermRefPics;
struct Decoded_StdVideoEncodeH265SliceSegmentHeaderFlags;
struct Decoded_StdVideoEncodeH265SliceSegmentHeader;
struct Decoded_StdVideoEncodeH265ReferenceListsInfoFlags;
struct Decoded_StdVideoEncodeH265ReferenceListsInfo;
struct Decoded_StdVideoEncodeH265PictureInfoFlags;
struct Decoded_StdVideoEncodeH265PictureInfo;
struct Decoded_StdVideoEncodeH265ReferenceInfoFlags;
struct Decoded_StdVideoEncodeH265ReferenceInfo;
struct Decoded_StdVideoAV1ColorConfigFlags;
struct Decoded_StdVideoAV1ColorConfig;
struct Decoded_StdVideoAV1TimingInfoFlags;
struct Decoded_StdVideoAV1TimingInfo;
struct Decoded_StdVideoAV1SequenceHeaderFlags;
struct Decoded_StdVideoAV1SequenceHeader;
struct Decoded_StdVideoAV1LoopFilterFlags;
struct Decoded_StdVideoAV1LoopFilter;
struct Decoded_StdVideoAV1QuantizationFlags;
struct Decoded_StdVideoAV1Quantization;
struct Decoded_StdVideoAV1Segmentation;
struct Decoded_StdVideoAV1TileInfoFlags;
struct Decoded_StdVideoAV1TileInfo;
struct Decoded_StdVideoAV1CDEF;
struct Decoded_StdVideoAV1LoopRestoration;
struct Decoded_StdVideoAV1GlobalMotion;
struct Decoded_StdVideoAV1FilmGrainFlags;
struct Decoded_StdVideoAV1FilmGrain;
struct Decoded_StdVideoDecodeAV1PictureInfoFlags;
struct Decoded_StdVideoDecodeAV1PictureInfo;
struct Decoded_StdVideoDecodeAV1ReferenceInfoFlags;
struct Decoded_StdVideoDecodeAV1ReferenceInfo;
struct Decoded_VkExtent2D;
struct Decoded_VkExtent3D;
struct Decoded_VkOffset2D;
struct Decoded_VkOffset3D;
struct Decoded_VkRect2D;
struct Decoded_VkBufferMemoryBarrier;
struct Decoded_VkDispatchIndirectCommand;
struct Decoded_VkDrawIndexedIndirectCommand;
struct Decoded_VkDrawIndirectCommand;
struct Decoded_VkImageSubresourceRange;
struct Decoded_VkImageMemoryBarrier;
struct Decoded_VkMemoryBarrier;
struct Decoded_VkPipelineCacheHeaderVersionOne;
struct Decoded_VkAllocationCallbacks;
struct Decoded_VkApplicationInfo;
struct Decoded_VkFormatProperties;
struct Decoded_VkImageFormatProperties;
struct Decoded_VkInstanceCreateInfo;
struct Decoded_VkMemoryHeap;
struct Decoded_VkMemoryType;
struct Decoded_VkPhysicalDeviceFeatures;
struct Decoded_VkPhysicalDeviceLimits;
struct Decoded_VkPhysicalDeviceMemoryProperties;
struct Decoded_VkPhysicalDeviceSparseProperties;
struct Decoded_VkPhysicalDeviceProperties;
struct Decoded_VkQueueFamilyProperties;
struct Decoded_VkDeviceQueueCreateInfo;
struct Decoded_VkDeviceCreateInfo;
struct Decoded_VkExtensionProperties;
struct Decoded_VkLayerProperties;
struct Decoded_VkSubmitInfo;
struct Decoded_VkMappedMemoryRange;
struct Decoded_VkMemoryAllocateInfo;
struct Decoded_VkMemoryRequirements;
struct Decoded_VkSparseMemoryBind;
struct Decoded_VkSparseBufferMemoryBindInfo;
struct Decoded_VkSparseImageOpaqueMemoryBindInfo;
struct Decoded_VkImageSubresource;
struct Decoded_VkSparseImageMemoryBind;
struct Decoded_VkSparseImageMemoryBindInfo;
struct Decoded_VkBindSparseInfo;
struct Decoded_VkSparseImageFormatProperties;
struct Decoded_VkSparseImageMemoryRequirements;
struct Decoded_VkFenceCreateInfo;
struct Decoded_VkSemaphoreCreateInfo;
struct Decoded_VkEventCreateInfo;
struct Decoded_VkQueryPoolCreateInfo;
struct Decoded_VkBufferCreateInfo;
struct Decoded_VkBufferViewCreateInfo;
struct Decoded_VkImageCreateInfo;
struct Decoded_VkSubresourceLayout;
struct Decoded_VkComponentMapping;
struct Decoded_VkImageViewCreateInfo;
struct Decoded_VkShaderModuleCreateInfo;
struct Decoded_VkPipelineCacheCreateInfo;
struct Decoded_VkSpecializationMapEntry;
struct Decoded_VkSpecializationInfo;
struct Decoded_VkPipelineShaderStageCreateInfo;
struct Decoded_VkComputePipelineCreateInfo;
struct Decoded_VkVertexInputBindingDescription;
struct Decoded_VkVertexInputAttributeDescription;
struct Decoded_VkPipelineVertexInputStateCreateInfo;
struct Decoded_VkPipelineInputAssemblyStateCreateInfo;
struct Decoded_VkPipelineTessellationStateCreateInfo;
struct Decoded_VkViewport;
struct Decoded_VkPipelineViewportStateCreateInfo;
struct Decoded_VkPipelineRasterizationStateCreateInfo;
struct Decoded_VkPipelineMultisampleStateCreateInfo;
struct Decoded_VkStencilOpState;
struct Decoded_VkPipelineDepthStencilStateCreateInfo;
struct Decoded_VkPipelineColorBlendAttachmentState;
struct Decoded_VkPipelineColorBlendStateCreateInfo;
struct Decoded_VkPipelineDynamicStateCreateInfo;
struct Decoded_VkGraphicsPipelineCreateInfo;
struct Decoded_VkPushConstantRange;
struct Decoded_VkPipelineLayoutCreateInfo;
struct Decoded_VkSamplerCreateInfo;
struct Decoded_VkCopyDescriptorSet;
struct Decoded_VkDescriptorBufferInfo;
struct Decoded_VkDescriptorPoolSize;
struct Decoded_VkDescriptorPoolCreateInfo;
struct Decoded_VkDescriptorSetAllocateInfo;
struct Decoded_VkDescriptorSetLayoutBinding;
struct Decoded_VkDescriptorSetLayoutCreateInfo;
struct Decoded_VkAttachmentDescription;
struct Decoded_VkAttachmentReference;
struct Decoded_VkFramebufferCreateInfo;
struct Decoded_VkSubpassDescription;
struct Decoded_VkSubpassDependency;
struct Decoded_VkRenderPassCreateInfo;
struct Decoded_VkCommandPoolCreateInfo;
struct Decoded_VkCommandBufferAllocateInfo;
struct Decoded_VkCommandBufferInheritanceInfo;
struct Decoded_VkCommandBufferBeginInfo;
struct Decoded_VkBufferCopy;
struct Decoded_VkImageSubresourceLayers;
struct Decoded_VkBufferImageCopy;
struct Decoded_VkClearDepthStencilValue;
struct Decoded_VkClearAttachment;
struct Decoded_VkClearRect;
struct Decoded_VkImageBlit;
struct Decoded_VkImageCopy;
struct Decoded_VkImageResolve;
struct Decoded_VkRenderPassBeginInfo;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH264SpsVuiFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH264HrdParameters* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH264SequenceParameterSetVui* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH264SpsFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH264ScalingLists* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH264SequenceParameterSet* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH264PpsFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH264PictureParameterSet* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoDecodeH264PictureInfoFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoDecodeH264PictureInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoDecodeH264ReferenceInfoFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoDecodeH264ReferenceInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH264WeightTableFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH264WeightTable* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH264SliceHeaderFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH264PictureInfoFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH264ReferenceInfoFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH264ReferenceListsInfoFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH264RefListModEntry* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH264RefPicMarkingEntry* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH264ReferenceListsInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH264PictureInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH264ReferenceInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH264SliceHeader* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH265ProfileTierLevelFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH265ProfileTierLevel* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH265DecPicBufMgr* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH265SubLayerHrdParameters* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH265HrdFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH265HrdParameters* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH265VpsFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH265VideoParameterSet* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH265ScalingLists* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH265ShortTermRefPicSetFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH265ShortTermRefPicSet* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH265LongTermRefPicsSps* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH265SpsVuiFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH265SequenceParameterSetVui* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH265PredictorPaletteEntries* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH265SpsFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH265SequenceParameterSet* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH265PpsFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoH265PictureParameterSet* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoDecodeH265PictureInfoFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoDecodeH265PictureInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoDecodeH265ReferenceInfoFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoDecodeH265ReferenceInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH265WeightTableFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH265WeightTable* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH265LongTermRefPics* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH265SliceSegmentHeaderFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH265SliceSegmentHeader* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH265ReferenceListsInfoFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH265ReferenceListsInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH265PictureInfoFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH265PictureInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH265ReferenceInfoFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoEncodeH265ReferenceInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoAV1ColorConfigFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoAV1ColorConfig* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoAV1TimingInfoFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoAV1TimingInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoAV1SequenceHeaderFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoAV1SequenceHeader* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoAV1LoopFilterFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoAV1LoopFilter* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoAV1QuantizationFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoAV1Quantization* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoAV1Segmentation* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoAV1TileInfoFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoAV1TileInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoAV1CDEF* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoAV1LoopRestoration* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoAV1GlobalMotion* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoAV1FilmGrainFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoAV1FilmGrain* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoDecodeAV1PictureInfoFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoDecodeAV1PictureInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoDecodeAV1ReferenceInfoFlags* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_StdVideoDecodeAV1ReferenceInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExtent2D* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExtent3D* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkOffset2D* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkOffset3D* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRect2D* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBufferMemoryBarrier* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDispatchIndirectCommand* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDrawIndexedIndirectCommand* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDrawIndirectCommand* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageSubresourceRange* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageMemoryBarrier* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryBarrier* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineCacheHeaderVersionOne* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAllocationCallbacks* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkApplicationInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkFormatProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageFormatProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkInstanceCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryHeap* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryType* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceLimits* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMemoryProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSparseProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkQueueFamilyProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceQueueCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExtensionProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkLayerProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubmitInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMappedMemoryRange* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryAllocateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryRequirements* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSparseMemoryBind* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSparseBufferMemoryBindInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSparseImageOpaqueMemoryBindInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageSubresource* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSparseImageMemoryBind* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSparseImageMemoryBindInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindSparseInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSparseImageFormatProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSparseImageMemoryRequirements* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkFenceCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSemaphoreCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkEventCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkQueryPoolCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBufferCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBufferViewCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubresourceLayout* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkComponentMapping* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageViewCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkShaderModuleCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineCacheCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSpecializationMapEntry* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSpecializationInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineShaderStageCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkComputePipelineCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVertexInputBindingDescription* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVertexInputAttributeDescription* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineVertexInputStateCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineInputAssemblyStateCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineTessellationStateCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkViewport* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineViewportStateCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineRasterizationStateCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineMultisampleStateCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkStencilOpState* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineDepthStencilStateCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineColorBlendAttachmentState* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineColorBlendStateCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineDynamicStateCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkGraphicsPipelineCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPushConstantRange* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineLayoutCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSamplerCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCopyDescriptorSet* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorBufferInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorPoolSize* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorPoolCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorSetAllocateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorSetLayoutBinding* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorSetLayoutCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAttachmentDescription* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAttachmentReference* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkFramebufferCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubpassDescription* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubpassDependency* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCommandPoolCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCommandBufferAllocateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCommandBufferInheritanceInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCommandBufferBeginInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBufferCopy* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageSubresourceLayers* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBufferImageCopy* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkClearDepthStencilValue* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkClearAttachment* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkClearRect* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageBlit* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageCopy* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageResolve* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassBeginInfo* wrapper);

struct Decoded_VkPhysicalDeviceSubgroupProperties;
struct Decoded_VkBindBufferMemoryInfo;
struct Decoded_VkBindImageMemoryInfo;
struct Decoded_VkPhysicalDevice16BitStorageFeatures;
struct Decoded_VkMemoryDedicatedRequirements;
struct Decoded_VkMemoryDedicatedAllocateInfo;
struct Decoded_VkMemoryAllocateFlagsInfo;
struct Decoded_VkDeviceGroupRenderPassBeginInfo;
struct Decoded_VkDeviceGroupCommandBufferBeginInfo;
struct Decoded_VkDeviceGroupSubmitInfo;
struct Decoded_VkDeviceGroupBindSparseInfo;
struct Decoded_VkBindBufferMemoryDeviceGroupInfo;
struct Decoded_VkBindImageMemoryDeviceGroupInfo;
struct Decoded_VkPhysicalDeviceGroupProperties;
struct Decoded_VkDeviceGroupDeviceCreateInfo;
struct Decoded_VkBufferMemoryRequirementsInfo2;
struct Decoded_VkImageMemoryRequirementsInfo2;
struct Decoded_VkImageSparseMemoryRequirementsInfo2;
struct Decoded_VkMemoryRequirements2;
struct Decoded_VkSparseImageMemoryRequirements2;
struct Decoded_VkPhysicalDeviceFeatures2;
struct Decoded_VkPhysicalDeviceProperties2;
struct Decoded_VkFormatProperties2;
struct Decoded_VkImageFormatProperties2;
struct Decoded_VkPhysicalDeviceImageFormatInfo2;
struct Decoded_VkQueueFamilyProperties2;
struct Decoded_VkPhysicalDeviceMemoryProperties2;
struct Decoded_VkSparseImageFormatProperties2;
struct Decoded_VkPhysicalDeviceSparseImageFormatInfo2;
struct Decoded_VkPhysicalDevicePointClippingProperties;
struct Decoded_VkInputAttachmentAspectReference;
struct Decoded_VkRenderPassInputAttachmentAspectCreateInfo;
struct Decoded_VkImageViewUsageCreateInfo;
struct Decoded_VkPipelineTessellationDomainOriginStateCreateInfo;
struct Decoded_VkRenderPassMultiviewCreateInfo;
struct Decoded_VkPhysicalDeviceMultiviewFeatures;
struct Decoded_VkPhysicalDeviceMultiviewProperties;
struct Decoded_VkPhysicalDeviceVariablePointersFeatures;
struct Decoded_VkPhysicalDeviceProtectedMemoryFeatures;
struct Decoded_VkPhysicalDeviceProtectedMemoryProperties;
struct Decoded_VkDeviceQueueInfo2;
struct Decoded_VkProtectedSubmitInfo;
struct Decoded_VkSamplerYcbcrConversionCreateInfo;
struct Decoded_VkSamplerYcbcrConversionInfo;
struct Decoded_VkBindImagePlaneMemoryInfo;
struct Decoded_VkImagePlaneMemoryRequirementsInfo;
struct Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures;
struct Decoded_VkSamplerYcbcrConversionImageFormatProperties;
struct Decoded_VkDescriptorUpdateTemplateEntry;
struct Decoded_VkDescriptorUpdateTemplateCreateInfo;
struct Decoded_VkExternalMemoryProperties;
struct Decoded_VkPhysicalDeviceExternalImageFormatInfo;
struct Decoded_VkExternalImageFormatProperties;
struct Decoded_VkPhysicalDeviceExternalBufferInfo;
struct Decoded_VkExternalBufferProperties;
struct Decoded_VkPhysicalDeviceIDProperties;
struct Decoded_VkExternalMemoryImageCreateInfo;
struct Decoded_VkExternalMemoryBufferCreateInfo;
struct Decoded_VkExportMemoryAllocateInfo;
struct Decoded_VkPhysicalDeviceExternalFenceInfo;
struct Decoded_VkExternalFenceProperties;
struct Decoded_VkExportFenceCreateInfo;
struct Decoded_VkExportSemaphoreCreateInfo;
struct Decoded_VkPhysicalDeviceExternalSemaphoreInfo;
struct Decoded_VkExternalSemaphoreProperties;
struct Decoded_VkPhysicalDeviceMaintenance3Properties;
struct Decoded_VkDescriptorSetLayoutSupport;
struct Decoded_VkPhysicalDeviceShaderDrawParametersFeatures;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSubgroupProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindBufferMemoryInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindImageMemoryInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevice16BitStorageFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryDedicatedRequirements* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryDedicatedAllocateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryAllocateFlagsInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceGroupRenderPassBeginInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceGroupCommandBufferBeginInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceGroupSubmitInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceGroupBindSparseInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindBufferMemoryDeviceGroupInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindImageMemoryDeviceGroupInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceGroupProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceGroupDeviceCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBufferMemoryRequirementsInfo2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageMemoryRequirementsInfo2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageSparseMemoryRequirementsInfo2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryRequirements2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSparseImageMemoryRequirements2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFeatures2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceProperties2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkFormatProperties2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageFormatProperties2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceImageFormatInfo2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkQueueFamilyProperties2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMemoryProperties2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSparseImageFormatProperties2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSparseImageFormatInfo2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePointClippingProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkInputAttachmentAspectReference* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassInputAttachmentAspectCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageViewUsageCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineTessellationDomainOriginStateCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassMultiviewCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMultiviewFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMultiviewProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVariablePointersFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceProtectedMemoryFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceProtectedMemoryProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceQueueInfo2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkProtectedSubmitInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSamplerYcbcrConversionCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSamplerYcbcrConversionInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindImagePlaneMemoryInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImagePlaneMemoryRequirementsInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSamplerYcbcrConversionImageFormatProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorUpdateTemplateEntry* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorUpdateTemplateCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExternalMemoryProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalImageFormatInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExternalImageFormatProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalBufferInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExternalBufferProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceIDProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExternalMemoryImageCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExternalMemoryBufferCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExportMemoryAllocateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalFenceInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExternalFenceProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExportFenceCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExportSemaphoreCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalSemaphoreInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExternalSemaphoreProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMaintenance3Properties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorSetLayoutSupport* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderDrawParametersFeatures* wrapper);

struct Decoded_VkPhysicalDeviceVulkan11Features;
struct Decoded_VkPhysicalDeviceVulkan11Properties;
struct Decoded_VkPhysicalDeviceVulkan12Features;
struct Decoded_VkConformanceVersion;
struct Decoded_VkPhysicalDeviceVulkan12Properties;
struct Decoded_VkImageFormatListCreateInfo;
struct Decoded_VkAttachmentDescription2;
struct Decoded_VkAttachmentReference2;
struct Decoded_VkSubpassDescription2;
struct Decoded_VkSubpassDependency2;
struct Decoded_VkRenderPassCreateInfo2;
struct Decoded_VkSubpassBeginInfo;
struct Decoded_VkSubpassEndInfo;
struct Decoded_VkPhysicalDevice8BitStorageFeatures;
struct Decoded_VkPhysicalDeviceDriverProperties;
struct Decoded_VkPhysicalDeviceShaderAtomicInt64Features;
struct Decoded_VkPhysicalDeviceShaderFloat16Int8Features;
struct Decoded_VkPhysicalDeviceFloatControlsProperties;
struct Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfo;
struct Decoded_VkPhysicalDeviceDescriptorIndexingFeatures;
struct Decoded_VkPhysicalDeviceDescriptorIndexingProperties;
struct Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfo;
struct Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupport;
struct Decoded_VkSubpassDescriptionDepthStencilResolve;
struct Decoded_VkPhysicalDeviceDepthStencilResolveProperties;
struct Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures;
struct Decoded_VkImageStencilUsageCreateInfo;
struct Decoded_VkSamplerReductionModeCreateInfo;
struct Decoded_VkPhysicalDeviceSamplerFilterMinmaxProperties;
struct Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures;
struct Decoded_VkPhysicalDeviceImagelessFramebufferFeatures;
struct Decoded_VkFramebufferAttachmentImageInfo;
struct Decoded_VkFramebufferAttachmentsCreateInfo;
struct Decoded_VkRenderPassAttachmentBeginInfo;
struct Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures;
struct Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures;
struct Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures;
struct Decoded_VkAttachmentReferenceStencilLayout;
struct Decoded_VkAttachmentDescriptionStencilLayout;
struct Decoded_VkPhysicalDeviceHostQueryResetFeatures;
struct Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures;
struct Decoded_VkPhysicalDeviceTimelineSemaphoreProperties;
struct Decoded_VkSemaphoreTypeCreateInfo;
struct Decoded_VkTimelineSemaphoreSubmitInfo;
struct Decoded_VkSemaphoreWaitInfo;
struct Decoded_VkSemaphoreSignalInfo;
struct Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures;
struct Decoded_VkBufferDeviceAddressInfo;
struct Decoded_VkBufferOpaqueCaptureAddressCreateInfo;
struct Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo;
struct Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVulkan11Features* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVulkan11Properties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVulkan12Features* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkConformanceVersion* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVulkan12Properties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageFormatListCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAttachmentDescription2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAttachmentReference2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubpassDescription2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubpassDependency2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassCreateInfo2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubpassBeginInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubpassEndInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevice8BitStorageFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDriverProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderAtomicInt64Features* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderFloat16Int8Features* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFloatControlsProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDescriptorIndexingFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDescriptorIndexingProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupport* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubpassDescriptionDepthStencilResolve* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDepthStencilResolveProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageStencilUsageCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSamplerReductionModeCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSamplerFilterMinmaxProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceImagelessFramebufferFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkFramebufferAttachmentImageInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkFramebufferAttachmentsCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassAttachmentBeginInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAttachmentReferenceStencilLayout* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAttachmentDescriptionStencilLayout* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceHostQueryResetFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceTimelineSemaphoreProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSemaphoreTypeCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkTimelineSemaphoreSubmitInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSemaphoreWaitInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSemaphoreSignalInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBufferDeviceAddressInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBufferOpaqueCaptureAddressCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo* wrapper);

struct Decoded_VkPhysicalDeviceVulkan13Features;
struct Decoded_VkPhysicalDeviceVulkan13Properties;
struct Decoded_VkPipelineCreationFeedback;
struct Decoded_VkPipelineCreationFeedbackCreateInfo;
struct Decoded_VkPhysicalDeviceShaderTerminateInvocationFeatures;
struct Decoded_VkPhysicalDeviceToolProperties;
struct Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures;
struct Decoded_VkPhysicalDevicePrivateDataFeatures;
struct Decoded_VkDevicePrivateDataCreateInfo;
struct Decoded_VkPrivateDataSlotCreateInfo;
struct Decoded_VkPhysicalDevicePipelineCreationCacheControlFeatures;
struct Decoded_VkMemoryBarrier2;
struct Decoded_VkBufferMemoryBarrier2;
struct Decoded_VkImageMemoryBarrier2;
struct Decoded_VkDependencyInfo;
struct Decoded_VkSemaphoreSubmitInfo;
struct Decoded_VkCommandBufferSubmitInfo;
struct Decoded_VkSubmitInfo2;
struct Decoded_VkPhysicalDeviceSynchronization2Features;
struct Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures;
struct Decoded_VkPhysicalDeviceImageRobustnessFeatures;
struct Decoded_VkBufferCopy2;
struct Decoded_VkCopyBufferInfo2;
struct Decoded_VkImageCopy2;
struct Decoded_VkCopyImageInfo2;
struct Decoded_VkBufferImageCopy2;
struct Decoded_VkCopyBufferToImageInfo2;
struct Decoded_VkCopyImageToBufferInfo2;
struct Decoded_VkImageBlit2;
struct Decoded_VkBlitImageInfo2;
struct Decoded_VkImageResolve2;
struct Decoded_VkResolveImageInfo2;
struct Decoded_VkPhysicalDeviceSubgroupSizeControlFeatures;
struct Decoded_VkPhysicalDeviceSubgroupSizeControlProperties;
struct Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo;
struct Decoded_VkPhysicalDeviceInlineUniformBlockFeatures;
struct Decoded_VkPhysicalDeviceInlineUniformBlockProperties;
struct Decoded_VkWriteDescriptorSetInlineUniformBlock;
struct Decoded_VkDescriptorPoolInlineUniformBlockCreateInfo;
struct Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeatures;
struct Decoded_VkRenderingAttachmentInfo;
struct Decoded_VkRenderingInfo;
struct Decoded_VkPipelineRenderingCreateInfo;
struct Decoded_VkPhysicalDeviceDynamicRenderingFeatures;
struct Decoded_VkCommandBufferInheritanceRenderingInfo;
struct Decoded_VkPhysicalDeviceShaderIntegerDotProductFeatures;
struct Decoded_VkPhysicalDeviceShaderIntegerDotProductProperties;
struct Decoded_VkPhysicalDeviceTexelBufferAlignmentProperties;
struct Decoded_VkFormatProperties3;
struct Decoded_VkPhysicalDeviceMaintenance4Features;
struct Decoded_VkPhysicalDeviceMaintenance4Properties;
struct Decoded_VkDeviceBufferMemoryRequirements;
struct Decoded_VkDeviceImageMemoryRequirements;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVulkan13Features* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVulkan13Properties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineCreationFeedback* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineCreationFeedbackCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderTerminateInvocationFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceToolProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePrivateDataFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDevicePrivateDataCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPrivateDataSlotCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePipelineCreationCacheControlFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryBarrier2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBufferMemoryBarrier2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageMemoryBarrier2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDependencyInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSemaphoreSubmitInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCommandBufferSubmitInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubmitInfo2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSynchronization2Features* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceImageRobustnessFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBufferCopy2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCopyBufferInfo2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageCopy2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCopyImageInfo2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBufferImageCopy2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCopyBufferToImageInfo2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCopyImageToBufferInfo2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageBlit2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBlitImageInfo2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageResolve2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkResolveImageInfo2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSubgroupSizeControlFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSubgroupSizeControlProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceInlineUniformBlockFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceInlineUniformBlockProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkWriteDescriptorSetInlineUniformBlock* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorPoolInlineUniformBlockCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderingAttachmentInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderingInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineRenderingCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDynamicRenderingFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCommandBufferInheritanceRenderingInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderIntegerDotProductFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderIntegerDotProductProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceTexelBufferAlignmentProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkFormatProperties3* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMaintenance4Features* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMaintenance4Properties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceBufferMemoryRequirements* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceImageMemoryRequirements* wrapper);

struct Decoded_VkSurfaceCapabilitiesKHR;
struct Decoded_VkSurfaceFormatKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSurfaceCapabilitiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSurfaceFormatKHR* wrapper);

struct Decoded_VkSwapchainCreateInfoKHR;
struct Decoded_VkPresentInfoKHR;
struct Decoded_VkImageSwapchainCreateInfoKHR;
struct Decoded_VkBindImageMemorySwapchainInfoKHR;
struct Decoded_VkAcquireNextImageInfoKHR;
struct Decoded_VkDeviceGroupPresentCapabilitiesKHR;
struct Decoded_VkDeviceGroupPresentInfoKHR;
struct Decoded_VkDeviceGroupSwapchainCreateInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSwapchainCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPresentInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageSwapchainCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindImageMemorySwapchainInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAcquireNextImageInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceGroupPresentCapabilitiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceGroupPresentInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceGroupSwapchainCreateInfoKHR* wrapper);

struct Decoded_VkDisplayModeParametersKHR;
struct Decoded_VkDisplayModeCreateInfoKHR;
struct Decoded_VkDisplayModePropertiesKHR;
struct Decoded_VkDisplayPlaneCapabilitiesKHR;
struct Decoded_VkDisplayPlanePropertiesKHR;
struct Decoded_VkDisplayPropertiesKHR;
struct Decoded_VkDisplaySurfaceCreateInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayModeParametersKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayModeCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayModePropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayPlaneCapabilitiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayPlanePropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayPropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplaySurfaceCreateInfoKHR* wrapper);

struct Decoded_VkDisplayPresentInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayPresentInfoKHR* wrapper);

struct Decoded_VkXlibSurfaceCreateInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkXlibSurfaceCreateInfoKHR* wrapper);

struct Decoded_VkXcbSurfaceCreateInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkXcbSurfaceCreateInfoKHR* wrapper);

struct Decoded_VkWaylandSurfaceCreateInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkWaylandSurfaceCreateInfoKHR* wrapper);

struct Decoded_VkAndroidSurfaceCreateInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAndroidSurfaceCreateInfoKHR* wrapper);

struct Decoded_VkWin32SurfaceCreateInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkWin32SurfaceCreateInfoKHR* wrapper);

struct Decoded_VkQueueFamilyQueryResultStatusPropertiesKHR;
struct Decoded_VkQueueFamilyVideoPropertiesKHR;
struct Decoded_VkVideoProfileInfoKHR;
struct Decoded_VkVideoProfileListInfoKHR;
struct Decoded_VkVideoCapabilitiesKHR;
struct Decoded_VkPhysicalDeviceVideoFormatInfoKHR;
struct Decoded_VkVideoFormatPropertiesKHR;
struct Decoded_VkVideoPictureResourceInfoKHR;
struct Decoded_VkVideoReferenceSlotInfoKHR;
struct Decoded_VkVideoSessionMemoryRequirementsKHR;
struct Decoded_VkBindVideoSessionMemoryInfoKHR;
struct Decoded_VkVideoSessionCreateInfoKHR;
struct Decoded_VkVideoSessionParametersCreateInfoKHR;
struct Decoded_VkVideoSessionParametersUpdateInfoKHR;
struct Decoded_VkVideoBeginCodingInfoKHR;
struct Decoded_VkVideoEndCodingInfoKHR;
struct Decoded_VkVideoCodingControlInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkQueueFamilyQueryResultStatusPropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkQueueFamilyVideoPropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoProfileInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoProfileListInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoCapabilitiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVideoFormatInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoFormatPropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoPictureResourceInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoReferenceSlotInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoSessionMemoryRequirementsKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindVideoSessionMemoryInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoSessionCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoSessionParametersCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoSessionParametersUpdateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoBeginCodingInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEndCodingInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoCodingControlInfoKHR* wrapper);

struct Decoded_VkVideoDecodeCapabilitiesKHR;
struct Decoded_VkVideoDecodeUsageInfoKHR;
struct Decoded_VkVideoDecodeInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoDecodeCapabilitiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoDecodeUsageInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoDecodeInfoKHR* wrapper);

struct Decoded_VkVideoEncodeH264CapabilitiesKHR;
struct Decoded_VkVideoEncodeH264QpKHR;
struct Decoded_VkVideoEncodeH264QualityLevelPropertiesKHR;
struct Decoded_VkVideoEncodeH264SessionCreateInfoKHR;
struct Decoded_VkVideoEncodeH264SessionParametersAddInfoKHR;
struct Decoded_VkVideoEncodeH264SessionParametersCreateInfoKHR;
struct Decoded_VkVideoEncodeH264SessionParametersGetInfoKHR;
struct Decoded_VkVideoEncodeH264SessionParametersFeedbackInfoKHR;
struct Decoded_VkVideoEncodeH264NaluSliceInfoKHR;
struct Decoded_VkVideoEncodeH264PictureInfoKHR;
struct Decoded_VkVideoEncodeH264DpbSlotInfoKHR;
struct Decoded_VkVideoEncodeH264ProfileInfoKHR;
struct Decoded_VkVideoEncodeH264RateControlInfoKHR;
struct Decoded_VkVideoEncodeH264FrameSizeKHR;
struct Decoded_VkVideoEncodeH264RateControlLayerInfoKHR;
struct Decoded_VkVideoEncodeH264GopRemainingFrameInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH264CapabilitiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH264QpKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH264QualityLevelPropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH264SessionCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH264SessionParametersAddInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH264SessionParametersCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH264SessionParametersGetInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH264SessionParametersFeedbackInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH264NaluSliceInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH264PictureInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH264DpbSlotInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH264ProfileInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH264RateControlInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH264FrameSizeKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH264RateControlLayerInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH264GopRemainingFrameInfoKHR* wrapper);

struct Decoded_VkVideoEncodeH265CapabilitiesKHR;
struct Decoded_VkVideoEncodeH265SessionCreateInfoKHR;
struct Decoded_VkVideoEncodeH265QpKHR;
struct Decoded_VkVideoEncodeH265QualityLevelPropertiesKHR;
struct Decoded_VkVideoEncodeH265SessionParametersAddInfoKHR;
struct Decoded_VkVideoEncodeH265SessionParametersCreateInfoKHR;
struct Decoded_VkVideoEncodeH265SessionParametersGetInfoKHR;
struct Decoded_VkVideoEncodeH265SessionParametersFeedbackInfoKHR;
struct Decoded_VkVideoEncodeH265NaluSliceSegmentInfoKHR;
struct Decoded_VkVideoEncodeH265PictureInfoKHR;
struct Decoded_VkVideoEncodeH265DpbSlotInfoKHR;
struct Decoded_VkVideoEncodeH265ProfileInfoKHR;
struct Decoded_VkVideoEncodeH265RateControlInfoKHR;
struct Decoded_VkVideoEncodeH265FrameSizeKHR;
struct Decoded_VkVideoEncodeH265RateControlLayerInfoKHR;
struct Decoded_VkVideoEncodeH265GopRemainingFrameInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH265CapabilitiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH265SessionCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH265QpKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH265QualityLevelPropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH265SessionParametersAddInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH265SessionParametersCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH265SessionParametersGetInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH265SessionParametersFeedbackInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH265NaluSliceSegmentInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH265PictureInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH265DpbSlotInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH265ProfileInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH265RateControlInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH265FrameSizeKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH265RateControlLayerInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeH265GopRemainingFrameInfoKHR* wrapper);

struct Decoded_VkVideoDecodeH264ProfileInfoKHR;
struct Decoded_VkVideoDecodeH264CapabilitiesKHR;
struct Decoded_VkVideoDecodeH264SessionParametersAddInfoKHR;
struct Decoded_VkVideoDecodeH264SessionParametersCreateInfoKHR;
struct Decoded_VkVideoDecodeH264PictureInfoKHR;
struct Decoded_VkVideoDecodeH264DpbSlotInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoDecodeH264ProfileInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoDecodeH264CapabilitiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoDecodeH264SessionParametersAddInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoDecodeH264SessionParametersCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoDecodeH264PictureInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoDecodeH264DpbSlotInfoKHR* wrapper);

struct Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR;
struct Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT;
struct Decoded_VkAttachmentSampleCountInfoAMD;
struct Decoded_VkMultiviewPerViewAttributesInfoNVX;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAttachmentSampleCountInfoAMD* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMultiviewPerViewAttributesInfoNVX* wrapper);

struct Decoded_VkImportMemoryWin32HandleInfoKHR;
struct Decoded_VkExportMemoryWin32HandleInfoKHR;
struct Decoded_VkMemoryWin32HandlePropertiesKHR;
struct Decoded_VkMemoryGetWin32HandleInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImportMemoryWin32HandleInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExportMemoryWin32HandleInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryWin32HandlePropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryGetWin32HandleInfoKHR* wrapper);

struct Decoded_VkImportMemoryFdInfoKHR;
struct Decoded_VkMemoryFdPropertiesKHR;
struct Decoded_VkMemoryGetFdInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImportMemoryFdInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryFdPropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryGetFdInfoKHR* wrapper);

struct Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR* wrapper);

struct Decoded_VkImportSemaphoreWin32HandleInfoKHR;
struct Decoded_VkExportSemaphoreWin32HandleInfoKHR;
struct Decoded_VkD3D12FenceSubmitInfoKHR;
struct Decoded_VkSemaphoreGetWin32HandleInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImportSemaphoreWin32HandleInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExportSemaphoreWin32HandleInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkD3D12FenceSubmitInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSemaphoreGetWin32HandleInfoKHR* wrapper);

struct Decoded_VkImportSemaphoreFdInfoKHR;
struct Decoded_VkSemaphoreGetFdInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImportSemaphoreFdInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSemaphoreGetFdInfoKHR* wrapper);

struct Decoded_VkPhysicalDevicePushDescriptorPropertiesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePushDescriptorPropertiesKHR* wrapper);

struct Decoded_VkRectLayerKHR;
struct Decoded_VkPresentRegionKHR;
struct Decoded_VkPresentRegionsKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRectLayerKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPresentRegionKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPresentRegionsKHR* wrapper);

struct Decoded_VkSharedPresentSurfaceCapabilitiesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSharedPresentSurfaceCapabilitiesKHR* wrapper);

struct Decoded_VkImportFenceWin32HandleInfoKHR;
struct Decoded_VkExportFenceWin32HandleInfoKHR;
struct Decoded_VkFenceGetWin32HandleInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImportFenceWin32HandleInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExportFenceWin32HandleInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkFenceGetWin32HandleInfoKHR* wrapper);

struct Decoded_VkImportFenceFdInfoKHR;
struct Decoded_VkFenceGetFdInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImportFenceFdInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkFenceGetFdInfoKHR* wrapper);

struct Decoded_VkPhysicalDevicePerformanceQueryFeaturesKHR;
struct Decoded_VkPhysicalDevicePerformanceQueryPropertiesKHR;
struct Decoded_VkPerformanceCounterKHR;
struct Decoded_VkPerformanceCounterDescriptionKHR;
struct Decoded_VkQueryPoolPerformanceCreateInfoKHR;
struct Decoded_VkAcquireProfilingLockInfoKHR;
struct Decoded_VkPerformanceQuerySubmitInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePerformanceQueryFeaturesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePerformanceQueryPropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPerformanceCounterKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPerformanceCounterDescriptionKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkQueryPoolPerformanceCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAcquireProfilingLockInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPerformanceQuerySubmitInfoKHR* wrapper);

struct Decoded_VkPhysicalDeviceSurfaceInfo2KHR;
struct Decoded_VkSurfaceCapabilities2KHR;
struct Decoded_VkSurfaceFormat2KHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSurfaceInfo2KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSurfaceCapabilities2KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSurfaceFormat2KHR* wrapper);

struct Decoded_VkDisplayProperties2KHR;
struct Decoded_VkDisplayPlaneProperties2KHR;
struct Decoded_VkDisplayModeProperties2KHR;
struct Decoded_VkDisplayPlaneInfo2KHR;
struct Decoded_VkDisplayPlaneCapabilities2KHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayProperties2KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayPlaneProperties2KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayModeProperties2KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayPlaneInfo2KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayPlaneCapabilities2KHR* wrapper);

struct Decoded_VkPhysicalDevicePortabilitySubsetFeaturesKHR;
struct Decoded_VkPhysicalDevicePortabilitySubsetPropertiesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePortabilitySubsetFeaturesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePortabilitySubsetPropertiesKHR* wrapper);

struct Decoded_VkPhysicalDeviceShaderClockFeaturesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderClockFeaturesKHR* wrapper);

struct Decoded_VkVideoDecodeH265ProfileInfoKHR;
struct Decoded_VkVideoDecodeH265CapabilitiesKHR;
struct Decoded_VkVideoDecodeH265SessionParametersAddInfoKHR;
struct Decoded_VkVideoDecodeH265SessionParametersCreateInfoKHR;
struct Decoded_VkVideoDecodeH265PictureInfoKHR;
struct Decoded_VkVideoDecodeH265DpbSlotInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoDecodeH265ProfileInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoDecodeH265CapabilitiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoDecodeH265SessionParametersAddInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoDecodeH265SessionParametersCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoDecodeH265PictureInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoDecodeH265DpbSlotInfoKHR* wrapper);

struct Decoded_VkDeviceQueueGlobalPriorityCreateInfoKHR;
struct Decoded_VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR;
struct Decoded_VkQueueFamilyGlobalPriorityPropertiesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceQueueGlobalPriorityCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkQueueFamilyGlobalPriorityPropertiesKHR* wrapper);

struct Decoded_VkFragmentShadingRateAttachmentInfoKHR;
struct Decoded_VkPipelineFragmentShadingRateStateCreateInfoKHR;
struct Decoded_VkPhysicalDeviceFragmentShadingRateFeaturesKHR;
struct Decoded_VkPhysicalDeviceFragmentShadingRatePropertiesKHR;
struct Decoded_VkPhysicalDeviceFragmentShadingRateKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkFragmentShadingRateAttachmentInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineFragmentShadingRateStateCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFragmentShadingRateFeaturesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFragmentShadingRatePropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFragmentShadingRateKHR* wrapper);

struct Decoded_VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR;
struct Decoded_VkRenderingAttachmentLocationInfoKHR;
struct Decoded_VkRenderingInputAttachmentIndexInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderingAttachmentLocationInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderingInputAttachmentIndexInfoKHR* wrapper);

struct Decoded_VkPhysicalDeviceShaderQuadControlFeaturesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderQuadControlFeaturesKHR* wrapper);

struct Decoded_VkSurfaceProtectedCapabilitiesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSurfaceProtectedCapabilitiesKHR* wrapper);

struct Decoded_VkPhysicalDevicePresentWaitFeaturesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePresentWaitFeaturesKHR* wrapper);

struct Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR;
struct Decoded_VkPipelineInfoKHR;
struct Decoded_VkPipelineExecutablePropertiesKHR;
struct Decoded_VkPipelineExecutableInfoKHR;
struct Decoded_VkPipelineExecutableStatisticKHR;
struct Decoded_VkPipelineExecutableInternalRepresentationKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineExecutablePropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineExecutableInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineExecutableStatisticKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineExecutableInternalRepresentationKHR* wrapper);

struct Decoded_VkMemoryMapInfoKHR;
struct Decoded_VkMemoryUnmapInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryMapInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryUnmapInfoKHR* wrapper);

struct Decoded_VkPipelineLibraryCreateInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineLibraryCreateInfoKHR* wrapper);

struct Decoded_VkPresentIdKHR;
struct Decoded_VkPhysicalDevicePresentIdFeaturesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPresentIdKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePresentIdFeaturesKHR* wrapper);

struct Decoded_VkVideoEncodeInfoKHR;
struct Decoded_VkVideoEncodeCapabilitiesKHR;
struct Decoded_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR;
struct Decoded_VkVideoEncodeUsageInfoKHR;
struct Decoded_VkVideoEncodeRateControlLayerInfoKHR;
struct Decoded_VkVideoEncodeRateControlInfoKHR;
struct Decoded_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR;
struct Decoded_VkVideoEncodeQualityLevelPropertiesKHR;
struct Decoded_VkVideoEncodeQualityLevelInfoKHR;
struct Decoded_VkVideoEncodeSessionParametersGetInfoKHR;
struct Decoded_VkVideoEncodeSessionParametersFeedbackInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeCapabilitiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeUsageInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeRateControlLayerInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeRateControlInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeQualityLevelPropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeQualityLevelInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeSessionParametersGetInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoEncodeSessionParametersFeedbackInfoKHR* wrapper);

struct Decoded_VkQueueFamilyCheckpointProperties2NV;
struct Decoded_VkCheckpointData2NV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkQueueFamilyCheckpointProperties2NV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCheckpointData2NV* wrapper);

struct Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR;
struct Decoded_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR* wrapper);

struct Decoded_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* wrapper);

struct Decoded_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* wrapper);

struct Decoded_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR;
struct Decoded_VkTraceRaysIndirectCommand2KHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkTraceRaysIndirectCommand2KHR* wrapper);

struct Decoded_VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR* wrapper);

struct Decoded_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR* wrapper);

struct Decoded_VkPhysicalDeviceMaintenance5FeaturesKHR;
struct Decoded_VkPhysicalDeviceMaintenance5PropertiesKHR;
struct Decoded_VkRenderingAreaInfoKHR;
struct Decoded_VkImageSubresource2KHR;
struct Decoded_VkDeviceImageSubresourceInfoKHR;
struct Decoded_VkSubresourceLayout2KHR;
struct Decoded_VkPipelineCreateFlags2CreateInfoKHR;
struct Decoded_VkBufferUsageFlags2CreateInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMaintenance5FeaturesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMaintenance5PropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderingAreaInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageSubresource2KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceImageSubresourceInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubresourceLayout2KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineCreateFlags2CreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBufferUsageFlags2CreateInfoKHR* wrapper);

struct Decoded_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR* wrapper);

struct Decoded_VkCooperativeMatrixPropertiesKHR;
struct Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesKHR;
struct Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCooperativeMatrixPropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesKHR* wrapper);

struct Decoded_VkVideoDecodeAV1ProfileInfoKHR;
struct Decoded_VkVideoDecodeAV1CapabilitiesKHR;
struct Decoded_VkVideoDecodeAV1SessionParametersCreateInfoKHR;
struct Decoded_VkVideoDecodeAV1PictureInfoKHR;
struct Decoded_VkVideoDecodeAV1DpbSlotInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoDecodeAV1ProfileInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoDecodeAV1CapabilitiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoDecodeAV1SessionParametersCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoDecodeAV1PictureInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoDecodeAV1DpbSlotInfoKHR* wrapper);

struct Decoded_VkPhysicalDeviceVideoMaintenance1FeaturesKHR;
struct Decoded_VkVideoInlineQueryInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVideoMaintenance1FeaturesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVideoInlineQueryInfoKHR* wrapper);

struct Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR;
struct Decoded_VkVertexInputBindingDivisorDescriptionKHR;
struct Decoded_VkPipelineVertexInputDivisorStateCreateInfoKHR;
struct Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVertexInputBindingDivisorDescriptionKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineVertexInputDivisorStateCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR* wrapper);

struct Decoded_VkPhysicalDeviceShaderFloatControls2FeaturesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderFloatControls2FeaturesKHR* wrapper);

struct Decoded_VkPhysicalDeviceIndexTypeUint8FeaturesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceIndexTypeUint8FeaturesKHR* wrapper);

struct Decoded_VkPhysicalDeviceLineRasterizationFeaturesKHR;
struct Decoded_VkPhysicalDeviceLineRasterizationPropertiesKHR;
struct Decoded_VkPipelineRasterizationLineStateCreateInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceLineRasterizationFeaturesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceLineRasterizationPropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineRasterizationLineStateCreateInfoKHR* wrapper);

struct Decoded_VkCalibratedTimestampInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCalibratedTimestampInfoKHR* wrapper);

struct Decoded_VkPhysicalDeviceShaderExpectAssumeFeaturesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderExpectAssumeFeaturesKHR* wrapper);

struct Decoded_VkPhysicalDeviceMaintenance6FeaturesKHR;
struct Decoded_VkPhysicalDeviceMaintenance6PropertiesKHR;
struct Decoded_VkBindMemoryStatusKHR;
struct Decoded_VkBindDescriptorSetsInfoKHR;
struct Decoded_VkPushConstantsInfoKHR;
struct Decoded_VkPushDescriptorSetInfoKHR;
struct Decoded_VkPushDescriptorSetWithTemplateInfoKHR;
struct Decoded_VkSetDescriptorBufferOffsetsInfoEXT;
struct Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMaintenance6FeaturesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMaintenance6PropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindMemoryStatusKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindDescriptorSetsInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPushConstantsInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPushDescriptorSetInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPushDescriptorSetWithTemplateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSetDescriptorBufferOffsetsInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT* wrapper);

struct Decoded_VkDebugReportCallbackCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDebugReportCallbackCreateInfoEXT* wrapper);

struct Decoded_VkPipelineRasterizationStateRasterizationOrderAMD;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineRasterizationStateRasterizationOrderAMD* wrapper);

struct Decoded_VkDebugMarkerObjectNameInfoEXT;
struct Decoded_VkDebugMarkerObjectTagInfoEXT;
struct Decoded_VkDebugMarkerMarkerInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDebugMarkerObjectNameInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDebugMarkerObjectTagInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDebugMarkerMarkerInfoEXT* wrapper);

struct Decoded_VkDedicatedAllocationImageCreateInfoNV;
struct Decoded_VkDedicatedAllocationBufferCreateInfoNV;
struct Decoded_VkDedicatedAllocationMemoryAllocateInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDedicatedAllocationImageCreateInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDedicatedAllocationBufferCreateInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDedicatedAllocationMemoryAllocateInfoNV* wrapper);

struct Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT;
struct Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT;
struct Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT* wrapper);

struct Decoded_VkImageViewHandleInfoNVX;
struct Decoded_VkImageViewAddressPropertiesNVX;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageViewHandleInfoNVX* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageViewAddressPropertiesNVX* wrapper);

struct Decoded_VkTextureLODGatherFormatPropertiesAMD;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkTextureLODGatherFormatPropertiesAMD* wrapper);

struct Decoded_VkShaderResourceUsageAMD;
struct Decoded_VkShaderStatisticsInfoAMD;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkShaderResourceUsageAMD* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkShaderStatisticsInfoAMD* wrapper);

struct Decoded_VkStreamDescriptorSurfaceCreateInfoGGP;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkStreamDescriptorSurfaceCreateInfoGGP* wrapper);

struct Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV* wrapper);

struct Decoded_VkExternalImageFormatPropertiesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExternalImageFormatPropertiesNV* wrapper);

struct Decoded_VkExternalMemoryImageCreateInfoNV;
struct Decoded_VkExportMemoryAllocateInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExternalMemoryImageCreateInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExportMemoryAllocateInfoNV* wrapper);

struct Decoded_VkImportMemoryWin32HandleInfoNV;
struct Decoded_VkExportMemoryWin32HandleInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImportMemoryWin32HandleInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExportMemoryWin32HandleInfoNV* wrapper);

struct Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV* wrapper);

struct Decoded_VkValidationFlagsEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkValidationFlagsEXT* wrapper);

struct Decoded_VkViSurfaceCreateInfoNN;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkViSurfaceCreateInfoNN* wrapper);

struct Decoded_VkImageViewASTCDecodeModeEXT;
struct Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageViewASTCDecodeModeEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT* wrapper);

struct Decoded_VkPhysicalDevicePipelineRobustnessFeaturesEXT;
struct Decoded_VkPhysicalDevicePipelineRobustnessPropertiesEXT;
struct Decoded_VkPipelineRobustnessCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePipelineRobustnessFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePipelineRobustnessPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineRobustnessCreateInfoEXT* wrapper);

struct Decoded_VkConditionalRenderingBeginInfoEXT;
struct Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT;
struct Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkConditionalRenderingBeginInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT* wrapper);

struct Decoded_VkViewportWScalingNV;
struct Decoded_VkPipelineViewportWScalingStateCreateInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkViewportWScalingNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineViewportWScalingStateCreateInfoNV* wrapper);

struct Decoded_VkSurfaceCapabilities2EXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSurfaceCapabilities2EXT* wrapper);

struct Decoded_VkDisplayPowerInfoEXT;
struct Decoded_VkDeviceEventInfoEXT;
struct Decoded_VkDisplayEventInfoEXT;
struct Decoded_VkSwapchainCounterCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayPowerInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceEventInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayEventInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSwapchainCounterCreateInfoEXT* wrapper);

struct Decoded_VkRefreshCycleDurationGOOGLE;
struct Decoded_VkPastPresentationTimingGOOGLE;
struct Decoded_VkPresentTimeGOOGLE;
struct Decoded_VkPresentTimesInfoGOOGLE;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRefreshCycleDurationGOOGLE* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPastPresentationTimingGOOGLE* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPresentTimeGOOGLE* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPresentTimesInfoGOOGLE* wrapper);

struct Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* wrapper);

struct Decoded_VkViewportSwizzleNV;
struct Decoded_VkPipelineViewportSwizzleStateCreateInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkViewportSwizzleNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineViewportSwizzleStateCreateInfoNV* wrapper);

struct Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT;
struct Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT;
struct Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT;
struct Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT* wrapper);

struct Decoded_VkXYColorEXT;
struct Decoded_VkHdrMetadataEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkXYColorEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkHdrMetadataEXT* wrapper);

struct Decoded_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG* wrapper);

struct Decoded_VkIOSSurfaceCreateInfoMVK;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkIOSSurfaceCreateInfoMVK* wrapper);

struct Decoded_VkMacOSSurfaceCreateInfoMVK;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMacOSSurfaceCreateInfoMVK* wrapper);

struct Decoded_VkDebugUtilsLabelEXT;
struct Decoded_VkDebugUtilsObjectNameInfoEXT;
struct Decoded_VkDebugUtilsMessengerCallbackDataEXT;
struct Decoded_VkDebugUtilsMessengerCreateInfoEXT;
struct Decoded_VkDebugUtilsObjectTagInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDebugUtilsLabelEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDebugUtilsObjectNameInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDebugUtilsMessengerCallbackDataEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDebugUtilsMessengerCreateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDebugUtilsObjectTagInfoEXT* wrapper);

struct Decoded_VkAndroidHardwareBufferUsageANDROID;
struct Decoded_VkAndroidHardwareBufferPropertiesANDROID;
struct Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID;
struct Decoded_VkImportAndroidHardwareBufferInfoANDROID;
struct Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID;
struct Decoded_VkExternalFormatANDROID;
struct Decoded_VkAndroidHardwareBufferFormatProperties2ANDROID;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAndroidHardwareBufferUsageANDROID* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAndroidHardwareBufferPropertiesANDROID* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImportAndroidHardwareBufferInfoANDROID* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExternalFormatANDROID* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAndroidHardwareBufferFormatProperties2ANDROID* wrapper);

struct Decoded_VkSampleLocationEXT;
struct Decoded_VkSampleLocationsInfoEXT;
struct Decoded_VkAttachmentSampleLocationsEXT;
struct Decoded_VkSubpassSampleLocationsEXT;
struct Decoded_VkRenderPassSampleLocationsBeginInfoEXT;
struct Decoded_VkPipelineSampleLocationsStateCreateInfoEXT;
struct Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT;
struct Decoded_VkMultisamplePropertiesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSampleLocationEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSampleLocationsInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAttachmentSampleLocationsEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubpassSampleLocationsEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassSampleLocationsBeginInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineSampleLocationsStateCreateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMultisamplePropertiesEXT* wrapper);

struct Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT;
struct Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT;
struct Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT* wrapper);

struct Decoded_VkPipelineCoverageToColorStateCreateInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineCoverageToColorStateCreateInfoNV* wrapper);

struct Decoded_VkPipelineCoverageModulationStateCreateInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineCoverageModulationStateCreateInfoNV* wrapper);

struct Decoded_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV;
struct Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* wrapper);

struct Decoded_VkDrmFormatModifierPropertiesEXT;
struct Decoded_VkDrmFormatModifierPropertiesListEXT;
struct Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT;
struct Decoded_VkImageDrmFormatModifierListCreateInfoEXT;
struct Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT;
struct Decoded_VkImageDrmFormatModifierPropertiesEXT;
struct Decoded_VkDrmFormatModifierProperties2EXT;
struct Decoded_VkDrmFormatModifierPropertiesList2EXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDrmFormatModifierPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDrmFormatModifierPropertiesListEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageDrmFormatModifierListCreateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageDrmFormatModifierPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDrmFormatModifierProperties2EXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDrmFormatModifierPropertiesList2EXT* wrapper);

struct Decoded_VkValidationCacheCreateInfoEXT;
struct Decoded_VkShaderModuleValidationCacheCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkValidationCacheCreateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkShaderModuleValidationCacheCreateInfoEXT* wrapper);

struct Decoded_VkShadingRatePaletteNV;
struct Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV;
struct Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV;
struct Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV;
struct Decoded_VkCoarseSampleLocationNV;
struct Decoded_VkCoarseSampleOrderCustomNV;
struct Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkShadingRatePaletteNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCoarseSampleLocationNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCoarseSampleOrderCustomNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* wrapper);

struct Decoded_VkRayTracingShaderGroupCreateInfoNV;
struct Decoded_VkRayTracingPipelineCreateInfoNV;
struct Decoded_VkGeometryTrianglesNV;
struct Decoded_VkGeometryAABBNV;
struct Decoded_VkGeometryDataNV;
struct Decoded_VkGeometryNV;
struct Decoded_VkAccelerationStructureInfoNV;
struct Decoded_VkAccelerationStructureCreateInfoNV;
struct Decoded_VkBindAccelerationStructureMemoryInfoNV;
struct Decoded_VkWriteDescriptorSetAccelerationStructureNV;
struct Decoded_VkAccelerationStructureMemoryRequirementsInfoNV;
struct Decoded_VkPhysicalDeviceRayTracingPropertiesNV;
struct Decoded_VkTransformMatrixKHR;
struct Decoded_VkAabbPositionsKHR;
struct Decoded_VkAccelerationStructureInstanceKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRayTracingShaderGroupCreateInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRayTracingPipelineCreateInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkGeometryTrianglesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkGeometryAABBNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkGeometryDataNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkGeometryNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAccelerationStructureInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAccelerationStructureCreateInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindAccelerationStructureMemoryInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkWriteDescriptorSetAccelerationStructureNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAccelerationStructureMemoryRequirementsInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRayTracingPropertiesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkTransformMatrixKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAabbPositionsKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAccelerationStructureInstanceKHR* wrapper);

struct Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV;
struct Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV* wrapper);

struct Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT;
struct Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT* wrapper);

struct Decoded_VkImportMemoryHostPointerInfoEXT;
struct Decoded_VkMemoryHostPointerPropertiesEXT;
struct Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImportMemoryHostPointerInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryHostPointerPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT* wrapper);

struct Decoded_VkPipelineCompilerControlCreateInfoAMD;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineCompilerControlCreateInfoAMD* wrapper);

struct Decoded_VkPhysicalDeviceShaderCorePropertiesAMD;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderCorePropertiesAMD* wrapper);

struct Decoded_VkDeviceMemoryOverallocationCreateInfoAMD;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceMemoryOverallocationCreateInfoAMD* wrapper);

struct Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* wrapper);

struct Decoded_VkPresentFrameTokenGGP;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPresentFrameTokenGGP* wrapper);

struct Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* wrapper);

struct Decoded_VkPhysicalDeviceMeshShaderFeaturesNV;
struct Decoded_VkPhysicalDeviceMeshShaderPropertiesNV;
struct Decoded_VkDrawMeshTasksIndirectCommandNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMeshShaderFeaturesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMeshShaderPropertiesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDrawMeshTasksIndirectCommandNV* wrapper);

struct Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV* wrapper);

struct Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV;
struct Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV* wrapper);

struct Decoded_VkQueueFamilyCheckpointPropertiesNV;
struct Decoded_VkCheckpointDataNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkQueueFamilyCheckpointPropertiesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCheckpointDataNV* wrapper);

struct Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* wrapper);

struct Decoded_VkInitializePerformanceApiInfoINTEL;
struct Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL;
struct Decoded_VkPerformanceMarkerInfoINTEL;
struct Decoded_VkPerformanceStreamMarkerInfoINTEL;
struct Decoded_VkPerformanceOverrideInfoINTEL;
struct Decoded_VkPerformanceConfigurationAcquireInfoINTEL;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkInitializePerformanceApiInfoINTEL* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPerformanceMarkerInfoINTEL* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPerformanceStreamMarkerInfoINTEL* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPerformanceOverrideInfoINTEL* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPerformanceConfigurationAcquireInfoINTEL* wrapper);

struct Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT* wrapper);

struct Decoded_VkDisplayNativeHdrSurfaceCapabilitiesAMD;
struct Decoded_VkSwapchainDisplayNativeHdrCreateInfoAMD;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayNativeHdrSurfaceCapabilitiesAMD* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSwapchainDisplayNativeHdrCreateInfoAMD* wrapper);

struct Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA* wrapper);

struct Decoded_VkMetalSurfaceCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMetalSurfaceCreateInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT;
struct Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT;
struct Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceShaderCoreProperties2AMD;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderCoreProperties2AMD* wrapper);

struct Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD* wrapper);

struct Decoded_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* wrapper);

struct Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT* wrapper);

struct Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT;
struct Decoded_VkMemoryPriorityAllocateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryPriorityAllocateInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* wrapper);

struct Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT;
struct Decoded_VkBufferDeviceAddressCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBufferDeviceAddressCreateInfoEXT* wrapper);

struct Decoded_VkValidationFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkValidationFeaturesEXT* wrapper);

struct Decoded_VkCooperativeMatrixPropertiesNV;
struct Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV;
struct Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCooperativeMatrixPropertiesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV* wrapper);

struct Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV;
struct Decoded_VkPipelineCoverageReductionStateCreateInfoNV;
struct Decoded_VkFramebufferMixedSamplesCombinationNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineCoverageReductionStateCreateInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkFramebufferMixedSamplesCombinationNV* wrapper);

struct Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* wrapper);

struct Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* wrapper);

struct Decoded_VkPhysicalDeviceProvokingVertexFeaturesEXT;
struct Decoded_VkPhysicalDeviceProvokingVertexPropertiesEXT;
struct Decoded_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceProvokingVertexFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceProvokingVertexPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT* wrapper);

struct Decoded_VkSurfaceFullScreenExclusiveInfoEXT;
struct Decoded_VkSurfaceCapabilitiesFullScreenExclusiveEXT;
struct Decoded_VkSurfaceFullScreenExclusiveWin32InfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSurfaceFullScreenExclusiveInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSurfaceCapabilitiesFullScreenExclusiveEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSurfaceFullScreenExclusiveWin32InfoEXT* wrapper);

struct Decoded_VkHeadlessSurfaceCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkHeadlessSurfaceCreateInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* wrapper);

struct Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* wrapper);

struct Decoded_VkPhysicalDeviceHostImageCopyFeaturesEXT;
struct Decoded_VkPhysicalDeviceHostImageCopyPropertiesEXT;
struct Decoded_VkMemoryToImageCopyEXT;
struct Decoded_VkImageToMemoryCopyEXT;
struct Decoded_VkCopyMemoryToImageInfoEXT;
struct Decoded_VkCopyImageToMemoryInfoEXT;
struct Decoded_VkCopyImageToImageInfoEXT;
struct Decoded_VkHostImageLayoutTransitionInfoEXT;
struct Decoded_VkSubresourceHostMemcpySizeEXT;
struct Decoded_VkHostImageCopyDevicePerformanceQueryEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceHostImageCopyFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceHostImageCopyPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryToImageCopyEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageToMemoryCopyEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCopyMemoryToImageInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCopyImageToMemoryInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCopyImageToImageInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkHostImageLayoutTransitionInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubresourceHostMemcpySizeEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkHostImageCopyDevicePerformanceQueryEXT* wrapper);

struct Decoded_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT;
struct Decoded_VkPhysicalDeviceMapMemoryPlacedPropertiesEXT;
struct Decoded_VkMemoryMapPlacedInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMapMemoryPlacedPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryMapPlacedInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* wrapper);

struct Decoded_VkSurfacePresentModeEXT;
struct Decoded_VkSurfacePresentScalingCapabilitiesEXT;
struct Decoded_VkSurfacePresentModeCompatibilityEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSurfacePresentModeEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSurfacePresentScalingCapabilitiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSurfacePresentModeCompatibilityEXT* wrapper);

struct Decoded_VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT;
struct Decoded_VkSwapchainPresentFenceInfoEXT;
struct Decoded_VkSwapchainPresentModesCreateInfoEXT;
struct Decoded_VkSwapchainPresentModeInfoEXT;
struct Decoded_VkSwapchainPresentScalingCreateInfoEXT;
struct Decoded_VkReleaseSwapchainImagesInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSwapchainPresentFenceInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSwapchainPresentModesCreateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSwapchainPresentModeInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSwapchainPresentScalingCreateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkReleaseSwapchainImagesInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV;
struct Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV;
struct Decoded_VkGraphicsShaderGroupCreateInfoNV;
struct Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV;
struct Decoded_VkBindShaderGroupIndirectCommandNV;
struct Decoded_VkBindIndexBufferIndirectCommandNV;
struct Decoded_VkBindVertexBufferIndirectCommandNV;
struct Decoded_VkSetStateFlagsIndirectCommandNV;
struct Decoded_VkIndirectCommandsStreamNV;
struct Decoded_VkIndirectCommandsLayoutTokenNV;
struct Decoded_VkIndirectCommandsLayoutCreateInfoNV;
struct Decoded_VkGeneratedCommandsInfoNV;
struct Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkGraphicsShaderGroupCreateInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindShaderGroupIndirectCommandNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindIndexBufferIndirectCommandNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindVertexBufferIndirectCommandNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSetStateFlagsIndirectCommandNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkIndirectCommandsStreamNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkIndirectCommandsLayoutTokenNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkIndirectCommandsLayoutCreateInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkGeneratedCommandsInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV* wrapper);

struct Decoded_VkPhysicalDeviceInheritedViewportScissorFeaturesNV;
struct Decoded_VkCommandBufferInheritanceViewportScissorInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceInheritedViewportScissorFeaturesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCommandBufferInheritanceViewportScissorInfoNV* wrapper);

struct Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* wrapper);

struct Decoded_VkRenderPassTransformBeginInfoQCOM;
struct Decoded_VkCommandBufferInheritanceRenderPassTransformInfoQCOM;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassTransformBeginInfoQCOM* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCommandBufferInheritanceRenderPassTransformInfoQCOM* wrapper);

struct Decoded_VkPhysicalDeviceDepthBiasControlFeaturesEXT;
struct Decoded_VkDepthBiasInfoEXT;
struct Decoded_VkDepthBiasRepresentationInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDepthBiasControlFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDepthBiasInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDepthBiasRepresentationInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT;
struct Decoded_VkDeviceMemoryReportCallbackDataEXT;
struct Decoded_VkDeviceDeviceMemoryReportCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceMemoryReportCallbackDataEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceDeviceMemoryReportCreateInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceRobustness2FeaturesEXT;
struct Decoded_VkPhysicalDeviceRobustness2PropertiesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRobustness2FeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRobustness2PropertiesEXT* wrapper);

struct Decoded_VkSamplerCustomBorderColorCreateInfoEXT;
struct Decoded_VkPhysicalDeviceCustomBorderColorPropertiesEXT;
struct Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSamplerCustomBorderColorCreateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceCustomBorderColorPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT* wrapper);

struct Decoded_VkPhysicalDevicePresentBarrierFeaturesNV;
struct Decoded_VkSurfaceCapabilitiesPresentBarrierNV;
struct Decoded_VkSwapchainPresentBarrierCreateInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePresentBarrierFeaturesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSurfaceCapabilitiesPresentBarrierNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSwapchainPresentBarrierCreateInfoNV* wrapper);

struct Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV;
struct Decoded_VkDeviceDiagnosticsConfigCreateInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceDiagnosticsConfigCreateInfoNV* wrapper);

struct Decoded_VkQueryLowLatencySupportNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkQueryLowLatencySupportNV* wrapper);

struct Decoded_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT;
struct Decoded_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT;
struct Decoded_VkGraphicsPipelineLibraryCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkGraphicsPipelineLibraryCreateInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* wrapper);

struct Decoded_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV;
struct Decoded_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV;
struct Decoded_VkPipelineFragmentShadingRateEnumStateCreateInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineFragmentShadingRateEnumStateCreateInfoNV* wrapper);

struct Decoded_VkAccelerationStructureGeometryMotionTrianglesDataNV;
struct Decoded_VkAccelerationStructureMotionInfoNV;
struct Decoded_VkAccelerationStructureMatrixMotionInstanceNV;
struct Decoded_VkSRTDataNV;
struct Decoded_VkAccelerationStructureSRTMotionInstanceNV;
struct Decoded_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAccelerationStructureGeometryMotionTrianglesDataNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAccelerationStructureMotionInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAccelerationStructureMatrixMotionInstanceNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSRTDataNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAccelerationStructureSRTMotionInstanceNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* wrapper);

struct Decoded_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* wrapper);

struct Decoded_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT;
struct Decoded_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT* wrapper);

struct Decoded_VkCopyCommandTransformInfoQCOM;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCopyCommandTransformInfoQCOM* wrapper);

struct Decoded_VkPhysicalDeviceImageCompressionControlFeaturesEXT;
struct Decoded_VkImageCompressionControlEXT;
struct Decoded_VkImageCompressionPropertiesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceImageCompressionControlFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageCompressionControlEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageCompressionPropertiesEXT* wrapper);

struct Decoded_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* wrapper);

struct Decoded_VkPhysicalDevice4444FormatsFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevice4444FormatsFeaturesEXT* wrapper);

struct Decoded_VkPhysicalDeviceFaultFeaturesEXT;
struct Decoded_VkDeviceFaultCountsEXT;
struct Decoded_VkDeviceFaultAddressInfoEXT;
struct Decoded_VkDeviceFaultVendorInfoEXT;
struct Decoded_VkDeviceFaultInfoEXT;
struct Decoded_VkDeviceFaultVendorBinaryHeaderVersionOneEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFaultFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceFaultCountsEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceFaultAddressInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceFaultVendorInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceFaultInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceFaultVendorBinaryHeaderVersionOneEXT* wrapper);

struct Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* wrapper);

struct Decoded_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* wrapper);

struct Decoded_VkDirectFBSurfaceCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDirectFBSurfaceCreateInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT;
struct Decoded_VkMutableDescriptorTypeListEXT;
struct Decoded_VkMutableDescriptorTypeCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMutableDescriptorTypeListEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMutableDescriptorTypeCreateInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT;
struct Decoded_VkVertexInputBindingDescription2EXT;
struct Decoded_VkVertexInputAttributeDescription2EXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVertexInputBindingDescription2EXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVertexInputAttributeDescription2EXT* wrapper);

struct Decoded_VkPhysicalDeviceDrmPropertiesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDrmPropertiesEXT* wrapper);

struct Decoded_VkPhysicalDeviceAddressBindingReportFeaturesEXT;
struct Decoded_VkDeviceAddressBindingCallbackDataEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceAddressBindingReportFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceAddressBindingCallbackDataEXT* wrapper);

struct Decoded_VkPhysicalDeviceDepthClipControlFeaturesEXT;
struct Decoded_VkPipelineViewportDepthClipControlCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDepthClipControlFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineViewportDepthClipControlCreateInfoEXT* wrapper);

struct Decoded_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* wrapper);

struct Decoded_VkImportMemoryZirconHandleInfoFUCHSIA;
struct Decoded_VkMemoryZirconHandlePropertiesFUCHSIA;
struct Decoded_VkMemoryGetZirconHandleInfoFUCHSIA;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImportMemoryZirconHandleInfoFUCHSIA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryZirconHandlePropertiesFUCHSIA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryGetZirconHandleInfoFUCHSIA* wrapper);

struct Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA;
struct Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA* wrapper);

struct Decoded_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* wrapper);

struct Decoded_VkMemoryGetRemoteAddressInfoNV;
struct Decoded_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryGetRemoteAddressInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* wrapper);

struct Decoded_VkPhysicalDeviceFrameBoundaryFeaturesEXT;
struct Decoded_VkFrameBoundaryEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFrameBoundaryFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkFrameBoundaryEXT* wrapper);

struct Decoded_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT;
struct Decoded_VkSubpassResolvePerformanceQueryEXT;
struct Decoded_VkMultisampledRenderToSingleSampledInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubpassResolvePerformanceQueryEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMultisampledRenderToSingleSampledInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* wrapper);

struct Decoded_VkScreenSurfaceCreateInfoQNX;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkScreenSurfaceCreateInfoQNX* wrapper);

struct Decoded_VkPhysicalDeviceColorWriteEnableFeaturesEXT;
struct Decoded_VkPipelineColorWriteCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceColorWriteEnableFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineColorWriteCreateInfoEXT* wrapper);

struct Decoded_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* wrapper);

struct Decoded_VkPhysicalDeviceImageViewMinLodFeaturesEXT;
struct Decoded_VkImageViewMinLodCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceImageViewMinLodFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageViewMinLodCreateInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceMultiDrawFeaturesEXT;
struct Decoded_VkPhysicalDeviceMultiDrawPropertiesEXT;
struct Decoded_VkMultiDrawInfoEXT;
struct Decoded_VkMultiDrawIndexedInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMultiDrawFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMultiDrawPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMultiDrawInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMultiDrawIndexedInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* wrapper);

struct Decoded_VkPhysicalDeviceShaderTileImageFeaturesEXT;
struct Decoded_VkPhysicalDeviceShaderTileImagePropertiesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderTileImageFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderTileImagePropertiesEXT* wrapper);

struct Decoded_VkMicromapUsageEXT;
struct Decoded_VkMicromapBuildInfoEXT;
struct Decoded_VkMicromapCreateInfoEXT;
struct Decoded_VkPhysicalDeviceOpacityMicromapFeaturesEXT;
struct Decoded_VkPhysicalDeviceOpacityMicromapPropertiesEXT;
struct Decoded_VkMicromapVersionInfoEXT;
struct Decoded_VkCopyMicromapToMemoryInfoEXT;
struct Decoded_VkCopyMemoryToMicromapInfoEXT;
struct Decoded_VkCopyMicromapInfoEXT;
struct Decoded_VkMicromapBuildSizesInfoEXT;
struct Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT;
struct Decoded_VkMicromapTriangleEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMicromapUsageEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMicromapBuildInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMicromapCreateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceOpacityMicromapFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceOpacityMicromapPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMicromapVersionInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCopyMicromapToMemoryInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCopyMemoryToMicromapInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCopyMicromapInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMicromapBuildSizesInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMicromapTriangleEXT* wrapper);

struct Decoded_VkPhysicalDeviceDisplacementMicromapFeaturesNV;
struct Decoded_VkPhysicalDeviceDisplacementMicromapPropertiesNV;
struct Decoded_VkAccelerationStructureTrianglesDisplacementMicromapNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDisplacementMicromapFeaturesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDisplacementMicromapPropertiesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAccelerationStructureTrianglesDisplacementMicromapNV* wrapper);

struct Decoded_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI;
struct Decoded_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI;
struct Decoded_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI* wrapper);

struct Decoded_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT;
struct Decoded_VkSamplerBorderColorComponentMappingCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSamplerBorderColorComponentMappingCreateInfoEXT* wrapper);

struct Decoded_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* wrapper);

struct Decoded_VkPhysicalDeviceShaderCorePropertiesARM;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderCorePropertiesARM* wrapper);

struct Decoded_VkDeviceQueueShaderCoreControlCreateInfoARM;
struct Decoded_VkPhysicalDeviceSchedulingControlsFeaturesARM;
struct Decoded_VkPhysicalDeviceSchedulingControlsPropertiesARM;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceQueueShaderCoreControlCreateInfoARM* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSchedulingControlsFeaturesARM* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSchedulingControlsPropertiesARM* wrapper);

struct Decoded_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT;
struct Decoded_VkImageViewSlicedCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageViewSlicedCreateInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE;
struct Decoded_VkDescriptorSetBindingReferenceVALVE;
struct Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorSetBindingReferenceVALVE* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE* wrapper);

struct Decoded_VkPhysicalDeviceDepthClampZeroOneFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDepthClampZeroOneFeaturesEXT* wrapper);

struct Decoded_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* wrapper);

struct Decoded_VkPhysicalDeviceRenderPassStripedFeaturesARM;
struct Decoded_VkPhysicalDeviceRenderPassStripedPropertiesARM;
struct Decoded_VkRenderPassStripeInfoARM;
struct Decoded_VkRenderPassStripeBeginInfoARM;
struct Decoded_VkRenderPassStripeSubmitInfoARM;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRenderPassStripedFeaturesARM* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRenderPassStripedPropertiesARM* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassStripeInfoARM* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassStripeBeginInfoARM* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassStripeSubmitInfoARM* wrapper);

struct Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM;
struct Decoded_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM;
struct Decoded_VkSubpassFragmentDensityMapOffsetEndInfoQCOM;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubpassFragmentDensityMapOffsetEndInfoQCOM* wrapper);

struct Decoded_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV;
struct Decoded_VkComputePipelineIndirectBufferInfoNV;
struct Decoded_VkPipelineIndirectDeviceAddressInfoNV;
struct Decoded_VkBindPipelineIndirectCommandNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkComputePipelineIndirectBufferInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineIndirectDeviceAddressInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindPipelineIndirectCommandNV* wrapper);

struct Decoded_VkPhysicalDeviceLinearColorAttachmentFeaturesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceLinearColorAttachmentFeaturesNV* wrapper);

struct Decoded_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* wrapper);

struct Decoded_VkImageViewSampleWeightCreateInfoQCOM;
struct Decoded_VkPhysicalDeviceImageProcessingFeaturesQCOM;
struct Decoded_VkPhysicalDeviceImageProcessingPropertiesQCOM;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageViewSampleWeightCreateInfoQCOM* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceImageProcessingFeaturesQCOM* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceImageProcessingPropertiesQCOM* wrapper);

struct Decoded_VkPhysicalDeviceNestedCommandBufferFeaturesEXT;
struct Decoded_VkPhysicalDeviceNestedCommandBufferPropertiesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceNestedCommandBufferFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceNestedCommandBufferPropertiesEXT* wrapper);

struct Decoded_VkExternalMemoryAcquireUnmodifiedEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExternalMemoryAcquireUnmodifiedEXT* wrapper);

struct Decoded_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT;
struct Decoded_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT;
struct Decoded_VkColorBlendEquationEXT;
struct Decoded_VkColorBlendAdvancedEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkColorBlendEquationEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkColorBlendAdvancedEXT* wrapper);

struct Decoded_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT;
struct Decoded_VkRenderPassCreationControlEXT;
struct Decoded_VkRenderPassCreationFeedbackInfoEXT;
struct Decoded_VkRenderPassCreationFeedbackCreateInfoEXT;
struct Decoded_VkRenderPassSubpassFeedbackInfoEXT;
struct Decoded_VkRenderPassSubpassFeedbackCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassCreationControlEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassCreationFeedbackInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassCreationFeedbackCreateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassSubpassFeedbackInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassSubpassFeedbackCreateInfoEXT* wrapper);

struct Decoded_VkDirectDriverLoadingInfoLUNARG;
struct Decoded_VkDirectDriverLoadingListLUNARG;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDirectDriverLoadingInfoLUNARG* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDirectDriverLoadingListLUNARG* wrapper);

struct Decoded_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT;
struct Decoded_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT;
struct Decoded_VkPipelineShaderStageModuleIdentifierCreateInfoEXT;
struct Decoded_VkShaderModuleIdentifierEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineShaderStageModuleIdentifierCreateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkShaderModuleIdentifierEXT* wrapper);

struct Decoded_VkPhysicalDeviceOpticalFlowFeaturesNV;
struct Decoded_VkPhysicalDeviceOpticalFlowPropertiesNV;
struct Decoded_VkOpticalFlowImageFormatInfoNV;
struct Decoded_VkOpticalFlowImageFormatPropertiesNV;
struct Decoded_VkOpticalFlowSessionCreateInfoNV;
struct Decoded_VkOpticalFlowSessionCreatePrivateDataInfoNV;
struct Decoded_VkOpticalFlowExecuteInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceOpticalFlowFeaturesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceOpticalFlowPropertiesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkOpticalFlowImageFormatInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkOpticalFlowImageFormatPropertiesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkOpticalFlowSessionCreateInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkOpticalFlowSessionCreatePrivateDataInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkOpticalFlowExecuteInfoNV* wrapper);

struct Decoded_VkPhysicalDeviceLegacyDitheringFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceLegacyDitheringFeaturesEXT* wrapper);

struct Decoded_VkPhysicalDevicePipelineProtectedAccessFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePipelineProtectedAccessFeaturesEXT* wrapper);

struct Decoded_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID;
struct Decoded_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID;
struct Decoded_VkAndroidHardwareBufferFormatResolvePropertiesANDROID;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAndroidHardwareBufferFormatResolvePropertiesANDROID* wrapper);

struct Decoded_VkPhysicalDeviceShaderObjectFeaturesEXT;
struct Decoded_VkPhysicalDeviceShaderObjectPropertiesEXT;
struct Decoded_VkShaderCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderObjectFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderObjectPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkShaderCreateInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceTilePropertiesFeaturesQCOM;
struct Decoded_VkTilePropertiesQCOM;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceTilePropertiesFeaturesQCOM* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkTilePropertiesQCOM* wrapper);

struct Decoded_VkPhysicalDeviceAmigoProfilingFeaturesSEC;
struct Decoded_VkAmigoProfilingSubmitInfoSEC;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceAmigoProfilingFeaturesSEC* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAmigoProfilingSubmitInfoSEC* wrapper);

struct Decoded_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* wrapper);

struct Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV;
struct Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV* wrapper);

struct Decoded_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV;
struct Decoded_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV* wrapper);

struct Decoded_VkLayerSettingEXT;
struct Decoded_VkLayerSettingsCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkLayerSettingEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkLayerSettingsCreateInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM;
struct Decoded_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM* wrapper);

struct Decoded_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT* wrapper);

struct Decoded_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT* wrapper);

struct Decoded_VkLatencySleepModeInfoNV;
struct Decoded_VkLatencySleepInfoNV;
struct Decoded_VkSetLatencyMarkerInfoNV;
struct Decoded_VkLatencyTimingsFrameReportNV;
struct Decoded_VkGetLatencyMarkerInfoNV;
struct Decoded_VkLatencySubmissionPresentIdNV;
struct Decoded_VkSwapchainLatencyCreateInfoNV;
struct Decoded_VkOutOfBandQueueTypeInfoNV;
struct Decoded_VkLatencySurfaceCapabilitiesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkLatencySleepModeInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkLatencySleepInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSetLatencyMarkerInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkLatencyTimingsFrameReportNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkGetLatencyMarkerInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkLatencySubmissionPresentIdNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSwapchainLatencyCreateInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkOutOfBandQueueTypeInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkLatencySurfaceCapabilitiesNV* wrapper);

struct Decoded_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM;
struct Decoded_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM* wrapper);

struct Decoded_VkPhysicalDevicePerStageDescriptorSetFeaturesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePerStageDescriptorSetFeaturesNV* wrapper);

struct Decoded_VkPhysicalDeviceImageProcessing2FeaturesQCOM;
struct Decoded_VkPhysicalDeviceImageProcessing2PropertiesQCOM;
struct Decoded_VkSamplerBlockMatchWindowCreateInfoQCOM;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceImageProcessing2FeaturesQCOM* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceImageProcessing2PropertiesQCOM* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSamplerBlockMatchWindowCreateInfoQCOM* wrapper);

struct Decoded_VkPhysicalDeviceCubicWeightsFeaturesQCOM;
struct Decoded_VkSamplerCubicWeightsCreateInfoQCOM;
struct Decoded_VkBlitImageCubicWeightsInfoQCOM;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceCubicWeightsFeaturesQCOM* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSamplerCubicWeightsCreateInfoQCOM* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBlitImageCubicWeightsInfoQCOM* wrapper);

struct Decoded_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM;
struct Decoded_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM* wrapper);

struct Decoded_VkPhysicalDeviceCubicClampFeaturesQCOM;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceCubicClampFeaturesQCOM* wrapper);

struct Decoded_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT* wrapper);

struct Decoded_VkPhysicalDeviceLayeredDriverPropertiesMSFT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceLayeredDriverPropertiesMSFT* wrapper);

struct Decoded_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV* wrapper);

struct Decoded_VkPhysicalDeviceRawAccessChainsFeaturesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRawAccessChainsFeaturesNV* wrapper);

struct Decoded_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV* wrapper);

struct Decoded_VkPhysicalDeviceRayTracingValidationFeaturesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRayTracingValidationFeaturesNV* wrapper);

struct Decoded_VkAccelerationStructureBuildRangeInfoKHR;
struct Decoded_VkAccelerationStructureGeometryTrianglesDataKHR;
struct Decoded_VkAccelerationStructureGeometryAabbsDataKHR;
struct Decoded_VkAccelerationStructureGeometryInstancesDataKHR;
struct Decoded_VkAccelerationStructureBuildGeometryInfoKHR;
struct Decoded_VkAccelerationStructureCreateInfoKHR;
struct Decoded_VkWriteDescriptorSetAccelerationStructureKHR;
struct Decoded_VkPhysicalDeviceAccelerationStructureFeaturesKHR;
struct Decoded_VkPhysicalDeviceAccelerationStructurePropertiesKHR;
struct Decoded_VkAccelerationStructureDeviceAddressInfoKHR;
struct Decoded_VkAccelerationStructureVersionInfoKHR;
struct Decoded_VkCopyAccelerationStructureToMemoryInfoKHR;
struct Decoded_VkCopyMemoryToAccelerationStructureInfoKHR;
struct Decoded_VkCopyAccelerationStructureInfoKHR;
struct Decoded_VkAccelerationStructureBuildSizesInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAccelerationStructureBuildRangeInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAccelerationStructureGeometryTrianglesDataKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAccelerationStructureGeometryAabbsDataKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAccelerationStructureGeometryInstancesDataKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAccelerationStructureBuildGeometryInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAccelerationStructureCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkWriteDescriptorSetAccelerationStructureKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceAccelerationStructureFeaturesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceAccelerationStructurePropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAccelerationStructureDeviceAddressInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAccelerationStructureVersionInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCopyAccelerationStructureToMemoryInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCopyMemoryToAccelerationStructureInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCopyAccelerationStructureInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAccelerationStructureBuildSizesInfoKHR* wrapper);

struct Decoded_VkRayTracingShaderGroupCreateInfoKHR;
struct Decoded_VkRayTracingPipelineInterfaceCreateInfoKHR;
struct Decoded_VkRayTracingPipelineCreateInfoKHR;
struct Decoded_VkPhysicalDeviceRayTracingPipelineFeaturesKHR;
struct Decoded_VkPhysicalDeviceRayTracingPipelinePropertiesKHR;
struct Decoded_VkStridedDeviceAddressRegionKHR;
struct Decoded_VkTraceRaysIndirectCommandKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRayTracingShaderGroupCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRayTracingPipelineInterfaceCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRayTracingPipelineCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRayTracingPipelineFeaturesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRayTracingPipelinePropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkStridedDeviceAddressRegionKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkTraceRaysIndirectCommandKHR* wrapper);

struct Decoded_VkPhysicalDeviceRayQueryFeaturesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRayQueryFeaturesKHR* wrapper);

struct Decoded_VkPhysicalDeviceMeshShaderFeaturesEXT;
struct Decoded_VkPhysicalDeviceMeshShaderPropertiesEXT;
struct Decoded_VkDrawMeshTasksIndirectCommandEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMeshShaderFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMeshShaderPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDrawMeshTasksIndirectCommandEXT* wrapper);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
