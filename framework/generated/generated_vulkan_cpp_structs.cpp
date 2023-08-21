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

#include "decode/vulkan_cpp_structs.h"
#include "generated/generated_vulkan_cpp_structs.h"
#include "generated/generated_vulkan_cpp_consumer.h"
#include "generated/generated_vulkan_cpp_consumer_extension.h"
#include "generated/generated_vulkan_enum_to_string.h"
GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)


std::string GenerateStruct_VkAttachmentDescription(std::ostream &out, const VkAttachmentDescription* structInfo, Decoded_VkAttachmentDescription* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* flags */
    structBody << "\t" << "VkAttachmentDescriptionFlags(" << structInfo->flags << ")" << "," << std::endl;
/* format */
    structBody << "\t" << "VkFormat(" << structInfo->format << ")" << "," << std::endl;
/* samples */
    structBody << "\t" << "VkSampleCountFlagBits(" << structInfo->samples << ")" << "," << std::endl;
/* loadOp */
    structBody << "\t" << "VkAttachmentLoadOp(" << structInfo->loadOp << ")" << "," << std::endl;
/* storeOp */
    structBody << "\t" << "VkAttachmentStoreOp(" << structInfo->storeOp << ")" << "," << std::endl;
/* stencilLoadOp */
    structBody << "\t" << "VkAttachmentLoadOp(" << structInfo->stencilLoadOp << ")" << "," << std::endl;
/* stencilStoreOp */
    structBody << "\t" << "VkAttachmentStoreOp(" << structInfo->stencilStoreOp << ")" << "," << std::endl;
/* initialLayout */
    structBody << "\t" << "VkImageLayout(" << structInfo->initialLayout << ")" << "," << std::endl;
/* finalLayout */
    structBody << "\t" << "VkImageLayout(" << structInfo->finalLayout << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "attachmentDescription");
        out << "VkAttachmentDescription " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkAttachmentReference(std::ostream &out, const VkAttachmentReference* structInfo, Decoded_VkAttachmentReference* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* attachment */
    structBody << "\t" << structInfo->attachment << "," << std::endl;
/* layout */
    structBody << "\t" << "VkImageLayout(" << structInfo->layout << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "attachmentReference");
        out << "VkAttachmentReference " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkBindSparseInfo(std::ostream &out, const VkBindSparseInfo* structInfo, Decoded_VkBindSparseInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pSignalSemaphoresArray = "NULL";
    if (metainfo->pSignalSemaphores.GetPointer() != NULL && structInfo->signalSemaphoreCount > 0) {
        pSignalSemaphoresArray = "pSignalSemaphoresArray_" + std::to_string(consumer.getNextId());
        std::string pSignalSemaphoresValues = toStringJoin(metainfo->pSignalSemaphores.GetPointer(),
                                                           metainfo->pSignalSemaphores.GetPointer() + structInfo->signalSemaphoreCount,
                                                           [&](const format::HandleId current) { return consumer.GetHandle(current); },
                                                           ", ");
        if (structInfo->signalSemaphoreCount == 1) {
            pSignalSemaphoresArray = "&" + pSignalSemaphoresValues;
        } else if (structInfo->signalSemaphoreCount > 1) {
            out << "VkSemaphore " << pSignalSemaphoresArray << "[] = {" << pSignalSemaphoresValues << "};" << std::endl;
        }
    }
    std::string pImageBindsArray = "NULL";
    if (structInfo->pImageBinds != NULL) {
        pImageBindsArray = "pImageBinds_" + std::to_string(consumer.getNextId());
        std::string pImageBindsNames;
        for (uint32_t idx = 0; idx < structInfo->imageBindCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pImageBinds + idx != NULL) {
                varName = GenerateStruct_VkSparseImageMemoryBindInfo(out,
                                                         structInfo->pImageBinds + idx,
                                                         metainfo->pImageBinds->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pImageBindsNames += varName + ", ";
        }
        out << "VkSparseImageMemoryBindInfo " << pImageBindsArray << "[] = {" << pImageBindsNames << "};" << std::endl;
    }
    std::string pImageOpaqueBindsArray = "NULL";
    if (structInfo->pImageOpaqueBinds != NULL) {
        pImageOpaqueBindsArray = "pImageOpaqueBinds_" + std::to_string(consumer.getNextId());
        std::string pImageOpaqueBindsNames;
        for (uint32_t idx = 0; idx < structInfo->imageOpaqueBindCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pImageOpaqueBinds + idx != NULL) {
                varName = GenerateStruct_VkSparseImageOpaqueMemoryBindInfo(out,
                                                         structInfo->pImageOpaqueBinds + idx,
                                                         metainfo->pImageOpaqueBinds->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pImageOpaqueBindsNames += varName + ", ";
        }
        out << "VkSparseImageOpaqueMemoryBindInfo " << pImageOpaqueBindsArray << "[] = {" << pImageOpaqueBindsNames << "};" << std::endl;
    }
    std::string pBufferBindsArray = "NULL";
    if (structInfo->pBufferBinds != NULL) {
        pBufferBindsArray = "pBufferBinds_" + std::to_string(consumer.getNextId());
        std::string pBufferBindsNames;
        for (uint32_t idx = 0; idx < structInfo->bufferBindCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pBufferBinds + idx != NULL) {
                varName = GenerateStruct_VkSparseBufferMemoryBindInfo(out,
                                                         structInfo->pBufferBinds + idx,
                                                         metainfo->pBufferBinds->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pBufferBindsNames += varName + ", ";
        }
        out << "VkSparseBufferMemoryBindInfo " << pBufferBindsArray << "[] = {" << pBufferBindsNames << "};" << std::endl;
    }
    std::string pWaitSemaphoresArray = "NULL";
    if (metainfo->pWaitSemaphores.GetPointer() != NULL && structInfo->waitSemaphoreCount > 0) {
        pWaitSemaphoresArray = "pWaitSemaphoresArray_" + std::to_string(consumer.getNextId());
        std::string pWaitSemaphoresValues = toStringJoin(metainfo->pWaitSemaphores.GetPointer(),
                                                         metainfo->pWaitSemaphores.GetPointer() + structInfo->waitSemaphoreCount,
                                                         [&](const format::HandleId current) { return consumer.GetHandle(current); },
                                                         ", ");
        if (structInfo->waitSemaphoreCount == 1) {
            pWaitSemaphoresArray = "&" + pWaitSemaphoresValues;
        } else if (structInfo->waitSemaphoreCount > 1) {
            out << "VkSemaphore " << pWaitSemaphoresArray << "[] = {" << pWaitSemaphoresValues << "};" << std::endl;
        }
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* waitSemaphoreCount */
    structBody << "\t" << structInfo->waitSemaphoreCount << "," << std::endl;
/* pWaitSemaphores */
    structBody << "\t" << pWaitSemaphoresArray << "," << std::endl;
/* bufferBindCount */
    structBody << "\t" << structInfo->bufferBindCount << "," << std::endl;
/* pBufferBinds */
    structBody << "\t" << pBufferBindsArray << "," << std::endl;
/* imageOpaqueBindCount */
    structBody << "\t" << structInfo->imageOpaqueBindCount << "," << std::endl;
/* pImageOpaqueBinds */
    structBody << "\t" << pImageOpaqueBindsArray << "," << std::endl;
/* imageBindCount */
    structBody << "\t" << structInfo->imageBindCount << "," << std::endl;
/* pImageBinds */
    structBody << "\t" << pImageBindsArray << "," << std::endl;
/* signalSemaphoreCount */
    structBody << "\t" << structInfo->signalSemaphoreCount << "," << std::endl;
/* pSignalSemaphores */
    structBody << "\t" << pSignalSemaphoresArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "bindSparseInfo");
        out << "VkBindSparseInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkBufferCopy(std::ostream &out, const VkBufferCopy* structInfo, Decoded_VkBufferCopy* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* srcOffset */
    structBody << "\t" << structInfo->srcOffset << "UL" << "," << std::endl;
/* dstOffset */
    structBody << "\t" << structInfo->dstOffset << "UL" << "," << std::endl;
/* size */
    structBody << "\t" << structInfo->size << "UL" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "bufferCopy");
        out << "VkBufferCopy " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkBufferCreateInfo(std::ostream &out, const VkBufferCreateInfo* structInfo, Decoded_VkBufferCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pQueueFamilyIndicesArray = "NULL";
    if (structInfo->pQueueFamilyIndices != NULL) {
        pQueueFamilyIndicesArray = "pQueueFamilyIndices_" + std::to_string(consumer.getNextId());
        out << "uint32_t " << pQueueFamilyIndicesArray << "[] = " << VulkanCppConsumerBase::BuildValue(structInfo->pQueueFamilyIndices, structInfo->queueFamilyIndexCount) << ";" << std::endl;
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkBufferCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* size */
    structBody << "\t" << structInfo->size << "UL" << "," << std::endl;
/* usage */
    structBody << "\t" << "VkBufferUsageFlags(" << structInfo->usage << ")" << "," << std::endl;
/* sharingMode */
    structBody << "\t" << "VkSharingMode(" << structInfo->sharingMode << ")" << "," << std::endl;
/* queueFamilyIndexCount */
    structBody << "\t" << structInfo->queueFamilyIndexCount << "," << std::endl;
/* pQueueFamilyIndices */
    structBody << "\t" << pQueueFamilyIndicesArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "bufferCreateInfo");
        out << "VkBufferCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkBufferImageCopy(std::ostream &out, const VkBufferImageCopy* structInfo, Decoded_VkBufferImageCopy* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* bufferOffset */
    structBody << "\t" << structInfo->bufferOffset << "UL" << "," << std::endl;
/* bufferRowLength */
    structBody << "\t" << structInfo->bufferRowLength << "," << std::endl;
/* bufferImageHeight */
    structBody << "\t" << structInfo->bufferImageHeight << "," << std::endl;
/* imageSubresource */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->imageSubresource) << "," << std::endl;
/* imageOffset */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->imageOffset) << "," << std::endl;
/* imageExtent */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->imageExtent) << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "bufferImageCopy");
        out << "VkBufferImageCopy " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkBufferMemoryBarrier(std::ostream &out, const VkBufferMemoryBarrier* structInfo, Decoded_VkBufferMemoryBarrier* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* srcAccessMask */
    structBody << "\t" << "VkAccessFlags(" << structInfo->srcAccessMask << ")" << "," << std::endl;
/* dstAccessMask */
    structBody << "\t" << "VkAccessFlags(" << structInfo->dstAccessMask << ")" << "," << std::endl;
/* srcQueueFamilyIndex */
    structBody << "\t" << structInfo->srcQueueFamilyIndex << "," << std::endl;
/* dstQueueFamilyIndex */
    structBody << "\t" << structInfo->dstQueueFamilyIndex << "," << std::endl;
/* buffer */
    structBody << "\t" << consumer.GetHandle(metainfo->buffer) << "," << std::endl;
/* offset */
    structBody << "\t" << structInfo->offset << "UL" << "," << std::endl;
/* size */
    structBody << "\t" << structInfo->size << "UL" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "bufferMemoryBarrier");
        out << "VkBufferMemoryBarrier " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkBufferViewCreateInfo(std::ostream &out, const VkBufferViewCreateInfo* structInfo, Decoded_VkBufferViewCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkBufferViewCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* buffer */
    structBody << "\t" << consumer.GetHandle(metainfo->buffer) << "," << std::endl;
/* format */
    structBody << "\t" << "VkFormat(" << structInfo->format << ")" << "," << std::endl;
/* offset */
    structBody << "\t" << structInfo->offset << "UL" << "," << std::endl;
/* range */
    structBody << "\t" << structInfo->range << "UL" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "bufferViewCreateInfo");
        out << "VkBufferViewCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkClearAttachment(std::ostream &out, const VkClearAttachment* structInfo, Decoded_VkClearAttachment* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* aspectMask */
    structBody << "\t" << "VkImageAspectFlags(" << structInfo->aspectMask << ")" << "," << std::endl;
/* colorAttachment */
    structBody << "\t" << structInfo->colorAttachment << "," << std::endl;
/* clearValue */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->clearValue) << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "clearAttachment");
        out << "VkClearAttachment " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkClearDepthStencilValue(std::ostream &out, const VkClearDepthStencilValue* structInfo, Decoded_VkClearDepthStencilValue* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* depth */
    structBody << "\t" << structInfo->depth << "," << std::endl;
/* stencil */
    structBody << "\t" << structInfo->stencil << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "clearDepthStencilValue");
        out << "VkClearDepthStencilValue " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkClearRect(std::ostream &out, const VkClearRect* structInfo, Decoded_VkClearRect* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* rect */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->rect) << "," << std::endl;
/* baseArrayLayer */
    structBody << "\t" << structInfo->baseArrayLayer << "," << std::endl;
/* layerCount */
    structBody << "\t" << structInfo->layerCount << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "clearRect");
        out << "VkClearRect " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkCommandBufferAllocateInfo(std::ostream &out, const VkCommandBufferAllocateInfo* structInfo, Decoded_VkCommandBufferAllocateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* commandPool */
    structBody << "\t" << consumer.GetHandle(metainfo->commandPool) << "," << std::endl;
/* level */
    structBody << "\t" << "VkCommandBufferLevel(" << structInfo->level << ")" << "," << std::endl;
/* commandBufferCount */
    structBody << "\t" << structInfo->commandBufferCount << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "commandBufferAllocateInfo");
        out << "VkCommandBufferAllocateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkCommandBufferBeginInfo(std::ostream &out, const VkCommandBufferBeginInfo* structInfo, Decoded_VkCommandBufferBeginInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pInheritanceInfoStruct = "NULL";
    if (structInfo->pInheritanceInfo != NULL) {
        pInheritanceInfoStruct = GenerateStruct_VkCommandBufferInheritanceInfo(out,
                                                                structInfo->pInheritanceInfo,
                                                                metainfo->pInheritanceInfo->GetMetaStructPointer(),
                                                                consumer);
        pInheritanceInfoStruct.insert(0, "&");
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkCommandBufferUsageFlags(" << structInfo->flags << ")" << "," << std::endl;
/* pInheritanceInfo */
    structBody << "\t" << pInheritanceInfoStruct << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "commandBufferBeginInfo");
        out << "VkCommandBufferBeginInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkCommandBufferInheritanceInfo(std::ostream &out, const VkCommandBufferInheritanceInfo* structInfo, Decoded_VkCommandBufferInheritanceInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* renderPass */
    structBody << "\t" << consumer.GetHandle(metainfo->renderPass) << "," << std::endl;
/* subpass */
    structBody << "\t" << structInfo->subpass << "," << std::endl;
/* framebuffer */
    structBody << "\t" << consumer.GetHandle(metainfo->framebuffer) << "," << std::endl;
/* occlusionQueryEnable */
    structBody << "\t" << structInfo->occlusionQueryEnable << "," << std::endl;
/* queryFlags */
    structBody << "\t" << "VkQueryControlFlags(" << structInfo->queryFlags << ")" << "," << std::endl;
/* pipelineStatistics */
    structBody << "\t" << "VkQueryPipelineStatisticFlags(" << structInfo->pipelineStatistics << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "commandBufferInheritanceInfo");
        out << "VkCommandBufferInheritanceInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkCommandPoolCreateInfo(std::ostream &out, const VkCommandPoolCreateInfo* structInfo, Decoded_VkCommandPoolCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkCommandPoolCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* queueFamilyIndex */
    structBody << "\t" << structInfo->queueFamilyIndex << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "commandPoolCreateInfo");
        out << "VkCommandPoolCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkComponentMapping(std::ostream &out, const VkComponentMapping* structInfo, Decoded_VkComponentMapping* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* r */
    structBody << "\t" << "VkComponentSwizzle(" << structInfo->r << ")" << "," << std::endl;
/* g */
    structBody << "\t" << "VkComponentSwizzle(" << structInfo->g << ")" << "," << std::endl;
/* b */
    structBody << "\t" << "VkComponentSwizzle(" << structInfo->b << ")" << "," << std::endl;
/* a */
    structBody << "\t" << "VkComponentSwizzle(" << structInfo->a << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "componentMapping");
        out << "VkComponentMapping " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkComputePipelineCreateInfo(std::ostream &out, const VkComputePipelineCreateInfo* structInfo, Decoded_VkComputePipelineCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string stageInfoVar = GenerateStruct_VkPipelineShaderStageCreateInfo(out,
                                                              &structInfo->stage,
                                                              metainfo->stage,
                                                              consumer);
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkPipelineCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* stage */
    structBody << "\t" << stageInfoVar << "," << std::endl;
/* layout */
    structBody << "\t" << consumer.GetHandle(metainfo->layout) << "," << std::endl;
/* basePipelineHandle */
    structBody << "\t" << consumer.GetHandle(metainfo->basePipelineHandle) << "," << std::endl;
/* basePipelineIndex */
    structBody << "\t" << structInfo->basePipelineIndex << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "computePipelineCreateInfo");
        out << "VkComputePipelineCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkCopyDescriptorSet(std::ostream &out, const VkCopyDescriptorSet* structInfo, Decoded_VkCopyDescriptorSet* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* srcSet */
    structBody << "\t" << consumer.GetHandle(metainfo->srcSet) << "," << std::endl;
/* srcBinding */
    structBody << "\t" << structInfo->srcBinding << "," << std::endl;
/* srcArrayElement */
    structBody << "\t" << structInfo->srcArrayElement << "," << std::endl;
/* dstSet */
    structBody << "\t" << consumer.GetHandle(metainfo->dstSet) << "," << std::endl;
/* dstBinding */
    structBody << "\t" << structInfo->dstBinding << "," << std::endl;
/* dstArrayElement */
    structBody << "\t" << structInfo->dstArrayElement << "," << std::endl;
