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
    async_batch_iterator_ = AsyncBatchIterator(batch_queue_);
}

void AsyncProcessor::NotifyFrameIndexDequeued(FrameCount frame_index)
{
    // Always need to update the dequeued index s.t. the producer can throttle or wait
    dequeued_frames_.store(frame_index, std::memory_order_release);

    // To minimize notify calls, check that the producer is waiting for the index we have.
    // *MUST* be done under lock
    std::unique_lock<std::mutex> lock(throttle_mutex_);
    if (frame_index >= throttle_wait_target_.load(std::memory_order_acquire))
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

void AsyncProcessor::WaitForFrameCount(FrameCount wait_target)
{
    std::unique_lock<std::mutex> lock(throttle_mutex_);
    // We tell the consumer to only notify us when we are waiting
    // Which means "wait_target < kMaxFrameCount".  And then only when
    // the predicate will pass.
    throttle_wait_target_.store(wait_target, std::memory_order_release);
    throttle_cv_.wait(lock, [this, wait_target] {
        // Start again when consumer has caught up to target
        return !keep_alive_ || dequeued_frames_.load(std::memory_order_acquire) >= wait_target;
    });
    throttle_wait_target_.store(kMaxFrameCount, std::memory_order_release);
}

void AsyncProcessor::ThrottleQueue(FrameCount enqueued_frames, const BatchFramesRing& batch_frame_index)
{
    // 2 is "next to last batch".
    const FrameCount prior_batch_frames = batch_frame_index.Back(2);

    // Lowwater/Highwater checks
    //  * The highwater and lowwater checks are based on both frames and batches
    //  * It is possible for the producer to be in both highwater based on frames ahead and lowwater based on batches
    //  ahead
    //  * Priority is given to lowwater, to prevent starvation of the consumer, as the "high water based on frames"
    //    check will only happen simultaneously with the lowwater check if the frames are small w.r.t. batch size,
    //  * Preventing starvation of the consumer and the cost of one or two additional batches pending is a small memory
    //    and batch overhead.
    //
    // Since dequeued_frames_ is set from the ProcessBlocksResult::index it must be <= enqueued_frames
    const FrameCount dequeued_frames = dequeued_frames_.load(std::memory_order_acquire);
    const FrameCount pending_frames  = enqueued_frames - dequeued_frames;
    async_stats_.AddFramePending(pending_frames);

    if (dequeued_frames >= prior_batch_frames)
    {
        // Avoid consumer starvation:
        // * The consumer is currently processing frames in one of the last two batches we enqueued.
        // * Flush the current batch in progress and offload decompression to the consumer to load balance
        async_stats_.AddLowWaterFlush(enqueued_frames, dequeued_frames, prior_batch_frames);
        block_parser_.GetBlockAllocator().FlushBatch();

        async_stats_.AddPolicyChange(block_parser_.GetDecompressionPolicy(), BlockParser::DecompressionPolicy::kNever);
        block_parser_.SetDecompressionPolicy(BlockParser::DecompressionPolicy::kNever);
    }
    else if (pending_frames >= kAsyncWait)
    {
        // Since we're not starving the consumer, check if we're far enough ahead, and if so, wait for the consumer.
        static_assert(kAsyncWait > kAsyncResume);
        FrameCount wait_target = enqueued_frames - kAsyncResume;

        // We wait, if we are "Wait" frames ahead of the consumer, and either:
        // * producers is more than one batch ahead of wait_target,
        // * OR dequeued_frames is approximately kSize batches behind. (frames spanning batches make this approximate)
        // Note: we don't have to use kSize, just any value <= kSize, it's just conveniently, heuristically sized to
        // match.
        //       Make sure to adjust the wait_target override below if you change the kSize (use a different offset).
        const FrameCount oldest_batch_frames  = batch_frame_index.Back(BatchFramesRing::kSize);
        bool             excess_batch_pending = false;
        if (dequeued_frames < oldest_batch_frames)
        {
            // If consumer is more than kSize batches behind, catch up, but not enough to trigger lowwater on resume.
            constexpr size_t kWaitTargetOffset = BatchFramesRing::kSize - 1;
            static_assert(kWaitTargetOffset > 1,
                          "Do not use 1 as the wait target offset,  this will force LowWater on resume");
            wait_target          = batch_frame_index.Back(kWaitTargetOffset);
            excess_batch_pending = true;
        }

        if (wait_target <= prior_batch_frames)
        {
            // Since the consumer is at least one batch and kAsyncWait frames behind, we wait until the consumer has
            // caught up to the "resume" point, which is at least 1 full batch behind.
            // We needn't flush here, as there is at least one full batch between the consumer and the producer.
            async_stats_.AddHighwaterWait(enqueued_frames, dequeued_frames, wait_target, excess_batch_pending);
            WaitForFrameCount(wait_target);
            AdjustDecompressionPolicy(kAsyncResume);
        }
        else
        {
            // The resume point is no more than one batch behind, regardless of frame distance, we don't want to wait.
            // We also don't need to flush as the lowwater handler will do so as necessary.
            AdjustDecompressionPolicy(pending_frames);
        }
    }
    else
    {
        // Neither high nor low water, adjust decompression policy to attempt to load balance.
        AdjustDecompressionPolicy(pending_frames);
    }

    async_stats_.IncrementPolicyCount(block_parser_);
}

void AsyncProcessor::AdjustDecompressionPolicy(FrameCount pending_frames)
{
    const auto policy = block_parser_.GetDecompressionPolicy();
    switch (policy)
    {
        case BlockParser::DecompressionPolicy::kNever:
            if (pending_frames > kAsyncOptimized)
            {
                async_stats_.AddPolicyChange(policy, BlockParser::DecompressionPolicy::kQueueOptimized);
                block_parser_.SetDecompressionPolicy(BlockParser::DecompressionPolicy::kQueueOptimized);
            }
            break;
        case BlockParser::DecompressionPolicy::kQueueOptimized:
            if (pending_frames >= kAsyncAlways)
            {
                async_stats_.AddPolicyChange(policy, BlockParser::DecompressionPolicy::kAlways);
                block_parser_.SetDecompressionPolicy(BlockParser::DecompressionPolicy::kAlways);
            }
            else if (pending_frames <= kAsyncNever)
            {
                async_stats_.AddPolicyChange(policy, BlockParser::DecompressionPolicy::kNever);
                block_parser_.SetDecompressionPolicy(BlockParser::DecompressionPolicy::kNever);
            }
            break;
        case BlockParser::DecompressionPolicy::kAlways:
            if (pending_frames <= kAsyncOptimized)
            {
                async_stats_.AddPolicyChange(policy, BlockParser::DecompressionPolicy::kQueueOptimized);
                block_parser_.SetDecompressionPolicy(BlockParser::DecompressionPolicy::kQueueOptimized);
            }
            break;
    }
}

// This is the block loading and processing child thread.
void AsyncProcessor::ThreadMain()
{
    // As frame numbers can be non-contiguous, use a frame enqueing index for throttling math
    // Allow the *index* to be one based, counting the number of enqueued frames
    FrameCount enqueued_frames = 0;

    // The batch_frame_index is a circular buffer of the last frame indices of the last few enqueued batches,
    // indexed by batch_index.
    BatchFramesRing batch_frame_index;

    block_parser_.GetBlockAllocator().SetBatchSinkProc(
        [this, &enqueued_frames, &batch_frame_index](BlockBatch::BatchPtr&& batch) {
            // This is the frame index of the last frame in the batch. Used to detect starvation, and force flush on
            // near empty queue.
            batch_frame_index.Push(enqueued_frames);
            async_stats_.AddBatch(batch, enqueued_frames);
            batch_queue_.emplace(std::move(batch));
        });
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

                // Required for performance and frame looping reasons
                block_parser_.SetDecompressionPolicy(BlockParser::DecompressionPolicy::kAlways);
            }
        }
        file_processor::ProcessBlockState process_state = file_processor_.ProcessBlocks(process_policy);
        frame_number                                    = file_processor_.GetProcessFrameNumber();
        // Push all processed blocks onto the queue, and add the end of frame/end of process result to the queue
        ++enqueued_frames;
        async_stats_.AddFrame();
        block_parser_.EmplaceResultsBlock(
            enqueued_frames, frame_number, file_processor_.GetProcessErrorState(), process_state);

        if (preloading)
        {
            if (!preload_frame_range_.contains(frame_number))
            {
                // We don't want any more than the preloaded frames on the queue, as async should quiesce
                // during preload replay.
                block_parser_.GetBlockAllocator().FlushBatch();
                async_stats_.AddPendingAtWait(enqueued_frames, dequeued_frames_);
                // Once we've loaded all the frames in the preload, we wait until they've all replayed
                // from the preload queue
                WaitForFrameCount(enqueued_frames);

                // After preload the queue is empty, so we allow for catchup by not decompressing
                block_parser_.SetDecompressionPolicy(BlockParser::DecompressionPolicy::kNever);
            }
        }
        else
        {
            ThrottleQueue(enqueued_frames, batch_frame_index);
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
            GFXRECON_WRITE_CONSOLE("Avg pending %f", total_pending_ * oof);
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
        static const char* kQueueStatusNames[] = { "LowWater", "HighWater", "Flush" };
        GFXRECON_WRITE_CONSOLE("Queue events:");
        FrameCount last_frame = ~0;
        for (const auto& event : queue_events_)
        {
            if (event.frame_index != last_frame)
            {
                if (event.status == QueueStatus::kLowWater)
                {
                    GFXRECON_WRITE_CONSOLE("%s: Frame %" PRIu64 ": Dequeued: %" PRIu64 " Prior Batch Frame: %" PRIu64,
                                           kQueueStatusNames[int(event.status)],
                                           event.frame_index,
                                           event.dequed_frames,
                                           event.prior_frame);
                }
                else if (event.status == QueueStatus::kHighWater)
                {
                    const char* wait_target_str = (event.wait_for_prev) ? "(prev batch)" : "(excess batch)";
                    GFXRECON_WRITE_CONSOLE("%s: Frame %" PRIu64 ": Dequeued: %" PRIu64 " Wait Target: %" PRIu64 "%s",
                                           kQueueStatusNames[int(event.status)],
                                           event.frame_index,
                                           event.dequed_frames,
                                           event.prior_frame,
                                           wait_target_str);
                }
                else
                {
                    GFXRECON_ASSERT(event.status == QueueStatus::kFlush);
                    GFXRECON_WRITE_CONSOLE(
                        "%s: Frame %" PRIu64, kQueueStatusNames[int(event.status)], event.frame_index);
                }
            }
            else
            {
                GFXRECON_ASSERT(event.status == QueueStatus::kFlush);
            }
            last_frame = event.frame_index;
        }
    }
}

