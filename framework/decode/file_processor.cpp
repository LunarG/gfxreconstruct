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

#include "decode/async_processor.h"
#include "decode/block_buffer.h"
#include "decode/file_processor.h"
#include "decode/file_processor_visitors.h" // Must be after file_processor.h for FileProcessor callbacks
#include "format/format_util.h"
#include "util/logging.h"

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

FileProcessor::FileProcessor(uint64_t block_limit) :
    block_limit_{ block_limit }, proc_(std::make_unique<BlockProcessor>()), async_block_iterator_(),
    working_uncompressed_store_(kWorkingStoreInitialSize)
{}

FileProcessor::~FileProcessor()
{
    DecodeAllocator::DestroyInstance();
}

void FileProcessor::WaitDecodersIdle()
{
    for (auto decoder : config_.decoders)
    {
        decoder->WaitIdle();
    }
}

void FileProcessor::SetBlocksToSkip(const std::unordered_set<uint64_t>& blocks_to_skip)
{
    GFXRECON_ASSERT(!frame_processing_initialized_);
    // Calling this function after InitializeFrameProcessing() is an error, asserting
    // in DEBUG, and a no-op in RELEASE.
    if (!frame_processing_initialized_)
    {
        dispatch_skipping_finished_ = blocks_to_skip.empty();
        pending_blocks_to_skip_     = blocks_to_skip;
    }
}

bool FileProcessor::InitializeFrameProcessing(const FrameProcessingParams& params)
{
    GFXRECON_ASSERT(proc_ != nullptr);
    GFXRECON_ASSERT(!frame_processing_initialized_);
    // Asserts in DEBUG, fails in RELEASE if either proc_ is null (moved to AsyncProcessor) or
    // InitializeFrameProcessing() has already been called.
    if ((proc_ == nullptr) || frame_processing_initialized_)
    {
        return false;
    }

    frame_processing_initialized_ = true;

    // Transfer pending skip-blocks from FileProcessor to BlockProcessor.
    // Stored here so they survive any BlockProcessor replacement in Initialize().
    if (!pending_blocks_to_skip_.empty())
    {
        proc_->SetPendingBlocksToSkip(std::move(pending_blocks_to_skip_));
    }

    // Build the skip-completion callback here because set_finished captures FileProcessor state.
    std::function<void()> on_complete;
    if (proc_->HasPendingBlocksToSkip())
    {
        auto                  set_finished = [this] { dispatch_skipping_finished_ = true; };
        std::function<void()> on_complete;
        if (params.async)
        {
            BlockParser* parser = proc_->block_parser.get();
            on_complete         = [parser, set_finished] { parser->EmplaceCallbackBlock(set_finished); };
        }
        else
        {
            on_complete = set_finished;
        }
        proc_->block_skip =
            std::make_unique<BlockSkip>(std::move(proc_->pending_blocks_to_skip), std::move(on_complete));
    }

    if (proc_->params.async)
    {
        GFXRECON_ASSERT(proc_->GetProcessFrameNumber() == kFirstFrame);

        // Transfer proc_ to AsyncProcessor. After this, proc_ is null -- intentional.
        async_processor_ = std::make_unique<AsyncProcessor>(std::move(proc_));
        async_processor_->SetBlockLimit(block_limit_);
        async_processor_->SetPreloadFrameRange(proc_->params.preload_range);
        if (proc_->params.quit_before_frame != kMaxFrame)
        {
            async_processor_->SetQuitBeforeFrame(proc_->params.quit_before_frame);
        }

        // Blocks until async_processor_ flushes its first batch (or finishes processing with no batches).
        async_processor_->LaunchAsyncThread();

        // c.f. file_processor_types.h re: iterator semantics.
        async_block_iterator_ = BlockIterator(&async_processor_->GetBatchIterator());
    }

    return dispatch_error_state_ == kErrorNone;
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
        proc_->absolute_path = util::filepath::GetBasedir(filename);

        // Initialize block parser, with the compressor created during file header processing.
        auto err_handler = BlockParser::ErrorHandler{ [this](BlockIOError err, const char* message) {
            HandleBlockReadError(err, message);
        } };
        proc_->block_parser = std::make_unique<BlockParser>(err_handler, proc_->compressor.get());
        if (proc_->block_parser.get() != nullptr)
        {
            // For immediate dispatching (the default mode of operation) no need to defer decompression
            proc_->block_parser->SetDecompressionPolicy(BlockParser::DecompressionPolicy::kAlways);
        }
        else
        {
            dispatch_error_state_ = kErrorOpeningFile;
            success               = false;
        }
    }

    return success;
}

