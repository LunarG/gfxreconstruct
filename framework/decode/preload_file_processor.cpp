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

#include "decode/block_allocator.h"
#include "decode/preload_file_processor.h"
#include "util/logging.h"

#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

PreloadFileProcessor::PreloadFileProcessor() : working_uncompressed_store_(kWorkingStoreInitialSize) {}

void PreloadFileProcessor::PreloadNextFrames(size_t count)
{
    size_t expected_count = count;
    if (!IsFileValid())
    {
        error_state_ = CheckFileStatus();
        return;
    }

    // Block processing will update current_frame_number_, so save and restore it,
    // as callers rely on it remaining unchanged by preload.
    const uint64_t save_current_frame = current_frame_number_;

    // Escalate operation mode to enqueueing if needed, saving previous mode
    auto save_operation_mode = block_parser_->GetOperationMode();
    // NOTE: Preload only works when starting from immediate mode, currently, as there is no
    //       support for draining enqueued blocks back into immediate mode.
    GFXRECON_ASSERT(save_operation_mode == BlockParser::OperationMode::kImmediate);
    if (save_operation_mode == BlockParser::OperationMode::kImmediate)
    {
        // Only need to change if wasn't enqueueing already
        // When changing from Immediate need to clear out the last immediate block,
        // as StartBlock does it lazily, and thus the last will be present.
        // NOTE: This must be done before SetBatchSinkProc, or we'll record it to preload
        block_parser_->GetBlockAllocator().FlushBatch();
        block_parser_->SetOperationMode(BlockParser::OperationMode::kEnqueued);
    }

    // Set up block batch sink to collect preloaded blocks, as a single queue of batches.
    // Parsed blocks are tagged with frame boundaries when parsed.

    block_parser_->GetBlockAllocator().SetBatchSinkProc(
        [this](BlockBatch::BatchPtr&& completed_batch) { this->EnqueueBatch(std::move(completed_batch)); });

    // Use kAlways decompression policy to move the maximum amount of work outside the measurement loop
    auto save_decompression_policy = block_parser_->GetDecompressionPolicy();
    block_parser_->SetDecompressionPolicy(BlockParser::DecompressionPolicy::kAlways);

    // Multiple appended preload not supported.
    GFXRECON_ASSERT(!preload_head_);
    ResetPreload();

    ProcessBlockState preload_result = ProcessBlockState::kFrameBoundary;
    bool              first_preloaded_frame = true;
    while ((count != 0U) && (preload_result == ProcessBlockState::kFrameBoundary))
    {
        uint64_t         current_preload_frame = current_frame_number_;
        preload_result                         = PreloadBlocksOneFrame();

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
                if (first_preloaded_frame)
                {
                    // This is really part of the non-preloaded previous (first) frame,
                    // so immediately replay it to complete that frame
                    block_parser_->GetBlockAllocator().FlushBatch();
                    ProcessBlockState replay_result = ReplayOneFrame();
                    ResetPreload();
                    GFXRECON_ASSERT(replay_result == ProcessBlockState::kFrameBoundary);
                }
                else
                {
                    // Marking the preloaded queue as having a stuttered frame,
                    // and have replay skip the first frame boundary when replaying
                    GFXRECON_ASSERT(!first_preloaded_frame);
                    preload_contains_frame_stutter_ = true;
                }
            }
            else
            {
                // Normal case, just count the preloaded frame
                count--;
            }

            first_preloaded_frame = false;
        }
    }

    // Ensure we have even non-full batches
    block_parser_->GetBlockAllocator().FlushBatch();

    // Need to remember how preloading ended to know what to do after replay completes
    final_process_state_ = preload_result;

    if (count)
    {
        const uint64_t found = expected_count - count;
        const uint64_t total = expected_count;
        GFXRECON_LOG_INFO("Preload did not load all measurement frames. %" PRIu64 " frames found, %" PRIu64 " expected",
                          found,
                          total);
    }

    // Restore the original parser policies
    block_parser_->SetOperationMode(save_operation_mode);
    block_parser_->SetDecompressionPolicy(save_decompression_policy);
    block_parser_->GetBlockAllocator().ResetBatchSinkProc();

    // Restore saved frame number callers expect it to be unchanged by preload
    current_frame_number_ = save_current_frame;
}

