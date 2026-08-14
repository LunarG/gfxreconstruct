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
    args::AllocateCommandBuffers&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pallocate_info;
    std::string pallocate_info_struct = GenerateStruct_VkCommandBufferAllocateInfo(stream_pallocate_info,
                                                                                   args.pAllocateInfo.GetPointer(),
                                                                                   args.pAllocateInfo.GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "%s", stream_pallocate_info.str().c_str());
    std::string pcommand_buffers_name = "pCommandBuffers_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_COMMAND_BUFFER));
    AddKnownVariables("VkCommandBuffer", pcommand_buffers_name, args.pCommandBuffers.GetPointer(), args.pAllocateInfo.GetPointer()->commandBufferCount);
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pcommand_buffers_name,
                         args.pCommandBuffers.GetPointer(), args.pAllocateInfo.GetPointer()->commandBufferCount);
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkAllocateCommandBuffers(%s, &%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pallocate_info_struct.c_str(),
            pcommand_buffers_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkAllocateCommandBuffers);
}

void VulkanCppConsumer::Process_vkAllocateDescriptorSets(
    const ApiCallInfo&                          call_info,
    args::AllocateDescriptorSets&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pallocate_info;
    std::string pallocate_info_struct = GenerateStruct_VkDescriptorSetAllocateInfo(stream_pallocate_info,
                                                                                   args.pAllocateInfo.GetPointer(),
                                                                                   args.pAllocateInfo.GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "%s", stream_pallocate_info.str().c_str());
    std::string pdescriptor_sets_name = "pDescriptorSets_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DESCRIPTOR_SET));
    AddKnownVariables("VkDescriptorSet", pdescriptor_sets_name, args.pDescriptorSets.GetPointer(), args.pAllocateInfo.GetPointer()->descriptorSetCount);
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pdescriptor_sets_name,
                         args.pDescriptorSets.GetPointer(), args.pAllocateInfo.GetPointer()->descriptorSetCount);
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkAllocateDescriptorSets(%s, &%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pallocate_info_struct.c_str(),
            pdescriptor_sets_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkAllocateDescriptorSets);
}

void VulkanCppConsumer::Process_vkAllocateMemory(
    const ApiCallInfo&                          call_info,
    args::AllocateMemory&                       args)
{
    Generate_vkAllocateMemory(args);
    Post_APICall(format::ApiCallId::ApiCall_vkAllocateMemory);
}

void VulkanCppConsumer::Process_vkBeginCommandBuffer(
    const ApiCallInfo&                          call_info,
    args::BeginCommandBuffer&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbegin_info;
    std::string pbegin_info_struct = GenerateStruct_VkCommandBufferBeginInfo(stream_pbegin_info,
                                                                             args.pBeginInfo.GetPointer(),
                                                                             args.pBeginInfo.GetMetaStructPointer(),
                                                                             *this);
    fprintf(file, "%s", stream_pbegin_info.str().c_str());
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkBeginCommandBuffer(%s, &%s), %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pbegin_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBeginCommandBuffer);
}

void VulkanCppConsumer::Process_vkBindBufferMemory(
    const ApiCallInfo&                          call_info,
    args::BindBufferMemory&                     args)
{
    Intercept_vkBindBufferMemory(args);
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkBindBufferMemory(%s, %s, %s, %" PRIu64 "UL), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.buffer).c_str(),
            this->GetHandle(args.memory).c_str(),
            args.memoryOffset,
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindBufferMemory);
}

void VulkanCppConsumer::Process_vkBindImageMemory(
    const ApiCallInfo&                          call_info,
    args::BindImageMemory&                      args)
{
    Intercept_vkBindImageMemory(args);
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkBindImageMemory(%s, %s, %s, %" PRIu64 "UL), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.image).c_str(),
            this->GetHandle(args.memory).c_str(),
            args.memoryOffset,
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindImageMemory);
}

void VulkanCppConsumer::Process_vkCmdBeginQuery(
    const ApiCallInfo&                          call_info,
    args::CmdBeginQuery&                        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdBeginQuery(%s, %s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.queryPool).c_str(),
            args.query,
            util::ToString<VkQueryControlFlags>(args.flags).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginQuery);
}

void VulkanCppConsumer::Process_vkCmdBeginRenderPass(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderPass&                   args)
{
    Intercept_vkCmdBeginRenderPass(args);
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_prender_pass_begin;
    std::string prender_pass_begin_struct = GenerateStruct_VkRenderPassBeginInfo(stream_prender_pass_begin,
                                                                                 args.pRenderPassBegin.GetPointer(),
                                                                                 args.pRenderPassBegin.GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_prender_pass_begin.str().c_str());
    fprintf(file,
            "\t\tvkCmdBeginRenderPass(%s, &%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            prender_pass_begin_struct.c_str(),
            util::ToString<VkSubpassContents>(args.contents).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginRenderPass);
}

void VulkanCppConsumer::Process_vkCmdBindDescriptorSets(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorSets&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pdescriptor_sets_array = "NULL";
    std::string pdescriptor_sets_values = toStringJoin(args.pDescriptorSets.GetPointer(),
                                                       args.pDescriptorSets.GetPointer() + args.descriptorSetCount,
                                                       [&](const format::HandleId current) { return this->GetHandle(current); },
                                                       ", ");
    if (args.descriptorSetCount == 1 && pdescriptor_sets_values != "VK_NULL_HANDLE") {
        pdescriptor_sets_array = "&" + pdescriptor_sets_values;
    } else if (args.descriptorSetCount > 1) {
        pdescriptor_sets_array = "pdescriptor_sets_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDescriptorSet %s[] = { %s };\n", pdescriptor_sets_array.c_str(), pdescriptor_sets_values.c_str());
    }
    std::string pdynamic_offsets_array = "pDynamicOffsets_" + std::to_string(this->GetNextId());
    if (args.dynamicOffsetCount > 0) {
        std::string pdynamic_offsets_values = toStringJoin(args.pDynamicOffsets.GetPointer(),
                                                           args.pDynamicOffsets.GetPointer() + args.dynamicOffsetCount,
                                                           [&](const auto current) { return std::to_string(current) + ""; },
                                                           ", ");
        fprintf(file, "\t\tuint32_t %s[] = { %s };\n", pdynamic_offsets_array.c_str(), pdynamic_offsets_values.c_str());
    } else {
        pdynamic_offsets_array = "NULL";
    }
    fprintf(file,
            "\t\tvkCmdBindDescriptorSets(%s, %s, %s, %u, %u, %s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkPipelineBindPoint>(args.pipelineBindPoint).c_str(),
            this->GetHandle(args.layout).c_str(),
            args.firstSet,
            args.descriptorSetCount,
            pdescriptor_sets_array.c_str(),
            args.dynamicOffsetCount,
            pdynamic_offsets_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindDescriptorSets);
}

void VulkanCppConsumer::Process_vkCmdBindIndexBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdBindIndexBuffer(%s, %s, %" PRIu64 "UL, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.buffer).c_str(),
            args.offset,
            util::ToString<VkIndexType>(args.indexType).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindIndexBuffer);
}

void VulkanCppConsumer::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    args::CmdBindPipeline&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdBindPipeline(%s, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkPipelineBindPoint>(args.pipelineBindPoint).c_str(),
            this->GetHandle(args.pipeline).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindPipeline);
}

void VulkanCppConsumer::Process_vkCmdBindVertexBuffers(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pbuffers_array = "NULL";
    std::string pbuffers_values = toStringJoin(args.pBuffers.GetPointer(),
                                               args.pBuffers.GetPointer() + args.bindingCount,
                                               [&](const format::HandleId current) { return this->GetHandle(current); },
                                               ", ");
    if (args.bindingCount == 1 && pbuffers_values != "VK_NULL_HANDLE") {
        pbuffers_array = "&" + pbuffers_values;
    } else if (args.bindingCount > 1) {
        pbuffers_array = "pbuffers_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkBuffer %s[] = { %s };\n", pbuffers_array.c_str(), pbuffers_values.c_str());
    }
    std::string poffsets_array = "pOffsets_" + std::to_string(this->GetNextId());
    if (args.bindingCount > 0) {
        std::string poffsets_values = toStringJoin(args.pOffsets.GetPointer(),
                                                   args.pOffsets.GetPointer() + args.bindingCount,
                                                   [&](const auto current) { return std::to_string(current) + "UL"; },
                                                   ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", poffsets_array.c_str(), poffsets_values.c_str());
    } else {
        poffsets_array = "NULL";
    }
    fprintf(file,
            "\t\tvkCmdBindVertexBuffers(%s, %u, %u, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.firstBinding,
            args.bindingCount,
            pbuffers_array.c_str(),
            poffsets_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindVertexBuffers);
}

void VulkanCppConsumer::Process_vkCmdBlitImage(
    const ApiCallInfo&                          call_info,
    args::CmdBlitImage&                         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pregions;
    std::string pregions_array = "NULL";
    PointerPairContainer<decltype(args.pRegions.GetPointer()), decltype(args.pRegions.GetMetaStructPointer())> pregions_pair{ args.pRegions.GetPointer(), args.pRegions.GetMetaStructPointer(), args.regionCount };
    std::string pregions_names = toStringJoin(pregions_pair.begin(),
                                              pregions_pair.end(),
                                              [&](auto pair) {{ return GenerateStruct_VkImageBlit(stream_pregions, pair.t1, pair.t2, *this); }},
                                              ", ");
    if (stream_pregions.str().length() > 0) {
        fprintf(file, "%s", stream_pregions.str().c_str());
        if (args.regionCount == 1) {
            pregions_array = "&" + pregions_names;
        } else if (args.regionCount > 1) {
            pregions_array = "pRegions_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkImageBlit %s[] = { %s };\n", pregions_array.c_str(), pregions_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdBlitImage(%s, %s, %s, %s, %s, %u, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.srcImage).c_str(),
            util::ToString<VkImageLayout>(args.srcImageLayout).c_str(),
            this->GetHandle(args.dstImage).c_str(),
            util::ToString<VkImageLayout>(args.dstImageLayout).c_str(),
            args.regionCount,
            pregions_array.c_str(),
            util::ToString<VkFilter>(args.filter).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBlitImage);
}

void VulkanCppConsumer::Process_vkCmdClearAttachments(
    const ApiCallInfo&                          call_info,
    args::CmdClearAttachments&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pattachments;
    std::string pattachments_array = "NULL";
    PointerPairContainer<decltype(args.pAttachments.GetPointer()), decltype(args.pAttachments.GetMetaStructPointer())> pattachments_pair{ args.pAttachments.GetPointer(), args.pAttachments.GetMetaStructPointer(), args.attachmentCount };
    std::string pattachments_names = toStringJoin(pattachments_pair.begin(),
                                                  pattachments_pair.end(),
                                                  [&](auto pair) {{ return GenerateStruct_VkClearAttachment(stream_pattachments, pair.t1, pair.t2, *this); }},
                                                  ", ");
    if (stream_pattachments.str().length() > 0) {
        fprintf(file, "%s", stream_pattachments.str().c_str());
        if (args.attachmentCount == 1) {
            pattachments_array = "&" + pattachments_names;
        } else if (args.attachmentCount > 1) {
            pattachments_array = "pAttachments_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkClearAttachment %s[] = { %s };\n", pattachments_array.c_str(), pattachments_names.c_str());
        }
    }
    std::stringstream stream_prects;
    std::string prects_array = "NULL";
    PointerPairContainer<decltype(args.pRects.GetPointer()), decltype(args.pRects.GetMetaStructPointer())> prects_pair{ args.pRects.GetPointer(), args.pRects.GetMetaStructPointer(), args.rectCount };
    std::string prects_names = toStringJoin(prects_pair.begin(),
                                            prects_pair.end(),
                                            [&](auto pair) {{ return GenerateStruct_VkClearRect(stream_prects, pair.t1, pair.t2, *this); }},
                                            ", ");
    if (stream_prects.str().length() > 0) {
        fprintf(file, "%s", stream_prects.str().c_str());
        if (args.rectCount == 1) {
            prects_array = "&" + prects_names;
        } else if (args.rectCount > 1) {
            prects_array = "pRects_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkClearRect %s[] = { %s };\n", prects_array.c_str(), prects_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdClearAttachments(%s, %u, %s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.attachmentCount,
            pattachments_array.c_str(),
            args.rectCount,
            prects_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdClearAttachments);
}

void VulkanCppConsumer::Process_vkCmdClearColorImage(
    const ApiCallInfo&                          call_info,
    args::CmdClearColorImage&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcolor;
    std::string pcolor_struct = GenerateStruct_VkClearColorValue(stream_pcolor,
                                                                 args.pColor.GetPointer(),
                                                                 args.pColor.GetMetaStructPointer(),
                                                                 *this);
    fprintf(file, "%s", stream_pcolor.str().c_str());
    std::stringstream stream_pranges;
    std::string pranges_array = "NULL";
    PointerPairContainer<decltype(args.pRanges.GetPointer()), decltype(args.pRanges.GetMetaStructPointer())> pranges_pair{ args.pRanges.GetPointer(), args.pRanges.GetMetaStructPointer(), args.rangeCount };
    std::string pranges_names = toStringJoin(pranges_pair.begin(),
                                             pranges_pair.end(),
                                             [&](auto pair) {{ return GenerateStruct_VkImageSubresourceRange(stream_pranges, pair.t1, pair.t2, *this); }},
                                             ", ");
    if (stream_pranges.str().length() > 0) {
        fprintf(file, "%s", stream_pranges.str().c_str());
        if (args.rangeCount == 1) {
            pranges_array = "&" + pranges_names;
        } else if (args.rangeCount > 1) {
            pranges_array = "pRanges_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkImageSubresourceRange %s[] = { %s };\n", pranges_array.c_str(), pranges_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdClearColorImage(%s, %s, %s, &%s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.image).c_str(),
            util::ToString<VkImageLayout>(args.imageLayout).c_str(),
            pcolor_struct.c_str(),
            args.rangeCount,
            pranges_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdClearColorImage);
}

void VulkanCppConsumer::Process_vkCmdClearDepthStencilImage(
    const ApiCallInfo&                          call_info,
    args::CmdClearDepthStencilImage&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdepth_stencil;
    std::string pdepth_stencil_struct = GenerateStruct_VkClearDepthStencilValue(stream_pdepth_stencil,
                                                                                args.pDepthStencil.GetPointer(),
                                                                                args.pDepthStencil.GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_pdepth_stencil.str().c_str());
    std::stringstream stream_pranges;
    std::string pranges_array = "NULL";
    PointerPairContainer<decltype(args.pRanges.GetPointer()), decltype(args.pRanges.GetMetaStructPointer())> pranges_pair{ args.pRanges.GetPointer(), args.pRanges.GetMetaStructPointer(), args.rangeCount };
    std::string pranges_names = toStringJoin(pranges_pair.begin(),
                                             pranges_pair.end(),
                                             [&](auto pair) {{ return GenerateStruct_VkImageSubresourceRange(stream_pranges, pair.t1, pair.t2, *this); }},
                                             ", ");
    if (stream_pranges.str().length() > 0) {
        fprintf(file, "%s", stream_pranges.str().c_str());
        if (args.rangeCount == 1) {
            pranges_array = "&" + pranges_names;
        } else if (args.rangeCount > 1) {
            pranges_array = "pRanges_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkImageSubresourceRange %s[] = { %s };\n", pranges_array.c_str(), pranges_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdClearDepthStencilImage(%s, %s, %s, &%s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.image).c_str(),
            util::ToString<VkImageLayout>(args.imageLayout).c_str(),
            pdepth_stencil_struct.c_str(),
            args.rangeCount,
            pranges_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage);
}

void VulkanCppConsumer::Process_vkCmdCopyBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBuffer&                        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pregions;
    std::string pregions_array = "NULL";
    PointerPairContainer<decltype(args.pRegions.GetPointer()), decltype(args.pRegions.GetMetaStructPointer())> pregions_pair{ args.pRegions.GetPointer(), args.pRegions.GetMetaStructPointer(), args.regionCount };
    std::string pregions_names = toStringJoin(pregions_pair.begin(),
                                              pregions_pair.end(),
                                              [&](auto pair) {{ return GenerateStruct_VkBufferCopy(stream_pregions, pair.t1, pair.t2, *this); }},
                                              ", ");
    if (stream_pregions.str().length() > 0) {
        fprintf(file, "%s", stream_pregions.str().c_str());
        if (args.regionCount == 1) {
            pregions_array = "&" + pregions_names;
        } else if (args.regionCount > 1) {
            pregions_array = "pRegions_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBufferCopy %s[] = { %s };\n", pregions_array.c_str(), pregions_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdCopyBuffer(%s, %s, %s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.srcBuffer).c_str(),
            this->GetHandle(args.dstBuffer).c_str(),
            args.regionCount,
            pregions_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyBuffer);
}

void VulkanCppConsumer::Process_vkCmdCopyBufferToImage(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBufferToImage&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pregions;
    std::string pregions_array = "NULL";
    PointerPairContainer<decltype(args.pRegions.GetPointer()), decltype(args.pRegions.GetMetaStructPointer())> pregions_pair{ args.pRegions.GetPointer(), args.pRegions.GetMetaStructPointer(), args.regionCount };
    std::string pregions_names = toStringJoin(pregions_pair.begin(),
                                              pregions_pair.end(),
                                              [&](auto pair) {{ return GenerateStruct_VkBufferImageCopy(stream_pregions, pair.t1, pair.t2, *this); }},
                                              ", ");
    if (stream_pregions.str().length() > 0) {
        fprintf(file, "%s", stream_pregions.str().c_str());
        if (args.regionCount == 1) {
            pregions_array = "&" + pregions_names;
        } else if (args.regionCount > 1) {
            pregions_array = "pRegions_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBufferImageCopy %s[] = { %s };\n", pregions_array.c_str(), pregions_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdCopyBufferToImage(%s, %s, %s, %s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.srcBuffer).c_str(),
            this->GetHandle(args.dstImage).c_str(),
            util::ToString<VkImageLayout>(args.dstImageLayout).c_str(),
            args.regionCount,
            pregions_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyBufferToImage);
}

void VulkanCppConsumer::Process_vkCmdCopyImage(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImage&                         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pregions;
    std::string pregions_array = "NULL";
    PointerPairContainer<decltype(args.pRegions.GetPointer()), decltype(args.pRegions.GetMetaStructPointer())> pregions_pair{ args.pRegions.GetPointer(), args.pRegions.GetMetaStructPointer(), args.regionCount };
    std::string pregions_names = toStringJoin(pregions_pair.begin(),
                                              pregions_pair.end(),
                                              [&](auto pair) {{ return GenerateStruct_VkImageCopy(stream_pregions, pair.t1, pair.t2, *this); }},
                                              ", ");
    if (stream_pregions.str().length() > 0) {
        fprintf(file, "%s", stream_pregions.str().c_str());
        if (args.regionCount == 1) {
            pregions_array = "&" + pregions_names;
        } else if (args.regionCount > 1) {
            pregions_array = "pRegions_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkImageCopy %s[] = { %s };\n", pregions_array.c_str(), pregions_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdCopyImage(%s, %s, %s, %s, %s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.srcImage).c_str(),
            util::ToString<VkImageLayout>(args.srcImageLayout).c_str(),
            this->GetHandle(args.dstImage).c_str(),
            util::ToString<VkImageLayout>(args.dstImageLayout).c_str(),
            args.regionCount,
            pregions_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImage);
}

void VulkanCppConsumer::Process_vkCmdCopyImageToBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToBuffer&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pregions;
    std::string pregions_array = "NULL";
    PointerPairContainer<decltype(args.pRegions.GetPointer()), decltype(args.pRegions.GetMetaStructPointer())> pregions_pair{ args.pRegions.GetPointer(), args.pRegions.GetMetaStructPointer(), args.regionCount };
    std::string pregions_names = toStringJoin(pregions_pair.begin(),
                                              pregions_pair.end(),
                                              [&](auto pair) {{ return GenerateStruct_VkBufferImageCopy(stream_pregions, pair.t1, pair.t2, *this); }},
                                              ", ");
    if (stream_pregions.str().length() > 0) {
        fprintf(file, "%s", stream_pregions.str().c_str());
        if (args.regionCount == 1) {
            pregions_array = "&" + pregions_names;
        } else if (args.regionCount > 1) {
            pregions_array = "pRegions_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBufferImageCopy %s[] = { %s };\n", pregions_array.c_str(), pregions_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdCopyImageToBuffer(%s, %s, %s, %s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.srcImage).c_str(),
            util::ToString<VkImageLayout>(args.srcImageLayout).c_str(),
            this->GetHandle(args.dstBuffer).c_str(),
            args.regionCount,
            pregions_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer);
}

void VulkanCppConsumer::Process_vkCmdCopyQueryPoolResults(
    const ApiCallInfo&                          call_info,
    args::CmdCopyQueryPoolResults&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdCopyQueryPoolResults(%s, %s, %u, %u, %s, %" PRIu64 "UL, %" PRIu64 "UL, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.queryPool).c_str(),
            args.firstQuery,
            args.queryCount,
            this->GetHandle(args.dstBuffer).c_str(),
            args.dstOffset,
            args.stride,
            util::ToString<VkQueryResultFlags>(args.flags).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults);
}

void VulkanCppConsumer::Process_vkCmdDispatch(
    const ApiCallInfo&                          call_info,
    args::CmdDispatch&                          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdDispatch(%s, %u, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.groupCountX,
            args.groupCountY,
            args.groupCountZ);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDispatch);
}

void VulkanCppConsumer::Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchIndirect&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdDispatchIndirect(%s, %s, %" PRIu64 "UL);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.buffer).c_str(),
            args.offset);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDispatchIndirect);
}

void VulkanCppConsumer::Process_vkCmdDraw(
    const ApiCallInfo&                          call_info,
    args::CmdDraw&                              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdDraw(%s, %u, %u, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.vertexCount,
            args.instanceCount,
            args.firstVertex,
            args.firstInstance);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDraw);
}

void VulkanCppConsumer::Process_vkCmdDrawIndexed(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexed&                       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdDrawIndexed(%s, %u, %u, %u, %d, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.indexCount,
            args.instanceCount,
            args.firstIndex,
            args.vertexOffset,
            args.firstInstance);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndexed);
}

void VulkanCppConsumer::Process_vkCmdDrawIndexedIndirect(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirect&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdDrawIndexedIndirect(%s, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.buffer).c_str(),
            args.offset,
            args.drawCount,
            args.stride);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect);
}

void VulkanCppConsumer::Process_vkCmdDrawIndirect(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirect&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdDrawIndirect(%s, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.buffer).c_str(),
            args.offset,
            args.drawCount,
            args.stride);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirect);
}

void VulkanCppConsumer::Process_vkCmdEndQuery(
    const ApiCallInfo&                          call_info,
    args::CmdEndQuery&                          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdEndQuery(%s, %s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.queryPool).c_str(),
            args.query);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndQuery);
}

void VulkanCppConsumer::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    args::CmdEndRenderPass&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdEndRenderPass(%s);\n",
            this->GetHandle(args.commandBuffer).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRenderPass);
}

void VulkanCppConsumer::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    args::CmdExecuteCommands&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcommand_buffers_array = "NULL";
    std::string pcommand_buffers_values = toStringJoin(args.pCommandBuffers.GetPointer(),
                                                       args.pCommandBuffers.GetPointer() + args.commandBufferCount,
                                                       [&](const format::HandleId current) { return this->GetHandle(current); },
                                                       ", ");
    if (args.commandBufferCount == 1 && pcommand_buffers_values != "VK_NULL_HANDLE") {
        pcommand_buffers_array = "&" + pcommand_buffers_values;
    } else if (args.commandBufferCount > 1) {
        pcommand_buffers_array = "pcommand_buffers_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkCommandBuffer %s[] = { %s };\n", pcommand_buffers_array.c_str(), pcommand_buffers_values.c_str());
    }
    fprintf(file,
            "\t\tvkCmdExecuteCommands(%s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.commandBufferCount,
            pcommand_buffers_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdExecuteCommands);
}

void VulkanCppConsumer::Process_vkCmdFillBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdFillBuffer&                        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdFillBuffer(%s, %s, %" PRIu64 "UL, %" PRIu64 "UL, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.dstBuffer).c_str(),
            args.dstOffset,
            args.size,
            args.data);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdFillBuffer);
}

void VulkanCppConsumer::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    args::CmdNextSubpass&                       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdNextSubpass(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkSubpassContents>(args.contents).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdNextSubpass);
}

void VulkanCppConsumer::Process_vkCmdPipelineBarrier(
    const ApiCallInfo&                          call_info,
    args::CmdPipelineBarrier&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pmemory_barriers;
    std::string pmemory_barriers_array = "NULL";
    PointerPairContainer<decltype(args.pMemoryBarriers.GetPointer()), decltype(args.pMemoryBarriers.GetMetaStructPointer())> pmemory_barriers_pair{ args.pMemoryBarriers.GetPointer(), args.pMemoryBarriers.GetMetaStructPointer(), args.memoryBarrierCount };
    std::string pmemory_barriers_names = toStringJoin(pmemory_barriers_pair.begin(),
                                                      pmemory_barriers_pair.end(),
                                                      [&](auto pair) {{ return GenerateStruct_VkMemoryBarrier(stream_pmemory_barriers, pair.t1, pair.t2, *this); }},
                                                      ", ");
    if (stream_pmemory_barriers.str().length() > 0) {
        fprintf(file, "%s", stream_pmemory_barriers.str().c_str());
        if (args.memoryBarrierCount == 1) {
            pmemory_barriers_array = "&" + pmemory_barriers_names;
        } else if (args.memoryBarrierCount > 1) {
            pmemory_barriers_array = "pMemoryBarriers_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkMemoryBarrier %s[] = { %s };\n", pmemory_barriers_array.c_str(), pmemory_barriers_names.c_str());
        }
    }
    std::stringstream stream_pbuffer_memory_barriers;
    std::string pbuffer_memory_barriers_array = "NULL";
    PointerPairContainer<decltype(args.pBufferMemoryBarriers.GetPointer()), decltype(args.pBufferMemoryBarriers.GetMetaStructPointer())> pbuffer_memory_barriers_pair{ args.pBufferMemoryBarriers.GetPointer(), args.pBufferMemoryBarriers.GetMetaStructPointer(), args.bufferMemoryBarrierCount };
    std::string pbuffer_memory_barriers_names = toStringJoin(pbuffer_memory_barriers_pair.begin(),
                                                             pbuffer_memory_barriers_pair.end(),
                                                             [&](auto pair) {{ return GenerateStruct_VkBufferMemoryBarrier(stream_pbuffer_memory_barriers, pair.t1, pair.t2, *this); }},
                                                             ", ");
    if (stream_pbuffer_memory_barriers.str().length() > 0) {
        fprintf(file, "%s", stream_pbuffer_memory_barriers.str().c_str());
        if (args.bufferMemoryBarrierCount == 1) {
            pbuffer_memory_barriers_array = "&" + pbuffer_memory_barriers_names;
        } else if (args.bufferMemoryBarrierCount > 1) {
            pbuffer_memory_barriers_array = "pBufferMemoryBarriers_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBufferMemoryBarrier %s[] = { %s };\n", pbuffer_memory_barriers_array.c_str(), pbuffer_memory_barriers_names.c_str());
        }
    }
    std::stringstream stream_pimage_memory_barriers;
    std::string pimage_memory_barriers_array = "NULL";
    PointerPairContainer<decltype(args.pImageMemoryBarriers.GetPointer()), decltype(args.pImageMemoryBarriers.GetMetaStructPointer())> pimage_memory_barriers_pair{ args.pImageMemoryBarriers.GetPointer(), args.pImageMemoryBarriers.GetMetaStructPointer(), args.imageMemoryBarrierCount };
    std::string pimage_memory_barriers_names = toStringJoin(pimage_memory_barriers_pair.begin(),
                                                            pimage_memory_barriers_pair.end(),
                                                            [&](auto pair) {{ return GenerateStruct_VkImageMemoryBarrier(stream_pimage_memory_barriers, pair.t1, pair.t2, *this); }},
                                                            ", ");
    if (stream_pimage_memory_barriers.str().length() > 0) {
        fprintf(file, "%s", stream_pimage_memory_barriers.str().c_str());
        if (args.imageMemoryBarrierCount == 1) {
            pimage_memory_barriers_array = "&" + pimage_memory_barriers_names;
        } else if (args.imageMemoryBarrierCount > 1) {
            pimage_memory_barriers_array = "pImageMemoryBarriers_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkImageMemoryBarrier %s[] = { %s };\n", pimage_memory_barriers_array.c_str(), pimage_memory_barriers_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdPipelineBarrier(%s, %s, %s, %s, %u, %s, %u, %s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkPipelineStageFlags>(args.srcStageMask).c_str(),
            util::ToString<VkPipelineStageFlags>(args.dstStageMask).c_str(),
            util::ToString<VkDependencyFlags>(args.dependencyFlags).c_str(),
            args.memoryBarrierCount,
            pmemory_barriers_array.c_str(),
            args.bufferMemoryBarrierCount,
            pbuffer_memory_barriers_array.c_str(),
            args.imageMemoryBarrierCount,
            pimage_memory_barriers_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPipelineBarrier);
}

void VulkanCppConsumer::Process_vkCmdPushConstants(
    const ApiCallInfo&                          call_info,
    args::CmdPushConstants&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pvalues_array = "pValues_" + std::to_string(this->GetNextId());
    if (args.size > 0) {
        std::string pvalues_values = toStringJoin(args.pValues.GetPointer(),
                                                  args.pValues.GetPointer() + args.size,
                                                  [&](const auto current) { return std::to_string(current) + ""; },
                                                  ", ");
        fprintf(file, "\t\tuint8_t %s[] = { %s };\n", pvalues_array.c_str(), pvalues_values.c_str());
    } else {
        pvalues_array = "NULL";
    }
    fprintf(file,
            "\t\tvkCmdPushConstants(%s, %s, %s, %u, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.layout).c_str(),
            util::ToString<VkShaderStageFlags>(args.stageFlags).c_str(),
            args.offset,
            args.size,
            pvalues_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPushConstants);
}

void VulkanCppConsumer::Process_vkCmdResetEvent(
    const ApiCallInfo&                          call_info,
    args::CmdResetEvent&                        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdResetEvent(%s, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.event).c_str(),
            util::ToString<VkPipelineStageFlags>(args.stageMask).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResetEvent);
}

void VulkanCppConsumer::Process_vkCmdResetQueryPool(
    const ApiCallInfo&                          call_info,
    args::CmdResetQueryPool&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdResetQueryPool(%s, %s, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.queryPool).c_str(),
            args.firstQuery,
            args.queryCount);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResetQueryPool);
}

void VulkanCppConsumer::Process_vkCmdResolveImage(
    const ApiCallInfo&                          call_info,
    args::CmdResolveImage&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pregions;
    std::string pregions_array = "NULL";
    PointerPairContainer<decltype(args.pRegions.GetPointer()), decltype(args.pRegions.GetMetaStructPointer())> pregions_pair{ args.pRegions.GetPointer(), args.pRegions.GetMetaStructPointer(), args.regionCount };
    std::string pregions_names = toStringJoin(pregions_pair.begin(),
                                              pregions_pair.end(),
                                              [&](auto pair) {{ return GenerateStruct_VkImageResolve(stream_pregions, pair.t1, pair.t2, *this); }},
                                              ", ");
    if (stream_pregions.str().length() > 0) {
        fprintf(file, "%s", stream_pregions.str().c_str());
        if (args.regionCount == 1) {
            pregions_array = "&" + pregions_names;
        } else if (args.regionCount > 1) {
            pregions_array = "pRegions_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkImageResolve %s[] = { %s };\n", pregions_array.c_str(), pregions_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdResolveImage(%s, %s, %s, %s, %s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.srcImage).c_str(),
            util::ToString<VkImageLayout>(args.srcImageLayout).c_str(),
            this->GetHandle(args.dstImage).c_str(),
            util::ToString<VkImageLayout>(args.dstImageLayout).c_str(),
            args.regionCount,
            pregions_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResolveImage);
}

void VulkanCppConsumer::Process_vkCmdSetBlendConstants(
    const ApiCallInfo&                          call_info,
    args::CmdSetBlendConstants&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string blend_constants_array = "blendConstants_" + std::to_string(this->GetNextId());
    if (4 > 0) {
        std::string blend_constants_values = toStringJoin(args.blendConstants.GetPointer(),
                                                          args.blendConstants.GetPointer() + 4,
                                                          [&](const auto current) { return std::to_string(current) + ""; },
                                                          ", ");
        fprintf(file, "\t\tfloat %s[] = { %s };\n", blend_constants_array.c_str(), blend_constants_values.c_str());
    } else {
        blend_constants_array = "NULL";
    }
    fprintf(file,
            "\t\tvkCmdSetBlendConstants(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            blend_constants_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetBlendConstants);
}

void VulkanCppConsumer::Process_vkCmdSetDepthBias(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBias&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetDepthBias(%s, %f, %f, %f);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.depthBiasConstantFactor,
            args.depthBiasClamp,
            args.depthBiasSlopeFactor);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBias);
}

void VulkanCppConsumer::Process_vkCmdSetDepthBounds(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBounds&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetDepthBounds(%s, %f, %f);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.minDepthBounds,
            args.maxDepthBounds);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBounds);
}

void VulkanCppConsumer::Process_vkCmdSetEvent(
    const ApiCallInfo&                          call_info,
    args::CmdSetEvent&                          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetEvent(%s, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.event).c_str(),
            util::ToString<VkPipelineStageFlags>(args.stageMask).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetEvent);
}

void VulkanCppConsumer::Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineWidth&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetLineWidth(%s, %f);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.lineWidth);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLineWidth);
}

void VulkanCppConsumer::Process_vkCmdSetScissor(
    const ApiCallInfo&                          call_info,
    args::CmdSetScissor&                        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pscissors;
    std::string pscissors_array = "NULL";
    PointerPairContainer<decltype(args.pScissors.GetPointer()), decltype(args.pScissors.GetMetaStructPointer())> pscissors_pair{ args.pScissors.GetPointer(), args.pScissors.GetMetaStructPointer(), args.scissorCount };
    std::string pscissors_names = toStringJoin(pscissors_pair.begin(),
                                               pscissors_pair.end(),
                                               [&](auto pair) {{ return GenerateStruct_VkRect2D(stream_pscissors, pair.t1, pair.t2, *this); }},
                                               ", ");
    if (stream_pscissors.str().length() > 0) {
        fprintf(file, "%s", stream_pscissors.str().c_str());
        if (args.scissorCount == 1) {
            pscissors_array = "&" + pscissors_names;
        } else if (args.scissorCount > 1) {
            pscissors_array = "pScissors_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkRect2D %s[] = { %s };\n", pscissors_array.c_str(), pscissors_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdSetScissor(%s, %u, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.firstScissor,
            args.scissorCount,
            pscissors_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetScissor);
}

void VulkanCppConsumer::Process_vkCmdSetStencilCompareMask(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilCompareMask&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetStencilCompareMask(%s, %s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkStencilFaceFlags>(args.faceMask).c_str(),
            args.compareMask);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask);
}

void VulkanCppConsumer::Process_vkCmdSetStencilReference(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilReference&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetStencilReference(%s, %s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkStencilFaceFlags>(args.faceMask).c_str(),
            args.reference);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilReference);
}

void VulkanCppConsumer::Process_vkCmdSetStencilWriteMask(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilWriteMask&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetStencilWriteMask(%s, %s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkStencilFaceFlags>(args.faceMask).c_str(),
            args.writeMask);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask);
}

void VulkanCppConsumer::Process_vkCmdSetViewport(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewport&                       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pviewports;
    std::string pviewports_array = "NULL";
    PointerPairContainer<decltype(args.pViewports.GetPointer()), decltype(args.pViewports.GetMetaStructPointer())> pviewports_pair{ args.pViewports.GetPointer(), args.pViewports.GetMetaStructPointer(), args.viewportCount };
    std::string pviewports_names = toStringJoin(pviewports_pair.begin(),
                                                pviewports_pair.end(),
                                                [&](auto pair) {{ return GenerateStruct_VkViewport(stream_pviewports, pair.t1, pair.t2, *this); }},
                                                ", ");
    if (stream_pviewports.str().length() > 0) {
        fprintf(file, "%s", stream_pviewports.str().c_str());
        if (args.viewportCount == 1) {
            pviewports_array = "&" + pviewports_names;
        } else if (args.viewportCount > 1) {
            pviewports_array = "pViewports_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkViewport %s[] = { %s };\n", pviewports_array.c_str(), pviewports_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdSetViewport(%s, %u, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.firstViewport,
            args.viewportCount,
            pviewports_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewport);
}

void VulkanCppConsumer::Process_vkCmdUpdateBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdUpdateBuffer&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pdata_array = "pData_" + std::to_string(this->GetNextId());
    if (args.dataSize > 0) {
        std::string pdata_values = toStringJoin(args.pData.GetPointer(),
                                                args.pData.GetPointer() + args.dataSize,
                                                [&](const auto current) { return std::to_string(current) + ""; },
                                                ", ");
        fprintf(file, "\t\tuint8_t %s[] = { %s };\n", pdata_array.c_str(), pdata_values.c_str());
    } else {
        pdata_array = "NULL";
    }
    fprintf(file,
            "\t\tvkCmdUpdateBuffer(%s, %s, %" PRIu64 "UL, %" PRIu64 "UL, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.dstBuffer).c_str(),
            args.dstOffset,
            args.dataSize,
            pdata_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdUpdateBuffer);
}

void VulkanCppConsumer::Process_vkCmdWaitEvents(
    const ApiCallInfo&                          call_info,
    args::CmdWaitEvents&                        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pevents_array = "NULL";
    std::string pevents_values = toStringJoin(args.pEvents.GetPointer(),
                                              args.pEvents.GetPointer() + args.eventCount,
                                              [&](const format::HandleId current) { return this->GetHandle(current); },
                                              ", ");
    if (args.eventCount == 1 && pevents_values != "VK_NULL_HANDLE") {
        pevents_array = "&" + pevents_values;
    } else if (args.eventCount > 1) {
        pevents_array = "pevents_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkEvent %s[] = { %s };\n", pevents_array.c_str(), pevents_values.c_str());
    }
    std::stringstream stream_pmemory_barriers;
    std::string pmemory_barriers_array = "NULL";
    PointerPairContainer<decltype(args.pMemoryBarriers.GetPointer()), decltype(args.pMemoryBarriers.GetMetaStructPointer())> pmemory_barriers_pair{ args.pMemoryBarriers.GetPointer(), args.pMemoryBarriers.GetMetaStructPointer(), args.memoryBarrierCount };
    std::string pmemory_barriers_names = toStringJoin(pmemory_barriers_pair.begin(),
                                                      pmemory_barriers_pair.end(),
                                                      [&](auto pair) {{ return GenerateStruct_VkMemoryBarrier(stream_pmemory_barriers, pair.t1, pair.t2, *this); }},
                                                      ", ");
    if (stream_pmemory_barriers.str().length() > 0) {
        fprintf(file, "%s", stream_pmemory_barriers.str().c_str());
        if (args.memoryBarrierCount == 1) {
            pmemory_barriers_array = "&" + pmemory_barriers_names;
        } else if (args.memoryBarrierCount > 1) {
            pmemory_barriers_array = "pMemoryBarriers_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkMemoryBarrier %s[] = { %s };\n", pmemory_barriers_array.c_str(), pmemory_barriers_names.c_str());
        }
    }
    std::stringstream stream_pbuffer_memory_barriers;
    std::string pbuffer_memory_barriers_array = "NULL";
    PointerPairContainer<decltype(args.pBufferMemoryBarriers.GetPointer()), decltype(args.pBufferMemoryBarriers.GetMetaStructPointer())> pbuffer_memory_barriers_pair{ args.pBufferMemoryBarriers.GetPointer(), args.pBufferMemoryBarriers.GetMetaStructPointer(), args.bufferMemoryBarrierCount };
    std::string pbuffer_memory_barriers_names = toStringJoin(pbuffer_memory_barriers_pair.begin(),
                                                             pbuffer_memory_barriers_pair.end(),
                                                             [&](auto pair) {{ return GenerateStruct_VkBufferMemoryBarrier(stream_pbuffer_memory_barriers, pair.t1, pair.t2, *this); }},
                                                             ", ");
    if (stream_pbuffer_memory_barriers.str().length() > 0) {
        fprintf(file, "%s", stream_pbuffer_memory_barriers.str().c_str());
        if (args.bufferMemoryBarrierCount == 1) {
            pbuffer_memory_barriers_array = "&" + pbuffer_memory_barriers_names;
        } else if (args.bufferMemoryBarrierCount > 1) {
            pbuffer_memory_barriers_array = "pBufferMemoryBarriers_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBufferMemoryBarrier %s[] = { %s };\n", pbuffer_memory_barriers_array.c_str(), pbuffer_memory_barriers_names.c_str());
        }
    }
    std::stringstream stream_pimage_memory_barriers;
    std::string pimage_memory_barriers_array = "NULL";
    PointerPairContainer<decltype(args.pImageMemoryBarriers.GetPointer()), decltype(args.pImageMemoryBarriers.GetMetaStructPointer())> pimage_memory_barriers_pair{ args.pImageMemoryBarriers.GetPointer(), args.pImageMemoryBarriers.GetMetaStructPointer(), args.imageMemoryBarrierCount };
    std::string pimage_memory_barriers_names = toStringJoin(pimage_memory_barriers_pair.begin(),
                                                            pimage_memory_barriers_pair.end(),
                                                            [&](auto pair) {{ return GenerateStruct_VkImageMemoryBarrier(stream_pimage_memory_barriers, pair.t1, pair.t2, *this); }},
                                                            ", ");
    if (stream_pimage_memory_barriers.str().length() > 0) {
        fprintf(file, "%s", stream_pimage_memory_barriers.str().c_str());
        if (args.imageMemoryBarrierCount == 1) {
            pimage_memory_barriers_array = "&" + pimage_memory_barriers_names;
        } else if (args.imageMemoryBarrierCount > 1) {
            pimage_memory_barriers_array = "pImageMemoryBarriers_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkImageMemoryBarrier %s[] = { %s };\n", pimage_memory_barriers_array.c_str(), pimage_memory_barriers_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdWaitEvents(%s, %u, %s, %s, %s, %u, %s, %u, %s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.eventCount,
            pevents_array.c_str(),
            util::ToString<VkPipelineStageFlags>(args.srcStageMask).c_str(),
            util::ToString<VkPipelineStageFlags>(args.dstStageMask).c_str(),
            args.memoryBarrierCount,
            pmemory_barriers_array.c_str(),
            args.bufferMemoryBarrierCount,
            pbuffer_memory_barriers_array.c_str(),
            args.imageMemoryBarrierCount,
            pimage_memory_barriers_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWaitEvents);
}

void VulkanCppConsumer::Process_vkCmdWriteTimestamp(
    const ApiCallInfo&                          call_info,
    args::CmdWriteTimestamp&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdWriteTimestamp(%s, %s, %s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkPipelineStageFlagBits>(args.pipelineStage).c_str(),
            this->GetHandle(args.queryPool).c_str(),
            args.query);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteTimestamp);
}

void VulkanCppConsumer::Process_vkCreateBuffer(
    const ApiCallInfo&                          call_info,
    args::CreateBuffer&                         args)
{
    Generate_vkCreateBuffer(args);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateBuffer);
}

void VulkanCppConsumer::Process_vkCreateBufferView(
    const ApiCallInfo&                          call_info,
    args::CreateBufferView&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkBufferViewCreateInfo(stream_pcreate_info,
                                                                            args.pCreateInfo.GetPointer(),
                                                                            args.pCreateInfo.GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pview_name = "pView_" + std::to_string(this->GetNextId());
    AddKnownVariables("VkBufferView", pview_name, args.pView.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pview_name,
                         args.pView.GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateBufferView(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pview_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateBufferView);
}

void VulkanCppConsumer::Process_vkCreateCommandPool(
    const ApiCallInfo&                          call_info,
    args::CreateCommandPool&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkCommandPoolCreateInfo(stream_pcreate_info,
                                                                             args.pCreateInfo.GetPointer(),
                                                                             args.pCreateInfo.GetMetaStructPointer(),
                                                                             *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pcommand_pool_name = "pCommandPool_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_COMMAND_POOL));
    AddKnownVariables("VkCommandPool", pcommand_pool_name, args.pCommandPool.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pcommand_pool_name,
                         args.pCommandPool.GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateCommandPool(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pcommand_pool_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateCommandPool);
}

void VulkanCppConsumer::Process_vkCreateComputePipelines(
    const ApiCallInfo&                          call_info,
    args::CreateComputePipelines&               args)
{
    Generate_vkCreateComputePipelines(args);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateComputePipelines);
}

void VulkanCppConsumer::Process_vkCreateDescriptorPool(
    const ApiCallInfo&                          call_info,
    args::CreateDescriptorPool&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkDescriptorPoolCreateInfo(stream_pcreate_info,
                                                                                args.pCreateInfo.GetPointer(),
                                                                                args.pCreateInfo.GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pdescriptor_pool_name = "pDescriptorPool_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DESCRIPTOR_POOL));
    AddKnownVariables("VkDescriptorPool", pdescriptor_pool_name, args.pDescriptorPool.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pdescriptor_pool_name,
                         args.pDescriptorPool.GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateDescriptorPool(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pdescriptor_pool_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDescriptorPool);
}

void VulkanCppConsumer::Process_vkCreateDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    args::CreateDescriptorSetLayout&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkDescriptorSetLayoutCreateInfo(stream_pcreate_info,
                                                                                     args.pCreateInfo.GetPointer(),
                                                                                     args.pCreateInfo.GetMetaStructPointer(),
                                                                                     *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pset_layout_name = "pSetLayout_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT));
    AddKnownVariables("VkDescriptorSetLayout", pset_layout_name, args.pSetLayout.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pset_layout_name,
                         args.pSetLayout.GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateDescriptorSetLayout(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pset_layout_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout);
}

void VulkanCppConsumer::Process_vkCreateDevice(
    const ApiCallInfo&                          call_info,
    args::CreateDevice&                         args)
{
    Generate_vkCreateDevice(args);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDevice);
}

void VulkanCppConsumer::Process_vkCreateEvent(
    const ApiCallInfo&                          call_info,
    args::CreateEvent&                          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkEventCreateInfo(stream_pcreate_info,
                                                                       args.pCreateInfo.GetPointer(),
                                                                       args.pCreateInfo.GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pevent_name = "pEvent_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_EVENT));
    AddKnownVariables("VkEvent", pevent_name, args.pEvent.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pevent_name,
                         args.pEvent.GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateEvent(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pevent_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateEvent);
}

void VulkanCppConsumer::Process_vkCreateFence(
    const ApiCallInfo&                          call_info,
    args::CreateFence&                          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkFenceCreateInfo(stream_pcreate_info,
                                                                       args.pCreateInfo.GetPointer(),
                                                                       args.pCreateInfo.GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pfence_name = "pFence_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_FENCE));
    AddKnownVariables("VkFence", pfence_name, args.pFence.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pfence_name,
                         args.pFence.GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateFence(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pfence_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateFence);
}

void VulkanCppConsumer::Process_vkCreateFramebuffer(
    const ApiCallInfo&                          call_info,
    args::CreateFramebuffer&                    args)
{
    Intercept_vkCreateFramebuffer(args);
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkFramebufferCreateInfo(stream_pcreate_info,
                                                                             args.pCreateInfo.GetPointer(),
                                                                             args.pCreateInfo.GetMetaStructPointer(),
                                                                             *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pframebuffer_name = "pFramebuffer_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_FRAMEBUFFER));
    AddKnownVariables("VkFramebuffer", pframebuffer_name, args.pFramebuffer.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pframebuffer_name,
                         args.pFramebuffer.GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateFramebuffer(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pframebuffer_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateFramebuffer);
}

void VulkanCppConsumer::Process_vkCreateGraphicsPipelines(
    const ApiCallInfo&                          call_info,
    args::CreateGraphicsPipelines&              args)
{
    Generate_vkCreateGraphicsPipelines(args);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateGraphicsPipelines);
}

void VulkanCppConsumer::Process_vkCreateImage(
    const ApiCallInfo&                          call_info,
    args::CreateImage&                          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkImageCreateInfo(stream_pcreate_info,
                                                                       args.pCreateInfo.GetPointer(),
                                                                       args.pCreateInfo.GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pimage_name = "pImage_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_IMAGE));
    AddKnownVariables("VkImage", pimage_name, args.pImage.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pimage_name,
                         args.pImage.GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateImage(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pimage_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateImage);
}

void VulkanCppConsumer::Process_vkCreateImageView(
    const ApiCallInfo&                          call_info,
    args::CreateImageView&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkImageViewCreateInfo(stream_pcreate_info,
                                                                           args.pCreateInfo.GetPointer(),
                                                                           args.pCreateInfo.GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pview_name = "pView_" + std::to_string(this->GetNextId());
    AddKnownVariables("VkImageView", pview_name, args.pView.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pview_name,
                         args.pView.GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateImageView(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pview_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateImageView);
}

void VulkanCppConsumer::Process_vkCreateInstance(
    const ApiCallInfo&                          call_info,
    args::CreateInstance&                       args)
{
    Generate_vkCreateInstance(args);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateInstance);
}

void VulkanCppConsumer::Process_vkCreatePipelineCache(
    const ApiCallInfo&                          call_info,
    args::CreatePipelineCache&                  args)
{
    Generate_vkCreatePipelineCache(args);
    Post_APICall(format::ApiCallId::ApiCall_vkCreatePipelineCache);
}

void VulkanCppConsumer::Process_vkCreatePipelineLayout(
    const ApiCallInfo&                          call_info,
    args::CreatePipelineLayout&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkPipelineLayoutCreateInfo(stream_pcreate_info,
                                                                                args.pCreateInfo.GetPointer(),
                                                                                args.pCreateInfo.GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string ppipeline_layout_name = "pPipelineLayout_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_PIPELINE_LAYOUT));
    AddKnownVariables("VkPipelineLayout", ppipeline_layout_name, args.pPipelineLayout.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(ppipeline_layout_name,
                         args.pPipelineLayout.GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreatePipelineLayout(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            ppipeline_layout_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreatePipelineLayout);
}

void VulkanCppConsumer::Process_vkCreateQueryPool(
    const ApiCallInfo&                          call_info,
    args::CreateQueryPool&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkQueryPoolCreateInfo(stream_pcreate_info,
                                                                           args.pCreateInfo.GetPointer(),
                                                                           args.pCreateInfo.GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pquery_pool_name = "pQueryPool_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_QUERY_POOL));
    AddKnownVariables("VkQueryPool", pquery_pool_name, args.pQueryPool.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pquery_pool_name,
                         args.pQueryPool.GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateQueryPool(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pquery_pool_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateQueryPool);
}

void VulkanCppConsumer::Process_vkCreateRenderPass(
    const ApiCallInfo&                          call_info,
    args::CreateRenderPass&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkRenderPassCreateInfo(stream_pcreate_info,
                                                                            args.pCreateInfo.GetPointer(),
                                                                            args.pCreateInfo.GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string prender_pass_name = "pRenderPass_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_RENDER_PASS));
    AddKnownVariables("VkRenderPass", prender_pass_name, args.pRenderPass.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(prender_pass_name,
                         args.pRenderPass.GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateRenderPass(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            prender_pass_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateRenderPass);
}

void VulkanCppConsumer::Process_vkCreateSampler(
    const ApiCallInfo&                          call_info,
    args::CreateSampler&                        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkSamplerCreateInfo(stream_pcreate_info,
                                                                         args.pCreateInfo.GetPointer(),
                                                                         args.pCreateInfo.GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psampler_name = "pSampler_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SAMPLER));
    AddKnownVariables("VkSampler", psampler_name, args.pSampler.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(psampler_name,
                         args.pSampler.GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateSampler(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psampler_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateSampler);
}

void VulkanCppConsumer::Process_vkCreateSemaphore(
    const ApiCallInfo&                          call_info,
    args::CreateSemaphore&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkSemaphoreCreateInfo(stream_pcreate_info,
                                                                           args.pCreateInfo.GetPointer(),
                                                                           args.pCreateInfo.GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psemaphore_name = "pSemaphore_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SEMAPHORE));
    AddKnownVariables("VkSemaphore", psemaphore_name, args.pSemaphore.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(psemaphore_name,
                         args.pSemaphore.GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateSemaphore(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psemaphore_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateSemaphore);
}

void VulkanCppConsumer::Process_vkCreateShaderModule(
    const ApiCallInfo&                          call_info,
    args::CreateShaderModule&                   args)
{
    Generate_vkCreateShaderModule(args);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateShaderModule);
}

void VulkanCppConsumer::Process_vkDestroyBuffer(
    const ApiCallInfo&                          call_info,
    args::DestroyBuffer&                        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyBuffer(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.buffer).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyBuffer);
}

void VulkanCppConsumer::Process_vkDestroyBufferView(
    const ApiCallInfo&                          call_info,
    args::DestroyBufferView&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyBufferView(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.bufferView).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyBufferView);
}

void VulkanCppConsumer::Process_vkDestroyCommandPool(
    const ApiCallInfo&                          call_info,
    args::DestroyCommandPool&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyCommandPool(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.commandPool).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyCommandPool);
}

void VulkanCppConsumer::Process_vkDestroyDescriptorPool(
    const ApiCallInfo&                          call_info,
    args::DestroyDescriptorPool&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyDescriptorPool(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.descriptorPool).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDescriptorPool);
}

void VulkanCppConsumer::Process_vkDestroyDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    args::DestroyDescriptorSetLayout&           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyDescriptorSetLayout(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.descriptorSetLayout).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout);
}

void VulkanCppConsumer::Process_vkDestroyDevice(
    const ApiCallInfo&                          call_info,
    args::DestroyDevice&                        args)
{
    Generate_vkDestroyDevice(args);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDevice);
}

void VulkanCppConsumer::Process_vkDestroyEvent(
    const ApiCallInfo&                          call_info,
    args::DestroyEvent&                         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyEvent(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.event).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyEvent);
}

void VulkanCppConsumer::Process_vkDestroyFence(
    const ApiCallInfo&                          call_info,
    args::DestroyFence&                         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyFence(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.fence).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyFence);
}

void VulkanCppConsumer::Process_vkDestroyFramebuffer(
    const ApiCallInfo&                          call_info,
    args::DestroyFramebuffer&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyFramebuffer(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.framebuffer).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyFramebuffer);
}

void VulkanCppConsumer::Process_vkDestroyImage(
    const ApiCallInfo&                          call_info,
    args::DestroyImage&                         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyImage(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.image).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyImage);
}

void VulkanCppConsumer::Process_vkDestroyImageView(
    const ApiCallInfo&                          call_info,
    args::DestroyImageView&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyImageView(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.imageView).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyImageView);
}

void VulkanCppConsumer::Process_vkDestroyInstance(
    const ApiCallInfo&                          call_info,
    args::DestroyInstance&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyInstance(%s, %s);\n",
            this->GetHandle(args.instance).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyInstance);
}

void VulkanCppConsumer::Process_vkDestroyPipeline(
    const ApiCallInfo&                          call_info,
    args::DestroyPipeline&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyPipeline(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.pipeline).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPipeline);
}

void VulkanCppConsumer::Process_vkDestroyPipelineCache(
    const ApiCallInfo&                          call_info,
    args::DestroyPipelineCache&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyPipelineCache(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.pipelineCache).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPipelineCache);
}

void VulkanCppConsumer::Process_vkDestroyPipelineLayout(
    const ApiCallInfo&                          call_info,
    args::DestroyPipelineLayout&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyPipelineLayout(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.pipelineLayout).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPipelineLayout);
}

void VulkanCppConsumer::Process_vkDestroyQueryPool(
    const ApiCallInfo&                          call_info,
    args::DestroyQueryPool&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyQueryPool(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.queryPool).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyQueryPool);
}

void VulkanCppConsumer::Process_vkDestroyRenderPass(
    const ApiCallInfo&                          call_info,
    args::DestroyRenderPass&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyRenderPass(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.renderPass).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyRenderPass);
}

void VulkanCppConsumer::Process_vkDestroySampler(
    const ApiCallInfo&                          call_info,
    args::DestroySampler&                       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroySampler(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.sampler).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySampler);
}

void VulkanCppConsumer::Process_vkDestroySemaphore(
    const ApiCallInfo&                          call_info,
    args::DestroySemaphore&                     args)
{
    Intercept_vkDestroySemaphore(args);
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroySemaphore(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.semaphore).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySemaphore);
}

void VulkanCppConsumer::Process_vkDestroyShaderModule(
    const ApiCallInfo&                          call_info,
    args::DestroyShaderModule&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyShaderModule(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.shaderModule).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyShaderModule);
}

void VulkanCppConsumer::Process_vkDeviceWaitIdle(
    const ApiCallInfo&                          call_info,
    args::DeviceWaitIdle&                       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkDeviceWaitIdle(%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDeviceWaitIdle);
}

void VulkanCppConsumer::Process_vkEndCommandBuffer(
    const ApiCallInfo&                          call_info,
    args::EndCommandBuffer&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkEndCommandBuffer(%s), %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkEndCommandBuffer);
}

void VulkanCppConsumer::Process_vkEnumeratePhysicalDevices(
    const ApiCallInfo&                          call_info,
    args::EnumeratePhysicalDevices&             args)
{
    Generate_vkEnumeratePhysicalDevices(args);
    Post_APICall(format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices);
}

void VulkanCppConsumer::Process_vkFlushMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    args::FlushMappedMemoryRanges&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pmemory_ranges;
    std::string pmemory_ranges_array = "NULL";
    PointerPairContainer<decltype(args.pMemoryRanges.GetPointer()), decltype(args.pMemoryRanges.GetMetaStructPointer())> pmemory_ranges_pair{ args.pMemoryRanges.GetPointer(), args.pMemoryRanges.GetMetaStructPointer(), args.memoryRangeCount };
    std::string pmemory_ranges_names = toStringJoin(pmemory_ranges_pair.begin(),
                                                    pmemory_ranges_pair.end(),
                                                    [&](auto pair) {{ return GenerateStruct_VkMappedMemoryRange(stream_pmemory_ranges, pair.t1, pair.t2, *this); }},
                                                    ", ");
    if (stream_pmemory_ranges.str().length() > 0) {
        fprintf(file, "%s", stream_pmemory_ranges.str().c_str());
        if (args.memoryRangeCount == 1) {
            pmemory_ranges_array = "&" + pmemory_ranges_names;
        } else if (args.memoryRangeCount > 1) {
            pmemory_ranges_array = "pMemoryRanges_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkMappedMemoryRange %s[] = { %s };\n", pmemory_ranges_array.c_str(), pmemory_ranges_names.c_str());
        }
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkFlushMappedMemoryRanges(%s, %u, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            args.memoryRangeCount,
            pmemory_ranges_array.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges);
}

void VulkanCppConsumer::Process_vkFreeCommandBuffers(
    const ApiCallInfo&                          call_info,
    args::FreeCommandBuffers&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcommand_buffers_array = "NULL";
    std::string pcommand_buffers_values = toStringJoin(args.pCommandBuffers.GetPointer(),
                                                       args.pCommandBuffers.GetPointer() + args.commandBufferCount,
                                                       [&](const format::HandleId current) { return this->GetHandle(current); },
                                                       ", ");
    if (args.commandBufferCount == 1 && pcommand_buffers_values != "VK_NULL_HANDLE") {
        pcommand_buffers_array = "&" + pcommand_buffers_values;
    } else if (args.commandBufferCount > 1) {
        pcommand_buffers_array = "pcommand_buffers_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkCommandBuffer %s[] = { %s };\n", pcommand_buffers_array.c_str(), pcommand_buffers_values.c_str());
    }
    fprintf(file,
            "\t\tvkFreeCommandBuffers(%s, %s, %u, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.commandPool).c_str(),
            args.commandBufferCount,
            pcommand_buffers_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkFreeCommandBuffers);
}

void VulkanCppConsumer::Process_vkFreeDescriptorSets(
    const ApiCallInfo&                          call_info,
    args::FreeDescriptorSets&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pdescriptor_sets_array = "NULL";
    std::string pdescriptor_sets_values = toStringJoin(args.pDescriptorSets.GetPointer(),
                                                       args.pDescriptorSets.GetPointer() + args.descriptorSetCount,
                                                       [&](const format::HandleId current) { return this->GetHandle(current); },
                                                       ", ");
    if (args.descriptorSetCount == 1 && pdescriptor_sets_values != "VK_NULL_HANDLE") {
        pdescriptor_sets_array = "&" + pdescriptor_sets_values;
    } else if (args.descriptorSetCount > 1) {
        pdescriptor_sets_array = "pdescriptor_sets_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDescriptorSet %s[] = { %s };\n", pdescriptor_sets_array.c_str(), pdescriptor_sets_values.c_str());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkFreeDescriptorSets(%s, %s, %u, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.descriptorPool).c_str(),
            args.descriptorSetCount,
            pdescriptor_sets_array.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkFreeDescriptorSets);
}

void VulkanCppConsumer::Process_vkFreeMemory(
    const ApiCallInfo&                          call_info,
    args::FreeMemory&                           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkFreeMemory(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.memory).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkFreeMemory);
}

void VulkanCppConsumer::Process_vkGetBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    args::GetBufferMemoryRequirements&          args)
{
    Generate_vkGetBufferMemoryRequirements(args);
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements);
}

void VulkanCppConsumer::Process_vkGetDeviceMemoryCommitment(
    const ApiCallInfo&                          call_info,
    args::GetDeviceMemoryCommitment&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcommitted_memory_in_bytes_name = "NULL";
    if (!args.pCommittedMemoryInBytes.IsNull()) {
        pcommitted_memory_in_bytes_name = "pCommittedMemoryInBytes_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDeviceSize %s = %s;\n", pcommitted_memory_in_bytes_name.c_str(), util::ToString(*args.pCommittedMemoryInBytes.GetPointer()).c_str());
        pcommitted_memory_in_bytes_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetDeviceMemoryCommitment(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.memory).c_str(),
            pcommitted_memory_in_bytes_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment);
}

void VulkanCppConsumer::Process_vkGetDeviceQueue(
    const ApiCallInfo&                          call_info,
    args::GetDeviceQueue&                       args)
{
    Generate_vkGetDeviceQueue(args);
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceQueue);
}

void VulkanCppConsumer::Process_vkGetEventStatus(
    const ApiCallInfo&                          call_info,
    args::GetEventStatus&                       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkGetEventStatus(%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.event).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetEventStatus);
}

void VulkanCppConsumer::Process_vkGetFenceStatus(
    const ApiCallInfo&                          call_info,
    args::GetFenceStatus&                       args)
{
    Generate_vkGetFenceStatus(args);
    Post_APICall(format::ApiCallId::ApiCall_vkGetFenceStatus);
}

void VulkanCppConsumer::Process_vkGetImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    args::GetImageMemoryRequirements&           args)
{
    Generate_vkGetImageMemoryRequirements(args);
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements);
}

void VulkanCppConsumer::Process_vkGetImageSparseMemoryRequirements(
    const ApiCallInfo&                          call_info,
    args::GetImageSparseMemoryRequirements&     args)
{
    Generate_vkGetImageSparseMemoryRequirements(args);
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements);
}

void VulkanCppConsumer::Process_vkGetImageSubresourceLayout(
    const ApiCallInfo&                          call_info,
    args::GetImageSubresourceLayout&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psubresource;
    std::string psubresource_struct = GenerateStruct_VkImageSubresource(stream_psubresource,
                                                                        args.pSubresource.GetPointer(),
                                                                        args.pSubresource.GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_psubresource.str().c_str());
    std::string playout_name = "NULL";
    if (!args.pLayout.IsNull()) {
        playout_name = "pLayout_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkSubresourceLayout %s = {};\n", playout_name.c_str());
        playout_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetImageSubresourceLayout(%s, %s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.image).c_str(),
            psubresource_struct.c_str(),
            playout_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSubresourceLayout);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceFeatures(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceFeatures&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pfeatures_name = "NULL";
    if (!args.pFeatures.IsNull()) {
        pfeatures_name = "pFeatures_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPhysicalDeviceFeatures %s = {};\n", pfeatures_name.c_str());
        pfeatures_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetPhysicalDeviceFeatures(%s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pfeatures_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceFormatProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceFormatProperties&    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pformat_properties_name = "NULL";
    if (!args.pFormatProperties.IsNull()) {
        pformat_properties_name = "pFormatProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkFormatProperties %s = {};\n", pformat_properties_name.c_str());
        pformat_properties_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetPhysicalDeviceFormatProperties(%s, %s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            util::ToString<VkFormat>(args.format).c_str(),
            pformat_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceImageFormatProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceImageFormatProperties& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pimage_format_properties_name = "NULL";
    if (!args.pImageFormatProperties.IsNull()) {
        pimage_format_properties_name = "pImageFormatProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkImageFormatProperties %s = {};\n", pimage_format_properties_name.c_str());
        pimage_format_properties_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetPhysicalDeviceImageFormatProperties(%s, %s, %s, %s, %s, %s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            util::ToString<VkFormat>(args.format).c_str(),
            util::ToString<VkImageType>(args.type).c_str(),
            util::ToString<VkImageTiling>(args.tiling).c_str(),
            util::ToString<VkImageUsageFlags>(args.usage).c_str(),
            util::ToString<VkImageCreateFlags>(args.flags).c_str(),
            pimage_format_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceMemoryProperties&    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pmemory_properties_name = "NULL";
    if (!args.pMemoryProperties.IsNull()) {
        pmemory_properties_name = "pMemoryProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPhysicalDeviceMemoryProperties %s = {};\n", pmemory_properties_name.c_str());
        pmemory_properties_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetPhysicalDeviceMemoryProperties(%s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pmemory_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceProperties&          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPhysicalDeviceProperties %s = {};\n", pproperties_name.c_str());
        pproperties_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetPhysicalDeviceProperties(%s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pproperties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceQueueFamilyProperties& args)
{
    Generate_vkGetPhysicalDeviceQueueFamilyProperties(args);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSparseImageFormatProperties& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pproperty_count_name = "NULL";
    if (!args.pPropertyCount.IsNull()) {
        pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pproperty_count_name.c_str(), util::ToString(*args.pPropertyCount.GetPointer()).c_str());
        pproperty_count_name.insert(0, "&");
    }
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        const uint32_t* in_pproperty_count = args.pPropertyCount.GetPointer();
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkSparseImageFormatProperties %s[%d] = {};\n", pproperties_name.c_str(), *in_pproperty_count);
    }
    fprintf(file,
            "\t\tvkGetPhysicalDeviceSparseImageFormatProperties(%s, %s, %s, %s, %s, %s, %s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            util::ToString<VkFormat>(args.format).c_str(),
            util::ToString<VkImageType>(args.type).c_str(),
            util::ToString<VkSampleCountFlagBits>(args.samples).c_str(),
            util::ToString<VkImageUsageFlags>(args.usage).c_str(),
            util::ToString<VkImageTiling>(args.tiling).c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties);
}

void VulkanCppConsumer::Process_vkGetPipelineCacheData(
    const ApiCallInfo&                          call_info,
    args::GetPipelineCacheData&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file, "// TODO: Support vkGetPipelineCacheData function.\n");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPipelineCacheData);
}

void VulkanCppConsumer::Process_vkGetQueryPoolResults(
    const ApiCallInfo&                          call_info,
    args::GetQueryPoolResults&                  args)
{
    Generate_vkGetQueryPoolResults(args);
    Post_APICall(format::ApiCallId::ApiCall_vkGetQueryPoolResults);
}

void VulkanCppConsumer::Process_vkGetRenderAreaGranularity(
    const ApiCallInfo&                          call_info,
    args::GetRenderAreaGranularity&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pgranularity_name = "NULL";
    if (!args.pGranularity.IsNull()) {
        pgranularity_name = "pGranularity_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkExtent2D %s = {};\n", pgranularity_name.c_str());
        pgranularity_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetRenderAreaGranularity(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.renderPass).c_str(),
            pgranularity_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetRenderAreaGranularity);
}

void VulkanCppConsumer::Process_vkInvalidateMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    args::InvalidateMappedMemoryRanges&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pmemory_ranges;
    std::string pmemory_ranges_array = "NULL";
    PointerPairContainer<decltype(args.pMemoryRanges.GetPointer()), decltype(args.pMemoryRanges.GetMetaStructPointer())> pmemory_ranges_pair{ args.pMemoryRanges.GetPointer(), args.pMemoryRanges.GetMetaStructPointer(), args.memoryRangeCount };
    std::string pmemory_ranges_names = toStringJoin(pmemory_ranges_pair.begin(),
                                                    pmemory_ranges_pair.end(),
                                                    [&](auto pair) {{ return GenerateStruct_VkMappedMemoryRange(stream_pmemory_ranges, pair.t1, pair.t2, *this); }},
                                                    ", ");
    if (stream_pmemory_ranges.str().length() > 0) {
        fprintf(file, "%s", stream_pmemory_ranges.str().c_str());
        if (args.memoryRangeCount == 1) {
            pmemory_ranges_array = "&" + pmemory_ranges_names;
        } else if (args.memoryRangeCount > 1) {
            pmemory_ranges_array = "pMemoryRanges_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkMappedMemoryRange %s[] = { %s };\n", pmemory_ranges_array.c_str(), pmemory_ranges_names.c_str());
        }
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkInvalidateMappedMemoryRanges(%s, %u, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            args.memoryRangeCount,
            pmemory_ranges_array.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges);
}

void VulkanCppConsumer::Process_vkMapMemory(
    const ApiCallInfo&                          call_info,
    args::MapMemory&                            args)
{
    Generate_vkMapMemory(args);
    Post_APICall(format::ApiCallId::ApiCall_vkMapMemory);
}

void VulkanCppConsumer::Process_vkMergePipelineCaches(
    const ApiCallInfo&                          call_info,
    args::MergePipelineCaches&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string psrc_caches_array = "NULL";
    std::string psrc_caches_values = toStringJoin(args.pSrcCaches.GetPointer(),
                                                  args.pSrcCaches.GetPointer() + args.srcCacheCount,
                                                  [&](const format::HandleId current) { return this->GetHandle(current); },
                                                  ", ");
    if (args.srcCacheCount == 1 && psrc_caches_values != "VK_NULL_HANDLE") {
        psrc_caches_array = "&" + psrc_caches_values;
    } else if (args.srcCacheCount > 1) {
        psrc_caches_array = "psrc_caches_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPipelineCache %s[] = { %s };\n", psrc_caches_array.c_str(), psrc_caches_values.c_str());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkMergePipelineCaches(%s, %s, %u, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.dstCache).c_str(),
            args.srcCacheCount,
            psrc_caches_array.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkMergePipelineCaches);
}

void VulkanCppConsumer::Process_vkQueueBindSparse(
    const ApiCallInfo&                          call_info,
    args::QueueBindSparse&                      args)
{
    Generate_vkQueueBindSparse(args);
    Post_APICall(format::ApiCallId::ApiCall_vkQueueBindSparse);
}

void VulkanCppConsumer::Process_vkQueueSubmit(
    const ApiCallInfo&                          call_info,
    args::QueueSubmit&                          args)
{
    Generate_vkQueueSubmit(args);
    Post_APICall(format::ApiCallId::ApiCall_vkQueueSubmit);
}

void VulkanCppConsumer::Process_vkQueueWaitIdle(
    const ApiCallInfo&                          call_info,
    args::QueueWaitIdle&                        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkQueueWaitIdle(%s), %s);\n",
            this->GetHandle(args.queue).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkQueueWaitIdle);
}

void VulkanCppConsumer::Process_vkResetCommandBuffer(
    const ApiCallInfo&                          call_info,
    args::ResetCommandBuffer&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkResetCommandBuffer(%s, %s), %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkCommandBufferResetFlags>(args.flags).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkResetCommandBuffer);
}

void VulkanCppConsumer::Process_vkResetCommandPool(
    const ApiCallInfo&                          call_info,
    args::ResetCommandPool&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkResetCommandPool(%s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.commandPool).c_str(),
            util::ToString<VkCommandPoolResetFlags>(args.flags).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkResetCommandPool);
}

void VulkanCppConsumer::Process_vkResetDescriptorPool(
    const ApiCallInfo&                          call_info,
    args::ResetDescriptorPool&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkResetDescriptorPool(%s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.descriptorPool).c_str(),
            util::ToString<VkDescriptorPoolResetFlags>(args.flags).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkResetDescriptorPool);
}

void VulkanCppConsumer::Process_vkResetEvent(
    const ApiCallInfo&                          call_info,
    args::ResetEvent&                           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkResetEvent(%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.event).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkResetEvent);
}

void VulkanCppConsumer::Process_vkResetFences(
    const ApiCallInfo&                          call_info,
    args::ResetFences&                          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pfences_array = "NULL";
    std::string pfences_values = toStringJoin(args.pFences.GetPointer(),
                                              args.pFences.GetPointer() + args.fenceCount,
                                              [&](const format::HandleId current) { return this->GetHandle(current); },
                                              ", ");
    if (args.fenceCount == 1 && pfences_values != "VK_NULL_HANDLE") {
        pfences_array = "&" + pfences_values;
    } else if (args.fenceCount > 1) {
        pfences_array = "pfences_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkFence %s[] = { %s };\n", pfences_array.c_str(), pfences_values.c_str());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkResetFences(%s, %u, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            args.fenceCount,
            pfences_array.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkResetFences);
}

void VulkanCppConsumer::Process_vkSetEvent(
    const ApiCallInfo&                          call_info,
    args::SetEvent&                             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkSetEvent(%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.event).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSetEvent);
}

void VulkanCppConsumer::Process_vkUnmapMemory(
    const ApiCallInfo&                          call_info,
    args::UnmapMemory&                          args)
{
    Generate_vkUnmapMemory(args);
    Post_APICall(format::ApiCallId::ApiCall_vkUnmapMemory);
}

void VulkanCppConsumer::Process_vkUpdateDescriptorSets(
    const ApiCallInfo&                          call_info,
    args::UpdateDescriptorSets&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdescriptor_writes;
    std::string pdescriptor_writes_array = "NULL";
    PointerPairContainer<decltype(args.pDescriptorWrites.GetPointer()), decltype(args.pDescriptorWrites.GetMetaStructPointer())> pdescriptor_writes_pair{ args.pDescriptorWrites.GetPointer(), args.pDescriptorWrites.GetMetaStructPointer(), args.descriptorWriteCount };
    std::string pdescriptor_writes_names = toStringJoin(pdescriptor_writes_pair.begin(),
                                                        pdescriptor_writes_pair.end(),
                                                        [&](auto pair) {{ return GenerateStruct_VkWriteDescriptorSet(stream_pdescriptor_writes, pair.t1, pair.t2, *this); }},
                                                        ", ");
    if (stream_pdescriptor_writes.str().length() > 0) {
        fprintf(file, "%s", stream_pdescriptor_writes.str().c_str());
        if (args.descriptorWriteCount == 1) {
            pdescriptor_writes_array = "&" + pdescriptor_writes_names;
        } else if (args.descriptorWriteCount > 1) {
            pdescriptor_writes_array = "pDescriptorWrites_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkWriteDescriptorSet %s[] = { %s };\n", pdescriptor_writes_array.c_str(), pdescriptor_writes_names.c_str());
        }
    }
    std::stringstream stream_pdescriptor_copies;
    std::string pdescriptor_copies_array = "NULL";
    PointerPairContainer<decltype(args.pDescriptorCopies.GetPointer()), decltype(args.pDescriptorCopies.GetMetaStructPointer())> pdescriptor_copies_pair{ args.pDescriptorCopies.GetPointer(), args.pDescriptorCopies.GetMetaStructPointer(), args.descriptorCopyCount };
    std::string pdescriptor_copies_names = toStringJoin(pdescriptor_copies_pair.begin(),
                                                        pdescriptor_copies_pair.end(),
                                                        [&](auto pair) {{ return GenerateStruct_VkCopyDescriptorSet(stream_pdescriptor_copies, pair.t1, pair.t2, *this); }},
                                                        ", ");
    if (stream_pdescriptor_copies.str().length() > 0) {
        fprintf(file, "%s", stream_pdescriptor_copies.str().c_str());
        if (args.descriptorCopyCount == 1) {
            pdescriptor_copies_array = "&" + pdescriptor_copies_names;
        } else if (args.descriptorCopyCount > 1) {
            pdescriptor_copies_array = "pDescriptorCopies_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkCopyDescriptorSet %s[] = { %s };\n", pdescriptor_copies_array.c_str(), pdescriptor_copies_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkUpdateDescriptorSets(%s, %u, %s, %u, %s);\n",
            this->GetHandle(args.device).c_str(),
            args.descriptorWriteCount,
            pdescriptor_writes_array.c_str(),
            args.descriptorCopyCount,
            pdescriptor_copies_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkUpdateDescriptorSets);
}

void VulkanCppConsumer::Process_vkWaitForFences(
    const ApiCallInfo&                          call_info,
    args::WaitForFences&                        args)
{
    Generate_vkWaitForFences(args);
    Post_APICall(format::ApiCallId::ApiCall_vkWaitForFences);
}
void VulkanCppConsumer::Process_vkBindBufferMemory2(
    const ApiCallInfo&                          call_info,
    args::BindBufferMemory2&                    args)
{
    Intercept_vkBindBufferMemory2(args);
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbind_infos;
    std::string pbind_infos_array = "NULL";
    PointerPairContainer<decltype(args.pBindInfos.GetPointer()), decltype(args.pBindInfos.GetMetaStructPointer())> pbind_infos_pair{ args.pBindInfos.GetPointer(), args.pBindInfos.GetMetaStructPointer(), args.bindInfoCount };
    std::string pbind_infos_names = toStringJoin(pbind_infos_pair.begin(),
                                                 pbind_infos_pair.end(),
                                                 [&](auto pair) {{ return GenerateStruct_VkBindBufferMemoryInfo(stream_pbind_infos, pair.t1, pair.t2, *this); }},
                                                 ", ");
    if (stream_pbind_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pbind_infos.str().c_str());
        if (args.bindInfoCount == 1) {
            pbind_infos_array = "&" + pbind_infos_names;
        } else if (args.bindInfoCount > 1) {
            pbind_infos_array = "pBindInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBindBufferMemoryInfo %s[] = { %s };\n", pbind_infos_array.c_str(), pbind_infos_names.c_str());
        }
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkBindBufferMemory2(%s, %u, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            args.bindInfoCount,
            pbind_infos_array.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindBufferMemory2);
}

void VulkanCppConsumer::Process_vkBindImageMemory2(
    const ApiCallInfo&                          call_info,
    args::BindImageMemory2&                     args)
{
    Intercept_vkBindImageMemory2(args);
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbind_infos;
    std::string pbind_infos_array = "NULL";
    PointerPairContainer<decltype(args.pBindInfos.GetPointer()), decltype(args.pBindInfos.GetMetaStructPointer())> pbind_infos_pair{ args.pBindInfos.GetPointer(), args.pBindInfos.GetMetaStructPointer(), args.bindInfoCount };
    std::string pbind_infos_names = toStringJoin(pbind_infos_pair.begin(),
                                                 pbind_infos_pair.end(),
                                                 [&](auto pair) {{ return GenerateStruct_VkBindImageMemoryInfo(stream_pbind_infos, pair.t1, pair.t2, *this); }},
                                                 ", ");
    if (stream_pbind_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pbind_infos.str().c_str());
        if (args.bindInfoCount == 1) {
            pbind_infos_array = "&" + pbind_infos_names;
        } else if (args.bindInfoCount > 1) {
            pbind_infos_array = "pBindInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBindImageMemoryInfo %s[] = { %s };\n", pbind_infos_array.c_str(), pbind_infos_names.c_str());
        }
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkBindImageMemory2(%s, %u, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            args.bindInfoCount,
            pbind_infos_array.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindImageMemory2);
}

void VulkanCppConsumer::Process_vkCmdDispatchBase(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchBase&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdDispatchBase(%s, %u, %u, %u, %u, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.baseGroupX,
            args.baseGroupY,
            args.baseGroupZ,
            args.groupCountX,
            args.groupCountY,
            args.groupCountZ);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDispatchBase);
}

void VulkanCppConsumer::Process_vkCmdSetDeviceMask(
    const ApiCallInfo&                          call_info,
    args::CmdSetDeviceMask&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetDeviceMask(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.deviceMask);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDeviceMask);
}

void VulkanCppConsumer::Process_vkCreateDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    args::CreateDescriptorUpdateTemplate&       args)
{
    Generate_vkCreateDescriptorUpdateTemplate(args);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate);
}

void VulkanCppConsumer::Process_vkCreateSamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    args::CreateSamplerYcbcrConversion&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkSamplerYcbcrConversionCreateInfo(stream_pcreate_info,
                                                                                        args.pCreateInfo.GetPointer(),
                                                                                        args.pCreateInfo.GetMetaStructPointer(),
                                                                                        *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pycbcr_conversion_name = "pYcbcrConversion_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION));
    AddKnownVariables("VkSamplerYcbcrConversion", pycbcr_conversion_name, args.pYcbcrConversion.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pycbcr_conversion_name,
                         args.pYcbcrConversion.GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateSamplerYcbcrConversion(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pycbcr_conversion_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion);
}

void VulkanCppConsumer::Process_vkDestroyDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    args::DestroyDescriptorUpdateTemplate&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyDescriptorUpdateTemplate(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.descriptorUpdateTemplate).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate);
}

void VulkanCppConsumer::Process_vkDestroySamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    args::DestroySamplerYcbcrConversion&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroySamplerYcbcrConversion(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.ycbcrConversion).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion);
}

void VulkanCppConsumer::Process_vkEnumeratePhysicalDeviceGroups(
    const ApiCallInfo&                          call_info,
    args::EnumeratePhysicalDeviceGroups&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pphysical_device_group_count_name = "NULL";
    if (!args.pPhysicalDeviceGroupCount.IsNull()) {
        pphysical_device_group_count_name = "pPhysicalDeviceGroupCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pphysical_device_group_count_name.c_str(), util::ToString(*args.pPhysicalDeviceGroupCount.GetPointer()).c_str());
        pphysical_device_group_count_name.insert(0, "&");
    }
    std::string pphysical_device_group_properties_name = "NULL";
    if (!args.pPhysicalDeviceGroupProperties.IsNull()) {
        const uint32_t* in_pphysical_device_group_count = args.pPhysicalDeviceGroupCount.GetPointer();
        pphysical_device_group_properties_name = "pPhysicalDeviceGroupProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPhysicalDeviceGroupProperties %s[%d] = {};\n", pphysical_device_group_properties_name.c_str(), *in_pphysical_device_group_count);
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkEnumeratePhysicalDeviceGroups(%s, %s, %s), %s);\n",
            this->GetHandle(args.instance).c_str(),
            pphysical_device_group_count_name.c_str(),
            pphysical_device_group_properties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups);
}

void VulkanCppConsumer::Process_vkGetBufferMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    args::GetBufferMemoryRequirements2&         args)
{
    Generate_vkGetBufferMemoryRequirements2(args);
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2);
}

void VulkanCppConsumer::Process_vkGetDescriptorSetLayoutSupport(
    const ApiCallInfo&                          call_info,
    args::GetDescriptorSetLayoutSupport&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkDescriptorSetLayoutCreateInfo(stream_pcreate_info,
                                                                                     args.pCreateInfo.GetPointer(),
                                                                                     args.pCreateInfo.GetMetaStructPointer(),
                                                                                     *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psupport_name = "NULL";
    if (!args.pSupport.IsNull()) {
        psupport_name = "pSupport_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDescriptorSetLayoutSupport %s = {};\n", psupport_name.c_str());
        psupport_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetDescriptorSetLayoutSupport(%s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            psupport_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport);
}

void VulkanCppConsumer::Process_vkGetDeviceGroupPeerMemoryFeatures(
    const ApiCallInfo&                          call_info,
    args::GetDeviceGroupPeerMemoryFeatures&     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string ppeer_memory_features_name = "NULL";
    if (!args.pPeerMemoryFeatures.IsNull()) {
        ppeer_memory_features_name = "pPeerMemoryFeatures_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPeerMemoryFeatureFlags %s = %s;\n", ppeer_memory_features_name.c_str(), util::ToString(*args.pPeerMemoryFeatures.GetPointer()).c_str());
        ppeer_memory_features_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetDeviceGroupPeerMemoryFeatures(%s, %u, %u, %u, %s);\n",
            this->GetHandle(args.device).c_str(),
            args.heapIndex,
            args.localDeviceIndex,
            args.remoteDeviceIndex,
            ppeer_memory_features_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures);
}

void VulkanCppConsumer::Process_vkGetDeviceQueue2(
    const ApiCallInfo&                          call_info,
    args::GetDeviceQueue2&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pqueue_info;
    std::string pqueue_info_struct = GenerateStruct_VkDeviceQueueInfo2(stream_pqueue_info,
                                                                       args.pQueueInfo.GetPointer(),
                                                                       args.pQueueInfo.GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "%s", stream_pqueue_info.str().c_str());
    std::string pqueue_name = "pQueue_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_QUEUE));
    AddKnownVariables("VkQueue", pqueue_name, args.pQueue.GetPointer());
    this->AddHandles(pqueue_name,
                     args.pQueue.GetPointer());
    fprintf(file,
            "\t\tvkGetDeviceQueue2(%s, &%s, &%s);\n",
            this->GetHandle(args.device).c_str(),
            pqueue_info_struct.c_str(),
            pqueue_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceQueue2);
}

void VulkanCppConsumer::Process_vkGetImageMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    args::GetImageMemoryRequirements2&          args)
{
    Generate_vkGetImageMemoryRequirements2(args);
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2);
}

void VulkanCppConsumer::Process_vkGetImageSparseMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    args::GetImageSparseMemoryRequirements2&    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkImageSparseMemoryRequirementsInfo2(stream_pinfo,
                                                                                   args.pInfo.GetPointer(),
                                                                                   args.pInfo.GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string psparse_memory_requirement_count_name = "NULL";
    if (!args.pSparseMemoryRequirementCount.IsNull()) {
        psparse_memory_requirement_count_name = "pSparseMemoryRequirementCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", psparse_memory_requirement_count_name.c_str(), util::ToString(*args.pSparseMemoryRequirementCount.GetPointer()).c_str());
        psparse_memory_requirement_count_name.insert(0, "&");
    }
    std::string psparse_memory_requirements_name = "NULL";
    if (!args.pSparseMemoryRequirements.IsNull()) {
        const uint32_t* in_psparse_memory_requirement_count = args.pSparseMemoryRequirementCount.GetPointer();
        psparse_memory_requirements_name = "pSparseMemoryRequirements_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkSparseImageMemoryRequirements2 %s[%d] = {};\n", psparse_memory_requirements_name.c_str(), *in_psparse_memory_requirement_count);
    }
    fprintf(file,
            "\t\tvkGetImageSparseMemoryRequirements2(%s, &%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str(),
            psparse_memory_requirement_count_name.c_str(),
            psparse_memory_requirements_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceExternalBufferProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalBufferProperties& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pexternal_buffer_info;
    std::string pexternal_buffer_info_struct = GenerateStruct_VkPhysicalDeviceExternalBufferInfo(stream_pexternal_buffer_info,
                                                                                                 args.pExternalBufferInfo.GetPointer(),
                                                                                                 args.pExternalBufferInfo.GetMetaStructPointer(),
                                                                                                 *this);
    fprintf(file, "%s", stream_pexternal_buffer_info.str().c_str());
    std::string pexternal_buffer_properties_name = "NULL";
    if (!args.pExternalBufferProperties.IsNull()) {
        pexternal_buffer_properties_name = "pExternalBufferProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkExternalBufferProperties %s = {};\n", pexternal_buffer_properties_name.c_str());
        pexternal_buffer_properties_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetPhysicalDeviceExternalBufferProperties(%s, &%s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pexternal_buffer_info_struct.c_str(),
            pexternal_buffer_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceExternalFenceProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalFenceProperties& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pexternal_fence_info;
    std::string pexternal_fence_info_struct = GenerateStruct_VkPhysicalDeviceExternalFenceInfo(stream_pexternal_fence_info,
                                                                                               args.pExternalFenceInfo.GetPointer(),
                                                                                               args.pExternalFenceInfo.GetMetaStructPointer(),
                                                                                               *this);
    fprintf(file, "%s", stream_pexternal_fence_info.str().c_str());
    std::string pexternal_fence_properties_name = "NULL";
    if (!args.pExternalFenceProperties.IsNull()) {
        pexternal_fence_properties_name = "pExternalFenceProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkExternalFenceProperties %s = {};\n", pexternal_fence_properties_name.c_str());
        pexternal_fence_properties_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetPhysicalDeviceExternalFenceProperties(%s, &%s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pexternal_fence_info_struct.c_str(),
            pexternal_fence_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalSemaphoreProperties& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pexternal_semaphore_info;
    std::string pexternal_semaphore_info_struct = GenerateStruct_VkPhysicalDeviceExternalSemaphoreInfo(stream_pexternal_semaphore_info,
                                                                                                       args.pExternalSemaphoreInfo.GetPointer(),
                                                                                                       args.pExternalSemaphoreInfo.GetMetaStructPointer(),
                                                                                                       *this);
    fprintf(file, "%s", stream_pexternal_semaphore_info.str().c_str());
    std::string pexternal_semaphore_properties_name = "NULL";
    if (!args.pExternalSemaphoreProperties.IsNull()) {
        pexternal_semaphore_properties_name = "pExternalSemaphoreProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkExternalSemaphoreProperties %s = {};\n", pexternal_semaphore_properties_name.c_str());
        pexternal_semaphore_properties_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetPhysicalDeviceExternalSemaphoreProperties(%s, &%s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pexternal_semaphore_info_struct.c_str(),
            pexternal_semaphore_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceFeatures2(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceFeatures2&           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pfeatures_name = "NULL";
    if (!args.pFeatures.IsNull()) {
        pfeatures_name = "pFeatures_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPhysicalDeviceFeatures2 %s = {};\n", pfeatures_name.c_str());
        pfeatures_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetPhysicalDeviceFeatures2(%s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pfeatures_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceFormatProperties2(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceFormatProperties2&   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pformat_properties_name = "NULL";
    if (!args.pFormatProperties.IsNull()) {
        pformat_properties_name = "pFormatProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkFormatProperties2 %s = {};\n", pformat_properties_name.c_str());
        pformat_properties_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetPhysicalDeviceFormatProperties2(%s, %s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            util::ToString<VkFormat>(args.format).c_str(),
            pformat_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceImageFormatProperties2& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pimage_format_info;
    std::string pimage_format_info_struct = GenerateStruct_VkPhysicalDeviceImageFormatInfo2(stream_pimage_format_info,
                                                                                            args.pImageFormatInfo.GetPointer(),
                                                                                            args.pImageFormatInfo.GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pimage_format_info.str().c_str());
    std::string pimage_format_properties_name = "NULL";
    if (!args.pImageFormatProperties.IsNull()) {
        pimage_format_properties_name = "pImageFormatProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkImageFormatProperties2 %s = {};\n", pimage_format_properties_name.c_str());
        pimage_format_properties_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkGetPhysicalDeviceImageFormatProperties2(%s, &%s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pimage_format_info_struct.c_str(),
            pimage_format_properties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceMemoryProperties2(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceMemoryProperties2&   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pmemory_properties_name = "NULL";
    if (!args.pMemoryProperties.IsNull()) {
        pmemory_properties_name = "pMemoryProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPhysicalDeviceMemoryProperties2 %s = {};\n", pmemory_properties_name.c_str());
        pmemory_properties_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetPhysicalDeviceMemoryProperties2(%s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pmemory_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceProperties2(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceProperties2&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPhysicalDeviceProperties2 %s = {};\n", pproperties_name.c_str());
        pproperties_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetPhysicalDeviceProperties2(%s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pproperties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceQueueFamilyProperties2& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pqueue_family_property_count_name = "NULL";
    if (!args.pQueueFamilyPropertyCount.IsNull()) {
        pqueue_family_property_count_name = "pQueueFamilyPropertyCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pqueue_family_property_count_name.c_str(), util::ToString(*args.pQueueFamilyPropertyCount.GetPointer()).c_str());
        pqueue_family_property_count_name.insert(0, "&");
    }
    std::string pqueue_family_properties_name = "NULL";
    if (!args.pQueueFamilyProperties.IsNull()) {
        const uint32_t* in_pqueue_family_property_count = args.pQueueFamilyPropertyCount.GetPointer();
        pqueue_family_properties_name = "pQueueFamilyProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkQueueFamilyProperties2 %s[%d] = {};\n", pqueue_family_properties_name.c_str(), *in_pqueue_family_property_count);
    }
    fprintf(file,
            "\t\tvkGetPhysicalDeviceQueueFamilyProperties2(%s, %s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pqueue_family_property_count_name.c_str(),
            pqueue_family_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSparseImageFormatProperties2& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pformat_info;
    std::string pformat_info_struct = GenerateStruct_VkPhysicalDeviceSparseImageFormatInfo2(stream_pformat_info,
                                                                                            args.pFormatInfo.GetPointer(),
                                                                                            args.pFormatInfo.GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pformat_info.str().c_str());
    std::string pproperty_count_name = "NULL";
    if (!args.pPropertyCount.IsNull()) {
        pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pproperty_count_name.c_str(), util::ToString(*args.pPropertyCount.GetPointer()).c_str());
        pproperty_count_name.insert(0, "&");
    }
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        const uint32_t* in_pproperty_count = args.pPropertyCount.GetPointer();
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkSparseImageFormatProperties2 %s[%d] = {};\n", pproperties_name.c_str(), *in_pproperty_count);
    }
    fprintf(file,
            "\t\tvkGetPhysicalDeviceSparseImageFormatProperties2(%s, &%s, %s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pformat_info_struct.c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2);
}

void VulkanCppConsumer::Process_vkTrimCommandPool(
    const ApiCallInfo&                          call_info,
    args::TrimCommandPool&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkTrimCommandPool(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.commandPool).c_str(),
            util::ToString<VkCommandPoolTrimFlags>(args.flags).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkTrimCommandPool);
}
void VulkanCppConsumer::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderPass2&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_prender_pass_begin;
    std::string prender_pass_begin_struct = GenerateStruct_VkRenderPassBeginInfo(stream_prender_pass_begin,
                                                                                 args.pRenderPassBegin.GetPointer(),
                                                                                 args.pRenderPassBegin.GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_prender_pass_begin.str().c_str());
    std::stringstream stream_psubpass_begin_info;
    std::string psubpass_begin_info_struct = GenerateStruct_VkSubpassBeginInfo(stream_psubpass_begin_info,
                                                                               args.pSubpassBeginInfo.GetPointer(),
                                                                               args.pSubpassBeginInfo.GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_psubpass_begin_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdBeginRenderPass2(%s, &%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            prender_pass_begin_struct.c_str(),
            psubpass_begin_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginRenderPass2);
}

void VulkanCppConsumer::Process_vkCmdDrawIndexedIndirectCount(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCount&          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdDrawIndexedIndirectCount(%s, %s, %" PRIu64 "UL, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.buffer).c_str(),
            args.offset,
            this->GetHandle(args.countBuffer).c_str(),
            args.countBufferOffset,
            args.maxDrawCount,
            args.stride);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount);
}

void VulkanCppConsumer::Process_vkCmdDrawIndirectCount(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCount&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdDrawIndirectCount(%s, %s, %" PRIu64 "UL, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.buffer).c_str(),
            args.offset,
            this->GetHandle(args.countBuffer).c_str(),
            args.countBufferOffset,
            args.maxDrawCount,
            args.stride);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirectCount);
}

void VulkanCppConsumer::Process_vkCmdEndRenderPass2(
    const ApiCallInfo&                          call_info,
    args::CmdEndRenderPass2&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psubpass_end_info;
    std::string psubpass_end_info_struct = GenerateStruct_VkSubpassEndInfo(stream_psubpass_end_info,
                                                                           args.pSubpassEndInfo.GetPointer(),
                                                                           args.pSubpassEndInfo.GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_psubpass_end_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdEndRenderPass2(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            psubpass_end_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRenderPass2);
}

void VulkanCppConsumer::Process_vkCmdNextSubpass2(
    const ApiCallInfo&                          call_info,
    args::CmdNextSubpass2&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psubpass_begin_info;
    std::string psubpass_begin_info_struct = GenerateStruct_VkSubpassBeginInfo(stream_psubpass_begin_info,
                                                                               args.pSubpassBeginInfo.GetPointer(),
                                                                               args.pSubpassBeginInfo.GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_psubpass_begin_info.str().c_str());
    std::stringstream stream_psubpass_end_info;
    std::string psubpass_end_info_struct = GenerateStruct_VkSubpassEndInfo(stream_psubpass_end_info,
                                                                           args.pSubpassEndInfo.GetPointer(),
                                                                           args.pSubpassEndInfo.GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_psubpass_end_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdNextSubpass2(%s, &%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            psubpass_begin_info_struct.c_str(),
            psubpass_end_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdNextSubpass2);
}

void VulkanCppConsumer::Process_vkCreateRenderPass2(
    const ApiCallInfo&                          call_info,
    args::CreateRenderPass2&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkRenderPassCreateInfo2(stream_pcreate_info,
                                                                             args.pCreateInfo.GetPointer(),
                                                                             args.pCreateInfo.GetMetaStructPointer(),
                                                                             *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string prender_pass_name = "pRenderPass_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_RENDER_PASS));
    AddKnownVariables("VkRenderPass", prender_pass_name, args.pRenderPass.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(prender_pass_name,
                         args.pRenderPass.GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateRenderPass2(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            prender_pass_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateRenderPass2);
}

void VulkanCppConsumer::Process_vkGetBufferDeviceAddress(
    const ApiCallInfo&                          call_info,
    args::GetBufferDeviceAddress&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkBufferDeviceAddressInfo(stream_pinfo,
                                                                        args.pInfo.GetPointer(),
                                                                        args.pInfo.GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    fprintf(file,
            "\t\tvkGetBufferDeviceAddress(%s, &%s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferDeviceAddress);
}

void VulkanCppConsumer::Process_vkGetBufferOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    args::GetBufferOpaqueCaptureAddress&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkBufferDeviceAddressInfo(stream_pinfo,
                                                                        args.pInfo.GetPointer(),
                                                                        args.pInfo.GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    fprintf(file,
            "\t\tvkGetBufferOpaqueCaptureAddress(%s, &%s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress);
}

void VulkanCppConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    args::GetDeviceMemoryOpaqueCaptureAddress&  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDeviceMemoryOpaqueCaptureAddressInfo(stream_pinfo,
                                                                                     args.pInfo.GetPointer(),
                                                                                     args.pInfo.GetMetaStructPointer(),
                                                                                     *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    fprintf(file,
            "\t\tvkGetDeviceMemoryOpaqueCaptureAddress(%s, &%s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress);
}

void VulkanCppConsumer::Process_vkGetSemaphoreCounterValue(
    const ApiCallInfo&                          call_info,
    args::GetSemaphoreCounterValue&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pvalue_name = "NULL";
    if (!args.pValue.IsNull()) {
        pvalue_name = "pValue_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint64_t %s = %s;\n", pvalue_name.c_str(), util::ToString(*args.pValue.GetPointer()).c_str());
        pvalue_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkGetSemaphoreCounterValue(%s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.semaphore).c_str(),
            pvalue_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue);
}

void VulkanCppConsumer::Process_vkResetQueryPool(
    const ApiCallInfo&                          call_info,
    args::ResetQueryPool&                       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkResetQueryPool(%s, %s, %u, %u);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.queryPool).c_str(),
            args.firstQuery,
            args.queryCount);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkResetQueryPool);
}

void VulkanCppConsumer::Process_vkSignalSemaphore(
    const ApiCallInfo&                          call_info,
    args::SignalSemaphore&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psignal_info;
    std::string psignal_info_struct = GenerateStruct_VkSemaphoreSignalInfo(stream_psignal_info,
                                                                           args.pSignalInfo.GetPointer(),
                                                                           args.pSignalInfo.GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_psignal_info.str().c_str());
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkSignalSemaphore(%s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            psignal_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSignalSemaphore);
}

void VulkanCppConsumer::Process_vkWaitSemaphores(
    const ApiCallInfo&                          call_info,
    args::WaitSemaphores&                       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pwait_info;
    std::string pwait_info_struct = GenerateStruct_VkSemaphoreWaitInfo(stream_pwait_info,
                                                                       args.pWaitInfo.GetPointer(),
                                                                       args.pWaitInfo.GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "%s", stream_pwait_info.str().c_str());
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkWaitSemaphores(%s, &%s, %" PRIu64 "UL), %s);\n",
            this->GetHandle(args.device).c_str(),
            pwait_info_struct.c_str(),
            args.timeout,
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkWaitSemaphores);
}
void VulkanCppConsumer::Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRendering&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_prendering_info;
    std::string prendering_info_struct = GenerateStruct_VkRenderingInfo(stream_prendering_info,
                                                                        args.pRenderingInfo.GetPointer(),
                                                                        args.pRenderingInfo.GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_prendering_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdBeginRendering(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            prendering_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginRendering);
}

void VulkanCppConsumer::Process_vkCmdBindVertexBuffers2(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers2&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pbuffers_array = "NULL";
    std::string pbuffers_values = toStringJoin(args.pBuffers.GetPointer(),
                                               args.pBuffers.GetPointer() + args.bindingCount,
                                               [&](const format::HandleId current) { return this->GetHandle(current); },
                                               ", ");
    if (args.bindingCount == 1 && pbuffers_values != "VK_NULL_HANDLE") {
        pbuffers_array = "&" + pbuffers_values;
    } else if (args.bindingCount > 1) {
        pbuffers_array = "pbuffers_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkBuffer %s[] = { %s };\n", pbuffers_array.c_str(), pbuffers_values.c_str());
    }
    std::string poffsets_array = "pOffsets_" + std::to_string(this->GetNextId());
    if (args.bindingCount > 0) {
        std::string poffsets_values = toStringJoin(args.pOffsets.GetPointer(),
                                                   args.pOffsets.GetPointer() + args.bindingCount,
                                                   [&](const auto current) { return std::to_string(current) + "UL"; },
                                                   ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", poffsets_array.c_str(), poffsets_values.c_str());
    } else {
        poffsets_array = "NULL";
    }
    std::string psizes_array = "pSizes_" + std::to_string(this->GetNextId());
    if (args.bindingCount > 0 && args.pSizes.GetPointer() != nullptr) {
        std::string psizes_values = toStringJoin(args.pSizes.GetPointer(),
                                                 args.pSizes.GetPointer() + args.bindingCount,
                                                 [&](const auto current) { return std::to_string(current) + "UL"; },
                                                 ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", psizes_array.c_str(), psizes_values.c_str());
    } else {
        psizes_array = "NULL";
    }
    std::string pstrides_array = "pStrides_" + std::to_string(this->GetNextId());
    if (args.bindingCount > 0 && args.pStrides.GetPointer() != nullptr) {
        std::string pstrides_values = toStringJoin(args.pStrides.GetPointer(),
                                                   args.pStrides.GetPointer() + args.bindingCount,
                                                   [&](const auto current) { return std::to_string(current) + "UL"; },
                                                   ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", pstrides_array.c_str(), pstrides_values.c_str());
    } else {
        pstrides_array = "NULL";
    }
    fprintf(file,
            "\t\tvkCmdBindVertexBuffers2(%s, %u, %u, %s, %s, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.firstBinding,
            args.bindingCount,
            pbuffers_array.c_str(),
            poffsets_array.c_str(),
            psizes_array.c_str(),
            pstrides_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2);
}

void VulkanCppConsumer::Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    args::CmdBlitImage2&                        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pblit_image_info;
    std::string pblit_image_info_struct = GenerateStruct_VkBlitImageInfo2(stream_pblit_image_info,
                                                                          args.pBlitImageInfo.GetPointer(),
                                                                          args.pBlitImageInfo.GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pblit_image_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdBlitImage2(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pblit_image_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBlitImage2);
}

void VulkanCppConsumer::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBuffer2&                       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_buffer_info;
    std::string pcopy_buffer_info_struct = GenerateStruct_VkCopyBufferInfo2(stream_pcopy_buffer_info,
                                                                            args.pCopyBufferInfo.GetPointer(),
                                                                            args.pCopyBufferInfo.GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pcopy_buffer_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdCopyBuffer2(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pcopy_buffer_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyBuffer2);
}

void VulkanCppConsumer::Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBufferToImage2&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_buffer_to_image_info;
    std::string pcopy_buffer_to_image_info_struct = GenerateStruct_VkCopyBufferToImageInfo2(stream_pcopy_buffer_to_image_info,
                                                                                            args.pCopyBufferToImageInfo.GetPointer(),
                                                                                            args.pCopyBufferToImageInfo.GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pcopy_buffer_to_image_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdCopyBufferToImage2(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pcopy_buffer_to_image_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2);
}

void VulkanCppConsumer::Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImage2&                        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_image_info;
    std::string pcopy_image_info_struct = GenerateStruct_VkCopyImageInfo2(stream_pcopy_image_info,
                                                                          args.pCopyImageInfo.GetPointer(),
                                                                          args.pCopyImageInfo.GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pcopy_image_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdCopyImage2(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pcopy_image_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImage2);
}

void VulkanCppConsumer::Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToBuffer2&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_image_to_buffer_info;
    std::string pcopy_image_to_buffer_info_struct = GenerateStruct_VkCopyImageToBufferInfo2(stream_pcopy_image_to_buffer_info,
                                                                                            args.pCopyImageToBufferInfo.GetPointer(),
                                                                                            args.pCopyImageToBufferInfo.GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pcopy_image_to_buffer_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdCopyImageToBuffer2(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pcopy_image_to_buffer_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2);
}

void VulkanCppConsumer::Process_vkCmdEndRendering(
    const ApiCallInfo&                          call_info,
    args::CmdEndRendering&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdEndRendering(%s);\n",
            this->GetHandle(args.commandBuffer).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRendering);
}

void VulkanCppConsumer::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    args::CmdPipelineBarrier2&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdependency_info;
    std::string pdependency_info_struct = GenerateStruct_VkDependencyInfo(stream_pdependency_info,
                                                                          args.pDependencyInfo.GetPointer(),
                                                                          args.pDependencyInfo.GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pdependency_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdPipelineBarrier2(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pdependency_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPipelineBarrier2);
}

void VulkanCppConsumer::Process_vkCmdResetEvent2(
    const ApiCallInfo&                          call_info,
    args::CmdResetEvent2&                       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdResetEvent2(%s, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.event).c_str(),
            util::ToString<VkPipelineStageFlags2>(args.stageMask).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResetEvent2);
}

void VulkanCppConsumer::Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    args::CmdResolveImage2&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_presolve_image_info;
    std::string presolve_image_info_struct = GenerateStruct_VkResolveImageInfo2(stream_presolve_image_info,
                                                                                args.pResolveImageInfo.GetPointer(),
                                                                                args.pResolveImageInfo.GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_presolve_image_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdResolveImage2(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            presolve_image_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResolveImage2);
}

void VulkanCppConsumer::Process_vkCmdSetCullMode(
    const ApiCallInfo&                          call_info,
    args::CmdSetCullMode&                       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetCullMode(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkCullModeFlags>(args.cullMode).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCullMode);
}

void VulkanCppConsumer::Process_vkCmdSetDepthBiasEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBiasEnable&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetDepthBiasEnable(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.depthBiasEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable);
}

void VulkanCppConsumer::Process_vkCmdSetDepthBoundsTestEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBoundsTestEnable&          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetDepthBoundsTestEnable(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.depthBoundsTestEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable);
}

void VulkanCppConsumer::Process_vkCmdSetDepthCompareOp(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthCompareOp&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetDepthCompareOp(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkCompareOp>(args.depthCompareOp).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp);
}

void VulkanCppConsumer::Process_vkCmdSetDepthTestEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthTestEnable&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetDepthTestEnable(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.depthTestEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable);
}

void VulkanCppConsumer::Process_vkCmdSetDepthWriteEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthWriteEnable&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetDepthWriteEnable(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.depthWriteEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable);
}

void VulkanCppConsumer::Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    args::CmdSetEvent2&                         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdependency_info;
    std::string pdependency_info_struct = GenerateStruct_VkDependencyInfo(stream_pdependency_info,
                                                                          args.pDependencyInfo.GetPointer(),
                                                                          args.pDependencyInfo.GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pdependency_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdSetEvent2(%s, %s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.event).c_str(),
            pdependency_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetEvent2);
}

void VulkanCppConsumer::Process_vkCmdSetFrontFace(
    const ApiCallInfo&                          call_info,
    args::CmdSetFrontFace&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetFrontFace(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkFrontFace>(args.frontFace).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetFrontFace);
}

void VulkanCppConsumer::Process_vkCmdSetPrimitiveRestartEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveRestartEnable&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetPrimitiveRestartEnable(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.primitiveRestartEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable);
}

void VulkanCppConsumer::Process_vkCmdSetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveTopology&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetPrimitiveTopology(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkPrimitiveTopology>(args.primitiveTopology).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology);
}

void VulkanCppConsumer::Process_vkCmdSetRasterizerDiscardEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetRasterizerDiscardEnable&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetRasterizerDiscardEnable(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.rasterizerDiscardEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable);
}

void VulkanCppConsumer::Process_vkCmdSetScissorWithCount(
    const ApiCallInfo&                          call_info,
    args::CmdSetScissorWithCount&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pscissors;
    std::string pscissors_array = "NULL";
    PointerPairContainer<decltype(args.pScissors.GetPointer()), decltype(args.pScissors.GetMetaStructPointer())> pscissors_pair{ args.pScissors.GetPointer(), args.pScissors.GetMetaStructPointer(), args.scissorCount };
    std::string pscissors_names = toStringJoin(pscissors_pair.begin(),
                                               pscissors_pair.end(),
                                               [&](auto pair) {{ return GenerateStruct_VkRect2D(stream_pscissors, pair.t1, pair.t2, *this); }},
                                               ", ");
    if (stream_pscissors.str().length() > 0) {
        fprintf(file, "%s", stream_pscissors.str().c_str());
        if (args.scissorCount == 1) {
            pscissors_array = "&" + pscissors_names;
        } else if (args.scissorCount > 1) {
            pscissors_array = "pScissors_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkRect2D %s[] = { %s };\n", pscissors_array.c_str(), pscissors_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdSetScissorWithCount(%s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.scissorCount,
            pscissors_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetScissorWithCount);
}

void VulkanCppConsumer::Process_vkCmdSetStencilOp(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilOp&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetStencilOp(%s, %s, %s, %s, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkStencilFaceFlags>(args.faceMask).c_str(),
            util::ToString<VkStencilOp>(args.failOp).c_str(),
            util::ToString<VkStencilOp>(args.passOp).c_str(),
            util::ToString<VkStencilOp>(args.depthFailOp).c_str(),
            util::ToString<VkCompareOp>(args.compareOp).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilOp);
}

void VulkanCppConsumer::Process_vkCmdSetStencilTestEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilTestEnable&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetStencilTestEnable(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.stencilTestEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable);
}

void VulkanCppConsumer::Process_vkCmdSetViewportWithCount(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportWithCount&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pviewports;
    std::string pviewports_array = "NULL";
    PointerPairContainer<decltype(args.pViewports.GetPointer()), decltype(args.pViewports.GetMetaStructPointer())> pviewports_pair{ args.pViewports.GetPointer(), args.pViewports.GetMetaStructPointer(), args.viewportCount };
    std::string pviewports_names = toStringJoin(pviewports_pair.begin(),
                                                pviewports_pair.end(),
                                                [&](auto pair) {{ return GenerateStruct_VkViewport(stream_pviewports, pair.t1, pair.t2, *this); }},
                                                ", ");
    if (stream_pviewports.str().length() > 0) {
        fprintf(file, "%s", stream_pviewports.str().c_str());
        if (args.viewportCount == 1) {
            pviewports_array = "&" + pviewports_names;
        } else if (args.viewportCount > 1) {
            pviewports_array = "pViewports_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkViewport %s[] = { %s };\n", pviewports_array.c_str(), pviewports_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdSetViewportWithCount(%s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.viewportCount,
            pviewports_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewportWithCount);
}

void VulkanCppConsumer::Process_vkCmdWaitEvents2(
    const ApiCallInfo&                          call_info,
    args::CmdWaitEvents2&                       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pevents_array = "NULL";
    std::string pevents_values = toStringJoin(args.pEvents.GetPointer(),
                                              args.pEvents.GetPointer() + args.eventCount,
                                              [&](const format::HandleId current) { return this->GetHandle(current); },
                                              ", ");
    if (args.eventCount == 1 && pevents_values != "VK_NULL_HANDLE") {
        pevents_array = "&" + pevents_values;
    } else if (args.eventCount > 1) {
        pevents_array = "pevents_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkEvent %s[] = { %s };\n", pevents_array.c_str(), pevents_values.c_str());
    }
    std::stringstream stream_pdependency_infos;
    std::string pdependency_infos_array = "NULL";
    PointerPairContainer<decltype(args.pDependencyInfos.GetPointer()), decltype(args.pDependencyInfos.GetMetaStructPointer())> pdependency_infos_pair{ args.pDependencyInfos.GetPointer(), args.pDependencyInfos.GetMetaStructPointer(), args.eventCount };
    std::string pdependency_infos_names = toStringJoin(pdependency_infos_pair.begin(),
                                                       pdependency_infos_pair.end(),
                                                       [&](auto pair) {{ return GenerateStruct_VkDependencyInfo(stream_pdependency_infos, pair.t1, pair.t2, *this); }},
                                                       ", ");
    if (stream_pdependency_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pdependency_infos.str().c_str());
        if (args.eventCount == 1) {
            pdependency_infos_array = "&" + pdependency_infos_names;
        } else if (args.eventCount > 1) {
            pdependency_infos_array = "pDependencyInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkDependencyInfo %s[] = { %s };\n", pdependency_infos_array.c_str(), pdependency_infos_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdWaitEvents2(%s, %u, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.eventCount,
            pevents_array.c_str(),
            pdependency_infos_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWaitEvents2);
}

void VulkanCppConsumer::Process_vkCmdWriteTimestamp2(
    const ApiCallInfo&                          call_info,
    args::CmdWriteTimestamp2&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdWriteTimestamp2(%s, %s, %s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkPipelineStageFlags2>(args.stage).c_str(),
            this->GetHandle(args.queryPool).c_str(),
            args.query);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteTimestamp2);
}

void VulkanCppConsumer::Process_vkCreatePrivateDataSlot(
    const ApiCallInfo&                          call_info,
    args::CreatePrivateDataSlot&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkPrivateDataSlotCreateInfo(stream_pcreate_info,
                                                                                 args.pCreateInfo.GetPointer(),
                                                                                 args.pCreateInfo.GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pprivate_data_slot_name = "pPrivateDataSlot_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_PRIVATE_DATA_SLOT));
    AddKnownVariables("VkPrivateDataSlot", pprivate_data_slot_name, args.pPrivateDataSlot.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pprivate_data_slot_name,
                         args.pPrivateDataSlot.GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreatePrivateDataSlot(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pprivate_data_slot_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreatePrivateDataSlot);
}

void VulkanCppConsumer::Process_vkDestroyPrivateDataSlot(
    const ApiCallInfo&                          call_info,
    args::DestroyPrivateDataSlot&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkDestroyPrivateDataSlot(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.privateDataSlot).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot);
}

void VulkanCppConsumer::Process_vkGetDeviceBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    args::GetDeviceBufferMemoryRequirements&    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDeviceBufferMemoryRequirements(stream_pinfo,
                                                                               args.pInfo.GetPointer(),
                                                                               args.pInfo.GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string pmemory_requirements_name = "NULL";
    if (!args.pMemoryRequirements.IsNull()) {
        pmemory_requirements_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkMemoryRequirements2 %s = {};\n", pmemory_requirements_name.c_str());
        pmemory_requirements_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetDeviceBufferMemoryRequirements(%s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str(),
            pmemory_requirements_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements);
}

void VulkanCppConsumer::Process_vkGetDeviceImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    args::GetDeviceImageMemoryRequirements&     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDeviceImageMemoryRequirements(stream_pinfo,
                                                                              args.pInfo.GetPointer(),
                                                                              args.pInfo.GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string pmemory_requirements_name = "NULL";
    if (!args.pMemoryRequirements.IsNull()) {
        pmemory_requirements_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkMemoryRequirements2 %s = {};\n", pmemory_requirements_name.c_str());
        pmemory_requirements_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetDeviceImageMemoryRequirements(%s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str(),
            pmemory_requirements_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements);
}

void VulkanCppConsumer::Process_vkGetDeviceImageSparseMemoryRequirements(
    const ApiCallInfo&                          call_info,
    args::GetDeviceImageSparseMemoryRequirements& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDeviceImageMemoryRequirements(stream_pinfo,
                                                                              args.pInfo.GetPointer(),
                                                                              args.pInfo.GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string psparse_memory_requirement_count_name = "NULL";
    if (!args.pSparseMemoryRequirementCount.IsNull()) {
        psparse_memory_requirement_count_name = "pSparseMemoryRequirementCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", psparse_memory_requirement_count_name.c_str(), util::ToString(*args.pSparseMemoryRequirementCount.GetPointer()).c_str());
        psparse_memory_requirement_count_name.insert(0, "&");
    }
    std::string psparse_memory_requirements_name = "NULL";
    if (!args.pSparseMemoryRequirements.IsNull()) {
        const uint32_t* in_psparse_memory_requirement_count = args.pSparseMemoryRequirementCount.GetPointer();
        psparse_memory_requirements_name = "pSparseMemoryRequirements_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkSparseImageMemoryRequirements2 %s[%d] = {};\n", psparse_memory_requirements_name.c_str(), *in_psparse_memory_requirement_count);
    }
    fprintf(file,
            "\t\tvkGetDeviceImageSparseMemoryRequirements(%s, &%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str(),
            psparse_memory_requirement_count_name.c_str(),
            psparse_memory_requirements_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceToolProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceToolProperties&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string ptool_count_name = "NULL";
    if (!args.pToolCount.IsNull()) {
        ptool_count_name = "pToolCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", ptool_count_name.c_str(), util::ToString(*args.pToolCount.GetPointer()).c_str());
        ptool_count_name.insert(0, "&");
    }
    std::string ptool_properties_name = "NULL";
    if (!args.pToolProperties.IsNull()) {
        const uint32_t* in_ptool_count = args.pToolCount.GetPointer();
        ptool_properties_name = "pToolProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPhysicalDeviceToolProperties %s[%d] = {};\n", ptool_properties_name.c_str(), *in_ptool_count);
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkGetPhysicalDeviceToolProperties(%s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            ptool_count_name.c_str(),
            ptool_properties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties);
}

void VulkanCppConsumer::Process_vkGetPrivateData(
    const ApiCallInfo&                          call_info,
    args::GetPrivateData&                       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pdata_name = "NULL";
    if (!args.pData.IsNull()) {
        pdata_name = "pData_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint64_t %s = %s;\n", pdata_name.c_str(), util::ToString(*args.pData.GetPointer()).c_str());
        pdata_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetPrivateData(%s, %s, %" PRIu64 "UL, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            util::ToString<VkObjectType>(args.objectType).c_str(),
            args.objectHandle,
            this->GetHandle(args.privateDataSlot).c_str(),
            pdata_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPrivateData);
}

void VulkanCppConsumer::Process_vkQueueSubmit2(
    const ApiCallInfo&                          call_info,
    args::QueueSubmit2&                         args)
{
    Generate_vkQueueSubmit2(args);
    Post_APICall(format::ApiCallId::ApiCall_vkQueueSubmit2);
}

void VulkanCppConsumer::Process_vkSetPrivateData(
    const ApiCallInfo&                          call_info,
    args::SetPrivateData&                       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkSetPrivateData(%s, %s, %" PRIu64 "UL, %s, %" PRIu64 "UL), %s);\n",
            this->GetHandle(args.device).c_str(),
            util::ToString<VkObjectType>(args.objectType).c_str(),
            args.objectHandle,
            this->GetHandle(args.privateDataSlot).c_str(),
            args.data,
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSetPrivateData);
}
void VulkanCppConsumer::Process_vkCmdBindDescriptorSets2(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorSets2&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbind_descriptor_sets_info;
    std::string pbind_descriptor_sets_info_struct = GenerateStruct_VkBindDescriptorSetsInfo(stream_pbind_descriptor_sets_info,
                                                                                            args.pBindDescriptorSetsInfo.GetPointer(),
                                                                                            args.pBindDescriptorSetsInfo.GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pbind_descriptor_sets_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdBindDescriptorSets2(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pbind_descriptor_sets_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindDescriptorSets2);
}

void VulkanCppConsumer::Process_vkCmdBindIndexBuffer2(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer2&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdBindIndexBuffer2(%s, %s, %" PRIu64 "UL, %" PRIu64 "UL, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.buffer).c_str(),
            args.offset,
            args.size,
            util::ToString<VkIndexType>(args.indexType).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindIndexBuffer2);
}

void VulkanCppConsumer::Process_vkCmdPushConstants2(
    const ApiCallInfo&                          call_info,
    args::CmdPushConstants2&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_ppush_constants_info;
    std::string ppush_constants_info_struct = GenerateStruct_VkPushConstantsInfo(stream_ppush_constants_info,
                                                                                 args.pPushConstantsInfo.GetPointer(),
                                                                                 args.pPushConstantsInfo.GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_ppush_constants_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdPushConstants2(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            ppush_constants_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPushConstants2);
}

void VulkanCppConsumer::Process_vkCmdPushDescriptorSet(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSet&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdescriptor_writes;
    std::string pdescriptor_writes_array = "NULL";
    PointerPairContainer<decltype(args.pDescriptorWrites.GetPointer()), decltype(args.pDescriptorWrites.GetMetaStructPointer())> pdescriptor_writes_pair{ args.pDescriptorWrites.GetPointer(), args.pDescriptorWrites.GetMetaStructPointer(), args.descriptorWriteCount };
    std::string pdescriptor_writes_names = toStringJoin(pdescriptor_writes_pair.begin(),
                                                        pdescriptor_writes_pair.end(),
                                                        [&](auto pair) {{ return GenerateStruct_VkWriteDescriptorSet(stream_pdescriptor_writes, pair.t1, pair.t2, *this); }},
                                                        ", ");
    if (stream_pdescriptor_writes.str().length() > 0) {
        fprintf(file, "%s", stream_pdescriptor_writes.str().c_str());
        if (args.descriptorWriteCount == 1) {
            pdescriptor_writes_array = "&" + pdescriptor_writes_names;
        } else if (args.descriptorWriteCount > 1) {
            pdescriptor_writes_array = "pDescriptorWrites_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkWriteDescriptorSet %s[] = { %s };\n", pdescriptor_writes_array.c_str(), pdescriptor_writes_names.c_str());
        }
    }
    fprintf(file,
            "\t\tvkCmdPushDescriptorSet(%s, %s, %s, %u, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkPipelineBindPoint>(args.pipelineBindPoint).c_str(),
            this->GetHandle(args.layout).c_str(),
            args.set,
            args.descriptorWriteCount,
            pdescriptor_writes_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPushDescriptorSet);
}

void VulkanCppConsumer::Process_vkCmdPushDescriptorSet2(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSet2&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_ppush_descriptor_set_info;
    std::string ppush_descriptor_set_info_struct = GenerateStruct_VkPushDescriptorSetInfo(stream_ppush_descriptor_set_info,
                                                                                          args.pPushDescriptorSetInfo.GetPointer(),
                                                                                          args.pPushDescriptorSetInfo.GetMetaStructPointer(),
                                                                                          *this);
    fprintf(file, "%s", stream_ppush_descriptor_set_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdPushDescriptorSet2(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            ppush_descriptor_set_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPushDescriptorSet2);
}

void VulkanCppConsumer::Process_vkCmdSetLineStipple(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineStipple&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\tvkCmdSetLineStipple(%s, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.lineStippleFactor,
            args.lineStipplePattern);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLineStipple);
}

void VulkanCppConsumer::Process_vkCmdSetRenderingAttachmentLocations(
    const ApiCallInfo&                          call_info,
    args::CmdSetRenderingAttachmentLocations&   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_plocation_info;
    std::string plocation_info_struct = GenerateStruct_VkRenderingAttachmentLocationInfo(stream_plocation_info,
                                                                                         args.pLocationInfo.GetPointer(),
                                                                                         args.pLocationInfo.GetMetaStructPointer(),
                                                                                         *this);
    fprintf(file, "%s", stream_plocation_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdSetRenderingAttachmentLocations(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            plocation_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRenderingAttachmentLocations);
}

void VulkanCppConsumer::Process_vkCmdSetRenderingInputAttachmentIndices(
    const ApiCallInfo&                          call_info,
    args::CmdSetRenderingInputAttachmentIndices& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinput_attachment_index_info;
    std::string pinput_attachment_index_info_struct = GenerateStruct_VkRenderingInputAttachmentIndexInfo(stream_pinput_attachment_index_info,
                                                                                                         args.pInputAttachmentIndexInfo.GetPointer(),
                                                                                                         args.pInputAttachmentIndexInfo.GetMetaStructPointer(),
                                                                                                         *this);
    fprintf(file, "%s", stream_pinput_attachment_index_info.str().c_str());
    fprintf(file,
            "\t\tvkCmdSetRenderingInputAttachmentIndices(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pinput_attachment_index_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRenderingInputAttachmentIndices);
}

void VulkanCppConsumer::Process_vkCopyImageToImage(
    const ApiCallInfo&                          call_info,
    args::CopyImageToImage&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_image_to_image_info;
    std::string pcopy_image_to_image_info_struct = GenerateStruct_VkCopyImageToImageInfo(stream_pcopy_image_to_image_info,
                                                                                         args.pCopyImageToImageInfo.GetPointer(),
                                                                                         args.pCopyImageToImageInfo.GetMetaStructPointer(),
                                                                                         *this);
    fprintf(file, "%s", stream_pcopy_image_to_image_info.str().c_str());
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCopyImageToImage(%s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcopy_image_to_image_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCopyImageToImage);
}

void VulkanCppConsumer::Process_vkCopyImageToMemory(
    const ApiCallInfo&                          call_info,
    args::CopyImageToMemory&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_image_to_memory_info;
    std::string pcopy_image_to_memory_info_struct = GenerateStruct_VkCopyImageToMemoryInfo(stream_pcopy_image_to_memory_info,
                                                                                           args.pCopyImageToMemoryInfo.GetPointer(),
                                                                                           args.pCopyImageToMemoryInfo.GetMetaStructPointer(),
                                                                                           *this);
    fprintf(file, "%s", stream_pcopy_image_to_memory_info.str().c_str());
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCopyImageToMemory(%s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcopy_image_to_memory_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCopyImageToMemory);
}

void VulkanCppConsumer::Process_vkCopyMemoryToImage(
    const ApiCallInfo&                          call_info,
    args::CopyMemoryToImage&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_memory_to_image_info;
    std::string pcopy_memory_to_image_info_struct = GenerateStruct_VkCopyMemoryToImageInfo(stream_pcopy_memory_to_image_info,
                                                                                           args.pCopyMemoryToImageInfo.GetPointer(),
                                                                                           args.pCopyMemoryToImageInfo.GetMetaStructPointer(),
                                                                                           *this);
    fprintf(file, "%s", stream_pcopy_memory_to_image_info.str().c_str());
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCopyMemoryToImage(%s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcopy_memory_to_image_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCopyMemoryToImage);
}

void VulkanCppConsumer::Process_vkGetDeviceImageSubresourceLayout(
    const ApiCallInfo&                          call_info,
    args::GetDeviceImageSubresourceLayout&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDeviceImageSubresourceInfo(stream_pinfo,
                                                                           args.pInfo.GetPointer(),
                                                                           args.pInfo.GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string playout_name = "NULL";
    if (!args.pLayout.IsNull()) {
        playout_name = "pLayout_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkSubresourceLayout2 %s = {};\n", playout_name.c_str());
        playout_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetDeviceImageSubresourceLayout(%s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str(),
            playout_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceImageSubresourceLayout);
}

void VulkanCppConsumer::Process_vkGetImageSubresourceLayout2(
    const ApiCallInfo&                          call_info,
    args::GetImageSubresourceLayout2&           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psubresource;
    std::string psubresource_struct = GenerateStruct_VkImageSubresource2(stream_psubresource,
                                                                         args.pSubresource.GetPointer(),
                                                                         args.pSubresource.GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "%s", stream_psubresource.str().c_str());
    std::string playout_name = "NULL";
    if (!args.pLayout.IsNull()) {
        playout_name = "pLayout_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkSubresourceLayout2 %s = {};\n", playout_name.c_str());
        playout_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetImageSubresourceLayout2(%s, %s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.image).c_str(),
            psubresource_struct.c_str(),
            playout_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2);
}

void VulkanCppConsumer::Process_vkGetRenderingAreaGranularity(
    const ApiCallInfo&                          call_info,
    args::GetRenderingAreaGranularity&          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_prendering_area_info;
    std::string prendering_area_info_struct = GenerateStruct_VkRenderingAreaInfo(stream_prendering_area_info,
                                                                                 args.pRenderingAreaInfo.GetPointer(),
                                                                                 args.pRenderingAreaInfo.GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_prendering_area_info.str().c_str());
    std::string pgranularity_name = "NULL";
    if (!args.pGranularity.IsNull()) {
        pgranularity_name = "pGranularity_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkExtent2D %s = {};\n", pgranularity_name.c_str());
        pgranularity_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tvkGetRenderingAreaGranularity(%s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            prendering_area_info_struct.c_str(),
            pgranularity_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetRenderingAreaGranularity);
}

void VulkanCppConsumer::Process_vkMapMemory2(
    const ApiCallInfo&                          call_info,
    args::MapMemory2&                           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pmemory_map_info;
    std::string pmemory_map_info_struct = GenerateStruct_VkMemoryMapInfo(stream_pmemory_map_info,
                                                                         args.pMemoryMapInfo.GetPointer(),
                                                                         args.pMemoryMapInfo.GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "%s", stream_pmemory_map_info.str().c_str());
    std::string pp_data_name = "NULL";
    if (!args.ppData.IsNull()) {
        pp_data_name = "ppData_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint8_t* %s = %s;\n", pp_data_name.c_str(), util::ToString(*args.ppData.GetPointer()).c_str());
        pp_data_name.insert(0, "&");
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkMapMemory2(%s, &%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pmemory_map_info_struct.c_str(),
            pp_data_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkMapMemory2);
}

void VulkanCppConsumer::Process_vkTransitionImageLayout(
    const ApiCallInfo&                          call_info,
    args::TransitionImageLayout&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_ptransitions;
    std::string ptransitions_array = "NULL";
    PointerPairContainer<decltype(args.pTransitions.GetPointer()), decltype(args.pTransitions.GetMetaStructPointer())> ptransitions_pair{ args.pTransitions.GetPointer(), args.pTransitions.GetMetaStructPointer(), args.transitionCount };
    std::string ptransitions_names = toStringJoin(ptransitions_pair.begin(),
                                                  ptransitions_pair.end(),
                                                  [&](auto pair) {{ return GenerateStruct_VkHostImageLayoutTransitionInfo(stream_ptransitions, pair.t1, pair.t2, *this); }},
                                                  ", ");
    if (stream_ptransitions.str().length() > 0) {
        fprintf(file, "%s", stream_ptransitions.str().c_str());
        if (args.transitionCount == 1) {
            ptransitions_array = "&" + ptransitions_names;
        } else if (args.transitionCount > 1) {
            ptransitions_array = "pTransitions_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkHostImageLayoutTransitionInfo %s[] = { %s };\n", ptransitions_array.c_str(), ptransitions_names.c_str());
        }
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkTransitionImageLayout(%s, %u, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            args.transitionCount,
            ptransitions_array.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkTransitionImageLayout);
}

void VulkanCppConsumer::Process_vkUnmapMemory2(
    const ApiCallInfo&                          call_info,
    args::UnmapMemory2&                         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pmemory_unmap_info;
    std::string pmemory_unmap_info_struct = GenerateStruct_VkMemoryUnmapInfo(stream_pmemory_unmap_info,
                                                                             args.pMemoryUnmapInfo.GetPointer(),
                                                                             args.pMemoryUnmapInfo.GetMetaStructPointer(),
                                                                             *this);
    fprintf(file, "%s", stream_pmemory_unmap_info.str().c_str());
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkUnmapMemory2(%s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pmemory_unmap_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkUnmapMemory2);
}
void VulkanCppConsumer::Process_vkDestroySurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::DestroySurfaceKHR&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroySurfaceKHR");
    fprintf(file,
            "\t\tloaded_vkDestroySurfaceKHR(%s, %s, %s);\n",
            this->GetHandle(args.instance).c_str(),
            this->GetHandle(args.surface).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySurfaceKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfaceCapabilitiesKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string psurface_capabilities_name = "NULL";
    if (!args.pSurfaceCapabilities.IsNull()) {
        psurface_capabilities_name = "pSurfaceCapabilities_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkSurfaceCapabilitiesKHR %s = {};\n", psurface_capabilities_name.c_str());
        psurface_capabilities_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(%s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            this->GetHandle(args.surface).c_str(),
            psurface_capabilities_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfaceFormatsKHR&   args)
{
    Generate_vkGetPhysicalDeviceSurfaceFormatsKHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfacePresentModesKHR& args)
{
    Generate_vkGetPhysicalDeviceSurfacePresentModesKHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceSurfaceSupportKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfaceSupportKHR&   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string psupported_name = "NULL";
    if (!args.pSupported.IsNull()) {
        psupported_name = "pSupported_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkBool32 %s = %s;\n", psupported_name.c_str(), util::ToString(*args.pSupported.GetPointer()).c_str());
        psupported_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceSurfaceSupportKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfaceSupportKHR(%s, %u, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            args.queueFamilyIndex,
            this->GetHandle(args.surface).c_str(),
            psupported_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR);
}
void VulkanCppConsumer::Process_vkAcquireNextImage2KHR(
    const ApiCallInfo&                          call_info,
    args::AcquireNextImage2KHR&                 args)
{
    Generate_vkAcquireNextImage2KHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkAcquireNextImage2KHR);
}

void VulkanCppConsumer::Process_vkAcquireNextImageKHR(
    const ApiCallInfo&                          call_info,
    args::AcquireNextImageKHR&                  args)
{
    Generate_vkAcquireNextImageKHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkAcquireNextImageKHR);
}

void VulkanCppConsumer::Process_vkCreateSwapchainKHR(
    const ApiCallInfo&                          call_info,
    args::CreateSwapchainKHR&                   args)
{
    Generate_vkCreateSwapchainKHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateSwapchainKHR);
}

void VulkanCppConsumer::Process_vkDestroySwapchainKHR(
    const ApiCallInfo&                          call_info,
    args::DestroySwapchainKHR&                  args)
{
    Generate_vkDestroySwapchainKHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySwapchainKHR);
}

void VulkanCppConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceGroupPresentCapabilitiesKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pdevice_group_present_capabilities_name = "NULL";
    if (!args.pDeviceGroupPresentCapabilities.IsNull()) {
        pdevice_group_present_capabilities_name = "pDeviceGroupPresentCapabilities_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDeviceGroupPresentCapabilitiesKHR %s = {};\n", pdevice_group_present_capabilities_name.c_str());
        pdevice_group_present_capabilities_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetDeviceGroupPresentCapabilitiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDeviceGroupPresentCapabilitiesKHR(%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pdevice_group_present_capabilities_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR);
}

void VulkanCppConsumer::Process_vkGetDeviceGroupSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceGroupSurfacePresentModesKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pmodes_name = "NULL";
    if (!args.pModes.IsNull()) {
        pmodes_name = "pModes_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDeviceGroupPresentModeFlagsKHR %s = %s;\n", pmodes_name.c_str(), util::ToString(*args.pModes.GetPointer()).c_str());
        pmodes_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetDeviceGroupSurfacePresentModesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDeviceGroupSurfacePresentModesKHR(%s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.surface).c_str(),
            pmodes_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDevicePresentRectanglesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDevicePresentRectanglesKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string prect_count_name = "NULL";
    if (!args.pRectCount.IsNull()) {
        prect_count_name = "pRectCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", prect_count_name.c_str(), util::ToString(*args.pRectCount.GetPointer()).c_str());
        prect_count_name.insert(0, "&");
    }
    std::string prects_name = "NULL";
    if (!args.pRects.IsNull()) {
        const uint32_t* in_prect_count = args.pRectCount.GetPointer();
        prects_name = "pRects_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkRect2D %s[%d] = {};\n", prects_name.c_str(), *in_prect_count);
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDevicePresentRectanglesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDevicePresentRectanglesKHR(%s, %s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            this->GetHandle(args.surface).c_str(),
            prect_count_name.c_str(),
            prects_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR);
}

void VulkanCppConsumer::Process_vkGetSwapchainImagesKHR(
    const ApiCallInfo&                          call_info,
    args::GetSwapchainImagesKHR&                args)
{
    Generate_vkGetSwapchainImagesKHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR);
}

void VulkanCppConsumer::Process_vkQueuePresentKHR(
    const ApiCallInfo&                          call_info,
    args::QueuePresentKHR&                      args)
{
    Generate_vkQueuePresentKHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkQueuePresentKHR);
}
void VulkanCppConsumer::Process_vkCreateDisplayModeKHR(
    const ApiCallInfo&                          call_info,
    args::CreateDisplayModeKHR&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkDisplayModeCreateInfoKHR(stream_pcreate_info,
                                                                                args.pCreateInfo.GetPointer(),
                                                                                args.pCreateInfo.GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pmode_name = "pMode_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DISPLAY_MODE_KHR));
    AddKnownVariables("VkDisplayModeKHR", pmode_name, args.pMode.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pmode_name,
                         args.pMode.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateDisplayModeKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateDisplayModeKHR(%s, %s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            this->GetHandle(args.display).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pmode_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDisplayModeKHR);
}

void VulkanCppConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateDisplayPlaneSurfaceKHR&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkDisplaySurfaceCreateInfoKHR(stream_pcreate_info,
                                                                                   args.pCreateInfo.GetPointer(),
                                                                                   args.pCreateInfo.GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psurface_name = "pSurface_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", psurface_name, args.pSurface.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(psurface_name,
                         args.pSurface.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateDisplayPlaneSurfaceKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateDisplayPlaneSurfaceKHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.instance).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psurface_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR);
}

void VulkanCppConsumer::Process_vkGetDisplayModePropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetDisplayModePropertiesKHR&          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pproperty_count_name = "NULL";
    if (!args.pPropertyCount.IsNull()) {
        pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pproperty_count_name.c_str(), util::ToString(*args.pPropertyCount.GetPointer()).c_str());
        pproperty_count_name.insert(0, "&");
    }
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        const uint32_t* in_pproperty_count = args.pPropertyCount.GetPointer();
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDisplayModePropertiesKHR %s[%d] = {};\n", pproperties_name.c_str(), *in_pproperty_count);
    }
    pfn_loader_.AddMethodName("vkGetDisplayModePropertiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDisplayModePropertiesKHR(%s, %s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            this->GetHandle(args.display).c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR);
}

void VulkanCppConsumer::Process_vkGetDisplayPlaneCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetDisplayPlaneCapabilitiesKHR&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcapabilities_name = "NULL";
    if (!args.pCapabilities.IsNull()) {
        pcapabilities_name = "pCapabilities_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDisplayPlaneCapabilitiesKHR %s = {};\n", pcapabilities_name.c_str());
        pcapabilities_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetDisplayPlaneCapabilitiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDisplayPlaneCapabilitiesKHR(%s, %s, %u, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            this->GetHandle(args.mode).c_str(),
            args.planeIndex,
            pcapabilities_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR);
}

void VulkanCppConsumer::Process_vkGetDisplayPlaneSupportedDisplaysKHR(
    const ApiCallInfo&                          call_info,
    args::GetDisplayPlaneSupportedDisplaysKHR&  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pdisplay_count_name = "NULL";
    if (!args.pDisplayCount.IsNull()) {
        pdisplay_count_name = "pDisplayCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pdisplay_count_name.c_str(), util::ToString(*args.pDisplayCount.GetPointer()).c_str());
        pdisplay_count_name.insert(0, "&");
    }
    std::string pdisplays_name = "pDisplays_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DISPLAY_KHR));
    AddKnownVariables("VkDisplayKHR", pdisplays_name, args.pDisplays.GetPointer(), *args.pDisplayCount.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pdisplays_name,
                         args.pDisplays.GetPointer(), *args.pDisplayCount.GetPointer());
    }
    pfn_loader_.AddMethodName("vkGetDisplayPlaneSupportedDisplaysKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDisplayPlaneSupportedDisplaysKHR(%s, %u, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            args.planeIndex,
            pdisplay_count_name.c_str(),
            pdisplays_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceDisplayPlanePropertiesKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pproperty_count_name = "NULL";
    if (!args.pPropertyCount.IsNull()) {
        pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pproperty_count_name.c_str(), util::ToString(*args.pPropertyCount.GetPointer()).c_str());
        pproperty_count_name.insert(0, "&");
    }
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        const uint32_t* in_pproperty_count = args.pPropertyCount.GetPointer();
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDisplayPlanePropertiesKHR %s[%d] = {};\n", pproperties_name.c_str(), *in_pproperty_count);
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(%s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceDisplayPropertiesKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pproperty_count_name = "NULL";
    if (!args.pPropertyCount.IsNull()) {
        pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pproperty_count_name.c_str(), util::ToString(*args.pPropertyCount.GetPointer()).c_str());
        pproperty_count_name.insert(0, "&");
    }
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        const uint32_t* in_pproperty_count = args.pPropertyCount.GetPointer();
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDisplayPropertiesKHR %s[%d] = {};\n", pproperties_name.c_str(), *in_pproperty_count);
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceDisplayPropertiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceDisplayPropertiesKHR(%s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR);
}
void VulkanCppConsumer::Process_vkCreateSharedSwapchainsKHR(
    const ApiCallInfo&                          call_info,
    args::CreateSharedSwapchainsKHR&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_infos;
    std::string pcreate_infos_array = "NULL";
    PointerPairContainer<decltype(args.pCreateInfos.GetPointer()), decltype(args.pCreateInfos.GetMetaStructPointer())> pcreate_infos_pair{ args.pCreateInfos.GetPointer(), args.pCreateInfos.GetMetaStructPointer(), args.swapchainCount };
    std::string pcreate_infos_names = toStringJoin(pcreate_infos_pair.begin(),
                                                   pcreate_infos_pair.end(),
                                                   [&](auto pair) {{ return GenerateStruct_VkSwapchainCreateInfoKHR(stream_pcreate_infos, pair.t1, pair.t2, *this); }},
                                                   ", ");
    if (stream_pcreate_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pcreate_infos.str().c_str());
        if (args.swapchainCount == 1) {
            pcreate_infos_array = "&" + pcreate_infos_names;
        } else if (args.swapchainCount > 1) {
            pcreate_infos_array = "pCreateInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkSwapchainCreateInfoKHR %s[] = { %s };\n", pcreate_infos_array.c_str(), pcreate_infos_names.c_str());
        }
    }
    std::string pswapchains_name = "pSwapchains_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SWAPCHAIN_KHR));
    AddKnownVariables("VkSwapchainKHR", pswapchains_name, args.pSwapchains.GetPointer(), args.swapchainCount);
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pswapchains_name,
                         args.pSwapchains.GetPointer(), args.swapchainCount);
    }
    pfn_loader_.AddMethodName("vkCreateSharedSwapchainsKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateSharedSwapchainsKHR(%s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            args.swapchainCount,
            pcreate_infos_array.c_str(),
            "nullptr",
            pswapchains_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR);
}
void VulkanCppConsumer::Process_vkCreateXlibSurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateXlibSurfaceKHR&                 args)
{
    Generate_vkCreateXlibSurfaceKHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceXlibPresentationSupportKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string dpy_name = "args.dpy_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tvoid* %s;\n", dpy_name.c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceXlibPresentationSupportKHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceXlibPresentationSupportKHR(%s, %u, %s, %" PRIu64 ");\n",
            this->GetHandle(args.physicalDevice).c_str(),
            args.queueFamilyIndex,
            dpy_name.c_str(),
            util::platform::SizeTtoUint64(args.visualID));
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR);
}
void VulkanCppConsumer::Process_vkCreateXcbSurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateXcbSurfaceKHR&                  args)
{
    Generate_vkCreateXcbSurfaceKHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceXcbPresentationSupportKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file, "// TODO: Support vkGetPhysicalDeviceXcbPresentationSupportKHR function.\n");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR);
}
void VulkanCppConsumer::Process_vkCreateWaylandSurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateWaylandSurfaceKHR&              args)
{
    Generate_vkCreateWaylandSurfaceKHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceWaylandPresentationSupportKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string display_name = "args.display_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tvoid* %s;\n", display_name.c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceWaylandPresentationSupportKHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceWaylandPresentationSupportKHR(%s, %u, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            args.queueFamilyIndex,
            display_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR);
}
void VulkanCppConsumer::Process_vkCreateAndroidSurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateAndroidSurfaceKHR&              args)
{
    Generate_vkCreateAndroidSurfaceKHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR);
}
void VulkanCppConsumer::Process_vkCreateWin32SurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateWin32SurfaceKHR&                args)
{
    Generate_vkCreateWin32SurfaceKHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceWin32PresentationSupportKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceWin32PresentationSupportKHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceWin32PresentationSupportKHR(%s, %u);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            args.queueFamilyIndex);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR);
}
void VulkanCppConsumer::Process_vkBindVideoSessionMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::BindVideoSessionMemoryKHR&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbind_session_memory_infos;
    std::string pbind_session_memory_infos_array = "NULL";
    PointerPairContainer<decltype(args.pBindSessionMemoryInfos.GetPointer()), decltype(args.pBindSessionMemoryInfos.GetMetaStructPointer())> pbind_session_memory_infos_pair{ args.pBindSessionMemoryInfos.GetPointer(), args.pBindSessionMemoryInfos.GetMetaStructPointer(), args.bindSessionMemoryInfoCount };
    std::string pbind_session_memory_infos_names = toStringJoin(pbind_session_memory_infos_pair.begin(),
                                                                pbind_session_memory_infos_pair.end(),
                                                                [&](auto pair) {{ return GenerateStruct_VkBindVideoSessionMemoryInfoKHR(stream_pbind_session_memory_infos, pair.t1, pair.t2, *this); }},
                                                                ", ");
    if (stream_pbind_session_memory_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pbind_session_memory_infos.str().c_str());
        if (args.bindSessionMemoryInfoCount == 1) {
            pbind_session_memory_infos_array = "&" + pbind_session_memory_infos_names;
        } else if (args.bindSessionMemoryInfoCount > 1) {
            pbind_session_memory_infos_array = "pBindSessionMemoryInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBindVideoSessionMemoryInfoKHR %s[] = { %s };\n", pbind_session_memory_infos_array.c_str(), pbind_session_memory_infos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkBindVideoSessionMemoryKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkBindVideoSessionMemoryKHR(%s, %s, %u, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.videoSession).c_str(),
            args.bindSessionMemoryInfoCount,
            pbind_session_memory_infos_array.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR);
}

void VulkanCppConsumer::Process_vkCmdBeginVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBeginVideoCodingKHR&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbegin_info;
    std::string pbegin_info_struct = GenerateStruct_VkVideoBeginCodingInfoKHR(stream_pbegin_info,
                                                                              args.pBeginInfo.GetPointer(),
                                                                              args.pBeginInfo.GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "%s", stream_pbegin_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdBeginVideoCodingKHR");
    fprintf(file,
            "\t\tloaded_vkCmdBeginVideoCodingKHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pbegin_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR);
}

void VulkanCppConsumer::Process_vkCmdControlVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdControlVideoCodingKHR&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcoding_control_info;
    std::string pcoding_control_info_struct = GenerateStruct_VkVideoCodingControlInfoKHR(stream_pcoding_control_info,
                                                                                         args.pCodingControlInfo.GetPointer(),
                                                                                         args.pCodingControlInfo.GetMetaStructPointer(),
                                                                                         *this);
    fprintf(file, "%s", stream_pcoding_control_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdControlVideoCodingKHR");
    fprintf(file,
            "\t\tloaded_vkCmdControlVideoCodingKHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pcoding_control_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR);
}

void VulkanCppConsumer::Process_vkCmdEndVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdEndVideoCodingKHR&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pend_coding_info;
    std::string pend_coding_info_struct = GenerateStruct_VkVideoEndCodingInfoKHR(stream_pend_coding_info,
                                                                                 args.pEndCodingInfo.GetPointer(),
                                                                                 args.pEndCodingInfo.GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_pend_coding_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdEndVideoCodingKHR");
    fprintf(file,
            "\t\tloaded_vkCmdEndVideoCodingKHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pend_coding_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR);
}

void VulkanCppConsumer::Process_vkCreateVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    args::CreateVideoSessionKHR&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkVideoSessionCreateInfoKHR(stream_pcreate_info,
                                                                                 args.pCreateInfo.GetPointer(),
                                                                                 args.pCreateInfo.GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pvideo_session_name = "pVideoSession_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_VIDEO_SESSION_KHR));
    AddKnownVariables("VkVideoSessionKHR", pvideo_session_name, args.pVideoSession.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pvideo_session_name,
                         args.pVideoSession.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateVideoSessionKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateVideoSessionKHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pvideo_session_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateVideoSessionKHR);
}

void VulkanCppConsumer::Process_vkCreateVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    args::CreateVideoSessionParametersKHR&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkVideoSessionParametersCreateInfoKHR(stream_pcreate_info,
                                                                                           args.pCreateInfo.GetPointer(),
                                                                                           args.pCreateInfo.GetMetaStructPointer(),
                                                                                           *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pvideo_session_parameters_name = "pVideoSessionParameters_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_VIDEO_SESSION_PARAMETERS_KHR));
    AddKnownVariables("VkVideoSessionParametersKHR", pvideo_session_parameters_name, args.pVideoSessionParameters.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pvideo_session_parameters_name,
                         args.pVideoSessionParameters.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateVideoSessionParametersKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateVideoSessionParametersKHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pvideo_session_parameters_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR);
}

void VulkanCppConsumer::Process_vkDestroyVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyVideoSessionKHR&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyVideoSessionKHR");
    fprintf(file,
            "\t\tloaded_vkDestroyVideoSessionKHR(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.videoSession).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR);
}

void VulkanCppConsumer::Process_vkDestroyVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyVideoSessionParametersKHR&     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyVideoSessionParametersKHR");
    fprintf(file,
            "\t\tloaded_vkDestroyVideoSessionParametersKHR(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.videoSessionParameters).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceVideoCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceVideoCapabilitiesKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pvideo_profile;
    std::string pvideo_profile_struct = GenerateStruct_VkVideoProfileInfoKHR(stream_pvideo_profile,
                                                                             args.pVideoProfile.GetPointer(),
                                                                             args.pVideoProfile.GetMetaStructPointer(),
                                                                             *this);
    fprintf(file, "%s", stream_pvideo_profile.str().c_str());
    std::string pcapabilities_name = "NULL";
    if (!args.pCapabilities.IsNull()) {
        pcapabilities_name = "pCapabilities_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkVideoCapabilitiesKHR %s = {};\n", pcapabilities_name.c_str());
        pcapabilities_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceVideoCapabilitiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceVideoCapabilitiesKHR(%s, &%s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pvideo_profile_struct.c_str(),
            pcapabilities_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceVideoFormatPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceVideoFormatPropertiesKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pvideo_format_info;
    std::string pvideo_format_info_struct = GenerateStruct_VkPhysicalDeviceVideoFormatInfoKHR(stream_pvideo_format_info,
                                                                                              args.pVideoFormatInfo.GetPointer(),
                                                                                              args.pVideoFormatInfo.GetMetaStructPointer(),
                                                                                              *this);
    fprintf(file, "%s", stream_pvideo_format_info.str().c_str());
    std::string pvideo_format_property_count_name = "NULL";
    if (!args.pVideoFormatPropertyCount.IsNull()) {
        pvideo_format_property_count_name = "pVideoFormatPropertyCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pvideo_format_property_count_name.c_str(), util::ToString(*args.pVideoFormatPropertyCount.GetPointer()).c_str());
        pvideo_format_property_count_name.insert(0, "&");
    }
    std::string pvideo_format_properties_name = "NULL";
    if (!args.pVideoFormatProperties.IsNull()) {
        const uint32_t* in_pvideo_format_property_count = args.pVideoFormatPropertyCount.GetPointer();
        pvideo_format_properties_name = "pVideoFormatProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkVideoFormatPropertiesKHR %s[%d] = {};\n", pvideo_format_properties_name.c_str(), *in_pvideo_format_property_count);
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceVideoFormatPropertiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceVideoFormatPropertiesKHR(%s, &%s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pvideo_format_info_struct.c_str(),
            pvideo_format_property_count_name.c_str(),
            pvideo_format_properties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR);
}

void VulkanCppConsumer::Process_vkGetVideoSessionMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    args::GetVideoSessionMemoryRequirementsKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pmemory_requirements_count_name = "NULL";
    if (!args.pMemoryRequirementsCount.IsNull()) {
        pmemory_requirements_count_name = "pMemoryRequirementsCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pmemory_requirements_count_name.c_str(), util::ToString(*args.pMemoryRequirementsCount.GetPointer()).c_str());
        pmemory_requirements_count_name.insert(0, "&");
    }
    std::string pmemory_requirements_name = "NULL";
    if (!args.pMemoryRequirements.IsNull()) {
        const uint32_t* in_pmemory_requirements_count = args.pMemoryRequirementsCount.GetPointer();
        pmemory_requirements_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkVideoSessionMemoryRequirementsKHR %s[%d] = {};\n", pmemory_requirements_name.c_str(), *in_pmemory_requirements_count);
    }
    pfn_loader_.AddMethodName("vkGetVideoSessionMemoryRequirementsKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetVideoSessionMemoryRequirementsKHR(%s, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.videoSession).c_str(),
            pmemory_requirements_count_name.c_str(),
            pmemory_requirements_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR);
}

void VulkanCppConsumer::Process_vkUpdateVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    args::UpdateVideoSessionParametersKHR&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pupdate_info;
    std::string pupdate_info_struct = GenerateStruct_VkVideoSessionParametersUpdateInfoKHR(stream_pupdate_info,
                                                                                           args.pUpdateInfo.GetPointer(),
                                                                                           args.pUpdateInfo.GetMetaStructPointer(),
                                                                                           *this);
    fprintf(file, "%s", stream_pupdate_info.str().c_str());
    pfn_loader_.AddMethodName("vkUpdateVideoSessionParametersKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkUpdateVideoSessionParametersKHR(%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.videoSessionParameters).c_str(),
            pupdate_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR);
}
void VulkanCppConsumer::Process_vkCmdDecodeVideoKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDecodeVideoKHR&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdecode_info;
    std::string pdecode_info_struct = GenerateStruct_VkVideoDecodeInfoKHR(stream_pdecode_info,
                                                                          args.pDecodeInfo.GetPointer(),
                                                                          args.pDecodeInfo.GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pdecode_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdDecodeVideoKHR");
    fprintf(file,
            "\t\tloaded_vkCmdDecodeVideoKHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pdecode_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR);
}
void VulkanCppConsumer::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderingKHR&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_prendering_info;
    std::string prendering_info_struct = GenerateStruct_VkRenderingInfo(stream_prendering_info,
                                                                        args.pRenderingInfo.GetPointer(),
                                                                        args.pRenderingInfo.GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_prendering_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdBeginRenderingKHR");
    fprintf(file,
            "\t\tloaded_vkCmdBeginRenderingKHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            prendering_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR);
}

void VulkanCppConsumer::Process_vkCmdEndRenderingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdEndRenderingKHR&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdEndRenderingKHR");
    fprintf(file,
            "\t\tloaded_vkCmdEndRenderingKHR(%s);\n",
            this->GetHandle(args.commandBuffer).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRenderingKHR);
}
void VulkanCppConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceFeatures2KHR&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pfeatures_name = "NULL";
    if (!args.pFeatures.IsNull()) {
        pfeatures_name = "pFeatures_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPhysicalDeviceFeatures2 %s = {};\n", pfeatures_name.c_str());
        pfeatures_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceFeatures2KHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceFeatures2KHR(%s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pfeatures_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceFormatProperties2KHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pformat_properties_name = "NULL";
    if (!args.pFormatProperties.IsNull()) {
        pformat_properties_name = "pFormatProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkFormatProperties2 %s = {};\n", pformat_properties_name.c_str());
        pformat_properties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceFormatProperties2KHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceFormatProperties2KHR(%s, %s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            util::ToString<VkFormat>(args.format).c_str(),
            pformat_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceImageFormatProperties2KHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pimage_format_info;
    std::string pimage_format_info_struct = GenerateStruct_VkPhysicalDeviceImageFormatInfo2(stream_pimage_format_info,
                                                                                            args.pImageFormatInfo.GetPointer(),
                                                                                            args.pImageFormatInfo.GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pimage_format_info.str().c_str());
    std::string pimage_format_properties_name = "NULL";
    if (!args.pImageFormatProperties.IsNull()) {
        pimage_format_properties_name = "pImageFormatProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkImageFormatProperties2 %s = {};\n", pimage_format_properties_name.c_str());
        pimage_format_properties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceImageFormatProperties2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceImageFormatProperties2KHR(%s, &%s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pimage_format_info_struct.c_str(),
            pimage_format_properties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceMemoryProperties2KHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pmemory_properties_name = "NULL";
    if (!args.pMemoryProperties.IsNull()) {
        pmemory_properties_name = "pMemoryProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPhysicalDeviceMemoryProperties2 %s = {};\n", pmemory_properties_name.c_str());
        pmemory_properties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceMemoryProperties2KHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceMemoryProperties2KHR(%s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pmemory_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceProperties2KHR&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPhysicalDeviceProperties2 %s = {};\n", pproperties_name.c_str());
        pproperties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceProperties2KHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceProperties2KHR(%s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pproperties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceQueueFamilyProperties2KHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pqueue_family_property_count_name = "NULL";
    if (!args.pQueueFamilyPropertyCount.IsNull()) {
        pqueue_family_property_count_name = "pQueueFamilyPropertyCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pqueue_family_property_count_name.c_str(), util::ToString(*args.pQueueFamilyPropertyCount.GetPointer()).c_str());
        pqueue_family_property_count_name.insert(0, "&");
    }
    std::string pqueue_family_properties_name = "NULL";
    if (!args.pQueueFamilyProperties.IsNull()) {
        const uint32_t* in_pqueue_family_property_count = args.pQueueFamilyPropertyCount.GetPointer();
        pqueue_family_properties_name = "pQueueFamilyProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkQueueFamilyProperties2 %s[%d] = {};\n", pqueue_family_properties_name.c_str(), *in_pqueue_family_property_count);
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceQueueFamilyProperties2KHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceQueueFamilyProperties2KHR(%s, %s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pqueue_family_property_count_name.c_str(),
            pqueue_family_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSparseImageFormatProperties2KHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pformat_info;
    std::string pformat_info_struct = GenerateStruct_VkPhysicalDeviceSparseImageFormatInfo2(stream_pformat_info,
                                                                                            args.pFormatInfo.GetPointer(),
                                                                                            args.pFormatInfo.GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pformat_info.str().c_str());
    std::string pproperty_count_name = "NULL";
    if (!args.pPropertyCount.IsNull()) {
        pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pproperty_count_name.c_str(), util::ToString(*args.pPropertyCount.GetPointer()).c_str());
        pproperty_count_name.insert(0, "&");
    }
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        const uint32_t* in_pproperty_count = args.pPropertyCount.GetPointer();
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkSparseImageFormatProperties2 %s[%d] = {};\n", pproperties_name.c_str(), *in_pproperty_count);
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceSparseImageFormatProperties2KHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(%s, &%s, %s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pformat_info_struct.c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR);
}
void VulkanCppConsumer::Process_vkCmdDispatchBaseKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchBaseKHR&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDispatchBaseKHR");
    fprintf(file,
            "\t\tloaded_vkCmdDispatchBaseKHR(%s, %u, %u, %u, %u, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.baseGroupX,
            args.baseGroupY,
            args.baseGroupZ,
            args.groupCountX,
            args.groupCountY,
            args.groupCountZ);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR);
}

void VulkanCppConsumer::Process_vkCmdSetDeviceMaskKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetDeviceMaskKHR&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetDeviceMaskKHR");
    fprintf(file,
            "\t\tloaded_vkCmdSetDeviceMaskKHR(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.deviceMask);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR);
}

void VulkanCppConsumer::Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceGroupPeerMemoryFeaturesKHR&  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string ppeer_memory_features_name = "NULL";
    if (!args.pPeerMemoryFeatures.IsNull()) {
        ppeer_memory_features_name = "pPeerMemoryFeatures_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPeerMemoryFeatureFlags %s = %s;\n", ppeer_memory_features_name.c_str(), util::ToString(*args.pPeerMemoryFeatures.GetPointer()).c_str());
        ppeer_memory_features_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetDeviceGroupPeerMemoryFeaturesKHR");
    fprintf(file,
            "\t\tloaded_vkGetDeviceGroupPeerMemoryFeaturesKHR(%s, %u, %u, %u, %s);\n",
            this->GetHandle(args.device).c_str(),
            args.heapIndex,
            args.localDeviceIndex,
            args.remoteDeviceIndex,
            ppeer_memory_features_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR);
}
void VulkanCppConsumer::Process_vkTrimCommandPoolKHR(
    const ApiCallInfo&                          call_info,
    args::TrimCommandPoolKHR&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkTrimCommandPoolKHR");
    fprintf(file,
            "\t\tloaded_vkTrimCommandPoolKHR(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.commandPool).c_str(),
            util::ToString<VkCommandPoolTrimFlags>(args.flags).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkTrimCommandPoolKHR);
}
void VulkanCppConsumer::Process_vkEnumeratePhysicalDeviceGroupsKHR(
    const ApiCallInfo&                          call_info,
    args::EnumeratePhysicalDeviceGroupsKHR&     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pphysical_device_group_count_name = "NULL";
    if (!args.pPhysicalDeviceGroupCount.IsNull()) {
        pphysical_device_group_count_name = "pPhysicalDeviceGroupCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pphysical_device_group_count_name.c_str(), util::ToString(*args.pPhysicalDeviceGroupCount.GetPointer()).c_str());
        pphysical_device_group_count_name.insert(0, "&");
    }
    std::string pphysical_device_group_properties_name = "NULL";
    if (!args.pPhysicalDeviceGroupProperties.IsNull()) {
        const uint32_t* in_pphysical_device_group_count = args.pPhysicalDeviceGroupCount.GetPointer();
        pphysical_device_group_properties_name = "pPhysicalDeviceGroupProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPhysicalDeviceGroupProperties %s[%d] = {};\n", pphysical_device_group_properties_name.c_str(), *in_pphysical_device_group_count);
    }
    pfn_loader_.AddMethodName("vkEnumeratePhysicalDeviceGroupsKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkEnumeratePhysicalDeviceGroupsKHR(%s, %s, %s), %s);\n",
            this->GetHandle(args.instance).c_str(),
            pphysical_device_group_count_name.c_str(),
            pphysical_device_group_properties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR);
}
void VulkanCppConsumer::Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalBufferPropertiesKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pexternal_buffer_info;
    std::string pexternal_buffer_info_struct = GenerateStruct_VkPhysicalDeviceExternalBufferInfo(stream_pexternal_buffer_info,
                                                                                                 args.pExternalBufferInfo.GetPointer(),
                                                                                                 args.pExternalBufferInfo.GetMetaStructPointer(),
                                                                                                 *this);
    fprintf(file, "%s", stream_pexternal_buffer_info.str().c_str());
    std::string pexternal_buffer_properties_name = "NULL";
    if (!args.pExternalBufferProperties.IsNull()) {
        pexternal_buffer_properties_name = "pExternalBufferProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkExternalBufferProperties %s = {};\n", pexternal_buffer_properties_name.c_str());
        pexternal_buffer_properties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceExternalBufferPropertiesKHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceExternalBufferPropertiesKHR(%s, &%s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pexternal_buffer_info_struct.c_str(),
            pexternal_buffer_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR);
}
void VulkanCppConsumer::Process_vkGetMemoryWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    args::GetMemoryWin32HandleKHR&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pget_win32_handle_info;
    std::string pget_win32_handle_info_struct = GenerateStruct_VkMemoryGetWin32HandleInfoKHR(stream_pget_win32_handle_info,
                                                                                             args.pGetWin32HandleInfo.GetPointer(),
                                                                                             args.pGetWin32HandleInfo.GetMetaStructPointer(),
                                                                                             *this);
    fprintf(file, "%s", stream_pget_win32_handle_info.str().c_str());
    std::string phandle_name = "NULL";
    if (!args.pHandle.IsNull()) {
        phandle_name = "pHandle_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint8_t* %s = %s;\n", phandle_name.c_str(), util::ToString(*args.pHandle.GetPointer()).c_str());
        phandle_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetMemoryWin32HandleKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetMemoryWin32HandleKHR(%s, &%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pget_win32_handle_info_struct.c_str(),
            phandle_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR);
}

void VulkanCppConsumer::Process_vkGetMemoryWin32HandlePropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetMemoryWin32HandlePropertiesKHR&    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string handle_name = "args.handle_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tvoid* %s;\n", handle_name.c_str());
    std::string pmemory_win32_handle_properties_name = "NULL";
    if (!args.pMemoryWin32HandleProperties.IsNull()) {
        pmemory_win32_handle_properties_name = "pMemoryWin32HandleProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkMemoryWin32HandlePropertiesKHR %s = {};\n", pmemory_win32_handle_properties_name.c_str());
        pmemory_win32_handle_properties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetMemoryWin32HandlePropertiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetMemoryWin32HandlePropertiesKHR(%s, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            util::ToString<VkExternalMemoryHandleTypeFlagBits>(args.handleType).c_str(),
            handle_name.c_str(),
            pmemory_win32_handle_properties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR);
}
void VulkanCppConsumer::Process_vkGetMemoryFdKHR(
    const ApiCallInfo&                          call_info,
    args::GetMemoryFdKHR&                       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pget_fd_info;
    std::string pget_fd_info_struct = GenerateStruct_VkMemoryGetFdInfoKHR(stream_pget_fd_info,
                                                                          args.pGetFdInfo.GetPointer(),
                                                                          args.pGetFdInfo.GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pget_fd_info.str().c_str());
    std::string pfd_name = "NULL";
    if (!args.pFd.IsNull()) {
        pfd_name = "pFd_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tint %s = %s;\n", pfd_name.c_str(), util::ToString(*args.pFd.GetPointer()).c_str());
        pfd_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetMemoryFdKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetMemoryFdKHR(%s, &%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pget_fd_info_struct.c_str(),
            pfd_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryFdKHR);
}

void VulkanCppConsumer::Process_vkGetMemoryFdPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetMemoryFdPropertiesKHR&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pmemory_fd_properties_name = "NULL";
    if (!args.pMemoryFdProperties.IsNull()) {
        pmemory_fd_properties_name = "pMemoryFdProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkMemoryFdPropertiesKHR %s = {};\n", pmemory_fd_properties_name.c_str());
        pmemory_fd_properties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetMemoryFdPropertiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetMemoryFdPropertiesKHR(%s, %s, %d, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            util::ToString<VkExternalMemoryHandleTypeFlagBits>(args.handleType).c_str(),
            args.fd,
            pmemory_fd_properties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR);
}
void VulkanCppConsumer::Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalSemaphorePropertiesKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pexternal_semaphore_info;
    std::string pexternal_semaphore_info_struct = GenerateStruct_VkPhysicalDeviceExternalSemaphoreInfo(stream_pexternal_semaphore_info,
                                                                                                       args.pExternalSemaphoreInfo.GetPointer(),
                                                                                                       args.pExternalSemaphoreInfo.GetMetaStructPointer(),
                                                                                                       *this);
    fprintf(file, "%s", stream_pexternal_semaphore_info.str().c_str());
    std::string pexternal_semaphore_properties_name = "NULL";
    if (!args.pExternalSemaphoreProperties.IsNull()) {
        pexternal_semaphore_properties_name = "pExternalSemaphoreProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkExternalSemaphoreProperties %s = {};\n", pexternal_semaphore_properties_name.c_str());
        pexternal_semaphore_properties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceExternalSemaphorePropertiesKHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(%s, &%s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pexternal_semaphore_info_struct.c_str(),
            pexternal_semaphore_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR);
}
void VulkanCppConsumer::Process_vkGetSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    args::GetSemaphoreWin32HandleKHR&           args)
{
    Generate_vkGetSemaphoreWin32HandleKHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR);
}

void VulkanCppConsumer::Process_vkImportSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    args::ImportSemaphoreWin32HandleKHR&        args)
{
    Generate_vkImportSemaphoreWin32HandleKHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR);
}
void VulkanCppConsumer::Process_vkGetSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    args::GetSemaphoreFdKHR&                    args)
{
    Generate_vkGetSemaphoreFdKHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR);
}

void VulkanCppConsumer::Process_vkImportSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    args::ImportSemaphoreFdKHR&                 args)
{
    Generate_vkImportSemaphoreFdKHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR);
}
void VulkanCppConsumer::Process_vkCmdPushDescriptorSetKHR(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSetKHR&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdescriptor_writes;
    std::string pdescriptor_writes_array = "NULL";
    PointerPairContainer<decltype(args.pDescriptorWrites.GetPointer()), decltype(args.pDescriptorWrites.GetMetaStructPointer())> pdescriptor_writes_pair{ args.pDescriptorWrites.GetPointer(), args.pDescriptorWrites.GetMetaStructPointer(), args.descriptorWriteCount };
    std::string pdescriptor_writes_names = toStringJoin(pdescriptor_writes_pair.begin(),
                                                        pdescriptor_writes_pair.end(),
                                                        [&](auto pair) {{ return GenerateStruct_VkWriteDescriptorSet(stream_pdescriptor_writes, pair.t1, pair.t2, *this); }},
                                                        ", ");
    if (stream_pdescriptor_writes.str().length() > 0) {
        fprintf(file, "%s", stream_pdescriptor_writes.str().c_str());
        if (args.descriptorWriteCount == 1) {
            pdescriptor_writes_array = "&" + pdescriptor_writes_names;
        } else if (args.descriptorWriteCount > 1) {
            pdescriptor_writes_array = "pDescriptorWrites_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkWriteDescriptorSet %s[] = { %s };\n", pdescriptor_writes_array.c_str(), pdescriptor_writes_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdPushDescriptorSetKHR");
    fprintf(file,
            "\t\tloaded_vkCmdPushDescriptorSetKHR(%s, %s, %s, %u, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkPipelineBindPoint>(args.pipelineBindPoint).c_str(),
            this->GetHandle(args.layout).c_str(),
            args.set,
            args.descriptorWriteCount,
            pdescriptor_writes_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR);
}
void VulkanCppConsumer::Process_vkCreateDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    args::CreateDescriptorUpdateTemplateKHR&    args)
{
    Generate_vkCreateDescriptorUpdateTemplateKHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR);
}

void VulkanCppConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyDescriptorUpdateTemplateKHR&   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyDescriptorUpdateTemplateKHR");
    fprintf(file,
            "\t\tloaded_vkDestroyDescriptorUpdateTemplateKHR(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.descriptorUpdateTemplate).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR);
}
void VulkanCppConsumer::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderPass2KHR&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_prender_pass_begin;
    std::string prender_pass_begin_struct = GenerateStruct_VkRenderPassBeginInfo(stream_prender_pass_begin,
                                                                                 args.pRenderPassBegin.GetPointer(),
                                                                                 args.pRenderPassBegin.GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_prender_pass_begin.str().c_str());
    std::stringstream stream_psubpass_begin_info;
    std::string psubpass_begin_info_struct = GenerateStruct_VkSubpassBeginInfo(stream_psubpass_begin_info,
                                                                               args.pSubpassBeginInfo.GetPointer(),
                                                                               args.pSubpassBeginInfo.GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_psubpass_begin_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdBeginRenderPass2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdBeginRenderPass2KHR(%s, &%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            prender_pass_begin_struct.c_str(),
            psubpass_begin_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR);
}

void VulkanCppConsumer::Process_vkCmdEndRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdEndRenderPass2KHR&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psubpass_end_info;
    std::string psubpass_end_info_struct = GenerateStruct_VkSubpassEndInfo(stream_psubpass_end_info,
                                                                           args.pSubpassEndInfo.GetPointer(),
                                                                           args.pSubpassEndInfo.GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_psubpass_end_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdEndRenderPass2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdEndRenderPass2KHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            psubpass_end_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR);
}

void VulkanCppConsumer::Process_vkCmdNextSubpass2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdNextSubpass2KHR&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psubpass_begin_info;
    std::string psubpass_begin_info_struct = GenerateStruct_VkSubpassBeginInfo(stream_psubpass_begin_info,
                                                                               args.pSubpassBeginInfo.GetPointer(),
                                                                               args.pSubpassBeginInfo.GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_psubpass_begin_info.str().c_str());
    std::stringstream stream_psubpass_end_info;
    std::string psubpass_end_info_struct = GenerateStruct_VkSubpassEndInfo(stream_psubpass_end_info,
                                                                           args.pSubpassEndInfo.GetPointer(),
                                                                           args.pSubpassEndInfo.GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_psubpass_end_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdNextSubpass2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdNextSubpass2KHR(%s, &%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            psubpass_begin_info_struct.c_str(),
            psubpass_end_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR);
}

void VulkanCppConsumer::Process_vkCreateRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    args::CreateRenderPass2KHR&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkRenderPassCreateInfo2(stream_pcreate_info,
                                                                             args.pCreateInfo.GetPointer(),
                                                                             args.pCreateInfo.GetMetaStructPointer(),
                                                                             *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string prender_pass_name = "pRenderPass_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_RENDER_PASS));
    AddKnownVariables("VkRenderPass", prender_pass_name, args.pRenderPass.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(prender_pass_name,
                         args.pRenderPass.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateRenderPass2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateRenderPass2KHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            prender_pass_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateRenderPass2KHR);
}
void VulkanCppConsumer::Process_vkGetSwapchainStatusKHR(
    const ApiCallInfo&                          call_info,
    args::GetSwapchainStatusKHR&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkGetSwapchainStatusKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetSwapchainStatusKHR(%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.swapchain).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR);
}
void VulkanCppConsumer::Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalFencePropertiesKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pexternal_fence_info;
    std::string pexternal_fence_info_struct = GenerateStruct_VkPhysicalDeviceExternalFenceInfo(stream_pexternal_fence_info,
                                                                                               args.pExternalFenceInfo.GetPointer(),
                                                                                               args.pExternalFenceInfo.GetMetaStructPointer(),
                                                                                               *this);
    fprintf(file, "%s", stream_pexternal_fence_info.str().c_str());
    std::string pexternal_fence_properties_name = "NULL";
    if (!args.pExternalFenceProperties.IsNull()) {
        pexternal_fence_properties_name = "pExternalFenceProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkExternalFenceProperties %s = {};\n", pexternal_fence_properties_name.c_str());
        pexternal_fence_properties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceExternalFencePropertiesKHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceExternalFencePropertiesKHR(%s, &%s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pexternal_fence_info_struct.c_str(),
            pexternal_fence_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR);
}
void VulkanCppConsumer::Process_vkGetFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    args::GetFenceWin32HandleKHR&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pget_win32_handle_info;
    std::string pget_win32_handle_info_struct = GenerateStruct_VkFenceGetWin32HandleInfoKHR(stream_pget_win32_handle_info,
                                                                                            args.pGetWin32HandleInfo.GetPointer(),
                                                                                            args.pGetWin32HandleInfo.GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pget_win32_handle_info.str().c_str());
    std::string phandle_name = "NULL";
    if (!args.pHandle.IsNull()) {
        phandle_name = "pHandle_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint8_t* %s = %s;\n", phandle_name.c_str(), util::ToString(*args.pHandle.GetPointer()).c_str());
        phandle_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetFenceWin32HandleKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetFenceWin32HandleKHR(%s, &%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pget_win32_handle_info_struct.c_str(),
            phandle_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR);
}

void VulkanCppConsumer::Process_vkImportFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    args::ImportFenceWin32HandleKHR&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pimport_fence_win32_handle_info;
    std::string pimport_fence_win32_handle_info_struct = GenerateStruct_VkImportFenceWin32HandleInfoKHR(stream_pimport_fence_win32_handle_info,
                                                                                                        args.pImportFenceWin32HandleInfo.GetPointer(),
                                                                                                        args.pImportFenceWin32HandleInfo.GetMetaStructPointer(),
                                                                                                        *this);
    fprintf(file, "%s", stream_pimport_fence_win32_handle_info.str().c_str());
    pfn_loader_.AddMethodName("vkImportFenceWin32HandleKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkImportFenceWin32HandleKHR(%s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pimport_fence_win32_handle_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR);
}
void VulkanCppConsumer::Process_vkGetFenceFdKHR(
    const ApiCallInfo&                          call_info,
    args::GetFenceFdKHR&                        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pget_fd_info;
    std::string pget_fd_info_struct = GenerateStruct_VkFenceGetFdInfoKHR(stream_pget_fd_info,
                                                                         args.pGetFdInfo.GetPointer(),
                                                                         args.pGetFdInfo.GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "%s", stream_pget_fd_info.str().c_str());
    std::string pfd_name = "NULL";
    if (!args.pFd.IsNull()) {
        pfd_name = "pFd_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tint %s = %s;\n", pfd_name.c_str(), util::ToString(*args.pFd.GetPointer()).c_str());
        pfd_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetFenceFdKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetFenceFdKHR(%s, &%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pget_fd_info_struct.c_str(),
            pfd_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetFenceFdKHR);
}

void VulkanCppConsumer::Process_vkImportFenceFdKHR(
    const ApiCallInfo&                          call_info,
    args::ImportFenceFdKHR&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pimport_fence_fd_info;
    std::string pimport_fence_fd_info_struct = GenerateStruct_VkImportFenceFdInfoKHR(stream_pimport_fence_fd_info,
                                                                                     args.pImportFenceFdInfo.GetPointer(),
                                                                                     args.pImportFenceFdInfo.GetMetaStructPointer(),
                                                                                     *this);
    fprintf(file, "%s", stream_pimport_fence_fd_info.str().c_str());
    pfn_loader_.AddMethodName("vkImportFenceFdKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkImportFenceFdKHR(%s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pimport_fence_fd_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkImportFenceFdKHR);
}
void VulkanCppConsumer::Process_vkAcquireProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    args::AcquireProfilingLockKHR&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkAcquireProfilingLockInfoKHR(stream_pinfo,
                                                                            args.pInfo.GetPointer(),
                                                                            args.pInfo.GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkAcquireProfilingLockKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkAcquireProfilingLockKHR(%s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR);
}

void VulkanCppConsumer::Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
    const ApiCallInfo&                          call_info,
    args::EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcounter_count_name = "NULL";
    if (!args.pCounterCount.IsNull()) {
        pcounter_count_name = "pCounterCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pcounter_count_name.c_str(), util::ToString(*args.pCounterCount.GetPointer()).c_str());
        pcounter_count_name.insert(0, "&");
    }
    std::string pcounters_name = "NULL";
    if (!args.pCounters.IsNull()) {
        const uint32_t* in_pcounter_count = args.pCounterCount.GetPointer();
        pcounters_name = "pCounters_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPerformanceCounterKHR %s[%d] = {};\n", pcounters_name.c_str(), *in_pcounter_count);
    }
    std::string pcounter_descriptions_name = "NULL";
    if (!args.pCounterDescriptions.IsNull()) {
        const uint32_t* in_pcounter_count = args.pCounterCount.GetPointer();
        pcounter_descriptions_name = "pCounterDescriptions_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPerformanceCounterDescriptionKHR %s[%d] = {};\n", pcounter_descriptions_name.c_str(), *in_pcounter_count);
    }
    pfn_loader_.AddMethodName("vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(%s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            args.queueFamilyIndex,
            pcounter_count_name.c_str(),
            pcounters_name.c_str(),
            pcounter_descriptions_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pperformance_query_create_info;
    std::string pperformance_query_create_info_struct = GenerateStruct_VkQueryPoolPerformanceCreateInfoKHR(stream_pperformance_query_create_info,
                                                                                                           args.pPerformanceQueryCreateInfo.GetPointer(),
                                                                                                           args.pPerformanceQueryCreateInfo.GetMetaStructPointer(),
                                                                                                           *this);
    fprintf(file, "%s", stream_pperformance_query_create_info.str().c_str());
    std::string pnum_passes_name = "NULL";
    if (!args.pNumPasses.IsNull()) {
        pnum_passes_name = "pNumPasses_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pnum_passes_name.c_str(), util::ToString(*args.pNumPasses.GetPointer()).c_str());
        pnum_passes_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(%s, &%s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pperformance_query_create_info_struct.c_str(),
            pnum_passes_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR);
}

void VulkanCppConsumer::Process_vkReleaseProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    args::ReleaseProfilingLockKHR&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkReleaseProfilingLockKHR");
    fprintf(file,
            "\t\tloaded_vkReleaseProfilingLockKHR(%s);\n",
            this->GetHandle(args.device).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR);
}
void VulkanCppConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfaceCapabilities2KHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psurface_info;
    std::string psurface_info_struct = GenerateStruct_VkPhysicalDeviceSurfaceInfo2KHR(stream_psurface_info,
                                                                                      args.pSurfaceInfo.GetPointer(),
                                                                                      args.pSurfaceInfo.GetMetaStructPointer(),
                                                                                      *this);
    fprintf(file, "%s", stream_psurface_info.str().c_str());
    std::string psurface_capabilities_name = "NULL";
    if (!args.pSurfaceCapabilities.IsNull()) {
        psurface_capabilities_name = "pSurfaceCapabilities_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkSurfaceCapabilities2KHR %s = {};\n", psurface_capabilities_name.c_str());
        psurface_capabilities_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceSurfaceCapabilities2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfaceCapabilities2KHR(%s, &%s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            psurface_info_struct.c_str(),
            psurface_capabilities_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfaceFormats2KHR&  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psurface_info;
    std::string psurface_info_struct = GenerateStruct_VkPhysicalDeviceSurfaceInfo2KHR(stream_psurface_info,
                                                                                      args.pSurfaceInfo.GetPointer(),
                                                                                      args.pSurfaceInfo.GetMetaStructPointer(),
                                                                                      *this);
    fprintf(file, "%s", stream_psurface_info.str().c_str());
    std::string psurface_format_count_name = "NULL";
    if (!args.pSurfaceFormatCount.IsNull()) {
        psurface_format_count_name = "pSurfaceFormatCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", psurface_format_count_name.c_str(), util::ToString(*args.pSurfaceFormatCount.GetPointer()).c_str());
        psurface_format_count_name.insert(0, "&");
    }
    std::string psurface_formats_name = "NULL";
    if (!args.pSurfaceFormats.IsNull()) {
        const uint32_t* in_psurface_format_count = args.pSurfaceFormatCount.GetPointer();
        psurface_formats_name = "pSurfaceFormats_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkSurfaceFormat2KHR %s[%d] = {};\n", psurface_formats_name.c_str(), *in_psurface_format_count);
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceSurfaceFormats2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfaceFormats2KHR(%s, &%s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            psurface_info_struct.c_str(),
            psurface_format_count_name.c_str(),
            psurface_formats_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR);
}
void VulkanCppConsumer::Process_vkGetDisplayModeProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetDisplayModeProperties2KHR&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pproperty_count_name = "NULL";
    if (!args.pPropertyCount.IsNull()) {
        pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pproperty_count_name.c_str(), util::ToString(*args.pPropertyCount.GetPointer()).c_str());
        pproperty_count_name.insert(0, "&");
    }
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        const uint32_t* in_pproperty_count = args.pPropertyCount.GetPointer();
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDisplayModeProperties2KHR %s[%d] = {};\n", pproperties_name.c_str(), *in_pproperty_count);
    }
    pfn_loader_.AddMethodName("vkGetDisplayModeProperties2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDisplayModeProperties2KHR(%s, %s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            this->GetHandle(args.display).c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR);
}

void VulkanCppConsumer::Process_vkGetDisplayPlaneCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    args::GetDisplayPlaneCapabilities2KHR&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdisplay_plane_info;
    std::string pdisplay_plane_info_struct = GenerateStruct_VkDisplayPlaneInfo2KHR(stream_pdisplay_plane_info,
                                                                                   args.pDisplayPlaneInfo.GetPointer(),
                                                                                   args.pDisplayPlaneInfo.GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "%s", stream_pdisplay_plane_info.str().c_str());
    std::string pcapabilities_name = "NULL";
    if (!args.pCapabilities.IsNull()) {
        pcapabilities_name = "pCapabilities_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDisplayPlaneCapabilities2KHR %s = {};\n", pcapabilities_name.c_str());
        pcapabilities_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetDisplayPlaneCapabilities2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDisplayPlaneCapabilities2KHR(%s, &%s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pdisplay_plane_info_struct.c_str(),
            pcapabilities_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceDisplayPlaneProperties2KHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pproperty_count_name = "NULL";
    if (!args.pPropertyCount.IsNull()) {
        pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pproperty_count_name.c_str(), util::ToString(*args.pPropertyCount.GetPointer()).c_str());
        pproperty_count_name.insert(0, "&");
    }
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        const uint32_t* in_pproperty_count = args.pPropertyCount.GetPointer();
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDisplayPlaneProperties2KHR %s[%d] = {};\n", pproperties_name.c_str(), *in_pproperty_count);
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(%s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceDisplayProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceDisplayProperties2KHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pproperty_count_name = "NULL";
    if (!args.pPropertyCount.IsNull()) {
        pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pproperty_count_name.c_str(), util::ToString(*args.pPropertyCount.GetPointer()).c_str());
        pproperty_count_name.insert(0, "&");
    }
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        const uint32_t* in_pproperty_count = args.pPropertyCount.GetPointer();
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDisplayProperties2KHR %s[%d] = {};\n", pproperties_name.c_str(), *in_pproperty_count);
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceDisplayProperties2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceDisplayProperties2KHR(%s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR);
}
void VulkanCppConsumer::Process_vkGetBufferMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    args::GetBufferMemoryRequirements2KHR&      args)
{
    Generate_vkGetBufferMemoryRequirements2KHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR);
}

void VulkanCppConsumer::Process_vkGetImageMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    args::GetImageMemoryRequirements2KHR&       args)
{
    Generate_vkGetImageMemoryRequirements2KHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR);
}

void VulkanCppConsumer::Process_vkGetImageSparseMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    args::GetImageSparseMemoryRequirements2KHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkImageSparseMemoryRequirementsInfo2(stream_pinfo,
                                                                                   args.pInfo.GetPointer(),
                                                                                   args.pInfo.GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string psparse_memory_requirement_count_name = "NULL";
    if (!args.pSparseMemoryRequirementCount.IsNull()) {
        psparse_memory_requirement_count_name = "pSparseMemoryRequirementCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", psparse_memory_requirement_count_name.c_str(), util::ToString(*args.pSparseMemoryRequirementCount.GetPointer()).c_str());
        psparse_memory_requirement_count_name.insert(0, "&");
    }
    std::string psparse_memory_requirements_name = "NULL";
    if (!args.pSparseMemoryRequirements.IsNull()) {
        const uint32_t* in_psparse_memory_requirement_count = args.pSparseMemoryRequirementCount.GetPointer();
        psparse_memory_requirements_name = "pSparseMemoryRequirements_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkSparseImageMemoryRequirements2 %s[%d] = {};\n", psparse_memory_requirements_name.c_str(), *in_psparse_memory_requirement_count);
    }
    pfn_loader_.AddMethodName("vkGetImageSparseMemoryRequirements2KHR");
    fprintf(file,
            "\t\tloaded_vkGetImageSparseMemoryRequirements2KHR(%s, &%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str(),
            psparse_memory_requirement_count_name.c_str(),
            psparse_memory_requirements_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR);
}
void VulkanCppConsumer::Process_vkCreateSamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    args::CreateSamplerYcbcrConversionKHR&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkSamplerYcbcrConversionCreateInfo(stream_pcreate_info,
                                                                                        args.pCreateInfo.GetPointer(),
                                                                                        args.pCreateInfo.GetMetaStructPointer(),
                                                                                        *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pycbcr_conversion_name = "pYcbcrConversion_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION));
    AddKnownVariables("VkSamplerYcbcrConversion", pycbcr_conversion_name, args.pYcbcrConversion.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pycbcr_conversion_name,
                         args.pYcbcrConversion.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateSamplerYcbcrConversionKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateSamplerYcbcrConversionKHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pycbcr_conversion_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR);
}

void VulkanCppConsumer::Process_vkDestroySamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    args::DestroySamplerYcbcrConversionKHR&     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroySamplerYcbcrConversionKHR");
    fprintf(file,
            "\t\tloaded_vkDestroySamplerYcbcrConversionKHR(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.ycbcrConversion).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR);
}
void VulkanCppConsumer::Process_vkBindBufferMemory2KHR(
    const ApiCallInfo&                          call_info,
    args::BindBufferMemory2KHR&                 args)
{
    Intercept_vkBindBufferMemory2KHR(args);
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbind_infos;
    std::string pbind_infos_array = "NULL";
    PointerPairContainer<decltype(args.pBindInfos.GetPointer()), decltype(args.pBindInfos.GetMetaStructPointer())> pbind_infos_pair{ args.pBindInfos.GetPointer(), args.pBindInfos.GetMetaStructPointer(), args.bindInfoCount };
    std::string pbind_infos_names = toStringJoin(pbind_infos_pair.begin(),
                                                 pbind_infos_pair.end(),
                                                 [&](auto pair) {{ return GenerateStruct_VkBindBufferMemoryInfo(stream_pbind_infos, pair.t1, pair.t2, *this); }},
                                                 ", ");
    if (stream_pbind_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pbind_infos.str().c_str());
        if (args.bindInfoCount == 1) {
            pbind_infos_array = "&" + pbind_infos_names;
        } else if (args.bindInfoCount > 1) {
            pbind_infos_array = "pBindInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBindBufferMemoryInfo %s[] = { %s };\n", pbind_infos_array.c_str(), pbind_infos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkBindBufferMemory2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkBindBufferMemory2KHR(%s, %u, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            args.bindInfoCount,
            pbind_infos_array.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindBufferMemory2KHR);
}

void VulkanCppConsumer::Process_vkBindImageMemory2KHR(
    const ApiCallInfo&                          call_info,
    args::BindImageMemory2KHR&                  args)
{
    Intercept_vkBindImageMemory2KHR(args);
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbind_infos;
    std::string pbind_infos_array = "NULL";
    PointerPairContainer<decltype(args.pBindInfos.GetPointer()), decltype(args.pBindInfos.GetMetaStructPointer())> pbind_infos_pair{ args.pBindInfos.GetPointer(), args.pBindInfos.GetMetaStructPointer(), args.bindInfoCount };
    std::string pbind_infos_names = toStringJoin(pbind_infos_pair.begin(),
                                                 pbind_infos_pair.end(),
                                                 [&](auto pair) {{ return GenerateStruct_VkBindImageMemoryInfo(stream_pbind_infos, pair.t1, pair.t2, *this); }},
                                                 ", ");
    if (stream_pbind_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pbind_infos.str().c_str());
        if (args.bindInfoCount == 1) {
            pbind_infos_array = "&" + pbind_infos_names;
        } else if (args.bindInfoCount > 1) {
            pbind_infos_array = "pBindInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBindImageMemoryInfo %s[] = { %s };\n", pbind_infos_array.c_str(), pbind_infos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkBindImageMemory2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkBindImageMemory2KHR(%s, %u, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            args.bindInfoCount,
            pbind_infos_array.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindImageMemory2KHR);
}
void VulkanCppConsumer::Process_vkGetDescriptorSetLayoutSupportKHR(
    const ApiCallInfo&                          call_info,
    args::GetDescriptorSetLayoutSupportKHR&     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkDescriptorSetLayoutCreateInfo(stream_pcreate_info,
                                                                                     args.pCreateInfo.GetPointer(),
                                                                                     args.pCreateInfo.GetMetaStructPointer(),
                                                                                     *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psupport_name = "NULL";
    if (!args.pSupport.IsNull()) {
        psupport_name = "pSupport_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDescriptorSetLayoutSupport %s = {};\n", psupport_name.c_str());
        psupport_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetDescriptorSetLayoutSupportKHR");
    fprintf(file,
            "\t\tloaded_vkGetDescriptorSetLayoutSupportKHR(%s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            psupport_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR);
}
void VulkanCppConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCountKHR&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawIndexedIndirectCountKHR");
    fprintf(file,
            "\t\tloaded_vkCmdDrawIndexedIndirectCountKHR(%s, %s, %" PRIu64 "UL, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.buffer).c_str(),
            args.offset,
            this->GetHandle(args.countBuffer).c_str(),
            args.countBufferOffset,
            args.maxDrawCount,
            args.stride);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR);
}

void VulkanCppConsumer::Process_vkCmdDrawIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCountKHR&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawIndirectCountKHR");
    fprintf(file,
            "\t\tloaded_vkCmdDrawIndirectCountKHR(%s, %s, %" PRIu64 "UL, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.buffer).c_str(),
            args.offset,
            this->GetHandle(args.countBuffer).c_str(),
            args.countBufferOffset,
            args.maxDrawCount,
            args.stride);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR);
}
void VulkanCppConsumer::Process_vkGetSemaphoreCounterValueKHR(
    const ApiCallInfo&                          call_info,
    args::GetSemaphoreCounterValueKHR&          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pvalue_name = "NULL";
    if (!args.pValue.IsNull()) {
        pvalue_name = "pValue_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint64_t %s = %s;\n", pvalue_name.c_str(), util::ToString(*args.pValue.GetPointer()).c_str());
        pvalue_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetSemaphoreCounterValueKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetSemaphoreCounterValueKHR(%s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.semaphore).c_str(),
            pvalue_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR);
}

void VulkanCppConsumer::Process_vkSignalSemaphoreKHR(
    const ApiCallInfo&                          call_info,
    args::SignalSemaphoreKHR&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psignal_info;
    std::string psignal_info_struct = GenerateStruct_VkSemaphoreSignalInfo(stream_psignal_info,
                                                                           args.pSignalInfo.GetPointer(),
                                                                           args.pSignalInfo.GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_psignal_info.str().c_str());
    pfn_loader_.AddMethodName("vkSignalSemaphoreKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkSignalSemaphoreKHR(%s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            psignal_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSignalSemaphoreKHR);
}

void VulkanCppConsumer::Process_vkWaitSemaphoresKHR(
    const ApiCallInfo&                          call_info,
    args::WaitSemaphoresKHR&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pwait_info;
    std::string pwait_info_struct = GenerateStruct_VkSemaphoreWaitInfo(stream_pwait_info,
                                                                       args.pWaitInfo.GetPointer(),
                                                                       args.pWaitInfo.GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "%s", stream_pwait_info.str().c_str());
    pfn_loader_.AddMethodName("vkWaitSemaphoresKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkWaitSemaphoresKHR(%s, &%s, %" PRIu64 "UL), %s);\n",
            this->GetHandle(args.device).c_str(),
            pwait_info_struct.c_str(),
            args.timeout,
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkWaitSemaphoresKHR);
}
void VulkanCppConsumer::Process_vkCmdSetFragmentShadingRateKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetFragmentShadingRateKHR&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pfragment_size;
    std::string pfragment_size_struct = GenerateStruct_VkExtent2D(stream_pfragment_size,
                                                                  args.pFragmentSize.GetPointer(),
                                                                  args.pFragmentSize.GetMetaStructPointer(),
                                                                  *this);
    fprintf(file, "%s", stream_pfragment_size.str().c_str());
    std::string combiner_ops_array = "combiner_ops_array_" + std::to_string(this->GetNextId());
    std::string combiner_ops_values = toStringJoin(args.combinerOps.GetPointer(),
                                                   args.combinerOps.GetPointer() + 2,
                                                   [&](const VkFragmentShadingRateCombinerOpKHR current) { return util::ToString(current); },
                                                   ", ");
    fprintf(file, "\t\tVkFragmentShadingRateCombinerOpKHR %s[] = { %s };\n", combiner_ops_array.c_str(), combiner_ops_values.c_str());
    pfn_loader_.AddMethodName("vkCmdSetFragmentShadingRateKHR");
    fprintf(file,
            "\t\tloaded_vkCmdSetFragmentShadingRateKHR(%s, &%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pfragment_size_struct.c_str(),
            combiner_ops_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceFragmentShadingRatesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceFragmentShadingRatesKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pfragment_shading_rate_count_name = "NULL";
    if (!args.pFragmentShadingRateCount.IsNull()) {
        pfragment_shading_rate_count_name = "pFragmentShadingRateCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pfragment_shading_rate_count_name.c_str(), util::ToString(*args.pFragmentShadingRateCount.GetPointer()).c_str());
        pfragment_shading_rate_count_name.insert(0, "&");
    }
    std::string pfragment_shading_rates_name = "NULL";
    if (!args.pFragmentShadingRates.IsNull()) {
        const uint32_t* in_pfragment_shading_rate_count = args.pFragmentShadingRateCount.GetPointer();
        pfragment_shading_rates_name = "pFragmentShadingRates_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPhysicalDeviceFragmentShadingRateKHR %s[%d] = {};\n", pfragment_shading_rates_name.c_str(), *in_pfragment_shading_rate_count);
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceFragmentShadingRatesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceFragmentShadingRatesKHR(%s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pfragment_shading_rate_count_name.c_str(),
            pfragment_shading_rates_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR);
}
void VulkanCppConsumer::Process_vkCmdSetRenderingAttachmentLocationsKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetRenderingAttachmentLocationsKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_plocation_info;
    std::string plocation_info_struct = GenerateStruct_VkRenderingAttachmentLocationInfo(stream_plocation_info,
                                                                                         args.pLocationInfo.GetPointer(),
                                                                                         args.pLocationInfo.GetMetaStructPointer(),
                                                                                         *this);
    fprintf(file, "%s", stream_plocation_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdSetRenderingAttachmentLocationsKHR");
    fprintf(file,
            "\t\tloaded_vkCmdSetRenderingAttachmentLocationsKHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            plocation_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRenderingAttachmentLocationsKHR);
}

void VulkanCppConsumer::Process_vkCmdSetRenderingInputAttachmentIndicesKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetRenderingInputAttachmentIndicesKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinput_attachment_index_info;
    std::string pinput_attachment_index_info_struct = GenerateStruct_VkRenderingInputAttachmentIndexInfo(stream_pinput_attachment_index_info,
                                                                                                         args.pInputAttachmentIndexInfo.GetPointer(),
                                                                                                         args.pInputAttachmentIndexInfo.GetMetaStructPointer(),
                                                                                                         *this);
    fprintf(file, "%s", stream_pinput_attachment_index_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdSetRenderingInputAttachmentIndicesKHR");
    fprintf(file,
            "\t\tloaded_vkCmdSetRenderingInputAttachmentIndicesKHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pinput_attachment_index_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRenderingInputAttachmentIndicesKHR);
}
void VulkanCppConsumer::Process_vkWaitForPresentKHR(
    const ApiCallInfo&                          call_info,
    args::WaitForPresentKHR&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkWaitForPresentKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkWaitForPresentKHR(%s, %s, %" PRIu64 "UL, %" PRIu64 "UL), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.swapchain).c_str(),
            args.presentId,
            args.timeout,
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkWaitForPresentKHR);
}
void VulkanCppConsumer::Process_vkGetBufferDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    args::GetBufferDeviceAddressKHR&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkBufferDeviceAddressInfo(stream_pinfo,
                                                                        args.pInfo.GetPointer(),
                                                                        args.pInfo.GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkGetBufferDeviceAddressKHR");
    fprintf(file,
            "\t\tloaded_vkGetBufferDeviceAddressKHR(%s, &%s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR);
}

void VulkanCppConsumer::Process_vkGetBufferOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    args::GetBufferOpaqueCaptureAddressKHR&     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkBufferDeviceAddressInfo(stream_pinfo,
                                                                        args.pInfo.GetPointer(),
                                                                        args.pInfo.GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkGetBufferOpaqueCaptureAddressKHR");
    fprintf(file,
            "\t\tloaded_vkGetBufferOpaqueCaptureAddressKHR(%s, &%s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR);
}

void VulkanCppConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceMemoryOpaqueCaptureAddressKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDeviceMemoryOpaqueCaptureAddressInfo(stream_pinfo,
                                                                                     args.pInfo.GetPointer(),
                                                                                     args.pInfo.GetMetaStructPointer(),
                                                                                     *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkGetDeviceMemoryOpaqueCaptureAddressKHR");
    fprintf(file,
            "\t\tloaded_vkGetDeviceMemoryOpaqueCaptureAddressKHR(%s, &%s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR);
}
void VulkanCppConsumer::Process_vkCreateDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    args::CreateDeferredOperationKHR&           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pdeferred_operation_name = "pDeferredOperation_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR));
    AddKnownVariables("VkDeferredOperationKHR", pdeferred_operation_name, args.pDeferredOperation.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pdeferred_operation_name,
                         args.pDeferredOperation.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateDeferredOperationKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateDeferredOperationKHR(%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            "nullptr",
            pdeferred_operation_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR);
}

void VulkanCppConsumer::Process_vkDeferredOperationJoinKHR(
    const ApiCallInfo&                          call_info,
    args::DeferredOperationJoinKHR&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDeferredOperationJoinKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkDeferredOperationJoinKHR(%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.operation).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR);
}

void VulkanCppConsumer::Process_vkDestroyDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyDeferredOperationKHR&          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyDeferredOperationKHR");
    fprintf(file,
            "\t\tloaded_vkDestroyDeferredOperationKHR(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.operation).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR);
}

void VulkanCppConsumer::Process_vkGetDeferredOperationMaxConcurrencyKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeferredOperationMaxConcurrencyKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkGetDeferredOperationMaxConcurrencyKHR");
    fprintf(file,
            "\t\tloaded_vkGetDeferredOperationMaxConcurrencyKHR(%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.operation).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR);
}

void VulkanCppConsumer::Process_vkGetDeferredOperationResultKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeferredOperationResultKHR&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkGetDeferredOperationResultKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDeferredOperationResultKHR(%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.operation).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR);
}
void VulkanCppConsumer::Process_vkGetPipelineExecutableInternalRepresentationsKHR(
    const ApiCallInfo&                          call_info,
    args::GetPipelineExecutableInternalRepresentationsKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pexecutable_info;
    std::string pexecutable_info_struct = GenerateStruct_VkPipelineExecutableInfoKHR(stream_pexecutable_info,
                                                                                     args.pExecutableInfo.GetPointer(),
                                                                                     args.pExecutableInfo.GetMetaStructPointer(),
                                                                                     *this);
    fprintf(file, "%s", stream_pexecutable_info.str().c_str());
    std::string pinternal_representation_count_name = "NULL";
    if (!args.pInternalRepresentationCount.IsNull()) {
        pinternal_representation_count_name = "pInternalRepresentationCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pinternal_representation_count_name.c_str(), util::ToString(*args.pInternalRepresentationCount.GetPointer()).c_str());
        pinternal_representation_count_name.insert(0, "&");
    }
    std::string pinternal_representations_name = "NULL";
    if (!args.pInternalRepresentations.IsNull()) {
        const uint32_t* in_pinternal_representation_count = args.pInternalRepresentationCount.GetPointer();
        pinternal_representations_name = "pInternalRepresentations_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPipelineExecutableInternalRepresentationKHR %s[%d] = {};\n", pinternal_representations_name.c_str(), *in_pinternal_representation_count);
    }
    pfn_loader_.AddMethodName("vkGetPipelineExecutableInternalRepresentationsKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPipelineExecutableInternalRepresentationsKHR(%s, &%s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pexecutable_info_struct.c_str(),
            pinternal_representation_count_name.c_str(),
            pinternal_representations_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR);
}

void VulkanCppConsumer::Process_vkGetPipelineExecutablePropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPipelineExecutablePropertiesKHR&   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_ppipeline_info;
    std::string ppipeline_info_struct = GenerateStruct_VkPipelineInfoKHR(stream_ppipeline_info,
                                                                         args.pPipelineInfo.GetPointer(),
                                                                         args.pPipelineInfo.GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "%s", stream_ppipeline_info.str().c_str());
    std::string pexecutable_count_name = "NULL";
    if (!args.pExecutableCount.IsNull()) {
        pexecutable_count_name = "pExecutableCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pexecutable_count_name.c_str(), util::ToString(*args.pExecutableCount.GetPointer()).c_str());
        pexecutable_count_name.insert(0, "&");
    }
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        const uint32_t* in_pexecutable_count = args.pExecutableCount.GetPointer();
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPipelineExecutablePropertiesKHR %s[%d] = {};\n", pproperties_name.c_str(), *in_pexecutable_count);
    }
    pfn_loader_.AddMethodName("vkGetPipelineExecutablePropertiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPipelineExecutablePropertiesKHR(%s, &%s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            ppipeline_info_struct.c_str(),
            pexecutable_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR);
}

void VulkanCppConsumer::Process_vkGetPipelineExecutableStatisticsKHR(
    const ApiCallInfo&                          call_info,
    args::GetPipelineExecutableStatisticsKHR&   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pexecutable_info;
    std::string pexecutable_info_struct = GenerateStruct_VkPipelineExecutableInfoKHR(stream_pexecutable_info,
                                                                                     args.pExecutableInfo.GetPointer(),
                                                                                     args.pExecutableInfo.GetMetaStructPointer(),
                                                                                     *this);
    fprintf(file, "%s", stream_pexecutable_info.str().c_str());
    std::string pstatistic_count_name = "NULL";
    if (!args.pStatisticCount.IsNull()) {
        pstatistic_count_name = "pStatisticCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pstatistic_count_name.c_str(), util::ToString(*args.pStatisticCount.GetPointer()).c_str());
        pstatistic_count_name.insert(0, "&");
    }
    std::string pstatistics_name = "NULL";
    if (!args.pStatistics.IsNull()) {
        const uint32_t* in_pstatistic_count = args.pStatisticCount.GetPointer();
        pstatistics_name = "pStatistics_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPipelineExecutableStatisticKHR %s[%d] = {};\n", pstatistics_name.c_str(), *in_pstatistic_count);
    }
    pfn_loader_.AddMethodName("vkGetPipelineExecutableStatisticsKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPipelineExecutableStatisticsKHR(%s, &%s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pexecutable_info_struct.c_str(),
            pstatistic_count_name.c_str(),
            pstatistics_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR);
}
void VulkanCppConsumer::Process_vkMapMemory2KHR(
    const ApiCallInfo&                          call_info,
    args::MapMemory2KHR&                        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pmemory_map_info;
    std::string pmemory_map_info_struct = GenerateStruct_VkMemoryMapInfo(stream_pmemory_map_info,
                                                                         args.pMemoryMapInfo.GetPointer(),
                                                                         args.pMemoryMapInfo.GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "%s", stream_pmemory_map_info.str().c_str());
    std::string pp_data_name = "NULL";
    if (!args.ppData.IsNull()) {
        pp_data_name = "ppData_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint8_t* %s = %s;\n", pp_data_name.c_str(), util::ToString(*args.ppData.GetPointer()).c_str());
        pp_data_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkMapMemory2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkMapMemory2KHR(%s, &%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pmemory_map_info_struct.c_str(),
            pp_data_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkMapMemory2KHR);
}

void VulkanCppConsumer::Process_vkUnmapMemory2KHR(
    const ApiCallInfo&                          call_info,
    args::UnmapMemory2KHR&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pmemory_unmap_info;
    std::string pmemory_unmap_info_struct = GenerateStruct_VkMemoryUnmapInfo(stream_pmemory_unmap_info,
                                                                             args.pMemoryUnmapInfo.GetPointer(),
                                                                             args.pMemoryUnmapInfo.GetMetaStructPointer(),
                                                                             *this);
    fprintf(file, "%s", stream_pmemory_unmap_info.str().c_str());
    pfn_loader_.AddMethodName("vkUnmapMemory2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkUnmapMemory2KHR(%s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pmemory_unmap_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkUnmapMemory2KHR);
}
void VulkanCppConsumer::Process_vkCmdEncodeVideoKHR(
    const ApiCallInfo&                          call_info,
    args::CmdEncodeVideoKHR&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pencode_info;
    std::string pencode_info_struct = GenerateStruct_VkVideoEncodeInfoKHR(stream_pencode_info,
                                                                          args.pEncodeInfo.GetPointer(),
                                                                          args.pEncodeInfo.GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pencode_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdEncodeVideoKHR");
    fprintf(file,
            "\t\tloaded_vkCmdEncodeVideoKHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pencode_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR);
}

void VulkanCppConsumer::Process_vkGetEncodedVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    args::GetEncodedVideoSessionParametersKHR&  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pvideo_session_parameters_info;
    std::string pvideo_session_parameters_info_struct = GenerateStruct_VkVideoEncodeSessionParametersGetInfoKHR(stream_pvideo_session_parameters_info,
                                                                                                                args.pVideoSessionParametersInfo.GetPointer(),
                                                                                                                args.pVideoSessionParametersInfo.GetMetaStructPointer(),
                                                                                                                *this);
    fprintf(file, "%s", stream_pvideo_session_parameters_info.str().c_str());
    std::string pfeedback_info_name = "NULL";
    if (!args.pFeedbackInfo.IsNull()) {
        pfeedback_info_name = "pFeedbackInfo_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkVideoEncodeSessionParametersFeedbackInfoKHR %s = {};\n", pfeedback_info_name.c_str());
        pfeedback_info_name.insert(0, "&");
    }
    std::string pdata_size_name = "NULL";
    if (!args.pDataSize.IsNull()) {
        pdata_size_name = "pDataSize_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tsize_t %s = %s;\n", pdata_size_name.c_str(), util::ToString(*args.pDataSize.GetPointer()).c_str());
        pdata_size_name.insert(0, "&");
    }
    std::string pdata_name = "NULL";
    if (!args.pData.IsNull()) {
        size_t* in_pdata_size = args.pDataSize.GetPointer();
        pdata_name = "pData_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint8_t %s[%" PRIu64 "] = {};\n", pdata_name.c_str(), util::platform::SizeTtoUint64(*in_pdata_size));
    }
    pfn_loader_.AddMethodName("vkGetEncodedVideoSessionParametersKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetEncodedVideoSessionParametersKHR(%s, &%s, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pvideo_session_parameters_info_struct.c_str(),
            pfeedback_info_name.c_str(),
            pdata_size_name.c_str(),
            pdata_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetEncodedVideoSessionParametersKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pquality_level_info;
    std::string pquality_level_info_struct = GenerateStruct_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR(stream_pquality_level_info,
                                                                                                           args.pQualityLevelInfo.GetPointer(),
                                                                                                           args.pQualityLevelInfo.GetMetaStructPointer(),
                                                                                                           *this);
    fprintf(file, "%s", stream_pquality_level_info.str().c_str());
    std::string pquality_level_properties_name = "NULL";
    if (!args.pQualityLevelProperties.IsNull()) {
        pquality_level_properties_name = "pQualityLevelProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkVideoEncodeQualityLevelPropertiesKHR %s = {};\n", pquality_level_properties_name.c_str());
        pquality_level_properties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(%s, &%s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pquality_level_info_struct.c_str(),
            pquality_level_properties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR);
}
void VulkanCppConsumer::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdPipelineBarrier2KHR&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdependency_info;
    std::string pdependency_info_struct = GenerateStruct_VkDependencyInfo(stream_pdependency_info,
                                                                          args.pDependencyInfo.GetPointer(),
                                                                          args.pDependencyInfo.GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pdependency_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdPipelineBarrier2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdPipelineBarrier2KHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pdependency_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR);
}

void VulkanCppConsumer::Process_vkCmdResetEvent2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdResetEvent2KHR&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdResetEvent2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdResetEvent2KHR(%s, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.event).c_str(),
            util::ToString<VkPipelineStageFlags2>(args.stageMask).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResetEvent2KHR);
}

void VulkanCppConsumer::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetEvent2KHR&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdependency_info;
    std::string pdependency_info_struct = GenerateStruct_VkDependencyInfo(stream_pdependency_info,
                                                                          args.pDependencyInfo.GetPointer(),
                                                                          args.pDependencyInfo.GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pdependency_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdSetEvent2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdSetEvent2KHR(%s, %s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.event).c_str(),
            pdependency_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetEvent2KHR);
}

void VulkanCppConsumer::Process_vkCmdWaitEvents2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdWaitEvents2KHR&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pevents_array = "NULL";
    std::string pevents_values = toStringJoin(args.pEvents.GetPointer(),
                                              args.pEvents.GetPointer() + args.eventCount,
                                              [&](const format::HandleId current) { return this->GetHandle(current); },
                                              ", ");
    if (args.eventCount == 1 && pevents_values != "VK_NULL_HANDLE") {
        pevents_array = "&" + pevents_values;
    } else if (args.eventCount > 1) {
        pevents_array = "pevents_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkEvent %s[] = { %s };\n", pevents_array.c_str(), pevents_values.c_str());
    }
    std::stringstream stream_pdependency_infos;
    std::string pdependency_infos_array = "NULL";
    PointerPairContainer<decltype(args.pDependencyInfos.GetPointer()), decltype(args.pDependencyInfos.GetMetaStructPointer())> pdependency_infos_pair{ args.pDependencyInfos.GetPointer(), args.pDependencyInfos.GetMetaStructPointer(), args.eventCount };
    std::string pdependency_infos_names = toStringJoin(pdependency_infos_pair.begin(),
                                                       pdependency_infos_pair.end(),
                                                       [&](auto pair) {{ return GenerateStruct_VkDependencyInfo(stream_pdependency_infos, pair.t1, pair.t2, *this); }},
                                                       ", ");
    if (stream_pdependency_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pdependency_infos.str().c_str());
        if (args.eventCount == 1) {
            pdependency_infos_array = "&" + pdependency_infos_names;
        } else if (args.eventCount > 1) {
            pdependency_infos_array = "pDependencyInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkDependencyInfo %s[] = { %s };\n", pdependency_infos_array.c_str(), pdependency_infos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdWaitEvents2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdWaitEvents2KHR(%s, %u, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.eventCount,
            pevents_array.c_str(),
            pdependency_infos_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR);
}

void VulkanCppConsumer::Process_vkCmdWriteTimestamp2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdWriteTimestamp2KHR&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdWriteTimestamp2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdWriteTimestamp2KHR(%s, %s, %s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkPipelineStageFlags2>(args.stage).c_str(),
            this->GetHandle(args.queryPool).c_str(),
            args.query);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR);
}

void VulkanCppConsumer::Process_vkQueueSubmit2KHR(
    const ApiCallInfo&                          call_info,
    args::QueueSubmit2KHR&                      args)
{
    Generate_vkQueueSubmit2KHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkQueueSubmit2KHR);
}
void VulkanCppConsumer::Process_vkCmdBeginConditionalRendering2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginConditionalRendering2EXT&     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pconditional_rendering_begin;
    std::string pconditional_rendering_begin_struct = GenerateStruct_VkConditionalRenderingBeginInfo2EXT(stream_pconditional_rendering_begin,
                                                                                                         args.pConditionalRenderingBegin.GetPointer(),
                                                                                                         args.pConditionalRenderingBegin.GetMetaStructPointer(),
                                                                                                         *this);
    fprintf(file, "%s", stream_pconditional_rendering_begin.str().c_str());
    pfn_loader_.AddMethodName("vkCmdBeginConditionalRendering2EXT");
    fprintf(file,
            "\t\tloaded_vkCmdBeginConditionalRendering2EXT(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pconditional_rendering_begin_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginConditionalRendering2EXT);
}

void VulkanCppConsumer::Process_vkCmdBeginTransformFeedback2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginTransformFeedback2EXT&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcounter_infos;
    std::string pcounter_infos_array = "NULL";
    PointerPairContainer<decltype(args.pCounterInfos.GetPointer()), decltype(args.pCounterInfos.GetMetaStructPointer())> pcounter_infos_pair{ args.pCounterInfos.GetPointer(), args.pCounterInfos.GetMetaStructPointer(), args.counterRangeCount };
    std::string pcounter_infos_names = toStringJoin(pcounter_infos_pair.begin(),
                                                    pcounter_infos_pair.end(),
                                                    [&](auto pair) {{ return GenerateStruct_VkBindTransformFeedbackBuffer2InfoEXT(stream_pcounter_infos, pair.t1, pair.t2, *this); }},
                                                    ", ");
    if (stream_pcounter_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pcounter_infos.str().c_str());
        if (args.counterRangeCount == 1) {
            pcounter_infos_array = "&" + pcounter_infos_names;
        } else if (args.counterRangeCount > 1) {
            pcounter_infos_array = "pCounterInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBindTransformFeedbackBuffer2InfoEXT %s[] = { %s };\n", pcounter_infos_array.c_str(), pcounter_infos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdBeginTransformFeedback2EXT");
    fprintf(file,
            "\t\tloaded_vkCmdBeginTransformFeedback2EXT(%s, %u, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.firstCounterRange,
            args.counterRangeCount,
            pcounter_infos_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginTransformFeedback2EXT);
}

void VulkanCppConsumer::Process_vkCmdBindIndexBuffer3KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer3KHR&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkBindIndexBuffer3InfoKHR(stream_pinfo,
                                                                        args.pInfo.GetPointer(),
                                                                        args.pInfo.GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCmdBindIndexBuffer3KHR");
    fprintf(file,
            "\t\tloaded_vkCmdBindIndexBuffer3KHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindIndexBuffer3KHR);
}

void VulkanCppConsumer::Process_vkCmdBindTransformFeedbackBuffers2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindTransformFeedbackBuffers2EXT&  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbinding_infos;
    std::string pbinding_infos_array = "NULL";
    PointerPairContainer<decltype(args.pBindingInfos.GetPointer()), decltype(args.pBindingInfos.GetMetaStructPointer())> pbinding_infos_pair{ args.pBindingInfos.GetPointer(), args.pBindingInfos.GetMetaStructPointer(), args.bindingCount };
    std::string pbinding_infos_names = toStringJoin(pbinding_infos_pair.begin(),
                                                    pbinding_infos_pair.end(),
                                                    [&](auto pair) {{ return GenerateStruct_VkBindTransformFeedbackBuffer2InfoEXT(stream_pbinding_infos, pair.t1, pair.t2, *this); }},
                                                    ", ");
    if (stream_pbinding_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pbinding_infos.str().c_str());
        if (args.bindingCount == 1) {
            pbinding_infos_array = "&" + pbinding_infos_names;
        } else if (args.bindingCount > 1) {
            pbinding_infos_array = "pBindingInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBindTransformFeedbackBuffer2InfoEXT %s[] = { %s };\n", pbinding_infos_array.c_str(), pbinding_infos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdBindTransformFeedbackBuffers2EXT");
    fprintf(file,
            "\t\tloaded_vkCmdBindTransformFeedbackBuffers2EXT(%s, %u, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.firstBinding,
            args.bindingCount,
            pbinding_infos_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffers2EXT);
}

void VulkanCppConsumer::Process_vkCmdBindVertexBuffers3KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers3KHR&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbinding_infos;
    std::string pbinding_infos_array = "NULL";
    PointerPairContainer<decltype(args.pBindingInfos.GetPointer()), decltype(args.pBindingInfos.GetMetaStructPointer())> pbinding_infos_pair{ args.pBindingInfos.GetPointer(), args.pBindingInfos.GetMetaStructPointer(), args.bindingCount };
    std::string pbinding_infos_names = toStringJoin(pbinding_infos_pair.begin(),
                                                    pbinding_infos_pair.end(),
                                                    [&](auto pair) {{ return GenerateStruct_VkBindVertexBuffer3InfoKHR(stream_pbinding_infos, pair.t1, pair.t2, *this); }},
                                                    ", ");
    if (stream_pbinding_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pbinding_infos.str().c_str());
        if (args.bindingCount == 1) {
            pbinding_infos_array = "&" + pbinding_infos_names;
        } else if (args.bindingCount > 1) {
            pbinding_infos_array = "pBindingInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBindVertexBuffer3InfoKHR %s[] = { %s };\n", pbinding_infos_array.c_str(), pbinding_infos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdBindVertexBuffers3KHR");
    fprintf(file,
            "\t\tloaded_vkCmdBindVertexBuffers3KHR(%s, %u, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.firstBinding,
            args.bindingCount,
            pbinding_infos_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindVertexBuffers3KHR);
}

void VulkanCppConsumer::Process_vkCmdCopyImageToMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToMemoryKHR&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_memory_info;
    std::string pcopy_memory_info_struct = GenerateStruct_VkCopyDeviceMemoryImageInfoKHR(stream_pcopy_memory_info,
                                                                                         args.pCopyMemoryInfo.GetPointer(),
                                                                                         args.pCopyMemoryInfo.GetMetaStructPointer(),
                                                                                         *this);
    fprintf(file, "%s", stream_pcopy_memory_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyImageToMemoryKHR");
    fprintf(file,
            "\t\tloaded_vkCmdCopyImageToMemoryKHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pcopy_memory_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImageToMemoryKHR);
}

void VulkanCppConsumer::Process_vkCmdCopyMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryKHR&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_memory_info;
    std::string pcopy_memory_info_struct = GenerateStruct_VkCopyDeviceMemoryInfoKHR(stream_pcopy_memory_info,
                                                                                    args.pCopyMemoryInfo.GetPointer(),
                                                                                    args.pCopyMemoryInfo.GetMetaStructPointer(),
                                                                                    *this);
    fprintf(file, "%s", stream_pcopy_memory_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyMemoryKHR");
    fprintf(file,
            "\t\tloaded_vkCmdCopyMemoryKHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pcopy_memory_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyMemoryKHR);
}

void VulkanCppConsumer::Process_vkCmdCopyMemoryToImageKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToImageKHR&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_memory_info;
    std::string pcopy_memory_info_struct = GenerateStruct_VkCopyDeviceMemoryImageInfoKHR(stream_pcopy_memory_info,
                                                                                         args.pCopyMemoryInfo.GetPointer(),
                                                                                         args.pCopyMemoryInfo.GetMetaStructPointer(),
                                                                                         *this);
    fprintf(file, "%s", stream_pcopy_memory_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyMemoryToImageKHR");
    fprintf(file,
            "\t\tloaded_vkCmdCopyMemoryToImageKHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pcopy_memory_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyMemoryToImageKHR);
}

void VulkanCppConsumer::Process_vkCmdCopyQueryPoolResultsToMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyQueryPoolResultsToMemoryKHR&   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdst_range;
    std::string pdst_range_struct = GenerateStruct_VkStridedDeviceAddressRangeKHR(stream_pdst_range,
                                                                                  args.pDstRange.GetPointer(),
                                                                                  args.pDstRange.GetMetaStructPointer(),
                                                                                  *this);
    fprintf(file, "%s", stream_pdst_range.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyQueryPoolResultsToMemoryKHR");
    fprintf(file,
            "\t\tloaded_vkCmdCopyQueryPoolResultsToMemoryKHR(%s, %s, %u, %u, &%s, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.queryPool).c_str(),
            args.firstQuery,
            args.queryCount,
            pdst_range_struct.c_str(),
            util::ToString<VkAddressCommandFlagsKHR>(args.dstFlags).c_str(),
            util::ToString<VkQueryResultFlags>(args.queryResultFlags).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResultsToMemoryKHR);
}

void VulkanCppConsumer::Process_vkCmdDispatchIndirect2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchIndirect2KHR&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDispatchIndirect2InfoKHR(stream_pinfo,
                                                                         args.pInfo.GetPointer(),
                                                                         args.pInfo.GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCmdDispatchIndirect2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdDispatchIndirect2KHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDispatchIndirect2KHR);
}

void VulkanCppConsumer::Process_vkCmdDrawIndexedIndirect2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirect2KHR&           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDrawIndirect2InfoKHR(stream_pinfo,
                                                                     args.pInfo.GetPointer(),
                                                                     args.pInfo.GetMetaStructPointer(),
                                                                     *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCmdDrawIndexedIndirect2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdDrawIndexedIndirect2KHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect2KHR);
}

void VulkanCppConsumer::Process_vkCmdDrawIndexedIndirectCount2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCount2KHR&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDrawIndirectCount2InfoKHR(stream_pinfo,
                                                                          args.pInfo.GetPointer(),
                                                                          args.pInfo.GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCmdDrawIndexedIndirectCount2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdDrawIndexedIndirectCount2KHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount2KHR);
}

void VulkanCppConsumer::Process_vkCmdDrawIndirect2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirect2KHR&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDrawIndirect2InfoKHR(stream_pinfo,
                                                                     args.pInfo.GetPointer(),
                                                                     args.pInfo.GetMetaStructPointer(),
                                                                     *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCmdDrawIndirect2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdDrawIndirect2KHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirect2KHR);
}

void VulkanCppConsumer::Process_vkCmdDrawIndirectByteCount2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectByteCount2EXT&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcounter_info;
    std::string pcounter_info_struct = GenerateStruct_VkBindTransformFeedbackBuffer2InfoEXT(stream_pcounter_info,
                                                                                            args.pCounterInfo.GetPointer(),
                                                                                            args.pCounterInfo.GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pcounter_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdDrawIndirectByteCount2EXT");
    fprintf(file,
            "\t\tloaded_vkCmdDrawIndirectByteCount2EXT(%s, %u, %u, &%s, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.instanceCount,
            args.firstInstance,
            pcounter_info_struct.c_str(),
            args.counterOffset,
            args.vertexStride);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCount2EXT);
}

void VulkanCppConsumer::Process_vkCmdDrawIndirectCount2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCount2KHR&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDrawIndirectCount2InfoKHR(stream_pinfo,
                                                                          args.pInfo.GetPointer(),
                                                                          args.pInfo.GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCmdDrawIndirectCount2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdDrawIndirectCount2KHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirectCount2KHR);
}

void VulkanCppConsumer::Process_vkCmdDrawMeshTasksIndirect2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirect2EXT&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDrawIndirect2InfoKHR(stream_pinfo,
                                                                     args.pInfo.GetPointer(),
                                                                     args.pInfo.GetMetaStructPointer(),
                                                                     *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCmdDrawMeshTasksIndirect2EXT");
    fprintf(file,
            "\t\tloaded_vkCmdDrawMeshTasksIndirect2EXT(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirect2EXT);
}

void VulkanCppConsumer::Process_vkCmdDrawMeshTasksIndirectCount2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectCount2EXT&    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDrawIndirectCount2InfoKHR(stream_pinfo,
                                                                          args.pInfo.GetPointer(),
                                                                          args.pInfo.GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCmdDrawMeshTasksIndirectCount2EXT");
    fprintf(file,
            "\t\tloaded_vkCmdDrawMeshTasksIndirectCount2EXT(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCount2EXT);
}

void VulkanCppConsumer::Process_vkCmdEndTransformFeedback2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndTransformFeedback2EXT&          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcounter_infos;
    std::string pcounter_infos_array = "NULL";
    PointerPairContainer<decltype(args.pCounterInfos.GetPointer()), decltype(args.pCounterInfos.GetMetaStructPointer())> pcounter_infos_pair{ args.pCounterInfos.GetPointer(), args.pCounterInfos.GetMetaStructPointer(), args.counterRangeCount };
    std::string pcounter_infos_names = toStringJoin(pcounter_infos_pair.begin(),
                                                    pcounter_infos_pair.end(),
                                                    [&](auto pair) {{ return GenerateStruct_VkBindTransformFeedbackBuffer2InfoEXT(stream_pcounter_infos, pair.t1, pair.t2, *this); }},
                                                    ", ");
    if (stream_pcounter_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pcounter_infos.str().c_str());
        if (args.counterRangeCount == 1) {
            pcounter_infos_array = "&" + pcounter_infos_names;
        } else if (args.counterRangeCount > 1) {
            pcounter_infos_array = "pCounterInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBindTransformFeedbackBuffer2InfoEXT %s[] = { %s };\n", pcounter_infos_array.c_str(), pcounter_infos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdEndTransformFeedback2EXT");
    fprintf(file,
            "\t\tloaded_vkCmdEndTransformFeedback2EXT(%s, %u, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.firstCounterRange,
            args.counterRangeCount,
            pcounter_infos_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndTransformFeedback2EXT);
}

void VulkanCppConsumer::Process_vkCmdFillMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdFillMemoryKHR&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdst_range;
    std::string pdst_range_struct = GenerateStruct_VkDeviceAddressRangeKHR(stream_pdst_range,
                                                                           args.pDstRange.GetPointer(),
                                                                           args.pDstRange.GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_pdst_range.str().c_str());
    pfn_loader_.AddMethodName("vkCmdFillMemoryKHR");
    fprintf(file,
            "\t\tloaded_vkCmdFillMemoryKHR(%s, &%s, %s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pdst_range_struct.c_str(),
            util::ToString<VkAddressCommandFlagsKHR>(args.dstFlags).c_str(),
            args.data);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdFillMemoryKHR);
}

void VulkanCppConsumer::Process_vkCmdUpdateMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdUpdateMemoryKHR&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdst_range;
    std::string pdst_range_struct = GenerateStruct_VkDeviceAddressRangeKHR(stream_pdst_range,
                                                                           args.pDstRange.GetPointer(),
                                                                           args.pDstRange.GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_pdst_range.str().c_str());
    std::string pdata_array = "pData_" + std::to_string(this->GetNextId());
    if (args.dataSize > 0) {
        std::string pdata_values = toStringJoin(args.pData.GetPointer(),
                                                args.pData.GetPointer() + args.dataSize,
                                                [&](const auto current) { return std::to_string(current) + ""; },
                                                ", ");
        fprintf(file, "\t\tuint8_t %s[] = { %s };\n", pdata_array.c_str(), pdata_values.c_str());
    } else {
        pdata_array = "NULL";
    }
    pfn_loader_.AddMethodName("vkCmdUpdateMemoryKHR");
    fprintf(file,
            "\t\tloaded_vkCmdUpdateMemoryKHR(%s, &%s, %s, %" PRIu64 "UL, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pdst_range_struct.c_str(),
            util::ToString<VkAddressCommandFlagsKHR>(args.dstFlags).c_str(),
            args.dataSize,
            pdata_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdUpdateMemoryKHR);
}

void VulkanCppConsumer::Process_vkCmdWriteMarkerToMemoryAMD(
    const ApiCallInfo&                          call_info,
    args::CmdWriteMarkerToMemoryAMD&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkMemoryMarkerInfoAMD(stream_pinfo,
                                                                    args.pInfo.GetPointer(),
                                                                    args.pInfo.GetMetaStructPointer(),
                                                                    *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCmdWriteMarkerToMemoryAMD");
    fprintf(file,
            "\t\tloaded_vkCmdWriteMarkerToMemoryAMD(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteMarkerToMemoryAMD);
}

void VulkanCppConsumer::Process_vkCreateAccelerationStructure2KHR(
    const ApiCallInfo&                          call_info,
    args::CreateAccelerationStructure2KHR&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkAccelerationStructureCreateInfo2KHR(stream_pcreate_info,
                                                                                           args.pCreateInfo.GetPointer(),
                                                                                           args.pCreateInfo.GetMetaStructPointer(),
                                                                                           *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pacceleration_structure_name = "pAccelerationStructure_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR));
    AddKnownVariables("VkAccelerationStructureKHR", pacceleration_structure_name, args.pAccelerationStructure.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pacceleration_structure_name,
                         args.pAccelerationStructure.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateAccelerationStructure2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateAccelerationStructure2KHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pacceleration_structure_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateAccelerationStructure2KHR);
}
void VulkanCppConsumer::Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBlitImage2KHR&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pblit_image_info;
    std::string pblit_image_info_struct = GenerateStruct_VkBlitImageInfo2(stream_pblit_image_info,
                                                                          args.pBlitImageInfo.GetPointer(),
                                                                          args.pBlitImageInfo.GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pblit_image_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdBlitImage2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdBlitImage2KHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pblit_image_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBlitImage2KHR);
}

void VulkanCppConsumer::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBuffer2KHR&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_buffer_info;
    std::string pcopy_buffer_info_struct = GenerateStruct_VkCopyBufferInfo2(stream_pcopy_buffer_info,
                                                                            args.pCopyBufferInfo.GetPointer(),
                                                                            args.pCopyBufferInfo.GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pcopy_buffer_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyBuffer2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdCopyBuffer2KHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pcopy_buffer_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR);
}

void VulkanCppConsumer::Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBufferToImage2KHR&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_buffer_to_image_info;
    std::string pcopy_buffer_to_image_info_struct = GenerateStruct_VkCopyBufferToImageInfo2(stream_pcopy_buffer_to_image_info,
                                                                                            args.pCopyBufferToImageInfo.GetPointer(),
                                                                                            args.pCopyBufferToImageInfo.GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pcopy_buffer_to_image_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyBufferToImage2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdCopyBufferToImage2KHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pcopy_buffer_to_image_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR);
}

void VulkanCppConsumer::Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImage2KHR&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_image_info;
    std::string pcopy_image_info_struct = GenerateStruct_VkCopyImageInfo2(stream_pcopy_image_info,
                                                                          args.pCopyImageInfo.GetPointer(),
                                                                          args.pCopyImageInfo.GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pcopy_image_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyImage2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdCopyImage2KHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pcopy_image_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImage2KHR);
}

void VulkanCppConsumer::Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToBuffer2KHR&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_image_to_buffer_info;
    std::string pcopy_image_to_buffer_info_struct = GenerateStruct_VkCopyImageToBufferInfo2(stream_pcopy_image_to_buffer_info,
                                                                                            args.pCopyImageToBufferInfo.GetPointer(),
                                                                                            args.pCopyImageToBufferInfo.GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pcopy_image_to_buffer_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyImageToBuffer2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdCopyImageToBuffer2KHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pcopy_image_to_buffer_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR);
}

void VulkanCppConsumer::Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdResolveImage2KHR&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_presolve_image_info;
    std::string presolve_image_info_struct = GenerateStruct_VkResolveImageInfo2(stream_presolve_image_info,
                                                                                args.pResolveImageInfo.GetPointer(),
                                                                                args.pResolveImageInfo.GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_presolve_image_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdResolveImage2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdResolveImage2KHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            presolve_image_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResolveImage2KHR);
}
void VulkanCppConsumer::Process_vkCmdTraceRaysIndirect2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdTraceRaysIndirect2KHR&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdTraceRaysIndirect2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdTraceRaysIndirect2KHR(%s, %" PRIu64 "UL);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.indirectDeviceAddress);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR);
}
void VulkanCppConsumer::Process_vkGetDeviceBufferMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceBufferMemoryRequirementsKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDeviceBufferMemoryRequirements(stream_pinfo,
                                                                               args.pInfo.GetPointer(),
                                                                               args.pInfo.GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string pmemory_requirements_name = "NULL";
    if (!args.pMemoryRequirements.IsNull()) {
        pmemory_requirements_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkMemoryRequirements2 %s = {};\n", pmemory_requirements_name.c_str());
        pmemory_requirements_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetDeviceBufferMemoryRequirementsKHR");
    fprintf(file,
            "\t\tloaded_vkGetDeviceBufferMemoryRequirementsKHR(%s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str(),
            pmemory_requirements_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR);
}

void VulkanCppConsumer::Process_vkGetDeviceImageMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceImageMemoryRequirementsKHR&  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDeviceImageMemoryRequirements(stream_pinfo,
                                                                              args.pInfo.GetPointer(),
                                                                              args.pInfo.GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string pmemory_requirements_name = "NULL";
    if (!args.pMemoryRequirements.IsNull()) {
        pmemory_requirements_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkMemoryRequirements2 %s = {};\n", pmemory_requirements_name.c_str());
        pmemory_requirements_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetDeviceImageMemoryRequirementsKHR");
    fprintf(file,
            "\t\tloaded_vkGetDeviceImageMemoryRequirementsKHR(%s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str(),
            pmemory_requirements_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR);
}

void VulkanCppConsumer::Process_vkGetDeviceImageSparseMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceImageSparseMemoryRequirementsKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDeviceImageMemoryRequirements(stream_pinfo,
                                                                              args.pInfo.GetPointer(),
                                                                              args.pInfo.GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string psparse_memory_requirement_count_name = "NULL";
    if (!args.pSparseMemoryRequirementCount.IsNull()) {
        psparse_memory_requirement_count_name = "pSparseMemoryRequirementCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", psparse_memory_requirement_count_name.c_str(), util::ToString(*args.pSparseMemoryRequirementCount.GetPointer()).c_str());
        psparse_memory_requirement_count_name.insert(0, "&");
    }
    std::string psparse_memory_requirements_name = "NULL";
    if (!args.pSparseMemoryRequirements.IsNull()) {
        const uint32_t* in_psparse_memory_requirement_count = args.pSparseMemoryRequirementCount.GetPointer();
        psparse_memory_requirements_name = "pSparseMemoryRequirements_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkSparseImageMemoryRequirements2 %s[%d] = {};\n", psparse_memory_requirements_name.c_str(), *in_psparse_memory_requirement_count);
    }
    pfn_loader_.AddMethodName("vkGetDeviceImageSparseMemoryRequirementsKHR");
    fprintf(file,
            "\t\tloaded_vkGetDeviceImageSparseMemoryRequirementsKHR(%s, &%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str(),
            psparse_memory_requirement_count_name.c_str(),
            psparse_memory_requirements_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR);
}
void VulkanCppConsumer::Process_vkCmdBindIndexBuffer2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer2KHR&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdBindIndexBuffer2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdBindIndexBuffer2KHR(%s, %s, %" PRIu64 "UL, %" PRIu64 "UL, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.buffer).c_str(),
            args.offset,
            args.size,
            util::ToString<VkIndexType>(args.indexType).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindIndexBuffer2KHR);
}

void VulkanCppConsumer::Process_vkGetDeviceImageSubresourceLayoutKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceImageSubresourceLayoutKHR&   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDeviceImageSubresourceInfo(stream_pinfo,
                                                                           args.pInfo.GetPointer(),
                                                                           args.pInfo.GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string playout_name = "NULL";
    if (!args.pLayout.IsNull()) {
        playout_name = "pLayout_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkSubresourceLayout2 %s = {};\n", playout_name.c_str());
        playout_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetDeviceImageSubresourceLayoutKHR");
    fprintf(file,
            "\t\tloaded_vkGetDeviceImageSubresourceLayoutKHR(%s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str(),
            playout_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceImageSubresourceLayoutKHR);
}

void VulkanCppConsumer::Process_vkGetImageSubresourceLayout2KHR(
    const ApiCallInfo&                          call_info,
    args::GetImageSubresourceLayout2KHR&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psubresource;
    std::string psubresource_struct = GenerateStruct_VkImageSubresource2(stream_psubresource,
                                                                         args.pSubresource.GetPointer(),
                                                                         args.pSubresource.GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "%s", stream_psubresource.str().c_str());
    std::string playout_name = "NULL";
    if (!args.pLayout.IsNull()) {
        playout_name = "pLayout_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkSubresourceLayout2 %s = {};\n", playout_name.c_str());
        playout_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetImageSubresourceLayout2KHR");
    fprintf(file,
            "\t\tloaded_vkGetImageSubresourceLayout2KHR(%s, %s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.image).c_str(),
            psubresource_struct.c_str(),
            playout_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2KHR);
}

void VulkanCppConsumer::Process_vkGetRenderingAreaGranularityKHR(
    const ApiCallInfo&                          call_info,
    args::GetRenderingAreaGranularityKHR&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_prendering_area_info;
    std::string prendering_area_info_struct = GenerateStruct_VkRenderingAreaInfo(stream_prendering_area_info,
                                                                                 args.pRenderingAreaInfo.GetPointer(),
                                                                                 args.pRenderingAreaInfo.GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_prendering_area_info.str().c_str());
    std::string pgranularity_name = "NULL";
    if (!args.pGranularity.IsNull()) {
        pgranularity_name = "pGranularity_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkExtent2D %s = {};\n", pgranularity_name.c_str());
        pgranularity_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetRenderingAreaGranularityKHR");
    fprintf(file,
            "\t\tloaded_vkGetRenderingAreaGranularityKHR(%s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            prendering_area_info_struct.c_str(),
            pgranularity_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetRenderingAreaGranularityKHR);
}
void VulkanCppConsumer::Process_vkWaitForPresent2KHR(
    const ApiCallInfo&                          call_info,
    args::WaitForPresent2KHR&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_ppresent_wait2_info;
    std::string ppresent_wait2_info_struct = GenerateStruct_VkPresentWait2InfoKHR(stream_ppresent_wait2_info,
                                                                                  args.pPresentWait2Info.GetPointer(),
                                                                                  args.pPresentWait2Info.GetMetaStructPointer(),
                                                                                  *this);
    fprintf(file, "%s", stream_ppresent_wait2_info.str().c_str());
    pfn_loader_.AddMethodName("vkWaitForPresent2KHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkWaitForPresent2KHR(%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.swapchain).c_str(),
            ppresent_wait2_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkWaitForPresent2KHR);
}
void VulkanCppConsumer::Process_vkCreatePipelineBinariesKHR(
    const ApiCallInfo&                          call_info,
    args::CreatePipelineBinariesKHR&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkPipelineBinaryCreateInfoKHR(stream_pcreate_info,
                                                                                   args.pCreateInfo.GetPointer(),
                                                                                   args.pCreateInfo.GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pbinaries_name = "NULL";
    if (!args.pBinaries.IsNull()) {
        pbinaries_name = "pBinaries_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPipelineBinaryHandlesInfoKHR %s = {};\n", pbinaries_name.c_str());
        pbinaries_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkCreatePipelineBinariesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreatePipelineBinariesKHR(%s, &%s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pbinaries_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreatePipelineBinariesKHR);
}

void VulkanCppConsumer::Process_vkDestroyPipelineBinaryKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyPipelineBinaryKHR&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyPipelineBinaryKHR");
    fprintf(file,
            "\t\tloaded_vkDestroyPipelineBinaryKHR(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.pipelineBinary).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPipelineBinaryKHR);
}

void VulkanCppConsumer::Process_vkGetPipelineBinaryDataKHR(
    const ApiCallInfo&                          call_info,
    args::GetPipelineBinaryDataKHR&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkPipelineBinaryDataInfoKHR(stream_pinfo,
                                                                          args.pInfo.GetPointer(),
                                                                          args.pInfo.GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string ppipeline_binary_key_name = "NULL";
    if (!args.pPipelineBinaryKey.IsNull()) {
        ppipeline_binary_key_name = "pPipelineBinaryKey_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPipelineBinaryKeyKHR %s = {};\n", ppipeline_binary_key_name.c_str());
        ppipeline_binary_key_name.insert(0, "&");
    }
    std::string ppipeline_binary_data_size_name = "NULL";
    if (!args.pPipelineBinaryDataSize.IsNull()) {
        ppipeline_binary_data_size_name = "pPipelineBinaryDataSize_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tsize_t %s = %s;\n", ppipeline_binary_data_size_name.c_str(), util::ToString(*args.pPipelineBinaryDataSize.GetPointer()).c_str());
        ppipeline_binary_data_size_name.insert(0, "&");
    }
    std::string ppipeline_binary_data_name = "NULL";
    if (!args.pPipelineBinaryData.IsNull()) {
        size_t* in_ppipeline_binary_data_size = args.pPipelineBinaryDataSize.GetPointer();
        ppipeline_binary_data_name = "pPipelineBinaryData_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint8_t %s[%" PRIu64 "] = {};\n", ppipeline_binary_data_name.c_str(), util::platform::SizeTtoUint64(*in_ppipeline_binary_data_size));
    }
    pfn_loader_.AddMethodName("vkGetPipelineBinaryDataKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPipelineBinaryDataKHR(%s, &%s, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str(),
            ppipeline_binary_key_name.c_str(),
            ppipeline_binary_data_size_name.c_str(),
            ppipeline_binary_data_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPipelineBinaryDataKHR);
}

void VulkanCppConsumer::Process_vkGetPipelineKeyKHR(
    const ApiCallInfo&                          call_info,
    args::GetPipelineKeyKHR&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_ppipeline_create_info;
    std::string ppipeline_create_info_struct = GenerateStruct_VkPipelineCreateInfoKHR(stream_ppipeline_create_info,
                                                                                      args.pPipelineCreateInfo.GetPointer(),
                                                                                      args.pPipelineCreateInfo.GetMetaStructPointer(),
                                                                                      *this);
    fprintf(file, "%s", stream_ppipeline_create_info.str().c_str());
    std::string ppipeline_key_name = "NULL";
    if (!args.pPipelineKey.IsNull()) {
        ppipeline_key_name = "pPipelineKey_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPipelineBinaryKeyKHR %s = {};\n", ppipeline_key_name.c_str());
        ppipeline_key_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPipelineKeyKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPipelineKeyKHR(%s, &%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            ppipeline_create_info_struct.c_str(),
            ppipeline_key_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPipelineKeyKHR);
}

void VulkanCppConsumer::Process_vkReleaseCapturedPipelineDataKHR(
    const ApiCallInfo&                          call_info,
    args::ReleaseCapturedPipelineDataKHR&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkReleaseCapturedPipelineDataInfoKHR(stream_pinfo,
                                                                                   args.pInfo.GetPointer(),
                                                                                   args.pInfo.GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkReleaseCapturedPipelineDataKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkReleaseCapturedPipelineDataKHR(%s, &%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str(),
            "nullptr",
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkReleaseCapturedPipelineDataKHR);
}
void VulkanCppConsumer::Process_vkReleaseSwapchainImagesKHR(
    const ApiCallInfo&                          call_info,
    args::ReleaseSwapchainImagesKHR&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_prelease_info;
    std::string prelease_info_struct = GenerateStruct_VkReleaseSwapchainImagesInfoKHR(stream_prelease_info,
                                                                                      args.pReleaseInfo.GetPointer(),
                                                                                      args.pReleaseInfo.GetMetaStructPointer(),
                                                                                      *this);
    fprintf(file, "%s", stream_prelease_info.str().c_str());
    pfn_loader_.AddMethodName("vkReleaseSwapchainImagesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkReleaseSwapchainImagesKHR(%s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            prelease_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkReleaseSwapchainImagesKHR);
}
void VulkanCppConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceCooperativeMatrixPropertiesKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pproperty_count_name = "NULL";
    if (!args.pPropertyCount.IsNull()) {
        pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pproperty_count_name.c_str(), util::ToString(*args.pPropertyCount.GetPointer()).c_str());
        pproperty_count_name.insert(0, "&");
    }
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        const uint32_t* in_pproperty_count = args.pPropertyCount.GetPointer();
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkCooperativeMatrixPropertiesKHR %s[%d] = {};\n", pproperties_name.c_str(), *in_pproperty_count);
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(%s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR);
}
void VulkanCppConsumer::Process_vkCmdSetLineStippleKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineStippleKHR&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetLineStippleKHR");
    fprintf(file,
            "\t\tloaded_vkCmdSetLineStippleKHR(%s, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.lineStippleFactor,
            args.lineStipplePattern);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLineStippleKHR);
}
void VulkanCppConsumer::Process_vkGetCalibratedTimestampsKHR(
    const ApiCallInfo&                          call_info,
    args::GetCalibratedTimestampsKHR&           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_ptimestamp_infos;
    std::string ptimestamp_infos_array = "NULL";
    PointerPairContainer<decltype(args.pTimestampInfos.GetPointer()), decltype(args.pTimestampInfos.GetMetaStructPointer())> ptimestamp_infos_pair{ args.pTimestampInfos.GetPointer(), args.pTimestampInfos.GetMetaStructPointer(), args.timestampCount };
    std::string ptimestamp_infos_names = toStringJoin(ptimestamp_infos_pair.begin(),
                                                      ptimestamp_infos_pair.end(),
                                                      [&](auto pair) {{ return GenerateStruct_VkCalibratedTimestampInfoKHR(stream_ptimestamp_infos, pair.t1, pair.t2, *this); }},
                                                      ", ");
    if (stream_ptimestamp_infos.str().length() > 0) {
        fprintf(file, "%s", stream_ptimestamp_infos.str().c_str());
        if (args.timestampCount == 1) {
            ptimestamp_infos_array = "&" + ptimestamp_infos_names;
        } else if (args.timestampCount > 1) {
            ptimestamp_infos_array = "pTimestampInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkCalibratedTimestampInfoKHR %s[] = { %s };\n", ptimestamp_infos_array.c_str(), ptimestamp_infos_names.c_str());
        }
    }
    std::string ptimestamps_name = "NULL";
    if (!args.pTimestamps.IsNull()) {
        ptimestamps_name = "pTimestamps_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint64_t %s[%d] = {};\n", ptimestamps_name.c_str(), args.timestampCount);
    }
    std::string pmax_deviation_name = "NULL";
    if (!args.pMaxDeviation.IsNull()) {
        pmax_deviation_name = "pMaxDeviation_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint64_t %s = %s;\n", pmax_deviation_name.c_str(), util::ToString(*args.pMaxDeviation.GetPointer()).c_str());
        pmax_deviation_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetCalibratedTimestampsKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetCalibratedTimestampsKHR(%s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            args.timestampCount,
            ptimestamp_infos_array.c_str(),
            ptimestamps_name.c_str(),
            pmax_deviation_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetCalibratedTimestampsKHR);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceCalibrateableTimeDomainsKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string ptime_domain_count_name = "NULL";
    if (!args.pTimeDomainCount.IsNull()) {
        ptime_domain_count_name = "pTimeDomainCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", ptime_domain_count_name.c_str(), util::ToString(*args.pTimeDomainCount.GetPointer()).c_str());
        ptime_domain_count_name.insert(0, "&");
    }
    std::string ptime_domains_name = "NULL";
    if (!args.pTimeDomains.IsNull()) {
        const uint32_t* in_ptime_domain_count = args.pTimeDomainCount.GetPointer();
        ptime_domains_name = "pTimeDomains_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkTimeDomainKHR %s[%d] = {};\n", ptime_domains_name.c_str(), *in_ptime_domain_count);
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceCalibrateableTimeDomainsKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(%s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            ptime_domain_count_name.c_str(),
            ptime_domains_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR);
}
void VulkanCppConsumer::Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorBufferEmbeddedSamplers2EXT& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbind_descriptor_buffer_embedded_samplers_info;
    std::string pbind_descriptor_buffer_embedded_samplers_info_struct = GenerateStruct_VkBindDescriptorBufferEmbeddedSamplersInfoEXT(stream_pbind_descriptor_buffer_embedded_samplers_info,
                                                                                                                                     args.pBindDescriptorBufferEmbeddedSamplersInfo.GetPointer(),
                                                                                                                                     args.pBindDescriptorBufferEmbeddedSamplersInfo.GetMetaStructPointer(),
                                                                                                                                     *this);
    fprintf(file, "%s", stream_pbind_descriptor_buffer_embedded_samplers_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdBindDescriptorBufferEmbeddedSamplers2EXT");
    fprintf(file,
            "\t\tloaded_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pbind_descriptor_buffer_embedded_samplers_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT);
}

void VulkanCppConsumer::Process_vkCmdBindDescriptorSets2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorSets2KHR&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbind_descriptor_sets_info;
    std::string pbind_descriptor_sets_info_struct = GenerateStruct_VkBindDescriptorSetsInfo(stream_pbind_descriptor_sets_info,
                                                                                            args.pBindDescriptorSetsInfo.GetPointer(),
                                                                                            args.pBindDescriptorSetsInfo.GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pbind_descriptor_sets_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdBindDescriptorSets2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdBindDescriptorSets2KHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pbind_descriptor_sets_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindDescriptorSets2KHR);
}

void VulkanCppConsumer::Process_vkCmdPushConstants2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdPushConstants2KHR&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_ppush_constants_info;
    std::string ppush_constants_info_struct = GenerateStruct_VkPushConstantsInfo(stream_ppush_constants_info,
                                                                                 args.pPushConstantsInfo.GetPointer(),
                                                                                 args.pPushConstantsInfo.GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_ppush_constants_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdPushConstants2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdPushConstants2KHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            ppush_constants_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPushConstants2KHR);
}

void VulkanCppConsumer::Process_vkCmdPushDescriptorSet2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSet2KHR&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_ppush_descriptor_set_info;
    std::string ppush_descriptor_set_info_struct = GenerateStruct_VkPushDescriptorSetInfo(stream_ppush_descriptor_set_info,
                                                                                          args.pPushDescriptorSetInfo.GetPointer(),
                                                                                          args.pPushDescriptorSetInfo.GetMetaStructPointer(),
                                                                                          *this);
    fprintf(file, "%s", stream_ppush_descriptor_set_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdPushDescriptorSet2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdPushDescriptorSet2KHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            ppush_descriptor_set_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPushDescriptorSet2KHR);
}

void VulkanCppConsumer::Process_vkCmdSetDescriptorBufferOffsets2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDescriptorBufferOffsets2EXT&    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pset_descriptor_buffer_offsets_info;
    std::string pset_descriptor_buffer_offsets_info_struct = GenerateStruct_VkSetDescriptorBufferOffsetsInfoEXT(stream_pset_descriptor_buffer_offsets_info,
                                                                                                                args.pSetDescriptorBufferOffsetsInfo.GetPointer(),
                                                                                                                args.pSetDescriptorBufferOffsetsInfo.GetMetaStructPointer(),
                                                                                                                *this);
    fprintf(file, "%s", stream_pset_descriptor_buffer_offsets_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdSetDescriptorBufferOffsets2EXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDescriptorBufferOffsets2EXT(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pset_descriptor_buffer_offsets_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDescriptorBufferOffsets2EXT);
}
void VulkanCppConsumer::Process_vkCmdCopyMemoryIndirectKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryIndirectKHR&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_memory_indirect_info;
    std::string pcopy_memory_indirect_info_struct = GenerateStruct_VkCopyMemoryIndirectInfoKHR(stream_pcopy_memory_indirect_info,
                                                                                               args.pCopyMemoryIndirectInfo.GetPointer(),
                                                                                               args.pCopyMemoryIndirectInfo.GetMetaStructPointer(),
                                                                                               *this);
    fprintf(file, "%s", stream_pcopy_memory_indirect_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyMemoryIndirectKHR");
    fprintf(file,
            "\t\tloaded_vkCmdCopyMemoryIndirectKHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pcopy_memory_indirect_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyMemoryIndirectKHR);
}

void VulkanCppConsumer::Process_vkCmdCopyMemoryToImageIndirectKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToImageIndirectKHR&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_memory_to_image_indirect_info;
    std::string pcopy_memory_to_image_indirect_info_struct = GenerateStruct_VkCopyMemoryToImageIndirectInfoKHR(stream_pcopy_memory_to_image_indirect_info,
                                                                                                               args.pCopyMemoryToImageIndirectInfo.GetPointer(),
                                                                                                               args.pCopyMemoryToImageIndirectInfo.GetMetaStructPointer(),
                                                                                                               *this);
    fprintf(file, "%s", stream_pcopy_memory_to_image_indirect_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyMemoryToImageIndirectKHR");
    fprintf(file,
            "\t\tloaded_vkCmdCopyMemoryToImageIndirectKHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pcopy_memory_to_image_indirect_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyMemoryToImageIndirectKHR);
}
void VulkanCppConsumer::Process_vkGetDeviceFaultDebugInfoKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceFaultDebugInfoKHR&           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pdebug_info_name = "NULL";
    if (!args.pDebugInfo.IsNull()) {
        pdebug_info_name = "pDebugInfo_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDeviceFaultDebugInfoKHR %s = {};\n", pdebug_info_name.c_str());
        pdebug_info_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetDeviceFaultDebugInfoKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDeviceFaultDebugInfoKHR(%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pdebug_info_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceFaultDebugInfoKHR);
}

void VulkanCppConsumer::Process_vkGetDeviceFaultReportsKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceFaultReportsKHR&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pfault_counts_name = "NULL";
    if (!args.pFaultCounts.IsNull()) {
        pfault_counts_name = "pFaultCounts_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pfault_counts_name.c_str(), util::ToString(*args.pFaultCounts.GetPointer()).c_str());
        pfault_counts_name.insert(0, "&");
    }
    std::string pfault_info_name = "NULL";
    if (!args.pFaultInfo.IsNull()) {
        const uint32_t* in_pfault_counts = args.pFaultCounts.GetPointer();
        pfault_info_name = "pFaultInfo_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDeviceFaultInfoKHR %s[%d] = {};\n", pfault_info_name.c_str(), *in_pfault_counts);
    }
    pfn_loader_.AddMethodName("vkGetDeviceFaultReportsKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDeviceFaultReportsKHR(%s, %" PRIu64 "UL, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            args.timeout,
            pfault_counts_name.c_str(),
            pfault_info_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceFaultReportsKHR);
}
void VulkanCppConsumer::Process_vkCmdEndRendering2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdEndRendering2KHR&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_prendering_end_info;
    std::string prendering_end_info_struct = GenerateStruct_VkRenderingEndInfoKHR(stream_prendering_end_info,
                                                                                  args.pRenderingEndInfo.GetPointer(),
                                                                                  args.pRenderingEndInfo.GetMetaStructPointer(),
                                                                                  *this);
    fprintf(file, "%s", stream_prendering_end_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdEndRendering2KHR");
    fprintf(file,
            "\t\tloaded_vkCmdEndRendering2KHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            prendering_end_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRendering2KHR);
}
void VulkanCppConsumer::Process_vkFrameBoundaryANDROID(
    const ApiCallInfo&                          call_info,
    args::FrameBoundaryANDROID&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkFrameBoundaryANDROID");
    fprintf(file,
            "\t\tloaded_vkFrameBoundaryANDROID(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.semaphore).c_str(),
            this->GetHandle(args.image).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkFrameBoundaryANDROID);
}
void VulkanCppConsumer::Process_vkCreateDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    args::CreateDebugReportCallbackEXT&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkDebugReportCallbackCreateInfoEXT(stream_pcreate_info,
                                                                                        args.pCreateInfo.GetPointer(),
                                                                                        args.pCreateInfo.GetMetaStructPointer(),
                                                                                        *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pcallback_name = "pCallback_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT));
    AddKnownVariables("VkDebugReportCallbackEXT", pcallback_name, args.pCallback.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pcallback_name,
                         args.pCallback.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateDebugReportCallbackEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateDebugReportCallbackEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.instance).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pcallback_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT);
}

void VulkanCppConsumer::Process_vkDebugReportMessageEXT(
    const ApiCallInfo&                          call_info,
    args::DebugReportMessageEXT&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDebugReportMessageEXT");
    fprintf(file,
            "\t\tloaded_vkDebugReportMessageEXT(%s, %s, %s, %" PRIu64 "UL, %" PRIu64 ", %d, %p, %p);\n",
            this->GetHandle(args.instance).c_str(),
            util::ToString<VkDebugReportFlagsEXT>(args.flags).c_str(),
            util::ToString<VkDebugReportObjectTypeEXT>(args.objectType).c_str(),
            args.object,
            util::platform::SizeTtoUint64(args.location),
            args.messageCode,
            args.pLayerPrefix.GetPointer(),
            args.pMessage.GetPointer());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDebugReportMessageEXT);
}

void VulkanCppConsumer::Process_vkDestroyDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyDebugReportCallbackEXT&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyDebugReportCallbackEXT");
    fprintf(file,
            "\t\tloaded_vkDestroyDebugReportCallbackEXT(%s, %s, %s);\n",
            this->GetHandle(args.instance).c_str(),
            this->GetHandle(args.callback).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT);
}
void VulkanCppConsumer::Process_vkCmdDebugMarkerBeginEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDebugMarkerBeginEXT&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pmarker_info;
    std::string pmarker_info_struct = GenerateStruct_VkDebugMarkerMarkerInfoEXT(stream_pmarker_info,
                                                                                args.pMarkerInfo.GetPointer(),
                                                                                args.pMarkerInfo.GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_pmarker_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdDebugMarkerBeginEXT");
    fprintf(file,
            "\t\tloaded_vkCmdDebugMarkerBeginEXT(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pmarker_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT);
}

void VulkanCppConsumer::Process_vkCmdDebugMarkerEndEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDebugMarkerEndEXT&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDebugMarkerEndEXT");
    fprintf(file,
            "\t\tloaded_vkCmdDebugMarkerEndEXT(%s);\n",
            this->GetHandle(args.commandBuffer).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT);
}

void VulkanCppConsumer::Process_vkCmdDebugMarkerInsertEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDebugMarkerInsertEXT&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pmarker_info;
    std::string pmarker_info_struct = GenerateStruct_VkDebugMarkerMarkerInfoEXT(stream_pmarker_info,
                                                                                args.pMarkerInfo.GetPointer(),
                                                                                args.pMarkerInfo.GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_pmarker_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdDebugMarkerInsertEXT");
    fprintf(file,
            "\t\tloaded_vkCmdDebugMarkerInsertEXT(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pmarker_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT);
}

void VulkanCppConsumer::Process_vkDebugMarkerSetObjectNameEXT(
    const ApiCallInfo&                          call_info,
    args::DebugMarkerSetObjectNameEXT&          args)
{
    Generate_vkDebugMarkerSetObjectNameEXT(args);
    Post_APICall(format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT);
}

void VulkanCppConsumer::Process_vkDebugMarkerSetObjectTagEXT(
    const ApiCallInfo&                          call_info,
    args::DebugMarkerSetObjectTagEXT&           args)
{
    Generate_vkDebugMarkerSetObjectTagEXT(args);
    Post_APICall(format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT);
}
void VulkanCppConsumer::Process_vkCmdBeginQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginQueryIndexedEXT&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdBeginQueryIndexedEXT");
    fprintf(file,
            "\t\tloaded_vkCmdBeginQueryIndexedEXT(%s, %s, %u, %s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.queryPool).c_str(),
            args.query,
            util::ToString<VkQueryControlFlags>(args.flags).c_str(),
            args.index);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT);
}

void VulkanCppConsumer::Process_vkCmdBeginTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginTransformFeedbackEXT&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcounter_buffers_array = "NULL";
    std::string pcounter_buffers_values = toStringJoin(args.pCounterBuffers.GetPointer(),
                                                       args.pCounterBuffers.GetPointer() + args.counterBufferCount,
                                                       [&](const format::HandleId current) { return this->GetHandle(current); },
                                                       ", ");
    if (args.counterBufferCount == 1 && pcounter_buffers_values != "VK_NULL_HANDLE") {
        pcounter_buffers_array = "&" + pcounter_buffers_values;
    } else if (args.counterBufferCount > 1) {
        pcounter_buffers_array = "pcounter_buffers_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkBuffer %s[] = { %s };\n", pcounter_buffers_array.c_str(), pcounter_buffers_values.c_str());
    }
    std::string pcounter_buffer_offsets_array = "pCounterBufferOffsets_" + std::to_string(this->GetNextId());
    if (args.counterBufferCount > 0 && args.pCounterBufferOffsets.GetPointer() != nullptr) {
        std::string pcounter_buffer_offsets_values = toStringJoin(args.pCounterBufferOffsets.GetPointer(),
                                                                  args.pCounterBufferOffsets.GetPointer() + args.counterBufferCount,
                                                                  [&](const auto current) { return std::to_string(current) + "UL"; },
                                                                  ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", pcounter_buffer_offsets_array.c_str(), pcounter_buffer_offsets_values.c_str());
    } else {
        pcounter_buffer_offsets_array = "NULL";
    }
    pfn_loader_.AddMethodName("vkCmdBeginTransformFeedbackEXT");
    fprintf(file,
            "\t\tloaded_vkCmdBeginTransformFeedbackEXT(%s, %u, %u, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.firstCounterBuffer,
            args.counterBufferCount,
            pcounter_buffers_array.c_str(),
            pcounter_buffer_offsets_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT);
}

void VulkanCppConsumer::Process_vkCmdBindTransformFeedbackBuffersEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindTransformFeedbackBuffersEXT&   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pbuffers_array = "NULL";
    std::string pbuffers_values = toStringJoin(args.pBuffers.GetPointer(),
                                               args.pBuffers.GetPointer() + args.bindingCount,
                                               [&](const format::HandleId current) { return this->GetHandle(current); },
                                               ", ");
    if (args.bindingCount == 1 && pbuffers_values != "VK_NULL_HANDLE") {
        pbuffers_array = "&" + pbuffers_values;
    } else if (args.bindingCount > 1) {
        pbuffers_array = "pbuffers_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkBuffer %s[] = { %s };\n", pbuffers_array.c_str(), pbuffers_values.c_str());
    }
    std::string poffsets_array = "pOffsets_" + std::to_string(this->GetNextId());
    if (args.bindingCount > 0) {
        std::string poffsets_values = toStringJoin(args.pOffsets.GetPointer(),
                                                   args.pOffsets.GetPointer() + args.bindingCount,
                                                   [&](const auto current) { return std::to_string(current) + "UL"; },
                                                   ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", poffsets_array.c_str(), poffsets_values.c_str());
    } else {
        poffsets_array = "NULL";
    }
    std::string psizes_array = "pSizes_" + std::to_string(this->GetNextId());
    if (args.bindingCount > 0 && args.pSizes.GetPointer() != nullptr) {
        std::string psizes_values = toStringJoin(args.pSizes.GetPointer(),
                                                 args.pSizes.GetPointer() + args.bindingCount,
                                                 [&](const auto current) { return std::to_string(current) + "UL"; },
                                                 ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", psizes_array.c_str(), psizes_values.c_str());
    } else {
        psizes_array = "NULL";
    }
    pfn_loader_.AddMethodName("vkCmdBindTransformFeedbackBuffersEXT");
    fprintf(file,
            "\t\tloaded_vkCmdBindTransformFeedbackBuffersEXT(%s, %u, %u, %s, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.firstBinding,
            args.bindingCount,
            pbuffers_array.c_str(),
            poffsets_array.c_str(),
            psizes_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT);
}

void VulkanCppConsumer::Process_vkCmdDrawIndirectByteCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectByteCountEXT&          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawIndirectByteCountEXT");
    fprintf(file,
            "\t\tloaded_vkCmdDrawIndirectByteCountEXT(%s, %u, %u, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.instanceCount,
            args.firstInstance,
            this->GetHandle(args.counterBuffer).c_str(),
            args.counterBufferOffset,
            args.counterOffset,
            args.vertexStride);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT);
}

void VulkanCppConsumer::Process_vkCmdEndQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndQueryIndexedEXT&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdEndQueryIndexedEXT");
    fprintf(file,
            "\t\tloaded_vkCmdEndQueryIndexedEXT(%s, %s, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.queryPool).c_str(),
            args.query,
            args.index);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT);
}

void VulkanCppConsumer::Process_vkCmdEndTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndTransformFeedbackEXT&           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcounter_buffers_array = "NULL";
    std::string pcounter_buffers_values = toStringJoin(args.pCounterBuffers.GetPointer(),
                                                       args.pCounterBuffers.GetPointer() + args.counterBufferCount,
                                                       [&](const format::HandleId current) { return this->GetHandle(current); },
                                                       ", ");
    if (args.counterBufferCount == 1 && pcounter_buffers_values != "VK_NULL_HANDLE") {
        pcounter_buffers_array = "&" + pcounter_buffers_values;
    } else if (args.counterBufferCount > 1) {
        pcounter_buffers_array = "pcounter_buffers_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkBuffer %s[] = { %s };\n", pcounter_buffers_array.c_str(), pcounter_buffers_values.c_str());
    }
    std::string pcounter_buffer_offsets_array = "pCounterBufferOffsets_" + std::to_string(this->GetNextId());
    if (args.counterBufferCount > 0 && args.pCounterBufferOffsets.GetPointer() != nullptr) {
        std::string pcounter_buffer_offsets_values = toStringJoin(args.pCounterBufferOffsets.GetPointer(),
                                                                  args.pCounterBufferOffsets.GetPointer() + args.counterBufferCount,
                                                                  [&](const auto current) { return std::to_string(current) + "UL"; },
                                                                  ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", pcounter_buffer_offsets_array.c_str(), pcounter_buffer_offsets_values.c_str());
    } else {
        pcounter_buffer_offsets_array = "NULL";
    }
    pfn_loader_.AddMethodName("vkCmdEndTransformFeedbackEXT");
    fprintf(file,
            "\t\tloaded_vkCmdEndTransformFeedbackEXT(%s, %u, %u, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.firstCounterBuffer,
            args.counterBufferCount,
            pcounter_buffers_array.c_str(),
            pcounter_buffer_offsets_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT);
}
void VulkanCppConsumer::Process_vkGetDeviceCombinedImageSamplerIndexNVX(
    const ApiCallInfo&                          call_info,
    args::GetDeviceCombinedImageSamplerIndexNVX& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkGetDeviceCombinedImageSamplerIndexNVX");
    fprintf(file,
            "\t\tloaded_vkGetDeviceCombinedImageSamplerIndexNVX(%s, %" PRIu64 "UL, %" PRIu64 "UL);\n",
            this->GetHandle(args.device).c_str(),
            args.imageViewIndex,
            args.samplerIndex);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceCombinedImageSamplerIndexNVX);
}

void VulkanCppConsumer::Process_vkGetImageViewAddressNVX(
    const ApiCallInfo&                          call_info,
    args::GetImageViewAddressNVX&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkImageViewAddressPropertiesNVX %s = {};\n", pproperties_name.c_str());
        pproperties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetImageViewAddressNVX");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetImageViewAddressNVX(%s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.imageView).c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageViewAddressNVX);
}

void VulkanCppConsumer::Process_vkGetImageViewHandle64NVX(
    const ApiCallInfo&                          call_info,
    args::GetImageViewHandle64NVX&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkImageViewHandleInfoNVX(stream_pinfo,
                                                                       args.pInfo.GetPointer(),
                                                                       args.pInfo.GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkGetImageViewHandle64NVX");
    fprintf(file,
            "\t\tloaded_vkGetImageViewHandle64NVX(%s, &%s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageViewHandle64NVX);
}

void VulkanCppConsumer::Process_vkGetImageViewHandleNVX(
    const ApiCallInfo&                          call_info,
    args::GetImageViewHandleNVX&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkImageViewHandleInfoNVX(stream_pinfo,
                                                                       args.pInfo.GetPointer(),
                                                                       args.pInfo.GetMetaStructPointer(),
                                                                       *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkGetImageViewHandleNVX");
    fprintf(file,
            "\t\tloaded_vkGetImageViewHandleNVX(%s, &%s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageViewHandleNVX);
}
void VulkanCppConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCountAMD&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawIndexedIndirectCountAMD");
    fprintf(file,
            "\t\tloaded_vkCmdDrawIndexedIndirectCountAMD(%s, %s, %" PRIu64 "UL, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.buffer).c_str(),
            args.offset,
            this->GetHandle(args.countBuffer).c_str(),
            args.countBufferOffset,
            args.maxDrawCount,
            args.stride);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD);
}

void VulkanCppConsumer::Process_vkCmdDrawIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCountAMD&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawIndirectCountAMD");
    fprintf(file,
            "\t\tloaded_vkCmdDrawIndirectCountAMD(%s, %s, %" PRIu64 "UL, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.buffer).c_str(),
            args.offset,
            this->GetHandle(args.countBuffer).c_str(),
            args.countBufferOffset,
            args.maxDrawCount,
            args.stride);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD);
}
void VulkanCppConsumer::Process_vkGetShaderInfoAMD(
    const ApiCallInfo&                          call_info,
    args::GetShaderInfoAMD&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pinfo_size_name = "NULL";
    if (!args.pInfoSize.IsNull()) {
        pinfo_size_name = "pInfoSize_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tsize_t %s = %s;\n", pinfo_size_name.c_str(), util::ToString(*args.pInfoSize.GetPointer()).c_str());
        pinfo_size_name.insert(0, "&");
    }
    std::string pinfo_name = "NULL";
    if (!args.pInfo.IsNull()) {
        size_t* in_pinfo_size = args.pInfoSize.GetPointer();
        pinfo_name = "pInfo_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint8_t %s[%" PRIu64 "] = {};\n", pinfo_name.c_str(), util::platform::SizeTtoUint64(*in_pinfo_size));
    }
    pfn_loader_.AddMethodName("vkGetShaderInfoAMD");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetShaderInfoAMD(%s, %s, %s, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.pipeline).c_str(),
            util::ToString<VkShaderStageFlagBits>(args.shaderStage).c_str(),
            util::ToString<VkShaderInfoTypeAMD>(args.infoType).c_str(),
            pinfo_size_name.c_str(),
            pinfo_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetShaderInfoAMD);
}
void VulkanCppConsumer::Process_vkCreateStreamDescriptorSurfaceGGP(
    const ApiCallInfo&                          call_info,
    args::CreateStreamDescriptorSurfaceGGP&     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkStreamDescriptorSurfaceCreateInfoGGP(stream_pcreate_info,
                                                                                            args.pCreateInfo.GetPointer(),
                                                                                            args.pCreateInfo.GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psurface_name = "pSurface_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", psurface_name, args.pSurface.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(psurface_name,
                         args.pSurface.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateStreamDescriptorSurfaceGGP");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateStreamDescriptorSurfaceGGP(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.instance).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psurface_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP);
}
void VulkanCppConsumer::Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalImageFormatPropertiesNV& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pexternal_image_format_properties_name = "NULL";
    if (!args.pExternalImageFormatProperties.IsNull()) {
        pexternal_image_format_properties_name = "pExternalImageFormatProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkExternalImageFormatPropertiesNV %s = {};\n", pexternal_image_format_properties_name.c_str());
        pexternal_image_format_properties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceExternalImageFormatPropertiesNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(%s, %s, %s, %s, %s, %s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            util::ToString<VkFormat>(args.format).c_str(),
            util::ToString<VkImageType>(args.type).c_str(),
            util::ToString<VkImageTiling>(args.tiling).c_str(),
            util::ToString<VkImageUsageFlags>(args.usage).c_str(),
            util::ToString<VkImageCreateFlags>(args.flags).c_str(),
            util::ToString<VkExternalMemoryHandleTypeFlagsNV>(args.externalHandleType).c_str(),
            pexternal_image_format_properties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV);
}
void VulkanCppConsumer::Process_vkGetMemoryWin32HandleNV(
    const ApiCallInfo&                          call_info,
    args::GetMemoryWin32HandleNV&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string phandle_name = "NULL";
    if (!args.pHandle.IsNull()) {
        phandle_name = "pHandle_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint8_t* %s = %s;\n", phandle_name.c_str(), util::ToString(*args.pHandle.GetPointer()).c_str());
        phandle_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetMemoryWin32HandleNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetMemoryWin32HandleNV(%s, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.memory).c_str(),
            util::ToString<VkExternalMemoryHandleTypeFlagsNV>(args.handleType).c_str(),
            phandle_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV);
}
void VulkanCppConsumer::Process_vkCreateViSurfaceNN(
    const ApiCallInfo&                          call_info,
    args::CreateViSurfaceNN&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkViSurfaceCreateInfoNN(stream_pcreate_info,
                                                                             args.pCreateInfo.GetPointer(),
                                                                             args.pCreateInfo.GetMetaStructPointer(),
                                                                             *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psurface_name = "pSurface_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", psurface_name, args.pSurface.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(psurface_name,
                         args.pSurface.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateViSurfaceNN");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateViSurfaceNN(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.instance).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psurface_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateViSurfaceNN);
}
void VulkanCppConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginConditionalRenderingEXT&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pconditional_rendering_begin;
    std::string pconditional_rendering_begin_struct = GenerateStruct_VkConditionalRenderingBeginInfoEXT(stream_pconditional_rendering_begin,
                                                                                                        args.pConditionalRenderingBegin.GetPointer(),
                                                                                                        args.pConditionalRenderingBegin.GetMetaStructPointer(),
                                                                                                        *this);
    fprintf(file, "%s", stream_pconditional_rendering_begin.str().c_str());
    pfn_loader_.AddMethodName("vkCmdBeginConditionalRenderingEXT");
    fprintf(file,
            "\t\tloaded_vkCmdBeginConditionalRenderingEXT(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pconditional_rendering_begin_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT);
}

void VulkanCppConsumer::Process_vkCmdEndConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndConditionalRenderingEXT&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdEndConditionalRenderingEXT");
    fprintf(file,
            "\t\tloaded_vkCmdEndConditionalRenderingEXT(%s);\n",
            this->GetHandle(args.commandBuffer).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT);
}
void VulkanCppConsumer::Process_vkCmdSetViewportWScalingNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportWScalingNV&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pviewport_w_scalings;
    std::string pviewport_w_scalings_array = "NULL";
    PointerPairContainer<decltype(args.pViewportWScalings.GetPointer()), decltype(args.pViewportWScalings.GetMetaStructPointer())> pviewport_w_scalings_pair{ args.pViewportWScalings.GetPointer(), args.pViewportWScalings.GetMetaStructPointer(), args.viewportCount };
    std::string pviewport_w_scalings_names = toStringJoin(pviewport_w_scalings_pair.begin(),
                                                          pviewport_w_scalings_pair.end(),
                                                          [&](auto pair) {{ return GenerateStruct_VkViewportWScalingNV(stream_pviewport_w_scalings, pair.t1, pair.t2, *this); }},
                                                          ", ");
    if (stream_pviewport_w_scalings.str().length() > 0) {
        fprintf(file, "%s", stream_pviewport_w_scalings.str().c_str());
        if (args.viewportCount == 1) {
            pviewport_w_scalings_array = "&" + pviewport_w_scalings_names;
        } else if (args.viewportCount > 1) {
            pviewport_w_scalings_array = "pViewportWScalings_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkViewportWScalingNV %s[] = { %s };\n", pviewport_w_scalings_array.c_str(), pviewport_w_scalings_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdSetViewportWScalingNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetViewportWScalingNV(%s, %u, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.firstViewport,
            args.viewportCount,
            pviewport_w_scalings_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV);
}
void VulkanCppConsumer::Process_vkReleaseDisplayEXT(
    const ApiCallInfo&                          call_info,
    args::ReleaseDisplayEXT&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkReleaseDisplayEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkReleaseDisplayEXT(%s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            this->GetHandle(args.display).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkReleaseDisplayEXT);
}
void VulkanCppConsumer::Process_vkAcquireXlibDisplayEXT(
    const ApiCallInfo&                          call_info,
    args::AcquireXlibDisplayEXT&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string dpy_name = "args.dpy_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tvoid* %s;\n", dpy_name.c_str());
    pfn_loader_.AddMethodName("vkAcquireXlibDisplayEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkAcquireXlibDisplayEXT(%s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            dpy_name.c_str(),
            this->GetHandle(args.display).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT);
}

void VulkanCppConsumer::Process_vkGetRandROutputDisplayEXT(
    const ApiCallInfo&                          call_info,
    args::GetRandROutputDisplayEXT&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string dpy_name = "args.dpy_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tvoid* %s;\n", dpy_name.c_str());
    std::string pdisplay_name = "pDisplay_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DISPLAY_KHR));
    AddKnownVariables("VkDisplayKHR", pdisplay_name, args.pDisplay.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pdisplay_name,
                         args.pDisplay.GetPointer());
    }
    pfn_loader_.AddMethodName("vkGetRandROutputDisplayEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetRandROutputDisplayEXT(%s, %s, %" PRIu64 ", &%s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            dpy_name.c_str(),
            util::platform::SizeTtoUint64(args.rrOutput),
            pdisplay_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT);
}
void VulkanCppConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfaceCapabilities2EXT& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string psurface_capabilities_name = "NULL";
    if (!args.pSurfaceCapabilities.IsNull()) {
        psurface_capabilities_name = "pSurfaceCapabilities_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkSurfaceCapabilities2EXT %s = {};\n", psurface_capabilities_name.c_str());
        psurface_capabilities_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceSurfaceCapabilities2EXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfaceCapabilities2EXT(%s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            this->GetHandle(args.surface).c_str(),
            psurface_capabilities_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT);
}
void VulkanCppConsumer::Process_vkDisplayPowerControlEXT(
    const ApiCallInfo&                          call_info,
    args::DisplayPowerControlEXT&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdisplay_power_info;
    std::string pdisplay_power_info_struct = GenerateStruct_VkDisplayPowerInfoEXT(stream_pdisplay_power_info,
                                                                                  args.pDisplayPowerInfo.GetPointer(),
                                                                                  args.pDisplayPowerInfo.GetMetaStructPointer(),
                                                                                  *this);
    fprintf(file, "%s", stream_pdisplay_power_info.str().c_str());
    pfn_loader_.AddMethodName("vkDisplayPowerControlEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkDisplayPowerControlEXT(%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.display).c_str(),
            pdisplay_power_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDisplayPowerControlEXT);
}

void VulkanCppConsumer::Process_vkGetSwapchainCounterEXT(
    const ApiCallInfo&                          call_info,
    args::GetSwapchainCounterEXT&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcounter_value_name = "NULL";
    if (!args.pCounterValue.IsNull()) {
        pcounter_value_name = "pCounterValue_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint64_t %s = %s;\n", pcounter_value_name.c_str(), util::ToString(*args.pCounterValue.GetPointer()).c_str());
        pcounter_value_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetSwapchainCounterEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetSwapchainCounterEXT(%s, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.swapchain).c_str(),
            util::ToString<VkSurfaceCounterFlagBitsEXT>(args.counter).c_str(),
            pcounter_value_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT);
}

void VulkanCppConsumer::Process_vkRegisterDeviceEventEXT(
    const ApiCallInfo&                          call_info,
    args::RegisterDeviceEventEXT&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdevice_event_info;
    std::string pdevice_event_info_struct = GenerateStruct_VkDeviceEventInfoEXT(stream_pdevice_event_info,
                                                                                args.pDeviceEventInfo.GetPointer(),
                                                                                args.pDeviceEventInfo.GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_pdevice_event_info.str().c_str());
    std::string pfence_name = "pFence_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_FENCE));
    AddKnownVariables("VkFence", pfence_name, args.pFence.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pfence_name,
                         args.pFence.GetPointer());
    }
    pfn_loader_.AddMethodName("vkRegisterDeviceEventEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkRegisterDeviceEventEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pdevice_event_info_struct.c_str(),
            "nullptr",
            pfence_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT);
}

void VulkanCppConsumer::Process_vkRegisterDisplayEventEXT(
    const ApiCallInfo&                          call_info,
    args::RegisterDisplayEventEXT&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdisplay_event_info;
    std::string pdisplay_event_info_struct = GenerateStruct_VkDisplayEventInfoEXT(stream_pdisplay_event_info,
                                                                                  args.pDisplayEventInfo.GetPointer(),
                                                                                  args.pDisplayEventInfo.GetMetaStructPointer(),
                                                                                  *this);
    fprintf(file, "%s", stream_pdisplay_event_info.str().c_str());
    std::string pfence_name = "pFence_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_FENCE));
    AddKnownVariables("VkFence", pfence_name, args.pFence.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pfence_name,
                         args.pFence.GetPointer());
    }
    pfn_loader_.AddMethodName("vkRegisterDisplayEventEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkRegisterDisplayEventEXT(%s, %s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.display).c_str(),
            pdisplay_event_info_struct.c_str(),
            "nullptr",
            pfence_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT);
}
void VulkanCppConsumer::Process_vkGetPastPresentationTimingGOOGLE(
    const ApiCallInfo&                          call_info,
    args::GetPastPresentationTimingGOOGLE&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string ppresentation_timing_count_name = "NULL";
    if (!args.pPresentationTimingCount.IsNull()) {
        ppresentation_timing_count_name = "pPresentationTimingCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", ppresentation_timing_count_name.c_str(), util::ToString(*args.pPresentationTimingCount.GetPointer()).c_str());
        ppresentation_timing_count_name.insert(0, "&");
    }
    std::string ppresentation_timings_name = "NULL";
    if (!args.pPresentationTimings.IsNull()) {
        const uint32_t* in_ppresentation_timing_count = args.pPresentationTimingCount.GetPointer();
        ppresentation_timings_name = "pPresentationTimings_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPastPresentationTimingGOOGLE %s[%d] = {};\n", ppresentation_timings_name.c_str(), *in_ppresentation_timing_count);
    }
    pfn_loader_.AddMethodName("vkGetPastPresentationTimingGOOGLE");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPastPresentationTimingGOOGLE(%s, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.swapchain).c_str(),
            ppresentation_timing_count_name.c_str(),
            ppresentation_timings_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE);
}

void VulkanCppConsumer::Process_vkGetRefreshCycleDurationGOOGLE(
    const ApiCallInfo&                          call_info,
    args::GetRefreshCycleDurationGOOGLE&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pdisplay_timing_properties_name = "NULL";
    if (!args.pDisplayTimingProperties.IsNull()) {
        pdisplay_timing_properties_name = "pDisplayTimingProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkRefreshCycleDurationGOOGLE %s = {};\n", pdisplay_timing_properties_name.c_str());
        pdisplay_timing_properties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetRefreshCycleDurationGOOGLE");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetRefreshCycleDurationGOOGLE(%s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.swapchain).c_str(),
            pdisplay_timing_properties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE);
}
void VulkanCppConsumer::Process_vkCmdSetDiscardRectangleEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDiscardRectangleEXT&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdiscard_rectangles;
    std::string pdiscard_rectangles_array = "NULL";
    PointerPairContainer<decltype(args.pDiscardRectangles.GetPointer()), decltype(args.pDiscardRectangles.GetMetaStructPointer())> pdiscard_rectangles_pair{ args.pDiscardRectangles.GetPointer(), args.pDiscardRectangles.GetMetaStructPointer(), args.discardRectangleCount };
    std::string pdiscard_rectangles_names = toStringJoin(pdiscard_rectangles_pair.begin(),
                                                         pdiscard_rectangles_pair.end(),
                                                         [&](auto pair) {{ return GenerateStruct_VkRect2D(stream_pdiscard_rectangles, pair.t1, pair.t2, *this); }},
                                                         ", ");
    if (stream_pdiscard_rectangles.str().length() > 0) {
        fprintf(file, "%s", stream_pdiscard_rectangles.str().c_str());
        if (args.discardRectangleCount == 1) {
            pdiscard_rectangles_array = "&" + pdiscard_rectangles_names;
        } else if (args.discardRectangleCount > 1) {
            pdiscard_rectangles_array = "pDiscardRectangles_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkRect2D %s[] = { %s };\n", pdiscard_rectangles_array.c_str(), pdiscard_rectangles_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdSetDiscardRectangleEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDiscardRectangleEXT(%s, %u, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.firstDiscardRectangle,
            args.discardRectangleCount,
            pdiscard_rectangles_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDiscardRectangleEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDiscardRectangleEnableEXT&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetDiscardRectangleEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDiscardRectangleEnableEXT(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.discardRectangleEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDiscardRectangleModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDiscardRectangleModeEXT&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetDiscardRectangleModeEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDiscardRectangleModeEXT(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkDiscardRectangleModeEXT>(args.discardRectangleMode).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT);
}
void VulkanCppConsumer::Process_vkSetHdrMetadataEXT(
    const ApiCallInfo&                          call_info,
    args::SetHdrMetadataEXT&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pswapchains_array = "NULL";
    std::string pswapchains_values = toStringJoin(args.pSwapchains.GetPointer(),
                                                  args.pSwapchains.GetPointer() + args.swapchainCount,
                                                  [&](const format::HandleId current) { return this->GetHandle(current); },
                                                  ", ");
    if (args.swapchainCount == 1 && pswapchains_values != "VK_NULL_HANDLE") {
        pswapchains_array = "&" + pswapchains_values;
    } else if (args.swapchainCount > 1) {
        pswapchains_array = "pswapchains_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkSwapchainKHR %s[] = { %s };\n", pswapchains_array.c_str(), pswapchains_values.c_str());
    }
    std::stringstream stream_pmetadata;
    std::string pmetadata_array = "NULL";
    PointerPairContainer<decltype(args.pMetadata.GetPointer()), decltype(args.pMetadata.GetMetaStructPointer())> pmetadata_pair{ args.pMetadata.GetPointer(), args.pMetadata.GetMetaStructPointer(), args.swapchainCount };
    std::string pmetadata_names = toStringJoin(pmetadata_pair.begin(),
                                               pmetadata_pair.end(),
                                               [&](auto pair) {{ return GenerateStruct_VkHdrMetadataEXT(stream_pmetadata, pair.t1, pair.t2, *this); }},
                                               ", ");
    if (stream_pmetadata.str().length() > 0) {
        fprintf(file, "%s", stream_pmetadata.str().c_str());
        if (args.swapchainCount == 1) {
            pmetadata_array = "&" + pmetadata_names;
        } else if (args.swapchainCount > 1) {
            pmetadata_array = "pMetadata_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkHdrMetadataEXT %s[] = { %s };\n", pmetadata_array.c_str(), pmetadata_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkSetHdrMetadataEXT");
    fprintf(file,
            "\t\tloaded_vkSetHdrMetadataEXT(%s, %u, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            args.swapchainCount,
            pswapchains_array.c_str(),
            pmetadata_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSetHdrMetadataEXT);
}
void VulkanCppConsumer::Process_vkCreateIOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    args::CreateIOSSurfaceMVK&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkIOSSurfaceCreateInfoMVK(stream_pcreate_info,
                                                                               args.pCreateInfo.GetPointer(),
                                                                               args.pCreateInfo.GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psurface_name = "pSurface_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", psurface_name, args.pSurface.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(psurface_name,
                         args.pSurface.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateIOSSurfaceMVK");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateIOSSurfaceMVK(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.instance).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psurface_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK);
}
void VulkanCppConsumer::Process_vkCreateMacOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    args::CreateMacOSSurfaceMVK&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkMacOSSurfaceCreateInfoMVK(stream_pcreate_info,
                                                                                 args.pCreateInfo.GetPointer(),
                                                                                 args.pCreateInfo.GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psurface_name = "pSurface_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", psurface_name, args.pSurface.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(psurface_name,
                         args.pSurface.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateMacOSSurfaceMVK");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateMacOSSurfaceMVK(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.instance).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psurface_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK);
}
void VulkanCppConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginDebugUtilsLabelEXT&           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_plabel_info;
    std::string plabel_info_struct = GenerateStruct_VkDebugUtilsLabelEXT(stream_plabel_info,
                                                                         args.pLabelInfo.GetPointer(),
                                                                         args.pLabelInfo.GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "%s", stream_plabel_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdBeginDebugUtilsLabelEXT");
    fprintf(file,
            "\t\tloaded_vkCmdBeginDebugUtilsLabelEXT(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            plabel_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT);
}

void VulkanCppConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndDebugUtilsLabelEXT&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdEndDebugUtilsLabelEXT");
    fprintf(file,
            "\t\tloaded_vkCmdEndDebugUtilsLabelEXT(%s);\n",
            this->GetHandle(args.commandBuffer).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT);
}

void VulkanCppConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::CmdInsertDebugUtilsLabelEXT&          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_plabel_info;
    std::string plabel_info_struct = GenerateStruct_VkDebugUtilsLabelEXT(stream_plabel_info,
                                                                         args.pLabelInfo.GetPointer(),
                                                                         args.pLabelInfo.GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "%s", stream_plabel_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdInsertDebugUtilsLabelEXT");
    fprintf(file,
            "\t\tloaded_vkCmdInsertDebugUtilsLabelEXT(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            plabel_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT);
}

void VulkanCppConsumer::Process_vkCreateDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    args::CreateDebugUtilsMessengerEXT&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkDebugUtilsMessengerCreateInfoEXT(stream_pcreate_info,
                                                                                        args.pCreateInfo.GetPointer(),
                                                                                        args.pCreateInfo.GetMetaStructPointer(),
                                                                                        *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pmessenger_name = "pMessenger_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT));
    AddKnownVariables("VkDebugUtilsMessengerEXT", pmessenger_name, args.pMessenger.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pmessenger_name,
                         args.pMessenger.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateDebugUtilsMessengerEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateDebugUtilsMessengerEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.instance).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pmessenger_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT);
}

void VulkanCppConsumer::Process_vkDestroyDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyDebugUtilsMessengerEXT&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyDebugUtilsMessengerEXT");
    fprintf(file,
            "\t\tloaded_vkDestroyDebugUtilsMessengerEXT(%s, %s, %s);\n",
            this->GetHandle(args.instance).c_str(),
            this->GetHandle(args.messenger).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT);
}

void VulkanCppConsumer::Process_vkQueueBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::QueueBeginDebugUtilsLabelEXT&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_plabel_info;
    std::string plabel_info_struct = GenerateStruct_VkDebugUtilsLabelEXT(stream_plabel_info,
                                                                         args.pLabelInfo.GetPointer(),
                                                                         args.pLabelInfo.GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "%s", stream_plabel_info.str().c_str());
    pfn_loader_.AddMethodName("vkQueueBeginDebugUtilsLabelEXT");
    fprintf(file,
            "\t\tloaded_vkQueueBeginDebugUtilsLabelEXT(%s, &%s);\n",
            this->GetHandle(args.queue).c_str(),
            plabel_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT);
}

void VulkanCppConsumer::Process_vkQueueEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::QueueEndDebugUtilsLabelEXT&           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkQueueEndDebugUtilsLabelEXT");
    fprintf(file,
            "\t\tloaded_vkQueueEndDebugUtilsLabelEXT(%s);\n",
            this->GetHandle(args.queue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT);
}

void VulkanCppConsumer::Process_vkQueueInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::QueueInsertDebugUtilsLabelEXT&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_plabel_info;
    std::string plabel_info_struct = GenerateStruct_VkDebugUtilsLabelEXT(stream_plabel_info,
                                                                         args.pLabelInfo.GetPointer(),
                                                                         args.pLabelInfo.GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "%s", stream_plabel_info.str().c_str());
    pfn_loader_.AddMethodName("vkQueueInsertDebugUtilsLabelEXT");
    fprintf(file,
            "\t\tloaded_vkQueueInsertDebugUtilsLabelEXT(%s, &%s);\n",
            this->GetHandle(args.queue).c_str(),
            plabel_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT);
}

void VulkanCppConsumer::Process_vkSetDebugUtilsObjectNameEXT(
    const ApiCallInfo&                          call_info,
    args::SetDebugUtilsObjectNameEXT&           args)
{
    Generate_vkSetDebugUtilsObjectNameEXT(args);
    Post_APICall(format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT);
}

void VulkanCppConsumer::Process_vkSetDebugUtilsObjectTagEXT(
    const ApiCallInfo&                          call_info,
    args::SetDebugUtilsObjectTagEXT&            args)
{
    Generate_vkSetDebugUtilsObjectTagEXT(args);
    Post_APICall(format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT);
}

void VulkanCppConsumer::Process_vkSubmitDebugUtilsMessageEXT(
    const ApiCallInfo&                          call_info,
    args::SubmitDebugUtilsMessageEXT&           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcallback_data;
    std::string pcallback_data_struct = GenerateStruct_VkDebugUtilsMessengerCallbackDataEXT(stream_pcallback_data,
                                                                                            args.pCallbackData.GetPointer(),
                                                                                            args.pCallbackData.GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pcallback_data.str().c_str());
    pfn_loader_.AddMethodName("vkSubmitDebugUtilsMessageEXT");
    fprintf(file,
            "\t\tloaded_vkSubmitDebugUtilsMessageEXT(%s, %s, %s, &%s);\n",
            this->GetHandle(args.instance).c_str(),
            util::ToString<VkDebugUtilsMessageSeverityFlagBitsEXT>(args.messageSeverity).c_str(),
            util::ToString<VkDebugUtilsMessageTypeFlagsEXT>(args.messageTypes).c_str(),
            pcallback_data_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT);
}
void VulkanCppConsumer::Process_vkGetAndroidHardwareBufferPropertiesANDROID(
    const ApiCallInfo&                          call_info,
    args::GetAndroidHardwareBufferPropertiesANDROID& args)
{
    Generate_vkGetAndroidHardwareBufferPropertiesANDROID(args);
    Post_APICall(format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID);
}

void VulkanCppConsumer::Process_vkGetMemoryAndroidHardwareBufferANDROID(
    const ApiCallInfo&                          call_info,
    args::GetMemoryAndroidHardwareBufferANDROID& args)
{
    Generate_vkGetMemoryAndroidHardwareBufferANDROID(args);
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID);
}
void VulkanCppConsumer::Process_vkCmdBeginGpaSampleAMD(
    const ApiCallInfo&                          call_info,
    args::CmdBeginGpaSampleAMD&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pgpa_sample_begin_info;
    std::string pgpa_sample_begin_info_struct = GenerateStruct_VkGpaSampleBeginInfoAMD(stream_pgpa_sample_begin_info,
                                                                                       args.pGpaSampleBeginInfo.GetPointer(),
                                                                                       args.pGpaSampleBeginInfo.GetMetaStructPointer(),
                                                                                       *this);
    fprintf(file, "%s", stream_pgpa_sample_begin_info.str().c_str());
    std::string psample_i_d_name = "NULL";
    if (!args.pSampleID.IsNull()) {
        psample_i_d_name = "pSampleID_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", psample_i_d_name.c_str(), util::ToString(*args.pSampleID.GetPointer()).c_str());
        psample_i_d_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkCmdBeginGpaSampleAMD");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCmdBeginGpaSampleAMD(%s, %s, &%s, %s), %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.gpaSession).c_str(),
            pgpa_sample_begin_info_struct.c_str(),
            psample_i_d_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginGpaSampleAMD);
}

void VulkanCppConsumer::Process_vkCmdBeginGpaSessionAMD(
    const ApiCallInfo&                          call_info,
    args::CmdBeginGpaSessionAMD&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdBeginGpaSessionAMD");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCmdBeginGpaSessionAMD(%s, %s), %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.gpaSession).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginGpaSessionAMD);
}

void VulkanCppConsumer::Process_vkCmdCopyGpaSessionResultsAMD(
    const ApiCallInfo&                          call_info,
    args::CmdCopyGpaSessionResultsAMD&          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdCopyGpaSessionResultsAMD");
    fprintf(file,
            "\t\tloaded_vkCmdCopyGpaSessionResultsAMD(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.gpaSession).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyGpaSessionResultsAMD);
}

void VulkanCppConsumer::Process_vkCmdEndGpaSampleAMD(
    const ApiCallInfo&                          call_info,
    args::CmdEndGpaSampleAMD&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdEndGpaSampleAMD");
    fprintf(file,
            "\t\tloaded_vkCmdEndGpaSampleAMD(%s, %s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.gpaSession).c_str(),
            args.sampleID);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndGpaSampleAMD);
}

void VulkanCppConsumer::Process_vkCmdEndGpaSessionAMD(
    const ApiCallInfo&                          call_info,
    args::CmdEndGpaSessionAMD&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdEndGpaSessionAMD");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCmdEndGpaSessionAMD(%s, %s), %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.gpaSession).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndGpaSessionAMD);
}

void VulkanCppConsumer::Process_vkCreateGpaSessionAMD(
    const ApiCallInfo&                          call_info,
    args::CreateGpaSessionAMD&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkGpaSessionCreateInfoAMD(stream_pcreate_info,
                                                                               args.pCreateInfo.GetPointer(),
                                                                               args.pCreateInfo.GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pgpa_session_name = "pGpaSession_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_GPA_SESSION_AMD));
    AddKnownVariables("VkGpaSessionAMD", pgpa_session_name, args.pGpaSession.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pgpa_session_name,
                         args.pGpaSession.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateGpaSessionAMD");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateGpaSessionAMD(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pgpa_session_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateGpaSessionAMD);
}

void VulkanCppConsumer::Process_vkDestroyGpaSessionAMD(
    const ApiCallInfo&                          call_info,
    args::DestroyGpaSessionAMD&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyGpaSessionAMD");
    fprintf(file,
            "\t\tloaded_vkDestroyGpaSessionAMD(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.gpaSession).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyGpaSessionAMD);
}

void VulkanCppConsumer::Process_vkGetGpaDeviceClockInfoAMD(
    const ApiCallInfo&                          call_info,
    args::GetGpaDeviceClockInfoAMD&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pinfo_name = "NULL";
    if (!args.pInfo.IsNull()) {
        pinfo_name = "pInfo_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkGpaDeviceGetClockInfoAMD %s = {};\n", pinfo_name.c_str());
        pinfo_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetGpaDeviceClockInfoAMD");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetGpaDeviceClockInfoAMD(%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetGpaDeviceClockInfoAMD);
}

void VulkanCppConsumer::Process_vkGetGpaSessionResultsAMD(
    const ApiCallInfo&                          call_info,
    args::GetGpaSessionResultsAMD&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string psize_in_bytes_name = "NULL";
    if (!args.pSizeInBytes.IsNull()) {
        psize_in_bytes_name = "pSizeInBytes_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tsize_t %s = %s;\n", psize_in_bytes_name.c_str(), util::ToString(*args.pSizeInBytes.GetPointer()).c_str());
        psize_in_bytes_name.insert(0, "&");
    }
    std::string pdata_name = "NULL";
    if (!args.pData.IsNull()) {
        size_t* in_psize_in_bytes = args.pSizeInBytes.GetPointer();
        pdata_name = "pData_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint8_t %s[%" PRIu64 "] = {};\n", pdata_name.c_str(), util::platform::SizeTtoUint64(*in_psize_in_bytes));
    }
    pfn_loader_.AddMethodName("vkGetGpaSessionResultsAMD");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetGpaSessionResultsAMD(%s, %s, %u, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.gpaSession).c_str(),
            args.sampleID,
            psize_in_bytes_name.c_str(),
            pdata_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetGpaSessionResultsAMD);
}

void VulkanCppConsumer::Process_vkGetGpaSessionStatusAMD(
    const ApiCallInfo&                          call_info,
    args::GetGpaSessionStatusAMD&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkGetGpaSessionStatusAMD");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetGpaSessionStatusAMD(%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.gpaSession).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetGpaSessionStatusAMD);
}

void VulkanCppConsumer::Process_vkResetGpaSessionAMD(
    const ApiCallInfo&                          call_info,
    args::ResetGpaSessionAMD&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkResetGpaSessionAMD");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkResetGpaSessionAMD(%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.gpaSession).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkResetGpaSessionAMD);
}

void VulkanCppConsumer::Process_vkSetGpaDeviceClockModeAMD(
    const ApiCallInfo&                          call_info,
    args::SetGpaDeviceClockModeAMD&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pinfo_name = "NULL";
    if (!args.pInfo.IsNull()) {
        pinfo_name = "pInfo_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkGpaDeviceClockModeInfoAMD %s = {};\n", pinfo_name.c_str());
        pinfo_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkSetGpaDeviceClockModeAMD");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkSetGpaDeviceClockModeAMD(%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSetGpaDeviceClockModeAMD);
}
void VulkanCppConsumer::Process_vkCmdSetSampleLocationsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetSampleLocationsEXT&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psample_locations_info;
    std::string psample_locations_info_struct = GenerateStruct_VkSampleLocationsInfoEXT(stream_psample_locations_info,
                                                                                        args.pSampleLocationsInfo.GetPointer(),
                                                                                        args.pSampleLocationsInfo.GetMetaStructPointer(),
                                                                                        *this);
    fprintf(file, "%s", stream_psample_locations_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdSetSampleLocationsEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetSampleLocationsEXT(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            psample_locations_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceMultisamplePropertiesEXT& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pmultisample_properties_name = "NULL";
    if (!args.pMultisampleProperties.IsNull()) {
        pmultisample_properties_name = "pMultisampleProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkMultisamplePropertiesEXT %s = {};\n", pmultisample_properties_name.c_str());
        pmultisample_properties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceMultisamplePropertiesEXT");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceMultisamplePropertiesEXT(%s, %s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            util::ToString<VkSampleCountFlagBits>(args.samples).c_str(),
            pmultisample_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT);
}
void VulkanCppConsumer::Process_vkGetImageDrmFormatModifierPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::GetImageDrmFormatModifierPropertiesEXT& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkImageDrmFormatModifierPropertiesEXT %s = {};\n", pproperties_name.c_str());
        pproperties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetImageDrmFormatModifierPropertiesEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetImageDrmFormatModifierPropertiesEXT(%s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.image).c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT);
}
void VulkanCppConsumer::Process_vkCreateValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    args::CreateValidationCacheEXT&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkValidationCacheCreateInfoEXT(stream_pcreate_info,
                                                                                    args.pCreateInfo.GetPointer(),
                                                                                    args.pCreateInfo.GetMetaStructPointer(),
                                                                                    *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pvalidation_cache_name = "pValidationCache_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_VALIDATION_CACHE_EXT));
    AddKnownVariables("VkValidationCacheEXT", pvalidation_cache_name, args.pValidationCache.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pvalidation_cache_name,
                         args.pValidationCache.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateValidationCacheEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateValidationCacheEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pvalidation_cache_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateValidationCacheEXT);
}

void VulkanCppConsumer::Process_vkDestroyValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyValidationCacheEXT&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyValidationCacheEXT");
    fprintf(file,
            "\t\tloaded_vkDestroyValidationCacheEXT(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.validationCache).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT);
}

void VulkanCppConsumer::Process_vkGetValidationCacheDataEXT(
    const ApiCallInfo&                          call_info,
    args::GetValidationCacheDataEXT&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pdata_size_name = "NULL";
    if (!args.pDataSize.IsNull()) {
        pdata_size_name = "pDataSize_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tsize_t %s = %s;\n", pdata_size_name.c_str(), util::ToString(*args.pDataSize.GetPointer()).c_str());
        pdata_size_name.insert(0, "&");
    }
    std::string pdata_name = "NULL";
    if (!args.pData.IsNull()) {
        size_t* in_pdata_size = args.pDataSize.GetPointer();
        pdata_name = "pData_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint8_t %s[%" PRIu64 "] = {};\n", pdata_name.c_str(), util::platform::SizeTtoUint64(*in_pdata_size));
    }
    pfn_loader_.AddMethodName("vkGetValidationCacheDataEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetValidationCacheDataEXT(%s, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.validationCache).c_str(),
            pdata_size_name.c_str(),
            pdata_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT);
}

void VulkanCppConsumer::Process_vkMergeValidationCachesEXT(
    const ApiCallInfo&                          call_info,
    args::MergeValidationCachesEXT&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string psrc_caches_array = "NULL";
    std::string psrc_caches_values = toStringJoin(args.pSrcCaches.GetPointer(),
                                                  args.pSrcCaches.GetPointer() + args.srcCacheCount,
                                                  [&](const format::HandleId current) { return this->GetHandle(current); },
                                                  ", ");
    if (args.srcCacheCount == 1 && psrc_caches_values != "VK_NULL_HANDLE") {
        psrc_caches_array = "&" + psrc_caches_values;
    } else if (args.srcCacheCount > 1) {
        psrc_caches_array = "psrc_caches_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkValidationCacheEXT %s[] = { %s };\n", psrc_caches_array.c_str(), psrc_caches_values.c_str());
    }
    pfn_loader_.AddMethodName("vkMergeValidationCachesEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkMergeValidationCachesEXT(%s, %s, %u, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.dstCache).c_str(),
            args.srcCacheCount,
            psrc_caches_array.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkMergeValidationCachesEXT);
}
void VulkanCppConsumer::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    args::CmdBindShadingRateImageNV&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdBindShadingRateImageNV");
    fprintf(file,
            "\t\tloaded_vkCmdBindShadingRateImageNV(%s, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.imageView).c_str(),
            util::ToString<VkImageLayout>(args.imageLayout).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV);
}

void VulkanCppConsumer::Process_vkCmdSetCoarseSampleOrderNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoarseSampleOrderNV&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcustom_sample_orders;
    std::string pcustom_sample_orders_array = "NULL";
    PointerPairContainer<decltype(args.pCustomSampleOrders.GetPointer()), decltype(args.pCustomSampleOrders.GetMetaStructPointer())> pcustom_sample_orders_pair{ args.pCustomSampleOrders.GetPointer(), args.pCustomSampleOrders.GetMetaStructPointer(), args.customSampleOrderCount };
    std::string pcustom_sample_orders_names = toStringJoin(pcustom_sample_orders_pair.begin(),
                                                           pcustom_sample_orders_pair.end(),
                                                           [&](auto pair) {{ return GenerateStruct_VkCoarseSampleOrderCustomNV(stream_pcustom_sample_orders, pair.t1, pair.t2, *this); }},
                                                           ", ");
    if (stream_pcustom_sample_orders.str().length() > 0) {
        fprintf(file, "%s", stream_pcustom_sample_orders.str().c_str());
        if (args.customSampleOrderCount == 1) {
            pcustom_sample_orders_array = "&" + pcustom_sample_orders_names;
        } else if (args.customSampleOrderCount > 1) {
            pcustom_sample_orders_array = "pCustomSampleOrders_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkCoarseSampleOrderCustomNV %s[] = { %s };\n", pcustom_sample_orders_array.c_str(), pcustom_sample_orders_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdSetCoarseSampleOrderNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetCoarseSampleOrderNV(%s, %s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkCoarseSampleOrderTypeNV>(args.sampleOrderType).c_str(),
            args.customSampleOrderCount,
            pcustom_sample_orders_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV);
}

void VulkanCppConsumer::Process_vkCmdSetViewportShadingRatePaletteNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportShadingRatePaletteNV&   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pshading_rate_palettes;
    std::string pshading_rate_palettes_array = "NULL";
    PointerPairContainer<decltype(args.pShadingRatePalettes.GetPointer()), decltype(args.pShadingRatePalettes.GetMetaStructPointer())> pshading_rate_palettes_pair{ args.pShadingRatePalettes.GetPointer(), args.pShadingRatePalettes.GetMetaStructPointer(), args.viewportCount };
    std::string pshading_rate_palettes_names = toStringJoin(pshading_rate_palettes_pair.begin(),
                                                            pshading_rate_palettes_pair.end(),
                                                            [&](auto pair) {{ return GenerateStruct_VkShadingRatePaletteNV(stream_pshading_rate_palettes, pair.t1, pair.t2, *this); }},
                                                            ", ");
    if (stream_pshading_rate_palettes.str().length() > 0) {
        fprintf(file, "%s", stream_pshading_rate_palettes.str().c_str());
        if (args.viewportCount == 1) {
            pshading_rate_palettes_array = "&" + pshading_rate_palettes_names;
        } else if (args.viewportCount > 1) {
            pshading_rate_palettes_array = "pShadingRatePalettes_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkShadingRatePaletteNV %s[] = { %s };\n", pshading_rate_palettes_array.c_str(), pshading_rate_palettes_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdSetViewportShadingRatePaletteNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetViewportShadingRatePaletteNV(%s, %u, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.firstViewport,
            args.viewportCount,
            pshading_rate_palettes_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV);
}
void VulkanCppConsumer::Process_vkBindAccelerationStructureMemoryNV(
    const ApiCallInfo&                          call_info,
    args::BindAccelerationStructureMemoryNV&    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbind_infos;
    std::string pbind_infos_array = "NULL";
    PointerPairContainer<decltype(args.pBindInfos.GetPointer()), decltype(args.pBindInfos.GetMetaStructPointer())> pbind_infos_pair{ args.pBindInfos.GetPointer(), args.pBindInfos.GetMetaStructPointer(), args.bindInfoCount };
    std::string pbind_infos_names = toStringJoin(pbind_infos_pair.begin(),
                                                 pbind_infos_pair.end(),
                                                 [&](auto pair) {{ return GenerateStruct_VkBindAccelerationStructureMemoryInfoNV(stream_pbind_infos, pair.t1, pair.t2, *this); }},
                                                 ", ");
    if (stream_pbind_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pbind_infos.str().c_str());
        if (args.bindInfoCount == 1) {
            pbind_infos_array = "&" + pbind_infos_names;
        } else if (args.bindInfoCount > 1) {
            pbind_infos_array = "pBindInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBindAccelerationStructureMemoryInfoNV %s[] = { %s };\n", pbind_infos_array.c_str(), pbind_infos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkBindAccelerationStructureMemoryNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkBindAccelerationStructureMemoryNV(%s, %u, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            args.bindInfoCount,
            pbind_infos_array.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV);
}

void VulkanCppConsumer::Process_vkCmdCopyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    args::CmdCopyAccelerationStructureNV&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdCopyAccelerationStructureNV");
    fprintf(file,
            "\t\tloaded_vkCmdCopyAccelerationStructureNV(%s, %s, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.dst).c_str(),
            this->GetHandle(args.src).c_str(),
            util::ToString<VkCopyAccelerationStructureModeKHR>(args.mode).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV);
}

void VulkanCppConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesNV(
    const ApiCallInfo&                          call_info,
    args::CmdWriteAccelerationStructuresPropertiesNV& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pacceleration_structures_array = "NULL";
    std::string pacceleration_structures_values = toStringJoin(args.pAccelerationStructures.GetPointer(),
                                                               args.pAccelerationStructures.GetPointer() + args.accelerationStructureCount,
                                                               [&](const format::HandleId current) { return this->GetHandle(current); },
                                                               ", ");
    if (args.accelerationStructureCount == 1 && pacceleration_structures_values != "VK_NULL_HANDLE") {
        pacceleration_structures_array = "&" + pacceleration_structures_values;
    } else if (args.accelerationStructureCount > 1) {
        pacceleration_structures_array = "pacceleration_structures_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkAccelerationStructureNV %s[] = { %s };\n", pacceleration_structures_array.c_str(), pacceleration_structures_values.c_str());
    }
    pfn_loader_.AddMethodName("vkCmdWriteAccelerationStructuresPropertiesNV");
    fprintf(file,
            "\t\tloaded_vkCmdWriteAccelerationStructuresPropertiesNV(%s, %u, %s, %s, %s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.accelerationStructureCount,
            pacceleration_structures_array.c_str(),
            util::ToString<VkQueryType>(args.queryType).c_str(),
            this->GetHandle(args.queryPool).c_str(),
            args.firstQuery);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV);
}

void VulkanCppConsumer::Process_vkCompileDeferredNV(
    const ApiCallInfo&                          call_info,
    args::CompileDeferredNV&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCompileDeferredNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCompileDeferredNV(%s, %s, %u), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.pipeline).c_str(),
            args.shader,
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCompileDeferredNV);
}

void VulkanCppConsumer::Process_vkCreateRayTracingPipelinesNV(
    const ApiCallInfo&                          call_info,
    args::CreateRayTracingPipelinesNV&          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_infos;
    std::string pcreate_infos_array = "NULL";
    PointerPairContainer<decltype(args.pCreateInfos.GetPointer()), decltype(args.pCreateInfos.GetMetaStructPointer())> pcreate_infos_pair{ args.pCreateInfos.GetPointer(), args.pCreateInfos.GetMetaStructPointer(), args.createInfoCount };
    std::string pcreate_infos_names = toStringJoin(pcreate_infos_pair.begin(),
                                                   pcreate_infos_pair.end(),
                                                   [&](auto pair) {{ return GenerateStruct_VkRayTracingPipelineCreateInfoNV(stream_pcreate_infos, pair.t1, pair.t2, *this); }},
                                                   ", ");
    if (stream_pcreate_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pcreate_infos.str().c_str());
        if (args.createInfoCount == 1) {
            pcreate_infos_array = "&" + pcreate_infos_names;
        } else if (args.createInfoCount > 1) {
            pcreate_infos_array = "pCreateInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkRayTracingPipelineCreateInfoNV %s[] = { %s };\n", pcreate_infos_array.c_str(), pcreate_infos_names.c_str());
        }
    }
    std::string ppipelines_name = "pPipelines_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_PIPELINE));
    AddKnownVariables("VkPipeline", ppipelines_name, args.pPipelines.GetPointer(), args.createInfoCount);
    if (args.result == VK_SUCCESS) {
        this->AddHandles(ppipelines_name,
                         args.pPipelines.GetPointer(), args.createInfoCount);
    }
    pfn_loader_.AddMethodName("vkCreateRayTracingPipelinesNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateRayTracingPipelinesNV(%s, %s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.pipelineCache).c_str(),
            args.createInfoCount,
            pcreate_infos_array.c_str(),
            "nullptr",
            ppipelines_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV);
}

void VulkanCppConsumer::Process_vkDestroyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    args::DestroyAccelerationStructureNV&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyAccelerationStructureNV");
    fprintf(file,
            "\t\tloaded_vkDestroyAccelerationStructureNV(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.accelerationStructure).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV);
}

void VulkanCppConsumer::Process_vkGetAccelerationStructureHandleNV(
    const ApiCallInfo&                          call_info,
    args::GetAccelerationStructureHandleNV&     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pdata_name = "NULL";
    if (!args.pData.IsNull()) {
        pdata_name = "pData_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint8_t %s[%" PRIu64 "] = {};\n", pdata_name.c_str(), util::platform::SizeTtoUint64(args.dataSize));
    }
    pfn_loader_.AddMethodName("vkGetAccelerationStructureHandleNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetAccelerationStructureHandleNV(%s, %s, %" PRIu64 ", %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.accelerationStructure).c_str(),
            util::platform::SizeTtoUint64(args.dataSize),
            pdata_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV);
}

void VulkanCppConsumer::Process_vkGetAccelerationStructureMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    args::GetAccelerationStructureMemoryRequirementsNV& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkAccelerationStructureMemoryRequirementsInfoNV(stream_pinfo,
                                                                                              args.pInfo.GetPointer(),
                                                                                              args.pInfo.GetMetaStructPointer(),
                                                                                              *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string pmemory_requirements_name = "NULL";
    if (!args.pMemoryRequirements.IsNull()) {
        pmemory_requirements_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkMemoryRequirements2 %s = {};\n", pmemory_requirements_name.c_str());
        pmemory_requirements_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetAccelerationStructureMemoryRequirementsNV");
    fprintf(file,
            "\t\tloaded_vkGetAccelerationStructureMemoryRequirementsNV(%s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str(),
            pmemory_requirements_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV);
}

void VulkanCppConsumer::Process_vkGetRayTracingShaderGroupHandlesKHR(
    const ApiCallInfo&                          call_info,
    args::GetRayTracingShaderGroupHandlesKHR&   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pdata_name = "NULL";
    if (!args.pData.IsNull()) {
        pdata_name = "pData_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint8_t %s[%" PRIu64 "] = {};\n", pdata_name.c_str(), util::platform::SizeTtoUint64(args.dataSize));
    }
    pfn_loader_.AddMethodName("vkGetRayTracingShaderGroupHandlesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetRayTracingShaderGroupHandlesKHR(%s, %s, %u, %u, %" PRIu64 ", %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.pipeline).c_str(),
            args.firstGroup,
            args.groupCount,
            util::platform::SizeTtoUint64(args.dataSize),
            pdata_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR);
}

void VulkanCppConsumer::Process_vkGetRayTracingShaderGroupHandlesNV(
    const ApiCallInfo&                          call_info,
    args::GetRayTracingShaderGroupHandlesNV&    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pdata_name = "NULL";
    if (!args.pData.IsNull()) {
        pdata_name = "pData_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint8_t %s[%" PRIu64 "] = {};\n", pdata_name.c_str(), util::platform::SizeTtoUint64(args.dataSize));
    }
    pfn_loader_.AddMethodName("vkGetRayTracingShaderGroupHandlesNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetRayTracingShaderGroupHandlesNV(%s, %s, %u, %u, %" PRIu64 ", %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.pipeline).c_str(),
            args.firstGroup,
            args.groupCount,
            util::platform::SizeTtoUint64(args.dataSize),
            pdata_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV);
}
void VulkanCppConsumer::Process_vkGetMemoryHostPointerPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::GetMemoryHostPointerPropertiesEXT&    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string phost_pointer_name = "args.pHostPointer_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tvoid* %s;\n", phost_pointer_name.c_str());
    std::string pmemory_host_pointer_properties_name = "NULL";
    if (!args.pMemoryHostPointerProperties.IsNull()) {
        pmemory_host_pointer_properties_name = "pMemoryHostPointerProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkMemoryHostPointerPropertiesEXT %s = {};\n", pmemory_host_pointer_properties_name.c_str());
        pmemory_host_pointer_properties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetMemoryHostPointerPropertiesEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetMemoryHostPointerPropertiesEXT(%s, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            util::ToString<VkExternalMemoryHandleTypeFlagBits>(args.handleType).c_str(),
            phost_pointer_name.c_str(),
            pmemory_host_pointer_properties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT);
}
void VulkanCppConsumer::Process_vkCmdWriteBufferMarker2AMD(
    const ApiCallInfo&                          call_info,
    args::CmdWriteBufferMarker2AMD&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdWriteBufferMarker2AMD");
    fprintf(file,
            "\t\tloaded_vkCmdWriteBufferMarker2AMD(%s, %s, %s, %" PRIu64 "UL, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkPipelineStageFlags2>(args.stage).c_str(),
            this->GetHandle(args.dstBuffer).c_str(),
            args.dstOffset,
            args.marker);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD);
}

void VulkanCppConsumer::Process_vkCmdWriteBufferMarkerAMD(
    const ApiCallInfo&                          call_info,
    args::CmdWriteBufferMarkerAMD&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdWriteBufferMarkerAMD");
    fprintf(file,
            "\t\tloaded_vkCmdWriteBufferMarkerAMD(%s, %s, %s, %" PRIu64 "UL, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkPipelineStageFlagBits>(args.pipelineStage).c_str(),
            this->GetHandle(args.dstBuffer).c_str(),
            args.dstOffset,
            args.marker);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD);
}
void VulkanCppConsumer::Process_vkGetCalibratedTimestampsEXT(
    const ApiCallInfo&                          call_info,
    args::GetCalibratedTimestampsEXT&           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_ptimestamp_infos;
    std::string ptimestamp_infos_array = "NULL";
    PointerPairContainer<decltype(args.pTimestampInfos.GetPointer()), decltype(args.pTimestampInfos.GetMetaStructPointer())> ptimestamp_infos_pair{ args.pTimestampInfos.GetPointer(), args.pTimestampInfos.GetMetaStructPointer(), args.timestampCount };
    std::string ptimestamp_infos_names = toStringJoin(ptimestamp_infos_pair.begin(),
                                                      ptimestamp_infos_pair.end(),
                                                      [&](auto pair) {{ return GenerateStruct_VkCalibratedTimestampInfoKHR(stream_ptimestamp_infos, pair.t1, pair.t2, *this); }},
                                                      ", ");
    if (stream_ptimestamp_infos.str().length() > 0) {
        fprintf(file, "%s", stream_ptimestamp_infos.str().c_str());
        if (args.timestampCount == 1) {
            ptimestamp_infos_array = "&" + ptimestamp_infos_names;
        } else if (args.timestampCount > 1) {
            ptimestamp_infos_array = "pTimestampInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkCalibratedTimestampInfoKHR %s[] = { %s };\n", ptimestamp_infos_array.c_str(), ptimestamp_infos_names.c_str());
        }
    }
    std::string ptimestamps_name = "NULL";
    if (!args.pTimestamps.IsNull()) {
        ptimestamps_name = "pTimestamps_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint64_t %s[%d] = {};\n", ptimestamps_name.c_str(), args.timestampCount);
    }
    std::string pmax_deviation_name = "NULL";
    if (!args.pMaxDeviation.IsNull()) {
        pmax_deviation_name = "pMaxDeviation_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint64_t %s = %s;\n", pmax_deviation_name.c_str(), util::ToString(*args.pMaxDeviation.GetPointer()).c_str());
        pmax_deviation_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetCalibratedTimestampsEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetCalibratedTimestampsEXT(%s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            args.timestampCount,
            ptimestamp_infos_array.c_str(),
            ptimestamps_name.c_str(),
            pmax_deviation_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceCalibrateableTimeDomainsEXT& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string ptime_domain_count_name = "NULL";
    if (!args.pTimeDomainCount.IsNull()) {
        ptime_domain_count_name = "pTimeDomainCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", ptime_domain_count_name.c_str(), util::ToString(*args.pTimeDomainCount.GetPointer()).c_str());
        ptime_domain_count_name.insert(0, "&");
    }
    std::string ptime_domains_name = "NULL";
    if (!args.pTimeDomains.IsNull()) {
        const uint32_t* in_ptime_domain_count = args.pTimeDomainCount.GetPointer();
        ptime_domains_name = "pTimeDomains_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkTimeDomainKHR %s[%d] = {};\n", ptime_domains_name.c_str(), *in_ptime_domain_count);
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceCalibrateableTimeDomainsEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(%s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            ptime_domain_count_name.c_str(),
            ptime_domains_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT);
}
void VulkanCppConsumer::Process_vkCmdDrawMeshTasksIndirectCountNV(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectCountNV&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawMeshTasksIndirectCountNV");
    fprintf(file,
            "\t\tloaded_vkCmdDrawMeshTasksIndirectCountNV(%s, %s, %" PRIu64 "UL, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.buffer).c_str(),
            args.offset,
            this->GetHandle(args.countBuffer).c_str(),
            args.countBufferOffset,
            args.maxDrawCount,
            args.stride);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV);
}

void VulkanCppConsumer::Process_vkCmdDrawMeshTasksIndirectNV(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectNV&           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawMeshTasksIndirectNV");
    fprintf(file,
            "\t\tloaded_vkCmdDrawMeshTasksIndirectNV(%s, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.buffer).c_str(),
            args.offset,
            args.drawCount,
            args.stride);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV);
}

void VulkanCppConsumer::Process_vkCmdDrawMeshTasksNV(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksNV&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawMeshTasksNV");
    fprintf(file,
            "\t\tloaded_vkCmdDrawMeshTasksNV(%s, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.taskCount,
            args.firstTask);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV);
}
void VulkanCppConsumer::Process_vkCmdSetExclusiveScissorEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetExclusiveScissorEnableNV&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pexclusive_scissor_enables_array = "pExclusiveScissorEnables_" + std::to_string(this->GetNextId());
    if (args.exclusiveScissorCount > 0) {
        std::string pexclusive_scissor_enables_values = toStringJoin(args.pExclusiveScissorEnables.GetPointer(),
                                                                     args.pExclusiveScissorEnables.GetPointer() + args.exclusiveScissorCount,
                                                                     [&](const auto current) { return std::to_string(current) + ""; },
                                                                     ", ");
        fprintf(file, "\t\tVkBool32 %s[] = { %s };\n", pexclusive_scissor_enables_array.c_str(), pexclusive_scissor_enables_values.c_str());
    } else {
        pexclusive_scissor_enables_array = "NULL";
    }
    pfn_loader_.AddMethodName("vkCmdSetExclusiveScissorEnableNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetExclusiveScissorEnableNV(%s, %u, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.firstExclusiveScissor,
            args.exclusiveScissorCount,
            pexclusive_scissor_enables_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV);
}

void VulkanCppConsumer::Process_vkCmdSetExclusiveScissorNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetExclusiveScissorNV&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pexclusive_scissors;
    std::string pexclusive_scissors_array = "NULL";
    PointerPairContainer<decltype(args.pExclusiveScissors.GetPointer()), decltype(args.pExclusiveScissors.GetMetaStructPointer())> pexclusive_scissors_pair{ args.pExclusiveScissors.GetPointer(), args.pExclusiveScissors.GetMetaStructPointer(), args.exclusiveScissorCount };
    std::string pexclusive_scissors_names = toStringJoin(pexclusive_scissors_pair.begin(),
                                                         pexclusive_scissors_pair.end(),
                                                         [&](auto pair) {{ return GenerateStruct_VkRect2D(stream_pexclusive_scissors, pair.t1, pair.t2, *this); }},
                                                         ", ");
    if (stream_pexclusive_scissors.str().length() > 0) {
        fprintf(file, "%s", stream_pexclusive_scissors.str().c_str());
        if (args.exclusiveScissorCount == 1) {
            pexclusive_scissors_array = "&" + pexclusive_scissors_names;
        } else if (args.exclusiveScissorCount > 1) {
            pexclusive_scissors_array = "pExclusiveScissors_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkRect2D %s[] = { %s };\n", pexclusive_scissors_array.c_str(), pexclusive_scissors_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdSetExclusiveScissorNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetExclusiveScissorNV(%s, %u, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.firstExclusiveScissor,
            args.exclusiveScissorCount,
            pexclusive_scissors_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV);
}
void VulkanCppConsumer::Process_vkCmdSetCheckpointNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCheckpointNV&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcheckpoint_marker_name = "args.pCheckpointMarker_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tvoid* %s;\n", pcheckpoint_marker_name.c_str());
    pfn_loader_.AddMethodName("vkCmdSetCheckpointNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetCheckpointNV(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pcheckpoint_marker_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCheckpointNV);
}

void VulkanCppConsumer::Process_vkGetQueueCheckpointData2NV(
    const ApiCallInfo&                          call_info,
    args::GetQueueCheckpointData2NV&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcheckpoint_data_count_name = "NULL";
    if (!args.pCheckpointDataCount.IsNull()) {
        pcheckpoint_data_count_name = "pCheckpointDataCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pcheckpoint_data_count_name.c_str(), util::ToString(*args.pCheckpointDataCount.GetPointer()).c_str());
        pcheckpoint_data_count_name.insert(0, "&");
    }
    std::string pcheckpoint_data_name = "NULL";
    if (!args.pCheckpointData.IsNull()) {
        const uint32_t* in_pcheckpoint_data_count = args.pCheckpointDataCount.GetPointer();
        pcheckpoint_data_name = "pCheckpointData_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkCheckpointData2NV %s[%d] = {};\n", pcheckpoint_data_name.c_str(), *in_pcheckpoint_data_count);
    }
    pfn_loader_.AddMethodName("vkGetQueueCheckpointData2NV");
    fprintf(file,
            "\t\tloaded_vkGetQueueCheckpointData2NV(%s, %s, %s);\n",
            this->GetHandle(args.queue).c_str(),
            pcheckpoint_data_count_name.c_str(),
            pcheckpoint_data_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV);
}

void VulkanCppConsumer::Process_vkGetQueueCheckpointDataNV(
    const ApiCallInfo&                          call_info,
    args::GetQueueCheckpointDataNV&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcheckpoint_data_count_name = "NULL";
    if (!args.pCheckpointDataCount.IsNull()) {
        pcheckpoint_data_count_name = "pCheckpointDataCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pcheckpoint_data_count_name.c_str(), util::ToString(*args.pCheckpointDataCount.GetPointer()).c_str());
        pcheckpoint_data_count_name.insert(0, "&");
    }
    std::string pcheckpoint_data_name = "NULL";
    if (!args.pCheckpointData.IsNull()) {
        const uint32_t* in_pcheckpoint_data_count = args.pCheckpointDataCount.GetPointer();
        pcheckpoint_data_name = "pCheckpointData_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkCheckpointDataNV %s[%d] = {};\n", pcheckpoint_data_name.c_str(), *in_pcheckpoint_data_count);
    }
    pfn_loader_.AddMethodName("vkGetQueueCheckpointDataNV");
    fprintf(file,
            "\t\tloaded_vkGetQueueCheckpointDataNV(%s, %s, %s);\n",
            this->GetHandle(args.queue).c_str(),
            pcheckpoint_data_count_name.c_str(),
            pcheckpoint_data_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV);
}
void VulkanCppConsumer::Process_vkGetPastPresentationTimingEXT(
    const ApiCallInfo&                          call_info,
    args::GetPastPresentationTimingEXT&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_ppast_presentation_timing_info;
    std::string ppast_presentation_timing_info_struct = GenerateStruct_VkPastPresentationTimingInfoEXT(stream_ppast_presentation_timing_info,
                                                                                                       args.pPastPresentationTimingInfo.GetPointer(),
                                                                                                       args.pPastPresentationTimingInfo.GetMetaStructPointer(),
                                                                                                       *this);
    fprintf(file, "%s", stream_ppast_presentation_timing_info.str().c_str());
    std::string ppast_presentation_timing_properties_name = "NULL";
    if (!args.pPastPresentationTimingProperties.IsNull()) {
        ppast_presentation_timing_properties_name = "pPastPresentationTimingProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPastPresentationTimingPropertiesEXT %s = {};\n", ppast_presentation_timing_properties_name.c_str());
        ppast_presentation_timing_properties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPastPresentationTimingEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPastPresentationTimingEXT(%s, &%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            ppast_presentation_timing_info_struct.c_str(),
            ppast_presentation_timing_properties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPastPresentationTimingEXT);
}

void VulkanCppConsumer::Process_vkGetSwapchainTimeDomainPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::GetSwapchainTimeDomainPropertiesEXT&  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pswapchain_time_domain_properties_name = "NULL";
    if (!args.pSwapchainTimeDomainProperties.IsNull()) {
        pswapchain_time_domain_properties_name = "pSwapchainTimeDomainProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkSwapchainTimeDomainPropertiesEXT %s = {};\n", pswapchain_time_domain_properties_name.c_str());
        pswapchain_time_domain_properties_name.insert(0, "&");
    }
    std::string ptime_domains_counter_name = "NULL";
    if (!args.pTimeDomainsCounter.IsNull()) {
        ptime_domains_counter_name = "pTimeDomainsCounter_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint64_t %s = %s;\n", ptime_domains_counter_name.c_str(), util::ToString(*args.pTimeDomainsCounter.GetPointer()).c_str());
        ptime_domains_counter_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetSwapchainTimeDomainPropertiesEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetSwapchainTimeDomainPropertiesEXT(%s, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.swapchain).c_str(),
            pswapchain_time_domain_properties_name.c_str(),
            ptime_domains_counter_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetSwapchainTimeDomainPropertiesEXT);
}

void VulkanCppConsumer::Process_vkGetSwapchainTimingPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::GetSwapchainTimingPropertiesEXT&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pswapchain_timing_properties_name = "NULL";
    if (!args.pSwapchainTimingProperties.IsNull()) {
        pswapchain_timing_properties_name = "pSwapchainTimingProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkSwapchainTimingPropertiesEXT %s = {};\n", pswapchain_timing_properties_name.c_str());
        pswapchain_timing_properties_name.insert(0, "&");
    }
    std::string pswapchain_timing_properties_counter_name = "NULL";
    if (!args.pSwapchainTimingPropertiesCounter.IsNull()) {
        pswapchain_timing_properties_counter_name = "pSwapchainTimingPropertiesCounter_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint64_t %s = %s;\n", pswapchain_timing_properties_counter_name.c_str(), util::ToString(*args.pSwapchainTimingPropertiesCounter.GetPointer()).c_str());
        pswapchain_timing_properties_counter_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetSwapchainTimingPropertiesEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetSwapchainTimingPropertiesEXT(%s, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.swapchain).c_str(),
            pswapchain_timing_properties_name.c_str(),
            pswapchain_timing_properties_counter_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetSwapchainTimingPropertiesEXT);
}

void VulkanCppConsumer::Process_vkSetSwapchainPresentTimingQueueSizeEXT(
    const ApiCallInfo&                          call_info,
    args::SetSwapchainPresentTimingQueueSizeEXT& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkSetSwapchainPresentTimingQueueSizeEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkSetSwapchainPresentTimingQueueSizeEXT(%s, %s, %u), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.swapchain).c_str(),
            args.size,
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSetSwapchainPresentTimingQueueSizeEXT);
}
void VulkanCppConsumer::Process_vkAcquirePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    args::AcquirePerformanceConfigurationINTEL& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pacquire_info;
    std::string pacquire_info_struct = GenerateStruct_VkPerformanceConfigurationAcquireInfoINTEL(stream_pacquire_info,
                                                                                                 args.pAcquireInfo.GetPointer(),
                                                                                                 args.pAcquireInfo.GetMetaStructPointer(),
                                                                                                 *this);
    fprintf(file, "%s", stream_pacquire_info.str().c_str());
    std::string pconfiguration_name = "pConfiguration_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL));
    AddKnownVariables("VkPerformanceConfigurationINTEL", pconfiguration_name, args.pConfiguration.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pconfiguration_name,
                         args.pConfiguration.GetPointer());
    }
    pfn_loader_.AddMethodName("vkAcquirePerformanceConfigurationINTEL");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkAcquirePerformanceConfigurationINTEL(%s, &%s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pacquire_info_struct.c_str(),
            pconfiguration_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL);
}

void VulkanCppConsumer::Process_vkCmdSetPerformanceMarkerINTEL(
    const ApiCallInfo&                          call_info,
    args::CmdSetPerformanceMarkerINTEL&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pmarker_info;
    std::string pmarker_info_struct = GenerateStruct_VkPerformanceMarkerInfoINTEL(stream_pmarker_info,
                                                                                  args.pMarkerInfo.GetPointer(),
                                                                                  args.pMarkerInfo.GetMetaStructPointer(),
                                                                                  *this);
    fprintf(file, "%s", stream_pmarker_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdSetPerformanceMarkerINTEL");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCmdSetPerformanceMarkerINTEL(%s, &%s), %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pmarker_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL);
}

void VulkanCppConsumer::Process_vkCmdSetPerformanceOverrideINTEL(
    const ApiCallInfo&                          call_info,
    args::CmdSetPerformanceOverrideINTEL&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_poverride_info;
    std::string poverride_info_struct = GenerateStruct_VkPerformanceOverrideInfoINTEL(stream_poverride_info,
                                                                                      args.pOverrideInfo.GetPointer(),
                                                                                      args.pOverrideInfo.GetMetaStructPointer(),
                                                                                      *this);
    fprintf(file, "%s", stream_poverride_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdSetPerformanceOverrideINTEL");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCmdSetPerformanceOverrideINTEL(%s, &%s), %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            poverride_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL);
}

void VulkanCppConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    const ApiCallInfo&                          call_info,
    args::CmdSetPerformanceStreamMarkerINTEL&   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pmarker_info;
    std::string pmarker_info_struct = GenerateStruct_VkPerformanceStreamMarkerInfoINTEL(stream_pmarker_info,
                                                                                        args.pMarkerInfo.GetPointer(),
                                                                                        args.pMarkerInfo.GetMetaStructPointer(),
                                                                                        *this);
    fprintf(file, "%s", stream_pmarker_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdSetPerformanceStreamMarkerINTEL");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCmdSetPerformanceStreamMarkerINTEL(%s, &%s), %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pmarker_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL);
}

void VulkanCppConsumer::Process_vkGetPerformanceParameterINTEL(
    const ApiCallInfo&                          call_info,
    args::GetPerformanceParameterINTEL&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pvalue_name = "NULL";
    if (!args.pValue.IsNull()) {
        pvalue_name = "pValue_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPerformanceValueINTEL %s = {};\n", pvalue_name.c_str());
        pvalue_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPerformanceParameterINTEL");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPerformanceParameterINTEL(%s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            util::ToString<VkPerformanceParameterTypeINTEL>(args.parameter).c_str(),
            pvalue_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL);
}

void VulkanCppConsumer::Process_vkInitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    args::InitializePerformanceApiINTEL&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinitialize_info;
    std::string pinitialize_info_struct = GenerateStruct_VkInitializePerformanceApiInfoINTEL(stream_pinitialize_info,
                                                                                             args.pInitializeInfo.GetPointer(),
                                                                                             args.pInitializeInfo.GetMetaStructPointer(),
                                                                                             *this);
    fprintf(file, "%s", stream_pinitialize_info.str().c_str());
    pfn_loader_.AddMethodName("vkInitializePerformanceApiINTEL");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkInitializePerformanceApiINTEL(%s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pinitialize_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL);
}

void VulkanCppConsumer::Process_vkQueueSetPerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    args::QueueSetPerformanceConfigurationINTEL& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkQueueSetPerformanceConfigurationINTEL");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkQueueSetPerformanceConfigurationINTEL(%s, %s), %s);\n",
            this->GetHandle(args.queue).c_str(),
            this->GetHandle(args.configuration).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL);
}

void VulkanCppConsumer::Process_vkReleasePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    args::ReleasePerformanceConfigurationINTEL& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkReleasePerformanceConfigurationINTEL");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkReleasePerformanceConfigurationINTEL(%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.configuration).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL);
}

void VulkanCppConsumer::Process_vkUninitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    args::UninitializePerformanceApiINTEL&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkUninitializePerformanceApiINTEL");
    fprintf(file,
            "\t\tloaded_vkUninitializePerformanceApiINTEL(%s);\n",
            this->GetHandle(args.device).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL);
}
void VulkanCppConsumer::Process_vkSetLocalDimmingAMD(
    const ApiCallInfo&                          call_info,
    args::SetLocalDimmingAMD&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkSetLocalDimmingAMD");
    fprintf(file,
            "\t\tloaded_vkSetLocalDimmingAMD(%s, %s, %u);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.swapChain).c_str(),
            args.localDimmingEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSetLocalDimmingAMD);
}
void VulkanCppConsumer::Process_vkCreateImagePipeSurfaceFUCHSIA(
    const ApiCallInfo&                          call_info,
    args::CreateImagePipeSurfaceFUCHSIA&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkImagePipeSurfaceCreateInfoFUCHSIA(stream_pcreate_info,
                                                                                         args.pCreateInfo.GetPointer(),
                                                                                         args.pCreateInfo.GetMetaStructPointer(),
                                                                                         *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psurface_name = "pSurface_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", psurface_name, args.pSurface.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(psurface_name,
                         args.pSurface.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateImagePipeSurfaceFUCHSIA");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateImagePipeSurfaceFUCHSIA(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.instance).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psurface_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA);
}
void VulkanCppConsumer::Process_vkCreateMetalSurfaceEXT(
    const ApiCallInfo&                          call_info,
    args::CreateMetalSurfaceEXT&                args)
{
    Generate_vkCreateMetalSurfaceEXT(args);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT);
}
void VulkanCppConsumer::Process_vkGetBufferDeviceAddressEXT(
    const ApiCallInfo&                          call_info,
    args::GetBufferDeviceAddressEXT&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkBufferDeviceAddressInfo(stream_pinfo,
                                                                        args.pInfo.GetPointer(),
                                                                        args.pInfo.GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkGetBufferDeviceAddressEXT");
    fprintf(file,
            "\t\tloaded_vkGetBufferDeviceAddressEXT(%s, &%s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT);
}
void VulkanCppConsumer::Process_vkGetPhysicalDeviceToolPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceToolPropertiesEXT&   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string ptool_count_name = "NULL";
    if (!args.pToolCount.IsNull()) {
        ptool_count_name = "pToolCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", ptool_count_name.c_str(), util::ToString(*args.pToolCount.GetPointer()).c_str());
        ptool_count_name.insert(0, "&");
    }
    std::string ptool_properties_name = "NULL";
    if (!args.pToolProperties.IsNull()) {
        const uint32_t* in_ptool_count = args.pToolCount.GetPointer();
        ptool_properties_name = "pToolProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPhysicalDeviceToolProperties %s[%d] = {};\n", ptool_properties_name.c_str(), *in_ptool_count);
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceToolPropertiesEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceToolPropertiesEXT(%s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            ptool_count_name.c_str(),
            ptool_properties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT);
}
void VulkanCppConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceCooperativeMatrixPropertiesNV& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pproperty_count_name = "NULL";
    if (!args.pPropertyCount.IsNull()) {
        pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pproperty_count_name.c_str(), util::ToString(*args.pPropertyCount.GetPointer()).c_str());
        pproperty_count_name.insert(0, "&");
    }
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        const uint32_t* in_pproperty_count = args.pPropertyCount.GetPointer();
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkCooperativeMatrixPropertiesNV %s[%d] = {};\n", pproperties_name.c_str(), *in_pproperty_count);
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceCooperativeMatrixPropertiesNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(%s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV);
}
void VulkanCppConsumer::Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcombination_count_name = "NULL";
    if (!args.pCombinationCount.IsNull()) {
        pcombination_count_name = "pCombinationCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pcombination_count_name.c_str(), util::ToString(*args.pCombinationCount.GetPointer()).c_str());
        pcombination_count_name.insert(0, "&");
    }
    std::string pcombinations_name = "NULL";
    if (!args.pCombinations.IsNull()) {
        const uint32_t* in_pcombination_count = args.pCombinationCount.GetPointer();
        pcombinations_name = "pCombinations_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkFramebufferMixedSamplesCombinationNV %s[%d] = {};\n", pcombinations_name.c_str(), *in_pcombination_count);
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(%s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pcombination_count_name.c_str(),
            pcombinations_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV);
}
void VulkanCppConsumer::Process_vkAcquireFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    args::AcquireFullScreenExclusiveModeEXT&    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkAcquireFullScreenExclusiveModeEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkAcquireFullScreenExclusiveModeEXT(%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.swapchain).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT);
}

void VulkanCppConsumer::Process_vkGetDeviceGroupSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
    args::GetDeviceGroupSurfacePresentModes2EXT& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psurface_info;
    std::string psurface_info_struct = GenerateStruct_VkPhysicalDeviceSurfaceInfo2KHR(stream_psurface_info,
                                                                                      args.pSurfaceInfo.GetPointer(),
                                                                                      args.pSurfaceInfo.GetMetaStructPointer(),
                                                                                      *this);
    fprintf(file, "%s", stream_psurface_info.str().c_str());
    std::string pmodes_name = "NULL";
    if (!args.pModes.IsNull()) {
        pmodes_name = "pModes_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDeviceGroupPresentModeFlagsKHR %s = %s;\n", pmodes_name.c_str(), util::ToString(*args.pModes.GetPointer()).c_str());
        pmodes_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetDeviceGroupSurfacePresentModes2EXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDeviceGroupSurfacePresentModes2EXT(%s, &%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            psurface_info_struct.c_str(),
            pmodes_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfacePresentModes2EXT& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psurface_info;
    std::string psurface_info_struct = GenerateStruct_VkPhysicalDeviceSurfaceInfo2KHR(stream_psurface_info,
                                                                                      args.pSurfaceInfo.GetPointer(),
                                                                                      args.pSurfaceInfo.GetMetaStructPointer(),
                                                                                      *this);
    fprintf(file, "%s", stream_psurface_info.str().c_str());
    std::string ppresent_mode_count_name = "NULL";
    if (!args.pPresentModeCount.IsNull()) {
        ppresent_mode_count_name = "pPresentModeCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", ppresent_mode_count_name.c_str(), util::ToString(*args.pPresentModeCount.GetPointer()).c_str());
        ppresent_mode_count_name.insert(0, "&");
    }
    std::string ppresent_modes_name = "NULL";
    if (!args.pPresentModes.IsNull()) {
        const uint32_t* in_ppresent_mode_count = args.pPresentModeCount.GetPointer();
        ppresent_modes_name = "pPresentModes_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPresentModeKHR %s[%d] = {};\n", ppresent_modes_name.c_str(), *in_ppresent_mode_count);
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceSurfacePresentModes2EXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfacePresentModes2EXT(%s, &%s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            psurface_info_struct.c_str(),
            ppresent_mode_count_name.c_str(),
            ppresent_modes_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT);
}

void VulkanCppConsumer::Process_vkReleaseFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    args::ReleaseFullScreenExclusiveModeEXT&    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkReleaseFullScreenExclusiveModeEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkReleaseFullScreenExclusiveModeEXT(%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.swapchain).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT);
}
void VulkanCppConsumer::Process_vkCreateHeadlessSurfaceEXT(
    const ApiCallInfo&                          call_info,
    args::CreateHeadlessSurfaceEXT&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkHeadlessSurfaceCreateInfoEXT(stream_pcreate_info,
                                                                                    args.pCreateInfo.GetPointer(),
                                                                                    args.pCreateInfo.GetMetaStructPointer(),
                                                                                    *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psurface_name = "pSurface_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", psurface_name, args.pSurface.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(psurface_name,
                         args.pSurface.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateHeadlessSurfaceEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateHeadlessSurfaceEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.instance).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psurface_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT);
}
void VulkanCppConsumer::Process_vkCmdSetLineStippleEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineStippleEXT&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetLineStippleEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetLineStippleEXT(%s, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.lineStippleFactor,
            args.lineStipplePattern);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT);
}
void VulkanCppConsumer::Process_vkResetQueryPoolEXT(
    const ApiCallInfo&                          call_info,
    args::ResetQueryPoolEXT&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkResetQueryPoolEXT");
    fprintf(file,
            "\t\tloaded_vkResetQueryPoolEXT(%s, %s, %u, %u);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.queryPool).c_str(),
            args.firstQuery,
            args.queryCount);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkResetQueryPoolEXT);
}
void VulkanCppConsumer::Process_vkCmdBindVertexBuffers2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers2EXT&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pbuffers_array = "NULL";
    std::string pbuffers_values = toStringJoin(args.pBuffers.GetPointer(),
                                               args.pBuffers.GetPointer() + args.bindingCount,
                                               [&](const format::HandleId current) { return this->GetHandle(current); },
                                               ", ");
    if (args.bindingCount == 1 && pbuffers_values != "VK_NULL_HANDLE") {
        pbuffers_array = "&" + pbuffers_values;
    } else if (args.bindingCount > 1) {
        pbuffers_array = "pbuffers_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkBuffer %s[] = { %s };\n", pbuffers_array.c_str(), pbuffers_values.c_str());
    }
    std::string poffsets_array = "pOffsets_" + std::to_string(this->GetNextId());
    if (args.bindingCount > 0) {
        std::string poffsets_values = toStringJoin(args.pOffsets.GetPointer(),
                                                   args.pOffsets.GetPointer() + args.bindingCount,
                                                   [&](const auto current) { return std::to_string(current) + "UL"; },
                                                   ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", poffsets_array.c_str(), poffsets_values.c_str());
    } else {
        poffsets_array = "NULL";
    }
    std::string psizes_array = "pSizes_" + std::to_string(this->GetNextId());
    if (args.bindingCount > 0 && args.pSizes.GetPointer() != nullptr) {
        std::string psizes_values = toStringJoin(args.pSizes.GetPointer(),
                                                 args.pSizes.GetPointer() + args.bindingCount,
                                                 [&](const auto current) { return std::to_string(current) + "UL"; },
                                                 ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", psizes_array.c_str(), psizes_values.c_str());
    } else {
        psizes_array = "NULL";
    }
    std::string pstrides_array = "pStrides_" + std::to_string(this->GetNextId());
    if (args.bindingCount > 0 && args.pStrides.GetPointer() != nullptr) {
        std::string pstrides_values = toStringJoin(args.pStrides.GetPointer(),
                                                   args.pStrides.GetPointer() + args.bindingCount,
                                                   [&](const auto current) { return std::to_string(current) + "UL"; },
                                                   ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", pstrides_array.c_str(), pstrides_values.c_str());
    } else {
        pstrides_array = "NULL";
    }
    pfn_loader_.AddMethodName("vkCmdBindVertexBuffers2EXT");
    fprintf(file,
            "\t\tloaded_vkCmdBindVertexBuffers2EXT(%s, %u, %u, %s, %s, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.firstBinding,
            args.bindingCount,
            pbuffers_array.c_str(),
            poffsets_array.c_str(),
            psizes_array.c_str(),
            pstrides_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT);
}

void VulkanCppConsumer::Process_vkCmdSetCullModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetCullModeEXT&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetCullModeEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetCullModeEXT(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkCullModeFlags>(args.cullMode).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCullModeEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDepthBoundsTestEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBoundsTestEnableEXT&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetDepthBoundsTestEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDepthBoundsTestEnableEXT(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.depthBoundsTestEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDepthCompareOpEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthCompareOpEXT&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetDepthCompareOpEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDepthCompareOpEXT(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkCompareOp>(args.depthCompareOp).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDepthTestEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthTestEnableEXT&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetDepthTestEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDepthTestEnableEXT(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.depthTestEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDepthWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthWriteEnableEXT&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetDepthWriteEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDepthWriteEnableEXT(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.depthWriteEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetFrontFaceEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetFrontFaceEXT&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetFrontFaceEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetFrontFaceEXT(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkFrontFace>(args.frontFace).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT);
}

void VulkanCppConsumer::Process_vkCmdSetPrimitiveTopologyEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveTopologyEXT&           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetPrimitiveTopologyEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetPrimitiveTopologyEXT(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkPrimitiveTopology>(args.primitiveTopology).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT);
}

void VulkanCppConsumer::Process_vkCmdSetScissorWithCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetScissorWithCountEXT&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pscissors;
    std::string pscissors_array = "NULL";
    PointerPairContainer<decltype(args.pScissors.GetPointer()), decltype(args.pScissors.GetMetaStructPointer())> pscissors_pair{ args.pScissors.GetPointer(), args.pScissors.GetMetaStructPointer(), args.scissorCount };
    std::string pscissors_names = toStringJoin(pscissors_pair.begin(),
                                               pscissors_pair.end(),
                                               [&](auto pair) {{ return GenerateStruct_VkRect2D(stream_pscissors, pair.t1, pair.t2, *this); }},
                                               ", ");
    if (stream_pscissors.str().length() > 0) {
        fprintf(file, "%s", stream_pscissors.str().c_str());
        if (args.scissorCount == 1) {
            pscissors_array = "&" + pscissors_names;
        } else if (args.scissorCount > 1) {
            pscissors_array = "pScissors_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkRect2D %s[] = { %s };\n", pscissors_array.c_str(), pscissors_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdSetScissorWithCountEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetScissorWithCountEXT(%s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.scissorCount,
            pscissors_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT);
}

void VulkanCppConsumer::Process_vkCmdSetStencilOpEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilOpEXT&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetStencilOpEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetStencilOpEXT(%s, %s, %s, %s, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkStencilFaceFlags>(args.faceMask).c_str(),
            util::ToString<VkStencilOp>(args.failOp).c_str(),
            util::ToString<VkStencilOp>(args.passOp).c_str(),
            util::ToString<VkStencilOp>(args.depthFailOp).c_str(),
            util::ToString<VkCompareOp>(args.compareOp).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT);
}

void VulkanCppConsumer::Process_vkCmdSetStencilTestEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilTestEnableEXT&           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetStencilTestEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetStencilTestEnableEXT(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.stencilTestEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetViewportWithCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportWithCountEXT&           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pviewports;
    std::string pviewports_array = "NULL";
    PointerPairContainer<decltype(args.pViewports.GetPointer()), decltype(args.pViewports.GetMetaStructPointer())> pviewports_pair{ args.pViewports.GetPointer(), args.pViewports.GetMetaStructPointer(), args.viewportCount };
    std::string pviewports_names = toStringJoin(pviewports_pair.begin(),
                                                pviewports_pair.end(),
                                                [&](auto pair) {{ return GenerateStruct_VkViewport(stream_pviewports, pair.t1, pair.t2, *this); }},
                                                ", ");
    if (stream_pviewports.str().length() > 0) {
        fprintf(file, "%s", stream_pviewports.str().c_str());
        if (args.viewportCount == 1) {
            pviewports_array = "&" + pviewports_names;
        } else if (args.viewportCount > 1) {
            pviewports_array = "pViewports_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkViewport %s[] = { %s };\n", pviewports_array.c_str(), pviewports_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdSetViewportWithCountEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetViewportWithCountEXT(%s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.viewportCount,
            pviewports_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT);
}
void VulkanCppConsumer::Process_vkCopyImageToImageEXT(
    const ApiCallInfo&                          call_info,
    args::CopyImageToImageEXT&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_image_to_image_info;
    std::string pcopy_image_to_image_info_struct = GenerateStruct_VkCopyImageToImageInfo(stream_pcopy_image_to_image_info,
                                                                                         args.pCopyImageToImageInfo.GetPointer(),
                                                                                         args.pCopyImageToImageInfo.GetMetaStructPointer(),
                                                                                         *this);
    fprintf(file, "%s", stream_pcopy_image_to_image_info.str().c_str());
    pfn_loader_.AddMethodName("vkCopyImageToImageEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCopyImageToImageEXT(%s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcopy_image_to_image_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCopyImageToImageEXT);
}

void VulkanCppConsumer::Process_vkCopyImageToMemoryEXT(
    const ApiCallInfo&                          call_info,
    args::CopyImageToMemoryEXT&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_image_to_memory_info;
    std::string pcopy_image_to_memory_info_struct = GenerateStruct_VkCopyImageToMemoryInfo(stream_pcopy_image_to_memory_info,
                                                                                           args.pCopyImageToMemoryInfo.GetPointer(),
                                                                                           args.pCopyImageToMemoryInfo.GetMetaStructPointer(),
                                                                                           *this);
    fprintf(file, "%s", stream_pcopy_image_to_memory_info.str().c_str());
    pfn_loader_.AddMethodName("vkCopyImageToMemoryEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCopyImageToMemoryEXT(%s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcopy_image_to_memory_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCopyImageToMemoryEXT);
}

void VulkanCppConsumer::Process_vkCopyMemoryToImageEXT(
    const ApiCallInfo&                          call_info,
    args::CopyMemoryToImageEXT&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_memory_to_image_info;
    std::string pcopy_memory_to_image_info_struct = GenerateStruct_VkCopyMemoryToImageInfo(stream_pcopy_memory_to_image_info,
                                                                                           args.pCopyMemoryToImageInfo.GetPointer(),
                                                                                           args.pCopyMemoryToImageInfo.GetMetaStructPointer(),
                                                                                           *this);
    fprintf(file, "%s", stream_pcopy_memory_to_image_info.str().c_str());
    pfn_loader_.AddMethodName("vkCopyMemoryToImageEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCopyMemoryToImageEXT(%s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcopy_memory_to_image_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCopyMemoryToImageEXT);
}

void VulkanCppConsumer::Process_vkGetImageSubresourceLayout2EXT(
    const ApiCallInfo&                          call_info,
    args::GetImageSubresourceLayout2EXT&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psubresource;
    std::string psubresource_struct = GenerateStruct_VkImageSubresource2(stream_psubresource,
                                                                         args.pSubresource.GetPointer(),
                                                                         args.pSubresource.GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "%s", stream_psubresource.str().c_str());
    std::string playout_name = "NULL";
    if (!args.pLayout.IsNull()) {
        playout_name = "pLayout_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkSubresourceLayout2 %s = {};\n", playout_name.c_str());
        playout_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetImageSubresourceLayout2EXT");
    fprintf(file,
            "\t\tloaded_vkGetImageSubresourceLayout2EXT(%s, %s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.image).c_str(),
            psubresource_struct.c_str(),
            playout_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT);
}

void VulkanCppConsumer::Process_vkTransitionImageLayoutEXT(
    const ApiCallInfo&                          call_info,
    args::TransitionImageLayoutEXT&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_ptransitions;
    std::string ptransitions_array = "NULL";
    PointerPairContainer<decltype(args.pTransitions.GetPointer()), decltype(args.pTransitions.GetMetaStructPointer())> ptransitions_pair{ args.pTransitions.GetPointer(), args.pTransitions.GetMetaStructPointer(), args.transitionCount };
    std::string ptransitions_names = toStringJoin(ptransitions_pair.begin(),
                                                  ptransitions_pair.end(),
                                                  [&](auto pair) {{ return GenerateStruct_VkHostImageLayoutTransitionInfo(stream_ptransitions, pair.t1, pair.t2, *this); }},
                                                  ", ");
    if (stream_ptransitions.str().length() > 0) {
        fprintf(file, "%s", stream_ptransitions.str().c_str());
        if (args.transitionCount == 1) {
            ptransitions_array = "&" + ptransitions_names;
        } else if (args.transitionCount > 1) {
            ptransitions_array = "pTransitions_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkHostImageLayoutTransitionInfo %s[] = { %s };\n", ptransitions_array.c_str(), ptransitions_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkTransitionImageLayoutEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkTransitionImageLayoutEXT(%s, %u, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            args.transitionCount,
            ptransitions_array.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkTransitionImageLayoutEXT);
}
void VulkanCppConsumer::Process_vkReleaseSwapchainImagesEXT(
    const ApiCallInfo&                          call_info,
    args::ReleaseSwapchainImagesEXT&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_prelease_info;
    std::string prelease_info_struct = GenerateStruct_VkReleaseSwapchainImagesInfoKHR(stream_prelease_info,
                                                                                      args.pReleaseInfo.GetPointer(),
                                                                                      args.pReleaseInfo.GetMetaStructPointer(),
                                                                                      *this);
    fprintf(file, "%s", stream_prelease_info.str().c_str());
    pfn_loader_.AddMethodName("vkReleaseSwapchainImagesEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkReleaseSwapchainImagesEXT(%s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            prelease_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT);
}
void VulkanCppConsumer::Process_vkCmdBindPipelineShaderGroupNV(
    const ApiCallInfo&                          call_info,
    args::CmdBindPipelineShaderGroupNV&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdBindPipelineShaderGroupNV");
    fprintf(file,
            "\t\tloaded_vkCmdBindPipelineShaderGroupNV(%s, %s, %s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkPipelineBindPoint>(args.pipelineBindPoint).c_str(),
            this->GetHandle(args.pipeline).c_str(),
            args.groupIndex);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV);
}

void VulkanCppConsumer::Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    args::CmdExecuteGeneratedCommandsNV&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pgenerated_commands_info;
    std::string pgenerated_commands_info_struct = GenerateStruct_VkGeneratedCommandsInfoNV(stream_pgenerated_commands_info,
                                                                                           args.pGeneratedCommandsInfo.GetPointer(),
                                                                                           args.pGeneratedCommandsInfo.GetMetaStructPointer(),
                                                                                           *this);
    fprintf(file, "%s", stream_pgenerated_commands_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdExecuteGeneratedCommandsNV");
    fprintf(file,
            "\t\tloaded_vkCmdExecuteGeneratedCommandsNV(%s, %u, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.isPreprocessed,
            pgenerated_commands_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV);
}

void VulkanCppConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    args::CmdPreprocessGeneratedCommandsNV&     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pgenerated_commands_info;
    std::string pgenerated_commands_info_struct = GenerateStruct_VkGeneratedCommandsInfoNV(stream_pgenerated_commands_info,
                                                                                           args.pGeneratedCommandsInfo.GetPointer(),
                                                                                           args.pGeneratedCommandsInfo.GetMetaStructPointer(),
                                                                                           *this);
    fprintf(file, "%s", stream_pgenerated_commands_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdPreprocessGeneratedCommandsNV");
    fprintf(file,
            "\t\tloaded_vkCmdPreprocessGeneratedCommandsNV(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pgenerated_commands_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV);
}

void VulkanCppConsumer::Process_vkCreateIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    args::CreateIndirectCommandsLayoutNV&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkIndirectCommandsLayoutCreateInfoNV(stream_pcreate_info,
                                                                                          args.pCreateInfo.GetPointer(),
                                                                                          args.pCreateInfo.GetMetaStructPointer(),
                                                                                          *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pindirect_commands_layout_name = "pIndirectCommandsLayout_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV));
    AddKnownVariables("VkIndirectCommandsLayoutNV", pindirect_commands_layout_name, args.pIndirectCommandsLayout.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pindirect_commands_layout_name,
                         args.pIndirectCommandsLayout.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateIndirectCommandsLayoutNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateIndirectCommandsLayoutNV(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pindirect_commands_layout_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV);
}

void VulkanCppConsumer::Process_vkDestroyIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    args::DestroyIndirectCommandsLayoutNV&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyIndirectCommandsLayoutNV");
    fprintf(file,
            "\t\tloaded_vkDestroyIndirectCommandsLayoutNV(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.indirectCommandsLayout).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV);
}

void VulkanCppConsumer::Process_vkGetGeneratedCommandsMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    args::GetGeneratedCommandsMemoryRequirementsNV& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkGeneratedCommandsMemoryRequirementsInfoNV(stream_pinfo,
                                                                                          args.pInfo.GetPointer(),
                                                                                          args.pInfo.GetMetaStructPointer(),
                                                                                          *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string pmemory_requirements_name = "NULL";
    if (!args.pMemoryRequirements.IsNull()) {
        pmemory_requirements_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkMemoryRequirements2 %s = {};\n", pmemory_requirements_name.c_str());
        pmemory_requirements_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetGeneratedCommandsMemoryRequirementsNV");
    fprintf(file,
            "\t\tloaded_vkGetGeneratedCommandsMemoryRequirementsNV(%s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str(),
            pmemory_requirements_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV);
}
void VulkanCppConsumer::Process_vkCmdSetDepthBias2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBias2EXT&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdepth_bias_info;
    std::string pdepth_bias_info_struct = GenerateStruct_VkDepthBiasInfoEXT(stream_pdepth_bias_info,
                                                                            args.pDepthBiasInfo.GetPointer(),
                                                                            args.pDepthBiasInfo.GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pdepth_bias_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdSetDepthBias2EXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDepthBias2EXT(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pdepth_bias_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBias2EXT);
}
void VulkanCppConsumer::Process_vkAcquireDrmDisplayEXT(
    const ApiCallInfo&                          call_info,
    args::AcquireDrmDisplayEXT&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkAcquireDrmDisplayEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkAcquireDrmDisplayEXT(%s, %d, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            args.drmFd,
            this->GetHandle(args.display).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT);
}

void VulkanCppConsumer::Process_vkGetDrmDisplayEXT(
    const ApiCallInfo&                          call_info,
    args::GetDrmDisplayEXT&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string display_name = "display_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DISPLAY_KHR));
    AddKnownVariables("VkDisplayKHR", display_name, args.display.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(display_name,
                         args.display.GetPointer());
    }
    pfn_loader_.AddMethodName("vkGetDrmDisplayEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDrmDisplayEXT(%s, %d, %u, &%s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            args.drmFd,
            args.connectorId,
            display_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDrmDisplayEXT);
}
void VulkanCppConsumer::Process_vkCreatePrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    args::CreatePrivateDataSlotEXT&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkPrivateDataSlotCreateInfo(stream_pcreate_info,
                                                                                 args.pCreateInfo.GetPointer(),
                                                                                 args.pCreateInfo.GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pprivate_data_slot_name = "pPrivateDataSlot_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_PRIVATE_DATA_SLOT));
    AddKnownVariables("VkPrivateDataSlot", pprivate_data_slot_name, args.pPrivateDataSlot.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pprivate_data_slot_name,
                         args.pPrivateDataSlot.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreatePrivateDataSlotEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreatePrivateDataSlotEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pprivate_data_slot_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT);
}

void VulkanCppConsumer::Process_vkDestroyPrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyPrivateDataSlotEXT&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyPrivateDataSlotEXT");
    fprintf(file,
            "\t\tloaded_vkDestroyPrivateDataSlotEXT(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.privateDataSlot).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT);
}

void VulkanCppConsumer::Process_vkGetPrivateDataEXT(
    const ApiCallInfo&                          call_info,
    args::GetPrivateDataEXT&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pdata_name = "NULL";
    if (!args.pData.IsNull()) {
        pdata_name = "pData_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint64_t %s = %s;\n", pdata_name.c_str(), util::ToString(*args.pData.GetPointer()).c_str());
        pdata_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPrivateDataEXT");
    fprintf(file,
            "\t\tloaded_vkGetPrivateDataEXT(%s, %s, %" PRIu64 "UL, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            util::ToString<VkObjectType>(args.objectType).c_str(),
            args.objectHandle,
            this->GetHandle(args.privateDataSlot).c_str(),
            pdata_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPrivateDataEXT);
}

void VulkanCppConsumer::Process_vkSetPrivateDataEXT(
    const ApiCallInfo&                          call_info,
    args::SetPrivateDataEXT&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkSetPrivateDataEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkSetPrivateDataEXT(%s, %s, %" PRIu64 "UL, %s, %" PRIu64 "UL), %s);\n",
            this->GetHandle(args.device).c_str(),
            util::ToString<VkObjectType>(args.objectType).c_str(),
            args.objectHandle,
            this->GetHandle(args.privateDataSlot).c_str(),
            args.data,
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSetPrivateDataEXT);
}
void VulkanCppConsumer::Process_vkQueueSetPerfHintQCOM(
    const ApiCallInfo&                          call_info,
    args::QueueSetPerfHintQCOM&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pperf_hint_info;
    std::string pperf_hint_info_struct = GenerateStruct_VkPerfHintInfoQCOM(stream_pperf_hint_info,
                                                                           args.pPerfHintInfo.GetPointer(),
                                                                           args.pPerfHintInfo.GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_pperf_hint_info.str().c_str());
    pfn_loader_.AddMethodName("vkQueueSetPerfHintQCOM");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkQueueSetPerfHintQCOM(%s, &%s), %s);\n",
            this->GetHandle(args.queue).c_str(),
            pperf_hint_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkQueueSetPerfHintQCOM);
}
void VulkanCppConsumer::Process_vkCmdBeginPerTileExecutionQCOM(
    const ApiCallInfo&                          call_info,
    args::CmdBeginPerTileExecutionQCOM&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pper_tile_begin_info;
    std::string pper_tile_begin_info_struct = GenerateStruct_VkPerTileBeginInfoQCOM(stream_pper_tile_begin_info,
                                                                                    args.pPerTileBeginInfo.GetPointer(),
                                                                                    args.pPerTileBeginInfo.GetMetaStructPointer(),
                                                                                    *this);
    fprintf(file, "%s", stream_pper_tile_begin_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdBeginPerTileExecutionQCOM");
    fprintf(file,
            "\t\tloaded_vkCmdBeginPerTileExecutionQCOM(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pper_tile_begin_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginPerTileExecutionQCOM);
}

void VulkanCppConsumer::Process_vkCmdDispatchTileQCOM(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchTileQCOM&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdispatch_tile_info;
    std::string pdispatch_tile_info_struct = GenerateStruct_VkDispatchTileInfoQCOM(stream_pdispatch_tile_info,
                                                                                   args.pDispatchTileInfo.GetPointer(),
                                                                                   args.pDispatchTileInfo.GetMetaStructPointer(),
                                                                                   *this);
    fprintf(file, "%s", stream_pdispatch_tile_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdDispatchTileQCOM");
    fprintf(file,
            "\t\tloaded_vkCmdDispatchTileQCOM(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pdispatch_tile_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDispatchTileQCOM);
}

void VulkanCppConsumer::Process_vkCmdEndPerTileExecutionQCOM(
    const ApiCallInfo&                          call_info,
    args::CmdEndPerTileExecutionQCOM&           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pper_tile_end_info;
    std::string pper_tile_end_info_struct = GenerateStruct_VkPerTileEndInfoQCOM(stream_pper_tile_end_info,
                                                                                args.pPerTileEndInfo.GetPointer(),
                                                                                args.pPerTileEndInfo.GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_pper_tile_end_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdEndPerTileExecutionQCOM");
    fprintf(file,
            "\t\tloaded_vkCmdEndPerTileExecutionQCOM(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pper_tile_end_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndPerTileExecutionQCOM);
}
void VulkanCppConsumer::Process_vkCmdBindDescriptorBufferEmbeddedSamplersEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorBufferEmbeddedSamplersEXT& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdBindDescriptorBufferEmbeddedSamplersEXT");
    fprintf(file,
            "\t\tloaded_vkCmdBindDescriptorBufferEmbeddedSamplersEXT(%s, %s, %s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkPipelineBindPoint>(args.pipelineBindPoint).c_str(),
            this->GetHandle(args.layout).c_str(),
            args.set);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindDescriptorBufferEmbeddedSamplersEXT);
}

void VulkanCppConsumer::Process_vkCmdBindDescriptorBuffersEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorBuffersEXT&          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbinding_infos;
    std::string pbinding_infos_array = "NULL";
    PointerPairContainer<decltype(args.pBindingInfos.GetPointer()), decltype(args.pBindingInfos.GetMetaStructPointer())> pbinding_infos_pair{ args.pBindingInfos.GetPointer(), args.pBindingInfos.GetMetaStructPointer(), args.bufferCount };
    std::string pbinding_infos_names = toStringJoin(pbinding_infos_pair.begin(),
                                                    pbinding_infos_pair.end(),
                                                    [&](auto pair) {{ return GenerateStruct_VkDescriptorBufferBindingInfoEXT(stream_pbinding_infos, pair.t1, pair.t2, *this); }},
                                                    ", ");
    if (stream_pbinding_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pbinding_infos.str().c_str());
        if (args.bufferCount == 1) {
            pbinding_infos_array = "&" + pbinding_infos_names;
        } else if (args.bufferCount > 1) {
            pbinding_infos_array = "pBindingInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkDescriptorBufferBindingInfoEXT %s[] = { %s };\n", pbinding_infos_array.c_str(), pbinding_infos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdBindDescriptorBuffersEXT");
    fprintf(file,
            "\t\tloaded_vkCmdBindDescriptorBuffersEXT(%s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.bufferCount,
            pbinding_infos_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindDescriptorBuffersEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDescriptorBufferOffsetsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDescriptorBufferOffsetsEXT&     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pbuffer_indices_array = "pBufferIndices_" + std::to_string(this->GetNextId());
    if (args.setCount > 0) {
        std::string pbuffer_indices_values = toStringJoin(args.pBufferIndices.GetPointer(),
                                                          args.pBufferIndices.GetPointer() + args.setCount,
                                                          [&](const auto current) { return std::to_string(current) + ""; },
                                                          ", ");
        fprintf(file, "\t\tuint32_t %s[] = { %s };\n", pbuffer_indices_array.c_str(), pbuffer_indices_values.c_str());
    } else {
        pbuffer_indices_array = "NULL";
    }
    std::string poffsets_array = "pOffsets_" + std::to_string(this->GetNextId());
    if (args.setCount > 0) {
        std::string poffsets_values = toStringJoin(args.pOffsets.GetPointer(),
                                                   args.pOffsets.GetPointer() + args.setCount,
                                                   [&](const auto current) { return std::to_string(current) + "UL"; },
                                                   ", ");
        fprintf(file, "\t\tVkDeviceSize %s[] = { %s };\n", poffsets_array.c_str(), poffsets_values.c_str());
    } else {
        poffsets_array = "NULL";
    }
    pfn_loader_.AddMethodName("vkCmdSetDescriptorBufferOffsetsEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDescriptorBufferOffsetsEXT(%s, %s, %s, %u, %u, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkPipelineBindPoint>(args.pipelineBindPoint).c_str(),
            this->GetHandle(args.layout).c_str(),
            args.firstSet,
            args.setCount,
            pbuffer_indices_array.c_str(),
            poffsets_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDescriptorBufferOffsetsEXT);
}

void VulkanCppConsumer::Process_vkGetDescriptorEXT(
    const ApiCallInfo&                          call_info,
    args::GetDescriptorEXT&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdescriptor_info;
    std::string pdescriptor_info_struct = GenerateStruct_VkDescriptorGetInfoEXT(stream_pdescriptor_info,
                                                                                args.pDescriptorInfo.GetPointer(),
                                                                                args.pDescriptorInfo.GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_pdescriptor_info.str().c_str());
    std::string pdescriptor_name = "NULL";
    if (!args.pDescriptor.IsNull()) {
        pdescriptor_name = "pDescriptor_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint8_t %s[%" PRIu64 "] = {};\n", pdescriptor_name.c_str(), util::platform::SizeTtoUint64(args.dataSize));
    }
    pfn_loader_.AddMethodName("vkGetDescriptorEXT");
    fprintf(file,
            "\t\tloaded_vkGetDescriptorEXT(%s, &%s, %" PRIu64 ", %s);\n",
            this->GetHandle(args.device).c_str(),
            pdescriptor_info_struct.c_str(),
            util::platform::SizeTtoUint64(args.dataSize),
            pdescriptor_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDescriptorEXT);
}

void VulkanCppConsumer::Process_vkGetDescriptorSetLayoutBindingOffsetEXT(
    const ApiCallInfo&                          call_info,
    args::GetDescriptorSetLayoutBindingOffsetEXT& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string poffset_name = "NULL";
    if (!args.pOffset.IsNull()) {
        poffset_name = "pOffset_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDeviceSize %s = %s;\n", poffset_name.c_str(), util::ToString(*args.pOffset.GetPointer()).c_str());
        poffset_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetDescriptorSetLayoutBindingOffsetEXT");
    fprintf(file,
            "\t\tloaded_vkGetDescriptorSetLayoutBindingOffsetEXT(%s, %s, %u, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.layout).c_str(),
            args.binding,
            poffset_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutBindingOffsetEXT);
}

void VulkanCppConsumer::Process_vkGetDescriptorSetLayoutSizeEXT(
    const ApiCallInfo&                          call_info,
    args::GetDescriptorSetLayoutSizeEXT&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string playout_size_in_bytes_name = "NULL";
    if (!args.pLayoutSizeInBytes.IsNull()) {
        playout_size_in_bytes_name = "pLayoutSizeInBytes_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDeviceSize %s = %s;\n", playout_size_in_bytes_name.c_str(), util::ToString(*args.pLayoutSizeInBytes.GetPointer()).c_str());
        playout_size_in_bytes_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetDescriptorSetLayoutSizeEXT");
    fprintf(file,
            "\t\tloaded_vkGetDescriptorSetLayoutSizeEXT(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.layout).c_str(),
            playout_size_in_bytes_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSizeEXT);
}
void VulkanCppConsumer::Process_vkCmdSetFragmentShadingRateEnumNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetFragmentShadingRateEnumNV&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string combiner_ops_array = "combiner_ops_array_" + std::to_string(this->GetNextId());
    std::string combiner_ops_values = toStringJoin(args.combinerOps.GetPointer(),
                                                   args.combinerOps.GetPointer() + 2,
                                                   [&](const VkFragmentShadingRateCombinerOpKHR current) { return util::ToString(current); },
                                                   ", ");
    fprintf(file, "\t\tVkFragmentShadingRateCombinerOpKHR %s[] = { %s };\n", combiner_ops_array.c_str(), combiner_ops_values.c_str());
    pfn_loader_.AddMethodName("vkCmdSetFragmentShadingRateEnumNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetFragmentShadingRateEnumNV(%s, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkFragmentShadingRateNV>(args.shadingRate).c_str(),
            combiner_ops_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV);
}
void VulkanCppConsumer::Process_vkGetDeviceFaultInfoEXT(
    const ApiCallInfo&                          call_info,
    args::GetDeviceFaultInfoEXT&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pfault_counts_name = "NULL";
    if (!args.pFaultCounts.IsNull()) {
        pfault_counts_name = "pFaultCounts_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDeviceFaultCountsEXT %s = {};\n", pfault_counts_name.c_str());
        pfault_counts_name.insert(0, "&");
    }
    std::string pfault_info_name = "NULL";
    if (!args.pFaultInfo.IsNull()) {
        pfault_info_name = "pFaultInfo_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDeviceFaultInfoEXT %s = {};\n", pfault_info_name.c_str());
        pfault_info_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetDeviceFaultInfoEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDeviceFaultInfoEXT(%s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pfault_counts_name.c_str(),
            pfault_info_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT);
}
void VulkanCppConsumer::Process_vkAcquireWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    args::AcquireWinrtDisplayNV&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkAcquireWinrtDisplayNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkAcquireWinrtDisplayNV(%s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            this->GetHandle(args.display).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV);
}

void VulkanCppConsumer::Process_vkGetWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    args::GetWinrtDisplayNV&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pdisplay_name = "pDisplay_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DISPLAY_KHR));
    AddKnownVariables("VkDisplayKHR", pdisplay_name, args.pDisplay.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pdisplay_name,
                         args.pDisplay.GetPointer());
    }
    pfn_loader_.AddMethodName("vkGetWinrtDisplayNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetWinrtDisplayNV(%s, %u, &%s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            args.deviceRelativeId,
            pdisplay_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetWinrtDisplayNV);
}
void VulkanCppConsumer::Process_vkCreateDirectFBSurfaceEXT(
    const ApiCallInfo&                          call_info,
    args::CreateDirectFBSurfaceEXT&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkDirectFBSurfaceCreateInfoEXT(stream_pcreate_info,
                                                                                    args.pCreateInfo.GetPointer(),
                                                                                    args.pCreateInfo.GetMetaStructPointer(),
                                                                                    *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psurface_name = "pSurface_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", psurface_name, args.pSurface.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(psurface_name,
                         args.pSurface.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateDirectFBSurfaceEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateDirectFBSurfaceEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.instance).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psurface_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceDirectFBPresentationSupportEXT& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string dfb_name = "args.dfb_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tvoid* %s;\n", dfb_name.c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceDirectFBPresentationSupportEXT");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(%s, %u, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            args.queueFamilyIndex,
            dfb_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT);
}
void VulkanCppConsumer::Process_vkCmdSetVertexInputEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetVertexInputEXT&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pvertex_binding_descriptions;
    std::string pvertex_binding_descriptions_array = "NULL";
    PointerPairContainer<decltype(args.pVertexBindingDescriptions.GetPointer()), decltype(args.pVertexBindingDescriptions.GetMetaStructPointer())> pvertex_binding_descriptions_pair{ args.pVertexBindingDescriptions.GetPointer(), args.pVertexBindingDescriptions.GetMetaStructPointer(), args.vertexBindingDescriptionCount };
    std::string pvertex_binding_descriptions_names = toStringJoin(pvertex_binding_descriptions_pair.begin(),
                                                                  pvertex_binding_descriptions_pair.end(),
                                                                  [&](auto pair) {{ return GenerateStruct_VkVertexInputBindingDescription2EXT(stream_pvertex_binding_descriptions, pair.t1, pair.t2, *this); }},
                                                                  ", ");
    if (stream_pvertex_binding_descriptions.str().length() > 0) {
        fprintf(file, "%s", stream_pvertex_binding_descriptions.str().c_str());
        if (args.vertexBindingDescriptionCount == 1) {
            pvertex_binding_descriptions_array = "&" + pvertex_binding_descriptions_names;
        } else if (args.vertexBindingDescriptionCount > 1) {
            pvertex_binding_descriptions_array = "pVertexBindingDescriptions_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkVertexInputBindingDescription2EXT %s[] = { %s };\n", pvertex_binding_descriptions_array.c_str(), pvertex_binding_descriptions_names.c_str());
        }
    }
    std::stringstream stream_pvertex_attribute_descriptions;
    std::string pvertex_attribute_descriptions_array = "NULL";
    PointerPairContainer<decltype(args.pVertexAttributeDescriptions.GetPointer()), decltype(args.pVertexAttributeDescriptions.GetMetaStructPointer())> pvertex_attribute_descriptions_pair{ args.pVertexAttributeDescriptions.GetPointer(), args.pVertexAttributeDescriptions.GetMetaStructPointer(), args.vertexAttributeDescriptionCount };
    std::string pvertex_attribute_descriptions_names = toStringJoin(pvertex_attribute_descriptions_pair.begin(),
                                                                    pvertex_attribute_descriptions_pair.end(),
                                                                    [&](auto pair) {{ return GenerateStruct_VkVertexInputAttributeDescription2EXT(stream_pvertex_attribute_descriptions, pair.t1, pair.t2, *this); }},
                                                                    ", ");
    if (stream_pvertex_attribute_descriptions.str().length() > 0) {
        fprintf(file, "%s", stream_pvertex_attribute_descriptions.str().c_str());
        if (args.vertexAttributeDescriptionCount == 1) {
            pvertex_attribute_descriptions_array = "&" + pvertex_attribute_descriptions_names;
        } else if (args.vertexAttributeDescriptionCount > 1) {
            pvertex_attribute_descriptions_array = "pVertexAttributeDescriptions_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkVertexInputAttributeDescription2EXT %s[] = { %s };\n", pvertex_attribute_descriptions_array.c_str(), pvertex_attribute_descriptions_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdSetVertexInputEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetVertexInputEXT(%s, %u, %s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.vertexBindingDescriptionCount,
            pvertex_binding_descriptions_array.c_str(),
            args.vertexAttributeDescriptionCount,
            pvertex_attribute_descriptions_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT);
}
void VulkanCppConsumer::Process_vkGetMemoryZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    args::GetMemoryZirconHandleFUCHSIA&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pget_zircon_handle_info;
    std::string pget_zircon_handle_info_struct = GenerateStruct_VkMemoryGetZirconHandleInfoFUCHSIA(stream_pget_zircon_handle_info,
                                                                                                   args.pGetZirconHandleInfo.GetPointer(),
                                                                                                   args.pGetZirconHandleInfo.GetMetaStructPointer(),
                                                                                                   *this);
    fprintf(file, "%s", stream_pget_zircon_handle_info.str().c_str());
    std::string pzircon_handle_name = "NULL";
    if (!args.pZirconHandle.IsNull()) {
        pzircon_handle_name = "pZirconHandle_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pzircon_handle_name.c_str(), util::ToString(*args.pZirconHandle.GetPointer()).c_str());
        pzircon_handle_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetMemoryZirconHandleFUCHSIA");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetMemoryZirconHandleFUCHSIA(%s, &%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pget_zircon_handle_info_struct.c_str(),
            pzircon_handle_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA);
}

void VulkanCppConsumer::Process_vkGetMemoryZirconHandlePropertiesFUCHSIA(
    const ApiCallInfo&                          call_info,
    args::GetMemoryZirconHandlePropertiesFUCHSIA& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pmemory_zircon_handle_properties_name = "NULL";
    if (!args.pMemoryZirconHandleProperties.IsNull()) {
        pmemory_zircon_handle_properties_name = "pMemoryZirconHandleProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkMemoryZirconHandlePropertiesFUCHSIA %s = {};\n", pmemory_zircon_handle_properties_name.c_str());
        pmemory_zircon_handle_properties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetMemoryZirconHandlePropertiesFUCHSIA");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetMemoryZirconHandlePropertiesFUCHSIA(%s, %s, %u, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            util::ToString<VkExternalMemoryHandleTypeFlagBits>(args.handleType).c_str(),
            args.zirconHandle,
            pmemory_zircon_handle_properties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA);
}
void VulkanCppConsumer::Process_vkGetSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    args::GetSemaphoreZirconHandleFUCHSIA&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pget_zircon_handle_info;
    std::string pget_zircon_handle_info_struct = GenerateStruct_VkSemaphoreGetZirconHandleInfoFUCHSIA(stream_pget_zircon_handle_info,
                                                                                                      args.pGetZirconHandleInfo.GetPointer(),
                                                                                                      args.pGetZirconHandleInfo.GetMetaStructPointer(),
                                                                                                      *this);
    fprintf(file, "%s", stream_pget_zircon_handle_info.str().c_str());
    std::string pzircon_handle_name = "NULL";
    if (!args.pZirconHandle.IsNull()) {
        pzircon_handle_name = "pZirconHandle_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pzircon_handle_name.c_str(), util::ToString(*args.pZirconHandle.GetPointer()).c_str());
        pzircon_handle_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetSemaphoreZirconHandleFUCHSIA");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetSemaphoreZirconHandleFUCHSIA(%s, &%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pget_zircon_handle_info_struct.c_str(),
            pzircon_handle_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA);
}

void VulkanCppConsumer::Process_vkImportSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    args::ImportSemaphoreZirconHandleFUCHSIA&   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pimport_semaphore_zircon_handle_info;
    std::string pimport_semaphore_zircon_handle_info_struct = GenerateStruct_VkImportSemaphoreZirconHandleInfoFUCHSIA(stream_pimport_semaphore_zircon_handle_info,
                                                                                                                      args.pImportSemaphoreZirconHandleInfo.GetPointer(),
                                                                                                                      args.pImportSemaphoreZirconHandleInfo.GetMetaStructPointer(),
                                                                                                                      *this);
    fprintf(file, "%s", stream_pimport_semaphore_zircon_handle_info.str().c_str());
    pfn_loader_.AddMethodName("vkImportSemaphoreZirconHandleFUCHSIA");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkImportSemaphoreZirconHandleFUCHSIA(%s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pimport_semaphore_zircon_handle_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA);
}
void VulkanCppConsumer::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    args::CmdBindInvocationMaskHUAWEI&          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdBindInvocationMaskHUAWEI");
    fprintf(file,
            "\t\tloaded_vkCmdBindInvocationMaskHUAWEI(%s, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.imageView).c_str(),
            util::ToString<VkImageLayout>(args.imageLayout).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI);
}
void VulkanCppConsumer::Process_vkGetMemoryRemoteAddressNV(
    const ApiCallInfo&                          call_info,
    args::GetMemoryRemoteAddressNV&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pmemory_get_remote_address_info;
    std::string pmemory_get_remote_address_info_struct = GenerateStruct_VkMemoryGetRemoteAddressInfoNV(stream_pmemory_get_remote_address_info,
                                                                                                       args.pMemoryGetRemoteAddressInfo.GetPointer(),
                                                                                                       args.pMemoryGetRemoteAddressInfo.GetMetaStructPointer(),
                                                                                                       *this);
    fprintf(file, "%s", stream_pmemory_get_remote_address_info.str().c_str());
    std::string paddress_name = "NULL";
    if (!args.pAddress.IsNull()) {
        paddress_name = "pAddress_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint8_t* %s = %s;\n", paddress_name.c_str(), util::ToString(*args.pAddress.GetPointer()).c_str());
        paddress_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetMemoryRemoteAddressNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetMemoryRemoteAddressNV(%s, &%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pmemory_get_remote_address_info_struct.c_str(),
            paddress_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV);
}
void VulkanCppConsumer::Process_vkCmdSetDepthBiasEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBiasEnableEXT&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetDepthBiasEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDepthBiasEnableEXT(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.depthBiasEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetLogicOpEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLogicOpEXT&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetLogicOpEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetLogicOpEXT(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkLogicOp>(args.logicOp).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT);
}

void VulkanCppConsumer::Process_vkCmdSetPatchControlPointsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPatchControlPointsEXT&          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetPatchControlPointsEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetPatchControlPointsEXT(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.patchControlPoints);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT);
}

void VulkanCppConsumer::Process_vkCmdSetPrimitiveRestartEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveRestartEnableEXT&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetPrimitiveRestartEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetPrimitiveRestartEnableEXT(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.primitiveRestartEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetRasterizerDiscardEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetRasterizerDiscardEnableEXT&     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetRasterizerDiscardEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetRasterizerDiscardEnableEXT(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.rasterizerDiscardEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT);
}
void VulkanCppConsumer::Process_vkCreateScreenSurfaceQNX(
    const ApiCallInfo&                          call_info,
    args::CreateScreenSurfaceQNX&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkScreenSurfaceCreateInfoQNX(stream_pcreate_info,
                                                                                  args.pCreateInfo.GetPointer(),
                                                                                  args.pCreateInfo.GetMetaStructPointer(),
                                                                                  *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psurface_name = "pSurface_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SURFACE_KHR));
    AddKnownVariables("VkSurfaceKHR", psurface_name, args.pSurface.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(psurface_name,
                         args.pSurface.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateScreenSurfaceQNX");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateScreenSurfaceQNX(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.instance).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psurface_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceScreenPresentationSupportQNX(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceScreenPresentationSupportQNX& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string window_name = "args.window_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tvoid* %s;\n", window_name.c_str());
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceScreenPresentationSupportQNX");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceScreenPresentationSupportQNX(%s, %u, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            args.queueFamilyIndex,
            window_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX);
}
void VulkanCppConsumer::Process_vkCmdSetColorWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorWriteEnableEXT&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcolor_write_enables_array = "pColorWriteEnables_" + std::to_string(this->GetNextId());
    if (args.attachmentCount > 0) {
        std::string pcolor_write_enables_values = toStringJoin(args.pColorWriteEnables.GetPointer(),
                                                               args.pColorWriteEnables.GetPointer() + args.attachmentCount,
                                                               [&](const auto current) { return std::to_string(current) + ""; },
                                                               ", ");
        fprintf(file, "\t\tVkBool32 %s[] = { %s };\n", pcolor_write_enables_array.c_str(), pcolor_write_enables_values.c_str());
    } else {
        pcolor_write_enables_array = "NULL";
    }
    pfn_loader_.AddMethodName("vkCmdSetColorWriteEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetColorWriteEnableEXT(%s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.attachmentCount,
            pcolor_write_enables_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT);
}
void VulkanCppConsumer::Process_vkCmdDrawMultiEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMultiEXT&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pvertex_info;
    std::string pvertex_info_array = "NULL";
    PointerPairContainer<decltype(args.pVertexInfo.GetPointer()), decltype(args.pVertexInfo.GetMetaStructPointer())> pvertex_info_pair{ args.pVertexInfo.GetPointer(), args.pVertexInfo.GetMetaStructPointer(), args.drawCount };
    std::string pvertex_info_names = toStringJoin(pvertex_info_pair.begin(),
                                                  pvertex_info_pair.end(),
                                                  [&](auto pair) {{ return GenerateStruct_VkMultiDrawInfoEXT(stream_pvertex_info, pair.t1, pair.t2, *this); }},
                                                  ", ");
    if (stream_pvertex_info.str().length() > 0) {
        fprintf(file, "%s", stream_pvertex_info.str().c_str());
        if (args.drawCount == 1) {
            pvertex_info_array = "&" + pvertex_info_names;
        } else if (args.drawCount > 1) {
            pvertex_info_array = "pVertexInfo_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkMultiDrawInfoEXT %s[] = { %s };\n", pvertex_info_array.c_str(), pvertex_info_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdDrawMultiEXT");
    fprintf(file,
            "\t\tloaded_vkCmdDrawMultiEXT(%s, %u, %s, %u, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.drawCount,
            pvertex_info_array.c_str(),
            args.instanceCount,
            args.firstInstance,
            args.stride);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMultiEXT);
}

void VulkanCppConsumer::Process_vkCmdDrawMultiIndexedEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMultiIndexedEXT&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pindex_info;
    std::string pindex_info_array = "NULL";
    PointerPairContainer<decltype(args.pIndexInfo.GetPointer()), decltype(args.pIndexInfo.GetMetaStructPointer())> pindex_info_pair{ args.pIndexInfo.GetPointer(), args.pIndexInfo.GetMetaStructPointer(), args.drawCount };
    std::string pindex_info_names = toStringJoin(pindex_info_pair.begin(),
                                                 pindex_info_pair.end(),
                                                 [&](auto pair) {{ return GenerateStruct_VkMultiDrawIndexedInfoEXT(stream_pindex_info, pair.t1, pair.t2, *this); }},
                                                 ", ");
    if (stream_pindex_info.str().length() > 0) {
        fprintf(file, "%s", stream_pindex_info.str().c_str());
        if (args.drawCount == 1) {
            pindex_info_array = "&" + pindex_info_names;
        } else if (args.drawCount > 1) {
            pindex_info_array = "pIndexInfo_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkMultiDrawIndexedInfoEXT %s[] = { %s };\n", pindex_info_array.c_str(), pindex_info_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdDrawMultiIndexedEXT");
    fprintf(file,
            "\t\tloaded_vkCmdDrawMultiIndexedEXT(%s, %u, %s, %u, %u, %u, %p);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.drawCount,
            pindex_info_array.c_str(),
            args.instanceCount,
            args.firstInstance,
            args.stride,
            args.pVertexOffset.GetPointer());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT);
}
void VulkanCppConsumer::Process_vkBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    args::BuildMicromapsEXT&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfos;
    std::string pinfos_array = "NULL";
    PointerPairContainer<decltype(args.pInfos.GetPointer()), decltype(args.pInfos.GetMetaStructPointer())> pinfos_pair{ args.pInfos.GetPointer(), args.pInfos.GetMetaStructPointer(), args.infoCount };
    std::string pinfos_names = toStringJoin(pinfos_pair.begin(),
                                            pinfos_pair.end(),
                                            [&](auto pair) {{ return GenerateStruct_VkMicromapBuildInfoEXT(stream_pinfos, pair.t1, pair.t2, *this); }},
                                            ", ");
    if (stream_pinfos.str().length() > 0) {
        fprintf(file, "%s", stream_pinfos.str().c_str());
        if (args.infoCount == 1) {
            pinfos_array = "&" + pinfos_names;
        } else if (args.infoCount > 1) {
            pinfos_array = "pInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkMicromapBuildInfoEXT %s[] = { %s };\n", pinfos_array.c_str(), pinfos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkBuildMicromapsEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkBuildMicromapsEXT(%s, %s, %u, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.deferredOperation).c_str(),
            args.infoCount,
            pinfos_array.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBuildMicromapsEXT);
}

void VulkanCppConsumer::Process_vkCmdBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBuildMicromapsEXT&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfos;
    std::string pinfos_array = "NULL";
    PointerPairContainer<decltype(args.pInfos.GetPointer()), decltype(args.pInfos.GetMetaStructPointer())> pinfos_pair{ args.pInfos.GetPointer(), args.pInfos.GetMetaStructPointer(), args.infoCount };
    std::string pinfos_names = toStringJoin(pinfos_pair.begin(),
                                            pinfos_pair.end(),
                                            [&](auto pair) {{ return GenerateStruct_VkMicromapBuildInfoEXT(stream_pinfos, pair.t1, pair.t2, *this); }},
                                            ", ");
    if (stream_pinfos.str().length() > 0) {
        fprintf(file, "%s", stream_pinfos.str().c_str());
        if (args.infoCount == 1) {
            pinfos_array = "&" + pinfos_names;
        } else if (args.infoCount > 1) {
            pinfos_array = "pInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkMicromapBuildInfoEXT %s[] = { %s };\n", pinfos_array.c_str(), pinfos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdBuildMicromapsEXT");
    fprintf(file,
            "\t\tloaded_vkCmdBuildMicromapsEXT(%s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.infoCount,
            pinfos_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT);
}

void VulkanCppConsumer::Process_vkCmdCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToMicromapEXT&           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkCopyMemoryToMicromapInfoEXT(stream_pinfo,
                                                                            args.pInfo.GetPointer(),
                                                                            args.pInfo.GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyMemoryToMicromapEXT");
    fprintf(file,
            "\t\tloaded_vkCmdCopyMemoryToMicromapEXT(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT);
}

void VulkanCppConsumer::Process_vkCmdCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMicromapEXT&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkCopyMicromapInfoEXT(stream_pinfo,
                                                                    args.pInfo.GetPointer(),
                                                                    args.pInfo.GetMetaStructPointer(),
                                                                    *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyMicromapEXT");
    fprintf(file,
            "\t\tloaded_vkCmdCopyMicromapEXT(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT);
}

void VulkanCppConsumer::Process_vkCmdCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMicromapToMemoryEXT&           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkCopyMicromapToMemoryInfoEXT(stream_pinfo,
                                                                            args.pInfo.GetPointer(),
                                                                            args.pInfo.GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyMicromapToMemoryEXT");
    fprintf(file,
            "\t\tloaded_vkCmdCopyMicromapToMemoryEXT(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT);
}

void VulkanCppConsumer::Process_vkCmdWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::CmdWriteMicromapsPropertiesEXT&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pmicromaps_array = "NULL";
    std::string pmicromaps_values = toStringJoin(args.pMicromaps.GetPointer(),
                                                 args.pMicromaps.GetPointer() + args.micromapCount,
                                                 [&](const format::HandleId current) { return this->GetHandle(current); },
                                                 ", ");
    if (args.micromapCount == 1 && pmicromaps_values != "VK_NULL_HANDLE") {
        pmicromaps_array = "&" + pmicromaps_values;
    } else if (args.micromapCount > 1) {
        pmicromaps_array = "pmicromaps_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkMicromapEXT %s[] = { %s };\n", pmicromaps_array.c_str(), pmicromaps_values.c_str());
    }
    pfn_loader_.AddMethodName("vkCmdWriteMicromapsPropertiesEXT");
    fprintf(file,
            "\t\tloaded_vkCmdWriteMicromapsPropertiesEXT(%s, %u, %s, %s, %s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.micromapCount,
            pmicromaps_array.c_str(),
            util::ToString<VkQueryType>(args.queryType).c_str(),
            this->GetHandle(args.queryPool).c_str(),
            args.firstQuery);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT);
}

void VulkanCppConsumer::Process_vkCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::CopyMemoryToMicromapEXT&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkCopyMemoryToMicromapInfoEXT(stream_pinfo,
                                                                            args.pInfo.GetPointer(),
                                                                            args.pInfo.GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCopyMemoryToMicromapEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCopyMemoryToMicromapEXT(%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.deferredOperation).c_str(),
            pinfo_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT);
}

void VulkanCppConsumer::Process_vkCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::CopyMicromapEXT&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkCopyMicromapInfoEXT(stream_pinfo,
                                                                    args.pInfo.GetPointer(),
                                                                    args.pInfo.GetMetaStructPointer(),
                                                                    *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCopyMicromapEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCopyMicromapEXT(%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.deferredOperation).c_str(),
            pinfo_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCopyMicromapEXT);
}

void VulkanCppConsumer::Process_vkCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    args::CopyMicromapToMemoryEXT&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkCopyMicromapToMemoryInfoEXT(stream_pinfo,
                                                                            args.pInfo.GetPointer(),
                                                                            args.pInfo.GetMetaStructPointer(),
                                                                            *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCopyMicromapToMemoryEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCopyMicromapToMemoryEXT(%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.deferredOperation).c_str(),
            pinfo_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT);
}

void VulkanCppConsumer::Process_vkCreateMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::CreateMicromapEXT&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkMicromapCreateInfoEXT(stream_pcreate_info,
                                                                             args.pCreateInfo.GetPointer(),
                                                                             args.pCreateInfo.GetMetaStructPointer(),
                                                                             *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pmicromap_name = "pMicromap_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_MICROMAP_EXT));
    AddKnownVariables("VkMicromapEXT", pmicromap_name, args.pMicromap.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pmicromap_name,
                         args.pMicromap.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateMicromapEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateMicromapEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pmicromap_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateMicromapEXT);
}

void VulkanCppConsumer::Process_vkDestroyMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyMicromapEXT&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyMicromapEXT");
    fprintf(file,
            "\t\tloaded_vkDestroyMicromapEXT(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.micromap).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyMicromapEXT);
}

void VulkanCppConsumer::Process_vkGetDeviceMicromapCompatibilityEXT(
    const ApiCallInfo&                          call_info,
    args::GetDeviceMicromapCompatibilityEXT&    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pversion_info;
    std::string pversion_info_struct = GenerateStruct_VkMicromapVersionInfoEXT(stream_pversion_info,
                                                                               args.pVersionInfo.GetPointer(),
                                                                               args.pVersionInfo.GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_pversion_info.str().c_str());
    std::string pcompatibility_name = "NULL";
    if (!args.pCompatibility.IsNull()) {
        pcompatibility_name = "pCompatibility_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkAccelerationStructureCompatibilityKHR %s = %s;\n", pcompatibility_name.c_str(), util::ToString(*args.pCompatibility.GetPointer()).c_str());
        pcompatibility_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetDeviceMicromapCompatibilityEXT");
    fprintf(file,
            "\t\tloaded_vkGetDeviceMicromapCompatibilityEXT(%s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pversion_info_struct.c_str(),
            pcompatibility_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT);
}

void VulkanCppConsumer::Process_vkGetMicromapBuildSizesEXT(
    const ApiCallInfo&                          call_info,
    args::GetMicromapBuildSizesEXT&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbuild_info;
    std::string pbuild_info_struct = GenerateStruct_VkMicromapBuildInfoEXT(stream_pbuild_info,
                                                                           args.pBuildInfo.GetPointer(),
                                                                           args.pBuildInfo.GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_pbuild_info.str().c_str());
    std::string psize_info_name = "NULL";
    if (!args.pSizeInfo.IsNull()) {
        psize_info_name = "pSizeInfo_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkMicromapBuildSizesInfoEXT %s = {};\n", psize_info_name.c_str());
        psize_info_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetMicromapBuildSizesEXT");
    fprintf(file,
            "\t\tloaded_vkGetMicromapBuildSizesEXT(%s, %s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            util::ToString<VkAccelerationStructureBuildTypeKHR>(args.buildType).c_str(),
            pbuild_info_struct.c_str(),
            psize_info_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT);
}

void VulkanCppConsumer::Process_vkWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::WriteMicromapsPropertiesEXT&          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pmicromaps_array = "NULL";
    std::string pmicromaps_values = toStringJoin(args.pMicromaps.GetPointer(),
                                                 args.pMicromaps.GetPointer() + args.micromapCount,
                                                 [&](const format::HandleId current) { return this->GetHandle(current); },
                                                 ", ");
    if (args.micromapCount == 1 && pmicromaps_values != "VK_NULL_HANDLE") {
        pmicromaps_array = "&" + pmicromaps_values;
    } else if (args.micromapCount > 1) {
        pmicromaps_array = "pmicromaps_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkMicromapEXT %s[] = { %s };\n", pmicromaps_array.c_str(), pmicromaps_values.c_str());
    }
    std::string pdata_name = "NULL";
    if (!args.pData.IsNull()) {
        pdata_name = "pData_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint8_t %s[%" PRIu64 "] = {};\n", pdata_name.c_str(), util::platform::SizeTtoUint64(args.dataSize));
    }
    pfn_loader_.AddMethodName("vkWriteMicromapsPropertiesEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkWriteMicromapsPropertiesEXT(%s, %u, %s, %s, %" PRIu64 ", %s, %" PRIu64 "), %s);\n",
            this->GetHandle(args.device).c_str(),
            args.micromapCount,
            pmicromaps_array.c_str(),
            util::ToString<VkQueryType>(args.queryType).c_str(),
            util::platform::SizeTtoUint64(args.dataSize),
            pdata_name.c_str(),
            util::platform::SizeTtoUint64(args.stride),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT);
}
void VulkanCppConsumer::Process_vkCmdDrawClusterHUAWEI(
    const ApiCallInfo&                          call_info,
    args::CmdDrawClusterHUAWEI&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawClusterHUAWEI");
    fprintf(file,
            "\t\tloaded_vkCmdDrawClusterHUAWEI(%s, %u, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.groupCountX,
            args.groupCountY,
            args.groupCountZ);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI);
}

void VulkanCppConsumer::Process_vkCmdDrawClusterIndirectHUAWEI(
    const ApiCallInfo&                          call_info,
    args::CmdDrawClusterIndirectHUAWEI&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawClusterIndirectHUAWEI");
    fprintf(file,
            "\t\tloaded_vkCmdDrawClusterIndirectHUAWEI(%s, %s, %" PRIu64 "UL);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.buffer).c_str(),
            args.offset);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI);
}
void VulkanCppConsumer::Process_vkSetDeviceMemoryPriorityEXT(
    const ApiCallInfo&                          call_info,
    args::SetDeviceMemoryPriorityEXT&           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkSetDeviceMemoryPriorityEXT");
    fprintf(file,
            "\t\tloaded_vkSetDeviceMemoryPriorityEXT(%s, %s, %f);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.memory).c_str(),
            args.priority);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT);
}
void VulkanCppConsumer::Process_vkCmdSetDispatchParametersARM(
    const ApiCallInfo&                          call_info,
    args::CmdSetDispatchParametersARM&          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdispatch_parameters;
    std::string pdispatch_parameters_struct = GenerateStruct_VkDispatchParametersARM(stream_pdispatch_parameters,
                                                                                     args.pDispatchParameters.GetPointer(),
                                                                                     args.pDispatchParameters.GetMetaStructPointer(),
                                                                                     *this);
    fprintf(file, "%s", stream_pdispatch_parameters.str().c_str());
    pfn_loader_.AddMethodName("vkCmdSetDispatchParametersARM");
    fprintf(file,
            "\t\tloaded_vkCmdSetDispatchParametersARM(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pdispatch_parameters_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDispatchParametersARM);
}
void VulkanCppConsumer::Process_vkGetDescriptorSetHostMappingVALVE(
    const ApiCallInfo&                          call_info,
    args::GetDescriptorSetHostMappingVALVE&     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pp_data_name = "NULL";
    if (!args.ppData.IsNull()) {
        pp_data_name = "ppData_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint8_t* %s = %s;\n", pp_data_name.c_str(), util::ToString(*args.ppData.GetPointer()).c_str());
        pp_data_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetDescriptorSetHostMappingVALVE");
    fprintf(file,
            "\t\tloaded_vkGetDescriptorSetHostMappingVALVE(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.descriptorSet).c_str(),
            pp_data_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE);
}

void VulkanCppConsumer::Process_vkGetDescriptorSetLayoutHostMappingInfoVALVE(
    const ApiCallInfo&                          call_info,
    args::GetDescriptorSetLayoutHostMappingInfoVALVE& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbinding_reference;
    std::string pbinding_reference_struct = GenerateStruct_VkDescriptorSetBindingReferenceVALVE(stream_pbinding_reference,
                                                                                                args.pBindingReference.GetPointer(),
                                                                                                args.pBindingReference.GetMetaStructPointer(),
                                                                                                *this);
    fprintf(file, "%s", stream_pbinding_reference.str().c_str());
    std::string phost_mapping_name = "NULL";
    if (!args.pHostMapping.IsNull()) {
        phost_mapping_name = "pHostMapping_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDescriptorSetLayoutHostMappingInfoVALVE %s = {};\n", phost_mapping_name.c_str());
        phost_mapping_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetDescriptorSetLayoutHostMappingInfoVALVE");
    fprintf(file,
            "\t\tloaded_vkGetDescriptorSetLayoutHostMappingInfoVALVE(%s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pbinding_reference_struct.c_str(),
            phost_mapping_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE);
}
void VulkanCppConsumer::Process_vkCmdUpdatePipelineIndirectBufferNV(
    const ApiCallInfo&                          call_info,
    args::CmdUpdatePipelineIndirectBufferNV&    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdUpdatePipelineIndirectBufferNV");
    fprintf(file,
            "\t\tloaded_vkCmdUpdatePipelineIndirectBufferNV(%s, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkPipelineBindPoint>(args.pipelineBindPoint).c_str(),
            this->GetHandle(args.pipeline).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdUpdatePipelineIndirectBufferNV);
}

void VulkanCppConsumer::Process_vkGetPipelineIndirectDeviceAddressNV(
    const ApiCallInfo&                          call_info,
    args::GetPipelineIndirectDeviceAddressNV&   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkPipelineIndirectDeviceAddressInfoNV(stream_pinfo,
                                                                                    args.pInfo.GetPointer(),
                                                                                    args.pInfo.GetMetaStructPointer(),
                                                                                    *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkGetPipelineIndirectDeviceAddressNV");
    fprintf(file,
            "\t\tloaded_vkGetPipelineIndirectDeviceAddressNV(%s, &%s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPipelineIndirectDeviceAddressNV);
}

void VulkanCppConsumer::Process_vkGetPipelineIndirectMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    args::GetPipelineIndirectMemoryRequirementsNV& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkComputePipelineCreateInfo(stream_pcreate_info,
                                                                                 args.pCreateInfo.GetPointer(),
                                                                                 args.pCreateInfo.GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pmemory_requirements_name = "NULL";
    if (!args.pMemoryRequirements.IsNull()) {
        pmemory_requirements_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkMemoryRequirements2 %s = {};\n", pmemory_requirements_name.c_str());
        pmemory_requirements_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPipelineIndirectMemoryRequirementsNV");
    fprintf(file,
            "\t\tloaded_vkGetPipelineIndirectMemoryRequirementsNV(%s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            pmemory_requirements_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPipelineIndirectMemoryRequirementsNV);
}
void VulkanCppConsumer::Process_vkCmdSetAlphaToCoverageEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetAlphaToCoverageEnableEXT&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetAlphaToCoverageEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetAlphaToCoverageEnableEXT(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.alphaToCoverageEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetAlphaToOneEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetAlphaToOneEnableEXT&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetAlphaToOneEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetAlphaToOneEnableEXT(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.alphaToOneEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetColorBlendAdvancedEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorBlendAdvancedEXT&          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcolor_blend_advanced;
    std::string pcolor_blend_advanced_array = "NULL";
    PointerPairContainer<decltype(args.pColorBlendAdvanced.GetPointer()), decltype(args.pColorBlendAdvanced.GetMetaStructPointer())> pcolor_blend_advanced_pair{ args.pColorBlendAdvanced.GetPointer(), args.pColorBlendAdvanced.GetMetaStructPointer(), args.attachmentCount };
    std::string pcolor_blend_advanced_names = toStringJoin(pcolor_blend_advanced_pair.begin(),
                                                           pcolor_blend_advanced_pair.end(),
                                                           [&](auto pair) {{ return GenerateStruct_VkColorBlendAdvancedEXT(stream_pcolor_blend_advanced, pair.t1, pair.t2, *this); }},
                                                           ", ");
    if (stream_pcolor_blend_advanced.str().length() > 0) {
        fprintf(file, "%s", stream_pcolor_blend_advanced.str().c_str());
        if (args.attachmentCount == 1) {
            pcolor_blend_advanced_array = "&" + pcolor_blend_advanced_names;
        } else if (args.attachmentCount > 1) {
            pcolor_blend_advanced_array = "pColorBlendAdvanced_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkColorBlendAdvancedEXT %s[] = { %s };\n", pcolor_blend_advanced_array.c_str(), pcolor_blend_advanced_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdSetColorBlendAdvancedEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetColorBlendAdvancedEXT(%s, %u, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.firstAttachment,
            args.attachmentCount,
            pcolor_blend_advanced_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT);
}

void VulkanCppConsumer::Process_vkCmdSetColorBlendEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorBlendEnableEXT&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcolor_blend_enables_array = "pColorBlendEnables_" + std::to_string(this->GetNextId());
    if (args.attachmentCount > 0) {
        std::string pcolor_blend_enables_values = toStringJoin(args.pColorBlendEnables.GetPointer(),
                                                               args.pColorBlendEnables.GetPointer() + args.attachmentCount,
                                                               [&](const auto current) { return std::to_string(current) + ""; },
                                                               ", ");
        fprintf(file, "\t\tVkBool32 %s[] = { %s };\n", pcolor_blend_enables_array.c_str(), pcolor_blend_enables_values.c_str());
    } else {
        pcolor_blend_enables_array = "NULL";
    }
    pfn_loader_.AddMethodName("vkCmdSetColorBlendEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetColorBlendEnableEXT(%s, %u, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.firstAttachment,
            args.attachmentCount,
            pcolor_blend_enables_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetColorBlendEquationEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorBlendEquationEXT&          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcolor_blend_equations;
    std::string pcolor_blend_equations_array = "NULL";
    PointerPairContainer<decltype(args.pColorBlendEquations.GetPointer()), decltype(args.pColorBlendEquations.GetMetaStructPointer())> pcolor_blend_equations_pair{ args.pColorBlendEquations.GetPointer(), args.pColorBlendEquations.GetMetaStructPointer(), args.attachmentCount };
    std::string pcolor_blend_equations_names = toStringJoin(pcolor_blend_equations_pair.begin(),
                                                            pcolor_blend_equations_pair.end(),
                                                            [&](auto pair) {{ return GenerateStruct_VkColorBlendEquationEXT(stream_pcolor_blend_equations, pair.t1, pair.t2, *this); }},
                                                            ", ");
    if (stream_pcolor_blend_equations.str().length() > 0) {
        fprintf(file, "%s", stream_pcolor_blend_equations.str().c_str());
        if (args.attachmentCount == 1) {
            pcolor_blend_equations_array = "&" + pcolor_blend_equations_names;
        } else if (args.attachmentCount > 1) {
            pcolor_blend_equations_array = "pColorBlendEquations_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkColorBlendEquationEXT %s[] = { %s };\n", pcolor_blend_equations_array.c_str(), pcolor_blend_equations_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdSetColorBlendEquationEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetColorBlendEquationEXT(%s, %u, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.firstAttachment,
            args.attachmentCount,
            pcolor_blend_equations_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT);
}

void VulkanCppConsumer::Process_vkCmdSetColorWriteMaskEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorWriteMaskEXT&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcolor_write_masks_array = "pcolor_write_masks_array_" + std::to_string(this->GetNextId());
    std::string pcolor_write_masks_values = toStringJoin(args.pColorWriteMasks.GetPointer(),
                                                         args.pColorWriteMasks.GetPointer() + args.attachmentCount,
                                                         [&](const VkColorComponentFlags current) { return util::ToString(current); },
                                                         ", ");
    if (args.attachmentCount > 0) {
        pcolor_write_masks_array = "pcolor_write_masks_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkColorComponentFlags %s[] = { %s };\n", pcolor_write_masks_array.c_str(), pcolor_write_masks_values.c_str());
    }
    pfn_loader_.AddMethodName("vkCmdSetColorWriteMaskEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetColorWriteMaskEXT(%s, %u, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.firstAttachment,
            args.attachmentCount,
            pcolor_write_masks_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT);
}

void VulkanCppConsumer::Process_vkCmdSetConservativeRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetConservativeRasterizationModeEXT& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetConservativeRasterizationModeEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetConservativeRasterizationModeEXT(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkConservativeRasterizationModeEXT>(args.conservativeRasterizationMode).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT);
}

void VulkanCppConsumer::Process_vkCmdSetCoverageModulationModeNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageModulationModeNV&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetCoverageModulationModeNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetCoverageModulationModeNV(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkCoverageModulationModeNV>(args.coverageModulationMode).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV);
}

void VulkanCppConsumer::Process_vkCmdSetCoverageModulationTableEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageModulationTableEnableNV& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetCoverageModulationTableEnableNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetCoverageModulationTableEnableNV(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.coverageModulationTableEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV);
}

void VulkanCppConsumer::Process_vkCmdSetCoverageModulationTableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageModulationTableNV&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcoverage_modulation_table_array = "pCoverageModulationTable_" + std::to_string(this->GetNextId());
    if (args.coverageModulationTableCount > 0) {
        std::string pcoverage_modulation_table_values = toStringJoin(args.pCoverageModulationTable.GetPointer(),
                                                                     args.pCoverageModulationTable.GetPointer() + args.coverageModulationTableCount,
                                                                     [&](const auto current) { return std::to_string(current) + ""; },
                                                                     ", ");
        fprintf(file, "\t\tfloat %s[] = { %s };\n", pcoverage_modulation_table_array.c_str(), pcoverage_modulation_table_values.c_str());
    } else {
        pcoverage_modulation_table_array = "NULL";
    }
    pfn_loader_.AddMethodName("vkCmdSetCoverageModulationTableNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetCoverageModulationTableNV(%s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.coverageModulationTableCount,
            pcoverage_modulation_table_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV);
}

void VulkanCppConsumer::Process_vkCmdSetCoverageReductionModeNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageReductionModeNV&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetCoverageReductionModeNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetCoverageReductionModeNV(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkCoverageReductionModeNV>(args.coverageReductionMode).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV);
}

void VulkanCppConsumer::Process_vkCmdSetCoverageToColorEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageToColorEnableNV&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetCoverageToColorEnableNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetCoverageToColorEnableNV(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.coverageToColorEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV);
}

void VulkanCppConsumer::Process_vkCmdSetCoverageToColorLocationNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageToColorLocationNV&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetCoverageToColorLocationNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetCoverageToColorLocationNV(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.coverageToColorLocation);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV);
}

void VulkanCppConsumer::Process_vkCmdSetDepthClampEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthClampEnableEXT&            args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetDepthClampEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDepthClampEnableEXT(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.depthClampEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDepthClipEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthClipEnableEXT&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetDepthClipEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDepthClipEnableEXT(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.depthClipEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDepthClipNegativeOneToOneEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthClipNegativeOneToOneEXT&   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetDepthClipNegativeOneToOneEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDepthClipNegativeOneToOneEXT(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.negativeOneToOne);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT);
}

void VulkanCppConsumer::Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetExtraPrimitiveOverestimationSizeEXT& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetExtraPrimitiveOverestimationSizeEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetExtraPrimitiveOverestimationSizeEXT(%s, %f);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.extraPrimitiveOverestimationSize);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT);
}

void VulkanCppConsumer::Process_vkCmdSetLineRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineRasterizationModeEXT&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetLineRasterizationModeEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetLineRasterizationModeEXT(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkLineRasterizationModeEXT>(args.lineRasterizationMode).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT);
}

void VulkanCppConsumer::Process_vkCmdSetLineStippleEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineStippleEnableEXT&           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetLineStippleEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetLineStippleEnableEXT(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.stippledLineEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetLogicOpEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLogicOpEnableEXT&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetLogicOpEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetLogicOpEnableEXT(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.logicOpEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetPolygonModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPolygonModeEXT&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetPolygonModeEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetPolygonModeEXT(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkPolygonMode>(args.polygonMode).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT);
}

void VulkanCppConsumer::Process_vkCmdSetProvokingVertexModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetProvokingVertexModeEXT&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetProvokingVertexModeEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetProvokingVertexModeEXT(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkProvokingVertexModeEXT>(args.provokingVertexMode).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT);
}

void VulkanCppConsumer::Process_vkCmdSetRasterizationSamplesEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetRasterizationSamplesEXT&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetRasterizationSamplesEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetRasterizationSamplesEXT(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkSampleCountFlagBits>(args.rasterizationSamples).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT);
}

void VulkanCppConsumer::Process_vkCmdSetRasterizationStreamEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetRasterizationStreamEXT&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetRasterizationStreamEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetRasterizationStreamEXT(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.rasterizationStream);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT);
}

void VulkanCppConsumer::Process_vkCmdSetRepresentativeFragmentTestEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetRepresentativeFragmentTestEnableNV& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetRepresentativeFragmentTestEnableNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetRepresentativeFragmentTestEnableNV(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.representativeFragmentTestEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV);
}

void VulkanCppConsumer::Process_vkCmdSetSampleLocationsEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetSampleLocationsEnableEXT&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetSampleLocationsEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetSampleLocationsEnableEXT(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.sampleLocationsEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT);
}

void VulkanCppConsumer::Process_vkCmdSetSampleMaskEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetSampleMaskEXT&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string psample_mask_array = "pSampleMask_" + std::to_string(this->GetNextId());
    if ((args.samples + 31) / 32 > 0 && args.pSampleMask.GetPointer() != nullptr) {
        std::string psample_mask_values = toStringJoin(args.pSampleMask.GetPointer(),
                                                       args.pSampleMask.GetPointer() + (args.samples + 31) / 32,
                                                       [&](const auto current) { return std::to_string(current) + ""; },
                                                       ", ");
        fprintf(file, "\t\tVkSampleMask %s[] = { %s };\n", psample_mask_array.c_str(), psample_mask_values.c_str());
    } else {
        psample_mask_array = "NULL";
    }
    pfn_loader_.AddMethodName("vkCmdSetSampleMaskEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetSampleMaskEXT(%s, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkSampleCountFlagBits>(args.samples).c_str(),
            psample_mask_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT);
}

void VulkanCppConsumer::Process_vkCmdSetShadingRateImageEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetShadingRateImageEnableNV&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetShadingRateImageEnableNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetShadingRateImageEnableNV(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.shadingRateImageEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV);
}

void VulkanCppConsumer::Process_vkCmdSetTessellationDomainOriginEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetTessellationDomainOriginEXT&    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetTessellationDomainOriginEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetTessellationDomainOriginEXT(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkTessellationDomainOrigin>(args.domainOrigin).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT);
}

void VulkanCppConsumer::Process_vkCmdSetViewportSwizzleNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportSwizzleNV&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pviewport_swizzles;
    std::string pviewport_swizzles_array = "NULL";
    PointerPairContainer<decltype(args.pViewportSwizzles.GetPointer()), decltype(args.pViewportSwizzles.GetMetaStructPointer())> pviewport_swizzles_pair{ args.pViewportSwizzles.GetPointer(), args.pViewportSwizzles.GetMetaStructPointer(), args.viewportCount };
    std::string pviewport_swizzles_names = toStringJoin(pviewport_swizzles_pair.begin(),
                                                        pviewport_swizzles_pair.end(),
                                                        [&](auto pair) {{ return GenerateStruct_VkViewportSwizzleNV(stream_pviewport_swizzles, pair.t1, pair.t2, *this); }},
                                                        ", ");
    if (stream_pviewport_swizzles.str().length() > 0) {
        fprintf(file, "%s", stream_pviewport_swizzles.str().c_str());
        if (args.viewportCount == 1) {
            pviewport_swizzles_array = "&" + pviewport_swizzles_names;
        } else if (args.viewportCount > 1) {
            pviewport_swizzles_array = "pViewportSwizzles_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkViewportSwizzleNV %s[] = { %s };\n", pviewport_swizzles_array.c_str(), pviewport_swizzles_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdSetViewportSwizzleNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetViewportSwizzleNV(%s, %u, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.firstViewport,
            args.viewportCount,
            pviewport_swizzles_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV);
}

void VulkanCppConsumer::Process_vkCmdSetViewportWScalingEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportWScalingEnableNV&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetViewportWScalingEnableNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetViewportWScalingEnableNV(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.viewportWScalingEnable);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV);
}
void VulkanCppConsumer::Process_vkBindTensorMemoryARM(
    const ApiCallInfo&                          call_info,
    args::BindTensorMemoryARM&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbind_infos;
    std::string pbind_infos_array = "NULL";
    PointerPairContainer<decltype(args.pBindInfos.GetPointer()), decltype(args.pBindInfos.GetMetaStructPointer())> pbind_infos_pair{ args.pBindInfos.GetPointer(), args.pBindInfos.GetMetaStructPointer(), args.bindInfoCount };
    std::string pbind_infos_names = toStringJoin(pbind_infos_pair.begin(),
                                                 pbind_infos_pair.end(),
                                                 [&](auto pair) {{ return GenerateStruct_VkBindTensorMemoryInfoARM(stream_pbind_infos, pair.t1, pair.t2, *this); }},
                                                 ", ");
    if (stream_pbind_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pbind_infos.str().c_str());
        if (args.bindInfoCount == 1) {
            pbind_infos_array = "&" + pbind_infos_names;
        } else if (args.bindInfoCount > 1) {
            pbind_infos_array = "pBindInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBindTensorMemoryInfoARM %s[] = { %s };\n", pbind_infos_array.c_str(), pbind_infos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkBindTensorMemoryARM");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkBindTensorMemoryARM(%s, %u, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            args.bindInfoCount,
            pbind_infos_array.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindTensorMemoryARM);
}

void VulkanCppConsumer::Process_vkCmdCopyTensorARM(
    const ApiCallInfo&                          call_info,
    args::CmdCopyTensorARM&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcopy_tensor_info;
    std::string pcopy_tensor_info_struct = GenerateStruct_VkCopyTensorInfoARM(stream_pcopy_tensor_info,
                                                                              args.pCopyTensorInfo.GetPointer(),
                                                                              args.pCopyTensorInfo.GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "%s", stream_pcopy_tensor_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyTensorARM");
    fprintf(file,
            "\t\tloaded_vkCmdCopyTensorARM(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pcopy_tensor_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyTensorARM);
}

void VulkanCppConsumer::Process_vkCreateTensorARM(
    const ApiCallInfo&                          call_info,
    args::CreateTensorARM&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkTensorCreateInfoARM(stream_pcreate_info,
                                                                           args.pCreateInfo.GetPointer(),
                                                                           args.pCreateInfo.GetMetaStructPointer(),
                                                                           *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string ptensor_name = "pTensor_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_TENSOR_ARM));
    AddKnownVariables("VkTensorARM", ptensor_name, args.pTensor.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(ptensor_name,
                         args.pTensor.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateTensorARM");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateTensorARM(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            ptensor_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateTensorARM);
}

void VulkanCppConsumer::Process_vkCreateTensorViewARM(
    const ApiCallInfo&                          call_info,
    args::CreateTensorViewARM&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkTensorViewCreateInfoARM(stream_pcreate_info,
                                                                               args.pCreateInfo.GetPointer(),
                                                                               args.pCreateInfo.GetMetaStructPointer(),
                                                                               *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pview_name = "pView_" + std::to_string(this->GetNextId());
    AddKnownVariables("VkTensorViewARM", pview_name, args.pView.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pview_name,
                         args.pView.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateTensorViewARM");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateTensorViewARM(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pview_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateTensorViewARM);
}

void VulkanCppConsumer::Process_vkDestroyTensorARM(
    const ApiCallInfo&                          call_info,
    args::DestroyTensorARM&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyTensorARM");
    fprintf(file,
            "\t\tloaded_vkDestroyTensorARM(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.tensor).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyTensorARM);
}

void VulkanCppConsumer::Process_vkDestroyTensorViewARM(
    const ApiCallInfo&                          call_info,
    args::DestroyTensorViewARM&                 args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyTensorViewARM");
    fprintf(file,
            "\t\tloaded_vkDestroyTensorViewARM(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.tensorView).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyTensorViewARM);
}

void VulkanCppConsumer::Process_vkGetDeviceTensorMemoryRequirementsARM(
    const ApiCallInfo&                          call_info,
    args::GetDeviceTensorMemoryRequirementsARM& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDeviceTensorMemoryRequirementsARM(stream_pinfo,
                                                                                  args.pInfo.GetPointer(),
                                                                                  args.pInfo.GetMetaStructPointer(),
                                                                                  *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string pmemory_requirements_name = "NULL";
    if (!args.pMemoryRequirements.IsNull()) {
        pmemory_requirements_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkMemoryRequirements2 %s = {};\n", pmemory_requirements_name.c_str());
        pmemory_requirements_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetDeviceTensorMemoryRequirementsARM");
    fprintf(file,
            "\t\tloaded_vkGetDeviceTensorMemoryRequirementsARM(%s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str(),
            pmemory_requirements_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceTensorMemoryRequirementsARM);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceExternalTensorPropertiesARM(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalTensorPropertiesARM& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pexternal_tensor_info;
    std::string pexternal_tensor_info_struct = GenerateStruct_VkPhysicalDeviceExternalTensorInfoARM(stream_pexternal_tensor_info,
                                                                                                    args.pExternalTensorInfo.GetPointer(),
                                                                                                    args.pExternalTensorInfo.GetMetaStructPointer(),
                                                                                                    *this);
    fprintf(file, "%s", stream_pexternal_tensor_info.str().c_str());
    std::string pexternal_tensor_properties_name = "NULL";
    if (!args.pExternalTensorProperties.IsNull()) {
        pexternal_tensor_properties_name = "pExternalTensorProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkExternalTensorPropertiesARM %s = {};\n", pexternal_tensor_properties_name.c_str());
        pexternal_tensor_properties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceExternalTensorPropertiesARM");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceExternalTensorPropertiesARM(%s, &%s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pexternal_tensor_info_struct.c_str(),
            pexternal_tensor_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalTensorPropertiesARM);
}

void VulkanCppConsumer::Process_vkGetTensorMemoryRequirementsARM(
    const ApiCallInfo&                          call_info,
    args::GetTensorMemoryRequirementsARM&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkTensorMemoryRequirementsInfoARM(stream_pinfo,
                                                                                args.pInfo.GetPointer(),
                                                                                args.pInfo.GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string pmemory_requirements_name = "NULL";
    if (!args.pMemoryRequirements.IsNull()) {
        pmemory_requirements_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkMemoryRequirements2 %s = {};\n", pmemory_requirements_name.c_str());
        pmemory_requirements_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetTensorMemoryRequirementsARM");
    fprintf(file,
            "\t\tloaded_vkGetTensorMemoryRequirementsARM(%s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str(),
            pmemory_requirements_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetTensorMemoryRequirementsARM);
}
void VulkanCppConsumer::Process_vkGetShaderModuleCreateInfoIdentifierEXT(
    const ApiCallInfo&                          call_info,
    args::GetShaderModuleCreateInfoIdentifierEXT& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkShaderModuleCreateInfo(stream_pcreate_info,
                                                                              args.pCreateInfo.GetPointer(),
                                                                              args.pCreateInfo.GetMetaStructPointer(),
                                                                              *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pidentifier_name = "NULL";
    if (!args.pIdentifier.IsNull()) {
        pidentifier_name = "pIdentifier_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkShaderModuleIdentifierEXT %s = {};\n", pidentifier_name.c_str());
        pidentifier_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetShaderModuleCreateInfoIdentifierEXT");
    fprintf(file,
            "\t\tloaded_vkGetShaderModuleCreateInfoIdentifierEXT(%s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            pidentifier_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT);
}

void VulkanCppConsumer::Process_vkGetShaderModuleIdentifierEXT(
    const ApiCallInfo&                          call_info,
    args::GetShaderModuleIdentifierEXT&         args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pidentifier_name = "NULL";
    if (!args.pIdentifier.IsNull()) {
        pidentifier_name = "pIdentifier_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkShaderModuleIdentifierEXT %s = {};\n", pidentifier_name.c_str());
        pidentifier_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetShaderModuleIdentifierEXT");
    fprintf(file,
            "\t\tloaded_vkGetShaderModuleIdentifierEXT(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.shaderModule).c_str(),
            pidentifier_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT);
}
void VulkanCppConsumer::Process_vkBindOpticalFlowSessionImageNV(
    const ApiCallInfo&                          call_info,
    args::BindOpticalFlowSessionImageNV&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkBindOpticalFlowSessionImageNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkBindOpticalFlowSessionImageNV(%s, %s, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.session).c_str(),
            util::ToString<VkOpticalFlowSessionBindingPointNV>(args.bindingPoint).c_str(),
            this->GetHandle(args.view).c_str(),
            util::ToString<VkImageLayout>(args.layout).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV);
}

void VulkanCppConsumer::Process_vkCmdOpticalFlowExecuteNV(
    const ApiCallInfo&                          call_info,
    args::CmdOpticalFlowExecuteNV&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pexecute_info;
    std::string pexecute_info_struct = GenerateStruct_VkOpticalFlowExecuteInfoNV(stream_pexecute_info,
                                                                                 args.pExecuteInfo.GetPointer(),
                                                                                 args.pExecuteInfo.GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_pexecute_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdOpticalFlowExecuteNV");
    fprintf(file,
            "\t\tloaded_vkCmdOpticalFlowExecuteNV(%s, %s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.session).c_str(),
            pexecute_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV);
}

void VulkanCppConsumer::Process_vkCreateOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    args::CreateOpticalFlowSessionNV&           args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkOpticalFlowSessionCreateInfoNV(stream_pcreate_info,
                                                                                      args.pCreateInfo.GetPointer(),
                                                                                      args.pCreateInfo.GetMetaStructPointer(),
                                                                                      *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psession_name = "pSession_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_OPTICAL_FLOW_SESSION_NV));
    AddKnownVariables("VkOpticalFlowSessionNV", psession_name, args.pSession.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(psession_name,
                         args.pSession.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateOpticalFlowSessionNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateOpticalFlowSessionNV(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psession_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV);
}

void VulkanCppConsumer::Process_vkDestroyOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    args::DestroyOpticalFlowSessionNV&          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyOpticalFlowSessionNV");
    fprintf(file,
            "\t\tloaded_vkDestroyOpticalFlowSessionNV(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.session).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceOpticalFlowImageFormatsNV& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_poptical_flow_image_format_info;
    std::string poptical_flow_image_format_info_struct = GenerateStruct_VkOpticalFlowImageFormatInfoNV(stream_poptical_flow_image_format_info,
                                                                                                       args.pOpticalFlowImageFormatInfo.GetPointer(),
                                                                                                       args.pOpticalFlowImageFormatInfo.GetMetaStructPointer(),
                                                                                                       *this);
    fprintf(file, "%s", stream_poptical_flow_image_format_info.str().c_str());
    std::string pformat_count_name = "NULL";
    if (!args.pFormatCount.IsNull()) {
        pformat_count_name = "pFormatCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pformat_count_name.c_str(), util::ToString(*args.pFormatCount.GetPointer()).c_str());
        pformat_count_name.insert(0, "&");
    }
    std::string pimage_format_properties_name = "NULL";
    if (!args.pImageFormatProperties.IsNull()) {
        const uint32_t* in_pformat_count = args.pFormatCount.GetPointer();
        pimage_format_properties_name = "pImageFormatProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkOpticalFlowImageFormatPropertiesNV %s[%d] = {};\n", pimage_format_properties_name.c_str(), *in_pformat_count);
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceOpticalFlowImageFormatsNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(%s, &%s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            poptical_flow_image_format_info_struct.c_str(),
            pformat_count_name.c_str(),
            pimage_format_properties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV);
}
void VulkanCppConsumer::Process_vkAntiLagUpdateAMD(
    const ApiCallInfo&                          call_info,
    args::AntiLagUpdateAMD&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdata;
    std::string pdata_struct = GenerateStruct_VkAntiLagDataAMD(stream_pdata,
                                                               args.pData.GetPointer(),
                                                               args.pData.GetMetaStructPointer(),
                                                               *this);
    fprintf(file, "%s", stream_pdata.str().c_str());
    pfn_loader_.AddMethodName("vkAntiLagUpdateAMD");
    fprintf(file,
            "\t\tloaded_vkAntiLagUpdateAMD(%s, &%s);\n",
            this->GetHandle(args.device).c_str(),
            pdata_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkAntiLagUpdateAMD);
}
void VulkanCppConsumer::Process_vkCmdBindShadersEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindShadersEXT&                    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pstages_array = "pstages_array_" + std::to_string(this->GetNextId());
    std::string pstages_values = toStringJoin(args.pStages.GetPointer(),
                                              args.pStages.GetPointer() + args.stageCount,
                                              [&](const VkShaderStageFlagBits current) { return util::ToString(current); },
                                              ", ");
    if (args.stageCount > 0) {
        pstages_array = "pstages_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkShaderStageFlagBits %s[] = { %s };\n", pstages_array.c_str(), pstages_values.c_str());
    }
    std::string pshaders_array = "NULL";
    std::string pshaders_values = toStringJoin(args.pShaders.GetPointer(),
                                               args.pShaders.GetPointer() + args.stageCount,
                                               [&](const format::HandleId current) { return this->GetHandle(current); },
                                               ", ");
    if (args.stageCount == 1 && pshaders_values != "VK_NULL_HANDLE") {
        pshaders_array = "&" + pshaders_values;
    } else if (args.stageCount > 1) {
        pshaders_array = "pshaders_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkShaderEXT %s[] = { %s };\n", pshaders_array.c_str(), pshaders_values.c_str());
    }
    pfn_loader_.AddMethodName("vkCmdBindShadersEXT");
    fprintf(file,
            "\t\tloaded_vkCmdBindShadersEXT(%s, %u, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.stageCount,
            pstages_array.c_str(),
            pshaders_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindShadersEXT);
}

void VulkanCppConsumer::Process_vkCmdSetDepthClampRangeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthClampRangeEXT&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdepth_clamp_range;
    std::string pdepth_clamp_range_struct = GenerateStruct_VkDepthClampRangeEXT(stream_pdepth_clamp_range,
                                                                                args.pDepthClampRange.GetPointer(),
                                                                                args.pDepthClampRange.GetMetaStructPointer(),
                                                                                *this);
    fprintf(file, "%s", stream_pdepth_clamp_range.str().c_str());
    pfn_loader_.AddMethodName("vkCmdSetDepthClampRangeEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetDepthClampRangeEXT(%s, %s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkDepthClampModeEXT>(args.depthClampMode).c_str(),
            pdepth_clamp_range_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthClampRangeEXT);
}

void VulkanCppConsumer::Process_vkCreateShadersEXT(
    const ApiCallInfo&                          call_info,
    args::CreateShadersEXT&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_infos;
    std::string pcreate_infos_array = "NULL";
    PointerPairContainer<decltype(args.pCreateInfos.GetPointer()), decltype(args.pCreateInfos.GetMetaStructPointer())> pcreate_infos_pair{ args.pCreateInfos.GetPointer(), args.pCreateInfos.GetMetaStructPointer(), args.createInfoCount };
    std::string pcreate_infos_names = toStringJoin(pcreate_infos_pair.begin(),
                                                   pcreate_infos_pair.end(),
                                                   [&](auto pair) {{ return GenerateStruct_VkShaderCreateInfoEXT(stream_pcreate_infos, pair.t1, pair.t2, *this); }},
                                                   ", ");
    if (stream_pcreate_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pcreate_infos.str().c_str());
        if (args.createInfoCount == 1) {
            pcreate_infos_array = "&" + pcreate_infos_names;
        } else if (args.createInfoCount > 1) {
            pcreate_infos_array = "pCreateInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkShaderCreateInfoEXT %s[] = { %s };\n", pcreate_infos_array.c_str(), pcreate_infos_names.c_str());
        }
    }
    std::string pshaders_name = "pShaders_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SHADER_EXT));
    AddKnownVariables("VkShaderEXT", pshaders_name, args.pShaders.GetPointer(), args.createInfoCount);
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pshaders_name,
                         args.pShaders.GetPointer(), args.createInfoCount);
    }
    pfn_loader_.AddMethodName("vkCreateShadersEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateShadersEXT(%s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            args.createInfoCount,
            pcreate_infos_array.c_str(),
            "nullptr",
            pshaders_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateShadersEXT);
}

void VulkanCppConsumer::Process_vkDestroyShaderEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyShaderEXT&                     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyShaderEXT");
    fprintf(file,
            "\t\tloaded_vkDestroyShaderEXT(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.shader).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyShaderEXT);
}

void VulkanCppConsumer::Process_vkGetShaderBinaryDataEXT(
    const ApiCallInfo&                          call_info,
    args::GetShaderBinaryDataEXT&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pdata_size_name = "NULL";
    if (!args.pDataSize.IsNull()) {
        pdata_size_name = "pDataSize_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tsize_t %s = %s;\n", pdata_size_name.c_str(), util::ToString(*args.pDataSize.GetPointer()).c_str());
        pdata_size_name.insert(0, "&");
    }
    std::string pdata_name = "NULL";
    if (!args.pData.IsNull()) {
        size_t* in_pdata_size = args.pDataSize.GetPointer();
        pdata_name = "pData_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint8_t %s[%" PRIu64 "] = {};\n", pdata_name.c_str(), util::platform::SizeTtoUint64(*in_pdata_size));
    }
    pfn_loader_.AddMethodName("vkGetShaderBinaryDataEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetShaderBinaryDataEXT(%s, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.shader).c_str(),
            pdata_size_name.c_str(),
            pdata_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetShaderBinaryDataEXT);
}
void VulkanCppConsumer::Process_vkGetDynamicRenderingTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    args::GetDynamicRenderingTilePropertiesQCOM& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_prendering_info;
    std::string prendering_info_struct = GenerateStruct_VkRenderingInfo(stream_prendering_info,
                                                                        args.pRenderingInfo.GetPointer(),
                                                                        args.pRenderingInfo.GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_prendering_info.str().c_str());
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkTilePropertiesQCOM %s = {};\n", pproperties_name.c_str());
        pproperties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetDynamicRenderingTilePropertiesQCOM");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDynamicRenderingTilePropertiesQCOM(%s, &%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            prendering_info_struct.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM);
}

void VulkanCppConsumer::Process_vkGetFramebufferTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    args::GetFramebufferTilePropertiesQCOM&     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pproperties_count_name = "NULL";
    if (!args.pPropertiesCount.IsNull()) {
        pproperties_count_name = "pPropertiesCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pproperties_count_name.c_str(), util::ToString(*args.pPropertiesCount.GetPointer()).c_str());
        pproperties_count_name.insert(0, "&");
    }
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        const uint32_t* in_pproperties_count = args.pPropertiesCount.GetPointer();
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkTilePropertiesQCOM %s[%d] = {};\n", pproperties_name.c_str(), *in_pproperties_count);
    }
    pfn_loader_.AddMethodName("vkGetFramebufferTilePropertiesQCOM");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetFramebufferTilePropertiesQCOM(%s, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.framebuffer).c_str(),
            pproperties_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM);
}
void VulkanCppConsumer::Process_vkCmdConvertCooperativeVectorMatrixNV(
    const ApiCallInfo&                          call_info,
    args::CmdConvertCooperativeVectorMatrixNV&  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfos;
    std::string pinfos_array = "NULL";
    PointerPairContainer<decltype(args.pInfos.GetPointer()), decltype(args.pInfos.GetMetaStructPointer())> pinfos_pair{ args.pInfos.GetPointer(), args.pInfos.GetMetaStructPointer(), args.infoCount };
    std::string pinfos_names = toStringJoin(pinfos_pair.begin(),
                                            pinfos_pair.end(),
                                            [&](auto pair) {{ return GenerateStruct_VkConvertCooperativeVectorMatrixInfoNV(stream_pinfos, pair.t1, pair.t2, *this); }},
                                            ", ");
    if (stream_pinfos.str().length() > 0) {
        fprintf(file, "%s", stream_pinfos.str().c_str());
        if (args.infoCount == 1) {
            pinfos_array = "&" + pinfos_names;
        } else if (args.infoCount > 1) {
            pinfos_array = "pInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkConvertCooperativeVectorMatrixInfoNV %s[] = { %s };\n", pinfos_array.c_str(), pinfos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdConvertCooperativeVectorMatrixNV");
    fprintf(file,
            "\t\tloaded_vkCmdConvertCooperativeVectorMatrixNV(%s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.infoCount,
            pinfos_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdConvertCooperativeVectorMatrixNV);
}

void VulkanCppConsumer::Process_vkConvertCooperativeVectorMatrixNV(
    const ApiCallInfo&                          call_info,
    args::ConvertCooperativeVectorMatrixNV&     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkConvertCooperativeVectorMatrixInfoNV(stream_pinfo,
                                                                                     args.pInfo.GetPointer(),
                                                                                     args.pInfo.GetMetaStructPointer(),
                                                                                     *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkConvertCooperativeVectorMatrixNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkConvertCooperativeVectorMatrixNV(%s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkConvertCooperativeVectorMatrixNV);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceCooperativeVectorPropertiesNV(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceCooperativeVectorPropertiesNV& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pproperty_count_name = "NULL";
    if (!args.pPropertyCount.IsNull()) {
        pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pproperty_count_name.c_str(), util::ToString(*args.pPropertyCount.GetPointer()).c_str());
        pproperty_count_name.insert(0, "&");
    }
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        const uint32_t* in_pproperty_count = args.pPropertyCount.GetPointer();
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkCooperativeVectorPropertiesNV %s[%d] = {};\n", pproperties_name.c_str(), *in_pproperty_count);
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceCooperativeVectorPropertiesNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceCooperativeVectorPropertiesNV(%s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeVectorPropertiesNV);
}
void VulkanCppConsumer::Process_vkGetLatencyTimingsNV(
    const ApiCallInfo&                          call_info,
    args::GetLatencyTimingsNV&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string platency_marker_info_name = "NULL";
    if (!args.pLatencyMarkerInfo.IsNull()) {
        platency_marker_info_name = "pLatencyMarkerInfo_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkGetLatencyMarkerInfoNV %s = {};\n", platency_marker_info_name.c_str());
        platency_marker_info_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetLatencyTimingsNV");
    fprintf(file,
            "\t\tloaded_vkGetLatencyTimingsNV(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.swapchain).c_str(),
            platency_marker_info_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetLatencyTimingsNV);
}

void VulkanCppConsumer::Process_vkLatencySleepNV(
    const ApiCallInfo&                          call_info,
    args::LatencySleepNV&                       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psleep_info;
    std::string psleep_info_struct = GenerateStruct_VkLatencySleepInfoNV(stream_psleep_info,
                                                                         args.pSleepInfo.GetPointer(),
                                                                         args.pSleepInfo.GetMetaStructPointer(),
                                                                         *this);
    fprintf(file, "%s", stream_psleep_info.str().c_str());
    pfn_loader_.AddMethodName("vkLatencySleepNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkLatencySleepNV(%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.swapchain).c_str(),
            psleep_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkLatencySleepNV);
}

void VulkanCppConsumer::Process_vkQueueNotifyOutOfBandNV(
    const ApiCallInfo&                          call_info,
    args::QueueNotifyOutOfBandNV&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pqueue_type_info;
    std::string pqueue_type_info_struct = GenerateStruct_VkOutOfBandQueueTypeInfoNV(stream_pqueue_type_info,
                                                                                    args.pQueueTypeInfo.GetPointer(),
                                                                                    args.pQueueTypeInfo.GetMetaStructPointer(),
                                                                                    *this);
    fprintf(file, "%s", stream_pqueue_type_info.str().c_str());
    pfn_loader_.AddMethodName("vkQueueNotifyOutOfBandNV");
    fprintf(file,
            "\t\tloaded_vkQueueNotifyOutOfBandNV(%s, &%s);\n",
            this->GetHandle(args.queue).c_str(),
            pqueue_type_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkQueueNotifyOutOfBandNV);
}

void VulkanCppConsumer::Process_vkSetLatencyMarkerNV(
    const ApiCallInfo&                          call_info,
    args::SetLatencyMarkerNV&                   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_platency_marker_info;
    std::string platency_marker_info_struct = GenerateStruct_VkSetLatencyMarkerInfoNV(stream_platency_marker_info,
                                                                                      args.pLatencyMarkerInfo.GetPointer(),
                                                                                      args.pLatencyMarkerInfo.GetMetaStructPointer(),
                                                                                      *this);
    fprintf(file, "%s", stream_platency_marker_info.str().c_str());
    pfn_loader_.AddMethodName("vkSetLatencyMarkerNV");
    fprintf(file,
            "\t\tloaded_vkSetLatencyMarkerNV(%s, %s, &%s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.swapchain).c_str(),
            platency_marker_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSetLatencyMarkerNV);
}

void VulkanCppConsumer::Process_vkSetLatencySleepModeNV(
    const ApiCallInfo&                          call_info,
    args::SetLatencySleepModeNV&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_psleep_mode_info;
    std::string psleep_mode_info_struct = GenerateStruct_VkLatencySleepModeInfoNV(stream_psleep_mode_info,
                                                                                  args.pSleepModeInfo.GetPointer(),
                                                                                  args.pSleepModeInfo.GetMetaStructPointer(),
                                                                                  *this);
    fprintf(file, "%s", stream_psleep_mode_info.str().c_str());
    pfn_loader_.AddMethodName("vkSetLatencySleepModeNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkSetLatencySleepModeNV(%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.swapchain).c_str(),
            psleep_mode_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkSetLatencySleepModeNV);
}
void VulkanCppConsumer::Process_vkBindDataGraphPipelineSessionMemoryARM(
    const ApiCallInfo&                          call_info,
    args::BindDataGraphPipelineSessionMemoryARM& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbind_infos;
    std::string pbind_infos_array = "NULL";
    PointerPairContainer<decltype(args.pBindInfos.GetPointer()), decltype(args.pBindInfos.GetMetaStructPointer())> pbind_infos_pair{ args.pBindInfos.GetPointer(), args.pBindInfos.GetMetaStructPointer(), args.bindInfoCount };
    std::string pbind_infos_names = toStringJoin(pbind_infos_pair.begin(),
                                                 pbind_infos_pair.end(),
                                                 [&](auto pair) {{ return GenerateStruct_VkBindDataGraphPipelineSessionMemoryInfoARM(stream_pbind_infos, pair.t1, pair.t2, *this); }},
                                                 ", ");
    if (stream_pbind_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pbind_infos.str().c_str());
        if (args.bindInfoCount == 1) {
            pbind_infos_array = "&" + pbind_infos_names;
        } else if (args.bindInfoCount > 1) {
            pbind_infos_array = "pBindInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBindDataGraphPipelineSessionMemoryInfoARM %s[] = { %s };\n", pbind_infos_array.c_str(), pbind_infos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkBindDataGraphPipelineSessionMemoryARM");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkBindDataGraphPipelineSessionMemoryARM(%s, %u, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            args.bindInfoCount,
            pbind_infos_array.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkBindDataGraphPipelineSessionMemoryARM);
}

void VulkanCppConsumer::Process_vkCmdDispatchDataGraphARM(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchDataGraphARM&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDataGraphPipelineDispatchInfoARM(stream_pinfo,
                                                                                 args.pInfo.GetPointer(),
                                                                                 args.pInfo.GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCmdDispatchDataGraphARM");
    fprintf(file,
            "\t\tloaded_vkCmdDispatchDataGraphARM(%s, %s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.session).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDispatchDataGraphARM);
}

void VulkanCppConsumer::Process_vkCreateDataGraphPipelineSessionARM(
    const ApiCallInfo&                          call_info,
    args::CreateDataGraphPipelineSessionARM&    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkDataGraphPipelineSessionCreateInfoARM(stream_pcreate_info,
                                                                                             args.pCreateInfo.GetPointer(),
                                                                                             args.pCreateInfo.GetMetaStructPointer(),
                                                                                             *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string psession_name = "pSession_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DATA_GRAPH_PIPELINE_SESSION_ARM));
    AddKnownVariables("VkDataGraphPipelineSessionARM", psession_name, args.pSession.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(psession_name,
                         args.pSession.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateDataGraphPipelineSessionARM");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateDataGraphPipelineSessionARM(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            psession_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDataGraphPipelineSessionARM);
}

void VulkanCppConsumer::Process_vkCreateDataGraphPipelinesARM(
    const ApiCallInfo&                          call_info,
    args::CreateDataGraphPipelinesARM&          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_infos;
    std::string pcreate_infos_array = "NULL";
    PointerPairContainer<decltype(args.pCreateInfos.GetPointer()), decltype(args.pCreateInfos.GetMetaStructPointer())> pcreate_infos_pair{ args.pCreateInfos.GetPointer(), args.pCreateInfos.GetMetaStructPointer(), args.createInfoCount };
    std::string pcreate_infos_names = toStringJoin(pcreate_infos_pair.begin(),
                                                   pcreate_infos_pair.end(),
                                                   [&](auto pair) {{ return GenerateStruct_VkDataGraphPipelineCreateInfoARM(stream_pcreate_infos, pair.t1, pair.t2, *this); }},
                                                   ", ");
    if (stream_pcreate_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pcreate_infos.str().c_str());
        if (args.createInfoCount == 1) {
            pcreate_infos_array = "&" + pcreate_infos_names;
        } else if (args.createInfoCount > 1) {
            pcreate_infos_array = "pCreateInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkDataGraphPipelineCreateInfoARM %s[] = { %s };\n", pcreate_infos_array.c_str(), pcreate_infos_names.c_str());
        }
    }
    std::string ppipelines_name = "pPipelines_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_PIPELINE));
    AddKnownVariables("VkPipeline", ppipelines_name, args.pPipelines.GetPointer(), args.createInfoCount);
    if (args.result == VK_SUCCESS) {
        this->AddHandles(ppipelines_name,
                         args.pPipelines.GetPointer(), args.createInfoCount);
    }
    pfn_loader_.AddMethodName("vkCreateDataGraphPipelinesARM");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateDataGraphPipelinesARM(%s, %s, %s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.deferredOperation).c_str(),
            this->GetHandle(args.pipelineCache).c_str(),
            args.createInfoCount,
            pcreate_infos_array.c_str(),
            "nullptr",
            ppipelines_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDataGraphPipelinesARM);
}

void VulkanCppConsumer::Process_vkDestroyDataGraphPipelineSessionARM(
    const ApiCallInfo&                          call_info,
    args::DestroyDataGraphPipelineSessionARM&   args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyDataGraphPipelineSessionARM");
    fprintf(file,
            "\t\tloaded_vkDestroyDataGraphPipelineSessionARM(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.session).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDataGraphPipelineSessionARM);
}

void VulkanCppConsumer::Process_vkGetDataGraphPipelineAvailablePropertiesARM(
    const ApiCallInfo&                          call_info,
    args::GetDataGraphPipelineAvailablePropertiesARM& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_ppipeline_info;
    std::string ppipeline_info_struct = GenerateStruct_VkDataGraphPipelineInfoARM(stream_ppipeline_info,
                                                                                  args.pPipelineInfo.GetPointer(),
                                                                                  args.pPipelineInfo.GetMetaStructPointer(),
                                                                                  *this);
    fprintf(file, "%s", stream_ppipeline_info.str().c_str());
    std::string pproperties_count_name = "NULL";
    if (!args.pPropertiesCount.IsNull()) {
        pproperties_count_name = "pPropertiesCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pproperties_count_name.c_str(), util::ToString(*args.pPropertiesCount.GetPointer()).c_str());
        pproperties_count_name.insert(0, "&");
    }
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        const uint32_t* in_pproperties_count = args.pPropertiesCount.GetPointer();
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDataGraphPipelinePropertyARM %s[%d] = {};\n", pproperties_name.c_str(), *in_pproperties_count);
    }
    pfn_loader_.AddMethodName("vkGetDataGraphPipelineAvailablePropertiesARM");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDataGraphPipelineAvailablePropertiesARM(%s, &%s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            ppipeline_info_struct.c_str(),
            pproperties_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDataGraphPipelineAvailablePropertiesARM);
}

void VulkanCppConsumer::Process_vkGetDataGraphPipelinePropertiesARM(
    const ApiCallInfo&                          call_info,
    args::GetDataGraphPipelinePropertiesARM&    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_ppipeline_info;
    std::string ppipeline_info_struct = GenerateStruct_VkDataGraphPipelineInfoARM(stream_ppipeline_info,
                                                                                  args.pPipelineInfo.GetPointer(),
                                                                                  args.pPipelineInfo.GetMetaStructPointer(),
                                                                                  *this);
    fprintf(file, "%s", stream_ppipeline_info.str().c_str());
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDataGraphPipelinePropertyQueryResultARM %s[%d] = {};\n", pproperties_name.c_str(), args.propertiesCount);
    }
    pfn_loader_.AddMethodName("vkGetDataGraphPipelinePropertiesARM");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDataGraphPipelinePropertiesARM(%s, &%s, %u, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            ppipeline_info_struct.c_str(),
            args.propertiesCount,
            pproperties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDataGraphPipelinePropertiesARM);
}

void VulkanCppConsumer::Process_vkGetDataGraphPipelineSessionBindPointRequirementsARM(
    const ApiCallInfo&                          call_info,
    args::GetDataGraphPipelineSessionBindPointRequirementsARM& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDataGraphPipelineSessionBindPointRequirementsInfoARM(stream_pinfo,
                                                                                                     args.pInfo.GetPointer(),
                                                                                                     args.pInfo.GetMetaStructPointer(),
                                                                                                     *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string pbind_point_requirement_count_name = "NULL";
    if (!args.pBindPointRequirementCount.IsNull()) {
        pbind_point_requirement_count_name = "pBindPointRequirementCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pbind_point_requirement_count_name.c_str(), util::ToString(*args.pBindPointRequirementCount.GetPointer()).c_str());
        pbind_point_requirement_count_name.insert(0, "&");
    }
    std::string pbind_point_requirements_name = "NULL";
    if (!args.pBindPointRequirements.IsNull()) {
        const uint32_t* in_pbind_point_requirement_count = args.pBindPointRequirementCount.GetPointer();
        pbind_point_requirements_name = "pBindPointRequirements_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDataGraphPipelineSessionBindPointRequirementARM %s[%d] = {};\n", pbind_point_requirements_name.c_str(), *in_pbind_point_requirement_count);
    }
    pfn_loader_.AddMethodName("vkGetDataGraphPipelineSessionBindPointRequirementsARM");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetDataGraphPipelineSessionBindPointRequirementsARM(%s, &%s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str(),
            pbind_point_requirement_count_name.c_str(),
            pbind_point_requirements_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDataGraphPipelineSessionBindPointRequirementsARM);
}

void VulkanCppConsumer::Process_vkGetDataGraphPipelineSessionMemoryRequirementsARM(
    const ApiCallInfo&                          call_info,
    args::GetDataGraphPipelineSessionMemoryRequirementsARM& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkDataGraphPipelineSessionMemoryRequirementsInfoARM(stream_pinfo,
                                                                                                  args.pInfo.GetPointer(),
                                                                                                  args.pInfo.GetMetaStructPointer(),
                                                                                                  *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string pmemory_requirements_name = "NULL";
    if (!args.pMemoryRequirements.IsNull()) {
        pmemory_requirements_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkMemoryRequirements2 %s = {};\n", pmemory_requirements_name.c_str());
        pmemory_requirements_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetDataGraphPipelineSessionMemoryRequirementsARM");
    fprintf(file,
            "\t\tloaded_vkGetDataGraphPipelineSessionMemoryRequirementsARM(%s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str(),
            pmemory_requirements_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDataGraphPipelineSessionMemoryRequirementsARM);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pqueue_family_data_graph_processing_engine_info;
    std::string pqueue_family_data_graph_processing_engine_info_struct = GenerateStruct_VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM(stream_pqueue_family_data_graph_processing_engine_info,
                                                                                                                                                    args.pQueueFamilyDataGraphProcessingEngineInfo.GetPointer(),
                                                                                                                                                    args.pQueueFamilyDataGraphProcessingEngineInfo.GetMetaStructPointer(),
                                                                                                                                                    *this);
    fprintf(file, "%s", stream_pqueue_family_data_graph_processing_engine_info.str().c_str());
    std::string pqueue_family_data_graph_processing_engine_properties_name = "NULL";
    if (!args.pQueueFamilyDataGraphProcessingEngineProperties.IsNull()) {
        pqueue_family_data_graph_processing_engine_properties_name = "pQueueFamilyDataGraphProcessingEngineProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkQueueFamilyDataGraphProcessingEnginePropertiesARM %s = {};\n", pqueue_family_data_graph_processing_engine_properties_name.c_str());
        pqueue_family_data_graph_processing_engine_properties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM");
    fprintf(file,
            "\t\tloaded_vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(%s, &%s, %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pqueue_family_data_graph_processing_engine_info_struct.c_str(),
            pqueue_family_data_graph_processing_engine_properties_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pqueue_family_data_graph_property_count_name = "NULL";
    if (!args.pQueueFamilyDataGraphPropertyCount.IsNull()) {
        pqueue_family_data_graph_property_count_name = "pQueueFamilyDataGraphPropertyCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pqueue_family_data_graph_property_count_name.c_str(), util::ToString(*args.pQueueFamilyDataGraphPropertyCount.GetPointer()).c_str());
        pqueue_family_data_graph_property_count_name.insert(0, "&");
    }
    std::string pqueue_family_data_graph_properties_name = "NULL";
    if (!args.pQueueFamilyDataGraphProperties.IsNull()) {
        const uint32_t* in_pqueue_family_data_graph_property_count = args.pQueueFamilyDataGraphPropertyCount.GetPointer();
        pqueue_family_data_graph_properties_name = "pQueueFamilyDataGraphProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkQueueFamilyDataGraphPropertiesARM %s[%d] = {};\n", pqueue_family_data_graph_properties_name.c_str(), *in_pqueue_family_data_graph_property_count);
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(%s, %u, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            args.queueFamilyIndex,
            pqueue_family_data_graph_property_count_name.c_str(),
            pqueue_family_data_graph_properties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM);
}
void VulkanCppConsumer::Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetAttachmentFeedbackLoopEnableEXT& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetAttachmentFeedbackLoopEnableEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetAttachmentFeedbackLoopEnableEXT(%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkImageAspectFlags>(args.aspectMask).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetAttachmentFeedbackLoopEnableEXT);
}
void VulkanCppConsumer::Process_vkCmdBindTileMemoryQCOM(
    const ApiCallInfo&                          call_info,
    args::CmdBindTileMemoryQCOM&                args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_ptile_memory_bind_info;
    std::string ptile_memory_bind_info_struct = GenerateStruct_VkTileMemoryBindInfoQCOM(stream_ptile_memory_bind_info,
                                                                                        args.pTileMemoryBindInfo.GetPointer(),
                                                                                        args.pTileMemoryBindInfo.GetMetaStructPointer(),
                                                                                        *this);
    fprintf(file, "%s", stream_ptile_memory_bind_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdBindTileMemoryQCOM");
    fprintf(file,
            "\t\tloaded_vkCmdBindTileMemoryQCOM(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            ptile_memory_bind_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindTileMemoryQCOM);
}
void VulkanCppConsumer::Process_vkCmdDecompressMemoryEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDecompressMemoryEXT&               args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pdecompress_memory_info_e_x_t;
    std::string pdecompress_memory_info_e_x_t_struct = GenerateStruct_VkDecompressMemoryInfoEXT(stream_pdecompress_memory_info_e_x_t,
                                                                                                args.pDecompressMemoryInfoEXT.GetPointer(),
                                                                                                args.pDecompressMemoryInfoEXT.GetMetaStructPointer(),
                                                                                                *this);
    fprintf(file, "%s", stream_pdecompress_memory_info_e_x_t.str().c_str());
    pfn_loader_.AddMethodName("vkCmdDecompressMemoryEXT");
    fprintf(file,
            "\t\tloaded_vkCmdDecompressMemoryEXT(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pdecompress_memory_info_e_x_t_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDecompressMemoryEXT);
}

void VulkanCppConsumer::Process_vkCmdDecompressMemoryIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDecompressMemoryIndirectCountEXT&  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDecompressMemoryIndirectCountEXT");
    fprintf(file,
            "\t\tloaded_vkCmdDecompressMemoryIndirectCountEXT(%s, %s, %" PRIu64 "UL, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            util::ToString<VkMemoryDecompressionMethodFlagsEXT>(args.decompressionMethod).c_str(),
            args.indirectCommandsAddress,
            args.indirectCommandsCountAddress,
            args.maxDecompressionCount,
            args.stride);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDecompressMemoryIndirectCountEXT);
}
void VulkanCppConsumer::Process_vkCmdBuildPartitionedAccelerationStructuresNV(
    const ApiCallInfo&                          call_info,
    args::CmdBuildPartitionedAccelerationStructuresNV& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbuild_info;
    std::string pbuild_info_struct = GenerateStruct_VkBuildPartitionedAccelerationStructureInfoNV(stream_pbuild_info,
                                                                                                  args.pBuildInfo.GetPointer(),
                                                                                                  args.pBuildInfo.GetMetaStructPointer(),
                                                                                                  *this);
    fprintf(file, "%s", stream_pbuild_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdBuildPartitionedAccelerationStructuresNV");
    fprintf(file,
            "\t\tloaded_vkCmdBuildPartitionedAccelerationStructuresNV(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pbuild_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBuildPartitionedAccelerationStructuresNV);
}

void VulkanCppConsumer::Process_vkGetPartitionedAccelerationStructuresBuildSizesNV(
    const ApiCallInfo&                          call_info,
    args::GetPartitionedAccelerationStructuresBuildSizesNV& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkPartitionedAccelerationStructureInstancesInputNV(stream_pinfo,
                                                                                                 args.pInfo.GetPointer(),
                                                                                                 args.pInfo.GetMetaStructPointer(),
                                                                                                 *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string psize_info_name = "NULL";
    if (!args.pSizeInfo.IsNull()) {
        psize_info_name = "pSizeInfo_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkAccelerationStructureBuildSizesInfoKHR %s = {};\n", psize_info_name.c_str());
        psize_info_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPartitionedAccelerationStructuresBuildSizesNV");
    fprintf(file,
            "\t\tloaded_vkGetPartitionedAccelerationStructuresBuildSizesNV(%s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str(),
            psize_info_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPartitionedAccelerationStructuresBuildSizesNV);
}
void VulkanCppConsumer::Process_vkCmdExecuteGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdExecuteGeneratedCommandsEXT&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pgenerated_commands_info;
    std::string pgenerated_commands_info_struct = GenerateStruct_VkGeneratedCommandsInfoEXT(stream_pgenerated_commands_info,
                                                                                            args.pGeneratedCommandsInfo.GetPointer(),
                                                                                            args.pGeneratedCommandsInfo.GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pgenerated_commands_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdExecuteGeneratedCommandsEXT");
    fprintf(file,
            "\t\tloaded_vkCmdExecuteGeneratedCommandsEXT(%s, %u, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.isPreprocessed,
            pgenerated_commands_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsEXT);
}

void VulkanCppConsumer::Process_vkCmdPreprocessGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdPreprocessGeneratedCommandsEXT&    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pgenerated_commands_info;
    std::string pgenerated_commands_info_struct = GenerateStruct_VkGeneratedCommandsInfoEXT(stream_pgenerated_commands_info,
                                                                                            args.pGeneratedCommandsInfo.GetPointer(),
                                                                                            args.pGeneratedCommandsInfo.GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pgenerated_commands_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdPreprocessGeneratedCommandsEXT");
    fprintf(file,
            "\t\tloaded_vkCmdPreprocessGeneratedCommandsEXT(%s, &%s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pgenerated_commands_info_struct.c_str(),
            this->GetHandle(args.stateCommandBuffer).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsEXT);
}

void VulkanCppConsumer::Process_vkCreateIndirectCommandsLayoutEXT(
    const ApiCallInfo&                          call_info,
    args::CreateIndirectCommandsLayoutEXT&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkIndirectCommandsLayoutCreateInfoEXT(stream_pcreate_info,
                                                                                           args.pCreateInfo.GetPointer(),
                                                                                           args.pCreateInfo.GetMetaStructPointer(),
                                                                                           *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pindirect_commands_layout_name = "pIndirectCommandsLayout_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_EXT));
    AddKnownVariables("VkIndirectCommandsLayoutEXT", pindirect_commands_layout_name, args.pIndirectCommandsLayout.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pindirect_commands_layout_name,
                         args.pIndirectCommandsLayout.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateIndirectCommandsLayoutEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateIndirectCommandsLayoutEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pindirect_commands_layout_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutEXT);
}

void VulkanCppConsumer::Process_vkCreateIndirectExecutionSetEXT(
    const ApiCallInfo&                          call_info,
    args::CreateIndirectExecutionSetEXT&        args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkIndirectExecutionSetCreateInfoEXT(stream_pcreate_info,
                                                                                         args.pCreateInfo.GetPointer(),
                                                                                         args.pCreateInfo.GetMetaStructPointer(),
                                                                                         *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pindirect_execution_set_name = "pIndirectExecutionSet_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_INDIRECT_EXECUTION_SET_EXT));
    AddKnownVariables("VkIndirectExecutionSetEXT", pindirect_execution_set_name, args.pIndirectExecutionSet.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pindirect_execution_set_name,
                         args.pIndirectExecutionSet.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateIndirectExecutionSetEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateIndirectExecutionSetEXT(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pindirect_execution_set_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateIndirectExecutionSetEXT);
}

void VulkanCppConsumer::Process_vkDestroyIndirectCommandsLayoutEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyIndirectCommandsLayoutEXT&     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyIndirectCommandsLayoutEXT");
    fprintf(file,
            "\t\tloaded_vkDestroyIndirectCommandsLayoutEXT(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.indirectCommandsLayout).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutEXT);
}

void VulkanCppConsumer::Process_vkDestroyIndirectExecutionSetEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyIndirectExecutionSetEXT&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyIndirectExecutionSetEXT");
    fprintf(file,
            "\t\tloaded_vkDestroyIndirectExecutionSetEXT(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.indirectExecutionSet).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyIndirectExecutionSetEXT);
}

void VulkanCppConsumer::Process_vkGetGeneratedCommandsMemoryRequirementsEXT(
    const ApiCallInfo&                          call_info,
    args::GetGeneratedCommandsMemoryRequirementsEXT& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkGeneratedCommandsMemoryRequirementsInfoEXT(stream_pinfo,
                                                                                           args.pInfo.GetPointer(),
                                                                                           args.pInfo.GetMetaStructPointer(),
                                                                                           *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    std::string pmemory_requirements_name = "NULL";
    if (!args.pMemoryRequirements.IsNull()) {
        pmemory_requirements_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkMemoryRequirements2 %s = {};\n", pmemory_requirements_name.c_str());
        pmemory_requirements_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetGeneratedCommandsMemoryRequirementsEXT");
    fprintf(file,
            "\t\tloaded_vkGetGeneratedCommandsMemoryRequirementsEXT(%s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str(),
            pmemory_requirements_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsEXT);
}

void VulkanCppConsumer::Process_vkUpdateIndirectExecutionSetPipelineEXT(
    const ApiCallInfo&                          call_info,
    args::UpdateIndirectExecutionSetPipelineEXT& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pexecution_set_writes;
    std::string pexecution_set_writes_array = "NULL";
    PointerPairContainer<decltype(args.pExecutionSetWrites.GetPointer()), decltype(args.pExecutionSetWrites.GetMetaStructPointer())> pexecution_set_writes_pair{ args.pExecutionSetWrites.GetPointer(), args.pExecutionSetWrites.GetMetaStructPointer(), args.executionSetWriteCount };
    std::string pexecution_set_writes_names = toStringJoin(pexecution_set_writes_pair.begin(),
                                                           pexecution_set_writes_pair.end(),
                                                           [&](auto pair) {{ return GenerateStruct_VkWriteIndirectExecutionSetPipelineEXT(stream_pexecution_set_writes, pair.t1, pair.t2, *this); }},
                                                           ", ");
    if (stream_pexecution_set_writes.str().length() > 0) {
        fprintf(file, "%s", stream_pexecution_set_writes.str().c_str());
        if (args.executionSetWriteCount == 1) {
            pexecution_set_writes_array = "&" + pexecution_set_writes_names;
        } else if (args.executionSetWriteCount > 1) {
            pexecution_set_writes_array = "pExecutionSetWrites_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkWriteIndirectExecutionSetPipelineEXT %s[] = { %s };\n", pexecution_set_writes_array.c_str(), pexecution_set_writes_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkUpdateIndirectExecutionSetPipelineEXT");
    fprintf(file,
            "\t\tloaded_vkUpdateIndirectExecutionSetPipelineEXT(%s, %s, %u, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.indirectExecutionSet).c_str(),
            args.executionSetWriteCount,
            pexecution_set_writes_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkUpdateIndirectExecutionSetPipelineEXT);
}

void VulkanCppConsumer::Process_vkUpdateIndirectExecutionSetShaderEXT(
    const ApiCallInfo&                          call_info,
    args::UpdateIndirectExecutionSetShaderEXT&  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pexecution_set_writes;
    std::string pexecution_set_writes_array = "NULL";
    PointerPairContainer<decltype(args.pExecutionSetWrites.GetPointer()), decltype(args.pExecutionSetWrites.GetMetaStructPointer())> pexecution_set_writes_pair{ args.pExecutionSetWrites.GetPointer(), args.pExecutionSetWrites.GetMetaStructPointer(), args.executionSetWriteCount };
    std::string pexecution_set_writes_names = toStringJoin(pexecution_set_writes_pair.begin(),
                                                           pexecution_set_writes_pair.end(),
                                                           [&](auto pair) {{ return GenerateStruct_VkWriteIndirectExecutionSetShaderEXT(stream_pexecution_set_writes, pair.t1, pair.t2, *this); }},
                                                           ", ");
    if (stream_pexecution_set_writes.str().length() > 0) {
        fprintf(file, "%s", stream_pexecution_set_writes.str().c_str());
        if (args.executionSetWriteCount == 1) {
            pexecution_set_writes_array = "&" + pexecution_set_writes_names;
        } else if (args.executionSetWriteCount > 1) {
            pexecution_set_writes_array = "pExecutionSetWrites_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkWriteIndirectExecutionSetShaderEXT %s[] = { %s };\n", pexecution_set_writes_array.c_str(), pexecution_set_writes_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkUpdateIndirectExecutionSetShaderEXT");
    fprintf(file,
            "\t\tloaded_vkUpdateIndirectExecutionSetShaderEXT(%s, %s, %u, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.indirectExecutionSet).c_str(),
            args.executionSetWriteCount,
            pexecution_set_writes_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkUpdateIndirectExecutionSetShaderEXT);
}
void VulkanCppConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pproperty_count_name = "NULL";
    if (!args.pPropertyCount.IsNull()) {
        pproperty_count_name = "pPropertyCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pproperty_count_name.c_str(), util::ToString(*args.pPropertyCount.GetPointer()).c_str());
        pproperty_count_name.insert(0, "&");
    }
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        const uint32_t* in_pproperty_count = args.pPropertyCount.GetPointer();
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkCooperativeMatrixFlexibleDimensionsPropertiesNV %s[%d] = {};\n", pproperties_name.c_str(), *in_pproperty_count);
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(%s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pproperty_count_name.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV);
}
void VulkanCppConsumer::Process_vkGetMemoryMetalHandleEXT(
    const ApiCallInfo&                          call_info,
    args::GetMemoryMetalHandleEXT&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pget_metal_handle_info;
    std::string pget_metal_handle_info_struct = GenerateStruct_VkMemoryGetMetalHandleInfoEXT(stream_pget_metal_handle_info,
                                                                                             args.pGetMetalHandleInfo.GetPointer(),
                                                                                             args.pGetMetalHandleInfo.GetMetaStructPointer(),
                                                                                             *this);
    fprintf(file, "%s", stream_pget_metal_handle_info.str().c_str());
    std::string phandle_name = "NULL";
    if (!args.pHandle.IsNull()) {
        phandle_name = "pHandle_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint8_t* %s = %s;\n", phandle_name.c_str(), util::ToString(*args.pHandle.GetPointer()).c_str());
        phandle_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetMemoryMetalHandleEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetMemoryMetalHandleEXT(%s, &%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pget_metal_handle_info_struct.c_str(),
            phandle_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryMetalHandleEXT);
}

void VulkanCppConsumer::Process_vkGetMemoryMetalHandlePropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::GetMemoryMetalHandlePropertiesEXT&    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string phandle_name = "args.pHandle_" + std::to_string(this->GetNextId());
    fprintf(file, "\t\tvoid* %s;\n", phandle_name.c_str());
    std::string pmemory_metal_handle_properties_name = "NULL";
    if (!args.pMemoryMetalHandleProperties.IsNull()) {
        pmemory_metal_handle_properties_name = "pMemoryMetalHandleProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkMemoryMetalHandlePropertiesEXT %s = {};\n", pmemory_metal_handle_properties_name.c_str());
        pmemory_metal_handle_properties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetMemoryMetalHandlePropertiesEXT");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetMemoryMetalHandlePropertiesEXT(%s, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            util::ToString<VkExternalMemoryHandleTypeFlagBits>(args.handleType).c_str(),
            phandle_name.c_str(),
            pmemory_metal_handle_properties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryMetalHandlePropertiesEXT);
}
void VulkanCppConsumer::Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM(
    const ApiCallInfo&                          call_info,
    args::EnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pcounter_count_name = "NULL";
    if (!args.pCounterCount.IsNull()) {
        pcounter_count_name = "pCounterCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pcounter_count_name.c_str(), util::ToString(*args.pCounterCount.GetPointer()).c_str());
        pcounter_count_name.insert(0, "&");
    }
    std::string pcounters_name = "NULL";
    if (!args.pCounters.IsNull()) {
        const uint32_t* in_pcounter_count = args.pCounterCount.GetPointer();
        pcounters_name = "pCounters_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPerformanceCounterARM %s[%d] = {};\n", pcounters_name.c_str(), *in_pcounter_count);
    }
    std::string pcounter_descriptions_name = "NULL";
    if (!args.pCounterDescriptions.IsNull()) {
        const uint32_t* in_pcounter_count = args.pCounterCount.GetPointer();
        pcounter_descriptions_name = "pCounterDescriptions_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkPerformanceCounterDescriptionARM %s[%d] = {};\n", pcounter_descriptions_name.c_str(), *in_pcounter_count);
    }
    pfn_loader_.AddMethodName("vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM(%s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            args.queueFamilyIndex,
            pcounter_count_name.c_str(),
            pcounters_name.c_str(),
            pcounter_descriptions_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM);
}
void VulkanCppConsumer::Process_vkCmdEndRendering2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndRendering2EXT&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_prendering_end_info;
    std::string prendering_end_info_struct = GenerateStruct_VkRenderingEndInfoKHR(stream_prendering_end_info,
                                                                                  args.pRenderingEndInfo.GetPointer(),
                                                                                  args.pRenderingEndInfo.GetMetaStructPointer(),
                                                                                  *this);
    fprintf(file, "%s", stream_prendering_end_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdEndRendering2EXT");
    fprintf(file,
            "\t\tloaded_vkCmdEndRendering2EXT(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            prendering_end_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRendering2EXT);
}
void VulkanCppConsumer::Process_vkCmdBeginCustomResolveEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginCustomResolveEXT&             args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbegin_custom_resolve_info;
    std::string pbegin_custom_resolve_info_struct = GenerateStruct_VkBeginCustomResolveInfoEXT(stream_pbegin_custom_resolve_info,
                                                                                               args.pBeginCustomResolveInfo.GetPointer(),
                                                                                               args.pBeginCustomResolveInfo.GetMetaStructPointer(),
                                                                                               *this);
    fprintf(file, "%s", stream_pbegin_custom_resolve_info.str().c_str());
    pfn_loader_.AddMethodName("vkCmdBeginCustomResolveEXT");
    fprintf(file,
            "\t\tloaded_vkCmdBeginCustomResolveEXT(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pbegin_custom_resolve_info_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginCustomResolveEXT);
}
void VulkanCppConsumer::Process_vkGetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pqueue_family_data_graph_properties;
    std::string pqueue_family_data_graph_properties_struct = GenerateStruct_VkQueueFamilyDataGraphPropertiesARM(stream_pqueue_family_data_graph_properties,
                                                                                                                args.pQueueFamilyDataGraphProperties.GetPointer(),
                                                                                                                args.pQueueFamilyDataGraphProperties.GetMetaStructPointer(),
                                                                                                                *this);
    fprintf(file, "%s", stream_pqueue_family_data_graph_properties.str().c_str());
    std::string pproperties_name = "NULL";
    if (!args.pProperties.IsNull()) {
        pproperties_name = "pProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkBaseOutStructure %s = {};\n", pproperties_name.c_str());
        pproperties_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM(%s, %u, &%s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            args.queueFamilyIndex,
            pqueue_family_data_graph_properties_struct.c_str(),
            pproperties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM);
}

void VulkanCppConsumer::Process_vkGetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pqueue_family_data_graph_properties;
    std::string pqueue_family_data_graph_properties_struct = GenerateStruct_VkQueueFamilyDataGraphPropertiesARM(stream_pqueue_family_data_graph_properties,
                                                                                                                args.pQueueFamilyDataGraphProperties.GetPointer(),
                                                                                                                args.pQueueFamilyDataGraphProperties.GetMetaStructPointer(),
                                                                                                                *this);
    fprintf(file, "%s", stream_pqueue_family_data_graph_properties.str().c_str());
    std::stringstream stream_poptical_flow_image_format_info;
    std::string poptical_flow_image_format_info_struct = GenerateStruct_VkDataGraphOpticalFlowImageFormatInfoARM(stream_poptical_flow_image_format_info,
                                                                                                                 args.pOpticalFlowImageFormatInfo.GetPointer(),
                                                                                                                 args.pOpticalFlowImageFormatInfo.GetMetaStructPointer(),
                                                                                                                 *this);
    fprintf(file, "%s", stream_poptical_flow_image_format_info.str().c_str());
    std::string pformat_count_name = "NULL";
    if (!args.pFormatCount.IsNull()) {
        pformat_count_name = "pFormatCount_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint32_t %s = %s;\n", pformat_count_name.c_str(), util::ToString(*args.pFormatCount.GetPointer()).c_str());
        pformat_count_name.insert(0, "&");
    }
    std::string pimage_format_properties_name = "NULL";
    if (!args.pImageFormatProperties.IsNull()) {
        const uint32_t* in_pformat_count = args.pFormatCount.GetPointer();
        pimage_format_properties_name = "pImageFormatProperties_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkDataGraphOpticalFlowImageFormatPropertiesARM %s[%d] = {};\n", pimage_format_properties_name.c_str(), *in_pformat_count);
    }
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM(%s, %u, &%s, &%s, %s, %s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            args.queueFamilyIndex,
            pqueue_family_data_graph_properties_struct.c_str(),
            poptical_flow_image_format_info_struct.c_str(),
            pformat_count_name.c_str(),
            pimage_format_properties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM);
}
void VulkanCppConsumer::Process_vkCmdSetComputeOccupancyPriorityNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetComputeOccupancyPriorityNV&     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pparameters;
    std::string pparameters_struct = GenerateStruct_VkComputeOccupancyPriorityParametersNV(stream_pparameters,
                                                                                           args.pParameters.GetPointer(),
                                                                                           args.pParameters.GetMetaStructPointer(),
                                                                                           *this);
    fprintf(file, "%s", stream_pparameters.str().c_str());
    pfn_loader_.AddMethodName("vkCmdSetComputeOccupancyPriorityNV");
    fprintf(file,
            "\t\tloaded_vkCmdSetComputeOccupancyPriorityNV(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pparameters_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetComputeOccupancyPriorityNV);
}
void VulkanCppConsumer::Process_vkCmdSetPrimitiveRestartIndexEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveRestartIndexEXT&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetPrimitiveRestartIndexEXT");
    fprintf(file,
            "\t\tloaded_vkCmdSetPrimitiveRestartIndexEXT(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.primitiveRestartIndex);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartIndexEXT);
}
void VulkanCppConsumer::Process_vkCmdBuildAccelerationStructuresIndirectKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBuildAccelerationStructuresIndirectKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfos;
    std::string pinfos_array = "NULL";
    PointerPairContainer<decltype(args.pInfos.GetPointer()), decltype(args.pInfos.GetMetaStructPointer())> pinfos_pair{ args.pInfos.GetPointer(), args.pInfos.GetMetaStructPointer(), args.infoCount };
    std::string pinfos_names = toStringJoin(pinfos_pair.begin(),
                                            pinfos_pair.end(),
                                            [&](auto pair) {{ return GenerateStruct_VkAccelerationStructureBuildGeometryInfoKHR(stream_pinfos, pair.t1, pair.t2, *this); }},
                                            ", ");
    if (stream_pinfos.str().length() > 0) {
        fprintf(file, "%s", stream_pinfos.str().c_str());
        if (args.infoCount == 1) {
            pinfos_array = "&" + pinfos_names;
        } else if (args.infoCount > 1) {
            pinfos_array = "pInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkAccelerationStructureBuildGeometryInfoKHR %s[] = { %s };\n", pinfos_array.c_str(), pinfos_names.c_str());
        }
    }
    std::string pindirect_device_addresses_array = "pIndirectDeviceAddresses_" + std::to_string(this->GetNextId());
    if (args.infoCount > 0) {
        std::string pindirect_device_addresses_values = toStringJoin(args.pIndirectDeviceAddresses.GetPointer(),
                                                                     args.pIndirectDeviceAddresses.GetPointer() + args.infoCount,
                                                                     [&](const auto current) { return std::to_string(current) + "UL"; },
                                                                     ", ");
        fprintf(file, "\t\tVkDeviceAddress %s[] = { %s };\n", pindirect_device_addresses_array.c_str(), pindirect_device_addresses_values.c_str());
    } else {
        pindirect_device_addresses_array = "NULL";
    }
    std::string pindirect_strides_array = "pIndirectStrides_" + std::to_string(this->GetNextId());
    if (args.infoCount > 0) {
        std::string pindirect_strides_values = toStringJoin(args.pIndirectStrides.GetPointer(),
                                                            args.pIndirectStrides.GetPointer() + args.infoCount,
                                                            [&](const auto current) { return std::to_string(current) + ""; },
                                                            ", ");
        fprintf(file, "\t\tuint32_t %s[] = { %s };\n", pindirect_strides_array.c_str(), pindirect_strides_values.c_str());
    } else {
        pindirect_strides_array = "NULL";
    }
    std::string pp_max_primitive_counts_array = "ppMaxPrimitiveCounts_" + std::to_string(this->GetNextId());
    if (args.infoCount > 0) {
        std::string pp_max_primitive_counts_values = toStringJoin(args.ppMaxPrimitiveCounts.GetPointer(),
                                                                  args.ppMaxPrimitiveCounts.GetPointer() + args.infoCount,
                                                                  [&](const auto current) { return std::to_string(reinterpret_cast<const VkDeviceSize>(current)) + ""; },
                                                                  ", ");
        fprintf(file, "\t\tuint32_t %s[] = { %s };\n", pp_max_primitive_counts_array.c_str(), pp_max_primitive_counts_values.c_str());
    } else {
        pp_max_primitive_counts_array = "NULL";
    }
    pfn_loader_.AddMethodName("vkCmdBuildAccelerationStructuresIndirectKHR");
    fprintf(file,
            "\t\tloaded_vkCmdBuildAccelerationStructuresIndirectKHR(%s, %u, %s, %s, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.infoCount,
            pinfos_array.c_str(),
            pindirect_device_addresses_array.c_str(),
            pindirect_strides_array.c_str(),
            pp_max_primitive_counts_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR);
}

void VulkanCppConsumer::Process_vkCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBuildAccelerationStructuresKHR&    args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfos;
    std::string pinfos_array = "NULL";
    PointerPairContainer<decltype(args.pInfos.GetPointer()), decltype(args.pInfos.GetMetaStructPointer())> pinfos_pair{ args.pInfos.GetPointer(), args.pInfos.GetMetaStructPointer(), args.infoCount };
    std::string pinfos_names = toStringJoin(pinfos_pair.begin(),
                                            pinfos_pair.end(),
                                            [&](auto pair) {{ return GenerateStruct_VkAccelerationStructureBuildGeometryInfoKHR(stream_pinfos, pair.t1, pair.t2, *this); }},
                                            ", ");
    if (stream_pinfos.str().length() > 0) {
        fprintf(file, "%s", stream_pinfos.str().c_str());
        if (args.infoCount == 1) {
            pinfos_array = "&" + pinfos_names;
        } else if (args.infoCount > 1) {
            pinfos_array = "pInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkAccelerationStructureBuildGeometryInfoKHR %s[] = { %s };\n", pinfos_array.c_str(), pinfos_names.c_str());
        }
    }
    std::stringstream stream_pp_build_range_infos;
    std::string pp_build_range_infos_array = "NULL";
    PointerPairContainer<decltype(args.ppBuildRangeInfos.GetPointer()), decltype(args.ppBuildRangeInfos.GetMetaStructPointer())> pp_build_range_infos_pair{ args.ppBuildRangeInfos.GetPointer(), args.ppBuildRangeInfos.GetMetaStructPointer(), args.infoCount };
    std::string pp_build_range_infos_names = toStringJoin(pp_build_range_infos_pair.begin(),
                                                          pp_build_range_infos_pair.end(),
                                                          [&](auto pair) {{ return GenerateStruct_VkAccelerationStructureBuildRangeInfoKHR(stream_pp_build_range_infos, *pair.t1, *pair.t2, *this); }},
                                                          ", ");
    if (stream_pp_build_range_infos.str().length() > 0) {
        fprintf(file, "%s", stream_pp_build_range_infos.str().c_str());
        if (args.infoCount == 1) {
            pp_build_range_infos_array = "&" + pp_build_range_infos_names;
        } else if (args.infoCount > 1) {
            pp_build_range_infos_array = "ppBuildRangeInfos_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkAccelerationStructureBuildRangeInfoKHR %s[] = { %s };\n", pp_build_range_infos_array.c_str(), pp_build_range_infos_names.c_str());
        }
    }
    pfn_loader_.AddMethodName("vkCmdBuildAccelerationStructuresKHR");
    fprintf(file,
            "\t\tloaded_vkCmdBuildAccelerationStructuresKHR(%s, %u, %s, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.infoCount,
            pinfos_array.c_str(),
            pp_build_range_infos_array.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR);
}

void VulkanCppConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyAccelerationStructureKHR&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkCopyAccelerationStructureInfoKHR(stream_pinfo,
                                                                                 args.pInfo.GetPointer(),
                                                                                 args.pInfo.GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyAccelerationStructureKHR");
    fprintf(file,
            "\t\tloaded_vkCmdCopyAccelerationStructureKHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR);
}

void VulkanCppConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyAccelerationStructureToMemoryKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkCopyAccelerationStructureToMemoryInfoKHR(stream_pinfo,
                                                                                         args.pInfo.GetPointer(),
                                                                                         args.pInfo.GetMetaStructPointer(),
                                                                                         *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyAccelerationStructureToMemoryKHR");
    fprintf(file,
            "\t\tloaded_vkCmdCopyAccelerationStructureToMemoryKHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR);
}

void VulkanCppConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToAccelerationStructureKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkCopyMemoryToAccelerationStructureInfoKHR(stream_pinfo,
                                                                                         args.pInfo.GetPointer(),
                                                                                         args.pInfo.GetMetaStructPointer(),
                                                                                         *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCmdCopyMemoryToAccelerationStructureKHR");
    fprintf(file,
            "\t\tloaded_vkCmdCopyMemoryToAccelerationStructureKHR(%s, &%s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR);
}

void VulkanCppConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::CmdWriteAccelerationStructuresPropertiesKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pacceleration_structures_array = "NULL";
    std::string pacceleration_structures_values = toStringJoin(args.pAccelerationStructures.GetPointer(),
                                                               args.pAccelerationStructures.GetPointer() + args.accelerationStructureCount,
                                                               [&](const format::HandleId current) { return this->GetHandle(current); },
                                                               ", ");
    if (args.accelerationStructureCount == 1 && pacceleration_structures_values != "VK_NULL_HANDLE") {
        pacceleration_structures_array = "&" + pacceleration_structures_values;
    } else if (args.accelerationStructureCount > 1) {
        pacceleration_structures_array = "pacceleration_structures_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkAccelerationStructureKHR %s[] = { %s };\n", pacceleration_structures_array.c_str(), pacceleration_structures_values.c_str());
    }
    pfn_loader_.AddMethodName("vkCmdWriteAccelerationStructuresPropertiesKHR");
    fprintf(file,
            "\t\tloaded_vkCmdWriteAccelerationStructuresPropertiesKHR(%s, %u, %s, %s, %s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.accelerationStructureCount,
            pacceleration_structures_array.c_str(),
            util::ToString<VkQueryType>(args.queryType).c_str(),
            this->GetHandle(args.queryPool).c_str(),
            args.firstQuery);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR);
}

void VulkanCppConsumer::Process_vkCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CopyAccelerationStructureToMemoryKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkCopyAccelerationStructureToMemoryInfoKHR(stream_pinfo,
                                                                                         args.pInfo.GetPointer(),
                                                                                         args.pInfo.GetMetaStructPointer(),
                                                                                         *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCopyAccelerationStructureToMemoryKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCopyAccelerationStructureToMemoryKHR(%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.deferredOperation).c_str(),
            pinfo_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR);
}

void VulkanCppConsumer::Process_vkCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::CopyMemoryToAccelerationStructureKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkCopyMemoryToAccelerationStructureInfoKHR(stream_pinfo,
                                                                                         args.pInfo.GetPointer(),
                                                                                         args.pInfo.GetMetaStructPointer(),
                                                                                         *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkCopyMemoryToAccelerationStructureKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCopyMemoryToAccelerationStructureKHR(%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.deferredOperation).c_str(),
            pinfo_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR);
}

void VulkanCppConsumer::Process_vkCreateAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::CreateAccelerationStructureKHR&       args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pcreate_info;
    std::string pcreate_info_struct = GenerateStruct_VkAccelerationStructureCreateInfoKHR(stream_pcreate_info,
                                                                                          args.pCreateInfo.GetPointer(),
                                                                                          args.pCreateInfo.GetMetaStructPointer(),
                                                                                          *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pacceleration_structure_name = "pAccelerationStructure_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR));
    AddKnownVariables("VkAccelerationStructureKHR", pacceleration_structure_name, args.pAccelerationStructure.GetPointer());
    if (args.result == VK_SUCCESS) {
        this->AddHandles(pacceleration_structure_name,
                         args.pAccelerationStructure.GetPointer());
    }
    pfn_loader_.AddMethodName("vkCreateAccelerationStructureKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkCreateAccelerationStructureKHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pacceleration_structure_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR);
}

void VulkanCppConsumer::Process_vkDestroyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyAccelerationStructureKHR&      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkDestroyAccelerationStructureKHR");
    fprintf(file,
            "\t\tloaded_vkDestroyAccelerationStructureKHR(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.accelerationStructure).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR);
}

void VulkanCppConsumer::Process_vkGetAccelerationStructureBuildSizesKHR(
    const ApiCallInfo&                          call_info,
    args::GetAccelerationStructureBuildSizesKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pbuild_info;
    std::string pbuild_info_struct = GenerateStruct_VkAccelerationStructureBuildGeometryInfoKHR(stream_pbuild_info,
                                                                                                args.pBuildInfo.GetPointer(),
                                                                                                args.pBuildInfo.GetMetaStructPointer(),
                                                                                                *this);
    fprintf(file, "%s", stream_pbuild_info.str().c_str());
    std::string pmax_primitive_counts_array = "pMaxPrimitiveCounts_" + std::to_string(this->GetNextId());
    if (args.pBuildInfo.GetPointer()->geometryCount > 0 && args.pMaxPrimitiveCounts.GetPointer() != nullptr) {
        std::string pmax_primitive_counts_values = toStringJoin(args.pMaxPrimitiveCounts.GetPointer(),
                                                                args.pMaxPrimitiveCounts.GetPointer() + args.pBuildInfo.GetPointer()->geometryCount,
                                                                [&](const auto current) { return std::to_string(current) + ""; },
                                                                ", ");
        fprintf(file, "\t\tuint32_t %s[] = { %s };\n", pmax_primitive_counts_array.c_str(), pmax_primitive_counts_values.c_str());
    } else {
        pmax_primitive_counts_array = "NULL";
    }
    std::string psize_info_name = "NULL";
    if (!args.pSizeInfo.IsNull()) {
        psize_info_name = "pSizeInfo_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkAccelerationStructureBuildSizesInfoKHR %s = {};\n", psize_info_name.c_str());
        psize_info_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetAccelerationStructureBuildSizesKHR");
    fprintf(file,
            "\t\tloaded_vkGetAccelerationStructureBuildSizesKHR(%s, %s, &%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            util::ToString<VkAccelerationStructureBuildTypeKHR>(args.buildType).c_str(),
            pbuild_info_struct.c_str(),
            pmax_primitive_counts_array.c_str(),
            psize_info_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR);
}

void VulkanCppConsumer::Process_vkGetAccelerationStructureDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    args::GetAccelerationStructureDeviceAddressKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pinfo;
    std::string pinfo_struct = GenerateStruct_VkAccelerationStructureDeviceAddressInfoKHR(stream_pinfo,
                                                                                          args.pInfo.GetPointer(),
                                                                                          args.pInfo.GetMetaStructPointer(),
                                                                                          *this);
    fprintf(file, "%s", stream_pinfo.str().c_str());
    pfn_loader_.AddMethodName("vkGetAccelerationStructureDeviceAddressKHR");
    fprintf(file,
            "\t\tloaded_vkGetAccelerationStructureDeviceAddressKHR(%s, &%s);\n",
            this->GetHandle(args.device).c_str(),
            pinfo_struct.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR);
}

void VulkanCppConsumer::Process_vkGetDeviceAccelerationStructureCompatibilityKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceAccelerationStructureCompatibilityKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_pversion_info;
    std::string pversion_info_struct = GenerateStruct_VkAccelerationStructureVersionInfoKHR(stream_pversion_info,
                                                                                            args.pVersionInfo.GetPointer(),
                                                                                            args.pVersionInfo.GetMetaStructPointer(),
                                                                                            *this);
    fprintf(file, "%s", stream_pversion_info.str().c_str());
    std::string pcompatibility_name = "NULL";
    if (!args.pCompatibility.IsNull()) {
        pcompatibility_name = "pCompatibility_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkAccelerationStructureCompatibilityKHR %s = %s;\n", pcompatibility_name.c_str(), util::ToString(*args.pCompatibility.GetPointer()).c_str());
        pcompatibility_name.insert(0, "&");
    }
    pfn_loader_.AddMethodName("vkGetDeviceAccelerationStructureCompatibilityKHR");
    fprintf(file,
            "\t\tloaded_vkGetDeviceAccelerationStructureCompatibilityKHR(%s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            pversion_info_struct.c_str(),
            pcompatibility_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR);
}

void VulkanCppConsumer::Process_vkWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::WriteAccelerationStructuresPropertiesKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pacceleration_structures_array = "NULL";
    std::string pacceleration_structures_values = toStringJoin(args.pAccelerationStructures.GetPointer(),
                                                               args.pAccelerationStructures.GetPointer() + args.accelerationStructureCount,
                                                               [&](const format::HandleId current) { return this->GetHandle(current); },
                                                               ", ");
    if (args.accelerationStructureCount == 1 && pacceleration_structures_values != "VK_NULL_HANDLE") {
        pacceleration_structures_array = "&" + pacceleration_structures_values;
    } else if (args.accelerationStructureCount > 1) {
        pacceleration_structures_array = "pacceleration_structures_array_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tVkAccelerationStructureKHR %s[] = { %s };\n", pacceleration_structures_array.c_str(), pacceleration_structures_values.c_str());
    }
    std::string pdata_name = "NULL";
    if (!args.pData.IsNull()) {
        pdata_name = "pData_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint8_t %s[%" PRIu64 "] = {};\n", pdata_name.c_str(), util::platform::SizeTtoUint64(args.dataSize));
    }
    pfn_loader_.AddMethodName("vkWriteAccelerationStructuresPropertiesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkWriteAccelerationStructuresPropertiesKHR(%s, %u, %s, %s, %" PRIu64 ", %s, %" PRIu64 "), %s);\n",
            this->GetHandle(args.device).c_str(),
            args.accelerationStructureCount,
            pacceleration_structures_array.c_str(),
            util::ToString<VkQueryType>(args.queryType).c_str(),
            util::platform::SizeTtoUint64(args.dataSize),
            pdata_name.c_str(),
            util::platform::SizeTtoUint64(args.stride),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR);
}
void VulkanCppConsumer::Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetRayTracingPipelineStackSizeKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdSetRayTracingPipelineStackSizeKHR");
    fprintf(file,
            "\t\tloaded_vkCmdSetRayTracingPipelineStackSizeKHR(%s, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.pipelineStackSize);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR);
}

void VulkanCppConsumer::Process_vkCmdTraceRaysIndirectKHR(
    const ApiCallInfo&                          call_info,
    args::CmdTraceRaysIndirectKHR&              args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_praygen_shader_binding_table;
    std::string praygen_shader_binding_table_struct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_praygen_shader_binding_table,
                                                                                                     args.pRaygenShaderBindingTable.GetPointer(),
                                                                                                     args.pRaygenShaderBindingTable.GetMetaStructPointer(),
                                                                                                     *this);
    fprintf(file, "%s", stream_praygen_shader_binding_table.str().c_str());
    std::stringstream stream_pmiss_shader_binding_table;
    std::string pmiss_shader_binding_table_struct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_pmiss_shader_binding_table,
                                                                                                   args.pMissShaderBindingTable.GetPointer(),
                                                                                                   args.pMissShaderBindingTable.GetMetaStructPointer(),
                                                                                                   *this);
    fprintf(file, "%s", stream_pmiss_shader_binding_table.str().c_str());
    std::stringstream stream_phit_shader_binding_table;
    std::string phit_shader_binding_table_struct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_phit_shader_binding_table,
                                                                                                  args.pHitShaderBindingTable.GetPointer(),
                                                                                                  args.pHitShaderBindingTable.GetMetaStructPointer(),
                                                                                                  *this);
    fprintf(file, "%s", stream_phit_shader_binding_table.str().c_str());
    std::stringstream stream_pcallable_shader_binding_table;
    std::string pcallable_shader_binding_table_struct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_pcallable_shader_binding_table,
                                                                                                       args.pCallableShaderBindingTable.GetPointer(),
                                                                                                       args.pCallableShaderBindingTable.GetMetaStructPointer(),
                                                                                                       *this);
    fprintf(file, "%s", stream_pcallable_shader_binding_table.str().c_str());
    pfn_loader_.AddMethodName("vkCmdTraceRaysIndirectKHR");
    fprintf(file,
            "\t\tloaded_vkCmdTraceRaysIndirectKHR(%s, &%s, &%s, &%s, &%s, %" PRIu64 "UL);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            praygen_shader_binding_table_struct.c_str(),
            pmiss_shader_binding_table_struct.c_str(),
            phit_shader_binding_table_struct.c_str(),
            pcallable_shader_binding_table_struct.c_str(),
            args.indirectDeviceAddress);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR);
}

void VulkanCppConsumer::Process_vkCmdTraceRaysKHR(
    const ApiCallInfo&                          call_info,
    args::CmdTraceRaysKHR&                      args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_praygen_shader_binding_table;
    std::string praygen_shader_binding_table_struct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_praygen_shader_binding_table,
                                                                                                     args.pRaygenShaderBindingTable.GetPointer(),
                                                                                                     args.pRaygenShaderBindingTable.GetMetaStructPointer(),
                                                                                                     *this);
    fprintf(file, "%s", stream_praygen_shader_binding_table.str().c_str());
    std::stringstream stream_pmiss_shader_binding_table;
    std::string pmiss_shader_binding_table_struct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_pmiss_shader_binding_table,
                                                                                                   args.pMissShaderBindingTable.GetPointer(),
                                                                                                   args.pMissShaderBindingTable.GetMetaStructPointer(),
                                                                                                   *this);
    fprintf(file, "%s", stream_pmiss_shader_binding_table.str().c_str());
    std::stringstream stream_phit_shader_binding_table;
    std::string phit_shader_binding_table_struct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_phit_shader_binding_table,
                                                                                                  args.pHitShaderBindingTable.GetPointer(),
                                                                                                  args.pHitShaderBindingTable.GetMetaStructPointer(),
                                                                                                  *this);
    fprintf(file, "%s", stream_phit_shader_binding_table.str().c_str());
    std::stringstream stream_pcallable_shader_binding_table;
    std::string pcallable_shader_binding_table_struct = GenerateStruct_VkStridedDeviceAddressRegionKHR(stream_pcallable_shader_binding_table,
                                                                                                       args.pCallableShaderBindingTable.GetPointer(),
                                                                                                       args.pCallableShaderBindingTable.GetMetaStructPointer(),
                                                                                                       *this);
    fprintf(file, "%s", stream_pcallable_shader_binding_table.str().c_str());
    pfn_loader_.AddMethodName("vkCmdTraceRaysKHR");
    fprintf(file,
            "\t\tloaded_vkCmdTraceRaysKHR(%s, &%s, &%s, &%s, &%s, %u, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            praygen_shader_binding_table_struct.c_str(),
            pmiss_shader_binding_table_struct.c_str(),
            phit_shader_binding_table_struct.c_str(),
            pcallable_shader_binding_table_struct.c_str(),
            args.width,
            args.height,
            args.depth);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdTraceRaysKHR);
}

void VulkanCppConsumer::Process_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(
    const ApiCallInfo&                          call_info,
    args::GetRayTracingCaptureReplayShaderGroupHandlesKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pdata_name = "NULL";
    if (!args.pData.IsNull()) {
        pdata_name = "pData_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tuint8_t %s[%" PRIu64 "] = {};\n", pdata_name.c_str(), util::platform::SizeTtoUint64(args.dataSize));
    }
    pfn_loader_.AddMethodName("vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(%s, %s, %u, %u, %" PRIu64 ", %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.pipeline).c_str(),
            args.firstGroup,
            args.groupCount,
            util::platform::SizeTtoUint64(args.dataSize),
            pdata_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR);
}

void VulkanCppConsumer::Process_vkGetRayTracingShaderGroupStackSizeKHR(
    const ApiCallInfo&                          call_info,
    args::GetRayTracingShaderGroupStackSizeKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkGetRayTracingShaderGroupStackSizeKHR");
    fprintf(file,
            "\t\tloaded_vkGetRayTracingShaderGroupStackSizeKHR(%s, %s, %u, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.pipeline).c_str(),
            args.group,
            util::ToString<VkShaderGroupShaderKHR>(args.groupShader).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR);
}
void VulkanCppConsumer::Process_vkCmdDrawMeshTasksEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksEXT&                  args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawMeshTasksEXT");
    fprintf(file,
            "\t\tloaded_vkCmdDrawMeshTasksEXT(%s, %u, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            args.groupCountX,
            args.groupCountY,
            args.groupCountZ);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT);
}

void VulkanCppConsumer::Process_vkCmdDrawMeshTasksIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectCountEXT&     args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawMeshTasksIndirectCountEXT");
    fprintf(file,
            "\t\tloaded_vkCmdDrawMeshTasksIndirectCountEXT(%s, %s, %" PRIu64 "UL, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.buffer).c_str(),
            args.offset,
            this->GetHandle(args.countBuffer).c_str(),
            args.countBufferOffset,
            args.maxDrawCount,
            args.stride);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT);
}

void VulkanCppConsumer::Process_vkCmdDrawMeshTasksIndirectEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectEXT&          args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    pfn_loader_.AddMethodName("vkCmdDrawMeshTasksIndirectEXT");
    fprintf(file,
            "\t\tloaded_vkCmdDrawMeshTasksIndirectEXT(%s, %s, %" PRIu64 "UL, %u, %u);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.buffer).c_str(),
            args.offset,
            args.drawCount,
            args.stride);
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT);
}
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
