/*
** Copyright (c) 2018-2026 LunarG, Inc.
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

// #define ASYNC_PROCESSING_INSTRUMENTATION

#ifndef GFXRECON_DECODE_ASYNC_PROCESSOR_H
#define GFXRECON_DECODE_ASYNC_PROCESSOR_H

#include "decode/block_parser.h"

#include <array>
#include <atomic>

#if defined(ASYNC_PROCESSING_INSTRUMENTATION)
#include <deque>
#include <optional>
#include <unordered_map>
#endif

#include "decode/file_processor_types.h"
#include "util/thread_safe_queue.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class FileProcessor;
class BlockParser;

class AsyncProcessor
{
  public:
    using AsyncBatchQueue   = util::ThreadSafeQueue<BlockBatch::BatchPtr, true /* Single Consumer Queue */>;
    using BatchCount        = uint64_t;
    using FrameCount        = file_processor::FrameCount;
    using FrameNumber       = file_processor::FrameNumber;
    using FrameRange        = file_processor::FrameRange;
    using ProcessBlockState = file_processor::ProcessBlockState;

    constexpr static FrameNumber kMaxFrameNumber = std::numeric_limits<FrameNumber>::max();
    constexpr static BatchCount  kMaxBatchCount  = std::numeric_limits<BatchCount>::max();

    AsyncProcessor(FileProcessor& file_processor, BlockParser& block_parser) :
        file_processor_(file_processor), block_parser_(block_parser), async_batch_iterator_()
    {}
    ~AsyncProcessor();
    void LaunchAsyncThread();
    void NotifyBatchIndexDequeued(BatchCount frame_index);

    // Adapts the async thread-safe queue. Blocks on Advance() until a batch is available.
    // Blocking occurs here — not hidden inside BlockIterator construction.
    class AsyncBatchIterator : public file_processor::BatchIterator
    {
      public:
        AsyncBatchIterator() = default;
        explicit AsyncBatchIterator(AsyncProcessor& async_processor, AsyncBatchQueue& queue) :
            async_processor_(&async_processor), queue_(&queue)
        {
            Advance();
        }
        void Advance() override;

      private:
        AsyncProcessor*  async_processor_{ nullptr }; // For NotifyFrameIndexDequeued
        AsyncBatchQueue* queue_{ nullptr };
    };

    AsyncBatchIterator& GetBatchIterator() { return async_batch_iterator_; }
    void                SetPreloadFrameRange(const FrameRange& frame_range);
    void                SetQuitBeforeFrame(FrameNumber frame_number);

#if defined(ASYNC_PROCESSING_INSTRUMENTATION)
    class AsyncInstrumentation
    {
      public:
        ~AsyncInstrumentation();
        void Dump(bool reset);

        void AddFrame() { ++total_frames_; }
        void AddBatchesPending(FrameCount pending_batches);
        void AddLowWaterFlush(FrameCount frame_index, BatchCount batch_index, BatchCount pending_batches);
        void AddHighwaterWait(FrameCount frame_index, BatchCount batch_index, BatchCount pending_batches);
        void AddBatch(const BlockBatch::BatchPtr&    batch,
                      FrameCount                     frame_index,
                      BatchCount                     batch_index,
                      const std::atomic<BatchCount>& dequeued_batches);
        void AddBlock() { ++total_blocks_; }
        void AddPolicyChange(BlockParser::DecompressionPolicy from, BlockParser::DecompressionPolicy to);
        void IncrementPolicyCount(const BlockParser& parser) { ++policy_count_[int(parser.GetDecompressionPolicy())]; }
        void AddPendingAtWait(FrameCount                     frame_index,
                              BatchCount                     batch_index,
                              const std::atomic<BatchCount>& dequeued_batches);

      private:
        FrameCount total_frames_  = 0;
        uint64_t   total_batches_ = 0;
        uint64_t   total_bytes_   = 0;
        uint64_t   total_unused_  = 0;
        uint64_t   total_blocks_  = 0;
        FrameCount waits_         = 0;
        FrameCount low_water_     = 0;
        FrameCount starve_        = 0;
        FrameCount near_starve_   = 0;
        FrameCount total_pending_ = 0;
        enum QueueStatus
        {
            kLowWater  = 0,
            kHighWater = 1,
            kFlush     = 2,
            kWait      = 3,
            kAddBatch  = 4
        };

        struct QueueEvent
        {
            FrameCount  frame_index;
            BatchCount  batch_index;
            BatchCount  pending_batches;
            QueueStatus status;
        };
        std::deque<QueueEvent>    queue_events_;
        std::optional<FrameCount> preload_pending_at_wait_ = std::nullopt;

        std::array<FrameCount, 3>                policy_count_{};
        std::array<std::array<FrameCount, 3>, 3> policy_change_{};
    };
