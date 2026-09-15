/*
** Copyright (c) 2026 Valve Corporation
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

#include "hashing_manager.h"
#include "util/logging.h"

#define XXH_STATIC_LINKING_ONLY
#define XXH_IMPLEMENTATION
#include <xxhash.h>

#include <cinttypes>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

HashingManager* HashingManager::instance_             = nullptr;
size_t          HashingManager::block_size_pot_shift_ = 0;

void HashingManager::Create()
{
    instance_ = new HashingManager();
}

void HashingManager::Destroy()
{
    if (instance_ != nullptr)
    {
        delete instance_;
    }
}

HashingManager::HashingManager() : thread_pool_(std::thread::hardware_concurrency())
{
    size_t block          = block_size_;
    block_size_pot_shift_ = 0;

    while (block != 1)
    {
        block >>= 1;
        ++block_size_pot_shift_;
    }
}

void HashingManager::AddTrackedMemory(uint64_t memory_id, void* mapped_memory, size_t mapped_range)
{
    if (!mapped_range)
    {
        return;
    }

    size_t total_pages       = mapped_range >> block_size_pot_shift_;
    size_t last_segment_size = mapped_range & (block_size_ - 1); // mapped_range % system_page_size_

    if (last_segment_size != 0)
    {
        ++total_pages;
    }
    else
    {
        last_segment_size = block_size_;
    }

    std::lock_guard<std::mutex> lock(tracked_memory_lock_);
    auto                        new_entry = memory_info_.emplace(std::piecewise_construct,
                                          std::forward_as_tuple(memory_id),
                                          std::forward_as_tuple(mapped_memory, total_pages, last_segment_size));
    GFXRECON_ASSERT(new_entry.second);
    MemoryInfo& new_memory_info = new_entry.first->second;

    Hash128* const       hash_data = new_memory_info.hashes.data();
    const uint8_t* const base      = reinterpret_cast<const uint8_t*>(mapped_memory);
    ForEachPage(new_memory_info, [hash_data, base](size_t page, size_t block_size) {
        const XXH128_hash_t hash = XXH3_128bits(base + page * block_size, block_size);
        hash_data[page]          = { hash.low64, hash.high64 };
    });
}

void HashingManager::RemoveTrackedMemory(uint64_t memory_id)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);
    auto                        entry = memory_info_.find(memory_id);

    if ((entry != memory_info_.end()))
    {
        memory_info_.erase(entry);
    }
}

void HashingManager::ProcessMemoryEntry(uint64_t memory_id, const ModifiedMemoryFunc& handle_modified)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);
    auto                        entry = memory_info_.find(memory_id);

    if (entry != memory_info_.end())
    {
        ProcessEntry(entry, handle_modified);
    }
}

void HashingManager::ProcessMemoryEntries(const ModifiedMemoryFunc& handle_modified)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    for (auto entry = memory_info_.begin(); entry != memory_info_.end(); ++entry)
    {
        ProcessEntry(entry, handle_modified);
    }
}

void HashingManager::ProcessEntry(MemoryInfoEntry memory_entry, const ModifiedMemoryFunc& handle_modified)
{
    MemoryInfo& memory_info = memory_entry->second;

    std::fill(memory_info.pages_status.begin(), memory_info.pages_status.end(), 0);

    Hash128* const       hash_data = memory_info.hashes.data();
    const uint8_t* const base      = reinterpret_cast<const uint8_t*>(memory_info.mapped_memory);
    PagesStatus&         status    = memory_info.pages_status;
    ForEachPage(memory_info, [hash_data, base, &status](size_t page, size_t block_size) {
        const XXH128_hash_t hash = XXH3_128bits(base + page * block_size, block_size);
        if (hash_data[page].low64 != hash.low64 || hash_data[page].high64 != hash.high64)
        {
            hash_data[page] = { hash.low64, hash.high64 };
            status[page]    = 1;
        }
    });

    bool   active_range = false;
    size_t start_index  = 0;

    for (size_t i = 0; i < memory_info.total_pages; ++i)
    {
        if (memory_info.pages_status[i])
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
                ProcessActiveRange(memory_entry, start_index, i, handle_modified);
            }
        }
    }

    if (active_range)
    {
        ProcessActiveRange(memory_entry, start_index, memory_info.total_pages, handle_modified);
    }
}

void HashingManager::ProcessActiveRange(MemoryInfoEntry           memory_entry,
                                        size_t                    start_index,
                                        size_t                    end_index,
                                        const ModifiedMemoryFunc& handle_modified)
{
    GFXRECON_ASSERT(end_index > start_index);

    const size_t page_count  = end_index - start_index;
    const size_t page_offset = start_index << block_size_pot_shift_;
    size_t       page_range  = page_count << block_size_pot_shift_;

    if (end_index == memory_entry->second.total_pages)
    {
        // Adjust range for memory ranges that end with a partial page.
        page_range -= block_size_ - memory_entry->second.last_segment_size;
    }

    handle_modified(memory_entry->first, memory_entry->second.mapped_memory, page_offset, page_range);
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
