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

#ifndef GFXRECON_DECODE_FILE_PROCESSOR_TYPES_H
#define GFXRECON_DECODE_FILE_PROCESSOR_TYPES_H

#include "format/format.h"
#include "decode/block_batch.h"
#include "decode/block_parser.h"
#include "util/defines.h"
#include "util/logging.h"
#include "util/thread_safe_queue.h"

#include <array>
#include <atomic>
#include <cinttypes>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <optional>
#include <unordered_map>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class FileProcessor;

GFXRECON_BEGIN_NAMESPACE(file_processor)

// ProcessBlocks specific status.
enum class ProcessBlockState : int32_t
{
    // Negative values indicate terminal states. Do not call ProcessBlocks again after receiving these.
    //
    // Returned when ProcessBlocks ...
    kFrameBoundary = 1,  // encountered a frame boundary
    kRunning       = 0,  // never. Internal state: continue looping in ProcessBlocks
    kEndProcessing = -1, // completed processing (!ContinueDecoding or clean EOF)
    kError         = -2, // encountered an error
};

// Stores block processing state at return of ProcessBlocks in async or preload mode
using FrameCount  = uint64_t;
using FrameNumber = uint64_t;
struct ProcessBlocksResult
{
    FrameCount        index{ 0U };                          // Strictly monotonic index of result
    uint64_t          frame_number{ 0U };                   // Snapshot of process_frame_number_ at return.
    BlockIOError      error{ BlockIOError::kErrorNone };    // Snapshot of the process_error_state_ at return.
    ProcessBlockState state{ ProcessBlockState::kRunning }; // ProcessBlocks return value.
};

using AsyncProcessedBlockQueue = util::ThreadSafeQueue<BlockBatch::BatchPtr, true /* Single Consumer Queue */>;

// Iteration framework for traversing ParsedBlocks across batches during replay.
//
// The two-level design allows block consumers to iterate blocks directly as a uniform
// stream, independent of how batches are sourced and packaged. Block consumers should
// not carry batch concerns (transport layering); BatchIterator is the mode seam —
// async and preload require structurally incompatible batch sources. Batch boundaries
// are rare relative to block advances, so virtual dispatch at Advance() amortizes
// cheaply, making a templated design unnecessary.
//
// BatchIterator (abstract, below)
//   Defines the queue protocol. batch_ always holds the current batch; AtEnd() is true
//   when batch_ is null (source exhausted). Two concrete forms:
//     - AsyncBatchIterator: wraps a thread-safe queue. Advance() BLOCKS until the async
//       parse thread delivers a batch or signals EOF. The queue is consumed — no rewind.
//     - PreloadBatchIterator (preload_file_processor.h): wraps a std::deque<BatchPtr>.
//       Advance() is non-blocking. Rewind() resets the cursor to the deque beginning,
//       making it the only BatchIterator subclass that supports re-traversal.
//
// BlockIterator (below)
//   A standard forward iterator (forward_iterator_tag) over individual ParsedBlocks.
//   Holds a raw BatchIterator* and a ParsedBlock* to the current block.
//   operator++() follows the intra-batch linked list; at the end of a batch it calls
//   BatchIterator::Advance() transparently to move to the next batch.
//   Limitations:
//     - Forward-only: no decrement, no random access.
//     - Backed by AsyncBatchIterator: single-pass — the underlying queue is consumed.
//     - Default-constructed BlockIterator{} is the end sentinel (block_ == nullptr);
//       compare against it to detect exhaustion.
//     - Empty batches are forbidden; asserted in debug builds at construction.
//   Lifetime and uniqueness:
//     - The BatchIterator must outlive any BlockIterator that references it.
//     - At most one BlockIterator may reference a given BatchIterator at a time. Copies
//       share the raw pointer, so both will call Advance() at batch boundaries,
//       corrupting the shared BatchIterator state.
//   Important usage notes:
//     - NextBatch() silently discards all remaining blocks in the current batch.
//     - AsyncBatchIterator::Advance() blocks the calling thread when the queue is empty,
//       waiting for the async parser thread to deliver the next batch.
//   Typical pattern:
//     for (BlockIterator it(&batch_iter); it != BlockIterator{}; ++it) { ... }
//
// For save/restore of a position within a PreloadBatchIterator, see Bookmark in
// preload_file_processor.h. Bookmark is a position snapshot, not an iterator.

// Abstract base for batch-level iteration. Derived classes encapsulate queue semantics;
// BatchIterator::batch_ always holds the current batch (null when exhausted).
class BatchIterator
{
  public:
    using BatchPtr = BlockBatch::BatchPtr;

    virtual ~BatchIterator() = default;

