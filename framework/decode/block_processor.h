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

#ifndef GFXRECON_DECODE_BLOCK_PROCESSOR_H
#define GFXRECON_DECODE_BLOCK_PROCESSOR_H

#include "decode/block_parser.h"
#include "decode/file_processor_types.h"
#include "format/format.h"
#include "util/clock_cache.h"
#include "util/compressor.h"
#include "util/defines.h"
#include "util/file_input_stream.h"
#include "util/logging.h"

#include <deque>
#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Open struct holding all process-side (I/O and parse thread) state for FileProcessor.
// In async mode, ownership transfers to AsyncProcessor at InitializeFrameProcessing time;
// FileProcessor's handle becomes null, making cross-thread access a compile error.
struct BlockProcessor
{
    // Frame/block/error tracking — written exclusively by the active loading path.
    alignas(util::kConstructiveAlign) uint64_t frame_number{ file_processor::kFirstFrame };
    BlockIOError error_state{ kErrorInvalidFileDescriptor };
    uint64_t     block_index{ 0 };

    // Cumulative read metrics forwarded to dispatch side via ProcessBlocksResult snapshots.
    uint64_t bytes_read{ 0 };
    bool     capture_uses_frame_markers{ false };
    bool     file_supports_frame_markers{ false };
    bool     pending_capture_uses_frame_markers{ false };

    // Frame offset for trimmed captures: set from the state-end marker's frame number.
    uint64_t first_frame{ file_processor::kFirstFrame + 1 };

    // Block-index–based skip list; on_complete fires once all targeted blocks are skipped.
    std::unique_ptr<file_processor::BlockSkip> block_skip;
    std::unordered_set<uint64_t>               pending_blocks_to_skip;

    // Parameters supplied to InitializeFrameProcessing.
    file_processor::FrameProcessingParams params;

    // I/O and parse machinery.
    std::unique_ptr<util::Compressor> compressor;
    std::unique_ptr<BlockParser>      block_parser;

    // Stack of active input files; the top entry is the currently-read file.
    struct ActiveFileContext
    {
        ActiveFileContext(FileInputStreamPtr&& active_file_, bool execute_til_eof_ = false) :
            active_file(std::move(active_file_)), execute_till_eof(execute_til_eof_)
        {}

        FileInputStreamPtr active_file;
        uint32_t           remaining_commands{ 0 };
        bool               execute_till_eof{ false };
    };
    std::deque<ActiveFileContext> file_stack;

    // LRU cache of open FileInputStreams, keyed by filename (for ExecuteBlocksFromFile reuse).
    struct InputStreamGetKey
    {
        const std::string& operator()(const FileInputStreamPtr& input_stream)
        {
            GFXRECON_ASSERT(input_stream);
            return input_stream->GetFilename();
        }
    };
    using ActiveStreamCache = util::ClockCache<FileInputStreamPtr, 3, std::string, InputStreamGetKey>;
    ActiveStreamCache stream_cache;
    std::string       absolute_path;

    // Capture-file metadata — const after Initialize().
    format::FileHeader                  file_header{};
    std::vector<format::FileOptionPair> file_options;
    format::EnabledOptions              enabled_options{};
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_BLOCK_PROCESSOR_H
