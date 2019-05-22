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

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void UnwrapStructHandles(const VkDeviceCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            UnwrapPNextStructHandles(value->pNext, handle_store, handle_array_store, handle_unwrap_memory);
        }
    }
}

void RewrapStructHandles(const VkDeviceCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            RewrapPNextStructHandles(value->pNext, handle_store_iter, handle_array_store_iter);
        }
    }
}

void UnwrapStructHandles(const VkSubmitInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            UnwrapPNextStructHandles(value->pNext, handle_store, handle_array_store, handle_unwrap_memory);
        }

        UnwrapHandles<SemaphoreWrapper>(&value->pWaitSemaphores, value->waitSemaphoreCount, handle_array_store, handle_unwrap_memory);


        UnwrapHandles<SemaphoreWrapper>(&value->pSignalSemaphores, value->signalSemaphoreCount, handle_array_store, handle_unwrap_memory);
    }
}

void RewrapStructHandles(const VkSubmitInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            RewrapPNextStructHandles(value->pNext, handle_store_iter, handle_array_store_iter);
        }

        RewrapHandles<SemaphoreWrapper>(&value->pWaitSemaphores, value->waitSemaphoreCount, handle_array_store_iter);


        RewrapHandles<SemaphoreWrapper>(&value->pSignalSemaphores, value->signalSemaphoreCount, handle_array_store_iter);
    }
}

void UnwrapStructHandles(const VkMemoryAllocateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            UnwrapPNextStructHandles(value->pNext, handle_store, handle_array_store, handle_unwrap_memory);
        }
    }
}

void RewrapStructHandles(const VkMemoryAllocateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            RewrapPNextStructHandles(value->pNext, handle_store_iter, handle_array_store_iter);
        }
    }
}

void UnwrapStructHandles(const VkMappedMemoryRange* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<DeviceMemoryWrapper>(&value->memory, handle_store);
    }
}

void RewrapStructHandles(const VkMappedMemoryRange* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<DeviceMemoryWrapper>(&value->memory, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkSparseMemoryBind* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<DeviceMemoryWrapper>(&value->memory, handle_store);
    }
}

void RewrapStructHandles(const VkSparseMemoryBind* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<DeviceMemoryWrapper>(&value->memory, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkSparseBufferMemoryBindInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<BufferWrapper>(&value->buffer, handle_store);

        UnwrapStructArrayHandles(value->pBinds, value->bindCount, handle_store, handle_array_store, handle_unwrap_memory);
    }
}

void RewrapStructHandles(const VkSparseBufferMemoryBindInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<BufferWrapper>(&value->buffer, handle_store_iter);

        RewrapStructArrayHandles(value->pBinds, value->bindCount, handle_store_iter, handle_array_store_iter);
    }
}

void UnwrapStructHandles(const VkSparseImageOpaqueMemoryBindInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<ImageWrapper>(&value->image, handle_store);

        UnwrapStructArrayHandles(value->pBinds, value->bindCount, handle_store, handle_array_store, handle_unwrap_memory);
    }
}

void RewrapStructHandles(const VkSparseImageOpaqueMemoryBindInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<ImageWrapper>(&value->image, handle_store_iter);

        RewrapStructArrayHandles(value->pBinds, value->bindCount, handle_store_iter, handle_array_store_iter);
    }
}

void UnwrapStructHandles(const VkSparseImageMemoryBind* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<DeviceMemoryWrapper>(&value->memory, handle_store);
    }
}

void RewrapStructHandles(const VkSparseImageMemoryBind* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<DeviceMemoryWrapper>(&value->memory, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkSparseImageMemoryBindInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<ImageWrapper>(&value->image, handle_store);

        UnwrapStructArrayHandles(value->pBinds, value->bindCount, handle_store, handle_array_store, handle_unwrap_memory);
    }
}

void RewrapStructHandles(const VkSparseImageMemoryBindInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<ImageWrapper>(&value->image, handle_store_iter);

        RewrapStructArrayHandles(value->pBinds, value->bindCount, handle_store_iter, handle_array_store_iter);
    }
}

void UnwrapStructHandles(const VkBindSparseInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandles<SemaphoreWrapper>(&value->pWaitSemaphores, value->waitSemaphoreCount, handle_array_store, handle_unwrap_memory);

        UnwrapStructArrayHandles(value->pBufferBinds, value->bufferBindCount, handle_store, handle_array_store, handle_unwrap_memory);

        UnwrapStructArrayHandles(value->pImageOpaqueBinds, value->imageOpaqueBindCount, handle_store, handle_array_store, handle_unwrap_memory);

        UnwrapStructArrayHandles(value->pImageBinds, value->imageBindCount, handle_store, handle_array_store, handle_unwrap_memory);

        UnwrapHandles<SemaphoreWrapper>(&value->pSignalSemaphores, value->signalSemaphoreCount, handle_array_store, handle_unwrap_memory);
    }
}

