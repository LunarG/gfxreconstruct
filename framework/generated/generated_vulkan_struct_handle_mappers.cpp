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

#include "generated/generated_vulkan_struct_decoders.h"
#include "generated/generated_vulkan_struct_handle_mappers.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename T>
static void MapHandleArray(const format::HandleId*   ids,
                           T*                        handles,
                           size_t                    len,
                           const VulkanObjectMapper& object_mapper,
                           T (VulkanObjectMapper::*MapFunc)(format::HandleId) const)
{
    if ((ids != nullptr) && (handles != nullptr))
    {
        for (size_t i = 0; i < len; ++i)
        {
            handles[i] = (object_mapper.*MapFunc)(ids[i]);
        }
    }
}

void MapStructHandles(Decoded_VkApplicationInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkApplicationInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkInstanceCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkInstanceCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapStructArrayHandles<Decoded_VkApplicationInfo>(wrapper->pApplicationInfo.GetMetaStructPointer(), 1, object_mapper);
    }
}

void MapStructHandles(Decoded_VkDeviceQueueCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDeviceQueueCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDeviceCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapStructArrayHandles<Decoded_VkDeviceQueueCreateInfo>(wrapper->pQueueCreateInfos.GetMetaStructPointer(), wrapper->pQueueCreateInfos.GetLength(), object_mapper);
    }
}

void MapStructHandles(Decoded_VkSubmitInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSubmitInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapHandleArray<VkSemaphore>(wrapper->pWaitSemaphores.GetPointer(), wrapper->pWaitSemaphores.GetHandlePointer(), wrapper->pWaitSemaphores.GetLength(), object_mapper, &VulkanObjectMapper::MapVkSemaphore);

        MapHandleArray<VkCommandBuffer>(wrapper->pCommandBuffers.GetPointer(), wrapper->pCommandBuffers.GetHandlePointer(), wrapper->pCommandBuffers.GetLength(), object_mapper, &VulkanObjectMapper::MapVkCommandBuffer);

        MapHandleArray<VkSemaphore>(wrapper->pSignalSemaphores.GetPointer(), wrapper->pSignalSemaphores.GetHandlePointer(), wrapper->pSignalSemaphores.GetLength(), object_mapper, &VulkanObjectMapper::MapVkSemaphore);
    }
}

void MapStructHandles(Decoded_VkMemoryAllocateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkMemoryAllocateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkMappedMemoryRange* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkMappedMemoryRange* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->memory = object_mapper.MapVkDeviceMemory(wrapper->memory);
    }
}

void MapStructHandles(Decoded_VkSparseMemoryBind* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSparseMemoryBind* value = wrapper->value;

        value->memory = object_mapper.MapVkDeviceMemory(wrapper->memory);
    }
}

void MapStructHandles(Decoded_VkSparseBufferMemoryBindInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSparseBufferMemoryBindInfo* value = wrapper->value;

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);

        MapStructArrayHandles<Decoded_VkSparseMemoryBind>(wrapper->pBinds.GetMetaStructPointer(), wrapper->pBinds.GetLength(), object_mapper);
    }
}

void MapStructHandles(Decoded_VkSparseImageOpaqueMemoryBindInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSparseImageOpaqueMemoryBindInfo* value = wrapper->value;

        value->image = object_mapper.MapVkImage(wrapper->image);

        MapStructArrayHandles<Decoded_VkSparseMemoryBind>(wrapper->pBinds.GetMetaStructPointer(), wrapper->pBinds.GetLength(), object_mapper);
    }
}

void MapStructHandles(Decoded_VkSparseImageMemoryBind* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSparseImageMemoryBind* value = wrapper->value;

        value->memory = object_mapper.MapVkDeviceMemory(wrapper->memory);
    }
}

void MapStructHandles(Decoded_VkSparseImageMemoryBindInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSparseImageMemoryBindInfo* value = wrapper->value;

        value->image = object_mapper.MapVkImage(wrapper->image);

        MapStructArrayHandles<Decoded_VkSparseImageMemoryBind>(wrapper->pBinds.GetMetaStructPointer(), wrapper->pBinds.GetLength(), object_mapper);
    }
}

void MapStructHandles(Decoded_VkBindSparseInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBindSparseInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapHandleArray<VkSemaphore>(wrapper->pWaitSemaphores.GetPointer(), wrapper->pWaitSemaphores.GetHandlePointer(), wrapper->pWaitSemaphores.GetLength(), object_mapper, &VulkanObjectMapper::MapVkSemaphore);

        MapStructArrayHandles<Decoded_VkSparseBufferMemoryBindInfo>(wrapper->pBufferBinds.GetMetaStructPointer(), wrapper->pBufferBinds.GetLength(), object_mapper);

        MapStructArrayHandles<Decoded_VkSparseImageOpaqueMemoryBindInfo>(wrapper->pImageOpaqueBinds.GetMetaStructPointer(), wrapper->pImageOpaqueBinds.GetLength(), object_mapper);

        MapStructArrayHandles<Decoded_VkSparseImageMemoryBindInfo>(wrapper->pImageBinds.GetMetaStructPointer(), wrapper->pImageBinds.GetLength(), object_mapper);

        MapHandleArray<VkSemaphore>(wrapper->pSignalSemaphores.GetPointer(), wrapper->pSignalSemaphores.GetHandlePointer(), wrapper->pSignalSemaphores.GetLength(), object_mapper, &VulkanObjectMapper::MapVkSemaphore);
    }
}

void MapStructHandles(Decoded_VkFenceCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkFenceCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkSemaphoreCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSemaphoreCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkEventCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkEventCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkQueryPoolCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkQueryPoolCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkBufferCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBufferCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkBufferViewCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBufferViewCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);
    }
}

void MapStructHandles(Decoded_VkImageCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImageCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkImageViewCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImageViewCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->image = object_mapper.MapVkImage(wrapper->image);
    }
}

void MapStructHandles(Decoded_VkShaderModuleCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkShaderModuleCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineCacheCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineCacheCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineShaderStageCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineShaderStageCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->module = object_mapper.MapVkShaderModule(wrapper->module);
    }
}

