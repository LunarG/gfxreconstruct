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
#include "decode/file_processor_visitors.h"
#include "util/logging.h"

#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

PreloadFileProcessor::PreloadFileProcessor() : preload_queue_(), preload_batch_iterator_(preload_queue_) {}

void PreloadFileProcessor::PreloadLoopFrame()
{
    PreloadNextFrames(1);
    loop_replay_ = true;
    loop_bookmark_ =
        SkipStateBlocks(dispatch_frame_number_, preload_batch_iterator_.MakeBookmark(preload_block_iterator_));
}
void PreloadFileProcessor::PreloadNextFrames(size_t count)
{
    // This should never be called for zero length ranges
    GFXRECON_ASSERT(count > 0U);

    // Multiple appended preload not supported.
    ResetPreload();

    size_t preloaded_frames = 0;
    if (async_processing_)
    {
        preloaded_frames = PreloadNextFramesAsync(count);
    }
    else
    {
        preloaded_frames = PreloadNextFramesSync(count);
    }

    if (preloaded_frames != count)
    {
        GFXRECON_LOG_INFO("Preload did not load all measurement frames. %" PRIu64 " frames found, %" PRIu64 " expected",
                          preloaded_frames,
                          count);
    }

    // Set the replay controls
    replay_from_queue_ = true;
    preload_batch_iterator_.Rewind(); // loads first batch; points cursor to head of preload_queue_
    preload_block_iterator_ = BlockIterator(&preload_batch_iterator_);
}

void PreloadFileProcessor::ReplayAndClearStutterFrame()
{
    // This is really part of the non-preloaded previous (first) frame,
    // so immediately replay it to complete that frame
    DispatchVisitor dispatch_visitor(*this, decoders_, annotation_handler_);
    preload_batch_iterator_.Rewind();
    BlockIterator begin(&preload_batch_iterator_);
    ReplayOneFrame(dispatch_visitor, begin, BlockIterator());

    // Don't need/want to NotifyIndexDequeued here as since:
    // * this is a frame boundary (not EOF)
    // * count is not decremented (and non-zero)
    // * the next frame won't be first
    //
    // Thus at least one result is guaranteed to be preloaded.
    ResetPreload();

    GFXRECON_ASSERT(GetReplayResult(dispatch_visitor).state == ProcessBlockState::kFrameBoundary);
}

