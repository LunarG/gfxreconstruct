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
    // Block processing will update current_frame_number_, so save and restore it,
    // as callers rely on it remaining unchanged by preload.
    const uint64_t save_current_frame = current_frame_number_;
    uint64_t       preload_frame      = save_current_frame;
    bool           success            = true;
    while (--count != 0U && success)
    {
        uint64_t preload_frame = current_frame_number_;
        success                = DoProcessNextFrame([this]() { return this->PreloadBlocksOneFrame(); });
        if (success)
        {
            if (current_frame_number_ == preload_frame)
            {
                // Deal with the frame marker after implied frame kFunctionCallBlock frame boundary case
                // Append the blocks leading up to the frame marker to the previous frame
                GFXRECON_ASSERT(current_frame_number_ == (kFirstFrame + 1));
                GFXRECON_ASSERT(!preload_frames_.empty());
                auto& prev_frame = preload_frames_.back().blocks;
                prev_frame.insert(prev_frame.end(),
                                  std::make_move_iterator(pending_parsed_blocks_.begin()),
                                  std::make_move_iterator(pending_parsed_blocks_.end()));
            }
            else
            {
                preload_frames_.emplace_back(preload_frame, std::move(pending_parsed_blocks_));
                preload_frame++;
            }
        }
    }

    // Set up the garbage frames for cleanup after replay
    replayed_preload_frames_.clear();
    replayed_preload_frames_.reserve(preload_frames_.size());

    // Restore saved frame number callers expect it to be unchanged by preload
    current_frame_number_ = save_current_frame;
}

bool PreloadFileProcessor::PreloadBlocksOneFrame()
{
    // Use queue-optimized to set early decompression for "small" parsed blocks
    block_parser_->SetDecompressionPolicy(BlockParser::DecompressionPolicy::kQueueOptimized);
    DispatchFunction dispatch = [this](uint64_t block_index, ParsedBlock& block) {
        pending_parsed_blocks_.emplace_back(block_index, std::move(block));
        return ProcessBlockState::kRunning;
    };

    ProcessBlockState process_result = ProcessBlocks(dispatch, false /* check decoder completion */);
    return ContinueProcessing(process_result);
}

void PreloadFileProcessor::CleanupReplay()
{
    // Clear out preloaded frames that have been replayed
    replayed_preload_frames_.clear();
    replayed_preload_frames_.shrink_to_fit();
}

bool PreloadFileProcessor::ProcessBlocksOneFrame()
{
    // Passthrough if no preloaded frame.
    if (preload_frames_.empty())
    {
        CleanupReplay();
        return FileProcessor::ProcessBlocksOneFrame();
    }

    PreloadedFrame&   frame          = preload_frames_.front();
    ProcessBlockState process_result = ReplayOneFrame(frame);

    // Defer cleanup of preloaded frames to avoid contaminating performance measurements during replay
    replayed_preload_frames_.emplace_back(std::move(frame));
    preload_frames_.pop_front();

    if (process_result == ProcessBlockState::kFrameBoundary)
    {
        current_frame_number_++;
    }

    return ContinueProcessing(process_result);
}

FileProcessor::ProcessBlockState PreloadFileProcessor::ReplayOneFrame(PreloadedFrame& frame)
{
    BlockParser&    block_parser = GetBlockParser();
    DispatchVisitor dispatch_visitor(decoders_, annotation_handler_);
    SetDecoderFrameNumber(frame.frame_number);

    ProcessBlockState process_state = ProcessBlockState::kFrameBoundary;
    for (auto& queued_block : frame.blocks)
    {
        uint64_t block_index = queued_block.block_index;
        if (!ContinueDecoding(block_index, true /* check decoder completion */))
        {
            process_state = ProcessBlockState::kEndProcessing;
            break;
        }

        // We assume that only known, vistable blocks were preloaded
        ParsedBlock& parsed_block = queued_block.block;
        GFXRECON_ASSERT(parsed_block.IsVisitable());

        bool decompressed = false;
        if (parsed_block.NeedsDecompression())
        {
            if (!parsed_block.Decompress(block_parser))
            {
                process_state = ProcessBlockState::kError;
                break;
            }
            decompressed = true;
        }

        SetDecoderBlockIndex(block_index);
        std::visit(dispatch_visitor, parsed_block.GetArgs());
        block_index++;

        // Cleanup large decompressed blocks after processing to reduce memory usage during replay
        if (decompressed)
        {
            parsed_block.TrimBlock(block_parser);
        }
    }

    return process_state;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
