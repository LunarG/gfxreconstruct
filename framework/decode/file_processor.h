/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018-2025 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_FILE_PROCESSOR_H
#define GFXRECON_DECODE_FILE_PROCESSOR_H

#include "format/api_call_id.h"
#include "format/format.h"
#include "decode/annotation_handler.h"
#include "decode/api_decoder.h"
#include "decode/api_payload.h"
#include "decode/block_parser.h"
#include "decode/block_processor.h"
#include "decode/file_processor_types.h"
#include "util/defines.h"
#include "decode/decode_allocator.h"
#include "util/logging.h"
#include "util/file_input_stream.h"

#include <algorithm>
#include <cstdint>
#include <deque>
#include <functional>
#include <memory>
#include <string>
#include <type_traits> // ParsedBlock
#include <unordered_set>
#include <utility>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Forward declarations
class AsyncProcessor;

GFXRECON_BEGIN_NAMESPACE(file_processor)
class AsyncProcessPolicy;
class DispatchVisitor;
class PreloadProcessPolicy;
class ProcessVisitor;
class SynchronousProcessPolicy;
GFXRECON_END_NAMESPACE(file_processor)

class FileProcessor
{
  public:
    using BlockIterator         = file_processor::BlockIterator;
    using DispatchVisitor       = file_processor::DispatchVisitor;
    using FrameNumber           = file_processor::FrameNumber;
    using FrameCount            = file_processor::FrameCount;
    using FrameRange            = file_processor::FrameRange;
    using FrameProcessingParams = file_processor::FrameProcessingParams;
    using ProcessBlockState     = file_processor::ProcessBlockState;
    using ProcessBlocksResult   = file_processor::ProcessBlocksResult;
    using DispatchConfig        = file_processor::DispatchConfig;
    using ProcessVisitor        = file_processor::ProcessVisitor;
    using BlockSkip             = file_processor::BlockSkip;

    constexpr static FrameNumber kFirstFrame = 0;
    constexpr static FrameNumber kMaxFrame   = file_processor::kMaxFrame;
    static FrameNumber           DecrementFrame(FrameNumber f) { return file_processor::DecrementFrame(f); }

    FileProcessor(uint64_t block_limit = 0);

    virtual ~FileProcessor();

    void WaitDecodersIdle();

    void SetAnnotationProcessor(AnnotationHandler* handler) { config_.annotation_handler = handler; }

    void AddDecoder(ApiDecoder* decoder) { config_.decoders.push_back(decoder); }

    void RemoveDecoder(ApiDecoder* decoder)
    {
        auto& d = config_.decoders;
        d.erase(std::remove(d.begin(), d.end(), decoder), d.end());
    }

    bool Initialize(const std::string& filename);

    // Called implicitly by ProcessAllFrames() and directly by Application::Run()
    // Must be called at most once after Initialize() and before ProcessNextFrame()
    // Default params{} gives sync mode with no preload. Block limit is set via the constructor.
    bool InitializeFrameProcessing(const FrameProcessingParams& params = {});

    bool IsFrameProcessingInitialized() const { return frame_processing_initialized_; }

    // May be called after Initialize() and before InitializeFrameProcessing().
    // Safe to call even after Initialize() re-creates the BlockProcessor.
    void SetBlocksToSkip(const std::unordered_set<uint64_t>& blocks_to_skip);

    // In async mode, skip completion is reported only after dispatch reaches this
    // in-band marker. This means the consumer has observed the stream past all
    // skipped blocks, not merely that the process thread has read and omitted them.
    bool IsSkippingFinished() const { return dispatch_skipping_finished_; }

    // Returns true if there are more frames to process, false if all frames have been processed or an error has
    // occurred.  Use GetErrorState() to determine error condition.
    virtual bool ProcessNextFrame();

    // Returns false if processing failed.  Use GetErrorState() to determine error condition for failure case.
    bool ProcessAllFrames();

    const std::vector<format::FileOptionPair>& GetFileOptions() const { return proc_->file_options; }