void MapStructHandles(Decoded_VkPipelineVertexInputStateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineVertexInputStateCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineInputAssemblyStateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineInputAssemblyStateCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineTessellationStateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineTessellationStateCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineViewportStateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineViewportStateCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineRasterizationStateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineRasterizationStateCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineMultisampleStateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineMultisampleStateCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineDepthStencilStateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineDepthStencilStateCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineColorBlendStateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineColorBlendStateCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineDynamicStateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineDynamicStateCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkGraphicsPipelineCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkGraphicsPipelineCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapStructArrayHandles<Decoded_VkPipelineShaderStageCreateInfo>(wrapper->pStages.GetMetaStructPointer(), wrapper->pStages.GetLength(), object_mapper);

        MapStructArrayHandles<Decoded_VkPipelineVertexInputStateCreateInfo>(wrapper->pVertexInputState.GetMetaStructPointer(), 1, object_mapper);

        MapStructArrayHandles<Decoded_VkPipelineInputAssemblyStateCreateInfo>(wrapper->pInputAssemblyState.GetMetaStructPointer(), 1, object_mapper);

        MapStructArrayHandles<Decoded_VkPipelineTessellationStateCreateInfo>(wrapper->pTessellationState.GetMetaStructPointer(), 1, object_mapper);

        MapStructArrayHandles<Decoded_VkPipelineViewportStateCreateInfo>(wrapper->pViewportState.GetMetaStructPointer(), 1, object_mapper);

        MapStructArrayHandles<Decoded_VkPipelineRasterizationStateCreateInfo>(wrapper->pRasterizationState.GetMetaStructPointer(), 1, object_mapper);

        MapStructArrayHandles<Decoded_VkPipelineMultisampleStateCreateInfo>(wrapper->pMultisampleState.GetMetaStructPointer(), 1, object_mapper);

        MapStructArrayHandles<Decoded_VkPipelineDepthStencilStateCreateInfo>(wrapper->pDepthStencilState.GetMetaStructPointer(), 1, object_mapper);

        MapStructArrayHandles<Decoded_VkPipelineColorBlendStateCreateInfo>(wrapper->pColorBlendState.GetMetaStructPointer(), 1, object_mapper);

        MapStructArrayHandles<Decoded_VkPipelineDynamicStateCreateInfo>(wrapper->pDynamicState.GetMetaStructPointer(), 1, object_mapper);

        value->layout = object_mapper.MapVkPipelineLayout(wrapper->layout);

        value->renderPass = object_mapper.MapVkRenderPass(wrapper->renderPass);

        value->basePipelineHandle = object_mapper.MapVkPipeline(wrapper->basePipelineHandle);
    }
}

void MapStructHandles(Decoded_VkComputePipelineCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkComputePipelineCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapStructHandles(&wrapper->stage, object_mapper);

        value->layout = object_mapper.MapVkPipelineLayout(wrapper->layout);

        value->basePipelineHandle = object_mapper.MapVkPipeline(wrapper->basePipelineHandle);
    }
}

void MapStructHandles(Decoded_VkPipelineLayoutCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineLayoutCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapHandleArray<VkDescriptorSetLayout>(wrapper->pSetLayouts.GetPointer(), wrapper->pSetLayouts.GetHandlePointer(), wrapper->pSetLayouts.GetLength(), object_mapper, &VulkanObjectMapper::MapVkDescriptorSetLayout);
    }
}

void MapStructHandles(Decoded_VkSamplerCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSamplerCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorSetLayoutBinding* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDescriptorSetLayoutBinding* value = wrapper->value;

        MapHandleArray<VkSampler>(wrapper->pImmutableSamplers.GetPointer(), wrapper->pImmutableSamplers.GetHandlePointer(), wrapper->pImmutableSamplers.GetLength(), object_mapper, &VulkanObjectMapper::MapVkSampler);
    }
}

void MapStructHandles(Decoded_VkDescriptorSetLayoutCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDescriptorSetLayoutCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapStructArrayHandles<Decoded_VkDescriptorSetLayoutBinding>(wrapper->pBindings.GetMetaStructPointer(), wrapper->pBindings.GetLength(), object_mapper);
    }
}

void MapStructHandles(Decoded_VkDescriptorPoolCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDescriptorPoolCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorSetAllocateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDescriptorSetAllocateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->descriptorPool = object_mapper.MapVkDescriptorPool(wrapper->descriptorPool);

        MapHandleArray<VkDescriptorSetLayout>(wrapper->pSetLayouts.GetPointer(), wrapper->pSetLayouts.GetHandlePointer(), wrapper->pSetLayouts.GetLength(), object_mapper, &VulkanObjectMapper::MapVkDescriptorSetLayout);
    }
}

void MapStructHandles(Decoded_VkDescriptorImageInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDescriptorImageInfo* value = wrapper->value;

        value->sampler = object_mapper.MapVkSampler(wrapper->sampler);

        value->imageView = object_mapper.MapVkImageView(wrapper->imageView);
    }
}

void MapStructHandles(Decoded_VkDescriptorBufferInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDescriptorBufferInfo* value = wrapper->value;

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);
    }
}

void MapStructHandles(Decoded_VkWriteDescriptorSet* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkWriteDescriptorSet* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->dstSet = object_mapper.MapVkDescriptorSet(wrapper->dstSet);

        MapStructArrayHandles<Decoded_VkDescriptorImageInfo>(wrapper->pImageInfo.GetMetaStructPointer(), wrapper->pImageInfo.GetLength(), object_mapper);

        MapStructArrayHandles<Decoded_VkDescriptorBufferInfo>(wrapper->pBufferInfo.GetMetaStructPointer(), wrapper->pBufferInfo.GetLength(), object_mapper);

        MapHandleArray<VkBufferView>(wrapper->pTexelBufferView.GetPointer(), wrapper->pTexelBufferView.GetHandlePointer(), wrapper->pTexelBufferView.GetLength(), object_mapper, &VulkanObjectMapper::MapVkBufferView);
    }
}

void MapStructHandles(Decoded_VkCopyDescriptorSet* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkCopyDescriptorSet* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->srcSet = object_mapper.MapVkDescriptorSet(wrapper->srcSet);

        value->dstSet = object_mapper.MapVkDescriptorSet(wrapper->dstSet);
    }
}

void MapStructHandles(Decoded_VkFramebufferCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkFramebufferCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->renderPass = object_mapper.MapVkRenderPass(wrapper->renderPass);

        MapHandleArray<VkImageView>(wrapper->pAttachments.GetPointer(), wrapper->pAttachments.GetHandlePointer(), wrapper->pAttachments.GetLength(), object_mapper, &VulkanObjectMapper::MapVkImageView);
    }
}

void MapStructHandles(Decoded_VkRenderPassCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkRenderPassCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkCommandPoolCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkCommandPoolCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkCommandBufferAllocateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkCommandBufferAllocateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->commandPool = object_mapper.MapVkCommandPool(wrapper->commandPool);
    }
}

