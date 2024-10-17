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

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);
    }
}

void MapStructHandles(Decoded_VkImageMemoryBarrier* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImageMemoryBarrier* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);
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

        value->pWaitSemaphores = handle_mapping::MapHandleArray<VulkanSemaphoreInfo>(&wrapper->pWaitSemaphores, object_info_table, &VulkanObjectInfoTable::GetVkSemaphoreInfo);

        value->pCommandBuffers = handle_mapping::MapHandleArray<VulkanCommandBufferInfo>(&wrapper->pCommandBuffers, object_info_table, &VulkanObjectInfoTable::GetVkCommandBufferInfo);

        value->pSignalSemaphores = handle_mapping::MapHandleArray<VulkanSemaphoreInfo>(&wrapper->pSignalSemaphores, object_info_table, &VulkanObjectInfoTable::GetVkSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkMappedMemoryRange* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMappedMemoryRange* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetVkDeviceMemoryInfo);
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

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetVkDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkSparseBufferMemoryBindInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSparseBufferMemoryBindInfo* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);

        MapStructArrayHandles<Decoded_VkSparseMemoryBind>(wrapper->pBinds->GetMetaStructPointer(), wrapper->pBinds->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkSparseImageOpaqueMemoryBindInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSparseImageOpaqueMemoryBindInfo* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);

        MapStructArrayHandles<Decoded_VkSparseMemoryBind>(wrapper->pBinds->GetMetaStructPointer(), wrapper->pBinds->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkSparseImageMemoryBind* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSparseImageMemoryBind* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetVkDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkSparseImageMemoryBindInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSparseImageMemoryBindInfo* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);

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

        value->pWaitSemaphores = handle_mapping::MapHandleArray<VulkanSemaphoreInfo>(&wrapper->pWaitSemaphores, object_info_table, &VulkanObjectInfoTable::GetVkSemaphoreInfo);

        MapStructArrayHandles<Decoded_VkSparseBufferMemoryBindInfo>(wrapper->pBufferBinds->GetMetaStructPointer(), wrapper->pBufferBinds->GetLength(), object_info_table);

        MapStructArrayHandles<Decoded_VkSparseImageOpaqueMemoryBindInfo>(wrapper->pImageOpaqueBinds->GetMetaStructPointer(), wrapper->pImageOpaqueBinds->GetLength(), object_info_table);

        MapStructArrayHandles<Decoded_VkSparseImageMemoryBindInfo>(wrapper->pImageBinds->GetMetaStructPointer(), wrapper->pImageBinds->GetLength(), object_info_table);

        value->pSignalSemaphores = handle_mapping::MapHandleArray<VulkanSemaphoreInfo>(&wrapper->pSignalSemaphores, object_info_table, &VulkanObjectInfoTable::GetVkSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkBufferViewCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBufferViewCreateInfo* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);
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

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);
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

        value->module = handle_mapping::MapHandle<VulkanShaderModuleInfo>(wrapper->module, object_info_table, &VulkanObjectInfoTable::GetVkShaderModuleInfo);
    }
}

void MapStructHandles(Decoded_VkComputePipelineCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkComputePipelineCreateInfo* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        MapStructHandles(wrapper->stage, object_info_table);

        value->layout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->layout, object_info_table, &VulkanObjectInfoTable::GetVkPipelineLayoutInfo);

        value->basePipelineHandle = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->basePipelineHandle, object_info_table, &VulkanObjectInfoTable::GetVkPipelineInfo);
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

        value->layout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->layout, object_info_table, &VulkanObjectInfoTable::GetVkPipelineLayoutInfo);

        value->renderPass = handle_mapping::MapHandle<VulkanRenderPassInfo>(wrapper->renderPass, object_info_table, &VulkanObjectInfoTable::GetVkRenderPassInfo);

        value->basePipelineHandle = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->basePipelineHandle, object_info_table, &VulkanObjectInfoTable::GetVkPipelineInfo);
    }
}

void MapStructHandles(Decoded_VkPipelineLayoutCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineLayoutCreateInfo* value = wrapper->decoded_value;

        value->pSetLayouts = handle_mapping::MapHandleArray<VulkanDescriptorSetLayoutInfo>(&wrapper->pSetLayouts, object_info_table, &VulkanObjectInfoTable::GetVkDescriptorSetLayoutInfo);
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

        value->srcSet = handle_mapping::MapHandle<VulkanDescriptorSetInfo>(wrapper->srcSet, object_info_table, &VulkanObjectInfoTable::GetVkDescriptorSetInfo);

        value->dstSet = handle_mapping::MapHandle<VulkanDescriptorSetInfo>(wrapper->dstSet, object_info_table, &VulkanObjectInfoTable::GetVkDescriptorSetInfo);
    }
}

void MapStructHandles(Decoded_VkDescriptorBufferInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDescriptorBufferInfo* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);
    }
}

void MapStructHandles(Decoded_VkDescriptorSetAllocateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDescriptorSetAllocateInfo* value = wrapper->decoded_value;

        value->descriptorPool = handle_mapping::MapHandle<VulkanDescriptorPoolInfo>(wrapper->descriptorPool, object_info_table, &VulkanObjectInfoTable::GetVkDescriptorPoolInfo);

        value->pSetLayouts = handle_mapping::MapHandleArray<VulkanDescriptorSetLayoutInfo>(&wrapper->pSetLayouts, object_info_table, &VulkanObjectInfoTable::GetVkDescriptorSetLayoutInfo);
    }
}

void MapStructHandles(Decoded_VkDescriptorSetLayoutBinding* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDescriptorSetLayoutBinding* value = wrapper->decoded_value;

        value->pImmutableSamplers = handle_mapping::MapHandleArray<VulkanSamplerInfo>(&wrapper->pImmutableSamplers, object_info_table, &VulkanObjectInfoTable::GetVkSamplerInfo);
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

        value->renderPass = handle_mapping::MapHandle<VulkanRenderPassInfo>(wrapper->renderPass, object_info_table, &VulkanObjectInfoTable::GetVkRenderPassInfo);

        value->pAttachments = handle_mapping::MapHandleArray<VulkanImageViewInfo>(&wrapper->pAttachments, object_info_table, &VulkanObjectInfoTable::GetVkImageViewInfo);
    }
}

void MapStructHandles(Decoded_VkCommandBufferAllocateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCommandBufferAllocateInfo* value = wrapper->decoded_value;

        value->commandPool = handle_mapping::MapHandle<VulkanCommandPoolInfo>(wrapper->commandPool, object_info_table, &VulkanObjectInfoTable::GetVkCommandPoolInfo);
    }
}

