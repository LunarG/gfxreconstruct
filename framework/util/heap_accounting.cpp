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

#include "util/heap_accounting.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(heap_accounting)

std::atomic<int64_t>  current_bytes_g{ 0 };
std::atomic<int64_t>  peak_bytes_g{ 0 };
std::atomic<uint64_t> total_allocated_bytes_g{ 0 };
std::atomic<uint64_t> alloc_count_g{ 0 };
std::atomic<uint64_t> free_count_g{ 0 };

HeapStats GetHeapStats()
{
    HeapStats stats;
    stats.current_bytes         = current_bytes_g.load(std::memory_order_relaxed);
    stats.peak_bytes            = peak_bytes_g.load(std::memory_order_relaxed);
    stats.total_allocated_bytes = total_allocated_bytes_g.load(std::memory_order_relaxed);
    stats.alloc_count           = alloc_count_g.load(std::memory_order_relaxed);
    stats.free_count            = free_count_g.load(std::memory_order_relaxed);
    return stats;
}

GFXRECON_END_NAMESPACE(heap_accounting)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
