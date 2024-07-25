/*
** Copyright (c) 2020 Samsung
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pallocate_info;
    std::string pallocate_info_struct = GenerateStruct_VkCommandBufferAllocateInfo(stream_pallocate_info,
                                                                                   pAllocateInfo->GetPointer(),
                                                                                   pAllocateInfo->GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "%s", stream_pallocate_info.str().c_str());
    std::string pcommand_buffers_name = "pCommandBuffers_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_COMMAND_BUFFER));
    AddKnownVariables("VkCommandBuffer", pcommand_buffers_name, pCommandBuffers->GetPointer(), pAllocateInfo->GetPointer()->commandBufferCount);
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pcommand_buffers_name,
                         pCommandBuffers->GetPointer(), pAllocateInfo->GetPointer()->commandBufferCount);
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkAllocateCommandBuffers(%s, &%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            pallocate_info_struct.c_str(),
            pcommand_buffers_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pallocate_info;
    std::string pallocate_info_struct = GenerateStruct_VkDescriptorSetAllocateInfo(stream_pallocate_info,
                                                                                   pAllocateInfo->GetPointer(),
                                                                                   pAllocateInfo->GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "%s", stream_pallocate_info.str().c_str());
    std::string pdescriptor_sets_name = "pDescriptorSets_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DESCRIPTOR_SET));
    AddKnownVariables("VkDescriptorSet", pdescriptor_sets_name, pDescriptorSets->GetPointer(), pAllocateInfo->GetPointer()->descriptorSetCount);
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pdescriptor_sets_name,
                         pDescriptorSets->GetPointer(), pAllocateInfo->GetPointer()->descriptorSetCount);
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkAllocateDescriptorSets(%s, &%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            pallocate_info_struct.c_str(),
            pdescriptor_sets_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pbegin_info;
    std::string pbegin_info_struct = GenerateStruct_VkCommandBufferBeginInfo(stream_pbegin_info,
                                                                             pBeginInfo->GetPointer(),
                                                                             pBeginInfo->GetMetaStructPointer(),
                                                                             *this);
    fprintf(file, "%s", stream_pbegin_info.str().c_str());
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkBeginCommandBuffer(%s, &%s), %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pbegin_info_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    Intercept_vkBindBufferMemory(returnValue, device, buffer, memory, memoryOffset);
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkBindBufferMemory(%s, %s, %s, %" PRIu64 "UL), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(buffer).c_str(),
            this->GetHandle(memory).c_str(),
            memoryOffset,
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    Intercept_vkBindImageMemory(returnValue, device, image, memory, memoryOffset);
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkBindImageMemory(%s, %s, %s, %" PRIu64 "UL), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(image).c_str(),
            this->GetHandle(memory).c_str(),
            memoryOffset,
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdBeginQuery(%s, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(queryPool).c_str(),
            query,
            util::ToString<VkQueryControlFlags>(flags).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_prender_pass_begin;
    std::string prender_pass_begin_struct = GenerateStruct_VkRenderPassBeginInfo(stream_prender_pass_begin,
                                                                                 pRenderPassBegin->GetPointer(),
                                                                                 pRenderPassBegin->GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_prender_pass_begin.str().c_str());
    fprintf(file,
            "\t\tvkCmdBeginRenderPass(%s, &%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            prender_pass_begin_struct.c_str(),
            util::ToString<VkSubpassContents>(contents).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pdescriptor_sets_array = "NULL";
    std::string pdescriptor_sets_values = toStringJoin(pDescriptorSets->GetPointer(),
                                                       pDescriptorSets->GetPointer() + descriptorSetCount,
                                                       [&](const format::HandleId current) { return this->GetHandle(current); },
                                                       ", ");
    if (descriptorSetCount == 1 && pdescriptor_sets_values != "VK_NULL_HANDLE") {
        pdescriptor_sets_array = "&" + pdescriptor_sets_values;
    } else if (descriptorSetCount > 1) {
        pdescriptor_sets_array = "pdescriptor_sets_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDescriptorSet %s[] = { %s };\n", pdescriptor_sets_array.c_str(), pdescriptor_sets_values.c_str());
    }
    std::string pdynamic_offsets_array = "pDynamicOffsets_" + std::to_string(this->GetNextId());
    if (dynamicOffsetCount > 0) {
        std::string pdynamic_offsets_values = toStringJoin(pDynamicOffsets->GetPointer(),
                                                           pDynamicOffsets->GetPointer() + dynamicOffsetCount,
                                                           [&](const auto current) { return std::to_string(current) + ""; },
                                                           ", ");
        fprintf(file, "\t\tuint32_t %s[] = { %s };\n", pdynamic_offsets_array.c_str(), pdynamic_offsets_values.c_str());
    } else {
        pdynamic_offsets_array = "NULL";
    }
    fprintf(file,
            "\t\tvkCmdBindDescriptorSets(%s, %s, %s, %u, %u, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineBindPoint>(pipelineBindPoint).c_str(),
            this->GetHandle(layout).c_str(),
            firstSet,
            descriptorSetCount,
            pdescriptor_sets_array.c_str(),
            dynamicOffsetCount,
            pdynamic_offsets_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdBindIndexBuffer(%s, %s, %" PRIu64 "UL, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            util::ToString<VkIndexType>(indexType).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindIndexBuffer);
}

void VulkanCppConsumer::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdBindPipeline(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineBindPoint>(pipelineBindPoint).c_str(),
            this->GetHandle(pipeline).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pbuffers_array = "NULL";
    std::string pbuffers_values = toStringJoin(pBuffers->GetPointer(),
                                               pBuffers->GetPointer() + bindingCount,
                                               [&](const format::HandleId current) { return this->GetHandle(current); },
                                               ", ");
    if (bindingCount == 1 && pbuffers_values != "VK_NULL_HANDLE") {
        pbuffers_array = "&" + pbuffers_values;
    } else if (bindingCount > 1) {
        pbuffers_array = "pbuffers_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkBuffer %s[] = { %s };\n", pbuffers_array.c_str(), pbuffers_values.c_str());
    }
    std::string poffsets_array = "pOffsets_" + std::to_string(this->GetNextId());
    if (bindingCount > 0) {
        std::string poffsets_values = toStringJoin(pOffsets->GetPointer(),
                                                   pOffsets->GetPointer() + bindingCount,
                                                   [&](const auto current) { return std::to_string(current) + "UL"; },
                                                   ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", poffsets_array.c_str(), poffsets_values.c_str());
    } else {
        poffsets_array = "NULL";
    }
    fprintf(file,
            "\t\tvkCmdBindVertexBuffers(%s, %u, %u, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstBinding,
            bindingCount,
            pbuffers_array.c_str(),
            poffsets_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pregions;
    std::string pregions_array = "NULL";
    PointerPairContainer<decltype(pRegions->GetPointer()), decltype(pRegions->GetMetaStructPointer())> pregions_pair{ pRegions->GetPointer(), pRegions->GetMetaStructPointer(), regionCount };
    std::string pregions_names = toStringJoin(pregions_pair.begin(),
                                              pregions_pair.end(),
                                              [&](auto pair) {{ return GenerateStruct_VkImageBlit(stream_pregions, pair.t1, pair.t2, *this); }},
                                              ", ");
    if (stream_pregions.str().length() > 0) {
        fprintf(file, "%s", stream_pregions.str().c_str());
        if (regionCount == 1) {
            pregions_array = "&" + pregions_names;
        } else if (regionCount > 1) {
            pregions_array = "pRegions_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkImageBlit %s[] = { %s };\n", pregions_array.c_str(), pregions_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdBlitImage(%s, %s, %s, %s, %s, %u, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(srcImage).c_str(),
            util::ToString<VkImageLayout>(srcImageLayout).c_str(),
            this->GetHandle(dstImage).c_str(),
            util::ToString<VkImageLayout>(dstImageLayout).c_str(),
            regionCount,
            pregions_array.c_str(),
            util::ToString<VkFilter>(filter).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pattachments;
    std::string pattachments_array = "NULL";
    PointerPairContainer<decltype(pAttachments->GetPointer()), decltype(pAttachments->GetMetaStructPointer())> pattachments_pair{ pAttachments->GetPointer(), pAttachments->GetMetaStructPointer(), attachmentCount };
    std::string pattachments_names = toStringJoin(pattachments_pair.begin(),
                                                  pattachments_pair.end(),
                                                  [&](auto pair) {{ return GenerateStruct_VkClearAttachment(stream_pattachments, pair.t1, pair.t2, *this); }},
                                                  ", ");
    if (stream_pattachments.str().length() > 0) {
        fprintf(file, "%s", stream_pattachments.str().c_str());
        if (attachmentCount == 1) {
            pattachments_array = "&" + pattachments_names;
        } else if (attachmentCount > 1) {
            pattachments_array = "pAttachments_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkClearAttachment %s[] = { %s };\n", pattachments_array.c_str(), pattachments_names.c_str());
        }
    }
    std::stringstream stream_prects;
    std::string prects_array = "NULL";
    PointerPairContainer<decltype(pRects->GetPointer()), decltype(pRects->GetMetaStructPointer())> prects_pair{ pRects->GetPointer(), pRects->GetMetaStructPointer(), rectCount };
    std::string prects_names = toStringJoin(prects_pair.begin(),
                                            prects_pair.end(),
                                            [&](auto pair) {{ return GenerateStruct_VkClearRect(stream_prects, pair.t1, pair.t2, *this); }},
                                            ", ");
    if (stream_prects.str().length() > 0) {
        fprintf(file, "%s", stream_prects.str().c_str());
        if (rectCount == 1) {
            prects_array = "&" + prects_names;
        } else if (rectCount > 1) {
            prects_array = "pRects_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkClearRect %s[] = { %s };\n", prects_array.c_str(), prects_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdClearAttachments(%s, %u, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            attachmentCount,
            pattachments_array.c_str(),
            rectCount,
            prects_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcolor;
    std::string pcolor_struct = GenerateStruct_VkClearColorValue(stream_pcolor,
                                                                 pColor->GetPointer(),
                                                                 pColor->GetMetaStructPointer(),
                                                                 *this);
    fprintf(file, "%s", stream_pcolor.str().c_str());
    std::stringstream stream_pranges;
    std::string pranges_array = "NULL";
    PointerPairContainer<decltype(pRanges->GetPointer()), decltype(pRanges->GetMetaStructPointer())> pranges_pair{ pRanges->GetPointer(), pRanges->GetMetaStructPointer(), rangeCount };
    std::string pranges_names = toStringJoin(pranges_pair.begin(),
                                             pranges_pair.end(),
                                             [&](auto pair) {{ return GenerateStruct_VkImageSubresourceRange(stream_pranges, pair.t1, pair.t2, *this); }},
                                             ", ");
    if (stream_pranges.str().length() > 0) {
        fprintf(file, "%s", stream_pranges.str().c_str());
        if (rangeCount == 1) {
            pranges_array = "&" + pranges_names;
        } else if (rangeCount > 1) {
            pranges_array = "pRanges_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkImageSubresourceRange %s[] = { %s };\n", pranges_array.c_str(), pranges_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdClearColorImage(%s, %s, %s, &%s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(image).c_str(),
            util::ToString<VkImageLayout>(imageLayout).c_str(),
            pcolor_struct.c_str(),
            rangeCount,
            pranges_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pdepth_stencil;
    std::string pdepth_stencil_struct = GenerateStruct_VkClearDepthStencilValue(stream_pdepth_stencil,
                                                                                pDepthStencil->GetPointer(),
                                                                                pDepthStencil->GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_pdepth_stencil.str().c_str());
    std::stringstream stream_pranges;
    std::string pranges_array = "NULL";
    PointerPairContainer<decltype(pRanges->GetPointer()), decltype(pRanges->GetMetaStructPointer())> pranges_pair{ pRanges->GetPointer(), pRanges->GetMetaStructPointer(), rangeCount };
    std::string pranges_names = toStringJoin(pranges_pair.begin(),
                                             pranges_pair.end(),
                                             [&](auto pair) {{ return GenerateStruct_VkImageSubresourceRange(stream_pranges, pair.t1, pair.t2, *this); }},
                                             ", ");
    if (stream_pranges.str().length() > 0) {
        fprintf(file, "%s", stream_pranges.str().c_str());
        if (rangeCount == 1) {
            pranges_array = "&" + pranges_names;
        } else if (rangeCount > 1) {
            pranges_array = "pRanges_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkImageSubresourceRange %s[] = { %s };\n", pranges_array.c_str(), pranges_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdClearDepthStencilImage(%s, %s, %s, &%s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(image).c_str(),
            util::ToString<VkImageLayout>(imageLayout).c_str(),
            pdepth_stencil_struct.c_str(),
            rangeCount,
            pranges_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pregions;
    std::string pregions_array = "NULL";
    PointerPairContainer<decltype(pRegions->GetPointer()), decltype(pRegions->GetMetaStructPointer())> pregions_pair{ pRegions->GetPointer(), pRegions->GetMetaStructPointer(), regionCount };
    std::string pregions_names = toStringJoin(pregions_pair.begin(),
                                              pregions_pair.end(),
                                              [&](auto pair) {{ return GenerateStruct_VkBufferCopy(stream_pregions, pair.t1, pair.t2, *this); }},
                                              ", ");
    if (stream_pregions.str().length() > 0) {
        fprintf(file, "%s", stream_pregions.str().c_str());
        if (regionCount == 1) {
            pregions_array = "&" + pregions_names;
        } else if (regionCount > 1) {
            pregions_array = "pRegions_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBufferCopy %s[] = { %s };\n", pregions_array.c_str(), pregions_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdCopyBuffer(%s, %s, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(srcBuffer).c_str(),
            this->GetHandle(dstBuffer).c_str(),
            regionCount,
            pregions_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pregions;
    std::string pregions_array = "NULL";
    PointerPairContainer<decltype(pRegions->GetPointer()), decltype(pRegions->GetMetaStructPointer())> pregions_pair{ pRegions->GetPointer(), pRegions->GetMetaStructPointer(), regionCount };
    std::string pregions_names = toStringJoin(pregions_pair.begin(),
                                              pregions_pair.end(),
                                              [&](auto pair) {{ return GenerateStruct_VkBufferImageCopy(stream_pregions, pair.t1, pair.t2, *this); }},
                                              ", ");
    if (stream_pregions.str().length() > 0) {
        fprintf(file, "%s", stream_pregions.str().c_str());
        if (regionCount == 1) {
            pregions_array = "&" + pregions_names;
        } else if (regionCount > 1) {
            pregions_array = "pRegions_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBufferImageCopy %s[] = { %s };\n", pregions_array.c_str(), pregions_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdCopyBufferToImage(%s, %s, %s, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(srcBuffer).c_str(),
            this->GetHandle(dstImage).c_str(),
            util::ToString<VkImageLayout>(dstImageLayout).c_str(),
            regionCount,
            pregions_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pregions;
    std::string pregions_array = "NULL";
    PointerPairContainer<decltype(pRegions->GetPointer()), decltype(pRegions->GetMetaStructPointer())> pregions_pair{ pRegions->GetPointer(), pRegions->GetMetaStructPointer(), regionCount };
    std::string pregions_names = toStringJoin(pregions_pair.begin(),
                                              pregions_pair.end(),
                                              [&](auto pair) {{ return GenerateStruct_VkImageCopy(stream_pregions, pair.t1, pair.t2, *this); }},
                                              ", ");
    if (stream_pregions.str().length() > 0) {
        fprintf(file, "%s", stream_pregions.str().c_str());
        if (regionCount == 1) {
            pregions_array = "&" + pregions_names;
        } else if (regionCount > 1) {
            pregions_array = "pRegions_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkImageCopy %s[] = { %s };\n", pregions_array.c_str(), pregions_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdCopyImage(%s, %s, %s, %s, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(srcImage).c_str(),
            util::ToString<VkImageLayout>(srcImageLayout).c_str(),
            this->GetHandle(dstImage).c_str(),
            util::ToString<VkImageLayout>(dstImageLayout).c_str(),
            regionCount,
            pregions_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pregions;
    std::string pregions_array = "NULL";
    PointerPairContainer<decltype(pRegions->GetPointer()), decltype(pRegions->GetMetaStructPointer())> pregions_pair{ pRegions->GetPointer(), pRegions->GetMetaStructPointer(), regionCount };
    std::string pregions_names = toStringJoin(pregions_pair.begin(),
                                              pregions_pair.end(),
                                              [&](auto pair) {{ return GenerateStruct_VkBufferImageCopy(stream_pregions, pair.t1, pair.t2, *this); }},
                                              ", ");
    if (stream_pregions.str().length() > 0) {
        fprintf(file, "%s", stream_pregions.str().c_str());
        if (regionCount == 1) {
            pregions_array = "&" + pregions_names;
        } else if (regionCount > 1) {
            pregions_array = "pRegions_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBufferImageCopy %s[] = { %s };\n", pregions_array.c_str(), pregions_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdCopyImageToBuffer(%s, %s, %s, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(srcImage).c_str(),
            util::ToString<VkImageLayout>(srcImageLayout).c_str(),
            this->GetHandle(dstBuffer).c_str(),
            regionCount,
            pregions_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdCopyQueryPoolResults(%s, %s, %u, %u, %s, %" PRIu64 "UL, %" PRIu64 "UL, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(queryPool).c_str(),
            firstQuery,
            queryCount,
            this->GetHandle(dstBuffer).c_str(),
            dstOffset,
            stride,
            util::ToString<VkQueryResultFlags>(flags).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdDispatch(%s, %u, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            groupCountX,
            groupCountY,
            groupCountZ);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDispatch);
}

void VulkanCppConsumer::Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdDispatchIndirect(%s, %s, %" PRIu64 "UL);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdDraw(%s, %u, %u, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            vertexCount,
            instanceCount,
            firstVertex,
            firstInstance);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdDrawIndexed(%s, %u, %u, %u, %d, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            indexCount,
            instanceCount,
            firstIndex,
            vertexOffset,
            firstInstance);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdDrawIndexedIndirect(%s, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            drawCount,
            stride);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdDrawIndirect(%s, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            drawCount,
            stride);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirect);
}

void VulkanCppConsumer::Process_vkCmdEndQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdEndQuery(%s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(queryPool).c_str(),
            query);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndQuery);
}

void VulkanCppConsumer::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdEndRenderPass(%s);\n",
            this->GetHandle(commandBuffer).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRenderPass);
}

void VulkanCppConsumer::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcommand_buffers_array = "NULL";
    std::string pcommand_buffers_values = toStringJoin(pCommandBuffers->GetPointer(),
                                                       pCommandBuffers->GetPointer() + commandBufferCount,
                                                       [&](const format::HandleId current) { return this->GetHandle(current); },
                                                       ", ");
    if (commandBufferCount == 1 && pcommand_buffers_values != "VK_NULL_HANDLE") {
        pcommand_buffers_array = "&" + pcommand_buffers_values;
    } else if (commandBufferCount > 1) {
        pcommand_buffers_array = "pcommand_buffers_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkCommandBuffer %s[] = { %s };\n", pcommand_buffers_array.c_str(), pcommand_buffers_values.c_str());
    }
    fprintf(file,
            "\t\tvkCmdExecuteCommands(%s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            commandBufferCount,
            pcommand_buffers_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdFillBuffer(%s, %s, %" PRIu64 "UL, %" PRIu64 "UL, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(dstBuffer).c_str(),
            dstOffset,
            size,
            data);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdFillBuffer);
}

void VulkanCppConsumer::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSubpassContents                           contents)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdNextSubpass(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkSubpassContents>(contents).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pmemory_barriers;
    std::string pmemory_barriers_array = "NULL";
    PointerPairContainer<decltype(pMemoryBarriers->GetPointer()), decltype(pMemoryBarriers->GetMetaStructPointer())> pmemory_barriers_pair{ pMemoryBarriers->GetPointer(), pMemoryBarriers->GetMetaStructPointer(), memoryBarrierCount };
    std::string pmemory_barriers_names = toStringJoin(pmemory_barriers_pair.begin(),
                                                      pmemory_barriers_pair.end(),
                                                      [&](auto pair) {{ return GenerateStruct_VkMemoryBarrier(stream_pmemory_barriers, pair.t1, pair.t2, *this); }},
                                                      ", ");
    if (stream_pmemory_barriers.str().length() > 0) {
        fprintf(file, "%s", stream_pmemory_barriers.str().c_str());
        if (memoryBarrierCount == 1) {
            pmemory_barriers_array = "&" + pmemory_barriers_names;
        } else if (memoryBarrierCount > 1) {
            pmemory_barriers_array = "pMemoryBarriers_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkMemoryBarrier %s[] = { %s };\n", pmemory_barriers_array.c_str(), pmemory_barriers_names.c_str());
        }
    }
    std::stringstream stream_pbuffer_memory_barriers;
    std::string pbuffer_memory_barriers_array = "NULL";
    PointerPairContainer<decltype(pBufferMemoryBarriers->GetPointer()), decltype(pBufferMemoryBarriers->GetMetaStructPointer())> pbuffer_memory_barriers_pair{ pBufferMemoryBarriers->GetPointer(), pBufferMemoryBarriers->GetMetaStructPointer(), bufferMemoryBarrierCount };
    std::string pbuffer_memory_barriers_names = toStringJoin(pbuffer_memory_barriers_pair.begin(),
                                                             pbuffer_memory_barriers_pair.end(),
                                                             [&](auto pair) {{ return GenerateStruct_VkBufferMemoryBarrier(stream_pbuffer_memory_barriers, pair.t1, pair.t2, *this); }},
                                                             ", ");
    if (stream_pbuffer_memory_barriers.str().length() > 0) {
        fprintf(file, "%s", stream_pbuffer_memory_barriers.str().c_str());
        if (bufferMemoryBarrierCount == 1) {
            pbuffer_memory_barriers_array = "&" + pbuffer_memory_barriers_names;
        } else if (bufferMemoryBarrierCount > 1) {
            pbuffer_memory_barriers_array = "pBufferMemoryBarriers_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBufferMemoryBarrier %s[] = { %s };\n", pbuffer_memory_barriers_array.c_str(), pbuffer_memory_barriers_names.c_str());
        }
    }
    std::stringstream stream_pimage_memory_barriers;
    std::string pimage_memory_barriers_array = "NULL";
    PointerPairContainer<decltype(pImageMemoryBarriers->GetPointer()), decltype(pImageMemoryBarriers->GetMetaStructPointer())> pimage_memory_barriers_pair{ pImageMemoryBarriers->GetPointer(), pImageMemoryBarriers->GetMetaStructPointer(), imageMemoryBarrierCount };
    std::string pimage_memory_barriers_names = toStringJoin(pimage_memory_barriers_pair.begin(),
                                                            pimage_memory_barriers_pair.end(),
                                                            [&](auto pair) {{ return GenerateStruct_VkImageMemoryBarrier(stream_pimage_memory_barriers, pair.t1, pair.t2, *this); }},
                                                            ", ");
    if (stream_pimage_memory_barriers.str().length() > 0) {
        fprintf(file, "%s", stream_pimage_memory_barriers.str().c_str());
        if (imageMemoryBarrierCount == 1) {
            pimage_memory_barriers_array = "&" + pimage_memory_barriers_names;
        } else if (imageMemoryBarrierCount > 1) {
            pimage_memory_barriers_array = "pImageMemoryBarriers_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkImageMemoryBarrier %s[] = { %s };\n", pimage_memory_barriers_array.c_str(), pimage_memory_barriers_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdPipelineBarrier(%s, %s, %s, %s, %u, %s, %u, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineStageFlags>(srcStageMask).c_str(),
            util::ToString<VkPipelineStageFlags>(dstStageMask).c_str(),
            util::ToString<VkDependencyFlags>(dependencyFlags).c_str(),
            memoryBarrierCount,
            pmemory_barriers_array.c_str(),
            bufferMemoryBarrierCount,
            pbuffer_memory_barriers_array.c_str(),
            imageMemoryBarrierCount,
            pimage_memory_barriers_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pvalues_array = "pValues_" + std::to_string(this->GetNextId());
    if (size > 0) {
        std::string pvalues_values = toStringJoin(pValues->GetPointer(),
                                                  pValues->GetPointer() + size,
                                                  [&](const auto current) { return std::to_string(current) + ""; },
                                                  ", ");
        fprintf(file, "\t\tuint8_t %s[] = { %s };\n", pvalues_array.c_str(), pvalues_values.c_str());
    } else {
        pvalues_array = "NULL";
    }
    fprintf(file,
            "\t\tvkCmdPushConstants(%s, %s, %s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(layout).c_str(),
            util::ToString<VkShaderStageFlags>(stageFlags).c_str(),
            offset,
            size,
            pvalues_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPushConstants);
}

void VulkanCppConsumer::Process_vkCmdResetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdResetEvent(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(event).c_str(),
            util::ToString<VkPipelineStageFlags>(stageMask).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdResetQueryPool(%s, %s, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(queryPool).c_str(),
            firstQuery,
            queryCount);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pregions;
    std::string pregions_array = "NULL";
    PointerPairContainer<decltype(pRegions->GetPointer()), decltype(pRegions->GetMetaStructPointer())> pregions_pair{ pRegions->GetPointer(), pRegions->GetMetaStructPointer(), regionCount };
    std::string pregions_names = toStringJoin(pregions_pair.begin(),
                                              pregions_pair.end(),
                                              [&](auto pair) {{ return GenerateStruct_VkImageResolve(stream_pregions, pair.t1, pair.t2, *this); }},
                                              ", ");
    if (stream_pregions.str().length() > 0) {
        fprintf(file, "%s", stream_pregions.str().c_str());
        if (regionCount == 1) {
            pregions_array = "&" + pregions_names;
        } else if (regionCount > 1) {
            pregions_array = "pRegions_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkImageResolve %s[] = { %s };\n", pregions_array.c_str(), pregions_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdResolveImage(%s, %s, %s, %s, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(srcImage).c_str(),
            util::ToString<VkImageLayout>(srcImageLayout).c_str(),
            this->GetHandle(dstImage).c_str(),
            util::ToString<VkImageLayout>(dstImageLayout).c_str(),
            regionCount,
            pregions_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResolveImage);
}

void VulkanCppConsumer::Process_vkCmdSetBlendConstants(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    PointerDecoder<float>*                      blendConstants)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string blend_constants_array = "blendConstants_" + std::to_string(this->GetNextId());
    if (4 > 0) {
        std::string blend_constants_values = toStringJoin(blendConstants->GetPointer(),
                                                          blendConstants->GetPointer() + 4,
                                                          [&](const auto current) { return std::to_string(current) + ""; },
                                                          ", ");
        fprintf(file, "\t\tfloat %s[] = { %s };\n", blend_constants_array.c_str(), blend_constants_values.c_str());
    } else {
        blend_constants_array = "NULL";
    }
    fprintf(file,
            "\t\tvkCmdSetBlendConstants(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            blend_constants_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetDepthBias(%s, %f, %f, %f);\n",
            this->GetHandle(commandBuffer).c_str(),
            depthBiasConstantFactor,
            depthBiasClamp,
            depthBiasSlopeFactor);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBias);
}

void VulkanCppConsumer::Process_vkCmdSetDepthBounds(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetDepthBounds(%s, %f, %f);\n",
            this->GetHandle(commandBuffer).c_str(),
            minDepthBounds,
            maxDepthBounds);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBounds);
}

void VulkanCppConsumer::Process_vkCmdSetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetEvent(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(event).c_str(),
            util::ToString<VkPipelineStageFlags>(stageMask).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetEvent);
}

void VulkanCppConsumer::Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       lineWidth)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetLineWidth(%s, %f);\n",
            this->GetHandle(commandBuffer).c_str(),
            lineWidth);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pscissors;
    std::string pscissors_array = "NULL";
    PointerPairContainer<decltype(pScissors->GetPointer()), decltype(pScissors->GetMetaStructPointer())> pscissors_pair{ pScissors->GetPointer(), pScissors->GetMetaStructPointer(), scissorCount };
    std::string pscissors_names = toStringJoin(pscissors_pair.begin(),
                                               pscissors_pair.end(),
                                               [&](auto pair) {{ return GenerateStruct_VkRect2D(stream_pscissors, pair.t1, pair.t2, *this); }},
                                               ", ");
    if (stream_pscissors.str().length() > 0) {
        fprintf(file, "%s", stream_pscissors.str().c_str());
        if (scissorCount == 1) {
            pscissors_array = "&" + pscissors_names;
        } else if (scissorCount > 1) {
            pscissors_array = "pScissors_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkRect2D %s[] = { %s };\n", pscissors_array.c_str(), pscissors_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdSetScissor(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstScissor,
            scissorCount,
            pscissors_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetScissor);
}

void VulkanCppConsumer::Process_vkCmdSetStencilCompareMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetStencilCompareMask(%s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkStencilFaceFlags>(faceMask).c_str(),
            compareMask);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask);
}

void VulkanCppConsumer::Process_vkCmdSetStencilReference(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetStencilReference(%s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkStencilFaceFlags>(faceMask).c_str(),
            reference);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilReference);
}

void VulkanCppConsumer::Process_vkCmdSetStencilWriteMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetStencilWriteMask(%s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkStencilFaceFlags>(faceMask).c_str(),
            writeMask);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pviewports;
    std::string pviewports_array = "NULL";
    PointerPairContainer<decltype(pViewports->GetPointer()), decltype(pViewports->GetMetaStructPointer())> pviewports_pair{ pViewports->GetPointer(), pViewports->GetMetaStructPointer(), viewportCount };
    std::string pviewports_names = toStringJoin(pviewports_pair.begin(),
                                                pviewports_pair.end(),
                                                [&](auto pair) {{ return GenerateStruct_VkViewport(stream_pviewports, pair.t1, pair.t2, *this); }},
                                                ", ");
    if (stream_pviewports.str().length() > 0) {
        fprintf(file, "%s", stream_pviewports.str().c_str());
        if (viewportCount == 1) {
            pviewports_array = "&" + pviewports_names;
        } else if (viewportCount > 1) {
            pviewports_array = "pViewports_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkViewport %s[] = { %s };\n", pviewports_array.c_str(), pviewports_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdSetViewport(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstViewport,
            viewportCount,
            pviewports_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pdata_array = "pData_" + std::to_string(this->GetNextId());
    if (dataSize > 0) {
        std::string pdata_values = toStringJoin(pData->GetPointer(),
                                                pData->GetPointer() + dataSize,
                                                [&](const auto current) { return std::to_string(current) + ""; },
                                                ", ");
        fprintf(file, "\t\tuint8_t %s[] = { %s };\n", pdata_array.c_str(), pdata_values.c_str());
    } else {
        pdata_array = "NULL";
    }
    fprintf(file,
            "\t\tvkCmdUpdateBuffer(%s, %s, %" PRIu64 "UL, %" PRIu64 "UL, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(dstBuffer).c_str(),
            dstOffset,
            dataSize,
            pdata_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pevents_array = "NULL";
    std::string pevents_values = toStringJoin(pEvents->GetPointer(),
                                              pEvents->GetPointer() + eventCount,
                                              [&](const format::HandleId current) { return this->GetHandle(current); },
                                              ", ");
    if (eventCount == 1 && pevents_values != "VK_NULL_HANDLE") {
        pevents_array = "&" + pevents_values;
    } else if (eventCount > 1) {
        pevents_array = "pevents_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkEvent %s[] = { %s };\n", pevents_array.c_str(), pevents_values.c_str());
    }
    std::stringstream stream_pmemory_barriers;
    std::string pmemory_barriers_array = "NULL";
    PointerPairContainer<decltype(pMemoryBarriers->GetPointer()), decltype(pMemoryBarriers->GetMetaStructPointer())> pmemory_barriers_pair{ pMemoryBarriers->GetPointer(), pMemoryBarriers->GetMetaStructPointer(), memoryBarrierCount };
    std::string pmemory_barriers_names = toStringJoin(pmemory_barriers_pair.begin(),
                                                      pmemory_barriers_pair.end(),
                                                      [&](auto pair) {{ return GenerateStruct_VkMemoryBarrier(stream_pmemory_barriers, pair.t1, pair.t2, *this); }},
                                                      ", ");
    if (stream_pmemory_barriers.str().length() > 0) {
        fprintf(file, "%s", stream_pmemory_barriers.str().c_str());
        if (memoryBarrierCount == 1) {
            pmemory_barriers_array = "&" + pmemory_barriers_names;
        } else if (memoryBarrierCount > 1) {
            pmemory_barriers_array = "pMemoryBarriers_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkMemoryBarrier %s[] = { %s };\n", pmemory_barriers_array.c_str(), pmemory_barriers_names.c_str());
        }
    }
    std::stringstream stream_pbuffer_memory_barriers;
    std::string pbuffer_memory_barriers_array = "NULL";
    PointerPairContainer<decltype(pBufferMemoryBarriers->GetPointer()), decltype(pBufferMemoryBarriers->GetMetaStructPointer())> pbuffer_memory_barriers_pair{ pBufferMemoryBarriers->GetPointer(), pBufferMemoryBarriers->GetMetaStructPointer(), bufferMemoryBarrierCount };
    std::string pbuffer_memory_barriers_names = toStringJoin(pbuffer_memory_barriers_pair.begin(),
                                                             pbuffer_memory_barriers_pair.end(),
                                                             [&](auto pair) {{ return GenerateStruct_VkBufferMemoryBarrier(stream_pbuffer_memory_barriers, pair.t1, pair.t2, *this); }},
                                                             ", ");
    if (stream_pbuffer_memory_barriers.str().length() > 0) {
        fprintf(file, "%s", stream_pbuffer_memory_barriers.str().c_str());
        if (bufferMemoryBarrierCount == 1) {
            pbuffer_memory_barriers_array = "&" + pbuffer_memory_barriers_names;
        } else if (bufferMemoryBarrierCount > 1) {
            pbuffer_memory_barriers_array = "pBufferMemoryBarriers_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBufferMemoryBarrier %s[] = { %s };\n", pbuffer_memory_barriers_array.c_str(), pbuffer_memory_barriers_names.c_str());
        }
    }
    std::stringstream stream_pimage_memory_barriers;
    std::string pimage_memory_barriers_array = "NULL";
    PointerPairContainer<decltype(pImageMemoryBarriers->GetPointer()), decltype(pImageMemoryBarriers->GetMetaStructPointer())> pimage_memory_barriers_pair{ pImageMemoryBarriers->GetPointer(), pImageMemoryBarriers->GetMetaStructPointer(), imageMemoryBarrierCount };
    std::string pimage_memory_barriers_names = toStringJoin(pimage_memory_barriers_pair.begin(),
                                                            pimage_memory_barriers_pair.end(),
                                                            [&](auto pair) {{ return GenerateStruct_VkImageMemoryBarrier(stream_pimage_memory_barriers, pair.t1, pair.t2, *this); }},
                                                            ", ");
    if (stream_pimage_memory_barriers.str().length() > 0) {
        fprintf(file, "%s", stream_pimage_memory_barriers.str().c_str());
        if (imageMemoryBarrierCount == 1) {
            pimage_memory_barriers_array = "&" + pimage_memory_barriers_names;
        } else if (imageMemoryBarrierCount > 1) {
            pimage_memory_barriers_array = "pImageMemoryBarriers_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkImageMemoryBarrier %s[] = { %s };\n", pimage_memory_barriers_array.c_str(), pimage_memory_barriers_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdWaitEvents(%s, %u, %s, %s, %s, %u, %s, %u, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            eventCount,
            pevents_array.c_str(),
            util::ToString<VkPipelineStageFlags>(srcStageMask).c_str(),
            util::ToString<VkPipelineStageFlags>(dstStageMask).c_str(),
            memoryBarrierCount,
            pmemory_barriers_array.c_str(),
            bufferMemoryBarrierCount,
            pbuffer_memory_barriers_array.c_str(),
            imageMemoryBarrierCount,
            pimage_memory_barriers_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdWriteTimestamp(%s, %s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineStageFlagBits>(pipelineStage).c_str(),
            this->GetHandle(queryPool).c_str(),
            query);
    fprintf(file, "\t}\n");
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
    Generate_vkCreateBuffer(returnValue, device, pCreateInfo, pAllocator, pBuffer);
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkBufferViewCreateInfo(stream_pcreate_info,
                                                                            pCreateInfo->GetPointer(),
                                                                            pCreateInfo->GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pview_name = "pView_" + std::to_string(this->GetNextId());
    AddKnownVariables("VkBufferView", pview_name, pView->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pview_name,
                         pView->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateBufferView(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pview_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkCommandPoolCreateInfo(stream_pcreate_info,
                                                                             pCreateInfo->GetPointer(),
                                                                             pCreateInfo->GetMetaStructPointer(),
                                                                             *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pcommand_pool_name = "pCommandPool_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_COMMAND_POOL));
    AddKnownVariables("VkCommandPool", pcommand_pool_name, pCommandPool->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pcommand_pool_name,
                         pCommandPool->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateCommandPool(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pcommand_pool_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    Generate_vkCreateComputePipelines(returnValue, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkDescriptorPoolCreateInfo(stream_pcreate_info,
                                                                                pCreateInfo->GetPointer(),
                                                                                pCreateInfo->GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pdescriptor_pool_name = "pDescriptorPool_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DESCRIPTOR_POOL));
    AddKnownVariables("VkDescriptorPool", pdescriptor_pool_name, pDescriptorPool->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pdescriptor_pool_name,
                         pDescriptorPool->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateDescriptorPool(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pdescriptor_pool_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkDescriptorSetLayoutCreateInfo(stream_pcreate_info,
                                                                                     pCreateInfo->GetPointer(),
                                                                                     pCreateInfo->GetMetaStructPointer(),
                                                                                     *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pset_layout_name = "pSetLayout_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT));
    AddKnownVariables("VkDescriptorSetLayout", pset_layout_name, pSetLayout->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pset_layout_name,
                         pSetLayout->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateDescriptorSetLayout(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pset_layout_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    Generate_vkCreateDevice(returnValue, physicalDevice, pCreateInfo, pAllocator, pDevice);
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkEventCreateInfo(stream_pcreate_info,
                                                                       pCreateInfo->GetPointer(),
                                                                       pCreateInfo->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pevent_name = "pEvent_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_EVENT));
    AddKnownVariables("VkEvent", pevent_name, pEvent->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pevent_name,
                         pEvent->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateEvent(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pevent_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkFenceCreateInfo(stream_pcreate_info,
                                                                       pCreateInfo->GetPointer(),
                                                                       pCreateInfo->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pfence_name = "pFence_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_FENCE));
    AddKnownVariables("VkFence", pfence_name, pFence->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pfence_name,
                         pFence->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateFence(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pfence_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkFramebufferCreateInfo(stream_pcreate_info,
                                                                             pCreateInfo->GetPointer(),
                                                                             pCreateInfo->GetMetaStructPointer(),
                                                                             *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pframebuffer_name = "pFramebuffer_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_FRAMEBUFFER));
    AddKnownVariables("VkFramebuffer", pframebuffer_name, pFramebuffer->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pframebuffer_name,
                         pFramebuffer->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateFramebuffer(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pframebuffer_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    Generate_vkCreateGraphicsPipelines(returnValue, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkImageCreateInfo(stream_pcreate_info,
                                                                       pCreateInfo->GetPointer(),
                                                                       pCreateInfo->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pimage_name = "pImage_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_IMAGE));
    AddKnownVariables("VkImage", pimage_name, pImage->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pimage_name,
                         pImage->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateImage(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pimage_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkImageViewCreateInfo(stream_pcreate_info,
                                                                           pCreateInfo->GetPointer(),
                                                                           pCreateInfo->GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pview_name = "pView_" + std::to_string(this->GetNextId());
    AddKnownVariables("VkImageView", pview_name, pView->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pview_name,
                         pView->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateImageView(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pview_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkPipelineLayoutCreateInfo(stream_pcreate_info,
                                                                                pCreateInfo->GetPointer(),
                                                                                pCreateInfo->GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string ppipeline_layout_name = "pPipelineLayout_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_PIPELINE_LAYOUT));
    AddKnownVariables("VkPipelineLayout", ppipeline_layout_name, pPipelineLayout->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(ppipeline_layout_name,
                         pPipelineLayout->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreatePipelineLayout(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            ppipeline_layout_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkQueryPoolCreateInfo(stream_pcreate_info,
                                                                           pCreateInfo->GetPointer(),
                                                                           pCreateInfo->GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pquery_pool_name = "pQueryPool_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_QUERY_POOL));
    AddKnownVariables("VkQueryPool", pquery_pool_name, pQueryPool->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pquery_pool_name,
                         pQueryPool->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateQueryPool(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pquery_pool_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkRenderPassCreateInfo(stream_pcreate_info,
                                                                            pCreateInfo->GetPointer(),
                                                                            pCreateInfo->GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string prender_pass_name = "pRenderPass_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_RENDER_PASS));
    AddKnownVariables("VkRenderPass", prender_pass_name, pRenderPass->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(prender_pass_name,
                         pRenderPass->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateRenderPass(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            prender_pass_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkSamplerCreateInfo(stream_pcreate_info,
                                                                         pCreateInfo->GetPointer(),
                                                                         pCreateInfo->GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psampler_name = "pSampler_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SAMPLER));
    AddKnownVariables("VkSampler", psampler_name, pSampler->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(psampler_name,
                         pSampler->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateSampler(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psampler_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkSemaphoreCreateInfo(stream_pcreate_info,
                                                                           pCreateInfo->GetPointer(),
                                                                           pCreateInfo->GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psemaphore_name = "pSemaphore_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SEMAPHORE));
    AddKnownVariables("VkSemaphore", psemaphore_name, pSemaphore->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(psemaphore_name,
                         pSemaphore->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateSemaphore(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psemaphore_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyBuffer(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(buffer).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyBuffer);
}

void VulkanCppConsumer::Process_vkDestroyBufferView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            bufferView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyBufferView(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(bufferView).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyBufferView);
}

void VulkanCppConsumer::Process_vkDestroyCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyCommandPool(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(commandPool).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyCommandPool);
}

void VulkanCppConsumer::Process_vkDestroyDescriptorPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyDescriptorPool(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(descriptorPool).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDescriptorPool);
}

void VulkanCppConsumer::Process_vkDestroyDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSetLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyDescriptorSetLayout(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(descriptorSetLayout).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout);
}

void VulkanCppConsumer::Process_vkDestroyDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    Generate_vkDestroyDevice(device, pAllocator);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDevice);
}

void VulkanCppConsumer::Process_vkDestroyEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyEvent(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(event).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyEvent);
}

void VulkanCppConsumer::Process_vkDestroyFence(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            fence,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyFence(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(fence).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyFence);
}

void VulkanCppConsumer::Process_vkDestroyFramebuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyFramebuffer(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(framebuffer).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyFramebuffer);
}

void VulkanCppConsumer::Process_vkDestroyImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyImage(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(image).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyImage);
}

void VulkanCppConsumer::Process_vkDestroyImageView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyImageView(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(imageView).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyImageView);
}

void VulkanCppConsumer::Process_vkDestroyInstance(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyInstance(%s, %s);\n",
            this->GetHandle(instance).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyInstance);
}

void VulkanCppConsumer::Process_vkDestroyPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyPipeline(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipeline).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPipeline);
}

void VulkanCppConsumer::Process_vkDestroyPipelineCache(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyPipelineCache(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipelineCache).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPipelineCache);
}

void VulkanCppConsumer::Process_vkDestroyPipelineLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyPipelineLayout(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipelineLayout).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPipelineLayout);
}

void VulkanCppConsumer::Process_vkDestroyQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyQueryPool(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(queryPool).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyQueryPool);
}

void VulkanCppConsumer::Process_vkDestroyRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyRenderPass(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(renderPass).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyRenderPass);
}

void VulkanCppConsumer::Process_vkDestroySampler(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            sampler,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroySampler(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(sampler).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySampler);
}

void VulkanCppConsumer::Process_vkDestroySemaphore(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    Intercept_vkDestroySemaphore(device, semaphore, pAllocator);
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroySemaphore(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(semaphore).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySemaphore);
}

void VulkanCppConsumer::Process_vkDestroyShaderModule(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyShaderModule(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(shaderModule).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyShaderModule);
}

void VulkanCppConsumer::Process_vkDeviceWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkDeviceWaitIdle(%s), %s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDeviceWaitIdle);
}

void VulkanCppConsumer::Process_vkEndCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkEndCommandBuffer(%s), %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pmemory_ranges;
    std::string pmemory_ranges_array = "NULL";
    PointerPairContainer<decltype(pMemoryRanges->GetPointer()), decltype(pMemoryRanges->GetMetaStructPointer())> pmemory_ranges_pair{ pMemoryRanges->GetPointer(), pMemoryRanges->GetMetaStructPointer(), memoryRangeCount };
    std::string pmemory_ranges_names = toStringJoin(pmemory_ranges_pair.begin(),
                                                    pmemory_ranges_pair.end(),
                                                    [&](auto pair) {{ return GenerateStruct_VkMappedMemoryRange(stream_pmemory_ranges, pair.t1, pair.t2, *this); }},
                                                    ", ");
    if (stream_pmemory_ranges.str().length() > 0) {
        fprintf(file, "%s", stream_pmemory_ranges.str().c_str());
        if (memoryRangeCount == 1) {
            pmemory_ranges_array = "&" + pmemory_ranges_names;
        } else if (memoryRangeCount > 1) {
            pmemory_ranges_array = "pMemoryRanges_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkMappedMemoryRange %s[] = { %s };\n", pmemory_ranges_array.c_str(), pmemory_ranges_names.c_str());
        }
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkFlushMappedMemoryRanges(%s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            memoryRangeCount,
            pmemory_ranges_array.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pcommand_buffers_array = "NULL";
    std::string pcommand_buffers_values = toStringJoin(pCommandBuffers->GetPointer(),
                                                       pCommandBuffers->GetPointer() + commandBufferCount,
                                                       [&](const format::HandleId current) { return this->GetHandle(current); },
                                                       ", ");
    if (commandBufferCount == 1 && pcommand_buffers_values != "VK_NULL_HANDLE") {
        pcommand_buffers_array = "&" + pcommand_buffers_values;
    } else if (commandBufferCount > 1) {
        pcommand_buffers_array = "pcommand_buffers_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkCommandBuffer %s[] = { %s };\n", pcommand_buffers_array.c_str(), pcommand_buffers_values.c_str());
    }
    fprintf(file,
            "\t\tvkFreeCommandBuffers(%s, %s, %u, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(commandPool).c_str(),
            commandBufferCount,
            pcommand_buffers_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pdescriptor_sets_array = "NULL";
    std::string pdescriptor_sets_values = toStringJoin(pDescriptorSets->GetPointer(),
                                                       pDescriptorSets->GetPointer() + descriptorSetCount,
                                                       [&](const format::HandleId current) { return this->GetHandle(current); },
                                                       ", ");
    if (descriptorSetCount == 1 && pdescriptor_sets_values != "VK_NULL_HANDLE") {
        pdescriptor_sets_array = "&" + pdescriptor_sets_values;
    } else if (descriptorSetCount > 1) {
        pdescriptor_sets_array = "pdescriptor_sets_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDescriptorSet %s[] = { %s };\n", pdescriptor_sets_array.c_str(), pdescriptor_sets_values.c_str());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkFreeDescriptorSets(%s, %s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(descriptorPool).c_str(),
            descriptorSetCount,
            pdescriptor_sets_array.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkFreeDescriptorSets);
}

void VulkanCppConsumer::Process_vkFreeMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkFreeMemory(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(memory).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pcommitted_memory_in_bytes_name = "pCommittedMemoryInBytes_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tVkDeviceSize %s;\n", pcommitted_memory_in_bytes_name.c_str());
    fprintf(file,
            "\t\tvkGetDeviceMemoryCommitment(%s, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(memory).c_str(),
            pcommitted_memory_in_bytes_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment);
}

void VulkanCppConsumer::Process_vkGetDeviceQueue(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    Generate_vkGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceQueue);
}

void VulkanCppConsumer::Process_vkGetEventStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkGetEventStatus(%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(event).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_psubresource;
    std::string psubresource_struct = GenerateStruct_VkImageSubresource(stream_psubresource,
                                                                        pSubresource->GetPointer(),
                                                                        pSubresource->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_psubresource.str().c_str());
    std::string playout_name = "pLayout_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tVkSubresourceLayout %s;\n", playout_name.c_str());
    fprintf(file,
            "\t\tvkGetImageSubresourceLayout(%s, %s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(image).c_str(),
            psubresource_struct.c_str(),
            playout_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSubresourceLayout);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pfeatures_name = "pFeatures_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tVkPhysicalDeviceFeatures %s;\n", pfeatures_name.c_str());
    fprintf(file,
            "\t\tvkGetPhysicalDeviceFeatures(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pfeatures_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceFormatProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pformat_properties_name = "pFormatProperties_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tVkFormatProperties %s;\n", pformat_properties_name.c_str());
    fprintf(file,
            "\t\tvkGetPhysicalDeviceFormatProperties(%s, %s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            util::ToString<VkFormat>(format).c_str(),
            pformat_properties_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pimage_format_properties_name = "pImageFormatProperties_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tVkImageFormatProperties %s;\n", pimage_format_properties_name.c_str());
    fprintf(file,
            "\t\tvkGetPhysicalDeviceImageFormatProperties(%s, %s, %s, %s, %s, %s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            util::ToString<VkFormat>(format).c_str(),
            util::ToString<VkImageType>(type).c_str(),
            util::ToString<VkImageTiling>(tiling).c_str(),
            util::ToString<VkImageUsageFlags>(usage).c_str(),
            util::ToString<VkImageCreateFlags>(flags).c_str(),
            pimage_format_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pmemory_properties_name = "pMemoryProperties_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tVkPhysicalDeviceMemoryProperties %s;\n", pmemory_properties_name.c_str());
    fprintf(file,
            "\t\tvkGetPhysicalDeviceMemoryProperties(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pmemory_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tVkPhysicalDeviceProperties %s;\n", pproperties_name.c_str());
    fprintf(file,
            "\t\tvkGetPhysicalDeviceProperties(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pproperties_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pproperty_count_name.c_str());
    std::string pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
    const uint32_t* in_pproperty_count = pPropertyCount->GetPointer();
    fprintf(file, "\t\tVkSparseImageFormatProperties %s[%d];\n", pproperties_name.c_str(), *in_pproperty_count);
    fprintf(file,
            "\t\tvkGetPhysicalDeviceSparseImageFormatProperties(%s, %s, %s, %s, %s, %s, &%s, %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            util::ToString<VkFormat>(format).c_str(),
            util::ToString<VkImageType>(type).c_str(),
            util::ToString<VkSampleCountFlagBits>(samples).c_str(),
            util::ToString<VkImageUsageFlags>(usage).c_str(),
            util::ToString<VkImageTiling>(tiling).c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file, "// TODO: Support vkGetPipelineCacheData function.\n");
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pgranularity_name = "pGranularity_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tVkExtent2D %s;\n", pgranularity_name.c_str());
    fprintf(file,
            "\t\tvkGetRenderAreaGranularity(%s, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(renderPass).c_str(),
            pgranularity_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pmemory_ranges;
    std::string pmemory_ranges_array = "NULL";
    PointerPairContainer<decltype(pMemoryRanges->GetPointer()), decltype(pMemoryRanges->GetMetaStructPointer())> pmemory_ranges_pair{ pMemoryRanges->GetPointer(), pMemoryRanges->GetMetaStructPointer(), memoryRangeCount };
    std::string pmemory_ranges_names = toStringJoin(pmemory_ranges_pair.begin(),
                                                    pmemory_ranges_pair.end(),
                                                    [&](auto pair) {{ return GenerateStruct_VkMappedMemoryRange(stream_pmemory_ranges, pair.t1, pair.t2, *this); }},
                                                    ", ");
    if (stream_pmemory_ranges.str().length() > 0) {
        fprintf(file, "%s", stream_pmemory_ranges.str().c_str());
        if (memoryRangeCount == 1) {
            pmemory_ranges_array = "&" + pmemory_ranges_names;
        } else if (memoryRangeCount > 1) {
            pmemory_ranges_array = "pMemoryRanges_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkMappedMemoryRange %s[] = { %s };\n", pmemory_ranges_array.c_str(), pmemory_ranges_names.c_str());
        }
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkInvalidateMappedMemoryRanges(%s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            memoryRangeCount,
            pmemory_ranges_array.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string psrc_caches_array = "NULL";
    std::string psrc_caches_values = toStringJoin(pSrcCaches->GetPointer(),
                                                  pSrcCaches->GetPointer() + srcCacheCount,
                                                  [&](const format::HandleId current) { return this->GetHandle(current); },
                                                  ", ");
    if (srcCacheCount == 1 && psrc_caches_values != "VK_NULL_HANDLE") {
        psrc_caches_array = "&" + psrc_caches_values;
    } else if (srcCacheCount > 1) {
        psrc_caches_array = "psrc_caches_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPipelineCache %s[] = { %s };\n", psrc_caches_array.c_str(), psrc_caches_values.c_str());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkMergePipelineCaches(%s, %s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(dstCache).c_str(),
            srcCacheCount,
            psrc_caches_array.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    Generate_vkQueueBindSparse(returnValue, queue, bindInfoCount, pBindInfo, fence);
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
    Generate_vkQueueSubmit(returnValue, queue, submitCount, pSubmits, fence);
    Post_APICall(format::ApiCallId::ApiCall_vkQueueSubmit);
}

void VulkanCppConsumer::Process_vkQueueWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkQueueWaitIdle(%s), %s);\n",
            this->GetHandle(queue).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkQueueWaitIdle);
}

void VulkanCppConsumer::Process_vkResetCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkResetCommandBuffer(%s, %s), %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkCommandBufferResetFlags>(flags).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkResetCommandPool(%s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(commandPool).c_str(),
            util::ToString<VkCommandPoolResetFlags>(flags).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkResetDescriptorPool(%s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(descriptorPool).c_str(),
            util::ToString<VkDescriptorPoolResetFlags>(flags).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkResetDescriptorPool);
}

void VulkanCppConsumer::Process_vkResetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkResetEvent(%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(event).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pfences_array = "NULL";
    std::string pfences_values = toStringJoin(pFences->GetPointer(),
                                              pFences->GetPointer() + fenceCount,
                                              [&](const format::HandleId current) { return this->GetHandle(current); },
                                              ", ");
    if (fenceCount == 1 && pfences_values != "VK_NULL_HANDLE") {
        pfences_array = "&" + pfences_values;
    } else if (fenceCount > 1) {
        pfences_array = "pfences_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkFence %s[] = { %s };\n", pfences_array.c_str(), pfences_values.c_str());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkResetFences(%s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            fenceCount,
            pfences_array.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkResetFences);
}

void VulkanCppConsumer::Process_vkSetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkSetEvent(%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(event).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pdescriptor_writes;
    std::string pdescriptor_writes_array = "NULL";
    PointerPairContainer<decltype(pDescriptorWrites->GetPointer()), decltype(pDescriptorWrites->GetMetaStructPointer())> pdescriptor_writes_pair{ pDescriptorWrites->GetPointer(), pDescriptorWrites->GetMetaStructPointer(), descriptorWriteCount };
    std::string pdescriptor_writes_names = toStringJoin(pdescriptor_writes_pair.begin(),
                                                        pdescriptor_writes_pair.end(),
                                                        [&](auto pair) {{ return GenerateStruct_VkWriteDescriptorSet(stream_pdescriptor_writes, pair.t1, pair.t2, *this); }},
                                                        ", ");
    if (stream_pdescriptor_writes.str().length() > 0) {
        fprintf(file, "%s", stream_pdescriptor_writes.str().c_str());
        if (descriptorWriteCount == 1) {
            pdescriptor_writes_array = "&" + pdescriptor_writes_names;
        } else if (descriptorWriteCount > 1) {
            pdescriptor_writes_array = "pDescriptorWrites_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkWriteDescriptorSet %s[] = { %s };\n", pdescriptor_writes_array.c_str(), pdescriptor_writes_names.c_str());
        }
    }
    std::stringstream stream_pdescriptor_copies;
    std::string pdescriptor_copies_array = "NULL";
    PointerPairContainer<decltype(pDescriptorCopies->GetPointer()), decltype(pDescriptorCopies->GetMetaStructPointer())> pdescriptor_copies_pair{ pDescriptorCopies->GetPointer(), pDescriptorCopies->GetMetaStructPointer(), descriptorCopyCount };
    std::string pdescriptor_copies_names = toStringJoin(pdescriptor_copies_pair.begin(),
                                                        pdescriptor_copies_pair.end(),
                                                        [&](auto pair) {{ return GenerateStruct_VkCopyDescriptorSet(stream_pdescriptor_copies, pair.t1, pair.t2, *this); }},
                                                        ", ");
    if (stream_pdescriptor_copies.str().length() > 0) {
        fprintf(file, "%s", stream_pdescriptor_copies.str().c_str());
        if (descriptorCopyCount == 1) {
            pdescriptor_copies_array = "&" + pdescriptor_copies_names;
        } else if (descriptorCopyCount > 1) {
            pdescriptor_copies_array = "pDescriptorCopies_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkCopyDescriptorSet %s[] = { %s };\n", pdescriptor_copies_array.c_str(), pdescriptor_copies_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkUpdateDescriptorSets(%s, %u, %s, %u, %s);\n",
            this->GetHandle(device).c_str(),
            descriptorWriteCount,
            pdescriptor_writes_array.c_str(),
            descriptorCopyCount,
            pdescriptor_copies_array.c_str());
    fprintf(file, "\t}\n");
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
    Intercept_vkBindBufferMemory2(returnValue, device, bindInfoCount, pBindInfos);
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbind_infos;
    std::string pbind_infos_array = "NULL";
    PointerPairContainer<decltype(pBindInfos->GetPointer()), decltype(pBindInfos->GetMetaStructPointer())> pbind_infos_pair{ pBindInfos->GetPointer(), pBindInfos->GetMetaStructPointer(), bindInfoCount };
    std::string pbind_infos_names = toStringJoin(pbind_infos_pair.begin(),
                                                 pbind_infos_pair.end(),
                                                 [&](auto pair) {{ return GenerateStruct_VkBindBufferMemoryInfo(stream_pbind_infos, pair.t1, pair.t2, *this); }},
                                                 ", ");
    if (stream_pbind_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pbind_infos.str().c_str());
        if (bindInfoCount == 1) {
            pbind_infos_array = "&" + pbind_infos_names;
        } else if (bindInfoCount > 1) {
            pbind_infos_array = "pBindInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBindBufferMemoryInfo %s[] = { %s };\n", pbind_infos_array.c_str(), pbind_infos_names.c_str());
        }
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkBindBufferMemory2(%s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            bindInfoCount,
            pbind_infos_array.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindBufferMemory2);
}

void VulkanCppConsumer::Process_vkBindImageMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    Intercept_vkBindImageMemory2(returnValue, device, bindInfoCount, pBindInfos);
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbind_infos;
    std::string pbind_infos_array = "NULL";
    PointerPairContainer<decltype(pBindInfos->GetPointer()), decltype(pBindInfos->GetMetaStructPointer())> pbind_infos_pair{ pBindInfos->GetPointer(), pBindInfos->GetMetaStructPointer(), bindInfoCount };
    std::string pbind_infos_names = toStringJoin(pbind_infos_pair.begin(),
                                                 pbind_infos_pair.end(),
                                                 [&](auto pair) {{ return GenerateStruct_VkBindImageMemoryInfo(stream_pbind_infos, pair.t1, pair.t2, *this); }},
                                                 ", ");
    if (stream_pbind_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pbind_infos.str().c_str());
        if (bindInfoCount == 1) {
            pbind_infos_array = "&" + pbind_infos_names;
        } else if (bindInfoCount > 1) {
            pbind_infos_array = "pBindInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBindImageMemoryInfo %s[] = { %s };\n", pbind_infos_array.c_str(), pbind_infos_names.c_str());
        }
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkBindImageMemory2(%s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            bindInfoCount,
            pbind_infos_array.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdDispatchBase(%s, %u, %u, %u, %u, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            baseGroupX,
            baseGroupY,
            baseGroupZ,
            groupCountX,
            groupCountY,
            groupCountZ);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDispatchBase);
}

void VulkanCppConsumer::Process_vkCmdSetDeviceMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetDeviceMask(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            deviceMask);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkSamplerYcbcrConversionCreateInfo(stream_pcreate_info,
                                                                                        pCreateInfo->GetPointer(),
                                                                                        pCreateInfo->GetMetaStructPointer(),
                                                                                        *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pycbcr_conversion_name = "pYcbcrConversion_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION));
    AddKnownVariables("VkSamplerYcbcrConversion", pycbcr_conversion_name, pYcbcrConversion->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pycbcr_conversion_name,
                         pYcbcrConversion->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateSamplerYcbcrConversion(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pycbcr_conversion_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion);
}

void VulkanCppConsumer::Process_vkDestroyDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyDescriptorUpdateTemplate(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(descriptorUpdateTemplate).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate);
}

void VulkanCppConsumer::Process_vkDestroySamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroySamplerYcbcrConversion(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(ycbcrConversion).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pphysical_device_group_count_name = "pPhysicalDeviceGroupCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pphysical_device_group_count_name.c_str());
    std::string pphysical_device_group_properties_name = "pPhysicalDeviceGroupProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pphysical_device_group_properties;
    pphysical_device_group_properties_name = GenerateStruct_VkPhysicalDeviceGroupProperties(stream_pphysical_device_group_properties,
                                                                                            pPhysicalDeviceGroupProperties->GetPointer(),
                                                                                            pPhysicalDeviceGroupProperties->GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pphysical_device_group_properties.str().c_str());
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkEnumeratePhysicalDeviceGroups(%s, &%s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pphysical_device_group_count_name.c_str(),
            pphysical_device_group_properties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups);
}

void VulkanCppConsumer::Process_vkGetBufferMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    Generate_vkGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2);
}

void VulkanCppConsumer::Process_vkGetDescriptorSetLayoutSupport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkDescriptorSetLayoutCreateInfo(stream_pcreate_info,
                                                                                     pCreateInfo->GetPointer(),
                                                                                     pCreateInfo->GetMetaStructPointer(),
                                                                                     *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psupport_name = "pSupport_" + std::to_string(this->GetNextId());
    std::stringstream stream_psupport;
    psupport_name = GenerateStruct_VkDescriptorSetLayoutSupport(stream_psupport,
                                                                pSupport->GetPointer(),
                                                                pSupport->GetMetaStructPointer(),
                                                                *this);
    fprintf(file, "%s", stream_psupport.str().c_str());
    fprintf(file,
            "\t\tvkGetDescriptorSetLayoutSupport(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            psupport_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string ppeer_memory_features_name = "pPeerMemoryFeatures_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tVkPeerMemoryFeatureFlags %s;\n", ppeer_memory_features_name.c_str());
    fprintf(file,
            "\t\tvkGetDeviceGroupPeerMemoryFeatures(%s, %u, %u, %u, &%s);\n",
            this->GetHandle(device).c_str(),
            heapIndex,
            localDeviceIndex,
            remoteDeviceIndex,
            ppeer_memory_features_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures);
}

void VulkanCppConsumer::Process_vkGetDeviceQueue2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceQueueInfo2>* pQueueInfo,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pqueue_info;
    std::string pqueue_info_struct = GenerateStruct_VkDeviceQueueInfo2(stream_pqueue_info,
                                                                       pQueueInfo->GetPointer(),
                                                                       pQueueInfo->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "%s", stream_pqueue_info.str().c_str());
    std::string pqueue_name = "pQueue_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_QUEUE));
    AddKnownVariables("VkQueue", pqueue_name, pQueue->GetPointer());
    this->AddHandles(pqueue_name,
                     pQueue->GetPointer());
    fprintf(file,
            "\t\tvkGetDeviceQueue2(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pqueue_info_struct.c_str(),
            pqueue_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceQueue2);
}

void VulkanCppConsumer::Process_vkGetImageMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    Generate_vkGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkImageSparseMemoryRequirementsInfo2(stream_pinfo,
                                                                                   pInfo->GetPointer(),
                                                                                   pInfo->GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string psparse_memory_requirement_count_name = "pSparseMemoryRequirementCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", psparse_memory_requirement_count_name.c_str());
    std::string psparse_memory_requirements_name = "pSparseMemoryRequirements_" + std::to_string(this->GetNextId());
    std::stringstream stream_psparse_memory_requirements;
    psparse_memory_requirements_name = GenerateStruct_VkSparseImageMemoryRequirements2(stream_psparse_memory_requirements,
                                                                                       pSparseMemoryRequirements->GetPointer(),
                                                                                       pSparseMemoryRequirements->GetMetaStructPointer(),
                                                                                       *this);
    fprintf(file, "%s", stream_psparse_memory_requirements.str().c_str());
    fprintf(file,
            "\t\tvkGetImageSparseMemoryRequirements2(%s, &%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pinfo_struct.c_str(),
            psparse_memory_requirement_count_name.c_str(),
            psparse_memory_requirements_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceExternalBufferProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pexternal_buffer_info;
    std::string pexternal_buffer_info_struct = GenerateStruct_VkPhysicalDeviceExternalBufferInfo(stream_pexternal_buffer_info,
                                                                                                 pExternalBufferInfo->GetPointer(),
                                                                                                 pExternalBufferInfo->GetMetaStructPointer(),
                                                                                                 *this);
    fprintf(file, "%s", stream_pexternal_buffer_info.str().c_str());
    std::string pexternal_buffer_properties_name = "pExternalBufferProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pexternal_buffer_properties;
    pexternal_buffer_properties_name = GenerateStruct_VkExternalBufferProperties(stream_pexternal_buffer_properties,
                                                                                 pExternalBufferProperties->GetPointer(),
                                                                                 pExternalBufferProperties->GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_pexternal_buffer_properties.str().c_str());
    fprintf(file,
            "\t\tvkGetPhysicalDeviceExternalBufferProperties(%s, &%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pexternal_buffer_info_struct.c_str(),
            pexternal_buffer_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceExternalFenceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pexternal_fence_info;
    std::string pexternal_fence_info_struct = GenerateStruct_VkPhysicalDeviceExternalFenceInfo(stream_pexternal_fence_info,
                                                                                               pExternalFenceInfo->GetPointer(),
                                                                                               pExternalFenceInfo->GetMetaStructPointer(),
                                                                                               *this);
    fprintf(file, "%s", stream_pexternal_fence_info.str().c_str());
    std::string pexternal_fence_properties_name = "pExternalFenceProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pexternal_fence_properties;
    pexternal_fence_properties_name = GenerateStruct_VkExternalFenceProperties(stream_pexternal_fence_properties,
                                                                               pExternalFenceProperties->GetPointer(),
                                                                               pExternalFenceProperties->GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_pexternal_fence_properties.str().c_str());
    fprintf(file,
            "\t\tvkGetPhysicalDeviceExternalFenceProperties(%s, &%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pexternal_fence_info_struct.c_str(),
            pexternal_fence_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pexternal_semaphore_info;
    std::string pexternal_semaphore_info_struct = GenerateStruct_VkPhysicalDeviceExternalSemaphoreInfo(stream_pexternal_semaphore_info,
                                                                                                       pExternalSemaphoreInfo->GetPointer(),
                                                                                                       pExternalSemaphoreInfo->GetMetaStructPointer(),
                                                                                                       *this);
    fprintf(file, "%s", stream_pexternal_semaphore_info.str().c_str());
    std::string pexternal_semaphore_properties_name = "pExternalSemaphoreProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pexternal_semaphore_properties;
    pexternal_semaphore_properties_name = GenerateStruct_VkExternalSemaphoreProperties(stream_pexternal_semaphore_properties,
                                                                                       pExternalSemaphoreProperties->GetPointer(),
                                                                                       pExternalSemaphoreProperties->GetMetaStructPointer(),
                                                                                       *this);
    fprintf(file, "%s", stream_pexternal_semaphore_properties.str().c_str());
    fprintf(file,
            "\t\tvkGetPhysicalDeviceExternalSemaphoreProperties(%s, &%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pexternal_semaphore_info_struct.c_str(),
            pexternal_semaphore_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceFeatures2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pfeatures_name = "pFeatures_" + std::to_string(this->GetNextId());
    std::stringstream stream_pfeatures;
    pfeatures_name = GenerateStruct_VkPhysicalDeviceFeatures2(stream_pfeatures,
                                                              pFeatures->GetPointer(),
                                                              pFeatures->GetMetaStructPointer(),
                                                              *this);
    fprintf(file, "%s", stream_pfeatures.str().c_str());
    fprintf(file,
            "\t\tvkGetPhysicalDeviceFeatures2(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pfeatures_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceFormatProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pformat_properties_name = "pFormatProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pformat_properties;
    pformat_properties_name = GenerateStruct_VkFormatProperties2(stream_pformat_properties,
                                                                 pFormatProperties->GetPointer(),
                                                                 pFormatProperties->GetMetaStructPointer(),
                                                                 *this);
    fprintf(file, "%s", stream_pformat_properties.str().c_str());
    fprintf(file,
            "\t\tvkGetPhysicalDeviceFormatProperties2(%s, %s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            util::ToString<VkFormat>(format).c_str(),
            pformat_properties_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pimage_format_info;
    std::string pimage_format_info_struct = GenerateStruct_VkPhysicalDeviceImageFormatInfo2(stream_pimage_format_info,
                                                                                            pImageFormatInfo->GetPointer(),
                                                                                            pImageFormatInfo->GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pimage_format_info.str().c_str());
    std::string pimage_format_properties_name = "pImageFormatProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pimage_format_properties;
    pimage_format_properties_name = GenerateStruct_VkImageFormatProperties2(stream_pimage_format_properties,
                                                                            pImageFormatProperties->GetPointer(),
                                                                            pImageFormatProperties->GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pimage_format_properties.str().c_str());
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkGetPhysicalDeviceImageFormatProperties2(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pimage_format_info_struct.c_str(),
            pimage_format_properties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceMemoryProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pmemory_properties_name = "pMemoryProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pmemory_properties;
    pmemory_properties_name = GenerateStruct_VkPhysicalDeviceMemoryProperties2(stream_pmemory_properties,
                                                                               pMemoryProperties->GetPointer(),
                                                                               pMemoryProperties->GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_pmemory_properties.str().c_str());
    fprintf(file,
            "\t\tvkGetPhysicalDeviceMemoryProperties2(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pmemory_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pproperties;
    pproperties_name = GenerateStruct_VkPhysicalDeviceProperties2(stream_pproperties,
                                                                  pProperties->GetPointer(),
                                                                  pProperties->GetMetaStructPointer(),
                                                                  *this);
    fprintf(file, "%s", stream_pproperties.str().c_str());
    fprintf(file,
            "\t\tvkGetPhysicalDeviceProperties2(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pproperties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pqueue_family_property_count_name = "pQueueFamilyPropertyCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pqueue_family_property_count_name.c_str());
    std::string pqueue_family_properties_name = "pQueueFamilyProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pqueue_family_properties;
    pqueue_family_properties_name = GenerateStruct_VkQueueFamilyProperties2(stream_pqueue_family_properties,
                                                                            pQueueFamilyProperties->GetPointer(),
                                                                            pQueueFamilyProperties->GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pqueue_family_properties.str().c_str());
    fprintf(file,
            "\t\tvkGetPhysicalDeviceQueueFamilyProperties2(%s, &%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pqueue_family_property_count_name.c_str(),
            pqueue_family_properties_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pformat_info;
    std::string pformat_info_struct = GenerateStruct_VkPhysicalDeviceSparseImageFormatInfo2(stream_pformat_info,
                                                                                            pFormatInfo->GetPointer(),
                                                                                            pFormatInfo->GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pformat_info.str().c_str());
    std::string pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pproperty_count_name.c_str());
    std::string pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pproperties;
    pproperties_name = GenerateStruct_VkSparseImageFormatProperties2(stream_pproperties,
                                                                     pProperties->GetPointer(),
                                                                     pProperties->GetMetaStructPointer(),
                                                                     *this);
    fprintf(file, "%s", stream_pproperties.str().c_str());
    fprintf(file,
            "\t\tvkGetPhysicalDeviceSparseImageFormatProperties2(%s, &%s, &%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pformat_info_struct.c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2);
}

void VulkanCppConsumer::Process_vkTrimCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkTrimCommandPool(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(commandPool).c_str(),
            util::ToString<VkCommandPoolTrimFlags>(flags).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkTrimCommandPool);
}
void VulkanCppConsumer::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_prender_pass_begin;
    std::string prender_pass_begin_struct = GenerateStruct_VkRenderPassBeginInfo(stream_prender_pass_begin,
                                                                                 pRenderPassBegin->GetPointer(),
                                                                                 pRenderPassBegin->GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_prender_pass_begin.str().c_str());
    std::stringstream stream_psubpass_begin_info;
    std::string psubpass_begin_info_struct = GenerateStruct_VkSubpassBeginInfo(stream_psubpass_begin_info,
                                                                               pSubpassBeginInfo->GetPointer(),
                                                                               pSubpassBeginInfo->GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_psubpass_begin_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdBeginRenderPass2(%s, &%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            prender_pass_begin_struct.c_str(),
            psubpass_begin_info_struct.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdDrawIndexedIndirectCount(%s, %s, %" PRIu64 "UL, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            this->GetHandle(countBuffer).c_str(),
            countBufferOffset,
            maxDrawCount,
            stride);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdDrawIndirectCount(%s, %s, %" PRIu64 "UL, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            this->GetHandle(countBuffer).c_str(),
            countBufferOffset,
            maxDrawCount,
            stride);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirectCount);
}

void VulkanCppConsumer::Process_vkCmdEndRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psubpass_end_info;
    std::string psubpass_end_info_struct = GenerateStruct_VkSubpassEndInfo(stream_psubpass_end_info,
                                                                           pSubpassEndInfo->GetPointer(),
                                                                           pSubpassEndInfo->GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_psubpass_end_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdEndRenderPass2(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            psubpass_end_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRenderPass2);
}

void VulkanCppConsumer::Process_vkCmdNextSubpass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psubpass_begin_info;
    std::string psubpass_begin_info_struct = GenerateStruct_VkSubpassBeginInfo(stream_psubpass_begin_info,
                                                                               pSubpassBeginInfo->GetPointer(),
                                                                               pSubpassBeginInfo->GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_psubpass_begin_info.str().c_str());
    std::stringstream stream_psubpass_end_info;
    std::string psubpass_end_info_struct = GenerateStruct_VkSubpassEndInfo(stream_psubpass_end_info,
                                                                           pSubpassEndInfo->GetPointer(),
                                                                           pSubpassEndInfo->GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_psubpass_end_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdNextSubpass2(%s, &%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            psubpass_begin_info_struct.c_str(),
            psubpass_end_info_struct.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkRenderPassCreateInfo2(stream_pcreate_info,
                                                                             pCreateInfo->GetPointer(),
                                                                             pCreateInfo->GetMetaStructPointer(),
                                                                             *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string prender_pass_name = "pRenderPass_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_RENDER_PASS));
    AddKnownVariables("VkRenderPass", prender_pass_name, pRenderPass->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(prender_pass_name,
                         pRenderPass->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateRenderPass2(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            prender_pass_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateRenderPass2);
}

void VulkanCppConsumer::Process_vkGetBufferDeviceAddress(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkBufferDeviceAddressInfo(stream_pinfo,
                                                                        pInfo->GetPointer(),
                                                                        pInfo->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    fprintf(file,
            "\t\tvkGetBufferDeviceAddress(%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferDeviceAddress);
}

void VulkanCppConsumer::Process_vkGetBufferOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkBufferDeviceAddressInfo(stream_pinfo,
                                                                        pInfo->GetPointer(),
                                                                        pInfo->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    fprintf(file,
            "\t\tvkGetBufferOpaqueCaptureAddress(%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress);
}

void VulkanCppConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDeviceMemoryOpaqueCaptureAddressInfo(stream_pinfo,
                                                                                     pInfo->GetPointer(),
                                                                                     pInfo->GetMetaStructPointer(),
                                                                                     *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    fprintf(file,
            "\t\tvkGetDeviceMemoryOpaqueCaptureAddress(%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pvalue_name = "pValue_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint64_t %s;\n", pvalue_name.c_str());
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkGetSemaphoreCounterValue(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(semaphore).c_str(),
            pvalue_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkResetQueryPool(%s, %s, %u, %u);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(queryPool).c_str(),
            firstQuery,
            queryCount);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkResetQueryPool);
}

void VulkanCppConsumer::Process_vkSignalSemaphore(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psignal_info;
    std::string psignal_info_struct = GenerateStruct_VkSemaphoreSignalInfo(stream_psignal_info,
                                                                           pSignalInfo->GetPointer(),
                                                                           pSignalInfo->GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_psignal_info.str().c_str());
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkSignalSemaphore(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            psignal_info_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pwait_info;
    std::string pwait_info_struct = GenerateStruct_VkSemaphoreWaitInfo(stream_pwait_info,
                                                                       pWaitInfo->GetPointer(),
                                                                       pWaitInfo->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "%s", stream_pwait_info.str().c_str());
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkWaitSemaphores(%s, &%s, %" PRIu64 "UL), %s);\n",
            this->GetHandle(device).c_str(),
            pwait_info_struct.c_str(),
            timeout,
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkWaitSemaphores);
}
void VulkanCppConsumer::Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_prendering_info;
    std::string prendering_info_struct = GenerateStruct_VkRenderingInfo(stream_prendering_info,
                                                                        pRenderingInfo->GetPointer(),
                                                                        pRenderingInfo->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_prendering_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdBeginRendering(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            prendering_info_struct.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pbuffers_array = "NULL";
    std::string pbuffers_values = toStringJoin(pBuffers->GetPointer(),
                                               pBuffers->GetPointer() + bindingCount,
                                               [&](const format::HandleId current) { return this->GetHandle(current); },
                                               ", ");
    if (bindingCount == 1 && pbuffers_values != "VK_NULL_HANDLE") {
        pbuffers_array = "&" + pbuffers_values;
    } else if (bindingCount > 1) {
        pbuffers_array = "pbuffers_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkBuffer %s[] = { %s };\n", pbuffers_array.c_str(), pbuffers_values.c_str());
    }
    std::string poffsets_array = "pOffsets_" + std::to_string(this->GetNextId());
    if (bindingCount > 0) {
        std::string poffsets_values = toStringJoin(pOffsets->GetPointer(),
                                                   pOffsets->GetPointer() + bindingCount,
                                                   [&](const auto current) { return std::to_string(current) + "UL"; },
                                                   ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", poffsets_array.c_str(), poffsets_values.c_str());
    } else {
        poffsets_array = "NULL";
    }
    std::string psizes_array = "pSizes_" + std::to_string(this->GetNextId());
    if (bindingCount > 0 && pSizes->GetPointer() != nullptr) {
        std::string psizes_values = toStringJoin(pSizes->GetPointer(),
                                                 pSizes->GetPointer() + bindingCount,
                                                 [&](const auto current) { return std::to_string(current) + "UL"; },
                                                 ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", psizes_array.c_str(), psizes_values.c_str());
    } else {
        psizes_array = "NULL";
    }
    std::string pstrides_array = "pStrides_" + std::to_string(this->GetNextId());
    if (bindingCount > 0 && pStrides->GetPointer() != nullptr) {
        std::string pstrides_values = toStringJoin(pStrides->GetPointer(),
                                                   pStrides->GetPointer() + bindingCount,
                                                   [&](const auto current) { return std::to_string(current) + "UL"; },
                                                   ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", pstrides_array.c_str(), pstrides_values.c_str());
    } else {
        pstrides_array = "NULL";
    }
    fprintf(file,
            "\t\tvkCmdBindVertexBuffers2(%s, %u, %u, %s, %s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstBinding,
            bindingCount,
            pbuffers_array.c_str(),
            poffsets_array.c_str(),
            psizes_array.c_str(),
            pstrides_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2);
}

void VulkanCppConsumer::Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pblit_image_info;
    std::string pblit_image_info_struct = GenerateStruct_VkBlitImageInfo2(stream_pblit_image_info,
                                                                          pBlitImageInfo->GetPointer(),
                                                                          pBlitImageInfo->GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pblit_image_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdBlitImage2(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pblit_image_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBlitImage2);
}

void VulkanCppConsumer::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_buffer_info;
    std::string pcopy_buffer_info_struct = GenerateStruct_VkCopyBufferInfo2(stream_pcopy_buffer_info,
                                                                            pCopyBufferInfo->GetPointer(),
                                                                            pCopyBufferInfo->GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pcopy_buffer_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdCopyBuffer2(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pcopy_buffer_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyBuffer2);
}

void VulkanCppConsumer::Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_buffer_to_image_info;
    std::string pcopy_buffer_to_image_info_struct = GenerateStruct_VkCopyBufferToImageInfo2(stream_pcopy_buffer_to_image_info,
                                                                                            pCopyBufferToImageInfo->GetPointer(),
                                                                                            pCopyBufferToImageInfo->GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pcopy_buffer_to_image_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdCopyBufferToImage2(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pcopy_buffer_to_image_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2);
}

void VulkanCppConsumer::Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_image_info;
    std::string pcopy_image_info_struct = GenerateStruct_VkCopyImageInfo2(stream_pcopy_image_info,
                                                                          pCopyImageInfo->GetPointer(),
                                                                          pCopyImageInfo->GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pcopy_image_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdCopyImage2(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pcopy_image_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImage2);
}

void VulkanCppConsumer::Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_image_to_buffer_info;
    std::string pcopy_image_to_buffer_info_struct = GenerateStruct_VkCopyImageToBufferInfo2(stream_pcopy_image_to_buffer_info,
                                                                                            pCopyImageToBufferInfo->GetPointer(),
                                                                                            pCopyImageToBufferInfo->GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pcopy_image_to_buffer_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdCopyImageToBuffer2(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pcopy_image_to_buffer_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2);
}

void VulkanCppConsumer::Process_vkCmdEndRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdEndRendering(%s);\n",
            this->GetHandle(commandBuffer).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRendering);
}

void VulkanCppConsumer::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdependency_info;
    std::string pdependency_info_struct = GenerateStruct_VkDependencyInfo(stream_pdependency_info,
                                                                          pDependencyInfo->GetPointer(),
                                                                          pDependencyInfo->GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pdependency_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdPipelineBarrier2(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pdependency_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPipelineBarrier2);
}

void VulkanCppConsumer::Process_vkCmdResetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdResetEvent2(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(event).c_str(),
            util::ToString<VkPipelineStageFlags2>(stageMask).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResetEvent2);
}

void VulkanCppConsumer::Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_presolve_image_info;
    std::string presolve_image_info_struct = GenerateStruct_VkResolveImageInfo2(stream_presolve_image_info,
                                                                                pResolveImageInfo->GetPointer(),
                                                                                pResolveImageInfo->GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_presolve_image_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdResolveImage2(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            presolve_image_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResolveImage2);
}

void VulkanCppConsumer::Process_vkCmdSetCullMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetCullMode(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkCullModeFlags>(cullMode).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCullMode);
}

void VulkanCppConsumer::Process_vkCmdSetDepthBiasEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetDepthBiasEnable(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            depthBiasEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable);
}

void VulkanCppConsumer::Process_vkCmdSetDepthBoundsTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetDepthBoundsTestEnable(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            depthBoundsTestEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable);
}

void VulkanCppConsumer::Process_vkCmdSetDepthCompareOp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetDepthCompareOp(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkCompareOp>(depthCompareOp).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp);
}

void VulkanCppConsumer::Process_vkCmdSetDepthTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetDepthTestEnable(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            depthTestEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable);
}

void VulkanCppConsumer::Process_vkCmdSetDepthWriteEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetDepthWriteEnable(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            depthWriteEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable);
}

void VulkanCppConsumer::Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdependency_info;
    std::string pdependency_info_struct = GenerateStruct_VkDependencyInfo(stream_pdependency_info,
                                                                          pDependencyInfo->GetPointer(),
                                                                          pDependencyInfo->GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pdependency_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdSetEvent2(%s, %s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(event).c_str(),
            pdependency_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetEvent2);
}

void VulkanCppConsumer::Process_vkCmdSetFrontFace(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetFrontFace(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkFrontFace>(frontFace).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetFrontFace);
}

void VulkanCppConsumer::Process_vkCmdSetPrimitiveRestartEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetPrimitiveRestartEnable(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            primitiveRestartEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable);
}

void VulkanCppConsumer::Process_vkCmdSetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetPrimitiveTopology(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPrimitiveTopology>(primitiveTopology).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology);
}

void VulkanCppConsumer::Process_vkCmdSetRasterizerDiscardEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetRasterizerDiscardEnable(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            rasterizerDiscardEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable);
}

void VulkanCppConsumer::Process_vkCmdSetScissorWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pscissors;
    std::string pscissors_array = "NULL";
    PointerPairContainer<decltype(pScissors->GetPointer()), decltype(pScissors->GetMetaStructPointer())> pscissors_pair{ pScissors->GetPointer(), pScissors->GetMetaStructPointer(), scissorCount };
    std::string pscissors_names = toStringJoin(pscissors_pair.begin(),
                                               pscissors_pair.end(),
                                               [&](auto pair) {{ return GenerateStruct_VkRect2D(stream_pscissors, pair.t1, pair.t2, *this); }},
                                               ", ");
    if (stream_pscissors.str().length() > 0) {
        fprintf(file, "%s", stream_pscissors.str().c_str());
        if (scissorCount == 1) {
            pscissors_array = "&" + pscissors_names;
        } else if (scissorCount > 1) {
            pscissors_array = "pScissors_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkRect2D %s[] = { %s };\n", pscissors_array.c_str(), pscissors_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdSetScissorWithCount(%s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            scissorCount,
            pscissors_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetStencilOp(%s, %s, %s, %s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkStencilFaceFlags>(faceMask).c_str(),
            util::ToString<VkStencilOp>(failOp).c_str(),
            util::ToString<VkStencilOp>(passOp).c_str(),
            util::ToString<VkStencilOp>(depthFailOp).c_str(),
            util::ToString<VkCompareOp>(compareOp).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilOp);
}

void VulkanCppConsumer::Process_vkCmdSetStencilTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetStencilTestEnable(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            stencilTestEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable);
}

void VulkanCppConsumer::Process_vkCmdSetViewportWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pviewports;
    std::string pviewports_array = "NULL";
    PointerPairContainer<decltype(pViewports->GetPointer()), decltype(pViewports->GetMetaStructPointer())> pviewports_pair{ pViewports->GetPointer(), pViewports->GetMetaStructPointer(), viewportCount };
    std::string pviewports_names = toStringJoin(pviewports_pair.begin(),
                                                pviewports_pair.end(),
                                                [&](auto pair) {{ return GenerateStruct_VkViewport(stream_pviewports, pair.t1, pair.t2, *this); }},
                                                ", ");
    if (stream_pviewports.str().length() > 0) {
        fprintf(file, "%s", stream_pviewports.str().c_str());
        if (viewportCount == 1) {
            pviewports_array = "&" + pviewports_names;
        } else if (viewportCount > 1) {
            pviewports_array = "pViewports_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkViewport %s[] = { %s };\n", pviewports_array.c_str(), pviewports_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdSetViewportWithCount(%s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            viewportCount,
            pviewports_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pevents_array = "NULL";
    std::string pevents_values = toStringJoin(pEvents->GetPointer(),
                                              pEvents->GetPointer() + eventCount,
                                              [&](const format::HandleId current) { return this->GetHandle(current); },
                                              ", ");
    if (eventCount == 1 && pevents_values != "VK_NULL_HANDLE") {
        pevents_array = "&" + pevents_values;
    } else if (eventCount > 1) {
        pevents_array = "pevents_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkEvent %s[] = { %s };\n", pevents_array.c_str(), pevents_values.c_str());
    }
    std::stringstream stream_pdependency_infos;
    std::string pdependency_infos_array = "NULL";
    PointerPairContainer<decltype(pDependencyInfos->GetPointer()), decltype(pDependencyInfos->GetMetaStructPointer())> pdependency_infos_pair{ pDependencyInfos->GetPointer(), pDependencyInfos->GetMetaStructPointer(), eventCount };
    std::string pdependency_infos_names = toStringJoin(pdependency_infos_pair.begin(),
                                                       pdependency_infos_pair.end(),
                                                       [&](auto pair) {{ return GenerateStruct_VkDependencyInfo(stream_pdependency_infos, pair.t1, pair.t2, *this); }},
                                                       ", ");
    if (stream_pdependency_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pdependency_infos.str().c_str());
        if (eventCount == 1) {
            pdependency_infos_array = "&" + pdependency_infos_names;
        } else if (eventCount > 1) {
            pdependency_infos_array = "pDependencyInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkDependencyInfo %s[] = { %s };\n", pdependency_infos_array.c_str(), pdependency_infos_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdWaitEvents2(%s, %u, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            eventCount,
            pevents_array.c_str(),
            pdependency_infos_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdWriteTimestamp2(%s, %s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineStageFlags2>(stage).c_str(),
            this->GetHandle(queryPool).c_str(),
            query);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkPrivateDataSlotCreateInfo(stream_pcreate_info,
                                                                                 pCreateInfo->GetPointer(),
                                                                                 pCreateInfo->GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pprivate_data_slot_name = "pPrivateDataSlot_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_PRIVATE_DATA_SLOT));
    AddKnownVariables("VkPrivateDataSlot", pprivate_data_slot_name, pPrivateDataSlot->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pprivate_data_slot_name,
                         pPrivateDataSlot->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreatePrivateDataSlot(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pprivate_data_slot_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreatePrivateDataSlot);
}

void VulkanCppConsumer::Process_vkDestroyPrivateDataSlot(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyPrivateDataSlot(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(privateDataSlot).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot);
}

void VulkanCppConsumer::Process_vkGetDeviceBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDeviceBufferMemoryRequirements(stream_pinfo,
                                                                               pInfo->GetPointer(),
                                                                               pInfo->GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string pmemory_requirements_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
    std::stringstream stream_pmemory_requirements;
    pmemory_requirements_name = GenerateStruct_VkMemoryRequirements2(stream_pmemory_requirements,
                                                                     pMemoryRequirements->GetPointer(),
                                                                     pMemoryRequirements->GetMetaStructPointer(),
                                                                     *this);
    fprintf(file, "%s", stream_pmemory_requirements.str().c_str());
    fprintf(file,
            "\t\tvkGetDeviceBufferMemoryRequirements(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pinfo_struct.c_str(),
            pmemory_requirements_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements);
}

void VulkanCppConsumer::Process_vkGetDeviceImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDeviceImageMemoryRequirements(stream_pinfo,
                                                                              pInfo->GetPointer(),
                                                                              pInfo->GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string pmemory_requirements_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
    std::stringstream stream_pmemory_requirements;
    pmemory_requirements_name = GenerateStruct_VkMemoryRequirements2(stream_pmemory_requirements,
                                                                     pMemoryRequirements->GetPointer(),
                                                                     pMemoryRequirements->GetMetaStructPointer(),
                                                                     *this);
    fprintf(file, "%s", stream_pmemory_requirements.str().c_str());
    fprintf(file,
            "\t\tvkGetDeviceImageMemoryRequirements(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pinfo_struct.c_str(),
            pmemory_requirements_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDeviceImageMemoryRequirements(stream_pinfo,
                                                                              pInfo->GetPointer(),
                                                                              pInfo->GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string psparse_memory_requirement_count_name = "pSparseMemoryRequirementCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", psparse_memory_requirement_count_name.c_str());
    std::string psparse_memory_requirements_name = "pSparseMemoryRequirements_" + std::to_string(this->GetNextId());
    std::stringstream stream_psparse_memory_requirements;
    psparse_memory_requirements_name = GenerateStruct_VkSparseImageMemoryRequirements2(stream_psparse_memory_requirements,
                                                                                       pSparseMemoryRequirements->GetPointer(),
                                                                                       pSparseMemoryRequirements->GetMetaStructPointer(),
                                                                                       *this);
    fprintf(file, "%s", stream_psparse_memory_requirements.str().c_str());
    fprintf(file,
            "\t\tvkGetDeviceImageSparseMemoryRequirements(%s, &%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pinfo_struct.c_str(),
            psparse_memory_requirement_count_name.c_str(),
            psparse_memory_requirements_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string ptool_count_name = "pToolCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", ptool_count_name.c_str());
    std::string ptool_properties_name = "pToolProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_ptool_properties;
    ptool_properties_name = GenerateStruct_VkPhysicalDeviceToolProperties(stream_ptool_properties,
                                                                          pToolProperties->GetPointer(),
                                                                          pToolProperties->GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_ptool_properties.str().c_str());
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkGetPhysicalDeviceToolProperties(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            ptool_count_name.c_str(),
            ptool_properties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pdata_name = "pData_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint64_t %s;\n", pdata_name.c_str());
    fprintf(file,
            "\t\tvkGetPrivateData(%s, %s, %" PRIu64 "UL, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkObjectType>(objectType).c_str(),
            objectHandle,
            this->GetHandle(privateDataSlot).c_str(),
            pdata_name.c_str());
    fprintf(file, "\t}\n");
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
    Generate_vkQueueSubmit2(returnValue, queue, submitCount, pSubmits, fence);
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
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkSetPrivateData(%s, %s, %" PRIu64 "UL, %s, %" PRIu64 "UL), %s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkObjectType>(objectType).c_str(),
            objectHandle,
            this->GetHandle(privateDataSlot).c_str(),
            data,
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSetPrivateData);
}
void VulkanCppConsumer::Process_vkDestroySurfaceKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroySurfaceKHR");
    fprintf(file,
            "\t\tloaded_vkDestroySurfaceKHR(%s, %s, %s);\n",
            this->GetHandle(instance).c_str(),
            this->GetHandle(surface).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string psurface_capabilities_name = "pSurfaceCapabilities_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tVkSurfaceCapabilitiesKHR %s;\n", psurface_capabilities_name.c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(%s, %s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            this->GetHandle(surface).c_str(),
            psurface_capabilities_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string psupported_name = "pSupported_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tVkBool32 %s;\n", psupported_name.c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceSurfaceSupportKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfaceSupportKHR(%s, %u, %s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            queueFamilyIndex,
            this->GetHandle(surface).c_str(),
            psupported_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    Generate_vkCreateSwapchainKHR(returnValue, device, pCreateInfo, pAllocator, pSwapchain);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateSwapchainKHR);
}

void VulkanCppConsumer::Process_vkDestroySwapchainKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    Generate_vkDestroySwapchainKHR(device, swapchain, pAllocator);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySwapchainKHR);
}

void VulkanCppConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pdevice_group_present_capabilities_name = "pDeviceGroupPresentCapabilities_" + std::to_string(this->GetNextId());
    std::stringstream stream_pdevice_group_present_capabilities;
    pdevice_group_present_capabilities_name = GenerateStruct_VkDeviceGroupPresentCapabilitiesKHR(stream_pdevice_group_present_capabilities,
                                                                                                 pDeviceGroupPresentCapabilities->GetPointer(),
                                                                                                 pDeviceGroupPresentCapabilities->GetMetaStructPointer(),
                                                                                                 *this);
    fprintf(file, "%s", stream_pdevice_group_present_capabilities.str().c_str());
    pfn_loader_.AddMethodName("vkGetDeviceGroupPresentCapabilitiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDeviceGroupPresentCapabilitiesKHR(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pdevice_group_present_capabilities_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pmodes_name = "pModes_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tVkDeviceGroupPresentModeFlagsKHR %s;\n", pmodes_name.c_str());
    pfn_loader_.AddMethodName("vkGetDeviceGroupSurfacePresentModesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDeviceGroupSurfacePresentModesKHR(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(surface).c_str(),
            pmodes_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string prect_count_name = "pRectCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", prect_count_name.c_str());
    std::string prects_name = "pRects_" + std::to_string(this->GetNextId());
    const uint32_t* in_prect_count = pRectCount->GetPointer();
    fprintf(file, "\t\tVkRect2D %s[%d];\n", prects_name.c_str(), *in_prect_count);
    pfn_loader_.AddMethodName("vkGetPhysicalDevicePresentRectanglesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDevicePresentRectanglesKHR(%s, %s, &%s, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            this->GetHandle(surface).c_str(),
            prect_count_name.c_str(),
            prects_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    Generate_vkQueuePresentKHR(returnValue, queue, pPresentInfo);
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkDisplayModeCreateInfoKHR(stream_pcreate_info,
                                                                                pCreateInfo->GetPointer(),
                                                                                pCreateInfo->GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pmode_name = "pMode_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DISPLAY_MODE_KHR));
    AddKnownVariables("VkDisplayModeKHR", pmode_name, pMode->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pmode_name,
                         pMode->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateDisplayModeKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateDisplayModeKHR(%s, %s, &%s, %s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            this->GetHandle(display).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pmode_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkDisplaySurfaceCreateInfoKHR(stream_pcreate_info,
                                                                                   pCreateInfo->GetPointer(),
                                                                                   pCreateInfo->GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psurface_name = "pSurface_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", psurface_name, pSurface->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(psurface_name,
                         pSurface->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateDisplayPlaneSurfaceKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateDisplayPlaneSurfaceKHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psurface_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pproperty_count_name.c_str());
    std::string pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
    const uint32_t* in_pproperty_count = pPropertyCount->GetPointer();
    fprintf(file, "\t\tVkDisplayModePropertiesKHR %s[%d];\n", pproperties_name.c_str(), *in_pproperty_count);
    pfn_loader_.AddMethodName("vkGetDisplayModePropertiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDisplayModePropertiesKHR(%s, %s, &%s, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            this->GetHandle(display).c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pcapabilities_name = "pCapabilities_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tVkDisplayPlaneCapabilitiesKHR %s;\n", pcapabilities_name.c_str());
    pfn_loader_.AddMethodName("vkGetDisplayPlaneCapabilitiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDisplayPlaneCapabilitiesKHR(%s, %s, %u, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            this->GetHandle(mode).c_str(),
            planeIndex,
            pcapabilities_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pdisplay_count_name = "pDisplayCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pdisplay_count_name.c_str());
    std::string pdisplays_name = "pDisplays_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DISPLAY_KHR));
    AddKnownVariables("VkDisplayKHR", pdisplays_name, pDisplays->GetPointer(), *pDisplayCount->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pdisplays_name,
                         pDisplays->GetPointer(), *pDisplayCount->GetPointer());
    }
    pfn_loader_.AddMethodName("vkGetDisplayPlaneSupportedDisplaysKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDisplayPlaneSupportedDisplaysKHR(%s, %u, &%s, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            planeIndex,
            pdisplay_count_name.c_str(),
            pdisplays_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pproperty_count_name.c_str());
    std::string pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
    const uint32_t* in_pproperty_count = pPropertyCount->GetPointer();
    fprintf(file, "\t\tVkDisplayPlanePropertiesKHR %s[%d];\n", pproperties_name.c_str(), *in_pproperty_count);
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(%s, &%s, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pproperty_count_name.c_str());
    std::string pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
    const uint32_t* in_pproperty_count = pPropertyCount->GetPointer();
    fprintf(file, "\t\tVkDisplayPropertiesKHR %s[%d];\n", pproperties_name.c_str(), *in_pproperty_count);
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceDisplayPropertiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceDisplayPropertiesKHR(%s, &%s, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_infos;
    std::string pcreate_infos_array = "NULL";
    PointerPairContainer<decltype(pCreateInfos->GetPointer()), decltype(pCreateInfos->GetMetaStructPointer())> pcreate_infos_pair{ pCreateInfos->GetPointer(), pCreateInfos->GetMetaStructPointer(), swapchainCount };
    std::string pcreate_infos_names = toStringJoin(pcreate_infos_pair.begin(),
                                                   pcreate_infos_pair.end(),
                                                   [&](auto pair) {{ return GenerateStruct_VkSwapchainCreateInfoKHR(stream_pcreate_infos, pair.t1, pair.t2, *this); }},
                                                   ", ");
    if (stream_pcreate_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pcreate_infos.str().c_str());
        if (swapchainCount == 1) {
            pcreate_infos_array = "&" + pcreate_infos_names;
        } else if (swapchainCount > 1) {
            pcreate_infos_array = "pCreateInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkSwapchainCreateInfoKHR %s[] = { %s };\n", pcreate_infos_array.c_str(), pcreate_infos_names.c_str());
        }
    }
    std::string pswapchains_name = "pSwapchains_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SWAPCHAIN_KHR));
    AddKnownVariables("VkSwapchainKHR", pswapchains_name, pSwapchains->GetPointer(), swapchainCount);
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pswapchains_name,
                         pSwapchains->GetPointer(), swapchainCount);
    }
    pfn_loader_.AddMethodName("vkCreateSharedSwapchainsKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateSharedSwapchainsKHR(%s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            swapchainCount,
            pcreate_infos_array.c_str(),
            "nullptr",
            pswapchains_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    Generate_vkCreateXlibSurfaceKHR(returnValue, instance, pCreateInfo, pAllocator, pSurface);
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
    fprintf(file, "\t{\n");
    std::string dpy_name = "dpy_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tvoid* %s;\n", dpy_name.c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceXlibPresentationSupportKHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceXlibPresentationSupportKHR(%s, %u, %s, %" PRIu64 ");\n",
            this->GetHandle(physicalDevice).c_str(),
            queueFamilyIndex,
            dpy_name.c_str(),
            util::platform::SizeTtoUint64(visualID));
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    fprintf(file, "// TODO: Support vkGetPhysicalDeviceXcbPresentationSupportKHR function.\n");
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string display_name = "display_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tvoid* %s;\n", display_name.c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceWaylandPresentationSupportKHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceWaylandPresentationSupportKHR(%s, %u, %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            queueFamilyIndex,
            display_name.c_str());
    fprintf(file, "\t}\n");
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
    Generate_vkCreateWin32SurfaceKHR(returnValue, instance, pCreateInfo, pAllocator, pSurface);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceWin32PresentationSupportKHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceWin32PresentationSupportKHR(%s, %u);\n",
            this->GetHandle(physicalDevice).c_str(),
            queueFamilyIndex);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pbind_session_memory_infos;
    std::string pbind_session_memory_infos_array = "NULL";
    PointerPairContainer<decltype(pBindSessionMemoryInfos->GetPointer()), decltype(pBindSessionMemoryInfos->GetMetaStructPointer())> pbind_session_memory_infos_pair{ pBindSessionMemoryInfos->GetPointer(), pBindSessionMemoryInfos->GetMetaStructPointer(), bindSessionMemoryInfoCount };
    std::string pbind_session_memory_infos_names = toStringJoin(pbind_session_memory_infos_pair.begin(),
                                                                pbind_session_memory_infos_pair.end(),
                                                                [&](auto pair) {{ return GenerateStruct_VkBindVideoSessionMemoryInfoKHR(stream_pbind_session_memory_infos, pair.t1, pair.t2, *this); }},
                                                                ", ");
    if (stream_pbind_session_memory_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pbind_session_memory_infos.str().c_str());
        if (bindSessionMemoryInfoCount == 1) {
            pbind_session_memory_infos_array = "&" + pbind_session_memory_infos_names;
        } else if (bindSessionMemoryInfoCount > 1) {
            pbind_session_memory_infos_array = "pBindSessionMemoryInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBindVideoSessionMemoryInfoKHR %s[] = { %s };\n", pbind_session_memory_infos_array.c_str(), pbind_session_memory_infos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkBindVideoSessionMemoryKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkBindVideoSessionMemoryKHR(%s, %s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(videoSession).c_str(),
            bindSessionMemoryInfoCount,
            pbind_session_memory_infos_array.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR);
}

void VulkanCppConsumer::Process_vkCmdBeginVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR>* pBeginInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbegin_info;
    std::string pbegin_info_struct = GenerateStruct_VkVideoBeginCodingInfoKHR(stream_pbegin_info,
                                                                              pBeginInfo->GetPointer(),
                                                                              pBeginInfo->GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "%s", stream_pbegin_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdBeginVideoCodingKHR");
    fprintf(file,
            "\t\tloaded_vkCmdBeginVideoCodingKHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pbegin_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR);
}

void VulkanCppConsumer::Process_vkCmdControlVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR>* pCodingControlInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcoding_control_info;
    std::string pcoding_control_info_struct = GenerateStruct_VkVideoCodingControlInfoKHR(stream_pcoding_control_info,
                                                                                         pCodingControlInfo->GetPointer(),
                                                                                         pCodingControlInfo->GetMetaStructPointer(),
                                                                                         *this);
    fprintf(file, "%s", stream_pcoding_control_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdControlVideoCodingKHR");
    fprintf(file,
            "\t\tloaded_vkCmdControlVideoCodingKHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pcoding_control_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR);
}

void VulkanCppConsumer::Process_vkCmdEndVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR>* pEndCodingInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pend_coding_info;
    std::string pend_coding_info_struct = GenerateStruct_VkVideoEndCodingInfoKHR(stream_pend_coding_info,
                                                                                 pEndCodingInfo->GetPointer(),
                                                                                 pEndCodingInfo->GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_pend_coding_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdEndVideoCodingKHR");
    fprintf(file,
            "\t\tloaded_vkCmdEndVideoCodingKHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pend_coding_info_struct.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkVideoSessionCreateInfoKHR(stream_pcreate_info,
                                                                                 pCreateInfo->GetPointer(),
                                                                                 pCreateInfo->GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pvideo_session_name = "pVideoSession_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_VIDEO_SESSION_KHR));
    AddKnownVariables("VkVideoSessionKHR", pvideo_session_name, pVideoSession->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pvideo_session_name,
                         pVideoSession->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateVideoSessionKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateVideoSessionKHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pvideo_session_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkVideoSessionParametersCreateInfoKHR(stream_pcreate_info,
                                                                                           pCreateInfo->GetPointer(),
                                                                                           pCreateInfo->GetMetaStructPointer(),
                                                                                           *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pvideo_session_parameters_name = "pVideoSessionParameters_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_VIDEO_SESSION_PARAMETERS_KHR));
    AddKnownVariables("VkVideoSessionParametersKHR", pvideo_session_parameters_name, pVideoSessionParameters->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pvideo_session_parameters_name,
                         pVideoSessionParameters->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateVideoSessionParametersKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateVideoSessionParametersKHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pvideo_session_parameters_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR);
}

void VulkanCppConsumer::Process_vkDestroyVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyVideoSessionKHR");
    fprintf(file,
            "\t\tloaded_vkDestroyVideoSessionKHR(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(videoSession).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR);
}

void VulkanCppConsumer::Process_vkDestroyVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            videoSessionParameters,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyVideoSessionParametersKHR");
    fprintf(file,
            "\t\tloaded_vkDestroyVideoSessionParametersKHR(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(videoSessionParameters).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pvideo_profile;
    std::string pvideo_profile_struct = GenerateStruct_VkVideoProfileInfoKHR(stream_pvideo_profile,
                                                                             pVideoProfile->GetPointer(),
                                                                             pVideoProfile->GetMetaStructPointer(),
                                                                             *this);
    fprintf(file, "%s", stream_pvideo_profile.str().c_str());
    std::string pcapabilities_name = "pCapabilities_" + std::to_string(this->GetNextId());
    std::stringstream stream_pcapabilities;
    pcapabilities_name = GenerateStruct_VkVideoCapabilitiesKHR(stream_pcapabilities,
                                                               pCapabilities->GetPointer(),
                                                               pCapabilities->GetMetaStructPointer(),
                                                               *this);
    fprintf(file, "%s", stream_pcapabilities.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceVideoCapabilitiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceVideoCapabilitiesKHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pvideo_profile_struct.c_str(),
            pcapabilities_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pvideo_format_info;
    std::string pvideo_format_info_struct = GenerateStruct_VkPhysicalDeviceVideoFormatInfoKHR(stream_pvideo_format_info,
                                                                                              pVideoFormatInfo->GetPointer(),
                                                                                              pVideoFormatInfo->GetMetaStructPointer(),
                                                                                              *this);
    fprintf(file, "%s", stream_pvideo_format_info.str().c_str());
    std::string pvideo_format_property_count_name = "pVideoFormatPropertyCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pvideo_format_property_count_name.c_str());
    std::string pvideo_format_properties_name = "pVideoFormatProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pvideo_format_properties;
    pvideo_format_properties_name = GenerateStruct_VkVideoFormatPropertiesKHR(stream_pvideo_format_properties,
                                                                              pVideoFormatProperties->GetPointer(),
                                                                              pVideoFormatProperties->GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "%s", stream_pvideo_format_properties.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceVideoFormatPropertiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceVideoFormatPropertiesKHR(%s, &%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pvideo_format_info_struct.c_str(),
            pvideo_format_property_count_name.c_str(),
            pvideo_format_properties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pmemory_requirements_count_name = "pMemoryRequirementsCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pmemory_requirements_count_name.c_str());
    std::string pmemory_requirements_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
    std::stringstream stream_pmemory_requirements;
    pmemory_requirements_name = GenerateStruct_VkVideoSessionMemoryRequirementsKHR(stream_pmemory_requirements,
                                                                                   pMemoryRequirements->GetPointer(),
                                                                                   pMemoryRequirements->GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "%s", stream_pmemory_requirements.str().c_str());
    pfn_loader_.AddMethodName("vkGetVideoSessionMemoryRequirementsKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetVideoSessionMemoryRequirementsKHR(%s, %s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(videoSession).c_str(),
            pmemory_requirements_count_name.c_str(),
            pmemory_requirements_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pupdate_info;
    std::string pupdate_info_struct = GenerateStruct_VkVideoSessionParametersUpdateInfoKHR(stream_pupdate_info,
                                                                                           pUpdateInfo->GetPointer(),
                                                                                           pUpdateInfo->GetMetaStructPointer(),
                                                                                           *this);
    fprintf(file, "%s", stream_pupdate_info.str().c_str());
    pfn_loader_.AddMethodName("vkUpdateVideoSessionParametersKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkUpdateVideoSessionParametersKHR(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(videoSessionParameters).c_str(),
            pupdate_info_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR);
}
void VulkanCppConsumer::Process_vkCmdDecodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR>* pDecodeInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdecode_info;
    std::string pdecode_info_struct = GenerateStruct_VkVideoDecodeInfoKHR(stream_pdecode_info,
                                                                          pDecodeInfo->GetPointer(),
                                                                          pDecodeInfo->GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pdecode_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdDecodeVideoKHR");
    fprintf(file,
            "\t\tloaded_vkCmdDecodeVideoKHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pdecode_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR);
}
void VulkanCppConsumer::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_prendering_info;
    std::string prendering_info_struct = GenerateStruct_VkRenderingInfo(stream_prendering_info,
                                                                        pRenderingInfo->GetPointer(),
                                                                        pRenderingInfo->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_prendering_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdBeginRenderingKHR");
    fprintf(file,
            "\t\tloaded_vkCmdBeginRenderingKHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            prendering_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR);
}

void VulkanCppConsumer::Process_vkCmdEndRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdEndRenderingKHR");
    fprintf(file,
            "\t\tloaded_vkCmdEndRenderingKHR(%s);\n",
            this->GetHandle(commandBuffer).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRenderingKHR);
}
void VulkanCppConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pfeatures_name = "pFeatures_" + std::to_string(this->GetNextId());
    std::stringstream stream_pfeatures;
    pfeatures_name = GenerateStruct_VkPhysicalDeviceFeatures2(stream_pfeatures,
                                                              pFeatures->GetPointer(),
                                                              pFeatures->GetMetaStructPointer(),
                                                              *this);
    fprintf(file, "%s", stream_pfeatures.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceFeatures2KHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceFeatures2KHR(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pfeatures_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pformat_properties_name = "pFormatProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pformat_properties;
    pformat_properties_name = GenerateStruct_VkFormatProperties2(stream_pformat_properties,
                                                                 pFormatProperties->GetPointer(),
                                                                 pFormatProperties->GetMetaStructPointer(),
                                                                 *this);
    fprintf(file, "%s", stream_pformat_properties.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceFormatProperties2KHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceFormatProperties2KHR(%s, %s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            util::ToString<VkFormat>(format).c_str(),
            pformat_properties_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pimage_format_info;
    std::string pimage_format_info_struct = GenerateStruct_VkPhysicalDeviceImageFormatInfo2(stream_pimage_format_info,
                                                                                            pImageFormatInfo->GetPointer(),
                                                                                            pImageFormatInfo->GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pimage_format_info.str().c_str());
    std::string pimage_format_properties_name = "pImageFormatProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pimage_format_properties;
    pimage_format_properties_name = GenerateStruct_VkImageFormatProperties2(stream_pimage_format_properties,
                                                                            pImageFormatProperties->GetPointer(),
                                                                            pImageFormatProperties->GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pimage_format_properties.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceImageFormatProperties2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceImageFormatProperties2KHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pimage_format_info_struct.c_str(),
            pimage_format_properties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pmemory_properties_name = "pMemoryProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pmemory_properties;
    pmemory_properties_name = GenerateStruct_VkPhysicalDeviceMemoryProperties2(stream_pmemory_properties,
                                                                               pMemoryProperties->GetPointer(),
                                                                               pMemoryProperties->GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_pmemory_properties.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceMemoryProperties2KHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceMemoryProperties2KHR(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pmemory_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pproperties;
    pproperties_name = GenerateStruct_VkPhysicalDeviceProperties2(stream_pproperties,
                                                                  pProperties->GetPointer(),
                                                                  pProperties->GetMetaStructPointer(),
                                                                  *this);
    fprintf(file, "%s", stream_pproperties.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceProperties2KHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceProperties2KHR(%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pproperties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pqueue_family_property_count_name = "pQueueFamilyPropertyCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pqueue_family_property_count_name.c_str());
    std::string pqueue_family_properties_name = "pQueueFamilyProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pqueue_family_properties;
    pqueue_family_properties_name = GenerateStruct_VkQueueFamilyProperties2(stream_pqueue_family_properties,
                                                                            pQueueFamilyProperties->GetPointer(),
                                                                            pQueueFamilyProperties->GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pqueue_family_properties.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceQueueFamilyProperties2KHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceQueueFamilyProperties2KHR(%s, &%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pqueue_family_property_count_name.c_str(),
            pqueue_family_properties_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pformat_info;
    std::string pformat_info_struct = GenerateStruct_VkPhysicalDeviceSparseImageFormatInfo2(stream_pformat_info,
                                                                                            pFormatInfo->GetPointer(),
                                                                                            pFormatInfo->GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pformat_info.str().c_str());
    std::string pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pproperty_count_name.c_str());
    std::string pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pproperties;
    pproperties_name = GenerateStruct_VkSparseImageFormatProperties2(stream_pproperties,
                                                                     pProperties->GetPointer(),
                                                                     pProperties->GetMetaStructPointer(),
                                                                     *this);
    fprintf(file, "%s", stream_pproperties.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceSparseImageFormatProperties2KHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(%s, &%s, &%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pformat_info_struct.c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDispatchBaseKHR");
    fprintf(file,
            "\t\tloaded_vkCmdDispatchBaseKHR(%s, %u, %u, %u, %u, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            baseGroupX,
            baseGroupY,
            baseGroupZ,
            groupCountX,
            groupCountY,
            groupCountZ);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR);
}

void VulkanCppConsumer::Process_vkCmdSetDeviceMaskKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetDeviceMaskKHR");
    fprintf(file,
            "\t\tloaded_vkCmdSetDeviceMaskKHR(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            deviceMask);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string ppeer_memory_features_name = "pPeerMemoryFeatures_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tVkPeerMemoryFeatureFlags %s;\n", ppeer_memory_features_name.c_str());
    pfn_loader_.AddMethodName("vkGetDeviceGroupPeerMemoryFeaturesKHR");
    fprintf(file,
            "\t\tloaded_vkGetDeviceGroupPeerMemoryFeaturesKHR(%s, %u, %u, %u, &%s);\n",
            this->GetHandle(device).c_str(),
            heapIndex,
            localDeviceIndex,
            remoteDeviceIndex,
            ppeer_memory_features_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR);
}
void VulkanCppConsumer::Process_vkTrimCommandPoolKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkTrimCommandPoolKHR");
    fprintf(file,
            "\t\tloaded_vkTrimCommandPoolKHR(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(commandPool).c_str(),
            util::ToString<VkCommandPoolTrimFlags>(flags).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pphysical_device_group_count_name = "pPhysicalDeviceGroupCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pphysical_device_group_count_name.c_str());
    std::string pphysical_device_group_properties_name = "pPhysicalDeviceGroupProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pphysical_device_group_properties;
    pphysical_device_group_properties_name = GenerateStruct_VkPhysicalDeviceGroupProperties(stream_pphysical_device_group_properties,
                                                                                            pPhysicalDeviceGroupProperties->GetPointer(),
                                                                                            pPhysicalDeviceGroupProperties->GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pphysical_device_group_properties.str().c_str());
    pfn_loader_.AddMethodName("vkEnumeratePhysicalDeviceGroupsKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkEnumeratePhysicalDeviceGroupsKHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pphysical_device_group_count_name.c_str(),
            pphysical_device_group_properties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR);
}
void VulkanCppConsumer::Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pexternal_buffer_info;
    std::string pexternal_buffer_info_struct = GenerateStruct_VkPhysicalDeviceExternalBufferInfo(stream_pexternal_buffer_info,
                                                                                                 pExternalBufferInfo->GetPointer(),
                                                                                                 pExternalBufferInfo->GetMetaStructPointer(),
                                                                                                 *this);
    fprintf(file, "%s", stream_pexternal_buffer_info.str().c_str());
    std::string pexternal_buffer_properties_name = "pExternalBufferProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pexternal_buffer_properties;
    pexternal_buffer_properties_name = GenerateStruct_VkExternalBufferProperties(stream_pexternal_buffer_properties,
                                                                                 pExternalBufferProperties->GetPointer(),
                                                                                 pExternalBufferProperties->GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_pexternal_buffer_properties.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceExternalBufferPropertiesKHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceExternalBufferPropertiesKHR(%s, &%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pexternal_buffer_info_struct.c_str(),
            pexternal_buffer_properties_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pget_win32_handle_info;
    std::string pget_win32_handle_info_struct = GenerateStruct_VkMemoryGetWin32HandleInfoKHR(stream_pget_win32_handle_info,
                                                                                             pGetWin32HandleInfo->GetPointer(),
                                                                                             pGetWin32HandleInfo->GetMetaStructPointer(),
                                                                                             *this);
    fprintf(file, "%s", stream_pget_win32_handle_info.str().c_str());
    std::string phandle_name = "pHandle_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint8_t* %s;\n", phandle_name.c_str());
    pfn_loader_.AddMethodName("vkGetMemoryWin32HandleKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetMemoryWin32HandleKHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pget_win32_handle_info_struct.c_str(),
            phandle_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string handle_name = "handle_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tvoid* %s;\n", handle_name.c_str());
    std::string pmemory_win32_handle_properties_name = "pMemoryWin32HandleProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pmemory_win32_handle_properties;
    pmemory_win32_handle_properties_name = GenerateStruct_VkMemoryWin32HandlePropertiesKHR(stream_pmemory_win32_handle_properties,
                                                                                           pMemoryWin32HandleProperties->GetPointer(),
                                                                                           pMemoryWin32HandleProperties->GetMetaStructPointer(),
                                                                                           *this);
    fprintf(file, "%s", stream_pmemory_win32_handle_properties.str().c_str());
    pfn_loader_.AddMethodName("vkGetMemoryWin32HandlePropertiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetMemoryWin32HandlePropertiesKHR(%s, %s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkExternalMemoryHandleTypeFlagBits>(handleType).c_str(),
            handle_name.c_str(),
            pmemory_win32_handle_properties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pget_fd_info;
    std::string pget_fd_info_struct = GenerateStruct_VkMemoryGetFdInfoKHR(stream_pget_fd_info,
                                                                          pGetFdInfo->GetPointer(),
                                                                          pGetFdInfo->GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pget_fd_info.str().c_str());
    std::string pfd_name = "pFd_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tint %s;\n", pfd_name.c_str());
    pfn_loader_.AddMethodName("vkGetMemoryFdKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetMemoryFdKHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pget_fd_info_struct.c_str(),
            pfd_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pmemory_fd_properties_name = "pMemoryFdProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pmemory_fd_properties;
    pmemory_fd_properties_name = GenerateStruct_VkMemoryFdPropertiesKHR(stream_pmemory_fd_properties,
                                                                        pMemoryFdProperties->GetPointer(),
                                                                        pMemoryFdProperties->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_pmemory_fd_properties.str().c_str());
    pfn_loader_.AddMethodName("vkGetMemoryFdPropertiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetMemoryFdPropertiesKHR(%s, %s, %d, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkExternalMemoryHandleTypeFlagBits>(handleType).c_str(),
            fd,
            pmemory_fd_properties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR);
}
void VulkanCppConsumer::Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pexternal_semaphore_info;
    std::string pexternal_semaphore_info_struct = GenerateStruct_VkPhysicalDeviceExternalSemaphoreInfo(stream_pexternal_semaphore_info,
                                                                                                       pExternalSemaphoreInfo->GetPointer(),
                                                                                                       pExternalSemaphoreInfo->GetMetaStructPointer(),
                                                                                                       *this);
    fprintf(file, "%s", stream_pexternal_semaphore_info.str().c_str());
    std::string pexternal_semaphore_properties_name = "pExternalSemaphoreProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pexternal_semaphore_properties;
    pexternal_semaphore_properties_name = GenerateStruct_VkExternalSemaphoreProperties(stream_pexternal_semaphore_properties,
                                                                                       pExternalSemaphoreProperties->GetPointer(),
                                                                                       pExternalSemaphoreProperties->GetMetaStructPointer(),
                                                                                       *this);
    fprintf(file, "%s", stream_pexternal_semaphore_properties.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceExternalSemaphorePropertiesKHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(%s, &%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pexternal_semaphore_info_struct.c_str(),
            pexternal_semaphore_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR);
}
void VulkanCppConsumer::Process_vkGetSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    Generate_vkGetSemaphoreWin32HandleKHR(returnValue, device, pGetWin32HandleInfo, pHandle);
    Post_APICall(format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR);
}

void VulkanCppConsumer::Process_vkImportSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo)
{
    Generate_vkImportSemaphoreWin32HandleKHR(returnValue, device, pImportSemaphoreWin32HandleInfo);
    Post_APICall(format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR);
}
void VulkanCppConsumer::Process_vkGetSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    Generate_vkGetSemaphoreFdKHR(returnValue, device, pGetFdInfo, pFd);
    Post_APICall(format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR);
}

void VulkanCppConsumer::Process_vkImportSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo)
{
    Generate_vkImportSemaphoreFdKHR(returnValue, device, pImportSemaphoreFdInfo);
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pdescriptor_writes;
    std::string pdescriptor_writes_array = "NULL";
    PointerPairContainer<decltype(pDescriptorWrites->GetPointer()), decltype(pDescriptorWrites->GetMetaStructPointer())> pdescriptor_writes_pair{ pDescriptorWrites->GetPointer(), pDescriptorWrites->GetMetaStructPointer(), descriptorWriteCount };
    std::string pdescriptor_writes_names = toStringJoin(pdescriptor_writes_pair.begin(),
                                                        pdescriptor_writes_pair.end(),
                                                        [&](auto pair) {{ return GenerateStruct_VkWriteDescriptorSet(stream_pdescriptor_writes, pair.t1, pair.t2, *this); }},
                                                        ", ");
    if (stream_pdescriptor_writes.str().length() > 0) {
        fprintf(file, "%s", stream_pdescriptor_writes.str().c_str());
        if (descriptorWriteCount == 1) {
            pdescriptor_writes_array = "&" + pdescriptor_writes_names;
        } else if (descriptorWriteCount > 1) {
            pdescriptor_writes_array = "pDescriptorWrites_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkWriteDescriptorSet %s[] = { %s };\n", pdescriptor_writes_array.c_str(), pdescriptor_writes_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdPushDescriptorSetKHR");
    fprintf(file,
            "\t\tloaded_vkCmdPushDescriptorSetKHR(%s, %s, %s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineBindPoint>(pipelineBindPoint).c_str(),
            this->GetHandle(layout).c_str(),
            set,
            descriptorWriteCount,
            pdescriptor_writes_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyDescriptorUpdateTemplateKHR");
    fprintf(file,
            "\t\tloaded_vkDestroyDescriptorUpdateTemplateKHR(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(descriptorUpdateTemplate).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR);
}
void VulkanCppConsumer::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_prender_pass_begin;
    std::string prender_pass_begin_struct = GenerateStruct_VkRenderPassBeginInfo(stream_prender_pass_begin,
                                                                                 pRenderPassBegin->GetPointer(),
                                                                                 pRenderPassBegin->GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_prender_pass_begin.str().c_str());
    std::stringstream stream_psubpass_begin_info;
    std::string psubpass_begin_info_struct = GenerateStruct_VkSubpassBeginInfo(stream_psubpass_begin_info,
                                                                               pSubpassBeginInfo->GetPointer(),
                                                                               pSubpassBeginInfo->GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_psubpass_begin_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdBeginRenderPass2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdBeginRenderPass2KHR(%s, &%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            prender_pass_begin_struct.c_str(),
            psubpass_begin_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR);
}

void VulkanCppConsumer::Process_vkCmdEndRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psubpass_end_info;
    std::string psubpass_end_info_struct = GenerateStruct_VkSubpassEndInfo(stream_psubpass_end_info,
                                                                           pSubpassEndInfo->GetPointer(),
                                                                           pSubpassEndInfo->GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_psubpass_end_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdEndRenderPass2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdEndRenderPass2KHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            psubpass_end_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR);
}

void VulkanCppConsumer::Process_vkCmdNextSubpass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psubpass_begin_info;
    std::string psubpass_begin_info_struct = GenerateStruct_VkSubpassBeginInfo(stream_psubpass_begin_info,
                                                                               pSubpassBeginInfo->GetPointer(),
                                                                               pSubpassBeginInfo->GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_psubpass_begin_info.str().c_str());
    std::stringstream stream_psubpass_end_info;
    std::string psubpass_end_info_struct = GenerateStruct_VkSubpassEndInfo(stream_psubpass_end_info,
                                                                           pSubpassEndInfo->GetPointer(),
                                                                           pSubpassEndInfo->GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_psubpass_end_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdNextSubpass2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdNextSubpass2KHR(%s, &%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            psubpass_begin_info_struct.c_str(),
            psubpass_end_info_struct.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkRenderPassCreateInfo2(stream_pcreate_info,
                                                                             pCreateInfo->GetPointer(),
                                                                             pCreateInfo->GetMetaStructPointer(),
                                                                             *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string prender_pass_name = "pRenderPass_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_RENDER_PASS));
    AddKnownVariables("VkRenderPass", prender_pass_name, pRenderPass->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(prender_pass_name,
                         pRenderPass->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateRenderPass2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateRenderPass2KHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            prender_pass_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateRenderPass2KHR);
}
void VulkanCppConsumer::Process_vkGetSwapchainStatusKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkGetSwapchainStatusKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetSwapchainStatusKHR(%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapchain).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR);
}
void VulkanCppConsumer::Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pexternal_fence_info;
    std::string pexternal_fence_info_struct = GenerateStruct_VkPhysicalDeviceExternalFenceInfo(stream_pexternal_fence_info,
                                                                                               pExternalFenceInfo->GetPointer(),
                                                                                               pExternalFenceInfo->GetMetaStructPointer(),
                                                                                               *this);
    fprintf(file, "%s", stream_pexternal_fence_info.str().c_str());
    std::string pexternal_fence_properties_name = "pExternalFenceProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pexternal_fence_properties;
    pexternal_fence_properties_name = GenerateStruct_VkExternalFenceProperties(stream_pexternal_fence_properties,
                                                                               pExternalFenceProperties->GetPointer(),
                                                                               pExternalFenceProperties->GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_pexternal_fence_properties.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceExternalFencePropertiesKHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceExternalFencePropertiesKHR(%s, &%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pexternal_fence_info_struct.c_str(),
            pexternal_fence_properties_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pget_win32_handle_info;
    std::string pget_win32_handle_info_struct = GenerateStruct_VkFenceGetWin32HandleInfoKHR(stream_pget_win32_handle_info,
                                                                                            pGetWin32HandleInfo->GetPointer(),
                                                                                            pGetWin32HandleInfo->GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pget_win32_handle_info.str().c_str());
    std::string phandle_name = "pHandle_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint8_t* %s;\n", phandle_name.c_str());
    pfn_loader_.AddMethodName("vkGetFenceWin32HandleKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetFenceWin32HandleKHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pget_win32_handle_info_struct.c_str(),
            phandle_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR);
}

void VulkanCppConsumer::Process_vkImportFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>* pImportFenceWin32HandleInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pimport_fence_win32_handle_info;
    std::string pimport_fence_win32_handle_info_struct = GenerateStruct_VkImportFenceWin32HandleInfoKHR(stream_pimport_fence_win32_handle_info,
                                                                                                        pImportFenceWin32HandleInfo->GetPointer(),
                                                                                                        pImportFenceWin32HandleInfo->GetMetaStructPointer(),
                                                                                                        *this);
    fprintf(file, "%s", stream_pimport_fence_win32_handle_info.str().c_str());
    pfn_loader_.AddMethodName("vkImportFenceWin32HandleKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkImportFenceWin32HandleKHR(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pimport_fence_win32_handle_info_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pget_fd_info;
    std::string pget_fd_info_struct = GenerateStruct_VkFenceGetFdInfoKHR(stream_pget_fd_info,
                                                                         pGetFdInfo->GetPointer(),
                                                                         pGetFdInfo->GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "%s", stream_pget_fd_info.str().c_str());
    std::string pfd_name = "pFd_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tint %s;\n", pfd_name.c_str());
    pfn_loader_.AddMethodName("vkGetFenceFdKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetFenceFdKHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pget_fd_info_struct.c_str(),
            pfd_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetFenceFdKHR);
}

void VulkanCppConsumer::Process_vkImportFenceFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>* pImportFenceFdInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pimport_fence_fd_info;
    std::string pimport_fence_fd_info_struct = GenerateStruct_VkImportFenceFdInfoKHR(stream_pimport_fence_fd_info,
                                                                                     pImportFenceFdInfo->GetPointer(),
                                                                                     pImportFenceFdInfo->GetMetaStructPointer(),
                                                                                     *this);
    fprintf(file, "%s", stream_pimport_fence_fd_info.str().c_str());
    pfn_loader_.AddMethodName("vkImportFenceFdKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkImportFenceFdKHR(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pimport_fence_fd_info_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkImportFenceFdKHR);
}
void VulkanCppConsumer::Process_vkAcquireProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkAcquireProfilingLockInfoKHR(stream_pinfo,
                                                                            pInfo->GetPointer(),
                                                                            pInfo->GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkAcquireProfilingLockKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkAcquireProfilingLockKHR(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pinfo_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pcounter_count_name = "pCounterCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pcounter_count_name.c_str());
    std::string pcounters_name = "pCounters_" + std::to_string(this->GetNextId());
    std::stringstream stream_pcounters;
    pcounters_name = GenerateStruct_VkPerformanceCounterKHR(stream_pcounters,
                                                            pCounters->GetPointer(),
                                                            pCounters->GetMetaStructPointer(),
                                                            *this);
    fprintf(file, "%s", stream_pcounters.str().c_str());
    std::string pcounter_descriptions_name = "pCounterDescriptions_" + std::to_string(this->GetNextId());
    std::stringstream stream_pcounter_descriptions;
    pcounter_descriptions_name = GenerateStruct_VkPerformanceCounterDescriptionKHR(stream_pcounter_descriptions,
                                                                                   pCounterDescriptions->GetPointer(),
                                                                                   pCounterDescriptions->GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "%s", stream_pcounter_descriptions.str().c_str());
    pfn_loader_.AddMethodName("vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(%s, %u, &%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            queueFamilyIndex,
            pcounter_count_name.c_str(),
            pcounters_name.c_str(),
            pcounter_descriptions_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR>* pPerformanceQueryCreateInfo,
    PointerDecoder<uint32_t>*                   pNumPasses)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pperformance_query_create_info;
    std::string pperformance_query_create_info_struct = GenerateStruct_VkQueryPoolPerformanceCreateInfoKHR(stream_pperformance_query_create_info,
                                                                                                           pPerformanceQueryCreateInfo->GetPointer(),
                                                                                                           pPerformanceQueryCreateInfo->GetMetaStructPointer(),
                                                                                                           *this);
    fprintf(file, "%s", stream_pperformance_query_create_info.str().c_str());
    std::string pnum_passes_name = "pNumPasses_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pnum_passes_name.c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(%s, &%s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pperformance_query_create_info_struct.c_str(),
            pnum_passes_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR);
}

void VulkanCppConsumer::Process_vkReleaseProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkReleaseProfilingLockKHR");
    fprintf(file,
            "\t\tloaded_vkReleaseProfilingLockKHR(%s);\n",
            this->GetHandle(device).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_psurface_info;
    std::string psurface_info_struct = GenerateStruct_VkPhysicalDeviceSurfaceInfo2KHR(stream_psurface_info,
                                                                                      pSurfaceInfo->GetPointer(),
                                                                                      pSurfaceInfo->GetMetaStructPointer(),
                                                                                      *this);
    fprintf(file, "%s", stream_psurface_info.str().c_str());
    std::string psurface_capabilities_name = "pSurfaceCapabilities_" + std::to_string(this->GetNextId());
    std::stringstream stream_psurface_capabilities;
    psurface_capabilities_name = GenerateStruct_VkSurfaceCapabilities2KHR(stream_psurface_capabilities,
                                                                          pSurfaceCapabilities->GetPointer(),
                                                                          pSurfaceCapabilities->GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_psurface_capabilities.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceSurfaceCapabilities2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfaceCapabilities2KHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            psurface_info_struct.c_str(),
            psurface_capabilities_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_psurface_info;
    std::string psurface_info_struct = GenerateStruct_VkPhysicalDeviceSurfaceInfo2KHR(stream_psurface_info,
                                                                                      pSurfaceInfo->GetPointer(),
                                                                                      pSurfaceInfo->GetMetaStructPointer(),
                                                                                      *this);
    fprintf(file, "%s", stream_psurface_info.str().c_str());
    std::string psurface_format_count_name = "pSurfaceFormatCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", psurface_format_count_name.c_str());
    std::string psurface_formats_name = "pSurfaceFormats_" + std::to_string(this->GetNextId());
    std::stringstream stream_psurface_formats;
    psurface_formats_name = GenerateStruct_VkSurfaceFormat2KHR(stream_psurface_formats,
                                                               pSurfaceFormats->GetPointer(),
                                                               pSurfaceFormats->GetMetaStructPointer(),
                                                               *this);
    fprintf(file, "%s", stream_psurface_formats.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceSurfaceFormats2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfaceFormats2KHR(%s, &%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            psurface_info_struct.c_str(),
            psurface_format_count_name.c_str(),
            psurface_formats_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pproperty_count_name.c_str());
    std::string pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pproperties;
    pproperties_name = GenerateStruct_VkDisplayModeProperties2KHR(stream_pproperties,
                                                                  pProperties->GetPointer(),
                                                                  pProperties->GetMetaStructPointer(),
                                                                  *this);
    fprintf(file, "%s", stream_pproperties.str().c_str());
    pfn_loader_.AddMethodName("vkGetDisplayModeProperties2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDisplayModeProperties2KHR(%s, %s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            this->GetHandle(display).c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pdisplay_plane_info;
    std::string pdisplay_plane_info_struct = GenerateStruct_VkDisplayPlaneInfo2KHR(stream_pdisplay_plane_info,
                                                                                   pDisplayPlaneInfo->GetPointer(),
                                                                                   pDisplayPlaneInfo->GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "%s", stream_pdisplay_plane_info.str().c_str());
    std::string pcapabilities_name = "pCapabilities_" + std::to_string(this->GetNextId());
    std::stringstream stream_pcapabilities;
    pcapabilities_name = GenerateStruct_VkDisplayPlaneCapabilities2KHR(stream_pcapabilities,
                                                                       pCapabilities->GetPointer(),
                                                                       pCapabilities->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "%s", stream_pcapabilities.str().c_str());
    pfn_loader_.AddMethodName("vkGetDisplayPlaneCapabilities2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDisplayPlaneCapabilities2KHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pdisplay_plane_info_struct.c_str(),
            pcapabilities_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pproperty_count_name.c_str());
    std::string pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pproperties;
    pproperties_name = GenerateStruct_VkDisplayPlaneProperties2KHR(stream_pproperties,
                                                                   pProperties->GetPointer(),
                                                                   pProperties->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "%s", stream_pproperties.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pproperty_count_name.c_str());
    std::string pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pproperties;
    pproperties_name = GenerateStruct_VkDisplayProperties2KHR(stream_pproperties,
                                                              pProperties->GetPointer(),
                                                              pProperties->GetMetaStructPointer(),
                                                              *this);
    fprintf(file, "%s", stream_pproperties.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceDisplayProperties2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceDisplayProperties2KHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkImageSparseMemoryRequirementsInfo2(stream_pinfo,
                                                                                   pInfo->GetPointer(),
                                                                                   pInfo->GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string psparse_memory_requirement_count_name = "pSparseMemoryRequirementCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", psparse_memory_requirement_count_name.c_str());
    std::string psparse_memory_requirements_name = "pSparseMemoryRequirements_" + std::to_string(this->GetNextId());
    std::stringstream stream_psparse_memory_requirements;
    psparse_memory_requirements_name = GenerateStruct_VkSparseImageMemoryRequirements2(stream_psparse_memory_requirements,
                                                                                       pSparseMemoryRequirements->GetPointer(),
                                                                                       pSparseMemoryRequirements->GetMetaStructPointer(),
                                                                                       *this);
    fprintf(file, "%s", stream_psparse_memory_requirements.str().c_str());
    pfn_loader_.AddMethodName("vkGetImageSparseMemoryRequirements2KHR");
    fprintf(file,
            "\t\tloaded_vkGetImageSparseMemoryRequirements2KHR(%s, &%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pinfo_struct.c_str(),
            psparse_memory_requirement_count_name.c_str(),
            psparse_memory_requirements_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkSamplerYcbcrConversionCreateInfo(stream_pcreate_info,
                                                                                        pCreateInfo->GetPointer(),
                                                                                        pCreateInfo->GetMetaStructPointer(),
                                                                                        *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pycbcr_conversion_name = "pYcbcrConversion_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION));
    AddKnownVariables("VkSamplerYcbcrConversion", pycbcr_conversion_name, pYcbcrConversion->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pycbcr_conversion_name,
                         pYcbcrConversion->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateSamplerYcbcrConversionKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateSamplerYcbcrConversionKHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pycbcr_conversion_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR);
}

void VulkanCppConsumer::Process_vkDestroySamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroySamplerYcbcrConversionKHR");
    fprintf(file,
            "\t\tloaded_vkDestroySamplerYcbcrConversionKHR(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(ycbcrConversion).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR);
}
void VulkanCppConsumer::Process_vkBindBufferMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    Intercept_vkBindBufferMemory2KHR(returnValue, device, bindInfoCount, pBindInfos);
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbind_infos;
    std::string pbind_infos_array = "NULL";
    PointerPairContainer<decltype(pBindInfos->GetPointer()), decltype(pBindInfos->GetMetaStructPointer())> pbind_infos_pair{ pBindInfos->GetPointer(), pBindInfos->GetMetaStructPointer(), bindInfoCount };
    std::string pbind_infos_names = toStringJoin(pbind_infos_pair.begin(),
                                                 pbind_infos_pair.end(),
                                                 [&](auto pair) {{ return GenerateStruct_VkBindBufferMemoryInfo(stream_pbind_infos, pair.t1, pair.t2, *this); }},
                                                 ", ");
    if (stream_pbind_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pbind_infos.str().c_str());
        if (bindInfoCount == 1) {
            pbind_infos_array = "&" + pbind_infos_names;
        } else if (bindInfoCount > 1) {
            pbind_infos_array = "pBindInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBindBufferMemoryInfo %s[] = { %s };\n", pbind_infos_array.c_str(), pbind_infos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkBindBufferMemory2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkBindBufferMemory2KHR(%s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            bindInfoCount,
            pbind_infos_array.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindBufferMemory2KHR);
}

void VulkanCppConsumer::Process_vkBindImageMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    Intercept_vkBindImageMemory2KHR(returnValue, device, bindInfoCount, pBindInfos);
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbind_infos;
    std::string pbind_infos_array = "NULL";
    PointerPairContainer<decltype(pBindInfos->GetPointer()), decltype(pBindInfos->GetMetaStructPointer())> pbind_infos_pair{ pBindInfos->GetPointer(), pBindInfos->GetMetaStructPointer(), bindInfoCount };
    std::string pbind_infos_names = toStringJoin(pbind_infos_pair.begin(),
                                                 pbind_infos_pair.end(),
                                                 [&](auto pair) {{ return GenerateStruct_VkBindImageMemoryInfo(stream_pbind_infos, pair.t1, pair.t2, *this); }},
                                                 ", ");
    if (stream_pbind_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pbind_infos.str().c_str());
        if (bindInfoCount == 1) {
            pbind_infos_array = "&" + pbind_infos_names;
        } else if (bindInfoCount > 1) {
            pbind_infos_array = "pBindInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBindImageMemoryInfo %s[] = { %s };\n", pbind_infos_array.c_str(), pbind_infos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkBindImageMemory2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkBindImageMemory2KHR(%s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            bindInfoCount,
            pbind_infos_array.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindImageMemory2KHR);
}
void VulkanCppConsumer::Process_vkGetDescriptorSetLayoutSupportKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkDescriptorSetLayoutCreateInfo(stream_pcreate_info,
                                                                                     pCreateInfo->GetPointer(),
                                                                                     pCreateInfo->GetMetaStructPointer(),
                                                                                     *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psupport_name = "pSupport_" + std::to_string(this->GetNextId());
    std::stringstream stream_psupport;
    psupport_name = GenerateStruct_VkDescriptorSetLayoutSupport(stream_psupport,
                                                                pSupport->GetPointer(),
                                                                pSupport->GetMetaStructPointer(),
                                                                *this);
    fprintf(file, "%s", stream_psupport.str().c_str());
    pfn_loader_.AddMethodName("vkGetDescriptorSetLayoutSupportKHR");
    fprintf(file,
            "\t\tloaded_vkGetDescriptorSetLayoutSupportKHR(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            psupport_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawIndexedIndirectCountKHR");
    fprintf(file,
            "\t\tloaded_vkCmdDrawIndexedIndirectCountKHR(%s, %s, %" PRIu64 "UL, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            this->GetHandle(countBuffer).c_str(),
            countBufferOffset,
            maxDrawCount,
            stride);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawIndirectCountKHR");
    fprintf(file,
            "\t\tloaded_vkCmdDrawIndirectCountKHR(%s, %s, %" PRIu64 "UL, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            this->GetHandle(countBuffer).c_str(),
            countBufferOffset,
            maxDrawCount,
            stride);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pvalue_name = "pValue_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint64_t %s;\n", pvalue_name.c_str());
    pfn_loader_.AddMethodName("vkGetSemaphoreCounterValueKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetSemaphoreCounterValueKHR(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(semaphore).c_str(),
            pvalue_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR);
}

void VulkanCppConsumer::Process_vkSignalSemaphoreKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psignal_info;
    std::string psignal_info_struct = GenerateStruct_VkSemaphoreSignalInfo(stream_psignal_info,
                                                                           pSignalInfo->GetPointer(),
                                                                           pSignalInfo->GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_psignal_info.str().c_str());
    pfn_loader_.AddMethodName("vkSignalSemaphoreKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkSignalSemaphoreKHR(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            psignal_info_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pwait_info;
    std::string pwait_info_struct = GenerateStruct_VkSemaphoreWaitInfo(stream_pwait_info,
                                                                       pWaitInfo->GetPointer(),
                                                                       pWaitInfo->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "%s", stream_pwait_info.str().c_str());
    pfn_loader_.AddMethodName("vkWaitSemaphoresKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkWaitSemaphoresKHR(%s, &%s, %" PRIu64 "UL), %s);\n",
            this->GetHandle(device).c_str(),
            pwait_info_struct.c_str(),
            timeout,
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkWaitSemaphoresKHR);
}
void VulkanCppConsumer::Process_vkCmdSetFragmentShadingRateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkExtent2D>*   pFragmentSize,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pfragment_size;
    std::string pfragment_size_struct = GenerateStruct_VkExtent2D(stream_pfragment_size,
                                                                  pFragmentSize->GetPointer(),
                                                                  pFragmentSize->GetMetaStructPointer(),
                                                                  *this);
    fprintf(file, "%s", stream_pfragment_size.str().c_str());
    std::string combiner_ops_array = "NULL";
    std::string combiner_ops_values = toStringJoin(combinerOps->GetPointer(),
                                                   combinerOps->GetPointer() + 2,
                                                   [&](const format::HandleId current) { return this->GetHandle(current); },
                                                   ", ");
    fprintf(file, "\t\tVkFragmentShadingRateCombinerOpKHR %s[] = { %s };\n", combiner_ops_array.c_str(), combiner_ops_values.c_str());
    pfn_loader_.AddMethodName("vkCmdSetFragmentShadingRateKHR");
    fprintf(file,
            "\t\tloaded_vkCmdSetFragmentShadingRateKHR(%s, &%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pfragment_size_struct.c_str(),
            combiner_ops_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pfragment_shading_rate_count_name = "pFragmentShadingRateCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pfragment_shading_rate_count_name.c_str());
    std::string pfragment_shading_rates_name = "pFragmentShadingRates_" + std::to_string(this->GetNextId());
    std::stringstream stream_pfragment_shading_rates;
    pfragment_shading_rates_name = GenerateStruct_VkPhysicalDeviceFragmentShadingRateKHR(stream_pfragment_shading_rates,
                                                                                         pFragmentShadingRates->GetPointer(),
                                                                                         pFragmentShadingRates->GetMetaStructPointer(),
                                                                                         *this);
    fprintf(file, "%s", stream_pfragment_shading_rates.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceFragmentShadingRatesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceFragmentShadingRatesKHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pfragment_shading_rate_count_name.c_str(),
            pfragment_shading_rates_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR);
}
void VulkanCppConsumer::Process_vkCmdSetRenderingAttachmentLocationsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingAttachmentLocationInfoKHR>* pLocationInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_plocation_info;
    std::string plocation_info_struct = GenerateStruct_VkRenderingAttachmentLocationInfoKHR(stream_plocation_info,
                                                                                            pLocationInfo->GetPointer(),
                                                                                            pLocationInfo->GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_plocation_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdSetRenderingAttachmentLocationsKHR");
    fprintf(file,
            "\t\tloaded_vkCmdSetRenderingAttachmentLocationsKHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            plocation_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRenderingAttachmentLocationsKHR);
}

void VulkanCppConsumer::Process_vkCmdSetRenderingInputAttachmentIndicesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInputAttachmentIndexInfoKHR>* pInputAttachmentIndexInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinput_attachment_index_info;
    std::string pinput_attachment_index_info_struct = GenerateStruct_VkRenderingInputAttachmentIndexInfoKHR(stream_pinput_attachment_index_info,
                                                                                                            pInputAttachmentIndexInfo->GetPointer(),
                                                                                                            pInputAttachmentIndexInfo->GetMetaStructPointer(),
                                                                                                            *this);
    fprintf(file, "%s", stream_pinput_attachment_index_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdSetRenderingInputAttachmentIndicesKHR");
    fprintf(file,
            "\t\tloaded_vkCmdSetRenderingInputAttachmentIndicesKHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pinput_attachment_index_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRenderingInputAttachmentIndicesKHR);
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkWaitForPresentKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkWaitForPresentKHR(%s, %s, %" PRIu64 "UL, %" PRIu64 "UL), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapchain).c_str(),
            presentId,
            timeout,
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkWaitForPresentKHR);
}
void VulkanCppConsumer::Process_vkGetBufferDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkBufferDeviceAddressInfo(stream_pinfo,
                                                                        pInfo->GetPointer(),
                                                                        pInfo->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkGetBufferDeviceAddressKHR");
    fprintf(file,
            "\t\tloaded_vkGetBufferDeviceAddressKHR(%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR);
}

void VulkanCppConsumer::Process_vkGetBufferOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkBufferDeviceAddressInfo(stream_pinfo,
                                                                        pInfo->GetPointer(),
                                                                        pInfo->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkGetBufferOpaqueCaptureAddressKHR");
    fprintf(file,
            "\t\tloaded_vkGetBufferOpaqueCaptureAddressKHR(%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR);
}

void VulkanCppConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDeviceMemoryOpaqueCaptureAddressInfo(stream_pinfo,
                                                                                     pInfo->GetPointer(),
                                                                                     pInfo->GetMetaStructPointer(),
                                                                                     *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkGetDeviceMemoryOpaqueCaptureAddressKHR");
    fprintf(file,
            "\t\tloaded_vkGetDeviceMemoryOpaqueCaptureAddressKHR(%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pdeferred_operation_name = "pDeferredOperation_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR));
    AddKnownVariables("VkDeferredOperationKHR", pdeferred_operation_name, pDeferredOperation->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pdeferred_operation_name,
                         pDeferredOperation->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateDeferredOperationKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateDeferredOperationKHR(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            "nullptr",
            pdeferred_operation_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR);
}

void VulkanCppConsumer::Process_vkDeferredOperationJoinKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDeferredOperationJoinKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkDeferredOperationJoinKHR(%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(operation).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR);
}

void VulkanCppConsumer::Process_vkDestroyDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            operation,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyDeferredOperationKHR");
    fprintf(file,
            "\t\tloaded_vkDestroyDeferredOperationKHR(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(operation).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR);
}

void VulkanCppConsumer::Process_vkGetDeferredOperationMaxConcurrencyKHR(
    const ApiCallInfo&                          call_info,
    uint32_t                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkGetDeferredOperationMaxConcurrencyKHR");
    fprintf(file,
            "\t\tloaded_vkGetDeferredOperationMaxConcurrencyKHR(%s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(operation).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR);
}

void VulkanCppConsumer::Process_vkGetDeferredOperationResultKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkGetDeferredOperationResultKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDeferredOperationResultKHR(%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(operation).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pexecutable_info;
    std::string pexecutable_info_struct = GenerateStruct_VkPipelineExecutableInfoKHR(stream_pexecutable_info,
                                                                                     pExecutableInfo->GetPointer(),
                                                                                     pExecutableInfo->GetMetaStructPointer(),
                                                                                     *this);
    fprintf(file, "%s", stream_pexecutable_info.str().c_str());
    std::string pinternal_representation_count_name = "pInternalRepresentationCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pinternal_representation_count_name.c_str());
    std::string pinternal_representations_name = "pInternalRepresentations_" + std::to_string(this->GetNextId());
    std::stringstream stream_pinternal_representations;
    pinternal_representations_name = GenerateStruct_VkPipelineExecutableInternalRepresentationKHR(stream_pinternal_representations,
                                                                                                  pInternalRepresentations->GetPointer(),
                                                                                                  pInternalRepresentations->GetMetaStructPointer(),
                                                                                                  *this);
    fprintf(file, "%s", stream_pinternal_representations.str().c_str());
    pfn_loader_.AddMethodName("vkGetPipelineExecutableInternalRepresentationsKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPipelineExecutableInternalRepresentationsKHR(%s, &%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pexecutable_info_struct.c_str(),
            pinternal_representation_count_name.c_str(),
            pinternal_representations_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_ppipeline_info;
    std::string ppipeline_info_struct = GenerateStruct_VkPipelineInfoKHR(stream_ppipeline_info,
                                                                         pPipelineInfo->GetPointer(),
                                                                         pPipelineInfo->GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "%s", stream_ppipeline_info.str().c_str());
    std::string pexecutable_count_name = "pExecutableCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pexecutable_count_name.c_str());
    std::string pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pproperties;
    pproperties_name = GenerateStruct_VkPipelineExecutablePropertiesKHR(stream_pproperties,
                                                                        pProperties->GetPointer(),
                                                                        pProperties->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_pproperties.str().c_str());
    pfn_loader_.AddMethodName("vkGetPipelineExecutablePropertiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPipelineExecutablePropertiesKHR(%s, &%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            ppipeline_info_struct.c_str(),
            pexecutable_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pexecutable_info;
    std::string pexecutable_info_struct = GenerateStruct_VkPipelineExecutableInfoKHR(stream_pexecutable_info,
                                                                                     pExecutableInfo->GetPointer(),
                                                                                     pExecutableInfo->GetMetaStructPointer(),
                                                                                     *this);
    fprintf(file, "%s", stream_pexecutable_info.str().c_str());
    std::string pstatistic_count_name = "pStatisticCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pstatistic_count_name.c_str());
    std::string pstatistics_name = "pStatistics_" + std::to_string(this->GetNextId());
    std::stringstream stream_pstatistics;
    pstatistics_name = GenerateStruct_VkPipelineExecutableStatisticKHR(stream_pstatistics,
                                                                       pStatistics->GetPointer(),
                                                                       pStatistics->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "%s", stream_pstatistics.str().c_str());
    pfn_loader_.AddMethodName("vkGetPipelineExecutableStatisticsKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPipelineExecutableStatisticsKHR(%s, &%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pexecutable_info_struct.c_str(),
            pstatistic_count_name.c_str(),
            pstatistics_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pmemory_map_info;
    std::string pmemory_map_info_struct = GenerateStruct_VkMemoryMapInfoKHR(stream_pmemory_map_info,
                                                                            pMemoryMapInfo->GetPointer(),
                                                                            pMemoryMapInfo->GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pmemory_map_info.str().c_str());
    std::string pp_data_name = "ppData_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint8_t* %s;\n", pp_data_name.c_str());
    pfn_loader_.AddMethodName("vkMapMemory2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkMapMemory2KHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pmemory_map_info_struct.c_str(),
            pp_data_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkMapMemory2KHR);
}

void VulkanCppConsumer::Process_vkUnmapMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryUnmapInfoKHR>* pMemoryUnmapInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pmemory_unmap_info;
    std::string pmemory_unmap_info_struct = GenerateStruct_VkMemoryUnmapInfoKHR(stream_pmemory_unmap_info,
                                                                                pMemoryUnmapInfo->GetPointer(),
                                                                                pMemoryUnmapInfo->GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_pmemory_unmap_info.str().c_str());
    pfn_loader_.AddMethodName("vkUnmapMemory2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkUnmapMemory2KHR(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pmemory_unmap_info_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkUnmapMemory2KHR);
}
void VulkanCppConsumer::Process_vkCmdEncodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR>* pEncodeInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pencode_info;
    std::string pencode_info_struct = GenerateStruct_VkVideoEncodeInfoKHR(stream_pencode_info,
                                                                          pEncodeInfo->GetPointer(),
                                                                          pEncodeInfo->GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pencode_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdEncodeVideoKHR");
    fprintf(file,
            "\t\tloaded_vkCmdEncodeVideoKHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pencode_info_struct.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pvideo_session_parameters_info;
    std::string pvideo_session_parameters_info_struct = GenerateStruct_VkVideoEncodeSessionParametersGetInfoKHR(stream_pvideo_session_parameters_info,
                                                                                                                pVideoSessionParametersInfo->GetPointer(),
                                                                                                                pVideoSessionParametersInfo->GetMetaStructPointer(),
                                                                                                                *this);
    fprintf(file, "%s", stream_pvideo_session_parameters_info.str().c_str());
    std::string pfeedback_info_name = "pFeedbackInfo_" + std::to_string(this->GetNextId());
    std::stringstream stream_pfeedback_info;
    pfeedback_info_name = GenerateStruct_VkVideoEncodeSessionParametersFeedbackInfoKHR(stream_pfeedback_info,
                                                                                       pFeedbackInfo->GetPointer(),
                                                                                       pFeedbackInfo->GetMetaStructPointer(),
                                                                                       *this);
    fprintf(file, "%s", stream_pfeedback_info.str().c_str());
    std::string pdata_size_name = "pDataSize_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tsize_t %s;\n", pdata_size_name.c_str());
    std::string pdata_name = "pData_" + std::to_string(this->GetNextId());
    size_t* in_pdata_size = pDataSize->GetPointer();
    fprintf(file, "\t\tuint8_t %s[%" PRIu64 "];\n", pdata_name.c_str(), util::platform::SizeTtoUint64(*in_pdata_size));
    pfn_loader_.AddMethodName("vkGetEncodedVideoSessionParametersKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetEncodedVideoSessionParametersKHR(%s, &%s, &%s, &%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            pvideo_session_parameters_info_struct.c_str(),
            pfeedback_info_name.c_str(),
            pdata_size_name.c_str(),
            pdata_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pquality_level_info;
    std::string pquality_level_info_struct = GenerateStruct_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR(stream_pquality_level_info,
                                                                                                           pQualityLevelInfo->GetPointer(),
                                                                                                           pQualityLevelInfo->GetMetaStructPointer(),
                                                                                                           *this);
    fprintf(file, "%s", stream_pquality_level_info.str().c_str());
    std::string pquality_level_properties_name = "pQualityLevelProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pquality_level_properties;
    pquality_level_properties_name = GenerateStruct_VkVideoEncodeQualityLevelPropertiesKHR(stream_pquality_level_properties,
                                                                                           pQualityLevelProperties->GetPointer(),
                                                                                           pQualityLevelProperties->GetMetaStructPointer(),
                                                                                           *this);
    fprintf(file, "%s", stream_pquality_level_properties.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pquality_level_info_struct.c_str(),
            pquality_level_properties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR);
}
void VulkanCppConsumer::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdependency_info;
    std::string pdependency_info_struct = GenerateStruct_VkDependencyInfo(stream_pdependency_info,
                                                                          pDependencyInfo->GetPointer(),
                                                                          pDependencyInfo->GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pdependency_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdPipelineBarrier2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdPipelineBarrier2KHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pdependency_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR);
}

void VulkanCppConsumer::Process_vkCmdResetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdResetEvent2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdResetEvent2KHR(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(event).c_str(),
            util::ToString<VkPipelineStageFlags2>(stageMask).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResetEvent2KHR);
}

void VulkanCppConsumer::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdependency_info;
    std::string pdependency_info_struct = GenerateStruct_VkDependencyInfo(stream_pdependency_info,
                                                                          pDependencyInfo->GetPointer(),
                                                                          pDependencyInfo->GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pdependency_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdSetEvent2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdSetEvent2KHR(%s, %s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(event).c_str(),
            pdependency_info_struct.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pevents_array = "NULL";
    std::string pevents_values = toStringJoin(pEvents->GetPointer(),
                                              pEvents->GetPointer() + eventCount,
                                              [&](const format::HandleId current) { return this->GetHandle(current); },
                                              ", ");
    if (eventCount == 1 && pevents_values != "VK_NULL_HANDLE") {
        pevents_array = "&" + pevents_values;
    } else if (eventCount > 1) {
        pevents_array = "pevents_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkEvent %s[] = { %s };\n", pevents_array.c_str(), pevents_values.c_str());
    }
    std::stringstream stream_pdependency_infos;
    std::string pdependency_infos_array = "NULL";
    PointerPairContainer<decltype(pDependencyInfos->GetPointer()), decltype(pDependencyInfos->GetMetaStructPointer())> pdependency_infos_pair{ pDependencyInfos->GetPointer(), pDependencyInfos->GetMetaStructPointer(), eventCount };
    std::string pdependency_infos_names = toStringJoin(pdependency_infos_pair.begin(),
                                                       pdependency_infos_pair.end(),
                                                       [&](auto pair) {{ return GenerateStruct_VkDependencyInfo(stream_pdependency_infos, pair.t1, pair.t2, *this); }},
                                                       ", ");
    if (stream_pdependency_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pdependency_infos.str().c_str());
        if (eventCount == 1) {
            pdependency_infos_array = "&" + pdependency_infos_names;
        } else if (eventCount > 1) {
            pdependency_infos_array = "pDependencyInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkDependencyInfo %s[] = { %s };\n", pdependency_infos_array.c_str(), pdependency_infos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdWaitEvents2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdWaitEvents2KHR(%s, %u, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            eventCount,
            pevents_array.c_str(),
            pdependency_infos_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdWriteBufferMarker2AMD");
    fprintf(file,
            "\t\tloaded_vkCmdWriteBufferMarker2AMD(%s, %s, %s, %" PRIu64 "UL, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineStageFlags2>(stage).c_str(),
            this->GetHandle(dstBuffer).c_str(),
            dstOffset,
            marker);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdWriteTimestamp2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdWriteTimestamp2KHR(%s, %s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineStageFlags2>(stage).c_str(),
            this->GetHandle(queryPool).c_str(),
            query);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR);
}

void VulkanCppConsumer::Process_vkGetQueueCheckpointData2NV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointData2NV>* pCheckpointData)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcheckpoint_data_count_name = "pCheckpointDataCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pcheckpoint_data_count_name.c_str());
    std::string pcheckpoint_data_name = "pCheckpointData_" + std::to_string(this->GetNextId());
    std::stringstream stream_pcheckpoint_data;
    pcheckpoint_data_name = GenerateStruct_VkCheckpointData2NV(stream_pcheckpoint_data,
                                                               pCheckpointData->GetPointer(),
                                                               pCheckpointData->GetMetaStructPointer(),
                                                               *this);
    fprintf(file, "%s", stream_pcheckpoint_data.str().c_str());
    pfn_loader_.AddMethodName("vkGetQueueCheckpointData2NV");
    fprintf(file,
            "\t\tloaded_vkGetQueueCheckpointData2NV(%s, &%s, &%s);\n",
            this->GetHandle(queue).c_str(),
            pcheckpoint_data_count_name.c_str(),
            pcheckpoint_data_name.c_str());
    fprintf(file, "\t}\n");
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
    Generate_vkQueueSubmit2KHR(returnValue, queue, submitCount, pSubmits, fence);
    Post_APICall(format::ApiCallId::ApiCall_vkQueueSubmit2KHR);
}
void VulkanCppConsumer::Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pblit_image_info;
    std::string pblit_image_info_struct = GenerateStruct_VkBlitImageInfo2(stream_pblit_image_info,
                                                                          pBlitImageInfo->GetPointer(),
                                                                          pBlitImageInfo->GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pblit_image_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdBlitImage2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdBlitImage2KHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pblit_image_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBlitImage2KHR);
}

void VulkanCppConsumer::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_buffer_info;
    std::string pcopy_buffer_info_struct = GenerateStruct_VkCopyBufferInfo2(stream_pcopy_buffer_info,
                                                                            pCopyBufferInfo->GetPointer(),
                                                                            pCopyBufferInfo->GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pcopy_buffer_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyBuffer2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdCopyBuffer2KHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pcopy_buffer_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR);
}

void VulkanCppConsumer::Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_buffer_to_image_info;
    std::string pcopy_buffer_to_image_info_struct = GenerateStruct_VkCopyBufferToImageInfo2(stream_pcopy_buffer_to_image_info,
                                                                                            pCopyBufferToImageInfo->GetPointer(),
                                                                                            pCopyBufferToImageInfo->GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pcopy_buffer_to_image_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyBufferToImage2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdCopyBufferToImage2KHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pcopy_buffer_to_image_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR);
}

void VulkanCppConsumer::Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_image_info;
    std::string pcopy_image_info_struct = GenerateStruct_VkCopyImageInfo2(stream_pcopy_image_info,
                                                                          pCopyImageInfo->GetPointer(),
                                                                          pCopyImageInfo->GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pcopy_image_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyImage2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdCopyImage2KHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pcopy_image_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImage2KHR);
}

void VulkanCppConsumer::Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_image_to_buffer_info;
    std::string pcopy_image_to_buffer_info_struct = GenerateStruct_VkCopyImageToBufferInfo2(stream_pcopy_image_to_buffer_info,
                                                                                            pCopyImageToBufferInfo->GetPointer(),
                                                                                            pCopyImageToBufferInfo->GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pcopy_image_to_buffer_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyImageToBuffer2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdCopyImageToBuffer2KHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pcopy_image_to_buffer_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR);
}

void VulkanCppConsumer::Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_presolve_image_info;
    std::string presolve_image_info_struct = GenerateStruct_VkResolveImageInfo2(stream_presolve_image_info,
                                                                                pResolveImageInfo->GetPointer(),
                                                                                pResolveImageInfo->GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_presolve_image_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdResolveImage2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdResolveImage2KHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            presolve_image_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResolveImage2KHR);
}
void VulkanCppConsumer::Process_vkCmdTraceRaysIndirect2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdTraceRaysIndirect2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdTraceRaysIndirect2KHR(%s, %" PRIu64 "UL);\n",
            this->GetHandle(commandBuffer).c_str(),
            indirectDeviceAddress);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR);
}
void VulkanCppConsumer::Process_vkGetDeviceBufferMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDeviceBufferMemoryRequirements(stream_pinfo,
                                                                               pInfo->GetPointer(),
                                                                               pInfo->GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string pmemory_requirements_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
    std::stringstream stream_pmemory_requirements;
    pmemory_requirements_name = GenerateStruct_VkMemoryRequirements2(stream_pmemory_requirements,
                                                                     pMemoryRequirements->GetPointer(),
                                                                     pMemoryRequirements->GetMetaStructPointer(),
                                                                     *this);
    fprintf(file, "%s", stream_pmemory_requirements.str().c_str());
    pfn_loader_.AddMethodName("vkGetDeviceBufferMemoryRequirementsKHR");
    fprintf(file,
            "\t\tloaded_vkGetDeviceBufferMemoryRequirementsKHR(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pinfo_struct.c_str(),
            pmemory_requirements_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR);
}

void VulkanCppConsumer::Process_vkGetDeviceImageMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDeviceImageMemoryRequirements(stream_pinfo,
                                                                              pInfo->GetPointer(),
                                                                              pInfo->GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string pmemory_requirements_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
    std::stringstream stream_pmemory_requirements;
    pmemory_requirements_name = GenerateStruct_VkMemoryRequirements2(stream_pmemory_requirements,
                                                                     pMemoryRequirements->GetPointer(),
                                                                     pMemoryRequirements->GetMetaStructPointer(),
                                                                     *this);
    fprintf(file, "%s", stream_pmemory_requirements.str().c_str());
    pfn_loader_.AddMethodName("vkGetDeviceImageMemoryRequirementsKHR");
    fprintf(file,
            "\t\tloaded_vkGetDeviceImageMemoryRequirementsKHR(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pinfo_struct.c_str(),
            pmemory_requirements_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDeviceImageMemoryRequirements(stream_pinfo,
                                                                              pInfo->GetPointer(),
                                                                              pInfo->GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string psparse_memory_requirement_count_name = "pSparseMemoryRequirementCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", psparse_memory_requirement_count_name.c_str());
    std::string psparse_memory_requirements_name = "pSparseMemoryRequirements_" + std::to_string(this->GetNextId());
    std::stringstream stream_psparse_memory_requirements;
    psparse_memory_requirements_name = GenerateStruct_VkSparseImageMemoryRequirements2(stream_psparse_memory_requirements,
                                                                                       pSparseMemoryRequirements->GetPointer(),
                                                                                       pSparseMemoryRequirements->GetMetaStructPointer(),
                                                                                       *this);
    fprintf(file, "%s", stream_psparse_memory_requirements.str().c_str());
    pfn_loader_.AddMethodName("vkGetDeviceImageSparseMemoryRequirementsKHR");
    fprintf(file,
            "\t\tloaded_vkGetDeviceImageSparseMemoryRequirementsKHR(%s, &%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pinfo_struct.c_str(),
            psparse_memory_requirement_count_name.c_str(),
            psparse_memory_requirements_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdBindIndexBuffer2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdBindIndexBuffer2KHR(%s, %s, %" PRIu64 "UL, %" PRIu64 "UL, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            size,
            util::ToString<VkIndexType>(indexType).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindIndexBuffer2KHR);
}

void VulkanCppConsumer::Process_vkGetDeviceImageSubresourceLayoutKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageSubresourceInfoKHR>* pInfo,
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR>* pLayout)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDeviceImageSubresourceInfoKHR(stream_pinfo,
                                                                              pInfo->GetPointer(),
                                                                              pInfo->GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string playout_name = "pLayout_" + std::to_string(this->GetNextId());
    std::stringstream stream_playout;
    playout_name = GenerateStruct_VkSubresourceLayout2KHR(stream_playout,
                                                          pLayout->GetPointer(),
                                                          pLayout->GetMetaStructPointer(),
                                                          *this);
    fprintf(file, "%s", stream_playout.str().c_str());
    pfn_loader_.AddMethodName("vkGetDeviceImageSubresourceLayoutKHR");
    fprintf(file,
            "\t\tloaded_vkGetDeviceImageSubresourceLayoutKHR(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pinfo_struct.c_str(),
            playout_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_psubresource;
    std::string psubresource_struct = GenerateStruct_VkImageSubresource2KHR(stream_psubresource,
                                                                            pSubresource->GetPointer(),
                                                                            pSubresource->GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_psubresource.str().c_str());
    std::string playout_name = "pLayout_" + std::to_string(this->GetNextId());
    std::stringstream stream_playout;
    playout_name = GenerateStruct_VkSubresourceLayout2KHR(stream_playout,
                                                          pLayout->GetPointer(),
                                                          pLayout->GetMetaStructPointer(),
                                                          *this);
    fprintf(file, "%s", stream_playout.str().c_str());
    pfn_loader_.AddMethodName("vkGetImageSubresourceLayout2KHR");
    fprintf(file,
            "\t\tloaded_vkGetImageSubresourceLayout2KHR(%s, %s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(image).c_str(),
            psubresource_struct.c_str(),
            playout_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2KHR);
}

void VulkanCppConsumer::Process_vkGetRenderingAreaGranularityKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderingAreaInfoKHR>* pRenderingAreaInfo,
    StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_prendering_area_info;
    std::string prendering_area_info_struct = GenerateStruct_VkRenderingAreaInfoKHR(stream_prendering_area_info,
                                                                                    pRenderingAreaInfo->GetPointer(),
                                                                                    pRenderingAreaInfo->GetMetaStructPointer(),
                                                                                    *this);
    fprintf(file, "%s", stream_prendering_area_info.str().c_str());
    std::string pgranularity_name = "pGranularity_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tVkExtent2D %s;\n", pgranularity_name.c_str());
    pfn_loader_.AddMethodName("vkGetRenderingAreaGranularityKHR");
    fprintf(file,
            "\t\tloaded_vkGetRenderingAreaGranularityKHR(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            prendering_area_info_struct.c_str(),
            pgranularity_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pproperty_count_name.c_str());
    std::string pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pproperties;
    pproperties_name = GenerateStruct_VkCooperativeMatrixPropertiesKHR(stream_pproperties,
                                                                       pProperties->GetPointer(),
                                                                       pProperties->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "%s", stream_pproperties.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR);
}
void VulkanCppConsumer::Process_vkCmdSetLineStippleKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetLineStippleKHR");
    fprintf(file,
            "\t\tloaded_vkCmdSetLineStippleKHR(%s, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            lineStippleFactor,
            lineStipplePattern);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLineStippleKHR);
}
void VulkanCppConsumer::Process_vkGetCalibratedTimestampsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    timestampCount,
    StructPointerDecoder<Decoded_VkCalibratedTimestampInfoKHR>* pTimestampInfos,
    PointerDecoder<uint64_t>*                   pTimestamps,
    PointerDecoder<uint64_t>*                   pMaxDeviation)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_ptimestamp_infos;
    std::string ptimestamp_infos_array = "NULL";
    PointerPairContainer<decltype(pTimestampInfos->GetPointer()), decltype(pTimestampInfos->GetMetaStructPointer())> ptimestamp_infos_pair{ pTimestampInfos->GetPointer(), pTimestampInfos->GetMetaStructPointer(), timestampCount };
    std::string ptimestamp_infos_names = toStringJoin(ptimestamp_infos_pair.begin(),
                                                      ptimestamp_infos_pair.end(),
                                                      [&](auto pair) {{ return GenerateStruct_VkCalibratedTimestampInfoKHR(stream_ptimestamp_infos, pair.t1, pair.t2, *this); }},
                                                      ", ");
    if (stream_ptimestamp_infos.str().length() > 0) {
        fprintf(file, "%s", stream_ptimestamp_infos.str().c_str());
        if (timestampCount == 1) {
            ptimestamp_infos_array = "&" + ptimestamp_infos_names;
        } else if (timestampCount > 1) {
            ptimestamp_infos_array = "pTimestampInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkCalibratedTimestampInfoKHR %s[] = { %s };\n", ptimestamp_infos_array.c_str(), ptimestamp_infos_names.c_str());
        }
    }
    std::string ptimestamps_name = "pTimestamps_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint64_t %s[%d];\n", ptimestamps_name.c_str(), timestampCount);
    std::string pmax_deviation_name = "pMaxDeviation_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint64_t %s;\n", pmax_deviation_name.c_str());
    pfn_loader_.AddMethodName("vkGetCalibratedTimestampsKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetCalibratedTimestampsKHR(%s, %u, %s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            timestampCount,
            ptimestamp_infos_array.c_str(),
            ptimestamps_name.c_str(),
            pmax_deviation_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetCalibratedTimestampsKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pTimeDomainCount,
    PointerDecoder<VkTimeDomainKHR>*            pTimeDomains)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string ptime_domain_count_name = "pTimeDomainCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", ptime_domain_count_name.c_str());
    std::string ptime_domains_name = "pTimeDomains_" + std::to_string(this->GetNextId());
    const uint32_t* in_ptime_domain_count = pTimeDomainCount->GetPointer();
    fprintf(file, "\t\tVkTimeDomainKHR %s[%d];\n", ptime_domains_name.c_str(), *in_ptime_domain_count);
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceCalibrateableTimeDomainsKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(%s, &%s, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            ptime_domain_count_name.c_str(),
            ptime_domains_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR);
}
void VulkanCppConsumer::Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT>* pBindDescriptorBufferEmbeddedSamplersInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbind_descriptor_buffer_embedded_samplers_info;
    std::string pbind_descriptor_buffer_embedded_samplers_info_struct = GenerateStruct_VkBindDescriptorBufferEmbeddedSamplersInfoEXT(stream_pbind_descriptor_buffer_embedded_samplers_info,
                                                                                                                                     pBindDescriptorBufferEmbeddedSamplersInfo->GetPointer(),
                                                                                                                                     pBindDescriptorBufferEmbeddedSamplersInfo->GetMetaStructPointer(),
                                                                                                                                     *this);
    fprintf(file, "%s", stream_pbind_descriptor_buffer_embedded_samplers_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdBindDescriptorBufferEmbeddedSamplers2EXT");
    fprintf(file,
            "\t\tloaded_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pbind_descriptor_buffer_embedded_samplers_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT);
}

void VulkanCppConsumer::Process_vkCmdBindDescriptorSets2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBindDescriptorSetsInfoKHR>* pBindDescriptorSetsInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbind_descriptor_sets_info;
    std::string pbind_descriptor_sets_info_struct = GenerateStruct_VkBindDescriptorSetsInfoKHR(stream_pbind_descriptor_sets_info,
                                                                                               pBindDescriptorSetsInfo->GetPointer(),
                                                                                               pBindDescriptorSetsInfo->GetMetaStructPointer(),
                                                                                               *this);
    fprintf(file, "%s", stream_pbind_descriptor_sets_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdBindDescriptorSets2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdBindDescriptorSets2KHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pbind_descriptor_sets_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindDescriptorSets2KHR);
}

void VulkanCppConsumer::Process_vkCmdPushConstants2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPushConstantsInfoKHR>* pPushConstantsInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_ppush_constants_info;
    std::string ppush_constants_info_struct = GenerateStruct_VkPushConstantsInfoKHR(stream_ppush_constants_info,
                                                                                    pPushConstantsInfo->GetPointer(),
                                                                                    pPushConstantsInfo->GetMetaStructPointer(),
                                                                                    *this);
    fprintf(file, "%s", stream_ppush_constants_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdPushConstants2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdPushConstants2KHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            ppush_constants_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPushConstants2KHR);
}

void VulkanCppConsumer::Process_vkCmdPushDescriptorSet2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPushDescriptorSetInfoKHR>* pPushDescriptorSetInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_ppush_descriptor_set_info;
    std::string ppush_descriptor_set_info_struct = GenerateStruct_VkPushDescriptorSetInfoKHR(stream_ppush_descriptor_set_info,
                                                                                             pPushDescriptorSetInfo->GetPointer(),
                                                                                             pPushDescriptorSetInfo->GetMetaStructPointer(),
                                                                                             *this);
    fprintf(file, "%s", stream_ppush_descriptor_set_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdPushDescriptorSet2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdPushDescriptorSet2KHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            ppush_descriptor_set_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPushDescriptorSet2KHR);
}

void VulkanCppConsumer::Process_vkCmdSetDescriptorBufferOffsets2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSetDescriptorBufferOffsetsInfoEXT>* pSetDescriptorBufferOffsetsInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pset_descriptor_buffer_offsets_info;
    std::string pset_descriptor_buffer_offsets_info_struct = GenerateStruct_VkSetDescriptorBufferOffsetsInfoEXT(stream_pset_descriptor_buffer_offsets_info,
                                                                                                                pSetDescriptorBufferOffsetsInfo->GetPointer(),
                                                                                                                pSetDescriptorBufferOffsetsInfo->GetMetaStructPointer(),
                                                                                                                *this);
    fprintf(file, "%s", stream_pset_descriptor_buffer_offsets_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdSetDescriptorBufferOffsets2EXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDescriptorBufferOffsets2EXT(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pset_descriptor_buffer_offsets_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDescriptorBufferOffsets2EXT);
}
void VulkanCppConsumer::Process_vkFrameBoundaryANDROID(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    format::HandleId                            image)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkFrameBoundaryANDROID");
    fprintf(file,
            "\t\tloaded_vkFrameBoundaryANDROID(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(semaphore).c_str(),
            this->GetHandle(image).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkDebugReportCallbackCreateInfoEXT(stream_pcreate_info,
                                                                                        pCreateInfo->GetPointer(),
                                                                                        pCreateInfo->GetMetaStructPointer(),
                                                                                        *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pcallback_name = "pCallback_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT));
    AddKnownVariables("VkDebugReportCallbackEXT", pcallback_name, pCallback->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pcallback_name,
                         pCallback->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateDebugReportCallbackEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateDebugReportCallbackEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pcallback_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDebugReportMessageEXT");
    fprintf(file,
            "\t\tloaded_vkDebugReportMessageEXT(%s, %s, %s, %" PRIu64 "UL, %" PRIu64 ", %d, %p, %p);\n",
            this->GetHandle(instance).c_str(),
            util::ToString<VkDebugReportFlagsEXT>(flags).c_str(),
            util::ToString<VkDebugReportObjectTypeEXT>(objectType).c_str(),
            object,
            util::platform::SizeTtoUint64(location),
            messageCode,
            pLayerPrefix->GetPointer(),
            pMessage->GetPointer());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDebugReportMessageEXT);
}

void VulkanCppConsumer::Process_vkDestroyDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            callback,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyDebugReportCallbackEXT");
    fprintf(file,
            "\t\tloaded_vkDestroyDebugReportCallbackEXT(%s, %s, %s);\n",
            this->GetHandle(instance).c_str(),
            this->GetHandle(callback).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT);
}
void VulkanCppConsumer::Process_vkCmdDebugMarkerBeginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pmarker_info;
    std::string pmarker_info_struct = GenerateStruct_VkDebugMarkerMarkerInfoEXT(stream_pmarker_info,
                                                                                pMarkerInfo->GetPointer(),
                                                                                pMarkerInfo->GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_pmarker_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdDebugMarkerBeginEXT");
    fprintf(file,
            "\t\tloaded_vkCmdDebugMarkerBeginEXT(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pmarker_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT);
}

void VulkanCppConsumer::Process_vkCmdDebugMarkerEndEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDebugMarkerEndEXT");
    fprintf(file,
            "\t\tloaded_vkCmdDebugMarkerEndEXT(%s);\n",
            this->GetHandle(commandBuffer).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT);
}

void VulkanCppConsumer::Process_vkCmdDebugMarkerInsertEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pmarker_info;
    std::string pmarker_info_struct = GenerateStruct_VkDebugMarkerMarkerInfoEXT(stream_pmarker_info,
                                                                                pMarkerInfo->GetPointer(),
                                                                                pMarkerInfo->GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_pmarker_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdDebugMarkerInsertEXT");
    fprintf(file,
            "\t\tloaded_vkCmdDebugMarkerInsertEXT(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pmarker_info_struct.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdBeginQueryIndexedEXT");
    fprintf(file,
            "\t\tloaded_vkCmdBeginQueryIndexedEXT(%s, %s, %u, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(queryPool).c_str(),
            query,
            util::ToString<VkQueryControlFlags>(flags).c_str(),
            index);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pcounter_buffers_array = "NULL";
    std::string pcounter_buffers_values = toStringJoin(pCounterBuffers->GetPointer(),
                                                       pCounterBuffers->GetPointer() + counterBufferCount,
                                                       [&](const format::HandleId current) { return this->GetHandle(current); },
                                                       ", ");
    if (counterBufferCount == 1 && pcounter_buffers_values != "VK_NULL_HANDLE") {
        pcounter_buffers_array = "&" + pcounter_buffers_values;
    } else if (counterBufferCount > 1) {
        pcounter_buffers_array = "pcounter_buffers_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkBuffer %s[] = { %s };\n", pcounter_buffers_array.c_str(), pcounter_buffers_values.c_str());
    }
    std::string pcounter_buffer_offsets_array = "pCounterBufferOffsets_" + std::to_string(this->GetNextId());
    if (counterBufferCount > 0 && pCounterBufferOffsets->GetPointer() != nullptr) {
        std::string pcounter_buffer_offsets_values = toStringJoin(pCounterBufferOffsets->GetPointer(),
                                                                  pCounterBufferOffsets->GetPointer() + counterBufferCount,
                                                                  [&](const auto current) { return std::to_string(current) + "UL"; },
                                                                  ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", pcounter_buffer_offsets_array.c_str(), pcounter_buffer_offsets_values.c_str());
    } else {
        pcounter_buffer_offsets_array = "NULL";
    }
    pfn_loader_.AddMethodName("vkCmdBeginTransformFeedbackEXT");
    fprintf(file,
            "\t\tloaded_vkCmdBeginTransformFeedbackEXT(%s, %u, %u, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstCounterBuffer,
            counterBufferCount,
            pcounter_buffers_array.c_str(),
            pcounter_buffer_offsets_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pbuffers_array = "NULL";
    std::string pbuffers_values = toStringJoin(pBuffers->GetPointer(),
                                               pBuffers->GetPointer() + bindingCount,
                                               [&](const format::HandleId current) { return this->GetHandle(current); },
                                               ", ");
    if (bindingCount == 1 && pbuffers_values != "VK_NULL_HANDLE") {
        pbuffers_array = "&" + pbuffers_values;
    } else if (bindingCount > 1) {
        pbuffers_array = "pbuffers_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkBuffer %s[] = { %s };\n", pbuffers_array.c_str(), pbuffers_values.c_str());
    }
    std::string poffsets_array = "pOffsets_" + std::to_string(this->GetNextId());
    if (bindingCount > 0) {
        std::string poffsets_values = toStringJoin(pOffsets->GetPointer(),
                                                   pOffsets->GetPointer() + bindingCount,
                                                   [&](const auto current) { return std::to_string(current) + "UL"; },
                                                   ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", poffsets_array.c_str(), poffsets_values.c_str());
    } else {
        poffsets_array = "NULL";
    }
    std::string psizes_array = "pSizes_" + std::to_string(this->GetNextId());
    if (bindingCount > 0 && pSizes->GetPointer() != nullptr) {
        std::string psizes_values = toStringJoin(pSizes->GetPointer(),
                                                 pSizes->GetPointer() + bindingCount,
                                                 [&](const auto current) { return std::to_string(current) + "UL"; },
                                                 ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", psizes_array.c_str(), psizes_values.c_str());
    } else {
        psizes_array = "NULL";
    }
    pfn_loader_.AddMethodName("vkCmdBindTransformFeedbackBuffersEXT");
    fprintf(file,
            "\t\tloaded_vkCmdBindTransformFeedbackBuffersEXT(%s, %u, %u, %s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstBinding,
            bindingCount,
            pbuffers_array.c_str(),
            poffsets_array.c_str(),
            psizes_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawIndirectByteCountEXT");
    fprintf(file,
            "\t\tloaded_vkCmdDrawIndirectByteCountEXT(%s, %u, %u, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            instanceCount,
            firstInstance,
            this->GetHandle(counterBuffer).c_str(),
            counterBufferOffset,
            counterOffset,
            vertexStride);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdEndQueryIndexedEXT");
    fprintf(file,
            "\t\tloaded_vkCmdEndQueryIndexedEXT(%s, %s, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(queryPool).c_str(),
            query,
            index);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pcounter_buffers_array = "NULL";
    std::string pcounter_buffers_values = toStringJoin(pCounterBuffers->GetPointer(),
                                                       pCounterBuffers->GetPointer() + counterBufferCount,
                                                       [&](const format::HandleId current) { return this->GetHandle(current); },
                                                       ", ");
    if (counterBufferCount == 1 && pcounter_buffers_values != "VK_NULL_HANDLE") {
        pcounter_buffers_array = "&" + pcounter_buffers_values;
    } else if (counterBufferCount > 1) {
        pcounter_buffers_array = "pcounter_buffers_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkBuffer %s[] = { %s };\n", pcounter_buffers_array.c_str(), pcounter_buffers_values.c_str());
    }
    std::string pcounter_buffer_offsets_array = "pCounterBufferOffsets_" + std::to_string(this->GetNextId());
    if (counterBufferCount > 0 && pCounterBufferOffsets->GetPointer() != nullptr) {
        std::string pcounter_buffer_offsets_values = toStringJoin(pCounterBufferOffsets->GetPointer(),
                                                                  pCounterBufferOffsets->GetPointer() + counterBufferCount,
                                                                  [&](const auto current) { return std::to_string(current) + "UL"; },
                                                                  ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", pcounter_buffer_offsets_array.c_str(), pcounter_buffer_offsets_values.c_str());
    } else {
        pcounter_buffer_offsets_array = "NULL";
    }
    pfn_loader_.AddMethodName("vkCmdEndTransformFeedbackEXT");
    fprintf(file,
            "\t\tloaded_vkCmdEndTransformFeedbackEXT(%s, %u, %u, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstCounterBuffer,
            counterBufferCount,
            pcounter_buffers_array.c_str(),
            pcounter_buffer_offsets_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pproperties;
    pproperties_name = GenerateStruct_VkImageViewAddressPropertiesNVX(stream_pproperties,
                                                                      pProperties->GetPointer(),
                                                                      pProperties->GetMetaStructPointer(),
                                                                      *this);
    fprintf(file, "%s", stream_pproperties.str().c_str());
    pfn_loader_.AddMethodName("vkGetImageViewAddressNVX");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetImageViewAddressNVX(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(imageView).c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageViewAddressNVX);
}

void VulkanCppConsumer::Process_vkGetImageViewHandleNVX(
    const ApiCallInfo&                          call_info,
    uint32_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkImageViewHandleInfoNVX(stream_pinfo,
                                                                       pInfo->GetPointer(),
                                                                       pInfo->GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkGetImageViewHandleNVX");
    fprintf(file,
            "\t\tloaded_vkGetImageViewHandleNVX(%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawIndexedIndirectCountAMD");
    fprintf(file,
            "\t\tloaded_vkCmdDrawIndexedIndirectCountAMD(%s, %s, %" PRIu64 "UL, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            this->GetHandle(countBuffer).c_str(),
            countBufferOffset,
            maxDrawCount,
            stride);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawIndirectCountAMD");
    fprintf(file,
            "\t\tloaded_vkCmdDrawIndirectCountAMD(%s, %s, %" PRIu64 "UL, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            this->GetHandle(countBuffer).c_str(),
            countBufferOffset,
            maxDrawCount,
            stride);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pinfo_size_name = "pInfoSize_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tsize_t %s;\n", pinfo_size_name.c_str());
    std::string pinfo_name = "pInfo_" + std::to_string(this->GetNextId());
    size_t* in_pinfo_size = pInfoSize->GetPointer();
    fprintf(file, "\t\tuint8_t %s[%" PRIu64 "];\n", pinfo_name.c_str(), util::platform::SizeTtoUint64(*in_pinfo_size));
    pfn_loader_.AddMethodName("vkGetShaderInfoAMD");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetShaderInfoAMD(%s, %s, %s, %s, &%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipeline).c_str(),
            util::ToString<VkShaderStageFlagBits>(shaderStage).c_str(),
            util::ToString<VkShaderInfoTypeAMD>(infoType).c_str(),
            pinfo_size_name.c_str(),
            pinfo_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkStreamDescriptorSurfaceCreateInfoGGP(stream_pcreate_info,
                                                                                            pCreateInfo->GetPointer(),
                                                                                            pCreateInfo->GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psurface_name = "pSurface_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", psurface_name, pSurface->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(psurface_name,
                         pSurface->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateStreamDescriptorSurfaceGGP");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateStreamDescriptorSurfaceGGP(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psurface_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pexternal_image_format_properties_name = "pExternalImageFormatProperties_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tVkExternalImageFormatPropertiesNV %s;\n", pexternal_image_format_properties_name.c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceExternalImageFormatPropertiesNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(%s, %s, %s, %s, %s, %s, %s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            util::ToString<VkFormat>(format).c_str(),
            util::ToString<VkImageType>(type).c_str(),
            util::ToString<VkImageTiling>(tiling).c_str(),
            util::ToString<VkImageUsageFlags>(usage).c_str(),
            util::ToString<VkImageCreateFlags>(flags).c_str(),
            util::ToString<VkExternalMemoryHandleTypeFlagsNV>(externalHandleType).c_str(),
            pexternal_image_format_properties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string phandle_name = "pHandle_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint8_t* %s;\n", phandle_name.c_str());
    pfn_loader_.AddMethodName("vkGetMemoryWin32HandleNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetMemoryWin32HandleNV(%s, %s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(memory).c_str(),
            util::ToString<VkExternalMemoryHandleTypeFlagsNV>(handleType).c_str(),
            phandle_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkViSurfaceCreateInfoNN(stream_pcreate_info,
                                                                             pCreateInfo->GetPointer(),
                                                                             pCreateInfo->GetMetaStructPointer(),
                                                                             *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psurface_name = "pSurface_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", psurface_name, pSurface->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(psurface_name,
                         pSurface->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateViSurfaceNN");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateViSurfaceNN(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psurface_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateViSurfaceNN);
}
void VulkanCppConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pconditional_rendering_begin;
    std::string pconditional_rendering_begin_struct = GenerateStruct_VkConditionalRenderingBeginInfoEXT(stream_pconditional_rendering_begin,
                                                                                                        pConditionalRenderingBegin->GetPointer(),
                                                                                                        pConditionalRenderingBegin->GetMetaStructPointer(),
                                                                                                        *this);
    fprintf(file, "%s", stream_pconditional_rendering_begin.str().c_str());
    pfn_loader_.AddMethodName("vkCmdBeginConditionalRenderingEXT");
    fprintf(file,
            "\t\tloaded_vkCmdBeginConditionalRenderingEXT(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pconditional_rendering_begin_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT);
}

void VulkanCppConsumer::Process_vkCmdEndConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdEndConditionalRenderingEXT");
    fprintf(file,
            "\t\tloaded_vkCmdEndConditionalRenderingEXT(%s);\n",
            this->GetHandle(commandBuffer).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pviewport_w_scalings;
    std::string pviewport_w_scalings_array = "NULL";
    PointerPairContainer<decltype(pViewportWScalings->GetPointer()), decltype(pViewportWScalings->GetMetaStructPointer())> pviewport_w_scalings_pair{ pViewportWScalings->GetPointer(), pViewportWScalings->GetMetaStructPointer(), viewportCount };
    std::string pviewport_w_scalings_names = toStringJoin(pviewport_w_scalings_pair.begin(),
                                                          pviewport_w_scalings_pair.end(),
                                                          [&](auto pair) {{ return GenerateStruct_VkViewportWScalingNV(stream_pviewport_w_scalings, pair.t1, pair.t2, *this); }},
                                                          ", ");
    if (stream_pviewport_w_scalings.str().length() > 0) {
        fprintf(file, "%s", stream_pviewport_w_scalings.str().c_str());
        if (viewportCount == 1) {
            pviewport_w_scalings_array = "&" + pviewport_w_scalings_names;
        } else if (viewportCount > 1) {
            pviewport_w_scalings_array = "pViewportWScalings_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkViewportWScalingNV %s[] = { %s };\n", pviewport_w_scalings_array.c_str(), pviewport_w_scalings_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdSetViewportWScalingNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetViewportWScalingNV(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstViewport,
            viewportCount,
            pviewport_w_scalings_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV);
}
void VulkanCppConsumer::Process_vkReleaseDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkReleaseDisplayEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkReleaseDisplayEXT(%s, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            this->GetHandle(display).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string dpy_name = "dpy_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tvoid* %s;\n", dpy_name.c_str());
    pfn_loader_.AddMethodName("vkAcquireXlibDisplayEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkAcquireXlibDisplayEXT(%s, %s, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            dpy_name.c_str(),
            this->GetHandle(display).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string dpy_name = "dpy_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tvoid* %s;\n", dpy_name.c_str());
    std::string pdisplay_name = "pDisplay_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DISPLAY_KHR));
    AddKnownVariables("VkDisplayKHR", pdisplay_name, pDisplay->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pdisplay_name,
                         pDisplay->GetPointer());
    }
    pfn_loader_.AddMethodName("vkGetRandROutputDisplayEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetRandROutputDisplayEXT(%s, %s, %" PRIu64 ", &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            dpy_name.c_str(),
            util::platform::SizeTtoUint64(rrOutput),
            pdisplay_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string psurface_capabilities_name = "pSurfaceCapabilities_" + std::to_string(this->GetNextId());
    std::stringstream stream_psurface_capabilities;
    psurface_capabilities_name = GenerateStruct_VkSurfaceCapabilities2EXT(stream_psurface_capabilities,
                                                                          pSurfaceCapabilities->GetPointer(),
                                                                          pSurfaceCapabilities->GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_psurface_capabilities.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceSurfaceCapabilities2EXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfaceCapabilities2EXT(%s, %s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            this->GetHandle(surface).c_str(),
            psurface_capabilities_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pdisplay_power_info;
    std::string pdisplay_power_info_struct = GenerateStruct_VkDisplayPowerInfoEXT(stream_pdisplay_power_info,
                                                                                  pDisplayPowerInfo->GetPointer(),
                                                                                  pDisplayPowerInfo->GetMetaStructPointer(),
                                                                                  *this);
    fprintf(file, "%s", stream_pdisplay_power_info.str().c_str());
    pfn_loader_.AddMethodName("vkDisplayPowerControlEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkDisplayPowerControlEXT(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(display).c_str(),
            pdisplay_power_info_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pcounter_value_name = "pCounterValue_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint64_t %s;\n", pcounter_value_name.c_str());
    pfn_loader_.AddMethodName("vkGetSwapchainCounterEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetSwapchainCounterEXT(%s, %s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapchain).c_str(),
            util::ToString<VkSurfaceCounterFlagBitsEXT>(counter).c_str(),
            pcounter_value_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pdevice_event_info;
    std::string pdevice_event_info_struct = GenerateStruct_VkDeviceEventInfoEXT(stream_pdevice_event_info,
                                                                                pDeviceEventInfo->GetPointer(),
                                                                                pDeviceEventInfo->GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_pdevice_event_info.str().c_str());
    std::string pfence_name = "pFence_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_FENCE));
    AddKnownVariables("VkFence", pfence_name, pFence->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pfence_name,
                         pFence->GetPointer());
    }
    pfn_loader_.AddMethodName("vkRegisterDeviceEventEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkRegisterDeviceEventEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pdevice_event_info_struct.c_str(),
            "nullptr",
            pfence_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pdisplay_event_info;
    std::string pdisplay_event_info_struct = GenerateStruct_VkDisplayEventInfoEXT(stream_pdisplay_event_info,
                                                                                  pDisplayEventInfo->GetPointer(),
                                                                                  pDisplayEventInfo->GetMetaStructPointer(),
                                                                                  *this);
    fprintf(file, "%s", stream_pdisplay_event_info.str().c_str());
    std::string pfence_name = "pFence_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_FENCE));
    AddKnownVariables("VkFence", pfence_name, pFence->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pfence_name,
                         pFence->GetPointer());
    }
    pfn_loader_.AddMethodName("vkRegisterDisplayEventEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkRegisterDisplayEventEXT(%s, %s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(display).c_str(),
            pdisplay_event_info_struct.c_str(),
            "nullptr",
            pfence_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string ppresentation_timing_count_name = "pPresentationTimingCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", ppresentation_timing_count_name.c_str());
    std::string ppresentation_timings_name = "pPresentationTimings_" + std::to_string(this->GetNextId());
    const uint32_t* in_ppresentation_timing_count = pPresentationTimingCount->GetPointer();
    fprintf(file, "\t\tVkPastPresentationTimingGOOGLE %s[%d];\n", ppresentation_timings_name.c_str(), *in_ppresentation_timing_count);
    pfn_loader_.AddMethodName("vkGetPastPresentationTimingGOOGLE");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPastPresentationTimingGOOGLE(%s, %s, &%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapchain).c_str(),
            ppresentation_timing_count_name.c_str(),
            ppresentation_timings_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pdisplay_timing_properties_name = "pDisplayTimingProperties_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tVkRefreshCycleDurationGOOGLE %s;\n", pdisplay_timing_properties_name.c_str());
    pfn_loader_.AddMethodName("vkGetRefreshCycleDurationGOOGLE");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetRefreshCycleDurationGOOGLE(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapchain).c_str(),
            pdisplay_timing_properties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pdiscard_rectangles;
    std::string pdiscard_rectangles_array = "NULL";
    PointerPairContainer<decltype(pDiscardRectangles->GetPointer()), decltype(pDiscardRectangles->GetMetaStructPointer())> pdiscard_rectangles_pair{ pDiscardRectangles->GetPointer(), pDiscardRectangles->GetMetaStructPointer(), discardRectangleCount };
    std::string pdiscard_rectangles_names = toStringJoin(pdiscard_rectangles_pair.begin(),
                                                         pdiscard_rectangles_pair.end(),
                                                         [&](auto pair) {{ return GenerateStruct_VkRect2D(stream_pdiscard_rectangles, pair.t1, pair.t2, *this); }},
                                                         ", ");
    if (stream_pdiscard_rectangles.str().length() > 0) {
        fprintf(file, "%s", stream_pdiscard_rectangles.str().c_str());
        if (discardRectangleCount == 1) {
            pdiscard_rectangles_array = "&" + pdiscard_rectangles_names;
        } else if (discardRectangleCount > 1) {
            pdiscard_rectangles_array = "pDiscardRectangles_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkRect2D %s[] = { %s };\n", pdiscard_rectangles_array.c_str(), pdiscard_rectangles_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdSetDiscardRectangleEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDiscardRectangleEXT(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstDiscardRectangle,
            discardRectangleCount,
            pdiscard_rectangles_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDiscardRectangleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    discardRectangleEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetDiscardRectangleEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDiscardRectangleEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            discardRectangleEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDiscardRectangleModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDiscardRectangleModeEXT                   discardRectangleMode)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetDiscardRectangleModeEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDiscardRectangleModeEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkDiscardRectangleModeEXT>(discardRectangleMode).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pswapchains_array = "NULL";
    std::string pswapchains_values = toStringJoin(pSwapchains->GetPointer(),
                                                  pSwapchains->GetPointer() + swapchainCount,
                                                  [&](const format::HandleId current) { return this->GetHandle(current); },
                                                  ", ");
    if (swapchainCount == 1 && pswapchains_values != "VK_NULL_HANDLE") {
        pswapchains_array = "&" + pswapchains_values;
    } else if (swapchainCount > 1) {
        pswapchains_array = "pswapchains_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkSwapchainKHR %s[] = { %s };\n", pswapchains_array.c_str(), pswapchains_values.c_str());
    }
    std::stringstream stream_pmetadata;
    std::string pmetadata_array = "NULL";
    PointerPairContainer<decltype(pMetadata->GetPointer()), decltype(pMetadata->GetMetaStructPointer())> pmetadata_pair{ pMetadata->GetPointer(), pMetadata->GetMetaStructPointer(), swapchainCount };
    std::string pmetadata_names = toStringJoin(pmetadata_pair.begin(),
                                               pmetadata_pair.end(),
                                               [&](auto pair) {{ return GenerateStruct_VkHdrMetadataEXT(stream_pmetadata, pair.t1, pair.t2, *this); }},
                                               ", ");
    if (stream_pmetadata.str().length() > 0) {
        fprintf(file, "%s", stream_pmetadata.str().c_str());
        if (swapchainCount == 1) {
            pmetadata_array = "&" + pmetadata_names;
        } else if (swapchainCount > 1) {
            pmetadata_array = "pMetadata_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkHdrMetadataEXT %s[] = { %s };\n", pmetadata_array.c_str(), pmetadata_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkSetHdrMetadataEXT");
    fprintf(file,
            "\t\tloaded_vkSetHdrMetadataEXT(%s, %u, %s, %s);\n",
            this->GetHandle(device).c_str(),
            swapchainCount,
            pswapchains_array.c_str(),
            pmetadata_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkIOSSurfaceCreateInfoMVK(stream_pcreate_info,
                                                                               pCreateInfo->GetPointer(),
                                                                               pCreateInfo->GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psurface_name = "pSurface_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", psurface_name, pSurface->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(psurface_name,
                         pSurface->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateIOSSurfaceMVK");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateIOSSurfaceMVK(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psurface_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkMacOSSurfaceCreateInfoMVK(stream_pcreate_info,
                                                                                 pCreateInfo->GetPointer(),
                                                                                 pCreateInfo->GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psurface_name = "pSurface_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", psurface_name, pSurface->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(psurface_name,
                         pSurface->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateMacOSSurfaceMVK");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateMacOSSurfaceMVK(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psurface_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK);
}
void VulkanCppConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_plabel_info;
    std::string plabel_info_struct = GenerateStruct_VkDebugUtilsLabelEXT(stream_plabel_info,
                                                                         pLabelInfo->GetPointer(),
                                                                         pLabelInfo->GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "%s", stream_plabel_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdBeginDebugUtilsLabelEXT");
    fprintf(file,
            "\t\tloaded_vkCmdBeginDebugUtilsLabelEXT(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            plabel_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT);
}

void VulkanCppConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdEndDebugUtilsLabelEXT");
    fprintf(file,
            "\t\tloaded_vkCmdEndDebugUtilsLabelEXT(%s);\n",
            this->GetHandle(commandBuffer).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT);
}

void VulkanCppConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_plabel_info;
    std::string plabel_info_struct = GenerateStruct_VkDebugUtilsLabelEXT(stream_plabel_info,
                                                                         pLabelInfo->GetPointer(),
                                                                         pLabelInfo->GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "%s", stream_plabel_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdInsertDebugUtilsLabelEXT");
    fprintf(file,
            "\t\tloaded_vkCmdInsertDebugUtilsLabelEXT(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            plabel_info_struct.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkDebugUtilsMessengerCreateInfoEXT(stream_pcreate_info,
                                                                                        pCreateInfo->GetPointer(),
                                                                                        pCreateInfo->GetMetaStructPointer(),
                                                                                        *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pmessenger_name = "pMessenger_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT));
    AddKnownVariables("VkDebugUtilsMessengerEXT", pmessenger_name, pMessenger->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pmessenger_name,
                         pMessenger->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateDebugUtilsMessengerEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateDebugUtilsMessengerEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pmessenger_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT);
}

void VulkanCppConsumer::Process_vkDestroyDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            messenger,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyDebugUtilsMessengerEXT");
    fprintf(file,
            "\t\tloaded_vkDestroyDebugUtilsMessengerEXT(%s, %s, %s);\n",
            this->GetHandle(instance).c_str(),
            this->GetHandle(messenger).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT);
}

void VulkanCppConsumer::Process_vkQueueBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_plabel_info;
    std::string plabel_info_struct = GenerateStruct_VkDebugUtilsLabelEXT(stream_plabel_info,
                                                                         pLabelInfo->GetPointer(),
                                                                         pLabelInfo->GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "%s", stream_plabel_info.str().c_str());
    pfn_loader_.AddMethodName("vkQueueBeginDebugUtilsLabelEXT");
    fprintf(file,
            "\t\tloaded_vkQueueBeginDebugUtilsLabelEXT(%s, &%s);\n",
            this->GetHandle(queue).c_str(),
            plabel_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT);
}

void VulkanCppConsumer::Process_vkQueueEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkQueueEndDebugUtilsLabelEXT");
    fprintf(file,
            "\t\tloaded_vkQueueEndDebugUtilsLabelEXT(%s);\n",
            this->GetHandle(queue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT);
}

void VulkanCppConsumer::Process_vkQueueInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_plabel_info;
    std::string plabel_info_struct = GenerateStruct_VkDebugUtilsLabelEXT(stream_plabel_info,
                                                                         pLabelInfo->GetPointer(),
                                                                         pLabelInfo->GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "%s", stream_plabel_info.str().c_str());
    pfn_loader_.AddMethodName("vkQueueInsertDebugUtilsLabelEXT");
    fprintf(file,
            "\t\tloaded_vkQueueInsertDebugUtilsLabelEXT(%s, &%s);\n",
            this->GetHandle(queue).c_str(),
            plabel_info_struct.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcallback_data;
    std::string pcallback_data_struct = GenerateStruct_VkDebugUtilsMessengerCallbackDataEXT(stream_pcallback_data,
                                                                                            pCallbackData->GetPointer(),
                                                                                            pCallbackData->GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pcallback_data.str().c_str());
    pfn_loader_.AddMethodName("vkSubmitDebugUtilsMessageEXT");
    fprintf(file,
            "\t\tloaded_vkSubmitDebugUtilsMessageEXT(%s, %s, %s, &%s);\n",
            this->GetHandle(instance).c_str(),
            util::ToString<VkDebugUtilsMessageSeverityFlagBitsEXT>(messageSeverity).c_str(),
            util::ToString<VkDebugUtilsMessageTypeFlagsEXT>(messageTypes).c_str(),
            pcallback_data_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT);
}
void VulkanCppConsumer::Process_vkGetAndroidHardwareBufferPropertiesANDROID(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint64_t                                    buffer,
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties)
{
    Generate_vkGetAndroidHardwareBufferPropertiesANDROID(returnValue, device, buffer, pProperties);
    Post_APICall(format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID);
}

void VulkanCppConsumer::Process_vkGetMemoryAndroidHardwareBufferANDROID(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>* pInfo,
    PointerDecoder<uint64_t, void*>*            pBuffer)
{
    Generate_vkGetMemoryAndroidHardwareBufferANDROID(returnValue, device, pInfo, pBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID);
}
void VulkanCppConsumer::Process_vkCmdSetSampleLocationsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psample_locations_info;
    std::string psample_locations_info_struct = GenerateStruct_VkSampleLocationsInfoEXT(stream_psample_locations_info,
                                                                                        pSampleLocationsInfo->GetPointer(),
                                                                                        pSampleLocationsInfo->GetMetaStructPointer(),
                                                                                        *this);
    fprintf(file, "%s", stream_psample_locations_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdSetSampleLocationsEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetSampleLocationsEXT(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            psample_locations_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>* pMultisampleProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pmultisample_properties_name = "pMultisampleProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pmultisample_properties;
    pmultisample_properties_name = GenerateStruct_VkMultisamplePropertiesEXT(stream_pmultisample_properties,
                                                                             pMultisampleProperties->GetPointer(),
                                                                             pMultisampleProperties->GetMetaStructPointer(),
                                                                             *this);
    fprintf(file, "%s", stream_pmultisample_properties.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceMultisamplePropertiesEXT");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceMultisamplePropertiesEXT(%s, %s, &%s);\n",
            this->GetHandle(physicalDevice).c_str(),
            util::ToString<VkSampleCountFlagBits>(samples).c_str(),
            pmultisample_properties_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pproperties;
    pproperties_name = GenerateStruct_VkImageDrmFormatModifierPropertiesEXT(stream_pproperties,
                                                                            pProperties->GetPointer(),
                                                                            pProperties->GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pproperties.str().c_str());
    pfn_loader_.AddMethodName("vkGetImageDrmFormatModifierPropertiesEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetImageDrmFormatModifierPropertiesEXT(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(image).c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkValidationCacheCreateInfoEXT(stream_pcreate_info,
                                                                                    pCreateInfo->GetPointer(),
                                                                                    pCreateInfo->GetMetaStructPointer(),
                                                                                    *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pvalidation_cache_name = "pValidationCache_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_VALIDATION_CACHE_EXT));
    AddKnownVariables("VkValidationCacheEXT", pvalidation_cache_name, pValidationCache->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pvalidation_cache_name,
                         pValidationCache->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateValidationCacheEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateValidationCacheEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pvalidation_cache_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateValidationCacheEXT);
}

void VulkanCppConsumer::Process_vkDestroyValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyValidationCacheEXT");
    fprintf(file,
            "\t\tloaded_vkDestroyValidationCacheEXT(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(validationCache).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pdata_size_name = "pDataSize_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tsize_t %s;\n", pdata_size_name.c_str());
    std::string pdata_name = "pData_" + std::to_string(this->GetNextId());
    size_t* in_pdata_size = pDataSize->GetPointer();
    fprintf(file, "\t\tuint8_t %s[%" PRIu64 "];\n", pdata_name.c_str(), util::platform::SizeTtoUint64(*in_pdata_size));
    pfn_loader_.AddMethodName("vkGetValidationCacheDataEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetValidationCacheDataEXT(%s, %s, &%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(validationCache).c_str(),
            pdata_size_name.c_str(),
            pdata_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string psrc_caches_array = "NULL";
    std::string psrc_caches_values = toStringJoin(pSrcCaches->GetPointer(),
                                                  pSrcCaches->GetPointer() + srcCacheCount,
                                                  [&](const format::HandleId current) { return this->GetHandle(current); },
                                                  ", ");
    if (srcCacheCount == 1 && psrc_caches_values != "VK_NULL_HANDLE") {
        psrc_caches_array = "&" + psrc_caches_values;
    } else if (srcCacheCount > 1) {
        psrc_caches_array = "psrc_caches_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkValidationCacheEXT %s[] = { %s };\n", psrc_caches_array.c_str(), psrc_caches_values.c_str());
    }
    pfn_loader_.AddMethodName("vkMergeValidationCachesEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkMergeValidationCachesEXT(%s, %s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(dstCache).c_str(),
            srcCacheCount,
            psrc_caches_array.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkMergeValidationCachesEXT);
}
void VulkanCppConsumer::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdBindShadingRateImageNV");
    fprintf(file,
            "\t\tloaded_vkCmdBindShadingRateImageNV(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(imageView).c_str(),
            util::ToString<VkImageLayout>(imageLayout).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcustom_sample_orders;
    std::string pcustom_sample_orders_array = "NULL";
    PointerPairContainer<decltype(pCustomSampleOrders->GetPointer()), decltype(pCustomSampleOrders->GetMetaStructPointer())> pcustom_sample_orders_pair{ pCustomSampleOrders->GetPointer(), pCustomSampleOrders->GetMetaStructPointer(), customSampleOrderCount };
    std::string pcustom_sample_orders_names = toStringJoin(pcustom_sample_orders_pair.begin(),
                                                           pcustom_sample_orders_pair.end(),
                                                           [&](auto pair) {{ return GenerateStruct_VkCoarseSampleOrderCustomNV(stream_pcustom_sample_orders, pair.t1, pair.t2, *this); }},
                                                           ", ");
    if (stream_pcustom_sample_orders.str().length() > 0) {
        fprintf(file, "%s", stream_pcustom_sample_orders.str().c_str());
        if (customSampleOrderCount == 1) {
            pcustom_sample_orders_array = "&" + pcustom_sample_orders_names;
        } else if (customSampleOrderCount > 1) {
            pcustom_sample_orders_array = "pCustomSampleOrders_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkCoarseSampleOrderCustomNV %s[] = { %s };\n", pcustom_sample_orders_array.c_str(), pcustom_sample_orders_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdSetCoarseSampleOrderNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetCoarseSampleOrderNV(%s, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkCoarseSampleOrderTypeNV>(sampleOrderType).c_str(),
            customSampleOrderCount,
            pcustom_sample_orders_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pshading_rate_palettes;
    std::string pshading_rate_palettes_array = "NULL";
    PointerPairContainer<decltype(pShadingRatePalettes->GetPointer()), decltype(pShadingRatePalettes->GetMetaStructPointer())> pshading_rate_palettes_pair{ pShadingRatePalettes->GetPointer(), pShadingRatePalettes->GetMetaStructPointer(), viewportCount };
    std::string pshading_rate_palettes_names = toStringJoin(pshading_rate_palettes_pair.begin(),
                                                            pshading_rate_palettes_pair.end(),
                                                            [&](auto pair) {{ return GenerateStruct_VkShadingRatePaletteNV(stream_pshading_rate_palettes, pair.t1, pair.t2, *this); }},
                                                            ", ");
    if (stream_pshading_rate_palettes.str().length() > 0) {
        fprintf(file, "%s", stream_pshading_rate_palettes.str().c_str());
        if (viewportCount == 1) {
            pshading_rate_palettes_array = "&" + pshading_rate_palettes_names;
        } else if (viewportCount > 1) {
            pshading_rate_palettes_array = "pShadingRatePalettes_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkShadingRatePaletteNV %s[] = { %s };\n", pshading_rate_palettes_array.c_str(), pshading_rate_palettes_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdSetViewportShadingRatePaletteNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetViewportShadingRatePaletteNV(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstViewport,
            viewportCount,
            pshading_rate_palettes_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pbind_infos;
    std::string pbind_infos_array = "NULL";
    PointerPairContainer<decltype(pBindInfos->GetPointer()), decltype(pBindInfos->GetMetaStructPointer())> pbind_infos_pair{ pBindInfos->GetPointer(), pBindInfos->GetMetaStructPointer(), bindInfoCount };
    std::string pbind_infos_names = toStringJoin(pbind_infos_pair.begin(),
                                                 pbind_infos_pair.end(),
                                                 [&](auto pair) {{ return GenerateStruct_VkBindAccelerationStructureMemoryInfoNV(stream_pbind_infos, pair.t1, pair.t2, *this); }},
                                                 ", ");
    if (stream_pbind_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pbind_infos.str().c_str());
        if (bindInfoCount == 1) {
            pbind_infos_array = "&" + pbind_infos_names;
        } else if (bindInfoCount > 1) {
            pbind_infos_array = "pBindInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBindAccelerationStructureMemoryInfoNV %s[] = { %s };\n", pbind_infos_array.c_str(), pbind_infos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkBindAccelerationStructureMemoryNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkBindAccelerationStructureMemoryNV(%s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            bindInfoCount,
            pbind_infos_array.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV);
}

void VulkanCppConsumer::Process_vkCmdCopyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dst,
    format::HandleId                            src,
    VkCopyAccelerationStructureModeKHR          mode)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdCopyAccelerationStructureNV");
    fprintf(file,
            "\t\tloaded_vkCmdCopyAccelerationStructureNV(%s, %s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(dst).c_str(),
            this->GetHandle(src).c_str(),
            util::ToString<VkCopyAccelerationStructureModeKHR>(mode).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV);
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
    fprintf(file, "\t{\n");
    std::string pacceleration_structures_array = "NULL";
    std::string pacceleration_structures_values = toStringJoin(pAccelerationStructures->GetPointer(),
                                                               pAccelerationStructures->GetPointer() + accelerationStructureCount,
                                                               [&](const format::HandleId current) { return this->GetHandle(current); },
                                                               ", ");
    if (accelerationStructureCount == 1 && pacceleration_structures_values != "VK_NULL_HANDLE") {
        pacceleration_structures_array = "&" + pacceleration_structures_values;
    } else if (accelerationStructureCount > 1) {
        pacceleration_structures_array = "pacceleration_structures_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkAccelerationStructureNV %s[] = { %s };\n", pacceleration_structures_array.c_str(), pacceleration_structures_values.c_str());
    }
    pfn_loader_.AddMethodName("vkCmdWriteAccelerationStructuresPropertiesNV");
    fprintf(file,
            "\t\tloaded_vkCmdWriteAccelerationStructuresPropertiesNV(%s, %u, %s, %s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            accelerationStructureCount,
            pacceleration_structures_array.c_str(),
            util::ToString<VkQueryType>(queryType).c_str(),
            this->GetHandle(queryPool).c_str(),
            firstQuery);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCompileDeferredNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCompileDeferredNV(%s, %s, %u), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipeline).c_str(),
            shader,
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCompileDeferredNV);
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_infos;
    std::string pcreate_infos_array = "NULL";
    PointerPairContainer<decltype(pCreateInfos->GetPointer()), decltype(pCreateInfos->GetMetaStructPointer())> pcreate_infos_pair{ pCreateInfos->GetPointer(), pCreateInfos->GetMetaStructPointer(), createInfoCount };
    std::string pcreate_infos_names = toStringJoin(pcreate_infos_pair.begin(),
                                                   pcreate_infos_pair.end(),
                                                   [&](auto pair) {{ return GenerateStruct_VkRayTracingPipelineCreateInfoNV(stream_pcreate_infos, pair.t1, pair.t2, *this); }},
                                                   ", ");
    if (stream_pcreate_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pcreate_infos.str().c_str());
        if (createInfoCount == 1) {
            pcreate_infos_array = "&" + pcreate_infos_names;
        } else if (createInfoCount > 1) {
            pcreate_infos_array = "pCreateInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkRayTracingPipelineCreateInfoNV %s[] = { %s };\n", pcreate_infos_array.c_str(), pcreate_infos_names.c_str());
        }
    }
    std::string ppipelines_name = "pPipelines_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_PIPELINE));
    AddKnownVariables("VkPipeline", ppipelines_name, pPipelines->GetPointer(), createInfoCount);
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(ppipelines_name,
                         pPipelines->GetPointer(), createInfoCount);
    }
    pfn_loader_.AddMethodName("vkCreateRayTracingPipelinesNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateRayTracingPipelinesNV(%s, %s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipelineCache).c_str(),
            createInfoCount,
            pcreate_infos_array.c_str(),
            "nullptr",
            ppipelines_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV);
}

void VulkanCppConsumer::Process_vkDestroyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyAccelerationStructureNV");
    fprintf(file,
            "\t\tloaded_vkDestroyAccelerationStructureNV(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(accelerationStructure).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pdata_name = "pData_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint8_t %s[%" PRIu64 "];\n", pdata_name.c_str(), util::platform::SizeTtoUint64(dataSize));
    pfn_loader_.AddMethodName("vkGetAccelerationStructureHandleNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetAccelerationStructureHandleNV(%s, %s, %" PRIu64 ", %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(accelerationStructure).c_str(),
            util::platform::SizeTtoUint64(dataSize),
            pdata_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV);
}

void VulkanCppConsumer::Process_vkGetAccelerationStructureMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkAccelerationStructureMemoryRequirementsInfoNV(stream_pinfo,
                                                                                              pInfo->GetPointer(),
                                                                                              pInfo->GetMetaStructPointer(),
                                                                                              *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string pmemory_requirements_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tVkMemoryRequirements2KHR %s;\n", pmemory_requirements_name.c_str());
    pfn_loader_.AddMethodName("vkGetAccelerationStructureMemoryRequirementsNV");
    fprintf(file,
            "\t\tloaded_vkGetAccelerationStructureMemoryRequirementsNV(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pinfo_struct.c_str(),
            pmemory_requirements_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pdata_name = "pData_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint8_t %s[%" PRIu64 "];\n", pdata_name.c_str(), util::platform::SizeTtoUint64(dataSize));
    pfn_loader_.AddMethodName("vkGetRayTracingShaderGroupHandlesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetRayTracingShaderGroupHandlesKHR(%s, %s, %u, %u, %" PRIu64 ", %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipeline).c_str(),
            firstGroup,
            groupCount,
            util::platform::SizeTtoUint64(dataSize),
            pdata_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pdata_name = "pData_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint8_t %s[%" PRIu64 "];\n", pdata_name.c_str(), util::platform::SizeTtoUint64(dataSize));
    pfn_loader_.AddMethodName("vkGetRayTracingShaderGroupHandlesNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetRayTracingShaderGroupHandlesNV(%s, %s, %u, %u, %" PRIu64 ", %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipeline).c_str(),
            firstGroup,
            groupCount,
            util::platform::SizeTtoUint64(dataSize),
            pdata_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string phost_pointer_name = "pHostPointer_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tvoid* %s;\n", phost_pointer_name.c_str());
    std::string pmemory_host_pointer_properties_name = "pMemoryHostPointerProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pmemory_host_pointer_properties;
    pmemory_host_pointer_properties_name = GenerateStruct_VkMemoryHostPointerPropertiesEXT(stream_pmemory_host_pointer_properties,
                                                                                           pMemoryHostPointerProperties->GetPointer(),
                                                                                           pMemoryHostPointerProperties->GetMetaStructPointer(),
                                                                                           *this);
    fprintf(file, "%s", stream_pmemory_host_pointer_properties.str().c_str());
    pfn_loader_.AddMethodName("vkGetMemoryHostPointerPropertiesEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetMemoryHostPointerPropertiesEXT(%s, %s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkExternalMemoryHandleTypeFlagBits>(handleType).c_str(),
            phost_pointer_name.c_str(),
            pmemory_host_pointer_properties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdWriteBufferMarkerAMD");
    fprintf(file,
            "\t\tloaded_vkCmdWriteBufferMarkerAMD(%s, %s, %s, %" PRIu64 "UL, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineStageFlagBits>(pipelineStage).c_str(),
            this->GetHandle(dstBuffer).c_str(),
            dstOffset,
            marker);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD);
}
void VulkanCppConsumer::Process_vkGetCalibratedTimestampsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    timestampCount,
    StructPointerDecoder<Decoded_VkCalibratedTimestampInfoKHR>* pTimestampInfos,
    PointerDecoder<uint64_t>*                   pTimestamps,
    PointerDecoder<uint64_t>*                   pMaxDeviation)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_ptimestamp_infos;
    std::string ptimestamp_infos_array = "NULL";
    PointerPairContainer<decltype(pTimestampInfos->GetPointer()), decltype(pTimestampInfos->GetMetaStructPointer())> ptimestamp_infos_pair{ pTimestampInfos->GetPointer(), pTimestampInfos->GetMetaStructPointer(), timestampCount };
    std::string ptimestamp_infos_names = toStringJoin(ptimestamp_infos_pair.begin(),
                                                      ptimestamp_infos_pair.end(),
                                                      [&](auto pair) {{ return GenerateStruct_VkCalibratedTimestampInfoKHR(stream_ptimestamp_infos, pair.t1, pair.t2, *this); }},
                                                      ", ");
    if (stream_ptimestamp_infos.str().length() > 0) {
        fprintf(file, "%s", stream_ptimestamp_infos.str().c_str());
        if (timestampCount == 1) {
            ptimestamp_infos_array = "&" + ptimestamp_infos_names;
        } else if (timestampCount > 1) {
            ptimestamp_infos_array = "pTimestampInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkCalibratedTimestampInfoKHR %s[] = { %s };\n", ptimestamp_infos_array.c_str(), ptimestamp_infos_names.c_str());
        }
    }
    std::string ptimestamps_name = "pTimestamps_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint64_t %s[%d];\n", ptimestamps_name.c_str(), timestampCount);
    std::string pmax_deviation_name = "pMaxDeviation_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint64_t %s;\n", pmax_deviation_name.c_str());
    pfn_loader_.AddMethodName("vkGetCalibratedTimestampsEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetCalibratedTimestampsEXT(%s, %u, %s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            timestampCount,
            ptimestamp_infos_array.c_str(),
            ptimestamps_name.c_str(),
            pmax_deviation_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pTimeDomainCount,
    PointerDecoder<VkTimeDomainKHR>*            pTimeDomains)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string ptime_domain_count_name = "pTimeDomainCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", ptime_domain_count_name.c_str());
    std::string ptime_domains_name = "pTimeDomains_" + std::to_string(this->GetNextId());
    const uint32_t* in_ptime_domain_count = pTimeDomainCount->GetPointer();
    fprintf(file, "\t\tVkTimeDomainKHR %s[%d];\n", ptime_domains_name.c_str(), *in_ptime_domain_count);
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceCalibrateableTimeDomainsEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(%s, &%s, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            ptime_domain_count_name.c_str(),
            ptime_domains_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawMeshTasksIndirectCountNV");
    fprintf(file,
            "\t\tloaded_vkCmdDrawMeshTasksIndirectCountNV(%s, %s, %" PRIu64 "UL, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            this->GetHandle(countBuffer).c_str(),
            countBufferOffset,
            maxDrawCount,
            stride);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawMeshTasksIndirectNV");
    fprintf(file,
            "\t\tloaded_vkCmdDrawMeshTasksIndirectNV(%s, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            drawCount,
            stride);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV);
}

void VulkanCppConsumer::Process_vkCmdDrawMeshTasksNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawMeshTasksNV");
    fprintf(file,
            "\t\tloaded_vkCmdDrawMeshTasksNV(%s, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            taskCount,
            firstTask);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pexclusive_scissor_enables_array = "pExclusiveScissorEnables_" + std::to_string(this->GetNextId());
    if (exclusiveScissorCount > 0) {
        std::string pexclusive_scissor_enables_values = toStringJoin(pExclusiveScissorEnables->GetPointer(),
                                                                     pExclusiveScissorEnables->GetPointer() + exclusiveScissorCount,
                                                                     [&](const auto current) { return std::to_string(current) + ""; },
                                                                     ", ");
        fprintf(file, "\t\tVkBool32 %s[] = { %s };\n", pexclusive_scissor_enables_array.c_str(), pexclusive_scissor_enables_values.c_str());
    } else {
        pexclusive_scissor_enables_array = "NULL";
    }
    pfn_loader_.AddMethodName("vkCmdSetExclusiveScissorEnableNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetExclusiveScissorEnableNV(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstExclusiveScissor,
            exclusiveScissorCount,
            pexclusive_scissor_enables_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pexclusive_scissors;
    std::string pexclusive_scissors_array = "NULL";
    PointerPairContainer<decltype(pExclusiveScissors->GetPointer()), decltype(pExclusiveScissors->GetMetaStructPointer())> pexclusive_scissors_pair{ pExclusiveScissors->GetPointer(), pExclusiveScissors->GetMetaStructPointer(), exclusiveScissorCount };
    std::string pexclusive_scissors_names = toStringJoin(pexclusive_scissors_pair.begin(),
                                                         pexclusive_scissors_pair.end(),
                                                         [&](auto pair) {{ return GenerateStruct_VkRect2D(stream_pexclusive_scissors, pair.t1, pair.t2, *this); }},
                                                         ", ");
    if (stream_pexclusive_scissors.str().length() > 0) {
        fprintf(file, "%s", stream_pexclusive_scissors.str().c_str());
        if (exclusiveScissorCount == 1) {
            pexclusive_scissors_array = "&" + pexclusive_scissors_names;
        } else if (exclusiveScissorCount > 1) {
            pexclusive_scissors_array = "pExclusiveScissors_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkRect2D %s[] = { %s };\n", pexclusive_scissors_array.c_str(), pexclusive_scissors_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdSetExclusiveScissorNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetExclusiveScissorNV(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstExclusiveScissor,
            exclusiveScissorCount,
            pexclusive_scissors_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV);
}
void VulkanCppConsumer::Process_vkCmdSetCheckpointNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint64_t                                    pCheckpointMarker)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcheckpoint_marker_name = "pCheckpointMarker_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tvoid* %s;\n", pcheckpoint_marker_name.c_str());
    pfn_loader_.AddMethodName("vkCmdSetCheckpointNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetCheckpointNV(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pcheckpoint_marker_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCheckpointNV);
}

void VulkanCppConsumer::Process_vkGetQueueCheckpointDataNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointDataNV>* pCheckpointData)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcheckpoint_data_count_name = "pCheckpointDataCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pcheckpoint_data_count_name.c_str());
    std::string pcheckpoint_data_name = "pCheckpointData_" + std::to_string(this->GetNextId());
    std::stringstream stream_pcheckpoint_data;
    pcheckpoint_data_name = GenerateStruct_VkCheckpointDataNV(stream_pcheckpoint_data,
                                                              pCheckpointData->GetPointer(),
                                                              pCheckpointData->GetMetaStructPointer(),
                                                              *this);
    fprintf(file, "%s", stream_pcheckpoint_data.str().c_str());
    pfn_loader_.AddMethodName("vkGetQueueCheckpointDataNV");
    fprintf(file,
            "\t\tloaded_vkGetQueueCheckpointDataNV(%s, &%s, &%s);\n",
            this->GetHandle(queue).c_str(),
            pcheckpoint_data_count_name.c_str(),
            pcheckpoint_data_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pacquire_info;
    std::string pacquire_info_struct = GenerateStruct_VkPerformanceConfigurationAcquireInfoINTEL(stream_pacquire_info,
                                                                                                 pAcquireInfo->GetPointer(),
                                                                                                 pAcquireInfo->GetMetaStructPointer(),
                                                                                                 *this);
    fprintf(file, "%s", stream_pacquire_info.str().c_str());
    std::string pconfiguration_name = "pConfiguration_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL));
    AddKnownVariables("VkPerformanceConfigurationINTEL", pconfiguration_name, pConfiguration->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pconfiguration_name,
                         pConfiguration->GetPointer());
    }
    pfn_loader_.AddMethodName("vkAcquirePerformanceConfigurationINTEL");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkAcquirePerformanceConfigurationINTEL(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pacquire_info_struct.c_str(),
            pconfiguration_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL);
}

void VulkanCppConsumer::Process_vkCmdSetPerformanceMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pmarker_info;
    std::string pmarker_info_struct = GenerateStruct_VkPerformanceMarkerInfoINTEL(stream_pmarker_info,
                                                                                  pMarkerInfo->GetPointer(),
                                                                                  pMarkerInfo->GetMetaStructPointer(),
                                                                                  *this);
    fprintf(file, "%s", stream_pmarker_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdSetPerformanceMarkerINTEL");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCmdSetPerformanceMarkerINTEL(%s, &%s), %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pmarker_info_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL);
}

void VulkanCppConsumer::Process_vkCmdSetPerformanceOverrideINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_poverride_info;
    std::string poverride_info_struct = GenerateStruct_VkPerformanceOverrideInfoINTEL(stream_poverride_info,
                                                                                      pOverrideInfo->GetPointer(),
                                                                                      pOverrideInfo->GetMetaStructPointer(),
                                                                                      *this);
    fprintf(file, "%s", stream_poverride_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdSetPerformanceOverrideINTEL");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCmdSetPerformanceOverrideINTEL(%s, &%s), %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            poverride_info_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL);
}

void VulkanCppConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pmarker_info;
    std::string pmarker_info_struct = GenerateStruct_VkPerformanceStreamMarkerInfoINTEL(stream_pmarker_info,
                                                                                        pMarkerInfo->GetPointer(),
                                                                                        pMarkerInfo->GetMetaStructPointer(),
                                                                                        *this);
    fprintf(file, "%s", stream_pmarker_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdSetPerformanceStreamMarkerINTEL");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCmdSetPerformanceStreamMarkerINTEL(%s, &%s), %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pmarker_info_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pvalue_name = "pValue_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tVkPerformanceValueINTEL %s;\n", pvalue_name.c_str());
    pfn_loader_.AddMethodName("vkGetPerformanceParameterINTEL");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPerformanceParameterINTEL(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkPerformanceParameterTypeINTEL>(parameter).c_str(),
            pvalue_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL);
}

void VulkanCppConsumer::Process_vkInitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>* pInitializeInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinitialize_info;
    std::string pinitialize_info_struct = GenerateStruct_VkInitializePerformanceApiInfoINTEL(stream_pinitialize_info,
                                                                                             pInitializeInfo->GetPointer(),
                                                                                             pInitializeInfo->GetMetaStructPointer(),
                                                                                             *this);
    fprintf(file, "%s", stream_pinitialize_info.str().c_str());
    pfn_loader_.AddMethodName("vkInitializePerformanceApiINTEL");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkInitializePerformanceApiINTEL(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pinitialize_info_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL);
}

void VulkanCppConsumer::Process_vkQueueSetPerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    format::HandleId                            configuration)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkQueueSetPerformanceConfigurationINTEL");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkQueueSetPerformanceConfigurationINTEL(%s, %s), %s);\n",
            this->GetHandle(queue).c_str(),
            this->GetHandle(configuration).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL);
}

void VulkanCppConsumer::Process_vkReleasePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            configuration)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkReleasePerformanceConfigurationINTEL");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkReleasePerformanceConfigurationINTEL(%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(configuration).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL);
}

void VulkanCppConsumer::Process_vkUninitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkUninitializePerformanceApiINTEL");
    fprintf(file,
            "\t\tloaded_vkUninitializePerformanceApiINTEL(%s);\n",
            this->GetHandle(device).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL);
}
void VulkanCppConsumer::Process_vkSetLocalDimmingAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapChain,
    VkBool32                                    localDimmingEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkSetLocalDimmingAMD");
    fprintf(file,
            "\t\tloaded_vkSetLocalDimmingAMD(%s, %s, %u);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapChain).c_str(),
            localDimmingEnable);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkImagePipeSurfaceCreateInfoFUCHSIA(stream_pcreate_info,
                                                                                         pCreateInfo->GetPointer(),
                                                                                         pCreateInfo->GetMetaStructPointer(),
                                                                                         *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psurface_name = "pSurface_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", psurface_name, pSurface->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(psurface_name,
                         pSurface->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateImagePipeSurfaceFUCHSIA");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateImagePipeSurfaceFUCHSIA(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psurface_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    Generate_vkCreateMetalSurfaceEXT(returnValue, instance, pCreateInfo, pAllocator, pSurface);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT);
}
void VulkanCppConsumer::Process_vkGetBufferDeviceAddressEXT(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkBufferDeviceAddressInfo(stream_pinfo,
                                                                        pInfo->GetPointer(),
                                                                        pInfo->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkGetBufferDeviceAddressEXT");
    fprintf(file,
            "\t\tloaded_vkGetBufferDeviceAddressEXT(%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string ptool_count_name = "pToolCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", ptool_count_name.c_str());
    std::string ptool_properties_name = "pToolProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_ptool_properties;
    ptool_properties_name = GenerateStruct_VkPhysicalDeviceToolProperties(stream_ptool_properties,
                                                                          pToolProperties->GetPointer(),
                                                                          pToolProperties->GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_ptool_properties.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceToolPropertiesEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceToolPropertiesEXT(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            ptool_count_name.c_str(),
            ptool_properties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pproperty_count_name.c_str());
    std::string pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pproperties;
    pproperties_name = GenerateStruct_VkCooperativeMatrixPropertiesNV(stream_pproperties,
                                                                      pProperties->GetPointer(),
                                                                      pProperties->GetMetaStructPointer(),
                                                                      *this);
    fprintf(file, "%s", stream_pproperties.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceCooperativeMatrixPropertiesNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pcombination_count_name = "pCombinationCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pcombination_count_name.c_str());
    std::string pcombinations_name = "pCombinations_" + std::to_string(this->GetNextId());
    std::stringstream stream_pcombinations;
    pcombinations_name = GenerateStruct_VkFramebufferMixedSamplesCombinationNV(stream_pcombinations,
                                                                               pCombinations->GetPointer(),
                                                                               pCombinations->GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_pcombinations.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pcombination_count_name.c_str(),
            pcombinations_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV);
}
void VulkanCppConsumer::Process_vkAcquireFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkAcquireFullScreenExclusiveModeEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkAcquireFullScreenExclusiveModeEXT(%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapchain).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_psurface_info;
    std::string psurface_info_struct = GenerateStruct_VkPhysicalDeviceSurfaceInfo2KHR(stream_psurface_info,
                                                                                      pSurfaceInfo->GetPointer(),
                                                                                      pSurfaceInfo->GetMetaStructPointer(),
                                                                                      *this);
    fprintf(file, "%s", stream_psurface_info.str().c_str());
    std::string pmodes_name = "pModes_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tVkDeviceGroupPresentModeFlagsKHR %s;\n", pmodes_name.c_str());
    pfn_loader_.AddMethodName("vkGetDeviceGroupSurfacePresentModes2EXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDeviceGroupSurfacePresentModes2EXT(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            psurface_info_struct.c_str(),
            pmodes_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_psurface_info;
    std::string psurface_info_struct = GenerateStruct_VkPhysicalDeviceSurfaceInfo2KHR(stream_psurface_info,
                                                                                      pSurfaceInfo->GetPointer(),
                                                                                      pSurfaceInfo->GetMetaStructPointer(),
                                                                                      *this);
    fprintf(file, "%s", stream_psurface_info.str().c_str());
    std::string ppresent_mode_count_name = "pPresentModeCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", ppresent_mode_count_name.c_str());
    std::string ppresent_modes_name = "pPresentModes_" + std::to_string(this->GetNextId());
    const uint32_t* in_ppresent_mode_count = pPresentModeCount->GetPointer();
    fprintf(file, "\t\tVkPresentModeKHR %s[%d];\n", ppresent_modes_name.c_str(), *in_ppresent_mode_count);
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceSurfacePresentModes2EXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfacePresentModes2EXT(%s, &%s, &%s, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            psurface_info_struct.c_str(),
            ppresent_mode_count_name.c_str(),
            ppresent_modes_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT);
}

void VulkanCppConsumer::Process_vkReleaseFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkReleaseFullScreenExclusiveModeEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkReleaseFullScreenExclusiveModeEXT(%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapchain).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkHeadlessSurfaceCreateInfoEXT(stream_pcreate_info,
                                                                                    pCreateInfo->GetPointer(),
                                                                                    pCreateInfo->GetMetaStructPointer(),
                                                                                    *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psurface_name = "pSurface_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", psurface_name, pSurface->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(psurface_name,
                         pSurface->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateHeadlessSurfaceEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateHeadlessSurfaceEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psurface_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT);
}
void VulkanCppConsumer::Process_vkCmdSetLineStippleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetLineStippleEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetLineStippleEXT(%s, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            lineStippleFactor,
            lineStipplePattern);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkResetQueryPoolEXT");
    fprintf(file,
            "\t\tloaded_vkResetQueryPoolEXT(%s, %s, %u, %u);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(queryPool).c_str(),
            firstQuery,
            queryCount);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pbuffers_array = "NULL";
    std::string pbuffers_values = toStringJoin(pBuffers->GetPointer(),
                                               pBuffers->GetPointer() + bindingCount,
                                               [&](const format::HandleId current) { return this->GetHandle(current); },
                                               ", ");
    if (bindingCount == 1 && pbuffers_values != "VK_NULL_HANDLE") {
        pbuffers_array = "&" + pbuffers_values;
    } else if (bindingCount > 1) {
        pbuffers_array = "pbuffers_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkBuffer %s[] = { %s };\n", pbuffers_array.c_str(), pbuffers_values.c_str());
    }
    std::string poffsets_array = "pOffsets_" + std::to_string(this->GetNextId());
    if (bindingCount > 0) {
        std::string poffsets_values = toStringJoin(pOffsets->GetPointer(),
                                                   pOffsets->GetPointer() + bindingCount,
                                                   [&](const auto current) { return std::to_string(current) + "UL"; },
                                                   ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", poffsets_array.c_str(), poffsets_values.c_str());
    } else {
        poffsets_array = "NULL";
    }
    std::string psizes_array = "pSizes_" + std::to_string(this->GetNextId());
    if (bindingCount > 0 && pSizes->GetPointer() != nullptr) {
        std::string psizes_values = toStringJoin(pSizes->GetPointer(),
                                                 pSizes->GetPointer() + bindingCount,
                                                 [&](const auto current) { return std::to_string(current) + "UL"; },
                                                 ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", psizes_array.c_str(), psizes_values.c_str());
    } else {
        psizes_array = "NULL";
    }
    std::string pstrides_array = "pStrides_" + std::to_string(this->GetNextId());
    if (bindingCount > 0 && pStrides->GetPointer() != nullptr) {
        std::string pstrides_values = toStringJoin(pStrides->GetPointer(),
                                                   pStrides->GetPointer() + bindingCount,
                                                   [&](const auto current) { return std::to_string(current) + "UL"; },
                                                   ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", pstrides_array.c_str(), pstrides_values.c_str());
    } else {
        pstrides_array = "NULL";
    }
    pfn_loader_.AddMethodName("vkCmdBindVertexBuffers2EXT");
    fprintf(file,
            "\t\tloaded_vkCmdBindVertexBuffers2EXT(%s, %u, %u, %s, %s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstBinding,
            bindingCount,
            pbuffers_array.c_str(),
            poffsets_array.c_str(),
            psizes_array.c_str(),
            pstrides_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT);
}

void VulkanCppConsumer::Process_vkCmdSetCullModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetCullModeEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetCullModeEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkCullModeFlags>(cullMode).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCullModeEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDepthBoundsTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetDepthBoundsTestEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDepthBoundsTestEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            depthBoundsTestEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDepthCompareOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetDepthCompareOpEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDepthCompareOpEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkCompareOp>(depthCompareOp).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDepthTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetDepthTestEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDepthTestEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            depthTestEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDepthWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetDepthWriteEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDepthWriteEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            depthWriteEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetFrontFaceEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetFrontFaceEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetFrontFaceEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkFrontFace>(frontFace).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT);
}

void VulkanCppConsumer::Process_vkCmdSetPrimitiveTopologyEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetPrimitiveTopologyEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetPrimitiveTopologyEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPrimitiveTopology>(primitiveTopology).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT);
}

void VulkanCppConsumer::Process_vkCmdSetScissorWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pscissors;
    std::string pscissors_array = "NULL";
    PointerPairContainer<decltype(pScissors->GetPointer()), decltype(pScissors->GetMetaStructPointer())> pscissors_pair{ pScissors->GetPointer(), pScissors->GetMetaStructPointer(), scissorCount };
    std::string pscissors_names = toStringJoin(pscissors_pair.begin(),
                                               pscissors_pair.end(),
                                               [&](auto pair) {{ return GenerateStruct_VkRect2D(stream_pscissors, pair.t1, pair.t2, *this); }},
                                               ", ");
    if (stream_pscissors.str().length() > 0) {
        fprintf(file, "%s", stream_pscissors.str().c_str());
        if (scissorCount == 1) {
            pscissors_array = "&" + pscissors_names;
        } else if (scissorCount > 1) {
            pscissors_array = "pScissors_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkRect2D %s[] = { %s };\n", pscissors_array.c_str(), pscissors_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdSetScissorWithCountEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetScissorWithCountEXT(%s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            scissorCount,
            pscissors_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetStencilOpEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetStencilOpEXT(%s, %s, %s, %s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkStencilFaceFlags>(faceMask).c_str(),
            util::ToString<VkStencilOp>(failOp).c_str(),
            util::ToString<VkStencilOp>(passOp).c_str(),
            util::ToString<VkStencilOp>(depthFailOp).c_str(),
            util::ToString<VkCompareOp>(compareOp).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT);
}

void VulkanCppConsumer::Process_vkCmdSetStencilTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetStencilTestEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetStencilTestEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            stencilTestEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetViewportWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pviewports;
    std::string pviewports_array = "NULL";
    PointerPairContainer<decltype(pViewports->GetPointer()), decltype(pViewports->GetMetaStructPointer())> pviewports_pair{ pViewports->GetPointer(), pViewports->GetMetaStructPointer(), viewportCount };
    std::string pviewports_names = toStringJoin(pviewports_pair.begin(),
                                                pviewports_pair.end(),
                                                [&](auto pair) {{ return GenerateStruct_VkViewport(stream_pviewports, pair.t1, pair.t2, *this); }},
                                                ", ");
    if (stream_pviewports.str().length() > 0) {
        fprintf(file, "%s", stream_pviewports.str().c_str());
        if (viewportCount == 1) {
            pviewports_array = "&" + pviewports_names;
        } else if (viewportCount > 1) {
            pviewports_array = "pViewports_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkViewport %s[] = { %s };\n", pviewports_array.c_str(), pviewports_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdSetViewportWithCountEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetViewportWithCountEXT(%s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            viewportCount,
            pviewports_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT);
}
void VulkanCppConsumer::Process_vkCopyImageToImageEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyImageToImageInfoEXT>* pCopyImageToImageInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_image_to_image_info;
    std::string pcopy_image_to_image_info_struct = GenerateStruct_VkCopyImageToImageInfoEXT(stream_pcopy_image_to_image_info,
                                                                                            pCopyImageToImageInfo->GetPointer(),
                                                                                            pCopyImageToImageInfo->GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pcopy_image_to_image_info.str().c_str());
    pfn_loader_.AddMethodName("vkCopyImageToImageEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCopyImageToImageEXT(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcopy_image_to_image_info_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCopyImageToImageEXT);
}

void VulkanCppConsumer::Process_vkCopyImageToMemoryEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyImageToMemoryInfoEXT>* pCopyImageToMemoryInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_image_to_memory_info;
    std::string pcopy_image_to_memory_info_struct = GenerateStruct_VkCopyImageToMemoryInfoEXT(stream_pcopy_image_to_memory_info,
                                                                                              pCopyImageToMemoryInfo->GetPointer(),
                                                                                              pCopyImageToMemoryInfo->GetMetaStructPointer(),
                                                                                              *this);
    fprintf(file, "%s", stream_pcopy_image_to_memory_info.str().c_str());
    pfn_loader_.AddMethodName("vkCopyImageToMemoryEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCopyImageToMemoryEXT(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcopy_image_to_memory_info_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCopyImageToMemoryEXT);
}

void VulkanCppConsumer::Process_vkCopyMemoryToImageEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyMemoryToImageInfoEXT>* pCopyMemoryToImageInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_memory_to_image_info;
    std::string pcopy_memory_to_image_info_struct = GenerateStruct_VkCopyMemoryToImageInfoEXT(stream_pcopy_memory_to_image_info,
                                                                                              pCopyMemoryToImageInfo->GetPointer(),
                                                                                              pCopyMemoryToImageInfo->GetMetaStructPointer(),
                                                                                              *this);
    fprintf(file, "%s", stream_pcopy_memory_to_image_info.str().c_str());
    pfn_loader_.AddMethodName("vkCopyMemoryToImageEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCopyMemoryToImageEXT(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcopy_memory_to_image_info_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_psubresource;
    std::string psubresource_struct = GenerateStruct_VkImageSubresource2KHR(stream_psubresource,
                                                                            pSubresource->GetPointer(),
                                                                            pSubresource->GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_psubresource.str().c_str());
    std::string playout_name = "pLayout_" + std::to_string(this->GetNextId());
    std::stringstream stream_playout;
    playout_name = GenerateStruct_VkSubresourceLayout2KHR(stream_playout,
                                                          pLayout->GetPointer(),
                                                          pLayout->GetMetaStructPointer(),
                                                          *this);
    fprintf(file, "%s", stream_playout.str().c_str());
    pfn_loader_.AddMethodName("vkGetImageSubresourceLayout2EXT");
    fprintf(file,
            "\t\tloaded_vkGetImageSubresourceLayout2EXT(%s, %s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(image).c_str(),
            psubresource_struct.c_str(),
            playout_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_ptransitions;
    std::string ptransitions_array = "NULL";
    PointerPairContainer<decltype(pTransitions->GetPointer()), decltype(pTransitions->GetMetaStructPointer())> ptransitions_pair{ pTransitions->GetPointer(), pTransitions->GetMetaStructPointer(), transitionCount };
    std::string ptransitions_names = toStringJoin(ptransitions_pair.begin(),
                                                  ptransitions_pair.end(),
                                                  [&](auto pair) {{ return GenerateStruct_VkHostImageLayoutTransitionInfoEXT(stream_ptransitions, pair.t1, pair.t2, *this); }},
                                                  ", ");
    if (stream_ptransitions.str().length() > 0) {
        fprintf(file, "%s", stream_ptransitions.str().c_str());
        if (transitionCount == 1) {
            ptransitions_array = "&" + ptransitions_names;
        } else if (transitionCount > 1) {
            ptransitions_array = "pTransitions_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkHostImageLayoutTransitionInfoEXT %s[] = { %s };\n", ptransitions_array.c_str(), ptransitions_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkTransitionImageLayoutEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkTransitionImageLayoutEXT(%s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            transitionCount,
            ptransitions_array.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkTransitionImageLayoutEXT);
}
void VulkanCppConsumer::Process_vkReleaseSwapchainImagesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoEXT>* pReleaseInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_prelease_info;
    std::string prelease_info_struct = GenerateStruct_VkReleaseSwapchainImagesInfoEXT(stream_prelease_info,
                                                                                      pReleaseInfo->GetPointer(),
                                                                                      pReleaseInfo->GetMetaStructPointer(),
                                                                                      *this);
    fprintf(file, "%s", stream_prelease_info.str().c_str());
    pfn_loader_.AddMethodName("vkReleaseSwapchainImagesEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkReleaseSwapchainImagesEXT(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            prelease_info_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdBindPipelineShaderGroupNV");
    fprintf(file,
            "\t\tloaded_vkCmdBindPipelineShaderGroupNV(%s, %s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineBindPoint>(pipelineBindPoint).c_str(),
            this->GetHandle(pipeline).c_str(),
            groupIndex);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV);
}

void VulkanCppConsumer::Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    isPreprocessed,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pgenerated_commands_info;
    std::string pgenerated_commands_info_struct = GenerateStruct_VkGeneratedCommandsInfoNV(stream_pgenerated_commands_info,
                                                                                           pGeneratedCommandsInfo->GetPointer(),
                                                                                           pGeneratedCommandsInfo->GetMetaStructPointer(),
                                                                                           *this);
    fprintf(file, "%s", stream_pgenerated_commands_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdExecuteGeneratedCommandsNV");
    fprintf(file,
            "\t\tloaded_vkCmdExecuteGeneratedCommandsNV(%s, %u, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            isPreprocessed,
            pgenerated_commands_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV);
}

void VulkanCppConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pgenerated_commands_info;
    std::string pgenerated_commands_info_struct = GenerateStruct_VkGeneratedCommandsInfoNV(stream_pgenerated_commands_info,
                                                                                           pGeneratedCommandsInfo->GetPointer(),
                                                                                           pGeneratedCommandsInfo->GetMetaStructPointer(),
                                                                                           *this);
    fprintf(file, "%s", stream_pgenerated_commands_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdPreprocessGeneratedCommandsNV");
    fprintf(file,
            "\t\tloaded_vkCmdPreprocessGeneratedCommandsNV(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pgenerated_commands_info_struct.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkIndirectCommandsLayoutCreateInfoNV(stream_pcreate_info,
                                                                                          pCreateInfo->GetPointer(),
                                                                                          pCreateInfo->GetMetaStructPointer(),
                                                                                          *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pindirect_commands_layout_name = "pIndirectCommandsLayout_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV));
    AddKnownVariables("VkIndirectCommandsLayoutNV", pindirect_commands_layout_name, pIndirectCommandsLayout->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pindirect_commands_layout_name,
                         pIndirectCommandsLayout->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateIndirectCommandsLayoutNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateIndirectCommandsLayoutNV(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pindirect_commands_layout_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV);
}

void VulkanCppConsumer::Process_vkDestroyIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            indirectCommandsLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyIndirectCommandsLayoutNV");
    fprintf(file,
            "\t\tloaded_vkDestroyIndirectCommandsLayoutNV(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(indirectCommandsLayout).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV);
}

void VulkanCppConsumer::Process_vkGetGeneratedCommandsMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkGeneratedCommandsMemoryRequirementsInfoNV(stream_pinfo,
                                                                                          pInfo->GetPointer(),
                                                                                          pInfo->GetMetaStructPointer(),
                                                                                          *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string pmemory_requirements_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
    std::stringstream stream_pmemory_requirements;
    pmemory_requirements_name = GenerateStruct_VkMemoryRequirements2(stream_pmemory_requirements,
                                                                     pMemoryRequirements->GetPointer(),
                                                                     pMemoryRequirements->GetMetaStructPointer(),
                                                                     *this);
    fprintf(file, "%s", stream_pmemory_requirements.str().c_str());
    pfn_loader_.AddMethodName("vkGetGeneratedCommandsMemoryRequirementsNV");
    fprintf(file,
            "\t\tloaded_vkGetGeneratedCommandsMemoryRequirementsNV(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pinfo_struct.c_str(),
            pmemory_requirements_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV);
}
void VulkanCppConsumer::Process_vkCmdSetDepthBias2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDepthBiasInfoEXT>* pDepthBiasInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdepth_bias_info;
    std::string pdepth_bias_info_struct = GenerateStruct_VkDepthBiasInfoEXT(stream_pdepth_bias_info,
                                                                            pDepthBiasInfo->GetPointer(),
                                                                            pDepthBiasInfo->GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pdepth_bias_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdSetDepthBias2EXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDepthBias2EXT(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pdepth_bias_info_struct.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkAcquireDrmDisplayEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkAcquireDrmDisplayEXT(%s, %d, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            drmFd,
            this->GetHandle(display).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string display_name = "display_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DISPLAY_KHR));
    AddKnownVariables("VkDisplayKHR", display_name, display->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(display_name,
                         display->GetPointer());
    }
    pfn_loader_.AddMethodName("vkGetDrmDisplayEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDrmDisplayEXT(%s, %d, %u, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            drmFd,
            connectorId,
            display_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkPrivateDataSlotCreateInfo(stream_pcreate_info,
                                                                                 pCreateInfo->GetPointer(),
                                                                                 pCreateInfo->GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pprivate_data_slot_name = "pPrivateDataSlot_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_PRIVATE_DATA_SLOT));
    AddKnownVariables("VkPrivateDataSlot", pprivate_data_slot_name, pPrivateDataSlot->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pprivate_data_slot_name,
                         pPrivateDataSlot->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreatePrivateDataSlotEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreatePrivateDataSlotEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pprivate_data_slot_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT);
}

void VulkanCppConsumer::Process_vkDestroyPrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyPrivateDataSlotEXT");
    fprintf(file,
            "\t\tloaded_vkDestroyPrivateDataSlotEXT(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(privateDataSlot).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pdata_name = "pData_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint64_t %s;\n", pdata_name.c_str());
    pfn_loader_.AddMethodName("vkGetPrivateDataEXT");
    fprintf(file,
            "\t\tloaded_vkGetPrivateDataEXT(%s, %s, %" PRIu64 "UL, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkObjectType>(objectType).c_str(),
            objectHandle,
            this->GetHandle(privateDataSlot).c_str(),
            pdata_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkSetPrivateDataEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkSetPrivateDataEXT(%s, %s, %" PRIu64 "UL, %s, %" PRIu64 "UL), %s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkObjectType>(objectType).c_str(),
            objectHandle,
            this->GetHandle(privateDataSlot).c_str(),
            data,
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSetPrivateDataEXT);
}
void VulkanCppConsumer::Process_vkCmdSetFragmentShadingRateEnumNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string combiner_ops_array = "NULL";
    std::string combiner_ops_values = toStringJoin(combinerOps->GetPointer(),
                                                   combinerOps->GetPointer() + 2,
                                                   [&](const format::HandleId current) { return this->GetHandle(current); },
                                                   ", ");
    fprintf(file, "\t\tVkFragmentShadingRateCombinerOpKHR %s[] = { %s };\n", combiner_ops_array.c_str(), combiner_ops_values.c_str());
    pfn_loader_.AddMethodName("vkCmdSetFragmentShadingRateEnumNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetFragmentShadingRateEnumNV(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkFragmentShadingRateNV>(shadingRate).c_str(),
            combiner_ops_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pfault_counts_name = "pFaultCounts_" + std::to_string(this->GetNextId());
    std::stringstream stream_pfault_counts;
    pfault_counts_name = GenerateStruct_VkDeviceFaultCountsEXT(stream_pfault_counts,
                                                               pFaultCounts->GetPointer(),
                                                               pFaultCounts->GetMetaStructPointer(),
                                                               *this);
    fprintf(file, "%s", stream_pfault_counts.str().c_str());
    std::string pfault_info_name = "pFaultInfo_" + std::to_string(this->GetNextId());
    std::stringstream stream_pfault_info;
    pfault_info_name = GenerateStruct_VkDeviceFaultInfoEXT(stream_pfault_info,
                                                           pFaultInfo->GetPointer(),
                                                           pFaultInfo->GetMetaStructPointer(),
                                                           *this);
    fprintf(file, "%s", stream_pfault_info.str().c_str());
    pfn_loader_.AddMethodName("vkGetDeviceFaultInfoEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDeviceFaultInfoEXT(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pfault_counts_name.c_str(),
            pfault_info_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT);
}
void VulkanCppConsumer::Process_vkAcquireWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkAcquireWinrtDisplayNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkAcquireWinrtDisplayNV(%s, %s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            this->GetHandle(display).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pdisplay_name = "pDisplay_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DISPLAY_KHR));
    AddKnownVariables("VkDisplayKHR", pdisplay_name, pDisplay->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pdisplay_name,
                         pDisplay->GetPointer());
    }
    pfn_loader_.AddMethodName("vkGetWinrtDisplayNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetWinrtDisplayNV(%s, %u, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            deviceRelativeId,
            pdisplay_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkDirectFBSurfaceCreateInfoEXT(stream_pcreate_info,
                                                                                    pCreateInfo->GetPointer(),
                                                                                    pCreateInfo->GetMetaStructPointer(),
                                                                                    *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psurface_name = "pSurface_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", psurface_name, pSurface->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(psurface_name,
                         pSurface->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateDirectFBSurfaceEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateDirectFBSurfaceEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psurface_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string dfb_name = "dfb_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tvoid* %s;\n", dfb_name.c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceDirectFBPresentationSupportEXT");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(%s, %u, %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            queueFamilyIndex,
            dfb_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pvertex_binding_descriptions;
    std::string pvertex_binding_descriptions_array = "NULL";
    PointerPairContainer<decltype(pVertexBindingDescriptions->GetPointer()), decltype(pVertexBindingDescriptions->GetMetaStructPointer())> pvertex_binding_descriptions_pair{ pVertexBindingDescriptions->GetPointer(), pVertexBindingDescriptions->GetMetaStructPointer(), vertexBindingDescriptionCount };
    std::string pvertex_binding_descriptions_names = toStringJoin(pvertex_binding_descriptions_pair.begin(),
                                                                  pvertex_binding_descriptions_pair.end(),
                                                                  [&](auto pair) {{ return GenerateStruct_VkVertexInputBindingDescription2EXT(stream_pvertex_binding_descriptions, pair.t1, pair.t2, *this); }},
                                                                  ", ");
    if (stream_pvertex_binding_descriptions.str().length() > 0) {
        fprintf(file, "%s", stream_pvertex_binding_descriptions.str().c_str());
        if (vertexBindingDescriptionCount == 1) {
            pvertex_binding_descriptions_array = "&" + pvertex_binding_descriptions_names;
        } else if (vertexBindingDescriptionCount > 1) {
            pvertex_binding_descriptions_array = "pVertexBindingDescriptions_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkVertexInputBindingDescription2EXT %s[] = { %s };\n", pvertex_binding_descriptions_array.c_str(), pvertex_binding_descriptions_names.c_str());
        }
    }
    std::stringstream stream_pvertex_attribute_descriptions;
    std::string pvertex_attribute_descriptions_array = "NULL";
    PointerPairContainer<decltype(pVertexAttributeDescriptions->GetPointer()), decltype(pVertexAttributeDescriptions->GetMetaStructPointer())> pvertex_attribute_descriptions_pair{ pVertexAttributeDescriptions->GetPointer(), pVertexAttributeDescriptions->GetMetaStructPointer(), vertexAttributeDescriptionCount };
    std::string pvertex_attribute_descriptions_names = toStringJoin(pvertex_attribute_descriptions_pair.begin(),
                                                                    pvertex_attribute_descriptions_pair.end(),
                                                                    [&](auto pair) {{ return GenerateStruct_VkVertexInputAttributeDescription2EXT(stream_pvertex_attribute_descriptions, pair.t1, pair.t2, *this); }},
                                                                    ", ");
    if (stream_pvertex_attribute_descriptions.str().length() > 0) {
        fprintf(file, "%s", stream_pvertex_attribute_descriptions.str().c_str());
        if (vertexAttributeDescriptionCount == 1) {
            pvertex_attribute_descriptions_array = "&" + pvertex_attribute_descriptions_names;
        } else if (vertexAttributeDescriptionCount > 1) {
            pvertex_attribute_descriptions_array = "pVertexAttributeDescriptions_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkVertexInputAttributeDescription2EXT %s[] = { %s };\n", pvertex_attribute_descriptions_array.c_str(), pvertex_attribute_descriptions_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdSetVertexInputEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetVertexInputEXT(%s, %u, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            vertexBindingDescriptionCount,
            pvertex_binding_descriptions_array.c_str(),
            vertexAttributeDescriptionCount,
            pvertex_attribute_descriptions_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pget_zircon_handle_info;
    std::string pget_zircon_handle_info_struct = GenerateStruct_VkMemoryGetZirconHandleInfoFUCHSIA(stream_pget_zircon_handle_info,
                                                                                                   pGetZirconHandleInfo->GetPointer(),
                                                                                                   pGetZirconHandleInfo->GetMetaStructPointer(),
                                                                                                   *this);
    fprintf(file, "%s", stream_pget_zircon_handle_info.str().c_str());
    std::string pzircon_handle_name = "pZirconHandle_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pzircon_handle_name.c_str());
    pfn_loader_.AddMethodName("vkGetMemoryZirconHandleFUCHSIA");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetMemoryZirconHandleFUCHSIA(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pget_zircon_handle_info_struct.c_str(),
            pzircon_handle_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pmemory_zircon_handle_properties_name = "pMemoryZirconHandleProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pmemory_zircon_handle_properties;
    pmemory_zircon_handle_properties_name = GenerateStruct_VkMemoryZirconHandlePropertiesFUCHSIA(stream_pmemory_zircon_handle_properties,
                                                                                                 pMemoryZirconHandleProperties->GetPointer(),
                                                                                                 pMemoryZirconHandleProperties->GetMetaStructPointer(),
                                                                                                 *this);
    fprintf(file, "%s", stream_pmemory_zircon_handle_properties.str().c_str());
    pfn_loader_.AddMethodName("vkGetMemoryZirconHandlePropertiesFUCHSIA");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetMemoryZirconHandlePropertiesFUCHSIA(%s, %s, %u, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkExternalMemoryHandleTypeFlagBits>(handleType).c_str(),
            zirconHandle,
            pmemory_zircon_handle_properties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pget_zircon_handle_info;
    std::string pget_zircon_handle_info_struct = GenerateStruct_VkSemaphoreGetZirconHandleInfoFUCHSIA(stream_pget_zircon_handle_info,
                                                                                                      pGetZirconHandleInfo->GetPointer(),
                                                                                                      pGetZirconHandleInfo->GetMetaStructPointer(),
                                                                                                      *this);
    fprintf(file, "%s", stream_pget_zircon_handle_info.str().c_str());
    std::string pzircon_handle_name = "pZirconHandle_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pzircon_handle_name.c_str());
    pfn_loader_.AddMethodName("vkGetSemaphoreZirconHandleFUCHSIA");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetSemaphoreZirconHandleFUCHSIA(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pget_zircon_handle_info_struct.c_str(),
            pzircon_handle_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA);
}

void VulkanCppConsumer::Process_vkImportSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA>* pImportSemaphoreZirconHandleInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pimport_semaphore_zircon_handle_info;
    std::string pimport_semaphore_zircon_handle_info_struct = GenerateStruct_VkImportSemaphoreZirconHandleInfoFUCHSIA(stream_pimport_semaphore_zircon_handle_info,
                                                                                                                      pImportSemaphoreZirconHandleInfo->GetPointer(),
                                                                                                                      pImportSemaphoreZirconHandleInfo->GetMetaStructPointer(),
                                                                                                                      *this);
    fprintf(file, "%s", stream_pimport_semaphore_zircon_handle_info.str().c_str());
    pfn_loader_.AddMethodName("vkImportSemaphoreZirconHandleFUCHSIA");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkImportSemaphoreZirconHandleFUCHSIA(%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pimport_semaphore_zircon_handle_info_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA);
}
void VulkanCppConsumer::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdBindInvocationMaskHUAWEI");
    fprintf(file,
            "\t\tloaded_vkCmdBindInvocationMaskHUAWEI(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(imageView).c_str(),
            util::ToString<VkImageLayout>(imageLayout).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pmemory_get_remote_address_info;
    std::string pmemory_get_remote_address_info_struct = GenerateStruct_VkMemoryGetRemoteAddressInfoNV(stream_pmemory_get_remote_address_info,
                                                                                                       pMemoryGetRemoteAddressInfo->GetPointer(),
                                                                                                       pMemoryGetRemoteAddressInfo->GetMetaStructPointer(),
                                                                                                       *this);
    fprintf(file, "%s", stream_pmemory_get_remote_address_info.str().c_str());
    std::string paddress_name = "pAddress_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint8_t* %s;\n", paddress_name.c_str());
    pfn_loader_.AddMethodName("vkGetMemoryRemoteAddressNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetMemoryRemoteAddressNV(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pmemory_get_remote_address_info_struct.c_str(),
            paddress_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV);
}
void VulkanCppConsumer::Process_vkCmdSetDepthBiasEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetDepthBiasEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDepthBiasEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            depthBiasEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetLogicOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLogicOp                                   logicOp)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetLogicOpEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetLogicOpEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkLogicOp>(logicOp).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT);
}

void VulkanCppConsumer::Process_vkCmdSetPatchControlPointsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    patchControlPoints)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetPatchControlPointsEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetPatchControlPointsEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            patchControlPoints);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT);
}

void VulkanCppConsumer::Process_vkCmdSetPrimitiveRestartEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetPrimitiveRestartEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetPrimitiveRestartEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            primitiveRestartEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetRasterizerDiscardEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetRasterizerDiscardEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetRasterizerDiscardEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            rasterizerDiscardEnable);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkScreenSurfaceCreateInfoQNX(stream_pcreate_info,
                                                                                  pCreateInfo->GetPointer(),
                                                                                  pCreateInfo->GetMetaStructPointer(),
                                                                                  *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psurface_name = "pSurface_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", psurface_name, pSurface->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(psurface_name,
                         pSurface->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateScreenSurfaceQNX");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateScreenSurfaceQNX(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(instance).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psurface_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string window_name = "window_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tvoid* %s;\n", window_name.c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceScreenPresentationSupportQNX");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceScreenPresentationSupportQNX(%s, %u, %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            queueFamilyIndex,
            window_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX);
}
void VulkanCppConsumer::Process_vkCmdSetColorWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorWriteEnables)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcolor_write_enables_array = "pColorWriteEnables_" + std::to_string(this->GetNextId());
    if (attachmentCount > 0) {
        std::string pcolor_write_enables_values = toStringJoin(pColorWriteEnables->GetPointer(),
                                                               pColorWriteEnables->GetPointer() + attachmentCount,
                                                               [&](const auto current) { return std::to_string(current) + ""; },
                                                               ", ");
        fprintf(file, "\t\tVkBool32 %s[] = { %s };\n", pcolor_write_enables_array.c_str(), pcolor_write_enables_values.c_str());
    } else {
        pcolor_write_enables_array = "NULL";
    }
    pfn_loader_.AddMethodName("vkCmdSetColorWriteEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetColorWriteEnableEXT(%s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            attachmentCount,
            pcolor_write_enables_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pvertex_info;
    std::string pvertex_info_array = "NULL";
    PointerPairContainer<decltype(pVertexInfo->GetPointer()), decltype(pVertexInfo->GetMetaStructPointer())> pvertex_info_pair{ pVertexInfo->GetPointer(), pVertexInfo->GetMetaStructPointer(), drawCount };
    std::string pvertex_info_names = toStringJoin(pvertex_info_pair.begin(),
                                                  pvertex_info_pair.end(),
                                                  [&](auto pair) {{ return GenerateStruct_VkMultiDrawInfoEXT(stream_pvertex_info, pair.t1, pair.t2, *this); }},
                                                  ", ");
    if (stream_pvertex_info.str().length() > 0) {
        fprintf(file, "%s", stream_pvertex_info.str().c_str());
        if (drawCount == 1) {
            pvertex_info_array = "&" + pvertex_info_names;
        } else if (drawCount > 1) {
            pvertex_info_array = "pVertexInfo_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkMultiDrawInfoEXT %s[] = { %s };\n", pvertex_info_array.c_str(), pvertex_info_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdDrawMultiEXT");
    fprintf(file,
            "\t\tloaded_vkCmdDrawMultiEXT(%s, %u, %s, %u, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            drawCount,
            pvertex_info_array.c_str(),
            instanceCount,
            firstInstance,
            stride);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pindex_info;
    std::string pindex_info_array = "NULL";
    PointerPairContainer<decltype(pIndexInfo->GetPointer()), decltype(pIndexInfo->GetMetaStructPointer())> pindex_info_pair{ pIndexInfo->GetPointer(), pIndexInfo->GetMetaStructPointer(), drawCount };
    std::string pindex_info_names = toStringJoin(pindex_info_pair.begin(),
                                                 pindex_info_pair.end(),
                                                 [&](auto pair) {{ return GenerateStruct_VkMultiDrawIndexedInfoEXT(stream_pindex_info, pair.t1, pair.t2, *this); }},
                                                 ", ");
    if (stream_pindex_info.str().length() > 0) {
        fprintf(file, "%s", stream_pindex_info.str().c_str());
        if (drawCount == 1) {
            pindex_info_array = "&" + pindex_info_names;
        } else if (drawCount > 1) {
            pindex_info_array = "pIndexInfo_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkMultiDrawIndexedInfoEXT %s[] = { %s };\n", pindex_info_array.c_str(), pindex_info_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdDrawMultiIndexedEXT");
    fprintf(file,
            "\t\tloaded_vkCmdDrawMultiIndexedEXT(%s, %u, %s, %u, %u, %u, %p);\n",
            this->GetHandle(commandBuffer).c_str(),
            drawCount,
            pindex_info_array.c_str(),
            instanceCount,
            firstInstance,
            stride,
            pVertexOffset->GetPointer());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfos;
    std::string pinfos_array = "NULL";
    PointerPairContainer<decltype(pInfos->GetPointer()), decltype(pInfos->GetMetaStructPointer())> pinfos_pair{ pInfos->GetPointer(), pInfos->GetMetaStructPointer(), infoCount };
    std::string pinfos_names = toStringJoin(pinfos_pair.begin(),
                                            pinfos_pair.end(),
                                            [&](auto pair) {{ return GenerateStruct_VkMicromapBuildInfoEXT(stream_pinfos, pair.t1, pair.t2, *this); }},
                                            ", ");
    if (stream_pinfos.str().length() > 0) {
        fprintf(file, "%s", stream_pinfos.str().c_str());
        if (infoCount == 1) {
            pinfos_array = "&" + pinfos_names;
        } else if (infoCount > 1) {
            pinfos_array = "pInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkMicromapBuildInfoEXT %s[] = { %s };\n", pinfos_array.c_str(), pinfos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkBuildMicromapsEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkBuildMicromapsEXT(%s, %s, %u, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(deferredOperation).c_str(),
            infoCount,
            pinfos_array.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBuildMicromapsEXT);
}

void VulkanCppConsumer::Process_vkCmdBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfos;
    std::string pinfos_array = "NULL";
    PointerPairContainer<decltype(pInfos->GetPointer()), decltype(pInfos->GetMetaStructPointer())> pinfos_pair{ pInfos->GetPointer(), pInfos->GetMetaStructPointer(), infoCount };
    std::string pinfos_names = toStringJoin(pinfos_pair.begin(),
                                            pinfos_pair.end(),
                                            [&](auto pair) {{ return GenerateStruct_VkMicromapBuildInfoEXT(stream_pinfos, pair.t1, pair.t2, *this); }},
                                            ", ");
    if (stream_pinfos.str().length() > 0) {
        fprintf(file, "%s", stream_pinfos.str().c_str());
        if (infoCount == 1) {
            pinfos_array = "&" + pinfos_names;
        } else if (infoCount > 1) {
            pinfos_array = "pInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkMicromapBuildInfoEXT %s[] = { %s };\n", pinfos_array.c_str(), pinfos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdBuildMicromapsEXT");
    fprintf(file,
            "\t\tloaded_vkCmdBuildMicromapsEXT(%s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            infoCount,
            pinfos_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT);
}

void VulkanCppConsumer::Process_vkCmdCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkCopyMemoryToMicromapInfoEXT(stream_pinfo,
                                                                            pInfo->GetPointer(),
                                                                            pInfo->GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyMemoryToMicromapEXT");
    fprintf(file,
            "\t\tloaded_vkCmdCopyMemoryToMicromapEXT(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT);
}

void VulkanCppConsumer::Process_vkCmdCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkCopyMicromapInfoEXT(stream_pinfo,
                                                                    pInfo->GetPointer(),
                                                                    pInfo->GetMetaStructPointer(),
                                                                    *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyMicromapEXT");
    fprintf(file,
            "\t\tloaded_vkCmdCopyMicromapEXT(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT);
}

void VulkanCppConsumer::Process_vkCmdCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkCopyMicromapToMemoryInfoEXT(stream_pinfo,
                                                                            pInfo->GetPointer(),
                                                                            pInfo->GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyMicromapToMemoryEXT");
    fprintf(file,
            "\t\tloaded_vkCmdCopyMicromapToMemoryEXT(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pmicromaps_array = "NULL";
    std::string pmicromaps_values = toStringJoin(pMicromaps->GetPointer(),
                                                 pMicromaps->GetPointer() + micromapCount,
                                                 [&](const format::HandleId current) { return this->GetHandle(current); },
                                                 ", ");
    if (micromapCount == 1 && pmicromaps_values != "VK_NULL_HANDLE") {
        pmicromaps_array = "&" + pmicromaps_values;
    } else if (micromapCount > 1) {
        pmicromaps_array = "pmicromaps_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkMicromapEXT %s[] = { %s };\n", pmicromaps_array.c_str(), pmicromaps_values.c_str());
    }
    pfn_loader_.AddMethodName("vkCmdWriteMicromapsPropertiesEXT");
    fprintf(file,
            "\t\tloaded_vkCmdWriteMicromapsPropertiesEXT(%s, %u, %s, %s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            micromapCount,
            pmicromaps_array.c_str(),
            util::ToString<VkQueryType>(queryType).c_str(),
            this->GetHandle(queryPool).c_str(),
            firstQuery);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkCopyMemoryToMicromapInfoEXT(stream_pinfo,
                                                                            pInfo->GetPointer(),
                                                                            pInfo->GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCopyMemoryToMicromapEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCopyMemoryToMicromapEXT(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(deferredOperation).c_str(),
            pinfo_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkCopyMicromapInfoEXT(stream_pinfo,
                                                                    pInfo->GetPointer(),
                                                                    pInfo->GetMetaStructPointer(),
                                                                    *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCopyMicromapEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCopyMicromapEXT(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(deferredOperation).c_str(),
            pinfo_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkCopyMicromapToMemoryInfoEXT(stream_pinfo,
                                                                            pInfo->GetPointer(),
                                                                            pInfo->GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCopyMicromapToMemoryEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCopyMicromapToMemoryEXT(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(deferredOperation).c_str(),
            pinfo_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkMicromapCreateInfoEXT(stream_pcreate_info,
                                                                             pCreateInfo->GetPointer(),
                                                                             pCreateInfo->GetMetaStructPointer(),
                                                                             *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pmicromap_name = "pMicromap_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_MICROMAP_EXT));
    AddKnownVariables("VkMicromapEXT", pmicromap_name, pMicromap->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pmicromap_name,
                         pMicromap->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateMicromapEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateMicromapEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pmicromap_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateMicromapEXT);
}

void VulkanCppConsumer::Process_vkDestroyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            micromap,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyMicromapEXT");
    fprintf(file,
            "\t\tloaded_vkDestroyMicromapEXT(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(micromap).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyMicromapEXT);
}

void VulkanCppConsumer::Process_vkGetDeviceMicromapCompatibilityEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMicromapVersionInfoEXT>* pVersionInfo,
    PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pversion_info;
    std::string pversion_info_struct = GenerateStruct_VkMicromapVersionInfoEXT(stream_pversion_info,
                                                                               pVersionInfo->GetPointer(),
                                                                               pVersionInfo->GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_pversion_info.str().c_str());
    std::string pcompatibility_name = "pCompatibility_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tVkAccelerationStructureCompatibilityKHR %s;\n", pcompatibility_name.c_str());
    pfn_loader_.AddMethodName("vkGetDeviceMicromapCompatibilityEXT");
    fprintf(file,
            "\t\tloaded_vkGetDeviceMicromapCompatibilityEXT(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pversion_info_struct.c_str(),
            pcompatibility_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pbuild_info;
    std::string pbuild_info_struct = GenerateStruct_VkMicromapBuildInfoEXT(stream_pbuild_info,
                                                                           pBuildInfo->GetPointer(),
                                                                           pBuildInfo->GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_pbuild_info.str().c_str());
    std::string psize_info_name = "pSizeInfo_" + std::to_string(this->GetNextId());
    std::stringstream stream_psize_info;
    psize_info_name = GenerateStruct_VkMicromapBuildSizesInfoEXT(stream_psize_info,
                                                                 pSizeInfo->GetPointer(),
                                                                 pSizeInfo->GetMetaStructPointer(),
                                                                 *this);
    fprintf(file, "%s", stream_psize_info.str().c_str());
    pfn_loader_.AddMethodName("vkGetMicromapBuildSizesEXT");
    fprintf(file,
            "\t\tloaded_vkGetMicromapBuildSizesEXT(%s, %s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkAccelerationStructureBuildTypeKHR>(buildType).c_str(),
            pbuild_info_struct.c_str(),
            psize_info_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pmicromaps_array = "NULL";
    std::string pmicromaps_values = toStringJoin(pMicromaps->GetPointer(),
                                                 pMicromaps->GetPointer() + micromapCount,
                                                 [&](const format::HandleId current) { return this->GetHandle(current); },
                                                 ", ");
    if (micromapCount == 1 && pmicromaps_values != "VK_NULL_HANDLE") {
        pmicromaps_array = "&" + pmicromaps_values;
    } else if (micromapCount > 1) {
        pmicromaps_array = "pmicromaps_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkMicromapEXT %s[] = { %s };\n", pmicromaps_array.c_str(), pmicromaps_values.c_str());
    }
    std::string pdata_name = "pData_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint8_t %s[%" PRIu64 "];\n", pdata_name.c_str(), util::platform::SizeTtoUint64(dataSize));
    pfn_loader_.AddMethodName("vkWriteMicromapsPropertiesEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkWriteMicromapsPropertiesEXT(%s, %u, %s, %s, %" PRIu64 ", %s, %" PRIu64 "), %s);\n",
            this->GetHandle(device).c_str(),
            micromapCount,
            pmicromaps_array.c_str(),
            util::ToString<VkQueryType>(queryType).c_str(),
            util::platform::SizeTtoUint64(dataSize),
            pdata_name.c_str(),
            util::platform::SizeTtoUint64(stride),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawClusterHUAWEI");
    fprintf(file,
            "\t\tloaded_vkCmdDrawClusterHUAWEI(%s, %u, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            groupCountX,
            groupCountY,
            groupCountZ);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI);
}

void VulkanCppConsumer::Process_vkCmdDrawClusterIndirectHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawClusterIndirectHUAWEI");
    fprintf(file,
            "\t\tloaded_vkCmdDrawClusterIndirectHUAWEI(%s, %s, %" PRIu64 "UL);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI);
}
void VulkanCppConsumer::Process_vkSetDeviceMemoryPriorityEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    float                                       priority)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkSetDeviceMemoryPriorityEXT");
    fprintf(file,
            "\t\tloaded_vkSetDeviceMemoryPriorityEXT(%s, %s, %f);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(memory).c_str(),
            priority);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT);
}
void VulkanCppConsumer::Process_vkGetDescriptorSetHostMappingVALVE(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSet,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pp_data_name = "ppData_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint8_t* %s;\n", pp_data_name.c_str());
    pfn_loader_.AddMethodName("vkGetDescriptorSetHostMappingVALVE");
    fprintf(file,
            "\t\tloaded_vkGetDescriptorSetHostMappingVALVE(%s, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(descriptorSet).c_str(),
            pp_data_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE);
}

void VulkanCppConsumer::Process_vkGetDescriptorSetLayoutHostMappingInfoVALVE(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetBindingReferenceVALVE>* pBindingReference,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE>* pHostMapping)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbinding_reference;
    std::string pbinding_reference_struct = GenerateStruct_VkDescriptorSetBindingReferenceVALVE(stream_pbinding_reference,
                                                                                                pBindingReference->GetPointer(),
                                                                                                pBindingReference->GetMetaStructPointer(),
                                                                                                *this);
    fprintf(file, "%s", stream_pbinding_reference.str().c_str());
    std::string phost_mapping_name = "pHostMapping_" + std::to_string(this->GetNextId());
    std::stringstream stream_phost_mapping;
    phost_mapping_name = GenerateStruct_VkDescriptorSetLayoutHostMappingInfoVALVE(stream_phost_mapping,
                                                                                  pHostMapping->GetPointer(),
                                                                                  pHostMapping->GetMetaStructPointer(),
                                                                                  *this);
    fprintf(file, "%s", stream_phost_mapping.str().c_str());
    pfn_loader_.AddMethodName("vkGetDescriptorSetLayoutHostMappingInfoVALVE");
    fprintf(file,
            "\t\tloaded_vkGetDescriptorSetLayoutHostMappingInfoVALVE(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pbinding_reference_struct.c_str(),
            phost_mapping_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE);
}
void VulkanCppConsumer::Process_vkCmdUpdatePipelineIndirectBufferNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdUpdatePipelineIndirectBufferNV");
    fprintf(file,
            "\t\tloaded_vkCmdUpdatePipelineIndirectBufferNV(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPipelineBindPoint>(pipelineBindPoint).c_str(),
            this->GetHandle(pipeline).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdUpdatePipelineIndirectBufferNV);
}

void VulkanCppConsumer::Process_vkGetPipelineIndirectDeviceAddressNV(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineIndirectDeviceAddressInfoNV>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkPipelineIndirectDeviceAddressInfoNV(stream_pinfo,
                                                                                    pInfo->GetPointer(),
                                                                                    pInfo->GetMetaStructPointer(),
                                                                                    *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkGetPipelineIndirectDeviceAddressNV");
    fprintf(file,
            "\t\tloaded_vkGetPipelineIndirectDeviceAddressNV(%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPipelineIndirectDeviceAddressNV);
}

void VulkanCppConsumer::Process_vkGetPipelineIndirectMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkComputePipelineCreateInfo(stream_pcreate_info,
                                                                                 pCreateInfo->GetPointer(),
                                                                                 pCreateInfo->GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pmemory_requirements_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
    std::stringstream stream_pmemory_requirements;
    pmemory_requirements_name = GenerateStruct_VkMemoryRequirements2(stream_pmemory_requirements,
                                                                     pMemoryRequirements->GetPointer(),
                                                                     pMemoryRequirements->GetMetaStructPointer(),
                                                                     *this);
    fprintf(file, "%s", stream_pmemory_requirements.str().c_str());
    pfn_loader_.AddMethodName("vkGetPipelineIndirectMemoryRequirementsNV");
    fprintf(file,
            "\t\tloaded_vkGetPipelineIndirectMemoryRequirementsNV(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            pmemory_requirements_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPipelineIndirectMemoryRequirementsNV);
}
void VulkanCppConsumer::Process_vkCmdSetAlphaToCoverageEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToCoverageEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetAlphaToCoverageEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetAlphaToCoverageEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            alphaToCoverageEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetAlphaToOneEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToOneEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetAlphaToOneEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetAlphaToOneEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            alphaToOneEnable);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcolor_blend_advanced;
    std::string pcolor_blend_advanced_array = "NULL";
    PointerPairContainer<decltype(pColorBlendAdvanced->GetPointer()), decltype(pColorBlendAdvanced->GetMetaStructPointer())> pcolor_blend_advanced_pair{ pColorBlendAdvanced->GetPointer(), pColorBlendAdvanced->GetMetaStructPointer(), attachmentCount };
    std::string pcolor_blend_advanced_names = toStringJoin(pcolor_blend_advanced_pair.begin(),
                                                           pcolor_blend_advanced_pair.end(),
                                                           [&](auto pair) {{ return GenerateStruct_VkColorBlendAdvancedEXT(stream_pcolor_blend_advanced, pair.t1, pair.t2, *this); }},
                                                           ", ");
    if (stream_pcolor_blend_advanced.str().length() > 0) {
        fprintf(file, "%s", stream_pcolor_blend_advanced.str().c_str());
        if (attachmentCount == 1) {
            pcolor_blend_advanced_array = "&" + pcolor_blend_advanced_names;
        } else if (attachmentCount > 1) {
            pcolor_blend_advanced_array = "pColorBlendAdvanced_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkColorBlendAdvancedEXT %s[] = { %s };\n", pcolor_blend_advanced_array.c_str(), pcolor_blend_advanced_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdSetColorBlendAdvancedEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetColorBlendAdvancedEXT(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstAttachment,
            attachmentCount,
            pcolor_blend_advanced_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pcolor_blend_enables_array = "pColorBlendEnables_" + std::to_string(this->GetNextId());
    if (attachmentCount > 0) {
        std::string pcolor_blend_enables_values = toStringJoin(pColorBlendEnables->GetPointer(),
                                                               pColorBlendEnables->GetPointer() + attachmentCount,
                                                               [&](const auto current) { return std::to_string(current) + ""; },
                                                               ", ");
        fprintf(file, "\t\tVkBool32 %s[] = { %s };\n", pcolor_blend_enables_array.c_str(), pcolor_blend_enables_values.c_str());
    } else {
        pcolor_blend_enables_array = "NULL";
    }
    pfn_loader_.AddMethodName("vkCmdSetColorBlendEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetColorBlendEnableEXT(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstAttachment,
            attachmentCount,
            pcolor_blend_enables_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcolor_blend_equations;
    std::string pcolor_blend_equations_array = "NULL";
    PointerPairContainer<decltype(pColorBlendEquations->GetPointer()), decltype(pColorBlendEquations->GetMetaStructPointer())> pcolor_blend_equations_pair{ pColorBlendEquations->GetPointer(), pColorBlendEquations->GetMetaStructPointer(), attachmentCount };
    std::string pcolor_blend_equations_names = toStringJoin(pcolor_blend_equations_pair.begin(),
                                                            pcolor_blend_equations_pair.end(),
                                                            [&](auto pair) {{ return GenerateStruct_VkColorBlendEquationEXT(stream_pcolor_blend_equations, pair.t1, pair.t2, *this); }},
                                                            ", ");
    if (stream_pcolor_blend_equations.str().length() > 0) {
        fprintf(file, "%s", stream_pcolor_blend_equations.str().c_str());
        if (attachmentCount == 1) {
            pcolor_blend_equations_array = "&" + pcolor_blend_equations_names;
        } else if (attachmentCount > 1) {
            pcolor_blend_equations_array = "pColorBlendEquations_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkColorBlendEquationEXT %s[] = { %s };\n", pcolor_blend_equations_array.c_str(), pcolor_blend_equations_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdSetColorBlendEquationEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetColorBlendEquationEXT(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstAttachment,
            attachmentCount,
            pcolor_blend_equations_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pcolor_write_masks_array = "NULL";
    std::string pcolor_write_masks_values = toStringJoin(pColorWriteMasks->GetPointer(),
                                                         pColorWriteMasks->GetPointer() + attachmentCount,
                                                         [&](const format::HandleId current) { return this->GetHandle(current); },
                                                         ", ");
    if (attachmentCount == 1) {
        pcolor_write_masks_array = "&" + pcolor_write_masks_values;
    } else if (attachmentCount > 1) {
        pcolor_write_masks_array = "pcolor_write_masks_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkColorComponentFlags %s[] = { %s };\n", pcolor_write_masks_array.c_str(), pcolor_write_masks_values.c_str());
    }
    pfn_loader_.AddMethodName("vkCmdSetColorWriteMaskEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetColorWriteMaskEXT(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstAttachment,
            attachmentCount,
            pcolor_write_masks_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT);
}

void VulkanCppConsumer::Process_vkCmdSetConservativeRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetConservativeRasterizationModeEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetConservativeRasterizationModeEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkConservativeRasterizationModeEXT>(conservativeRasterizationMode).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT);
}

void VulkanCppConsumer::Process_vkCmdSetCoverageModulationModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetCoverageModulationModeNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetCoverageModulationModeNV(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkCoverageModulationModeNV>(coverageModulationMode).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV);
}

void VulkanCppConsumer::Process_vkCmdSetCoverageModulationTableEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageModulationTableEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetCoverageModulationTableEnableNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetCoverageModulationTableEnableNV(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            coverageModulationTableEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV);
}

void VulkanCppConsumer::Process_vkCmdSetCoverageModulationTableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    PointerDecoder<float>*                      pCoverageModulationTable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcoverage_modulation_table_array = "pCoverageModulationTable_" + std::to_string(this->GetNextId());
    if (coverageModulationTableCount > 0) {
        std::string pcoverage_modulation_table_values = toStringJoin(pCoverageModulationTable->GetPointer(),
                                                                     pCoverageModulationTable->GetPointer() + coverageModulationTableCount,
                                                                     [&](const auto current) { return std::to_string(current) + ""; },
                                                                     ", ");
        fprintf(file, "\t\tfloat %s[] = { %s };\n", pcoverage_modulation_table_array.c_str(), pcoverage_modulation_table_values.c_str());
    } else {
        pcoverage_modulation_table_array = "NULL";
    }
    pfn_loader_.AddMethodName("vkCmdSetCoverageModulationTableNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetCoverageModulationTableNV(%s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            coverageModulationTableCount,
            pcoverage_modulation_table_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV);
}

void VulkanCppConsumer::Process_vkCmdSetCoverageReductionModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetCoverageReductionModeNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetCoverageReductionModeNV(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkCoverageReductionModeNV>(coverageReductionMode).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV);
}

void VulkanCppConsumer::Process_vkCmdSetCoverageToColorEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageToColorEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetCoverageToColorEnableNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetCoverageToColorEnableNV(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            coverageToColorEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV);
}

void VulkanCppConsumer::Process_vkCmdSetCoverageToColorLocationNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageToColorLocation)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetCoverageToColorLocationNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetCoverageToColorLocationNV(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            coverageToColorLocation);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV);
}

void VulkanCppConsumer::Process_vkCmdSetDepthClampEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClampEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetDepthClampEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDepthClampEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            depthClampEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDepthClipEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClipEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetDepthClipEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDepthClipEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            depthClipEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDepthClipNegativeOneToOneEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    negativeOneToOne)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetDepthClipNegativeOneToOneEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDepthClipNegativeOneToOneEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            negativeOneToOne);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT);
}

void VulkanCppConsumer::Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       extraPrimitiveOverestimationSize)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetExtraPrimitiveOverestimationSizeEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetExtraPrimitiveOverestimationSizeEXT(%s, %f);\n",
            this->GetHandle(commandBuffer).c_str(),
            extraPrimitiveOverestimationSize);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT);
}

void VulkanCppConsumer::Process_vkCmdSetLineRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetLineRasterizationModeEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetLineRasterizationModeEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkLineRasterizationModeEXT>(lineRasterizationMode).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT);
}

void VulkanCppConsumer::Process_vkCmdSetLineStippleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stippledLineEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetLineStippleEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetLineStippleEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            stippledLineEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetLogicOpEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    logicOpEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetLogicOpEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetLogicOpEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            logicOpEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetPolygonModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPolygonMode                               polygonMode)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetPolygonModeEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetPolygonModeEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkPolygonMode>(polygonMode).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT);
}

void VulkanCppConsumer::Process_vkCmdSetProvokingVertexModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetProvokingVertexModeEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetProvokingVertexModeEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkProvokingVertexModeEXT>(provokingVertexMode).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT);
}

void VulkanCppConsumer::Process_vkCmdSetRasterizationSamplesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetRasterizationSamplesEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetRasterizationSamplesEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkSampleCountFlagBits>(rasterizationSamples).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT);
}

void VulkanCppConsumer::Process_vkCmdSetRasterizationStreamEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    rasterizationStream)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetRasterizationStreamEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetRasterizationStreamEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            rasterizationStream);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT);
}

void VulkanCppConsumer::Process_vkCmdSetRepresentativeFragmentTestEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    representativeFragmentTestEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetRepresentativeFragmentTestEnableNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetRepresentativeFragmentTestEnableNV(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            representativeFragmentTestEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV);
}

void VulkanCppConsumer::Process_vkCmdSetSampleLocationsEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    sampleLocationsEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetSampleLocationsEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetSampleLocationsEnableEXT(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            sampleLocationsEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetSampleMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       samples,
    PointerDecoder<VkSampleMask>*               pSampleMask)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string psample_mask_array = "pSampleMask_" + std::to_string(this->GetNextId());
    if ((samples + 31) / 32 > 0) {
        std::string psample_mask_values = toStringJoin(pSampleMask->GetPointer(),
                                                       pSampleMask->GetPointer() + (samples + 31) / 32,
                                                       [&](const auto current) { return std::to_string(current) + ""; },
                                                       ", ");
        fprintf(file, "\t\tVkSampleMask %s[] = { %s };\n", psample_mask_array.c_str(), psample_mask_values.c_str());
    } else {
        psample_mask_array = "NULL";
    }
    pfn_loader_.AddMethodName("vkCmdSetSampleMaskEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetSampleMaskEXT(%s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkSampleCountFlagBits>(samples).c_str(),
            psample_mask_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT);
}

void VulkanCppConsumer::Process_vkCmdSetShadingRateImageEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    shadingRateImageEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetShadingRateImageEnableNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetShadingRateImageEnableNV(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            shadingRateImageEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV);
}

void VulkanCppConsumer::Process_vkCmdSetTessellationDomainOriginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetTessellationDomainOriginEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetTessellationDomainOriginEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkTessellationDomainOrigin>(domainOrigin).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pviewport_swizzles;
    std::string pviewport_swizzles_array = "NULL";
    PointerPairContainer<decltype(pViewportSwizzles->GetPointer()), decltype(pViewportSwizzles->GetMetaStructPointer())> pviewport_swizzles_pair{ pViewportSwizzles->GetPointer(), pViewportSwizzles->GetMetaStructPointer(), viewportCount };
    std::string pviewport_swizzles_names = toStringJoin(pviewport_swizzles_pair.begin(),
                                                        pviewport_swizzles_pair.end(),
                                                        [&](auto pair) {{ return GenerateStruct_VkViewportSwizzleNV(stream_pviewport_swizzles, pair.t1, pair.t2, *this); }},
                                                        ", ");
    if (stream_pviewport_swizzles.str().length() > 0) {
        fprintf(file, "%s", stream_pviewport_swizzles.str().c_str());
        if (viewportCount == 1) {
            pviewport_swizzles_array = "&" + pviewport_swizzles_names;
        } else if (viewportCount > 1) {
            pviewport_swizzles_array = "pViewportSwizzles_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkViewportSwizzleNV %s[] = { %s };\n", pviewport_swizzles_array.c_str(), pviewport_swizzles_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdSetViewportSwizzleNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetViewportSwizzleNV(%s, %u, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            firstViewport,
            viewportCount,
            pviewport_swizzles_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV);
}

void VulkanCppConsumer::Process_vkCmdSetViewportWScalingEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    viewportWScalingEnable)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetViewportWScalingEnableNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetViewportWScalingEnableNV(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            viewportWScalingEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV);
}
void VulkanCppConsumer::Process_vkGetShaderModuleCreateInfoIdentifierEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkShaderModuleCreateInfo(stream_pcreate_info,
                                                                              pCreateInfo->GetPointer(),
                                                                              pCreateInfo->GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pidentifier_name = "pIdentifier_" + std::to_string(this->GetNextId());
    std::stringstream stream_pidentifier;
    pidentifier_name = GenerateStruct_VkShaderModuleIdentifierEXT(stream_pidentifier,
                                                                  pIdentifier->GetPointer(),
                                                                  pIdentifier->GetMetaStructPointer(),
                                                                  *this);
    fprintf(file, "%s", stream_pidentifier.str().c_str());
    pfn_loader_.AddMethodName("vkGetShaderModuleCreateInfoIdentifierEXT");
    fprintf(file,
            "\t\tloaded_vkGetShaderModuleCreateInfoIdentifierEXT(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            pidentifier_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT);
}

void VulkanCppConsumer::Process_vkGetShaderModuleIdentifierEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pidentifier_name = "pIdentifier_" + std::to_string(this->GetNextId());
    std::stringstream stream_pidentifier;
    pidentifier_name = GenerateStruct_VkShaderModuleIdentifierEXT(stream_pidentifier,
                                                                  pIdentifier->GetPointer(),
                                                                  pIdentifier->GetMetaStructPointer(),
                                                                  *this);
    fprintf(file, "%s", stream_pidentifier.str().c_str());
    pfn_loader_.AddMethodName("vkGetShaderModuleIdentifierEXT");
    fprintf(file,
            "\t\tloaded_vkGetShaderModuleIdentifierEXT(%s, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(shaderModule).c_str(),
            pidentifier_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkBindOpticalFlowSessionImageNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkBindOpticalFlowSessionImageNV(%s, %s, %s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(session).c_str(),
            util::ToString<VkOpticalFlowSessionBindingPointNV>(bindingPoint).c_str(),
            this->GetHandle(view).c_str(),
            util::ToString<VkImageLayout>(layout).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV);
}

void VulkanCppConsumer::Process_vkCmdOpticalFlowExecuteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV>* pExecuteInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pexecute_info;
    std::string pexecute_info_struct = GenerateStruct_VkOpticalFlowExecuteInfoNV(stream_pexecute_info,
                                                                                 pExecuteInfo->GetPointer(),
                                                                                 pExecuteInfo->GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_pexecute_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdOpticalFlowExecuteNV");
    fprintf(file,
            "\t\tloaded_vkCmdOpticalFlowExecuteNV(%s, %s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(session).c_str(),
            pexecute_info_struct.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkOpticalFlowSessionCreateInfoNV(stream_pcreate_info,
                                                                                      pCreateInfo->GetPointer(),
                                                                                      pCreateInfo->GetMetaStructPointer(),
                                                                                      *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psession_name = "pSession_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_OPTICAL_FLOW_SESSION_NV));
    AddKnownVariables("VkOpticalFlowSessionNV", psession_name, pSession->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(psession_name,
                         pSession->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateOpticalFlowSessionNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateOpticalFlowSessionNV(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psession_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV);
}

void VulkanCppConsumer::Process_vkDestroyOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyOpticalFlowSessionNV");
    fprintf(file,
            "\t\tloaded_vkDestroyOpticalFlowSessionNV(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(session).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_poptical_flow_image_format_info;
    std::string poptical_flow_image_format_info_struct = GenerateStruct_VkOpticalFlowImageFormatInfoNV(stream_poptical_flow_image_format_info,
                                                                                                       pOpticalFlowImageFormatInfo->GetPointer(),
                                                                                                       pOpticalFlowImageFormatInfo->GetMetaStructPointer(),
                                                                                                       *this);
    fprintf(file, "%s", stream_poptical_flow_image_format_info.str().c_str());
    std::string pformat_count_name = "pFormatCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pformat_count_name.c_str());
    std::string pimage_format_properties_name = "pImageFormatProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pimage_format_properties;
    pimage_format_properties_name = GenerateStruct_VkOpticalFlowImageFormatPropertiesNV(stream_pimage_format_properties,
                                                                                        pImageFormatProperties->GetPointer(),
                                                                                        pImageFormatProperties->GetMetaStructPointer(),
                                                                                        *this);
    fprintf(file, "%s", stream_pimage_format_properties.str().c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceOpticalFlowImageFormatsNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(%s, &%s, &%s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            poptical_flow_image_format_info_struct.c_str(),
            pformat_count_name.c_str(),
            pimage_format_properties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pstages_array = "NULL";
    std::string pstages_values = toStringJoin(pStages->GetPointer(),
                                              pStages->GetPointer() + stageCount,
                                              [&](const format::HandleId current) { return this->GetHandle(current); },
                                              ", ");
    if (stageCount == 1) {
        pstages_array = "&" + pstages_values;
    } else if (stageCount > 1) {
        pstages_array = "pstages_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkShaderStageFlagBits %s[] = { %s };\n", pstages_array.c_str(), pstages_values.c_str());
    }
    std::string pshaders_array = "NULL";
    std::string pshaders_values = toStringJoin(pShaders->GetPointer(),
                                               pShaders->GetPointer() + stageCount,
                                               [&](const format::HandleId current) { return this->GetHandle(current); },
                                               ", ");
    if (stageCount == 1 && pshaders_values != "VK_NULL_HANDLE") {
        pshaders_array = "&" + pshaders_values;
    } else if (stageCount > 1) {
        pshaders_array = "pshaders_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkShaderEXT %s[] = { %s };\n", pshaders_array.c_str(), pshaders_values.c_str());
    }
    pfn_loader_.AddMethodName("vkCmdBindShadersEXT");
    fprintf(file,
            "\t\tloaded_vkCmdBindShadersEXT(%s, %u, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            stageCount,
            pstages_array.c_str(),
            pshaders_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_infos;
    std::string pcreate_infos_array = "NULL";
    PointerPairContainer<decltype(pCreateInfos->GetPointer()), decltype(pCreateInfos->GetMetaStructPointer())> pcreate_infos_pair{ pCreateInfos->GetPointer(), pCreateInfos->GetMetaStructPointer(), createInfoCount };
    std::string pcreate_infos_names = toStringJoin(pcreate_infos_pair.begin(),
                                                   pcreate_infos_pair.end(),
                                                   [&](auto pair) {{ return GenerateStruct_VkShaderCreateInfoEXT(stream_pcreate_infos, pair.t1, pair.t2, *this); }},
                                                   ", ");
    if (stream_pcreate_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pcreate_infos.str().c_str());
        if (createInfoCount == 1) {
            pcreate_infos_array = "&" + pcreate_infos_names;
        } else if (createInfoCount > 1) {
            pcreate_infos_array = "pCreateInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkShaderCreateInfoEXT %s[] = { %s };\n", pcreate_infos_array.c_str(), pcreate_infos_names.c_str());
        }
    }
    std::string pshaders_name = "pShaders_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SHADER_EXT));
    AddKnownVariables("VkShaderEXT", pshaders_name, pShaders->GetPointer(), createInfoCount);
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pshaders_name,
                         pShaders->GetPointer(), createInfoCount);
    }
    pfn_loader_.AddMethodName("vkCreateShadersEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateShadersEXT(%s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            createInfoCount,
            pcreate_infos_array.c_str(),
            "nullptr",
            pshaders_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateShadersEXT);
}

void VulkanCppConsumer::Process_vkDestroyShaderEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shader,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyShaderEXT");
    fprintf(file,
            "\t\tloaded_vkDestroyShaderEXT(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(shader).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pdata_size_name = "pDataSize_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tsize_t %s;\n", pdata_size_name.c_str());
    std::string pdata_name = "pData_" + std::to_string(this->GetNextId());
    size_t* in_pdata_size = pDataSize->GetPointer();
    fprintf(file, "\t\tuint8_t %s[%" PRIu64 "];\n", pdata_name.c_str(), util::platform::SizeTtoUint64(*in_pdata_size));
    pfn_loader_.AddMethodName("vkGetShaderBinaryDataEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetShaderBinaryDataEXT(%s, %s, &%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(shader).c_str(),
            pdata_size_name.c_str(),
            pdata_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_prendering_info;
    std::string prendering_info_struct = GenerateStruct_VkRenderingInfo(stream_prendering_info,
                                                                        pRenderingInfo->GetPointer(),
                                                                        pRenderingInfo->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_prendering_info.str().c_str());
    std::string pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pproperties;
    pproperties_name = GenerateStruct_VkTilePropertiesQCOM(stream_pproperties,
                                                           pProperties->GetPointer(),
                                                           pProperties->GetMetaStructPointer(),
                                                           *this);
    fprintf(file, "%s", stream_pproperties.str().c_str());
    pfn_loader_.AddMethodName("vkGetDynamicRenderingTilePropertiesQCOM");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDynamicRenderingTilePropertiesQCOM(%s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            prendering_info_struct.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pproperties_count_name = "pPropertiesCount_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint32_t %s;\n", pproperties_count_name.c_str());
    std::string pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
    std::stringstream stream_pproperties;
    pproperties_name = GenerateStruct_VkTilePropertiesQCOM(stream_pproperties,
                                                           pProperties->GetPointer(),
                                                           pProperties->GetMetaStructPointer(),
                                                           *this);
    fprintf(file, "%s", stream_pproperties.str().c_str());
    pfn_loader_.AddMethodName("vkGetFramebufferTilePropertiesQCOM");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetFramebufferTilePropertiesQCOM(%s, %s, &%s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(framebuffer).c_str(),
            pproperties_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM);
}
void VulkanCppConsumer::Process_vkGetLatencyTimingsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkGetLatencyMarkerInfoNV>* pLatencyMarkerInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string platency_marker_info_name = "pLatencyMarkerInfo_" + std::to_string(this->GetNextId());
    std::stringstream stream_platency_marker_info;
    platency_marker_info_name = GenerateStruct_VkGetLatencyMarkerInfoNV(stream_platency_marker_info,
                                                                        pLatencyMarkerInfo->GetPointer(),
                                                                        pLatencyMarkerInfo->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_platency_marker_info.str().c_str());
    pfn_loader_.AddMethodName("vkGetLatencyTimingsNV");
    fprintf(file,
            "\t\tloaded_vkGetLatencyTimingsNV(%s, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapchain).c_str(),
            platency_marker_info_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetLatencyTimingsNV);
}

void VulkanCppConsumer::Process_vkLatencySleepNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkLatencySleepInfoNV>* pSleepInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psleep_info;
    std::string psleep_info_struct = GenerateStruct_VkLatencySleepInfoNV(stream_psleep_info,
                                                                         pSleepInfo->GetPointer(),
                                                                         pSleepInfo->GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "%s", stream_psleep_info.str().c_str());
    pfn_loader_.AddMethodName("vkLatencySleepNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkLatencySleepNV(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapchain).c_str(),
            psleep_info_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkLatencySleepNV);
}

void VulkanCppConsumer::Process_vkQueueNotifyOutOfBandNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkOutOfBandQueueTypeInfoNV>* pQueueTypeInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pqueue_type_info;
    std::string pqueue_type_info_struct = GenerateStruct_VkOutOfBandQueueTypeInfoNV(stream_pqueue_type_info,
                                                                                    pQueueTypeInfo->GetPointer(),
                                                                                    pQueueTypeInfo->GetMetaStructPointer(),
                                                                                    *this);
    fprintf(file, "%s", stream_pqueue_type_info.str().c_str());
    pfn_loader_.AddMethodName("vkQueueNotifyOutOfBandNV");
    fprintf(file,
            "\t\tloaded_vkQueueNotifyOutOfBandNV(%s, &%s);\n",
            this->GetHandle(queue).c_str(),
            pqueue_type_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkQueueNotifyOutOfBandNV);
}

void VulkanCppConsumer::Process_vkSetLatencyMarkerNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkSetLatencyMarkerInfoNV>* pLatencyMarkerInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_platency_marker_info;
    std::string platency_marker_info_struct = GenerateStruct_VkSetLatencyMarkerInfoNV(stream_platency_marker_info,
                                                                                      pLatencyMarkerInfo->GetPointer(),
                                                                                      pLatencyMarkerInfo->GetMetaStructPointer(),
                                                                                      *this);
    fprintf(file, "%s", stream_platency_marker_info.str().c_str());
    pfn_loader_.AddMethodName("vkSetLatencyMarkerNV");
    fprintf(file,
            "\t\tloaded_vkSetLatencyMarkerNV(%s, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapchain).c_str(),
            platency_marker_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSetLatencyMarkerNV);
}

void VulkanCppConsumer::Process_vkSetLatencySleepModeNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkLatencySleepModeInfoNV>* pSleepModeInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psleep_mode_info;
    std::string psleep_mode_info_struct = GenerateStruct_VkLatencySleepModeInfoNV(stream_psleep_mode_info,
                                                                                  pSleepModeInfo->GetPointer(),
                                                                                  pSleepModeInfo->GetMetaStructPointer(),
                                                                                  *this);
    fprintf(file, "%s", stream_psleep_mode_info.str().c_str());
    pfn_loader_.AddMethodName("vkSetLatencySleepModeNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkSetLatencySleepModeNV(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapchain).c_str(),
            psleep_mode_info_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSetLatencySleepModeNV);
}
void VulkanCppConsumer::Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkImageAspectFlags                          aspectMask)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetAttachmentFeedbackLoopEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetAttachmentFeedbackLoopEnableEXT(%s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            util::ToString<VkImageAspectFlags>(aspectMask).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfos;
    std::string pinfos_array = "NULL";
    PointerPairContainer<decltype(pInfos->GetPointer()), decltype(pInfos->GetMetaStructPointer())> pinfos_pair{ pInfos->GetPointer(), pInfos->GetMetaStructPointer(), infoCount };
    std::string pinfos_names = toStringJoin(pinfos_pair.begin(),
                                            pinfos_pair.end(),
                                            [&](auto pair) {{ return GenerateStruct_VkAccelerationStructureBuildGeometryInfoKHR(stream_pinfos, pair.t1, pair.t2, *this); }},
                                            ", ");
    if (stream_pinfos.str().length() > 0) {
        fprintf(file, "%s", stream_pinfos.str().c_str());
        if (infoCount == 1) {
            pinfos_array = "&" + pinfos_names;
        } else if (infoCount > 1) {
            pinfos_array = "pInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkAccelerationStructureBuildGeometryInfoKHR %s[] = { %s };\n", pinfos_array.c_str(), pinfos_names.c_str());
        }
    }
    std::string pindirect_device_addresses_array = "pIndirectDeviceAddresses_" + std::to_string(this->GetNextId());
    if (infoCount > 0) {
        std::string pindirect_device_addresses_values = toStringJoin(pIndirectDeviceAddresses->GetPointer(),
                                                                     pIndirectDeviceAddresses->GetPointer() + infoCount,
                                                                     [&](const auto current) { return std::to_string(current) + "UL"; },
                                                                     ", ");
        fprintf(file, "\t\tVkDeviceAddress %s[] = { %s };\n", pindirect_device_addresses_array.c_str(), pindirect_device_addresses_values.c_str());
    } else {
        pindirect_device_addresses_array = "NULL";
    }
    std::string pindirect_strides_array = "pIndirectStrides_" + std::to_string(this->GetNextId());
    if (infoCount > 0) {
        std::string pindirect_strides_values = toStringJoin(pIndirectStrides->GetPointer(),
                                                            pIndirectStrides->GetPointer() + infoCount,
                                                            [&](const auto current) { return std::to_string(current) + ""; },
                                                            ", ");
        fprintf(file, "\t\tuint32_t %s[] = { %s };\n", pindirect_strides_array.c_str(), pindirect_strides_values.c_str());
    } else {
        pindirect_strides_array = "NULL";
    }
    std::string pp_max_primitive_counts_array = "ppMaxPrimitiveCounts_" + std::to_string(this->GetNextId());
    if (infoCount > 0) {
        std::string pp_max_primitive_counts_values = toStringJoin(ppMaxPrimitiveCounts->GetPointer(),
                                                                  ppMaxPrimitiveCounts->GetPointer() + infoCount,
                                                                  [&](const auto current) { return std::to_string(reinterpret_cast<const VkDeviceSize>(current)) + ""; },
                                                                  ", ");
        fprintf(file, "\t\tuint32_t %s[] = { %s };\n", pp_max_primitive_counts_array.c_str(), pp_max_primitive_counts_values.c_str());
    } else {
        pp_max_primitive_counts_array = "NULL";
    }
    pfn_loader_.AddMethodName("vkCmdBuildAccelerationStructuresIndirectKHR");
    fprintf(file,
            "\t\tloaded_vkCmdBuildAccelerationStructuresIndirectKHR(%s, %u, %s, %s, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            infoCount,
            pinfos_array.c_str(),
            pindirect_device_addresses_array.c_str(),
            pindirect_strides_array.c_str(),
            pp_max_primitive_counts_array.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfos;
    std::string pinfos_array = "NULL";
    PointerPairContainer<decltype(pInfos->GetPointer()), decltype(pInfos->GetMetaStructPointer())> pinfos_pair{ pInfos->GetPointer(), pInfos->GetMetaStructPointer(), infoCount };
    std::string pinfos_names = toStringJoin(pinfos_pair.begin(),
                                            pinfos_pair.end(),
                                            [&](auto pair) {{ return GenerateStruct_VkAccelerationStructureBuildGeometryInfoKHR(stream_pinfos, pair.t1, pair.t2, *this); }},
                                            ", ");
    if (stream_pinfos.str().length() > 0) {
        fprintf(file, "%s", stream_pinfos.str().c_str());
        if (infoCount == 1) {
            pinfos_array = "&" + pinfos_names;
        } else if (infoCount > 1) {
            pinfos_array = "pInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkAccelerationStructureBuildGeometryInfoKHR %s[] = { %s };\n", pinfos_array.c_str(), pinfos_names.c_str());
        }
    }
    std::stringstream stream_pp_build_range_infos;
    std::string pp_build_range_infos_array = "NULL";
    PointerPairContainer<decltype(ppBuildRangeInfos->GetPointer()), decltype(ppBuildRangeInfos->GetMetaStructPointer())> pp_build_range_infos_pair{ ppBuildRangeInfos->GetPointer(), ppBuildRangeInfos->GetMetaStructPointer(), infoCount };
    std::string pp_build_range_infos_names = toStringJoin(pp_build_range_infos_pair.begin(),
                                                          pp_build_range_infos_pair.end(),
                                                          [&](auto pair) {{ return GenerateStruct_VkAccelerationStructureBuildRangeInfoKHR(stream_pp_build_range_infos, *pair.t1, *pair.t2, *this); }},
                                                          ", ");
    if (stream_pp_build_range_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pp_build_range_infos.str().c_str());
        if (infoCount == 1) {
            pp_build_range_infos_array = "&" + pp_build_range_infos_names;
        } else if (infoCount > 1) {
            pp_build_range_infos_array = "ppBuildRangeInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkAccelerationStructureBuildRangeInfoKHR %s[] = { %s };\n", pp_build_range_infos_array.c_str(), pp_build_range_infos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdBuildAccelerationStructuresKHR");
    fprintf(file,
            "\t\tloaded_vkCmdBuildAccelerationStructuresKHR(%s, %u, %s, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            infoCount,
            pinfos_array.c_str(),
            pp_build_range_infos_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR);
}

void VulkanCppConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkCopyAccelerationStructureInfoKHR(stream_pinfo,
                                                                                 pInfo->GetPointer(),
                                                                                 pInfo->GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyAccelerationStructureKHR");
    fprintf(file,
            "\t\tloaded_vkCmdCopyAccelerationStructureKHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR);
}

void VulkanCppConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkCopyAccelerationStructureToMemoryInfoKHR(stream_pinfo,
                                                                                         pInfo->GetPointer(),
                                                                                         pInfo->GetMetaStructPointer(),
                                                                                         *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyAccelerationStructureToMemoryKHR");
    fprintf(file,
            "\t\tloaded_vkCmdCopyAccelerationStructureToMemoryKHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR);
}

void VulkanCppConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkCopyMemoryToAccelerationStructureInfoKHR(stream_pinfo,
                                                                                         pInfo->GetPointer(),
                                                                                         pInfo->GetMetaStructPointer(),
                                                                                         *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyMemoryToAccelerationStructureKHR");
    fprintf(file,
            "\t\tloaded_vkCmdCopyMemoryToAccelerationStructureKHR(%s, &%s);\n",
            this->GetHandle(commandBuffer).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pacceleration_structures_array = "NULL";
    std::string pacceleration_structures_values = toStringJoin(pAccelerationStructures->GetPointer(),
                                                               pAccelerationStructures->GetPointer() + accelerationStructureCount,
                                                               [&](const format::HandleId current) { return this->GetHandle(current); },
                                                               ", ");
    if (accelerationStructureCount == 1 && pacceleration_structures_values != "VK_NULL_HANDLE") {
        pacceleration_structures_array = "&" + pacceleration_structures_values;
    } else if (accelerationStructureCount > 1) {
        pacceleration_structures_array = "pacceleration_structures_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkAccelerationStructureKHR %s[] = { %s };\n", pacceleration_structures_array.c_str(), pacceleration_structures_values.c_str());
    }
    pfn_loader_.AddMethodName("vkCmdWriteAccelerationStructuresPropertiesKHR");
    fprintf(file,
            "\t\tloaded_vkCmdWriteAccelerationStructuresPropertiesKHR(%s, %u, %s, %s, %s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            accelerationStructureCount,
            pacceleration_structures_array.c_str(),
            util::ToString<VkQueryType>(queryType).c_str(),
            this->GetHandle(queryPool).c_str(),
            firstQuery);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkCopyAccelerationStructureToMemoryInfoKHR(stream_pinfo,
                                                                                         pInfo->GetPointer(),
                                                                                         pInfo->GetMetaStructPointer(),
                                                                                         *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCopyAccelerationStructureToMemoryKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCopyAccelerationStructureToMemoryKHR(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(deferredOperation).c_str(),
            pinfo_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkCopyMemoryToAccelerationStructureInfoKHR(stream_pinfo,
                                                                                         pInfo->GetPointer(),
                                                                                         pInfo->GetMetaStructPointer(),
                                                                                         *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCopyMemoryToAccelerationStructureKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCopyMemoryToAccelerationStructureKHR(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(deferredOperation).c_str(),
            pinfo_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkAccelerationStructureCreateInfoKHR(stream_pcreate_info,
                                                                                          pCreateInfo->GetPointer(),
                                                                                          pCreateInfo->GetMetaStructPointer(),
                                                                                          *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pacceleration_structure_name = "pAccelerationStructure_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR));
    AddKnownVariables("VkAccelerationStructureKHR", pacceleration_structure_name, pAccelerationStructure->GetPointer());
    if (returnValue == VK_SUCCESS) {
        this->AddHandles(pacceleration_structure_name,
                         pAccelerationStructure->GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateAccelerationStructureKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateAccelerationStructureKHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pacceleration_structure_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR);
}

void VulkanCppConsumer::Process_vkDestroyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyAccelerationStructureKHR");
    fprintf(file,
            "\t\tloaded_vkDestroyAccelerationStructureKHR(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(accelerationStructure).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_pbuild_info;
    std::string pbuild_info_struct = GenerateStruct_VkAccelerationStructureBuildGeometryInfoKHR(stream_pbuild_info,
                                                                                                pBuildInfo->GetPointer(),
                                                                                                pBuildInfo->GetMetaStructPointer(),
                                                                                                *this);
    fprintf(file, "%s", stream_pbuild_info.str().c_str());
    std::string pmax_primitive_counts_array = "pMaxPrimitiveCounts_" + std::to_string(this->GetNextId());
    if (pBuildInfo->GetPointer()->geometryCount > 0 && pMaxPrimitiveCounts->GetPointer() != nullptr) {
        std::string pmax_primitive_counts_values = toStringJoin(pMaxPrimitiveCounts->GetPointer(),
                                                                pMaxPrimitiveCounts->GetPointer() + pBuildInfo->GetPointer()->geometryCount,
                                                                [&](const auto current) { return std::to_string(current) + ""; },
                                                                ", ");
        fprintf(file, "\t\tuint32_t %s[] = { %s };\n", pmax_primitive_counts_array.c_str(), pmax_primitive_counts_values.c_str());
    } else {
        pmax_primitive_counts_array = "NULL";
    }
    std::string psize_info_name = "pSizeInfo_" + std::to_string(this->GetNextId());
    std::stringstream stream_psize_info;
    psize_info_name = GenerateStruct_VkAccelerationStructureBuildSizesInfoKHR(stream_psize_info,
                                                                              pSizeInfo->GetPointer(),
                                                                              pSizeInfo->GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "%s", stream_psize_info.str().c_str());
    pfn_loader_.AddMethodName("vkGetAccelerationStructureBuildSizesKHR");
    fprintf(file,
            "\t\tloaded_vkGetAccelerationStructureBuildSizesKHR(%s, %s, &%s, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            util::ToString<VkAccelerationStructureBuildTypeKHR>(buildType).c_str(),
            pbuild_info_struct.c_str(),
            pmax_primitive_counts_array.c_str(),
            psize_info_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR);
}

void VulkanCppConsumer::Process_vkGetAccelerationStructureDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkAccelerationStructureDeviceAddressInfoKHR(stream_pinfo,
                                                                                          pInfo->GetPointer(),
                                                                                          pInfo->GetMetaStructPointer(),
                                                                                          *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkGetAccelerationStructureDeviceAddressKHR");
    fprintf(file,
            "\t\tloaded_vkGetAccelerationStructureDeviceAddressKHR(%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR);
}

void VulkanCppConsumer::Process_vkGetDeviceAccelerationStructureCompatibilityKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureVersionInfoKHR>* pVersionInfo,
    PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pversion_info;
    std::string pversion_info_struct = GenerateStruct_VkAccelerationStructureVersionInfoKHR(stream_pversion_info,
                                                                                            pVersionInfo->GetPointer(),
                                                                                            pVersionInfo->GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pversion_info.str().c_str());
    std::string pcompatibility_name = "pCompatibility_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tVkAccelerationStructureCompatibilityKHR %s;\n", pcompatibility_name.c_str());
    pfn_loader_.AddMethodName("vkGetDeviceAccelerationStructureCompatibilityKHR");
    fprintf(file,
            "\t\tloaded_vkGetDeviceAccelerationStructureCompatibilityKHR(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pversion_info_struct.c_str(),
            pcompatibility_name.c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::string pacceleration_structures_array = "NULL";
    std::string pacceleration_structures_values = toStringJoin(pAccelerationStructures->GetPointer(),
                                                               pAccelerationStructures->GetPointer() + accelerationStructureCount,
                                                               [&](const format::HandleId current) { return this->GetHandle(current); },
                                                               ", ");
    if (accelerationStructureCount == 1 && pacceleration_structures_values != "VK_NULL_HANDLE") {
        pacceleration_structures_array = "&" + pacceleration_structures_values;
    } else if (accelerationStructureCount > 1) {
        pacceleration_structures_array = "pacceleration_structures_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkAccelerationStructureKHR %s[] = { %s };\n", pacceleration_structures_array.c_str(), pacceleration_structures_values.c_str());
    }
    std::string pdata_name = "pData_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint8_t %s[%" PRIu64 "];\n", pdata_name.c_str(), util::platform::SizeTtoUint64(dataSize));
    pfn_loader_.AddMethodName("vkWriteAccelerationStructuresPropertiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkWriteAccelerationStructuresPropertiesKHR(%s, %u, %s, %s, %" PRIu64 ", %s, %" PRIu64 "), %s);\n",
            this->GetHandle(device).c_str(),
            accelerationStructureCount,
            pacceleration_structures_array.c_str(),
            util::ToString<VkQueryType>(queryType).c_str(),
            util::platform::SizeTtoUint64(dataSize),
            pdata_name.c_str(),
            util::platform::SizeTtoUint64(stride),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR);
}
void VulkanCppConsumer::Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    pipelineStackSize)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetRayTracingPipelineStackSizeKHR");
    fprintf(file,
            "\t\tloaded_vkCmdSetRayTracingPipelineStackSizeKHR(%s, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            pipelineStackSize);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_praygen_shader_binding_table;
    std::string praygen_shader_binding_table_struct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_praygen_shader_binding_table,
                                                                                                     pRaygenShaderBindingTable->GetPointer(),
                                                                                                     pRaygenShaderBindingTable->GetMetaStructPointer(),
                                                                                                     *this);
    fprintf(file, "%s", stream_praygen_shader_binding_table.str().c_str());
    std::stringstream stream_pmiss_shader_binding_table;
    std::string pmiss_shader_binding_table_struct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_pmiss_shader_binding_table,
                                                                                                   pMissShaderBindingTable->GetPointer(),
                                                                                                   pMissShaderBindingTable->GetMetaStructPointer(),
                                                                                                   *this);
    fprintf(file, "%s", stream_pmiss_shader_binding_table.str().c_str());
    std::stringstream stream_phit_shader_binding_table;
    std::string phit_shader_binding_table_struct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_phit_shader_binding_table,
                                                                                                  pHitShaderBindingTable->GetPointer(),
                                                                                                  pHitShaderBindingTable->GetMetaStructPointer(),
                                                                                                  *this);
    fprintf(file, "%s", stream_phit_shader_binding_table.str().c_str());
    std::stringstream stream_pcallable_shader_binding_table;
    std::string pcallable_shader_binding_table_struct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_pcallable_shader_binding_table,
                                                                                                       pCallableShaderBindingTable->GetPointer(),
                                                                                                       pCallableShaderBindingTable->GetMetaStructPointer(),
                                                                                                       *this);
    fprintf(file, "%s", stream_pcallable_shader_binding_table.str().c_str());
    pfn_loader_.AddMethodName("vkCmdTraceRaysIndirectKHR");
    fprintf(file,
            "\t\tloaded_vkCmdTraceRaysIndirectKHR(%s, &%s, &%s, &%s, &%s, %" PRIu64 "UL);\n",
            this->GetHandle(commandBuffer).c_str(),
            praygen_shader_binding_table_struct.c_str(),
            pmiss_shader_binding_table_struct.c_str(),
            phit_shader_binding_table_struct.c_str(),
            pcallable_shader_binding_table_struct.c_str(),
            indirectDeviceAddress);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    std::stringstream stream_praygen_shader_binding_table;
    std::string praygen_shader_binding_table_struct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_praygen_shader_binding_table,
                                                                                                     pRaygenShaderBindingTable->GetPointer(),
                                                                                                     pRaygenShaderBindingTable->GetMetaStructPointer(),
                                                                                                     *this);
    fprintf(file, "%s", stream_praygen_shader_binding_table.str().c_str());
    std::stringstream stream_pmiss_shader_binding_table;
    std::string pmiss_shader_binding_table_struct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_pmiss_shader_binding_table,
                                                                                                   pMissShaderBindingTable->GetPointer(),
                                                                                                   pMissShaderBindingTable->GetMetaStructPointer(),
                                                                                                   *this);
    fprintf(file, "%s", stream_pmiss_shader_binding_table.str().c_str());
    std::stringstream stream_phit_shader_binding_table;
    std::string phit_shader_binding_table_struct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_phit_shader_binding_table,
                                                                                                  pHitShaderBindingTable->GetPointer(),
                                                                                                  pHitShaderBindingTable->GetMetaStructPointer(),
                                                                                                  *this);
    fprintf(file, "%s", stream_phit_shader_binding_table.str().c_str());
    std::stringstream stream_pcallable_shader_binding_table;
    std::string pcallable_shader_binding_table_struct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_pcallable_shader_binding_table,
                                                                                                       pCallableShaderBindingTable->GetPointer(),
                                                                                                       pCallableShaderBindingTable->GetMetaStructPointer(),
                                                                                                       *this);
    fprintf(file, "%s", stream_pcallable_shader_binding_table.str().c_str());
    pfn_loader_.AddMethodName("vkCmdTraceRaysKHR");
    fprintf(file,
            "\t\tloaded_vkCmdTraceRaysKHR(%s, &%s, &%s, &%s, &%s, %u, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            praygen_shader_binding_table_struct.c_str(),
            pmiss_shader_binding_table_struct.c_str(),
            phit_shader_binding_table_struct.c_str(),
            pcallable_shader_binding_table_struct.c_str(),
            width,
            height,
            depth);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdTraceRaysKHR);
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
    fprintf(file, "\t{\n");
    std::string pdata_name = "pData_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tuint8_t %s[%" PRIu64 "];\n", pdata_name.c_str(), util::platform::SizeTtoUint64(dataSize));
    pfn_loader_.AddMethodName("vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(%s, %s, %u, %u, %" PRIu64 ", %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipeline).c_str(),
            firstGroup,
            groupCount,
            util::platform::SizeTtoUint64(dataSize),
            pdata_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkGetRayTracingShaderGroupStackSizeKHR");
    fprintf(file,
            "\t\tloaded_vkGetRayTracingShaderGroupStackSizeKHR(%s, %s, %u, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipeline).c_str(),
            group,
            util::ToString<VkShaderGroupShaderKHR>(groupShader).c_str());
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawMeshTasksEXT");
    fprintf(file,
            "\t\tloaded_vkCmdDrawMeshTasksEXT(%s, %u, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            groupCountX,
            groupCountY,
            groupCountZ);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawMeshTasksIndirectCountEXT");
    fprintf(file,
            "\t\tloaded_vkCmdDrawMeshTasksIndirectCountEXT(%s, %s, %" PRIu64 "UL, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            this->GetHandle(countBuffer).c_str(),
            countBufferOffset,
            maxDrawCount,
            stride);
    fprintf(file, "\t}\n");
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
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawMeshTasksIndirectEXT");
    fprintf(file,
            "\t\tloaded_vkCmdDrawMeshTasksIndirectEXT(%s, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(buffer).c_str(),
            offset,
            drawCount,
            stride);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
