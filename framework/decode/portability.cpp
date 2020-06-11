/*
** Copyright (c) 2020 LunarG, Inc.
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

#include "decode/portability.h"

#include <cassert>
#include <limits>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(portability)

// Minimum heap size to use when checking for memory type compatibility without comparing capture and replay heap
// sizes, to prevent invalid mappings from iGPU DEVICE_LOCAL|HOST_VISIBLE types to the special 256MB
// DEVICE_LOCAL|HOST_VISIBLE heaps provided by some dGPUs.
const VkDeviceSize kMinHeapSize  = 0x40000000; // 1 GB
const uint32_t     kInvalidIndex = std::numeric_limits<uint32_t>::max();

static uint32_t FindMemoryTypeMatch(VkMemoryPropertyFlags                   capture_flags,
                                    uint32_t                                capture_occurrence,
                                    VkDeviceSize                            capture_heap_size,
                                    const VkPhysicalDeviceMemoryProperties& replay_props,
                                    bool                                    exact_flags_match,
                                    bool                                    check_heap_sizes)
{
    uint32_t current_match      = kInvalidIndex;
    uint32_t current_occurrence = 0;

    for (uint32_t i = 0; i < replay_props.memoryTypeCount; ++i)
    {
        bool compatible_flags = false;
        bool compatible_heaps = false;

        if (exact_flags_match)
        {
            if (capture_flags == replay_props.memoryTypes[i].propertyFlags)
            {
                compatible_flags = true;
            }
        }
        else
        {
            if ((capture_flags & replay_props.memoryTypes[i].propertyFlags) == capture_flags)
            {
                compatible_flags = true;
            }
        }

        uint32_t replay_heap_index = replay_props.memoryTypes[i].heapIndex;

        if (check_heap_sizes)
        {
            if (replay_props.memoryHeaps[replay_heap_index].size >= capture_heap_size)
            {
                compatible_heaps = true;
            }
        }
        else
        {
            // When not comparing capture and replay heap sizes, enforce a minimum heap size to prevent invalid mappings
            // from iGPU DEVICE_LOCAL|HOST_VISIBLE types to dGPU 256MB DEVICE_LOCAL|HOST_VISIBLE heaps, unless the
            // capture heap size was also smaller than the min heap size (e.g. if the capture heap is the 256MB heap,
            // allow it to map to a 256MB replay heap).
            if ((replay_props.memoryHeaps[replay_heap_index].size >= kMinHeapSize) ||
                (capture_heap_size <= kMinHeapSize))
            {
                compatible_heaps = true;
            }
        }

        if (compatible_flags && compatible_heaps)
        {
            ++current_occurrence;

            if (capture_occurrence == current_occurrence)
            {
                return i;
            }
            else
            {
                // Continue looking for an index with matching property flags and occurrence count.  Checking for a
                // matching occurrence count will provide one-to-one mappings when the capture and replay memory
                // properties are the same.
                current_match = i;
            }
        }
    }

    return current_match;
}

// Check for multiple occurences of memory types with the same property flags, returning the occurence number for the
// specified index.
static uint32_t GetMemoryTypeOccurence(uint32_t index, const VkPhysicalDeviceMemoryProperties& props)
{
    assert(index < props.memoryTypeCount);

    uint32_t occurrence = 1;

    for (uint32_t i = 0; i < index; ++i)
    {
        if (props.memoryTypes[index].propertyFlags == props.memoryTypes[i].propertyFlags)
        {
            ++occurrence;
        }
    }

    return occurrence;
}

bool CheckMemoryTypeCompatibility(const VkPhysicalDeviceMemoryProperties& capture_props,
                                  const VkPhysicalDeviceMemoryProperties& replay_props,
                                  bool                                    ignore_heap_sizes)
{
    if ((capture_props.memoryTypeCount == 0) || (capture_props.memoryTypeCount > replay_props.memoryTypeCount))
    {
        return false;
    }

    for (uint32_t i = 0; i < capture_props.memoryTypeCount; ++i)
    {
        VkMemoryPropertyFlags capture_flags = capture_props.memoryTypes[i].propertyFlags;

        if ((capture_flags & replay_props.memoryTypes[i].propertyFlags) != capture_flags)
        {
            return false;
        }

        if (!ignore_heap_sizes)
        {
            uint32_t capture_heap_index = capture_props.memoryTypes[i].heapIndex;
            uint32_t replay_heap_index  = replay_props.memoryTypes[i].heapIndex;

            if (capture_props.memoryHeaps[capture_heap_index].size > replay_props.memoryHeaps[replay_heap_index].size)
            {
                return false;
            }
        }
    }

    return true;
}

uint32_t FindCompatibleMemoryType(uint32_t                                capture_index,
                                  const VkPhysicalDeviceMemoryProperties& capture_props,
                                  const VkPhysicalDeviceMemoryProperties& replay_props)
{
    VkMemoryPropertyFlags capture_flags      = capture_props.memoryTypes[capture_index].propertyFlags;
    uint32_t              capture_heap_index = capture_props.memoryTypes[capture_index].heapIndex;
    VkDeviceSize          capture_heap_size  = capture_props.memoryHeaps[capture_heap_index].size;

    uint32_t index              = kInvalidIndex;
    uint32_t capture_occurrence = GetMemoryTypeOccurence(capture_index, capture_props);
    bool     do_checks          = true;

    while (do_checks)
    {
        // Check for exact property match with replay heap size greater than or equal to capture heap size.
        index = FindMemoryTypeMatch(capture_flags, capture_occurrence, capture_heap_size, replay_props, true, true);
        if (index != kInvalidIndex)
        {
            return index;
        }

        // Check for property superset with replay heap size greater than or equal to capture heap size.
        index = FindMemoryTypeMatch(capture_flags, capture_occurrence, capture_heap_size, replay_props, false, true);
        if (index != kInvalidIndex)
        {
            return index;
        }

        // Check for exact property match, allowing replay heap sizes to be smaller than capture heap sizes.
        index = FindMemoryTypeMatch(capture_flags, capture_occurrence, capture_heap_size, replay_props, true, false);
        if (index != kInvalidIndex)
        {
            return index;
        }

        // Check for property superset, allowing replay heap sizes to be smaller than capture heap sizes.
        index = FindMemoryTypeMatch(capture_flags, capture_occurrence, capture_heap_size, replay_props, false, false);
        if (index != kInvalidIndex)
        {
            return index;
        }

        // If present, remove AMD device property flag bits and try again with just the core property flags.
        VkMemoryPropertyFlags new_flags =
            capture_flags & ~(VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD | VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD);

        if ((new_flags == 0) || (new_flags == capture_flags))
        {
            do_checks = false;
        }
        else
        {
            capture_flags = new_flags;
        }
    }

    // If a match has not been found, try adjusting the memory property flags and try again.
    const VkMemoryPropertyFlags kDeviceAndHost =
        VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT | VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT;

    VkMemoryPropertyFlags new_flags = capture_flags;

    if (new_flags == 0)
    {
        // Attempt to map memory types that report no flags to host memory.
        new_flags = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
    }
    else if ((new_flags & kDeviceAndHost) == kDeviceAndHost)
    {
        // The replay device may not have a memory type that is both device local and host visible, so we default to
        // just the host visible type.
        new_flags &= ~VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;
    }

    // If the flags are unchanged, there is nothing else to do.
    if (new_flags != capture_flags)
    {
        // Check for exact property match with compatible heap size.
        index = FindMemoryTypeMatch(new_flags, capture_occurrence, capture_heap_size, replay_props, true, true);
        if (index != kInvalidIndex)
        {
            return index;
        }

        // Check for property superset with compatible heap size.
        index = FindMemoryTypeMatch(new_flags, capture_occurrence, capture_heap_size, replay_props, false, true);
        if (index != kInvalidIndex)
        {
            return index;
        }

        // Check for exact property match.
        index = FindMemoryTypeMatch(new_flags, capture_occurrence, capture_heap_size, replay_props, true, false);
        if (index != kInvalidIndex)
        {
            return index;
        }

        // Check for property superset.
        index = FindMemoryTypeMatch(new_flags, capture_occurrence, capture_heap_size, replay_props, false, false);
        if (index != kInvalidIndex)
        {
            return index;
        }
    }

    return index;
}

bool CheckMemoryTypeIndexValidity(std::vector<uint32_t> indexes)
{
    if (indexes.empty())
    {
        return false;
    }

    for (auto index : indexes)
    {
        if (index == kInvalidIndex)
        {
            return false;
        }
    }

    return true;
}

GFXRECON_END_NAMESPACE(portability)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