/* descriptorCount */
    structBody << "\t" << structInfo->descriptorCount << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "copyDescriptorSet");
        out << "VkCopyDescriptorSet " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkDescriptorBufferInfo(std::ostream &out, const VkDescriptorBufferInfo* structInfo, Decoded_VkDescriptorBufferInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* buffer */
    structBody << "\t" << consumer.GetHandle(metainfo->buffer) << "," << std::endl;
/* offset */
    structBody << "\t" << structInfo->offset << "UL" << "," << std::endl;
/* range */
    structBody << "\t" << structInfo->range << "UL" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "descriptorBufferInfo");
        out << "VkDescriptorBufferInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkDescriptorPoolCreateInfo(std::ostream &out, const VkDescriptorPoolCreateInfo* structInfo, Decoded_VkDescriptorPoolCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pPoolSizesArray = "NULL";
    if (structInfo->pPoolSizes != NULL) {
        pPoolSizesArray = "pPoolSizes_" + std::to_string(consumer.getNextId());
        std::string pPoolSizesNames;
        for (uint32_t idx = 0; idx < structInfo->poolSizeCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pPoolSizes + idx != NULL) {
                varName = GenerateStruct_VkDescriptorPoolSize(out,
                                                         structInfo->pPoolSizes + idx,
                                                         metainfo->pPoolSizes->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pPoolSizesNames += varName + ", ";
        }
        out << "VkDescriptorPoolSize " << pPoolSizesArray << "[] = {" << pPoolSizesNames << "};" << std::endl;
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkDescriptorPoolCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* maxSets */
    structBody << "\t" << structInfo->maxSets << "," << std::endl;
/* poolSizeCount */
    structBody << "\t" << structInfo->poolSizeCount << "," << std::endl;
/* pPoolSizes */
    structBody << "\t" << pPoolSizesArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "descriptorPoolCreateInfo");
        out << "VkDescriptorPoolCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkDescriptorPoolSize(std::ostream &out, const VkDescriptorPoolSize* structInfo, Decoded_VkDescriptorPoolSize* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* type */
    structBody << "\t" << "VkDescriptorType(" << structInfo->type << ")" << "," << std::endl;
/* descriptorCount */
    structBody << "\t" << structInfo->descriptorCount << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "descriptorPoolSize");
        out << "VkDescriptorPoolSize " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkDescriptorSetAllocateInfo(std::ostream &out, const VkDescriptorSetAllocateInfo* structInfo, Decoded_VkDescriptorSetAllocateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pSetLayoutsArray = "NULL";
    if (metainfo->pSetLayouts.GetPointer() != NULL && structInfo->descriptorSetCount > 0) {
        pSetLayoutsArray = "pSetLayoutsArray_" + std::to_string(consumer.getNextId());
        std::string pSetLayoutsValues = toStringJoin(metainfo->pSetLayouts.GetPointer(),
                                                     metainfo->pSetLayouts.GetPointer() + structInfo->descriptorSetCount,
                                                     [&](const format::HandleId current) { return consumer.GetHandle(current); },
                                                     ", ");
        if (structInfo->descriptorSetCount == 1) {
            pSetLayoutsArray = "&" + pSetLayoutsValues;
        } else if (structInfo->descriptorSetCount > 1) {
            out << "VkDescriptorSetLayout " << pSetLayoutsArray << "[] = {" << pSetLayoutsValues << "};" << std::endl;
        }
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* descriptorPool */
    structBody << "\t" << consumer.GetHandle(metainfo->descriptorPool) << "," << std::endl;
/* descriptorSetCount */
    structBody << "\t" << structInfo->descriptorSetCount << "," << std::endl;
/* pSetLayouts */
    structBody << "\t" << pSetLayoutsArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "descriptorSetAllocateInfo");
        out << "VkDescriptorSetAllocateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkDescriptorSetLayoutBinding(std::ostream &out, const VkDescriptorSetLayoutBinding* structInfo, Decoded_VkDescriptorSetLayoutBinding* metainfo, VulkanCppConsumerBase &consumer){
    std::string pImmutableSamplersArray = "NULL";
    if (metainfo->pImmutableSamplers.GetPointer() != NULL && structInfo->descriptorCount > 0) {
        pImmutableSamplersArray = "pImmutableSamplersArray_" + std::to_string(consumer.getNextId());
        std::string pImmutableSamplersValues = toStringJoin(metainfo->pImmutableSamplers.GetPointer(),
                                                            metainfo->pImmutableSamplers.GetPointer() + structInfo->descriptorCount,
                                                            [&](const format::HandleId current) { return consumer.GetHandle(current); },
                                                            ", ");
        if (structInfo->descriptorCount == 1) {
            pImmutableSamplersArray = "&" + pImmutableSamplersValues;
        } else if (structInfo->descriptorCount > 1) {
            out << "VkSampler " << pImmutableSamplersArray << "[] = {" << pImmutableSamplersValues << "};" << std::endl;
        }
    }
    std::stringstream structBody;
/* binding */
    structBody << "\t" << structInfo->binding << "," << std::endl;
/* descriptorType */
    structBody << "\t" << "VkDescriptorType(" << structInfo->descriptorType << ")" << "," << std::endl;
/* descriptorCount */
    structBody << "\t" << structInfo->descriptorCount << "," << std::endl;
/* stageFlags */
    structBody << "\t" << "VkShaderStageFlags(" << structInfo->stageFlags << ")" << "," << std::endl;
/* pImmutableSamplers */
    structBody << "\t" << pImmutableSamplersArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "descriptorSetLayoutBinding");
        out << "VkDescriptorSetLayoutBinding " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkDescriptorSetLayoutCreateInfo(std::ostream &out, const VkDescriptorSetLayoutCreateInfo* structInfo, Decoded_VkDescriptorSetLayoutCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pBindingsArray = "NULL";
    if (structInfo->pBindings != NULL) {
        pBindingsArray = "pBindings_" + std::to_string(consumer.getNextId());
        std::string pBindingsNames;
        for (uint32_t idx = 0; idx < structInfo->bindingCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pBindings + idx != NULL) {
                varName = GenerateStruct_VkDescriptorSetLayoutBinding(out,
                                                         structInfo->pBindings + idx,
                                                         metainfo->pBindings->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pBindingsNames += varName + ", ";
        }
        out << "VkDescriptorSetLayoutBinding " << pBindingsArray << "[] = {" << pBindingsNames << "};" << std::endl;
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkDescriptorSetLayoutCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* bindingCount */
    structBody << "\t" << structInfo->bindingCount << "," << std::endl;
/* pBindings */
    structBody << "\t" << pBindingsArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "descriptorSetLayoutCreateInfo");
        out << "VkDescriptorSetLayoutCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkDeviceCreateInfo(std::ostream &out, const VkDeviceCreateInfo* structInfo, Decoded_VkDeviceCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pEnabledFeaturesStruct = "NULL";
    if (structInfo->pEnabledFeatures != NULL) {
        pEnabledFeaturesStruct = GenerateStruct_VkPhysicalDeviceFeatures(out,
                                                                structInfo->pEnabledFeatures,
                                                                metainfo->pEnabledFeatures->GetMetaStructPointer(),
                                                                consumer);
        pEnabledFeaturesStruct.insert(0, "&");
    }
    std::string ppEnabledExtensionNamesVar = "NULL";
    if (structInfo->enabledExtensionCount) {
        ppEnabledExtensionNamesVar = "ppEnabledExtensionNames_" + std::to_string(consumer.getNextId());
        out << "const char* " << ppEnabledExtensionNamesVar << "[] = " << VulkanCppConsumerBase::escapeStringArray(structInfo->ppEnabledExtensionNames, structInfo->enabledExtensionCount) << ";" << std::endl;
    }
    std::string ppEnabledLayerNamesVar = "NULL";
    if (structInfo->enabledLayerCount) {
        ppEnabledLayerNamesVar = "ppEnabledLayerNames_" + std::to_string(consumer.getNextId());
        out << "const char* " << ppEnabledLayerNamesVar << "[] = " << VulkanCppConsumerBase::escapeStringArray(structInfo->ppEnabledLayerNames, structInfo->enabledLayerCount) << ";" << std::endl;
    }
    std::string pQueueCreateInfosArray = "NULL";
    if (structInfo->pQueueCreateInfos != NULL) {
        pQueueCreateInfosArray = "pQueueCreateInfos_" + std::to_string(consumer.getNextId());
        std::string pQueueCreateInfosNames;
        for (uint32_t idx = 0; idx < structInfo->queueCreateInfoCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pQueueCreateInfos + idx != NULL) {
                varName = GenerateStruct_VkDeviceQueueCreateInfo(out,
                                                         structInfo->pQueueCreateInfos + idx,
                                                         metainfo->pQueueCreateInfos->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pQueueCreateInfosNames += varName + ", ";
        }
        out << "VkDeviceQueueCreateInfo " << pQueueCreateInfosArray << "[] = {" << pQueueCreateInfosNames << "};" << std::endl;
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkDeviceCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* queueCreateInfoCount */
    structBody << "\t" << structInfo->queueCreateInfoCount << "," << std::endl;
/* pQueueCreateInfos */
    structBody << "\t" << pQueueCreateInfosArray << "," << std::endl;
/* enabledLayerCount */
    structBody << "\t" << structInfo->enabledLayerCount << "," << std::endl;
/* ppEnabledLayerNames */
    structBody << "\t" << ppEnabledLayerNamesVar << "," << std::endl;
/* enabledExtensionCount */
    structBody << "\t" << structInfo->enabledExtensionCount << "," << std::endl;
/* ppEnabledExtensionNames */
    structBody << "\t" << ppEnabledExtensionNamesVar << "," << std::endl;
/* pEnabledFeatures */
    structBody << "\t" << pEnabledFeaturesStruct << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "deviceCreateInfo");
        out << "VkDeviceCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkDeviceQueueCreateInfo(std::ostream &out, const VkDeviceQueueCreateInfo* structInfo, Decoded_VkDeviceQueueCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pQueuePrioritiesArray = "NULL";
    if (structInfo->pQueuePriorities != NULL) {
        pQueuePrioritiesArray = "pQueuePriorities_" + std::to_string(consumer.getNextId());
        out << "float " << pQueuePrioritiesArray << "[] = " << VulkanCppConsumerBase::BuildValue(structInfo->pQueuePriorities, structInfo->queueCount) << ";" << std::endl;
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkDeviceQueueCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* queueFamilyIndex */
    structBody << "\t" << structInfo->queueFamilyIndex << "," << std::endl;
/* queueCount */
    structBody << "\t" << structInfo->queueCount << "," << std::endl;
/* pQueuePriorities */
    structBody << "\t" << pQueuePrioritiesArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "deviceQueueCreateInfo");
        out << "VkDeviceQueueCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkDispatchIndirectCommand(std::ostream &out, const VkDispatchIndirectCommand* structInfo, Decoded_VkDispatchIndirectCommand* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* x */
    structBody << "\t" << structInfo->x << "," << std::endl;
/* y */
    structBody << "\t" << structInfo->y << "," << std::endl;
/* z */
    structBody << "\t" << structInfo->z << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "dispatchIndirectCommand");
        out << "VkDispatchIndirectCommand " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkDrawIndexedIndirectCommand(std::ostream &out, const VkDrawIndexedIndirectCommand* structInfo, Decoded_VkDrawIndexedIndirectCommand* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* indexCount */
    structBody << "\t" << structInfo->indexCount << "," << std::endl;
/* instanceCount */
    structBody << "\t" << structInfo->instanceCount << "," << std::endl;
/* firstIndex */
    structBody << "\t" << structInfo->firstIndex << "," << std::endl;
/* vertexOffset */
    structBody << "\t" << structInfo->vertexOffset << "," << std::endl;
/* firstInstance */
    structBody << "\t" << structInfo->firstInstance << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "drawIndexedIndirectCommand");
        out << "VkDrawIndexedIndirectCommand " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkDrawIndirectCommand(std::ostream &out, const VkDrawIndirectCommand* structInfo, Decoded_VkDrawIndirectCommand* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* vertexCount */
    structBody << "\t" << structInfo->vertexCount << "," << std::endl;
/* instanceCount */
    structBody << "\t" << structInfo->instanceCount << "," << std::endl;
/* firstVertex */
    structBody << "\t" << structInfo->firstVertex << "," << std::endl;
/* firstInstance */
    structBody << "\t" << structInfo->firstInstance << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "drawIndirectCommand");
        out << "VkDrawIndirectCommand " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkEventCreateInfo(std::ostream &out, const VkEventCreateInfo* structInfo, Decoded_VkEventCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkEventCreateFlags(" << structInfo->flags << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "eventCreateInfo");
        out << "VkEventCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkExtensionProperties(std::ostream &out, const VkExtensionProperties* structInfo, Decoded_VkExtensionProperties* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* extensionName */
    structBody << "\t" << VulkanCppConsumerBase::toEscape(structInfo->extensionName) << "," << std::endl;
/* specVersion */
    structBody << "\t" << structInfo->specVersion << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "extensionProperties");
        out << "VkExtensionProperties " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkExtent2D(std::ostream &out, const VkExtent2D* structInfo, Decoded_VkExtent2D* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* width */
    structBody << "\t" << structInfo->width << "," << std::endl;
/* height */
    structBody << "\t" << structInfo->height << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "extent2D");
        out << "VkExtent2D " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkExtent3D(std::ostream &out, const VkExtent3D* structInfo, Decoded_VkExtent3D* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* width */
    structBody << "\t" << structInfo->width << "," << std::endl;
/* height */
    structBody << "\t" << structInfo->height << "," << std::endl;
/* depth */
    structBody << "\t" << structInfo->depth << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "extent3D");
        out << "VkExtent3D " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkFenceCreateInfo(std::ostream &out, const VkFenceCreateInfo* structInfo, Decoded_VkFenceCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkFenceCreateFlags(" << structInfo->flags << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "fenceCreateInfo");
        out << "VkFenceCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkFormatProperties(std::ostream &out, const VkFormatProperties* structInfo, Decoded_VkFormatProperties* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* linearTilingFeatures */
    structBody << "\t" << "VkFormatFeatureFlags(" << structInfo->linearTilingFeatures << ")" << "," << std::endl;
/* optimalTilingFeatures */
    structBody << "\t" << "VkFormatFeatureFlags(" << structInfo->optimalTilingFeatures << ")" << "," << std::endl;
/* bufferFeatures */
    structBody << "\t" << "VkFormatFeatureFlags(" << structInfo->bufferFeatures << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "formatProperties");
        out << "VkFormatProperties " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkFramebufferCreateInfo(std::ostream &out, const VkFramebufferCreateInfo* structInfo, Decoded_VkFramebufferCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pAttachmentsArray = "NULL";
    if (metainfo->pAttachments.GetPointer() != NULL && structInfo->attachmentCount > 0) {
        pAttachmentsArray = "pAttachmentsArray_" + std::to_string(consumer.getNextId());
        std::string pAttachmentsValues = toStringJoin(metainfo->pAttachments.GetPointer(),
                                                      metainfo->pAttachments.GetPointer() + structInfo->attachmentCount,
                                                      [&](const format::HandleId current) { return consumer.GetHandle(current); },
                                                      ", ");
        if (structInfo->attachmentCount == 1) {
            pAttachmentsArray = "&" + pAttachmentsValues;
        } else if (structInfo->attachmentCount > 1) {
            out << "VkImageView " << pAttachmentsArray << "[] = {" << pAttachmentsValues << "};" << std::endl;
        }
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkFramebufferCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* renderPass */
    structBody << "\t" << consumer.GetHandle(metainfo->renderPass) << "," << std::endl;
/* attachmentCount */
    structBody << "\t" << structInfo->attachmentCount << "," << std::endl;
/* pAttachments */
    structBody << "\t" << pAttachmentsArray << "," << std::endl;
/* width */
    structBody << "\t" << structInfo->width << "," << std::endl;
/* height */
    structBody << "\t" << structInfo->height << "," << std::endl;
/* layers */
    structBody << "\t" << structInfo->layers << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "framebufferCreateInfo");
        out << "VkFramebufferCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkGraphicsPipelineCreateInfo(std::ostream &out, const VkGraphicsPipelineCreateInfo* structInfo, Decoded_VkGraphicsPipelineCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pDynamicStateStruct = "NULL";
    if (structInfo->pDynamicState != NULL) {
        pDynamicStateStruct = GenerateStruct_VkPipelineDynamicStateCreateInfo(out,
                                                             structInfo->pDynamicState,
                                                             metainfo->pDynamicState->GetMetaStructPointer(),
                                                             consumer);
        pDynamicStateStruct.insert(0, "&");
    }
    std::string pColorBlendStateStruct = "NULL";
    if (structInfo->pColorBlendState != NULL) {
        pColorBlendStateStruct = GenerateStruct_VkPipelineColorBlendStateCreateInfo(out,
                                                                structInfo->pColorBlendState,
                                                                metainfo->pColorBlendState->GetMetaStructPointer(),
                                                                consumer);
        pColorBlendStateStruct.insert(0, "&");
    }
    std::string pDepthStencilStateStruct = "NULL";
    if (structInfo->pDepthStencilState != NULL) {
        pDepthStencilStateStruct = GenerateStruct_VkPipelineDepthStencilStateCreateInfo(out,
                                                                  structInfo->pDepthStencilState,
                                                                  metainfo->pDepthStencilState->GetMetaStructPointer(),
                                                                  consumer);
        pDepthStencilStateStruct.insert(0, "&");
    }
    std::string pMultisampleStateStruct = "NULL";
    if (structInfo->pMultisampleState != NULL) {
        pMultisampleStateStruct = GenerateStruct_VkPipelineMultisampleStateCreateInfo(out,
                                                                 structInfo->pMultisampleState,
                                                                 metainfo->pMultisampleState->GetMetaStructPointer(),
                                                                 consumer);
        pMultisampleStateStruct.insert(0, "&");
    }
    std::string pRasterizationStateStruct = "NULL";
    if (structInfo->pRasterizationState != NULL) {
        pRasterizationStateStruct = GenerateStruct_VkPipelineRasterizationStateCreateInfo(out,
                                                                   structInfo->pRasterizationState,
                                                                   metainfo->pRasterizationState->GetMetaStructPointer(),
                                                                   consumer);
        pRasterizationStateStruct.insert(0, "&");
    }
    std::string pViewportStateStruct = "NULL";
    if (structInfo->pViewportState != NULL) {
        pViewportStateStruct = GenerateStruct_VkPipelineViewportStateCreateInfo(out,
                                                              structInfo->pViewportState,
                                                              metainfo->pViewportState->GetMetaStructPointer(),
                                                              consumer);
        pViewportStateStruct.insert(0, "&");
    }
    std::string pTessellationStateStruct = "NULL";
    if (structInfo->pTessellationState != NULL) {
        pTessellationStateStruct = GenerateStruct_VkPipelineTessellationStateCreateInfo(out,
                                                                  structInfo->pTessellationState,
                                                                  metainfo->pTessellationState->GetMetaStructPointer(),
                                                                  consumer);
        pTessellationStateStruct.insert(0, "&");
    }
    std::string pInputAssemblyStateStruct = "NULL";
    if (structInfo->pInputAssemblyState != NULL) {
        pInputAssemblyStateStruct = GenerateStruct_VkPipelineInputAssemblyStateCreateInfo(out,
                                                                   structInfo->pInputAssemblyState,
                                                                   metainfo->pInputAssemblyState->GetMetaStructPointer(),
                                                                   consumer);
        pInputAssemblyStateStruct.insert(0, "&");
    }
    std::string pVertexInputStateStruct = "NULL";
    if (structInfo->pVertexInputState != NULL) {
        pVertexInputStateStruct = GenerateStruct_VkPipelineVertexInputStateCreateInfo(out,
                                                                 structInfo->pVertexInputState,
                                                                 metainfo->pVertexInputState->GetMetaStructPointer(),
                                                                 consumer);
        pVertexInputStateStruct.insert(0, "&");
    }
    std::string pStagesArray = "NULL";
    if (structInfo->pStages != NULL) {
        pStagesArray = "pStages_" + std::to_string(consumer.getNextId());
        std::string pStagesNames;
        for (uint32_t idx = 0; idx < structInfo->stageCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pStages + idx != NULL) {
                varName = GenerateStruct_VkPipelineShaderStageCreateInfo(out,
                                                         structInfo->pStages + idx,
                                                         metainfo->pStages->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pStagesNames += varName + ", ";
        }
        out << "VkPipelineShaderStageCreateInfo " << pStagesArray << "[] = {" << pStagesNames << "};" << std::endl;
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkPipelineCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* stageCount */
    structBody << "\t" << structInfo->stageCount << "," << std::endl;
/* pStages */
    structBody << "\t" << pStagesArray << "," << std::endl;
/* pVertexInputState */
    structBody << "\t" << pVertexInputStateStruct << "," << std::endl;
/* pInputAssemblyState */
    structBody << "\t" << pInputAssemblyStateStruct << "," << std::endl;
/* pTessellationState */
    structBody << "\t" << pTessellationStateStruct << "," << std::endl;
/* pViewportState */
    structBody << "\t" << pViewportStateStruct << "," << std::endl;
/* pRasterizationState */
    structBody << "\t" << pRasterizationStateStruct << "," << std::endl;
/* pMultisampleState */
    structBody << "\t" << pMultisampleStateStruct << "," << std::endl;
/* pDepthStencilState */
    structBody << "\t" << pDepthStencilStateStruct << "," << std::endl;
/* pColorBlendState */
    structBody << "\t" << pColorBlendStateStruct << "," << std::endl;
/* pDynamicState */
    structBody << "\t" << pDynamicStateStruct << "," << std::endl;
/* layout */
    structBody << "\t" << consumer.GetHandle(metainfo->layout) << "," << std::endl;
/* renderPass */
    structBody << "\t" << consumer.GetHandle(metainfo->renderPass) << "," << std::endl;
/* subpass */
    structBody << "\t" << structInfo->subpass << "," << std::endl;
/* basePipelineHandle */
    structBody << "\t" << consumer.GetHandle(metainfo->basePipelineHandle) << "," << std::endl;
/* basePipelineIndex */
    structBody << "\t" << structInfo->basePipelineIndex << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "graphicsPipelineCreateInfo");
        out << "VkGraphicsPipelineCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkImageBlit(std::ostream &out, const VkImageBlit* structInfo, Decoded_VkImageBlit* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* srcSubresource */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->srcSubresource) << "," << std::endl;
/* srcOffsets */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->srcOffsets, 2) << "," << std::endl;
/* dstSubresource */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->dstSubresource) << "," << std::endl;
/* dstOffsets */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->dstOffsets, 2) << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "imageBlit");
        out << "VkImageBlit " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkImageCopy(std::ostream &out, const VkImageCopy* structInfo, Decoded_VkImageCopy* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* srcSubresource */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->srcSubresource) << "," << std::endl;
/* srcOffset */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->srcOffset) << "," << std::endl;
/* dstSubresource */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->dstSubresource) << "," << std::endl;
/* dstOffset */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->dstOffset) << "," << std::endl;
/* extent */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->extent) << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "imageCopy");
        out << "VkImageCopy " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkImageCreateInfo(std::ostream &out, const VkImageCreateInfo* structInfo, Decoded_VkImageCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pQueueFamilyIndicesArray = "NULL";
    if (structInfo->pQueueFamilyIndices != NULL) {
        pQueueFamilyIndicesArray = "pQueueFamilyIndices_" + std::to_string(consumer.getNextId());
        out << "uint32_t " << pQueueFamilyIndicesArray << "[] = " << VulkanCppConsumerBase::BuildValue(structInfo->pQueueFamilyIndices, structInfo->queueFamilyIndexCount) << ";" << std::endl;
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkImageCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* imageType */
    structBody << "\t" << "VkImageType(" << structInfo->imageType << ")" << "," << std::endl;
/* format */
    structBody << "\t" << "VkFormat(" << structInfo->format << ")" << "," << std::endl;
/* extent */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->extent) << "," << std::endl;
/* mipLevels */
    structBody << "\t" << structInfo->mipLevels << "," << std::endl;
/* arrayLayers */
    structBody << "\t" << structInfo->arrayLayers << "," << std::endl;
/* samples */
    structBody << "\t" << "VkSampleCountFlagBits(" << structInfo->samples << ")" << "," << std::endl;
/* tiling */
    structBody << "\t" << "VkImageTiling(" << structInfo->tiling << ")" << "," << std::endl;
/* usage */
    structBody << "\t" << "VkImageUsageFlags(" << structInfo->usage << ")" << "," << std::endl;
/* sharingMode */
    structBody << "\t" << "VkSharingMode(" << structInfo->sharingMode << ")" << "," << std::endl;
/* queueFamilyIndexCount */
    structBody << "\t" << structInfo->queueFamilyIndexCount << "," << std::endl;
/* pQueueFamilyIndices */
    structBody << "\t" << pQueueFamilyIndicesArray << "," << std::endl;
/* initialLayout */
    structBody << "\t" << "VkImageLayout(" << structInfo->initialLayout << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "imageCreateInfo");
        out << "VkImageCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkImageFormatProperties(std::ostream &out, const VkImageFormatProperties* structInfo, Decoded_VkImageFormatProperties* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* maxExtent */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->maxExtent) << "," << std::endl;
