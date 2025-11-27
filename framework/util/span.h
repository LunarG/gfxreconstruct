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

#ifndef GFXRECON_UTIL_SPAN_H
#define GFXRECON_UTIL_SPAN_H

#include "util/heap_buffer.h"
#include "util/type_traits_extras.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// Back porting a portion from C++20
// Dynamic extent only
template <typename T>
class Span
{
  public:
    using element_type    = T;
    using value_type      = std::remove_cv_t<T>;
    using size_type       = std::size_t;
    using difference_type = std::ptrdiff_t;
    using pointer         = T*;
    using const_pointer   = const T*;
    using reference       = T&;
    using const_reference = const T&;

    // This is where we get lazy about the backport
    using iterator       = pointer;
    using const_iterator = const_pointer;

    // No extent parameter
    constexpr Span() noexcept : data_(nullptr), size_(0U) {}
    constexpr Span(pointer ptr, size_type count) noexcept : data_(ptr), size_(count)
    {
        GFXRECON_ASSERT((data_ != nullptr) || (count == 0));
    }

    Span(Span&&)                 = default;
    Span(const Span&)            = default;
    Span& operator=(Span&&)      = default;
    Span& operator=(const Span&) = default;

    // Add other constructors as needed (c.f. YAGNI)

    constexpr iterator begin() noexcept { return data_; }
    constexpr iterator end() noexcept { return data_ ? data_ + size_ : data_; }

    constexpr iterator begin() const noexcept { return data_; }
    constexpr iterator end() const noexcept { return data_ ? data_ + size_ : data_; }

    constexpr const_iterator cbegin() const noexcept { return data_; }
    constexpr const_iterator cend() const noexcept { return data_ ? data_ + size_ : data_; }

    constexpr pointer       data() noexcept { return data_; }
    constexpr const_pointer data() const noexcept { return data_; }

    [[nodiscard]] constexpr size_type size() const noexcept { return size_; }
    [[nodiscard]] constexpr bool      empty() const noexcept { return size_ == 0U; }

    // Non-standard accessor
    template <typename U>
    [[nodiscard]] const U* GetDataAs() const noexcept
    {
        static_assert(!std::is_reference_v<U>, "U must not be a reference type");
        static_assert(IsByteEquivalent_v<U>, "Buffer reinterpretation only valid for byte-like types.");
        return reinterpret_cast<const U*>(data_);
    }

  private:
    pointer   data_;
    size_type size_;
};

// A type anonymous union that can represent a data span from one of three sources:
// 1) A heap allocated buffer owned by this object
// 2) An entry from a heap buffer pool
// 3) A shared pointer to externally owned data
//
// NOTE: Access is designed to be read-only
// NOTE: Only one of the available sources will be active at any time.
// NOTE: This class is *NOT* copyable, only movable
// NOTE: Additional constructors could be added to support other data sources
//
// TODO: Some housekeeping
//       Add capacity assert in DataSpan(HeapBuffer&&, size_type).
//       Decide if empty() should reflect size_ == 0 rather than !IsValid(). Document.
class DataSpan
{
  public:
    using DataType = std::byte;
    using SizeType = size_t;

    // STL style types
    using value_type    = DataType;
    using size_type     = SizeType;
    using const_pointer = const DataType*;

    // Output Span
    using OutputSpan                      = Span<const DataType>;
    static constexpr size_type kRemainder = static_cast<size_type>(-1);

    using PoolEntry = HeapBufferPool::Entry;
    using SharedBuffer = std::shared_ptr<DataType>;

