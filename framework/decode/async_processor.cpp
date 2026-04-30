/*
** Copyright (c) 2018-2020,2022 Valve Corporation
** Copyright (c) 2018-2020,2022 LunarG, Inc.
** Copyright (c) 2022-2025 Advanced Micro Devices, Inc. All rights reserved.
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

#include "util/defines.h"
#include "util/logging.h"
#include "decode/async_processor.h"
#include "decode/file_processor.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

AsyncProcessor::~AsyncProcessor()
{
    if (async_thread_.joinable())
    {
        keep_alive_.store(false, std::memory_order_release);
        throttle_cv_.notify_all();
        async_thread_.join();
    }
}

void AsyncProcessor::LaunchAsyncThread()
{
    GFXRECON_ASSERT(!async_thread_.joinable());
    keep_alive_.store(true, std::memory_order_release);
    async_thread_ = std::thread([this]() { this->ThreadMain(); });

    // Waits until the first batch is flushed, or the queue is closed without flushing.
    // To shorten the block, the ThreadMain() enqueues a "Continue" batch holding only
    // ProcessBlocksResult "block" with state == kContinue, which DispatchVisitor treats as a noop.
    async_batch_iterator_ = AsyncBatchIterator(*this, batch_queue_);
}

void AsyncProcessor::NotifyBatchIndexDequeued(BatchCount batch_index)
{
    // Always need to update the dequeued index s.t. the producer can throttle or wait
    last_dequeued_batch_.store(batch_index, std::memory_order_release);

    // To minimize notify calls, check that the producer is waiting for the index we have.
    // *MUST* be done under lock
    std::unique_lock<std::mutex> lock(throttle_mutex_);
    if (batch_index >= throttle_wait_target_.load(std::memory_order_acquire))
    {
        throttle_cv_.notify_one();
    }
}

void AsyncProcessor::SetPreloadFrameRange(const FrameRange& frame_range)
{
    // Only callable before launching thread. (Avoids sychronization.)
    GFXRECON_ASSERT(!async_thread_.joinable());
    preload_frame_range_ = frame_range;
}

void AsyncProcessor::SetQuitBeforeFrame(FrameNumber frame_number)
{
    // Only callable before launching thread. (Avoids sychronization.)
    GFXRECON_ASSERT(!async_thread_.joinable());
    // Caller responsible for valid frame numbers.
    GFXRECON_ASSERT(frame_number > 0);
    quit_before_frame_ = frame_number;
}

void AsyncProcessor::WaitForBatchCount(BatchCount wait_target)
{
    std::unique_lock<std::mutex> lock(throttle_mutex_);
    // We tell the consumer to only notify us when we are waiting
    // Which means "wait_target < kMaxBatchCount".  And then only when
    // the predicate will pass.
    throttle_wait_target_.store(wait_target, std::memory_order_release);
    throttle_cv_.wait(lock, [this, wait_target] {
        // Start again when consumer has caught up to target
        return !keep_alive_ || last_dequeued_batch_.load(std::memory_order_acquire) >= wait_target;
    });
    throttle_wait_target_.store(kMaxBatchCount, std::memory_order_release);
}

void AsyncProcessor::ThrottleQueue()
{
    // Lowwater/Highwater checks
    //  * The highwater and lowwater checks are based on pending batches
    //  * Priority is given to lowwater, to prevent starvation of the consumer
    //  * Preventing starvation of the consumer and the cost of one or two additional batches pending is a small memory
    //    and batch overhead.
    //
    // Since last_dequeued_batch_ is set from the BlockBatch::tag it must be <= enqueued_batch_index_
    const BatchCount dequeued_batches = last_dequeued_batch_.load(std::memory_order_acquire);
    const BatchCount pending_batches  = enqueued_batch_index_ - dequeued_batches;
    async_stats_.AddBatchesPending(pending_batches);

    // LowWater checks to prevent consumer starvation.
    // * Soft: less than kSoftLowWater (2) batches pending and the current batch is at least half full.
    // * Hard: less than kLowWater (1) batches pending
    //
    // Soft is used to balance starvation with premature flushing.  Since the last_batch_dequeued_ is on average
    // still only half processed, this gives us a an average minium of two batches (soft) or 1.5 batches (hard)
    // pending.
    if (pending_batches <= kSoftLowWater)
    {
        BlockAllocator& allocator = block_parser_.GetBlockAllocator();
        if ((pending_batches <= kLowWater) || (allocator.BytesRemaining() <= (allocator.Capacity() / 2)))
        {
            // Avoid consumer starvation:
            // * The consumer is currently processing frames in one of the last two batches we enqueued.
            // * Flush the current batch in progress and offload decompression to the consumer to load balance
            allocator.FlushBatch();
            async_stats_.AddLowWaterFlush(enqueued_frame_index_, enqueued_batch_index_, pending_batches);
        }

        // Whether we flush or not, need to attempt to improve load balance by shifting decompression to
        // the consumer.
        static_assert(kSoftLowWater <= kAsyncDecompressNever,
                      "Must stay compatible with AdjustDecompressionPolicy threshold.");
        async_stats_.AddPolicyChange(block_parser_.GetDecompressionPolicy(), BlockParser::DecompressionPolicy::kNever);
        block_parser_.SetDecompressionPolicy(BlockParser::DecompressionPolicy::kNever);
    }
    else if (pending_batches >= kAsyncWait)
    {
        // Since we're not starving the consumer, check if we're far enough ahead, and if so, wait for the consumer.
        static_assert(kAsyncWait > kAsyncResume);
        BatchCount wait_target = enqueued_batch_index_ - kAsyncResume;
        async_stats_.AddHighwaterWait(enqueued_frame_index_, enqueued_batch_index_, pending_batches);
        WaitForBatchCount(wait_target);
        AdjustDecompressionPolicy(kAsyncResume);
    }
    else
    {
        // Neither high nor low water, adjust decompression policy to attempt to load balance.
        AdjustDecompressionPolicy(pending_batches);
    }

    async_stats_.IncrementPolicyCount(block_parser_);
}

void AsyncProcessor::AdjustDecompressionPolicy(BatchCount pending_batches)
{
    const auto policy = block_parser_.GetDecompressionPolicy();
    switch (policy)
    {
        case BlockParser::DecompressionPolicy::kNever:
            if (pending_batches > kAsyncDecompressOptimized)
            {
                async_stats_.AddPolicyChange(policy, BlockParser::DecompressionPolicy::kQueueOptimized);
                block_parser_.SetDecompressionPolicy(BlockParser::DecompressionPolicy::kQueueOptimized);
            }
            break;
        case BlockParser::DecompressionPolicy::kQueueOptimized:
            if (pending_batches >= kAsyncDecompressAlways)
            {
                async_stats_.AddPolicyChange(policy, BlockParser::DecompressionPolicy::kAlways);
                block_parser_.SetDecompressionPolicy(BlockParser::DecompressionPolicy::kAlways);
            }
            else if (pending_batches <= kAsyncDecompressNever)
            {
                async_stats_.AddPolicyChange(policy, BlockParser::DecompressionPolicy::kNever);
                block_parser_.SetDecompressionPolicy(BlockParser::DecompressionPolicy::kNever);
            }
            break;
        case BlockParser::DecompressionPolicy::kAlways:
            if (pending_batches <= kAsyncDecompressOptimized)
            {
                async_stats_.AddPolicyChange(policy, BlockParser::DecompressionPolicy::kQueueOptimized);
                block_parser_.SetDecompressionPolicy(BlockParser::DecompressionPolicy::kQueueOptimized);
            }
            break;
    }
}

// Add a the results block for the current frame with a strictly increasing frame index
void AsyncProcessor::AddResultsBlock(FrameNumber       frame_number,
                                     BlockIOError      error_state,
                                     ProcessBlockState process_state)
{
    ++enqueued_frame_index_;
    async_stats_.AddFrame();
    block_parser_.EmplaceResultsBlock(enqueued_frame_index_, frame_number, error_state, process_state);
}

// Continues blocks are used for in-band signalling, specifically to allow the async thread to unblock on
// startup, and to wait on when preload replay is running.
void AsyncProcessor::AddContinueBatch()
{
    AddResultsBlock(0, BlockIOError::kErrorNone, ProcessBlockState::kContinue);
    block_parser_.GetBlockAllocator().FlushBatch();
}

// This is the block loading and processing child thread.
void AsyncProcessor::ThreadMain()
{
    // As frame numbers can be non-contiguous, use a frame enqueing index for throttling math
    // The "frame index" encoded in a ProcessBlocksResult is not the frame number due to frame stuttering,
    // and of in-band signalling results blocks ProcessBlocksResults (for example a ContinueBlock)
    // and are stricltly increasing with each results block enqueued.

    block_parser_.GetBlockAllocator().SetBatchSinkProc([this](BlockBatch::BatchPtr&& batch) {
        // We tag each batch with a unique strictly monotonically increasing index before
        // placing it on the queue.  LowWater and HighWater use the index to control flushing and waiting
        ++enqueued_batch_index_;
        async_stats_.AddBatch(batch, enqueued_frame_index_, enqueued_batch_index_, last_dequeued_batch_);
        batch->SetBatchTag(enqueued_batch_index_);
        batch_queue_.emplace(std::move(batch));
    });

    // Enqueue a dummy batch to unblock the BatchIterator.
    AddContinueBatch();

    // Start with async_thread_ doing the minimal, and adjust if it gets too far ahead
    block_parser_.SetDecompressionPolicy(BlockParser::DecompressionPolicy::kNever);
    file_processor::AsyncProcessPolicy process_policy{ file_processor_, async_stats_ };

    FrameNumber frame_number        = file_processor_.GetProcessFrameNumber();
    bool        continue_processing = true;
    do
    {
        const bool preloading = preload_frame_range_.contains(frame_number);
        if (preloading)
        {
            if (frame_number == preload_frame_range_.begin_frame)
            {
                // To make async preloading simpler, Async Preloading starts and end on frame bounded batches.
                // In the stuttering case both the false and true frame boundaries will flush.
                block_parser_.GetBlockAllocator().FlushBatch();
                async_stats_.Dump(true); // Output stats so far and reset == true

                // Required for performance and frame looping reasons
                block_parser_.SetDecompressionPolicy(BlockParser::DecompressionPolicy::kAlways);
            }
        }
        ProcessBlockState process_state = file_processor_.ProcessBlocks(process_policy);
        BlockIOError      error_state   = file_processor_.GetProcessErrorState();
        frame_number                    = file_processor_.GetProcessFrameNumber();
        // Push all processed blocks onto the queue, and add the end of frame/end of process result to the queue
        AddResultsBlock(frame_number, error_state, process_state);

        if (preloading)
        {
            if (!preload_frame_range_.contains(frame_number))
            {
                // We don't want any more than the preloaded frames on the queue, as async should quiesce
                // during preload replay and it simplifies preload loading by having the preload range end on
                // a batch boundary
                block_parser_.GetBlockAllocator().FlushBatch();

                // And a batch after the last preload batch, to wait on for the preload replay to complete.
                AddContinueBatch();
                async_stats_.AddPendingAtWait(enqueued_frame_index_, enqueued_batch_index_, last_dequeued_batch_);
                // Once we've loaded all the frames in the preload, we wait until they've all replayed
                // from the preload queue
                WaitForBatchCount(enqueued_batch_index_);

                // After preload the queue is empty, so we allow for catchup by not decompressing
                block_parser_.SetDecompressionPolicy(BlockParser::DecompressionPolicy::kNever);
            }
        }
        else
        {
            ThrottleQueue();
        }

        continue_processing = file_processor_.ContinueProcessing(process_state) && (frame_number < quit_before_frame_);

    } while (continue_processing && keep_alive_.load(std::memory_order_acquire));

    // Must flush before closing.
    block_parser_.GetBlockAllocator().FlushBatch();

    GFXRECON_LOG_INFO("Async processing ending at frame %" PRIu64, frame_number);
    batch_queue_.close();
}

#if defined(ASYNC_PROCESSING_INSTRUMENTATION)
AsyncProcessor::AsyncInstrumentation::~AsyncInstrumentation()
{
    Dump(false);
}
void AsyncProcessor::AsyncInstrumentation::Dump(bool reset)
{
    // We only get any data if we've processed any asynchronous batches
    if (total_batches_)
    {
        GFXRECON_WRITE_CONSOLE("Total frames %" PRIu64, total_frames_);
        GFXRECON_WRITE_CONSOLE("Total batches %" PRIu64, total_batches_);
        GFXRECON_WRITE_CONSOLE("Total blocks %" PRIu64, total_blocks_);
        GFXRECON_WRITE_CONSOLE("Total linear bytes %" PRIu64, total_bytes_);
        GFXRECON_WRITE_CONSOLE("Total unused bytes %" PRIu64, total_unused_);
        GFXRECON_WRITE_CONSOLE("Total pending %" PRIu64, total_pending_);
        GFXRECON_WRITE_CONSOLE("Total wait %" PRIu64, waits_);
        GFXRECON_WRITE_CONSOLE("Total low water %" PRIu64, low_water_);
        GFXRECON_WRITE_CONSOLE("Total starve (0 pending) %" PRIu64, starve_);
        GFXRECON_WRITE_CONSOLE("Total near starve (1 pending) %" PRIu64, near_starve_);
        GFXRECON_WRITE_CONSOLE("Total always %" PRIu64, policy_count_[int(BlockParser::DecompressionPolicy::kAlways)]);
        GFXRECON_WRITE_CONSOLE("Total optimized %" PRIu64,
                               policy_count_[int(BlockParser::DecompressionPolicy::kQueueOptimized)]);
        GFXRECON_WRITE_CONSOLE("Total never %" PRIu64, policy_count_[int(BlockParser::DecompressionPolicy::kNever)]);

        using Policy                                          = BlockParser::DecompressionPolicy;
        std::unordered_map<Policy, const char*> dbg_names     = { { Policy::kAlways, "kAlways" },
                                                                  { Policy::kNever, "kNever" },
                                                                  { Policy::kQueueOptimized, "kQueueOptimized" } };
        std::pair<Policy, Policy>               dbg_changes[] = { { Policy::kNever, Policy::kQueueOptimized },
                                                                  { Policy::kQueueOptimized, Policy::kNever },
                                                                  { Policy::kAlways, Policy::kNever },
                                                                  { Policy::kQueueOptimized, Policy::kAlways },
                                                                  { Policy::kAlways, Policy::kQueueOptimized } };

        GFXRECON_WRITE_CONSOLE("Policy transitions");
        for (const auto& change : dbg_changes)
        {
            GFXRECON_WRITE_CONSOLE("From %s to %s:  %" PRIu64,
                                   dbg_names[change.first],
                                   dbg_names[change.second],
                                   policy_change_[int(change.first)][int(change.second)]);
        }

        if (preload_pending_at_wait_.has_value())
        {
            GFXRECON_WRITE_CONSOLE("Pending");
            GFXRECON_WRITE_CONSOLE("Frames pending at preload wait  %" PRIu64, *preload_pending_at_wait_);
        }

        if (total_frames_)
        {
            double oof = 1.0 / double(total_frames_);
            double oom = 1.0 / double(1024 * 1024);
            GFXRECON_WRITE_CONSOLE("Avg batches pending %f", total_pending_ * oof);
            GFXRECON_WRITE_CONSOLE("Avg batches/frame %.3f", total_batches_ * oof);
            GFXRECON_WRITE_CONSOLE("Avg blocks/frame %.3f", total_blocks_ * oof);
            GFXRECON_WRITE_CONSOLE("Avg MB/frame %.3f", total_bytes_ * oof * oom);
            GFXRECON_WRITE_CONSOLE("Avg unused MB/frame %.3f", total_unused_ * oof * oom);
            if (total_batches_)
            {
                double oob      = 1.0 / double(total_batches_);
                size_t capacity = BlockBatch::kCapacity;
                double ooc      = 1.0 / double(capacity);
                GFXRECON_WRITE_CONSOLE("capacity/batch %" PRIu64, capacity);
                GFXRECON_WRITE_CONSOLE("Avg blocks/batch %.3f", total_blocks_ * oob);
                GFXRECON_WRITE_CONSOLE("Avg MB/batch %.3f", total_bytes_ * oob * oom);
                GFXRECON_WRITE_CONSOLE("Avg unused MB/batch %.3f", total_unused_ * oob * oom);
                GFXRECON_WRITE_CONSOLE("%% capacity used %.3f", total_bytes_ * 100. * oob * ooc);
            }

            double poof = 100. * oof;
            GFXRECON_WRITE_CONSOLE("%% wait %.3f", waits_ * poof);
            GFXRECON_WRITE_CONSOLE("%% low_water %.3f", low_water_ * poof);
            GFXRECON_WRITE_CONSOLE("%% starve (0 pending) %.3f", starve_ * poof);
            GFXRECON_WRITE_CONSOLE("%% near starve (1 pending) %.3f", near_starve_ * poof);
            GFXRECON_WRITE_CONSOLE("%% always %.3f",
                                   poof * policy_count_[int(BlockParser::DecompressionPolicy::kAlways)]);
            GFXRECON_WRITE_CONSOLE("%% optimized %.3f",
                                   poof * policy_count_[int(BlockParser::DecompressionPolicy::kQueueOptimized)]);
            GFXRECON_WRITE_CONSOLE("%% never %.3f",
                                   poof * policy_count_[int(BlockParser::DecompressionPolicy::kNever)]);
        }
    }

    if (queue_events_.size())
    {
        static const char* kQueueStatusNames[] = { "LowWater", "HighWater", "Flush", "Wait", "AddBatch" };
        GFXRECON_WRITE_CONSOLE("Queue events:");
        for (const auto& event : queue_events_)
        {
            GFXRECON_WRITE_CONSOLE("%s: Frame %" PRIu64 ": Batch: %" PRIu64 "Pending: %" PRIu64,
                                   kQueueStatusNames[int(event.status)],
                                   event.frame_index,
                                   event.batch_index,
                                   event.pending_batches);
        }
    }
    if (reset)
    {
        *this = AsyncInstrumentation();
    }
}

void AsyncProcessor::AsyncInstrumentation::AddBatchesPending(BatchCount pending_batches)
{
    total_pending_ += pending_batches;
    if (pending_batches == 0)
    {
        ++starve_;
    }
    else if (pending_batches == 1)
    {
        ++near_starve_;
    }
}

void AsyncProcessor::AsyncInstrumentation::AddLowWaterFlush(FrameCount frame_index,
                                                            BatchCount batch_index,
                                                            BatchCount pending_batches)
{
    ++low_water_;
    queue_events_.push_back({ frame_index, batch_index, pending_batches, QueueStatus::kLowWater });
}

void AsyncProcessor::AsyncInstrumentation::AddHighwaterWait(FrameCount frame_index,
                                                            BatchCount batch_index,
                                                            BatchCount pending_batches)
{
    ++waits_;
    queue_events_.push_back({ frame_index, batch_index, pending_batches, QueueStatus::kHighWater });
}

void AsyncProcessor::AsyncInstrumentation::AddBatch(const BlockBatch::BatchPtr&    batch,
                                                    FrameCount                     frame_index,
                                                    BatchCount                     batch_index,
                                                    const std::atomic<FrameCount>& dequeued_batches)
{
    ++total_batches_;
    total_unused_ += batch->BytesRemaining();
    total_bytes_ += (batch->kCapacity - batch->BytesRemaining()); // linear usage only
    const BatchCount pending_batches = batch_index - dequeued_batches.load(std::memory_order_acquire);
    queue_events_.push_back({ frame_index, batch_index, pending_batches, QueueStatus::kAddBatch });
}

void AsyncProcessor::AsyncInstrumentation::AddPolicyChange(BlockParser::DecompressionPolicy from,
                                                           BlockParser::DecompressionPolicy to)
{
    if (from != to)
    {
        ++policy_change_[int(from)][int(to)];
    }
}

void AsyncProcessor::AsyncInstrumentation::AddPendingAtWait(FrameCount                     frame_index,
                                                            BatchCount                     batch_index,
                                                            const std::atomic<FrameCount>& dequeued_batches)
{
    BatchCount pending_batches = batch_index - dequeued_batches.load(std::memory_order_acquire);
    preload_pending_at_wait_.emplace(pending_batches);
    queue_events_.push_back({ frame_index, batch_index, pending_batches, QueueStatus::kWait });
}
#endif // ASYNC_PROCESSING_INSTRUMENTATION

GFXRECON_BEGIN_NAMESPACE(file_processor)
bool AsyncProcessPolicy::ContinueBlockProcessing(uint64_t block_index)
{
    return file_processor_.ContinueBlockProcessing<ContinueProcessingPolicy::BlockLimitOnly>(block_index);
}
GFXRECON_END_NAMESPACE(file_processor)

void AsyncProcessor::AsyncBatchIterator::Advance()
{
    if (queue_ != nullptr)
    {
        auto item = queue_->pop();
        batch_    = item.has_value() ? std::move(*item) : nullptr;
    }
    else
    {
        batch_ = nullptr;
    }

    if ((async_processor_ != nullptr) && (batch_ != nullptr))
    {
        async_processor_->NotifyBatchIndexDequeued(batch_->GetBatchTag());
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
