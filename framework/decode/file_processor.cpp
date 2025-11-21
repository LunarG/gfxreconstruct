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

#include "decode/file_processor.h"

#include "format/format_util.h"
#include "util/logging.h"

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// TODO GH #1195: frame numbering should be 1-based.
const uint32_t kFirstFrame = 0;

FileProcessor::FileProcessor() :
    current_frame_number_(kFirstFrame), annotation_handler_(nullptr), error_state_(kErrorInvalidFileDescriptor),
    bytes_read_(0), block_index_(0), block_limit_(0), pending_capture_uses_frame_markers_(false),
    capture_uses_frame_markers_(false), first_frame_(kFirstFrame + 1), loading_trimmed_capture_state_(false),
    pool_(util::HeapBufferPool::Create()), compressor_(nullptr)
{}

FileProcessor::FileProcessor(uint64_t block_limit) : FileProcessor()
{
    block_limit_ = block_limit;
}

FileProcessor::~FileProcessor()
{
    if (nullptr != compressor_)
    {
        delete compressor_;
        compressor_ = nullptr;
    }

    DecodeAllocator::DestroyInstance();
}

void FileProcessor::WaitDecodersIdle()
{
    for (auto decoder : decoders_)
    {
        decoder->WaitIdle();
    }
};

bool FileProcessor::Initialize(const std::string& filename)
{
    bool success = SetActiveFile(filename, true);

    if (success)
    {
        success = success && ProcessFileHeader();
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to open file %s", filename.c_str());
        error_state_ = kErrorOpeningFile;
    }

    // Find absolute path of capture file
    if (success)
    {
        absolute_path_ = util::filepath::GetBasedir(filename);
    }

    return success;
}

std::string FileProcessor::ApplyAbsolutePath(const std::string& file)
{
    if (absolute_path_.empty())
    {
        return file;
    }

    return absolute_path_ + file;
}

bool FileProcessor::ProcessNextFrame()
{
    auto block_processor = [this]() { return this->ProcessBlocksOneFrame(); };
    return DoProcessNextFrame(block_processor);
}

bool FileProcessor::ProcessBlocksOneFrame()
{
    for (ApiDecoder* decoder : decoders_)
    {
        decoder->SetCurrentFrameNumber(current_frame_number_);
    }
    return ProcessBlocks();
}

bool FileProcessor::DoProcessNextFrame(const std::function<bool()>& block_processor)
{
    bool success = IsFileValid();

    if (success)
    {

        success = block_processor();
    }
    else
    {
        error_state_ = CheckFileStatus();
    }

    return success;
}

bool FileProcessor::ProcessAllFrames()
{
    bool success = true;

    block_index_ = 0;

    while (success)
    {
        if (success)
        {
            success = ProcessNextFrame();
        }
    }

    return (error_state_ == kErrorNone);
}