void RewrapStructHandles(const VkBindSparseInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandles<SemaphoreWrapper>(&value->pWaitSemaphores, value->waitSemaphoreCount, handle_array_store_iter);

        RewrapStructArrayHandles(value->pBufferBinds, value->bufferBindCount, handle_store_iter, handle_array_store_iter);

        RewrapStructArrayHandles(value->pImageOpaqueBinds, value->imageOpaqueBindCount, handle_store_iter, handle_array_store_iter);

        RewrapStructArrayHandles(value->pImageBinds, value->imageBindCount, handle_store_iter, handle_array_store_iter);

        RewrapHandles<SemaphoreWrapper>(&value->pSignalSemaphores, value->signalSemaphoreCount, handle_array_store_iter);
    }
}

void UnwrapStructHandles(const VkBufferViewCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<BufferWrapper>(&value->buffer, handle_store);
    }
}

void RewrapStructHandles(const VkBufferViewCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<BufferWrapper>(&value->buffer, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkImageCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            UnwrapPNextStructHandles(value->pNext, handle_store, handle_array_store, handle_unwrap_memory);
        }
    }
}

void RewrapStructHandles(const VkImageCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            RewrapPNextStructHandles(value->pNext, handle_store_iter, handle_array_store_iter);
        }
    }
}

void UnwrapStructHandles(const VkImageViewCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            UnwrapPNextStructHandles(value->pNext, handle_store, handle_array_store, handle_unwrap_memory);
        }

        UnwrapHandle<ImageWrapper>(&value->image, handle_store);
    }
}

void RewrapStructHandles(const VkImageViewCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            RewrapPNextStructHandles(value->pNext, handle_store_iter, handle_array_store_iter);
        }

        RewrapHandle<ImageWrapper>(&value->image, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkShaderModuleCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            UnwrapPNextStructHandles(value->pNext, handle_store, handle_array_store, handle_unwrap_memory);
        }
    }
}

void RewrapStructHandles(const VkShaderModuleCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            RewrapPNextStructHandles(value->pNext, handle_store_iter, handle_array_store_iter);
        }
    }
}

void UnwrapStructHandles(const VkPipelineShaderStageCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<ShaderModuleWrapper>(&value->module, handle_store);
    }
}

void RewrapStructHandles(const VkPipelineShaderStageCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<ShaderModuleWrapper>(&value->module, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkGraphicsPipelineCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructArrayHandles(value->pStages, value->stageCount, handle_store, handle_array_store, handle_unwrap_memory);

        UnwrapHandle<PipelineLayoutWrapper>(&value->layout, handle_store);

        UnwrapHandle<RenderPassWrapper>(&value->renderPass, handle_store);

        UnwrapHandle<PipelineWrapper>(&value->basePipelineHandle, handle_store);
    }
}

void RewrapStructHandles(const VkGraphicsPipelineCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapStructArrayHandles(value->pStages, value->stageCount, handle_store_iter, handle_array_store_iter);

        RewrapHandle<PipelineLayoutWrapper>(&value->layout, handle_store_iter);

        RewrapHandle<RenderPassWrapper>(&value->renderPass, handle_store_iter);

        RewrapHandle<PipelineWrapper>(&value->basePipelineHandle, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkComputePipelineCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->stage, handle_store, handle_array_store, handle_unwrap_memory);

        UnwrapHandle<PipelineLayoutWrapper>(&value->layout, handle_store);

        UnwrapHandle<PipelineWrapper>(&value->basePipelineHandle, handle_store);
    }
}

void RewrapStructHandles(const VkComputePipelineCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapStructHandles(&value->stage, handle_store_iter, handle_array_store_iter);

        RewrapHandle<PipelineLayoutWrapper>(&value->layout, handle_store_iter);

        RewrapHandle<PipelineWrapper>(&value->basePipelineHandle, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkPipelineLayoutCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandles<DescriptorSetLayoutWrapper>(&value->pSetLayouts, value->setLayoutCount, handle_array_store, handle_unwrap_memory);
    }
}

void RewrapStructHandles(const VkPipelineLayoutCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandles<DescriptorSetLayoutWrapper>(&value->pSetLayouts, value->setLayoutCount, handle_array_store_iter);
    }
}

void UnwrapStructHandles(const VkSamplerCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            UnwrapPNextStructHandles(value->pNext, handle_store, handle_array_store, handle_unwrap_memory);
        }
    }
}

void RewrapStructHandles(const VkSamplerCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            RewrapPNextStructHandles(value->pNext, handle_store_iter, handle_array_store_iter);
        }
    }
}

void UnwrapStructHandles(const VkDescriptorSetLayoutBinding* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandles<SamplerWrapper>(&value->pImmutableSamplers, value->descriptorCount, handle_array_store, handle_unwrap_memory);
    }
}

void RewrapStructHandles(const VkDescriptorSetLayoutBinding* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandles<SamplerWrapper>(&value->pImmutableSamplers, value->descriptorCount, handle_array_store_iter);
    }
}

void UnwrapStructHandles(const VkDescriptorSetLayoutCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructArrayHandles(value->pBindings, value->bindingCount, handle_store, handle_array_store, handle_unwrap_memory);
    }
}

