/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
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

void UnwrapStructHandles(VkBufferMemoryBarrier* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->buffer = GetWrappedHandle<VkBuffer>(value->buffer);
    }
}

void UnwrapStructHandles(VkImageMemoryBarrier* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->image = GetWrappedHandle<VkImage>(value->image);
    }
}

void UnwrapStructHandles(VkDeviceCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapStructHandles(VkSubmitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }

        value->pWaitSemaphores = UnwrapHandles<VkSemaphore>(value->pWaitSemaphores, value->waitSemaphoreCount, unwrap_memory);

        value->pCommandBuffers = UnwrapHandles<VkCommandBuffer>(value->pCommandBuffers, value->commandBufferCount, unwrap_memory);

        value->pSignalSemaphores = UnwrapHandles<VkSemaphore>(value->pSignalSemaphores, value->signalSemaphoreCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkMappedMemoryRange* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->memory = GetWrappedHandle<VkDeviceMemory>(value->memory);
    }
}

void UnwrapStructHandles(VkMemoryAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapStructHandles(VkSparseMemoryBind* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->memory = GetWrappedHandle<VkDeviceMemory>(value->memory);
    }
}

void UnwrapStructHandles(VkSparseBufferMemoryBindInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->buffer = GetWrappedHandle<VkBuffer>(value->buffer);

        value->pBinds = UnwrapStructArrayHandles(value->pBinds, value->bindCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkSparseImageOpaqueMemoryBindInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->image = GetWrappedHandle<VkImage>(value->image);

        value->pBinds = UnwrapStructArrayHandles(value->pBinds, value->bindCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkSparseImageMemoryBind* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->memory = GetWrappedHandle<VkDeviceMemory>(value->memory);
    }
}

void UnwrapStructHandles(VkSparseImageMemoryBindInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->image = GetWrappedHandle<VkImage>(value->image);

        value->pBinds = UnwrapStructArrayHandles(value->pBinds, value->bindCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkBindSparseInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pWaitSemaphores = UnwrapHandles<VkSemaphore>(value->pWaitSemaphores, value->waitSemaphoreCount, unwrap_memory);

        value->pBufferBinds = UnwrapStructArrayHandles(value->pBufferBinds, value->bufferBindCount, unwrap_memory);

        value->pImageOpaqueBinds = UnwrapStructArrayHandles(value->pImageOpaqueBinds, value->imageOpaqueBindCount, unwrap_memory);

        value->pImageBinds = UnwrapStructArrayHandles(value->pImageBinds, value->imageBindCount, unwrap_memory);

        value->pSignalSemaphores = UnwrapHandles<VkSemaphore>(value->pSignalSemaphores, value->signalSemaphoreCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkBufferCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapStructHandles(VkBufferViewCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->buffer = GetWrappedHandle<VkBuffer>(value->buffer);
    }
}

void UnwrapStructHandles(VkImageCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapStructHandles(VkImageViewCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }

        value->image = GetWrappedHandle<VkImage>(value->image);
    }
}

void UnwrapStructHandles(VkShaderModuleCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapStructHandles(VkPipelineShaderStageCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->module = GetWrappedHandle<VkShaderModule>(value->module);
    }
}

void UnwrapStructHandles(VkComputePipelineCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }

        UnwrapStructHandles(&value->stage, unwrap_memory);

        value->layout = GetWrappedHandle<VkPipelineLayout>(value->layout);

        value->basePipelineHandle = GetWrappedHandle<VkPipeline>(value->basePipelineHandle);
    }
}

void UnwrapStructHandles(VkGraphicsPipelineCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }

        value->pStages = UnwrapStructArrayHandles(value->pStages, value->stageCount, unwrap_memory);

        value->layout = GetWrappedHandle<VkPipelineLayout>(value->layout);

        value->renderPass = GetWrappedHandle<VkRenderPass>(value->renderPass);

        value->basePipelineHandle = GetWrappedHandle<VkPipeline>(value->basePipelineHandle);
    }
}

void UnwrapStructHandles(VkPipelineLayoutCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pSetLayouts = UnwrapHandles<VkDescriptorSetLayout>(value->pSetLayouts, value->setLayoutCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkSamplerCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }
    }
}

void UnwrapStructHandles(VkCopyDescriptorSet* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->srcSet = GetWrappedHandle<VkDescriptorSet>(value->srcSet);

        value->dstSet = GetWrappedHandle<VkDescriptorSet>(value->dstSet);
    }
}

