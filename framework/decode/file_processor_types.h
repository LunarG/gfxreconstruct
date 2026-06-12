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
#include <functional>
#include <limits>
#include <deque>
#include <optional>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class AnnotationHandler;
class ApiDecoder;
class FileProcessor;

GFXRECON_BEGIN_NAMESPACE(file_processor)

// ProcessBlocks specific status.
enum class ProcessBlockState : int32_t
{
    // Negative values indicate terminal states. Do not call ProcessBlocks again after receiving these.
    //
    // Returned when ProcessBlocks ...
    kFrameBoundary = 1,  // encountered a frame boundary
    kContinue      = 0,  // never returned by ProcessBlocks. Denotes placeholder/noop ProcessBlocksResult.
    kEndProcessing = -1, // completed processing (block limit reached or decoder complete)
    kError         = -2, // encountered an error
    kEndOfFile     = -3, // clean EOF on the root capture file
};

// Stores block processing state at return of ProcessBlocks in async or preload mode.
// Constructed either as a full process-side result (has_process_state = true) or as a
// dispatch-side exit signal carrying only state and error (has_process_state = false).
using FrameCount  = uint64_t;
using FrameNumber = uint64_t;
struct ProcessBlocksResult
{
    // Always meaningful.
    ProcessBlockState state{ ProcessBlockState::kContinue };
    BlockIOError      error{ BlockIOError::kErrorNone };

    // Process-side snapshot fields; only valid when has_process_state is true.
    // NOTE: frame_number is the *next* frame -- snapshot of process_frame_number_ at return.
    uint64_t frame_number{ 0U };
    uint64_t bytes_read{ 0 };
    bool     capture_uses_frame_markers{ false };
    bool     file_supports_frame_markers{ false };
    bool     has_process_state{ false };
    // Padding for alignment (5 bytes)

    ProcessBlocksResult() = default;

    // Dispatch-side exit: state and error only; no valid process-side snapshot.
    ProcessBlocksResult(ProcessBlockState s, BlockIOError e) : state(s), error(e) {}

    // Process-side result: full snapshot.
    ProcessBlocksResult(
        ProcessBlockState s, BlockIOError e, uint64_t frame, uint64_t bytes, bool markers, bool file_markers) :
        state(s),
        error(e), frame_number(frame), bytes_read(bytes), capture_uses_frame_markers(markers),
        file_supports_frame_markers(file_markers), has_process_state(true)
    {}
};

// Assert struct size to assure changes are intentional and optimal w.r.t. placement and padding
static_assert(sizeof(ProcessBlocksResult) <= 32, "ProcessBlocksResult must not exceed 32 bytes");

// Zero-based index of the first frame.
constexpr FrameNumber kFirstFrame = 0;

// Maximum representable frame number; used as a sentinel meaning "no upper bound".
constexpr FrameNumber kMaxFrame = std::numeric_limits<FrameNumber>::max();

// Decrement a frame number, preserving kMaxFrame and preventing underflow at 0.
inline constexpr FrameNumber DecrementFrame(FrameNumber frame)
{
    return (frame != 0 && frame != kMaxFrame) ? frame - 1 : frame;
}

// Range of frame numbers with half open [begin(), end()) semantics.
struct FrameRange
{
    FrameNumber begin_frame{ 0 };
    FrameNumber end_frame{ 0 };

    FrameNumber begin() const noexcept { return begin_frame; }
    FrameNumber end() const noexcept { return end_frame; }
    bool        contains(FrameNumber frame) const noexcept { return (begin_frame <= frame) && (frame < end_frame); }
    bool        empty() const noexcept { return begin_frame == end_frame; }
    bool        valid() const noexcept { return begin_frame <= end_frame; }

    template <typename T, typename U>
    static FrameRange MakeFromOneBased(T inclusive_begin1, U exclusive_end1)
    {
        return FrameRange(DecrementFrame(GFXRECON_NARROWING_CAST(FrameNumber, inclusive_begin1)),
                          DecrementFrame(GFXRECON_NARROWING_CAST(FrameNumber, exclusive_end1)));
    }

    FrameRange(FrameNumber inclusive_begin, FrameNumber exclusive_end) :
        begin_frame(inclusive_begin), end_frame(exclusive_end)
    {
        GFXRECON_ASSERT(valid());
    }
    FrameRange() = default;
};

// Dispatch-side configuration: the decoders and annotation handler that receive decoded blocks.
// Set before InitializeFrameProcessing(); must not be mutated after async init.
struct DispatchConfig
{
    std::vector<decode::ApiDecoder*> decoders;
    decode::AnnotationHandler*       annotation_handler{ nullptr };
};

// Parameters for InitializeFrameProcessing().
// Default {} gives sync mode with no preload.
struct FrameProcessingParams
{
    bool        async{ false };
    FrameRange  preload_range{};
    FrameNumber quit_before_frame{ kMaxFrame };
    bool        print_block_info{ false };
    int64_t     block_index_from{ 0 };
    int64_t     block_index_to{ 0 };
};

// Iteration framework for traversing ParsedBlocks across batches during replay.
//
// The two-level design allows block consumers to iterate blocks directly as a uniform
// stream, independent of how batches are sourced and packaged. Block consumers should
// not carry batch concerns (transport layering); BatchIterator is the mode seam --
// async and preload require structurally incompatible batch sources. Batch boundaries
// are rare relative to block advances, so virtual dispatch at Advance() amortizes
// cheaply, making a templated design unnecessary.
//
// BatchIterator (abstract, below)
//   Defines the queue protocol. batch_ always holds the current batch; AtEnd() is true
//   when batch_ is null (source exhausted). Two concrete forms:
//     - AsyncBatchIterator: wraps a thread-safe queue. Advance() BLOCKS until the async
//       parse thread delivers a batch or signals EOF. The queue is consumed -- no rewind.
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
//     - Backed by AsyncBatchIterator: single-pass -- the underlying queue is consumed.
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

// Block-level iterator over batches supplied by a BatchIterator.
// Construction reads the current batch head -- no Advance() is triggered.
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

// ProcessBlocks policy definitions.
struct ContinueProcessingPolicy
{
    struct BlockLimitOnly
    {
        constexpr static bool kCheckBlockLimit = true;
        constexpr static bool kCheckDecoders   = false;
    };
    struct DecoderOnly
    {
        constexpr static bool kCheckBlockLimit = false;
        constexpr static bool kCheckDecoders   = true;
    };
    struct CheckBoth
    {
        constexpr static bool kCheckBlockLimit = true;
        constexpr static bool kCheckDecoders   = true;
    };
};

// Functor that tracks a set of block indices to skip during processing.
// Calls on_complete() once all targeted blocks have been skipped.
class BlockSkip
{
  public:
    BlockSkip(std::unordered_set<uint64_t>&& blocks_to_skip, std::function<void()>&& on_complete) :
        blocks_to_skip_(std::move(blocks_to_skip)), on_complete_(std::move(on_complete))
    {}

    bool operator()(uint64_t block_index)
    {
        if (blocks_to_skip_.count(block_index))
        {
            if ((++blocks_skipped_ == blocks_to_skip_.size()) && on_complete_)
            {
                on_complete_();
            }
            return true;
        }
        return false;
    }

  private:
    std::unordered_set<uint64_t> blocks_to_skip_;
    uint64_t                     blocks_skipped_{ 0 };
    std::function<void()>        on_complete_;
};

GFXRECON_END_NAMESPACE(file_processor)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_FILE_PROCESSOR_TYPES_H