void MapStructHandles(Decoded_VkCommandBufferInheritanceInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCommandBufferInheritanceInfo* value = wrapper->decoded_value;

        value->renderPass = handle_mapping::MapHandle<VulkanRenderPassInfo>(wrapper->renderPass, object_info_table, &VulkanObjectInfoTable::GetVkRenderPassInfo);

        value->framebuffer = handle_mapping::MapHandle<VulkanFramebufferInfo>(wrapper->framebuffer, object_info_table, &VulkanObjectInfoTable::GetVkFramebufferInfo);
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

        value->renderPass = handle_mapping::MapHandle<VulkanRenderPassInfo>(wrapper->renderPass, object_info_table, &VulkanObjectInfoTable::GetVkRenderPassInfo);

        value->framebuffer = handle_mapping::MapHandle<VulkanFramebufferInfo>(wrapper->framebuffer, object_info_table, &VulkanObjectInfoTable::GetVkFramebufferInfo);
    }
}

void MapStructHandles(Decoded_VkBindBufferMemoryInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBindBufferMemoryInfo* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetVkDeviceMemoryInfo);
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

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetVkDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkMemoryDedicatedAllocateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryDedicatedAllocateInfo* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceGroupProperties* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        handle_mapping::MapHandleArray<VulkanPhysicalDeviceInfo>(&wrapper->physicalDevices, object_info_table, &VulkanObjectInfoTable::GetVkPhysicalDeviceInfo);
    }
}

void MapStructHandles(Decoded_VkDeviceGroupDeviceCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDeviceGroupDeviceCreateInfo* value = wrapper->decoded_value;

        value->pPhysicalDevices = handle_mapping::MapHandleArray<VulkanPhysicalDeviceInfo>(&wrapper->pPhysicalDevices, object_info_table, &VulkanObjectInfoTable::GetVkPhysicalDeviceInfo);
    }
}

void MapStructHandles(Decoded_VkBufferMemoryRequirementsInfo2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBufferMemoryRequirementsInfo2* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);
    }
}

void MapStructHandles(Decoded_VkImageMemoryRequirementsInfo2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImageMemoryRequirementsInfo2* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);
    }
}

void MapStructHandles(Decoded_VkImageSparseMemoryRequirementsInfo2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImageSparseMemoryRequirementsInfo2* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);
    }
}

void MapStructHandles(Decoded_VkSamplerYcbcrConversionInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSamplerYcbcrConversionInfo* value = wrapper->decoded_value;

        value->conversion = handle_mapping::MapHandle<VulkanSamplerYcbcrConversionInfo>(wrapper->conversion, object_info_table, &VulkanObjectInfoTable::GetVkSamplerYcbcrConversionInfo);
    }
}

void MapStructHandles(Decoded_VkDescriptorUpdateTemplateCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDescriptorUpdateTemplateCreateInfo* value = wrapper->decoded_value;

        value->descriptorSetLayout = handle_mapping::MapHandle<VulkanDescriptorSetLayoutInfo>(wrapper->descriptorSetLayout, object_info_table, &VulkanObjectInfoTable::GetVkDescriptorSetLayoutInfo);

        value->pipelineLayout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->pipelineLayout, object_info_table, &VulkanObjectInfoTable::GetVkPipelineLayoutInfo);
    }
}

void MapStructHandles(Decoded_VkRenderPassAttachmentBeginInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkRenderPassAttachmentBeginInfo* value = wrapper->decoded_value;

        value->pAttachments = handle_mapping::MapHandleArray<VulkanImageViewInfo>(&wrapper->pAttachments, object_info_table, &VulkanObjectInfoTable::GetVkImageViewInfo);
    }
}

void MapStructHandles(Decoded_VkSemaphoreWaitInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSemaphoreWaitInfo* value = wrapper->decoded_value;

        value->pSemaphores = handle_mapping::MapHandleArray<VulkanSemaphoreInfo>(&wrapper->pSemaphores, object_info_table, &VulkanObjectInfoTable::GetVkSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkSemaphoreSignalInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSemaphoreSignalInfo* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<VulkanSemaphoreInfo>(wrapper->semaphore, object_info_table, &VulkanObjectInfoTable::GetVkSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkBufferDeviceAddressInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBufferDeviceAddressInfo* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);
    }
}

void MapStructHandles(Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDeviceMemoryOpaqueCaptureAddressInfo* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetVkDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkBufferMemoryBarrier2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBufferMemoryBarrier2* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);
    }
}

void MapStructHandles(Decoded_VkImageMemoryBarrier2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImageMemoryBarrier2* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);
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

        value->semaphore = handle_mapping::MapHandle<VulkanSemaphoreInfo>(wrapper->semaphore, object_info_table, &VulkanObjectInfoTable::GetVkSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkCommandBufferSubmitInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCommandBufferSubmitInfo* value = wrapper->decoded_value;

        value->commandBuffer = handle_mapping::MapHandle<VulkanCommandBufferInfo>(wrapper->commandBuffer, object_info_table, &VulkanObjectInfoTable::GetVkCommandBufferInfo);
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

void MapStructHandles(Decoded_VkCopyBufferInfo2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyBufferInfo2* value = wrapper->decoded_value;

        value->srcBuffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->srcBuffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);

        value->dstBuffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->dstBuffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);
    }
}

void MapStructHandles(Decoded_VkCopyImageInfo2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyImageInfo2* value = wrapper->decoded_value;

        value->srcImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->srcImage, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);

        value->dstImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->dstImage, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);
    }
}

void MapStructHandles(Decoded_VkCopyBufferToImageInfo2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyBufferToImageInfo2* value = wrapper->decoded_value;

        value->srcBuffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->srcBuffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);

        value->dstImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->dstImage, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);
    }
}

void MapStructHandles(Decoded_VkCopyImageToBufferInfo2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyImageToBufferInfo2* value = wrapper->decoded_value;

        value->srcImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->srcImage, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);

        value->dstBuffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->dstBuffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);
    }
}

void MapStructHandles(Decoded_VkBlitImageInfo2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBlitImageInfo2* value = wrapper->decoded_value;

        value->srcImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->srcImage, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);

        value->dstImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->dstImage, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);
    }
}

void MapStructHandles(Decoded_VkResolveImageInfo2* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkResolveImageInfo2* value = wrapper->decoded_value;

        value->srcImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->srcImage, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);

        value->dstImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->dstImage, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);
    }
}