void RewrapStructHandles(const VkDescriptorSetLayoutCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapStructArrayHandles(value->pBindings, value->bindingCount, handle_store_iter, handle_array_store_iter);
    }
}

void UnwrapStructHandles(const VkDescriptorSetAllocateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<DescriptorPoolWrapper>(&value->descriptorPool, handle_store);

        UnwrapHandles<DescriptorSetLayoutWrapper>(&value->pSetLayouts, value->descriptorSetCount, handle_array_store, handle_unwrap_memory);
    }
}

void RewrapStructHandles(const VkDescriptorSetAllocateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<DescriptorPoolWrapper>(&value->descriptorPool, handle_store_iter);

        RewrapHandles<DescriptorSetLayoutWrapper>(&value->pSetLayouts, value->descriptorSetCount, handle_array_store_iter);
    }
}

void UnwrapStructHandles(const VkDescriptorBufferInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<BufferWrapper>(&value->buffer, handle_store);
    }
}

void RewrapStructHandles(const VkDescriptorBufferInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<BufferWrapper>(&value->buffer, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkCopyDescriptorSet* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<DescriptorSetWrapper>(&value->srcSet, handle_store);

        UnwrapHandle<DescriptorSetWrapper>(&value->dstSet, handle_store);
    }
}

void RewrapStructHandles(const VkCopyDescriptorSet* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<DescriptorSetWrapper>(&value->srcSet, handle_store_iter);

        RewrapHandle<DescriptorSetWrapper>(&value->dstSet, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkFramebufferCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<RenderPassWrapper>(&value->renderPass, handle_store);

        UnwrapHandles<ImageViewWrapper>(&value->pAttachments, value->attachmentCount, handle_array_store, handle_unwrap_memory);
    }
}

void RewrapStructHandles(const VkFramebufferCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<RenderPassWrapper>(&value->renderPass, handle_store_iter);

        RewrapHandles<ImageViewWrapper>(&value->pAttachments, value->attachmentCount, handle_array_store_iter);
    }
}

void UnwrapStructHandles(const VkCommandBufferAllocateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<CommandPoolWrapper>(&value->commandPool, handle_store);
    }
}

void RewrapStructHandles(const VkCommandBufferAllocateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<CommandPoolWrapper>(&value->commandPool, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkCommandBufferInheritanceInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<RenderPassWrapper>(&value->renderPass, handle_store);

        UnwrapHandle<FramebufferWrapper>(&value->framebuffer, handle_store);
    }
}

void RewrapStructHandles(const VkCommandBufferInheritanceInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<RenderPassWrapper>(&value->renderPass, handle_store_iter);

        RewrapHandle<FramebufferWrapper>(&value->framebuffer, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkCommandBufferBeginInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(value->pInheritanceInfo, handle_store, handle_array_store, handle_unwrap_memory);
    }
}

void RewrapStructHandles(const VkCommandBufferBeginInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapStructHandles(value->pInheritanceInfo, handle_store_iter, handle_array_store_iter);
    }
}

void UnwrapStructHandles(const VkBufferMemoryBarrier* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<BufferWrapper>(&value->buffer, handle_store);
    }
}

void RewrapStructHandles(const VkBufferMemoryBarrier* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<BufferWrapper>(&value->buffer, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkImageMemoryBarrier* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<ImageWrapper>(&value->image, handle_store);
    }
}

void RewrapStructHandles(const VkImageMemoryBarrier* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<ImageWrapper>(&value->image, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkRenderPassBeginInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<RenderPassWrapper>(&value->renderPass, handle_store);

        UnwrapHandle<FramebufferWrapper>(&value->framebuffer, handle_store);
    }
}

void RewrapStructHandles(const VkRenderPassBeginInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<RenderPassWrapper>(&value->renderPass, handle_store_iter);

        RewrapHandle<FramebufferWrapper>(&value->framebuffer, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkBindBufferMemoryInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<BufferWrapper>(&value->buffer, handle_store);

        UnwrapHandle<DeviceMemoryWrapper>(&value->memory, handle_store);
    }
}

void RewrapStructHandles(const VkBindBufferMemoryInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<BufferWrapper>(&value->buffer, handle_store_iter);

        RewrapHandle<DeviceMemoryWrapper>(&value->memory, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkBindImageMemoryInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            UnwrapPNextStructHandles(value->pNext, handle_store, handle_array_store, handle_unwrap_memory);
        }

        UnwrapHandle<ImageWrapper>(&value->image, handle_store);

        UnwrapHandle<DeviceMemoryWrapper>(&value->memory, handle_store);
    }
}

void RewrapStructHandles(const VkBindImageMemoryInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            RewrapPNextStructHandles(value->pNext, handle_store_iter, handle_array_store_iter);
        }

        RewrapHandle<ImageWrapper>(&value->image, handle_store_iter);

        RewrapHandle<DeviceMemoryWrapper>(&value->memory, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkMemoryDedicatedAllocateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<ImageWrapper>(&value->image, handle_store);

        UnwrapHandle<BufferWrapper>(&value->buffer, handle_store);
    }
}

