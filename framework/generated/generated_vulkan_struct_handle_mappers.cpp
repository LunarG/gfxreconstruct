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

#include "generated/generated_vulkan_struct_handle_mappers.h"

#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/vulkan_handle_mapping_util.h"
#include "generated/generated_vulkan_struct_decoders.h"

#include <algorithm>
#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void MapStructHandles(Decoded_VkBufferMemoryBarrier* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBufferMemoryBarrier* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<BufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);
    }
}

void MapStructHandles(Decoded_VkImageMemoryBarrier* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImageMemoryBarrier* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<ImageInfo>(wrapper->image, object_info_table, &VulkanObjectInfoTable::GetImageInfo);
    }
}

void MapStructHandles(Decoded_VkDeviceCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSubmitInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSubmitInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->pWaitSemaphores = handle_mapping::MapHandleArray<SemaphoreInfo>(&wrapper->pWaitSemaphores, object_info_table, &VulkanObjectInfoTable::GetSemaphoreInfo);

        value->pCommandBuffers = handle_mapping::MapHandleArray<CommandBufferInfo>(&wrapper->pCommandBuffers, object_info_table, &VulkanObjectInfoTable::GetCommandBufferInfo);

        value->pSignalSemaphores = handle_mapping::MapHandleArray<SemaphoreInfo>(&wrapper->pSignalSemaphores, object_info_table, &VulkanObjectInfoTable::GetSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkMappedMemoryRange* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMappedMemoryRange* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<DeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkMemoryAllocateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSparseMemoryBind* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSparseMemoryBind* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<DeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkSparseBufferMemoryBindInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSparseBufferMemoryBindInfo* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<BufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);

        MapStructArrayHandles<Decoded_VkSparseMemoryBind>(wrapper->pBinds->GetMetaStructPointer(), wrapper->pBinds->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkSparseImageOpaqueMemoryBindInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSparseImageOpaqueMemoryBindInfo* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<ImageInfo>(wrapper->image, object_info_table, &VulkanObjectInfoTable::GetImageInfo);

        MapStructArrayHandles<Decoded_VkSparseMemoryBind>(wrapper->pBinds->GetMetaStructPointer(), wrapper->pBinds->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkSparseImageMemoryBind* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSparseImageMemoryBind* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<DeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkSparseImageMemoryBindInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSparseImageMemoryBindInfo* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<ImageInfo>(wrapper->image, object_info_table, &VulkanObjectInfoTable::GetImageInfo);

        MapStructArrayHandles<Decoded_VkSparseImageMemoryBind>(wrapper->pBinds->GetMetaStructPointer(), wrapper->pBinds->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkBindSparseInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBindSparseInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->pWaitSemaphores = handle_mapping::MapHandleArray<SemaphoreInfo>(&wrapper->pWaitSemaphores, object_info_table, &VulkanObjectInfoTable::GetSemaphoreInfo);

        MapStructArrayHandles<Decoded_VkSparseBufferMemoryBindInfo>(wrapper->pBufferBinds->GetMetaStructPointer(), wrapper->pBufferBinds->GetLength(), object_info_table);

        MapStructArrayHandles<Decoded_VkSparseImageOpaqueMemoryBindInfo>(wrapper->pImageOpaqueBinds->GetMetaStructPointer(), wrapper->pImageOpaqueBinds->GetLength(), object_info_table);

        MapStructArrayHandles<Decoded_VkSparseImageMemoryBindInfo>(wrapper->pImageBinds->GetMetaStructPointer(), wrapper->pImageBinds->GetLength(), object_info_table);

        value->pSignalSemaphores = handle_mapping::MapHandleArray<SemaphoreInfo>(&wrapper->pSignalSemaphores, object_info_table, &VulkanObjectInfoTable::GetSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkBufferViewCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBufferViewCreateInfo* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<BufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);
    }
}

void MapStructHandles(Decoded_VkImageCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageViewCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImageViewCreateInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->image = handle_mapping::MapHandle<ImageInfo>(wrapper->image, object_info_table, &VulkanObjectInfoTable::GetImageInfo);
    }
}

void MapStructHandles(Decoded_VkShaderModuleCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineShaderStageCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineShaderStageCreateInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->module = handle_mapping::MapHandle<ShaderModuleInfo>(wrapper->module, object_info_table, &VulkanObjectInfoTable::GetShaderModuleInfo);
    }
}

void MapStructHandles(Decoded_VkComputePipelineCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkComputePipelineCreateInfo* value = wrapper->decoded_value;

        MapStructHandles(wrapper->stage, object_info_table);

        value->layout = handle_mapping::MapHandle<PipelineLayoutInfo>(wrapper->layout, object_info_table, &VulkanObjectInfoTable::GetPipelineLayoutInfo);

        value->basePipelineHandle = handle_mapping::MapHandle<PipelineInfo>(wrapper->basePipelineHandle, object_info_table, &VulkanObjectInfoTable::GetPipelineInfo);
    }
}

void MapStructHandles(Decoded_VkGraphicsPipelineCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGraphicsPipelineCreateInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        MapStructArrayHandles<Decoded_VkPipelineShaderStageCreateInfo>(wrapper->pStages->GetMetaStructPointer(), wrapper->pStages->GetLength(), object_info_table);

        value->layout = handle_mapping::MapHandle<PipelineLayoutInfo>(wrapper->layout, object_info_table, &VulkanObjectInfoTable::GetPipelineLayoutInfo);

        value->renderPass = handle_mapping::MapHandle<RenderPassInfo>(wrapper->renderPass, object_info_table, &VulkanObjectInfoTable::GetRenderPassInfo);

        value->basePipelineHandle = handle_mapping::MapHandle<PipelineInfo>(wrapper->basePipelineHandle, object_info_table, &VulkanObjectInfoTable::GetPipelineInfo);
    }
}

void MapStructHandles(Decoded_VkPipelineLayoutCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineLayoutCreateInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->pSetLayouts = handle_mapping::MapHandleArray<DescriptorSetLayoutInfo>(&wrapper->pSetLayouts, object_info_table, &VulkanObjectInfoTable::GetDescriptorSetLayoutInfo);
    }
}

void MapStructHandles(Decoded_VkSamplerCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCopyDescriptorSet* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyDescriptorSet* value = wrapper->decoded_value;

        value->srcSet = handle_mapping::MapHandle<DescriptorSetInfo>(wrapper->srcSet, object_info_table, &VulkanObjectInfoTable::GetDescriptorSetInfo);

        value->dstSet = handle_mapping::MapHandle<DescriptorSetInfo>(wrapper->dstSet, object_info_table, &VulkanObjectInfoTable::GetDescriptorSetInfo);
    }
}

void MapStructHandles(Decoded_VkDescriptorBufferInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDescriptorBufferInfo* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<BufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);
    }
}

void MapStructHandles(Decoded_VkDescriptorSetAllocateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDescriptorSetAllocateInfo* value = wrapper->decoded_value;

        value->descriptorPool = handle_mapping::MapHandle<DescriptorPoolInfo>(wrapper->descriptorPool, object_info_table, &VulkanObjectInfoTable::GetDescriptorPoolInfo);

        value->pSetLayouts = handle_mapping::MapHandleArray<DescriptorSetLayoutInfo>(&wrapper->pSetLayouts, object_info_table, &VulkanObjectInfoTable::GetDescriptorSetLayoutInfo);
    }
}

void MapStructHandles(Decoded_VkDescriptorSetLayoutBinding* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDescriptorSetLayoutBinding* value = wrapper->decoded_value;

        value->pImmutableSamplers = handle_mapping::MapHandleArray<SamplerInfo>(&wrapper->pImmutableSamplers, object_info_table, &VulkanObjectInfoTable::GetSamplerInfo);
    }
}

void MapStructHandles(Decoded_VkDescriptorSetLayoutCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkDescriptorSetLayoutBinding>(wrapper->pBindings->GetMetaStructPointer(), wrapper->pBindings->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkFramebufferCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkFramebufferCreateInfo* value = wrapper->decoded_value;

        value->renderPass = handle_mapping::MapHandle<RenderPassInfo>(wrapper->renderPass, object_info_table, &VulkanObjectInfoTable::GetRenderPassInfo);

        value->pAttachments = handle_mapping::MapHandleArray<ImageViewInfo>(&wrapper->pAttachments, object_info_table, &VulkanObjectInfoTable::GetImageViewInfo);
    }
}

