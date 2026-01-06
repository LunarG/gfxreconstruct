/*
** Copyright (c) 2025 LunarG, Inc.
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
#ifndef GFXRECON_UTIL_HEAP_BUFFER_H
#define GFXRECON_UTIL_HEAP_BUFFER_H

#include "util/logging.h"
#include "util/type_traits_extras.h"

#include <deque>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// Basic heap buffer management class to use instead of std::vector<char>
//
// NOTE: Access is designed to be read-write
// NOTE: ReserveDiscarding will only grow the buffer, never shrink it
// NOTE: ReserveDiscarding doesn't preserve existing data, but also doesn't clear it for performance reasons
// NOTE: This class is *NOT* copyable, only movable
class HeapBuffer
{
  public:
    using DataType = std::byte;
    using Store    = std::unique_ptr<DataType[]>;

    using value_type = DataType;
    using pointer    = DataType*;

    HeapBuffer() = default;
    HeapBuffer(size_t capacity) { ReserveDiscarding(capacity); }
    HeapBuffer(HeapBuffer&& other) noexcept            = default;
    HeapBuffer& operator=(HeapBuffer&& other) noexcept = default;

    // Grow the capacity of the HeapBuffer without attempting to preserve the current contents
    void ReserveDiscarding(size_t capacity);
    void reserve_discarding(size_t capacity) { ReserveDiscarding(capacity); }

    // Grow the capacity of the HeapBuffer while conserving the current contents
    void ReservePreserving(size_t new_capacity);
    void reserve_preserving(size_t capacity) { ReservePreserving(capacity); }
    void reserve(size_t capacity) { ReservePreserving(capacity); }

    void Reset();
    void reset() { Reset(); }

    [[nodiscard]] DataType* Get() { return store_.get(); }
    [[nodiscard]] pointer   data() noexcept { return store_.get(); }

    template <typename T>
    [[nodiscard]] T* GetAs() noexcept
    {
        static_assert(!std::is_reference_v<T>, "T must not be a reference type");
        static_assert(IsByteEquivalent_v<T>, "Buffer reinterpretation only valid for byte-like types.");
        return reinterpret_cast<T*>(store_.get());
    }

    size_t Capacity() const { return store_ ? capacity_ : 0U; }
    bool   IsEmpty() const { return store_ == nullptr; }

    DataType* get() { return store_.get(); }
    size_t    capacity() const { return Capacity(); }
    bool      empty() const { return IsEmpty(); }

  private:
    size_t capacity_{ 0 };
    Store  store_;
};

// Now a pool of heap buffers to avoid repeated allocations/deallocations
// NOTE: This class is *NOT* copyable, only movable
class HeapBufferPool : public std::enable_shared_from_this<HeapBufferPool>
{
  public:
    using DataBuffer = HeapBuffer;
    using DataType   = DataBuffer::DataType;
    using SizeType   = size_t;
    using PoolPtr    = std::shared_ptr<HeapBufferPool>;

    // Wrapper around DataBuffer that returns to the pool on destruction
    // NOTE: This class is *NOT* copyable, only movable
    // NOTE: The pool_ weak_ptr is used to avoid circular references
    class Entry : public DataBuffer
    {
      public:
        using Base = DataBuffer;
        using Pool = HeapBufferPool;
        friend Pool;

        ~Entry() noexcept;

        Entry(const Entry&)            = delete;
        Entry& operator=(const Entry&) = delete;

        Entry(Entry&& other) noexcept;

        Entry& operator=(Entry&& other) noexcept;
        Entry() = default;

      private:
        Entry(Pool* pool, size_t size) : DataBuffer(size), pool_(pool) {}
        void DisavowPool() { pool_ = nullptr; }

        // Pool is guarded by a refcount of Acquire'd Entry objects
        Pool* pool_ = nullptr;
    };

    Entry Acquire(size_t size);

    void Reset() noexcept;
    void clear() { Reset(); }

    // Since the entry destructor needs to return to the pool, we need to use a shared_ptr.
    static PoolPtr Create(size_t max_entries = kDefaultMaxCount)
    {
        // Can't use make_shared as the constructor is private
        return PoolPtr(new HeapBufferPool(max_entries));
    }
    HeapBufferPool(const HeapBufferPool&) = delete;
    HeapBufferPool(HeapBufferPool&&)      = delete;

    ~HeapBufferPool();

  private:
    friend Entry::~Entry() noexcept;
    void Release(Entry&& entry) noexcept;

    // NOTE: This is a WAG.  Current designed usage is 1 except during preloading, which doesn't recur
    static constexpr size_t kDefaultMaxCount = 16;
    HeapBufferPool(size_t max_entries = kDefaultMaxCount) : max_entries_(max_entries), store_() {}
    using Store         = std::deque<Entry>;
    size_t max_entries_ = kDefaultMaxCount;

    // NOTE: As Store isn't thread safe, acquired_ doesn't have to be atomic, if Store acquires a mutex
    //       acquired_ should be guarded by it as well
    size_t acquired_ = 0;
    Store  store_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_HEAP_BUFFER_H