void RewrapStructHandles(const VkMemoryDedicatedAllocateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<ImageWrapper>(&value->image, handle_store_iter);

        RewrapHandle<BufferWrapper>(&value->buffer, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkPhysicalDeviceGroupProperties* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void RewrapStructHandles(const VkPhysicalDeviceGroupProperties* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(const VkDeviceGroupDeviceCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void RewrapStructHandles(const VkDeviceGroupDeviceCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(const VkBufferMemoryRequirementsInfo2* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<BufferWrapper>(&value->buffer, handle_store);
    }
}

void RewrapStructHandles(const VkBufferMemoryRequirementsInfo2* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<BufferWrapper>(&value->buffer, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkImageMemoryRequirementsInfo2* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<ImageWrapper>(&value->image, handle_store);
    }
}

void RewrapStructHandles(const VkImageMemoryRequirementsInfo2* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<ImageWrapper>(&value->image, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkImageSparseMemoryRequirementsInfo2* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<ImageWrapper>(&value->image, handle_store);
    }
}

void RewrapStructHandles(const VkImageSparseMemoryRequirementsInfo2* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<ImageWrapper>(&value->image, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkSamplerYcbcrConversionInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<SamplerYcbcrConversionWrapper>(&value->conversion, handle_store);
    }
}

void RewrapStructHandles(const VkSamplerYcbcrConversionInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<SamplerYcbcrConversionWrapper>(&value->conversion, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkDescriptorUpdateTemplateCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<DescriptorSetLayoutWrapper>(&value->descriptorSetLayout, handle_store);

        UnwrapHandle<PipelineLayoutWrapper>(&value->pipelineLayout, handle_store);
    }
}

void RewrapStructHandles(const VkDescriptorUpdateTemplateCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<DescriptorSetLayoutWrapper>(&value->descriptorSetLayout, handle_store_iter);

        RewrapHandle<PipelineLayoutWrapper>(&value->pipelineLayout, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkSwapchainCreateInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<SurfaceKHRWrapper>(&value->surface, handle_store);

        UnwrapHandle<SwapchainKHRWrapper>(&value->oldSwapchain, handle_store);
    }
}

void RewrapStructHandles(const VkSwapchainCreateInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<SurfaceKHRWrapper>(&value->surface, handle_store_iter);

        RewrapHandle<SwapchainKHRWrapper>(&value->oldSwapchain, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkPresentInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandles<SemaphoreWrapper>(&value->pWaitSemaphores, value->waitSemaphoreCount, handle_array_store, handle_unwrap_memory);

        UnwrapHandles<SwapchainKHRWrapper>(&value->pSwapchains, value->swapchainCount, handle_array_store, handle_unwrap_memory);
    }
}

void RewrapStructHandles(const VkPresentInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandles<SemaphoreWrapper>(&value->pWaitSemaphores, value->waitSemaphoreCount, handle_array_store_iter);

        RewrapHandles<SwapchainKHRWrapper>(&value->pSwapchains, value->swapchainCount, handle_array_store_iter);
    }
}

void UnwrapStructHandles(const VkImageSwapchainCreateInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<SwapchainKHRWrapper>(&value->swapchain, handle_store);
    }
}

void RewrapStructHandles(const VkImageSwapchainCreateInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<SwapchainKHRWrapper>(&value->swapchain, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkBindImageMemorySwapchainInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<SwapchainKHRWrapper>(&value->swapchain, handle_store);
    }
}

void RewrapStructHandles(const VkBindImageMemorySwapchainInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<SwapchainKHRWrapper>(&value->swapchain, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkAcquireNextImageInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<SwapchainKHRWrapper>(&value->swapchain, handle_store);

        UnwrapHandle<SemaphoreWrapper>(&value->semaphore, handle_store);

        UnwrapHandle<FenceWrapper>(&value->fence, handle_store);
    }
}

void RewrapStructHandles(const VkAcquireNextImageInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<SwapchainKHRWrapper>(&value->swapchain, handle_store_iter);

        RewrapHandle<SemaphoreWrapper>(&value->semaphore, handle_store_iter);

        RewrapHandle<FenceWrapper>(&value->fence, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkDisplayPropertiesKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<DisplayKHRWrapper>(&value->display, handle_store);
    }
}

void RewrapStructHandles(const VkDisplayPropertiesKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<DisplayKHRWrapper>(&value->display, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkDisplayModePropertiesKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<DisplayModeKHRWrapper>(&value->displayMode, handle_store);
    }
}

void RewrapStructHandles(const VkDisplayModePropertiesKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<DisplayModeKHRWrapper>(&value->displayMode, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkDisplayPlanePropertiesKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<DisplayKHRWrapper>(&value->currentDisplay, handle_store);
    }
}

void RewrapStructHandles(const VkDisplayPlanePropertiesKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<DisplayKHRWrapper>(&value->currentDisplay, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkDisplaySurfaceCreateInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<DisplayModeKHRWrapper>(&value->displayMode, handle_store);
    }
}

void RewrapStructHandles(const VkDisplaySurfaceCreateInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<DisplayModeKHRWrapper>(&value->displayMode, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkMemoryGetWin32HandleInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<DeviceMemoryWrapper>(&value->memory, handle_store);
    }
}

void RewrapStructHandles(const VkMemoryGetWin32HandleInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<DeviceMemoryWrapper>(&value->memory, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkMemoryGetFdInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<DeviceMemoryWrapper>(&value->memory, handle_store);
    }
}

void RewrapStructHandles(const VkMemoryGetFdInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<DeviceMemoryWrapper>(&value->memory, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkWin32KeyedMutexAcquireReleaseInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandles<DeviceMemoryWrapper>(&value->pAcquireSyncs, value->acquireCount, handle_array_store, handle_unwrap_memory);

        UnwrapHandles<DeviceMemoryWrapper>(&value->pReleaseSyncs, value->releaseCount, handle_array_store, handle_unwrap_memory);
    }
}

void RewrapStructHandles(const VkWin32KeyedMutexAcquireReleaseInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandles<DeviceMemoryWrapper>(&value->pAcquireSyncs, value->acquireCount, handle_array_store_iter);

        RewrapHandles<DeviceMemoryWrapper>(&value->pReleaseSyncs, value->releaseCount, handle_array_store_iter);
    }
}

void UnwrapStructHandles(const VkImportSemaphoreWin32HandleInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<SemaphoreWrapper>(&value->semaphore, handle_store);
    }
}