void MapStructHandles(Decoded_VkCommandBufferAllocateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCommandBufferAllocateInfo* value = wrapper->decoded_value;

        value->commandPool = handle_mapping::MapHandle<CommandPoolInfo>(wrapper->commandPool, object_info_table, &VulkanObjectInfoTable::GetCommandPoolInfo);
    }
}

void MapStructHandles(Decoded_VkCommandBufferInheritanceInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCommandBufferInheritanceInfo* value = wrapper->decoded_value;

        value->renderPass = handle_mapping::MapHandle<RenderPassInfo>(wrapper->renderPass, object_info_table, &VulkanObjectInfoTable::GetRenderPassInfo);

        value->framebuffer = handle_mapping::MapHandle<FramebufferInfo>(wrapper->framebuffer, object_info_table, &VulkanObjectInfoTable::GetFramebufferInfo);
    }
}

void MapStructHandles(Decoded_VkCommandBufferBeginInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkCommandBufferInheritanceInfo>(wrapper->pInheritanceInfo->GetMetaStructPointer(), 1, object_info_table);
    }
}

void MapStructHandles(Decoded_VkRenderPassBeginInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkRenderPassBeginInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->renderPass = handle_mapping::MapHandle<RenderPassInfo>(wrapper->renderPass, object_info_table, &VulkanObjectInfoTable::GetRenderPassInfo);

        value->framebuffer = handle_mapping::MapHandle<FramebufferInfo>(wrapper->framebuffer, object_info_table, &VulkanObjectInfoTable::GetFramebufferInfo);
    }
}

void MapStructHandles(Decoded_VkBindBufferMemoryInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBindBufferMemoryInfo* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<BufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);

        value->memory = handle_mapping::MapHandle<DeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkBindImageMemoryInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBindImageMemoryInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->image = handle_mapping::MapHandle<ImageInfo>(wrapper->image, object_info_table, &VulkanObjectInfoTable::GetImageInfo);

        value->memory = handle_mapping::MapHandle<DeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDevice16BitStorageFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryDedicatedAllocateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryDedicatedAllocateInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->image = handle_mapping::MapHandle<ImageInfo>(wrapper->image, object_info_table, &VulkanObjectInfoTable::GetImageInfo);

        value->buffer = handle_mapping::MapHandle<BufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);
    }
}

void MapStructHandles(Decoded_VkMemoryAllocateFlagsInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceGroupRenderPassBeginInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceGroupSubmitInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceGroupBindSparseInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBindImageMemoryDeviceGroupInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceGroupProperties* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        handle_mapping::MapHandleArray<PhysicalDeviceInfo>(&wrapper->physicalDevices, object_info_table, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    }
}

void MapStructHandles(Decoded_VkDeviceGroupDeviceCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDeviceGroupDeviceCreateInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->pPhysicalDevices = handle_mapping::MapHandleArray<PhysicalDeviceInfo>(&wrapper->pPhysicalDevices, object_info_table, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    }
}

void MapStructHandles(Decoded_VkBufferMemoryRequirementsInfo2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBufferMemoryRequirementsInfo2* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<BufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);
    }
}

void MapStructHandles(Decoded_VkImageMemoryRequirementsInfo2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImageMemoryRequirementsInfo2* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<ImageInfo>(wrapper->image, object_info_table, &VulkanObjectInfoTable::GetImageInfo);
    }
}

void MapStructHandles(Decoded_VkImageSparseMemoryRequirementsInfo2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImageSparseMemoryRequirementsInfo2* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<ImageInfo>(wrapper->image, object_info_table, &VulkanObjectInfoTable::GetImageInfo);
    }
}

void MapStructHandles(Decoded_VkImageViewUsageCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMultiviewFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVariablePointersFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceProtectedMemoryFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkProtectedSubmitInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSamplerYcbcrConversionInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSamplerYcbcrConversionInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->conversion = handle_mapping::MapHandle<SamplerYcbcrConversionInfo>(wrapper->conversion, object_info_table, &VulkanObjectInfoTable::GetSamplerYcbcrConversionInfo);
    }
}

void MapStructHandles(Decoded_VkBindImagePlaneMemoryInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorUpdateTemplateCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDescriptorUpdateTemplateCreateInfo* value = wrapper->decoded_value;

        value->descriptorSetLayout = handle_mapping::MapHandle<DescriptorSetLayoutInfo>(wrapper->descriptorSetLayout, object_info_table, &VulkanObjectInfoTable::GetDescriptorSetLayoutInfo);

        value->pipelineLayout = handle_mapping::MapHandle<PipelineLayoutInfo>(wrapper->pipelineLayout, object_info_table, &VulkanObjectInfoTable::GetPipelineLayoutInfo);
    }
}

void MapStructHandles(Decoded_VkExternalMemoryImageCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkExportMemoryAllocateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderDrawParametersFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVulkan11Features* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVulkan12Features* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageFormatListCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevice8BitStorageFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderAtomicInt64Features* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderFloat16Int8Features* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorIndexingFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageStencilUsageCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSamplerReductionModeCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImagelessFramebufferFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassAttachmentBeginInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkRenderPassAttachmentBeginInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->pAttachments = handle_mapping::MapHandleArray<ImageViewInfo>(&wrapper->pAttachments, object_info_table, &VulkanObjectInfoTable::GetImageViewInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceHostQueryResetFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkTimelineSemaphoreSubmitInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSemaphoreWaitInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSemaphoreWaitInfo* value = wrapper->decoded_value;

        value->pSemaphores = handle_mapping::MapHandleArray<SemaphoreInfo>(&wrapper->pSemaphores, object_info_table, &VulkanObjectInfoTable::GetSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkSemaphoreSignalInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSemaphoreSignalInfo* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<SemaphoreInfo>(wrapper->semaphore, object_info_table, &VulkanObjectInfoTable::GetSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBufferDeviceAddressInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBufferDeviceAddressInfo* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<BufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);
    }
}

void MapStructHandles(Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDeviceMemoryOpaqueCaptureAddressInfo* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<DeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVulkan13Features* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineCreationFeedbackCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderTerminateInvocationFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePrivateDataFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDevicePrivateDataCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePipelineCreationCacheControlFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBufferMemoryBarrier2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBufferMemoryBarrier2* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<BufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);
    }
}

void MapStructHandles(Decoded_VkImageMemoryBarrier2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImageMemoryBarrier2* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<ImageInfo>(wrapper->image, object_info_table, &VulkanObjectInfoTable::GetImageInfo);
    }
}

void MapStructHandles(Decoded_VkDependencyInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkBufferMemoryBarrier2>(wrapper->pBufferMemoryBarriers->GetMetaStructPointer(), wrapper->pBufferMemoryBarriers->GetLength(), object_info_table);

        MapStructArrayHandles<Decoded_VkImageMemoryBarrier2>(wrapper->pImageMemoryBarriers->GetMetaStructPointer(), wrapper->pImageMemoryBarriers->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkSemaphoreSubmitInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSemaphoreSubmitInfo* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<SemaphoreInfo>(wrapper->semaphore, object_info_table, &VulkanObjectInfoTable::GetSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkCommandBufferSubmitInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCommandBufferSubmitInfo* value = wrapper->decoded_value;

        value->commandBuffer = handle_mapping::MapHandle<CommandBufferInfo>(wrapper->commandBuffer, object_info_table, &VulkanObjectInfoTable::GetCommandBufferInfo);
    }
}

void MapStructHandles(Decoded_VkSubmitInfo2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        MapStructArrayHandles<Decoded_VkSemaphoreSubmitInfo>(wrapper->pWaitSemaphoreInfos->GetMetaStructPointer(), wrapper->pWaitSemaphoreInfos->GetLength(), object_info_table);

        MapStructArrayHandles<Decoded_VkCommandBufferSubmitInfo>(wrapper->pCommandBufferInfos->GetMetaStructPointer(), wrapper->pCommandBufferInfos->GetLength(), object_info_table);

        MapStructArrayHandles<Decoded_VkSemaphoreSubmitInfo>(wrapper->pSignalSemaphoreInfos->GetMetaStructPointer(), wrapper->pSignalSemaphoreInfos->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSynchronization2Features* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageRobustnessFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCopyBufferInfo2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyBufferInfo2* value = wrapper->decoded_value;

        value->srcBuffer = handle_mapping::MapHandle<BufferInfo>(wrapper->srcBuffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);

        value->dstBuffer = handle_mapping::MapHandle<BufferInfo>(wrapper->dstBuffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);
    }
}

void MapStructHandles(Decoded_VkCopyImageInfo2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyImageInfo2* value = wrapper->decoded_value;

        value->srcImage = handle_mapping::MapHandle<ImageInfo>(wrapper->srcImage, object_info_table, &VulkanObjectInfoTable::GetImageInfo);

        value->dstImage = handle_mapping::MapHandle<ImageInfo>(wrapper->dstImage, object_info_table, &VulkanObjectInfoTable::GetImageInfo);
    }
}

