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

#ifndef GFXRECON_UTIL_HYBRID_LINEAR_ALLOCATOR_H
#define GFXRECON_UTIL_HYBRID_LINEAR_ALLOCATOR_H
/* BlockBatch: ParsedBlocks and associated memory for a collection of Blocks */

#include "util/defines.h"
#include "util/logging.h"

#include <algorithm>
#include <cstddef>
#include <deque>
#include <memory>

// #define ZZZ_INSTRUMENT
#ifdef ZZZ_INSTRUMENT
#include <iostream>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class HybridLinearAllocator
{
  public:
    using DataType = uint8_t;
    using Store    = std::unique_ptr<DataType[]>;

    // 2 MB -- the default size of the linear allocation
    constexpr static size_t kDefaultCapacity = 2 * 1024 * 1024;
    // Size threshold for low frequency, large allocations, which are dynamically allocated
    constexpr static size_t kDefaultJumboSize = 2 * 1024;
    constexpr static size_t kAlignment        = alignof(std::max_align_t); // Safe alignment for all types

    HybridLinearAllocator() : HybridLinearAllocator(kDefaultCapacity, kDefaultJumboSize) {}
    HybridLinearAllocator(size_t capacity, size_t jumbo);
    ~HybridLinearAllocator();

    template <size_t kAlignment>
    void* Allocate(size_t size)
    {
        assert(std::has_single_bit(kAlignment));
        const uintptr_t cursor        = reinterpret_cast<uintptr_t>(alloc_cursor_);
        uintptr_t       start         = aligned_value<kAlignment>(cursor);
        const size_t    align_pad     = static_cast<size_t>(start - cursor);
        const size_t    total_size    = size + align_pad;
        DataType* const update_cursor = alloc_cursor_ + total_size;

        const bool has_linear_space = update_cursor <= alloc_end_;
        const bool is_jumbo         = total_size >= jumbo_;
        if (is_jumbo || !has_linear_space)
        {
            return AllocateDynamic(size, kAlignment);
        }

        alloc_cursor_ = update_cursor;
        return reinterpret_cast<void*>(start);
    }

    // Emplace a new ParsedBlock at the end of the batch
    template <typename T, typename... Args>
    [[nodiscard]] T* emplace(Args&&... args)
    {
        void* storage = Allocate<alignof(T)>(sizeof(T));
        T*    obj     = new (storage) T(std::forward<Args>(args)...);
        if constexpr (!std::is_trivially_destructible_v<T>)
        {
            trivial_ = false;
            destructors_.emplace_back(obj);
        }
        return obj;
    }

    void reset()
    {
        if (!trivial_) [[unlikely]]
        {
            reset_non_trivial();
        }

#ifdef ZZZ_INSTRUMENT
        InstrumentReset();
#endif

        // Reset the logical state of the allocator
        alloc_cursor_ = reset_cursor_;
    }

    size_t BytesRemaining() const noexcept;
    bool   HasDynamicAllocations() const noexcept
    {
        return !dynamic_allocations_.empty();
    }
    bool HasNonTrivialAllocations() const noexcept
    {
        return !destructors_.empty();
    }

  private:
#ifdef ZZZ_INSTRUMENT
    size_t kResets      = 0;
    size_t kK           = 0;
    size_t kDestructors = 0;
    size_t kDynamic     = 0;
    size_t kNonTrivial  = 0;
    size_t kTotalLinear = 0;
    void   InstrumentReset();
#endif
    void reset_non_trivial();

    void SetStorePointers();

    // All dynamic allocations are aligned to at least kAlignment, but support stricter pow2 alignments
    struct DynamicDeleter
    {
        std::align_val_t alignment;
        void             operator()(void* pointer) const noexcept { ::operator delete(pointer, alignment); }
    };

    using DynamicAllocation  = std::unique_ptr<void, DynamicDeleter>;
    using DynamicAllocations = std::deque<DynamicAllocation>;

    static DynamicAllocation MakeDynamicAllocation(size_t size, size_t alignment);

    void* AllocateDynamic(size_t size, size_t alignment);

    const size_t       capacity_;
    const size_t       jumbo_;
    DynamicAllocation  store_;
    DynamicAllocations dynamic_allocations_;

    DataType* reset_cursor_ = nullptr;
    DataType* alloc_cursor_ = nullptr;
    DataType* alloc_end_    = nullptr;
    bool      trivial_      = true;

    // Type erasure for destructors of non-trivially destructible emplaced objects in the arena:
    // Background reading: https://herbsutter.com/2016/09/25/to-store-a-destructor/
    // This approach lighter weight (but more code) using a custom functor instead of a std::function wrapped lambda
    using DestructorProc = void (*)(void*);
    class DestructorFunctor
    {
      public:
        // Restrict operations with semantics that don't match this RAII ownership of
        // destruction
        DestructorFunctor()                                          = delete;
        DestructorFunctor(const DestructorFunctor&)                  = delete;
        DestructorFunctor& operator=(const DestructorFunctor& other) = delete;
        DestructorFunctor& operator=(DestructorFunctor&& other)      = delete;

        template <typename T>
        explicit DestructorFunctor(T* data) noexcept : data_(data), proc_(&DestructorSpecialization<T>)
        {
            static_assert(!std::is_trivially_destructible_v<T>);
            GFXRECON_ASSERT(data != nullptr);
        }

        // Containers may need this to shuffle entries potentially.  It's safe and doesn't
        // prematurely destruct the held data_ unless the move *to* is destructed, and that's
        // inconsistent with container usage of move construction
        DestructorFunctor(DestructorFunctor&& other) noexcept : data_(other.data_), proc_(other.proc_)
        {
            // No need to null out proc.
            other.data_ = nullptr;
        }

        // When the destructor holder is eliminated, the object is destroyed.  Allocation freeing is the
        // responsibility of whomever created this functor, and is not done here.
        // NOTE: Ensure all DestructorFunctors are destructed *before* freeing backing allocation, this is the
        //       callers responsibility to ensure destructors aren't called on stale pointers.
        ~DestructorFunctor()
        {
            if (data_ != nullptr)
            {
                GFXRECON_ASSERT(proc_ != nullptr);
                proc_(data_);
            }
        }

      private:
        // This is now the destructor is anonymized.  A specialization is created for every type a
        // DestructorFunctor is created from, and the address of that specialization is stored in
        // the DestructorFunctor along with the anonymized pointer.
        template <typename T>
        static void DestructorSpecialization(void* data)
        {
            GFXRECON_ASSERT(data != nullptr);
            static_cast<T*>(data)->~T();
        }

        void*          data_;
        DestructorProc proc_;
    };
    using Destructors = std::deque<DestructorFunctor>;
    Destructors destructors_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_HYBRID_LINEAR_ALLOCATOR_H