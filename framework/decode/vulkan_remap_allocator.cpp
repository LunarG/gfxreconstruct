/*
** Copyright (c) 2020 LunarG, Inc.
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

#include "decode/vulkan_remap_allocator.h"

#include "decode/portability.h"
#include "util/logging.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VkResult VulkanRemapAllocator::Initialize(uint32_t                                api_version,
                                          VkInstance                              instance,
                                          VkPhysicalDevice                        physical_device,
                                          VkDevice                                device,
                                          const std::vector<std::string>&         enabled_device_extensions,
                                          VkPhysicalDeviceType                    capture_device_type,
                                          const VkPhysicalDeviceMemoryProperties& capture_memory_properties,
                                          const VkPhysicalDeviceMemoryProperties& replay_memory_properties,
                                          const Functions&                        functions)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    VulkanDefaultAllocator::Initialize(api_version,
                                       instance,
                                       physical_device,
                                       device,
                                       enabled_device_extensions,
                                       capture_device_type,
                                       capture_memory_properties,
                                       replay_memory_properties,
                                       functions);

    if ((capture_memory_properties.memoryTypeCount == 0) || (replay_memory_properties.memoryTypeCount == 0))
    {
        GFXRECON_LOG_FATAL("Capture file does not contain physical device memory properties and cannot be used with "
                           "memory translation.");
    }
    else if (portability::CheckMemoryTypeCompatibility(capture_memory_properties, replay_memory_properties, false))
    {
        // One-to-one mapping when all memory types match.
        for (uint32_t i = 0; i < replay_memory_properties.memoryTypeCount; ++i)
        {
            index_map_.push_back(i);
        }

        result = VK_SUCCESS;
    }
    else
    {
        index_map_.resize(capture_memory_properties.memoryTypeCount);

        for (uint32_t i = 0; i < capture_memory_properties.memoryTypeCount; ++i)
        {
            index_map_[i] =
                portability::FindCompatibleMemoryType(i, capture_memory_properties, replay_memory_properties);
        }

        if (portability::CheckMemoryTypeIndexValidity(index_map_))
        {
            result = VK_SUCCESS;
        }
        else
        {
            GFXRECON_LOG_FATAL(
                "Failed to find valid memory type mappings for replay when using the \"-m remap\" option.");
            GFXRECON_LOG_FATAL(
                "Try replay with rebind memory translation enabled via the \"-m rebind\" option instead.");
        }
    }

    return result;
}

VkResult VulkanRemapAllocator::AllocateMemory(const VkMemoryAllocateInfo*  allocate_info,
                                              const VkAllocationCallbacks* allocation_callbacks,
                                              format::HandleId             capture_id,
                                              VkDeviceMemory*              memory,
                                              MemoryData*                  allocator_data)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((allocate_info != nullptr) && (allocator_data != nullptr))
    {
        assert(allocate_info->memoryTypeIndex < index_map_.size());

        VkMemoryAllocateInfo replay_allocate_info = *allocate_info;

        replay_allocate_info.memoryTypeIndex = index_map_[allocate_info->memoryTypeIndex];

        result = Allocate(&replay_allocate_info, allocation_callbacks, capture_id, memory, allocator_data);
    }

    return result;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