void MapStructHandles(Decoded_VkCopyBufferToImageInfo2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyBufferToImageInfo2* value = wrapper->decoded_value;

        value->srcBuffer = handle_mapping::MapHandle<BufferInfo>(wrapper->srcBuffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);

        value->dstImage = handle_mapping::MapHandle<ImageInfo>(wrapper->dstImage, object_info_table, &VulkanObjectInfoTable::GetImageInfo);
    }
}

void MapStructHandles(Decoded_VkCopyImageToBufferInfo2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyImageToBufferInfo2* value = wrapper->decoded_value;

        value->srcImage = handle_mapping::MapHandle<ImageInfo>(wrapper->srcImage, object_info_table, &VulkanObjectInfoTable::GetImageInfo);

        value->dstBuffer = handle_mapping::MapHandle<BufferInfo>(wrapper->dstBuffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);
    }
}

void MapStructHandles(Decoded_VkBlitImageInfo2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBlitImageInfo2* value = wrapper->decoded_value;

        value->srcImage = handle_mapping::MapHandle<ImageInfo>(wrapper->srcImage, object_info_table, &VulkanObjectInfoTable::GetImageInfo);

        value->dstImage = handle_mapping::MapHandle<ImageInfo>(wrapper->dstImage, object_info_table, &VulkanObjectInfoTable::GetImageInfo);
    }
}

void MapStructHandles(Decoded_VkResolveImageInfo2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkResolveImageInfo2* value = wrapper->decoded_value;

        value->srcImage = handle_mapping::MapHandle<ImageInfo>(wrapper->srcImage, object_info_table, &VulkanObjectInfoTable::GetImageInfo);

        value->dstImage = handle_mapping::MapHandle<ImageInfo>(wrapper->dstImage, object_info_table, &VulkanObjectInfoTable::GetImageInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSubgroupSizeControlFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceInlineUniformBlockFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkWriteDescriptorSetInlineUniformBlock* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderingAttachmentInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkRenderingAttachmentInfo* value = wrapper->decoded_value;

        value->imageView = handle_mapping::MapHandle<ImageViewInfo>(wrapper->imageView, object_info_table, &VulkanObjectInfoTable::GetImageViewInfo);

        value->resolveImageView = handle_mapping::MapHandle<ImageViewInfo>(wrapper->resolveImageView, object_info_table, &VulkanObjectInfoTable::GetImageViewInfo);
    }
}

void MapStructHandles(Decoded_VkRenderingInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        MapStructArrayHandles<Decoded_VkRenderingAttachmentInfo>(wrapper->pColorAttachments->GetMetaStructPointer(), wrapper->pColorAttachments->GetLength(), object_info_table);

        MapStructArrayHandles<Decoded_VkRenderingAttachmentInfo>(wrapper->pDepthAttachment->GetMetaStructPointer(), 1, object_info_table);

        MapStructArrayHandles<Decoded_VkRenderingAttachmentInfo>(wrapper->pStencilAttachment->GetMetaStructPointer(), 1, object_info_table);
    }
}

void MapStructHandles(Decoded_VkPipelineRenderingCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDynamicRenderingFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderIntegerDotProductFeatures* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance4Features* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceImageMemoryRequirements* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkImageCreateInfo>(wrapper->pCreateInfo->GetMetaStructPointer(), 1, object_info_table);
    }
}

void MapStructHandles(Decoded_VkSwapchainCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSwapchainCreateInfoKHR* value = wrapper->decoded_value;

        value->surface = handle_mapping::MapHandle<SurfaceKHRInfo>(wrapper->surface, object_info_table, &VulkanObjectInfoTable::GetSurfaceKHRInfo);

        value->oldSwapchain = handle_mapping::MapHandle<SwapchainKHRInfo>(wrapper->oldSwapchain, object_info_table, &VulkanObjectInfoTable::GetSwapchainKHRInfo);
    }
}

void MapStructHandles(Decoded_VkPresentInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPresentInfoKHR* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->pWaitSemaphores = handle_mapping::MapHandleArray<SemaphoreInfo>(&wrapper->pWaitSemaphores, object_info_table, &VulkanObjectInfoTable::GetSemaphoreInfo);

        value->pSwapchains = handle_mapping::MapHandleArray<SwapchainKHRInfo>(&wrapper->pSwapchains, object_info_table, &VulkanObjectInfoTable::GetSwapchainKHRInfo);
    }
}

void MapStructHandles(Decoded_VkImageSwapchainCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImageSwapchainCreateInfoKHR* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->swapchain = handle_mapping::MapHandle<SwapchainKHRInfo>(wrapper->swapchain, object_info_table, &VulkanObjectInfoTable::GetSwapchainKHRInfo);
    }
}

void MapStructHandles(Decoded_VkBindImageMemorySwapchainInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBindImageMemorySwapchainInfoKHR* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->swapchain = handle_mapping::MapHandle<SwapchainKHRInfo>(wrapper->swapchain, object_info_table, &VulkanObjectInfoTable::GetSwapchainKHRInfo);
    }
}

void MapStructHandles(Decoded_VkAcquireNextImageInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkAcquireNextImageInfoKHR* value = wrapper->decoded_value;

        value->swapchain = handle_mapping::MapHandle<SwapchainKHRInfo>(wrapper->swapchain, object_info_table, &VulkanObjectInfoTable::GetSwapchainKHRInfo);

        value->semaphore = handle_mapping::MapHandle<SemaphoreInfo>(wrapper->semaphore, object_info_table, &VulkanObjectInfoTable::GetSemaphoreInfo);

        value->fence = handle_mapping::MapHandle<FenceInfo>(wrapper->fence, object_info_table, &VulkanObjectInfoTable::GetFenceInfo);
    }
}

void MapStructHandles(Decoded_VkDeviceGroupPresentInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDisplayModePropertiesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDisplayModePropertiesKHR* value = wrapper->decoded_value;

        value->displayMode = handle_mapping::MapHandle<DisplayModeKHRInfo>(wrapper->displayMode, object_info_table, &VulkanObjectInfoTable::GetDisplayModeKHRInfo);
    }
}

void MapStructHandles(Decoded_VkDisplayPlanePropertiesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDisplayPlanePropertiesKHR* value = wrapper->decoded_value;

        value->currentDisplay = handle_mapping::MapHandle<DisplayKHRInfo>(wrapper->currentDisplay, object_info_table, &VulkanObjectInfoTable::GetDisplayKHRInfo);
    }
}

void MapStructHandles(Decoded_VkDisplayPropertiesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDisplayPropertiesKHR* value = wrapper->decoded_value;

        value->display = handle_mapping::MapHandle<DisplayKHRInfo>(wrapper->display, object_info_table, &VulkanObjectInfoTable::GetDisplayKHRInfo);
    }
}

void MapStructHandles(Decoded_VkDisplaySurfaceCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDisplaySurfaceCreateInfoKHR* value = wrapper->decoded_value;

        value->displayMode = handle_mapping::MapHandle<DisplayModeKHRInfo>(wrapper->displayMode, object_info_table, &VulkanObjectInfoTable::GetDisplayModeKHRInfo);
    }
}

void MapStructHandles(Decoded_VkDisplayPresentInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoProfileListInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoPictureResourceInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkVideoPictureResourceInfoKHR* value = wrapper->decoded_value;

        value->imageViewBinding = handle_mapping::MapHandle<ImageViewInfo>(wrapper->imageViewBinding, object_info_table, &VulkanObjectInfoTable::GetImageViewInfo);
    }
}

void MapStructHandles(Decoded_VkVideoReferenceSlotInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkVideoPictureResourceInfoKHR>(wrapper->pPictureResource->GetMetaStructPointer(), 1, object_info_table);
    }
}

