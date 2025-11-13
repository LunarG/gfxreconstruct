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

#include "decode/decode_allocator.h"
#include "format/format.h"
#include "format/format_util.h"
#include "util/compressor.h"
#include "util/file_path.h"
#include "util/logging.h"
#include "util/platform.h"

#include <cassert>
#include <cstdint>
#include <memory>
#include <numeric>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

bool BlockBuffer::ReadBytes(void* buffer, size_t buffer_size)
{
    bool success = ReadBytesAt(buffer, buffer_size, read_pos_);
    if (success)
    {
        read_pos_ += buffer_size;
    }
    return success;
}

bool BlockBuffer::ReadBytesAt(void* buffer, size_t buffer_size, size_t at) const
{
    if (IsAvailableAt(buffer_size, at))
    {
        memcpy(buffer, block_span_.data() + at, buffer_size);
        return true;
    }
    return false;
}

BlockBuffer::BlockSpan BlockBuffer::ReadSpan(size_t buffer_size)
{
    BlockSpan read_span = ReadSpanAt(buffer_size, read_pos_);
    if (!read_span.empty())
    {
        read_pos_ += read_span.size();
    }
    return read_span;
}

BlockBuffer::BlockSpan BlockBuffer::ReadSpanAt(size_t buffer_size, size_t at)
{
    if (IsAvailableAt(buffer_size, at))
    {
        // Create a borrowed data span from our private buffer
        return BlockSpan(block_span_.data() + at, buffer_size);
    }
    return BlockSpan();
}

// Create a block buffer from a block data span
// Reading the block header contents from the given span
BlockBuffer::BlockBuffer(util::DataSpan&& block_span) : read_pos_{ 0 }, block_span_(std::move(block_span))
{
    InitBlockHeaderFromSpan();
}

void BlockBuffer::InitBlockHeaderFromSpan()
{
    GFXRECON_ASSERT(block_span_.IsValid())
    const bool success = ReadBytes(&header_, sizeof(format::BlockHeader));

    // Bad or incorrect block data should never be present
    const bool correct = success && block_span_.Size() == header_.size + sizeof(header_);
    assert(correct);

    // Only report failure to read header, span size validity checks are done later in calling code
    if (!success)
    {
        // Tag block buffer as invalid
        block_span_.Reset();
    }
}

void BlockBuffer::Reset(util::DataSpan&& block_span)
{
    read_pos_   = 0;
    block_span_ = std::move(block_span);
    InitBlockHeaderFromSpan();
}

bool BlockBuffer::IsFrameDelimiter(const FileProcessor& file_processor) const
{
    if (!IsValid())
    {
        return false;
    }

    format::BlockType base_type = format::RemoveCompressedBlockBit(header_.type);
    switch (base_type)
    {
        case format::BlockType::kFrameMarkerBlock:
            format::MarkerType marker_type;
            if (ReadAt<format::MarkerType>(marker_type, sizeof(format::BlockHeader)))
            {
                return file_processor.IsFrameDelimiter(base_type, marker_type);
            }
            break;
        case format::BlockType::kFunctionCallBlock:
        case format::BlockType::kMethodCallBlock:
            format::ApiCallId call_id;
            if (ReadAt<format::ApiCallId>(call_id, sizeof(format::BlockHeader)))
            {
                return file_processor.IsFrameDelimiter(call_id);
            }
            break;

        case format::BlockType::kUnknownBlock:
        case format::BlockType::kStateMarkerBlock:
        case format::BlockType::kMetaDataBlock:
        case format::BlockType::kCompressedMetaDataBlock:
        case format::BlockType::kCompressedFunctionCallBlock:
        case format::BlockType::kCompressedMethodCallBlock:
        case format::BlockType::kAnnotation:
            break;
    }
    return false;
}

bool BlockBuffer::SeekForward(size_t size)
{
    if (IsAvailable(size))
    {
        read_pos_ += size;
        return true;
    }
    return false;
}

bool BlockBuffer::SeekTo(size_t location)
{
    if (location <= Size())
    {
        read_pos_ = location;
        return true;
    }
    return false;
}

// TODO GH #1195: frame numbering should be 1-based.
const uint32_t kFirstFrame = 0;

FileProcessor::FileProcessor() :
    current_frame_number_(kFirstFrame), error_state_(kErrorInvalidFileDescriptor), bytes_read_(0),
    annotation_handler_(nullptr), compressor_(nullptr), block_index_(0), block_limit_(0),
    pending_capture_uses_frame_markers_(false), capture_uses_frame_markers_(false), first_frame_(kFirstFrame + 1),
    loading_trimmed_capture_state_(false), pool_(util::HeapBufferPool::Create())
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
        int completed_decoders = 0;

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
    bool               success = false;
    file_header_               = format::FileHeader();

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
    BlockBuffer         block_buffer;
    bool                success = true;

    BlockParser block_parser(*this, pool_, compressor_);

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
                const format::BlockType base_type = format::RemoveCompressedBlockBit(block_buffer.Header().type);
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

                    ProcessVisitor process_visitor(*this);
                    // NOTE: We don't support delayed decompression in these visitors at this point,
                    //       but the IsReady condition should be updated when support is added for
                    //       deferred decomprssion
                    if (parsed_block.IsReady())
                    {
                        parsed_block.Visit(process_visitor);
                        success = process_visitor.IsSuccess();
                        if (success)
                        {
                            DispatchVisitor dispatch_visitor(decoders_, annotation_handler_);
                            parsed_block.Visit(dispatch_visitor);
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
    bool success = parser.ReadBlockBuffer(GetCurrentFile().active_file, block_buffer);
    if (success)
    {
        bytes_read_ += block_buffer.Size();
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockData, "Failed to read block body data");
    }
    return success;
}

