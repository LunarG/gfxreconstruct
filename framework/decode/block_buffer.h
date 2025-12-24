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

#ifndef GFXRECON_DECODE_BLOCK_BUFFER_H
#define GFXRECON_DECODE_BLOCK_BUFFER_H

#include "format/format.h"
#include "util/span.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// TODO: Remove this when preload_file_processor is converted to the common BlockParser/ParsedBlock approach
class FileProcessor;

class BlockBuffer
{
  public:
    using BlockSpan = util::DataSpan::OutputSpan;
    // Validity means that it has a payload and the payload size is consistent with the block header
    bool IsValid() const
    {
        return (block_span_.data() != nullptr) && (block_span_.size() == (header_.size + sizeof(format::BlockHeader)));
    }
    bool IsEof() const { return read_pos_ >= block_span_.size(); }

    template <typename T>
    bool Read(T& value)
    {
        bool success = ReadAt<T>(value, read_pos_);
        if (success)
        {
            read_pos_ += sizeof(T);
        }
        return success;
    }

    template <typename T>
    bool ReadAt(T& value, size_t at) const
    {
        // Ensure that this isn't being misused.
        static_assert(std::is_trivially_copyable_v<T>, "Read<T> requires a trivially copyable type");
        if (IsAvailableAt(sizeof(value), at))
        {
            memcpy(&value, block_span_.data() + at, sizeof(value));
            return true;
        }
        return false;
    }

    bool ReadBytes(void* buffer, size_t buffer_size);
    bool ReadBytesAt(void* buffer, size_t buffer_size, size_t at) const;

    BlockSpan ReadSpan(size_t buffer_size);
    BlockSpan ReadSpanAt(size_t buffer_size, size_t at);

    size_t                     Size() const { return block_span_.size(); }
    const format::BlockHeader& Header() const { return header_; }

    size_t ReadPos() const { return read_pos_; }
    size_t Remainder() const
    {
        GFXRECON_ASSERT(Size() >= read_pos_);
        return Size() - read_pos_;
    }

    BlockBuffer() = default;
    BlockBuffer(util::DataSpan&& block_span);

    // TODO: Remove this when preload_file_processor is converted to the common BlockParser/ParsedBlock approach
    bool IsFrameDelimiter(const FileProcessor& file_processor) const;

    void Reset(util::DataSpan&& block_span);
    void Reset()
    {
        read_pos_ = 0;
        block_span_.Reset();
    };

    util::DataSpan&& ReleaseData() { return std::move(block_span_); }
    bool             SeekForward(size_t size);
    bool             SeekTo(size_t size);

    bool IsAvailable(size_t size) const { return IsAvailableAt(size, read_pos_); }
    bool IsAvailableAt(size_t size, size_t at) const { return Size() >= (at + size); }

  private:
    void                InitBlockHeaderFromSpan();
    size_t              read_pos_{ 0 };
    util::DataSpan      block_span_;
    format::BlockHeader header_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
#endif // GFXRECON_DECODE_BLOCK_BUFFER_H
