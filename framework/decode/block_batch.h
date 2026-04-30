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

    // Capacity -- the size of the linear allocation
    constexpr static size_t kCapacity = 1 * 1024 * 1024;
    // Size threshold for low frequency, large allocations, which are dynamically allocated
    constexpr static size_t kJumboSize = 1 * 1024;

    BlockBatch() : allocator_(kCapacity, kJumboSize), head_(nullptr), tail_(nullptr) {}
    ~BlockBatch() = default;

    template <size_t kAlignment>
    void* Allocate(size_t size)
    {
        return allocator_.Allocate<kAlignment>(size);
    }

    template <typename T, typename... Args>
    [[nodiscard]] T* emplace(Args&&... args)
    {
        return allocator_.emplace<T>(std::forward<Args>(args)...);
    }

    // Emplace a new ParsedBlock at the end of the batch
    // This isn't marked "nodiscard" as it's saved in the linked list
    template <typename... Args>
    reference emplace_block(bool add_to_list, Args&&... args)
    {
        ParsedBlock* parsed_block = allocator_.emplace<ParsedBlock>(std::forward<Args>(args)...);

        if (add_to_list)
        {
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
        }
        return *parsed_block;
    }

    // The block batch stores parsed blocks in an internal linked list.
    // Public traversal is intentionally limited to direct access through head/tail accessors.

    pointer Head() const noexcept { return head_; }
    pointer Tail() const noexcept { return tail_; }

    bool empty() const noexcept { return head_ == nullptr; }

#if !defined(NDEBUG)
    // Returns true if block is reachable by walking the linked list from Head().
    // Intended for use in debug assertions only — O(n).
    bool ContainsBlock(const pointer block) const noexcept
    {
        for (auto* cur = head_; cur != nullptr; cur = cur->GetNext())
            if (cur == block)
                return true;
        return false;
    }
#endif

    void    reset();
    void    reset_no_list()
    {
        // Only for use with emplace_block(false, ...) batches
        GFXRECON_ASSERT((head_ == nullptr) && (tail_ == nullptr));
        allocator_.reset();
    }

    size_t BytesRemaining() const noexcept;

    void SetBatchTag(uint64_t tag) noexcept
    {
        batch_tag_ = tag;
    }
    uint64_t GetBatchTag() const noexcept
    {
        return batch_tag_;
    }

  private:
    util::HybridLinearAllocator allocator_;

    pointer  head_;
    pointer  tail_;
    uint64_t batch_tag_ = 0; // Opaque tag for batch identification
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_BLOCK_BATCH_H