void UnwrapStructHandles(VkDescriptorBufferInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->buffer = GetWrappedHandle<VkBuffer>(value->buffer);
    }
}

void UnwrapStructHandles(VkDescriptorSetAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->descriptorPool = GetWrappedHandle<VkDescriptorPool>(value->descriptorPool);

        value->pSetLayouts = UnwrapHandles<VkDescriptorSetLayout>(value->pSetLayouts, value->descriptorSetCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkDescriptorSetLayoutBinding* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pImmutableSamplers = UnwrapHandles<VkSampler>(value->pImmutableSamplers, value->descriptorCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkDescriptorSetLayoutCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pBindings = UnwrapStructArrayHandles(value->pBindings, value->bindingCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkFramebufferCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->renderPass = GetWrappedHandle<VkRenderPass>(value->renderPass);

        value->pAttachments = UnwrapHandles<VkImageView>(value->pAttachments, value->attachmentCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkCommandBufferAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->commandPool = GetWrappedHandle<VkCommandPool>(value->commandPool);
    }
}

void UnwrapStructHandles(VkCommandBufferInheritanceInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->renderPass = GetWrappedHandle<VkRenderPass>(value->renderPass);

        value->framebuffer = GetWrappedHandle<VkFramebuffer>(value->framebuffer);
    }
}

void UnwrapStructHandles(VkCommandBufferBeginInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pInheritanceInfo = UnwrapStructPtrHandles(value->pInheritanceInfo, unwrap_memory);
    }
}

void UnwrapStructHandles(VkRenderPassBeginInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }

        value->renderPass = GetWrappedHandle<VkRenderPass>(value->renderPass);

        value->framebuffer = GetWrappedHandle<VkFramebuffer>(value->framebuffer);
    }
}

void UnwrapStructHandles(VkBindBufferMemoryInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->buffer = GetWrappedHandle<VkBuffer>(value->buffer);

        value->memory = GetWrappedHandle<VkDeviceMemory>(value->memory);
    }
}

void UnwrapStructHandles(VkBindImageMemoryInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }

        value->image = GetWrappedHandle<VkImage>(value->image);

        value->memory = GetWrappedHandle<VkDeviceMemory>(value->memory);
    }
}

void UnwrapStructHandles(VkMemoryDedicatedAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->image = GetWrappedHandle<VkImage>(value->image);

        value->buffer = GetWrappedHandle<VkBuffer>(value->buffer);
    }
}

void UnwrapStructHandles(VkPhysicalDeviceGroupProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        std::transform(value->physicalDevices, value->physicalDevices + value->physicalDeviceCount, value->physicalDevices, GetWrappedHandle<VkPhysicalDevice>);
    }
}

void UnwrapStructHandles(VkDeviceGroupDeviceCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pPhysicalDevices = UnwrapHandles<VkPhysicalDevice>(value->pPhysicalDevices, value->physicalDeviceCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkBufferMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->buffer = GetWrappedHandle<VkBuffer>(value->buffer);
    }
}

void UnwrapStructHandles(VkImageMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->image = GetWrappedHandle<VkImage>(value->image);
    }
}

void UnwrapStructHandles(VkImageSparseMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->image = GetWrappedHandle<VkImage>(value->image);
    }
}

void UnwrapStructHandles(VkSamplerYcbcrConversionInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->conversion = GetWrappedHandle<VkSamplerYcbcrConversion>(value->conversion);
    }
}

void UnwrapStructHandles(VkDescriptorUpdateTemplateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->descriptorSetLayout = GetWrappedHandle<VkDescriptorSetLayout>(value->descriptorSetLayout);

        value->pipelineLayout = GetWrappedHandle<VkPipelineLayout>(value->pipelineLayout);
    }
}

void UnwrapStructHandles(VkRenderPassAttachmentBeginInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pAttachments = UnwrapHandles<VkImageView>(value->pAttachments, value->attachmentCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkSemaphoreWaitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pSemaphores = UnwrapHandles<VkSemaphore>(value->pSemaphores, value->semaphoreCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkSemaphoreSignalInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->semaphore = GetWrappedHandle<VkSemaphore>(value->semaphore);
    }
}

void UnwrapStructHandles(VkBufferDeviceAddressInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->buffer = GetWrappedHandle<VkBuffer>(value->buffer);
    }
}

