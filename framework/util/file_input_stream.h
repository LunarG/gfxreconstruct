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

#include "util/logging.h"
#include "util/platform.h"
#include "util/span.h"

#include <array>
#include <cstddef>
#include <type_traits>
#include <variant>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

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
    bool IsEof() const { return IsOpen() && (read_ahead_bytes_ == 0) && (feof(fd_) != 0); }
    bool IsError() const { return IsOpen() && (ferror(fd_) != 0); }
    bool IsReady() const { return IsOpen() && !IsEof() && !IsError(); }

    bool     Open(const std::string& filename);
    void     Close();
    bool     FileSeek(int64_t offset, util::platform::FileSeekOrigin origin);
    int64_t  Tell() const;
    bool     ReadBytes(void* buffer, size_t bytes);
    size_t   PeekBytes(void* buffer, size_t bytes);
    bool     ReadOverwriteSpan(const size_t bytes, DataSpan& span);
    DataSpan ReadSpan(const size_t bytes);

    explicit operator bool() const { return IsOpen(); }

    // This saves on fread calls for small reads/peeks.  1024 is as big
    // as useful for performance if using fread.  If we go larger we should
    // go to read/_read system calls, directly and avoid the fread buffer
    // entirely.
    constexpr static size_t kReadAheadBufferSize = 1024U;

    // Design assumes kMaxPeekBytes << kReadAheadBufferSize, as we move data when peeking would
    // exceed the read ahead buffer size, and we want to avoid moving large amounts of data.
    constexpr static size_t kMaxPeekBytes = 32U;

    size_t GetMaxPeekBytes() const { return kMaxPeekBytes; }

  protected:
    size_t ReadFromReadAheadBuffer(void* buffer, size_t bytes);

    std::string   filename_;
    FILE*         fd_{ nullptr };
    BufferPoolPtr buffer_pool_;
    size_t        read_ahead_bytes_  = 0U;
    size_t        read_ahead_offset_ = 0U;

    std::array<char, kReadAheadBufferSize> read_ahead_buffer_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_FILE_INPUT_STREAM_H
