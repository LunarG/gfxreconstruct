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

  private:
    constexpr static size_t kWorkingStoreInitialSize = 4096;

    void              ResetPreload();
    ProcessBlockState PreloadBlocksOneFrame();
    ProcessBlockState ReplayOneFrame();
    void              EnqueueBatch(BlockBatch::BatchPtr&& batch);

    util::HeapBuffer     working_uncompressed_store_;
    BlockBatch::iterator preload_head_;
    BlockBatch*          preload_tail_ = nullptr;
    BlockBatch::iterator replay_cursor_;

    ProcessBlockState final_process_state_{ ProcessBlockState::kError }; // How the last frame preload ended
    bool              preload_contains_frame_stutter_ = false; // Tells replay to ignore first frame boundary block
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_PRELOAD_FILE_PROCESSOR_H