void UnwrapStructHandles(VkDeviceMemoryOpaqueCaptureAddressInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->memory = GetWrappedHandle<VkDeviceMemory>(value->memory);
    }
}

void UnwrapStructHandles(VkBufferMemoryBarrier2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->buffer = GetWrappedHandle<VkBuffer>(value->buffer);
    }
}

void UnwrapStructHandles(VkImageMemoryBarrier2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->image = GetWrappedHandle<VkImage>(value->image);
    }
}

void UnwrapStructHandles(VkDependencyInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pBufferMemoryBarriers = UnwrapStructArrayHandles(value->pBufferMemoryBarriers, value->bufferMemoryBarrierCount, unwrap_memory);

        value->pImageMemoryBarriers = UnwrapStructArrayHandles(value->pImageMemoryBarriers, value->imageMemoryBarrierCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkSemaphoreSubmitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->semaphore = GetWrappedHandle<VkSemaphore>(value->semaphore);
    }
}

void UnwrapStructHandles(VkCommandBufferSubmitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->commandBuffer = GetWrappedHandle<VkCommandBuffer>(value->commandBuffer);
    }
}

void UnwrapStructHandles(VkSubmitInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }

        value->pWaitSemaphoreInfos = UnwrapStructArrayHandles(value->pWaitSemaphoreInfos, value->waitSemaphoreInfoCount, unwrap_memory);

        value->pCommandBufferInfos = UnwrapStructArrayHandles(value->pCommandBufferInfos, value->commandBufferInfoCount, unwrap_memory);

        value->pSignalSemaphoreInfos = UnwrapStructArrayHandles(value->pSignalSemaphoreInfos, value->signalSemaphoreInfoCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkCopyBufferInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->srcBuffer = GetWrappedHandle<VkBuffer>(value->srcBuffer);

        value->dstBuffer = GetWrappedHandle<VkBuffer>(value->dstBuffer);
    }
}

void UnwrapStructHandles(VkCopyImageInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->srcImage = GetWrappedHandle<VkImage>(value->srcImage);

        value->dstImage = GetWrappedHandle<VkImage>(value->dstImage);
    }
}

void UnwrapStructHandles(VkCopyBufferToImageInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->srcBuffer = GetWrappedHandle<VkBuffer>(value->srcBuffer);

        value->dstImage = GetWrappedHandle<VkImage>(value->dstImage);
    }
}

void UnwrapStructHandles(VkCopyImageToBufferInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->srcImage = GetWrappedHandle<VkImage>(value->srcImage);

        value->dstBuffer = GetWrappedHandle<VkBuffer>(value->dstBuffer);
    }
}

void UnwrapStructHandles(VkBlitImageInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->srcImage = GetWrappedHandle<VkImage>(value->srcImage);

        value->dstImage = GetWrappedHandle<VkImage>(value->dstImage);
    }
}

void UnwrapStructHandles(VkResolveImageInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->srcImage = GetWrappedHandle<VkImage>(value->srcImage);

        value->dstImage = GetWrappedHandle<VkImage>(value->dstImage);
    }
}

void UnwrapStructHandles(VkRenderingAttachmentInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->imageView = GetWrappedHandle<VkImageView>(value->imageView);

        value->resolveImageView = GetWrappedHandle<VkImageView>(value->resolveImageView);
    }
}

void UnwrapStructHandles(VkRenderingInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }

        value->pColorAttachments = UnwrapStructArrayHandles(value->pColorAttachments, value->colorAttachmentCount, unwrap_memory);

        value->pDepthAttachment = UnwrapStructPtrHandles(value->pDepthAttachment, unwrap_memory);

        value->pStencilAttachment = UnwrapStructPtrHandles(value->pStencilAttachment, unwrap_memory);
    }
}

void UnwrapStructHandles(VkDeviceBufferMemoryRequirements* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pCreateInfo = UnwrapStructPtrHandles(value->pCreateInfo, unwrap_memory);
    }
}

void UnwrapStructHandles(VkDeviceImageMemoryRequirements* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pCreateInfo = UnwrapStructPtrHandles(value->pCreateInfo, unwrap_memory);
    }
}

