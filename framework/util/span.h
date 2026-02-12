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

    // NOTE: No bounds checking, nor "dynamic extent" support
    Span subspan(size_type offset, size_type size) const noexcept
    {
        GFXRECON_ASSERT((offset + size) <= size_);
        return Span(data_ + offset, size);
    }

  private:
    pointer   data_;
    size_type size_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_SPAN_H