void MapStructHandles(Decoded_VkCommandBufferInheritanceInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkCommandBufferInheritanceInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->renderPass = object_mapper.MapVkRenderPass(wrapper->renderPass);

        value->framebuffer = object_mapper.MapVkFramebuffer(wrapper->framebuffer);
    }
}

void MapStructHandles(Decoded_VkCommandBufferBeginInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkCommandBufferBeginInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapStructArrayHandles<Decoded_VkCommandBufferInheritanceInfo>(wrapper->pInheritanceInfo.GetMetaStructPointer(), 1, object_mapper);
    }
}

void MapStructHandles(Decoded_VkMemoryBarrier* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkMemoryBarrier* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkBufferMemoryBarrier* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBufferMemoryBarrier* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);
    }
}

void MapStructHandles(Decoded_VkImageMemoryBarrier* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImageMemoryBarrier* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->image = object_mapper.MapVkImage(wrapper->image);
    }
}

void MapStructHandles(Decoded_VkRenderPassBeginInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkRenderPassBeginInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->renderPass = object_mapper.MapVkRenderPass(wrapper->renderPass);

        value->framebuffer = object_mapper.MapVkFramebuffer(wrapper->framebuffer);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSubgroupProperties* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceSubgroupProperties* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkBindBufferMemoryInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBindBufferMemoryInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);

        value->memory = object_mapper.MapVkDeviceMemory(wrapper->memory);
    }
}

void MapStructHandles(Decoded_VkBindImageMemoryInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBindImageMemoryInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->image = object_mapper.MapVkImage(wrapper->image);

        value->memory = object_mapper.MapVkDeviceMemory(wrapper->memory);
    }
}

void MapStructHandles(Decoded_VkPhysicalDevice16BitStorageFeatures* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDevice16BitStorageFeatures* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryDedicatedRequirements* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkMemoryDedicatedRequirements* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryDedicatedAllocateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkMemoryDedicatedAllocateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->image = object_mapper.MapVkImage(wrapper->image);

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);
    }
}

void MapStructHandles(Decoded_VkMemoryAllocateFlagsInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkMemoryAllocateFlagsInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceGroupRenderPassBeginInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDeviceGroupRenderPassBeginInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceGroupCommandBufferBeginInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDeviceGroupCommandBufferBeginInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceGroupSubmitInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDeviceGroupSubmitInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceGroupBindSparseInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDeviceGroupBindSparseInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkBindBufferMemoryDeviceGroupInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBindBufferMemoryDeviceGroupInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkBindImageMemoryDeviceGroupInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBindImageMemoryDeviceGroupInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceGroupProperties* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceGroupProperties* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapHandleArray<VkPhysicalDevice>(wrapper->physicalDevices.GetPointer(), wrapper->physicalDevices.GetHandlePointer(), wrapper->physicalDevices.GetLength(), object_mapper, &VulkanObjectMapper::MapVkPhysicalDevice);
    }
}

void MapStructHandles(Decoded_VkDeviceGroupDeviceCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDeviceGroupDeviceCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapHandleArray<VkPhysicalDevice>(wrapper->pPhysicalDevices.GetPointer(), wrapper->pPhysicalDevices.GetHandlePointer(), wrapper->pPhysicalDevices.GetLength(), object_mapper, &VulkanObjectMapper::MapVkPhysicalDevice);
    }
}

void MapStructHandles(Decoded_VkBufferMemoryRequirementsInfo2* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBufferMemoryRequirementsInfo2* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);
    }
}

void MapStructHandles(Decoded_VkImageMemoryRequirementsInfo2* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImageMemoryRequirementsInfo2* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->image = object_mapper.MapVkImage(wrapper->image);
    }
}

void MapStructHandles(Decoded_VkImageSparseMemoryRequirementsInfo2* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImageSparseMemoryRequirementsInfo2* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->image = object_mapper.MapVkImage(wrapper->image);
    }
}

void MapStructHandles(Decoded_VkMemoryRequirements2* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkMemoryRequirements2* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkSparseImageMemoryRequirements2* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSparseImageMemoryRequirements2* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFeatures2* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceFeatures2* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceProperties2* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceProperties2* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkFormatProperties2* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkFormatProperties2* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkImageFormatProperties2* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImageFormatProperties2* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageFormatInfo2* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceImageFormatInfo2* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkQueueFamilyProperties2* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkQueueFamilyProperties2* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMemoryProperties2* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceMemoryProperties2* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkSparseImageFormatProperties2* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSparseImageFormatProperties2* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSparseImageFormatInfo2* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceSparseImageFormatInfo2* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePointClippingProperties* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDevicePointClippingProperties* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassInputAttachmentAspectCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkRenderPassInputAttachmentAspectCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkImageViewUsageCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImageViewUsageCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineTessellationDomainOriginStateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineTessellationDomainOriginStateCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassMultiviewCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkRenderPassMultiviewCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMultiviewFeatures* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceMultiviewFeatures* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMultiviewProperties* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceMultiviewProperties* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVariablePointerFeatures* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceVariablePointerFeatures* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceProtectedMemoryFeatures* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceProtectedMemoryFeatures* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceProtectedMemoryProperties* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceProtectedMemoryProperties* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceQueueInfo2* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDeviceQueueInfo2* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkProtectedSubmitInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkProtectedSubmitInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkSamplerYcbcrConversionCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSamplerYcbcrConversionCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkSamplerYcbcrConversionInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSamplerYcbcrConversionInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->conversion = object_mapper.MapVkSamplerYcbcrConversion(wrapper->conversion);
    }
}

