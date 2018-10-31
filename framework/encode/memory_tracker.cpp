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

#include "encode/memory_tracker.h"

#include "util/defines.h"

#include <cassert>

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(encode)

void MemoryTracker::AddEntry(VkDeviceMemory memory, VkMemoryPropertyFlags property_flags, VkDeviceSize allocation_size)
{
    assert(mapped_memory_.find(memory) == mapped_memory_.end());

    mapped_memory_.emplace(std::piecewise_construct,
                           std::forward_as_tuple(memory),
                           std::forward_as_tuple(memory, property_flags, allocation_size));
}

const MemoryTracker::EntryInfo*
MemoryTracker::MapEntry(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, void* data)
{
    assert(mapped_memory_.find(memory) != mapped_memory_.end());

    EntryInfo* result = nullptr;

    auto entry = mapped_memory_.find(memory);
    if (entry != mapped_memory_.end())
    {
        entry->second.mapped_offset = offset;
        entry->second.mapped_size   = (size != VK_WHOLE_SIZE) ? size : (entry->second.allocation_size - offset);
        entry->second.data          = data;
        result                      = &(entry->second);
    }

    return result;
}

void MemoryTracker::UnmapEntry(VkDeviceMemory memory)
{
    assert(mapped_memory_.find(memory) != mapped_memory_.end());

    auto entry = mapped_memory_.find(memory);
    if (entry != mapped_memory_.end())
    {
        entry->second.mapped_offset = 0;
        entry->second.mapped_size   = 0;
        entry->second.data          = nullptr;
    }
}

void MemoryTracker::RemoveEntry(VkDeviceMemory memory)
{
    mapped_memory_.erase(memory);
}

const MemoryTracker::EntryInfo* MemoryTracker::GetEntryInfo(VkDeviceMemory memory) const
{
    assert(mapped_memory_.find(memory) != mapped_memory_.end());

    auto entry = mapped_memory_.find(memory);
    return (entry != mapped_memory_.end()) ? &(entry->second) : nullptr;
}

void MemoryTracker::VisitEntries(std::function<void(VkDeviceMemory, const EntryInfo&)> visit)
{
    for (const auto& entry : mapped_memory_)
    {
        visit(entry.first, entry.second);
    }
}

BRIMSTONE_END_NAMESPACE(encode)
BRIMSTONE_END_NAMESPACE(brimstone)
