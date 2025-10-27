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
    annotation_handler_(nullptr), compressor_(nullptr), block_index_(0), api_call_index_(0), block_limit_(0),
    capture_uses_frame_markers_(false), first_frame_(kFirstFrame + 1), loading_trimmed_capture_state_(false)
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
    format::FileHeader file_header{};

    assert(file_stack_.front().active_file);

    if (ReadBytes(&file_header, sizeof(file_header)))
    {
        success = format::ValidateFileHeader(file_header);

        if (success)
        {
            file_options_.resize(file_header.num_options);

            size_t option_data_size = file_header.num_options * sizeof(format::FileOptionPair);

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

    while (success)
    {
        PrintBlockInfo();
        success = ContinueDecoding();

        if (success)
        {
            success = GetBlockBuffer(block_buffer);

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
                else if (base_type == format::BlockType::kFunctionCallBlock)
                {
                    format::ApiCallId api_call_id = format::ApiCallId::ApiCall_Unknown;

                    success = block_buffer.Read(api_call_id);

                    if (success)
                    {
                        bool should_break = false;
                        success           = ProcessFunctionCall(block_buffer, api_call_id, should_break);

                        if (should_break)
                        {
                            break;
                        }
                    }
                    else
                    {
                        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read function call block header");
                    }
                }
                else if (base_type == format::BlockType::kMethodCallBlock)
                {
                    format::ApiCallId api_call_id = format::ApiCallId::ApiCall_Unknown;

                    success = block_buffer.Read(api_call_id);

                    if (success)
                    {
                        bool should_break = false;
                        success           = ProcessMethodCall(block_buffer, api_call_id, should_break);

                        if (should_break)
                        {
                            break;
                        }
                    }
                    else
                    {
                        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read function call block header");
                    }
                }
                else if (base_type == format::BlockType::kMetaDataBlock)
                {
                    format::MetaDataId meta_data_id = format::MakeMetaDataId(
                        format::ApiFamilyId::ApiFamily_None, format::MetaDataType::kUnknownMetaDataType);

                    success = block_buffer.Read(meta_data_id);

                    if (success)
                    {
                        success = ProcessMetaData(block_buffer, meta_data_id);
                    }
                    else
                    {
                        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read meta-data block header");
                    }
                }
                else if (base_type == format::BlockType::kFrameMarkerBlock)
                {
                    format::MarkerType marker_type  = format::MarkerType::kUnknownMarker;
                    uint64_t           frame_number = 0;

                    success = block_buffer.Read(marker_type);

                    if (success)
                    {
                        bool should_break = false;
                        success           = ProcessFrameMarker(block_buffer, marker_type, should_break);

                        if (should_break)
                        {
                            break;
                        }
                    }
                    else
                    {
                        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read frame marker header");
                    }
                }
                else if (base_type == format::BlockType::kStateMarkerBlock)
                {
                    format::MarkerType marker_type  = format::MarkerType::kUnknownMarker;
                    uint64_t           frame_number = 0;

                    success = block_buffer.Read(marker_type);

                    if (success)
                    {
                        success = ProcessStateMarker(block_buffer, marker_type);
                    }
                    else
                    {
                        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read state marker header");
                    }
                }
                else if (base_type == format::BlockType::kAnnotation)
                {
                    if (annotation_handler_ != nullptr)
                    {
                        format::AnnotationType annotation_type = format::AnnotationType::kUnknown;

                        success = block_buffer.Read(annotation_type);

                        if (success)
                        {
                            success = ProcessAnnotation(block_buffer, annotation_type);
                        }
                        else
                        {
                            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read annotation block header");
                        }
                    }
                    else
                    {
                        // If there is no annotation handler to process the annotation, we can skip the annotation
                        // block.
                        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_buffer.Header().size);
                        // Replacing the result of SkipBytes. The BlockBuffer read succeeded, so skip would.
                        success = true;
                    }
                }
                else
                {
                    // Unrecognized block type.
                    GFXRECON_LOG_WARNING("Skipping unrecognized file block with type %u (frame %u block %" PRIu64 ")",
                                         block_buffer.Header().type,
                                         current_frame_number_,
                                         block_index_);
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_buffer.Header().size);
                    // Replacing the result of SkipBytes. The BlockBuffer read succeeded, so skip would.
                    success = true;
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
bool FileProcessor::ReadBlockBuffer(BlockBuffer& block_buffer)
{
    bool success = true;

    using BlockSizeType = decltype(format::BlockHeader::size);
    BlockSizeType block_size;
    success = PeekBytes(&block_size, sizeof(block_size));
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
        util::DataSpan block_span = ReadSpan(static_cast<size_t>(total_block_size));
        success                   = block_span.IsValid();
        if (success)
        {
            block_buffer.Reset(std::move(block_span));
            bytes_read_ += total_block_size;
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read block body data");
        }
    }

    return success;
}

// Preloading overloads this to get preloaded blocks
bool FileProcessor::GetBlockBuffer(BlockBuffer& block_buffer)
{
    return ReadBlockBuffer(block_buffer);
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
        // Note: WIP WIP WIP Should this += read_span.size() instead...
        bytes_read_ += bytes;
    }
    return read_span;
}

bool FileProcessor::SkipBytes(size_t skip_size)
{
    const auto& active_file = file_stack_.back().active_file;
    GFXRECON_ASSERT(active_file);

    bool success = active_file->FileSeek(skip_size, util::platform::FileSeekCurrent);

    if (success)
    {
        // These technically count as bytes read/processed.
        bytes_read_ += skip_size;
    }

    return success;
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

bool FileProcessor::ProcessFunctionCall(BlockBuffer& block_buffer, format::ApiCallId call_id, bool& should_break)
{
    const format::BlockHeader& block_header = block_buffer.Header();

    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
    size_t      parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(call_id);
    uint64_t    uncompressed_size     = 0;
    ApiCallInfo call_info{ block_index_ };
    bool        success = block_buffer.Read(call_info.thread_id);

    if (success)
    {
        parameter_buffer_size -= sizeof(call_info.thread_id);

        BlockBuffer::BlockSpan parameter_data;
        if (format::IsBlockCompressed(block_header.type))
        {
            parameter_buffer_size -= sizeof(uncompressed_size);
            success = block_buffer.Read(uncompressed_size);

            if (success)
            {
                GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, uncompressed_size);
                const size_t data_size = static_cast<size_t>(uncompressed_size);
                parameter_data         = ReadCompressedParameterBuffer(block_buffer, parameter_buffer_size, data_size);
                success                = parameter_data.size() == data_size;

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
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsApiCall(call_id))
                {
                    DecodeAllocator::Begin();
                    decoder->SetCurrentApiCallId(call_id);
                    decoder->DecodeFunctionCall(
                        call_id, call_info, parameter_data.GetDataAs<uint8_t>(), parameter_buffer_size);
                    DecodeAllocator::End();
                }
            }
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read function call block header");
    }

    // Break from loop on frame delimiter.
    if (IsFrameDelimiter(call_id))
    {
        // Make sure to increment the frame number on the way out.
        ++current_frame_number_;
        ++block_index_;
        should_break = true;
    }
    return success;
}

bool FileProcessor::ProcessMethodCall(BlockBuffer& block_buffer, format::ApiCallId call_id, bool& should_break)
{
    const format::BlockHeader& block_header = block_buffer.Header();

    size_t           parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(call_id);
    uint64_t         uncompressed_size     = 0;
    format::HandleId object_id             = 0;
    ApiCallInfo      call_info{ block_index_ };

    bool success = block_buffer.Read(object_id);
    success      = success && block_buffer.Read(call_info.thread_id);

    if (success)
    {
        parameter_buffer_size -= (sizeof(object_id) + sizeof(call_info.thread_id));

        BlockBuffer::BlockSpan parameter_data;
        if (format::IsBlockCompressed(block_header.type))
        {
            parameter_buffer_size -= sizeof(uncompressed_size);
            success = block_buffer.Read(uncompressed_size);

            if (success)
            {
                GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, uncompressed_size);
                const size_t data_size = static_cast<size_t>(uncompressed_size);
                parameter_data         = ReadCompressedParameterBuffer(block_buffer, parameter_buffer_size, data_size);
                success                = parameter_data.size() == data_size;

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
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsApiCall(call_id))
                {
                    DecodeAllocator::Begin();
                    decoder->SetCurrentApiCallId(call_id);
                    decoder->DecodeMethodCall(
                        call_id, object_id, call_info, parameter_data.GetDataAs<uint8_t>(), parameter_buffer_size);
                    DecodeAllocator::End();
                }
            }

            ++api_call_index_;
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read function call block header");
    }

    // Break from loop on frame delimiter.
    if (IsFrameDelimiter(call_id))
    {
        // Make sure to increment the frame number on the way out.
        ++current_frame_number_;
        ++block_index_;
        should_break = true;
    }
    return success;
}