/* maxMipLevels */
    structBody << "\t" << structInfo->maxMipLevels << "," << std::endl;
/* maxArrayLayers */
    structBody << "\t" << structInfo->maxArrayLayers << "," << std::endl;
/* sampleCounts */
    structBody << "\t" << "VkSampleCountFlags(" << structInfo->sampleCounts << ")" << "," << std::endl;
/* maxResourceSize */
    structBody << "\t" << structInfo->maxResourceSize << "UL" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "imageFormatProperties");
        out << "VkImageFormatProperties " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkImageMemoryBarrier(std::ostream &out, const VkImageMemoryBarrier* structInfo, Decoded_VkImageMemoryBarrier* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* srcAccessMask */
    structBody << "\t" << "VkAccessFlags(" << structInfo->srcAccessMask << ")" << "," << std::endl;
/* dstAccessMask */
    structBody << "\t" << "VkAccessFlags(" << structInfo->dstAccessMask << ")" << "," << std::endl;
/* oldLayout */
    structBody << "\t" << "VkImageLayout(" << structInfo->oldLayout << ")" << "," << std::endl;
/* newLayout */
    structBody << "\t" << "VkImageLayout(" << structInfo->newLayout << ")" << "," << std::endl;
/* srcQueueFamilyIndex */
    structBody << "\t" << structInfo->srcQueueFamilyIndex << "," << std::endl;
/* dstQueueFamilyIndex */
    structBody << "\t" << structInfo->dstQueueFamilyIndex << "," << std::endl;
/* image */
    structBody << "\t" << consumer.GetHandle(metainfo->image) << "," << std::endl;
/* subresourceRange */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->subresourceRange) << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "imageMemoryBarrier");
        out << "VkImageMemoryBarrier " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkImageResolve(std::ostream &out, const VkImageResolve* structInfo, Decoded_VkImageResolve* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* srcSubresource */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->srcSubresource) << "," << std::endl;
/* srcOffset */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->srcOffset) << "," << std::endl;
/* dstSubresource */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->dstSubresource) << "," << std::endl;
/* dstOffset */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->dstOffset) << "," << std::endl;
/* extent */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->extent) << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "imageResolve");
        out << "VkImageResolve " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkImageSubresource(std::ostream &out, const VkImageSubresource* structInfo, Decoded_VkImageSubresource* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* aspectMask */
    structBody << "\t" << "VkImageAspectFlags(" << structInfo->aspectMask << ")" << "," << std::endl;
/* mipLevel */
    structBody << "\t" << structInfo->mipLevel << "," << std::endl;
/* arrayLayer */
    structBody << "\t" << structInfo->arrayLayer << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "imageSubresource");
        out << "VkImageSubresource " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkImageSubresourceLayers(std::ostream &out, const VkImageSubresourceLayers* structInfo, Decoded_VkImageSubresourceLayers* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* aspectMask */
    structBody << "\t" << "VkImageAspectFlags(" << structInfo->aspectMask << ")" << "," << std::endl;
/* mipLevel */
    structBody << "\t" << structInfo->mipLevel << "," << std::endl;
/* baseArrayLayer */
    structBody << "\t" << structInfo->baseArrayLayer << "," << std::endl;
/* layerCount */
    structBody << "\t" << structInfo->layerCount << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "imageSubresourceLayers");
        out << "VkImageSubresourceLayers " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkImageSubresourceRange(std::ostream &out, const VkImageSubresourceRange* structInfo, Decoded_VkImageSubresourceRange* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* aspectMask */
    structBody << "\t" << "VkImageAspectFlags(" << structInfo->aspectMask << ")" << "," << std::endl;
/* baseMipLevel */
    structBody << "\t" << structInfo->baseMipLevel << "," << std::endl;
/* levelCount */
    structBody << "\t" << structInfo->levelCount << "," << std::endl;
/* baseArrayLayer */
    structBody << "\t" << structInfo->baseArrayLayer << "," << std::endl;
/* layerCount */
    structBody << "\t" << structInfo->layerCount << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "imageSubresourceRange");
        out << "VkImageSubresourceRange " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkImageViewCreateInfo(std::ostream &out, const VkImageViewCreateInfo* structInfo, Decoded_VkImageViewCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkImageViewCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* image */
    structBody << "\t" << consumer.GetHandle(metainfo->image) << "," << std::endl;
/* viewType */
    structBody << "\t" << "VkImageViewType(" << structInfo->viewType << ")" << "," << std::endl;
/* format */
    structBody << "\t" << "VkFormat(" << structInfo->format << ")" << "," << std::endl;
/* components */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->components) << "," << std::endl;
/* subresourceRange */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->subresourceRange) << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "imageViewCreateInfo");
        out << "VkImageViewCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkLayerProperties(std::ostream &out, const VkLayerProperties* structInfo, Decoded_VkLayerProperties* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* layerName */
    structBody << "\t" << VulkanCppConsumerBase::toEscape(structInfo->layerName) << "," << std::endl;
/* specVersion */
    structBody << "\t" << structInfo->specVersion << "," << std::endl;
/* implementationVersion */
    structBody << "\t" << structInfo->implementationVersion << "," << std::endl;
/* description */
    structBody << "\t" << VulkanCppConsumerBase::toEscape(structInfo->description) << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "layerProperties");
        out << "VkLayerProperties " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkMappedMemoryRange(std::ostream &out, const VkMappedMemoryRange* structInfo, Decoded_VkMappedMemoryRange* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* memory */
    structBody << "\t" << consumer.GetHandle(metainfo->memory) << "," << std::endl;
/* offset */
    structBody << "\t" << structInfo->offset << "UL" << "," << std::endl;
/* size */
    structBody << "\t" << structInfo->size << "UL" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "mappedMemoryRange");
        out << "VkMappedMemoryRange " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkMemoryBarrier(std::ostream &out, const VkMemoryBarrier* structInfo, Decoded_VkMemoryBarrier* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* srcAccessMask */
    structBody << "\t" << "VkAccessFlags(" << structInfo->srcAccessMask << ")" << "," << std::endl;
/* dstAccessMask */
    structBody << "\t" << "VkAccessFlags(" << structInfo->dstAccessMask << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "memoryBarrier");
        out << "VkMemoryBarrier " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkMemoryHeap(std::ostream &out, const VkMemoryHeap* structInfo, Decoded_VkMemoryHeap* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* size */
    structBody << "\t" << structInfo->size << "UL" << "," << std::endl;
/* flags */
    structBody << "\t" << "VkMemoryHeapFlags(" << structInfo->flags << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "memoryHeap");
        out << "VkMemoryHeap " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkMemoryRequirements(std::ostream &out, const VkMemoryRequirements* structInfo, Decoded_VkMemoryRequirements* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* size */
    structBody << "\t" << structInfo->size << "UL" << "," << std::endl;
/* alignment */
    structBody << "\t" << structInfo->alignment << "UL" << "," << std::endl;
/* memoryTypeBits */
    structBody << "\t" << structInfo->memoryTypeBits << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "memoryRequirements");
        out << "VkMemoryRequirements " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkMemoryType(std::ostream &out, const VkMemoryType* structInfo, Decoded_VkMemoryType* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* propertyFlags */
    structBody << "\t" << "VkMemoryPropertyFlags(" << structInfo->propertyFlags << ")" << "," << std::endl;
/* heapIndex */
    structBody << "\t" << structInfo->heapIndex << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "memoryType");
        out << "VkMemoryType " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkOffset2D(std::ostream &out, const VkOffset2D* structInfo, Decoded_VkOffset2D* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* x */
    structBody << "\t" << structInfo->x << "," << std::endl;
/* y */
    structBody << "\t" << structInfo->y << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "offset2D");
        out << "VkOffset2D " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkOffset3D(std::ostream &out, const VkOffset3D* structInfo, Decoded_VkOffset3D* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* x */
    structBody << "\t" << structInfo->x << "," << std::endl;
/* y */
    structBody << "\t" << structInfo->y << "," << std::endl;
/* z */
    structBody << "\t" << structInfo->z << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "offset3D");
        out << "VkOffset3D " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPhysicalDeviceFeatures(std::ostream &out, const VkPhysicalDeviceFeatures* structInfo, Decoded_VkPhysicalDeviceFeatures* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* robustBufferAccess */
    structBody << "\t" << structInfo->robustBufferAccess << "," << std::endl;
/* fullDrawIndexUint32 */
    structBody << "\t" << structInfo->fullDrawIndexUint32 << "," << std::endl;
/* imageCubeArray */
    structBody << "\t" << structInfo->imageCubeArray << "," << std::endl;
/* independentBlend */
    structBody << "\t" << structInfo->independentBlend << "," << std::endl;
/* geometryShader */
    structBody << "\t" << structInfo->geometryShader << "," << std::endl;
/* tessellationShader */
    structBody << "\t" << structInfo->tessellationShader << "," << std::endl;
/* sampleRateShading */
    structBody << "\t" << structInfo->sampleRateShading << "," << std::endl;
/* dualSrcBlend */
    structBody << "\t" << structInfo->dualSrcBlend << "," << std::endl;
/* logicOp */
    structBody << "\t" << structInfo->logicOp << "," << std::endl;
/* multiDrawIndirect */
    structBody << "\t" << structInfo->multiDrawIndirect << "," << std::endl;
/* drawIndirectFirstInstance */
    structBody << "\t" << structInfo->drawIndirectFirstInstance << "," << std::endl;
/* depthClamp */
    structBody << "\t" << structInfo->depthClamp << "," << std::endl;
/* depthBiasClamp */
    structBody << "\t" << structInfo->depthBiasClamp << "," << std::endl;
/* fillModeNonSolid */
    structBody << "\t" << structInfo->fillModeNonSolid << "," << std::endl;
/* depthBounds */
    structBody << "\t" << structInfo->depthBounds << "," << std::endl;
/* wideLines */
    structBody << "\t" << structInfo->wideLines << "," << std::endl;
/* largePoints */
    structBody << "\t" << structInfo->largePoints << "," << std::endl;
/* alphaToOne */
    structBody << "\t" << structInfo->alphaToOne << "," << std::endl;
/* multiViewport */
    structBody << "\t" << structInfo->multiViewport << "," << std::endl;
/* samplerAnisotropy */
    structBody << "\t" << structInfo->samplerAnisotropy << "," << std::endl;
/* textureCompressionETC2 */
    structBody << "\t" << structInfo->textureCompressionETC2 << "," << std::endl;
/* textureCompressionASTC_LDR */
    structBody << "\t" << structInfo->textureCompressionASTC_LDR << "," << std::endl;
/* textureCompressionBC */
    structBody << "\t" << structInfo->textureCompressionBC << "," << std::endl;
/* occlusionQueryPrecise */
    structBody << "\t" << structInfo->occlusionQueryPrecise << "," << std::endl;
/* pipelineStatisticsQuery */
    structBody << "\t" << structInfo->pipelineStatisticsQuery << "," << std::endl;
/* vertexPipelineStoresAndAtomics */
    structBody << "\t" << structInfo->vertexPipelineStoresAndAtomics << "," << std::endl;
/* fragmentStoresAndAtomics */
    structBody << "\t" << structInfo->fragmentStoresAndAtomics << "," << std::endl;
/* shaderTessellationAndGeometryPointSize */
    structBody << "\t" << structInfo->shaderTessellationAndGeometryPointSize << "," << std::endl;
/* shaderImageGatherExtended */
    structBody << "\t" << structInfo->shaderImageGatherExtended << "," << std::endl;
/* shaderStorageImageExtendedFormats */
    structBody << "\t" << structInfo->shaderStorageImageExtendedFormats << "," << std::endl;
/* shaderStorageImageMultisample */
    structBody << "\t" << structInfo->shaderStorageImageMultisample << "," << std::endl;
/* shaderStorageImageReadWithoutFormat */
    structBody << "\t" << structInfo->shaderStorageImageReadWithoutFormat << "," << std::endl;
/* shaderStorageImageWriteWithoutFormat */
    structBody << "\t" << structInfo->shaderStorageImageWriteWithoutFormat << "," << std::endl;
/* shaderUniformBufferArrayDynamicIndexing */
    structBody << "\t" << structInfo->shaderUniformBufferArrayDynamicIndexing << "," << std::endl;
/* shaderSampledImageArrayDynamicIndexing */
    structBody << "\t" << structInfo->shaderSampledImageArrayDynamicIndexing << "," << std::endl;
/* shaderStorageBufferArrayDynamicIndexing */
    structBody << "\t" << structInfo->shaderStorageBufferArrayDynamicIndexing << "," << std::endl;
/* shaderStorageImageArrayDynamicIndexing */
    structBody << "\t" << structInfo->shaderStorageImageArrayDynamicIndexing << "," << std::endl;
/* shaderClipDistance */
    structBody << "\t" << structInfo->shaderClipDistance << "," << std::endl;
/* shaderCullDistance */
    structBody << "\t" << structInfo->shaderCullDistance << "," << std::endl;
/* shaderFloat64 */
    structBody << "\t" << structInfo->shaderFloat64 << "," << std::endl;
/* shaderInt64 */
    structBody << "\t" << structInfo->shaderInt64 << "," << std::endl;
/* shaderInt16 */
    structBody << "\t" << structInfo->shaderInt16 << "," << std::endl;
/* shaderResourceResidency */
    structBody << "\t" << structInfo->shaderResourceResidency << "," << std::endl;
/* shaderResourceMinLod */
    structBody << "\t" << structInfo->shaderResourceMinLod << "," << std::endl;
/* sparseBinding */
    structBody << "\t" << structInfo->sparseBinding << "," << std::endl;
/* sparseResidencyBuffer */
    structBody << "\t" << structInfo->sparseResidencyBuffer << "," << std::endl;
/* sparseResidencyImage2D */
    structBody << "\t" << structInfo->sparseResidencyImage2D << "," << std::endl;
/* sparseResidencyImage3D */
    structBody << "\t" << structInfo->sparseResidencyImage3D << "," << std::endl;
/* sparseResidency2Samples */
    structBody << "\t" << structInfo->sparseResidency2Samples << "," << std::endl;
/* sparseResidency4Samples */
    structBody << "\t" << structInfo->sparseResidency4Samples << "," << std::endl;
/* sparseResidency8Samples */
    structBody << "\t" << structInfo->sparseResidency8Samples << "," << std::endl;
/* sparseResidency16Samples */
    structBody << "\t" << structInfo->sparseResidency16Samples << "," << std::endl;
/* sparseResidencyAliased */
    structBody << "\t" << structInfo->sparseResidencyAliased << "," << std::endl;
/* variableMultisampleRate */
    structBody << "\t" << structInfo->variableMultisampleRate << "," << std::endl;
/* inheritedQueries */
    structBody << "\t" << structInfo->inheritedQueries << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "physicalDeviceFeatures");
        out << "VkPhysicalDeviceFeatures " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPhysicalDeviceLimits(std::ostream &out, const VkPhysicalDeviceLimits* structInfo, Decoded_VkPhysicalDeviceLimits* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* maxImageDimension1D */
    structBody << "\t" << structInfo->maxImageDimension1D << "," << std::endl;
/* maxImageDimension2D */
    structBody << "\t" << structInfo->maxImageDimension2D << "," << std::endl;
/* maxImageDimension3D */
    structBody << "\t" << structInfo->maxImageDimension3D << "," << std::endl;
/* maxImageDimensionCube */
    structBody << "\t" << structInfo->maxImageDimensionCube << "," << std::endl;
/* maxImageArrayLayers */
    structBody << "\t" << structInfo->maxImageArrayLayers << "," << std::endl;
/* maxTexelBufferElements */
    structBody << "\t" << structInfo->maxTexelBufferElements << "," << std::endl;
/* maxUniformBufferRange */
    structBody << "\t" << structInfo->maxUniformBufferRange << "," << std::endl;
/* maxStorageBufferRange */
    structBody << "\t" << structInfo->maxStorageBufferRange << "," << std::endl;
/* maxPushConstantsSize */
    structBody << "\t" << structInfo->maxPushConstantsSize << "," << std::endl;
/* maxMemoryAllocationCount */
    structBody << "\t" << structInfo->maxMemoryAllocationCount << "," << std::endl;
/* maxSamplerAllocationCount */
    structBody << "\t" << structInfo->maxSamplerAllocationCount << "," << std::endl;
/* bufferImageGranularity */
    structBody << "\t" << structInfo->bufferImageGranularity << "UL" << "," << std::endl;
/* sparseAddressSpaceSize */
    structBody << "\t" << structInfo->sparseAddressSpaceSize << "UL" << "," << std::endl;
/* maxBoundDescriptorSets */
    structBody << "\t" << structInfo->maxBoundDescriptorSets << "," << std::endl;
/* maxPerStageDescriptorSamplers */
    structBody << "\t" << structInfo->maxPerStageDescriptorSamplers << "," << std::endl;
/* maxPerStageDescriptorUniformBuffers */
    structBody << "\t" << structInfo->maxPerStageDescriptorUniformBuffers << "," << std::endl;
/* maxPerStageDescriptorStorageBuffers */
    structBody << "\t" << structInfo->maxPerStageDescriptorStorageBuffers << "," << std::endl;
/* maxPerStageDescriptorSampledImages */
    structBody << "\t" << structInfo->maxPerStageDescriptorSampledImages << "," << std::endl;
/* maxPerStageDescriptorStorageImages */
    structBody << "\t" << structInfo->maxPerStageDescriptorStorageImages << "," << std::endl;
/* maxPerStageDescriptorInputAttachments */
    structBody << "\t" << structInfo->maxPerStageDescriptorInputAttachments << "," << std::endl;
/* maxPerStageResources */
    structBody << "\t" << structInfo->maxPerStageResources << "," << std::endl;
/* maxDescriptorSetSamplers */
    structBody << "\t" << structInfo->maxDescriptorSetSamplers << "," << std::endl;
/* maxDescriptorSetUniformBuffers */
    structBody << "\t" << structInfo->maxDescriptorSetUniformBuffers << "," << std::endl;
/* maxDescriptorSetUniformBuffersDynamic */
    structBody << "\t" << structInfo->maxDescriptorSetUniformBuffersDynamic << "," << std::endl;
/* maxDescriptorSetStorageBuffers */
    structBody << "\t" << structInfo->maxDescriptorSetStorageBuffers << "," << std::endl;
/* maxDescriptorSetStorageBuffersDynamic */
    structBody << "\t" << structInfo->maxDescriptorSetStorageBuffersDynamic << "," << std::endl;
/* maxDescriptorSetSampledImages */
    structBody << "\t" << structInfo->maxDescriptorSetSampledImages << "," << std::endl;
/* maxDescriptorSetStorageImages */
    structBody << "\t" << structInfo->maxDescriptorSetStorageImages << "," << std::endl;
/* maxDescriptorSetInputAttachments */
    structBody << "\t" << structInfo->maxDescriptorSetInputAttachments << "," << std::endl;
/* maxVertexInputAttributes */
    structBody << "\t" << structInfo->maxVertexInputAttributes << "," << std::endl;
/* maxVertexInputBindings */
    structBody << "\t" << structInfo->maxVertexInputBindings << "," << std::endl;
/* maxVertexInputAttributeOffset */
    structBody << "\t" << structInfo->maxVertexInputAttributeOffset << "," << std::endl;
/* maxVertexInputBindingStride */
    structBody << "\t" << structInfo->maxVertexInputBindingStride << "," << std::endl;
/* maxVertexOutputComponents */
    structBody << "\t" << structInfo->maxVertexOutputComponents << "," << std::endl;
/* maxTessellationGenerationLevel */
    structBody << "\t" << structInfo->maxTessellationGenerationLevel << "," << std::endl;
/* maxTessellationPatchSize */
    structBody << "\t" << structInfo->maxTessellationPatchSize << "," << std::endl;
/* maxTessellationControlPerVertexInputComponents */
    structBody << "\t" << structInfo->maxTessellationControlPerVertexInputComponents << "," << std::endl;
/* maxTessellationControlPerVertexOutputComponents */
    structBody << "\t" << structInfo->maxTessellationControlPerVertexOutputComponents << "," << std::endl;
/* maxTessellationControlPerPatchOutputComponents */
    structBody << "\t" << structInfo->maxTessellationControlPerPatchOutputComponents << "," << std::endl;
/* maxTessellationControlTotalOutputComponents */
    structBody << "\t" << structInfo->maxTessellationControlTotalOutputComponents << "," << std::endl;
/* maxTessellationEvaluationInputComponents */
    structBody << "\t" << structInfo->maxTessellationEvaluationInputComponents << "," << std::endl;
/* maxTessellationEvaluationOutputComponents */
    structBody << "\t" << structInfo->maxTessellationEvaluationOutputComponents << "," << std::endl;
/* maxGeometryShaderInvocations */
    structBody << "\t" << structInfo->maxGeometryShaderInvocations << "," << std::endl;
/* maxGeometryInputComponents */
    structBody << "\t" << structInfo->maxGeometryInputComponents << "," << std::endl;
/* maxGeometryOutputComponents */
    structBody << "\t" << structInfo->maxGeometryOutputComponents << "," << std::endl;
/* maxGeometryOutputVertices */
    structBody << "\t" << structInfo->maxGeometryOutputVertices << "," << std::endl;
/* maxGeometryTotalOutputComponents */
    structBody << "\t" << structInfo->maxGeometryTotalOutputComponents << "," << std::endl;
/* maxFragmentInputComponents */
    structBody << "\t" << structInfo->maxFragmentInputComponents << "," << std::endl;
/* maxFragmentOutputAttachments */
    structBody << "\t" << structInfo->maxFragmentOutputAttachments << "," << std::endl;
/* maxFragmentDualSrcAttachments */
    structBody << "\t" << structInfo->maxFragmentDualSrcAttachments << "," << std::endl;
/* maxFragmentCombinedOutputResources */
    structBody << "\t" << structInfo->maxFragmentCombinedOutputResources << "," << std::endl;
/* maxComputeSharedMemorySize */
    structBody << "\t" << structInfo->maxComputeSharedMemorySize << "," << std::endl;
/* maxComputeWorkGroupCount */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->maxComputeWorkGroupCount, 3) << "," << std::endl;
/* maxComputeWorkGroupInvocations */
    structBody << "\t" << structInfo->maxComputeWorkGroupInvocations << "," << std::endl;
