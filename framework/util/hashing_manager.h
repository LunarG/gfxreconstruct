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

#ifndef GFXRECON_UTIL_HASHING_MANAGER_H
#define GFXRECON_UTIL_HASHING_MANAGER_H

#include "util/defines.h"
#include "util/threadpool.h"

#include <algorithm>
#include <cstdint>
#include <functional>
#include <future>
#include <mutex>
#include <vector>
#include <unordered_map>

#include <xxhash.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class HashingManager
{
  private:
    static constexpr size_t block_size_ = 4096;
    static size_t           block_size_pot_shift_;

    // Below this many full pages, hashing serially is faster than paying the thread-dispatch overhead.
    static constexpr size_t kMinPagesForThreading = 64; // ~256 KiB

  public:
    // Callback for processing modified memory.  The function parameters are the ID of the modified memory object,
    // a pointer to the start of the modified memory range, the offset from the initial mapped memory pointer to
    // the modified range pointer, and the size of the modified range.
    using ModifiedMemoryFunc = std::function<void(uint64_t, const void*, size_t, size_t)>;

  public:
    static void Create();

    static void Destroy();

    static HashingManager* Get() { return instance_; }

    void AddTrackedMemory(uint64_t memory_id, void* mapped_memory, size_t mapped_range);

    void RemoveTrackedMemory(uint64_t memory_id);

    void ProcessMemoryEntry(uint64_t memory_id, const ModifiedMemoryFunc& handle_modified);

    void ProcessMemoryEntries(const ModifiedMemoryFunc& handle_modified);

  private:
    using HashVector  = std::vector<XXH128_hash_t>;
    using PagesStatus = std::vector<uint8_t>;

    struct MemoryInfo
    {
        MemoryInfo(const void* mm, size_t tp, size_t lss) :
            mapped_memory(mm), total_pages(tp), last_segment_size(lss), pages_status(tp), hashes(tp)
        {}

        // Pointer to mapped memory to be tracked.
        const void*  mapped_memory;
        const size_t total_pages;
        // Size of the last segment of the mapped memory, which may not be a full page.
        const size_t last_segment_size;
        PagesStatus  pages_status;
        HashVector   hashes;
    };

    using MemoryInfoMap   = std::unordered_map<uint64_t, MemoryInfo>;
    using MemoryInfoEntry = std::unordered_map<uint64_t, MemoryInfo>::iterator;

    static HashingManager* instance_;
    MemoryInfoMap          memory_info_;
    std::mutex             tracked_memory_lock_;
    ThreadPool             thread_pool_;

    HashingManager();

    void ProcessEntry(MemoryInfoEntry memory_entry, const ModifiedMemoryFunc& handle_modified);

    void ProcessActiveRange(MemoryInfoEntry           memory_entry,
                            size_t                    start_index,
                            size_t                    end_index,
                            const ModifiedMemoryFunc& handle_modified);

    // Run `fn(page_index)` for every page in [0, page_count).  The work is fanned out across the thread pool when
    // the range is large enough to be worth the dispatch overhead.  `fn` is invoked concurrently on disjoint
    // indices, so it must only touch per-index state.
    template <typename PerPageFn>
    void ForEachPage(const MemoryInfo& memory_info, PerPageFn&& fn)
    {
        const size_t full_pages =
            memory_info.last_segment_size == block_size_ ? memory_info.total_pages : memory_info.total_pages - 1;

        // Below a threshold (or with no worker threads) the dispatch overhead outweighs the win.
        if (full_pages < kMinPagesForThreading || thread_pool_.numthreads() == 0)
        {
            for (size_t i = 0; i < full_pages; ++i)
            {
                fn(i, block_size_);
            }

            // Hash last separately if it is smaller than the block size
            if (full_pages == memory_info.total_pages - 1)
            {
                fn(full_pages, memory_info.last_segment_size);
            }
            return;
        }

        const size_t num_tasks  = thread_pool_.numthreads();
        const size_t pages_each = (full_pages + num_tasks - 1) / num_tasks; // ceil-divide

        std::vector<std::future<void>> futures;
        futures.reserve(num_tasks);

        for (size_t begin = 0; begin < full_pages; begin += pages_each)
        {
            const size_t end = std::min(begin + pages_each, full_pages);

            // Each task processes a disjoint [begin, end) slice, so `fn` needs no internal locking.
            futures.emplace_back(thread_pool_.post([&fn, begin, end]() {
                for (size_t i = begin; i < end; ++i)
                {
                    fn(i, block_size_);
                }
            }));
        }

        // Hash the last page
        if (full_pages == memory_info.total_pages - 1)
        {
            fn(full_pages, memory_info.last_segment_size);
        }

        for (auto& future : futures)
        {
            future.get(); // wait for all slices (also propagates any exception)
        }
    }
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_HASHING_MANAGER_H
