/*
** Copyright (c) 2018-2019 Valve Corporation
** Copyright (c) 2018-2019 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#include "generated/generated_vulkan_struct_handle_wrappers.h"

#include "vulkan/vk_layer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

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

void UnwrapStructHandles(VkMappedMemoryRange* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->memory = GetWrappedHandle<VkDeviceMemory>(value->memory);
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

void UnwrapStructHandles(VkGraphicsPipelineCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pStages = UnwrapStructArrayHandles(value->pStages, value->stageCount, unwrap_memory);

        value->layout = GetWrappedHandle<VkPipelineLayout>(value->layout);

        value->renderPass = GetWrappedHandle<VkRenderPass>(value->renderPass);

        value->basePipelineHandle = GetWrappedHandle<VkPipeline>(value->basePipelineHandle);
    }
}

void UnwrapStructHandles(VkComputePipelineCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->stage, unwrap_memory);

        value->layout = GetWrappedHandle<VkPipelineLayout>(value->layout);

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

void UnwrapStructHandles(VkDescriptorSetAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->descriptorPool = GetWrappedHandle<VkDescriptorPool>(value->descriptorPool);

        value->pSetLayouts = UnwrapHandles<VkDescriptorSetLayout>(value->pSetLayouts, value->descriptorSetCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkDescriptorBufferInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->buffer = GetWrappedHandle<VkBuffer>(value->buffer);
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

void UnwrapStructHandles(VkDisplayPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->display = GetWrappedHandle<VkDisplayKHR>(value->display);
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

void UnwrapStructHandles(VkDisplaySurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->displayMode = GetWrappedHandle<VkDisplayModeKHR>(value->displayMode);
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

void UnwrapStructHandles(VkRenderPassAttachmentBeginInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pAttachments = UnwrapHandles<VkImageView>(value->pAttachments, value->attachmentCount, unwrap_memory);
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

void UnwrapStructHandles(VkIndirectCommandsTokenNVX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->buffer = GetWrappedHandle<VkBuffer>(value->buffer);
    }
}

void UnwrapStructHandles(VkCmdProcessCommandsInfoNVX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->objectTable = GetWrappedHandle<VkObjectTableNVX>(value->objectTable);

        value->indirectCommandsLayout = GetWrappedHandle<VkIndirectCommandsLayoutNVX>(value->indirectCommandsLayout);

        value->pIndirectCommandsTokens = UnwrapStructArrayHandles(value->pIndirectCommandsTokens, value->indirectCommandsTokenCount, unwrap_memory);

        value->targetCommandBuffer = GetWrappedHandle<VkCommandBuffer>(value->targetCommandBuffer);

        value->sequencesCountBuffer = GetWrappedHandle<VkBuffer>(value->sequencesCountBuffer);

        value->sequencesIndexBuffer = GetWrappedHandle<VkBuffer>(value->sequencesIndexBuffer);
    }
}

void UnwrapStructHandles(VkCmdReserveSpaceForCommandsInfoNVX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->objectTable = GetWrappedHandle<VkObjectTableNVX>(value->objectTable);

        value->indirectCommandsLayout = GetWrappedHandle<VkIndirectCommandsLayoutNVX>(value->indirectCommandsLayout);
    }
}

void UnwrapStructHandles(VkObjectTablePipelineEntryNVX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pipeline = GetWrappedHandle<VkPipeline>(value->pipeline);
    }
}

void UnwrapStructHandles(VkObjectTableDescriptorSetEntryNVX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pipelineLayout = GetWrappedHandle<VkPipelineLayout>(value->pipelineLayout);

        value->descriptorSet = GetWrappedHandle<VkDescriptorSet>(value->descriptorSet);
    }
}

void UnwrapStructHandles(VkObjectTableVertexBufferEntryNVX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->buffer = GetWrappedHandle<VkBuffer>(value->buffer);
    }
}

void UnwrapStructHandles(VkObjectTableIndexBufferEntryNVX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->buffer = GetWrappedHandle<VkBuffer>(value->buffer);
    }
}

void UnwrapStructHandles(VkObjectTablePushConstantEntryNVX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pipelineLayout = GetWrappedHandle<VkPipelineLayout>(value->pipelineLayout);
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

void UnwrapStructHandles(VkBufferDeviceAddressInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->buffer = GetWrappedHandle<VkBuffer>(value->buffer);
    }
}

static VkBaseInStructure* CopyPNextStruct(const VkBaseInStructure* base, HandleUnwrapMemory* unwrap_memory)
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
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSubgroupProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevice16BitStorageFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryDedicatedRequirements*>(base), 1, unwrap_memory));
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
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceGroupPresentInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceGroupSwapchainCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDisplayPresentInfoKHR*>(base), 1, unwrap_memory));
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
    case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExportSemaphoreWin32HandleInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkD3D12FenceSubmitInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePushDescriptorPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderFloat16Int8FeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPresentRegionsKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImagelessFramebufferFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkFramebufferAttachmentsCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSharedPresentSurfaceCapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExportFenceWin32HandleInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageFormatListCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevice8BitStorageFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderAtomicInt64FeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDriverPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFloatControlsPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSubpassDescriptionDepthStencilResolveKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDepthStencilResolvePropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVulkanMemoryModelFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSurfaceProtectedCapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceUniformBufferStandardLayoutFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(base), 1, unwrap_memory));
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
    case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkValidationFlagsEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT*>(base), 1, unwrap_memory));
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
    case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSamplerReductionModeCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkWriteDescriptorSetInlineUniformBlockEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDescriptorPoolInlineUniformBlockCreateInfoEXT*>(base), 1, unwrap_memory));
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
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDescriptorSetLayoutBindingFlagsCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDescriptorSetVariableDescriptorCountAllocateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDescriptorSetVariableDescriptorCountLayoutSupportEXT*>(base), 1, unwrap_memory));
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
    case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceQueueGlobalPriorityCreateInfoEXT*>(base), 1, unwrap_memory));
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
    case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineCreationFeedbackCreateInfoEXT*>(base), 1, unwrap_memory));
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
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV*>(base), 1, unwrap_memory));
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
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceScalarBlockLayoutFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderCoreProperties2AMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(base), 1, unwrap_memory));
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
    case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageStencilUsageCreateInfoEXT*>(base), 1, unwrap_memory));
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
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceHostQueryResetFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceIndexTypeUint8FeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT*>(base), 1, unwrap_memory));
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
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkMemoryDedicatedAllocateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkSamplerYcbcrConversionInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkRenderPassAttachmentBeginInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureNV*>(base), unwrap_memory);
        }
    }

    return nullptr;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