// Parse the block header and load the whole block into a block buffer
bool BlockParser::ReadBlockBuffer(FileInputStreamPtr& input_stream, BlockBuffer& block_buffer)
{
    using BlockSizeType = decltype(format::BlockHeader::size);
    BlockSizeType block_size;
    bool          success = input_stream->PeekBytes(&block_size, sizeof(block_size));
    if (success)
    {
        // NOTE: If BlockSkippingFileProcessor preformance is significantly harmed we could defer the data span read
        // here For 32bit size_t is << BlockSizeType ... but expecting support for > 4GB blocks on 32 bit platforms
        // isn't reasonable
        constexpr size_t        size_t_max        = std::numeric_limits<size_t>::max();
        constexpr BlockSizeType block_size_max    = std::numeric_limits<BlockSizeType>::max();
        constexpr bool          small_size        = size_t_max < std::numeric_limits<BlockSizeType>::max();
        constexpr size_t        block_header_size = sizeof(format::BlockHeader);

        GFXRECON_ASSERT(block_size <= (block_size_max - BlockSizeType(block_header_size)));
        const BlockSizeType total_block_size = block_size + sizeof(format::BlockHeader);
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, total_block_size);

        if constexpr (small_size)
        {
            if (total_block_size > size_t_max)
            {
                block_buffer.Reset();
                // This is a fatal error (caller will catch). SkipBytes takes size_t and fseek takes *long*,
                // which means we can't even skip this block on all 32 bit systems
                return false;
            }
        }
        // Note this leave the BlockBuffer read position at the first byte following the header.
        util::DataSpan block_span = input_stream->ReadSpan(static_cast<size_t>(total_block_size));
        success                   = block_span.IsValid();
        if (success)
        {
            block_buffer.Reset(std::move(block_span));
        }
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

BlockBuffer::BlockSpan FileProcessor::ReadParameterBuffer(BlockBuffer& block_buffer, size_t buffer_size)
{
    return block_buffer.ReadSpan(buffer_size);
}

BlockBuffer::BlockSpan FileProcessor::ReadCompressedParameterBuffer(BlockBuffer& block_buffer,
                                                                    size_t       compressed_buffer_size,
                                                                    size_t       expected_uncompressed_size)
{
    // This should only be null if initialization failed.
    GFXRECON_ASSERT(compressor_ != nullptr);

    BlockBuffer::BlockSpan compressed_span = block_buffer.ReadSpan(compressed_buffer_size);
    if (!compressed_span.empty())
    {
        // Resize the buffer
        if (uncompressed_buffer_.size() < expected_uncompressed_size)
        {
            uncompressed_buffer_.resize(expected_uncompressed_size);
        }

        size_t uncompressed_size = compressor_->Decompress(compressed_buffer_size,
                                                           reinterpret_cast<const uint8_t*>(compressed_span.data()),
                                                           expected_uncompressed_size,
                                                           uncompressed_buffer_.data());
        if ((0 < uncompressed_size) && (uncompressed_size == expected_uncompressed_size))
        {
            return BlockBuffer::BlockSpan(reinterpret_cast<const std::byte*>(uncompressed_buffer_.data()),
                                          uncompressed_size);
        }
    }
    return BlockBuffer::BlockSpan();
}

void BlockParser::HandleBlockReadError(BlockReadError error_code, const char* error_message)
{
    err_handler_.HandleBlockReadError(error_code, error_message);
}

BlockBuffer::BlockSpan BlockParser::ReadParameterBuffer(BlockBuffer& block_buffer, size_t buffer_size)
{
    return block_buffer.ReadSpan(buffer_size);
}

BlockBuffer::BlockSpan BlockParser::ReadCompressedParameterBuffer(BlockBuffer&       block_buffer,
                                                                  size_t             compressed_buffer_size,
                                                                  size_t             expanded_size,
                                                                  UncompressedStore& uncompressed_store)
{
    // This should only be null if initialization failed.
    GFXRECON_ASSERT(compressor_ != nullptr);

    BlockBuffer::BlockSpan compressed_span = block_buffer.ReadSpan(compressed_buffer_size);
    if (!compressed_span.empty())
    {
        // Resize the buffer
        auto uncompressed_buffer = pool_->Acquire(expanded_size);

        size_t uncompressed_size = compressor_->Decompress(compressed_buffer_size,
                                                           reinterpret_cast<const uint8_t*>(compressed_span.data()),
                                                           expanded_size,
                                                           uncompressed_buffer.GetAs<uint8_t>());
        if ((0 < uncompressed_size) && (uncompressed_size == expanded_size))
        {
            uncompressed_store = std::move(uncompressed_buffer);
            return BlockBuffer::BlockSpan(uncompressed_store.data(), uncompressed_size);
        }
    }
    // need to export the owning pool entry too...
    return BlockBuffer::BlockSpan();
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

void FileProcessor::HandleBlockReadError(Error error_code, const char* error_message)
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
        format::GfxrVersion version = format::ParseVersionFromOperations(annotation.data.c_str());
        if (version.SupportsFrameMarkers())
        {
            GFXRECON_ASSERT(current_frame_number_ == kFirstFrame);
            capture_uses_frame_markers_  = true;
            file_supports_frame_markers_ = true;
        }
    }
}

ParsedBlock BlockParser::ParseBlock(BlockBuffer& block_buffer)
{
    // Note that header parsing has been done by the BlockParser before this call is made.
    GFXRECON_ASSERT(block_buffer.ReadPos() == sizeof(format::BlockHeader));
    const format::BlockHeader& block_header = block_buffer.Header();
    format::BlockType          base_type    = format::RemoveCompressedBlockBit(block_header.type);

    switch (base_type)
    {
        case format::kFunctionCallBlock:
            return ParseFunctionCall(block_buffer);
        case format::kMethodCallBlock:
            return ParseMethodCall(block_buffer);
        case format::kMetaDataBlock:
            return ParseMetaData(block_buffer);
        case format::kFrameMarkerBlock:
            return ParseFrameMarker(block_buffer);
        case format::kStateMarkerBlock:
            return ParseStateMarker(block_buffer);
        case format::kAnnotation:
            return ParseAnnotation(block_buffer);
        case format::kUnknownBlock:
        default:
            return ParsedBlock(ParsedBlock::EmptyBlockTag(), ParsedBlock::BlockState::kUnknown);
    }
}

ParsedBlock BlockParser::ParseFunctionCall(BlockBuffer& block_buffer)
{
    // The caller is responsible for reading the block and parsing the header
    GFXRECON_ASSERT(block_buffer.ReadPos() == sizeof(format::BlockHeader));
    const format::BlockHeader& block_header = block_buffer.Header();
    format::ApiCallId          api_call_id  = format::ApiCallId::ApiCall_Unknown;

    uint64_t    uncompressed_size     = 0;
    ApiCallInfo call_info{ GetBlockIndex() };

    bool success = block_buffer.Read(api_call_id);
    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
    size_t parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(api_call_id);
    success                      = success && block_buffer.Read(call_info.thread_id);

    if (success)
    {
        parameter_buffer_size -= sizeof(call_info.thread_id);

        BlockBuffer::BlockSpan parameter_data;

        // Optional backing store for uncompressed parameter_data, moved to ParsedBlock
        UncompressedStore uncompressed_store;

        if (format::IsBlockCompressed(block_header.type))
        {
            parameter_buffer_size -= sizeof(uncompressed_size);
            success = block_buffer.Read(uncompressed_size);

            if (success)
            {
                // NOTE: Given this is true, we can stop tracking parameter_buffer_size independently from
                // BlockBuffer::Remainder.
                GFXRECON_ASSERT(block_buffer.Remainder() == parameter_buffer_size);

                GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, uncompressed_size);
                const size_t data_size = static_cast<size_t>(uncompressed_size);
                parameter_data =
                    ReadCompressedParameterBuffer(block_buffer, parameter_buffer_size, data_size, uncompressed_store);
                success = parameter_data.size() == data_size;

                if (success)
                {
                    assert(parameter_data.size() == data_size);
                    parameter_buffer_size = data_size;
                }
                else
                {
                    HandleBlockReadError(kErrorReadingCompressedBlockData,
                                         "Failed to read compressed function call block data");
                }
            }
            else
            {
                HandleBlockReadError(kErrorReadingCompressedBlockHeader,
                                     "Failed to read compressed function call block header");
            }
        }
        else
        {
            parameter_data = ReadParameterBuffer(block_buffer, parameter_buffer_size);
            success        = parameter_data.size() == parameter_buffer_size;

            if (!success)
            {
                HandleBlockReadError(kErrorReadingBlockData, "Failed to read function call block data");
            }
        }

        if (success)
        {
            return ParsedBlock(
                block_buffer.ReleaseData(),
                FunctionCallArgs{ api_call_id, call_info, parameter_data.GetDataAs<uint8_t>(), parameter_buffer_size },
                std::move(uncompressed_store));
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read function call block header");
    }

    return ParsedBlock(ParsedBlock::EmptyBlockTag(), ParsedBlock::BlockState::kInvalid);
}