bool FileProcessor::ProcessNextFrame()
{
    GFXRECON_ASSERT(frame_processing_initialized_);
    if (AsyncProcessingEnabled())
    {
        return ProcessNextFrameAsync();
    }
    return ProcessNextFrameSync();
}

bool FileProcessor::ProcessNextFrameAsync()
{
    // Note that this call may block on empty queue, but the async
    // queue loader should always close the queue on end processing or error
    // NOTE: If the dispatch visitor is reused from frame to frame, then should be Reset().
    DispatchVisitor dispatch_visitor(*this, config_);
    async_block_iterator_ = ReplayOneFrame(dispatch_visitor, async_block_iterator_, BlockIterator());

    const ProcessBlocksResult& result = dispatch_visitor.GetReplayResult();
    HandleReplayResult(result);

    return ContinueProcessing(result.state);
}

file_processor::ProcessBlocksResult FileProcessor::MakeResult(ProcessBlockState state) const
{
    return ProcessBlocksResult(state,
                               proc_->error_state,
                               proc_->frame_number,
                               proc_->bytes_read,
                               proc_->capture_uses_frame_markers,
                               proc_->file_supports_frame_markers);
}

bool FileProcessor::ProcessNextFrameSync()
{
    if (!IsFileValid())
    {
        // Correctly handle file invalid (either errror or EOF)
        dispatch_error_state_ = proc_->GetProcessError();
        if (IsErrorCode(dispatch_error_state_))
        {
            dispatch_terminal_state_ = ProcessBlockState::kError;
        }
        else
        {
            // We're out of file content without error, so mark as end of processing.
            // the last frame has been processed.
            dispatch_terminal_state_ = ProcessBlockState::kEndOfFile;
        }
        return false;
    }

    // The dispatch function is correct only for non-enqueued, and requires decompression during ParsedBlock creation
    GFXRECON_ASSERT(proc_->block_parser->GetOperationMode() == BlockParser::OperationMode::kImmediate);
    GFXRECON_ASSERT(proc_->block_parser->GetDecompressionPolicy() == BlockParser::DecompressionPolicy::kAlways);

    DispatchVisitor                          dispatch_visitor(*this, config_);
    file_processor::SynchronousProcessPolicy process_policy{ *this, dispatch_visitor };

    // This is immediate mode, process and dispatch frame numbers are matched.
    // This should be true for initialization and every frame when not replaying from preload.
    // But we don't call down this path after preloading and before replay is complete.
    GFXRECON_ASSERT(dispatch_frame_number_ == proc_->frame_number);

    SetDecoderFrameNumber(dispatch_frame_number_);
    ProcessBlockState process_result = ProcessBlocks(process_policy);

    // In sync mode, process-side state is directly usable as the dispatch-side snapshot.
    ProcessBlocksResult result = MakeResult(process_result);
    HandleReplayResult(result);

    return ContinueProcessing(process_result);
}

bool FileProcessor::ProcessAllFrames()
{
    if (!frame_processing_initialized_)
    {
        InitializeFrameProcessing();
    }
    bool success = true;

    while (success)
    {
        if (success)
        {
            success = ProcessNextFrame();
        }
    }

    return (dispatch_error_state_ == kErrorNone);
}