void RewrapStructHandles(const VkImportSemaphoreWin32HandleInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<SemaphoreWrapper>(&value->semaphore, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkSemaphoreGetWin32HandleInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<SemaphoreWrapper>(&value->semaphore, handle_store);
    }
}

void RewrapStructHandles(const VkSemaphoreGetWin32HandleInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<SemaphoreWrapper>(&value->semaphore, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkImportSemaphoreFdInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<SemaphoreWrapper>(&value->semaphore, handle_store);
    }
}

void RewrapStructHandles(const VkImportSemaphoreFdInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<SemaphoreWrapper>(&value->semaphore, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkSemaphoreGetFdInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<SemaphoreWrapper>(&value->semaphore, handle_store);
    }
}

void RewrapStructHandles(const VkSemaphoreGetFdInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<SemaphoreWrapper>(&value->semaphore, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkImportFenceWin32HandleInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<FenceWrapper>(&value->fence, handle_store);
    }
}

void RewrapStructHandles(const VkImportFenceWin32HandleInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<FenceWrapper>(&value->fence, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkFenceGetWin32HandleInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<FenceWrapper>(&value->fence, handle_store);
    }
}

void RewrapStructHandles(const VkFenceGetWin32HandleInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<FenceWrapper>(&value->fence, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkImportFenceFdInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<FenceWrapper>(&value->fence, handle_store);
    }
}

void RewrapStructHandles(const VkImportFenceFdInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<FenceWrapper>(&value->fence, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkFenceGetFdInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<FenceWrapper>(&value->fence, handle_store);
    }
}

void RewrapStructHandles(const VkFenceGetFdInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<FenceWrapper>(&value->fence, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkPhysicalDeviceSurfaceInfo2KHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<SurfaceKHRWrapper>(&value->surface, handle_store);
    }
}

void RewrapStructHandles(const VkPhysicalDeviceSurfaceInfo2KHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<SurfaceKHRWrapper>(&value->surface, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkDisplayProperties2KHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->displayProperties, handle_store, handle_array_store, handle_unwrap_memory);
    }
}

void RewrapStructHandles(const VkDisplayProperties2KHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapStructHandles(&value->displayProperties, handle_store_iter, handle_array_store_iter);
    }
}

void UnwrapStructHandles(const VkDisplayPlaneProperties2KHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->displayPlaneProperties, handle_store, handle_array_store, handle_unwrap_memory);
    }
}

void RewrapStructHandles(const VkDisplayPlaneProperties2KHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapStructHandles(&value->displayPlaneProperties, handle_store_iter, handle_array_store_iter);
    }
}

void UnwrapStructHandles(const VkDisplayModeProperties2KHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->displayModeProperties, handle_store, handle_array_store, handle_unwrap_memory);
    }
}

void RewrapStructHandles(const VkDisplayModeProperties2KHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapStructHandles(&value->displayModeProperties, handle_store_iter, handle_array_store_iter);
    }
}

void UnwrapStructHandles(const VkDisplayPlaneInfo2KHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<DisplayModeKHRWrapper>(&value->mode, handle_store);
    }
}

void RewrapStructHandles(const VkDisplayPlaneInfo2KHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<DisplayModeKHRWrapper>(&value->mode, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkDedicatedAllocationMemoryAllocateInfoNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<ImageWrapper>(&value->image, handle_store);

        UnwrapHandle<BufferWrapper>(&value->buffer, handle_store);
    }
}

