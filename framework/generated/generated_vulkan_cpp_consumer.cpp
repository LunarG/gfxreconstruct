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
/* device */
/* pAllocateInfo */
    std::stringstream stream_pAllocateInfo;
    std::string pAllocateInfoStruct = GenerateStruct_VkCommandBufferAllocateInfo(stream_pAllocateInfo,
                                                                     pAllocateInfo->GetPointer(),
                                                                     pAllocateInfo->GetMetaStructPointer(),
                                                                     *this);
    fprintf(file, "\n%s", stream_pAllocateInfo.str().c_str());
/* pCommandBuffers */
    std::string pCommandBuffersName = "pCommandBuffers_" + std::to_string(this->getNextId());
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
/* device */
/* pAllocateInfo */
    std::stringstream stream_pAllocateInfo;
    std::string pAllocateInfoStruct = GenerateStruct_VkDescriptorSetAllocateInfo(stream_pAllocateInfo,
                                                                     pAllocateInfo->GetPointer(),
                                                                     pAllocateInfo->GetMetaStructPointer(),
                                                                     *this);
    fprintf(file, "\n%s", stream_pAllocateInfo.str().c_str());
/* pDescriptorSets */
    std::string pDescriptorSetsName = "pDescriptorSets_" + std::to_string(this->getNextId());
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
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindIndexBuffer);
}

void VulkanCppConsumer::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    FILE* file = GetFrameFile();
/* commandBuffer */
/* pipelineBindPoint */
/* pipeline */
    fprintf(file,
            "vkCmdBindPipeline(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineBindPoint>(pipelineBindPoint).c_str(),
            this->GetHandle(pipeline).c_str());
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
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDispatch);
}

void VulkanCppConsumer::Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    FILE* file = GetFrameFile();
/* commandBuffer */
/* buffer */
/* offset */
    fprintf(file,
            "vkCmdDispatchIndirect(%s, %s, %luUL);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset);
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
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirect);
}

void VulkanCppConsumer::Process_vkCmdEndQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    FILE* file = GetFrameFile();
/* commandBuffer */
/* queryPool */
/* query */
    fprintf(file,
            "vkCmdEndQuery(%s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(queryPool).c_str(),
            query);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndQuery);
}

void VulkanCppConsumer::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    FILE* file = GetFrameFile();
/* commandBuffer */
    fprintf(file,
            "vkCmdEndRenderPass(%s);\n",
            this->GetHandle(commandBuffer).c_str());
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRenderPass);
}

void VulkanCppConsumer::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    FILE* file = GetFrameFile();
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
    Post_APICall(format::ApiCallId::ApiCall_vkCmdFillBuffer);
}

void VulkanCppConsumer::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSubpassContents                           contents)
{
    FILE* file = GetFrameFile();
/* commandBuffer */
/* contents */
    fprintf(file,
            "vkCmdNextSubpass(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkSubpassContents>(contents).c_str());
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
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPushConstants);
}

void VulkanCppConsumer::Process_vkCmdResetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    FILE* file = GetFrameFile();
/* commandBuffer */
/* event */
/* stageMask */
    fprintf(file,
            "vkCmdResetEvent(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(event).c_str(),
            util::ToString<VkPipelineStageFlags>(stageMask).c_str());
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
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResolveImage);
}

void VulkanCppConsumer::Process_vkCmdSetBlendConstants(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    PointerDecoder<float>*                      blendConstants)
{
    FILE* file = GetFrameFile();
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
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBias);
}

void VulkanCppConsumer::Process_vkCmdSetDepthBounds(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    FILE* file = GetFrameFile();
/* commandBuffer */
/* minDepthBounds */
/* maxDepthBounds */
    fprintf(file,
            "vkCmdSetDepthBounds(%s, %f, %f);\n",
            this->GetHandle(commandBuffer).c_str(),
            minDepthBounds,
            maxDepthBounds);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBounds);
}

void VulkanCppConsumer::Process_vkCmdSetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    FILE* file = GetFrameFile();
/* commandBuffer */
/* event */
/* stageMask */
    fprintf(file,
            "vkCmdSetEvent(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(event).c_str(),
            util::ToString<VkPipelineStageFlags>(stageMask).c_str());
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetEvent);
}

