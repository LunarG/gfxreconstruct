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

#ifndef BRIMSTONE_UTIL_GRAPHICS_MEMORY_ALLOCATOR_H
#define BRIMSTONE_UTIL_GRAPHICS_MEMORY_ALLOCATOR_H

#include <vulkan/vulkan.h>

#include "util/graphics_memory.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(util)

class GraphicsMemoryAllocator
{
public:
    virtual ~GraphicsMemoryAllocator();

    virtual VkResult AllocateMemory(
        VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, GraphicsMemory** ppMemory, const VkPhysicalDeviceMemoryProperties* pMemoryProperties) = 0;

    virtual VkResult FreeMemory(VkDevice device, GraphicsMemory* const pMemory) = 0;
    
    virtual VkResult BindBufferMemory(
        VkDevice device, VkBuffer buffer, GraphicsMemory* const pMemory, VkDeviceSize memoryOffset) = 0;

    virtual VkResult BindImageMemory(
        VkDevice device, VkImage image, GraphicsMemory* const pMemory, VkDeviceSize memoryOffset) = 0;

    virtual VkResult MapMemory(
        VkDevice device, GraphicsMemory* const pMemory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void ** ppData) = 0;

    virtual VkResult UnmapMemory(VkDevice device, GraphicsMemory* const pMemory) = 0;

    virtual VkResult FlushMappedMemoryRange(
        VkDevice device, GraphicsMemory* const pMemory, VkDeviceSize offset, VkDeviceSize size) = 0;

    virtual VkResult InvalidateMappedMemoryRange(
        VkDevice device, GraphicsMemory* const pMemory, VkDeviceSize offset, VkDeviceSize size) = 0;
};

BRIMSTONE_END_NAMESPACE(util)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_UTIL_GRAPHICS_MEMORY_ALLOCATOR_H