void MapStructHandles(Decoded_VkRenderingAttachmentInfo* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkRenderingAttachmentInfo* value = wrapper->decoded_value;

        value->imageView = handle_mapping::MapHandle<VulkanImageViewInfo>(wrapper->imageView, object_info_table, &VulkanObjectInfoTable::GetVkImageViewInfo);

        value->resolveImageView = handle_mapping::MapHandle<VulkanImageViewInfo>(wrapper->resolveImageView, object_info_table, &VulkanObjectInfoTable::GetVkImageViewInfo);
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

        value->surface = handle_mapping::MapHandle<VulkanSurfaceKHRInfo>(wrapper->surface, object_info_table, &VulkanObjectInfoTable::GetVkSurfaceKHRInfo);

        value->oldSwapchain = handle_mapping::MapHandle<VulkanSwapchainKHRInfo>(wrapper->oldSwapchain, object_info_table, &VulkanObjectInfoTable::GetVkSwapchainKHRInfo);
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

        value->pWaitSemaphores = handle_mapping::MapHandleArray<VulkanSemaphoreInfo>(&wrapper->pWaitSemaphores, object_info_table, &VulkanObjectInfoTable::GetVkSemaphoreInfo);

        value->pSwapchains = handle_mapping::MapHandleArray<VulkanSwapchainKHRInfo>(&wrapper->pSwapchains, object_info_table, &VulkanObjectInfoTable::GetVkSwapchainKHRInfo);
    }
}

void MapStructHandles(Decoded_VkImageSwapchainCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImageSwapchainCreateInfoKHR* value = wrapper->decoded_value;

        value->swapchain = handle_mapping::MapHandle<VulkanSwapchainKHRInfo>(wrapper->swapchain, object_info_table, &VulkanObjectInfoTable::GetVkSwapchainKHRInfo);
    }
}

void MapStructHandles(Decoded_VkBindImageMemorySwapchainInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkBindImageMemorySwapchainInfoKHR* value = wrapper->decoded_value;

        value->swapchain = handle_mapping::MapHandle<VulkanSwapchainKHRInfo>(wrapper->swapchain, object_info_table, &VulkanObjectInfoTable::GetVkSwapchainKHRInfo);
    }
}

void MapStructHandles(Decoded_VkAcquireNextImageInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkAcquireNextImageInfoKHR* value = wrapper->decoded_value;

        value->swapchain = handle_mapping::MapHandle<VulkanSwapchainKHRInfo>(wrapper->swapchain, object_info_table, &VulkanObjectInfoTable::GetVkSwapchainKHRInfo);

        value->semaphore = handle_mapping::MapHandle<VulkanSemaphoreInfo>(wrapper->semaphore, object_info_table, &VulkanObjectInfoTable::GetVkSemaphoreInfo);

        value->fence = handle_mapping::MapHandle<VulkanFenceInfo>(wrapper->fence, object_info_table, &VulkanObjectInfoTable::GetVkFenceInfo);
    }
}

void MapStructHandles(Decoded_VkDisplayModePropertiesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDisplayModePropertiesKHR* value = wrapper->decoded_value;

        value->displayMode = handle_mapping::MapHandle<VulkanDisplayModeKHRInfo>(wrapper->displayMode, object_info_table, &VulkanObjectInfoTable::GetVkDisplayModeKHRInfo);
    }
}

void MapStructHandles(Decoded_VkDisplayPlanePropertiesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDisplayPlanePropertiesKHR* value = wrapper->decoded_value;

        value->currentDisplay = handle_mapping::MapHandle<VulkanDisplayKHRInfo>(wrapper->currentDisplay, object_info_table, &VulkanObjectInfoTable::GetVkDisplayKHRInfo);
    }
}

void MapStructHandles(Decoded_VkDisplayPropertiesKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDisplayPropertiesKHR* value = wrapper->decoded_value;

        value->display = handle_mapping::MapHandle<VulkanDisplayKHRInfo>(wrapper->display, object_info_table, &VulkanObjectInfoTable::GetVkDisplayKHRInfo);
    }
}

void MapStructHandles(Decoded_VkDisplaySurfaceCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDisplaySurfaceCreateInfoKHR* value = wrapper->decoded_value;

        value->displayMode = handle_mapping::MapHandle<VulkanDisplayModeKHRInfo>(wrapper->displayMode, object_info_table, &VulkanObjectInfoTable::GetVkDisplayModeKHRInfo);
    }
}

void MapStructHandles(Decoded_VkVideoPictureResourceInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkVideoPictureResourceInfoKHR* value = wrapper->decoded_value;

        value->imageViewBinding = handle_mapping::MapHandle<VulkanImageViewInfo>(wrapper->imageViewBinding, object_info_table, &VulkanObjectInfoTable::GetVkImageViewInfo);
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

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetVkDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkVideoSessionParametersCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkVideoSessionParametersCreateInfoKHR* value = wrapper->decoded_value;

        value->videoSessionParametersTemplate = handle_mapping::MapHandle<VulkanVideoSessionParametersKHRInfo>(wrapper->videoSessionParametersTemplate, object_info_table, &VulkanObjectInfoTable::GetVkVideoSessionParametersKHRInfo);

        value->videoSession = handle_mapping::MapHandle<VulkanVideoSessionKHRInfo>(wrapper->videoSession, object_info_table, &VulkanObjectInfoTable::GetVkVideoSessionKHRInfo);
    }
}

void MapStructHandles(Decoded_VkVideoBeginCodingInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkVideoBeginCodingInfoKHR* value = wrapper->decoded_value;

        value->videoSession = handle_mapping::MapHandle<VulkanVideoSessionKHRInfo>(wrapper->videoSession, object_info_table, &VulkanObjectInfoTable::GetVkVideoSessionKHRInfo);

        value->videoSessionParameters = handle_mapping::MapHandle<VulkanVideoSessionParametersKHRInfo>(wrapper->videoSessionParameters, object_info_table, &VulkanObjectInfoTable::GetVkVideoSessionParametersKHRInfo);

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

        value->srcBuffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->srcBuffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);

        MapStructHandles(wrapper->dstPictureResource, object_info_table);

        MapStructArrayHandles<Decoded_VkVideoReferenceSlotInfoKHR>(wrapper->pSetupReferenceSlot->GetMetaStructPointer(), 1, object_info_table);

        MapStructArrayHandles<Decoded_VkVideoReferenceSlotInfoKHR>(wrapper->pReferenceSlots->GetMetaStructPointer(), wrapper->pReferenceSlots->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkRenderingFragmentShadingRateAttachmentInfoKHR* value = wrapper->decoded_value;

        value->imageView = handle_mapping::MapHandle<VulkanImageViewInfo>(wrapper->imageView, object_info_table, &VulkanObjectInfoTable::GetVkImageViewInfo);
    }
}