/* maxComputeWorkGroupSize */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->maxComputeWorkGroupSize, 3) << "," << std::endl;
/* subPixelPrecisionBits */
    structBody << "\t" << structInfo->subPixelPrecisionBits << "," << std::endl;
/* subTexelPrecisionBits */
    structBody << "\t" << structInfo->subTexelPrecisionBits << "," << std::endl;
/* mipmapPrecisionBits */
    structBody << "\t" << structInfo->mipmapPrecisionBits << "," << std::endl;
/* maxDrawIndexedIndexValue */
    structBody << "\t" << structInfo->maxDrawIndexedIndexValue << "," << std::endl;
/* maxDrawIndirectCount */
    structBody << "\t" << structInfo->maxDrawIndirectCount << "," << std::endl;
/* maxSamplerLodBias */
    structBody << "\t" << structInfo->maxSamplerLodBias << "," << std::endl;
/* maxSamplerAnisotropy */
    structBody << "\t" << structInfo->maxSamplerAnisotropy << "," << std::endl;
/* maxViewports */
    structBody << "\t" << structInfo->maxViewports << "," << std::endl;
/* maxViewportDimensions */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->maxViewportDimensions, 2) << "," << std::endl;
/* viewportBoundsRange */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->viewportBoundsRange, 2) << "," << std::endl;
/* viewportSubPixelBits */
    structBody << "\t" << structInfo->viewportSubPixelBits << "," << std::endl;
/* minMemoryMapAlignment */
    structBody << "\t" << structInfo->minMemoryMapAlignment << "," << std::endl;
/* minTexelBufferOffsetAlignment */
    structBody << "\t" << structInfo->minTexelBufferOffsetAlignment << "UL" << "," << std::endl;
/* minUniformBufferOffsetAlignment */
    structBody << "\t" << structInfo->minUniformBufferOffsetAlignment << "UL" << "," << std::endl;
/* minStorageBufferOffsetAlignment */
    structBody << "\t" << structInfo->minStorageBufferOffsetAlignment << "UL" << "," << std::endl;
/* minTexelOffset */
    structBody << "\t" << structInfo->minTexelOffset << "," << std::endl;
/* maxTexelOffset */
    structBody << "\t" << structInfo->maxTexelOffset << "," << std::endl;
/* minTexelGatherOffset */
    structBody << "\t" << structInfo->minTexelGatherOffset << "," << std::endl;
/* maxTexelGatherOffset */
    structBody << "\t" << structInfo->maxTexelGatherOffset << "," << std::endl;
/* minInterpolationOffset */
    structBody << "\t" << structInfo->minInterpolationOffset << "," << std::endl;
/* maxInterpolationOffset */
    structBody << "\t" << structInfo->maxInterpolationOffset << "," << std::endl;
/* subPixelInterpolationOffsetBits */
    structBody << "\t" << structInfo->subPixelInterpolationOffsetBits << "," << std::endl;
/* maxFramebufferWidth */
    structBody << "\t" << structInfo->maxFramebufferWidth << "," << std::endl;
/* maxFramebufferHeight */
    structBody << "\t" << structInfo->maxFramebufferHeight << "," << std::endl;
/* maxFramebufferLayers */
    structBody << "\t" << structInfo->maxFramebufferLayers << "," << std::endl;
/* framebufferColorSampleCounts */
    structBody << "\t" << "VkSampleCountFlags(" << structInfo->framebufferColorSampleCounts << ")" << "," << std::endl;
/* framebufferDepthSampleCounts */
    structBody << "\t" << "VkSampleCountFlags(" << structInfo->framebufferDepthSampleCounts << ")" << "," << std::endl;
/* framebufferStencilSampleCounts */
    structBody << "\t" << "VkSampleCountFlags(" << structInfo->framebufferStencilSampleCounts << ")" << "," << std::endl;
/* framebufferNoAttachmentsSampleCounts */
    structBody << "\t" << "VkSampleCountFlags(" << structInfo->framebufferNoAttachmentsSampleCounts << ")" << "," << std::endl;
/* maxColorAttachments */
    structBody << "\t" << structInfo->maxColorAttachments << "," << std::endl;
/* sampledImageColorSampleCounts */
    structBody << "\t" << "VkSampleCountFlags(" << structInfo->sampledImageColorSampleCounts << ")" << "," << std::endl;
/* sampledImageIntegerSampleCounts */
    structBody << "\t" << "VkSampleCountFlags(" << structInfo->sampledImageIntegerSampleCounts << ")" << "," << std::endl;
/* sampledImageDepthSampleCounts */
    structBody << "\t" << "VkSampleCountFlags(" << structInfo->sampledImageDepthSampleCounts << ")" << "," << std::endl;
/* sampledImageStencilSampleCounts */
    structBody << "\t" << "VkSampleCountFlags(" << structInfo->sampledImageStencilSampleCounts << ")" << "," << std::endl;
/* storageImageSampleCounts */
    structBody << "\t" << "VkSampleCountFlags(" << structInfo->storageImageSampleCounts << ")" << "," << std::endl;
/* maxSampleMaskWords */
    structBody << "\t" << structInfo->maxSampleMaskWords << "," << std::endl;
/* timestampComputeAndGraphics */
    structBody << "\t" << structInfo->timestampComputeAndGraphics << "," << std::endl;
/* timestampPeriod */
    structBody << "\t" << structInfo->timestampPeriod << "," << std::endl;
/* maxClipDistances */
    structBody << "\t" << structInfo->maxClipDistances << "," << std::endl;
/* maxCullDistances */
    structBody << "\t" << structInfo->maxCullDistances << "," << std::endl;
/* maxCombinedClipAndCullDistances */
    structBody << "\t" << structInfo->maxCombinedClipAndCullDistances << "," << std::endl;
/* discreteQueuePriorities */
    structBody << "\t" << structInfo->discreteQueuePriorities << "," << std::endl;
/* pointSizeRange */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->pointSizeRange, 2) << "," << std::endl;
/* lineWidthRange */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->lineWidthRange, 2) << "," << std::endl;
/* pointSizeGranularity */
    structBody << "\t" << structInfo->pointSizeGranularity << "," << std::endl;
/* lineWidthGranularity */
    structBody << "\t" << structInfo->lineWidthGranularity << "," << std::endl;
/* strictLines */
    structBody << "\t" << structInfo->strictLines << "," << std::endl;
/* standardSampleLocations */
    structBody << "\t" << structInfo->standardSampleLocations << "," << std::endl;
/* optimalBufferCopyOffsetAlignment */
    structBody << "\t" << structInfo->optimalBufferCopyOffsetAlignment << "UL" << "," << std::endl;
/* optimalBufferCopyRowPitchAlignment */
    structBody << "\t" << structInfo->optimalBufferCopyRowPitchAlignment << "UL" << "," << std::endl;
/* nonCoherentAtomSize */
    structBody << "\t" << structInfo->nonCoherentAtomSize << "UL" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "physicalDeviceLimits");
        out << "VkPhysicalDeviceLimits " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPhysicalDeviceMemoryProperties(std::ostream &out, const VkPhysicalDeviceMemoryProperties* structInfo, Decoded_VkPhysicalDeviceMemoryProperties* metainfo, VulkanCppConsumerBase &consumer){
    std::string memoryHeapsArray = "memoryHeaps_" + std::to_string(consumer.getNextId());
    std::string memoryHeapsNames;
    for (uint32_t idx = 0; idx < structInfo->memoryHeapCount; idx++) {
        std::string varName = "NULL";
        if (structInfo->memoryHeaps + idx != NULL) {
            varName = GenerateStruct_VkMemoryHeap(out,
                                                     structInfo->memoryHeaps + idx,
                                                     metainfo->memoryHeaps->GetMetaStructPointer() + idx,
                                                     consumer);
        }
        memoryHeapsNames += varName + ", ";
    }
    out << "VkMemoryHeap " << memoryHeapsArray << "[] = {" << memoryHeapsNames << "};" << std::endl;
    std::string memoryTypesArray = "memoryTypes_" + std::to_string(consumer.getNextId());
    std::string memoryTypesNames;
    for (uint32_t idx = 0; idx < structInfo->memoryTypeCount; idx++) {
        std::string varName = "NULL";
        if (structInfo->memoryTypes + idx != NULL) {
            varName = GenerateStruct_VkMemoryType(out,
                                                     structInfo->memoryTypes + idx,
                                                     metainfo->memoryTypes->GetMetaStructPointer() + idx,
                                                     consumer);
        }
        memoryTypesNames += varName + ", ";
    }
    out << "VkMemoryType " << memoryTypesArray << "[] = {" << memoryTypesNames << "};" << std::endl;
    std::stringstream structBody;
/* memoryTypeCount */
    structBody << "\t" << structInfo->memoryTypeCount << "," << std::endl;
/* memoryTypes */
    structBody << "\t" << memoryTypesArray << "," << std::endl;
/* memoryHeapCount */
    structBody << "\t" << structInfo->memoryHeapCount << "," << std::endl;
/* memoryHeaps */
    structBody << "\t" << memoryHeapsArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "physicalDeviceMemoryProperties");
        out << "VkPhysicalDeviceMemoryProperties " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPhysicalDeviceProperties(std::ostream &out, const VkPhysicalDeviceProperties* structInfo, Decoded_VkPhysicalDeviceProperties* metainfo, VulkanCppConsumerBase &consumer){
    std::string sparsePropertiesInfoVar = GenerateStruct_VkPhysicalDeviceSparseProperties(out,
                                                                         &structInfo->sparseProperties,
                                                                         metainfo->sparseProperties,
                                                                         consumer);
    std::string limitsInfoVar = GenerateStruct_VkPhysicalDeviceLimits(out,
                                                               &structInfo->limits,
                                                               metainfo->limits,
                                                               consumer);
    std::stringstream structBody;
/* apiVersion */
    structBody << "\t" << structInfo->apiVersion << "," << std::endl;
/* driverVersion */
    structBody << "\t" << structInfo->driverVersion << "," << std::endl;
/* vendorID */
    structBody << "\t" << structInfo->vendorID << "," << std::endl;
/* deviceID */
    structBody << "\t" << structInfo->deviceID << "," << std::endl;
/* deviceType */
    structBody << "\t" << "VkPhysicalDeviceType(" << structInfo->deviceType << ")" << "," << std::endl;
/* deviceName */
    structBody << "\t" << VulkanCppConsumerBase::toEscape(structInfo->deviceName) << "," << std::endl;
/* pipelineCacheUUID */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->pipelineCacheUUID, VK_UUID_SIZE) << "," << std::endl;
/* limits */
    structBody << "\t" << limitsInfoVar << "," << std::endl;
/* sparseProperties */
    structBody << "\t" << sparsePropertiesInfoVar << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "physicalDeviceProperties");
        out << "VkPhysicalDeviceProperties " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPhysicalDeviceSparseProperties(std::ostream &out, const VkPhysicalDeviceSparseProperties* structInfo, Decoded_VkPhysicalDeviceSparseProperties* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* residencyStandard2DBlockShape */
    structBody << "\t" << structInfo->residencyStandard2DBlockShape << "," << std::endl;
/* residencyStandard2DMultisampleBlockShape */
    structBody << "\t" << structInfo->residencyStandard2DMultisampleBlockShape << "," << std::endl;
/* residencyStandard3DBlockShape */
    structBody << "\t" << structInfo->residencyStandard3DBlockShape << "," << std::endl;
/* residencyAlignedMipSize */
    structBody << "\t" << structInfo->residencyAlignedMipSize << "," << std::endl;
/* residencyNonResidentStrict */
    structBody << "\t" << structInfo->residencyNonResidentStrict << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "physicalDeviceSparseProperties");
        out << "VkPhysicalDeviceSparseProperties " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPipelineCacheHeaderVersionOne(std::ostream &out, const VkPipelineCacheHeaderVersionOne* structInfo, Decoded_VkPipelineCacheHeaderVersionOne* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* headerSize */
    structBody << "\t" << structInfo->headerSize << "," << std::endl;
/* headerVersion */
    structBody << "\t" << "VkPipelineCacheHeaderVersion(" << structInfo->headerVersion << ")" << "," << std::endl;
/* vendorID */
    structBody << "\t" << structInfo->vendorID << "," << std::endl;
/* deviceID */
    structBody << "\t" << structInfo->deviceID << "," << std::endl;
/* pipelineCacheUUID */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->pipelineCacheUUID, VK_UUID_SIZE) << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "pipelineCacheHeaderVersionOne");
        out << "VkPipelineCacheHeaderVersionOne " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPipelineColorBlendAttachmentState(std::ostream &out, const VkPipelineColorBlendAttachmentState* structInfo, Decoded_VkPipelineColorBlendAttachmentState* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* blendEnable */
    structBody << "\t" << structInfo->blendEnable << "," << std::endl;
/* srcColorBlendFactor */
    structBody << "\t" << "VkBlendFactor(" << structInfo->srcColorBlendFactor << ")" << "," << std::endl;
/* dstColorBlendFactor */
    structBody << "\t" << "VkBlendFactor(" << structInfo->dstColorBlendFactor << ")" << "," << std::endl;
/* colorBlendOp */
    structBody << "\t" << "VkBlendOp(" << structInfo->colorBlendOp << ")" << "," << std::endl;
/* srcAlphaBlendFactor */
    structBody << "\t" << "VkBlendFactor(" << structInfo->srcAlphaBlendFactor << ")" << "," << std::endl;
/* dstAlphaBlendFactor */
    structBody << "\t" << "VkBlendFactor(" << structInfo->dstAlphaBlendFactor << ")" << "," << std::endl;
/* alphaBlendOp */
    structBody << "\t" << "VkBlendOp(" << structInfo->alphaBlendOp << ")" << "," << std::endl;
/* colorWriteMask */
    structBody << "\t" << "VkColorComponentFlags(" << structInfo->colorWriteMask << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "pipelineColorBlendAttachmentState");
        out << "VkPipelineColorBlendAttachmentState " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPipelineColorBlendStateCreateInfo(std::ostream &out, const VkPipelineColorBlendStateCreateInfo* structInfo, Decoded_VkPipelineColorBlendStateCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pAttachmentsArray = "NULL";
    if (structInfo->pAttachments != NULL) {
        pAttachmentsArray = "pAttachments_" + std::to_string(consumer.getNextId());
        std::string pAttachmentsNames;
        for (uint32_t idx = 0; idx < structInfo->attachmentCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pAttachments + idx != NULL) {
                varName = GenerateStruct_VkPipelineColorBlendAttachmentState(out,
                                                         structInfo->pAttachments + idx,
                                                         metainfo->pAttachments->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pAttachmentsNames += varName + ", ";
        }
        out << "VkPipelineColorBlendAttachmentState " << pAttachmentsArray << "[] = {" << pAttachmentsNames << "};" << std::endl;
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkPipelineColorBlendStateCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* logicOpEnable */
    structBody << "\t" << structInfo->logicOpEnable << "," << std::endl;
/* logicOp */
    structBody << "\t" << "VkLogicOp(" << structInfo->logicOp << ")" << "," << std::endl;
/* attachmentCount */
    structBody << "\t" << structInfo->attachmentCount << "," << std::endl;
/* pAttachments */
    structBody << "\t" << pAttachmentsArray << "," << std::endl;
/* blendConstants */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->blendConstants, 4) << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "pipelineColorBlendStateCreateInfo");
        out << "VkPipelineColorBlendStateCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPipelineDepthStencilStateCreateInfo(std::ostream &out, const VkPipelineDepthStencilStateCreateInfo* structInfo, Decoded_VkPipelineDepthStencilStateCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkPipelineDepthStencilStateCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* depthTestEnable */
    structBody << "\t" << structInfo->depthTestEnable << "," << std::endl;
/* depthWriteEnable */
    structBody << "\t" << structInfo->depthWriteEnable << "," << std::endl;
/* depthCompareOp */
    structBody << "\t" << "VkCompareOp(" << structInfo->depthCompareOp << ")" << "," << std::endl;
/* depthBoundsTestEnable */
    structBody << "\t" << structInfo->depthBoundsTestEnable << "," << std::endl;
/* stencilTestEnable */
    structBody << "\t" << structInfo->stencilTestEnable << "," << std::endl;
/* front */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->front) << "," << std::endl;
/* back */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->back) << "," << std::endl;
/* minDepthBounds */
    structBody << "\t" << structInfo->minDepthBounds << "," << std::endl;
/* maxDepthBounds */
    structBody << "\t" << structInfo->maxDepthBounds << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "pipelineDepthStencilStateCreateInfo");
        out << "VkPipelineDepthStencilStateCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPipelineDynamicStateCreateInfo(std::ostream &out, const VkPipelineDynamicStateCreateInfo* structInfo, Decoded_VkPipelineDynamicStateCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pDynamicStatesValues;
    std::string pDynamicStatesArray = "NULL";
    if (structInfo->pDynamicStates != NULL) {
        for (uint32_t idx = 0; idx < structInfo->dynamicStateCount; idx++) {
            pDynamicStatesValues += util::ToString<VkDynamicState>(structInfo->pDynamicStates[idx]) + ", ";
        }
        pDynamicStatesArray = "pDynamicStates_" + std::to_string(consumer.getNextId());
        out << "VkDynamicState " << pDynamicStatesArray << "[] = {" << pDynamicStatesValues << "};" << std::endl;
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkPipelineDynamicStateCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* dynamicStateCount */
    structBody << "\t" << structInfo->dynamicStateCount << "," << std::endl;
/* pDynamicStates */
    structBody << "\t" << pDynamicStatesArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "pipelineDynamicStateCreateInfo");
        out << "VkPipelineDynamicStateCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPipelineInputAssemblyStateCreateInfo(std::ostream &out, const VkPipelineInputAssemblyStateCreateInfo* structInfo, Decoded_VkPipelineInputAssemblyStateCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkPipelineInputAssemblyStateCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* topology */
    structBody << "\t" << "VkPrimitiveTopology(" << structInfo->topology << ")" << "," << std::endl;