    // NOTE: we use SharedBuffer instead std::monostate, as
    //       1) it's a safe "empty" state
    //       2) it avoids issues with variant's triviality when using monostate (MSVC 17.14 specific)
    using Storage      = std::variant<SharedBuffer, HeapBuffer, PoolEntry>;
    using FirstVariant = std::variant_alternative_t<0, Storage>;
    // NOTE: When adding supported types
    //     * they must be move-assignable
    //     * they noexcept move-constructible
    //     * they noexcept move-assignable
    static_assert(std::is_move_assignable_v<Storage>,
                  "All variant members must be move-assignable for variant to be move-assignable.");
    static_assert(std::is_nothrow_move_constructible_v<Storage>,
                  "All variant members must have noexcept move constructors");
    static_assert(std::is_nothrow_move_assignable_v<Storage>,
                  "All variant members must have noexcept move assignment operators");

    // Could check for size as well, but we'll just say non-nullptr is valid, and ensure size is non-zero when data_ is
    // set
    [[nodiscard]] bool      IsValid() const { return data_ != nullptr; }
    [[nodiscard]] size_type Size() const { return size_; }

    [[nodiscard]] const_pointer GetData() const { return data_; }

    template <typename T>
    [[nodiscard]] const T* GetDataAs() const noexcept
    {
        static_assert(!std::is_reference_v<T>, "T must not be a reference type");
        static_assert(IsByteEquivalent_v<T>, "Buffer reinterpretation only valid for byte-like types.");
        return reinterpret_cast<const T*>(data_);
    }

    explicit operator bool() const { return IsValid(); }

    // Alternate STL style interface...
    [[nodiscard]] const_pointer data() const { return data_; }
    [[nodiscard]] size_type     size() const { return size_; }
    [[nodiscard]] bool          has_value() const { return IsValid(); }
    [[nodiscard]] bool          empty() const { return !IsValid(); }

    DataSpan() : size_(0), data_(nullptr) {}
    DataSpan(const DataSpan&) = delete;

    DataSpan(DataSpan&& other) noexcept : size_(other.size_), data_(other.data_), store_(std::move(other.store_))
    {
        other.Reset();
    }

    DataSpan& operator=(const DataSpan&) = delete;
    DataSpan& operator=(DataSpan&& from_span) noexcept
    {
        if (this != &from_span)
        {
            size_  = from_span.size_;
            data_  = from_span.data_;
            store_ = std::move(from_span.store_);

            from_span.Reset();
        }
        return *this;
    }

    DataSpan(const SharedBuffer& shared, size_type size) : size_(size), data_(shared.get()), store_(shared) {}
    DataSpan(SharedBuffer&& from_shared, size_type size) :
        size_(size), data_(from_shared.get()), store_(std::move(from_shared))
    {}

    DataSpan(HeapBuffer&& from_heap, size_type size) : size_(size)
    {
        store_.emplace<HeapBuffer>(std::move(from_heap));
        data_ = std::get<HeapBuffer>(store_).get();
    }

    DataSpan(PoolEntry&& from_pool, size_type size) : size_(size)
    {
        GFXRECON_ASSERT(size <= from_pool.Capacity());
        store_.emplace<PoolEntry>(std::move(from_pool));
        data_ = std::get<PoolEntry>(store_).Get();
    }

    void Reset() noexcept
    {
        data_ = nullptr;
        size_ = 0;
        store_.emplace<FirstVariant>();
    }
    void reset() noexcept { Reset(); }

    [[nodiscard]] OutputSpan AsSpan(size_type offset = 0, size_type count = kRemainder) const noexcept
    {
        const_pointer span_data  = nullptr;
        size_type     span_count = 0;
        if (data_ && (offset <= size_))
        {
            // Remainder can be zero, offset starting address can be "end"
            // If we ask for (size_, kRemainder) return empty span at end (it's what std::span does, apparently)
            const size_type remainder   = size_ - offset;
            const_pointer   offset_data = data_ + offset;
            if (count == kRemainder)
            {
                span_data  = offset_data;
                span_count = remainder;
            }
            else if (count <= remainder)
            {
                span_data  = offset_data;
                span_count = count;
            }
        }

        return OutputSpan(span_data, span_count);
    }

  private:
    size_type     size_{ 0 };
    const_pointer data_{ nullptr };

    Storage store_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_SPAN_H