void MapStructHandles(Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkRenderingFragmentDensityMapAttachmentInfoEXT* value = wrapper->decoded_value;

        value->imageView = handle_mapping::MapHandle<VulkanImageViewInfo>(wrapper->imageView, object_info_table, &VulkanObjectInfoTable::GetVkImageViewInfo);
    }
}

void MapStructHandles(Decoded_VkMemoryGetWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryGetWin32HandleInfoKHR* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetVkDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkMemoryGetFdInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryGetFdInfoKHR* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetVkDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkWin32KeyedMutexAcquireReleaseInfoKHR* value = wrapper->decoded_value;

        value->pAcquireSyncs = handle_mapping::MapHandleArray<VulkanDeviceMemoryInfo>(&wrapper->pAcquireSyncs, object_info_table, &VulkanObjectInfoTable::GetVkDeviceMemoryInfo);

        value->pReleaseSyncs = handle_mapping::MapHandleArray<VulkanDeviceMemoryInfo>(&wrapper->pReleaseSyncs, object_info_table, &VulkanObjectInfoTable::GetVkDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkImportSemaphoreWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImportSemaphoreWin32HandleInfoKHR* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<VulkanSemaphoreInfo>(wrapper->semaphore, object_info_table, &VulkanObjectInfoTable::GetVkSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkSemaphoreGetWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSemaphoreGetWin32HandleInfoKHR* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<VulkanSemaphoreInfo>(wrapper->semaphore, object_info_table, &VulkanObjectInfoTable::GetVkSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkImportSemaphoreFdInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImportSemaphoreFdInfoKHR* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<VulkanSemaphoreInfo>(wrapper->semaphore, object_info_table, &VulkanObjectInfoTable::GetVkSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkSemaphoreGetFdInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSemaphoreGetFdInfoKHR* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<VulkanSemaphoreInfo>(wrapper->semaphore, object_info_table, &VulkanObjectInfoTable::GetVkSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkImportFenceWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImportFenceWin32HandleInfoKHR* value = wrapper->decoded_value;

        value->fence = handle_mapping::MapHandle<VulkanFenceInfo>(wrapper->fence, object_info_table, &VulkanObjectInfoTable::GetVkFenceInfo);
    }
}

void MapStructHandles(Decoded_VkFenceGetWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkFenceGetWin32HandleInfoKHR* value = wrapper->decoded_value;

        value->fence = handle_mapping::MapHandle<VulkanFenceInfo>(wrapper->fence, object_info_table, &VulkanObjectInfoTable::GetVkFenceInfo);
    }
}

void MapStructHandles(Decoded_VkImportFenceFdInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImportFenceFdInfoKHR* value = wrapper->decoded_value;

        value->fence = handle_mapping::MapHandle<VulkanFenceInfo>(wrapper->fence, object_info_table, &VulkanObjectInfoTable::GetVkFenceInfo);
    }
}

void MapStructHandles(Decoded_VkFenceGetFdInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkFenceGetFdInfoKHR* value = wrapper->decoded_value;

        value->fence = handle_mapping::MapHandle<VulkanFenceInfo>(wrapper->fence, object_info_table, &VulkanObjectInfoTable::GetVkFenceInfo);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSurfaceInfo2KHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPhysicalDeviceSurfaceInfo2KHR* value = wrapper->decoded_value;

        value->surface = handle_mapping::MapHandle<VulkanSurfaceKHRInfo>(wrapper->surface, object_info_table, &VulkanObjectInfoTable::GetVkSurfaceKHRInfo);
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

        value->mode = handle_mapping::MapHandle<VulkanDisplayModeKHRInfo>(wrapper->mode, object_info_table, &VulkanObjectInfoTable::GetVkDisplayModeKHRInfo);
    }
}

void MapStructHandles(Decoded_VkPipelineInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineInfoKHR* value = wrapper->decoded_value;

        value->pipeline = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->pipeline, object_info_table, &VulkanObjectInfoTable::GetVkPipelineInfo);
    }
}

void MapStructHandles(Decoded_VkPipelineExecutableInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineExecutableInfoKHR* value = wrapper->decoded_value;

        value->pipeline = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->pipeline, object_info_table, &VulkanObjectInfoTable::GetVkPipelineInfo);
    }
}

void MapStructHandles(Decoded_VkMemoryMapInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryMapInfoKHR* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetVkDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkMemoryUnmapInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryUnmapInfoKHR* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetVkDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkPipelineLibraryCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineLibraryCreateInfoKHR* value = wrapper->decoded_value;

        value->pLibraries = handle_mapping::MapHandleArray<VulkanPipelineInfo>(&wrapper->pLibraries, object_info_table, &VulkanObjectInfoTable::GetVkPipelineInfo);
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

        value->dstBuffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->dstBuffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);

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

        value->videoSessionParameters = handle_mapping::MapHandle<VulkanVideoSessionParametersKHRInfo>(wrapper->videoSessionParameters, object_info_table, &VulkanObjectInfoTable::GetVkVideoSessionParametersKHRInfo);
    }
}

void MapStructHandles(Decoded_VkDeviceImageSubresourceInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkImageCreateInfo>(wrapper->pCreateInfo->GetMetaStructPointer(), 1, object_info_table);
    }
}

void MapStructHandles(Decoded_VkPipelineBinaryCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineBinaryCreateInfoKHR* value = wrapper->decoded_value;

        value->pipeline = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->pipeline, object_info_table, &VulkanObjectInfoTable::GetVkPipelineInfo);
    }
}

void MapStructHandles(Decoded_VkPipelineBinaryInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineBinaryInfoKHR* value = wrapper->decoded_value;

        value->pPipelineBinaries = handle_mapping::MapHandleArray<VulkanPipelineBinaryKHRInfo>(&wrapper->pPipelineBinaries, object_info_table, &VulkanObjectInfoTable::GetVkPipelineBinaryKHRInfo);
    }
}

void MapStructHandles(Decoded_VkReleaseCapturedPipelineDataInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkReleaseCapturedPipelineDataInfoKHR* value = wrapper->decoded_value;

        value->pipeline = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->pipeline, object_info_table, &VulkanObjectInfoTable::GetVkPipelineInfo);
    }
}

void MapStructHandles(Decoded_VkPipelineBinaryDataInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineBinaryDataInfoKHR* value = wrapper->decoded_value;

        value->pipelineBinary = handle_mapping::MapHandle<VulkanPipelineBinaryKHRInfo>(wrapper->pipelineBinary, object_info_table, &VulkanObjectInfoTable::GetVkPipelineBinaryKHRInfo);
    }
}