void MapStructHandles(Decoded_VkBindVideoSessionMemoryInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBindVideoSessionMemoryInfoKHR* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<DeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkVideoSessionParametersCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkVideoSessionParametersCreateInfoKHR* value = wrapper->decoded_value;

        value->videoSessionParametersTemplate = handle_mapping::MapHandle<VideoSessionParametersKHRInfo>(wrapper->videoSessionParametersTemplate, object_info_table, &VulkanObjectInfoTable::GetVideoSessionParametersKHRInfo);

        value->videoSession = handle_mapping::MapHandle<VideoSessionKHRInfo>(wrapper->videoSession, object_info_table, &VulkanObjectInfoTable::GetVideoSessionKHRInfo);
    }
}

void MapStructHandles(Decoded_VkVideoBeginCodingInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkVideoBeginCodingInfoKHR* value = wrapper->decoded_value;

        value->videoSession = handle_mapping::MapHandle<VideoSessionKHRInfo>(wrapper->videoSession, object_info_table, &VulkanObjectInfoTable::GetVideoSessionKHRInfo);

        value->videoSessionParameters = handle_mapping::MapHandle<VideoSessionParametersKHRInfo>(wrapper->videoSessionParameters, object_info_table, &VulkanObjectInfoTable::GetVideoSessionParametersKHRInfo);

        MapStructArrayHandles<Decoded_VkVideoReferenceSlotInfoKHR>(wrapper->pReferenceSlots->GetMetaStructPointer(), wrapper->pReferenceSlots->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkVideoDecodeInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkVideoDecodeInfoKHR* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->srcBuffer = handle_mapping::MapHandle<BufferInfo>(wrapper->srcBuffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);

        MapStructHandles(wrapper->dstPictureResource, object_info_table);

        MapStructArrayHandles<Decoded_VkVideoReferenceSlotInfoKHR>(wrapper->pSetupReferenceSlot->GetMetaStructPointer(), 1, object_info_table);

        MapStructArrayHandles<Decoded_VkVideoReferenceSlotInfoKHR>(wrapper->pReferenceSlots->GetMetaStructPointer(), wrapper->pReferenceSlots->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkVideoEncodeH264PictureInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeH265PictureInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoDecodeH264PictureInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkRenderingFragmentShadingRateAttachmentInfoKHR* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->imageView = handle_mapping::MapHandle<ImageViewInfo>(wrapper->imageView, object_info_table, &VulkanObjectInfoTable::GetImageViewInfo);
    }
}

void MapStructHandles(Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkRenderingFragmentDensityMapAttachmentInfoEXT* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->imageView = handle_mapping::MapHandle<ImageViewInfo>(wrapper->imageView, object_info_table, &VulkanObjectInfoTable::GetImageViewInfo);
    }
}

void MapStructHandles(Decoded_VkAttachmentSampleCountInfoAMD* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMultiviewPerViewAttributesInfoNVX* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImportMemoryWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkExportMemoryWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryGetWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryGetWin32HandleInfoKHR* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<DeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkImportMemoryFdInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryGetFdInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryGetFdInfoKHR* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<DeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkWin32KeyedMutexAcquireReleaseInfoKHR* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->pAcquireSyncs = handle_mapping::MapHandleArray<DeviceMemoryInfo>(&wrapper->pAcquireSyncs, object_info_table, &VulkanObjectInfoTable::GetDeviceMemoryInfo);

        value->pReleaseSyncs = handle_mapping::MapHandleArray<DeviceMemoryInfo>(&wrapper->pReleaseSyncs, object_info_table, &VulkanObjectInfoTable::GetDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkImportSemaphoreWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImportSemaphoreWin32HandleInfoKHR* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<SemaphoreInfo>(wrapper->semaphore, object_info_table, &VulkanObjectInfoTable::GetSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkD3D12FenceSubmitInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSemaphoreGetWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSemaphoreGetWin32HandleInfoKHR* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<SemaphoreInfo>(wrapper->semaphore, object_info_table, &VulkanObjectInfoTable::GetSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkImportSemaphoreFdInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImportSemaphoreFdInfoKHR* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<SemaphoreInfo>(wrapper->semaphore, object_info_table, &VulkanObjectInfoTable::GetSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkSemaphoreGetFdInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSemaphoreGetFdInfoKHR* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<SemaphoreInfo>(wrapper->semaphore, object_info_table, &VulkanObjectInfoTable::GetSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkPresentRegionsKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImportFenceWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImportFenceWin32HandleInfoKHR* value = wrapper->decoded_value;

        value->fence = handle_mapping::MapHandle<FenceInfo>(wrapper->fence, object_info_table, &VulkanObjectInfoTable::GetFenceInfo);
    }
}

void MapStructHandles(Decoded_VkFenceGetWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkFenceGetWin32HandleInfoKHR* value = wrapper->decoded_value;

        value->fence = handle_mapping::MapHandle<FenceInfo>(wrapper->fence, object_info_table, &VulkanObjectInfoTable::GetFenceInfo);
    }
}

void MapStructHandles(Decoded_VkImportFenceFdInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImportFenceFdInfoKHR* value = wrapper->decoded_value;

        value->fence = handle_mapping::MapHandle<FenceInfo>(wrapper->fence, object_info_table, &VulkanObjectInfoTable::GetFenceInfo);
    }
}

void MapStructHandles(Decoded_VkFenceGetFdInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkFenceGetFdInfoKHR* value = wrapper->decoded_value;

        value->fence = handle_mapping::MapHandle<FenceInfo>(wrapper->fence, object_info_table, &VulkanObjectInfoTable::GetFenceInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePerformanceQueryFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPerformanceQuerySubmitInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSurfaceInfo2KHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPhysicalDeviceSurfaceInfo2KHR* value = wrapper->decoded_value;

        value->surface = handle_mapping::MapHandle<SurfaceKHRInfo>(wrapper->surface, object_info_table, &VulkanObjectInfoTable::GetSurfaceKHRInfo);
    }
}

void MapStructHandles(Decoded_VkDisplayProperties2KHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(wrapper->displayProperties, object_info_table);
    }
}

void MapStructHandles(Decoded_VkDisplayPlaneProperties2KHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(wrapper->displayPlaneProperties, object_info_table);
    }
}

void MapStructHandles(Decoded_VkDisplayModeProperties2KHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(wrapper->displayModeProperties, object_info_table);
    }
}

void MapStructHandles(Decoded_VkDisplayPlaneInfo2KHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDisplayPlaneInfo2KHR* value = wrapper->decoded_value;

        value->mode = handle_mapping::MapHandle<DisplayModeKHRInfo>(wrapper->mode, object_info_table, &VulkanObjectInfoTable::GetDisplayModeKHRInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePortabilitySubsetFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderClockFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoDecodeH265PictureInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineFragmentShadingRateStateCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShadingRateFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderingAttachmentLocationInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderingInputAttachmentIndexInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderQuadControlFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePresentWaitFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineInfoKHR* value = wrapper->decoded_value;

        value->pipeline = handle_mapping::MapHandle<PipelineInfo>(wrapper->pipeline, object_info_table, &VulkanObjectInfoTable::GetPipelineInfo);
    }
}

void MapStructHandles(Decoded_VkPipelineExecutableInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineExecutableInfoKHR* value = wrapper->decoded_value;

        value->pipeline = handle_mapping::MapHandle<PipelineInfo>(wrapper->pipeline, object_info_table, &VulkanObjectInfoTable::GetPipelineInfo);
    }
}

void MapStructHandles(Decoded_VkMemoryMapInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryMapInfoKHR* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<DeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkMemoryUnmapInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryUnmapInfoKHR* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<DeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkPipelineLibraryCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineLibraryCreateInfoKHR* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->pLibraries = handle_mapping::MapHandleArray<PipelineInfo>(&wrapper->pLibraries, object_info_table, &VulkanObjectInfoTable::GetPipelineInfo);
    }
}