size_t PreloadFileProcessor::PreloadNextFramesSync(size_t preload_count)
{
    // This should never be called for zero length ranges
    GFXRECON_ASSERT(preload_count > 0U);

    if (!IsFileValid())
    {
        process_error_state_ = CheckFileStatus();
        return 0;
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

    // Use kAlways when preloading for frame looping.
    // This is required not only to move decompression work out of the measurement loop,
    // but also to ensure queued blocks have stable decompressed argument data for replay.
    // If decompression were deferred to replay, dispatch args for compressed blocks could
    // point into the temporary working decompression store, which is overwritten/resized
    // by subsequent decompressions, leading to invalid or stale pointers.
    block_parser_->SetDecompressionPolicy(BlockParser::DecompressionPolicy::kAlways);

    DispatchFunction dispatch = [](uint64_t block_index, ParsedBlock& block) {
        // NULL dispatch function.  The block batch sink will collect the parsed blocks.
        return ProcessBlockState::kRunning;
    };

    const FrameNumber end_preload_frame = dispatch_frame_number_ + preload_count;

    ProcessBlockState state = ProcessBlockState::kFrameBoundary;
    while ((process_frame_number_ < end_preload_frame) && (state == ProcessBlockState::kFrameBoundary))
    {
        state = ProcessBlocks(dispatch);

        // The index is not meaningful during synchronous processing.
        ProcessBlocksResult preload_result = { 0U, process_frame_number_, process_error_state_, state };
        block_parser_->EmplaceResultsBlock(preload_result);

        // This is the "leading stutter"" condition.  The ProcessBlocks is repeating the same frame
        // number we started with. Middle stutter (where the duplicate frame boundary is embbedded in
        // the measurement range doesn't need special handling
        if ((state == ProcessBlockState::kFrameBoundary) && (process_frame_number_ == dispatch_frame_number_))
        {
            // This can only happen between frames 0 and 1.
            GFXRECON_ASSERT(dispatch_frame_number_ == (kFirstFrame + 1));
            block_parser_->GetBlockAllocator().FlushBatch();
            ReplayAndClearStutterFrame();
        }
    }

    // Flush any pending batches to the preload_queue_
    block_parser_->GetBlockAllocator().FlushBatch();

    // Since preload_count can't be zero, the queue mustn't be empty, even with no complete frames.
    // If there are no complete frames, a kError or kEndProcessing result will be on the queue.
    GFXRECON_ASSERT(!preload_queue_.empty());

    size_t frames_preloaded = process_frame_number_ - dispatch_frame_number_;

    // Restore the original parser policies
    block_parser_->SetOperationMode(save_operation_mode);
    block_parser_->SetDecompressionPolicy(save_decompression_policy);
    block_parser_->GetBlockAllocator().ResetBatchSinkProc();
    return frames_preloaded;
}

void PreloadFileProcessor::ResetPreload()
{
    preload_queue_.clear();
    // view holds preload_queue_ iterators, make sure they aren't invalid
    preload_batch_iterator_.Rewind();

    // The Rewind call points cursor at preload_queue_.begin() but after clear,
    // this should also be end(), and thus the view must be empty.
    GFXRECON_ASSERT(preload_batch_iterator_.empty());
}

size_t PreloadFileProcessor::PreloadNextFramesAsync(size_t count)
{
    // Need to copy from the async_queue_ to the preload_queue_
    // Only batches with trailing ProcessBlocksResults are interesting, as they reflect the flush conditions of
    // the async thread:
    // * End of preload
    // * End of file
    // * Coincidental with batch boundary.  Effectively, ignored
    //
    // Note that since we are directly consuming batches via async_block_iterator_, we will need to
    // advance it past the last preloaded batch at the end of preload (see ProcessNextFrame).
    //
    FrameNumber       preload_frame_number = dispatch_frame_number_;
    FrameNumber       preload_frame_limit_ = dispatch_frame_number_ + count;
    ProcessBlockState state                = ProcessBlockState::kFrameBoundary;

    // Note that we aren't counting frames, rather looking at reported frame numbers.
    bool preloading = true;
    do
    {
        // Starting from were non-preload replay left off...
        BlockBatch::BatchPtr batch = async_block_iterator_.GetBatch();
        if (batch.get() == nullptr)
        {
            GFXRECON_ASSERT(
                false && "Should never encounter end of queue without a terminating ProcessBlocksResult ahead of it.");
            dispatch_error_state_ = BlockIOError::kErrorReadingBlockData;
            state                 = ProcessBlockState::kError;
            preloading            = false;
        }
        else
        {
            GFXRECON_ASSERT((batch.get() != nullptr) && !batch->empty());
            ParsedBlock* tail_block = batch->Tail();

            const ProcessBlocksResult* const* block_result_ptr =
                std::get_if<ProcessBlocksResult*>(&(tail_block->GetArgs()));
            preload_queue_.emplace_back(std::move(batch));

            // The pointer is still valid, as moving the batch shared_ptr doesn't alter the batch..
            if (block_result_ptr != nullptr)
            {
                const ProcessBlocksResult* const block_result = *block_result_ptr;
                if (block_result)
                {
                    preload_frame_number = block_result->frame_number;
                    state                = block_result->state;

                    // This is the "leading stutter"" condition.  The batch tail is a frame boundary repeating the same
                    // frame number. Middle stutter (where the duplicate frame boundary is embbedded in the measurement
                    // range doesn't need special handling
                    if ((state == ProcessBlockState::kFrameBoundary) &&
                        (preload_frame_number == dispatch_frame_number_))
                    {
                        // This can only happen between frames 0 and 1.
                        GFXRECON_ASSERT(dispatch_frame_number_ == (kFirstFrame + 1));
                        ReplayAndClearStutterFrame();
                    }
                    GFXRECON_ASSERT(state != ProcessBlockState::kRunning);
                    // Terminate if we hit anything other than a frame boundary in a trailing result, or finish the
                    // preload.
                    preloading =
                        (state == ProcessBlockState::kFrameBoundary) && (preload_frame_number < preload_frame_limit_);
                }
            }
        }

        // If we're still preloading, get the next batch.
        if (preloading)
        {
            async_block_iterator_.NextBatch();
        }
    } while (preloading);

    // Return the number frames preloaded.
    return preload_frame_number - dispatch_frame_number_;
}

bool PreloadFileProcessor::ProcessNextFrame()
{
    // Clean up preloaded frames if we're at the end of the preloaded frames.  It's done here
    // so that the clean up time is not measured in the measurement-frame-range timing.
    if (!replay_from_queue_)
    {
        if (!preload_queue_.empty())
        {
            // We clean up frame after limit s.t. memory operations don't taint performance
            ResetPreload();

            if (async_processing_)
            {
                // We didn't notify dequeued for all of replay, until now, and if async_processing_,
                // the async_thread_ has been blocking on this last enqueued index
                NotifyIndexDequeued(preload_last_index_);
                // After restarting the async_thread_ (such that NextBatch doesn't hang), advance past the last
                // preloaded batch; blocks until async_thread_ flushes the next one.
                async_block_iterator_.NextBatch();
            }
        }
        return FileProcessor::ProcessNextFrame();
    }

    DispatchVisitor dispatch_visitor(*this, decoders_, annotation_handler_);
    preload_block_iterator_           = ReplayOneFrame(dispatch_visitor, preload_block_iterator_, BlockIterator());
    const ProcessBlocksResult& result = GetReplayResult(dispatch_visitor);
    HandleReplayResult(result, preload_block_iterator_, [this](const ProcessBlocksResult& publish_result) {
        preload_last_index_ = publish_result.index;
    });

    if (loop_replay_)
    {
        // We're resetting the command stream, wait for all referenced resources to be non-busy
        WaitDecodersIdle();
        preload_block_iterator_ = loop_bookmark_->RestoreInto(preload_batch_iterator_);
        // NOTE: EOP is a valid loop continuation — only Error terminates looping.
        return result.state != ProcessBlockState::kError;
    }

    if (preload_block_iterator_ == BlockIterator())
    {
        replay_from_queue_ = false;
    }
    return ContinueProcessing(result.state);
}

void PreloadFileProcessor::EnqueueBatch(BlockBatch::BatchPtr&& batch)
{
    GFXRECON_ASSERT(batch.get() != nullptr);
    preload_queue_.emplace_back(batch);
}

PreloadFileProcessor::Bookmark
PreloadFileProcessor::PreloadBatchIterator::MakeBookmark(const file_processor::BlockIterator& bit) const
{
    GFXRECON_ASSERT(bit.BelongsTo(*this));
    return Bookmark(*this, bit.GetBlock());
}

file_processor::BlockIterator PreloadFileProcessor::Bookmark::RestoreInto(PreloadBatchIterator& target) const
{
    target = pbi_;
    return file_processor::BlockIterator(file_processor::BlockIterator::ForceLocationTag{}, target, block_);
}

PreloadFileProcessor::Bookmark PreloadFileProcessor::SkipStateBlocks(uint64_t frame_number, Bookmark start)
{
    PreloadBatchIterator local;
    BlockIterator        it = start.RestoreInto(local);
    size_t               n  = 0;
    for (; it != BlockIterator(); ++it, ++n)
    {
        if (it->Holds<StateEndMarkerArgs>())
        {
            ++n;
            ++it; // advance past the StateEndMarkerArgs block
            GFXRECON_LOG_INFO("Skipped %zu state blocks from preloaded frame %" PRIu64, n, frame_number);
            return local.MakeBookmark(it);
        }
    }
    return start;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
