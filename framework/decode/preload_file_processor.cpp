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
    preload_block_data_ = std::move(pending_block_data_);
}

bool PreloadFileProcessor::PreloadBlocksOneFrame()
{
    BlockBuffer block_buffer;
    bool        success = true;

    BlockParser block_parser([this](BlockIOError err, const char* message) { HandleBlockReadError(err, message); },
                             pool_,
                             compressor_.get());

    while (success)
    {
        PrintBlockInfo();
        success = ContinueDecoding();

        if (success)
        {
            success = ReadBlockBuffer(block_parser, block_buffer);
            if (success)
            {
                // Valid checks for the presence and size of the data span matching the header
                success = block_buffer.IsValid();

                if (success)
                {
                    // Note: in order to support kExecuteBlocksFromFile in preload, we need to add special case logic
                    //       to look for the meta data block here, and allow it to push itself on the stack, and then
                    //       add command counting here as well.
                    const bool end_of_frame = block_buffer.IsFrameDelimiter(*this);
                    // Record the block data for replay, Moves DataSpan out of BlockBuffer, so don't use after this.
                    // NOTE: It is intentional to only store only the data span to make preload lightweight a possible
                    pending_block_data_.emplace_back(std::move(block_buffer.ReleaseData()));
                    if (end_of_frame)
                    {
                        // GFXRECON_LOG_INFO("Frame delimiter encountered during preload, ending frame preload.");
                        break;
                    }
                }
                else
                {
                    std::string msg = "Failed to preload block data of size " +
                                      std::to_string(block_buffer.Header().size) + " for block type " +
                                      format::ToString(block_buffer.Header().type);
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

// Grab the block data off the front of the
bool PreloadFileProcessor::GetBlockBuffer(BlockParser& block_parser, BlockBuffer& block_buffer)
{
    // Quick escape
    if (preload_block_data_.empty())
    {
        return Base::GetBlockBuffer(block_parser, block_buffer);
    }

    block_buffer = BlockBuffer(std::move(preload_block_data_.front()));
    preload_block_data_.pop_front();

    // Caller expects read position just past header
    // Again the pattern is to validate the header presense, not span consistency
    bool success = block_buffer.SeekTo(sizeof(format::BlockHeader));

    // However, preload should never add data the doesn't result in a valid block_buffer.
    // Should have failed in preload.
    GFXRECON_ASSERT(block_buffer.IsValid());

    return success;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
