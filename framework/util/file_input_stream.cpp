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
        if (peek_bytes_ && (origin == util::platform::FileSeekOrigin::FileSeekCurrent))
        {
            // The file read pos is peek_bytes_ further, than the caller thinks it is so the relative offset must be
            // adjusted
            if (offset > 0 && (peek_bytes_ >= static_cast<size_t>(offset)))
            {
                // This is a forward seek, so we shouldn't assume the file can be rewound, therefore adjust the seek
                // Offset is positive and in size_t range
                const size_t u_offset = static_cast<size_t>(offset);
                peek_bytes_ -= u_offset;
                if (peek_bytes_ == 0)
                {
                    peek_offset_ = 0;
                }
                else
                {
                    peek_offset_ += u_offset;
                }

                // The seek was contained within the peeked bytes
                return true; // vini vidi quaesivi
            }
            else
            {
                // Either the original offset was negative or beyond the peeked region, so it's fair to just adjust it
                // Unless someone has peek'd all of size_t, this is safe on 64bit.
                GFXRECON_ASSERT(static_cast<int64_t>(peek_bytes_) <= std::numeric_limits<int64_t>::max());
                offset = offset - static_cast<int64_t>(peek_bytes_);
            }
        }

        // The seek position is now both the FILE and the classes read position
        peek_bytes_  = 0;
        peek_offset_ = 0;

        return util::platform::FileSeek(fd_, offset, origin);
    }
    return false;
}

size_t FStreamFileInputStream::ReadFromPeekBuffer(void* buffer, size_t bytes)
{
    GFXRECON_ASSERT(peek_bytes_);
    char* dest = static_cast<char*>(buffer);

    // Get the data from the peek buffer up to the whole remaining contents of it (peek_bytes_ bytes)
    size_t copy_bytes = std::min(bytes, peek_bytes_);
    std::memcpy(dest, peek_buffer_.Get() + peek_offset_, copy_bytes);
    if (copy_bytes == peek_bytes_)
    {
        // All peek bytes read, reset the peek_buffer_ state to empty
        peek_bytes_  = 0;
        peek_offset_ = 0;
    }
    else
    {
        // Update the peek buffer state to reflect the consumed bytes
        peek_bytes_ -= copy_bytes;
        peek_offset_ += copy_bytes;
        GFXRECON_ASSERT(peek_bytes_ != 0);
    }
    return copy_bytes;
}

bool FStreamFileInputStream::ReadBytes(void* buffer, size_t bytes)
{
    GFXRECON_ASSERT(fd_);
    char* dest    = static_cast<char*>(buffer);
    bool  success = true;

    if (peek_bytes_)
    {
        // Get whatever part of the request read data from the peek buffer is present
        size_t copy_bytes = ReadFromPeekBuffer(dest, bytes);
        bytes -= copy_bytes;
        dest += copy_bytes;
    }
    if (bytes)
        success = util::platform::FileRead(dest, bytes, fd_);

    return success;
}

// The goal of PeekBytes is to have a small read-ahead capability for reading things
// like protocol block headers or sizes.  For larger read-ahead use the read and seek
// methods on rewind-able streams.  If a "large read-ahead" is needed in the future
// for non-rewindable streams, consider adding full input-buffer suppport.
bool FStreamFileInputStream::PeekBytes(void* buffer, size_t bytes)
{
    GFXRECON_ASSERT(fd_);
    bool success = true;

    if (peek_bytes_ < bytes)
    {
        // We don't have all the bytes we need peeked already

        // Make sure we have the room to store them
        const size_t buffer_capacity = peek_buffer_.Capacity();
        if ((bytes > buffer_capacity) || (peek_offset_ > (buffer_capacity - bytes)))
        {
            // Adding more bytes at this offset would overflow the peek_buffer_.
            // Shifting them down may means that the ReservePreserving resize may be
            // no-op, or at least is kept to a minium
            std::memmove(peek_buffer_.Get(), peek_buffer_.Get() + peek_offset_, peek_bytes_);
            peek_offset_ = 0;
            peek_buffer_.ReservePreserving(bytes);
        }

        // Copy missing bytes to peek_buffer_
        std::byte*   dest         = peek_buffer_.Get() + peek_offset_ + peek_bytes_;
        const size_t bytes_needed = bytes - peek_bytes_; // we know bytes > peek_bytes as we are in the else clause
        success                   = util::platform::FileRead(dest, bytes_needed, fd_);
        if (success)
        {
            // We now hav bytes in peek_bytes_. We have the requested bytes pre-read from the stream.
            peek_bytes_ = bytes;
        }
    }

    if (success)
    {
        std::memcpy(buffer, peek_buffer_.Get() + peek_offset_, bytes);
    }

    return success;
}

DataSpan FStreamFileInputStream::ReadSpan(const size_t bytes)
{
    auto  pool_entry = buffer_pool_->Acquire(bytes);
    std::byte* buffer     = pool_entry.Get();
    bool  success    = ReadBytes(buffer, bytes);
    if (success)
    {
        return DataSpan(std::move(pool_entry), bytes);
    }
    return DataSpan();
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
