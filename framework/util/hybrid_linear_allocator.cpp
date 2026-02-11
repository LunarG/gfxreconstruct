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

/*
 * Hybrid Linear Allocator:
 *   * small allocations in common linear store_
 *   * large allocations (and overflowing allocations) on heap
 *   * type-erased destructors for non-trivial type support
 */

#include "util/hybrid_linear_allocator.h"
#include "util/alignment_utils.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

HybridLinearAllocator::HybridLinearAllocator(size_t capacity, size_t jumbo) :
    capacity_(capacity), jumbo_(jumbo), store_(MakeDynamicAllocation(capacity, kAlignment))
{
    GFXRECON_ASSERT((capacity_ > 0) && (jumbo > 0) && (capacity_ > jumbo));
    ResetCursor();
}

HybridLinearAllocator::~HybridLinearAllocator()
{
    // Must call the non-trivial destructors before any allocations are destroyed
    destructors_.clear();
}

void* HybridLinearAllocator::Allocate(size_t size, size_t alignment)
{
    const uintptr_t cursor = reinterpret_cast<uintptr_t>(alloc_cursor_);
    if (alignment == 0)
    {
        alignment = alignof(std::max_align_t);
    }

    uintptr_t       start     = aligned_value_nz(cursor, alignment);
    const uintptr_t align_pad = start - cursor;
    const uintptr_t total_use = size + align_pad;

    // Large allocations are infrequent, but dominate memory usage if allocated from the linear block.
    // > 99% of allocations are expected to be less than kJumbo.
    if (total_use >= jumbo_)
    {
        return AllocateDynamic(size, alignment);
    }

    // Linearly allocate if there is sufficient space remaining in the linear store
    if ((alloc_cursor_ + total_use) <= alloc_end_)
    {
        alloc_cursor_ += total_use;
        return reinterpret_cast<void*>(start);
    }

    // Non-jumbo allocation will not fit.  Don't fail, just allocate and mark overflow, such that callers will know
    //
    // Also, if a later allocation is smaller than space remaining in the store, it will still be allocated from the
    // linear store.
    overflowed_ = true;
    return AllocateDynamic(size, alignment);
}

void HybridLinearAllocator::reset()
{
    // Clean up non-trival emplaced objects and dynamic allocations
    destructors_.clear();
    dynamic_allocations_.clear();

    // Reset the logical state of the allocator
    ResetCursor();
    overflowed_ = false;
}

size_t HybridLinearAllocator::BytesRemaining() const noexcept
{
    GFXRECON_ASSERT(alloc_cursor_ <= alloc_end_);
    return static_cast<size_t>(alloc_end_ - alloc_cursor_);
}

void HybridLinearAllocator::ResetCursor()
{
    alloc_cursor_ = static_cast<DataType*>(store_.get());
    alloc_end_    = alloc_cursor_ + capacity_;
}

HybridLinearAllocator::DynamicAllocation HybridLinearAllocator::MakeDynamicAllocation(size_t size, size_t alignment)
{
    GFXRECON_ASSERT(is_pow_2(alignment));
    std::align_val_t align_arg{ alignment };
    void* aligned_alloc = ::operator new(size, align_arg);
    return { aligned_alloc, DynamicDeleter{ align_arg } };
}

void* HybridLinearAllocator::AllocateDynamic(size_t size, size_t alignment)
{
    // Aligned alloc requires kAlignment (alignof(std::max_align_t))) as minimum
    alignment = std::max(alignment, kAlignment);

    dynamic_allocations_.emplace_back(MakeDynamicAllocation(size, alignment));
    return dynamic_allocations_.back().get();
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