void UnwrapStructHandles(VkSwapchainCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->surface = GetWrappedHandle<VkSurfaceKHR>(value->surface);

        value->oldSwapchain = GetWrappedHandle<VkSwapchainKHR>(value->oldSwapchain);
    }
}

void UnwrapStructHandles(VkPresentInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pWaitSemaphores = UnwrapHandles<VkSemaphore>(value->pWaitSemaphores, value->waitSemaphoreCount, unwrap_memory);

        value->pSwapchains = UnwrapHandles<VkSwapchainKHR>(value->pSwapchains, value->swapchainCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkImageSwapchainCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->swapchain = GetWrappedHandle<VkSwapchainKHR>(value->swapchain);
    }
}

void UnwrapStructHandles(VkBindImageMemorySwapchainInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->swapchain = GetWrappedHandle<VkSwapchainKHR>(value->swapchain);
    }
}

void UnwrapStructHandles(VkAcquireNextImageInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->swapchain = GetWrappedHandle<VkSwapchainKHR>(value->swapchain);

        value->semaphore = GetWrappedHandle<VkSemaphore>(value->semaphore);

        value->fence = GetWrappedHandle<VkFence>(value->fence);
    }
}

void UnwrapStructHandles(VkDisplayModePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->displayMode = GetWrappedHandle<VkDisplayModeKHR>(value->displayMode);
    }
}

void UnwrapStructHandles(VkDisplayPlanePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->currentDisplay = GetWrappedHandle<VkDisplayKHR>(value->currentDisplay);
    }
}

void UnwrapStructHandles(VkDisplayPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->display = GetWrappedHandle<VkDisplayKHR>(value->display);
    }
}

void UnwrapStructHandles(VkDisplaySurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->displayMode = GetWrappedHandle<VkDisplayModeKHR>(value->displayMode);
    }
}

void UnwrapStructHandles(VkRenderingFragmentShadingRateAttachmentInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->imageView = GetWrappedHandle<VkImageView>(value->imageView);
    }
}

void UnwrapStructHandles(VkRenderingFragmentDensityMapAttachmentInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->imageView = GetWrappedHandle<VkImageView>(value->imageView);
    }
}

void UnwrapStructHandles(VkMemoryGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->memory = GetWrappedHandle<VkDeviceMemory>(value->memory);
    }
}

void UnwrapStructHandles(VkMemoryGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->memory = GetWrappedHandle<VkDeviceMemory>(value->memory);
    }
}

void UnwrapStructHandles(VkWin32KeyedMutexAcquireReleaseInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pAcquireSyncs = UnwrapHandles<VkDeviceMemory>(value->pAcquireSyncs, value->acquireCount, unwrap_memory);

        value->pReleaseSyncs = UnwrapHandles<VkDeviceMemory>(value->pReleaseSyncs, value->releaseCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkImportSemaphoreWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->semaphore = GetWrappedHandle<VkSemaphore>(value->semaphore);
    }
}

void UnwrapStructHandles(VkSemaphoreGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->semaphore = GetWrappedHandle<VkSemaphore>(value->semaphore);
    }
}

void UnwrapStructHandles(VkImportSemaphoreFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->semaphore = GetWrappedHandle<VkSemaphore>(value->semaphore);
    }
}

void UnwrapStructHandles(VkSemaphoreGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->semaphore = GetWrappedHandle<VkSemaphore>(value->semaphore);
    }
}

void UnwrapStructHandles(VkImportFenceWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->fence = GetWrappedHandle<VkFence>(value->fence);
    }
}

void UnwrapStructHandles(VkFenceGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->fence = GetWrappedHandle<VkFence>(value->fence);
    }
}

void UnwrapStructHandles(VkImportFenceFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->fence = GetWrappedHandle<VkFence>(value->fence);
    }
}

void UnwrapStructHandles(VkFenceGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->fence = GetWrappedHandle<VkFence>(value->fence);
    }
}

void UnwrapStructHandles(VkPhysicalDeviceSurfaceInfo2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->surface = GetWrappedHandle<VkSurfaceKHR>(value->surface);
    }
}

void UnwrapStructHandles(VkDisplayProperties2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->displayProperties, unwrap_memory);
    }
}

void UnwrapStructHandles(VkDisplayPlaneProperties2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->displayPlaneProperties, unwrap_memory);
    }
}

void UnwrapStructHandles(VkDisplayModeProperties2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->displayModeProperties, unwrap_memory);
    }
}