ParsedBlock BlockParser::ParseMethodCall(BlockBuffer& block_buffer)
{
    // The caller is responsible for reading the block and parsing the header
    GFXRECON_ASSERT(block_buffer.ReadPos() == sizeof(format::BlockHeader));
    const format::BlockHeader& block_header = block_buffer.Header();
    format::ApiCallId          call_id      = format::ApiCallId::ApiCall_Unknown;
    bool                       success      = block_buffer.Read(call_id);

    size_t           parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(call_id);
    uint64_t         uncompressed_size     = 0;
    format::HandleId object_id             = 0;
    ApiCallInfo      call_info{ GetBlockIndex() };

    success = success && block_buffer.Read(object_id);
    success = success && block_buffer.Read(call_info.thread_id);

    if (success)
    {
        parameter_buffer_size -= (sizeof(object_id) + sizeof(call_info.thread_id));

        // Optional backing store for uncompressed parameter_data, moved to ParsedBlock
        UncompressedStore uncompressed_store;

        BlockBuffer::BlockSpan parameter_data;
        if (format::IsBlockCompressed(block_header.type))
        {
            parameter_buffer_size -= sizeof(uncompressed_size);
            success = block_buffer.Read(uncompressed_size);

            if (success)
            {
                GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, uncompressed_size);
                const size_t data_size = static_cast<size_t>(uncompressed_size);
                parameter_data =
                    ReadCompressedParameterBuffer(block_buffer, parameter_buffer_size, data_size, uncompressed_store);
                success = parameter_data.size() == data_size;

                if (success)
                {
                    assert(parameter_data.size() == uncompressed_size);
                    parameter_buffer_size = static_cast<size_t>(uncompressed_size);
                }
                else
                {
                    HandleBlockReadError(kErrorReadingCompressedBlockData,
                                         "Failed to read compressed function call block data");
                }
            }
            else
            {
                HandleBlockReadError(kErrorReadingCompressedBlockHeader,
                                     "Failed to read compressed function call block header");
            }
        }
        else
        {
            parameter_data = ReadParameterBuffer(block_buffer, parameter_buffer_size);
            success        = parameter_data.size() == parameter_buffer_size;

            if (!success)
            {
                HandleBlockReadError(kErrorReadingBlockData, "Failed to read function call block data");
            }
        }

        if (success)
        {
            return ParsedBlock(
                std::move(block_buffer.ReleaseData()),
                MethodCallArgs{
                    call_id, object_id, call_info, parameter_data.GetDataAs<const uint8_t>(), parameter_buffer_size },
                std::move(uncompressed_store));
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read function call block header");
    }

    return ParsedBlock(ParsedBlock::EmptyBlockTag(), ParsedBlock::BlockState::kInvalid);
}