void RewrapStructHandles(const VkDedicatedAllocationMemoryAllocateInfoNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<ImageWrapper>(&value->image, handle_store_iter);

        RewrapHandle<BufferWrapper>(&value->buffer, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkImageViewHandleInfoNVX* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<ImageViewWrapper>(&value->imageView, handle_store);

        UnwrapHandle<SamplerWrapper>(&value->sampler, handle_store);
    }
}

void RewrapStructHandles(const VkImageViewHandleInfoNVX* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<ImageViewWrapper>(&value->imageView, handle_store_iter);

        RewrapHandle<SamplerWrapper>(&value->sampler, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkWin32KeyedMutexAcquireReleaseInfoNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandles<DeviceMemoryWrapper>(&value->pAcquireSyncs, value->acquireCount, handle_array_store, handle_unwrap_memory);

        UnwrapHandles<DeviceMemoryWrapper>(&value->pReleaseSyncs, value->releaseCount, handle_array_store, handle_unwrap_memory);
    }
}

void RewrapStructHandles(const VkWin32KeyedMutexAcquireReleaseInfoNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandles<DeviceMemoryWrapper>(&value->pAcquireSyncs, value->acquireCount, handle_array_store_iter);

        RewrapHandles<DeviceMemoryWrapper>(&value->pReleaseSyncs, value->releaseCount, handle_array_store_iter);
    }
}

void UnwrapStructHandles(const VkConditionalRenderingBeginInfoEXT* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<BufferWrapper>(&value->buffer, handle_store);
    }
}

void RewrapStructHandles(const VkConditionalRenderingBeginInfoEXT* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<BufferWrapper>(&value->buffer, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkIndirectCommandsTokenNVX* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<BufferWrapper>(&value->buffer, handle_store);
    }
}

void RewrapStructHandles(const VkIndirectCommandsTokenNVX* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<BufferWrapper>(&value->buffer, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkCmdProcessCommandsInfoNVX* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<ObjectTableNVXWrapper>(&value->objectTable, handle_store);

        UnwrapHandle<IndirectCommandsLayoutNVXWrapper>(&value->indirectCommandsLayout, handle_store);

        UnwrapStructArrayHandles(value->pIndirectCommandsTokens, value->indirectCommandsTokenCount, handle_store, handle_array_store, handle_unwrap_memory);


        UnwrapHandle<BufferWrapper>(&value->sequencesCountBuffer, handle_store);

        UnwrapHandle<BufferWrapper>(&value->sequencesIndexBuffer, handle_store);
    }
}

void RewrapStructHandles(const VkCmdProcessCommandsInfoNVX* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<ObjectTableNVXWrapper>(&value->objectTable, handle_store_iter);

        RewrapHandle<IndirectCommandsLayoutNVXWrapper>(&value->indirectCommandsLayout, handle_store_iter);

        RewrapStructArrayHandles(value->pIndirectCommandsTokens, value->indirectCommandsTokenCount, handle_store_iter, handle_array_store_iter);


        RewrapHandle<BufferWrapper>(&value->sequencesCountBuffer, handle_store_iter);

        RewrapHandle<BufferWrapper>(&value->sequencesIndexBuffer, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkCmdReserveSpaceForCommandsInfoNVX* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<ObjectTableNVXWrapper>(&value->objectTable, handle_store);

        UnwrapHandle<IndirectCommandsLayoutNVXWrapper>(&value->indirectCommandsLayout, handle_store);
    }
}

void RewrapStructHandles(const VkCmdReserveSpaceForCommandsInfoNVX* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<ObjectTableNVXWrapper>(&value->objectTable, handle_store_iter);

        RewrapHandle<IndirectCommandsLayoutNVXWrapper>(&value->indirectCommandsLayout, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkObjectTablePipelineEntryNVX* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<PipelineWrapper>(&value->pipeline, handle_store);
    }
}

void RewrapStructHandles(const VkObjectTablePipelineEntryNVX* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<PipelineWrapper>(&value->pipeline, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkObjectTableDescriptorSetEntryNVX* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<PipelineLayoutWrapper>(&value->pipelineLayout, handle_store);

        UnwrapHandle<DescriptorSetWrapper>(&value->descriptorSet, handle_store);
    }
}

void RewrapStructHandles(const VkObjectTableDescriptorSetEntryNVX* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<PipelineLayoutWrapper>(&value->pipelineLayout, handle_store_iter);

        RewrapHandle<DescriptorSetWrapper>(&value->descriptorSet, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkObjectTableVertexBufferEntryNVX* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<BufferWrapper>(&value->buffer, handle_store);
    }
}

void RewrapStructHandles(const VkObjectTableVertexBufferEntryNVX* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<BufferWrapper>(&value->buffer, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkObjectTableIndexBufferEntryNVX* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<BufferWrapper>(&value->buffer, handle_store);
    }
}

void RewrapStructHandles(const VkObjectTableIndexBufferEntryNVX* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<BufferWrapper>(&value->buffer, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkObjectTablePushConstantEntryNVX* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<PipelineLayoutWrapper>(&value->pipelineLayout, handle_store);
    }
}