void UnwrapStructHandles(VkDisplayPlaneInfo2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->mode = GetWrappedHandle<VkDisplayModeKHR>(value->mode);
    }
}

void UnwrapStructHandles(VkPipelineInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pipeline = GetWrappedHandle<VkPipeline>(value->pipeline);
    }
}

void UnwrapStructHandles(VkPipelineExecutableInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pipeline = GetWrappedHandle<VkPipeline>(value->pipeline);
    }
}

void UnwrapStructHandles(VkPipelineLibraryCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pLibraries = UnwrapHandles<VkPipeline>(value->pLibraries, value->libraryCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkDebugMarkerObjectNameInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->object = GetWrappedHandle(value->object, value->objectType);
    }
}

void UnwrapStructHandles(VkDebugMarkerObjectTagInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->object = GetWrappedHandle(value->object, value->objectType);
    }
}

void UnwrapStructHandles(VkDedicatedAllocationMemoryAllocateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->image = GetWrappedHandle<VkImage>(value->image);

        value->buffer = GetWrappedHandle<VkBuffer>(value->buffer);
    }
}

void UnwrapStructHandles(VkImageViewHandleInfoNVX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->imageView = GetWrappedHandle<VkImageView>(value->imageView);

        value->sampler = GetWrappedHandle<VkSampler>(value->sampler);
    }
}

void UnwrapStructHandles(VkWin32KeyedMutexAcquireReleaseInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pAcquireSyncs = UnwrapHandles<VkDeviceMemory>(value->pAcquireSyncs, value->acquireCount, unwrap_memory);

        value->pReleaseSyncs = UnwrapHandles<VkDeviceMemory>(value->pReleaseSyncs, value->releaseCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkConditionalRenderingBeginInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->buffer = GetWrappedHandle<VkBuffer>(value->buffer);
    }
}

void UnwrapStructHandles(VkDebugUtilsObjectNameInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->objectHandle = GetWrappedHandle(value->objectHandle, value->objectType);
    }
}

void UnwrapStructHandles(VkDebugUtilsObjectTagInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->objectHandle = GetWrappedHandle(value->objectHandle, value->objectType);
    }
}

void UnwrapStructHandles(VkMemoryGetAndroidHardwareBufferInfoANDROID* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->memory = GetWrappedHandle<VkDeviceMemory>(value->memory);
    }
}

void UnwrapStructHandles(VkShaderModuleValidationCacheCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->validationCache = GetWrappedHandle<VkValidationCacheEXT>(value->validationCache);
    }
}

void UnwrapStructHandles(VkRayTracingPipelineCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pStages = UnwrapStructArrayHandles(value->pStages, value->stageCount, unwrap_memory);

        value->layout = GetWrappedHandle<VkPipelineLayout>(value->layout);

        value->basePipelineHandle = GetWrappedHandle<VkPipeline>(value->basePipelineHandle);
    }
}

void UnwrapStructHandles(VkGeometryTrianglesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->vertexData = GetWrappedHandle<VkBuffer>(value->vertexData);

        value->indexData = GetWrappedHandle<VkBuffer>(value->indexData);

        value->transformData = GetWrappedHandle<VkBuffer>(value->transformData);
    }
}

void UnwrapStructHandles(VkGeometryAABBNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->aabbData = GetWrappedHandle<VkBuffer>(value->aabbData);
    }
}

void UnwrapStructHandles(VkGeometryDataNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->triangles, unwrap_memory);

        UnwrapStructHandles(&value->aabbs, unwrap_memory);
    }
}

void UnwrapStructHandles(VkGeometryNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->geometry, unwrap_memory);
    }
}

void UnwrapStructHandles(VkAccelerationStructureInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pGeometries = UnwrapStructArrayHandles(value->pGeometries, value->geometryCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkAccelerationStructureCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->info, unwrap_memory);
    }
}

void UnwrapStructHandles(VkBindAccelerationStructureMemoryInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->accelerationStructure = GetWrappedHandle<VkAccelerationStructureNV>(value->accelerationStructure);

        value->memory = GetWrappedHandle<VkDeviceMemory>(value->memory);
    }
}