void MapStructHandles(Decoded_VkBindImagePlaneMemoryInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBindImagePlaneMemoryInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkImagePlaneMemoryRequirementsInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImagePlaneMemoryRequirementsInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceSamplerYcbcrConversionFeatures* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkSamplerYcbcrConversionImageFormatProperties* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSamplerYcbcrConversionImageFormatProperties* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorUpdateTemplateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDescriptorUpdateTemplateCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->descriptorSetLayout = object_mapper.MapVkDescriptorSetLayout(wrapper->descriptorSetLayout);

        value->pipelineLayout = object_mapper.MapVkPipelineLayout(wrapper->pipelineLayout);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExternalImageFormatInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceExternalImageFormatInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkExternalImageFormatProperties* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkExternalImageFormatProperties* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExternalBufferInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceExternalBufferInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkExternalBufferProperties* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkExternalBufferProperties* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceIDProperties* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceIDProperties* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkExternalMemoryImageCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkExternalMemoryImageCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkExternalMemoryBufferCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkExternalMemoryBufferCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkExportMemoryAllocateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkExportMemoryAllocateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExternalFenceInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceExternalFenceInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkExternalFenceProperties* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkExternalFenceProperties* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkExportFenceCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkExportFenceCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkExportSemaphoreCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkExportSemaphoreCreateInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExternalSemaphoreInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceExternalSemaphoreInfo* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkExternalSemaphoreProperties* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkExternalSemaphoreProperties* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance3Properties* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceMaintenance3Properties* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorSetLayoutSupport* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDescriptorSetLayoutSupport* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderDrawParameterFeatures* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceShaderDrawParameterFeatures* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkSwapchainCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSwapchainCreateInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->surface = object_mapper.MapVkSurfaceKHR(wrapper->surface);

        value->oldSwapchain = object_mapper.MapVkSwapchainKHR(wrapper->oldSwapchain);
    }
}

void MapStructHandles(Decoded_VkPresentInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPresentInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapHandleArray<VkSemaphore>(wrapper->pWaitSemaphores.GetPointer(), wrapper->pWaitSemaphores.GetHandlePointer(), wrapper->pWaitSemaphores.GetLength(), object_mapper, &VulkanObjectMapper::MapVkSemaphore);

        MapHandleArray<VkSwapchainKHR>(wrapper->pSwapchains.GetPointer(), wrapper->pSwapchains.GetHandlePointer(), wrapper->pSwapchains.GetLength(), object_mapper, &VulkanObjectMapper::MapVkSwapchainKHR);
    }
}

void MapStructHandles(Decoded_VkImageSwapchainCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImageSwapchainCreateInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->swapchain = object_mapper.MapVkSwapchainKHR(wrapper->swapchain);
    }
}

void MapStructHandles(Decoded_VkBindImageMemorySwapchainInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBindImageMemorySwapchainInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->swapchain = object_mapper.MapVkSwapchainKHR(wrapper->swapchain);
    }
}

void MapStructHandles(Decoded_VkAcquireNextImageInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkAcquireNextImageInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->swapchain = object_mapper.MapVkSwapchainKHR(wrapper->swapchain);

        value->semaphore = object_mapper.MapVkSemaphore(wrapper->semaphore);

        value->fence = object_mapper.MapVkFence(wrapper->fence);
    }
}

void MapStructHandles(Decoded_VkDeviceGroupPresentCapabilitiesKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDeviceGroupPresentCapabilitiesKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceGroupPresentInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDeviceGroupPresentInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceGroupSwapchainCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDeviceGroupSwapchainCreateInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDisplayPropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDisplayPropertiesKHR* value = wrapper->value;

        value->display = object_mapper.MapVkDisplayKHR(wrapper->display);
    }
}

void MapStructHandles(Decoded_VkDisplayModePropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDisplayModePropertiesKHR* value = wrapper->value;

        value->displayMode = object_mapper.MapVkDisplayModeKHR(wrapper->displayMode);
    }
}

void MapStructHandles(Decoded_VkDisplayModeCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDisplayModeCreateInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDisplayPlanePropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDisplayPlanePropertiesKHR* value = wrapper->value;

        value->currentDisplay = object_mapper.MapVkDisplayKHR(wrapper->currentDisplay);
    }
}

void MapStructHandles(Decoded_VkDisplaySurfaceCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDisplaySurfaceCreateInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->displayMode = object_mapper.MapVkDisplayModeKHR(wrapper->displayMode);
    }
}

void MapStructHandles(Decoded_VkDisplayPresentInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDisplayPresentInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkXlibSurfaceCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkXlibSurfaceCreateInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkXcbSurfaceCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkXcbSurfaceCreateInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkWaylandSurfaceCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkWaylandSurfaceCreateInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkAndroidSurfaceCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkAndroidSurfaceCreateInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkWin32SurfaceCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkWin32SurfaceCreateInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkImportMemoryWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImportMemoryWin32HandleInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkExportMemoryWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkExportMemoryWin32HandleInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryWin32HandlePropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkMemoryWin32HandlePropertiesKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryGetWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkMemoryGetWin32HandleInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->memory = object_mapper.MapVkDeviceMemory(wrapper->memory);
    }
}

void MapStructHandles(Decoded_VkImportMemoryFdInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImportMemoryFdInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryFdPropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkMemoryFdPropertiesKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryGetFdInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkMemoryGetFdInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->memory = object_mapper.MapVkDeviceMemory(wrapper->memory);
    }
}

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkWin32KeyedMutexAcquireReleaseInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapHandleArray<VkDeviceMemory>(wrapper->pAcquireSyncs.GetPointer(), wrapper->pAcquireSyncs.GetHandlePointer(), wrapper->pAcquireSyncs.GetLength(), object_mapper, &VulkanObjectMapper::MapVkDeviceMemory);

        MapHandleArray<VkDeviceMemory>(wrapper->pReleaseSyncs.GetPointer(), wrapper->pReleaseSyncs.GetHandlePointer(), wrapper->pReleaseSyncs.GetLength(), object_mapper, &VulkanObjectMapper::MapVkDeviceMemory);
    }
}

void MapStructHandles(Decoded_VkImportSemaphoreWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImportSemaphoreWin32HandleInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->semaphore = object_mapper.MapVkSemaphore(wrapper->semaphore);
    }
}

void MapStructHandles(Decoded_VkExportSemaphoreWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkExportSemaphoreWin32HandleInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkD3D12FenceSubmitInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkD3D12FenceSubmitInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkSemaphoreGetWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSemaphoreGetWin32HandleInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->semaphore = object_mapper.MapVkSemaphore(wrapper->semaphore);
    }
}

void MapStructHandles(Decoded_VkImportSemaphoreFdInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImportSemaphoreFdInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->semaphore = object_mapper.MapVkSemaphore(wrapper->semaphore);
    }
}