    // Application facing interface returns the *dispatched* frame and block index, to preserve expected semantics.
    uint64_t GetCurrentFrameNumber() const noexcept { return dispatch_frame_number_; }
    uint64_t GetCurrentBlockIndex() const noexcept { return dispatch_block_index_; }

    bool         GetLoadingTrimmedState() const { return loading_trimmed_capture_state_; }
    uint64_t     GetNumBytesRead() const { return dispatch_bytes_read_; }
    BlockIOError GetErrorState() const { return dispatch_error_state_; }

    bool EntireFileWasProcessed() const { return dispatch_terminal_state_ == ProcessBlockState::kEndOfFile; }

    bool                      UsesFrameMarkers() const { return dispatch_capture_uses_frame_markers_; }
    bool                      FileSupportsFrameMarkers() const { return dispatch_file_supports_frame_markers_; }
    const format::FileHeader& GetFileHeader() const { return proc_->file_header; }

    // Returns whether the call_id is a frame delimiter and handles frame delimiting logic
    // Called from ProcessVisitor.
    bool ProcessFrameDelimiter(format::ApiCallId call_id);
    bool ProcessFrameDelimiter(const FrameEndMarkerArgs& end_frame);

    bool IsFrameDelimiter(format::BlockType block_type, format::MarkerType marker_type) const;
    bool IsFrameDelimiter(format::ApiCallId call_id) const;

    void HandleBlockReadError(BlockIOError error_code, const char* error_message);

    bool ProcessExecuteBlocksFromFile(const ExecuteBlocksFromFileArgs& execute_blocks_info);
    void ProcessStateBeginMarker(const StateBeginMarkerArgs& state_begin);
    void ProcessStateEndMarker(const StateEndMarkerArgs& state_end);
    void ProcessStateEndMarkerFrameState(const StateEndMarkerArgs& state_end);
    void ProcessAnnotation(const AnnotationArgs& annotation);

  protected:
    bool AsyncProcessingEnabled() const { return async_processor_.get() != nullptr; }

    // Read from active file
    bool ReadBytes(void* buffer, size_t buffer_size);

    // Reads block header, from input stream.
    bool ReadBlockBuffer(BlockParser& parser, BlockBuffer& buffer);

    void UpdateEndFrameState();

    void PrintBlockInfo() const;

    static bool ContinueProcessing(ProcessBlockState state) { return static_cast<int32_t>(state) >= 0; }
    static bool IsFrameBoundary(ProcessBlockState state) { return state == ProcessBlockState::kFrameBoundary; }

    ProcessBlockState HandleBlockEof(const char* operation, bool report_frame_and_block);

    // Async processing needs to be to query this frame wise.
    friend class AsyncProcessor;
    friend class file_processor::SynchronousProcessPolicy;
    FrameNumber  GetProcessFrameNumber() const noexcept { return proc_->frame_number; }
    BlockIOError GetProcessErrorState() const noexcept { return proc_->error_state; }

  protected:
    // When non-zero, stop after this many blocks and never check decoder completion.
    uint64_t       block_limit_{ 0 };
    DispatchConfig config_;

    // All process-side (I/O and parse thread) state lives here.
    // In async mode, ownership transfers to AsyncProcessor at InitializeFrameProcessing time;
    // proc_ becomes null after the transfer -- any residual dispatch-thread access will null-deref.
    std::unique_ptr<BlockProcessor> proc_;

    // Dispatch-side frame/block/error tracking -- main-thread exclusive.
    //
    // Members prefixed 'dispatch_' refer to state during dispatch operations (DispatchVisitor, Replay*).
    // For API compatibility, state queries return the dispatch_<state> values.
    //
    // Frame numbers are zero-based (see kFirstFrame) and name the frame currently being dispatched,
    // or the frame that will become current on the next dispatch call.
    //
    // dispatch_* and proc_->* are kept in separate cachelines for async cache-line isolation.
    alignas(util::kConstructiveAlign) uint64_t dispatch_frame_number_{ kFirstFrame };
    BlockIOError      dispatch_error_state_{ kErrorNone };
    uint64_t          dispatch_block_index_{ 0 };
    ProcessBlockState dispatch_terminal_state_{ ProcessBlockState::kContinue };