void MapStructHandles(Decoded_VkPipelineBinaryHandlesInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineBinaryHandlesInfoKHR* value = wrapper->decoded_value;

        value->pPipelineBinaries = handle_mapping::MapHandleArray<VulkanPipelineBinaryKHRInfo>(&wrapper->pPipelineBinaries, object_info_table, &VulkanObjectInfoTable::GetVkPipelineBinaryKHRInfo);
    }
}

void MapStructHandles(Decoded_VkVideoInlineQueryInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkVideoInlineQueryInfoKHR* value = wrapper->decoded_value;

        value->queryPool = handle_mapping::MapHandle<VulkanQueryPoolInfo>(wrapper->queryPool, object_info_table, &VulkanObjectInfoTable::GetVkQueryPoolInfo);
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

        value->layout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->layout, object_info_table, &VulkanObjectInfoTable::GetVkPipelineLayoutInfo);

        value->pDescriptorSets = handle_mapping::MapHandleArray<VulkanDescriptorSetInfo>(&wrapper->pDescriptorSets, object_info_table, &VulkanObjectInfoTable::GetVkDescriptorSetInfo);
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

        value->layout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->layout, object_info_table, &VulkanObjectInfoTable::GetVkPipelineLayoutInfo);
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

        value->layout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->layout, object_info_table, &VulkanObjectInfoTable::GetVkPipelineLayoutInfo);

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

        value->layout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->layout, object_info_table, &VulkanObjectInfoTable::GetVkPipelineLayoutInfo);
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

        value->layout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->layout, object_info_table, &VulkanObjectInfoTable::GetVkPipelineLayoutInfo);
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

void MapStructHandles(Decoded_VkDedicatedAllocationMemoryAllocateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDedicatedAllocationMemoryAllocateInfoNV* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);
    }
}

void MapStructHandles(Decoded_VkImageViewHandleInfoNVX* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImageViewHandleInfoNVX* value = wrapper->decoded_value;

        value->imageView = handle_mapping::MapHandle<VulkanImageViewInfo>(wrapper->imageView, object_info_table, &VulkanObjectInfoTable::GetVkImageViewInfo);

        value->sampler = handle_mapping::MapHandle<VulkanSamplerInfo>(wrapper->sampler, object_info_table, &VulkanObjectInfoTable::GetVkSamplerInfo);
    }
}

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkWin32KeyedMutexAcquireReleaseInfoNV* value = wrapper->decoded_value;

        value->pAcquireSyncs = handle_mapping::MapHandleArray<VulkanDeviceMemoryInfo>(&wrapper->pAcquireSyncs, object_info_table, &VulkanObjectInfoTable::GetVkDeviceMemoryInfo);

        value->pReleaseSyncs = handle_mapping::MapHandleArray<VulkanDeviceMemoryInfo>(&wrapper->pReleaseSyncs, object_info_table, &VulkanObjectInfoTable::GetVkDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkConditionalRenderingBeginInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkConditionalRenderingBeginInfoEXT* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);
    }
}

void MapStructHandles(Decoded_VkDebugUtilsObjectNameInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDebugUtilsObjectNameInfoEXT* value = wrapper->decoded_value;

        value->objectHandle = handle_mapping::MapHandle(wrapper->objectHandle, value->objectType, object_info_table);
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

void MapStructHandles(Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryGetAndroidHardwareBufferInfoANDROID* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetVkDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkShaderModuleValidationCacheCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkShaderModuleValidationCacheCreateInfoEXT* value = wrapper->decoded_value;

        value->validationCache = handle_mapping::MapHandle<VulkanValidationCacheEXTInfo>(wrapper->validationCache, object_info_table, &VulkanObjectInfoTable::GetVkValidationCacheEXTInfo);
    }
}

void MapStructHandles(Decoded_VkRayTracingPipelineCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkRayTracingPipelineCreateInfoNV* value = wrapper->decoded_value;

        MapStructArrayHandles<Decoded_VkPipelineShaderStageCreateInfo>(wrapper->pStages->GetMetaStructPointer(), wrapper->pStages->GetLength(), object_info_table);

        value->layout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->layout, object_info_table, &VulkanObjectInfoTable::GetVkPipelineLayoutInfo);

        value->basePipelineHandle = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->basePipelineHandle, object_info_table, &VulkanObjectInfoTable::GetVkPipelineInfo);
    }
}

void MapStructHandles(Decoded_VkGeometryTrianglesNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGeometryTrianglesNV* value = wrapper->decoded_value;

        value->vertexData = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->vertexData, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);

        value->indexData = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->indexData, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);

        value->transformData = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->transformData, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);
    }
}

void MapStructHandles(Decoded_VkGeometryAABBNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGeometryAABBNV* value = wrapper->decoded_value;

        value->aabbData = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->aabbData, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);
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

        value->accelerationStructure = handle_mapping::MapHandle<VulkanAccelerationStructureNVInfo>(wrapper->accelerationStructure, object_info_table, &VulkanObjectInfoTable::GetVkAccelerationStructureNVInfo);

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetVkDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkWriteDescriptorSetAccelerationStructureNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkWriteDescriptorSetAccelerationStructureNV* value = wrapper->decoded_value;

        value->pAccelerationStructures = handle_mapping::MapHandleArray<VulkanAccelerationStructureNVInfo>(&wrapper->pAccelerationStructures, object_info_table, &VulkanObjectInfoTable::GetVkAccelerationStructureNVInfo);
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureMemoryRequirementsInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkAccelerationStructureMemoryRequirementsInfoNV* value = wrapper->decoded_value;

        value->accelerationStructure = handle_mapping::MapHandle<VulkanAccelerationStructureNVInfo>(wrapper->accelerationStructure, object_info_table, &VulkanObjectInfoTable::GetVkAccelerationStructureNVInfo);
    }
}

void MapStructHandles(Decoded_VkCopyMemoryToImageInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyMemoryToImageInfoEXT* value = wrapper->decoded_value;

        value->dstImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->dstImage, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);
    }
}

void MapStructHandles(Decoded_VkCopyImageToMemoryInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyImageToMemoryInfoEXT* value = wrapper->decoded_value;

        value->srcImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->srcImage, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);
    }
}

void MapStructHandles(Decoded_VkCopyImageToImageInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyImageToImageInfoEXT* value = wrapper->decoded_value;

        value->srcImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->srcImage, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);

        value->dstImage = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->dstImage, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);
    }
}

