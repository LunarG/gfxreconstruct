/*
** Copyright (c) 2026 LunarG, Inc.
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

#include "encode/vulkan_smart_memory_tracker.h"

#include "encode/api_capture_manager.h"
#include "util/logging.h"
#include "util/platform.h"

#include <algorithm>
#include <cinttypes>
#include <cstddef>
#include <cstring>
#include <limits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

constexpr size_t kDiffWordSize = sizeof(uint64_t);

static inline uint64_t LoadDiffWord(const uint8_t* data)
{
    uint64_t word = 0;
    std::memcpy(&word, data, kDiffWordSize);
    return word;
}

static inline void StoreDiffWord(uint8_t* data, uint64_t word)
{
    std::memcpy(data, &word, kDiffWordSize);
}

void VulkanSmartMemoryTracker::TrackMemory(format::HandleId      memory_id,
                                           uint64_t              allocation_size,
                                           VkMemoryPropertyFlags property_flags)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);
    auto&                       info = memory_info_[memory_id];
    info.allocation_size             = allocation_size;
    info.property_flags              = property_flags;
}

void VulkanSmartMemoryTracker::RemoveMemory(format::HandleId memory_id)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);
    memory_info_.erase(memory_id);
}

void VulkanSmartMemoryTracker::MapMemory(format::HandleId memory_id,
                                         const void*      mapped_data,
                                         uint64_t         offset,
                                         uint64_t         size)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);
    auto                        entry = memory_info_.find(memory_id);
    if (entry == memory_info_.end())
    {
        return;
    }

    MemoryInfo& info = entry->second;

    info.mapped_data   = reinterpret_cast<const uint8_t*>(mapped_data);
    info.mapped_offset = offset;
    info.mapped_size   = ClampRangeSize(offset, size, info.allocation_size);

    if ((info.property_flags & VK_MEMORY_PROPERTY_HOST_COHERENT_BIT) == VK_MEMORY_PROPERTY_HOST_COHERENT_BIT)
    {
        info.exposed_ranges.AddRange(offset, info.mapped_size);
    }
}

void VulkanSmartMemoryTracker::UnmapMemory(format::HandleId memory_id)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);
    auto                        entry = memory_info_.find(memory_id);
    if (entry == memory_info_.end())
    {
        return;
    }

    MemoryInfo& info   = entry->second;
    info.mapped_data   = nullptr;
    info.mapped_offset = 0;
    info.mapped_size   = 0;
}

void VulkanSmartMemoryTracker::FlushRange(format::HandleId          memory_id,
                                          uint64_t                  offset,
                                          uint64_t                  size,
                                          const ModifiedMemoryFunc& handle_modified)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);
    auto                        entry = memory_info_.find(memory_id);
    if (entry == memory_info_.end())
    {
        return;
    }

    MemoryInfo& info = entry->second;
    size             = ClampRangeSize(offset, size, info.allocation_size);

    if (size == 0)
    {
        return;
    }

    util::RangeList ranges(offset, size);
    EmitMappedIntersections(entry, ranges, handle_modified);
    info.exposed_ranges.AddRange(offset, size);
}

void VulkanSmartMemoryTracker::FlushMappedMemory(format::HandleId memory_id, const ModifiedMemoryFunc& handle_modified)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);
    auto                        entry = memory_info_.find(memory_id);
    if (entry == memory_info_.end())
    {
        return;
    }

    MemoryInfo& info = entry->second;
    EmitMappedIntersections(entry, info.exposed_ranges, handle_modified);
}

void VulkanSmartMemoryTracker::ProcessSubmit(
    const std::unordered_map<format::HandleId, util::RangeList>& touched_ranges,
    const ModifiedMemoryFunc&                                    handle_modified)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    for (const auto& [memory_id, ranges] : touched_ranges)
    {
        auto info_entry = memory_info_.find(memory_id);
        if (info_entry == memory_info_.end())
        {
            continue;
        }

        MemoryInfo& info = info_entry->second;

        // Non HOST_COHERENT ranges should have already been handled by FlushMappedMemoryRanges
        if ((info.property_flags & VK_MEMORY_PROPERTY_HOST_COHERENT_BIT) != VK_MEMORY_PROPERTY_HOST_COHERENT_BIT)
        {
            continue;
        }

        util::RangeList exposed_touched;
        for (const auto& range : ranges.GetRanges())
        {
            exposed_touched.AddRanges(info.exposed_ranges.Intersect(range.begin, range.Size()));
        }

        EmitMappedIntersections(info_entry, exposed_touched, handle_modified);
    }
}

uint64_t VulkanSmartMemoryTracker::ClampRangeSize(uint64_t offset, uint64_t size, uint64_t limit)
{
    if (offset >= limit)
    {
        return 0;
    }

    if (size == VK_WHOLE_SIZE || size > (limit - offset))
    {
        return limit - offset;
    }

    return size;
}

bool VulkanSmartMemoryTracker::EnsureBaseline(MemoryInfo& memory_info)
{
    if (memory_info.baseline.empty())
    {
        if (memory_info.allocation_size >= std::numeric_limits<size_t>::max())
        {
            GFXRECON_LOG_ERROR("Smart memory tracking cannot allocate a baseline for memory allocation size %" PRIu64,
                               memory_info.allocation_size);
            return false;
        }

        memory_info.baseline.resize(static_cast<size_t>(memory_info.allocation_size), 0);
    }

    return true;
}

void VulkanSmartMemoryTracker::EmitRange(MemoryInfoIterator        memory_info_entry,
                                         uint64_t                  offset,
                                         uint64_t                  size,
                                         const ModifiedMemoryFunc& handle_modified)
{
    GFXRECON_ASSERT(memory_info_entry != memory_info_.end());

    MemoryInfo& memory_info = memory_info_entry->second;
    if (size == 0 || memory_info.mapped_data == nullptr)
    {
        return;
    }

    if (!EnsureBaseline(memory_info))
    {
        return;
    }

    if (offset < memory_info.mapped_offset || size > memory_info.mapped_size ||
        (offset - memory_info.mapped_offset) > (memory_info.mapped_size - size))
    {
        return;
    }

    if (offset > std::numeric_limits<size_t>::max() || size > std::numeric_limits<size_t>::max())
    {
        GFXRECON_LOG_ERROR(
            "Smart memory tracking range is too large to process: offset=%" PRIu64 ", size=%" PRIu64, offset, size);
        return;
    }

    const size_t baseline_offset = static_cast<size_t>(offset);
    const size_t range_size      = static_cast<size_t>(size);
    const size_t mapped_offset   = static_cast<size_t>(offset - memory_info.mapped_offset);

    const uint8_t* data     = memory_info.mapped_data + mapped_offset;
    uint8_t*       baseline = memory_info.baseline.data() + baseline_offset;

    if (!memory_info.baseline_valid_ranges.ContainsRange(offset, size))
    {
        handle_modified(memory_info_entry->first, data, offset - memory_info.mapped_offset, size);
        util::platform::MemoryCopy(baseline, range_size, data, range_size);
        memory_info.baseline_valid_ranges.AddRange(offset, size);
        return;
    }

    const uint64_t relative_base = offset - memory_info.mapped_offset;

    size_t cursor = 0;
    while ((range_size - cursor) >= kDiffWordSize)
    {
        while ((range_size - cursor) >= kDiffWordSize && LoadDiffWord(baseline + cursor) == LoadDiffWord(data + cursor))
        {
            cursor += kDiffWordSize;
        }

        const size_t changed_begin = cursor;

        while ((range_size - cursor) >= kDiffWordSize)
        {
            const uint64_t data_word = LoadDiffWord(data + cursor);
            if (LoadDiffWord(baseline + cursor) == data_word)
            {
                break;
            }

            StoreDiffWord(baseline + cursor, data_word);
            cursor += kDiffWordSize;
        }

        if (cursor > changed_begin)
        {
            const uint64_t relative_offset = relative_base + changed_begin;
            const uint64_t changed_size    = cursor - changed_begin;
            handle_modified(memory_info_entry->first, data + changed_begin, relative_offset, changed_size);
        }
    }

    while (cursor < range_size)
    {
        while (cursor < range_size && baseline[cursor] == data[cursor])
        {
            ++cursor;
        }

        const size_t changed_begin = cursor;

        while (cursor < range_size && baseline[cursor] != data[cursor])
        {
            baseline[cursor] = data[cursor];
            ++cursor;
        }

        if (cursor > changed_begin)
        {
            const uint64_t relative_offset = relative_base + changed_begin;
            const uint64_t changed_size    = cursor - changed_begin;
            handle_modified(memory_info_entry->first, data + changed_begin, relative_offset, changed_size);
        }
    }
}

void VulkanSmartMemoryTracker::EmitMappedIntersections(MemoryInfoIterator        memory_info_entry,
                                                       const util::RangeList&    ranges,
                                                       const ModifiedMemoryFunc& handle_modified)
{
    GFXRECON_ASSERT(memory_info_entry != memory_info_.end());

    MemoryInfo& memory_info = memory_info_entry->second;
    if (memory_info.mapped_data == nullptr || memory_info.mapped_size == 0)
    {
        return;
    }

    const uint64_t mapped_begin = memory_info.mapped_offset;
    const uint64_t mapped_end   = mapped_begin + memory_info.mapped_size;

    for (const auto& range : ranges.GetRanges())
    {
        if (range.end <= mapped_begin || range.begin >= mapped_end)
        {
            continue;
        }

        const uint64_t begin = std::max(range.begin, mapped_begin);
        const uint64_t end   = std::min(range.end, mapped_end);
        EmitRange(memory_info_entry, begin, end - begin, handle_modified);
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
