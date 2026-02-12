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
#include "util/hybrid_linear_allocator.h"

#include <cstddef>
#include <deque>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class BlockBatch
{
  public:
    using value_type = ParsedBlock;
    using reference  = ParsedBlock&;
    using pointer    = ParsedBlock*;
    using BatchPtr   = std::shared_ptr<BlockBatch>;

    // 2 MB -- the size of the linear allocation
    constexpr static size_t kCapacity = 2 * 1024 * 1024;
    // Size threshold for low frequency, large allocations, which are dynamically allocated
    constexpr static size_t kJumboSize = 2 * 1024;

    BlockBatch() : allocator_(kCapacity, kJumboSize), head_(nullptr), tail_(nullptr) {}
    ~BlockBatch() = default;

    void* Allocate(size_t size, size_t alignment) { return allocator_.Allocate(size, alignment); }

    template <typename T, typename... Args>
    [[nodiscard]] T* emplace(Args&&... args)
    {
        return allocator_.emplace<T>(std::forward<Args>(args)...);
    }

    // Emplace a new ParsedBlock at the end of the batch
    // This isn't marked "nodiscard" as it's saved in the linked list
    template <typename... Args>
    reference emplace_block(Args&&... args)
    {
        ParsedBlock* parsed_block = allocator_.emplace<ParsedBlock>(std::forward<Args>(args)...);

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

        iterator& operator++();
        iterator  operator++(int);

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
    void    reset();

    bool      IsBatchFull() const noexcept;
    size_t    BytesRemaining() const noexcept;
    void      SetNext(const BatchPtr& batch);
    BatchPtr& GetNext();

  private:
    util::HybridLinearAllocator allocator_;

    pointer   head_;
    pointer   tail_;
    BatchPtr  next_batch_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_BLOCK_BATCH_H