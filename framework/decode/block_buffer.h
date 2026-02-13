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
    BlockBuffer() = default;

    using BlockSpan = util::Span<const uint8_t>;

    // Readers
    template <typename T>
    bool Read(T& value)
    {
        constexpr size_t size = sizeof(value);
        if (IsAvailable(size))
        {
            memcpy(&value, cursor_, size);
            cursor_ += size;
            return true;
        }
        return false;
    }

    // No alignment guarantees, but none are assumed by the callers/decoders, or consumers
    bool      ReadBytes(void* buffer, size_t buffer_size);
    BlockSpan ReadSpan(size_t buffer_size);

    // Accessors
    // Validity means that it has a payload and the payload size is consistent with the block header
    // Don't assert on header_ as that's what we're checking.
    bool IsValid() const { return (header_ != nullptr) && (Size() == (Header().size + sizeof(format::BlockHeader))); }
    const format::BlockHeader& Header() const
    {
        AssertValidPointers();
        return *header_;
    }
    size_t Size() const
    {
        AssertValidPointers();
        return end_ - GetData();
    }
    const uint8_t* GetData() const
    {
        AssertValidPointers();
        return reinterpret_cast<uint8_t*>(header_);
    }
    size_t ReadPos() const
    {
        AssertValidPointers();
        return cursor_ - GetData();
    }
    bool IsAvailable(size_t size) const noexcept
    {
        AssertValidPointers();
        return (cursor_ + size) <= end_;
    }
    size_t Remainder() const
    {
        AssertValidPointers();
        GFXRECON_ASSERT(end_ >= cursor_);
        return end_ - cursor_;
    }

    // Life cycle management
    void Reset(uint8_t* data, size_t size);
    void Clear()
    {
        header_ = 0;
        cursor_ = 0;
        end_    = nullptr;
    };

  private:
    // Make sure the accessors are only called when the pointers are valid.
    // It's an emptpy function on Release, but it should be eliminated by the optimizer.
    void AssertValidPointers() const
    {
        GFXRECON_ASSERT(header_ != nullptr);
        GFXRECON_ASSERT(cursor_ != nullptr);
        GFXRECON_ASSERT(end_ != nullptr);
    }

    format::BlockHeader* header_{ nullptr };
    uint8_t*             cursor_{ nullptr };
    uint8_t*             end_{ nullptr };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
#endif // GFXRECON_DECODE_BLOCK_BUFFER_H