/* primitiveRestartEnable */
    structBody << "\t" << structInfo->primitiveRestartEnable << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "pipelineInputAssemblyStateCreateInfo");
        out << "VkPipelineInputAssemblyStateCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPipelineLayoutCreateInfo(std::ostream &out, const VkPipelineLayoutCreateInfo* structInfo, Decoded_VkPipelineLayoutCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pPushConstantRangesArray = "NULL";
    if (structInfo->pPushConstantRanges != NULL) {
        pPushConstantRangesArray = "pPushConstantRanges_" + std::to_string(consumer.getNextId());
        std::string pPushConstantRangesNames;
        for (uint32_t idx = 0; idx < structInfo->pushConstantRangeCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pPushConstantRanges + idx != NULL) {
                varName = GenerateStruct_VkPushConstantRange(out,
                                                         structInfo->pPushConstantRanges + idx,
                                                         metainfo->pPushConstantRanges->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pPushConstantRangesNames += varName + ", ";
        }
        out << "VkPushConstantRange " << pPushConstantRangesArray << "[] = {" << pPushConstantRangesNames << "};" << std::endl;
    }
    std::string pSetLayoutsArray = "NULL";
    if (metainfo->pSetLayouts.GetPointer() != NULL && structInfo->setLayoutCount > 0) {
        pSetLayoutsArray = "pSetLayoutsArray_" + std::to_string(consumer.getNextId());
        std::string pSetLayoutsValues = toStringJoin(metainfo->pSetLayouts.GetPointer(),
                                                     metainfo->pSetLayouts.GetPointer() + structInfo->setLayoutCount,
                                                     [&](const format::HandleId current) { return consumer.GetHandle(current); },
                                                     ", ");
        if (structInfo->setLayoutCount == 1) {
            pSetLayoutsArray = "&" + pSetLayoutsValues;
        } else if (structInfo->setLayoutCount > 1) {
            out << "VkDescriptorSetLayout " << pSetLayoutsArray << "[] = {" << pSetLayoutsValues << "};" << std::endl;
        }
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkPipelineLayoutCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* setLayoutCount */
    structBody << "\t" << structInfo->setLayoutCount << "," << std::endl;
/* pSetLayouts */
    structBody << "\t" << pSetLayoutsArray << "," << std::endl;
/* pushConstantRangeCount */
    structBody << "\t" << structInfo->pushConstantRangeCount << "," << std::endl;
/* pPushConstantRanges */
    structBody << "\t" << pPushConstantRangesArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "pipelineLayoutCreateInfo");
        out << "VkPipelineLayoutCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPipelineMultisampleStateCreateInfo(std::ostream &out, const VkPipelineMultisampleStateCreateInfo* structInfo, Decoded_VkPipelineMultisampleStateCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pSampleMaskArray = "NULL";
    if (structInfo->pSampleMask != NULL) {
        std::string pSampleMaskValues;
        const VkSampleMask* pSampleMaskPointer = (VkSampleMask*)structInfo->pSampleMask;
        for (uint32_t idx = 0; idx < (structInfo->rasterizationSamples + 31) / 32; idx++) {
            pSampleMaskValues += std::to_string(pSampleMaskPointer[idx]) + ", ";
        }
        pSampleMaskArray = "pSampleMask_" + std::to_string(consumer.getNextId());
        out << "VkSampleMask " << pSampleMaskArray << "[] = {" << pSampleMaskValues << "};" << std::endl;
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkPipelineMultisampleStateCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* rasterizationSamples */
    structBody << "\t" << "VkSampleCountFlagBits(" << structInfo->rasterizationSamples << ")" << "," << std::endl;
/* sampleShadingEnable */
    structBody << "\t" << structInfo->sampleShadingEnable << "," << std::endl;
/* minSampleShading */
    structBody << "\t" << structInfo->minSampleShading << "," << std::endl;
/* pSampleMask */
    structBody << "\t" << pSampleMaskArray << "," << std::endl;
/* alphaToCoverageEnable */
    structBody << "\t" << structInfo->alphaToCoverageEnable << "," << std::endl;
/* alphaToOneEnable */
    structBody << "\t" << structInfo->alphaToOneEnable << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "pipelineMultisampleStateCreateInfo");
        out << "VkPipelineMultisampleStateCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPipelineRasterizationStateCreateInfo(std::ostream &out, const VkPipelineRasterizationStateCreateInfo* structInfo, Decoded_VkPipelineRasterizationStateCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkPipelineRasterizationStateCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* depthClampEnable */
    structBody << "\t" << structInfo->depthClampEnable << "," << std::endl;
/* rasterizerDiscardEnable */
    structBody << "\t" << structInfo->rasterizerDiscardEnable << "," << std::endl;
/* polygonMode */
    structBody << "\t" << "VkPolygonMode(" << structInfo->polygonMode << ")" << "," << std::endl;
/* cullMode */
    structBody << "\t" << "VkCullModeFlags(" << structInfo->cullMode << ")" << "," << std::endl;
/* frontFace */
    structBody << "\t" << "VkFrontFace(" << structInfo->frontFace << ")" << "," << std::endl;
/* depthBiasEnable */
    structBody << "\t" << structInfo->depthBiasEnable << "," << std::endl;
/* depthBiasConstantFactor */
    structBody << "\t" << structInfo->depthBiasConstantFactor << "," << std::endl;
/* depthBiasClamp */
    structBody << "\t" << structInfo->depthBiasClamp << "," << std::endl;
/* depthBiasSlopeFactor */
    structBody << "\t" << structInfo->depthBiasSlopeFactor << "," << std::endl;
/* lineWidth */
    structBody << "\t" << structInfo->lineWidth << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "pipelineRasterizationStateCreateInfo");
        out << "VkPipelineRasterizationStateCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPipelineShaderStageCreateInfo(std::ostream &out, const VkPipelineShaderStageCreateInfo* structInfo, Decoded_VkPipelineShaderStageCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pSpecializationInfoStruct = "NULL";
    if (structInfo->pSpecializationInfo != NULL) {
        pSpecializationInfoStruct = GenerateStruct_VkSpecializationInfo(out,
                                                                   structInfo->pSpecializationInfo,
                                                                   metainfo->pSpecializationInfo->GetMetaStructPointer(),
                                                                   consumer);
        pSpecializationInfoStruct.insert(0, "&");
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkPipelineShaderStageCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* stage */
    structBody << "\t" << "VkShaderStageFlagBits(" << structInfo->stage << ")" << "," << std::endl;
/* module */
    structBody << "\t" << consumer.GetHandle(metainfo->module) << "," << std::endl;
/* pName */
    structBody << "\t" << VulkanCppConsumerBase::toEscape(structInfo->pName) << "," << std::endl;
/* pSpecializationInfo */
    structBody << "\t" << pSpecializationInfoStruct << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "pipelineShaderStageCreateInfo");
        out << "VkPipelineShaderStageCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPipelineTessellationStateCreateInfo(std::ostream &out, const VkPipelineTessellationStateCreateInfo* structInfo, Decoded_VkPipelineTessellationStateCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkPipelineTessellationStateCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* patchControlPoints */
    structBody << "\t" << structInfo->patchControlPoints << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "pipelineTessellationStateCreateInfo");
        out << "VkPipelineTessellationStateCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPipelineVertexInputStateCreateInfo(std::ostream &out, const VkPipelineVertexInputStateCreateInfo* structInfo, Decoded_VkPipelineVertexInputStateCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pVertexAttributeDescriptionsArray = "NULL";
    if (structInfo->pVertexAttributeDescriptions != NULL) {
        pVertexAttributeDescriptionsArray = "pVertexAttributeDescriptions_" + std::to_string(consumer.getNextId());
        std::string pVertexAttributeDescriptionsNames;
        for (uint32_t idx = 0; idx < structInfo->vertexAttributeDescriptionCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pVertexAttributeDescriptions + idx != NULL) {
                varName = GenerateStruct_VkVertexInputAttributeDescription(out,
                                                         structInfo->pVertexAttributeDescriptions + idx,
                                                         metainfo->pVertexAttributeDescriptions->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pVertexAttributeDescriptionsNames += varName + ", ";
        }
        out << "VkVertexInputAttributeDescription " << pVertexAttributeDescriptionsArray << "[] = {" << pVertexAttributeDescriptionsNames << "};" << std::endl;
    }
    std::string pVertexBindingDescriptionsArray = "NULL";
    if (structInfo->pVertexBindingDescriptions != NULL) {
        pVertexBindingDescriptionsArray = "pVertexBindingDescriptions_" + std::to_string(consumer.getNextId());
        std::string pVertexBindingDescriptionsNames;
        for (uint32_t idx = 0; idx < structInfo->vertexBindingDescriptionCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pVertexBindingDescriptions + idx != NULL) {
                varName = GenerateStruct_VkVertexInputBindingDescription(out,
                                                         structInfo->pVertexBindingDescriptions + idx,
                                                         metainfo->pVertexBindingDescriptions->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pVertexBindingDescriptionsNames += varName + ", ";
        }
        out << "VkVertexInputBindingDescription " << pVertexBindingDescriptionsArray << "[] = {" << pVertexBindingDescriptionsNames << "};" << std::endl;
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkPipelineVertexInputStateCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* vertexBindingDescriptionCount */
    structBody << "\t" << structInfo->vertexBindingDescriptionCount << "," << std::endl;
/* pVertexBindingDescriptions */
    structBody << "\t" << pVertexBindingDescriptionsArray << "," << std::endl;
/* vertexAttributeDescriptionCount */
    structBody << "\t" << structInfo->vertexAttributeDescriptionCount << "," << std::endl;
/* pVertexAttributeDescriptions */
    structBody << "\t" << pVertexAttributeDescriptionsArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "pipelineVertexInputStateCreateInfo");
        out << "VkPipelineVertexInputStateCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPipelineViewportStateCreateInfo(std::ostream &out, const VkPipelineViewportStateCreateInfo* structInfo, Decoded_VkPipelineViewportStateCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pScissorsArray = "NULL";
    if (structInfo->pScissors != NULL) {
        pScissorsArray = "pScissors_" + std::to_string(consumer.getNextId());
        out << "VkRect2D " << pScissorsArray << "[] = " << VulkanCppConsumerBase::BuildValue(structInfo->pScissors, structInfo->scissorCount) << ";" << std::endl;
    }
    std::string pViewportsArray = "NULL";
    if (structInfo->pViewports != NULL) {
        pViewportsArray = "pViewports_" + std::to_string(consumer.getNextId());
        std::string pViewportsNames;
        for (uint32_t idx = 0; idx < structInfo->viewportCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pViewports + idx != NULL) {
                varName = GenerateStruct_VkViewport(out,
                                                         structInfo->pViewports + idx,
                                                         metainfo->pViewports->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pViewportsNames += varName + ", ";
        }
        out << "VkViewport " << pViewportsArray << "[] = {" << pViewportsNames << "};" << std::endl;
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkPipelineViewportStateCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* viewportCount */
    structBody << "\t" << structInfo->viewportCount << "," << std::endl;
/* pViewports */
    structBody << "\t" << pViewportsArray << "," << std::endl;
/* scissorCount */
    structBody << "\t" << structInfo->scissorCount << "," << std::endl;
/* pScissors */
    structBody << "\t" << pScissorsArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "pipelineViewportStateCreateInfo");
        out << "VkPipelineViewportStateCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPushConstantRange(std::ostream &out, const VkPushConstantRange* structInfo, Decoded_VkPushConstantRange* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* stageFlags */
    structBody << "\t" << "VkShaderStageFlags(" << structInfo->stageFlags << ")" << "," << std::endl;
/* offset */
    structBody << "\t" << structInfo->offset << "," << std::endl;
/* size */
    structBody << "\t" << structInfo->size << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "pushConstantRange");
        out << "VkPushConstantRange " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkQueryPoolCreateInfo(std::ostream &out, const VkQueryPoolCreateInfo* structInfo, Decoded_VkQueryPoolCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkQueryPoolCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* queryType */
    structBody << "\t" << "VkQueryType(" << structInfo->queryType << ")" << "," << std::endl;
/* queryCount */
    structBody << "\t" << structInfo->queryCount << "," << std::endl;
/* pipelineStatistics */
    structBody << "\t" << "VkQueryPipelineStatisticFlags(" << structInfo->pipelineStatistics << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "queryPoolCreateInfo");
        out << "VkQueryPoolCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkQueueFamilyProperties(std::ostream &out, const VkQueueFamilyProperties* structInfo, Decoded_VkQueueFamilyProperties* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* queueFlags */
    structBody << "\t" << "VkQueueFlags(" << structInfo->queueFlags << ")" << "," << std::endl;
/* queueCount */
    structBody << "\t" << structInfo->queueCount << "," << std::endl;
/* timestampValidBits */
    structBody << "\t" << structInfo->timestampValidBits << "," << std::endl;
/* minImageTransferGranularity */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->minImageTransferGranularity) << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "queueFamilyProperties");
        out << "VkQueueFamilyProperties " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkRect2D(std::ostream &out, const VkRect2D* structInfo, Decoded_VkRect2D* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* offset */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->offset) << "," << std::endl;
/* extent */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->extent) << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "rect2D");
        out << "VkRect2D " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkRenderPassBeginInfo(std::ostream &out, const VkRenderPassBeginInfo* structInfo, Decoded_VkRenderPassBeginInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pClearValuesArray = "NULL";
    if (structInfo->pClearValues != NULL) {
        pClearValuesArray = "pClearValues_" + std::to_string(consumer.getNextId());
        out << "VkClearValue " << pClearValuesArray << "[] = " << VulkanCppConsumerBase::BuildValue(structInfo->pClearValues, structInfo->clearValueCount) << ";" << std::endl;
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* renderPass */
    structBody << "\t" << consumer.GetHandle(metainfo->renderPass) << "," << std::endl;
/* framebuffer */
    structBody << "\t" << consumer.GetHandle(metainfo->framebuffer) << "," << std::endl;
/* renderArea */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->renderArea) << "," << std::endl;
/* clearValueCount */
    structBody << "\t" << structInfo->clearValueCount << "," << std::endl;
/* pClearValues */
    structBody << "\t" << pClearValuesArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "renderPassBeginInfo");
        out << "VkRenderPassBeginInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkRenderPassCreateInfo(std::ostream &out, const VkRenderPassCreateInfo* structInfo, Decoded_VkRenderPassCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pDependenciesArray = "NULL";
    if (structInfo->pDependencies != NULL) {
        pDependenciesArray = "pDependencies_" + std::to_string(consumer.getNextId());
        std::string pDependenciesNames;
        for (uint32_t idx = 0; idx < structInfo->dependencyCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pDependencies + idx != NULL) {
                varName = GenerateStruct_VkSubpassDependency(out,
                                                         structInfo->pDependencies + idx,
                                                         metainfo->pDependencies->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pDependenciesNames += varName + ", ";
        }
        out << "VkSubpassDependency " << pDependenciesArray << "[] = {" << pDependenciesNames << "};" << std::endl;
    }
    std::string pSubpassesArray = "NULL";
    if (structInfo->pSubpasses != NULL) {
        pSubpassesArray = "pSubpasses_" + std::to_string(consumer.getNextId());
        std::string pSubpassesNames;
        for (uint32_t idx = 0; idx < structInfo->subpassCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pSubpasses + idx != NULL) {
                varName = GenerateStruct_VkSubpassDescription(out,
                                                         structInfo->pSubpasses + idx,
                                                         metainfo->pSubpasses->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pSubpassesNames += varName + ", ";
        }
        out << "VkSubpassDescription " << pSubpassesArray << "[] = {" << pSubpassesNames << "};" << std::endl;
    }
    std::string pAttachmentsArray = "NULL";
    if (structInfo->pAttachments != NULL) {
        pAttachmentsArray = "pAttachments_" + std::to_string(consumer.getNextId());
        std::string pAttachmentsNames;
        for (uint32_t idx = 0; idx < structInfo->attachmentCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pAttachments + idx != NULL) {
                varName = GenerateStruct_VkAttachmentDescription(out,
                                                         structInfo->pAttachments + idx,
                                                         metainfo->pAttachments->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pAttachmentsNames += varName + ", ";
        }
        out << "VkAttachmentDescription " << pAttachmentsArray << "[] = {" << pAttachmentsNames << "};" << std::endl;
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkRenderPassCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* attachmentCount */
    structBody << "\t" << structInfo->attachmentCount << "," << std::endl;
/* pAttachments */
    structBody << "\t" << pAttachmentsArray << "," << std::endl;
/* subpassCount */
    structBody << "\t" << structInfo->subpassCount << "," << std::endl;
/* pSubpasses */
    structBody << "\t" << pSubpassesArray << "," << std::endl;
/* dependencyCount */
    structBody << "\t" << structInfo->dependencyCount << "," << std::endl;
/* pDependencies */
    structBody << "\t" << pDependenciesArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "renderPassCreateInfo");
        out << "VkRenderPassCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSamplerCreateInfo(std::ostream &out, const VkSamplerCreateInfo* structInfo, Decoded_VkSamplerCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkSamplerCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* magFilter */
    structBody << "\t" << "VkFilter(" << structInfo->magFilter << ")" << "," << std::endl;
/* minFilter */
    structBody << "\t" << "VkFilter(" << structInfo->minFilter << ")" << "," << std::endl;
/* mipmapMode */
    structBody << "\t" << "VkSamplerMipmapMode(" << structInfo->mipmapMode << ")" << "," << std::endl;
/* addressModeU */
    structBody << "\t" << "VkSamplerAddressMode(" << structInfo->addressModeU << ")" << "," << std::endl;
/* addressModeV */
    structBody << "\t" << "VkSamplerAddressMode(" << structInfo->addressModeV << ")" << "," << std::endl;
/* addressModeW */
    structBody << "\t" << "VkSamplerAddressMode(" << structInfo->addressModeW << ")" << "," << std::endl;
/* mipLodBias */
    structBody << "\t" << structInfo->mipLodBias << "," << std::endl;
/* anisotropyEnable */
    structBody << "\t" << structInfo->anisotropyEnable << "," << std::endl;
/* maxAnisotropy */
    structBody << "\t" << structInfo->maxAnisotropy << "," << std::endl;
/* compareEnable */
    structBody << "\t" << structInfo->compareEnable << "," << std::endl;
/* compareOp */
    structBody << "\t" << "VkCompareOp(" << structInfo->compareOp << ")" << "," << std::endl;
/* minLod */
    structBody << "\t" << structInfo->minLod << "," << std::endl;
/* maxLod */
    structBody << "\t" << structInfo->maxLod << "," << std::endl;
/* borderColor */
    structBody << "\t" << "VkBorderColor(" << structInfo->borderColor << ")" << "," << std::endl;
/* unnormalizedCoordinates */
    structBody << "\t" << structInfo->unnormalizedCoordinates << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "samplerCreateInfo");
        out << "VkSamplerCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSemaphoreCreateInfo(std::ostream &out, const VkSemaphoreCreateInfo* structInfo, Decoded_VkSemaphoreCreateInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkSemaphoreCreateFlags(" << structInfo->flags << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "semaphoreCreateInfo");
        out << "VkSemaphoreCreateInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSparseBufferMemoryBindInfo(std::ostream &out, const VkSparseBufferMemoryBindInfo* structInfo, Decoded_VkSparseBufferMemoryBindInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pBindsArray = "NULL";
    if (structInfo->pBinds != NULL) {
        pBindsArray = "pBinds_" + std::to_string(consumer.getNextId());
        std::string pBindsNames;
        for (uint32_t idx = 0; idx < structInfo->bindCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pBinds + idx != NULL) {
                varName = GenerateStruct_VkSparseMemoryBind(out,
                                                         structInfo->pBinds + idx,
                                                         metainfo->pBinds->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pBindsNames += varName + ", ";
        }
        out << "VkSparseMemoryBind " << pBindsArray << "[] = {" << pBindsNames << "};" << std::endl;
    }
    std::stringstream structBody;
/* buffer */
    structBody << "\t" << consumer.GetHandle(metainfo->buffer) << "," << std::endl;
/* bindCount */
    structBody << "\t" << structInfo->bindCount << "," << std::endl;
/* pBinds */
    structBody << "\t" << pBindsArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "sparseBufferMemoryBindInfo");
        out << "VkSparseBufferMemoryBindInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSparseImageFormatProperties(std::ostream &out, const VkSparseImageFormatProperties* structInfo, Decoded_VkSparseImageFormatProperties* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* aspectMask */
    structBody << "\t" << "VkImageAspectFlags(" << structInfo->aspectMask << ")" << "," << std::endl;
/* imageGranularity */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->imageGranularity) << "," << std::endl;
/* flags */
    structBody << "\t" << "VkSparseImageFormatFlags(" << structInfo->flags << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "sparseImageFormatProperties");
        out << "VkSparseImageFormatProperties " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSparseImageMemoryBind(std::ostream &out, const VkSparseImageMemoryBind* structInfo, Decoded_VkSparseImageMemoryBind* metainfo, VulkanCppConsumerBase &consumer){
    std::string subresourceInfoVar = GenerateStruct_VkImageSubresource(out,
                                                                    &structInfo->subresource,
                                                                    metainfo->subresource,
                                                                    consumer);
    std::stringstream structBody;
/* subresource */
    structBody << "\t" << subresourceInfoVar << "," << std::endl;
/* offset */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->offset) << "," << std::endl;
/* extent */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->extent) << "," << std::endl;
/* memory */
    structBody << "\t" << consumer.GetHandle(metainfo->memory) << "," << std::endl;
/* memoryOffset */
    structBody << "\t" << structInfo->memoryOffset << "UL" << "," << std::endl;
