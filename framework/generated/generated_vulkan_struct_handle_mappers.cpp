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

#include "generated/generated_vulkan_struct_handle_mappers.h"

#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/vulkan_handle_mapping_util.h"
#include "generated/generated_vulkan_struct_decoders.h"

#include <algorithm>
#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void MapStructHandles(Decoded_VkBufferMemoryBarrier* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBufferMemoryBarrier* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageMemoryBarrier* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImageMemoryBarrier* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryBarrier* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkApplicationInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkInstanceCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceQueueCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSubmitInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSubmitInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->pWaitSemaphores = handle_mapping::MapHandleArray<VulkanSemaphoreInfo>(&wrapper->pWaitSemaphores, object_info_table, &CommonObjectInfoTable::GetVkSemaphoreInfo);

        value->pCommandBuffers = handle_mapping::MapHandleArray<VulkanCommandBufferInfo>(&wrapper->pCommandBuffers, object_info_table, &CommonObjectInfoTable::GetVkCommandBufferInfo);

        value->pSignalSemaphores = handle_mapping::MapHandleArray<VulkanSemaphoreInfo>(&wrapper->pSignalSemaphores, object_info_table, &CommonObjectInfoTable::GetVkSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkMappedMemoryRange* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMappedMemoryRange* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryAllocateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSparseMemoryBind* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSparseMemoryBind* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkSparseBufferMemoryBindInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSparseBufferMemoryBindInfo* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        MapStructArrayHandles<Decoded_VkSparseMemoryBind>(wrapper->pBinds->GetMetaStructPointer(), wrapper->pBinds->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkSparseImageOpaqueMemoryBindInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSparseImageOpaqueMemoryBindInfo* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        MapStructArrayHandles<Decoded_VkSparseMemoryBind>(wrapper->pBinds->GetMetaStructPointer(), wrapper->pBinds->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkSparseImageMemoryBind* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSparseImageMemoryBind* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkSparseImageMemoryBindInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSparseImageMemoryBindInfo* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        MapStructArrayHandles<Decoded_VkSparseImageMemoryBind>(wrapper->pBinds->GetMetaStructPointer(), wrapper->pBinds->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkBindSparseInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBindSparseInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->pWaitSemaphores = handle_mapping::MapHandleArray<VulkanSemaphoreInfo>(&wrapper->pWaitSemaphores, object_info_table, &CommonObjectInfoTable::GetVkSemaphoreInfo);

        MapStructArrayHandles<Decoded_VkSparseBufferMemoryBindInfo>(wrapper->pBufferBinds->GetMetaStructPointer(), wrapper->pBufferBinds->GetLength(), object_info_table);

        MapStructArrayHandles<Decoded_VkSparseImageOpaqueMemoryBindInfo>(wrapper->pImageOpaqueBinds->GetMetaStructPointer(), wrapper->pImageOpaqueBinds->GetLength(), object_info_table);

        MapStructArrayHandles<Decoded_VkSparseImageMemoryBindInfo>(wrapper->pImageBinds->GetMetaStructPointer(), wrapper->pImageBinds->GetLength(), object_info_table);

        value->pSignalSemaphores = handle_mapping::MapHandleArray<VulkanSemaphoreInfo>(&wrapper->pSignalSemaphores, object_info_table, &CommonObjectInfoTable::GetVkSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkFenceCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSemaphoreCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkQueryPoolCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBufferCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageViewCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImageViewCreateInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);
    }
}

void MapStructHandles(Decoded_VkCommandPoolCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCommandBufferAllocateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCommandBufferAllocateInfo* value = wrapper->decoded_value;

        value->commandPool = handle_mapping::MapHandle<VulkanCommandPoolInfo>(wrapper->commandPool, object_info_table, &CommonObjectInfoTable::GetVkCommandPoolInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCommandBufferInheritanceInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCommandBufferInheritanceInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->renderPass = handle_mapping::MapHandle<VulkanRenderPassInfo>(wrapper->renderPass, object_info_table, &CommonObjectInfoTable::GetVkRenderPassInfo);

        value->framebuffer = handle_mapping::MapHandle<VulkanFramebufferInfo>(wrapper->framebuffer, object_info_table, &CommonObjectInfoTable::GetVkFramebufferInfo);
    }
}

void MapStructHandles(Decoded_VkCommandBufferBeginInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkCommandBufferInheritanceInfo>(wrapper->pInheritanceInfo->GetMetaStructPointer(), 1, object_info_table);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkEventCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBufferViewCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBufferViewCreateInfo* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkShaderModuleCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineCacheCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineShaderStageCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineShaderStageCreateInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->module = handle_mapping::MapHandle<VulkanShaderModuleInfo>(wrapper->module, object_info_table, &CommonObjectInfoTable::GetVkShaderModuleInfo);
    }
}

void MapStructHandles(Decoded_VkComputePipelineCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkComputePipelineCreateInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        MapStructHandles(wrapper->stage, object_info_table);

        value->layout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->layout, object_info_table, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);

        value->basePipelineHandle = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->basePipelineHandle, object_info_table, &CommonObjectInfoTable::GetVkPipelineInfo);
    }
}

void MapStructHandles(Decoded_VkPipelineLayoutCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineLayoutCreateInfo* value = wrapper->decoded_value;

        value->pSetLayouts = handle_mapping::MapHandleArray<VulkanDescriptorSetLayoutInfo>(&wrapper->pSetLayouts, object_info_table, &CommonObjectInfoTable::GetVkDescriptorSetLayoutInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSamplerCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCopyDescriptorSet* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyDescriptorSet* value = wrapper->decoded_value;

        value->srcSet = handle_mapping::MapHandle<VulkanDescriptorSetInfo>(wrapper->srcSet, object_info_table, &CommonObjectInfoTable::GetVkDescriptorSetInfo);

        value->dstSet = handle_mapping::MapHandle<VulkanDescriptorSetInfo>(wrapper->dstSet, object_info_table, &CommonObjectInfoTable::GetVkDescriptorSetInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorBufferInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDescriptorBufferInfo* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);
    }
}

void MapStructHandles(Decoded_VkDescriptorPoolCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorSetAllocateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDescriptorSetAllocateInfo* value = wrapper->decoded_value;

        value->descriptorPool = handle_mapping::MapHandle<VulkanDescriptorPoolInfo>(wrapper->descriptorPool, object_info_table, &CommonObjectInfoTable::GetVkDescriptorPoolInfo);

        value->pSetLayouts = handle_mapping::MapHandleArray<VulkanDescriptorSetLayoutInfo>(&wrapper->pSetLayouts, object_info_table, &CommonObjectInfoTable::GetVkDescriptorSetLayoutInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorSetLayoutBinding* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDescriptorSetLayoutBinding* value = wrapper->decoded_value;

        value->pImmutableSamplers = handle_mapping::MapHandleArray<VulkanSamplerInfo>(&wrapper->pImmutableSamplers, object_info_table, &CommonObjectInfoTable::GetVkSamplerInfo);
    }
}

void MapStructHandles(Decoded_VkDescriptorSetLayoutCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkDescriptorSetLayoutBinding>(wrapper->pBindings->GetMetaStructPointer(), wrapper->pBindings->GetLength(), object_info_table);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineVertexInputStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineInputAssemblyStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineTessellationStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineViewportStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineRasterizationStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineMultisampleStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineDepthStencilStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineColorBlendStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineDynamicStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkGraphicsPipelineCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGraphicsPipelineCreateInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        MapStructArrayHandles<Decoded_VkPipelineShaderStageCreateInfo>(wrapper->pStages->GetMetaStructPointer(), wrapper->pStages->GetLength(), object_info_table);

        value->layout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->layout, object_info_table, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);

        value->renderPass = handle_mapping::MapHandle<VulkanRenderPassInfo>(wrapper->renderPass, object_info_table, &CommonObjectInfoTable::GetVkRenderPassInfo);

        value->basePipelineHandle = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->basePipelineHandle, object_info_table, &CommonObjectInfoTable::GetVkPipelineInfo);
    }
}

void MapStructHandles(Decoded_VkFramebufferCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkFramebufferCreateInfo* value = wrapper->decoded_value;

        value->renderPass = handle_mapping::MapHandle<VulkanRenderPassInfo>(wrapper->renderPass, object_info_table, &CommonObjectInfoTable::GetVkRenderPassInfo);

        value->pAttachments = handle_mapping::MapHandleArray<VulkanImageViewInfo>(&wrapper->pAttachments, object_info_table, &CommonObjectInfoTable::GetVkImageViewInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassBeginInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkRenderPassBeginInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->renderPass = handle_mapping::MapHandle<VulkanRenderPassInfo>(wrapper->renderPass, object_info_table, &CommonObjectInfoTable::GetVkRenderPassInfo);

        value->framebuffer = handle_mapping::MapHandle<VulkanFramebufferInfo>(wrapper->framebuffer, object_info_table, &CommonObjectInfoTable::GetVkFramebufferInfo);
    }
}

