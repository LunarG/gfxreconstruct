/*
** Copyright (c) 2018 Valve Corporation
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

#ifndef GFXRECON_ENCODE_MEMORY_TRACKER_H
#define GFXRECON_ENCODE_MEMORY_TRACKER_H

#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <functional>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class MemoryTracker
{
  public:
    struct EntryInfo
    {
        EntryInfo(VkDeviceMemory memory, VkMemoryPropertyFlags flags, VkDeviceSize size) :
            memory_handle(memory), property_flags(flags), allocation_size(size), mapped_offset(0), mapped_size(0),
            mapped_memory(nullptr), tracked_memory(nullptr)
        {}
        VkDeviceMemory        memory_handle;
        VkMemoryPropertyFlags property_flags;
        VkDeviceSize          allocation_size;
        VkDeviceSize          mapped_offset;
        VkDeviceSize          mapped_size;
        void*                 mapped_memory;
        void*                 tracked_memory;
    };

  public:
    MemoryTracker() {}

    ~MemoryTracker() {}

    void AddEntry(VkDeviceMemory memory, VkMemoryPropertyFlags flags, VkDeviceSize size);

    // Returns false if memory was already mapped.
    bool MapEntry(
        VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, void* data, MemoryTracker::EntryInfo** info);

    void UnmapEntry(VkDeviceMemory memory);

    void RemoveEntry(VkDeviceMemory memory, bool* is_mapped);

    const EntryInfo* GetEntryInfo(VkDeviceMemory memory) const;

    void VisitEntries(std::function<void(VkDeviceMemory, const EntryInfo&)> visit);

  private:
    std::unordered_map<VkDeviceMemory, EntryInfo> mapped_memory_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_MEMORY_TRACKER_H
