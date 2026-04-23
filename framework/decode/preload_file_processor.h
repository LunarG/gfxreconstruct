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

#ifndef GFXRECON_DECODE_PRELOAD_FILE_PROCESSOR_H
#define GFXRECON_DECODE_PRELOAD_FILE_PROCESSOR_H

#include <deque>
#include <optional>

#include "decode/file_processor.h"
#include "format/format_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class PreloadFileProcessor : public FileProcessor
{
  public:
    using Base = FileProcessor;
    PreloadFileProcessor();

    // Returns true if there are more frames to process, false if all frames have been processed or an error has occured
    bool ProcessNextFrame() override;

    // Preload one frame, set looping state
    void PreloadLoopFrame();

    /// Preloads `count` frames to continuous, expandable memory buffer.
    void PreloadNextFrames(size_t count);

  private:
    void   ReplayAndClearStutterFrame();
    size_t PreloadNextFramesSync(size_t count);
    void   ResetPreload();
    size_t PreloadNextFramesAsync(size_t count);
    void   EnqueueBatch(BlockBatch::BatchPtr&& batch);

    bool          replay_from_queue_{ false };
    FrameCount    preload_last_index_{ 0 };
    BlockIterator preload_block_iterator_;

    using PreloadBlockQueue = std::deque<BlockBatch::BatchPtr>;

    // Forward declaration — defined below after PreloadBatchIterator (which it stores by value)
    struct Bookmark;

    // Adapts the preload deque as a BatchIterator. Rewind() loads the first batch and
    // resets the cursor; Advance() steps to the next batch.
    class PreloadBatchIterator : public file_processor::BatchIterator
    {
      public:
        PreloadBatchIterator() : queue_(nullptr), cursor_() {}
        PreloadBatchIterator(PreloadBlockQueue& queue) : queue_(&queue), cursor_(queue.begin()) {}

        void Advance() override { LoadNext(); }

        // Preload-specific: reset cursor and load the first batch.
        void Rewind()
        {
            cursor_ = queue_->begin();
            LoadNext();
        }
        bool empty() const { return AtEnd(); }

        // Snapshot the current position of bit. bit must BelongsTo(*this).
        Bookmark MakeBookmark(const file_processor::BlockIterator& bit) const;

      private:
        void LoadNext() { batch_ = (cursor_ != queue_->end()) ? *cursor_++ : nullptr; }

        PreloadBlockQueue*          queue_;
        PreloadBlockQueue::iterator cursor_;
    };

    PreloadBlockQueue    preload_queue_;
    PreloadBatchIterator preload_batch_iterator_;

    // Immutable position snapshot within a PreloadBatchIterator traversal.
    // See file_processor_types.h for the BatchIterator / BlockIterator framework.
    //
    // Unlike BlockIterator (a mutable, forward-only, single-pass cursor), a Bookmark captures
    // the full PreloadBatchIterator state (deque cursor + batch_) and a ParsedBlock* at the
    // bookmarked position. It may be copied freely and RestoreInto() may be called multiple
    // times on independent targets to replay from the same point.
    //
    // Created:  Bookmark bm = pbi.MakeBookmark(bit);  // bit must BelongsTo(pbi)
    // Restored: BlockIterator it = bm.RestoreInto(pbi);
    //
    // RestoreInto() is [[nodiscard]]: discarding the returned BlockIterator silently loses the
    // only handle to the restored position. Bookmarks are only meaningful for
    // PreloadBatchIterator; AsyncBatchIterator cannot be bookmarked because its queue is
    // consumed on read and the underlying data is not retained.
    struct Bookmark
    {
        // Overwrites target with the saved PBI state and returns a BlockIterator positioned at
        // the bookmarked block within target. Do not discard — it is the only recovery of the position.
        [[nodiscard]] file_processor::BlockIterator RestoreInto(PreloadBatchIterator& target) const;

      private:
        friend class PreloadBatchIterator;
        Bookmark(const PreloadBatchIterator& pbi, ParsedBlock* block) : pbi_(pbi), block_(block) {}

        PreloadBatchIterator pbi_; // copy of PBI at bookmark time; cursor_ and batch_ already positioned
        ParsedBlock*         block_;
    };

    /// Skips state blocks from a bookmarked position. Restores start into a local PBI to walk;
    /// returns a Bookmark at the post-StateEnd position, or start unchanged if none found.
    static Bookmark SkipStateBlocks(uint64_t frame_number, Bookmark start);

    bool                    loop_replay_{ false };
    std::optional<Bookmark> loop_bookmark_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_PRELOAD_FILE_PROCESSOR_H