void MapStructHandles(Decoded_VkBindBufferMemoryInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBindBufferMemoryInfo* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBindImageMemoryInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBindImageMemoryInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkMemoryDedicatedRequirements* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryDedicatedAllocateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryDedicatedAllocateInfo* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryAllocateFlagsInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceGroupCommandBufferBeginInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceGroupSubmitInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceGroupBindSparseInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBindBufferMemoryDeviceGroupInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBindImageMemoryDeviceGroupInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceGroupProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        handle_mapping::MapHandleArray<VulkanPhysicalDeviceInfo>(&wrapper->physicalDevices, object_info_table, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceGroupDeviceCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDeviceGroupDeviceCreateInfo* value = wrapper->decoded_value;

        value->pPhysicalDevices = handle_mapping::MapHandleArray<VulkanPhysicalDeviceInfo>(&wrapper->pPhysicalDevices, object_info_table, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBufferMemoryRequirementsInfo2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBufferMemoryRequirementsInfo2* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageMemoryRequirementsInfo2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImageMemoryRequirementsInfo2* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageSparseMemoryRequirementsInfo2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImageSparseMemoryRequirementsInfo2* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryRequirements2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSparseImageMemoryRequirements2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFeatures2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceProperties2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkFormatProperties2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageFormatProperties2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageFormatInfo2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkQueueFamilyProperties2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMemoryProperties2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSparseImageFormatProperties2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSparseImageFormatInfo2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageViewUsageCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceProtectedMemoryFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceProtectedMemoryProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceQueueInfo2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkProtectedSubmitInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBindImagePlaneMemoryInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImagePlaneMemoryRequirementsInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExternalImageFormatInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkExternalImageFormatProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExternalBufferInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkExternalBufferProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceIDProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkExternalMemoryImageCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkExternalMemoryBufferCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkExportMemoryAllocateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExternalFenceInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkExternalFenceProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkExportFenceCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkExportSemaphoreCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExternalSemaphoreInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkExternalSemaphoreProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSubgroupProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevice16BitStorageFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVariablePointersFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorUpdateTemplateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDescriptorUpdateTemplateCreateInfo* value = wrapper->decoded_value;

        value->descriptorSetLayout = handle_mapping::MapHandle<VulkanDescriptorSetLayoutInfo>(wrapper->descriptorSetLayout, object_info_table, &CommonObjectInfoTable::GetVkDescriptorSetLayoutInfo);

        value->pipelineLayout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->pipelineLayout, object_info_table, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance3Properties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorSetLayoutSupport* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSamplerYcbcrConversionCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSamplerYcbcrConversionInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSamplerYcbcrConversionInfo* value = wrapper->decoded_value;

        value->conversion = handle_mapping::MapHandle<VulkanSamplerYcbcrConversionInfo>(wrapper->conversion, object_info_table, &CommonObjectInfoTable::GetVkSamplerYcbcrConversionInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSamplerYcbcrConversionImageFormatProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceGroupRenderPassBeginInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePointClippingProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassInputAttachmentAspectCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineTessellationDomainOriginStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassMultiviewCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMultiviewFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMultiviewProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderDrawParametersFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVulkan11Features* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVulkan11Properties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVulkan12Features* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVulkan12Properties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageFormatListCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDriverProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceHostQueryResetFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceTimelineSemaphoreProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSemaphoreTypeCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkTimelineSemaphoreSubmitInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSemaphoreWaitInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSemaphoreWaitInfo* value = wrapper->decoded_value;

        value->pSemaphores = handle_mapping::MapHandleArray<VulkanSemaphoreInfo>(&wrapper->pSemaphores, object_info_table, &CommonObjectInfoTable::GetVkSemaphoreInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSemaphoreSignalInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSemaphoreSignalInfo* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<VulkanSemaphoreInfo>(wrapper->semaphore, object_info_table, &CommonObjectInfoTable::GetVkSemaphoreInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBufferDeviceAddressInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBufferDeviceAddressInfo* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBufferOpaqueCaptureAddressCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDeviceMemoryOpaqueCaptureAddressInfo* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevice8BitStorageFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderAtomicInt64Features* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderFloat16Int8Features* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFloatControlsProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorIndexingFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorIndexingProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupport* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSamplerReductionModeCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSamplerFilterMinmaxProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAttachmentDescription2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAttachmentReference2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSubpassDescription2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSubpassDependency2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassCreateInfo2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSubpassBeginInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSubpassEndInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSubpassDescriptionDepthStencilResolve* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDepthStencilResolveProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageStencilUsageCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImagelessFramebufferFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkFramebufferAttachmentImageInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkFramebufferAttachmentsCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassAttachmentBeginInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkRenderPassAttachmentBeginInfo* value = wrapper->decoded_value;

        value->pAttachments = handle_mapping::MapHandleArray<VulkanImageViewInfo>(&wrapper->pAttachments, object_info_table, &CommonObjectInfoTable::GetVkImageViewInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAttachmentReferenceStencilLayout* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAttachmentDescriptionStencilLayout* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVulkan13Features* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVulkan13Properties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceToolProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePrivateDataFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDevicePrivateDataCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPrivateDataSlotCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryBarrier2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBufferMemoryBarrier2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBufferMemoryBarrier2* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageMemoryBarrier2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImageMemoryBarrier2* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDependencyInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkBufferMemoryBarrier2>(wrapper->pBufferMemoryBarriers->GetMetaStructPointer(), wrapper->pBufferMemoryBarriers->GetLength(), object_info_table);

        MapStructArrayHandles<Decoded_VkImageMemoryBarrier2>(wrapper->pImageMemoryBarriers->GetMetaStructPointer(), wrapper->pImageMemoryBarriers->GetLength(), object_info_table);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSemaphoreSubmitInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSemaphoreSubmitInfo* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<VulkanSemaphoreInfo>(wrapper->semaphore, object_info_table, &CommonObjectInfoTable::GetVkSemaphoreInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCommandBufferSubmitInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCommandBufferSubmitInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->commandBuffer = handle_mapping::MapHandle<VulkanCommandBufferInfo>(wrapper->commandBuffer, object_info_table, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    }
}

void MapStructHandles(Decoded_VkSubmitInfo2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        MapStructArrayHandles<Decoded_VkSemaphoreSubmitInfo>(wrapper->pWaitSemaphoreInfos->GetMetaStructPointer(), wrapper->pWaitSemaphoreInfos->GetLength(), object_info_table);

        MapStructArrayHandles<Decoded_VkCommandBufferSubmitInfo>(wrapper->pCommandBufferInfos->GetMetaStructPointer(), wrapper->pCommandBufferInfos->GetLength(), object_info_table);

        MapStructArrayHandles<Decoded_VkSemaphoreSubmitInfo>(wrapper->pSignalSemaphoreInfos->GetMetaStructPointer(), wrapper->pSignalSemaphoreInfos->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSynchronization2Features* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBufferCopy2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCopyBufferInfo2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyBufferInfo2* value = wrapper->decoded_value;

        value->srcBuffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->srcBuffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        value->dstBuffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->dstBuffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageCopy2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCopyImageInfo2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyImageInfo2* value = wrapper->decoded_value;

        value->srcImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->srcImage, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        value->dstImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->dstImage, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBufferImageCopy2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCopyBufferToImageInfo2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyBufferToImageInfo2* value = wrapper->decoded_value;

        value->srcBuffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->srcBuffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        value->dstImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->dstImage, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCopyImageToBufferInfo2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyImageToBufferInfo2* value = wrapper->decoded_value;

        value->srcImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->srcImage, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        value->dstBuffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->dstBuffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkFormatProperties3* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance4Features* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance4Properties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceBufferMemoryRequirements* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceImageMemoryRequirements* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkImageCreateInfo>(wrapper->pCreateInfo->GetMetaStructPointer(), 1, object_info_table);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineCreationFeedbackCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderTerminateInvocationFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePipelineCreationCacheControlFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageRobustnessFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSubgroupSizeControlFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSubgroupSizeControlProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceInlineUniformBlockFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceInlineUniformBlockProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkWriteDescriptorSetInlineUniformBlock* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorPoolInlineUniformBlockCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderIntegerDotProductFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderIntegerDotProductProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceTexelBufferAlignmentProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageBlit2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBlitImageInfo2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBlitImageInfo2* value = wrapper->decoded_value;

        value->srcImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->srcImage, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        value->dstImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->dstImage, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageResolve2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkResolveImageInfo2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkResolveImageInfo2* value = wrapper->decoded_value;

        value->srcImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->srcImage, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        value->dstImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->dstImage, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderingAttachmentInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkRenderingAttachmentInfo* value = wrapper->decoded_value;

        value->imageView = handle_mapping::MapHandle<VulkanImageViewInfo>(wrapper->imageView, object_info_table, &CommonObjectInfoTable::GetVkImageViewInfo);

        value->resolveImageView = handle_mapping::MapHandle<VulkanImageViewInfo>(wrapper->resolveImageView, object_info_table, &CommonObjectInfoTable::GetVkImageViewInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderingInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        MapStructArrayHandles<Decoded_VkRenderingAttachmentInfo>(wrapper->pColorAttachments->GetMetaStructPointer(), wrapper->pColorAttachments->GetLength(), object_info_table);

        MapStructArrayHandles<Decoded_VkRenderingAttachmentInfo>(wrapper->pDepthAttachment->GetMetaStructPointer(), 1, object_info_table);

        MapStructArrayHandles<Decoded_VkRenderingAttachmentInfo>(wrapper->pStencilAttachment->GetMetaStructPointer(), 1, object_info_table);
    }
}

void MapStructHandles(Decoded_VkPipelineRenderingCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDynamicRenderingFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCommandBufferInheritanceRenderingInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVulkan14Features* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVulkan14Properties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceQueueGlobalPriorityCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceGlobalPriorityQueryFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkQueueFamilyGlobalPriorityProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceIndexTypeUint8Features* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryMapInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryMapInfo* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryUnmapInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryUnmapInfo* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance5Features* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance5Properties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageSubresource2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceImageSubresourceInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkImageCreateInfo>(wrapper->pCreateInfo->GetMetaStructPointer(), 1, object_info_table);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSubresourceLayout2* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBufferUsageFlags2CreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance6Features* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance6Properties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBindMemoryStatus* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceHostImageCopyFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceHostImageCopyProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCopyImageToImageInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyImageToImageInfo* value = wrapper->decoded_value;

        value->srcImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->srcImage, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        value->dstImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->dstImage, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkHostImageLayoutTransitionInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkHostImageLayoutTransitionInfo* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSubresourceHostMemcpySize* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkHostImageCopyDevicePerformanceQuery* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderSubgroupRotateFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderFloatControls2Features* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderExpectAssumeFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineCreateFlags2CreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePushDescriptorProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBindDescriptorSetsInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBindDescriptorSetsInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->layout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->layout, object_info_table, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);

        value->pDescriptorSets = handle_mapping::MapHandleArray<VulkanDescriptorSetInfo>(&wrapper->pDescriptorSets, object_info_table, &CommonObjectInfoTable::GetVkDescriptorSetInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPushConstantsInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPushConstantsInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->layout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->layout, object_info_table, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPushDescriptorSetInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPushDescriptorSetInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->layout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->layout, object_info_table, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);

        MapStructArrayHandles<Decoded_VkWriteDescriptorSet>(wrapper->pDescriptorWrites->GetMetaStructPointer(), wrapper->pDescriptorWrites->GetLength(), object_info_table);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePipelineProtectedAccessFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePipelineRobustnessFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePipelineRobustnessProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineRobustnessCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceLineRasterizationFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceLineRasterizationProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineRasterizationLineStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVertexAttributeDivisorProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineVertexInputDivisorStateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVertexAttributeDivisorFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderingAreaInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDynamicRenderingLocalReadFeatures* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderingAttachmentLocationInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderingInputAttachmentIndexInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSwapchainCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSwapchainCreateInfoKHR* value = wrapper->decoded_value;

        value->surface = handle_mapping::MapHandle<VulkanSurfaceKHRInfo>(wrapper->surface, object_info_table, &CommonObjectInfoTable::GetVkSurfaceKHRInfo);

        value->oldSwapchain = handle_mapping::MapHandle<VulkanSwapchainKHRInfo>(wrapper->oldSwapchain, object_info_table, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPresentInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPresentInfoKHR* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->pWaitSemaphores = handle_mapping::MapHandleArray<VulkanSemaphoreInfo>(&wrapper->pWaitSemaphores, object_info_table, &CommonObjectInfoTable::GetVkSemaphoreInfo);

        value->pSwapchains = handle_mapping::MapHandleArray<VulkanSwapchainKHRInfo>(&wrapper->pSwapchains, object_info_table, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    }
}

void MapStructHandles(Decoded_VkImageSwapchainCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImageSwapchainCreateInfoKHR* value = wrapper->decoded_value;

        value->swapchain = handle_mapping::MapHandle<VulkanSwapchainKHRInfo>(wrapper->swapchain, object_info_table, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBindImageMemorySwapchainInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBindImageMemorySwapchainInfoKHR* value = wrapper->decoded_value;

        value->swapchain = handle_mapping::MapHandle<VulkanSwapchainKHRInfo>(wrapper->swapchain, object_info_table, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAcquireNextImageInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkAcquireNextImageInfoKHR* value = wrapper->decoded_value;

        value->swapchain = handle_mapping::MapHandle<VulkanSwapchainKHRInfo>(wrapper->swapchain, object_info_table, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);

        value->semaphore = handle_mapping::MapHandle<VulkanSemaphoreInfo>(wrapper->semaphore, object_info_table, &CommonObjectInfoTable::GetVkSemaphoreInfo);

        value->fence = handle_mapping::MapHandle<VulkanFenceInfo>(wrapper->fence, object_info_table, &CommonObjectInfoTable::GetVkFenceInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceGroupPresentCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceGroupPresentInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceGroupSwapchainCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDisplayModeCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDisplayModePropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDisplayModePropertiesKHR* value = wrapper->decoded_value;

        value->displayMode = handle_mapping::MapHandle<VulkanDisplayModeKHRInfo>(wrapper->displayMode, object_info_table, &CommonObjectInfoTable::GetVkDisplayModeKHRInfo);
    }
}

void MapStructHandles(Decoded_VkDisplayPlanePropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDisplayPlanePropertiesKHR* value = wrapper->decoded_value;

        value->currentDisplay = handle_mapping::MapHandle<VulkanDisplayKHRInfo>(wrapper->currentDisplay, object_info_table, &CommonObjectInfoTable::GetVkDisplayKHRInfo);
    }
}

void MapStructHandles(Decoded_VkDisplayPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDisplayPropertiesKHR* value = wrapper->decoded_value;

        value->display = handle_mapping::MapHandle<VulkanDisplayKHRInfo>(wrapper->display, object_info_table, &CommonObjectInfoTable::GetVkDisplayKHRInfo);
    }
}

void MapStructHandles(Decoded_VkDisplaySurfaceCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDisplaySurfaceCreateInfoKHR* value = wrapper->decoded_value;

        value->displayMode = handle_mapping::MapHandle<VulkanDisplayModeKHRInfo>(wrapper->displayMode, object_info_table, &CommonObjectInfoTable::GetVkDisplayModeKHRInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDisplayPresentInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkXlibSurfaceCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkXcbSurfaceCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkWaylandSurfaceCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAndroidSurfaceCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkWin32SurfaceCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkQueueFamilyQueryResultStatusPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkQueueFamilyVideoPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoProfileInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoProfileListInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVideoFormatInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoFormatPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoPictureResourceInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkVideoPictureResourceInfoKHR* value = wrapper->decoded_value;

        value->imageViewBinding = handle_mapping::MapHandle<VulkanImageViewInfo>(wrapper->imageViewBinding, object_info_table, &CommonObjectInfoTable::GetVkImageViewInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoReferenceSlotInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkVideoPictureResourceInfoKHR>(wrapper->pPictureResource->GetMetaStructPointer(), 1, object_info_table);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoSessionMemoryRequirementsKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBindVideoSessionMemoryInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBindVideoSessionMemoryInfoKHR* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoSessionCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoSessionParametersCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkVideoSessionParametersCreateInfoKHR* value = wrapper->decoded_value;

        value->videoSessionParametersTemplate = handle_mapping::MapHandle<VulkanVideoSessionParametersKHRInfo>(wrapper->videoSessionParametersTemplate, object_info_table, &CommonObjectInfoTable::GetVkVideoSessionParametersKHRInfo);

        value->videoSession = handle_mapping::MapHandle<VulkanVideoSessionKHRInfo>(wrapper->videoSession, object_info_table, &CommonObjectInfoTable::GetVkVideoSessionKHRInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoSessionParametersUpdateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoBeginCodingInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkVideoBeginCodingInfoKHR* value = wrapper->decoded_value;

        value->videoSession = handle_mapping::MapHandle<VulkanVideoSessionKHRInfo>(wrapper->videoSession, object_info_table, &CommonObjectInfoTable::GetVkVideoSessionKHRInfo);

        value->videoSessionParameters = handle_mapping::MapHandle<VulkanVideoSessionParametersKHRInfo>(wrapper->videoSessionParameters, object_info_table, &CommonObjectInfoTable::GetVkVideoSessionParametersKHRInfo);

        MapStructArrayHandles<Decoded_VkVideoReferenceSlotInfoKHR>(wrapper->pReferenceSlots->GetMetaStructPointer(), wrapper->pReferenceSlots->GetLength(), object_info_table);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEndCodingInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoCodingControlInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoDecodeCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoDecodeUsageInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoDecodeInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkVideoDecodeInfoKHR* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->srcBuffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->srcBuffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        MapStructHandles(wrapper->dstPictureResource, object_info_table);

        MapStructArrayHandles<Decoded_VkVideoReferenceSlotInfoKHR>(wrapper->pSetupReferenceSlot->GetMetaStructPointer(), 1, object_info_table);

        MapStructArrayHandles<Decoded_VkVideoReferenceSlotInfoKHR>(wrapper->pReferenceSlots->GetMetaStructPointer(), wrapper->pReferenceSlots->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkVideoEncodeH264CapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeH264QualityLevelPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeH264SessionCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeH264SessionParametersAddInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeH264SessionParametersCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeH264SessionParametersGetInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeH264SessionParametersFeedbackInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeH264NaluSliceInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeH264PictureInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeH264DpbSlotInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeH264ProfileInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeH264RateControlInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeH264RateControlLayerInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeH264GopRemainingFrameInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoDecodeH264ProfileInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoDecodeH264CapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoDecodeH264SessionParametersAddInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoDecodeH264SessionParametersCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoDecodeH264PictureInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoDecodeH264DpbSlotInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImportMemoryWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkExportMemoryWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryWin32HandlePropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryGetWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryGetWin32HandleInfoKHR* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImportMemoryFdInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryFdPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryGetFdInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryGetFdInfoKHR* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkWin32KeyedMutexAcquireReleaseInfoKHR* value = wrapper->decoded_value;

        value->pAcquireSyncs = handle_mapping::MapHandleArray<VulkanDeviceMemoryInfo>(&wrapper->pAcquireSyncs, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);

        value->pReleaseSyncs = handle_mapping::MapHandleArray<VulkanDeviceMemoryInfo>(&wrapper->pReleaseSyncs, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImportSemaphoreWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImportSemaphoreWin32HandleInfoKHR* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<VulkanSemaphoreInfo>(wrapper->semaphore, object_info_table, &CommonObjectInfoTable::GetVkSemaphoreInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkExportSemaphoreWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkD3D12FenceSubmitInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSemaphoreGetWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSemaphoreGetWin32HandleInfoKHR* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<VulkanSemaphoreInfo>(wrapper->semaphore, object_info_table, &CommonObjectInfoTable::GetVkSemaphoreInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImportSemaphoreFdInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImportSemaphoreFdInfoKHR* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<VulkanSemaphoreInfo>(wrapper->semaphore, object_info_table, &CommonObjectInfoTable::GetVkSemaphoreInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSemaphoreGetFdInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSemaphoreGetFdInfoKHR* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<VulkanSemaphoreInfo>(wrapper->semaphore, object_info_table, &CommonObjectInfoTable::GetVkSemaphoreInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPresentRegionsKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSharedPresentSurfaceCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImportFenceWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImportFenceWin32HandleInfoKHR* value = wrapper->decoded_value;

        value->fence = handle_mapping::MapHandle<VulkanFenceInfo>(wrapper->fence, object_info_table, &CommonObjectInfoTable::GetVkFenceInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkExportFenceWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkFenceGetWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkFenceGetWin32HandleInfoKHR* value = wrapper->decoded_value;

        value->fence = handle_mapping::MapHandle<VulkanFenceInfo>(wrapper->fence, object_info_table, &CommonObjectInfoTable::GetVkFenceInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImportFenceFdInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImportFenceFdInfoKHR* value = wrapper->decoded_value;

        value->fence = handle_mapping::MapHandle<VulkanFenceInfo>(wrapper->fence, object_info_table, &CommonObjectInfoTable::GetVkFenceInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkFenceGetFdInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkFenceGetFdInfoKHR* value = wrapper->decoded_value;

        value->fence = handle_mapping::MapHandle<VulkanFenceInfo>(wrapper->fence, object_info_table, &CommonObjectInfoTable::GetVkFenceInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePerformanceQueryFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePerformanceQueryPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPerformanceCounterKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPerformanceCounterDescriptionKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkQueryPoolPerformanceCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAcquireProfilingLockInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPerformanceQuerySubmitInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSurfaceInfo2KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPhysicalDeviceSurfaceInfo2KHR* value = wrapper->decoded_value;

        value->surface = handle_mapping::MapHandle<VulkanSurfaceKHRInfo>(wrapper->surface, object_info_table, &CommonObjectInfoTable::GetVkSurfaceKHRInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSurfaceCapabilities2KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSurfaceFormat2KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDisplayProperties2KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(wrapper->displayProperties, object_info_table);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDisplayPlaneProperties2KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(wrapper->displayPlaneProperties, object_info_table);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDisplayModeProperties2KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(wrapper->displayModeProperties, object_info_table);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDisplayPlaneInfo2KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDisplayPlaneInfo2KHR* value = wrapper->decoded_value;

        value->mode = handle_mapping::MapHandle<VulkanDisplayModeKHRInfo>(wrapper->mode, object_info_table, &CommonObjectInfoTable::GetVkDisplayModeKHRInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDisplayPlaneCapabilities2KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderBfloat16FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePortabilitySubsetFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePortabilitySubsetPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderClockFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkFragmentShadingRateAttachmentInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineFragmentShadingRateStateCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShadingRateFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShadingRatePropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShadingRateKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkRenderingFragmentShadingRateAttachmentInfoKHR* value = wrapper->decoded_value;

        value->imageView = handle_mapping::MapHandle<VulkanImageViewInfo>(wrapper->imageView, object_info_table, &CommonObjectInfoTable::GetVkImageViewInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderQuadControlFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSurfaceProtectedCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePresentWaitFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineInfoKHR* value = wrapper->decoded_value;

        value->pipeline = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->pipeline, object_info_table, &CommonObjectInfoTable::GetVkPipelineInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineExecutablePropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineExecutableInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineExecutableInfoKHR* value = wrapper->decoded_value;

        value->pipeline = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->pipeline, object_info_table, &CommonObjectInfoTable::GetVkPipelineInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineExecutableStatisticKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineExecutableInternalRepresentationKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineLibraryCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineLibraryCreateInfoKHR* value = wrapper->decoded_value;

        value->pLibraries = handle_mapping::MapHandleArray<VulkanPipelineInfo>(&wrapper->pLibraries, object_info_table, &CommonObjectInfoTable::GetVkPipelineInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPresentIdKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePresentIdFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkVideoEncodeInfoKHR* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->dstBuffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->dstBuffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        MapStructHandles(wrapper->srcPictureResource, object_info_table);

        MapStructArrayHandles<Decoded_VkVideoReferenceSlotInfoKHR>(wrapper->pSetupReferenceSlot->GetMetaStructPointer(), 1, object_info_table);

        MapStructArrayHandles<Decoded_VkVideoReferenceSlotInfoKHR>(wrapper->pReferenceSlots->GetMetaStructPointer(), wrapper->pReferenceSlots->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkVideoEncodeCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeUsageInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeRateControlLayerInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeRateControlInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeQualityLevelPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeQualityLevelInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeSessionParametersGetInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkVideoEncodeSessionParametersGetInfoKHR* value = wrapper->decoded_value;

        value->videoSessionParameters = handle_mapping::MapHandle<VulkanVideoSessionParametersKHRInfo>(wrapper->videoSessionParameters, object_info_table, &CommonObjectInfoTable::GetVkVideoSessionParametersKHRInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeSessionParametersFeedbackInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSurfaceCapabilitiesPresentId2KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPresentId2KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePresentId2FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSurfaceCapabilitiesPresentWait2KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePresentWait2FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPresentWait2InfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePipelineBinaryFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePipelineBinaryPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDevicePipelineBinaryInternalCacheControlKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineBinaryKeyKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineBinaryCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineBinaryCreateInfoKHR* value = wrapper->decoded_value;

        value->pipeline = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->pipeline, object_info_table, &CommonObjectInfoTable::GetVkPipelineInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineBinaryInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineBinaryInfoKHR* value = wrapper->decoded_value;

        value->pPipelineBinaries = handle_mapping::MapHandleArray<VulkanPipelineBinaryKHRInfo>(&wrapper->pPipelineBinaries, object_info_table, &CommonObjectInfoTable::GetVkPipelineBinaryKHRInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkReleaseCapturedPipelineDataInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkReleaseCapturedPipelineDataInfoKHR* value = wrapper->decoded_value;

        value->pipeline = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->pipeline, object_info_table, &CommonObjectInfoTable::GetVkPipelineInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineBinaryDataInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineBinaryDataInfoKHR* value = wrapper->decoded_value;

        value->pipelineBinary = handle_mapping::MapHandle<VulkanPipelineBinaryKHRInfo>(wrapper->pipelineBinary, object_info_table, &CommonObjectInfoTable::GetVkPipelineBinaryKHRInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineBinaryHandlesInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineBinaryHandlesInfoKHR* value = wrapper->decoded_value;

        value->pPipelineBinaries = handle_mapping::MapHandleArray<VulkanPipelineBinaryKHRInfo>(&wrapper->pPipelineBinaries, object_info_table, &CommonObjectInfoTable::GetVkPipelineBinaryKHRInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSurfacePresentModeKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSurfacePresentScalingCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSurfacePresentModeCompatibilityKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSwapchainPresentFenceInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSwapchainPresentFenceInfoKHR* value = wrapper->decoded_value;

        value->pFences = handle_mapping::MapHandleArray<VulkanFenceInfo>(&wrapper->pFences, object_info_table, &CommonObjectInfoTable::GetVkFenceInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSwapchainPresentModesCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSwapchainPresentModeInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSwapchainPresentScalingCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkReleaseSwapchainImagesInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkReleaseSwapchainImagesInfoKHR* value = wrapper->decoded_value;

        value->swapchain = handle_mapping::MapHandle<VulkanSwapchainKHRInfo>(wrapper->swapchain, object_info_table, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCooperativeMatrixPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoDecodeAV1ProfileInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoDecodeAV1CapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoDecodeAV1SessionParametersCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoDecodeAV1PictureInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoDecodeAV1DpbSlotInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVideoEncodeAV1FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeAV1CapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeAV1QualityLevelPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeAV1SessionCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeAV1SessionParametersCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeAV1PictureInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeAV1DpbSlotInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeAV1ProfileInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeAV1GopRemainingFrameInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeAV1RateControlInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeAV1RateControlLayerInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVideoDecodeVP9FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoDecodeVP9ProfileInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoDecodeVP9CapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoDecodeVP9PictureInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVideoMaintenance1FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoInlineQueryInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkVideoInlineQueryInfoKHR* value = wrapper->decoded_value;

        value->queryPool = handle_mapping::MapHandle<VulkanQueryPoolInfo>(wrapper->queryPool, object_info_table, &CommonObjectInfoTable::GetVkQueryPoolInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAttachmentFeedbackLoopInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCalibratedTimestampInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSetDescriptorBufferOffsetsInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSetDescriptorBufferOffsetsInfoEXT* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->layout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->layout, object_info_table, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBindDescriptorBufferEmbeddedSamplersInfoEXT* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->layout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->layout, object_info_table, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCopyMemoryIndirectInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCopyMemoryToImageIndirectInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyMemoryToImageIndirectInfoKHR* value = wrapper->decoded_value;

        value->dstImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->dstImage, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeIntraRefreshCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeSessionIntraRefreshCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeIntraRefreshInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoReferenceIntraRefreshInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeQuantizationMapCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoFormatQuantizationMapPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeQuantizationMapInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkVideoEncodeQuantizationMapInfoKHR* value = wrapper->decoded_value;

        value->quantizationMap = handle_mapping::MapHandle<VulkanImageViewInfo>(wrapper->quantizationMap, object_info_table, &CommonObjectInfoTable::GetVkImageViewInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeH264QuantizationMapCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeH265QuantizationMapCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoFormatH265QuantizationMapPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeAV1QuantizationMapCapabilitiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoFormatAV1QuantizationMapPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance7FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance7PropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceLayeredApiPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceLayeredApiPropertiesListKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceLayeredApiVulkanPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryBarrierAccessFlags3KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance8FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderFmaFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance9FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance9PropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkQueueFamilyOwnershipTransferPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRobustness2FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRobustness2PropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance10FeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance10PropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderingEndInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderingAttachmentFlagsInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkResolveImageModeInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDebugReportCallbackCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineRasterizationStateRasterizationOrderAMD* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDebugMarkerObjectNameInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDebugMarkerObjectNameInfoEXT* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->object = handle_mapping::MapHandle(wrapper->object, value->objectType, object_info_table);
    }
}

void MapStructHandles(Decoded_VkDebugMarkerObjectTagInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDebugMarkerObjectTagInfoEXT* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->object = handle_mapping::MapHandle(wrapper->object, value->objectType, object_info_table);
    }
}

void MapStructHandles(Decoded_VkDebugMarkerMarkerInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDedicatedAllocationImageCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDedicatedAllocationBufferCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDedicatedAllocationMemoryAllocateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDedicatedAllocationMemoryAllocateInfoNV* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageViewHandleInfoNVX* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImageViewHandleInfoNVX* value = wrapper->decoded_value;

        value->imageView = handle_mapping::MapHandle<VulkanImageViewInfo>(wrapper->imageView, object_info_table, &CommonObjectInfoTable::GetVkImageViewInfo);

        value->sampler = handle_mapping::MapHandle<VulkanSamplerInfo>(wrapper->sampler, object_info_table, &CommonObjectInfoTable::GetVkSamplerInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageViewAddressPropertiesNVX* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkTextureLODGatherFormatPropertiesAMD* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkStreamDescriptorSurfaceCreateInfoGGP* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkExternalMemoryImageCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkExportMemoryAllocateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImportMemoryWin32HandleInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkExportMemoryWin32HandleInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkWin32KeyedMutexAcquireReleaseInfoNV* value = wrapper->decoded_value;

        value->pAcquireSyncs = handle_mapping::MapHandleArray<VulkanDeviceMemoryInfo>(&wrapper->pAcquireSyncs, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);

        value->pReleaseSyncs = handle_mapping::MapHandleArray<VulkanDeviceMemoryInfo>(&wrapper->pReleaseSyncs, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkValidationFlagsEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkViSurfaceCreateInfoNN* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageViewASTCDecodeModeEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkConditionalRenderingBeginInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkConditionalRenderingBeginInfoEXT* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineViewportWScalingStateCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSurfaceCapabilities2EXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDisplayPowerInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceEventInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDisplayEventInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSwapchainCounterCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPresentTimesInfoGOOGLE* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMultiviewPerViewAttributesInfoNVX* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineViewportSwizzleStateCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkHdrMetadataEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkIOSSurfaceCreateInfoMVK* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMacOSSurfaceCreateInfoMVK* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDebugUtilsLabelEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDebugUtilsObjectNameInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDebugUtilsObjectNameInfoEXT* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->objectHandle = handle_mapping::MapHandle(wrapper->objectHandle, value->objectType, object_info_table);
    }
}

void MapStructHandles(Decoded_VkDebugUtilsMessengerCallbackDataEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDebugUtilsMessengerCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDebugUtilsObjectTagInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDebugUtilsObjectTagInfoEXT* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->objectHandle = handle_mapping::MapHandle(wrapper->objectHandle, value->objectType, object_info_table);
    }
}

void MapStructHandles(Decoded_VkAndroidHardwareBufferUsageANDROID* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAndroidHardwareBufferPropertiesANDROID* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImportAndroidHardwareBufferInfoANDROID* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryGetAndroidHardwareBufferInfoANDROID* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkExternalFormatANDROID* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAndroidHardwareBufferFormatProperties2ANDROID* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAttachmentSampleCountInfoAMD* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSampleLocationsInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassSampleLocationsBeginInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineSampleLocationsStateCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMultisamplePropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineCoverageToColorStateCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineCoverageModulationStateCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDrmFormatModifierPropertiesListEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageDrmFormatModifierListCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageDrmFormatModifierPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDrmFormatModifierPropertiesList2EXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkValidationCacheCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkShaderModuleValidationCacheCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkShaderModuleValidationCacheCreateInfoEXT* value = wrapper->decoded_value;

        value->validationCache = handle_mapping::MapHandle<VulkanValidationCacheEXTInfo>(wrapper->validationCache, object_info_table, &CommonObjectInfoTable::GetVkValidationCacheEXTInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRayTracingShaderGroupCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRayTracingPipelineCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkRayTracingPipelineCreateInfoNV* value = wrapper->decoded_value;

        MapStructArrayHandles<Decoded_VkPipelineShaderStageCreateInfo>(wrapper->pStages->GetMetaStructPointer(), wrapper->pStages->GetLength(), object_info_table);

        value->layout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->layout, object_info_table, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);

        value->basePipelineHandle = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->basePipelineHandle, object_info_table, &CommonObjectInfoTable::GetVkPipelineInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkGeometryTrianglesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGeometryTrianglesNV* value = wrapper->decoded_value;

        value->vertexData = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->vertexData, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        value->indexData = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->indexData, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        value->transformData = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->transformData, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkGeometryAABBNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGeometryAABBNV* value = wrapper->decoded_value;

        value->aabbData = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->aabbData, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkGeometryDataNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(wrapper->triangles, object_info_table);

        MapStructHandles(wrapper->aabbs, object_info_table);
    }
}

void MapStructHandles(Decoded_VkGeometryNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(wrapper->geometry, object_info_table);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkGeometryNV>(wrapper->pGeometries->GetMetaStructPointer(), wrapper->pGeometries->GetLength(), object_info_table);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(wrapper->info, object_info_table);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBindAccelerationStructureMemoryInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBindAccelerationStructureMemoryInfoNV* value = wrapper->decoded_value;

        value->accelerationStructure = handle_mapping::MapHandle<VulkanAccelerationStructureNVInfo>(wrapper->accelerationStructure, object_info_table, &CommonObjectInfoTable::GetVkAccelerationStructureNVInfo);

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkWriteDescriptorSetAccelerationStructureNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkWriteDescriptorSetAccelerationStructureNV* value = wrapper->decoded_value;

        value->pAccelerationStructures = handle_mapping::MapHandleArray<VulkanAccelerationStructureNVInfo>(&wrapper->pAccelerationStructures, object_info_table, &CommonObjectInfoTable::GetVkAccelerationStructureNVInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureMemoryRequirementsInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkAccelerationStructureMemoryRequirementsInfoNV* value = wrapper->decoded_value;

        value->accelerationStructure = handle_mapping::MapHandle<VulkanAccelerationStructureNVInfo>(wrapper->accelerationStructure, object_info_table, &CommonObjectInfoTable::GetVkAccelerationStructureNVInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImportMemoryHostPointerInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryHostPointerPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineCompilerControlCreateInfoAMD* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderCorePropertiesAMD* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceMemoryOverallocationCreateInfoAMD* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPresentFrameTokenGGP* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMeshShaderFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMeshShaderPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkQueueFamilyCheckpointPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCheckpointDataNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkQueueFamilyCheckpointProperties2NV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCheckpointData2NV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePresentTimingFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPresentTimingSurfaceCapabilitiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSwapchainCalibratedTimestampInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSwapchainCalibratedTimestampInfoEXT* value = wrapper->decoded_value;

        value->swapchain = handle_mapping::MapHandle<VulkanSwapchainKHRInfo>(wrapper->swapchain, object_info_table, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSwapchainTimingPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSwapchainTimeDomainPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPastPresentationTimingInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPastPresentationTimingInfoEXT* value = wrapper->decoded_value;

        value->swapchain = handle_mapping::MapHandle<VulkanSwapchainKHRInfo>(wrapper->swapchain, object_info_table, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPastPresentationTimingEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPastPresentationTimingPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPresentTimingInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPresentTimingsInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkInitializePerformanceApiInfoINTEL* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPerformanceMarkerInfoINTEL* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPerformanceStreamMarkerInfoINTEL* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPerformanceOverrideInfoINTEL* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPerformanceConfigurationAcquireInfoINTEL* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDisplayNativeHdrSurfaceCapabilitiesAMD* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSwapchainDisplayNativeHdrCreateInfoAMD* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMetalSurfaceCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkRenderingFragmentDensityMapAttachmentInfoEXT* value = wrapper->decoded_value;

        value->imageView = handle_mapping::MapHandle<VulkanImageViewInfo>(wrapper->imageView, object_info_table, &CommonObjectInfoTable::GetVkImageViewInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderCoreProperties2AMD* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryPriorityAllocateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBufferDeviceAddressCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkValidationFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCooperativeMatrixPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineCoverageReductionStateCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkFramebufferMixedSamplesCombinationNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceProvokingVertexFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceProvokingVertexPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSurfaceFullScreenExclusiveInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSurfaceCapabilitiesFullScreenExclusiveEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSurfaceFullScreenExclusiveWin32InfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkHeadlessSurfaceCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMapMemoryPlacedPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryMapPlacedInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkGraphicsShaderGroupCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkPipelineShaderStageCreateInfo>(wrapper->pStages->GetMetaStructPointer(), wrapper->pStages->GetLength(), object_info_table);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGraphicsPipelineShaderGroupsCreateInfoNV* value = wrapper->decoded_value;

        MapStructArrayHandles<Decoded_VkGraphicsShaderGroupCreateInfoNV>(wrapper->pGroups->GetMetaStructPointer(), wrapper->pGroups->GetLength(), object_info_table);

        value->pPipelines = handle_mapping::MapHandleArray<VulkanPipelineInfo>(&wrapper->pPipelines, object_info_table, &CommonObjectInfoTable::GetVkPipelineInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkIndirectCommandsStreamNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkIndirectCommandsStreamNV* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);
    }
}

void MapStructHandles(Decoded_VkIndirectCommandsLayoutTokenNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkIndirectCommandsLayoutTokenNV* value = wrapper->decoded_value;

        value->pushconstantPipelineLayout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->pushconstantPipelineLayout, object_info_table, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkIndirectCommandsLayoutCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkIndirectCommandsLayoutTokenNV>(wrapper->pTokens->GetMetaStructPointer(), wrapper->pTokens->GetLength(), object_info_table);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkGeneratedCommandsInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGeneratedCommandsInfoNV* value = wrapper->decoded_value;

        value->pipeline = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->pipeline, object_info_table, &CommonObjectInfoTable::GetVkPipelineInfo);

        value->indirectCommandsLayout = handle_mapping::MapHandle<VulkanIndirectCommandsLayoutNVInfo>(wrapper->indirectCommandsLayout, object_info_table, &CommonObjectInfoTable::GetVkIndirectCommandsLayoutNVInfo);

        MapStructArrayHandles<Decoded_VkIndirectCommandsStreamNV>(wrapper->pStreams->GetMetaStructPointer(), wrapper->pStreams->GetLength(), object_info_table);

        value->preprocessBuffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->preprocessBuffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        value->sequencesCountBuffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->sequencesCountBuffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        value->sequencesIndexBuffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->sequencesIndexBuffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGeneratedCommandsMemoryRequirementsInfoNV* value = wrapper->decoded_value;

        value->pipeline = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->pipeline, object_info_table, &CommonObjectInfoTable::GetVkPipelineInfo);

        value->indirectCommandsLayout = handle_mapping::MapHandle<VulkanIndirectCommandsLayoutNVInfo>(wrapper->indirectCommandsLayout, object_info_table, &CommonObjectInfoTable::GetVkIndirectCommandsLayoutNVInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceInheritedViewportScissorFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCommandBufferInheritanceViewportScissorInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassTransformBeginInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCommandBufferInheritanceRenderPassTransformInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDepthBiasControlFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDepthBiasInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDepthBiasRepresentationInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceMemoryReportCallbackDataEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceDeviceMemoryReportCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSamplerCustomBorderColorCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCustomBorderColorPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePresentBarrierFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSurfaceCapabilitiesPresentBarrierNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSwapchainPresentBarrierCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceDiagnosticsConfigCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceTileShadingFeaturesQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceTileShadingPropertiesQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassTileShadingCreateInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPerTileBeginInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPerTileEndInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDispatchTileInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkQueryLowLatencySupportNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorBufferPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorBufferFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorAddressInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorBufferBindingInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorBufferBindingPushDescriptorBufferHandleEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDescriptorBufferBindingPushDescriptorBufferHandleEXT* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBufferCaptureDescriptorDataInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBufferCaptureDescriptorDataInfoEXT* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageCaptureDescriptorDataInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImageCaptureDescriptorDataInfoEXT* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageViewCaptureDescriptorDataInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImageViewCaptureDescriptorDataInfoEXT* value = wrapper->decoded_value;

        value->imageView = handle_mapping::MapHandle<VulkanImageViewInfo>(wrapper->imageView, object_info_table, &CommonObjectInfoTable::GetVkImageViewInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSamplerCaptureDescriptorDataInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSamplerCaptureDescriptorDataInfoEXT* value = wrapper->decoded_value;

        value->sampler = handle_mapping::MapHandle<VulkanSamplerInfo>(wrapper->sampler, object_info_table, &CommonObjectInfoTable::GetVkSamplerInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkOpaqueCaptureDescriptorDataCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureCaptureDescriptorDataInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkAccelerationStructureCaptureDescriptorDataInfoEXT* value = wrapper->decoded_value;

        value->accelerationStructure = handle_mapping::MapHandle<VulkanAccelerationStructureKHRInfo>(wrapper->accelerationStructure, object_info_table, &CommonObjectInfoTable::GetVkAccelerationStructureKHRInfo);

        value->accelerationStructureNV = handle_mapping::MapHandle<VulkanAccelerationStructureNVInfo>(wrapper->accelerationStructureNV, object_info_table, &CommonObjectInfoTable::GetVkAccelerationStructureNVInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkGraphicsPipelineLibraryCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineFragmentShadingRateEnumStateCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureGeometryMotionTrianglesDataNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureMotionInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCopyCommandTransformInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageCompressionControlFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageCompressionControlEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageCompressionPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevice4444FormatsFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFaultFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceFaultCountsEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceFaultInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDirectFBSurfaceCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMutableDescriptorTypeCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVertexInputBindingDescription2EXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVertexInputAttributeDescription2EXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDrmPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceAddressBindingReportFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceAddressBindingCallbackDataEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDepthClipControlFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineViewportDepthClipControlCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImportMemoryZirconHandleInfoFUCHSIA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryZirconHandlePropertiesFUCHSIA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryGetZirconHandleInfoFUCHSIA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryGetZirconHandleInfoFUCHSIA* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImportSemaphoreZirconHandleInfoFUCHSIA* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<VulkanSemaphoreInfo>(wrapper->semaphore, object_info_table, &CommonObjectInfoTable::GetVkSemaphoreInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSemaphoreGetZirconHandleInfoFUCHSIA* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<VulkanSemaphoreInfo>(wrapper->semaphore, object_info_table, &CommonObjectInfoTable::GetVkSemaphoreInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryGetRemoteAddressInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryGetRemoteAddressInfoNV* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFrameBoundaryFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkFrameBoundaryEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkFrameBoundaryEXT* value = wrapper->decoded_value;

        value->pImages = handle_mapping::MapHandleArray<VulkanImageInfo>(&wrapper->pImages, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        value->pBuffers = handle_mapping::MapHandleArray<VulkanBufferInfo>(&wrapper->pBuffers, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSubpassResolvePerformanceQueryEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMultisampledRenderToSingleSampledInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkScreenSurfaceCreateInfoQNX* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceColorWriteEnableFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineColorWriteCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeRgbConversionCapabilitiesVALVE* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeProfileRgbConversionInfoVALVE* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeSessionRgbConversionCreateInfoVALVE* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageViewMinLodFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageViewMinLodCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMultiDrawFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMultiDrawPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderTileImageFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderTileImagePropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMicromapBuildInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMicromapBuildInfoEXT* value = wrapper->decoded_value;

        value->dstMicromap = handle_mapping::MapHandle<VulkanMicromapEXTInfo>(wrapper->dstMicromap, object_info_table, &CommonObjectInfoTable::GetVkMicromapEXTInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMicromapCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMicromapCreateInfoEXT* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceOpacityMicromapFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceOpacityMicromapPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMicromapVersionInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCopyMicromapToMemoryInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyMicromapToMemoryInfoEXT* value = wrapper->decoded_value;

        value->src = handle_mapping::MapHandle<VulkanMicromapEXTInfo>(wrapper->src, object_info_table, &CommonObjectInfoTable::GetVkMicromapEXTInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCopyMemoryToMicromapInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyMemoryToMicromapInfoEXT* value = wrapper->decoded_value;

        value->dst = handle_mapping::MapHandle<VulkanMicromapEXTInfo>(wrapper->dst, object_info_table, &CommonObjectInfoTable::GetVkMicromapEXTInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCopyMicromapInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyMicromapInfoEXT* value = wrapper->decoded_value;

        value->src = handle_mapping::MapHandle<VulkanMicromapEXTInfo>(wrapper->src, object_info_table, &CommonObjectInfoTable::GetVkMicromapEXTInfo);

        value->dst = handle_mapping::MapHandle<VulkanMicromapEXTInfo>(wrapper->dst, object_info_table, &CommonObjectInfoTable::GetVkMicromapEXTInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMicromapBuildSizesInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkAccelerationStructureTrianglesOpacityMicromapEXT* value = wrapper->decoded_value;

        value->micromap = handle_mapping::MapHandle<VulkanMicromapEXTInfo>(wrapper->micromap, object_info_table, &CommonObjectInfoTable::GetVkMicromapEXTInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDisplacementMicromapFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDisplacementMicromapPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureTrianglesDisplacementMicromapNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkAccelerationStructureTrianglesDisplacementMicromapNV* value = wrapper->decoded_value;

        value->micromap = handle_mapping::MapHandle<VulkanMicromapEXTInfo>(wrapper->micromap, object_info_table, &CommonObjectInfoTable::GetVkMicromapEXTInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSamplerBorderColorComponentMappingCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderCorePropertiesARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceQueueShaderCoreControlCreateInfoARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSchedulingControlsFeaturesARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSchedulingControlsPropertiesARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageViewSlicedCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorSetBindingReferenceVALVE* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDescriptorSetBindingReferenceVALVE* value = wrapper->decoded_value;

        value->descriptorSetLayout = handle_mapping::MapHandle<VulkanDescriptorSetLayoutInfo>(wrapper->descriptorSetLayout, object_info_table, &CommonObjectInfoTable::GetVkDescriptorSetLayoutInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRenderPassStripedFeaturesARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRenderPassStripedPropertiesARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassStripeInfoARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassStripeBeginInfoARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassStripeSubmitInfoARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkSemaphoreSubmitInfo>(wrapper->pStripeSemaphoreInfos->GetMetaStructPointer(), wrapper->pStripeSemaphoreInfos->GetLength(), object_info_table);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassFragmentDensityMapOffsetEndInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkComputePipelineIndirectBufferInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineIndirectDeviceAddressInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineIndirectDeviceAddressInfoNV* value = wrapper->decoded_value;

        value->pipeline = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->pipeline, object_info_table, &CommonObjectInfoTable::GetVkPipelineInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureGeometryLinearSweptSpheresDataNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureGeometrySpheresDataNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceLinearColorAttachmentFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageViewSampleWeightCreateInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageProcessingFeaturesQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageProcessingPropertiesQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceNestedCommandBufferFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceNestedCommandBufferPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkExternalMemoryAcquireUnmodifiedEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassCreationControlEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassCreationFeedbackCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassSubpassFeedbackCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDirectDriverLoadingInfoLUNARG* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDirectDriverLoadingListLUNARG* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineShaderStageModuleIdentifierCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkShaderModuleIdentifierEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceOpticalFlowFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceOpticalFlowPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkOpticalFlowImageFormatInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkOpticalFlowImageFormatPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkOpticalFlowSessionCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkOpticalFlowSessionCreatePrivateDataInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkOpticalFlowExecuteInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceLegacyDitheringFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAndroidHardwareBufferFormatResolvePropertiesANDROID* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceAntiLagFeaturesAMD* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAntiLagPresentationInfoAMD* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAntiLagDataAMD* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderObjectFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderObjectPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkShaderCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkShaderCreateInfoEXT* value = wrapper->decoded_value;

        value->pSetLayouts = handle_mapping::MapHandleArray<VulkanDescriptorSetLayoutInfo>(&wrapper->pSetLayouts, object_info_table, &CommonObjectInfoTable::GetVkDescriptorSetLayoutInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceTilePropertiesFeaturesQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkTilePropertiesQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceAmigoProfilingFeaturesSEC* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAmigoProfilingSubmitInfoSEC* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCooperativeVectorPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCooperativeVectorFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCooperativeVectorPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkConvertCooperativeVectorMatrixInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkLayerSettingsCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkLatencySleepModeInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkLatencySleepInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkLatencySleepInfoNV* value = wrapper->decoded_value;

        value->signalSemaphore = handle_mapping::MapHandle<VulkanSemaphoreInfo>(wrapper->signalSemaphore, object_info_table, &CommonObjectInfoTable::GetVkSemaphoreInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSetLatencyMarkerInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkLatencyTimingsFrameReportNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkGetLatencyMarkerInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkLatencySubmissionPresentIdNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSwapchainLatencyCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkOutOfBandQueueTypeInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkLatencySurfaceCapabilitiesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDataGraphFeaturesARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDataGraphPipelineConstantARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDataGraphPipelineResourceInfoARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDataGraphPipelineCompilerControlCreateInfoARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDataGraphPipelineCreateInfoARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDataGraphPipelineCreateInfoARM* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->layout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->layout, object_info_table, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDataGraphPipelineShaderModuleCreateInfoARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDataGraphPipelineShaderModuleCreateInfoARM* value = wrapper->decoded_value;

        value->module = handle_mapping::MapHandle<VulkanShaderModuleInfo>(wrapper->module, object_info_table, &CommonObjectInfoTable::GetVkShaderModuleInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDataGraphPipelineSessionCreateInfoARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDataGraphPipelineSessionCreateInfoARM* value = wrapper->decoded_value;

        value->dataGraphPipeline = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->dataGraphPipeline, object_info_table, &CommonObjectInfoTable::GetVkPipelineInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDataGraphPipelineSessionBindPointRequirementsInfoARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDataGraphPipelineSessionBindPointRequirementsInfoARM* value = wrapper->decoded_value;

        value->session = handle_mapping::MapHandle<VulkanDataGraphPipelineSessionARMInfo>(wrapper->session, object_info_table, &CommonObjectInfoTable::GetVkDataGraphPipelineSessionARMInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDataGraphPipelineSessionBindPointRequirementARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDataGraphPipelineSessionMemoryRequirementsInfoARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDataGraphPipelineSessionMemoryRequirementsInfoARM* value = wrapper->decoded_value;

        value->session = handle_mapping::MapHandle<VulkanDataGraphPipelineSessionARMInfo>(wrapper->session, object_info_table, &CommonObjectInfoTable::GetVkDataGraphPipelineSessionARMInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBindDataGraphPipelineSessionMemoryInfoARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBindDataGraphPipelineSessionMemoryInfoARM* value = wrapper->decoded_value;

        value->session = handle_mapping::MapHandle<VulkanDataGraphPipelineSessionARMInfo>(wrapper->session, object_info_table, &CommonObjectInfoTable::GetVkDataGraphPipelineSessionARMInfo);

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDataGraphPipelineInfoARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDataGraphPipelineInfoARM* value = wrapper->decoded_value;

        value->dataGraphPipeline = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->dataGraphPipeline, object_info_table, &CommonObjectInfoTable::GetVkPipelineInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDataGraphPipelinePropertyQueryResultARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDataGraphPipelineIdentifierCreateInfoARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDataGraphPipelineDispatchInfoARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkQueueFamilyDataGraphPropertiesARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDataGraphProcessingEngineCreateInfoARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkQueueFamilyDataGraphProcessingEnginePropertiesARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePerStageDescriptorSetFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageProcessing2FeaturesQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageProcessing2PropertiesQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSamplerBlockMatchWindowCreateInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCubicWeightsFeaturesQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSamplerCubicWeightsCreateInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBlitImageCubicWeightsInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCubicClampFeaturesQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceLayeredDriverPropertiesMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceTileMemoryHeapFeaturesQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceTileMemoryHeapPropertiesQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkTileMemoryRequirementsQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkTileMemoryBindInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkTileMemoryBindInfoQCOM* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkTileMemorySizeInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDecompressMemoryInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMemoryDecompressionFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMemoryDecompressionPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDisplaySurfaceStereoCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDisplayModeStereoPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRawAccessChainsFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCommandBufferInheritanceFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderFloat8FeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingValidationFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPartitionedAccelerationStructureFlagsNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkWriteDescriptorSetPartitionedAccelerationStructureNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPartitionedAccelerationStructureInstancesInputNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBuildPartitionedAccelerationStructureInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureBuildSizesInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkGeneratedCommandsMemoryRequirementsInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGeneratedCommandsMemoryRequirementsInfoEXT* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->indirectExecutionSet = handle_mapping::MapHandle<VulkanIndirectExecutionSetEXTInfo>(wrapper->indirectExecutionSet, object_info_table, &CommonObjectInfoTable::GetVkIndirectExecutionSetEXTInfo);

        value->indirectCommandsLayout = handle_mapping::MapHandle<VulkanIndirectCommandsLayoutEXTInfo>(wrapper->indirectCommandsLayout, object_info_table, &CommonObjectInfoTable::GetVkIndirectCommandsLayoutEXTInfo);
    }
}

void MapStructHandles(Decoded_VkIndirectExecutionSetPipelineInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkIndirectExecutionSetPipelineInfoEXT* value = wrapper->decoded_value;

        value->initialPipeline = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->initialPipeline, object_info_table, &CommonObjectInfoTable::GetVkPipelineInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkIndirectExecutionSetShaderLayoutInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkIndirectExecutionSetShaderLayoutInfoEXT* value = wrapper->decoded_value;

        value->pSetLayouts = handle_mapping::MapHandleArray<VulkanDescriptorSetLayoutInfo>(&wrapper->pSetLayouts, object_info_table, &CommonObjectInfoTable::GetVkDescriptorSetLayoutInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkIndirectExecutionSetShaderInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkIndirectExecutionSetShaderInfoEXT* value = wrapper->decoded_value;

        value->pInitialShaders = handle_mapping::MapHandleArray<VulkanShaderEXTInfo>(&wrapper->pInitialShaders, object_info_table, &CommonObjectInfoTable::GetVkShaderEXTInfo);

        MapStructArrayHandles<Decoded_VkIndirectExecutionSetShaderLayoutInfoEXT>(wrapper->pSetLayoutInfos->GetMetaStructPointer(), wrapper->pSetLayoutInfos->GetLength(), object_info_table);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkGeneratedCommandsInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGeneratedCommandsInfoEXT* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->indirectExecutionSet = handle_mapping::MapHandle<VulkanIndirectExecutionSetEXTInfo>(wrapper->indirectExecutionSet, object_info_table, &CommonObjectInfoTable::GetVkIndirectExecutionSetEXTInfo);

        value->indirectCommandsLayout = handle_mapping::MapHandle<VulkanIndirectCommandsLayoutEXTInfo>(wrapper->indirectCommandsLayout, object_info_table, &CommonObjectInfoTable::GetVkIndirectCommandsLayoutEXTInfo);
    }
}

void MapStructHandles(Decoded_VkWriteIndirectExecutionSetPipelineEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkWriteIndirectExecutionSetPipelineEXT* value = wrapper->decoded_value;

        value->pipeline = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->pipeline, object_info_table, &CommonObjectInfoTable::GetVkPipelineInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkIndirectCommandsLayoutCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkIndirectCommandsLayoutCreateInfoEXT* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        value->pipelineLayout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->pipelineLayout, object_info_table, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkGeneratedCommandsPipelineInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGeneratedCommandsPipelineInfoEXT* value = wrapper->decoded_value;

        value->pipeline = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->pipeline, object_info_table, &CommonObjectInfoTable::GetVkPipelineInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkGeneratedCommandsShaderInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGeneratedCommandsShaderInfoEXT* value = wrapper->decoded_value;

        value->pShaders = handle_mapping::MapHandleArray<VulkanShaderEXTInfo>(&wrapper->pShaders, object_info_table, &CommonObjectInfoTable::GetVkShaderEXTInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkWriteIndirectExecutionSetShaderEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkWriteIndirectExecutionSetShaderEXT* value = wrapper->decoded_value;

        value->shader = handle_mapping::MapHandle<VulkanShaderEXTInfo>(wrapper->shader, object_info_table, &CommonObjectInfoTable::GetVkShaderEXTInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageAlignmentControlFeaturesMESA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageAlignmentControlPropertiesMESA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageAlignmentControlCreateInfoMESA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPushConstantBankInfoNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePushConstantBankFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePushConstantBankPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDepthClampControlFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineViewportDepthClampControlCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceHdrVividFeaturesHUAWEI* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkHdrVividDynamicMetadataHUAWEI* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCooperativeMatrixFlexibleDimensionsPropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCooperativeMatrix2FeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCooperativeMatrix2PropertiesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePipelineOpacityMicromapFeaturesARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImportMemoryMetalHandleInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryMetalHandlePropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryGetMetalHandleInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryGetMetalHandleInfoEXT* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePerformanceCountersByRegionFeaturesARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePerformanceCountersByRegionPropertiesARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPerformanceCounterARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPerformanceCounterDescriptionARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassPerformanceCountersByRegionBeginInfoARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFormatPackFeaturesARM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineFragmentDensityMapLayeredCreateInfoVALVE* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSetPresentConfigNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePresentMeteringFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShader64BitIndexingFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCustomResolveFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBeginCustomResolveInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCustomResolveCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDataGraphPipelineBuiltinModelCreateInfoQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDataGraphModelFeaturesQCOM* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderLongVectorFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderLongVectorPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkComputeOccupancyPriorityParametersNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureGeometryTrianglesDataKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureGeometryAabbsDataKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureGeometryInstancesDataKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkAccelerationStructureCreateInfoKHR* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &CommonObjectInfoTable::GetVkBufferInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkWriteDescriptorSetAccelerationStructureKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkWriteDescriptorSetAccelerationStructureKHR* value = wrapper->decoded_value;

        value->pAccelerationStructures = handle_mapping::MapHandleArray<VulkanAccelerationStructureKHRInfo>(&wrapper->pAccelerationStructures, object_info_table, &CommonObjectInfoTable::GetVkAccelerationStructureKHRInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceAccelerationStructureFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceAccelerationStructurePropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureDeviceAddressInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkAccelerationStructureDeviceAddressInfoKHR* value = wrapper->decoded_value;

        value->accelerationStructure = handle_mapping::MapHandle<VulkanAccelerationStructureKHRInfo>(wrapper->accelerationStructure, object_info_table, &CommonObjectInfoTable::GetVkAccelerationStructureKHRInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureVersionInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCopyAccelerationStructureToMemoryInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyAccelerationStructureToMemoryInfoKHR* value = wrapper->decoded_value;

        value->src = handle_mapping::MapHandle<VulkanAccelerationStructureKHRInfo>(wrapper->src, object_info_table, &CommonObjectInfoTable::GetVkAccelerationStructureKHRInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCopyMemoryToAccelerationStructureInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyMemoryToAccelerationStructureInfoKHR* value = wrapper->decoded_value;

        value->dst = handle_mapping::MapHandle<VulkanAccelerationStructureKHRInfo>(wrapper->dst, object_info_table, &CommonObjectInfoTable::GetVkAccelerationStructureKHRInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCopyAccelerationStructureInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyAccelerationStructureInfoKHR* value = wrapper->decoded_value;

        value->src = handle_mapping::MapHandle<VulkanAccelerationStructureKHRInfo>(wrapper->src, object_info_table, &CommonObjectInfoTable::GetVkAccelerationStructureKHRInfo);

        value->dst = handle_mapping::MapHandle<VulkanAccelerationStructureKHRInfo>(wrapper->dst, object_info_table, &CommonObjectInfoTable::GetVkAccelerationStructureKHRInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRayTracingShaderGroupCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRayTracingPipelineInterfaceCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRayTracingPipelineCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkRayTracingPipelineCreateInfoKHR* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }

        MapStructArrayHandles<Decoded_VkPipelineShaderStageCreateInfo>(wrapper->pStages->GetMetaStructPointer(), wrapper->pStages->GetLength(), object_info_table);

        MapStructArrayHandles<Decoded_VkPipelineLibraryCreateInfoKHR>(wrapper->pLibraryInfo->GetMetaStructPointer(), 1, object_info_table);

        value->layout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->layout, object_info_table, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);

        value->basePipelineHandle = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->basePipelineHandle, object_info_table, &CommonObjectInfoTable::GetVkPipelineInfo);

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingPipelineFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingPipelinePropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRayQueryFeaturesKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMeshShaderFeaturesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMeshShaderPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext, object_info_table);
        }
    }
}

void MapPNextStructHandles(PNextNode* pnext, const CommonObjectInfoTable& object_info_table)
{
    while (pnext)
    {
        void *wrapper = pnext->GetMetaStructPointer();
        const auto* header = reinterpret_cast<const VulkanMetaStructHeader*>(pnext->GetMetaStructPointer());

        switch (*header->sType)
        {
        default:
            // TODO: Report or raise fatal error for unrecognized sType?
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureBuildGeometryInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureBuildSizesInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureCaptureDescriptorDataInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureDeviceAddressInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureGeometryAabbsDataKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureGeometryInstancesDataKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_LINEAR_SWEPT_SPHERES_DATA_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureGeometryLinearSweptSpheresDataNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureGeometryMotionTrianglesDataNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_SPHERES_DATA_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureGeometrySpheresDataNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureGeometryTrianglesDataKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureMotionInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureTrianglesDisplacementMicromapNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureVersionInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkAcquireNextImageInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkAcquireProfilingLockInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC:
            MapStructHandles(reinterpret_cast<Decoded_VkAmigoProfilingSubmitInfoSEC*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID:
            MapStructHandles(reinterpret_cast<Decoded_VkAndroidHardwareBufferFormatProperties2ANDROID*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
            MapStructHandles(reinterpret_cast<Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID:
            MapStructHandles(reinterpret_cast<Decoded_VkAndroidHardwareBufferFormatResolvePropertiesANDROID*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID:
            MapStructHandles(reinterpret_cast<Decoded_VkAndroidHardwareBufferPropertiesANDROID*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
            MapStructHandles(reinterpret_cast<Decoded_VkAndroidHardwareBufferUsageANDROID*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkAndroidSurfaceCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ANTI_LAG_DATA_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkAntiLagDataAMD*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ANTI_LAG_PRESENTATION_INFO_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkAntiLagPresentationInfoAMD*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_APPLICATION_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkApplicationInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2:
            MapStructHandles(reinterpret_cast<Decoded_VkAttachmentDescription2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
            MapStructHandles(reinterpret_cast<Decoded_VkAttachmentDescriptionStencilLayout*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_FEEDBACK_LOOP_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkAttachmentFeedbackLoopInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2:
            MapStructHandles(reinterpret_cast<Decoded_VkAttachmentReference2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
            MapStructHandles(reinterpret_cast<Decoded_VkAttachmentReferenceStencilLayout*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkAttachmentSampleCountInfoAMD*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BEGIN_CUSTOM_RESOLVE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkBeginCustomResolveInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkBindAccelerationStructureMemoryInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkBindBufferMemoryDeviceGroupInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkBindBufferMemoryInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BIND_DATA_GRAPH_PIPELINE_SESSION_MEMORY_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkBindDataGraphPipelineSessionMemoryInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_SETS_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkBindDescriptorSetsInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkBindImageMemoryDeviceGroupInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkBindImageMemoryInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkBindImageMemorySwapchainInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkBindImagePlaneMemoryInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS:
            MapStructHandles(reinterpret_cast<Decoded_VkBindMemoryStatus*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BIND_SPARSE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkBindSparseInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkBindVideoSessionMemoryInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkBlitImageCubicWeightsInfoQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2:
            MapStructHandles(reinterpret_cast<Decoded_VkBlitImageInfo2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkBufferCaptureDescriptorDataInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_COPY_2:
            MapStructHandles(reinterpret_cast<Decoded_VkBufferCopy2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkBufferCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkBufferDeviceAddressCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkBufferDeviceAddressInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2:
            MapStructHandles(reinterpret_cast<Decoded_VkBufferImageCopy2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER:
            MapStructHandles(reinterpret_cast<Decoded_VkBufferMemoryBarrier*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2:
            MapStructHandles(reinterpret_cast<Decoded_VkBufferMemoryBarrier2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2:
            MapStructHandles(reinterpret_cast<Decoded_VkBufferMemoryRequirementsInfo2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkBufferOpaqueCaptureAddressCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkBufferUsageFlags2CreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkBufferViewCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BUILD_PARTITIONED_ACCELERATION_STRUCTURE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkBuildPartitionedAccelerationStructureInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkCalibratedTimestampInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkCheckpointData2NV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkCheckpointDataNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkCommandBufferAllocateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkCommandBufferBeginInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkCommandBufferInheritanceInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkCommandBufferInheritanceRenderPassTransformInfoQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkCommandBufferInheritanceRenderingInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkCommandBufferInheritanceViewportScissorInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkCommandBufferSubmitInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkCommandPoolCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COMPUTE_OCCUPANCY_PRIORITY_PARAMETERS_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkComputeOccupancyPriorityParametersNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkComputePipelineCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkComputePipelineIndirectBufferInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkConditionalRenderingBeginInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_CONVERT_COOPERATIVE_VECTOR_MATRIX_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkConvertCooperativeVectorMatrixInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_FLEXIBLE_DIMENSIONS_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkCooperativeMatrixFlexibleDimensionsPropertiesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkCooperativeMatrixPropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkCooperativeMatrixPropertiesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COOPERATIVE_VECTOR_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkCooperativeVectorPropertiesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkCopyAccelerationStructureInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2:
            MapStructHandles(reinterpret_cast<Decoded_VkCopyBufferInfo2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2:
            MapStructHandles(reinterpret_cast<Decoded_VkCopyBufferToImageInfo2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkCopyCommandTransformInfoQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET:
            MapStructHandles(reinterpret_cast<Decoded_VkCopyDescriptorSet*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2:
            MapStructHandles(reinterpret_cast<Decoded_VkCopyImageInfo2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2:
            MapStructHandles(reinterpret_cast<Decoded_VkCopyImageToBufferInfo2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkCopyImageToImageInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COPY_MEMORY_INDIRECT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkCopyMemoryIndirectInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INDIRECT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkCopyMemoryToImageIndirectInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkCopyMemoryToMicromapInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkCopyMicromapInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkCopyMicromapToMemoryInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_CUSTOM_RESOLVE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkCustomResolveCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkD3D12FenceSubmitInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_BUILTIN_MODEL_CREATE_INFO_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkDataGraphPipelineBuiltinModelCreateInfoQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_COMPILER_CONTROL_CREATE_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkDataGraphPipelineCompilerControlCreateInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CONSTANT_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkDataGraphPipelineConstantARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CONSTANT_TENSOR_SEMI_STRUCTURED_SPARSITY_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CREATE_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkDataGraphPipelineCreateInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_DISPATCH_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkDataGraphPipelineDispatchInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_IDENTIFIER_CREATE_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkDataGraphPipelineIdentifierCreateInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkDataGraphPipelineInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_PROPERTY_QUERY_RESULT_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkDataGraphPipelinePropertyQueryResultARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkDataGraphPipelineResourceInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_REQUIREMENT_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkDataGraphPipelineSessionBindPointRequirementARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_REQUIREMENTS_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkDataGraphPipelineSessionBindPointRequirementsInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_CREATE_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkDataGraphPipelineSessionCreateInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_MEMORY_REQUIREMENTS_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkDataGraphPipelineSessionMemoryRequirementsInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SHADER_MODULE_CREATE_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkDataGraphPipelineShaderModuleCreateInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PROCESSING_ENGINE_CREATE_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkDataGraphProcessingEngineCreateInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDebugMarkerMarkerInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDebugMarkerObjectNameInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDebugMarkerObjectTagInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDebugReportCallbackCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDebugUtilsLabelEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDebugUtilsMessengerCallbackDataEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDebugUtilsMessengerCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDebugUtilsObjectNameInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDebugUtilsObjectTagInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DECOMPRESS_MEMORY_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDecompressMemoryInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkDedicatedAllocationBufferCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkDedicatedAllocationImageCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkDedicatedAllocationMemoryAllocateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEPENDENCY_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDependencyInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEPTH_BIAS_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDepthBiasInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDepthBiasRepresentationInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_ADDRESS_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDescriptorAddressInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDescriptorBufferBindingInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_PUSH_DESCRIPTOR_BUFFER_HANDLE_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDescriptorBufferBindingPushDescriptorBufferHandleEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDescriptorPoolCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDescriptorPoolInlineUniformBlockCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDescriptorSetAllocateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE:
            MapStructHandles(reinterpret_cast<Decoded_VkDescriptorSetBindingReferenceVALVE*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDescriptorSetLayoutCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE:
            MapStructHandles(reinterpret_cast<Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT:
            MapStructHandles(reinterpret_cast<Decoded_VkDescriptorSetLayoutSupport*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
            MapStructHandles(reinterpret_cast<Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupport*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDescriptorUpdateTemplateCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceAddressBindingCallbackDataEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceBufferMemoryRequirements*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceDeviceMemoryReportCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceDiagnosticsConfigCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceEventInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceFaultCountsEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceFaultInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceGroupBindSparseInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceGroupCommandBufferBeginInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceGroupDeviceCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceGroupPresentCapabilitiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceGroupPresentInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceGroupRenderPassBeginInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceGroupSubmitInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceGroupSwapchainCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceImageMemoryRequirements*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_IMAGE_SUBRESOURCE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceImageSubresourceInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceMemoryOverallocationCreateInfoAMD*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceMemoryReportCallbackDataEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_PIPELINE_BINARY_INTERNAL_CACHE_CONTROL_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkDevicePipelineBinaryInternalCacheControlKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDevicePrivateDataCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceQueueCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceQueueGlobalPriorityCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceQueueInfo2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceQueueShaderCoreControlCreateInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_INFO_LUNARG:
            MapStructHandles(reinterpret_cast<Decoded_VkDirectDriverLoadingInfoLUNARG*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG:
            MapStructHandles(reinterpret_cast<Decoded_VkDirectDriverLoadingListLUNARG*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDirectFBSurfaceCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DISPATCH_TILE_INFO_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkDispatchTileInfoQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDisplayEventInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkDisplayModeCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkDisplayModeProperties2KHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_STEREO_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkDisplayModeStereoPropertiesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkDisplayPlaneCapabilities2KHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkDisplayPlaneInfo2KHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkDisplayPlaneProperties2KHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDisplayPowerInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkDisplayPresentInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkDisplayProperties2KHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkDisplaySurfaceCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_STEREO_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkDisplaySurfaceStereoCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDrmFormatModifierPropertiesList2EXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDrmFormatModifierPropertiesListEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EVENT_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkEventCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkExportFenceCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkExportFenceWin32HandleInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkExportMemoryAllocateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkExportMemoryAllocateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkExportMemoryWin32HandleInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkExportMemoryWin32HandleInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkExportSemaphoreCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkExportSemaphoreWin32HandleInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkExternalBufferProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkExternalFenceProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
            MapStructHandles(reinterpret_cast<Decoded_VkExternalFormatANDROID*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkExternalImageFormatProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkExternalMemoryAcquireUnmodifiedEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkExternalMemoryBufferCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkExternalMemoryImageCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkExternalMemoryImageCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkExternalSemaphoreProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_FENCE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkFenceCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkFenceGetFdInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkFenceGetWin32HandleInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2:
            MapStructHandles(reinterpret_cast<Decoded_VkFormatProperties2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3:
            MapStructHandles(reinterpret_cast<Decoded_VkFormatProperties3*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkFragmentShadingRateAttachmentInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkFrameBoundaryEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkFramebufferAttachmentImageInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkFramebufferAttachmentsCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkFramebufferCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkFramebufferMixedSamplesCombinationNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkGeneratedCommandsInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkGeneratedCommandsInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkGeneratedCommandsMemoryRequirementsInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_PIPELINE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkGeneratedCommandsPipelineInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_SHADER_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkGeneratedCommandsShaderInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkGeometryAABBNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_GEOMETRY_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkGeometryNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkGeometryTrianglesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_GET_LATENCY_MARKER_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkGetLatencyMarkerInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkGraphicsPipelineCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkGraphicsPipelineLibraryCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkGraphicsShaderGroupCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_HDR_METADATA_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkHdrMetadataEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_HDR_VIVID_DYNAMIC_METADATA_HUAWEI:
            MapStructHandles(reinterpret_cast<Decoded_VkHdrVividDynamicMetadataHUAWEI*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkHeadlessSurfaceCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY:
            MapStructHandles(reinterpret_cast<Decoded_VkHostImageCopyDevicePerformanceQuery*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkHostImageLayoutTransitionInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK:
            MapStructHandles(reinterpret_cast<Decoded_VkIOSSurfaceCreateInfoMVK*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_ALIGNMENT_CONTROL_CREATE_INFO_MESA:
            MapStructHandles(reinterpret_cast<Decoded_VkImageAlignmentControlCreateInfoMESA*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_BLIT_2:
            MapStructHandles(reinterpret_cast<Decoded_VkImageBlit2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImageCaptureDescriptorDataInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImageCompressionControlEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImageCompressionPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_COPY_2:
            MapStructHandles(reinterpret_cast<Decoded_VkImageCopy2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkImageCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImageDrmFormatModifierListCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImageDrmFormatModifierPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkImageFormatListCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2:
            MapStructHandles(reinterpret_cast<Decoded_VkImageFormatProperties2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER:
            MapStructHandles(reinterpret_cast<Decoded_VkImageMemoryBarrier*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2:
            MapStructHandles(reinterpret_cast<Decoded_VkImageMemoryBarrier2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2:
            MapStructHandles(reinterpret_cast<Decoded_VkImageMemoryRequirementsInfo2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA:
            MapStructHandles(reinterpret_cast<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkImagePlaneMemoryRequirementsInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2:
            MapStructHandles(reinterpret_cast<Decoded_VkImageResolve2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2:
            MapStructHandles(reinterpret_cast<Decoded_VkImageSparseMemoryRequirementsInfo2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkImageStencilUsageCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2:
            MapStructHandles(reinterpret_cast<Decoded_VkImageSubresource2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkImageSwapchainCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImageViewASTCDecodeModeEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX:
            MapStructHandles(reinterpret_cast<Decoded_VkImageViewAddressPropertiesNVX*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImageViewCaptureDescriptorDataInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkImageViewCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX:
            MapStructHandles(reinterpret_cast<Decoded_VkImageViewHandleInfoNVX*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImageViewMinLodCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkImageViewSampleWeightCreateInfoQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImageViewSlicedCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkImageViewUsageCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            MapStructHandles(reinterpret_cast<Decoded_VkImportAndroidHardwareBufferInfoANDROID*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkImportFenceFdInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkImportFenceWin32HandleInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkImportMemoryFdInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImportMemoryHostPointerInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_METAL_HANDLE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImportMemoryMetalHandleInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkImportMemoryWin32HandleInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkImportMemoryWin32HandleInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA:
            MapStructHandles(reinterpret_cast<Decoded_VkImportMemoryZirconHandleInfoFUCHSIA*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkImportSemaphoreFdInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkImportSemaphoreWin32HandleInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA:
            MapStructHandles(reinterpret_cast<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkIndirectCommandsLayoutCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkIndirectCommandsLayoutCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkIndirectCommandsLayoutTokenNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_PIPELINE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkIndirectExecutionSetPipelineInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkIndirectExecutionSetShaderInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_LAYOUT_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkIndirectExecutionSetShaderLayoutInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL:
            MapStructHandles(reinterpret_cast<Decoded_VkInitializePerformanceApiInfoINTEL*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkInstanceCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_LATENCY_SLEEP_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkLatencySleepInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_LATENCY_SLEEP_MODE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkLatencySleepModeInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkLatencySubmissionPresentIdNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkLatencySurfaceCapabilitiesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_LATENCY_TIMINGS_FRAME_REPORT_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkLatencyTimingsFrameReportNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkLayerSettingsCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK:
            MapStructHandles(reinterpret_cast<Decoded_VkMacOSSurfaceCreateInfoMVK*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE:
            MapStructHandles(reinterpret_cast<Decoded_VkMappedMemoryRange*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryAllocateFlagsInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryAllocateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryBarrier*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryBarrier2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryBarrierAccessFlags3KHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryDedicatedAllocateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryDedicatedRequirements*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryFdPropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryGetFdInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_METAL_HANDLE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryGetMetalHandleInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryGetRemoteAddressInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryGetWin32HandleInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryGetZirconHandleInfoFUCHSIA*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryHostPointerPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_MAP_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryMapInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryMapPlacedInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_METAL_HANDLE_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryMetalHandlePropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryPriorityAllocateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryRequirements2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_UNMAP_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryUnmapInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryWin32HandlePropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryZirconHandlePropertiesFUCHSIA*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkMetalSurfaceCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkMicromapBuildInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkMicromapBuildSizesInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkMicromapCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MICROMAP_VERSION_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkMicromapVersionInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkMultisamplePropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkMultisampledRenderToSingleSampledInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX:
            MapStructHandles(reinterpret_cast<Decoded_VkMultiviewPerViewAttributesInfoNVX*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkMutableDescriptorTypeCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_OPAQUE_CAPTURE_DESCRIPTOR_DATA_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkOpaqueCaptureDescriptorDataCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_EXECUTE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkOpticalFlowExecuteInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkOpticalFlowImageFormatInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkOpticalFlowImageFormatPropertiesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkOpticalFlowSessionCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkOpticalFlowSessionCreatePrivateDataInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_OUT_OF_BAND_QUEUE_TYPE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkOutOfBandQueueTypeInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_FLAGS_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPartitionedAccelerationStructureFlagsNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_INSTANCES_INPUT_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPartitionedAccelerationStructureInstancesInputNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPastPresentationTimingEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPastPresentationTimingInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPastPresentationTimingPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PER_TILE_BEGIN_INFO_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPerTileBeginInfoQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PER_TILE_END_INFO_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPerTileEndInfoQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL:
            MapStructHandles(reinterpret_cast<Decoded_VkPerformanceConfigurationAcquireInfoINTEL*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkPerformanceCounterARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkPerformanceCounterDescriptionARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPerformanceCounterDescriptionKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPerformanceCounterKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL:
            MapStructHandles(reinterpret_cast<Decoded_VkPerformanceMarkerInfoINTEL*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL:
            MapStructHandles(reinterpret_cast<Decoded_VkPerformanceOverrideInfoINTEL*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPerformanceQuerySubmitInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL:
            MapStructHandles(reinterpret_cast<Decoded_VkPerformanceStreamMarkerInfoINTEL*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevice16BitStorageFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevice4444FormatsFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevice8BitStorageFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceAccelerationStructurePropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ANTI_LAG_FEATURES_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceAntiLagFeaturesAMD*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMMAND_BUFFER_INHERITANCE_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCommandBufferInheritanceFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_OCCUPANCY_PRIORITY_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrix2FeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrix2PropertiesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeVectorFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeVectorPropertiesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCubicClampFeaturesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCubicWeightsFeaturesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCustomBorderColorPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_RESOLVE_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCustomResolveFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_FEATURES_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDataGraphFeaturesARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_MODEL_FEATURES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDataGraphModelFeaturesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_CONTROL_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDepthClampControlFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDepthClipControlFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDepthStencilResolveProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_DENSITY_MAP_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorBufferFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorBufferPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorIndexingFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorIndexingProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDisplacementMicromapFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDisplacementMicromapPropertiesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDriverProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDrmPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDynamicRenderingFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDynamicRenderingLocalReadFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExternalBufferInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExternalFenceInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExternalImageFormatInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExternalSemaphoreInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFaultFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFeatures2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFloatControlsProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FORMAT_PACK_FEATURES_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFormatPackFeaturesARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_FEATURES_VALVE:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_PROPERTIES_VALVE:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShadingRateKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShadingRatePropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFrameBoundaryFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceGlobalPriorityQueryFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceGroupProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HDR_VIVID_FEATURES_HUAWEI:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceHdrVividFeaturesHUAWEI*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceHostImageCopyFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceHostImageCopyProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceHostQueryResetFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceIDProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_FEATURES_MESA:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImageAlignmentControlFeaturesMESA*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_PROPERTIES_MESA:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImageAlignmentControlPropertiesMESA*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImageFormatInfo2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImageProcessing2FeaturesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImageProcessing2PropertiesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImageProcessingFeaturesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImageProcessingPropertiesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImageRobustnessFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImagelessFramebufferFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceIndexTypeUint8Features*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceInlineUniformBlockFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceInlineUniformBlockProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INTERNALLY_SYNCHRONIZED_QUEUES_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceLayeredApiPropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_LIST_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceLayeredApiPropertiesListKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_VULKAN_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceLayeredApiVulkanPropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceLayeredDriverPropertiesMSFT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceLineRasterizationFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceLineRasterizationProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance10FeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance10PropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance3Properties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance4Features*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance4Properties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance5Features*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance5Properties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance6Features*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance6Properties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance7FeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance7PropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance8FeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance9FeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance9PropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMapMemoryPlacedPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMemoryDecompressionFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMemoryDecompressionPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMemoryProperties2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMeshShaderFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMeshShaderFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMeshShaderPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMeshShaderPropertiesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMultiDrawFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMultiDrawPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceNestedCommandBufferFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceNestedCommandBufferPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceOpacityMicromapPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceOpticalFlowFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceOpticalFlowPropertiesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePerStageDescriptorSetFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_FEATURES_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePerformanceCountersByRegionFeaturesARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_PROPERTIES_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePerformanceCountersByRegionPropertiesARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePerformanceQueryFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePerformanceQueryPropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePipelineBinaryFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePipelineBinaryPropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CACHE_INCREMENTAL_MODE_FEATURES_SEC:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePipelineCreationCacheControlFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_OPACITY_MICROMAP_FEATURES_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePipelineOpacityMicromapFeaturesARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePipelineProtectedAccessFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePipelineRobustnessFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePipelineRobustnessProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePointClippingProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePortabilitySubsetPropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePresentBarrierFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_2_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePresentId2FeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePresentIdFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_METERING_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePresentMeteringFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_TIMING_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePresentTimingFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_2_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePresentWait2FeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePresentWaitFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePrivateDataFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceProperties2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceProtectedMemoryFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceProtectedMemoryProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceProvokingVertexFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceProvokingVertexPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_CONSTANT_BANK_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePushConstantBankFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_CONSTANT_BANK_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePushConstantBankPropertiesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePushDescriptorProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRawAccessChainsFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRayQueryFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_LINEAR_SWEPT_SPHERES_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingPipelinePropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingPropertiesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingValidationFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRenderPassStripedFeaturesARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRenderPassStripedPropertiesARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRobustness2FeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRobustness2PropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSamplerFilterMinmaxProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSchedulingControlsFeaturesARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSchedulingControlsPropertiesARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_64_BIT_INDEXING_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShader64BitIndexingFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderAtomicInt64Features*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_BFLOAT16_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderBfloat16FeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderClockFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderCoreProperties2AMD*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderCorePropertiesAMD*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderCorePropertiesARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderDrawParametersFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderExpectAssumeFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderFloat16Int8Features*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT8_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderFloat8FeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderFloatControls2Features*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FMA_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderFmaFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderIntegerDotProductFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderIntegerDotProductProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_LONG_VECTOR_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderLongVectorFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_LONG_VECTOR_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderLongVectorPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderObjectFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderObjectPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderQuadControlFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_RELAXED_EXTENDED_INSTRUCTION_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_REPLICATED_COMPOSITES_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_PARTITIONED_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderSubgroupRotateFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderTerminateInvocationFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderTileImageFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderTileImagePropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNIFORM_BUFFER_UNSIZED_ARRAY_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNTYPED_POINTERS_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSparseImageFormatInfo2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSubgroupProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSubgroupSizeControlFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSubgroupSizeControlProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSurfaceInfo2KHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSynchronization2Features*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceTexelBufferAlignmentProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_3D_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_FEATURES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceTileMemoryHeapFeaturesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_PROPERTIES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceTileMemoryHeapPropertiesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_FEATURES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceTileShadingFeaturesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_PROPERTIES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceTileShadingPropertiesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceTimelineSemaphoreProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceToolProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFIED_IMAGE_LAYOUTS_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVariablePointersFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVertexAttributeDivisorFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVertexAttributeDivisorProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_ROBUSTNESS_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_DECODE_VP9_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVideoDecodeVP9FeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_AV1_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVideoEncodeAV1FeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_INTRA_REFRESH_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUANTIZATION_MAP_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_RGB_CONVERSION_FEATURES_VALVE:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVideoFormatInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVideoMaintenance1FeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVulkan11Features*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVulkan11Properties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVulkan12Features*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVulkan12Properties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVulkan13Features*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVulkan13Properties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVulkan14Features*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVulkan14Properties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_DEVICE_MEMORY_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineBinaryCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_DATA_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineBinaryDataInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_HANDLES_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineBinaryHandlesInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineBinaryInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_KEY_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineBinaryKeyKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineCacheCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineColorBlendStateCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineColorWriteCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineCompilerControlCreateInfoAMD*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineCoverageModulationStateCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineCoverageReductionStateCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineCoverageToColorStateCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineCreateFlags2CreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineCreationFeedbackCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineDepthStencilStateCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineDynamicStateCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineExecutableInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineExecutableInternalRepresentationKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineExecutablePropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineExecutableStatisticKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_DENSITY_MAP_LAYERED_CREATE_INFO_VALVE:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineFragmentDensityMapLayeredCreateInfoVALVE*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineFragmentShadingRateEnumStateCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineFragmentShadingRateStateCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineIndirectDeviceAddressInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineInputAssemblyStateCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineLayoutCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineLibraryCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineMultisampleStateCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineRasterizationLineStateCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineRasterizationStateCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineRasterizationStateRasterizationOrderAMD*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineRenderingCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineRobustnessCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineSampleLocationsStateCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineShaderStageCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineShaderStageModuleIdentifierCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineTessellationDomainOriginStateCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineTessellationStateCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineVertexInputDivisorStateCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineVertexInputStateCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLAMP_CONTROL_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineViewportDepthClampControlCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineViewportDepthClipControlCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineViewportStateCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineViewportSwizzleStateCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineViewportWScalingStateCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
            MapStructHandles(reinterpret_cast<Decoded_VkPresentFrameTokenGGP*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_ID_2_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPresentId2KHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_ID_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPresentIdKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPresentInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPresentRegionsKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
            MapStructHandles(reinterpret_cast<Decoded_VkPresentTimesInfoGOOGLE*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMING_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPresentTimingInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMING_SURFACE_CAPABILITIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPresentTimingSurfaceCapabilitiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMINGS_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPresentTimingsInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_WAIT_2_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPresentWait2InfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPrivateDataSlotCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkProtectedSubmitInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PUSH_CONSTANT_BANK_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPushConstantBankInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PUSH_CONSTANTS_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPushConstantsInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPushDescriptorSetInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkQueryLowLatencySupportNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkQueryPoolCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkQueryPoolPerformanceCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL:
            MapStructHandles(reinterpret_cast<Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkQueueFamilyCheckpointProperties2NV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkQueueFamilyCheckpointPropertiesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_PROPERTIES_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkQueueFamilyDataGraphProcessingEnginePropertiesARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROPERTIES_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkQueueFamilyDataGraphPropertiesARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkQueueFamilyGlobalPriorityProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_OWNERSHIP_TRANSFER_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkQueueFamilyOwnershipTransferPropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2:
            MapStructHandles(reinterpret_cast<Decoded_VkQueueFamilyProperties2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkQueueFamilyQueryResultStatusPropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkQueueFamilyVideoPropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkRayTracingPipelineCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkRayTracingPipelineCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkRayTracingPipelineInterfaceCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkRayTracingShaderGroupCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkRayTracingShaderGroupCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RELEASE_CAPTURED_PIPELINE_DATA_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkReleaseCapturedPipelineDataInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkReleaseSwapchainImagesInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassAttachmentBeginInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassBeginInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassCreateInfo2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassCreationControlEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassCreationFeedbackCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassFragmentDensityMapOffsetEndInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassInputAttachmentAspectCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassMultiviewCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_PERFORMANCE_COUNTERS_BY_REGION_BEGIN_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassPerformanceCountersByRegionBeginInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassSampleLocationsBeginInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassStripeBeginInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassStripeInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassStripeSubmitInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassSubpassFeedbackCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_TILE_SHADING_CREATE_INFO_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassTileShadingCreateInfoQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassTransformBeginInfoQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_AREA_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderingAreaInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_FLAGS_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderingAttachmentFlagsInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderingAttachmentInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderingAttachmentLocationInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_END_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderingEndInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderingInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderingInputAttachmentIndexInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2:
            MapStructHandles(reinterpret_cast<Decoded_VkResolveImageInfo2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RESOLVE_IMAGE_MODE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkResolveImageModeInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkSampleLocationsInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkSamplerBlockMatchWindowCreateInfoQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkSamplerBorderColorComponentMappingCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkSamplerCaptureDescriptorDataInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkSamplerCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkSamplerCubicWeightsCreateInfoQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkSamplerCustomBorderColorCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkSamplerReductionModeCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkSamplerYcbcrConversionCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
            MapStructHandles(reinterpret_cast<Decoded_VkSamplerYcbcrConversionImageFormatProperties*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkSamplerYcbcrConversionInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SCREEN_SURFACE_CREATE_INFO_QNX:
            MapStructHandles(reinterpret_cast<Decoded_VkScreenSurfaceCreateInfoQNX*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkSemaphoreCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkSemaphoreGetFdInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkSemaphoreGetWin32HandleInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA:
            MapStructHandles(reinterpret_cast<Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkSemaphoreSignalInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkSemaphoreSubmitInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkSemaphoreTypeCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkSemaphoreWaitInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SET_DESCRIPTOR_BUFFER_OFFSETS_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkSetDescriptorBufferOffsetsInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SET_LATENCY_MARKER_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkSetLatencyMarkerInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SET_PRESENT_CONFIG_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkSetPresentConfigNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkShaderCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkShaderModuleCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkShaderModuleIdentifierEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkShaderModuleValidationCacheCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkSharedPresentSurfaceCapabilitiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2:
            MapStructHandles(reinterpret_cast<Decoded_VkSparseImageFormatProperties2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2:
            MapStructHandles(reinterpret_cast<Decoded_VkSparseImageMemoryRequirements2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP:
            MapStructHandles(reinterpret_cast<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SUBMIT_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkSubmitInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SUBMIT_INFO_2:
            MapStructHandles(reinterpret_cast<Decoded_VkSubmitInfo2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkSubpassBeginInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2:
            MapStructHandles(reinterpret_cast<Decoded_VkSubpassDependency2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2:
            MapStructHandles(reinterpret_cast<Decoded_VkSubpassDescription2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
            MapStructHandles(reinterpret_cast<Decoded_VkSubpassDescriptionDepthStencilResolve*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_END_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkSubpassEndInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkSubpassResolvePerformanceQueryEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE:
            MapStructHandles(reinterpret_cast<Decoded_VkSubresourceHostMemcpySize*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2:
            MapStructHandles(reinterpret_cast<Decoded_VkSubresourceLayout2*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkSurfaceCapabilities2EXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkSurfaceCapabilities2KHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkSurfaceCapabilitiesFullScreenExclusiveEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkSurfaceCapabilitiesPresentBarrierNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_ID_2_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkSurfaceCapabilitiesPresentId2KHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_WAIT_2_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkSurfaceCapabilitiesPresentWait2KHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkSurfaceFormat2KHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkSurfaceFullScreenExclusiveInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkSurfaceFullScreenExclusiveWin32InfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkSurfacePresentModeCompatibilityKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkSurfacePresentModeKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkSurfacePresentScalingCapabilitiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkSurfaceProtectedCapabilitiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_CALIBRATED_TIMESTAMP_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkSwapchainCalibratedTimestampInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkSwapchainCounterCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkSwapchainCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkSwapchainDisplayNativeHdrCreateInfoAMD*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkSwapchainLatencyCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkSwapchainPresentBarrierCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkSwapchainPresentFenceInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkSwapchainPresentModeInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkSwapchainPresentModesCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkSwapchainPresentScalingCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_TIME_DOMAIN_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkSwapchainTimeDomainPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_TIMING_PROPERTIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkSwapchainTimingPropertiesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkTextureLODGatherFormatPropertiesAMD*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_TILE_MEMORY_BIND_INFO_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkTileMemoryBindInfoQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_TILE_MEMORY_REQUIREMENTS_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkTileMemoryRequirementsQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_TILE_MEMORY_SIZE_INFO_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkTileMemorySizeInfoQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkTilePropertiesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkTimelineSemaphoreSubmitInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkValidationCacheCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkValidationFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkValidationFlagsEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkVertexInputAttributeDescription2EXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkVertexInputBindingDescription2EXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN:
            MapStructHandles(reinterpret_cast<Decoded_VkViSurfaceCreateInfoNN*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoBeginCodingInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoCapabilitiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoCodingControlInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoDecodeAV1CapabilitiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoDecodeAV1DpbSlotInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoDecodeAV1PictureInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoDecodeAV1ProfileInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoDecodeAV1SessionParametersCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoDecodeCapabilitiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoDecodeH264CapabilitiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoDecodeH264DpbSlotInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoDecodeH264PictureInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoDecodeH264ProfileInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoDecodeH264SessionParametersAddInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoDecodeH264SessionParametersCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoDecodeInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoDecodeUsageInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_CAPABILITIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoDecodeVP9CapabilitiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PICTURE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoDecodeVP9PictureInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PROFILE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoDecodeVP9ProfileInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_CAPABILITIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeAV1CapabilitiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeAV1DpbSlotInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_GOP_REMAINING_FRAME_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeAV1GopRemainingFrameInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PICTURE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeAV1PictureInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PROFILE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeAV1ProfileInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUALITY_LEVEL_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeAV1QualityLevelPropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUANTIZATION_MAP_CAPABILITIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeAV1QuantizationMapCapabilitiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeAV1RateControlInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_LAYER_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeAV1RateControlLayerInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeAV1SessionCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeAV1SessionParametersCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeCapabilitiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeH264CapabilitiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeH264DpbSlotInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeH264GopRemainingFrameInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeH264NaluSliceInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeH264PictureInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeH264ProfileInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeH264QualityLevelPropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUANTIZATION_MAP_CAPABILITIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeH264QuantizationMapCapabilitiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeH264RateControlInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeH264RateControlLayerInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeH264SessionCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeH264SessionParametersAddInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeH264SessionParametersCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeH264SessionParametersFeedbackInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeH264SessionParametersGetInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUANTIZATION_MAP_CAPABILITIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeH265QuantizationMapCapabilitiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_CAPABILITIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeIntraRefreshCapabilitiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeIntraRefreshInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_PROFILE_RGB_CONVERSION_INFO_VALVE:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeProfileRgbConversionInfoVALVE*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeQualityLevelInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeQualityLevelPropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_CAPABILITIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeQuantizationMapCapabilitiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeQuantizationMapInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_SESSION_PARAMETERS_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeRateControlInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeRateControlLayerInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RGB_CONVERSION_CAPABILITIES_VALVE:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeRgbConversionCapabilitiesVALVE*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_INTRA_REFRESH_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeSessionIntraRefreshCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeSessionParametersFeedbackInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeSessionParametersGetInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_RGB_CONVERSION_CREATE_INFO_VALVE:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeSessionRgbConversionCreateInfoVALVE*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeUsageInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEndCodingInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_AV1_QUANTIZATION_MAP_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoFormatAV1QuantizationMapPropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_H265_QUANTIZATION_MAP_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoFormatH265QuantizationMapPropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoFormatPropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_QUANTIZATION_MAP_PROPERTIES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoFormatQuantizationMapPropertiesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoInlineQueryInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoPictureResourceInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoProfileInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoProfileListInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_INTRA_REFRESH_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoReferenceIntraRefreshInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoReferenceSlotInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoSessionCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoSessionMemoryRequirementsKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoSessionParametersCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoSessionParametersUpdateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkWaylandSurfaceCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkWin32SurfaceCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkWriteDescriptorSetAccelerationStructureKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkWriteDescriptorSetAccelerationStructureNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK:
            MapStructHandles(reinterpret_cast<Decoded_VkWriteDescriptorSetInlineUniformBlock*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_PARTITIONED_ACCELERATION_STRUCTURE_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkWriteDescriptorSetPartitionedAccelerationStructureNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_PIPELINE_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkWriteIndirectExecutionSetPipelineEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_SHADER_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkWriteIndirectExecutionSetShaderEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkXcbSurfaceCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkXlibSurfaceCreateInfoKHR*>(wrapper), object_info_table);
            break;
        }
        pnext = header->pNext;
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_VkPhysicalDeviceGroupProperties* id_wrapper, const VkPhysicalDeviceGroupProperties* handle_struct, CommonObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        handle_mapping::AddHandleArray<VulkanPhysicalDeviceInfo>(parent_id, id_wrapper->physicalDevices.GetPointer(), id_wrapper->physicalDevices.GetLength(), handle_struct->physicalDevices, handle_struct->physicalDeviceCount, object_info_table, &CommonObjectInfoTable::AddVkPhysicalDeviceInfo);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayPropertiesKHR* id_wrapper, const VkDisplayPropertiesKHR* handle_struct, CommonObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        handle_mapping::AddHandle<VulkanDisplayKHRInfo>(parent_id, id_wrapper->display, handle_struct->display, object_info_table, &CommonObjectInfoTable::AddVkDisplayKHRInfo);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayPlanePropertiesKHR* id_wrapper, const VkDisplayPlanePropertiesKHR* handle_struct, CommonObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        handle_mapping::AddHandle<VulkanDisplayKHRInfo>(parent_id, id_wrapper->currentDisplay, handle_struct->currentDisplay, object_info_table, &CommonObjectInfoTable::AddVkDisplayKHRInfo);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayModePropertiesKHR* id_wrapper, const VkDisplayModePropertiesKHR* handle_struct, CommonObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        handle_mapping::AddHandle<VulkanDisplayModeKHRInfo>(parent_id, id_wrapper->displayMode, handle_struct->displayMode, object_info_table, &CommonObjectInfoTable::AddVkDisplayModeKHRInfo);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayProperties2KHR* id_wrapper, const VkDisplayProperties2KHR* handle_struct, CommonObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        AddStructHandles(parent_id, id_wrapper->displayProperties, &handle_struct->displayProperties, object_info_table);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayPlaneProperties2KHR* id_wrapper, const VkDisplayPlaneProperties2KHR* handle_struct, CommonObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        AddStructHandles(parent_id, id_wrapper->displayPlaneProperties, &handle_struct->displayPlaneProperties, object_info_table);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayModeProperties2KHR* id_wrapper, const VkDisplayModeProperties2KHR* handle_struct, CommonObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        AddStructHandles(parent_id, id_wrapper->displayModeProperties, &handle_struct->displayModeProperties, object_info_table);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_VkPipelineBinaryHandlesInfoKHR* id_wrapper, const VkPipelineBinaryHandlesInfoKHR* handle_struct, CommonObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        handle_mapping::AddHandleArray<VulkanPipelineBinaryKHRInfo>(parent_id, id_wrapper->pPipelineBinaries.GetPointer(), id_wrapper->pPipelineBinaries.GetLength(), handle_struct->pPipelineBinaries, handle_struct->pipelineBinaryCount, object_info_table, &CommonObjectInfoTable::AddVkPipelineBinaryKHRInfo);
    }
}

void PushRecaptureStructHandleIds(const Decoded_VkPhysicalDeviceGroupProperties* id_wrapper, CommonConsumerBase* consumer)
{
    GFXRECON_ASSERT(consumer != nullptr);
    if (consumer->IsRecapture() && id_wrapper != nullptr)
    {
        consumer->PushRecaptureHandleIds(id_wrapper->physicalDevices.GetPointer(), id_wrapper->physicalDevices.GetLength());
    }
}

void PushRecaptureStructHandleIds(const Decoded_VkDisplayPropertiesKHR* id_wrapper, CommonConsumerBase* consumer)
{
    GFXRECON_ASSERT(consumer != nullptr);
    if (consumer->IsRecapture() && id_wrapper != nullptr)
    {
        consumer->PushRecaptureHandleId(&id_wrapper->display);
    }
}

void PushRecaptureStructHandleIds(const Decoded_VkDisplayPlanePropertiesKHR* id_wrapper, CommonConsumerBase* consumer)
{
    GFXRECON_ASSERT(consumer != nullptr);
    if (consumer->IsRecapture() && id_wrapper != nullptr)
    {
        consumer->PushRecaptureHandleId(&id_wrapper->currentDisplay);
    }
}

void PushRecaptureStructHandleIds(const Decoded_VkDisplayModePropertiesKHR* id_wrapper, CommonConsumerBase* consumer)
{
    GFXRECON_ASSERT(consumer != nullptr);
    if (consumer->IsRecapture() && id_wrapper != nullptr)
    {
        consumer->PushRecaptureHandleId(&id_wrapper->displayMode);
    }
}

void PushRecaptureStructHandleIds(const Decoded_VkDisplayProperties2KHR* id_wrapper, CommonConsumerBase* consumer)
{
    GFXRECON_ASSERT(consumer != nullptr);
    if (consumer->IsRecapture() && id_wrapper != nullptr)
    {
        PushRecaptureStructHandleIds(id_wrapper->displayProperties, consumer);
    }
}

void PushRecaptureStructHandleIds(const Decoded_VkDisplayPlaneProperties2KHR* id_wrapper, CommonConsumerBase* consumer)
{
    GFXRECON_ASSERT(consumer != nullptr);
    if (consumer->IsRecapture() && id_wrapper != nullptr)
    {
        PushRecaptureStructHandleIds(id_wrapper->displayPlaneProperties, consumer);
    }
}

void PushRecaptureStructHandleIds(const Decoded_VkDisplayModeProperties2KHR* id_wrapper, CommonConsumerBase* consumer)
{
    GFXRECON_ASSERT(consumer != nullptr);
    if (consumer->IsRecapture() && id_wrapper != nullptr)
    {
        PushRecaptureStructHandleIds(id_wrapper->displayModeProperties, consumer);
    }
}

void PushRecaptureStructHandleIds(const Decoded_VkPipelineBinaryHandlesInfoKHR* id_wrapper, CommonConsumerBase* consumer)
{
    GFXRECON_ASSERT(consumer != nullptr);
    if (consumer->IsRecapture() && id_wrapper != nullptr)
    {
        consumer->PushRecaptureHandleIds(id_wrapper->pPipelineBinaries.GetPointer(), id_wrapper->pPipelineBinaries.GetLength());
    }
}

void SetStructHandleLengths(Decoded_VkPhysicalDeviceGroupProperties* wrapper)
{
    if (wrapper != nullptr)
    {
        wrapper->physicalDevices.SetHandleLength(wrapper->physicalDevices.GetLength());
    }
}

void SetStructHandleLengths(Decoded_VkPipelineBinaryHandlesInfoKHR* wrapper)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineBinaryHandlesInfoKHR* value = wrapper->decoded_value;

        wrapper->pPipelineBinaries.SetHandleLength(wrapper->pPipelineBinaries.GetLength());
        value->pPipelineBinaries = wrapper->pPipelineBinaries.GetHandlePointer();
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
