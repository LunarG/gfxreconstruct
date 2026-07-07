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
#include "decode/decode_allocator.h"
#include "decode/file_processor.h"
#include "decode/file_processor_visitors.h" // Must be after file_processor.h for FileProcessor callbacks
#include "util/logging.h"

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

FileProcessor::FileProcessor(uint64_t block_limit) :
    block_limit_{ block_limit }, block_processor_(std::make_unique<BlockProcessor>()), async_block_iterator_(),
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
    GFXRECON_ASSERT(block_processor_ != nullptr);
    GFXRECON_ASSERT(!frame_processing_initialized_);
    // Asserts in DEBUG, fails in RELEASE if either block_processor_ is null (moved to AsyncProcessor) or
    // InitializeFrameProcessing() has already been called.
    if ((block_processor_ == nullptr) || frame_processing_initialized_)
    {
        return false;
    }

    frame_processing_initialized_ = true;

    // Transfer pending skip-blocks from FileProcessor to BlockProcessor.
    // Stored here so they survive any BlockProcessor replacement in Initialize().
    if (!pending_blocks_to_skip_.empty())
    {
        block_processor_->SetPendingBlocksToSkip(std::move(pending_blocks_to_skip_));
    }

    // Build the skip-completion callback here because set_finished captures FileProcessor state.
    std::function<void()> on_complete;
    if (block_processor_->HasPendingBlocksToSkip())
    {
        auto set_finished = [this] { dispatch_skipping_finished_ = true; };
        if (params.async)
        {
            BlockParser* parser = &block_processor_->GetBlockParser();
            on_complete         = [parser, set_finished] { parser->EmplaceCallbackBlock(set_finished); };
        }
        else
        {
            on_complete = set_finished;
        }
    }

    block_processor_->InitializeFrameProcessing(params, std::move(on_complete));

    // Clone the compressor before any ownership transfer; replay uses this on the dispatch thread.
    replay_compressor_ = block_processor_->CreateReplayCompressor();

    if (params.async)
    {
        GFXRECON_ASSERT(block_processor_->GetProcessFrameNumber() == kFirstFrame);

        // Transfer block_processor_ to AsyncProcessor. After this, block_processor_ is null -- intentional.
        async_processor_ = std::make_unique<AsyncProcessor>(std::move(block_processor_));
        async_processor_->SetBlockLimit(block_limit_);

        // Blocks until async_processor_ flushes its first batch (or finishes with no batches).
        async_processor_->LaunchAsyncThread();

        // c.f. file_processor_types.h re: iterator semantics.
        async_block_iterator_ = BlockIterator(&async_processor_->GetBatchIterator());
    }

    return dispatch_error_state_ == kErrorNone;
}

bool FileProcessor::Initialize(const std::string& filename)
{
    GFXRECON_ASSERT(block_processor_ != nullptr);
    bool success = block_processor_->Initialize(filename);

    if (success)
    {
        // Cache header and options so they remain accessible after block_processor_ transfers to AsyncProcessor.
        file_header_  = block_processor_->GetFileHeader();
        file_options_ = block_processor_->GetFileOptions();
    }
    else
    {
        dispatch_error_state_ = block_processor_->GetProcessError();
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
    DispatchVisitor dispatch_visitor(*this, config_);
    async_block_iterator_ = ReplayOneFrame(dispatch_visitor, async_block_iterator_, BlockIterator());

    const ProcessBlocksResult& result = dispatch_visitor.GetReplayResult();
    HandleReplayResult(result);

    return ContinueProcessing(result.state);
}

bool FileProcessor::ProcessNextFrameSync()
{
    GFXRECON_ASSERT(!AsyncProcessingEnabled()); // block_processor_ is null in async mode
    if (!block_processor_->IsFileValid())
    {
        // Correctly handle file invalid (either errror or EOF)
        dispatch_error_state_ = block_processor_->GetProcessError();
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

    GFXRECON_ASSERT(block_processor_->GetBlockParser().GetOperationMode() == BlockParser::OperationMode::kImmediate);
    GFXRECON_ASSERT(block_processor_->GetBlockParser().GetDecompressionPolicy() ==
                    BlockParser::DecompressionPolicy::kAlways);

    DispatchVisitor                          dispatch_visitor(*this, config_);
    file_processor::SynchronousProcessPolicy process_policy{ *this, dispatch_visitor };

    GFXRECON_ASSERT(dispatch_frame_number_ == block_processor_->GetProcessFrameNumber());

    SetDecoderFrameNumber(dispatch_frame_number_);
    ProcessBlockState process_result = block_processor_->ProcessBlocks(process_policy);

    // In sync mode, process-side state is directly usable as the dispatch-side snapshot.
    ProcessBlocksResult result = block_processor_->MakeResult(process_result);
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

void FileProcessor::HandleReplayResult(const ProcessBlocksResult& result)
{
    dispatch_error_state_ = result.error;

    if (result.snapshot.has_value())
    {
        dispatch_frame_number_                = result.snapshot->frame_number;
        dispatch_bytes_read_                  = result.snapshot->bytes_read;
        dispatch_capture_uses_frame_markers_  = result.snapshot->capture_uses_frame_markers;
        dispatch_file_supports_frame_markers_ = result.snapshot->file_supports_frame_markers;
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
    const util::Compressor* compressor = replay_compressor_.get();

    ProcessBlockState             state = ProcessBlockState::kContinue;
    file_processor::BlockIterator it    = begin;

    SetDecoderFrameNumber(dispatch_frame_number_);
    while ((it != end) && (ProcessBlockState::kContinue == state))
    {
        ParsedBlock& block = *it;
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

void FileProcessor::ProcessStateBeginMarker(const StateBeginMarkerArgs& state_begin)
{
    GFXRECON_LOG_INFO("Loading state for captured frame %" PRId64, state_begin.frame_number);
    loading_trimmed_capture_state_ = true;
}

void FileProcessor::ProcessStateEndMarker(const StateEndMarkerArgs& state_end)
{
    GFXRECON_LOG_INFO("Finished loading state for captured frame %" PRId64, state_end.frame_number);
    loading_trimmed_capture_state_ = false;
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
