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
#include "util/logging.h"
#include <cstdint>

#define XXH_STATIC_LINKING_ONLY
#define XXH_IMPLEMENTATION
#include <xxHash/xxhash.h>

#include <algorithm>
#include <cinttypes>
#include <cstddef>
#include <limits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

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

    auto entry = memory_info_.find(memory_id);
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

        if (!exposed_touched.Empty())
        {
            EmitMappedIntersections(info_entry, exposed_touched, handle_modified);
        }
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

    if (offset < memory_info.mapped_offset || size > memory_info.mapped_size ||
        (offset - memory_info.mapped_offset) > (memory_info.mapped_size - size))
    {
        return;
    }

    if (offset >= std::numeric_limits<size_t>::max() || size >= std::numeric_limits<size_t>::max())
    {
        GFXRECON_LOG_ERROR(
            "Smart memory tracking range is too large to process: offset=%" PRIu64 ", size=%" PRIu64, offset, size);
        return;
    }

    const size_t range_size        = static_cast<size_t>(size);
    const size_t offset_in_mapping = static_cast<size_t>(offset - memory_info.mapped_offset);

    const uint8_t* data = memory_info.mapped_data + offset_in_mapping;

    size_t total_blocks    = range_size >> kBlockSizePotShift;
    size_t last_block_size = range_size & (kBlockSize - 1);

    if (last_block_size != 0)
    {
        ++total_blocks;
    }
    else
    {
        last_block_size = kBlockSize;
    }

    auto [entry, inserted]      = memory_info.valid_range_hashes.try_emplace(offset, total_blocks, last_block_size);
    MemoryInfo::RangeHashes& rh = entry->second;
    if (inserted || (rh.total_blocks != total_blocks || rh.last_block_size != last_block_size))
    {
        rh.total_blocks    = total_blocks;
        rh.last_block_size = last_block_size;
        rh.previous_hashes.resize(total_blocks);

        ForEachBlock(rh, [&](size_t block, size_t block_size) {
            const XXH128_hash_t hash  = XXH3_128bits(data + block * kBlockSize, block_size);
            rh.previous_hashes[block] = { hash.low64, hash.high64 };
        });

        handle_modified(memory_info_entry->first, data, offset_in_mapping, range_size);
    }
    else
    {
        rh.current_hashes.resize(total_blocks);

        ForEachBlock(rh, [&](size_t block, size_t block_size) {
            const XXH128_hash_t hash = XXH3_128bits(data + block * kBlockSize, block_size);
            rh.current_hashes[block] = { hash.low64, hash.high64 };
        });

        bool   active_range = false;
        size_t start_index  = 0;

        for (size_t i = 0; i < total_blocks; ++i)
        {
            if (rh.previous_hashes[i] != rh.current_hashes[i])
            {
                if (!active_range)
                {
                    active_range = true;
                    start_index  = i;
                }
            }
            else
            {
                if (active_range)
                {
                    active_range = false;
                    ProcessActiveRange(
                        memory_info_entry->first, data, offset_in_mapping, rh, start_index, i, handle_modified);
                }
            }
        }

        if (active_range)
        {
            ProcessActiveRange(
                memory_info_entry->first, data, offset_in_mapping, rh, start_index, total_blocks, handle_modified);
        }

        rh.current_hashes.swap(rh.previous_hashes);
    }
}

void VulkanSmartMemoryTracker::ProcessActiveRange(uint64_t                       memory_id,
                                                  const uint8_t*                 data,
                                                  size_t                         offset_in_mapping,
                                                  const MemoryInfo::RangeHashes& range_info,
                                                  size_t                         start_index,
                                                  size_t                         end_index,
                                                  const ModifiedMemoryFunc&      handle_modified)
{
    GFXRECON_ASSERT(end_index > end_index);

    const size_t block_count  = end_index - start_index;
    const size_t block_offset = start_index << kBlockSizePotShift;
    size_t       block_range  = block_count << kBlockSizePotShift;

    if (end_index == range_info.total_blocks)
    {
        // Adjust range for memory ranges that end with a partial block.
        block_range -= kBlockSize - range_info.last_block_size;
    }

    handle_modified(memory_id, data + block_offset, offset_in_mapping + block_offset, block_range);
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
