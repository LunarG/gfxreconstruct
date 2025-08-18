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

PreloadFileProcessor::PreloadFileProcessor() : status_(PreloadStatus::kInactive) {}

void PreloadFileProcessor::PreloadNextFrames(size_t count)
{
    status_ = PreloadStatus::kRecord;
    while (--count != 0U)
    {
        ProcessNextFrame();
    }
    status_ = PreloadStatus::kReplay;
}

PreloadFileProcessor::PreloadBuffer::PreloadBuffer() : replay_offset_(0) {}

void PreloadFileProcessor::PreloadBuffer::Reserve(size_t size)
{
    container_.reserve(container_.size() + size);
}

size_t PreloadFileProcessor::PreloadBuffer::Read(void* destination, size_t destination_size)
{
    auto remaining_buffer_data = container_.size() - replay_offset_;
    auto read_size             = destination_size > remaining_buffer_data ? remaining_buffer_data : destination_size;
    memcpy(destination, &container_[replay_offset_], read_size);
    replay_offset_ += read_size;
    return read_size;
}

void PreloadFileProcessor::PreloadBuffer::Reset()
{
    container_.clear();
    container_.shrink_to_fit();
    replay_offset_ = 0;
}

template <format::BlockType BlockId, typename SubBlockId>
constexpr FileProcessor::ProcessBlockResult
PreloadFileProcessor::RecordPreloadBlock(const format::BlockHeader& block_header, SubBlockId sub_block_id)
{
    const bool is_frame_delimiter = IsFrameDelimiter(block_header.type, sub_block_id);
    const bool success            = ReadParameterBytes(block_header, sub_block_id, preload_buffer_);
    if (!success)
    {
        HandleBlockReadError(kErrorReadingBlockData, BlockReadErrorMsg<BlockId>("data"));
    }

    return { success, is_frame_delimiter };
}

bool PreloadFileProcessor::ProcessBlocks()
{
    return Base::ProcessBlocksImpl<Self>();
}

bool PreloadFileProcessor::ReadBytes(void* buffer, size_t buffer_size)
{
    size_t bytes_read = 0;
    if (status_ == PreloadStatus::kReplay)
    {
        bytes_read = preload_buffer_.Read(buffer, buffer_size);
        if (preload_buffer_.ReplayFinished())
        {
            status_ = PreloadStatus::kInactive;
        }
    }
    else
    {
        bytes_read = util::platform::FileRead(buffer, buffer_size, GetFileDescriptor());
    }

    bytes_read_ += bytes_read;
    return bytes_read == buffer_size;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
