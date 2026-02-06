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

#ifndef GFXRECON_DECODE_BLOCK_BATCH_H
#define GFXRECON_DECODE_BLOCK_BATCH_H
/* BlockBatch: ParsedBlocks and associated memory for a collection of Blocks */

#include "decode/parsed_block.h"
#include "util/defines.h"

#include <cstddef>
#include <deque>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class BlockBatch
{
  public:
    using DataType   = uint8_t;
    using Store      = std::unique_ptr<DataType[]>;
    using value_type = ParsedBlock;
    using reference  = ParsedBlock&;
    using pointer    = ParsedBlock*;
    using BatchPtr   = std::shared_ptr<BlockBatch>;

    constexpr static size_t kCapacity = 2 * 1024 * 1024; // 2 MB -- the size of the linear allocation for blocks
    constexpr static size_t kJumboSize =
        2 * 1024; // Size threshold for low frequency, large allocations, which are dynamically allocated
    constexpr static size_t kAlignment = alignof(std::max_align_t); // Safe alignment for all types

    BlockBatch() :
        store_(new DataType[kCapacity]), head_(nullptr), tail_(nullptr), alloc_cursor_(store_.get()),
        alloc_end_(store_.get() + kCapacity)
    {}
    ~BlockBatch() { DestroyBlocks(); }

    void* Allocate(size_t size);

    // Emplace a new ParsedBlock at the end of the batch
    template <typename... Args>
    reference emplace_back(Args&&... args)
    {
        void*        block_storage = Allocate(sizeof(ParsedBlock));
        ParsedBlock* parsed_block  = new (block_storage) ParsedBlock(*this, std::forward<Args>(args)...);

        if (head_ == nullptr)
        {
            head_ = parsed_block;
            tail_ = parsed_block;
        }
        else
        {
            tail_->SetNext(parsed_block);
            tail_ = parsed_block;
        }

        const bool block_is_trivial = parsed_block->IsTriviallyDestructible();
        batch_trivial_ &= block_is_trivial;
        return *parsed_block;
    }

    class iterator
    {
      public:
        // Standard iterator type aliases
        using iterator_category = std::forward_iterator_tag;
        using value_type        = ParsedBlock;
        using difference_type   = std::ptrdiff_t;
        using pointer           = ParsedBlock*;
        using reference         = ParsedBlock&;
        using BatchPtr          = BlockBatch::BatchPtr;

        iterator() = default;
        explicit iterator(const BatchPtr& batch) :
            batch_(batch), block_((batch.get() == nullptr) ? nullptr : batch->front())
        {}
        explicit iterator(BatchPtr&& batch) :
            batch_(std::move(batch)), block_((batch_.get() == nullptr) ? nullptr : batch_->front())
        {}

        explicit operator bool() const noexcept { return batch_ != nullptr; }

        reference operator*() const { return *block_; }
        pointer   operator->() const { return block_; }

        iterator& operator++()
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
        iterator operator++(int)
        {
            GFXRECON_ASSERT(block_ != nullptr);
            iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const iterator& other) const { return (batch_ == other.batch_) && (block_ == other.block_); }
        bool operator!=(const iterator& other) const { return (batch_ != other.batch_) || (block_ != other.block_); }

        const BatchPtr& GetBatch() const { return batch_; }

      private:
        BatchPtr batch_;
        pointer  block_ = nullptr;
    };

    // While the block batch is not a standard container, provide STL-like iteration support
    pointer front() const noexcept { return head_; }
    pointer back() const noexcept { return tail_; }
    bool    empty() const noexcept { return head_ == nullptr; }
    void    clear();

    bool IsBatchFull() const noexcept { return batch_full_; }

    size_t BytesRemaining() const noexcept;
    bool   HasJumboAllocations() const noexcept { return !dynamic_allocations_.empty(); }

    // Needed by BlockAllocator for rapid reset in immediate mode, clear is "safer" for general use
    void DestroyBlocks();

    void SetNext(const BatchPtr& batch)
    {
        // We don't want set to destructively lose a next chain, and we aren't going
        // catch a return everywhere.  So, just don't do it.
        GFXRECON_ASSERT(next_batch_.get() == nullptr);
        GFXRECON_ASSERT(batch.get() != this);
        next_batch_ = batch;
    }
    BatchPtr& GetNext() { return next_batch_; }

  private:
    void* AllocateDynamic(size_t size);

    Store     store_;
    pointer   head_;
    pointer   tail_;
    DataType* alloc_cursor_;
    DataType* alloc_end_;
    BatchPtr  next_batch_;

    using DynamicAllocations = std::deque<Store>;
    DynamicAllocations dynamic_allocations_;

    // Batch full flag -- don't start another Block in this batch
    bool batch_full_ = false;

    // Batch trivial dispatch args flag -- do all blocks in this batch have trivial dispatch args?
    bool batch_trivial_ = true;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_BLOCK_BATCH_H