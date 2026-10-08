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
#include "util/logging.h"

#include <atomic>
#include <cstddef>
#include <cstdint>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(heap_accounting)

extern std::atomic<int64_t>  current_bytes_g;
extern std::atomic<int64_t>  peak_bytes_g;
extern std::atomic<uint64_t> total_allocated_bytes_g;
extern std::atomic<uint64_t> alloc_count_g;
extern std::atomic<uint64_t> free_count_g;

// Heap use of the code linked into the capture layer library: gfxrecon itself, the
// compression libraries and the C++ runtime when it is linked statically. Memory obtained
// with mmap (page guard shadow memory) and blocks that libc allocates internally on the
// layer's behalf (stdio buffers) are not included. Sizes are what the allocator reserved
// for each block (malloc_usable_size), not the requested sizes.
//
// The counters only change when the layer is built with GFXRECON_ENABLE_HEAP_ACCOUNTING,
// which routes the malloc family through layer/heap_impostor.cpp; otherwise they stay zero.
struct HeapStats
{
    int64_t  current_bytes{ 0 };         // Bytes currently allocated.
    int64_t  peak_bytes{ 0 };            // High-water mark of current_bytes.
    uint64_t total_allocated_bytes{ 0 }; // Cumulative bytes handed out.
    uint64_t alloc_count{ 0 };           // Cumulative number of allocations.
    uint64_t free_count{ 0 };            // Cumulative number of frees.
};

HeapStats GetHeapStats();

// Called by the allocator impostor for every block it allocates
inline void RecordAlloc(size_t usable_size)
{
    const auto size = static_cast<int64_t>(usable_size);

    alloc_count_g.fetch_add(1, std::memory_order_relaxed);
    total_allocated_bytes_g.fetch_add(usable_size, std::memory_order_relaxed);

    const int64_t current = current_bytes_g.fetch_add(size, std::memory_order_relaxed) + size;
    int64_t       peak    = peak_bytes_g.load(std::memory_order_relaxed);
    while ((current > peak) && !peak_bytes_g.compare_exchange_weak(peak, current, std::memory_order_relaxed))
    {}
}

// Called by the allocator impostor for every block it frees
inline void RecordFree(size_t usable_size)
{
    free_count_g.fetch_add(1, std::memory_order_relaxed);
    current_bytes_g.fetch_sub(static_cast<int64_t>(usable_size), std::memory_order_relaxed);
}

GFXRECON_END_NAMESPACE(heap_accounting)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_HEAP_ACCOUNTING_H
