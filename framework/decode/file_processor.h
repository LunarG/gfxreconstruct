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

//#define ASYNC_PROCESSING_INSTRUMENTATION

#include "format/api_call_id.h"
#include "format/format.h"
#include "decode/annotation_handler.h"
#include "decode/api_decoder.h"
#include "decode/api_payload.h"
#include "decode/block_parser.h"
#include "decode/file_processor_types.h"
#include "util/clock_cache.h"
#include "util/compressor.h"
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
#include <utility>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(file_processor)
class DispatchVisitor;
class ProcessVisitor;
class PreloadProcessPolicy;
GFXRECON_END_NAMESPACE(file_processor)

class FileProcessor
{
  public:
    enum BlockProcessReturn : int32_t
    {
        kSuccess = 0,
        kFailure = 1,
        kBreak   = 2,
    };

    using BlockIterator   = file_processor::BlockIterator;
    using DispatchVisitor = file_processor::DispatchVisitor;
    using FrameNumber     = file_processor::FrameNumber;
    using FrameCount      = file_processor::FrameCount;
    using ProcessVisitor  = file_processor::ProcessVisitor;

    constexpr static FrameNumber kFirstFrame     = 0;
    constexpr static FrameNumber kMaxFrameNumber = std::numeric_limits<FrameNumber>::max();
    constexpr static FrameCount  kMaxFrameCount  = std::numeric_limits<FrameCount>::max();

    // Range of frame numbers with half open [begin(), end()) semantics.
    struct FrameRange
    {
        FrameNumber begin_frame{};
        FrameNumber end_frame{};

        FrameNumber begin() const noexcept { return begin_frame; }
        FrameNumber end() const noexcept { return end_frame; }
        bool        contains(FrameNumber frame) { return (frame >= begin_frame) && (frame < end_frame); }
        bool        empty() const noexcept { return begin_frame == end_frame; }

        template <typename T, typename U>
        static FrameRange MakeFromOneBased(T inclusive_begin1, U exclusive_end1)
        {
            GFXRECON_ASSERT((inclusive_begin1 > 0) && (exclusive_end1 > 0));
            return FrameRange(GFXRECON_NARROWING_CAST(FrameNumber, (inclusive_begin1 - 1)),
                              GFXRECON_NARROWING_CAST(FrameNumber, (exclusive_end1 - 1)));
        }

        FrameRange(FrameNumber inclusive_begin, FrameNumber exclusive_end) :
            begin_frame(inclusive_begin), end_frame(exclusive_end)
        {
            GFXRECON_ASSERT(begin_frame <= end_frame);
        }
        FrameRange() = default;
    };

    // ProcessBlocks specific status.
    using ProcessBlockState   = file_processor::ProcessBlockState;
    using ProcessBlocksResult = file_processor::ProcessBlocksResult;

    FileProcessor();

    FileProcessor(uint64_t block_limit);

    virtual ~FileProcessor();

    void WaitDecodersIdle();

    void SetAnnotationProcessor(AnnotationHandler* handler) { annotation_handler_ = handler; }

    void StartAsyncProcessing();
    void SetPreloadFrameRange(FrameRange frame_range);
    void SetQuitBeforeFrame(FrameNumber frame_number);

    void AddDecoder(ApiDecoder* decoder) { decoders_.push_back(decoder); }

    void RemoveDecoder(ApiDecoder* decoder)
    {
        decoders_.erase(std::remove(decoders_.begin(), decoders_.end(), decoder), decoders_.end());
    }

    bool Initialize(const std::string& filename);

    // Returns true if there are more frames to process, false if all frames have been processed or an error has
    // occurred.  Use GetErrorState() to determine error condition.
    virtual bool ProcessNextFrame();

    // Returns false if processing failed.  Use GetErrorState() to determine error condition for failure case.
    bool ProcessAllFrames();

    template <typename CheckPolicy>
    bool ContinueBlockProcessing(uint64_t block_index); // Check process_block_index_ against block_limit_

    const std::vector<format::FileOptionPair>& GetFileOptions() const { return file_options_; }

    // Application facing interface returns the *dispatched* frame and block index, to preserve expected semantics.
    uint64_t GetCurrentFrameNumber() const noexcept { return dispatch_frame_number_; }
    uint64_t GetCurrentBlockIndex() const noexcept { return dispatch_block_index_; }

    // These have "process_" side semantic semantics process_
    bool         GetLoadingTrimmedState() const { return loading_trimmed_capture_state_; }
    uint64_t GetNumBytesRead() const { return bytes_read_; }
    BlockIOError GetErrorState() const { return dispatch_error_state_; }

    bool EntireFileWasProcessed() const
    {
        if (file_stack_.empty())
        {
            return true;
        }

        return file_stack_.front().active_file->IsEof();
    }

    bool                      UsesFrameMarkers() const { return capture_uses_frame_markers_; }
    bool                      FileSupportsFrameMarkers() const { return file_supports_frame_markers_; }
    const format::FileHeader& GetFileHeader() const { return file_header_; }

