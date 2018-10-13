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

#ifndef BRIMSTONE_ENCODE_MEMORY_TRACKER_H
#define BRIMSTONE_ENCODE_MEMORY_TRACKER_H

#include <functional>
#include <unordered_map>

#include "vulkan/vulkan.h"

#include "util/defines.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(encode)

class MemoryTracker
{
  public:
    struct EntryInfo
    {
        EntryInfo(VkDeviceMemory memory, VkMemoryPropertyFlags flags, VkDeviceSize size) :
            memory_handle(memory), property_flags(flags), allocation_size(size), mapped_offset(0), mapped_size(0),
            data(nullptr)
        {}
        VkDeviceMemory        memory_handle;
        VkMemoryPropertyFlags property_flags;
        VkDeviceSize          allocation_size;
        VkDeviceSize          mapped_offset;
        VkDeviceSize          mapped_size;
        void*                 data;
    };

  public:
    MemoryTracker() {}

    ~MemoryTracker() {}

    void AddEntry(VkDeviceMemory memory, VkMemoryPropertyFlags flags, VkDeviceSize size);

    const EntryInfo* MapEntry(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, void* data);

    void UnmapEntry(VkDeviceMemory memory);

    void RemoveEntry(VkDeviceMemory memory);

    const EntryInfo* GetEntryInfo(VkDeviceMemory memory) const;

    void VisitEntries(std::function<void(VkDeviceMemory, const EntryInfo&)> visit);

  private:
    std::unordered_map<VkDeviceMemory, EntryInfo> mapped_memory_;
};

BRIMSTONE_END_NAMESPACE(encode)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_ENCODE_MEMORY_TRACKER_H