bool FileProcessor::ContinueDecoding()
{
    bool early_exit = false;
    // If a block limit was specified, obey it.
    // If not (block_limit_ = 0),  then the consumer may determine early exit
    if (block_limit_ > 0)
    {
        if (block_index_ > block_limit_)
        {
            early_exit = true;
        }
    }
    else
    {
        size_t completed_decoders = 0;

        for (auto& decoder : decoders_)
        {
            if (decoder->IsComplete(block_index_) == true)
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

                compressor_ = format::CreateCompressor(enabled_options_.compression_type);

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

bool FileProcessor::ProcessBlocks()
{
    BlockBuffer block_buffer;
    bool        success = true;

    auto        err_handler = [this](BlockReadError err, const char* message) { HandleBlockReadError(err, message); };
    BlockParser block_parser(BlockParser::ErrorHandler{ err_handler }, pool_, compressor_);
    // NOTE: To test deferred decompression operation uncomment next line
    // block_parser.SetDecompressionPolicy(BlockParser::DecompressionPolicy::kQueueOptimized);

    ProcessVisitor  process_visitor(*this);
    DispatchVisitor dispatch_visitor(decoders_, annotation_handler_);

    while (success)
    {
        PrintBlockInfo();
        success = ContinueDecoding();

        if (success)
        {
            success = GetBlockBuffer(block_parser, block_buffer);

            for (auto decoder : decoders_)
            {
                decoder->SetCurrentBlockIndex(block_index_);
            }

            if (success)
            {
                format::RemoveCompressedBlockBit(block_buffer.Header().type);
                if (SkipBlockProcessing())
                {
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_buffer.Header().size);
                }
                else
                {
                    block_parser.SetBlockIndex(block_index_);
                    block_parser.SetFrameNumber(current_frame_number_);
                    // NOTE: upon successful parsing, the block_buffer block data has been moved to the
                    // parsed_block, though the block header is still valid.
                    ParsedBlock parsed_block = block_parser.ParseBlock(block_buffer);

                    // NOTE: Visitable is either Ready or DeferredDecompression,
                    //       Invalid, Unknown, and Skip are not Visitable
                    if (parsed_block.IsVisitable())
                    {
                        std::visit(process_visitor, parsed_block.GetArgs());
                        success = process_visitor.IsSuccess();
                        if (success)
                        {
                            parsed_block.Decompress(block_parser); // Safe without testing block state.
                            std::visit(dispatch_visitor, parsed_block.GetArgs());
                        }
                    }
                    else if (parsed_block.IsUnknown())
                    {
                        // Unrecognized block type.
                        GFXRECON_LOG_WARNING("Skipping unrecognized file block with type %u (frame %u block %" PRIu64
                                             ")",
                                             block_buffer.Header().type,
                                             current_frame_number_,
                                             block_index_);
                        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_buffer.Header().size);
                        // Replacing the result of SkipBytes. The BlockBuffer read succeeded, so skip would.
                        success = true;
                    }

                    if (process_visitor.IsFrameDelimiter())
                    {
                        // The ProcessVisitor (pre-dispatch) is not the right place to update the frame state, so do it
                        // here
                        UpdateEndFrameState();
                        break;
                    }
                }
            }
            else
            {
                success = HandleBlockEof("read", true);
            }
        }
        ++block_index_;
        DecrementRemainingCommands();
    }

    DecrementRemainingCommands();
    return success;
}

// While ReadBlockBuffer both reads the block header and the block body, checks for
// the correct sizing of the block payload are done by the caller
bool FileProcessor::ReadBlockBuffer(BlockParser& parser, BlockBuffer& block_buffer)
{
    bool           success = true;
    BlockReadError status  = parser.ReadBlockBuffer(GetCurrentFile().active_file, block_buffer);
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

// Preloading overloads this to get preloaded blocks
bool FileProcessor::GetBlockBuffer(BlockParser& parser, BlockBuffer& block_buffer)
{
    return ReadBlockBuffer(parser, block_buffer);
}

bool FileProcessor::PeekBytes(void* buffer, size_t buffer_size)
{
    // File entry is non-const to allow read bytes to be non-const (i.e. potentially reflect a stateful operation)
    // without forcing use of mutability
    const auto& active_file = file_stack_.back().active_file;
    assert(active_file);

    return active_file->PeekBytes(buffer, buffer_size);
}

bool FileProcessor::PeekBlockHeader(format::BlockHeader* block_header)
{
    assert(block_header != nullptr);

    bool success = false;

    if (PeekBytes(block_header, sizeof(*block_header)))
    {
        success = true;
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

util::DataSpan FileProcessor::ReadSpan(size_t bytes)
{
    // File entry is non-const to allow read bytes to be non-const (i.e. potentially reflect a stateful operation)
    // without forcing use of mutability
    auto& active_file = file_stack_.back().active_file;
    GFXRECON_ASSERT(active_file);

    util::DataSpan read_span = active_file->ReadSpan(bytes);
    if (!read_span.empty())
    {
        // Note: Should this += read_span.size() instead... though current behavior of ReadSpan doesn't support partial
        // reads
        bytes_read_ += bytes;
    }
    return read_span;
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
            GFXRECON_LOG_ERROR("Failed to open file %s", filename.c_str());
            error_state_ = kErrorOpeningFile;
            return false;
        }

        // It's possible we'll want to use the input streams more than once, (kExecuteBlocksFromFile, usage often
        // does in test cases), so we'll stash off the stream's shared pointer to a cache
        stream_cache_.Insert(active_file);
    }

    // Now that we have a new stream or old, push it on the stack
    file_stack_.emplace_back(std::move(active_file), execute_till_eof);
    error_state_ = kErrorNone;
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

void FileProcessor::HandleBlockReadError(BlockReadError error_code, const char* error_message)
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
        GFXRECON_LOG_ERROR("%s (frame %u block %" PRIu64 ")", error_message, current_frame_number_, block_index_);
        error_state_ = error_code;
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
        current_frame_number_               = kFirstFrame;
        GFXRECON_LOG_WARNING("Explicit frame markers found in file format (0.0) file w/ gfxrecon-version < (1.0.1). "
                             "Patch input file format with 'gfxrecon-file-version-patch'");
    }

    // Make sure to increment the frame number on the way out.
    ++current_frame_number_;
    ++block_index_;
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
                    (current_frame_number_ == (end_frame.frame_number - first_frame_)));
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

void FileProcessor::ProcessStateEndMarker(const StateEndMarkerArgs& state_end)
{
    GFXRECON_LOG_INFO("Finished loading state for captured frame %" PRId64, state_end.frame_number);
    first_frame_                   = state_end.frame_number;
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
            GFXRECON_ASSERT(current_frame_number_ == kFirstFrame);
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
        ((block_index_from_ < 0 || block_index_to_ < 0) || (block_index_from_ <= static_cast<int64_t>(block_index_) &&
                                                            block_index_to_ >= static_cast<int64_t>(block_index_))))
    {
        GFXRECON_LOG_INFO(
            "block info: index: %" PRIu64 ", current frame: %" PRIu64 "", block_index_, current_frame_number_);
    }
}

bool FileProcessor::HandleBlockEof(const char* operation, bool report_frame_and_block)
{

    bool success = false;
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
                               current_frame_number_,
                               block_index_);
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to %s block header", operation);
        }

        error_state_ = kErrorReadingBlockHeader;
    }
    else
    {
        GFXRECON_ASSERT(!file_stack_.empty());

        ActiveFileContext& current_file = GetCurrentFile();
        if (current_file.execute_till_eof)
        {
            file_stack_.pop_back();
            success = !file_stack_.empty();
        }
    }
    return success;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
