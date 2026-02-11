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

bool BlockBatch::IsBatchFull() const noexcept
{
    return allocator_.IsOverflowed();
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

BlockBatch::BatchPtr& BlockBatch::GetNext()
{
    return next_batch_;
}

BlockBatch::iterator& BlockBatch::iterator::operator++()
{
    GFXRECON_ASSERT(batch_.get() != nullptr);
    GFXRECON_ASSERT(block_ != nullptr);
    block_ = block_->GetNext();
    if (block_ == nullptr)
    {
        // End of batch find next non-empty batch, or 'end'
        do
        {
            // Make a *copy* of the batch_'s next pointer, in case the iterator is the only owner when we
            // overwrite batch_ below. With move construction and assignment below we still have only on
            // atomic assignment operation per loop iteration.
            BatchPtr next_batch = batch_->GetNext();
            GFXRECON_ASSERT(next_batch.get() != batch_.get());
            if (!next_batch)
            {
                // No more batches end.
                *this = iterator();
                break;
            }
            if (!next_batch->empty())
            {
                // Found a non-empty batch stop looking
                *this = iterator(std::move(next_batch));
                break;
            }
            batch_ = std::move(next_batch);
        } while (true);
    }
    return *this;
}

BlockBatch::iterator BlockBatch::iterator::operator++(int)
{
    GFXRECON_ASSERT(block_ != nullptr);
    iterator temp = *this;
    ++(*this);
    return temp;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