void RewrapStructHandles(const VkObjectTablePushConstantEntryNVX* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<PipelineLayoutWrapper>(&value->pipelineLayout, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkMemoryGetAndroidHardwareBufferInfoANDROID* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<DeviceMemoryWrapper>(&value->memory, handle_store);
    }
}

void RewrapStructHandles(const VkMemoryGetAndroidHardwareBufferInfoANDROID* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<DeviceMemoryWrapper>(&value->memory, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkShaderModuleValidationCacheCreateInfoEXT* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<ValidationCacheEXTWrapper>(&value->validationCache, handle_store);
    }
}

void RewrapStructHandles(const VkShaderModuleValidationCacheCreateInfoEXT* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<ValidationCacheEXTWrapper>(&value->validationCache, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkRayTracingPipelineCreateInfoNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructArrayHandles(value->pStages, value->stageCount, handle_store, handle_array_store, handle_unwrap_memory);

        UnwrapHandle<PipelineLayoutWrapper>(&value->layout, handle_store);

        UnwrapHandle<PipelineWrapper>(&value->basePipelineHandle, handle_store);
    }
}

void RewrapStructHandles(const VkRayTracingPipelineCreateInfoNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapStructArrayHandles(value->pStages, value->stageCount, handle_store_iter, handle_array_store_iter);

        RewrapHandle<PipelineLayoutWrapper>(&value->layout, handle_store_iter);

        RewrapHandle<PipelineWrapper>(&value->basePipelineHandle, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkGeometryTrianglesNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<BufferWrapper>(&value->vertexData, handle_store);

        UnwrapHandle<BufferWrapper>(&value->indexData, handle_store);

        UnwrapHandle<BufferWrapper>(&value->transformData, handle_store);
    }
}

void RewrapStructHandles(const VkGeometryTrianglesNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<BufferWrapper>(&value->vertexData, handle_store_iter);

        RewrapHandle<BufferWrapper>(&value->indexData, handle_store_iter);

        RewrapHandle<BufferWrapper>(&value->transformData, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkGeometryAABBNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<BufferWrapper>(&value->aabbData, handle_store);
    }
}

void RewrapStructHandles(const VkGeometryAABBNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<BufferWrapper>(&value->aabbData, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkGeometryDataNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->triangles, handle_store, handle_array_store, handle_unwrap_memory);

        UnwrapStructHandles(&value->aabbs, handle_store, handle_array_store, handle_unwrap_memory);
    }
}

void RewrapStructHandles(const VkGeometryDataNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapStructHandles(&value->triangles, handle_store_iter, handle_array_store_iter);

        RewrapStructHandles(&value->aabbs, handle_store_iter, handle_array_store_iter);
    }
}

void UnwrapStructHandles(const VkGeometryNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->geometry, handle_store, handle_array_store, handle_unwrap_memory);
    }
}

void RewrapStructHandles(const VkGeometryNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapStructHandles(&value->geometry, handle_store_iter, handle_array_store_iter);
    }
}

void UnwrapStructHandles(const VkAccelerationStructureInfoNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructArrayHandles(value->pGeometries, value->geometryCount, handle_store, handle_array_store, handle_unwrap_memory);
    }
}

void RewrapStructHandles(const VkAccelerationStructureInfoNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapStructArrayHandles(value->pGeometries, value->geometryCount, handle_store_iter, handle_array_store_iter);
    }
}

void UnwrapStructHandles(const VkAccelerationStructureCreateInfoNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->info, handle_store, handle_array_store, handle_unwrap_memory);
    }
}

void RewrapStructHandles(const VkAccelerationStructureCreateInfoNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapStructHandles(&value->info, handle_store_iter, handle_array_store_iter);
    }
}

void UnwrapStructHandles(const VkBindAccelerationStructureMemoryInfoNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<AccelerationStructureNVWrapper>(&value->accelerationStructure, handle_store);

        UnwrapHandle<DeviceMemoryWrapper>(&value->memory, handle_store);
    }
}

void RewrapStructHandles(const VkBindAccelerationStructureMemoryInfoNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<AccelerationStructureNVWrapper>(&value->accelerationStructure, handle_store_iter);

        RewrapHandle<DeviceMemoryWrapper>(&value->memory, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkWriteDescriptorSetAccelerationStructureNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandles<AccelerationStructureNVWrapper>(&value->pAccelerationStructures, value->accelerationStructureCount, handle_array_store, handle_unwrap_memory);
    }
}

void RewrapStructHandles(const VkWriteDescriptorSetAccelerationStructureNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandles<AccelerationStructureNVWrapper>(&value->pAccelerationStructures, value->accelerationStructureCount, handle_array_store_iter);
    }
}

void UnwrapStructHandles(const VkAccelerationStructureMemoryRequirementsInfoNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<AccelerationStructureNVWrapper>(&value->accelerationStructure, handle_store);
    }
}

void RewrapStructHandles(const VkAccelerationStructureMemoryRequirementsInfoNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<AccelerationStructureNVWrapper>(&value->accelerationStructure, handle_store_iter);
    }
}

