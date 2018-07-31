/*
** Copyright (c) 2018 LunarG, Inc.
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

#include "util/passthrough_memory_allocator.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(util)

VkResult PassthroughMemoryAllocator::AllocateMemory(
    VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, GraphicsMemory** ppMemory, const VkPhysicalDeviceMemoryProperties* pMemoryProperties)
{
    VkMemoryType memory_type = pMemoryProperties->memoryTypes[pAllocateInfo->memoryTypeIndex];

    *ppMemory = new GraphicsMemory()
    (*ppMemory)->allocation_size = pAllocateInfo->allocationSize;
    (*ppMemory)->memory_type = memory_type;
    
    return vkAllocateMemory(device, pAllocateInfo, nullptr, pMemory->pDeviceMemory);
}

VkResult PassthroughMemoryAllocator::FreeMemory(VkDevice device, GraphicsMemory* const pMemory)
{
    return vkFreeMemory(device, *pMemory->pDeviceMemory, nullptr);
}

VkResult PassthroughMemoryAllocator::BindBufferMemory(
    VkDevice device, VkBuffer buffer, GraphicsMemory* const pMemory, VkDeviceSize memoryOffset)
{
    return vkBindBufferMemory(device, buffer, *pMemory->pDeviceMemory, memoryOffset);
}

VkResult PassthroughMemoryAllocator::BindImageMemory(
    VkDevice device, VkImage image, GraphicsMemory* const pMemory, VkDeviceSize memoryOffset)
{
    return vkBindImageMemory(device, image, *pMemory->pDeviceMemory, memoryOffset);
}

VkResult PassthroughMemoryAllocator::MapMemory(
    VkDevice device, GraphicsMemory* const pMemory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void ** ppData)
{
    return vkMapMemory(device, *pMemory->pDeviceMemory, offset, size, flags, ppData);
}

VkResult PassthroughMemoryAllocator::UnmapMemory(VkDevice device, GraphicsMemory* const pMemory)
{
    return vkUnmapMemory(device, *pMemory->pDeviceMemory);
}

VkResult PassthroughMemoryAllocator::FlushMappedMemoryRange(
    VkDevice device, GraphicsMemory* const pMemory, VkDeviceSize offset, VkDeviceSize size)
{
    VkMappedMemoryRange range
    {
        .sType = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE,
        .pNext = nullptr,
        .memory = *pMemory->pDeviceMemory,
        .offset = offset,
        .size = size
    };

    return vkFlushMappedMemoryRanges(device, 1, &range);
}

VkResult PassthroughMemoryAllocator::InvalidateMappedMemoryRange(
    VkDevice device, GraphicsMemory* const pMemory, VkDeviceSize offset, VkDeviceSize size)
{
    VkMappedMemoryRange range
    {
        .sType = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE,
        .pNext = nullptr,
        .memory = *pMemory->pDeviceMemory,
        .offset = offset,
        .size = size
    };

    return vkInvalidateMappedMemoryRanges(device, 1, &range);
}

BRIMSTONE_END_NAMESPACE(util)
BRIMSTONE_END_NAMESPACE(brimstone)
