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

/* BlockBatch: ParsedBlocks and associated memory for a collection of Blocks */
#include "decode/block_batch.h"
#include "util/alignment_utils.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void* BlockBatch::Allocate(size_t size)
{
    // Large allocations are infrequent, but dominate memory usage if allocated from the linear block.
    // > 99% of allocations are expected to be less than kJumbo.
    if (size >= kJumboSize)
    {
        return AllocateDynamic(size);
    }

    // Linearly allocate if there is sufficient space remaining in the block batch.
    // Only allocations from the linear store require alignment padding (for subsequent allocations).
    const size_t aligned_size = util::aligned_value<kAlignment>(size);
    if ((alloc_cursor_ + aligned_size) <= alloc_end_)
    {
        void* ptr = alloc_cursor_;
        alloc_cursor_ += aligned_size;
        return ptr;
    }

    // We underestimated the required size of the current block, so mark it as full and allocate dynamically.
    //
    // Full doesn't prevent allocations, it just tells the BlockAllocator not to start a new Block in this batch.
    // Given that typically 4K-8K blocks are allocated per batch, this should be a rare occurrence, with minimal
    // performance impact.
    //
    // Also, if a later allocation is smaller than space remaining in the batch, it will still be allocated from the
    // batch linear store.
    batch_full_ = true;
    return AllocateDynamic(size);
}

void* BlockBatch::AllocateDynamic(size_t size)
{
    // Large or overflow allocations are allocated individually.
    dynamic_allocations_.emplace_back(new DataType[size]);
    return dynamic_allocations_.back().get();
}

void BlockBatch::DestroyBlocks()
{
    if (!batch_trivial_)
    {
        // If any block in the batch had non-trivial dispatch args, we need to destroy all blocks
        ParsedBlock* current = head_;
        while (current != nullptr)
        {
            // TODO: See if it's more efficient to recheck triviality per-block here, rather than blindly destroying
            // all blocks
            ParsedBlock* next = current->GetNext();
            current->~ParsedBlock();
            current = next;
        }
        batch_trivial_ = true;
    }

    // Technically not required when called from the Destructor, but it's constructive paranoia, from
    // being bitten by dangling pointers before.
    head_ = nullptr;
    tail_ = nullptr;
}

void BlockBatch::clear()
{
    // Destroy all blocks in the batch
    DestroyBlocks();

    // Reset the allocation state
    alloc_cursor_ = store_.get();
    alloc_end_    = store_.get() + kCapacity;
    dynamic_allocations_.clear();

    // Reset the logical state of the batch
    batch_full_ = false;

    // No longer reference next
    next_batch_.reset();
}

size_t BlockBatch::BytesRemaining() const noexcept
{
    GFXRECON_ASSERT(alloc_cursor_ <= alloc_end_);
    return static_cast<size_t>(alloc_end_ - alloc_cursor_);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