void UnwrapStructHandles(VkWriteDescriptorSetAccelerationStructureNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pAccelerationStructures = UnwrapHandles<VkAccelerationStructureNV>(value->pAccelerationStructures, value->accelerationStructureCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkAccelerationStructureMemoryRequirementsInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->accelerationStructure = GetWrappedHandle<VkAccelerationStructureNV>(value->accelerationStructure);
    }
}

void UnwrapStructHandles(VkGraphicsShaderGroupCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pStages = UnwrapStructArrayHandles(value->pStages, value->stageCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkGraphicsPipelineShaderGroupsCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pGroups = UnwrapStructArrayHandles(value->pGroups, value->groupCount, unwrap_memory);

        value->pPipelines = UnwrapHandles<VkPipeline>(value->pPipelines, value->pipelineCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkIndirectCommandsStreamNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->buffer = GetWrappedHandle<VkBuffer>(value->buffer);
    }
}

void UnwrapStructHandles(VkIndirectCommandsLayoutTokenNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pushconstantPipelineLayout = GetWrappedHandle<VkPipelineLayout>(value->pushconstantPipelineLayout);
    }
}

void UnwrapStructHandles(VkIndirectCommandsLayoutCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pTokens = UnwrapStructArrayHandles(value->pTokens, value->tokenCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkGeneratedCommandsInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pipeline = GetWrappedHandle<VkPipeline>(value->pipeline);

        value->indirectCommandsLayout = GetWrappedHandle<VkIndirectCommandsLayoutNV>(value->indirectCommandsLayout);

        value->pStreams = UnwrapStructArrayHandles(value->pStreams, value->streamCount, unwrap_memory);

        value->preprocessBuffer = GetWrappedHandle<VkBuffer>(value->preprocessBuffer);

        value->sequencesCountBuffer = GetWrappedHandle<VkBuffer>(value->sequencesCountBuffer);

        value->sequencesIndexBuffer = GetWrappedHandle<VkBuffer>(value->sequencesIndexBuffer);
    }
}

void UnwrapStructHandles(VkGeneratedCommandsMemoryRequirementsInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pipeline = GetWrappedHandle<VkPipeline>(value->pipeline);

        value->indirectCommandsLayout = GetWrappedHandle<VkIndirectCommandsLayoutNV>(value->indirectCommandsLayout);
    }
}

void UnwrapStructHandles(VkMemoryGetZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->memory = GetWrappedHandle<VkDeviceMemory>(value->memory);
    }
}

void UnwrapStructHandles(VkImportSemaphoreZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->semaphore = GetWrappedHandle<VkSemaphore>(value->semaphore);
    }
}

void UnwrapStructHandles(VkSemaphoreGetZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->semaphore = GetWrappedHandle<VkSemaphore>(value->semaphore);
    }
}

void UnwrapStructHandles(VkMemoryGetRemoteAddressInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->memory = GetWrappedHandle<VkDeviceMemory>(value->memory);
    }
}

void UnwrapStructHandles(VkDescriptorSetBindingReferenceVALVE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->descriptorSetLayout = GetWrappedHandle<VkDescriptorSetLayout>(value->descriptorSetLayout);
    }
}

void UnwrapStructHandles(VkAccelerationStructureBuildGeometryInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->srcAccelerationStructure = GetWrappedHandle<VkAccelerationStructureKHR>(value->srcAccelerationStructure);

        value->dstAccelerationStructure = GetWrappedHandle<VkAccelerationStructureKHR>(value->dstAccelerationStructure);
    }
}

void UnwrapStructHandles(VkAccelerationStructureCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->buffer = GetWrappedHandle<VkBuffer>(value->buffer);
    }
}

void UnwrapStructHandles(VkWriteDescriptorSetAccelerationStructureKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pAccelerationStructures = UnwrapHandles<VkAccelerationStructureKHR>(value->pAccelerationStructures, value->accelerationStructureCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkAccelerationStructureDeviceAddressInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->accelerationStructure = GetWrappedHandle<VkAccelerationStructureKHR>(value->accelerationStructure);
    }
}

void UnwrapStructHandles(VkCopyAccelerationStructureToMemoryInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->src = GetWrappedHandle<VkAccelerationStructureKHR>(value->src);
    }
}

void UnwrapStructHandles(VkCopyMemoryToAccelerationStructureInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->dst = GetWrappedHandle<VkAccelerationStructureKHR>(value->dst);
    }
}

