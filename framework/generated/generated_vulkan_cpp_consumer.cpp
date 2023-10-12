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

#include "generated/generated_vulkan_cpp_consumer.h"

#include "decode/vulkan_cpp_consumer_base.h"
#include "decode/vulkan_cpp_structs.h"
#include "generated/generated_vulkan_cpp_structs.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "generated/generated_vulkan_cpp_consumer_extension.h"
#include "util/defines.h"
#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

#include <iostream>
#include <sstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)


void VulkanCppConsumer::Process_vkAllocateCommandBuffers(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pAllocateInfo */
    std::stringstream stream_pAllocateInfo;
    std::string pAllocateInfoStruct = GenerateStruct_VkCommandBufferAllocateInfo(stream_pAllocateInfo,
                                                                     pAllocateInfo->GetPointer(),
                                                                     pAllocateInfo->GetMetaStructPointer(),
                                                                     *this);
    fprintf(file, "\n%s", stream_pAllocateInfo.str().c_str());
/* pCommandBuffers */
    std::string pCommandBuffersName = "pCommandBuffers_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_COMMAND_BUFFER));
    AddKnownVariables("VkCommandBuffer", pCommandBuffersName, pCommandBuffers->GetPointer(), pAllocateInfo->GetPointer()->commandBufferCount);
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pCommandBuffersName,
                         pCommandBuffers->GetPointer(), pAllocateInfo->GetPointer()->commandBufferCount);
    }
    fprintf(file,
            "VK_CALL_CHECK(vkAllocateCommandBuffers(%s, &%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            pAllocateInfoStruct.c_str(),
            pCommandBuffersName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkAllocateCommandBuffers);
}

void VulkanCppConsumer::Process_vkAllocateDescriptorSets(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pAllocateInfo */
    std::stringstream stream_pAllocateInfo;
    std::string pAllocateInfoStruct = GenerateStruct_VkDescriptorSetAllocateInfo(stream_pAllocateInfo,
                                                                     pAllocateInfo->GetPointer(),
                                                                     pAllocateInfo->GetMetaStructPointer(),
                                                                     *this);
    fprintf(file, "\n%s", stream_pAllocateInfo.str().c_str());
/* pDescriptorSets */
    std::string pDescriptorSetsName = "pDescriptorSets_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_DESCRIPTOR_SET));
    AddKnownVariables("VkDescriptorSet", pDescriptorSetsName, pDescriptorSets->GetPointer(), pAllocateInfo->GetPointer()->descriptorSetCount);
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pDescriptorSetsName,
                         pDescriptorSets->GetPointer(), pAllocateInfo->GetPointer()->descriptorSetCount);
    }
    fprintf(file,
            "VK_CALL_CHECK(vkAllocateDescriptorSets(%s, &%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            pAllocateInfoStruct.c_str(),
            pDescriptorSetsName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkAllocateDescriptorSets);
}

void VulkanCppConsumer::Process_vkAllocateMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryAllocateInfo>* pAllocateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeviceMemory>*       pMemory)
{
    Generate_vkAllocateMemory(returnValue, device, pAllocateInfo, pAllocator, pMemory);
    Post_APICall(format::ApiCallId::ApiCall_vkAllocateMemory);
}

void VulkanCppConsumer::Process_vkBeginCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pBeginInfo */
    std::stringstream stream_pBeginInfo;
    std::string pBeginInfoStruct = GenerateStruct_VkCommandBufferBeginInfo(stream_pBeginInfo,
                                                                  pBeginInfo->GetPointer(),
                                                                  pBeginInfo->GetMetaStructPointer(),
                                                                  *this);
    fprintf(file, "\n%s", stream_pBeginInfo.str().c_str());
    fprintf(file,
            "VK_CALL_CHECK(vkBeginCommandBuffer(%s, &%s), %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pBeginInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBeginCommandBuffer);
}

void VulkanCppConsumer::Process_vkBindBufferMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            buffer,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* buffer */
/* memory */
/* memoryOffset */
    fprintf(file,
            "VK_CALL_CHECK(vkBindBufferMemory(%s, %s, %s, %luUL), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(buffer).c_str(),
            this->GetHandle(memory).c_str(),
            memoryOffset,
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindBufferMemory);
}

void VulkanCppConsumer::Process_vkBindImageMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* image */
/* memory */
/* memoryOffset */
    fprintf(file,
            "VK_CALL_CHECK(vkBindImageMemory(%s, %s, %s, %luUL), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(image).c_str(),
            this->GetHandle(memory).c_str(),
            memoryOffset,
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindImageMemory);
}

void VulkanCppConsumer::Process_vkCmdBeginQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* queryPool */
/* query */
/* flags */
    fprintf(file,
            "vkCmdBeginQuery(%s, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(queryPool).c_str(),
            query,
            util::ToString<VkQueryControlFlags>(flags).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginQuery);
}

void VulkanCppConsumer::Process_vkCmdBeginRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                           contents)
{
    Intercept_vkCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pRenderPassBegin */
    std::stringstream stream_pRenderPassBegin;
    std::string pRenderPassBeginStruct = GenerateStruct_VkRenderPassBeginInfo(stream_pRenderPassBegin,
                                                                        pRenderPassBegin->GetPointer(),
                                                                        pRenderPassBegin->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "\n%s", stream_pRenderPassBegin.str().c_str());
/* contents */
    fprintf(file,
            "vkCmdBeginRenderPass(%s, &%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pRenderPassBeginStruct.c_str(),
            util::ToString<VkSubpassContents>(contents).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginRenderPass);
}

void VulkanCppConsumer::Process_vkCmdBindDescriptorSets(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    PointerDecoder<uint32_t>*                   pDynamicOffsets)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pipelineBindPoint */
/* layout */
/* firstSet */
/* descriptorSetCount */
/* pDescriptorSets */
    std::string pDescriptorSetsArray = "NULL";
    std::string pDescriptorSetsValues = toStringJoin(pDescriptorSets->GetPointer(),
                                                     pDescriptorSets->GetPointer() + descriptorSetCount,
                                                     [&](const format::HandleId current) { return this->GetHandle(current); },
                                                     ", ");
    if (descriptorSetCount == 1) {
        pDescriptorSetsArray = "&" + pDescriptorSetsValues;
    } else if (descriptorSetCount > 1) {
        pDescriptorSetsArray = "pDescriptorSetsArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkDescriptorSet %s[] = { %s };\n", pDescriptorSetsArray.c_str(), pDescriptorSetsValues.c_str());
    }
/* dynamicOffsetCount */
/* pDynamicOffsets */
    std::string pDynamicOffsetsArray = "pDynamicOffsets_" + std::to_string(this->getNextId());
    if (dynamicOffsetCount > 0) {
        std::string pDynamicOffsetsValues = toStringJoin(pDynamicOffsets->GetPointer(),
                                                         pDynamicOffsets->GetPointer() + dynamicOffsetCount,
                                                         [&](const auto current) { return std::to_string(current) + ""; },
                                                         ", ");
        fprintf(file, "uint32_t %s[] = { %s };\n", pDynamicOffsetsArray.c_str(), pDynamicOffsetsValues.c_str());
    } else {
        pDynamicOffsetsArray = "NULL";
    }
    fprintf(file,
            "vkCmdBindDescriptorSets(%s, %s, %s, %u, %u, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineBindPoint>(pipelineBindPoint).c_str(),
            this->GetHandle(layout).c_str(),
            firstSet,
            descriptorSetCount,
            pDescriptorSetsArray.c_str(),
            dynamicOffsetCount,
            pDynamicOffsetsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindDescriptorSets);
}

void VulkanCppConsumer::Process_vkCmdBindIndexBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* buffer */
/* offset */
/* indexType */
    fprintf(file,
            "vkCmdBindIndexBuffer(%s, %s, %luUL, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            util::ToString<VkIndexType>(indexType).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindIndexBuffer);
}

void VulkanCppConsumer::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pipelineBindPoint */
/* pipeline */
    fprintf(file,
            "vkCmdBindPipeline(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineBindPoint>(pipelineBindPoint).c_str(),
            this->GetHandle(pipeline).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindPipeline);
}

void VulkanCppConsumer::Process_vkCmdBindVertexBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* firstBinding */
/* bindingCount */
/* pBuffers */
    std::string pBuffersArray = "NULL";
    std::string pBuffersValues = toStringJoin(pBuffers->GetPointer(),
                                              pBuffers->GetPointer() + bindingCount,
                                              [&](const format::HandleId current) { return this->GetHandle(current); },
                                              ", ");
    if (bindingCount == 1) {
        pBuffersArray = "&" + pBuffersValues;
    } else if (bindingCount > 1) {
        pBuffersArray = "pBuffersArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkBuffer %s[] = { %s };\n", pBuffersArray.c_str(), pBuffersValues.c_str());
    }
/* pOffsets */
    std::string pOffsetsArray = "pOffsets_" + std::to_string(this->getNextId());
    if (bindingCount > 0) {
        std::string pOffsetsValues = toStringJoin(pOffsets->GetPointer(),
                                                  pOffsets->GetPointer() + bindingCount,
                                                  [&](const auto current) { return std::to_string(current) + "UL"; },
                                                  ", ");
        fprintf(file, "VkDeviceSize %s[] = { %s };\n", pOffsetsArray.c_str(), pOffsetsValues.c_str());
    } else {
        pOffsetsArray = "NULL";
    }
    fprintf(file,
            "vkCmdBindVertexBuffers(%s, %u, %u, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstBinding,
            bindingCount,
            pBuffersArray.c_str(),
            pOffsetsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindVertexBuffers);
}

void VulkanCppConsumer::Process_vkCmdBlitImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageBlit>*  pRegions,
    VkFilter                                    filter)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* srcImage */
/* srcImageLayout */
/* dstImage */
/* dstImageLayout */
/* regionCount */
/* pRegions */
    std::stringstream stream_pRegions;
    std::string pRegionsArray = "NULL";
    PointerPairContainer<decltype(pRegions->GetPointer()), decltype(pRegions->GetMetaStructPointer())> pRegionsPair{ pRegions->GetPointer(), pRegions->GetMetaStructPointer(), regionCount };
    std::string pRegionsNames = toStringJoin(pRegionsPair.begin(),
                                             pRegionsPair.end(),
                                             [&](auto pair) { return GenerateStruct_VkImageBlit(stream_pRegions, pair.t1, pair.t2, *this); },
                                             ", ");
    fprintf(file, "\n%s", stream_pRegions.str().c_str());
    if (regionCount == 1) {
        pRegionsArray = "&" + pRegionsNames;
    } else if (regionCount > 1) {
        pRegionsArray = "pRegions_" + std::to_string(this->getNextId());
        fprintf(file, "VkImageBlit %s[] = { %s };\n", pRegionsArray.c_str(), pRegionsNames.c_str());
    }
/* filter */
    fprintf(file,
            "vkCmdBlitImage(%s, %s, %s, %s, %s, %u, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(srcImage).c_str(),
            util::ToString<VkImageLayout>(srcImageLayout).c_str(),
            this->GetHandle(dstImage).c_str(),
            util::ToString<VkImageLayout>(dstImageLayout).c_str(),
            regionCount,
            pRegionsArray.c_str(),
            util::ToString<VkFilter>(filter).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBlitImage);
}

void VulkanCppConsumer::Process_vkCmdClearAttachments(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkClearAttachment>* pAttachments,
    uint32_t                                    rectCount,
    StructPointerDecoder<Decoded_VkClearRect>*  pRects)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* attachmentCount */
/* pAttachments */
    std::stringstream stream_pAttachments;
    std::string pAttachmentsArray = "NULL";
    PointerPairContainer<decltype(pAttachments->GetPointer()), decltype(pAttachments->GetMetaStructPointer())> pAttachmentsPair{ pAttachments->GetPointer(), pAttachments->GetMetaStructPointer(), attachmentCount };
    std::string pAttachmentsNames = toStringJoin(pAttachmentsPair.begin(),
                                                 pAttachmentsPair.end(),
                                                 [&](auto pair) { return GenerateStruct_VkClearAttachment(stream_pAttachments, pair.t1, pair.t2, *this); },
                                                 ", ");
    fprintf(file, "\n%s", stream_pAttachments.str().c_str());
    if (attachmentCount == 1) {
        pAttachmentsArray = "&" + pAttachmentsNames;
    } else if (attachmentCount > 1) {
        pAttachmentsArray = "pAttachments_" + std::to_string(this->getNextId());
        fprintf(file, "VkClearAttachment %s[] = { %s };\n", pAttachmentsArray.c_str(), pAttachmentsNames.c_str());
    }
/* rectCount */
/* pRects */
    std::stringstream stream_pRects;
    std::string pRectsArray = "NULL";
    PointerPairContainer<decltype(pRects->GetPointer()), decltype(pRects->GetMetaStructPointer())> pRectsPair{ pRects->GetPointer(), pRects->GetMetaStructPointer(), rectCount };
    std::string pRectsNames = toStringJoin(pRectsPair.begin(),
                                           pRectsPair.end(),
                                           [&](auto pair) { return GenerateStruct_VkClearRect(stream_pRects, pair.t1, pair.t2, *this); },
                                           ", ");
    fprintf(file, "\n%s", stream_pRects.str().c_str());
    if (rectCount == 1) {
        pRectsArray = "&" + pRectsNames;
    } else if (rectCount > 1) {
        pRectsArray = "pRects_" + std::to_string(this->getNextId());
        fprintf(file, "VkClearRect %s[] = { %s };\n", pRectsArray.c_str(), pRectsNames.c_str());
    }
    fprintf(file,
            "vkCmdClearAttachments(%s, %u, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            attachmentCount,
            pAttachmentsArray.c_str(),
            rectCount,
            pRectsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdClearAttachments);
}

void VulkanCppConsumer::Process_vkCmdClearColorImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            image,
    VkImageLayout                               imageLayout,
    StructPointerDecoder<Decoded_VkClearColorValue>* pColor,
    uint32_t                                    rangeCount,
    StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* image */
/* imageLayout */
/* pColor */
    std::stringstream stream_pColor;
    std::string pColorStruct = GenerateStruct_VkClearColorValue(stream_pColor,
                                                              pColor->GetPointer(),
                                                              pColor->GetMetaStructPointer(),
                                                              *this);
    fprintf(file, "\n%s", stream_pColor.str().c_str());
/* rangeCount */
/* pRanges */
    std::stringstream stream_pRanges;
    std::string pRangesArray = "NULL";
    PointerPairContainer<decltype(pRanges->GetPointer()), decltype(pRanges->GetMetaStructPointer())> pRangesPair{ pRanges->GetPointer(), pRanges->GetMetaStructPointer(), rangeCount };
    std::string pRangesNames = toStringJoin(pRangesPair.begin(),
                                            pRangesPair.end(),
                                            [&](auto pair) { return GenerateStruct_VkImageSubresourceRange(stream_pRanges, pair.t1, pair.t2, *this); },
                                            ", ");
    fprintf(file, "\n%s", stream_pRanges.str().c_str());
    if (rangeCount == 1) {
        pRangesArray = "&" + pRangesNames;
    } else if (rangeCount > 1) {
        pRangesArray = "pRanges_" + std::to_string(this->getNextId());
        fprintf(file, "VkImageSubresourceRange %s[] = { %s };\n", pRangesArray.c_str(), pRangesNames.c_str());
    }
    fprintf(file,
            "vkCmdClearColorImage(%s, %s, %s, &%s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(image).c_str(),
            util::ToString<VkImageLayout>(imageLayout).c_str(),
            pColorStruct.c_str(),
            rangeCount,
            pRangesArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdClearColorImage);
}

void VulkanCppConsumer::Process_vkCmdClearDepthStencilImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            image,
    VkImageLayout                               imageLayout,
    StructPointerDecoder<Decoded_VkClearDepthStencilValue>* pDepthStencil,
    uint32_t                                    rangeCount,
    StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* image */
/* imageLayout */
/* pDepthStencil */
    std::stringstream stream_pDepthStencil;
    std::string pDepthStencilStruct = GenerateStruct_VkClearDepthStencilValue(stream_pDepthStencil,
                                                                     pDepthStencil->GetPointer(),
                                                                     pDepthStencil->GetMetaStructPointer(),
                                                                     *this);
    fprintf(file, "\n%s", stream_pDepthStencil.str().c_str());
/* rangeCount */
/* pRanges */
    std::stringstream stream_pRanges;
    std::string pRangesArray = "NULL";
    PointerPairContainer<decltype(pRanges->GetPointer()), decltype(pRanges->GetMetaStructPointer())> pRangesPair{ pRanges->GetPointer(), pRanges->GetMetaStructPointer(), rangeCount };
    std::string pRangesNames = toStringJoin(pRangesPair.begin(),
                                            pRangesPair.end(),
                                            [&](auto pair) { return GenerateStruct_VkImageSubresourceRange(stream_pRanges, pair.t1, pair.t2, *this); },
                                            ", ");
    fprintf(file, "\n%s", stream_pRanges.str().c_str());
    if (rangeCount == 1) {
        pRangesArray = "&" + pRangesNames;
    } else if (rangeCount > 1) {
        pRangesArray = "pRanges_" + std::to_string(this->getNextId());
        fprintf(file, "VkImageSubresourceRange %s[] = { %s };\n", pRangesArray.c_str(), pRangesNames.c_str());
    }
    fprintf(file,
            "vkCmdClearDepthStencilImage(%s, %s, %s, &%s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(image).c_str(),
            util::ToString<VkImageLayout>(imageLayout).c_str(),
            pDepthStencilStruct.c_str(),
            rangeCount,
            pRangesArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage);
}

void VulkanCppConsumer::Process_vkCmdCopyBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferCopy>* pRegions)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* srcBuffer */
/* dstBuffer */
/* regionCount */
/* pRegions */
    std::stringstream stream_pRegions;
    std::string pRegionsArray = "NULL";
    PointerPairContainer<decltype(pRegions->GetPointer()), decltype(pRegions->GetMetaStructPointer())> pRegionsPair{ pRegions->GetPointer(), pRegions->GetMetaStructPointer(), regionCount };
    std::string pRegionsNames = toStringJoin(pRegionsPair.begin(),
                                             pRegionsPair.end(),
                                             [&](auto pair) { return GenerateStruct_VkBufferCopy(stream_pRegions, pair.t1, pair.t2, *this); },
                                             ", ");
    fprintf(file, "\n%s", stream_pRegions.str().c_str());
    if (regionCount == 1) {
        pRegionsArray = "&" + pRegionsNames;
    } else if (regionCount > 1) {
        pRegionsArray = "pRegions_" + std::to_string(this->getNextId());
        fprintf(file, "VkBufferCopy %s[] = { %s };\n", pRegionsArray.c_str(), pRegionsNames.c_str());
    }
    fprintf(file,
            "vkCmdCopyBuffer(%s, %s, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(srcBuffer).c_str(),
            this->GetHandle(dstBuffer).c_str(),
            regionCount,
            pRegionsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyBuffer);
}

void VulkanCppConsumer::Process_vkCmdCopyBufferToImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* srcBuffer */
/* dstImage */
/* dstImageLayout */
/* regionCount */
/* pRegions */
    std::stringstream stream_pRegions;
    std::string pRegionsArray = "NULL";
    PointerPairContainer<decltype(pRegions->GetPointer()), decltype(pRegions->GetMetaStructPointer())> pRegionsPair{ pRegions->GetPointer(), pRegions->GetMetaStructPointer(), regionCount };
    std::string pRegionsNames = toStringJoin(pRegionsPair.begin(),
                                             pRegionsPair.end(),
                                             [&](auto pair) { return GenerateStruct_VkBufferImageCopy(stream_pRegions, pair.t1, pair.t2, *this); },
                                             ", ");
    fprintf(file, "\n%s", stream_pRegions.str().c_str());
    if (regionCount == 1) {
        pRegionsArray = "&" + pRegionsNames;
    } else if (regionCount > 1) {
        pRegionsArray = "pRegions_" + std::to_string(this->getNextId());
        fprintf(file, "VkBufferImageCopy %s[] = { %s };\n", pRegionsArray.c_str(), pRegionsNames.c_str());
    }
    fprintf(file,
            "vkCmdCopyBufferToImage(%s, %s, %s, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(srcBuffer).c_str(),
            this->GetHandle(dstImage).c_str(),
            util::ToString<VkImageLayout>(dstImageLayout).c_str(),
            regionCount,
            pRegionsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyBufferToImage);
}

void VulkanCppConsumer::Process_vkCmdCopyImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageCopy>*  pRegions)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* srcImage */
/* srcImageLayout */
/* dstImage */
/* dstImageLayout */
/* regionCount */
/* pRegions */
    std::stringstream stream_pRegions;
    std::string pRegionsArray = "NULL";
    PointerPairContainer<decltype(pRegions->GetPointer()), decltype(pRegions->GetMetaStructPointer())> pRegionsPair{ pRegions->GetPointer(), pRegions->GetMetaStructPointer(), regionCount };
    std::string pRegionsNames = toStringJoin(pRegionsPair.begin(),
                                             pRegionsPair.end(),
                                             [&](auto pair) { return GenerateStruct_VkImageCopy(stream_pRegions, pair.t1, pair.t2, *this); },
                                             ", ");
    fprintf(file, "\n%s", stream_pRegions.str().c_str());
    if (regionCount == 1) {
        pRegionsArray = "&" + pRegionsNames;
    } else if (regionCount > 1) {
        pRegionsArray = "pRegions_" + std::to_string(this->getNextId());
        fprintf(file, "VkImageCopy %s[] = { %s };\n", pRegionsArray.c_str(), pRegionsNames.c_str());
    }
    fprintf(file,
            "vkCmdCopyImage(%s, %s, %s, %s, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(srcImage).c_str(),
            util::ToString<VkImageLayout>(srcImageLayout).c_str(),
            this->GetHandle(dstImage).c_str(),
            util::ToString<VkImageLayout>(dstImageLayout).c_str(),
            regionCount,
            pRegionsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImage);
}

void VulkanCppConsumer::Process_vkCmdCopyImageToBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* srcImage */
/* srcImageLayout */
/* dstBuffer */
/* regionCount */
/* pRegions */
    std::stringstream stream_pRegions;
    std::string pRegionsArray = "NULL";
    PointerPairContainer<decltype(pRegions->GetPointer()), decltype(pRegions->GetMetaStructPointer())> pRegionsPair{ pRegions->GetPointer(), pRegions->GetMetaStructPointer(), regionCount };
    std::string pRegionsNames = toStringJoin(pRegionsPair.begin(),
                                             pRegionsPair.end(),
                                             [&](auto pair) { return GenerateStruct_VkBufferImageCopy(stream_pRegions, pair.t1, pair.t2, *this); },
                                             ", ");
    fprintf(file, "\n%s", stream_pRegions.str().c_str());
    if (regionCount == 1) {
        pRegionsArray = "&" + pRegionsNames;
    } else if (regionCount > 1) {
        pRegionsArray = "pRegions_" + std::to_string(this->getNextId());
        fprintf(file, "VkBufferImageCopy %s[] = { %s };\n", pRegionsArray.c_str(), pRegionsNames.c_str());
    }
    fprintf(file,
            "vkCmdCopyImageToBuffer(%s, %s, %s, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(srcImage).c_str(),
            util::ToString<VkImageLayout>(srcImageLayout).c_str(),
            this->GetHandle(dstBuffer).c_str(),
            regionCount,
            pRegionsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer);
}

void VulkanCppConsumer::Process_vkCmdCopyQueryPoolResults(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* queryPool */
/* firstQuery */
/* queryCount */
/* dstBuffer */
/* dstOffset */
/* stride */
/* flags */
    fprintf(file,
            "vkCmdCopyQueryPoolResults(%s, %s, %u, %u, %s, %luUL, %luUL, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(queryPool).c_str(),
            firstQuery,
            queryCount,
            this->GetHandle(dstBuffer).c_str(),
            dstOffset,
            stride,
            util::ToString<VkQueryResultFlags>(flags).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults);
}

void VulkanCppConsumer::Process_vkCmdDispatch(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* groupCountX */
/* groupCountY */
/* groupCountZ */
    fprintf(file,
            "vkCmdDispatch(%s, %u, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            groupCountX,
            groupCountY,
            groupCountZ);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDispatch);
}

void VulkanCppConsumer::Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* buffer */
/* offset */
    fprintf(file,
            "vkCmdDispatchIndirect(%s, %s, %luUL);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDispatchIndirect);
}

void VulkanCppConsumer::Process_vkCmdDraw(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* vertexCount */
/* instanceCount */
/* firstVertex */
/* firstInstance */
    fprintf(file,
            "vkCmdDraw(%s, %u, %u, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            vertexCount,
            instanceCount,
            firstVertex,
            firstInstance);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDraw);
}

void VulkanCppConsumer::Process_vkCmdDrawIndexed(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* indexCount */
/* instanceCount */
/* firstIndex */
/* vertexOffset */
/* firstInstance */
    fprintf(file,
            "vkCmdDrawIndexed(%s, %u, %u, %u, %d, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            indexCount,
            instanceCount,
            firstIndex,
            vertexOffset,
            firstInstance);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndexed);
}

void VulkanCppConsumer::Process_vkCmdDrawIndexedIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* buffer */
/* offset */
/* drawCount */
/* stride */
    fprintf(file,
            "vkCmdDrawIndexedIndirect(%s, %s, %luUL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            drawCount,
            stride);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect);
}

void VulkanCppConsumer::Process_vkCmdDrawIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* buffer */
/* offset */
/* drawCount */
/* stride */
    fprintf(file,
            "vkCmdDrawIndirect(%s, %s, %luUL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            drawCount,
            stride);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirect);
}

void VulkanCppConsumer::Process_vkCmdEndQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* queryPool */
/* query */
    fprintf(file,
            "vkCmdEndQuery(%s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(queryPool).c_str(),
            query);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndQuery);
}

void VulkanCppConsumer::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
    fprintf(file,
            "vkCmdEndRenderPass(%s);\n",
            this->GetHandle(commandBuffer).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRenderPass);
}

void VulkanCppConsumer::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* commandBufferCount */
/* pCommandBuffers */
    std::string pCommandBuffersArray = "NULL";
    std::string pCommandBuffersValues = toStringJoin(pCommandBuffers->GetPointer(),
                                                     pCommandBuffers->GetPointer() + commandBufferCount,
                                                     [&](const format::HandleId current) { return this->GetHandle(current); },
                                                     ", ");
    if (commandBufferCount == 1) {
        pCommandBuffersArray = "&" + pCommandBuffersValues;
    } else if (commandBufferCount > 1) {
        pCommandBuffersArray = "pCommandBuffersArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkCommandBuffer %s[] = { %s };\n", pCommandBuffersArray.c_str(), pCommandBuffersValues.c_str());
    }
    fprintf(file,
            "vkCmdExecuteCommands(%s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            commandBufferCount,
            pCommandBuffersArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdExecuteCommands);
}

void VulkanCppConsumer::Process_vkCmdFillBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* dstBuffer */
/* dstOffset */
/* size */
/* data */
    fprintf(file,
            "vkCmdFillBuffer(%s, %s, %luUL, %luUL, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(dstBuffer).c_str(),
            dstOffset,
            size,
            data);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdFillBuffer);
}

void VulkanCppConsumer::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSubpassContents                           contents)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* contents */
    fprintf(file,
            "vkCmdNextSubpass(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkSubpassContents>(contents).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdNextSubpass);
}

void VulkanCppConsumer::Process_vkCmdPipelineBarrier(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    uint32_t                                    memoryBarrierCount,
    StructPointerDecoder<Decoded_VkMemoryBarrier>* pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* srcStageMask */
/* dstStageMask */
/* dependencyFlags */
/* memoryBarrierCount */
/* pMemoryBarriers */
    std::stringstream stream_pMemoryBarriers;
    std::string pMemoryBarriersArray = "NULL";
    PointerPairContainer<decltype(pMemoryBarriers->GetPointer()), decltype(pMemoryBarriers->GetMetaStructPointer())> pMemoryBarriersPair{ pMemoryBarriers->GetPointer(), pMemoryBarriers->GetMetaStructPointer(), memoryBarrierCount };
    std::string pMemoryBarriersNames = toStringJoin(pMemoryBarriersPair.begin(),
                                                    pMemoryBarriersPair.end(),
                                                    [&](auto pair) { return GenerateStruct_VkMemoryBarrier(stream_pMemoryBarriers, pair.t1, pair.t2, *this); },
                                                    ", ");
    fprintf(file, "\n%s", stream_pMemoryBarriers.str().c_str());
    if (memoryBarrierCount == 1) {
        pMemoryBarriersArray = "&" + pMemoryBarriersNames;
    } else if (memoryBarrierCount > 1) {
        pMemoryBarriersArray = "pMemoryBarriers_" + std::to_string(this->getNextId());
        fprintf(file, "VkMemoryBarrier %s[] = { %s };\n", pMemoryBarriersArray.c_str(), pMemoryBarriersNames.c_str());
    }
/* bufferMemoryBarrierCount */
/* pBufferMemoryBarriers */
    std::stringstream stream_pBufferMemoryBarriers;
    std::string pBufferMemoryBarriersArray = "NULL";
    PointerPairContainer<decltype(pBufferMemoryBarriers->GetPointer()), decltype(pBufferMemoryBarriers->GetMetaStructPointer())> pBufferMemoryBarriersPair{ pBufferMemoryBarriers->GetPointer(), pBufferMemoryBarriers->GetMetaStructPointer(), bufferMemoryBarrierCount };
    std::string pBufferMemoryBarriersNames = toStringJoin(pBufferMemoryBarriersPair.begin(),
                                                          pBufferMemoryBarriersPair.end(),
                                                          [&](auto pair) { return GenerateStruct_VkBufferMemoryBarrier(stream_pBufferMemoryBarriers, pair.t1, pair.t2, *this); },
                                                          ", ");
    fprintf(file, "\n%s", stream_pBufferMemoryBarriers.str().c_str());
    if (bufferMemoryBarrierCount == 1) {
        pBufferMemoryBarriersArray = "&" + pBufferMemoryBarriersNames;
    } else if (bufferMemoryBarrierCount > 1) {
        pBufferMemoryBarriersArray = "pBufferMemoryBarriers_" + std::to_string(this->getNextId());
        fprintf(file, "VkBufferMemoryBarrier %s[] = { %s };\n", pBufferMemoryBarriersArray.c_str(), pBufferMemoryBarriersNames.c_str());
    }
/* imageMemoryBarrierCount */
/* pImageMemoryBarriers */
    std::stringstream stream_pImageMemoryBarriers;
    std::string pImageMemoryBarriersArray = "NULL";
    PointerPairContainer<decltype(pImageMemoryBarriers->GetPointer()), decltype(pImageMemoryBarriers->GetMetaStructPointer())> pImageMemoryBarriersPair{ pImageMemoryBarriers->GetPointer(), pImageMemoryBarriers->GetMetaStructPointer(), imageMemoryBarrierCount };
    std::string pImageMemoryBarriersNames = toStringJoin(pImageMemoryBarriersPair.begin(),
                                                         pImageMemoryBarriersPair.end(),
                                                         [&](auto pair) { return GenerateStruct_VkImageMemoryBarrier(stream_pImageMemoryBarriers, pair.t1, pair.t2, *this); },
                                                         ", ");
    fprintf(file, "\n%s", stream_pImageMemoryBarriers.str().c_str());
    if (imageMemoryBarrierCount == 1) {
        pImageMemoryBarriersArray = "&" + pImageMemoryBarriersNames;
    } else if (imageMemoryBarrierCount > 1) {
        pImageMemoryBarriersArray = "pImageMemoryBarriers_" + std::to_string(this->getNextId());
        fprintf(file, "VkImageMemoryBarrier %s[] = { %s };\n", pImageMemoryBarriersArray.c_str(), pImageMemoryBarriersNames.c_str());
    }
    fprintf(file,
            "vkCmdPipelineBarrier(%s, %s, %s, %s, %u, %s, %u, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineStageFlags>(srcStageMask).c_str(),
            util::ToString<VkPipelineStageFlags>(dstStageMask).c_str(),
            util::ToString<VkDependencyFlags>(dependencyFlags).c_str(),
            memoryBarrierCount,
            pMemoryBarriersArray.c_str(),
            bufferMemoryBarrierCount,
            pBufferMemoryBarriersArray.c_str(),
            imageMemoryBarrierCount,
            pImageMemoryBarriersArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPipelineBarrier);
}

void VulkanCppConsumer::Process_vkCmdPushConstants(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    PointerDecoder<uint8_t>*                    pValues)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* layout */
/* stageFlags */
/* offset */
/* size */
/* pValues */
    std::string pValuesArray = "pValues_" + std::to_string(this->getNextId());
    if (size > 0) {
        std::string pValuesValues = toStringJoin(pValues->GetPointer(),
                                                 pValues->GetPointer() + size,
                                                 [&](const auto current) { return std::to_string(current) + ""; },
                                                 ", ");
        fprintf(file, "uint8_t %s[] = { %s };\n", pValuesArray.c_str(), pValuesValues.c_str());
    } else {
        pValuesArray = "NULL";
    }
    fprintf(file,
            "vkCmdPushConstants(%s, %s, %s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(layout).c_str(),
            util::ToString<VkShaderStageFlags>(stageFlags).c_str(),
            offset,
            size,
            pValuesArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPushConstants);
}

void VulkanCppConsumer::Process_vkCmdResetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* event */
/* stageMask */
    fprintf(file,
            "vkCmdResetEvent(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(event).c_str(),
            util::ToString<VkPipelineStageFlags>(stageMask).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResetEvent);
}

void VulkanCppConsumer::Process_vkCmdResetQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* queryPool */
/* firstQuery */
/* queryCount */
    fprintf(file,
            "vkCmdResetQueryPool(%s, %s, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(queryPool).c_str(),
            firstQuery,
            queryCount);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResetQueryPool);
}

void VulkanCppConsumer::Process_vkCmdResolveImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageResolve>* pRegions)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* srcImage */
/* srcImageLayout */
/* dstImage */
/* dstImageLayout */
/* regionCount */
/* pRegions */
    std::stringstream stream_pRegions;
    std::string pRegionsArray = "NULL";
    PointerPairContainer<decltype(pRegions->GetPointer()), decltype(pRegions->GetMetaStructPointer())> pRegionsPair{ pRegions->GetPointer(), pRegions->GetMetaStructPointer(), regionCount };
    std::string pRegionsNames = toStringJoin(pRegionsPair.begin(),
                                             pRegionsPair.end(),
                                             [&](auto pair) { return GenerateStruct_VkImageResolve(stream_pRegions, pair.t1, pair.t2, *this); },
                                             ", ");
    fprintf(file, "\n%s", stream_pRegions.str().c_str());
    if (regionCount == 1) {
        pRegionsArray = "&" + pRegionsNames;
    } else if (regionCount > 1) {
        pRegionsArray = "pRegions_" + std::to_string(this->getNextId());
        fprintf(file, "VkImageResolve %s[] = { %s };\n", pRegionsArray.c_str(), pRegionsNames.c_str());
    }
    fprintf(file,
            "vkCmdResolveImage(%s, %s, %s, %s, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(srcImage).c_str(),
            util::ToString<VkImageLayout>(srcImageLayout).c_str(),
            this->GetHandle(dstImage).c_str(),
            util::ToString<VkImageLayout>(dstImageLayout).c_str(),
            regionCount,
            pRegionsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResolveImage);
}

void VulkanCppConsumer::Process_vkCmdSetBlendConstants(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    PointerDecoder<float>*                      blendConstants)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* blendConstants */
    std::string blendConstantsArray = "blendConstants_" + std::to_string(this->getNextId());
    if (4 > 0) {
        std::string blendConstantsValues = toStringJoin(blendConstants->GetPointer(),
                                                        blendConstants->GetPointer() + 4,
                                                        [&](const auto current) { return std::to_string(current) + ""; },
                                                        ", ");
        fprintf(file, "float %s[] = { %s };\n", blendConstantsArray.c_str(), blendConstantsValues.c_str());
    } else {
        blendConstantsArray = "NULL";
    }
    fprintf(file,
            "vkCmdSetBlendConstants(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            blendConstantsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetBlendConstants);
}

void VulkanCppConsumer::Process_vkCmdSetDepthBias(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* depthBiasConstantFactor */
/* depthBiasClamp */
/* depthBiasSlopeFactor */
    fprintf(file,
            "vkCmdSetDepthBias(%s, %f, %f, %f);\n",
            this->GetHandle(commandBuffer).c_str(),
            depthBiasConstantFactor,
            depthBiasClamp,
            depthBiasSlopeFactor);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBias);
}

void VulkanCppConsumer::Process_vkCmdSetDepthBounds(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* minDepthBounds */
/* maxDepthBounds */
    fprintf(file,
            "vkCmdSetDepthBounds(%s, %f, %f);\n",
            this->GetHandle(commandBuffer).c_str(),
            minDepthBounds,
            maxDepthBounds);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBounds);
}

void VulkanCppConsumer::Process_vkCmdSetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* event */
/* stageMask */
    fprintf(file,
            "vkCmdSetEvent(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(event).c_str(),
            util::ToString<VkPipelineStageFlags>(stageMask).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetEvent);
}

void VulkanCppConsumer::Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       lineWidth)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* lineWidth */
    fprintf(file,
            "vkCmdSetLineWidth(%s, %f);\n",
            this->GetHandle(commandBuffer).c_str(),
            lineWidth);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLineWidth);
}

void VulkanCppConsumer::Process_vkCmdSetScissor(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* firstScissor */
/* scissorCount */
/* pScissors */
    std::stringstream stream_pScissors;
    std::string pScissorsArray = "NULL";
    PointerPairContainer<decltype(pScissors->GetPointer()), decltype(pScissors->GetMetaStructPointer())> pScissorsPair{ pScissors->GetPointer(), pScissors->GetMetaStructPointer(), scissorCount };
    std::string pScissorsNames = toStringJoin(pScissorsPair.begin(),
                                              pScissorsPair.end(),
                                              [&](auto pair) { return GenerateStruct_VkRect2D(stream_pScissors, pair.t1, pair.t2, *this); },
                                              ", ");
    fprintf(file, "\n%s", stream_pScissors.str().c_str());
    if (scissorCount == 1) {
        pScissorsArray = "&" + pScissorsNames;
    } else if (scissorCount > 1) {
        pScissorsArray = "pScissors_" + std::to_string(this->getNextId());
        fprintf(file, "VkRect2D %s[] = { %s };\n", pScissorsArray.c_str(), pScissorsNames.c_str());
    }
    fprintf(file,
            "vkCmdSetScissor(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstScissor,
            scissorCount,
            pScissorsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetScissor);
}

void VulkanCppConsumer::Process_vkCmdSetStencilCompareMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* faceMask */
/* compareMask */
    fprintf(file,
            "vkCmdSetStencilCompareMask(%s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkStencilFaceFlags>(faceMask).c_str(),
            compareMask);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask);
}

void VulkanCppConsumer::Process_vkCmdSetStencilReference(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* faceMask */
/* reference */
    fprintf(file,
            "vkCmdSetStencilReference(%s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkStencilFaceFlags>(faceMask).c_str(),
            reference);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilReference);
}

void VulkanCppConsumer::Process_vkCmdSetStencilWriteMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* faceMask */
/* writeMask */
    fprintf(file,
            "vkCmdSetStencilWriteMask(%s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkStencilFaceFlags>(faceMask).c_str(),
            writeMask);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask);
}

void VulkanCppConsumer::Process_vkCmdSetViewport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* firstViewport */
/* viewportCount */
/* pViewports */
    std::stringstream stream_pViewports;
    std::string pViewportsArray = "NULL";
    PointerPairContainer<decltype(pViewports->GetPointer()), decltype(pViewports->GetMetaStructPointer())> pViewportsPair{ pViewports->GetPointer(), pViewports->GetMetaStructPointer(), viewportCount };
    std::string pViewportsNames = toStringJoin(pViewportsPair.begin(),
                                               pViewportsPair.end(),
                                               [&](auto pair) { return GenerateStruct_VkViewport(stream_pViewports, pair.t1, pair.t2, *this); },
                                               ", ");
    fprintf(file, "\n%s", stream_pViewports.str().c_str());
    if (viewportCount == 1) {
        pViewportsArray = "&" + pViewportsNames;
    } else if (viewportCount > 1) {
        pViewportsArray = "pViewports_" + std::to_string(this->getNextId());
        fprintf(file, "VkViewport %s[] = { %s };\n", pViewportsArray.c_str(), pViewportsNames.c_str());
    }
    fprintf(file,
            "vkCmdSetViewport(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstViewport,
            viewportCount,
            pViewportsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewport);
}

void VulkanCppConsumer::Process_vkCmdUpdateBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* dstBuffer */
/* dstOffset */
/* dataSize */
/* pData */
    std::string pDataArray = "pData_" + std::to_string(this->getNextId());
    if (dataSize > 0) {
        std::string pDataValues = toStringJoin(pData->GetPointer(),
                                               pData->GetPointer() + dataSize,
                                               [&](const auto current) { return std::to_string(current) + ""; },
                                               ", ");
        fprintf(file, "uint8_t %s[] = { %s };\n", pDataArray.c_str(), pDataValues.c_str());
    } else {
        pDataArray = "NULL";
    }
    fprintf(file,
            "vkCmdUpdateBuffer(%s, %s, %luUL, %luUL, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(dstBuffer).c_str(),
            dstOffset,
            dataSize,
            pDataArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdUpdateBuffer);
}

void VulkanCppConsumer::Process_vkCmdWaitEvents(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    uint32_t                                    memoryBarrierCount,
    StructPointerDecoder<Decoded_VkMemoryBarrier>* pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* eventCount */
/* pEvents */
    std::string pEventsArray = "NULL";
    std::string pEventsValues = toStringJoin(pEvents->GetPointer(),
                                             pEvents->GetPointer() + eventCount,
                                             [&](const format::HandleId current) { return this->GetHandle(current); },
                                             ", ");
    if (eventCount == 1) {
        pEventsArray = "&" + pEventsValues;
    } else if (eventCount > 1) {
        pEventsArray = "pEventsArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkEvent %s[] = { %s };\n", pEventsArray.c_str(), pEventsValues.c_str());
    }
/* srcStageMask */
/* dstStageMask */
/* memoryBarrierCount */
/* pMemoryBarriers */
    std::stringstream stream_pMemoryBarriers;
    std::string pMemoryBarriersArray = "NULL";
    PointerPairContainer<decltype(pMemoryBarriers->GetPointer()), decltype(pMemoryBarriers->GetMetaStructPointer())> pMemoryBarriersPair{ pMemoryBarriers->GetPointer(), pMemoryBarriers->GetMetaStructPointer(), memoryBarrierCount };
    std::string pMemoryBarriersNames = toStringJoin(pMemoryBarriersPair.begin(),
                                                    pMemoryBarriersPair.end(),
                                                    [&](auto pair) { return GenerateStruct_VkMemoryBarrier(stream_pMemoryBarriers, pair.t1, pair.t2, *this); },
                                                    ", ");
    fprintf(file, "\n%s", stream_pMemoryBarriers.str().c_str());
    if (memoryBarrierCount == 1) {
        pMemoryBarriersArray = "&" + pMemoryBarriersNames;
    } else if (memoryBarrierCount > 1) {
        pMemoryBarriersArray = "pMemoryBarriers_" + std::to_string(this->getNextId());
        fprintf(file, "VkMemoryBarrier %s[] = { %s };\n", pMemoryBarriersArray.c_str(), pMemoryBarriersNames.c_str());
    }
/* bufferMemoryBarrierCount */
/* pBufferMemoryBarriers */
    std::stringstream stream_pBufferMemoryBarriers;
    std::string pBufferMemoryBarriersArray = "NULL";
    PointerPairContainer<decltype(pBufferMemoryBarriers->GetPointer()), decltype(pBufferMemoryBarriers->GetMetaStructPointer())> pBufferMemoryBarriersPair{ pBufferMemoryBarriers->GetPointer(), pBufferMemoryBarriers->GetMetaStructPointer(), bufferMemoryBarrierCount };
    std::string pBufferMemoryBarriersNames = toStringJoin(pBufferMemoryBarriersPair.begin(),
                                                          pBufferMemoryBarriersPair.end(),
                                                          [&](auto pair) { return GenerateStruct_VkBufferMemoryBarrier(stream_pBufferMemoryBarriers, pair.t1, pair.t2, *this); },
                                                          ", ");
    fprintf(file, "\n%s", stream_pBufferMemoryBarriers.str().c_str());
    if (bufferMemoryBarrierCount == 1) {
        pBufferMemoryBarriersArray = "&" + pBufferMemoryBarriersNames;
    } else if (bufferMemoryBarrierCount > 1) {
        pBufferMemoryBarriersArray = "pBufferMemoryBarriers_" + std::to_string(this->getNextId());
        fprintf(file, "VkBufferMemoryBarrier %s[] = { %s };\n", pBufferMemoryBarriersArray.c_str(), pBufferMemoryBarriersNames.c_str());
    }
/* imageMemoryBarrierCount */
/* pImageMemoryBarriers */
    std::stringstream stream_pImageMemoryBarriers;
    std::string pImageMemoryBarriersArray = "NULL";
    PointerPairContainer<decltype(pImageMemoryBarriers->GetPointer()), decltype(pImageMemoryBarriers->GetMetaStructPointer())> pImageMemoryBarriersPair{ pImageMemoryBarriers->GetPointer(), pImageMemoryBarriers->GetMetaStructPointer(), imageMemoryBarrierCount };
    std::string pImageMemoryBarriersNames = toStringJoin(pImageMemoryBarriersPair.begin(),
                                                         pImageMemoryBarriersPair.end(),
                                                         [&](auto pair) { return GenerateStruct_VkImageMemoryBarrier(stream_pImageMemoryBarriers, pair.t1, pair.t2, *this); },
                                                         ", ");
    fprintf(file, "\n%s", stream_pImageMemoryBarriers.str().c_str());
    if (imageMemoryBarrierCount == 1) {
        pImageMemoryBarriersArray = "&" + pImageMemoryBarriersNames;
    } else if (imageMemoryBarrierCount > 1) {
        pImageMemoryBarriersArray = "pImageMemoryBarriers_" + std::to_string(this->getNextId());
        fprintf(file, "VkImageMemoryBarrier %s[] = { %s };\n", pImageMemoryBarriersArray.c_str(), pImageMemoryBarriersNames.c_str());
    }
    fprintf(file,
            "vkCmdWaitEvents(%s, %u, %s, %s, %s, %u, %s, %u, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            eventCount,
            pEventsArray.c_str(),
            util::ToString<VkPipelineStageFlags>(srcStageMask).c_str(),
            util::ToString<VkPipelineStageFlags>(dstStageMask).c_str(),
            memoryBarrierCount,
            pMemoryBarriersArray.c_str(),
            bufferMemoryBarrierCount,
            pBufferMemoryBarriersArray.c_str(),
            imageMemoryBarrierCount,
            pImageMemoryBarriersArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWaitEvents);
}

void VulkanCppConsumer::Process_vkCmdWriteTimestamp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pipelineStage */
/* queryPool */
/* query */
    fprintf(file,
            "vkCmdWriteTimestamp(%s, %s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineStageFlagBits>(pipelineStage).c_str(),
            this->GetHandle(queryPool).c_str(),
            query);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteTimestamp);
}

void VulkanCppConsumer::Process_vkCreateBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBuffer>*             pBuffer)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkBufferCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pBuffer */
    std::string pBufferName = "pBuffer_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_BUFFER));
    AddKnownVariables("VkBuffer", pBufferName, pBuffer->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pBufferName,
                         pBuffer->GetPointer());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreateBuffer(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pBufferName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateBuffer);
}

void VulkanCppConsumer::Process_vkCreateBufferView(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBufferView>*         pView)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkBufferViewCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pView */
    std::string pViewName = "pView_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_BUFFER_VIEW));
    AddKnownVariables("VkBufferView", pViewName, pView->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pViewName,
                         pView->GetPointer());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreateBufferView(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pViewName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateBufferView);
}

void VulkanCppConsumer::Process_vkCreateCommandPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkCommandPool>*        pCommandPool)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkCommandPoolCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pCommandPool */
    std::string pCommandPoolName = "pCommandPool_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_COMMAND_POOL));
    AddKnownVariables("VkCommandPool", pCommandPoolName, pCommandPool->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pCommandPoolName,
                         pCommandPool->GetPointer());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreateCommandPool(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pCommandPoolName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateCommandPool);
}

void VulkanCppConsumer::Process_vkCreateComputePipelines(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pipelineCache */
/* createInfoCount */
/* pCreateInfos */
    std::stringstream stream_pCreateInfos;
    std::string pCreateInfosArray = "NULL";
    PointerPairContainer<decltype(pCreateInfos->GetPointer()), decltype(pCreateInfos->GetMetaStructPointer())> pCreateInfosPair{ pCreateInfos->GetPointer(), pCreateInfos->GetMetaStructPointer(), createInfoCount };
    std::string pCreateInfosNames = toStringJoin(pCreateInfosPair.begin(),
                                                 pCreateInfosPair.end(),
                                                 [&](auto pair) { return GenerateStruct_VkComputePipelineCreateInfo(stream_pCreateInfos, pair.t1, pair.t2, *this); },
                                                 ", ");
    fprintf(file, "\n%s", stream_pCreateInfos.str().c_str());
    if (createInfoCount == 1) {
        pCreateInfosArray = "&" + pCreateInfosNames;
    } else if (createInfoCount > 1) {
        pCreateInfosArray = "pCreateInfos_" + std::to_string(this->getNextId());
        fprintf(file, "VkComputePipelineCreateInfo %s[] = { %s };\n", pCreateInfosArray.c_str(), pCreateInfosNames.c_str());
    }
/* pAllocator */
/* pPipelines */
    std::string pPipelinesName = "pPipelines_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_PIPELINE));
    AddKnownVariables("VkPipeline", pPipelinesName, pPipelines->GetPointer(), createInfoCount);
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pPipelinesName,
                         pPipelines->GetPointer(), createInfoCount);
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreateComputePipelines(%s, %s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipelineCache).c_str(),
            createInfoCount,
            pCreateInfosArray.c_str(),
            "nullptr",
            pPipelinesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateComputePipelines);
}

void VulkanCppConsumer::Process_vkCreateDescriptorPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorPool>*     pDescriptorPool)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkDescriptorPoolCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pDescriptorPool */
    std::string pDescriptorPoolName = "pDescriptorPool_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_DESCRIPTOR_POOL));
    AddKnownVariables("VkDescriptorPool", pDescriptorPoolName, pDescriptorPool->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pDescriptorPoolName,
                         pDescriptorPool->GetPointer());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreateDescriptorPool(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pDescriptorPoolName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDescriptorPool);
}

void VulkanCppConsumer::Process_vkCreateDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkDescriptorSetLayoutCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pSetLayout */
    std::string pSetLayoutName = "pSetLayout_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT));
    AddKnownVariables("VkDescriptorSetLayout", pSetLayoutName, pSetLayout->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pSetLayoutName,
                         pSetLayout->GetPointer());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreateDescriptorSetLayout(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pSetLayoutName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout);
}

void VulkanCppConsumer::Process_vkCreateDevice(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDeviceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDevice>*             pDevice)
{
    Intercept_vkCreateDevice(returnValue, physicalDevice, pCreateInfo, pAllocator, pDevice);
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkDeviceCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pDevice */
    std::string pDeviceName = "pDevice_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_DEVICE));
    AddKnownVariables("VkDevice", pDeviceName, pDevice->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pDeviceName,
                         pDevice->GetPointer());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreateDevice(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pDeviceName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDevice);
}

void VulkanCppConsumer::Process_vkCreateEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkEventCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkEvent>*              pEvent)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkEventCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pEvent */
    std::string pEventName = "pEvent_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_EVENT));
    AddKnownVariables("VkEvent", pEventName, pEvent->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pEventName,
                         pEvent->GetPointer());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreateEvent(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pEventName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateEvent);
}

void VulkanCppConsumer::Process_vkCreateFence(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkFenceCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pFence */
    std::string pFenceName = "pFence_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_FENCE));
    AddKnownVariables("VkFence", pFenceName, pFence->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pFenceName,
                         pFence->GetPointer());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreateFence(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pFenceName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateFence);
}

void VulkanCppConsumer::Process_vkCreateFramebuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFramebuffer>*        pFramebuffer)
{
    Intercept_vkCreateFramebuffer(returnValue, device, pCreateInfo, pAllocator, pFramebuffer);
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkFramebufferCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pFramebuffer */
    std::string pFramebufferName = "pFramebuffer_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_FRAMEBUFFER));
    AddKnownVariables("VkFramebuffer", pFramebufferName, pFramebuffer->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pFramebufferName,
                         pFramebuffer->GetPointer());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreateFramebuffer(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pFramebufferName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateFramebuffer);
}

void VulkanCppConsumer::Process_vkCreateGraphicsPipelines(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pipelineCache */
/* createInfoCount */
/* pCreateInfos */
    std::stringstream stream_pCreateInfos;
    std::string pCreateInfosArray = "NULL";
    PointerPairContainer<decltype(pCreateInfos->GetPointer()), decltype(pCreateInfos->GetMetaStructPointer())> pCreateInfosPair{ pCreateInfos->GetPointer(), pCreateInfos->GetMetaStructPointer(), createInfoCount };
    std::string pCreateInfosNames = toStringJoin(pCreateInfosPair.begin(),
                                                 pCreateInfosPair.end(),
                                                 [&](auto pair) { return GenerateStruct_VkGraphicsPipelineCreateInfo(stream_pCreateInfos, pair.t1, pair.t2, *this); },
                                                 ", ");
    fprintf(file, "\n%s", stream_pCreateInfos.str().c_str());
    if (createInfoCount == 1) {
        pCreateInfosArray = "&" + pCreateInfosNames;
    } else if (createInfoCount > 1) {
        pCreateInfosArray = "pCreateInfos_" + std::to_string(this->getNextId());
        fprintf(file, "VkGraphicsPipelineCreateInfo %s[] = { %s };\n", pCreateInfosArray.c_str(), pCreateInfosNames.c_str());
    }
/* pAllocator */
/* pPipelines */
    std::string pPipelinesName = "pPipelines_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_PIPELINE));
    AddKnownVariables("VkPipeline", pPipelinesName, pPipelines->GetPointer(), createInfoCount);
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pPipelinesName,
                         pPipelines->GetPointer(), createInfoCount);
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreateGraphicsPipelines(%s, %s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipelineCache).c_str(),
            createInfoCount,
            pCreateInfosArray.c_str(),
            "nullptr",
            pPipelinesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateGraphicsPipelines);
}

void VulkanCppConsumer::Process_vkCreateImage(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImage>*              pImage)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkImageCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pImage */
    std::string pImageName = "pImage_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_IMAGE));
    AddKnownVariables("VkImage", pImageName, pImage->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pImageName,
                         pImage->GetPointer());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreateImage(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pImageName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateImage);
}

void VulkanCppConsumer::Process_vkCreateImageView(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImageView>*          pView)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkImageViewCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pView */
    std::string pViewName = "pView_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_IMAGE_VIEW));
    AddKnownVariables("VkImageView", pViewName, pView->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pViewName,
                         pView->GetPointer());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreateImageView(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pViewName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateImageView);
}

void VulkanCppConsumer::Process_vkCreateInstance(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkInstance>*           pInstance)
{
    Generate_vkCreateInstance(returnValue, pCreateInfo, pAllocator, pInstance);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateInstance);
}

void VulkanCppConsumer::Process_vkCreatePipelineCache(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipelineCache>*      pPipelineCache)
{
    Generate_vkCreatePipelineCache(returnValue, device, pCreateInfo, pAllocator, pPipelineCache);
    Post_APICall(format::ApiCallId::ApiCall_vkCreatePipelineCache);
}

void VulkanCppConsumer::Process_vkCreatePipelineLayout(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipelineLayout>*     pPipelineLayout)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkPipelineLayoutCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pPipelineLayout */
    std::string pPipelineLayoutName = "pPipelineLayout_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_PIPELINE_LAYOUT));
    AddKnownVariables("VkPipelineLayout", pPipelineLayoutName, pPipelineLayout->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pPipelineLayoutName,
                         pPipelineLayout->GetPointer());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreatePipelineLayout(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pPipelineLayoutName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreatePipelineLayout);
}

void VulkanCppConsumer::Process_vkCreateQueryPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkQueryPool>*          pQueryPool)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkQueryPoolCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pQueryPool */
    std::string pQueryPoolName = "pQueryPool_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_QUERY_POOL));
    AddKnownVariables("VkQueryPool", pQueryPoolName, pQueryPool->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pQueryPoolName,
                         pQueryPool->GetPointer());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreateQueryPool(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pQueryPoolName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateQueryPool);
}

void VulkanCppConsumer::Process_vkCreateRenderPass(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkRenderPassCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pRenderPass */
    std::string pRenderPassName = "pRenderPass_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_RENDER_PASS));
    AddKnownVariables("VkRenderPass", pRenderPassName, pRenderPass->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pRenderPassName,
                         pRenderPass->GetPointer());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreateRenderPass(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pRenderPassName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateRenderPass);
}

void VulkanCppConsumer::Process_vkCreateSampler(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSampler>*            pSampler)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkSamplerCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pSampler */
    std::string pSamplerName = "pSampler_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_SAMPLER));
    AddKnownVariables("VkSampler", pSamplerName, pSampler->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pSamplerName,
                         pSampler->GetPointer());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreateSampler(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pSamplerName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateSampler);
}

void VulkanCppConsumer::Process_vkCreateSemaphore(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSemaphore>*          pSemaphore)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkSemaphoreCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pSemaphore */
    std::string pSemaphoreName = "pSemaphore_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_SEMAPHORE));
    AddKnownVariables("VkSemaphore", pSemaphoreName, pSemaphore->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pSemaphoreName,
                         pSemaphore->GetPointer());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreateSemaphore(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pSemaphoreName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateSemaphore);
}

void VulkanCppConsumer::Process_vkCreateShaderModule(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkShaderModule>*       pShaderModule)
{
    Generate_vkCreateShaderModule(returnValue, device, pCreateInfo, pAllocator, pShaderModule);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateShaderModule);
}

void VulkanCppConsumer::Process_vkDestroyBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* buffer */
/* pAllocator */
    fprintf(file,
            "vkDestroyBuffer(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(buffer).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyBuffer);
}

void VulkanCppConsumer::Process_vkDestroyBufferView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            bufferView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* bufferView */
/* pAllocator */
    fprintf(file,
            "vkDestroyBufferView(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(bufferView).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyBufferView);
}

void VulkanCppConsumer::Process_vkDestroyCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* commandPool */
/* pAllocator */
    fprintf(file,
            "vkDestroyCommandPool(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(commandPool).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyCommandPool);
}

void VulkanCppConsumer::Process_vkDestroyDescriptorPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* descriptorPool */
/* pAllocator */
    fprintf(file,
            "vkDestroyDescriptorPool(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(descriptorPool).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDescriptorPool);
}

void VulkanCppConsumer::Process_vkDestroyDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSetLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* descriptorSetLayout */
/* pAllocator */
    fprintf(file,
            "vkDestroyDescriptorSetLayout(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(descriptorSetLayout).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout);
}

void VulkanCppConsumer::Process_vkDestroyDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pAllocator */
    fprintf(file,
            "vkDestroyDevice(%s, %s);\n",
            this->GetHandle(device).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDevice);
}

void VulkanCppConsumer::Process_vkDestroyEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* event */
/* pAllocator */
    fprintf(file,
            "vkDestroyEvent(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(event).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyEvent);
}

void VulkanCppConsumer::Process_vkDestroyFence(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            fence,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* fence */
/* pAllocator */
    fprintf(file,
            "vkDestroyFence(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(fence).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyFence);
}

void VulkanCppConsumer::Process_vkDestroyFramebuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* framebuffer */
/* pAllocator */
    fprintf(file,
            "vkDestroyFramebuffer(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(framebuffer).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyFramebuffer);
}

void VulkanCppConsumer::Process_vkDestroyImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* image */
/* pAllocator */
    fprintf(file,
            "vkDestroyImage(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(image).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyImage);
}

void VulkanCppConsumer::Process_vkDestroyImageView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* imageView */
/* pAllocator */
    fprintf(file,
            "vkDestroyImageView(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(imageView).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyImageView);
}

void VulkanCppConsumer::Process_vkDestroyInstance(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* instance */
/* pAllocator */
    fprintf(file,
            "vkDestroyInstance(%s, %s);\n",
            this->GetHandle(instance).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyInstance);
}

void VulkanCppConsumer::Process_vkDestroyPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pipeline */
/* pAllocator */
    fprintf(file,
            "vkDestroyPipeline(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipeline).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPipeline);
}

void VulkanCppConsumer::Process_vkDestroyPipelineCache(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pipelineCache */
/* pAllocator */
    fprintf(file,
            "vkDestroyPipelineCache(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipelineCache).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPipelineCache);
}

void VulkanCppConsumer::Process_vkDestroyPipelineLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pipelineLayout */
/* pAllocator */
    fprintf(file,
            "vkDestroyPipelineLayout(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipelineLayout).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPipelineLayout);
}

void VulkanCppConsumer::Process_vkDestroyQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* queryPool */
/* pAllocator */
    fprintf(file,
            "vkDestroyQueryPool(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(queryPool).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyQueryPool);
}

void VulkanCppConsumer::Process_vkDestroyRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* renderPass */
/* pAllocator */
    fprintf(file,
            "vkDestroyRenderPass(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(renderPass).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyRenderPass);
}

void VulkanCppConsumer::Process_vkDestroySampler(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            sampler,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* sampler */
/* pAllocator */
    fprintf(file,
            "vkDestroySampler(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(sampler).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySampler);
}

void VulkanCppConsumer::Process_vkDestroySemaphore(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* semaphore */
/* pAllocator */
    fprintf(file,
            "vkDestroySemaphore(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(semaphore).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySemaphore);
}

void VulkanCppConsumer::Process_vkDestroyShaderModule(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* shaderModule */
/* pAllocator */
    fprintf(file,
            "vkDestroyShaderModule(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(shaderModule).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyShaderModule);
}

void VulkanCppConsumer::Process_vkDeviceWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
    fprintf(file,
            "VK_CALL_CHECK(vkDeviceWaitIdle(%s), %s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDeviceWaitIdle);
}

void VulkanCppConsumer::Process_vkEndCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
    fprintf(file,
            "VK_CALL_CHECK(vkEndCommandBuffer(%s), %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkEndCommandBuffer);
}

void VulkanCppConsumer::Process_vkEnumeratePhysicalDevices(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceCount,
    HandlePointerDecoder<VkPhysicalDevice>*     pPhysicalDevices)
{
    Generate_vkEnumeratePhysicalDevices(returnValue, instance, pPhysicalDeviceCount, pPhysicalDevices);
    Post_APICall(format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices);
}

void VulkanCppConsumer::Process_vkFlushMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* memoryRangeCount */
/* pMemoryRanges */
    std::stringstream stream_pMemoryRanges;
    std::string pMemoryRangesArray = "NULL";
    PointerPairContainer<decltype(pMemoryRanges->GetPointer()), decltype(pMemoryRanges->GetMetaStructPointer())> pMemoryRangesPair{ pMemoryRanges->GetPointer(), pMemoryRanges->GetMetaStructPointer(), memoryRangeCount };
    std::string pMemoryRangesNames = toStringJoin(pMemoryRangesPair.begin(),
                                                  pMemoryRangesPair.end(),
                                                  [&](auto pair) { return GenerateStruct_VkMappedMemoryRange(stream_pMemoryRanges, pair.t1, pair.t2, *this); },
                                                  ", ");
    fprintf(file, "\n%s", stream_pMemoryRanges.str().c_str());
    if (memoryRangeCount == 1) {
        pMemoryRangesArray = "&" + pMemoryRangesNames;
    } else if (memoryRangeCount > 1) {
        pMemoryRangesArray = "pMemoryRanges_" + std::to_string(this->getNextId());
        fprintf(file, "VkMappedMemoryRange %s[] = { %s };\n", pMemoryRangesArray.c_str(), pMemoryRangesNames.c_str());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkFlushMappedMemoryRanges(%s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            memoryRangeCount,
            pMemoryRangesArray.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges);
}

void VulkanCppConsumer::Process_vkFreeCommandBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* commandPool */
/* commandBufferCount */
/* pCommandBuffers */
    std::string pCommandBuffersArray = "NULL";
    std::string pCommandBuffersValues = toStringJoin(pCommandBuffers->GetPointer(),
                                                     pCommandBuffers->GetPointer() + commandBufferCount,
                                                     [&](const format::HandleId current) { return this->GetHandle(current); },
                                                     ", ");
    if (commandBufferCount == 1) {
        pCommandBuffersArray = "&" + pCommandBuffersValues;
    } else if (commandBufferCount > 1) {
        pCommandBuffersArray = "pCommandBuffersArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkCommandBuffer %s[] = { %s };\n", pCommandBuffersArray.c_str(), pCommandBuffersValues.c_str());
    }
    fprintf(file,
            "vkFreeCommandBuffers(%s, %s, %u, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(commandPool).c_str(),
            commandBufferCount,
            pCommandBuffersArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkFreeCommandBuffers);
}

void VulkanCppConsumer::Process_vkFreeDescriptorSets(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* descriptorPool */
/* descriptorSetCount */
/* pDescriptorSets */
    std::string pDescriptorSetsArray = "NULL";
    std::string pDescriptorSetsValues = toStringJoin(pDescriptorSets->GetPointer(),
                                                     pDescriptorSets->GetPointer() + descriptorSetCount,
                                                     [&](const format::HandleId current) { return this->GetHandle(current); },
                                                     ", ");
    if (descriptorSetCount == 1) {
        pDescriptorSetsArray = "&" + pDescriptorSetsValues;
    } else if (descriptorSetCount > 1) {
        pDescriptorSetsArray = "pDescriptorSetsArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkDescriptorSet %s[] = { %s };\n", pDescriptorSetsArray.c_str(), pDescriptorSetsValues.c_str());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkFreeDescriptorSets(%s, %s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(descriptorPool).c_str(),
            descriptorSetCount,
            pDescriptorSetsArray.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkFreeDescriptorSets);
}

void VulkanCppConsumer::Process_vkFreeMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* memory */
/* pAllocator */
    fprintf(file,
            "vkFreeMemory(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(memory).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkFreeMemory);
}

void VulkanCppConsumer::Process_vkGetBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    Generate_vkGetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements);
}

void VulkanCppConsumer::Process_vkGetDeviceMemoryCommitment(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    PointerDecoder<VkDeviceSize>*               pCommittedMemoryInBytes)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* memory */
/* pCommittedMemoryInBytes */
    std::string pCommittedMemoryInBytesName = "pCommittedMemoryInBytes_" + std::to_string(this->getNextId());
    fprintf(file, "VkDeviceSize %s;\n", pCommittedMemoryInBytesName.c_str());
    fprintf(file,
            "vkGetDeviceMemoryCommitment(%s, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(memory).c_str(),
            pCommittedMemoryInBytesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment);
}

void VulkanCppConsumer::Process_vkGetDeviceQueue(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* queueFamilyIndex */
/* queueIndex */
/* pQueue */
    std::string pQueueName = "pQueue_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_QUEUE));
    AddKnownVariables("VkQueue", pQueueName, pQueue->GetPointer());
    this->AddHandles(pQueueName,
                     pQueue->GetPointer());
    fprintf(file,
            "vkGetDeviceQueue(%s, %u, %u, &%s);\n",
            this->GetHandle(device).c_str(),
            queueFamilyIndex,
            queueIndex,
            pQueueName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceQueue);
}

void VulkanCppConsumer::Process_vkGetEventStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* event */
    fprintf(file,
            "VK_CALL_CHECK(vkGetEventStatus(%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(event).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetEventStatus);
}

void VulkanCppConsumer::Process_vkGetFenceStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            fence)
{
    Generate_vkGetFenceStatus(returnValue, device, fence);
    Post_APICall(format::ApiCallId::ApiCall_vkGetFenceStatus);
}

void VulkanCppConsumer::Process_vkGetImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    Generate_vkGetImageMemoryRequirements(device, image, pMemoryRequirements);
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements);
}

void VulkanCppConsumer::Process_vkGetImageSparseMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements)
{
    Generate_vkGetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements);
}

void VulkanCppConsumer::Process_vkGetImageSubresourceLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout>* pLayout)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* image */
/* pSubresource */
    std::stringstream stream_pSubresource;
    std::string pSubresourceStruct = GenerateStruct_VkImageSubresource(stream_pSubresource,
                                                                    pSubresource->GetPointer(),
                                                                    pSubresource->GetMetaStructPointer(),
                                                                    *this);
    fprintf(file, "\n%s", stream_pSubresource.str().c_str());
/* pLayout */
    std::string pLayoutName = "pLayout_" + std::to_string(this->getNextId());
    fprintf(file, "VkSubresourceLayout %s;\n", pLayoutName.c_str());
    fprintf(file,
            "vkGetImageSubresourceLayout(%s, %s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(image).c_str(),
            pSubresourceStruct.c_str(),
            pLayoutName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSubresourceLayout);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pFeatures */
    std::string pFeaturesName = "pFeatures_" + std::to_string(this->getNextId());
    fprintf(file, "VkPhysicalDeviceFeatures %s;\n", pFeaturesName.c_str());
    fprintf(file,
            "vkGetPhysicalDeviceFeatures(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pFeaturesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceFormatProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* format */
/* pFormatProperties */
    std::string pFormatPropertiesName = "pFormatProperties_" + std::to_string(this->getNextId());
    fprintf(file, "VkFormatProperties %s;\n", pFormatPropertiesName.c_str());
    fprintf(file,
            "vkGetPhysicalDeviceFormatProperties(%s, %s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            util::ToString<VkFormat>(format).c_str(),
            pFormatPropertiesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceImageFormatProperties(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    StructPointerDecoder<Decoded_VkImageFormatProperties>* pImageFormatProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* format */
/* type */
/* tiling */
/* usage */
/* flags */
/* pImageFormatProperties */
    std::string pImageFormatPropertiesName = "pImageFormatProperties_" + std::to_string(this->getNextId());
    fprintf(file, "VkImageFormatProperties %s;\n", pImageFormatPropertiesName.c_str());
    fprintf(file,
            "vkGetPhysicalDeviceImageFormatProperties(%s, %s, %s, %s, %s, %s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            util::ToString<VkFormat>(format).c_str(),
            util::ToString<VkImageType>(type).c_str(),
            util::ToString<VkImageTiling>(tiling).c_str(),
            util::ToString<VkImageUsageFlags>(usage).c_str(),
            util::ToString<VkImageCreateFlags>(flags).c_str(),
            pImageFormatPropertiesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pMemoryProperties */
    std::string pMemoryPropertiesName = "pMemoryProperties_" + std::to_string(this->getNextId());
    fprintf(file, "VkPhysicalDeviceMemoryProperties %s;\n", pMemoryPropertiesName.c_str());
    fprintf(file,
            "vkGetPhysicalDeviceMemoryProperties(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pMemoryPropertiesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pProperties */
    std::string pPropertiesName = "pProperties_" + std::to_string(this->getNextId());
    fprintf(file, "VkPhysicalDeviceProperties %s;\n", pPropertiesName.c_str());
    fprintf(file,
            "vkGetPhysicalDeviceProperties(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pPropertiesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties)
{
    Generate_vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkSampleCountFlagBits                       samples,
    VkImageUsageFlags                           usage,
    VkImageTiling                               tiling,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* format */
/* type */
/* samples */
/* usage */
/* tiling */
/* pPropertyCount */
    std::string pPropertyCountName = "pPropertyCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pPropertyCountName.c_str());
/* pProperties */
    std::string pPropertiesName = "pProperties_" + std::to_string(this->getNextId());
    const uint32_t* in_pPropertyCount = pPropertyCount->GetPointer();
    fprintf(file, "VkSparseImageFormatProperties %s[%d];\n", pPropertiesName.c_str(), *in_pPropertyCount);
    fprintf(file,
            "vkGetPhysicalDeviceSparseImageFormatProperties(%s, %s, %s, %s, %s, %s, &%s, %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            util::ToString<VkFormat>(format).c_str(),
            util::ToString<VkImageType>(type).c_str(),
            util::ToString<VkSampleCountFlagBits>(samples).c_str(),
            util::ToString<VkImageUsageFlags>(usage).c_str(),
            util::ToString<VkImageTiling>(tiling).c_str(),
            pPropertyCountName.c_str(),
            pPropertiesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties);
}

void VulkanCppConsumer::Process_vkGetPipelineCacheData(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
    fprintf(file, "// TODO: Support vkGetPipelineCacheData function.\n");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPipelineCacheData);
}

void VulkanCppConsumer::Process_vkGetQueryPoolResults(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    Generate_vkGetQueryPoolResults(returnValue, device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    Post_APICall(format::ApiCallId::ApiCall_vkGetQueryPoolResults);
}

void VulkanCppConsumer::Process_vkGetRenderAreaGranularity(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* renderPass */
/* pGranularity */
    std::string pGranularityName = "pGranularity_" + std::to_string(this->getNextId());
    fprintf(file, "VkExtent2D %s;\n", pGranularityName.c_str());
    fprintf(file,
            "vkGetRenderAreaGranularity(%s, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(renderPass).c_str(),
            pGranularityName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetRenderAreaGranularity);
}

void VulkanCppConsumer::Process_vkInvalidateMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* memoryRangeCount */
/* pMemoryRanges */
    std::stringstream stream_pMemoryRanges;
    std::string pMemoryRangesArray = "NULL";
    PointerPairContainer<decltype(pMemoryRanges->GetPointer()), decltype(pMemoryRanges->GetMetaStructPointer())> pMemoryRangesPair{ pMemoryRanges->GetPointer(), pMemoryRanges->GetMetaStructPointer(), memoryRangeCount };
    std::string pMemoryRangesNames = toStringJoin(pMemoryRangesPair.begin(),
                                                  pMemoryRangesPair.end(),
                                                  [&](auto pair) { return GenerateStruct_VkMappedMemoryRange(stream_pMemoryRanges, pair.t1, pair.t2, *this); },
                                                  ", ");
    fprintf(file, "\n%s", stream_pMemoryRanges.str().c_str());
    if (memoryRangeCount == 1) {
        pMemoryRangesArray = "&" + pMemoryRangesNames;
    } else if (memoryRangeCount > 1) {
        pMemoryRangesArray = "pMemoryRanges_" + std::to_string(this->getNextId());
        fprintf(file, "VkMappedMemoryRange %s[] = { %s };\n", pMemoryRangesArray.c_str(), pMemoryRangesNames.c_str());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkInvalidateMappedMemoryRanges(%s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            memoryRangeCount,
            pMemoryRangesArray.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges);
}

void VulkanCppConsumer::Process_vkMapMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            memory,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkMemoryMapFlags                            flags,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    Generate_vkMapMemory(returnValue, device, memory, offset, size, flags, ppData);
    Post_APICall(format::ApiCallId::ApiCall_vkMapMemory);
}

void VulkanCppConsumer::Process_vkMergePipelineCaches(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    HandlePointerDecoder<VkPipelineCache>*      pSrcCaches)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* dstCache */
/* srcCacheCount */
/* pSrcCaches */
    std::string pSrcCachesArray = "NULL";
    std::string pSrcCachesValues = toStringJoin(pSrcCaches->GetPointer(),
                                                pSrcCaches->GetPointer() + srcCacheCount,
                                                [&](const format::HandleId current) { return this->GetHandle(current); },
                                                ", ");
    if (srcCacheCount == 1) {
        pSrcCachesArray = "&" + pSrcCachesValues;
    } else if (srcCacheCount > 1) {
        pSrcCachesArray = "pSrcCachesArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkPipelineCache %s[] = { %s };\n", pSrcCachesArray.c_str(), pSrcCachesValues.c_str());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkMergePipelineCaches(%s, %s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(dstCache).c_str(),
            srcCacheCount,
            pSrcCachesArray.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkMergePipelineCaches);
}

void VulkanCppConsumer::Process_vkQueueBindSparse(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo,
    format::HandleId                            fence)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* queue */
/* bindInfoCount */
/* pBindInfo */
    std::stringstream stream_pBindInfo;
    std::string pBindInfoArray = "NULL";
    PointerPairContainer<decltype(pBindInfo->GetPointer()), decltype(pBindInfo->GetMetaStructPointer())> pBindInfoPair{ pBindInfo->GetPointer(), pBindInfo->GetMetaStructPointer(), bindInfoCount };
    std::string pBindInfoNames = toStringJoin(pBindInfoPair.begin(),
                                              pBindInfoPair.end(),
                                              [&](auto pair) { return GenerateStruct_VkBindSparseInfo(stream_pBindInfo, pair.t1, pair.t2, *this); },
                                              ", ");
    fprintf(file, "\n%s", stream_pBindInfo.str().c_str());
    if (bindInfoCount == 1) {
        pBindInfoArray = "&" + pBindInfoNames;
    } else if (bindInfoCount > 1) {
        pBindInfoArray = "pBindInfo_" + std::to_string(this->getNextId());
        fprintf(file, "VkBindSparseInfo %s[] = { %s };\n", pBindInfoArray.c_str(), pBindInfoNames.c_str());
    }
/* fence */
    fprintf(file,
            "VK_CALL_CHECK(vkQueueBindSparse(%s, %u, %s, %s), %s);\n",
            this->GetHandle(queue).c_str(),
            bindInfoCount,
            pBindInfoArray.c_str(),
            this->GetHandle(fence).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkQueueBindSparse);
}

void VulkanCppConsumer::Process_vkQueueSubmit(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
    format::HandleId                            fence)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* queue */
/* submitCount */
/* pSubmits */
    std::stringstream stream_pSubmits;
    std::string pSubmitsArray = "NULL";
    PointerPairContainer<decltype(pSubmits->GetPointer()), decltype(pSubmits->GetMetaStructPointer())> pSubmitsPair{ pSubmits->GetPointer(), pSubmits->GetMetaStructPointer(), submitCount };
    std::string pSubmitsNames = toStringJoin(pSubmitsPair.begin(),
                                             pSubmitsPair.end(),
                                             [&](auto pair) { return GenerateStruct_VkSubmitInfo(stream_pSubmits, pair.t1, pair.t2, *this); },
                                             ", ");
    fprintf(file, "\n%s", stream_pSubmits.str().c_str());
    if (submitCount == 1) {
        pSubmitsArray = "&" + pSubmitsNames;
    } else if (submitCount > 1) {
        pSubmitsArray = "pSubmits_" + std::to_string(this->getNextId());
        fprintf(file, "VkSubmitInfo %s[] = { %s };\n", pSubmitsArray.c_str(), pSubmitsNames.c_str());
    }
/* fence */
    fprintf(file,
            "VK_CALL_CHECK(vkQueueSubmit(%s, %u, %s, %s), %s);\n",
            this->GetHandle(queue).c_str(),
            submitCount,
            pSubmitsArray.c_str(),
            this->GetHandle(fence).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkQueueSubmit);
}

void VulkanCppConsumer::Process_vkQueueWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* queue */
    fprintf(file,
            "VK_CALL_CHECK(vkQueueWaitIdle(%s), %s);\n",
            this->GetHandle(queue).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkQueueWaitIdle);
}

void VulkanCppConsumer::Process_vkResetCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* flags */
    fprintf(file,
            "VK_CALL_CHECK(vkResetCommandBuffer(%s, %s), %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkCommandBufferResetFlags>(flags).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkResetCommandBuffer);
}

void VulkanCppConsumer::Process_vkResetCommandPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolResetFlags                     flags)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* commandPool */
/* flags */
    fprintf(file,
            "VK_CALL_CHECK(vkResetCommandPool(%s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(commandPool).c_str(),
            util::ToString<VkCommandPoolResetFlags>(flags).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkResetCommandPool);
}

void VulkanCppConsumer::Process_vkResetDescriptorPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* descriptorPool */
/* flags */
    fprintf(file,
            "VK_CALL_CHECK(vkResetDescriptorPool(%s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(descriptorPool).c_str(),
            util::ToString<VkDescriptorPoolResetFlags>(flags).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkResetDescriptorPool);
}

void VulkanCppConsumer::Process_vkResetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* event */
    fprintf(file,
            "VK_CALL_CHECK(vkResetEvent(%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(event).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkResetEvent);
}

void VulkanCppConsumer::Process_vkResetFences(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    fenceCount,
    HandlePointerDecoder<VkFence>*              pFences)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* fenceCount */
/* pFences */
    std::string pFencesArray = "NULL";
    std::string pFencesValues = toStringJoin(pFences->GetPointer(),
                                             pFences->GetPointer() + fenceCount,
                                             [&](const format::HandleId current) { return this->GetHandle(current); },
                                             ", ");
    if (fenceCount == 1) {
        pFencesArray = "&" + pFencesValues;
    } else if (fenceCount > 1) {
        pFencesArray = "pFencesArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkFence %s[] = { %s };\n", pFencesArray.c_str(), pFencesValues.c_str());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkResetFences(%s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            fenceCount,
            pFencesArray.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkResetFences);
}

void VulkanCppConsumer::Process_vkSetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* event */
    fprintf(file,
            "VK_CALL_CHECK(vkSetEvent(%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(event).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSetEvent);
}

void VulkanCppConsumer::Process_vkUnmapMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory)
{
    Generate_vkUnmapMemory(device, memory);
    Post_APICall(format::ApiCallId::ApiCall_vkUnmapMemory);
}

void VulkanCppConsumer::Process_vkUpdateDescriptorSets(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
    uint32_t                                    descriptorCopyCount,
    StructPointerDecoder<Decoded_VkCopyDescriptorSet>* pDescriptorCopies)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* descriptorWriteCount */
/* pDescriptorWrites */
    std::stringstream stream_pDescriptorWrites;
    std::string pDescriptorWritesArray = "NULL";
    PointerPairContainer<decltype(pDescriptorWrites->GetPointer()), decltype(pDescriptorWrites->GetMetaStructPointer())> pDescriptorWritesPair{ pDescriptorWrites->GetPointer(), pDescriptorWrites->GetMetaStructPointer(), descriptorWriteCount };
    std::string pDescriptorWritesNames = toStringJoin(pDescriptorWritesPair.begin(),
                                                      pDescriptorWritesPair.end(),
                                                      [&](auto pair) { return GenerateStruct_VkWriteDescriptorSet(stream_pDescriptorWrites, pair.t1, pair.t2, *this); },
                                                      ", ");
    fprintf(file, "\n%s", stream_pDescriptorWrites.str().c_str());
    if (descriptorWriteCount == 1) {
        pDescriptorWritesArray = "&" + pDescriptorWritesNames;
    } else if (descriptorWriteCount > 1) {
        pDescriptorWritesArray = "pDescriptorWrites_" + std::to_string(this->getNextId());
        fprintf(file, "VkWriteDescriptorSet %s[] = { %s };\n", pDescriptorWritesArray.c_str(), pDescriptorWritesNames.c_str());
    }
/* descriptorCopyCount */
/* pDescriptorCopies */
    std::stringstream stream_pDescriptorCopies;
    std::string pDescriptorCopiesArray = "NULL";
    PointerPairContainer<decltype(pDescriptorCopies->GetPointer()), decltype(pDescriptorCopies->GetMetaStructPointer())> pDescriptorCopiesPair{ pDescriptorCopies->GetPointer(), pDescriptorCopies->GetMetaStructPointer(), descriptorCopyCount };
    std::string pDescriptorCopiesNames = toStringJoin(pDescriptorCopiesPair.begin(),
                                                      pDescriptorCopiesPair.end(),
                                                      [&](auto pair) { return GenerateStruct_VkCopyDescriptorSet(stream_pDescriptorCopies, pair.t1, pair.t2, *this); },
                                                      ", ");
    fprintf(file, "\n%s", stream_pDescriptorCopies.str().c_str());
    if (descriptorCopyCount == 1) {
        pDescriptorCopiesArray = "&" + pDescriptorCopiesNames;
    } else if (descriptorCopyCount > 1) {
        pDescriptorCopiesArray = "pDescriptorCopies_" + std::to_string(this->getNextId());
        fprintf(file, "VkCopyDescriptorSet %s[] = { %s };\n", pDescriptorCopiesArray.c_str(), pDescriptorCopiesNames.c_str());
    }
    fprintf(file,
            "vkUpdateDescriptorSets(%s, %u, %s, %u, %s);\n",
            this->GetHandle(device).c_str(),
            descriptorWriteCount,
            pDescriptorWritesArray.c_str(),
            descriptorCopyCount,
            pDescriptorCopiesArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkUpdateDescriptorSets);
}

void VulkanCppConsumer::Process_vkWaitForFences(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    fenceCount,
    HandlePointerDecoder<VkFence>*              pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout)
{
    Generate_vkWaitForFences(returnValue, device, fenceCount, pFences, waitAll, timeout);
    Post_APICall(format::ApiCallId::ApiCall_vkWaitForFences);
}

void VulkanCppConsumer::Process_vkBindBufferMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* bindInfoCount */
/* pBindInfos */
    std::stringstream stream_pBindInfos;
    std::string pBindInfosArray = "NULL";
    PointerPairContainer<decltype(pBindInfos->GetPointer()), decltype(pBindInfos->GetMetaStructPointer())> pBindInfosPair{ pBindInfos->GetPointer(), pBindInfos->GetMetaStructPointer(), bindInfoCount };
    std::string pBindInfosNames = toStringJoin(pBindInfosPair.begin(),
                                               pBindInfosPair.end(),
                                               [&](auto pair) { return GenerateStruct_VkBindBufferMemoryInfo(stream_pBindInfos, pair.t1, pair.t2, *this); },
                                               ", ");
    fprintf(file, "\n%s", stream_pBindInfos.str().c_str());
    if (bindInfoCount == 1) {
        pBindInfosArray = "&" + pBindInfosNames;
    } else if (bindInfoCount > 1) {
        pBindInfosArray = "pBindInfos_" + std::to_string(this->getNextId());
        fprintf(file, "VkBindBufferMemoryInfo %s[] = { %s };\n", pBindInfosArray.c_str(), pBindInfosNames.c_str());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkBindBufferMemory2(%s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            bindInfoCount,
            pBindInfosArray.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindBufferMemory2);
}

void VulkanCppConsumer::Process_vkBindImageMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* bindInfoCount */
/* pBindInfos */
    std::stringstream stream_pBindInfos;
    std::string pBindInfosArray = "NULL";
    PointerPairContainer<decltype(pBindInfos->GetPointer()), decltype(pBindInfos->GetMetaStructPointer())> pBindInfosPair{ pBindInfos->GetPointer(), pBindInfos->GetMetaStructPointer(), bindInfoCount };
    std::string pBindInfosNames = toStringJoin(pBindInfosPair.begin(),
                                               pBindInfosPair.end(),
                                               [&](auto pair) { return GenerateStruct_VkBindImageMemoryInfo(stream_pBindInfos, pair.t1, pair.t2, *this); },
                                               ", ");
    fprintf(file, "\n%s", stream_pBindInfos.str().c_str());
    if (bindInfoCount == 1) {
        pBindInfosArray = "&" + pBindInfosNames;
    } else if (bindInfoCount > 1) {
        pBindInfosArray = "pBindInfos_" + std::to_string(this->getNextId());
        fprintf(file, "VkBindImageMemoryInfo %s[] = { %s };\n", pBindInfosArray.c_str(), pBindInfosNames.c_str());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkBindImageMemory2(%s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            bindInfoCount,
            pBindInfosArray.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindImageMemory2);
}

void VulkanCppConsumer::Process_vkCmdDispatchBase(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* baseGroupX */
/* baseGroupY */
/* baseGroupZ */
/* groupCountX */
/* groupCountY */
/* groupCountZ */
    fprintf(file,
            "vkCmdDispatchBase(%s, %u, %u, %u, %u, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            baseGroupX,
            baseGroupY,
            baseGroupZ,
            groupCountX,
            groupCountY,
            groupCountZ);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDispatchBase);
}

void VulkanCppConsumer::Process_vkCmdSetDeviceMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* deviceMask */
    fprintf(file,
            "vkCmdSetDeviceMask(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            deviceMask);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDeviceMask);
}

void VulkanCppConsumer::Process_vkCreateDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    Generate_vkCreateDescriptorUpdateTemplate(returnValue, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate);
}

void VulkanCppConsumer::Process_vkCreateSamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkSamplerYcbcrConversionCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pYcbcrConversion */
    std::string pYcbcrConversionName = "pYcbcrConversion_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION));
    AddKnownVariables("VkSamplerYcbcrConversion", pYcbcrConversionName, pYcbcrConversion->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pYcbcrConversionName,
                         pYcbcrConversion->GetPointer());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreateSamplerYcbcrConversion(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pYcbcrConversionName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion);
}

void VulkanCppConsumer::Process_vkDestroyDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* descriptorUpdateTemplate */
/* pAllocator */
    fprintf(file,
            "vkDestroyDescriptorUpdateTemplate(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(descriptorUpdateTemplate).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate);
}

void VulkanCppConsumer::Process_vkDestroySamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* ycbcrConversion */
/* pAllocator */
    fprintf(file,
            "vkDestroySamplerYcbcrConversion(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(ycbcrConversion).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion);
}

void VulkanCppConsumer::Process_vkEnumeratePhysicalDeviceGroups(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* instance */
/* pPhysicalDeviceGroupCount */
    std::string pPhysicalDeviceGroupCountName = "pPhysicalDeviceGroupCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pPhysicalDeviceGroupCountName.c_str());
/* pPhysicalDeviceGroupProperties */
    std::string pPhysicalDeviceGroupPropertiesName = "pPhysicalDeviceGroupProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pPhysicalDeviceGroupProperties;
    pPhysicalDeviceGroupPropertiesName = GenerateStruct_VkPhysicalDeviceGroupProperties(stream_pPhysicalDeviceGroupProperties,
                                                                        pPhysicalDeviceGroupProperties->GetPointer(),
                                                                        pPhysicalDeviceGroupProperties->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "\n%s", stream_pPhysicalDeviceGroupProperties.str().c_str());
    fprintf(file,
            "VK_CALL_CHECK(vkEnumeratePhysicalDeviceGroups(%s, &%s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pPhysicalDeviceGroupCountName.c_str(),
            pPhysicalDeviceGroupPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups);
}

void VulkanCppConsumer::Process_vkGetBufferMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkBufferMemoryRequirementsInfo2(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
/* pMemoryRequirements */
    std::string pMemoryRequirementsName = "pMemoryRequirements_" + std::to_string(this->getNextId());
    std::stringstream stream_pMemoryRequirements;
    pMemoryRequirementsName = GenerateStruct_VkMemoryRequirements2(stream_pMemoryRequirements,
                                                             pMemoryRequirements->GetPointer(),
                                                             pMemoryRequirements->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pMemoryRequirements.str().c_str());
    fprintf(file,
            "vkGetBufferMemoryRequirements2(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str(),
            pMemoryRequirementsName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2);
}

void VulkanCppConsumer::Process_vkGetDescriptorSetLayoutSupport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkDescriptorSetLayoutCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pSupport */
    std::string pSupportName = "pSupport_" + std::to_string(this->getNextId());
    std::stringstream stream_pSupport;
    pSupportName = GenerateStruct_VkDescriptorSetLayoutSupport(stream_pSupport,
                                                  pSupport->GetPointer(),
                                                  pSupport->GetMetaStructPointer(),
                                                  *this);
    fprintf(file, "\n%s", stream_pSupport.str().c_str());
    fprintf(file,
            "vkGetDescriptorSetLayoutSupport(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            pSupportName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport);
}

void VulkanCppConsumer::Process_vkGetDeviceGroupPeerMemoryFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* heapIndex */
/* localDeviceIndex */
/* remoteDeviceIndex */
/* pPeerMemoryFeatures */
    std::string pPeerMemoryFeaturesName = "pPeerMemoryFeatures_" + std::to_string(this->getNextId());
    fprintf(file, "VkPeerMemoryFeatureFlags %s;\n", pPeerMemoryFeaturesName.c_str());
    fprintf(file,
            "vkGetDeviceGroupPeerMemoryFeatures(%s, %u, %u, %u, &%s);\n",
            this->GetHandle(device).c_str(),
            heapIndex,
            localDeviceIndex,
            remoteDeviceIndex,
            pPeerMemoryFeaturesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures);
}

void VulkanCppConsumer::Process_vkGetDeviceQueue2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceQueueInfo2>* pQueueInfo,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pQueueInfo */
    std::stringstream stream_pQueueInfo;
    std::string pQueueInfoStruct = GenerateStruct_VkDeviceQueueInfo2(stream_pQueueInfo,
                                                                  pQueueInfo->GetPointer(),
                                                                  pQueueInfo->GetMetaStructPointer(),
                                                                  *this);
    fprintf(file, "\n%s", stream_pQueueInfo.str().c_str());
/* pQueue */
    std::string pQueueName = "pQueue_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_QUEUE));
    AddKnownVariables("VkQueue", pQueueName, pQueue->GetPointer());
    this->AddHandles(pQueueName,
                     pQueue->GetPointer());
    fprintf(file,
            "vkGetDeviceQueue2(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pQueueInfoStruct.c_str(),
            pQueueName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceQueue2);
}

void VulkanCppConsumer::Process_vkGetImageMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkImageMemoryRequirementsInfo2(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
/* pMemoryRequirements */
    std::string pMemoryRequirementsName = "pMemoryRequirements_" + std::to_string(this->getNextId());
    std::stringstream stream_pMemoryRequirements;
    pMemoryRequirementsName = GenerateStruct_VkMemoryRequirements2(stream_pMemoryRequirements,
                                                             pMemoryRequirements->GetPointer(),
                                                             pMemoryRequirements->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pMemoryRequirements.str().c_str());
    fprintf(file,
            "vkGetImageMemoryRequirements2(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str(),
            pMemoryRequirementsName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2);
}

void VulkanCppConsumer::Process_vkGetImageSparseMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkImageSparseMemoryRequirementsInfo2(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
/* pSparseMemoryRequirementCount */
    std::string pSparseMemoryRequirementCountName = "pSparseMemoryRequirementCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pSparseMemoryRequirementCountName.c_str());
/* pSparseMemoryRequirements */
    std::string pSparseMemoryRequirementsName = "pSparseMemoryRequirements_" + std::to_string(this->getNextId());
    std::stringstream stream_pSparseMemoryRequirements;
    pSparseMemoryRequirementsName = GenerateStruct_VkSparseImageMemoryRequirements2(stream_pSparseMemoryRequirements,
                                                                   pSparseMemoryRequirements->GetPointer(),
                                                                   pSparseMemoryRequirements->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pSparseMemoryRequirements.str().c_str());
    fprintf(file,
            "vkGetImageSparseMemoryRequirements2(%s, &%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str(),
            pSparseMemoryRequirementCountName.c_str(),
            pSparseMemoryRequirementsName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceExternalBufferProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pExternalBufferInfo */
    std::stringstream stream_pExternalBufferInfo;
    std::string pExternalBufferInfoStruct = GenerateStruct_VkPhysicalDeviceExternalBufferInfo(stream_pExternalBufferInfo,
                                                                           pExternalBufferInfo->GetPointer(),
                                                                           pExternalBufferInfo->GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "\n%s", stream_pExternalBufferInfo.str().c_str());
/* pExternalBufferProperties */
    std::string pExternalBufferPropertiesName = "pExternalBufferProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pExternalBufferProperties;
    pExternalBufferPropertiesName = GenerateStruct_VkExternalBufferProperties(stream_pExternalBufferProperties,
                                                                   pExternalBufferProperties->GetPointer(),
                                                                   pExternalBufferProperties->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pExternalBufferProperties.str().c_str());
    fprintf(file,
            "vkGetPhysicalDeviceExternalBufferProperties(%s, &%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pExternalBufferInfoStruct.c_str(),
            pExternalBufferPropertiesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceExternalFenceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pExternalFenceInfo */
    std::stringstream stream_pExternalFenceInfo;
    std::string pExternalFenceInfoStruct = GenerateStruct_VkPhysicalDeviceExternalFenceInfo(stream_pExternalFenceInfo,
                                                                          pExternalFenceInfo->GetPointer(),
                                                                          pExternalFenceInfo->GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "\n%s", stream_pExternalFenceInfo.str().c_str());
/* pExternalFenceProperties */
    std::string pExternalFencePropertiesName = "pExternalFenceProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pExternalFenceProperties;
    pExternalFencePropertiesName = GenerateStruct_VkExternalFenceProperties(stream_pExternalFenceProperties,
                                                                  pExternalFenceProperties->GetPointer(),
                                                                  pExternalFenceProperties->GetMetaStructPointer(),
                                                                  *this);
    fprintf(file, "\n%s", stream_pExternalFenceProperties.str().c_str());
    fprintf(file,
            "vkGetPhysicalDeviceExternalFenceProperties(%s, &%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pExternalFenceInfoStruct.c_str(),
            pExternalFencePropertiesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pExternalSemaphoreInfo */
    std::stringstream stream_pExternalSemaphoreInfo;
    std::string pExternalSemaphoreInfoStruct = GenerateStruct_VkPhysicalDeviceExternalSemaphoreInfo(stream_pExternalSemaphoreInfo,
                                                                              pExternalSemaphoreInfo->GetPointer(),
                                                                              pExternalSemaphoreInfo->GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "\n%s", stream_pExternalSemaphoreInfo.str().c_str());
/* pExternalSemaphoreProperties */
    std::string pExternalSemaphorePropertiesName = "pExternalSemaphoreProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pExternalSemaphoreProperties;
    pExternalSemaphorePropertiesName = GenerateStruct_VkExternalSemaphoreProperties(stream_pExternalSemaphoreProperties,
                                                                      pExternalSemaphoreProperties->GetPointer(),
                                                                      pExternalSemaphoreProperties->GetMetaStructPointer(),
                                                                      *this);
    fprintf(file, "\n%s", stream_pExternalSemaphoreProperties.str().c_str());
    fprintf(file,
            "vkGetPhysicalDeviceExternalSemaphoreProperties(%s, &%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pExternalSemaphoreInfoStruct.c_str(),
            pExternalSemaphorePropertiesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceFeatures2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pFeatures */
    std::string pFeaturesName = "pFeatures_" + std::to_string(this->getNextId());
    std::stringstream stream_pFeatures;
    pFeaturesName = GenerateStruct_VkPhysicalDeviceFeatures2(stream_pFeatures,
                                                   pFeatures->GetPointer(),
                                                   pFeatures->GetMetaStructPointer(),
                                                   *this);
    fprintf(file, "\n%s", stream_pFeatures.str().c_str());
    fprintf(file,
            "vkGetPhysicalDeviceFeatures2(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pFeaturesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceFormatProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* format */
/* pFormatProperties */
    std::string pFormatPropertiesName = "pFormatProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pFormatProperties;
    pFormatPropertiesName = GenerateStruct_VkFormatProperties2(stream_pFormatProperties,
                                                           pFormatProperties->GetPointer(),
                                                           pFormatProperties->GetMetaStructPointer(),
                                                           *this);
    fprintf(file, "\n%s", stream_pFormatProperties.str().c_str());
    fprintf(file,
            "vkGetPhysicalDeviceFormatProperties2(%s, %s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            util::ToString<VkFormat>(format).c_str(),
            pFormatPropertiesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pImageFormatInfo */
    std::stringstream stream_pImageFormatInfo;
    std::string pImageFormatInfoStruct = GenerateStruct_VkPhysicalDeviceImageFormatInfo2(stream_pImageFormatInfo,
                                                                        pImageFormatInfo->GetPointer(),
                                                                        pImageFormatInfo->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "\n%s", stream_pImageFormatInfo.str().c_str());
/* pImageFormatProperties */
    std::string pImageFormatPropertiesName = "pImageFormatProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pImageFormatProperties;
    pImageFormatPropertiesName = GenerateStruct_VkImageFormatProperties2(stream_pImageFormatProperties,
                                                                pImageFormatProperties->GetPointer(),
                                                                pImageFormatProperties->GetMetaStructPointer(),
                                                                *this);
    fprintf(file, "\n%s", stream_pImageFormatProperties.str().c_str());
    fprintf(file,
            "VK_CALL_CHECK(vkGetPhysicalDeviceImageFormatProperties2(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pImageFormatInfoStruct.c_str(),
            pImageFormatPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceMemoryProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pMemoryProperties */
    std::string pMemoryPropertiesName = "pMemoryProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pMemoryProperties;
    pMemoryPropertiesName = GenerateStruct_VkPhysicalDeviceMemoryProperties2(stream_pMemoryProperties,
                                                           pMemoryProperties->GetPointer(),
                                                           pMemoryProperties->GetMetaStructPointer(),
                                                           *this);
    fprintf(file, "\n%s", stream_pMemoryProperties.str().c_str());
    fprintf(file,
            "vkGetPhysicalDeviceMemoryProperties2(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pMemoryPropertiesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pProperties */
    std::string pPropertiesName = "pProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pProperties;
    pPropertiesName = GenerateStruct_VkPhysicalDeviceProperties2(stream_pProperties,
                                                     pProperties->GetPointer(),
                                                     pProperties->GetMetaStructPointer(),
                                                     *this);
    fprintf(file, "\n%s", stream_pProperties.str().c_str());
    fprintf(file,
            "vkGetPhysicalDeviceProperties2(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pPropertiesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pQueueFamilyPropertyCount */
    std::string pQueueFamilyPropertyCountName = "pQueueFamilyPropertyCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pQueueFamilyPropertyCountName.c_str());
/* pQueueFamilyProperties */
    std::string pQueueFamilyPropertiesName = "pQueueFamilyProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pQueueFamilyProperties;
    pQueueFamilyPropertiesName = GenerateStruct_VkQueueFamilyProperties2(stream_pQueueFamilyProperties,
                                                                pQueueFamilyProperties->GetPointer(),
                                                                pQueueFamilyProperties->GetMetaStructPointer(),
                                                                *this);
    fprintf(file, "\n%s", stream_pQueueFamilyProperties.str().c_str());
    fprintf(file,
            "vkGetPhysicalDeviceQueueFamilyProperties2(%s, &%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pQueueFamilyPropertyCountName.c_str(),
            pQueueFamilyPropertiesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pFormatInfo */
    std::stringstream stream_pFormatInfo;
    std::string pFormatInfoStruct = GenerateStruct_VkPhysicalDeviceSparseImageFormatInfo2(stream_pFormatInfo,
                                                                   pFormatInfo->GetPointer(),
                                                                   pFormatInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pFormatInfo.str().c_str());
/* pPropertyCount */
    std::string pPropertyCountName = "pPropertyCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pPropertyCountName.c_str());
/* pProperties */
    std::string pPropertiesName = "pProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pProperties;
    pPropertiesName = GenerateStruct_VkSparseImageFormatProperties2(stream_pProperties,
                                                     pProperties->GetPointer(),
                                                     pProperties->GetMetaStructPointer(),
                                                     *this);
    fprintf(file, "\n%s", stream_pProperties.str().c_str());
    fprintf(file,
            "vkGetPhysicalDeviceSparseImageFormatProperties2(%s, &%s, &%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pFormatInfoStruct.c_str(),
            pPropertyCountName.c_str(),
            pPropertiesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2);
}

void VulkanCppConsumer::Process_vkTrimCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* commandPool */
/* flags */
    fprintf(file,
            "vkTrimCommandPool(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(commandPool).c_str(),
            util::ToString<VkCommandPoolTrimFlags>(flags).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkTrimCommandPool);
}

void VulkanCppConsumer::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pRenderPassBegin */
    std::stringstream stream_pRenderPassBegin;
    std::string pRenderPassBeginStruct = GenerateStruct_VkRenderPassBeginInfo(stream_pRenderPassBegin,
                                                                        pRenderPassBegin->GetPointer(),
                                                                        pRenderPassBegin->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "\n%s", stream_pRenderPassBegin.str().c_str());
/* pSubpassBeginInfo */
    std::stringstream stream_pSubpassBeginInfo;
    std::string pSubpassBeginInfoStruct = GenerateStruct_VkSubpassBeginInfo(stream_pSubpassBeginInfo,
                                                                         pSubpassBeginInfo->GetPointer(),
                                                                         pSubpassBeginInfo->GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "\n%s", stream_pSubpassBeginInfo.str().c_str());
    fprintf(file,
            "vkCmdBeginRenderPass2(%s, &%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pRenderPassBeginStruct.c_str(),
            pSubpassBeginInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginRenderPass2);
}

void VulkanCppConsumer::Process_vkCmdDrawIndexedIndirectCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* buffer */
/* offset */
/* countBuffer */
/* countBufferOffset */
/* maxDrawCount */
/* stride */
    fprintf(file,
            "vkCmdDrawIndexedIndirectCount(%s, %s, %luUL, %s, %luUL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            this->GetHandle(countBuffer).c_str(),
            countBufferOffset,
            maxDrawCount,
            stride);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount);
}

void VulkanCppConsumer::Process_vkCmdDrawIndirectCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* buffer */
/* offset */
/* countBuffer */
/* countBufferOffset */
/* maxDrawCount */
/* stride */
    fprintf(file,
            "vkCmdDrawIndirectCount(%s, %s, %luUL, %s, %luUL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            this->GetHandle(countBuffer).c_str(),
            countBufferOffset,
            maxDrawCount,
            stride);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirectCount);
}

void VulkanCppConsumer::Process_vkCmdEndRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pSubpassEndInfo */
    std::stringstream stream_pSubpassEndInfo;
    std::string pSubpassEndInfoStruct = GenerateStruct_VkSubpassEndInfo(stream_pSubpassEndInfo,
                                                                       pSubpassEndInfo->GetPointer(),
                                                                       pSubpassEndInfo->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "\n%s", stream_pSubpassEndInfo.str().c_str());
    fprintf(file,
            "vkCmdEndRenderPass2(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pSubpassEndInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRenderPass2);
}

void VulkanCppConsumer::Process_vkCmdNextSubpass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pSubpassBeginInfo */
    std::stringstream stream_pSubpassBeginInfo;
    std::string pSubpassBeginInfoStruct = GenerateStruct_VkSubpassBeginInfo(stream_pSubpassBeginInfo,
                                                                         pSubpassBeginInfo->GetPointer(),
                                                                         pSubpassBeginInfo->GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "\n%s", stream_pSubpassBeginInfo.str().c_str());
/* pSubpassEndInfo */
    std::stringstream stream_pSubpassEndInfo;
    std::string pSubpassEndInfoStruct = GenerateStruct_VkSubpassEndInfo(stream_pSubpassEndInfo,
                                                                       pSubpassEndInfo->GetPointer(),
                                                                       pSubpassEndInfo->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "\n%s", stream_pSubpassEndInfo.str().c_str());
    fprintf(file,
            "vkCmdNextSubpass2(%s, &%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pSubpassBeginInfoStruct.c_str(),
            pSubpassEndInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdNextSubpass2);
}

void VulkanCppConsumer::Process_vkCreateRenderPass2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkRenderPassCreateInfo2(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pRenderPass */
    std::string pRenderPassName = "pRenderPass_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_RENDER_PASS));
    AddKnownVariables("VkRenderPass", pRenderPassName, pRenderPass->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pRenderPassName,
                         pRenderPass->GetPointer());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreateRenderPass2(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pRenderPassName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateRenderPass2);
}

void VulkanCppConsumer::Process_vkGetBufferDeviceAddress(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkBufferDeviceAddressInfo(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
    fprintf(file,
            "vkGetBufferDeviceAddress(%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferDeviceAddress);
}

void VulkanCppConsumer::Process_vkGetBufferOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkBufferDeviceAddressInfo(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
    fprintf(file,
            "vkGetBufferOpaqueCaptureAddress(%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress);
}

void VulkanCppConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkDeviceMemoryOpaqueCaptureAddressInfo(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
    fprintf(file,
            "vkGetDeviceMemoryOpaqueCaptureAddress(%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress);
}

void VulkanCppConsumer::Process_vkGetSemaphoreCounterValue(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* semaphore */
/* pValue */
    std::string pValueName = "pValue_" + std::to_string(this->getNextId());
    fprintf(file, "uint64_t %s;\n", pValueName.c_str());
    fprintf(file,
            "VK_CALL_CHECK(vkGetSemaphoreCounterValue(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(semaphore).c_str(),
            pValueName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue);
}

void VulkanCppConsumer::Process_vkResetQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* queryPool */
/* firstQuery */
/* queryCount */
    fprintf(file,
            "vkResetQueryPool(%s, %s, %u, %u);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(queryPool).c_str(),
            firstQuery,
            queryCount);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkResetQueryPool);
}

void VulkanCppConsumer::Process_vkSignalSemaphore(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pSignalInfo */
    std::stringstream stream_pSignalInfo;
    std::string pSignalInfoStruct = GenerateStruct_VkSemaphoreSignalInfo(stream_pSignalInfo,
                                                                   pSignalInfo->GetPointer(),
                                                                   pSignalInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pSignalInfo.str().c_str());
    fprintf(file,
            "VK_CALL_CHECK(vkSignalSemaphore(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pSignalInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSignalSemaphore);
}

void VulkanCppConsumer::Process_vkWaitSemaphores(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pWaitInfo */
    std::stringstream stream_pWaitInfo;
    std::string pWaitInfoStruct = GenerateStruct_VkSemaphoreWaitInfo(stream_pWaitInfo,
                                                                 pWaitInfo->GetPointer(),
                                                                 pWaitInfo->GetMetaStructPointer(),
                                                                 *this);
    fprintf(file, "\n%s", stream_pWaitInfo.str().c_str());
/* timeout */
    fprintf(file,
            "VK_CALL_CHECK(vkWaitSemaphores(%s, &%s, %luUL), %s);\n",
            this->GetHandle(device).c_str(),
            pWaitInfoStruct.c_str(),
            timeout,
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkWaitSemaphores);
}

void VulkanCppConsumer::Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pRenderingInfo */
    std::stringstream stream_pRenderingInfo;
    std::string pRenderingInfoStruct = GenerateStruct_VkRenderingInfo(stream_pRenderingInfo,
                                                                      pRenderingInfo->GetPointer(),
                                                                      pRenderingInfo->GetMetaStructPointer(),
                                                                      *this);
    fprintf(file, "\n%s", stream_pRenderingInfo.str().c_str());
    fprintf(file,
            "vkCmdBeginRendering(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pRenderingInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginRendering);
}

void VulkanCppConsumer::Process_vkCmdBindVertexBuffers2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes,
    PointerDecoder<VkDeviceSize>*               pStrides)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* firstBinding */
/* bindingCount */
/* pBuffers */
    std::string pBuffersArray = "NULL";
    std::string pBuffersValues = toStringJoin(pBuffers->GetPointer(),
                                              pBuffers->GetPointer() + bindingCount,
                                              [&](const format::HandleId current) { return this->GetHandle(current); },
                                              ", ");
    if (bindingCount == 1) {
        pBuffersArray = "&" + pBuffersValues;
    } else if (bindingCount > 1) {
        pBuffersArray = "pBuffersArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkBuffer %s[] = { %s };\n", pBuffersArray.c_str(), pBuffersValues.c_str());
    }
/* pOffsets */
    std::string pOffsetsArray = "pOffsets_" + std::to_string(this->getNextId());
    if (bindingCount > 0) {
        std::string pOffsetsValues = toStringJoin(pOffsets->GetPointer(),
                                                  pOffsets->GetPointer() + bindingCount,
                                                  [&](const auto current) { return std::to_string(current) + "UL"; },
                                                  ", ");
        fprintf(file, "VkDeviceSize %s[] = { %s };\n", pOffsetsArray.c_str(), pOffsetsValues.c_str());
    } else {
        pOffsetsArray = "NULL";
    }
/* pSizes */
    std::string pSizesArray = "pSizes_" + std::to_string(this->getNextId());
    if (bindingCount > 0) {
        std::string pSizesValues = toStringJoin(pSizes->GetPointer(),
                                                pSizes->GetPointer() + bindingCount,
                                                [&](const auto current) { return std::to_string(current) + "UL"; },
                                                ", ");
        fprintf(file, "VkDeviceSize %s[] = { %s };\n", pSizesArray.c_str(), pSizesValues.c_str());
    } else {
        pSizesArray = "NULL";
    }
/* pStrides */
    std::string pStridesArray = "pStrides_" + std::to_string(this->getNextId());
    if (bindingCount > 0) {
        std::string pStridesValues = toStringJoin(pStrides->GetPointer(),
                                                  pStrides->GetPointer() + bindingCount,
                                                  [&](const auto current) { return std::to_string(current) + "UL"; },
                                                  ", ");
        fprintf(file, "VkDeviceSize %s[] = { %s };\n", pStridesArray.c_str(), pStridesValues.c_str());
    } else {
        pStridesArray = "NULL";
    }
    fprintf(file,
            "vkCmdBindVertexBuffers2(%s, %u, %u, %s, %s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstBinding,
            bindingCount,
            pBuffersArray.c_str(),
            pOffsetsArray.c_str(),
            pSizesArray.c_str(),
            pStridesArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2);
}

void VulkanCppConsumer::Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pBlitImageInfo */
    std::stringstream stream_pBlitImageInfo;
    std::string pBlitImageInfoStruct = GenerateStruct_VkBlitImageInfo2(stream_pBlitImageInfo,
                                                                      pBlitImageInfo->GetPointer(),
                                                                      pBlitImageInfo->GetMetaStructPointer(),
                                                                      *this);
    fprintf(file, "\n%s", stream_pBlitImageInfo.str().c_str());
    fprintf(file,
            "vkCmdBlitImage2(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pBlitImageInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBlitImage2);
}

void VulkanCppConsumer::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pCopyBufferInfo */
    std::stringstream stream_pCopyBufferInfo;
    std::string pCopyBufferInfoStruct = GenerateStruct_VkCopyBufferInfo2(stream_pCopyBufferInfo,
                                                                       pCopyBufferInfo->GetPointer(),
                                                                       pCopyBufferInfo->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "\n%s", stream_pCopyBufferInfo.str().c_str());
    fprintf(file,
            "vkCmdCopyBuffer2(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pCopyBufferInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyBuffer2);
}

void VulkanCppConsumer::Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pCopyBufferToImageInfo */
    std::stringstream stream_pCopyBufferToImageInfo;
    std::string pCopyBufferToImageInfoStruct = GenerateStruct_VkCopyBufferToImageInfo2(stream_pCopyBufferToImageInfo,
                                                                              pCopyBufferToImageInfo->GetPointer(),
                                                                              pCopyBufferToImageInfo->GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "\n%s", stream_pCopyBufferToImageInfo.str().c_str());
    fprintf(file,
            "vkCmdCopyBufferToImage2(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pCopyBufferToImageInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2);
}

void VulkanCppConsumer::Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pCopyImageInfo */
    std::stringstream stream_pCopyImageInfo;
    std::string pCopyImageInfoStruct = GenerateStruct_VkCopyImageInfo2(stream_pCopyImageInfo,
                                                                      pCopyImageInfo->GetPointer(),
                                                                      pCopyImageInfo->GetMetaStructPointer(),
                                                                      *this);
    fprintf(file, "\n%s", stream_pCopyImageInfo.str().c_str());
    fprintf(file,
            "vkCmdCopyImage2(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pCopyImageInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImage2);
}

void VulkanCppConsumer::Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pCopyImageToBufferInfo */
    std::stringstream stream_pCopyImageToBufferInfo;
    std::string pCopyImageToBufferInfoStruct = GenerateStruct_VkCopyImageToBufferInfo2(stream_pCopyImageToBufferInfo,
                                                                              pCopyImageToBufferInfo->GetPointer(),
                                                                              pCopyImageToBufferInfo->GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "\n%s", stream_pCopyImageToBufferInfo.str().c_str());
    fprintf(file,
            "vkCmdCopyImageToBuffer2(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pCopyImageToBufferInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2);
}

void VulkanCppConsumer::Process_vkCmdEndRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
    fprintf(file,
            "vkCmdEndRendering(%s);\n",
            this->GetHandle(commandBuffer).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRendering);
}

void VulkanCppConsumer::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pDependencyInfo */
    std::stringstream stream_pDependencyInfo;
    std::string pDependencyInfoStruct = GenerateStruct_VkDependencyInfo(stream_pDependencyInfo,
                                                                       pDependencyInfo->GetPointer(),
                                                                       pDependencyInfo->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "\n%s", stream_pDependencyInfo.str().c_str());
    fprintf(file,
            "vkCmdPipelineBarrier2(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pDependencyInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPipelineBarrier2);
}

void VulkanCppConsumer::Process_vkCmdResetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* event */
/* stageMask */
    fprintf(file,
            "vkCmdResetEvent2(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(event).c_str(),
            util::ToString<VkPipelineStageFlags2>(stageMask).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResetEvent2);
}

void VulkanCppConsumer::Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pResolveImageInfo */
    std::stringstream stream_pResolveImageInfo;
    std::string pResolveImageInfoStruct = GenerateStruct_VkResolveImageInfo2(stream_pResolveImageInfo,
                                                                         pResolveImageInfo->GetPointer(),
                                                                         pResolveImageInfo->GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "\n%s", stream_pResolveImageInfo.str().c_str());
    fprintf(file,
            "vkCmdResolveImage2(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pResolveImageInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResolveImage2);
}

void VulkanCppConsumer::Process_vkCmdSetCullMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* cullMode */
    fprintf(file,
            "vkCmdSetCullMode(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkCullModeFlags>(cullMode).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCullMode);
}

void VulkanCppConsumer::Process_vkCmdSetDepthBiasEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* depthBiasEnable */
    fprintf(file,
            "vkCmdSetDepthBiasEnable(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            depthBiasEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable);
}

void VulkanCppConsumer::Process_vkCmdSetDepthBoundsTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* depthBoundsTestEnable */
    fprintf(file,
            "vkCmdSetDepthBoundsTestEnable(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            depthBoundsTestEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable);
}

void VulkanCppConsumer::Process_vkCmdSetDepthCompareOp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* depthCompareOp */
    fprintf(file,
            "vkCmdSetDepthCompareOp(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkCompareOp>(depthCompareOp).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp);
}

void VulkanCppConsumer::Process_vkCmdSetDepthTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* depthTestEnable */
    fprintf(file,
            "vkCmdSetDepthTestEnable(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            depthTestEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable);
}

void VulkanCppConsumer::Process_vkCmdSetDepthWriteEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* depthWriteEnable */
    fprintf(file,
            "vkCmdSetDepthWriteEnable(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            depthWriteEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable);
}

void VulkanCppConsumer::Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* event */
/* pDependencyInfo */
    std::stringstream stream_pDependencyInfo;
    std::string pDependencyInfoStruct = GenerateStruct_VkDependencyInfo(stream_pDependencyInfo,
                                                                       pDependencyInfo->GetPointer(),
                                                                       pDependencyInfo->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "\n%s", stream_pDependencyInfo.str().c_str());
    fprintf(file,
            "vkCmdSetEvent2(%s, %s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(event).c_str(),
            pDependencyInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetEvent2);
}

void VulkanCppConsumer::Process_vkCmdSetFrontFace(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* frontFace */
    fprintf(file,
            "vkCmdSetFrontFace(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkFrontFace>(frontFace).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetFrontFace);
}

void VulkanCppConsumer::Process_vkCmdSetPrimitiveRestartEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* primitiveRestartEnable */
    fprintf(file,
            "vkCmdSetPrimitiveRestartEnable(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            primitiveRestartEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable);
}

void VulkanCppConsumer::Process_vkCmdSetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* primitiveTopology */
    fprintf(file,
            "vkCmdSetPrimitiveTopology(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPrimitiveTopology>(primitiveTopology).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology);
}

void VulkanCppConsumer::Process_vkCmdSetRasterizerDiscardEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* rasterizerDiscardEnable */
    fprintf(file,
            "vkCmdSetRasterizerDiscardEnable(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            rasterizerDiscardEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable);
}

void VulkanCppConsumer::Process_vkCmdSetScissorWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* scissorCount */
/* pScissors */
    std::stringstream stream_pScissors;
    std::string pScissorsArray = "NULL";
    PointerPairContainer<decltype(pScissors->GetPointer()), decltype(pScissors->GetMetaStructPointer())> pScissorsPair{ pScissors->GetPointer(), pScissors->GetMetaStructPointer(), scissorCount };
    std::string pScissorsNames = toStringJoin(pScissorsPair.begin(),
                                              pScissorsPair.end(),
                                              [&](auto pair) { return GenerateStruct_VkRect2D(stream_pScissors, pair.t1, pair.t2, *this); },
                                              ", ");
    fprintf(file, "\n%s", stream_pScissors.str().c_str());
    if (scissorCount == 1) {
        pScissorsArray = "&" + pScissorsNames;
    } else if (scissorCount > 1) {
        pScissorsArray = "pScissors_" + std::to_string(this->getNextId());
        fprintf(file, "VkRect2D %s[] = { %s };\n", pScissorsArray.c_str(), pScissorsNames.c_str());
    }
    fprintf(file,
            "vkCmdSetScissorWithCount(%s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            scissorCount,
            pScissorsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetScissorWithCount);
}

void VulkanCppConsumer::Process_vkCmdSetStencilOp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* faceMask */
/* failOp */
/* passOp */
/* depthFailOp */
/* compareOp */
    fprintf(file,
            "vkCmdSetStencilOp(%s, %s, %s, %s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkStencilFaceFlags>(faceMask).c_str(),
            util::ToString<VkStencilOp>(failOp).c_str(),
            util::ToString<VkStencilOp>(passOp).c_str(),
            util::ToString<VkStencilOp>(depthFailOp).c_str(),
            util::ToString<VkCompareOp>(compareOp).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilOp);
}

void VulkanCppConsumer::Process_vkCmdSetStencilTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* stencilTestEnable */
    fprintf(file,
            "vkCmdSetStencilTestEnable(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            stencilTestEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable);
}

void VulkanCppConsumer::Process_vkCmdSetViewportWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* viewportCount */
/* pViewports */
    std::stringstream stream_pViewports;
    std::string pViewportsArray = "NULL";
    PointerPairContainer<decltype(pViewports->GetPointer()), decltype(pViewports->GetMetaStructPointer())> pViewportsPair{ pViewports->GetPointer(), pViewports->GetMetaStructPointer(), viewportCount };
    std::string pViewportsNames = toStringJoin(pViewportsPair.begin(),
                                               pViewportsPair.end(),
                                               [&](auto pair) { return GenerateStruct_VkViewport(stream_pViewports, pair.t1, pair.t2, *this); },
                                               ", ");
    fprintf(file, "\n%s", stream_pViewports.str().c_str());
    if (viewportCount == 1) {
        pViewportsArray = "&" + pViewportsNames;
    } else if (viewportCount > 1) {
        pViewportsArray = "pViewports_" + std::to_string(this->getNextId());
        fprintf(file, "VkViewport %s[] = { %s };\n", pViewportsArray.c_str(), pViewportsNames.c_str());
    }
    fprintf(file,
            "vkCmdSetViewportWithCount(%s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            viewportCount,
            pViewportsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewportWithCount);
}

void VulkanCppConsumer::Process_vkCmdWaitEvents2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* eventCount */
/* pEvents */
    std::string pEventsArray = "NULL";
    std::string pEventsValues = toStringJoin(pEvents->GetPointer(),
                                             pEvents->GetPointer() + eventCount,
                                             [&](const format::HandleId current) { return this->GetHandle(current); },
                                             ", ");
    if (eventCount == 1) {
        pEventsArray = "&" + pEventsValues;
    } else if (eventCount > 1) {
        pEventsArray = "pEventsArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkEvent %s[] = { %s };\n", pEventsArray.c_str(), pEventsValues.c_str());
    }
/* pDependencyInfos */
    std::stringstream stream_pDependencyInfos;
    std::string pDependencyInfosArray = "NULL";
    PointerPairContainer<decltype(pDependencyInfos->GetPointer()), decltype(pDependencyInfos->GetMetaStructPointer())> pDependencyInfosPair{ pDependencyInfos->GetPointer(), pDependencyInfos->GetMetaStructPointer(), eventCount };
    std::string pDependencyInfosNames = toStringJoin(pDependencyInfosPair.begin(),
                                                     pDependencyInfosPair.end(),
                                                     [&](auto pair) { return GenerateStruct_VkDependencyInfo(stream_pDependencyInfos, pair.t1, pair.t2, *this); },
                                                     ", ");
    fprintf(file, "\n%s", stream_pDependencyInfos.str().c_str());
    if (eventCount == 1) {
        pDependencyInfosArray = "&" + pDependencyInfosNames;
    } else if (eventCount > 1) {
        pDependencyInfosArray = "pDependencyInfos_" + std::to_string(this->getNextId());
        fprintf(file, "VkDependencyInfo %s[] = { %s };\n", pDependencyInfosArray.c_str(), pDependencyInfosNames.c_str());
    }
    fprintf(file,
            "vkCmdWaitEvents2(%s, %u, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            eventCount,
            pEventsArray.c_str(),
            pDependencyInfosArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWaitEvents2);
}

void VulkanCppConsumer::Process_vkCmdWriteTimestamp2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* stage */
/* queryPool */
/* query */
    fprintf(file,
            "vkCmdWriteTimestamp2(%s, %s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineStageFlags2>(stage).c_str(),
            this->GetHandle(queryPool).c_str(),
            query);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteTimestamp2);
}

void VulkanCppConsumer::Process_vkCreatePrivateDataSlot(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPrivateDataSlot>*    pPrivateDataSlot)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkPrivateDataSlotCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pPrivateDataSlot */
    std::string pPrivateDataSlotName = "pPrivateDataSlot_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_PRIVATE_DATA_SLOT));
    AddKnownVariables("VkPrivateDataSlot", pPrivateDataSlotName, pPrivateDataSlot->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pPrivateDataSlotName,
                         pPrivateDataSlot->GetPointer());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreatePrivateDataSlot(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pPrivateDataSlotName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreatePrivateDataSlot);
}

void VulkanCppConsumer::Process_vkDestroyPrivateDataSlot(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* privateDataSlot */
/* pAllocator */
    fprintf(file,
            "vkDestroyPrivateDataSlot(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(privateDataSlot).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot);
}

void VulkanCppConsumer::Process_vkGetDeviceBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkDeviceBufferMemoryRequirements(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
/* pMemoryRequirements */
    std::string pMemoryRequirementsName = "pMemoryRequirements_" + std::to_string(this->getNextId());
    std::stringstream stream_pMemoryRequirements;
    pMemoryRequirementsName = GenerateStruct_VkMemoryRequirements2(stream_pMemoryRequirements,
                                                             pMemoryRequirements->GetPointer(),
                                                             pMemoryRequirements->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pMemoryRequirements.str().c_str());
    fprintf(file,
            "vkGetDeviceBufferMemoryRequirements(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str(),
            pMemoryRequirementsName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements);
}

void VulkanCppConsumer::Process_vkGetDeviceImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkDeviceImageMemoryRequirements(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
/* pMemoryRequirements */
    std::string pMemoryRequirementsName = "pMemoryRequirements_" + std::to_string(this->getNextId());
    std::stringstream stream_pMemoryRequirements;
    pMemoryRequirementsName = GenerateStruct_VkMemoryRequirements2(stream_pMemoryRequirements,
                                                             pMemoryRequirements->GetPointer(),
                                                             pMemoryRequirements->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pMemoryRequirements.str().c_str());
    fprintf(file,
            "vkGetDeviceImageMemoryRequirements(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str(),
            pMemoryRequirementsName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements);
}

void VulkanCppConsumer::Process_vkGetDeviceImageSparseMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkDeviceImageMemoryRequirements(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
/* pSparseMemoryRequirementCount */
    std::string pSparseMemoryRequirementCountName = "pSparseMemoryRequirementCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pSparseMemoryRequirementCountName.c_str());
/* pSparseMemoryRequirements */
    std::string pSparseMemoryRequirementsName = "pSparseMemoryRequirements_" + std::to_string(this->getNextId());
    std::stringstream stream_pSparseMemoryRequirements;
    pSparseMemoryRequirementsName = GenerateStruct_VkSparseImageMemoryRequirements2(stream_pSparseMemoryRequirements,
                                                                   pSparseMemoryRequirements->GetPointer(),
                                                                   pSparseMemoryRequirements->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pSparseMemoryRequirements.str().c_str());
    fprintf(file,
            "vkGetDeviceImageSparseMemoryRequirements(%s, &%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str(),
            pSparseMemoryRequirementCountName.c_str(),
            pSparseMemoryRequirementsName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceToolProperties(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pToolCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pToolCount */
    std::string pToolCountName = "pToolCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pToolCountName.c_str());
/* pToolProperties */
    std::string pToolPropertiesName = "pToolProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pToolProperties;
    pToolPropertiesName = GenerateStruct_VkPhysicalDeviceToolProperties(stream_pToolProperties,
                                                         pToolProperties->GetPointer(),
                                                         pToolProperties->GetMetaStructPointer(),
                                                         *this);
    fprintf(file, "\n%s", stream_pToolProperties.str().c_str());
    fprintf(file,
            "VK_CALL_CHECK(vkGetPhysicalDeviceToolProperties(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pToolCountName.c_str(),
            pToolPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties);
}

void VulkanCppConsumer::Process_vkGetPrivateData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    PointerDecoder<uint64_t>*                   pData)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* objectType */
/* objectHandle */
/* privateDataSlot */
/* pData */
    std::string pDataName = "pData_" + std::to_string(this->getNextId());
    fprintf(file, "uint64_t %s;\n", pDataName.c_str());
    fprintf(file,
            "vkGetPrivateData(%s, %s, %luUL, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkObjectType>(objectType).c_str(),
            objectHandle,
            this->GetHandle(privateDataSlot).c_str(),
            pDataName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPrivateData);
}

void VulkanCppConsumer::Process_vkQueueSubmit2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
    format::HandleId                            fence)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* queue */
/* submitCount */
/* pSubmits */
    std::stringstream stream_pSubmits;
    std::string pSubmitsArray = "NULL";
    PointerPairContainer<decltype(pSubmits->GetPointer()), decltype(pSubmits->GetMetaStructPointer())> pSubmitsPair{ pSubmits->GetPointer(), pSubmits->GetMetaStructPointer(), submitCount };
    std::string pSubmitsNames = toStringJoin(pSubmitsPair.begin(),
                                             pSubmitsPair.end(),
                                             [&](auto pair) { return GenerateStruct_VkSubmitInfo2(stream_pSubmits, pair.t1, pair.t2, *this); },
                                             ", ");
    fprintf(file, "\n%s", stream_pSubmits.str().c_str());
    if (submitCount == 1) {
        pSubmitsArray = "&" + pSubmitsNames;
    } else if (submitCount > 1) {
        pSubmitsArray = "pSubmits_" + std::to_string(this->getNextId());
        fprintf(file, "VkSubmitInfo2 %s[] = { %s };\n", pSubmitsArray.c_str(), pSubmitsNames.c_str());
    }
/* fence */
    fprintf(file,
            "VK_CALL_CHECK(vkQueueSubmit2(%s, %u, %s, %s), %s);\n",
            this->GetHandle(queue).c_str(),
            submitCount,
            pSubmitsArray.c_str(),
            this->GetHandle(fence).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkQueueSubmit2);
}

void VulkanCppConsumer::Process_vkSetPrivateData(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    uint64_t                                    data)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* objectType */
/* objectHandle */
/* privateDataSlot */
/* data */
    fprintf(file,
            "VK_CALL_CHECK(vkSetPrivateData(%s, %s, %luUL, %s, %luUL), %s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkObjectType>(objectType).c_str(),
            objectHandle,
            this->GetHandle(privateDataSlot).c_str(),
            data,
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSetPrivateData);
}

void VulkanCppConsumer::Process_vkDestroySurfaceKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* instance */
/* surface */
/* pAllocator */
    m_pfnLoader.AddMethodName("vkDestroySurfaceKHR");
    fprintf(file,
            "loaded_vkDestroySurfaceKHR(%s, %s, %s);\n",
            this->GetHandle(instance).c_str(),
            this->GetHandle(surface).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySurfaceKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* surface */
/* pSurfaceCapabilities */
    std::string pSurfaceCapabilitiesName = "pSurfaceCapabilities_" + std::to_string(this->getNextId());
    fprintf(file, "VkSurfaceCapabilitiesKHR %s;\n", pSurfaceCapabilitiesName.c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(%s, %s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            this->GetHandle(surface).c_str(),
            pSurfaceCapabilitiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormatKHR>* pSurfaceFormats)
{
    Generate_vkGetPhysicalDeviceSurfaceFormatsKHR(returnValue, physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>*           pPresentModes)
{
    Generate_vkGetPhysicalDeviceSurfacePresentModesKHR(returnValue, physicalDevice, surface, pPresentModeCount, pPresentModes);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceSurfaceSupportKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    format::HandleId                            surface,
    PointerDecoder<VkBool32>*                   pSupported)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* queueFamilyIndex */
/* surface */
/* pSupported */
    std::string pSupportedName = "pSupported_" + std::to_string(this->getNextId());
    fprintf(file, "VkBool32 %s;\n", pSupportedName.c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceSurfaceSupportKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfaceSupportKHR(%s, %u, %s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            queueFamilyIndex,
            this->GetHandle(surface).c_str(),
            pSupportedName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR);
}

void VulkanCppConsumer::Process_vkAcquireNextImage2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    Generate_vkAcquireNextImage2KHR(returnValue, device, pAcquireInfo, pImageIndex);
    Post_APICall(format::ApiCallId::ApiCall_vkAcquireNextImage2KHR);
}

void VulkanCppConsumer::Process_vkAcquireNextImageKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    uint64_t                                    timeout,
    format::HandleId                            semaphore,
    format::HandleId                            fence,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    Generate_vkAcquireNextImageKHR(returnValue, device, swapchain, timeout, semaphore, fence, pImageIndex);
    Post_APICall(format::ApiCallId::ApiCall_vkAcquireNextImageKHR);
}

void VulkanCppConsumer::Process_vkCreateSwapchainKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchain)
{
    Intercept_vkCreateSwapchainKHR(returnValue, device, pCreateInfo, pAllocator, pSwapchain);
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkSwapchainCreateInfoKHR(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pSwapchain */
    std::string pSwapchainName = "pSwapchain_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_SWAPCHAIN_KHR));
    AddKnownVariables("VkSwapchainKHR", pSwapchainName, pSwapchain->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pSwapchainName,
                         pSwapchain->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateSwapchainKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateSwapchainKHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pSwapchainName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateSwapchainKHR);
}

void VulkanCppConsumer::Process_vkDestroySwapchainKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* swapchain */
/* pAllocator */
    m_pfnLoader.AddMethodName("vkDestroySwapchainKHR");
    fprintf(file,
            "loaded_vkDestroySwapchainKHR(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapchain).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySwapchainKHR);
}

void VulkanCppConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pDeviceGroupPresentCapabilities */
    std::string pDeviceGroupPresentCapabilitiesName = "pDeviceGroupPresentCapabilities_" + std::to_string(this->getNextId());
    std::stringstream stream_pDeviceGroupPresentCapabilities;
    pDeviceGroupPresentCapabilitiesName = GenerateStruct_VkDeviceGroupPresentCapabilitiesKHR(stream_pDeviceGroupPresentCapabilities,
                                                                         pDeviceGroupPresentCapabilities->GetPointer(),
                                                                         pDeviceGroupPresentCapabilities->GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "\n%s", stream_pDeviceGroupPresentCapabilities.str().c_str());
    m_pfnLoader.AddMethodName("vkGetDeviceGroupPresentCapabilitiesKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetDeviceGroupPresentCapabilitiesKHR(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pDeviceGroupPresentCapabilitiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR);
}

void VulkanCppConsumer::Process_vkGetDeviceGroupSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            surface,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* surface */
/* pModes */
    std::string pModesName = "pModes_" + std::to_string(this->getNextId());
    fprintf(file, "VkDeviceGroupPresentModeFlagsKHR %s;\n", pModesName.c_str());
    m_pfnLoader.AddMethodName("vkGetDeviceGroupSurfacePresentModesKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetDeviceGroupSurfacePresentModesKHR(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(surface).c_str(),
            pModesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDevicePresentRectanglesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pRectCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pRects)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* surface */
/* pRectCount */
    std::string pRectCountName = "pRectCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pRectCountName.c_str());
/* pRects */
    std::string pRectsName = "pRects_" + std::to_string(this->getNextId());
    const uint32_t* in_pRectCount = pRectCount->GetPointer();
    fprintf(file, "VkRect2D %s[%d];\n", pRectsName.c_str(), *in_pRectCount);
    m_pfnLoader.AddMethodName("vkGetPhysicalDevicePresentRectanglesKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDevicePresentRectanglesKHR(%s, %s, &%s, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            this->GetHandle(surface).c_str(),
            pRectCountName.c_str(),
            pRectsName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR);
}

void VulkanCppConsumer::Process_vkGetSwapchainImagesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    PointerDecoder<uint32_t>*                   pSwapchainImageCount,
    HandlePointerDecoder<VkImage>*              pSwapchainImages)
{
    Generate_vkGetSwapchainImagesKHR(returnValue, device, swapchain, pSwapchainImageCount, pSwapchainImages);
    Post_APICall(format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR);
}

void VulkanCppConsumer::Process_vkQueuePresentKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* queue */
/* pPresentInfo */
    std::stringstream stream_pPresentInfo;
    std::string pPresentInfoStruct = GenerateStruct_VkPresentInfoKHR(stream_pPresentInfo,
                                                                    pPresentInfo->GetPointer(),
                                                                    pPresentInfo->GetMetaStructPointer(),
                                                                    *this);
    fprintf(file, "\n%s", stream_pPresentInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkQueuePresentKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkQueuePresentKHR(%s, &%s), %s);\n",
            this->GetHandle(queue).c_str(),
            pPresentInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkQueuePresentKHR);
}

void VulkanCppConsumer::Process_vkCreateDisplayModeKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDisplayModeKHR>*     pMode)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* display */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkDisplayModeCreateInfoKHR(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pMode */
    std::string pModeName = "pMode_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_DISPLAY_MODE_KHR));
    AddKnownVariables("VkDisplayModeKHR", pModeName, pMode->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pModeName,
                         pMode->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateDisplayModeKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateDisplayModeKHR(%s, %s, &%s, %s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            this->GetHandle(display).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pModeName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDisplayModeKHR);
}

void VulkanCppConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* instance */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkDisplaySurfaceCreateInfoKHR(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pSurface */
    std::string pSurfaceName = "pSurface_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", pSurfaceName, pSurface->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pSurfaceName,
                         pSurface->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateDisplayPlaneSurfaceKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateDisplayPlaneSurfaceKHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pSurfaceName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR);
}

void VulkanCppConsumer::Process_vkGetDisplayModePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* display */
/* pPropertyCount */
    std::string pPropertyCountName = "pPropertyCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pPropertyCountName.c_str());
/* pProperties */
    std::string pPropertiesName = "pProperties_" + std::to_string(this->getNextId());
    const uint32_t* in_pPropertyCount = pPropertyCount->GetPointer();
    fprintf(file, "VkDisplayModePropertiesKHR %s[%d];\n", pPropertiesName.c_str(), *in_pPropertyCount);
    m_pfnLoader.AddMethodName("vkGetDisplayModePropertiesKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetDisplayModePropertiesKHR(%s, %s, &%s, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            this->GetHandle(display).c_str(),
            pPropertyCountName.c_str(),
            pPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR);
}

void VulkanCppConsumer::Process_vkGetDisplayPlaneCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            mode,
    uint32_t                                    planeIndex,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>* pCapabilities)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* mode */
/* planeIndex */
/* pCapabilities */
    std::string pCapabilitiesName = "pCapabilities_" + std::to_string(this->getNextId());
    fprintf(file, "VkDisplayPlaneCapabilitiesKHR %s;\n", pCapabilitiesName.c_str());
    m_pfnLoader.AddMethodName("vkGetDisplayPlaneCapabilitiesKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetDisplayPlaneCapabilitiesKHR(%s, %s, %u, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            this->GetHandle(mode).c_str(),
            planeIndex,
            pCapabilitiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR);
}

void VulkanCppConsumer::Process_vkGetDisplayPlaneSupportedDisplaysKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    planeIndex,
    PointerDecoder<uint32_t>*                   pDisplayCount,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplays)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* planeIndex */
/* pDisplayCount */
    std::string pDisplayCountName = "pDisplayCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pDisplayCountName.c_str());
/* pDisplays */
    std::string pDisplaysName = "pDisplays_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_DISPLAY_KHR));
    AddKnownVariables("VkDisplayKHR", pDisplaysName, pDisplays->GetPointer(), *pDisplayCount->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pDisplaysName,
                         pDisplays->GetPointer(), *pDisplayCount->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkGetDisplayPlaneSupportedDisplaysKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetDisplayPlaneSupportedDisplaysKHR(%s, %u, &%s, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            planeIndex,
            pDisplayCountName.c_str(),
            pDisplaysName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pPropertyCount */
    std::string pPropertyCountName = "pPropertyCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pPropertyCountName.c_str());
/* pProperties */
    std::string pPropertiesName = "pProperties_" + std::to_string(this->getNextId());
    const uint32_t* in_pPropertyCount = pPropertyCount->GetPointer();
    fprintf(file, "VkDisplayPlanePropertiesKHR %s[%d];\n", pPropertiesName.c_str(), *in_pPropertyCount);
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(%s, &%s, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pPropertyCountName.c_str(),
            pPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pPropertyCount */
    std::string pPropertyCountName = "pPropertyCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pPropertyCountName.c_str());
/* pProperties */
    std::string pPropertiesName = "pProperties_" + std::to_string(this->getNextId());
    const uint32_t* in_pPropertyCount = pPropertyCount->GetPointer();
    fprintf(file, "VkDisplayPropertiesKHR %s[%d];\n", pPropertiesName.c_str(), *in_pPropertyCount);
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceDisplayPropertiesKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceDisplayPropertiesKHR(%s, &%s, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pPropertyCountName.c_str(),
            pPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR);
}

void VulkanCppConsumer::Process_vkCreateSharedSwapchainsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    swapchainCount,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* swapchainCount */
/* pCreateInfos */
    std::stringstream stream_pCreateInfos;
    std::string pCreateInfosArray = "NULL";
    PointerPairContainer<decltype(pCreateInfos->GetPointer()), decltype(pCreateInfos->GetMetaStructPointer())> pCreateInfosPair{ pCreateInfos->GetPointer(), pCreateInfos->GetMetaStructPointer(), swapchainCount };
    std::string pCreateInfosNames = toStringJoin(pCreateInfosPair.begin(),
                                                 pCreateInfosPair.end(),
                                                 [&](auto pair) { return GenerateStruct_VkSwapchainCreateInfoKHR(stream_pCreateInfos, pair.t1, pair.t2, *this); },
                                                 ", ");
    fprintf(file, "\n%s", stream_pCreateInfos.str().c_str());
    if (swapchainCount == 1) {
        pCreateInfosArray = "&" + pCreateInfosNames;
    } else if (swapchainCount > 1) {
        pCreateInfosArray = "pCreateInfos_" + std::to_string(this->getNextId());
        fprintf(file, "VkSwapchainCreateInfoKHR %s[] = { %s };\n", pCreateInfosArray.c_str(), pCreateInfosNames.c_str());
    }
/* pAllocator */
/* pSwapchains */
    std::string pSwapchainsName = "pSwapchains_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_SWAPCHAIN_KHR));
    AddKnownVariables("VkSwapchainKHR", pSwapchainsName, pSwapchains->GetPointer(), swapchainCount);
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pSwapchainsName,
                         pSwapchains->GetPointer(), swapchainCount);
    }
    m_pfnLoader.AddMethodName("vkCreateSharedSwapchainsKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateSharedSwapchainsKHR(%s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            swapchainCount,
            pCreateInfosArray.c_str(),
            "nullptr",
            pSwapchainsName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR);
}

void VulkanCppConsumer::Process_vkCreateXlibSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* instance */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkXlibSurfaceCreateInfoKHR(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pSurface */
    std::string pSurfaceName = "pSurface_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", pSurfaceName, pSurface->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pSurfaceName,
                         pSurface->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateXlibSurfaceKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateXlibSurfaceKHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pSurfaceName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    dpy,
    size_t                                      visualID)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* queueFamilyIndex */
/* dpy */
    std::string dpyName = "dpy_" + std::to_string(this->getNextId());
    fprintf(file, "void* %s;\n", dpyName.c_str());
/* visualID */
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceXlibPresentationSupportKHR");
    fprintf(file,
            "loaded_vkGetPhysicalDeviceXlibPresentationSupportKHR(%s, %u, %s, %lu);\n",
            this->GetHandle(physicalDevice).c_str(),
            queueFamilyIndex,
            dpyName.c_str(),
            visualID);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR);
}

void VulkanCppConsumer::Process_vkCreateXcbSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    Generate_vkCreateXcbSurfaceKHR(returnValue, instance, pCreateInfo, pAllocator, pSurface);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    connection,
    uint32_t                                    visual_id)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* queueFamilyIndex */
/* connection */
    std::string connectionName = "connection_" + std::to_string(this->getNextId());
    fprintf(file, "void* %s;\n", connectionName.c_str());
/* visual_id */
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceXcbPresentationSupportKHR");
    fprintf(file,
            "loaded_vkGetPhysicalDeviceXcbPresentationSupportKHR(%s, %u, %s, %u);\n",
            this->GetHandle(physicalDevice).c_str(),
            queueFamilyIndex,
            connectionName.c_str(),
            visual_id);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR);
}

void VulkanCppConsumer::Process_vkCreateWaylandSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    Generate_vkCreateWaylandSurfaceKHR(returnValue, instance, pCreateInfo, pAllocator, pSurface);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    display)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* queueFamilyIndex */
/* display */
    std::string displayName = "display_" + std::to_string(this->getNextId());
    fprintf(file, "void* %s;\n", displayName.c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceWaylandPresentationSupportKHR");
    fprintf(file,
            "loaded_vkGetPhysicalDeviceWaylandPresentationSupportKHR(%s, %u, %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            queueFamilyIndex,
            displayName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR);
}

void VulkanCppConsumer::Process_vkCreateAndroidSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    Generate_vkCreateAndroidSurfaceKHR(returnValue, instance, pCreateInfo, pAllocator, pSurface);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR);
}

void VulkanCppConsumer::Process_vkCreateWin32SurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* instance */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkWin32SurfaceCreateInfoKHR(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pSurface */
    std::string pSurfaceName = "pSurface_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", pSurfaceName, pSurface->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pSurfaceName,
                         pSurface->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateWin32SurfaceKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateWin32SurfaceKHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pSurfaceName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* queueFamilyIndex */
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceWin32PresentationSupportKHR");
    fprintf(file,
            "loaded_vkGetPhysicalDeviceWin32PresentationSupportKHR(%s, %u);\n",
            this->GetHandle(physicalDevice).c_str(),
            queueFamilyIndex);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR);
}


void VulkanCppConsumer::Process_vkBindVideoSessionMemoryKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    uint32_t                                    bindSessionMemoryInfoCount,
    StructPointerDecoder<Decoded_VkBindVideoSessionMemoryInfoKHR>* pBindSessionMemoryInfos)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* videoSession */
/* bindSessionMemoryInfoCount */
/* pBindSessionMemoryInfos */
    std::stringstream stream_pBindSessionMemoryInfos;
    std::string pBindSessionMemoryInfosArray = "NULL";
    PointerPairContainer<decltype(pBindSessionMemoryInfos->GetPointer()), decltype(pBindSessionMemoryInfos->GetMetaStructPointer())> pBindSessionMemoryInfosPair{ pBindSessionMemoryInfos->GetPointer(), pBindSessionMemoryInfos->GetMetaStructPointer(), bindSessionMemoryInfoCount };
    std::string pBindSessionMemoryInfosNames = toStringJoin(pBindSessionMemoryInfosPair.begin(),
                                                            pBindSessionMemoryInfosPair.end(),
                                                            [&](auto pair) { return GenerateStruct_VkBindVideoSessionMemoryInfoKHR(stream_pBindSessionMemoryInfos, pair.t1, pair.t2, *this); },
                                                            ", ");
    fprintf(file, "\n%s", stream_pBindSessionMemoryInfos.str().c_str());
    if (bindSessionMemoryInfoCount == 1) {
        pBindSessionMemoryInfosArray = "&" + pBindSessionMemoryInfosNames;
    } else if (bindSessionMemoryInfoCount > 1) {
        pBindSessionMemoryInfosArray = "pBindSessionMemoryInfos_" + std::to_string(this->getNextId());
        fprintf(file, "VkBindVideoSessionMemoryInfoKHR %s[] = { %s };\n", pBindSessionMemoryInfosArray.c_str(), pBindSessionMemoryInfosNames.c_str());
    }
    m_pfnLoader.AddMethodName("vkBindVideoSessionMemoryKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkBindVideoSessionMemoryKHR(%s, %s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(videoSession).c_str(),
            bindSessionMemoryInfoCount,
            pBindSessionMemoryInfosArray.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR);
}

void VulkanCppConsumer::Process_vkCmdBeginVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR>* pBeginInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pBeginInfo */
    std::stringstream stream_pBeginInfo;
    std::string pBeginInfoStruct = GenerateStruct_VkVideoBeginCodingInfoKHR(stream_pBeginInfo,
                                                                  pBeginInfo->GetPointer(),
                                                                  pBeginInfo->GetMetaStructPointer(),
                                                                  *this);
    fprintf(file, "\n%s", stream_pBeginInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdBeginVideoCodingKHR");
    fprintf(file,
            "loaded_vkCmdBeginVideoCodingKHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pBeginInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR);
}

void VulkanCppConsumer::Process_vkCmdControlVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR>* pCodingControlInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pCodingControlInfo */
    std::stringstream stream_pCodingControlInfo;
    std::string pCodingControlInfoStruct = GenerateStruct_VkVideoCodingControlInfoKHR(stream_pCodingControlInfo,
                                                                          pCodingControlInfo->GetPointer(),
                                                                          pCodingControlInfo->GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "\n%s", stream_pCodingControlInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdControlVideoCodingKHR");
    fprintf(file,
            "loaded_vkCmdControlVideoCodingKHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pCodingControlInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR);
}

void VulkanCppConsumer::Process_vkCmdEndVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR>* pEndCodingInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pEndCodingInfo */
    std::stringstream stream_pEndCodingInfo;
    std::string pEndCodingInfoStruct = GenerateStruct_VkVideoEndCodingInfoKHR(stream_pEndCodingInfo,
                                                                      pEndCodingInfo->GetPointer(),
                                                                      pEndCodingInfo->GetMetaStructPointer(),
                                                                      *this);
    fprintf(file, "\n%s", stream_pEndCodingInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdEndVideoCodingKHR");
    fprintf(file,
            "loaded_vkCmdEndVideoCodingKHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pEndCodingInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR);
}

void VulkanCppConsumer::Process_vkCreateVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkVideoSessionCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkVideoSessionKHR>*    pVideoSession)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkVideoSessionCreateInfoKHR(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pVideoSession */
    std::string pVideoSessionName = "pVideoSession_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_VIDEO_SESSION_KHR));
    AddKnownVariables("VkVideoSessionKHR", pVideoSessionName, pVideoSession->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pVideoSessionName,
                         pVideoSession->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateVideoSessionKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateVideoSessionKHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pVideoSessionName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateVideoSessionKHR);
}

void VulkanCppConsumer::Process_vkCreateVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkVideoSessionParametersCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkVideoSessionParametersKHR>* pVideoSessionParameters)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkVideoSessionParametersCreateInfoKHR(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pVideoSessionParameters */
    std::string pVideoSessionParametersName = "pVideoSessionParameters_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_VIDEO_SESSION_PARAMETERS_KHR));
    AddKnownVariables("VkVideoSessionParametersKHR", pVideoSessionParametersName, pVideoSessionParameters->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pVideoSessionParametersName,
                         pVideoSessionParameters->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateVideoSessionParametersKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateVideoSessionParametersKHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pVideoSessionParametersName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR);
}

void VulkanCppConsumer::Process_vkDestroyVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* videoSession */
/* pAllocator */
    m_pfnLoader.AddMethodName("vkDestroyVideoSessionKHR");
    fprintf(file,
            "loaded_vkDestroyVideoSessionKHR(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(videoSession).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR);
}

void VulkanCppConsumer::Process_vkDestroyVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            videoSessionParameters,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* videoSessionParameters */
/* pAllocator */
    m_pfnLoader.AddMethodName("vkDestroyVideoSessionParametersKHR");
    fprintf(file,
            "loaded_vkDestroyVideoSessionParametersKHR(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(videoSessionParameters).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceVideoCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkVideoProfileInfoKHR>* pVideoProfile,
    StructPointerDecoder<Decoded_VkVideoCapabilitiesKHR>* pCapabilities)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pVideoProfile */
    std::stringstream stream_pVideoProfile;
    std::string pVideoProfileStruct = GenerateStruct_VkVideoProfileInfoKHR(stream_pVideoProfile,
                                                                     pVideoProfile->GetPointer(),
                                                                     pVideoProfile->GetMetaStructPointer(),
                                                                     *this);
    fprintf(file, "\n%s", stream_pVideoProfile.str().c_str());
/* pCapabilities */
    std::string pCapabilitiesName = "pCapabilities_" + std::to_string(this->getNextId());
    std::stringstream stream_pCapabilities;
    pCapabilitiesName = GenerateStruct_VkVideoCapabilitiesKHR(stream_pCapabilities,
                                                       pCapabilities->GetPointer(),
                                                       pCapabilities->GetMetaStructPointer(),
                                                       *this);
    fprintf(file, "\n%s", stream_pCapabilities.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceVideoCapabilitiesKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceVideoCapabilitiesKHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pVideoProfileStruct.c_str(),
            pCapabilitiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceVideoFormatPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceVideoFormatInfoKHR>* pVideoFormatInfo,
    PointerDecoder<uint32_t>*                   pVideoFormatPropertyCount,
    StructPointerDecoder<Decoded_VkVideoFormatPropertiesKHR>* pVideoFormatProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pVideoFormatInfo */
    std::stringstream stream_pVideoFormatInfo;
    std::string pVideoFormatInfoStruct = GenerateStruct_VkPhysicalDeviceVideoFormatInfoKHR(stream_pVideoFormatInfo,
                                                                        pVideoFormatInfo->GetPointer(),
                                                                        pVideoFormatInfo->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "\n%s", stream_pVideoFormatInfo.str().c_str());
/* pVideoFormatPropertyCount */
    std::string pVideoFormatPropertyCountName = "pVideoFormatPropertyCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pVideoFormatPropertyCountName.c_str());
/* pVideoFormatProperties */
    std::string pVideoFormatPropertiesName = "pVideoFormatProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pVideoFormatProperties;
    pVideoFormatPropertiesName = GenerateStruct_VkVideoFormatPropertiesKHR(stream_pVideoFormatProperties,
                                                                pVideoFormatProperties->GetPointer(),
                                                                pVideoFormatProperties->GetMetaStructPointer(),
                                                                *this);
    fprintf(file, "\n%s", stream_pVideoFormatProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceVideoFormatPropertiesKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceVideoFormatPropertiesKHR(%s, &%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pVideoFormatInfoStruct.c_str(),
            pVideoFormatPropertyCountName.c_str(),
            pVideoFormatPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR);
}

void VulkanCppConsumer::Process_vkGetVideoSessionMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    PointerDecoder<uint32_t>*                   pMemoryRequirementsCount,
    StructPointerDecoder<Decoded_VkVideoSessionMemoryRequirementsKHR>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* videoSession */
/* pMemoryRequirementsCount */
    std::string pMemoryRequirementsCountName = "pMemoryRequirementsCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pMemoryRequirementsCountName.c_str());
/* pMemoryRequirements */
    std::string pMemoryRequirementsName = "pMemoryRequirements_" + std::to_string(this->getNextId());
    std::stringstream stream_pMemoryRequirements;
    pMemoryRequirementsName = GenerateStruct_VkVideoSessionMemoryRequirementsKHR(stream_pMemoryRequirements,
                                                             pMemoryRequirements->GetPointer(),
                                                             pMemoryRequirements->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pMemoryRequirements.str().c_str());
    m_pfnLoader.AddMethodName("vkGetVideoSessionMemoryRequirementsKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetVideoSessionMemoryRequirementsKHR(%s, %s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(videoSession).c_str(),
            pMemoryRequirementsCountName.c_str(),
            pMemoryRequirementsName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR);
}

void VulkanCppConsumer::Process_vkUpdateVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            videoSessionParameters,
    StructPointerDecoder<Decoded_VkVideoSessionParametersUpdateInfoKHR>* pUpdateInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* videoSessionParameters */
/* pUpdateInfo */
    std::stringstream stream_pUpdateInfo;
    std::string pUpdateInfoStruct = GenerateStruct_VkVideoSessionParametersUpdateInfoKHR(stream_pUpdateInfo,
                                                                   pUpdateInfo->GetPointer(),
                                                                   pUpdateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pUpdateInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkUpdateVideoSessionParametersKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkUpdateVideoSessionParametersKHR(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(videoSessionParameters).c_str(),
            pUpdateInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR);
}

void VulkanCppConsumer::Process_vkCmdDecodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR>* pDecodeInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pDecodeInfo */
    std::stringstream stream_pDecodeInfo;
    std::string pDecodeInfoStruct = GenerateStruct_VkVideoDecodeInfoKHR(stream_pDecodeInfo,
                                                                   pDecodeInfo->GetPointer(),
                                                                   pDecodeInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pDecodeInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdDecodeVideoKHR");
    fprintf(file,
            "loaded_vkCmdDecodeVideoKHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pDecodeInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR);
}


void VulkanCppConsumer::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pRenderingInfo */
    std::stringstream stream_pRenderingInfo;
    std::string pRenderingInfoStruct = GenerateStruct_VkRenderingInfo(stream_pRenderingInfo,
                                                                      pRenderingInfo->GetPointer(),
                                                                      pRenderingInfo->GetMetaStructPointer(),
                                                                      *this);
    fprintf(file, "\n%s", stream_pRenderingInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdBeginRenderingKHR");
    fprintf(file,
            "loaded_vkCmdBeginRenderingKHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pRenderingInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR);
}

void VulkanCppConsumer::Process_vkCmdEndRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
    m_pfnLoader.AddMethodName("vkCmdEndRenderingKHR");
    fprintf(file,
            "loaded_vkCmdEndRenderingKHR(%s);\n",
            this->GetHandle(commandBuffer).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRenderingKHR);
}


void VulkanCppConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pFeatures */
    std::string pFeaturesName = "pFeatures_" + std::to_string(this->getNextId());
    std::stringstream stream_pFeatures;
    pFeaturesName = GenerateStruct_VkPhysicalDeviceFeatures2(stream_pFeatures,
                                                   pFeatures->GetPointer(),
                                                   pFeatures->GetMetaStructPointer(),
                                                   *this);
    fprintf(file, "\n%s", stream_pFeatures.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceFeatures2KHR");
    fprintf(file,
            "loaded_vkGetPhysicalDeviceFeatures2KHR(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pFeaturesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* format */
/* pFormatProperties */
    std::string pFormatPropertiesName = "pFormatProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pFormatProperties;
    pFormatPropertiesName = GenerateStruct_VkFormatProperties2(stream_pFormatProperties,
                                                           pFormatProperties->GetPointer(),
                                                           pFormatProperties->GetMetaStructPointer(),
                                                           *this);
    fprintf(file, "\n%s", stream_pFormatProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceFormatProperties2KHR");
    fprintf(file,
            "loaded_vkGetPhysicalDeviceFormatProperties2KHR(%s, %s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            util::ToString<VkFormat>(format).c_str(),
            pFormatPropertiesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pImageFormatInfo */
    std::stringstream stream_pImageFormatInfo;
    std::string pImageFormatInfoStruct = GenerateStruct_VkPhysicalDeviceImageFormatInfo2(stream_pImageFormatInfo,
                                                                        pImageFormatInfo->GetPointer(),
                                                                        pImageFormatInfo->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "\n%s", stream_pImageFormatInfo.str().c_str());
/* pImageFormatProperties */
    std::string pImageFormatPropertiesName = "pImageFormatProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pImageFormatProperties;
    pImageFormatPropertiesName = GenerateStruct_VkImageFormatProperties2(stream_pImageFormatProperties,
                                                                pImageFormatProperties->GetPointer(),
                                                                pImageFormatProperties->GetMetaStructPointer(),
                                                                *this);
    fprintf(file, "\n%s", stream_pImageFormatProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceImageFormatProperties2KHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceImageFormatProperties2KHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pImageFormatInfoStruct.c_str(),
            pImageFormatPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pMemoryProperties */
    std::string pMemoryPropertiesName = "pMemoryProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pMemoryProperties;
    pMemoryPropertiesName = GenerateStruct_VkPhysicalDeviceMemoryProperties2(stream_pMemoryProperties,
                                                           pMemoryProperties->GetPointer(),
                                                           pMemoryProperties->GetMetaStructPointer(),
                                                           *this);
    fprintf(file, "\n%s", stream_pMemoryProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceMemoryProperties2KHR");
    fprintf(file,
            "loaded_vkGetPhysicalDeviceMemoryProperties2KHR(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pMemoryPropertiesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pProperties */
    std::string pPropertiesName = "pProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pProperties;
    pPropertiesName = GenerateStruct_VkPhysicalDeviceProperties2(stream_pProperties,
                                                     pProperties->GetPointer(),
                                                     pProperties->GetMetaStructPointer(),
                                                     *this);
    fprintf(file, "\n%s", stream_pProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceProperties2KHR");
    fprintf(file,
            "loaded_vkGetPhysicalDeviceProperties2KHR(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pPropertiesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pQueueFamilyPropertyCount */
    std::string pQueueFamilyPropertyCountName = "pQueueFamilyPropertyCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pQueueFamilyPropertyCountName.c_str());
/* pQueueFamilyProperties */
    std::string pQueueFamilyPropertiesName = "pQueueFamilyProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pQueueFamilyProperties;
    pQueueFamilyPropertiesName = GenerateStruct_VkQueueFamilyProperties2(stream_pQueueFamilyProperties,
                                                                pQueueFamilyProperties->GetPointer(),
                                                                pQueueFamilyProperties->GetMetaStructPointer(),
                                                                *this);
    fprintf(file, "\n%s", stream_pQueueFamilyProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceQueueFamilyProperties2KHR");
    fprintf(file,
            "loaded_vkGetPhysicalDeviceQueueFamilyProperties2KHR(%s, &%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pQueueFamilyPropertyCountName.c_str(),
            pQueueFamilyPropertiesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pFormatInfo */
    std::stringstream stream_pFormatInfo;
    std::string pFormatInfoStruct = GenerateStruct_VkPhysicalDeviceSparseImageFormatInfo2(stream_pFormatInfo,
                                                                   pFormatInfo->GetPointer(),
                                                                   pFormatInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pFormatInfo.str().c_str());
/* pPropertyCount */
    std::string pPropertyCountName = "pPropertyCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pPropertyCountName.c_str());
/* pProperties */
    std::string pPropertiesName = "pProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pProperties;
    pPropertiesName = GenerateStruct_VkSparseImageFormatProperties2(stream_pProperties,
                                                     pProperties->GetPointer(),
                                                     pProperties->GetMetaStructPointer(),
                                                     *this);
    fprintf(file, "\n%s", stream_pProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceSparseImageFormatProperties2KHR");
    fprintf(file,
            "loaded_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(%s, &%s, &%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pFormatInfoStruct.c_str(),
            pPropertyCountName.c_str(),
            pPropertiesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR);
}

void VulkanCppConsumer::Process_vkCmdDispatchBaseKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* baseGroupX */
/* baseGroupY */
/* baseGroupZ */
/* groupCountX */
/* groupCountY */
/* groupCountZ */
    m_pfnLoader.AddMethodName("vkCmdDispatchBaseKHR");
    fprintf(file,
            "loaded_vkCmdDispatchBaseKHR(%s, %u, %u, %u, %u, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            baseGroupX,
            baseGroupY,
            baseGroupZ,
            groupCountX,
            groupCountY,
            groupCountZ);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR);
}

void VulkanCppConsumer::Process_vkCmdSetDeviceMaskKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* deviceMask */
    m_pfnLoader.AddMethodName("vkCmdSetDeviceMaskKHR");
    fprintf(file,
            "loaded_vkCmdSetDeviceMaskKHR(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            deviceMask);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR);
}

void VulkanCppConsumer::Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* heapIndex */
/* localDeviceIndex */
/* remoteDeviceIndex */
/* pPeerMemoryFeatures */
    std::string pPeerMemoryFeaturesName = "pPeerMemoryFeatures_" + std::to_string(this->getNextId());
    fprintf(file, "VkPeerMemoryFeatureFlags %s;\n", pPeerMemoryFeaturesName.c_str());
    m_pfnLoader.AddMethodName("vkGetDeviceGroupPeerMemoryFeaturesKHR");
    fprintf(file,
            "loaded_vkGetDeviceGroupPeerMemoryFeaturesKHR(%s, %u, %u, %u, &%s);\n",
            this->GetHandle(device).c_str(),
            heapIndex,
            localDeviceIndex,
            remoteDeviceIndex,
            pPeerMemoryFeaturesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR);
}


void VulkanCppConsumer::Process_vkTrimCommandPoolKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* commandPool */
/* flags */
    m_pfnLoader.AddMethodName("vkTrimCommandPoolKHR");
    fprintf(file,
            "loaded_vkTrimCommandPoolKHR(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(commandPool).c_str(),
            util::ToString<VkCommandPoolTrimFlags>(flags).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkTrimCommandPoolKHR);
}

void VulkanCppConsumer::Process_vkEnumeratePhysicalDeviceGroupsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* instance */
/* pPhysicalDeviceGroupCount */
    std::string pPhysicalDeviceGroupCountName = "pPhysicalDeviceGroupCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pPhysicalDeviceGroupCountName.c_str());
/* pPhysicalDeviceGroupProperties */
    std::string pPhysicalDeviceGroupPropertiesName = "pPhysicalDeviceGroupProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pPhysicalDeviceGroupProperties;
    pPhysicalDeviceGroupPropertiesName = GenerateStruct_VkPhysicalDeviceGroupProperties(stream_pPhysicalDeviceGroupProperties,
                                                                        pPhysicalDeviceGroupProperties->GetPointer(),
                                                                        pPhysicalDeviceGroupProperties->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "\n%s", stream_pPhysicalDeviceGroupProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkEnumeratePhysicalDeviceGroupsKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkEnumeratePhysicalDeviceGroupsKHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pPhysicalDeviceGroupCountName.c_str(),
            pPhysicalDeviceGroupPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pExternalBufferInfo */
    std::stringstream stream_pExternalBufferInfo;
    std::string pExternalBufferInfoStruct = GenerateStruct_VkPhysicalDeviceExternalBufferInfo(stream_pExternalBufferInfo,
                                                                           pExternalBufferInfo->GetPointer(),
                                                                           pExternalBufferInfo->GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "\n%s", stream_pExternalBufferInfo.str().c_str());
/* pExternalBufferProperties */
    std::string pExternalBufferPropertiesName = "pExternalBufferProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pExternalBufferProperties;
    pExternalBufferPropertiesName = GenerateStruct_VkExternalBufferProperties(stream_pExternalBufferProperties,
                                                                   pExternalBufferProperties->GetPointer(),
                                                                   pExternalBufferProperties->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pExternalBufferProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceExternalBufferPropertiesKHR");
    fprintf(file,
            "loaded_vkGetPhysicalDeviceExternalBufferPropertiesKHR(%s, &%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pExternalBufferInfoStruct.c_str(),
            pExternalBufferPropertiesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR);
}


void VulkanCppConsumer::Process_vkGetMemoryWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pGetWin32HandleInfo */
    std::stringstream stream_pGetWin32HandleInfo;
    std::string pGetWin32HandleInfoStruct = GenerateStruct_VkMemoryGetWin32HandleInfoKHR(stream_pGetWin32HandleInfo,
                                                                           pGetWin32HandleInfo->GetPointer(),
                                                                           pGetWin32HandleInfo->GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "\n%s", stream_pGetWin32HandleInfo.str().c_str());
/* pHandle */
    std::string pHandleName = "pHandle_" + std::to_string(this->getNextId());
    fprintf(file, "uint8_t* %s;\n", pHandleName.c_str());
    m_pfnLoader.AddMethodName("vkGetMemoryWin32HandleKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetMemoryWin32HandleKHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pGetWin32HandleInfoStruct.c_str(),
            pHandleName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR);
}

void VulkanCppConsumer::Process_vkGetMemoryWin32HandlePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    handle,
    StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR>* pMemoryWin32HandleProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* handleType */
/* handle */
    std::string handleName = "handle_" + std::to_string(this->getNextId());
    fprintf(file, "void* %s;\n", handleName.c_str());
/* pMemoryWin32HandleProperties */
    std::string pMemoryWin32HandlePropertiesName = "pMemoryWin32HandleProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pMemoryWin32HandleProperties;
    pMemoryWin32HandlePropertiesName = GenerateStruct_VkMemoryWin32HandlePropertiesKHR(stream_pMemoryWin32HandleProperties,
                                                                      pMemoryWin32HandleProperties->GetPointer(),
                                                                      pMemoryWin32HandleProperties->GetMetaStructPointer(),
                                                                      *this);
    fprintf(file, "\n%s", stream_pMemoryWin32HandleProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetMemoryWin32HandlePropertiesKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetMemoryWin32HandlePropertiesKHR(%s, %s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkExternalMemoryHandleTypeFlagBits>(handleType).c_str(),
            handleName.c_str(),
            pMemoryWin32HandlePropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR);
}

void VulkanCppConsumer::Process_vkGetMemoryFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pGetFdInfo */
    std::stringstream stream_pGetFdInfo;
    std::string pGetFdInfoStruct = GenerateStruct_VkMemoryGetFdInfoKHR(stream_pGetFdInfo,
                                                                  pGetFdInfo->GetPointer(),
                                                                  pGetFdInfo->GetMetaStructPointer(),
                                                                  *this);
    fprintf(file, "\n%s", stream_pGetFdInfo.str().c_str());
/* pFd */
    std::string pFdName = "pFd_" + std::to_string(this->getNextId());
    fprintf(file, "int %s;\n", pFdName.c_str());
    m_pfnLoader.AddMethodName("vkGetMemoryFdKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetMemoryFdKHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pGetFdInfoStruct.c_str(),
            pFdName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryFdKHR);
}

void VulkanCppConsumer::Process_vkGetMemoryFdPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>* pMemoryFdProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* handleType */
/* fd */
/* pMemoryFdProperties */
    std::string pMemoryFdPropertiesName = "pMemoryFdProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pMemoryFdProperties;
    pMemoryFdPropertiesName = GenerateStruct_VkMemoryFdPropertiesKHR(stream_pMemoryFdProperties,
                                                             pMemoryFdProperties->GetPointer(),
                                                             pMemoryFdProperties->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pMemoryFdProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetMemoryFdPropertiesKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetMemoryFdPropertiesKHR(%s, %s, %d, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkExternalMemoryHandleTypeFlagBits>(handleType).c_str(),
            fd,
            pMemoryFdPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR);
}


void VulkanCppConsumer::Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pExternalSemaphoreInfo */
    std::stringstream stream_pExternalSemaphoreInfo;
    std::string pExternalSemaphoreInfoStruct = GenerateStruct_VkPhysicalDeviceExternalSemaphoreInfo(stream_pExternalSemaphoreInfo,
                                                                              pExternalSemaphoreInfo->GetPointer(),
                                                                              pExternalSemaphoreInfo->GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "\n%s", stream_pExternalSemaphoreInfo.str().c_str());
/* pExternalSemaphoreProperties */
    std::string pExternalSemaphorePropertiesName = "pExternalSemaphoreProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pExternalSemaphoreProperties;
    pExternalSemaphorePropertiesName = GenerateStruct_VkExternalSemaphoreProperties(stream_pExternalSemaphoreProperties,
                                                                      pExternalSemaphoreProperties->GetPointer(),
                                                                      pExternalSemaphoreProperties->GetMetaStructPointer(),
                                                                      *this);
    fprintf(file, "\n%s", stream_pExternalSemaphoreProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceExternalSemaphorePropertiesKHR");
    fprintf(file,
            "loaded_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(%s, &%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pExternalSemaphoreInfoStruct.c_str(),
            pExternalSemaphorePropertiesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR);
}


void VulkanCppConsumer::Process_vkGetSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pGetWin32HandleInfo */
    std::stringstream stream_pGetWin32HandleInfo;
    std::string pGetWin32HandleInfoStruct = GenerateStruct_VkSemaphoreGetWin32HandleInfoKHR(stream_pGetWin32HandleInfo,
                                                                           pGetWin32HandleInfo->GetPointer(),
                                                                           pGetWin32HandleInfo->GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "\n%s", stream_pGetWin32HandleInfo.str().c_str());
/* pHandle */
    std::string pHandleName = "pHandle_" + std::to_string(this->getNextId());
    fprintf(file, "uint8_t* %s;\n", pHandleName.c_str());
    m_pfnLoader.AddMethodName("vkGetSemaphoreWin32HandleKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetSemaphoreWin32HandleKHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pGetWin32HandleInfoStruct.c_str(),
            pHandleName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR);
}

void VulkanCppConsumer::Process_vkImportSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pImportSemaphoreWin32HandleInfo */
    std::stringstream stream_pImportSemaphoreWin32HandleInfo;
    std::string pImportSemaphoreWin32HandleInfoStruct = GenerateStruct_VkImportSemaphoreWin32HandleInfoKHR(stream_pImportSemaphoreWin32HandleInfo,
                                                                                       pImportSemaphoreWin32HandleInfo->GetPointer(),
                                                                                       pImportSemaphoreWin32HandleInfo->GetMetaStructPointer(),
                                                                                       *this);
    fprintf(file, "\n%s", stream_pImportSemaphoreWin32HandleInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkImportSemaphoreWin32HandleKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkImportSemaphoreWin32HandleKHR(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pImportSemaphoreWin32HandleInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR);
}

void VulkanCppConsumer::Process_vkGetSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pGetFdInfo */
    std::stringstream stream_pGetFdInfo;
    std::string pGetFdInfoStruct = GenerateStruct_VkSemaphoreGetFdInfoKHR(stream_pGetFdInfo,
                                                                  pGetFdInfo->GetPointer(),
                                                                  pGetFdInfo->GetMetaStructPointer(),
                                                                  *this);
    fprintf(file, "\n%s", stream_pGetFdInfo.str().c_str());
/* pFd */
    std::string pFdName = "pFd_" + std::to_string(this->getNextId());
    fprintf(file, "int %s;\n", pFdName.c_str());
    m_pfnLoader.AddMethodName("vkGetSemaphoreFdKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetSemaphoreFdKHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pGetFdInfoStruct.c_str(),
            pFdName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR);
}

void VulkanCppConsumer::Process_vkImportSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pImportSemaphoreFdInfo */
    std::stringstream stream_pImportSemaphoreFdInfo;
    std::string pImportSemaphoreFdInfoStruct = GenerateStruct_VkImportSemaphoreFdInfoKHR(stream_pImportSemaphoreFdInfo,
                                                                              pImportSemaphoreFdInfo->GetPointer(),
                                                                              pImportSemaphoreFdInfo->GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "\n%s", stream_pImportSemaphoreFdInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkImportSemaphoreFdKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkImportSemaphoreFdKHR(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pImportSemaphoreFdInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR);
}

void VulkanCppConsumer::Process_vkCmdPushDescriptorSetKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pipelineBindPoint */
/* layout */
/* set */
/* descriptorWriteCount */
/* pDescriptorWrites */
    std::stringstream stream_pDescriptorWrites;
    std::string pDescriptorWritesArray = "NULL";
    PointerPairContainer<decltype(pDescriptorWrites->GetPointer()), decltype(pDescriptorWrites->GetMetaStructPointer())> pDescriptorWritesPair{ pDescriptorWrites->GetPointer(), pDescriptorWrites->GetMetaStructPointer(), descriptorWriteCount };
    std::string pDescriptorWritesNames = toStringJoin(pDescriptorWritesPair.begin(),
                                                      pDescriptorWritesPair.end(),
                                                      [&](auto pair) { return GenerateStruct_VkWriteDescriptorSet(stream_pDescriptorWrites, pair.t1, pair.t2, *this); },
                                                      ", ");
    fprintf(file, "\n%s", stream_pDescriptorWrites.str().c_str());
    if (descriptorWriteCount == 1) {
        pDescriptorWritesArray = "&" + pDescriptorWritesNames;
    } else if (descriptorWriteCount > 1) {
        pDescriptorWritesArray = "pDescriptorWrites_" + std::to_string(this->getNextId());
        fprintf(file, "VkWriteDescriptorSet %s[] = { %s };\n", pDescriptorWritesArray.c_str(), pDescriptorWritesNames.c_str());
    }
    m_pfnLoader.AddMethodName("vkCmdPushDescriptorSetKHR");
    fprintf(file,
            "loaded_vkCmdPushDescriptorSetKHR(%s, %s, %s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineBindPoint>(pipelineBindPoint).c_str(),
            this->GetHandle(layout).c_str(),
            set,
            descriptorWriteCount,
            pDescriptorWritesArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR);
}




void VulkanCppConsumer::Process_vkCreateDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    Generate_vkCreateDescriptorUpdateTemplateKHR(returnValue, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR);
}

void VulkanCppConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* descriptorUpdateTemplate */
/* pAllocator */
    m_pfnLoader.AddMethodName("vkDestroyDescriptorUpdateTemplateKHR");
    fprintf(file,
            "loaded_vkDestroyDescriptorUpdateTemplateKHR(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(descriptorUpdateTemplate).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR);
}


void VulkanCppConsumer::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pRenderPassBegin */
    std::stringstream stream_pRenderPassBegin;
    std::string pRenderPassBeginStruct = GenerateStruct_VkRenderPassBeginInfo(stream_pRenderPassBegin,
                                                                        pRenderPassBegin->GetPointer(),
                                                                        pRenderPassBegin->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "\n%s", stream_pRenderPassBegin.str().c_str());
/* pSubpassBeginInfo */
    std::stringstream stream_pSubpassBeginInfo;
    std::string pSubpassBeginInfoStruct = GenerateStruct_VkSubpassBeginInfo(stream_pSubpassBeginInfo,
                                                                         pSubpassBeginInfo->GetPointer(),
                                                                         pSubpassBeginInfo->GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "\n%s", stream_pSubpassBeginInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdBeginRenderPass2KHR");
    fprintf(file,
            "loaded_vkCmdBeginRenderPass2KHR(%s, &%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pRenderPassBeginStruct.c_str(),
            pSubpassBeginInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR);
}

void VulkanCppConsumer::Process_vkCmdEndRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pSubpassEndInfo */
    std::stringstream stream_pSubpassEndInfo;
    std::string pSubpassEndInfoStruct = GenerateStruct_VkSubpassEndInfo(stream_pSubpassEndInfo,
                                                                       pSubpassEndInfo->GetPointer(),
                                                                       pSubpassEndInfo->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "\n%s", stream_pSubpassEndInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdEndRenderPass2KHR");
    fprintf(file,
            "loaded_vkCmdEndRenderPass2KHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pSubpassEndInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR);
}

void VulkanCppConsumer::Process_vkCmdNextSubpass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pSubpassBeginInfo */
    std::stringstream stream_pSubpassBeginInfo;
    std::string pSubpassBeginInfoStruct = GenerateStruct_VkSubpassBeginInfo(stream_pSubpassBeginInfo,
                                                                         pSubpassBeginInfo->GetPointer(),
                                                                         pSubpassBeginInfo->GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "\n%s", stream_pSubpassBeginInfo.str().c_str());
/* pSubpassEndInfo */
    std::stringstream stream_pSubpassEndInfo;
    std::string pSubpassEndInfoStruct = GenerateStruct_VkSubpassEndInfo(stream_pSubpassEndInfo,
                                                                       pSubpassEndInfo->GetPointer(),
                                                                       pSubpassEndInfo->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "\n%s", stream_pSubpassEndInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdNextSubpass2KHR");
    fprintf(file,
            "loaded_vkCmdNextSubpass2KHR(%s, &%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pSubpassBeginInfoStruct.c_str(),
            pSubpassEndInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR);
}

void VulkanCppConsumer::Process_vkCreateRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkRenderPassCreateInfo2(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pRenderPass */
    std::string pRenderPassName = "pRenderPass_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_RENDER_PASS));
    AddKnownVariables("VkRenderPass", pRenderPassName, pRenderPass->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pRenderPassName,
                         pRenderPass->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateRenderPass2KHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateRenderPass2KHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pRenderPassName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateRenderPass2KHR);
}

void VulkanCppConsumer::Process_vkGetSwapchainStatusKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* swapchain */
    m_pfnLoader.AddMethodName("vkGetSwapchainStatusKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetSwapchainStatusKHR(%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapchain).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pExternalFenceInfo */
    std::stringstream stream_pExternalFenceInfo;
    std::string pExternalFenceInfoStruct = GenerateStruct_VkPhysicalDeviceExternalFenceInfo(stream_pExternalFenceInfo,
                                                                          pExternalFenceInfo->GetPointer(),
                                                                          pExternalFenceInfo->GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "\n%s", stream_pExternalFenceInfo.str().c_str());
/* pExternalFenceProperties */
    std::string pExternalFencePropertiesName = "pExternalFenceProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pExternalFenceProperties;
    pExternalFencePropertiesName = GenerateStruct_VkExternalFenceProperties(stream_pExternalFenceProperties,
                                                                  pExternalFenceProperties->GetPointer(),
                                                                  pExternalFenceProperties->GetMetaStructPointer(),
                                                                  *this);
    fprintf(file, "\n%s", stream_pExternalFenceProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceExternalFencePropertiesKHR");
    fprintf(file,
            "loaded_vkGetPhysicalDeviceExternalFencePropertiesKHR(%s, &%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pExternalFenceInfoStruct.c_str(),
            pExternalFencePropertiesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR);
}


void VulkanCppConsumer::Process_vkGetFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pGetWin32HandleInfo */
    std::stringstream stream_pGetWin32HandleInfo;
    std::string pGetWin32HandleInfoStruct = GenerateStruct_VkFenceGetWin32HandleInfoKHR(stream_pGetWin32HandleInfo,
                                                                           pGetWin32HandleInfo->GetPointer(),
                                                                           pGetWin32HandleInfo->GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "\n%s", stream_pGetWin32HandleInfo.str().c_str());
/* pHandle */
    std::string pHandleName = "pHandle_" + std::to_string(this->getNextId());
    fprintf(file, "uint8_t* %s;\n", pHandleName.c_str());
    m_pfnLoader.AddMethodName("vkGetFenceWin32HandleKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetFenceWin32HandleKHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pGetWin32HandleInfoStruct.c_str(),
            pHandleName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR);
}

void VulkanCppConsumer::Process_vkImportFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>* pImportFenceWin32HandleInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pImportFenceWin32HandleInfo */
    std::stringstream stream_pImportFenceWin32HandleInfo;
    std::string pImportFenceWin32HandleInfoStruct = GenerateStruct_VkImportFenceWin32HandleInfoKHR(stream_pImportFenceWin32HandleInfo,
                                                                                   pImportFenceWin32HandleInfo->GetPointer(),
                                                                                   pImportFenceWin32HandleInfo->GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "\n%s", stream_pImportFenceWin32HandleInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkImportFenceWin32HandleKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkImportFenceWin32HandleKHR(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pImportFenceWin32HandleInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR);
}

void VulkanCppConsumer::Process_vkGetFenceFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pGetFdInfo */
    std::stringstream stream_pGetFdInfo;
    std::string pGetFdInfoStruct = GenerateStruct_VkFenceGetFdInfoKHR(stream_pGetFdInfo,
                                                                  pGetFdInfo->GetPointer(),
                                                                  pGetFdInfo->GetMetaStructPointer(),
                                                                  *this);
    fprintf(file, "\n%s", stream_pGetFdInfo.str().c_str());
/* pFd */
    std::string pFdName = "pFd_" + std::to_string(this->getNextId());
    fprintf(file, "int %s;\n", pFdName.c_str());
    m_pfnLoader.AddMethodName("vkGetFenceFdKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetFenceFdKHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pGetFdInfoStruct.c_str(),
            pFdName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetFenceFdKHR);
}

void VulkanCppConsumer::Process_vkImportFenceFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>* pImportFenceFdInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pImportFenceFdInfo */
    std::stringstream stream_pImportFenceFdInfo;
    std::string pImportFenceFdInfoStruct = GenerateStruct_VkImportFenceFdInfoKHR(stream_pImportFenceFdInfo,
                                                                          pImportFenceFdInfo->GetPointer(),
                                                                          pImportFenceFdInfo->GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "\n%s", stream_pImportFenceFdInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkImportFenceFdKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkImportFenceFdKHR(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pImportFenceFdInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkImportFenceFdKHR);
}

void VulkanCppConsumer::Process_vkAcquireProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkAcquireProfilingLockInfoKHR(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkAcquireProfilingLockKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkAcquireProfilingLockKHR(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR);
}

void VulkanCppConsumer::Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    PointerDecoder<uint32_t>*                   pCounterCount,
    StructPointerDecoder<Decoded_VkPerformanceCounterKHR>* pCounters,
    StructPointerDecoder<Decoded_VkPerformanceCounterDescriptionKHR>* pCounterDescriptions)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* queueFamilyIndex */
/* pCounterCount */
    std::string pCounterCountName = "pCounterCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pCounterCountName.c_str());
/* pCounters */
    std::string pCountersName = "pCounters_" + std::to_string(this->getNextId());
    std::stringstream stream_pCounters;
    pCountersName = GenerateStruct_VkPerformanceCounterKHR(stream_pCounters,
                                                   pCounters->GetPointer(),
                                                   pCounters->GetMetaStructPointer(),
                                                   *this);
    fprintf(file, "\n%s", stream_pCounters.str().c_str());
/* pCounterDescriptions */
    std::string pCounterDescriptionsName = "pCounterDescriptions_" + std::to_string(this->getNextId());
    std::stringstream stream_pCounterDescriptions;
    pCounterDescriptionsName = GenerateStruct_VkPerformanceCounterDescriptionKHR(stream_pCounterDescriptions,
                                                              pCounterDescriptions->GetPointer(),
                                                              pCounterDescriptions->GetMetaStructPointer(),
                                                              *this);
    fprintf(file, "\n%s", stream_pCounterDescriptions.str().c_str());
    m_pfnLoader.AddMethodName("vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(%s, %u, &%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            queueFamilyIndex,
            pCounterCountName.c_str(),
            pCountersName.c_str(),
            pCounterDescriptionsName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR>* pPerformanceQueryCreateInfo,
    PointerDecoder<uint32_t>*                   pNumPasses)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pPerformanceQueryCreateInfo */
    std::stringstream stream_pPerformanceQueryCreateInfo;
    std::string pPerformanceQueryCreateInfoStruct = GenerateStruct_VkQueryPoolPerformanceCreateInfoKHR(stream_pPerformanceQueryCreateInfo,
                                                                                   pPerformanceQueryCreateInfo->GetPointer(),
                                                                                   pPerformanceQueryCreateInfo->GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "\n%s", stream_pPerformanceQueryCreateInfo.str().c_str());
/* pNumPasses */
    std::string pNumPassesName = "pNumPasses_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pNumPassesName.c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
    fprintf(file,
            "loaded_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(%s, &%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pPerformanceQueryCreateInfoStruct.c_str(),
            pNumPassesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR);
}

void VulkanCppConsumer::Process_vkReleaseProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
    m_pfnLoader.AddMethodName("vkReleaseProfilingLockKHR");
    fprintf(file,
            "loaded_vkReleaseProfilingLockKHR(%s);\n",
            this->GetHandle(device).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR);
}


void VulkanCppConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>* pSurfaceCapabilities)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pSurfaceInfo */
    std::stringstream stream_pSurfaceInfo;
    std::string pSurfaceInfoStruct = GenerateStruct_VkPhysicalDeviceSurfaceInfo2KHR(stream_pSurfaceInfo,
                                                                    pSurfaceInfo->GetPointer(),
                                                                    pSurfaceInfo->GetMetaStructPointer(),
                                                                    *this);
    fprintf(file, "\n%s", stream_pSurfaceInfo.str().c_str());
/* pSurfaceCapabilities */
    std::string pSurfaceCapabilitiesName = "pSurfaceCapabilities_" + std::to_string(this->getNextId());
    std::stringstream stream_pSurfaceCapabilities;
    pSurfaceCapabilitiesName = GenerateStruct_VkSurfaceCapabilities2KHR(stream_pSurfaceCapabilities,
                                                              pSurfaceCapabilities->GetPointer(),
                                                              pSurfaceCapabilities->GetMetaStructPointer(),
                                                              *this);
    fprintf(file, "\n%s", stream_pSurfaceCapabilities.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceSurfaceCapabilities2KHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfaceCapabilities2KHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pSurfaceInfoStruct.c_str(),
            pSurfaceCapabilitiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>* pSurfaceFormats)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pSurfaceInfo */
    std::stringstream stream_pSurfaceInfo;
    std::string pSurfaceInfoStruct = GenerateStruct_VkPhysicalDeviceSurfaceInfo2KHR(stream_pSurfaceInfo,
                                                                    pSurfaceInfo->GetPointer(),
                                                                    pSurfaceInfo->GetMetaStructPointer(),
                                                                    *this);
    fprintf(file, "\n%s", stream_pSurfaceInfo.str().c_str());
/* pSurfaceFormatCount */
    std::string pSurfaceFormatCountName = "pSurfaceFormatCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pSurfaceFormatCountName.c_str());
/* pSurfaceFormats */
    std::string pSurfaceFormatsName = "pSurfaceFormats_" + std::to_string(this->getNextId());
    std::stringstream stream_pSurfaceFormats;
    pSurfaceFormatsName = GenerateStruct_VkSurfaceFormat2KHR(stream_pSurfaceFormats,
                                                         pSurfaceFormats->GetPointer(),
                                                         pSurfaceFormats->GetMetaStructPointer(),
                                                         *this);
    fprintf(file, "\n%s", stream_pSurfaceFormats.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceSurfaceFormats2KHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfaceFormats2KHR(%s, &%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pSurfaceInfoStruct.c_str(),
            pSurfaceFormatCountName.c_str(),
            pSurfaceFormatsName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR);
}


void VulkanCppConsumer::Process_vkGetDisplayModeProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* display */
/* pPropertyCount */
    std::string pPropertyCountName = "pPropertyCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pPropertyCountName.c_str());
/* pProperties */
    std::string pPropertiesName = "pProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pProperties;
    pPropertiesName = GenerateStruct_VkDisplayModeProperties2KHR(stream_pProperties,
                                                     pProperties->GetPointer(),
                                                     pProperties->GetMetaStructPointer(),
                                                     *this);
    fprintf(file, "\n%s", stream_pProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetDisplayModeProperties2KHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetDisplayModeProperties2KHR(%s, %s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            this->GetHandle(display).c_str(),
            pPropertyCountName.c_str(),
            pPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR);
}

void VulkanCppConsumer::Process_vkGetDisplayPlaneCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>* pDisplayPlaneInfo,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>* pCapabilities)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pDisplayPlaneInfo */
    std::stringstream stream_pDisplayPlaneInfo;
    std::string pDisplayPlaneInfoStruct = GenerateStruct_VkDisplayPlaneInfo2KHR(stream_pDisplayPlaneInfo,
                                                                         pDisplayPlaneInfo->GetPointer(),
                                                                         pDisplayPlaneInfo->GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "\n%s", stream_pDisplayPlaneInfo.str().c_str());
/* pCapabilities */
    std::string pCapabilitiesName = "pCapabilities_" + std::to_string(this->getNextId());
    std::stringstream stream_pCapabilities;
    pCapabilitiesName = GenerateStruct_VkDisplayPlaneCapabilities2KHR(stream_pCapabilities,
                                                       pCapabilities->GetPointer(),
                                                       pCapabilities->GetMetaStructPointer(),
                                                       *this);
    fprintf(file, "\n%s", stream_pCapabilities.str().c_str());
    m_pfnLoader.AddMethodName("vkGetDisplayPlaneCapabilities2KHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetDisplayPlaneCapabilities2KHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pDisplayPlaneInfoStruct.c_str(),
            pCapabilitiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pPropertyCount */
    std::string pPropertyCountName = "pPropertyCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pPropertyCountName.c_str());
/* pProperties */
    std::string pPropertiesName = "pProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pProperties;
    pPropertiesName = GenerateStruct_VkDisplayPlaneProperties2KHR(stream_pProperties,
                                                     pProperties->GetPointer(),
                                                     pProperties->GetMetaStructPointer(),
                                                     *this);
    fprintf(file, "\n%s", stream_pProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pPropertyCountName.c_str(),
            pPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceDisplayProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayProperties2KHR>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pPropertyCount */
    std::string pPropertyCountName = "pPropertyCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pPropertyCountName.c_str());
/* pProperties */
    std::string pPropertiesName = "pProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pProperties;
    pPropertiesName = GenerateStruct_VkDisplayProperties2KHR(stream_pProperties,
                                                     pProperties->GetPointer(),
                                                     pProperties->GetMetaStructPointer(),
                                                     *this);
    fprintf(file, "\n%s", stream_pProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceDisplayProperties2KHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceDisplayProperties2KHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pPropertyCountName.c_str(),
            pPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR);
}




void VulkanCppConsumer::Process_vkGetBufferMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    Generate_vkGetBufferMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR);
}

void VulkanCppConsumer::Process_vkGetImageMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    Generate_vkGetImageMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR);
}

void VulkanCppConsumer::Process_vkGetImageSparseMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkImageSparseMemoryRequirementsInfo2(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
/* pSparseMemoryRequirementCount */
    std::string pSparseMemoryRequirementCountName = "pSparseMemoryRequirementCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pSparseMemoryRequirementCountName.c_str());
/* pSparseMemoryRequirements */
    std::string pSparseMemoryRequirementsName = "pSparseMemoryRequirements_" + std::to_string(this->getNextId());
    std::stringstream stream_pSparseMemoryRequirements;
    pSparseMemoryRequirementsName = GenerateStruct_VkSparseImageMemoryRequirements2(stream_pSparseMemoryRequirements,
                                                                   pSparseMemoryRequirements->GetPointer(),
                                                                   pSparseMemoryRequirements->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pSparseMemoryRequirements.str().c_str());
    m_pfnLoader.AddMethodName("vkGetImageSparseMemoryRequirements2KHR");
    fprintf(file,
            "loaded_vkGetImageSparseMemoryRequirements2KHR(%s, &%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str(),
            pSparseMemoryRequirementCountName.c_str(),
            pSparseMemoryRequirementsName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR);
}


void VulkanCppConsumer::Process_vkCreateSamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkSamplerYcbcrConversionCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pYcbcrConversion */
    std::string pYcbcrConversionName = "pYcbcrConversion_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION));
    AddKnownVariables("VkSamplerYcbcrConversion", pYcbcrConversionName, pYcbcrConversion->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pYcbcrConversionName,
                         pYcbcrConversion->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateSamplerYcbcrConversionKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateSamplerYcbcrConversionKHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pYcbcrConversionName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR);
}

void VulkanCppConsumer::Process_vkDestroySamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* ycbcrConversion */
/* pAllocator */
    m_pfnLoader.AddMethodName("vkDestroySamplerYcbcrConversionKHR");
    fprintf(file,
            "loaded_vkDestroySamplerYcbcrConversionKHR(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(ycbcrConversion).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR);
}

void VulkanCppConsumer::Process_vkBindBufferMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* bindInfoCount */
/* pBindInfos */
    std::stringstream stream_pBindInfos;
    std::string pBindInfosArray = "NULL";
    PointerPairContainer<decltype(pBindInfos->GetPointer()), decltype(pBindInfos->GetMetaStructPointer())> pBindInfosPair{ pBindInfos->GetPointer(), pBindInfos->GetMetaStructPointer(), bindInfoCount };
    std::string pBindInfosNames = toStringJoin(pBindInfosPair.begin(),
                                               pBindInfosPair.end(),
                                               [&](auto pair) { return GenerateStruct_VkBindBufferMemoryInfo(stream_pBindInfos, pair.t1, pair.t2, *this); },
                                               ", ");
    fprintf(file, "\n%s", stream_pBindInfos.str().c_str());
    if (bindInfoCount == 1) {
        pBindInfosArray = "&" + pBindInfosNames;
    } else if (bindInfoCount > 1) {
        pBindInfosArray = "pBindInfos_" + std::to_string(this->getNextId());
        fprintf(file, "VkBindBufferMemoryInfo %s[] = { %s };\n", pBindInfosArray.c_str(), pBindInfosNames.c_str());
    }
    m_pfnLoader.AddMethodName("vkBindBufferMemory2KHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkBindBufferMemory2KHR(%s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            bindInfoCount,
            pBindInfosArray.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindBufferMemory2KHR);
}

void VulkanCppConsumer::Process_vkBindImageMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* bindInfoCount */
/* pBindInfos */
    std::stringstream stream_pBindInfos;
    std::string pBindInfosArray = "NULL";
    PointerPairContainer<decltype(pBindInfos->GetPointer()), decltype(pBindInfos->GetMetaStructPointer())> pBindInfosPair{ pBindInfos->GetPointer(), pBindInfos->GetMetaStructPointer(), bindInfoCount };
    std::string pBindInfosNames = toStringJoin(pBindInfosPair.begin(),
                                               pBindInfosPair.end(),
                                               [&](auto pair) { return GenerateStruct_VkBindImageMemoryInfo(stream_pBindInfos, pair.t1, pair.t2, *this); },
                                               ", ");
    fprintf(file, "\n%s", stream_pBindInfos.str().c_str());
    if (bindInfoCount == 1) {
        pBindInfosArray = "&" + pBindInfosNames;
    } else if (bindInfoCount > 1) {
        pBindInfosArray = "pBindInfos_" + std::to_string(this->getNextId());
        fprintf(file, "VkBindImageMemoryInfo %s[] = { %s };\n", pBindInfosArray.c_str(), pBindInfosNames.c_str());
    }
    m_pfnLoader.AddMethodName("vkBindImageMemory2KHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkBindImageMemory2KHR(%s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            bindInfoCount,
            pBindInfosArray.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindImageMemory2KHR);
}


void VulkanCppConsumer::Process_vkGetDescriptorSetLayoutSupportKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkDescriptorSetLayoutCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pSupport */
    std::string pSupportName = "pSupport_" + std::to_string(this->getNextId());
    std::stringstream stream_pSupport;
    pSupportName = GenerateStruct_VkDescriptorSetLayoutSupport(stream_pSupport,
                                                  pSupport->GetPointer(),
                                                  pSupport->GetMetaStructPointer(),
                                                  *this);
    fprintf(file, "\n%s", stream_pSupport.str().c_str());
    m_pfnLoader.AddMethodName("vkGetDescriptorSetLayoutSupportKHR");
    fprintf(file,
            "loaded_vkGetDescriptorSetLayoutSupportKHR(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            pSupportName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR);
}

void VulkanCppConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* buffer */
/* offset */
/* countBuffer */
/* countBufferOffset */
/* maxDrawCount */
/* stride */
    m_pfnLoader.AddMethodName("vkCmdDrawIndexedIndirectCountKHR");
    fprintf(file,
            "loaded_vkCmdDrawIndexedIndirectCountKHR(%s, %s, %luUL, %s, %luUL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            this->GetHandle(countBuffer).c_str(),
            countBufferOffset,
            maxDrawCount,
            stride);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR);
}

void VulkanCppConsumer::Process_vkCmdDrawIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* buffer */
/* offset */
/* countBuffer */
/* countBufferOffset */
/* maxDrawCount */
/* stride */
    m_pfnLoader.AddMethodName("vkCmdDrawIndirectCountKHR");
    fprintf(file,
            "loaded_vkCmdDrawIndirectCountKHR(%s, %s, %luUL, %s, %luUL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            this->GetHandle(countBuffer).c_str(),
            countBufferOffset,
            maxDrawCount,
            stride);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR);
}











void VulkanCppConsumer::Process_vkGetSemaphoreCounterValueKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* semaphore */
/* pValue */
    std::string pValueName = "pValue_" + std::to_string(this->getNextId());
    fprintf(file, "uint64_t %s;\n", pValueName.c_str());
    m_pfnLoader.AddMethodName("vkGetSemaphoreCounterValueKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetSemaphoreCounterValueKHR(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(semaphore).c_str(),
            pValueName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR);
}

void VulkanCppConsumer::Process_vkSignalSemaphoreKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pSignalInfo */
    std::stringstream stream_pSignalInfo;
    std::string pSignalInfoStruct = GenerateStruct_VkSemaphoreSignalInfo(stream_pSignalInfo,
                                                                   pSignalInfo->GetPointer(),
                                                                   pSignalInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pSignalInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkSignalSemaphoreKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkSignalSemaphoreKHR(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pSignalInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSignalSemaphoreKHR);
}

void VulkanCppConsumer::Process_vkWaitSemaphoresKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pWaitInfo */
    std::stringstream stream_pWaitInfo;
    std::string pWaitInfoStruct = GenerateStruct_VkSemaphoreWaitInfo(stream_pWaitInfo,
                                                                 pWaitInfo->GetPointer(),
                                                                 pWaitInfo->GetMetaStructPointer(),
                                                                 *this);
    fprintf(file, "\n%s", stream_pWaitInfo.str().c_str());
/* timeout */
    m_pfnLoader.AddMethodName("vkWaitSemaphoresKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkWaitSemaphoresKHR(%s, &%s, %luUL), %s);\n",
            this->GetHandle(device).c_str(),
            pWaitInfoStruct.c_str(),
            timeout,
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkWaitSemaphoresKHR);
}



void VulkanCppConsumer::Process_vkCmdSetFragmentShadingRateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkExtent2D>*   pFragmentSize,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pFragmentSize */
    std::stringstream stream_pFragmentSize;
    std::string pFragmentSizeStruct = GenerateStruct_VkExtent2D(stream_pFragmentSize,
                                                                     pFragmentSize->GetPointer(),
                                                                     pFragmentSize->GetMetaStructPointer(),
                                                                     *this);
    fprintf(file, "\n%s", stream_pFragmentSize.str().c_str());
/* combinerOps */
    std::string combinerOpsArray = "NULL";
    std::string combinerOpsValues = toStringJoin(combinerOps->GetPointer(),
                                                 combinerOps->GetPointer() + 2,
                                                 [&](const format::HandleId current) { return this->GetHandle(current); },
                                                 ", ");
    fprintf(file, "VkFragmentShadingRateCombinerOpKHR %s[] = { %s };\n", combinerOpsArray.c_str(), combinerOpsValues.c_str());
    m_pfnLoader.AddMethodName("vkCmdSetFragmentShadingRateKHR");
    fprintf(file,
            "loaded_vkCmdSetFragmentShadingRateKHR(%s, &%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pFragmentSizeStruct.c_str(),
            combinerOpsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceFragmentShadingRatesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pFragmentShadingRateCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFragmentShadingRateKHR>* pFragmentShadingRates)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pFragmentShadingRateCount */
    std::string pFragmentShadingRateCountName = "pFragmentShadingRateCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pFragmentShadingRateCountName.c_str());
/* pFragmentShadingRates */
    std::string pFragmentShadingRatesName = "pFragmentShadingRates_" + std::to_string(this->getNextId());
    std::stringstream stream_pFragmentShadingRates;
    pFragmentShadingRatesName = GenerateStruct_VkPhysicalDeviceFragmentShadingRateKHR(stream_pFragmentShadingRates,
                                                               pFragmentShadingRates->GetPointer(),
                                                               pFragmentShadingRates->GetMetaStructPointer(),
                                                               *this);
    fprintf(file, "\n%s", stream_pFragmentShadingRates.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceFragmentShadingRatesKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceFragmentShadingRatesKHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pFragmentShadingRateCountName.c_str(),
            pFragmentShadingRatesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR);
}




void VulkanCppConsumer::Process_vkWaitForPresentKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    uint64_t                                    presentId,
    uint64_t                                    timeout)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* swapchain */
/* presentId */
/* timeout */
    m_pfnLoader.AddMethodName("vkWaitForPresentKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkWaitForPresentKHR(%s, %s, %luUL, %luUL), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapchain).c_str(),
            presentId,
            timeout,
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkWaitForPresentKHR);
}


void VulkanCppConsumer::Process_vkGetBufferDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkBufferDeviceAddressInfo(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkGetBufferDeviceAddressKHR");
    fprintf(file,
            "loaded_vkGetBufferDeviceAddressKHR(%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR);
}

void VulkanCppConsumer::Process_vkGetBufferOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkBufferDeviceAddressInfo(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkGetBufferOpaqueCaptureAddressKHR");
    fprintf(file,
            "loaded_vkGetBufferOpaqueCaptureAddressKHR(%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR);
}

void VulkanCppConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkDeviceMemoryOpaqueCaptureAddressInfo(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkGetDeviceMemoryOpaqueCaptureAddressKHR");
    fprintf(file,
            "loaded_vkGetDeviceMemoryOpaqueCaptureAddressKHR(%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR);
}

void VulkanCppConsumer::Process_vkCreateDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeferredOperationKHR>* pDeferredOperation)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pAllocator */
/* pDeferredOperation */
    std::string pDeferredOperationName = "pDeferredOperation_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR));
    AddKnownVariables("VkDeferredOperationKHR", pDeferredOperationName, pDeferredOperation->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pDeferredOperationName,
                         pDeferredOperation->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateDeferredOperationKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateDeferredOperationKHR(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            "nullptr",
            pDeferredOperationName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR);
}

void VulkanCppConsumer::Process_vkDeferredOperationJoinKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* operation */
    m_pfnLoader.AddMethodName("vkDeferredOperationJoinKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkDeferredOperationJoinKHR(%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(operation).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR);
}

void VulkanCppConsumer::Process_vkDestroyDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            operation,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* operation */
/* pAllocator */
    m_pfnLoader.AddMethodName("vkDestroyDeferredOperationKHR");
    fprintf(file,
            "loaded_vkDestroyDeferredOperationKHR(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(operation).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR);
}

void VulkanCppConsumer::Process_vkGetDeferredOperationMaxConcurrencyKHR(
    const ApiCallInfo&                          call_info,
    uint32_t                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* operation */
    m_pfnLoader.AddMethodName("vkGetDeferredOperationMaxConcurrencyKHR");
    fprintf(file,
            "loaded_vkGetDeferredOperationMaxConcurrencyKHR(%s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(operation).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR);
}

void VulkanCppConsumer::Process_vkGetDeferredOperationResultKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* operation */
    m_pfnLoader.AddMethodName("vkGetDeferredOperationResultKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetDeferredOperationResultKHR(%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(operation).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR);
}

void VulkanCppConsumer::Process_vkGetPipelineExecutableInternalRepresentationsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
    PointerDecoder<uint32_t>*                   pInternalRepresentationCount,
    StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR>* pInternalRepresentations)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pExecutableInfo */
    std::stringstream stream_pExecutableInfo;
    std::string pExecutableInfoStruct = GenerateStruct_VkPipelineExecutableInfoKHR(stream_pExecutableInfo,
                                                                       pExecutableInfo->GetPointer(),
                                                                       pExecutableInfo->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "\n%s", stream_pExecutableInfo.str().c_str());
/* pInternalRepresentationCount */
    std::string pInternalRepresentationCountName = "pInternalRepresentationCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pInternalRepresentationCountName.c_str());
/* pInternalRepresentations */
    std::string pInternalRepresentationsName = "pInternalRepresentations_" + std::to_string(this->getNextId());
    std::stringstream stream_pInternalRepresentations;
    pInternalRepresentationsName = GenerateStruct_VkPipelineExecutableInternalRepresentationKHR(stream_pInternalRepresentations,
                                                                  pInternalRepresentations->GetPointer(),
                                                                  pInternalRepresentations->GetMetaStructPointer(),
                                                                  *this);
    fprintf(file, "\n%s", stream_pInternalRepresentations.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPipelineExecutableInternalRepresentationsKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPipelineExecutableInternalRepresentationsKHR(%s, &%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pExecutableInfoStruct.c_str(),
            pInternalRepresentationCountName.c_str(),
            pInternalRepresentationsName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR);
}

void VulkanCppConsumer::Process_vkGetPipelineExecutablePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineInfoKHR>* pPipelineInfo,
    PointerDecoder<uint32_t>*                   pExecutableCount,
    StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pPipelineInfo */
    std::stringstream stream_pPipelineInfo;
    std::string pPipelineInfoStruct = GenerateStruct_VkPipelineInfoKHR(stream_pPipelineInfo,
                                                                     pPipelineInfo->GetPointer(),
                                                                     pPipelineInfo->GetMetaStructPointer(),
                                                                     *this);
    fprintf(file, "\n%s", stream_pPipelineInfo.str().c_str());
/* pExecutableCount */
    std::string pExecutableCountName = "pExecutableCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pExecutableCountName.c_str());
/* pProperties */
    std::string pPropertiesName = "pProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pProperties;
    pPropertiesName = GenerateStruct_VkPipelineExecutablePropertiesKHR(stream_pProperties,
                                                     pProperties->GetPointer(),
                                                     pProperties->GetMetaStructPointer(),
                                                     *this);
    fprintf(file, "\n%s", stream_pProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPipelineExecutablePropertiesKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPipelineExecutablePropertiesKHR(%s, &%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pPipelineInfoStruct.c_str(),
            pExecutableCountName.c_str(),
            pPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR);
}

void VulkanCppConsumer::Process_vkGetPipelineExecutableStatisticsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
    PointerDecoder<uint32_t>*                   pStatisticCount,
    StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR>* pStatistics)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pExecutableInfo */
    std::stringstream stream_pExecutableInfo;
    std::string pExecutableInfoStruct = GenerateStruct_VkPipelineExecutableInfoKHR(stream_pExecutableInfo,
                                                                       pExecutableInfo->GetPointer(),
                                                                       pExecutableInfo->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "\n%s", stream_pExecutableInfo.str().c_str());
/* pStatisticCount */
    std::string pStatisticCountName = "pStatisticCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pStatisticCountName.c_str());
/* pStatistics */
    std::string pStatisticsName = "pStatistics_" + std::to_string(this->getNextId());
    std::stringstream stream_pStatistics;
    pStatisticsName = GenerateStruct_VkPipelineExecutableStatisticKHR(stream_pStatistics,
                                                     pStatistics->GetPointer(),
                                                     pStatistics->GetMetaStructPointer(),
                                                     *this);
    fprintf(file, "\n%s", stream_pStatistics.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPipelineExecutableStatisticsKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPipelineExecutableStatisticsKHR(%s, &%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pExecutableInfoStruct.c_str(),
            pStatisticCountName.c_str(),
            pStatisticsName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR);
}

void VulkanCppConsumer::Process_vkMapMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryMapInfoKHR>* pMemoryMapInfo,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pMemoryMapInfo */
    std::stringstream stream_pMemoryMapInfo;
    std::string pMemoryMapInfoStruct = GenerateStruct_VkMemoryMapInfoKHR(stream_pMemoryMapInfo,
                                                                      pMemoryMapInfo->GetPointer(),
                                                                      pMemoryMapInfo->GetMetaStructPointer(),
                                                                      *this);
    fprintf(file, "\n%s", stream_pMemoryMapInfo.str().c_str());
/* ppData */
    std::string ppDataName = "ppData_" + std::to_string(this->getNextId());
    fprintf(file, "uint8_t* %s;\n", ppDataName.c_str());
    m_pfnLoader.AddMethodName("vkMapMemory2KHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkMapMemory2KHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pMemoryMapInfoStruct.c_str(),
            ppDataName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkMapMemory2KHR);
}

void VulkanCppConsumer::Process_vkUnmapMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryUnmapInfoKHR>* pMemoryUnmapInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pMemoryUnmapInfo */
    std::stringstream stream_pMemoryUnmapInfo;
    std::string pMemoryUnmapInfoStruct = GenerateStruct_VkMemoryUnmapInfoKHR(stream_pMemoryUnmapInfo,
                                                                        pMemoryUnmapInfo->GetPointer(),
                                                                        pMemoryUnmapInfo->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "\n%s", stream_pMemoryUnmapInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkUnmapMemory2KHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkUnmapMemory2KHR(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pMemoryUnmapInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkUnmapMemory2KHR);
}





void VulkanCppConsumer::Process_vkCmdEncodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR>* pEncodeInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pEncodeInfo */
    std::stringstream stream_pEncodeInfo;
    std::string pEncodeInfoStruct = GenerateStruct_VkVideoEncodeInfoKHR(stream_pEncodeInfo,
                                                                   pEncodeInfo->GetPointer(),
                                                                   pEncodeInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pEncodeInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdEncodeVideoKHR");
    fprintf(file,
            "loaded_vkCmdEncodeVideoKHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pEncodeInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR);
}

void VulkanCppConsumer::Process_vkGetEncodedVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkVideoEncodeSessionParametersGetInfoKHR>* pVideoSessionParametersInfo,
    StructPointerDecoder<Decoded_VkVideoEncodeSessionParametersFeedbackInfoKHR>* pFeedbackInfo,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pVideoSessionParametersInfo */
    std::stringstream stream_pVideoSessionParametersInfo;
    std::string pVideoSessionParametersInfoStruct = GenerateStruct_VkVideoEncodeSessionParametersGetInfoKHR(stream_pVideoSessionParametersInfo,
                                                                                   pVideoSessionParametersInfo->GetPointer(),
                                                                                   pVideoSessionParametersInfo->GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "\n%s", stream_pVideoSessionParametersInfo.str().c_str());
/* pFeedbackInfo */
    std::string pFeedbackInfoName = "pFeedbackInfo_" + std::to_string(this->getNextId());
    std::stringstream stream_pFeedbackInfo;
    pFeedbackInfoName = GenerateStruct_VkVideoEncodeSessionParametersFeedbackInfoKHR(stream_pFeedbackInfo,
                                                       pFeedbackInfo->GetPointer(),
                                                       pFeedbackInfo->GetMetaStructPointer(),
                                                       *this);
    fprintf(file, "\n%s", stream_pFeedbackInfo.str().c_str());
/* pDataSize */
    std::string pDataSizeName = "pDataSize_" + std::to_string(this->getNextId());
    fprintf(file, "size_t %s;\n", pDataSizeName.c_str());
/* pData */
    std::string pDataName = "pData_" + std::to_string(this->getNextId());
    long unsigned int* in_pDataSize = pDataSize->GetPointer();
    fprintf(file, "uint8_t %s[%ld];\n", pDataName.c_str(), *in_pDataSize);
    m_pfnLoader.AddMethodName("vkGetEncodedVideoSessionParametersKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetEncodedVideoSessionParametersKHR(%s, &%s, &%s, &%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            pVideoSessionParametersInfoStruct.c_str(),
            pFeedbackInfoName.c_str(),
            pDataSizeName.c_str(),
            pDataName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetEncodedVideoSessionParametersKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR>* pQualityLevelInfo,
    StructPointerDecoder<Decoded_VkVideoEncodeQualityLevelPropertiesKHR>* pQualityLevelProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pQualityLevelInfo */
    std::stringstream stream_pQualityLevelInfo;
    std::string pQualityLevelInfoStruct = GenerateStruct_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR(stream_pQualityLevelInfo,
                                                                         pQualityLevelInfo->GetPointer(),
                                                                         pQualityLevelInfo->GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "\n%s", stream_pQualityLevelInfo.str().c_str());
/* pQualityLevelProperties */
    std::string pQualityLevelPropertiesName = "pQualityLevelProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pQualityLevelProperties;
    pQualityLevelPropertiesName = GenerateStruct_VkVideoEncodeQualityLevelPropertiesKHR(stream_pQualityLevelProperties,
                                                                 pQualityLevelProperties->GetPointer(),
                                                                 pQualityLevelProperties->GetMetaStructPointer(),
                                                                 *this);
    fprintf(file, "\n%s", stream_pQualityLevelProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pQualityLevelInfoStruct.c_str(),
            pQualityLevelPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR);
}

void VulkanCppConsumer::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pDependencyInfo */
    std::stringstream stream_pDependencyInfo;
    std::string pDependencyInfoStruct = GenerateStruct_VkDependencyInfo(stream_pDependencyInfo,
                                                                       pDependencyInfo->GetPointer(),
                                                                       pDependencyInfo->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "\n%s", stream_pDependencyInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdPipelineBarrier2KHR");
    fprintf(file,
            "loaded_vkCmdPipelineBarrier2KHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pDependencyInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR);
}

void VulkanCppConsumer::Process_vkCmdResetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* event */
/* stageMask */
    m_pfnLoader.AddMethodName("vkCmdResetEvent2KHR");
    fprintf(file,
            "loaded_vkCmdResetEvent2KHR(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(event).c_str(),
            util::ToString<VkPipelineStageFlags2>(stageMask).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResetEvent2KHR);
}

void VulkanCppConsumer::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* event */
/* pDependencyInfo */
    std::stringstream stream_pDependencyInfo;
    std::string pDependencyInfoStruct = GenerateStruct_VkDependencyInfo(stream_pDependencyInfo,
                                                                       pDependencyInfo->GetPointer(),
                                                                       pDependencyInfo->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "\n%s", stream_pDependencyInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdSetEvent2KHR");
    fprintf(file,
            "loaded_vkCmdSetEvent2KHR(%s, %s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(event).c_str(),
            pDependencyInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetEvent2KHR);
}

void VulkanCppConsumer::Process_vkCmdWaitEvents2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* eventCount */
/* pEvents */
    std::string pEventsArray = "NULL";
    std::string pEventsValues = toStringJoin(pEvents->GetPointer(),
                                             pEvents->GetPointer() + eventCount,
                                             [&](const format::HandleId current) { return this->GetHandle(current); },
                                             ", ");
    if (eventCount == 1) {
        pEventsArray = "&" + pEventsValues;
    } else if (eventCount > 1) {
        pEventsArray = "pEventsArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkEvent %s[] = { %s };\n", pEventsArray.c_str(), pEventsValues.c_str());
    }
/* pDependencyInfos */
    std::stringstream stream_pDependencyInfos;
    std::string pDependencyInfosArray = "NULL";
    PointerPairContainer<decltype(pDependencyInfos->GetPointer()), decltype(pDependencyInfos->GetMetaStructPointer())> pDependencyInfosPair{ pDependencyInfos->GetPointer(), pDependencyInfos->GetMetaStructPointer(), eventCount };
    std::string pDependencyInfosNames = toStringJoin(pDependencyInfosPair.begin(),
                                                     pDependencyInfosPair.end(),
                                                     [&](auto pair) { return GenerateStruct_VkDependencyInfo(stream_pDependencyInfos, pair.t1, pair.t2, *this); },
                                                     ", ");
    fprintf(file, "\n%s", stream_pDependencyInfos.str().c_str());
    if (eventCount == 1) {
        pDependencyInfosArray = "&" + pDependencyInfosNames;
    } else if (eventCount > 1) {
        pDependencyInfosArray = "pDependencyInfos_" + std::to_string(this->getNextId());
        fprintf(file, "VkDependencyInfo %s[] = { %s };\n", pDependencyInfosArray.c_str(), pDependencyInfosNames.c_str());
    }
    m_pfnLoader.AddMethodName("vkCmdWaitEvents2KHR");
    fprintf(file,
            "loaded_vkCmdWaitEvents2KHR(%s, %u, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            eventCount,
            pEventsArray.c_str(),
            pDependencyInfosArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR);
}

void VulkanCppConsumer::Process_vkCmdWriteBufferMarker2AMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* stage */
/* dstBuffer */
/* dstOffset */
/* marker */
    m_pfnLoader.AddMethodName("vkCmdWriteBufferMarker2AMD");
    fprintf(file,
            "loaded_vkCmdWriteBufferMarker2AMD(%s, %s, %s, %luUL, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineStageFlags2>(stage).c_str(),
            this->GetHandle(dstBuffer).c_str(),
            dstOffset,
            marker);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD);
}

void VulkanCppConsumer::Process_vkCmdWriteTimestamp2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* stage */
/* queryPool */
/* query */
    m_pfnLoader.AddMethodName("vkCmdWriteTimestamp2KHR");
    fprintf(file,
            "loaded_vkCmdWriteTimestamp2KHR(%s, %s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineStageFlags2>(stage).c_str(),
            this->GetHandle(queryPool).c_str(),
            query);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR);
}

void VulkanCppConsumer::Process_vkGetQueueCheckpointData2NV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointData2NV>* pCheckpointData)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* queue */
/* pCheckpointDataCount */
    std::string pCheckpointDataCountName = "pCheckpointDataCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pCheckpointDataCountName.c_str());
/* pCheckpointData */
    std::string pCheckpointDataName = "pCheckpointData_" + std::to_string(this->getNextId());
    std::stringstream stream_pCheckpointData;
    pCheckpointDataName = GenerateStruct_VkCheckpointData2NV(stream_pCheckpointData,
                                                         pCheckpointData->GetPointer(),
                                                         pCheckpointData->GetMetaStructPointer(),
                                                         *this);
    fprintf(file, "\n%s", stream_pCheckpointData.str().c_str());
    m_pfnLoader.AddMethodName("vkGetQueueCheckpointData2NV");
    fprintf(file,
            "loaded_vkGetQueueCheckpointData2NV(%s, &%s, &%s);\n",
            this->GetHandle(queue).c_str(),
            pCheckpointDataCountName.c_str(),
            pCheckpointDataName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV);
}

void VulkanCppConsumer::Process_vkQueueSubmit2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
    format::HandleId                            fence)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* queue */
/* submitCount */
/* pSubmits */
    std::stringstream stream_pSubmits;
    std::string pSubmitsArray = "NULL";
    PointerPairContainer<decltype(pSubmits->GetPointer()), decltype(pSubmits->GetMetaStructPointer())> pSubmitsPair{ pSubmits->GetPointer(), pSubmits->GetMetaStructPointer(), submitCount };
    std::string pSubmitsNames = toStringJoin(pSubmitsPair.begin(),
                                             pSubmitsPair.end(),
                                             [&](auto pair) { return GenerateStruct_VkSubmitInfo2(stream_pSubmits, pair.t1, pair.t2, *this); },
                                             ", ");
    fprintf(file, "\n%s", stream_pSubmits.str().c_str());
    if (submitCount == 1) {
        pSubmitsArray = "&" + pSubmitsNames;
    } else if (submitCount > 1) {
        pSubmitsArray = "pSubmits_" + std::to_string(this->getNextId());
        fprintf(file, "VkSubmitInfo2 %s[] = { %s };\n", pSubmitsArray.c_str(), pSubmitsNames.c_str());
    }
/* fence */
    m_pfnLoader.AddMethodName("vkQueueSubmit2KHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkQueueSubmit2KHR(%s, %u, %s, %s), %s);\n",
            this->GetHandle(queue).c_str(),
            submitCount,
            pSubmitsArray.c_str(),
            this->GetHandle(fence).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkQueueSubmit2KHR);
}





void VulkanCppConsumer::Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pBlitImageInfo */
    std::stringstream stream_pBlitImageInfo;
    std::string pBlitImageInfoStruct = GenerateStruct_VkBlitImageInfo2(stream_pBlitImageInfo,
                                                                      pBlitImageInfo->GetPointer(),
                                                                      pBlitImageInfo->GetMetaStructPointer(),
                                                                      *this);
    fprintf(file, "\n%s", stream_pBlitImageInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdBlitImage2KHR");
    fprintf(file,
            "loaded_vkCmdBlitImage2KHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pBlitImageInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBlitImage2KHR);
}

void VulkanCppConsumer::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pCopyBufferInfo */
    std::stringstream stream_pCopyBufferInfo;
    std::string pCopyBufferInfoStruct = GenerateStruct_VkCopyBufferInfo2(stream_pCopyBufferInfo,
                                                                       pCopyBufferInfo->GetPointer(),
                                                                       pCopyBufferInfo->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "\n%s", stream_pCopyBufferInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdCopyBuffer2KHR");
    fprintf(file,
            "loaded_vkCmdCopyBuffer2KHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pCopyBufferInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR);
}

void VulkanCppConsumer::Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pCopyBufferToImageInfo */
    std::stringstream stream_pCopyBufferToImageInfo;
    std::string pCopyBufferToImageInfoStruct = GenerateStruct_VkCopyBufferToImageInfo2(stream_pCopyBufferToImageInfo,
                                                                              pCopyBufferToImageInfo->GetPointer(),
                                                                              pCopyBufferToImageInfo->GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "\n%s", stream_pCopyBufferToImageInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdCopyBufferToImage2KHR");
    fprintf(file,
            "loaded_vkCmdCopyBufferToImage2KHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pCopyBufferToImageInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR);
}

void VulkanCppConsumer::Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pCopyImageInfo */
    std::stringstream stream_pCopyImageInfo;
    std::string pCopyImageInfoStruct = GenerateStruct_VkCopyImageInfo2(stream_pCopyImageInfo,
                                                                      pCopyImageInfo->GetPointer(),
                                                                      pCopyImageInfo->GetMetaStructPointer(),
                                                                      *this);
    fprintf(file, "\n%s", stream_pCopyImageInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdCopyImage2KHR");
    fprintf(file,
            "loaded_vkCmdCopyImage2KHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pCopyImageInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImage2KHR);
}

void VulkanCppConsumer::Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pCopyImageToBufferInfo */
    std::stringstream stream_pCopyImageToBufferInfo;
    std::string pCopyImageToBufferInfoStruct = GenerateStruct_VkCopyImageToBufferInfo2(stream_pCopyImageToBufferInfo,
                                                                              pCopyImageToBufferInfo->GetPointer(),
                                                                              pCopyImageToBufferInfo->GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "\n%s", stream_pCopyImageToBufferInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdCopyImageToBuffer2KHR");
    fprintf(file,
            "loaded_vkCmdCopyImageToBuffer2KHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pCopyImageToBufferInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR);
}

void VulkanCppConsumer::Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pResolveImageInfo */
    std::stringstream stream_pResolveImageInfo;
    std::string pResolveImageInfoStruct = GenerateStruct_VkResolveImageInfo2(stream_pResolveImageInfo,
                                                                         pResolveImageInfo->GetPointer(),
                                                                         pResolveImageInfo->GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "\n%s", stream_pResolveImageInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdResolveImage2KHR");
    fprintf(file,
            "loaded_vkCmdResolveImage2KHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pResolveImageInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResolveImage2KHR);
}


void VulkanCppConsumer::Process_vkCmdTraceRaysIndirect2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* indirectDeviceAddress */
    m_pfnLoader.AddMethodName("vkCmdTraceRaysIndirect2KHR");
    fprintf(file,
            "loaded_vkCmdTraceRaysIndirect2KHR(%s, %luUL);\n",
            this->GetHandle(commandBuffer).c_str(),
            indirectDeviceAddress);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR);
}


void VulkanCppConsumer::Process_vkGetDeviceBufferMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkDeviceBufferMemoryRequirements(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
/* pMemoryRequirements */
    std::string pMemoryRequirementsName = "pMemoryRequirements_" + std::to_string(this->getNextId());
    std::stringstream stream_pMemoryRequirements;
    pMemoryRequirementsName = GenerateStruct_VkMemoryRequirements2(stream_pMemoryRequirements,
                                                             pMemoryRequirements->GetPointer(),
                                                             pMemoryRequirements->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pMemoryRequirements.str().c_str());
    m_pfnLoader.AddMethodName("vkGetDeviceBufferMemoryRequirementsKHR");
    fprintf(file,
            "loaded_vkGetDeviceBufferMemoryRequirementsKHR(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str(),
            pMemoryRequirementsName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR);
}

void VulkanCppConsumer::Process_vkGetDeviceImageMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkDeviceImageMemoryRequirements(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
/* pMemoryRequirements */
    std::string pMemoryRequirementsName = "pMemoryRequirements_" + std::to_string(this->getNextId());
    std::stringstream stream_pMemoryRequirements;
    pMemoryRequirementsName = GenerateStruct_VkMemoryRequirements2(stream_pMemoryRequirements,
                                                             pMemoryRequirements->GetPointer(),
                                                             pMemoryRequirements->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pMemoryRequirements.str().c_str());
    m_pfnLoader.AddMethodName("vkGetDeviceImageMemoryRequirementsKHR");
    fprintf(file,
            "loaded_vkGetDeviceImageMemoryRequirementsKHR(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str(),
            pMemoryRequirementsName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR);
}

void VulkanCppConsumer::Process_vkGetDeviceImageSparseMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkDeviceImageMemoryRequirements(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
/* pSparseMemoryRequirementCount */
    std::string pSparseMemoryRequirementCountName = "pSparseMemoryRequirementCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pSparseMemoryRequirementCountName.c_str());
/* pSparseMemoryRequirements */
    std::string pSparseMemoryRequirementsName = "pSparseMemoryRequirements_" + std::to_string(this->getNextId());
    std::stringstream stream_pSparseMemoryRequirements;
    pSparseMemoryRequirementsName = GenerateStruct_VkSparseImageMemoryRequirements2(stream_pSparseMemoryRequirements,
                                                                   pSparseMemoryRequirements->GetPointer(),
                                                                   pSparseMemoryRequirements->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pSparseMemoryRequirements.str().c_str());
    m_pfnLoader.AddMethodName("vkGetDeviceImageSparseMemoryRequirementsKHR");
    fprintf(file,
            "loaded_vkGetDeviceImageSparseMemoryRequirementsKHR(%s, &%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str(),
            pSparseMemoryRequirementCountName.c_str(),
            pSparseMemoryRequirementsName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR);
}

void VulkanCppConsumer::Process_vkCmdBindIndexBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkIndexType                                 indexType)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* buffer */
/* offset */
/* size */
/* indexType */
    m_pfnLoader.AddMethodName("vkCmdBindIndexBuffer2KHR");
    fprintf(file,
            "loaded_vkCmdBindIndexBuffer2KHR(%s, %s, %luUL, %luUL, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            size,
            util::ToString<VkIndexType>(indexType).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindIndexBuffer2KHR);
}

void VulkanCppConsumer::Process_vkGetDeviceImageSubresourceLayoutKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageSubresourceInfoKHR>* pInfo,
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR>* pLayout)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkDeviceImageSubresourceInfoKHR(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
/* pLayout */
    std::string pLayoutName = "pLayout_" + std::to_string(this->getNextId());
    std::stringstream stream_pLayout;
    pLayoutName = GenerateStruct_VkSubresourceLayout2KHR(stream_pLayout,
                                                 pLayout->GetPointer(),
                                                 pLayout->GetMetaStructPointer(),
                                                 *this);
    fprintf(file, "\n%s", stream_pLayout.str().c_str());
    m_pfnLoader.AddMethodName("vkGetDeviceImageSubresourceLayoutKHR");
    fprintf(file,
            "loaded_vkGetDeviceImageSubresourceLayoutKHR(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str(),
            pLayoutName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceImageSubresourceLayoutKHR);
}

void VulkanCppConsumer::Process_vkGetImageSubresourceLayout2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource2KHR>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR>* pLayout)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* image */
/* pSubresource */
    std::stringstream stream_pSubresource;
    std::string pSubresourceStruct = GenerateStruct_VkImageSubresource2KHR(stream_pSubresource,
                                                                    pSubresource->GetPointer(),
                                                                    pSubresource->GetMetaStructPointer(),
                                                                    *this);
    fprintf(file, "\n%s", stream_pSubresource.str().c_str());
/* pLayout */
    std::string pLayoutName = "pLayout_" + std::to_string(this->getNextId());
    std::stringstream stream_pLayout;
    pLayoutName = GenerateStruct_VkSubresourceLayout2KHR(stream_pLayout,
                                                 pLayout->GetPointer(),
                                                 pLayout->GetMetaStructPointer(),
                                                 *this);
    fprintf(file, "\n%s", stream_pLayout.str().c_str());
    m_pfnLoader.AddMethodName("vkGetImageSubresourceLayout2KHR");
    fprintf(file,
            "loaded_vkGetImageSubresourceLayout2KHR(%s, %s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(image).c_str(),
            pSubresourceStruct.c_str(),
            pLayoutName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2KHR);
}

void VulkanCppConsumer::Process_vkGetRenderingAreaGranularityKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderingAreaInfoKHR>* pRenderingAreaInfo,
    StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pRenderingAreaInfo */
    std::stringstream stream_pRenderingAreaInfo;
    std::string pRenderingAreaInfoStruct = GenerateStruct_VkRenderingAreaInfoKHR(stream_pRenderingAreaInfo,
                                                                          pRenderingAreaInfo->GetPointer(),
                                                                          pRenderingAreaInfo->GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "\n%s", stream_pRenderingAreaInfo.str().c_str());
/* pGranularity */
    std::string pGranularityName = "pGranularity_" + std::to_string(this->getNextId());
    fprintf(file, "VkExtent2D %s;\n", pGranularityName.c_str());
    m_pfnLoader.AddMethodName("vkGetRenderingAreaGranularityKHR");
    fprintf(file,
            "loaded_vkGetRenderingAreaGranularityKHR(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pRenderingAreaInfoStruct.c_str(),
            pGranularityName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetRenderingAreaGranularityKHR);
}


void VulkanCppConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesKHR>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pPropertyCount */
    std::string pPropertyCountName = "pPropertyCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pPropertyCountName.c_str());
/* pProperties */
    std::string pPropertiesName = "pProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pProperties;
    pPropertiesName = GenerateStruct_VkCooperativeMatrixPropertiesKHR(stream_pProperties,
                                                     pProperties->GetPointer(),
                                                     pProperties->GetMetaStructPointer(),
                                                     *this);
    fprintf(file, "\n%s", stream_pProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pPropertyCountName.c_str(),
            pPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR);
}

void VulkanCppConsumer::Process_vkFrameBoundaryANDROID(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    format::HandleId                            image)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* semaphore */
/* image */
    m_pfnLoader.AddMethodName("vkFrameBoundaryANDROID");
    fprintf(file,
            "loaded_vkFrameBoundaryANDROID(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(semaphore).c_str(),
            this->GetHandle(image).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkFrameBoundaryANDROID);
}

void VulkanCppConsumer::Process_vkCreateDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugReportCallbackEXT>* pCallback)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* instance */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkDebugReportCallbackCreateInfoEXT(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pCallback */
    std::string pCallbackName = "pCallback_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT));
    AddKnownVariables("VkDebugReportCallbackEXT", pCallbackName, pCallback->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pCallbackName,
                         pCallback->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateDebugReportCallbackEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateDebugReportCallbackEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pCallbackName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT);
}

void VulkanCppConsumer::Process_vkDebugReportMessageEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    VkDebugReportFlagsEXT                       flags,
    VkDebugReportObjectTypeEXT                  objectType,
    uint64_t                                    object,
    size_t                                      location,
    int32_t                                     messageCode,
    StringDecoder*                              pLayerPrefix,
    StringDecoder*                              pMessage)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* instance */
/* flags */
/* objectType */
/* object */
/* location */
/* messageCode */
/* pLayerPrefix */
/* pMessage */
    m_pfnLoader.AddMethodName("vkDebugReportMessageEXT");
    fprintf(file,
            "loaded_vkDebugReportMessageEXT(%s, %s, %s, %luUL, %lu, %d, %p, %p);\n",
            this->GetHandle(instance).c_str(),
            util::ToString<VkDebugReportFlagsEXT>(flags).c_str(),
            util::ToString<VkDebugReportObjectTypeEXT>(objectType).c_str(),
            object,
            location,
            messageCode,
            pMessage->GetPointer(),
            pMessage->GetPointer());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDebugReportMessageEXT);
}

void VulkanCppConsumer::Process_vkDestroyDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            callback,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* instance */
/* callback */
/* pAllocator */
    m_pfnLoader.AddMethodName("vkDestroyDebugReportCallbackEXT");
    fprintf(file,
            "loaded_vkDestroyDebugReportCallbackEXT(%s, %s, %s);\n",
            this->GetHandle(instance).c_str(),
            this->GetHandle(callback).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT);
}







void VulkanCppConsumer::Process_vkCmdDebugMarkerBeginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pMarkerInfo */
    std::stringstream stream_pMarkerInfo;
    std::string pMarkerInfoStruct = GenerateStruct_VkDebugMarkerMarkerInfoEXT(stream_pMarkerInfo,
                                                                   pMarkerInfo->GetPointer(),
                                                                   pMarkerInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pMarkerInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdDebugMarkerBeginEXT");
    fprintf(file,
            "loaded_vkCmdDebugMarkerBeginEXT(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pMarkerInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT);
}

void VulkanCppConsumer::Process_vkCmdDebugMarkerEndEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
    m_pfnLoader.AddMethodName("vkCmdDebugMarkerEndEXT");
    fprintf(file,
            "loaded_vkCmdDebugMarkerEndEXT(%s);\n",
            this->GetHandle(commandBuffer).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT);
}

void VulkanCppConsumer::Process_vkCmdDebugMarkerInsertEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pMarkerInfo */
    std::stringstream stream_pMarkerInfo;
    std::string pMarkerInfoStruct = GenerateStruct_VkDebugMarkerMarkerInfoEXT(stream_pMarkerInfo,
                                                                   pMarkerInfo->GetPointer(),
                                                                   pMarkerInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pMarkerInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdDebugMarkerInsertEXT");
    fprintf(file,
            "loaded_vkCmdDebugMarkerInsertEXT(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pMarkerInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT);
}

void VulkanCppConsumer::Process_vkDebugMarkerSetObjectNameEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>* pNameInfo)
{
    Generate_vkDebugMarkerSetObjectNameEXT(returnValue, device, pNameInfo);
    Post_APICall(format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT);
}

void VulkanCppConsumer::Process_vkDebugMarkerSetObjectTagEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>* pTagInfo)
{
    Generate_vkDebugMarkerSetObjectTagEXT(returnValue, device, pTagInfo);
    Post_APICall(format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT);
}



void VulkanCppConsumer::Process_vkCmdBeginQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* queryPool */
/* query */
/* flags */
/* index */
    m_pfnLoader.AddMethodName("vkCmdBeginQueryIndexedEXT");
    fprintf(file,
            "loaded_vkCmdBeginQueryIndexedEXT(%s, %s, %u, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(queryPool).c_str(),
            query,
            util::ToString<VkQueryControlFlags>(flags).c_str(),
            index);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT);
}

void VulkanCppConsumer::Process_vkCmdBeginTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* firstCounterBuffer */
/* counterBufferCount */
/* pCounterBuffers */
    std::string pCounterBuffersArray = "NULL";
    std::string pCounterBuffersValues = toStringJoin(pCounterBuffers->GetPointer(),
                                                     pCounterBuffers->GetPointer() + counterBufferCount,
                                                     [&](const format::HandleId current) { return this->GetHandle(current); },
                                                     ", ");
    if (counterBufferCount == 1) {
        pCounterBuffersArray = "&" + pCounterBuffersValues;
    } else if (counterBufferCount > 1) {
        pCounterBuffersArray = "pCounterBuffersArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkBuffer %s[] = { %s };\n", pCounterBuffersArray.c_str(), pCounterBuffersValues.c_str());
    }
/* pCounterBufferOffsets */
    std::string pCounterBufferOffsetsArray = "pCounterBufferOffsets_" + std::to_string(this->getNextId());
    if (counterBufferCount > 0) {
        std::string pCounterBufferOffsetsValues = toStringJoin(pCounterBufferOffsets->GetPointer(),
                                                               pCounterBufferOffsets->GetPointer() + counterBufferCount,
                                                               [&](const auto current) { return std::to_string(current) + "UL"; },
                                                               ", ");
        fprintf(file, "VkDeviceSize %s[] = { %s };\n", pCounterBufferOffsetsArray.c_str(), pCounterBufferOffsetsValues.c_str());
    } else {
        pCounterBufferOffsetsArray = "NULL";
    }
    m_pfnLoader.AddMethodName("vkCmdBeginTransformFeedbackEXT");
    fprintf(file,
            "loaded_vkCmdBeginTransformFeedbackEXT(%s, %u, %u, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstCounterBuffer,
            counterBufferCount,
            pCounterBuffersArray.c_str(),
            pCounterBufferOffsetsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT);
}

void VulkanCppConsumer::Process_vkCmdBindTransformFeedbackBuffersEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* firstBinding */
/* bindingCount */
/* pBuffers */
    std::string pBuffersArray = "NULL";
    std::string pBuffersValues = toStringJoin(pBuffers->GetPointer(),
                                              pBuffers->GetPointer() + bindingCount,
                                              [&](const format::HandleId current) { return this->GetHandle(current); },
                                              ", ");
    if (bindingCount == 1) {
        pBuffersArray = "&" + pBuffersValues;
    } else if (bindingCount > 1) {
        pBuffersArray = "pBuffersArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkBuffer %s[] = { %s };\n", pBuffersArray.c_str(), pBuffersValues.c_str());
    }
/* pOffsets */
    std::string pOffsetsArray = "pOffsets_" + std::to_string(this->getNextId());
    if (bindingCount > 0) {
        std::string pOffsetsValues = toStringJoin(pOffsets->GetPointer(),
                                                  pOffsets->GetPointer() + bindingCount,
                                                  [&](const auto current) { return std::to_string(current) + "UL"; },
                                                  ", ");
        fprintf(file, "VkDeviceSize %s[] = { %s };\n", pOffsetsArray.c_str(), pOffsetsValues.c_str());
    } else {
        pOffsetsArray = "NULL";
    }
/* pSizes */
    std::string pSizesArray = "pSizes_" + std::to_string(this->getNextId());
    if (bindingCount > 0) {
        std::string pSizesValues = toStringJoin(pSizes->GetPointer(),
                                                pSizes->GetPointer() + bindingCount,
                                                [&](const auto current) { return std::to_string(current) + "UL"; },
                                                ", ");
        fprintf(file, "VkDeviceSize %s[] = { %s };\n", pSizesArray.c_str(), pSizesValues.c_str());
    } else {
        pSizesArray = "NULL";
    }
    m_pfnLoader.AddMethodName("vkCmdBindTransformFeedbackBuffersEXT");
    fprintf(file,
            "loaded_vkCmdBindTransformFeedbackBuffersEXT(%s, %u, %u, %s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstBinding,
            bindingCount,
            pBuffersArray.c_str(),
            pOffsetsArray.c_str(),
            pSizesArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT);
}

void VulkanCppConsumer::Process_vkCmdDrawIndirectByteCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    format::HandleId                            counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* instanceCount */
/* firstInstance */
/* counterBuffer */
/* counterBufferOffset */
/* counterOffset */
/* vertexStride */
    m_pfnLoader.AddMethodName("vkCmdDrawIndirectByteCountEXT");
    fprintf(file,
            "loaded_vkCmdDrawIndirectByteCountEXT(%s, %u, %u, %s, %luUL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            instanceCount,
            firstInstance,
            this->GetHandle(counterBuffer).c_str(),
            counterBufferOffset,
            counterOffset,
            vertexStride);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT);
}

void VulkanCppConsumer::Process_vkCmdEndQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    uint32_t                                    index)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* queryPool */
/* query */
/* index */
    m_pfnLoader.AddMethodName("vkCmdEndQueryIndexedEXT");
    fprintf(file,
            "loaded_vkCmdEndQueryIndexedEXT(%s, %s, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(queryPool).c_str(),
            query,
            index);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT);
}

void VulkanCppConsumer::Process_vkCmdEndTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* firstCounterBuffer */
/* counterBufferCount */
/* pCounterBuffers */
    std::string pCounterBuffersArray = "NULL";
    std::string pCounterBuffersValues = toStringJoin(pCounterBuffers->GetPointer(),
                                                     pCounterBuffers->GetPointer() + counterBufferCount,
                                                     [&](const format::HandleId current) { return this->GetHandle(current); },
                                                     ", ");
    if (counterBufferCount == 1) {
        pCounterBuffersArray = "&" + pCounterBuffersValues;
    } else if (counterBufferCount > 1) {
        pCounterBuffersArray = "pCounterBuffersArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkBuffer %s[] = { %s };\n", pCounterBuffersArray.c_str(), pCounterBuffersValues.c_str());
    }
/* pCounterBufferOffsets */
    std::string pCounterBufferOffsetsArray = "pCounterBufferOffsets_" + std::to_string(this->getNextId());
    if (counterBufferCount > 0) {
        std::string pCounterBufferOffsetsValues = toStringJoin(pCounterBufferOffsets->GetPointer(),
                                                               pCounterBufferOffsets->GetPointer() + counterBufferCount,
                                                               [&](const auto current) { return std::to_string(current) + "UL"; },
                                                               ", ");
        fprintf(file, "VkDeviceSize %s[] = { %s };\n", pCounterBufferOffsetsArray.c_str(), pCounterBufferOffsetsValues.c_str());
    } else {
        pCounterBufferOffsetsArray = "NULL";
    }
    m_pfnLoader.AddMethodName("vkCmdEndTransformFeedbackEXT");
    fprintf(file,
            "loaded_vkCmdEndTransformFeedbackEXT(%s, %u, %u, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstCounterBuffer,
            counterBufferCount,
            pCounterBuffersArray.c_str(),
            pCounterBufferOffsetsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT);
}

void VulkanCppConsumer::Process_vkGetImageViewAddressNVX(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkImageViewAddressPropertiesNVX>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* imageView */
/* pProperties */
    std::string pPropertiesName = "pProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pProperties;
    pPropertiesName = GenerateStruct_VkImageViewAddressPropertiesNVX(stream_pProperties,
                                                     pProperties->GetPointer(),
                                                     pProperties->GetMetaStructPointer(),
                                                     *this);
    fprintf(file, "\n%s", stream_pProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetImageViewAddressNVX");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetImageViewAddressNVX(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(imageView).c_str(),
            pPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageViewAddressNVX);
}

void VulkanCppConsumer::Process_vkGetImageViewHandleNVX(
    const ApiCallInfo&                          call_info,
    uint32_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkImageViewHandleInfoNVX(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkGetImageViewHandleNVX");
    fprintf(file,
            "loaded_vkGetImageViewHandleNVX(%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageViewHandleNVX);
}

void VulkanCppConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* buffer */
/* offset */
/* countBuffer */
/* countBufferOffset */
/* maxDrawCount */
/* stride */
    m_pfnLoader.AddMethodName("vkCmdDrawIndexedIndirectCountAMD");
    fprintf(file,
            "loaded_vkCmdDrawIndexedIndirectCountAMD(%s, %s, %luUL, %s, %luUL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            this->GetHandle(countBuffer).c_str(),
            countBufferOffset,
            maxDrawCount,
            stride);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD);
}

void VulkanCppConsumer::Process_vkCmdDrawIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* buffer */
/* offset */
/* countBuffer */
/* countBufferOffset */
/* maxDrawCount */
/* stride */
    m_pfnLoader.AddMethodName("vkCmdDrawIndirectCountAMD");
    fprintf(file,
            "loaded_vkCmdDrawIndirectCountAMD(%s, %s, %luUL, %s, %luUL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            this->GetHandle(countBuffer).c_str(),
            countBufferOffset,
            maxDrawCount,
            stride);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD);
}







void VulkanCppConsumer::Process_vkGetShaderInfoAMD(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    VkShaderStageFlagBits                       shaderStage,
    VkShaderInfoTypeAMD                         infoType,
    PointerDecoder<size_t>*                     pInfoSize,
    PointerDecoder<uint8_t>*                    pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pipeline */
/* shaderStage */
/* infoType */
/* pInfoSize */
    std::string pInfoSizeName = "pInfoSize_" + std::to_string(this->getNextId());
    fprintf(file, "size_t %s;\n", pInfoSizeName.c_str());
/* pInfo */
    std::string pInfoName = "pInfo_" + std::to_string(this->getNextId());
    long unsigned int* in_pInfoSize = pInfoSize->GetPointer();
    fprintf(file, "uint8_t %s[%ld];\n", pInfoName.c_str(), *in_pInfoSize);
    m_pfnLoader.AddMethodName("vkGetShaderInfoAMD");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetShaderInfoAMD(%s, %s, %s, %s, &%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipeline).c_str(),
            util::ToString<VkShaderStageFlagBits>(shaderStage).c_str(),
            util::ToString<VkShaderInfoTypeAMD>(infoType).c_str(),
            pInfoSizeName.c_str(),
            pInfoName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetShaderInfoAMD);
}


void VulkanCppConsumer::Process_vkCreateStreamDescriptorSurfaceGGP(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* instance */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkStreamDescriptorSurfaceCreateInfoGGP(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pSurface */
    std::string pSurfaceName = "pSurface_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", pSurfaceName, pSurface->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pSurfaceName,
                         pSurface->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateStreamDescriptorSurfaceGGP");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateStreamDescriptorSurfaceGGP(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pSurfaceName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP);
}



void VulkanCppConsumer::Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    VkExternalMemoryHandleTypeFlagsNV           externalHandleType,
    StructPointerDecoder<Decoded_VkExternalImageFormatPropertiesNV>* pExternalImageFormatProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* format */
/* type */
/* tiling */
/* usage */
/* flags */
/* externalHandleType */
/* pExternalImageFormatProperties */
    std::string pExternalImageFormatPropertiesName = "pExternalImageFormatProperties_" + std::to_string(this->getNextId());
    fprintf(file, "VkExternalImageFormatPropertiesNV %s;\n", pExternalImageFormatPropertiesName.c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceExternalImageFormatPropertiesNV");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(%s, %s, %s, %s, %s, %s, %s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            util::ToString<VkFormat>(format).c_str(),
            util::ToString<VkImageType>(type).c_str(),
            util::ToString<VkImageTiling>(tiling).c_str(),
            util::ToString<VkImageUsageFlags>(usage).c_str(),
            util::ToString<VkImageCreateFlags>(flags).c_str(),
            util::ToString<VkExternalMemoryHandleTypeFlagsNV>(externalHandleType).c_str(),
            pExternalImageFormatPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV);
}


void VulkanCppConsumer::Process_vkGetMemoryWin32HandleNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            memory,
    VkExternalMemoryHandleTypeFlagsNV           handleType,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* memory */
/* handleType */
/* pHandle */
    std::string pHandleName = "pHandle_" + std::to_string(this->getNextId());
    fprintf(file, "uint8_t* %s;\n", pHandleName.c_str());
    m_pfnLoader.AddMethodName("vkGetMemoryWin32HandleNV");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetMemoryWin32HandleNV(%s, %s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(memory).c_str(),
            util::ToString<VkExternalMemoryHandleTypeFlagsNV>(handleType).c_str(),
            pHandleName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV);
}



void VulkanCppConsumer::Process_vkCreateViSurfaceNN(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* instance */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkViSurfaceCreateInfoNN(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pSurface */
    std::string pSurfaceName = "pSurface_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", pSurfaceName, pSurface->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pSurfaceName,
                         pSurface->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateViSurfaceNN");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateViSurfaceNN(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pSurfaceName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateViSurfaceNN);
}






void VulkanCppConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pConditionalRenderingBegin */
    std::stringstream stream_pConditionalRenderingBegin;
    std::string pConditionalRenderingBeginStruct = GenerateStruct_VkConditionalRenderingBeginInfoEXT(stream_pConditionalRenderingBegin,
                                                                                  pConditionalRenderingBegin->GetPointer(),
                                                                                  pConditionalRenderingBegin->GetMetaStructPointer(),
                                                                                  *this);
    fprintf(file, "\n%s", stream_pConditionalRenderingBegin.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdBeginConditionalRenderingEXT");
    fprintf(file,
            "loaded_vkCmdBeginConditionalRenderingEXT(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pConditionalRenderingBeginStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT);
}

void VulkanCppConsumer::Process_vkCmdEndConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
    m_pfnLoader.AddMethodName("vkCmdEndConditionalRenderingEXT");
    fprintf(file,
            "loaded_vkCmdEndConditionalRenderingEXT(%s);\n",
            this->GetHandle(commandBuffer).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT);
}

void VulkanCppConsumer::Process_vkCmdSetViewportWScalingNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportWScalingNV>* pViewportWScalings)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* firstViewport */
/* viewportCount */
/* pViewportWScalings */
    std::stringstream stream_pViewportWScalings;
    std::string pViewportWScalingsArray = "NULL";
    PointerPairContainer<decltype(pViewportWScalings->GetPointer()), decltype(pViewportWScalings->GetMetaStructPointer())> pViewportWScalingsPair{ pViewportWScalings->GetPointer(), pViewportWScalings->GetMetaStructPointer(), viewportCount };
    std::string pViewportWScalingsNames = toStringJoin(pViewportWScalingsPair.begin(),
                                                       pViewportWScalingsPair.end(),
                                                       [&](auto pair) { return GenerateStruct_VkViewportWScalingNV(stream_pViewportWScalings, pair.t1, pair.t2, *this); },
                                                       ", ");
    fprintf(file, "\n%s", stream_pViewportWScalings.str().c_str());
    if (viewportCount == 1) {
        pViewportWScalingsArray = "&" + pViewportWScalingsNames;
    } else if (viewportCount > 1) {
        pViewportWScalingsArray = "pViewportWScalings_" + std::to_string(this->getNextId());
        fprintf(file, "VkViewportWScalingNV %s[] = { %s };\n", pViewportWScalingsArray.c_str(), pViewportWScalingsNames.c_str());
    }
    m_pfnLoader.AddMethodName("vkCmdSetViewportWScalingNV");
    fprintf(file,
            "loaded_vkCmdSetViewportWScalingNV(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstViewport,
            viewportCount,
            pViewportWScalingsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV);
}

void VulkanCppConsumer::Process_vkReleaseDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* display */
    m_pfnLoader.AddMethodName("vkReleaseDisplayEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkReleaseDisplayEXT(%s, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            this->GetHandle(display).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkReleaseDisplayEXT);
}

void VulkanCppConsumer::Process_vkAcquireXlibDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    format::HandleId                            display)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* dpy */
    std::string dpyName = "dpy_" + std::to_string(this->getNextId());
    fprintf(file, "void* %s;\n", dpyName.c_str());
/* display */
    m_pfnLoader.AddMethodName("vkAcquireXlibDisplayEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkAcquireXlibDisplayEXT(%s, %s, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            dpyName.c_str(),
            this->GetHandle(display).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT);
}

void VulkanCppConsumer::Process_vkGetRandROutputDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    size_t                                      rrOutput,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplay)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* dpy */
    std::string dpyName = "dpy_" + std::to_string(this->getNextId());
    fprintf(file, "void* %s;\n", dpyName.c_str());
/* rrOutput */
/* pDisplay */
    std::string pDisplayName = "pDisplay_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_DISPLAY_KHR));
    AddKnownVariables("VkDisplayKHR", pDisplayName, pDisplay->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pDisplayName,
                         pDisplay->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkGetRandROutputDisplayEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetRandROutputDisplayEXT(%s, %s, %lu, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            dpyName.c_str(),
            rrOutput,
            pDisplayName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>* pSurfaceCapabilities)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* surface */
/* pSurfaceCapabilities */
    std::string pSurfaceCapabilitiesName = "pSurfaceCapabilities_" + std::to_string(this->getNextId());
    std::stringstream stream_pSurfaceCapabilities;
    pSurfaceCapabilitiesName = GenerateStruct_VkSurfaceCapabilities2EXT(stream_pSurfaceCapabilities,
                                                              pSurfaceCapabilities->GetPointer(),
                                                              pSurfaceCapabilities->GetMetaStructPointer(),
                                                              *this);
    fprintf(file, "\n%s", stream_pSurfaceCapabilities.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceSurfaceCapabilities2EXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfaceCapabilities2EXT(%s, %s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            this->GetHandle(surface).c_str(),
            pSurfaceCapabilitiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT);
}

void VulkanCppConsumer::Process_vkDisplayPowerControlEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>* pDisplayPowerInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* display */
/* pDisplayPowerInfo */
    std::stringstream stream_pDisplayPowerInfo;
    std::string pDisplayPowerInfoStruct = GenerateStruct_VkDisplayPowerInfoEXT(stream_pDisplayPowerInfo,
                                                                         pDisplayPowerInfo->GetPointer(),
                                                                         pDisplayPowerInfo->GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "\n%s", stream_pDisplayPowerInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkDisplayPowerControlEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkDisplayPowerControlEXT(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(display).c_str(),
            pDisplayPowerInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDisplayPowerControlEXT);
}

void VulkanCppConsumer::Process_vkGetSwapchainCounterEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    PointerDecoder<uint64_t>*                   pCounterValue)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* swapchain */
/* counter */
/* pCounterValue */
    std::string pCounterValueName = "pCounterValue_" + std::to_string(this->getNextId());
    fprintf(file, "uint64_t %s;\n", pCounterValueName.c_str());
    m_pfnLoader.AddMethodName("vkGetSwapchainCounterEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetSwapchainCounterEXT(%s, %s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapchain).c_str(),
            util::ToString<VkSurfaceCounterFlagBitsEXT>(counter).c_str(),
            pCounterValueName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT);
}

void VulkanCppConsumer::Process_vkRegisterDeviceEventEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>* pDeviceEventInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pDeviceEventInfo */
    std::stringstream stream_pDeviceEventInfo;
    std::string pDeviceEventInfoStruct = GenerateStruct_VkDeviceEventInfoEXT(stream_pDeviceEventInfo,
                                                                        pDeviceEventInfo->GetPointer(),
                                                                        pDeviceEventInfo->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "\n%s", stream_pDeviceEventInfo.str().c_str());
/* pAllocator */
/* pFence */
    std::string pFenceName = "pFence_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_FENCE));
    AddKnownVariables("VkFence", pFenceName, pFence->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pFenceName,
                         pFence->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkRegisterDeviceEventEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkRegisterDeviceEventEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pDeviceEventInfoStruct.c_str(),
            "nullptr",
            pFenceName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT);
}

void VulkanCppConsumer::Process_vkRegisterDisplayEventEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayEventInfoEXT>* pDisplayEventInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* display */
/* pDisplayEventInfo */
    std::stringstream stream_pDisplayEventInfo;
    std::string pDisplayEventInfoStruct = GenerateStruct_VkDisplayEventInfoEXT(stream_pDisplayEventInfo,
                                                                         pDisplayEventInfo->GetPointer(),
                                                                         pDisplayEventInfo->GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "\n%s", stream_pDisplayEventInfo.str().c_str());
/* pAllocator */
/* pFence */
    std::string pFenceName = "pFence_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_FENCE));
    AddKnownVariables("VkFence", pFenceName, pFence->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pFenceName,
                         pFence->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkRegisterDisplayEventEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkRegisterDisplayEventEXT(%s, %s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(display).c_str(),
            pDisplayEventInfoStruct.c_str(),
            "nullptr",
            pFenceName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT);
}

void VulkanCppConsumer::Process_vkGetPastPresentationTimingGOOGLE(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    PointerDecoder<uint32_t>*                   pPresentationTimingCount,
    StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>* pPresentationTimings)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* swapchain */
/* pPresentationTimingCount */
    std::string pPresentationTimingCountName = "pPresentationTimingCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pPresentationTimingCountName.c_str());
/* pPresentationTimings */
    std::string pPresentationTimingsName = "pPresentationTimings_" + std::to_string(this->getNextId());
    const uint32_t* in_pPresentationTimingCount = pPresentationTimingCount->GetPointer();
    fprintf(file, "VkPastPresentationTimingGOOGLE %s[%d];\n", pPresentationTimingsName.c_str(), *in_pPresentationTimingCount);
    m_pfnLoader.AddMethodName("vkGetPastPresentationTimingGOOGLE");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPastPresentationTimingGOOGLE(%s, %s, &%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapchain).c_str(),
            pPresentationTimingCountName.c_str(),
            pPresentationTimingsName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE);
}

void VulkanCppConsumer::Process_vkGetRefreshCycleDurationGOOGLE(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>* pDisplayTimingProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* swapchain */
/* pDisplayTimingProperties */
    std::string pDisplayTimingPropertiesName = "pDisplayTimingProperties_" + std::to_string(this->getNextId());
    fprintf(file, "VkRefreshCycleDurationGOOGLE %s;\n", pDisplayTimingPropertiesName.c_str());
    m_pfnLoader.AddMethodName("vkGetRefreshCycleDurationGOOGLE");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetRefreshCycleDurationGOOGLE(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapchain).c_str(),
            pDisplayTimingPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE);
}






void VulkanCppConsumer::Process_vkCmdSetDiscardRectangleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pDiscardRectangles)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* firstDiscardRectangle */
/* discardRectangleCount */
/* pDiscardRectangles */
    std::stringstream stream_pDiscardRectangles;
    std::string pDiscardRectanglesArray = "NULL";
    PointerPairContainer<decltype(pDiscardRectangles->GetPointer()), decltype(pDiscardRectangles->GetMetaStructPointer())> pDiscardRectanglesPair{ pDiscardRectangles->GetPointer(), pDiscardRectangles->GetMetaStructPointer(), discardRectangleCount };
    std::string pDiscardRectanglesNames = toStringJoin(pDiscardRectanglesPair.begin(),
                                                       pDiscardRectanglesPair.end(),
                                                       [&](auto pair) { return GenerateStruct_VkRect2D(stream_pDiscardRectangles, pair.t1, pair.t2, *this); },
                                                       ", ");
    fprintf(file, "\n%s", stream_pDiscardRectangles.str().c_str());
    if (discardRectangleCount == 1) {
        pDiscardRectanglesArray = "&" + pDiscardRectanglesNames;
    } else if (discardRectangleCount > 1) {
        pDiscardRectanglesArray = "pDiscardRectangles_" + std::to_string(this->getNextId());
        fprintf(file, "VkRect2D %s[] = { %s };\n", pDiscardRectanglesArray.c_str(), pDiscardRectanglesNames.c_str());
    }
    m_pfnLoader.AddMethodName("vkCmdSetDiscardRectangleEXT");
    fprintf(file,
            "loaded_vkCmdSetDiscardRectangleEXT(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstDiscardRectangle,
            discardRectangleCount,
            pDiscardRectanglesArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDiscardRectangleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    discardRectangleEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* discardRectangleEnable */
    m_pfnLoader.AddMethodName("vkCmdSetDiscardRectangleEnableEXT");
    fprintf(file,
            "loaded_vkCmdSetDiscardRectangleEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            discardRectangleEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDiscardRectangleModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDiscardRectangleModeEXT                   discardRectangleMode)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* discardRectangleMode */
    m_pfnLoader.AddMethodName("vkCmdSetDiscardRectangleModeEXT");
    fprintf(file,
            "loaded_vkCmdSetDiscardRectangleModeEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkDiscardRectangleModeEXT>(discardRectangleMode).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT);
}




void VulkanCppConsumer::Process_vkSetHdrMetadataEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    swapchainCount,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains,
    StructPointerDecoder<Decoded_VkHdrMetadataEXT>* pMetadata)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* swapchainCount */
/* pSwapchains */
    std::string pSwapchainsArray = "NULL";
    std::string pSwapchainsValues = toStringJoin(pSwapchains->GetPointer(),
                                                 pSwapchains->GetPointer() + swapchainCount,
                                                 [&](const format::HandleId current) { return this->GetHandle(current); },
                                                 ", ");
    if (swapchainCount == 1) {
        pSwapchainsArray = "&" + pSwapchainsValues;
    } else if (swapchainCount > 1) {
        pSwapchainsArray = "pSwapchainsArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkSwapchainKHR %s[] = { %s };\n", pSwapchainsArray.c_str(), pSwapchainsValues.c_str());
    }
/* pMetadata */
    std::stringstream stream_pMetadata;
    std::string pMetadataArray = "NULL";
    PointerPairContainer<decltype(pMetadata->GetPointer()), decltype(pMetadata->GetMetaStructPointer())> pMetadataPair{ pMetadata->GetPointer(), pMetadata->GetMetaStructPointer(), swapchainCount };
    std::string pMetadataNames = toStringJoin(pMetadataPair.begin(),
                                              pMetadataPair.end(),
                                              [&](auto pair) { return GenerateStruct_VkHdrMetadataEXT(stream_pMetadata, pair.t1, pair.t2, *this); },
                                              ", ");
    fprintf(file, "\n%s", stream_pMetadata.str().c_str());
    if (swapchainCount == 1) {
        pMetadataArray = "&" + pMetadataNames;
    } else if (swapchainCount > 1) {
        pMetadataArray = "pMetadata_" + std::to_string(this->getNextId());
        fprintf(file, "VkHdrMetadataEXT %s[] = { %s };\n", pMetadataArray.c_str(), pMetadataNames.c_str());
    }
    m_pfnLoader.AddMethodName("vkSetHdrMetadataEXT");
    fprintf(file,
            "loaded_vkSetHdrMetadataEXT(%s, %u, %s, %s);\n",
            this->GetHandle(device).c_str(),
            swapchainCount,
            pSwapchainsArray.c_str(),
            pMetadataArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSetHdrMetadataEXT);
}

void VulkanCppConsumer::Process_vkCreateIOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* instance */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkIOSSurfaceCreateInfoMVK(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pSurface */
    std::string pSurfaceName = "pSurface_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", pSurfaceName, pSurface->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pSurfaceName,
                         pSurface->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateIOSSurfaceMVK");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateIOSSurfaceMVK(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pSurfaceName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK);
}

void VulkanCppConsumer::Process_vkCreateMacOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* instance */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkMacOSSurfaceCreateInfoMVK(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pSurface */
    std::string pSurfaceName = "pSurface_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", pSurfaceName, pSurface->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pSurfaceName,
                         pSurface->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateMacOSSurfaceMVK");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateMacOSSurfaceMVK(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pSurfaceName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK);
}



void VulkanCppConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pLabelInfo */
    std::stringstream stream_pLabelInfo;
    std::string pLabelInfoStruct = GenerateStruct_VkDebugUtilsLabelEXT(stream_pLabelInfo,
                                                                  pLabelInfo->GetPointer(),
                                                                  pLabelInfo->GetMetaStructPointer(),
                                                                  *this);
    fprintf(file, "\n%s", stream_pLabelInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdBeginDebugUtilsLabelEXT");
    fprintf(file,
            "loaded_vkCmdBeginDebugUtilsLabelEXT(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pLabelInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT);
}

void VulkanCppConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
    m_pfnLoader.AddMethodName("vkCmdEndDebugUtilsLabelEXT");
    fprintf(file,
            "loaded_vkCmdEndDebugUtilsLabelEXT(%s);\n",
            this->GetHandle(commandBuffer).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT);
}

void VulkanCppConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pLabelInfo */
    std::stringstream stream_pLabelInfo;
    std::string pLabelInfoStruct = GenerateStruct_VkDebugUtilsLabelEXT(stream_pLabelInfo,
                                                                  pLabelInfo->GetPointer(),
                                                                  pLabelInfo->GetMetaStructPointer(),
                                                                  *this);
    fprintf(file, "\n%s", stream_pLabelInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdInsertDebugUtilsLabelEXT");
    fprintf(file,
            "loaded_vkCmdInsertDebugUtilsLabelEXT(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pLabelInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT);
}

void VulkanCppConsumer::Process_vkCreateDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugUtilsMessengerEXT>* pMessenger)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* instance */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkDebugUtilsMessengerCreateInfoEXT(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pMessenger */
    std::string pMessengerName = "pMessenger_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT));
    AddKnownVariables("VkDebugUtilsMessengerEXT", pMessengerName, pMessenger->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pMessengerName,
                         pMessenger->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateDebugUtilsMessengerEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateDebugUtilsMessengerEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pMessengerName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT);
}

void VulkanCppConsumer::Process_vkDestroyDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            messenger,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* instance */
/* messenger */
/* pAllocator */
    m_pfnLoader.AddMethodName("vkDestroyDebugUtilsMessengerEXT");
    fprintf(file,
            "loaded_vkDestroyDebugUtilsMessengerEXT(%s, %s, %s);\n",
            this->GetHandle(instance).c_str(),
            this->GetHandle(messenger).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT);
}

void VulkanCppConsumer::Process_vkQueueBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* queue */
/* pLabelInfo */
    std::stringstream stream_pLabelInfo;
    std::string pLabelInfoStruct = GenerateStruct_VkDebugUtilsLabelEXT(stream_pLabelInfo,
                                                                  pLabelInfo->GetPointer(),
                                                                  pLabelInfo->GetMetaStructPointer(),
                                                                  *this);
    fprintf(file, "\n%s", stream_pLabelInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkQueueBeginDebugUtilsLabelEXT");
    fprintf(file,
            "loaded_vkQueueBeginDebugUtilsLabelEXT(%s, &%s);\n",
            this->GetHandle(queue).c_str(),
            pLabelInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT);
}

void VulkanCppConsumer::Process_vkQueueEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* queue */
    m_pfnLoader.AddMethodName("vkQueueEndDebugUtilsLabelEXT");
    fprintf(file,
            "loaded_vkQueueEndDebugUtilsLabelEXT(%s);\n",
            this->GetHandle(queue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT);
}

void VulkanCppConsumer::Process_vkQueueInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* queue */
/* pLabelInfo */
    std::stringstream stream_pLabelInfo;
    std::string pLabelInfoStruct = GenerateStruct_VkDebugUtilsLabelEXT(stream_pLabelInfo,
                                                                  pLabelInfo->GetPointer(),
                                                                  pLabelInfo->GetMetaStructPointer(),
                                                                  *this);
    fprintf(file, "\n%s", stream_pLabelInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkQueueInsertDebugUtilsLabelEXT");
    fprintf(file,
            "loaded_vkQueueInsertDebugUtilsLabelEXT(%s, &%s);\n",
            this->GetHandle(queue).c_str(),
            pLabelInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT);
}

void VulkanCppConsumer::Process_vkSetDebugUtilsObjectNameEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo)
{
    Generate_vkSetDebugUtilsObjectNameEXT(returnValue, device, pNameInfo);
    Post_APICall(format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT);
}

void VulkanCppConsumer::Process_vkSetDebugUtilsObjectTagEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>* pTagInfo)
{
    Generate_vkSetDebugUtilsObjectTagEXT(returnValue, device, pTagInfo);
    Post_APICall(format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT);
}

void VulkanCppConsumer::Process_vkSubmitDebugUtilsMessageEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>* pCallbackData)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* instance */
/* messageSeverity */
/* messageTypes */
/* pCallbackData */
    std::stringstream stream_pCallbackData;
    std::string pCallbackDataStruct = GenerateStruct_VkDebugUtilsMessengerCallbackDataEXT(stream_pCallbackData,
                                                                     pCallbackData->GetPointer(),
                                                                     pCallbackData->GetMetaStructPointer(),
                                                                     *this);
    fprintf(file, "\n%s", stream_pCallbackData.str().c_str());
    m_pfnLoader.AddMethodName("vkSubmitDebugUtilsMessageEXT");
    fprintf(file,
            "loaded_vkSubmitDebugUtilsMessageEXT(%s, %s, %s, &%s);\n",
            this->GetHandle(instance).c_str(),
            util::ToString<VkDebugUtilsMessageSeverityFlagBitsEXT>(messageSeverity).c_str(),
            util::ToString<VkDebugUtilsMessageTypeFlagsEXT>(messageTypes).c_str(),
            pCallbackDataStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT);
}

void VulkanCppConsumer::Process_vkGetAndroidHardwareBufferPropertiesANDROID(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint64_t                                    buffer,
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* buffer */
    std::string bufferName = "buffer_" + std::to_string(this->getNextId());
    fprintf(file, "void* %s;\n", bufferName.c_str());
/* pProperties */
    std::string pPropertiesName = "pProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pProperties;
    pPropertiesName = GenerateStruct_VkAndroidHardwareBufferPropertiesANDROID(stream_pProperties,
                                                     pProperties->GetPointer(),
                                                     pProperties->GetMetaStructPointer(),
                                                     *this);
    fprintf(file, "\n%s", stream_pProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetAndroidHardwareBufferPropertiesANDROID");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetAndroidHardwareBufferPropertiesANDROID(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            bufferName.c_str(),
            pPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID);
}

void VulkanCppConsumer::Process_vkGetMemoryAndroidHardwareBufferANDROID(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>* pInfo,
    PointerDecoder<uint64_t, void*>*            pBuffer)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkMemoryGetAndroidHardwareBufferInfoANDROID(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
/* pBuffer */
    std::string pBufferName = "pBuffer_" + std::to_string(this->getNextId());
    fprintf(file, "uint8_t* %s;\n", pBufferName.c_str());
    m_pfnLoader.AddMethodName("vkGetMemoryAndroidHardwareBufferANDROID");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetMemoryAndroidHardwareBufferANDROID(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str(),
            pBufferName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID);
}







void VulkanCppConsumer::Process_vkCmdSetSampleLocationsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pSampleLocationsInfo */
    std::stringstream stream_pSampleLocationsInfo;
    std::string pSampleLocationsInfoStruct = GenerateStruct_VkSampleLocationsInfoEXT(stream_pSampleLocationsInfo,
                                                                            pSampleLocationsInfo->GetPointer(),
                                                                            pSampleLocationsInfo->GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "\n%s", stream_pSampleLocationsInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdSetSampleLocationsEXT");
    fprintf(file,
            "loaded_vkCmdSetSampleLocationsEXT(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pSampleLocationsInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>* pMultisampleProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* samples */
/* pMultisampleProperties */
    std::string pMultisamplePropertiesName = "pMultisampleProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pMultisampleProperties;
    pMultisamplePropertiesName = GenerateStruct_VkMultisamplePropertiesEXT(stream_pMultisampleProperties,
                                                                pMultisampleProperties->GetPointer(),
                                                                pMultisampleProperties->GetMetaStructPointer(),
                                                                *this);
    fprintf(file, "\n%s", stream_pMultisampleProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceMultisamplePropertiesEXT");
    fprintf(file,
            "loaded_vkGetPhysicalDeviceMultisamplePropertiesEXT(%s, %s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            util::ToString<VkSampleCountFlagBits>(samples).c_str(),
            pMultisamplePropertiesName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT);
}







void VulkanCppConsumer::Process_vkGetImageDrmFormatModifierPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* image */
/* pProperties */
    std::string pPropertiesName = "pProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pProperties;
    pPropertiesName = GenerateStruct_VkImageDrmFormatModifierPropertiesEXT(stream_pProperties,
                                                     pProperties->GetPointer(),
                                                     pProperties->GetMetaStructPointer(),
                                                     *this);
    fprintf(file, "\n%s", stream_pProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetImageDrmFormatModifierPropertiesEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetImageDrmFormatModifierPropertiesEXT(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(image).c_str(),
            pPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT);
}

void VulkanCppConsumer::Process_vkCreateValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkValidationCacheEXT>* pValidationCache)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkValidationCacheCreateInfoEXT(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pValidationCache */
    std::string pValidationCacheName = "pValidationCache_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_VALIDATION_CACHE_EXT));
    AddKnownVariables("VkValidationCacheEXT", pValidationCacheName, pValidationCache->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pValidationCacheName,
                         pValidationCache->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateValidationCacheEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateValidationCacheEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pValidationCacheName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateValidationCacheEXT);
}

void VulkanCppConsumer::Process_vkDestroyValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* validationCache */
/* pAllocator */
    m_pfnLoader.AddMethodName("vkDestroyValidationCacheEXT");
    fprintf(file,
            "loaded_vkDestroyValidationCacheEXT(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(validationCache).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT);
}

void VulkanCppConsumer::Process_vkGetValidationCacheDataEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* validationCache */
/* pDataSize */
    std::string pDataSizeName = "pDataSize_" + std::to_string(this->getNextId());
    fprintf(file, "size_t %s;\n", pDataSizeName.c_str());
/* pData */
    std::string pDataName = "pData_" + std::to_string(this->getNextId());
    long unsigned int* in_pDataSize = pDataSize->GetPointer();
    fprintf(file, "uint8_t %s[%ld];\n", pDataName.c_str(), *in_pDataSize);
    m_pfnLoader.AddMethodName("vkGetValidationCacheDataEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetValidationCacheDataEXT(%s, %s, &%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(validationCache).c_str(),
            pDataSizeName.c_str(),
            pDataName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT);
}

void VulkanCppConsumer::Process_vkMergeValidationCachesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    HandlePointerDecoder<VkValidationCacheEXT>* pSrcCaches)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* dstCache */
/* srcCacheCount */
/* pSrcCaches */
    std::string pSrcCachesArray = "NULL";
    std::string pSrcCachesValues = toStringJoin(pSrcCaches->GetPointer(),
                                                pSrcCaches->GetPointer() + srcCacheCount,
                                                [&](const format::HandleId current) { return this->GetHandle(current); },
                                                ", ");
    if (srcCacheCount == 1) {
        pSrcCachesArray = "&" + pSrcCachesValues;
    } else if (srcCacheCount > 1) {
        pSrcCachesArray = "pSrcCachesArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkValidationCacheEXT %s[] = { %s };\n", pSrcCachesArray.c_str(), pSrcCachesValues.c_str());
    }
    m_pfnLoader.AddMethodName("vkMergeValidationCachesEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkMergeValidationCachesEXT(%s, %s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(dstCache).c_str(),
            srcCacheCount,
            pSrcCachesArray.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkMergeValidationCachesEXT);
}



void VulkanCppConsumer::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* imageView */
/* imageLayout */
    m_pfnLoader.AddMethodName("vkCmdBindShadingRateImageNV");
    fprintf(file,
            "loaded_vkCmdBindShadingRateImageNV(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(imageView).c_str(),
            util::ToString<VkImageLayout>(imageLayout).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV);
}

void VulkanCppConsumer::Process_vkCmdSetCoarseSampleOrderNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>* pCustomSampleOrders)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* sampleOrderType */
/* customSampleOrderCount */
/* pCustomSampleOrders */
    std::stringstream stream_pCustomSampleOrders;
    std::string pCustomSampleOrdersArray = "NULL";
    PointerPairContainer<decltype(pCustomSampleOrders->GetPointer()), decltype(pCustomSampleOrders->GetMetaStructPointer())> pCustomSampleOrdersPair{ pCustomSampleOrders->GetPointer(), pCustomSampleOrders->GetMetaStructPointer(), customSampleOrderCount };
    std::string pCustomSampleOrdersNames = toStringJoin(pCustomSampleOrdersPair.begin(),
                                                        pCustomSampleOrdersPair.end(),
                                                        [&](auto pair) { return GenerateStruct_VkCoarseSampleOrderCustomNV(stream_pCustomSampleOrders, pair.t1, pair.t2, *this); },
                                                        ", ");
    fprintf(file, "\n%s", stream_pCustomSampleOrders.str().c_str());
    if (customSampleOrderCount == 1) {
        pCustomSampleOrdersArray = "&" + pCustomSampleOrdersNames;
    } else if (customSampleOrderCount > 1) {
        pCustomSampleOrdersArray = "pCustomSampleOrders_" + std::to_string(this->getNextId());
        fprintf(file, "VkCoarseSampleOrderCustomNV %s[] = { %s };\n", pCustomSampleOrdersArray.c_str(), pCustomSampleOrdersNames.c_str());
    }
    m_pfnLoader.AddMethodName("vkCmdSetCoarseSampleOrderNV");
    fprintf(file,
            "loaded_vkCmdSetCoarseSampleOrderNV(%s, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkCoarseSampleOrderTypeNV>(sampleOrderType).c_str(),
            customSampleOrderCount,
            pCustomSampleOrdersArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV);
}

void VulkanCppConsumer::Process_vkCmdSetViewportShadingRatePaletteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV>* pShadingRatePalettes)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* firstViewport */
/* viewportCount */
/* pShadingRatePalettes */
    std::stringstream stream_pShadingRatePalettes;
    std::string pShadingRatePalettesArray = "NULL";
    PointerPairContainer<decltype(pShadingRatePalettes->GetPointer()), decltype(pShadingRatePalettes->GetMetaStructPointer())> pShadingRatePalettesPair{ pShadingRatePalettes->GetPointer(), pShadingRatePalettes->GetMetaStructPointer(), viewportCount };
    std::string pShadingRatePalettesNames = toStringJoin(pShadingRatePalettesPair.begin(),
                                                         pShadingRatePalettesPair.end(),
                                                         [&](auto pair) { return GenerateStruct_VkShadingRatePaletteNV(stream_pShadingRatePalettes, pair.t1, pair.t2, *this); },
                                                         ", ");
    fprintf(file, "\n%s", stream_pShadingRatePalettes.str().c_str());
    if (viewportCount == 1) {
        pShadingRatePalettesArray = "&" + pShadingRatePalettesNames;
    } else if (viewportCount > 1) {
        pShadingRatePalettesArray = "pShadingRatePalettes_" + std::to_string(this->getNextId());
        fprintf(file, "VkShadingRatePaletteNV %s[] = { %s };\n", pShadingRatePalettesArray.c_str(), pShadingRatePalettesNames.c_str());
    }
    m_pfnLoader.AddMethodName("vkCmdSetViewportShadingRatePaletteNV");
    fprintf(file,
            "loaded_vkCmdSetViewportShadingRatePaletteNV(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstViewport,
            viewportCount,
            pShadingRatePalettesArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV);
}

void VulkanCppConsumer::Process_vkBindAccelerationStructureMemoryNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNV>* pBindInfos)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* bindInfoCount */
/* pBindInfos */
    std::stringstream stream_pBindInfos;
    std::string pBindInfosArray = "NULL";
    PointerPairContainer<decltype(pBindInfos->GetPointer()), decltype(pBindInfos->GetMetaStructPointer())> pBindInfosPair{ pBindInfos->GetPointer(), pBindInfos->GetMetaStructPointer(), bindInfoCount };
    std::string pBindInfosNames = toStringJoin(pBindInfosPair.begin(),
                                               pBindInfosPair.end(),
                                               [&](auto pair) { return GenerateStruct_VkBindAccelerationStructureMemoryInfoNV(stream_pBindInfos, pair.t1, pair.t2, *this); },
                                               ", ");
    fprintf(file, "\n%s", stream_pBindInfos.str().c_str());
    if (bindInfoCount == 1) {
        pBindInfosArray = "&" + pBindInfosNames;
    } else if (bindInfoCount > 1) {
        pBindInfosArray = "pBindInfos_" + std::to_string(this->getNextId());
        fprintf(file, "VkBindAccelerationStructureMemoryInfoNV %s[] = { %s };\n", pBindInfosArray.c_str(), pBindInfosNames.c_str());
    }
    m_pfnLoader.AddMethodName("vkBindAccelerationStructureMemoryNV");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkBindAccelerationStructureMemoryNV(%s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            bindInfoCount,
            pBindInfosArray.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV);
}

void VulkanCppConsumer::Process_vkCmdBuildAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkAccelerationStructureInfoNV>* pInfo,
    format::HandleId                            instanceData,
    VkDeviceSize                                instanceOffset,
    VkBool32                                    update,
    format::HandleId                            dst,
    format::HandleId                            src,
    format::HandleId                            scratch,
    VkDeviceSize                                scratchOffset)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkAccelerationStructureInfoNV(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
/* instanceData */
/* instanceOffset */
/* update */
/* dst */
/* src */
/* scratch */
/* scratchOffset */
    m_pfnLoader.AddMethodName("vkCmdBuildAccelerationStructureNV");
    fprintf(file,
            "loaded_vkCmdBuildAccelerationStructureNV(%s, &%s, %s, %luUL, %u, %s, %s, %s, %luUL);\n",
            this->GetHandle(commandBuffer).c_str(),
            pInfoStruct.c_str(),
            this->GetHandle(instanceData).c_str(),
            instanceOffset,
            update,
            this->GetHandle(dst).c_str(),
            this->GetHandle(src).c_str(),
            this->GetHandle(scratch).c_str(),
            scratchOffset);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV);
}

void VulkanCppConsumer::Process_vkCmdCopyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dst,
    format::HandleId                            src,
    VkCopyAccelerationStructureModeKHR          mode)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* dst */
/* src */
/* mode */
    m_pfnLoader.AddMethodName("vkCmdCopyAccelerationStructureNV");
    fprintf(file,
            "loaded_vkCmdCopyAccelerationStructureNV(%s, %s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(dst).c_str(),
            this->GetHandle(src).c_str(),
            util::ToString<VkCopyAccelerationStructureModeKHR>(mode).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV);
}

void VulkanCppConsumer::Process_vkCmdTraceRaysNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            raygenShaderBindingTableBuffer,
    VkDeviceSize                                raygenShaderBindingOffset,
    format::HandleId                            missShaderBindingTableBuffer,
    VkDeviceSize                                missShaderBindingOffset,
    VkDeviceSize                                missShaderBindingStride,
    format::HandleId                            hitShaderBindingTableBuffer,
    VkDeviceSize                                hitShaderBindingOffset,
    VkDeviceSize                                hitShaderBindingStride,
    format::HandleId                            callableShaderBindingTableBuffer,
    VkDeviceSize                                callableShaderBindingOffset,
    VkDeviceSize                                callableShaderBindingStride,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* raygenShaderBindingTableBuffer */
/* raygenShaderBindingOffset */
/* missShaderBindingTableBuffer */
/* missShaderBindingOffset */
/* missShaderBindingStride */
/* hitShaderBindingTableBuffer */
/* hitShaderBindingOffset */
/* hitShaderBindingStride */
/* callableShaderBindingTableBuffer */
/* callableShaderBindingOffset */
/* callableShaderBindingStride */
/* width */
/* height */
/* depth */
    m_pfnLoader.AddMethodName("vkCmdTraceRaysNV");
    fprintf(file,
            "loaded_vkCmdTraceRaysNV(%s, %s, %luUL, %s, %luUL, %luUL, %s, %luUL, %luUL, %s, %luUL, %luUL, %u, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(raygenShaderBindingTableBuffer).c_str(),
            raygenShaderBindingOffset,
            this->GetHandle(missShaderBindingTableBuffer).c_str(),
            missShaderBindingOffset,
            missShaderBindingStride,
            this->GetHandle(hitShaderBindingTableBuffer).c_str(),
            hitShaderBindingOffset,
            hitShaderBindingStride,
            this->GetHandle(callableShaderBindingTableBuffer).c_str(),
            callableShaderBindingOffset,
            callableShaderBindingStride,
            width,
            height,
            depth);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdTraceRaysNV);
}

void VulkanCppConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructures,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* accelerationStructureCount */
/* pAccelerationStructures */
    std::string pAccelerationStructuresArray = "NULL";
    std::string pAccelerationStructuresValues = toStringJoin(pAccelerationStructures->GetPointer(),
                                                             pAccelerationStructures->GetPointer() + accelerationStructureCount,
                                                             [&](const format::HandleId current) { return this->GetHandle(current); },
                                                             ", ");
    if (accelerationStructureCount == 1) {
        pAccelerationStructuresArray = "&" + pAccelerationStructuresValues;
    } else if (accelerationStructureCount > 1) {
        pAccelerationStructuresArray = "pAccelerationStructuresArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkAccelerationStructureNV %s[] = { %s };\n", pAccelerationStructuresArray.c_str(), pAccelerationStructuresValues.c_str());
    }
/* queryType */
/* queryPool */
/* firstQuery */
    m_pfnLoader.AddMethodName("vkCmdWriteAccelerationStructuresPropertiesNV");
    fprintf(file,
            "loaded_vkCmdWriteAccelerationStructuresPropertiesNV(%s, %u, %s, %s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            accelerationStructureCount,
            pAccelerationStructuresArray.c_str(),
            util::ToString<VkQueryType>(queryType).c_str(),
            this->GetHandle(queryPool).c_str(),
            firstQuery);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV);
}

void VulkanCppConsumer::Process_vkCompileDeferredNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    shader)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pipeline */
/* shader */
    m_pfnLoader.AddMethodName("vkCompileDeferredNV");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCompileDeferredNV(%s, %s, %u), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipeline).c_str(),
            shader,
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCompileDeferredNV);
}

void VulkanCppConsumer::Process_vkCreateAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructure)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkAccelerationStructureCreateInfoNV(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pAccelerationStructure */
    std::string pAccelerationStructureName = "pAccelerationStructure_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV));
    AddKnownVariables("VkAccelerationStructureNV", pAccelerationStructureName, pAccelerationStructure->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pAccelerationStructureName,
                         pAccelerationStructure->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateAccelerationStructureNV");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateAccelerationStructureNV(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pAccelerationStructureName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV);
}

void VulkanCppConsumer::Process_vkCreateRayTracingPipelinesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoNV>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pipelineCache */
/* createInfoCount */
/* pCreateInfos */
    std::stringstream stream_pCreateInfos;
    std::string pCreateInfosArray = "NULL";
    PointerPairContainer<decltype(pCreateInfos->GetPointer()), decltype(pCreateInfos->GetMetaStructPointer())> pCreateInfosPair{ pCreateInfos->GetPointer(), pCreateInfos->GetMetaStructPointer(), createInfoCount };
    std::string pCreateInfosNames = toStringJoin(pCreateInfosPair.begin(),
                                                 pCreateInfosPair.end(),
                                                 [&](auto pair) { return GenerateStruct_VkRayTracingPipelineCreateInfoNV(stream_pCreateInfos, pair.t1, pair.t2, *this); },
                                                 ", ");
    fprintf(file, "\n%s", stream_pCreateInfos.str().c_str());
    if (createInfoCount == 1) {
        pCreateInfosArray = "&" + pCreateInfosNames;
    } else if (createInfoCount > 1) {
        pCreateInfosArray = "pCreateInfos_" + std::to_string(this->getNextId());
        fprintf(file, "VkRayTracingPipelineCreateInfoNV %s[] = { %s };\n", pCreateInfosArray.c_str(), pCreateInfosNames.c_str());
    }
/* pAllocator */
/* pPipelines */
    std::string pPipelinesName = "pPipelines_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_PIPELINE));
    AddKnownVariables("VkPipeline", pPipelinesName, pPipelines->GetPointer(), createInfoCount);
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pPipelinesName,
                         pPipelines->GetPointer(), createInfoCount);
    }
    m_pfnLoader.AddMethodName("vkCreateRayTracingPipelinesNV");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateRayTracingPipelinesNV(%s, %s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipelineCache).c_str(),
            createInfoCount,
            pCreateInfosArray.c_str(),
            "nullptr",
            pPipelinesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV);
}

void VulkanCppConsumer::Process_vkDestroyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* accelerationStructure */
/* pAllocator */
    m_pfnLoader.AddMethodName("vkDestroyAccelerationStructureNV");
    fprintf(file,
            "loaded_vkDestroyAccelerationStructureNV(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(accelerationStructure).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV);
}

void VulkanCppConsumer::Process_vkGetAccelerationStructureHandleNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* accelerationStructure */
/* dataSize */
/* pData */
    std::string pDataName = "pData_" + std::to_string(this->getNextId());
    fprintf(file, "uint8_t %s[%ld];\n", pDataName.c_str(), dataSize);
    m_pfnLoader.AddMethodName("vkGetAccelerationStructureHandleNV");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetAccelerationStructureHandleNV(%s, %s, %lu, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(accelerationStructure).c_str(),
            dataSize,
            pDataName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV);
}

void VulkanCppConsumer::Process_vkGetAccelerationStructureMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2KHR>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkAccelerationStructureMemoryRequirementsInfoNV(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
/* pMemoryRequirements */
    std::string pMemoryRequirementsName = "pMemoryRequirements_" + std::to_string(this->getNextId());
    fprintf(file, "VkMemoryRequirements2KHR %s;\n", pMemoryRequirementsName.c_str());
    m_pfnLoader.AddMethodName("vkGetAccelerationStructureMemoryRequirementsNV");
    fprintf(file,
            "loaded_vkGetAccelerationStructureMemoryRequirementsNV(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str(),
            pMemoryRequirementsName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV);
}

void VulkanCppConsumer::Process_vkGetRayTracingShaderGroupHandlesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pipeline */
/* firstGroup */
/* groupCount */
/* dataSize */
/* pData */
    std::string pDataName = "pData_" + std::to_string(this->getNextId());
    fprintf(file, "uint8_t %s[%ld];\n", pDataName.c_str(), dataSize);
    m_pfnLoader.AddMethodName("vkGetRayTracingShaderGroupHandlesKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetRayTracingShaderGroupHandlesKHR(%s, %s, %u, %u, %lu, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipeline).c_str(),
            firstGroup,
            groupCount,
            dataSize,
            pDataName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR);
}

void VulkanCppConsumer::Process_vkGetRayTracingShaderGroupHandlesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pipeline */
/* firstGroup */
/* groupCount */
/* dataSize */
/* pData */
    std::string pDataName = "pData_" + std::to_string(this->getNextId());
    fprintf(file, "uint8_t %s[%ld];\n", pDataName.c_str(), dataSize);
    m_pfnLoader.AddMethodName("vkGetRayTracingShaderGroupHandlesNV");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetRayTracingShaderGroupHandlesNV(%s, %s, %u, %u, %lu, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipeline).c_str(),
            firstGroup,
            groupCount,
            dataSize,
            pDataName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV);
}





void VulkanCppConsumer::Process_vkGetMemoryHostPointerPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    pHostPointer,
    StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>* pMemoryHostPointerProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* handleType */
/* pHostPointer */
    std::string pHostPointerName = "pHostPointer_" + std::to_string(this->getNextId());
    fprintf(file, "void* %s;\n", pHostPointerName.c_str());
/* pMemoryHostPointerProperties */
    std::string pMemoryHostPointerPropertiesName = "pMemoryHostPointerProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pMemoryHostPointerProperties;
    pMemoryHostPointerPropertiesName = GenerateStruct_VkMemoryHostPointerPropertiesEXT(stream_pMemoryHostPointerProperties,
                                                                      pMemoryHostPointerProperties->GetPointer(),
                                                                      pMemoryHostPointerProperties->GetMetaStructPointer(),
                                                                      *this);
    fprintf(file, "\n%s", stream_pMemoryHostPointerProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetMemoryHostPointerPropertiesEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetMemoryHostPointerPropertiesEXT(%s, %s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkExternalMemoryHandleTypeFlagBits>(handleType).c_str(),
            pHostPointerName.c_str(),
            pMemoryHostPointerPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT);
}

void VulkanCppConsumer::Process_vkCmdWriteBufferMarkerAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pipelineStage */
/* dstBuffer */
/* dstOffset */
/* marker */
    m_pfnLoader.AddMethodName("vkCmdWriteBufferMarkerAMD");
    fprintf(file,
            "loaded_vkCmdWriteBufferMarkerAMD(%s, %s, %s, %luUL, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineStageFlagBits>(pipelineStage).c_str(),
            this->GetHandle(dstBuffer).c_str(),
            dstOffset,
            marker);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD);
}


void VulkanCppConsumer::Process_vkGetCalibratedTimestampsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    timestampCount,
    StructPointerDecoder<Decoded_VkCalibratedTimestampInfoEXT>* pTimestampInfos,
    PointerDecoder<uint64_t>*                   pTimestamps,
    PointerDecoder<uint64_t>*                   pMaxDeviation)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* timestampCount */
/* pTimestampInfos */
    std::stringstream stream_pTimestampInfos;
    std::string pTimestampInfosArray = "NULL";
    PointerPairContainer<decltype(pTimestampInfos->GetPointer()), decltype(pTimestampInfos->GetMetaStructPointer())> pTimestampInfosPair{ pTimestampInfos->GetPointer(), pTimestampInfos->GetMetaStructPointer(), timestampCount };
    std::string pTimestampInfosNames = toStringJoin(pTimestampInfosPair.begin(),
                                                    pTimestampInfosPair.end(),
                                                    [&](auto pair) { return GenerateStruct_VkCalibratedTimestampInfoEXT(stream_pTimestampInfos, pair.t1, pair.t2, *this); },
                                                    ", ");
    fprintf(file, "\n%s", stream_pTimestampInfos.str().c_str());
    if (timestampCount == 1) {
        pTimestampInfosArray = "&" + pTimestampInfosNames;
    } else if (timestampCount > 1) {
        pTimestampInfosArray = "pTimestampInfos_" + std::to_string(this->getNextId());
        fprintf(file, "VkCalibratedTimestampInfoEXT %s[] = { %s };\n", pTimestampInfosArray.c_str(), pTimestampInfosNames.c_str());
    }
/* pTimestamps */
    std::string pTimestampsName = "pTimestamps_" + std::to_string(this->getNextId());
    fprintf(file, "uint64_t %s[%d];\n", pTimestampsName.c_str(), timestampCount);
/* pMaxDeviation */
    std::string pMaxDeviationName = "pMaxDeviation_" + std::to_string(this->getNextId());
    fprintf(file, "uint64_t %s;\n", pMaxDeviationName.c_str());
    m_pfnLoader.AddMethodName("vkGetCalibratedTimestampsEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetCalibratedTimestampsEXT(%s, %u, %s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            timestampCount,
            pTimestampInfosArray.c_str(),
            pTimestampsName.c_str(),
            pMaxDeviationName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pTimeDomainCount,
    PointerDecoder<VkTimeDomainEXT>*            pTimeDomains)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pTimeDomainCount */
    std::string pTimeDomainCountName = "pTimeDomainCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pTimeDomainCountName.c_str());
/* pTimeDomains */
    std::string pTimeDomainsName = "pTimeDomains_" + std::to_string(this->getNextId());
    const uint32_t* in_pTimeDomainCount = pTimeDomainCount->GetPointer();
    fprintf(file, "VkTimeDomainEXT %s[%d];\n", pTimeDomainsName.c_str(), *in_pTimeDomainCount);
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceCalibrateableTimeDomainsEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(%s, &%s, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pTimeDomainCountName.c_str(),
            pTimeDomainsName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT);
}








void VulkanCppConsumer::Process_vkCmdDrawMeshTasksIndirectCountNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* buffer */
/* offset */
/* countBuffer */
/* countBufferOffset */
/* maxDrawCount */
/* stride */
    m_pfnLoader.AddMethodName("vkCmdDrawMeshTasksIndirectCountNV");
    fprintf(file,
            "loaded_vkCmdDrawMeshTasksIndirectCountNV(%s, %s, %luUL, %s, %luUL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            this->GetHandle(countBuffer).c_str(),
            countBufferOffset,
            maxDrawCount,
            stride);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV);
}

void VulkanCppConsumer::Process_vkCmdDrawMeshTasksIndirectNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* buffer */
/* offset */
/* drawCount */
/* stride */
    m_pfnLoader.AddMethodName("vkCmdDrawMeshTasksIndirectNV");
    fprintf(file,
            "loaded_vkCmdDrawMeshTasksIndirectNV(%s, %s, %luUL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            drawCount,
            stride);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV);
}

void VulkanCppConsumer::Process_vkCmdDrawMeshTasksNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* taskCount */
/* firstTask */
    m_pfnLoader.AddMethodName("vkCmdDrawMeshTasksNV");
    fprintf(file,
            "loaded_vkCmdDrawMeshTasksNV(%s, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            taskCount,
            firstTask);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV);
}



void VulkanCppConsumer::Process_vkCmdSetExclusiveScissorEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    PointerDecoder<VkBool32>*                   pExclusiveScissorEnables)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* firstExclusiveScissor */
/* exclusiveScissorCount */
/* pExclusiveScissorEnables */
    std::string pExclusiveScissorEnablesArray = "pExclusiveScissorEnables_" + std::to_string(this->getNextId());
    if (exclusiveScissorCount > 0) {
        std::string pExclusiveScissorEnablesValues = toStringJoin(pExclusiveScissorEnables->GetPointer(),
                                                                  pExclusiveScissorEnables->GetPointer() + exclusiveScissorCount,
                                                                  [&](const auto current) { return std::to_string(current) + ""; },
                                                                  ", ");
        fprintf(file, "VkBool32 %s[] = { %s };\n", pExclusiveScissorEnablesArray.c_str(), pExclusiveScissorEnablesValues.c_str());
    } else {
        pExclusiveScissorEnablesArray = "NULL";
    }
    m_pfnLoader.AddMethodName("vkCmdSetExclusiveScissorEnableNV");
    fprintf(file,
            "loaded_vkCmdSetExclusiveScissorEnableNV(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstExclusiveScissor,
            exclusiveScissorCount,
            pExclusiveScissorEnablesArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV);
}

void VulkanCppConsumer::Process_vkCmdSetExclusiveScissorNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pExclusiveScissors)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* firstExclusiveScissor */
/* exclusiveScissorCount */
/* pExclusiveScissors */
    std::stringstream stream_pExclusiveScissors;
    std::string pExclusiveScissorsArray = "NULL";
    PointerPairContainer<decltype(pExclusiveScissors->GetPointer()), decltype(pExclusiveScissors->GetMetaStructPointer())> pExclusiveScissorsPair{ pExclusiveScissors->GetPointer(), pExclusiveScissors->GetMetaStructPointer(), exclusiveScissorCount };
    std::string pExclusiveScissorsNames = toStringJoin(pExclusiveScissorsPair.begin(),
                                                       pExclusiveScissorsPair.end(),
                                                       [&](auto pair) { return GenerateStruct_VkRect2D(stream_pExclusiveScissors, pair.t1, pair.t2, *this); },
                                                       ", ");
    fprintf(file, "\n%s", stream_pExclusiveScissors.str().c_str());
    if (exclusiveScissorCount == 1) {
        pExclusiveScissorsArray = "&" + pExclusiveScissorsNames;
    } else if (exclusiveScissorCount > 1) {
        pExclusiveScissorsArray = "pExclusiveScissors_" + std::to_string(this->getNextId());
        fprintf(file, "VkRect2D %s[] = { %s };\n", pExclusiveScissorsArray.c_str(), pExclusiveScissorsNames.c_str());
    }
    m_pfnLoader.AddMethodName("vkCmdSetExclusiveScissorNV");
    fprintf(file,
            "loaded_vkCmdSetExclusiveScissorNV(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstExclusiveScissor,
            exclusiveScissorCount,
            pExclusiveScissorsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV);
}

void VulkanCppConsumer::Process_vkCmdSetCheckpointNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint64_t                                    pCheckpointMarker)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pCheckpointMarker */
    std::string pCheckpointMarkerName = "pCheckpointMarker_" + std::to_string(this->getNextId());
    fprintf(file, "void* %s;\n", pCheckpointMarkerName.c_str());
    m_pfnLoader.AddMethodName("vkCmdSetCheckpointNV");
    fprintf(file,
            "loaded_vkCmdSetCheckpointNV(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pCheckpointMarkerName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCheckpointNV);
}

void VulkanCppConsumer::Process_vkGetQueueCheckpointDataNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointDataNV>* pCheckpointData)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* queue */
/* pCheckpointDataCount */
    std::string pCheckpointDataCountName = "pCheckpointDataCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pCheckpointDataCountName.c_str());
/* pCheckpointData */
    std::string pCheckpointDataName = "pCheckpointData_" + std::to_string(this->getNextId());
    std::stringstream stream_pCheckpointData;
    pCheckpointDataName = GenerateStruct_VkCheckpointDataNV(stream_pCheckpointData,
                                                         pCheckpointData->GetPointer(),
                                                         pCheckpointData->GetMetaStructPointer(),
                                                         *this);
    fprintf(file, "\n%s", stream_pCheckpointData.str().c_str());
    m_pfnLoader.AddMethodName("vkGetQueueCheckpointDataNV");
    fprintf(file,
            "loaded_vkGetQueueCheckpointDataNV(%s, &%s, &%s);\n",
            this->GetHandle(queue).c_str(),
            pCheckpointDataCountName.c_str(),
            pCheckpointDataName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV);
}


void VulkanCppConsumer::Process_vkAcquirePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL>* pAcquireInfo,
    HandlePointerDecoder<VkPerformanceConfigurationINTEL>* pConfiguration)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pAcquireInfo */
    std::stringstream stream_pAcquireInfo;
    std::string pAcquireInfoStruct = GenerateStruct_VkPerformanceConfigurationAcquireInfoINTEL(stream_pAcquireInfo,
                                                                    pAcquireInfo->GetPointer(),
                                                                    pAcquireInfo->GetMetaStructPointer(),
                                                                    *this);
    fprintf(file, "\n%s", stream_pAcquireInfo.str().c_str());
/* pConfiguration */
    std::string pConfigurationName = "pConfiguration_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL));
    AddKnownVariables("VkPerformanceConfigurationINTEL", pConfigurationName, pConfiguration->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pConfigurationName,
                         pConfiguration->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkAcquirePerformanceConfigurationINTEL");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkAcquirePerformanceConfigurationINTEL(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pAcquireInfoStruct.c_str(),
            pConfigurationName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL);
}

void VulkanCppConsumer::Process_vkCmdSetPerformanceMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pMarkerInfo */
    std::stringstream stream_pMarkerInfo;
    std::string pMarkerInfoStruct = GenerateStruct_VkPerformanceMarkerInfoINTEL(stream_pMarkerInfo,
                                                                   pMarkerInfo->GetPointer(),
                                                                   pMarkerInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pMarkerInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdSetPerformanceMarkerINTEL");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCmdSetPerformanceMarkerINTEL(%s, &%s), %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pMarkerInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL);
}

void VulkanCppConsumer::Process_vkCmdSetPerformanceOverrideINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pOverrideInfo */
    std::stringstream stream_pOverrideInfo;
    std::string pOverrideInfoStruct = GenerateStruct_VkPerformanceOverrideInfoINTEL(stream_pOverrideInfo,
                                                                     pOverrideInfo->GetPointer(),
                                                                     pOverrideInfo->GetMetaStructPointer(),
                                                                     *this);
    fprintf(file, "\n%s", stream_pOverrideInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdSetPerformanceOverrideINTEL");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCmdSetPerformanceOverrideINTEL(%s, &%s), %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pOverrideInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL);
}

void VulkanCppConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pMarkerInfo */
    std::stringstream stream_pMarkerInfo;
    std::string pMarkerInfoStruct = GenerateStruct_VkPerformanceStreamMarkerInfoINTEL(stream_pMarkerInfo,
                                                                   pMarkerInfo->GetPointer(),
                                                                   pMarkerInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pMarkerInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdSetPerformanceStreamMarkerINTEL");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCmdSetPerformanceStreamMarkerINTEL(%s, &%s), %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pMarkerInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL);
}

void VulkanCppConsumer::Process_vkGetPerformanceParameterINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkPerformanceParameterTypeINTEL             parameter,
    StructPointerDecoder<Decoded_VkPerformanceValueINTEL>* pValue)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* parameter */
/* pValue */
    std::string pValueName = "pValue_" + std::to_string(this->getNextId());
    fprintf(file, "VkPerformanceValueINTEL %s;\n", pValueName.c_str());
    m_pfnLoader.AddMethodName("vkGetPerformanceParameterINTEL");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPerformanceParameterINTEL(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkPerformanceParameterTypeINTEL>(parameter).c_str(),
            pValueName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL);
}

void VulkanCppConsumer::Process_vkInitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>* pInitializeInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInitializeInfo */
    std::stringstream stream_pInitializeInfo;
    std::string pInitializeInfoStruct = GenerateStruct_VkInitializePerformanceApiInfoINTEL(stream_pInitializeInfo,
                                                                       pInitializeInfo->GetPointer(),
                                                                       pInitializeInfo->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "\n%s", stream_pInitializeInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkInitializePerformanceApiINTEL");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkInitializePerformanceApiINTEL(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pInitializeInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL);
}

void VulkanCppConsumer::Process_vkQueueSetPerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    format::HandleId                            configuration)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* queue */
/* configuration */
    m_pfnLoader.AddMethodName("vkQueueSetPerformanceConfigurationINTEL");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkQueueSetPerformanceConfigurationINTEL(%s, %s), %s);\n",
            this->GetHandle(queue).c_str(),
            this->GetHandle(configuration).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL);
}

void VulkanCppConsumer::Process_vkReleasePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            configuration)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* configuration */
    m_pfnLoader.AddMethodName("vkReleasePerformanceConfigurationINTEL");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkReleasePerformanceConfigurationINTEL(%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(configuration).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL);
}

void VulkanCppConsumer::Process_vkUninitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
    m_pfnLoader.AddMethodName("vkUninitializePerformanceApiINTEL");
    fprintf(file,
            "loaded_vkUninitializePerformanceApiINTEL(%s);\n",
            this->GetHandle(device).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL);
}


void VulkanCppConsumer::Process_vkSetLocalDimmingAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapChain,
    VkBool32                                    localDimmingEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* swapChain */
/* localDimmingEnable */
    m_pfnLoader.AddMethodName("vkSetLocalDimmingAMD");
    fprintf(file,
            "loaded_vkSetLocalDimmingAMD(%s, %s, %u);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapChain).c_str(),
            localDimmingEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSetLocalDimmingAMD);
}

void VulkanCppConsumer::Process_vkCreateImagePipeSurfaceFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* instance */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkImagePipeSurfaceCreateInfoFUCHSIA(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pSurface */
    std::string pSurfaceName = "pSurface_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", pSurfaceName, pSurface->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pSurfaceName,
                         pSurface->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateImagePipeSurfaceFUCHSIA");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateImagePipeSurfaceFUCHSIA(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pSurfaceName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA);
}

void VulkanCppConsumer::Process_vkCreateMetalSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* instance */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkMetalSurfaceCreateInfoEXT(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pSurface */
    std::string pSurfaceName = "pSurface_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", pSurfaceName, pSurface->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pSurfaceName,
                         pSurface->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateMetalSurfaceEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateMetalSurfaceEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pSurfaceName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT);
}












void VulkanCppConsumer::Process_vkGetBufferDeviceAddressEXT(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkBufferDeviceAddressInfo(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkGetBufferDeviceAddressEXT");
    fprintf(file,
            "loaded_vkGetBufferDeviceAddressEXT(%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceToolPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pToolCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pToolCount */
    std::string pToolCountName = "pToolCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pToolCountName.c_str());
/* pToolProperties */
    std::string pToolPropertiesName = "pToolProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pToolProperties;
    pToolPropertiesName = GenerateStruct_VkPhysicalDeviceToolProperties(stream_pToolProperties,
                                                         pToolProperties->GetPointer(),
                                                         pToolProperties->GetMetaStructPointer(),
                                                         *this);
    fprintf(file, "\n%s", stream_pToolProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceToolPropertiesEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceToolPropertiesEXT(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pToolCountName.c_str(),
            pToolPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT);
}



void VulkanCppConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pPropertyCount */
    std::string pPropertyCountName = "pPropertyCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pPropertyCountName.c_str());
/* pProperties */
    std::string pPropertiesName = "pProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pProperties;
    pPropertiesName = GenerateStruct_VkCooperativeMatrixPropertiesNV(stream_pProperties,
                                                     pProperties->GetPointer(),
                                                     pProperties->GetMetaStructPointer(),
                                                     *this);
    fprintf(file, "\n%s", stream_pProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceCooperativeMatrixPropertiesNV");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pPropertyCountName.c_str(),
            pPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pCombinationCount,
    StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV>* pCombinations)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pCombinationCount */
    std::string pCombinationCountName = "pCombinationCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pCombinationCountName.c_str());
/* pCombinations */
    std::string pCombinationsName = "pCombinations_" + std::to_string(this->getNextId());
    std::stringstream stream_pCombinations;
    pCombinationsName = GenerateStruct_VkFramebufferMixedSamplesCombinationNV(stream_pCombinations,
                                                       pCombinations->GetPointer(),
                                                       pCombinations->GetMetaStructPointer(),
                                                       *this);
    fprintf(file, "\n%s", stream_pCombinations.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pCombinationCountName.c_str(),
            pCombinationsName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV);
}




void VulkanCppConsumer::Process_vkAcquireFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* swapchain */
    m_pfnLoader.AddMethodName("vkAcquireFullScreenExclusiveModeEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkAcquireFullScreenExclusiveModeEXT(%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapchain).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT);
}

void VulkanCppConsumer::Process_vkGetDeviceGroupSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pSurfaceInfo */
    std::stringstream stream_pSurfaceInfo;
    std::string pSurfaceInfoStruct = GenerateStruct_VkPhysicalDeviceSurfaceInfo2KHR(stream_pSurfaceInfo,
                                                                    pSurfaceInfo->GetPointer(),
                                                                    pSurfaceInfo->GetMetaStructPointer(),
                                                                    *this);
    fprintf(file, "\n%s", stream_pSurfaceInfo.str().c_str());
/* pModes */
    std::string pModesName = "pModes_" + std::to_string(this->getNextId());
    fprintf(file, "VkDeviceGroupPresentModeFlagsKHR %s;\n", pModesName.c_str());
    m_pfnLoader.AddMethodName("vkGetDeviceGroupSurfacePresentModes2EXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetDeviceGroupSurfacePresentModes2EXT(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pSurfaceInfoStruct.c_str(),
            pModesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<uint32_t>*                   pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>*           pPresentModes)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pSurfaceInfo */
    std::stringstream stream_pSurfaceInfo;
    std::string pSurfaceInfoStruct = GenerateStruct_VkPhysicalDeviceSurfaceInfo2KHR(stream_pSurfaceInfo,
                                                                    pSurfaceInfo->GetPointer(),
                                                                    pSurfaceInfo->GetMetaStructPointer(),
                                                                    *this);
    fprintf(file, "\n%s", stream_pSurfaceInfo.str().c_str());
/* pPresentModeCount */
    std::string pPresentModeCountName = "pPresentModeCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pPresentModeCountName.c_str());
/* pPresentModes */
    std::string pPresentModesName = "pPresentModes_" + std::to_string(this->getNextId());
    const uint32_t* in_pPresentModeCount = pPresentModeCount->GetPointer();
    fprintf(file, "VkPresentModeKHR %s[%d];\n", pPresentModesName.c_str(), *in_pPresentModeCount);
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceSurfacePresentModes2EXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfacePresentModes2EXT(%s, &%s, &%s, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pSurfaceInfoStruct.c_str(),
            pPresentModeCountName.c_str(),
            pPresentModesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT);
}

void VulkanCppConsumer::Process_vkReleaseFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* swapchain */
    m_pfnLoader.AddMethodName("vkReleaseFullScreenExclusiveModeEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkReleaseFullScreenExclusiveModeEXT(%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapchain).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT);
}

void VulkanCppConsumer::Process_vkCreateHeadlessSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* instance */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkHeadlessSurfaceCreateInfoEXT(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pSurface */
    std::string pSurfaceName = "pSurface_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", pSurfaceName, pSurface->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pSurfaceName,
                         pSurface->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateHeadlessSurfaceEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateHeadlessSurfaceEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pSurfaceName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT);
}

void VulkanCppConsumer::Process_vkCmdSetLineStippleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* lineStippleFactor */
/* lineStipplePattern */
    m_pfnLoader.AddMethodName("vkCmdSetLineStippleEXT");
    fprintf(file,
            "loaded_vkCmdSetLineStippleEXT(%s, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            lineStippleFactor,
            lineStipplePattern);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT);
}


void VulkanCppConsumer::Process_vkResetQueryPoolEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* queryPool */
/* firstQuery */
/* queryCount */
    m_pfnLoader.AddMethodName("vkResetQueryPoolEXT");
    fprintf(file,
            "loaded_vkResetQueryPoolEXT(%s, %s, %u, %u);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(queryPool).c_str(),
            firstQuery,
            queryCount);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkResetQueryPoolEXT);
}


void VulkanCppConsumer::Process_vkCmdBindVertexBuffers2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes,
    PointerDecoder<VkDeviceSize>*               pStrides)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* firstBinding */
/* bindingCount */
/* pBuffers */
    std::string pBuffersArray = "NULL";
    std::string pBuffersValues = toStringJoin(pBuffers->GetPointer(),
                                              pBuffers->GetPointer() + bindingCount,
                                              [&](const format::HandleId current) { return this->GetHandle(current); },
                                              ", ");
    if (bindingCount == 1) {
        pBuffersArray = "&" + pBuffersValues;
    } else if (bindingCount > 1) {
        pBuffersArray = "pBuffersArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkBuffer %s[] = { %s };\n", pBuffersArray.c_str(), pBuffersValues.c_str());
    }
/* pOffsets */
    std::string pOffsetsArray = "pOffsets_" + std::to_string(this->getNextId());
    if (bindingCount > 0) {
        std::string pOffsetsValues = toStringJoin(pOffsets->GetPointer(),
                                                  pOffsets->GetPointer() + bindingCount,
                                                  [&](const auto current) { return std::to_string(current) + "UL"; },
                                                  ", ");
        fprintf(file, "VkDeviceSize %s[] = { %s };\n", pOffsetsArray.c_str(), pOffsetsValues.c_str());
    } else {
        pOffsetsArray = "NULL";
    }
/* pSizes */
    std::string pSizesArray = "pSizes_" + std::to_string(this->getNextId());
    if (bindingCount > 0) {
        std::string pSizesValues = toStringJoin(pSizes->GetPointer(),
                                                pSizes->GetPointer() + bindingCount,
                                                [&](const auto current) { return std::to_string(current) + "UL"; },
                                                ", ");
        fprintf(file, "VkDeviceSize %s[] = { %s };\n", pSizesArray.c_str(), pSizesValues.c_str());
    } else {
        pSizesArray = "NULL";
    }
/* pStrides */
    std::string pStridesArray = "pStrides_" + std::to_string(this->getNextId());
    if (bindingCount > 0) {
        std::string pStridesValues = toStringJoin(pStrides->GetPointer(),
                                                  pStrides->GetPointer() + bindingCount,
                                                  [&](const auto current) { return std::to_string(current) + "UL"; },
                                                  ", ");
        fprintf(file, "VkDeviceSize %s[] = { %s };\n", pStridesArray.c_str(), pStridesValues.c_str());
    } else {
        pStridesArray = "NULL";
    }
    m_pfnLoader.AddMethodName("vkCmdBindVertexBuffers2EXT");
    fprintf(file,
            "loaded_vkCmdBindVertexBuffers2EXT(%s, %u, %u, %s, %s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstBinding,
            bindingCount,
            pBuffersArray.c_str(),
            pOffsetsArray.c_str(),
            pSizesArray.c_str(),
            pStridesArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT);
}

void VulkanCppConsumer::Process_vkCmdSetCullModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* cullMode */
    m_pfnLoader.AddMethodName("vkCmdSetCullModeEXT");
    fprintf(file,
            "loaded_vkCmdSetCullModeEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkCullModeFlags>(cullMode).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCullModeEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDepthBoundsTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* depthBoundsTestEnable */
    m_pfnLoader.AddMethodName("vkCmdSetDepthBoundsTestEnableEXT");
    fprintf(file,
            "loaded_vkCmdSetDepthBoundsTestEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            depthBoundsTestEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDepthCompareOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* depthCompareOp */
    m_pfnLoader.AddMethodName("vkCmdSetDepthCompareOpEXT");
    fprintf(file,
            "loaded_vkCmdSetDepthCompareOpEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkCompareOp>(depthCompareOp).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDepthTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* depthTestEnable */
    m_pfnLoader.AddMethodName("vkCmdSetDepthTestEnableEXT");
    fprintf(file,
            "loaded_vkCmdSetDepthTestEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            depthTestEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDepthWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* depthWriteEnable */
    m_pfnLoader.AddMethodName("vkCmdSetDepthWriteEnableEXT");
    fprintf(file,
            "loaded_vkCmdSetDepthWriteEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            depthWriteEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetFrontFaceEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* frontFace */
    m_pfnLoader.AddMethodName("vkCmdSetFrontFaceEXT");
    fprintf(file,
            "loaded_vkCmdSetFrontFaceEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkFrontFace>(frontFace).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT);
}

void VulkanCppConsumer::Process_vkCmdSetPrimitiveTopologyEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* primitiveTopology */
    m_pfnLoader.AddMethodName("vkCmdSetPrimitiveTopologyEXT");
    fprintf(file,
            "loaded_vkCmdSetPrimitiveTopologyEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPrimitiveTopology>(primitiveTopology).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT);
}

void VulkanCppConsumer::Process_vkCmdSetScissorWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* scissorCount */
/* pScissors */
    std::stringstream stream_pScissors;
    std::string pScissorsArray = "NULL";
    PointerPairContainer<decltype(pScissors->GetPointer()), decltype(pScissors->GetMetaStructPointer())> pScissorsPair{ pScissors->GetPointer(), pScissors->GetMetaStructPointer(), scissorCount };
    std::string pScissorsNames = toStringJoin(pScissorsPair.begin(),
                                              pScissorsPair.end(),
                                              [&](auto pair) { return GenerateStruct_VkRect2D(stream_pScissors, pair.t1, pair.t2, *this); },
                                              ", ");
    fprintf(file, "\n%s", stream_pScissors.str().c_str());
    if (scissorCount == 1) {
        pScissorsArray = "&" + pScissorsNames;
    } else if (scissorCount > 1) {
        pScissorsArray = "pScissors_" + std::to_string(this->getNextId());
        fprintf(file, "VkRect2D %s[] = { %s };\n", pScissorsArray.c_str(), pScissorsNames.c_str());
    }
    m_pfnLoader.AddMethodName("vkCmdSetScissorWithCountEXT");
    fprintf(file,
            "loaded_vkCmdSetScissorWithCountEXT(%s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            scissorCount,
            pScissorsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT);
}

void VulkanCppConsumer::Process_vkCmdSetStencilOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* faceMask */
/* failOp */
/* passOp */
/* depthFailOp */
/* compareOp */
    m_pfnLoader.AddMethodName("vkCmdSetStencilOpEXT");
    fprintf(file,
            "loaded_vkCmdSetStencilOpEXT(%s, %s, %s, %s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkStencilFaceFlags>(faceMask).c_str(),
            util::ToString<VkStencilOp>(failOp).c_str(),
            util::ToString<VkStencilOp>(passOp).c_str(),
            util::ToString<VkStencilOp>(depthFailOp).c_str(),
            util::ToString<VkCompareOp>(compareOp).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT);
}

void VulkanCppConsumer::Process_vkCmdSetStencilTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* stencilTestEnable */
    m_pfnLoader.AddMethodName("vkCmdSetStencilTestEnableEXT");
    fprintf(file,
            "loaded_vkCmdSetStencilTestEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            stencilTestEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetViewportWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* viewportCount */
/* pViewports */
    std::stringstream stream_pViewports;
    std::string pViewportsArray = "NULL";
    PointerPairContainer<decltype(pViewports->GetPointer()), decltype(pViewports->GetMetaStructPointer())> pViewportsPair{ pViewports->GetPointer(), pViewports->GetMetaStructPointer(), viewportCount };
    std::string pViewportsNames = toStringJoin(pViewportsPair.begin(),
                                               pViewportsPair.end(),
                                               [&](auto pair) { return GenerateStruct_VkViewport(stream_pViewports, pair.t1, pair.t2, *this); },
                                               ", ");
    fprintf(file, "\n%s", stream_pViewports.str().c_str());
    if (viewportCount == 1) {
        pViewportsArray = "&" + pViewportsNames;
    } else if (viewportCount > 1) {
        pViewportsArray = "pViewports_" + std::to_string(this->getNextId());
        fprintf(file, "VkViewport %s[] = { %s };\n", pViewportsArray.c_str(), pViewportsNames.c_str());
    }
    m_pfnLoader.AddMethodName("vkCmdSetViewportWithCountEXT");
    fprintf(file,
            "loaded_vkCmdSetViewportWithCountEXT(%s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            viewportCount,
            pViewportsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT);
}

void VulkanCppConsumer::Process_vkCopyImageToImageEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyImageToImageInfoEXT>* pCopyImageToImageInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCopyImageToImageInfo */
    std::stringstream stream_pCopyImageToImageInfo;
    std::string pCopyImageToImageInfoStruct = GenerateStruct_VkCopyImageToImageInfoEXT(stream_pCopyImageToImageInfo,
                                                                             pCopyImageToImageInfo->GetPointer(),
                                                                             pCopyImageToImageInfo->GetMetaStructPointer(),
                                                                             *this);
    fprintf(file, "\n%s", stream_pCopyImageToImageInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCopyImageToImageEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCopyImageToImageEXT(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCopyImageToImageInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCopyImageToImageEXT);
}

void VulkanCppConsumer::Process_vkCopyImageToMemoryEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyImageToMemoryInfoEXT>* pCopyImageToMemoryInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCopyImageToMemoryInfo */
    std::stringstream stream_pCopyImageToMemoryInfo;
    std::string pCopyImageToMemoryInfoStruct = GenerateStruct_VkCopyImageToMemoryInfoEXT(stream_pCopyImageToMemoryInfo,
                                                                              pCopyImageToMemoryInfo->GetPointer(),
                                                                              pCopyImageToMemoryInfo->GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "\n%s", stream_pCopyImageToMemoryInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCopyImageToMemoryEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCopyImageToMemoryEXT(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCopyImageToMemoryInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCopyImageToMemoryEXT);
}

void VulkanCppConsumer::Process_vkCopyMemoryToImageEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyMemoryToImageInfoEXT>* pCopyMemoryToImageInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCopyMemoryToImageInfo */
    std::stringstream stream_pCopyMemoryToImageInfo;
    std::string pCopyMemoryToImageInfoStruct = GenerateStruct_VkCopyMemoryToImageInfoEXT(stream_pCopyMemoryToImageInfo,
                                                                              pCopyMemoryToImageInfo->GetPointer(),
                                                                              pCopyMemoryToImageInfo->GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "\n%s", stream_pCopyMemoryToImageInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCopyMemoryToImageEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCopyMemoryToImageEXT(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCopyMemoryToImageInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCopyMemoryToImageEXT);
}

void VulkanCppConsumer::Process_vkGetImageSubresourceLayout2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource2KHR>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR>* pLayout)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* image */
/* pSubresource */
    std::stringstream stream_pSubresource;
    std::string pSubresourceStruct = GenerateStruct_VkImageSubresource2KHR(stream_pSubresource,
                                                                    pSubresource->GetPointer(),
                                                                    pSubresource->GetMetaStructPointer(),
                                                                    *this);
    fprintf(file, "\n%s", stream_pSubresource.str().c_str());
/* pLayout */
    std::string pLayoutName = "pLayout_" + std::to_string(this->getNextId());
    std::stringstream stream_pLayout;
    pLayoutName = GenerateStruct_VkSubresourceLayout2KHR(stream_pLayout,
                                                 pLayout->GetPointer(),
                                                 pLayout->GetMetaStructPointer(),
                                                 *this);
    fprintf(file, "\n%s", stream_pLayout.str().c_str());
    m_pfnLoader.AddMethodName("vkGetImageSubresourceLayout2EXT");
    fprintf(file,
            "loaded_vkGetImageSubresourceLayout2EXT(%s, %s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(image).c_str(),
            pSubresourceStruct.c_str(),
            pLayoutName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT);
}

void VulkanCppConsumer::Process_vkTransitionImageLayoutEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    transitionCount,
    StructPointerDecoder<Decoded_VkHostImageLayoutTransitionInfoEXT>* pTransitions)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* transitionCount */
/* pTransitions */
    std::stringstream stream_pTransitions;
    std::string pTransitionsArray = "NULL";
    PointerPairContainer<decltype(pTransitions->GetPointer()), decltype(pTransitions->GetMetaStructPointer())> pTransitionsPair{ pTransitions->GetPointer(), pTransitions->GetMetaStructPointer(), transitionCount };
    std::string pTransitionsNames = toStringJoin(pTransitionsPair.begin(),
                                                 pTransitionsPair.end(),
                                                 [&](auto pair) { return GenerateStruct_VkHostImageLayoutTransitionInfoEXT(stream_pTransitions, pair.t1, pair.t2, *this); },
                                                 ", ");
    fprintf(file, "\n%s", stream_pTransitions.str().c_str());
    if (transitionCount == 1) {
        pTransitionsArray = "&" + pTransitionsNames;
    } else if (transitionCount > 1) {
        pTransitionsArray = "pTransitions_" + std::to_string(this->getNextId());
        fprintf(file, "VkHostImageLayoutTransitionInfoEXT %s[] = { %s };\n", pTransitionsArray.c_str(), pTransitionsNames.c_str());
    }
    m_pfnLoader.AddMethodName("vkTransitionImageLayoutEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkTransitionImageLayoutEXT(%s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            transitionCount,
            pTransitionsArray.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkTransitionImageLayoutEXT);
}



void VulkanCppConsumer::Process_vkReleaseSwapchainImagesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoEXT>* pReleaseInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pReleaseInfo */
    std::stringstream stream_pReleaseInfo;
    std::string pReleaseInfoStruct = GenerateStruct_VkReleaseSwapchainImagesInfoEXT(stream_pReleaseInfo,
                                                                    pReleaseInfo->GetPointer(),
                                                                    pReleaseInfo->GetMetaStructPointer(),
                                                                    *this);
    fprintf(file, "\n%s", stream_pReleaseInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkReleaseSwapchainImagesEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkReleaseSwapchainImagesEXT(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pReleaseInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT);
}


void VulkanCppConsumer::Process_vkCmdBindPipelineShaderGroupNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline,
    uint32_t                                    groupIndex)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pipelineBindPoint */
/* pipeline */
/* groupIndex */
    m_pfnLoader.AddMethodName("vkCmdBindPipelineShaderGroupNV");
    fprintf(file,
            "loaded_vkCmdBindPipelineShaderGroupNV(%s, %s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineBindPoint>(pipelineBindPoint).c_str(),
            this->GetHandle(pipeline).c_str(),
            groupIndex);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV);
}

void VulkanCppConsumer::Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    isPreprocessed,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* isPreprocessed */
/* pGeneratedCommandsInfo */
    std::stringstream stream_pGeneratedCommandsInfo;
    std::string pGeneratedCommandsInfoStruct = GenerateStruct_VkGeneratedCommandsInfoNV(stream_pGeneratedCommandsInfo,
                                                                              pGeneratedCommandsInfo->GetPointer(),
                                                                              pGeneratedCommandsInfo->GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "\n%s", stream_pGeneratedCommandsInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdExecuteGeneratedCommandsNV");
    fprintf(file,
            "loaded_vkCmdExecuteGeneratedCommandsNV(%s, %u, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            isPreprocessed,
            pGeneratedCommandsInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV);
}

void VulkanCppConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pGeneratedCommandsInfo */
    std::stringstream stream_pGeneratedCommandsInfo;
    std::string pGeneratedCommandsInfoStruct = GenerateStruct_VkGeneratedCommandsInfoNV(stream_pGeneratedCommandsInfo,
                                                                              pGeneratedCommandsInfo->GetPointer(),
                                                                              pGeneratedCommandsInfo->GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "\n%s", stream_pGeneratedCommandsInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdPreprocessGeneratedCommandsNV");
    fprintf(file,
            "loaded_vkCmdPreprocessGeneratedCommandsNV(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pGeneratedCommandsInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV);
}

void VulkanCppConsumer::Process_vkCreateIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkIndirectCommandsLayoutNV>* pIndirectCommandsLayout)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkIndirectCommandsLayoutCreateInfoNV(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pIndirectCommandsLayout */
    std::string pIndirectCommandsLayoutName = "pIndirectCommandsLayout_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV));
    AddKnownVariables("VkIndirectCommandsLayoutNV", pIndirectCommandsLayoutName, pIndirectCommandsLayout->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pIndirectCommandsLayoutName,
                         pIndirectCommandsLayout->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateIndirectCommandsLayoutNV");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateIndirectCommandsLayoutNV(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pIndirectCommandsLayoutName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV);
}

void VulkanCppConsumer::Process_vkDestroyIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            indirectCommandsLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* indirectCommandsLayout */
/* pAllocator */
    m_pfnLoader.AddMethodName("vkDestroyIndirectCommandsLayoutNV");
    fprintf(file,
            "loaded_vkDestroyIndirectCommandsLayoutNV(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(indirectCommandsLayout).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV);
}

void VulkanCppConsumer::Process_vkGetGeneratedCommandsMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkGeneratedCommandsMemoryRequirementsInfoNV(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
/* pMemoryRequirements */
    std::string pMemoryRequirementsName = "pMemoryRequirements_" + std::to_string(this->getNextId());
    std::stringstream stream_pMemoryRequirements;
    pMemoryRequirementsName = GenerateStruct_VkMemoryRequirements2(stream_pMemoryRequirements,
                                                             pMemoryRequirements->GetPointer(),
                                                             pMemoryRequirements->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pMemoryRequirements.str().c_str());
    m_pfnLoader.AddMethodName("vkGetGeneratedCommandsMemoryRequirementsNV");
    fprintf(file,
            "loaded_vkGetGeneratedCommandsMemoryRequirementsNV(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str(),
            pMemoryRequirementsName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV);
}




void VulkanCppConsumer::Process_vkCmdSetDepthBias2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDepthBiasInfoEXT>* pDepthBiasInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pDepthBiasInfo */
    std::stringstream stream_pDepthBiasInfo;
    std::string pDepthBiasInfoStruct = GenerateStruct_VkDepthBiasInfoEXT(stream_pDepthBiasInfo,
                                                                      pDepthBiasInfo->GetPointer(),
                                                                      pDepthBiasInfo->GetMetaStructPointer(),
                                                                      *this);
    fprintf(file, "\n%s", stream_pDepthBiasInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdSetDepthBias2EXT");
    fprintf(file,
            "loaded_vkCmdSetDepthBias2EXT(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pDepthBiasInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBias2EXT);
}


void VulkanCppConsumer::Process_vkAcquireDrmDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    int32_t                                     drmFd,
    format::HandleId                            display)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* drmFd */
/* display */
    m_pfnLoader.AddMethodName("vkAcquireDrmDisplayEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkAcquireDrmDisplayEXT(%s, %d, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            drmFd,
            this->GetHandle(display).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT);
}

void VulkanCppConsumer::Process_vkGetDrmDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    int32_t                                     drmFd,
    uint32_t                                    connectorId,
    HandlePointerDecoder<VkDisplayKHR>*         display)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* drmFd */
/* connectorId */
/* display */
    std::string displayName = "display_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_DISPLAY_KHR));
    AddKnownVariables("VkDisplayKHR", displayName, display->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(displayName,
                         display->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkGetDrmDisplayEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetDrmDisplayEXT(%s, %d, %u, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            drmFd,
            connectorId,
            displayName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDrmDisplayEXT);
}





void VulkanCppConsumer::Process_vkCreatePrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPrivateDataSlot>*    pPrivateDataSlot)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkPrivateDataSlotCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pPrivateDataSlot */
    std::string pPrivateDataSlotName = "pPrivateDataSlot_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_PRIVATE_DATA_SLOT));
    AddKnownVariables("VkPrivateDataSlot", pPrivateDataSlotName, pPrivateDataSlot->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pPrivateDataSlotName,
                         pPrivateDataSlot->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreatePrivateDataSlotEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreatePrivateDataSlotEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pPrivateDataSlotName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT);
}

void VulkanCppConsumer::Process_vkDestroyPrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* privateDataSlot */
/* pAllocator */
    m_pfnLoader.AddMethodName("vkDestroyPrivateDataSlotEXT");
    fprintf(file,
            "loaded_vkDestroyPrivateDataSlotEXT(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(privateDataSlot).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT);
}

void VulkanCppConsumer::Process_vkGetPrivateDataEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    PointerDecoder<uint64_t>*                   pData)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* objectType */
/* objectHandle */
/* privateDataSlot */
/* pData */
    std::string pDataName = "pData_" + std::to_string(this->getNextId());
    fprintf(file, "uint64_t %s;\n", pDataName.c_str());
    m_pfnLoader.AddMethodName("vkGetPrivateDataEXT");
    fprintf(file,
            "loaded_vkGetPrivateDataEXT(%s, %s, %luUL, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkObjectType>(objectType).c_str(),
            objectHandle,
            this->GetHandle(privateDataSlot).c_str(),
            pDataName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPrivateDataEXT);
}

void VulkanCppConsumer::Process_vkSetPrivateDataEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    uint64_t                                    data)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* objectType */
/* objectHandle */
/* privateDataSlot */
/* data */
    m_pfnLoader.AddMethodName("vkSetPrivateDataEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkSetPrivateDataEXT(%s, %s, %luUL, %s, %luUL), %s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkObjectType>(objectType).c_str(),
            objectHandle,
            this->GetHandle(privateDataSlot).c_str(),
            data,
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSetPrivateDataEXT);
}







void VulkanCppConsumer::Process_vkCmdSetFragmentShadingRateEnumNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* shadingRate */
/* combinerOps */
    std::string combinerOpsArray = "NULL";
    std::string combinerOpsValues = toStringJoin(combinerOps->GetPointer(),
                                                 combinerOps->GetPointer() + 2,
                                                 [&](const format::HandleId current) { return this->GetHandle(current); },
                                                 ", ");
    fprintf(file, "VkFragmentShadingRateCombinerOpKHR %s[] = { %s };\n", combinerOpsArray.c_str(), combinerOpsValues.c_str());
    m_pfnLoader.AddMethodName("vkCmdSetFragmentShadingRateEnumNV");
    fprintf(file,
            "loaded_vkCmdSetFragmentShadingRateEnumNV(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkFragmentShadingRateNV>(shadingRate).c_str(),
            combinerOpsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV);
}









void VulkanCppConsumer::Process_vkGetDeviceFaultInfoEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceFaultCountsEXT>* pFaultCounts,
    StructPointerDecoder<Decoded_VkDeviceFaultInfoEXT>* pFaultInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pFaultCounts */
    std::string pFaultCountsName = "pFaultCounts_" + std::to_string(this->getNextId());
    std::stringstream stream_pFaultCounts;
    pFaultCountsName = GenerateStruct_VkDeviceFaultCountsEXT(stream_pFaultCounts,
                                                      pFaultCounts->GetPointer(),
                                                      pFaultCounts->GetMetaStructPointer(),
                                                      *this);
    fprintf(file, "\n%s", stream_pFaultCounts.str().c_str());
/* pFaultInfo */
    std::string pFaultInfoName = "pFaultInfo_" + std::to_string(this->getNextId());
    std::stringstream stream_pFaultInfo;
    pFaultInfoName = GenerateStruct_VkDeviceFaultInfoEXT(stream_pFaultInfo,
                                                    pFaultInfo->GetPointer(),
                                                    pFaultInfo->GetMetaStructPointer(),
                                                    *this);
    fprintf(file, "\n%s", stream_pFaultInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkGetDeviceFaultInfoEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetDeviceFaultInfoEXT(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pFaultCountsName.c_str(),
            pFaultInfoName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT);
}



void VulkanCppConsumer::Process_vkAcquireWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* display */
    m_pfnLoader.AddMethodName("vkAcquireWinrtDisplayNV");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkAcquireWinrtDisplayNV(%s, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            this->GetHandle(display).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV);
}

void VulkanCppConsumer::Process_vkGetWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    deviceRelativeId,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplay)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* deviceRelativeId */
/* pDisplay */
    std::string pDisplayName = "pDisplay_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_DISPLAY_KHR));
    AddKnownVariables("VkDisplayKHR", pDisplayName, pDisplay->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pDisplayName,
                         pDisplay->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkGetWinrtDisplayNV");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetWinrtDisplayNV(%s, %u, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            deviceRelativeId,
            pDisplayName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetWinrtDisplayNV);
}

void VulkanCppConsumer::Process_vkCreateDirectFBSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* instance */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkDirectFBSurfaceCreateInfoEXT(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pSurface */
    std::string pSurfaceName = "pSurface_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", pSurfaceName, pSurface->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pSurfaceName,
                         pSurface->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateDirectFBSurfaceEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateDirectFBSurfaceEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pSurfaceName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    dfb)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* queueFamilyIndex */
/* dfb */
    std::string dfbName = "dfb_" + std::to_string(this->getNextId());
    fprintf(file, "void* %s;\n", dfbName.c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceDirectFBPresentationSupportEXT");
    fprintf(file,
            "loaded_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(%s, %u, %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            queueFamilyIndex,
            dfbName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT);
}


void VulkanCppConsumer::Process_vkCmdSetVertexInputEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    vertexBindingDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT>* pVertexBindingDescriptions,
    uint32_t                                    vertexAttributeDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT>* pVertexAttributeDescriptions)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* vertexBindingDescriptionCount */
/* pVertexBindingDescriptions */
    std::stringstream stream_pVertexBindingDescriptions;
    std::string pVertexBindingDescriptionsArray = "NULL";
    PointerPairContainer<decltype(pVertexBindingDescriptions->GetPointer()), decltype(pVertexBindingDescriptions->GetMetaStructPointer())> pVertexBindingDescriptionsPair{ pVertexBindingDescriptions->GetPointer(), pVertexBindingDescriptions->GetMetaStructPointer(), vertexBindingDescriptionCount };
    std::string pVertexBindingDescriptionsNames = toStringJoin(pVertexBindingDescriptionsPair.begin(),
                                                               pVertexBindingDescriptionsPair.end(),
                                                               [&](auto pair) { return GenerateStruct_VkVertexInputBindingDescription2EXT(stream_pVertexBindingDescriptions, pair.t1, pair.t2, *this); },
                                                               ", ");
    fprintf(file, "\n%s", stream_pVertexBindingDescriptions.str().c_str());
    if (vertexBindingDescriptionCount == 1) {
        pVertexBindingDescriptionsArray = "&" + pVertexBindingDescriptionsNames;
    } else if (vertexBindingDescriptionCount > 1) {
        pVertexBindingDescriptionsArray = "pVertexBindingDescriptions_" + std::to_string(this->getNextId());
        fprintf(file, "VkVertexInputBindingDescription2EXT %s[] = { %s };\n", pVertexBindingDescriptionsArray.c_str(), pVertexBindingDescriptionsNames.c_str());
    }
/* vertexAttributeDescriptionCount */
/* pVertexAttributeDescriptions */
    std::stringstream stream_pVertexAttributeDescriptions;
    std::string pVertexAttributeDescriptionsArray = "NULL";
    PointerPairContainer<decltype(pVertexAttributeDescriptions->GetPointer()), decltype(pVertexAttributeDescriptions->GetMetaStructPointer())> pVertexAttributeDescriptionsPair{ pVertexAttributeDescriptions->GetPointer(), pVertexAttributeDescriptions->GetMetaStructPointer(), vertexAttributeDescriptionCount };
    std::string pVertexAttributeDescriptionsNames = toStringJoin(pVertexAttributeDescriptionsPair.begin(),
                                                                 pVertexAttributeDescriptionsPair.end(),
                                                                 [&](auto pair) { return GenerateStruct_VkVertexInputAttributeDescription2EXT(stream_pVertexAttributeDescriptions, pair.t1, pair.t2, *this); },
                                                                 ", ");
    fprintf(file, "\n%s", stream_pVertexAttributeDescriptions.str().c_str());
    if (vertexAttributeDescriptionCount == 1) {
        pVertexAttributeDescriptionsArray = "&" + pVertexAttributeDescriptionsNames;
    } else if (vertexAttributeDescriptionCount > 1) {
        pVertexAttributeDescriptionsArray = "pVertexAttributeDescriptions_" + std::to_string(this->getNextId());
        fprintf(file, "VkVertexInputAttributeDescription2EXT %s[] = { %s };\n", pVertexAttributeDescriptionsArray.c_str(), pVertexAttributeDescriptionsNames.c_str());
    }
    m_pfnLoader.AddMethodName("vkCmdSetVertexInputEXT");
    fprintf(file,
            "loaded_vkCmdSetVertexInputEXT(%s, %u, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            vertexBindingDescriptionCount,
            pVertexBindingDescriptionsArray.c_str(),
            vertexAttributeDescriptionCount,
            pVertexAttributeDescriptionsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT);
}





void VulkanCppConsumer::Process_vkGetMemoryZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo,
    PointerDecoder<uint32_t>*                   pZirconHandle)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pGetZirconHandleInfo */
    std::stringstream stream_pGetZirconHandleInfo;
    std::string pGetZirconHandleInfoStruct = GenerateStruct_VkMemoryGetZirconHandleInfoFUCHSIA(stream_pGetZirconHandleInfo,
                                                                            pGetZirconHandleInfo->GetPointer(),
                                                                            pGetZirconHandleInfo->GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "\n%s", stream_pGetZirconHandleInfo.str().c_str());
/* pZirconHandle */
    std::string pZirconHandleName = "pZirconHandle_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pZirconHandleName.c_str());
    m_pfnLoader.AddMethodName("vkGetMemoryZirconHandleFUCHSIA");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetMemoryZirconHandleFUCHSIA(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pGetZirconHandleInfoStruct.c_str(),
            pZirconHandleName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA);
}

void VulkanCppConsumer::Process_vkGetMemoryZirconHandlePropertiesFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint32_t                                    zirconHandle,
    StructPointerDecoder<Decoded_VkMemoryZirconHandlePropertiesFUCHSIA>* pMemoryZirconHandleProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* handleType */
/* zirconHandle */
/* pMemoryZirconHandleProperties */
    std::string pMemoryZirconHandlePropertiesName = "pMemoryZirconHandleProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pMemoryZirconHandleProperties;
    pMemoryZirconHandlePropertiesName = GenerateStruct_VkMemoryZirconHandlePropertiesFUCHSIA(stream_pMemoryZirconHandleProperties,
                                                                       pMemoryZirconHandleProperties->GetPointer(),
                                                                       pMemoryZirconHandleProperties->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "\n%s", stream_pMemoryZirconHandleProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetMemoryZirconHandlePropertiesFUCHSIA");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetMemoryZirconHandlePropertiesFUCHSIA(%s, %s, %u, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkExternalMemoryHandleTypeFlagBits>(handleType).c_str(),
            zirconHandle,
            pMemoryZirconHandlePropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA);
}

void VulkanCppConsumer::Process_vkGetSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo,
    PointerDecoder<uint32_t>*                   pZirconHandle)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pGetZirconHandleInfo */
    std::stringstream stream_pGetZirconHandleInfo;
    std::string pGetZirconHandleInfoStruct = GenerateStruct_VkSemaphoreGetZirconHandleInfoFUCHSIA(stream_pGetZirconHandleInfo,
                                                                            pGetZirconHandleInfo->GetPointer(),
                                                                            pGetZirconHandleInfo->GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "\n%s", stream_pGetZirconHandleInfo.str().c_str());
/* pZirconHandle */
    std::string pZirconHandleName = "pZirconHandle_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pZirconHandleName.c_str());
    m_pfnLoader.AddMethodName("vkGetSemaphoreZirconHandleFUCHSIA");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetSemaphoreZirconHandleFUCHSIA(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pGetZirconHandleInfoStruct.c_str(),
            pZirconHandleName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA);
}

void VulkanCppConsumer::Process_vkImportSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA>* pImportSemaphoreZirconHandleInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pImportSemaphoreZirconHandleInfo */
    std::stringstream stream_pImportSemaphoreZirconHandleInfo;
    std::string pImportSemaphoreZirconHandleInfoStruct = GenerateStruct_VkImportSemaphoreZirconHandleInfoFUCHSIA(stream_pImportSemaphoreZirconHandleInfo,
                                                                                        pImportSemaphoreZirconHandleInfo->GetPointer(),
                                                                                        pImportSemaphoreZirconHandleInfo->GetMetaStructPointer(),
                                                                                        *this);
    fprintf(file, "\n%s", stream_pImportSemaphoreZirconHandleInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkImportSemaphoreZirconHandleFUCHSIA");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkImportSemaphoreZirconHandleFUCHSIA(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pImportSemaphoreZirconHandleInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA);
}

void VulkanCppConsumer::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* imageView */
/* imageLayout */
    m_pfnLoader.AddMethodName("vkCmdBindInvocationMaskHUAWEI");
    fprintf(file,
            "loaded_vkCmdBindInvocationMaskHUAWEI(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(imageView).c_str(),
            util::ToString<VkImageLayout>(imageLayout).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI);
}

void VulkanCppConsumer::Process_vkGetMemoryRemoteAddressNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetRemoteAddressInfoNV>* pMemoryGetRemoteAddressInfo,
    PointerDecoder<uint64_t, void*>*            pAddress)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pMemoryGetRemoteAddressInfo */
    std::stringstream stream_pMemoryGetRemoteAddressInfo;
    std::string pMemoryGetRemoteAddressInfoStruct = GenerateStruct_VkMemoryGetRemoteAddressInfoNV(stream_pMemoryGetRemoteAddressInfo,
                                                                                   pMemoryGetRemoteAddressInfo->GetPointer(),
                                                                                   pMemoryGetRemoteAddressInfo->GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "\n%s", stream_pMemoryGetRemoteAddressInfo.str().c_str());
/* pAddress */
    std::string pAddressName = "pAddress_" + std::to_string(this->getNextId());
    fprintf(file, "uint8_t* %s;\n", pAddressName.c_str());
    m_pfnLoader.AddMethodName("vkGetMemoryRemoteAddressNV");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetMemoryRemoteAddressNV(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pMemoryGetRemoteAddressInfoStruct.c_str(),
            pAddressName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV);
}



void VulkanCppConsumer::Process_vkCmdSetDepthBiasEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* depthBiasEnable */
    m_pfnLoader.AddMethodName("vkCmdSetDepthBiasEnableEXT");
    fprintf(file,
            "loaded_vkCmdSetDepthBiasEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            depthBiasEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetLogicOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLogicOp                                   logicOp)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* logicOp */
    m_pfnLoader.AddMethodName("vkCmdSetLogicOpEXT");
    fprintf(file,
            "loaded_vkCmdSetLogicOpEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkLogicOp>(logicOp).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT);
}

void VulkanCppConsumer::Process_vkCmdSetPatchControlPointsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    patchControlPoints)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* patchControlPoints */
    m_pfnLoader.AddMethodName("vkCmdSetPatchControlPointsEXT");
    fprintf(file,
            "loaded_vkCmdSetPatchControlPointsEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            patchControlPoints);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT);
}

void VulkanCppConsumer::Process_vkCmdSetPrimitiveRestartEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* primitiveRestartEnable */
    m_pfnLoader.AddMethodName("vkCmdSetPrimitiveRestartEnableEXT");
    fprintf(file,
            "loaded_vkCmdSetPrimitiveRestartEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            primitiveRestartEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetRasterizerDiscardEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* rasterizerDiscardEnable */
    m_pfnLoader.AddMethodName("vkCmdSetRasterizerDiscardEnableEXT");
    fprintf(file,
            "loaded_vkCmdSetRasterizerDiscardEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            rasterizerDiscardEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT);
}

void VulkanCppConsumer::Process_vkCreateScreenSurfaceQNX(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* instance */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkScreenSurfaceCreateInfoQNX(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pSurface */
    std::string pSurfaceName = "pSurface_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", pSurfaceName, pSurface->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pSurfaceName,
                         pSurface->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateScreenSurfaceQNX");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateScreenSurfaceQNX(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pSurfaceName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceScreenPresentationSupportQNX(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    window)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* queueFamilyIndex */
/* window */
    std::string windowName = "window_" + std::to_string(this->getNextId());
    fprintf(file, "void* %s;\n", windowName.c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceScreenPresentationSupportQNX");
    fprintf(file,
            "loaded_vkGetPhysicalDeviceScreenPresentationSupportQNX(%s, %u, %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            queueFamilyIndex,
            windowName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX);
}

void VulkanCppConsumer::Process_vkCmdSetColorWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorWriteEnables)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* attachmentCount */
/* pColorWriteEnables */
    std::string pColorWriteEnablesArray = "pColorWriteEnables_" + std::to_string(this->getNextId());
    if (attachmentCount > 0) {
        std::string pColorWriteEnablesValues = toStringJoin(pColorWriteEnables->GetPointer(),
                                                            pColorWriteEnables->GetPointer() + attachmentCount,
                                                            [&](const auto current) { return std::to_string(current) + ""; },
                                                            ", ");
        fprintf(file, "VkBool32 %s[] = { %s };\n", pColorWriteEnablesArray.c_str(), pColorWriteEnablesValues.c_str());
    } else {
        pColorWriteEnablesArray = "NULL";
    }
    m_pfnLoader.AddMethodName("vkCmdSetColorWriteEnableEXT");
    fprintf(file,
            "loaded_vkCmdSetColorWriteEnableEXT(%s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            attachmentCount,
            pColorWriteEnablesArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT);
}




void VulkanCppConsumer::Process_vkCmdDrawMultiEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    drawCount,
    StructPointerDecoder<Decoded_VkMultiDrawInfoEXT>* pVertexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* drawCount */
/* pVertexInfo */
    std::stringstream stream_pVertexInfo;
    std::string pVertexInfoArray = "NULL";
    PointerPairContainer<decltype(pVertexInfo->GetPointer()), decltype(pVertexInfo->GetMetaStructPointer())> pVertexInfoPair{ pVertexInfo->GetPointer(), pVertexInfo->GetMetaStructPointer(), drawCount };
    std::string pVertexInfoNames = toStringJoin(pVertexInfoPair.begin(),
                                                pVertexInfoPair.end(),
                                                [&](auto pair) { return GenerateStruct_VkMultiDrawInfoEXT(stream_pVertexInfo, pair.t1, pair.t2, *this); },
                                                ", ");
    fprintf(file, "\n%s", stream_pVertexInfo.str().c_str());
    if (drawCount == 1) {
        pVertexInfoArray = "&" + pVertexInfoNames;
    } else if (drawCount > 1) {
        pVertexInfoArray = "pVertexInfo_" + std::to_string(this->getNextId());
        fprintf(file, "VkMultiDrawInfoEXT %s[] = { %s };\n", pVertexInfoArray.c_str(), pVertexInfoNames.c_str());
    }
/* instanceCount */
/* firstInstance */
/* stride */
    m_pfnLoader.AddMethodName("vkCmdDrawMultiEXT");
    fprintf(file,
            "loaded_vkCmdDrawMultiEXT(%s, %u, %s, %u, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            drawCount,
            pVertexInfoArray.c_str(),
            instanceCount,
            firstInstance,
            stride);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMultiEXT);
}

void VulkanCppConsumer::Process_vkCmdDrawMultiIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    drawCount,
    StructPointerDecoder<Decoded_VkMultiDrawIndexedInfoEXT>* pIndexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride,
    PointerDecoder<int32_t>*                    pVertexOffset)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* drawCount */
/* pIndexInfo */
    std::stringstream stream_pIndexInfo;
    std::string pIndexInfoArray = "NULL";
    PointerPairContainer<decltype(pIndexInfo->GetPointer()), decltype(pIndexInfo->GetMetaStructPointer())> pIndexInfoPair{ pIndexInfo->GetPointer(), pIndexInfo->GetMetaStructPointer(), drawCount };
    std::string pIndexInfoNames = toStringJoin(pIndexInfoPair.begin(),
                                               pIndexInfoPair.end(),
                                               [&](auto pair) { return GenerateStruct_VkMultiDrawIndexedInfoEXT(stream_pIndexInfo, pair.t1, pair.t2, *this); },
                                               ", ");
    fprintf(file, "\n%s", stream_pIndexInfo.str().c_str());
    if (drawCount == 1) {
        pIndexInfoArray = "&" + pIndexInfoNames;
    } else if (drawCount > 1) {
        pIndexInfoArray = "pIndexInfo_" + std::to_string(this->getNextId());
        fprintf(file, "VkMultiDrawIndexedInfoEXT %s[] = { %s };\n", pIndexInfoArray.c_str(), pIndexInfoNames.c_str());
    }
/* instanceCount */
/* firstInstance */
/* stride */
/* pVertexOffset */
    m_pfnLoader.AddMethodName("vkCmdDrawMultiIndexedEXT");
    fprintf(file,
            "loaded_vkCmdDrawMultiIndexedEXT(%s, %u, %s, %u, %u, %u, %p);\n",
            this->GetHandle(commandBuffer).c_str(),
            drawCount,
            pIndexInfoArray.c_str(),
            instanceCount,
            firstInstance,
            stride,
            pVertexOffset->GetPointer());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT);
}



void VulkanCppConsumer::Process_vkBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* deferredOperation */
/* infoCount */
/* pInfos */
    std::stringstream stream_pInfos;
    std::string pInfosArray = "NULL";
    PointerPairContainer<decltype(pInfos->GetPointer()), decltype(pInfos->GetMetaStructPointer())> pInfosPair{ pInfos->GetPointer(), pInfos->GetMetaStructPointer(), infoCount };
    std::string pInfosNames = toStringJoin(pInfosPair.begin(),
                                           pInfosPair.end(),
                                           [&](auto pair) { return GenerateStruct_VkMicromapBuildInfoEXT(stream_pInfos, pair.t1, pair.t2, *this); },
                                           ", ");
    fprintf(file, "\n%s", stream_pInfos.str().c_str());
    if (infoCount == 1) {
        pInfosArray = "&" + pInfosNames;
    } else if (infoCount > 1) {
        pInfosArray = "pInfos_" + std::to_string(this->getNextId());
        fprintf(file, "VkMicromapBuildInfoEXT %s[] = { %s };\n", pInfosArray.c_str(), pInfosNames.c_str());
    }
    m_pfnLoader.AddMethodName("vkBuildMicromapsEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkBuildMicromapsEXT(%s, %s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(deferredOperation).c_str(),
            infoCount,
            pInfosArray.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBuildMicromapsEXT);
}

void VulkanCppConsumer::Process_vkCmdBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* infoCount */
/* pInfos */
    std::stringstream stream_pInfos;
    std::string pInfosArray = "NULL";
    PointerPairContainer<decltype(pInfos->GetPointer()), decltype(pInfos->GetMetaStructPointer())> pInfosPair{ pInfos->GetPointer(), pInfos->GetMetaStructPointer(), infoCount };
    std::string pInfosNames = toStringJoin(pInfosPair.begin(),
                                           pInfosPair.end(),
                                           [&](auto pair) { return GenerateStruct_VkMicromapBuildInfoEXT(stream_pInfos, pair.t1, pair.t2, *this); },
                                           ", ");
    fprintf(file, "\n%s", stream_pInfos.str().c_str());
    if (infoCount == 1) {
        pInfosArray = "&" + pInfosNames;
    } else if (infoCount > 1) {
        pInfosArray = "pInfos_" + std::to_string(this->getNextId());
        fprintf(file, "VkMicromapBuildInfoEXT %s[] = { %s };\n", pInfosArray.c_str(), pInfosNames.c_str());
    }
    m_pfnLoader.AddMethodName("vkCmdBuildMicromapsEXT");
    fprintf(file,
            "loaded_vkCmdBuildMicromapsEXT(%s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            infoCount,
            pInfosArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT);
}

void VulkanCppConsumer::Process_vkCmdCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkCopyMemoryToMicromapInfoEXT(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdCopyMemoryToMicromapEXT");
    fprintf(file,
            "loaded_vkCmdCopyMemoryToMicromapEXT(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT);
}

void VulkanCppConsumer::Process_vkCmdCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkCopyMicromapInfoEXT(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdCopyMicromapEXT");
    fprintf(file,
            "loaded_vkCmdCopyMicromapEXT(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT);
}

void VulkanCppConsumer::Process_vkCmdCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkCopyMicromapToMemoryInfoEXT(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdCopyMicromapToMemoryEXT");
    fprintf(file,
            "loaded_vkCmdCopyMicromapToMemoryEXT(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT);
}

void VulkanCppConsumer::Process_vkCmdWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    micromapCount,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromaps,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* micromapCount */
/* pMicromaps */
    std::string pMicromapsArray = "NULL";
    std::string pMicromapsValues = toStringJoin(pMicromaps->GetPointer(),
                                                pMicromaps->GetPointer() + micromapCount,
                                                [&](const format::HandleId current) { return this->GetHandle(current); },
                                                ", ");
    if (micromapCount == 1) {
        pMicromapsArray = "&" + pMicromapsValues;
    } else if (micromapCount > 1) {
        pMicromapsArray = "pMicromapsArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkMicromapEXT %s[] = { %s };\n", pMicromapsArray.c_str(), pMicromapsValues.c_str());
    }
/* queryType */
/* queryPool */
/* firstQuery */
    m_pfnLoader.AddMethodName("vkCmdWriteMicromapsPropertiesEXT");
    fprintf(file,
            "loaded_vkCmdWriteMicromapsPropertiesEXT(%s, %u, %s, %s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            micromapCount,
            pMicromapsArray.c_str(),
            util::ToString<VkQueryType>(queryType).c_str(),
            this->GetHandle(queryPool).c_str(),
            firstQuery);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT);
}

void VulkanCppConsumer::Process_vkCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* deferredOperation */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkCopyMemoryToMicromapInfoEXT(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCopyMemoryToMicromapEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCopyMemoryToMicromapEXT(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(deferredOperation).c_str(),
            pInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT);
}

void VulkanCppConsumer::Process_vkCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* deferredOperation */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkCopyMicromapInfoEXT(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCopyMicromapEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCopyMicromapEXT(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(deferredOperation).c_str(),
            pInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCopyMicromapEXT);
}

void VulkanCppConsumer::Process_vkCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* deferredOperation */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkCopyMicromapToMemoryInfoEXT(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCopyMicromapToMemoryEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCopyMicromapToMemoryEXT(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(deferredOperation).c_str(),
            pInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT);
}

void VulkanCppConsumer::Process_vkCreateMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMicromapCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromap)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkMicromapCreateInfoEXT(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pMicromap */
    std::string pMicromapName = "pMicromap_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_MICROMAP_EXT));
    AddKnownVariables("VkMicromapEXT", pMicromapName, pMicromap->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pMicromapName,
                         pMicromap->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateMicromapEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateMicromapEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pMicromapName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateMicromapEXT);
}

void VulkanCppConsumer::Process_vkDestroyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            micromap,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* micromap */
/* pAllocator */
    m_pfnLoader.AddMethodName("vkDestroyMicromapEXT");
    fprintf(file,
            "loaded_vkDestroyMicromapEXT(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(micromap).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyMicromapEXT);
}

void VulkanCppConsumer::Process_vkGetDeviceMicromapCompatibilityEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMicromapVersionInfoEXT>* pVersionInfo,
    PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pVersionInfo */
    std::stringstream stream_pVersionInfo;
    std::string pVersionInfoStruct = GenerateStruct_VkMicromapVersionInfoEXT(stream_pVersionInfo,
                                                                    pVersionInfo->GetPointer(),
                                                                    pVersionInfo->GetMetaStructPointer(),
                                                                    *this);
    fprintf(file, "\n%s", stream_pVersionInfo.str().c_str());
/* pCompatibility */
    std::string pCompatibilityName = "pCompatibility_" + std::to_string(this->getNextId());
    fprintf(file, "VkAccelerationStructureCompatibilityKHR %s;\n", pCompatibilityName.c_str());
    m_pfnLoader.AddMethodName("vkGetDeviceMicromapCompatibilityEXT");
    fprintf(file,
            "loaded_vkGetDeviceMicromapCompatibilityEXT(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pVersionInfoStruct.c_str(),
            pCompatibilityName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT);
}

void VulkanCppConsumer::Process_vkGetMicromapBuildSizesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkAccelerationStructureBuildTypeKHR         buildType,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pBuildInfo,
    StructPointerDecoder<Decoded_VkMicromapBuildSizesInfoEXT>* pSizeInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* buildType */
/* pBuildInfo */
    std::stringstream stream_pBuildInfo;
    std::string pBuildInfoStruct = GenerateStruct_VkMicromapBuildInfoEXT(stream_pBuildInfo,
                                                                  pBuildInfo->GetPointer(),
                                                                  pBuildInfo->GetMetaStructPointer(),
                                                                  *this);
    fprintf(file, "\n%s", stream_pBuildInfo.str().c_str());
/* pSizeInfo */
    std::string pSizeInfoName = "pSizeInfo_" + std::to_string(this->getNextId());
    std::stringstream stream_pSizeInfo;
    pSizeInfoName = GenerateStruct_VkMicromapBuildSizesInfoEXT(stream_pSizeInfo,
                                                   pSizeInfo->GetPointer(),
                                                   pSizeInfo->GetMetaStructPointer(),
                                                   *this);
    fprintf(file, "\n%s", stream_pSizeInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkGetMicromapBuildSizesEXT");
    fprintf(file,
            "loaded_vkGetMicromapBuildSizesEXT(%s, %s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkAccelerationStructureBuildTypeKHR>(buildType).c_str(),
            pBuildInfoStruct.c_str(),
            pSizeInfoName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT);
}

void VulkanCppConsumer::Process_vkWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    micromapCount,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromaps,
    VkQueryType                                 queryType,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData,
    size_t                                      stride)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* micromapCount */
/* pMicromaps */
    std::string pMicromapsArray = "NULL";
    std::string pMicromapsValues = toStringJoin(pMicromaps->GetPointer(),
                                                pMicromaps->GetPointer() + micromapCount,
                                                [&](const format::HandleId current) { return this->GetHandle(current); },
                                                ", ");
    if (micromapCount == 1) {
        pMicromapsArray = "&" + pMicromapsValues;
    } else if (micromapCount > 1) {
        pMicromapsArray = "pMicromapsArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkMicromapEXT %s[] = { %s };\n", pMicromapsArray.c_str(), pMicromapsValues.c_str());
    }
/* queryType */
/* dataSize */
/* pData */
    std::string pDataName = "pData_" + std::to_string(this->getNextId());
    fprintf(file, "uint8_t %s[%ld];\n", pDataName.c_str(), dataSize);
/* stride */
    m_pfnLoader.AddMethodName("vkWriteMicromapsPropertiesEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkWriteMicromapsPropertiesEXT(%s, %u, %s, %s, %lu, %s, %lu), %s);\n",
            this->GetHandle(device).c_str(),
            micromapCount,
            pMicromapsArray.c_str(),
            util::ToString<VkQueryType>(queryType).c_str(),
            dataSize,
            pDataName.c_str(),
            stride,
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT);
}



void VulkanCppConsumer::Process_vkCmdDrawClusterHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* groupCountX */
/* groupCountY */
/* groupCountZ */
    m_pfnLoader.AddMethodName("vkCmdDrawClusterHUAWEI");
    fprintf(file,
            "loaded_vkCmdDrawClusterHUAWEI(%s, %u, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            groupCountX,
            groupCountY,
            groupCountZ);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI);
}

void VulkanCppConsumer::Process_vkCmdDrawClusterIndirectHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* buffer */
/* offset */
    m_pfnLoader.AddMethodName("vkCmdDrawClusterIndirectHUAWEI");
    fprintf(file,
            "loaded_vkCmdDrawClusterIndirectHUAWEI(%s, %s, %luUL);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI);
}


void VulkanCppConsumer::Process_vkSetDeviceMemoryPriorityEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    float                                       priority)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* memory */
/* priority */
    m_pfnLoader.AddMethodName("vkSetDeviceMemoryPriorityEXT");
    fprintf(file,
            "loaded_vkSetDeviceMemoryPriorityEXT(%s, %s, %f);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(memory).c_str(),
            priority);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT);
}



void VulkanCppConsumer::Process_vkGetDescriptorSetHostMappingVALVE(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSet,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* descriptorSet */
/* ppData */
    std::string ppDataName = "ppData_" + std::to_string(this->getNextId());
    fprintf(file, "uint8_t* %s;\n", ppDataName.c_str());
    m_pfnLoader.AddMethodName("vkGetDescriptorSetHostMappingVALVE");
    fprintf(file,
            "loaded_vkGetDescriptorSetHostMappingVALVE(%s, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(descriptorSet).c_str(),
            ppDataName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE);
}

void VulkanCppConsumer::Process_vkGetDescriptorSetLayoutHostMappingInfoVALVE(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetBindingReferenceVALVE>* pBindingReference,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE>* pHostMapping)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pBindingReference */
    std::stringstream stream_pBindingReference;
    std::string pBindingReferenceStruct = GenerateStruct_VkDescriptorSetBindingReferenceVALVE(stream_pBindingReference,
                                                                         pBindingReference->GetPointer(),
                                                                         pBindingReference->GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "\n%s", stream_pBindingReference.str().c_str());
/* pHostMapping */
    std::string pHostMappingName = "pHostMapping_" + std::to_string(this->getNextId());
    std::stringstream stream_pHostMapping;
    pHostMappingName = GenerateStruct_VkDescriptorSetLayoutHostMappingInfoVALVE(stream_pHostMapping,
                                                      pHostMapping->GetPointer(),
                                                      pHostMapping->GetMetaStructPointer(),
                                                      *this);
    fprintf(file, "\n%s", stream_pHostMapping.str().c_str());
    m_pfnLoader.AddMethodName("vkGetDescriptorSetLayoutHostMappingInfoVALVE");
    fprintf(file,
            "loaded_vkGetDescriptorSetLayoutHostMappingInfoVALVE(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pBindingReferenceStruct.c_str(),
            pHostMappingName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE);
}




void VulkanCppConsumer::Process_vkCmdUpdatePipelineIndirectBufferNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pipelineBindPoint */
/* pipeline */
    m_pfnLoader.AddMethodName("vkCmdUpdatePipelineIndirectBufferNV");
    fprintf(file,
            "loaded_vkCmdUpdatePipelineIndirectBufferNV(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineBindPoint>(pipelineBindPoint).c_str(),
            this->GetHandle(pipeline).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdUpdatePipelineIndirectBufferNV);
}

void VulkanCppConsumer::Process_vkGetPipelineIndirectDeviceAddressNV(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineIndirectDeviceAddressInfoNV>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkPipelineIndirectDeviceAddressInfoNV(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPipelineIndirectDeviceAddressNV");
    fprintf(file,
            "loaded_vkGetPipelineIndirectDeviceAddressNV(%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPipelineIndirectDeviceAddressNV);
}

void VulkanCppConsumer::Process_vkGetPipelineIndirectMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkComputePipelineCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pMemoryRequirements */
    std::string pMemoryRequirementsName = "pMemoryRequirements_" + std::to_string(this->getNextId());
    std::stringstream stream_pMemoryRequirements;
    pMemoryRequirementsName = GenerateStruct_VkMemoryRequirements2(stream_pMemoryRequirements,
                                                             pMemoryRequirements->GetPointer(),
                                                             pMemoryRequirements->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pMemoryRequirements.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPipelineIndirectMemoryRequirementsNV");
    fprintf(file,
            "loaded_vkGetPipelineIndirectMemoryRequirementsNV(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            pMemoryRequirementsName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPipelineIndirectMemoryRequirementsNV);
}






void VulkanCppConsumer::Process_vkCmdSetAlphaToCoverageEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToCoverageEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* alphaToCoverageEnable */
    m_pfnLoader.AddMethodName("vkCmdSetAlphaToCoverageEnableEXT");
    fprintf(file,
            "loaded_vkCmdSetAlphaToCoverageEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            alphaToCoverageEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetAlphaToOneEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToOneEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* alphaToOneEnable */
    m_pfnLoader.AddMethodName("vkCmdSetAlphaToOneEnableEXT");
    fprintf(file,
            "loaded_vkCmdSetAlphaToOneEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            alphaToOneEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetColorBlendAdvancedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkColorBlendAdvancedEXT>* pColorBlendAdvanced)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* firstAttachment */
/* attachmentCount */
/* pColorBlendAdvanced */
    std::stringstream stream_pColorBlendAdvanced;
    std::string pColorBlendAdvancedArray = "NULL";
    PointerPairContainer<decltype(pColorBlendAdvanced->GetPointer()), decltype(pColorBlendAdvanced->GetMetaStructPointer())> pColorBlendAdvancedPair{ pColorBlendAdvanced->GetPointer(), pColorBlendAdvanced->GetMetaStructPointer(), attachmentCount };
    std::string pColorBlendAdvancedNames = toStringJoin(pColorBlendAdvancedPair.begin(),
                                                        pColorBlendAdvancedPair.end(),
                                                        [&](auto pair) { return GenerateStruct_VkColorBlendAdvancedEXT(stream_pColorBlendAdvanced, pair.t1, pair.t2, *this); },
                                                        ", ");
    fprintf(file, "\n%s", stream_pColorBlendAdvanced.str().c_str());
    if (attachmentCount == 1) {
        pColorBlendAdvancedArray = "&" + pColorBlendAdvancedNames;
    } else if (attachmentCount > 1) {
        pColorBlendAdvancedArray = "pColorBlendAdvanced_" + std::to_string(this->getNextId());
        fprintf(file, "VkColorBlendAdvancedEXT %s[] = { %s };\n", pColorBlendAdvancedArray.c_str(), pColorBlendAdvancedNames.c_str());
    }
    m_pfnLoader.AddMethodName("vkCmdSetColorBlendAdvancedEXT");
    fprintf(file,
            "loaded_vkCmdSetColorBlendAdvancedEXT(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstAttachment,
            attachmentCount,
            pColorBlendAdvancedArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT);
}

void VulkanCppConsumer::Process_vkCmdSetColorBlendEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorBlendEnables)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* firstAttachment */
/* attachmentCount */
/* pColorBlendEnables */
    std::string pColorBlendEnablesArray = "pColorBlendEnables_" + std::to_string(this->getNextId());
    if (attachmentCount > 0) {
        std::string pColorBlendEnablesValues = toStringJoin(pColorBlendEnables->GetPointer(),
                                                            pColorBlendEnables->GetPointer() + attachmentCount,
                                                            [&](const auto current) { return std::to_string(current) + ""; },
                                                            ", ");
        fprintf(file, "VkBool32 %s[] = { %s };\n", pColorBlendEnablesArray.c_str(), pColorBlendEnablesValues.c_str());
    } else {
        pColorBlendEnablesArray = "NULL";
    }
    m_pfnLoader.AddMethodName("vkCmdSetColorBlendEnableEXT");
    fprintf(file,
            "loaded_vkCmdSetColorBlendEnableEXT(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstAttachment,
            attachmentCount,
            pColorBlendEnablesArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetColorBlendEquationEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkColorBlendEquationEXT>* pColorBlendEquations)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* firstAttachment */
/* attachmentCount */
/* pColorBlendEquations */
    std::stringstream stream_pColorBlendEquations;
    std::string pColorBlendEquationsArray = "NULL";
    PointerPairContainer<decltype(pColorBlendEquations->GetPointer()), decltype(pColorBlendEquations->GetMetaStructPointer())> pColorBlendEquationsPair{ pColorBlendEquations->GetPointer(), pColorBlendEquations->GetMetaStructPointer(), attachmentCount };
    std::string pColorBlendEquationsNames = toStringJoin(pColorBlendEquationsPair.begin(),
                                                         pColorBlendEquationsPair.end(),
                                                         [&](auto pair) { return GenerateStruct_VkColorBlendEquationEXT(stream_pColorBlendEquations, pair.t1, pair.t2, *this); },
                                                         ", ");
    fprintf(file, "\n%s", stream_pColorBlendEquations.str().c_str());
    if (attachmentCount == 1) {
        pColorBlendEquationsArray = "&" + pColorBlendEquationsNames;
    } else if (attachmentCount > 1) {
        pColorBlendEquationsArray = "pColorBlendEquations_" + std::to_string(this->getNextId());
        fprintf(file, "VkColorBlendEquationEXT %s[] = { %s };\n", pColorBlendEquationsArray.c_str(), pColorBlendEquationsNames.c_str());
    }
    m_pfnLoader.AddMethodName("vkCmdSetColorBlendEquationEXT");
    fprintf(file,
            "loaded_vkCmdSetColorBlendEquationEXT(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstAttachment,
            attachmentCount,
            pColorBlendEquationsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT);
}

void VulkanCppConsumer::Process_vkCmdSetColorWriteMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkColorComponentFlags>*      pColorWriteMasks)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* firstAttachment */
/* attachmentCount */
/* pColorWriteMasks */
    std::string pColorWriteMasksArray = "NULL";
    std::string pColorWriteMasksValues = toStringJoin(pColorWriteMasks->GetPointer(),
                                                      pColorWriteMasks->GetPointer() + attachmentCount,
                                                      [&](const format::HandleId current) { return this->GetHandle(current); },
                                                      ", ");
    if (attachmentCount == 1) {
        pColorWriteMasksArray = "&" + pColorWriteMasksValues;
    } else if (attachmentCount > 1) {
        pColorWriteMasksArray = "pColorWriteMasksArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkColorComponentFlags %s[] = { %s };\n", pColorWriteMasksArray.c_str(), pColorWriteMasksValues.c_str());
    }
    m_pfnLoader.AddMethodName("vkCmdSetColorWriteMaskEXT");
    fprintf(file,
            "loaded_vkCmdSetColorWriteMaskEXT(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstAttachment,
            attachmentCount,
            pColorWriteMasksArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT);
}

void VulkanCppConsumer::Process_vkCmdSetConservativeRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* conservativeRasterizationMode */
    m_pfnLoader.AddMethodName("vkCmdSetConservativeRasterizationModeEXT");
    fprintf(file,
            "loaded_vkCmdSetConservativeRasterizationModeEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkConservativeRasterizationModeEXT>(conservativeRasterizationMode).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT);
}

void VulkanCppConsumer::Process_vkCmdSetCoverageModulationModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* coverageModulationMode */
    m_pfnLoader.AddMethodName("vkCmdSetCoverageModulationModeNV");
    fprintf(file,
            "loaded_vkCmdSetCoverageModulationModeNV(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkCoverageModulationModeNV>(coverageModulationMode).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV);
}

void VulkanCppConsumer::Process_vkCmdSetCoverageModulationTableEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageModulationTableEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* coverageModulationTableEnable */
    m_pfnLoader.AddMethodName("vkCmdSetCoverageModulationTableEnableNV");
    fprintf(file,
            "loaded_vkCmdSetCoverageModulationTableEnableNV(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            coverageModulationTableEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV);
}

void VulkanCppConsumer::Process_vkCmdSetCoverageModulationTableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    PointerDecoder<float>*                      pCoverageModulationTable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* coverageModulationTableCount */
/* pCoverageModulationTable */
    std::string pCoverageModulationTableArray = "pCoverageModulationTable_" + std::to_string(this->getNextId());
    if (coverageModulationTableCount > 0) {
        std::string pCoverageModulationTableValues = toStringJoin(pCoverageModulationTable->GetPointer(),
                                                                  pCoverageModulationTable->GetPointer() + coverageModulationTableCount,
                                                                  [&](const auto current) { return std::to_string(current) + ""; },
                                                                  ", ");
        fprintf(file, "float %s[] = { %s };\n", pCoverageModulationTableArray.c_str(), pCoverageModulationTableValues.c_str());
    } else {
        pCoverageModulationTableArray = "NULL";
    }
    m_pfnLoader.AddMethodName("vkCmdSetCoverageModulationTableNV");
    fprintf(file,
            "loaded_vkCmdSetCoverageModulationTableNV(%s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            coverageModulationTableCount,
            pCoverageModulationTableArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV);
}

void VulkanCppConsumer::Process_vkCmdSetCoverageReductionModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* coverageReductionMode */
    m_pfnLoader.AddMethodName("vkCmdSetCoverageReductionModeNV");
    fprintf(file,
            "loaded_vkCmdSetCoverageReductionModeNV(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkCoverageReductionModeNV>(coverageReductionMode).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV);
}

void VulkanCppConsumer::Process_vkCmdSetCoverageToColorEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageToColorEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* coverageToColorEnable */
    m_pfnLoader.AddMethodName("vkCmdSetCoverageToColorEnableNV");
    fprintf(file,
            "loaded_vkCmdSetCoverageToColorEnableNV(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            coverageToColorEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV);
}

void VulkanCppConsumer::Process_vkCmdSetCoverageToColorLocationNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageToColorLocation)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* coverageToColorLocation */
    m_pfnLoader.AddMethodName("vkCmdSetCoverageToColorLocationNV");
    fprintf(file,
            "loaded_vkCmdSetCoverageToColorLocationNV(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            coverageToColorLocation);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV);
}

void VulkanCppConsumer::Process_vkCmdSetDepthClampEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClampEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* depthClampEnable */
    m_pfnLoader.AddMethodName("vkCmdSetDepthClampEnableEXT");
    fprintf(file,
            "loaded_vkCmdSetDepthClampEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            depthClampEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDepthClipEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClipEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* depthClipEnable */
    m_pfnLoader.AddMethodName("vkCmdSetDepthClipEnableEXT");
    fprintf(file,
            "loaded_vkCmdSetDepthClipEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            depthClipEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDepthClipNegativeOneToOneEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    negativeOneToOne)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* negativeOneToOne */
    m_pfnLoader.AddMethodName("vkCmdSetDepthClipNegativeOneToOneEXT");
    fprintf(file,
            "loaded_vkCmdSetDepthClipNegativeOneToOneEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            negativeOneToOne);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT);
}

void VulkanCppConsumer::Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       extraPrimitiveOverestimationSize)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* extraPrimitiveOverestimationSize */
    m_pfnLoader.AddMethodName("vkCmdSetExtraPrimitiveOverestimationSizeEXT");
    fprintf(file,
            "loaded_vkCmdSetExtraPrimitiveOverestimationSizeEXT(%s, %f);\n",
            this->GetHandle(commandBuffer).c_str(),
            extraPrimitiveOverestimationSize);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT);
}

void VulkanCppConsumer::Process_vkCmdSetLineRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* lineRasterizationMode */
    m_pfnLoader.AddMethodName("vkCmdSetLineRasterizationModeEXT");
    fprintf(file,
            "loaded_vkCmdSetLineRasterizationModeEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkLineRasterizationModeEXT>(lineRasterizationMode).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT);
}

void VulkanCppConsumer::Process_vkCmdSetLineStippleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stippledLineEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* stippledLineEnable */
    m_pfnLoader.AddMethodName("vkCmdSetLineStippleEnableEXT");
    fprintf(file,
            "loaded_vkCmdSetLineStippleEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            stippledLineEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetLogicOpEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    logicOpEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* logicOpEnable */
    m_pfnLoader.AddMethodName("vkCmdSetLogicOpEnableEXT");
    fprintf(file,
            "loaded_vkCmdSetLogicOpEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            logicOpEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetPolygonModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPolygonMode                               polygonMode)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* polygonMode */
    m_pfnLoader.AddMethodName("vkCmdSetPolygonModeEXT");
    fprintf(file,
            "loaded_vkCmdSetPolygonModeEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPolygonMode>(polygonMode).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT);
}

void VulkanCppConsumer::Process_vkCmdSetProvokingVertexModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* provokingVertexMode */
    m_pfnLoader.AddMethodName("vkCmdSetProvokingVertexModeEXT");
    fprintf(file,
            "loaded_vkCmdSetProvokingVertexModeEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkProvokingVertexModeEXT>(provokingVertexMode).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT);
}

void VulkanCppConsumer::Process_vkCmdSetRasterizationSamplesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* rasterizationSamples */
    m_pfnLoader.AddMethodName("vkCmdSetRasterizationSamplesEXT");
    fprintf(file,
            "loaded_vkCmdSetRasterizationSamplesEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkSampleCountFlagBits>(rasterizationSamples).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT);
}

void VulkanCppConsumer::Process_vkCmdSetRasterizationStreamEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    rasterizationStream)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* rasterizationStream */
    m_pfnLoader.AddMethodName("vkCmdSetRasterizationStreamEXT");
    fprintf(file,
            "loaded_vkCmdSetRasterizationStreamEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            rasterizationStream);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT);
}

void VulkanCppConsumer::Process_vkCmdSetRepresentativeFragmentTestEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    representativeFragmentTestEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* representativeFragmentTestEnable */
    m_pfnLoader.AddMethodName("vkCmdSetRepresentativeFragmentTestEnableNV");
    fprintf(file,
            "loaded_vkCmdSetRepresentativeFragmentTestEnableNV(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            representativeFragmentTestEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV);
}

void VulkanCppConsumer::Process_vkCmdSetSampleLocationsEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    sampleLocationsEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* sampleLocationsEnable */
    m_pfnLoader.AddMethodName("vkCmdSetSampleLocationsEnableEXT");
    fprintf(file,
            "loaded_vkCmdSetSampleLocationsEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            sampleLocationsEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetSampleMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       samples,
    PointerDecoder<VkSampleMask>*               pSampleMask)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* samples */
/* pSampleMask */
    std::string pSampleMaskArray = "pSampleMask_" + std::to_string(this->getNextId());
    if ((samples + 31) / 32 > 0) {
        std::string pSampleMaskValues = toStringJoin(pSampleMask->GetPointer(),
                                                     pSampleMask->GetPointer() + (samples + 31) / 32,
                                                     [&](const auto current) { return std::to_string(current) + ""; },
                                                     ", ");
        fprintf(file, "VkSampleMask %s[] = { %s };\n", pSampleMaskArray.c_str(), pSampleMaskValues.c_str());
    } else {
        pSampleMaskArray = "NULL";
    }
    m_pfnLoader.AddMethodName("vkCmdSetSampleMaskEXT");
    fprintf(file,
            "loaded_vkCmdSetSampleMaskEXT(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkSampleCountFlagBits>(samples).c_str(),
            pSampleMaskArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT);
}

void VulkanCppConsumer::Process_vkCmdSetShadingRateImageEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    shadingRateImageEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* shadingRateImageEnable */
    m_pfnLoader.AddMethodName("vkCmdSetShadingRateImageEnableNV");
    fprintf(file,
            "loaded_vkCmdSetShadingRateImageEnableNV(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            shadingRateImageEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV);
}

void VulkanCppConsumer::Process_vkCmdSetTessellationDomainOriginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* domainOrigin */
    m_pfnLoader.AddMethodName("vkCmdSetTessellationDomainOriginEXT");
    fprintf(file,
            "loaded_vkCmdSetTessellationDomainOriginEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkTessellationDomainOrigin>(domainOrigin).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT);
}

void VulkanCppConsumer::Process_vkCmdSetViewportSwizzleNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportSwizzleNV>* pViewportSwizzles)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* firstViewport */
/* viewportCount */
/* pViewportSwizzles */
    std::stringstream stream_pViewportSwizzles;
    std::string pViewportSwizzlesArray = "NULL";
    PointerPairContainer<decltype(pViewportSwizzles->GetPointer()), decltype(pViewportSwizzles->GetMetaStructPointer())> pViewportSwizzlesPair{ pViewportSwizzles->GetPointer(), pViewportSwizzles->GetMetaStructPointer(), viewportCount };
    std::string pViewportSwizzlesNames = toStringJoin(pViewportSwizzlesPair.begin(),
                                                      pViewportSwizzlesPair.end(),
                                                      [&](auto pair) { return GenerateStruct_VkViewportSwizzleNV(stream_pViewportSwizzles, pair.t1, pair.t2, *this); },
                                                      ", ");
    fprintf(file, "\n%s", stream_pViewportSwizzles.str().c_str());
    if (viewportCount == 1) {
        pViewportSwizzlesArray = "&" + pViewportSwizzlesNames;
    } else if (viewportCount > 1) {
        pViewportSwizzlesArray = "pViewportSwizzles_" + std::to_string(this->getNextId());
        fprintf(file, "VkViewportSwizzleNV %s[] = { %s };\n", pViewportSwizzlesArray.c_str(), pViewportSwizzlesNames.c_str());
    }
    m_pfnLoader.AddMethodName("vkCmdSetViewportSwizzleNV");
    fprintf(file,
            "loaded_vkCmdSetViewportSwizzleNV(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstViewport,
            viewportCount,
            pViewportSwizzlesArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV);
}

void VulkanCppConsumer::Process_vkCmdSetViewportWScalingEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    viewportWScalingEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* viewportWScalingEnable */
    m_pfnLoader.AddMethodName("vkCmdSetViewportWScalingEnableNV");
    fprintf(file,
            "loaded_vkCmdSetViewportWScalingEnableNV(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            viewportWScalingEnable);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV);
}



void VulkanCppConsumer::Process_vkGetShaderModuleCreateInfoIdentifierEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkShaderModuleCreateInfo(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pIdentifier */
    std::string pIdentifierName = "pIdentifier_" + std::to_string(this->getNextId());
    std::stringstream stream_pIdentifier;
    pIdentifierName = GenerateStruct_VkShaderModuleIdentifierEXT(stream_pIdentifier,
                                                     pIdentifier->GetPointer(),
                                                     pIdentifier->GetMetaStructPointer(),
                                                     *this);
    fprintf(file, "\n%s", stream_pIdentifier.str().c_str());
    m_pfnLoader.AddMethodName("vkGetShaderModuleCreateInfoIdentifierEXT");
    fprintf(file,
            "loaded_vkGetShaderModuleCreateInfoIdentifierEXT(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            pIdentifierName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT);
}

void VulkanCppConsumer::Process_vkGetShaderModuleIdentifierEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* shaderModule */
/* pIdentifier */
    std::string pIdentifierName = "pIdentifier_" + std::to_string(this->getNextId());
    std::stringstream stream_pIdentifier;
    pIdentifierName = GenerateStruct_VkShaderModuleIdentifierEXT(stream_pIdentifier,
                                                     pIdentifier->GetPointer(),
                                                     pIdentifier->GetMetaStructPointer(),
                                                     *this);
    fprintf(file, "\n%s", stream_pIdentifier.str().c_str());
    m_pfnLoader.AddMethodName("vkGetShaderModuleIdentifierEXT");
    fprintf(file,
            "loaded_vkGetShaderModuleIdentifierEXT(%s, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(shaderModule).c_str(),
            pIdentifierName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT);
}


void VulkanCppConsumer::Process_vkBindOpticalFlowSessionImageNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            session,
    VkOpticalFlowSessionBindingPointNV          bindingPoint,
    format::HandleId                            view,
    VkImageLayout                               layout)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* session */
/* bindingPoint */
/* view */
/* layout */
    m_pfnLoader.AddMethodName("vkBindOpticalFlowSessionImageNV");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkBindOpticalFlowSessionImageNV(%s, %s, %s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(session).c_str(),
            util::ToString<VkOpticalFlowSessionBindingPointNV>(bindingPoint).c_str(),
            this->GetHandle(view).c_str(),
            util::ToString<VkImageLayout>(layout).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV);
}

void VulkanCppConsumer::Process_vkCmdOpticalFlowExecuteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV>* pExecuteInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* session */
/* pExecuteInfo */
    std::stringstream stream_pExecuteInfo;
    std::string pExecuteInfoStruct = GenerateStruct_VkOpticalFlowExecuteInfoNV(stream_pExecuteInfo,
                                                                    pExecuteInfo->GetPointer(),
                                                                    pExecuteInfo->GetMetaStructPointer(),
                                                                    *this);
    fprintf(file, "\n%s", stream_pExecuteInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdOpticalFlowExecuteNV");
    fprintf(file,
            "loaded_vkCmdOpticalFlowExecuteNV(%s, %s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(session).c_str(),
            pExecuteInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV);
}

void VulkanCppConsumer::Process_vkCreateOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkOpticalFlowSessionCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkOpticalFlowSessionNV>* pSession)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkOpticalFlowSessionCreateInfoNV(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pSession */
    std::string pSessionName = "pSession_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_OPTICAL_FLOW_SESSION_NV));
    AddKnownVariables("VkOpticalFlowSessionNV", pSessionName, pSession->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pSessionName,
                         pSession->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateOpticalFlowSessionNV");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateOpticalFlowSessionNV(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pSessionName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV);
}

void VulkanCppConsumer::Process_vkDestroyOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* session */
/* pAllocator */
    m_pfnLoader.AddMethodName("vkDestroyOpticalFlowSessionNV");
    fprintf(file,
            "loaded_vkDestroyOpticalFlowSessionNV(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(session).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatInfoNV>* pOpticalFlowImageFormatInfo,
    PointerDecoder<uint32_t>*                   pFormatCount,
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatPropertiesNV>* pImageFormatProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* physicalDevice */
/* pOpticalFlowImageFormatInfo */
    std::stringstream stream_pOpticalFlowImageFormatInfo;
    std::string pOpticalFlowImageFormatInfoStruct = GenerateStruct_VkOpticalFlowImageFormatInfoNV(stream_pOpticalFlowImageFormatInfo,
                                                                                   pOpticalFlowImageFormatInfo->GetPointer(),
                                                                                   pOpticalFlowImageFormatInfo->GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "\n%s", stream_pOpticalFlowImageFormatInfo.str().c_str());
/* pFormatCount */
    std::string pFormatCountName = "pFormatCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pFormatCountName.c_str());
/* pImageFormatProperties */
    std::string pImageFormatPropertiesName = "pImageFormatProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pImageFormatProperties;
    pImageFormatPropertiesName = GenerateStruct_VkOpticalFlowImageFormatPropertiesNV(stream_pImageFormatProperties,
                                                                pImageFormatProperties->GetPointer(),
                                                                pImageFormatProperties->GetMetaStructPointer(),
                                                                *this);
    fprintf(file, "\n%s", stream_pImageFormatProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceOpticalFlowImageFormatsNV");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(%s, &%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pOpticalFlowImageFormatInfoStruct.c_str(),
            pFormatCountName.c_str(),
            pImageFormatPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV);
}




void VulkanCppConsumer::Process_vkCmdBindShadersEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    stageCount,
    PointerDecoder<VkShaderStageFlagBits>*      pStages,
    HandlePointerDecoder<VkShaderEXT>*          pShaders)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* stageCount */
/* pStages */
    std::string pStagesArray = "NULL";
    std::string pStagesValues = toStringJoin(pStages->GetPointer(),
                                             pStages->GetPointer() + stageCount,
                                             [&](const format::HandleId current) { return this->GetHandle(current); },
                                             ", ");
    if (stageCount == 1) {
        pStagesArray = "&" + pStagesValues;
    } else if (stageCount > 1) {
        pStagesArray = "pStagesArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkShaderStageFlagBits %s[] = { %s };\n", pStagesArray.c_str(), pStagesValues.c_str());
    }
/* pShaders */
    std::string pShadersArray = "NULL";
    std::string pShadersValues = toStringJoin(pShaders->GetPointer(),
                                              pShaders->GetPointer() + stageCount,
                                              [&](const format::HandleId current) { return this->GetHandle(current); },
                                              ", ");
    if (stageCount == 1) {
        pShadersArray = "&" + pShadersValues;
    } else if (stageCount > 1) {
        pShadersArray = "pShadersArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkShaderEXT %s[] = { %s };\n", pShadersArray.c_str(), pShadersValues.c_str());
    }
    m_pfnLoader.AddMethodName("vkCmdBindShadersEXT");
    fprintf(file,
            "loaded_vkCmdBindShadersEXT(%s, %u, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            stageCount,
            pStagesArray.c_str(),
            pShadersArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindShadersEXT);
}

void VulkanCppConsumer::Process_vkCreateShadersEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkShaderCreateInfoEXT>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkShaderEXT>*          pShaders)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* createInfoCount */
/* pCreateInfos */
    std::stringstream stream_pCreateInfos;
    std::string pCreateInfosArray = "NULL";
    PointerPairContainer<decltype(pCreateInfos->GetPointer()), decltype(pCreateInfos->GetMetaStructPointer())> pCreateInfosPair{ pCreateInfos->GetPointer(), pCreateInfos->GetMetaStructPointer(), createInfoCount };
    std::string pCreateInfosNames = toStringJoin(pCreateInfosPair.begin(),
                                                 pCreateInfosPair.end(),
                                                 [&](auto pair) { return GenerateStruct_VkShaderCreateInfoEXT(stream_pCreateInfos, pair.t1, pair.t2, *this); },
                                                 ", ");
    fprintf(file, "\n%s", stream_pCreateInfos.str().c_str());
    if (createInfoCount == 1) {
        pCreateInfosArray = "&" + pCreateInfosNames;
    } else if (createInfoCount > 1) {
        pCreateInfosArray = "pCreateInfos_" + std::to_string(this->getNextId());
        fprintf(file, "VkShaderCreateInfoEXT %s[] = { %s };\n", pCreateInfosArray.c_str(), pCreateInfosNames.c_str());
    }
/* pAllocator */
/* pShaders */
    std::string pShadersName = "pShaders_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_SHADER_EXT));
    AddKnownVariables("VkShaderEXT", pShadersName, pShaders->GetPointer(), createInfoCount);
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pShadersName,
                         pShaders->GetPointer(), createInfoCount);
    }
    m_pfnLoader.AddMethodName("vkCreateShadersEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateShadersEXT(%s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            createInfoCount,
            pCreateInfosArray.c_str(),
            "nullptr",
            pShadersName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateShadersEXT);
}

void VulkanCppConsumer::Process_vkDestroyShaderEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shader,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* shader */
/* pAllocator */
    m_pfnLoader.AddMethodName("vkDestroyShaderEXT");
    fprintf(file,
            "loaded_vkDestroyShaderEXT(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(shader).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyShaderEXT);
}

void VulkanCppConsumer::Process_vkGetShaderBinaryDataEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            shader,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* shader */
/* pDataSize */
    std::string pDataSizeName = "pDataSize_" + std::to_string(this->getNextId());
    fprintf(file, "size_t %s;\n", pDataSizeName.c_str());
/* pData */
    std::string pDataName = "pData_" + std::to_string(this->getNextId());
    long unsigned int* in_pDataSize = pDataSize->GetPointer();
    fprintf(file, "uint8_t %s[%ld];\n", pDataName.c_str(), *in_pDataSize);
    m_pfnLoader.AddMethodName("vkGetShaderBinaryDataEXT");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetShaderBinaryDataEXT(%s, %s, &%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(shader).c_str(),
            pDataSizeName.c_str(),
            pDataName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetShaderBinaryDataEXT);
}

void VulkanCppConsumer::Process_vkGetDynamicRenderingTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo,
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pRenderingInfo */
    std::stringstream stream_pRenderingInfo;
    std::string pRenderingInfoStruct = GenerateStruct_VkRenderingInfo(stream_pRenderingInfo,
                                                                      pRenderingInfo->GetPointer(),
                                                                      pRenderingInfo->GetMetaStructPointer(),
                                                                      *this);
    fprintf(file, "\n%s", stream_pRenderingInfo.str().c_str());
/* pProperties */
    std::string pPropertiesName = "pProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pProperties;
    pPropertiesName = GenerateStruct_VkTilePropertiesQCOM(stream_pProperties,
                                                     pProperties->GetPointer(),
                                                     pProperties->GetMetaStructPointer(),
                                                     *this);
    fprintf(file, "\n%s", stream_pProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetDynamicRenderingTilePropertiesQCOM");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetDynamicRenderingTilePropertiesQCOM(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pRenderingInfoStruct.c_str(),
            pPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM);
}

void VulkanCppConsumer::Process_vkGetFramebufferTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    PointerDecoder<uint32_t>*                   pPropertiesCount,
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* framebuffer */
/* pPropertiesCount */
    std::string pPropertiesCountName = "pPropertiesCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pPropertiesCountName.c_str());
/* pProperties */
    std::string pPropertiesName = "pProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pProperties;
    pPropertiesName = GenerateStruct_VkTilePropertiesQCOM(stream_pProperties,
                                                     pProperties->GetPointer(),
                                                     pProperties->GetMetaStructPointer(),
                                                     *this);
    fprintf(file, "\n%s", stream_pProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetFramebufferTilePropertiesQCOM");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetFramebufferTilePropertiesQCOM(%s, %s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(framebuffer).c_str(),
            pPropertiesCountName.c_str(),
            pPropertiesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM);
}













void VulkanCppConsumer::Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkImageAspectFlags                          aspectMask)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* aspectMask */
    m_pfnLoader.AddMethodName("vkCmdSetAttachmentFeedbackLoopEnableEXT");
    fprintf(file,
            "loaded_vkCmdSetAttachmentFeedbackLoopEnableEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkImageAspectFlags>(aspectMask).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetAttachmentFeedbackLoopEnableEXT);
}



void VulkanCppConsumer::Process_vkCmdBuildAccelerationStructuresIndirectKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    PointerDecoder<VkDeviceAddress>*            pIndirectDeviceAddresses,
    PointerDecoder<uint32_t>*                   pIndirectStrides,
    PointerDecoder<uint32_t*>*                  ppMaxPrimitiveCounts)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* infoCount */
/* pInfos */
    std::stringstream stream_pInfos;
    std::string pInfosArray = "NULL";
    PointerPairContainer<decltype(pInfos->GetPointer()), decltype(pInfos->GetMetaStructPointer())> pInfosPair{ pInfos->GetPointer(), pInfos->GetMetaStructPointer(), infoCount };
    std::string pInfosNames = toStringJoin(pInfosPair.begin(),
                                           pInfosPair.end(),
                                           [&](auto pair) { return GenerateStruct_VkAccelerationStructureBuildGeometryInfoKHR(stream_pInfos, pair.t1, pair.t2, *this); },
                                           ", ");
    fprintf(file, "\n%s", stream_pInfos.str().c_str());
    if (infoCount == 1) {
        pInfosArray = "&" + pInfosNames;
    } else if (infoCount > 1) {
        pInfosArray = "pInfos_" + std::to_string(this->getNextId());
        fprintf(file, "VkAccelerationStructureBuildGeometryInfoKHR %s[] = { %s };\n", pInfosArray.c_str(), pInfosNames.c_str());
    }
/* pIndirectDeviceAddresses */
    std::string pIndirectDeviceAddressesArray = "pIndirectDeviceAddresses_" + std::to_string(this->getNextId());
    if (infoCount > 0) {
        std::string pIndirectDeviceAddressesValues = toStringJoin(pIndirectDeviceAddresses->GetPointer(),
                                                                  pIndirectDeviceAddresses->GetPointer() + infoCount,
                                                                  [&](const auto current) { return std::to_string(current) + "UL"; },
                                                                  ", ");
        fprintf(file, "VkDeviceAddress %s[] = { %s };\n", pIndirectDeviceAddressesArray.c_str(), pIndirectDeviceAddressesValues.c_str());
    } else {
        pIndirectDeviceAddressesArray = "NULL";
    }
/* pIndirectStrides */
    std::string pIndirectStridesArray = "pIndirectStrides_" + std::to_string(this->getNextId());
    if (infoCount > 0) {
        std::string pIndirectStridesValues = toStringJoin(pIndirectStrides->GetPointer(),
                                                          pIndirectStrides->GetPointer() + infoCount,
                                                          [&](const auto current) { return std::to_string(current) + ""; },
                                                          ", ");
        fprintf(file, "uint32_t %s[] = { %s };\n", pIndirectStridesArray.c_str(), pIndirectStridesValues.c_str());
    } else {
        pIndirectStridesArray = "NULL";
    }
/* ppMaxPrimitiveCounts */
    std::string ppMaxPrimitiveCountsArray = "ppMaxPrimitiveCounts_" + std::to_string(this->getNextId());
    if (infoCount > 0) {
        std::string ppMaxPrimitiveCountsValues = toStringJoin(ppMaxPrimitiveCounts->GetPointer(),
                                                              ppMaxPrimitiveCounts->GetPointer() + infoCount,
                                                              [&](const auto current) { return std::to_string(reinterpret_cast<const VkDeviceSize>(current)) + ""; },
                                                              ", ");
        fprintf(file, "uint32_t %s[] = { %s };\n", ppMaxPrimitiveCountsArray.c_str(), ppMaxPrimitiveCountsValues.c_str());
    } else {
        ppMaxPrimitiveCountsArray = "NULL";
    }
    m_pfnLoader.AddMethodName("vkCmdBuildAccelerationStructuresIndirectKHR");
    fprintf(file,
            "loaded_vkCmdBuildAccelerationStructuresIndirectKHR(%s, %u, %s, %s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            infoCount,
            pInfosArray.c_str(),
            pIndirectDeviceAddressesArray.c_str(),
            pIndirectStridesArray.c_str(),
            ppMaxPrimitiveCountsArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR);
}

void VulkanCppConsumer::Process_vkCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>* ppBuildRangeInfos)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* infoCount */
/* pInfos */
    std::stringstream stream_pInfos;
    std::string pInfosArray = "NULL";
    PointerPairContainer<decltype(pInfos->GetPointer()), decltype(pInfos->GetMetaStructPointer())> pInfosPair{ pInfos->GetPointer(), pInfos->GetMetaStructPointer(), infoCount };
    std::string pInfosNames = toStringJoin(pInfosPair.begin(),
                                           pInfosPair.end(),
                                           [&](auto pair) { return GenerateStruct_VkAccelerationStructureBuildGeometryInfoKHR(stream_pInfos, pair.t1, pair.t2, *this); },
                                           ", ");
    fprintf(file, "\n%s", stream_pInfos.str().c_str());
    if (infoCount == 1) {
        pInfosArray = "&" + pInfosNames;
    } else if (infoCount > 1) {
        pInfosArray = "pInfos_" + std::to_string(this->getNextId());
        fprintf(file, "VkAccelerationStructureBuildGeometryInfoKHR %s[] = { %s };\n", pInfosArray.c_str(), pInfosNames.c_str());
    }
/* ppBuildRangeInfos */
    std::stringstream stream_ppBuildRangeInfos;
    std::string ppBuildRangeInfosArray = "NULL";
    PointerPairContainer<decltype(ppBuildRangeInfos->GetPointer()), decltype(ppBuildRangeInfos->GetMetaStructPointer())> ppBuildRangeInfosPair{ ppBuildRangeInfos->GetPointer(), ppBuildRangeInfos->GetMetaStructPointer(), infoCount };
    std::string ppBuildRangeInfosNames = toStringJoin(ppBuildRangeInfosPair.begin(),
                                                      ppBuildRangeInfosPair.end(),
                                                      [&](auto pair) { return GenerateStruct_VkAccelerationStructureBuildRangeInfoKHR(stream_ppBuildRangeInfos, *pair.t1, *pair.t2, *this); },
                                                      ", ");
    fprintf(file, "\n%s", stream_ppBuildRangeInfos.str().c_str());
    if (infoCount == 1) {
        ppBuildRangeInfosArray = "&" + ppBuildRangeInfosNames;
    } else if (infoCount > 1) {
        ppBuildRangeInfosArray = "ppBuildRangeInfos_" + std::to_string(this->getNextId());
        fprintf(file, "VkAccelerationStructureBuildRangeInfoKHR %s[] = { %s };\n", ppBuildRangeInfosArray.c_str(), ppBuildRangeInfosNames.c_str());
    }
    m_pfnLoader.AddMethodName("vkCmdBuildAccelerationStructuresKHR");
    fprintf(file,
            "loaded_vkCmdBuildAccelerationStructuresKHR(%s, %u, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            infoCount,
            pInfosArray.c_str(),
            ppBuildRangeInfosArray.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR);
}

void VulkanCppConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkCopyAccelerationStructureInfoKHR(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdCopyAccelerationStructureKHR");
    fprintf(file,
            "loaded_vkCmdCopyAccelerationStructureKHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR);
}

void VulkanCppConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkCopyAccelerationStructureToMemoryInfoKHR(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdCopyAccelerationStructureToMemoryKHR");
    fprintf(file,
            "loaded_vkCmdCopyAccelerationStructureToMemoryKHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR);
}

void VulkanCppConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkCopyMemoryToAccelerationStructureInfoKHR(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdCopyMemoryToAccelerationStructureKHR");
    fprintf(file,
            "loaded_vkCmdCopyMemoryToAccelerationStructureKHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR);
}

void VulkanCppConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* accelerationStructureCount */
/* pAccelerationStructures */
    std::string pAccelerationStructuresArray = "NULL";
    std::string pAccelerationStructuresValues = toStringJoin(pAccelerationStructures->GetPointer(),
                                                             pAccelerationStructures->GetPointer() + accelerationStructureCount,
                                                             [&](const format::HandleId current) { return this->GetHandle(current); },
                                                             ", ");
    if (accelerationStructureCount == 1) {
        pAccelerationStructuresArray = "&" + pAccelerationStructuresValues;
    } else if (accelerationStructureCount > 1) {
        pAccelerationStructuresArray = "pAccelerationStructuresArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkAccelerationStructureKHR %s[] = { %s };\n", pAccelerationStructuresArray.c_str(), pAccelerationStructuresValues.c_str());
    }
/* queryType */
/* queryPool */
/* firstQuery */
    m_pfnLoader.AddMethodName("vkCmdWriteAccelerationStructuresPropertiesKHR");
    fprintf(file,
            "loaded_vkCmdWriteAccelerationStructuresPropertiesKHR(%s, %u, %s, %s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            accelerationStructureCount,
            pAccelerationStructuresArray.c_str(),
            util::ToString<VkQueryType>(queryType).c_str(),
            this->GetHandle(queryPool).c_str(),
            firstQuery);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR);
}

void VulkanCppConsumer::Process_vkCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* deferredOperation */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkCopyAccelerationStructureToMemoryInfoKHR(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCopyAccelerationStructureToMemoryKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCopyAccelerationStructureToMemoryKHR(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(deferredOperation).c_str(),
            pInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR);
}

void VulkanCppConsumer::Process_vkCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* deferredOperation */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkCopyMemoryToAccelerationStructureInfoKHR(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCopyMemoryToAccelerationStructureKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCopyMemoryToAccelerationStructureKHR(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(deferredOperation).c_str(),
            pInfoStruct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR);
}

void VulkanCppConsumer::Process_vkCreateAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructure)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkAccelerationStructureCreateInfoKHR(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pAccelerationStructure */
    std::string pAccelerationStructureName = "pAccelerationStructure_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR));
    AddKnownVariables("VkAccelerationStructureKHR", pAccelerationStructureName, pAccelerationStructure->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pAccelerationStructureName,
                         pAccelerationStructure->GetPointer());
    }
    m_pfnLoader.AddMethodName("vkCreateAccelerationStructureKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateAccelerationStructureKHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pAccelerationStructureName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR);
}

void VulkanCppConsumer::Process_vkDestroyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* accelerationStructure */
/* pAllocator */
    m_pfnLoader.AddMethodName("vkDestroyAccelerationStructureKHR");
    fprintf(file,
            "loaded_vkDestroyAccelerationStructureKHR(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(accelerationStructure).c_str(),
            "nullptr");
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR);
}

void VulkanCppConsumer::Process_vkGetAccelerationStructureBuildSizesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkAccelerationStructureBuildTypeKHR         buildType,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pBuildInfo,
    PointerDecoder<uint32_t>*                   pMaxPrimitiveCounts,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR>* pSizeInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* buildType */
/* pBuildInfo */
    std::stringstream stream_pBuildInfo;
    std::string pBuildInfoStruct = GenerateStruct_VkAccelerationStructureBuildGeometryInfoKHR(stream_pBuildInfo,
                                                                  pBuildInfo->GetPointer(),
                                                                  pBuildInfo->GetMetaStructPointer(),
                                                                  *this);
    fprintf(file, "\n%s", stream_pBuildInfo.str().c_str());
/* pMaxPrimitiveCounts */
    std::string pMaxPrimitiveCountsArray = "pMaxPrimitiveCounts_" + std::to_string(this->getNextId());
    if (pBuildInfo->GetPointer()->geometryCount > 0) {
        std::string pMaxPrimitiveCountsValues = toStringJoin(pMaxPrimitiveCounts->GetPointer(),
                                                             pMaxPrimitiveCounts->GetPointer() + pBuildInfo->GetPointer()->geometryCount,
                                                             [&](const auto current) { return std::to_string(current) + ""; },
                                                             ", ");
        fprintf(file, "uint32_t %s[] = { %s };\n", pMaxPrimitiveCountsArray.c_str(), pMaxPrimitiveCountsValues.c_str());
    } else {
        pMaxPrimitiveCountsArray = "NULL";
    }
/* pSizeInfo */
    std::string pSizeInfoName = "pSizeInfo_" + std::to_string(this->getNextId());
    std::stringstream stream_pSizeInfo;
    pSizeInfoName = GenerateStruct_VkAccelerationStructureBuildSizesInfoKHR(stream_pSizeInfo,
                                                   pSizeInfo->GetPointer(),
                                                   pSizeInfo->GetMetaStructPointer(),
                                                   *this);
    fprintf(file, "\n%s", stream_pSizeInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkGetAccelerationStructureBuildSizesKHR");
    fprintf(file,
            "loaded_vkGetAccelerationStructureBuildSizesKHR(%s, %s, &%s, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkAccelerationStructureBuildTypeKHR>(buildType).c_str(),
            pBuildInfoStruct.c_str(),
            pMaxPrimitiveCountsArray.c_str(),
            pSizeInfoName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR);
}

void VulkanCppConsumer::Process_vkGetAccelerationStructureDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkAccelerationStructureDeviceAddressInfoKHR(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkGetAccelerationStructureDeviceAddressKHR");
    fprintf(file,
            "loaded_vkGetAccelerationStructureDeviceAddressKHR(%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR);
}

void VulkanCppConsumer::Process_vkGetDeviceAccelerationStructureCompatibilityKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureVersionInfoKHR>* pVersionInfo,
    PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pVersionInfo */
    std::stringstream stream_pVersionInfo;
    std::string pVersionInfoStruct = GenerateStruct_VkAccelerationStructureVersionInfoKHR(stream_pVersionInfo,
                                                                    pVersionInfo->GetPointer(),
                                                                    pVersionInfo->GetMetaStructPointer(),
                                                                    *this);
    fprintf(file, "\n%s", stream_pVersionInfo.str().c_str());
/* pCompatibility */
    std::string pCompatibilityName = "pCompatibility_" + std::to_string(this->getNextId());
    fprintf(file, "VkAccelerationStructureCompatibilityKHR %s;\n", pCompatibilityName.c_str());
    m_pfnLoader.AddMethodName("vkGetDeviceAccelerationStructureCompatibilityKHR");
    fprintf(file,
            "loaded_vkGetDeviceAccelerationStructureCompatibilityKHR(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pVersionInfoStruct.c_str(),
            pCompatibilityName.c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR);
}

void VulkanCppConsumer::Process_vkWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
    VkQueryType                                 queryType,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData,
    size_t                                      stride)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* accelerationStructureCount */
/* pAccelerationStructures */
    std::string pAccelerationStructuresArray = "NULL";
    std::string pAccelerationStructuresValues = toStringJoin(pAccelerationStructures->GetPointer(),
                                                             pAccelerationStructures->GetPointer() + accelerationStructureCount,
                                                             [&](const format::HandleId current) { return this->GetHandle(current); },
                                                             ", ");
    if (accelerationStructureCount == 1) {
        pAccelerationStructuresArray = "&" + pAccelerationStructuresValues;
    } else if (accelerationStructureCount > 1) {
        pAccelerationStructuresArray = "pAccelerationStructuresArray_" + std::to_string(this->getNextId());
        fprintf(file, "VkAccelerationStructureKHR %s[] = { %s };\n", pAccelerationStructuresArray.c_str(), pAccelerationStructuresValues.c_str());
    }
/* queryType */
/* dataSize */
/* pData */
    std::string pDataName = "pData_" + std::to_string(this->getNextId());
    fprintf(file, "uint8_t %s[%ld];\n", pDataName.c_str(), dataSize);
/* stride */
    m_pfnLoader.AddMethodName("vkWriteAccelerationStructuresPropertiesKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkWriteAccelerationStructuresPropertiesKHR(%s, %u, %s, %s, %lu, %s, %lu), %s);\n",
            this->GetHandle(device).c_str(),
            accelerationStructureCount,
            pAccelerationStructuresArray.c_str(),
            util::ToString<VkQueryType>(queryType).c_str(),
            dataSize,
            pDataName.c_str(),
            stride,
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR);
}

void VulkanCppConsumer::Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    pipelineStackSize)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pipelineStackSize */
    m_pfnLoader.AddMethodName("vkCmdSetRayTracingPipelineStackSizeKHR");
    fprintf(file,
            "loaded_vkCmdSetRayTracingPipelineStackSizeKHR(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            pipelineStackSize);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR);
}

void VulkanCppConsumer::Process_vkCmdTraceRaysIndirectKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    VkDeviceAddress                             indirectDeviceAddress)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pRaygenShaderBindingTable */
    std::stringstream stream_pRaygenShaderBindingTable;
    std::string pRaygenShaderBindingTableStruct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_pRaygenShaderBindingTable,
                                                                                 pRaygenShaderBindingTable->GetPointer(),
                                                                                 pRaygenShaderBindingTable->GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "\n%s", stream_pRaygenShaderBindingTable.str().c_str());
/* pMissShaderBindingTable */
    std::stringstream stream_pMissShaderBindingTable;
    std::string pMissShaderBindingTableStruct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_pMissShaderBindingTable,
                                                                               pMissShaderBindingTable->GetPointer(),
                                                                               pMissShaderBindingTable->GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "\n%s", stream_pMissShaderBindingTable.str().c_str());
/* pHitShaderBindingTable */
    std::stringstream stream_pHitShaderBindingTable;
    std::string pHitShaderBindingTableStruct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_pHitShaderBindingTable,
                                                                              pHitShaderBindingTable->GetPointer(),
                                                                              pHitShaderBindingTable->GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "\n%s", stream_pHitShaderBindingTable.str().c_str());
/* pCallableShaderBindingTable */
    std::stringstream stream_pCallableShaderBindingTable;
    std::string pCallableShaderBindingTableStruct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_pCallableShaderBindingTable,
                                                                                   pCallableShaderBindingTable->GetPointer(),
                                                                                   pCallableShaderBindingTable->GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "\n%s", stream_pCallableShaderBindingTable.str().c_str());
/* indirectDeviceAddress */
    m_pfnLoader.AddMethodName("vkCmdTraceRaysIndirectKHR");
    fprintf(file,
            "loaded_vkCmdTraceRaysIndirectKHR(%s, &%s, &%s, &%s, &%s, %luUL);\n",
            this->GetHandle(commandBuffer).c_str(),
            pRaygenShaderBindingTableStruct.c_str(),
            pMissShaderBindingTableStruct.c_str(),
            pHitShaderBindingTableStruct.c_str(),
            pCallableShaderBindingTableStruct.c_str(),
            indirectDeviceAddress);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR);
}

void VulkanCppConsumer::Process_vkCmdTraceRaysKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* pRaygenShaderBindingTable */
    std::stringstream stream_pRaygenShaderBindingTable;
    std::string pRaygenShaderBindingTableStruct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_pRaygenShaderBindingTable,
                                                                                 pRaygenShaderBindingTable->GetPointer(),
                                                                                 pRaygenShaderBindingTable->GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "\n%s", stream_pRaygenShaderBindingTable.str().c_str());
/* pMissShaderBindingTable */
    std::stringstream stream_pMissShaderBindingTable;
    std::string pMissShaderBindingTableStruct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_pMissShaderBindingTable,
                                                                               pMissShaderBindingTable->GetPointer(),
                                                                               pMissShaderBindingTable->GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "\n%s", stream_pMissShaderBindingTable.str().c_str());
/* pHitShaderBindingTable */
    std::stringstream stream_pHitShaderBindingTable;
    std::string pHitShaderBindingTableStruct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_pHitShaderBindingTable,
                                                                              pHitShaderBindingTable->GetPointer(),
                                                                              pHitShaderBindingTable->GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "\n%s", stream_pHitShaderBindingTable.str().c_str());
/* pCallableShaderBindingTable */
    std::stringstream stream_pCallableShaderBindingTable;
    std::string pCallableShaderBindingTableStruct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_pCallableShaderBindingTable,
                                                                                   pCallableShaderBindingTable->GetPointer(),
                                                                                   pCallableShaderBindingTable->GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "\n%s", stream_pCallableShaderBindingTable.str().c_str());
/* width */
/* height */
/* depth */
    m_pfnLoader.AddMethodName("vkCmdTraceRaysKHR");
    fprintf(file,
            "loaded_vkCmdTraceRaysKHR(%s, &%s, &%s, &%s, &%s, %u, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            pRaygenShaderBindingTableStruct.c_str(),
            pMissShaderBindingTableStruct.c_str(),
            pHitShaderBindingTableStruct.c_str(),
            pCallableShaderBindingTableStruct.c_str(),
            width,
            height,
            depth);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdTraceRaysKHR);
}

void VulkanCppConsumer::Process_vkCreateRayTracingPipelinesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* deferredOperation */
/* pipelineCache */
/* createInfoCount */
/* pCreateInfos */
    std::stringstream stream_pCreateInfos;
    std::string pCreateInfosArray = "NULL";
    PointerPairContainer<decltype(pCreateInfos->GetPointer()), decltype(pCreateInfos->GetMetaStructPointer())> pCreateInfosPair{ pCreateInfos->GetPointer(), pCreateInfos->GetMetaStructPointer(), createInfoCount };
    std::string pCreateInfosNames = toStringJoin(pCreateInfosPair.begin(),
                                                 pCreateInfosPair.end(),
                                                 [&](auto pair) { return GenerateStruct_VkRayTracingPipelineCreateInfoKHR(stream_pCreateInfos, pair.t1, pair.t2, *this); },
                                                 ", ");
    fprintf(file, "\n%s", stream_pCreateInfos.str().c_str());
    if (createInfoCount == 1) {
        pCreateInfosArray = "&" + pCreateInfosNames;
    } else if (createInfoCount > 1) {
        pCreateInfosArray = "pCreateInfos_" + std::to_string(this->getNextId());
        fprintf(file, "VkRayTracingPipelineCreateInfoKHR %s[] = { %s };\n", pCreateInfosArray.c_str(), pCreateInfosNames.c_str());
    }
/* pAllocator */
/* pPipelines */
    std::string pPipelinesName = "pPipelines_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_PIPELINE));
    AddKnownVariables("VkPipeline", pPipelinesName, pPipelines->GetPointer(), createInfoCount);
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pPipelinesName,
                         pPipelines->GetPointer(), createInfoCount);
    }
    m_pfnLoader.AddMethodName("vkCreateRayTracingPipelinesKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateRayTracingPipelinesKHR(%s, %s, %s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(deferredOperation).c_str(),
            this->GetHandle(pipelineCache).c_str(),
            createInfoCount,
            pCreateInfosArray.c_str(),
            "nullptr",
            pPipelinesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR);
}

void VulkanCppConsumer::Process_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pipeline */
/* firstGroup */
/* groupCount */
/* dataSize */
/* pData */
    std::string pDataName = "pData_" + std::to_string(this->getNextId());
    fprintf(file, "uint8_t %s[%ld];\n", pDataName.c_str(), dataSize);
    m_pfnLoader.AddMethodName("vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(%s, %s, %u, %u, %lu, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipeline).c_str(),
            firstGroup,
            groupCount,
            dataSize,
            pDataName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR);
}

void VulkanCppConsumer::Process_vkGetRayTracingShaderGroupStackSizeKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceSize                                returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    group,
    VkShaderGroupShaderKHR                      groupShader)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* device */
/* pipeline */
/* group */
/* groupShader */
    m_pfnLoader.AddMethodName("vkGetRayTracingShaderGroupStackSizeKHR");
    fprintf(file,
            "loaded_vkGetRayTracingShaderGroupStackSizeKHR(%s, %s, %u, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipeline).c_str(),
            group,
            util::ToString<VkShaderGroupShaderKHR>(groupShader).c_str());
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR);
}


void VulkanCppConsumer::Process_vkCmdDrawMeshTasksEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* groupCountX */
/* groupCountY */
/* groupCountZ */
    m_pfnLoader.AddMethodName("vkCmdDrawMeshTasksEXT");
    fprintf(file,
            "loaded_vkCmdDrawMeshTasksEXT(%s, %u, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            groupCountX,
            groupCountY,
            groupCountZ);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT);
}

void VulkanCppConsumer::Process_vkCmdDrawMeshTasksIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* buffer */
/* offset */
/* countBuffer */
/* countBufferOffset */
/* maxDrawCount */
/* stride */
    m_pfnLoader.AddMethodName("vkCmdDrawMeshTasksIndirectCountEXT");
    fprintf(file,
            "loaded_vkCmdDrawMeshTasksIndirectCountEXT(%s, %s, %luUL, %s, %luUL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            this->GetHandle(countBuffer).c_str(),
            countBufferOffset,
            maxDrawCount,
            stride);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT);
}

void VulkanCppConsumer::Process_vkCmdDrawMeshTasksIndirectEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
/* commandBuffer */
/* buffer */
/* offset */
/* drawCount */
/* stride */
    m_pfnLoader.AddMethodName("vkCmdDrawMeshTasksIndirectEXT");
    fprintf(file,
            "loaded_vkCmdDrawMeshTasksIndirectEXT(%s, %s, %luUL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            drawCount,
            stride);
    fprintf(file, "    }\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
