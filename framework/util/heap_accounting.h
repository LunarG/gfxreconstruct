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

#ifndef GFXRECON_UTIL_HEAP_ACCOUNTING_H
#define GFXRECON_UTIL_HEAP_ACCOUNTING_H

#include "util/defines.h"

#include <atomic>
#include <cstddef>
#include <cstdint>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(heap_accounting)

extern std::atomic<int64_t>  current_bytes_g;
extern std::atomic<int64_t>  peak_bytes_g;
extern std::atomic<int64_t>  current_mmap_bytes_g;
extern std::atomic<int64_t>  peak_mmap_bytes_g;
extern std::atomic<uint64_t> total_allocated_bytes_g;
extern std::atomic<uint64_t> alloc_count_g;
extern std::atomic<uint64_t> free_count_g;

// The counters only change when the layer is built with GFXRECON_ENABLE_HEAP_ACCOUNTING.
struct HeapStats
{
    int64_t  current_bytes{ 0 };         // Bytes currently allocated.
    int64_t  peak_bytes{ 0 };            // High-water mark of current_bytes.
    int64_t  current_mmap_bytes{ 0 };    // Bytes currently allocated through mmap (page_guard).
    int64_t  peak_mmap_bytes{ 0 };       // High-water mark of current_mmap_bytes.
    uint64_t total_allocated_bytes{ 0 }; // Cumulative bytes handed out.
    uint64_t alloc_count{ 0 };           // Cumulative number of allocations.
    uint64_t free_count{ 0 };            // Cumulative number of frees.
};

HeapStats GetHeapStats();

inline void UpdatePeak(int64_t current, std::atomic<int64_t>& peak)
{
    int64_t p = peak.load(std::memory_order_relaxed);
    while ((current > p) && !peak.compare_exchange_weak(p, current, std::memory_order_relaxed))
    {}
}

// Called by the allocator impostor for every block it hands out.
inline void RecordAlloc(size_t usable_size)
{
    const auto size = static_cast<int64_t>(usable_size);

    alloc_count_g.fetch_add(1, std::memory_order_relaxed);
    total_allocated_bytes_g.fetch_add(usable_size, std::memory_order_relaxed);
    int64_t current = current_bytes_g.fetch_add(size, std::memory_order_relaxed) + size;

    UpdatePeak(current, peak_bytes_g);
}

// Called by the allocator impostor for every block it frees
inline void RecordFree(size_t usable_size)
{
    free_count_g.fetch_add(1, std::memory_order_relaxed);
    current_bytes_g.fetch_sub(static_cast<int64_t>(usable_size), std::memory_order_relaxed);
}

inline void RecordRawAlloc(size_t size)
{
    alloc_count_g.fetch_add(1, std::memory_order_relaxed);
    total_allocated_bytes_g.fetch_add(static_cast<uint64_t>(size), std::memory_order_relaxed);

    const int64_t current =
        current_mmap_bytes_g.fetch_add(static_cast<int64_t>(size), std::memory_order_relaxed) + size;
    UpdatePeak(current, peak_mmap_bytes_g);
}

inline void RecordRawFree(size_t size)
{
    free_count_g.fetch_add(1, std::memory_order_relaxed);
    current_mmap_bytes_g.fetch_sub(static_cast<int64_t>(size), std::memory_order_relaxed);
}

GFXRECON_END_NAMESPACE(heap_accounting)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_HEAP_ACCOUNTING_H
