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
    SetStorePointers();
}

HybridLinearAllocator::~HybridLinearAllocator()
{
    // Must call the non-trivial destructors before any allocations are destroyed
    destructors_.clear();
}

#if 0
template <size_t kAlignment>
void* Allocate(size_t size)
{
    assert(std::has_single_bit(kAlignment));
    const uintptr_t cursor = reinterpret_cast<uintptr_t>(alloc_cursor_);
    uintptr_t       start  = aligned_value<kAlignment>(cursor);
    const uintptr_t align_pad = start - cursor;
    const uintptr_t total_use = size + align_pad;

    const bool has_linear_space = (alloc_cursor_ + total_use) <= alloc_end_;
    const bool is_jumbo         = total_size >= jumbo;
    if (is_jumbo || !has_linear_space )
    {
        overflow_ |= !has_linear_space && !is_jumbo;
        return AllocateDynamic(size, kAlignment);
    }

    alloc_cursor_ += total_use;
    return reinterpret_cast<void*>(start);

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
#endif

void HybridLinearAllocator::reset_non_trivial()
{
    // Clean up non-trival emplaced objects and dynamic allocations
#ifdef ZZZ_INSTRUMENT
    kDestructors += destructors_.size();
    kDynamic += dynamic_allocations_.size();
    kNonTrivial++;
#endif
    destructors_.clear();
    dynamic_allocations_.clear();
    trivial_ = true;
}

#ifdef ZZZ_INSTRUMENT
void HybridLinearAllocator::InstrumentReset()
{
    ptrdiff_t zzz_alloc = alloc_cursor_ - reset_cursor_;
    kTotalLinear += static_cast<size_t>(zzz_alloc);
    constexpr size_t kBound = 1000000;
    kResets++;
    if (kResets >= kBound)
    {
        kK += kBound;
        std::cout << "Resets       : " << kK << std::endl;
        std::cout << "NonTrivial   : " << kNonTrivial << std::endl;
        std::cout << "Destructors  : " << kDestructors << std::endl;
        std::cout << "Dynamics     : " << kDynamic << std::endl;
        std::cout << "Total Linear : " << kTotalLinear << std::endl;
        std::cout << "Avg Linear   : " << size_t(.5 + double(kTotalLinear) / double(kK)) << std::endl;
        kResets = 0;
    }
}
#endif

size_t HybridLinearAllocator::BytesRemaining() const noexcept
{
    GFXRECON_ASSERT(alloc_cursor_ <= alloc_end_);
    return static_cast<size_t>(alloc_end_ - alloc_cursor_);
}

void HybridLinearAllocator::SetStorePointers()
{
    reset_cursor_ = static_cast<DataType*>(store_.get());
    alloc_cursor_ = reset_cursor_;
    alloc_end_    = reset_cursor_ + capacity_;
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
    trivial_ = false;
    // Aligned alloc requires kAlignment (alignof(std::max_align_t))) as minimum
    alignment = std::max(alignment, kAlignment);

    dynamic_allocations_.emplace_back(MakeDynamicAllocation(size, alignment));
    return dynamic_allocations_.back().get();
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
