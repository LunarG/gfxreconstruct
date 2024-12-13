/*
** Copyright (c) 2021 Samsung
** Copyright (c) 2023 Google
** Copyright (c) 2023 LunarG, Inc.
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

#ifndef  GFXRECON_GENERATED_VULKAN_CPP_STRUCTS_H
#define  GFXRECON_GENERATED_VULKAN_CPP_STRUCTS_H

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

std::string GenerateStruct_StdVideoAV1CDEF(std::ostream &out, const StdVideoAV1CDEF* structInfo, Decoded_StdVideoAV1CDEF* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoAV1ColorConfig(std::ostream &out, const StdVideoAV1ColorConfig* structInfo, Decoded_StdVideoAV1ColorConfig* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoAV1ColorConfigFlags(std::ostream &out, const StdVideoAV1ColorConfigFlags* structInfo, Decoded_StdVideoAV1ColorConfigFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoAV1FilmGrain(std::ostream &out, const StdVideoAV1FilmGrain* structInfo, Decoded_StdVideoAV1FilmGrain* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoAV1FilmGrainFlags(std::ostream &out, const StdVideoAV1FilmGrainFlags* structInfo, Decoded_StdVideoAV1FilmGrainFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoAV1GlobalMotion(std::ostream &out, const StdVideoAV1GlobalMotion* structInfo, Decoded_StdVideoAV1GlobalMotion* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoAV1LoopFilter(std::ostream &out, const StdVideoAV1LoopFilter* structInfo, Decoded_StdVideoAV1LoopFilter* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoAV1LoopFilterFlags(std::ostream &out, const StdVideoAV1LoopFilterFlags* structInfo, Decoded_StdVideoAV1LoopFilterFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoAV1LoopRestoration(std::ostream &out, const StdVideoAV1LoopRestoration* structInfo, Decoded_StdVideoAV1LoopRestoration* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoAV1Quantization(std::ostream &out, const StdVideoAV1Quantization* structInfo, Decoded_StdVideoAV1Quantization* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoAV1QuantizationFlags(std::ostream &out, const StdVideoAV1QuantizationFlags* structInfo, Decoded_StdVideoAV1QuantizationFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoAV1Segmentation(std::ostream &out, const StdVideoAV1Segmentation* structInfo, Decoded_StdVideoAV1Segmentation* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoAV1SequenceHeader(std::ostream &out, const StdVideoAV1SequenceHeader* structInfo, Decoded_StdVideoAV1SequenceHeader* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoAV1SequenceHeaderFlags(std::ostream &out, const StdVideoAV1SequenceHeaderFlags* structInfo, Decoded_StdVideoAV1SequenceHeaderFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoAV1TileInfo(std::ostream &out, const StdVideoAV1TileInfo* structInfo, Decoded_StdVideoAV1TileInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoAV1TileInfoFlags(std::ostream &out, const StdVideoAV1TileInfoFlags* structInfo, Decoded_StdVideoAV1TileInfoFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoAV1TimingInfo(std::ostream &out, const StdVideoAV1TimingInfo* structInfo, Decoded_StdVideoAV1TimingInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoAV1TimingInfoFlags(std::ostream &out, const StdVideoAV1TimingInfoFlags* structInfo, Decoded_StdVideoAV1TimingInfoFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoDecodeAV1PictureInfo(std::ostream &out, const StdVideoDecodeAV1PictureInfo* structInfo, Decoded_StdVideoDecodeAV1PictureInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoDecodeAV1PictureInfoFlags(std::ostream &out, const StdVideoDecodeAV1PictureInfoFlags* structInfo, Decoded_StdVideoDecodeAV1PictureInfoFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoDecodeAV1ReferenceInfo(std::ostream &out, const StdVideoDecodeAV1ReferenceInfo* structInfo, Decoded_StdVideoDecodeAV1ReferenceInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoDecodeAV1ReferenceInfoFlags(std::ostream &out, const StdVideoDecodeAV1ReferenceInfoFlags* structInfo, Decoded_StdVideoDecodeAV1ReferenceInfoFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoDecodeH264PictureInfo(std::ostream &out, const StdVideoDecodeH264PictureInfo* structInfo, Decoded_StdVideoDecodeH264PictureInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoDecodeH264PictureInfoFlags(std::ostream &out, const StdVideoDecodeH264PictureInfoFlags* structInfo, Decoded_StdVideoDecodeH264PictureInfoFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoDecodeH264ReferenceInfo(std::ostream &out, const StdVideoDecodeH264ReferenceInfo* structInfo, Decoded_StdVideoDecodeH264ReferenceInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoDecodeH264ReferenceInfoFlags(std::ostream &out, const StdVideoDecodeH264ReferenceInfoFlags* structInfo, Decoded_StdVideoDecodeH264ReferenceInfoFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoDecodeH265PictureInfo(std::ostream &out, const StdVideoDecodeH265PictureInfo* structInfo, Decoded_StdVideoDecodeH265PictureInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoDecodeH265PictureInfoFlags(std::ostream &out, const StdVideoDecodeH265PictureInfoFlags* structInfo, Decoded_StdVideoDecodeH265PictureInfoFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoDecodeH265ReferenceInfo(std::ostream &out, const StdVideoDecodeH265ReferenceInfo* structInfo, Decoded_StdVideoDecodeH265ReferenceInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoDecodeH265ReferenceInfoFlags(std::ostream &out, const StdVideoDecodeH265ReferenceInfoFlags* structInfo, Decoded_StdVideoDecodeH265ReferenceInfoFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeAV1DecoderModelInfo(std::ostream &out, const StdVideoEncodeAV1DecoderModelInfo* structInfo, Decoded_StdVideoEncodeAV1DecoderModelInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeAV1ExtensionHeader(std::ostream &out, const StdVideoEncodeAV1ExtensionHeader* structInfo, Decoded_StdVideoEncodeAV1ExtensionHeader* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeAV1OperatingPointInfo(std::ostream &out, const StdVideoEncodeAV1OperatingPointInfo* structInfo, Decoded_StdVideoEncodeAV1OperatingPointInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeAV1OperatingPointInfoFlags(std::ostream &out, const StdVideoEncodeAV1OperatingPointInfoFlags* structInfo, Decoded_StdVideoEncodeAV1OperatingPointInfoFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeAV1PictureInfo(std::ostream &out, const StdVideoEncodeAV1PictureInfo* structInfo, Decoded_StdVideoEncodeAV1PictureInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeAV1PictureInfoFlags(std::ostream &out, const StdVideoEncodeAV1PictureInfoFlags* structInfo, Decoded_StdVideoEncodeAV1PictureInfoFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeAV1ReferenceInfo(std::ostream &out, const StdVideoEncodeAV1ReferenceInfo* structInfo, Decoded_StdVideoEncodeAV1ReferenceInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeAV1ReferenceInfoFlags(std::ostream &out, const StdVideoEncodeAV1ReferenceInfoFlags* structInfo, Decoded_StdVideoEncodeAV1ReferenceInfoFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264PictureInfo(std::ostream &out, const StdVideoEncodeH264PictureInfo* structInfo, Decoded_StdVideoEncodeH264PictureInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264PictureInfoFlags(std::ostream &out, const StdVideoEncodeH264PictureInfoFlags* structInfo, Decoded_StdVideoEncodeH264PictureInfoFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264RefListModEntry(std::ostream &out, const StdVideoEncodeH264RefListModEntry* structInfo, Decoded_StdVideoEncodeH264RefListModEntry* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264RefPicMarkingEntry(std::ostream &out, const StdVideoEncodeH264RefPicMarkingEntry* structInfo, Decoded_StdVideoEncodeH264RefPicMarkingEntry* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264ReferenceInfo(std::ostream &out, const StdVideoEncodeH264ReferenceInfo* structInfo, Decoded_StdVideoEncodeH264ReferenceInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264ReferenceInfoFlags(std::ostream &out, const StdVideoEncodeH264ReferenceInfoFlags* structInfo, Decoded_StdVideoEncodeH264ReferenceInfoFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264ReferenceListsInfo(std::ostream &out, const StdVideoEncodeH264ReferenceListsInfo* structInfo, Decoded_StdVideoEncodeH264ReferenceListsInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264ReferenceListsInfoFlags(std::ostream &out, const StdVideoEncodeH264ReferenceListsInfoFlags* structInfo, Decoded_StdVideoEncodeH264ReferenceListsInfoFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264SliceHeader(std::ostream &out, const StdVideoEncodeH264SliceHeader* structInfo, Decoded_StdVideoEncodeH264SliceHeader* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264SliceHeaderFlags(std::ostream &out, const StdVideoEncodeH264SliceHeaderFlags* structInfo, Decoded_StdVideoEncodeH264SliceHeaderFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264WeightTable(std::ostream &out, const StdVideoEncodeH264WeightTable* structInfo, Decoded_StdVideoEncodeH264WeightTable* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264WeightTableFlags(std::ostream &out, const StdVideoEncodeH264WeightTableFlags* structInfo, Decoded_StdVideoEncodeH264WeightTableFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH265LongTermRefPics(std::ostream &out, const StdVideoEncodeH265LongTermRefPics* structInfo, Decoded_StdVideoEncodeH265LongTermRefPics* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH265PictureInfo(std::ostream &out, const StdVideoEncodeH265PictureInfo* structInfo, Decoded_StdVideoEncodeH265PictureInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH265PictureInfoFlags(std::ostream &out, const StdVideoEncodeH265PictureInfoFlags* structInfo, Decoded_StdVideoEncodeH265PictureInfoFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH265ReferenceInfo(std::ostream &out, const StdVideoEncodeH265ReferenceInfo* structInfo, Decoded_StdVideoEncodeH265ReferenceInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH265ReferenceInfoFlags(std::ostream &out, const StdVideoEncodeH265ReferenceInfoFlags* structInfo, Decoded_StdVideoEncodeH265ReferenceInfoFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH265ReferenceListsInfo(std::ostream &out, const StdVideoEncodeH265ReferenceListsInfo* structInfo, Decoded_StdVideoEncodeH265ReferenceListsInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH265ReferenceListsInfoFlags(std::ostream &out, const StdVideoEncodeH265ReferenceListsInfoFlags* structInfo, Decoded_StdVideoEncodeH265ReferenceListsInfoFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH265SliceSegmentHeader(std::ostream &out, const StdVideoEncodeH265SliceSegmentHeader* structInfo, Decoded_StdVideoEncodeH265SliceSegmentHeader* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH265SliceSegmentHeaderFlags(std::ostream &out, const StdVideoEncodeH265SliceSegmentHeaderFlags* structInfo, Decoded_StdVideoEncodeH265SliceSegmentHeaderFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH265WeightTable(std::ostream &out, const StdVideoEncodeH265WeightTable* structInfo, Decoded_StdVideoEncodeH265WeightTable* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH265WeightTableFlags(std::ostream &out, const StdVideoEncodeH265WeightTableFlags* structInfo, Decoded_StdVideoEncodeH265WeightTableFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH264HrdParameters(std::ostream &out, const StdVideoH264HrdParameters* structInfo, Decoded_StdVideoH264HrdParameters* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH264PictureParameterSet(std::ostream &out, const StdVideoH264PictureParameterSet* structInfo, Decoded_StdVideoH264PictureParameterSet* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH264PpsFlags(std::ostream &out, const StdVideoH264PpsFlags* structInfo, Decoded_StdVideoH264PpsFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH264ScalingLists(std::ostream &out, const StdVideoH264ScalingLists* structInfo, Decoded_StdVideoH264ScalingLists* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH264SequenceParameterSet(std::ostream &out, const StdVideoH264SequenceParameterSet* structInfo, Decoded_StdVideoH264SequenceParameterSet* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH264SequenceParameterSetVui(std::ostream &out, const StdVideoH264SequenceParameterSetVui* structInfo, Decoded_StdVideoH264SequenceParameterSetVui* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH264SpsFlags(std::ostream &out, const StdVideoH264SpsFlags* structInfo, Decoded_StdVideoH264SpsFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH264SpsVuiFlags(std::ostream &out, const StdVideoH264SpsVuiFlags* structInfo, Decoded_StdVideoH264SpsVuiFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265DecPicBufMgr(std::ostream &out, const StdVideoH265DecPicBufMgr* structInfo, Decoded_StdVideoH265DecPicBufMgr* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265HrdFlags(std::ostream &out, const StdVideoH265HrdFlags* structInfo, Decoded_StdVideoH265HrdFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265HrdParameters(std::ostream &out, const StdVideoH265HrdParameters* structInfo, Decoded_StdVideoH265HrdParameters* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265LongTermRefPicsSps(std::ostream &out, const StdVideoH265LongTermRefPicsSps* structInfo, Decoded_StdVideoH265LongTermRefPicsSps* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265PictureParameterSet(std::ostream &out, const StdVideoH265PictureParameterSet* structInfo, Decoded_StdVideoH265PictureParameterSet* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265PpsFlags(std::ostream &out, const StdVideoH265PpsFlags* structInfo, Decoded_StdVideoH265PpsFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265PredictorPaletteEntries(std::ostream &out, const StdVideoH265PredictorPaletteEntries* structInfo, Decoded_StdVideoH265PredictorPaletteEntries* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265ProfileTierLevel(std::ostream &out, const StdVideoH265ProfileTierLevel* structInfo, Decoded_StdVideoH265ProfileTierLevel* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265ProfileTierLevelFlags(std::ostream &out, const StdVideoH265ProfileTierLevelFlags* structInfo, Decoded_StdVideoH265ProfileTierLevelFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265ScalingLists(std::ostream &out, const StdVideoH265ScalingLists* structInfo, Decoded_StdVideoH265ScalingLists* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265SequenceParameterSet(std::ostream &out, const StdVideoH265SequenceParameterSet* structInfo, Decoded_StdVideoH265SequenceParameterSet* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265SequenceParameterSetVui(std::ostream &out, const StdVideoH265SequenceParameterSetVui* structInfo, Decoded_StdVideoH265SequenceParameterSetVui* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265ShortTermRefPicSet(std::ostream &out, const StdVideoH265ShortTermRefPicSet* structInfo, Decoded_StdVideoH265ShortTermRefPicSet* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265ShortTermRefPicSetFlags(std::ostream &out, const StdVideoH265ShortTermRefPicSetFlags* structInfo, Decoded_StdVideoH265ShortTermRefPicSetFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265SpsFlags(std::ostream &out, const StdVideoH265SpsFlags* structInfo, Decoded_StdVideoH265SpsFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265SpsVuiFlags(std::ostream &out, const StdVideoH265SpsVuiFlags* structInfo, Decoded_StdVideoH265SpsVuiFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265SubLayerHrdParameters(std::ostream &out, const StdVideoH265SubLayerHrdParameters* structInfo, Decoded_StdVideoH265SubLayerHrdParameters* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265VideoParameterSet(std::ostream &out, const StdVideoH265VideoParameterSet* structInfo, Decoded_StdVideoH265VideoParameterSet* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265VpsFlags(std::ostream &out, const StdVideoH265VpsFlags* structInfo, Decoded_StdVideoH265VpsFlags* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAllocationCallbacks(std::ostream &out, const VkAllocationCallbacks* structInfo, Decoded_VkAllocationCallbacks* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkApplicationInfo(std::ostream &out, const VkApplicationInfo* structInfo, Decoded_VkApplicationInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAttachmentDescription(std::ostream &out, const VkAttachmentDescription* structInfo, Decoded_VkAttachmentDescription* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAttachmentReference(std::ostream &out, const VkAttachmentReference* structInfo, Decoded_VkAttachmentReference* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferCopy(std::ostream &out, const VkBufferCopy* structInfo, Decoded_VkBufferCopy* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferCreateInfo(std::ostream &out, const VkBufferCreateInfo* structInfo, Decoded_VkBufferCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferImageCopy(std::ostream &out, const VkBufferImageCopy* structInfo, Decoded_VkBufferImageCopy* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferMemoryBarrier(std::ostream &out, const VkBufferMemoryBarrier* structInfo, Decoded_VkBufferMemoryBarrier* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferViewCreateInfo(std::ostream &out, const VkBufferViewCreateInfo* structInfo, Decoded_VkBufferViewCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkClearAttachment(std::ostream &out, const VkClearAttachment* structInfo, Decoded_VkClearAttachment* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkClearDepthStencilValue(std::ostream &out, const VkClearDepthStencilValue* structInfo, Decoded_VkClearDepthStencilValue* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkClearRect(std::ostream &out, const VkClearRect* structInfo, Decoded_VkClearRect* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCommandBufferAllocateInfo(std::ostream &out, const VkCommandBufferAllocateInfo* structInfo, Decoded_VkCommandBufferAllocateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCommandBufferBeginInfo(std::ostream &out, const VkCommandBufferBeginInfo* structInfo, Decoded_VkCommandBufferBeginInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCommandBufferInheritanceInfo(std::ostream &out, const VkCommandBufferInheritanceInfo* structInfo, Decoded_VkCommandBufferInheritanceInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCommandPoolCreateInfo(std::ostream &out, const VkCommandPoolCreateInfo* structInfo, Decoded_VkCommandPoolCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkComponentMapping(std::ostream &out, const VkComponentMapping* structInfo, Decoded_VkComponentMapping* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkComputePipelineCreateInfo(std::ostream &out, const VkComputePipelineCreateInfo* structInfo, Decoded_VkComputePipelineCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyDescriptorSet(std::ostream &out, const VkCopyDescriptorSet* structInfo, Decoded_VkCopyDescriptorSet* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorBufferInfo(std::ostream &out, const VkDescriptorBufferInfo* structInfo, Decoded_VkDescriptorBufferInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorPoolCreateInfo(std::ostream &out, const VkDescriptorPoolCreateInfo* structInfo, Decoded_VkDescriptorPoolCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorPoolSize(std::ostream &out, const VkDescriptorPoolSize* structInfo, Decoded_VkDescriptorPoolSize* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorSetAllocateInfo(std::ostream &out, const VkDescriptorSetAllocateInfo* structInfo, Decoded_VkDescriptorSetAllocateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorSetLayoutBinding(std::ostream &out, const VkDescriptorSetLayoutBinding* structInfo, Decoded_VkDescriptorSetLayoutBinding* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorSetLayoutCreateInfo(std::ostream &out, const VkDescriptorSetLayoutCreateInfo* structInfo, Decoded_VkDescriptorSetLayoutCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceCreateInfo(std::ostream &out, const VkDeviceCreateInfo* structInfo, Decoded_VkDeviceCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceQueueCreateInfo(std::ostream &out, const VkDeviceQueueCreateInfo* structInfo, Decoded_VkDeviceQueueCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDispatchIndirectCommand(std::ostream &out, const VkDispatchIndirectCommand* structInfo, Decoded_VkDispatchIndirectCommand* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDrawIndexedIndirectCommand(std::ostream &out, const VkDrawIndexedIndirectCommand* structInfo, Decoded_VkDrawIndexedIndirectCommand* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDrawIndirectCommand(std::ostream &out, const VkDrawIndirectCommand* structInfo, Decoded_VkDrawIndirectCommand* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkEventCreateInfo(std::ostream &out, const VkEventCreateInfo* structInfo, Decoded_VkEventCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExtensionProperties(std::ostream &out, const VkExtensionProperties* structInfo, Decoded_VkExtensionProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExtent2D(std::ostream &out, const VkExtent2D* structInfo, Decoded_VkExtent2D* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExtent3D(std::ostream &out, const VkExtent3D* structInfo, Decoded_VkExtent3D* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFenceCreateInfo(std::ostream &out, const VkFenceCreateInfo* structInfo, Decoded_VkFenceCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFormatProperties(std::ostream &out, const VkFormatProperties* structInfo, Decoded_VkFormatProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFramebufferCreateInfo(std::ostream &out, const VkFramebufferCreateInfo* structInfo, Decoded_VkFramebufferCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGraphicsPipelineCreateInfo(std::ostream &out, const VkGraphicsPipelineCreateInfo* structInfo, Decoded_VkGraphicsPipelineCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageBlit(std::ostream &out, const VkImageBlit* structInfo, Decoded_VkImageBlit* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageCopy(std::ostream &out, const VkImageCopy* structInfo, Decoded_VkImageCopy* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageCreateInfo(std::ostream &out, const VkImageCreateInfo* structInfo, Decoded_VkImageCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageFormatProperties(std::ostream &out, const VkImageFormatProperties* structInfo, Decoded_VkImageFormatProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageMemoryBarrier(std::ostream &out, const VkImageMemoryBarrier* structInfo, Decoded_VkImageMemoryBarrier* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageResolve(std::ostream &out, const VkImageResolve* structInfo, Decoded_VkImageResolve* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageSubresource(std::ostream &out, const VkImageSubresource* structInfo, Decoded_VkImageSubresource* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageSubresourceLayers(std::ostream &out, const VkImageSubresourceLayers* structInfo, Decoded_VkImageSubresourceLayers* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageSubresourceRange(std::ostream &out, const VkImageSubresourceRange* structInfo, Decoded_VkImageSubresourceRange* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageViewCreateInfo(std::ostream &out, const VkImageViewCreateInfo* structInfo, Decoded_VkImageViewCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkLayerProperties(std::ostream &out, const VkLayerProperties* structInfo, Decoded_VkLayerProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMappedMemoryRange(std::ostream &out, const VkMappedMemoryRange* structInfo, Decoded_VkMappedMemoryRange* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryBarrier(std::ostream &out, const VkMemoryBarrier* structInfo, Decoded_VkMemoryBarrier* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryHeap(std::ostream &out, const VkMemoryHeap* structInfo, Decoded_VkMemoryHeap* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryRequirements(std::ostream &out, const VkMemoryRequirements* structInfo, Decoded_VkMemoryRequirements* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryType(std::ostream &out, const VkMemoryType* structInfo, Decoded_VkMemoryType* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkOffset2D(std::ostream &out, const VkOffset2D* structInfo, Decoded_VkOffset2D* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkOffset3D(std::ostream &out, const VkOffset3D* structInfo, Decoded_VkOffset3D* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFeatures(std::ostream &out, const VkPhysicalDeviceFeatures* structInfo, Decoded_VkPhysicalDeviceFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceLimits(std::ostream &out, const VkPhysicalDeviceLimits* structInfo, Decoded_VkPhysicalDeviceLimits* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMemoryProperties(std::ostream &out, const VkPhysicalDeviceMemoryProperties* structInfo, Decoded_VkPhysicalDeviceMemoryProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceProperties(std::ostream &out, const VkPhysicalDeviceProperties* structInfo, Decoded_VkPhysicalDeviceProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSparseProperties(std::ostream &out, const VkPhysicalDeviceSparseProperties* structInfo, Decoded_VkPhysicalDeviceSparseProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineCacheCreateInfo(std::ostream &out, const VkPipelineCacheCreateInfo* structInfo, Decoded_VkPipelineCacheCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineCacheHeaderVersionOne(std::ostream &out, const VkPipelineCacheHeaderVersionOne* structInfo, Decoded_VkPipelineCacheHeaderVersionOne* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineColorBlendAttachmentState(std::ostream &out, const VkPipelineColorBlendAttachmentState* structInfo, Decoded_VkPipelineColorBlendAttachmentState* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineColorBlendStateCreateInfo(std::ostream &out, const VkPipelineColorBlendStateCreateInfo* structInfo, Decoded_VkPipelineColorBlendStateCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineDepthStencilStateCreateInfo(std::ostream &out, const VkPipelineDepthStencilStateCreateInfo* structInfo, Decoded_VkPipelineDepthStencilStateCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineDynamicStateCreateInfo(std::ostream &out, const VkPipelineDynamicStateCreateInfo* structInfo, Decoded_VkPipelineDynamicStateCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineInputAssemblyStateCreateInfo(std::ostream &out, const VkPipelineInputAssemblyStateCreateInfo* structInfo, Decoded_VkPipelineInputAssemblyStateCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineLayoutCreateInfo(std::ostream &out, const VkPipelineLayoutCreateInfo* structInfo, Decoded_VkPipelineLayoutCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineMultisampleStateCreateInfo(std::ostream &out, const VkPipelineMultisampleStateCreateInfo* structInfo, Decoded_VkPipelineMultisampleStateCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineRasterizationStateCreateInfo(std::ostream &out, const VkPipelineRasterizationStateCreateInfo* structInfo, Decoded_VkPipelineRasterizationStateCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineShaderStageCreateInfo(std::ostream &out, const VkPipelineShaderStageCreateInfo* structInfo, Decoded_VkPipelineShaderStageCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineTessellationStateCreateInfo(std::ostream &out, const VkPipelineTessellationStateCreateInfo* structInfo, Decoded_VkPipelineTessellationStateCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineVertexInputStateCreateInfo(std::ostream &out, const VkPipelineVertexInputStateCreateInfo* structInfo, Decoded_VkPipelineVertexInputStateCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineViewportStateCreateInfo(std::ostream &out, const VkPipelineViewportStateCreateInfo* structInfo, Decoded_VkPipelineViewportStateCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPushConstantRange(std::ostream &out, const VkPushConstantRange* structInfo, Decoded_VkPushConstantRange* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueryPoolCreateInfo(std::ostream &out, const VkQueryPoolCreateInfo* structInfo, Decoded_VkQueryPoolCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueueFamilyProperties(std::ostream &out, const VkQueueFamilyProperties* structInfo, Decoded_VkQueueFamilyProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRect2D(std::ostream &out, const VkRect2D* structInfo, Decoded_VkRect2D* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassBeginInfo(std::ostream &out, const VkRenderPassBeginInfo* structInfo, Decoded_VkRenderPassBeginInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassCreateInfo(std::ostream &out, const VkRenderPassCreateInfo* structInfo, Decoded_VkRenderPassCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSamplerCreateInfo(std::ostream &out, const VkSamplerCreateInfo* structInfo, Decoded_VkSamplerCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSemaphoreCreateInfo(std::ostream &out, const VkSemaphoreCreateInfo* structInfo, Decoded_VkSemaphoreCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkShaderModuleCreateInfo(std::ostream &out, const VkShaderModuleCreateInfo* structInfo, Decoded_VkShaderModuleCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSparseBufferMemoryBindInfo(std::ostream &out, const VkSparseBufferMemoryBindInfo* structInfo, Decoded_VkSparseBufferMemoryBindInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSparseImageFormatProperties(std::ostream &out, const VkSparseImageFormatProperties* structInfo, Decoded_VkSparseImageFormatProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSparseImageMemoryBind(std::ostream &out, const VkSparseImageMemoryBind* structInfo, Decoded_VkSparseImageMemoryBind* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSparseImageMemoryBindInfo(std::ostream &out, const VkSparseImageMemoryBindInfo* structInfo, Decoded_VkSparseImageMemoryBindInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSparseImageMemoryRequirements(std::ostream &out, const VkSparseImageMemoryRequirements* structInfo, Decoded_VkSparseImageMemoryRequirements* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSparseImageOpaqueMemoryBindInfo(std::ostream &out, const VkSparseImageOpaqueMemoryBindInfo* structInfo, Decoded_VkSparseImageOpaqueMemoryBindInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSparseMemoryBind(std::ostream &out, const VkSparseMemoryBind* structInfo, Decoded_VkSparseMemoryBind* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSpecializationInfo(std::ostream &out, const VkSpecializationInfo* structInfo, Decoded_VkSpecializationInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSpecializationMapEntry(std::ostream &out, const VkSpecializationMapEntry* structInfo, Decoded_VkSpecializationMapEntry* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkStencilOpState(std::ostream &out, const VkStencilOpState* structInfo, Decoded_VkStencilOpState* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubpassDependency(std::ostream &out, const VkSubpassDependency* structInfo, Decoded_VkSubpassDependency* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubpassDescription(std::ostream &out, const VkSubpassDescription* structInfo, Decoded_VkSubpassDescription* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubresourceLayout(std::ostream &out, const VkSubresourceLayout* structInfo, Decoded_VkSubresourceLayout* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVertexInputAttributeDescription(std::ostream &out, const VkVertexInputAttributeDescription* structInfo, Decoded_VkVertexInputAttributeDescription* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVertexInputBindingDescription(std::ostream &out, const VkVertexInputBindingDescription* structInfo, Decoded_VkVertexInputBindingDescription* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkViewport(std::ostream &out, const VkViewport* structInfo, Decoded_VkViewport* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindBufferMemoryDeviceGroupInfo(std::ostream &out, const VkBindBufferMemoryDeviceGroupInfo* structInfo, Decoded_VkBindBufferMemoryDeviceGroupInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindBufferMemoryInfo(std::ostream &out, const VkBindBufferMemoryInfo* structInfo, Decoded_VkBindBufferMemoryInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindImageMemoryDeviceGroupInfo(std::ostream &out, const VkBindImageMemoryDeviceGroupInfo* structInfo, Decoded_VkBindImageMemoryDeviceGroupInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindImageMemoryInfo(std::ostream &out, const VkBindImageMemoryInfo* structInfo, Decoded_VkBindImageMemoryInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindImagePlaneMemoryInfo(std::ostream &out, const VkBindImagePlaneMemoryInfo* structInfo, Decoded_VkBindImagePlaneMemoryInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferMemoryRequirementsInfo2(std::ostream &out, const VkBufferMemoryRequirementsInfo2* structInfo, Decoded_VkBufferMemoryRequirementsInfo2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorSetLayoutSupport(std::ostream &out, const VkDescriptorSetLayoutSupport* structInfo, Decoded_VkDescriptorSetLayoutSupport* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorUpdateTemplateCreateInfo(std::ostream &out, const VkDescriptorUpdateTemplateCreateInfo* structInfo, Decoded_VkDescriptorUpdateTemplateCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceGroupBindSparseInfo(std::ostream &out, const VkDeviceGroupBindSparseInfo* structInfo, Decoded_VkDeviceGroupBindSparseInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceGroupCommandBufferBeginInfo(std::ostream &out, const VkDeviceGroupCommandBufferBeginInfo* structInfo, Decoded_VkDeviceGroupCommandBufferBeginInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceGroupDeviceCreateInfo(std::ostream &out, const VkDeviceGroupDeviceCreateInfo* structInfo, Decoded_VkDeviceGroupDeviceCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceGroupRenderPassBeginInfo(std::ostream &out, const VkDeviceGroupRenderPassBeginInfo* structInfo, Decoded_VkDeviceGroupRenderPassBeginInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceGroupSubmitInfo(std::ostream &out, const VkDeviceGroupSubmitInfo* structInfo, Decoded_VkDeviceGroupSubmitInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceQueueInfo2(std::ostream &out, const VkDeviceQueueInfo2* structInfo, Decoded_VkDeviceQueueInfo2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExportFenceCreateInfo(std::ostream &out, const VkExportFenceCreateInfo* structInfo, Decoded_VkExportFenceCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExportMemoryAllocateInfo(std::ostream &out, const VkExportMemoryAllocateInfo* structInfo, Decoded_VkExportMemoryAllocateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExportSemaphoreCreateInfo(std::ostream &out, const VkExportSemaphoreCreateInfo* structInfo, Decoded_VkExportSemaphoreCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExternalBufferProperties(std::ostream &out, const VkExternalBufferProperties* structInfo, Decoded_VkExternalBufferProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExternalFenceProperties(std::ostream &out, const VkExternalFenceProperties* structInfo, Decoded_VkExternalFenceProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExternalImageFormatProperties(std::ostream &out, const VkExternalImageFormatProperties* structInfo, Decoded_VkExternalImageFormatProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExternalMemoryBufferCreateInfo(std::ostream &out, const VkExternalMemoryBufferCreateInfo* structInfo, Decoded_VkExternalMemoryBufferCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExternalMemoryImageCreateInfo(std::ostream &out, const VkExternalMemoryImageCreateInfo* structInfo, Decoded_VkExternalMemoryImageCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExternalMemoryProperties(std::ostream &out, const VkExternalMemoryProperties* structInfo, Decoded_VkExternalMemoryProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExternalSemaphoreProperties(std::ostream &out, const VkExternalSemaphoreProperties* structInfo, Decoded_VkExternalSemaphoreProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFormatProperties2(std::ostream &out, const VkFormatProperties2* structInfo, Decoded_VkFormatProperties2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageFormatProperties2(std::ostream &out, const VkImageFormatProperties2* structInfo, Decoded_VkImageFormatProperties2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageMemoryRequirementsInfo2(std::ostream &out, const VkImageMemoryRequirementsInfo2* structInfo, Decoded_VkImageMemoryRequirementsInfo2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImagePlaneMemoryRequirementsInfo(std::ostream &out, const VkImagePlaneMemoryRequirementsInfo* structInfo, Decoded_VkImagePlaneMemoryRequirementsInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageSparseMemoryRequirementsInfo2(std::ostream &out, const VkImageSparseMemoryRequirementsInfo2* structInfo, Decoded_VkImageSparseMemoryRequirementsInfo2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageViewUsageCreateInfo(std::ostream &out, const VkImageViewUsageCreateInfo* structInfo, Decoded_VkImageViewUsageCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkInputAttachmentAspectReference(std::ostream &out, const VkInputAttachmentAspectReference* structInfo, Decoded_VkInputAttachmentAspectReference* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryDedicatedAllocateInfo(std::ostream &out, const VkMemoryDedicatedAllocateInfo* structInfo, Decoded_VkMemoryDedicatedAllocateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryDedicatedRequirements(std::ostream &out, const VkMemoryDedicatedRequirements* structInfo, Decoded_VkMemoryDedicatedRequirements* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryRequirements2(std::ostream &out, const VkMemoryRequirements2* structInfo, Decoded_VkMemoryRequirements2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevice16BitStorageFeatures(std::ostream &out, const VkPhysicalDevice16BitStorageFeatures* structInfo, Decoded_VkPhysicalDevice16BitStorageFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExternalBufferInfo(std::ostream &out, const VkPhysicalDeviceExternalBufferInfo* structInfo, Decoded_VkPhysicalDeviceExternalBufferInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExternalFenceInfo(std::ostream &out, const VkPhysicalDeviceExternalFenceInfo* structInfo, Decoded_VkPhysicalDeviceExternalFenceInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExternalImageFormatInfo(std::ostream &out, const VkPhysicalDeviceExternalImageFormatInfo* structInfo, Decoded_VkPhysicalDeviceExternalImageFormatInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExternalSemaphoreInfo(std::ostream &out, const VkPhysicalDeviceExternalSemaphoreInfo* structInfo, Decoded_VkPhysicalDeviceExternalSemaphoreInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFeatures2(std::ostream &out, const VkPhysicalDeviceFeatures2* structInfo, Decoded_VkPhysicalDeviceFeatures2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceGroupProperties(std::ostream &out, const VkPhysicalDeviceGroupProperties* structInfo, Decoded_VkPhysicalDeviceGroupProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceIDProperties(std::ostream &out, const VkPhysicalDeviceIDProperties* structInfo, Decoded_VkPhysicalDeviceIDProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageFormatInfo2(std::ostream &out, const VkPhysicalDeviceImageFormatInfo2* structInfo, Decoded_VkPhysicalDeviceImageFormatInfo2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMaintenance3Properties(std::ostream &out, const VkPhysicalDeviceMaintenance3Properties* structInfo, Decoded_VkPhysicalDeviceMaintenance3Properties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMemoryProperties2(std::ostream &out, const VkPhysicalDeviceMemoryProperties2* structInfo, Decoded_VkPhysicalDeviceMemoryProperties2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMultiviewFeatures(std::ostream &out, const VkPhysicalDeviceMultiviewFeatures* structInfo, Decoded_VkPhysicalDeviceMultiviewFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMultiviewProperties(std::ostream &out, const VkPhysicalDeviceMultiviewProperties* structInfo, Decoded_VkPhysicalDeviceMultiviewProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePointClippingProperties(std::ostream &out, const VkPhysicalDevicePointClippingProperties* structInfo, Decoded_VkPhysicalDevicePointClippingProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceProperties2(std::ostream &out, const VkPhysicalDeviceProperties2* structInfo, Decoded_VkPhysicalDeviceProperties2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceProtectedMemoryFeatures(std::ostream &out, const VkPhysicalDeviceProtectedMemoryFeatures* structInfo, Decoded_VkPhysicalDeviceProtectedMemoryFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceProtectedMemoryProperties(std::ostream &out, const VkPhysicalDeviceProtectedMemoryProperties* structInfo, Decoded_VkPhysicalDeviceProtectedMemoryProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSamplerYcbcrConversionFeatures(std::ostream &out, const VkPhysicalDeviceSamplerYcbcrConversionFeatures* structInfo, Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderDrawParametersFeatures(std::ostream &out, const VkPhysicalDeviceShaderDrawParametersFeatures* structInfo, Decoded_VkPhysicalDeviceShaderDrawParametersFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSparseImageFormatInfo2(std::ostream &out, const VkPhysicalDeviceSparseImageFormatInfo2* structInfo, Decoded_VkPhysicalDeviceSparseImageFormatInfo2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSubgroupProperties(std::ostream &out, const VkPhysicalDeviceSubgroupProperties* structInfo, Decoded_VkPhysicalDeviceSubgroupProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVariablePointersFeatures(std::ostream &out, const VkPhysicalDeviceVariablePointersFeatures* structInfo, Decoded_VkPhysicalDeviceVariablePointersFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineTessellationDomainOriginStateCreateInfo(std::ostream &out, const VkPipelineTessellationDomainOriginStateCreateInfo* structInfo, Decoded_VkPipelineTessellationDomainOriginStateCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkProtectedSubmitInfo(std::ostream &out, const VkProtectedSubmitInfo* structInfo, Decoded_VkProtectedSubmitInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueueFamilyProperties2(std::ostream &out, const VkQueueFamilyProperties2* structInfo, Decoded_VkQueueFamilyProperties2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassInputAttachmentAspectCreateInfo(std::ostream &out, const VkRenderPassInputAttachmentAspectCreateInfo* structInfo, Decoded_VkRenderPassInputAttachmentAspectCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassMultiviewCreateInfo(std::ostream &out, const VkRenderPassMultiviewCreateInfo* structInfo, Decoded_VkRenderPassMultiviewCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSamplerYcbcrConversionCreateInfo(std::ostream &out, const VkSamplerYcbcrConversionCreateInfo* structInfo, Decoded_VkSamplerYcbcrConversionCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSamplerYcbcrConversionImageFormatProperties(std::ostream &out, const VkSamplerYcbcrConversionImageFormatProperties* structInfo, Decoded_VkSamplerYcbcrConversionImageFormatProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSamplerYcbcrConversionInfo(std::ostream &out, const VkSamplerYcbcrConversionInfo* structInfo, Decoded_VkSamplerYcbcrConversionInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSparseImageFormatProperties2(std::ostream &out, const VkSparseImageFormatProperties2* structInfo, Decoded_VkSparseImageFormatProperties2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSparseImageMemoryRequirements2(std::ostream &out, const VkSparseImageMemoryRequirements2* structInfo, Decoded_VkSparseImageMemoryRequirements2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAttachmentDescription2(std::ostream &out, const VkAttachmentDescription2* structInfo, Decoded_VkAttachmentDescription2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAttachmentDescriptionStencilLayout(std::ostream &out, const VkAttachmentDescriptionStencilLayout* structInfo, Decoded_VkAttachmentDescriptionStencilLayout* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAttachmentReference2(std::ostream &out, const VkAttachmentReference2* structInfo, Decoded_VkAttachmentReference2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAttachmentReferenceStencilLayout(std::ostream &out, const VkAttachmentReferenceStencilLayout* structInfo, Decoded_VkAttachmentReferenceStencilLayout* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferDeviceAddressInfo(std::ostream &out, const VkBufferDeviceAddressInfo* structInfo, Decoded_VkBufferDeviceAddressInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferOpaqueCaptureAddressCreateInfo(std::ostream &out, const VkBufferOpaqueCaptureAddressCreateInfo* structInfo, Decoded_VkBufferOpaqueCaptureAddressCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkConformanceVersion(std::ostream &out, const VkConformanceVersion* structInfo, Decoded_VkConformanceVersion* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorSetLayoutBindingFlagsCreateInfo(std::ostream &out, const VkDescriptorSetLayoutBindingFlagsCreateInfo* structInfo, Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorSetVariableDescriptorCountAllocateInfo(std::ostream &out, const VkDescriptorSetVariableDescriptorCountAllocateInfo* structInfo, Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorSetVariableDescriptorCountLayoutSupport(std::ostream &out, const VkDescriptorSetVariableDescriptorCountLayoutSupport* structInfo, Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupport* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceMemoryOpaqueCaptureAddressInfo(std::ostream &out, const VkDeviceMemoryOpaqueCaptureAddressInfo* structInfo, Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFramebufferAttachmentImageInfo(std::ostream &out, const VkFramebufferAttachmentImageInfo* structInfo, Decoded_VkFramebufferAttachmentImageInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFramebufferAttachmentsCreateInfo(std::ostream &out, const VkFramebufferAttachmentsCreateInfo* structInfo, Decoded_VkFramebufferAttachmentsCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageFormatListCreateInfo(std::ostream &out, const VkImageFormatListCreateInfo* structInfo, Decoded_VkImageFormatListCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageStencilUsageCreateInfo(std::ostream &out, const VkImageStencilUsageCreateInfo* structInfo, Decoded_VkImageStencilUsageCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryOpaqueCaptureAddressAllocateInfo(std::ostream &out, const VkMemoryOpaqueCaptureAddressAllocateInfo* structInfo, Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevice8BitStorageFeatures(std::ostream &out, const VkPhysicalDevice8BitStorageFeatures* structInfo, Decoded_VkPhysicalDevice8BitStorageFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceBufferDeviceAddressFeatures(std::ostream &out, const VkPhysicalDeviceBufferDeviceAddressFeatures* structInfo, Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDepthStencilResolveProperties(std::ostream &out, const VkPhysicalDeviceDepthStencilResolveProperties* structInfo, Decoded_VkPhysicalDeviceDepthStencilResolveProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDescriptorIndexingFeatures(std::ostream &out, const VkPhysicalDeviceDescriptorIndexingFeatures* structInfo, Decoded_VkPhysicalDeviceDescriptorIndexingFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDescriptorIndexingProperties(std::ostream &out, const VkPhysicalDeviceDescriptorIndexingProperties* structInfo, Decoded_VkPhysicalDeviceDescriptorIndexingProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDriverProperties(std::ostream &out, const VkPhysicalDeviceDriverProperties* structInfo, Decoded_VkPhysicalDeviceDriverProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFloatControlsProperties(std::ostream &out, const VkPhysicalDeviceFloatControlsProperties* structInfo, Decoded_VkPhysicalDeviceFloatControlsProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceHostQueryResetFeatures(std::ostream &out, const VkPhysicalDeviceHostQueryResetFeatures* structInfo, Decoded_VkPhysicalDeviceHostQueryResetFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImagelessFramebufferFeatures(std::ostream &out, const VkPhysicalDeviceImagelessFramebufferFeatures* structInfo, Decoded_VkPhysicalDeviceImagelessFramebufferFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSamplerFilterMinmaxProperties(std::ostream &out, const VkPhysicalDeviceSamplerFilterMinmaxProperties* structInfo, Decoded_VkPhysicalDeviceSamplerFilterMinmaxProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceScalarBlockLayoutFeatures(std::ostream &out, const VkPhysicalDeviceScalarBlockLayoutFeatures* structInfo, Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures(std::ostream &out, const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* structInfo, Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderAtomicInt64Features(std::ostream &out, const VkPhysicalDeviceShaderAtomicInt64Features* structInfo, Decoded_VkPhysicalDeviceShaderAtomicInt64Features* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderFloat16Int8Features(std::ostream &out, const VkPhysicalDeviceShaderFloat16Int8Features* structInfo, Decoded_VkPhysicalDeviceShaderFloat16Int8Features* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures(std::ostream &out, const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* structInfo, Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceTimelineSemaphoreFeatures(std::ostream &out, const VkPhysicalDeviceTimelineSemaphoreFeatures* structInfo, Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceTimelineSemaphoreProperties(std::ostream &out, const VkPhysicalDeviceTimelineSemaphoreProperties* structInfo, Decoded_VkPhysicalDeviceTimelineSemaphoreProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceUniformBufferStandardLayoutFeatures(std::ostream &out, const VkPhysicalDeviceUniformBufferStandardLayoutFeatures* structInfo, Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVulkan11Features(std::ostream &out, const VkPhysicalDeviceVulkan11Features* structInfo, Decoded_VkPhysicalDeviceVulkan11Features* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVulkan11Properties(std::ostream &out, const VkPhysicalDeviceVulkan11Properties* structInfo, Decoded_VkPhysicalDeviceVulkan11Properties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVulkan12Features(std::ostream &out, const VkPhysicalDeviceVulkan12Features* structInfo, Decoded_VkPhysicalDeviceVulkan12Features* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVulkan12Properties(std::ostream &out, const VkPhysicalDeviceVulkan12Properties* structInfo, Decoded_VkPhysicalDeviceVulkan12Properties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVulkanMemoryModelFeatures(std::ostream &out, const VkPhysicalDeviceVulkanMemoryModelFeatures* structInfo, Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassAttachmentBeginInfo(std::ostream &out, const VkRenderPassAttachmentBeginInfo* structInfo, Decoded_VkRenderPassAttachmentBeginInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassCreateInfo2(std::ostream &out, const VkRenderPassCreateInfo2* structInfo, Decoded_VkRenderPassCreateInfo2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSamplerReductionModeCreateInfo(std::ostream &out, const VkSamplerReductionModeCreateInfo* structInfo, Decoded_VkSamplerReductionModeCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSemaphoreSignalInfo(std::ostream &out, const VkSemaphoreSignalInfo* structInfo, Decoded_VkSemaphoreSignalInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSemaphoreTypeCreateInfo(std::ostream &out, const VkSemaphoreTypeCreateInfo* structInfo, Decoded_VkSemaphoreTypeCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSemaphoreWaitInfo(std::ostream &out, const VkSemaphoreWaitInfo* structInfo, Decoded_VkSemaphoreWaitInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubpassBeginInfo(std::ostream &out, const VkSubpassBeginInfo* structInfo, Decoded_VkSubpassBeginInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubpassDependency2(std::ostream &out, const VkSubpassDependency2* structInfo, Decoded_VkSubpassDependency2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubpassDescription2(std::ostream &out, const VkSubpassDescription2* structInfo, Decoded_VkSubpassDescription2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubpassDescriptionDepthStencilResolve(std::ostream &out, const VkSubpassDescriptionDepthStencilResolve* structInfo, Decoded_VkSubpassDescriptionDepthStencilResolve* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubpassEndInfo(std::ostream &out, const VkSubpassEndInfo* structInfo, Decoded_VkSubpassEndInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkTimelineSemaphoreSubmitInfo(std::ostream &out, const VkTimelineSemaphoreSubmitInfo* structInfo, Decoded_VkTimelineSemaphoreSubmitInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBlitImageInfo2(std::ostream &out, const VkBlitImageInfo2* structInfo, Decoded_VkBlitImageInfo2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferCopy2(std::ostream &out, const VkBufferCopy2* structInfo, Decoded_VkBufferCopy2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferImageCopy2(std::ostream &out, const VkBufferImageCopy2* structInfo, Decoded_VkBufferImageCopy2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferMemoryBarrier2(std::ostream &out, const VkBufferMemoryBarrier2* structInfo, Decoded_VkBufferMemoryBarrier2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCommandBufferInheritanceRenderingInfo(std::ostream &out, const VkCommandBufferInheritanceRenderingInfo* structInfo, Decoded_VkCommandBufferInheritanceRenderingInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCommandBufferSubmitInfo(std::ostream &out, const VkCommandBufferSubmitInfo* structInfo, Decoded_VkCommandBufferSubmitInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyBufferInfo2(std::ostream &out, const VkCopyBufferInfo2* structInfo, Decoded_VkCopyBufferInfo2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyBufferToImageInfo2(std::ostream &out, const VkCopyBufferToImageInfo2* structInfo, Decoded_VkCopyBufferToImageInfo2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyImageInfo2(std::ostream &out, const VkCopyImageInfo2* structInfo, Decoded_VkCopyImageInfo2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyImageToBufferInfo2(std::ostream &out, const VkCopyImageToBufferInfo2* structInfo, Decoded_VkCopyImageToBufferInfo2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDependencyInfo(std::ostream &out, const VkDependencyInfo* structInfo, Decoded_VkDependencyInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorPoolInlineUniformBlockCreateInfo(std::ostream &out, const VkDescriptorPoolInlineUniformBlockCreateInfo* structInfo, Decoded_VkDescriptorPoolInlineUniformBlockCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceBufferMemoryRequirements(std::ostream &out, const VkDeviceBufferMemoryRequirements* structInfo, Decoded_VkDeviceBufferMemoryRequirements* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceImageMemoryRequirements(std::ostream &out, const VkDeviceImageMemoryRequirements* structInfo, Decoded_VkDeviceImageMemoryRequirements* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDevicePrivateDataCreateInfo(std::ostream &out, const VkDevicePrivateDataCreateInfo* structInfo, Decoded_VkDevicePrivateDataCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFormatProperties3(std::ostream &out, const VkFormatProperties3* structInfo, Decoded_VkFormatProperties3* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageBlit2(std::ostream &out, const VkImageBlit2* structInfo, Decoded_VkImageBlit2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageCopy2(std::ostream &out, const VkImageCopy2* structInfo, Decoded_VkImageCopy2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageMemoryBarrier2(std::ostream &out, const VkImageMemoryBarrier2* structInfo, Decoded_VkImageMemoryBarrier2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageResolve2(std::ostream &out, const VkImageResolve2* structInfo, Decoded_VkImageResolve2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryBarrier2(std::ostream &out, const VkMemoryBarrier2* structInfo, Decoded_VkMemoryBarrier2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDynamicRenderingFeatures(std::ostream &out, const VkPhysicalDeviceDynamicRenderingFeatures* structInfo, Decoded_VkPhysicalDeviceDynamicRenderingFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageRobustnessFeatures(std::ostream &out, const VkPhysicalDeviceImageRobustnessFeatures* structInfo, Decoded_VkPhysicalDeviceImageRobustnessFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceInlineUniformBlockFeatures(std::ostream &out, const VkPhysicalDeviceInlineUniformBlockFeatures* structInfo, Decoded_VkPhysicalDeviceInlineUniformBlockFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceInlineUniformBlockProperties(std::ostream &out, const VkPhysicalDeviceInlineUniformBlockProperties* structInfo, Decoded_VkPhysicalDeviceInlineUniformBlockProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMaintenance4Features(std::ostream &out, const VkPhysicalDeviceMaintenance4Features* structInfo, Decoded_VkPhysicalDeviceMaintenance4Features* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMaintenance4Properties(std::ostream &out, const VkPhysicalDeviceMaintenance4Properties* structInfo, Decoded_VkPhysicalDeviceMaintenance4Properties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePipelineCreationCacheControlFeatures(std::ostream &out, const VkPhysicalDevicePipelineCreationCacheControlFeatures* structInfo, Decoded_VkPhysicalDevicePipelineCreationCacheControlFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePrivateDataFeatures(std::ostream &out, const VkPhysicalDevicePrivateDataFeatures* structInfo, Decoded_VkPhysicalDevicePrivateDataFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures(std::ostream &out, const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* structInfo, Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderIntegerDotProductFeatures(std::ostream &out, const VkPhysicalDeviceShaderIntegerDotProductFeatures* structInfo, Decoded_VkPhysicalDeviceShaderIntegerDotProductFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderIntegerDotProductProperties(std::ostream &out, const VkPhysicalDeviceShaderIntegerDotProductProperties* structInfo, Decoded_VkPhysicalDeviceShaderIntegerDotProductProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderTerminateInvocationFeatures(std::ostream &out, const VkPhysicalDeviceShaderTerminateInvocationFeatures* structInfo, Decoded_VkPhysicalDeviceShaderTerminateInvocationFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSubgroupSizeControlFeatures(std::ostream &out, const VkPhysicalDeviceSubgroupSizeControlFeatures* structInfo, Decoded_VkPhysicalDeviceSubgroupSizeControlFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSubgroupSizeControlProperties(std::ostream &out, const VkPhysicalDeviceSubgroupSizeControlProperties* structInfo, Decoded_VkPhysicalDeviceSubgroupSizeControlProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSynchronization2Features(std::ostream &out, const VkPhysicalDeviceSynchronization2Features* structInfo, Decoded_VkPhysicalDeviceSynchronization2Features* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceTexelBufferAlignmentProperties(std::ostream &out, const VkPhysicalDeviceTexelBufferAlignmentProperties* structInfo, Decoded_VkPhysicalDeviceTexelBufferAlignmentProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceTextureCompressionASTCHDRFeatures(std::ostream &out, const VkPhysicalDeviceTextureCompressionASTCHDRFeatures* structInfo, Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceToolProperties(std::ostream &out, const VkPhysicalDeviceToolProperties* structInfo, Decoded_VkPhysicalDeviceToolProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVulkan13Features(std::ostream &out, const VkPhysicalDeviceVulkan13Features* structInfo, Decoded_VkPhysicalDeviceVulkan13Features* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVulkan13Properties(std::ostream &out, const VkPhysicalDeviceVulkan13Properties* structInfo, Decoded_VkPhysicalDeviceVulkan13Properties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures(std::ostream &out, const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* structInfo, Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineCreationFeedback(std::ostream &out, const VkPipelineCreationFeedback* structInfo, Decoded_VkPipelineCreationFeedback* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineCreationFeedbackCreateInfo(std::ostream &out, const VkPipelineCreationFeedbackCreateInfo* structInfo, Decoded_VkPipelineCreationFeedbackCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineRenderingCreateInfo(std::ostream &out, const VkPipelineRenderingCreateInfo* structInfo, Decoded_VkPipelineRenderingCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo(std::ostream &out, const VkPipelineShaderStageRequiredSubgroupSizeCreateInfo* structInfo, Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPrivateDataSlotCreateInfo(std::ostream &out, const VkPrivateDataSlotCreateInfo* structInfo, Decoded_VkPrivateDataSlotCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderingAttachmentInfo(std::ostream &out, const VkRenderingAttachmentInfo* structInfo, Decoded_VkRenderingAttachmentInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderingInfo(std::ostream &out, const VkRenderingInfo* structInfo, Decoded_VkRenderingInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkResolveImageInfo2(std::ostream &out, const VkResolveImageInfo2* structInfo, Decoded_VkResolveImageInfo2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSemaphoreSubmitInfo(std::ostream &out, const VkSemaphoreSubmitInfo* structInfo, Decoded_VkSemaphoreSubmitInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkWriteDescriptorSetInlineUniformBlock(std::ostream &out, const VkWriteDescriptorSetInlineUniformBlock* structInfo, Decoded_VkWriteDescriptorSetInlineUniformBlock* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindDescriptorSetsInfo(std::ostream &out, const VkBindDescriptorSetsInfo* structInfo, Decoded_VkBindDescriptorSetsInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindMemoryStatus(std::ostream &out, const VkBindMemoryStatus* structInfo, Decoded_VkBindMemoryStatus* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferUsageFlags2CreateInfo(std::ostream &out, const VkBufferUsageFlags2CreateInfo* structInfo, Decoded_VkBufferUsageFlags2CreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyImageToImageInfo(std::ostream &out, const VkCopyImageToImageInfo* structInfo, Decoded_VkCopyImageToImageInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyImageToMemoryInfo(std::ostream &out, const VkCopyImageToMemoryInfo* structInfo, Decoded_VkCopyImageToMemoryInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyMemoryToImageInfo(std::ostream &out, const VkCopyMemoryToImageInfo* structInfo, Decoded_VkCopyMemoryToImageInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceImageSubresourceInfo(std::ostream &out, const VkDeviceImageSubresourceInfo* structInfo, Decoded_VkDeviceImageSubresourceInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceQueueGlobalPriorityCreateInfo(std::ostream &out, const VkDeviceQueueGlobalPriorityCreateInfo* structInfo, Decoded_VkDeviceQueueGlobalPriorityCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkHostImageCopyDevicePerformanceQuery(std::ostream &out, const VkHostImageCopyDevicePerformanceQuery* structInfo, Decoded_VkHostImageCopyDevicePerformanceQuery* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkHostImageLayoutTransitionInfo(std::ostream &out, const VkHostImageLayoutTransitionInfo* structInfo, Decoded_VkHostImageLayoutTransitionInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageSubresource2(std::ostream &out, const VkImageSubresource2* structInfo, Decoded_VkImageSubresource2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageToMemoryCopy(std::ostream &out, const VkImageToMemoryCopy* structInfo, Decoded_VkImageToMemoryCopy* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryMapInfo(std::ostream &out, const VkMemoryMapInfo* structInfo, Decoded_VkMemoryMapInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryToImageCopy(std::ostream &out, const VkMemoryToImageCopy* structInfo, Decoded_VkMemoryToImageCopy* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryUnmapInfo(std::ostream &out, const VkMemoryUnmapInfo* structInfo, Decoded_VkMemoryUnmapInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDynamicRenderingLocalReadFeatures(std::ostream &out, const VkPhysicalDeviceDynamicRenderingLocalReadFeatures* structInfo, Decoded_VkPhysicalDeviceDynamicRenderingLocalReadFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceGlobalPriorityQueryFeatures(std::ostream &out, const VkPhysicalDeviceGlobalPriorityQueryFeatures* structInfo, Decoded_VkPhysicalDeviceGlobalPriorityQueryFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceHostImageCopyFeatures(std::ostream &out, const VkPhysicalDeviceHostImageCopyFeatures* structInfo, Decoded_VkPhysicalDeviceHostImageCopyFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceHostImageCopyProperties(std::ostream &out, const VkPhysicalDeviceHostImageCopyProperties* structInfo, Decoded_VkPhysicalDeviceHostImageCopyProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceIndexTypeUint8Features(std::ostream &out, const VkPhysicalDeviceIndexTypeUint8Features* structInfo, Decoded_VkPhysicalDeviceIndexTypeUint8Features* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceLineRasterizationFeatures(std::ostream &out, const VkPhysicalDeviceLineRasterizationFeatures* structInfo, Decoded_VkPhysicalDeviceLineRasterizationFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceLineRasterizationProperties(std::ostream &out, const VkPhysicalDeviceLineRasterizationProperties* structInfo, Decoded_VkPhysicalDeviceLineRasterizationProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMaintenance5Features(std::ostream &out, const VkPhysicalDeviceMaintenance5Features* structInfo, Decoded_VkPhysicalDeviceMaintenance5Features* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMaintenance5Properties(std::ostream &out, const VkPhysicalDeviceMaintenance5Properties* structInfo, Decoded_VkPhysicalDeviceMaintenance5Properties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMaintenance6Features(std::ostream &out, const VkPhysicalDeviceMaintenance6Features* structInfo, Decoded_VkPhysicalDeviceMaintenance6Features* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMaintenance6Properties(std::ostream &out, const VkPhysicalDeviceMaintenance6Properties* structInfo, Decoded_VkPhysicalDeviceMaintenance6Properties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePipelineProtectedAccessFeatures(std::ostream &out, const VkPhysicalDevicePipelineProtectedAccessFeatures* structInfo, Decoded_VkPhysicalDevicePipelineProtectedAccessFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePipelineRobustnessFeatures(std::ostream &out, const VkPhysicalDevicePipelineRobustnessFeatures* structInfo, Decoded_VkPhysicalDevicePipelineRobustnessFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePipelineRobustnessProperties(std::ostream &out, const VkPhysicalDevicePipelineRobustnessProperties* structInfo, Decoded_VkPhysicalDevicePipelineRobustnessProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePushDescriptorProperties(std::ostream &out, const VkPhysicalDevicePushDescriptorProperties* structInfo, Decoded_VkPhysicalDevicePushDescriptorProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderExpectAssumeFeatures(std::ostream &out, const VkPhysicalDeviceShaderExpectAssumeFeatures* structInfo, Decoded_VkPhysicalDeviceShaderExpectAssumeFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderFloatControls2Features(std::ostream &out, const VkPhysicalDeviceShaderFloatControls2Features* structInfo, Decoded_VkPhysicalDeviceShaderFloatControls2Features* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderSubgroupRotateFeatures(std::ostream &out, const VkPhysicalDeviceShaderSubgroupRotateFeatures* structInfo, Decoded_VkPhysicalDeviceShaderSubgroupRotateFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVertexAttributeDivisorFeatures(std::ostream &out, const VkPhysicalDeviceVertexAttributeDivisorFeatures* structInfo, Decoded_VkPhysicalDeviceVertexAttributeDivisorFeatures* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVertexAttributeDivisorProperties(std::ostream &out, const VkPhysicalDeviceVertexAttributeDivisorProperties* structInfo, Decoded_VkPhysicalDeviceVertexAttributeDivisorProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVulkan14Features(std::ostream &out, const VkPhysicalDeviceVulkan14Features* structInfo, Decoded_VkPhysicalDeviceVulkan14Features* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVulkan14Properties(std::ostream &out, const VkPhysicalDeviceVulkan14Properties* structInfo, Decoded_VkPhysicalDeviceVulkan14Properties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineCreateFlags2CreateInfo(std::ostream &out, const VkPipelineCreateFlags2CreateInfo* structInfo, Decoded_VkPipelineCreateFlags2CreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineRasterizationLineStateCreateInfo(std::ostream &out, const VkPipelineRasterizationLineStateCreateInfo* structInfo, Decoded_VkPipelineRasterizationLineStateCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineRobustnessCreateInfo(std::ostream &out, const VkPipelineRobustnessCreateInfo* structInfo, Decoded_VkPipelineRobustnessCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineVertexInputDivisorStateCreateInfo(std::ostream &out, const VkPipelineVertexInputDivisorStateCreateInfo* structInfo, Decoded_VkPipelineVertexInputDivisorStateCreateInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPushConstantsInfo(std::ostream &out, const VkPushConstantsInfo* structInfo, Decoded_VkPushConstantsInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPushDescriptorSetInfo(std::ostream &out, const VkPushDescriptorSetInfo* structInfo, Decoded_VkPushDescriptorSetInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueueFamilyGlobalPriorityProperties(std::ostream &out, const VkQueueFamilyGlobalPriorityProperties* structInfo, Decoded_VkQueueFamilyGlobalPriorityProperties* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderingAreaInfo(std::ostream &out, const VkRenderingAreaInfo* structInfo, Decoded_VkRenderingAreaInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderingAttachmentLocationInfo(std::ostream &out, const VkRenderingAttachmentLocationInfo* structInfo, Decoded_VkRenderingAttachmentLocationInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderingInputAttachmentIndexInfo(std::ostream &out, const VkRenderingInputAttachmentIndexInfo* structInfo, Decoded_VkRenderingInputAttachmentIndexInfo* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubresourceHostMemcpySize(std::ostream &out, const VkSubresourceHostMemcpySize* structInfo, Decoded_VkSubresourceHostMemcpySize* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubresourceLayout2(std::ostream &out, const VkSubresourceLayout2* structInfo, Decoded_VkSubresourceLayout2* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVertexInputBindingDivisorDescription(std::ostream &out, const VkVertexInputBindingDivisorDescription* structInfo, Decoded_VkVertexInputBindingDivisorDescription* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfaceCapabilitiesKHR(std::ostream &out, const VkSurfaceCapabilitiesKHR* structInfo, Decoded_VkSurfaceCapabilitiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfaceFormatKHR(std::ostream &out, const VkSurfaceFormatKHR* structInfo, Decoded_VkSurfaceFormatKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAcquireNextImageInfoKHR(std::ostream &out, const VkAcquireNextImageInfoKHR* structInfo, Decoded_VkAcquireNextImageInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindImageMemorySwapchainInfoKHR(std::ostream &out, const VkBindImageMemorySwapchainInfoKHR* structInfo, Decoded_VkBindImageMemorySwapchainInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceGroupPresentCapabilitiesKHR(std::ostream &out, const VkDeviceGroupPresentCapabilitiesKHR* structInfo, Decoded_VkDeviceGroupPresentCapabilitiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceGroupPresentInfoKHR(std::ostream &out, const VkDeviceGroupPresentInfoKHR* structInfo, Decoded_VkDeviceGroupPresentInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceGroupSwapchainCreateInfoKHR(std::ostream &out, const VkDeviceGroupSwapchainCreateInfoKHR* structInfo, Decoded_VkDeviceGroupSwapchainCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageSwapchainCreateInfoKHR(std::ostream &out, const VkImageSwapchainCreateInfoKHR* structInfo, Decoded_VkImageSwapchainCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayModeCreateInfoKHR(std::ostream &out, const VkDisplayModeCreateInfoKHR* structInfo, Decoded_VkDisplayModeCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayModeParametersKHR(std::ostream &out, const VkDisplayModeParametersKHR* structInfo, Decoded_VkDisplayModeParametersKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayModePropertiesKHR(std::ostream &out, const VkDisplayModePropertiesKHR* structInfo, Decoded_VkDisplayModePropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayPlaneCapabilitiesKHR(std::ostream &out, const VkDisplayPlaneCapabilitiesKHR* structInfo, Decoded_VkDisplayPlaneCapabilitiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayPlanePropertiesKHR(std::ostream &out, const VkDisplayPlanePropertiesKHR* structInfo, Decoded_VkDisplayPlanePropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayPropertiesKHR(std::ostream &out, const VkDisplayPropertiesKHR* structInfo, Decoded_VkDisplayPropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplaySurfaceCreateInfoKHR(std::ostream &out, const VkDisplaySurfaceCreateInfoKHR* structInfo, Decoded_VkDisplaySurfaceCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayPresentInfoKHR(std::ostream &out, const VkDisplayPresentInfoKHR* structInfo, Decoded_VkDisplayPresentInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkXlibSurfaceCreateInfoKHR(std::ostream &out, const VkXlibSurfaceCreateInfoKHR* structInfo, Decoded_VkXlibSurfaceCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkXcbSurfaceCreateInfoKHR(std::ostream &out, const VkXcbSurfaceCreateInfoKHR* structInfo, Decoded_VkXcbSurfaceCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkWaylandSurfaceCreateInfoKHR(std::ostream &out, const VkWaylandSurfaceCreateInfoKHR* structInfo, Decoded_VkWaylandSurfaceCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAndroidSurfaceCreateInfoKHR(std::ostream &out, const VkAndroidSurfaceCreateInfoKHR* structInfo, Decoded_VkAndroidSurfaceCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkWin32SurfaceCreateInfoKHR(std::ostream &out, const VkWin32SurfaceCreateInfoKHR* structInfo, Decoded_VkWin32SurfaceCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindVideoSessionMemoryInfoKHR(std::ostream &out, const VkBindVideoSessionMemoryInfoKHR* structInfo, Decoded_VkBindVideoSessionMemoryInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVideoFormatInfoKHR(std::ostream &out, const VkPhysicalDeviceVideoFormatInfoKHR* structInfo, Decoded_VkPhysicalDeviceVideoFormatInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueueFamilyQueryResultStatusPropertiesKHR(std::ostream &out, const VkQueueFamilyQueryResultStatusPropertiesKHR* structInfo, Decoded_VkQueueFamilyQueryResultStatusPropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueueFamilyVideoPropertiesKHR(std::ostream &out, const VkQueueFamilyVideoPropertiesKHR* structInfo, Decoded_VkQueueFamilyVideoPropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoBeginCodingInfoKHR(std::ostream &out, const VkVideoBeginCodingInfoKHR* structInfo, Decoded_VkVideoBeginCodingInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoCapabilitiesKHR(std::ostream &out, const VkVideoCapabilitiesKHR* structInfo, Decoded_VkVideoCapabilitiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoCodingControlInfoKHR(std::ostream &out, const VkVideoCodingControlInfoKHR* structInfo, Decoded_VkVideoCodingControlInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEndCodingInfoKHR(std::ostream &out, const VkVideoEndCodingInfoKHR* structInfo, Decoded_VkVideoEndCodingInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoFormatPropertiesKHR(std::ostream &out, const VkVideoFormatPropertiesKHR* structInfo, Decoded_VkVideoFormatPropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoPictureResourceInfoKHR(std::ostream &out, const VkVideoPictureResourceInfoKHR* structInfo, Decoded_VkVideoPictureResourceInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoProfileInfoKHR(std::ostream &out, const VkVideoProfileInfoKHR* structInfo, Decoded_VkVideoProfileInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoProfileListInfoKHR(std::ostream &out, const VkVideoProfileListInfoKHR* structInfo, Decoded_VkVideoProfileListInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoReferenceSlotInfoKHR(std::ostream &out, const VkVideoReferenceSlotInfoKHR* structInfo, Decoded_VkVideoReferenceSlotInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoSessionCreateInfoKHR(std::ostream &out, const VkVideoSessionCreateInfoKHR* structInfo, Decoded_VkVideoSessionCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoSessionMemoryRequirementsKHR(std::ostream &out, const VkVideoSessionMemoryRequirementsKHR* structInfo, Decoded_VkVideoSessionMemoryRequirementsKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoSessionParametersCreateInfoKHR(std::ostream &out, const VkVideoSessionParametersCreateInfoKHR* structInfo, Decoded_VkVideoSessionParametersCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoSessionParametersUpdateInfoKHR(std::ostream &out, const VkVideoSessionParametersUpdateInfoKHR* structInfo, Decoded_VkVideoSessionParametersUpdateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeCapabilitiesKHR(std::ostream &out, const VkVideoDecodeCapabilitiesKHR* structInfo, Decoded_VkVideoDecodeCapabilitiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeInfoKHR(std::ostream &out, const VkVideoDecodeInfoKHR* structInfo, Decoded_VkVideoDecodeInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeUsageInfoKHR(std::ostream &out, const VkVideoDecodeUsageInfoKHR* structInfo, Decoded_VkVideoDecodeUsageInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264CapabilitiesKHR(std::ostream &out, const VkVideoEncodeH264CapabilitiesKHR* structInfo, Decoded_VkVideoEncodeH264CapabilitiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264DpbSlotInfoKHR(std::ostream &out, const VkVideoEncodeH264DpbSlotInfoKHR* structInfo, Decoded_VkVideoEncodeH264DpbSlotInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264FrameSizeKHR(std::ostream &out, const VkVideoEncodeH264FrameSizeKHR* structInfo, Decoded_VkVideoEncodeH264FrameSizeKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264GopRemainingFrameInfoKHR(std::ostream &out, const VkVideoEncodeH264GopRemainingFrameInfoKHR* structInfo, Decoded_VkVideoEncodeH264GopRemainingFrameInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264NaluSliceInfoKHR(std::ostream &out, const VkVideoEncodeH264NaluSliceInfoKHR* structInfo, Decoded_VkVideoEncodeH264NaluSliceInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264PictureInfoKHR(std::ostream &out, const VkVideoEncodeH264PictureInfoKHR* structInfo, Decoded_VkVideoEncodeH264PictureInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264ProfileInfoKHR(std::ostream &out, const VkVideoEncodeH264ProfileInfoKHR* structInfo, Decoded_VkVideoEncodeH264ProfileInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264QpKHR(std::ostream &out, const VkVideoEncodeH264QpKHR* structInfo, Decoded_VkVideoEncodeH264QpKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264QualityLevelPropertiesKHR(std::ostream &out, const VkVideoEncodeH264QualityLevelPropertiesKHR* structInfo, Decoded_VkVideoEncodeH264QualityLevelPropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264RateControlInfoKHR(std::ostream &out, const VkVideoEncodeH264RateControlInfoKHR* structInfo, Decoded_VkVideoEncodeH264RateControlInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264RateControlLayerInfoKHR(std::ostream &out, const VkVideoEncodeH264RateControlLayerInfoKHR* structInfo, Decoded_VkVideoEncodeH264RateControlLayerInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264SessionCreateInfoKHR(std::ostream &out, const VkVideoEncodeH264SessionCreateInfoKHR* structInfo, Decoded_VkVideoEncodeH264SessionCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264SessionParametersAddInfoKHR(std::ostream &out, const VkVideoEncodeH264SessionParametersAddInfoKHR* structInfo, Decoded_VkVideoEncodeH264SessionParametersAddInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264SessionParametersCreateInfoKHR(std::ostream &out, const VkVideoEncodeH264SessionParametersCreateInfoKHR* structInfo, Decoded_VkVideoEncodeH264SessionParametersCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264SessionParametersFeedbackInfoKHR(std::ostream &out, const VkVideoEncodeH264SessionParametersFeedbackInfoKHR* structInfo, Decoded_VkVideoEncodeH264SessionParametersFeedbackInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264SessionParametersGetInfoKHR(std::ostream &out, const VkVideoEncodeH264SessionParametersGetInfoKHR* structInfo, Decoded_VkVideoEncodeH264SessionParametersGetInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265CapabilitiesKHR(std::ostream &out, const VkVideoEncodeH265CapabilitiesKHR* structInfo, Decoded_VkVideoEncodeH265CapabilitiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265DpbSlotInfoKHR(std::ostream &out, const VkVideoEncodeH265DpbSlotInfoKHR* structInfo, Decoded_VkVideoEncodeH265DpbSlotInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265FrameSizeKHR(std::ostream &out, const VkVideoEncodeH265FrameSizeKHR* structInfo, Decoded_VkVideoEncodeH265FrameSizeKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265GopRemainingFrameInfoKHR(std::ostream &out, const VkVideoEncodeH265GopRemainingFrameInfoKHR* structInfo, Decoded_VkVideoEncodeH265GopRemainingFrameInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265NaluSliceSegmentInfoKHR(std::ostream &out, const VkVideoEncodeH265NaluSliceSegmentInfoKHR* structInfo, Decoded_VkVideoEncodeH265NaluSliceSegmentInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265PictureInfoKHR(std::ostream &out, const VkVideoEncodeH265PictureInfoKHR* structInfo, Decoded_VkVideoEncodeH265PictureInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265ProfileInfoKHR(std::ostream &out, const VkVideoEncodeH265ProfileInfoKHR* structInfo, Decoded_VkVideoEncodeH265ProfileInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265QpKHR(std::ostream &out, const VkVideoEncodeH265QpKHR* structInfo, Decoded_VkVideoEncodeH265QpKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265QualityLevelPropertiesKHR(std::ostream &out, const VkVideoEncodeH265QualityLevelPropertiesKHR* structInfo, Decoded_VkVideoEncodeH265QualityLevelPropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265RateControlInfoKHR(std::ostream &out, const VkVideoEncodeH265RateControlInfoKHR* structInfo, Decoded_VkVideoEncodeH265RateControlInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265RateControlLayerInfoKHR(std::ostream &out, const VkVideoEncodeH265RateControlLayerInfoKHR* structInfo, Decoded_VkVideoEncodeH265RateControlLayerInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265SessionCreateInfoKHR(std::ostream &out, const VkVideoEncodeH265SessionCreateInfoKHR* structInfo, Decoded_VkVideoEncodeH265SessionCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265SessionParametersAddInfoKHR(std::ostream &out, const VkVideoEncodeH265SessionParametersAddInfoKHR* structInfo, Decoded_VkVideoEncodeH265SessionParametersAddInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265SessionParametersCreateInfoKHR(std::ostream &out, const VkVideoEncodeH265SessionParametersCreateInfoKHR* structInfo, Decoded_VkVideoEncodeH265SessionParametersCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265SessionParametersFeedbackInfoKHR(std::ostream &out, const VkVideoEncodeH265SessionParametersFeedbackInfoKHR* structInfo, Decoded_VkVideoEncodeH265SessionParametersFeedbackInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265SessionParametersGetInfoKHR(std::ostream &out, const VkVideoEncodeH265SessionParametersGetInfoKHR* structInfo, Decoded_VkVideoEncodeH265SessionParametersGetInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH264CapabilitiesKHR(std::ostream &out, const VkVideoDecodeH264CapabilitiesKHR* structInfo, Decoded_VkVideoDecodeH264CapabilitiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH264DpbSlotInfoKHR(std::ostream &out, const VkVideoDecodeH264DpbSlotInfoKHR* structInfo, Decoded_VkVideoDecodeH264DpbSlotInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH264PictureInfoKHR(std::ostream &out, const VkVideoDecodeH264PictureInfoKHR* structInfo, Decoded_VkVideoDecodeH264PictureInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH264ProfileInfoKHR(std::ostream &out, const VkVideoDecodeH264ProfileInfoKHR* structInfo, Decoded_VkVideoDecodeH264ProfileInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH264SessionParametersAddInfoKHR(std::ostream &out, const VkVideoDecodeH264SessionParametersAddInfoKHR* structInfo, Decoded_VkVideoDecodeH264SessionParametersAddInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH264SessionParametersCreateInfoKHR(std::ostream &out, const VkVideoDecodeH264SessionParametersCreateInfoKHR* structInfo, Decoded_VkVideoDecodeH264SessionParametersCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExportMemoryWin32HandleInfoKHR(std::ostream &out, const VkExportMemoryWin32HandleInfoKHR* structInfo, Decoded_VkExportMemoryWin32HandleInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImportMemoryWin32HandleInfoKHR(std::ostream &out, const VkImportMemoryWin32HandleInfoKHR* structInfo, Decoded_VkImportMemoryWin32HandleInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryGetWin32HandleInfoKHR(std::ostream &out, const VkMemoryGetWin32HandleInfoKHR* structInfo, Decoded_VkMemoryGetWin32HandleInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryWin32HandlePropertiesKHR(std::ostream &out, const VkMemoryWin32HandlePropertiesKHR* structInfo, Decoded_VkMemoryWin32HandlePropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImportMemoryFdInfoKHR(std::ostream &out, const VkImportMemoryFdInfoKHR* structInfo, Decoded_VkImportMemoryFdInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryFdPropertiesKHR(std::ostream &out, const VkMemoryFdPropertiesKHR* structInfo, Decoded_VkMemoryFdPropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryGetFdInfoKHR(std::ostream &out, const VkMemoryGetFdInfoKHR* structInfo, Decoded_VkMemoryGetFdInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkWin32KeyedMutexAcquireReleaseInfoKHR(std::ostream &out, const VkWin32KeyedMutexAcquireReleaseInfoKHR* structInfo, Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkD3D12FenceSubmitInfoKHR(std::ostream &out, const VkD3D12FenceSubmitInfoKHR* structInfo, Decoded_VkD3D12FenceSubmitInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExportSemaphoreWin32HandleInfoKHR(std::ostream &out, const VkExportSemaphoreWin32HandleInfoKHR* structInfo, Decoded_VkExportSemaphoreWin32HandleInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImportSemaphoreWin32HandleInfoKHR(std::ostream &out, const VkImportSemaphoreWin32HandleInfoKHR* structInfo, Decoded_VkImportSemaphoreWin32HandleInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSemaphoreGetWin32HandleInfoKHR(std::ostream &out, const VkSemaphoreGetWin32HandleInfoKHR* structInfo, Decoded_VkSemaphoreGetWin32HandleInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImportSemaphoreFdInfoKHR(std::ostream &out, const VkImportSemaphoreFdInfoKHR* structInfo, Decoded_VkImportSemaphoreFdInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSemaphoreGetFdInfoKHR(std::ostream &out, const VkSemaphoreGetFdInfoKHR* structInfo, Decoded_VkSemaphoreGetFdInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPresentRegionKHR(std::ostream &out, const VkPresentRegionKHR* structInfo, Decoded_VkPresentRegionKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPresentRegionsKHR(std::ostream &out, const VkPresentRegionsKHR* structInfo, Decoded_VkPresentRegionsKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRectLayerKHR(std::ostream &out, const VkRectLayerKHR* structInfo, Decoded_VkRectLayerKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSharedPresentSurfaceCapabilitiesKHR(std::ostream &out, const VkSharedPresentSurfaceCapabilitiesKHR* structInfo, Decoded_VkSharedPresentSurfaceCapabilitiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExportFenceWin32HandleInfoKHR(std::ostream &out, const VkExportFenceWin32HandleInfoKHR* structInfo, Decoded_VkExportFenceWin32HandleInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFenceGetWin32HandleInfoKHR(std::ostream &out, const VkFenceGetWin32HandleInfoKHR* structInfo, Decoded_VkFenceGetWin32HandleInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImportFenceWin32HandleInfoKHR(std::ostream &out, const VkImportFenceWin32HandleInfoKHR* structInfo, Decoded_VkImportFenceWin32HandleInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFenceGetFdInfoKHR(std::ostream &out, const VkFenceGetFdInfoKHR* structInfo, Decoded_VkFenceGetFdInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImportFenceFdInfoKHR(std::ostream &out, const VkImportFenceFdInfoKHR* structInfo, Decoded_VkImportFenceFdInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAcquireProfilingLockInfoKHR(std::ostream &out, const VkAcquireProfilingLockInfoKHR* structInfo, Decoded_VkAcquireProfilingLockInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPerformanceCounterDescriptionKHR(std::ostream &out, const VkPerformanceCounterDescriptionKHR* structInfo, Decoded_VkPerformanceCounterDescriptionKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPerformanceCounterKHR(std::ostream &out, const VkPerformanceCounterKHR* structInfo, Decoded_VkPerformanceCounterKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPerformanceQuerySubmitInfoKHR(std::ostream &out, const VkPerformanceQuerySubmitInfoKHR* structInfo, Decoded_VkPerformanceQuerySubmitInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePerformanceQueryFeaturesKHR(std::ostream &out, const VkPhysicalDevicePerformanceQueryFeaturesKHR* structInfo, Decoded_VkPhysicalDevicePerformanceQueryFeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePerformanceQueryPropertiesKHR(std::ostream &out, const VkPhysicalDevicePerformanceQueryPropertiesKHR* structInfo, Decoded_VkPhysicalDevicePerformanceQueryPropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueryPoolPerformanceCreateInfoKHR(std::ostream &out, const VkQueryPoolPerformanceCreateInfoKHR* structInfo, Decoded_VkQueryPoolPerformanceCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSurfaceInfo2KHR(std::ostream &out, const VkPhysicalDeviceSurfaceInfo2KHR* structInfo, Decoded_VkPhysicalDeviceSurfaceInfo2KHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfaceCapabilities2KHR(std::ostream &out, const VkSurfaceCapabilities2KHR* structInfo, Decoded_VkSurfaceCapabilities2KHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfaceFormat2KHR(std::ostream &out, const VkSurfaceFormat2KHR* structInfo, Decoded_VkSurfaceFormat2KHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayModeProperties2KHR(std::ostream &out, const VkDisplayModeProperties2KHR* structInfo, Decoded_VkDisplayModeProperties2KHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayPlaneCapabilities2KHR(std::ostream &out, const VkDisplayPlaneCapabilities2KHR* structInfo, Decoded_VkDisplayPlaneCapabilities2KHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayPlaneInfo2KHR(std::ostream &out, const VkDisplayPlaneInfo2KHR* structInfo, Decoded_VkDisplayPlaneInfo2KHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayPlaneProperties2KHR(std::ostream &out, const VkDisplayPlaneProperties2KHR* structInfo, Decoded_VkDisplayPlaneProperties2KHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayProperties2KHR(std::ostream &out, const VkDisplayProperties2KHR* structInfo, Decoded_VkDisplayProperties2KHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePortabilitySubsetFeaturesKHR(std::ostream &out, const VkPhysicalDevicePortabilitySubsetFeaturesKHR* structInfo, Decoded_VkPhysicalDevicePortabilitySubsetFeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePortabilitySubsetPropertiesKHR(std::ostream &out, const VkPhysicalDevicePortabilitySubsetPropertiesKHR* structInfo, Decoded_VkPhysicalDevicePortabilitySubsetPropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderClockFeaturesKHR(std::ostream &out, const VkPhysicalDeviceShaderClockFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceShaderClockFeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH265CapabilitiesKHR(std::ostream &out, const VkVideoDecodeH265CapabilitiesKHR* structInfo, Decoded_VkVideoDecodeH265CapabilitiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH265DpbSlotInfoKHR(std::ostream &out, const VkVideoDecodeH265DpbSlotInfoKHR* structInfo, Decoded_VkVideoDecodeH265DpbSlotInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH265PictureInfoKHR(std::ostream &out, const VkVideoDecodeH265PictureInfoKHR* structInfo, Decoded_VkVideoDecodeH265PictureInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH265ProfileInfoKHR(std::ostream &out, const VkVideoDecodeH265ProfileInfoKHR* structInfo, Decoded_VkVideoDecodeH265ProfileInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH265SessionParametersAddInfoKHR(std::ostream &out, const VkVideoDecodeH265SessionParametersAddInfoKHR* structInfo, Decoded_VkVideoDecodeH265SessionParametersAddInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH265SessionParametersCreateInfoKHR(std::ostream &out, const VkVideoDecodeH265SessionParametersCreateInfoKHR* structInfo, Decoded_VkVideoDecodeH265SessionParametersCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFragmentShadingRateAttachmentInfoKHR(std::ostream &out, const VkFragmentShadingRateAttachmentInfoKHR* structInfo, Decoded_VkFragmentShadingRateAttachmentInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentShadingRateFeaturesKHR(std::ostream &out, const VkPhysicalDeviceFragmentShadingRateFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceFragmentShadingRateFeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentShadingRateKHR(std::ostream &out, const VkPhysicalDeviceFragmentShadingRateKHR* structInfo, Decoded_VkPhysicalDeviceFragmentShadingRateKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentShadingRatePropertiesKHR(std::ostream &out, const VkPhysicalDeviceFragmentShadingRatePropertiesKHR* structInfo, Decoded_VkPhysicalDeviceFragmentShadingRatePropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineFragmentShadingRateStateCreateInfoKHR(std::ostream &out, const VkPipelineFragmentShadingRateStateCreateInfoKHR* structInfo, Decoded_VkPipelineFragmentShadingRateStateCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderingFragmentShadingRateAttachmentInfoKHR(std::ostream &out, const VkRenderingFragmentShadingRateAttachmentInfoKHR* structInfo, Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderQuadControlFeaturesKHR(std::ostream &out, const VkPhysicalDeviceShaderQuadControlFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceShaderQuadControlFeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfaceProtectedCapabilitiesKHR(std::ostream &out, const VkSurfaceProtectedCapabilitiesKHR* structInfo, Decoded_VkSurfaceProtectedCapabilitiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePresentWaitFeaturesKHR(std::ostream &out, const VkPhysicalDevicePresentWaitFeaturesKHR* structInfo, Decoded_VkPhysicalDevicePresentWaitFeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR(std::ostream &out, const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* structInfo, Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineExecutableInfoKHR(std::ostream &out, const VkPipelineExecutableInfoKHR* structInfo, Decoded_VkPipelineExecutableInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineExecutableInternalRepresentationKHR(std::ostream &out, const VkPipelineExecutableInternalRepresentationKHR* structInfo, Decoded_VkPipelineExecutableInternalRepresentationKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineExecutablePropertiesKHR(std::ostream &out, const VkPipelineExecutablePropertiesKHR* structInfo, Decoded_VkPipelineExecutablePropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineExecutableStatisticKHR(std::ostream &out, const VkPipelineExecutableStatisticKHR* structInfo, Decoded_VkPipelineExecutableStatisticKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineInfoKHR(std::ostream &out, const VkPipelineInfoKHR* structInfo, Decoded_VkPipelineInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineLibraryCreateInfoKHR(std::ostream &out, const VkPipelineLibraryCreateInfoKHR* structInfo, Decoded_VkPipelineLibraryCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePresentIdFeaturesKHR(std::ostream &out, const VkPhysicalDevicePresentIdFeaturesKHR* structInfo, Decoded_VkPhysicalDevicePresentIdFeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPresentIdKHR(std::ostream &out, const VkPresentIdKHR* structInfo, Decoded_VkPresentIdKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR(std::ostream &out, const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* structInfo, Decoded_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR(std::ostream &out, const VkQueryPoolVideoEncodeFeedbackCreateInfoKHR* structInfo, Decoded_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeCapabilitiesKHR(std::ostream &out, const VkVideoEncodeCapabilitiesKHR* structInfo, Decoded_VkVideoEncodeCapabilitiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeInfoKHR(std::ostream &out, const VkVideoEncodeInfoKHR* structInfo, Decoded_VkVideoEncodeInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeQualityLevelInfoKHR(std::ostream &out, const VkVideoEncodeQualityLevelInfoKHR* structInfo, Decoded_VkVideoEncodeQualityLevelInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeQualityLevelPropertiesKHR(std::ostream &out, const VkVideoEncodeQualityLevelPropertiesKHR* structInfo, Decoded_VkVideoEncodeQualityLevelPropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeRateControlInfoKHR(std::ostream &out, const VkVideoEncodeRateControlInfoKHR* structInfo, Decoded_VkVideoEncodeRateControlInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeRateControlLayerInfoKHR(std::ostream &out, const VkVideoEncodeRateControlLayerInfoKHR* structInfo, Decoded_VkVideoEncodeRateControlLayerInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeSessionParametersFeedbackInfoKHR(std::ostream &out, const VkVideoEncodeSessionParametersFeedbackInfoKHR* structInfo, Decoded_VkVideoEncodeSessionParametersFeedbackInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeSessionParametersGetInfoKHR(std::ostream &out, const VkVideoEncodeSessionParametersGetInfoKHR* structInfo, Decoded_VkVideoEncodeSessionParametersGetInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeUsageInfoKHR(std::ostream &out, const VkVideoEncodeUsageInfoKHR* structInfo, Decoded_VkVideoEncodeUsageInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR(std::ostream &out, const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR(std::ostream &out, const VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR* structInfo, Decoded_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR(std::ostream &out, const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR(std::ostream &out, const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR(std::ostream &out, const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* structInfo, Decoded_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkTraceRaysIndirectCommand2KHR(std::ostream &out, const VkTraceRaysIndirectCommand2KHR* structInfo, Decoded_VkTraceRaysIndirectCommand2KHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR(std::ostream &out, const VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR(std::ostream &out, const VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDevicePipelineBinaryInternalCacheControlKHR(std::ostream &out, const VkDevicePipelineBinaryInternalCacheControlKHR* structInfo, Decoded_VkDevicePipelineBinaryInternalCacheControlKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePipelineBinaryFeaturesKHR(std::ostream &out, const VkPhysicalDevicePipelineBinaryFeaturesKHR* structInfo, Decoded_VkPhysicalDevicePipelineBinaryFeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePipelineBinaryPropertiesKHR(std::ostream &out, const VkPhysicalDevicePipelineBinaryPropertiesKHR* structInfo, Decoded_VkPhysicalDevicePipelineBinaryPropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineBinaryCreateInfoKHR(std::ostream &out, const VkPipelineBinaryCreateInfoKHR* structInfo, Decoded_VkPipelineBinaryCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineBinaryDataInfoKHR(std::ostream &out, const VkPipelineBinaryDataInfoKHR* structInfo, Decoded_VkPipelineBinaryDataInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineBinaryDataKHR(std::ostream &out, const VkPipelineBinaryDataKHR* structInfo, Decoded_VkPipelineBinaryDataKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineBinaryHandlesInfoKHR(std::ostream &out, const VkPipelineBinaryHandlesInfoKHR* structInfo, Decoded_VkPipelineBinaryHandlesInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineBinaryInfoKHR(std::ostream &out, const VkPipelineBinaryInfoKHR* structInfo, Decoded_VkPipelineBinaryInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineBinaryKeyKHR(std::ostream &out, const VkPipelineBinaryKeyKHR* structInfo, Decoded_VkPipelineBinaryKeyKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineBinaryKeysAndDataKHR(std::ostream &out, const VkPipelineBinaryKeysAndDataKHR* structInfo, Decoded_VkPipelineBinaryKeysAndDataKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineCreateInfoKHR(std::ostream &out, const VkPipelineCreateInfoKHR* structInfo, Decoded_VkPipelineCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkReleaseCapturedPipelineDataInfoKHR(std::ostream &out, const VkReleaseCapturedPipelineDataInfoKHR* structInfo, Decoded_VkReleaseCapturedPipelineDataInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCooperativeMatrixPropertiesKHR(std::ostream &out, const VkCooperativeMatrixPropertiesKHR* structInfo, Decoded_VkCooperativeMatrixPropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCooperativeMatrixFeaturesKHR(std::ostream &out, const VkPhysicalDeviceCooperativeMatrixFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCooperativeMatrixPropertiesKHR(std::ostream &out, const VkPhysicalDeviceCooperativeMatrixPropertiesKHR* structInfo, Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR(std::ostream &out, const VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR(std::ostream &out, const VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR* structInfo, Decoded_VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeAV1CapabilitiesKHR(std::ostream &out, const VkVideoDecodeAV1CapabilitiesKHR* structInfo, Decoded_VkVideoDecodeAV1CapabilitiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeAV1DpbSlotInfoKHR(std::ostream &out, const VkVideoDecodeAV1DpbSlotInfoKHR* structInfo, Decoded_VkVideoDecodeAV1DpbSlotInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeAV1PictureInfoKHR(std::ostream &out, const VkVideoDecodeAV1PictureInfoKHR* structInfo, Decoded_VkVideoDecodeAV1PictureInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeAV1ProfileInfoKHR(std::ostream &out, const VkVideoDecodeAV1ProfileInfoKHR* structInfo, Decoded_VkVideoDecodeAV1ProfileInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeAV1SessionParametersCreateInfoKHR(std::ostream &out, const VkVideoDecodeAV1SessionParametersCreateInfoKHR* structInfo, Decoded_VkVideoDecodeAV1SessionParametersCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVideoEncodeAV1FeaturesKHR(std::ostream &out, const VkPhysicalDeviceVideoEncodeAV1FeaturesKHR* structInfo, Decoded_VkPhysicalDeviceVideoEncodeAV1FeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeAV1CapabilitiesKHR(std::ostream &out, const VkVideoEncodeAV1CapabilitiesKHR* structInfo, Decoded_VkVideoEncodeAV1CapabilitiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeAV1DpbSlotInfoKHR(std::ostream &out, const VkVideoEncodeAV1DpbSlotInfoKHR* structInfo, Decoded_VkVideoEncodeAV1DpbSlotInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeAV1FrameSizeKHR(std::ostream &out, const VkVideoEncodeAV1FrameSizeKHR* structInfo, Decoded_VkVideoEncodeAV1FrameSizeKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeAV1GopRemainingFrameInfoKHR(std::ostream &out, const VkVideoEncodeAV1GopRemainingFrameInfoKHR* structInfo, Decoded_VkVideoEncodeAV1GopRemainingFrameInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeAV1PictureInfoKHR(std::ostream &out, const VkVideoEncodeAV1PictureInfoKHR* structInfo, Decoded_VkVideoEncodeAV1PictureInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeAV1ProfileInfoKHR(std::ostream &out, const VkVideoEncodeAV1ProfileInfoKHR* structInfo, Decoded_VkVideoEncodeAV1ProfileInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeAV1QIndexKHR(std::ostream &out, const VkVideoEncodeAV1QIndexKHR* structInfo, Decoded_VkVideoEncodeAV1QIndexKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeAV1QualityLevelPropertiesKHR(std::ostream &out, const VkVideoEncodeAV1QualityLevelPropertiesKHR* structInfo, Decoded_VkVideoEncodeAV1QualityLevelPropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeAV1RateControlInfoKHR(std::ostream &out, const VkVideoEncodeAV1RateControlInfoKHR* structInfo, Decoded_VkVideoEncodeAV1RateControlInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeAV1RateControlLayerInfoKHR(std::ostream &out, const VkVideoEncodeAV1RateControlLayerInfoKHR* structInfo, Decoded_VkVideoEncodeAV1RateControlLayerInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeAV1SessionCreateInfoKHR(std::ostream &out, const VkVideoEncodeAV1SessionCreateInfoKHR* structInfo, Decoded_VkVideoEncodeAV1SessionCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeAV1SessionParametersCreateInfoKHR(std::ostream &out, const VkVideoEncodeAV1SessionParametersCreateInfoKHR* structInfo, Decoded_VkVideoEncodeAV1SessionParametersCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVideoMaintenance1FeaturesKHR(std::ostream &out, const VkPhysicalDeviceVideoMaintenance1FeaturesKHR* structInfo, Decoded_VkPhysicalDeviceVideoMaintenance1FeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoInlineQueryInfoKHR(std::ostream &out, const VkVideoInlineQueryInfoKHR* structInfo, Decoded_VkVideoInlineQueryInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCalibratedTimestampInfoKHR(std::ostream &out, const VkCalibratedTimestampInfoKHR* structInfo, Decoded_VkCalibratedTimestampInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindDescriptorBufferEmbeddedSamplersInfoEXT(std::ostream &out, const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* structInfo, Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSetDescriptorBufferOffsetsInfoEXT(std::ostream &out, const VkSetDescriptorBufferOffsetsInfoEXT* structInfo, Decoded_VkSetDescriptorBufferOffsetsInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR(std::ostream &out, const VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeAV1QuantizationMapCapabilitiesKHR(std::ostream &out, const VkVideoEncodeAV1QuantizationMapCapabilitiesKHR* structInfo, Decoded_VkVideoEncodeAV1QuantizationMapCapabilitiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264QuantizationMapCapabilitiesKHR(std::ostream &out, const VkVideoEncodeH264QuantizationMapCapabilitiesKHR* structInfo, Decoded_VkVideoEncodeH264QuantizationMapCapabilitiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265QuantizationMapCapabilitiesKHR(std::ostream &out, const VkVideoEncodeH265QuantizationMapCapabilitiesKHR* structInfo, Decoded_VkVideoEncodeH265QuantizationMapCapabilitiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeQuantizationMapCapabilitiesKHR(std::ostream &out, const VkVideoEncodeQuantizationMapCapabilitiesKHR* structInfo, Decoded_VkVideoEncodeQuantizationMapCapabilitiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeQuantizationMapInfoKHR(std::ostream &out, const VkVideoEncodeQuantizationMapInfoKHR* structInfo, Decoded_VkVideoEncodeQuantizationMapInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR(std::ostream &out, const VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR* structInfo, Decoded_VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoFormatAV1QuantizationMapPropertiesKHR(std::ostream &out, const VkVideoFormatAV1QuantizationMapPropertiesKHR* structInfo, Decoded_VkVideoFormatAV1QuantizationMapPropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoFormatH265QuantizationMapPropertiesKHR(std::ostream &out, const VkVideoFormatH265QuantizationMapPropertiesKHR* structInfo, Decoded_VkVideoFormatH265QuantizationMapPropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoFormatQuantizationMapPropertiesKHR(std::ostream &out, const VkVideoFormatQuantizationMapPropertiesKHR* structInfo, Decoded_VkVideoFormatQuantizationMapPropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR(std::ostream &out, const VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceLayeredApiPropertiesKHR(std::ostream &out, const VkPhysicalDeviceLayeredApiPropertiesKHR* structInfo, Decoded_VkPhysicalDeviceLayeredApiPropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceLayeredApiPropertiesListKHR(std::ostream &out, const VkPhysicalDeviceLayeredApiPropertiesListKHR* structInfo, Decoded_VkPhysicalDeviceLayeredApiPropertiesListKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceLayeredApiVulkanPropertiesKHR(std::ostream &out, const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR* structInfo, Decoded_VkPhysicalDeviceLayeredApiVulkanPropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMaintenance7FeaturesKHR(std::ostream &out, const VkPhysicalDeviceMaintenance7FeaturesKHR* structInfo, Decoded_VkPhysicalDeviceMaintenance7FeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMaintenance7PropertiesKHR(std::ostream &out, const VkPhysicalDeviceMaintenance7PropertiesKHR* structInfo, Decoded_VkPhysicalDeviceMaintenance7PropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryBarrierAccessFlags3KHR(std::ostream &out, const VkMemoryBarrierAccessFlags3KHR* structInfo, Decoded_VkMemoryBarrierAccessFlags3KHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMaintenance8FeaturesKHR(std::ostream &out, const VkPhysicalDeviceMaintenance8FeaturesKHR* structInfo, Decoded_VkPhysicalDeviceMaintenance8FeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVideoMaintenance2FeaturesKHR(std::ostream &out, const VkPhysicalDeviceVideoMaintenance2FeaturesKHR* structInfo, Decoded_VkPhysicalDeviceVideoMaintenance2FeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeAV1InlineSessionParametersInfoKHR(std::ostream &out, const VkVideoDecodeAV1InlineSessionParametersInfoKHR* structInfo, Decoded_VkVideoDecodeAV1InlineSessionParametersInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH264InlineSessionParametersInfoKHR(std::ostream &out, const VkVideoDecodeH264InlineSessionParametersInfoKHR* structInfo, Decoded_VkVideoDecodeH264InlineSessionParametersInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH265InlineSessionParametersInfoKHR(std::ostream &out, const VkVideoDecodeH265InlineSessionParametersInfoKHR* structInfo, Decoded_VkVideoDecodeH265InlineSessionParametersInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR(std::ostream &out, const VkPhysicalDeviceDepthClampZeroOneFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDebugReportCallbackCreateInfoEXT(std::ostream &out, const VkDebugReportCallbackCreateInfoEXT* structInfo, Decoded_VkDebugReportCallbackCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineRasterizationStateRasterizationOrderAMD(std::ostream &out, const VkPipelineRasterizationStateRasterizationOrderAMD* structInfo, Decoded_VkPipelineRasterizationStateRasterizationOrderAMD* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDebugMarkerMarkerInfoEXT(std::ostream &out, const VkDebugMarkerMarkerInfoEXT* structInfo, Decoded_VkDebugMarkerMarkerInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDebugMarkerObjectNameInfoEXT(std::ostream &out, const VkDebugMarkerObjectNameInfoEXT* structInfo, Decoded_VkDebugMarkerObjectNameInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDebugMarkerObjectTagInfoEXT(std::ostream &out, const VkDebugMarkerObjectTagInfoEXT* structInfo, Decoded_VkDebugMarkerObjectTagInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDedicatedAllocationBufferCreateInfoNV(std::ostream &out, const VkDedicatedAllocationBufferCreateInfoNV* structInfo, Decoded_VkDedicatedAllocationBufferCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDedicatedAllocationImageCreateInfoNV(std::ostream &out, const VkDedicatedAllocationImageCreateInfoNV* structInfo, Decoded_VkDedicatedAllocationImageCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDedicatedAllocationMemoryAllocateInfoNV(std::ostream &out, const VkDedicatedAllocationMemoryAllocateInfoNV* structInfo, Decoded_VkDedicatedAllocationMemoryAllocateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceTransformFeedbackFeaturesEXT(std::ostream &out, const VkPhysicalDeviceTransformFeedbackFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceTransformFeedbackPropertiesEXT(std::ostream &out, const VkPhysicalDeviceTransformFeedbackPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineRasterizationStateStreamCreateInfoEXT(std::ostream &out, const VkPipelineRasterizationStateStreamCreateInfoEXT* structInfo, Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageViewAddressPropertiesNVX(std::ostream &out, const VkImageViewAddressPropertiesNVX* structInfo, Decoded_VkImageViewAddressPropertiesNVX* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageViewHandleInfoNVX(std::ostream &out, const VkImageViewHandleInfoNVX* structInfo, Decoded_VkImageViewHandleInfoNVX* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkTextureLODGatherFormatPropertiesAMD(std::ostream &out, const VkTextureLODGatherFormatPropertiesAMD* structInfo, Decoded_VkTextureLODGatherFormatPropertiesAMD* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkShaderResourceUsageAMD(std::ostream &out, const VkShaderResourceUsageAMD* structInfo, Decoded_VkShaderResourceUsageAMD* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkShaderStatisticsInfoAMD(std::ostream &out, const VkShaderStatisticsInfoAMD* structInfo, Decoded_VkShaderStatisticsInfoAMD* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkStreamDescriptorSurfaceCreateInfoGGP(std::ostream &out, const VkStreamDescriptorSurfaceCreateInfoGGP* structInfo, Decoded_VkStreamDescriptorSurfaceCreateInfoGGP* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCornerSampledImageFeaturesNV(std::ostream &out, const VkPhysicalDeviceCornerSampledImageFeaturesNV* structInfo, Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExternalImageFormatPropertiesNV(std::ostream &out, const VkExternalImageFormatPropertiesNV* structInfo, Decoded_VkExternalImageFormatPropertiesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExportMemoryAllocateInfoNV(std::ostream &out, const VkExportMemoryAllocateInfoNV* structInfo, Decoded_VkExportMemoryAllocateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExternalMemoryImageCreateInfoNV(std::ostream &out, const VkExternalMemoryImageCreateInfoNV* structInfo, Decoded_VkExternalMemoryImageCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExportMemoryWin32HandleInfoNV(std::ostream &out, const VkExportMemoryWin32HandleInfoNV* structInfo, Decoded_VkExportMemoryWin32HandleInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImportMemoryWin32HandleInfoNV(std::ostream &out, const VkImportMemoryWin32HandleInfoNV* structInfo, Decoded_VkImportMemoryWin32HandleInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkWin32KeyedMutexAcquireReleaseInfoNV(std::ostream &out, const VkWin32KeyedMutexAcquireReleaseInfoNV* structInfo, Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkValidationFlagsEXT(std::ostream &out, const VkValidationFlagsEXT* structInfo, Decoded_VkValidationFlagsEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkViSurfaceCreateInfoNN(std::ostream &out, const VkViSurfaceCreateInfoNN* structInfo, Decoded_VkViSurfaceCreateInfoNN* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageViewASTCDecodeModeEXT(std::ostream &out, const VkImageViewASTCDecodeModeEXT* structInfo, Decoded_VkImageViewASTCDecodeModeEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceASTCDecodeFeaturesEXT(std::ostream &out, const VkPhysicalDeviceASTCDecodeFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCommandBufferInheritanceConditionalRenderingInfoEXT(std::ostream &out, const VkCommandBufferInheritanceConditionalRenderingInfoEXT* structInfo, Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkConditionalRenderingBeginInfoEXT(std::ostream &out, const VkConditionalRenderingBeginInfoEXT* structInfo, Decoded_VkConditionalRenderingBeginInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceConditionalRenderingFeaturesEXT(std::ostream &out, const VkPhysicalDeviceConditionalRenderingFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineViewportWScalingStateCreateInfoNV(std::ostream &out, const VkPipelineViewportWScalingStateCreateInfoNV* structInfo, Decoded_VkPipelineViewportWScalingStateCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkViewportWScalingNV(std::ostream &out, const VkViewportWScalingNV* structInfo, Decoded_VkViewportWScalingNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfaceCapabilities2EXT(std::ostream &out, const VkSurfaceCapabilities2EXT* structInfo, Decoded_VkSurfaceCapabilities2EXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceEventInfoEXT(std::ostream &out, const VkDeviceEventInfoEXT* structInfo, Decoded_VkDeviceEventInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayEventInfoEXT(std::ostream &out, const VkDisplayEventInfoEXT* structInfo, Decoded_VkDisplayEventInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayPowerInfoEXT(std::ostream &out, const VkDisplayPowerInfoEXT* structInfo, Decoded_VkDisplayPowerInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSwapchainCounterCreateInfoEXT(std::ostream &out, const VkSwapchainCounterCreateInfoEXT* structInfo, Decoded_VkSwapchainCounterCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPastPresentationTimingGOOGLE(std::ostream &out, const VkPastPresentationTimingGOOGLE* structInfo, Decoded_VkPastPresentationTimingGOOGLE* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPresentTimeGOOGLE(std::ostream &out, const VkPresentTimeGOOGLE* structInfo, Decoded_VkPresentTimeGOOGLE* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPresentTimesInfoGOOGLE(std::ostream &out, const VkPresentTimesInfoGOOGLE* structInfo, Decoded_VkPresentTimesInfoGOOGLE* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRefreshCycleDurationGOOGLE(std::ostream &out, const VkRefreshCycleDurationGOOGLE* structInfo, Decoded_VkRefreshCycleDurationGOOGLE* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMultiviewPerViewAttributesInfoNVX(std::ostream &out, const VkMultiviewPerViewAttributesInfoNVX* structInfo, Decoded_VkMultiviewPerViewAttributesInfoNVX* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX(std::ostream &out, const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* structInfo, Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineViewportSwizzleStateCreateInfoNV(std::ostream &out, const VkPipelineViewportSwizzleStateCreateInfoNV* structInfo, Decoded_VkPipelineViewportSwizzleStateCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkViewportSwizzleNV(std::ostream &out, const VkViewportSwizzleNV* structInfo, Decoded_VkViewportSwizzleNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDiscardRectanglePropertiesEXT(std::ostream &out, const VkPhysicalDeviceDiscardRectanglePropertiesEXT* structInfo, Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineDiscardRectangleStateCreateInfoEXT(std::ostream &out, const VkPipelineDiscardRectangleStateCreateInfoEXT* structInfo, Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceConservativeRasterizationPropertiesEXT(std::ostream &out, const VkPhysicalDeviceConservativeRasterizationPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineRasterizationConservativeStateCreateInfoEXT(std::ostream &out, const VkPipelineRasterizationConservativeStateCreateInfoEXT* structInfo, Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDepthClipEnableFeaturesEXT(std::ostream &out, const VkPhysicalDeviceDepthClipEnableFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineRasterizationDepthClipStateCreateInfoEXT(std::ostream &out, const VkPipelineRasterizationDepthClipStateCreateInfoEXT* structInfo, Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkHdrMetadataEXT(std::ostream &out, const VkHdrMetadataEXT* structInfo, Decoded_VkHdrMetadataEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkXYColorEXT(std::ostream &out, const VkXYColorEXT* structInfo, Decoded_VkXYColorEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG(std::ostream &out, const VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG* structInfo, Decoded_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkIOSSurfaceCreateInfoMVK(std::ostream &out, const VkIOSSurfaceCreateInfoMVK* structInfo, Decoded_VkIOSSurfaceCreateInfoMVK* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMacOSSurfaceCreateInfoMVK(std::ostream &out, const VkMacOSSurfaceCreateInfoMVK* structInfo, Decoded_VkMacOSSurfaceCreateInfoMVK* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDebugUtilsLabelEXT(std::ostream &out, const VkDebugUtilsLabelEXT* structInfo, Decoded_VkDebugUtilsLabelEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDebugUtilsMessengerCallbackDataEXT(std::ostream &out, const VkDebugUtilsMessengerCallbackDataEXT* structInfo, Decoded_VkDebugUtilsMessengerCallbackDataEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDebugUtilsObjectNameInfoEXT(std::ostream &out, const VkDebugUtilsObjectNameInfoEXT* structInfo, Decoded_VkDebugUtilsObjectNameInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDebugUtilsObjectTagInfoEXT(std::ostream &out, const VkDebugUtilsObjectTagInfoEXT* structInfo, Decoded_VkDebugUtilsObjectTagInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAndroidHardwareBufferFormatProperties2ANDROID(std::ostream &out, const VkAndroidHardwareBufferFormatProperties2ANDROID* structInfo, Decoded_VkAndroidHardwareBufferFormatProperties2ANDROID* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAndroidHardwareBufferFormatPropertiesANDROID(std::ostream &out, const VkAndroidHardwareBufferFormatPropertiesANDROID* structInfo, Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAndroidHardwareBufferPropertiesANDROID(std::ostream &out, const VkAndroidHardwareBufferPropertiesANDROID* structInfo, Decoded_VkAndroidHardwareBufferPropertiesANDROID* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAndroidHardwareBufferUsageANDROID(std::ostream &out, const VkAndroidHardwareBufferUsageANDROID* structInfo, Decoded_VkAndroidHardwareBufferUsageANDROID* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExternalFormatANDROID(std::ostream &out, const VkExternalFormatANDROID* structInfo, Decoded_VkExternalFormatANDROID* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryGetAndroidHardwareBufferInfoANDROID(std::ostream &out, const VkMemoryGetAndroidHardwareBufferInfoANDROID* structInfo, Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAttachmentSampleCountInfoAMD(std::ostream &out, const VkAttachmentSampleCountInfoAMD* structInfo, Decoded_VkAttachmentSampleCountInfoAMD* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAttachmentSampleLocationsEXT(std::ostream &out, const VkAttachmentSampleLocationsEXT* structInfo, Decoded_VkAttachmentSampleLocationsEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMultisamplePropertiesEXT(std::ostream &out, const VkMultisamplePropertiesEXT* structInfo, Decoded_VkMultisamplePropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSampleLocationsPropertiesEXT(std::ostream &out, const VkPhysicalDeviceSampleLocationsPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineSampleLocationsStateCreateInfoEXT(std::ostream &out, const VkPipelineSampleLocationsStateCreateInfoEXT* structInfo, Decoded_VkPipelineSampleLocationsStateCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassSampleLocationsBeginInfoEXT(std::ostream &out, const VkRenderPassSampleLocationsBeginInfoEXT* structInfo, Decoded_VkRenderPassSampleLocationsBeginInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSampleLocationEXT(std::ostream &out, const VkSampleLocationEXT* structInfo, Decoded_VkSampleLocationEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSampleLocationsInfoEXT(std::ostream &out, const VkSampleLocationsInfoEXT* structInfo, Decoded_VkSampleLocationsInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubpassSampleLocationsEXT(std::ostream &out, const VkSubpassSampleLocationsEXT* structInfo, Decoded_VkSubpassSampleLocationsEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT(std::ostream &out, const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT(std::ostream &out, const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineColorBlendAdvancedStateCreateInfoEXT(std::ostream &out, const VkPipelineColorBlendAdvancedStateCreateInfoEXT* structInfo, Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineCoverageToColorStateCreateInfoNV(std::ostream &out, const VkPipelineCoverageToColorStateCreateInfoNV* structInfo, Decoded_VkPipelineCoverageToColorStateCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineCoverageModulationStateCreateInfoNV(std::ostream &out, const VkPipelineCoverageModulationStateCreateInfoNV* structInfo, Decoded_VkPipelineCoverageModulationStateCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV(std::ostream &out, const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* structInfo, Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV(std::ostream &out, const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* structInfo, Decoded_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDrmFormatModifierProperties2EXT(std::ostream &out, const VkDrmFormatModifierProperties2EXT* structInfo, Decoded_VkDrmFormatModifierProperties2EXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDrmFormatModifierPropertiesEXT(std::ostream &out, const VkDrmFormatModifierPropertiesEXT* structInfo, Decoded_VkDrmFormatModifierPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDrmFormatModifierPropertiesList2EXT(std::ostream &out, const VkDrmFormatModifierPropertiesList2EXT* structInfo, Decoded_VkDrmFormatModifierPropertiesList2EXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDrmFormatModifierPropertiesListEXT(std::ostream &out, const VkDrmFormatModifierPropertiesListEXT* structInfo, Decoded_VkDrmFormatModifierPropertiesListEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageDrmFormatModifierExplicitCreateInfoEXT(std::ostream &out, const VkImageDrmFormatModifierExplicitCreateInfoEXT* structInfo, Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageDrmFormatModifierListCreateInfoEXT(std::ostream &out, const VkImageDrmFormatModifierListCreateInfoEXT* structInfo, Decoded_VkImageDrmFormatModifierListCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageDrmFormatModifierPropertiesEXT(std::ostream &out, const VkImageDrmFormatModifierPropertiesEXT* structInfo, Decoded_VkImageDrmFormatModifierPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageDrmFormatModifierInfoEXT(std::ostream &out, const VkPhysicalDeviceImageDrmFormatModifierInfoEXT* structInfo, Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkShaderModuleValidationCacheCreateInfoEXT(std::ostream &out, const VkShaderModuleValidationCacheCreateInfoEXT* structInfo, Decoded_VkShaderModuleValidationCacheCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkValidationCacheCreateInfoEXT(std::ostream &out, const VkValidationCacheCreateInfoEXT* structInfo, Decoded_VkValidationCacheCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCoarseSampleLocationNV(std::ostream &out, const VkCoarseSampleLocationNV* structInfo, Decoded_VkCoarseSampleLocationNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCoarseSampleOrderCustomNV(std::ostream &out, const VkCoarseSampleOrderCustomNV* structInfo, Decoded_VkCoarseSampleOrderCustomNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShadingRateImageFeaturesNV(std::ostream &out, const VkPhysicalDeviceShadingRateImageFeaturesNV* structInfo, Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShadingRateImagePropertiesNV(std::ostream &out, const VkPhysicalDeviceShadingRateImagePropertiesNV* structInfo, Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV(std::ostream &out, const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* structInfo, Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineViewportShadingRateImageStateCreateInfoNV(std::ostream &out, const VkPipelineViewportShadingRateImageStateCreateInfoNV* structInfo, Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkShadingRatePaletteNV(std::ostream &out, const VkShadingRatePaletteNV* structInfo, Decoded_VkShadingRatePaletteNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAabbPositionsKHR(std::ostream &out, const VkAabbPositionsKHR* structInfo, Decoded_VkAabbPositionsKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureCreateInfoNV(std::ostream &out, const VkAccelerationStructureCreateInfoNV* structInfo, Decoded_VkAccelerationStructureCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureInfoNV(std::ostream &out, const VkAccelerationStructureInfoNV* structInfo, Decoded_VkAccelerationStructureInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureInstanceKHR(std::ostream &out, const VkAccelerationStructureInstanceKHR* structInfo, Decoded_VkAccelerationStructureInstanceKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureMemoryRequirementsInfoNV(std::ostream &out, const VkAccelerationStructureMemoryRequirementsInfoNV* structInfo, Decoded_VkAccelerationStructureMemoryRequirementsInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindAccelerationStructureMemoryInfoNV(std::ostream &out, const VkBindAccelerationStructureMemoryInfoNV* structInfo, Decoded_VkBindAccelerationStructureMemoryInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGeometryAABBNV(std::ostream &out, const VkGeometryAABBNV* structInfo, Decoded_VkGeometryAABBNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGeometryDataNV(std::ostream &out, const VkGeometryDataNV* structInfo, Decoded_VkGeometryDataNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGeometryNV(std::ostream &out, const VkGeometryNV* structInfo, Decoded_VkGeometryNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGeometryTrianglesNV(std::ostream &out, const VkGeometryTrianglesNV* structInfo, Decoded_VkGeometryTrianglesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRayTracingPropertiesNV(std::ostream &out, const VkPhysicalDeviceRayTracingPropertiesNV* structInfo, Decoded_VkPhysicalDeviceRayTracingPropertiesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRayTracingPipelineCreateInfoNV(std::ostream &out, const VkRayTracingPipelineCreateInfoNV* structInfo, Decoded_VkRayTracingPipelineCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRayTracingShaderGroupCreateInfoNV(std::ostream &out, const VkRayTracingShaderGroupCreateInfoNV* structInfo, Decoded_VkRayTracingShaderGroupCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkTransformMatrixKHR(std::ostream &out, const VkTransformMatrixKHR* structInfo, Decoded_VkTransformMatrixKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkWriteDescriptorSetAccelerationStructureNV(std::ostream &out, const VkWriteDescriptorSetAccelerationStructureNV* structInfo, Decoded_VkWriteDescriptorSetAccelerationStructureNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV(std::ostream &out, const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* structInfo, Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineRepresentativeFragmentTestStateCreateInfoNV(std::ostream &out, const VkPipelineRepresentativeFragmentTestStateCreateInfoNV* structInfo, Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFilterCubicImageViewImageFormatPropertiesEXT(std::ostream &out, const VkFilterCubicImageViewImageFormatPropertiesEXT* structInfo, Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageViewImageFormatInfoEXT(std::ostream &out, const VkPhysicalDeviceImageViewImageFormatInfoEXT* structInfo, Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryHostPointerPropertiesEXT(std::ostream &out, const VkMemoryHostPointerPropertiesEXT* structInfo, Decoded_VkMemoryHostPointerPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExternalMemoryHostPropertiesEXT(std::ostream &out, const VkPhysicalDeviceExternalMemoryHostPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineCompilerControlCreateInfoAMD(std::ostream &out, const VkPipelineCompilerControlCreateInfoAMD* structInfo, Decoded_VkPipelineCompilerControlCreateInfoAMD* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderCorePropertiesAMD(std::ostream &out, const VkPhysicalDeviceShaderCorePropertiesAMD* structInfo, Decoded_VkPhysicalDeviceShaderCorePropertiesAMD* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceMemoryOverallocationCreateInfoAMD(std::ostream &out, const VkDeviceMemoryOverallocationCreateInfoAMD* structInfo, Decoded_VkDeviceMemoryOverallocationCreateInfoAMD* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT(std::ostream &out, const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPresentFrameTokenGGP(std::ostream &out, const VkPresentFrameTokenGGP* structInfo, Decoded_VkPresentFrameTokenGGP* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDrawMeshTasksIndirectCommandNV(std::ostream &out, const VkDrawMeshTasksIndirectCommandNV* structInfo, Decoded_VkDrawMeshTasksIndirectCommandNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMeshShaderFeaturesNV(std::ostream &out, const VkPhysicalDeviceMeshShaderFeaturesNV* structInfo, Decoded_VkPhysicalDeviceMeshShaderFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMeshShaderPropertiesNV(std::ostream &out, const VkPhysicalDeviceMeshShaderPropertiesNV* structInfo, Decoded_VkPhysicalDeviceMeshShaderPropertiesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderImageFootprintFeaturesNV(std::ostream &out, const VkPhysicalDeviceShaderImageFootprintFeaturesNV* structInfo, Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExclusiveScissorFeaturesNV(std::ostream &out, const VkPhysicalDeviceExclusiveScissorFeaturesNV* structInfo, Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineViewportExclusiveScissorStateCreateInfoNV(std::ostream &out, const VkPipelineViewportExclusiveScissorStateCreateInfoNV* structInfo, Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCheckpointData2NV(std::ostream &out, const VkCheckpointData2NV* structInfo, Decoded_VkCheckpointData2NV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCheckpointDataNV(std::ostream &out, const VkCheckpointDataNV* structInfo, Decoded_VkCheckpointDataNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueueFamilyCheckpointProperties2NV(std::ostream &out, const VkQueueFamilyCheckpointProperties2NV* structInfo, Decoded_VkQueueFamilyCheckpointProperties2NV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueueFamilyCheckpointPropertiesNV(std::ostream &out, const VkQueueFamilyCheckpointPropertiesNV* structInfo, Decoded_VkQueueFamilyCheckpointPropertiesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL(std::ostream &out, const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* structInfo, Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkInitializePerformanceApiInfoINTEL(std::ostream &out, const VkInitializePerformanceApiInfoINTEL* structInfo, Decoded_VkInitializePerformanceApiInfoINTEL* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPerformanceConfigurationAcquireInfoINTEL(std::ostream &out, const VkPerformanceConfigurationAcquireInfoINTEL* structInfo, Decoded_VkPerformanceConfigurationAcquireInfoINTEL* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPerformanceMarkerInfoINTEL(std::ostream &out, const VkPerformanceMarkerInfoINTEL* structInfo, Decoded_VkPerformanceMarkerInfoINTEL* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPerformanceOverrideInfoINTEL(std::ostream &out, const VkPerformanceOverrideInfoINTEL* structInfo, Decoded_VkPerformanceOverrideInfoINTEL* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPerformanceStreamMarkerInfoINTEL(std::ostream &out, const VkPerformanceStreamMarkerInfoINTEL* structInfo, Decoded_VkPerformanceStreamMarkerInfoINTEL* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueryPoolPerformanceQueryCreateInfoINTEL(std::ostream &out, const VkQueryPoolPerformanceQueryCreateInfoINTEL* structInfo, Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePCIBusInfoPropertiesEXT(std::ostream &out, const VkPhysicalDevicePCIBusInfoPropertiesEXT* structInfo, Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayNativeHdrSurfaceCapabilitiesAMD(std::ostream &out, const VkDisplayNativeHdrSurfaceCapabilitiesAMD* structInfo, Decoded_VkDisplayNativeHdrSurfaceCapabilitiesAMD* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSwapchainDisplayNativeHdrCreateInfoAMD(std::ostream &out, const VkSwapchainDisplayNativeHdrCreateInfoAMD* structInfo, Decoded_VkSwapchainDisplayNativeHdrCreateInfoAMD* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImagePipeSurfaceCreateInfoFUCHSIA(std::ostream &out, const VkImagePipeSurfaceCreateInfoFUCHSIA* structInfo, Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMetalSurfaceCreateInfoEXT(std::ostream &out, const VkMetalSurfaceCreateInfoEXT* structInfo, Decoded_VkMetalSurfaceCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentDensityMapFeaturesEXT(std::ostream &out, const VkPhysicalDeviceFragmentDensityMapFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentDensityMapPropertiesEXT(std::ostream &out, const VkPhysicalDeviceFragmentDensityMapPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassFragmentDensityMapCreateInfoEXT(std::ostream &out, const VkRenderPassFragmentDensityMapCreateInfoEXT* structInfo, Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderingFragmentDensityMapAttachmentInfoEXT(std::ostream &out, const VkRenderingFragmentDensityMapAttachmentInfoEXT* structInfo, Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderCoreProperties2AMD(std::ostream &out, const VkPhysicalDeviceShaderCoreProperties2AMD* structInfo, Decoded_VkPhysicalDeviceShaderCoreProperties2AMD* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCoherentMemoryFeaturesAMD(std::ostream &out, const VkPhysicalDeviceCoherentMemoryFeaturesAMD* structInfo, Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT(std::ostream &out, const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* structInfo, Decoded_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMemoryBudgetPropertiesEXT(std::ostream &out, const VkPhysicalDeviceMemoryBudgetPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryPriorityAllocateInfoEXT(std::ostream &out, const VkMemoryPriorityAllocateInfoEXT* structInfo, Decoded_VkMemoryPriorityAllocateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMemoryPriorityFeaturesEXT(std::ostream &out, const VkPhysicalDeviceMemoryPriorityFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV(std::ostream &out, const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* structInfo, Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferDeviceAddressCreateInfoEXT(std::ostream &out, const VkBufferDeviceAddressCreateInfoEXT* structInfo, Decoded_VkBufferDeviceAddressCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT(std::ostream &out, const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkValidationFeaturesEXT(std::ostream &out, const VkValidationFeaturesEXT* structInfo, Decoded_VkValidationFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCooperativeMatrixPropertiesNV(std::ostream &out, const VkCooperativeMatrixPropertiesNV* structInfo, Decoded_VkCooperativeMatrixPropertiesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCooperativeMatrixFeaturesNV(std::ostream &out, const VkPhysicalDeviceCooperativeMatrixFeaturesNV* structInfo, Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCooperativeMatrixPropertiesNV(std::ostream &out, const VkPhysicalDeviceCooperativeMatrixPropertiesNV* structInfo, Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFramebufferMixedSamplesCombinationNV(std::ostream &out, const VkFramebufferMixedSamplesCombinationNV* structInfo, Decoded_VkFramebufferMixedSamplesCombinationNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCoverageReductionModeFeaturesNV(std::ostream &out, const VkPhysicalDeviceCoverageReductionModeFeaturesNV* structInfo, Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineCoverageReductionStateCreateInfoNV(std::ostream &out, const VkPipelineCoverageReductionStateCreateInfoNV* structInfo, Decoded_VkPipelineCoverageReductionStateCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT(std::ostream &out, const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT(std::ostream &out, const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceProvokingVertexFeaturesEXT(std::ostream &out, const VkPhysicalDeviceProvokingVertexFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceProvokingVertexFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceProvokingVertexPropertiesEXT(std::ostream &out, const VkPhysicalDeviceProvokingVertexPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceProvokingVertexPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT(std::ostream &out, const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT* structInfo, Decoded_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfaceCapabilitiesFullScreenExclusiveEXT(std::ostream &out, const VkSurfaceCapabilitiesFullScreenExclusiveEXT* structInfo, Decoded_VkSurfaceCapabilitiesFullScreenExclusiveEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfaceFullScreenExclusiveInfoEXT(std::ostream &out, const VkSurfaceFullScreenExclusiveInfoEXT* structInfo, Decoded_VkSurfaceFullScreenExclusiveInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfaceFullScreenExclusiveWin32InfoEXT(std::ostream &out, const VkSurfaceFullScreenExclusiveWin32InfoEXT* structInfo, Decoded_VkSurfaceFullScreenExclusiveWin32InfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkHeadlessSurfaceCreateInfoEXT(std::ostream &out, const VkHeadlessSurfaceCreateInfoEXT* structInfo, Decoded_VkHeadlessSurfaceCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT(std::ostream &out, const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT(std::ostream &out, const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryMapPlacedInfoEXT(std::ostream &out, const VkMemoryMapPlacedInfoEXT* structInfo, Decoded_VkMemoryMapPlacedInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT(std::ostream &out, const VkPhysicalDeviceMapMemoryPlacedFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMapMemoryPlacedPropertiesEXT(std::ostream &out, const VkPhysicalDeviceMapMemoryPlacedPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceMapMemoryPlacedPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT(std::ostream &out, const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* structInfo, Decoded_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfacePresentModeCompatibilityEXT(std::ostream &out, const VkSurfacePresentModeCompatibilityEXT* structInfo, Decoded_VkSurfacePresentModeCompatibilityEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfacePresentModeEXT(std::ostream &out, const VkSurfacePresentModeEXT* structInfo, Decoded_VkSurfacePresentModeEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfacePresentScalingCapabilitiesEXT(std::ostream &out, const VkSurfacePresentScalingCapabilitiesEXT* structInfo, Decoded_VkSurfacePresentScalingCapabilitiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT(std::ostream &out, const VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT* structInfo, Decoded_VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkReleaseSwapchainImagesInfoEXT(std::ostream &out, const VkReleaseSwapchainImagesInfoEXT* structInfo, Decoded_VkReleaseSwapchainImagesInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSwapchainPresentFenceInfoEXT(std::ostream &out, const VkSwapchainPresentFenceInfoEXT* structInfo, Decoded_VkSwapchainPresentFenceInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSwapchainPresentModeInfoEXT(std::ostream &out, const VkSwapchainPresentModeInfoEXT* structInfo, Decoded_VkSwapchainPresentModeInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSwapchainPresentModesCreateInfoEXT(std::ostream &out, const VkSwapchainPresentModesCreateInfoEXT* structInfo, Decoded_VkSwapchainPresentModesCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSwapchainPresentScalingCreateInfoEXT(std::ostream &out, const VkSwapchainPresentScalingCreateInfoEXT* structInfo, Decoded_VkSwapchainPresentScalingCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindIndexBufferIndirectCommandNV(std::ostream &out, const VkBindIndexBufferIndirectCommandNV* structInfo, Decoded_VkBindIndexBufferIndirectCommandNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindShaderGroupIndirectCommandNV(std::ostream &out, const VkBindShaderGroupIndirectCommandNV* structInfo, Decoded_VkBindShaderGroupIndirectCommandNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindVertexBufferIndirectCommandNV(std::ostream &out, const VkBindVertexBufferIndirectCommandNV* structInfo, Decoded_VkBindVertexBufferIndirectCommandNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGeneratedCommandsInfoNV(std::ostream &out, const VkGeneratedCommandsInfoNV* structInfo, Decoded_VkGeneratedCommandsInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGeneratedCommandsMemoryRequirementsInfoNV(std::ostream &out, const VkGeneratedCommandsMemoryRequirementsInfoNV* structInfo, Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGraphicsPipelineShaderGroupsCreateInfoNV(std::ostream &out, const VkGraphicsPipelineShaderGroupsCreateInfoNV* structInfo, Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGraphicsShaderGroupCreateInfoNV(std::ostream &out, const VkGraphicsShaderGroupCreateInfoNV* structInfo, Decoded_VkGraphicsShaderGroupCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkIndirectCommandsLayoutCreateInfoNV(std::ostream &out, const VkIndirectCommandsLayoutCreateInfoNV* structInfo, Decoded_VkIndirectCommandsLayoutCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkIndirectCommandsLayoutTokenNV(std::ostream &out, const VkIndirectCommandsLayoutTokenNV* structInfo, Decoded_VkIndirectCommandsLayoutTokenNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkIndirectCommandsStreamNV(std::ostream &out, const VkIndirectCommandsStreamNV* structInfo, Decoded_VkIndirectCommandsStreamNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV(std::ostream &out, const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* structInfo, Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV(std::ostream &out, const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* structInfo, Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSetStateFlagsIndirectCommandNV(std::ostream &out, const VkSetStateFlagsIndirectCommandNV* structInfo, Decoded_VkSetStateFlagsIndirectCommandNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCommandBufferInheritanceViewportScissorInfoNV(std::ostream &out, const VkCommandBufferInheritanceViewportScissorInfoNV* structInfo, Decoded_VkCommandBufferInheritanceViewportScissorInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceInheritedViewportScissorFeaturesNV(std::ostream &out, const VkPhysicalDeviceInheritedViewportScissorFeaturesNV* structInfo, Decoded_VkPhysicalDeviceInheritedViewportScissorFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT(std::ostream &out, const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCommandBufferInheritanceRenderPassTransformInfoQCOM(std::ostream &out, const VkCommandBufferInheritanceRenderPassTransformInfoQCOM* structInfo, Decoded_VkCommandBufferInheritanceRenderPassTransformInfoQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassTransformBeginInfoQCOM(std::ostream &out, const VkRenderPassTransformBeginInfoQCOM* structInfo, Decoded_VkRenderPassTransformBeginInfoQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDepthBiasInfoEXT(std::ostream &out, const VkDepthBiasInfoEXT* structInfo, Decoded_VkDepthBiasInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDepthBiasRepresentationInfoEXT(std::ostream &out, const VkDepthBiasRepresentationInfoEXT* structInfo, Decoded_VkDepthBiasRepresentationInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDepthBiasControlFeaturesEXT(std::ostream &out, const VkPhysicalDeviceDepthBiasControlFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceDepthBiasControlFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceDeviceMemoryReportCreateInfoEXT(std::ostream &out, const VkDeviceDeviceMemoryReportCreateInfoEXT* structInfo, Decoded_VkDeviceDeviceMemoryReportCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceMemoryReportCallbackDataEXT(std::ostream &out, const VkDeviceMemoryReportCallbackDataEXT* structInfo, Decoded_VkDeviceMemoryReportCallbackDataEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT(std::ostream &out, const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRobustness2FeaturesEXT(std::ostream &out, const VkPhysicalDeviceRobustness2FeaturesEXT* structInfo, Decoded_VkPhysicalDeviceRobustness2FeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRobustness2PropertiesEXT(std::ostream &out, const VkPhysicalDeviceRobustness2PropertiesEXT* structInfo, Decoded_VkPhysicalDeviceRobustness2PropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCustomBorderColorFeaturesEXT(std::ostream &out, const VkPhysicalDeviceCustomBorderColorFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCustomBorderColorPropertiesEXT(std::ostream &out, const VkPhysicalDeviceCustomBorderColorPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceCustomBorderColorPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSamplerCustomBorderColorCreateInfoEXT(std::ostream &out, const VkSamplerCustomBorderColorCreateInfoEXT* structInfo, Decoded_VkSamplerCustomBorderColorCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePresentBarrierFeaturesNV(std::ostream &out, const VkPhysicalDevicePresentBarrierFeaturesNV* structInfo, Decoded_VkPhysicalDevicePresentBarrierFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfaceCapabilitiesPresentBarrierNV(std::ostream &out, const VkSurfaceCapabilitiesPresentBarrierNV* structInfo, Decoded_VkSurfaceCapabilitiesPresentBarrierNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSwapchainPresentBarrierCreateInfoNV(std::ostream &out, const VkSwapchainPresentBarrierCreateInfoNV* structInfo, Decoded_VkSwapchainPresentBarrierCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceDiagnosticsConfigCreateInfoNV(std::ostream &out, const VkDeviceDiagnosticsConfigCreateInfoNV* structInfo, Decoded_VkDeviceDiagnosticsConfigCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDiagnosticsConfigFeaturesNV(std::ostream &out, const VkPhysicalDeviceDiagnosticsConfigFeaturesNV* structInfo, Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueryLowLatencySupportNV(std::ostream &out, const VkQueryLowLatencySupportNV* structInfo, Decoded_VkQueryLowLatencySupportNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGraphicsPipelineLibraryCreateInfoEXT(std::ostream &out, const VkGraphicsPipelineLibraryCreateInfoEXT* structInfo, Decoded_VkGraphicsPipelineLibraryCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT(std::ostream &out, const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT(std::ostream &out, const VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD(std::ostream &out, const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* structInfo, Decoded_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV(std::ostream &out, const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* structInfo, Decoded_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV(std::ostream &out, const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV* structInfo, Decoded_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineFragmentShadingRateEnumStateCreateInfoNV(std::ostream &out, const VkPipelineFragmentShadingRateEnumStateCreateInfoNV* structInfo, Decoded_VkPipelineFragmentShadingRateEnumStateCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureGeometryMotionTrianglesDataNV(std::ostream &out, const VkAccelerationStructureGeometryMotionTrianglesDataNV* structInfo, Decoded_VkAccelerationStructureGeometryMotionTrianglesDataNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureMatrixMotionInstanceNV(std::ostream &out, const VkAccelerationStructureMatrixMotionInstanceNV* structInfo, Decoded_VkAccelerationStructureMatrixMotionInstanceNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureMotionInfoNV(std::ostream &out, const VkAccelerationStructureMotionInfoNV* structInfo, Decoded_VkAccelerationStructureMotionInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureSRTMotionInstanceNV(std::ostream &out, const VkAccelerationStructureSRTMotionInstanceNV* structInfo, Decoded_VkAccelerationStructureSRTMotionInstanceNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV(std::ostream &out, const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* structInfo, Decoded_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSRTDataNV(std::ostream &out, const VkSRTDataNV* structInfo, Decoded_VkSRTDataNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT(std::ostream &out, const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT(std::ostream &out, const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* structInfo, Decoded_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT(std::ostream &out, const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT* structInfo, Decoded_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyCommandTransformInfoQCOM(std::ostream &out, const VkCopyCommandTransformInfoQCOM* structInfo, Decoded_VkCopyCommandTransformInfoQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageCompressionControlEXT(std::ostream &out, const VkImageCompressionControlEXT* structInfo, Decoded_VkImageCompressionControlEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageCompressionPropertiesEXT(std::ostream &out, const VkImageCompressionPropertiesEXT* structInfo, Decoded_VkImageCompressionPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageCompressionControlFeaturesEXT(std::ostream &out, const VkPhysicalDeviceImageCompressionControlFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceImageCompressionControlFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT(std::ostream &out, const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevice4444FormatsFeaturesEXT(std::ostream &out, const VkPhysicalDevice4444FormatsFeaturesEXT* structInfo, Decoded_VkPhysicalDevice4444FormatsFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceFaultAddressInfoEXT(std::ostream &out, const VkDeviceFaultAddressInfoEXT* structInfo, Decoded_VkDeviceFaultAddressInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceFaultCountsEXT(std::ostream &out, const VkDeviceFaultCountsEXT* structInfo, Decoded_VkDeviceFaultCountsEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceFaultInfoEXT(std::ostream &out, const VkDeviceFaultInfoEXT* structInfo, Decoded_VkDeviceFaultInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceFaultVendorBinaryHeaderVersionOneEXT(std::ostream &out, const VkDeviceFaultVendorBinaryHeaderVersionOneEXT* structInfo, Decoded_VkDeviceFaultVendorBinaryHeaderVersionOneEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceFaultVendorInfoEXT(std::ostream &out, const VkDeviceFaultVendorInfoEXT* structInfo, Decoded_VkDeviceFaultVendorInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFaultFeaturesEXT(std::ostream &out, const VkPhysicalDeviceFaultFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceFaultFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT(std::ostream &out, const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT(std::ostream &out, const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDirectFBSurfaceCreateInfoEXT(std::ostream &out, const VkDirectFBSurfaceCreateInfoEXT* structInfo, Decoded_VkDirectFBSurfaceCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMutableDescriptorTypeCreateInfoEXT(std::ostream &out, const VkMutableDescriptorTypeCreateInfoEXT* structInfo, Decoded_VkMutableDescriptorTypeCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMutableDescriptorTypeListEXT(std::ostream &out, const VkMutableDescriptorTypeListEXT* structInfo, Decoded_VkMutableDescriptorTypeListEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT(std::ostream &out, const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT(std::ostream &out, const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVertexInputAttributeDescription2EXT(std::ostream &out, const VkVertexInputAttributeDescription2EXT* structInfo, Decoded_VkVertexInputAttributeDescription2EXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVertexInputBindingDescription2EXT(std::ostream &out, const VkVertexInputBindingDescription2EXT* structInfo, Decoded_VkVertexInputBindingDescription2EXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDrmPropertiesEXT(std::ostream &out, const VkPhysicalDeviceDrmPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceDrmPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceAddressBindingCallbackDataEXT(std::ostream &out, const VkDeviceAddressBindingCallbackDataEXT* structInfo, Decoded_VkDeviceAddressBindingCallbackDataEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceAddressBindingReportFeaturesEXT(std::ostream &out, const VkPhysicalDeviceAddressBindingReportFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceAddressBindingReportFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDepthClipControlFeaturesEXT(std::ostream &out, const VkPhysicalDeviceDepthClipControlFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceDepthClipControlFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineViewportDepthClipControlCreateInfoEXT(std::ostream &out, const VkPipelineViewportDepthClipControlCreateInfoEXT* structInfo, Decoded_VkPipelineViewportDepthClipControlCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT(std::ostream &out, const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* structInfo, Decoded_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesEXT(std::ostream &out, const VkPhysicalDevicePresentModeFifoLatestReadyFeaturesEXT* structInfo, Decoded_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImportMemoryZirconHandleInfoFUCHSIA(std::ostream &out, const VkImportMemoryZirconHandleInfoFUCHSIA* structInfo, Decoded_VkImportMemoryZirconHandleInfoFUCHSIA* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryGetZirconHandleInfoFUCHSIA(std::ostream &out, const VkMemoryGetZirconHandleInfoFUCHSIA* structInfo, Decoded_VkMemoryGetZirconHandleInfoFUCHSIA* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryZirconHandlePropertiesFUCHSIA(std::ostream &out, const VkMemoryZirconHandlePropertiesFUCHSIA* structInfo, Decoded_VkMemoryZirconHandlePropertiesFUCHSIA* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImportSemaphoreZirconHandleInfoFUCHSIA(std::ostream &out, const VkImportSemaphoreZirconHandleInfoFUCHSIA* structInfo, Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSemaphoreGetZirconHandleInfoFUCHSIA(std::ostream &out, const VkSemaphoreGetZirconHandleInfoFUCHSIA* structInfo, Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI(std::ostream &out, const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* structInfo, Decoded_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryGetRemoteAddressInfoNV(std::ostream &out, const VkMemoryGetRemoteAddressInfoNV* structInfo, Decoded_VkMemoryGetRemoteAddressInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV(std::ostream &out, const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* structInfo, Decoded_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFrameBoundaryEXT(std::ostream &out, const VkFrameBoundaryEXT* structInfo, Decoded_VkFrameBoundaryEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFrameBoundaryFeaturesEXT(std::ostream &out, const VkPhysicalDeviceFrameBoundaryFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceFrameBoundaryFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMultisampledRenderToSingleSampledInfoEXT(std::ostream &out, const VkMultisampledRenderToSingleSampledInfoEXT* structInfo, Decoded_VkMultisampledRenderToSingleSampledInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT(std::ostream &out, const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubpassResolvePerformanceQueryEXT(std::ostream &out, const VkSubpassResolvePerformanceQueryEXT* structInfo, Decoded_VkSubpassResolvePerformanceQueryEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT(std::ostream &out, const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* structInfo, Decoded_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkScreenSurfaceCreateInfoQNX(std::ostream &out, const VkScreenSurfaceCreateInfoQNX* structInfo, Decoded_VkScreenSurfaceCreateInfoQNX* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceColorWriteEnableFeaturesEXT(std::ostream &out, const VkPhysicalDeviceColorWriteEnableFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceColorWriteEnableFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineColorWriteCreateInfoEXT(std::ostream &out, const VkPipelineColorWriteCreateInfoEXT* structInfo, Decoded_VkPipelineColorWriteCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT(std::ostream &out, const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* structInfo, Decoded_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageViewMinLodCreateInfoEXT(std::ostream &out, const VkImageViewMinLodCreateInfoEXT* structInfo, Decoded_VkImageViewMinLodCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageViewMinLodFeaturesEXT(std::ostream &out, const VkPhysicalDeviceImageViewMinLodFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceImageViewMinLodFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMultiDrawIndexedInfoEXT(std::ostream &out, const VkMultiDrawIndexedInfoEXT* structInfo, Decoded_VkMultiDrawIndexedInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMultiDrawInfoEXT(std::ostream &out, const VkMultiDrawInfoEXT* structInfo, Decoded_VkMultiDrawInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMultiDrawFeaturesEXT(std::ostream &out, const VkPhysicalDeviceMultiDrawFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceMultiDrawFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMultiDrawPropertiesEXT(std::ostream &out, const VkPhysicalDeviceMultiDrawPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceMultiDrawPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT(std::ostream &out, const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderTileImageFeaturesEXT(std::ostream &out, const VkPhysicalDeviceShaderTileImageFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceShaderTileImageFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderTileImagePropertiesEXT(std::ostream &out, const VkPhysicalDeviceShaderTileImagePropertiesEXT* structInfo, Decoded_VkPhysicalDeviceShaderTileImagePropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureTrianglesOpacityMicromapEXT(std::ostream &out, const VkAccelerationStructureTrianglesOpacityMicromapEXT* structInfo, Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyMemoryToMicromapInfoEXT(std::ostream &out, const VkCopyMemoryToMicromapInfoEXT* structInfo, Decoded_VkCopyMemoryToMicromapInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyMicromapInfoEXT(std::ostream &out, const VkCopyMicromapInfoEXT* structInfo, Decoded_VkCopyMicromapInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyMicromapToMemoryInfoEXT(std::ostream &out, const VkCopyMicromapToMemoryInfoEXT* structInfo, Decoded_VkCopyMicromapToMemoryInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMicromapBuildInfoEXT(std::ostream &out, const VkMicromapBuildInfoEXT* structInfo, Decoded_VkMicromapBuildInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMicromapBuildSizesInfoEXT(std::ostream &out, const VkMicromapBuildSizesInfoEXT* structInfo, Decoded_VkMicromapBuildSizesInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMicromapCreateInfoEXT(std::ostream &out, const VkMicromapCreateInfoEXT* structInfo, Decoded_VkMicromapCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMicromapTriangleEXT(std::ostream &out, const VkMicromapTriangleEXT* structInfo, Decoded_VkMicromapTriangleEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMicromapUsageEXT(std::ostream &out, const VkMicromapUsageEXT* structInfo, Decoded_VkMicromapUsageEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMicromapVersionInfoEXT(std::ostream &out, const VkMicromapVersionInfoEXT* structInfo, Decoded_VkMicromapVersionInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceOpacityMicromapFeaturesEXT(std::ostream &out, const VkPhysicalDeviceOpacityMicromapFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceOpacityMicromapFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceOpacityMicromapPropertiesEXT(std::ostream &out, const VkPhysicalDeviceOpacityMicromapPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceOpacityMicromapPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureTrianglesDisplacementMicromapNV(std::ostream &out, const VkAccelerationStructureTrianglesDisplacementMicromapNV* structInfo, Decoded_VkAccelerationStructureTrianglesDisplacementMicromapNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDisplacementMicromapFeaturesNV(std::ostream &out, const VkPhysicalDeviceDisplacementMicromapFeaturesNV* structInfo, Decoded_VkPhysicalDeviceDisplacementMicromapFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDisplacementMicromapPropertiesNV(std::ostream &out, const VkPhysicalDeviceDisplacementMicromapPropertiesNV* structInfo, Decoded_VkPhysicalDeviceDisplacementMicromapPropertiesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI(std::ostream &out, const VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI* structInfo, Decoded_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI(std::ostream &out, const VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI* structInfo, Decoded_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI(std::ostream &out, const VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI* structInfo, Decoded_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT(std::ostream &out, const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSamplerBorderColorComponentMappingCreateInfoEXT(std::ostream &out, const VkSamplerBorderColorComponentMappingCreateInfoEXT* structInfo, Decoded_VkSamplerBorderColorComponentMappingCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT(std::ostream &out, const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* structInfo, Decoded_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderCorePropertiesARM(std::ostream &out, const VkPhysicalDeviceShaderCorePropertiesARM* structInfo, Decoded_VkPhysicalDeviceShaderCorePropertiesARM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceQueueShaderCoreControlCreateInfoARM(std::ostream &out, const VkDeviceQueueShaderCoreControlCreateInfoARM* structInfo, Decoded_VkDeviceQueueShaderCoreControlCreateInfoARM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSchedulingControlsFeaturesARM(std::ostream &out, const VkPhysicalDeviceSchedulingControlsFeaturesARM* structInfo, Decoded_VkPhysicalDeviceSchedulingControlsFeaturesARM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSchedulingControlsPropertiesARM(std::ostream &out, const VkPhysicalDeviceSchedulingControlsPropertiesARM* structInfo, Decoded_VkPhysicalDeviceSchedulingControlsPropertiesARM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageViewSlicedCreateInfoEXT(std::ostream &out, const VkImageViewSlicedCreateInfoEXT* structInfo, Decoded_VkImageViewSlicedCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT(std::ostream &out, const VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorSetBindingReferenceVALVE(std::ostream &out, const VkDescriptorSetBindingReferenceVALVE* structInfo, Decoded_VkDescriptorSetBindingReferenceVALVE* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorSetLayoutHostMappingInfoVALVE(std::ostream &out, const VkDescriptorSetLayoutHostMappingInfoVALVE* structInfo, Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE(std::ostream &out, const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* structInfo, Decoded_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT(std::ostream &out, const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRenderPassStripedFeaturesARM(std::ostream &out, const VkPhysicalDeviceRenderPassStripedFeaturesARM* structInfo, Decoded_VkPhysicalDeviceRenderPassStripedFeaturesARM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRenderPassStripedPropertiesARM(std::ostream &out, const VkPhysicalDeviceRenderPassStripedPropertiesARM* structInfo, Decoded_VkPhysicalDeviceRenderPassStripedPropertiesARM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassStripeBeginInfoARM(std::ostream &out, const VkRenderPassStripeBeginInfoARM* structInfo, Decoded_VkRenderPassStripeBeginInfoARM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassStripeInfoARM(std::ostream &out, const VkRenderPassStripeInfoARM* structInfo, Decoded_VkRenderPassStripeInfoARM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassStripeSubmitInfoARM(std::ostream &out, const VkRenderPassStripeSubmitInfoARM* structInfo, Decoded_VkRenderPassStripeSubmitInfoARM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM(std::ostream &out, const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM* structInfo, Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM(std::ostream &out, const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM* structInfo, Decoded_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubpassFragmentDensityMapOffsetEndInfoQCOM(std::ostream &out, const VkSubpassFragmentDensityMapOffsetEndInfoQCOM* structInfo, Decoded_VkSubpassFragmentDensityMapOffsetEndInfoQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindPipelineIndirectCommandNV(std::ostream &out, const VkBindPipelineIndirectCommandNV* structInfo, Decoded_VkBindPipelineIndirectCommandNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkComputePipelineIndirectBufferInfoNV(std::ostream &out, const VkComputePipelineIndirectBufferInfoNV* structInfo, Decoded_VkComputePipelineIndirectBufferInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV(std::ostream &out, const VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV* structInfo, Decoded_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineIndirectDeviceAddressInfoNV(std::ostream &out, const VkPipelineIndirectDeviceAddressInfoNV* structInfo, Decoded_VkPipelineIndirectDeviceAddressInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureGeometryLinearSweptSpheresDataNV(std::ostream &out, const VkAccelerationStructureGeometryLinearSweptSpheresDataNV* structInfo, Decoded_VkAccelerationStructureGeometryLinearSweptSpheresDataNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureGeometrySpheresDataNV(std::ostream &out, const VkAccelerationStructureGeometrySpheresDataNV* structInfo, Decoded_VkAccelerationStructureGeometrySpheresDataNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV(std::ostream &out, const VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV* structInfo, Decoded_VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceLinearColorAttachmentFeaturesNV(std::ostream &out, const VkPhysicalDeviceLinearColorAttachmentFeaturesNV* structInfo, Decoded_VkPhysicalDeviceLinearColorAttachmentFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT(std::ostream &out, const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageViewSampleWeightCreateInfoQCOM(std::ostream &out, const VkImageViewSampleWeightCreateInfoQCOM* structInfo, Decoded_VkImageViewSampleWeightCreateInfoQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageProcessingFeaturesQCOM(std::ostream &out, const VkPhysicalDeviceImageProcessingFeaturesQCOM* structInfo, Decoded_VkPhysicalDeviceImageProcessingFeaturesQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageProcessingPropertiesQCOM(std::ostream &out, const VkPhysicalDeviceImageProcessingPropertiesQCOM* structInfo, Decoded_VkPhysicalDeviceImageProcessingPropertiesQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceNestedCommandBufferFeaturesEXT(std::ostream &out, const VkPhysicalDeviceNestedCommandBufferFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceNestedCommandBufferFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceNestedCommandBufferPropertiesEXT(std::ostream &out, const VkPhysicalDeviceNestedCommandBufferPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceNestedCommandBufferPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExternalMemoryAcquireUnmodifiedEXT(std::ostream &out, const VkExternalMemoryAcquireUnmodifiedEXT* structInfo, Decoded_VkExternalMemoryAcquireUnmodifiedEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkColorBlendAdvancedEXT(std::ostream &out, const VkColorBlendAdvancedEXT* structInfo, Decoded_VkColorBlendAdvancedEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkColorBlendEquationEXT(std::ostream &out, const VkColorBlendEquationEXT* structInfo, Decoded_VkColorBlendEquationEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT(std::ostream &out, const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* structInfo, Decoded_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT(std::ostream &out, const VkPhysicalDeviceExtendedDynamicState3PropertiesEXT* structInfo, Decoded_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT(std::ostream &out, const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassCreationControlEXT(std::ostream &out, const VkRenderPassCreationControlEXT* structInfo, Decoded_VkRenderPassCreationControlEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassCreationFeedbackCreateInfoEXT(std::ostream &out, const VkRenderPassCreationFeedbackCreateInfoEXT* structInfo, Decoded_VkRenderPassCreationFeedbackCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassCreationFeedbackInfoEXT(std::ostream &out, const VkRenderPassCreationFeedbackInfoEXT* structInfo, Decoded_VkRenderPassCreationFeedbackInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassSubpassFeedbackCreateInfoEXT(std::ostream &out, const VkRenderPassSubpassFeedbackCreateInfoEXT* structInfo, Decoded_VkRenderPassSubpassFeedbackCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassSubpassFeedbackInfoEXT(std::ostream &out, const VkRenderPassSubpassFeedbackInfoEXT* structInfo, Decoded_VkRenderPassSubpassFeedbackInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDirectDriverLoadingInfoLUNARG(std::ostream &out, const VkDirectDriverLoadingInfoLUNARG* structInfo, Decoded_VkDirectDriverLoadingInfoLUNARG* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDirectDriverLoadingListLUNARG(std::ostream &out, const VkDirectDriverLoadingListLUNARG* structInfo, Decoded_VkDirectDriverLoadingListLUNARG* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT(std::ostream &out, const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT(std::ostream &out, const VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineShaderStageModuleIdentifierCreateInfoEXT(std::ostream &out, const VkPipelineShaderStageModuleIdentifierCreateInfoEXT* structInfo, Decoded_VkPipelineShaderStageModuleIdentifierCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkShaderModuleIdentifierEXT(std::ostream &out, const VkShaderModuleIdentifierEXT* structInfo, Decoded_VkShaderModuleIdentifierEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkOpticalFlowExecuteInfoNV(std::ostream &out, const VkOpticalFlowExecuteInfoNV* structInfo, Decoded_VkOpticalFlowExecuteInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkOpticalFlowImageFormatInfoNV(std::ostream &out, const VkOpticalFlowImageFormatInfoNV* structInfo, Decoded_VkOpticalFlowImageFormatInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkOpticalFlowImageFormatPropertiesNV(std::ostream &out, const VkOpticalFlowImageFormatPropertiesNV* structInfo, Decoded_VkOpticalFlowImageFormatPropertiesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkOpticalFlowSessionCreateInfoNV(std::ostream &out, const VkOpticalFlowSessionCreateInfoNV* structInfo, Decoded_VkOpticalFlowSessionCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkOpticalFlowSessionCreatePrivateDataInfoNV(std::ostream &out, const VkOpticalFlowSessionCreatePrivateDataInfoNV* structInfo, Decoded_VkOpticalFlowSessionCreatePrivateDataInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceOpticalFlowFeaturesNV(std::ostream &out, const VkPhysicalDeviceOpticalFlowFeaturesNV* structInfo, Decoded_VkPhysicalDeviceOpticalFlowFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceOpticalFlowPropertiesNV(std::ostream &out, const VkPhysicalDeviceOpticalFlowPropertiesNV* structInfo, Decoded_VkPhysicalDeviceOpticalFlowPropertiesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceLegacyDitheringFeaturesEXT(std::ostream &out, const VkPhysicalDeviceLegacyDitheringFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceLegacyDitheringFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAndroidHardwareBufferFormatResolvePropertiesANDROID(std::ostream &out, const VkAndroidHardwareBufferFormatResolvePropertiesANDROID* structInfo, Decoded_VkAndroidHardwareBufferFormatResolvePropertiesANDROID* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID(std::ostream &out, const VkPhysicalDeviceExternalFormatResolveFeaturesANDROID* structInfo, Decoded_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID(std::ostream &out, const VkPhysicalDeviceExternalFormatResolvePropertiesANDROID* structInfo, Decoded_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAntiLagDataAMD(std::ostream &out, const VkAntiLagDataAMD* structInfo, Decoded_VkAntiLagDataAMD* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAntiLagPresentationInfoAMD(std::ostream &out, const VkAntiLagPresentationInfoAMD* structInfo, Decoded_VkAntiLagPresentationInfoAMD* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceAntiLagFeaturesAMD(std::ostream &out, const VkPhysicalDeviceAntiLagFeaturesAMD* structInfo, Decoded_VkPhysicalDeviceAntiLagFeaturesAMD* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDepthClampRangeEXT(std::ostream &out, const VkDepthClampRangeEXT* structInfo, Decoded_VkDepthClampRangeEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderObjectFeaturesEXT(std::ostream &out, const VkPhysicalDeviceShaderObjectFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceShaderObjectFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderObjectPropertiesEXT(std::ostream &out, const VkPhysicalDeviceShaderObjectPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceShaderObjectPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkShaderCreateInfoEXT(std::ostream &out, const VkShaderCreateInfoEXT* structInfo, Decoded_VkShaderCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceTilePropertiesFeaturesQCOM(std::ostream &out, const VkPhysicalDeviceTilePropertiesFeaturesQCOM* structInfo, Decoded_VkPhysicalDeviceTilePropertiesFeaturesQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkTilePropertiesQCOM(std::ostream &out, const VkTilePropertiesQCOM* structInfo, Decoded_VkTilePropertiesQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAmigoProfilingSubmitInfoSEC(std::ostream &out, const VkAmigoProfilingSubmitInfoSEC* structInfo, Decoded_VkAmigoProfilingSubmitInfoSEC* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceAmigoProfilingFeaturesSEC(std::ostream &out, const VkPhysicalDeviceAmigoProfilingFeaturesSEC* structInfo, Decoded_VkPhysicalDeviceAmigoProfilingFeaturesSEC* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM(std::ostream &out, const VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* structInfo, Decoded_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV(std::ostream &out, const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV* structInfo, Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV(std::ostream &out, const VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV* structInfo, Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkConvertCooperativeVectorMatrixInfoNV(std::ostream &out, const VkConvertCooperativeVectorMatrixInfoNV* structInfo, Decoded_VkConvertCooperativeVectorMatrixInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCooperativeVectorPropertiesNV(std::ostream &out, const VkCooperativeVectorPropertiesNV* structInfo, Decoded_VkCooperativeVectorPropertiesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCooperativeVectorFeaturesNV(std::ostream &out, const VkPhysicalDeviceCooperativeVectorFeaturesNV* structInfo, Decoded_VkPhysicalDeviceCooperativeVectorFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCooperativeVectorPropertiesNV(std::ostream &out, const VkPhysicalDeviceCooperativeVectorPropertiesNV* structInfo, Decoded_VkPhysicalDeviceCooperativeVectorPropertiesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV(std::ostream &out, const VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV* structInfo, Decoded_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV(std::ostream &out, const VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV* structInfo, Decoded_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT(std::ostream &out, const VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT(std::ostream &out, const VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkLayerSettingEXT(std::ostream &out, const VkLayerSettingEXT* structInfo, Decoded_VkLayerSettingEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkLayerSettingsCreateInfoEXT(std::ostream &out, const VkLayerSettingsCreateInfoEXT* structInfo, Decoded_VkLayerSettingsCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM(std::ostream &out, const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* structInfo, Decoded_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM(std::ostream &out, const VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM* structInfo, Decoded_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT(std::ostream &out, const VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT* structInfo, Decoded_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT(std::ostream &out, const VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGetLatencyMarkerInfoNV(std::ostream &out, const VkGetLatencyMarkerInfoNV* structInfo, Decoded_VkGetLatencyMarkerInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkLatencySleepInfoNV(std::ostream &out, const VkLatencySleepInfoNV* structInfo, Decoded_VkLatencySleepInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkLatencySleepModeInfoNV(std::ostream &out, const VkLatencySleepModeInfoNV* structInfo, Decoded_VkLatencySleepModeInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkLatencySubmissionPresentIdNV(std::ostream &out, const VkLatencySubmissionPresentIdNV* structInfo, Decoded_VkLatencySubmissionPresentIdNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkLatencySurfaceCapabilitiesNV(std::ostream &out, const VkLatencySurfaceCapabilitiesNV* structInfo, Decoded_VkLatencySurfaceCapabilitiesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkLatencyTimingsFrameReportNV(std::ostream &out, const VkLatencyTimingsFrameReportNV* structInfo, Decoded_VkLatencyTimingsFrameReportNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkOutOfBandQueueTypeInfoNV(std::ostream &out, const VkOutOfBandQueueTypeInfoNV* structInfo, Decoded_VkOutOfBandQueueTypeInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSetLatencyMarkerInfoNV(std::ostream &out, const VkSetLatencyMarkerInfoNV* structInfo, Decoded_VkSetLatencyMarkerInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSwapchainLatencyCreateInfoNV(std::ostream &out, const VkSwapchainLatencyCreateInfoNV* structInfo, Decoded_VkSwapchainLatencyCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM(std::ostream &out, const VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM* structInfo, Decoded_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM(std::ostream &out, const VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM* structInfo, Decoded_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePerStageDescriptorSetFeaturesNV(std::ostream &out, const VkPhysicalDevicePerStageDescriptorSetFeaturesNV* structInfo, Decoded_VkPhysicalDevicePerStageDescriptorSetFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageProcessing2FeaturesQCOM(std::ostream &out, const VkPhysicalDeviceImageProcessing2FeaturesQCOM* structInfo, Decoded_VkPhysicalDeviceImageProcessing2FeaturesQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageProcessing2PropertiesQCOM(std::ostream &out, const VkPhysicalDeviceImageProcessing2PropertiesQCOM* structInfo, Decoded_VkPhysicalDeviceImageProcessing2PropertiesQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSamplerBlockMatchWindowCreateInfoQCOM(std::ostream &out, const VkSamplerBlockMatchWindowCreateInfoQCOM* structInfo, Decoded_VkSamplerBlockMatchWindowCreateInfoQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBlitImageCubicWeightsInfoQCOM(std::ostream &out, const VkBlitImageCubicWeightsInfoQCOM* structInfo, Decoded_VkBlitImageCubicWeightsInfoQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCubicWeightsFeaturesQCOM(std::ostream &out, const VkPhysicalDeviceCubicWeightsFeaturesQCOM* structInfo, Decoded_VkPhysicalDeviceCubicWeightsFeaturesQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSamplerCubicWeightsCreateInfoQCOM(std::ostream &out, const VkSamplerCubicWeightsCreateInfoQCOM* structInfo, Decoded_VkSamplerCubicWeightsCreateInfoQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM(std::ostream &out, const VkPhysicalDeviceYcbcrDegammaFeaturesQCOM* structInfo, Decoded_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM(std::ostream &out, const VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM* structInfo, Decoded_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCubicClampFeaturesQCOM(std::ostream &out, const VkPhysicalDeviceCubicClampFeaturesQCOM* structInfo, Decoded_VkPhysicalDeviceCubicClampFeaturesQCOM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT(std::ostream &out, const VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceLayeredDriverPropertiesMSFT(std::ostream &out, const VkPhysicalDeviceLayeredDriverPropertiesMSFT* structInfo, Decoded_VkPhysicalDeviceLayeredDriverPropertiesMSFT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV(std::ostream &out, const VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV* structInfo, Decoded_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayModeStereoPropertiesNV(std::ostream &out, const VkDisplayModeStereoPropertiesNV* structInfo, Decoded_VkDisplayModeStereoPropertiesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplaySurfaceStereoCreateInfoNV(std::ostream &out, const VkDisplaySurfaceStereoCreateInfoNV* structInfo, Decoded_VkDisplaySurfaceStereoCreateInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRawAccessChainsFeaturesNV(std::ostream &out, const VkPhysicalDeviceRawAccessChainsFeaturesNV* structInfo, Decoded_VkPhysicalDeviceRawAccessChainsFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCommandBufferInheritanceFeaturesNV(std::ostream &out, const VkPhysicalDeviceCommandBufferInheritanceFeaturesNV* structInfo, Decoded_VkPhysicalDeviceCommandBufferInheritanceFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV(std::ostream &out, const VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV* structInfo, Decoded_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT(std::ostream &out, const VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRayTracingValidationFeaturesNV(std::ostream &out, const VkPhysicalDeviceRayTracingValidationFeaturesNV* structInfo, Decoded_VkPhysicalDeviceRayTracingValidationFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureBuildSizesInfoKHR(std::ostream &out, const VkAccelerationStructureBuildSizesInfoKHR* structInfo, Decoded_VkAccelerationStructureBuildSizesInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBuildPartitionedAccelerationStructureIndirectCommandNV(std::ostream &out, const VkBuildPartitionedAccelerationStructureIndirectCommandNV* structInfo, Decoded_VkBuildPartitionedAccelerationStructureIndirectCommandNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBuildPartitionedAccelerationStructureInfoNV(std::ostream &out, const VkBuildPartitionedAccelerationStructureInfoNV* structInfo, Decoded_VkBuildPartitionedAccelerationStructureInfoNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPartitionedAccelerationStructureFlagsNV(std::ostream &out, const VkPartitionedAccelerationStructureFlagsNV* structInfo, Decoded_VkPartitionedAccelerationStructureFlagsNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPartitionedAccelerationStructureInstancesInputNV(std::ostream &out, const VkPartitionedAccelerationStructureInstancesInputNV* structInfo, Decoded_VkPartitionedAccelerationStructureInstancesInputNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPartitionedAccelerationStructureUpdateInstanceDataNV(std::ostream &out, const VkPartitionedAccelerationStructureUpdateInstanceDataNV* structInfo, Decoded_VkPartitionedAccelerationStructureUpdateInstanceDataNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPartitionedAccelerationStructureWriteInstanceDataNV(std::ostream &out, const VkPartitionedAccelerationStructureWriteInstanceDataNV* structInfo, Decoded_VkPartitionedAccelerationStructureWriteInstanceDataNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPartitionedAccelerationStructureWritePartitionTranslationDataNV(std::ostream &out, const VkPartitionedAccelerationStructureWritePartitionTranslationDataNV* structInfo, Decoded_VkPartitionedAccelerationStructureWritePartitionTranslationDataNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV(std::ostream &out, const VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV* structInfo, Decoded_VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV(std::ostream &out, const VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV* structInfo, Decoded_VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkStridedDeviceAddressNV(std::ostream &out, const VkStridedDeviceAddressNV* structInfo, Decoded_VkStridedDeviceAddressNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkWriteDescriptorSetPartitionedAccelerationStructureNV(std::ostream &out, const VkWriteDescriptorSetPartitionedAccelerationStructureNV* structInfo, Decoded_VkWriteDescriptorSetPartitionedAccelerationStructureNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindIndexBufferIndirectCommandEXT(std::ostream &out, const VkBindIndexBufferIndirectCommandEXT* structInfo, Decoded_VkBindIndexBufferIndirectCommandEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindVertexBufferIndirectCommandEXT(std::ostream &out, const VkBindVertexBufferIndirectCommandEXT* structInfo, Decoded_VkBindVertexBufferIndirectCommandEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDrawIndirectCountIndirectCommandEXT(std::ostream &out, const VkDrawIndirectCountIndirectCommandEXT* structInfo, Decoded_VkDrawIndirectCountIndirectCommandEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGeneratedCommandsInfoEXT(std::ostream &out, const VkGeneratedCommandsInfoEXT* structInfo, Decoded_VkGeneratedCommandsInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGeneratedCommandsMemoryRequirementsInfoEXT(std::ostream &out, const VkGeneratedCommandsMemoryRequirementsInfoEXT* structInfo, Decoded_VkGeneratedCommandsMemoryRequirementsInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGeneratedCommandsPipelineInfoEXT(std::ostream &out, const VkGeneratedCommandsPipelineInfoEXT* structInfo, Decoded_VkGeneratedCommandsPipelineInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGeneratedCommandsShaderInfoEXT(std::ostream &out, const VkGeneratedCommandsShaderInfoEXT* structInfo, Decoded_VkGeneratedCommandsShaderInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkIndirectCommandsExecutionSetTokenEXT(std::ostream &out, const VkIndirectCommandsExecutionSetTokenEXT* structInfo, Decoded_VkIndirectCommandsExecutionSetTokenEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkIndirectCommandsIndexBufferTokenEXT(std::ostream &out, const VkIndirectCommandsIndexBufferTokenEXT* structInfo, Decoded_VkIndirectCommandsIndexBufferTokenEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkIndirectCommandsLayoutCreateInfoEXT(std::ostream &out, const VkIndirectCommandsLayoutCreateInfoEXT* structInfo, Decoded_VkIndirectCommandsLayoutCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkIndirectCommandsPushConstantTokenEXT(std::ostream &out, const VkIndirectCommandsPushConstantTokenEXT* structInfo, Decoded_VkIndirectCommandsPushConstantTokenEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkIndirectCommandsVertexBufferTokenEXT(std::ostream &out, const VkIndirectCommandsVertexBufferTokenEXT* structInfo, Decoded_VkIndirectCommandsVertexBufferTokenEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkIndirectExecutionSetPipelineInfoEXT(std::ostream &out, const VkIndirectExecutionSetPipelineInfoEXT* structInfo, Decoded_VkIndirectExecutionSetPipelineInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkIndirectExecutionSetShaderInfoEXT(std::ostream &out, const VkIndirectExecutionSetShaderInfoEXT* structInfo, Decoded_VkIndirectExecutionSetShaderInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkIndirectExecutionSetShaderLayoutInfoEXT(std::ostream &out, const VkIndirectExecutionSetShaderLayoutInfoEXT* structInfo, Decoded_VkIndirectExecutionSetShaderLayoutInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT(std::ostream &out, const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT(std::ostream &out, const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkWriteIndirectExecutionSetPipelineEXT(std::ostream &out, const VkWriteIndirectExecutionSetPipelineEXT* structInfo, Decoded_VkWriteIndirectExecutionSetPipelineEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkWriteIndirectExecutionSetShaderEXT(std::ostream &out, const VkWriteIndirectExecutionSetShaderEXT* structInfo, Decoded_VkWriteIndirectExecutionSetShaderEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageAlignmentControlCreateInfoMESA(std::ostream &out, const VkImageAlignmentControlCreateInfoMESA* structInfo, Decoded_VkImageAlignmentControlCreateInfoMESA* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageAlignmentControlFeaturesMESA(std::ostream &out, const VkPhysicalDeviceImageAlignmentControlFeaturesMESA* structInfo, Decoded_VkPhysicalDeviceImageAlignmentControlFeaturesMESA* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageAlignmentControlPropertiesMESA(std::ostream &out, const VkPhysicalDeviceImageAlignmentControlPropertiesMESA* structInfo, Decoded_VkPhysicalDeviceImageAlignmentControlPropertiesMESA* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDepthClampControlFeaturesEXT(std::ostream &out, const VkPhysicalDeviceDepthClampControlFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceDepthClampControlFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineViewportDepthClampControlCreateInfoEXT(std::ostream &out, const VkPipelineViewportDepthClampControlCreateInfoEXT* structInfo, Decoded_VkPipelineViewportDepthClampControlCreateInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkHdrVividDynamicMetadataHUAWEI(std::ostream &out, const VkHdrVividDynamicMetadataHUAWEI* structInfo, Decoded_VkHdrVividDynamicMetadataHUAWEI* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceHdrVividFeaturesHUAWEI(std::ostream &out, const VkPhysicalDeviceHdrVividFeaturesHUAWEI* structInfo, Decoded_VkPhysicalDeviceHdrVividFeaturesHUAWEI* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCooperativeMatrixFlexibleDimensionsPropertiesNV(std::ostream &out, const VkCooperativeMatrixFlexibleDimensionsPropertiesNV* structInfo, Decoded_VkCooperativeMatrixFlexibleDimensionsPropertiesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCooperativeMatrix2FeaturesNV(std::ostream &out, const VkPhysicalDeviceCooperativeMatrix2FeaturesNV* structInfo, Decoded_VkPhysicalDeviceCooperativeMatrix2FeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCooperativeMatrix2PropertiesNV(std::ostream &out, const VkPhysicalDeviceCooperativeMatrix2PropertiesNV* structInfo, Decoded_VkPhysicalDeviceCooperativeMatrix2PropertiesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePipelineOpacityMicromapFeaturesARM(std::ostream &out, const VkPhysicalDevicePipelineOpacityMicromapFeaturesARM* structInfo, Decoded_VkPhysicalDevicePipelineOpacityMicromapFeaturesARM* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImportMemoryMetalHandleInfoEXT(std::ostream &out, const VkImportMemoryMetalHandleInfoEXT* structInfo, Decoded_VkImportMemoryMetalHandleInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryGetMetalHandleInfoEXT(std::ostream &out, const VkMemoryGetMetalHandleInfoEXT* structInfo, Decoded_VkMemoryGetMetalHandleInfoEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryMetalHandlePropertiesEXT(std::ostream &out, const VkMemoryMetalHandlePropertiesEXT* structInfo, Decoded_VkMemoryMetalHandlePropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT(std::ostream &out, const VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePresentMeteringFeaturesNV(std::ostream &out, const VkPhysicalDevicePresentMeteringFeaturesNV* structInfo, Decoded_VkPhysicalDevicePresentMeteringFeaturesNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSetPresentConfigNV(std::ostream &out, const VkSetPresentConfigNV* structInfo, Decoded_VkSetPresentConfigNV* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureBuildGeometryInfoKHR(std::ostream &out, const VkAccelerationStructureBuildGeometryInfoKHR* structInfo, Decoded_VkAccelerationStructureBuildGeometryInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureBuildRangeInfoKHR(std::ostream &out, const VkAccelerationStructureBuildRangeInfoKHR* structInfo, Decoded_VkAccelerationStructureBuildRangeInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureCreateInfoKHR(std::ostream &out, const VkAccelerationStructureCreateInfoKHR* structInfo, Decoded_VkAccelerationStructureCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureDeviceAddressInfoKHR(std::ostream &out, const VkAccelerationStructureDeviceAddressInfoKHR* structInfo, Decoded_VkAccelerationStructureDeviceAddressInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureGeometryAabbsDataKHR(std::ostream &out, const VkAccelerationStructureGeometryAabbsDataKHR* structInfo, Decoded_VkAccelerationStructureGeometryAabbsDataKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureGeometryInstancesDataKHR(std::ostream &out, const VkAccelerationStructureGeometryInstancesDataKHR* structInfo, Decoded_VkAccelerationStructureGeometryInstancesDataKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureGeometryTrianglesDataKHR(std::ostream &out, const VkAccelerationStructureGeometryTrianglesDataKHR* structInfo, Decoded_VkAccelerationStructureGeometryTrianglesDataKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureVersionInfoKHR(std::ostream &out, const VkAccelerationStructureVersionInfoKHR* structInfo, Decoded_VkAccelerationStructureVersionInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyAccelerationStructureInfoKHR(std::ostream &out, const VkCopyAccelerationStructureInfoKHR* structInfo, Decoded_VkCopyAccelerationStructureInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyAccelerationStructureToMemoryInfoKHR(std::ostream &out, const VkCopyAccelerationStructureToMemoryInfoKHR* structInfo, Decoded_VkCopyAccelerationStructureToMemoryInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyMemoryToAccelerationStructureInfoKHR(std::ostream &out, const VkCopyMemoryToAccelerationStructureInfoKHR* structInfo, Decoded_VkCopyMemoryToAccelerationStructureInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceAccelerationStructureFeaturesKHR(std::ostream &out, const VkPhysicalDeviceAccelerationStructureFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceAccelerationStructureFeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceAccelerationStructurePropertiesKHR(std::ostream &out, const VkPhysicalDeviceAccelerationStructurePropertiesKHR* structInfo, Decoded_VkPhysicalDeviceAccelerationStructurePropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkWriteDescriptorSetAccelerationStructureKHR(std::ostream &out, const VkWriteDescriptorSetAccelerationStructureKHR* structInfo, Decoded_VkWriteDescriptorSetAccelerationStructureKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRayTracingPipelineFeaturesKHR(std::ostream &out, const VkPhysicalDeviceRayTracingPipelineFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceRayTracingPipelineFeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRayTracingPipelinePropertiesKHR(std::ostream &out, const VkPhysicalDeviceRayTracingPipelinePropertiesKHR* structInfo, Decoded_VkPhysicalDeviceRayTracingPipelinePropertiesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRayTracingPipelineCreateInfoKHR(std::ostream &out, const VkRayTracingPipelineCreateInfoKHR* structInfo, Decoded_VkRayTracingPipelineCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRayTracingPipelineInterfaceCreateInfoKHR(std::ostream &out, const VkRayTracingPipelineInterfaceCreateInfoKHR* structInfo, Decoded_VkRayTracingPipelineInterfaceCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRayTracingShaderGroupCreateInfoKHR(std::ostream &out, const VkRayTracingShaderGroupCreateInfoKHR* structInfo, Decoded_VkRayTracingShaderGroupCreateInfoKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkStridedDeviceAddressRegionKHR(std::ostream &out, const VkStridedDeviceAddressRegionKHR* structInfo, Decoded_VkStridedDeviceAddressRegionKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkTraceRaysIndirectCommandKHR(std::ostream &out, const VkTraceRaysIndirectCommandKHR* structInfo, Decoded_VkTraceRaysIndirectCommandKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRayQueryFeaturesKHR(std::ostream &out, const VkPhysicalDeviceRayQueryFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceRayQueryFeaturesKHR* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDrawMeshTasksIndirectCommandEXT(std::ostream &out, const VkDrawMeshTasksIndirectCommandEXT* structInfo, Decoded_VkDrawMeshTasksIndirectCommandEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMeshShaderFeaturesEXT(std::ostream &out, const VkPhysicalDeviceMeshShaderFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceMeshShaderFeaturesEXT* metaInfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMeshShaderPropertiesEXT(std::ostream &out, const VkPhysicalDeviceMeshShaderPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceMeshShaderPropertiesEXT* metaInfo, VulkanCppConsumerBase &consumer);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
