/*
** Copyright (c) 2025 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
**
* copy of this software and associated documentation files (the "Software"),
** to deal in the Software without
* restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute,
* sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do
* so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be
* included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT
* WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
**
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
* FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#include "util/file_input_stream.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

bool FStreamFileInputStream::Open(const std::string& filename)
{
    if (IsOpen())
    {
        Close();
    }

    const int  result  = util::platform::FileOpen(&fd_, filename.c_str(), "rb");
    const bool success = result == 0;

    if (success)
    {
        filename_ = filename;
    }
    return success;
}

void FStreamFileInputStream::Close()
{
    if (fd_)
    {
        util::platform::FileClose(fd_);
        fd_ = nullptr;
    }
}

bool FStreamFileInputStream::FileSeek(int64_t offset, util::platform::FileSeekOrigin origin)
{
    if (fd_)
    {
        if (read_ahead_bytes_ && (origin == util::platform::FileSeekOrigin::FileSeekCurrent))
        {
            // The file read pos is read_ahead_bytes_ further, than the caller thinks it is so the relative offset must
            // be adjusted
            if (offset > 0 && (read_ahead_bytes_ >= offset))
            {
                // This is a forward seek, so we shouldn't assume the file can be rewound, therefore adjust the seek
                // Offset is positive and in size_t range
                const size_t u_offset = static_cast<size_t>(offset);
                read_ahead_bytes_ -= u_offset;
                if (read_ahead_bytes_ == 0)
                {
                    read_ahead_offset_ = 0;
                }
                else
                {
                    read_ahead_offset_ += u_offset;
                }

                // The seek was contained within the read ahead bytes
                return true; // vini vidi quaesivi (we came, we saw, we sought)
            }
            else
            {
                // Either the original offset was negative or beyond the peeked region, so it's fair to just adjust it
                // read_ahead_bytes_ is positive and <= kReadAheadBufferSize which is << int64_t max
                offset = offset - static_cast<int64_t>(read_ahead_bytes_);
            }
        }

        // The seek position is now both the FILE and the classes read position
        read_ahead_bytes_  = 0;
        read_ahead_offset_ = 0;

        return util::platform::FileSeek(fd_, offset, origin);
    }
    return false;
}

int64_t FStreamFileInputStream::Tell() const
{
    if (fd_)
    {
        int64_t pos = util::platform::FileTell(fd_);
        if (pos >= 0)
        {
            return pos - static_cast<int64_t>(read_ahead_bytes_);
        }
    }
    return -1;
}

size_t FStreamFileInputStream::ReadFromReadAheadBuffer(void* buffer, size_t bytes)
{
    char* dest = static_cast<char*>(buffer);

    size_t copy_bytes = 0;
    if (read_ahead_bytes_)
    {
        // Get the data from the read ahead buffer up to the whole remaining contents of it (read_ahead_bytes_ bytes)
        copy_bytes = std::min(bytes, read_ahead_bytes_);
        std::memcpy(dest, &read_ahead_buffer_[read_ahead_offset_], copy_bytes);
        if (copy_bytes == read_ahead_bytes_)
        {
            // All read ahead bytes read, reset the read_ahead_buffer_ state to empty
            read_ahead_bytes_  = 0;
            read_ahead_offset_ = 0;
        }
        else
        {
            // Update the read ahead buffer state to reflect the consumed bytes
            read_ahead_bytes_ -= copy_bytes;
            read_ahead_offset_ += copy_bytes;
            GFXRECON_ASSERT(read_ahead_bytes_ != 0);
        }
    }

    size_t remain_bytes = bytes - copy_bytes;
    if ((remain_bytes > 0) && (remain_bytes < kReadAheadBufferSize))
    {
        // If the remaining bytes to read is less than the read-ahead buffer size, fill the read-ahead buffer
        // even if it saves only a few bytes reading from the file
        GFXRECON_ASSERT(read_ahead_bytes_ == 0);
        GFXRECON_ASSERT(read_ahead_offset_ == 0);
        char*        tail        = static_cast<char*>(buffer) + copy_bytes;
        const size_t bytes_read  = util::platform::FileReadBytes(&read_ahead_buffer_[0], kReadAheadBufferSize, fd_);
        const size_t remain_read = std::min(remain_bytes, bytes_read);
        std::memcpy(tail, &read_ahead_buffer_[0], remain_read);

        copy_bytes += remain_read;
        read_ahead_offset_ = remain_read;
        read_ahead_bytes_  = bytes_read - remain_read;
    }

    return copy_bytes;
}

bool FStreamFileInputStream::ReadBytes(void* buffer, size_t bytes)
{
    GFXRECON_ASSERT(fd_);
    char* dest    = static_cast<char*>(buffer);
    bool  success = true;

    // Get whatever part of the request read data from the read ahead buffer if present
    size_t copy_bytes = ReadFromReadAheadBuffer(dest, bytes);
    bytes -= copy_bytes;

    if (bytes)
    {
        dest += copy_bytes;
        success = util::platform::FileRead(dest, bytes, fd_);
    }

    return success;
}

// The goal of PeekBytes is to have a small read-ahead capability for reading things
// like protocol block headers or sizes.  This is implemented using the read_ahead_buffer_,
// which also serves the ReadBytes function for small reads, and to reduce system calls.
size_t FStreamFileInputStream::PeekBytes(void* buffer, size_t bytes)
{
    GFXRECON_ASSERT(fd_);

    // Limit to the maximum number of peeked bytes
    bytes = std::min(bytes, kMaxPeekBytes);

    if (read_ahead_bytes_ < bytes)
    {
        // We don't have all the bytes we need peeked already, shift existing bytes down and refill the buffer
        std::memmove(&read_ahead_buffer_[0], &read_ahead_buffer_[read_ahead_offset_], read_ahead_bytes_);

        // Fill the remainder of the read_ahead_buffer_
        char*        read_ahead = &read_ahead_buffer_[read_ahead_bytes_];
        const size_t bytes_fill = kReadAheadBufferSize - read_ahead_bytes_; // fill the rest of the buffer
        const size_t bytes_read = util::platform::FileReadBytes(read_ahead, bytes_fill, fd_);

        // This read may be less than bytes_fill at EOF, which is why we track read_ahead_bytes_ separately
        read_ahead_bytes_ += bytes_read;
        read_ahead_offset_ = 0;
    }

    // Note that at EOF read_ahead_bytes_ may be < bytes requested, even after attempting to fill the buffer
    const size_t bytes_to_copy = std::min(bytes, read_ahead_bytes_);
    std::memcpy(buffer, &read_ahead_buffer_[read_ahead_offset_], bytes_to_copy);

    return bytes_to_copy;
}

bool FStreamFileInputStream::ReadOverwriteSpan(const size_t bytes, DataSpan& span)
{
    span.Reset(buffer_pool_, bytes);
    bool success = ReadBytes(const_cast<char*>(span.GetDataAs<const char>()), bytes);
    return success;
}

DataSpan FStreamFileInputStream::ReadSpan(const size_t bytes)
{
    auto  pool_entry = buffer_pool_->Acquire(bytes);
    char* buffer     = pool_entry.GetAs<char>();
    bool  success    = ReadBytes(buffer, bytes);
    if (success)
    {
        return DataSpan(std::move(pool_entry), bytes);
    }
    return DataSpan();
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