    const BatchPtr& GetBatch() const noexcept { return batch_; }
    bool            AtEnd() const noexcept { return batch_.get() == nullptr; }
    virtual void    Advance() = 0;

  protected:
    BatchPtr batch_{};
};

// Adapts the async thread-safe queue. Blocks on Advance() until a batch is available.
// Blocking occurs here — not hidden inside BlockIterator construction.
class AsyncBatchIterator : public BatchIterator
{
  public:
    AsyncBatchIterator() = default;
    explicit AsyncBatchIterator(AsyncProcessedBlockQueue& queue) : queue_(&queue) { Advance(); }

    void Advance() override
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

  private:
    AsyncProcessedBlockQueue* queue_{ nullptr };
};

// Block-level iterator over batches supplied by a BatchIterator.
// Construction reads the current batch head — no Advance() is triggered.
class BlockIterator
{
  public:
    // Standard iterator type aliases
    using iterator_category = std::forward_iterator_tag;
    using value_type        = ParsedBlock;
    using difference_type   = std::ptrdiff_t;
    using pointer           = ParsedBlock*;
    using reference         = ParsedBlock&;

    BlockIterator() : batch_iter_(nullptr), block_(nullptr) {}
    explicit BlockIterator(BatchIterator* batch_iter) : batch_iter_(batch_iter), block_(nullptr)
    {
        if (batch_iter_ != nullptr && !batch_iter_->AtEnd())
        {
            // We don't support empty batches
            GFXRECON_ASSERT(batch_iter_->GetBatch()->Head() != nullptr);
            block_ = batch_iter_->GetBatch()->Head();
        }
    }

    reference operator*() const { return *block_; }
    pointer   operator->() const { return block_; }

    BlockIterator& operator++()
    {
        GFXRECON_ASSERT(block_ != nullptr);
        block_ = block_->GetNext();
        if (block_ == nullptr)
        {
            AdvanceBatch();
        }
        return *this;
    }
    bool operator==(const BlockIterator& other) const { return block_ == other.block_; }
    bool operator!=(const BlockIterator& other) const { return block_ != other.block_; }

    const BlockBatch::BatchPtr& GetBatch() const noexcept
    {
        GFXRECON_ASSERT(batch_iter_ != nullptr);
        return batch_iter_->GetBatch();
    }
    void NextBatch()
    {
        block_ = nullptr;
        GFXRECON_ASSERT(batch_iter_ != nullptr);
        AdvanceBatch();
    }

    pointer GetBlock() const noexcept { return block_; }
    bool    BelongsTo(const BatchIterator& iter) const noexcept { return batch_iter_ == &iter; }

    // Tag-based constructor for bookmark restore only. Caller guarantees block is within
    // the BatchIterator's current batch. Debug build verifies via BlockBatch::ContainsBlock.
    struct ForceLocationTag
    {};
    BlockIterator(ForceLocationTag, BatchIterator& batch_iter, pointer block) : batch_iter_(&batch_iter), block_(block)
    {
        GFXRECON_ASSERT(!batch_iter_->AtEnd());
        GFXRECON_ASSERT(batch_iter_->GetBatch()->ContainsBlock(block_));
    }

  private:
    void AdvanceBatch()
    {
        GFXRECON_ASSERT(batch_iter_ != nullptr);
        batch_iter_->Advance();
        if (!batch_iter_->AtEnd())
        {
            block_ = batch_iter_->GetBatch()->Head();
        }
    }

    BatchIterator* batch_iter_;
    pointer        block_;
};

// Circular buffer of final frame indices of the last kSize enqueued batches, used for async throttle logic
class AsyncBatchFramesRing
{
  public:
    // We are tracking the last frame index for the last kSize batches, for low water and high water calculations.
    constexpr static size_t kSize = 4;
    constexpr static size_t kMask = kSize - 1;
    static_assert((kSize & kMask) == 0, "Size must be a power of two for masking to work");

    using value_type = FrameCount;

    // Push to the back of the ring, overwriting front.
    void Push(value_type frame_index)
    {
        buffer_[batch_index_ & kMask] = frame_index;
        ++batch_index_;
    }

    // Offset is how many batches back we want to look, with 0 being the current batch which has not yet been
    // enqueued, and thus for which no frame index has yet been recorded (and thus should not be accessed) (think of
    // Back as end() - offset) offset 1 is the last enqueued batch offset 2 is the next to last, etc.
    value_type Back(size_t offset) const noexcept
    {
        GFXRECON_ASSERT((0 < offset) && (offset <= kSize));
        // The addition of kSize allows use to ignore startup issues. Anything before zero is zero.
        size_t index = (batch_index_ + kSize - offset) & kMask;
        return buffer_[index];
    }

  private:
    using Store = std::array<value_type, kSize>;
    Store      buffer_{};
    FrameCount batch_index_ = 0;
};