    void SetPrintBlockInfoFlag(bool enable_print_block_info, int64_t block_index_from, int64_t block_index_to)
    {
        enable_print_block_info_ = enable_print_block_info;
        block_index_from_        = block_index_from;
        block_index_to_          = block_index_to;
    }

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

    void NotifyIndexDequeued(FrameCount index);

  protected:
    using BlockProcessor = std::function<bool()>;

    // Read from active file
    bool ReadBytes(void* buffer, size_t buffer_size);

    // Reads block header, from input stream.
    bool ReadBlockBuffer(BlockParser& parser, BlockBuffer& buffer);

    void UpdateEndFrameState();

    void PrintBlockInfo() const;

    static bool ContinueProcessing(ProcessBlockState state) { return static_cast<int32_t>(state) >= 0; }
    static bool IsFrameBoundary(ProcessBlockState state) { return state == ProcessBlockState::kFrameBoundary; }

    ProcessBlockState HandleBlockEof(const char* operation, bool report_frame_and_block);

  protected:
    std::vector<ApiDecoder*> decoders_;
    AnnotationHandler*       annotation_handler_{ nullptr };
    uint64_t                 bytes_read_{ 0 };

    // Frame, block, and error tracking state:
    // Members prefixed 'process_' refer to state during ProcessBlocks (reading, parsing, enqueueing).
    // Members prefixed 'dispatch_' refer to state during dispatch operations (DispatchVisitor, Replay*).
    //
    // For API compatibility, state queries return the dispatch_<state> values.
    //
    // In immediate mode (not preload, not asynchronous), process_<state> is propagated as needed
    // to dispatch_<state> in order to support application-facing state access.
    //
    // Frame numbers are zero-based (see kFirstFrame) and name the frame currently being processed or
    // dispatched, or the frame that will become current on the next call into the process or dispatch hierarchies.
    //
    // Frame numbers advance only on frame boundaries, and not on terminating exit conditions (error or EOF).
    uint64_t process_frame_number_{ kFirstFrame };
    uint64_t dispatch_frame_number_{ kFirstFrame };

    // The error state observed during block processing and dispatch.
    BlockIOError process_error_state_{ kErrorInvalidFileDescriptor };
    BlockIOError dispatch_error_state_{ kErrorNone };

    // The index of the block currently being processed or dispatched, or the next block that will be.
    uint64_t process_block_index_{ 0 };
    uint64_t dispatch_block_index_{ 0 };

    using AsyncQueue           = file_processor::AsyncProcessedBlockQueue;
    using AsyncBatchIterator   = file_processor::AsyncBatchIterator;
    using AsyncStats           = file_processor::AsyncInstrumentation;
    using AsyncBatchFramesRing = file_processor::AsyncBatchFramesRing;

    // Asynchronous file read and parsing support
    void AsyncWaitForFrameCount(FrameCount wait_target);
    void AsyncThrottleQueue(FrameCount enqueued_frames, const AsyncBatchFramesRing& batch_frame_index);
    void AsyncAdjustDecompressionPolicy(FrameCount pending_frames);
    void ProcessBlocksAsync();

    // Async Thread Control group: (constructive alignment)
    //  This is state primarly accessed by the async thread, and only occasionally read by the main thread, so we want
    //  to keep it together and away from the main thread accessed state to avoid cache thrashing on the async thread
    //  when the main thread is reading state.
    //
    // Note:
    // preload frame range is only used for preload, but we need it to control async processing w.r.t. the preload
    // frame range.  // During preload, different rules apply. Highwater becomes "all frames in preload range" and
    // decompression policy is kAlways.
    alignas(util::kConstructiveAlign) uint64_t async_quit_before_frame_{ kMaxFrameNumber };
    FrameRange        async_preload_frame_range_;
    std::atomic<bool> async_keep_alive_; // Thread teardown control
    AsyncStats        async_stats_;

    // Shared Control group: (constructive alignment)
    alignas(util::kConstructiveAlign) std::mutex async_throttle_mutex_;
    std::atomic<FrameCount> async_wait_target_{ kMaxFrameCount };
    std::condition_variable async_throttle_cv_;

    // Cache line isolated
    //  This state is frequently accessed by both thread, but not at exactly the same time or frequency, so we need
    //  these to be on separate cache lines to avoid thrashing when both threads are accessing them, and the need to be
    //  separated both from the Control groun and each other to avoid thrashing between them.
    alignas(util::kDestructiveAlign) AsyncQueue async_queue_;
    alignas(util::kDestructiveAlign) std::atomic<FrameCount> async_dequeued_frames_;

    // Main thread only group:
    //  This state is only accessed by the main thread.
    alignas(util::kDestructiveAlign) std::thread async_thread_;
    bool async_processing_{ false };