void UnwrapStructHandles(const VkBufferDeviceAddressInfoEXT* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapHandle<BufferWrapper>(&value->buffer, handle_store);
    }
}

void RewrapStructHandles(const VkBufferDeviceAddressInfoEXT* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        RewrapHandle<BufferWrapper>(&value->buffer, handle_store_iter);
    }
}

void UnwrapPNextStructHandles(const void* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    const VkBaseInStructure* base = reinterpret_cast<const VkBaseInStructure*>(value);

    // Ignore the structures added to the pnext chain by the loader.
    while ((base != nullptr) && ((base->sType == VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO) ||
                                 (base->sType == VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO)))
    {
        base = reinterpret_cast<const VkBaseInStructure*>(base->pNext);
    }

    if (base != nullptr)
    {
        switch (base->sType)
        {
        default:
            // This structure does not contain handles, but may point to a structure that does.
            UnwrapPNextStructHandles(base->pNext, handle_store, handle_array_store, handle_unwrap_memory);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            UnwrapStructHandles(reinterpret_cast<const VkMemoryDedicatedAllocateInfo*>(base), handle_store, handle_array_store, handle_unwrap_memory);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            UnwrapStructHandles(reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(base), handle_store, handle_array_store, handle_unwrap_memory);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            UnwrapStructHandles(reinterpret_cast<const VkSamplerYcbcrConversionInfo*>(base), handle_store, handle_array_store, handle_unwrap_memory);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            UnwrapStructHandles(reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(base), handle_store, handle_array_store, handle_unwrap_memory);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            UnwrapStructHandles(reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(base), handle_store, handle_array_store, handle_unwrap_memory);
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            UnwrapStructHandles(reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(base), handle_store, handle_array_store, handle_unwrap_memory);
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            UnwrapStructHandles(reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(base), handle_store, handle_array_store, handle_unwrap_memory);
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            UnwrapStructHandles(reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(base), handle_store, handle_array_store, handle_unwrap_memory);
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            UnwrapStructHandles(reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(base), handle_store, handle_array_store, handle_unwrap_memory);
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            UnwrapStructHandles(reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureNV*>(base), handle_store, handle_array_store, handle_unwrap_memory);
            break;
        }
    }
}

void RewrapPNextStructHandles(const void* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    const VkBaseInStructure* base = reinterpret_cast<const VkBaseInStructure*>(value);

    // Ignore the structures added to the pnext chain by the loader.
    while ((base != nullptr) && ((base->sType == VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO) ||
                                 (base->sType == VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO)))
    {
        base = reinterpret_cast<const VkBaseInStructure*>(base->pNext);
    }

    if (base != nullptr)
    {
        switch (base->sType)
        {
        default:
            // This structure does not contain handles, but may point to a structure that does.
            RewrapPNextStructHandles(base->pNext, handle_store_iter, handle_array_store_iter);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            RewrapStructHandles(reinterpret_cast<const VkMemoryDedicatedAllocateInfo*>(base), handle_store_iter, handle_array_store_iter);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            RewrapStructHandles(reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(base), handle_store_iter, handle_array_store_iter);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            RewrapStructHandles(reinterpret_cast<const VkSamplerYcbcrConversionInfo*>(base), handle_store_iter, handle_array_store_iter);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            RewrapStructHandles(reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(base), handle_store_iter, handle_array_store_iter);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            RewrapStructHandles(reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(base), handle_store_iter, handle_array_store_iter);
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            RewrapStructHandles(reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(base), handle_store_iter, handle_array_store_iter);
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            RewrapStructHandles(reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(base), handle_store_iter, handle_array_store_iter);
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            RewrapStructHandles(reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(base), handle_store_iter, handle_array_store_iter);
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            RewrapStructHandles(reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(base), handle_store_iter, handle_array_store_iter);
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            RewrapStructHandles(reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureNV*>(base), handle_store_iter, handle_array_store_iter);
            break;
        }
    }
}

void CreateWrappedStructHandles(VkPhysicalDeviceGroupProperties* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
    }
}

void CreateWrappedStructHandles(VkDisplayPropertiesKHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedHandle<DisplayKHRWrapper>(&value->display, get_id);
    }
}

void CreateWrappedStructHandles(VkDisplayPlanePropertiesKHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedHandle<DisplayKHRWrapper>(&value->currentDisplay, get_id);
    }
}

void CreateWrappedStructHandles(VkDisplayModePropertiesKHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedHandle<DisplayModeKHRWrapper>(&value->displayMode, get_id);
    }
}

void CreateWrappedStructHandles(VkDisplayProperties2KHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedStructHandles(&value->displayProperties, get_id);
    }
}

void CreateWrappedStructHandles(VkDisplayPlaneProperties2KHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedStructHandles(&value->displayPlaneProperties, get_id);
    }
}

void CreateWrappedStructHandles(VkDisplayModeProperties2KHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedStructHandles(&value->displayModeProperties, get_id);
    }
}


GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