void PreloadFileProcessor::ResetPreload()
{
    preload_head_  = BlockBatch::iterator();
    replay_cursor_ = BlockBatch::iterator();
    preload_tail_  = nullptr;
}

FileProcessor::ProcessBlockState PreloadFileProcessor::PreloadBlocksOneFrame()
{
    DispatchFunction dispatch = [](uint64_t block_index, ParsedBlock& block) {
        // NULL dispatch function.  The block batch sink will collect the parsed blocks.
        return ProcessBlockState::kRunning;
    };

    return ProcessBlocks(dispatch, false /* check decoder completion */);
}

bool PreloadFileProcessor::ProcessNextFrame()
{
    // Clean up preloaded frames if we're at the end of the preloaded frames.  It's done here
    // so that the clean up time is not measured in the measurement-frame-range timing.
    if (!replay_cursor_)
    {
        if (preload_head_)
        {
            ResetPreload();
        }
        return FileProcessor::ProcessNextFrame();
    }

    ProcessBlockState process_result = ReplayOneFrame();

    const bool at_end = (!replay_cursor_);
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

FileProcessor::ProcessBlockState PreloadFileProcessor::ReplayOneFrame()
{
    GFXRECON_ASSERT(replay_cursor_);

    BlockParser&    block_parser = GetBlockParser();
    DispatchVisitor dispatch_visitor(decoders_, annotation_handler_);
    SetDecoderFrameNumber(current_frame_number_);

    ProcessBlockState process_state = ProcessBlockState::kRunning;
    while (process_state == ProcessBlockState::kRunning)
    {
        ParsedBlock& queued_block = *replay_cursor_;
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
            if (!queued_block.Decompress(block_parser, working_uncompressed_store_))
            {
                process_state = ProcessBlockState::kError;
                break;
            }
        }

        dispatch_visitor.SetBlockIndex(block_index);
        std::visit(dispatch_visitor, queued_block.GetArgs());

        if (queued_block.IsFrameBoundary())
        {
            if (!preload_contains_frame_stutter_)
            {
                process_state = ProcessBlockState::kFrameBoundary;
            }
            else
            {
                // There is at most one spurious frame boundary
                preload_contains_frame_stutter_ = false;
            }
        }

        // Advanced
        ++replay_cursor_;

        if ((process_state == ProcessBlockState::kRunning) && !replay_cursor_)
        {
            // We did not end on a frame boundary, but that's okay if preloading end frame is beyond last complete frame
            // and there is a last incomplete frame, because of interrupt during record
            process_state = ProcessBlockState::kEndProcessing;
        }
    }

    return process_state;
}

void PreloadFileProcessor::EnqueueBatch(BlockBatch::BatchPtr&& batch)
{
    GFXRECON_ASSERT(batch.get() != nullptr);
    if (preload_tail_)
    {
        GFXRECON_ASSERT(preload_head_ && replay_cursor_);
        batch = BlockBatch::NonEmptyBatch(std::move(batch));
        if (batch.get() != nullptr)
        {
            // The batch was non-empty, so add it to the end of the queue.
            preload_tail_->SetNext(std::move(batch));
            preload_tail_ = preload_tail_->GetTail();
        }
    }
    else
    {
        preload_head_ = BlockBatch::MakeIteratorFromBatch(std::move(batch));
        if (preload_head_ != BlockBatch::iterator())
        {
            // We aren't expecting chains of batches, but preload_tail_ will be wrong if we don't get the tail.
            preload_tail_  = preload_head_.GetBatch()->GetTail();
            replay_cursor_ = preload_head_;
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