/* flags */
    structBody << "\t" << "VkSparseMemoryBindFlags(" << structInfo->flags << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "sparseImageMemoryBind");
        out << "VkSparseImageMemoryBind " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSparseImageMemoryBindInfo(std::ostream &out, const VkSparseImageMemoryBindInfo* structInfo, Decoded_VkSparseImageMemoryBindInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pBindsArray = "NULL";
    if (structInfo->pBinds != NULL) {
        pBindsArray = "pBinds_" + std::to_string(consumer.getNextId());
        std::string pBindsNames;
        for (uint32_t idx = 0; idx < structInfo->bindCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pBinds + idx != NULL) {
                varName = GenerateStruct_VkSparseImageMemoryBind(out,
                                                         structInfo->pBinds + idx,
                                                         metainfo->pBinds->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pBindsNames += varName + ", ";
        }
        out << "VkSparseImageMemoryBind " << pBindsArray << "[] = {" << pBindsNames << "};" << std::endl;
    }
    std::stringstream structBody;
/* image */
    structBody << "\t" << consumer.GetHandle(metainfo->image) << "," << std::endl;
/* bindCount */
    structBody << "\t" << structInfo->bindCount << "," << std::endl;
/* pBinds */
    structBody << "\t" << pBindsArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "sparseImageMemoryBindInfo");
        out << "VkSparseImageMemoryBindInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSparseImageMemoryRequirements(std::ostream &out, const VkSparseImageMemoryRequirements* structInfo, Decoded_VkSparseImageMemoryRequirements* metainfo, VulkanCppConsumerBase &consumer){
    std::string formatPropertiesInfoVar = GenerateStruct_VkSparseImageFormatProperties(out,
                                                                         &structInfo->formatProperties,
                                                                         metainfo->formatProperties,
                                                                         consumer);
    std::stringstream structBody;
/* formatProperties */
    structBody << "\t" << formatPropertiesInfoVar << "," << std::endl;
/* imageMipTailFirstLod */
    structBody << "\t" << structInfo->imageMipTailFirstLod << "," << std::endl;
/* imageMipTailSize */
    structBody << "\t" << structInfo->imageMipTailSize << "UL" << "," << std::endl;
/* imageMipTailOffset */
    structBody << "\t" << structInfo->imageMipTailOffset << "UL" << "," << std::endl;
/* imageMipTailStride */
    structBody << "\t" << structInfo->imageMipTailStride << "UL" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "sparseImageMemoryRequirements");
        out << "VkSparseImageMemoryRequirements " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSparseImageOpaqueMemoryBindInfo(std::ostream &out, const VkSparseImageOpaqueMemoryBindInfo* structInfo, Decoded_VkSparseImageOpaqueMemoryBindInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pBindsArray = "NULL";
    if (structInfo->pBinds != NULL) {
        pBindsArray = "pBinds_" + std::to_string(consumer.getNextId());
        std::string pBindsNames;
        for (uint32_t idx = 0; idx < structInfo->bindCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pBinds + idx != NULL) {
                varName = GenerateStruct_VkSparseMemoryBind(out,
                                                         structInfo->pBinds + idx,
                                                         metainfo->pBinds->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pBindsNames += varName + ", ";
        }
        out << "VkSparseMemoryBind " << pBindsArray << "[] = {" << pBindsNames << "};" << std::endl;
    }
    std::stringstream structBody;
/* image */
    structBody << "\t" << consumer.GetHandle(metainfo->image) << "," << std::endl;
/* bindCount */
    structBody << "\t" << structInfo->bindCount << "," << std::endl;
/* pBinds */
    structBody << "\t" << pBindsArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "sparseImageOpaqueMemoryBindInfo");
        out << "VkSparseImageOpaqueMemoryBindInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSparseMemoryBind(std::ostream &out, const VkSparseMemoryBind* structInfo, Decoded_VkSparseMemoryBind* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* resourceOffset */
    structBody << "\t" << structInfo->resourceOffset << "UL" << "," << std::endl;
/* size */
    structBody << "\t" << structInfo->size << "UL" << "," << std::endl;
/* memory */
    structBody << "\t" << consumer.GetHandle(metainfo->memory) << "," << std::endl;
/* memoryOffset */
    structBody << "\t" << structInfo->memoryOffset << "UL" << "," << std::endl;
/* flags */
    structBody << "\t" << "VkSparseMemoryBindFlags(" << structInfo->flags << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "sparseMemoryBind");
        out << "VkSparseMemoryBind " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSpecializationInfo(std::ostream &out, const VkSpecializationInfo* structInfo, Decoded_VkSpecializationInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pDataArray = "NULL";
    if (structInfo->pData != NULL) {
        std::string pDataValues;
        const uint8_t* pDataPointer = (uint8_t*)structInfo->pData;
        for (uint32_t idx = 0; idx < structInfo->dataSize; idx++) {
            pDataValues += std::to_string(pDataPointer[idx]) + ", ";
        }
        pDataArray = "pData_" + std::to_string(consumer.getNextId());
        out << "uint8_t " << pDataArray << "[] = {" << pDataValues << "};" << std::endl;
    }
    std::string pMapEntriesArray = "NULL";
    if (structInfo->pMapEntries != NULL) {
        pMapEntriesArray = "pMapEntries_" + std::to_string(consumer.getNextId());
        std::string pMapEntriesNames;
        for (uint32_t idx = 0; idx < structInfo->mapEntryCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pMapEntries + idx != NULL) {
                varName = GenerateStruct_VkSpecializationMapEntry(out,
                                                         structInfo->pMapEntries + idx,
                                                         metainfo->pMapEntries->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pMapEntriesNames += varName + ", ";
        }
        out << "VkSpecializationMapEntry " << pMapEntriesArray << "[] = {" << pMapEntriesNames << "};" << std::endl;
    }
    std::stringstream structBody;
/* mapEntryCount */
    structBody << "\t" << structInfo->mapEntryCount << "," << std::endl;
/* pMapEntries */
    structBody << "\t" << pMapEntriesArray << "," << std::endl;
/* dataSize */
    structBody << "\t" << structInfo->dataSize << "," << std::endl;
/* pData */
    structBody << "\t" << pDataArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "specializationInfo");
        out << "VkSpecializationInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSpecializationMapEntry(std::ostream &out, const VkSpecializationMapEntry* structInfo, Decoded_VkSpecializationMapEntry* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* constantID */
    structBody << "\t" << structInfo->constantID << "," << std::endl;
/* offset */
    structBody << "\t" << structInfo->offset << "," << std::endl;
/* size */
    structBody << "\t" << structInfo->size << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "specializationMapEntry");
        out << "VkSpecializationMapEntry " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkStencilOpState(std::ostream &out, const VkStencilOpState* structInfo, Decoded_VkStencilOpState* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* failOp */
    structBody << "\t" << "VkStencilOp(" << structInfo->failOp << ")" << "," << std::endl;
/* passOp */
    structBody << "\t" << "VkStencilOp(" << structInfo->passOp << ")" << "," << std::endl;
/* depthFailOp */
    structBody << "\t" << "VkStencilOp(" << structInfo->depthFailOp << ")" << "," << std::endl;
/* compareOp */
    structBody << "\t" << "VkCompareOp(" << structInfo->compareOp << ")" << "," << std::endl;
/* compareMask */
    structBody << "\t" << structInfo->compareMask << "," << std::endl;
/* writeMask */
    structBody << "\t" << structInfo->writeMask << "," << std::endl;
/* reference */
    structBody << "\t" << structInfo->reference << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "stencilOpState");
        out << "VkStencilOpState " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSubmitInfo(std::ostream &out, const VkSubmitInfo* structInfo, Decoded_VkSubmitInfo* metainfo, VulkanCppConsumerBase &consumer){
    std::string pSignalSemaphoresArray = "NULL";
    if (metainfo->pSignalSemaphores.GetPointer() != NULL && structInfo->signalSemaphoreCount > 0) {
        pSignalSemaphoresArray = "pSignalSemaphoresArray_" + std::to_string(consumer.getNextId());
        std::string pSignalSemaphoresValues = toStringJoin(metainfo->pSignalSemaphores.GetPointer(),
                                                           metainfo->pSignalSemaphores.GetPointer() + structInfo->signalSemaphoreCount,
                                                           [&](const format::HandleId current) { return consumer.GetHandle(current); },
                                                           ", ");
        if (structInfo->signalSemaphoreCount == 1) {
            pSignalSemaphoresArray = "&" + pSignalSemaphoresValues;
        } else if (structInfo->signalSemaphoreCount > 1) {
            out << "VkSemaphore " << pSignalSemaphoresArray << "[] = {" << pSignalSemaphoresValues << "};" << std::endl;
        }
    }
    std::string pCommandBuffersArray = "NULL";
    if (metainfo->pCommandBuffers.GetPointer() != NULL && structInfo->commandBufferCount > 0) {
        pCommandBuffersArray = "pCommandBuffersArray_" + std::to_string(consumer.getNextId());
        std::string pCommandBuffersValues = toStringJoin(metainfo->pCommandBuffers.GetPointer(),
                                                         metainfo->pCommandBuffers.GetPointer() + structInfo->commandBufferCount,
                                                         [&](const format::HandleId current) { return consumer.GetHandle(current); },
                                                         ", ");
        if (structInfo->commandBufferCount == 1) {
            pCommandBuffersArray = "&" + pCommandBuffersValues;
        } else if (structInfo->commandBufferCount > 1) {
            out << "VkCommandBuffer " << pCommandBuffersArray << "[] = {" << pCommandBuffersValues << "};" << std::endl;
        }
    }
    std::string pWaitDstStageMaskValues;
    std::string pWaitDstStageMaskArray = "NULL";
    if (structInfo->pWaitDstStageMask != NULL) {
        for (uint32_t idx = 0; idx < structInfo->waitSemaphoreCount; idx++) {
            pWaitDstStageMaskValues += util::ToString<VkPipelineStageFlags>(structInfo->pWaitDstStageMask[idx]) + ", ";
        }
        pWaitDstStageMaskArray = "pWaitDstStageMask_" + std::to_string(consumer.getNextId());
        out << "VkPipelineStageFlags " << pWaitDstStageMaskArray << "[] = {" << pWaitDstStageMaskValues << "};" << std::endl;
    }
    std::string pWaitSemaphoresArray = "NULL";
    if (metainfo->pWaitSemaphores.GetPointer() != NULL && structInfo->waitSemaphoreCount > 0) {
        pWaitSemaphoresArray = "pWaitSemaphoresArray_" + std::to_string(consumer.getNextId());
        std::string pWaitSemaphoresValues = toStringJoin(metainfo->pWaitSemaphores.GetPointer(),
                                                         metainfo->pWaitSemaphores.GetPointer() + structInfo->waitSemaphoreCount,
                                                         [&](const format::HandleId current) { return consumer.GetHandle(current); },
                                                         ", ");
        if (structInfo->waitSemaphoreCount == 1) {
            pWaitSemaphoresArray = "&" + pWaitSemaphoresValues;
        } else if (structInfo->waitSemaphoreCount > 1) {
            out << "VkSemaphore " << pWaitSemaphoresArray << "[] = {" << pWaitSemaphoresValues << "};" << std::endl;
        }
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* waitSemaphoreCount */
    structBody << "\t" << structInfo->waitSemaphoreCount << "," << std::endl;
/* pWaitSemaphores */
    structBody << "\t" << pWaitSemaphoresArray << "," << std::endl;
/* pWaitDstStageMask */
    structBody << "\t" << pWaitDstStageMaskArray << "," << std::endl;
/* commandBufferCount */
    structBody << "\t" << structInfo->commandBufferCount << "," << std::endl;
/* pCommandBuffers */
    structBody << "\t" << pCommandBuffersArray << "," << std::endl;
/* signalSemaphoreCount */
    structBody << "\t" << structInfo->signalSemaphoreCount << "," << std::endl;
/* pSignalSemaphores */
    structBody << "\t" << pSignalSemaphoresArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "submitInfo");
        out << "VkSubmitInfo " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSubpassDependency(std::ostream &out, const VkSubpassDependency* structInfo, Decoded_VkSubpassDependency* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* srcSubpass */
    structBody << "\t" << structInfo->srcSubpass << "," << std::endl;
/* dstSubpass */
    structBody << "\t" << structInfo->dstSubpass << "," << std::endl;
/* srcStageMask */
    structBody << "\t" << "VkPipelineStageFlags(" << structInfo->srcStageMask << ")" << "," << std::endl;
/* dstStageMask */
    structBody << "\t" << "VkPipelineStageFlags(" << structInfo->dstStageMask << ")" << "," << std::endl;
/* srcAccessMask */
    structBody << "\t" << "VkAccessFlags(" << structInfo->srcAccessMask << ")" << "," << std::endl;
/* dstAccessMask */
    structBody << "\t" << "VkAccessFlags(" << structInfo->dstAccessMask << ")" << "," << std::endl;
/* dependencyFlags */
    structBody << "\t" << "VkDependencyFlags(" << structInfo->dependencyFlags << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "subpassDependency");
        out << "VkSubpassDependency " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSubpassDescription(std::ostream &out, const VkSubpassDescription* structInfo, Decoded_VkSubpassDescription* metainfo, VulkanCppConsumerBase &consumer){
    std::string pPreserveAttachmentsArray = "NULL";
    if (structInfo->pPreserveAttachments != NULL) {
        pPreserveAttachmentsArray = "pPreserveAttachments_" + std::to_string(consumer.getNextId());
        out << "uint32_t " << pPreserveAttachmentsArray << "[] = " << VulkanCppConsumerBase::BuildValue(structInfo->pPreserveAttachments, structInfo->preserveAttachmentCount) << ";" << std::endl;
    }
    std::string pDepthStencilAttachmentStruct = "NULL";
    if (structInfo->pDepthStencilAttachment != NULL) {
        pDepthStencilAttachmentStruct = GenerateStruct_VkAttachmentReference(out,
                                                                       structInfo->pDepthStencilAttachment,
                                                                       metainfo->pDepthStencilAttachment->GetMetaStructPointer(),
                                                                       consumer);
        pDepthStencilAttachmentStruct.insert(0, "&");
    }
    std::string pResolveAttachmentsArray = "NULL";
    if (structInfo->pResolveAttachments != NULL) {
        pResolveAttachmentsArray = "pResolveAttachments_" + std::to_string(consumer.getNextId());
        std::string pResolveAttachmentsNames;
        for (uint32_t idx = 0; idx < structInfo->colorAttachmentCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pResolveAttachments + idx != NULL) {
                varName = GenerateStruct_VkAttachmentReference(out,
                                                         structInfo->pResolveAttachments + idx,
                                                         metainfo->pResolveAttachments->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pResolveAttachmentsNames += varName + ", ";
        }
        out << "VkAttachmentReference " << pResolveAttachmentsArray << "[] = {" << pResolveAttachmentsNames << "};" << std::endl;
    }
    std::string pColorAttachmentsArray = "NULL";
    if (structInfo->pColorAttachments != NULL) {
        pColorAttachmentsArray = "pColorAttachments_" + std::to_string(consumer.getNextId());
        std::string pColorAttachmentsNames;
        for (uint32_t idx = 0; idx < structInfo->colorAttachmentCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pColorAttachments + idx != NULL) {
                varName = GenerateStruct_VkAttachmentReference(out,
                                                         structInfo->pColorAttachments + idx,
                                                         metainfo->pColorAttachments->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pColorAttachmentsNames += varName + ", ";
        }
        out << "VkAttachmentReference " << pColorAttachmentsArray << "[] = {" << pColorAttachmentsNames << "};" << std::endl;
    }
    std::string pInputAttachmentsArray = "NULL";
    if (structInfo->pInputAttachments != NULL) {
        pInputAttachmentsArray = "pInputAttachments_" + std::to_string(consumer.getNextId());
        std::string pInputAttachmentsNames;
        for (uint32_t idx = 0; idx < structInfo->inputAttachmentCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pInputAttachments + idx != NULL) {
                varName = GenerateStruct_VkAttachmentReference(out,
                                                         structInfo->pInputAttachments + idx,
                                                         metainfo->pInputAttachments->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pInputAttachmentsNames += varName + ", ";
        }
        out << "VkAttachmentReference " << pInputAttachmentsArray << "[] = {" << pInputAttachmentsNames << "};" << std::endl;
    }
    std::stringstream structBody;
/* flags */
    structBody << "\t" << "VkSubpassDescriptionFlags(" << structInfo->flags << ")" << "," << std::endl;
/* pipelineBindPoint */
    structBody << "\t" << "VkPipelineBindPoint(" << structInfo->pipelineBindPoint << ")" << "," << std::endl;
/* inputAttachmentCount */
    structBody << "\t" << structInfo->inputAttachmentCount << "," << std::endl;
/* pInputAttachments */
    structBody << "\t" << pInputAttachmentsArray << "," << std::endl;
/* colorAttachmentCount */
    structBody << "\t" << structInfo->colorAttachmentCount << "," << std::endl;
/* pColorAttachments */
    structBody << "\t" << pColorAttachmentsArray << "," << std::endl;
/* pResolveAttachments */
    structBody << "\t" << pResolveAttachmentsArray << "," << std::endl;
/* pDepthStencilAttachment */
    structBody << "\t" << pDepthStencilAttachmentStruct << "," << std::endl;
/* preserveAttachmentCount */
    structBody << "\t" << structInfo->preserveAttachmentCount << "," << std::endl;
/* pPreserveAttachments */
    structBody << "\t" << pPreserveAttachmentsArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "subpassDescription");
        out << "VkSubpassDescription " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSubresourceLayout(std::ostream &out, const VkSubresourceLayout* structInfo, Decoded_VkSubresourceLayout* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* offset */
    structBody << "\t" << structInfo->offset << "UL" << "," << std::endl;
/* size */
    structBody << "\t" << structInfo->size << "UL" << "," << std::endl;
/* rowPitch */
    structBody << "\t" << structInfo->rowPitch << "UL" << "," << std::endl;
/* arrayPitch */
    structBody << "\t" << structInfo->arrayPitch << "UL" << "," << std::endl;
/* depthPitch */
    structBody << "\t" << structInfo->depthPitch << "UL" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "subresourceLayout");
        out << "VkSubresourceLayout " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkVertexInputAttributeDescription(std::ostream &out, const VkVertexInputAttributeDescription* structInfo, Decoded_VkVertexInputAttributeDescription* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* location */
    structBody << "\t" << structInfo->location << "," << std::endl;
/* binding */
    structBody << "\t" << structInfo->binding << "," << std::endl;
/* format */
    structBody << "\t" << "VkFormat(" << structInfo->format << ")" << "," << std::endl;
/* offset */
    structBody << "\t" << structInfo->offset << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "vertexInputAttributeDescription");
        out << "VkVertexInputAttributeDescription " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkVertexInputBindingDescription(std::ostream &out, const VkVertexInputBindingDescription* structInfo, Decoded_VkVertexInputBindingDescription* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* binding */
    structBody << "\t" << structInfo->binding << "," << std::endl;
/* stride */
    structBody << "\t" << structInfo->stride << "," << std::endl;
/* inputRate */
    structBody << "\t" << "VkVertexInputRate(" << structInfo->inputRate << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "vertexInputBindingDescription");
        out << "VkVertexInputBindingDescription " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkViewport(std::ostream &out, const VkViewport* structInfo, Decoded_VkViewport* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* x */
    structBody << "\t" << structInfo->x << "," << std::endl;
/* y */
    structBody << "\t" << structInfo->y << "," << std::endl;
/* width */
    structBody << "\t" << structInfo->width << "," << std::endl;
/* height */
    structBody << "\t" << structInfo->height << "," << std::endl;
/* minDepth */
    structBody << "\t" << structInfo->minDepth << "," << std::endl;
/* maxDepth */
    structBody << "\t" << structInfo->maxDepth << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "viewport");
        out << "VkViewport " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}


std::string GenerateStruct_VkSurfaceCapabilitiesKHR(std::ostream &out, const VkSurfaceCapabilitiesKHR* structInfo, Decoded_VkSurfaceCapabilitiesKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* minImageCount */
    structBody << "\t" << structInfo->minImageCount << "," << std::endl;
/* maxImageCount */
    structBody << "\t" << structInfo->maxImageCount << "," << std::endl;
/* currentExtent */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->currentExtent) << "," << std::endl;
/* minImageExtent */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->minImageExtent) << "," << std::endl;
/* maxImageExtent */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->maxImageExtent) << "," << std::endl;
/* maxImageArrayLayers */
    structBody << "\t" << structInfo->maxImageArrayLayers << "," << std::endl;
/* supportedTransforms */
    structBody << "\t" << "VkSurfaceTransformFlagsKHR(" << structInfo->supportedTransforms << ")" << "," << std::endl;
/* currentTransform */
    structBody << "\t" << "VkSurfaceTransformFlagBitsKHR(" << structInfo->currentTransform << ")" << "," << std::endl;
/* supportedCompositeAlpha */
    structBody << "\t" << "VkCompositeAlphaFlagsKHR(" << structInfo->supportedCompositeAlpha << ")" << "," << std::endl;
/* supportedUsageFlags */
    structBody << "\t" << "VkImageUsageFlags(" << structInfo->supportedUsageFlags << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "surfaceCapabilitiesKHR");
        out << "VkSurfaceCapabilitiesKHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSurfaceFormatKHR(std::ostream &out, const VkSurfaceFormatKHR* structInfo, Decoded_VkSurfaceFormatKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* format */
    structBody << "\t" << "VkFormat(" << structInfo->format << ")" << "," << std::endl;
/* colorSpace */
    structBody << "\t" << "VkColorSpaceKHR(" << structInfo->colorSpace << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "surfaceFormatKHR");
        out << "VkSurfaceFormatKHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}