#if defined(ASYNC_PROCESSING_INSTRUMENTATION)
class AsyncInstrumentation
{
  public:
    ~AsyncInstrumentation()
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
            GFXRECON_WRITE_CONSOLE("Total always %" PRIu64,
                                   policy_count_[int(BlockParser::DecompressionPolicy::kAlways)]);
            GFXRECON_WRITE_CONSOLE("Total optimized %" PRIu64,
                                   policy_count_[int(BlockParser::DecompressionPolicy::kQueueOptimized)]);
            GFXRECON_WRITE_CONSOLE("Total never %" PRIu64,
                                   policy_count_[int(BlockParser::DecompressionPolicy::kNever)]);

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
                        GFXRECON_WRITE_CONSOLE("%s: Frame %" PRIu64 ": Dequeued: %" PRIu64
                                               " Prior Batch Frame: %" PRIu64,
                                               kQueueStatusNames[int(event.status)],
                                               event.frame_index,
                                               event.dequed_frames,
                                               event.prior_frame);
                    }
                    else if (event.status == QueueStatus::kHighWater)
                    {
                        const char* wait_target_str = (event.wait_for_prev) ? "(prev batch)" : "(excess batch)";
                        GFXRECON_WRITE_CONSOLE("%s: Frame %" PRIu64 ": Dequeued: %" PRIu64 " Wait Target: %" PRIu64
                                               "%s",
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

    void AddFrame() { ++total_frames_; }
    void AddFramePending(FrameCount pending_frames)
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

    void AddLowWaterFlush(FrameCount frame_index, FrameCount dequeued_frames, FrameCount prior_batch_frames)
    {
        ++low_water_;
        queue_events_.push_back({ frame_index, dequeued_frames, QueueStatus::kLowWater, prior_batch_frames, true });
    }

    void AddHighwaterWait(FrameCount frame_index,
                          FrameCount dequeued_frames,
                          FrameCount wait_target,
                          bool       excess_batch_pending)
    {
        ++waits_;
        bool prior_batch_wait = !excess_batch_pending;
        queue_events_.push_back(
            { frame_index, dequeued_frames, QueueStatus::kHighWater, wait_target, prior_batch_wait });
    }

    void AddBatch(const BlockBatch::BatchPtr& batch, FrameCount frame_index)
    {
        ++total_batches_;
        total_unused_ += batch->BytesRemaining();
        total_bytes_ += (batch->kCapacity - batch->BytesRemaining()); // linear usage only
        queue_events_.push_back({ frame_index, 0, QueueStatus::kFlush, 0, true });
    }

    void AddBlock() { ++total_blocks_; }

    void AddPolicyChange(BlockParser::DecompressionPolicy from, BlockParser::DecompressionPolicy to)
    {
        if (from != to)
        {
            ++policy_change_[int(from)][int(to)];
        }
    }
    void IncrementPolicyCount(const BlockParser& parser) { ++policy_count_[int(parser.GetDecompressionPolicy())]; }

    void AddPendingAtWait(FrameCount enqueued_frames, const std::atomic<FrameCount>& dequeued_frames)
    {
        preload_pending_at_wait_.emplace(enqueued_frames - dequeued_frames.load(std::memory_order_acquire));
    }

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
        kFlush     = 2
    };

    struct QueueEvent
    {
        FrameCount  frame_index;
        FrameCount  dequed_frames;
        QueueStatus status;
        FrameCount  prior_frame;
        bool        wait_for_prev;
    };
    std::deque<QueueEvent> queue_events_;

    std::optional<FrameCount> preload_pending_at_wait_ = std::nullopt;

    std::array<FrameCount, 3>                policy_count_{};
    std::array<std::array<FrameCount, 3>, 3> policy_change_{};
};
#else  // !ASYNC_PROCESSING_INSTRUMENTATION)
class AsyncInstrumentation
{
  public:
    void AddFrame() {}
    void AddFramePending(FrameCount) {}
    void AddLowWaterFlush(FrameCount, FrameCount, FrameCount) {}
    void AddHighwaterWait(FrameCount, FrameCount, FrameCount, bool) {}
    void AddBatch(const BlockBatch::BatchPtr&, FrameCount) {}
    void AddBlock() {}
    void AddPolicyChange(BlockParser::DecompressionPolicy, BlockParser::DecompressionPolicy) {}
    void IncrementPolicyCount(const BlockParser&) {}
    void AddPendingAtWait(FrameCount, const std::atomic<FrameCount>&) {}
};
#endif // ASYNC_PROCESSING_INSTRUMENTATION)

GFXRECON_END_NAMESPACE(file_processor)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_FILE_PROCESSOR_TYPES_H
