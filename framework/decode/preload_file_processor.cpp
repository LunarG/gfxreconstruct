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

#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

PreloadFileProcessor::PreloadFileProcessor() {}

void PreloadFileProcessor::PreloadNextFrames(size_t count)
{
    if (!IsFileValid())
    {
        error_state_ = CheckFileStatus();
        return;
    }

    // Block processing will update current_frame_number_, so save and restore it,
    // as callers rely on it remaining unchanged by preload.
    const uint64_t save_current_frame = current_frame_number_;

    // Escalate block reference policy to owned to retain backing store for preloaded blocks
    auto save_reference_policy = block_parser_->GetBlockReferencePolicy();
    if (save_reference_policy == ParsedBlock::BlockReferencePolicy::kNonOwnedReference)
    {
        // Only need to change if was non-owned
        block_parser_->SetBlockReferencePolicy(ParsedBlock::BlockReferencePolicy::kOwnedReferenceAsNeeded);
    }

    // Use queue-optimized to set early decompression for "small" parsed blocks
    auto save_decompression_policy = block_parser_->GetDecompressionPolicy();
    block_parser_->SetDecompressionPolicy(BlockParser::DecompressionPolicy::kQueueOptimized);

    preloaded_frames_.clear();
    preloaded_frames_.reserve(count);

    ProcessBlockState preload_result = ProcessBlockState::kFrameBoundary;
    while ((count != 0U) && (preload_result == ProcessBlockState::kFrameBoundary))
    {
        uint64_t         current_preload_frame = current_frame_number_;
        ParsedBlockQueue frame_blocks;
        preload_result = PreloadBlocksOneFrame(frame_blocks);

        if (preload_result != ProcessBlockState::kError)
        {
            // This is for the corner case where we are seeing an explicit frame boundary, for a file
            // that assumes implicit frame boundaries on specific function call blocks.
            // A WARNING is logged during block processing when this occurs.

            // We have two strategies to deal with this case:
            const bool frame_stutter = (preload_result == ProcessBlockState::kFrameBoundary) &&
                                       (current_frame_number_ == current_preload_frame);
            if (frame_stutter)
            {
                // Deal with the frame marker after implied frame kFunctionCallBlock frame boundary case
                GFXRECON_ASSERT(current_frame_number_ == (kFirstFrame + 1));
                if (preloaded_frames_.empty())
                {
                    // This is really part of the non-preloaded previous (first) frame,
                    // so immediately replay it to complete that frame
                    PreloadedFrame temp_frame(kFirstFrame);
                    temp_frame.AppendMovedBlocks(frame_blocks);
                    ProcessBlockState replay_result = ReplayOneFrame(temp_frame);
                    GFXRECON_ASSERT(replay_result == ProcessBlockState::kFrameBoundary);
                }
                else
                {
                    // Append the blocks leading up to the frame marker to the previous frame
                    // completing that frame with the stuttered frame marker
                    GFXRECON_ASSERT(!frame_blocks.empty());
                    preloaded_frames_.back()->AppendMovedBlocks(frame_blocks);
                }
            }
            else
            {
                // Normal case, just add the preloaded frame
                preloaded_frames_.emplace_back(std::make_unique<PreloadedFrame>(current_preload_frame));
                preloaded_frames_.back()->AppendMovedBlocks(frame_blocks);
                count--;
            }
        }
    }

    // Need to remember how preloading ended to know what to do after replay completes
    final_process_state_ = preload_result;

    if (count)
    {
        const uint64_t found = preloaded_frames_.size();
        const uint64_t total = count + found;
        GFXRECON_LOG_INFO("Preload did not load all measurement frames. %" PRIu64 " frames found, %" PRIu64 " expected",
                          found,
                          total);
    }

    current_preloaded_frame_ = preloaded_frames_.begin();

    // Restore the original parser policies
    block_parser_->SetBlockReferencePolicy(save_reference_policy);
    block_parser_->SetDecompressionPolicy(save_decompression_policy);

    // Restore saved frame number callers expect it to be unchanged by preload
    current_frame_number_ = save_current_frame;
}

FileProcessor::ProcessBlockState PreloadFileProcessor::PreloadBlocksOneFrame(ParsedBlockQueue& frame_queue)
{
    DispatchFunction dispatch = [&frame_queue](uint64_t block_index, ParsedBlock& block) {
        frame_queue.emplace_back(std::move(block));
        return ProcessBlockState::kRunning;
    };

    return ProcessBlocks(dispatch, false /* check decoder completion */);
}

bool PreloadFileProcessor::ProcessNextFrame()
{
    // Clean up preloaded frames if we're at the end of the preloaded frames.  It's done here
    // so that the clean up time is not measured in the measurement-frame-range timing.
    if (!preloaded_frames_.empty() && current_preloaded_frame_ == preloaded_frames_.end())
    {
        preloaded_frames_.clear();
        current_preloaded_frame_ = preloaded_frames_.end();
    }

    // Passthrough if no preloaded frames.
    if (preloaded_frames_.empty())
    {
        return FileProcessor::ProcessNextFrame();
    }

    PreloadedFrame&   frame          = *(current_preloaded_frame_->get());
    ProcessBlockState process_result = ReplayOneFrame(frame);
    ++current_preloaded_frame_;

    const bool at_end = (current_preloaded_frame_ == preloaded_frames_.end());
    if (at_end)
    {
        if (IsFrameBoundary(process_result) && IsFrameBoundary(final_process_state_))
        {
            // If we reached the end of preloaded frames on a frame boundary, increment the frame number
            current_frame_number_++;
        }
        // Return true only if both the replay and preload are in a continue state
        return ContinueProcessing(process_result) && ContinueProcessing(final_process_state_);
    }

    if (IsFrameBoundary(process_result))
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
        uint64_t block_index = queued_block.GetBlockIndex();
        if (!ContinueDecoding(block_index, true /* check decoder completion */))
        {
            process_state = ProcessBlockState::kEndProcessing;
            break;
        }

        // We assume that only known, vistable blocks were preloaded
        GFXRECON_ASSERT(queued_block.IsVisitable());

        if (queued_block.NeedsDecompression())
        {
            if (!queued_block.Decompress(block_parser))
            {
                process_state = ProcessBlockState::kError;
                break;
            }
        }

        dispatch_visitor.SetBlockIndex(block_index);
        std::visit(dispatch_visitor, queued_block.GetArgs());
    }

    return process_state;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