void AsyncProcessor::AsyncInstrumentation::AddFramePending(FrameCount pending_frames)
{
    total_pending_ += pending_frames;
    if (pending_frames == 0)
    {
        ++starve_;
    }
    else if (pending_frames == 1)
    {
        ++near_starve_;
    }
}

void AsyncProcessor::AsyncInstrumentation::AddLowWaterFlush(FrameCount frame_index,
                                                            FrameCount dequeued_frames,
                                                            FrameCount prior_batch_frames)
{
    ++low_water_;
    queue_events_.push_back({ frame_index, dequeued_frames, QueueStatus::kLowWater, prior_batch_frames, true });
}

void AsyncProcessor::AsyncInstrumentation::AddHighwaterWait(FrameCount frame_index,
                                                            FrameCount dequeued_frames,
                                                            FrameCount wait_target,
                                                            bool       excess_batch_pending)
{
    ++waits_;
    bool prior_batch_wait = !excess_batch_pending;
    queue_events_.push_back({ frame_index, dequeued_frames, QueueStatus::kHighWater, wait_target, prior_batch_wait });
}

void AsyncProcessor::AsyncInstrumentation::AddBatch(const BlockBatch::BatchPtr& batch, FrameCount frame_index)
{
    ++total_batches_;
    total_unused_ += batch->BytesRemaining();
    total_bytes_ += (batch->kCapacity - batch->BytesRemaining()); // linear usage only
    queue_events_.push_back({ frame_index, 0, QueueStatus::kFlush, 0, true });
}

void AsyncProcessor::AsyncInstrumentation::AddPolicyChange(BlockParser::DecompressionPolicy from,
                                                           BlockParser::DecompressionPolicy to)
{
    if (from != to)
    {
        ++policy_change_[int(from)][int(to)];
    }
}

void AsyncProcessor::AsyncInstrumentation::AddPendingAtWait(FrameCount                     enqueued_frames,
                                                            const std::atomic<FrameCount>& dequeued_frames)
{
    preload_pending_at_wait_.emplace(enqueued_frames - dequeued_frames.load(std::memory_order_acquire));
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
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
