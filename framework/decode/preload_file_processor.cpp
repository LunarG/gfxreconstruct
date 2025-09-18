/*
** Copyright (c) 2023 LunarG, Inc.
** Copyright (c) 2023 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#include "decode/preload_file_processor.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

PreloadFileProcessor::PreloadFileProcessor() {}

void PreloadFileProcessor::PreloadNextFrames(size_t count)
{
    while (--count != 0U)
    {
        DoProcessNextFrame([this]() { return this->PreloadBlocksOneFrame(); });
    }
    block_buffers_ = std::move(pending_block_buffers_);
}

bool PreloadFileProcessor::PeekBytes(void* buffer, size_t buffer_size)
{
    // File entry is non-const to allow read bytes to be non-const (i.e. potentially reflect a stateful operation)
    // without forcing use of mutability
    const auto& active_file = file_stack_.back().active_file;
    assert(active_file);
    return active_file->PeekBytes(buffer, buffer_size);
}

bool PreloadFileProcessor::PeekBlockHeader(format::BlockHeader* block_header)
{
    assert(block_header != nullptr);

    bool success = false;

    if (PeekBytes(block_header, sizeof(*block_header)))
    {
        success = true;
    }

    return success;
}

bool PreloadFileProcessor::PreloadBlocksOneFrame()
{
    format::BlockHeader block_header;
    bool                success = true;

    while (success)
    {
        PrintBlockInfo();
        success = ContinueDecoding();

        if (success)
        {
            success = PeekBlockHeader(&block_header);
            if (success)
            {
                success = AddBlockBuffer(block_header);

                if (success)
                {
                    if (pending_block_buffers_.back().IsFrameDelimiter(*this))
                    {
                        // GFXRECON_LOG_INFO("Frame delimiter encountered during preload, ending frame preload.");
                        break;
                    }
                }
                else
                {
                    std::string msg = "Failed to preload block data of size " + std::to_string(block_header.size) +
                                      " for block type " + format::ToString(block_header.type);
                    HandleBlockReadError(kErrorReadingBlockData, msg.c_str());
                }
            }
            else
            {
                // We can succeed at EOF, if there are more files on the stack.
                success = HandleBlockEof("preload", false /* no frame or block info */);
            }
        }
    }

    return success;
}

bool PreloadFileProcessor::ReadBytes(void* buffer, size_t buffer_size)
{
    // Check for EOF at top of read, instead of at end of read, s.t.
    // the borrowed data spans in "ReadSpan" are valid until the then next Read operation
    BlockBuffer* block_buffer = GetCurrentBlockBuffer();

    // If we have a block buffer, read from it first
    if (block_buffer)
    {
        bool success = block_buffer->ReadBytes(buffer, buffer_size);
        if (success)
        {
            bytes_read_ += buffer_size;
        }
        return success;
    }

    // Otherwise read from the file as normal
    return Base::ReadBytes(buffer, buffer_size);
}

util::DataSpan PreloadFileProcessor::ReadSpan(size_t buffer_size)
{
    BlockBuffer* block_buffer = GetCurrentBlockBuffer();

    // If we have a block buffer, read from it first
    if (block_buffer)
    {
        util::DataSpan read_span = block_buffer->ReadSpan(buffer_size);
        if (read_span.IsValid())
        {
            bytes_read_ += read_span.size();
        }
        return read_span;
    }

    // Otherwise read from the file as normal
    return Base::ReadSpan(buffer_size);
}

bool PreloadFileProcessor::SkipBytes(size_t skip_size)
{
    // If we have a block buffer, read from it first
    BlockBuffer* block_buffer = GetCurrentBlockBuffer();
    if (block_buffer)
    {
        bool success = block_buffer->SeekForward(skip_size);
        return success;
    }

    // Otherwise read from the file as normal
    return Base::SkipBytes(skip_size);
}

// Gets current block buffer checking for EOF at top of read, instead of at end of read, s.t.
// the borrowed data spans in "ReadSpan" are valid until the then next Read operation
PreloadFileProcessor::BlockBuffer* PreloadFileProcessor::GetCurrentBlockBuffer()
{
    // Quick escape
    if (block_buffers_.empty())
        return nullptr;

    // I'd have to do this befor in in the loop, so define it once.
    auto get_block_buffer = [this]() {
        BlockBuffer* front_block_buffer = nullptr;
        if (!block_buffers_.empty())
        {
            front_block_buffer = &block_buffers_.front();
        }
        return front_block_buffer;
    };

    BlockBuffer* block_buffer = get_block_buffer();
    // The while loop allows for skipping empty blocks, which while not a current use case
    // is less fragile than not
    while (block_buffer && block_buffer->IsEof())
    {
        block_buffers_.pop_front();
        block_buffer = get_block_buffer();
    }
    return block_buffer;
}

bool PreloadFileProcessor::AddBlockBuffer(const format::BlockHeader& header)
{
    const size_t   total_block_size = header.size + sizeof(header);
    util::DataSpan block_span       = Base::ReadSpan(total_block_size);
    if (block_span.size() == total_block_size)
    {
        pending_block_buffers_.emplace_back(header, std::move(block_span));
        return true;
    }
    return false;
}

bool PreloadFileProcessor::BlockBuffer::ReadBytes(void* buffer, size_t buffer_size)
{
    bool success = ReadBytesAt(buffer, buffer_size, read_pos_);
    if (success)
    {
        read_pos_ += buffer_size;
    }
    return success;
}

bool PreloadFileProcessor::BlockBuffer::ReadBytesAt(void* buffer, size_t buffer_size, size_t at) const
{
    if (IsAvailableAt(buffer_size, at))
    {
        memcpy(buffer, block_span_.data() + at, buffer_size);
        return true;
    }
    return false;
}

util::DataSpan PreloadFileProcessor::BlockBuffer::ReadSpan(size_t buffer_size)
{
    util::DataSpan read_span = ReadSpanAt(buffer_size, read_pos_);
    if (read_span.IsValid())
    {
        read_pos_ += read_span.size();
    }
    return read_span;
}

util::DataSpan PreloadFileProcessor::BlockBuffer::ReadSpanAt(size_t buffer_size, size_t at)
{
    if (IsAvailableAt(buffer_size, at))
    {
        // Create a borrowed data span from our private buffer
        return util::DataSpan(block_span_.data() + at, buffer_size);
    }
    return util::DataSpan();
}

bool PreloadFileProcessor::BlockBuffer::IsFrameDelimiter(const FileProcessor& file_processor) const
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

bool PreloadFileProcessor::BlockBuffer::SeekForward(size_t size)
{
    if (IsAvailable(size))
    {
        read_pos_ += size;
        return true;
    }
    return false;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