#else  // !ASYNC_PROCESSING_INSTRUMENTATION)
    class AsyncInstrumentation
    {
      public:
        using FrameCount = file_processor::FrameCount;
        void AddFrame() {}
        void Dump(bool reset) {}
        void AddBatchesPending(BatchCount) {}
        void AddLowWaterFlush(FrameCount, BatchCount, BatchCount) {}
        void AddHighwaterWait(FrameCount, BatchCount, BatchCount) {}
        void AddBatch(const BlockBatch::BatchPtr&,
                      FrameCount frame_index,
                      BatchCount batch_index,
                      const std::atomic<BatchCount>&)
        {}
        void AddBlock() {}
        void AddPolicyChange(BlockParser::DecompressionPolicy, BlockParser::DecompressionPolicy) {}
        void IncrementPolicyCount(const BlockParser&) {}
        void AddPendingAtWait(FrameCount, BatchCount, const std::atomic<BatchCount>&) {}
    };
#endif // ASYNC_PROCESSING_INSTRUMENTATION)

  private:
    // Async processing throttle boundaries.  Values are in terms of batches async_thread is ahead of dispatching thread
    // NOTE: These values are intial guesses only. Tuning could/should be done.
    constexpr static BatchCount kLowWater             = 1; // Flush current batch if not this many batches queued
    constexpr static BatchCount kSoftLowWater         = 2; // Flush current batch if more than half full
    constexpr static BatchCount kAsyncDecompressNever = 4; // Offload decompression to dispatch when below this limit
    constexpr static BatchCount kAsyncDecompressOptimized = 8;  // Do decompression of smaller blocks on async_thread_
    constexpr static BatchCount kAsyncDecompressAlways    = 16; // Do all decompression on async_thread_

    // Note: the offset are intentional s.t. we don't beat agains the hysteresis boundaries above
    constexpr static BatchCount kAsyncResume = kAsyncDecompressOptimized + 1; // Unblock condition predicate criteria
    constexpr static BatchCount kAsyncWait =
        kAsyncDecompressAlways + 1; // Go into condition variable wait when above this limit

    void WaitForBatchCount(BatchCount wait_target);
    void ThrottleQueue();
    void AdjustDecompressionPolicy(BatchCount pending_batches);

    void AddResultsBlock(FrameNumber frame_number, BlockIOError error_state, ProcessBlockState state);
    void AddContinueBatch();

    // This is the block loading and processing child thread.
    void ThreadMain();

    // State objects from file file processor we need to access in the async thread.
    FileProcessor& file_processor_; // AsyncProcessor is a friend of FileProcessor.
    BlockParser&   block_parser_;

    // Thread Control group: (constructive alignment)
    //  This is state primarly accessed by the async thread, and only occasionally read by the main thread, so we want
    //  to keep it together and away from the main thread accessed state to avoid cache thrashing on the async thread
    //  when the main thread is reading state.
    //
    // Note:
    // preload frame range is only used for preload, but we need it to control async processing w.r.t. the preload
    // frame range.  During preload, different rules apply. Highwater becomes "all frames in preload range" and
    // decompression policy is kAlways.
    alignas(util::kConstructiveAlign) uint64_t quit_before_frame_{ kMaxFrameNumber };
    FrameRange        preload_frame_range_{};
    std::atomic<bool> keep_alive_{ false }; // Thread teardown control

    FrameCount           enqueued_frame_index_{ 0 };
    BatchCount           enqueued_batch_index_{ 0 };
    AsyncInstrumentation async_stats_;

    // Shared Control group: (constructive alignment)
    alignas(util::kConstructiveAlign) std::mutex throttle_mutex_;
    std::atomic<BatchCount> throttle_wait_target_{ kMaxBatchCount };
    std::condition_variable throttle_cv_;

    // Cache line isolated
    //  This state is frequently accessed by both thread, but not at exactly the same time or frequency, so we need
    //  these to be on separate cache lines to avoid thrashing when both threads are accessing them, and the need to be
    //  separated both from the Control groun and each other to avoid thrashing between them.
    alignas(util::kDestructiveAlign) AsyncBatchQueue batch_queue_;
    alignas(util::kDestructiveAlign) std::atomic<BatchCount> last_dequeued_batch_{ 0 };

    // Main thread only group:
    //  This state is only accessed by the main thread.
    alignas(util::kDestructiveAlign) std::thread async_thread_;
    AsyncBatchIterator async_batch_iterator_{};
};

GFXRECON_BEGIN_NAMESPACE(file_processor)
class AsyncProcessPolicy
{
  public:
    using AsyncInstrumentation = decode::AsyncProcessor::AsyncInstrumentation;
    AsyncProcessPolicy(FileProcessor& file_processor, AsyncInstrumentation& async_stats) :
        file_processor_(file_processor), async_stats_(async_stats)
    {}
    constexpr static bool kUpdateDispatchState = false;
    bool                  ContinueBlockProcessing(uint64_t block_index);
    ProcessBlockState     Dispatch(uint64_t block_index, ParsedBlock& block)
    {
        async_stats_.AddBlock();
        return ProcessBlockState::kContinue;
    }

  private:
    FileProcessor&        file_processor_;
    AsyncInstrumentation& async_stats_;
};

GFXRECON_END_NAMESPACE(file_processor)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_ASYNC_PROCESSOR_H