void VulkanCppConsumer::Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       lineWidth)
{
    FILE* file = GetFrameFile();
/* commandBuffer */
/* lineWidth */
    fprintf(file,
            "vkCmdSetLineWidth(%s, %f);\n",
            this->GetHandle(commandBuffer).c_str(),
            lineWidth);
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
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetScissor);
}

void VulkanCppConsumer::Process_vkCmdSetStencilCompareMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    FILE* file = GetFrameFile();
/* commandBuffer */
/* faceMask */
/* compareMask */
    fprintf(file,
            "vkCmdSetStencilCompareMask(%s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkStencilFaceFlags>(faceMask).c_str(),
            compareMask);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask);
}

void VulkanCppConsumer::Process_vkCmdSetStencilReference(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    FILE* file = GetFrameFile();
/* commandBuffer */
/* faceMask */
/* reference */
    fprintf(file,
            "vkCmdSetStencilReference(%s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkStencilFaceFlags>(faceMask).c_str(),
            reference);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilReference);
}

void VulkanCppConsumer::Process_vkCmdSetStencilWriteMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    FILE* file = GetFrameFile();
/* commandBuffer */
/* faceMask */
/* writeMask */
    fprintf(file,
            "vkCmdSetStencilWriteMask(%s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkStencilFaceFlags>(faceMask).c_str(),
            writeMask);
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
    std::string pBufferName = "pBuffer_" + std::to_string(this->getNextId());
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
    std::string pViewName = "pView_" + std::to_string(this->getNextId());
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
    std::string pCommandPoolName = "pCommandPool_" + std::to_string(this->getNextId());
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
    std::string pPipelinesName = "pPipelines_" + std::to_string(this->getNextId());
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
    std::string pDescriptorPoolName = "pDescriptorPool_" + std::to_string(this->getNextId());
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
    std::string pSetLayoutName = "pSetLayout_" + std::to_string(this->getNextId());
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
    std::string pDeviceName = "pDevice_" + std::to_string(this->getNextId());
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
    std::string pEventName = "pEvent_" + std::to_string(this->getNextId());
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
    std::string pFenceName = "pFence_" + std::to_string(this->getNextId());
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
    std::string pFramebufferName = "pFramebuffer_" + std::to_string(this->getNextId());
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
    std::string pPipelinesName = "pPipelines_" + std::to_string(this->getNextId());
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
    std::string pImageName = "pImage_" + std::to_string(this->getNextId());
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
    std::string pViewName = "pView_" + std::to_string(this->getNextId());
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
    std::string pPipelineLayoutName = "pPipelineLayout_" + std::to_string(this->getNextId());
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
    std::string pQueryPoolName = "pQueryPool_" + std::to_string(this->getNextId());
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
    std::string pRenderPassName = "pRenderPass_" + std::to_string(this->getNextId());
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
    std::string pSamplerName = "pSampler_" + std::to_string(this->getNextId());
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
    std::string pSemaphoreName = "pSemaphore_" + std::to_string(this->getNextId());
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
/* device */
/* buffer */
/* pAllocator */
    fprintf(file,
            "vkDestroyBuffer(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(buffer).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyBuffer);
}

void VulkanCppConsumer::Process_vkDestroyBufferView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            bufferView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* device */
/* bufferView */
/* pAllocator */
    fprintf(file,
            "vkDestroyBufferView(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(bufferView).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyBufferView);
}

void VulkanCppConsumer::Process_vkDestroyCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* device */
/* commandPool */
/* pAllocator */
    fprintf(file,
            "vkDestroyCommandPool(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(commandPool).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyCommandPool);
}

void VulkanCppConsumer::Process_vkDestroyDescriptorPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* device */
/* descriptorPool */
/* pAllocator */
    fprintf(file,
            "vkDestroyDescriptorPool(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(descriptorPool).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDescriptorPool);
}