void MapStructHandles(Decoded_VkSemaphoreGetFdInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSemaphoreGetFdInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->semaphore = object_mapper.MapVkSemaphore(wrapper->semaphore);
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePushDescriptorPropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDevicePushDescriptorPropertiesKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFloat16Int8FeaturesKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceFloat16Int8FeaturesKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPresentRegionsKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPresentRegionsKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkAttachmentDescription2KHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkAttachmentDescription2KHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkAttachmentReference2KHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkAttachmentReference2KHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkSubpassDescription2KHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSubpassDescription2KHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapStructArrayHandles<Decoded_VkAttachmentReference2KHR>(wrapper->pInputAttachments.GetMetaStructPointer(), wrapper->pInputAttachments.GetLength(), object_mapper);

        MapStructArrayHandles<Decoded_VkAttachmentReference2KHR>(wrapper->pColorAttachments.GetMetaStructPointer(), wrapper->pColorAttachments.GetLength(), object_mapper);

        MapStructArrayHandles<Decoded_VkAttachmentReference2KHR>(wrapper->pResolveAttachments.GetMetaStructPointer(), wrapper->pResolveAttachments.GetLength(), object_mapper);

        MapStructArrayHandles<Decoded_VkAttachmentReference2KHR>(wrapper->pDepthStencilAttachment.GetMetaStructPointer(), 1, object_mapper);
    }
}

void MapStructHandles(Decoded_VkSubpassDependency2KHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSubpassDependency2KHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassCreateInfo2KHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkRenderPassCreateInfo2KHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapStructArrayHandles<Decoded_VkAttachmentDescription2KHR>(wrapper->pAttachments.GetMetaStructPointer(), wrapper->pAttachments.GetLength(), object_mapper);

        MapStructArrayHandles<Decoded_VkSubpassDescription2KHR>(wrapper->pSubpasses.GetMetaStructPointer(), wrapper->pSubpasses.GetLength(), object_mapper);

        MapStructArrayHandles<Decoded_VkSubpassDependency2KHR>(wrapper->pDependencies.GetMetaStructPointer(), wrapper->pDependencies.GetLength(), object_mapper);
    }
}

void MapStructHandles(Decoded_VkSubpassBeginInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSubpassBeginInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkSubpassEndInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSubpassEndInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkSharedPresentSurfaceCapabilitiesKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSharedPresentSurfaceCapabilitiesKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkImportFenceWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImportFenceWin32HandleInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->fence = object_mapper.MapVkFence(wrapper->fence);
    }
}

void MapStructHandles(Decoded_VkExportFenceWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkExportFenceWin32HandleInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkFenceGetWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkFenceGetWin32HandleInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->fence = object_mapper.MapVkFence(wrapper->fence);
    }
}

void MapStructHandles(Decoded_VkImportFenceFdInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImportFenceFdInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->fence = object_mapper.MapVkFence(wrapper->fence);
    }
}

void MapStructHandles(Decoded_VkFenceGetFdInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkFenceGetFdInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->fence = object_mapper.MapVkFence(wrapper->fence);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSurfaceInfo2KHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceSurfaceInfo2KHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->surface = object_mapper.MapVkSurfaceKHR(wrapper->surface);
    }
}

void MapStructHandles(Decoded_VkSurfaceCapabilities2KHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSurfaceCapabilities2KHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkSurfaceFormat2KHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSurfaceFormat2KHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDisplayProperties2KHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDisplayProperties2KHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapStructHandles(&wrapper->displayProperties, object_mapper);
    }
}

void MapStructHandles(Decoded_VkDisplayPlaneProperties2KHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDisplayPlaneProperties2KHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapStructHandles(&wrapper->displayPlaneProperties, object_mapper);
    }
}

void MapStructHandles(Decoded_VkDisplayModeProperties2KHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDisplayModeProperties2KHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapStructHandles(&wrapper->displayModeProperties, object_mapper);
    }
}

void MapStructHandles(Decoded_VkDisplayPlaneInfo2KHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDisplayPlaneInfo2KHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->mode = object_mapper.MapVkDisplayModeKHR(wrapper->mode);
    }
}

void MapStructHandles(Decoded_VkDisplayPlaneCapabilities2KHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDisplayPlaneCapabilities2KHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkImageFormatListCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImageFormatListCreateInfoKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevice8BitStorageFeaturesKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDevice8BitStorageFeaturesKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderAtomicInt64FeaturesKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceShaderAtomicInt64FeaturesKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDriverPropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceDriverPropertiesKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFloatControlsPropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceFloatControlsPropertiesKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkSubpassDescriptionDepthStencilResolveKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSubpassDescriptionDepthStencilResolveKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapStructArrayHandles<Decoded_VkAttachmentReference2KHR>(wrapper->pDepthStencilResolveAttachment.GetMetaStructPointer(), 1, object_mapper);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDepthStencilResolvePropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceDepthStencilResolvePropertiesKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVulkanMemoryModelFeaturesKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceVulkanMemoryModelFeaturesKHR* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDebugReportCallbackCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDebugReportCallbackCreateInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineRasterizationStateRasterizationOrderAMD* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineRasterizationStateRasterizationOrderAMD* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDebugMarkerObjectNameInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDebugMarkerObjectNameInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDebugMarkerObjectTagInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDebugMarkerObjectTagInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDebugMarkerMarkerInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDebugMarkerMarkerInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDedicatedAllocationImageCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDedicatedAllocationImageCreateInfoNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDedicatedAllocationBufferCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDedicatedAllocationBufferCreateInfoNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDedicatedAllocationMemoryAllocateInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDedicatedAllocationMemoryAllocateInfoNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->image = object_mapper.MapVkImage(wrapper->image);

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceTransformFeedbackFeaturesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceTransformFeedbackPropertiesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineRasterizationStateStreamCreateInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkTextureLODGatherFormatPropertiesAMD* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkTextureLODGatherFormatPropertiesAMD* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceCornerSampledImageFeaturesNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkExternalMemoryImageCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkExternalMemoryImageCreateInfoNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkExportMemoryAllocateInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkExportMemoryAllocateInfoNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkImportMemoryWin32HandleInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImportMemoryWin32HandleInfoNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkExportMemoryWin32HandleInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkExportMemoryWin32HandleInfoNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkWin32KeyedMutexAcquireReleaseInfoNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapHandleArray<VkDeviceMemory>(wrapper->pAcquireSyncs.GetPointer(), wrapper->pAcquireSyncs.GetHandlePointer(), wrapper->pAcquireSyncs.GetLength(), object_mapper, &VulkanObjectMapper::MapVkDeviceMemory);

        MapHandleArray<VkDeviceMemory>(wrapper->pReleaseSyncs.GetPointer(), wrapper->pReleaseSyncs.GetHandlePointer(), wrapper->pReleaseSyncs.GetLength(), object_mapper, &VulkanObjectMapper::MapVkDeviceMemory);
    }
}

