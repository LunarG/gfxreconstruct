/*
** Copyright (c) 2018-2020,2022 Valve Corporation
** Copyright (c) 2018-2020,2022,2026 LunarG, Inc.
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

#include "decode/block_processor.h"
#include "decode/async_processor.h"         // AsyncProcessPolicy
#include "decode/file_processor.h"          // FileProcessor (for SynchronousProcessPolicy friendship)
#include "decode/file_processor_visitors.h" // ProcessVisitor, PreloadProcessPolicy, SynchronousProcessPolicy
#include "format/format_util.h"
#include "util/logging.h"

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

BlockProcessor::BlockProcessor() {}

bool BlockProcessor::Initialize(const std::string& filename)
{
    bool success = SetActiveFile(filename, true);

    if (success)
    {
        success = success && ProcessFileHeader();
    }
    else
    {
        error_state_ = kErrorOpeningFile;
    }

    if (success)
    {
        absolute_path_ = util::filepath::GetBasedir(filename);

        auto err_handler = BlockParser::ErrorHandler{ [this](BlockIOError err, const char* message) {
            HandleBlockReadError(err, message);
        } };
        block_parser_ = std::make_unique<BlockParser>(err_handler, compressor_.get());
        if (block_parser_.get() != nullptr)
        {
            block_parser_->SetDecompressionPolicy(BlockParser::DecompressionPolicy::kAlways);
        }
        else
        {
            error_state_ = kErrorOpeningFile;
            success      = false;
        }
    }

    return success;
}

void BlockProcessor::InitializeFrameProcessing(const file_processor::FrameProcessingParams& params,
                                               std::function<void()>&&                      skip_on_complete)
{
    params_ = params;

    if (!pending_blocks_to_skip_.empty())
    {
        block_skip_ = std::make_unique<file_processor::BlockSkip>(std::move(pending_blocks_to_skip_),
                                                                  std::move(skip_on_complete));
    }

    if (params_.async)
    {
        GFXRECON_ASSERT(frame_number_ == file_processor::kFirstFrame);
        block_parser_->SetOperationMode(BlockParser::OperationMode::kEnqueued);
    }
}

std::unique_ptr<util::Compressor> BlockProcessor::CreateReplayCompressor() const
{
    return util::Compressor::Copy(compressor_.get());
}

BlockParser& BlockProcessor::GetBlockParser()
{
    GFXRECON_ASSERT(block_parser_.get() != nullptr);
    return *block_parser_;
}

bool BlockProcessor::IsFileValid() const
{
    if (!file_stack_.empty())
    {
        return file_stack_.back().active_file->IsReady();
    }
    return false;
}

file_processor::ProcessBlocksResult BlockProcessor::MakeResult(file_processor::ProcessBlockState state) const
{
    return file_processor::ProcessBlocksResult(
        state, error_state_, frame_number_, bytes_read_, capture_uses_frame_markers_, file_supports_frame_markers_);
}

template <typename Policy>
file_processor::ProcessBlockState BlockProcessor::ProcessBlocks(Policy& policy)
{
    BlockBuffer                       block_buffer;
    file_processor::ProcessBlockState process_state = file_processor::ProcessBlockState::kContinue;
    BlockParser&                      block_parser  = *block_parser_.get();
    file_processor::ProcessVisitor    process_visitor(*this);

    while (process_state == file_processor::ProcessBlockState::kContinue)
    {
        PrintBlockInfo();

        bool success = policy.ContinueBlockProcessing(block_index_);

        if (success)
        {
            success = ReadBlockBuffer(block_parser, block_buffer);

            if (success)
            {
                const bool skip_block = block_skip_ && (*block_skip_)(block_index_);
                if (!skip_block)
                {
                    block_parser.SetBlockIndex(block_index_);
                    block_parser.SetFrameNumber(frame_number_);
                    ParsedBlock& parsed_block = block_parser.ParseBlock(block_buffer);

                    if (parsed_block.IsVisitable())
                    {
                        std::visit(process_visitor, parsed_block.GetArgs());
                        success = process_visitor.IsSuccess();
                        if (success)
                        {
                            process_state = policy.Dispatch(block_index_, parsed_block);
                            if ((file_processor::ProcessBlockState::kContinue == process_state) &&
                                process_visitor.IsFrameDelimiter())
                            {
                                process_state = file_processor::ProcessBlockState::kFrameBoundary;
                            }
                        }
                        else
                        {
                            process_state = file_processor::ProcessBlockState::kError;
                        }
                    }
                    else if (!parsed_block.IsValid())
                    {
                        process_state = file_processor::ProcessBlockState::kError;
                    }
                }
                ++block_index_;
                DecrementRemainingCommands();
            }
            else
            {
                process_state = HandleBlockEof("read", true);
            }
        }
        else
        {
            process_state = file_processor::ProcessBlockState::kEndProcessing;
        }
    }

    if (process_state == file_processor::ProcessBlockState::kFrameBoundary)
    {
        UpdateEndFrameState();
    }

    return process_state;
}

bool BlockProcessor::ProcessFileHeader()
{
    bool success = false;
    file_header_ = format::FileHeader();

    GFXRECON_ASSERT(file_stack_.front().active_file);

    if (ReadBytes(&file_header_, sizeof(file_header_)))
    {
        success = format::ValidateFileHeader(file_header_);

        if (success)
        {
            auto file_version = GFXRECON_MAKE_FILE_VERSION(file_header_.major_version, file_header_.minor_version);
            if (file_version >= GFXRECON_EXPLICIT_FRAME_MARKER_FILE_VERSION)
            {
                capture_uses_frame_markers_  = true;
                file_supports_frame_markers_ = true;
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
                    error_state_ = kErrorUnsupportedCompressionType;
                }
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("File header contains invalid four character code");
            error_state_ = kErrorInvalidFourCC;
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to read file header");
        error_state_ = kErrorReadingFileHeader;
    }

    return success;
}

void BlockProcessor::DecrementRemainingCommands()
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

bool BlockProcessor::ReadBlockBuffer(BlockParser& parser, BlockBuffer& block_buffer)
{
    bool         success = true;
    BlockIOError status  = parser.ReadBlockBuffer(GetCurrentFile().active_file, block_buffer);
    if (status == kErrorNone)
    {
        bytes_read_ += block_buffer.Size();
    }
    else
    {
        if (status != kEndOfFile)
        {
            HandleBlockReadError(status, "Failed to read next block");
        }
        success = false;
    }
    return success;
}

bool BlockProcessor::ReadBytes(void* buffer, size_t buffer_size)
{
    const auto& active_file = file_stack_.back().active_file;
    GFXRECON_ASSERT(active_file);

    if (active_file->ReadBytes(buffer, buffer_size))
    {
        bytes_read_ += buffer_size;
        return true;
    }
    return false;
}

void BlockProcessor::HandleBlockReadError(BlockIOError error_code, const char* error_message)
{
    GFXRECON_ASSERT(!file_stack_.empty());
    const auto& active_file = file_stack_.back().active_file;

    if (active_file->IsEof() && !active_file->IsError())
    {
        GFXRECON_LOG_WARNING("Incomplete block at end of file");
    }
    else
    {
        GFXRECON_LOG_ERROR("%s (frame %u block %" PRIu64 ")", error_message, frame_number_, block_index_);
        error_state_ = error_code;
    }
}

void BlockProcessor::UpdateEndFrameState()
{
    if (pending_capture_uses_frame_markers_)
    {
        GFXRECON_ASSERT(!capture_uses_frame_markers_);
        capture_uses_frame_markers_         = true;
        pending_capture_uses_frame_markers_ = false;
        frame_number_                       = file_processor::kFirstFrame;
        GFXRECON_LOG_WARNING("Explicit frame markers found in file format (0.0) file w/ gfxrecon-version < (1.0.1). "
                             "Patch input file format with 'gfxrecon-file-version-patch'");
    }

    ++frame_number_;
}

bool BlockProcessor::ProcessFrameDelimiter(format::ApiCallId call_id)
{
    return IsFrameDelimiter(call_id);
}

bool BlockProcessor::ProcessFrameDelimiter(const FrameEndMarkerArgs& end_frame)
{
    if (capture_uses_frame_markers_ && (frame_number_ != (end_frame.frame_number - first_frame_)))
    {
        GFXRECON_LOG_ERROR("Frame end marker frame number (%" PRIu64 ") does not match current frame number (%" PRIu64
                           ")",
                           end_frame.frame_number - first_frame_,
                           frame_number_);
    }
    if (IsFrameDelimiter(format::BlockType::kFrameMarkerBlock, format::MarkerType::kEndMarker))
    {
        if (!capture_uses_frame_markers_)
        {
            pending_capture_uses_frame_markers_ = true;
        }
        return true;
    }
    return false;
}

bool BlockProcessor::ProcessExecuteBlocksFromFile(const ExecuteBlocksFromFileArgs& exec_from_file)
{
    std::string filename = util::filepath::Join(absolute_path_, exec_from_file.filename);

    if (!filename.compare(file_stack_.back().active_file->GetFilename()))
    {
        GFXRECON_LOG_WARNING("ExecuteBlocksFromFile is referencing itself. Probably this is not intentional.");
    }

    bool success =
        SetActiveFile(filename, exec_from_file.offset, util::platform::FileSeekSet, exec_from_file.n_blocks == 0);

    if (success)
    {
        file_stack_.back().remaining_commands = exec_from_file.n_blocks + 1;
    }

    return success;
}

void BlockProcessor::ProcessStateEndMarkerFrameState(const StateEndMarkerArgs& state_end)
{
    first_frame_ = state_end.frame_number;
}

void BlockProcessor::ProcessAnnotation(const AnnotationArgs& annotation)
{
    if (annotation.type == gfxrecon::format::AnnotationType::kJson &&
        annotation.label.compare(gfxrecon::format::kAnnotationLabelOperation) == 0)
    {
        format::GfxrVersion version = format::ParseVersionFromOperations(annotation.annotation_data.c_str());
        if (version.SupportsFrameMarkers())
        {
            GFXRECON_ASSERT(frame_number_ == file_processor::kFirstFrame);
            capture_uses_frame_markers_  = true;
            file_supports_frame_markers_ = true;
        }
    }
}

// static
bool BlockProcessor::IsFrameDelimiter(format::BlockType block_type, format::MarkerType marker_type)
{
    return ((block_type == format::BlockType::kFrameMarkerBlock) && (marker_type == format::MarkerType::kEndMarker));
}

bool BlockProcessor::IsFrameDelimiter(format::ApiCallId call_id) const
{
    if (capture_uses_frame_markers_)
    {
        return false;
    }
    return ((call_id == format::ApiCallId::ApiCall_vkQueuePresentKHR) ||
            (call_id == format::ApiCallId::ApiCall_vkFrameBoundaryANDROID) ||
            (call_id == format::ApiCallId::ApiCall_IDXGISwapChain_Present) ||
            (call_id == format::ApiCallId::ApiCall_IDXGISwapChain1_Present1) ||
            (call_id == format::ApiCallId::ApiCall_xrEndFrame));
}

void BlockProcessor::PrintBlockInfo() const
{
    if (params_.print_block_info && ((params_.block_index_from < 0 || params_.block_index_to < 0) ||
                                     (params_.block_index_from <= static_cast<int64_t>(block_index_) &&
                                      params_.block_index_to >= static_cast<int64_t>(block_index_))))
    {
        GFXRECON_LOG_INFO("block info: index: %" PRIu64 ", current frame: %" PRIu64 "", block_index_, frame_number_);
    }
}

file_processor::ProcessBlockState BlockProcessor::HandleBlockEof(const char* operation, bool report_frame_and_block)
{
    file_processor::ProcessBlockState state = file_processor::ProcessBlockState::kEndProcessing;
    if (!AtEof())
    {
        if (report_frame_and_block)
        {
            GFXRECON_LOG_ERROR(
                "Failed to %s block header (frame %u block %" PRIu64 ")", operation, frame_number_, block_index_);
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to %s block header", operation);
        }

        error_state_ = kErrorReadingBlockHeader;
        state        = file_processor::ProcessBlockState::kError;
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
                state = file_processor::ProcessBlockState::kContinue;
            }
            else
            {
                state = file_processor::ProcessBlockState::kEndOfFile;
            }
        }
    }
    return state;
}

bool BlockProcessor::SeekActiveFile(const FileInputStreamPtr&      active_file,
                                    int64_t                        offset,
                                    util::platform::FileSeekOrigin origin)
{
    GFXRECON_ASSERT(active_file);

    bool success = active_file->FileSeek(offset, origin);

    if (success && origin == util::platform::FileSeekCurrent)
    {
        bytes_read_ += offset;
    }

    return success;
}

bool BlockProcessor::SeekActiveFile(int64_t offset, util::platform::FileSeekOrigin origin)
{
    return SeekActiveFile(file_stack_.back().active_file, offset, origin);
}

bool BlockProcessor::SetActiveFile(const std::string& filename, bool execute_till_eof)
{
    auto cached_stream = stream_cache_.Lookup(filename);

    FileInputStreamPtr active_file;
    if (cached_stream.has_value())
    {
        active_file = std::move(*cached_stream);

        GFXRECON_ASSERT(active_file);
        GFXRECON_ASSERT(active_file->IsOpen());
    }
    else
    {
        active_file = std::make_shared<FileInputStream>();
        bool opened = active_file->Open(filename);

        if (!opened || !active_file->IsOpen())
        {
            error_state_ = kErrorOpeningFile;
            return false;
        }

        stream_cache_.Insert(active_file);
    }

    file_stack_.emplace_back(std::move(active_file), execute_till_eof);
    error_state_ = kErrorNone;
    return true;
}

bool BlockProcessor::SetActiveFile(const std::string&             filename,
                                   int64_t                        offset,
                                   util::platform::FileSeekOrigin origin,
                                   bool                           execute_till_eof)
{
    bool success = SetActiveFile(filename, execute_till_eof);
    if (success)
    {
        return SeekActiveFile(file_stack_.back().active_file, offset, origin);
    }
    return false;
}

bool BlockProcessor::AtEof() const
{
    if (file_stack_.empty())
    {
        return true;
    }
    return file_stack_.back().active_file->IsEof();
}

BlockProcessor::ActiveFileContext& BlockProcessor::GetCurrentFile()
{
    GFXRECON_ASSERT(file_stack_.size());
    return file_stack_.back();
}

// Explicit template instantiations -- all three policies that ProcessBlocks is used with.
template file_processor::ProcessBlockState
BlockProcessor::ProcessBlocks<file_processor::PreloadProcessPolicy>(file_processor::PreloadProcessPolicy&);
template file_processor::ProcessBlockState
BlockProcessor::ProcessBlocks<file_processor::SynchronousProcessPolicy>(file_processor::SynchronousProcessPolicy&);
template file_processor::ProcessBlockState
BlockProcessor::ProcessBlocks<file_processor::AsyncProcessPolicy>(file_processor::AsyncProcessPolicy&);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
