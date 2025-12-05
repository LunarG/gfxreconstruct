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

    // Preloads *count* frames to continuous, expandable memory buffer
    void PreloadNextFrames(size_t count);

  protected:
    bool PreloadBlocksOneFrame();
    bool ProcessBlocksOneFrame() override;

  private:
    // Read and parse all blocks for one frame
    struct QueuedBlock
    {
        uint64_t    block_index;
        ParsedBlock block;
        QueuedBlock()                              = delete;
        QueuedBlock(QueuedBlock&&) noexcept        = default;
        QueuedBlock& operator=(QueuedBlock&&)      = default;
        QueuedBlock(const QueuedBlock&)            = delete;
        QueuedBlock& operator=(const QueuedBlock&) = delete;
        QueuedBlock(uint64_t block_index_, ParsedBlock&& block_) : block_index(block_index_), block(std::move(block_))
        {}
    };

    using ParsedBlockQueue = std::deque<QueuedBlock>;
    ParsedBlockQueue pending_parsed_blocks_;
    struct PreloadedFrame
    {
        uint64_t         frame_number;
        ParsedBlockQueue blocks;

        PreloadedFrame()                                 = default;
        PreloadedFrame(PreloadedFrame&&) noexcept        = default;
        PreloadedFrame(const PreloadedFrame&)            = delete;
        PreloadedFrame& operator=(const PreloadedFrame&) = delete;
        PreloadedFrame(uint64_t frame_number_, ParsedBlockQueue&& blocks_) :
            frame_number(frame_number_), blocks(std::move(blocks_))
        {}
    };

    ProcessBlockState ReplayOneFrame(PreloadedFrame& frame);
    void              CleanupReplay();

    std::deque<PreloadedFrame>  preload_frames_;
    std::vector<PreloadedFrame> replayed_preload_frames_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_PRELOAD_FILE_PROCESSOR_H