void MapStructHandles(Decoded_VkValidationFlagsEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkValidationFlagsEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkViSurfaceCreateInfoNN* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkViSurfaceCreateInfoNN* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkImageViewASTCDecodeModeEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImageViewASTCDecodeModeEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceASTCDecodeFeaturesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkConditionalRenderingBeginInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkConditionalRenderingBeginInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceConditionalRenderingFeaturesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkCommandBufferInheritanceConditionalRenderingInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceGeneratedCommandsFeaturesNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDeviceGeneratedCommandsFeaturesNVX* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceGeneratedCommandsLimitsNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDeviceGeneratedCommandsLimitsNVX* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkIndirectCommandsTokenNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkIndirectCommandsTokenNVX* value = wrapper->value;

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);
    }
}

void MapStructHandles(Decoded_VkIndirectCommandsLayoutCreateInfoNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkIndirectCommandsLayoutCreateInfoNVX* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkCmdProcessCommandsInfoNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkCmdProcessCommandsInfoNVX* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->objectTable = object_mapper.MapVkObjectTableNVX(wrapper->objectTable);

        value->indirectCommandsLayout = object_mapper.MapVkIndirectCommandsLayoutNVX(wrapper->indirectCommandsLayout);

        MapStructArrayHandles<Decoded_VkIndirectCommandsTokenNVX>(wrapper->pIndirectCommandsTokens.GetMetaStructPointer(), wrapper->pIndirectCommandsTokens.GetLength(), object_mapper);

        value->targetCommandBuffer = object_mapper.MapVkCommandBuffer(wrapper->targetCommandBuffer);

        value->sequencesCountBuffer = object_mapper.MapVkBuffer(wrapper->sequencesCountBuffer);

        value->sequencesIndexBuffer = object_mapper.MapVkBuffer(wrapper->sequencesIndexBuffer);
    }
}

void MapStructHandles(Decoded_VkCmdReserveSpaceForCommandsInfoNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkCmdReserveSpaceForCommandsInfoNVX* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->objectTable = object_mapper.MapVkObjectTableNVX(wrapper->objectTable);

        value->indirectCommandsLayout = object_mapper.MapVkIndirectCommandsLayoutNVX(wrapper->indirectCommandsLayout);
    }
}

void MapStructHandles(Decoded_VkObjectTableCreateInfoNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkObjectTableCreateInfoNVX* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkObjectTablePipelineEntryNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkObjectTablePipelineEntryNVX* value = wrapper->value;

        value->pipeline = object_mapper.MapVkPipeline(wrapper->pipeline);
    }
}

void MapStructHandles(Decoded_VkObjectTableDescriptorSetEntryNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkObjectTableDescriptorSetEntryNVX* value = wrapper->value;

        value->pipelineLayout = object_mapper.MapVkPipelineLayout(wrapper->pipelineLayout);

        value->descriptorSet = object_mapper.MapVkDescriptorSet(wrapper->descriptorSet);
    }
}

void MapStructHandles(Decoded_VkObjectTableVertexBufferEntryNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkObjectTableVertexBufferEntryNVX* value = wrapper->value;

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);
    }
}

void MapStructHandles(Decoded_VkObjectTableIndexBufferEntryNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkObjectTableIndexBufferEntryNVX* value = wrapper->value;

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);
    }
}

void MapStructHandles(Decoded_VkObjectTablePushConstantEntryNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkObjectTablePushConstantEntryNVX* value = wrapper->value;

        value->pipelineLayout = object_mapper.MapVkPipelineLayout(wrapper->pipelineLayout);
    }
}

void MapStructHandles(Decoded_VkPipelineViewportWScalingStateCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineViewportWScalingStateCreateInfoNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkSurfaceCapabilities2EXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSurfaceCapabilities2EXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDisplayPowerInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDisplayPowerInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceEventInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDeviceEventInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDisplayEventInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDisplayEventInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkSwapchainCounterCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSwapchainCounterCreateInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPresentTimesInfoGOOGLE* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPresentTimesInfoGOOGLE* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineViewportSwizzleStateCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineViewportSwizzleStateCreateInfoNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceDiscardRectanglePropertiesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineDiscardRectangleStateCreateInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceConservativeRasterizationPropertiesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineRasterizationConservativeStateCreateInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkHdrMetadataEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkHdrMetadataEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkIOSSurfaceCreateInfoMVK* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkIOSSurfaceCreateInfoMVK* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkMacOSSurfaceCreateInfoMVK* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkMacOSSurfaceCreateInfoMVK* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDebugUtilsObjectNameInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDebugUtilsObjectNameInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDebugUtilsObjectTagInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDebugUtilsObjectTagInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDebugUtilsLabelEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDebugUtilsLabelEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDebugUtilsMessengerCallbackDataEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDebugUtilsMessengerCallbackDataEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapStructArrayHandles<Decoded_VkDebugUtilsLabelEXT>(wrapper->pQueueLabels.GetMetaStructPointer(), wrapper->pQueueLabels.GetLength(), object_mapper);

        MapStructArrayHandles<Decoded_VkDebugUtilsLabelEXT>(wrapper->pCmdBufLabels.GetMetaStructPointer(), wrapper->pCmdBufLabels.GetLength(), object_mapper);

        MapStructArrayHandles<Decoded_VkDebugUtilsObjectNameInfoEXT>(wrapper->pObjects.GetMetaStructPointer(), wrapper->pObjects.GetLength(), object_mapper);
    }
}

void MapStructHandles(Decoded_VkDebugUtilsMessengerCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDebugUtilsMessengerCreateInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkAndroidHardwareBufferUsageANDROID* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkAndroidHardwareBufferUsageANDROID* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkAndroidHardwareBufferPropertiesANDROID* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkAndroidHardwareBufferPropertiesANDROID* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkAndroidHardwareBufferFormatPropertiesANDROID* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkImportAndroidHardwareBufferInfoANDROID* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImportAndroidHardwareBufferInfoANDROID* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkMemoryGetAndroidHardwareBufferInfoANDROID* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->memory = object_mapper.MapVkDeviceMemory(wrapper->memory);
    }
}

