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

#include "generated/generated_vulkan_struct_handle_wrappers.h"

#include "vulkan/vk_layer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)
GFXRECON_BEGIN_NAMESPACE(vulkan_wrappers)

void UnwrapStructHandles(VkBufferMemoryBarrier* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageMemoryBarrier* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryBarrier* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkApplicationInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkInstanceCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pApplicationInfo = UnwrapStructPtrHandles(value->pApplicationInfo, unwrap_memory);
    }
}

void UnwrapStructHandles(VkDeviceQueueCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pQueueCreateInfos = UnwrapStructArrayHandles(value->pQueueCreateInfos, value->queueCreateInfoCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkSubmitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMappedMemoryRange* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSparseMemoryBind* value, HandleUnwrapMemory* unwrap_memory)
{
}

void UnwrapStructHandles(VkSparseBufferMemoryBindInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pBinds = UnwrapStructArrayHandles(value->pBinds, value->bindCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkSparseImageOpaqueMemoryBindInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pBinds = UnwrapStructArrayHandles(value->pBinds, value->bindCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkSparseImageMemoryBind* value, HandleUnwrapMemory* unwrap_memory)
{
}

void UnwrapStructHandles(VkSparseImageMemoryBindInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pBinds = UnwrapStructArrayHandles(value->pBinds, value->bindCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkBindSparseInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pBufferBinds = UnwrapStructArrayHandles(value->pBufferBinds, value->bufferBindCount, unwrap_memory);
        value->pImageOpaqueBinds = UnwrapStructArrayHandles(value->pImageOpaqueBinds, value->imageOpaqueBindCount, unwrap_memory);
        value->pImageBinds = UnwrapStructArrayHandles(value->pImageBinds, value->imageBindCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkFenceCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSemaphoreCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkQueryPoolCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBufferCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageViewCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCommandPoolCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCommandBufferAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCommandBufferInheritanceInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCommandBufferBeginInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pInheritanceInfo = UnwrapStructPtrHandles(value->pInheritanceInfo, unwrap_memory);
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pInheritanceInfo = UnwrapStructPtrHandles(value->pInheritanceInfo, unwrap_memory);
    }
}

void UnwrapStructHandles(VkEventCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBufferViewCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkShaderModuleCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineCacheCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineShaderStageCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkComputePipelineCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        UnwrapStructHandles(&value->stage, unwrap_memory);
        UnwrapStructHandles(&value->stage, unwrap_memory);
    }
}

void UnwrapStructHandles(VkPipelineLayoutCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSamplerCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCopyDescriptorSet* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDescriptorBufferInfo* value, HandleUnwrapMemory* unwrap_memory)
{
}

void UnwrapStructHandles(VkDescriptorPoolCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDescriptorSetAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDescriptorSetLayoutBinding* value, HandleUnwrapMemory* unwrap_memory)
{
}

void UnwrapStructHandles(VkDescriptorSetLayoutCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pBindings = UnwrapStructArrayHandles(value->pBindings, value->bindingCount, unwrap_memory);
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineVertexInputStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineInputAssemblyStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineTessellationStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineViewportStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineRasterizationStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineMultisampleStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineDepthStencilStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineColorBlendStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineDynamicStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkGraphicsPipelineCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pStages = UnwrapStructArrayHandles(value->pStages, value->stageCount, unwrap_memory);
        value->pStages = UnwrapStructArrayHandles(value->pStages, value->stageCount, unwrap_memory);
        value->pVertexInputState = UnwrapStructPtrHandles(value->pVertexInputState, unwrap_memory);
        value->pInputAssemblyState = UnwrapStructPtrHandles(value->pInputAssemblyState, unwrap_memory);
        value->pTessellationState = UnwrapStructPtrHandles(value->pTessellationState, unwrap_memory);
        value->pViewportState = UnwrapStructPtrHandles(value->pViewportState, unwrap_memory);
        value->pRasterizationState = UnwrapStructPtrHandles(value->pRasterizationState, unwrap_memory);
        value->pMultisampleState = UnwrapStructPtrHandles(value->pMultisampleState, unwrap_memory);
        value->pDepthStencilState = UnwrapStructPtrHandles(value->pDepthStencilState, unwrap_memory);
        value->pColorBlendState = UnwrapStructPtrHandles(value->pColorBlendState, unwrap_memory);
        value->pDynamicState = UnwrapStructPtrHandles(value->pDynamicState, unwrap_memory);
    }
}

void UnwrapStructHandles(VkFramebufferCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderPassCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderPassBeginInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBindBufferMemoryInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBindImageMemoryInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryDedicatedRequirements* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryDedicatedAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryAllocateFlagsInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceGroupCommandBufferBeginInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceGroupSubmitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceGroupBindSparseInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBindBufferMemoryDeviceGroupInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBindImageMemoryDeviceGroupInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceGroupProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceGroupDeviceCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBufferMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageSparseMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryRequirements2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSparseImageMemoryRequirements2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceFeatures2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceProperties2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkFormatProperties2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageFormatProperties2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceImageFormatInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkQueueFamilyProperties2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMemoryProperties2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSparseImageFormatProperties2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceSparseImageFormatInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageViewUsageCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceProtectedMemoryFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceProtectedMemoryProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceQueueInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkProtectedSubmitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBindImagePlaneMemoryInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImagePlaneMemoryRequirementsInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceExternalImageFormatInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkExternalImageFormatProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceExternalBufferInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkExternalBufferProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceIDProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkExternalMemoryImageCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkExternalMemoryBufferCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkExportMemoryAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceExternalFenceInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkExternalFenceProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkExportFenceCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkExportSemaphoreCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceExternalSemaphoreInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkExternalSemaphoreProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceSubgroupProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevice16BitStorageFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVariablePointersFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDescriptorUpdateTemplateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMaintenance3Properties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDescriptorSetLayoutSupport* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSamplerYcbcrConversionCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSamplerYcbcrConversionInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceSamplerYcbcrConversionFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSamplerYcbcrConversionImageFormatProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceGroupRenderPassBeginInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePointClippingProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderPassInputAttachmentAspectCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineTessellationDomainOriginStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderPassMultiviewCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMultiviewFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMultiviewProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderDrawParametersFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVulkan11Features* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVulkan11Properties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVulkan12Features* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVulkan12Properties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageFormatListCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDriverProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVulkanMemoryModelFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceHostQueryResetFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceTimelineSemaphoreFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceTimelineSemaphoreProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSemaphoreTypeCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkTimelineSemaphoreSubmitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSemaphoreWaitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSemaphoreSignalInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceBufferDeviceAddressFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBufferDeviceAddressInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBufferOpaqueCaptureAddressCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryOpaqueCaptureAddressAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceMemoryOpaqueCaptureAddressInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevice8BitStorageFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderAtomicInt64Features* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderFloat16Int8Features* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceFloatControlsProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDescriptorSetLayoutBindingFlagsCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDescriptorIndexingFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDescriptorIndexingProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDescriptorSetVariableDescriptorCountAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDescriptorSetVariableDescriptorCountLayoutSupport* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceScalarBlockLayoutFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSamplerReductionModeCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceSamplerFilterMinmaxProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceUniformBufferStandardLayoutFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAttachmentDescription2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAttachmentReference2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSubpassDescription2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pInputAttachments = UnwrapStructArrayHandles(value->pInputAttachments, value->inputAttachmentCount, unwrap_memory);
        value->pColorAttachments = UnwrapStructArrayHandles(value->pColorAttachments, value->colorAttachmentCount, unwrap_memory);
        value->pResolveAttachments = UnwrapStructArrayHandles(value->pResolveAttachments, value->colorAttachmentCount, unwrap_memory);
        value->pDepthStencilAttachment = UnwrapStructPtrHandles(value->pDepthStencilAttachment, unwrap_memory);
    }
}

void UnwrapStructHandles(VkSubpassDependency2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderPassCreateInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pAttachments = UnwrapStructArrayHandles(value->pAttachments, value->attachmentCount, unwrap_memory);
        value->pSubpasses = UnwrapStructArrayHandles(value->pSubpasses, value->subpassCount, unwrap_memory);
        value->pDependencies = UnwrapStructArrayHandles(value->pDependencies, value->dependencyCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkSubpassBeginInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSubpassEndInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSubpassDescriptionDepthStencilResolve* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pDepthStencilResolveAttachment = UnwrapStructPtrHandles(value->pDepthStencilResolveAttachment, unwrap_memory);
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDepthStencilResolveProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageStencilUsageCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceImagelessFramebufferFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkFramebufferAttachmentImageInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkFramebufferAttachmentsCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pAttachmentImageInfos = UnwrapStructArrayHandles(value->pAttachmentImageInfos, value->attachmentImageInfoCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkRenderPassAttachmentBeginInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAttachmentReferenceStencilLayout* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAttachmentDescriptionStencilLayout* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVulkan13Features* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVulkan13Properties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceToolProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePrivateDataFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDevicePrivateDataCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPrivateDataSlotCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryBarrier2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBufferMemoryBarrier2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageMemoryBarrier2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDependencyInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pBufferMemoryBarriers = UnwrapStructArrayHandles(value->pBufferMemoryBarriers, value->bufferMemoryBarrierCount, unwrap_memory);
        value->pImageMemoryBarriers = UnwrapStructArrayHandles(value->pImageMemoryBarriers, value->imageMemoryBarrierCount, unwrap_memory);
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pMemoryBarriers = UnwrapStructArrayHandles(value->pMemoryBarriers, value->memoryBarrierCount, unwrap_memory);
        value->pBufferMemoryBarriers = UnwrapStructArrayHandles(value->pBufferMemoryBarriers, value->bufferMemoryBarrierCount, unwrap_memory);
        value->pImageMemoryBarriers = UnwrapStructArrayHandles(value->pImageMemoryBarriers, value->imageMemoryBarrierCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkSemaphoreSubmitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCommandBufferSubmitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSubmitInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pWaitSemaphoreInfos = UnwrapStructArrayHandles(value->pWaitSemaphoreInfos, value->waitSemaphoreInfoCount, unwrap_memory);
        value->pCommandBufferInfos = UnwrapStructArrayHandles(value->pCommandBufferInfos, value->commandBufferInfoCount, unwrap_memory);
        value->pSignalSemaphoreInfos = UnwrapStructArrayHandles(value->pSignalSemaphoreInfos, value->signalSemaphoreInfoCount, unwrap_memory);
        value->pWaitSemaphoreInfos = UnwrapStructArrayHandles(value->pWaitSemaphoreInfos, value->waitSemaphoreInfoCount, unwrap_memory);
        value->pCommandBufferInfos = UnwrapStructArrayHandles(value->pCommandBufferInfos, value->commandBufferInfoCount, unwrap_memory);
        value->pSignalSemaphoreInfos = UnwrapStructArrayHandles(value->pSignalSemaphoreInfos, value->signalSemaphoreInfoCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkPhysicalDeviceSynchronization2Features* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBufferCopy2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCopyBufferInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pRegions = UnwrapStructArrayHandles(value->pRegions, value->regionCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkImageCopy2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCopyImageInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pRegions = UnwrapStructArrayHandles(value->pRegions, value->regionCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkBufferImageCopy2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCopyBufferToImageInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pRegions = UnwrapStructArrayHandles(value->pRegions, value->regionCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkCopyImageToBufferInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pRegions = UnwrapStructArrayHandles(value->pRegions, value->regionCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkPhysicalDeviceTextureCompressionASTCHDRFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkFormatProperties3* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMaintenance4Features* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMaintenance4Properties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceBufferMemoryRequirements* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pCreateInfo = UnwrapStructPtrHandles(value->pCreateInfo, unwrap_memory);
    }
}

void UnwrapStructHandles(VkDeviceImageMemoryRequirements* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pCreateInfo = UnwrapStructPtrHandles(value->pCreateInfo, unwrap_memory);
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineCreationFeedbackCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderTerminateInvocationFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePipelineCreationCacheControlFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceImageRobustnessFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceSubgroupSizeControlFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceSubgroupSizeControlProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineShaderStageRequiredSubgroupSizeCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceInlineUniformBlockFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceInlineUniformBlockProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkWriteDescriptorSetInlineUniformBlock* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDescriptorPoolInlineUniformBlockCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderIntegerDotProductFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderIntegerDotProductProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceTexelBufferAlignmentProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageBlit2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBlitImageInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pRegions = UnwrapStructArrayHandles(value->pRegions, value->regionCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkImageResolve2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkResolveImageInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pRegions = UnwrapStructArrayHandles(value->pRegions, value->regionCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkRenderingAttachmentInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderingInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pColorAttachments = UnwrapStructArrayHandles(value->pColorAttachments, value->colorAttachmentCount, unwrap_memory);
        value->pDepthAttachment = UnwrapStructPtrHandles(value->pDepthAttachment, unwrap_memory);
        value->pStencilAttachment = UnwrapStructPtrHandles(value->pStencilAttachment, unwrap_memory);
        value->pColorAttachments = UnwrapStructArrayHandles(value->pColorAttachments, value->colorAttachmentCount, unwrap_memory);
        value->pDepthAttachment = UnwrapStructPtrHandles(value->pDepthAttachment, unwrap_memory);
        value->pStencilAttachment = UnwrapStructPtrHandles(value->pStencilAttachment, unwrap_memory);
    }
}

void UnwrapStructHandles(VkPipelineRenderingCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDynamicRenderingFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCommandBufferInheritanceRenderingInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVulkan14Features* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVulkan14Properties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceQueueGlobalPriorityCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceGlobalPriorityQueryFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkQueueFamilyGlobalPriorityProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceIndexTypeUint8Features* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryMapInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryUnmapInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMaintenance5Features* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMaintenance5Properties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageSubresource2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceImageSubresourceInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pCreateInfo = UnwrapStructPtrHandles(value->pCreateInfo, unwrap_memory);
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pSubresource = UnwrapStructPtrHandles(value->pSubresource, unwrap_memory);
    }
}

void UnwrapStructHandles(VkSubresourceLayout2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBufferUsageFlags2CreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMaintenance6Features* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMaintenance6Properties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBindMemoryStatus* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceHostImageCopyFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceHostImageCopyProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCopyImageToImageInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pRegions = UnwrapStructArrayHandles(value->pRegions, value->regionCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkHostImageLayoutTransitionInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSubresourceHostMemcpySize* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkHostImageCopyDevicePerformanceQuery* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderSubgroupRotateFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderFloatControls2Features* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderExpectAssumeFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineCreateFlags2CreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePushDescriptorProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBindDescriptorSetsInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPushConstantsInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPushDescriptorSetInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pDescriptorWrites = UnwrapStructArrayHandles(value->pDescriptorWrites, value->descriptorWriteCount, unwrap_memory);
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePipelineProtectedAccessFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePipelineRobustnessFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePipelineRobustnessProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineRobustnessCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceLineRasterizationFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceLineRasterizationProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineRasterizationLineStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVertexAttributeDivisorProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineVertexInputDivisorStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVertexAttributeDivisorFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderingAreaInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDynamicRenderingLocalReadFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderingAttachmentLocationInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderingInputAttachmentIndexInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSwapchainCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPresentInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageSwapchainCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBindImageMemorySwapchainInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAcquireNextImageInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceGroupPresentCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceGroupPresentInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceGroupSwapchainCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDisplayModeCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDisplayModePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
}

void UnwrapStructHandles(VkDisplayPlanePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
}

void UnwrapStructHandles(VkDisplayPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
}

void UnwrapStructHandles(VkDisplaySurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDisplayPresentInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkXlibSurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkXcbSurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkWaylandSurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAndroidSurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkWin32SurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkQueueFamilyQueryResultStatusPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkQueueFamilyVideoPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoProfileInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoProfileListInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pProfiles = UnwrapStructArrayHandles(value->pProfiles, value->profileCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkVideoCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVideoFormatInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoFormatPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoPictureResourceInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoReferenceSlotInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pPictureResource = UnwrapStructPtrHandles(value->pPictureResource, unwrap_memory);
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pPictureResource = UnwrapStructPtrHandles(value->pPictureResource, unwrap_memory);
    }
}

void UnwrapStructHandles(VkVideoSessionMemoryRequirementsKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBindVideoSessionMemoryInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoSessionCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pVideoProfile = UnwrapStructPtrHandles(value->pVideoProfile, unwrap_memory);
    }
}

void UnwrapStructHandles(VkVideoSessionParametersCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoSessionParametersUpdateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoBeginCodingInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pReferenceSlots = UnwrapStructArrayHandles(value->pReferenceSlots, value->referenceSlotCount, unwrap_memory);
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pReferenceSlots = UnwrapStructArrayHandles(value->pReferenceSlots, value->referenceSlotCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkVideoEndCodingInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoCodingControlInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoDecodeCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoDecodeUsageInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoDecodeInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        UnwrapStructHandles(&value->dstPictureResource, unwrap_memory);
        value->pSetupReferenceSlot = UnwrapStructPtrHandles(value->pSetupReferenceSlot, unwrap_memory);
        value->pReferenceSlots = UnwrapStructArrayHandles(value->pReferenceSlots, value->referenceSlotCount, unwrap_memory);
        UnwrapStructHandles(&value->dstPictureResource, unwrap_memory);
        value->pSetupReferenceSlot = UnwrapStructPtrHandles(value->pSetupReferenceSlot, unwrap_memory);
        value->pReferenceSlots = UnwrapStructArrayHandles(value->pReferenceSlots, value->referenceSlotCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkVideoEncodeH264CapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeH264QualityLevelPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeH264SessionCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeH264SessionParametersAddInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeH264SessionParametersCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pParametersAddInfo = UnwrapStructPtrHandles(value->pParametersAddInfo, unwrap_memory);
    }
}

void UnwrapStructHandles(VkVideoEncodeH264SessionParametersGetInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeH264SessionParametersFeedbackInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeH264NaluSliceInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeH264PictureInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pNaluSliceEntries = UnwrapStructArrayHandles(value->pNaluSliceEntries, value->naluSliceEntryCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkVideoEncodeH264DpbSlotInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeH264ProfileInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeH264RateControlInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeH264RateControlLayerInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeH264GopRemainingFrameInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoDecodeH264ProfileInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoDecodeH264CapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoDecodeH264SessionParametersAddInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoDecodeH264SessionParametersCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pParametersAddInfo = UnwrapStructPtrHandles(value->pParametersAddInfo, unwrap_memory);
    }
}

void UnwrapStructHandles(VkVideoDecodeH264PictureInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoDecodeH264DpbSlotInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImportMemoryWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkExportMemoryWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryWin32HandlePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImportMemoryFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryFdPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkWin32KeyedMutexAcquireReleaseInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImportSemaphoreWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkExportSemaphoreWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkD3D12FenceSubmitInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSemaphoreGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImportSemaphoreFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSemaphoreGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPresentRegionsKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSharedPresentSurfaceCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImportFenceWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkExportFenceWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkFenceGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImportFenceFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkFenceGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePerformanceQueryFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePerformanceQueryPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPerformanceCounterKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPerformanceCounterDescriptionKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkQueryPoolPerformanceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAcquireProfilingLockInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPerformanceQuerySubmitInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceSurfaceInfo2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSurfaceCapabilities2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSurfaceFormat2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDisplayProperties2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->displayProperties, unwrap_memory);
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDisplayPlaneProperties2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->displayPlaneProperties, unwrap_memory);
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDisplayModeProperties2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->displayModeProperties, unwrap_memory);
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDisplayPlaneInfo2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDisplayPlaneCapabilities2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderBfloat16FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePortabilitySubsetFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePortabilitySubsetPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderClockFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkFragmentShadingRateAttachmentInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pFragmentShadingRateAttachment = UnwrapStructPtrHandles(value->pFragmentShadingRateAttachment, unwrap_memory);
    }
}

void UnwrapStructHandles(VkPipelineFragmentShadingRateStateCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceFragmentShadingRateFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceFragmentShadingRatePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceFragmentShadingRateKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderingFragmentShadingRateAttachmentInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderQuadControlFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSurfaceProtectedCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePresentWaitFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineExecutablePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineExecutableInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineExecutableStatisticKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineExecutableInternalRepresentationKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineLibraryCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPresentIdKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePresentIdFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        UnwrapStructHandles(&value->srcPictureResource, unwrap_memory);
        value->pSetupReferenceSlot = UnwrapStructPtrHandles(value->pSetupReferenceSlot, unwrap_memory);
        value->pReferenceSlots = UnwrapStructArrayHandles(value->pReferenceSlots, value->referenceSlotCount, unwrap_memory);
        UnwrapStructHandles(&value->srcPictureResource, unwrap_memory);
        value->pSetupReferenceSlot = UnwrapStructPtrHandles(value->pSetupReferenceSlot, unwrap_memory);
        value->pReferenceSlots = UnwrapStructArrayHandles(value->pReferenceSlots, value->referenceSlotCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkVideoEncodeCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkQueryPoolVideoEncodeFeedbackCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeUsageInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeRateControlLayerInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeRateControlInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pLayers = UnwrapStructArrayHandles(value->pLayers, value->layerCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pVideoProfile = UnwrapStructPtrHandles(value->pVideoProfile, unwrap_memory);
    }
}

void UnwrapStructHandles(VkVideoEncodeQualityLevelPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeQualityLevelInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeSessionParametersGetInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeSessionParametersFeedbackInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderUntypedPointersFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSurfaceCapabilitiesPresentId2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPresentId2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePresentId2FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSurfaceCapabilitiesPresentWait2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePresentWait2FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPresentWait2InfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePipelineBinaryFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePipelineBinaryPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDevicePipelineBinaryInternalCacheControlKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineBinaryKeyKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineBinaryCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pPipelineCreateInfo = UnwrapStructPtrHandles(value->pPipelineCreateInfo, unwrap_memory);
    }
}

void UnwrapStructHandles(VkPipelineBinaryInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkReleaseCapturedPipelineDataInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineBinaryDataInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineBinaryHandlesInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSurfacePresentModeKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSurfacePresentScalingCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSurfacePresentModeCompatibilityKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSwapchainPresentFenceInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSwapchainPresentModesCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSwapchainPresentModeInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSwapchainPresentScalingCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkReleaseSwapchainImagesInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCooperativeMatrixPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceCooperativeMatrixFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceCooperativeMatrixPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoDecodeAV1ProfileInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoDecodeAV1CapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoDecodeAV1SessionParametersCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoDecodeAV1PictureInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoDecodeAV1DpbSlotInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVideoEncodeAV1FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeAV1CapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeAV1QualityLevelPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeAV1SessionCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeAV1SessionParametersCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeAV1PictureInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeAV1DpbSlotInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeAV1ProfileInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeAV1GopRemainingFrameInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeAV1RateControlInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeAV1RateControlLayerInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVideoDecodeVP9FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoDecodeVP9ProfileInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoDecodeVP9CapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoDecodeVP9PictureInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVideoMaintenance1FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoInlineQueryInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAttachmentFeedbackLoopInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCalibratedTimestampInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSetDescriptorBufferOffsetsInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBindDescriptorBufferEmbeddedSamplersInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCopyMemoryIndirectInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCopyMemoryToImageIndirectInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeIntraRefreshCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeSessionIntraRefreshCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeIntraRefreshInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoReferenceIntraRefreshInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeQuantizationMapCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoFormatQuantizationMapPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeQuantizationMapInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeH264QuantizationMapCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeH265QuantizationMapCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoFormatH265QuantizationMapPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeAV1QuantizationMapCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoFormatAV1QuantizationMapPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMaintenance7FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMaintenance7PropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceLayeredApiPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceLayeredApiPropertiesListKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pLayeredApis = const_cast<VkPhysicalDeviceLayeredApiPropertiesKHR*>(UnwrapStructArrayHandles(value->pLayeredApis, value->layeredApiCount, unwrap_memory));
    }
}

void UnwrapStructHandles(VkPhysicalDeviceLayeredApiVulkanPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        UnwrapStructHandles(&value->properties, unwrap_memory);
    }
}

void UnwrapStructHandles(VkMemoryBarrierAccessFlags3KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMaintenance8FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderFmaFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMaintenance9FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMaintenance9PropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkQueueFamilyOwnershipTransferPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDepthClampZeroOneFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceRobustness2FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceRobustness2PropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMaintenance10FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMaintenance10PropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderingEndInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderingAttachmentFlagsInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkResolveImageModeInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDebugReportCallbackCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineRasterizationStateRasterizationOrderAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDebugMarkerObjectNameInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDebugMarkerObjectTagInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDebugMarkerMarkerInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDedicatedAllocationImageCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDedicatedAllocationBufferCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDedicatedAllocationMemoryAllocateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceTransformFeedbackFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceTransformFeedbackPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineRasterizationStateStreamCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageViewHandleInfoNVX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageViewAddressPropertiesNVX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkTextureLODGatherFormatPropertiesAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkStreamDescriptorSurfaceCreateInfoGGP* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceCornerSampledImageFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkExternalMemoryImageCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkExportMemoryAllocateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImportMemoryWin32HandleInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkExportMemoryWin32HandleInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkWin32KeyedMutexAcquireReleaseInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkValidationFlagsEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkViSurfaceCreateInfoNN* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageViewASTCDecodeModeEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceASTCDecodeFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkConditionalRenderingBeginInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceConditionalRenderingFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCommandBufferInheritanceConditionalRenderingInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineViewportWScalingStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSurfaceCapabilities2EXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDisplayPowerInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceEventInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDisplayEventInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSwapchainCounterCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPresentTimesInfoGOOGLE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMultiviewPerViewAttributesInfoNVX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineViewportSwizzleStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDiscardRectanglePropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineDiscardRectangleStateCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceConservativeRasterizationPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineRasterizationConservativeStateCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDepthClipEnableFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineRasterizationDepthClipStateCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkHdrMetadataEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkIOSSurfaceCreateInfoMVK* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMacOSSurfaceCreateInfoMVK* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDebugUtilsLabelEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDebugUtilsObjectNameInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDebugUtilsMessengerCallbackDataEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pQueueLabels = UnwrapStructArrayHandles(value->pQueueLabels, value->queueLabelCount, unwrap_memory);
        value->pCmdBufLabels = UnwrapStructArrayHandles(value->pCmdBufLabels, value->cmdBufLabelCount, unwrap_memory);
        value->pObjects = UnwrapStructArrayHandles(value->pObjects, value->objectCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkDebugUtilsMessengerCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDebugUtilsObjectTagInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAndroidHardwareBufferUsageANDROID* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAndroidHardwareBufferPropertiesANDROID* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAndroidHardwareBufferFormatPropertiesANDROID* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImportAndroidHardwareBufferInfoANDROID* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryGetAndroidHardwareBufferInfoANDROID* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkExternalFormatANDROID* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAndroidHardwareBufferFormatProperties2ANDROID* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAttachmentSampleCountInfoAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSampleLocationsInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderPassSampleLocationsBeginInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineSampleLocationsStateCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        UnwrapStructHandles(&value->sampleLocationsInfo, unwrap_memory);
    }
}

void UnwrapStructHandles(VkPhysicalDeviceSampleLocationsPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMultisamplePropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineColorBlendAdvancedStateCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineCoverageToColorStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineCoverageModulationStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDrmFormatModifierPropertiesListEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceImageDrmFormatModifierInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageDrmFormatModifierListCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageDrmFormatModifierExplicitCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageDrmFormatModifierPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDrmFormatModifierPropertiesList2EXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkValidationCacheCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkShaderModuleValidationCacheCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineViewportShadingRateImageStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShadingRateImageFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShadingRateImagePropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRayTracingShaderGroupCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRayTracingPipelineCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pStages = UnwrapStructArrayHandles(value->pStages, value->stageCount, unwrap_memory);
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pStages = UnwrapStructArrayHandles(value->pStages, value->stageCount, unwrap_memory);
        value->pGroups = UnwrapStructArrayHandles(value->pGroups, value->groupCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkGeometryTrianglesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkGeometryAABBNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
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
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAccelerationStructureInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pGeometries = UnwrapStructArrayHandles(value->pGeometries, value->geometryCount, unwrap_memory);
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pGeometries = UnwrapStructArrayHandles(value->pGeometries, value->geometryCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkAccelerationStructureCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->info, unwrap_memory);
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        UnwrapStructHandles(&value->info, unwrap_memory);
    }
}

void UnwrapStructHandles(VkBindAccelerationStructureMemoryInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkWriteDescriptorSetAccelerationStructureNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAccelerationStructureMemoryRequirementsInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceRayTracingPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineRepresentativeFragmentTestStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceImageViewImageFormatInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkFilterCubicImageViewImageFormatPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImportMemoryHostPointerInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryHostPointerPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceExternalMemoryHostPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineCompilerControlCreateInfoAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderCorePropertiesAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceMemoryOverallocationCreateInfoAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPresentFrameTokenGGP* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMeshShaderFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMeshShaderPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderImageFootprintFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineViewportExclusiveScissorStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceExclusiveScissorFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkQueueFamilyCheckpointPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCheckpointDataNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkQueueFamilyCheckpointProperties2NV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCheckpointData2NV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePresentTimingFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPresentTimingSurfaceCapabilitiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSwapchainCalibratedTimestampInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSwapchainTimingPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSwapchainTimeDomainPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPastPresentationTimingInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPastPresentationTimingEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPastPresentationTimingPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pPresentationTimings = const_cast<VkPastPresentationTimingEXT*>(UnwrapStructArrayHandles(value->pPresentationTimings, value->presentationTimingCount, unwrap_memory));
    }
}

void UnwrapStructHandles(VkPresentTimingInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPresentTimingsInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pTimingInfos = UnwrapStructArrayHandles(value->pTimingInfos, value->swapchainCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkInitializePerformanceApiInfoINTEL* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkQueryPoolPerformanceQueryCreateInfoINTEL* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPerformanceMarkerInfoINTEL* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPerformanceStreamMarkerInfoINTEL* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPerformanceOverrideInfoINTEL* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPerformanceConfigurationAcquireInfoINTEL* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePCIBusInfoPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDisplayNativeHdrSurfaceCapabilitiesAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSwapchainDisplayNativeHdrCreateInfoAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImagePipeSurfaceCreateInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMetalSurfaceCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceFragmentDensityMapFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceFragmentDensityMapPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderPassFragmentDensityMapCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderingFragmentDensityMapAttachmentInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderCoreProperties2AMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceCoherentMemoryFeaturesAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMemoryBudgetPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMemoryPriorityFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryPriorityAllocateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBufferDeviceAddressCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkValidationFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCooperativeMatrixPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceCooperativeMatrixFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceCooperativeMatrixPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceCoverageReductionModeFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineCoverageReductionStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkFramebufferMixedSamplesCombinationNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceProvokingVertexFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceProvokingVertexPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineRasterizationProvokingVertexStateCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSurfaceFullScreenExclusiveInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSurfaceCapabilitiesFullScreenExclusiveEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSurfaceFullScreenExclusiveWin32InfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkHeadlessSurfaceCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMapMemoryPlacedFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMapMemoryPlacedPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryMapPlacedInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkGraphicsShaderGroupCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pStages = UnwrapStructArrayHandles(value->pStages, value->stageCount, unwrap_memory);
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pStages = UnwrapStructArrayHandles(value->pStages, value->stageCount, unwrap_memory);
        value->pVertexInputState = UnwrapStructPtrHandles(value->pVertexInputState, unwrap_memory);
        value->pTessellationState = UnwrapStructPtrHandles(value->pTessellationState, unwrap_memory);
    }
}

void UnwrapStructHandles(VkGraphicsPipelineShaderGroupsCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pGroups = UnwrapStructArrayHandles(value->pGroups, value->groupCount, unwrap_memory);
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pGroups = UnwrapStructArrayHandles(value->pGroups, value->groupCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkIndirectCommandsStreamNV* value, HandleUnwrapMemory* unwrap_memory)
{
}

void UnwrapStructHandles(VkIndirectCommandsLayoutTokenNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkIndirectCommandsLayoutCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pTokens = UnwrapStructArrayHandles(value->pTokens, value->tokenCount, unwrap_memory);
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pTokens = UnwrapStructArrayHandles(value->pTokens, value->tokenCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkGeneratedCommandsInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pStreams = UnwrapStructArrayHandles(value->pStreams, value->streamCount, unwrap_memory);
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkGeneratedCommandsMemoryRequirementsInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceInheritedViewportScissorFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCommandBufferInheritanceViewportScissorInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderPassTransformBeginInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCommandBufferInheritanceRenderPassTransformInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDepthBiasControlFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDepthBiasInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDepthBiasRepresentationInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceMemoryReportCallbackDataEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceDeviceMemoryReportCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSamplerCustomBorderColorCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceCustomBorderColorPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceCustomBorderColorFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePresentBarrierFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSurfaceCapabilitiesPresentBarrierNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSwapchainPresentBarrierCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDiagnosticsConfigFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceDiagnosticsConfigCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceTileShadingFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceTileShadingPropertiesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderPassTileShadingCreateInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPerTileBeginInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPerTileEndInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDispatchTileInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkQueryLowLatencySupportNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDescriptorBufferPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDescriptorBufferFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDescriptorAddressInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDescriptorBufferBindingInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDescriptorBufferBindingPushDescriptorBufferHandleEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBufferCaptureDescriptorDataInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageCaptureDescriptorDataInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageViewCaptureDescriptorDataInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSamplerCaptureDescriptorDataInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkOpaqueCaptureDescriptorDataCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAccelerationStructureCaptureDescriptorDataInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkGraphicsPipelineLibraryCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineFragmentShadingRateEnumStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAccelerationStructureGeometryMotionTrianglesDataNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAccelerationStructureMotionInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceFragmentDensityMap2PropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCopyCommandTransformInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceImageCompressionControlFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageCompressionControlEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageCompressionPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevice4444FormatsFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceFaultFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceFaultCountsEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceFaultInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDirectFBSurfaceCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMutableDescriptorTypeCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVertexInputBindingDescription2EXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVertexInputAttributeDescription2EXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDrmPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceAddressBindingReportFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceAddressBindingCallbackDataEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDepthClipControlFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineViewportDepthClipControlCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImportMemoryZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryZirconHandlePropertiesFUCHSIA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryGetZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImportSemaphoreZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSemaphoreGetZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryGetRemoteAddressInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceFrameBoundaryFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkFrameBoundaryEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSubpassResolvePerformanceQueryEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMultisampledRenderToSingleSampledInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkScreenSurfaceCreateInfoQNX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceColorWriteEnableFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineColorWriteCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeRgbConversionCapabilitiesVALVE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeProfileRgbConversionInfoVALVE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkVideoEncodeSessionRgbConversionCreateInfoVALVE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceImageViewMinLodFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageViewMinLodCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMultiDrawFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMultiDrawPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderTileImageFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderTileImagePropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMicromapBuildInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMicromapCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceOpacityMicromapFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceOpacityMicromapPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMicromapVersionInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCopyMicromapToMemoryInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCopyMemoryToMicromapInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCopyMicromapInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMicromapBuildSizesInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAccelerationStructureTrianglesOpacityMicromapEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDisplacementMicromapFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDisplacementMicromapPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAccelerationStructureTrianglesDisplacementMicromapNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSamplerBorderColorComponentMappingCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderCorePropertiesARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDeviceQueueShaderCoreControlCreateInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceSchedulingControlsFeaturesARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceSchedulingControlsPropertiesARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageViewSlicedCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDescriptorSetBindingReferenceVALVE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDescriptorSetLayoutHostMappingInfoVALVE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceRenderPassStripedFeaturesARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceRenderPassStripedPropertiesARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderPassStripeInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderPassStripeBeginInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pStripeInfos = UnwrapStructArrayHandles(value->pStripeInfos, value->stripeInfoCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkRenderPassStripeSubmitInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pStripeSemaphoreInfos = UnwrapStructArrayHandles(value->pStripeSemaphoreInfos, value->stripeSemaphoreInfoCount, unwrap_memory);
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pStripeSemaphoreInfos = UnwrapStructArrayHandles(value->pStripeSemaphoreInfos, value->stripeSemaphoreInfoCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderPassFragmentDensityMapOffsetEndInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkComputePipelineIndirectBufferInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineIndirectDeviceAddressInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAccelerationStructureGeometryLinearSweptSpheresDataNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAccelerationStructureGeometrySpheresDataNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceLinearColorAttachmentFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageViewSampleWeightCreateInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceImageProcessingFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceImageProcessingPropertiesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceNestedCommandBufferFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceNestedCommandBufferPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkExternalMemoryAcquireUnmodifiedEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceExtendedDynamicState3PropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderPassCreationControlEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderPassCreationFeedbackCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderPassSubpassFeedbackCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDirectDriverLoadingInfoLUNARG* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDirectDriverLoadingListLUNARG* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pDrivers = UnwrapStructArrayHandles(value->pDrivers, value->driverCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineShaderStageModuleIdentifierCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkShaderModuleIdentifierEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceOpticalFlowFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceOpticalFlowPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkOpticalFlowImageFormatInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkOpticalFlowImageFormatPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkOpticalFlowSessionCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkOpticalFlowSessionCreatePrivateDataInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkOpticalFlowExecuteInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceLegacyDitheringFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceExternalFormatResolveFeaturesANDROID* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceExternalFormatResolvePropertiesANDROID* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAndroidHardwareBufferFormatResolvePropertiesANDROID* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceAntiLagFeaturesAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAntiLagPresentationInfoAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAntiLagDataAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pPresentationInfo = UnwrapStructPtrHandles(value->pPresentationInfo, unwrap_memory);
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderObjectFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderObjectPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkShaderCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceTilePropertiesFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkTilePropertiesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceAmigoProfilingFeaturesSEC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAmigoProfilingSubmitInfoSEC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceCooperativeVectorPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceCooperativeVectorFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCooperativeVectorPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkConvertCooperativeVectorMatrixInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkLayerSettingsCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkLatencySleepModeInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkLatencySleepInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSetLatencyMarkerInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkLatencyTimingsFrameReportNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkGetLatencyMarkerInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pTimings = const_cast<VkLatencyTimingsFrameReportNV*>(UnwrapStructArrayHandles(value->pTimings, value->timingCount, unwrap_memory));
    }
}

void UnwrapStructHandles(VkLatencySubmissionPresentIdNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSwapchainLatencyCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkOutOfBandQueueTypeInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkLatencySurfaceCapabilitiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDataGraphFeaturesARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDataGraphPipelineConstantARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDataGraphPipelineResourceInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDataGraphPipelineCompilerControlCreateInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDataGraphPipelineCreateInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pResourceInfos = UnwrapStructArrayHandles(value->pResourceInfos, value->resourceInfoCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkDataGraphPipelineShaderModuleCreateInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pConstants = UnwrapStructArrayHandles(value->pConstants, value->constantCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkDataGraphPipelineSessionCreateInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDataGraphPipelineSessionBindPointRequirementsInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDataGraphPipelineSessionBindPointRequirementARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDataGraphPipelineSessionMemoryRequirementsInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBindDataGraphPipelineSessionMemoryInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDataGraphPipelineInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDataGraphPipelinePropertyQueryResultARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDataGraphPipelineIdentifierCreateInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDataGraphPipelineDispatchInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkQueueFamilyDataGraphPropertiesARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDataGraphProcessingEngineCreateInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkQueueFamilyDataGraphProcessingEnginePropertiesARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePerStageDescriptorSetFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceImageProcessing2FeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceImageProcessing2PropertiesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSamplerBlockMatchWindowCreateInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceCubicWeightsFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSamplerCubicWeightsCreateInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBlitImageCubicWeightsInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceYcbcrDegammaFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceCubicClampFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceLayeredDriverPropertiesMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceTileMemoryHeapFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceTileMemoryHeapPropertiesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkTileMemoryRequirementsQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkTileMemoryBindInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkTileMemorySizeInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDecompressMemoryInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMemoryDecompressionFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMemoryDecompressionPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDisplaySurfaceStereoCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDisplayModeStereoPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceRawAccessChainsFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceCommandBufferInheritanceFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderFloat8FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceRayTracingValidationFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPartitionedAccelerationStructureFlagsNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkWriteDescriptorSetPartitionedAccelerationStructureNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPartitionedAccelerationStructureInstancesInputNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBuildPartitionedAccelerationStructureInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        UnwrapStructHandles(&value->input, unwrap_memory);
    }
}

void UnwrapStructHandles(VkAccelerationStructureBuildSizesInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkGeneratedCommandsMemoryRequirementsInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkIndirectExecutionSetPipelineInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkIndirectExecutionSetShaderLayoutInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkIndirectExecutionSetShaderInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pSetLayoutInfos = UnwrapStructArrayHandles(value->pSetLayoutInfos, value->shaderCount, unwrap_memory);
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pSetLayoutInfos = UnwrapStructArrayHandles(value->pSetLayoutInfos, value->shaderCount, unwrap_memory);
    }
}

void UnwrapStructHandles(VkGeneratedCommandsInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkWriteIndirectExecutionSetPipelineEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkIndirectCommandsLayoutCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkGeneratedCommandsPipelineInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkGeneratedCommandsShaderInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkWriteIndirectExecutionSetShaderEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceImageAlignmentControlFeaturesMESA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceImageAlignmentControlPropertiesMESA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImageAlignmentControlCreateInfoMESA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPushConstantBankInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePushConstantBankFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePushConstantBankPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDepthClampControlFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineViewportDepthClampControlCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceHdrVividFeaturesHUAWEI* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkHdrVividDynamicMetadataHUAWEI* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCooperativeMatrixFlexibleDimensionsPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceCooperativeMatrix2FeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceCooperativeMatrix2PropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePipelineOpacityMicromapFeaturesARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkImportMemoryMetalHandleInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryMetalHandlePropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkMemoryGetMetalHandleInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePerformanceCountersByRegionFeaturesARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePerformanceCountersByRegionPropertiesARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPerformanceCounterARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPerformanceCounterDescriptionARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRenderPassPerformanceCountersByRegionBeginInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceFormatPackFeaturesARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPipelineFragmentDensityMapLayeredCreateInfoVALVE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkSetPresentConfigNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePresentMeteringFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShader64BitIndexingFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceCustomResolveFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkBeginCustomResolveInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCustomResolveCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkDataGraphPipelineBuiltinModelCreateInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceDataGraphModelFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderLongVectorFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderLongVectorPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkComputeOccupancyPriorityParametersNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAccelerationStructureGeometryTrianglesDataKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAccelerationStructureGeometryAabbsDataKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAccelerationStructureGeometryInstancesDataKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAccelerationStructureCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkWriteDescriptorSetAccelerationStructureKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceAccelerationStructureFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceAccelerationStructurePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAccelerationStructureDeviceAddressInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkAccelerationStructureVersionInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCopyAccelerationStructureToMemoryInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCopyMemoryToAccelerationStructureInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkCopyAccelerationStructureInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRayTracingShaderGroupCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRayTracingPipelineInterfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkRayTracingPipelineCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pStages = UnwrapStructArrayHandles(value->pStages, value->stageCount, unwrap_memory);
        value->pLibraryInfo = UnwrapStructPtrHandles(value->pLibraryInfo, unwrap_memory);
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
        value->pStages = UnwrapStructArrayHandles(value->pStages, value->stageCount, unwrap_memory);
        value->pGroups = UnwrapStructArrayHandles(value->pGroups, value->groupCount, unwrap_memory);
        value->pLibraryInfo = UnwrapStructPtrHandles(value->pLibraryInfo, unwrap_memory);
        value->pLibraryInterface = UnwrapStructPtrHandles(value->pLibraryInterface, unwrap_memory);
        value->pDynamicState = UnwrapStructPtrHandles(value->pDynamicState, unwrap_memory);
    }
}

void UnwrapStructHandles(VkPhysicalDeviceRayTracingPipelineFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceRayTracingPipelinePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceRayQueryFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMeshShaderFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(VkPhysicalDeviceMeshShaderPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));
        }
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
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAccelerationStructureBuildGeometryInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAccelerationStructureBuildSizesInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAccelerationStructureCaptureDescriptorDataInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAccelerationStructureCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAccelerationStructureCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAccelerationStructureDeviceAddressInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAccelerationStructureGeometryAabbsDataKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAccelerationStructureGeometryInstancesDataKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_LINEAR_SWEPT_SPHERES_DATA_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAccelerationStructureGeometryLinearSweptSpheresDataNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAccelerationStructureGeometryMotionTrianglesDataNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_SPHERES_DATA_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAccelerationStructureGeometrySpheresDataNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAccelerationStructureGeometryTrianglesDataKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAccelerationStructureInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAccelerationStructureMemoryRequirementsInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAccelerationStructureMotionInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAccelerationStructureTrianglesDisplacementMicromapNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAccelerationStructureTrianglesOpacityMicromapEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAccelerationStructureVersionInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAcquireNextImageInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAcquireProfilingLockInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAmigoProfilingSubmitInfoSEC*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAndroidHardwareBufferFormatProperties2ANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAndroidHardwareBufferFormatPropertiesANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAndroidHardwareBufferFormatResolvePropertiesANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAndroidHardwareBufferPropertiesANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAndroidHardwareBufferUsageANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAndroidSurfaceCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ANTI_LAG_DATA_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAntiLagDataAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ANTI_LAG_PRESENTATION_INFO_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAntiLagPresentationInfoAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_APPLICATION_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkApplicationInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAttachmentDescription2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAttachmentDescriptionStencilLayout*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ATTACHMENT_FEEDBACK_LOOP_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAttachmentFeedbackLoopInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAttachmentReference2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAttachmentReferenceStencilLayout*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkAttachmentSampleCountInfoAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BEGIN_CUSTOM_RESOLVE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBeginCustomResolveInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBindAccelerationStructureMemoryInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBindBufferMemoryDeviceGroupInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBindBufferMemoryInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BIND_DATA_GRAPH_PIPELINE_SESSION_MEMORY_INFO_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBindDataGraphPipelineSessionMemoryInfoARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBindDescriptorBufferEmbeddedSamplersInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_SETS_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBindDescriptorSetsInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBindImageMemoryDeviceGroupInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBindImageMemoryInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBindImagePlaneMemoryInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBindMemoryStatus*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BIND_SPARSE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBindSparseInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBindVideoSessionMemoryInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBlitImageCubicWeightsInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBlitImageInfo2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BUFFER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBufferCaptureDescriptorDataInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BUFFER_COPY_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBufferCopy2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBufferCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBufferDeviceAddressCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBufferDeviceAddressInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBufferImageCopy2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBufferMemoryBarrier*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBufferMemoryBarrier2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBufferMemoryRequirementsInfo2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBufferOpaqueCaptureAddressCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBufferUsageFlags2CreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBufferViewCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_BUILD_PARTITIONED_ACCELERATION_STRUCTURE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkBuildPartitionedAccelerationStructureInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCalibratedTimestampInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCheckpointData2NV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCheckpointDataNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCommandBufferAllocateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCommandBufferBeginInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCommandBufferInheritanceInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCommandBufferInheritanceRenderPassTransformInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCommandBufferInheritanceRenderingInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCommandBufferInheritanceViewportScissorInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCommandBufferSubmitInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCommandPoolCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COMPUTE_OCCUPANCY_PRIORITY_PARAMETERS_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkComputeOccupancyPriorityParametersNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkComputePipelineCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkComputePipelineIndirectBufferInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkConditionalRenderingBeginInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_CONVERT_COOPERATIVE_VECTOR_MATRIX_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkConvertCooperativeVectorMatrixInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_FLEXIBLE_DIMENSIONS_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCooperativeMatrixFlexibleDimensionsPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCooperativeMatrixPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCooperativeMatrixPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COOPERATIVE_VECTOR_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCooperativeVectorPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCopyAccelerationStructureInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCopyAccelerationStructureToMemoryInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCopyBufferInfo2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCopyBufferToImageInfo2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCopyCommandTransformInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCopyDescriptorSet*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCopyImageInfo2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCopyImageToBufferInfo2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCopyImageToImageInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COPY_MEMORY_INDIRECT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCopyMemoryIndirectInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCopyMemoryToAccelerationStructureInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INDIRECT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCopyMemoryToImageIndirectInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCopyMemoryToMicromapInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCopyMicromapInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCopyMicromapToMemoryInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_CUSTOM_RESOLVE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkCustomResolveCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkD3D12FenceSubmitInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_BUILTIN_MODEL_CREATE_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDataGraphPipelineBuiltinModelCreateInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_COMPILER_CONTROL_CREATE_INFO_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDataGraphPipelineCompilerControlCreateInfoARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CONSTANT_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDataGraphPipelineConstantARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CONSTANT_TENSOR_SEMI_STRUCTURED_SPARSITY_INFO_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CREATE_INFO_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDataGraphPipelineCreateInfoARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_DISPATCH_INFO_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDataGraphPipelineDispatchInfoARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_IDENTIFIER_CREATE_INFO_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDataGraphPipelineIdentifierCreateInfoARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_INFO_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDataGraphPipelineInfoARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_PROPERTY_QUERY_RESULT_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDataGraphPipelinePropertyQueryResultARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDataGraphPipelineResourceInfoARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_REQUIREMENT_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDataGraphPipelineSessionBindPointRequirementARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_REQUIREMENTS_INFO_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDataGraphPipelineSessionBindPointRequirementsInfoARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_CREATE_INFO_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDataGraphPipelineSessionCreateInfoARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_MEMORY_REQUIREMENTS_INFO_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDataGraphPipelineSessionMemoryRequirementsInfoARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SHADER_MODULE_CREATE_INFO_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDataGraphPipelineShaderModuleCreateInfoARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PROCESSING_ENGINE_CREATE_INFO_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDataGraphProcessingEngineCreateInfoARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDebugMarkerMarkerInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDebugMarkerObjectNameInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDebugMarkerObjectTagInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDebugReportCallbackCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDebugUtilsLabelEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDebugUtilsMessengerCallbackDataEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDebugUtilsMessengerCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDebugUtilsObjectNameInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDebugUtilsObjectTagInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DECOMPRESS_MEMORY_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDecompressMemoryInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDedicatedAllocationBufferCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDedicatedAllocationImageCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEPENDENCY_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDependencyInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEPTH_BIAS_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDepthBiasInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDepthBiasRepresentationInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_ADDRESS_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDescriptorAddressInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDescriptorBufferBindingInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_PUSH_DESCRIPTOR_BUFFER_HANDLE_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDescriptorBufferBindingPushDescriptorBufferHandleEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDescriptorPoolCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDescriptorPoolInlineUniformBlockCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDescriptorSetAllocateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDescriptorSetBindingReferenceVALVE*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDescriptorSetLayoutBindingFlagsCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDescriptorSetLayoutCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDescriptorSetLayoutHostMappingInfoVALVE*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDescriptorSetLayoutSupport*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDescriptorSetVariableDescriptorCountAllocateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDescriptorSetVariableDescriptorCountLayoutSupport*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDescriptorUpdateTemplateCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceAddressBindingCallbackDataEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceBufferMemoryRequirements*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceDeviceMemoryReportCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceDiagnosticsConfigCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceEventInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceFaultCountsEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceFaultInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceGroupBindSparseInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceGroupCommandBufferBeginInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceGroupPresentCapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceGroupPresentInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceGroupRenderPassBeginInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceGroupSubmitInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceGroupSwapchainCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceImageMemoryRequirements*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_IMAGE_SUBRESOURCE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceImageSubresourceInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceMemoryOpaqueCaptureAddressInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceMemoryOverallocationCreateInfoAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceMemoryReportCallbackDataEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_PIPELINE_BINARY_INTERNAL_CACHE_CONTROL_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDevicePipelineBinaryInternalCacheControlKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDevicePrivateDataCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceQueueCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceQueueGlobalPriorityCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceQueueInfo2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDeviceQueueShaderCoreControlCreateInfoARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_INFO_LUNARG:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDirectDriverLoadingInfoLUNARG*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDirectDriverLoadingListLUNARG*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDirectFBSurfaceCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DISPATCH_TILE_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDispatchTileInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDisplayEventInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDisplayModeCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDisplayModeProperties2KHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DISPLAY_MODE_STEREO_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDisplayModeStereoPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDisplayPlaneCapabilities2KHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDisplayPlaneInfo2KHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDisplayPlaneProperties2KHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDisplayPowerInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDisplayPresentInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDisplayProperties2KHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDisplaySurfaceCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_STEREO_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDisplaySurfaceStereoCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDrmFormatModifierPropertiesList2EXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkDrmFormatModifierPropertiesListEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EVENT_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkEventCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExportFenceCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExportFenceWin32HandleInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExportMemoryAllocateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExportMemoryAllocateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExportMemoryWin32HandleInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExportMemoryWin32HandleInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExportSemaphoreCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExportSemaphoreWin32HandleInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExternalBufferProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExternalFenceProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExternalFormatANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExternalImageFormatProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExternalMemoryAcquireUnmodifiedEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExternalMemoryBufferCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExternalMemoryImageCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExternalMemoryImageCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkExternalSemaphoreProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_FENCE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkFenceCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkFenceGetFdInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkFenceGetWin32HandleInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkFilterCubicImageViewImageFormatPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkFormatProperties2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkFormatProperties3*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkFragmentShadingRateAttachmentInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkFrameBoundaryEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkFramebufferAttachmentImageInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkFramebufferAttachmentsCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkFramebufferCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkFramebufferMixedSamplesCombinationNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkGeneratedCommandsInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkGeneratedCommandsInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkGeneratedCommandsMemoryRequirementsInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkGeneratedCommandsMemoryRequirementsInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_PIPELINE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkGeneratedCommandsPipelineInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_SHADER_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkGeneratedCommandsShaderInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkGeometryAABBNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_GEOMETRY_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkGeometryNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkGeometryTrianglesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_GET_LATENCY_MARKER_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkGetLatencyMarkerInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkGraphicsPipelineCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkGraphicsPipelineLibraryCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkGraphicsPipelineShaderGroupsCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkGraphicsShaderGroupCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_HDR_METADATA_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkHdrMetadataEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_HDR_VIVID_DYNAMIC_METADATA_HUAWEI:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkHdrVividDynamicMetadataHUAWEI*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkHeadlessSurfaceCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkHostImageCopyDevicePerformanceQuery*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkHostImageLayoutTransitionInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkIOSSurfaceCreateInfoMVK*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_ALIGNMENT_CONTROL_CREATE_INFO_MESA:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageAlignmentControlCreateInfoMESA*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_BLIT_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageBlit2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageCaptureDescriptorDataInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageCompressionControlEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageCompressionPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_COPY_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageCopy2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageDrmFormatModifierExplicitCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageDrmFormatModifierListCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageDrmFormatModifierPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageFormatListCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageFormatProperties2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageMemoryBarrier*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageMemoryBarrier2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageMemoryRequirementsInfo2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImagePipeSurfaceCreateInfoFUCHSIA*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImagePlaneMemoryRequirementsInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageResolve2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageSparseMemoryRequirementsInfo2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageStencilUsageCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageSubresource2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageViewASTCDecodeModeEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageViewAddressPropertiesNVX*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageViewCaptureDescriptorDataInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageViewCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageViewHandleInfoNVX*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageViewMinLodCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageViewSampleWeightCreateInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageViewSlicedCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImageViewUsageCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImportAndroidHardwareBufferInfoANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImportFenceFdInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImportFenceWin32HandleInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImportMemoryFdInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImportMemoryHostPointerInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_METAL_HANDLE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImportMemoryMetalHandleInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImportMemoryWin32HandleInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImportMemoryWin32HandleInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImportMemoryZirconHandleInfoFUCHSIA*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImportSemaphoreFdInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImportSemaphoreWin32HandleInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkImportSemaphoreZirconHandleInfoFUCHSIA*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkIndirectCommandsLayoutCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkIndirectCommandsLayoutCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkIndirectCommandsLayoutTokenNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_PIPELINE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkIndirectExecutionSetPipelineInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkIndirectExecutionSetShaderInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_LAYOUT_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkIndirectExecutionSetShaderLayoutInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkInitializePerformanceApiInfoINTEL*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkInstanceCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_LATENCY_SLEEP_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkLatencySleepInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_LATENCY_SLEEP_MODE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkLatencySleepModeInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkLatencySubmissionPresentIdNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkLatencySurfaceCapabilitiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_LATENCY_TIMINGS_FRAME_REPORT_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkLatencyTimingsFrameReportNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkLayerSettingsCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMacOSSurfaceCreateInfoMVK*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMappedMemoryRange*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryAllocateFlagsInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryAllocateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_BARRIER:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryBarrier*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryBarrier2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryBarrierAccessFlags3KHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryDedicatedAllocateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryDedicatedRequirements*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryFdPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryGetAndroidHardwareBufferInfoANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryGetFdInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_GET_METAL_HANDLE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryGetMetalHandleInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryGetRemoteAddressInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryGetWin32HandleInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryGetZirconHandleInfoFUCHSIA*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryHostPointerPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_MAP_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryMapInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryMapPlacedInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_METAL_HANDLE_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryMetalHandlePropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryOpaqueCaptureAddressAllocateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryPriorityAllocateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryRequirements2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_UNMAP_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryUnmapInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryWin32HandlePropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMemoryZirconHandlePropertiesFUCHSIA*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMetalSurfaceCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMicromapBuildInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMicromapBuildSizesInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMicromapCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MICROMAP_VERSION_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMicromapVersionInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMultisamplePropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMultisampledRenderToSingleSampledInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMultiviewPerViewAttributesInfoNVX*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkMutableDescriptorTypeCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_OPAQUE_CAPTURE_DESCRIPTOR_DATA_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkOpaqueCaptureDescriptorDataCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_OPTICAL_FLOW_EXECUTE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkOpticalFlowExecuteInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkOpticalFlowImageFormatInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkOpticalFlowImageFormatPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkOpticalFlowSessionCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkOpticalFlowSessionCreatePrivateDataInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_OUT_OF_BAND_QUEUE_TYPE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkOutOfBandQueueTypeInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_FLAGS_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPartitionedAccelerationStructureFlagsNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_INSTANCES_INPUT_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPartitionedAccelerationStructureInstancesInputNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPastPresentationTimingEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPastPresentationTimingInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPastPresentationTimingPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PER_TILE_BEGIN_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPerTileBeginInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PER_TILE_END_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPerTileEndInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPerformanceConfigurationAcquireInfoINTEL*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPerformanceCounterARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPerformanceCounterDescriptionARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPerformanceCounterDescriptionKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPerformanceCounterKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPerformanceMarkerInfoINTEL*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPerformanceOverrideInfoINTEL*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPerformanceQuerySubmitInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPerformanceStreamMarkerInfoINTEL*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevice16BitStorageFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevice4444FormatsFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevice8BitStorageFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceASTCDecodeFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceAccelerationStructurePropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ANTI_LAG_FEATURES_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceAntiLagFeaturesAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMMAND_BUFFER_INHERITANCE_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCommandBufferInheritanceFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_OCCUPANCY_PRIORITY_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCooperativeMatrix2FeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCooperativeMatrix2PropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCooperativeVectorFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCooperativeVectorPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCornerSampledImageFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCubicClampFeaturesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCubicWeightsFeaturesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCustomBorderColorPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_RESOLVE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceCustomResolveFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_FEATURES_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDataGraphFeaturesARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_MODEL_FEATURES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDataGraphModelFeaturesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_CONTROL_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDepthClampControlFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDepthClampZeroOneFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDepthClipControlFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDepthStencilResolveProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_DENSITY_MAP_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDescriptorBufferFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDescriptorBufferPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDisplacementMicromapFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDisplacementMicromapPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDriverProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDrmPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDynamicRenderingFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDynamicRenderingLocalReadFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceExclusiveScissorFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState3PropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceExternalBufferInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceExternalFenceInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceExternalFormatResolvePropertiesANDROID*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceExternalImageFormatInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceExternalSemaphoreInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFaultFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFeatures2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFloatControlsProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FORMAT_PACK_FEATURES_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFormatPackFeaturesARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_FEATURES_VALVE:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_PROPERTIES_VALVE:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFragmentShadingRatePropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceFrameBoundaryFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceGlobalPriorityQueryFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceGroupProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HDR_VIVID_FEATURES_HUAWEI:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceHdrVividFeaturesHUAWEI*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceHostImageCopyFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceHostImageCopyProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceHostQueryResetFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceIDProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_FEATURES_MESA:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImageAlignmentControlFeaturesMESA*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_PROPERTIES_MESA:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImageAlignmentControlPropertiesMESA*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImageFormatInfo2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImageProcessing2FeaturesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImageProcessing2PropertiesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImageProcessingFeaturesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImageProcessingPropertiesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImageRobustnessFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImageViewImageFormatInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceImagelessFramebufferFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceIndexTypeUint8Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INTERNALLY_SYNCHRONIZED_QUEUES_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceLayeredApiPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_LIST_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceLayeredApiPropertiesListKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_VULKAN_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceLayeredDriverPropertiesMSFT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceLineRasterizationFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceLineRasterizationProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance10FeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance10PropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance3Properties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance4Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance4Properties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance5Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance5Properties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance6Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance6Properties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance7FeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance7PropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance8FeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance9FeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMaintenance9PropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMapMemoryPlacedFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMapMemoryPlacedPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMemoryDecompressionFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMemoryDecompressionPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMemoryProperties2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMultiDrawFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMultiDrawPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMultiviewFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMultiviewProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceNestedCommandBufferFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceNestedCommandBufferPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceOpacityMicromapPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceOpticalFlowFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceOpticalFlowPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePCIBusInfoPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePerStageDescriptorSetFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_FEATURES_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePerformanceCountersByRegionFeaturesARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_PROPERTIES_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePerformanceCountersByRegionPropertiesARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePerformanceQueryFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePerformanceQueryPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePipelineBinaryFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePipelineBinaryPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CACHE_INCREMENTAL_MODE_FEATURES_SEC:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePipelineCreationCacheControlFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_OPACITY_MICROMAP_FEATURES_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePipelineOpacityMicromapFeaturesARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePipelineProtectedAccessFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePipelineRobustnessFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePipelineRobustnessProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePointClippingProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePortabilitySubsetPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePresentBarrierFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_2_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePresentId2FeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePresentIdFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_METERING_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePresentMeteringFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_TIMING_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePresentTimingFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_2_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePresentWait2FeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePresentWaitFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePrivateDataFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceProperties2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceProtectedMemoryFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceProtectedMemoryProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceProvokingVertexFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceProvokingVertexPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_CONSTANT_BANK_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePushConstantBankFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_CONSTANT_BANK_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePushConstantBankPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDevicePushDescriptorProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_INFO_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRawAccessChainsFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRayQueryFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_LINEAR_SWEPT_SPHERES_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingPipelinePropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRayTracingValidationFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRenderPassStripedFeaturesARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRenderPassStripedPropertiesARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRobustness2FeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceRobustness2PropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSampleLocationsPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSamplerFilterMinmaxProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceScalarBlockLayoutFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSchedulingControlsFeaturesARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSchedulingControlsPropertiesARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_64_BIT_INDEXING_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShader64BitIndexingFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderAtomicInt64Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_BFLOAT16_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderBfloat16FeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderClockFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderCoreProperties2AMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderDrawParametersFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderExpectAssumeFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderFloat16Int8Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT8_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderFloat8FeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderFloatControls2Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FMA_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderFmaFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_LONG_VECTOR_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderLongVectorFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_LONG_VECTOR_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderLongVectorPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderObjectFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderObjectPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderQuadControlFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_RELAXED_EXTENDED_INSTRUCTION_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_REPLICATED_COMPOSITES_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_PARTITIONED_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderSubgroupRotateFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderTerminateInvocationFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderTileImageFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderTileImagePropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNIFORM_BUFFER_UNSIZED_ARRAY_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNTYPED_POINTERS_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShaderUntypedPointersFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShadingRateImageFeaturesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceShadingRateImagePropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSparseImageFormatInfo2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSubgroupProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSurfaceInfo2KHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceSynchronization2Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_3D_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_FEATURES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTileMemoryHeapFeaturesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_PROPERTIES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTileMemoryHeapPropertiesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_FEATURES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTileShadingFeaturesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_PROPERTIES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTileShadingPropertiesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceToolProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceTransformFeedbackPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFIED_IMAGE_LAYOUTS_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVariablePointersFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_ROBUSTNESS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_DECODE_VP9_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVideoDecodeVP9FeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_AV1_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVideoEncodeAV1FeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_INTRA_REFRESH_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUANTIZATION_MAP_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_RGB_CONVERSION_FEATURES_VALVE:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVideoFormatInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVideoMaintenance1FeaturesKHR*>(base), 1, unwrap_memory));
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
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVulkan13Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVulkan13Properties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVulkan14Features*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVulkan14Properties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceVulkanMemoryModelFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_DEVICE_MEMORY_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_BINARY_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineBinaryCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_BINARY_DATA_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineBinaryDataInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_BINARY_HANDLES_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineBinaryHandlesInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_BINARY_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineBinaryInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_BINARY_KEY_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineBinaryKeyKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineCacheCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineColorBlendStateCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineColorWriteCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineCompilerControlCreateInfoAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineCoverageModulationStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineCoverageReductionStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineCoverageToColorStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineCreateFlags2CreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineCreationFeedbackCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineDepthStencilStateCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineDiscardRectangleStateCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineDynamicStateCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineExecutableInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineExecutableInternalRepresentationKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineExecutablePropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineExecutableStatisticKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_DENSITY_MAP_LAYERED_CREATE_INFO_VALVE:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineFragmentDensityMapLayeredCreateInfoVALVE*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineFragmentShadingRateEnumStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineFragmentShadingRateStateCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineIndirectDeviceAddressInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineInputAssemblyStateCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineLayoutCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineLibraryCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineMultisampleStateCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineRasterizationConservativeStateCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineRasterizationDepthClipStateCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineRasterizationLineStateCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineRasterizationStateCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineRasterizationStateRasterizationOrderAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineRasterizationStateStreamCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineRenderingCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineRobustnessCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineSampleLocationsStateCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineShaderStageCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineShaderStageModuleIdentifierCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineShaderStageRequiredSubgroupSizeCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineTessellationDomainOriginStateCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineTessellationStateCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineVertexInputDivisorStateCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineVertexInputStateCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLAMP_CONTROL_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineViewportDepthClampControlCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineViewportDepthClipControlCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineViewportShadingRateImageStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineViewportStateCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineViewportSwizzleStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPipelineViewportWScalingStateCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPresentFrameTokenGGP*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PRESENT_ID_2_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPresentId2KHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PRESENT_ID_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPresentIdKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PRESENT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPresentInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPresentRegionsKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPresentTimesInfoGOOGLE*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PRESENT_TIMING_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPresentTimingInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PRESENT_TIMING_SURFACE_CAPABILITIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPresentTimingSurfaceCapabilitiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PRESENT_TIMINGS_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPresentTimingsInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PRESENT_WAIT_2_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPresentWait2InfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPrivateDataSlotCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkProtectedSubmitInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PUSH_CONSTANT_BANK_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPushConstantBankInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PUSH_CONSTANTS_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPushConstantsInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkPushDescriptorSetInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkQueryLowLatencySupportNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkQueryPoolCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkQueryPoolPerformanceCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkQueryPoolPerformanceQueryCreateInfoINTEL*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkQueryPoolVideoEncodeFeedbackCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkQueueFamilyCheckpointProperties2NV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkQueueFamilyCheckpointPropertiesNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_PROPERTIES_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkQueueFamilyDataGraphProcessingEnginePropertiesARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROPERTIES_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkQueueFamilyDataGraphPropertiesARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkQueueFamilyGlobalPriorityProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_OWNERSHIP_TRANSFER_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkQueueFamilyOwnershipTransferPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkQueueFamilyProperties2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkQueueFamilyQueryResultStatusPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkQueueFamilyVideoPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRayTracingPipelineCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRayTracingPipelineCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRayTracingPipelineInterfaceCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRayTracingShaderGroupCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRayTracingShaderGroupCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RELEASE_CAPTURED_PIPELINE_DATA_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkReleaseCapturedPipelineDataInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkReleaseSwapchainImagesInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassAttachmentBeginInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassBeginInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassCreateInfo2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassCreationControlEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassCreationFeedbackCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassFragmentDensityMapCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassFragmentDensityMapOffsetEndInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassInputAttachmentAspectCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassMultiviewCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_PERFORMANCE_COUNTERS_BY_REGION_BEGIN_INFO_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassPerformanceCountersByRegionBeginInfoARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassSampleLocationsBeginInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassStripeBeginInfoARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_INFO_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassStripeInfoARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassStripeSubmitInfoARM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassSubpassFeedbackCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_TILE_SHADING_CREATE_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassTileShadingCreateInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderPassTransformBeginInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDERING_AREA_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderingAreaInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_FLAGS_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderingAttachmentFlagsInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderingAttachmentInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderingAttachmentLocationInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDERING_END_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderingEndInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderingFragmentDensityMapAttachmentInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDERING_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderingInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkRenderingInputAttachmentIndexInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkResolveImageInfo2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_RESOLVE_IMAGE_MODE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkResolveImageModeInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSampleLocationsInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSamplerBlockMatchWindowCreateInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSamplerBorderColorComponentMappingCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSamplerCaptureDescriptorDataInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSamplerCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSamplerCubicWeightsCreateInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSamplerCustomBorderColorCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSamplerReductionModeCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSamplerYcbcrConversionCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSamplerYcbcrConversionImageFormatProperties*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSamplerYcbcrConversionInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SCREEN_SURFACE_CREATE_INFO_QNX:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkScreenSurfaceCreateInfoQNX*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSemaphoreCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSemaphoreGetFdInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSemaphoreGetWin32HandleInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSemaphoreGetZirconHandleInfoFUCHSIA*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSemaphoreSignalInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSemaphoreSubmitInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSemaphoreTypeCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSemaphoreWaitInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SET_DESCRIPTOR_BUFFER_OFFSETS_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSetDescriptorBufferOffsetsInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SET_LATENCY_MARKER_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSetLatencyMarkerInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SET_PRESENT_CONFIG_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSetPresentConfigNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkShaderCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkShaderModuleCreateInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkShaderModuleIdentifierEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSharedPresentSurfaceCapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSparseImageFormatProperties2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSparseImageMemoryRequirements2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkStreamDescriptorSurfaceCreateInfoGGP*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SUBMIT_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSubmitInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SUBMIT_INFO_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSubmitInfo2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSubpassBeginInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSubpassDependency2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSubpassDescription2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSubpassDescriptionDepthStencilResolve*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SUBPASS_END_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSubpassEndInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSubpassResolvePerformanceQueryEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSubresourceHostMemcpySize*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSubresourceLayout2*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSurfaceCapabilities2EXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSurfaceCapabilities2KHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSurfaceCapabilitiesFullScreenExclusiveEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSurfaceCapabilitiesPresentBarrierNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_ID_2_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSurfaceCapabilitiesPresentId2KHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_WAIT_2_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSurfaceCapabilitiesPresentWait2KHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSurfaceFormat2KHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSurfaceFullScreenExclusiveInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSurfaceFullScreenExclusiveWin32InfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSurfacePresentModeCompatibilityKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSurfacePresentModeKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSurfacePresentScalingCapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSurfaceProtectedCapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SWAPCHAIN_CALIBRATED_TIMESTAMP_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSwapchainCalibratedTimestampInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSwapchainCounterCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSwapchainCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSwapchainDisplayNativeHdrCreateInfoAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSwapchainLatencyCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSwapchainPresentBarrierCreateInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSwapchainPresentFenceInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSwapchainPresentModeInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSwapchainPresentModesCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSwapchainPresentScalingCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SWAPCHAIN_TIME_DOMAIN_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSwapchainTimeDomainPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_SWAPCHAIN_TIMING_PROPERTIES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkSwapchainTimingPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkTextureLODGatherFormatPropertiesAMD*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_TILE_MEMORY_BIND_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkTileMemoryBindInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_TILE_MEMORY_REQUIREMENTS_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkTileMemoryRequirementsQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_TILE_MEMORY_SIZE_INFO_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkTileMemorySizeInfoQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkTilePropertiesQCOM*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkTimelineSemaphoreSubmitInfo*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkValidationCacheCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkValidationFeaturesEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkValidationFlagsEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVertexInputAttributeDescription2EXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVertexInputBindingDescription2EXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkViSurfaceCreateInfoNN*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoBeginCodingInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoCapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoCodingControlInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoDecodeAV1CapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoDecodeAV1DpbSlotInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoDecodeAV1PictureInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoDecodeAV1ProfileInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoDecodeAV1SessionParametersCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoDecodeCapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoDecodeH264CapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoDecodeH264DpbSlotInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoDecodeH264PictureInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoDecodeH264ProfileInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoDecodeH264SessionParametersAddInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoDecodeH264SessionParametersCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoDecodeInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoDecodeUsageInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoDecodeVP9CapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PICTURE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoDecodeVP9PictureInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PROFILE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoDecodeVP9ProfileInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeAV1CapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeAV1DpbSlotInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_GOP_REMAINING_FRAME_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeAV1GopRemainingFrameInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PICTURE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeAV1PictureInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PROFILE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeAV1ProfileInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUALITY_LEVEL_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeAV1QualityLevelPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUANTIZATION_MAP_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeAV1QuantizationMapCapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeAV1RateControlInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_LAYER_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeAV1RateControlLayerInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeAV1SessionCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeAV1SessionParametersCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeCapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeH264CapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeH264DpbSlotInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeH264GopRemainingFrameInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeH264NaluSliceInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeH264PictureInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeH264ProfileInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeH264QualityLevelPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUANTIZATION_MAP_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeH264QuantizationMapCapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeH264RateControlInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeH264RateControlLayerInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeH264SessionCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeH264SessionParametersAddInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeH264SessionParametersCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeH264SessionParametersFeedbackInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeH264SessionParametersGetInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUANTIZATION_MAP_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeH265QuantizationMapCapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeIntraRefreshCapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeIntraRefreshInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_PROFILE_RGB_CONVERSION_INFO_VALVE:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeProfileRgbConversionInfoVALVE*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeQualityLevelInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeQualityLevelPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_CAPABILITIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeQuantizationMapCapabilitiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeQuantizationMapInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_SESSION_PARAMETERS_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeRateControlInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeRateControlLayerInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RGB_CONVERSION_CAPABILITIES_VALVE:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeRgbConversionCapabilitiesVALVE*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_INTRA_REFRESH_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeSessionIntraRefreshCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeSessionParametersFeedbackInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeSessionParametersGetInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_RGB_CONVERSION_CREATE_INFO_VALVE:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeSessionRgbConversionCreateInfoVALVE*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEncodeUsageInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoEndCodingInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_FORMAT_AV1_QUANTIZATION_MAP_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoFormatAV1QuantizationMapPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_FORMAT_H265_QUANTIZATION_MAP_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoFormatH265QuantizationMapPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoFormatPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_FORMAT_QUANTIZATION_MAP_PROPERTIES_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoFormatQuantizationMapPropertiesKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoInlineQueryInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoPictureResourceInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoProfileInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoProfileListInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_INTRA_REFRESH_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoReferenceIntraRefreshInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoReferenceSlotInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoSessionCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoSessionMemoryRequirementsKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoSessionParametersCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkVideoSessionParametersUpdateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkWaylandSurfaceCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkWin32SurfaceCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkWriteDescriptorSetInlineUniformBlock*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_PARTITIONED_ACCELERATION_STRUCTURE_NV:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkWriteDescriptorSetPartitionedAccelerationStructureNV*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_PIPELINE_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkWriteIndirectExecutionSetPipelineEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_SHADER_EXT:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkWriteIndirectExecutionSetShaderEXT*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkXcbSurfaceCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    case VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR:
        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkXlibSurfaceCreateInfoKHR*>(base), 1, unwrap_memory));
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
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkAccelerationStructureBuildGeometryInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkAccelerationStructureCaptureDescriptorDataInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkAccelerationStructureCreateInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkAccelerationStructureCreateInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkAccelerationStructureDeviceAddressInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkAccelerationStructureGeometryTrianglesDataKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkAccelerationStructureInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkAccelerationStructureMemoryRequirementsInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkAccelerationStructureTrianglesDisplacementMicromapNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkAccelerationStructureTrianglesOpacityMicromapEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkAcquireNextImageInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkBindAccelerationStructureMemoryInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkBindBufferMemoryInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_DATA_GRAPH_PIPELINE_SESSION_MEMORY_INFO_ARM:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkBindDataGraphPipelineSessionMemoryInfoARM*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkBindDescriptorBufferEmbeddedSamplersInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_SETS_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkBindDescriptorSetsInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkBindImageMemoryInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_SPARSE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkBindSparseInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkBindVideoSessionMemoryInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkBlitImageInfo2*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_BUFFER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkBufferCaptureDescriptorDataInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkBufferDeviceAddressInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkBufferMemoryBarrier*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkBufferMemoryBarrier2*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkBufferMemoryRequirementsInfo2*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkBufferViewCreateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkCalibratedTimestampInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkCommandBufferAllocateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkCommandBufferBeginInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkCommandBufferInheritanceInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkCommandBufferSubmitInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkComputePipelineCreateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkConditionalRenderingBeginInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkCopyAccelerationStructureInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkCopyAccelerationStructureToMemoryInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkCopyBufferInfo2*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkCopyBufferToImageInfo2*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkCopyDescriptorSet*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkCopyImageInfo2*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkCopyImageToBufferInfo2*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkCopyImageToImageInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkCopyMemoryToAccelerationStructureInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INDIRECT_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkCopyMemoryToImageIndirectInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkCopyMemoryToMicromapInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkCopyMicromapInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkCopyMicromapToMemoryInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CREATE_INFO_ARM:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDataGraphPipelineCreateInfoARM*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_INFO_ARM:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDataGraphPipelineInfoARM*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_REQUIREMENTS_INFO_ARM:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDataGraphPipelineSessionBindPointRequirementsInfoARM*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_CREATE_INFO_ARM:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDataGraphPipelineSessionCreateInfoARM*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_MEMORY_REQUIREMENTS_INFO_ARM:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDataGraphPipelineSessionMemoryRequirementsInfoARM*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SHADER_MODULE_CREATE_INFO_ARM:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDataGraphPipelineShaderModuleCreateInfoARM*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEPENDENCY_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDependencyInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDescriptorBufferBindingInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_PUSH_DESCRIPTOR_BUFFER_HANDLE_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDescriptorBufferBindingPushDescriptorBufferHandleEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDescriptorSetAllocateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDescriptorSetBindingReferenceVALVE*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDescriptorSetLayoutCreateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDescriptorUpdateTemplateCreateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDeviceCreateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDeviceImageMemoryRequirements*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_IMAGE_SUBRESOURCE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDeviceImageSubresourceInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDeviceMemoryOpaqueCaptureAddressInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDisplayModeProperties2KHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDisplayPlaneInfo2KHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDisplayPlaneProperties2KHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDisplayProperties2KHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkDisplaySurfaceCreateInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkFenceGetFdInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkFenceGetWin32HandleInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkFrameBoundaryEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkFramebufferCreateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkGeneratedCommandsInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkGeneratedCommandsInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkGeneratedCommandsMemoryRequirementsInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkGeneratedCommandsMemoryRequirementsInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_PIPELINE_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkGeneratedCommandsPipelineInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_SHADER_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkGeneratedCommandsShaderInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkGeometryAABBNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_GEOMETRY_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkGeometryNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkGeometryTrianglesNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkGraphicsPipelineCreateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkGraphicsPipelineShaderGroupsCreateInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkGraphicsShaderGroupCreateInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkHostImageLayoutTransitionInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkImageCaptureDescriptorDataInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkImageCreateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkImageMemoryBarrier*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkImageMemoryBarrier2*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkImageMemoryRequirementsInfo2*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkImageSparseMemoryRequirementsInfo2*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkImageViewCaptureDescriptorDataInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkImageViewCreateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkImageViewHandleInfoNVX*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkImportFenceFdInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkImportFenceWin32HandleInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkImportSemaphoreFdInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkImportSemaphoreWin32HandleInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkImportSemaphoreZirconHandleInfoFUCHSIA*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkIndirectCommandsLayoutCreateInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkIndirectCommandsLayoutCreateInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkIndirectCommandsLayoutTokenNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_PIPELINE_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkIndirectExecutionSetPipelineInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkIndirectExecutionSetShaderInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_LAYOUT_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkIndirectExecutionSetShaderLayoutInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_LATENCY_SLEEP_INFO_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkLatencySleepInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkMappedMemoryRange*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkMemoryAllocateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkMemoryDedicatedAllocateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkMemoryGetAndroidHardwareBufferInfoANDROID*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkMemoryGetFdInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_GET_METAL_HANDLE_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkMemoryGetMetalHandleInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkMemoryGetRemoteAddressInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkMemoryGetWin32HandleInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkMemoryGetZirconHandleInfoFUCHSIA*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_MAP_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkMemoryMapInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_UNMAP_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkMemoryUnmapInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkMicromapBuildInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkMicromapCreateInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkPastPresentationTimingInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkPhysicalDeviceGroupProperties*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkPhysicalDeviceSurfaceInfo2KHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_CREATE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkPipelineBinaryCreateInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_DATA_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkPipelineBinaryDataInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_HANDLES_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkPipelineBinaryHandlesInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkPipelineBinaryInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkPipelineExecutableInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkPipelineIndirectDeviceAddressInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkPipelineInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkPipelineLayoutCreateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkPipelineLibraryCreateInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkPipelineShaderStageCreateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_PRESENT_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkPresentInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_PUSH_CONSTANTS_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkPushConstantsInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkPushDescriptorSetInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkRayTracingPipelineCreateInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkRayTracingPipelineCreateInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_RELEASE_CAPTURED_PIPELINE_DATA_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkReleaseCapturedPipelineDataInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkReleaseSwapchainImagesInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkRenderPassAttachmentBeginInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkRenderPassBeginInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkRenderPassStripeSubmitInfoARM*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkRenderingAttachmentInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkRenderingFragmentDensityMapAttachmentInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDERING_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkRenderingInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkResolveImageInfo2*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SAMPLER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkSamplerCaptureDescriptorDataInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkSamplerCreateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkSamplerYcbcrConversionInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkSemaphoreGetFdInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkSemaphoreGetWin32HandleInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkSemaphoreGetZirconHandleInfoFUCHSIA*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkSemaphoreSignalInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkSemaphoreSubmitInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkSemaphoreWaitInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SET_DESCRIPTOR_BUFFER_OFFSETS_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkSetDescriptorBufferOffsetsInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkShaderCreateInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkShaderModuleCreateInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SUBMIT_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkSubmitInfo*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SUBMIT_INFO_2:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkSubmitInfo2*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_CALIBRATED_TIMESTAMP_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkSwapchainCalibratedTimestampInfoEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkSwapchainCreateInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkSwapchainPresentFenceInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_TILE_MEMORY_BIND_INFO_QCOM:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkTileMemoryBindInfoQCOM*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkVideoBeginCodingInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkVideoDecodeInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkVideoEncodeInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkVideoEncodeQuantizationMapInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkVideoEncodeSessionParametersGetInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkVideoInlineQueryInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkVideoPictureResourceInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkVideoReferenceSlotInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkVideoSessionParametersCreateInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureKHR*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureNV*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_PIPELINE_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkWriteIndirectExecutionSetPipelineEXT*>(base), unwrap_memory);
        case VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_SHADER_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const VkWriteIndirectExecutionSetShaderEXT*>(base), unwrap_memory);
        }
    }

    return nullptr;
}

GFXRECON_END_NAMESPACE(vulkan_wrappers)
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