ParsedBlock BlockParser::ParseMetaData(BlockBuffer& block_buffer)
{
    // The caller is responsible for reading the block and parsing the header
    GFXRECON_ASSERT(block_buffer.ReadPos() == sizeof(format::BlockHeader));
    const format::BlockHeader& block_header = block_buffer.Header();
    format::ApiCallId          call_id      = format::ApiCallId::ApiCall_Unknown;
    format::MetaDataId         meta_data_id;
    bool                       success = block_buffer.Read(meta_data_id);

    if (!success)
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read function call block header");
        return ParsedBlock(ParsedBlock::EmptyBlockTag(), ParsedBlock::BlockState::kInvalid);
    }

    // Optional backing store for the various uncompressed metadata contents
    UncompressedStore uncompressed_store;

    format::MetaDataType meta_data_type = format::GetMetaDataType(meta_data_id);

    if (meta_data_type == format::MetaDataType::kFillMemoryCommand)
    {
        format::FillMemoryCommandHeader header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.memory_id);
        success = success && block_buffer.Read(header.memory_offset);
        success = success && block_buffer.Read(header.memory_size);

        if (success)
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, header.memory_size);
            const size_t memory_size = static_cast<size_t>(header.memory_size);

            BlockBuffer::BlockSpan parameter_data;
            if (format::IsBlockCompressed(block_header.type))
            {
                size_t uncompressed_size = 0;
                size_t compressed_size   = static_cast<size_t>(block_header.size) - sizeof(meta_data_id) -
                                         sizeof(header.thread_id) - sizeof(header.memory_id) -
                                         sizeof(header.memory_offset) - sizeof(header.memory_size);

                parameter_data =
                    ReadCompressedParameterBuffer(block_buffer, compressed_size, memory_size, uncompressed_store);
            }
            else
            {
                parameter_data = ReadParameterBuffer(block_buffer, memory_size);
            }
            success = parameter_data.size() == memory_size;

            if (success)
            {
                return ParsedBlock(std::move(block_buffer.ReleaseData()),
                                   FillMemoryArgs{ meta_data_id,
                                                   header.thread_id,
                                                   header.memory_id,
                                                   header.memory_offset,
                                                   header.memory_size,
                                                   parameter_data.GetDataAs<uint8_t>() },
                                   std::move(uncompressed_store));
            }
            else
            {
                if (format::IsBlockCompressed(block_header.type))
                {
                    HandleBlockReadError(kErrorReadingCompressedBlockData,
                                         "Failed to read fill memory meta-data block");
                }
                else
                {
                    HandleBlockReadError(kErrorReadingBlockData, "Failed to read fill memory meta-data block");
                }
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read fill memory meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kFillMemoryResourceValueCommand)
    {
        format::FillMemoryResourceValueCommandHeader header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.resource_value_count);

        if (success)
        {
            // Uncompressed parameter_data size is computed and not encoded.
            uint64_t parameter_data_size =
                header.resource_value_count * (sizeof(format::ResourceValueType) + sizeof(uint64_t));
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, parameter_data_size);
            const size_t data_size = static_cast<size_t>(parameter_data_size);

            BlockBuffer::BlockSpan parameter_data;
            if (format::IsBlockCompressed(block_header.type))
            {
                GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
                size_t compressed_size   = static_cast<size_t>(block_header.size) - sizeof(meta_data_id) -
                                         sizeof(header.thread_id) - sizeof(header.resource_value_count);
                parameter_data =
                    ReadCompressedParameterBuffer(block_buffer, compressed_size, data_size, uncompressed_store);
            }
            else
            {
                parameter_data = ReadParameterBuffer(block_buffer, data_size);
            }
            success = parameter_data.size() == data_size;

            if (success)
            {
                return ParsedBlock(
                    std::move(block_buffer.ReleaseData()),
                    FillMemoryResourceValueArgs{ meta_data_id, header, parameter_data.GetDataAs<uint8_t>() },
                    std::move(uncompressed_store));
            }
            else
            {
                HandleBlockReadError(kErrorReadingBlockData,
                                     "Failed to read fill memory resource value meta-data block");
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read fill memory resource value meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kResizeWindowCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::ResizeWindowCommand command;

        success = block_buffer.Read(command.thread_id);
        success = success && block_buffer.Read(command.surface_id);
        success = success && block_buffer.Read(command.width);
        success = success && block_buffer.Read(command.height);

        if (success)
        {
            return ParsedBlock(
                std::move(block_buffer.ReleaseData()),
                ResizeWindowArgs{ meta_data_id, command.thread_id, command.surface_id, command.width, command.height },
                std::move(uncompressed_store));
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read resize window meta-data block");
        }
    }
    else if (meta_data_type == format::MetaDataType::kResizeWindowCommand2)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::ResizeWindowCommand2 command;

        success = block_buffer.Read(command.thread_id);
        success = success && block_buffer.Read(command.surface_id);
        success = success && block_buffer.Read(command.width);
        success = success && block_buffer.Read(command.height);
        success = success && block_buffer.Read(command.pre_transform);

        if (success)
        {
            return ParsedBlock(std::move(block_buffer.ReleaseData()),
                               ResizeWindow2Args{ meta_data_id,
                                                  command.thread_id,
                                                  command.surface_id,
                                                  command.width,
                                                  command.height,
                                                  command.pre_transform },
                               std::move(uncompressed_store));
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read resize window 2 meta-data block");
        }
    }
    else if (meta_data_type == format::MetaDataType::kExeFileInfoCommand)
    {
        format::ExeFileInfoBlock header;
        success = block_buffer.Read(header.thread_id);

        success = success && block_buffer.ReadBytes(&header.info_record.ProductVersion,
                                                    gfxrecon::util::filepath::kMaxFilePropertySize);
        success = success && block_buffer.ReadBytes(&header.info_record.FileVersion,
                                                    gfxrecon::util::filepath::kMaxFilePropertySize);
        success = success && block_buffer.ReadBytes(&header.info_record.AppVersion,
                                                    sizeof(uint32_t) * gfxrecon::util::filepath::kFileVersionSize);
        success = success &&
                  block_buffer.ReadBytes(&header.info_record.AppName, gfxrecon::util::filepath::kMaxFilePropertySize);
        success = success && block_buffer.ReadBytes(&header.info_record.CompanyName,
                                                    gfxrecon::util::filepath::kMaxFilePropertySize);
        success = success && block_buffer.ReadBytes(&header.info_record.FileDescription,
                                                    gfxrecon::util::filepath::kMaxFilePropertySize);
        success = success && block_buffer.ReadBytes(&header.info_record.InternalName,
                                                    gfxrecon::util::filepath::kMaxFilePropertySize);
        success = success && block_buffer.ReadBytes(&header.info_record.OriginalFilename,
                                                    gfxrecon::util::filepath::kMaxFilePropertySize);
        success = success && block_buffer.ReadBytes(&header.info_record.ProductName,
                                                    gfxrecon::util::filepath::kMaxFilePropertySize);

        if (success)
        {
            return ParsedBlock(std::move(block_buffer.ReleaseData()),
                               ExeFileArgs{ meta_data_id, header.thread_id, header },
                               std::move(uncompressed_store));
        }
    }
    else if (meta_data_type == format::MetaDataType::kDriverInfoCommand)
    {
        format::DriverInfoBlock header;
        success = block_buffer.Read(header.thread_id);

        success =
            success && block_buffer.ReadBytes(&header.driver_record, gfxrecon::util::filepath::kMaxDriverInfoSize);

        if (success)
        {
            return ParsedBlock(std::move(block_buffer.ReleaseData()),
                               DriverArgs{ meta_data_id, header.thread_id, header },
                               std::move(uncompressed_store));
        }
    }
    else if (meta_data_type == format::MetaDataType::kDisplayMessageCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::DisplayMessageCommandHeader header;

        success = block_buffer.Read(header.thread_id);

        if (success)
        {
            uint64_t message_size = block_header.size - sizeof(meta_data_id) - sizeof(header.thread_id);

            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, message_size);
            const size_t           data_size      = static_cast<size_t>(message_size);
            BlockBuffer::BlockSpan parameter_data = ReadParameterBuffer(block_buffer, data_size);
            success                               = parameter_data.size() == data_size;

            if (success)
            {
                const char* message_start = parameter_data.GetDataAs<char>();
                std::string message(message_start, std::next(message_start, static_cast<size_t>(message_size)));

                return ParsedBlock(std::move(block_buffer.ReleaseData()),
                                   DisplayMessageArgs{ meta_data_id, header.thread_id, message },
                                   std::move(uncompressed_store));
            }
            else
            {
                HandleBlockReadError(kErrorReadingBlockData, "Failed to read display message meta-data block");
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read display message meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kCreateHardwareBufferCommand_deprecated)
    {
        format::CreateHardwareBufferCommandHeader_deprecated header;

        GFXRECON_LOG_WARNING_ONCE(
            "This capture contains a deprecated metacommand to create an AHardwareBuffer.  While still supported, this "
            "metacommand may not correctly represent some state of the captured AHardwareBuffer.");

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.memory_id);
        success = success && block_buffer.Read(header.buffer_id);
        success = success && block_buffer.Read(header.format);
        success = success && block_buffer.Read(header.width);
        success = success && block_buffer.Read(header.height);
        success = success && block_buffer.Read(header.stride);
        success = success && block_buffer.Read(header.usage);
        success = success && block_buffer.Read(header.layers);
        success = success && block_buffer.Read(header.planes);

        if (success)
        {
            std::vector<format::HardwareBufferPlaneInfo> entries;

            for (uint64_t i = 0; i < header.planes; ++i)
            {
                format::HardwareBufferPlaneInfo entry;

                if (!block_buffer.Read(entry))
                {
                    success = false;
                    break;
                }

                entries.emplace_back(std::move(entry));
            }

            if (success)
            {
                return ParsedBlock(std::move(block_buffer.ReleaseData()),
                                   CreateHardwareBufferArgs{ meta_data_id,
                                                             header.thread_id,
                                                             0u,
                                                             header.memory_id,
                                                             header.buffer_id,
                                                             header.format,
                                                             header.width,
                                                             header.height,
                                                             header.stride,
                                                             header.usage,
                                                             header.layers,
                                                             entries },
                                   std::move(uncompressed_store));
            }
            else
            {
                if (format::IsBlockCompressed(block_header.type))
                {
                    HandleBlockReadError(kErrorReadingCompressedBlockData,
                                         "Failed to read create hardware buffer meta-data block");
                }
                else
                {
                    HandleBlockReadError(kErrorReadingBlockData,
                                         "Failed to read create hardware buffer meta-data block");
                }
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read create hardware buffer meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kCreateHardwareBufferCommand_deprecated2)
    {
        format::CreateHardwareBufferCommandHeader_deprecated2 header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.memory_id);
        success = success && block_buffer.Read(header.buffer_id);
        success = success && block_buffer.Read(header.format);
        success = success && block_buffer.Read(header.width);
        success = success && block_buffer.Read(header.height);
        success = success && block_buffer.Read(header.stride);
        success = success && block_buffer.Read(header.usage);
        success = success && block_buffer.Read(header.layers);
        success = success && block_buffer.Read(header.planes);

        if (success)
        {
            std::vector<format::HardwareBufferPlaneInfo> entries;

            for (uint64_t i = 0; i < header.planes; ++i)
            {
                format::HardwareBufferPlaneInfo entry;

                if (!block_buffer.Read(entry))
                {
                    success = false;
                    break;
                }

                entries.emplace_back(std::move(entry));
            }

            if (success)
            {
                return ParsedBlock(std::move(block_buffer.ReleaseData()),
                                   CreateHardwareBufferArgs{ meta_data_id,
                                                             header.thread_id,
                                                             0u,
                                                             header.memory_id,
                                                             header.buffer_id,
                                                             header.format,
                                                             header.width,
                                                             header.height,
                                                             header.stride,
                                                             header.usage,
                                                             header.layers,
                                                             entries },
                                   std::move(uncompressed_store));
            }
            else
            {
                if (format::IsBlockCompressed(block_header.type))
                {
                    HandleBlockReadError(kErrorReadingCompressedBlockData,
                                         "Failed to read create hardware buffer meta-data block");
                }
                else
                {
                    HandleBlockReadError(kErrorReadingBlockData,
                                         "Failed to read create hardware buffer meta-data block");
                }
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read create hardware buffer meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kCreateHardwareBufferCommand)
    {
        format::CreateHardwareBufferCommandHeader header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.device_id);
        success = success && block_buffer.Read(header.memory_id);
        success = success && block_buffer.Read(header.buffer_id);
        success = success && block_buffer.Read(header.format);
        success = success && block_buffer.Read(header.width);
        success = success && block_buffer.Read(header.height);
        success = success && block_buffer.Read(header.stride);
        success = success && block_buffer.Read(header.usage);
        success = success && block_buffer.Read(header.layers);
        success = success && block_buffer.Read(header.planes);

        if (success)
        {
            std::vector<format::HardwareBufferPlaneInfo> entries;

            for (uint64_t i = 0; i < header.planes; ++i)
            {
                format::HardwareBufferPlaneInfo entry;

                if (!block_buffer.Read(entry))
                {
                    success = false;
                    break;
                }

                entries.emplace_back(std::move(entry));
            }

            if (success)
            {
                return ParsedBlock(std::move(block_buffer.ReleaseData()),
                                   CreateHardwareBufferArgs{ meta_data_id,
                                                             header.thread_id,
                                                             header.device_id,
                                                             header.memory_id,
                                                             header.buffer_id,
                                                             header.format,
                                                             header.width,
                                                             header.height,
                                                             header.stride,
                                                             header.usage,
                                                             header.layers,
                                                             entries },
                                   std::move(uncompressed_store));
            }
            else
            {
                if (format::IsBlockCompressed(block_header.type))
                {
                    HandleBlockReadError(kErrorReadingCompressedBlockData,
                                         "Failed to read create hardware buffer meta-data block");
                }
                else
                {
                    HandleBlockReadError(kErrorReadingBlockData,
                                         "Failed to read create hardware buffer meta-data block");
                }
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read create hardware buffer meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kDestroyHardwareBufferCommand)
    {
        format::DestroyHardwareBufferCommand command;

        success = block_buffer.Read(command.thread_id);
        success = success && block_buffer.Read(command.buffer_id);

        if (success)
        {
            return ParsedBlock(std::move(block_buffer.ReleaseData()),
                               DestroyHardwareBufferArgs{ meta_data_id, command.thread_id, command.buffer_id },
                               std::move(uncompressed_store));
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read destroy hardware buffer meta-data block");
        }
    }
    else if (meta_data_type == format::MetaDataType::kCreateHeapAllocationCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::CreateHeapAllocationCommand header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.allocation_id);
        success = success && block_buffer.Read(header.allocation_size);

        if (success)
        {
            return ParsedBlock(std::move(block_buffer.ReleaseData()),
                               CreateHeapAllocationArgs{
                                   meta_data_id, header.thread_id, header.allocation_id, header.allocation_size },
                               std::move(uncompressed_store));
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read create heap allocation meta-data block");
        }
    }
    else if (meta_data_type == format::MetaDataType::kSetDevicePropertiesCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::SetDevicePropertiesCommand header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.physical_device_id);
        success = success && block_buffer.Read(header.api_version);
        success = success && block_buffer.Read(header.driver_version);
        success = success && block_buffer.Read(header.vendor_id);
        success = success && block_buffer.Read(header.device_id);
        success = success && block_buffer.Read(header.device_type);
        success = success && block_buffer.ReadBytes(&header.pipeline_cache_uuid, format::kUuidSize);
        success = success && block_buffer.Read(header.device_name_len);

        if (success)
        {
            char device_name[format::kMaxPhysicalDeviceNameSize];

            if (header.device_name_len < format::kMaxPhysicalDeviceNameSize)
            {
                success = success && block_buffer.ReadBytes(&device_name, header.device_name_len);
                device_name[header.device_name_len] = '\0';
            }

            if (success)
            {
                return ParsedBlock(std::move(block_buffer.ReleaseData()),
                                   SetDevicePropertiesArgs(meta_data_id,
                                                           header.thread_id,
                                                           header.physical_device_id,
                                                           header.api_version,
                                                           header.driver_version,
                                                           header.vendor_id,
                                                           header.device_id,
                                                           header.device_type,
                                                           header.pipeline_cache_uuid,
                                                           device_name),
                                   std::move(uncompressed_store));
            }
            else
            {
                HandleBlockReadError(kErrorReadingBlockData,
                                     "Failed to read set device memory properties meta-data block");
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read set device memory properties meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kSetDeviceMemoryPropertiesCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::SetDeviceMemoryPropertiesCommand header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.physical_device_id);
        success = success && block_buffer.Read(header.memory_type_count);
        success = success && block_buffer.Read(header.memory_heap_count);

        if (success)
        {
            std::vector<format::DeviceMemoryType> types;
            std::vector<format::DeviceMemoryHeap> heaps;

            for (uint32_t i = 0; i < header.memory_type_count; ++i)
            {
                format::DeviceMemoryType type;

                if (!block_buffer.Read(type))
                {
                    success = false;
                    break;
                }

                types.emplace_back(std::move(type));
            }

            for (uint32_t i = 0; i < header.memory_heap_count; ++i)
            {
                format::DeviceMemoryHeap heap;

                if (!block_buffer.Read(heap))
                {
                    success = false;
                    break;
                }

                heaps.emplace_back(std::move(heap));
            }

            if (success)
            {
                return ParsedBlock(std::move(block_buffer.ReleaseData()),
                                   SetDeviceMemoryPropertiesArgs{
                                       meta_data_id, header.thread_id, header.physical_device_id, types, heaps },
                                   std::move(uncompressed_store));
            }
            else
            {
                HandleBlockReadError(kErrorReadingBlockData,
                                     "Failed to read set device memory properties meta-data block");
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read set device memory properties meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kSetOpaqueAddressCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::SetOpaqueAddressCommand header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.device_id);
        success = success && block_buffer.Read(header.object_id);
        success = success && block_buffer.Read(header.address);

        if (success)
        {
            return ParsedBlock(std::move(block_buffer.ReleaseData()),
                               SetOpaqueAddressArgs{
                                   meta_data_id, header.thread_id, header.device_id, header.object_id, header.address },
                               std::move(uncompressed_store));
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read set opaque address meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kSetRayTracingShaderGroupHandlesCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::SetRayTracingShaderGroupHandlesCommandHeader header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.device_id);
        success = success && block_buffer.Read(header.pipeline_id);
        success = success && block_buffer.Read(header.data_size);

        // Read variable size shader group handle data into parameter_data.
        BlockBuffer::BlockSpan parameter_data;
        if (success)
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, header.data_size);
            size_t data_size = static_cast<size_t>(header.data_size);
            parameter_data   = ReadParameterBuffer(block_buffer, static_cast<size_t>(data_size));
            success          = parameter_data.size() == data_size;
        }

        if (success)
        {
            return ParsedBlock(std::move(block_buffer.ReleaseData()),
                               SetRayTracingShaderGroupHandlesArgs{ meta_data_id,
                                                                    header.thread_id,
                                                                    header.device_id,
                                                                    header.pipeline_id,
                                                                    static_cast<size_t>(header.data_size),
                                                                    parameter_data.GetDataAs<uint8_t>() },
                               std::move(uncompressed_store));
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read set ray tracing shader group handles meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kSetSwapchainImageStateCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::SetSwapchainImageStateCommandHeader header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.device_id);
        success = success && block_buffer.Read(header.swapchain_id);
        success = success && block_buffer.Read(header.last_presented_image);
        success = success && block_buffer.Read(header.image_info_count);

        if (success)
        {
            std::vector<format::SwapchainImageStateInfo> entries;

            for (uint32_t i = 0; i < header.image_info_count; ++i)
            {
                format::SwapchainImageStateInfo entry;

                if (!block_buffer.Read(entry))
                {
                    success = false;
                    break;
                }

                entries.emplace_back(std::move(entry));
            }

            if (success)
            {
                return ParsedBlock(std::move(block_buffer.ReleaseData()),
                                   SetSwapchainImageStateArgs{ meta_data_id,
                                                               header.thread_id,
                                                               header.device_id,
                                                               header.swapchain_id,
                                                               header.last_presented_image,
                                                               entries },
                                   std::move(uncompressed_store));
            }
            else
            {
                HandleBlockReadError(kErrorReadingBlockData,
                                     "Failed to read set swapchain image state meta-data block");
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read set swapchain image state meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kBeginResourceInitCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::BeginResourceInitCommand header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.device_id);
        success = success && block_buffer.Read(header.total_copy_size);
        success = success && block_buffer.Read(header.max_copy_size);

        if (success)
        {
            return ParsedBlock(
                std::move(block_buffer.ReleaseData()),
                BeginResourceInitArgs{
                    meta_data_id, header.thread_id, header.device_id, header.total_copy_size, header.max_copy_size },
                std::move(uncompressed_store));
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read begin resource init meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kEndResourceInitCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::EndResourceInitCommand header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.device_id);

        if (success)
        {
            return ParsedBlock(std::move(block_buffer.ReleaseData()),
                               EndResourceInitArgs{ meta_data_id, header.thread_id, header.device_id },
                               std::move(uncompressed_store));
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read end resource init meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kInitBufferCommand)
    {
        format::InitBufferCommandHeader header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.device_id);
        success = success && block_buffer.Read(header.buffer_id);
        success = success && block_buffer.Read(header.data_size);

        if (success)
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, header.data_size);
            const size_t data_size = static_cast<size_t>(header.data_size);

            BlockBuffer::BlockSpan parameter_data;
            if (format::IsBlockCompressed(block_header.type))
            {
                GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
                size_t compressed_size =
                    static_cast<size_t>(block_header.size) - (sizeof(header) - sizeof(header.meta_header.block_header));

                parameter_data =
                    ReadCompressedParameterBuffer(block_buffer, compressed_size, data_size, uncompressed_store);
            }
            else
            {
                parameter_data = ReadParameterBuffer(block_buffer, data_size);
            }
            success = parameter_data.size() == data_size;

            if (success)
            {
                return ParsedBlock(std::move(block_buffer.ReleaseData()),
                                   InitBufferArgs{ meta_data_id,
                                                   header.thread_id,
                                                   header.device_id,
                                                   header.buffer_id,
                                                   header.data_size,
                                                   parameter_data.GetDataAs<uint8_t>() },
                                   std::move(uncompressed_store));
            }
            else
            {
                if (format::IsBlockCompressed(block_header.type))
                {
                    HandleBlockReadError(kErrorReadingCompressedBlockData,
                                         "Failed to read init buffer data meta-data block");
                }
                else
                {
                    HandleBlockReadError(kErrorReadingBlockData, "Failed to read init buffer data meta-data block");
                }
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read init buffer data meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kInitImageCommand)
    {
        format::InitImageCommandHeader header;
        std::vector<uint64_t>          level_sizes;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.device_id);
        success = success && block_buffer.Read(header.image_id);
        success = success && block_buffer.Read(header.data_size);
        success = success && block_buffer.Read(header.aspect);
        success = success && block_buffer.Read(header.layout);
        success = success && block_buffer.Read(header.level_count);

        if (success && (header.level_count > 0))
        {
            level_sizes.resize(header.level_count);
            success =
                success && block_buffer.ReadBytes(level_sizes.data(), header.level_count * sizeof(level_sizes[0]));
        }

        BlockBuffer::BlockSpan parameter_data;
        if (success && (header.data_size > 0))
        {
            assert(header.data_size == std::accumulate(level_sizes.begin(), level_sizes.end(), 0ull));
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, header.data_size);
            const size_t data_size = static_cast<size_t>(header.data_size);

            if (format::IsBlockCompressed(block_header.type))
            {
                GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
                size_t compressed_size   = static_cast<size_t>(block_header.size) -
                                         (sizeof(header) - sizeof(header.meta_header.block_header)) -
                                         (level_sizes.size() * sizeof(level_sizes[0]));
                parameter_data =
                    ReadCompressedParameterBuffer(block_buffer, compressed_size, data_size, uncompressed_store);
            }
            else
            {
                parameter_data = ReadParameterBuffer(block_buffer, data_size);
            }
            success = parameter_data.size() == data_size;
        }

        if (success)
        {
            return ParsedBlock(std::move(block_buffer.ReleaseData()),
                               InitImageArgs{ meta_data_id,
                                              header.thread_id,
                                              header.device_id,
                                              header.image_id,
                                              header.data_size,
                                              header.aspect,
                                              header.layout,
                                              level_sizes,
                                              parameter_data.GetDataAs<uint8_t>() },
                               std::move(uncompressed_store));
        }
        else
        {
            if (format::IsBlockCompressed(block_header.type))
            {
                HandleBlockReadError(kErrorReadingCompressedBlockData,
                                     "Failed to read init image data meta-data block");
            }
            else
            {
                HandleBlockReadError(kErrorReadingBlockData, "Failed to read init image data meta-data block");
            }
        }
    }
    else if (meta_data_type == format::MetaDataType::kInitSubresourceCommand)
    {
        format::InitSubresourceCommandHeader header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.device_id);
        success = success && block_buffer.Read(header.resource_id);
        success = success && block_buffer.Read(header.subresource);
        success = success && block_buffer.Read(header.initial_state);
        success = success && block_buffer.Read(header.resource_state);
        success = success && block_buffer.Read(header.barrier_flags);
        success = success && block_buffer.Read(header.data_size);

        if (success)
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, header.data_size);
            const size_t data_size = static_cast<size_t>(header.data_size);

            BlockBuffer::BlockSpan parameter_data;
            if (format::IsBlockCompressed(block_header.type))
            {
                GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
                size_t compressed_size =
                    static_cast<size_t>(block_header.size) - (sizeof(header) - sizeof(header.meta_header.block_header));

                parameter_data =
                    ReadCompressedParameterBuffer(block_buffer, compressed_size, data_size, uncompressed_store);
            }
            else
            {
                parameter_data = ReadParameterBuffer(block_buffer, data_size);
            }
            success = parameter_data.size() == data_size;

            if (success)
            {
                return ParsedBlock(std::move(block_buffer.ReleaseData()),
                                   InitSubresourceArgs{ meta_data_id, header, parameter_data.GetDataAs<uint8_t>() },
                                   std::move(uncompressed_store));
            }
            else
            {
                if (format::IsBlockCompressed(block_header.type))
                {
                    HandleBlockReadError(kErrorReadingCompressedBlockData,
                                         "Failed to read init subresource data meta-data block");
                }
                else
                {
                    HandleBlockReadError(kErrorReadingBlockData,
                                         "Failed to read init subresource data meta-data block");
                }
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read init subresource data meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kInitDx12AccelerationStructureCommand)
    {
        // Parse command header.
        format::InitDx12AccelerationStructureCommandHeader header;
        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.dest_acceleration_structure_data);
        success = success && block_buffer.Read(header.copy_source_gpu_va);
        success = success && block_buffer.Read(header.copy_mode);
        success = success && block_buffer.Read(header.inputs_type);
        success = success && block_buffer.Read(header.inputs_flags);
        success = success && block_buffer.Read(header.inputs_num_instance_descs);
        success = success && block_buffer.Read(header.inputs_num_geometry_descs);
        success = success && block_buffer.Read(header.inputs_data_size);

        // Parse geometry descs.
        std::vector<format::InitDx12AccelerationStructureGeometryDesc> geom_descs;
        if (success)
        {
            for (uint32_t i = 0; i < header.inputs_num_geometry_descs; ++i)
            {
                format::InitDx12AccelerationStructureGeometryDesc geom_desc;
                success = success && block_buffer.Read(geom_desc.geometry_type);
                success = success && block_buffer.Read(geom_desc.geometry_flags);
                success = success && block_buffer.Read(geom_desc.aabbs_count);
                success = success && block_buffer.Read(geom_desc.aabbs_stride);
                success = success && block_buffer.Read(geom_desc.triangles_has_transform);
                success = success && block_buffer.Read(geom_desc.triangles_index_format);
                success = success && block_buffer.Read(geom_desc.triangles_vertex_format);
                success = success && block_buffer.Read(geom_desc.triangles_index_count);
                success = success && block_buffer.Read(geom_desc.triangles_vertex_count);
                success = success && block_buffer.Read(geom_desc.triangles_vertex_stride);
                geom_descs.push_back(geom_desc);
            }
        }

        BlockBuffer::BlockSpan parameter_data;
        if (success)
        {
            if (header.inputs_data_size > 0)
            {
                GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, header.inputs_data_size);
                const size_t data_size = static_cast<size_t>(header.inputs_data_size);

                if (format::IsBlockCompressed(block_header.type))
                {
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
                    size_t compressed_size =
                        static_cast<size_t>(block_header.size) -
                        (sizeof(header) - sizeof(header.meta_header.block_header)) -
                        (sizeof(format::InitDx12AccelerationStructureGeometryDesc) * header.inputs_num_geometry_descs);

                    parameter_data =
                        ReadCompressedParameterBuffer(block_buffer, compressed_size, data_size, uncompressed_store);
                }
                else
                {
                    parameter_data = ReadParameterBuffer(block_buffer, data_size);
                }
                success = parameter_data.size() == data_size;
            }

            if (success)
            {
                return ParsedBlock(std::move(block_buffer.ReleaseData()),
                                   InitDx12AccelerationStructureArgs{
                                       meta_data_id, header, geom_descs, parameter_data.GetDataAs<uint8_t>() },
                                   std::move(uncompressed_store));
            }
            else
            {
                HandleBlockReadError(kErrorReadingBlockData,
                                     "Failed to read init DX12 acceleration structure meta-data block");
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read init DX12 acceleration structure meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kDxgiAdapterInfoCommand)
    {
        format::DxgiAdapterInfoCommandHeader adapter_info_header;
        memset(&adapter_info_header, 0, sizeof(adapter_info_header));

        success = block_buffer.Read(adapter_info_header.thread_id);

        success = success && block_buffer.Read(adapter_info_header.adapter_desc.Description);
        success = success && block_buffer.Read(adapter_info_header.adapter_desc.VendorId);
        success = success && block_buffer.Read(adapter_info_header.adapter_desc.DeviceId);
        success = success && block_buffer.Read(adapter_info_header.adapter_desc.SubSysId);
        success = success && block_buffer.Read(adapter_info_header.adapter_desc.Revision);
        success = success && block_buffer.Read(adapter_info_header.adapter_desc.DedicatedVideoMemory);
        success = success && block_buffer.Read(adapter_info_header.adapter_desc.DedicatedSystemMemory);
        success = success && block_buffer.Read(adapter_info_header.adapter_desc.SharedSystemMemory);
        success = success && block_buffer.Read(adapter_info_header.adapter_desc.LuidLowPart);
        success = success && block_buffer.Read(adapter_info_header.adapter_desc.LuidHighPart);
        success = success && block_buffer.Read(adapter_info_header.adapter_desc.extra_info);

        if (success)
        {
            return ParsedBlock(std::move(block_buffer.ReleaseData()),
                               GetDxgiAdapterArgs{ meta_data_id, adapter_info_header },
                               std::move(uncompressed_store));
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read adapter info meta-data block");
        }
    }
    else if (meta_data_type == format::MetaDataType::kDx12RuntimeInfoCommand)
    {
        format::Dx12RuntimeInfoCommandHeader dx12_runtime_info_header;
        memset(&dx12_runtime_info_header, 0, sizeof(dx12_runtime_info_header));

        success = block_buffer.Read(dx12_runtime_info_header.thread_id);
        success = success && block_buffer.Read(dx12_runtime_info_header.runtime_info.version);
        success = success && block_buffer.Read(dx12_runtime_info_header.runtime_info.src);

        if (success)
        {
            return ParsedBlock(std::move(block_buffer.ReleaseData()),
                               GetDx12RuntimeArgs{ meta_data_id, dx12_runtime_info_header },
                               std::move(uncompressed_store));
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read runtime info meta-data block");
        }
    }
    else if (meta_data_type == format::MetaDataType::kParentToChildDependency)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::ParentToChildDependencyHeader header;
        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.dependency_type);
        success = success && block_buffer.Read(header.parent_id);
        success = success && block_buffer.Read(header.child_count);

        if (success)
        {
            switch (header.dependency_type)
            {
                case format::kAccelerationStructuresDependency:
                {
                    std::vector<format::HandleId> blases;
                    blases.resize(header.child_count);

                    for (uint32_t i = 0; i < header.child_count; ++i)
                    {
                        success = success && block_buffer.Read(blases[i]);
                    }

                    if (success)
                    {
                        return ParsedBlock(
                            std::move(block_buffer.ReleaseData()),
                            SetTlasToBlasDependencyArgs{ meta_data_id, header.parent_id, std::move(blases) },
                            std::move(uncompressed_store));
                    }
                    else
                    {
                        HandleBlockReadError(kErrorReadingBlockHeader,
                                             "Failed to read TLAS to BLAS dependency meta-data block header");
                    }
                }
                break;

                default:
                    success = false;
                    HandleBlockReadError(kErrorReadingBlockHeader,
                                         "Corrupted parent to child dependency meta-data block header");
                    break;
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read parent to child dependency meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kSetEnvironmentVariablesCommand)
    {
        format::SetEnvironmentVariablesCommand header;
        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.string_length);
        if (!success)
        {
            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read environment variable block header");
            return ParsedBlock(ParsedBlock::EmptyBlockTag(), ParsedBlock::BlockState::kInvalid);
        }

        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, header.string_length);
        const size_t           data_size      = static_cast<size_t>(header.string_length);
        BlockBuffer::BlockSpan parameter_data = ReadParameterBuffer(block_buffer, data_size);
        success                               = parameter_data.size() == data_size;

        if (!success)
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read environment variable block data");
            return ParsedBlock(ParsedBlock::EmptyBlockTag(), ParsedBlock::BlockState::kInvalid);
        }

        const char* env_string = parameter_data.GetDataAs<char>();
        return ParsedBlock(std::move(block_buffer.ReleaseData()),
                           SetEnvironmentVariablesArgs{ meta_data_id, header, env_string },
                           std::move(uncompressed_store));
    }
    else if (meta_data_type == format::MetaDataType::kVulkanBuildAccelerationStructuresCommand)
    {
        format::VulkanMetaBuildAccelerationStructuresHeader header{};
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
        const size_t           parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(meta_data_id);
        BlockBuffer::BlockSpan parameter_data        = ReadParameterBuffer(block_buffer, parameter_buffer_size);
        success                                      = parameter_data.size() == parameter_buffer_size;

        if (success)
        {
            return ParsedBlock(std::move(block_buffer.ReleaseData()),
                               VulkanAccelerationStructuresBuildMetaArgs{
                                   meta_data_id, parameter_data.GetDataAs<uint8_t>(), parameter_buffer_size },
                               std::move(uncompressed_store));
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read acceleration structure init meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kVulkanCopyAccelerationStructuresCommand)
    {
        format::VulkanCopyAccelerationStructuresCommandHeader header{};
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
        const size_t           parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(meta_data_id);
        BlockBuffer::BlockSpan parameter_data        = ReadParameterBuffer(block_buffer, parameter_buffer_size);
        success                                      = parameter_data.size() == parameter_buffer_size;

        if (success)
        {
            return ParsedBlock(std::move(block_buffer.ReleaseData()),
                               VulkanAccelerationStructuresCopyMetaArgs{
                                   meta_data_id, parameter_data.GetDataAs<uint8_t>(), parameter_buffer_size },
                               std::move(uncompressed_store));
        }
    }
    else if (meta_data_type == format::MetaDataType::kVulkanWriteAccelerationStructuresPropertiesCommand)
    {
        format::VulkanCopyAccelerationStructuresCommandHeader header{};
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
        const size_t           parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(meta_data_id);
        BlockBuffer::BlockSpan parameter_data        = ReadParameterBuffer(block_buffer, parameter_buffer_size);
        success                                      = parameter_data.size() == parameter_buffer_size;

        if (success)
        {
            return ParsedBlock(std::move(block_buffer.ReleaseData()),
                               VulkanAccelerationStructuresWritePropertiesMetaArgs{
                                   meta_data_id, parameter_data.GetDataAs<uint8_t>(), parameter_buffer_size },
                               std::move(uncompressed_store));
        }
    }
    else if (meta_data_type == format::MetaDataType::kExecuteBlocksFromFile)
    {
        format::ExecuteBlocksFromFile exec_from_file;
        success = block_buffer.Read(exec_from_file.thread_id);
        success = success && block_buffer.Read(exec_from_file.n_blocks);
        success = success && block_buffer.Read(exec_from_file.offset);
        success = success && block_buffer.Read(exec_from_file.filename_length);

        if (success)
        {
            std::string filename_c_str(exec_from_file.filename_length, '\0');
            success = success && block_buffer.ReadBytes(filename_c_str.data(), exec_from_file.filename_length);
            if (success)
            {
                if (success)
                {
                    return ParsedBlock(std::move(block_buffer.ReleaseData()),
                                       ExecuteBlocksFromFileArgs{ meta_data_id,
                                                                  exec_from_file.thread_id,
                                                                  exec_from_file.n_blocks,
                                                                  exec_from_file.offset,
                                                                  filename_c_str },
                                       std::move(uncompressed_store));
                }
            }
        }

        if (!success)
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read runtime info meta-data block");
        }
    }
    else if (meta_data_type == format::MetaDataType::kViewRelativeLocation)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::ViewRelativeLocation Location;
        format::ThreadId             thread_id;
        success = block_buffer.Read(thread_id);

        format::ViewRelativeLocation location;
        if (success)
        {
            success = block_buffer.Read(location);
        }

        if (success)
        {
            return ParsedBlock(std::move(block_buffer.ReleaseData()),
                               ViewRelativeLocationArgs{ meta_data_id, thread_id, location },
                               std::move(uncompressed_store));
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to ViewRelativeLocation meta-data block");
        }
    }
    else if (meta_data_type == format::MetaDataType::kInitializeMetaCommand)
    {
        format::InitializeMetaCommand header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.capture_id);
        success = success && block_buffer.Read(header.block_index);
        success = success && block_buffer.Read(header.total_number_of_initializemetacommand);
        success = success && block_buffer.Read(header.initialization_parameters_data_size);

        if (success)
        {
            BlockBuffer::BlockSpan parameter_data;

            if (header.initialization_parameters_data_size > 0)
            {
                GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, header.initialization_parameters_data_size);
                const size_t data_size = static_cast<size_t>(header.initialization_parameters_data_size);
                if (format::IsBlockCompressed(block_header.type))
                {
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
                    size_t compressed_size   = static_cast<size_t>(block_header.size) -
                                             (sizeof(header) - sizeof(header.meta_header.block_header));

                    parameter_data =
                        ReadCompressedParameterBuffer(block_buffer, compressed_size, data_size, uncompressed_store);
                }
                else
                {
                    parameter_data = ReadParameterBuffer(block_buffer, data_size);
                }
                success = parameter_data.size() == data_size;
            }
            if (success)
            {
                return ParsedBlock(std::move(block_buffer.ReleaseData()),
                                   InitializeMetaArgs{ meta_data_id, header, parameter_data.GetDataAs<uint8_t>() },
                                   std::move(uncompressed_store));
            }
            else
            {
                if (format::IsBlockCompressed(block_header.type))
                {
                    HandleBlockReadError(kErrorReadingCompressedBlockData,
                                         "Failed to read init subresource data meta-data block");
                }
                else
                {
                    HandleBlockReadError(kErrorReadingBlockData,
                                         "Failed to read init subresource data meta-data block");
                }
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read init subresource data meta-data block header");
        }
    }
    else
    {
        if (meta_data_type >= format::MetaDataType::kBeginExperimentalReservedRange ||
            meta_data_type == format::MetaDataType::kReserved23 || meta_data_type == format::MetaDataType::kReserved25)
        {
            // Only log a warning once if the capture file contains blocks that are a "reserved" meta data type.
            GFXRECON_LOG_WARNING_ONCE("This capture file contains meta-data block(s) with reserved type(s) that are "
                                      "not supported. Unsupported meta-data block types will be skipped.");
        }
        else
        {
            // Unrecognized metadata type.
            GFXRECON_LOG_WARNING("Skipping unrecognized meta-data block with type %" PRIu16, meta_data_type);
        }
        // Skip unsupported meta-data block.
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
        // Replacing the result of SkipBytes. The BlockBuffer read succeeded, so skip would.
        success = true;
    }

    return ParsedBlock(ParsedBlock::EmptyBlockTag(), ParsedBlock::BlockState::kInvalid);
}