void MapStructHandles(Decoded_VkExternalFormatANDROID* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkExternalFormatANDROID* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkSamplerReductionModeCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSamplerReductionModeCreateInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceInlineUniformBlockFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceInlineUniformBlockFeaturesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceInlineUniformBlockPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceInlineUniformBlockPropertiesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkWriteDescriptorSetInlineUniformBlockEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkWriteDescriptorSetInlineUniformBlockEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorPoolInlineUniformBlockCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDescriptorPoolInlineUniformBlockCreateInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkSampleLocationsInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSampleLocationsInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkAttachmentSampleLocationsEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(&wrapper->sampleLocationsInfo, object_mapper);
    }
}

void MapStructHandles(Decoded_VkSubpassSampleLocationsEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(&wrapper->sampleLocationsInfo, object_mapper);
    }
}

void MapStructHandles(Decoded_VkRenderPassSampleLocationsBeginInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkRenderPassSampleLocationsBeginInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapStructArrayHandles<Decoded_VkAttachmentSampleLocationsEXT>(wrapper->pAttachmentInitialSampleLocations.GetMetaStructPointer(), wrapper->pAttachmentInitialSampleLocations.GetLength(), object_mapper);

        MapStructArrayHandles<Decoded_VkSubpassSampleLocationsEXT>(wrapper->pPostSubpassSampleLocations.GetMetaStructPointer(), wrapper->pPostSubpassSampleLocations.GetLength(), object_mapper);
    }
}

void MapStructHandles(Decoded_VkPipelineSampleLocationsStateCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineSampleLocationsStateCreateInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapStructHandles(&wrapper->sampleLocationsInfo, object_mapper);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceSampleLocationsPropertiesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkMultisamplePropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkMultisamplePropertiesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineColorBlendAdvancedStateCreateInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineCoverageToColorStateCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineCoverageToColorStateCreateInfoNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineCoverageModulationStateCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineCoverageModulationStateCreateInfoNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDrmFormatModifierPropertiesListEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDrmFormatModifierPropertiesListEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceImageDrmFormatModifierInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkImageDrmFormatModifierListCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImageDrmFormatModifierListCreateInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImageDrmFormatModifierExplicitCreateInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkImageDrmFormatModifierPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImageDrmFormatModifierPropertiesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkValidationCacheCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkValidationCacheCreateInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkShaderModuleValidationCacheCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkShaderModuleValidationCacheCreateInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->validationCache = object_mapper.MapVkValidationCacheEXT(wrapper->validationCache);
    }
}

void MapStructHandles(Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDescriptorSetLayoutBindingFlagsCreateInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorIndexingFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceDescriptorIndexingFeaturesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorIndexingPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceDescriptorIndexingPropertiesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDescriptorSetVariableDescriptorCountAllocateInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupportEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDescriptorSetVariableDescriptorCountLayoutSupportEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineViewportShadingRateImageStateCreateInfoNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceShadingRateImageFeaturesNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceShadingRateImagePropertiesNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkRayTracingShaderGroupCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkRayTracingShaderGroupCreateInfoNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkRayTracingPipelineCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkRayTracingPipelineCreateInfoNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapStructArrayHandles<Decoded_VkPipelineShaderStageCreateInfo>(wrapper->pStages.GetMetaStructPointer(), wrapper->pStages.GetLength(), object_mapper);

        MapStructArrayHandles<Decoded_VkRayTracingShaderGroupCreateInfoNV>(wrapper->pGroups.GetMetaStructPointer(), wrapper->pGroups.GetLength(), object_mapper);

        value->layout = object_mapper.MapVkPipelineLayout(wrapper->layout);

        value->basePipelineHandle = object_mapper.MapVkPipeline(wrapper->basePipelineHandle);
    }
}

void MapStructHandles(Decoded_VkGeometryTrianglesNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkGeometryTrianglesNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->vertexData = object_mapper.MapVkBuffer(wrapper->vertexData);

        value->indexData = object_mapper.MapVkBuffer(wrapper->indexData);

        value->transformData = object_mapper.MapVkBuffer(wrapper->transformData);
    }
}

void MapStructHandles(Decoded_VkGeometryAABBNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkGeometryAABBNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->aabbData = object_mapper.MapVkBuffer(wrapper->aabbData);
    }
}

void MapStructHandles(Decoded_VkGeometryDataNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(&wrapper->triangles, object_mapper);

        MapStructHandles(&wrapper->aabbs, object_mapper);
    }
}

void MapStructHandles(Decoded_VkGeometryNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkGeometryNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapStructHandles(&wrapper->geometry, object_mapper);
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkAccelerationStructureInfoNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapStructArrayHandles<Decoded_VkGeometryNV>(wrapper->pGeometries.GetMetaStructPointer(), wrapper->pGeometries.GetLength(), object_mapper);
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkAccelerationStructureCreateInfoNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapStructHandles(&wrapper->info, object_mapper);
    }
}

void MapStructHandles(Decoded_VkBindAccelerationStructureMemoryInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBindAccelerationStructureMemoryInfoNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->accelerationStructure = object_mapper.MapVkAccelerationStructureNV(wrapper->accelerationStructure);

        value->memory = object_mapper.MapVkDeviceMemory(wrapper->memory);
    }
}

void MapStructHandles(Decoded_VkWriteDescriptorSetAccelerationStructureNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkWriteDescriptorSetAccelerationStructureNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapHandleArray<VkAccelerationStructureNV>(wrapper->pAccelerationStructures.GetPointer(), wrapper->pAccelerationStructures.GetHandlePointer(), wrapper->pAccelerationStructures.GetLength(), object_mapper, &VulkanObjectMapper::MapVkAccelerationStructureNV);
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureMemoryRequirementsInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkAccelerationStructureMemoryRequirementsInfoNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->accelerationStructure = object_mapper.MapVkAccelerationStructureNV(wrapper->accelerationStructure);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingPropertiesNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceRayTracingPropertiesNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineRepresentativeFragmentTestStateCreateInfoNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceQueueGlobalPriorityCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDeviceQueueGlobalPriorityCreateInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkImportMemoryHostPointerInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImportMemoryHostPointerInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryHostPointerPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkMemoryHostPointerPropertiesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceExternalMemoryHostPropertiesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkCalibratedTimestampInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkCalibratedTimestampInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderCorePropertiesAMD* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceShaderCorePropertiesAMD* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceMemoryOverallocationCreateInfoAMD* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDeviceMemoryOverallocationCreateInfoAMD* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineVertexInputDivisorStateCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineVertexInputDivisorStateCreateInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMeshShaderFeaturesNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceMeshShaderFeaturesNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMeshShaderPropertiesNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceMeshShaderPropertiesNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceShaderImageFootprintFeaturesNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineViewportExclusiveScissorStateCreateInfoNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceExclusiveScissorFeaturesNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkQueueFamilyCheckpointPropertiesNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkQueueFamilyCheckpointPropertiesNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkCheckpointDataNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkCheckpointDataNV* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDevicePCIBusInfoPropertiesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImagePipeSurfaceCreateInfoFUCHSIA* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceFragmentDensityMapFeaturesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceFragmentDensityMapPropertiesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkRenderPassFragmentDensityMapCreateInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceScalarBlockLayoutFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceScalarBlockLayoutFeaturesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceMemoryBudgetPropertiesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceMemoryPriorityFeaturesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryPriorityAllocateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkMemoryPriorityAllocateInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceBufferAddressFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceBufferAddressFeaturesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkBufferDeviceAddressInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBufferDeviceAddressInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);
    }
}

