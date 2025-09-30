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
#ifndef GFXRECON_UTIL_FILE_INPUT_STREAM_H
#define GFXRECON_UTIL_FILE_INPUT_STREAM_H

#include "util/heap_buffer.h"
#include "util/logging.h"
#include "util/platform.h"

#include <type_traits>
#include <variant>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// DataSpan supporting code
struct DataRange
{
    int64_t offset = 0;
    size_t  size   = 0U;

    int64_t RelativeOffset(int64_t absolute_offset) const { return absolute_offset - offset; }
    bool    IsEmpty() const { return size == 0; }
    bool    Contains(int64_t access_offset) const;
    bool    Contains(const DataRange& range) const;
};

// An type anonymous union that can represent a data span from one of three sources:
// 1) A heap allocated buffer owned by this object
// 2) An entry from a heap buffer pool
// 3) A borrowed data pointer, not owned by this object
//
// NOTE: Access is designed to be read-only
// NOTE: Only one of the available sources will be active at any time.
// NOTE: This class is *NOT* copyable, only movable
// NOTE: Additional constructors could be added to support other data sources
//
//
// NOTE: Currently only non-owning subspans are supported, but require explicit use of a tag type
class DataSpan
{
  public:
    using DataType = char;
    using SizeType = size_t;

    // STL style types
    using value_type    = DataType;
    using size_type     = SizeType;
    using const_pointer = const DataType*;

    using PoolEntry = HeapBufferPool::Entry;

    struct BorrowedBuffer
    {
        const DataType* data;
        // As we create subspans, we need might want know the remaining capacity after offsets
        // const size_type capacity;
    };

    using Storage = std::variant<std::monostate, HeapBuffer, PoolEntry, BorrowedBuffer>;
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
    bool          IsValid() const { return data_ != nullptr; }
    size_type     Size() const { return size_; }
    const_pointer GetData() const { return data_; }
    template <typename T>
    const T* GetDataAs()
    {
        return reinterpret_cast<const T*>(data_);
    }

    explicit operator bool() const { return IsValid(); }

    // Alternate STL style interface...
    const_pointer data() const { return data_; }
    size_type     size() const { return size_; }
    bool          has_value() const { return IsValid(); }
    bool          empty() const { return !IsValid(); }

    DataSpan() : size_(0), data_(nullptr), store_(std::monostate()) {}
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

    DataSpan(HeapBuffer&& from_heap, size_t size) : size_(size)
    {
        store_.emplace<HeapBuffer>(std::move(from_heap));
        data_ = std::get<HeapBuffer>(store_).get();
    }

    DataSpan(const DataType* borrowed_data, size_t size) :
        size_(size), data_(borrowed_data), store_(BorrowedBuffer{ borrowed_data })
    {}

    DataSpan(PoolEntry&& from_pool, size_t size) : size_(size)
    {
        GFXRECON_ASSERT(size <= from_pool.Capacity());
        store_.emplace<PoolEntry>(std::move(from_pool));
        data_ = std::get<PoolEntry>(store_).Get();
    }

    void Reset() noexcept
    {
        data_ = nullptr;
        size_ = 0;
        store_.emplace<std::monostate>();
    }
    void reset() noexcept { Reset(); }

    // Make a borrowed data subspan from offset, offset+count (or to end if count is 0)
    // NOTE: We might want to add similar subspan support for retaining shared ownership of
    //       of shared ownership types
    struct NonOwningTag
    {};

    DataSpan(const DataSpan& other, const NonOwningTag&, size_t offset, size_t count = 0) noexcept
    {
        if (!other.IsValid() || (offset >= other.size_))
        {
            Reset();
            return;
        }

        const size_t remainder = other.size_ - offset;
        if (count == 0)
        {
            count = remainder;
        }

        if (count > remainder)
        {
            Reset();
            return;
        }

        data_ = other.data_ + offset;
        size_ = count;
        store_.emplace<BorrowedBuffer>(BorrowedBuffer{ data_ });
    }

  private:
    size_t        size_{ 0 };
    const_pointer data_{ nullptr };

    Storage store_;
};

class FStreamFileInputStream
{
  public:
    using BufferPool    = HeapBufferPool;
    using BufferPoolPtr = BufferPool::PoolPtr;

    FStreamFileInputStream() : filename_(), fd_(nullptr), buffer_pool_(BufferPool::Create()) {}
    FStreamFileInputStream(const FStreamFileInputStream&)            = delete;
    FStreamFileInputStream& operator=(const FStreamFileInputStream&) = delete;

    ~FStreamFileInputStream() { Close(); }

    const std::string& GetFilename() const { return filename_; }

    bool IsOpen() const { return fd_ != nullptr; }
    bool IsEof() const { return IsOpen() && (feof(fd_) != 0); }
    bool IsError() const { return IsOpen() && (ferror(fd_) != 0); }
    bool IsReady() const { return IsOpen() && !IsEof() && !IsError(); }

    bool Open(const std::string& filename);
    void Close();
    bool FileSeek(int64_t offset, util::platform::FileSeekOrigin origin);
    bool ReadBytes(void* buffer, size_t bytes);
    bool     PeekBytes(void* buffer, size_t bytes);
    DataSpan ReadSpan(const size_t bytes);

    explicit operator bool() const { return IsOpen(); }

  protected:
    size_t ReadFromPeekBuffer(void* buffer, size_t bytes);

    std::string filename_;
    FILE*       fd_{ nullptr };
    BufferPoolPtr buffer_pool_;
    size_t        peek_bytes_  = 0U;
    size_t        peek_offset_ = 0U;
    HeapBuffer    peek_buffer_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_FILE_INPUT_STREAM_H
