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

#include "generated/generated_vulkan_struct_handle_wrappers.h"

#include "vulkan/vk_layer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void UnwrapVulkanStructHandles(VkBufferMemoryBarrier* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkImageMemoryBarrier* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkDeviceCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapVulkanStructHandles(VkSubmitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapVulkanStructHandles(VkMappedMemoryRange* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkMemoryAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapVulkanStructHandles(VkSparseMemoryBind* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkSparseBufferMemoryBindInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pBinds = UnwrapVulkanStructArrayHandles(value->pBinds, value->bindCount, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkSparseImageOpaqueMemoryBindInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pBinds = UnwrapVulkanStructArrayHandles(value->pBinds, value->bindCount, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkSparseImageMemoryBind* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkSparseImageMemoryBindInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pBinds = UnwrapVulkanStructArrayHandles(value->pBinds, value->bindCount, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkBindSparseInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
        value->pBufferBinds = UnwrapVulkanStructArrayHandles(value->pBufferBinds, value->bufferBindCount, unwrap_memory);
        value->pImageOpaqueBinds = UnwrapVulkanStructArrayHandles(value->pImageOpaqueBinds, value->imageOpaqueBindCount, unwrap_memory);
        value->pImageBinds = UnwrapVulkanStructArrayHandles(value->pImageBinds, value->imageBindCount, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkBufferViewCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkImageCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapVulkanStructHandles(VkImageViewCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapVulkanStructHandles(VkShaderModuleCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapVulkanStructHandles(VkPipelineShaderStageCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapVulkanStructHandles(VkComputePipelineCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapVulkanStructHandles(&value->stage, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkGraphicsPipelineCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
        value->pStages = UnwrapVulkanStructArrayHandles(value->pStages, value->stageCount, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkPipelineLayoutCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkSamplerCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapVulkanStructHandles(VkCopyDescriptorSet* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkDescriptorBufferInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkDescriptorSetAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkDescriptorSetLayoutBinding* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkDescriptorSetLayoutCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pBindings = UnwrapVulkanStructArrayHandles(value->pBindings, value->bindingCount, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkFramebufferCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkCommandBufferAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkCommandBufferInheritanceInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkCommandBufferBeginInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pInheritanceInfo = UnwrapVulkanStructPtrHandles(value->pInheritanceInfo, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkRenderPassBeginInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapVulkanStructHandles(VkBindBufferMemoryInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkBindImageMemoryInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapVulkanStructHandles(VkMemoryDedicatedAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkPhysicalDeviceGroupProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkDeviceGroupDeviceCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkBufferMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkImageMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkImageSparseMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkSamplerYcbcrConversionInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkDescriptorUpdateTemplateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkRenderPassAttachmentBeginInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkSemaphoreWaitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkSemaphoreSignalInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkBufferDeviceAddressInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkDeviceMemoryOpaqueCaptureAddressInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkBufferMemoryBarrier2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkImageMemoryBarrier2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkDependencyInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pBufferMemoryBarriers = UnwrapVulkanStructArrayHandles(value->pBufferMemoryBarriers, value->bufferMemoryBarrierCount, unwrap_memory);
        value->pImageMemoryBarriers = UnwrapVulkanStructArrayHandles(value->pImageMemoryBarriers, value->imageMemoryBarrierCount, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkSemaphoreSubmitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkCommandBufferSubmitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkSubmitInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
        value->pWaitSemaphoreInfos = UnwrapVulkanStructArrayHandles(value->pWaitSemaphoreInfos, value->waitSemaphoreInfoCount, unwrap_memory);
        value->pCommandBufferInfos = UnwrapVulkanStructArrayHandles(value->pCommandBufferInfos, value->commandBufferInfoCount, unwrap_memory);
        value->pSignalSemaphoreInfos = UnwrapVulkanStructArrayHandles(value->pSignalSemaphoreInfos, value->signalSemaphoreInfoCount, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkCopyBufferInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkCopyImageInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkCopyBufferToImageInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkCopyImageToBufferInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkBlitImageInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkResolveImageInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkRenderingAttachmentInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkRenderingInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
        value->pColorAttachments = UnwrapVulkanStructArrayHandles(value->pColorAttachments, value->colorAttachmentCount, unwrap_memory);
        value->pDepthAttachment = UnwrapVulkanStructPtrHandles(value->pDepthAttachment, unwrap_memory);
        value->pStencilAttachment = UnwrapVulkanStructPtrHandles(value->pStencilAttachment, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkDeviceImageMemoryRequirements* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pCreateInfo = UnwrapVulkanStructPtrHandles(value->pCreateInfo, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkSwapchainCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkPresentInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapVulkanStructHandles(VkImageSwapchainCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkBindImageMemorySwapchainInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkAcquireNextImageInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkDisplayModePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkDisplayPlanePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkDisplayPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkDisplaySurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkVideoPictureResourceInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkVideoReferenceSlotInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pPictureResource = UnwrapVulkanStructPtrHandles(value->pPictureResource, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkBindVideoSessionMemoryInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkVideoSessionParametersCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkVideoBeginCodingInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pReferenceSlots = UnwrapVulkanStructArrayHandles(value->pReferenceSlots, value->referenceSlotCount, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkVideoDecodeInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
        UnwrapVulkanStructHandles(&value->dstPictureResource, unwrap_memory);
        value->pSetupReferenceSlot = UnwrapVulkanStructPtrHandles(value->pSetupReferenceSlot, unwrap_memory);
        value->pReferenceSlots = UnwrapVulkanStructArrayHandles(value->pReferenceSlots, value->referenceSlotCount, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkRenderingFragmentShadingRateAttachmentInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkRenderingFragmentDensityMapAttachmentInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkMemoryGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkMemoryGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkWin32KeyedMutexAcquireReleaseInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkImportSemaphoreWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkSemaphoreGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkImportSemaphoreFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkSemaphoreGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkImportFenceWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkFenceGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkImportFenceFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkFenceGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkPhysicalDeviceSurfaceInfo2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkDisplayProperties2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapVulkanStructHandles(&value->displayProperties, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkDisplayPlaneProperties2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapVulkanStructHandles(&value->displayPlaneProperties, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkDisplayModeProperties2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapVulkanStructHandles(&value->displayModeProperties, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkDisplayPlaneInfo2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkPipelineInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkPipelineExecutableInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkMemoryMapInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkMemoryUnmapInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkPipelineLibraryCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkVideoEncodeInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
        UnwrapVulkanStructHandles(&value->srcPictureResource, unwrap_memory);
        value->pSetupReferenceSlot = UnwrapVulkanStructPtrHandles(value->pSetupReferenceSlot, unwrap_memory);
        value->pReferenceSlots = UnwrapVulkanStructArrayHandles(value->pReferenceSlots, value->referenceSlotCount, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkVideoEncodeSessionParametersGetInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkDeviceImageSubresourceInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pCreateInfo = UnwrapVulkanStructPtrHandles(value->pCreateInfo, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkVideoInlineQueryInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkBindDescriptorSetsInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapVulkanStructHandles(VkPushConstantsInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapVulkanStructHandles(VkPushDescriptorSetInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
        value->pDescriptorWrites = UnwrapVulkanStructArrayHandles(value->pDescriptorWrites, value->descriptorWriteCount, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkPushDescriptorSetWithTemplateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapVulkanStructHandles(VkSetDescriptorBufferOffsetsInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapVulkanStructHandles(VkBindDescriptorBufferEmbeddedSamplersInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapVulkanStructHandles(VkDebugMarkerObjectNameInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkDebugMarkerObjectTagInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkDedicatedAllocationMemoryAllocateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkImageViewHandleInfoNVX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkWin32KeyedMutexAcquireReleaseInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkConditionalRenderingBeginInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkDebugUtilsObjectNameInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkDebugUtilsObjectTagInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkMemoryGetAndroidHardwareBufferInfoANDROID* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkShaderModuleValidationCacheCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkRayTracingPipelineCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pStages = UnwrapVulkanStructArrayHandles(value->pStages, value->stageCount, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkGeometryTrianglesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkGeometryAABBNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkGeometryDataNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapVulkanStructHandles(&value->triangles, unwrap_memory);
        UnwrapVulkanStructHandles(&value->aabbs, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkGeometryNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapVulkanStructHandles(&value->geometry, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkAccelerationStructureInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pGeometries = UnwrapVulkanStructArrayHandles(value->pGeometries, value->geometryCount, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkAccelerationStructureCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapVulkanStructHandles(&value->info, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkBindAccelerationStructureMemoryInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkWriteDescriptorSetAccelerationStructureNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkAccelerationStructureMemoryRequirementsInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkCopyMemoryToImageInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkCopyImageToMemoryInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkCopyImageToImageInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkHostImageLayoutTransitionInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkSwapchainPresentFenceInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkReleaseSwapchainImagesInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkGraphicsShaderGroupCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pStages = UnwrapVulkanStructArrayHandles(value->pStages, value->stageCount, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkGraphicsPipelineShaderGroupsCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pGroups = UnwrapVulkanStructArrayHandles(value->pGroups, value->groupCount, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkIndirectCommandsStreamNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkIndirectCommandsLayoutTokenNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkIndirectCommandsLayoutCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pTokens = UnwrapVulkanStructArrayHandles(value->pTokens, value->tokenCount, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkGeneratedCommandsInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pStreams = UnwrapVulkanStructArrayHandles(value->pStreams, value->streamCount, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkGeneratedCommandsMemoryRequirementsInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkMemoryGetZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkImportSemaphoreZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkSemaphoreGetZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkMemoryGetRemoteAddressInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkFrameBoundaryEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkMicromapBuildInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkMicromapCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkCopyMicromapToMemoryInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkCopyMemoryToMicromapInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkCopyMicromapInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkAccelerationStructureTrianglesOpacityMicromapEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkAccelerationStructureTrianglesDisplacementMicromapNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkDescriptorSetBindingReferenceVALVE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkRenderPassStripeSubmitInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pStripeSemaphoreInfos = UnwrapVulkanStructArrayHandles(value->pStripeSemaphoreInfos, value->stripeSemaphoreInfoCount, unwrap_memory);
    }
}

void UnwrapVulkanStructHandles(VkPipelineIndirectDeviceAddressInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkShaderCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkLatencySleepInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkAccelerationStructureGeometryTrianglesDataKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapVulkanStructHandles(VkAccelerationStructureBuildGeometryInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkAccelerationStructureCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkWriteDescriptorSetAccelerationStructureKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkAccelerationStructureDeviceAddressInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkCopyAccelerationStructureToMemoryInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkCopyMemoryToAccelerationStructureInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkCopyAccelerationStructureInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapVulkanStructHandles(VkRayTracingPipelineCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pStages = UnwrapVulkanStructArrayHandles(value->pStages, value->stageCount, unwrap_memory);
        value->pLibraryInfo = UnwrapVulkanStructPtrHandles(value->pLibraryInfo, unwrap_memory);
    }
}

VkBaseInStructure* CopyPNextStruct(const VkBaseInStructure* base, HandleUnwrapMemory* unwrap_memory)
{
    assert(base != nullptr);

    VkBaseInStructure* copy = nullptr;
    switch (base->sType)
    {
    default:
        GFXRECON_LOG_WARNING("Failed to copy entire pNext chain when unwrapping handles due to unrecognized sType %d", base->sType);
        break;
    case VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkLayerInstanceCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkLayerDeviceCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkShaderModuleCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineLayoutCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceSubgroupProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevice16BitStorageFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkMemoryDedicatedRequirements*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkMemoryDedicatedAllocateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkMemoryAllocateFlagsInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDeviceGroupRenderPassBeginInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDeviceGroupCommandBufferBeginInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDeviceGroupSubmitInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDeviceGroupBindSparseInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkBindBufferMemoryDeviceGroupInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkBindImageMemoryDeviceGroupInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceFeatures2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevicePointClippingProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkRenderPassInputAttachmentAspectCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkImageViewUsageCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineTessellationDomainOriginStateCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkRenderPassMultiviewCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMultiviewFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMultiviewProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceVariablePointersFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceProtectedMemoryFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceProtectedMemoryProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkProtectedSubmitInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSamplerYcbcrConversionInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkBindImagePlaneMemoryInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkImagePlaneMemoryRequirementsInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSamplerYcbcrConversionImageFormatProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceExternalImageFormatInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkExternalImageFormatProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceIDProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkExternalMemoryImageCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkExternalMemoryBufferCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkExportMemoryAllocateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkExportFenceCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkExportSemaphoreCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance3Properties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderDrawParametersFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceVulkan11Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceVulkan11Properties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceVulkan12Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceVulkan12Properties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkImageFormatListCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevice8BitStorageFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDriverProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderAtomicInt64Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderFloat16Int8Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceFloatControlsProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDescriptorSetLayoutBindingFlagsCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDescriptorSetVariableDescriptorCountAllocateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDescriptorSetVariableDescriptorCountLayoutSupport*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSubpassDescriptionDepthStencilResolve*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDepthStencilResolveProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceScalarBlockLayoutFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkImageStencilUsageCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSamplerReductionModeCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceSamplerFilterMinmaxProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceVulkanMemoryModelFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceImagelessFramebufferFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkFramebufferAttachmentsCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkRenderPassAttachmentBeginInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkAttachmentReferenceStencilLayout*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkAttachmentDescriptionStencilLayout*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceHostQueryResetFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSemaphoreTypeCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkTimelineSemaphoreSubmitInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkBufferOpaqueCaptureAddressCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkMemoryOpaqueCaptureAddressAllocateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceVulkan13Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceVulkan13Properties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineCreationFeedbackCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderTerminateInvocationFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevicePrivateDataFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDevicePrivateDataCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevicePipelineCreationCacheControlFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkMemoryBarrier2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceSynchronization2Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceImageRobustnessFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineShaderStageRequiredSubgroupSizeCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkWriteDescriptorSetInlineUniformBlock*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDescriptorPoolInlineUniformBlockCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineRenderingCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDynamicRenderingFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkCommandBufferInheritanceRenderingInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkFormatProperties3*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance4Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance4Properties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDeviceGroupPresentInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDeviceGroupSwapchainCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDisplayPresentInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkQueueFamilyQueryResultStatusPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkQueueFamilyVideoPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoProfileInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoProfileListInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoDecodeCapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoDecodeUsageInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH264CapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH264QualityLevelPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH264SessionCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH264SessionParametersAddInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH264SessionParametersCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH264SessionParametersGetInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH264SessionParametersFeedbackInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH264PictureInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH264DpbSlotInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH264ProfileInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH264RateControlInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH264RateControlLayerInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH264GopRemainingFrameInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH265CapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH265SessionCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUALITY_LEVEL_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH265QualityLevelPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH265SessionParametersAddInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH265SessionParametersCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_GET_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH265SessionParametersGetInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH265SessionParametersFeedbackInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PICTURE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH265PictureInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH265DpbSlotInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH265ProfileInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH265RateControlInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH265RateControlLayerInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_GOP_REMAINING_FRAME_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeH265GopRemainingFrameInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoDecodeH264ProfileInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoDecodeH264CapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoDecodeH264SessionParametersAddInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoDecodeH264SessionParametersCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoDecodeH264PictureInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoDecodeH264DpbSlotInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkRenderingFragmentDensityMapAttachmentInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkAttachmentSampleCountInfoAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkMultiviewPerViewAttributesInfoNVX*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkImportMemoryWin32HandleInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkExportMemoryWin32HandleInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkImportMemoryFdInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkExportSemaphoreWin32HandleInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkD3D12FenceSubmitInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevicePushDescriptorPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPresentRegionsKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSharedPresentSurfaceCapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkExportFenceWin32HandleInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevicePerformanceQueryFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevicePerformanceQueryPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkQueryPoolPerformanceCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPerformanceQuerySubmitInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevicePortabilitySubsetPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderClockFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoDecodeH265ProfileInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoDecodeH265CapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoDecodeH265SessionParametersAddInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoDecodeH265SessionParametersCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoDecodeH265PictureInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoDecodeH265DpbSlotInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDeviceQueueGlobalPriorityCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkQueueFamilyGlobalPriorityPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkFragmentShadingRateAttachmentInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineFragmentShadingRateStateCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShadingRatePropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkRenderingAttachmentLocationInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkRenderingInputAttachmentIndexInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderQuadControlFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSurfaceProtectedCapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevicePresentWaitFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineLibraryCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PRESENT_ID_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPresentIdKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevicePresentIdFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeCapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkQueryPoolVideoEncodeFeedbackCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeUsageInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeRateControlInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoEncodeQualityLevelInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkQueueFamilyCheckpointProperties2NV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance5FeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance5PropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineCreateFlags2CreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkBufferUsageFlags2CreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoDecodeAV1ProfileInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoDecodeAV1CapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoDecodeAV1SessionParametersCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoDecodeAV1PictureInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoDecodeAV1DpbSlotInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceVideoMaintenance1FeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkVideoInlineQueryInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineVertexInputDivisorStateCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderFloatControls2FeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceIndexTypeUint8FeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceLineRasterizationFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceLineRasterizationPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineRasterizationLineStateCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderExpectAssumeFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance6FeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance6PropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkBindMemoryStatusKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDebugReportCallbackCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineRasterizationStateRasterizationOrderAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDedicatedAllocationImageCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDedicatedAllocationBufferCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceTransformFeedbackPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineRasterizationStateStreamCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkTextureLODGatherFormatPropertiesAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceCornerSampledImageFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkExternalMemoryImageCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkExportMemoryAllocateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkImportMemoryWin32HandleInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkExportMemoryWin32HandleInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkValidationFlagsEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkImageViewASTCDecodeModeEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceASTCDecodeFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevicePipelineRobustnessFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevicePipelineRobustnessPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineRobustnessCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineViewportWScalingStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSwapchainCounterCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPresentTimesInfoGOOGLE*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineViewportSwizzleStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineDiscardRectangleStateCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineRasterizationConservativeStateCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineRasterizationDepthClipStateCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDebugUtilsObjectNameInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDebugUtilsMessengerCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkAndroidHardwareBufferUsageANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkAndroidHardwareBufferFormatPropertiesANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkImportAndroidHardwareBufferInfoANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkExternalFormatANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkAndroidHardwareBufferFormatProperties2ANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSampleLocationsInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkRenderPassSampleLocationsBeginInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineSampleLocationsStateCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceSampleLocationsPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineCoverageToColorStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineCoverageModulationStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDrmFormatModifierPropertiesListEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkImageDrmFormatModifierListCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkImageDrmFormatModifierExplicitCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDrmFormatModifierPropertiesList2EXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineViewportShadingRateImageStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShadingRateImageFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShadingRateImagePropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceImageViewImageFormatInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkFilterCubicImageViewImageFormatPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkImportMemoryHostPointerInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineCompilerControlCreateInfoAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDeviceMemoryOverallocationCreateInfoAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPresentFrameTokenGGP*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceExclusiveScissorFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkQueueFamilyCheckpointPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkQueryPoolPerformanceQueryCreateInfoINTEL*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevicePCIBusInfoPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSwapchainDisplayNativeHdrCreateInfoAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkRenderPassFragmentDensityMapCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderCoreProperties2AMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkMemoryPriorityAllocateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkBufferDeviceAddressCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkValidationFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineCoverageReductionStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceProvokingVertexFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceProvokingVertexPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSurfaceFullScreenExclusiveInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSurfaceCapabilitiesFullScreenExclusiveEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSurfaceFullScreenExclusiveWin32InfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceHostImageCopyFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceHostImageCopyPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSubresourceHostMemcpySizeEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkHostImageCopyDevicePerformanceQueryEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMapMemoryPlacedFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMapMemoryPlacedPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkMemoryMapPlacedInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSurfacePresentModeEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSurfacePresentScalingCapabilitiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSurfacePresentModeCompatibilityEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSwapchainPresentFenceInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSwapchainPresentModesCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSwapchainPresentModeInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSwapchainPresentScalingCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkGraphicsPipelineShaderGroupsCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkCommandBufferInheritanceViewportScissorInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkRenderPassTransformBeginInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkCommandBufferInheritanceRenderPassTransformInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDepthBiasRepresentationInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDeviceDeviceMemoryReportCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceRobustness2FeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceRobustness2PropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSamplerCustomBorderColorCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceCustomBorderColorPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevicePresentBarrierFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSurfaceCapabilitiesPresentBarrierNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSwapchainPresentBarrierCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDeviceDiagnosticsConfigCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkQueryLowLatencySupportNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkGraphicsPipelineLibraryCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineFragmentShadingRateEnumStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkAccelerationStructureGeometryMotionTrianglesDataNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkAccelerationStructureMotionInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkCopyCommandTransformInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkImageCompressionControlEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkImageCompressionPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevice4444FormatsFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceFaultFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkMutableDescriptorTypeCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDrmPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDeviceAddressBindingCallbackDataEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDepthClipControlFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineViewportDepthClipControlCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkImportMemoryZirconHandleInfoFUCHSIA*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceFrameBoundaryFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkFrameBoundaryEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSubpassResolvePerformanceQueryEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkMultisampledRenderToSingleSampledInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineColorWriteCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkImageViewMinLodCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMultiDrawFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMultiDrawPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderTileImageFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderTileImagePropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceOpacityMicromapPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkAccelerationStructureTrianglesOpacityMicromapEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDisplacementMicromapFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDisplacementMicromapPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkAccelerationStructureTrianglesDisplacementMicromapNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSamplerBorderColorComponentMappingCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDeviceQueueShaderCoreControlCreateInfoARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceSchedulingControlsFeaturesARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceSchedulingControlsPropertiesARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkImageViewSlicedCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDepthClampZeroOneFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceRenderPassStripedFeaturesARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceRenderPassStripedPropertiesARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkRenderPassStripeBeginInfoARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkRenderPassStripeSubmitInfoARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSubpassFragmentDensityMapOffsetEndInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkComputePipelineIndirectBufferInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkImageViewSampleWeightCreateInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceImageProcessingFeaturesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceImageProcessingPropertiesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceNestedCommandBufferFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceNestedCommandBufferPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkExternalMemoryAcquireUnmodifiedEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState3PropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkRenderPassCreationControlEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkRenderPassCreationFeedbackCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkRenderPassSubpassFeedbackCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkDirectDriverLoadingListLUNARG*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPipelineShaderStageModuleIdentifierCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceOpticalFlowFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceOpticalFlowPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkOpticalFlowImageFormatInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkOpticalFlowSessionCreatePrivateDataInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevicePipelineProtectedAccessFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceExternalFormatResolvePropertiesANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkAndroidHardwareBufferFormatResolvePropertiesANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderObjectFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderObjectPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkAmigoProfilingSubmitInfoSEC*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkLayerSettingsCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkLatencySubmissionPresentIdNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSwapchainLatencyCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkLatencySurfaceCapabilitiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDevicePerStageDescriptorSetFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceImageProcessing2FeaturesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceImageProcessing2PropertiesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSamplerBlockMatchWindowCreateInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceCubicWeightsFeaturesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSamplerCubicWeightsCreateInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkBlitImageCubicWeightsInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceCubicClampFeaturesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceLayeredDriverPropertiesMSFT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceRawAccessChainsFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingValidationFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceAccelerationStructurePropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingPipelinePropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceRayQueryFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapVulkanStructs(reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    }

    return copy;
}

const void* UnwrapPNextStructHandles(const void* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        const VkBaseInStructure* base = reinterpret_cast<const VkBaseInStructure*>(value);

        switch (base->sType)
        {
        default:
        {
            // This structure does not contain handles, but may point to a structure that does.
            VkBaseInStructure* copy = CopyPNextStruct(base, unwrap_memory);
            if (copy != nullptr)
            {
                copy->pNext = reinterpret_cast<const VkBaseInStructure*>(UnwrapPNextStructHandles(base->pNext, unwrap_memory));
            }
            return copy;
        }
        case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkShaderModuleCreateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkPipelineLayoutCreateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkMemoryDedicatedAllocateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkSamplerYcbcrConversionInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkRenderPassAttachmentBeginInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkRenderingFragmentDensityMapAttachmentInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkPipelineLibraryCreateInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkVideoInlineQueryInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_EXT:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkSwapchainPresentFenceInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkGraphicsPipelineShaderGroupsCreateInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkFrameBoundaryEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkAccelerationStructureTrianglesOpacityMicromapEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkAccelerationStructureTrianglesDisplacementMicromapNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkRenderPassStripeSubmitInfoARM*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
            return UnwrapVulkanStructPtrHandles(reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureKHR*>(base), unwrap_memory);
        }
    }

    return nullptr;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