ParsedBlock BlockParser::ParseFrameMarker(BlockBuffer& block_buffer)
{
    // The caller is responsible for reading the block and parsing the header
    GFXRECON_ASSERT(block_buffer.ReadPos() == sizeof(format::BlockHeader));
    const format::BlockHeader& block_header = block_buffer.Header();
    format::MarkerType         marker_type  = format::MarkerType::kUnknownMarker;

    bool success = block_buffer.Read(marker_type);
    if (!success)
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read frame marker block header");
        return ParsedBlock(ParsedBlock::EmptyBlockTag(), ParsedBlock::BlockState::kInvalid);
    }

    // Read the rest of the frame marker data. Currently frame markers are not dispatched to decoders.
    uint64_t frame_number = 0;
    success               = success && block_buffer.Read(frame_number);

    if (success)
    {
        // Unlike most blocks, only one subtype results in a dispatchable command
        if (marker_type == format::kEndMarker)
        {
            return ParsedBlock(std::move(block_buffer.ReleaseData()),
                               FrameEndMarkerArgs{ frame_number },
                               ParsedBlock::UncompressedStore());
        }
        else
        {
            GFXRECON_LOG_WARNING("Skipping unrecognized frame marker with type %u", marker_type);
            return ParsedBlock(ParsedBlock::EmptyBlockTag(), ParsedBlock::BlockState::kSkip);
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockData, "Failed to read frame marker data");
    }

    return ParsedBlock(ParsedBlock::EmptyBlockTag(), ParsedBlock::BlockState::kInvalid);
}