void MapStructHandles(Decoded_VkHostImageLayoutTransitionInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkHostImageLayoutTransitionInfoEXT* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);
    }
}

void MapStructHandles(Decoded_VkSwapchainPresentFenceInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSwapchainPresentFenceInfoEXT* value = wrapper->decoded_value;

        value->pFences = handle_mapping::MapHandleArray<VulkanFenceInfo>(&wrapper->pFences, object_info_table, &VulkanObjectInfoTable::GetVkFenceInfo);
    }
}

void MapStructHandles(Decoded_VkReleaseSwapchainImagesInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkReleaseSwapchainImagesInfoEXT* value = wrapper->decoded_value;

        value->swapchain = handle_mapping::MapHandle<VulkanSwapchainKHRInfo>(wrapper->swapchain, object_info_table, &VulkanObjectInfoTable::GetVkSwapchainKHRInfo);
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

        MapStructArrayHandles<Decoded_VkGraphicsShaderGroupCreateInfoNV>(wrapper->pGroups->GetMetaStructPointer(), wrapper->pGroups->GetLength(), object_info_table);

        value->pPipelines = handle_mapping::MapHandleArray<VulkanPipelineInfo>(&wrapper->pPipelines, object_info_table, &VulkanObjectInfoTable::GetVkPipelineInfo);
    }
}

void MapStructHandles(Decoded_VkIndirectCommandsStreamNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkIndirectCommandsStreamNV* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);
    }
}

void MapStructHandles(Decoded_VkIndirectCommandsLayoutTokenNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkIndirectCommandsLayoutTokenNV* value = wrapper->decoded_value;

        value->pushconstantPipelineLayout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->pushconstantPipelineLayout, object_info_table, &VulkanObjectInfoTable::GetVkPipelineLayoutInfo);
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

        value->pipeline = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->pipeline, object_info_table, &VulkanObjectInfoTable::GetVkPipelineInfo);

        value->indirectCommandsLayout = handle_mapping::MapHandle<VulkanIndirectCommandsLayoutNVInfo>(wrapper->indirectCommandsLayout, object_info_table, &VulkanObjectInfoTable::GetVkIndirectCommandsLayoutNVInfo);

        MapStructArrayHandles<Decoded_VkIndirectCommandsStreamNV>(wrapper->pStreams->GetMetaStructPointer(), wrapper->pStreams->GetLength(), object_info_table);

        value->preprocessBuffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->preprocessBuffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);

        value->sequencesCountBuffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->sequencesCountBuffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);

        value->sequencesIndexBuffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->sequencesIndexBuffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);
    }
}

void MapStructHandles(Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGeneratedCommandsMemoryRequirementsInfoNV* value = wrapper->decoded_value;

        value->pipeline = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->pipeline, object_info_table, &VulkanObjectInfoTable::GetVkPipelineInfo);

        value->indirectCommandsLayout = handle_mapping::MapHandle<VulkanIndirectCommandsLayoutNVInfo>(wrapper->indirectCommandsLayout, object_info_table, &VulkanObjectInfoTable::GetVkIndirectCommandsLayoutNVInfo);
    }
}

void MapStructHandles(Decoded_VkMemoryGetZirconHandleInfoFUCHSIA* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryGetZirconHandleInfoFUCHSIA* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetVkDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkImportSemaphoreZirconHandleInfoFUCHSIA* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<VulkanSemaphoreInfo>(wrapper->semaphore, object_info_table, &VulkanObjectInfoTable::GetVkSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkSemaphoreGetZirconHandleInfoFUCHSIA* value = wrapper->decoded_value;

        value->semaphore = handle_mapping::MapHandle<VulkanSemaphoreInfo>(wrapper->semaphore, object_info_table, &VulkanObjectInfoTable::GetVkSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkMemoryGetRemoteAddressInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMemoryGetRemoteAddressInfoNV* value = wrapper->decoded_value;

        value->memory = handle_mapping::MapHandle<VulkanDeviceMemoryInfo>(wrapper->memory, object_info_table, &VulkanObjectInfoTable::GetVkDeviceMemoryInfo);
    }
}

void MapStructHandles(Decoded_VkFrameBoundaryEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkFrameBoundaryEXT* value = wrapper->decoded_value;

        value->pImages = handle_mapping::MapHandleArray<VulkanImageInfo>(&wrapper->pImages, object_info_table, &VulkanObjectInfoTable::GetVkImageInfo);

        value->pBuffers = handle_mapping::MapHandleArray<VulkanBufferInfo>(&wrapper->pBuffers, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);
    }
}

void MapStructHandles(Decoded_VkMicromapBuildInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMicromapBuildInfoEXT* value = wrapper->decoded_value;

        value->dstMicromap = handle_mapping::MapHandle<VulkanMicromapEXTInfo>(wrapper->dstMicromap, object_info_table, &VulkanObjectInfoTable::GetVkMicromapEXTInfo);
    }
}

void MapStructHandles(Decoded_VkMicromapCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkMicromapCreateInfoEXT* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);
    }
}

void MapStructHandles(Decoded_VkCopyMicromapToMemoryInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyMicromapToMemoryInfoEXT* value = wrapper->decoded_value;

        value->src = handle_mapping::MapHandle<VulkanMicromapEXTInfo>(wrapper->src, object_info_table, &VulkanObjectInfoTable::GetVkMicromapEXTInfo);
    }
}

void MapStructHandles(Decoded_VkCopyMemoryToMicromapInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyMemoryToMicromapInfoEXT* value = wrapper->decoded_value;

        value->dst = handle_mapping::MapHandle<VulkanMicromapEXTInfo>(wrapper->dst, object_info_table, &VulkanObjectInfoTable::GetVkMicromapEXTInfo);
    }
}

void MapStructHandles(Decoded_VkCopyMicromapInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyMicromapInfoEXT* value = wrapper->decoded_value;

        value->src = handle_mapping::MapHandle<VulkanMicromapEXTInfo>(wrapper->src, object_info_table, &VulkanObjectInfoTable::GetVkMicromapEXTInfo);

        value->dst = handle_mapping::MapHandle<VulkanMicromapEXTInfo>(wrapper->dst, object_info_table, &VulkanObjectInfoTable::GetVkMicromapEXTInfo);
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkAccelerationStructureTrianglesOpacityMicromapEXT* value = wrapper->decoded_value;

        value->micromap = handle_mapping::MapHandle<VulkanMicromapEXTInfo>(wrapper->micromap, object_info_table, &VulkanObjectInfoTable::GetVkMicromapEXTInfo);
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureTrianglesDisplacementMicromapNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkAccelerationStructureTrianglesDisplacementMicromapNV* value = wrapper->decoded_value;

        value->micromap = handle_mapping::MapHandle<VulkanMicromapEXTInfo>(wrapper->micromap, object_info_table, &VulkanObjectInfoTable::GetVkMicromapEXTInfo);
    }
}