void MapStructHandles(Decoded_VkPresentIdKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePresentIdFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoEncodeInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkVideoEncodeInfoKHR* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->dstBuffer = handle_mapping::MapHandle<BufferInfo>(wrapper->dstBuffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);

        MapStructHandles(wrapper->srcPictureResource, object_info_table);

        MapStructArrayHandles<Decoded_VkVideoReferenceSlotInfoKHR>(wrapper->pSetupReferenceSlot->GetMetaStructPointer(), 1, object_info_table);

        MapStructArrayHandles<Decoded_VkVideoReferenceSlotInfoKHR>(wrapper->pReferenceSlots->GetMetaStructPointer(), wrapper->pReferenceSlots->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkVideoEncodeSessionParametersGetInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkVideoEncodeSessionParametersGetInfoKHR* value = wrapper->decoded_value;

        value->videoSessionParameters = handle_mapping::MapHandle<VideoSessionParametersKHRInfo>(wrapper->videoSessionParameters, object_info_table, &VulkanObjectInfoTable::GetVideoSessionParametersKHRInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance5FeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceImageSubresourceInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkImageCreateInfo>(wrapper->pCreateInfo->GetMetaStructPointer(), 1, object_info_table);
    }
}

void MapStructHandles(Decoded_VkPipelineCreateFlags2CreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoDecodeAV1PictureInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVideoMaintenance1FeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkVideoInlineQueryInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkVideoInlineQueryInfoKHR* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->queryPool = handle_mapping::MapHandle<QueryPoolInfo>(wrapper->queryPool, object_info_table, &VulkanObjectInfoTable::GetQueryPoolInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderFloatControls2FeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceIndexTypeUint8FeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceLineRasterizationFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderExpectAssumeFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance6FeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBindMemoryStatusKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkBindDescriptorSetsInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBindDescriptorSetsInfoKHR* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->layout = handle_mapping::MapHandle<PipelineLayoutInfo>(wrapper->layout, object_info_table, &VulkanObjectInfoTable::GetPipelineLayoutInfo);

        value->pDescriptorSets = handle_mapping::MapHandleArray<DescriptorSetInfo>(&wrapper->pDescriptorSets, object_info_table, &VulkanObjectInfoTable::GetDescriptorSetInfo);
    }
}

void MapStructHandles(Decoded_VkPushConstantsInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPushConstantsInfoKHR* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->layout = handle_mapping::MapHandle<PipelineLayoutInfo>(wrapper->layout, object_info_table, &VulkanObjectInfoTable::GetPipelineLayoutInfo);
    }
}

void MapStructHandles(Decoded_VkPushDescriptorSetInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPushDescriptorSetInfoKHR* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->layout = handle_mapping::MapHandle<PipelineLayoutInfo>(wrapper->layout, object_info_table, &VulkanObjectInfoTable::GetPipelineLayoutInfo);

        MapStructArrayHandles<Decoded_VkWriteDescriptorSet>(wrapper->pDescriptorWrites->GetMetaStructPointer(), wrapper->pDescriptorWrites->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkSetDescriptorBufferOffsetsInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSetDescriptorBufferOffsetsInfoEXT* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->layout = handle_mapping::MapHandle<PipelineLayoutInfo>(wrapper->layout, object_info_table, &VulkanObjectInfoTable::GetPipelineLayoutInfo);
    }
}

void MapStructHandles(Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBindDescriptorBufferEmbeddedSamplersInfoEXT* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->layout = handle_mapping::MapHandle<PipelineLayoutInfo>(wrapper->layout, object_info_table, &VulkanObjectInfoTable::GetPipelineLayoutInfo);
    }
}

void MapStructHandles(Decoded_VkDebugMarkerObjectNameInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDebugMarkerObjectNameInfoEXT* value = wrapper->decoded_value;

        value->object = handle_mapping::MapHandle(wrapper->object, value->objectType, object_info_table);
    }
}

void MapStructHandles(Decoded_VkDebugMarkerObjectTagInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDebugMarkerObjectTagInfoEXT* value = wrapper->decoded_value;

        value->object = handle_mapping::MapHandle(wrapper->object, value->objectType, object_info_table);
    }
}

void MapStructHandles(Decoded_VkDedicatedAllocationImageCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDedicatedAllocationMemoryAllocateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDedicatedAllocationMemoryAllocateInfoNV* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->image = handle_mapping::MapHandle<ImageInfo>(wrapper->image, object_info_table, &VulkanObjectInfoTable::GetImageInfo);

        value->buffer = handle_mapping::MapHandle<BufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageViewHandleInfoNVX* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImageViewHandleInfoNVX* value = wrapper->decoded_value;

        value->imageView = handle_mapping::MapHandle<ImageViewInfo>(wrapper->imageView, object_info_table, &VulkanObjectInfoTable::GetImageViewInfo);

        value->sampler = handle_mapping::MapHandle<SamplerInfo>(wrapper->sampler, object_info_table, &VulkanObjectInfoTable::GetSamplerInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkExternalMemoryImageCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkExportMemoryAllocateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImportMemoryWin32HandleInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkExportMemoryWin32HandleInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkWin32KeyedMutexAcquireReleaseInfoNV* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->pAcquireSyncs = handle_mapping::MapHandleArray<DeviceMemoryInfo>(&wrapper->pAcquireSyncs, object_info_table, &VulkanObjectInfoTable::GetDeviceMemoryInfo);

        value->pReleaseSyncs = handle_mapping::MapHandleArray<DeviceMemoryInfo>(&wrapper->pReleaseSyncs, object_info_table, &VulkanObjectInfoTable::GetDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkImageViewASTCDecodeModeEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePipelineRobustnessFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineRobustnessCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkConditionalRenderingBeginInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkConditionalRenderingBeginInfoEXT* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<BufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPresentTimesInfoGOOGLE* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDebugUtilsObjectNameInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDebugUtilsObjectNameInfoEXT* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->objectHandle = handle_mapping::MapHandle(wrapper->objectHandle, value->objectType, object_info_table);
    }
}

void MapStructHandles(Decoded_VkDebugUtilsMessengerCallbackDataEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkDebugUtilsObjectNameInfoEXT>(wrapper->pObjects->GetMetaStructPointer(), wrapper->pObjects->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkDebugUtilsObjectTagInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDebugUtilsObjectTagInfoEXT* value = wrapper->decoded_value;

        value->objectHandle = handle_mapping::MapHandle(wrapper->objectHandle, value->objectType, object_info_table);
    }
}

void MapStructHandles(Decoded_VkImportAndroidHardwareBufferInfoANDROID* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryGetAndroidHardwareBufferInfoANDROID* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<DeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkExternalFormatANDROID* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassSampleLocationsBeginInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageDrmFormatModifierListCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkShaderModuleValidationCacheCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkShaderModuleValidationCacheCreateInfoEXT* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->validationCache = handle_mapping::MapHandle<ValidationCacheEXTInfo>(wrapper->validationCache, object_info_table, &VulkanObjectInfoTable::GetValidationCacheEXTInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRayTracingPipelineCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkRayTracingPipelineCreateInfoNV* value = wrapper->decoded_value;

        MapStructArrayHandles<Decoded_VkPipelineShaderStageCreateInfo>(wrapper->pStages->GetMetaStructPointer(), wrapper->pStages->GetLength(), object_info_table);

        value->layout = handle_mapping::MapHandle<PipelineLayoutInfo>(wrapper->layout, object_info_table, &VulkanObjectInfoTable::GetPipelineLayoutInfo);

        value->basePipelineHandle = handle_mapping::MapHandle<PipelineInfo>(wrapper->basePipelineHandle, object_info_table, &VulkanObjectInfoTable::GetPipelineInfo);
    }
}

void MapStructHandles(Decoded_VkGeometryTrianglesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGeometryTrianglesNV* value = wrapper->decoded_value;

        value->vertexData = handle_mapping::MapHandle<BufferInfo>(wrapper->vertexData, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);

        value->indexData = handle_mapping::MapHandle<BufferInfo>(wrapper->indexData, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);

        value->transformData = handle_mapping::MapHandle<BufferInfo>(wrapper->transformData, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);
    }
}

void MapStructHandles(Decoded_VkGeometryAABBNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGeometryAABBNV* value = wrapper->decoded_value;

        value->aabbData = handle_mapping::MapHandle<BufferInfo>(wrapper->aabbData, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);
    }
}

void MapStructHandles(Decoded_VkGeometryDataNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(wrapper->triangles, object_info_table);

        MapStructHandles(wrapper->aabbs, object_info_table);
    }
}

void MapStructHandles(Decoded_VkGeometryNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(wrapper->geometry, object_info_table);
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkGeometryNV>(wrapper->pGeometries->GetMetaStructPointer(), wrapper->pGeometries->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(wrapper->info, object_info_table);
    }
}