bool FileProcessor::ProcessFileHeader()
{
    bool success       = false;
    proc_->file_header = format::FileHeader();

    assert(proc_->file_stack.front().active_file);

    if (ReadBytes(&proc_->file_header, sizeof(proc_->file_header)))
    {
        success = format::ValidateFileHeader(proc_->file_header);

        if (success)
        {
            auto file_version =
                GFXRECON_MAKE_FILE_VERSION(proc_->file_header.major_version, proc_->file_header.minor_version);
            if (file_version >= GFXRECON_EXPLICIT_FRAME_MARKER_FILE_VERSION)
            {
                proc_->capture_uses_frame_markers  = true;
                proc_->file_supports_frame_markers = true;
            }

            proc_->file_options.resize(proc_->file_header.num_options);

            size_t option_data_size = proc_->file_header.num_options * sizeof(format::FileOptionPair);

            success = ReadBytes(proc_->file_options.data(), option_data_size);

            if (success)
            {
                for (const auto& option : proc_->file_options)
                {
                    switch (option.key)
                    {
                        case format::FileOption::kCompressionType:
                            proc_->enabled_options.compression_type =
                                static_cast<format::CompressionType>(option.value);
                            break;
                        default:
                            GFXRECON_LOG_WARNING("Ignoring unrecognized file header option %u", option.key);
                            break;
                    }
                }

                proc_->compressor.reset(format::CreateCompressor(proc_->enabled_options.compression_type));

                if ((proc_->compressor == nullptr) &&
                    (proc_->enabled_options.compression_type != format::CompressionType::kNone))
                {
                    GFXRECON_LOG_ERROR("Failed to initialize file compression module (type = %u); replay of "
                                       "compressed data will not be possible",
                                       proc_->enabled_options.compression_type);
                    success               = false;
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
    if (proc_->file_stack.empty())
    {
        return;
    }

    BlockProcessor::ActiveFileContext& current_file = GetCurrentFile();

    if (!current_file.execute_till_eof)
    {
        --current_file.remaining_commands;
        if (current_file.remaining_commands == 0)
        {
            proc_->file_stack.pop_back();
        }
    }
}

template <typename ProcessPolicy>
FileProcessor::ProcessBlockState FileProcessor::ProcessBlocks(ProcessPolicy& policy)
{
    BlockBuffer       block_buffer;
    ProcessBlockState process_state = ProcessBlockState::kContinue;
    BlockParser&      block_parser  = *proc_->block_parser.get();
    ProcessVisitor    process_visitor(*this);

    while (process_state == ProcessBlockState::kContinue)
    {
        PrintBlockInfo();

        bool success = policy.ContinueBlockProcessing(proc_->block_index);

        if (success)
        {
            success = ReadBlockBuffer(block_parser, block_buffer);

            if (success)
            {
                if (proc_->block_skip && (*proc_->block_skip)(proc_->block_index))
                {
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_buffer.Header().size);
                }
                else
                {
                    block_parser.SetBlockIndex(proc_->block_index);
                    block_parser.SetFrameNumber(proc_->frame_number);
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
                                process_state = policy.Dispatch(proc_->block_index, parsed_block);
                                if ((ProcessBlockState::kContinue == process_state) &&
                                    process_visitor.IsFrameDelimiter())
                                {
                                    process_state = ProcessBlockState::kFrameBoundary;
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
                ++proc_->block_index;
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
        proc_->bytes_read += block_buffer.Size();
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
    const auto& active_file = proc_->file_stack.back().active_file;
    GFXRECON_ASSERT(active_file);

    if (active_file->ReadBytes(buffer, buffer_size))
    {
        proc_->bytes_read += buffer_size;
        return true;
    }
    return false;
}

template file_processor::ProcessBlockState
FileProcessor::ProcessBlocks<file_processor::PreloadProcessPolicy>(file_processor::PreloadProcessPolicy& policy);
template file_processor::ProcessBlockState
FileProcessor::ProcessBlocks<file_processor::AsyncProcessPolicy>(file_processor::AsyncProcessPolicy& policy);

void FileProcessor::HandleReplayResult(const ProcessBlocksResult& result)
{
    dispatch_error_state_ = result.error;

    if (result.has_process_state)
    {
        dispatch_frame_number_                = result.frame_number;
        dispatch_bytes_read_                  = result.bytes_read;
        dispatch_capture_uses_frame_markers_  = result.capture_uses_frame_markers;
        dispatch_file_supports_frame_markers_ = result.file_supports_frame_markers;
    }

    if (!ContinueProcessing(result.state))
    {
        dispatch_terminal_state_ = result.state;
    }
}

file_processor::BlockIterator
FileProcessor::ReplayOneFrame(DispatchVisitor& dispatch_visitor, BlockIterator begin, BlockIterator end)
{
    GFXRECON_ASSERT(begin != end);
    const util::Compressor* compressor = proc_->compressor.get();

    ProcessBlockState             state = ProcessBlockState::kContinue;
    file_processor::BlockIterator it    = begin;

    SetDecoderFrameNumber(dispatch_frame_number_);
    while ((it != end) && (ProcessBlockState::kContinue == state))
    {
        ParsedBlock& block = *it;
        // We assume that only known, visitable blocks were preloaded
        GFXRECON_ASSERT(block.IsVisitable());

        // update the "dispatched" block index for the application facing interfaces and decoders
        const uint64_t block_index = block.GetBlockIndex();
        if (block_index != ParsedBlock::kInvalidIndex)
        {
            dispatch_block_index_ = block_index;
        }

        // Handle deferred decompression
        if (block.NeedsDecompression())
        {
            // Note: This path is destructive to replayed blocks.
            //
            // Decompression during replay sets the args data pointer to the working_uncompressed_store_ data.
            // The pointer is valid only until the next decompressed block -- the working store is overwritten
            // or resized, potentially invalidating the previous pointer. Replayed blocks are therefore
            // effectively single-use after decompression. Preloaded blocks intended for loop replay must
            // have been decompressed at load time (kAlways) so their args data lives in the batch allocation,
            // not in the working store.
            if (!block.Decompress(compressor, working_uncompressed_store_))
            {
                GFXRECON_LOG_ERROR("Failed to decompress block during replay (frame %" PRIu64 " block %" PRIu64 ")",
                                   dispatch_frame_number_,
                                   block_index);
                dispatch_visitor.SetReplayResult(
                    ProcessBlocksResult(ProcessBlockState::kError, kErrorReadingCompressedBlockData));
                break;
            }
        }

        // update the "dispatched" block index for the application facing interfaces and decoders
        dispatch_block_index_ = block.GetBlockIndex();
        if (file_processor::ContinueBlockProcessing<file_processor::ContinueProcessingPolicy::DecoderOnly>(
                block_limit_, config_, block_index)) // Requires the dispatch_block_index_ to be updated
        {
            dispatch_visitor.SetBlockIndex(block_index);
            state = std::visit(dispatch_visitor, block.GetArgs());
        }
        else
        {
            state = ProcessBlockState::kEndProcessing;
            dispatch_visitor.SetReplayResult(
                ProcessBlocksResult(ProcessBlockState::kEndProcessing, BlockIOError::kErrorNone));
        }

        ++it;
    }

    if (dispatch_visitor.GetReplayResult().state == ProcessBlockState::kContinue)
    {
        GFXRECON_LOG_FATAL(
            "Should never encounter end of queue without a terminating ProcessBlocksResult ahead of it.");
        dispatch_visitor.SetReplayResult(
            ProcessBlocksResult(ProcessBlockState::kError, BlockIOError::kErrorReadingBlockData));
    }
    return it;
}

bool FileProcessor::IsFileValid() const
{
    if (!proc_->file_stack.empty())
    {
        return proc_->file_stack.back().active_file->IsReady();
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
        proc_->bytes_read += offset;
    }

    return success;
}

bool FileProcessor::SeekActiveFile(int64_t offset, util::platform::FileSeekOrigin origin)
{
    return SeekActiveFile(proc_->file_stack.back().active_file, offset, origin);
}

bool FileProcessor::SetActiveFile(const std::string& filename, bool execute_till_eof)
{

    // Look for the name stream in the cache
    auto cached_stream = proc_->stream_cache.Lookup(filename);

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
            proc_->error_state = kErrorOpeningFile;
            return false;
        }

        // It's possible we'll want to use the input streams more than once, (kExecuteBlocksFromFile, usage often
        // does in test cases), so we'll stash off the stream's shared pointer to a cache
        proc_->stream_cache.Insert(active_file);
    }

    // Now that we have a new stream or old, push it on the stack
    proc_->file_stack.emplace_back(std::move(active_file), execute_till_eof);
    proc_->error_state = kErrorNone;
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
        return SeekActiveFile(proc_->file_stack.back().active_file, offset, origin);
    }
    else
    {
        return false;
    }
}

void FileProcessor::HandleBlockReadError(BlockIOError error_code, const char* error_message)
{
    GFXRECON_ASSERT(!proc_->file_stack.empty());
    const auto& active_file = proc_->file_stack.back().active_file;

    // Report incomplete block at end of file as a warning, other I/O errors as an error.
    if (active_file->IsEof() && !active_file->IsError())
    {
        GFXRECON_LOG_WARNING("Incomplete block at end of file");
    }
    else
    {
        GFXRECON_LOG_ERROR("%s (frame %u block %" PRIu64 ")", error_message, proc_->frame_number, proc_->block_index);
        proc_->error_state = error_code;
    }
}

void FileProcessor::UpdateEndFrameState()
{
    if (proc_->pending_capture_uses_frame_markers)
    {
        // If the capture file contains frame markers, it will have a frame marker for every
        // frame-ending API call such as vkQueuePresentKHR. If this is the first frame marker
        // encountered, reset the frame count and ignore frame-ending API calls in
        // IsFrameDelimiter(format::ApiCallId call_id).
        GFXRECON_ASSERT(!proc_->capture_uses_frame_markers);
        proc_->capture_uses_frame_markers         = true;
        proc_->pending_capture_uses_frame_markers = false;
        proc_->frame_number                       = kFirstFrame;
        GFXRECON_LOG_WARNING("Explicit frame markers found in file format (0.0) file w/ gfxrecon-version < (1.0.1). "
                             "Patch input file format with 'gfxrecon-file-version-patch'");
    }

    // Make sure to increment the frame number on the way out.
    ++proc_->frame_number;
}

bool FileProcessor::ProcessFrameDelimiter(gfxrecon::format::ApiCallId call_id)
{
    return IsFrameDelimiter(call_id);
}

bool FileProcessor::ProcessFrameDelimiter(const FrameEndMarkerArgs& end_frame)
{
    // Validate frame end marker's frame number matches current_frame_number_ when proc_->capture_uses_frame_markers is
    // true.
    GFXRECON_ASSERT((!proc_->capture_uses_frame_markers) ||
                    (proc_->frame_number == (end_frame.frame_number - proc_->first_frame)));
    if (IsFrameDelimiter(format::BlockType::kFrameMarkerBlock, format::MarkerType::kEndMarker))
    {
        // If this is the first FrameEndMarker, this frame has side effects to be applied after dispatch
        if (!proc_->capture_uses_frame_markers)
        {
            proc_->pending_capture_uses_frame_markers = true;
        }
        return true;
    }
    return false;
}
bool FileProcessor::ProcessExecuteBlocksFromFile(const ExecuteBlocksFromFileArgs& exec_from_file)
{
    std::string filename = util::filepath::Join(proc_->absolute_path, exec_from_file.filename);

    // Check for self references
    if (!filename.compare(proc_->file_stack.back().active_file->GetFilename()))
    {
        GFXRECON_LOG_WARNING("ExecuteBlocksFromFile is referencing itself. Probably this is not intentional.");
    }

    bool success =
        SetActiveFile(filename, exec_from_file.offset, util::platform::FileSeekSet, exec_from_file.n_blocks == 0);

    if (success)
    {
        // We need to add 1 because it will be decremented right after this function returns
        proc_->file_stack.back().remaining_commands = exec_from_file.n_blocks + 1;
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
    proc_->first_frame = state_end.frame_number;
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
            GFXRECON_ASSERT(proc_->frame_number == kFirstFrame);
            proc_->capture_uses_frame_markers  = true;
            proc_->file_supports_frame_markers = true;
        }
    }
}

bool FileProcessor::IsFrameDelimiter(format::BlockType block_type, format::MarkerType marker_type) const
{
    return ((block_type == format::BlockType::kFrameMarkerBlock) && (marker_type == format::MarkerType::kEndMarker));
}

bool FileProcessor::IsFrameDelimiter(format::ApiCallId call_id) const
{
    if (proc_->capture_uses_frame_markers)
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
    if (proc_->params.print_block_info &&
        ((proc_->params.block_index_from < 0 || proc_->params.block_index_to < 0) ||
         (proc_->params.block_index_from <= proc_->block_index && proc_->params.block_index_to >= proc_->block_index)))
    {
        GFXRECON_LOG_INFO(
            "block info: index: %" PRIu64 ", current frame: %" PRIu64 "", proc_->block_index, proc_->frame_number);
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
                               proc_->frame_number,
                               proc_->block_index);
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to %s block header", operation);
        }

        proc_->error_state = kErrorReadingBlockHeader;
        state              = ProcessBlockState::kError;
    }
    else
    {
        GFXRECON_ASSERT(!proc_->file_stack.empty());

        BlockProcessor::ActiveFileContext& current_file = GetCurrentFile();
        if (current_file.execute_till_eof)
        {
            proc_->file_stack.pop_back();
            if (!proc_->file_stack.empty())
            {
                state = ProcessBlockState::kContinue;
            }
            else
            {
                // Clean EOF: file was fully read and is the last in stack.
                state = ProcessBlockState::kEndOfFile;
            }
        }
    }
    return state;
}

void FileProcessor::SetDecoderFrameNumber(uint64_t frame_number)
{
    for (auto* decoder : config_.decoders)
    {
        decoder->SetCurrentFrameNumber(frame_number);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