    // Owns the current async batch; only accessed by the main thread on operator++
    BlockIterator async_block_iterator_;

    BlockIterator ReplayOneFrame(DispatchVisitor& dispatch_visitor, BlockIterator begin, BlockIterator end);
    void          HandleReplayResult(const ProcessBlocksResult& result);

    bool         IsFileValid() const;
    BlockIOError CheckFileStatus() const
    {
        if (proc_->file_stack.empty())
        {
            return kErrorInvalidFileDescriptor;
        }
        const auto& active_file = proc_->file_stack.back().active_file;
        // If not EOF, determine reason for invalid state.
        if (!active_file->IsOpen())
        {
            return kErrorInvalidFileDescriptor;
        }
        else if (active_file->IsError())
        {
            return kErrorReadingFile;
        }

        return kErrorNone;
    }

    bool AtEof() const
    {
        if (proc_->file_stack.empty())
        {
            return true;
        }
        return proc_->file_stack.back().active_file->IsEof();
    }

    // Control the update, continue, and dispatch functionality from a policy
    // appropriate to the callers requirements.
    template <typename Policy>
    ProcessBlockState ProcessBlocks(Policy& policy);

    void SetDecoderFrameNumber(uint64_t frame_number);

    BlockParser& GetBlockParser()
    {
        GFXRECON_ASSERT(proc_->block_parser.get() != nullptr);
        return *proc_->block_parser;
    }

  private:
    bool                ProcessFileHeader();
    bool                ProcessNextFrameAsync();
    bool                ProcessNextFrameSync();
    ProcessBlocksResult MakeResult(ProcessBlockState state) const;

    bool SeekActiveFile(const FileInputStreamPtr& file, int64_t offset, util::platform::FileSeekOrigin origin);

    bool SeekActiveFile(int64_t offset, util::platform::FileSeekOrigin origin);

    bool SetActiveFile(const std::string& filename, bool execute_till_eof);

    bool SetActiveFile(const std::string&             filename,
                       int64_t                        offset,
                       util::platform::FileSeekOrigin origin,
                       bool                           execute_till_eof);

    void DecrementRemainingCommands();

  private:
    bool     frame_processing_initialized_{ false };
    uint64_t dispatch_bytes_read_{ 0 };
    bool     dispatch_capture_uses_frame_markers_{ false };
    bool     dispatch_file_supports_frame_markers_{ false };
    bool     dispatch_skipping_finished_{ true };
    bool     loading_trimmed_capture_state_{ false };

    // Stored at FileProcessor level so they survive a BlockProcessor re-creation in Initialize().
    // Transferred to BlockProcessor in InitializeFrameProcessing().
    std::unordered_set<uint64_t> pending_blocks_to_skip_;

    // Cached copies of capture-file metadata set during Initialize() from proc_.
    // Remain valid after proc_ transfers to AsyncProcessor.
    format::FileHeader                  file_header_{};
    std::vector<format::FileOptionPair> file_options_;

    // Replay-time decompressor (dispatch/main-thread exclusive).
    // Cloned from proc_->compressor_ in InitializeFrameProcessing() before async transfer.
    std::unique_ptr<util::Compressor> replay_compressor_;

    // Working store for replay-time decompression (dispatch/main-thread exclusive).
    constexpr static size_t kWorkingStoreInitialSize = 4096;
    util::HeapBuffer        working_uncompressed_store_;

    BlockProcessor::ActiveFileContext& GetCurrentFile()
    {
        GFXRECON_ASSERT(proc_->file_stack.size());
        return proc_->file_stack.back();
    }

    std::unique_ptr<AsyncProcessor> async_processor_{};
};

extern template file_processor::ProcessBlockState
FileProcessor::ProcessBlocks<file_processor::PreloadProcessPolicy>(file_processor::PreloadProcessPolicy& policy);
extern template file_processor::ProcessBlockState
FileProcessor::ProcessBlocks<file_processor::AsyncProcessPolicy>(file_processor::AsyncProcessPolicy& policy);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_FILE_PROCESSOR_H