void MapStructHandles(Decoded_VkBindAccelerationStructureMemoryInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBindAccelerationStructureMemoryInfoNV* value = wrapper->decoded_value;

        value->accelerationStructure = handle_mapping::MapHandle<AccelerationStructureNVInfo>(wrapper->accelerationStructure, object_info_table, &VulkanObjectInfoTable::GetAccelerationStructureNVInfo);

        value->memory = handle_mapping::MapHandle<DeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkWriteDescriptorSetAccelerationStructureNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkWriteDescriptorSetAccelerationStructureNV* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->pAccelerationStructures = handle_mapping::MapHandleArray<AccelerationStructureNVInfo>(&wrapper->pAccelerationStructures, object_info_table, &VulkanObjectInfoTable::GetAccelerationStructureNVInfo);
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureMemoryRequirementsInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkAccelerationStructureMemoryRequirementsInfoNV* value = wrapper->decoded_value;

        value->accelerationStructure = handle_mapping::MapHandle<AccelerationStructureNVInfo>(wrapper->accelerationStructure, object_info_table, &VulkanObjectInfoTable::GetAccelerationStructureNVInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImportMemoryHostPointerInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineCompilerControlCreateInfoAMD* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceMemoryOverallocationCreateInfoAMD* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPresentFrameTokenGGP* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMeshShaderFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryPriorityAllocateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceProvokingVertexFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceHostImageCopyFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCopyMemoryToImageInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyMemoryToImageInfoEXT* value = wrapper->decoded_value;

        value->dstImage = handle_mapping::MapHandle<ImageInfo>(wrapper->dstImage, object_info_table, &VulkanObjectInfoTable::GetImageInfo);
    }
}

void MapStructHandles(Decoded_VkCopyImageToMemoryInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyImageToMemoryInfoEXT* value = wrapper->decoded_value;

        value->srcImage = handle_mapping::MapHandle<ImageInfo>(wrapper->srcImage, object_info_table, &VulkanObjectInfoTable::GetImageInfo);
    }
}

void MapStructHandles(Decoded_VkCopyImageToImageInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyImageToImageInfoEXT* value = wrapper->decoded_value;

        value->srcImage = handle_mapping::MapHandle<ImageInfo>(wrapper->srcImage, object_info_table, &VulkanObjectInfoTable::GetImageInfo);

        value->dstImage = handle_mapping::MapHandle<ImageInfo>(wrapper->dstImage, object_info_table, &VulkanObjectInfoTable::GetImageInfo);
    }
}

void MapStructHandles(Decoded_VkHostImageLayoutTransitionInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkHostImageLayoutTransitionInfoEXT* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<ImageInfo>(wrapper->image, object_info_table, &VulkanObjectInfoTable::GetImageInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSwapchainPresentFenceInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSwapchainPresentFenceInfoEXT* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->pFences = handle_mapping::MapHandleArray<FenceInfo>(&wrapper->pFences, object_info_table, &VulkanObjectInfoTable::GetFenceInfo);
    }
}

void MapStructHandles(Decoded_VkSwapchainPresentModeInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkReleaseSwapchainImagesInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkReleaseSwapchainImagesInfoEXT* value = wrapper->decoded_value;

        value->swapchain = handle_mapping::MapHandle<SwapchainKHRInfo>(wrapper->swapchain, object_info_table, &VulkanObjectInfoTable::GetSwapchainKHRInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkGraphicsShaderGroupCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkPipelineShaderStageCreateInfo>(wrapper->pStages->GetMetaStructPointer(), wrapper->pStages->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGraphicsPipelineShaderGroupsCreateInfoNV* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        MapStructArrayHandles<Decoded_VkGraphicsShaderGroupCreateInfoNV>(wrapper->pGroups->GetMetaStructPointer(), wrapper->pGroups->GetLength(), object_info_table);

        value->pPipelines = handle_mapping::MapHandleArray<PipelineInfo>(&wrapper->pPipelines, object_info_table, &VulkanObjectInfoTable::GetPipelineInfo);
    }
}

void MapStructHandles(Decoded_VkIndirectCommandsStreamNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkIndirectCommandsStreamNV* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<BufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);
    }
}

void MapStructHandles(Decoded_VkIndirectCommandsLayoutTokenNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkIndirectCommandsLayoutTokenNV* value = wrapper->decoded_value;

        value->pushconstantPipelineLayout = handle_mapping::MapHandle<PipelineLayoutInfo>(wrapper->pushconstantPipelineLayout, object_info_table, &VulkanObjectInfoTable::GetPipelineLayoutInfo);
    }
}

void MapStructHandles(Decoded_VkIndirectCommandsLayoutCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkIndirectCommandsLayoutTokenNV>(wrapper->pTokens->GetMetaStructPointer(), wrapper->pTokens->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkGeneratedCommandsInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGeneratedCommandsInfoNV* value = wrapper->decoded_value;

        value->pipeline = handle_mapping::MapHandle<PipelineInfo>(wrapper->pipeline, object_info_table, &VulkanObjectInfoTable::GetPipelineInfo);

        value->indirectCommandsLayout = handle_mapping::MapHandle<IndirectCommandsLayoutNVInfo>(wrapper->indirectCommandsLayout, object_info_table, &VulkanObjectInfoTable::GetIndirectCommandsLayoutNVInfo);

        MapStructArrayHandles<Decoded_VkIndirectCommandsStreamNV>(wrapper->pStreams->GetMetaStructPointer(), wrapper->pStreams->GetLength(), object_info_table);

        value->preprocessBuffer = handle_mapping::MapHandle<BufferInfo>(wrapper->preprocessBuffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);

        value->sequencesCountBuffer = handle_mapping::MapHandle<BufferInfo>(wrapper->sequencesCountBuffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);

        value->sequencesIndexBuffer = handle_mapping::MapHandle<BufferInfo>(wrapper->sequencesIndexBuffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);
    }
}