std::string GenerateStruct_VkAcquireNextImageInfoKHR(std::ostream &out, const VkAcquireNextImageInfoKHR* structInfo, Decoded_VkAcquireNextImageInfoKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* swapchain */
    structBody << "\t" << consumer.GetHandle(metainfo->swapchain) << "," << std::endl;
/* timeout */
    structBody << "\t" << structInfo->timeout << "UL" << "," << std::endl;
/* semaphore */
    structBody << "\t" << consumer.GetHandle(metainfo->semaphore) << "," << std::endl;
/* fence */
    structBody << "\t" << consumer.GetHandle(metainfo->fence) << "," << std::endl;
/* deviceMask */
    structBody << "\t" << structInfo->deviceMask << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "acquireNextImageInfoKHR");
        out << "VkAcquireNextImageInfoKHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkBindImageMemorySwapchainInfoKHR(std::ostream &out, const VkBindImageMemorySwapchainInfoKHR* structInfo, Decoded_VkBindImageMemorySwapchainInfoKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* swapchain */
    structBody << "\t" << consumer.GetHandle(metainfo->swapchain) << "," << std::endl;
/* imageIndex */
    structBody << "\t" << structInfo->imageIndex << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "bindImageMemorySwapchainInfoKHR");
        out << "VkBindImageMemorySwapchainInfoKHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkDeviceGroupPresentCapabilitiesKHR(std::ostream &out, const VkDeviceGroupPresentCapabilitiesKHR* structInfo, Decoded_VkDeviceGroupPresentCapabilitiesKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* presentMask */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->presentMask, VK_MAX_DEVICE_GROUP_SIZE) << "," << std::endl;
/* modes */
    structBody << "\t" << "VkDeviceGroupPresentModeFlagsKHR(" << structInfo->modes << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "deviceGroupPresentCapabilitiesKHR");
        out << "VkDeviceGroupPresentCapabilitiesKHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkDeviceGroupPresentInfoKHR(std::ostream &out, const VkDeviceGroupPresentInfoKHR* structInfo, Decoded_VkDeviceGroupPresentInfoKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::string pDeviceMasksArray = "NULL";
    if (structInfo->pDeviceMasks != NULL) {
        pDeviceMasksArray = "pDeviceMasks_" + std::to_string(consumer.getNextId());
        out << "uint32_t " << pDeviceMasksArray << "[] = " << VulkanCppConsumerBase::BuildValue(structInfo->pDeviceMasks, structInfo->swapchainCount) << ";" << std::endl;
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* swapchainCount */
    structBody << "\t" << structInfo->swapchainCount << "," << std::endl;
/* pDeviceMasks */
    structBody << "\t" << pDeviceMasksArray << "," << std::endl;
/* mode */
    structBody << "\t" << "VkDeviceGroupPresentModeFlagBitsKHR(" << structInfo->mode << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "deviceGroupPresentInfoKHR");
        out << "VkDeviceGroupPresentInfoKHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkDeviceGroupSwapchainCreateInfoKHR(std::ostream &out, const VkDeviceGroupSwapchainCreateInfoKHR* structInfo, Decoded_VkDeviceGroupSwapchainCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* modes */
    structBody << "\t" << "VkDeviceGroupPresentModeFlagsKHR(" << structInfo->modes << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "deviceGroupSwapchainCreateInfoKHR");
        out << "VkDeviceGroupSwapchainCreateInfoKHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkImageSwapchainCreateInfoKHR(std::ostream &out, const VkImageSwapchainCreateInfoKHR* structInfo, Decoded_VkImageSwapchainCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* swapchain */
    structBody << "\t" << consumer.GetHandle(metainfo->swapchain) << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "imageSwapchainCreateInfoKHR");
        out << "VkImageSwapchainCreateInfoKHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSwapchainCreateInfoKHR(std::ostream &out, const VkSwapchainCreateInfoKHR* structInfo, Decoded_VkSwapchainCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::string pQueueFamilyIndicesArray = "NULL";
    if (structInfo->pQueueFamilyIndices != NULL) {
        pQueueFamilyIndicesArray = "pQueueFamilyIndices_" + std::to_string(consumer.getNextId());
        out << "uint32_t " << pQueueFamilyIndicesArray << "[] = " << VulkanCppConsumerBase::BuildValue(structInfo->pQueueFamilyIndices, structInfo->queueFamilyIndexCount) << ";" << std::endl;
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkSwapchainCreateFlagsKHR(" << structInfo->flags << ")" << "," << std::endl;
/* surface */
    structBody << "\t" << consumer.GetHandle(metainfo->surface) << "," << std::endl;
/* minImageCount */
    structBody << "\t" << structInfo->minImageCount << "," << std::endl;
/* imageFormat */
    structBody << "\t" << "VkFormat(" << structInfo->imageFormat << ")" << "," << std::endl;
/* imageColorSpace */
    structBody << "\t" << "VkColorSpaceKHR(" << structInfo->imageColorSpace << ")" << "," << std::endl;
/* imageExtent */
    structBody << "\t" << VulkanCppConsumerBase::BuildValue(structInfo->imageExtent) << "," << std::endl;
/* imageArrayLayers */
    structBody << "\t" << structInfo->imageArrayLayers << "," << std::endl;
/* imageUsage */
    structBody << "\t" << "VkImageUsageFlags(" << structInfo->imageUsage << ")" << "," << std::endl;
/* imageSharingMode */
    structBody << "\t" << "VkSharingMode(" << structInfo->imageSharingMode << ")" << "," << std::endl;
/* queueFamilyIndexCount */
    structBody << "\t" << structInfo->queueFamilyIndexCount << "," << std::endl;
/* pQueueFamilyIndices */
    structBody << "\t" << pQueueFamilyIndicesArray << "," << std::endl;
/* preTransform */
    structBody << "\t" << "VkSurfaceTransformFlagBitsKHR(" << structInfo->preTransform << ")" << "," << std::endl;
/* compositeAlpha */
    structBody << "\t" << "VkCompositeAlphaFlagBitsKHR(" << structInfo->compositeAlpha << ")" << "," << std::endl;
/* presentMode */
    structBody << "\t" << "VkPresentModeKHR(" << structInfo->presentMode << ")" << "," << std::endl;
/* clipped */
    structBody << "\t" << structInfo->clipped << "," << std::endl;
/* oldSwapchain */
    structBody << "\t" << consumer.GetHandle(metainfo->oldSwapchain) << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "swapchainCreateInfoKHR");
        out << "VkSwapchainCreateInfoKHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}


std::string GenerateStruct_VkXcbSurfaceCreateInfoKHR(std::ostream &out, const VkXcbSurfaceCreateInfoKHR* structInfo, Decoded_VkXcbSurfaceCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
    std::string varname = "override_" + std::to_string(consumer.getNextId());
    out << "VkXcbSurfaceCreateInfoKHR " << varname << " {};" << std::endl;
    out << "OverrideVkXcbSurfaceCreateInfoKHR(&" << varname << ", " << "appdata" << ");" << std::endl;
    return varname;
}


std::string GenerateStruct_VkWaylandSurfaceCreateInfoKHR(std::ostream &out, const VkWaylandSurfaceCreateInfoKHR* structInfo, Decoded_VkWaylandSurfaceCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
    std::string varname = "override_" + std::to_string(consumer.getNextId());
    out << "VkWaylandSurfaceCreateInfoKHR " << varname << " {};" << std::endl;
    out << "OverrideVkWaylandSurfaceCreateInfoKHR(&" << varname << ", " << "appdata" << ");" << std::endl;
    return varname;
}


std::string GenerateStruct_VkAndroidSurfaceCreateInfoKHR(std::ostream &out, const VkAndroidSurfaceCreateInfoKHR* structInfo, Decoded_VkAndroidSurfaceCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
    std::string varname = "override_" + std::to_string(consumer.getNextId());
    out << "VkAndroidSurfaceCreateInfoKHR " << varname << " {};" << std::endl;
    out << "OverrideVkAndroidSurfaceCreateInfoKHR(&" << varname << ", " << "appdata" << ");" << std::endl;
    return varname;
}


std::string GenerateStruct_VkPhysicalDeviceMultiviewFeaturesKHR(std::ostream &out, const VkPhysicalDeviceMultiviewFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceMultiviewFeaturesKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* multiview */
    structBody << "\t" << structInfo->multiview << "," << std::endl;
/* multiviewGeometryShader */
    structBody << "\t" << structInfo->multiviewGeometryShader << "," << std::endl;
/* multiviewTessellationShader */
    structBody << "\t" << structInfo->multiviewTessellationShader << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "physicalDeviceMultiviewFeatures");
        out << "VkPhysicalDeviceMultiviewFeaturesKHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPhysicalDeviceMultiviewPropertiesKHR(std::ostream &out, const VkPhysicalDeviceMultiviewPropertiesKHR* structInfo, Decoded_VkPhysicalDeviceMultiviewPropertiesKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* maxMultiviewViewCount */
    structBody << "\t" << structInfo->maxMultiviewViewCount << "," << std::endl;
/* maxMultiviewInstanceIndex */
    structBody << "\t" << structInfo->maxMultiviewInstanceIndex << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "physicalDeviceMultiviewProperties");
        out << "VkPhysicalDeviceMultiviewPropertiesKHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkRenderPassMultiviewCreateInfoKHR(std::ostream &out, const VkRenderPassMultiviewCreateInfoKHR* structInfo, Decoded_VkRenderPassMultiviewCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::string pCorrelationMasksArray = "NULL";
    if (structInfo->pCorrelationMasks != NULL) {
        pCorrelationMasksArray = "pCorrelationMasks_" + std::to_string(consumer.getNextId());
        out << "uint32_t " << pCorrelationMasksArray << "[] = " << VulkanCppConsumerBase::BuildValue(structInfo->pCorrelationMasks, structInfo->correlationMaskCount) << ";" << std::endl;
    }
    std::string pViewOffsetsArray = "NULL";
    if (structInfo->pViewOffsets != NULL) {
        pViewOffsetsArray = "pViewOffsets_" + std::to_string(consumer.getNextId());
        out << "int32_t " << pViewOffsetsArray << "[] = " << VulkanCppConsumerBase::BuildValue(structInfo->pViewOffsets, structInfo->dependencyCount) << ";" << std::endl;
    }
    std::string pViewMasksArray = "NULL";
    if (structInfo->pViewMasks != NULL) {
        pViewMasksArray = "pViewMasks_" + std::to_string(consumer.getNextId());
        out << "uint32_t " << pViewMasksArray << "[] = " << VulkanCppConsumerBase::BuildValue(structInfo->pViewMasks, structInfo->subpassCount) << ";" << std::endl;
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* subpassCount */
    structBody << "\t" << structInfo->subpassCount << "," << std::endl;
/* pViewMasks */
    structBody << "\t" << pViewMasksArray << "," << std::endl;
/* dependencyCount */
    structBody << "\t" << structInfo->dependencyCount << "," << std::endl;
/* pViewOffsets */
    structBody << "\t" << pViewOffsetsArray << "," << std::endl;
/* correlationMaskCount */
    structBody << "\t" << structInfo->correlationMaskCount << "," << std::endl;
/* pCorrelationMasks */
    structBody << "\t" << pCorrelationMasksArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "renderPassMultiviewCreateInfo");
        out << "VkRenderPassMultiviewCreateInfoKHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}


std::string GenerateStruct_VkFormatProperties2KHR(std::ostream &out, const VkFormatProperties2KHR* structInfo, Decoded_VkFormatProperties2KHR* metainfo, VulkanCppConsumerBase &consumer){
    std::string formatPropertiesInfoVar = GenerateStruct_VkFormatProperties(out,
                                                                         &structInfo->formatProperties,
                                                                         metainfo->formatProperties,
                                                                         consumer);
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* formatProperties */
    structBody << "\t" << formatPropertiesInfoVar << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "formatProperties2");
        out << "VkFormatProperties2KHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkImageFormatProperties2KHR(std::ostream &out, const VkImageFormatProperties2KHR* structInfo, Decoded_VkImageFormatProperties2KHR* metainfo, VulkanCppConsumerBase &consumer){
    std::string imageFormatPropertiesInfoVar = GenerateStruct_VkImageFormatProperties(out,
                                                                              &structInfo->imageFormatProperties,
                                                                              metainfo->imageFormatProperties,
                                                                              consumer);
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* imageFormatProperties */
    structBody << "\t" << imageFormatPropertiesInfoVar << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "imageFormatProperties2");
        out << "VkImageFormatProperties2KHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPhysicalDeviceFeatures2KHR(std::ostream &out, const VkPhysicalDeviceFeatures2KHR* structInfo, Decoded_VkPhysicalDeviceFeatures2KHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* features */
    std::string featuresInfoVar = "features_" + std::to_string(consumer.getNextId());
    out << "VkPhysicalDeviceFeatures " << featuresInfoVar + ";" << std::endl;
    structBody << "\t" << featuresInfoVar << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "physicalDeviceFeatures2");
        out << "VkPhysicalDeviceFeatures2KHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPhysicalDeviceImageFormatInfo2KHR(std::ostream &out, const VkPhysicalDeviceImageFormatInfo2KHR* structInfo, Decoded_VkPhysicalDeviceImageFormatInfo2KHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* format */
    structBody << "\t" << "VkFormat(" << structInfo->format << ")" << "," << std::endl;
/* type */
    structBody << "\t" << "VkImageType(" << structInfo->type << ")" << "," << std::endl;
/* tiling */
    structBody << "\t" << "VkImageTiling(" << structInfo->tiling << ")" << "," << std::endl;
/* usage */
    structBody << "\t" << "VkImageUsageFlags(" << structInfo->usage << ")" << "," << std::endl;
/* flags */
    structBody << "\t" << "VkImageCreateFlags(" << structInfo->flags << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "physicalDeviceImageFormatInfo2");
        out << "VkPhysicalDeviceImageFormatInfo2KHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPhysicalDeviceMemoryProperties2KHR(std::ostream &out, const VkPhysicalDeviceMemoryProperties2KHR* structInfo, Decoded_VkPhysicalDeviceMemoryProperties2KHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* memoryProperties */
    std::string memoryPropertiesInfoVar = "memoryProperties_" + std::to_string(consumer.getNextId());
    out << "VkPhysicalDeviceMemoryProperties " << memoryPropertiesInfoVar + ";" << std::endl;
    structBody << "\t" << memoryPropertiesInfoVar << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "physicalDeviceMemoryProperties2");
        out << "VkPhysicalDeviceMemoryProperties2KHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPhysicalDeviceProperties2KHR(std::ostream &out, const VkPhysicalDeviceProperties2KHR* structInfo, Decoded_VkPhysicalDeviceProperties2KHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* properties */
    std::string propertiesInfoVar = "properties_" + std::to_string(consumer.getNextId());
    out << "VkPhysicalDeviceProperties " << propertiesInfoVar + ";" << std::endl;
    structBody << "\t" << propertiesInfoVar << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "physicalDeviceProperties2");
        out << "VkPhysicalDeviceProperties2KHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPhysicalDeviceSparseImageFormatInfo2KHR(std::ostream &out, const VkPhysicalDeviceSparseImageFormatInfo2KHR* structInfo, Decoded_VkPhysicalDeviceSparseImageFormatInfo2KHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* format */
    structBody << "\t" << "VkFormat(" << structInfo->format << ")" << "," << std::endl;
/* type */
    structBody << "\t" << "VkImageType(" << structInfo->type << ")" << "," << std::endl;
/* samples */
    structBody << "\t" << "VkSampleCountFlagBits(" << structInfo->samples << ")" << "," << std::endl;
/* usage */
    structBody << "\t" << "VkImageUsageFlags(" << structInfo->usage << ")" << "," << std::endl;
/* tiling */
    structBody << "\t" << "VkImageTiling(" << structInfo->tiling << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "physicalDeviceSparseImageFormatInfo2");
        out << "VkPhysicalDeviceSparseImageFormatInfo2KHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkQueueFamilyProperties2KHR(std::ostream &out, const VkQueueFamilyProperties2KHR* structInfo, Decoded_VkQueueFamilyProperties2KHR* metainfo, VulkanCppConsumerBase &consumer){
    std::string queueFamilyPropertiesInfoVar = GenerateStruct_VkQueueFamilyProperties(out,
                                                                              &structInfo->queueFamilyProperties,
                                                                              metainfo->queueFamilyProperties,
                                                                              consumer);
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* queueFamilyProperties */
    structBody << "\t" << queueFamilyPropertiesInfoVar << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "queueFamilyProperties2");
        out << "VkQueueFamilyProperties2KHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSparseImageFormatProperties2KHR(std::ostream &out, const VkSparseImageFormatProperties2KHR* structInfo, Decoded_VkSparseImageFormatProperties2KHR* metainfo, VulkanCppConsumerBase &consumer){
    std::string propertiesInfoVar = GenerateStruct_VkSparseImageFormatProperties(out,
                                                                   &structInfo->properties,
                                                                   metainfo->properties,
                                                                   consumer);
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* properties */
    structBody << "\t" << propertiesInfoVar << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "sparseImageFormatProperties2");
        out << "VkSparseImageFormatProperties2KHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}




std::string GenerateStruct_VkAttachmentDescription2KHR(std::ostream &out, const VkAttachmentDescription2KHR* structInfo, Decoded_VkAttachmentDescription2KHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkAttachmentDescriptionFlags(" << structInfo->flags << ")" << "," << std::endl;
/* format */
    structBody << "\t" << "VkFormat(" << structInfo->format << ")" << "," << std::endl;
/* samples */
    structBody << "\t" << "VkSampleCountFlagBits(" << structInfo->samples << ")" << "," << std::endl;
/* loadOp */
    structBody << "\t" << "VkAttachmentLoadOp(" << structInfo->loadOp << ")" << "," << std::endl;
/* storeOp */
    structBody << "\t" << "VkAttachmentStoreOp(" << structInfo->storeOp << ")" << "," << std::endl;
/* stencilLoadOp */
    structBody << "\t" << "VkAttachmentLoadOp(" << structInfo->stencilLoadOp << ")" << "," << std::endl;
/* stencilStoreOp */
    structBody << "\t" << "VkAttachmentStoreOp(" << structInfo->stencilStoreOp << ")" << "," << std::endl;
/* initialLayout */
    structBody << "\t" << "VkImageLayout(" << structInfo->initialLayout << ")" << "," << std::endl;
/* finalLayout */
    structBody << "\t" << "VkImageLayout(" << structInfo->finalLayout << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "attachmentDescription2");
        out << "VkAttachmentDescription2KHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkAttachmentReference2KHR(std::ostream &out, const VkAttachmentReference2KHR* structInfo, Decoded_VkAttachmentReference2KHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* attachment */
    structBody << "\t" << structInfo->attachment << "," << std::endl;
/* layout */
    structBody << "\t" << "VkImageLayout(" << structInfo->layout << ")" << "," << std::endl;
