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

#include "generated/generated_vulkan_struct_trackers.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)
GFXRECON_BEGIN_NAMESPACE(vulkan_trackers)

VkBufferMemoryBarrier* TrackStruct(const VkBufferMemoryBarrier* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBufferMemoryBarrier* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageMemoryBarrier* TrackStruct(const VkImageMemoryBarrier* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageMemoryBarrier* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMemoryBarrier* TrackStruct(const VkMemoryBarrier* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMemoryBarrier* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkApplicationInfo* TrackStruct(const VkApplicationInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkApplicationInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkInstanceCreateInfo* TrackStruct(const VkInstanceCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkInstanceCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->ppEnabledLayerNames)
    {
        unwrapped_struct->ppEnabledLayerNames = MakeUnwrapVulkanStructs(unwrapped_struct->ppEnabledLayerNames, unwrapped_struct->enabledLayerCount, unwrap_memory);
    }
    if (unwrapped_struct->ppEnabledExtensionNames)
    {
        unwrapped_struct->ppEnabledExtensionNames = MakeUnwrapVulkanStructs(unwrapped_struct->ppEnabledExtensionNames, unwrapped_struct->enabledExtensionCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceQueueCreateInfo* TrackStruct(const VkDeviceQueueCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceQueueCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pQueuePriorities)
    {
        unwrapped_struct->pQueuePriorities = MakeUnwrapVulkanStructs(unwrapped_struct->pQueuePriorities, unwrapped_struct->queueCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceCreateInfo* TrackStruct(const VkDeviceCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pQueueCreateInfos)
    {
        unwrapped_struct->pQueueCreateInfos = MakeUnwrapVulkanStructs(unwrapped_struct->pQueueCreateInfos, unwrapped_struct->queueCreateInfoCount, unwrap_memory);
    }
    if (unwrapped_struct->ppEnabledLayerNames)
    {
        unwrapped_struct->ppEnabledLayerNames = MakeUnwrapVulkanStructs(unwrapped_struct->ppEnabledLayerNames, unwrapped_struct->enabledLayerCount, unwrap_memory);
    }
    if (unwrapped_struct->ppEnabledExtensionNames)
    {
        unwrapped_struct->ppEnabledExtensionNames = MakeUnwrapVulkanStructs(unwrapped_struct->ppEnabledExtensionNames, unwrapped_struct->enabledExtensionCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSubmitInfo* TrackStruct(const VkSubmitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSubmitInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pWaitSemaphores)
    {
        unwrapped_struct->pWaitSemaphores = MakeUnwrapVulkanStructs(unwrapped_struct->pWaitSemaphores, unwrapped_struct->waitSemaphoreCount, unwrap_memory);
    }
    if (unwrapped_struct->pWaitDstStageMask)
    {
        unwrapped_struct->pWaitDstStageMask = MakeUnwrapVulkanStructs(unwrapped_struct->pWaitDstStageMask, unwrapped_struct->waitSemaphoreCount, unwrap_memory);
    }
    if (unwrapped_struct->pCommandBuffers)
    {
        unwrapped_struct->pCommandBuffers = MakeUnwrapVulkanStructs(unwrapped_struct->pCommandBuffers, unwrapped_struct->commandBufferCount, unwrap_memory);
    }
    if (unwrapped_struct->pSignalSemaphores)
    {
        unwrapped_struct->pSignalSemaphores = MakeUnwrapVulkanStructs(unwrapped_struct->pSignalSemaphores, unwrapped_struct->signalSemaphoreCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMappedMemoryRange* TrackStruct(const VkMappedMemoryRange* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMappedMemoryRange* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMemoryAllocateInfo* TrackStruct(const VkMemoryAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMemoryAllocateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBindSparseInfo* TrackStruct(const VkBindSparseInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBindSparseInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pWaitSemaphores)
    {
        unwrapped_struct->pWaitSemaphores = MakeUnwrapVulkanStructs(unwrapped_struct->pWaitSemaphores, unwrapped_struct->waitSemaphoreCount, unwrap_memory);
    }
    if (unwrapped_struct->pBufferBinds)
    {
        unwrapped_struct->pBufferBinds = MakeUnwrapVulkanStructs(unwrapped_struct->pBufferBinds, unwrapped_struct->bufferBindCount, unwrap_memory);
    }
    if (unwrapped_struct->pImageOpaqueBinds)
    {
        unwrapped_struct->pImageOpaqueBinds = MakeUnwrapVulkanStructs(unwrapped_struct->pImageOpaqueBinds, unwrapped_struct->imageOpaqueBindCount, unwrap_memory);
    }
    if (unwrapped_struct->pImageBinds)
    {
        unwrapped_struct->pImageBinds = MakeUnwrapVulkanStructs(unwrapped_struct->pImageBinds, unwrapped_struct->imageBindCount, unwrap_memory);
    }
    if (unwrapped_struct->pSignalSemaphores)
    {
        unwrapped_struct->pSignalSemaphores = MakeUnwrapVulkanStructs(unwrapped_struct->pSignalSemaphores, unwrapped_struct->signalSemaphoreCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkFenceCreateInfo* TrackStruct(const VkFenceCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkFenceCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSemaphoreCreateInfo* TrackStruct(const VkSemaphoreCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSemaphoreCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkEventCreateInfo* TrackStruct(const VkEventCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkEventCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkQueryPoolCreateInfo* TrackStruct(const VkQueryPoolCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkQueryPoolCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBufferCreateInfo* TrackStruct(const VkBufferCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBufferCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pQueueFamilyIndices)
    {
        unwrapped_struct->pQueueFamilyIndices = MakeUnwrapVulkanStructs(unwrapped_struct->pQueueFamilyIndices, unwrapped_struct->queueFamilyIndexCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBufferViewCreateInfo* TrackStruct(const VkBufferViewCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBufferViewCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageCreateInfo* TrackStruct(const VkImageCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pQueueFamilyIndices)
    {
        unwrapped_struct->pQueueFamilyIndices = MakeUnwrapVulkanStructs(unwrapped_struct->pQueueFamilyIndices, unwrapped_struct->queueFamilyIndexCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageViewCreateInfo* TrackStruct(const VkImageViewCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageViewCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkShaderModuleCreateInfo* TrackStruct(const VkShaderModuleCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkShaderModuleCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pCode)
    {
        unwrapped_struct->pCode = MakeUnwrapVulkanStructs(unwrapped_struct->pCode, unwrapped_struct->codeSize / 4, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineCacheCreateInfo* TrackStruct(const VkPipelineCacheCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineCacheCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pInitialData)
    {
        unwrapped_struct->pInitialData = MakeUnwrapVulkanStructs<uint8_t>(reinterpret_cast<const uint8_t*>(unwrapped_struct->pInitialData), unwrapped_struct->initialDataSize, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineShaderStageCreateInfo* TrackStruct(const VkPipelineShaderStageCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineShaderStageCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkComputePipelineCreateInfo* TrackStruct(const VkComputePipelineCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkComputePipelineCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineVertexInputStateCreateInfo* TrackStruct(const VkPipelineVertexInputStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineVertexInputStateCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pVertexBindingDescriptions)
    {
        unwrapped_struct->pVertexBindingDescriptions = MakeUnwrapVulkanStructs(unwrapped_struct->pVertexBindingDescriptions, unwrapped_struct->vertexBindingDescriptionCount, unwrap_memory);
    }
    if (unwrapped_struct->pVertexAttributeDescriptions)
    {
        unwrapped_struct->pVertexAttributeDescriptions = MakeUnwrapVulkanStructs(unwrapped_struct->pVertexAttributeDescriptions, unwrapped_struct->vertexAttributeDescriptionCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineInputAssemblyStateCreateInfo* TrackStruct(const VkPipelineInputAssemblyStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineInputAssemblyStateCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineTessellationStateCreateInfo* TrackStruct(const VkPipelineTessellationStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineTessellationStateCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineViewportStateCreateInfo* TrackStruct(const VkPipelineViewportStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineViewportStateCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pViewports)
    {
        unwrapped_struct->pViewports = MakeUnwrapVulkanStructs(unwrapped_struct->pViewports, unwrapped_struct->viewportCount, unwrap_memory);
    }
    if (unwrapped_struct->pScissors)
    {
        unwrapped_struct->pScissors = MakeUnwrapVulkanStructs(unwrapped_struct->pScissors, unwrapped_struct->scissorCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineRasterizationStateCreateInfo* TrackStruct(const VkPipelineRasterizationStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineRasterizationStateCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineMultisampleStateCreateInfo* TrackStruct(const VkPipelineMultisampleStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineMultisampleStateCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pSampleMask)
    {
        unwrapped_struct->pSampleMask = MakeUnwrapVulkanStructs(unwrapped_struct->pSampleMask, (unwrapped_struct->rasterizationSamples + 31) / 32, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineDepthStencilStateCreateInfo* TrackStruct(const VkPipelineDepthStencilStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineDepthStencilStateCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineColorBlendStateCreateInfo* TrackStruct(const VkPipelineColorBlendStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineColorBlendStateCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pAttachments)
    {
        unwrapped_struct->pAttachments = MakeUnwrapVulkanStructs(unwrapped_struct->pAttachments, unwrapped_struct->attachmentCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineDynamicStateCreateInfo* TrackStruct(const VkPipelineDynamicStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineDynamicStateCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pDynamicStates)
    {
        unwrapped_struct->pDynamicStates = MakeUnwrapVulkanStructs(unwrapped_struct->pDynamicStates, unwrapped_struct->dynamicStateCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkGraphicsPipelineCreateInfo* TrackStruct(const VkGraphicsPipelineCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkGraphicsPipelineCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pStages)
    {
        unwrapped_struct->pStages = MakeUnwrapVulkanStructs(unwrapped_struct->pStages, unwrapped_struct->stageCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineLayoutCreateInfo* TrackStruct(const VkPipelineLayoutCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineLayoutCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pSetLayouts)
    {
        unwrapped_struct->pSetLayouts = MakeUnwrapVulkanStructs(unwrapped_struct->pSetLayouts, unwrapped_struct->setLayoutCount, unwrap_memory);
    }
    if (unwrapped_struct->pPushConstantRanges)
    {
        unwrapped_struct->pPushConstantRanges = MakeUnwrapVulkanStructs(unwrapped_struct->pPushConstantRanges, unwrapped_struct->pushConstantRangeCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSamplerCreateInfo* TrackStruct(const VkSamplerCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSamplerCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCopyDescriptorSet* TrackStruct(const VkCopyDescriptorSet* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCopyDescriptorSet* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDescriptorPoolCreateInfo* TrackStruct(const VkDescriptorPoolCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDescriptorPoolCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pPoolSizes)
    {
        unwrapped_struct->pPoolSizes = MakeUnwrapVulkanStructs(unwrapped_struct->pPoolSizes, unwrapped_struct->poolSizeCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDescriptorSetAllocateInfo* TrackStruct(const VkDescriptorSetAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDescriptorSetAllocateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pSetLayouts)
    {
        unwrapped_struct->pSetLayouts = MakeUnwrapVulkanStructs(unwrapped_struct->pSetLayouts, unwrapped_struct->descriptorSetCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDescriptorSetLayoutCreateInfo* TrackStruct(const VkDescriptorSetLayoutCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDescriptorSetLayoutCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pBindings)
    {
        unwrapped_struct->pBindings = MakeUnwrapVulkanStructs(unwrapped_struct->pBindings, unwrapped_struct->bindingCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkWriteDescriptorSet* TrackStruct(const VkWriteDescriptorSet* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkWriteDescriptorSet* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pImageInfo)
    {
        unwrapped_struct->pImageInfo = MakeUnwrapVulkanStructs(unwrapped_struct->pImageInfo, unwrapped_struct->descriptorCount, unwrap_memory);
    }
    if (unwrapped_struct->pBufferInfo)
    {
        unwrapped_struct->pBufferInfo = MakeUnwrapVulkanStructs(unwrapped_struct->pBufferInfo, unwrapped_struct->descriptorCount, unwrap_memory);
    }
    if (unwrapped_struct->pTexelBufferView)
    {
        unwrapped_struct->pTexelBufferView = MakeUnwrapVulkanStructs(unwrapped_struct->pTexelBufferView, unwrapped_struct->descriptorCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkFramebufferCreateInfo* TrackStruct(const VkFramebufferCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkFramebufferCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pAttachments)
    {
        unwrapped_struct->pAttachments = MakeUnwrapVulkanStructs(unwrapped_struct->pAttachments, unwrapped_struct->attachmentCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRenderPassCreateInfo* TrackStruct(const VkRenderPassCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRenderPassCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pAttachments)
    {
        unwrapped_struct->pAttachments = MakeUnwrapVulkanStructs(unwrapped_struct->pAttachments, unwrapped_struct->attachmentCount, unwrap_memory);
    }
    if (unwrapped_struct->pSubpasses)
    {
        unwrapped_struct->pSubpasses = MakeUnwrapVulkanStructs(unwrapped_struct->pSubpasses, unwrapped_struct->subpassCount, unwrap_memory);
    }
    if (unwrapped_struct->pDependencies)
    {
        unwrapped_struct->pDependencies = MakeUnwrapVulkanStructs(unwrapped_struct->pDependencies, unwrapped_struct->dependencyCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCommandPoolCreateInfo* TrackStruct(const VkCommandPoolCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCommandPoolCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCommandBufferAllocateInfo* TrackStruct(const VkCommandBufferAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCommandBufferAllocateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCommandBufferInheritanceInfo* TrackStruct(const VkCommandBufferInheritanceInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCommandBufferInheritanceInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCommandBufferBeginInfo* TrackStruct(const VkCommandBufferBeginInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCommandBufferBeginInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRenderPassBeginInfo* TrackStruct(const VkRenderPassBeginInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRenderPassBeginInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pClearValues)
    {
        unwrapped_struct->pClearValues = MakeUnwrapVulkanStructs(unwrapped_struct->pClearValues, unwrapped_struct->clearValueCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceSubgroupProperties* TrackStruct(const VkPhysicalDeviceSubgroupProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceSubgroupProperties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBindBufferMemoryInfo* TrackStruct(const VkBindBufferMemoryInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBindBufferMemoryInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBindImageMemoryInfo* TrackStruct(const VkBindImageMemoryInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBindImageMemoryInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevice16BitStorageFeatures* TrackStruct(const VkPhysicalDevice16BitStorageFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevice16BitStorageFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMemoryDedicatedRequirements* TrackStruct(const VkMemoryDedicatedRequirements* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMemoryDedicatedRequirements* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMemoryDedicatedAllocateInfo* TrackStruct(const VkMemoryDedicatedAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMemoryDedicatedAllocateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMemoryAllocateFlagsInfo* TrackStruct(const VkMemoryAllocateFlagsInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMemoryAllocateFlagsInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceGroupRenderPassBeginInfo* TrackStruct(const VkDeviceGroupRenderPassBeginInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceGroupRenderPassBeginInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pDeviceRenderAreas)
    {
        unwrapped_struct->pDeviceRenderAreas = MakeUnwrapVulkanStructs(unwrapped_struct->pDeviceRenderAreas, unwrapped_struct->deviceRenderAreaCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceGroupCommandBufferBeginInfo* TrackStruct(const VkDeviceGroupCommandBufferBeginInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceGroupCommandBufferBeginInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceGroupSubmitInfo* TrackStruct(const VkDeviceGroupSubmitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceGroupSubmitInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pWaitSemaphoreDeviceIndices)
    {
        unwrapped_struct->pWaitSemaphoreDeviceIndices = MakeUnwrapVulkanStructs(unwrapped_struct->pWaitSemaphoreDeviceIndices, unwrapped_struct->waitSemaphoreCount, unwrap_memory);
    }
    if (unwrapped_struct->pCommandBufferDeviceMasks)
    {
        unwrapped_struct->pCommandBufferDeviceMasks = MakeUnwrapVulkanStructs(unwrapped_struct->pCommandBufferDeviceMasks, unwrapped_struct->commandBufferCount, unwrap_memory);
    }
    if (unwrapped_struct->pSignalSemaphoreDeviceIndices)
    {
        unwrapped_struct->pSignalSemaphoreDeviceIndices = MakeUnwrapVulkanStructs(unwrapped_struct->pSignalSemaphoreDeviceIndices, unwrapped_struct->signalSemaphoreCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceGroupBindSparseInfo* TrackStruct(const VkDeviceGroupBindSparseInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceGroupBindSparseInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBindBufferMemoryDeviceGroupInfo* TrackStruct(const VkBindBufferMemoryDeviceGroupInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBindBufferMemoryDeviceGroupInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pDeviceIndices)
    {
        unwrapped_struct->pDeviceIndices = MakeUnwrapVulkanStructs(unwrapped_struct->pDeviceIndices, unwrapped_struct->deviceIndexCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBindImageMemoryDeviceGroupInfo* TrackStruct(const VkBindImageMemoryDeviceGroupInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBindImageMemoryDeviceGroupInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pDeviceIndices)
    {
        unwrapped_struct->pDeviceIndices = MakeUnwrapVulkanStructs(unwrapped_struct->pDeviceIndices, unwrapped_struct->deviceIndexCount, unwrap_memory);
    }
    if (unwrapped_struct->pSplitInstanceBindRegions)
    {
        unwrapped_struct->pSplitInstanceBindRegions = MakeUnwrapVulkanStructs(unwrapped_struct->pSplitInstanceBindRegions, unwrapped_struct->splitInstanceBindRegionCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceGroupProperties* TrackStruct(const VkPhysicalDeviceGroupProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceGroupProperties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceGroupDeviceCreateInfo* TrackStruct(const VkDeviceGroupDeviceCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceGroupDeviceCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pPhysicalDevices)
    {
        unwrapped_struct->pPhysicalDevices = MakeUnwrapVulkanStructs(unwrapped_struct->pPhysicalDevices, unwrapped_struct->physicalDeviceCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBufferMemoryRequirementsInfo2* TrackStruct(const VkBufferMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBufferMemoryRequirementsInfo2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageMemoryRequirementsInfo2* TrackStruct(const VkImageMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageMemoryRequirementsInfo2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageSparseMemoryRequirementsInfo2* TrackStruct(const VkImageSparseMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageSparseMemoryRequirementsInfo2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMemoryRequirements2* TrackStruct(const VkMemoryRequirements2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMemoryRequirements2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSparseImageMemoryRequirements2* TrackStruct(const VkSparseImageMemoryRequirements2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSparseImageMemoryRequirements2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceFeatures2* TrackStruct(const VkPhysicalDeviceFeatures2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceFeatures2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceProperties2* TrackStruct(const VkPhysicalDeviceProperties2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceProperties2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkFormatProperties2* TrackStruct(const VkFormatProperties2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkFormatProperties2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageFormatProperties2* TrackStruct(const VkImageFormatProperties2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageFormatProperties2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceImageFormatInfo2* TrackStruct(const VkPhysicalDeviceImageFormatInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceImageFormatInfo2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkQueueFamilyProperties2* TrackStruct(const VkQueueFamilyProperties2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkQueueFamilyProperties2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMemoryProperties2* TrackStruct(const VkPhysicalDeviceMemoryProperties2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMemoryProperties2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSparseImageFormatProperties2* TrackStruct(const VkSparseImageFormatProperties2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSparseImageFormatProperties2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceSparseImageFormatInfo2* TrackStruct(const VkPhysicalDeviceSparseImageFormatInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceSparseImageFormatInfo2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevicePointClippingProperties* TrackStruct(const VkPhysicalDevicePointClippingProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevicePointClippingProperties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRenderPassInputAttachmentAspectCreateInfo* TrackStruct(const VkRenderPassInputAttachmentAspectCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRenderPassInputAttachmentAspectCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pAspectReferences)
    {
        unwrapped_struct->pAspectReferences = MakeUnwrapVulkanStructs(unwrapped_struct->pAspectReferences, unwrapped_struct->aspectReferenceCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageViewUsageCreateInfo* TrackStruct(const VkImageViewUsageCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageViewUsageCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineTessellationDomainOriginStateCreateInfo* TrackStruct(const VkPipelineTessellationDomainOriginStateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineTessellationDomainOriginStateCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRenderPassMultiviewCreateInfo* TrackStruct(const VkRenderPassMultiviewCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRenderPassMultiviewCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pViewMasks)
    {
        unwrapped_struct->pViewMasks = MakeUnwrapVulkanStructs(unwrapped_struct->pViewMasks, unwrapped_struct->subpassCount, unwrap_memory);
    }
    if (unwrapped_struct->pViewOffsets)
    {
        unwrapped_struct->pViewOffsets = MakeUnwrapVulkanStructs(unwrapped_struct->pViewOffsets, unwrapped_struct->dependencyCount, unwrap_memory);
    }
    if (unwrapped_struct->pCorrelationMasks)
    {
        unwrapped_struct->pCorrelationMasks = MakeUnwrapVulkanStructs(unwrapped_struct->pCorrelationMasks, unwrapped_struct->correlationMaskCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMultiviewFeatures* TrackStruct(const VkPhysicalDeviceMultiviewFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMultiviewFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMultiviewProperties* TrackStruct(const VkPhysicalDeviceMultiviewProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMultiviewProperties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceVariablePointersFeatures* TrackStruct(const VkPhysicalDeviceVariablePointersFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceVariablePointersFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceProtectedMemoryFeatures* TrackStruct(const VkPhysicalDeviceProtectedMemoryFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceProtectedMemoryFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceProtectedMemoryProperties* TrackStruct(const VkPhysicalDeviceProtectedMemoryProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceProtectedMemoryProperties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceQueueInfo2* TrackStruct(const VkDeviceQueueInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceQueueInfo2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkProtectedSubmitInfo* TrackStruct(const VkProtectedSubmitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkProtectedSubmitInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSamplerYcbcrConversionCreateInfo* TrackStruct(const VkSamplerYcbcrConversionCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSamplerYcbcrConversionCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSamplerYcbcrConversionInfo* TrackStruct(const VkSamplerYcbcrConversionInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSamplerYcbcrConversionInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBindImagePlaneMemoryInfo* TrackStruct(const VkBindImagePlaneMemoryInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBindImagePlaneMemoryInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImagePlaneMemoryRequirementsInfo* TrackStruct(const VkImagePlaneMemoryRequirementsInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImagePlaneMemoryRequirementsInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceSamplerYcbcrConversionFeatures* TrackStruct(const VkPhysicalDeviceSamplerYcbcrConversionFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceSamplerYcbcrConversionFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSamplerYcbcrConversionImageFormatProperties* TrackStruct(const VkSamplerYcbcrConversionImageFormatProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSamplerYcbcrConversionImageFormatProperties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDescriptorUpdateTemplateCreateInfo* TrackStruct(const VkDescriptorUpdateTemplateCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDescriptorUpdateTemplateCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pDescriptorUpdateEntries)
    {
        unwrapped_struct->pDescriptorUpdateEntries = MakeUnwrapVulkanStructs(unwrapped_struct->pDescriptorUpdateEntries, unwrapped_struct->descriptorUpdateEntryCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceExternalImageFormatInfo* TrackStruct(const VkPhysicalDeviceExternalImageFormatInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceExternalImageFormatInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkExternalImageFormatProperties* TrackStruct(const VkExternalImageFormatProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkExternalImageFormatProperties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceExternalBufferInfo* TrackStruct(const VkPhysicalDeviceExternalBufferInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceExternalBufferInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkExternalBufferProperties* TrackStruct(const VkExternalBufferProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkExternalBufferProperties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceIDProperties* TrackStruct(const VkPhysicalDeviceIDProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceIDProperties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkExternalMemoryImageCreateInfo* TrackStruct(const VkExternalMemoryImageCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkExternalMemoryImageCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkExternalMemoryBufferCreateInfo* TrackStruct(const VkExternalMemoryBufferCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkExternalMemoryBufferCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkExportMemoryAllocateInfo* TrackStruct(const VkExportMemoryAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkExportMemoryAllocateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceExternalFenceInfo* TrackStruct(const VkPhysicalDeviceExternalFenceInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceExternalFenceInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkExternalFenceProperties* TrackStruct(const VkExternalFenceProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkExternalFenceProperties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkExportFenceCreateInfo* TrackStruct(const VkExportFenceCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkExportFenceCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkExportSemaphoreCreateInfo* TrackStruct(const VkExportSemaphoreCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkExportSemaphoreCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceExternalSemaphoreInfo* TrackStruct(const VkPhysicalDeviceExternalSemaphoreInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceExternalSemaphoreInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkExternalSemaphoreProperties* TrackStruct(const VkExternalSemaphoreProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkExternalSemaphoreProperties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMaintenance3Properties* TrackStruct(const VkPhysicalDeviceMaintenance3Properties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMaintenance3Properties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDescriptorSetLayoutSupport* TrackStruct(const VkDescriptorSetLayoutSupport* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDescriptorSetLayoutSupport* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderDrawParametersFeatures* TrackStruct(const VkPhysicalDeviceShaderDrawParametersFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderDrawParametersFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceVulkan11Features* TrackStruct(const VkPhysicalDeviceVulkan11Features* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceVulkan11Features* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceVulkan11Properties* TrackStruct(const VkPhysicalDeviceVulkan11Properties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceVulkan11Properties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceVulkan12Features* TrackStruct(const VkPhysicalDeviceVulkan12Features* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceVulkan12Features* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceVulkan12Properties* TrackStruct(const VkPhysicalDeviceVulkan12Properties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceVulkan12Properties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageFormatListCreateInfo* TrackStruct(const VkImageFormatListCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageFormatListCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pViewFormats)
    {
        unwrapped_struct->pViewFormats = MakeUnwrapVulkanStructs(unwrapped_struct->pViewFormats, unwrapped_struct->viewFormatCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAttachmentDescription2* TrackStruct(const VkAttachmentDescription2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAttachmentDescription2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAttachmentReference2* TrackStruct(const VkAttachmentReference2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAttachmentReference2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSubpassDescription2* TrackStruct(const VkSubpassDescription2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSubpassDescription2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pInputAttachments)
    {
        unwrapped_struct->pInputAttachments = MakeUnwrapVulkanStructs(unwrapped_struct->pInputAttachments, unwrapped_struct->inputAttachmentCount, unwrap_memory);
    }
    if (unwrapped_struct->pColorAttachments)
    {
        unwrapped_struct->pColorAttachments = MakeUnwrapVulkanStructs(unwrapped_struct->pColorAttachments, unwrapped_struct->colorAttachmentCount, unwrap_memory);
    }
    if (unwrapped_struct->pResolveAttachments)
    {
        unwrapped_struct->pResolveAttachments = MakeUnwrapVulkanStructs(unwrapped_struct->pResolveAttachments, unwrapped_struct->colorAttachmentCount, unwrap_memory);
    }
    if (unwrapped_struct->pPreserveAttachments)
    {
        unwrapped_struct->pPreserveAttachments = MakeUnwrapVulkanStructs(unwrapped_struct->pPreserveAttachments, unwrapped_struct->preserveAttachmentCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSubpassDependency2* TrackStruct(const VkSubpassDependency2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSubpassDependency2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRenderPassCreateInfo2* TrackStruct(const VkRenderPassCreateInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRenderPassCreateInfo2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pAttachments)
    {
        unwrapped_struct->pAttachments = MakeUnwrapVulkanStructs(unwrapped_struct->pAttachments, unwrapped_struct->attachmentCount, unwrap_memory);
    }
    if (unwrapped_struct->pSubpasses)
    {
        unwrapped_struct->pSubpasses = MakeUnwrapVulkanStructs(unwrapped_struct->pSubpasses, unwrapped_struct->subpassCount, unwrap_memory);
    }
    if (unwrapped_struct->pDependencies)
    {
        unwrapped_struct->pDependencies = MakeUnwrapVulkanStructs(unwrapped_struct->pDependencies, unwrapped_struct->dependencyCount, unwrap_memory);
    }
    if (unwrapped_struct->pCorrelatedViewMasks)
    {
        unwrapped_struct->pCorrelatedViewMasks = MakeUnwrapVulkanStructs(unwrapped_struct->pCorrelatedViewMasks, unwrapped_struct->correlatedViewMaskCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSubpassBeginInfo* TrackStruct(const VkSubpassBeginInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSubpassBeginInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSubpassEndInfo* TrackStruct(const VkSubpassEndInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSubpassEndInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevice8BitStorageFeatures* TrackStruct(const VkPhysicalDevice8BitStorageFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevice8BitStorageFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDriverProperties* TrackStruct(const VkPhysicalDeviceDriverProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDriverProperties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderAtomicInt64Features* TrackStruct(const VkPhysicalDeviceShaderAtomicInt64Features* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderAtomicInt64Features* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderFloat16Int8Features* TrackStruct(const VkPhysicalDeviceShaderFloat16Int8Features* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderFloat16Int8Features* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceFloatControlsProperties* TrackStruct(const VkPhysicalDeviceFloatControlsProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceFloatControlsProperties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDescriptorSetLayoutBindingFlagsCreateInfo* TrackStruct(const VkDescriptorSetLayoutBindingFlagsCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDescriptorSetLayoutBindingFlagsCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pBindingFlags)
    {
        unwrapped_struct->pBindingFlags = MakeUnwrapVulkanStructs(unwrapped_struct->pBindingFlags, unwrapped_struct->bindingCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDescriptorIndexingFeatures* TrackStruct(const VkPhysicalDeviceDescriptorIndexingFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDescriptorIndexingFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDescriptorIndexingProperties* TrackStruct(const VkPhysicalDeviceDescriptorIndexingProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDescriptorIndexingProperties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDescriptorSetVariableDescriptorCountAllocateInfo* TrackStruct(const VkDescriptorSetVariableDescriptorCountAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDescriptorSetVariableDescriptorCountAllocateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pDescriptorCounts)
    {
        unwrapped_struct->pDescriptorCounts = MakeUnwrapVulkanStructs(unwrapped_struct->pDescriptorCounts, unwrapped_struct->descriptorSetCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDescriptorSetVariableDescriptorCountLayoutSupport* TrackStruct(const VkDescriptorSetVariableDescriptorCountLayoutSupport* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDescriptorSetVariableDescriptorCountLayoutSupport* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSubpassDescriptionDepthStencilResolve* TrackStruct(const VkSubpassDescriptionDepthStencilResolve* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSubpassDescriptionDepthStencilResolve* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDepthStencilResolveProperties* TrackStruct(const VkPhysicalDeviceDepthStencilResolveProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDepthStencilResolveProperties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceScalarBlockLayoutFeatures* TrackStruct(const VkPhysicalDeviceScalarBlockLayoutFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceScalarBlockLayoutFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageStencilUsageCreateInfo* TrackStruct(const VkImageStencilUsageCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageStencilUsageCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSamplerReductionModeCreateInfo* TrackStruct(const VkSamplerReductionModeCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSamplerReductionModeCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceSamplerFilterMinmaxProperties* TrackStruct(const VkPhysicalDeviceSamplerFilterMinmaxProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceSamplerFilterMinmaxProperties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceVulkanMemoryModelFeatures* TrackStruct(const VkPhysicalDeviceVulkanMemoryModelFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceVulkanMemoryModelFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceImagelessFramebufferFeatures* TrackStruct(const VkPhysicalDeviceImagelessFramebufferFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceImagelessFramebufferFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkFramebufferAttachmentImageInfo* TrackStruct(const VkFramebufferAttachmentImageInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkFramebufferAttachmentImageInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pViewFormats)
    {
        unwrapped_struct->pViewFormats = MakeUnwrapVulkanStructs(unwrapped_struct->pViewFormats, unwrapped_struct->viewFormatCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkFramebufferAttachmentsCreateInfo* TrackStruct(const VkFramebufferAttachmentsCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkFramebufferAttachmentsCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pAttachmentImageInfos)
    {
        unwrapped_struct->pAttachmentImageInfos = MakeUnwrapVulkanStructs(unwrapped_struct->pAttachmentImageInfos, unwrapped_struct->attachmentImageInfoCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRenderPassAttachmentBeginInfo* TrackStruct(const VkRenderPassAttachmentBeginInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRenderPassAttachmentBeginInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pAttachments)
    {
        unwrapped_struct->pAttachments = MakeUnwrapVulkanStructs(unwrapped_struct->pAttachments, unwrapped_struct->attachmentCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceUniformBufferStandardLayoutFeatures* TrackStruct(const VkPhysicalDeviceUniformBufferStandardLayoutFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceUniformBufferStandardLayoutFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* TrackStruct(const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* TrackStruct(const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAttachmentReferenceStencilLayout* TrackStruct(const VkAttachmentReferenceStencilLayout* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAttachmentReferenceStencilLayout* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAttachmentDescriptionStencilLayout* TrackStruct(const VkAttachmentDescriptionStencilLayout* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAttachmentDescriptionStencilLayout* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceHostQueryResetFeatures* TrackStruct(const VkPhysicalDeviceHostQueryResetFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceHostQueryResetFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceTimelineSemaphoreFeatures* TrackStruct(const VkPhysicalDeviceTimelineSemaphoreFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceTimelineSemaphoreFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceTimelineSemaphoreProperties* TrackStruct(const VkPhysicalDeviceTimelineSemaphoreProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceTimelineSemaphoreProperties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSemaphoreTypeCreateInfo* TrackStruct(const VkSemaphoreTypeCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSemaphoreTypeCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkTimelineSemaphoreSubmitInfo* TrackStruct(const VkTimelineSemaphoreSubmitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkTimelineSemaphoreSubmitInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pWaitSemaphoreValues)
    {
        unwrapped_struct->pWaitSemaphoreValues = MakeUnwrapVulkanStructs(unwrapped_struct->pWaitSemaphoreValues, unwrapped_struct->waitSemaphoreValueCount, unwrap_memory);
    }
    if (unwrapped_struct->pSignalSemaphoreValues)
    {
        unwrapped_struct->pSignalSemaphoreValues = MakeUnwrapVulkanStructs(unwrapped_struct->pSignalSemaphoreValues, unwrapped_struct->signalSemaphoreValueCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSemaphoreWaitInfo* TrackStruct(const VkSemaphoreWaitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSemaphoreWaitInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pSemaphores)
    {
        unwrapped_struct->pSemaphores = MakeUnwrapVulkanStructs(unwrapped_struct->pSemaphores, unwrapped_struct->semaphoreCount, unwrap_memory);
    }
    if (unwrapped_struct->pValues)
    {
        unwrapped_struct->pValues = MakeUnwrapVulkanStructs(unwrapped_struct->pValues, unwrapped_struct->semaphoreCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSemaphoreSignalInfo* TrackStruct(const VkSemaphoreSignalInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSemaphoreSignalInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceBufferDeviceAddressFeatures* TrackStruct(const VkPhysicalDeviceBufferDeviceAddressFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceBufferDeviceAddressFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBufferDeviceAddressInfo* TrackStruct(const VkBufferDeviceAddressInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBufferDeviceAddressInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBufferOpaqueCaptureAddressCreateInfo* TrackStruct(const VkBufferOpaqueCaptureAddressCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBufferOpaqueCaptureAddressCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMemoryOpaqueCaptureAddressAllocateInfo* TrackStruct(const VkMemoryOpaqueCaptureAddressAllocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMemoryOpaqueCaptureAddressAllocateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceMemoryOpaqueCaptureAddressInfo* TrackStruct(const VkDeviceMemoryOpaqueCaptureAddressInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceMemoryOpaqueCaptureAddressInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceVulkan13Features* TrackStruct(const VkPhysicalDeviceVulkan13Features* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceVulkan13Features* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceVulkan13Properties* TrackStruct(const VkPhysicalDeviceVulkan13Properties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceVulkan13Properties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineCreationFeedbackCreateInfo* TrackStruct(const VkPipelineCreationFeedbackCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineCreationFeedbackCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pPipelineStageCreationFeedbacks)
    {
        unwrapped_struct->pPipelineStageCreationFeedbacks = MakeUnwrapVulkanStructs(unwrapped_struct->pPipelineStageCreationFeedbacks, unwrapped_struct->pipelineStageCreationFeedbackCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderTerminateInvocationFeatures* TrackStruct(const VkPhysicalDeviceShaderTerminateInvocationFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderTerminateInvocationFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceToolProperties* TrackStruct(const VkPhysicalDeviceToolProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceToolProperties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* TrackStruct(const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevicePrivateDataFeatures* TrackStruct(const VkPhysicalDevicePrivateDataFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevicePrivateDataFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDevicePrivateDataCreateInfo* TrackStruct(const VkDevicePrivateDataCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDevicePrivateDataCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPrivateDataSlotCreateInfo* TrackStruct(const VkPrivateDataSlotCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPrivateDataSlotCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevicePipelineCreationCacheControlFeatures* TrackStruct(const VkPhysicalDevicePipelineCreationCacheControlFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevicePipelineCreationCacheControlFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMemoryBarrier2* TrackStruct(const VkMemoryBarrier2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMemoryBarrier2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBufferMemoryBarrier2* TrackStruct(const VkBufferMemoryBarrier2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBufferMemoryBarrier2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageMemoryBarrier2* TrackStruct(const VkImageMemoryBarrier2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageMemoryBarrier2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDependencyInfo* TrackStruct(const VkDependencyInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDependencyInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pMemoryBarriers)
    {
        unwrapped_struct->pMemoryBarriers = MakeUnwrapVulkanStructs(unwrapped_struct->pMemoryBarriers, unwrapped_struct->memoryBarrierCount, unwrap_memory);
    }
    if (unwrapped_struct->pBufferMemoryBarriers)
    {
        unwrapped_struct->pBufferMemoryBarriers = MakeUnwrapVulkanStructs(unwrapped_struct->pBufferMemoryBarriers, unwrapped_struct->bufferMemoryBarrierCount, unwrap_memory);
    }
    if (unwrapped_struct->pImageMemoryBarriers)
    {
        unwrapped_struct->pImageMemoryBarriers = MakeUnwrapVulkanStructs(unwrapped_struct->pImageMemoryBarriers, unwrapped_struct->imageMemoryBarrierCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSemaphoreSubmitInfo* TrackStruct(const VkSemaphoreSubmitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSemaphoreSubmitInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCommandBufferSubmitInfo* TrackStruct(const VkCommandBufferSubmitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCommandBufferSubmitInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSubmitInfo2* TrackStruct(const VkSubmitInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSubmitInfo2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pWaitSemaphoreInfos)
    {
        unwrapped_struct->pWaitSemaphoreInfos = MakeUnwrapVulkanStructs(unwrapped_struct->pWaitSemaphoreInfos, unwrapped_struct->waitSemaphoreInfoCount, unwrap_memory);
    }
    if (unwrapped_struct->pCommandBufferInfos)
    {
        unwrapped_struct->pCommandBufferInfos = MakeUnwrapVulkanStructs(unwrapped_struct->pCommandBufferInfos, unwrapped_struct->commandBufferInfoCount, unwrap_memory);
    }
    if (unwrapped_struct->pSignalSemaphoreInfos)
    {
        unwrapped_struct->pSignalSemaphoreInfos = MakeUnwrapVulkanStructs(unwrapped_struct->pSignalSemaphoreInfos, unwrapped_struct->signalSemaphoreInfoCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceSynchronization2Features* TrackStruct(const VkPhysicalDeviceSynchronization2Features* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceSynchronization2Features* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* TrackStruct(const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceImageRobustnessFeatures* TrackStruct(const VkPhysicalDeviceImageRobustnessFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceImageRobustnessFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBufferCopy2* TrackStruct(const VkBufferCopy2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBufferCopy2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCopyBufferInfo2* TrackStruct(const VkCopyBufferInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCopyBufferInfo2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pRegions)
    {
        unwrapped_struct->pRegions = MakeUnwrapVulkanStructs(unwrapped_struct->pRegions, unwrapped_struct->regionCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageCopy2* TrackStruct(const VkImageCopy2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageCopy2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCopyImageInfo2* TrackStruct(const VkCopyImageInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCopyImageInfo2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pRegions)
    {
        unwrapped_struct->pRegions = MakeUnwrapVulkanStructs(unwrapped_struct->pRegions, unwrapped_struct->regionCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBufferImageCopy2* TrackStruct(const VkBufferImageCopy2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBufferImageCopy2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCopyBufferToImageInfo2* TrackStruct(const VkCopyBufferToImageInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCopyBufferToImageInfo2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pRegions)
    {
        unwrapped_struct->pRegions = MakeUnwrapVulkanStructs(unwrapped_struct->pRegions, unwrapped_struct->regionCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCopyImageToBufferInfo2* TrackStruct(const VkCopyImageToBufferInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCopyImageToBufferInfo2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pRegions)
    {
        unwrapped_struct->pRegions = MakeUnwrapVulkanStructs(unwrapped_struct->pRegions, unwrapped_struct->regionCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageBlit2* TrackStruct(const VkImageBlit2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageBlit2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBlitImageInfo2* TrackStruct(const VkBlitImageInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBlitImageInfo2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pRegions)
    {
        unwrapped_struct->pRegions = MakeUnwrapVulkanStructs(unwrapped_struct->pRegions, unwrapped_struct->regionCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageResolve2* TrackStruct(const VkImageResolve2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageResolve2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkResolveImageInfo2* TrackStruct(const VkResolveImageInfo2* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkResolveImageInfo2* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pRegions)
    {
        unwrapped_struct->pRegions = MakeUnwrapVulkanStructs(unwrapped_struct->pRegions, unwrapped_struct->regionCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceSubgroupSizeControlFeatures* TrackStruct(const VkPhysicalDeviceSubgroupSizeControlFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceSubgroupSizeControlFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceSubgroupSizeControlProperties* TrackStruct(const VkPhysicalDeviceSubgroupSizeControlProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceSubgroupSizeControlProperties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineShaderStageRequiredSubgroupSizeCreateInfo* TrackStruct(const VkPipelineShaderStageRequiredSubgroupSizeCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineShaderStageRequiredSubgroupSizeCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceInlineUniformBlockFeatures* TrackStruct(const VkPhysicalDeviceInlineUniformBlockFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceInlineUniformBlockFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceInlineUniformBlockProperties* TrackStruct(const VkPhysicalDeviceInlineUniformBlockProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceInlineUniformBlockProperties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkWriteDescriptorSetInlineUniformBlock* TrackStruct(const VkWriteDescriptorSetInlineUniformBlock* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkWriteDescriptorSetInlineUniformBlock* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pData)
    {
        unwrapped_struct->pData = MakeUnwrapVulkanStructs<uint8_t>(reinterpret_cast<const uint8_t*>(unwrapped_struct->pData), unwrapped_struct->dataSize, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDescriptorPoolInlineUniformBlockCreateInfo* TrackStruct(const VkDescriptorPoolInlineUniformBlockCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDescriptorPoolInlineUniformBlockCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceTextureCompressionASTCHDRFeatures* TrackStruct(const VkPhysicalDeviceTextureCompressionASTCHDRFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceTextureCompressionASTCHDRFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRenderingAttachmentInfo* TrackStruct(const VkRenderingAttachmentInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRenderingAttachmentInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRenderingInfo* TrackStruct(const VkRenderingInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRenderingInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pColorAttachments)
    {
        unwrapped_struct->pColorAttachments = MakeUnwrapVulkanStructs(unwrapped_struct->pColorAttachments, unwrapped_struct->colorAttachmentCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineRenderingCreateInfo* TrackStruct(const VkPipelineRenderingCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineRenderingCreateInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pColorAttachmentFormats)
    {
        unwrapped_struct->pColorAttachmentFormats = MakeUnwrapVulkanStructs(unwrapped_struct->pColorAttachmentFormats, unwrapped_struct->colorAttachmentCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDynamicRenderingFeatures* TrackStruct(const VkPhysicalDeviceDynamicRenderingFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDynamicRenderingFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCommandBufferInheritanceRenderingInfo* TrackStruct(const VkCommandBufferInheritanceRenderingInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCommandBufferInheritanceRenderingInfo* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pColorAttachmentFormats)
    {
        unwrapped_struct->pColorAttachmentFormats = MakeUnwrapVulkanStructs(unwrapped_struct->pColorAttachmentFormats, unwrapped_struct->colorAttachmentCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderIntegerDotProductFeatures* TrackStruct(const VkPhysicalDeviceShaderIntegerDotProductFeatures* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderIntegerDotProductFeatures* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderIntegerDotProductProperties* TrackStruct(const VkPhysicalDeviceShaderIntegerDotProductProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderIntegerDotProductProperties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceTexelBufferAlignmentProperties* TrackStruct(const VkPhysicalDeviceTexelBufferAlignmentProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceTexelBufferAlignmentProperties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkFormatProperties3* TrackStruct(const VkFormatProperties3* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkFormatProperties3* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMaintenance4Features* TrackStruct(const VkPhysicalDeviceMaintenance4Features* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMaintenance4Features* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMaintenance4Properties* TrackStruct(const VkPhysicalDeviceMaintenance4Properties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMaintenance4Properties* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceBufferMemoryRequirements* TrackStruct(const VkDeviceBufferMemoryRequirements* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceBufferMemoryRequirements* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceImageMemoryRequirements* TrackStruct(const VkDeviceImageMemoryRequirements* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceImageMemoryRequirements* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSwapchainCreateInfoKHR* TrackStruct(const VkSwapchainCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSwapchainCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pQueueFamilyIndices)
    {
        unwrapped_struct->pQueueFamilyIndices = MakeUnwrapVulkanStructs(unwrapped_struct->pQueueFamilyIndices, unwrapped_struct->queueFamilyIndexCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPresentInfoKHR* TrackStruct(const VkPresentInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPresentInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pWaitSemaphores)
    {
        unwrapped_struct->pWaitSemaphores = MakeUnwrapVulkanStructs(unwrapped_struct->pWaitSemaphores, unwrapped_struct->waitSemaphoreCount, unwrap_memory);
    }
    if (unwrapped_struct->pSwapchains)
    {
        unwrapped_struct->pSwapchains = MakeUnwrapVulkanStructs(unwrapped_struct->pSwapchains, unwrapped_struct->swapchainCount, unwrap_memory);
    }
    if (unwrapped_struct->pImageIndices)
    {
        unwrapped_struct->pImageIndices = MakeUnwrapVulkanStructs(unwrapped_struct->pImageIndices, unwrapped_struct->swapchainCount, unwrap_memory);
    }
    if (unwrapped_struct->pResults)
    {
        unwrapped_struct->pResults = MakeUnwrapVulkanStructs(unwrapped_struct->pResults, unwrapped_struct->swapchainCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageSwapchainCreateInfoKHR* TrackStruct(const VkImageSwapchainCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageSwapchainCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBindImageMemorySwapchainInfoKHR* TrackStruct(const VkBindImageMemorySwapchainInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBindImageMemorySwapchainInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAcquireNextImageInfoKHR* TrackStruct(const VkAcquireNextImageInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAcquireNextImageInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceGroupPresentCapabilitiesKHR* TrackStruct(const VkDeviceGroupPresentCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceGroupPresentCapabilitiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceGroupPresentInfoKHR* TrackStruct(const VkDeviceGroupPresentInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceGroupPresentInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pDeviceMasks)
    {
        unwrapped_struct->pDeviceMasks = MakeUnwrapVulkanStructs(unwrapped_struct->pDeviceMasks, unwrapped_struct->swapchainCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceGroupSwapchainCreateInfoKHR* TrackStruct(const VkDeviceGroupSwapchainCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceGroupSwapchainCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDisplayModeCreateInfoKHR* TrackStruct(const VkDisplayModeCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDisplayModeCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDisplaySurfaceCreateInfoKHR* TrackStruct(const VkDisplaySurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDisplaySurfaceCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDisplayPresentInfoKHR* TrackStruct(const VkDisplayPresentInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDisplayPresentInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkXlibSurfaceCreateInfoKHR* TrackStruct(const VkXlibSurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkXlibSurfaceCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkXcbSurfaceCreateInfoKHR* TrackStruct(const VkXcbSurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkXcbSurfaceCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkWaylandSurfaceCreateInfoKHR* TrackStruct(const VkWaylandSurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkWaylandSurfaceCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAndroidSurfaceCreateInfoKHR* TrackStruct(const VkAndroidSurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAndroidSurfaceCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkWin32SurfaceCreateInfoKHR* TrackStruct(const VkWin32SurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkWin32SurfaceCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkQueueFamilyQueryResultStatusPropertiesKHR* TrackStruct(const VkQueueFamilyQueryResultStatusPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkQueueFamilyQueryResultStatusPropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkQueueFamilyVideoPropertiesKHR* TrackStruct(const VkQueueFamilyVideoPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkQueueFamilyVideoPropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoProfileInfoKHR* TrackStruct(const VkVideoProfileInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoProfileInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoProfileListInfoKHR* TrackStruct(const VkVideoProfileListInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoProfileListInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pProfiles)
    {
        unwrapped_struct->pProfiles = MakeUnwrapVulkanStructs(unwrapped_struct->pProfiles, unwrapped_struct->profileCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoCapabilitiesKHR* TrackStruct(const VkVideoCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoCapabilitiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceVideoFormatInfoKHR* TrackStruct(const VkPhysicalDeviceVideoFormatInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceVideoFormatInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoFormatPropertiesKHR* TrackStruct(const VkVideoFormatPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoFormatPropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoPictureResourceInfoKHR* TrackStruct(const VkVideoPictureResourceInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoPictureResourceInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoReferenceSlotInfoKHR* TrackStruct(const VkVideoReferenceSlotInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoReferenceSlotInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoSessionMemoryRequirementsKHR* TrackStruct(const VkVideoSessionMemoryRequirementsKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoSessionMemoryRequirementsKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBindVideoSessionMemoryInfoKHR* TrackStruct(const VkBindVideoSessionMemoryInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBindVideoSessionMemoryInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoSessionCreateInfoKHR* TrackStruct(const VkVideoSessionCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoSessionCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoSessionParametersCreateInfoKHR* TrackStruct(const VkVideoSessionParametersCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoSessionParametersCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoSessionParametersUpdateInfoKHR* TrackStruct(const VkVideoSessionParametersUpdateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoSessionParametersUpdateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoBeginCodingInfoKHR* TrackStruct(const VkVideoBeginCodingInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoBeginCodingInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pReferenceSlots)
    {
        unwrapped_struct->pReferenceSlots = MakeUnwrapVulkanStructs(unwrapped_struct->pReferenceSlots, unwrapped_struct->referenceSlotCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEndCodingInfoKHR* TrackStruct(const VkVideoEndCodingInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEndCodingInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoCodingControlInfoKHR* TrackStruct(const VkVideoCodingControlInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoCodingControlInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoDecodeCapabilitiesKHR* TrackStruct(const VkVideoDecodeCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoDecodeCapabilitiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoDecodeUsageInfoKHR* TrackStruct(const VkVideoDecodeUsageInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoDecodeUsageInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoDecodeInfoKHR* TrackStruct(const VkVideoDecodeInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoDecodeInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pReferenceSlots)
    {
        unwrapped_struct->pReferenceSlots = MakeUnwrapVulkanStructs(unwrapped_struct->pReferenceSlots, unwrapped_struct->referenceSlotCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH264CapabilitiesKHR* TrackStruct(const VkVideoEncodeH264CapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH264CapabilitiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH264QualityLevelPropertiesKHR* TrackStruct(const VkVideoEncodeH264QualityLevelPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH264QualityLevelPropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH264SessionCreateInfoKHR* TrackStruct(const VkVideoEncodeH264SessionCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH264SessionCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH264SessionParametersAddInfoKHR* TrackStruct(const VkVideoEncodeH264SessionParametersAddInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH264SessionParametersAddInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pStdSPSs)
    {
        unwrapped_struct->pStdSPSs = MakeUnwrapVulkanStructs(unwrapped_struct->pStdSPSs, unwrapped_struct->stdSPSCount, unwrap_memory);
    }
    if (unwrapped_struct->pStdPPSs)
    {
        unwrapped_struct->pStdPPSs = MakeUnwrapVulkanStructs(unwrapped_struct->pStdPPSs, unwrapped_struct->stdPPSCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH264SessionParametersCreateInfoKHR* TrackStruct(const VkVideoEncodeH264SessionParametersCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH264SessionParametersCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH264SessionParametersGetInfoKHR* TrackStruct(const VkVideoEncodeH264SessionParametersGetInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH264SessionParametersGetInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH264SessionParametersFeedbackInfoKHR* TrackStruct(const VkVideoEncodeH264SessionParametersFeedbackInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH264SessionParametersFeedbackInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH264NaluSliceInfoKHR* TrackStruct(const VkVideoEncodeH264NaluSliceInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH264NaluSliceInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH264PictureInfoKHR* TrackStruct(const VkVideoEncodeH264PictureInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH264PictureInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pNaluSliceEntries)
    {
        unwrapped_struct->pNaluSliceEntries = MakeUnwrapVulkanStructs(unwrapped_struct->pNaluSliceEntries, unwrapped_struct->naluSliceEntryCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH264DpbSlotInfoKHR* TrackStruct(const VkVideoEncodeH264DpbSlotInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH264DpbSlotInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH264ProfileInfoKHR* TrackStruct(const VkVideoEncodeH264ProfileInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH264ProfileInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH264RateControlInfoKHR* TrackStruct(const VkVideoEncodeH264RateControlInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH264RateControlInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH264RateControlLayerInfoKHR* TrackStruct(const VkVideoEncodeH264RateControlLayerInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH264RateControlLayerInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH264GopRemainingFrameInfoKHR* TrackStruct(const VkVideoEncodeH264GopRemainingFrameInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH264GopRemainingFrameInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH265CapabilitiesKHR* TrackStruct(const VkVideoEncodeH265CapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH265CapabilitiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH265SessionCreateInfoKHR* TrackStruct(const VkVideoEncodeH265SessionCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH265SessionCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH265QualityLevelPropertiesKHR* TrackStruct(const VkVideoEncodeH265QualityLevelPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH265QualityLevelPropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH265SessionParametersAddInfoKHR* TrackStruct(const VkVideoEncodeH265SessionParametersAddInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH265SessionParametersAddInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pStdVPSs)
    {
        unwrapped_struct->pStdVPSs = MakeUnwrapVulkanStructs(unwrapped_struct->pStdVPSs, unwrapped_struct->stdVPSCount, unwrap_memory);
    }
    if (unwrapped_struct->pStdSPSs)
    {
        unwrapped_struct->pStdSPSs = MakeUnwrapVulkanStructs(unwrapped_struct->pStdSPSs, unwrapped_struct->stdSPSCount, unwrap_memory);
    }
    if (unwrapped_struct->pStdPPSs)
    {
        unwrapped_struct->pStdPPSs = MakeUnwrapVulkanStructs(unwrapped_struct->pStdPPSs, unwrapped_struct->stdPPSCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH265SessionParametersCreateInfoKHR* TrackStruct(const VkVideoEncodeH265SessionParametersCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH265SessionParametersCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH265SessionParametersGetInfoKHR* TrackStruct(const VkVideoEncodeH265SessionParametersGetInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH265SessionParametersGetInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH265SessionParametersFeedbackInfoKHR* TrackStruct(const VkVideoEncodeH265SessionParametersFeedbackInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH265SessionParametersFeedbackInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH265NaluSliceSegmentInfoKHR* TrackStruct(const VkVideoEncodeH265NaluSliceSegmentInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH265NaluSliceSegmentInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH265PictureInfoKHR* TrackStruct(const VkVideoEncodeH265PictureInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH265PictureInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pNaluSliceSegmentEntries)
    {
        unwrapped_struct->pNaluSliceSegmentEntries = MakeUnwrapVulkanStructs(unwrapped_struct->pNaluSliceSegmentEntries, unwrapped_struct->naluSliceSegmentEntryCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH265DpbSlotInfoKHR* TrackStruct(const VkVideoEncodeH265DpbSlotInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH265DpbSlotInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH265ProfileInfoKHR* TrackStruct(const VkVideoEncodeH265ProfileInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH265ProfileInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH265RateControlInfoKHR* TrackStruct(const VkVideoEncodeH265RateControlInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH265RateControlInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH265RateControlLayerInfoKHR* TrackStruct(const VkVideoEncodeH265RateControlLayerInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH265RateControlLayerInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeH265GopRemainingFrameInfoKHR* TrackStruct(const VkVideoEncodeH265GopRemainingFrameInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeH265GopRemainingFrameInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoDecodeH264ProfileInfoKHR* TrackStruct(const VkVideoDecodeH264ProfileInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoDecodeH264ProfileInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoDecodeH264CapabilitiesKHR* TrackStruct(const VkVideoDecodeH264CapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoDecodeH264CapabilitiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoDecodeH264SessionParametersAddInfoKHR* TrackStruct(const VkVideoDecodeH264SessionParametersAddInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoDecodeH264SessionParametersAddInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pStdSPSs)
    {
        unwrapped_struct->pStdSPSs = MakeUnwrapVulkanStructs(unwrapped_struct->pStdSPSs, unwrapped_struct->stdSPSCount, unwrap_memory);
    }
    if (unwrapped_struct->pStdPPSs)
    {
        unwrapped_struct->pStdPPSs = MakeUnwrapVulkanStructs(unwrapped_struct->pStdPPSs, unwrapped_struct->stdPPSCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoDecodeH264SessionParametersCreateInfoKHR* TrackStruct(const VkVideoDecodeH264SessionParametersCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoDecodeH264SessionParametersCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoDecodeH264PictureInfoKHR* TrackStruct(const VkVideoDecodeH264PictureInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoDecodeH264PictureInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pSliceOffsets)
    {
        unwrapped_struct->pSliceOffsets = MakeUnwrapVulkanStructs(unwrapped_struct->pSliceOffsets, unwrapped_struct->sliceCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoDecodeH264DpbSlotInfoKHR* TrackStruct(const VkVideoDecodeH264DpbSlotInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoDecodeH264DpbSlotInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRenderingFragmentShadingRateAttachmentInfoKHR* TrackStruct(const VkRenderingFragmentShadingRateAttachmentInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRenderingFragmentShadingRateAttachmentInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRenderingFragmentDensityMapAttachmentInfoEXT* TrackStruct(const VkRenderingFragmentDensityMapAttachmentInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRenderingFragmentDensityMapAttachmentInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAttachmentSampleCountInfoAMD* TrackStruct(const VkAttachmentSampleCountInfoAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAttachmentSampleCountInfoAMD* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pColorAttachmentSamples)
    {
        unwrapped_struct->pColorAttachmentSamples = MakeUnwrapVulkanStructs(unwrapped_struct->pColorAttachmentSamples, unwrapped_struct->colorAttachmentCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMultiviewPerViewAttributesInfoNVX* TrackStruct(const VkMultiviewPerViewAttributesInfoNVX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMultiviewPerViewAttributesInfoNVX* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImportMemoryWin32HandleInfoKHR* TrackStruct(const VkImportMemoryWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImportMemoryWin32HandleInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkExportMemoryWin32HandleInfoKHR* TrackStruct(const VkExportMemoryWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkExportMemoryWin32HandleInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMemoryWin32HandlePropertiesKHR* TrackStruct(const VkMemoryWin32HandlePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMemoryWin32HandlePropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMemoryGetWin32HandleInfoKHR* TrackStruct(const VkMemoryGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMemoryGetWin32HandleInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImportMemoryFdInfoKHR* TrackStruct(const VkImportMemoryFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImportMemoryFdInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMemoryFdPropertiesKHR* TrackStruct(const VkMemoryFdPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMemoryFdPropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMemoryGetFdInfoKHR* TrackStruct(const VkMemoryGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMemoryGetFdInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkWin32KeyedMutexAcquireReleaseInfoKHR* TrackStruct(const VkWin32KeyedMutexAcquireReleaseInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkWin32KeyedMutexAcquireReleaseInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pAcquireSyncs)
    {
        unwrapped_struct->pAcquireSyncs = MakeUnwrapVulkanStructs(unwrapped_struct->pAcquireSyncs, unwrapped_struct->acquireCount, unwrap_memory);
    }
    if (unwrapped_struct->pAcquireKeys)
    {
        unwrapped_struct->pAcquireKeys = MakeUnwrapVulkanStructs(unwrapped_struct->pAcquireKeys, unwrapped_struct->acquireCount, unwrap_memory);
    }
    if (unwrapped_struct->pAcquireTimeouts)
    {
        unwrapped_struct->pAcquireTimeouts = MakeUnwrapVulkanStructs(unwrapped_struct->pAcquireTimeouts, unwrapped_struct->acquireCount, unwrap_memory);
    }
    if (unwrapped_struct->pReleaseSyncs)
    {
        unwrapped_struct->pReleaseSyncs = MakeUnwrapVulkanStructs(unwrapped_struct->pReleaseSyncs, unwrapped_struct->releaseCount, unwrap_memory);
    }
    if (unwrapped_struct->pReleaseKeys)
    {
        unwrapped_struct->pReleaseKeys = MakeUnwrapVulkanStructs(unwrapped_struct->pReleaseKeys, unwrapped_struct->releaseCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImportSemaphoreWin32HandleInfoKHR* TrackStruct(const VkImportSemaphoreWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImportSemaphoreWin32HandleInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkExportSemaphoreWin32HandleInfoKHR* TrackStruct(const VkExportSemaphoreWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkExportSemaphoreWin32HandleInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkD3D12FenceSubmitInfoKHR* TrackStruct(const VkD3D12FenceSubmitInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkD3D12FenceSubmitInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pWaitSemaphoreValues)
    {
        unwrapped_struct->pWaitSemaphoreValues = MakeUnwrapVulkanStructs(unwrapped_struct->pWaitSemaphoreValues, unwrapped_struct->waitSemaphoreValuesCount, unwrap_memory);
    }
    if (unwrapped_struct->pSignalSemaphoreValues)
    {
        unwrapped_struct->pSignalSemaphoreValues = MakeUnwrapVulkanStructs(unwrapped_struct->pSignalSemaphoreValues, unwrapped_struct->signalSemaphoreValuesCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSemaphoreGetWin32HandleInfoKHR* TrackStruct(const VkSemaphoreGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSemaphoreGetWin32HandleInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImportSemaphoreFdInfoKHR* TrackStruct(const VkImportSemaphoreFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImportSemaphoreFdInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSemaphoreGetFdInfoKHR* TrackStruct(const VkSemaphoreGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSemaphoreGetFdInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevicePushDescriptorPropertiesKHR* TrackStruct(const VkPhysicalDevicePushDescriptorPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevicePushDescriptorPropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPresentRegionsKHR* TrackStruct(const VkPresentRegionsKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPresentRegionsKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pRegions)
    {
        unwrapped_struct->pRegions = MakeUnwrapVulkanStructs(unwrapped_struct->pRegions, unwrapped_struct->swapchainCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSharedPresentSurfaceCapabilitiesKHR* TrackStruct(const VkSharedPresentSurfaceCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSharedPresentSurfaceCapabilitiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImportFenceWin32HandleInfoKHR* TrackStruct(const VkImportFenceWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImportFenceWin32HandleInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkExportFenceWin32HandleInfoKHR* TrackStruct(const VkExportFenceWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkExportFenceWin32HandleInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkFenceGetWin32HandleInfoKHR* TrackStruct(const VkFenceGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkFenceGetWin32HandleInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImportFenceFdInfoKHR* TrackStruct(const VkImportFenceFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImportFenceFdInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkFenceGetFdInfoKHR* TrackStruct(const VkFenceGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkFenceGetFdInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevicePerformanceQueryFeaturesKHR* TrackStruct(const VkPhysicalDevicePerformanceQueryFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevicePerformanceQueryFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevicePerformanceQueryPropertiesKHR* TrackStruct(const VkPhysicalDevicePerformanceQueryPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevicePerformanceQueryPropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPerformanceCounterKHR* TrackStruct(const VkPerformanceCounterKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPerformanceCounterKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPerformanceCounterDescriptionKHR* TrackStruct(const VkPerformanceCounterDescriptionKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPerformanceCounterDescriptionKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkQueryPoolPerformanceCreateInfoKHR* TrackStruct(const VkQueryPoolPerformanceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkQueryPoolPerformanceCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pCounterIndices)
    {
        unwrapped_struct->pCounterIndices = MakeUnwrapVulkanStructs(unwrapped_struct->pCounterIndices, unwrapped_struct->counterIndexCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAcquireProfilingLockInfoKHR* TrackStruct(const VkAcquireProfilingLockInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAcquireProfilingLockInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPerformanceQuerySubmitInfoKHR* TrackStruct(const VkPerformanceQuerySubmitInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPerformanceQuerySubmitInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceSurfaceInfo2KHR* TrackStruct(const VkPhysicalDeviceSurfaceInfo2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceSurfaceInfo2KHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSurfaceCapabilities2KHR* TrackStruct(const VkSurfaceCapabilities2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSurfaceCapabilities2KHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSurfaceFormat2KHR* TrackStruct(const VkSurfaceFormat2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSurfaceFormat2KHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDisplayProperties2KHR* TrackStruct(const VkDisplayProperties2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDisplayProperties2KHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDisplayPlaneProperties2KHR* TrackStruct(const VkDisplayPlaneProperties2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDisplayPlaneProperties2KHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDisplayModeProperties2KHR* TrackStruct(const VkDisplayModeProperties2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDisplayModeProperties2KHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDisplayPlaneInfo2KHR* TrackStruct(const VkDisplayPlaneInfo2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDisplayPlaneInfo2KHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDisplayPlaneCapabilities2KHR* TrackStruct(const VkDisplayPlaneCapabilities2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDisplayPlaneCapabilities2KHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevicePortabilitySubsetFeaturesKHR* TrackStruct(const VkPhysicalDevicePortabilitySubsetFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevicePortabilitySubsetFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevicePortabilitySubsetPropertiesKHR* TrackStruct(const VkPhysicalDevicePortabilitySubsetPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevicePortabilitySubsetPropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderClockFeaturesKHR* TrackStruct(const VkPhysicalDeviceShaderClockFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderClockFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoDecodeH265ProfileInfoKHR* TrackStruct(const VkVideoDecodeH265ProfileInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoDecodeH265ProfileInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoDecodeH265CapabilitiesKHR* TrackStruct(const VkVideoDecodeH265CapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoDecodeH265CapabilitiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoDecodeH265SessionParametersAddInfoKHR* TrackStruct(const VkVideoDecodeH265SessionParametersAddInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoDecodeH265SessionParametersAddInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pStdVPSs)
    {
        unwrapped_struct->pStdVPSs = MakeUnwrapVulkanStructs(unwrapped_struct->pStdVPSs, unwrapped_struct->stdVPSCount, unwrap_memory);
    }
    if (unwrapped_struct->pStdSPSs)
    {
        unwrapped_struct->pStdSPSs = MakeUnwrapVulkanStructs(unwrapped_struct->pStdSPSs, unwrapped_struct->stdSPSCount, unwrap_memory);
    }
    if (unwrapped_struct->pStdPPSs)
    {
        unwrapped_struct->pStdPPSs = MakeUnwrapVulkanStructs(unwrapped_struct->pStdPPSs, unwrapped_struct->stdPPSCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoDecodeH265SessionParametersCreateInfoKHR* TrackStruct(const VkVideoDecodeH265SessionParametersCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoDecodeH265SessionParametersCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoDecodeH265PictureInfoKHR* TrackStruct(const VkVideoDecodeH265PictureInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoDecodeH265PictureInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pSliceSegmentOffsets)
    {
        unwrapped_struct->pSliceSegmentOffsets = MakeUnwrapVulkanStructs(unwrapped_struct->pSliceSegmentOffsets, unwrapped_struct->sliceSegmentCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoDecodeH265DpbSlotInfoKHR* TrackStruct(const VkVideoDecodeH265DpbSlotInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoDecodeH265DpbSlotInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceQueueGlobalPriorityCreateInfoKHR* TrackStruct(const VkDeviceQueueGlobalPriorityCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceQueueGlobalPriorityCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR* TrackStruct(const VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkQueueFamilyGlobalPriorityPropertiesKHR* TrackStruct(const VkQueueFamilyGlobalPriorityPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkQueueFamilyGlobalPriorityPropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkFragmentShadingRateAttachmentInfoKHR* TrackStruct(const VkFragmentShadingRateAttachmentInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkFragmentShadingRateAttachmentInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineFragmentShadingRateStateCreateInfoKHR* TrackStruct(const VkPipelineFragmentShadingRateStateCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineFragmentShadingRateStateCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceFragmentShadingRateFeaturesKHR* TrackStruct(const VkPhysicalDeviceFragmentShadingRateFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceFragmentShadingRateFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceFragmentShadingRatePropertiesKHR* TrackStruct(const VkPhysicalDeviceFragmentShadingRatePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceFragmentShadingRatePropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceFragmentShadingRateKHR* TrackStruct(const VkPhysicalDeviceFragmentShadingRateKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceFragmentShadingRateKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR* TrackStruct(const VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRenderingAttachmentLocationInfoKHR* TrackStruct(const VkRenderingAttachmentLocationInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRenderingAttachmentLocationInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pColorAttachmentLocations)
    {
        unwrapped_struct->pColorAttachmentLocations = MakeUnwrapVulkanStructs(unwrapped_struct->pColorAttachmentLocations, unwrapped_struct->colorAttachmentCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRenderingInputAttachmentIndexInfoKHR* TrackStruct(const VkRenderingInputAttachmentIndexInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRenderingInputAttachmentIndexInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pColorAttachmentInputIndices)
    {
        unwrapped_struct->pColorAttachmentInputIndices = MakeUnwrapVulkanStructs(unwrapped_struct->pColorAttachmentInputIndices, unwrapped_struct->colorAttachmentCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderQuadControlFeaturesKHR* TrackStruct(const VkPhysicalDeviceShaderQuadControlFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderQuadControlFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSurfaceProtectedCapabilitiesKHR* TrackStruct(const VkSurfaceProtectedCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSurfaceProtectedCapabilitiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevicePresentWaitFeaturesKHR* TrackStruct(const VkPhysicalDevicePresentWaitFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevicePresentWaitFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* TrackStruct(const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineInfoKHR* TrackStruct(const VkPipelineInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineExecutablePropertiesKHR* TrackStruct(const VkPipelineExecutablePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineExecutablePropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineExecutableInfoKHR* TrackStruct(const VkPipelineExecutableInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineExecutableInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineExecutableStatisticKHR* TrackStruct(const VkPipelineExecutableStatisticKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineExecutableStatisticKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineExecutableInternalRepresentationKHR* TrackStruct(const VkPipelineExecutableInternalRepresentationKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineExecutableInternalRepresentationKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pData)
    {
        unwrapped_struct->pData = MakeUnwrapVulkanStructs<uint8_t>(reinterpret_cast<const uint8_t*>(unwrapped_struct->pData), unwrapped_struct->dataSize, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMemoryMapInfoKHR* TrackStruct(const VkMemoryMapInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMemoryMapInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMemoryUnmapInfoKHR* TrackStruct(const VkMemoryUnmapInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMemoryUnmapInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineLibraryCreateInfoKHR* TrackStruct(const VkPipelineLibraryCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineLibraryCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pLibraries)
    {
        unwrapped_struct->pLibraries = MakeUnwrapVulkanStructs(unwrapped_struct->pLibraries, unwrapped_struct->libraryCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPresentIdKHR* TrackStruct(const VkPresentIdKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPresentIdKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pPresentIds)
    {
        unwrapped_struct->pPresentIds = MakeUnwrapVulkanStructs(unwrapped_struct->pPresentIds, unwrapped_struct->swapchainCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevicePresentIdFeaturesKHR* TrackStruct(const VkPhysicalDevicePresentIdFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevicePresentIdFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeInfoKHR* TrackStruct(const VkVideoEncodeInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pReferenceSlots)
    {
        unwrapped_struct->pReferenceSlots = MakeUnwrapVulkanStructs(unwrapped_struct->pReferenceSlots, unwrapped_struct->referenceSlotCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeCapabilitiesKHR* TrackStruct(const VkVideoEncodeCapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeCapabilitiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkQueryPoolVideoEncodeFeedbackCreateInfoKHR* TrackStruct(const VkQueryPoolVideoEncodeFeedbackCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkQueryPoolVideoEncodeFeedbackCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeUsageInfoKHR* TrackStruct(const VkVideoEncodeUsageInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeUsageInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeRateControlLayerInfoKHR* TrackStruct(const VkVideoEncodeRateControlLayerInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeRateControlLayerInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeRateControlInfoKHR* TrackStruct(const VkVideoEncodeRateControlInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeRateControlInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pLayers)
    {
        unwrapped_struct->pLayers = MakeUnwrapVulkanStructs(unwrapped_struct->pLayers, unwrapped_struct->layerCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* TrackStruct(const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeQualityLevelPropertiesKHR* TrackStruct(const VkVideoEncodeQualityLevelPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeQualityLevelPropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeQualityLevelInfoKHR* TrackStruct(const VkVideoEncodeQualityLevelInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeQualityLevelInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeSessionParametersGetInfoKHR* TrackStruct(const VkVideoEncodeSessionParametersGetInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeSessionParametersGetInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoEncodeSessionParametersFeedbackInfoKHR* TrackStruct(const VkVideoEncodeSessionParametersFeedbackInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoEncodeSessionParametersFeedbackInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkQueueFamilyCheckpointProperties2NV* TrackStruct(const VkQueueFamilyCheckpointProperties2NV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkQueueFamilyCheckpointProperties2NV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCheckpointData2NV* TrackStruct(const VkCheckpointData2NV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCheckpointData2NV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* TrackStruct(const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR* TrackStruct(const VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* TrackStruct(const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* TrackStruct(const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* TrackStruct(const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR* TrackStruct(const VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR* TrackStruct(const VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMaintenance5FeaturesKHR* TrackStruct(const VkPhysicalDeviceMaintenance5FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMaintenance5FeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMaintenance5PropertiesKHR* TrackStruct(const VkPhysicalDeviceMaintenance5PropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMaintenance5PropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRenderingAreaInfoKHR* TrackStruct(const VkRenderingAreaInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRenderingAreaInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pColorAttachmentFormats)
    {
        unwrapped_struct->pColorAttachmentFormats = MakeUnwrapVulkanStructs(unwrapped_struct->pColorAttachmentFormats, unwrapped_struct->colorAttachmentCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageSubresource2KHR* TrackStruct(const VkImageSubresource2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageSubresource2KHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceImageSubresourceInfoKHR* TrackStruct(const VkDeviceImageSubresourceInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceImageSubresourceInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSubresourceLayout2KHR* TrackStruct(const VkSubresourceLayout2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSubresourceLayout2KHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineCreateFlags2CreateInfoKHR* TrackStruct(const VkPipelineCreateFlags2CreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineCreateFlags2CreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBufferUsageFlags2CreateInfoKHR* TrackStruct(const VkBufferUsageFlags2CreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBufferUsageFlags2CreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR* TrackStruct(const VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCooperativeMatrixPropertiesKHR* TrackStruct(const VkCooperativeMatrixPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCooperativeMatrixPropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceCooperativeMatrixFeaturesKHR* TrackStruct(const VkPhysicalDeviceCooperativeMatrixFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceCooperativeMatrixFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceCooperativeMatrixPropertiesKHR* TrackStruct(const VkPhysicalDeviceCooperativeMatrixPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceCooperativeMatrixPropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoDecodeAV1ProfileInfoKHR* TrackStruct(const VkVideoDecodeAV1ProfileInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoDecodeAV1ProfileInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoDecodeAV1CapabilitiesKHR* TrackStruct(const VkVideoDecodeAV1CapabilitiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoDecodeAV1CapabilitiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoDecodeAV1SessionParametersCreateInfoKHR* TrackStruct(const VkVideoDecodeAV1SessionParametersCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoDecodeAV1SessionParametersCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoDecodeAV1PictureInfoKHR* TrackStruct(const VkVideoDecodeAV1PictureInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoDecodeAV1PictureInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pTileOffsets)
    {
        unwrapped_struct->pTileOffsets = MakeUnwrapVulkanStructs(unwrapped_struct->pTileOffsets, unwrapped_struct->tileCount, unwrap_memory);
    }
    if (unwrapped_struct->pTileSizes)
    {
        unwrapped_struct->pTileSizes = MakeUnwrapVulkanStructs(unwrapped_struct->pTileSizes, unwrapped_struct->tileCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoDecodeAV1DpbSlotInfoKHR* TrackStruct(const VkVideoDecodeAV1DpbSlotInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoDecodeAV1DpbSlotInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceVideoMaintenance1FeaturesKHR* TrackStruct(const VkPhysicalDeviceVideoMaintenance1FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceVideoMaintenance1FeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVideoInlineQueryInfoKHR* TrackStruct(const VkVideoInlineQueryInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVideoInlineQueryInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR* TrackStruct(const VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineVertexInputDivisorStateCreateInfoKHR* TrackStruct(const VkPipelineVertexInputDivisorStateCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineVertexInputDivisorStateCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pVertexBindingDivisors)
    {
        unwrapped_struct->pVertexBindingDivisors = MakeUnwrapVulkanStructs(unwrapped_struct->pVertexBindingDivisors, unwrapped_struct->vertexBindingDivisorCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR* TrackStruct(const VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderFloatControls2FeaturesKHR* TrackStruct(const VkPhysicalDeviceShaderFloatControls2FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderFloatControls2FeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceIndexTypeUint8FeaturesKHR* TrackStruct(const VkPhysicalDeviceIndexTypeUint8FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceIndexTypeUint8FeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceLineRasterizationFeaturesKHR* TrackStruct(const VkPhysicalDeviceLineRasterizationFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceLineRasterizationFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceLineRasterizationPropertiesKHR* TrackStruct(const VkPhysicalDeviceLineRasterizationPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceLineRasterizationPropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineRasterizationLineStateCreateInfoKHR* TrackStruct(const VkPipelineRasterizationLineStateCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineRasterizationLineStateCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCalibratedTimestampInfoKHR* TrackStruct(const VkCalibratedTimestampInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCalibratedTimestampInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderExpectAssumeFeaturesKHR* TrackStruct(const VkPhysicalDeviceShaderExpectAssumeFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderExpectAssumeFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMaintenance6FeaturesKHR* TrackStruct(const VkPhysicalDeviceMaintenance6FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMaintenance6FeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMaintenance6PropertiesKHR* TrackStruct(const VkPhysicalDeviceMaintenance6PropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMaintenance6PropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBindMemoryStatusKHR* TrackStruct(const VkBindMemoryStatusKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBindMemoryStatusKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBindDescriptorSetsInfoKHR* TrackStruct(const VkBindDescriptorSetsInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBindDescriptorSetsInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pDescriptorSets)
    {
        unwrapped_struct->pDescriptorSets = MakeUnwrapVulkanStructs(unwrapped_struct->pDescriptorSets, unwrapped_struct->descriptorSetCount, unwrap_memory);
    }
    if (unwrapped_struct->pDynamicOffsets)
    {
        unwrapped_struct->pDynamicOffsets = MakeUnwrapVulkanStructs(unwrapped_struct->pDynamicOffsets, unwrapped_struct->dynamicOffsetCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPushConstantsInfoKHR* TrackStruct(const VkPushConstantsInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPushConstantsInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pValues)
    {
        unwrapped_struct->pValues = MakeUnwrapVulkanStructs<uint8_t>(reinterpret_cast<const uint8_t*>(unwrapped_struct->pValues), unwrapped_struct->size, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPushDescriptorSetInfoKHR* TrackStruct(const VkPushDescriptorSetInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPushDescriptorSetInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pDescriptorWrites)
    {
        unwrapped_struct->pDescriptorWrites = MakeUnwrapVulkanStructs(unwrapped_struct->pDescriptorWrites, unwrapped_struct->descriptorWriteCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPushDescriptorSetWithTemplateInfoKHR* TrackStruct(const VkPushDescriptorSetWithTemplateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPushDescriptorSetWithTemplateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSetDescriptorBufferOffsetsInfoEXT* TrackStruct(const VkSetDescriptorBufferOffsetsInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSetDescriptorBufferOffsetsInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pBufferIndices)
    {
        unwrapped_struct->pBufferIndices = MakeUnwrapVulkanStructs(unwrapped_struct->pBufferIndices, unwrapped_struct->setCount, unwrap_memory);
    }
    if (unwrapped_struct->pOffsets)
    {
        unwrapped_struct->pOffsets = MakeUnwrapVulkanStructs(unwrapped_struct->pOffsets, unwrapped_struct->setCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBindDescriptorBufferEmbeddedSamplersInfoEXT* TrackStruct(const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBindDescriptorBufferEmbeddedSamplersInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDebugReportCallbackCreateInfoEXT* TrackStruct(const VkDebugReportCallbackCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDebugReportCallbackCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineRasterizationStateRasterizationOrderAMD* TrackStruct(const VkPipelineRasterizationStateRasterizationOrderAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineRasterizationStateRasterizationOrderAMD* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDebugMarkerObjectNameInfoEXT* TrackStruct(const VkDebugMarkerObjectNameInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDebugMarkerObjectNameInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDebugMarkerObjectTagInfoEXT* TrackStruct(const VkDebugMarkerObjectTagInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDebugMarkerObjectTagInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pTag)
    {
        unwrapped_struct->pTag = MakeUnwrapVulkanStructs<uint8_t>(reinterpret_cast<const uint8_t*>(unwrapped_struct->pTag), unwrapped_struct->tagSize, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDebugMarkerMarkerInfoEXT* TrackStruct(const VkDebugMarkerMarkerInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDebugMarkerMarkerInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDedicatedAllocationImageCreateInfoNV* TrackStruct(const VkDedicatedAllocationImageCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDedicatedAllocationImageCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDedicatedAllocationBufferCreateInfoNV* TrackStruct(const VkDedicatedAllocationBufferCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDedicatedAllocationBufferCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDedicatedAllocationMemoryAllocateInfoNV* TrackStruct(const VkDedicatedAllocationMemoryAllocateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDedicatedAllocationMemoryAllocateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceTransformFeedbackFeaturesEXT* TrackStruct(const VkPhysicalDeviceTransformFeedbackFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceTransformFeedbackFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceTransformFeedbackPropertiesEXT* TrackStruct(const VkPhysicalDeviceTransformFeedbackPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceTransformFeedbackPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineRasterizationStateStreamCreateInfoEXT* TrackStruct(const VkPipelineRasterizationStateStreamCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineRasterizationStateStreamCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageViewHandleInfoNVX* TrackStruct(const VkImageViewHandleInfoNVX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageViewHandleInfoNVX* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageViewAddressPropertiesNVX* TrackStruct(const VkImageViewAddressPropertiesNVX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageViewAddressPropertiesNVX* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkTextureLODGatherFormatPropertiesAMD* TrackStruct(const VkTextureLODGatherFormatPropertiesAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkTextureLODGatherFormatPropertiesAMD* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkStreamDescriptorSurfaceCreateInfoGGP* TrackStruct(const VkStreamDescriptorSurfaceCreateInfoGGP* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkStreamDescriptorSurfaceCreateInfoGGP* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceCornerSampledImageFeaturesNV* TrackStruct(const VkPhysicalDeviceCornerSampledImageFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceCornerSampledImageFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkExternalMemoryImageCreateInfoNV* TrackStruct(const VkExternalMemoryImageCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkExternalMemoryImageCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkExportMemoryAllocateInfoNV* TrackStruct(const VkExportMemoryAllocateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkExportMemoryAllocateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImportMemoryWin32HandleInfoNV* TrackStruct(const VkImportMemoryWin32HandleInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImportMemoryWin32HandleInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkExportMemoryWin32HandleInfoNV* TrackStruct(const VkExportMemoryWin32HandleInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkExportMemoryWin32HandleInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkWin32KeyedMutexAcquireReleaseInfoNV* TrackStruct(const VkWin32KeyedMutexAcquireReleaseInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkWin32KeyedMutexAcquireReleaseInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pAcquireSyncs)
    {
        unwrapped_struct->pAcquireSyncs = MakeUnwrapVulkanStructs(unwrapped_struct->pAcquireSyncs, unwrapped_struct->acquireCount, unwrap_memory);
    }
    if (unwrapped_struct->pAcquireKeys)
    {
        unwrapped_struct->pAcquireKeys = MakeUnwrapVulkanStructs(unwrapped_struct->pAcquireKeys, unwrapped_struct->acquireCount, unwrap_memory);
    }
    if (unwrapped_struct->pAcquireTimeoutMilliseconds)
    {
        unwrapped_struct->pAcquireTimeoutMilliseconds = MakeUnwrapVulkanStructs(unwrapped_struct->pAcquireTimeoutMilliseconds, unwrapped_struct->acquireCount, unwrap_memory);
    }
    if (unwrapped_struct->pReleaseSyncs)
    {
        unwrapped_struct->pReleaseSyncs = MakeUnwrapVulkanStructs(unwrapped_struct->pReleaseSyncs, unwrapped_struct->releaseCount, unwrap_memory);
    }
    if (unwrapped_struct->pReleaseKeys)
    {
        unwrapped_struct->pReleaseKeys = MakeUnwrapVulkanStructs(unwrapped_struct->pReleaseKeys, unwrapped_struct->releaseCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkValidationFlagsEXT* TrackStruct(const VkValidationFlagsEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkValidationFlagsEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pDisabledValidationChecks)
    {
        unwrapped_struct->pDisabledValidationChecks = MakeUnwrapVulkanStructs(unwrapped_struct->pDisabledValidationChecks, unwrapped_struct->disabledValidationCheckCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkViSurfaceCreateInfoNN* TrackStruct(const VkViSurfaceCreateInfoNN* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkViSurfaceCreateInfoNN* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageViewASTCDecodeModeEXT* TrackStruct(const VkImageViewASTCDecodeModeEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageViewASTCDecodeModeEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceASTCDecodeFeaturesEXT* TrackStruct(const VkPhysicalDeviceASTCDecodeFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceASTCDecodeFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevicePipelineRobustnessFeaturesEXT* TrackStruct(const VkPhysicalDevicePipelineRobustnessFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevicePipelineRobustnessFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevicePipelineRobustnessPropertiesEXT* TrackStruct(const VkPhysicalDevicePipelineRobustnessPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevicePipelineRobustnessPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineRobustnessCreateInfoEXT* TrackStruct(const VkPipelineRobustnessCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineRobustnessCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkConditionalRenderingBeginInfoEXT* TrackStruct(const VkConditionalRenderingBeginInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkConditionalRenderingBeginInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceConditionalRenderingFeaturesEXT* TrackStruct(const VkPhysicalDeviceConditionalRenderingFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceConditionalRenderingFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCommandBufferInheritanceConditionalRenderingInfoEXT* TrackStruct(const VkCommandBufferInheritanceConditionalRenderingInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCommandBufferInheritanceConditionalRenderingInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineViewportWScalingStateCreateInfoNV* TrackStruct(const VkPipelineViewportWScalingStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineViewportWScalingStateCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pViewportWScalings)
    {
        unwrapped_struct->pViewportWScalings = MakeUnwrapVulkanStructs(unwrapped_struct->pViewportWScalings, unwrapped_struct->viewportCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSurfaceCapabilities2EXT* TrackStruct(const VkSurfaceCapabilities2EXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSurfaceCapabilities2EXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDisplayPowerInfoEXT* TrackStruct(const VkDisplayPowerInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDisplayPowerInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceEventInfoEXT* TrackStruct(const VkDeviceEventInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceEventInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDisplayEventInfoEXT* TrackStruct(const VkDisplayEventInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDisplayEventInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSwapchainCounterCreateInfoEXT* TrackStruct(const VkSwapchainCounterCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSwapchainCounterCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPresentTimesInfoGOOGLE* TrackStruct(const VkPresentTimesInfoGOOGLE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPresentTimesInfoGOOGLE* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pTimes)
    {
        unwrapped_struct->pTimes = MakeUnwrapVulkanStructs(unwrapped_struct->pTimes, unwrapped_struct->swapchainCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* TrackStruct(const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineViewportSwizzleStateCreateInfoNV* TrackStruct(const VkPipelineViewportSwizzleStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineViewportSwizzleStateCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pViewportSwizzles)
    {
        unwrapped_struct->pViewportSwizzles = MakeUnwrapVulkanStructs(unwrapped_struct->pViewportSwizzles, unwrapped_struct->viewportCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDiscardRectanglePropertiesEXT* TrackStruct(const VkPhysicalDeviceDiscardRectanglePropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDiscardRectanglePropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineDiscardRectangleStateCreateInfoEXT* TrackStruct(const VkPipelineDiscardRectangleStateCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineDiscardRectangleStateCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pDiscardRectangles)
    {
        unwrapped_struct->pDiscardRectangles = MakeUnwrapVulkanStructs(unwrapped_struct->pDiscardRectangles, unwrapped_struct->discardRectangleCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceConservativeRasterizationPropertiesEXT* TrackStruct(const VkPhysicalDeviceConservativeRasterizationPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceConservativeRasterizationPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineRasterizationConservativeStateCreateInfoEXT* TrackStruct(const VkPipelineRasterizationConservativeStateCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineRasterizationConservativeStateCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDepthClipEnableFeaturesEXT* TrackStruct(const VkPhysicalDeviceDepthClipEnableFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDepthClipEnableFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineRasterizationDepthClipStateCreateInfoEXT* TrackStruct(const VkPipelineRasterizationDepthClipStateCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineRasterizationDepthClipStateCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkHdrMetadataEXT* TrackStruct(const VkHdrMetadataEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkHdrMetadataEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG* TrackStruct(const VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkIOSSurfaceCreateInfoMVK* TrackStruct(const VkIOSSurfaceCreateInfoMVK* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkIOSSurfaceCreateInfoMVK* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMacOSSurfaceCreateInfoMVK* TrackStruct(const VkMacOSSurfaceCreateInfoMVK* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMacOSSurfaceCreateInfoMVK* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDebugUtilsLabelEXT* TrackStruct(const VkDebugUtilsLabelEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDebugUtilsLabelEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDebugUtilsObjectNameInfoEXT* TrackStruct(const VkDebugUtilsObjectNameInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDebugUtilsObjectNameInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDebugUtilsMessengerCallbackDataEXT* TrackStruct(const VkDebugUtilsMessengerCallbackDataEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDebugUtilsMessengerCallbackDataEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pQueueLabels)
    {
        unwrapped_struct->pQueueLabels = MakeUnwrapVulkanStructs(unwrapped_struct->pQueueLabels, unwrapped_struct->queueLabelCount, unwrap_memory);
    }
    if (unwrapped_struct->pCmdBufLabels)
    {
        unwrapped_struct->pCmdBufLabels = MakeUnwrapVulkanStructs(unwrapped_struct->pCmdBufLabels, unwrapped_struct->cmdBufLabelCount, unwrap_memory);
    }
    if (unwrapped_struct->pObjects)
    {
        unwrapped_struct->pObjects = MakeUnwrapVulkanStructs(unwrapped_struct->pObjects, unwrapped_struct->objectCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDebugUtilsMessengerCreateInfoEXT* TrackStruct(const VkDebugUtilsMessengerCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDebugUtilsMessengerCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDebugUtilsObjectTagInfoEXT* TrackStruct(const VkDebugUtilsObjectTagInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDebugUtilsObjectTagInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pTag)
    {
        unwrapped_struct->pTag = MakeUnwrapVulkanStructs<uint8_t>(reinterpret_cast<const uint8_t*>(unwrapped_struct->pTag), unwrapped_struct->tagSize, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAndroidHardwareBufferUsageANDROID* TrackStruct(const VkAndroidHardwareBufferUsageANDROID* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAndroidHardwareBufferUsageANDROID* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAndroidHardwareBufferPropertiesANDROID* TrackStruct(const VkAndroidHardwareBufferPropertiesANDROID* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAndroidHardwareBufferPropertiesANDROID* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAndroidHardwareBufferFormatPropertiesANDROID* TrackStruct(const VkAndroidHardwareBufferFormatPropertiesANDROID* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAndroidHardwareBufferFormatPropertiesANDROID* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImportAndroidHardwareBufferInfoANDROID* TrackStruct(const VkImportAndroidHardwareBufferInfoANDROID* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImportAndroidHardwareBufferInfoANDROID* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMemoryGetAndroidHardwareBufferInfoANDROID* TrackStruct(const VkMemoryGetAndroidHardwareBufferInfoANDROID* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMemoryGetAndroidHardwareBufferInfoANDROID* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkExternalFormatANDROID* TrackStruct(const VkExternalFormatANDROID* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkExternalFormatANDROID* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAndroidHardwareBufferFormatProperties2ANDROID* TrackStruct(const VkAndroidHardwareBufferFormatProperties2ANDROID* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAndroidHardwareBufferFormatProperties2ANDROID* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSampleLocationsInfoEXT* TrackStruct(const VkSampleLocationsInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSampleLocationsInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pSampleLocations)
    {
        unwrapped_struct->pSampleLocations = MakeUnwrapVulkanStructs(unwrapped_struct->pSampleLocations, unwrapped_struct->sampleLocationsCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRenderPassSampleLocationsBeginInfoEXT* TrackStruct(const VkRenderPassSampleLocationsBeginInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRenderPassSampleLocationsBeginInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pAttachmentInitialSampleLocations)
    {
        unwrapped_struct->pAttachmentInitialSampleLocations = MakeUnwrapVulkanStructs(unwrapped_struct->pAttachmentInitialSampleLocations, unwrapped_struct->attachmentInitialSampleLocationsCount, unwrap_memory);
    }
    if (unwrapped_struct->pPostSubpassSampleLocations)
    {
        unwrapped_struct->pPostSubpassSampleLocations = MakeUnwrapVulkanStructs(unwrapped_struct->pPostSubpassSampleLocations, unwrapped_struct->postSubpassSampleLocationsCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineSampleLocationsStateCreateInfoEXT* TrackStruct(const VkPipelineSampleLocationsStateCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineSampleLocationsStateCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceSampleLocationsPropertiesEXT* TrackStruct(const VkPhysicalDeviceSampleLocationsPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceSampleLocationsPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMultisamplePropertiesEXT* TrackStruct(const VkMultisamplePropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMultisamplePropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* TrackStruct(const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* TrackStruct(const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineColorBlendAdvancedStateCreateInfoEXT* TrackStruct(const VkPipelineColorBlendAdvancedStateCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineColorBlendAdvancedStateCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineCoverageToColorStateCreateInfoNV* TrackStruct(const VkPipelineCoverageToColorStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineCoverageToColorStateCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineCoverageModulationStateCreateInfoNV* TrackStruct(const VkPipelineCoverageModulationStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineCoverageModulationStateCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pCoverageModulationTable)
    {
        unwrapped_struct->pCoverageModulationTable = MakeUnwrapVulkanStructs(unwrapped_struct->pCoverageModulationTable, unwrapped_struct->coverageModulationTableCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* TrackStruct(const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* TrackStruct(const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDrmFormatModifierPropertiesListEXT* TrackStruct(const VkDrmFormatModifierPropertiesListEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDrmFormatModifierPropertiesListEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pDrmFormatModifierProperties)
    {
        unwrapped_struct->pDrmFormatModifierProperties = MakeUnwrapVulkanStructs(unwrapped_struct->pDrmFormatModifierProperties, unwrapped_struct->drmFormatModifierCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceImageDrmFormatModifierInfoEXT* TrackStruct(const VkPhysicalDeviceImageDrmFormatModifierInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceImageDrmFormatModifierInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pQueueFamilyIndices)
    {
        unwrapped_struct->pQueueFamilyIndices = MakeUnwrapVulkanStructs(unwrapped_struct->pQueueFamilyIndices, unwrapped_struct->queueFamilyIndexCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageDrmFormatModifierListCreateInfoEXT* TrackStruct(const VkImageDrmFormatModifierListCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageDrmFormatModifierListCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pDrmFormatModifiers)
    {
        unwrapped_struct->pDrmFormatModifiers = MakeUnwrapVulkanStructs(unwrapped_struct->pDrmFormatModifiers, unwrapped_struct->drmFormatModifierCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageDrmFormatModifierExplicitCreateInfoEXT* TrackStruct(const VkImageDrmFormatModifierExplicitCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageDrmFormatModifierExplicitCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pPlaneLayouts)
    {
        unwrapped_struct->pPlaneLayouts = MakeUnwrapVulkanStructs(unwrapped_struct->pPlaneLayouts, unwrapped_struct->drmFormatModifierPlaneCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageDrmFormatModifierPropertiesEXT* TrackStruct(const VkImageDrmFormatModifierPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageDrmFormatModifierPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDrmFormatModifierPropertiesList2EXT* TrackStruct(const VkDrmFormatModifierPropertiesList2EXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDrmFormatModifierPropertiesList2EXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pDrmFormatModifierProperties)
    {
        unwrapped_struct->pDrmFormatModifierProperties = MakeUnwrapVulkanStructs(unwrapped_struct->pDrmFormatModifierProperties, unwrapped_struct->drmFormatModifierCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkValidationCacheCreateInfoEXT* TrackStruct(const VkValidationCacheCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkValidationCacheCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pInitialData)
    {
        unwrapped_struct->pInitialData = MakeUnwrapVulkanStructs<uint8_t>(reinterpret_cast<const uint8_t*>(unwrapped_struct->pInitialData), unwrapped_struct->initialDataSize, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkShaderModuleValidationCacheCreateInfoEXT* TrackStruct(const VkShaderModuleValidationCacheCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkShaderModuleValidationCacheCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineViewportShadingRateImageStateCreateInfoNV* TrackStruct(const VkPipelineViewportShadingRateImageStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineViewportShadingRateImageStateCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pShadingRatePalettes)
    {
        unwrapped_struct->pShadingRatePalettes = MakeUnwrapVulkanStructs(unwrapped_struct->pShadingRatePalettes, unwrapped_struct->viewportCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShadingRateImageFeaturesNV* TrackStruct(const VkPhysicalDeviceShadingRateImageFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShadingRateImageFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShadingRateImagePropertiesNV* TrackStruct(const VkPhysicalDeviceShadingRateImagePropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShadingRateImagePropertiesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* TrackStruct(const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pCustomSampleOrders)
    {
        unwrapped_struct->pCustomSampleOrders = MakeUnwrapVulkanStructs(unwrapped_struct->pCustomSampleOrders, unwrapped_struct->customSampleOrderCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRayTracingShaderGroupCreateInfoNV* TrackStruct(const VkRayTracingShaderGroupCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRayTracingShaderGroupCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRayTracingPipelineCreateInfoNV* TrackStruct(const VkRayTracingPipelineCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRayTracingPipelineCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pStages)
    {
        unwrapped_struct->pStages = MakeUnwrapVulkanStructs(unwrapped_struct->pStages, unwrapped_struct->stageCount, unwrap_memory);
    }
    if (unwrapped_struct->pGroups)
    {
        unwrapped_struct->pGroups = MakeUnwrapVulkanStructs(unwrapped_struct->pGroups, unwrapped_struct->groupCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkGeometryTrianglesNV* TrackStruct(const VkGeometryTrianglesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkGeometryTrianglesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkGeometryAABBNV* TrackStruct(const VkGeometryAABBNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkGeometryAABBNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkGeometryNV* TrackStruct(const VkGeometryNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkGeometryNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAccelerationStructureInfoNV* TrackStruct(const VkAccelerationStructureInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAccelerationStructureInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pGeometries)
    {
        unwrapped_struct->pGeometries = MakeUnwrapVulkanStructs(unwrapped_struct->pGeometries, unwrapped_struct->geometryCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAccelerationStructureCreateInfoNV* TrackStruct(const VkAccelerationStructureCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAccelerationStructureCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBindAccelerationStructureMemoryInfoNV* TrackStruct(const VkBindAccelerationStructureMemoryInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBindAccelerationStructureMemoryInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pDeviceIndices)
    {
        unwrapped_struct->pDeviceIndices = MakeUnwrapVulkanStructs(unwrapped_struct->pDeviceIndices, unwrapped_struct->deviceIndexCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkWriteDescriptorSetAccelerationStructureNV* TrackStruct(const VkWriteDescriptorSetAccelerationStructureNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkWriteDescriptorSetAccelerationStructureNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pAccelerationStructures)
    {
        unwrapped_struct->pAccelerationStructures = MakeUnwrapVulkanStructs(unwrapped_struct->pAccelerationStructures, unwrapped_struct->accelerationStructureCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAccelerationStructureMemoryRequirementsInfoNV* TrackStruct(const VkAccelerationStructureMemoryRequirementsInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAccelerationStructureMemoryRequirementsInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceRayTracingPropertiesNV* TrackStruct(const VkPhysicalDeviceRayTracingPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceRayTracingPropertiesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* TrackStruct(const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineRepresentativeFragmentTestStateCreateInfoNV* TrackStruct(const VkPipelineRepresentativeFragmentTestStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineRepresentativeFragmentTestStateCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceImageViewImageFormatInfoEXT* TrackStruct(const VkPhysicalDeviceImageViewImageFormatInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceImageViewImageFormatInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkFilterCubicImageViewImageFormatPropertiesEXT* TrackStruct(const VkFilterCubicImageViewImageFormatPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkFilterCubicImageViewImageFormatPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImportMemoryHostPointerInfoEXT* TrackStruct(const VkImportMemoryHostPointerInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImportMemoryHostPointerInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMemoryHostPointerPropertiesEXT* TrackStruct(const VkMemoryHostPointerPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMemoryHostPointerPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceExternalMemoryHostPropertiesEXT* TrackStruct(const VkPhysicalDeviceExternalMemoryHostPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceExternalMemoryHostPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineCompilerControlCreateInfoAMD* TrackStruct(const VkPipelineCompilerControlCreateInfoAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineCompilerControlCreateInfoAMD* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderCorePropertiesAMD* TrackStruct(const VkPhysicalDeviceShaderCorePropertiesAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderCorePropertiesAMD* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceMemoryOverallocationCreateInfoAMD* TrackStruct(const VkDeviceMemoryOverallocationCreateInfoAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceMemoryOverallocationCreateInfoAMD* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* TrackStruct(const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPresentFrameTokenGGP* TrackStruct(const VkPresentFrameTokenGGP* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPresentFrameTokenGGP* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* TrackStruct(const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMeshShaderFeaturesNV* TrackStruct(const VkPhysicalDeviceMeshShaderFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMeshShaderFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMeshShaderPropertiesNV* TrackStruct(const VkPhysicalDeviceMeshShaderPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMeshShaderPropertiesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderImageFootprintFeaturesNV* TrackStruct(const VkPhysicalDeviceShaderImageFootprintFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderImageFootprintFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineViewportExclusiveScissorStateCreateInfoNV* TrackStruct(const VkPipelineViewportExclusiveScissorStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineViewportExclusiveScissorStateCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pExclusiveScissors)
    {
        unwrapped_struct->pExclusiveScissors = MakeUnwrapVulkanStructs(unwrapped_struct->pExclusiveScissors, unwrapped_struct->exclusiveScissorCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceExclusiveScissorFeaturesNV* TrackStruct(const VkPhysicalDeviceExclusiveScissorFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceExclusiveScissorFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkQueueFamilyCheckpointPropertiesNV* TrackStruct(const VkQueueFamilyCheckpointPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkQueueFamilyCheckpointPropertiesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCheckpointDataNV* TrackStruct(const VkCheckpointDataNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCheckpointDataNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* TrackStruct(const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkInitializePerformanceApiInfoINTEL* TrackStruct(const VkInitializePerformanceApiInfoINTEL* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkInitializePerformanceApiInfoINTEL* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkQueryPoolPerformanceQueryCreateInfoINTEL* TrackStruct(const VkQueryPoolPerformanceQueryCreateInfoINTEL* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkQueryPoolPerformanceQueryCreateInfoINTEL* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPerformanceMarkerInfoINTEL* TrackStruct(const VkPerformanceMarkerInfoINTEL* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPerformanceMarkerInfoINTEL* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPerformanceStreamMarkerInfoINTEL* TrackStruct(const VkPerformanceStreamMarkerInfoINTEL* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPerformanceStreamMarkerInfoINTEL* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPerformanceOverrideInfoINTEL* TrackStruct(const VkPerformanceOverrideInfoINTEL* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPerformanceOverrideInfoINTEL* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPerformanceConfigurationAcquireInfoINTEL* TrackStruct(const VkPerformanceConfigurationAcquireInfoINTEL* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPerformanceConfigurationAcquireInfoINTEL* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevicePCIBusInfoPropertiesEXT* TrackStruct(const VkPhysicalDevicePCIBusInfoPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevicePCIBusInfoPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDisplayNativeHdrSurfaceCapabilitiesAMD* TrackStruct(const VkDisplayNativeHdrSurfaceCapabilitiesAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDisplayNativeHdrSurfaceCapabilitiesAMD* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSwapchainDisplayNativeHdrCreateInfoAMD* TrackStruct(const VkSwapchainDisplayNativeHdrCreateInfoAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSwapchainDisplayNativeHdrCreateInfoAMD* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImagePipeSurfaceCreateInfoFUCHSIA* TrackStruct(const VkImagePipeSurfaceCreateInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImagePipeSurfaceCreateInfoFUCHSIA* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMetalSurfaceCreateInfoEXT* TrackStruct(const VkMetalSurfaceCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMetalSurfaceCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceFragmentDensityMapFeaturesEXT* TrackStruct(const VkPhysicalDeviceFragmentDensityMapFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceFragmentDensityMapFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceFragmentDensityMapPropertiesEXT* TrackStruct(const VkPhysicalDeviceFragmentDensityMapPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceFragmentDensityMapPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRenderPassFragmentDensityMapCreateInfoEXT* TrackStruct(const VkRenderPassFragmentDensityMapCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRenderPassFragmentDensityMapCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderCoreProperties2AMD* TrackStruct(const VkPhysicalDeviceShaderCoreProperties2AMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderCoreProperties2AMD* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceCoherentMemoryFeaturesAMD* TrackStruct(const VkPhysicalDeviceCoherentMemoryFeaturesAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceCoherentMemoryFeaturesAMD* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* TrackStruct(const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMemoryBudgetPropertiesEXT* TrackStruct(const VkPhysicalDeviceMemoryBudgetPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMemoryBudgetPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMemoryPriorityFeaturesEXT* TrackStruct(const VkPhysicalDeviceMemoryPriorityFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMemoryPriorityFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMemoryPriorityAllocateInfoEXT* TrackStruct(const VkMemoryPriorityAllocateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMemoryPriorityAllocateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* TrackStruct(const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* TrackStruct(const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBufferDeviceAddressCreateInfoEXT* TrackStruct(const VkBufferDeviceAddressCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBufferDeviceAddressCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkValidationFeaturesEXT* TrackStruct(const VkValidationFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkValidationFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pEnabledValidationFeatures)
    {
        unwrapped_struct->pEnabledValidationFeatures = MakeUnwrapVulkanStructs(unwrapped_struct->pEnabledValidationFeatures, unwrapped_struct->enabledValidationFeatureCount, unwrap_memory);
    }
    if (unwrapped_struct->pDisabledValidationFeatures)
    {
        unwrapped_struct->pDisabledValidationFeatures = MakeUnwrapVulkanStructs(unwrapped_struct->pDisabledValidationFeatures, unwrapped_struct->disabledValidationFeatureCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCooperativeMatrixPropertiesNV* TrackStruct(const VkCooperativeMatrixPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCooperativeMatrixPropertiesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceCooperativeMatrixFeaturesNV* TrackStruct(const VkPhysicalDeviceCooperativeMatrixFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceCooperativeMatrixFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceCooperativeMatrixPropertiesNV* TrackStruct(const VkPhysicalDeviceCooperativeMatrixPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceCooperativeMatrixPropertiesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceCoverageReductionModeFeaturesNV* TrackStruct(const VkPhysicalDeviceCoverageReductionModeFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceCoverageReductionModeFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineCoverageReductionStateCreateInfoNV* TrackStruct(const VkPipelineCoverageReductionStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineCoverageReductionStateCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkFramebufferMixedSamplesCombinationNV* TrackStruct(const VkFramebufferMixedSamplesCombinationNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkFramebufferMixedSamplesCombinationNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* TrackStruct(const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* TrackStruct(const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceProvokingVertexFeaturesEXT* TrackStruct(const VkPhysicalDeviceProvokingVertexFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceProvokingVertexFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceProvokingVertexPropertiesEXT* TrackStruct(const VkPhysicalDeviceProvokingVertexPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceProvokingVertexPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineRasterizationProvokingVertexStateCreateInfoEXT* TrackStruct(const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineRasterizationProvokingVertexStateCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSurfaceFullScreenExclusiveInfoEXT* TrackStruct(const VkSurfaceFullScreenExclusiveInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSurfaceFullScreenExclusiveInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSurfaceCapabilitiesFullScreenExclusiveEXT* TrackStruct(const VkSurfaceCapabilitiesFullScreenExclusiveEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSurfaceCapabilitiesFullScreenExclusiveEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSurfaceFullScreenExclusiveWin32InfoEXT* TrackStruct(const VkSurfaceFullScreenExclusiveWin32InfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSurfaceFullScreenExclusiveWin32InfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkHeadlessSurfaceCreateInfoEXT* TrackStruct(const VkHeadlessSurfaceCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkHeadlessSurfaceCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* TrackStruct(const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* TrackStruct(const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceHostImageCopyFeaturesEXT* TrackStruct(const VkPhysicalDeviceHostImageCopyFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceHostImageCopyFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceHostImageCopyPropertiesEXT* TrackStruct(const VkPhysicalDeviceHostImageCopyPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceHostImageCopyPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pCopySrcLayouts)
    {
        unwrapped_struct->pCopySrcLayouts = MakeUnwrapVulkanStructs(unwrapped_struct->pCopySrcLayouts, unwrapped_struct->copySrcLayoutCount, unwrap_memory);
    }
    if (unwrapped_struct->pCopyDstLayouts)
    {
        unwrapped_struct->pCopyDstLayouts = MakeUnwrapVulkanStructs(unwrapped_struct->pCopyDstLayouts, unwrapped_struct->copyDstLayoutCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMemoryToImageCopyEXT* TrackStruct(const VkMemoryToImageCopyEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMemoryToImageCopyEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageToMemoryCopyEXT* TrackStruct(const VkImageToMemoryCopyEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageToMemoryCopyEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCopyMemoryToImageInfoEXT* TrackStruct(const VkCopyMemoryToImageInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCopyMemoryToImageInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pRegions)
    {
        unwrapped_struct->pRegions = MakeUnwrapVulkanStructs(unwrapped_struct->pRegions, unwrapped_struct->regionCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCopyImageToMemoryInfoEXT* TrackStruct(const VkCopyImageToMemoryInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCopyImageToMemoryInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pRegions)
    {
        unwrapped_struct->pRegions = MakeUnwrapVulkanStructs(unwrapped_struct->pRegions, unwrapped_struct->regionCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCopyImageToImageInfoEXT* TrackStruct(const VkCopyImageToImageInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCopyImageToImageInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pRegions)
    {
        unwrapped_struct->pRegions = MakeUnwrapVulkanStructs(unwrapped_struct->pRegions, unwrapped_struct->regionCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkHostImageLayoutTransitionInfoEXT* TrackStruct(const VkHostImageLayoutTransitionInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkHostImageLayoutTransitionInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSubresourceHostMemcpySizeEXT* TrackStruct(const VkSubresourceHostMemcpySizeEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSubresourceHostMemcpySizeEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkHostImageCopyDevicePerformanceQueryEXT* TrackStruct(const VkHostImageCopyDevicePerformanceQueryEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkHostImageCopyDevicePerformanceQueryEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMapMemoryPlacedFeaturesEXT* TrackStruct(const VkPhysicalDeviceMapMemoryPlacedFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMapMemoryPlacedFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMapMemoryPlacedPropertiesEXT* TrackStruct(const VkPhysicalDeviceMapMemoryPlacedPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMapMemoryPlacedPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMemoryMapPlacedInfoEXT* TrackStruct(const VkMemoryMapPlacedInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMemoryMapPlacedInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* TrackStruct(const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSurfacePresentModeEXT* TrackStruct(const VkSurfacePresentModeEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSurfacePresentModeEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSurfacePresentScalingCapabilitiesEXT* TrackStruct(const VkSurfacePresentScalingCapabilitiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSurfacePresentScalingCapabilitiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSurfacePresentModeCompatibilityEXT* TrackStruct(const VkSurfacePresentModeCompatibilityEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSurfacePresentModeCompatibilityEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pPresentModes)
    {
        unwrapped_struct->pPresentModes = MakeUnwrapVulkanStructs(unwrapped_struct->pPresentModes, unwrapped_struct->presentModeCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT* TrackStruct(const VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSwapchainPresentFenceInfoEXT* TrackStruct(const VkSwapchainPresentFenceInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSwapchainPresentFenceInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pFences)
    {
        unwrapped_struct->pFences = MakeUnwrapVulkanStructs(unwrapped_struct->pFences, unwrapped_struct->swapchainCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSwapchainPresentModesCreateInfoEXT* TrackStruct(const VkSwapchainPresentModesCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSwapchainPresentModesCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pPresentModes)
    {
        unwrapped_struct->pPresentModes = MakeUnwrapVulkanStructs(unwrapped_struct->pPresentModes, unwrapped_struct->presentModeCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSwapchainPresentModeInfoEXT* TrackStruct(const VkSwapchainPresentModeInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSwapchainPresentModeInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pPresentModes)
    {
        unwrapped_struct->pPresentModes = MakeUnwrapVulkanStructs(unwrapped_struct->pPresentModes, unwrapped_struct->swapchainCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSwapchainPresentScalingCreateInfoEXT* TrackStruct(const VkSwapchainPresentScalingCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSwapchainPresentScalingCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkReleaseSwapchainImagesInfoEXT* TrackStruct(const VkReleaseSwapchainImagesInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkReleaseSwapchainImagesInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pImageIndices)
    {
        unwrapped_struct->pImageIndices = MakeUnwrapVulkanStructs(unwrapped_struct->pImageIndices, unwrapped_struct->imageIndexCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* TrackStruct(const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* TrackStruct(const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkGraphicsShaderGroupCreateInfoNV* TrackStruct(const VkGraphicsShaderGroupCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkGraphicsShaderGroupCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pStages)
    {
        unwrapped_struct->pStages = MakeUnwrapVulkanStructs(unwrapped_struct->pStages, unwrapped_struct->stageCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkGraphicsPipelineShaderGroupsCreateInfoNV* TrackStruct(const VkGraphicsPipelineShaderGroupsCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkGraphicsPipelineShaderGroupsCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pGroups)
    {
        unwrapped_struct->pGroups = MakeUnwrapVulkanStructs(unwrapped_struct->pGroups, unwrapped_struct->groupCount, unwrap_memory);
    }
    if (unwrapped_struct->pPipelines)
    {
        unwrapped_struct->pPipelines = MakeUnwrapVulkanStructs(unwrapped_struct->pPipelines, unwrapped_struct->pipelineCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkIndirectCommandsLayoutTokenNV* TrackStruct(const VkIndirectCommandsLayoutTokenNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkIndirectCommandsLayoutTokenNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pIndexTypes)
    {
        unwrapped_struct->pIndexTypes = MakeUnwrapVulkanStructs(unwrapped_struct->pIndexTypes, unwrapped_struct->indexTypeCount, unwrap_memory);
    }
    if (unwrapped_struct->pIndexTypeValues)
    {
        unwrapped_struct->pIndexTypeValues = MakeUnwrapVulkanStructs(unwrapped_struct->pIndexTypeValues, unwrapped_struct->indexTypeCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkIndirectCommandsLayoutCreateInfoNV* TrackStruct(const VkIndirectCommandsLayoutCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkIndirectCommandsLayoutCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pTokens)
    {
        unwrapped_struct->pTokens = MakeUnwrapVulkanStructs(unwrapped_struct->pTokens, unwrapped_struct->tokenCount, unwrap_memory);
    }
    if (unwrapped_struct->pStreamStrides)
    {
        unwrapped_struct->pStreamStrides = MakeUnwrapVulkanStructs(unwrapped_struct->pStreamStrides, unwrapped_struct->streamCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkGeneratedCommandsInfoNV* TrackStruct(const VkGeneratedCommandsInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkGeneratedCommandsInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pStreams)
    {
        unwrapped_struct->pStreams = MakeUnwrapVulkanStructs(unwrapped_struct->pStreams, unwrapped_struct->streamCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkGeneratedCommandsMemoryRequirementsInfoNV* TrackStruct(const VkGeneratedCommandsMemoryRequirementsInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkGeneratedCommandsMemoryRequirementsInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceInheritedViewportScissorFeaturesNV* TrackStruct(const VkPhysicalDeviceInheritedViewportScissorFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceInheritedViewportScissorFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCommandBufferInheritanceViewportScissorInfoNV* TrackStruct(const VkCommandBufferInheritanceViewportScissorInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCommandBufferInheritanceViewportScissorInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* TrackStruct(const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRenderPassTransformBeginInfoQCOM* TrackStruct(const VkRenderPassTransformBeginInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRenderPassTransformBeginInfoQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCommandBufferInheritanceRenderPassTransformInfoQCOM* TrackStruct(const VkCommandBufferInheritanceRenderPassTransformInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCommandBufferInheritanceRenderPassTransformInfoQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDepthBiasControlFeaturesEXT* TrackStruct(const VkPhysicalDeviceDepthBiasControlFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDepthBiasControlFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDepthBiasInfoEXT* TrackStruct(const VkDepthBiasInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDepthBiasInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDepthBiasRepresentationInfoEXT* TrackStruct(const VkDepthBiasRepresentationInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDepthBiasRepresentationInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* TrackStruct(const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceMemoryReportCallbackDataEXT* TrackStruct(const VkDeviceMemoryReportCallbackDataEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceMemoryReportCallbackDataEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceDeviceMemoryReportCreateInfoEXT* TrackStruct(const VkDeviceDeviceMemoryReportCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceDeviceMemoryReportCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceRobustness2FeaturesEXT* TrackStruct(const VkPhysicalDeviceRobustness2FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceRobustness2FeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceRobustness2PropertiesEXT* TrackStruct(const VkPhysicalDeviceRobustness2PropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceRobustness2PropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSamplerCustomBorderColorCreateInfoEXT* TrackStruct(const VkSamplerCustomBorderColorCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSamplerCustomBorderColorCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceCustomBorderColorPropertiesEXT* TrackStruct(const VkPhysicalDeviceCustomBorderColorPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceCustomBorderColorPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceCustomBorderColorFeaturesEXT* TrackStruct(const VkPhysicalDeviceCustomBorderColorFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceCustomBorderColorFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevicePresentBarrierFeaturesNV* TrackStruct(const VkPhysicalDevicePresentBarrierFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevicePresentBarrierFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSurfaceCapabilitiesPresentBarrierNV* TrackStruct(const VkSurfaceCapabilitiesPresentBarrierNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSurfaceCapabilitiesPresentBarrierNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSwapchainPresentBarrierCreateInfoNV* TrackStruct(const VkSwapchainPresentBarrierCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSwapchainPresentBarrierCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDiagnosticsConfigFeaturesNV* TrackStruct(const VkPhysicalDeviceDiagnosticsConfigFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDiagnosticsConfigFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceDiagnosticsConfigCreateInfoNV* TrackStruct(const VkDeviceDiagnosticsConfigCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceDiagnosticsConfigCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkQueryLowLatencySupportNV* TrackStruct(const VkQueryLowLatencySupportNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkQueryLowLatencySupportNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* TrackStruct(const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT* TrackStruct(const VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkGraphicsPipelineLibraryCreateInfoEXT* TrackStruct(const VkGraphicsPipelineLibraryCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkGraphicsPipelineLibraryCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* TrackStruct(const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* TrackStruct(const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV* TrackStruct(const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineFragmentShadingRateEnumStateCreateInfoNV* TrackStruct(const VkPipelineFragmentShadingRateEnumStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineFragmentShadingRateEnumStateCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAccelerationStructureGeometryMotionTrianglesDataNV* TrackStruct(const VkAccelerationStructureGeometryMotionTrianglesDataNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAccelerationStructureGeometryMotionTrianglesDataNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAccelerationStructureMotionInfoNV* TrackStruct(const VkAccelerationStructureMotionInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAccelerationStructureMotionInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* TrackStruct(const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* TrackStruct(const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* TrackStruct(const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceFragmentDensityMap2PropertiesEXT* TrackStruct(const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceFragmentDensityMap2PropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCopyCommandTransformInfoQCOM* TrackStruct(const VkCopyCommandTransformInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCopyCommandTransformInfoQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceImageCompressionControlFeaturesEXT* TrackStruct(const VkPhysicalDeviceImageCompressionControlFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceImageCompressionControlFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageCompressionControlEXT* TrackStruct(const VkImageCompressionControlEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageCompressionControlEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pFixedRateFlags)
    {
        unwrapped_struct->pFixedRateFlags = MakeUnwrapVulkanStructs(unwrapped_struct->pFixedRateFlags, unwrapped_struct->compressionControlPlaneCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageCompressionPropertiesEXT* TrackStruct(const VkImageCompressionPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageCompressionPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* TrackStruct(const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevice4444FormatsFeaturesEXT* TrackStruct(const VkPhysicalDevice4444FormatsFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevice4444FormatsFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceFaultFeaturesEXT* TrackStruct(const VkPhysicalDeviceFaultFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceFaultFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceFaultCountsEXT* TrackStruct(const VkDeviceFaultCountsEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceFaultCountsEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceFaultInfoEXT* TrackStruct(const VkDeviceFaultInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceFaultInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* TrackStruct(const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* TrackStruct(const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDirectFBSurfaceCreateInfoEXT* TrackStruct(const VkDirectFBSurfaceCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDirectFBSurfaceCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* TrackStruct(const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMutableDescriptorTypeCreateInfoEXT* TrackStruct(const VkMutableDescriptorTypeCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMutableDescriptorTypeCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pMutableDescriptorTypeLists)
    {
        unwrapped_struct->pMutableDescriptorTypeLists = MakeUnwrapVulkanStructs(unwrapped_struct->pMutableDescriptorTypeLists, unwrapped_struct->mutableDescriptorTypeListCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* TrackStruct(const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVertexInputBindingDescription2EXT* TrackStruct(const VkVertexInputBindingDescription2EXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVertexInputBindingDescription2EXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkVertexInputAttributeDescription2EXT* TrackStruct(const VkVertexInputAttributeDescription2EXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkVertexInputAttributeDescription2EXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDrmPropertiesEXT* TrackStruct(const VkPhysicalDeviceDrmPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDrmPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceAddressBindingReportFeaturesEXT* TrackStruct(const VkPhysicalDeviceAddressBindingReportFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceAddressBindingReportFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceAddressBindingCallbackDataEXT* TrackStruct(const VkDeviceAddressBindingCallbackDataEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceAddressBindingCallbackDataEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDepthClipControlFeaturesEXT* TrackStruct(const VkPhysicalDeviceDepthClipControlFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDepthClipControlFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineViewportDepthClipControlCreateInfoEXT* TrackStruct(const VkPipelineViewportDepthClipControlCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineViewportDepthClipControlCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* TrackStruct(const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImportMemoryZirconHandleInfoFUCHSIA* TrackStruct(const VkImportMemoryZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImportMemoryZirconHandleInfoFUCHSIA* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMemoryZirconHandlePropertiesFUCHSIA* TrackStruct(const VkMemoryZirconHandlePropertiesFUCHSIA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMemoryZirconHandlePropertiesFUCHSIA* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMemoryGetZirconHandleInfoFUCHSIA* TrackStruct(const VkMemoryGetZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMemoryGetZirconHandleInfoFUCHSIA* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImportSemaphoreZirconHandleInfoFUCHSIA* TrackStruct(const VkImportSemaphoreZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImportSemaphoreZirconHandleInfoFUCHSIA* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSemaphoreGetZirconHandleInfoFUCHSIA* TrackStruct(const VkSemaphoreGetZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSemaphoreGetZirconHandleInfoFUCHSIA* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* TrackStruct(const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMemoryGetRemoteAddressInfoNV* TrackStruct(const VkMemoryGetRemoteAddressInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMemoryGetRemoteAddressInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* TrackStruct(const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceFrameBoundaryFeaturesEXT* TrackStruct(const VkPhysicalDeviceFrameBoundaryFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceFrameBoundaryFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkFrameBoundaryEXT* TrackStruct(const VkFrameBoundaryEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkFrameBoundaryEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pImages)
    {
        unwrapped_struct->pImages = MakeUnwrapVulkanStructs(unwrapped_struct->pImages, unwrapped_struct->imageCount, unwrap_memory);
    }
    if (unwrapped_struct->pBuffers)
    {
        unwrapped_struct->pBuffers = MakeUnwrapVulkanStructs(unwrapped_struct->pBuffers, unwrapped_struct->bufferCount, unwrap_memory);
    }
    if (unwrapped_struct->pTag)
    {
        unwrapped_struct->pTag = MakeUnwrapVulkanStructs<uint8_t>(reinterpret_cast<const uint8_t*>(unwrapped_struct->pTag), unwrapped_struct->tagSize, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* TrackStruct(const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSubpassResolvePerformanceQueryEXT* TrackStruct(const VkSubpassResolvePerformanceQueryEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSubpassResolvePerformanceQueryEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMultisampledRenderToSingleSampledInfoEXT* TrackStruct(const VkMultisampledRenderToSingleSampledInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMultisampledRenderToSingleSampledInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* TrackStruct(const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkScreenSurfaceCreateInfoQNX* TrackStruct(const VkScreenSurfaceCreateInfoQNX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkScreenSurfaceCreateInfoQNX* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceColorWriteEnableFeaturesEXT* TrackStruct(const VkPhysicalDeviceColorWriteEnableFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceColorWriteEnableFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineColorWriteCreateInfoEXT* TrackStruct(const VkPipelineColorWriteCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineColorWriteCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pColorWriteEnables)
    {
        unwrapped_struct->pColorWriteEnables = MakeUnwrapVulkanStructs(unwrapped_struct->pColorWriteEnables, unwrapped_struct->attachmentCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* TrackStruct(const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceImageViewMinLodFeaturesEXT* TrackStruct(const VkPhysicalDeviceImageViewMinLodFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceImageViewMinLodFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageViewMinLodCreateInfoEXT* TrackStruct(const VkImageViewMinLodCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageViewMinLodCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMultiDrawFeaturesEXT* TrackStruct(const VkPhysicalDeviceMultiDrawFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMultiDrawFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMultiDrawPropertiesEXT* TrackStruct(const VkPhysicalDeviceMultiDrawPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMultiDrawPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* TrackStruct(const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderTileImageFeaturesEXT* TrackStruct(const VkPhysicalDeviceShaderTileImageFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderTileImageFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderTileImagePropertiesEXT* TrackStruct(const VkPhysicalDeviceShaderTileImagePropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderTileImagePropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMicromapBuildInfoEXT* TrackStruct(const VkMicromapBuildInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMicromapBuildInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pUsageCounts)
    {
        unwrapped_struct->pUsageCounts = MakeUnwrapVulkanStructs(unwrapped_struct->pUsageCounts, unwrapped_struct->usageCountsCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMicromapCreateInfoEXT* TrackStruct(const VkMicromapCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMicromapCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceOpacityMicromapFeaturesEXT* TrackStruct(const VkPhysicalDeviceOpacityMicromapFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceOpacityMicromapFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceOpacityMicromapPropertiesEXT* TrackStruct(const VkPhysicalDeviceOpacityMicromapPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceOpacityMicromapPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMicromapVersionInfoEXT* TrackStruct(const VkMicromapVersionInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMicromapVersionInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pVersionData)
    {
        unwrapped_struct->pVersionData = MakeUnwrapVulkanStructs(unwrapped_struct->pVersionData, 2*VK_UUID_SIZE, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCopyMicromapToMemoryInfoEXT* TrackStruct(const VkCopyMicromapToMemoryInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCopyMicromapToMemoryInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCopyMemoryToMicromapInfoEXT* TrackStruct(const VkCopyMemoryToMicromapInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCopyMemoryToMicromapInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCopyMicromapInfoEXT* TrackStruct(const VkCopyMicromapInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCopyMicromapInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMicromapBuildSizesInfoEXT* TrackStruct(const VkMicromapBuildSizesInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMicromapBuildSizesInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAccelerationStructureTrianglesOpacityMicromapEXT* TrackStruct(const VkAccelerationStructureTrianglesOpacityMicromapEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAccelerationStructureTrianglesOpacityMicromapEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pUsageCounts)
    {
        unwrapped_struct->pUsageCounts = MakeUnwrapVulkanStructs(unwrapped_struct->pUsageCounts, unwrapped_struct->usageCountsCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDisplacementMicromapFeaturesNV* TrackStruct(const VkPhysicalDeviceDisplacementMicromapFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDisplacementMicromapFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDisplacementMicromapPropertiesNV* TrackStruct(const VkPhysicalDeviceDisplacementMicromapPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDisplacementMicromapPropertiesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAccelerationStructureTrianglesDisplacementMicromapNV* TrackStruct(const VkAccelerationStructureTrianglesDisplacementMicromapNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAccelerationStructureTrianglesDisplacementMicromapNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pUsageCounts)
    {
        unwrapped_struct->pUsageCounts = MakeUnwrapVulkanStructs(unwrapped_struct->pUsageCounts, unwrapped_struct->usageCountsCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI* TrackStruct(const VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI* TrackStruct(const VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI* TrackStruct(const VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* TrackStruct(const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSamplerBorderColorComponentMappingCreateInfoEXT* TrackStruct(const VkSamplerBorderColorComponentMappingCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSamplerBorderColorComponentMappingCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* TrackStruct(const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderCorePropertiesARM* TrackStruct(const VkPhysicalDeviceShaderCorePropertiesARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderCorePropertiesARM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDeviceQueueShaderCoreControlCreateInfoARM* TrackStruct(const VkDeviceQueueShaderCoreControlCreateInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDeviceQueueShaderCoreControlCreateInfoARM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceSchedulingControlsFeaturesARM* TrackStruct(const VkPhysicalDeviceSchedulingControlsFeaturesARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceSchedulingControlsFeaturesARM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceSchedulingControlsPropertiesARM* TrackStruct(const VkPhysicalDeviceSchedulingControlsPropertiesARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceSchedulingControlsPropertiesARM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT* TrackStruct(const VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageViewSlicedCreateInfoEXT* TrackStruct(const VkImageViewSlicedCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageViewSlicedCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* TrackStruct(const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDescriptorSetBindingReferenceVALVE* TrackStruct(const VkDescriptorSetBindingReferenceVALVE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDescriptorSetBindingReferenceVALVE* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDescriptorSetLayoutHostMappingInfoVALVE* TrackStruct(const VkDescriptorSetLayoutHostMappingInfoVALVE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDescriptorSetLayoutHostMappingInfoVALVE* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDepthClampZeroOneFeaturesEXT* TrackStruct(const VkPhysicalDeviceDepthClampZeroOneFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDepthClampZeroOneFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* TrackStruct(const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceRenderPassStripedFeaturesARM* TrackStruct(const VkPhysicalDeviceRenderPassStripedFeaturesARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceRenderPassStripedFeaturesARM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceRenderPassStripedPropertiesARM* TrackStruct(const VkPhysicalDeviceRenderPassStripedPropertiesARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceRenderPassStripedPropertiesARM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRenderPassStripeInfoARM* TrackStruct(const VkRenderPassStripeInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRenderPassStripeInfoARM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRenderPassStripeBeginInfoARM* TrackStruct(const VkRenderPassStripeBeginInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRenderPassStripeBeginInfoARM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pStripeInfos)
    {
        unwrapped_struct->pStripeInfos = MakeUnwrapVulkanStructs(unwrapped_struct->pStripeInfos, unwrapped_struct->stripeInfoCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRenderPassStripeSubmitInfoARM* TrackStruct(const VkRenderPassStripeSubmitInfoARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRenderPassStripeSubmitInfoARM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pStripeSemaphoreInfos)
    {
        unwrapped_struct->pStripeSemaphoreInfos = MakeUnwrapVulkanStructs(unwrapped_struct->pStripeSemaphoreInfos, unwrapped_struct->stripeSemaphoreInfoCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM* TrackStruct(const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM* TrackStruct(const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSubpassFragmentDensityMapOffsetEndInfoQCOM* TrackStruct(const VkSubpassFragmentDensityMapOffsetEndInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSubpassFragmentDensityMapOffsetEndInfoQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pFragmentDensityOffsets)
    {
        unwrapped_struct->pFragmentDensityOffsets = MakeUnwrapVulkanStructs(unwrapped_struct->pFragmentDensityOffsets, unwrapped_struct->fragmentDensityOffsetCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV* TrackStruct(const VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkComputePipelineIndirectBufferInfoNV* TrackStruct(const VkComputePipelineIndirectBufferInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkComputePipelineIndirectBufferInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineIndirectDeviceAddressInfoNV* TrackStruct(const VkPipelineIndirectDeviceAddressInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineIndirectDeviceAddressInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceLinearColorAttachmentFeaturesNV* TrackStruct(const VkPhysicalDeviceLinearColorAttachmentFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceLinearColorAttachmentFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* TrackStruct(const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkImageViewSampleWeightCreateInfoQCOM* TrackStruct(const VkImageViewSampleWeightCreateInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkImageViewSampleWeightCreateInfoQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceImageProcessingFeaturesQCOM* TrackStruct(const VkPhysicalDeviceImageProcessingFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceImageProcessingFeaturesQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceImageProcessingPropertiesQCOM* TrackStruct(const VkPhysicalDeviceImageProcessingPropertiesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceImageProcessingPropertiesQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceNestedCommandBufferFeaturesEXT* TrackStruct(const VkPhysicalDeviceNestedCommandBufferFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceNestedCommandBufferFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceNestedCommandBufferPropertiesEXT* TrackStruct(const VkPhysicalDeviceNestedCommandBufferPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceNestedCommandBufferPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkExternalMemoryAcquireUnmodifiedEXT* TrackStruct(const VkExternalMemoryAcquireUnmodifiedEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkExternalMemoryAcquireUnmodifiedEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* TrackStruct(const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceExtendedDynamicState3PropertiesEXT* TrackStruct(const VkPhysicalDeviceExtendedDynamicState3PropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceExtendedDynamicState3PropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* TrackStruct(const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRenderPassCreationControlEXT* TrackStruct(const VkRenderPassCreationControlEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRenderPassCreationControlEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRenderPassCreationFeedbackCreateInfoEXT* TrackStruct(const VkRenderPassCreationFeedbackCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRenderPassCreationFeedbackCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRenderPassSubpassFeedbackCreateInfoEXT* TrackStruct(const VkRenderPassSubpassFeedbackCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRenderPassSubpassFeedbackCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDirectDriverLoadingInfoLUNARG* TrackStruct(const VkDirectDriverLoadingInfoLUNARG* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDirectDriverLoadingInfoLUNARG* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkDirectDriverLoadingListLUNARG* TrackStruct(const VkDirectDriverLoadingListLUNARG* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkDirectDriverLoadingListLUNARG* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pDrivers)
    {
        unwrapped_struct->pDrivers = MakeUnwrapVulkanStructs(unwrapped_struct->pDrivers, unwrapped_struct->driverCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* TrackStruct(const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT* TrackStruct(const VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPipelineShaderStageModuleIdentifierCreateInfoEXT* TrackStruct(const VkPipelineShaderStageModuleIdentifierCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPipelineShaderStageModuleIdentifierCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pIdentifier)
    {
        unwrapped_struct->pIdentifier = MakeUnwrapVulkanStructs(unwrapped_struct->pIdentifier, unwrapped_struct->identifierSize, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkShaderModuleIdentifierEXT* TrackStruct(const VkShaderModuleIdentifierEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkShaderModuleIdentifierEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceOpticalFlowFeaturesNV* TrackStruct(const VkPhysicalDeviceOpticalFlowFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceOpticalFlowFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceOpticalFlowPropertiesNV* TrackStruct(const VkPhysicalDeviceOpticalFlowPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceOpticalFlowPropertiesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkOpticalFlowImageFormatInfoNV* TrackStruct(const VkOpticalFlowImageFormatInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkOpticalFlowImageFormatInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkOpticalFlowImageFormatPropertiesNV* TrackStruct(const VkOpticalFlowImageFormatPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkOpticalFlowImageFormatPropertiesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkOpticalFlowSessionCreateInfoNV* TrackStruct(const VkOpticalFlowSessionCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkOpticalFlowSessionCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkOpticalFlowSessionCreatePrivateDataInfoNV* TrackStruct(const VkOpticalFlowSessionCreatePrivateDataInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkOpticalFlowSessionCreatePrivateDataInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkOpticalFlowExecuteInfoNV* TrackStruct(const VkOpticalFlowExecuteInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkOpticalFlowExecuteInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pRegions)
    {
        unwrapped_struct->pRegions = MakeUnwrapVulkanStructs(unwrapped_struct->pRegions, unwrapped_struct->regionCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceLegacyDitheringFeaturesEXT* TrackStruct(const VkPhysicalDeviceLegacyDitheringFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceLegacyDitheringFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevicePipelineProtectedAccessFeaturesEXT* TrackStruct(const VkPhysicalDevicePipelineProtectedAccessFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevicePipelineProtectedAccessFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceExternalFormatResolveFeaturesANDROID* TrackStruct(const VkPhysicalDeviceExternalFormatResolveFeaturesANDROID* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceExternalFormatResolveFeaturesANDROID* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceExternalFormatResolvePropertiesANDROID* TrackStruct(const VkPhysicalDeviceExternalFormatResolvePropertiesANDROID* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceExternalFormatResolvePropertiesANDROID* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAndroidHardwareBufferFormatResolvePropertiesANDROID* TrackStruct(const VkAndroidHardwareBufferFormatResolvePropertiesANDROID* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAndroidHardwareBufferFormatResolvePropertiesANDROID* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderObjectFeaturesEXT* TrackStruct(const VkPhysicalDeviceShaderObjectFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderObjectFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderObjectPropertiesEXT* TrackStruct(const VkPhysicalDeviceShaderObjectPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderObjectPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkShaderCreateInfoEXT* TrackStruct(const VkShaderCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkShaderCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pCode)
    {
        unwrapped_struct->pCode = MakeUnwrapVulkanStructs<uint8_t>(reinterpret_cast<const uint8_t*>(unwrapped_struct->pCode), unwrapped_struct->codeSize, unwrap_memory);
    }
    if (unwrapped_struct->pSetLayouts)
    {
        unwrapped_struct->pSetLayouts = MakeUnwrapVulkanStructs(unwrapped_struct->pSetLayouts, unwrapped_struct->setLayoutCount, unwrap_memory);
    }
    if (unwrapped_struct->pPushConstantRanges)
    {
        unwrapped_struct->pPushConstantRanges = MakeUnwrapVulkanStructs(unwrapped_struct->pPushConstantRanges, unwrapped_struct->pushConstantRangeCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceTilePropertiesFeaturesQCOM* TrackStruct(const VkPhysicalDeviceTilePropertiesFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceTilePropertiesFeaturesQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkTilePropertiesQCOM* TrackStruct(const VkTilePropertiesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkTilePropertiesQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceAmigoProfilingFeaturesSEC* TrackStruct(const VkPhysicalDeviceAmigoProfilingFeaturesSEC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceAmigoProfilingFeaturesSEC* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAmigoProfilingSubmitInfoSEC* TrackStruct(const VkAmigoProfilingSubmitInfoSEC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAmigoProfilingSubmitInfoSEC* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* TrackStruct(const VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV* TrackStruct(const VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV* TrackStruct(const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV* TrackStruct(const VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV* TrackStruct(const VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkLayerSettingsCreateInfoEXT* TrackStruct(const VkLayerSettingsCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkLayerSettingsCreateInfoEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pSettings)
    {
        unwrapped_struct->pSettings = MakeUnwrapVulkanStructs(unwrapped_struct->pSettings, unwrapped_struct->settingCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* TrackStruct(const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM* TrackStruct(const VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT* TrackStruct(const VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT* TrackStruct(const VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkLatencySleepModeInfoNV* TrackStruct(const VkLatencySleepModeInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkLatencySleepModeInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkLatencySleepInfoNV* TrackStruct(const VkLatencySleepInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkLatencySleepInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSetLatencyMarkerInfoNV* TrackStruct(const VkSetLatencyMarkerInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSetLatencyMarkerInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkLatencyTimingsFrameReportNV* TrackStruct(const VkLatencyTimingsFrameReportNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkLatencyTimingsFrameReportNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkGetLatencyMarkerInfoNV* TrackStruct(const VkGetLatencyMarkerInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkGetLatencyMarkerInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pTimings)
    {
        unwrapped_struct->pTimings = MakeUnwrapVulkanStructs(unwrapped_struct->pTimings, unwrapped_struct->timingCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkLatencySubmissionPresentIdNV* TrackStruct(const VkLatencySubmissionPresentIdNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkLatencySubmissionPresentIdNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSwapchainLatencyCreateInfoNV* TrackStruct(const VkSwapchainLatencyCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSwapchainLatencyCreateInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkOutOfBandQueueTypeInfoNV* TrackStruct(const VkOutOfBandQueueTypeInfoNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkOutOfBandQueueTypeInfoNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkLatencySurfaceCapabilitiesNV* TrackStruct(const VkLatencySurfaceCapabilitiesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkLatencySurfaceCapabilitiesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pPresentModes)
    {
        unwrapped_struct->pPresentModes = MakeUnwrapVulkanStructs(unwrapped_struct->pPresentModes, unwrapped_struct->presentModeCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM* TrackStruct(const VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM* TrackStruct(const VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pPerViewRenderAreas)
    {
        unwrapped_struct->pPerViewRenderAreas = MakeUnwrapVulkanStructs(unwrapped_struct->pPerViewRenderAreas, unwrapped_struct->perViewRenderAreaCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDevicePerStageDescriptorSetFeaturesNV* TrackStruct(const VkPhysicalDevicePerStageDescriptorSetFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDevicePerStageDescriptorSetFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceImageProcessing2FeaturesQCOM* TrackStruct(const VkPhysicalDeviceImageProcessing2FeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceImageProcessing2FeaturesQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceImageProcessing2PropertiesQCOM* TrackStruct(const VkPhysicalDeviceImageProcessing2PropertiesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceImageProcessing2PropertiesQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSamplerBlockMatchWindowCreateInfoQCOM* TrackStruct(const VkSamplerBlockMatchWindowCreateInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSamplerBlockMatchWindowCreateInfoQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceCubicWeightsFeaturesQCOM* TrackStruct(const VkPhysicalDeviceCubicWeightsFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceCubicWeightsFeaturesQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSamplerCubicWeightsCreateInfoQCOM* TrackStruct(const VkSamplerCubicWeightsCreateInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSamplerCubicWeightsCreateInfoQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkBlitImageCubicWeightsInfoQCOM* TrackStruct(const VkBlitImageCubicWeightsInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkBlitImageCubicWeightsInfoQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceYcbcrDegammaFeaturesQCOM* TrackStruct(const VkPhysicalDeviceYcbcrDegammaFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceYcbcrDegammaFeaturesQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM* TrackStruct(const VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceCubicClampFeaturesQCOM* TrackStruct(const VkPhysicalDeviceCubicClampFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceCubicClampFeaturesQCOM* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT* TrackStruct(const VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceLayeredDriverPropertiesMSFT* TrackStruct(const VkPhysicalDeviceLayeredDriverPropertiesMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceLayeredDriverPropertiesMSFT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV* TrackStruct(const VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceRawAccessChainsFeaturesNV* TrackStruct(const VkPhysicalDeviceRawAccessChainsFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceRawAccessChainsFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV* TrackStruct(const VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceRayTracingValidationFeaturesNV* TrackStruct(const VkPhysicalDeviceRayTracingValidationFeaturesNV* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceRayTracingValidationFeaturesNV* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAccelerationStructureGeometryTrianglesDataKHR* TrackStruct(const VkAccelerationStructureGeometryTrianglesDataKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAccelerationStructureGeometryTrianglesDataKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAccelerationStructureGeometryAabbsDataKHR* TrackStruct(const VkAccelerationStructureGeometryAabbsDataKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAccelerationStructureGeometryAabbsDataKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAccelerationStructureGeometryInstancesDataKHR* TrackStruct(const VkAccelerationStructureGeometryInstancesDataKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAccelerationStructureGeometryInstancesDataKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAccelerationStructureGeometryKHR* TrackStruct(const VkAccelerationStructureGeometryKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAccelerationStructureGeometryKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAccelerationStructureBuildGeometryInfoKHR* TrackStruct(const VkAccelerationStructureBuildGeometryInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAccelerationStructureBuildGeometryInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pGeometries)
    {
        unwrapped_struct->pGeometries = MakeUnwrapVulkanStructs(unwrapped_struct->pGeometries, unwrapped_struct->geometryCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAccelerationStructureCreateInfoKHR* TrackStruct(const VkAccelerationStructureCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAccelerationStructureCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkWriteDescriptorSetAccelerationStructureKHR* TrackStruct(const VkWriteDescriptorSetAccelerationStructureKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkWriteDescriptorSetAccelerationStructureKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pAccelerationStructures)
    {
        unwrapped_struct->pAccelerationStructures = MakeUnwrapVulkanStructs(unwrapped_struct->pAccelerationStructures, unwrapped_struct->accelerationStructureCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceAccelerationStructureFeaturesKHR* TrackStruct(const VkPhysicalDeviceAccelerationStructureFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceAccelerationStructureFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceAccelerationStructurePropertiesKHR* TrackStruct(const VkPhysicalDeviceAccelerationStructurePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceAccelerationStructurePropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAccelerationStructureDeviceAddressInfoKHR* TrackStruct(const VkAccelerationStructureDeviceAddressInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAccelerationStructureDeviceAddressInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAccelerationStructureVersionInfoKHR* TrackStruct(const VkAccelerationStructureVersionInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAccelerationStructureVersionInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pVersionData)
    {
        unwrapped_struct->pVersionData = MakeUnwrapVulkanStructs(unwrapped_struct->pVersionData, 2*VK_UUID_SIZE, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCopyAccelerationStructureToMemoryInfoKHR* TrackStruct(const VkCopyAccelerationStructureToMemoryInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCopyAccelerationStructureToMemoryInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCopyMemoryToAccelerationStructureInfoKHR* TrackStruct(const VkCopyMemoryToAccelerationStructureInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCopyMemoryToAccelerationStructureInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkCopyAccelerationStructureInfoKHR* TrackStruct(const VkCopyAccelerationStructureInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkCopyAccelerationStructureInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkAccelerationStructureBuildSizesInfoKHR* TrackStruct(const VkAccelerationStructureBuildSizesInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkAccelerationStructureBuildSizesInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRayTracingShaderGroupCreateInfoKHR* TrackStruct(const VkRayTracingShaderGroupCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRayTracingShaderGroupCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRayTracingPipelineInterfaceCreateInfoKHR* TrackStruct(const VkRayTracingPipelineInterfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRayTracingPipelineInterfaceCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkRayTracingPipelineCreateInfoKHR* TrackStruct(const VkRayTracingPipelineCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkRayTracingPipelineCreateInfoKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->pStages)
    {
        unwrapped_struct->pStages = MakeUnwrapVulkanStructs(unwrapped_struct->pStages, unwrapped_struct->stageCount, unwrap_memory);
    }
    if (unwrapped_struct->pGroups)
    {
        unwrapped_struct->pGroups = MakeUnwrapVulkanStructs(unwrapped_struct->pGroups, unwrapped_struct->groupCount, unwrap_memory);
    }

    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceRayTracingPipelineFeaturesKHR* TrackStruct(const VkPhysicalDeviceRayTracingPipelineFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceRayTracingPipelineFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceRayTracingPipelinePropertiesKHR* TrackStruct(const VkPhysicalDeviceRayTracingPipelinePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceRayTracingPipelinePropertiesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceRayQueryFeaturesKHR* TrackStruct(const VkPhysicalDeviceRayQueryFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceRayQueryFeaturesKHR* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMeshShaderFeaturesEXT* TrackStruct(const VkPhysicalDeviceMeshShaderFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMeshShaderFeaturesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}

VkPhysicalDeviceMeshShaderPropertiesEXT* TrackStruct(const VkPhysicalDeviceMeshShaderPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkPhysicalDeviceMeshShaderPropertiesEXT* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);


    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);

    return unwrapped_struct;
}


void* TrackStruct(const void* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    VkStructureType valueType = reinterpret_cast<const VkBaseInStructure*>(value)->sType;
    switch (valueType)
    {
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER:
            return TrackStruct(reinterpret_cast<const VkBufferMemoryBarrier*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER:
            return TrackStruct(reinterpret_cast<const VkImageMemoryBarrier*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER:
            return TrackStruct(reinterpret_cast<const VkMemoryBarrier*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_APPLICATION_INFO:
            return TrackStruct(reinterpret_cast<const VkApplicationInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkInstanceCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkDeviceQueueCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkDeviceCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SUBMIT_INFO:
            return TrackStruct(reinterpret_cast<const VkSubmitInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE:
            return TrackStruct(reinterpret_cast<const VkMappedMemoryRange*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO:
            return TrackStruct(reinterpret_cast<const VkMemoryAllocateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_SPARSE_INFO:
            return TrackStruct(reinterpret_cast<const VkBindSparseInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_FENCE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkFenceCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkSemaphoreCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_EVENT_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkEventCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkQueryPoolCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkBufferCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkBufferViewCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkImageCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkImageViewCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkShaderModuleCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkPipelineCacheCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkPipelineShaderStageCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkComputePipelineCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkPipelineVertexInputStateCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkPipelineInputAssemblyStateCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkPipelineTessellationStateCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkPipelineViewportStateCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkPipelineRasterizationStateCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkPipelineMultisampleStateCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkPipelineDepthStencilStateCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkPipelineColorBlendStateCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkPipelineDynamicStateCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkGraphicsPipelineCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkPipelineLayoutCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkSamplerCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET:
            return TrackStruct(reinterpret_cast<const VkCopyDescriptorSet*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkDescriptorPoolCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO:
            return TrackStruct(reinterpret_cast<const VkDescriptorSetAllocateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkDescriptorSetLayoutCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET:
            return TrackStruct(reinterpret_cast<const VkWriteDescriptorSet*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkFramebufferCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkRenderPassCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkCommandPoolCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO:
            return TrackStruct(reinterpret_cast<const VkCommandBufferAllocateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO:
            return TrackStruct(reinterpret_cast<const VkCommandBufferInheritanceInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO:
            return TrackStruct(reinterpret_cast<const VkCommandBufferBeginInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO:
            return TrackStruct(reinterpret_cast<const VkRenderPassBeginInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceSubgroupProperties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO:
            return TrackStruct(reinterpret_cast<const VkBindBufferMemoryInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO:
            return TrackStruct(reinterpret_cast<const VkBindImageMemoryInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevice16BitStorageFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
            return TrackStruct(reinterpret_cast<const VkMemoryDedicatedRequirements*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            return TrackStruct(reinterpret_cast<const VkMemoryDedicatedAllocateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
            return TrackStruct(reinterpret_cast<const VkMemoryAllocateFlagsInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            return TrackStruct(reinterpret_cast<const VkDeviceGroupRenderPassBeginInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
            return TrackStruct(reinterpret_cast<const VkDeviceGroupCommandBufferBeginInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
            return TrackStruct(reinterpret_cast<const VkDeviceGroupSubmitInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
            return TrackStruct(reinterpret_cast<const VkDeviceGroupBindSparseInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
            return TrackStruct(reinterpret_cast<const VkBindBufferMemoryDeviceGroupInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            return TrackStruct(reinterpret_cast<const VkBindImageMemoryDeviceGroupInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceGroupProperties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2:
            return TrackStruct(reinterpret_cast<const VkBufferMemoryRequirementsInfo2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2:
            return TrackStruct(reinterpret_cast<const VkImageMemoryRequirementsInfo2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2:
            return TrackStruct(reinterpret_cast<const VkImageSparseMemoryRequirementsInfo2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2:
            return TrackStruct(reinterpret_cast<const VkMemoryRequirements2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2:
            return TrackStruct(reinterpret_cast<const VkSparseImageMemoryRequirements2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceFeatures2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceProperties2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2:
            return TrackStruct(reinterpret_cast<const VkFormatProperties2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2:
            return TrackStruct(reinterpret_cast<const VkImageFormatProperties2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceImageFormatInfo2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2:
            return TrackStruct(reinterpret_cast<const VkQueueFamilyProperties2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMemoryProperties2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2:
            return TrackStruct(reinterpret_cast<const VkSparseImageFormatProperties2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceSparseImageFormatInfo2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevicePointClippingProperties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkRenderPassInputAttachmentAspectCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkImageViewUsageCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkPipelineTessellationDomainOriginStateCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkRenderPassMultiviewCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMultiviewFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMultiviewProperties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceVariablePointersFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceProtectedMemoryFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceProtectedMemoryProperties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2:
            return TrackStruct(reinterpret_cast<const VkDeviceQueueInfo2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
            return TrackStruct(reinterpret_cast<const VkProtectedSubmitInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkSamplerYcbcrConversionCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            return TrackStruct(reinterpret_cast<const VkSamplerYcbcrConversionInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            return TrackStruct(reinterpret_cast<const VkBindImagePlaneMemoryInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
            return TrackStruct(reinterpret_cast<const VkImagePlaneMemoryRequirementsInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkSamplerYcbcrConversionImageFormatProperties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkDescriptorUpdateTemplateCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceExternalImageFormatInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkExternalImageFormatProperties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceExternalBufferInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkExternalBufferProperties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceIDProperties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkExternalMemoryImageCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkExternalMemoryBufferCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
            return TrackStruct(reinterpret_cast<const VkExportMemoryAllocateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceExternalFenceInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkExternalFenceProperties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkExportFenceCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkExportSemaphoreCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceExternalSemaphoreInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkExternalSemaphoreProperties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMaintenance3Properties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT:
            return TrackStruct(reinterpret_cast<const VkDescriptorSetLayoutSupport*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderDrawParametersFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceVulkan11Features*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceVulkan11Properties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceVulkan12Features*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceVulkan12Properties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkImageFormatListCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2:
            return TrackStruct(reinterpret_cast<const VkAttachmentDescription2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2:
            return TrackStruct(reinterpret_cast<const VkAttachmentReference2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2:
            return TrackStruct(reinterpret_cast<const VkSubpassDescription2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2:
            return TrackStruct(reinterpret_cast<const VkSubpassDependency2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2:
            return TrackStruct(reinterpret_cast<const VkRenderPassCreateInfo2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO:
            return TrackStruct(reinterpret_cast<const VkSubpassBeginInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SUBPASS_END_INFO:
            return TrackStruct(reinterpret_cast<const VkSubpassEndInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevice8BitStorageFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDriverProperties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderAtomicInt64Features*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderFloat16Int8Features*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceFloatControlsProperties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkDescriptorSetLayoutBindingFlagsCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingProperties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
            return TrackStruct(reinterpret_cast<const VkDescriptorSetVariableDescriptorCountAllocateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
            return TrackStruct(reinterpret_cast<const VkDescriptorSetVariableDescriptorCountLayoutSupport*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
            return TrackStruct(reinterpret_cast<const VkSubpassDescriptionDepthStencilResolve*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDepthStencilResolveProperties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceScalarBlockLayoutFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkImageStencilUsageCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkSamplerReductionModeCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceSamplerFilterMinmaxProperties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceVulkanMemoryModelFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceImagelessFramebufferFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO:
            return TrackStruct(reinterpret_cast<const VkFramebufferAttachmentImageInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkFramebufferAttachmentsCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            return TrackStruct(reinterpret_cast<const VkRenderPassAttachmentBeginInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
            return TrackStruct(reinterpret_cast<const VkAttachmentReferenceStencilLayout*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
            return TrackStruct(reinterpret_cast<const VkAttachmentDescriptionStencilLayout*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceHostQueryResetFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreProperties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkSemaphoreTypeCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
            return TrackStruct(reinterpret_cast<const VkTimelineSemaphoreSubmitInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO:
            return TrackStruct(reinterpret_cast<const VkSemaphoreWaitInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO:
            return TrackStruct(reinterpret_cast<const VkSemaphoreSignalInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO:
            return TrackStruct(reinterpret_cast<const VkBufferDeviceAddressInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkBufferOpaqueCaptureAddressCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
            return TrackStruct(reinterpret_cast<const VkMemoryOpaqueCaptureAddressAllocateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO:
            return TrackStruct(reinterpret_cast<const VkDeviceMemoryOpaqueCaptureAddressInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceVulkan13Features*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceVulkan13Properties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkPipelineCreationFeedbackCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderTerminateInvocationFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceToolProperties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevicePrivateDataFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkDevicePrivateDataCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkPrivateDataSlotCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevicePipelineCreationCacheControlFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2:
            return TrackStruct(reinterpret_cast<const VkMemoryBarrier2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2:
            return TrackStruct(reinterpret_cast<const VkBufferMemoryBarrier2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2:
            return TrackStruct(reinterpret_cast<const VkImageMemoryBarrier2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEPENDENCY_INFO:
            return TrackStruct(reinterpret_cast<const VkDependencyInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO:
            return TrackStruct(reinterpret_cast<const VkSemaphoreSubmitInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO:
            return TrackStruct(reinterpret_cast<const VkCommandBufferSubmitInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SUBMIT_INFO_2:
            return TrackStruct(reinterpret_cast<const VkSubmitInfo2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceSynchronization2Features*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceImageRobustnessFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BUFFER_COPY_2:
            return TrackStruct(reinterpret_cast<const VkBufferCopy2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2:
            return TrackStruct(reinterpret_cast<const VkCopyBufferInfo2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_COPY_2:
            return TrackStruct(reinterpret_cast<const VkImageCopy2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2:
            return TrackStruct(reinterpret_cast<const VkCopyImageInfo2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2:
            return TrackStruct(reinterpret_cast<const VkBufferImageCopy2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2:
            return TrackStruct(reinterpret_cast<const VkCopyBufferToImageInfo2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2:
            return TrackStruct(reinterpret_cast<const VkCopyImageToBufferInfo2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_BLIT_2:
            return TrackStruct(reinterpret_cast<const VkImageBlit2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2:
            return TrackStruct(reinterpret_cast<const VkBlitImageInfo2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2:
            return TrackStruct(reinterpret_cast<const VkImageResolve2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2:
            return TrackStruct(reinterpret_cast<const VkResolveImageInfo2*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlProperties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkPipelineShaderStageRequiredSubgroupSizeCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockProperties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK:
            return TrackStruct(reinterpret_cast<const VkWriteDescriptorSetInlineUniformBlock*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkDescriptorPoolInlineUniformBlockCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO:
            return TrackStruct(reinterpret_cast<const VkRenderingAttachmentInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDERING_INFO:
            return TrackStruct(reinterpret_cast<const VkRenderingInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const VkPipelineRenderingCreateInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDynamicRenderingFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO:
            return TrackStruct(reinterpret_cast<const VkCommandBufferInheritanceRenderingInfo*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductFeatures*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductProperties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentProperties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3:
            return TrackStruct(reinterpret_cast<const VkFormatProperties3*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMaintenance4Features*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMaintenance4Properties*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS:
            return TrackStruct(reinterpret_cast<const VkDeviceBufferMemoryRequirements*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS:
            return TrackStruct(reinterpret_cast<const VkDeviceImageMemoryRequirements*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkSwapchainCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PRESENT_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkPresentInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkAcquireNextImageInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR:
            return TrackStruct(reinterpret_cast<const VkDeviceGroupPresentCapabilitiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkDeviceGroupPresentInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkDeviceGroupSwapchainCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkDisplayModeCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkDisplaySurfaceCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkDisplayPresentInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkXlibSurfaceCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkXcbSurfaceCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkWaylandSurfaceCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkAndroidSurfaceCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkWin32SurfaceCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkQueueFamilyQueryResultStatusPropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkQueueFamilyVideoPropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoProfileInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoProfileListInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoCapabilitiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceVideoFormatInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoFormatPropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoPictureResourceInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoReferenceSlotInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoSessionMemoryRequirementsKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkBindVideoSessionMemoryInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoSessionCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoSessionParametersCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoSessionParametersUpdateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoBeginCodingInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEndCodingInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoCodingControlInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoDecodeCapabilitiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoDecodeUsageInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoDecodeInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH264CapabilitiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH264QualityLevelPropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH264SessionCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH264SessionParametersAddInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH264SessionParametersCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH264SessionParametersGetInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH264SessionParametersFeedbackInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH264NaluSliceInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH264PictureInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH264DpbSlotInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH264ProfileInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH264RateControlInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH264RateControlLayerInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH264GopRemainingFrameInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_CAPABILITIES_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH265CapabilitiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH265SessionCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUALITY_LEVEL_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH265QualityLevelPropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH265SessionParametersAddInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH265SessionParametersCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_GET_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH265SessionParametersGetInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH265SessionParametersFeedbackInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH265NaluSliceSegmentInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PICTURE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH265PictureInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH265DpbSlotInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH265ProfileInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH265RateControlInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH265RateControlLayerInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_GOP_REMAINING_FRAME_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeH265GopRemainingFrameInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoDecodeH264ProfileInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoDecodeH264CapabilitiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoDecodeH264SessionParametersAddInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoDecodeH264SessionParametersCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoDecodeH264PictureInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoDecodeH264DpbSlotInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkRenderingFragmentDensityMapAttachmentInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD:
            return TrackStruct(reinterpret_cast<const VkAttachmentSampleCountInfoAMD*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX:
            return TrackStruct(reinterpret_cast<const VkMultiviewPerViewAttributesInfoNVX*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkImportMemoryWin32HandleInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkExportMemoryWin32HandleInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkMemoryWin32HandlePropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkMemoryGetWin32HandleInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkImportMemoryFdInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkMemoryFdPropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkMemoryGetFdInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkImportSemaphoreWin32HandleInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkExportSemaphoreWin32HandleInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkD3D12FenceSubmitInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkSemaphoreGetWin32HandleInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkImportSemaphoreFdInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkSemaphoreGetFdInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevicePushDescriptorPropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
            return TrackStruct(reinterpret_cast<const VkPresentRegionsKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
            return TrackStruct(reinterpret_cast<const VkSharedPresentSurfaceCapabilitiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkImportFenceWin32HandleInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkExportFenceWin32HandleInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkFenceGetWin32HandleInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkImportFenceFdInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkFenceGetFdInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevicePerformanceQueryFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevicePerformanceQueryPropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR:
            return TrackStruct(reinterpret_cast<const VkPerformanceCounterKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR:
            return TrackStruct(reinterpret_cast<const VkPerformanceCounterDescriptionKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkQueryPoolPerformanceCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkAcquireProfilingLockInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkPerformanceQuerySubmitInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceSurfaceInfo2KHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR:
            return TrackStruct(reinterpret_cast<const VkSurfaceCapabilities2KHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR:
            return TrackStruct(reinterpret_cast<const VkSurfaceFormat2KHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR:
            return TrackStruct(reinterpret_cast<const VkDisplayProperties2KHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR:
            return TrackStruct(reinterpret_cast<const VkDisplayPlaneProperties2KHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR:
            return TrackStruct(reinterpret_cast<const VkDisplayModeProperties2KHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR:
            return TrackStruct(reinterpret_cast<const VkDisplayPlaneInfo2KHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR:
            return TrackStruct(reinterpret_cast<const VkDisplayPlaneCapabilities2KHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevicePortabilitySubsetPropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderClockFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoDecodeH265ProfileInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_CAPABILITIES_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoDecodeH265CapabilitiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoDecodeH265SessionParametersAddInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoDecodeH265SessionParametersCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoDecodeH265PictureInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoDecodeH265DpbSlotInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkDeviceQueueGlobalPriorityCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkQueueFamilyGlobalPriorityPropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkFragmentShadingRateAttachmentInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkPipelineFragmentShadingRateStateCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceFragmentShadingRatePropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkRenderingAttachmentLocationInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkRenderingInputAttachmentIndexInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderQuadControlFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
            return TrackStruct(reinterpret_cast<const VkSurfaceProtectedCapabilitiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevicePresentWaitFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkPipelineInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkPipelineExecutablePropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkPipelineExecutableInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR:
            return TrackStruct(reinterpret_cast<const VkPipelineExecutableStatisticKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR:
            return TrackStruct(reinterpret_cast<const VkPipelineExecutableInternalRepresentationKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_MAP_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkMemoryMapInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_UNMAP_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkMemoryUnmapInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkPipelineLibraryCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PRESENT_ID_KHR:
            return TrackStruct(reinterpret_cast<const VkPresentIdKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevicePresentIdFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeCapabilitiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkQueryPoolVideoEncodeFeedbackCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeUsageInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeRateControlLayerInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeRateControlInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeQualityLevelPropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeQualityLevelInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeSessionParametersGetInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoEncodeSessionParametersFeedbackInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV:
            return TrackStruct(reinterpret_cast<const VkQueueFamilyCheckpointProperties2NV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV:
            return TrackStruct(reinterpret_cast<const VkCheckpointData2NV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMaintenance5FeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMaintenance5PropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDERING_AREA_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkRenderingAreaInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2_KHR:
            return TrackStruct(reinterpret_cast<const VkImageSubresource2KHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_IMAGE_SUBRESOURCE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkDeviceImageSubresourceInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2_KHR:
            return TrackStruct(reinterpret_cast<const VkSubresourceLayout2KHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkPipelineCreateFlags2CreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkBufferUsageFlags2CreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkCooperativeMatrixPropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixPropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoDecodeAV1ProfileInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoDecodeAV1CapabilitiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoDecodeAV1SessionParametersCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoDecodeAV1PictureInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoDecodeAV1DpbSlotInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceVideoMaintenance1FeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkVideoInlineQueryInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkPipelineVertexInputDivisorStateCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderFloatControls2FeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceIndexTypeUint8FeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceLineRasterizationFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceLineRasterizationPropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkPipelineRasterizationLineStateCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkCalibratedTimestampInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderExpectAssumeFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMaintenance6FeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMaintenance6PropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS_KHR:
            return TrackStruct(reinterpret_cast<const VkBindMemoryStatusKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_SETS_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkBindDescriptorSetsInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PUSH_CONSTANTS_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkPushConstantsInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkPushDescriptorSetInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkPushDescriptorSetWithTemplateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SET_DESCRIPTOR_BUFFER_OFFSETS_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkSetDescriptorBufferOffsetsInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkBindDescriptorBufferEmbeddedSamplersInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkDebugReportCallbackCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
            return TrackStruct(reinterpret_cast<const VkPipelineRasterizationStateRasterizationOrderAMD*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkDebugMarkerObjectNameInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkDebugMarkerObjectTagInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkDebugMarkerMarkerInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkDedicatedAllocationImageCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkDedicatedAllocationBufferCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceTransformFeedbackPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkPipelineRasterizationStateStreamCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX:
            return TrackStruct(reinterpret_cast<const VkImageViewHandleInfoNVX*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX:
            return TrackStruct(reinterpret_cast<const VkImageViewAddressPropertiesNVX*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
            return TrackStruct(reinterpret_cast<const VkTextureLODGatherFormatPropertiesAMD*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP:
            return TrackStruct(reinterpret_cast<const VkStreamDescriptorSurfaceCreateInfoGGP*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceCornerSampledImageFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkExternalMemoryImageCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkExportMemoryAllocateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkImportMemoryWin32HandleInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkExportMemoryWin32HandleInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
            return TrackStruct(reinterpret_cast<const VkValidationFlagsEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN:
            return TrackStruct(reinterpret_cast<const VkViSurfaceCreateInfoNN*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
            return TrackStruct(reinterpret_cast<const VkImageViewASTCDecodeModeEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceASTCDecodeFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevicePipelineRobustnessFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevicePipelineRobustnessPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkPipelineRobustnessCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkConditionalRenderingBeginInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkPipelineViewportWScalingStateCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT:
            return TrackStruct(reinterpret_cast<const VkSurfaceCapabilities2EXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkDisplayPowerInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkDeviceEventInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkDisplayEventInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkSwapchainCounterCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
            return TrackStruct(reinterpret_cast<const VkPresentTimesInfoGOOGLE*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkPipelineViewportSwizzleStateCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkPipelineDiscardRectangleStateCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkPipelineRasterizationConservativeStateCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkPipelineRasterizationDepthClipStateCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_HDR_METADATA_EXT:
            return TrackStruct(reinterpret_cast<const VkHdrMetadataEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK:
            return TrackStruct(reinterpret_cast<const VkIOSSurfaceCreateInfoMVK*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK:
            return TrackStruct(reinterpret_cast<const VkMacOSSurfaceCreateInfoMVK*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT:
            return TrackStruct(reinterpret_cast<const VkDebugUtilsLabelEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkDebugUtilsObjectNameInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT:
            return TrackStruct(reinterpret_cast<const VkDebugUtilsMessengerCallbackDataEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkDebugUtilsMessengerCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkDebugUtilsObjectTagInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
            return TrackStruct(reinterpret_cast<const VkAndroidHardwareBufferUsageANDROID*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID:
            return TrackStruct(reinterpret_cast<const VkAndroidHardwareBufferPropertiesANDROID*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
            return TrackStruct(reinterpret_cast<const VkAndroidHardwareBufferFormatPropertiesANDROID*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            return TrackStruct(reinterpret_cast<const VkImportAndroidHardwareBufferInfoANDROID*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            return TrackStruct(reinterpret_cast<const VkMemoryGetAndroidHardwareBufferInfoANDROID*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
            return TrackStruct(reinterpret_cast<const VkExternalFormatANDROID*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID:
            return TrackStruct(reinterpret_cast<const VkAndroidHardwareBufferFormatProperties2ANDROID*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkSampleLocationsInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkRenderPassSampleLocationsBeginInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkPipelineSampleLocationsStateCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceSampleLocationsPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkMultisamplePropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkPipelineCoverageToColorStateCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkPipelineCoverageModulationStateCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
            return TrackStruct(reinterpret_cast<const VkDrmFormatModifierPropertiesListEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkImageDrmFormatModifierListCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkImageDrmFormatModifierExplicitCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkImageDrmFormatModifierPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT:
            return TrackStruct(reinterpret_cast<const VkDrmFormatModifierPropertiesList2EXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkValidationCacheCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkPipelineViewportShadingRateImageStateCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShadingRateImageFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShadingRateImagePropertiesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkRayTracingShaderGroupCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkRayTracingPipelineCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV:
            return TrackStruct(reinterpret_cast<const VkGeometryTrianglesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV:
            return TrackStruct(reinterpret_cast<const VkGeometryAABBNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_GEOMETRY_NV:
            return TrackStruct(reinterpret_cast<const VkGeometryNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkAccelerationStructureInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkAccelerationStructureCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkBindAccelerationStructureMemoryInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            return TrackStruct(reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkAccelerationStructureMemoryRequirementsInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceRayTracingPropertiesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceImageViewImageFormatInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkFilterCubicImageViewImageFormatPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkImportMemoryHostPointerInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkMemoryHostPointerPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
            return TrackStruct(reinterpret_cast<const VkPipelineCompilerControlCreateInfoAMD*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesAMD*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
            return TrackStruct(reinterpret_cast<const VkDeviceMemoryOverallocationCreateInfoAMD*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
            return TrackStruct(reinterpret_cast<const VkPresentFrameTokenGGP*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceExclusiveScissorFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
            return TrackStruct(reinterpret_cast<const VkQueueFamilyCheckpointPropertiesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV:
            return TrackStruct(reinterpret_cast<const VkCheckpointDataNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL:
            return TrackStruct(reinterpret_cast<const VkInitializePerformanceApiInfoINTEL*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL:
            return TrackStruct(reinterpret_cast<const VkQueryPoolPerformanceQueryCreateInfoINTEL*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL:
            return TrackStruct(reinterpret_cast<const VkPerformanceMarkerInfoINTEL*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL:
            return TrackStruct(reinterpret_cast<const VkPerformanceStreamMarkerInfoINTEL*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL:
            return TrackStruct(reinterpret_cast<const VkPerformanceOverrideInfoINTEL*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL:
            return TrackStruct(reinterpret_cast<const VkPerformanceConfigurationAcquireInfoINTEL*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevicePCIBusInfoPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
            return TrackStruct(reinterpret_cast<const VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
            return TrackStruct(reinterpret_cast<const VkSwapchainDisplayNativeHdrCreateInfoAMD*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA:
            return TrackStruct(reinterpret_cast<const VkImagePipeSurfaceCreateInfoFUCHSIA*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkMetalSurfaceCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkRenderPassFragmentDensityMapCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderCoreProperties2AMD*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkMemoryPriorityAllocateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkBufferDeviceAddressCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkValidationFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            return TrackStruct(reinterpret_cast<const VkCooperativeMatrixPropertiesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixPropertiesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkPipelineCoverageReductionStateCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV:
            return TrackStruct(reinterpret_cast<const VkFramebufferMixedSamplesCombinationNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceProvokingVertexFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceProvokingVertexPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkSurfaceFullScreenExclusiveInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
            return TrackStruct(reinterpret_cast<const VkSurfaceCapabilitiesFullScreenExclusiveEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkSurfaceFullScreenExclusiveWin32InfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkHeadlessSurfaceCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceHostImageCopyFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceHostImageCopyPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_TO_IMAGE_COPY_EXT:
            return TrackStruct(reinterpret_cast<const VkMemoryToImageCopyEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_TO_MEMORY_COPY_EXT:
            return TrackStruct(reinterpret_cast<const VkImageToMemoryCopyEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkCopyMemoryToImageInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_MEMORY_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkCopyImageToMemoryInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkCopyImageToImageInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkHostImageLayoutTransitionInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE_EXT:
            return TrackStruct(reinterpret_cast<const VkSubresourceHostMemcpySizeEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY_EXT:
            return TrackStruct(reinterpret_cast<const VkHostImageCopyDevicePerformanceQueryEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMapMemoryPlacedFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMapMemoryPlacedPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkMemoryMapPlacedInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_EXT:
            return TrackStruct(reinterpret_cast<const VkSurfacePresentModeEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_EXT:
            return TrackStruct(reinterpret_cast<const VkSurfacePresentScalingCapabilitiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_EXT:
            return TrackStruct(reinterpret_cast<const VkSurfacePresentModeCompatibilityEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkSwapchainPresentFenceInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkSwapchainPresentModesCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkSwapchainPresentModeInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkSwapchainPresentScalingCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkReleaseSwapchainImagesInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkGraphicsShaderGroupCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkGraphicsPipelineShaderGroupsCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV:
            return TrackStruct(reinterpret_cast<const VkIndirectCommandsLayoutTokenNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkIndirectCommandsLayoutCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkGeneratedCommandsInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkGeneratedCommandsMemoryRequirementsInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkCommandBufferInheritanceViewportScissorInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
            return TrackStruct(reinterpret_cast<const VkRenderPassTransformBeginInfoQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM:
            return TrackStruct(reinterpret_cast<const VkCommandBufferInheritanceRenderPassTransformInfoQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEPTH_BIAS_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkDepthBiasInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkDepthBiasRepresentationInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT:
            return TrackStruct(reinterpret_cast<const VkDeviceMemoryReportCallbackDataEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkDeviceDeviceMemoryReportCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceRobustness2FeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceRobustness2PropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkSamplerCustomBorderColorCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceCustomBorderColorPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevicePresentBarrierFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV:
            return TrackStruct(reinterpret_cast<const VkSurfaceCapabilitiesPresentBarrierNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkSwapchainPresentBarrierCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkDeviceDiagnosticsConfigCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV:
            return TrackStruct(reinterpret_cast<const VkQueryLowLatencySupportNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkGraphicsPipelineLibraryCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkPipelineFragmentShadingRateEnumStateCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV:
            return TrackStruct(reinterpret_cast<const VkAccelerationStructureGeometryMotionTrianglesDataNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkAccelerationStructureMotionInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
            return TrackStruct(reinterpret_cast<const VkCopyCommandTransformInfoQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT:
            return TrackStruct(reinterpret_cast<const VkImageCompressionControlEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkImageCompressionPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevice4444FormatsFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceFaultFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT:
            return TrackStruct(reinterpret_cast<const VkDeviceFaultCountsEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkDeviceFaultInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkDirectFBSurfaceCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkMutableDescriptorTypeCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT:
            return TrackStruct(reinterpret_cast<const VkVertexInputBindingDescription2EXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT:
            return TrackStruct(reinterpret_cast<const VkVertexInputAttributeDescription2EXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDrmPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT:
            return TrackStruct(reinterpret_cast<const VkDeviceAddressBindingCallbackDataEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDepthClipControlFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkPipelineViewportDepthClipControlCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA:
            return TrackStruct(reinterpret_cast<const VkImportMemoryZirconHandleInfoFUCHSIA*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA:
            return TrackStruct(reinterpret_cast<const VkMemoryZirconHandlePropertiesFUCHSIA*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA:
            return TrackStruct(reinterpret_cast<const VkMemoryGetZirconHandleInfoFUCHSIA*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA:
            return TrackStruct(reinterpret_cast<const VkImportSemaphoreZirconHandleInfoFUCHSIA*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA:
            return TrackStruct(reinterpret_cast<const VkSemaphoreGetZirconHandleInfoFUCHSIA*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkMemoryGetRemoteAddressInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceFrameBoundaryFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT:
            return TrackStruct(reinterpret_cast<const VkFrameBoundaryEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT:
            return TrackStruct(reinterpret_cast<const VkSubpassResolvePerformanceQueryEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkMultisampledRenderToSingleSampledInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SCREEN_SURFACE_CREATE_INFO_QNX:
            return TrackStruct(reinterpret_cast<const VkScreenSurfaceCreateInfoQNX*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkPipelineColorWriteCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkImageViewMinLodCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMultiDrawFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMultiDrawPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderTileImageFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderTileImagePropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkMicromapBuildInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkMicromapCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceOpacityMicromapPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MICROMAP_VERSION_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkMicromapVersionInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkCopyMicromapToMemoryInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkCopyMemoryToMicromapInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkCopyMicromapInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkMicromapBuildSizesInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT:
            return TrackStruct(reinterpret_cast<const VkAccelerationStructureTrianglesOpacityMicromapEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDisplacementMicromapFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_PROPERTIES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDisplacementMicromapPropertiesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV:
            return TrackStruct(reinterpret_cast<const VkAccelerationStructureTrianglesDisplacementMicromapNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkSamplerBorderColorComponentMappingCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesARM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM:
            return TrackStruct(reinterpret_cast<const VkDeviceQueueShaderCoreControlCreateInfoARM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceSchedulingControlsFeaturesARM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceSchedulingControlsPropertiesARM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkImageViewSlicedCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE:
            return TrackStruct(reinterpret_cast<const VkDescriptorSetBindingReferenceVALVE*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE:
            return TrackStruct(reinterpret_cast<const VkDescriptorSetLayoutHostMappingInfoVALVE*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDepthClampZeroOneFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceRenderPassStripedFeaturesARM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceRenderPassStripedPropertiesARM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_INFO_ARM:
            return TrackStruct(reinterpret_cast<const VkRenderPassStripeInfoARM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM:
            return TrackStruct(reinterpret_cast<const VkRenderPassStripeBeginInfoARM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM:
            return TrackStruct(reinterpret_cast<const VkRenderPassStripeSubmitInfoARM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM:
            return TrackStruct(reinterpret_cast<const VkSubpassFragmentDensityMapOffsetEndInfoQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkComputePipelineIndirectBufferInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkPipelineIndirectDeviceAddressInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM:
            return TrackStruct(reinterpret_cast<const VkImageViewSampleWeightCreateInfoQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceImageProcessingFeaturesQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceImageProcessingPropertiesQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceNestedCommandBufferFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceNestedCommandBufferPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT:
            return TrackStruct(reinterpret_cast<const VkExternalMemoryAcquireUnmodifiedEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState3PropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT:
            return TrackStruct(reinterpret_cast<const VkRenderPassCreationControlEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkRenderPassCreationFeedbackCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkRenderPassSubpassFeedbackCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_INFO_LUNARG:
            return TrackStruct(reinterpret_cast<const VkDirectDriverLoadingInfoLUNARG*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG:
            return TrackStruct(reinterpret_cast<const VkDirectDriverLoadingListLUNARG*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkPipelineShaderStageModuleIdentifierCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT:
            return TrackStruct(reinterpret_cast<const VkShaderModuleIdentifierEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceOpticalFlowFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceOpticalFlowPropertiesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkOpticalFlowImageFormatInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV:
            return TrackStruct(reinterpret_cast<const VkOpticalFlowImageFormatPropertiesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkOpticalFlowSessionCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkOpticalFlowSessionCreatePrivateDataInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_EXECUTE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkOpticalFlowExecuteInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevicePipelineProtectedAccessFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceExternalFormatResolvePropertiesANDROID*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID:
            return TrackStruct(reinterpret_cast<const VkAndroidHardwareBufferFormatResolvePropertiesANDROID*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderObjectFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderObjectPropertiesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkShaderCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM:
            return TrackStruct(reinterpret_cast<const VkTilePropertiesQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC:
            return TrackStruct(reinterpret_cast<const VkAmigoProfilingSubmitInfoSEC*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const VkLayerSettingsCreateInfoEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_LATENCY_SLEEP_MODE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkLatencySleepModeInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_LATENCY_SLEEP_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkLatencySleepInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SET_LATENCY_MARKER_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkSetLatencyMarkerInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_LATENCY_TIMINGS_FRAME_REPORT_NV:
            return TrackStruct(reinterpret_cast<const VkLatencyTimingsFrameReportNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_GET_LATENCY_MARKER_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkGetLatencyMarkerInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV:
            return TrackStruct(reinterpret_cast<const VkLatencySubmissionPresentIdNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkSwapchainLatencyCreateInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_OUT_OF_BAND_QUEUE_TYPE_INFO_NV:
            return TrackStruct(reinterpret_cast<const VkOutOfBandQueueTypeInfoNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV:
            return TrackStruct(reinterpret_cast<const VkLatencySurfaceCapabilitiesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM:
            return TrackStruct(reinterpret_cast<const VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDevicePerStageDescriptorSetFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceImageProcessing2FeaturesQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceImageProcessing2PropertiesQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM:
            return TrackStruct(reinterpret_cast<const VkSamplerBlockMatchWindowCreateInfoQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceCubicWeightsFeaturesQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM:
            return TrackStruct(reinterpret_cast<const VkSamplerCubicWeightsCreateInfoQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM:
            return TrackStruct(reinterpret_cast<const VkBlitImageCubicWeightsInfoQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM:
            return TrackStruct(reinterpret_cast<const VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceCubicClampFeaturesQCOM*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceLayeredDriverPropertiesMSFT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceRawAccessChainsFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceRayTracingValidationFeaturesNV*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR:
            return TrackStruct(reinterpret_cast<const VkAccelerationStructureGeometryTrianglesDataKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR:
            return TrackStruct(reinterpret_cast<const VkAccelerationStructureGeometryAabbsDataKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR:
            return TrackStruct(reinterpret_cast<const VkAccelerationStructureGeometryInstancesDataKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR:
            return TrackStruct(reinterpret_cast<const VkAccelerationStructureGeometryKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkAccelerationStructureBuildGeometryInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkAccelerationStructureCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
            return TrackStruct(reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceAccelerationStructurePropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkAccelerationStructureDeviceAddressInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkAccelerationStructureVersionInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkCopyAccelerationStructureToMemoryInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkCopyMemoryToAccelerationStructureInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkCopyAccelerationStructureInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkAccelerationStructureBuildSizesInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkRayTracingShaderGroupCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkRayTracingPipelineInterfaceCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const VkRayTracingPipelineCreateInfoKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceRayTracingPipelinePropertiesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceRayQueryFeaturesKHR*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesEXT*>(value), unwrap_memory);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesEXT*>(value), unwrap_memory);
        default:
            GFXRECON_LOG_ERROR("Unknown structure type: %u", valueType);
    }

    return nullptr;
}

GFXRECON_END_NAMESPACE(vulkan_trackers)
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
