/*
** Copyright (c) 2018-2020,2022 Valve Corporation
** Copyright (c) 2018-2020,2022 LunarG, Inc.
** Copyright (c) 2022-2025 Advanced Micro Devices, Inc. All rights reserved.
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

#include "decode/block_buffer.h"
#include "decode/file_processor.h"
#include "decode/file_processor_visitors.h" // Must be after file_processor.h for FileProcessor callbacks
#include "format/format_util.h"
#include "util/logging.h"

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

FileProcessor::FileProcessor() :
    async_keep_alive_(false), async_dequeued_frames_(0), async_preload_frame_range_(), async_batch_iterator_(),
    async_block_iterator_(), compressor_(nullptr), first_frame_(kFirstFrame + 1), file_header_({ 0, 0, 0, 0 }),
    working_uncompressed_store_(kWorkingStoreInitialSize)
{}

FileProcessor::FileProcessor(uint64_t block_limit) : FileProcessor()
{
    block_limit_ = block_limit;
}

FileProcessor::~FileProcessor()
{
    DecodeAllocator::DestroyInstance();

    if (async_thread_.joinable())
    {
        async_keep_alive_.store(false, std::memory_order_release);
        async_throttle_cv_.notify_all();
        async_thread_.join();
    }
}

void FileProcessor::WaitDecodersIdle()
{
    for (auto decoder : decoders_)
    {
        decoder->WaitIdle();
    }
}

void FileProcessor::StartAsyncProcessing()
{
    GFXRECON_ASSERT(process_frame_number_ == kFirstFrame);
    async_processing_ = true;
    block_parser_->SetOperationMode(BlockParser::OperationMode::kEnqueued);
    async_keep_alive_.store(true, std::memory_order_release);
    async_thread_ = std::thread([this]() { this->ProcessBlocksAsync(); });
    // Blocks until async_thread_ flushes its first batch.
    async_batch_iterator_ = AsyncBatchIterator(async_queue_);
    async_block_iterator_ = BlockIterator(&async_batch_iterator_);
}

void FileProcessor::SetPreloadFrameRange(FrameRange frame_range)
{
    GFXRECON_LOG_DEBUG(
        "Preload frame range set to [%" PRIu64 ", %" PRIu64 ")", frame_range.begin_frame, frame_range.end_frame);
    async_preload_frame_range_ = frame_range;
};

void FileProcessor::SetQuitBeforeFrame(FrameNumber frame_number)
{
    async_quit_before_frame_ = frame_number;
}

bool FileProcessor::Initialize(const std::string& filename)
{
    bool success = SetActiveFile(filename, true);

    if (success)
    {
        success = success && ProcessFileHeader();
    }
    else
    {
        dispatch_error_state_ = kErrorOpeningFile;
    }

    if (success)
    {
        // Find absolute path of capture file
        absolute_path_ = util::filepath::GetBasedir(filename);

        // Initialize block parser, with the compressor created during file header processing.
        auto err_handler = BlockParser::ErrorHandler{ [this](BlockIOError err, const char* message) {
            HandleBlockReadError(err, message);
        } };
        block_parser_    = std::make_unique<BlockParser>(err_handler, compressor_.get());
        if (block_parser_.get() != nullptr)
        {
            // For immediate dispatching (the default mode of operation) no need to defer decompression
            block_parser_->SetDecompressionPolicy(BlockParser::DecompressionPolicy::kAlways);
        }
        else
        {
            dispatch_error_state_ = kErrorOpeningFile;
            success      = false;
        }
    }

    return success;
}

bool FileProcessor::ProcessNextFrame()
{
    if (async_processing_)
    {
        return ProcessNextFrameAsync();
    }
    return ProcessNextFrameSync();
}

bool FileProcessor::ProcessNextFrameAsync()
{
    // Note that this call may block on empty queue, but the async
    // queue loader should alway close the queue on end processing or error
    // NOTE: If the dispatch vistor is reused from frame to frame, then is should be Reset().
    DispatchVisitor dispatch_visitor(*this, decoders_, annotation_handler_);
    async_block_iterator_ = ReplayOneFrame(dispatch_visitor, async_block_iterator_, BlockIterator());

    const ProcessBlocksResult& result = GetReplayResult(dispatch_visitor);
    HandleReplayResult(result, async_block_iterator_, [this](const ProcessBlocksResult& publish_result) {
        NotifyIndexDequeued(publish_result.index);
    });

    return ContinueProcessing(result.state);
}

bool FileProcessor::ProcessNextFrameSync()
{
    if (!IsFileValid())
    {
        dispatch_error_state_ = CheckFileStatus();
        return false;
    }

    // The dispatch function is correct only for non-enqueued, and requires decompression during ParsedBlock creation
    GFXRECON_ASSERT(block_parser_->GetOperationMode() == BlockParser::OperationMode::kImmediate);
    GFXRECON_ASSERT(block_parser_->GetDecompressionPolicy() == BlockParser::DecompressionPolicy::kAlways);

    DispatchVisitor  dispatch_visitor(*this, decoders_, annotation_handler_);
    file_processor::SynchronousProcessPolicy process_policy{ *this, dispatch_visitor };

    // This is immediate mode, process and dispatch frame numbers are matched.
    // This should be true for initialization and every frame when not replaying from preload.
    // But we don't call down this path after preloading and before replay is complete.
    GFXRECON_ASSERT(dispatch_frame_number_ == process_frame_number_);

    SetDecoderFrameNumber(dispatch_frame_number_);
    ProcessBlockState process_result = ProcessBlocks(process_policy);

    // ProcessBlocks can update process_frame_number_, so keep them in sync here
    dispatch_frame_number_ = process_frame_number_;

    // Pick up any errors from block processing, and make them application visiible.
    dispatch_error_state_ = process_error_state_;

    return ContinueProcessing(process_result);
}

bool FileProcessor::ProcessAllFrames()
{
    bool success = true;

    while (success)
    {
        if (success)
        {
            success = ProcessNextFrame();
        }
    }

    return (process_error_state_ == kErrorNone);
}

template <typename CheckPolicy>
bool FileProcessor::ContinueBlockProcessing(uint64_t block_index)
{
    bool early_exit = false;
    // If a block limit was specified, obey it.
    // If not (block_limit_ = 0),  then the consumer may determine early exit

    // Note:
    // The odd mix of runtime and Policy checks support the backwards compatible logic,
    // while still allowing policy control of ContinueChecks.
    //
    // The historical functionality is that if block_limit_ is set decoders are *never* checked, period.
    // With the sync/async split, this means that even in synchronous operation or during replay, when we enable
    // checking the decoders, we still don't if block_limit_ is set.
    if (block_limit_ > 0)
    {
        if constexpr (CheckPolicy::kCheckBlockLimit)
        {
            if (block_index > block_limit_)
            {
                early_exit = true;
            }
        }
    }
    else if constexpr (CheckPolicy::kCheckDecoders)
    {
        int completed_decoders = 0;

        for (auto& decoder : decoders_)
        {
            // Note: the "decoder->IsComplete" calls may have side effects, so we cannot simply
            // bail with early_exit = false on the first incomplete decoder.
            if (decoder->IsComplete(block_index) == true)
            {
                completed_decoders++;
            }
        }

        if (completed_decoders == decoders_.size())
        {
            early_exit = true;
        }
    }

    return !early_exit;
}

bool FileProcessor::ProcessFileHeader()
{
    bool success = false;
    file_header_ = format::FileHeader();

    assert(file_stack_.front().active_file);

    if (ReadBytes(&file_header_, sizeof(file_header_)))
    {
        success = format::ValidateFileHeader(file_header_);

        if (success)
        {
            auto file_version = GFXRECON_MAKE_FILE_VERSION(file_header_.major_version, file_header_.minor_version);
            if (file_version >= GFXRECON_EXPLICIT_FRAME_MARKER_FILE_VERSION)
            {
                capture_uses_frame_markers_ = true;
            }

            file_options_.resize(file_header_.num_options);

            size_t option_data_size = file_header_.num_options * sizeof(format::FileOptionPair);

            success = ReadBytes(file_options_.data(), option_data_size);

            if (success)
            {
                for (const auto& option : file_options_)
                {
                    switch (option.key)
                    {
                        case format::FileOption::kCompressionType:
                            enabled_options_.compression_type = static_cast<format::CompressionType>(option.value);
                            break;
                        default:
                            GFXRECON_LOG_WARNING("Ignoring unrecognized file header option %u", option.key);
                            break;
                    }
                }

                compressor_.reset(format::CreateCompressor(enabled_options_.compression_type));

                if ((compressor_ == nullptr) && (enabled_options_.compression_type != format::CompressionType::kNone))
                {
                    GFXRECON_LOG_ERROR("Failed to initialize file compression module (type = %u); replay of "
                                       "compressed data will not be possible",
                                       enabled_options_.compression_type);
                    success      = false;
                    dispatch_error_state_ = kErrorUnsupportedCompressionType;
                }
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("File header contains invalid four character code");
            dispatch_error_state_ = kErrorInvalidFourCC;
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to read file header");
        dispatch_error_state_ = kErrorReadingFileHeader;
    }

    return success;
}

void FileProcessor::DecrementRemainingCommands()
{
    if (file_stack_.empty())
    {
        return;
    }

    ActiveFileContext& current_file = GetCurrentFile();

    if (!current_file.execute_till_eof)
    {
        --current_file.remaining_commands;
        if (current_file.remaining_commands == 0)
        {
            file_stack_.pop_back();
        }
    }
}

template <typename ProcessPolicy>
FileProcessor::ProcessBlockState FileProcessor::ProcessBlocks(ProcessPolicy& policy)
{
    BlockBuffer       block_buffer;
    ProcessBlockState process_state = ProcessBlockState::kRunning;
    BlockParser&      block_parser  = *block_parser_.get();
    ProcessVisitor    process_visitor(*this);

    while (process_state == ProcessBlockState::kRunning)
    {
        PrintBlockInfo();

        if constexpr (ProcessPolicy::kUpdateDispatchState)
        {
            dispatch_block_index_ = process_block_index_;
        }
        bool success = policy.ContinueBlockProcessing(process_block_index_);

        if (success)
        {
            success = ReadBlockBuffer(block_parser, block_buffer);

            if (success)
            {
                if (SkipBlockProcessing())
                {
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_buffer.Header().size);
                }
                else
                {
                    block_parser.SetBlockIndex(process_block_index_);
                    block_parser.SetFrameNumber(process_frame_number_);
                    // NOTE: upon successful parsing, the block_buffer block data has been moved to the
                    // parsed_block, though the block header is still valid.
                    ParsedBlock& parsed_block = block_parser.ParseBlock(block_buffer);

                    // NOTE: Visitable is either Ready or DeferredDecompression,
                    //       Invalid, Unknown, and Skip are not Visitable
                    if (parsed_block.IsVisitable())
                    {
                        if (success)
                        {
                            std::visit(process_visitor, parsed_block.GetArgs());
                            success = process_visitor.IsSuccess();
                            if (success)
                            {
                                process_state = policy.Dispatch(process_block_index_, parsed_block);
                                if ((ProcessBlockState::kRunning == process_state) &&
                                    process_visitor.IsFrameDelimiter())
                                {
                                    process_state = ProcessBlockState::kFrameBoundary;
                                    parsed_block.SetFrameBoundaryFlag(true);
                                }
                            }
                            else
                            {
                                process_state = ProcessBlockState::kError;
                            }
                        }
                        else
                        {
                            // Decompression failed. Decompress logs error.
                            process_state = ProcessBlockState::kError;
                        }
                    }
                    else if (!parsed_block.IsValid())
                    {
                        // Invalid block. Error already logged in ParseBlock.
                        process_state = ProcessBlockState::kError;
                    }
                    // NOTE: Warnings for unknown/invalid blocks are handled in the BlockParser
                }
                ++process_block_index_;
                DecrementRemainingCommands();
            }
            else // ReadBlockBuffer failed
            {
                process_state = HandleBlockEof("read", true);
            }
        }
        else // ContinueBlockProcessing returned false
        {
            process_state = ProcessBlockState::kEndProcessing;
        }
    }

    // Update the frame number etc.
    if (process_state == ProcessBlockState::kFrameBoundary)
    {
        UpdateEndFrameState();
    }

    return process_state;
}

// While ReadBlockBuffer both reads the block header and the block body, checks for
// the correct sizing of the block payload are done by the caller
bool FileProcessor::ReadBlockBuffer(BlockParser& parser, BlockBuffer& block_buffer)
{
    bool         success = true;
    BlockIOError status  = parser.ReadBlockBuffer(GetCurrentFile().active_file, block_buffer);
    if (status == kErrorNone)
    {
        bytes_read_ += block_buffer.Size();
    }
    else
    {
        // Caller handles end of file on block boundaries
        if (status != kEndOfFile)
        {
            HandleBlockReadError(status, "Failed to read next block");
        }
        success = false;
    }
    return success;
}

bool FileProcessor::ReadBytes(void* buffer, size_t buffer_size)
{
    // File entry is non-const to allow read bytes to be non-const (i.e. potentially reflect a stateful operation)
    // without forcing use of mutability
    const auto& active_file = file_stack_.back().active_file;
    GFXRECON_ASSERT(active_file);

    if (active_file->ReadBytes(buffer, buffer_size))
    {
        bytes_read_ += buffer_size;
        return true;
    }
    return false;
}

template file_processor::ProcessBlockState
FileProcessor::ProcessBlocks<file_processor::PreloadProcessPolicy>(file_processor::PreloadProcessPolicy& policy);

void FileProcessor::AsyncWaitForFrameCount(FrameCount wait_target)
{
    std::unique_lock<std::mutex> lock(async_throttle_mutex_);
    async_throttle_cv_.wait(lock, [this, wait_target] {
        // Start again when consumer has caught up to target
        return !async_keep_alive_ || async_dequeued_frames_.load(std::memory_order_acquire) >= wait_target;
    });
}

void FileProcessor::AsyncThrottleQueue(FrameCount enqueued_frames)
{

    // Highwater check
    // Since async_dequeued_frames_ is set from the ProcessBlocksResult::index it must be <= enqueued_frames
    const FrameCount pending_frames = enqueued_frames - async_dequeued_frames_.load(std::memory_order_acquire);
    async_stats_.AddFramePending(pending_frames);

    // Make sure we don't starve the consumer on startup.
    if (pending_frames >= async_max_pending_)
    {
        block_parser_->GetBlockAllocator().FlushBatch();

        // Increase max pending to wait limit.
        async_max_pending_ <<= kAsyncMaxPendingShift;
        async_max_pending_ = std::min(async_max_pending_, kAsyncWait);

        // If we're far enough ahead, wait for the consumer.
        if (pending_frames >= kAsyncWait)
        {
            async_stats_.AddWait();
            static_assert(kAsyncWait > kAsyncResume);
            // Must flush before waiting
            AsyncWaitForFrameCount(enqueued_frames - kAsyncResume);
        }
    }
    else
    {
        const auto policy = block_parser_->GetDecompressionPolicy();
        switch (policy)
        {
            case BlockParser::DecompressionPolicy::kNever:
                if (pending_frames > kAsyncOptimized)
                {
                    async_stats_.AddPolicyChange(policy, BlockParser::DecompressionPolicy::kQueueOptimized);
                    block_parser_->SetDecompressionPolicy(BlockParser::DecompressionPolicy::kQueueOptimized);
                }
                break;
            case BlockParser::DecompressionPolicy::kQueueOptimized:
                if (pending_frames >= kAsyncAlways)
                {
                    async_stats_.AddPolicyChange(policy, BlockParser::DecompressionPolicy::kAlways);
                    block_parser_->SetDecompressionPolicy(BlockParser::DecompressionPolicy::kAlways);
                }
                else if (pending_frames <= kAsyncNever)
                {
                    async_stats_.AddPolicyChange(policy, BlockParser::DecompressionPolicy::kNever);
                    block_parser_->SetDecompressionPolicy(BlockParser::DecompressionPolicy::kNever);
                }
                break;
            case BlockParser::DecompressionPolicy::kAlways:
                if (pending_frames <= kAsyncOptimized)
                {
                    async_stats_.AddPolicyChange(policy, BlockParser::DecompressionPolicy::kQueueOptimized);
                    block_parser_->SetDecompressionPolicy(BlockParser::DecompressionPolicy::kQueueOptimized);
                }
                break;
        }

        async_stats_.IncrementPolicyCount(*block_parser_);
    }
}

// This is the block loading and processing child thread.
void FileProcessor::ProcessBlocksAsync()
{

    block_parser_->GetBlockAllocator().SetBatchSinkProc([this](BlockBatch::BatchPtr&& batch) {
        async_stats_.AddBatch(batch);
        async_queue_.emplace(std::move(batch));
    });
    // Start with async_thread_ doing the minimal, and adjust if it gets too far ahead
    block_parser_->SetDecompressionPolicy(BlockParser::DecompressionPolicy::kNever);
    file_processor::AsynchronousProcessPolicy process_policy{ *this, async_stats_ };

    // As frame numbers can be non-contiguous, use a frame enqueing index for throttling math
    // Allow the *index* to be one based, counting the number of enqueued frames
    FrameCount enqueued_frames = 0;

    bool continue_processing = true;
    do
    {
        const bool preloading = async_preload_frame_range_.contains(process_frame_number_);
        if (preloading)
        {
            if (process_frame_number_ == async_preload_frame_range_.begin_frame)
            {
                // To make async preloading simpler, Async Preloading starts and end on frame bounded batches.
                // In the stuttering case both the false and true frame boundaries will flush.
                block_parser_->GetBlockAllocator().FlushBatch();

                // Required for performance and frame looping reasons
                block_parser_->SetDecompressionPolicy(BlockParser::DecompressionPolicy::kAlways);
            }
        }
        ProcessBlockState process_state = ProcessBlocks(process_policy);
        // Push all processed blocks onto the queue, and add the end of frame/end of process result to the queue
        ++enqueued_frames;
        block_parser_->EmplaceResultsBlock(enqueued_frames, process_frame_number_, process_error_state_, process_state);

        // We don't want any more than Wait frames on the queue
        FrameCount wait_target = 0;
        if (preloading)
        {
            if (!async_preload_frame_range_.contains(process_frame_number_))
            {
                block_parser_->GetBlockAllocator().FlushBatch();
                async_stats_.AddPendingAtWait(enqueued_frames, async_dequeued_frames_);
                // Once we've loaded all the frames in the preload, we wait until they've all replayed
                // from the preload queue
                AsyncWaitForFrameCount(enqueued_frames);

                // After preload the queue is empty, so we allow for catchup by not decompressing
                block_parser_->SetDecompressionPolicy(BlockParser::DecompressionPolicy::kNever);
            }
        }
        else
        {
            AsyncThrottleQueue(enqueued_frames);
        }

        continue_processing = ContinueProcessing(process_state) && (process_frame_number_ < async_quit_before_frame_);

    } while (continue_processing && async_keep_alive_.load(std::memory_order_acquire));

    // Must flush before closing.
    block_parser_->GetBlockAllocator().FlushBatch();

    GFXRECON_LOG_INFO("Async processing ending at frame %" PRIu64, process_frame_number_);
    async_queue_.close();
}

const FileProcessor::ProcessBlocksResult& FileProcessor::GetReplayResult(DispatchVisitor& dispatch_visitor)
{
    return dispatch_visitor.GetReplayResult();
}

void FileProcessor::HandleReplayResult(const ProcessBlocksResult&                             result,
                                       const file_processor::BlockIterator&                   iterator,
                                       const std::function<void(const ProcessBlocksResult&)>& publish)
{
    dispatch_error_state_  = result.error;
    dispatch_frame_number_ = result.frame_number;

    if (result.state == ProcessBlockState::kRunning)
    {
        if (iterator == file_processor::BlockIterator())
        {
            GFXRECON_LOG_FATAL(
                "Should never encounter end of queue without a terminating ProcessBlocksResult ahead of it.");
            dispatch_error_state_ = BlockIOError::kErrorReadingBlockData;
        }
    }

    if (publish)
    {
        publish(result);
    }
}

file_processor::BlockIterator
FileProcessor::ReplayOneFrame(DispatchVisitor& dispatch_visitor, BlockIterator begin, BlockIterator end)
{
    GFXRECON_ASSERT(begin != end);
    BlockParser& block_parser = GetBlockParser();

    ProcessBlockState             state = ProcessBlockState::kRunning;
    file_processor::BlockIterator it    = begin;

    SetDecoderFrameNumber(dispatch_frame_number_);
    while ((it != end) && (ProcessBlockState::kRunning == state))
    {
        ParsedBlock& block = *it;
        // We assume that only known, visitable blocks were preloaded
        GFXRECON_ASSERT(block.IsVisitable());

        if (block.NeedsDecompression())
        {
            // Note: This path is destructive to replayed blocks.
            //
            // Decompression during replay sets the args data pointer to the working_uncompressed_store_ data.
            // The block is ready to dispatch; however, it will become invalid as soon as the next block is
            // decompressed. This is because the working store will be overwritten with the most recently
            // decompressed data, and since the working store automatically resizes as needed, the data
            // pointer may become stale.
            //
            // For performance reasons, we are neither updating the block state nor deleting the block until
            // *after* all preloaded blocks (or at least blocks in a given batch have been replayed. This
            // means that replayed blocks are effectively invalid, yet they are retained and still marked as valid.
            //
            // If in the future we need to support the reuse of preloaded blocks, we will need a way to:
            //  1: restore the args data pointer, or
            //  2: retain the decompressed data in the block batch (likely as a dynamic allocation in the HLA), or
            //  3: allocate the decompressed buffer storage at block creation time, but still defer decompression.
            if (!block.Decompress(block_parser, working_uncompressed_store_))
            {
                // As is the case with decompression failure during block parsing, decompression failure on replay
                // is fatal.
                //
                // Note: Error message generation is done by the block decompression code
                dispatch_visitor.SetReplayResult(
                    { 0, dispatch_frame_number_, kErrorReadingCompressedBlockData, ProcessBlockState::kError });
                break;
            }
        }

        // update the "dispatched" block index for the application facing interfaces and decoders
        dispatch_block_index_ = block.GetBlockIndex();
        if (ContinueBlockProcessing<file_processor::ContinueProcessingPolicy::DecoderOnly>(
                dispatch_block_index_)) // Requires the dispatch_block_index_ to be updated
        {
            dispatch_visitor.SetBlockIndex(dispatch_block_index_);
            state = std::visit(dispatch_visitor, block.GetArgs());
        }
        else
        {
            state = ProcessBlockState::kEndProcessing;
        }

        ++it;
    }
    return it;
}

void FileProcessor::NotifyIndexDequeued(FrameCount index)
{
    if (async_processing_)
    {
        async_dequeued_frames_.store(index, std::memory_order_release);
        async_throttle_cv_.notify_one();
    }
}

bool FileProcessor::IsFileValid() const
{
    if (!file_stack_.empty())
    {
        return file_stack_.back().active_file->IsReady();
    }
    else
    {
        return false;
    }
}

bool FileProcessor::SeekActiveFile(const FileInputStreamPtr&      active_file,
                                   int64_t                        offset,
                                   util::platform::FileSeekOrigin origin)
{
    GFXRECON_ASSERT(active_file);

    bool success = active_file->FileSeek(offset, origin);

    if (success && origin == util::platform::FileSeekCurrent)
    {
        // These technically count as bytes read/processed.
        bytes_read_ += offset;
    }

    return success;
}

bool FileProcessor::SeekActiveFile(int64_t offset, util::platform::FileSeekOrigin origin)
{
    return SeekActiveFile(file_stack_.back().active_file, offset, origin);
}

bool FileProcessor::SetActiveFile(const std::string& filename, bool execute_till_eof)
{

    // Look for the name stream in the cache
    auto cached_stream = stream_cache_.Lookup(filename);

    FileInputStreamPtr active_file;
    if (cached_stream.has_value())
    {
        active_file = std::move(*cached_stream);

        // Only valid streams in the cache
        GFXRECON_ASSERT(active_file);
        GFXRECON_ASSERT(active_file->IsOpen());
    }
    else
    {
        // No stream in cache, create one
        active_file = std::make_shared<FileInputStream>();
        bool opened = active_file->Open(filename);

        if (!opened || !active_file->IsOpen())
        {
            process_error_state_ = kErrorOpeningFile;
            return false;
        }

        // It's possible we'll want to use the input streams more than once, (kExecuteBlocksFromFile, usage often
        // does in test cases), so we'll stash off the stream's shared pointer to a cache
        stream_cache_.Insert(active_file);
    }

    // Now that we have a new stream or old, push it on the stack
    file_stack_.emplace_back(std::move(active_file), execute_till_eof);
    process_error_state_ = kErrorNone;
    return true;
}

bool FileProcessor::SetActiveFile(const std::string&             filename,
                                  int64_t                        offset,
                                  util::platform::FileSeekOrigin origin,
                                  bool                           execute_till_eof)
{
    bool success = SetActiveFile(filename, execute_till_eof);
    if (success)
    {
        return SeekActiveFile(file_stack_.back().active_file, offset, origin);
    }
    else
    {
        return false;
    }
}

void FileProcessor::HandleBlockReadError(BlockIOError error_code, const char* error_message)
{
    GFXRECON_ASSERT(!file_stack_.empty());
    const auto& active_file = file_stack_.back().active_file;

    // Report incomplete block at end of file as a warning, other I/O errors as an error.
    if (active_file->IsEof() && !active_file->IsError())
    {
        GFXRECON_LOG_WARNING("Incomplete block at end of file");
    }
    else
    {
        GFXRECON_LOG_ERROR(
            "%s (frame %u block %" PRIu64 ")", error_message, process_frame_number_, process_block_index_);
        process_error_state_ = error_code;
    }
}

void FileProcessor::UpdateEndFrameState()
{
    if (pending_capture_uses_frame_markers_)
    {
        // If the capture file contains frame markers, it will have a frame marker for every
        // frame-ending API call such as vkQueuePresentKHR. If this is the first frame marker
        // encountered, reset the frame count and ignore frame-ending API calls in
        // IsFrameDelimiter(format::ApiCallId call_id).
        GFXRECON_ASSERT(!capture_uses_frame_markers_);
        capture_uses_frame_markers_         = true;
        pending_capture_uses_frame_markers_ = false;
        process_frame_number_               = kFirstFrame;
        GFXRECON_LOG_WARNING("Explicit frame markers found in file format (0.0) file w/ gfxrecon-version < (1.0.1). "
                             "Patch input file format with 'gfxrecon-file-version-patch'");
    }

    // Make sure to increment the frame number on the way out.
    ++process_frame_number_;
}

bool FileProcessor::ProcessFrameDelimiter(gfxrecon::format::ApiCallId call_id)
{
    return IsFrameDelimiter(call_id);
}

bool FileProcessor::ProcessFrameDelimiter(const FrameEndMarkerArgs& end_frame)
{
    // Validate frame end marker's frame number matches current_frame_number_ when capture_uses_frame_markers_ is
    // true.
    GFXRECON_ASSERT((!capture_uses_frame_markers_) ||
                    (process_frame_number_ == (end_frame.frame_number - first_frame_)));
    if (IsFrameDelimiter(format::BlockType::kFrameMarkerBlock, format::MarkerType::kEndMarker))
    {
        // If this is the first FrameEndMarker, this frame has side effects to be applied after dispatch
        if (!capture_uses_frame_markers_)
        {
            pending_capture_uses_frame_markers_ = true;
        }
        return true;
    }
    return false;
}
bool FileProcessor::ProcessExecuteBlocksFromFile(const ExecuteBlocksFromFileArgs& exec_from_file)
{
    std::string filename = util::filepath::Join(absolute_path_, exec_from_file.filename);

    // Check for self references
    if (!filename.compare(file_stack_.back().active_file->GetFilename()))
    {
        GFXRECON_LOG_WARNING("ExecuteBlocksFromFile is referencing itself. Probably this is not intentional.");
    }

    bool success =
        SetActiveFile(filename, exec_from_file.offset, util::platform::FileSeekSet, exec_from_file.n_blocks == 0);

    if (success)
    {
        // We need to add 1 because it will be decremented right after this function returns
        file_stack_.back().remaining_commands = exec_from_file.n_blocks + 1;
    }

    return success;
}

void FileProcessor::ProcessStateBeginMarker(const StateBeginMarkerArgs& state_begin)
{
    GFXRECON_LOG_INFO("Loading state for captured frame %" PRId64, state_begin.frame_number);
    loading_trimmed_capture_state_ = true;
}

void FileProcessor::ProcessStateEndMarkerFrameState(const StateEndMarkerArgs& state_end)
{
    first_frame_ = state_end.frame_number;
}

void FileProcessor::ProcessStateEndMarker(const StateEndMarkerArgs& state_end)
{
    GFXRECON_LOG_INFO("Finished loading state for captured frame %" PRId64, state_end.frame_number);
    loading_trimmed_capture_state_ = false;
}

void FileProcessor::ProcessAnnotation(const AnnotationArgs& annotation)
{
    // We can infer the presence of frame markers from the operations version
    if (annotation.type == gfxrecon::format::AnnotationType::kJson &&
        annotation.label.compare(gfxrecon::format::kAnnotationLabelOperation) == 0)
    {
        // This is an operations annotation containing the version of the capture tool.
        format::GfxrVersion version = format::ParseVersionFromOperations(annotation.annotation_data.c_str());
        if (version.SupportsFrameMarkers())
        {
            GFXRECON_ASSERT(process_frame_number_ == kFirstFrame);
            capture_uses_frame_markers_  = true;
            file_supports_frame_markers_ = true;
        }
    }
}

bool FileProcessor::IsFrameDelimiter(format::BlockType block_type, format::MarkerType marker_type) const
{
    return ((block_type == format::BlockType::kFrameMarkerBlock) && (marker_type == format::MarkerType::kEndMarker));
}

bool FileProcessor::IsFrameDelimiter(format::ApiCallId call_id) const
{
    if (capture_uses_frame_markers_)
    {
        return false;
    }
    else
    {
        // This code is deprecated and no new API calls should be added. Instead, end of frame markers are used to track
        // the file processor's frame count.
        return ((call_id == format::ApiCallId::ApiCall_vkQueuePresentKHR) ||
                (call_id == format::ApiCallId::ApiCall_vkFrameBoundaryANDROID) ||
                (call_id == format::ApiCallId::ApiCall_IDXGISwapChain_Present) ||
                (call_id == format::ApiCallId::ApiCall_IDXGISwapChain1_Present1) ||
                (call_id == format::ApiCallId::ApiCall_xrEndFrame));
    }
}

void FileProcessor::PrintBlockInfo() const
{
    if (enable_print_block_info_ &&
        ((block_index_from_ < 0 || block_index_to_ < 0) ||
         (block_index_from_ <= process_block_index_ && block_index_to_ >= process_block_index_)))
    {
        GFXRECON_LOG_INFO(
            "block info: index: %" PRIu64 ", current frame: %" PRIu64 "", process_block_index_, process_frame_number_);
    }
}

FileProcessor::ProcessBlockState FileProcessor::HandleBlockEof(const char* operation, bool report_frame_and_block)
{

    ProcessBlockState state = ProcessBlockState::kEndProcessing;
    if (!AtEof())
    {
        // No data has been read for the current block, so we don't use 'HandleBlockReadError' here, as it
        // assumes that the block header has been successfully read and will print an incomplete block at
        // end of file warning when the file is at EOF without an error. For this case (the normal EOF case)
        // we print nothing at EOF, or print an error message and set the error code directly when not at
        // EOF.
        if (report_frame_and_block)
        {
            GFXRECON_LOG_ERROR("Failed to %s block header (frame %u block %" PRIu64 ")",
                               operation,
                               process_frame_number_,
                               process_block_index_);
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to %s block header", operation);
        }

        process_error_state_ = kErrorReadingBlockHeader;
        state        = ProcessBlockState::kError;
    }
    else
    {
        GFXRECON_ASSERT(!file_stack_.empty());

        ActiveFileContext& current_file = GetCurrentFile();
        if (current_file.execute_till_eof)
        {
            file_stack_.pop_back();
            if (!file_stack_.empty())
            {
                state = ProcessBlockState::kRunning;
            }
        }
    }
    return state;
}

void FileProcessor::SetDecoderFrameNumber(uint64_t frame_number)
{
    for (auto* decoder : decoders_)
    {
        decoder->SetCurrentFrameNumber(frame_number);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