void MapStructHandles(Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGeneratedCommandsMemoryRequirementsInfoNV* value = wrapper->decoded_value;

        value->pipeline = handle_mapping::MapHandle<PipelineInfo>(wrapper->pipeline, object_info_table, &VulkanObjectInfoTable::GetPipelineInfo);

        value->indirectCommandsLayout = handle_mapping::MapHandle<IndirectCommandsLayoutNVInfo>(wrapper->indirectCommandsLayout, object_info_table, &VulkanObjectInfoTable::GetIndirectCommandsLayoutNVInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceInheritedViewportScissorFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassTransformBeginInfoQCOM* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDepthBiasControlFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceDeviceMemoryReportCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRobustness2FeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSamplerCustomBorderColorCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePresentBarrierFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceDiagnosticsConfigCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkGraphicsPipelineLibraryCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineFragmentShadingRateEnumStateCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureGeometryMotionTrianglesDataNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageCompressionControlFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageCompressionControlEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevice4444FormatsFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFaultFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceAddressBindingReportFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDepthClipControlFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImportMemoryZirconHandleInfoFUCHSIA* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryGetZirconHandleInfoFUCHSIA* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryGetZirconHandleInfoFUCHSIA* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<DeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImportSemaphoreZirconHandleInfoFUCHSIA* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<SemaphoreInfo>(wrapper->semaphore, object_info_table, &VulkanObjectInfoTable::GetSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSemaphoreGetZirconHandleInfoFUCHSIA* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<SemaphoreInfo>(wrapper->semaphore, object_info_table, &VulkanObjectInfoTable::GetSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMemoryGetRemoteAddressInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryGetRemoteAddressInfoNV* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<DeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFrameBoundaryFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkFrameBoundaryEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkFrameBoundaryEXT* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->pImages = handle_mapping::MapHandleArray<ImageInfo>(&wrapper->pImages, object_info_table, &VulkanObjectInfoTable::GetImageInfo);

        value->pBuffers = handle_mapping::MapHandleArray<BufferInfo>(&wrapper->pBuffers, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMultisampledRenderToSingleSampledInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceColorWriteEnableFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageViewMinLodFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageViewMinLodCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMultiDrawFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderTileImageFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMicromapBuildInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMicromapBuildInfoEXT* value = wrapper->decoded_value;

        value->dstMicromap = handle_mapping::MapHandle<MicromapEXTInfo>(wrapper->dstMicromap, object_info_table, &VulkanObjectInfoTable::GetMicromapEXTInfo);
    }
}

void MapStructHandles(Decoded_VkMicromapCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMicromapCreateInfoEXT* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<BufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceOpacityMicromapFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkCopyMicromapToMemoryInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyMicromapToMemoryInfoEXT* value = wrapper->decoded_value;

        value->src = handle_mapping::MapHandle<MicromapEXTInfo>(wrapper->src, object_info_table, &VulkanObjectInfoTable::GetMicromapEXTInfo);
    }
}

void MapStructHandles(Decoded_VkCopyMemoryToMicromapInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyMemoryToMicromapInfoEXT* value = wrapper->decoded_value;

        value->dst = handle_mapping::MapHandle<MicromapEXTInfo>(wrapper->dst, object_info_table, &VulkanObjectInfoTable::GetMicromapEXTInfo);
    }
}

void MapStructHandles(Decoded_VkCopyMicromapInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyMicromapInfoEXT* value = wrapper->decoded_value;

        value->src = handle_mapping::MapHandle<MicromapEXTInfo>(wrapper->src, object_info_table, &VulkanObjectInfoTable::GetMicromapEXTInfo);

        value->dst = handle_mapping::MapHandle<MicromapEXTInfo>(wrapper->dst, object_info_table, &VulkanObjectInfoTable::GetMicromapEXTInfo);
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkAccelerationStructureTrianglesOpacityMicromapEXT* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->micromap = handle_mapping::MapHandle<MicromapEXTInfo>(wrapper->micromap, object_info_table, &VulkanObjectInfoTable::GetMicromapEXTInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDisplacementMicromapFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureTrianglesDisplacementMicromapNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkAccelerationStructureTrianglesDisplacementMicromapNV* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->micromap = handle_mapping::MapHandle<MicromapEXTInfo>(wrapper->micromap, object_info_table, &VulkanObjectInfoTable::GetMicromapEXTInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSamplerBorderColorComponentMappingCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceQueueShaderCoreControlCreateInfoARM* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSchedulingControlsFeaturesARM* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageViewSlicedCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorSetBindingReferenceVALVE* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDescriptorSetBindingReferenceVALVE* value = wrapper->decoded_value;

        value->descriptorSetLayout = handle_mapping::MapHandle<DescriptorSetLayoutInfo>(wrapper->descriptorSetLayout, object_info_table, &VulkanObjectInfoTable::GetDescriptorSetLayoutInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDepthClampZeroOneFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRenderPassStripedFeaturesARM* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassStripeBeginInfoARM* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkRenderPassStripeSubmitInfoARM* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkSemaphoreSubmitInfo>(wrapper->pStripeSemaphoreInfos->GetMetaStructPointer(), wrapper->pStripeSemaphoreInfos->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineIndirectDeviceAddressInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineIndirectDeviceAddressInfoNV* value = wrapper->decoded_value;

        value->pipeline = handle_mapping::MapHandle<PipelineInfo>(wrapper->pipeline, object_info_table, &VulkanObjectInfoTable::GetPipelineInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceLinearColorAttachmentFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkImageViewSampleWeightCreateInfoQCOM* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageProcessingFeaturesQCOM* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceNestedCommandBufferFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineShaderStageModuleIdentifierCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceOpticalFlowFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkOpticalFlowImageFormatInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceLegacyDitheringFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePipelineProtectedAccessFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderObjectFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkShaderCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkShaderCreateInfoEXT* value = wrapper->decoded_value;

        value->pSetLayouts = handle_mapping::MapHandleArray<DescriptorSetLayoutInfo>(&wrapper->pSetLayouts, object_info_table, &VulkanObjectInfoTable::GetDescriptorSetLayoutInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceTilePropertiesFeaturesQCOM* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceAmigoProfilingFeaturesSEC* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAmigoProfilingSubmitInfoSEC* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkLatencySleepInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkLatencySleepInfoNV* value = wrapper->decoded_value;

        value->signalSemaphore = handle_mapping::MapHandle<SemaphoreInfo>(wrapper->signalSemaphore, object_info_table, &VulkanObjectInfoTable::GetSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkLatencySubmissionPresentIdNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDevicePerStageDescriptorSetFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceImageProcessing2FeaturesQCOM* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSamplerBlockMatchWindowCreateInfoQCOM* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCubicWeightsFeaturesQCOM* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkSamplerCubicWeightsCreateInfoQCOM* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceCubicClampFeaturesQCOM* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRawAccessChainsFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingValidationFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureGeometryTrianglesDataKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureBuildGeometryInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkAccelerationStructureBuildGeometryInfoKHR* value = wrapper->decoded_value;

        value->srcAccelerationStructure = handle_mapping::MapHandle<AccelerationStructureKHRInfo>(wrapper->srcAccelerationStructure, object_info_table, &VulkanObjectInfoTable::GetAccelerationStructureKHRInfo);

        value->dstAccelerationStructure = handle_mapping::MapHandle<AccelerationStructureKHRInfo>(wrapper->dstAccelerationStructure, object_info_table, &VulkanObjectInfoTable::GetAccelerationStructureKHRInfo);
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkAccelerationStructureCreateInfoKHR* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<BufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetBufferInfo);
    }
}

void MapStructHandles(Decoded_VkWriteDescriptorSetAccelerationStructureKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkWriteDescriptorSetAccelerationStructureKHR* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->pAccelerationStructures = handle_mapping::MapHandleArray<AccelerationStructureKHRInfo>(&wrapper->pAccelerationStructures, object_info_table, &VulkanObjectInfoTable::GetAccelerationStructureKHRInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceAccelerationStructureFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureDeviceAddressInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkAccelerationStructureDeviceAddressInfoKHR* value = wrapper->decoded_value;

        value->accelerationStructure = handle_mapping::MapHandle<AccelerationStructureKHRInfo>(wrapper->accelerationStructure, object_info_table, &VulkanObjectInfoTable::GetAccelerationStructureKHRInfo);
    }
}

void MapStructHandles(Decoded_VkCopyAccelerationStructureToMemoryInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyAccelerationStructureToMemoryInfoKHR* value = wrapper->decoded_value;

        value->src = handle_mapping::MapHandle<AccelerationStructureKHRInfo>(wrapper->src, object_info_table, &VulkanObjectInfoTable::GetAccelerationStructureKHRInfo);
    }
}

void MapStructHandles(Decoded_VkCopyMemoryToAccelerationStructureInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyMemoryToAccelerationStructureInfoKHR* value = wrapper->decoded_value;

        value->dst = handle_mapping::MapHandle<AccelerationStructureKHRInfo>(wrapper->dst, object_info_table, &VulkanObjectInfoTable::GetAccelerationStructureKHRInfo);
    }
}

void MapStructHandles(Decoded_VkCopyAccelerationStructureInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyAccelerationStructureInfoKHR* value = wrapper->decoded_value;

        value->src = handle_mapping::MapHandle<AccelerationStructureKHRInfo>(wrapper->src, object_info_table, &VulkanObjectInfoTable::GetAccelerationStructureKHRInfo);

        value->dst = handle_mapping::MapHandle<AccelerationStructureKHRInfo>(wrapper->dst, object_info_table, &VulkanObjectInfoTable::GetAccelerationStructureKHRInfo);
    }
}

void MapStructHandles(Decoded_VkRayTracingPipelineCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkRayTracingPipelineCreateInfoKHR* value = wrapper->decoded_value;

        MapStructArrayHandles<Decoded_VkPipelineShaderStageCreateInfo>(wrapper->pStages->GetMetaStructPointer(), wrapper->pStages->GetLength(), object_info_table);

        MapStructArrayHandles<Decoded_VkPipelineLibraryCreateInfoKHR>(wrapper->pLibraryInfo->GetMetaStructPointer(), 1, object_info_table);

        value->layout = handle_mapping::MapHandle<PipelineLayoutInfo>(wrapper->layout, object_info_table, &VulkanObjectInfoTable::GetPipelineLayoutInfo);

        value->basePipelineHandle = handle_mapping::MapHandle<PipelineInfo>(wrapper->basePipelineHandle, object_info_table, &VulkanObjectInfoTable::GetPipelineInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingPipelineFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceRayQueryFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceMeshShaderFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapPNextStructHandles(const void* value, void* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((value != nullptr) && (wrapper != nullptr))
    {
        const VkBaseInStructure* base = reinterpret_cast<const VkBaseInStructure*>(value);

        switch (base->sType)
        {
        default:
            // TODO: Report or raise fatal error for unrecongized sType?
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkShaderModuleCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineLayoutCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevice16BitStorageFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryDedicatedAllocateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryAllocateFlagsInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceGroupRenderPassBeginInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceGroupSubmitInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceGroupBindSparseInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkBindImageMemoryDeviceGroupInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceGroupDeviceCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkImageViewUsageCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVariablePointersFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceProtectedMemoryFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkProtectedSubmitInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkSamplerYcbcrConversionInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkBindImagePlaneMemoryInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkExternalMemoryImageCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkExportMemoryAllocateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderDrawParametersFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVulkan11Features*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVulkan12Features*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkImageFormatListCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevice8BitStorageFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderAtomicInt64Features*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderFloat16Int8Features*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorIndexingFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkImageStencilUsageCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkSamplerReductionModeCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImagelessFramebufferFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassAttachmentBeginInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceHostQueryResetFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkTimelineSemaphoreSubmitInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVulkan13Features*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineCreationFeedbackCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderTerminateInvocationFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePrivateDataFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDevicePrivateDataCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePipelineCreationCacheControlFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSynchronization2Features*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImageRobustnessFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSubgroupSizeControlFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceInlineUniformBlockFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK:
            MapStructHandles(reinterpret_cast<Decoded_VkWriteDescriptorSetInlineUniformBlock*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineRenderingCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDynamicRenderingFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderIntegerDotProductFeatures*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance4Features*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkImageSwapchainCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkBindImageMemorySwapchainInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceGroupPresentInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkDisplayPresentInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoProfileListInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeH264PictureInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PICTURE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoEncodeH265PictureInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoDecodeH264PictureInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkAttachmentSampleCountInfoAMD*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX:
            MapStructHandles(reinterpret_cast<Decoded_VkMultiviewPerViewAttributesInfoNVX*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkImportMemoryWin32HandleInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkExportMemoryWin32HandleInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkImportMemoryFdInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkD3D12FenceSubmitInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPresentRegionsKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePerformanceQueryFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPerformanceQuerySubmitInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderClockFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoDecodeH265PictureInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineFragmentShadingRateStateCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderingAttachmentLocationInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderingInputAttachmentIndexInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderQuadControlFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePresentWaitFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineLibraryCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_ID_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPresentIdKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePresentIdFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance5FeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineCreateFlags2CreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoDecodeAV1PictureInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVideoMaintenance1FeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoInlineQueryInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderFloatControls2FeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceIndexTypeUint8FeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceLineRasterizationFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderExpectAssumeFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance6FeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkBindMemoryStatusKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkDedicatedAllocationImageCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkDedicatedAllocationMemoryAllocateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkExternalMemoryImageCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkExportMemoryAllocateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkImportMemoryWin32HandleInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkExportMemoryWin32HandleInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImageViewASTCDecodeModeEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePipelineRobustnessFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineRobustnessCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
            MapStructHandles(reinterpret_cast<Decoded_VkPresentTimesInfoGOOGLE*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDebugUtilsObjectNameInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            MapStructHandles(reinterpret_cast<Decoded_VkImportAndroidHardwareBufferInfoANDROID*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
            MapStructHandles(reinterpret_cast<Decoded_VkExternalFormatANDROID*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassSampleLocationsBeginInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImageDrmFormatModifierListCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkShaderModuleValidationCacheCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkWriteDescriptorSetAccelerationStructureNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImportMemoryHostPointerInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineCompilerControlCreateInfoAMD*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceMemoryOverallocationCreateInfoAMD*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
            MapStructHandles(reinterpret_cast<Decoded_VkPresentFrameTokenGGP*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMeshShaderFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryPriorityAllocateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceProvokingVertexFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceHostImageCopyFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkSwapchainPresentFenceInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkSwapchainPresentModeInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassTransformBeginInfoQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceDeviceMemoryReportCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRobustness2FeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkSamplerCustomBorderColorCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePresentBarrierFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceDiagnosticsConfigCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkGraphicsPipelineLibraryCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineFragmentShadingRateEnumStateCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureGeometryMotionTrianglesDataNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImageCompressionControlEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevice4444FormatsFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFaultFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDepthClipControlFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA:
            MapStructHandles(reinterpret_cast<Decoded_VkImportMemoryZirconHandleInfoFUCHSIA*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFrameBoundaryFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkFrameBoundaryEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkMultisampledRenderToSingleSampledInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImageViewMinLodCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMultiDrawFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderTileImageFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDisplacementMicromapFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureTrianglesDisplacementMicromapNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkSamplerBorderColorComponentMappingCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceQueueShaderCoreControlCreateInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSchedulingControlsFeaturesARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkImageViewSlicedCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDepthClampZeroOneFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRenderPassStripedFeaturesARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassStripeBeginInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassStripeSubmitInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkImageViewSampleWeightCreateInfoQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImageProcessingFeaturesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceNestedCommandBufferFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineShaderStageModuleIdentifierCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceOpticalFlowFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkOpticalFlowImageFormatInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePipelineProtectedAccessFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderObjectFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC:
            MapStructHandles(reinterpret_cast<Decoded_VkAmigoProfilingSubmitInfoSEC*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkLatencySubmissionPresentIdNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDevicePerStageDescriptorSetFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceImageProcessing2FeaturesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkSamplerBlockMatchWindowCreateInfoQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCubicWeightsFeaturesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkSamplerCubicWeightsCreateInfoQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceCubicClampFeaturesQCOM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRawAccessChainsFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingValidationFeaturesNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkWriteDescriptorSetAccelerationStructureKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceRayQueryFeaturesKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkPhysicalDeviceMeshShaderFeaturesEXT*>(wrapper), object_info_table);
            break;
        }
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_VkPhysicalDeviceGroupProperties* id_wrapper, const VkPhysicalDeviceGroupProperties* handle_struct, VulkanObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        handle_mapping::AddHandleArray<PhysicalDeviceInfo>(parent_id, id_wrapper->physicalDevices.GetPointer(), id_wrapper->physicalDevices.GetLength(), handle_struct->physicalDevices, handle_struct->physicalDeviceCount, object_info_table, &VulkanObjectInfoTable::AddPhysicalDeviceInfo);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayPropertiesKHR* id_wrapper, const VkDisplayPropertiesKHR* handle_struct, VulkanObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        handle_mapping::AddHandle<DisplayKHRInfo>(parent_id, id_wrapper->display, handle_struct->display, object_info_table, &VulkanObjectInfoTable::AddDisplayKHRInfo);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayPlanePropertiesKHR* id_wrapper, const VkDisplayPlanePropertiesKHR* handle_struct, VulkanObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        handle_mapping::AddHandle<DisplayKHRInfo>(parent_id, id_wrapper->currentDisplay, handle_struct->currentDisplay, object_info_table, &VulkanObjectInfoTable::AddDisplayKHRInfo);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayModePropertiesKHR* id_wrapper, const VkDisplayModePropertiesKHR* handle_struct, VulkanObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        handle_mapping::AddHandle<DisplayModeKHRInfo>(parent_id, id_wrapper->displayMode, handle_struct->displayMode, object_info_table, &VulkanObjectInfoTable::AddDisplayModeKHRInfo);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayProperties2KHR* id_wrapper, const VkDisplayProperties2KHR* handle_struct, VulkanObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        AddStructHandles(parent_id, id_wrapper->displayProperties, &handle_struct->displayProperties, object_info_table);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayPlaneProperties2KHR* id_wrapper, const VkDisplayPlaneProperties2KHR* handle_struct, VulkanObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        AddStructHandles(parent_id, id_wrapper->displayPlaneProperties, &handle_struct->displayPlaneProperties, object_info_table);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayModeProperties2KHR* id_wrapper, const VkDisplayModeProperties2KHR* handle_struct, VulkanObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        AddStructHandles(parent_id, id_wrapper->displayModeProperties, &handle_struct->displayModeProperties, object_info_table);
    }
}

void SetStructHandleLengths(Decoded_VkPhysicalDeviceGroupProperties* wrapper)
{
    if (wrapper != nullptr)
    {
        wrapper->physicalDevices.SetHandleLength(wrapper->physicalDevices.GetLength());
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