bool FileProcessor::ProcessMetaData(BlockBuffer& block_buffer, format::MetaDataId meta_data_id)
{
    bool success = false;

    const format::BlockHeader& block_header   = block_buffer.Header();
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

                parameter_data = ReadCompressedParameterBuffer(block_buffer, compressed_size, memory_size);
            }
            else
            {
                parameter_data = ReadParameterBuffer(block_buffer, memory_size);
            }
            success = parameter_data.size() == memory_size;

            if (success)
            {
                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchFillMemoryCommand(header.thread_id,
                                                           header.memory_id,
                                                           header.memory_offset,
                                                           header.memory_size,
                                                           parameter_data.GetDataAs<uint8_t>());
                    }
                }
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
                parameter_data = ReadCompressedParameterBuffer(block_buffer, compressed_size, data_size);
            }
            else
            {
                parameter_data = ReadParameterBuffer(block_buffer, data_size);
            }
            success = parameter_data.size() == data_size;

            if (success)
            {
                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchFillMemoryResourceValueCommand(header, parameter_data.GetDataAs<uint8_t>());
                    }
                }
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
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    decoder->DispatchResizeWindowCommand(
                        command.thread_id, command.surface_id, command.width, command.height);
                }
            }
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
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    decoder->DispatchResizeWindowCommand2(
                        command.thread_id, command.surface_id, command.width, command.height, command.pre_transform);
                }
            }
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
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    decoder->DispatchExeFileInfo(header.thread_id, header);
                }
            }
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
            for (auto decoder : decoders_)
            {
                decoder->DispatchDriverInfo(header.thread_id, header);
            }
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

                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchDisplayMessageCommand(header.thread_id, message);
                    }
                }
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
                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchCreateHardwareBufferCommand(header.thread_id,
                                                                     0u,
                                                                     header.memory_id,
                                                                     header.buffer_id,
                                                                     header.format,
                                                                     header.width,
                                                                     header.height,
                                                                     header.stride,
                                                                     header.usage,
                                                                     header.layers,
                                                                     entries);
                    }
                }
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
                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchCreateHardwareBufferCommand(header.thread_id,
                                                                     0u,
                                                                     header.memory_id,
                                                                     header.buffer_id,
                                                                     header.format,
                                                                     header.width,
                                                                     header.height,
                                                                     header.stride,
                                                                     header.usage,
                                                                     header.layers,
                                                                     entries);
                    }
                }
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
                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchCreateHardwareBufferCommand(header.thread_id,
                                                                     header.device_id,
                                                                     header.memory_id,
                                                                     header.buffer_id,
                                                                     header.format,
                                                                     header.width,
                                                                     header.height,
                                                                     header.stride,
                                                                     header.usage,
                                                                     header.layers,
                                                                     entries);
                    }
                }
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
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    decoder->DispatchDestroyHardwareBufferCommand(command.thread_id, command.buffer_id);
                }
            }
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
            for (auto decoder : decoders_)
            {
                decoder->DispatchCreateHeapAllocationCommand(
                    header.thread_id, header.allocation_id, header.allocation_size);
            }
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
                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchSetDevicePropertiesCommand(header.thread_id,
                                                                    header.physical_device_id,
                                                                    header.api_version,
                                                                    header.driver_version,
                                                                    header.vendor_id,
                                                                    header.device_id,
                                                                    header.device_type,
                                                                    header.pipeline_cache_uuid,
                                                                    device_name);
                    }
                }
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
                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchSetDeviceMemoryPropertiesCommand(
                            header.thread_id, header.physical_device_id, types, heaps);
                    }
                }
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
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    decoder->DispatchSetOpaqueAddressCommand(
                        header.thread_id, header.device_id, header.object_id, header.address);
                }
            }
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
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    decoder->DispatchSetRayTracingShaderGroupHandlesCommand(header.thread_id,
                                                                            header.device_id,
                                                                            header.pipeline_id,
                                                                            static_cast<size_t>(header.data_size),
                                                                            parameter_data.GetDataAs<uint8_t>());
                }
            }
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
                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchSetSwapchainImageStateCommand(header.thread_id,
                                                                       header.device_id,
                                                                       header.swapchain_id,
                                                                       header.last_presented_image,
                                                                       entries);
                    }
                }
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
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    decoder->DispatchBeginResourceInitCommand(
                        header.thread_id, header.device_id, header.total_copy_size, header.max_copy_size);
                }
            }
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
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    decoder->DispatchEndResourceInitCommand(header.thread_id, header.device_id);
                }
            }
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

                parameter_data = ReadCompressedParameterBuffer(block_buffer, compressed_size, data_size);
            }
            else
            {
                parameter_data = ReadParameterBuffer(block_buffer, data_size);
            }
            success = parameter_data.size() == data_size;

            if (success)
            {
                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchInitBufferCommand(header.thread_id,
                                                           header.device_id,
                                                           header.buffer_id,
                                                           header.data_size,
                                                           parameter_data.GetDataAs<uint8_t>());
                    }
                }
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
                parameter_data = ReadCompressedParameterBuffer(block_buffer, compressed_size, data_size);
            }
            else
            {
                parameter_data = ReadParameterBuffer(block_buffer, data_size);
            }
            success = parameter_data.size() == data_size;
        }

        if (success)
        {
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    decoder->DispatchInitImageCommand(header.thread_id,
                                                      header.device_id,
                                                      header.image_id,
                                                      header.data_size,
                                                      header.aspect,
                                                      header.layout,
                                                      level_sizes,
                                                      parameter_data.GetDataAs<uint8_t>());
                }
            }
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

                parameter_data = ReadCompressedParameterBuffer(block_buffer, compressed_size, data_size);
            }
            else
            {
                parameter_data = ReadParameterBuffer(block_buffer, data_size);
            }
            success = parameter_data.size() == data_size;

            if (success)
            {
                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchInitSubresourceCommand(header, parameter_data.GetDataAs<uint8_t>());
                    }
                }
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

                    parameter_data = ReadCompressedParameterBuffer(block_buffer, compressed_size, data_size);
                }
                else
                {
                    parameter_data = ReadParameterBuffer(block_buffer, data_size);
                }
                success = parameter_data.size() == data_size;
            }

            if (success)
            {
                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchInitDx12AccelerationStructureCommand(
                            header, geom_descs, parameter_data.GetDataAs<uint8_t>());
                    }
                }
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
            for (auto decoder : decoders_)
            {
                decoder->DispatchGetDxgiAdapterInfo(adapter_info_header);
            }
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
            for (auto decoder : decoders_)
            {
                decoder->DispatchGetDx12RuntimeInfo(dx12_runtime_info_header);
            }
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
                        for (auto decoder : decoders_)
                        {
                            if (decoder->SupportsMetaDataId(meta_data_id))
                            {
                                decoder->DispatchSetTlasToBlasDependencyCommand(header.parent_id, blases);
                            }
                        }
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
            return success;
        }

        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, header.string_length);
        const size_t           data_size      = static_cast<size_t>(header.string_length);
        BlockBuffer::BlockSpan parameter_data = ReadParameterBuffer(block_buffer, data_size);
        success                               = parameter_data.size() == data_size;

        if (!success)
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read environment variable block data");
            return success;
        }

        const char* env_string = parameter_data.GetDataAs<char>();
        for (auto decoder : decoders_)
        {
            decoder->DispatchSetEnvironmentVariablesCommand(header, env_string);
        }
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
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    DecodeAllocator::Begin();

                    decoder->DispatchVulkanAccelerationStructuresBuildMetaCommand(parameter_data.GetDataAs<uint8_t>(),
                                                                                  parameter_buffer_size);

                    DecodeAllocator::End();
                }
            }
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
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    DecodeAllocator::Begin();

                    decoder->DispatchVulkanAccelerationStructuresCopyMetaCommand(parameter_data.GetDataAs<uint8_t>(),
                                                                                 parameter_buffer_size);

                    DecodeAllocator::End();
                }
            }
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
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    DecodeAllocator::Begin();

                    decoder->DispatchVulkanAccelerationStructuresWritePropertiesMetaCommand(
                        parameter_data.GetDataAs<uint8_t>(), parameter_buffer_size);

                    DecodeAllocator::End();
                }
            }
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
                std::string filename = util::filepath::Join(absolute_path_, filename_c_str);

                // Check for self references
                if (!filename.compare(file_stack_.back().active_file->GetFilename()))
                {
                    GFXRECON_LOG_WARNING(
                        "ExecuteBlocksFromFile is referencing itself. Probably this is not intentional.");
                }

                success = SetActiveFile(
                    filename, exec_from_file.offset, util::platform::FileSeekSet, exec_from_file.n_blocks == 0);
                if (success)
                {
                    for (auto decoder : decoders_)
                    {
                        decoder->DispatchExecuteBlocksFromFile(
                            exec_from_file.thread_id, exec_from_file.n_blocks, exec_from_file.offset, filename);
                    }

                    // We need to add 1 because it will be decremented right after this function returns
                    file_stack_.back().remaining_commands = exec_from_file.n_blocks + 1;
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
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    decoder->DispatchViewRelativeLocation(thread_id, location);
                }
            }
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

                    parameter_data = ReadCompressedParameterBuffer(block_buffer, compressed_size, data_size);
                }
                else
                {
                    parameter_data = ReadParameterBuffer(block_buffer, data_size);
                }
                success = parameter_data.size() == data_size;
            }
            if (success)
            {
                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchInitializeMetaCommand(header, parameter_data.GetDataAs<uint8_t>());
                    }
                }
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

    return success;
}