/* aspectMask */
    structBody << "\t" << "VkImageAspectFlags(" << structInfo->aspectMask << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "attachmentReference2");
        out << "VkAttachmentReference2KHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkRenderPassCreateInfo2KHR(std::ostream &out, const VkRenderPassCreateInfo2KHR* structInfo, Decoded_VkRenderPassCreateInfo2KHR* metainfo, VulkanCppConsumerBase &consumer){
    std::string pCorrelatedViewMasksArray = "NULL";
    if (structInfo->pCorrelatedViewMasks != NULL) {
        pCorrelatedViewMasksArray = "pCorrelatedViewMasks_" + std::to_string(consumer.getNextId());
        out << "uint32_t " << pCorrelatedViewMasksArray << "[] = " << VulkanCppConsumerBase::BuildValue(structInfo->pCorrelatedViewMasks, structInfo->correlatedViewMaskCount) << ";" << std::endl;
    }
    std::string pDependenciesArray = "NULL";
    if (structInfo->pDependencies != NULL) {
        pDependenciesArray = "pDependencies_" + std::to_string(consumer.getNextId());
        std::string pDependenciesNames;
        for (uint32_t idx = 0; idx < structInfo->dependencyCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pDependencies + idx != NULL) {
                varName = GenerateStruct_VkSubpassDependency2KHR(out,
                                                         structInfo->pDependencies + idx,
                                                         metainfo->pDependencies->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pDependenciesNames += varName + ", ";
        }
        out << "VkSubpassDependency2KHR " << pDependenciesArray << "[] = {" << pDependenciesNames << "};" << std::endl;
    }
    std::string pSubpassesArray = "NULL";
    if (structInfo->pSubpasses != NULL) {
        pSubpassesArray = "pSubpasses_" + std::to_string(consumer.getNextId());
        std::string pSubpassesNames;
        for (uint32_t idx = 0; idx < structInfo->subpassCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pSubpasses + idx != NULL) {
                varName = GenerateStruct_VkSubpassDescription2KHR(out,
                                                         structInfo->pSubpasses + idx,
                                                         metainfo->pSubpasses->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pSubpassesNames += varName + ", ";
        }
        out << "VkSubpassDescription2KHR " << pSubpassesArray << "[] = {" << pSubpassesNames << "};" << std::endl;
    }
    std::string pAttachmentsArray = "NULL";
    if (structInfo->pAttachments != NULL) {
        pAttachmentsArray = "pAttachments_" + std::to_string(consumer.getNextId());
        std::string pAttachmentsNames;
        for (uint32_t idx = 0; idx < structInfo->attachmentCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pAttachments + idx != NULL) {
                varName = GenerateStruct_VkAttachmentDescription2KHR(out,
                                                         structInfo->pAttachments + idx,
                                                         metainfo->pAttachments->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pAttachmentsNames += varName + ", ";
        }
        out << "VkAttachmentDescription2KHR " << pAttachmentsArray << "[] = {" << pAttachmentsNames << "};" << std::endl;
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkRenderPassCreateFlags(" << structInfo->flags << ")" << "," << std::endl;
/* attachmentCount */
    structBody << "\t" << structInfo->attachmentCount << "," << std::endl;
/* pAttachments */
    structBody << "\t" << pAttachmentsArray << "," << std::endl;
/* subpassCount */
    structBody << "\t" << structInfo->subpassCount << "," << std::endl;
/* pSubpasses */
    structBody << "\t" << pSubpassesArray << "," << std::endl;
/* dependencyCount */
    structBody << "\t" << structInfo->dependencyCount << "," << std::endl;
/* pDependencies */
    structBody << "\t" << pDependenciesArray << "," << std::endl;
/* correlatedViewMaskCount */
    structBody << "\t" << structInfo->correlatedViewMaskCount << "," << std::endl;
/* pCorrelatedViewMasks */
    structBody << "\t" << pCorrelatedViewMasksArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "renderPassCreateInfo2");
        out << "VkRenderPassCreateInfo2KHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSubpassBeginInfoKHR(std::ostream &out, const VkSubpassBeginInfoKHR* structInfo, Decoded_VkSubpassBeginInfoKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* contents */
    structBody << "\t" << "VkSubpassContents(" << structInfo->contents << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "subpassBeginInfo");
        out << "VkSubpassBeginInfoKHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSubpassDependency2KHR(std::ostream &out, const VkSubpassDependency2KHR* structInfo, Decoded_VkSubpassDependency2KHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* srcSubpass */
    structBody << "\t" << structInfo->srcSubpass << "," << std::endl;
/* dstSubpass */
    structBody << "\t" << structInfo->dstSubpass << "," << std::endl;
/* srcStageMask */
    structBody << "\t" << "VkPipelineStageFlags(" << structInfo->srcStageMask << ")" << "," << std::endl;
/* dstStageMask */
    structBody << "\t" << "VkPipelineStageFlags(" << structInfo->dstStageMask << ")" << "," << std::endl;
/* srcAccessMask */
    structBody << "\t" << "VkAccessFlags(" << structInfo->srcAccessMask << ")" << "," << std::endl;
/* dstAccessMask */
    structBody << "\t" << "VkAccessFlags(" << structInfo->dstAccessMask << ")" << "," << std::endl;
/* dependencyFlags */
    structBody << "\t" << "VkDependencyFlags(" << structInfo->dependencyFlags << ")" << "," << std::endl;
/* viewOffset */
    structBody << "\t" << structInfo->viewOffset << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "subpassDependency2");
        out << "VkSubpassDependency2KHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSubpassDescription2KHR(std::ostream &out, const VkSubpassDescription2KHR* structInfo, Decoded_VkSubpassDescription2KHR* metainfo, VulkanCppConsumerBase &consumer){
    std::string pPreserveAttachmentsArray = "NULL";
    if (structInfo->pPreserveAttachments != NULL) {
        pPreserveAttachmentsArray = "pPreserveAttachments_" + std::to_string(consumer.getNextId());
        out << "uint32_t " << pPreserveAttachmentsArray << "[] = " << VulkanCppConsumerBase::BuildValue(structInfo->pPreserveAttachments, structInfo->preserveAttachmentCount) << ";" << std::endl;
    }
    std::string pDepthStencilAttachmentStruct = "NULL";
    if (structInfo->pDepthStencilAttachment != NULL) {
        pDepthStencilAttachmentStruct = GenerateStruct_VkAttachmentReference2KHR(out,
                                                                       structInfo->pDepthStencilAttachment,
                                                                       metainfo->pDepthStencilAttachment->GetMetaStructPointer(),
                                                                       consumer);
        pDepthStencilAttachmentStruct.insert(0, "&");
    }
    std::string pResolveAttachmentsArray = "NULL";
    if (structInfo->pResolveAttachments != NULL) {
        pResolveAttachmentsArray = "pResolveAttachments_" + std::to_string(consumer.getNextId());
        std::string pResolveAttachmentsNames;
        for (uint32_t idx = 0; idx < structInfo->colorAttachmentCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pResolveAttachments + idx != NULL) {
                varName = GenerateStruct_VkAttachmentReference2KHR(out,
                                                         structInfo->pResolveAttachments + idx,
                                                         metainfo->pResolveAttachments->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pResolveAttachmentsNames += varName + ", ";
        }
        out << "VkAttachmentReference2KHR " << pResolveAttachmentsArray << "[] = {" << pResolveAttachmentsNames << "};" << std::endl;
    }
    std::string pColorAttachmentsArray = "NULL";
    if (structInfo->pColorAttachments != NULL) {
        pColorAttachmentsArray = "pColorAttachments_" + std::to_string(consumer.getNextId());
        std::string pColorAttachmentsNames;
        for (uint32_t idx = 0; idx < structInfo->colorAttachmentCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pColorAttachments + idx != NULL) {
                varName = GenerateStruct_VkAttachmentReference2KHR(out,
                                                         structInfo->pColorAttachments + idx,
                                                         metainfo->pColorAttachments->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pColorAttachmentsNames += varName + ", ";
        }
        out << "VkAttachmentReference2KHR " << pColorAttachmentsArray << "[] = {" << pColorAttachmentsNames << "};" << std::endl;
    }
    std::string pInputAttachmentsArray = "NULL";
    if (structInfo->pInputAttachments != NULL) {
        pInputAttachmentsArray = "pInputAttachments_" + std::to_string(consumer.getNextId());
        std::string pInputAttachmentsNames;
        for (uint32_t idx = 0; idx < structInfo->inputAttachmentCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pInputAttachments + idx != NULL) {
                varName = GenerateStruct_VkAttachmentReference2KHR(out,
                                                         structInfo->pInputAttachments + idx,
                                                         metainfo->pInputAttachments->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pInputAttachmentsNames += varName + ", ";
        }
        out << "VkAttachmentReference2KHR " << pInputAttachmentsArray << "[] = {" << pInputAttachmentsNames << "};" << std::endl;
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* flags */
    structBody << "\t" << "VkSubpassDescriptionFlags(" << structInfo->flags << ")" << "," << std::endl;
/* pipelineBindPoint */
    structBody << "\t" << "VkPipelineBindPoint(" << structInfo->pipelineBindPoint << ")" << "," << std::endl;
/* viewMask */
    structBody << "\t" << structInfo->viewMask << "," << std::endl;
/* inputAttachmentCount */
    structBody << "\t" << structInfo->inputAttachmentCount << "," << std::endl;
/* pInputAttachments */
    structBody << "\t" << pInputAttachmentsArray << "," << std::endl;
/* colorAttachmentCount */
    structBody << "\t" << structInfo->colorAttachmentCount << "," << std::endl;
/* pColorAttachments */
    structBody << "\t" << pColorAttachmentsArray << "," << std::endl;
/* pResolveAttachments */
    structBody << "\t" << pResolveAttachmentsArray << "," << std::endl;
/* pDepthStencilAttachment */
    structBody << "\t" << pDepthStencilAttachmentStruct << "," << std::endl;
/* preserveAttachmentCount */
    structBody << "\t" << structInfo->preserveAttachmentCount << "," << std::endl;
/* pPreserveAttachments */
    structBody << "\t" << pPreserveAttachmentsArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "subpassDescription2");
        out << "VkSubpassDescription2KHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSubpassEndInfoKHR(std::ostream &out, const VkSubpassEndInfoKHR* structInfo, Decoded_VkSubpassEndInfoKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "subpassEndInfo");
        out << "VkSubpassEndInfoKHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}


std::string GenerateStruct_VkImageViewUsageCreateInfoKHR(std::ostream &out, const VkImageViewUsageCreateInfoKHR* structInfo, Decoded_VkImageViewUsageCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* usage */
    structBody << "\t" << "VkImageUsageFlags(" << structInfo->usage << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "imageViewUsageCreateInfo");
        out << "VkImageViewUsageCreateInfoKHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkInputAttachmentAspectReferenceKHR(std::ostream &out, const VkInputAttachmentAspectReferenceKHR* structInfo, Decoded_VkInputAttachmentAspectReferenceKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* subpass */
    structBody << "\t" << structInfo->subpass << "," << std::endl;
/* inputAttachmentIndex */
    structBody << "\t" << structInfo->inputAttachmentIndex << "," << std::endl;
/* aspectMask */
    structBody << "\t" << "VkImageAspectFlags(" << structInfo->aspectMask << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "inputAttachmentAspectReference");
        out << "VkInputAttachmentAspectReferenceKHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPhysicalDevicePointClippingPropertiesKHR(std::ostream &out, const VkPhysicalDevicePointClippingPropertiesKHR* structInfo, Decoded_VkPhysicalDevicePointClippingPropertiesKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* pointClippingBehavior */
    structBody << "\t" << "VkPointClippingBehaviorKHR(" << structInfo->pointClippingBehavior << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "physicalDevicePointClippingProperties");
        out << "VkPhysicalDevicePointClippingPropertiesKHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPipelineTessellationDomainOriginStateCreateInfoKHR(std::ostream &out, const VkPipelineTessellationDomainOriginStateCreateInfoKHR* structInfo, Decoded_VkPipelineTessellationDomainOriginStateCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* domainOrigin */
    structBody << "\t" << "VkTessellationDomainOriginKHR(" << structInfo->domainOrigin << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "pipelineTessellationDomainOriginStateCreateInfo");
        out << "VkPipelineTessellationDomainOriginStateCreateInfoKHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkRenderPassInputAttachmentAspectCreateInfoKHR(std::ostream &out, const VkRenderPassInputAttachmentAspectCreateInfoKHR* structInfo, Decoded_VkRenderPassInputAttachmentAspectCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::string pAspectReferencesArray = "NULL";
    if (structInfo->pAspectReferences != NULL) {
        pAspectReferencesArray = "pAspectReferences_" + std::to_string(consumer.getNextId());
        std::string pAspectReferencesNames;
        for (uint32_t idx = 0; idx < structInfo->aspectReferenceCount; idx++) {
            std::string varName = "NULL";
            if (structInfo->pAspectReferences + idx != NULL) {
                varName = GenerateStruct_VkInputAttachmentAspectReferenceKHR(out,
                                                         structInfo->pAspectReferences + idx,
                                                         metainfo->pAspectReferences->GetMetaStructPointer() + idx,
                                                         consumer);
            }
            pAspectReferencesNames += varName + ", ";
        }
        out << "VkInputAttachmentAspectReferenceKHR " << pAspectReferencesArray << "[] = {" << pAspectReferencesNames << "};" << std::endl;
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* aspectReferenceCount */
    structBody << "\t" << structInfo->aspectReferenceCount << "," << std::endl;
/* pAspectReferences */
    structBody << "\t" << pAspectReferencesArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "renderPassInputAttachmentAspectCreateInfo");
        out << "VkRenderPassInputAttachmentAspectCreateInfoKHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}


std::string GenerateStruct_VkBufferMemoryRequirementsInfo2KHR(std::ostream &out, const VkBufferMemoryRequirementsInfo2KHR* structInfo, Decoded_VkBufferMemoryRequirementsInfo2KHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* buffer */
    structBody << "\t" << consumer.GetHandle(metainfo->buffer) << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "bufferMemoryRequirementsInfo2");
        out << "VkBufferMemoryRequirementsInfo2KHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkImageMemoryRequirementsInfo2KHR(std::ostream &out, const VkImageMemoryRequirementsInfo2KHR* structInfo, Decoded_VkImageMemoryRequirementsInfo2KHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* image */
    structBody << "\t" << consumer.GetHandle(metainfo->image) << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "imageMemoryRequirementsInfo2");
        out << "VkImageMemoryRequirementsInfo2KHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkImageSparseMemoryRequirementsInfo2KHR(std::ostream &out, const VkImageSparseMemoryRequirementsInfo2KHR* structInfo, Decoded_VkImageSparseMemoryRequirementsInfo2KHR* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* image */
    structBody << "\t" << consumer.GetHandle(metainfo->image) << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "imageSparseMemoryRequirementsInfo2");
        out << "VkImageSparseMemoryRequirementsInfo2KHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkMemoryRequirements2KHR(std::ostream &out, const VkMemoryRequirements2KHR* structInfo, Decoded_VkMemoryRequirements2KHR* metainfo, VulkanCppConsumerBase &consumer){
    std::string memoryRequirementsInfoVar = GenerateStruct_VkMemoryRequirements(out,
                                                                           &structInfo->memoryRequirements,
                                                                           metainfo->memoryRequirements,
                                                                           consumer);
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* memoryRequirements */
    structBody << "\t" << memoryRequirementsInfoVar << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "memoryRequirements2");
        out << "VkMemoryRequirements2KHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkSparseImageMemoryRequirements2KHR(std::ostream &out, const VkSparseImageMemoryRequirements2KHR* structInfo, Decoded_VkSparseImageMemoryRequirements2KHR* metainfo, VulkanCppConsumerBase &consumer){
    std::string memoryRequirementsInfoVar = GenerateStruct_VkSparseImageMemoryRequirements(out,
                                                                           &structInfo->memoryRequirements,
                                                                           metainfo->memoryRequirements,
                                                                           consumer);
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* memoryRequirements */
    structBody << "\t" << memoryRequirementsInfoVar << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "sparseImageMemoryRequirements2");
        out << "VkSparseImageMemoryRequirements2KHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}


std::string GenerateStruct_VkImageFormatListCreateInfoKHR(std::ostream &out, const VkImageFormatListCreateInfoKHR* structInfo, Decoded_VkImageFormatListCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer){
    std::string pViewFormatsValues;
    std::string pViewFormatsArray = "NULL";
    if (structInfo->pViewFormats != NULL) {
        for (uint32_t idx = 0; idx < structInfo->viewFormatCount; idx++) {
            pViewFormatsValues += util::ToString<VkFormat>(structInfo->pViewFormats[idx]) + ", ";
        }
        pViewFormatsArray = "pViewFormats_" + std::to_string(consumer.getNextId());
        out << "VkFormat " << pViewFormatsArray << "[] = {" << pViewFormatsValues << "};" << std::endl;
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* viewFormatCount */
    structBody << "\t" << structInfo->viewFormatCount << "," << std::endl;
/* pViewFormats */
    structBody << "\t" << pViewFormatsArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "imageFormatListCreateInfo");
        out << "VkImageFormatListCreateInfoKHR " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}




std::string GenerateStruct_VkDescriptorPoolInlineUniformBlockCreateInfoEXT(std::ostream &out, const VkDescriptorPoolInlineUniformBlockCreateInfoEXT* structInfo, Decoded_VkDescriptorPoolInlineUniformBlockCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* maxInlineUniformBlockBindings */
    structBody << "\t" << structInfo->maxInlineUniformBlockBindings << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "descriptorPoolInlineUniformBlockCreateInfo");
        out << "VkDescriptorPoolInlineUniformBlockCreateInfoEXT " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPhysicalDeviceInlineUniformBlockFeaturesEXT(std::ostream &out, const VkPhysicalDeviceInlineUniformBlockFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceInlineUniformBlockFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* inlineUniformBlock */
    structBody << "\t" << structInfo->inlineUniformBlock << "," << std::endl;
/* descriptorBindingInlineUniformBlockUpdateAfterBind */
    structBody << "\t" << structInfo->descriptorBindingInlineUniformBlockUpdateAfterBind << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "physicalDeviceInlineUniformBlockFeatures");
        out << "VkPhysicalDeviceInlineUniformBlockFeaturesEXT " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkPhysicalDeviceInlineUniformBlockPropertiesEXT(std::ostream &out, const VkPhysicalDeviceInlineUniformBlockPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceInlineUniformBlockPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* maxInlineUniformBlockSize */
    structBody << "\t" << structInfo->maxInlineUniformBlockSize << "," << std::endl;
/* maxPerStageDescriptorInlineUniformBlocks */
    structBody << "\t" << structInfo->maxPerStageDescriptorInlineUniformBlocks << "," << std::endl;
/* maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks */
    structBody << "\t" << structInfo->maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks << "," << std::endl;
/* maxDescriptorSetInlineUniformBlocks */
    structBody << "\t" << structInfo->maxDescriptorSetInlineUniformBlocks << "," << std::endl;
/* maxDescriptorSetUpdateAfterBindInlineUniformBlocks */
    structBody << "\t" << structInfo->maxDescriptorSetUpdateAfterBindInlineUniformBlocks << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "physicalDeviceInlineUniformBlockProperties");
        out << "VkPhysicalDeviceInlineUniformBlockPropertiesEXT " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

std::string GenerateStruct_VkWriteDescriptorSetInlineUniformBlockEXT(std::ostream &out, const VkWriteDescriptorSetInlineUniformBlockEXT* structInfo, Decoded_VkWriteDescriptorSetInlineUniformBlockEXT* metainfo, VulkanCppConsumerBase &consumer){
    std::string pDataArray = "NULL";
    if (structInfo->pData != NULL) {
        std::string pDataValues;
        const uint8_t* pDataPointer = (uint8_t*)structInfo->pData;
        for (uint32_t idx = 0; idx < structInfo->dataSize; idx++) {
            pDataValues += std::to_string(pDataPointer[idx]) + ", ";
        }
        pDataArray = "pData_" + std::to_string(consumer.getNextId());
        out << "uint8_t " << pDataArray << "[] = {" << pDataValues << "};" << std::endl;
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* dataSize */
    structBody << "\t" << structInfo->dataSize << "," << std::endl;
/* pData */
    structBody << "\t" << pDataArray << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "writeDescriptorSetInlineUniformBlock");
        out << "VkWriteDescriptorSetInlineUniformBlockEXT " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}


std::string GenerateStruct_VkPhysicalDeviceMemoryBudgetPropertiesEXT(std::ostream &out, const VkPhysicalDeviceMemoryBudgetPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer){
    std::string heapUsageArray = "heapUsageArray_" + std::to_string(consumer.getNextId());
    if (VK_MAX_MEMORY_HEAPS > 0) {
        std::string heapUsageValues = toStringJoin(structInfo->heapUsage,
                                                   structInfo->heapUsage + VK_MAX_MEMORY_HEAPS,
                                                   [](VkDeviceSize current) { return std::to_string(current); },
                                                   ", ");
        if (VK_MAX_MEMORY_HEAPS == 1) {
            heapUsageArray = "&" + heapUsageValues;
        } else if (VK_MAX_MEMORY_HEAPS > 1) {
            out << "VkDeviceSize " << heapUsageArray << "[] = {" << heapUsageValues << "};" << std::endl;
        }
    }
    std::string heapBudgetArray = "heapBudgetArray_" + std::to_string(consumer.getNextId());
    if (VK_MAX_MEMORY_HEAPS > 0) {
        std::string heapBudgetValues = toStringJoin(structInfo->heapBudget,
                                                    structInfo->heapBudget + VK_MAX_MEMORY_HEAPS,
                                                    [](VkDeviceSize current) { return std::to_string(current); },
                                                    ", ");
        if (VK_MAX_MEMORY_HEAPS == 1) {
            heapBudgetArray = "&" + heapBudgetValues;
        } else if (VK_MAX_MEMORY_HEAPS > 1) {
            out << "VkDeviceSize " << heapBudgetArray << "[] = {" << heapBudgetValues << "};" << std::endl;
        }
    }
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* heapBudget */
    structBody << "\t" << "{ *" << heapBudgetArray << " }" << "," << std::endl;
/* heapUsage */
    structBody << "\t" << "{ *" << heapUsageArray << " }" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "physicalDeviceMemoryBudgetPropertiesEXT");
        out << "VkPhysicalDeviceMemoryBudgetPropertiesEXT " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}


std::string GenerateStruct_VkImageStencilUsageCreateInfoEXT(std::ostream &out, const VkImageStencilUsageCreateInfoEXT* structInfo, Decoded_VkImageStencilUsageCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer){
    std::stringstream structBody;
/* sType */
    structBody << "\t" << "VkStructureType(" << structInfo->sType << ")" << "," << std::endl;
/* pNext */
    std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    structBody << "\t" << pNextName << "," << std::endl;
/* stencilUsage */
    structBody << "\t" << "VkImageUsageFlags(" << structInfo->stencilUsage << ")" << "," ;
    std::string varname = consumer.GetExistingStruct(structBody);
    if (!varname.length()) {
        varname = consumer.AddStruct(structBody, "imageStencilUsageCreateInfo");
        out << "VkImageStencilUsageCreateInfoEXT " << varname << " {" << std::endl;
        out << structBody.str() << std::endl;
        out << "};" << std::endl;
    }
    return varname;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

