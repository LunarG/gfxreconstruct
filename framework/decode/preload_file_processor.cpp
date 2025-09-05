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
            success = ReadBlockHeader(&block_header);
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
    // If we have a block buffer, read from it first
    if (!block_buffers_.empty())
    {
        BlockBuffer& block_buffer = block_buffers_.front();
        bool         success      = block_buffer.ReadBytes(buffer, buffer_size);
        AdvanceBlockAtEof(block_buffer);
        if (success)
        {
            bytes_read_ += buffer_size;
        }
        return success;
    }

    // Otherwise read from the file as normal
    return Base::ReadBytes(buffer, buffer_size);
}

bool PreloadFileProcessor::SkipBytes(size_t skip_size)
{
    // If we have a block buffer, read from it first
    if (!block_buffers_.empty())
    {
        BlockBuffer& block_buffer = block_buffers_.front();
        bool         success      = block_buffer.SeekForward(skip_size);
        AdvanceBlockAtEof(block_buffer);
        return success;
    }

    // Otherwise read from the file as normal
    return Base::SkipBytes(skip_size);
}

void PreloadFileProcessor::AdvanceBlockAtEof(const BlockBuffer& block_buffer)
{
    if (block_buffer.IsEof())
    {
        block_buffers_.pop_front();
    }
}

bool PreloadFileProcessor::AddBlockBuffer(const format::BlockHeader& header)
{
    pending_block_buffers_.emplace_back(header);
    bool success = Base::ReadBytes(pending_block_buffers_.back().GetPayload(), header.size);
    if (!success)
    {
        pending_block_buffers_.pop_back();
    }
    return success;
}

bool PreloadFileProcessor::BlockBuffer::ReadBytes(void* buffer, size_t buffer_size)
{
    bool success = ReadBytes(buffer, buffer_size, read_pos_);
    if (success)
    {
        read_pos_ += buffer_size;
    }
    return success;
}

bool PreloadFileProcessor::BlockBuffer::ReadBytes(void* buffer, size_t buffer_size, size_t at) const
{
    if (IsAvailableAt(buffer_size, at))
    {
        memcpy(buffer, data_.get() + at, buffer_size);
        return true;
    }
    return false;
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
            if (Read<format::MarkerType>(marker_type, sizeof(format::BlockHeader)))
            {
                return file_processor.IsFrameDelimiter(base_type, marker_type);
            }
            break;
        case format::BlockType::kFunctionCallBlock:
        case format::BlockType::kMethodCallBlock:
            format::ApiCallId call_id;
            if (Read<format::ApiCallId>(call_id, sizeof(format::BlockHeader)))
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