bool FileProcessor::ProcessFrameMarker(BlockBuffer& block_buffer, format::MarkerType marker_type, bool& should_break)
{
    const format::BlockHeader& block_header = block_buffer.Header();

    // Read the rest of the frame marker data. Currently frame markers are not dispatched to decoders.
    uint64_t frame_number = 0;
    bool     success      = block_buffer.Read(frame_number);

    if (success)
    {
        // Validate frame end marker's frame number matches current_frame_number_ when capture_uses_frame_markers_ is
        // true.
        GFXRECON_ASSERT((marker_type != format::kEndMarker) || (!capture_uses_frame_markers_) ||
                        (current_frame_number_ == (frame_number - first_frame_)));

        for (auto decoder : decoders_)
        {
            if (marker_type == format::kEndMarker)
            {
                decoder->DispatchFrameEndMarker(frame_number);
            }
            else
            {
                GFXRECON_LOG_WARNING("Skipping unrecognized frame marker with type %u", marker_type);
            }
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockData, "Failed to read frame marker data");
    }

    // Break from loop on frame delimiter.
    if (IsFrameDelimiter(block_header.type, marker_type))
    {
        // If the capture file contains frame markers, it will have a frame marker for every
        // frame-ending API call such as vkQueuePresentKHR. If this is the first frame marker
        // encountered, reset the frame count and ignore frame-ending API calls in
        // IsFrameDelimiter(format::ApiCallId call_id).
        if (!capture_uses_frame_markers_)
        {
            capture_uses_frame_markers_ = true;
            current_frame_number_       = kFirstFrame;
        }

        // Make sure to increment the frame number on the way out.
        ++current_frame_number_;
        ++block_index_;
        should_break = true;
    }
    return success;
}

