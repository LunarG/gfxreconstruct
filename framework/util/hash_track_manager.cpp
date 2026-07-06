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

#include "hash_track_manager.h"
#include "util/logging.h"
#include <algorithm>
#include <cinttypes>
#include <future>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

HashTrackManager* HashTrackManager::instance_             = nullptr;
size_t            HashTrackManager::block_size_pot_shift_ = 0;

void HashTrackManager::Create()
{
    instance_ = new HashTrackManager();
}

void HashTrackManager::Destroy()
{
    if (instance_ != nullptr)
    {
        delete instance_;
    }
}

HashTrackManager::HashTrackManager() : thread_pool_(std::thread::hardware_concurrency())
{
    GFXRECON_WRITE_CONSOLE("std::thread::hardware_concurrency(): %u", std::thread::hardware_concurrency())

    size_t block          = block_size_;
    block_size_pot_shift_ = 0;

    while (block != 1)
    {
        block >>= 1;
        ++block_size_pot_shift_;
    }
}

void HashTrackManager::HashFullPages(XXH128_hash_t* hashes, const uint8_t* base, size_t page_count)
{
    GFXRECON_WRITE_CONSOLE("%s(map)", __func__)
    // Below a threshold (or with no worker threads) the dispatch overhead outweighs the win.
    if (page_count < kMinPagesForThreading || thread_pool_.numthreads() == 0)
    {
        GFXRECON_WRITE_CONSOLE("  small (%zu)", page_count)
        for (size_t i = 0; i < page_count; ++i)
        {
            hashes[i] = XXH3_128bits(base + i * block_size_, block_size_);
        }
        return;
    }

    const size_t num_tasks  = thread_pool_.numthreads();
    const size_t pages_each = (page_count + num_tasks - 1) / num_tasks; // ceil-divide

    GFXRECON_WRITE_CONSOLE("  parallel (%zu, %zu)", page_count, pages_each)

    std::vector<std::future<void>> futures;
    futures.reserve(num_tasks);

    for (size_t begin = 0; begin < page_count; begin += pages_each)
    {
        const size_t end = std::min(begin + pages_each, page_count);

        // Each task owns a disjoint [begin, end) slice of `hashes`, so no locking is required.
        futures.emplace_back(thread_pool_.post([hashes, base, begin, end]() {
            for (size_t i = begin; i < end; ++i)
            {
                hashes[i] = XXH3_128bits(base + i * block_size_, block_size_);
            }
        }));
    }

    for (auto& future : futures)
    {
        future.get(); // wait for all slices (also propagates any exception)
    }
}

void HashTrackManager::HashFullPages(XXH128_hash_t*     hashes,
                                     const uint8_t*     base,
                                     size_t             page_count,
                                     PageStatusTracker& pages_status)
{
    GFXRECON_WRITE_CONSOLE("%s(submit)", __func__)

    // Below a threshold (or with no worker threads) the dispatch overhead outweighs the win.
    if (page_count < kMinPagesForThreading || thread_pool_.numthreads() == 0)
    {
        GFXRECON_WRITE_CONSOLE("  small (%zu)", page_count)
        for (size_t i = 0; i < page_count; ++i)
        {
            const XXH128_hash_t hash = XXH3_128bits(base + i * block_size_, block_size_);
            if (!XXH128_isEqual(hashes[i], hash))
            {
                hashes[i] = hash;
                pages_status.SetActiveWriteBlock(i, true);
            }
        }
        return;
    }

    const size_t num_tasks  = thread_pool_.numthreads();
    const size_t pages_each = (page_count + num_tasks - 1) / num_tasks; // ceil-divide

    GFXRECON_WRITE_CONSOLE("  parallel (%zu, %zu)", page_count, pages_each)

    std::vector<std::future<void>> futures;
    futures.reserve(num_tasks);

    for (size_t begin = 0; begin < page_count; begin += pages_each)
    {
        const size_t end = std::min(begin + pages_each, page_count);

        // Each task owns a disjoint [begin, end) slice of `hashes`, so no locking is required.
        futures.emplace_back(thread_pool_.post([hashes, base, begin, end, &pages_status]() {
            for (size_t i = begin; i < end; ++i)
            {
                const XXH128_hash_t hash = XXH3_128bits(base + i * block_size_, block_size_);
                if (!XXH128_isEqual(hashes[i], hash))
                {
                    hashes[i] = hash;
                    pages_status.SetActiveWriteBlock(i, true);
                }
            }
        }));
    }

    for (auto& future : futures)
    {
        future.get(); // wait for all slices (also propagates any exception)
    }
}

