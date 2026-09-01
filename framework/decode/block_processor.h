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

#include "decode/api_payload.h"
#include "decode/block_buffer.h"
#include "decode/block_parser.h"
#include "decode/file_processor_types.h"
#include "format/api_call_id.h"
#include "format/format.h"
#include "util/clock_cache.h"
#include "util/compressor.h"
#include "util/defines.h"
#include "util/file_input_stream.h"
#include "util/logging.h"

#include <deque>
#include <functional>
#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Forward declarations for ProcessBlocks<Policy> extern template declarations.
// Full definitions are in file_processor_visitors.h and async_processor.h.
GFXRECON_BEGIN_NAMESPACE(file_processor)
class AsyncProcessPolicy;
class PreloadProcessPolicy;
class SynchronousProcessPolicy;
GFXRECON_END_NAMESPACE(file_processor)

// Owns all process-side (I/O and parse thread) state for FileProcessor.
// In async mode, ownership transfers to AsyncProcessor at InitializeFrameProcessing time;
// FileProcessor's block_processor_ becomes null -- any residual block_processor_ access from the dispatch thread
// will null-deref, making the bug immediately detectable.
//
// block_limit is NOT stored here. It lives on FileProcessor as an immutable protected
// member and is propagated into each policy object as a scalar before ProcessBlocks is called.
class BlockProcessor
{
  public:
    // Stack entry for the active input file.
    struct ActiveFileContext
    {
        ActiveFileContext(FileInputStreamPtr&& active_file_, bool execute_til_eof_ = false) :
            active_file(std::move(active_file_)), execute_till_eof(execute_til_eof_)
        {}

        FileInputStreamPtr active_file;
        uint32_t           remaining_commands{ 0 };
        bool               execute_till_eof{ false };
    };

    BlockProcessor();

    // -------------------------------------------------------------------------
    // Init sequence -- called by FileProcessor before async transfer
    // -------------------------------------------------------------------------

    // Opens filename, reads the file header, creates BlockParser.
    // On failure, error_state_ is set; call GetProcessError() to retrieve it.
    bool Initialize(const std::string& filename);

    // Stores params and installs the block_skip functor.
    // skip_on_complete: optional callback fired after all pending_blocks_to_skip_ have been seen.
    void InitializeFrameProcessing(const file_processor::FrameProcessingParams& params,
                                   std::function<void()>&&                      skip_on_complete);

    // -------------------------------------------------------------------------
    // Accessors -- used by FileProcessor and AsyncProcessor after init
    // -------------------------------------------------------------------------

    const format::FileHeader&                  GetFileHeader() const noexcept { return file_header_; }
    const std::vector<format::FileOptionPair>& GetFileOptions() const noexcept { return file_options_; }

    // Clone the process-side compressor for replay-time decompression on the dispatch thread.
    // Must be called before ownership transfers to AsyncProcessor (block_processor_ becomes null after).
    std::unique_ptr<util::Compressor> CreateReplayCompressor() const;

    uint64_t                          GetProcessFrameNumber() const noexcept { return frame_number_; }
    BlockIOError                      GetProcessError() const noexcept { return error_state_; }
    file_processor::FrameNumber       GetQuitBeforeFrame() const noexcept { return params_.quit_before_frame; }
    const file_processor::FrameRange& GetPreloadRange() const noexcept { return params_.preload_range; }

    // Returns the owned BlockParser by reference. Valid while this BlockProcessor is alive.
    BlockParser& GetBlockParser();

    // Returns true if the active file is open and ready for reading.
    bool IsFileValid() const;

    // -------------------------------------------------------------------------
    // Process-side result snapshot
    // -------------------------------------------------------------------------

    file_processor::ProcessBlocksResult MakeResult(file_processor::ProcessBlockState state) const;

    // -------------------------------------------------------------------------
    // Main processing loop (moved from FileProcessor)
    // -------------------------------------------------------------------------

    template <typename Policy>
    file_processor::ProcessBlockState ProcessBlock(Policy& policy, BlockBuffer& block_buffer);

    template <typename Policy>
    file_processor::ProcessBlockState ProcessBlocks(Policy& policy);

    // -------------------------------------------------------------------------
    // ProcessVisitor callbacks -- public because ProcessVisitor dispatches into them
    // -------------------------------------------------------------------------