bool FileProcessor::ProcessStateMarker(BlockBuffer& block_buffer, format::MarkerType marker_type)
{
    const format::BlockHeader& block_header = block_buffer.Header();

    uint64_t frame_number = 0;
    bool     success      = block_buffer.Read(frame_number);

    if (success)
    {
        if (marker_type == format::kBeginMarker)
        {
            GFXRECON_LOG_INFO("Loading state for captured frame %" PRId64, frame_number);
            loading_trimmed_capture_state_ = true;
        }
        else if (marker_type == format::kEndMarker)
        {
            GFXRECON_LOG_INFO("Finished loading state for captured frame %" PRId64, frame_number);
            first_frame_                   = frame_number;
            loading_trimmed_capture_state_ = false;
        }

        for (auto decoder : decoders_)
        {
            if (marker_type == format::kBeginMarker)
            {
                decoder->DispatchStateBeginMarker(frame_number);
            }
            else if (marker_type == format::kEndMarker)
            {
                decoder->DispatchStateEndMarker(frame_number);
            }
            else
            {
                GFXRECON_LOG_WARNING("Skipping unrecognized state marker with type %u", marker_type);
            }
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockData, "Failed to read state marker data");
    }

    return success;
}

bool FileProcessor::ProcessAnnotation(BlockBuffer& block_buffer, format::AnnotationType annotation_type)
{
    const format::BlockHeader& block_header = block_buffer.Header();
    bool                       success      = false;

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

                assert(annotation_handler_ != nullptr);
                annotation_handler_->ProcessAnnotation(block_index_, annotation_type, label, data);
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

    return success;
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

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