void MapStructHandles(Decoded_VkBufferDeviceAddressCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBufferDeviceAddressCreateInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkImageStencilUsageCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImageStencilUsageCreateInfoEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkValidationFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkValidationFeaturesEXT* value = wrapper->value;

        if (value->pNext != nullptr)
        {
            MapPNextStructHandles(value->pNext, wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapPNextStructHandles(const void* value, void* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((value != nullptr) && (wrapper != nullptr))
    {
        const VkBaseInStructure* base = reinterpret_cast<const VkBaseInStructure*>(value);

        switch (base->sType)
        {
        default:
            // TODO: Report or raise fatal error for unrecongized sType?
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSubgroupProperties*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevice16BitStorageFeatures*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryDedicatedRequirements*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryDedicatedAllocateInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryAllocateFlagsInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceGroupRenderPassBeginInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceGroupCommandBufferBeginInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceGroupSubmitInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceGroupBindSparseInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkBindBufferMemoryDeviceGroupInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkBindImageMemoryDeviceGroupInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceGroupDeviceCreateInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFeatures2*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePointClippingProperties*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassInputAttachmentAspectCreateInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkImageViewUsageCreateInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineTessellationDomainOriginStateCreateInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassMultiviewCreateInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewFeatures*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewProperties*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVariablePointerFeatures*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceProtectedMemoryFeatures*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceProtectedMemoryProperties*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkProtectedSubmitInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkSamplerYcbcrConversionInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkBindImagePlaneMemoryInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkImagePlaneMemoryRequirementsInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkSamplerYcbcrConversionImageFormatProperties*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExternalImageFormatInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkExternalImageFormatProperties*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceIDProperties*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkExternalMemoryImageCreateInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkExternalMemoryBufferCreateInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkExportMemoryAllocateInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkExportFenceCreateInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkExportSemaphoreCreateInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance3Properties*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETER_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderDrawParameterFeatures*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkImageSwapchainCreateInfoKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkBindImageMemorySwapchainInfoKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceGroupPresentInfoKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceGroupSwapchainCreateInfoKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkDisplayPresentInfoKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkImportMemoryWin32HandleInfoKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkExportMemoryWin32HandleInfoKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkImportMemoryFdInfoKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkExportSemaphoreWin32HandleInfoKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkD3D12FenceSubmitInfoKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePushDescriptorPropertiesKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT16_INT8_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFloat16Int8FeaturesKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPresentRegionsKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkSharedPresentSurfaceCapabilitiesKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkExportFenceWin32HandleInfoKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkImageFormatListCreateInfoKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevice8BitStorageFeaturesKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderAtomicInt64FeaturesKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDriverPropertiesKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFloatControlsPropertiesKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkSubpassDescriptionDepthStencilResolveKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDepthStencilResolvePropertiesKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVulkanMemoryModelFeaturesKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDebugReportCallbackCreateInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineRasterizationStateRasterizationOrderAMD*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkDedicatedAllocationImageCreateInfoNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkDedicatedAllocationBufferCreateInfoNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkDedicatedAllocationMemoryAllocateInfoNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkTextureLODGatherFormatPropertiesAMD*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkExternalMemoryImageCreateInfoNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkExportMemoryAllocateInfoNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkImportMemoryWin32HandleInfoNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkExportMemoryWin32HandleInfoNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkValidationFlagsEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImageViewASTCDecodeModeEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineViewportWScalingStateCreateInfoNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkSwapchainCounterCreateInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
            MapStructHandles(reinterpret_cast<Decoded_VkPresentTimesInfoGOOGLE*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineViewportSwizzleStateCreateInfoNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDebugUtilsMessengerCreateInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
            MapStructHandles(reinterpret_cast<Decoded_VkAndroidHardwareBufferUsageANDROID*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
            MapStructHandles(reinterpret_cast<Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            MapStructHandles(reinterpret_cast<Decoded_VkImportAndroidHardwareBufferInfoANDROID*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
            MapStructHandles(reinterpret_cast<Decoded_VkExternalFormatANDROID*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkSamplerReductionModeCreateInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceInlineUniformBlockFeaturesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceInlineUniformBlockPropertiesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkWriteDescriptorSetInlineUniformBlockEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDescriptorPoolInlineUniformBlockCreateInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkSampleLocationsInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassSampleLocationsBeginInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineSampleLocationsStateCreateInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineCoverageToColorStateCreateInfoNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineCoverageModulationStateCreateInfoNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDrmFormatModifierPropertiesListEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImageDrmFormatModifierListCreateInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkShaderModuleValidationCacheCreateInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorIndexingFeaturesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorIndexingPropertiesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupportEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkWriteDescriptorSetAccelerationStructureNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingPropertiesNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceQueueGlobalPriorityCreateInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImportMemoryHostPointerInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderCorePropertiesAMD*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceMemoryOverallocationCreateInfoAMD*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineVertexInputDivisorStateCreateInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMeshShaderFeaturesNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMeshShaderPropertiesNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkQueueFamilyCheckpointPropertiesNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceScalarBlockLayoutFeaturesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryPriorityAllocateInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_ADDRESS_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceBufferAddressFeaturesEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkBufferDeviceAddressCreateInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImageStencilUsageCreateInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkValidationFeaturesEXT*>(wrapper), object_mapper);
            break;
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
