
/*
** Copyright (c) 2020 LunarG, Inc.
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

#include "util/monotonic_allocator.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

void MonotonicAllocator::Clear(bool free_system_memory)
{
    // Call destructors of allocated objects
    for (auto destructor : destructors_)
    {
        destructor.destroy(destructor.obj);
    }
    destructors_.clear();

    // Free memory blocks
    if (free_system_memory)
    {
        memory_blocks_.clear();
    }

    // Free oversized allocations
    oversized_allocations_.clear();

    current_block_            = 0;
    current_block_free_bytes_ = block_size_;
}

void* MonotonicAllocator::Allocate(size_t object_bytes, size_t alignment_bytes)
{
    void* result = nullptr;

    // Don't allocate 0 bytes
    assert(object_bytes + alignment_bytes > 0);
    if (object_bytes + alignment_bytes == 0)
    {
        return nullptr;
    }

    if (object_bytes <= block_size_)
    {
        // Try to allocate to an existing block
        while (current_block_ < memory_blocks_.size() && result == nullptr)
        {
            result = AllocateToBlock(object_bytes, alignment_bytes);
            if (result == nullptr)
            {
                // Move to next block
                ++current_block_;
                current_block_free_bytes_ = block_size_;
            }
        }

        if (result == nullptr)
        {
            memory_blocks_.emplace_back(new unsigned char[block_size_]);
            result = AllocateToBlock(object_bytes, alignment_bytes);
        }
    }
    else
    {
        // Custom allocation
        oversized_allocations_.emplace_back(new unsigned char[object_bytes]);
        result = oversized_allocations_.back().get();
    }

    return result;
}

void* MonotonicAllocator::AllocateToBlock(size_t object_bytes, size_t alignment_bytes)
{
    void* block_ptr =
        reinterpret_cast<void*>(memory_blocks_[current_block_].get() + block_size_ - current_block_free_bytes_);
    void* result = std::align(alignment_bytes, object_bytes, block_ptr, current_block_free_bytes_);
    if (result != nullptr)
    {
        current_block_free_bytes_ -= object_bytes;
    }
    return result;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
