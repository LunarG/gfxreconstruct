/*
** Copyright (c) 2023-2026 LunarG, Inc.
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

PreloadFileProcessor::PreloadFileProcessor() {}

void PreloadFileProcessor::PreloadNextFrames(size_t count)
{
    size_t expected_count = count;
    if (!IsFileValid())
    {
        process_error_state_ = CheckFileStatus();
        return;
    }

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
    GFXRECON_ASSERT(keep_alive_.empty());
    ResetPreload();

    ProcessBlockState preload_result = ProcessBlockState::kFrameBoundary;
    bool              first_preloaded_frame = true;
    while ((count != 0U) && (preload_result == ProcessBlockState::kFrameBoundary))
    {
        uint64_t current_preload_frame         = process_frame_number_;
        preload_result                         = PreloadBlocksOneFrame();

        if (preload_result != ProcessBlockState::kError)
        {
            // This is for the corner case where we are seeing an explicit frame boundary, for a file
            // that assumes implicit frame boundaries on specific function call blocks.
            // A WARNING is logged during block processing when this occurs.

            // We have two strategies to deal with this case:
            const bool frame_stutter = (preload_result == ProcessBlockState::kFrameBoundary) &&
                                       (process_frame_number_ == current_preload_frame);
            if (frame_stutter)
            {
                // Deal with the frame marker after implied frame kFunctionCallBlock frame boundary case
                GFXRECON_ASSERT(process_frame_number_ == (kFirstFrame + 1));
                if (first_preloaded_frame)
                {
                    // This is really part of the non-preloaded previous (first) frame,
                    // so immediately replay it to complete that frame
                    block_parser_->GetBlockAllocator().FlushBatch();
                    ProcessBlockState replay_result = ReplayOneFrame(preload_queue_);
                    ResetPreload();
                    GFXRECON_ASSERT(replay_result == ProcessBlockState::kFrameBoundary);
                }
            }
            else
            {
                // Normal case, just count the preloaded frame
                count--;
            }
        }
        first_preloaded_frame = false;
    }

    // Set the replay controls
    preload_frame_limit_ = process_frame_number_;
    replay_from_queue_   = true;

    // Ensure we have even non-full batches
    block_parser_->GetBlockAllocator().FlushBatch();

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
}

void PreloadFileProcessor::ResetPreload()
{
    keep_alive_.clear();
    preload_queue_.clear();
}

FileProcessor::ProcessBlockState PreloadFileProcessor::PreloadBlocksOneFrame()
{
    DispatchFunction dispatch = [](uint64_t block_index, ParsedBlock& block) {
        // NULL dispatch function.  The block batch sink will collect the parsed blocks.
        return ProcessBlockState::kRunning;
    };

    auto state = ProcessBlocks(dispatch);
    // Push all processed blocks onto the queue, and add the end of frame/end of process result to the queue
    block_parser_->GetBlockAllocator().FlushBatch();
    preload_queue_.emplace(ProcessBlocksResult{ process_frame_number_, state, process_error_state_ });
    return state;
}

bool PreloadFileProcessor::ProcessNextFrame()
{
    // Clean up preloaded frames if we're at the end of the preloaded frames.  It's done here
    // so that the clean up time is not measured in the measurement-frame-range timing.
    if (!replay_from_queue_)
    {
        if (!keep_alive_.empty())
        {
            // We clean up frame after limit s.t. memory operations don't taint performance
            ResetPreload();
        }
        return FileProcessor::ProcessNextFrame();
    }

    ProcessBlockState process_result = ReplayOneFrame(preload_queue_);
    if (dispatch_frame_number_ >= preload_frame_limit_)
    {
        replay_from_queue_ = false;
    }
    return ContinueProcessing(process_result);
}

void PreloadFileProcessor::EnqueueBatch(BlockBatch::BatchPtr&& batch)
{
    GFXRECON_ASSERT(batch.get() != nullptr);
    keep_alive_.emplace_back(batch);
    preload_queue_.emplace(batch);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