    // Owns the current async batch; only accessed by the main thread, references the async_queue_
    // on operator++
    AsyncBatchIterator async_batch_iterator_;
    BlockIterator      async_block_iterator_;

    // Async processing throttle boundaries.  Values are in terms of frames async_thread is ahead of dispatching thread
    // NOTE: These values are intial guesses only. Tuning could/should be done.
    constexpr static FrameCount kAsyncNever     = 8;  // Offload decompression to dispatch when below this limit
    constexpr static FrameCount kAsyncOptimized = 16; // Do decompression of smaller blocks on async_thread_
    constexpr static FrameCount kAsyncAlways    = 32; // Do all decompression on async_thread_

    // Note: the offset are intentional s.t. we don't beat agains the hysteresis boundaries above
    constexpr static FrameCount kAsyncResume = kAsyncOptimized + 2; // Unblock condition predicate criteria
    constexpr static FrameCount kAsyncWait = kAsyncAlways + 2; // Go into condition variable wait when above this limit

    static const ProcessBlocksResult& GetReplayResult(DispatchVisitor& dispatch_visitor);
    BlockIterator ReplayOneFrame(DispatchVisitor& dispatch_visitor, BlockIterator begin, BlockIterator end);
    void          HandleReplayResult(const ProcessBlocksResult&                             result,
                                     const file_processor::BlockIterator&                   iterator,
                                     const std::function<void(const ProcessBlocksResult&)>& publish);

    bool         IsFileValid() const;
    BlockIOError CheckFileStatus() const
    {
        if (file_stack_.empty())
        {
            return kErrorInvalidFileDescriptor;
        }
        const auto& active_file = file_stack_.back().active_file;
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
        if (file_stack_.empty())
        {
            return true;
        }
        return file_stack_.back().active_file->IsEof();
    }

    // Control the update, continue, and dispatch functionality from a policy
    // appropriate to the callers requirements.
    template <typename Policy>
    ProcessBlockState ProcessBlocks(Policy& policy);

    void SetDecoderFrameNumber(uint64_t frame_number);

    BlockParser& GetBlockParser()
    {
        GFXRECON_ASSERT(block_parser_.get() != nullptr);
        return *block_parser_;
    }

    ProcessBlockState DispatchBlock(uint64_t block_index, DispatchVisitor& dispatch_visitor, ParsedBlock& block);

  private:
    bool ProcessFileHeader();
    bool ProcessNextFrameAsync();
    bool ProcessNextFrameSync();

    // NOTE: These two can't be const as derived class updates state.
    virtual bool SkipBlockProcessing() { return false; } // No block skipping in base class

    bool SeekActiveFile(const FileInputStreamPtr& file, int64_t offset, util::platform::FileSeekOrigin origin);

    bool SeekActiveFile(int64_t offset, util::platform::FileSeekOrigin origin);

    bool SetActiveFile(const std::string& filename, bool execute_till_eof);

    bool SetActiveFile(const std::string&             filename,
                       int64_t                        offset,
                       util::platform::FileSeekOrigin origin,
                       bool                           execute_till_eof);

    void DecrementRemainingCommands();

  private:
    std::vector<format::FileOptionPair> file_options_;
    format::EnabledOptions              enabled_options_;
    std::vector<uint8_t>                uncompressed_buffer_;
    uint64_t                            block_limit_{ 0 }; // No block limit by default
    bool                                pending_capture_uses_frame_markers_{ false };
    bool                                capture_uses_frame_markers_{ false };
    bool                                file_supports_frame_markers_{ false };
    uint64_t                            first_frame_;
    bool                                enable_print_block_info_{ false };
    int64_t                             block_index_from_{ 0 };
    int64_t                             block_index_to_{ 0 };
    bool                                loading_trimmed_capture_state_{ false };

    std::string        absolute_path_;
    format::FileHeader file_header_;

    // Working store for replay time decompression
    // Working store for replay time decompression
    constexpr static size_t kWorkingStoreInitialSize = 4096;
    util::HeapBuffer        working_uncompressed_store_;

  protected:
    std::unique_ptr<util::Compressor> compressor_;
    std::unique_ptr<BlockParser>      block_parser_;

    struct ActiveFileContext
    {
        ActiveFileContext(FileInputStreamPtr&& active_file_, bool execute_til_eof_ = false) :
            active_file(std::move(active_file_)), execute_till_eof(execute_til_eof_){};

        FileInputStreamPtr active_file;
        uint32_t           remaining_commands{ 0 };
        bool               execute_till_eof{ false };
    };

    std::deque<ActiveFileContext> file_stack_;

  private:
    ActiveFileContext& GetCurrentFile()
    {
        GFXRECON_ASSERT(file_stack_.size());
        return file_stack_.back();
    }

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
};

extern template file_processor::ProcessBlockState
FileProcessor::ProcessBlocks<file_processor::PreloadProcessPolicy>(file_processor::PreloadProcessPolicy& policy);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_FILE_PROCESSOR_H