ParsedBlock BlockParser::ParseStateMarker(BlockBuffer& block_buffer)
{
    // The caller is responsible for reading the block and parsing the header
    GFXRECON_ASSERT(block_buffer.ReadPos() == sizeof(format::BlockHeader));
    const format::BlockHeader& block_header = block_buffer.Header();
    format::MarkerType         marker_type  = format::MarkerType::kUnknownMarker;

    bool success = block_buffer.Read(marker_type);
    if (!success)
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read state marker block header");
        return ParsedBlock(ParsedBlock::EmptyBlockTag(), ParsedBlock::BlockState::kInvalid);
    }

    uint64_t frame_number = 0;
    success               = success && block_buffer.Read(frame_number);

    if (success)
    {
        if (marker_type == format::kBeginMarker)
        {
            return ParsedBlock(
                std::move(block_buffer.ReleaseData()), StateBeginMarkerArgs{ frame_number }, UncompressedStore());
        }
        else if (marker_type == format::kEndMarker)
        {
            return ParsedBlock(
                std::move(block_buffer.ReleaseData()), StateEndMarkerArgs{ frame_number }, UncompressedStore());
        }
        else
        {
            GFXRECON_LOG_WARNING("Skipping unrecognized state marker with type %u", marker_type);
            return ParsedBlock(ParsedBlock::EmptyBlockTag(), ParsedBlock::BlockState::kSkip);
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockData, "Failed to read state marker data");
    }

    return ParsedBlock(ParsedBlock::EmptyBlockTag(), ParsedBlock::BlockState::kInvalid);
}