void UnwrapStructHandles(VkCopyAccelerationStructureInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->src = GetWrappedHandle<VkAccelerationStructureKHR>(value->src);

        value->dst = GetWrappedHandle<VkAccelerationStructureKHR>(value->dst);
    }
}

void UnwrapStructHandles(VkRayTracingPipelineCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pStages = UnwrapStructArrayHandles(value->pStages, value->stageCount, unwrap_memory);

        value->pLibraryInfo = UnwrapStructPtrHandles(value->pLibraryInfo, unwrap_memory);

        value->layout = GetWrappedHandle<VkPipelineLayout>(value->layout);

        value->basePipelineHandle = GetWrappedHandle<VkPipeline>(value->basePipelineHandle);
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
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkLayerInstanceCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkLayerDeviceCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkShaderModuleCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSubgroupProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevice16BitStorageFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryDedicatedRequirements*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryDedicatedAllocateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryAllocateFlagsInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceGroupRenderPassBeginInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceGroupCommandBufferBeginInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceGroupSubmitInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceGroupBindSparseInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBindBufferMemoryDeviceGroupInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBindImageMemoryDeviceGroupInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFeatures2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePointClippingProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassInputAttachmentAspectCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageViewUsageCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineTessellationDomainOriginStateCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassMultiviewCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMultiviewFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMultiviewProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVariablePointersFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceProtectedMemoryFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceProtectedMemoryProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkProtectedSubmitInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSamplerYcbcrConversionInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBindImagePlaneMemoryInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImagePlaneMemoryRequirementsInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSamplerYcbcrConversionImageFormatProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceExternalImageFormatInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExternalImageFormatProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceIDProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExternalMemoryImageCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExternalMemoryBufferCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExportMemoryAllocateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExportFenceCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExportSemaphoreCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance3Properties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderDrawParametersFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVulkan11Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVulkan11Properties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVulkan12Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVulkan12Properties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageFormatListCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevice8BitStorageFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDriverProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderAtomicInt64Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderFloat16Int8Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFloatControlsProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDescriptorSetLayoutBindingFlagsCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDescriptorSetVariableDescriptorCountAllocateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDescriptorSetVariableDescriptorCountLayoutSupport*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSubpassDescriptionDepthStencilResolve*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDepthStencilResolveProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceScalarBlockLayoutFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageStencilUsageCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSamplerReductionModeCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSamplerFilterMinmaxProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVulkanMemoryModelFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImagelessFramebufferFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkFramebufferAttachmentsCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassAttachmentBeginInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAttachmentReferenceStencilLayout*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAttachmentDescriptionStencilLayout*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceHostQueryResetFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSemaphoreTypeCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkTimelineSemaphoreSubmitInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBufferOpaqueCaptureAddressCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryOpaqueCaptureAddressAllocateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVulkan13Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVulkan13Properties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineCreationFeedbackCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderTerminateInvocationFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePrivateDataFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDevicePrivateDataCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePipelineCreationCacheControlFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryBarrier2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSynchronization2Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImageRobustnessFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineShaderStageRequiredSubgroupSizeCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkWriteDescriptorSetInlineUniformBlock*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDescriptorPoolInlineUniformBlockCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineRenderingCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDynamicRenderingFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCommandBufferInheritanceRenderingInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkFormatProperties3*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance4Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance4Properties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceGroupPresentInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceGroupSwapchainCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDisplayPresentInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderingFragmentDensityMapAttachmentInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAttachmentSampleCountInfoAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMultiviewPerViewAttributesInfoNVX*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImportMemoryWin32HandleInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExportMemoryWin32HandleInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImportMemoryFdInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExportSemaphoreWin32HandleInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkD3D12FenceSubmitInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePushDescriptorPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPresentRegionsKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSharedPresentSurfaceCapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExportFenceWin32HandleInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePerformanceQueryFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePerformanceQueryPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkQueryPoolPerformanceCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPerformanceQuerySubmitInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePortabilitySubsetPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderClockFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceQueueGlobalPriorityCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkQueueFamilyGlobalPriorityPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkFragmentShadingRateAttachmentInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineFragmentShadingRateStateCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShadingRatePropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSurfaceProtectedCapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePresentWaitFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineLibraryCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PRESENT_ID_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPresentIdKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePresentIdFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkQueueFamilyCheckpointProperties2NV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDebugReportCallbackCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineRasterizationStateRasterizationOrderAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDedicatedAllocationImageCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDedicatedAllocationBufferCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTransformFeedbackPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineRasterizationStateStreamCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkTextureLODGatherFormatPropertiesAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCornerSampledImageFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExternalMemoryImageCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExportMemoryAllocateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImportMemoryWin32HandleInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExportMemoryWin32HandleInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkValidationFlagsEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageViewASTCDecodeModeEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceASTCDecodeFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineViewportWScalingStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSwapchainCounterCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPresentTimesInfoGOOGLE*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineViewportSwizzleStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineDiscardRectangleStateCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineRasterizationConservativeStateCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineRasterizationDepthClipStateCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDebugUtilsObjectNameInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDebugUtilsMessengerCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAndroidHardwareBufferUsageANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAndroidHardwareBufferFormatPropertiesANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImportAndroidHardwareBufferInfoANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExternalFormatANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAndroidHardwareBufferFormatProperties2ANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSampleLocationsInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassSampleLocationsBeginInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineSampleLocationsStateCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSampleLocationsPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineCoverageToColorStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineCoverageModulationStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDrmFormatModifierPropertiesListEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageDrmFormatModifierListCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageDrmFormatModifierExplicitCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDrmFormatModifierPropertiesList2EXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineViewportShadingRateImageStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShadingRateImageFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShadingRateImagePropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImageViewImageFormatInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkFilterCubicImageViewImageFormatPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImportMemoryHostPointerInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineCompilerControlCreateInfoAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceMemoryOverallocationCreateInfoAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineVertexInputDivisorStateCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPresentFrameTokenGGP*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceExclusiveScissorFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkQueueFamilyCheckpointPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkQueryPoolPerformanceQueryCreateInfoINTEL*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePCIBusInfoPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSwapchainDisplayNativeHdrCreateInfoAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassFragmentDensityMapCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderCoreProperties2AMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryPriorityAllocateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBufferDeviceAddressCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkValidationFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineCoverageReductionStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceProvokingVertexFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceProvokingVertexPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSurfaceFullScreenExclusiveInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSurfaceCapabilitiesFullScreenExclusiveEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSurfaceFullScreenExclusiveWin32InfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceLineRasterizationFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceLineRasterizationPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineRasterizationLineStateCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceIndexTypeUint8FeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkGraphicsPipelineShaderGroupsCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCommandBufferInheritanceViewportScissorInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassTransformBeginInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCommandBufferInheritanceRenderPassTransformInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceDeviceMemoryReportCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRobustness2FeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRobustness2PropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSamplerCustomBorderColorCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCustomBorderColorPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceDiagnosticsConfigCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkGraphicsPipelineLibraryCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineFragmentShadingRateEnumStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAccelerationStructureGeometryMotionTrianglesDataNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAccelerationStructureMotionInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCopyCommandTransformInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageCompressionControlEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageCompressionPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevice4444FormatsFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_VALVE:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMutableDescriptorTypeFeaturesVALVE*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_VALVE:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMutableDescriptorTypeCreateInfoVALVE*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDrmPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDepthClipControlFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineViewportDepthClipControlCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImportMemoryZirconHandleInfoFUCHSIA*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineColorWriteCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageViewMinLodCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMultiDrawFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMultiDrawPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSamplerBorderColorComponentMappingCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSubpassFragmentDensityMapOffsetEndInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassCreationControlEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassCreationFeedbackCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassSubpassFeedbackCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceAccelerationStructurePropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingPipelinePropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRayQueryFeaturesKHR*>(base), 1, unwrap_memory));
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
            return UnwrapStructPtrHandles(reinterpret_cast<const VkShaderModuleCreateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkMemoryDedicatedAllocateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkSamplerYcbcrConversionInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkRenderPassAttachmentBeginInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkRenderingFragmentDensityMapAttachmentInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkPipelineLibraryCreateInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkGraphicsPipelineShaderGroupsCreateInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureKHR*>(base), unwrap_memory);
        }
    }

    return nullptr;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
