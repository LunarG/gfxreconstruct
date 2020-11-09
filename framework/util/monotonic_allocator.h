
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

#ifndef GFXRECON_UTIL_MONOTONIC_ALLOCATOR_H
#define GFXRECON_UTIL_MONOTONIC_ALLOCATOR_H

#include "util/defines.h"

#include <memory>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// An allocator that manages and allocates from a pool of system memory blocks
class MonotonicAllocator
{
  public:
    // block_size is the size of the individual memory blocks allocated. The number of blocks increases as needed to
    // fit requested allocations, and blocks are freed using an appropriate call to Clear or upon destruction of this
    // MonotonicAllocator
    MonotonicAllocator(size_t block_size) :
        block_size_(block_size), current_block_(0), current_block_free_bytes_(block_size)
    {}

    ~MonotonicAllocator() { Clear(true); }

    // Allocates memory for count objects of type T and optionally initializes them with default constructor. Objects
    // allocated here are valid until the next call to Clear. If the allocation requires greater than block_size
    // bytes (oversized allocation), a system heap allocation is performed.
    template <typename T>
    T* Allocate(size_t count = 1, bool initialize = true)
    {
        T* result = reinterpret_cast<T*>(Allocate(sizeof(T) * count, alignof(T)));
        assert(result != nullptr);
        if ((result != nullptr) && initialize)
        {
            for (size_t i = 0; i < count; ++i)
            {
                T* obj = new (result + i) T();
                if (!std::is_trivially_destructible<T>())
                {
                    destructors_.push_back({ obj, [](const void* x) { static_cast<const T*>(x)->~T(); } });
                }
            }
        }
        assert(!(reinterpret_cast<uintptr_t>(result) % std::alignment_of<T>::value) &&
               "Allocated memory is not correctly aligned.");
        return result;
    }

    // "Frees" all previously allocated objects. Depending on free_system_memory, system memory blocks are either
    // reused for new calls to Allocate or freed and re-created as needed. Oversized allocations are freed from system
    // memory
    void Clear(bool free_system_memory);

  private:
    void* Allocate(size_t object_bytes, size_t alignment_bytes);
    void* AllocateToBlock(size_t object_bytes, size_t alignment_bytes);

  private:
    struct Destructor
    {
        void* obj;
        void (*destroy)(const void*);
    };

  private:
    std::vector<std::unique_ptr<unsigned char[]>> memory_blocks_;
    std::vector<std::unique_ptr<unsigned char[]>> oversized_allocations_;
    std::vector<Destructor>                       destructors_;
    const size_t                                  block_size_;
    size_t                                        current_block_;
    size_t                                        current_block_free_bytes_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_MONOTONIC_ALLOCATOR_H