void MapStructHandles(Decoded_VkDescriptorSetBindingReferenceVALVE* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDescriptorSetBindingReferenceVALVE* value = wrapper->decoded_value;

        value->descriptorSetLayout = handle_mapping::MapHandle<VulkanDescriptorSetLayoutInfo>(wrapper->descriptorSetLayout, object_info_table, &VulkanObjectInfoTable::GetVkDescriptorSetLayoutInfo);
    }
}

void MapStructHandles(Decoded_VkRenderPassStripeSubmitInfoARM* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkSemaphoreSubmitInfo>(wrapper->pStripeSemaphoreInfos->GetMetaStructPointer(), wrapper->pStripeSemaphoreInfos->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkPipelineIndirectDeviceAddressInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkPipelineIndirectDeviceAddressInfoNV* value = wrapper->decoded_value;

        value->pipeline = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->pipeline, object_info_table, &VulkanObjectInfoTable::GetVkPipelineInfo);
    }
}

void MapStructHandles(Decoded_VkShaderCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkShaderCreateInfoEXT* value = wrapper->decoded_value;

        value->pSetLayouts = handle_mapping::MapHandleArray<VulkanDescriptorSetLayoutInfo>(&wrapper->pSetLayouts, object_info_table, &VulkanObjectInfoTable::GetVkDescriptorSetLayoutInfo);
    }
}

void MapStructHandles(Decoded_VkLatencySleepInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkLatencySleepInfoNV* value = wrapper->decoded_value;

        value->signalSemaphore = handle_mapping::MapHandle<VulkanSemaphoreInfo>(wrapper->signalSemaphore, object_info_table, &VulkanObjectInfoTable::GetVkSemaphoreInfo);
    }
}

void MapStructHandles(Decoded_VkGeneratedCommandsMemoryRequirementsInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGeneratedCommandsMemoryRequirementsInfoEXT* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->indirectExecutionSet = handle_mapping::MapHandle<VulkanIndirectExecutionSetEXTInfo>(wrapper->indirectExecutionSet, object_info_table, &VulkanObjectInfoTable::GetVkIndirectExecutionSetEXTInfo);

        value->indirectCommandsLayout = handle_mapping::MapHandle<VulkanIndirectCommandsLayoutEXTInfo>(wrapper->indirectCommandsLayout, object_info_table, &VulkanObjectInfoTable::GetVkIndirectCommandsLayoutEXTInfo);
    }
}

void MapStructHandles(Decoded_VkIndirectExecutionSetPipelineInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkIndirectExecutionSetPipelineInfoEXT* value = wrapper->decoded_value;

        value->initialPipeline = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->initialPipeline, object_info_table, &VulkanObjectInfoTable::GetVkPipelineInfo);
    }
}

void MapStructHandles(Decoded_VkIndirectExecutionSetShaderLayoutInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkIndirectExecutionSetShaderLayoutInfoEXT* value = wrapper->decoded_value;

        value->pSetLayouts = handle_mapping::MapHandleArray<VulkanDescriptorSetLayoutInfo>(&wrapper->pSetLayouts, object_info_table, &VulkanObjectInfoTable::GetVkDescriptorSetLayoutInfo);
    }
}

void MapStructHandles(Decoded_VkIndirectExecutionSetShaderInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkIndirectExecutionSetShaderInfoEXT* value = wrapper->decoded_value;

        value->pInitialShaders = handle_mapping::MapHandleArray<VulkanShaderEXTInfo>(&wrapper->pInitialShaders, object_info_table, &VulkanObjectInfoTable::GetVkShaderEXTInfo);

        MapStructArrayHandles<Decoded_VkIndirectExecutionSetShaderLayoutInfoEXT>(wrapper->pSetLayoutInfos->GetMetaStructPointer(), wrapper->pSetLayoutInfos->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_VkGeneratedCommandsInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGeneratedCommandsInfoEXT* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->indirectExecutionSet = handle_mapping::MapHandle<VulkanIndirectExecutionSetEXTInfo>(wrapper->indirectExecutionSet, object_info_table, &VulkanObjectInfoTable::GetVkIndirectExecutionSetEXTInfo);

        value->indirectCommandsLayout = handle_mapping::MapHandle<VulkanIndirectCommandsLayoutEXTInfo>(wrapper->indirectCommandsLayout, object_info_table, &VulkanObjectInfoTable::GetVkIndirectCommandsLayoutEXTInfo);
    }
}

void MapStructHandles(Decoded_VkWriteIndirectExecutionSetPipelineEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkWriteIndirectExecutionSetPipelineEXT* value = wrapper->decoded_value;

        value->pipeline = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->pipeline, object_info_table, &VulkanObjectInfoTable::GetVkPipelineInfo);
    }
}

void MapStructHandles(Decoded_VkIndirectCommandsLayoutCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkIndirectCommandsLayoutCreateInfoEXT* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        value->pipelineLayout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->pipelineLayout, object_info_table, &VulkanObjectInfoTable::GetVkPipelineLayoutInfo);
    }
}

void MapStructHandles(Decoded_VkGeneratedCommandsPipelineInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGeneratedCommandsPipelineInfoEXT* value = wrapper->decoded_value;

        value->pipeline = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->pipeline, object_info_table, &VulkanObjectInfoTable::GetVkPipelineInfo);
    }
}

void MapStructHandles(Decoded_VkGeneratedCommandsShaderInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkGeneratedCommandsShaderInfoEXT* value = wrapper->decoded_value;

        value->pShaders = handle_mapping::MapHandleArray<VulkanShaderEXTInfo>(&wrapper->pShaders, object_info_table, &VulkanObjectInfoTable::GetVkShaderEXTInfo);
    }
}

void MapStructHandles(Decoded_VkWriteIndirectExecutionSetShaderEXT* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkWriteIndirectExecutionSetShaderEXT* value = wrapper->decoded_value;

        value->shader = handle_mapping::MapHandle<VulkanShaderEXTInfo>(wrapper->shader, object_info_table, &VulkanObjectInfoTable::GetVkShaderEXTInfo);
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

void MapStructHandles(Decoded_VkAccelerationStructureCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkAccelerationStructureCreateInfoKHR* value = wrapper->decoded_value;

        value->buffer = handle_mapping::MapHandle<VulkanBufferInfo>(wrapper->buffer, object_info_table, &VulkanObjectInfoTable::GetVkBufferInfo);
    }
}

