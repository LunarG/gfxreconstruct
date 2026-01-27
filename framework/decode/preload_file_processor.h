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

    // Preloads *count* frames to continuous, expandable memory buffer
    void PreloadNextFrames(size_t count);

    // If true, after replaying a preloaded frame, advance to the next preloaded frame.
    // Otherwise, remain on the current preloaded frame so that it can be replayed again.
    void SetAdvanceToNextFrame(bool advance) { advance_to_next_frame = advance; }

  private:
    // Read and parse all blocks for one frame
    using ParsedBlockQueue  = std::deque<ParsedBlock>;
    using ParsedBlockReplay = std::vector<ParsedBlockQueue::value_type>;

    // This structure is optimized for most efficient replay, even at the expense
    // of some preload overhead
    struct PreloadedFrame
    {
        uint64_t          frame_number;
        ParsedBlockReplay blocks;

        PreloadedFrame()                                 = default;
        PreloadedFrame(PreloadedFrame&&) noexcept        = default;
        PreloadedFrame(const PreloadedFrame&)            = delete;
        PreloadedFrame& operator=(const PreloadedFrame&) = delete;
        PreloadedFrame(uint64_t frame_number_) : frame_number(frame_number_), blocks() {}

        // Blocks must be iterable container of ParsedBlock, with a size() method
        template <typename Blocks>
        void AppendMovedBlocks(Blocks& from_blocks)
        {
            blocks.reserve(blocks.size() + from_blocks.size());
            blocks.insert(
                blocks.end(), std::make_move_iterator(from_blocks.begin()), std::make_move_iterator(from_blocks.end()));
        }
    };
    using PreloadedFramePtr = std::unique_ptr<PreloadedFrame>;
    using PreloadedFrames   = std::vector<PreloadedFramePtr>;
    using PreloadedFramesIt = PreloadedFrames::iterator;

    ProcessBlockState PreloadBlocksOneFrame(ParsedBlockQueue& frame_queue);
    ProcessBlockState ReplayOneFrame(PreloadedFrame& frame);
    bool              AdvanceToNextFrame(ProcessBlockState process_result);

    PreloadedFrames   preloaded_frames_;
    PreloadedFramesIt current_preloaded_frame_; // Only valid when preloaded_frames_ is not empty
    ProcessBlockState final_process_state_{ ProcessBlockState::kError }; // How the last frame preload ended
    bool              advance_to_next_frame{ true };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_PRELOAD_FILE_PROCESSOR_H
