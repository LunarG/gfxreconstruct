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
    bool success = ReadBytesAt(buffer, buffer_size, read_pos_);
    if (success)
    {
        read_pos_ += buffer_size;
    }
    return success;
}

bool BlockBuffer::ReadBytesAt(void* buffer, size_t buffer_size, size_t at) const
{
    if (IsAvailableAt(buffer_size, at))
    {
        memcpy(buffer, block_span_.data() + at, buffer_size);
        return true;
    }
    return false;
}

BlockBuffer::BlockSpan BlockBuffer::ReadSpan(size_t buffer_size)
{
    if (IsAvailableAt(buffer_size, read_pos_))
    {
        const auto span_pos = read_pos_;
        read_pos_ += buffer_size;
        return BlockSpan(block_span_.data() + span_pos, buffer_size);
    }
    return BlockSpan();
}

// Create a block buffer from a block data span
// Reading the block header contents from the given span
BlockBuffer::BlockBuffer(util::DataSpan&& block_span) : read_pos_{ 0 }, block_span_(std::move(block_span))
{
    InitBlockHeaderFromSpan();
}

void BlockBuffer::InitBlockHeaderFromSpan()
{
    GFXRECON_ASSERT(block_span_.IsValid());

    // Block header is always at the start of the block span
    read_pos_          = 0;
    const bool success = ReadBytes(&header_, sizeof(format::BlockHeader));

    // Bad or incorrect block data should never be present
    const bool correct = success && block_span_.Size() == header_.size + sizeof(header_);
    assert(correct);

    // Only report failure to read header, span size validity checks are done later in calling code
    if (!success)
    {
        // Tag block buffer as invalid
        block_span_.Reset();
    }
}

// TODO: Remove this when preload_file_processor is converted to the common BlockParser/ParsedBlock approach
bool BlockBuffer::IsFrameDelimiter(const FileProcessor& file_processor) const
{
    if (!IsValid())
    {
        return false;
    }

    format::BlockType base_type = format::RemoveCompressedBlockBit(header_.type);
    switch (base_type)
    {
        case format::BlockType::kFrameMarkerBlock:
            format::MarkerType marker_type;
            if (ReadAt<format::MarkerType>(marker_type, sizeof(format::BlockHeader)))
            {
                return file_processor.IsFrameDelimiter(base_type, marker_type);
            }
            break;
        case format::BlockType::kFunctionCallBlock:
        case format::BlockType::kMethodCallBlock:
            format::ApiCallId call_id;
            if (ReadAt<format::ApiCallId>(call_id, sizeof(format::BlockHeader)))
            {
                return file_processor.IsFrameDelimiter(call_id);
            }
            break;

        case format::BlockType::kUnknownBlock:
        case format::BlockType::kStateMarkerBlock:
        case format::BlockType::kMetaDataBlock:
        case format::BlockType::kCompressedMetaDataBlock:
        case format::BlockType::kCompressedFunctionCallBlock:
        case format::BlockType::kCompressedMethodCallBlock:
        case format::BlockType::kAnnotation:
            break;
    }
    return false;
}

bool BlockBuffer::SeekForward(size_t size)
{
    if (IsAvailable(size))
    {
        read_pos_ += size;
        return true;
    }
    return false;
}

bool BlockBuffer::SeekTo(size_t location)
{
    if (location <= Size())
    {
        read_pos_ = location;
        return true;
    }
    return false;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
