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

#include "generated/generated_vulkan_referenced_resource_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanReferencedResourceConsumer::Process_vkBeginCommandBuffer(
    const ApiCallInfo&                          call_info,
    args::BeginCommandBuffer&                   args)
{
    if (!args.pBeginInfo.IsNull() && (args.pBeginInfo.HasData()))
    {
        auto pBeginInfo_ptr = args.pBeginInfo.GetMetaStructPointer();
        if (!pBeginInfo_ptr->pInheritanceInfo->IsNull() && (pBeginInfo_ptr->pInheritanceInfo->HasData()))
        {
            auto pInheritanceInfo_ptr = pBeginInfo_ptr->pInheritanceInfo->GetMetaStructPointer();
            GetTable().AddResourceToUser(args.commandBuffer, pInheritanceInfo_ptr->framebuffer);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBuffer&                        args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.srcBuffer);
    GetTable().AddResourceToUser(args.commandBuffer, args.dstBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyImage(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImage&                         args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.srcImage);
    GetTable().AddResourceToUser(args.commandBuffer, args.dstImage);
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyBufferToImage(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBufferToImage&                 args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.srcBuffer);
    GetTable().AddResourceToUser(args.commandBuffer, args.dstImage);
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyImageToBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToBuffer&                 args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.srcImage);
    GetTable().AddResourceToUser(args.commandBuffer, args.dstBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdUpdateBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdUpdateBuffer&                      args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.dstBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdFillBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdFillBuffer&                        args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.dstBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdPipelineBarrier(
    const ApiCallInfo&                          call_info,
    args::CmdPipelineBarrier&                   args)
{
    if (!args.pBufferMemoryBarriers.IsNull() && (args.pBufferMemoryBarriers.HasData()))
    {
        auto pBufferMemoryBarriers_ptr = args.pBufferMemoryBarriers.GetMetaStructPointer();
        size_t pBufferMemoryBarriers_count = args.pBufferMemoryBarriers.GetLength();
        for (size_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pBufferMemoryBarriers_count; ++pBufferMemoryBarriers_index)
        {
            GetTable().AddResourceToUser(args.commandBuffer, pBufferMemoryBarriers_ptr[pBufferMemoryBarriers_index].buffer);
        }
    }

    if (!args.pImageMemoryBarriers.IsNull() && (args.pImageMemoryBarriers.HasData()))
    {
        auto pImageMemoryBarriers_ptr = args.pImageMemoryBarriers.GetMetaStructPointer();
        size_t pImageMemoryBarriers_count = args.pImageMemoryBarriers.GetLength();
        for (size_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pImageMemoryBarriers_count; ++pImageMemoryBarriers_index)
        {
            GetTable().AddResourceToUser(args.commandBuffer, pImageMemoryBarriers_ptr[pImageMemoryBarriers_index].image);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyQueryPoolResults(
    const ApiCallInfo&                          call_info,
    args::CmdCopyQueryPoolResults&              args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.dstBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    args::CmdExecuteCommands&                   args)
{
    if (!args.pCommandBuffers.IsNull() && (args.pCommandBuffers.HasData()))
    {
        auto pCommandBuffers_ptr = args.pCommandBuffers.GetPointer();
        size_t pCommandBuffers_count = args.pCommandBuffers.GetLength();
        for (size_t pCommandBuffers_index = 0; pCommandBuffers_index < pCommandBuffers_count; ++pCommandBuffers_index)
        {
            GetTable().AddUserToUser(args.commandBuffer, pCommandBuffers_ptr[pCommandBuffers_index]);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    args::CmdBindPipeline&                      args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.pipeline);
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindDescriptorSets(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorSets&                args)
{
    if (!args.pDescriptorSets.IsNull() && (args.pDescriptorSets.HasData()))
    {
        auto pDescriptorSets_ptr = args.pDescriptorSets.GetPointer();
        size_t pDescriptorSets_count = args.pDescriptorSets.GetLength();
        for (size_t pDescriptorSets_index = 0; pDescriptorSets_index < pDescriptorSets_count; ++pDescriptorSets_index)
        {
            GetTable().AddContainerToUser(args.commandBuffer, pDescriptorSets_ptr[pDescriptorSets_index]);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdClearColorImage(
    const ApiCallInfo&                          call_info,
    args::CmdClearColorImage&                   args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.image);
}

void VulkanReferencedResourceConsumer::Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchIndirect&                  args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.buffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdWaitEvents(
    const ApiCallInfo&                          call_info,
    args::CmdWaitEvents&                        args)
{
    if (!args.pBufferMemoryBarriers.IsNull() && (args.pBufferMemoryBarriers.HasData()))
    {
        auto pBufferMemoryBarriers_ptr = args.pBufferMemoryBarriers.GetMetaStructPointer();
        size_t pBufferMemoryBarriers_count = args.pBufferMemoryBarriers.GetLength();
        for (size_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pBufferMemoryBarriers_count; ++pBufferMemoryBarriers_index)
        {
            GetTable().AddResourceToUser(args.commandBuffer, pBufferMemoryBarriers_ptr[pBufferMemoryBarriers_index].buffer);
        }
    }

    if (!args.pImageMemoryBarriers.IsNull() && (args.pImageMemoryBarriers.HasData()))
    {
        auto pImageMemoryBarriers_ptr = args.pImageMemoryBarriers.GetMetaStructPointer();
        size_t pImageMemoryBarriers_count = args.pImageMemoryBarriers.GetLength();
        for (size_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pImageMemoryBarriers_count; ++pImageMemoryBarriers_index)
        {
            GetTable().AddResourceToUser(args.commandBuffer, pImageMemoryBarriers_ptr[pImageMemoryBarriers_index].image);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindIndexBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer&                   args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.buffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindVertexBuffers(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers&                 args)
{
    if (!args.pBuffers.IsNull() && (args.pBuffers.HasData()))
    {
        auto pBuffers_ptr = args.pBuffers.GetPointer();
        size_t pBuffers_count = args.pBuffers.GetLength();
        for (size_t pBuffers_index = 0; pBuffers_index < pBuffers_count; ++pBuffers_index)
        {
            GetTable().AddResourceToUser(args.commandBuffer, pBuffers_ptr[pBuffers_index]);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawIndirect(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirect&                      args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.buffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawIndexedIndirect(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirect&               args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.buffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdBlitImage(
    const ApiCallInfo&                          call_info,
    args::CmdBlitImage&                         args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.srcImage);
    GetTable().AddResourceToUser(args.commandBuffer, args.dstImage);
}

void VulkanReferencedResourceConsumer::Process_vkCmdClearDepthStencilImage(
    const ApiCallInfo&                          call_info,
    args::CmdClearDepthStencilImage&            args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.image);
}

void VulkanReferencedResourceConsumer::Process_vkCmdResolveImage(
    const ApiCallInfo&                          call_info,
    args::CmdResolveImage&                      args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.srcImage);
    GetTable().AddResourceToUser(args.commandBuffer, args.dstImage);
}

void VulkanReferencedResourceConsumer::Process_vkCmdBeginRenderPass(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderPass&                   args)
{
    if (!args.pRenderPassBegin.IsNull() && (args.pRenderPassBegin.HasData()))
    {
        auto pRenderPassBegin_ptr = args.pRenderPassBegin.GetMetaStructPointer();
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkRenderPassAttachmentBeginInfo>(pRenderPassBegin_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                if (!ext_struct_info->pAttachments.IsNull() && (ext_struct_info->pAttachments.HasData()))
                {
                    auto pAttachments_ptr = ext_struct_info->pAttachments.GetPointer();
                    size_t pAttachments_count = ext_struct_info->pAttachments.GetLength();
                    for (size_t pAttachments_index = 0; pAttachments_index < pAttachments_count; ++pAttachments_index)
                    {
                        GetTable().AddResourceToUser(args.commandBuffer, pAttachments_ptr[pAttachments_index]);
                    }
                }
            }
        }
        GetTable().AddResourceToUser(args.commandBuffer, pRenderPassBegin_ptr->framebuffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawIndirectCount(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCount&                 args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.buffer);
    GetTable().AddResourceToUser(args.commandBuffer, args.countBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawIndexedIndirectCount(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCount&          args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.buffer);
    GetTable().AddResourceToUser(args.commandBuffer, args.countBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderPass2&                  args)
{
    if (!args.pRenderPassBegin.IsNull() && (args.pRenderPassBegin.HasData()))
    {
        auto pRenderPassBegin_ptr = args.pRenderPassBegin.GetMetaStructPointer();
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkRenderPassAttachmentBeginInfo>(pRenderPassBegin_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                if (!ext_struct_info->pAttachments.IsNull() && (ext_struct_info->pAttachments.HasData()))
                {
                    auto pAttachments_ptr = ext_struct_info->pAttachments.GetPointer();
                    size_t pAttachments_count = ext_struct_info->pAttachments.GetLength();
                    for (size_t pAttachments_index = 0; pAttachments_index < pAttachments_count; ++pAttachments_index)
                    {
                        GetTable().AddResourceToUser(args.commandBuffer, pAttachments_ptr[pAttachments_index]);
                    }
                }
            }
        }
        GetTable().AddResourceToUser(args.commandBuffer, pRenderPassBegin_ptr->framebuffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    args::CmdPipelineBarrier2&                  args)
{
    if (!args.pDependencyInfo.IsNull() && (args.pDependencyInfo.HasData()))
    {
        auto pDependencyInfo_ptr = args.pDependencyInfo.GetMetaStructPointer();
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkTensorDependencyInfoARM>(pDependencyInfo_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                if (!ext_struct_info->pTensorMemoryBarriers->IsNull() && (ext_struct_info->pTensorMemoryBarriers->HasData()))
                {
                    auto pTensorMemoryBarriers_ptr = ext_struct_info->pTensorMemoryBarriers->GetMetaStructPointer();
                    size_t pTensorMemoryBarriers_count = ext_struct_info->pTensorMemoryBarriers->GetLength();
                    for (size_t pTensorMemoryBarriers_index = 0; pTensorMemoryBarriers_index < pTensorMemoryBarriers_count; ++pTensorMemoryBarriers_index)
                    {
                        GetTable().AddResourceToUser(args.commandBuffer, pTensorMemoryBarriers_ptr[pTensorMemoryBarriers_index].tensor);
                    }
                }
            }
        }
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkTensorMemoryBarrierARM>(pDependencyInfo_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                GetTable().AddResourceToUser(args.commandBuffer, ext_struct_info->tensor);
            }
        }

        if (!pDependencyInfo_ptr->pBufferMemoryBarriers->IsNull() && (pDependencyInfo_ptr->pBufferMemoryBarriers->HasData()))
        {
            auto pBufferMemoryBarriers_ptr = pDependencyInfo_ptr->pBufferMemoryBarriers->GetMetaStructPointer();
            size_t pBufferMemoryBarriers_count = pDependencyInfo_ptr->pBufferMemoryBarriers->GetLength();
            for (size_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pBufferMemoryBarriers_count; ++pBufferMemoryBarriers_index)
            {
                GetTable().AddResourceToUser(args.commandBuffer, pBufferMemoryBarriers_ptr[pBufferMemoryBarriers_index].buffer);
            }
        }

        if (!pDependencyInfo_ptr->pImageMemoryBarriers->IsNull() && (pDependencyInfo_ptr->pImageMemoryBarriers->HasData()))
        {
            auto pImageMemoryBarriers_ptr = pDependencyInfo_ptr->pImageMemoryBarriers->GetMetaStructPointer();
            size_t pImageMemoryBarriers_count = pDependencyInfo_ptr->pImageMemoryBarriers->GetLength();
            for (size_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pImageMemoryBarriers_count; ++pImageMemoryBarriers_index)
            {
                GetTable().AddResourceToUser(args.commandBuffer, pImageMemoryBarriers_ptr[pImageMemoryBarriers_index].image);
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBuffer2&                       args)
{
    if (!args.pCopyBufferInfo.IsNull() && (args.pCopyBufferInfo.HasData()))
    {
        auto pCopyBufferInfo_ptr = args.pCopyBufferInfo.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pCopyBufferInfo_ptr->srcBuffer);
        GetTable().AddResourceToUser(args.commandBuffer, pCopyBufferInfo_ptr->dstBuffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImage2&                        args)
{
    if (!args.pCopyImageInfo.IsNull() && (args.pCopyImageInfo.HasData()))
    {
        auto pCopyImageInfo_ptr = args.pCopyImageInfo.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pCopyImageInfo_ptr->srcImage);
        GetTable().AddResourceToUser(args.commandBuffer, pCopyImageInfo_ptr->dstImage);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBufferToImage2&                args)
{
    if (!args.pCopyBufferToImageInfo.IsNull() && (args.pCopyBufferToImageInfo.HasData()))
    {
        auto pCopyBufferToImageInfo_ptr = args.pCopyBufferToImageInfo.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pCopyBufferToImageInfo_ptr->srcBuffer);
        GetTable().AddResourceToUser(args.commandBuffer, pCopyBufferToImageInfo_ptr->dstImage);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToBuffer2&                args)
{
    if (!args.pCopyImageToBufferInfo.IsNull() && (args.pCopyImageToBufferInfo.HasData()))
    {
        auto pCopyImageToBufferInfo_ptr = args.pCopyImageToBufferInfo.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pCopyImageToBufferInfo_ptr->srcImage);
        GetTable().AddResourceToUser(args.commandBuffer, pCopyImageToBufferInfo_ptr->dstBuffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    args::CmdSetEvent2&                         args)
{
    if (!args.pDependencyInfo.IsNull() && (args.pDependencyInfo.HasData()))
    {
        auto pDependencyInfo_ptr = args.pDependencyInfo.GetMetaStructPointer();
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkTensorDependencyInfoARM>(pDependencyInfo_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                if (!ext_struct_info->pTensorMemoryBarriers->IsNull() && (ext_struct_info->pTensorMemoryBarriers->HasData()))
                {
                    auto pTensorMemoryBarriers_ptr = ext_struct_info->pTensorMemoryBarriers->GetMetaStructPointer();
                    size_t pTensorMemoryBarriers_count = ext_struct_info->pTensorMemoryBarriers->GetLength();
                    for (size_t pTensorMemoryBarriers_index = 0; pTensorMemoryBarriers_index < pTensorMemoryBarriers_count; ++pTensorMemoryBarriers_index)
                    {
                        GetTable().AddResourceToUser(args.commandBuffer, pTensorMemoryBarriers_ptr[pTensorMemoryBarriers_index].tensor);
                    }
                }
            }
        }
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkTensorMemoryBarrierARM>(pDependencyInfo_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                GetTable().AddResourceToUser(args.commandBuffer, ext_struct_info->tensor);
            }
        }

        if (!pDependencyInfo_ptr->pBufferMemoryBarriers->IsNull() && (pDependencyInfo_ptr->pBufferMemoryBarriers->HasData()))
        {
            auto pBufferMemoryBarriers_ptr = pDependencyInfo_ptr->pBufferMemoryBarriers->GetMetaStructPointer();
            size_t pBufferMemoryBarriers_count = pDependencyInfo_ptr->pBufferMemoryBarriers->GetLength();
            for (size_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pBufferMemoryBarriers_count; ++pBufferMemoryBarriers_index)
            {
                GetTable().AddResourceToUser(args.commandBuffer, pBufferMemoryBarriers_ptr[pBufferMemoryBarriers_index].buffer);
            }
        }

        if (!pDependencyInfo_ptr->pImageMemoryBarriers->IsNull() && (pDependencyInfo_ptr->pImageMemoryBarriers->HasData()))
        {
            auto pImageMemoryBarriers_ptr = pDependencyInfo_ptr->pImageMemoryBarriers->GetMetaStructPointer();
            size_t pImageMemoryBarriers_count = pDependencyInfo_ptr->pImageMemoryBarriers->GetLength();
            for (size_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pImageMemoryBarriers_count; ++pImageMemoryBarriers_index)
            {
                GetTable().AddResourceToUser(args.commandBuffer, pImageMemoryBarriers_ptr[pImageMemoryBarriers_index].image);
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdWaitEvents2(
    const ApiCallInfo&                          call_info,
    args::CmdWaitEvents2&                       args)
{
    if (!args.pDependencyInfos.IsNull() && (args.pDependencyInfos.HasData()))
    {
        auto pDependencyInfos_ptr = args.pDependencyInfos.GetMetaStructPointer();
        size_t pDependencyInfos_count = args.pDependencyInfos.GetLength();
        for (size_t pDependencyInfos_index = 0; pDependencyInfos_index < pDependencyInfos_count; ++pDependencyInfos_index)
        {
            {
                const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkTensorDependencyInfoARM>(pDependencyInfos_ptr[pDependencyInfos_index].pNext);
                if (ext_struct_info != nullptr)
                {
                    if (!ext_struct_info->pTensorMemoryBarriers->IsNull() && (ext_struct_info->pTensorMemoryBarriers->HasData()))
                    {
                        auto pTensorMemoryBarriers_ptr = ext_struct_info->pTensorMemoryBarriers->GetMetaStructPointer();
                        size_t pTensorMemoryBarriers_count = ext_struct_info->pTensorMemoryBarriers->GetLength();
                        for (size_t pTensorMemoryBarriers_index = 0; pTensorMemoryBarriers_index < pTensorMemoryBarriers_count; ++pTensorMemoryBarriers_index)
                        {
                            GetTable().AddResourceToUser(args.commandBuffer, pTensorMemoryBarriers_ptr[pTensorMemoryBarriers_index].tensor);
                        }
                    }
                }
            }
            {
                const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkTensorMemoryBarrierARM>(pDependencyInfos_ptr[pDependencyInfos_index].pNext);
                if (ext_struct_info != nullptr)
                {
                    GetTable().AddResourceToUser(args.commandBuffer, ext_struct_info->tensor);
                }
            }

            if (!pDependencyInfos_ptr[pDependencyInfos_index].pBufferMemoryBarriers->IsNull() && (pDependencyInfos_ptr[pDependencyInfos_index].pBufferMemoryBarriers->HasData()))
            {
                auto pBufferMemoryBarriers_ptr = pDependencyInfos_ptr[pDependencyInfos_index].pBufferMemoryBarriers->GetMetaStructPointer();
                size_t pBufferMemoryBarriers_count = pDependencyInfos_ptr[pDependencyInfos_index].pBufferMemoryBarriers->GetLength();
                for (size_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pBufferMemoryBarriers_count; ++pBufferMemoryBarriers_index)
                {
                    GetTable().AddResourceToUser(args.commandBuffer, pBufferMemoryBarriers_ptr[pBufferMemoryBarriers_index].buffer);
                }
            }

            if (!pDependencyInfos_ptr[pDependencyInfos_index].pImageMemoryBarriers->IsNull() && (pDependencyInfos_ptr[pDependencyInfos_index].pImageMemoryBarriers->HasData()))
            {
                auto pImageMemoryBarriers_ptr = pDependencyInfos_ptr[pDependencyInfos_index].pImageMemoryBarriers->GetMetaStructPointer();
                size_t pImageMemoryBarriers_count = pDependencyInfos_ptr[pDependencyInfos_index].pImageMemoryBarriers->GetLength();
                for (size_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pImageMemoryBarriers_count; ++pImageMemoryBarriers_index)
                {
                    GetTable().AddResourceToUser(args.commandBuffer, pImageMemoryBarriers_ptr[pImageMemoryBarriers_index].image);
                }
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    args::CmdBlitImage2&                        args)
{
    if (!args.pBlitImageInfo.IsNull() && (args.pBlitImageInfo.HasData()))
    {
        auto pBlitImageInfo_ptr = args.pBlitImageInfo.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pBlitImageInfo_ptr->srcImage);
        GetTable().AddResourceToUser(args.commandBuffer, pBlitImageInfo_ptr->dstImage);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    args::CmdResolveImage2&                     args)
{
    if (!args.pResolveImageInfo.IsNull() && (args.pResolveImageInfo.HasData()))
    {
        auto pResolveImageInfo_ptr = args.pResolveImageInfo.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pResolveImageInfo_ptr->srcImage);
        GetTable().AddResourceToUser(args.commandBuffer, pResolveImageInfo_ptr->dstImage);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRendering&                    args)
{
    if (!args.pRenderingInfo.IsNull() && (args.pRenderingInfo.HasData()))
    {
        auto pRenderingInfo_ptr = args.pRenderingInfo.GetMetaStructPointer();
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT>(pRenderingInfo_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                GetTable().AddResourceToUser(args.commandBuffer, ext_struct_info->imageView);
            }
        }
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR>(pRenderingInfo_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                GetTable().AddResourceToUser(args.commandBuffer, ext_struct_info->imageView);
            }
        }

        if (!pRenderingInfo_ptr->pColorAttachments->IsNull() && (pRenderingInfo_ptr->pColorAttachments->HasData()))
        {
            auto pColorAttachments_ptr = pRenderingInfo_ptr->pColorAttachments->GetMetaStructPointer();
            size_t pColorAttachments_count = pRenderingInfo_ptr->pColorAttachments->GetLength();
            for (size_t pColorAttachments_index = 0; pColorAttachments_index < pColorAttachments_count; ++pColorAttachments_index)
            {
                GetTable().AddResourceToUser(args.commandBuffer, pColorAttachments_ptr[pColorAttachments_index].imageView);
                GetTable().AddResourceToUser(args.commandBuffer, pColorAttachments_ptr[pColorAttachments_index].resolveImageView);
            }
        }

        if (!pRenderingInfo_ptr->pDepthAttachment->IsNull() && (pRenderingInfo_ptr->pDepthAttachment->HasData()))
        {
            auto pDepthAttachment_ptr = pRenderingInfo_ptr->pDepthAttachment->GetMetaStructPointer();
            GetTable().AddResourceToUser(args.commandBuffer, pDepthAttachment_ptr->imageView);
            GetTable().AddResourceToUser(args.commandBuffer, pDepthAttachment_ptr->resolveImageView);
        }

        if (!pRenderingInfo_ptr->pStencilAttachment->IsNull() && (pRenderingInfo_ptr->pStencilAttachment->HasData()))
        {
            auto pStencilAttachment_ptr = pRenderingInfo_ptr->pStencilAttachment->GetMetaStructPointer();
            GetTable().AddResourceToUser(args.commandBuffer, pStencilAttachment_ptr->imageView);
            GetTable().AddResourceToUser(args.commandBuffer, pStencilAttachment_ptr->resolveImageView);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindVertexBuffers2(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers2&                args)
{
    if (!args.pBuffers.IsNull() && (args.pBuffers.HasData()))
    {
        auto pBuffers_ptr = args.pBuffers.GetPointer();
        size_t pBuffers_count = args.pBuffers.GetLength();
        for (size_t pBuffers_index = 0; pBuffers_index < pBuffers_count; ++pBuffers_index)
        {
            GetTable().AddResourceToUser(args.commandBuffer, pBuffers_ptr[pBuffers_index]);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdPushDescriptorSet(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSet&                 args)
{
    if (!args.pDescriptorWrites.IsNull() && (args.pDescriptorWrites.HasData()))
    {
        auto pDescriptorWrites_ptr = args.pDescriptorWrites.GetMetaStructPointer();
        size_t pDescriptorWrites_count = args.pDescriptorWrites.GetLength();
        for (size_t pDescriptorWrites_index = 0; pDescriptorWrites_index < pDescriptorWrites_count; ++pDescriptorWrites_index)
        {
            {
                const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkWriteDescriptorSetAccelerationStructureKHR>(pDescriptorWrites_ptr[pDescriptorWrites_index].pNext);
                if (ext_struct_info != nullptr)
                {
                    if (!ext_struct_info->pAccelerationStructures.IsNull() && (ext_struct_info->pAccelerationStructures.HasData()))
                    {
                        auto pAccelerationStructures_ptr = ext_struct_info->pAccelerationStructures.GetPointer();
                        size_t pAccelerationStructures_count = ext_struct_info->pAccelerationStructures.GetLength();
                        for (size_t pAccelerationStructures_index = 0; pAccelerationStructures_index < pAccelerationStructures_count; ++pAccelerationStructures_index)
                        {
                            GetTable().AddResourceToUser(args.commandBuffer, pAccelerationStructures_ptr[pAccelerationStructures_index]);
                        }
                    }
                }
            }
            {
                const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkWriteDescriptorSetTensorARM>(pDescriptorWrites_ptr[pDescriptorWrites_index].pNext);
                if (ext_struct_info != nullptr)
                {
                    if (!ext_struct_info->pTensorViews.IsNull() && (ext_struct_info->pTensorViews.HasData()))
                    {
                        auto pTensorViews_ptr = ext_struct_info->pTensorViews.GetPointer();
                        size_t pTensorViews_count = ext_struct_info->pTensorViews.GetLength();
                        for (size_t pTensorViews_index = 0; pTensorViews_index < pTensorViews_count; ++pTensorViews_index)
                        {
                            GetTable().AddResourceToUser(args.commandBuffer, pTensorViews_ptr[pTensorViews_index]);
                        }
                    }
                }
            }
            GetTable().AddContainerToUser(args.commandBuffer, pDescriptorWrites_ptr[pDescriptorWrites_index].dstSet);

            if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->HasData()))
            {
                auto pImageInfo_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->GetMetaStructPointer();
                size_t pImageInfo_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->GetLength();
                for (size_t pImageInfo_index = 0; pImageInfo_index < pImageInfo_count; ++pImageInfo_index)
                {
                    GetTable().AddResourceToUser(args.commandBuffer, pImageInfo_ptr[pImageInfo_index].imageView);
                }
            }

            if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->HasData()))
            {
                auto pBufferInfo_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->GetMetaStructPointer();
                size_t pBufferInfo_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->GetLength();
                for (size_t pBufferInfo_index = 0; pBufferInfo_index < pBufferInfo_count; ++pBufferInfo_index)
                {
                    GetTable().AddResourceToUser(args.commandBuffer, pBufferInfo_ptr[pBufferInfo_index].buffer);
                }
            }

            if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.HasData()))
            {
                auto pTexelBufferView_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.GetPointer();
                size_t pTexelBufferView_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.GetLength();
                for (size_t pTexelBufferView_index = 0; pTexelBufferView_index < pTexelBufferView_count; ++pTexelBufferView_index)
                {
                    GetTable().AddResourceToUser(args.commandBuffer, pTexelBufferView_ptr[pTexelBufferView_index]);
                }
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindDescriptorSets2(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorSets2&               args)
{
    if (!args.pBindDescriptorSetsInfo.IsNull() && (args.pBindDescriptorSetsInfo.HasData()))
    {
        auto pBindDescriptorSetsInfo_ptr = args.pBindDescriptorSetsInfo.GetMetaStructPointer();
        if (!pBindDescriptorSetsInfo_ptr->pDescriptorSets.IsNull() && (pBindDescriptorSetsInfo_ptr->pDescriptorSets.HasData()))
        {
            auto pDescriptorSets_ptr = pBindDescriptorSetsInfo_ptr->pDescriptorSets.GetPointer();
            size_t pDescriptorSets_count = pBindDescriptorSetsInfo_ptr->pDescriptorSets.GetLength();
            for (size_t pDescriptorSets_index = 0; pDescriptorSets_index < pDescriptorSets_count; ++pDescriptorSets_index)
            {
                GetTable().AddContainerToUser(args.commandBuffer, pDescriptorSets_ptr[pDescriptorSets_index]);
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdPushDescriptorSet2(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSet2&                args)
{
    if (!args.pPushDescriptorSetInfo.IsNull() && (args.pPushDescriptorSetInfo.HasData()))
    {
        auto pPushDescriptorSetInfo_ptr = args.pPushDescriptorSetInfo.GetMetaStructPointer();
        if (!pPushDescriptorSetInfo_ptr->pDescriptorWrites->IsNull() && (pPushDescriptorSetInfo_ptr->pDescriptorWrites->HasData()))
        {
            auto pDescriptorWrites_ptr = pPushDescriptorSetInfo_ptr->pDescriptorWrites->GetMetaStructPointer();
            size_t pDescriptorWrites_count = pPushDescriptorSetInfo_ptr->pDescriptorWrites->GetLength();
            for (size_t pDescriptorWrites_index = 0; pDescriptorWrites_index < pDescriptorWrites_count; ++pDescriptorWrites_index)
            {
                {
                    const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkWriteDescriptorSetAccelerationStructureKHR>(pDescriptorWrites_ptr[pDescriptorWrites_index].pNext);
                    if (ext_struct_info != nullptr)
                    {
                        if (!ext_struct_info->pAccelerationStructures.IsNull() && (ext_struct_info->pAccelerationStructures.HasData()))
                        {
                            auto pAccelerationStructures_ptr = ext_struct_info->pAccelerationStructures.GetPointer();
                            size_t pAccelerationStructures_count = ext_struct_info->pAccelerationStructures.GetLength();
                            for (size_t pAccelerationStructures_index = 0; pAccelerationStructures_index < pAccelerationStructures_count; ++pAccelerationStructures_index)
                            {
                                GetTable().AddResourceToUser(args.commandBuffer, pAccelerationStructures_ptr[pAccelerationStructures_index]);
                            }
                        }
                    }
                }
                {
                    const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkWriteDescriptorSetTensorARM>(pDescriptorWrites_ptr[pDescriptorWrites_index].pNext);
                    if (ext_struct_info != nullptr)
                    {
                        if (!ext_struct_info->pTensorViews.IsNull() && (ext_struct_info->pTensorViews.HasData()))
                        {
                            auto pTensorViews_ptr = ext_struct_info->pTensorViews.GetPointer();
                            size_t pTensorViews_count = ext_struct_info->pTensorViews.GetLength();
                            for (size_t pTensorViews_index = 0; pTensorViews_index < pTensorViews_count; ++pTensorViews_index)
                            {
                                GetTable().AddResourceToUser(args.commandBuffer, pTensorViews_ptr[pTensorViews_index]);
                            }
                        }
                    }
                }
                GetTable().AddContainerToUser(args.commandBuffer, pDescriptorWrites_ptr[pDescriptorWrites_index].dstSet);

                if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->HasData()))
                {
                    auto pImageInfo_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->GetMetaStructPointer();
                    size_t pImageInfo_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->GetLength();
                    for (size_t pImageInfo_index = 0; pImageInfo_index < pImageInfo_count; ++pImageInfo_index)
                    {
                        GetTable().AddResourceToUser(args.commandBuffer, pImageInfo_ptr[pImageInfo_index].imageView);
                    }
                }

                if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->HasData()))
                {
                    auto pBufferInfo_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->GetMetaStructPointer();
                    size_t pBufferInfo_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->GetLength();
                    for (size_t pBufferInfo_index = 0; pBufferInfo_index < pBufferInfo_count; ++pBufferInfo_index)
                    {
                        GetTable().AddResourceToUser(args.commandBuffer, pBufferInfo_ptr[pBufferInfo_index].buffer);
                    }
                }

                if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.HasData()))
                {
                    auto pTexelBufferView_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.GetPointer();
                    size_t pTexelBufferView_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.GetLength();
                    for (size_t pTexelBufferView_index = 0; pTexelBufferView_index < pTexelBufferView_count; ++pTexelBufferView_index)
                    {
                        GetTable().AddResourceToUser(args.commandBuffer, pTexelBufferView_ptr[pTexelBufferView_index]);
                    }
                }
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindIndexBuffer2(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer2&                  args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.buffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdBeginVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBeginVideoCodingKHR&               args)
{
    if (!args.pBeginInfo.IsNull() && (args.pBeginInfo.HasData()))
    {
        auto pBeginInfo_ptr = args.pBeginInfo.GetMetaStructPointer();
        if (!pBeginInfo_ptr->pReferenceSlots->IsNull() && (pBeginInfo_ptr->pReferenceSlots->HasData()))
        {
            auto pReferenceSlots_ptr = pBeginInfo_ptr->pReferenceSlots->GetMetaStructPointer();
            size_t pReferenceSlots_count = pBeginInfo_ptr->pReferenceSlots->GetLength();
            for (size_t pReferenceSlots_index = 0; pReferenceSlots_index < pReferenceSlots_count; ++pReferenceSlots_index)
            {
                if (!pReferenceSlots_ptr[pReferenceSlots_index].pPictureResource->IsNull() && (pReferenceSlots_ptr[pReferenceSlots_index].pPictureResource->HasData()))
                {
                    auto pPictureResource_ptr = pReferenceSlots_ptr[pReferenceSlots_index].pPictureResource->GetMetaStructPointer();
                    GetTable().AddResourceToUser(args.commandBuffer, pPictureResource_ptr->imageViewBinding);
                }
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdDecodeVideoKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDecodeVideoKHR&                    args)
{
    if (!args.pDecodeInfo.IsNull() && (args.pDecodeInfo.HasData()))
    {
        auto pDecodeInfo_ptr = args.pDecodeInfo.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pDecodeInfo_ptr->srcBuffer);
        GetTable().AddResourceToUser(args.commandBuffer, pDecodeInfo_ptr->dstPictureResource->imageViewBinding);

        if (!pDecodeInfo_ptr->pSetupReferenceSlot->IsNull() && (pDecodeInfo_ptr->pSetupReferenceSlot->HasData()))
        {
            auto pSetupReferenceSlot_ptr = pDecodeInfo_ptr->pSetupReferenceSlot->GetMetaStructPointer();
            if (!pSetupReferenceSlot_ptr->pPictureResource->IsNull() && (pSetupReferenceSlot_ptr->pPictureResource->HasData()))
            {
                auto pPictureResource_ptr = pSetupReferenceSlot_ptr->pPictureResource->GetMetaStructPointer();
                GetTable().AddResourceToUser(args.commandBuffer, pPictureResource_ptr->imageViewBinding);
            }
        }

        if (!pDecodeInfo_ptr->pReferenceSlots->IsNull() && (pDecodeInfo_ptr->pReferenceSlots->HasData()))
        {
            auto pReferenceSlots_ptr = pDecodeInfo_ptr->pReferenceSlots->GetMetaStructPointer();
            size_t pReferenceSlots_count = pDecodeInfo_ptr->pReferenceSlots->GetLength();
            for (size_t pReferenceSlots_index = 0; pReferenceSlots_index < pReferenceSlots_count; ++pReferenceSlots_index)
            {
                if (!pReferenceSlots_ptr[pReferenceSlots_index].pPictureResource->IsNull() && (pReferenceSlots_ptr[pReferenceSlots_index].pPictureResource->HasData()))
                {
                    auto pPictureResource_ptr = pReferenceSlots_ptr[pReferenceSlots_index].pPictureResource->GetMetaStructPointer();
                    GetTable().AddResourceToUser(args.commandBuffer, pPictureResource_ptr->imageViewBinding);
                }
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderingKHR&                 args)
{
    if (!args.pRenderingInfo.IsNull() && (args.pRenderingInfo.HasData()))
    {
        auto pRenderingInfo_ptr = args.pRenderingInfo.GetMetaStructPointer();
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT>(pRenderingInfo_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                GetTable().AddResourceToUser(args.commandBuffer, ext_struct_info->imageView);
            }
        }
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR>(pRenderingInfo_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                GetTable().AddResourceToUser(args.commandBuffer, ext_struct_info->imageView);
            }
        }

        if (!pRenderingInfo_ptr->pColorAttachments->IsNull() && (pRenderingInfo_ptr->pColorAttachments->HasData()))
        {
            auto pColorAttachments_ptr = pRenderingInfo_ptr->pColorAttachments->GetMetaStructPointer();
            size_t pColorAttachments_count = pRenderingInfo_ptr->pColorAttachments->GetLength();
            for (size_t pColorAttachments_index = 0; pColorAttachments_index < pColorAttachments_count; ++pColorAttachments_index)
            {
                GetTable().AddResourceToUser(args.commandBuffer, pColorAttachments_ptr[pColorAttachments_index].imageView);
                GetTable().AddResourceToUser(args.commandBuffer, pColorAttachments_ptr[pColorAttachments_index].resolveImageView);
            }
        }

        if (!pRenderingInfo_ptr->pDepthAttachment->IsNull() && (pRenderingInfo_ptr->pDepthAttachment->HasData()))
        {
            auto pDepthAttachment_ptr = pRenderingInfo_ptr->pDepthAttachment->GetMetaStructPointer();
            GetTable().AddResourceToUser(args.commandBuffer, pDepthAttachment_ptr->imageView);
            GetTable().AddResourceToUser(args.commandBuffer, pDepthAttachment_ptr->resolveImageView);
        }

        if (!pRenderingInfo_ptr->pStencilAttachment->IsNull() && (pRenderingInfo_ptr->pStencilAttachment->HasData()))
        {
            auto pStencilAttachment_ptr = pRenderingInfo_ptr->pStencilAttachment->GetMetaStructPointer();
            GetTable().AddResourceToUser(args.commandBuffer, pStencilAttachment_ptr->imageView);
            GetTable().AddResourceToUser(args.commandBuffer, pStencilAttachment_ptr->resolveImageView);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdPushDescriptorSetKHR(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSetKHR&              args)
{
    if (!args.pDescriptorWrites.IsNull() && (args.pDescriptorWrites.HasData()))
    {
        auto pDescriptorWrites_ptr = args.pDescriptorWrites.GetMetaStructPointer();
        size_t pDescriptorWrites_count = args.pDescriptorWrites.GetLength();
        for (size_t pDescriptorWrites_index = 0; pDescriptorWrites_index < pDescriptorWrites_count; ++pDescriptorWrites_index)
        {
            {
                const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkWriteDescriptorSetAccelerationStructureKHR>(pDescriptorWrites_ptr[pDescriptorWrites_index].pNext);
                if (ext_struct_info != nullptr)
                {
                    if (!ext_struct_info->pAccelerationStructures.IsNull() && (ext_struct_info->pAccelerationStructures.HasData()))
                    {
                        auto pAccelerationStructures_ptr = ext_struct_info->pAccelerationStructures.GetPointer();
                        size_t pAccelerationStructures_count = ext_struct_info->pAccelerationStructures.GetLength();
                        for (size_t pAccelerationStructures_index = 0; pAccelerationStructures_index < pAccelerationStructures_count; ++pAccelerationStructures_index)
                        {
                            GetTable().AddResourceToUser(args.commandBuffer, pAccelerationStructures_ptr[pAccelerationStructures_index]);
                        }
                    }
                }
            }
            {
                const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkWriteDescriptorSetTensorARM>(pDescriptorWrites_ptr[pDescriptorWrites_index].pNext);
                if (ext_struct_info != nullptr)
                {
                    if (!ext_struct_info->pTensorViews.IsNull() && (ext_struct_info->pTensorViews.HasData()))
                    {
                        auto pTensorViews_ptr = ext_struct_info->pTensorViews.GetPointer();
                        size_t pTensorViews_count = ext_struct_info->pTensorViews.GetLength();
                        for (size_t pTensorViews_index = 0; pTensorViews_index < pTensorViews_count; ++pTensorViews_index)
                        {
                            GetTable().AddResourceToUser(args.commandBuffer, pTensorViews_ptr[pTensorViews_index]);
                        }
                    }
                }
            }
            GetTable().AddContainerToUser(args.commandBuffer, pDescriptorWrites_ptr[pDescriptorWrites_index].dstSet);

            if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->HasData()))
            {
                auto pImageInfo_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->GetMetaStructPointer();
                size_t pImageInfo_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->GetLength();
                for (size_t pImageInfo_index = 0; pImageInfo_index < pImageInfo_count; ++pImageInfo_index)
                {
                    GetTable().AddResourceToUser(args.commandBuffer, pImageInfo_ptr[pImageInfo_index].imageView);
                }
            }

            if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->HasData()))
            {
                auto pBufferInfo_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->GetMetaStructPointer();
                size_t pBufferInfo_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->GetLength();
                for (size_t pBufferInfo_index = 0; pBufferInfo_index < pBufferInfo_count; ++pBufferInfo_index)
                {
                    GetTable().AddResourceToUser(args.commandBuffer, pBufferInfo_ptr[pBufferInfo_index].buffer);
                }
            }

            if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.HasData()))
            {
                auto pTexelBufferView_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.GetPointer();
                size_t pTexelBufferView_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.GetLength();
                for (size_t pTexelBufferView_index = 0; pTexelBufferView_index < pTexelBufferView_count; ++pTexelBufferView_index)
                {
                    GetTable().AddResourceToUser(args.commandBuffer, pTexelBufferView_ptr[pTexelBufferView_index]);
                }
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderPass2KHR&               args)
{
    if (!args.pRenderPassBegin.IsNull() && (args.pRenderPassBegin.HasData()))
    {
        auto pRenderPassBegin_ptr = args.pRenderPassBegin.GetMetaStructPointer();
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkRenderPassAttachmentBeginInfo>(pRenderPassBegin_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                if (!ext_struct_info->pAttachments.IsNull() && (ext_struct_info->pAttachments.HasData()))
                {
                    auto pAttachments_ptr = ext_struct_info->pAttachments.GetPointer();
                    size_t pAttachments_count = ext_struct_info->pAttachments.GetLength();
                    for (size_t pAttachments_index = 0; pAttachments_index < pAttachments_count; ++pAttachments_index)
                    {
                        GetTable().AddResourceToUser(args.commandBuffer, pAttachments_ptr[pAttachments_index]);
                    }
                }
            }
        }
        GetTable().AddResourceToUser(args.commandBuffer, pRenderPassBegin_ptr->framebuffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCountKHR&              args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.buffer);
    GetTable().AddResourceToUser(args.commandBuffer, args.countBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCountKHR&       args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.buffer);
    GetTable().AddResourceToUser(args.commandBuffer, args.countBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdEncodeVideoKHR(
    const ApiCallInfo&                          call_info,
    args::CmdEncodeVideoKHR&                    args)
{
    if (!args.pEncodeInfo.IsNull() && (args.pEncodeInfo.HasData()))
    {
        auto pEncodeInfo_ptr = args.pEncodeInfo.GetMetaStructPointer();
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkVideoEncodeQuantizationMapInfoKHR>(pEncodeInfo_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                GetTable().AddResourceToUser(args.commandBuffer, ext_struct_info->quantizationMap);
            }
        }
        GetTable().AddResourceToUser(args.commandBuffer, pEncodeInfo_ptr->dstBuffer);
        GetTable().AddResourceToUser(args.commandBuffer, pEncodeInfo_ptr->srcPictureResource->imageViewBinding);

        if (!pEncodeInfo_ptr->pSetupReferenceSlot->IsNull() && (pEncodeInfo_ptr->pSetupReferenceSlot->HasData()))
        {
            auto pSetupReferenceSlot_ptr = pEncodeInfo_ptr->pSetupReferenceSlot->GetMetaStructPointer();
            if (!pSetupReferenceSlot_ptr->pPictureResource->IsNull() && (pSetupReferenceSlot_ptr->pPictureResource->HasData()))
            {
                auto pPictureResource_ptr = pSetupReferenceSlot_ptr->pPictureResource->GetMetaStructPointer();
                GetTable().AddResourceToUser(args.commandBuffer, pPictureResource_ptr->imageViewBinding);
            }
        }

        if (!pEncodeInfo_ptr->pReferenceSlots->IsNull() && (pEncodeInfo_ptr->pReferenceSlots->HasData()))
        {
            auto pReferenceSlots_ptr = pEncodeInfo_ptr->pReferenceSlots->GetMetaStructPointer();
            size_t pReferenceSlots_count = pEncodeInfo_ptr->pReferenceSlots->GetLength();
            for (size_t pReferenceSlots_index = 0; pReferenceSlots_index < pReferenceSlots_count; ++pReferenceSlots_index)
            {
                if (!pReferenceSlots_ptr[pReferenceSlots_index].pPictureResource->IsNull() && (pReferenceSlots_ptr[pReferenceSlots_index].pPictureResource->HasData()))
                {
                    auto pPictureResource_ptr = pReferenceSlots_ptr[pReferenceSlots_index].pPictureResource->GetMetaStructPointer();
                    GetTable().AddResourceToUser(args.commandBuffer, pPictureResource_ptr->imageViewBinding);
                }
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetEvent2KHR&                      args)
{
    if (!args.pDependencyInfo.IsNull() && (args.pDependencyInfo.HasData()))
    {
        auto pDependencyInfo_ptr = args.pDependencyInfo.GetMetaStructPointer();
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkTensorDependencyInfoARM>(pDependencyInfo_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                if (!ext_struct_info->pTensorMemoryBarriers->IsNull() && (ext_struct_info->pTensorMemoryBarriers->HasData()))
                {
                    auto pTensorMemoryBarriers_ptr = ext_struct_info->pTensorMemoryBarriers->GetMetaStructPointer();
                    size_t pTensorMemoryBarriers_count = ext_struct_info->pTensorMemoryBarriers->GetLength();
                    for (size_t pTensorMemoryBarriers_index = 0; pTensorMemoryBarriers_index < pTensorMemoryBarriers_count; ++pTensorMemoryBarriers_index)
                    {
                        GetTable().AddResourceToUser(args.commandBuffer, pTensorMemoryBarriers_ptr[pTensorMemoryBarriers_index].tensor);
                    }
                }
            }
        }
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkTensorMemoryBarrierARM>(pDependencyInfo_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                GetTable().AddResourceToUser(args.commandBuffer, ext_struct_info->tensor);
            }
        }

        if (!pDependencyInfo_ptr->pBufferMemoryBarriers->IsNull() && (pDependencyInfo_ptr->pBufferMemoryBarriers->HasData()))
        {
            auto pBufferMemoryBarriers_ptr = pDependencyInfo_ptr->pBufferMemoryBarriers->GetMetaStructPointer();
            size_t pBufferMemoryBarriers_count = pDependencyInfo_ptr->pBufferMemoryBarriers->GetLength();
            for (size_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pBufferMemoryBarriers_count; ++pBufferMemoryBarriers_index)
            {
                GetTable().AddResourceToUser(args.commandBuffer, pBufferMemoryBarriers_ptr[pBufferMemoryBarriers_index].buffer);
            }
        }

        if (!pDependencyInfo_ptr->pImageMemoryBarriers->IsNull() && (pDependencyInfo_ptr->pImageMemoryBarriers->HasData()))
        {
            auto pImageMemoryBarriers_ptr = pDependencyInfo_ptr->pImageMemoryBarriers->GetMetaStructPointer();
            size_t pImageMemoryBarriers_count = pDependencyInfo_ptr->pImageMemoryBarriers->GetLength();
            for (size_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pImageMemoryBarriers_count; ++pImageMemoryBarriers_index)
            {
                GetTable().AddResourceToUser(args.commandBuffer, pImageMemoryBarriers_ptr[pImageMemoryBarriers_index].image);
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdWaitEvents2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdWaitEvents2KHR&                    args)
{
    if (!args.pDependencyInfos.IsNull() && (args.pDependencyInfos.HasData()))
    {
        auto pDependencyInfos_ptr = args.pDependencyInfos.GetMetaStructPointer();
        size_t pDependencyInfos_count = args.pDependencyInfos.GetLength();
        for (size_t pDependencyInfos_index = 0; pDependencyInfos_index < pDependencyInfos_count; ++pDependencyInfos_index)
        {
            {
                const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkTensorDependencyInfoARM>(pDependencyInfos_ptr[pDependencyInfos_index].pNext);
                if (ext_struct_info != nullptr)
                {
                    if (!ext_struct_info->pTensorMemoryBarriers->IsNull() && (ext_struct_info->pTensorMemoryBarriers->HasData()))
                    {
                        auto pTensorMemoryBarriers_ptr = ext_struct_info->pTensorMemoryBarriers->GetMetaStructPointer();
                        size_t pTensorMemoryBarriers_count = ext_struct_info->pTensorMemoryBarriers->GetLength();
                        for (size_t pTensorMemoryBarriers_index = 0; pTensorMemoryBarriers_index < pTensorMemoryBarriers_count; ++pTensorMemoryBarriers_index)
                        {
                            GetTable().AddResourceToUser(args.commandBuffer, pTensorMemoryBarriers_ptr[pTensorMemoryBarriers_index].tensor);
                        }
                    }
                }
            }
            {
                const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkTensorMemoryBarrierARM>(pDependencyInfos_ptr[pDependencyInfos_index].pNext);
                if (ext_struct_info != nullptr)
                {
                    GetTable().AddResourceToUser(args.commandBuffer, ext_struct_info->tensor);
                }
            }

            if (!pDependencyInfos_ptr[pDependencyInfos_index].pBufferMemoryBarriers->IsNull() && (pDependencyInfos_ptr[pDependencyInfos_index].pBufferMemoryBarriers->HasData()))
            {
                auto pBufferMemoryBarriers_ptr = pDependencyInfos_ptr[pDependencyInfos_index].pBufferMemoryBarriers->GetMetaStructPointer();
                size_t pBufferMemoryBarriers_count = pDependencyInfos_ptr[pDependencyInfos_index].pBufferMemoryBarriers->GetLength();
                for (size_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pBufferMemoryBarriers_count; ++pBufferMemoryBarriers_index)
                {
                    GetTable().AddResourceToUser(args.commandBuffer, pBufferMemoryBarriers_ptr[pBufferMemoryBarriers_index].buffer);
                }
            }

            if (!pDependencyInfos_ptr[pDependencyInfos_index].pImageMemoryBarriers->IsNull() && (pDependencyInfos_ptr[pDependencyInfos_index].pImageMemoryBarriers->HasData()))
            {
                auto pImageMemoryBarriers_ptr = pDependencyInfos_ptr[pDependencyInfos_index].pImageMemoryBarriers->GetMetaStructPointer();
                size_t pImageMemoryBarriers_count = pDependencyInfos_ptr[pDependencyInfos_index].pImageMemoryBarriers->GetLength();
                for (size_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pImageMemoryBarriers_count; ++pImageMemoryBarriers_index)
                {
                    GetTable().AddResourceToUser(args.commandBuffer, pImageMemoryBarriers_ptr[pImageMemoryBarriers_index].image);
                }
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdPipelineBarrier2KHR&               args)
{
    if (!args.pDependencyInfo.IsNull() && (args.pDependencyInfo.HasData()))
    {
        auto pDependencyInfo_ptr = args.pDependencyInfo.GetMetaStructPointer();
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkTensorDependencyInfoARM>(pDependencyInfo_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                if (!ext_struct_info->pTensorMemoryBarriers->IsNull() && (ext_struct_info->pTensorMemoryBarriers->HasData()))
                {
                    auto pTensorMemoryBarriers_ptr = ext_struct_info->pTensorMemoryBarriers->GetMetaStructPointer();
                    size_t pTensorMemoryBarriers_count = ext_struct_info->pTensorMemoryBarriers->GetLength();
                    for (size_t pTensorMemoryBarriers_index = 0; pTensorMemoryBarriers_index < pTensorMemoryBarriers_count; ++pTensorMemoryBarriers_index)
                    {
                        GetTable().AddResourceToUser(args.commandBuffer, pTensorMemoryBarriers_ptr[pTensorMemoryBarriers_index].tensor);
                    }
                }
            }
        }
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkTensorMemoryBarrierARM>(pDependencyInfo_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                GetTable().AddResourceToUser(args.commandBuffer, ext_struct_info->tensor);
            }
        }

        if (!pDependencyInfo_ptr->pBufferMemoryBarriers->IsNull() && (pDependencyInfo_ptr->pBufferMemoryBarriers->HasData()))
        {
            auto pBufferMemoryBarriers_ptr = pDependencyInfo_ptr->pBufferMemoryBarriers->GetMetaStructPointer();
            size_t pBufferMemoryBarriers_count = pDependencyInfo_ptr->pBufferMemoryBarriers->GetLength();
            for (size_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pBufferMemoryBarriers_count; ++pBufferMemoryBarriers_index)
            {
                GetTable().AddResourceToUser(args.commandBuffer, pBufferMemoryBarriers_ptr[pBufferMemoryBarriers_index].buffer);
            }
        }

        if (!pDependencyInfo_ptr->pImageMemoryBarriers->IsNull() && (pDependencyInfo_ptr->pImageMemoryBarriers->HasData()))
        {
            auto pImageMemoryBarriers_ptr = pDependencyInfo_ptr->pImageMemoryBarriers->GetMetaStructPointer();
            size_t pImageMemoryBarriers_count = pDependencyInfo_ptr->pImageMemoryBarriers->GetLength();
            for (size_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pImageMemoryBarriers_count; ++pImageMemoryBarriers_index)
            {
                GetTable().AddResourceToUser(args.commandBuffer, pImageMemoryBarriers_ptr[pImageMemoryBarriers_index].image);
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyMemoryToImageKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToImageKHR&              args)
{
    if (!args.pCopyMemoryInfo.IsNull() && (args.pCopyMemoryInfo.HasData()))
    {
        auto pCopyMemoryInfo_ptr = args.pCopyMemoryInfo.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pCopyMemoryInfo_ptr->image);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyImageToMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToMemoryKHR&              args)
{
    if (!args.pCopyMemoryInfo.IsNull() && (args.pCopyMemoryInfo.HasData()))
    {
        auto pCopyMemoryInfo_ptr = args.pCopyMemoryInfo.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pCopyMemoryInfo_ptr->image);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBuffer2KHR&                    args)
{
    if (!args.pCopyBufferInfo.IsNull() && (args.pCopyBufferInfo.HasData()))
    {
        auto pCopyBufferInfo_ptr = args.pCopyBufferInfo.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pCopyBufferInfo_ptr->srcBuffer);
        GetTable().AddResourceToUser(args.commandBuffer, pCopyBufferInfo_ptr->dstBuffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImage2KHR&                     args)
{
    if (!args.pCopyImageInfo.IsNull() && (args.pCopyImageInfo.HasData()))
    {
        auto pCopyImageInfo_ptr = args.pCopyImageInfo.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pCopyImageInfo_ptr->srcImage);
        GetTable().AddResourceToUser(args.commandBuffer, pCopyImageInfo_ptr->dstImage);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBufferToImage2KHR&             args)
{
    if (!args.pCopyBufferToImageInfo.IsNull() && (args.pCopyBufferToImageInfo.HasData()))
    {
        auto pCopyBufferToImageInfo_ptr = args.pCopyBufferToImageInfo.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pCopyBufferToImageInfo_ptr->srcBuffer);
        GetTable().AddResourceToUser(args.commandBuffer, pCopyBufferToImageInfo_ptr->dstImage);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToBuffer2KHR&             args)
{
    if (!args.pCopyImageToBufferInfo.IsNull() && (args.pCopyImageToBufferInfo.HasData()))
    {
        auto pCopyImageToBufferInfo_ptr = args.pCopyImageToBufferInfo.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pCopyImageToBufferInfo_ptr->srcImage);
        GetTable().AddResourceToUser(args.commandBuffer, pCopyImageToBufferInfo_ptr->dstBuffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBlitImage2KHR&                     args)
{
    if (!args.pBlitImageInfo.IsNull() && (args.pBlitImageInfo.HasData()))
    {
        auto pBlitImageInfo_ptr = args.pBlitImageInfo.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pBlitImageInfo_ptr->srcImage);
        GetTable().AddResourceToUser(args.commandBuffer, pBlitImageInfo_ptr->dstImage);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdResolveImage2KHR&                  args)
{
    if (!args.pResolveImageInfo.IsNull() && (args.pResolveImageInfo.HasData()))
    {
        auto pResolveImageInfo_ptr = args.pResolveImageInfo.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pResolveImageInfo_ptr->srcImage);
        GetTable().AddResourceToUser(args.commandBuffer, pResolveImageInfo_ptr->dstImage);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindIndexBuffer2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer2KHR&               args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.buffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindDescriptorSets2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorSets2KHR&            args)
{
    if (!args.pBindDescriptorSetsInfo.IsNull() && (args.pBindDescriptorSetsInfo.HasData()))
    {
        auto pBindDescriptorSetsInfo_ptr = args.pBindDescriptorSetsInfo.GetMetaStructPointer();
        if (!pBindDescriptorSetsInfo_ptr->pDescriptorSets.IsNull() && (pBindDescriptorSetsInfo_ptr->pDescriptorSets.HasData()))
        {
            auto pDescriptorSets_ptr = pBindDescriptorSetsInfo_ptr->pDescriptorSets.GetPointer();
            size_t pDescriptorSets_count = pBindDescriptorSetsInfo_ptr->pDescriptorSets.GetLength();
            for (size_t pDescriptorSets_index = 0; pDescriptorSets_index < pDescriptorSets_count; ++pDescriptorSets_index)
            {
                GetTable().AddContainerToUser(args.commandBuffer, pDescriptorSets_ptr[pDescriptorSets_index]);
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdPushDescriptorSet2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSet2KHR&             args)
{
    if (!args.pPushDescriptorSetInfo.IsNull() && (args.pPushDescriptorSetInfo.HasData()))
    {
        auto pPushDescriptorSetInfo_ptr = args.pPushDescriptorSetInfo.GetMetaStructPointer();
        if (!pPushDescriptorSetInfo_ptr->pDescriptorWrites->IsNull() && (pPushDescriptorSetInfo_ptr->pDescriptorWrites->HasData()))
        {
            auto pDescriptorWrites_ptr = pPushDescriptorSetInfo_ptr->pDescriptorWrites->GetMetaStructPointer();
            size_t pDescriptorWrites_count = pPushDescriptorSetInfo_ptr->pDescriptorWrites->GetLength();
            for (size_t pDescriptorWrites_index = 0; pDescriptorWrites_index < pDescriptorWrites_count; ++pDescriptorWrites_index)
            {
                {
                    const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkWriteDescriptorSetAccelerationStructureKHR>(pDescriptorWrites_ptr[pDescriptorWrites_index].pNext);
                    if (ext_struct_info != nullptr)
                    {
                        if (!ext_struct_info->pAccelerationStructures.IsNull() && (ext_struct_info->pAccelerationStructures.HasData()))
                        {
                            auto pAccelerationStructures_ptr = ext_struct_info->pAccelerationStructures.GetPointer();
                            size_t pAccelerationStructures_count = ext_struct_info->pAccelerationStructures.GetLength();
                            for (size_t pAccelerationStructures_index = 0; pAccelerationStructures_index < pAccelerationStructures_count; ++pAccelerationStructures_index)
                            {
                                GetTable().AddResourceToUser(args.commandBuffer, pAccelerationStructures_ptr[pAccelerationStructures_index]);
                            }
                        }
                    }
                }
                {
                    const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkWriteDescriptorSetTensorARM>(pDescriptorWrites_ptr[pDescriptorWrites_index].pNext);
                    if (ext_struct_info != nullptr)
                    {
                        if (!ext_struct_info->pTensorViews.IsNull() && (ext_struct_info->pTensorViews.HasData()))
                        {
                            auto pTensorViews_ptr = ext_struct_info->pTensorViews.GetPointer();
                            size_t pTensorViews_count = ext_struct_info->pTensorViews.GetLength();
                            for (size_t pTensorViews_index = 0; pTensorViews_index < pTensorViews_count; ++pTensorViews_index)
                            {
                                GetTable().AddResourceToUser(args.commandBuffer, pTensorViews_ptr[pTensorViews_index]);
                            }
                        }
                    }
                }
                GetTable().AddContainerToUser(args.commandBuffer, pDescriptorWrites_ptr[pDescriptorWrites_index].dstSet);

                if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->HasData()))
                {
                    auto pImageInfo_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->GetMetaStructPointer();
                    size_t pImageInfo_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->GetLength();
                    for (size_t pImageInfo_index = 0; pImageInfo_index < pImageInfo_count; ++pImageInfo_index)
                    {
                        GetTable().AddResourceToUser(args.commandBuffer, pImageInfo_ptr[pImageInfo_index].imageView);
                    }
                }

                if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->HasData()))
                {
                    auto pBufferInfo_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->GetMetaStructPointer();
                    size_t pBufferInfo_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->GetLength();
                    for (size_t pBufferInfo_index = 0; pBufferInfo_index < pBufferInfo_count; ++pBufferInfo_index)
                    {
                        GetTable().AddResourceToUser(args.commandBuffer, pBufferInfo_ptr[pBufferInfo_index].buffer);
                    }
                }

                if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.HasData()))
                {
                    auto pTexelBufferView_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.GetPointer();
                    size_t pTexelBufferView_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.GetLength();
                    for (size_t pTexelBufferView_index = 0; pTexelBufferView_index < pTexelBufferView_count; ++pTexelBufferView_index)
                    {
                        GetTable().AddResourceToUser(args.commandBuffer, pTexelBufferView_ptr[pTexelBufferView_index]);
                    }
                }
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyMemoryToImageIndirectKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToImageIndirectKHR&      args)
{
    if (!args.pCopyMemoryToImageIndirectInfo.IsNull() && (args.pCopyMemoryToImageIndirectInfo.HasData()))
    {
        auto pCopyMemoryToImageIndirectInfo_ptr = args.pCopyMemoryToImageIndirectInfo.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pCopyMemoryToImageIndirectInfo_ptr->dstImage);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindTransformFeedbackBuffersEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindTransformFeedbackBuffersEXT&   args)
{
    if (!args.pBuffers.IsNull() && (args.pBuffers.HasData()))
    {
        auto pBuffers_ptr = args.pBuffers.GetPointer();
        size_t pBuffers_count = args.pBuffers.GetLength();
        for (size_t pBuffers_index = 0; pBuffers_index < pBuffers_count; ++pBuffers_index)
        {
            GetTable().AddResourceToUser(args.commandBuffer, pBuffers_ptr[pBuffers_index]);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBeginTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginTransformFeedbackEXT&         args)
{
    if (!args.pCounterBuffers.IsNull() && (args.pCounterBuffers.HasData()))
    {
        auto pCounterBuffers_ptr = args.pCounterBuffers.GetPointer();
        size_t pCounterBuffers_count = args.pCounterBuffers.GetLength();
        for (size_t pCounterBuffers_index = 0; pCounterBuffers_index < pCounterBuffers_count; ++pCounterBuffers_index)
        {
            GetTable().AddResourceToUser(args.commandBuffer, pCounterBuffers_ptr[pCounterBuffers_index]);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdEndTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndTransformFeedbackEXT&           args)
{
    if (!args.pCounterBuffers.IsNull() && (args.pCounterBuffers.HasData()))
    {
        auto pCounterBuffers_ptr = args.pCounterBuffers.GetPointer();
        size_t pCounterBuffers_count = args.pCounterBuffers.GetLength();
        for (size_t pCounterBuffers_index = 0; pCounterBuffers_index < pCounterBuffers_count; ++pCounterBuffers_index)
        {
            GetTable().AddResourceToUser(args.commandBuffer, pCounterBuffers_ptr[pCounterBuffers_index]);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawIndirectByteCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectByteCountEXT&          args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.counterBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCountAMD&              args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.buffer);
    GetTable().AddResourceToUser(args.commandBuffer, args.countBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCountAMD&       args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.buffer);
    GetTable().AddResourceToUser(args.commandBuffer, args.countBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginConditionalRenderingEXT&      args)
{
    if (!args.pConditionalRenderingBegin.IsNull() && (args.pConditionalRenderingBegin.HasData()))
    {
        auto pConditionalRenderingBegin_ptr = args.pConditionalRenderingBegin.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pConditionalRenderingBegin_ptr->buffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    args::CmdBindShadingRateImageNV&            args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.imageView);
}

void VulkanReferencedResourceConsumer::Process_vkCmdBuildAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    args::CmdBuildAccelerationStructureNV&      args)
{
    if (!args.pInfo.IsNull() && (args.pInfo.HasData()))
    {
        auto pInfo_ptr = args.pInfo.GetMetaStructPointer();
        if (!pInfo_ptr->pGeometries->IsNull() && (pInfo_ptr->pGeometries->HasData()))
        {
            auto pGeometries_ptr = pInfo_ptr->pGeometries->GetMetaStructPointer();
            size_t pGeometries_count = pInfo_ptr->pGeometries->GetLength();
            for (size_t pGeometries_index = 0; pGeometries_index < pGeometries_count; ++pGeometries_index)
            {
                GetTable().AddResourceToUser(args.commandBuffer, pGeometries_ptr[pGeometries_index].geometry->triangles->vertexData);
                GetTable().AddResourceToUser(args.commandBuffer, pGeometries_ptr[pGeometries_index].geometry->triangles->indexData);
                GetTable().AddResourceToUser(args.commandBuffer, pGeometries_ptr[pGeometries_index].geometry->triangles->transformData);
                GetTable().AddResourceToUser(args.commandBuffer, pGeometries_ptr[pGeometries_index].geometry->aabbs->aabbData);
            }
        }
    }
    GetTable().AddResourceToUser(args.commandBuffer, args.instanceData);
    GetTable().AddResourceToUser(args.commandBuffer, args.scratch);
}

void VulkanReferencedResourceConsumer::Process_vkCmdTraceRaysNV(
    const ApiCallInfo&                          call_info,
    args::CmdTraceRaysNV&                       args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.raygenShaderBindingTableBuffer);
    GetTable().AddResourceToUser(args.commandBuffer, args.missShaderBindingTableBuffer);
    GetTable().AddResourceToUser(args.commandBuffer, args.hitShaderBindingTableBuffer);
    GetTable().AddResourceToUser(args.commandBuffer, args.callableShaderBindingTableBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdWriteBufferMarkerAMD(
    const ApiCallInfo&                          call_info,
    args::CmdWriteBufferMarkerAMD&              args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.dstBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdWriteBufferMarker2AMD(
    const ApiCallInfo&                          call_info,
    args::CmdWriteBufferMarker2AMD&             args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.dstBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawMeshTasksIndirectNV(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectNV&           args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.buffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawMeshTasksIndirectCountNV(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectCountNV&      args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.buffer);
    GetTable().AddResourceToUser(args.commandBuffer, args.countBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindVertexBuffers2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers2EXT&             args)
{
    if (!args.pBuffers.IsNull() && (args.pBuffers.HasData()))
    {
        auto pBuffers_ptr = args.pBuffers.GetPointer();
        size_t pBuffers_count = args.pBuffers.GetLength();
        for (size_t pBuffers_index = 0; pBuffers_index < pBuffers_count; ++pBuffers_index)
        {
            GetTable().AddResourceToUser(args.commandBuffer, pBuffers_ptr[pBuffers_index]);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    args::CmdPreprocessGeneratedCommandsNV&     args)
{
    if (!args.pGeneratedCommandsInfo.IsNull() && (args.pGeneratedCommandsInfo.HasData()))
    {
        auto pGeneratedCommandsInfo_ptr = args.pGeneratedCommandsInfo.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pGeneratedCommandsInfo_ptr->pipeline);

        if (!pGeneratedCommandsInfo_ptr->pStreams->IsNull() && (pGeneratedCommandsInfo_ptr->pStreams->HasData()))
        {
            auto pStreams_ptr = pGeneratedCommandsInfo_ptr->pStreams->GetMetaStructPointer();
            size_t pStreams_count = pGeneratedCommandsInfo_ptr->pStreams->GetLength();
            for (size_t pStreams_index = 0; pStreams_index < pStreams_count; ++pStreams_index)
            {
                GetTable().AddResourceToUser(args.commandBuffer, pStreams_ptr[pStreams_index].buffer);
            }
        }
        GetTable().AddResourceToUser(args.commandBuffer, pGeneratedCommandsInfo_ptr->preprocessBuffer);
        GetTable().AddResourceToUser(args.commandBuffer, pGeneratedCommandsInfo_ptr->sequencesCountBuffer);
        GetTable().AddResourceToUser(args.commandBuffer, pGeneratedCommandsInfo_ptr->sequencesIndexBuffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    args::CmdExecuteGeneratedCommandsNV&        args)
{
    if (!args.pGeneratedCommandsInfo.IsNull() && (args.pGeneratedCommandsInfo.HasData()))
    {
        auto pGeneratedCommandsInfo_ptr = args.pGeneratedCommandsInfo.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pGeneratedCommandsInfo_ptr->pipeline);

        if (!pGeneratedCommandsInfo_ptr->pStreams->IsNull() && (pGeneratedCommandsInfo_ptr->pStreams->HasData()))
        {
            auto pStreams_ptr = pGeneratedCommandsInfo_ptr->pStreams->GetMetaStructPointer();
            size_t pStreams_count = pGeneratedCommandsInfo_ptr->pStreams->GetLength();
            for (size_t pStreams_index = 0; pStreams_index < pStreams_count; ++pStreams_index)
            {
                GetTable().AddResourceToUser(args.commandBuffer, pStreams_ptr[pStreams_index].buffer);
            }
        }
        GetTable().AddResourceToUser(args.commandBuffer, pGeneratedCommandsInfo_ptr->preprocessBuffer);
        GetTable().AddResourceToUser(args.commandBuffer, pGeneratedCommandsInfo_ptr->sequencesCountBuffer);
        GetTable().AddResourceToUser(args.commandBuffer, pGeneratedCommandsInfo_ptr->sequencesIndexBuffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindPipelineShaderGroupNV(
    const ApiCallInfo&                          call_info,
    args::CmdBindPipelineShaderGroupNV&         args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.pipeline);
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindDescriptorBuffersEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorBuffersEXT&          args)
{
    if (!args.pBindingInfos.IsNull() && (args.pBindingInfos.HasData()))
    {
        auto pBindingInfos_ptr = args.pBindingInfos.GetMetaStructPointer();
        size_t pBindingInfos_count = args.pBindingInfos.GetLength();
        for (size_t pBindingInfos_index = 0; pBindingInfos_index < pBindingInfos_count; ++pBindingInfos_index)
        {
            {
                const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkDescriptorBufferBindingPushDescriptorBufferHandleEXT>(pBindingInfos_ptr[pBindingInfos_index].pNext);
                if (ext_struct_info != nullptr)
                {
                    GetTable().AddResourceToUser(args.commandBuffer, ext_struct_info->buffer);
                }
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    args::CmdBindInvocationMaskHUAWEI&          args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.imageView);
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawClusterIndirectHUAWEI(
    const ApiCallInfo&                          call_info,
    args::CmdDrawClusterIndirectHUAWEI&         args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.buffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdUpdatePipelineIndirectBufferNV(
    const ApiCallInfo&                          call_info,
    args::CmdUpdatePipelineIndirectBufferNV&    args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.pipeline);
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyTensorARM(
    const ApiCallInfo&                          call_info,
    args::CmdCopyTensorARM&                     args)
{
    if (!args.pCopyTensorInfo.IsNull() && (args.pCopyTensorInfo.HasData()))
    {
        auto pCopyTensorInfo_ptr = args.pCopyTensorInfo.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pCopyTensorInfo_ptr->srcTensor);
        GetTable().AddResourceToUser(args.commandBuffer, pCopyTensorInfo_ptr->dstTensor);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdPreprocessGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdPreprocessGeneratedCommandsEXT&    args)
{
    if (!args.pGeneratedCommandsInfo.IsNull() && (args.pGeneratedCommandsInfo.HasData()))
    {
        auto pGeneratedCommandsInfo_ptr = args.pGeneratedCommandsInfo.GetMetaStructPointer();
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkGeneratedCommandsPipelineInfoEXT>(pGeneratedCommandsInfo_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                GetTable().AddResourceToUser(args.commandBuffer, ext_struct_info->pipeline);
            }
        }
    }
    GetTable().AddUserToUser(args.commandBuffer, args.stateCommandBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdExecuteGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdExecuteGeneratedCommandsEXT&       args)
{
    if (!args.pGeneratedCommandsInfo.IsNull() && (args.pGeneratedCommandsInfo.HasData()))
    {
        auto pGeneratedCommandsInfo_ptr = args.pGeneratedCommandsInfo.GetMetaStructPointer();
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkGeneratedCommandsPipelineInfoEXT>(pGeneratedCommandsInfo_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                GetTable().AddResourceToUser(args.commandBuffer, ext_struct_info->pipeline);
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBuildAccelerationStructuresKHR&    args)
{
    if (!args.pInfos.IsNull() && (args.pInfos.HasData()))
    {
        auto pInfos_ptr = args.pInfos.GetMetaStructPointer();
        size_t pInfos_count = args.pInfos.GetLength();
        for (size_t pInfos_index = 0; pInfos_index < pInfos_count; ++pInfos_index)
        {
            GetTable().AddResourceToUser(args.commandBuffer, pInfos_ptr[pInfos_index].srcAccelerationStructure);
            GetTable().AddResourceToUser(args.commandBuffer, pInfos_ptr[pInfos_index].dstAccelerationStructure);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBuildAccelerationStructuresIndirectKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBuildAccelerationStructuresIndirectKHR& args)
{
    if (!args.pInfos.IsNull() && (args.pInfos.HasData()))
    {
        auto pInfos_ptr = args.pInfos.GetMetaStructPointer();
        size_t pInfos_count = args.pInfos.GetLength();
        for (size_t pInfos_index = 0; pInfos_index < pInfos_count; ++pInfos_index)
        {
            GetTable().AddResourceToUser(args.commandBuffer, pInfos_ptr[pInfos_index].srcAccelerationStructure);
            GetTable().AddResourceToUser(args.commandBuffer, pInfos_ptr[pInfos_index].dstAccelerationStructure);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyAccelerationStructureKHR&      args)
{
    if (!args.pInfo.IsNull() && (args.pInfo.HasData()))
    {
        auto pInfo_ptr = args.pInfo.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pInfo_ptr->src);
        GetTable().AddResourceToUser(args.commandBuffer, pInfo_ptr->dst);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyAccelerationStructureToMemoryKHR& args)
{
    if (!args.pInfo.IsNull() && (args.pInfo.HasData()))
    {
        auto pInfo_ptr = args.pInfo.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pInfo_ptr->src);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToAccelerationStructureKHR& args)
{
    if (!args.pInfo.IsNull() && (args.pInfo.HasData()))
    {
        auto pInfo_ptr = args.pInfo.GetMetaStructPointer();
        GetTable().AddResourceToUser(args.commandBuffer, pInfo_ptr->dst);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::CmdWriteAccelerationStructuresPropertiesKHR& args)
{
    if (!args.pAccelerationStructures.IsNull() && (args.pAccelerationStructures.HasData()))
    {
        auto pAccelerationStructures_ptr = args.pAccelerationStructures.GetPointer();
        size_t pAccelerationStructures_count = args.pAccelerationStructures.GetLength();
        for (size_t pAccelerationStructures_index = 0; pAccelerationStructures_index < pAccelerationStructures_count; ++pAccelerationStructures_index)
        {
            GetTable().AddResourceToUser(args.commandBuffer, pAccelerationStructures_ptr[pAccelerationStructures_index]);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawMeshTasksIndirectEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectEXT&          args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.buffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawMeshTasksIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectCountEXT&     args)
{
    GetTable().AddResourceToUser(args.commandBuffer, args.buffer);
    GetTable().AddResourceToUser(args.commandBuffer, args.countBuffer);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