void MapStructHandles(Decoded_VkWriteDescriptorSetAccelerationStructureKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkWriteDescriptorSetAccelerationStructureKHR* value = wrapper->decoded_value;

        value->pAccelerationStructures = handle_mapping::MapHandleArray<VulkanAccelerationStructureKHRInfo>(&wrapper->pAccelerationStructures, object_info_table, &VulkanObjectInfoTable::GetVkAccelerationStructureKHRInfo);
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureDeviceAddressInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkAccelerationStructureDeviceAddressInfoKHR* value = wrapper->decoded_value;

        value->accelerationStructure = handle_mapping::MapHandle<VulkanAccelerationStructureKHRInfo>(wrapper->accelerationStructure, object_info_table, &VulkanObjectInfoTable::GetVkAccelerationStructureKHRInfo);
    }
}

void MapStructHandles(Decoded_VkCopyAccelerationStructureToMemoryInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyAccelerationStructureToMemoryInfoKHR* value = wrapper->decoded_value;

        value->src = handle_mapping::MapHandle<VulkanAccelerationStructureKHRInfo>(wrapper->src, object_info_table, &VulkanObjectInfoTable::GetVkAccelerationStructureKHRInfo);
    }
}

void MapStructHandles(Decoded_VkCopyMemoryToAccelerationStructureInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyMemoryToAccelerationStructureInfoKHR* value = wrapper->decoded_value;

        value->dst = handle_mapping::MapHandle<VulkanAccelerationStructureKHRInfo>(wrapper->dst, object_info_table, &VulkanObjectInfoTable::GetVkAccelerationStructureKHRInfo);
    }
}

void MapStructHandles(Decoded_VkCopyAccelerationStructureInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkCopyAccelerationStructureInfoKHR* value = wrapper->decoded_value;

        value->src = handle_mapping::MapHandle<VulkanAccelerationStructureKHRInfo>(wrapper->src, object_info_table, &VulkanObjectInfoTable::GetVkAccelerationStructureKHRInfo);

        value->dst = handle_mapping::MapHandle<VulkanAccelerationStructureKHRInfo>(wrapper->dst, object_info_table, &VulkanObjectInfoTable::GetVkAccelerationStructureKHRInfo);
    }
}

void MapStructHandles(Decoded_VkRayTracingPipelineCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkRayTracingPipelineCreateInfoKHR* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);
        }

        MapStructArrayHandles<Decoded_VkPipelineShaderStageCreateInfo>(wrapper->pStages->GetMetaStructPointer(), wrapper->pStages->GetLength(), object_info_table);

        MapStructArrayHandles<Decoded_VkPipelineLibraryCreateInfoKHR>(wrapper->pLibraryInfo->GetMetaStructPointer(), 1, object_info_table);

        value->layout = handle_mapping::MapHandle<VulkanPipelineLayoutInfo>(wrapper->layout, object_info_table, &VulkanObjectInfoTable::GetVkPipelineLayoutInfo);

        value->basePipelineHandle = handle_mapping::MapHandle<VulkanPipelineInfo>(wrapper->basePipelineHandle, object_info_table, &VulkanObjectInfoTable::GetVkPipelineInfo);
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
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryDedicatedAllocateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceGroupDeviceCreateInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkSamplerYcbcrConversionInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassAttachmentBeginInfo*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkImageSwapchainCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkBindImageMemorySwapchainInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineLibraryCreateInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkPipelineBinaryInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkVideoInlineQueryInfoKHR*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkDedicatedAllocationMemoryAllocateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkShaderModuleValidationCacheCreateInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkWriteDescriptorSetAccelerationStructureNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkSwapchainPresentFenceInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkFrameBoundaryEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkAccelerationStructureTrianglesDisplacementMicromapNV*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM:
            MapStructHandles(reinterpret_cast<Decoded_VkRenderPassStripeSubmitInfoARM*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_PIPELINE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkGeneratedCommandsPipelineInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_SHADER_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkGeneratedCommandsShaderInfoEXT*>(wrapper), object_info_table);
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkWriteDescriptorSetAccelerationStructureKHR*>(wrapper), object_info_table);
            break;
        }
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_VkPhysicalDeviceGroupProperties* id_wrapper, const VkPhysicalDeviceGroupProperties* handle_struct, VulkanObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        handle_mapping::AddHandleArray<VulkanPhysicalDeviceInfo>(parent_id, id_wrapper->physicalDevices.GetPointer(), id_wrapper->physicalDevices.GetLength(), handle_struct->physicalDevices, handle_struct->physicalDeviceCount, object_info_table, &VulkanObjectInfoTable::AddVkPhysicalDeviceInfo);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayPropertiesKHR* id_wrapper, const VkDisplayPropertiesKHR* handle_struct, VulkanObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        handle_mapping::AddHandle<VulkanDisplayKHRInfo>(parent_id, id_wrapper->display, handle_struct->display, object_info_table, &VulkanObjectInfoTable::AddVkDisplayKHRInfo);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayPlanePropertiesKHR* id_wrapper, const VkDisplayPlanePropertiesKHR* handle_struct, VulkanObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        handle_mapping::AddHandle<VulkanDisplayKHRInfo>(parent_id, id_wrapper->currentDisplay, handle_struct->currentDisplay, object_info_table, &VulkanObjectInfoTable::AddVkDisplayKHRInfo);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayModePropertiesKHR* id_wrapper, const VkDisplayModePropertiesKHR* handle_struct, VulkanObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        handle_mapping::AddHandle<VulkanDisplayModeKHRInfo>(parent_id, id_wrapper->displayMode, handle_struct->displayMode, object_info_table, &VulkanObjectInfoTable::AddVkDisplayModeKHRInfo);
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

void AddStructHandles(format::HandleId parent_id, const Decoded_VkPipelineBinaryHandlesInfoKHR* id_wrapper, const VkPipelineBinaryHandlesInfoKHR* handle_struct, VulkanObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        handle_mapping::AddHandleArray<VulkanPipelineBinaryKHRInfo>(parent_id, id_wrapper->pPipelineBinaries.GetPointer(), id_wrapper->pPipelineBinaries.GetLength(), handle_struct->pPipelineBinaries, handle_struct->pipelineBinaryCount, object_info_table, &VulkanObjectInfoTable::AddVkPipelineBinaryKHRInfo);
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