void VulkanCppConsumer::Process_vkDestroyDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSetLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* device */
/* descriptorSetLayout */
/* pAllocator */
    fprintf(file,
            "vkDestroyDescriptorSetLayout(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(descriptorSetLayout).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout);
}

void VulkanCppConsumer::Process_vkDestroyDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* device */
/* pAllocator */
    fprintf(file,
            "vkDestroyDevice(%s, %s);\n",
            this->GetHandle(device).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDevice);
}

void VulkanCppConsumer::Process_vkDestroyEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* device */
/* event */
/* pAllocator */
    fprintf(file,
            "vkDestroyEvent(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(event).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyEvent);
}

void VulkanCppConsumer::Process_vkDestroyFence(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            fence,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* device */
/* fence */
/* pAllocator */
    fprintf(file,
            "vkDestroyFence(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(fence).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyFence);
}

void VulkanCppConsumer::Process_vkDestroyFramebuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* device */
/* framebuffer */
/* pAllocator */
    fprintf(file,
            "vkDestroyFramebuffer(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(framebuffer).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyFramebuffer);
}

void VulkanCppConsumer::Process_vkDestroyImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* device */
/* image */
/* pAllocator */
    fprintf(file,
            "vkDestroyImage(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(image).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyImage);
}

void VulkanCppConsumer::Process_vkDestroyImageView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* device */
/* imageView */
/* pAllocator */
    fprintf(file,
            "vkDestroyImageView(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(imageView).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyImageView);
}

void VulkanCppConsumer::Process_vkDestroyInstance(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* instance */
/* pAllocator */
    fprintf(file,
            "vkDestroyInstance(%s, %s);\n",
            this->GetHandle(instance).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyInstance);
}

void VulkanCppConsumer::Process_vkDestroyPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* device */
/* pipeline */
/* pAllocator */
    fprintf(file,
            "vkDestroyPipeline(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipeline).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPipeline);
}

void VulkanCppConsumer::Process_vkDestroyPipelineCache(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* device */
/* pipelineCache */
/* pAllocator */
    fprintf(file,
            "vkDestroyPipelineCache(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipelineCache).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPipelineCache);
}

void VulkanCppConsumer::Process_vkDestroyPipelineLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* device */
/* pipelineLayout */
/* pAllocator */
    fprintf(file,
            "vkDestroyPipelineLayout(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipelineLayout).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPipelineLayout);
}

void VulkanCppConsumer::Process_vkDestroyQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* device */
/* queryPool */
/* pAllocator */
    fprintf(file,
            "vkDestroyQueryPool(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(queryPool).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyQueryPool);
}

void VulkanCppConsumer::Process_vkDestroyRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* device */
/* renderPass */
/* pAllocator */
    fprintf(file,
            "vkDestroyRenderPass(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(renderPass).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyRenderPass);
}

void VulkanCppConsumer::Process_vkDestroySampler(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            sampler,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* device */
/* sampler */
/* pAllocator */
    fprintf(file,
            "vkDestroySampler(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(sampler).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySampler);
}

void VulkanCppConsumer::Process_vkDestroySemaphore(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* device */
/* semaphore */
/* pAllocator */
    fprintf(file,
            "vkDestroySemaphore(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(semaphore).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySemaphore);
}

void VulkanCppConsumer::Process_vkDestroyShaderModule(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* device */
/* shaderModule */
/* pAllocator */
    fprintf(file,
            "vkDestroyShaderModule(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(shaderModule).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyShaderModule);
}

void VulkanCppConsumer::Process_vkDeviceWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device)
{
    FILE* file = GetFrameFile();
/* device */
    fprintf(file,
            "VK_CALL_CHECK(vkDeviceWaitIdle(%s), %s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    Post_APICall(format::ApiCallId::ApiCall_vkDeviceWaitIdle);
}

void VulkanCppConsumer::Process_vkEndCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer)
{
    FILE* file = GetFrameFile();
/* commandBuffer */
    fprintf(file,
            "VK_CALL_CHECK(vkEndCommandBuffer(%s), %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
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
    Post_APICall(format::ApiCallId::ApiCall_vkFreeDescriptorSets);
}

void VulkanCppConsumer::Process_vkFreeMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* device */
/* memory */
/* pAllocator */
    fprintf(file,
            "vkFreeMemory(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(memory).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkFreeMemory);
}

void VulkanCppConsumer::Process_vkGetBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();
/* device */
/* buffer */
/* pMemoryRequirements */
    std::string pMemoryRequirementsName = "pMemoryRequirements_" + std::to_string(this->getNextId());
    fprintf(file, "VkMemoryRequirements %s;\n", pMemoryRequirementsName.c_str());
    fprintf(file,
            "vkGetBufferMemoryRequirements(%s, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(buffer).c_str(),
            pMemoryRequirementsName.c_str());
    Post_vkGetBufferMemoryRequirements(device,
                                       buffer,
                                       pMemoryRequirements,
                                       this->GetHandle(device),
                                       this->GetHandle(buffer),
                                       pMemoryRequirementsName);
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements);
}

void VulkanCppConsumer::Process_vkGetDeviceMemoryCommitment(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    PointerDecoder<VkDeviceSize>*               pCommittedMemoryInBytes)
{
    FILE* file = GetFrameFile();
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
/* device */
/* queueFamilyIndex */
/* queueIndex */
/* pQueue */
    std::string pQueueName = "pQueue_" + std::to_string(this->getNextId());
    AddKnownVariables("VkQueue", pQueueName, pQueue->GetPointer());
    this->AddHandles(pQueueName,
                     pQueue->GetPointer());
    fprintf(file,
            "vkGetDeviceQueue(%s, %u, %u, &%s);\n",
            this->GetHandle(device).c_str(),
            queueFamilyIndex,
            queueIndex,
            pQueueName.c_str());
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceQueue);
}

void VulkanCppConsumer::Process_vkGetEventStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    FILE* file = GetFrameFile();
/* device */
/* event */
    fprintf(file,
            "VK_CALL_CHECK(vkGetEventStatus(%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(event).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
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
    FILE* file = GetFrameFile();
/* device */
/* image */
/* pMemoryRequirements */
    std::string pMemoryRequirementsName = "pMemoryRequirements_" + std::to_string(this->getNextId());
    fprintf(file, "VkMemoryRequirements %s;\n", pMemoryRequirementsName.c_str());
    fprintf(file,
            "vkGetImageMemoryRequirements(%s, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(image).c_str(),
            pMemoryRequirementsName.c_str());
    Post_vkGetImageMemoryRequirements(device,
                                      image,
                                      pMemoryRequirements,
                                      this->GetHandle(device),
                                      this->GetHandle(image),
                                      pMemoryRequirementsName);
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements);
}

void VulkanCppConsumer::Process_vkGetImageSparseMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements)
{
    FILE* file = GetFrameFile();
/* device */
/* image */
/* pSparseMemoryRequirementCount */
    std::string pSparseMemoryRequirementCountName = "pSparseMemoryRequirementCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pSparseMemoryRequirementCountName.c_str());
/* pSparseMemoryRequirements */
    std::string pSparseMemoryRequirementsName = "pSparseMemoryRequirements_" + std::to_string(this->getNextId());
    const uint32_t* in_pSparseMemoryRequirementCount = pSparseMemoryRequirementCount->GetPointer();
    fprintf(file, "VkSparseImageMemoryRequirements %s[%d];\n", pSparseMemoryRequirementsName.c_str(), *in_pSparseMemoryRequirementCount);
    fprintf(file,
            "vkGetImageSparseMemoryRequirements(%s, %s, &%s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(image).c_str(),
            pSparseMemoryRequirementCountName.c_str(),
            pSparseMemoryRequirementsName.c_str());
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
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSubresourceLayout);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures)
{
    FILE* file = GetFrameFile();
/* physicalDevice */
/* pFeatures */
    std::string pFeaturesName = "pFeatures_" + std::to_string(this->getNextId());
    fprintf(file, "VkPhysicalDeviceFeatures %s;\n", pFeaturesName.c_str());
    fprintf(file,
            "vkGetPhysicalDeviceFeatures(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pFeaturesName.c_str());
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceFormatProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties)
{
    FILE* file = GetFrameFile();
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
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties)
{
    FILE* file = GetFrameFile();
/* physicalDevice */
/* pMemoryProperties */
    std::string pMemoryPropertiesName = "pMemoryProperties_" + std::to_string(this->getNextId());
    fprintf(file, "VkPhysicalDeviceMemoryProperties %s;\n", pMemoryPropertiesName.c_str());
    fprintf(file,
            "vkGetPhysicalDeviceMemoryProperties(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pMemoryPropertiesName.c_str());
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties)
{
    FILE* file = GetFrameFile();
/* physicalDevice */
/* pProperties */
    std::string pPropertiesName = "pProperties_" + std::to_string(this->getNextId());
    fprintf(file, "VkPhysicalDeviceProperties %s;\n", pPropertiesName.c_str());
    fprintf(file,
            "vkGetPhysicalDeviceProperties(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pPropertiesName.c_str());
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
    fprintf(file, "// TODO: Support vkGetPipelineCacheData function.\n");
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
    FILE* file = GetFrameFile();
/* device */
/* queryPool */
/* firstQuery */
/* queryCount */
/* dataSize */
/* pData */
    std::string pDataName = "pData_" + std::to_string(this->getNextId());
    fprintf(file, "uint8_t %s[%ld];\n", pDataName.c_str(), dataSize);
/* stride */
/* flags */
    fprintf(file,
            "VK_CALL_CHECK(vkGetQueryPoolResults(%s, %s, %u, %u, %lu, %s, %luUL, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(queryPool).c_str(),
            firstQuery,
            queryCount,
            dataSize,
            pDataName.c_str(),
            stride,
            util::ToString<VkQueryResultFlags>(flags).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    Post_APICall(format::ApiCallId::ApiCall_vkGetQueryPoolResults);
}

void VulkanCppConsumer::Process_vkGetRenderAreaGranularity(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity)
{
    FILE* file = GetFrameFile();
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
    Post_APICall(format::ApiCallId::ApiCall_vkQueueSubmit);
}

void VulkanCppConsumer::Process_vkQueueWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue)
{
    FILE* file = GetFrameFile();
/* queue */
    fprintf(file,
            "VK_CALL_CHECK(vkQueueWaitIdle(%s), %s);\n",
            this->GetHandle(queue).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    Post_APICall(format::ApiCallId::ApiCall_vkQueueWaitIdle);
}

void VulkanCppConsumer::Process_vkResetCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    FILE* file = GetFrameFile();
/* commandBuffer */
/* flags */
    fprintf(file,
            "VK_CALL_CHECK(vkResetCommandBuffer(%s, %s), %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkCommandBufferResetFlags>(flags).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
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
/* device */
/* commandPool */
/* flags */
    fprintf(file,
            "VK_CALL_CHECK(vkResetCommandPool(%s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(commandPool).c_str(),
            util::ToString<VkCommandPoolResetFlags>(flags).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
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
/* device */
/* descriptorPool */
/* flags */
    fprintf(file,
            "VK_CALL_CHECK(vkResetDescriptorPool(%s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(descriptorPool).c_str(),
            util::ToString<VkDescriptorPoolResetFlags>(flags).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    Post_APICall(format::ApiCallId::ApiCall_vkResetDescriptorPool);
}

void VulkanCppConsumer::Process_vkResetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    FILE* file = GetFrameFile();
/* device */
/* event */
    fprintf(file,
            "VK_CALL_CHECK(vkResetEvent(%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(event).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
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
    Post_APICall(format::ApiCallId::ApiCall_vkResetFences);
}

void VulkanCppConsumer::Process_vkSetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    FILE* file = GetFrameFile();
/* device */
/* event */
    fprintf(file,
            "VK_CALL_CHECK(vkSetEvent(%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(event).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
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
    FILE* file = GetFrameFile();
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
/* waitAll */
/* timeout */
    fprintf(file,
            "VK_CALL_CHECK(vkWaitForFences(%s, %u, %s, %u, %luUL), %s);\n",
            this->GetHandle(device).c_str(),
            fenceCount,
            pFencesArray.c_str(),
            waitAll,
            timeout,
            util::ToString<VkResult>(returnValue).c_str());
    Post_APICall(format::ApiCallId::ApiCall_vkWaitForFences);
}

void VulkanCppConsumer::Process_vkDestroySurfaceKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* instance */
/* surface */
/* pAllocator */
    m_pfnLoader.AddMethodName("vkDestroySurfaceKHR");
    fprintf(file,
            "loaded_vkDestroySurfaceKHR(%s, %s, %s);\n",
            this->GetHandle(instance).c_str(),
            this->GetHandle(surface).c_str(),
            "nullptr");
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
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR);
}

void VulkanCppConsumer::Process_vkAcquireNextImage2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    FILE* file = GetFrameFile();
/* device */
/* pAcquireInfo */
    std::stringstream stream_pAcquireInfo;
    std::string pAcquireInfoStruct = GenerateStruct_VkAcquireNextImageInfoKHR(stream_pAcquireInfo,
                                                                    pAcquireInfo->GetPointer(),
                                                                    pAcquireInfo->GetMetaStructPointer(),
                                                                    *this);
    fprintf(file, "\n%s", stream_pAcquireInfo.str().c_str());
/* pImageIndex */
    std::string pImageIndexName = "pImageIndex_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pImageIndexName.c_str());
    m_pfnLoader.AddMethodName("vkAcquireNextImage2KHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkAcquireNextImage2KHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pAcquireInfoStruct.c_str(),
            pImageIndexName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
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
    std::string pSwapchainName = "pSwapchain_" + std::to_string(this->getNextId());
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
    Post_APICall(format::ApiCallId::ApiCall_vkCreateSwapchainKHR);
}

void VulkanCppConsumer::Process_vkDestroySwapchainKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* device */
/* swapchain */
/* pAllocator */
    m_pfnLoader.AddMethodName("vkDestroySwapchainKHR");
    fprintf(file,
            "loaded_vkDestroySwapchainKHR(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapchain).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySwapchainKHR);
}

void VulkanCppConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities)
{
    FILE* file = GetFrameFile();
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
    Post_APICall(format::ApiCallId::ApiCall_vkQueuePresentKHR);
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


void VulkanCppConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    FILE* file = GetFrameFile();
/* physicalDevice */
/* pFeatures */
    std::string pFeaturesName = "pFeatures_" + std::to_string(this->getNextId());
    std::stringstream stream_pFeatures;
    pFeaturesName = GenerateStruct_VkPhysicalDeviceFeatures2KHR(stream_pFeatures,
                                                   pFeatures->GetPointer(),
                                                   pFeatures->GetMetaStructPointer(),
                                                   *this);
    fprintf(file, "\n%s", stream_pFeatures.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceFeatures2KHR");
    fprintf(file,
            "loaded_vkGetPhysicalDeviceFeatures2KHR(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pFeaturesName.c_str());
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    FILE* file = GetFrameFile();
/* physicalDevice */
/* format */
/* pFormatProperties */
    std::string pFormatPropertiesName = "pFormatProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pFormatProperties;
    pFormatPropertiesName = GenerateStruct_VkFormatProperties2KHR(stream_pFormatProperties,
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
/* physicalDevice */
/* pImageFormatInfo */
    std::stringstream stream_pImageFormatInfo;
    std::string pImageFormatInfoStruct = GenerateStruct_VkPhysicalDeviceImageFormatInfo2KHR(stream_pImageFormatInfo,
                                                                        pImageFormatInfo->GetPointer(),
                                                                        pImageFormatInfo->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "\n%s", stream_pImageFormatInfo.str().c_str());
/* pImageFormatProperties */
    std::string pImageFormatPropertiesName = "pImageFormatProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pImageFormatProperties;
    pImageFormatPropertiesName = GenerateStruct_VkImageFormatProperties2KHR(stream_pImageFormatProperties,
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
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    FILE* file = GetFrameFile();
/* physicalDevice */
/* pMemoryProperties */
    std::string pMemoryPropertiesName = "pMemoryProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pMemoryProperties;
    pMemoryPropertiesName = GenerateStruct_VkPhysicalDeviceMemoryProperties2KHR(stream_pMemoryProperties,
                                                           pMemoryProperties->GetPointer(),
                                                           pMemoryProperties->GetMetaStructPointer(),
                                                           *this);
    fprintf(file, "\n%s", stream_pMemoryProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceMemoryProperties2KHR");
    fprintf(file,
            "loaded_vkGetPhysicalDeviceMemoryProperties2KHR(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pMemoryPropertiesName.c_str());
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    FILE* file = GetFrameFile();
/* physicalDevice */
/* pProperties */
    std::string pPropertiesName = "pProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pProperties;
    pPropertiesName = GenerateStruct_VkPhysicalDeviceProperties2KHR(stream_pProperties,
                                                     pProperties->GetPointer(),
                                                     pProperties->GetMetaStructPointer(),
                                                     *this);
    fprintf(file, "\n%s", stream_pProperties.str().c_str());
    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceProperties2KHR");
    fprintf(file,
            "loaded_vkGetPhysicalDeviceProperties2KHR(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pPropertiesName.c_str());
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    FILE* file = GetFrameFile();
/* physicalDevice */
/* pQueueFamilyPropertyCount */
    std::string pQueueFamilyPropertyCountName = "pQueueFamilyPropertyCount_" + std::to_string(this->getNextId());
    fprintf(file, "uint32_t %s;\n", pQueueFamilyPropertyCountName.c_str());
/* pQueueFamilyProperties */
    std::string pQueueFamilyPropertiesName = "pQueueFamilyProperties_" + std::to_string(this->getNextId());
    std::stringstream stream_pQueueFamilyProperties;
    pQueueFamilyPropertiesName = GenerateStruct_VkQueueFamilyProperties2KHR(stream_pQueueFamilyProperties,
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
/* physicalDevice */
/* pFormatInfo */
    std::stringstream stream_pFormatInfo;
    std::string pFormatInfoStruct = GenerateStruct_VkPhysicalDeviceSparseImageFormatInfo2KHR(stream_pFormatInfo,
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
    pPropertiesName = GenerateStruct_VkSparseImageFormatProperties2KHR(stream_pProperties,
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
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR);
}

void VulkanCppConsumer::Process_vkTrimCommandPoolKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    FILE* file = GetFrameFile();
/* device */
/* commandPool */
/* flags */
    m_pfnLoader.AddMethodName("vkTrimCommandPoolKHR");
    fprintf(file,
            "loaded_vkTrimCommandPoolKHR(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(commandPool).c_str(),
            util::ToString<VkCommandPoolTrimFlagsKHR>(flags).c_str());
    Post_APICall(format::ApiCallId::ApiCall_vkTrimCommandPoolKHR);
}

void VulkanCppConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
/* device */
/* descriptorUpdateTemplate */
/* pAllocator */
    m_pfnLoader.AddMethodName("vkDestroyDescriptorUpdateTemplateKHR");
    fprintf(file,
            "loaded_vkDestroyDescriptorUpdateTemplateKHR(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(descriptorUpdateTemplate).c_str(),
            "nullptr");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR);
}

void VulkanCppConsumer::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    FILE* file = GetFrameFile();
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
    std::string pSubpassBeginInfoStruct = GenerateStruct_VkSubpassBeginInfoKHR(stream_pSubpassBeginInfo,
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
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR);
}

void VulkanCppConsumer::Process_vkCmdEndRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    FILE* file = GetFrameFile();
/* commandBuffer */
/* pSubpassEndInfo */
    std::stringstream stream_pSubpassEndInfo;
    std::string pSubpassEndInfoStruct = GenerateStruct_VkSubpassEndInfoKHR(stream_pSubpassEndInfo,
                                                                       pSubpassEndInfo->GetPointer(),
                                                                       pSubpassEndInfo->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "\n%s", stream_pSubpassEndInfo.str().c_str());
    m_pfnLoader.AddMethodName("vkCmdEndRenderPass2KHR");
    fprintf(file,
            "loaded_vkCmdEndRenderPass2KHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pSubpassEndInfoStruct.c_str());
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR);
}

void VulkanCppConsumer::Process_vkCmdNextSubpass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    FILE* file = GetFrameFile();
/* commandBuffer */
/* pSubpassBeginInfo */
    std::stringstream stream_pSubpassBeginInfo;
    std::string pSubpassBeginInfoStruct = GenerateStruct_VkSubpassBeginInfoKHR(stream_pSubpassBeginInfo,
                                                                         pSubpassBeginInfo->GetPointer(),
                                                                         pSubpassBeginInfo->GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "\n%s", stream_pSubpassBeginInfo.str().c_str());
/* pSubpassEndInfo */
    std::stringstream stream_pSubpassEndInfo;
    std::string pSubpassEndInfoStruct = GenerateStruct_VkSubpassEndInfoKHR(stream_pSubpassEndInfo,
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
/* device */
/* pCreateInfo */
    std::stringstream stream_pCreateInfo;
    std::string pCreateInfoStruct = GenerateStruct_VkRenderPassCreateInfo2KHR(stream_pCreateInfo,
                                                                   pCreateInfo->GetPointer(),
                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
/* pAllocator */
/* pRenderPass */
    std::string pRenderPassName = "pRenderPass_" + std::to_string(this->getNextId());
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
    Post_APICall(format::ApiCallId::ApiCall_vkCreateRenderPass2KHR);
}


void VulkanCppConsumer::Process_vkGetBufferMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkBufferMemoryRequirementsInfo2KHR(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
/* pMemoryRequirements */
    std::string pMemoryRequirementsName = "pMemoryRequirements_" + std::to_string(this->getNextId());
    std::stringstream stream_pMemoryRequirements;
    pMemoryRequirementsName = GenerateStruct_VkMemoryRequirements2KHR(stream_pMemoryRequirements,
                                                             pMemoryRequirements->GetPointer(),
                                                             pMemoryRequirements->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pMemoryRequirements.str().c_str());
    m_pfnLoader.AddMethodName("vkGetBufferMemoryRequirements2KHR");
    fprintf(file,
            "loaded_vkGetBufferMemoryRequirements2KHR(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str(),
            pMemoryRequirementsName.c_str());
    Post_vkGetBufferMemoryRequirements2KHR(device,
                                           pInfo,
                                           pMemoryRequirements,
                                           this->GetHandle(device),
                                           pInfoStruct,
                                           pMemoryRequirementsName);
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR);
}

void VulkanCppConsumer::Process_vkGetImageMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkImageMemoryRequirementsInfo2KHR(stream_pInfo,
                                                             pInfo->GetPointer(),
                                                             pInfo->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());
/* pMemoryRequirements */
    std::string pMemoryRequirementsName = "pMemoryRequirements_" + std::to_string(this->getNextId());
    std::stringstream stream_pMemoryRequirements;
    pMemoryRequirementsName = GenerateStruct_VkMemoryRequirements2KHR(stream_pMemoryRequirements,
                                                             pMemoryRequirements->GetPointer(),
                                                             pMemoryRequirements->GetMetaStructPointer(),
                                                             *this);
    fprintf(file, "\n%s", stream_pMemoryRequirements.str().c_str());
    m_pfnLoader.AddMethodName("vkGetImageMemoryRequirements2KHR");
    fprintf(file,
            "loaded_vkGetImageMemoryRequirements2KHR(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str(),
            pMemoryRequirementsName.c_str());
    Post_vkGetImageMemoryRequirements2KHR(device,
                                          pInfo,
                                          pMemoryRequirements,
                                          this->GetHandle(device),
                                          pInfoStruct,
                                          pMemoryRequirementsName);
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
/* device */
/* pInfo */
    std::stringstream stream_pInfo;
    std::string pInfoStruct = GenerateStruct_VkImageSparseMemoryRequirementsInfo2KHR(stream_pInfo,
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
    pSparseMemoryRequirementsName = GenerateStruct_VkSparseImageMemoryRequirements2KHR(stream_pSparseMemoryRequirements,
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
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR);
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
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR);
}





GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