ParsedBlock BlockParser::ParseAnnotation(BlockBuffer& block_buffer)
{
    // The caller is responsible for reading the block and parsing the header
    GFXRECON_ASSERT(block_buffer.ReadPos() == sizeof(format::BlockHeader));
    const format::BlockHeader& block_header = block_buffer.Header();
    format::AnnotationType     annotation_type = format::AnnotationType::kUnknown;

    bool success = block_buffer.Read(annotation_type);
    if (!success)
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read annotation block header");
        return ParsedBlock(ParsedBlock::EmptyBlockTag(), ParsedBlock::BlockState::kInvalid);
    }

    decltype(format::AnnotationHeader::label_length) label_length = 0;
    decltype(format::AnnotationHeader::data_length)  data_length  = 0;

    success = block_buffer.Read(label_length);
    success = success && block_buffer.Read(data_length);
    if (success)
    {
        if ((label_length > 0) || (data_length > 0))
        {
            std::string label;
            std::string data;
            const auto  size_sum = label_length + data_length;
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size_sum);
            const size_t total_length = static_cast<size_t>(size_sum);

            BlockBuffer::BlockSpan parameter_data = ReadParameterBuffer(block_buffer, total_length);
            success                               = parameter_data.size() == total_length;

            if (success)
            {
                if (label_length > 0)
                {
                    const char* label_start = parameter_data.GetDataAs<char>();
                    label.assign(label_start, std::next(label_start, label_length));
                }

                if (data_length > 0)
                {
                    const char* data_start = std::next(parameter_data.GetDataAs<char>(), label_length);
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, data_length);
                    data.assign(data_start, std::next(data_start, static_cast<size_t>(data_length)));
                }

                return ParsedBlock(std::move(block_buffer.ReleaseData()),
                                   AnnotationArgs{ block_index_, annotation_type, std::move(label), std::move(data) },
                                   UncompressedStore());
            }
            else
            {
                HandleBlockReadError(kErrorReadingBlockData, "Failed to read annotation block");
            }
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read annotation block header");
    }

    return ParsedBlock(ParsedBlock::EmptyBlockTag(), ParsedBlock::BlockState::kInvalid);
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
    if (enable_print_block_info_ && ((block_index_from_ < 0 || block_index_to_ < 0) ||
                                     (block_index_from_ <= block_index_ && block_index_to_ >= block_index_)))
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

void ParsedBlock::Decompress(BlockParser& parser)
{
    GFXRECON_ASSERT("Not supported" == nullptr);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