void HashTrackManager::AddTrackedMemory(uint64_t memory_id, void* mapped_memory, size_t mapped_range)
{
    GFXRECON_ASSERT(mapped_range);

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

    HashVector           hashes(total_pages);
    const uint8_t* const base       = reinterpret_cast<const uint8_t*>(mapped_memory);
    const size_t         full_pages = total_pages - 1; // all but the (possibly partial) last page

    HashFullPages(hashes.data(), base, full_pages);

    // The last page may be a partial block, so hash it on the calling thread.
    hashes[full_pages] = XXH3_128bits(base + full_pages * block_size_, last_segment_size);

    std::lock_guard<std::mutex> lock(tracked_memory_lock_);
    memory_info_.emplace(
        std::piecewise_construct,
        std::forward_as_tuple(memory_id),
        std::forward_as_tuple(mapped_memory, mapped_range, total_pages, last_segment_size, std::move(hashes)));
}

void HashTrackManager::RemoveTrackedMemory(uint64_t memory_id)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);
    auto                        entry = memory_info_.find(memory_id);

    if ((entry != memory_info_.end()))
    {
        memory_info_.erase(entry);
    }
}

void HashTrackManager::ProcessMemoryEntry(uint64_t memory_id, const ModifiedMemoryFunc& handle_modified)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);
    auto                        entry = memory_info_.find(memory_id);

    if (entry != memory_info_.end())
    {
        ProcessEntry(entry, handle_modified);
    }
}

void HashTrackManager::ProcessMemoryEntries(const ModifiedMemoryFunc& handle_modified)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    for (auto entry = memory_info_.begin(); entry != memory_info_.end(); ++entry)
    {
        ProcessEntry(entry, handle_modified);
    }
}

bool HashTrackManager::MemoryInfo::CompareBlock(size_t page)
{
    GFXRECON_ASSERT(page < total_pages);

    const void* block_ptr = static_cast<const void*>(static_cast<const uint8_t*>(mapped_memory) + page * block_size_);

    const size_t        size = page == total_pages - 1 ? last_segment_size : block_size_;
    const XXH128_hash_t hash = XXH3_128bits(block_ptr, size);
    if (!XXH128_isEqual(hashes[page], hash))
    {
        hashes[page] = hash;
        return true;
    }

    return false;
}

void HashTrackManager::ProcessEntry(MemoryInfoEntry memory_entry, const ModifiedMemoryFunc& handle_modified)
{
    MemoryInfo& memory_info = memory_entry->second;

    const uint8_t* const base       = reinterpret_cast<const uint8_t*>(memory_info.mapped_memory);
    const size_t         full_pages = memory_info.total_pages - 1; // all but the (possibly partial) last page

    memory_info.status_tracker.ClearAllBlocksActiveWrite();
    HashFullPages(memory_info.hashes.data(), base, full_pages, memory_info.status_tracker);

    // HashFullPages only covers full pages; handle the (possibly partial) last page.
    if (memory_info.CompareBlock(full_pages))
    {
        memory_info.status_tracker.SetActiveWriteBlock(full_pages, true);
    }

    bool   active_range = false;
    size_t start_index  = 0;

    for (size_t i = 0; i < memory_info.total_pages; ++i)
    {
        if (memory_info.status_tracker.IsActiveWriteBlock(i))
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
                ProcessActiveRange(memory_entry->first, &memory_info, start_index, i, handle_modified);
            }
        }
    }

    if (active_range)
    {
        ProcessActiveRange(memory_entry->first, &memory_info, start_index, memory_info.total_pages, handle_modified);
    }
}

void HashTrackManager::ProcessActiveRange(uint64_t                  memory_id,
                                          MemoryInfo*               memory_info,
                                          size_t                    start_index,
                                          size_t                    end_index,
                                          const ModifiedMemoryFunc& handle_modified)
{
    GFXRECON_ASSERT(end_index > start_index);

    const size_t page_count  = end_index - start_index;
    const size_t page_offset = start_index << block_size_pot_shift_;
    size_t       page_range  = page_count << block_size_pot_shift_;

    if (end_index == memory_info->total_pages)
    {
        // Adjust range for memory ranges that end with a partial page.
        page_range -= block_size_ - memory_info->last_segment_size;
    }

    handle_modified(memory_id, memory_info->mapped_memory, page_offset, page_range);
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
