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

void BlockBatch::reset()
{
    // Reset the allocator, which destroy all blocks in the batch
    allocator_.reset();

    // Empty block list
    head_ = nullptr;
    tail_ = nullptr;

    // No longer reference next
    next_batch_.reset();
}

size_t BlockBatch::BytesRemaining() const noexcept
{
    return allocator_.BytesRemaining();
}

void BlockBatch::SetNext(const BatchPtr& batch)
{
    // We don't want set to destructively lose a next chain, and we aren't going
    // catch a return everywhere.  So, just don't do it.
    GFXRECON_ASSERT(next_batch_.get() == nullptr);
    GFXRECON_ASSERT(batch.get() != this);
    next_batch_ = batch;
}

// This gets the next non-empty batch in the chain, including the passed batch,
// nullptr is returned if there are no more batches or all remaining batches are
BlockBatch::BatchPtr BlockBatch::NonEmptyBatch(BatchPtr&& batch)
{
    // Short circuit if batch is a null or non-empty batch.
    if ((batch.get() == nullptr) || !batch->empty())
    {
        return std::move(batch);
    }

    return NextNonEmptyBatch(batch);
}

BlockBatch::BatchPtr BlockBatch::NextNonEmptyBatch(const BatchPtr& batch)
{
    GFXRECON_ASSERT(batch.get() != nullptr);
    const BatchPtr* last = &batch;
    do
    {
        const BatchPtr& candidate = (*last)->GetNext();
        // Same termination condition: batch is a null or non-empty.
        if ((candidate.get() == nullptr) || !candidate->empty())
        {
            return candidate;
        }
        last = &candidate;
    } while (true);
}

const BlockBatch::BatchPtr& BlockBatch::GetNext() const
{
    GFXRECON_ASSERT(next_batch_.get() != this);
    return next_batch_;
}

// Linear walk to the end.  Don't call this repeatedly, it's O(n) for batch list length.
// Current use case is appending batch lists.
BlockBatch* BlockBatch::GetTail()
{
    BlockBatch* tail = this;
    BlockBatch* next = tail->next_batch_.get();
    while (next != nullptr)
    {
        GFXRECON_ASSERT(next != tail);
        tail = next;
        next = tail->next_batch_.get();
    }
    return tail;
}

BlockBatch::iterator BlockBatch::MakeIteratorFromBatch(BatchPtr&& batch)
{
    // Get the first non-empty batch (or nullptr) (including the passed batch)
    batch = NonEmptyBatch(std::move(batch));

    // If batch is nullptr, the iterator will be at end(), otherwise at the front of the first non-empty // batch.
    return iterator(std::move(batch));
}

BlockBatch::iterator BlockBatch::iterator::operator++(int)
{
    GFXRECON_ASSERT(block_ != nullptr);
    iterator temp = *this;
    ++(*this);
    return temp;
}

void BlockBatch::iterator::IncrementToNextNonEmpty()
{
    // NonEmptyBatch should be zero cost if next_batch is non-empty
    // This is a slow path, but should only be hit if there are empty batches, which should be rare and transient.
    GFXRECON_ASSERT(batch_.get() != nullptr);
    GFXRECON_ASSERT(batch_->empty());
    GFXRECON_ASSERT(block_ == nullptr);
    batch_ = NextNonEmptyBatch(batch_);
    if (batch_.get() != nullptr)
    {
        // We found a non-empty batch, thus the "next" block is the front of that batch`
        block_ = batch_->front();
        GFXRECON_ASSERT(block_ != nullptr); // Verifies NonEmpty is doing its job
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