    bool ProcessFrameDelimiter(format::ApiCallId call_id);
    bool ProcessFrameDelimiter(const FrameEndMarkerArgs& end_frame);
    bool ProcessExecuteBlocksFromFile(const ExecuteBlocksFromFileArgs& execute_blocks_info);
    void ProcessStateEndMarkerFrameState(const StateEndMarkerArgs& state_end);
    void ProcessAnnotation(const AnnotationArgs& annotation);
    void HandleBlockReadError(BlockIOError error_code, const char* error_message);

    // -------------------------------------------------------------------------
    // Called by FileProcessor::SetBlocksToSkip before InitializeFrameProcessing
    // -------------------------------------------------------------------------

    void SetPendingBlocksToSkip(std::unordered_set<uint64_t>&& blocks_to_skip)
    {
        pending_blocks_to_skip_ = std::move(blocks_to_skip);
    }
    bool HasPendingBlocksToSkip() const noexcept { return !pending_blocks_to_skip_.empty(); }

  private:
    // Frame/block/error tracking -- written exclusively by the active loading path.
    uint64_t     frame_number_{ file_processor::kFirstFrame };
    BlockIOError error_state_{ kErrorInvalidFileDescriptor };
    uint64_t     block_index_{ 0 };

    // Cumulative read metrics forwarded to dispatch side via ProcessBlocksResult snapshots.
    uint64_t bytes_read_{ 0 };
    bool     capture_uses_frame_markers_{ false };
    bool     file_supports_frame_markers_{ false };
    bool     pending_capture_uses_frame_markers_{ false };

    // Frame offset for trimmed captures: set from the state-end marker's frame number.
    uint64_t first_frame_{ file_processor::kFirstFrame + 1 };

    // Block-index-based skip list; optional on_complete fires once all targeted blocks are skipped.
    std::unique_ptr<file_processor::BlockSkip> block_skip_;
    std::unordered_set<uint64_t>               pending_blocks_to_skip_;

    // Parameters supplied to InitializeFrameProcessing (quit_before_frame, preload_range, etc.).
    // block_limit is NOT here -- it lives on FileProcessor and is passed into policies as a scalar.
    file_processor::FrameProcessingParams params_;

    // I/O and parse machinery.
    std::unique_ptr<util::Compressor> compressor_;
    std::unique_ptr<BlockParser>      block_parser_;

    // Stack of active input files; the top entry is the currently-read file.
    std::deque<ActiveFileContext> file_stack_;

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
    ActiveStreamCache stream_cache_;
    std::string       absolute_path_;

    // Capture-file metadata -- const after Initialize().
    format::FileHeader                  file_header_{};
    std::vector<format::FileOptionPair> file_options_;
    format::EnabledOptions              enabled_options_{};

    // -------------------------------------------------------------------------
    // Private I/O and parsing helpers (moved from FileProcessor)
    // -------------------------------------------------------------------------

    bool ProcessFileHeader();
    bool ReadBlockBuffer(BlockParser& parser, BlockBuffer& buffer);
    bool ReadBytes(void* buffer, size_t buffer_size);
    void DecrementRemainingCommands();

    file_processor::ProcessBlockState HandleBlockEof(const char* operation, bool report_frame_and_block);
    void                              UpdateEndFrameState();
    void                              PrintBlockInfo() const;

    bool SeekActiveFile(const FileInputStreamPtr& file, int64_t offset, util::platform::FileSeekOrigin origin);
    bool SeekActiveFile(int64_t offset, util::platform::FileSeekOrigin origin);
    bool SetActiveFile(const std::string& filename, bool execute_till_eof);
    bool SetActiveFile(const std::string&             filename,
                       int64_t                        offset,
                       util::platform::FileSeekOrigin origin,
                       bool                           execute_till_eof);

    bool               AtEof() const;
    ActiveFileContext& GetCurrentFile();

    static bool IsFrameDelimiter(format::BlockType block_type, format::MarkerType marker_type);
    bool        IsFrameDelimiter(format::ApiCallId call_id) const;
};

// Explicit instantiation declarations -- definitions live in block_processor.cpp.
extern template file_processor::ProcessBlockState
BlockProcessor::ProcessBlocks<file_processor::PreloadProcessPolicy>(file_processor::PreloadProcessPolicy&);
extern template file_processor::ProcessBlockState
BlockProcessor::ProcessBlocks<file_processor::SynchronousProcessPolicy>(file_processor::SynchronousProcessPolicy&);
extern template file_processor::ProcessBlockState
BlockProcessor::ProcessBlocks<file_processor::AsyncProcessPolicy>(file_processor::AsyncProcessPolicy&);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_BLOCK_PROCESSOR_H
