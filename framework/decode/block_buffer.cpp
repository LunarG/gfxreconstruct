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

#include "decode/block_buffer.h"
// TODO: Remove file_processor.h when preload_file_processor is converted to the common BlockParser/ParsedBlock approach
#include "decode/file_processor.h"
#include "format/format_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

bool BlockBuffer::ReadBytes(void* buffer, size_t buffer_size)
{
    if (IsAvailable(buffer_size))
    {
        memcpy(buffer, cursor_, buffer_size);
        cursor_ += buffer_size;
        return true;
    }
    return false;
}

BlockBuffer::BlockSpan BlockBuffer::ReadSpan(size_t buffer_size)
{
    if (IsAvailable(buffer_size))
    {
        const auto span_data = cursor_;
        cursor_ += buffer_size;
        return BlockSpan(span_data, buffer_size);
    }
    return BlockSpan();
}

void BlockBuffer::Reset(uint8_t* buffer, size_t size)
{
    // Block header is always at the start of the block span
    // and buffer must be allocated to be usable as a blockheader ptr.
    GFXRECON_ASSERT(util::is_aligned_for<format::BlockHeader>(buffer));
    GFXRECON_ASSERT(buffer != nullptr);

    // Reset read position and block span
    header_ = reinterpret_cast<format::BlockHeader*>(buffer);
    cursor_ = buffer + sizeof(format::BlockHeader);
    end_    = cursor_ + header_->size;

    GFXRECON_ASSERT(Size() == size);
    GFXRECON_ASSERT(Size() == (Header().size + sizeof(format::BlockHeader)));
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
