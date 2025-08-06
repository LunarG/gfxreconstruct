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

    for (auto& file : active_files_)
    {
        util::platform::FileClose(file.second.fd);
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
    bool success = OpenFile(filename);

    if (success)
    {
        success = SetActiveFile(filename, true);
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

bool FileProcessor::OpenFile(const std::string& filename)
{
    if (active_files_.find(filename) == active_files_.end())
    {
        FILE* fd;
        int   result = util::platform::FileOpen(&fd, filename.c_str(), "rb");
        if (result || fd == nullptr)
        {
            GFXRECON_LOG_ERROR("Failed to open file %s", filename.c_str());
            error_state_ = kErrorOpeningFile;
            return false;
        }
        else
        {
            active_files_.emplace(std::piecewise_construct, std::forward_as_tuple(filename), std::forward_as_tuple(fd));
            error_state_ = kErrorNone;
        }
    }

    return true;
}

bool FileProcessor::ProcessNextFrame()
{
    bool success = IsFileValid();

    if (success)
    {
        for (ApiDecoder* decoder : decoders_)
        {
            decoder->SetCurrentFrameNumber(current_frame_number_);
        }
        success = ProcessBlocks();
    }
    else
    {
        // If not EOF, determine reason for invalid state.
        if (GetFileDescriptor() == nullptr)
        {
            error_state_ = kErrorInvalidFileDescriptor;
        }
        else if (ferror(GetFileDescriptor()))
        {
            error_state_ = kErrorReadingFile;
        }
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

    ActiveFiles& active_file = active_files_[file_stack_.front().filename];

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
    format::BlockHeader block_header;
    bool                success = true;

    while (success)
    {
        PrintBlockInfo();
        success = ContinueDecoding();

        if (success)
        {
            success = ReadBlockHeader(&block_header);
            file_stats_.AddBlockStats(block_header);
            for (auto decoder : decoders_)
            {
                decoder->SetCurrentBlockIndex(block_index_);
            }

            if (success)
            {
                if (format::RemoveCompressedBlockBit(block_header.type) == format::BlockType::kFunctionCallBlock)
                {
                    format::ApiCallId api_call_id = format::ApiCallId::ApiCall_Unknown;

                    success = ReadBytes(&api_call_id, sizeof(api_call_id));

                    if (success)
                    {
                        file_stats_.AddApiCallStats(block_header, api_call_id);

                        bool should_break = false;
                        success           = ProcessFunctionCall(block_header, api_call_id, should_break);

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
                else if (format::RemoveCompressedBlockBit(block_header.type) == format::BlockType::kMethodCallBlock)
                {
                    format::ApiCallId api_call_id = format::ApiCallId::ApiCall_Unknown;

                    success = ReadBytes(&api_call_id, sizeof(api_call_id));

                    if (success)
                    {
                        bool should_break = false;
                        success           = ProcessMethodCall(block_header, api_call_id, should_break);

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
                else if (format::RemoveCompressedBlockBit(block_header.type) == format::BlockType::kMetaDataBlock)
                {
                    format::MetaDataId meta_data_id = format::MakeMetaDataId(
                        format::ApiFamilyId::ApiFamily_None, format::MetaDataType::kUnknownMetaDataType);

                    success = ReadBytes(&meta_data_id, sizeof(meta_data_id));

                    if (success)
                    {
                        success = ProcessMetaData(block_header, meta_data_id);
                    }
                    else
                    {
                        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read meta-data block header");
                    }
                }
                else if (block_header.type == format::BlockType::kFrameMarkerBlock)
                {
                    format::MarkerType marker_type  = format::MarkerType::kUnknownMarker;
                    uint64_t           frame_number = 0;

                    success = ReadBytes(&marker_type, sizeof(marker_type));

                    if (success)
                    {
                        bool should_break = false;
                        success           = ProcessFrameMarker(block_header, marker_type, should_break);

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
                else if (block_header.type == format::BlockType::kStateMarkerBlock)
                {
                    format::MarkerType marker_type  = format::MarkerType::kUnknownMarker;
                    uint64_t           frame_number = 0;

                    success = ReadBytes(&marker_type, sizeof(marker_type));

                    if (success)
                    {
                        success = ProcessStateMarker(block_header, marker_type);
                    }
                    else
                    {
                        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read state marker header");
                    }
                }
                else if (block_header.type == format::BlockType::kAnnotation)
                {
                    if (annotation_handler_ != nullptr)
                    {
                        format::AnnotationType annotation_type = format::AnnotationType::kUnknown;

                        success = ReadBytes(&annotation_type, sizeof(annotation_type));

                        if (success)
                        {
                            success = ProcessAnnotation(block_header, annotation_type);
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
                        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
                        success = SkipBytes(static_cast<size_t>(block_header.size));
                    }
                }
                else
                {
                    // Unrecognized block type.
                    GFXRECON_LOG_WARNING("Skipping unrecognized file block with type %u (frame %u block %" PRIu64 ")",
                                         block_header.type,
                                         current_frame_number_,
                                         block_index_);
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
                    success = SkipBytes(static_cast<size_t>(block_header.size));
                }
            }
            else
            {
                if (!feof(GetFileDescriptor()))
                {
                    // No data has been read for the current block, so we don't use 'HandleBlockReadError' here, as it
                    // assumes that the block header has been successfully read and will print an incomplete block at
                    // end of file warning when the file is at EOF without an error. For this case (the normal EOF case)
                    // we print nothing at EOF, or print an error message and set the error code directly when not at
                    // EOF.
                    GFXRECON_LOG_ERROR("Failed to read block header (frame %u block %" PRIu64 ")",
                                       current_frame_number_,
                                       block_index_);
                    error_state_ = kErrorReadingBlockHeader;
                }
                else
                {
                    assert(!file_stack_.empty());

                    ActiveFileContext& current_file = GetCurrentFile();
                    if (current_file.execute_till_eof)
                    {
                        file_stack_.pop_back();
                        success = !file_stack_.empty();
                    }
                }
            }
        }
        ++block_index_;
        DecrementRemainingCommands();
    }

    DecrementRemainingCommands();
    return success;
}

bool FileProcessor::ReadBlockHeader(format::BlockHeader* block_header)
{
    assert(block_header != nullptr);

    bool success = false;

    if (ReadBytes(block_header, sizeof(*block_header)))
    {
        success = true;
    }

    return success;
}

bool FileProcessor::ReadParameterBuffer(size_t buffer_size)
{
    if (buffer_size > parameter_buffer_.size())
    {
        parameter_buffer_.resize(buffer_size);
    }

    return ReadBytes(parameter_buffer_.data(), buffer_size);
}

bool FileProcessor::ReadCompressedParameterBuffer(size_t  compressed_buffer_size,
                                                  size_t  expected_uncompressed_size,
                                                  size_t* uncompressed_buffer_size)
{
    // This should only be null if initialization failed.
    assert(compressor_ != nullptr);

    if (compressed_buffer_size > compressed_parameter_buffer_.size())
    {
        compressed_parameter_buffer_.resize(compressed_buffer_size);
    }

    if (ReadBytes(compressed_parameter_buffer_.data(), compressed_buffer_size))
    {
        if (parameter_buffer_.size() < expected_uncompressed_size)
        {
            parameter_buffer_.resize(expected_uncompressed_size);
        }

        size_t uncompressed_size = compressor_->Decompress(
            compressed_buffer_size, compressed_parameter_buffer_, expected_uncompressed_size, &parameter_buffer_);
        if ((0 < uncompressed_size) && (uncompressed_size == expected_uncompressed_size))
        {
            *uncompressed_buffer_size = uncompressed_size;
            return true;
        }
    }
    return false;
}

bool FileProcessor::ReadBytes(void* buffer, size_t buffer_size)
{
    auto file_entry = active_files_.find(file_stack_.back().filename);
    assert(file_entry != active_files_.end());

    if (util::platform::FileRead(buffer, buffer_size, file_entry->second.fd))
    {
        bytes_read_ += buffer_size;
        return true;
    }
    return false;
}

bool FileProcessor::SkipBytes(size_t skip_size)
{
    auto file_entry = active_files_.find(file_stack_.back().filename);
    assert(file_entry != active_files_.end());

    bool success = util::platform::FileSeek(file_entry->second.fd, skip_size, util::platform::FileSeekCurrent);

    if (success)
    {
        // These technically count as bytes read/processed.
        bytes_read_ += skip_size;
    }

    return success;
}

bool FileProcessor::SeekActiveFile(const std::string& filename, int64_t offset, util::platform::FileSeekOrigin origin)
{
    auto file_entry = active_files_.find(file_stack_.back().filename);
    assert(file_entry != active_files_.end());

    bool success = util::platform::FileSeek(file_entry->second.fd, offset, origin);

    if (success && origin == util::platform::FileSeekCurrent)
    {
        // These technically count as bytes read/processed.
        bytes_read_ += offset;
    }

    return success;
}

bool FileProcessor::SeekActiveFile(int64_t offset, util::platform::FileSeekOrigin origin)
{
    return SeekActiveFile(file_stack_.back().filename, offset, origin);
}

bool FileProcessor::SetActiveFile(const std::string& filename, bool execute_till_eof)
{
    if (active_files_.find(filename) != active_files_.end())
    {
        file_stack_.emplace_back(filename, execute_till_eof);
        return true;
    }
    else
    {
        return false;
    }
}

bool FileProcessor::SetActiveFile(const std::string&             filename,
                                  int64_t                        offset,
                                  util::platform::FileSeekOrigin origin,
                                  bool                           execute_till_eof)
{
    if (active_files_.find(filename) != active_files_.end())
    {
        file_stack_.emplace_back(filename, execute_till_eof);
        return SeekActiveFile(filename, offset, origin);
    }
    else
    {
        return false;
    }
}

void FileProcessor::HandleBlockReadError(Error error_code, const char* error_message)
{
    auto file_entry = active_files_.find(file_stack_.back().filename);
    assert(file_entry != active_files_.end());

    // Report incomplete block at end of file as a warning, other I/O errors as an error.
    if (feof(file_entry->second.fd) && !ferror(file_entry->second.fd))
    {
        GFXRECON_LOG_WARNING("Incomplete block at end of file");
    }
    else
    {
        GFXRECON_LOG_ERROR("%s (frame %u block %" PRIu64 ")", error_message, current_frame_number_, block_index_);
        error_state_ = error_code;
    }
}

bool FileProcessor::ProcessFunctionCall(const format::BlockHeader& block_header,
                                        format::ApiCallId          call_id,
                                        bool&                      should_break)
{
    size_t      parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(call_id);
    uint64_t    uncompressed_size     = 0;
    ApiCallInfo call_info{ block_index_ };
    bool        success = ReadBytes(&call_info.thread_id, sizeof(call_info.thread_id));

    if (success)
    {
        parameter_buffer_size -= sizeof(call_info.thread_id);

        if (format::IsBlockCompressed(block_header.type))
        {
            parameter_buffer_size -= sizeof(uncompressed_size);
            success = ReadBytes(&uncompressed_size, sizeof(uncompressed_size));

            if (success)
            {
                GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, uncompressed_size);

                size_t actual_size = 0;
                success            = ReadCompressedParameterBuffer(
                    parameter_buffer_size, static_cast<size_t>(uncompressed_size), &actual_size);

                if (success)
                {
                    assert(actual_size == uncompressed_size);
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
            success = ReadParameterBuffer(parameter_buffer_size);

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
                    decoder->DecodeFunctionCall(call_id, call_info, parameter_buffer_.data(), parameter_buffer_size);
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

bool FileProcessor::ProcessMethodCall(const format::BlockHeader& block_header,
                                      format::ApiCallId          call_id,
                                      bool&                      should_break)
{
    size_t           parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(call_id);
    uint64_t         uncompressed_size     = 0;
    format::HandleId object_id             = 0;
    ApiCallInfo      call_info{ block_index_ };

    bool success = ReadBytes(&object_id, sizeof(object_id));
    success      = success && ReadBytes(&call_info.thread_id, sizeof(call_info.thread_id));

    if (success)
    {
        parameter_buffer_size -= (sizeof(object_id) + sizeof(call_info.thread_id));

        if (format::IsBlockCompressed(block_header.type))
        {
            parameter_buffer_size -= sizeof(uncompressed_size);
            success = ReadBytes(&uncompressed_size, sizeof(uncompressed_size));

            if (success)
            {
                GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, uncompressed_size);

                size_t actual_size = 0;
                success            = ReadCompressedParameterBuffer(
                    parameter_buffer_size, static_cast<size_t>(uncompressed_size), &actual_size);

                if (success)
                {
                    assert(actual_size == uncompressed_size);
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
            success = ReadParameterBuffer(parameter_buffer_size);

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
                        call_id, object_id, call_info, parameter_buffer_.data(), parameter_buffer_size);
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

bool FileProcessor::ProcessMetaData(const format::BlockHeader& block_header, format::MetaDataId meta_data_id)
{
    bool success = false;

    format::MetaDataType meta_data_type = format::GetMetaDataType(meta_data_id);

    if (meta_data_type == format::MetaDataType::kFillMemoryCommand)
    {
        format::FillMemoryCommandHeader header;

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.memory_id, sizeof(header.memory_id));
        success = success && ReadBytes(&header.memory_offset, sizeof(header.memory_offset));
        success = success && ReadBytes(&header.memory_size, sizeof(header.memory_size));

        if (success)
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, header.memory_size);

            if (format::IsBlockCompressed(block_header.type))
            {
                size_t uncompressed_size = 0;
                size_t compressed_size   = static_cast<size_t>(block_header.size) - sizeof(meta_data_id) -
                                         sizeof(header.thread_id) - sizeof(header.memory_id) -
                                         sizeof(header.memory_offset) - sizeof(header.memory_size);

                success = ReadCompressedParameterBuffer(
                    compressed_size, static_cast<size_t>(header.memory_size), &uncompressed_size);
            }
            else
            {
                success = ReadParameterBuffer(static_cast<size_t>(header.memory_size));
            }

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
                                                           parameter_buffer_.data());
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

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = ReadBytes(&header.resource_value_count, sizeof(header.resource_value_count));

        if (success)
        {
            uint64_t data_size = header.resource_value_count * (sizeof(format::ResourceValueType) + sizeof(uint64_t));
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, data_size);

            if (format::IsBlockCompressed(block_header.type))
            {
                size_t uncompressed_size = 0;
                size_t compressed_size   = static_cast<size_t>(block_header.size) - sizeof(meta_data_id) -
                                         sizeof(header.thread_id) - sizeof(header.resource_value_count);
                size_t uncompressed_data = static_cast<size_t>(data_size);
                success = ReadCompressedParameterBuffer(compressed_size, uncompressed_data, &uncompressed_size);
            }
            else
            {
                success = ReadParameterBuffer(static_cast<size_t>(data_size));
            }

            if (success)
            {
                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchFillMemoryResourceValueCommand(header, parameter_buffer_.data());
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

        success = ReadBytes(&command.thread_id, sizeof(command.thread_id));
        success = success && ReadBytes(&command.surface_id, sizeof(command.surface_id));
        success = success && ReadBytes(&command.width, sizeof(command.width));
        success = success && ReadBytes(&command.height, sizeof(command.height));

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

        success = ReadBytes(&command.thread_id, sizeof(command.thread_id));
        success = success && ReadBytes(&command.surface_id, sizeof(command.surface_id));
        success = success && ReadBytes(&command.width, sizeof(command.width));
        success = success && ReadBytes(&command.height, sizeof(command.height));
        success = success && ReadBytes(&command.pre_transform, sizeof(command.pre_transform));

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
        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));

        success =
            success && ReadBytes(&header.info_record.ProductVersion, gfxrecon::util::filepath::kMaxFilePropertySize);
        success = success && ReadBytes(&header.info_record.FileVersion, gfxrecon::util::filepath::kMaxFilePropertySize);
        success = success && ReadBytes(&header.info_record.AppVersion,
                                       sizeof(uint32_t) * gfxrecon::util::filepath::kFileVersionSize);
        success = success && ReadBytes(&header.info_record.AppName, gfxrecon::util::filepath::kMaxFilePropertySize);
        success = success && ReadBytes(&header.info_record.CompanyName, gfxrecon::util::filepath::kMaxFilePropertySize);
        success =
            success && ReadBytes(&header.info_record.FileDescription, gfxrecon::util::filepath::kMaxFilePropertySize);
        success =
            success && ReadBytes(&header.info_record.InternalName, gfxrecon::util::filepath::kMaxFilePropertySize);
        success =
            success && ReadBytes(&header.info_record.OriginalFilename, gfxrecon::util::filepath::kMaxFilePropertySize);
        success = success && ReadBytes(&header.info_record.ProductName, gfxrecon::util::filepath::kMaxFilePropertySize);

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
        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));

        success = success && ReadBytes(&header.driver_record, gfxrecon::util::filepath::kMaxDriverInfoSize);

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

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));

        if (success)
        {
            uint64_t message_size = block_header.size - sizeof(meta_data_id) - sizeof(header.thread_id);

            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, message_size);

            success = ReadParameterBuffer(static_cast<size_t>(message_size));

            if (success)
            {
                auto        message_start = parameter_buffer_.begin();
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

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.memory_id, sizeof(header.memory_id));
        success = success && ReadBytes(&header.buffer_id, sizeof(header.buffer_id));
        success = success && ReadBytes(&header.format, sizeof(header.format));
        success = success && ReadBytes(&header.width, sizeof(header.width));
        success = success && ReadBytes(&header.height, sizeof(header.height));
        success = success && ReadBytes(&header.stride, sizeof(header.stride));
        success = success && ReadBytes(&header.usage, sizeof(header.usage));
        success = success && ReadBytes(&header.layers, sizeof(header.layers));
        success = success && ReadBytes(&header.planes, sizeof(header.planes));

        if (success)
        {
            std::vector<format::HardwareBufferPlaneInfo> entries;

            for (uint64_t i = 0; i < header.planes; ++i)
            {
                format::HardwareBufferPlaneInfo entry;

                if (!ReadBytes(&entry, sizeof(entry)))
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

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.memory_id, sizeof(header.memory_id));
        success = success && ReadBytes(&header.buffer_id, sizeof(header.buffer_id));
        success = success && ReadBytes(&header.format, sizeof(header.format));
        success = success && ReadBytes(&header.width, sizeof(header.width));
        success = success && ReadBytes(&header.height, sizeof(header.height));
        success = success && ReadBytes(&header.stride, sizeof(header.stride));
        success = success && ReadBytes(&header.usage, sizeof(header.usage));
        success = success && ReadBytes(&header.layers, sizeof(header.layers));
        success = success && ReadBytes(&header.planes, sizeof(header.planes));

        if (success)
        {
            std::vector<format::HardwareBufferPlaneInfo> entries;

            for (uint64_t i = 0; i < header.planes; ++i)
            {
                format::HardwareBufferPlaneInfo entry;

                if (!ReadBytes(&entry, sizeof(entry)))
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

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.device_id, sizeof(header.device_id));
        success = success && ReadBytes(&header.memory_id, sizeof(header.memory_id));
        success = success && ReadBytes(&header.buffer_id, sizeof(header.buffer_id));
        success = success && ReadBytes(&header.format, sizeof(header.format));
        success = success && ReadBytes(&header.width, sizeof(header.width));
        success = success && ReadBytes(&header.height, sizeof(header.height));
        success = success && ReadBytes(&header.stride, sizeof(header.stride));
        success = success && ReadBytes(&header.usage, sizeof(header.usage));
        success = success && ReadBytes(&header.layers, sizeof(header.layers));
        success = success && ReadBytes(&header.planes, sizeof(header.planes));

        if (success)
        {
            std::vector<format::HardwareBufferPlaneInfo> entries;

            for (uint64_t i = 0; i < header.planes; ++i)
            {
                format::HardwareBufferPlaneInfo entry;

                if (!ReadBytes(&entry, sizeof(entry)))
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

        success = ReadBytes(&command.thread_id, sizeof(command.thread_id));
        success = success && ReadBytes(&command.buffer_id, sizeof(command.buffer_id));

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

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.allocation_id, sizeof(header.allocation_id));
        success = success && ReadBytes(&header.allocation_size, sizeof(header.allocation_size));

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

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.physical_device_id, sizeof(header.physical_device_id));
        success = success && ReadBytes(&header.api_version, sizeof(header.api_version));
        success = success && ReadBytes(&header.driver_version, sizeof(header.driver_version));
        success = success && ReadBytes(&header.vendor_id, sizeof(header.vendor_id));
        success = success && ReadBytes(&header.device_id, sizeof(header.device_id));
        success = success && ReadBytes(&header.device_type, sizeof(header.device_type));
        success = success && ReadBytes(&header.pipeline_cache_uuid, format::kUuidSize);
        success = success && ReadBytes(&header.device_name_len, sizeof(header.device_name_len));

        if (success)
        {
            char device_name[format::kMaxPhysicalDeviceNameSize];

            if (header.device_name_len < format::kMaxPhysicalDeviceNameSize)
            {
                success                             = success && ReadBytes(&device_name, header.device_name_len);
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

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.physical_device_id, sizeof(header.physical_device_id));
        success = success && ReadBytes(&header.memory_type_count, sizeof(header.memory_type_count));
        success = success && ReadBytes(&header.memory_heap_count, sizeof(header.memory_heap_count));

        if (success)
        {
            std::vector<format::DeviceMemoryType> types;
            std::vector<format::DeviceMemoryHeap> heaps;

            for (uint32_t i = 0; i < header.memory_type_count; ++i)
            {
                format::DeviceMemoryType type;

                if (!ReadBytes(&type, sizeof(type)))
                {
                    success = false;
                    break;
                }

                types.emplace_back(std::move(type));
            }

            for (uint32_t i = 0; i < header.memory_heap_count; ++i)
            {
                format::DeviceMemoryHeap heap;

                if (!ReadBytes(&heap, sizeof(heap)))
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

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.device_id, sizeof(header.device_id));
        success = success && ReadBytes(&header.object_id, sizeof(header.object_id));
        success = success && ReadBytes(&header.address, sizeof(header.address));

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

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.device_id, sizeof(header.device_id));
        success = success && ReadBytes(&header.pipeline_id, sizeof(header.pipeline_id));
        success = success && ReadBytes(&header.data_size, sizeof(header.data_size));

        // Read variable size shader group handle data into parameter_buffer_.
        success = success && ReadParameterBuffer(static_cast<size_t>(header.data_size));

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
                                                                            parameter_buffer_.data());
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

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.device_id, sizeof(header.device_id));
        success = success && ReadBytes(&header.swapchain_id, sizeof(header.swapchain_id));
        success = success && ReadBytes(&header.last_presented_image, sizeof(header.last_presented_image));
        success = success && ReadBytes(&header.image_info_count, sizeof(header.image_info_count));

        if (success)
        {
            std::vector<format::SwapchainImageStateInfo> entries;

            for (uint32_t i = 0; i < header.image_info_count; ++i)
            {
                format::SwapchainImageStateInfo entry;

                if (!ReadBytes(&entry, sizeof(entry)))
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

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.device_id, sizeof(header.device_id));
        success = success && ReadBytes(&header.max_resource_size, sizeof(header.max_resource_size));
        success = success && ReadBytes(&header.max_copy_size, sizeof(header.max_copy_size));

        if (success)
        {
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    decoder->DispatchBeginResourceInitCommand(
                        header.thread_id, header.device_id, header.max_resource_size, header.max_copy_size);
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

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.device_id, sizeof(header.device_id));

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

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.device_id, sizeof(header.device_id));
        success = success && ReadBytes(&header.buffer_id, sizeof(header.buffer_id));
        success = success && ReadBytes(&header.data_size, sizeof(header.data_size));

        if (success)
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, header.data_size);

            if (format::IsBlockCompressed(block_header.type))
            {
                size_t uncompressed_size = 0;
                size_t compressed_size =
                    static_cast<size_t>(block_header.size) - (sizeof(header) - sizeof(header.meta_header.block_header));

                success = ReadCompressedParameterBuffer(
                    compressed_size, static_cast<size_t>(header.data_size), &uncompressed_size);
            }
            else
            {
                success = ReadParameterBuffer(static_cast<size_t>(header.data_size));
            }

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
                                                           parameter_buffer_.data());
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

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.device_id, sizeof(header.device_id));
        success = success && ReadBytes(&header.image_id, sizeof(header.image_id));
        success = success && ReadBytes(&header.data_size, sizeof(header.data_size));
        success = success && ReadBytes(&header.aspect, sizeof(header.aspect));
        success = success && ReadBytes(&header.layout, sizeof(header.layout));
        success = success && ReadBytes(&header.level_count, sizeof(header.level_count));

        if (success && (header.level_count > 0))
        {
            level_sizes.resize(header.level_count);
            success = success && ReadBytes(level_sizes.data(), header.level_count * sizeof(level_sizes[0]));
        }

        if (success && (header.data_size > 0))
        {
            assert(header.data_size == std::accumulate(level_sizes.begin(), level_sizes.end(), 0ull));
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, header.data_size);

            if (format::IsBlockCompressed(block_header.type))
            {
                size_t uncompressed_size = 0;
                size_t compressed_size   = static_cast<size_t>(block_header.size) -
                                         (sizeof(header) - sizeof(header.meta_header.block_header)) -
                                         (level_sizes.size() * sizeof(level_sizes[0]));

                success = ReadCompressedParameterBuffer(
                    compressed_size, static_cast<size_t>(header.data_size), &uncompressed_size);
            }
            else
            {
                success = ReadParameterBuffer(static_cast<size_t>(header.data_size));
            }
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
                                                      parameter_buffer_.data());
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

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.device_id, sizeof(header.device_id));
        success = success && ReadBytes(&header.resource_id, sizeof(header.resource_id));
        success = success && ReadBytes(&header.subresource, sizeof(header.subresource));
        success = success && ReadBytes(&header.initial_state, sizeof(header.initial_state));
        success = success && ReadBytes(&header.resource_state, sizeof(header.resource_state));
        success = success && ReadBytes(&header.barrier_flags, sizeof(header.barrier_flags));
        success = success && ReadBytes(&header.data_size, sizeof(header.data_size));

        if (success)
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, header.data_size);

            if (format::IsBlockCompressed(block_header.type))
            {
                size_t uncompressed_size = 0;
                size_t compressed_size =
                    static_cast<size_t>(block_header.size) - (sizeof(header) - sizeof(header.meta_header.block_header));

                success = ReadCompressedParameterBuffer(
                    compressed_size, static_cast<size_t>(header.data_size), &uncompressed_size);
            }
            else
            {
                success = ReadParameterBuffer(static_cast<size_t>(header.data_size));
            }

            if (success)
            {
                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchInitSubresourceCommand(header, parameter_buffer_.data());
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
        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success &&
                  ReadBytes(&header.dest_acceleration_structure_data, sizeof(header.dest_acceleration_structure_data));
        success = success && ReadBytes(&header.copy_source_gpu_va, sizeof(header.copy_source_gpu_va));
        success = success && ReadBytes(&header.copy_mode, sizeof(header.copy_mode));
        success = success && ReadBytes(&header.inputs_type, sizeof(header.inputs_type));
        success = success && ReadBytes(&header.inputs_flags, sizeof(header.inputs_flags));
        success = success && ReadBytes(&header.inputs_num_instance_descs, sizeof(header.inputs_num_instance_descs));
        success = success && ReadBytes(&header.inputs_num_geometry_descs, sizeof(header.inputs_num_geometry_descs));
        success = success && ReadBytes(&header.inputs_data_size, sizeof(header.inputs_data_size));

        // Parse geometry descs.
        std::vector<format::InitDx12AccelerationStructureGeometryDesc> geom_descs;
        if (success)
        {
            for (uint32_t i = 0; i < header.inputs_num_geometry_descs; ++i)
            {
                format::InitDx12AccelerationStructureGeometryDesc geom_desc;
                success = success && ReadBytes(&geom_desc.geometry_type, sizeof(geom_desc.geometry_type));
                success = success && ReadBytes(&geom_desc.geometry_flags, sizeof(geom_desc.geometry_flags));
                success = success && ReadBytes(&geom_desc.aabbs_count, sizeof(geom_desc.aabbs_count));
                success = success && ReadBytes(&geom_desc.aabbs_stride, sizeof(geom_desc.aabbs_stride));
                success =
                    success && ReadBytes(&geom_desc.triangles_has_transform, sizeof(geom_desc.triangles_has_transform));
                success =
                    success && ReadBytes(&geom_desc.triangles_index_format, sizeof(geom_desc.triangles_index_format));
                success =
                    success && ReadBytes(&geom_desc.triangles_vertex_format, sizeof(geom_desc.triangles_vertex_format));
                success =
                    success && ReadBytes(&geom_desc.triangles_index_count, sizeof(geom_desc.triangles_index_count));
                success =
                    success && ReadBytes(&geom_desc.triangles_vertex_count, sizeof(geom_desc.triangles_vertex_count));
                success =
                    success && ReadBytes(&geom_desc.triangles_vertex_stride, sizeof(geom_desc.triangles_vertex_stride));
                geom_descs.push_back(geom_desc);
            }
        }

        if (success)
        {
            if (header.inputs_data_size > 0)
            {
                GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, header.inputs_data_size);

                if (format::IsBlockCompressed(block_header.type))
                {
                    size_t uncompressed_size = 0;
                    size_t compressed_size =
                        static_cast<size_t>(block_header.size) -
                        (sizeof(header) - sizeof(header.meta_header.block_header)) -
                        (sizeof(format::InitDx12AccelerationStructureGeometryDesc) * header.inputs_num_geometry_descs);

                    success = ReadCompressedParameterBuffer(
                        compressed_size, static_cast<size_t>(header.inputs_data_size), &uncompressed_size);
                }
                else
                {
                    success = ReadParameterBuffer(static_cast<size_t>(header.inputs_data_size));
                }
            }

            if (success)
            {
                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchInitDx12AccelerationStructureCommand(
                            header, geom_descs, parameter_buffer_.data());
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

        success = ReadBytes(&adapter_info_header.thread_id, sizeof(adapter_info_header.thread_id));

        success = success && ReadBytes(&adapter_info_header.adapter_desc.Description,
                                       sizeof(adapter_info_header.adapter_desc.Description));
        success = success && ReadBytes(&adapter_info_header.adapter_desc.VendorId,
                                       sizeof(adapter_info_header.adapter_desc.VendorId));
        success = success && ReadBytes(&adapter_info_header.adapter_desc.DeviceId,
                                       sizeof(adapter_info_header.adapter_desc.DeviceId));
        success = success && ReadBytes(&adapter_info_header.adapter_desc.SubSysId,
                                       sizeof(adapter_info_header.adapter_desc.SubSysId));
        success = success && ReadBytes(&adapter_info_header.adapter_desc.Revision,
                                       sizeof(adapter_info_header.adapter_desc.Revision));
        success = success && ReadBytes(&adapter_info_header.adapter_desc.DedicatedVideoMemory,
                                       sizeof(adapter_info_header.adapter_desc.DedicatedVideoMemory));
        success = success && ReadBytes(&adapter_info_header.adapter_desc.DedicatedSystemMemory,
                                       sizeof(adapter_info_header.adapter_desc.DedicatedSystemMemory));
        success = success && ReadBytes(&adapter_info_header.adapter_desc.SharedSystemMemory,
                                       sizeof(adapter_info_header.adapter_desc.SharedSystemMemory));
        success = success && ReadBytes(&adapter_info_header.adapter_desc.LuidLowPart,
                                       sizeof(adapter_info_header.adapter_desc.LuidLowPart));
        success = success && ReadBytes(&adapter_info_header.adapter_desc.LuidHighPart,
                                       sizeof(adapter_info_header.adapter_desc.LuidHighPart));
        success = success && ReadBytes(&adapter_info_header.adapter_desc.extra_info,
                                       sizeof(adapter_info_header.adapter_desc.extra_info));

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

        success = ReadBytes(&dx12_runtime_info_header.thread_id, sizeof(dx12_runtime_info_header.thread_id));

        success = success && ReadBytes(&dx12_runtime_info_header.runtime_info.version,
                                       sizeof(dx12_runtime_info_header.runtime_info.version));

        success = success && ReadBytes(&dx12_runtime_info_header.runtime_info.src,
                                       sizeof(dx12_runtime_info_header.runtime_info.src));

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
        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.dependency_type, sizeof(header.dependency_type));
        success = success && ReadBytes(&header.parent_id, sizeof(header.parent_id));
        success = success && ReadBytes(&header.child_count, sizeof(header.child_count));

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
                        success = success && ReadBytes(&blases[i], sizeof(blases[i]));
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
        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.string_length, sizeof(header.string_length));
        if (!success)
        {
            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read environment variable block header");
            return success;
        }

        success = ReadParameterBuffer(static_cast<size_t>(header.string_length));
        if (!success)
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read environment variable block data");
            return success;
        }

        const char* env_string = (const char*)parameter_buffer_.data();
        for (auto decoder : decoders_)
        {
            decoder->DispatchSetEnvironmentVariablesCommand(header, env_string);
        }
    }
    else if (meta_data_type == format::MetaDataType::kVulkanBuildAccelerationStructuresCommand)
    {
        format::VulkanMetaBuildAccelerationStructuresHeader header{};
        size_t parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(meta_data_id);
        success                      = ReadParameterBuffer(parameter_buffer_size);

        if (success)
        {
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    DecodeAllocator::Begin();

                    decoder->DispatchVulkanAccelerationStructuresBuildMetaCommand(parameter_buffer_.data(),
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
        size_t parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(meta_data_id);
        success                      = ReadParameterBuffer(parameter_buffer_size);

        if (success)
        {
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    DecodeAllocator::Begin();

                    decoder->DispatchVulkanAccelerationStructuresCopyMetaCommand(parameter_buffer_.data(),
                                                                                 parameter_buffer_size);

                    DecodeAllocator::End();
                }
            }
        }
    }
    else if (meta_data_type == format::MetaDataType::kVulkanWriteAccelerationStructuresPropertiesCommand)
    {
        format::VulkanCopyAccelerationStructuresCommandHeader header{};
        size_t parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(meta_data_id);
        success                      = ReadParameterBuffer(parameter_buffer_size);

        if (success)
        {
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    DecodeAllocator::Begin();

                    decoder->DispatchVulkanAccelerationStructuresWritePropertiesMetaCommand(parameter_buffer_.data(),
                                                                                            parameter_buffer_size);

                    DecodeAllocator::End();
                }
            }
        }
    }
    else if (meta_data_type == format::MetaDataType::kExecuteBlocksFromFile)
    {
        format::ExecuteBlocksFromFile exec_from_file;
        success = ReadBytes(&exec_from_file.thread_id, sizeof(exec_from_file.thread_id));
        success = success && ReadBytes(&exec_from_file.n_blocks, sizeof(exec_from_file.n_blocks));
        success = success && ReadBytes(&exec_from_file.offset, sizeof(exec_from_file.offset));
        success = success && ReadBytes(&exec_from_file.filename_length, sizeof(exec_from_file.filename_length));

        if (success)
        {
            std::string filename_c_str(exec_from_file.filename_length, '\0');
            success = success && ReadBytes(filename_c_str.data(), exec_from_file.filename_length);
            if (success)
            {
                std::string filename = util::filepath::Join(absolute_path_, filename_c_str);

                // Check for self references
                if (!filename.compare(file_stack_.back().filename))
                {
                    GFXRECON_LOG_WARNING(
                        "ExecuteBlocksFromFile is referencing itself. Probably this is not intentional.");
                }

                success = OpenFile(filename);
                if (success)
                {
                    for (auto decoder : decoders_)
                    {
                        decoder->DispatchExecuteBlocksFromFile(
                            exec_from_file.thread_id, exec_from_file.n_blocks, exec_from_file.offset, filename);
                    }

                    SetActiveFile(
                        filename, exec_from_file.offset, util::platform::FileSeekSet, exec_from_file.n_blocks == 0);
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
        success = ReadBytes(&thread_id, sizeof(thread_id));

        format::ViewRelativeLocation location;
        if (success)
        {
            success = ReadBytes(&location, sizeof(location));
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

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.capture_id, sizeof(header.capture_id));
        success = success && ReadBytes(&header.block_index, sizeof(header.block_index));
        success = success && ReadBytes(&header.total_number_of_initializemetacommand,
                                       sizeof(header.total_number_of_initializemetacommand));
        success = success && ReadBytes(&header.initialization_parameters_data_size,
                                       sizeof(header.initialization_parameters_data_size));

        if (success)
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, header.initialization_parameters_data_size);
            if (header.initialization_parameters_data_size > 0)
            {
                if (format::IsBlockCompressed(block_header.type))
                {
                    size_t uncompressed_size = 0;
                    size_t compressed_size   = static_cast<size_t>(block_header.size) -
                                             (sizeof(header) - sizeof(header.meta_header.block_header));

                    success =
                        ReadCompressedParameterBuffer(compressed_size,
                                                      static_cast<size_t>(header.initialization_parameters_data_size),
                                                      &uncompressed_size);
                }
                else
                {
                    success = ReadParameterBuffer(static_cast<size_t>(header.initialization_parameters_data_size));
                }
            }
            if (success)
            {
                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchInitializeMetaCommand(header, parameter_buffer_.data());
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
        if ((meta_data_type == format::MetaDataType::kReserved23) ||
            (meta_data_type == format::MetaDataType::kReserved25))
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
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
        success = SkipBytes(static_cast<size_t>(block_header.size) - sizeof(meta_data_id));
    }

    return success;
}

bool FileProcessor::ProcessFrameMarker(const format::BlockHeader& block_header,
                                       format::MarkerType         marker_type,
                                       bool&                      should_break)
{
    // Read the rest of the frame marker data. Currently frame markers are not dispatched to decoders.
    uint64_t frame_number = 0;
    bool     success      = ReadBytes(&frame_number, sizeof(frame_number));

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

bool FileProcessor::ProcessStateMarker(const format::BlockHeader& block_header, format::MarkerType marker_type)
{
    uint64_t frame_number = 0;
    bool     success      = ReadBytes(&frame_number, sizeof(frame_number));

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

bool FileProcessor::ProcessAnnotation(const format::BlockHeader& block_header, format::AnnotationType annotation_type)
{
    bool                                             success      = false;
    decltype(format::AnnotationHeader::label_length) label_length = 0;
    decltype(format::AnnotationHeader::data_length)  data_length  = 0;

    success = ReadBytes(&label_length, sizeof(label_length));
    success = success && ReadBytes(&data_length, sizeof(data_length));
    if (success)
    {
        if ((label_length > 0) || (data_length > 0))
        {
            std::string label;
            std::string data;
            const auto  size_sum = label_length + data_length;
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size_sum);
            const size_t total_length = static_cast<size_t>(size_sum);

            success = ReadParameterBuffer(total_length);
            if (success)
            {
                if (label_length > 0)
                {
                    auto label_start = parameter_buffer_.begin();
                    label.assign(label_start, std::next(label_start, label_length));
                }

                if (data_length > 0)
                {
                    auto data_start = std::next(parameter_buffer_.begin(), label_length);
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

const char* FileProcessor::FileStats<true>::BlockName(format::BlockType type) const
{
    switch (type)
    {
        case format::kUnknownBlock:
            return "kUnknownBlock";
        case format::kFrameMarkerBlock:
            return "kFrameMarkerBlock";
        case format::kStateMarkerBlock:
            return "kStateMarkerBlock";
        case format::kMetaDataBlock:
            return "kMetaDataBlock";
        case format::kFunctionCallBlock:
            return "kFunctionCallBlock";
        case format::kAnnotation:
            return "kAnnotation";
        case format::kMethodCallBlock:
            return "kMethodCallBlock";
        case format::kCompressedMetaDataBlock:
            return "kCompressedMetaDataBlock";
        case format::kCompressedFunctionCallBlock:
            return "kCompressedFunctionCallBlock";
        case format::kCompressedMethodCallBlock:
            return "kCompressedMethodCallBlock";
    }
    return "BAD_BLOCK_TYPE";
}

const std::string FileProcessor::FileStats<true>::BlockName(format::ApiCallId call_id) const
{
    // clang-format off
    const static std::map<gfxrecon::format::ApiCallId, std::string> kApiCallIdToString = {
        { gfxrecon::format::ApiCall_Unknown, "ApiCall_Unknown" },
        { gfxrecon::format::ApiCall_vkCreateInstance, "ApiCall_vkCreateInstance" },
        { gfxrecon::format::ApiCall_vkDestroyInstance, "ApiCall_vkDestroyInstance" },
        { gfxrecon::format::ApiCall_vkEnumeratePhysicalDevices, "ApiCall_vkEnumeratePhysicalDevices" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceFeatures, "ApiCall_vkGetPhysicalDeviceFeatures" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceFormatProperties, "ApiCall_vkGetPhysicalDeviceFormatProperties" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceImageFormatProperties, "ApiCall_vkGetPhysicalDeviceImageFormatProperties" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceProperties, "ApiCall_vkGetPhysicalDeviceProperties" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties, "ApiCall_vkGetPhysicalDeviceQueueFamilyProperties" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceMemoryProperties, "ApiCall_vkGetPhysicalDeviceMemoryProperties" },
        { gfxrecon::format::ApiCall_vkGetInstanceProcAddr, "ApiCall_vkGetInstanceProcAddr" },
        { gfxrecon::format::ApiCall_vkGetDeviceProcAddr, "ApiCall_vkGetDeviceProcAddr" },
        { gfxrecon::format::ApiCall_vkCreateDevice, "ApiCall_vkCreateDevice" },
        { gfxrecon::format::ApiCall_vkDestroyDevice, "ApiCall_vkDestroyDevice" },
        { gfxrecon::format::ApiCall_vkEnumerateInstanceExtensionProperties, "ApiCall_vkEnumerateInstanceExtensionProperties" },
        { gfxrecon::format::ApiCall_vkEnumerateDeviceExtensionProperties, "ApiCall_vkEnumerateDeviceExtensionProperties" },
        { gfxrecon::format::ApiCall_vkEnumerateInstanceLayerProperties, "ApiCall_vkEnumerateInstanceLayerProperties" },
        { gfxrecon::format::ApiCall_vkEnumerateDeviceLayerProperties, "ApiCall_vkEnumerateDeviceLayerProperties" },
        { gfxrecon::format::ApiCall_vkGetDeviceQueue, "ApiCall_vkGetDeviceQueue" },
        { gfxrecon::format::ApiCall_vkQueueSubmit, "ApiCall_vkQueueSubmit" },
        { gfxrecon::format::ApiCall_vkQueueWaitIdle, "ApiCall_vkQueueWaitIdle" },
        { gfxrecon::format::ApiCall_vkDeviceWaitIdle, "ApiCall_vkDeviceWaitIdle" },
        { gfxrecon::format::ApiCall_vkAllocateMemory, "ApiCall_vkAllocateMemory" },
        { gfxrecon::format::ApiCall_vkFreeMemory, "ApiCall_vkFreeMemory" },
        { gfxrecon::format::ApiCall_vkMapMemory, "ApiCall_vkMapMemory" },
        { gfxrecon::format::ApiCall_vkUnmapMemory, "ApiCall_vkUnmapMemory" },
        { gfxrecon::format::ApiCall_vkFlushMappedMemoryRanges, "ApiCall_vkFlushMappedMemoryRanges" },
        { gfxrecon::format::ApiCall_vkInvalidateMappedMemoryRanges, "ApiCall_vkInvalidateMappedMemoryRanges" },
        { gfxrecon::format::ApiCall_vkGetDeviceMemoryCommitment, "ApiCall_vkGetDeviceMemoryCommitment" },
        { gfxrecon::format::ApiCall_vkBindBufferMemory, "ApiCall_vkBindBufferMemory" },
        { gfxrecon::format::ApiCall_vkBindImageMemory, "ApiCall_vkBindImageMemory" },
        { gfxrecon::format::ApiCall_vkGetBufferMemoryRequirements, "ApiCall_vkGetBufferMemoryRequirements" },
        { gfxrecon::format::ApiCall_vkGetImageMemoryRequirements, "ApiCall_vkGetImageMemoryRequirements" },
        { gfxrecon::format::ApiCall_vkGetImageSparseMemoryRequirements, "ApiCall_vkGetImageSparseMemoryRequirements" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties, "ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties" },
        { gfxrecon::format::ApiCall_vkQueueBindSparse, "ApiCall_vkQueueBindSparse" },
        { gfxrecon::format::ApiCall_vkCreateFence, "ApiCall_vkCreateFence" },
        { gfxrecon::format::ApiCall_vkDestroyFence, "ApiCall_vkDestroyFence" },
        { gfxrecon::format::ApiCall_vkResetFences, "ApiCall_vkResetFences" },
        { gfxrecon::format::ApiCall_vkGetFenceStatus, "ApiCall_vkGetFenceStatus" },
        { gfxrecon::format::ApiCall_vkWaitForFences, "ApiCall_vkWaitForFences" },
        { gfxrecon::format::ApiCall_vkCreateSemaphore, "ApiCall_vkCreateSemaphore" },
        { gfxrecon::format::ApiCall_vkDestroySemaphore, "ApiCall_vkDestroySemaphore" },
        { gfxrecon::format::ApiCall_vkCreateEvent, "ApiCall_vkCreateEvent" },
        { gfxrecon::format::ApiCall_vkDestroyEvent, "ApiCall_vkDestroyEvent" },
        { gfxrecon::format::ApiCall_vkGetEventStatus, "ApiCall_vkGetEventStatus" },
        { gfxrecon::format::ApiCall_vkSetEvent, "ApiCall_vkSetEvent" },
        { gfxrecon::format::ApiCall_vkResetEvent, "ApiCall_vkResetEvent" },
        { gfxrecon::format::ApiCall_vkCreateQueryPool, "ApiCall_vkCreateQueryPool" },
        { gfxrecon::format::ApiCall_vkDestroyQueryPool, "ApiCall_vkDestroyQueryPool" },
        { gfxrecon::format::ApiCall_vkGetQueryPoolResults, "ApiCall_vkGetQueryPoolResults" },
        { gfxrecon::format::ApiCall_vkCreateBuffer, "ApiCall_vkCreateBuffer" },
        { gfxrecon::format::ApiCall_vkDestroyBuffer, "ApiCall_vkDestroyBuffer" },
        { gfxrecon::format::ApiCall_vkCreateBufferView, "ApiCall_vkCreateBufferView" },
        { gfxrecon::format::ApiCall_vkDestroyBufferView, "ApiCall_vkDestroyBufferView" },
        { gfxrecon::format::ApiCall_vkCreateImage, "ApiCall_vkCreateImage" },
        { gfxrecon::format::ApiCall_vkDestroyImage, "ApiCall_vkDestroyImage" },
        { gfxrecon::format::ApiCall_vkGetImageSubresourceLayout, "ApiCall_vkGetImageSubresourceLayout" },
        { gfxrecon::format::ApiCall_vkCreateImageView, "ApiCall_vkCreateImageView" },
        { gfxrecon::format::ApiCall_vkDestroyImageView, "ApiCall_vkDestroyImageView" },
        { gfxrecon::format::ApiCall_vkCreateShaderModule, "ApiCall_vkCreateShaderModule" },
        { gfxrecon::format::ApiCall_vkDestroyShaderModule, "ApiCall_vkDestroyShaderModule" },
        { gfxrecon::format::ApiCall_vkCreatePipelineCache, "ApiCall_vkCreatePipelineCache" },
        { gfxrecon::format::ApiCall_vkDestroyPipelineCache, "ApiCall_vkDestroyPipelineCache" },
        { gfxrecon::format::ApiCall_vkGetPipelineCacheData, "ApiCall_vkGetPipelineCacheData" },
        { gfxrecon::format::ApiCall_vkMergePipelineCaches, "ApiCall_vkMergePipelineCaches" },
        { gfxrecon::format::ApiCall_vkCreateGraphicsPipelines, "ApiCall_vkCreateGraphicsPipelines" },
        { gfxrecon::format::ApiCall_vkCreateComputePipelines, "ApiCall_vkCreateComputePipelines" },
        { gfxrecon::format::ApiCall_vkDestroyPipeline, "ApiCall_vkDestroyPipeline" },
        { gfxrecon::format::ApiCall_vkCreatePipelineLayout, "ApiCall_vkCreatePipelineLayout" },
        { gfxrecon::format::ApiCall_vkDestroyPipelineLayout, "ApiCall_vkDestroyPipelineLayout" },
        { gfxrecon::format::ApiCall_vkCreateSampler, "ApiCall_vkCreateSampler" },
        { gfxrecon::format::ApiCall_vkDestroySampler, "ApiCall_vkDestroySampler" },
        { gfxrecon::format::ApiCall_vkCreateDescriptorSetLayout, "ApiCall_vkCreateDescriptorSetLayout" },
        { gfxrecon::format::ApiCall_vkDestroyDescriptorSetLayout, "ApiCall_vkDestroyDescriptorSetLayout" },
        { gfxrecon::format::ApiCall_vkCreateDescriptorPool, "ApiCall_vkCreateDescriptorPool" },
        { gfxrecon::format::ApiCall_vkDestroyDescriptorPool, "ApiCall_vkDestroyDescriptorPool" },
        { gfxrecon::format::ApiCall_vkResetDescriptorPool, "ApiCall_vkResetDescriptorPool" },
        { gfxrecon::format::ApiCall_vkAllocateDescriptorSets, "ApiCall_vkAllocateDescriptorSets" },
        { gfxrecon::format::ApiCall_vkFreeDescriptorSets, "ApiCall_vkFreeDescriptorSets" },
        { gfxrecon::format::ApiCall_vkUpdateDescriptorSets, "ApiCall_vkUpdateDescriptorSets" },
        { gfxrecon::format::ApiCall_vkCreateFramebuffer, "ApiCall_vkCreateFramebuffer" },
        { gfxrecon::format::ApiCall_vkDestroyFramebuffer, "ApiCall_vkDestroyFramebuffer" },
        { gfxrecon::format::ApiCall_vkCreateRenderPass, "ApiCall_vkCreateRenderPass" },
        { gfxrecon::format::ApiCall_vkDestroyRenderPass, "ApiCall_vkDestroyRenderPass" },
        { gfxrecon::format::ApiCall_vkGetRenderAreaGranularity, "ApiCall_vkGetRenderAreaGranularity" },
        { gfxrecon::format::ApiCall_vkCreateCommandPool, "ApiCall_vkCreateCommandPool" },
        { gfxrecon::format::ApiCall_vkDestroyCommandPool, "ApiCall_vkDestroyCommandPool" },
        { gfxrecon::format::ApiCall_vkResetCommandPool, "ApiCall_vkResetCommandPool" },
        { gfxrecon::format::ApiCall_vkAllocateCommandBuffers, "ApiCall_vkAllocateCommandBuffers" },
        { gfxrecon::format::ApiCall_vkFreeCommandBuffers, "ApiCall_vkFreeCommandBuffers" },
        { gfxrecon::format::ApiCall_vkBeginCommandBuffer, "ApiCall_vkBeginCommandBuffer" },
        { gfxrecon::format::ApiCall_vkEndCommandBuffer, "ApiCall_vkEndCommandBuffer" },
        { gfxrecon::format::ApiCall_vkResetCommandBuffer, "ApiCall_vkResetCommandBuffer" },
        { gfxrecon::format::ApiCall_vkCmdBindPipeline, "ApiCall_vkCmdBindPipeline" },
        { gfxrecon::format::ApiCall_vkCmdSetViewport, "ApiCall_vkCmdSetViewport" },
        { gfxrecon::format::ApiCall_vkCmdSetScissor, "ApiCall_vkCmdSetScissor" },
        { gfxrecon::format::ApiCall_vkCmdSetLineWidth, "ApiCall_vkCmdSetLineWidth" },
        { gfxrecon::format::ApiCall_vkCmdSetDepthBias, "ApiCall_vkCmdSetDepthBias" },
        { gfxrecon::format::ApiCall_vkCmdSetBlendConstants, "ApiCall_vkCmdSetBlendConstants" },
        { gfxrecon::format::ApiCall_vkCmdSetDepthBounds, "ApiCall_vkCmdSetDepthBounds" },
        { gfxrecon::format::ApiCall_vkCmdSetStencilCompareMask, "ApiCall_vkCmdSetStencilCompareMask" },
        { gfxrecon::format::ApiCall_vkCmdSetStencilWriteMask, "ApiCall_vkCmdSetStencilWriteMask" },
        { gfxrecon::format::ApiCall_vkCmdSetStencilReference, "ApiCall_vkCmdSetStencilReference" },
        { gfxrecon::format::ApiCall_vkCmdBindDescriptorSets, "ApiCall_vkCmdBindDescriptorSets" },
        { gfxrecon::format::ApiCall_vkCmdBindIndexBuffer, "ApiCall_vkCmdBindIndexBuffer" },
        { gfxrecon::format::ApiCall_vkCmdBindVertexBuffers, "ApiCall_vkCmdBindVertexBuffers" },
        { gfxrecon::format::ApiCall_vkCmdDraw, "ApiCall_vkCmdDraw" },
        { gfxrecon::format::ApiCall_vkCmdDrawIndexed, "ApiCall_vkCmdDrawIndexed" },
        { gfxrecon::format::ApiCall_vkCmdDrawIndirect, "ApiCall_vkCmdDrawIndirect" },
        { gfxrecon::format::ApiCall_vkCmdDrawIndexedIndirect, "ApiCall_vkCmdDrawIndexedIndirect" },
        { gfxrecon::format::ApiCall_vkCmdDispatch, "ApiCall_vkCmdDispatch" },
        { gfxrecon::format::ApiCall_vkCmdDispatchIndirect, "ApiCall_vkCmdDispatchIndirect" },
        { gfxrecon::format::ApiCall_vkCmdCopyBuffer, "ApiCall_vkCmdCopyBuffer" },
        { gfxrecon::format::ApiCall_vkCmdCopyImage, "ApiCall_vkCmdCopyImage" },
        { gfxrecon::format::ApiCall_vkCmdBlitImage, "ApiCall_vkCmdBlitImage" },
        { gfxrecon::format::ApiCall_vkCmdCopyBufferToImage, "ApiCall_vkCmdCopyBufferToImage" },
        { gfxrecon::format::ApiCall_vkCmdCopyImageToBuffer, "ApiCall_vkCmdCopyImageToBuffer" },
        { gfxrecon::format::ApiCall_vkCmdUpdateBuffer, "ApiCall_vkCmdUpdateBuffer" },
        { gfxrecon::format::ApiCall_vkCmdFillBuffer, "ApiCall_vkCmdFillBuffer" },
        { gfxrecon::format::ApiCall_vkCmdClearColorImage, "ApiCall_vkCmdClearColorImage" },
        { gfxrecon::format::ApiCall_vkCmdClearDepthStencilImage, "ApiCall_vkCmdClearDepthStencilImage" },
        { gfxrecon::format::ApiCall_vkCmdClearAttachments, "ApiCall_vkCmdClearAttachments" },
        { gfxrecon::format::ApiCall_vkCmdResolveImage, "ApiCall_vkCmdResolveImage" },
        { gfxrecon::format::ApiCall_vkCmdSetEvent, "ApiCall_vkCmdSetEvent" },
        { gfxrecon::format::ApiCall_vkCmdResetEvent, "ApiCall_vkCmdResetEvent" },
        { gfxrecon::format::ApiCall_vkCmdWaitEvents, "ApiCall_vkCmdWaitEvents" },
        { gfxrecon::format::ApiCall_vkCmdPipelineBarrier, "ApiCall_vkCmdPipelineBarrier" },
        { gfxrecon::format::ApiCall_vkCmdBeginQuery, "ApiCall_vkCmdBeginQuery" },
        { gfxrecon::format::ApiCall_vkCmdEndQuery, "ApiCall_vkCmdEndQuery" },
        { gfxrecon::format::ApiCall_vkCmdResetQueryPool, "ApiCall_vkCmdResetQueryPool" },
        { gfxrecon::format::ApiCall_vkCmdWriteTimestamp, "ApiCall_vkCmdWriteTimestamp" },
        { gfxrecon::format::ApiCall_vkCmdCopyQueryPoolResults, "ApiCall_vkCmdCopyQueryPoolResults" },
        { gfxrecon::format::ApiCall_vkCmdPushConstants, "ApiCall_vkCmdPushConstants" },
        { gfxrecon::format::ApiCall_vkCmdBeginRenderPass, "ApiCall_vkCmdBeginRenderPass" },
        { gfxrecon::format::ApiCall_vkCmdNextSubpass, "ApiCall_vkCmdNextSubpass" },
        { gfxrecon::format::ApiCall_vkCmdEndRenderPass, "ApiCall_vkCmdEndRenderPass" },
        { gfxrecon::format::ApiCall_vkCmdExecuteCommands, "ApiCall_vkCmdExecuteCommands" },
        { gfxrecon::format::ApiCall_vkEnumerateInstanceVersion, "ApiCall_vkEnumerateInstanceVersion" },
        { gfxrecon::format::ApiCall_vkBindBufferMemory2, "ApiCall_vkBindBufferMemory2" },
        { gfxrecon::format::ApiCall_vkBindImageMemory2, "ApiCall_vkBindImageMemory2" },
        { gfxrecon::format::ApiCall_vkGetDeviceGroupPeerMemoryFeatures, "ApiCall_vkGetDeviceGroupPeerMemoryFeatures" },
        { gfxrecon::format::ApiCall_vkCmdSetDeviceMask, "ApiCall_vkCmdSetDeviceMask" },
        { gfxrecon::format::ApiCall_vkCmdDispatchBase, "ApiCall_vkCmdDispatchBase" },
        { gfxrecon::format::ApiCall_vkEnumeratePhysicalDeviceGroups, "ApiCall_vkEnumeratePhysicalDeviceGroups" },
        { gfxrecon::format::ApiCall_vkGetImageMemoryRequirements2, "ApiCall_vkGetImageMemoryRequirements2" },
        { gfxrecon::format::ApiCall_vkGetBufferMemoryRequirements2, "ApiCall_vkGetBufferMemoryRequirements2" },
        { gfxrecon::format::ApiCall_vkGetImageSparseMemoryRequirements2, "ApiCall_vkGetImageSparseMemoryRequirements2" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceFeatures2, "ApiCall_vkGetPhysicalDeviceFeatures2" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceProperties2, "ApiCall_vkGetPhysicalDeviceProperties2" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceFormatProperties2, "ApiCall_vkGetPhysicalDeviceFormatProperties2" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceImageFormatProperties2, "ApiCall_vkGetPhysicalDeviceImageFormatProperties2" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2, "ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceMemoryProperties2, "ApiCall_vkGetPhysicalDeviceMemoryProperties2" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2, "ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2" },
        { gfxrecon::format::ApiCall_vkTrimCommandPool, "ApiCall_vkTrimCommandPool" },
        { gfxrecon::format::ApiCall_vkGetDeviceQueue2, "ApiCall_vkGetDeviceQueue2" },
        { gfxrecon::format::ApiCall_vkCreateSamplerYcbcrConversion, "ApiCall_vkCreateSamplerYcbcrConversion" },
        { gfxrecon::format::ApiCall_vkDestroySamplerYcbcrConversion, "ApiCall_vkDestroySamplerYcbcrConversion" },
        { gfxrecon::format::ApiCall_vkCreateDescriptorUpdateTemplate, "ApiCall_vkCreateDescriptorUpdateTemplate" },
        { gfxrecon::format::ApiCall_vkDestroyDescriptorUpdateTemplate, "ApiCall_vkDestroyDescriptorUpdateTemplate" },
        { gfxrecon::format::ApiCall_vkUpdateDescriptorSetWithTemplate, "ApiCall_vkUpdateDescriptorSetWithTemplate" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceExternalBufferProperties, "ApiCall_vkGetPhysicalDeviceExternalBufferProperties" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceExternalFenceProperties, "ApiCall_vkGetPhysicalDeviceExternalFenceProperties" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties, "ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties" },
        { gfxrecon::format::ApiCall_vkGetDescriptorSetLayoutSupport, "ApiCall_vkGetDescriptorSetLayoutSupport" },
        { gfxrecon::format::ApiCall_vkDestroySurfaceKHR, "ApiCall_vkDestroySurfaceKHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR, "ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR, "ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR, "ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR, "ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR" },
        { gfxrecon::format::ApiCall_vkCreateSwapchainKHR, "ApiCall_vkCreateSwapchainKHR" },
        { gfxrecon::format::ApiCall_vkDestroySwapchainKHR, "ApiCall_vkDestroySwapchainKHR" },
        { gfxrecon::format::ApiCall_vkGetSwapchainImagesKHR, "ApiCall_vkGetSwapchainImagesKHR" },
        { gfxrecon::format::ApiCall_vkAcquireNextImageKHR, "ApiCall_vkAcquireNextImageKHR" },
        { gfxrecon::format::ApiCall_vkQueuePresentKHR, "ApiCall_vkQueuePresentKHR" },
        { gfxrecon::format::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR, "ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR" },
        { gfxrecon::format::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR, "ApiCall_vkGetDeviceGroupSurfacePresentModesKHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR, "ApiCall_vkGetPhysicalDevicePresentRectanglesKHR" },
        { gfxrecon::format::ApiCall_vkAcquireNextImage2KHR, "ApiCall_vkAcquireNextImage2KHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR, "ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR, "ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR" },
        { gfxrecon::format::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR, "ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR" },
        { gfxrecon::format::ApiCall_vkGetDisplayModePropertiesKHR, "ApiCall_vkGetDisplayModePropertiesKHR" },
        { gfxrecon::format::ApiCall_vkCreateDisplayModeKHR, "ApiCall_vkCreateDisplayModeKHR" },
        { gfxrecon::format::ApiCall_vkGetDisplayPlaneCapabilitiesKHR, "ApiCall_vkGetDisplayPlaneCapabilitiesKHR" },
        { gfxrecon::format::ApiCall_vkCreateDisplayPlaneSurfaceKHR, "ApiCall_vkCreateDisplayPlaneSurfaceKHR" },
        { gfxrecon::format::ApiCall_vkCreateSharedSwapchainsKHR, "ApiCall_vkCreateSharedSwapchainsKHR" },
        { gfxrecon::format::ApiCall_vkCreateXlibSurfaceKHR, "ApiCall_vkCreateXlibSurfaceKHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR, "ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR" },
        { gfxrecon::format::ApiCall_vkCreateXcbSurfaceKHR, "ApiCall_vkCreateXcbSurfaceKHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR, "ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR" },
        { gfxrecon::format::ApiCall_vkCreateWaylandSurfaceKHR, "ApiCall_vkCreateWaylandSurfaceKHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR, "ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR" },
        { gfxrecon::format::ApiCall_vkCreateMirSurfaceKHR, "ApiCall_vkCreateMirSurfaceKHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceMirPresentationSupportKHR, "ApiCall_vkGetPhysicalDeviceMirPresentationSupportKHR" },
        { gfxrecon::format::ApiCall_vkCreateAndroidSurfaceKHR, "ApiCall_vkCreateAndroidSurfaceKHR" },
        { gfxrecon::format::ApiCall_vkCreateWin32SurfaceKHR, "ApiCall_vkCreateWin32SurfaceKHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR, "ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceFeatures2KHR, "ApiCall_vkGetPhysicalDeviceFeatures2KHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceProperties2KHR, "ApiCall_vkGetPhysicalDeviceProperties2KHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR, "ApiCall_vkGetPhysicalDeviceFormatProperties2KHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR, "ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR, "ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR, "ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR, "ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR" },
        { gfxrecon::format::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR, "ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR" },
        { gfxrecon::format::ApiCall_vkCmdSetDeviceMaskKHR, "ApiCall_vkCmdSetDeviceMaskKHR" },
        { gfxrecon::format::ApiCall_vkCmdDispatchBaseKHR, "ApiCall_vkCmdDispatchBaseKHR" },
        { gfxrecon::format::ApiCall_vkTrimCommandPoolKHR, "ApiCall_vkTrimCommandPoolKHR" },
        { gfxrecon::format::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR, "ApiCall_vkEnumeratePhysicalDeviceGroupsKHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR, "ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR" },
        { gfxrecon::format::ApiCall_vkGetMemoryWin32HandleKHR, "ApiCall_vkGetMemoryWin32HandleKHR" },
        { gfxrecon::format::ApiCall_vkGetMemoryWin32HandlePropertiesKHR, "ApiCall_vkGetMemoryWin32HandlePropertiesKHR" },
        { gfxrecon::format::ApiCall_vkGetMemoryFdKHR, "ApiCall_vkGetMemoryFdKHR" },
        { gfxrecon::format::ApiCall_vkGetMemoryFdPropertiesKHR, "ApiCall_vkGetMemoryFdPropertiesKHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR, "ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR" },
        { gfxrecon::format::ApiCall_vkImportSemaphoreWin32HandleKHR, "ApiCall_vkImportSemaphoreWin32HandleKHR" },
        { gfxrecon::format::ApiCall_vkGetSemaphoreWin32HandleKHR, "ApiCall_vkGetSemaphoreWin32HandleKHR" },
        { gfxrecon::format::ApiCall_vkImportSemaphoreFdKHR, "ApiCall_vkImportSemaphoreFdKHR" },
        { gfxrecon::format::ApiCall_vkGetSemaphoreFdKHR, "ApiCall_vkGetSemaphoreFdKHR" },
        { gfxrecon::format::ApiCall_vkCmdPushDescriptorSetKHR, "ApiCall_vkCmdPushDescriptorSetKHR" },
        { gfxrecon::format::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR, "ApiCall_vkCmdPushDescriptorSetWithTemplateKHR" },
        { gfxrecon::format::ApiCall_vkCreateDescriptorUpdateTemplateKHR, "ApiCall_vkCreateDescriptorUpdateTemplateKHR" },
        { gfxrecon::format::ApiCall_vkDestroyDescriptorUpdateTemplateKHR, "ApiCall_vkDestroyDescriptorUpdateTemplateKHR" },
        { gfxrecon::format::ApiCall_vkUpdateDescriptorSetWithTemplateKHR, "ApiCall_vkUpdateDescriptorSetWithTemplateKHR" },
        { gfxrecon::format::ApiCall_vkCreateRenderPass2KHR, "ApiCall_vkCreateRenderPass2KHR" },
        { gfxrecon::format::ApiCall_vkCmdBeginRenderPass2KHR, "ApiCall_vkCmdBeginRenderPass2KHR" },
        { gfxrecon::format::ApiCall_vkCmdNextSubpass2KHR, "ApiCall_vkCmdNextSubpass2KHR" },
        { gfxrecon::format::ApiCall_vkCmdEndRenderPass2KHR, "ApiCall_vkCmdEndRenderPass2KHR" },
        { gfxrecon::format::ApiCall_vkGetSwapchainStatusKHR, "ApiCall_vkGetSwapchainStatusKHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR, "ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR" },
        { gfxrecon::format::ApiCall_vkImportFenceWin32HandleKHR, "ApiCall_vkImportFenceWin32HandleKHR" },
        { gfxrecon::format::ApiCall_vkGetFenceWin32HandleKHR, "ApiCall_vkGetFenceWin32HandleKHR" },
        { gfxrecon::format::ApiCall_vkImportFenceFdKHR, "ApiCall_vkImportFenceFdKHR" },
        { gfxrecon::format::ApiCall_vkGetFenceFdKHR, "ApiCall_vkGetFenceFdKHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR, "ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR, "ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR, "ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR, "ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR" },
        { gfxrecon::format::ApiCall_vkGetDisplayModeProperties2KHR, "ApiCall_vkGetDisplayModeProperties2KHR" },
        { gfxrecon::format::ApiCall_vkGetDisplayPlaneCapabilities2KHR, "ApiCall_vkGetDisplayPlaneCapabilities2KHR" },
        { gfxrecon::format::ApiCall_vkGetImageMemoryRequirements2KHR, "ApiCall_vkGetImageMemoryRequirements2KHR" },
        { gfxrecon::format::ApiCall_vkGetBufferMemoryRequirements2KHR, "ApiCall_vkGetBufferMemoryRequirements2KHR" },
        { gfxrecon::format::ApiCall_vkGetImageSparseMemoryRequirements2KHR, "ApiCall_vkGetImageSparseMemoryRequirements2KHR" },
        { gfxrecon::format::ApiCall_vkCreateSamplerYcbcrConversionKHR, "ApiCall_vkCreateSamplerYcbcrConversionKHR" },
        { gfxrecon::format::ApiCall_vkDestroySamplerYcbcrConversionKHR, "ApiCall_vkDestroySamplerYcbcrConversionKHR" },
        { gfxrecon::format::ApiCall_vkBindBufferMemory2KHR, "ApiCall_vkBindBufferMemory2KHR" },
        { gfxrecon::format::ApiCall_vkBindImageMemory2KHR, "ApiCall_vkBindImageMemory2KHR" },
        { gfxrecon::format::ApiCall_vkGetDescriptorSetLayoutSupportKHR, "ApiCall_vkGetDescriptorSetLayoutSupportKHR" },
        { gfxrecon::format::ApiCall_vkCmdDrawIndirectCountKHR, "ApiCall_vkCmdDrawIndirectCountKHR" },
        { gfxrecon::format::ApiCall_vkCmdDrawIndexedIndirectCountKHR, "ApiCall_vkCmdDrawIndexedIndirectCountKHR" },
        { gfxrecon::format::ApiCall_vkCreateDebugReportCallbackEXT, "ApiCall_vkCreateDebugReportCallbackEXT" },
        { gfxrecon::format::ApiCall_vkDestroyDebugReportCallbackEXT, "ApiCall_vkDestroyDebugReportCallbackEXT" },
        { gfxrecon::format::ApiCall_vkDebugReportMessageEXT, "ApiCall_vkDebugReportMessageEXT" },
        { gfxrecon::format::ApiCall_vkDebugMarkerSetObjectTagEXT, "ApiCall_vkDebugMarkerSetObjectTagEXT" },
        { gfxrecon::format::ApiCall_vkDebugMarkerSetObjectNameEXT, "ApiCall_vkDebugMarkerSetObjectNameEXT" },
        { gfxrecon::format::ApiCall_vkCmdDebugMarkerBeginEXT, "ApiCall_vkCmdDebugMarkerBeginEXT" },
        { gfxrecon::format::ApiCall_vkCmdDebugMarkerEndEXT, "ApiCall_vkCmdDebugMarkerEndEXT" },
        { gfxrecon::format::ApiCall_vkCmdDebugMarkerInsertEXT, "ApiCall_vkCmdDebugMarkerInsertEXT" },
        { gfxrecon::format::ApiCall_vkCmdDrawIndirectCountAMD, "ApiCall_vkCmdDrawIndirectCountAMD" },
        { gfxrecon::format::ApiCall_vkCmdDrawIndexedIndirectCountAMD, "ApiCall_vkCmdDrawIndexedIndirectCountAMD" },
        { gfxrecon::format::ApiCall_vkGetShaderInfoAMD, "ApiCall_vkGetShaderInfoAMD" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV, "ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV" },
        { gfxrecon::format::ApiCall_vkGetMemoryWin32HandleNV, "ApiCall_vkGetMemoryWin32HandleNV" },
        { gfxrecon::format::ApiCall_vkCreateViSurfaceNN, "ApiCall_vkCreateViSurfaceNN" },
        { gfxrecon::format::ApiCall_vkCmdBeginConditionalRenderingEXT, "ApiCall_vkCmdBeginConditionalRenderingEXT" },
        { gfxrecon::format::ApiCall_vkCmdEndConditionalRenderingEXT, "ApiCall_vkCmdEndConditionalRenderingEXT" },
        { gfxrecon::format::ApiCall_vkCmdProcessCommandsNVX, "ApiCall_vkCmdProcessCommandsNVX" },
        { gfxrecon::format::ApiCall_vkCmdReserveSpaceForCommandsNVX, "ApiCall_vkCmdReserveSpaceForCommandsNVX" },
        { gfxrecon::format::ApiCall_vkCreateIndirectCommandsLayoutNVX, "ApiCall_vkCreateIndirectCommandsLayoutNVX" },
        { gfxrecon::format::ApiCall_vkDestroyIndirectCommandsLayoutNVX, "ApiCall_vkDestroyIndirectCommandsLayoutNVX" },
        { gfxrecon::format::ApiCall_vkCreateObjectTableNVX, "ApiCall_vkCreateObjectTableNVX" },
        { gfxrecon::format::ApiCall_vkDestroyObjectTableNVX, "ApiCall_vkDestroyObjectTableNVX" },
        { gfxrecon::format::ApiCall_vkRegisterObjectsNVX, "ApiCall_vkRegisterObjectsNVX" },
        { gfxrecon::format::ApiCall_vkUnregisterObjectsNVX, "ApiCall_vkUnregisterObjectsNVX" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX, "ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX" },
        { gfxrecon::format::ApiCall_vkCmdSetViewportWScalingNV, "ApiCall_vkCmdSetViewportWScalingNV" },
        { gfxrecon::format::ApiCall_vkReleaseDisplayEXT, "ApiCall_vkReleaseDisplayEXT" },
        { gfxrecon::format::ApiCall_vkAcquireXlibDisplayEXT, "ApiCall_vkAcquireXlibDisplayEXT" },
        { gfxrecon::format::ApiCall_vkGetRandROutputDisplayEXT, "ApiCall_vkGetRandROutputDisplayEXT" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT, "ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT" },
        { gfxrecon::format::ApiCall_vkDisplayPowerControlEXT, "ApiCall_vkDisplayPowerControlEXT" },
        { gfxrecon::format::ApiCall_vkRegisterDeviceEventEXT, "ApiCall_vkRegisterDeviceEventEXT" },
        { gfxrecon::format::ApiCall_vkRegisterDisplayEventEXT, "ApiCall_vkRegisterDisplayEventEXT" },
        { gfxrecon::format::ApiCall_vkGetSwapchainCounterEXT, "ApiCall_vkGetSwapchainCounterEXT" },
        { gfxrecon::format::ApiCall_vkGetRefreshCycleDurationGOOGLE, "ApiCall_vkGetRefreshCycleDurationGOOGLE" },
        { gfxrecon::format::ApiCall_vkGetPastPresentationTimingGOOGLE, "ApiCall_vkGetPastPresentationTimingGOOGLE" },
        { gfxrecon::format::ApiCall_vkCmdSetDiscardRectangleEXT, "ApiCall_vkCmdSetDiscardRectangleEXT" },
        { gfxrecon::format::ApiCall_vkSetHdrMetadataEXT, "ApiCall_vkSetHdrMetadataEXT" },
        { gfxrecon::format::ApiCall_vkCreateIOSSurfaceMVK, "ApiCall_vkCreateIOSSurfaceMVK" },
        { gfxrecon::format::ApiCall_vkCreateMacOSSurfaceMVK, "ApiCall_vkCreateMacOSSurfaceMVK" },
        { gfxrecon::format::ApiCall_vkSetDebugUtilsObjectNameEXT, "ApiCall_vkSetDebugUtilsObjectNameEXT" },
        { gfxrecon::format::ApiCall_vkSetDebugUtilsObjectTagEXT, "ApiCall_vkSetDebugUtilsObjectTagEXT" },
        { gfxrecon::format::ApiCall_vkQueueBeginDebugUtilsLabelEXT, "ApiCall_vkQueueBeginDebugUtilsLabelEXT" },
        { gfxrecon::format::ApiCall_vkQueueEndDebugUtilsLabelEXT, "ApiCall_vkQueueEndDebugUtilsLabelEXT" },
        { gfxrecon::format::ApiCall_vkQueueInsertDebugUtilsLabelEXT, "ApiCall_vkQueueInsertDebugUtilsLabelEXT" },
        { gfxrecon::format::ApiCall_vkCmdBeginDebugUtilsLabelEXT, "ApiCall_vkCmdBeginDebugUtilsLabelEXT" },
        { gfxrecon::format::ApiCall_vkCmdEndDebugUtilsLabelEXT, "ApiCall_vkCmdEndDebugUtilsLabelEXT" },
        { gfxrecon::format::ApiCall_vkCmdInsertDebugUtilsLabelEXT, "ApiCall_vkCmdInsertDebugUtilsLabelEXT" },
        { gfxrecon::format::ApiCall_vkCreateDebugUtilsMessengerEXT, "ApiCall_vkCreateDebugUtilsMessengerEXT" },
        { gfxrecon::format::ApiCall_vkDestroyDebugUtilsMessengerEXT, "ApiCall_vkDestroyDebugUtilsMessengerEXT" },
        { gfxrecon::format::ApiCall_vkSubmitDebugUtilsMessageEXT, "ApiCall_vkSubmitDebugUtilsMessageEXT" },
        { gfxrecon::format::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID, "ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID" },
        { gfxrecon::format::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID, "ApiCall_vkGetMemoryAndroidHardwareBufferANDROID" },
        { gfxrecon::format::ApiCall_vkCmdSetSampleLocationsEXT, "ApiCall_vkCmdSetSampleLocationsEXT" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT, "ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT" },
        { gfxrecon::format::ApiCall_vkCreateValidationCacheEXT, "ApiCall_vkCreateValidationCacheEXT" },
        { gfxrecon::format::ApiCall_vkDestroyValidationCacheEXT, "ApiCall_vkDestroyValidationCacheEXT" },
        { gfxrecon::format::ApiCall_vkMergeValidationCachesEXT, "ApiCall_vkMergeValidationCachesEXT" },
        { gfxrecon::format::ApiCall_vkGetValidationCacheDataEXT, "ApiCall_vkGetValidationCacheDataEXT" },
        { gfxrecon::format::ApiCall_vkGetMemoryHostPointerPropertiesEXT, "ApiCall_vkGetMemoryHostPointerPropertiesEXT" },
        { gfxrecon::format::ApiCall_vkCmdWriteBufferMarkerAMD, "ApiCall_vkCmdWriteBufferMarkerAMD" },
        { gfxrecon::format::ApiCall_vkCmdBindShadingRateImageNV, "ApiCall_vkCmdBindShadingRateImageNV" },
        { gfxrecon::format::ApiCall_vkCmdSetViewportShadingRatePaletteNV, "ApiCall_vkCmdSetViewportShadingRatePaletteNV" },
        { gfxrecon::format::ApiCall_vkCmdSetCoarseSampleOrderNV, "ApiCall_vkCmdSetCoarseSampleOrderNV" },
        { gfxrecon::format::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT, "ApiCall_vkGetImageDrmFormatModifierPropertiesEXT" },
        { gfxrecon::format::ApiCall_vkCreateAccelerationStructureNV, "ApiCall_vkCreateAccelerationStructureNV" },
        { gfxrecon::format::ApiCall_vkDestroyAccelerationStructureNV, "ApiCall_vkDestroyAccelerationStructureNV" },
        { gfxrecon::format::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV, "ApiCall_vkGetAccelerationStructureMemoryRequirementsNV" },
        { gfxrecon::format::ApiCall_vkBindAccelerationStructureMemoryNV, "ApiCall_vkBindAccelerationStructureMemoryNV" },
        { gfxrecon::format::ApiCall_vkCmdBuildAccelerationStructureNV, "ApiCall_vkCmdBuildAccelerationStructureNV" },
        { gfxrecon::format::ApiCall_vkCmdCopyAccelerationStructureNV, "ApiCall_vkCmdCopyAccelerationStructureNV" },
        { gfxrecon::format::ApiCall_vkCmdTraceRaysNV, "ApiCall_vkCmdTraceRaysNV" },
        { gfxrecon::format::ApiCall_vkCreateRayTracingPipelinesNV, "ApiCall_vkCreateRayTracingPipelinesNV" },
        { gfxrecon::format::ApiCall_vkGetRayTracingShaderGroupHandlesNV, "ApiCall_vkGetRayTracingShaderGroupHandlesNV" },
        { gfxrecon::format::ApiCall_vkGetAccelerationStructureHandleNV, "ApiCall_vkGetAccelerationStructureHandleNV" },
        { gfxrecon::format::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV, "ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV" },
        { gfxrecon::format::ApiCall_vkCompileDeferredNV, "ApiCall_vkCompileDeferredNV" },
        { gfxrecon::format::ApiCall_vkCmdDrawMeshTasksNV, "ApiCall_vkCmdDrawMeshTasksNV" },
        { gfxrecon::format::ApiCall_vkCmdDrawMeshTasksIndirectNV, "ApiCall_vkCmdDrawMeshTasksIndirectNV" },
        { gfxrecon::format::ApiCall_vkCmdDrawMeshTasksIndirectCountNV, "ApiCall_vkCmdDrawMeshTasksIndirectCountNV" },
        { gfxrecon::format::ApiCall_vkCmdSetExclusiveScissorNV, "ApiCall_vkCmdSetExclusiveScissorNV" },
        { gfxrecon::format::ApiCall_vkCmdSetCheckpointNV, "ApiCall_vkCmdSetCheckpointNV" },
        { gfxrecon::format::ApiCall_vkGetQueueCheckpointDataNV, "ApiCall_vkGetQueueCheckpointDataNV" },
        { gfxrecon::format::ApiCall_vkCreateImagePipeSurfaceFUCHSIA, "ApiCall_vkCreateImagePipeSurfaceFUCHSIA" },
        { gfxrecon::format::ApiCall_vkCmdBindTransformFeedbackBuffersEXT, "ApiCall_vkCmdBindTransformFeedbackBuffersEXT" },
        { gfxrecon::format::ApiCall_vkCmdBeginTransformFeedbackEXT, "ApiCall_vkCmdBeginTransformFeedbackEXT" },
        { gfxrecon::format::ApiCall_vkCmdEndTransformFeedbackEXT, "ApiCall_vkCmdEndTransformFeedbackEXT" },
        { gfxrecon::format::ApiCall_vkCmdBeginQueryIndexedEXT, "ApiCall_vkCmdBeginQueryIndexedEXT" },
        { gfxrecon::format::ApiCall_vkCmdEndQueryIndexedEXT, "ApiCall_vkCmdEndQueryIndexedEXT" },
        { gfxrecon::format::ApiCall_vkCmdDrawIndirectByteCountEXT, "ApiCall_vkCmdDrawIndirectByteCountEXT" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT, "ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT" },
        { gfxrecon::format::ApiCall_vkGetCalibratedTimestampsEXT, "ApiCall_vkGetCalibratedTimestampsEXT" },
        { gfxrecon::format::ApiCall_vkGetBufferDeviceAddressEXT, "ApiCall_vkGetBufferDeviceAddressEXT" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV, "ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV" },
        { gfxrecon::format::ApiCall_vkGetImageViewHandleNVX, "ApiCall_vkGetImageViewHandleNVX" },
        { gfxrecon::format::ApiCall_vkCreateMetalSurfaceEXT, "ApiCall_vkCreateMetalSurfaceEXT" },
        { gfxrecon::format::ApiCall_vkCreateStreamDescriptorSurfaceGGP, "ApiCall_vkCreateStreamDescriptorSurfaceGGP" },
        { gfxrecon::format::ApiCall_vkSetLocalDimmingAMD, "ApiCall_vkSetLocalDimmingAMD" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV, "ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT, "ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT" },
        { gfxrecon::format::ApiCall_vkAcquireFullScreenExclusiveModeEXT, "ApiCall_vkAcquireFullScreenExclusiveModeEXT" },
        { gfxrecon::format::ApiCall_vkReleaseFullScreenExclusiveModeEXT, "ApiCall_vkReleaseFullScreenExclusiveModeEXT" },
        { gfxrecon::format::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT, "ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT" },
        { gfxrecon::format::ApiCall_vkCreateHeadlessSurfaceEXT, "ApiCall_vkCreateHeadlessSurfaceEXT" },
        { gfxrecon::format::ApiCall_vkResetQueryPoolEXT, "ApiCall_vkResetQueryPoolEXT" },
        { gfxrecon::format::ApiCall_vkGetPipelineExecutablePropertiesKHR, "ApiCall_vkGetPipelineExecutablePropertiesKHR" },
        { gfxrecon::format::ApiCall_vkGetPipelineExecutableStatisticsKHR, "ApiCall_vkGetPipelineExecutableStatisticsKHR" },
        { gfxrecon::format::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR, "ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR" },
        { gfxrecon::format::ApiCall_vkInitializePerformanceApiINTEL, "ApiCall_vkInitializePerformanceApiINTEL" },
        { gfxrecon::format::ApiCall_vkUninitializePerformanceApiINTEL, "ApiCall_vkUninitializePerformanceApiINTEL" },
        { gfxrecon::format::ApiCall_vkCmdSetPerformanceMarkerINTEL, "ApiCall_vkCmdSetPerformanceMarkerINTEL" },
        { gfxrecon::format::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL, "ApiCall_vkCmdSetPerformanceStreamMarkerINTEL" },
        { gfxrecon::format::ApiCall_vkCmdSetPerformanceOverrideINTEL, "ApiCall_vkCmdSetPerformanceOverrideINTEL" },
        { gfxrecon::format::ApiCall_vkAcquirePerformanceConfigurationINTEL, "ApiCall_vkAcquirePerformanceConfigurationINTEL" },
        { gfxrecon::format::ApiCall_vkReleasePerformanceConfigurationINTEL, "ApiCall_vkReleasePerformanceConfigurationINTEL" },
        { gfxrecon::format::ApiCall_vkQueueSetPerformanceConfigurationINTEL, "ApiCall_vkQueueSetPerformanceConfigurationINTEL" },
        { gfxrecon::format::ApiCall_vkGetPerformanceParameterINTEL, "ApiCall_vkGetPerformanceParameterINTEL" },
        { gfxrecon::format::ApiCall_vkCmdSetLineStippleEXT, "ApiCall_vkCmdSetLineStippleEXT" },
        { gfxrecon::format::ApiCall_vkGetSemaphoreCounterValueKHR, "ApiCall_vkGetSemaphoreCounterValueKHR" },
        { gfxrecon::format::ApiCall_vkWaitSemaphoresKHR, "ApiCall_vkWaitSemaphoresKHR" },
        { gfxrecon::format::ApiCall_vkSignalSemaphoreKHR, "ApiCall_vkSignalSemaphoreKHR" },
        { gfxrecon::format::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR, "ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR, "ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR" },
        { gfxrecon::format::ApiCall_vkAcquireProfilingLockKHR, "ApiCall_vkAcquireProfilingLockKHR" },
        { gfxrecon::format::ApiCall_vkReleaseProfilingLockKHR, "ApiCall_vkReleaseProfilingLockKHR" },
        { gfxrecon::format::ApiCall_vkGetBufferDeviceAddressKHR, "ApiCall_vkGetBufferDeviceAddressKHR" },
        { gfxrecon::format::ApiCall_vkGetBufferOpaqueCaptureAddressKHR, "ApiCall_vkGetBufferOpaqueCaptureAddressKHR" },
        { gfxrecon::format::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR, "ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT, "ApiCall_vkGetPhysicalDeviceToolPropertiesEXT" },
        { gfxrecon::format::ApiCall_vkCmdDrawIndirectCount, "ApiCall_vkCmdDrawIndirectCount" },
        { gfxrecon::format::ApiCall_vkCmdDrawIndexedIndirectCount, "ApiCall_vkCmdDrawIndexedIndirectCount" },
        { gfxrecon::format::ApiCall_vkCreateRenderPass2, "ApiCall_vkCreateRenderPass2" },
        { gfxrecon::format::ApiCall_vkCmdBeginRenderPass2, "ApiCall_vkCmdBeginRenderPass2" },
        { gfxrecon::format::ApiCall_vkCmdNextSubpass2, "ApiCall_vkCmdNextSubpass2" },
        { gfxrecon::format::ApiCall_vkCmdEndRenderPass2, "ApiCall_vkCmdEndRenderPass2" },
        { gfxrecon::format::ApiCall_vkResetQueryPool, "ApiCall_vkResetQueryPool" },
        { gfxrecon::format::ApiCall_vkGetSemaphoreCounterValue, "ApiCall_vkGetSemaphoreCounterValue" },
        { gfxrecon::format::ApiCall_vkWaitSemaphores, "ApiCall_vkWaitSemaphores" },
        { gfxrecon::format::ApiCall_vkSignalSemaphore, "ApiCall_vkSignalSemaphore" },
        { gfxrecon::format::ApiCall_vkGetBufferDeviceAddress, "ApiCall_vkGetBufferDeviceAddress" },
        { gfxrecon::format::ApiCall_vkGetBufferOpaqueCaptureAddress, "ApiCall_vkGetBufferOpaqueCaptureAddress" },
        { gfxrecon::format::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress, "ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress" },
        { gfxrecon::format::ApiCall_vkCreateDeferredOperationKHR, "ApiCall_vkCreateDeferredOperationKHR" },
        { gfxrecon::format::ApiCall_vkDestroyDeferredOperationKHR, "ApiCall_vkDestroyDeferredOperationKHR" },
        { gfxrecon::format::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR, "ApiCall_vkGetDeferredOperationMaxConcurrencyKHR" },
        { gfxrecon::format::ApiCall_vkGetDeferredOperationResultKHR, "ApiCall_vkGetDeferredOperationResultKHR" },
        { gfxrecon::format::ApiCall_vkDeferredOperationJoinKHR, "ApiCall_vkDeferredOperationJoinKHR" },
        { gfxrecon::format::ApiCall_vkCreateAccelerationStructureKHR, "ApiCall_vkCreateAccelerationStructureKHR" },
        { gfxrecon::format::ApiCall_vkDestroyAccelerationStructureKHR, "ApiCall_vkDestroyAccelerationStructureKHR" },
        { gfxrecon::format::ApiCall_vkGetAccelerationStructureMemoryRequirementsKHR, "ApiCall_vkGetAccelerationStructureMemoryRequirementsKHR" },
        { gfxrecon::format::ApiCall_vkBindAccelerationStructureMemoryKHR, "ApiCall_vkBindAccelerationStructureMemoryKHR" },
        { gfxrecon::format::ApiCall_vkCmdBuildAccelerationStructuresKHR, "ApiCall_vkCmdBuildAccelerationStructuresKHR" },
        { gfxrecon::format::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR, "ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR" },
        { gfxrecon::format::ApiCall_vkBuildAccelerationStructuresKHR, "ApiCall_vkBuildAccelerationStructuresKHR" },
        { gfxrecon::format::ApiCall_vkCopyAccelerationStructureKHR, "ApiCall_vkCopyAccelerationStructureKHR" },
        { gfxrecon::format::ApiCall_vkCopyAccelerationStructureToMemoryKHR, "ApiCall_vkCopyAccelerationStructureToMemoryKHR" },
        { gfxrecon::format::ApiCall_vkCopyMemoryToAccelerationStructureKHR, "ApiCall_vkCopyMemoryToAccelerationStructureKHR" },
        { gfxrecon::format::ApiCall_vkWriteAccelerationStructuresPropertiesKHR, "ApiCall_vkWriteAccelerationStructuresPropertiesKHR" },
        { gfxrecon::format::ApiCall_vkCmdCopyAccelerationStructureKHR, "ApiCall_vkCmdCopyAccelerationStructureKHR" },
        { gfxrecon::format::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR, "ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR" },
        { gfxrecon::format::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR, "ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR" },
        { gfxrecon::format::ApiCall_vkCmdTraceRaysKHR, "ApiCall_vkCmdTraceRaysKHR" },
        { gfxrecon::format::ApiCall_vkCreateRayTracingPipelinesKHR, "ApiCall_vkCreateRayTracingPipelinesKHR" },
        { gfxrecon::format::ApiCall_vkGetRayTracingShaderGroupHandlesKHR, "ApiCall_vkGetRayTracingShaderGroupHandlesKHR" },
        { gfxrecon::format::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR, "ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR" },
        { gfxrecon::format::ApiCall_vkGetAccelerationStructureDeviceAddressKHR, "ApiCall_vkGetAccelerationStructureDeviceAddressKHR" },
        { gfxrecon::format::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR, "ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR" },
        { gfxrecon::format::ApiCall_vkCmdTraceRaysIndirectKHR, "ApiCall_vkCmdTraceRaysIndirectKHR" },
        { gfxrecon::format::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR, "ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR" },
        { gfxrecon::format::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV, "ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV" },
        { gfxrecon::format::ApiCall_vkCmdPreprocessGeneratedCommandsNV, "ApiCall_vkCmdPreprocessGeneratedCommandsNV" },
        { gfxrecon::format::ApiCall_vkCmdExecuteGeneratedCommandsNV, "ApiCall_vkCmdExecuteGeneratedCommandsNV" },
        { gfxrecon::format::ApiCall_vkCmdBindPipelineShaderGroupNV, "ApiCall_vkCmdBindPipelineShaderGroupNV" },
        { gfxrecon::format::ApiCall_vkCreateIndirectCommandsLayoutNV, "ApiCall_vkCreateIndirectCommandsLayoutNV" },
        { gfxrecon::format::ApiCall_vkDestroyIndirectCommandsLayoutNV, "ApiCall_vkDestroyIndirectCommandsLayoutNV" },
        { gfxrecon::format::ApiCall_vkGetImageViewAddressNVX, "ApiCall_vkGetImageViewAddressNVX" },
        { gfxrecon::format::ApiCall_vkCreatePrivateDataSlotEXT, "ApiCall_vkCreatePrivateDataSlotEXT" },
        { gfxrecon::format::ApiCall_vkDestroyPrivateDataSlotEXT, "ApiCall_vkDestroyPrivateDataSlotEXT" },
        { gfxrecon::format::ApiCall_vkSetPrivateDataEXT, "ApiCall_vkSetPrivateDataEXT" },
        { gfxrecon::format::ApiCall_vkGetPrivateDataEXT, "ApiCall_vkGetPrivateDataEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetCullModeEXT, "ApiCall_vkCmdSetCullModeEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetFrontFaceEXT, "ApiCall_vkCmdSetFrontFaceEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetPrimitiveTopologyEXT, "ApiCall_vkCmdSetPrimitiveTopologyEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetViewportWithCountEXT, "ApiCall_vkCmdSetViewportWithCountEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetScissorWithCountEXT, "ApiCall_vkCmdSetScissorWithCountEXT" },
        { gfxrecon::format::ApiCall_vkCmdBindVertexBuffers2EXT, "ApiCall_vkCmdBindVertexBuffers2EXT" },
        { gfxrecon::format::ApiCall_vkCmdSetDepthTestEnableEXT, "ApiCall_vkCmdSetDepthTestEnableEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetDepthWriteEnableEXT, "ApiCall_vkCmdSetDepthWriteEnableEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetDepthCompareOpEXT, "ApiCall_vkCmdSetDepthCompareOpEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetDepthBoundsTestEnableEXT, "ApiCall_vkCmdSetDepthBoundsTestEnableEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetStencilTestEnableEXT, "ApiCall_vkCmdSetStencilTestEnableEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetStencilOpEXT, "ApiCall_vkCmdSetStencilOpEXT" },
        { gfxrecon::format::ApiCall_vkCreateDirectFBSurfaceEXT, "ApiCall_vkCreateDirectFBSurfaceEXT" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT, "ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT" },
        { gfxrecon::format::ApiCall_vkCmdCopyBuffer2KHR, "ApiCall_vkCmdCopyBuffer2KHR" },
        { gfxrecon::format::ApiCall_vkCmdCopyImage2KHR, "ApiCall_vkCmdCopyImage2KHR" },
        { gfxrecon::format::ApiCall_vkCmdCopyBufferToImage2KHR, "ApiCall_vkCmdCopyBufferToImage2KHR" },
        { gfxrecon::format::ApiCall_vkCmdCopyImageToBuffer2KHR, "ApiCall_vkCmdCopyImageToBuffer2KHR" },
        { gfxrecon::format::ApiCall_vkCmdBlitImage2KHR, "ApiCall_vkCmdBlitImage2KHR" },
        { gfxrecon::format::ApiCall_vkCmdResolveImage2KHR, "ApiCall_vkCmdResolveImage2KHR" },
        { gfxrecon::format::ApiCall_vkGetAccelerationStructureBuildSizesKHR, "ApiCall_vkGetAccelerationStructureBuildSizesKHR" },
        { gfxrecon::format::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR, "ApiCall_vkGetRayTracingShaderGroupStackSizeKHR" },
        { gfxrecon::format::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR, "ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR, "ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR" },
        { gfxrecon::format::ApiCall_vkCmdSetFragmentShadingRateKHR, "ApiCall_vkCmdSetFragmentShadingRateKHR" },
        { gfxrecon::format::ApiCall_vkCmdSetFragmentShadingRateEnumNV, "ApiCall_vkCmdSetFragmentShadingRateEnumNV" },
        { gfxrecon::format::ApiCall_vkAcquireWinrtDisplayNV, "ApiCall_vkAcquireWinrtDisplayNV" },
        { gfxrecon::format::ApiCall_vkGetWinrtDisplayNV, "ApiCall_vkGetWinrtDisplayNV" },
        { gfxrecon::format::ApiCall_vkCmdSetEvent2KHR, "ApiCall_vkCmdSetEvent2KHR" },
        { gfxrecon::format::ApiCall_vkCmdResetEvent2KHR, "ApiCall_vkCmdResetEvent2KHR" },
        { gfxrecon::format::ApiCall_vkCmdWaitEvents2KHR, "ApiCall_vkCmdWaitEvents2KHR" },
        { gfxrecon::format::ApiCall_vkCmdPipelineBarrier2KHR, "ApiCall_vkCmdPipelineBarrier2KHR" },
        { gfxrecon::format::ApiCall_vkCmdWriteTimestamp2KHR, "ApiCall_vkCmdWriteTimestamp2KHR" },
        { gfxrecon::format::ApiCall_vkQueueSubmit2KHR, "ApiCall_vkQueueSubmit2KHR" },
        { gfxrecon::format::ApiCall_vkCmdWriteBufferMarker2AMD, "ApiCall_vkCmdWriteBufferMarker2AMD" },
        { gfxrecon::format::ApiCall_vkGetQueueCheckpointData2NV, "ApiCall_vkGetQueueCheckpointData2NV" },
        { gfxrecon::format::ApiCall_vkCmdSetVertexInputEXT, "ApiCall_vkCmdSetVertexInputEXT" },
        { gfxrecon::format::ApiCall_vkGetMemoryZirconHandleFUCHSIA, "ApiCall_vkGetMemoryZirconHandleFUCHSIA" },
        { gfxrecon::format::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA, "ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA" },
        { gfxrecon::format::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA, "ApiCall_vkImportSemaphoreZirconHandleFUCHSIA" },
        { gfxrecon::format::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA, "ApiCall_vkGetSemaphoreZirconHandleFUCHSIA" },
        { gfxrecon::format::ApiCall_vkCmdSetPatchControlPointsEXT, "ApiCall_vkCmdSetPatchControlPointsEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetRasterizerDiscardEnableEXT, "ApiCall_vkCmdSetRasterizerDiscardEnableEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetDepthBiasEnableEXT, "ApiCall_vkCmdSetDepthBiasEnableEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetLogicOpEXT, "ApiCall_vkCmdSetLogicOpEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetPrimitiveRestartEnableEXT, "ApiCall_vkCmdSetPrimitiveRestartEnableEXT" },
        { gfxrecon::format::ApiCall_vkCreateScreenSurfaceQNX, "ApiCall_vkCreateScreenSurfaceQNX" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX, "ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX" },
        { gfxrecon::format::ApiCall_vkCmdSetColorWriteEnableEXT, "ApiCall_vkCmdSetColorWriteEnableEXT" },
        { gfxrecon::format::ApiCall_vkAcquireDrmDisplayEXT, "ApiCall_vkAcquireDrmDisplayEXT" },
        { gfxrecon::format::ApiCall_vkGetDrmDisplayEXT, "ApiCall_vkGetDrmDisplayEXT" },
        { gfxrecon::format::ApiCall_vkCmdDrawMultiEXT, "ApiCall_vkCmdDrawMultiEXT" },
        { gfxrecon::format::ApiCall_vkCmdDrawMultiIndexedEXT, "ApiCall_vkCmdDrawMultiIndexedEXT" },
        { gfxrecon::format::ApiCall_vkWaitForPresentKHR, "ApiCall_vkWaitForPresentKHR" },
        { gfxrecon::format::ApiCall_vkCmdBindInvocationMaskHUAWEI, "ApiCall_vkCmdBindInvocationMaskHUAWEI" },
        { gfxrecon::format::ApiCall_vkGetMemoryRemoteAddressNV, "ApiCall_vkGetMemoryRemoteAddressNV" },
        { gfxrecon::format::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR, "ApiCall_vkGetDeviceBufferMemoryRequirementsKHR" },
        { gfxrecon::format::ApiCall_vkGetDeviceImageMemoryRequirementsKHR, "ApiCall_vkGetDeviceImageMemoryRequirementsKHR" },
        { gfxrecon::format::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR, "ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR" },
        { gfxrecon::format::ApiCall_vkSetDeviceMemoryPriorityEXT, "ApiCall_vkSetDeviceMemoryPriorityEXT" },
        { gfxrecon::format::ApiCall_vkCmdBeginRenderingKHR, "ApiCall_vkCmdBeginRenderingKHR" },
        { gfxrecon::format::ApiCall_vkCmdEndRenderingKHR, "ApiCall_vkCmdEndRenderingKHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceToolProperties, "ApiCall_vkGetPhysicalDeviceToolProperties" },
        { gfxrecon::format::ApiCall_vkCreatePrivateDataSlot, "ApiCall_vkCreatePrivateDataSlot" },
        { gfxrecon::format::ApiCall_vkDestroyPrivateDataSlot, "ApiCall_vkDestroyPrivateDataSlot" },
        { gfxrecon::format::ApiCall_vkSetPrivateData, "ApiCall_vkSetPrivateData" },
        { gfxrecon::format::ApiCall_vkGetPrivateData, "ApiCall_vkGetPrivateData" },
        { gfxrecon::format::ApiCall_vkCmdSetEvent2, "ApiCall_vkCmdSetEvent2" },
        { gfxrecon::format::ApiCall_vkCmdResetEvent2, "ApiCall_vkCmdResetEvent2" },
        { gfxrecon::format::ApiCall_vkCmdWaitEvents2, "ApiCall_vkCmdWaitEvents2" },
        { gfxrecon::format::ApiCall_vkCmdPipelineBarrier2, "ApiCall_vkCmdPipelineBarrier2" },
        { gfxrecon::format::ApiCall_vkCmdWriteTimestamp2, "ApiCall_vkCmdWriteTimestamp2" },
        { gfxrecon::format::ApiCall_vkQueueSubmit2, "ApiCall_vkQueueSubmit2" },
        { gfxrecon::format::ApiCall_vkCmdCopyBuffer2, "ApiCall_vkCmdCopyBuffer2" },
        { gfxrecon::format::ApiCall_vkCmdCopyImage2, "ApiCall_vkCmdCopyImage2" },
        { gfxrecon::format::ApiCall_vkCmdCopyBufferToImage2, "ApiCall_vkCmdCopyBufferToImage2" },
        { gfxrecon::format::ApiCall_vkCmdCopyImageToBuffer2, "ApiCall_vkCmdCopyImageToBuffer2" },
        { gfxrecon::format::ApiCall_vkCmdBlitImage2, "ApiCall_vkCmdBlitImage2" },
        { gfxrecon::format::ApiCall_vkCmdResolveImage2, "ApiCall_vkCmdResolveImage2" },
        { gfxrecon::format::ApiCall_vkCmdBeginRendering, "ApiCall_vkCmdBeginRendering" },
        { gfxrecon::format::ApiCall_vkCmdEndRendering, "ApiCall_vkCmdEndRendering" },
        { gfxrecon::format::ApiCall_vkCmdSetCullMode, "ApiCall_vkCmdSetCullMode" },
        { gfxrecon::format::ApiCall_vkCmdSetFrontFace, "ApiCall_vkCmdSetFrontFace" },
        { gfxrecon::format::ApiCall_vkCmdSetPrimitiveTopology, "ApiCall_vkCmdSetPrimitiveTopology" },
        { gfxrecon::format::ApiCall_vkCmdSetViewportWithCount, "ApiCall_vkCmdSetViewportWithCount" },
        { gfxrecon::format::ApiCall_vkCmdSetScissorWithCount, "ApiCall_vkCmdSetScissorWithCount" },
        { gfxrecon::format::ApiCall_vkCmdBindVertexBuffers2, "ApiCall_vkCmdBindVertexBuffers2" },
        { gfxrecon::format::ApiCall_vkCmdSetDepthTestEnable, "ApiCall_vkCmdSetDepthTestEnable" },
        { gfxrecon::format::ApiCall_vkCmdSetDepthWriteEnable, "ApiCall_vkCmdSetDepthWriteEnable" },
        { gfxrecon::format::ApiCall_vkCmdSetDepthCompareOp, "ApiCall_vkCmdSetDepthCompareOp" },
        { gfxrecon::format::ApiCall_vkCmdSetDepthBoundsTestEnable, "ApiCall_vkCmdSetDepthBoundsTestEnable" },
        { gfxrecon::format::ApiCall_vkCmdSetStencilTestEnable, "ApiCall_vkCmdSetStencilTestEnable" },
        { gfxrecon::format::ApiCall_vkCmdSetStencilOp, "ApiCall_vkCmdSetStencilOp" },
        { gfxrecon::format::ApiCall_vkCmdSetRasterizerDiscardEnable, "ApiCall_vkCmdSetRasterizerDiscardEnable" },
        { gfxrecon::format::ApiCall_vkCmdSetDepthBiasEnable, "ApiCall_vkCmdSetDepthBiasEnable" },
        { gfxrecon::format::ApiCall_vkCmdSetPrimitiveRestartEnable, "ApiCall_vkCmdSetPrimitiveRestartEnable" },
        { gfxrecon::format::ApiCall_vkGetDeviceBufferMemoryRequirements, "ApiCall_vkGetDeviceBufferMemoryRequirements" },
        { gfxrecon::format::ApiCall_vkGetDeviceImageMemoryRequirements, "ApiCall_vkGetDeviceImageMemoryRequirements" },
        { gfxrecon::format::ApiCall_vkGetDeviceImageSparseMemoryRequirements, "ApiCall_vkGetDeviceImageSparseMemoryRequirements" },
        { gfxrecon::format::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE, "ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE" },
        { gfxrecon::format::ApiCall_vkGetDescriptorSetHostMappingVALVE, "ApiCall_vkGetDescriptorSetHostMappingVALVE" },
        { gfxrecon::format::ApiCall_vkCmdTraceRaysIndirect2KHR, "ApiCall_vkCmdTraceRaysIndirect2KHR" },
        { gfxrecon::format::ApiCall_vkGetImageSubresourceLayout2EXT, "ApiCall_vkGetImageSubresourceLayout2EXT" },
        { gfxrecon::format::ApiCall_vkGetPipelinePropertiesEXT, "ApiCall_vkGetPipelinePropertiesEXT" },
        { gfxrecon::format::ApiCall_vkGetShaderModuleIdentifierEXT, "ApiCall_vkGetShaderModuleIdentifierEXT" },
        { gfxrecon::format::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT, "ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT" },
        { gfxrecon::format::ApiCall_vkGetFramebufferTilePropertiesQCOM, "ApiCall_vkGetFramebufferTilePropertiesQCOM" },
        { gfxrecon::format::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM, "ApiCall_vkGetDynamicRenderingTilePropertiesQCOM" },
        { gfxrecon::format::ApiCall_vkGetDeviceFaultInfoEXT, "ApiCall_vkGetDeviceFaultInfoEXT" },
        { gfxrecon::format::ApiCall_vkCreateMicromapEXT, "ApiCall_vkCreateMicromapEXT" },
        { gfxrecon::format::ApiCall_vkDestroyMicromapEXT, "ApiCall_vkDestroyMicromapEXT" },
        { gfxrecon::format::ApiCall_vkCmdBuildMicromapsEXT, "ApiCall_vkCmdBuildMicromapsEXT" },
        { gfxrecon::format::ApiCall_vkBuildMicromapsEXT, "ApiCall_vkBuildMicromapsEXT" },
        { gfxrecon::format::ApiCall_vkCopyMicromapEXT, "ApiCall_vkCopyMicromapEXT" },
        { gfxrecon::format::ApiCall_vkCopyMicromapToMemoryEXT, "ApiCall_vkCopyMicromapToMemoryEXT" },
        { gfxrecon::format::ApiCall_vkCopyMemoryToMicromapEXT, "ApiCall_vkCopyMemoryToMicromapEXT" },
        { gfxrecon::format::ApiCall_vkWriteMicromapsPropertiesEXT, "ApiCall_vkWriteMicromapsPropertiesEXT" },
        { gfxrecon::format::ApiCall_vkCmdCopyMicromapEXT, "ApiCall_vkCmdCopyMicromapEXT" },
        { gfxrecon::format::ApiCall_vkCmdCopyMicromapToMemoryEXT, "ApiCall_vkCmdCopyMicromapToMemoryEXT" },
        { gfxrecon::format::ApiCall_vkCmdCopyMemoryToMicromapEXT, "ApiCall_vkCmdCopyMemoryToMicromapEXT" },
        { gfxrecon::format::ApiCall_vkCmdWriteMicromapsPropertiesEXT, "ApiCall_vkCmdWriteMicromapsPropertiesEXT" },
        { gfxrecon::format::ApiCall_vkGetDeviceMicromapCompatibilityEXT, "ApiCall_vkGetDeviceMicromapCompatibilityEXT" },
        { gfxrecon::format::ApiCall_vkGetMicromapBuildSizesEXT, "ApiCall_vkGetMicromapBuildSizesEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetTessellationDomainOriginEXT, "ApiCall_vkCmdSetTessellationDomainOriginEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetDepthClampEnableEXT, "ApiCall_vkCmdSetDepthClampEnableEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetPolygonModeEXT, "ApiCall_vkCmdSetPolygonModeEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetRasterizationSamplesEXT, "ApiCall_vkCmdSetRasterizationSamplesEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetSampleMaskEXT, "ApiCall_vkCmdSetSampleMaskEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetAlphaToCoverageEnableEXT, "ApiCall_vkCmdSetAlphaToCoverageEnableEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetAlphaToOneEnableEXT, "ApiCall_vkCmdSetAlphaToOneEnableEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetLogicOpEnableEXT, "ApiCall_vkCmdSetLogicOpEnableEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetColorBlendEnableEXT, "ApiCall_vkCmdSetColorBlendEnableEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetColorBlendEquationEXT, "ApiCall_vkCmdSetColorBlendEquationEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetColorWriteMaskEXT, "ApiCall_vkCmdSetColorWriteMaskEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetRasterizationStreamEXT, "ApiCall_vkCmdSetRasterizationStreamEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetConservativeRasterizationModeEXT, "ApiCall_vkCmdSetConservativeRasterizationModeEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT, "ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetDepthClipEnableEXT, "ApiCall_vkCmdSetDepthClipEnableEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetSampleLocationsEnableEXT, "ApiCall_vkCmdSetSampleLocationsEnableEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetColorBlendAdvancedEXT, "ApiCall_vkCmdSetColorBlendAdvancedEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetProvokingVertexModeEXT, "ApiCall_vkCmdSetProvokingVertexModeEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetLineRasterizationModeEXT, "ApiCall_vkCmdSetLineRasterizationModeEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetLineStippleEnableEXT, "ApiCall_vkCmdSetLineStippleEnableEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT, "ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetViewportWScalingEnableNV, "ApiCall_vkCmdSetViewportWScalingEnableNV" },
        { gfxrecon::format::ApiCall_vkCmdSetViewportSwizzleNV, "ApiCall_vkCmdSetViewportSwizzleNV" },
        { gfxrecon::format::ApiCall_vkCmdSetCoverageToColorEnableNV, "ApiCall_vkCmdSetCoverageToColorEnableNV" },
        { gfxrecon::format::ApiCall_vkCmdSetCoverageToColorLocationNV, "ApiCall_vkCmdSetCoverageToColorLocationNV" },
        { gfxrecon::format::ApiCall_vkCmdSetCoverageModulationModeNV, "ApiCall_vkCmdSetCoverageModulationModeNV" },
        { gfxrecon::format::ApiCall_vkCmdSetCoverageModulationTableEnableNV, "ApiCall_vkCmdSetCoverageModulationTableEnableNV" },
        { gfxrecon::format::ApiCall_vkCmdSetCoverageModulationTableNV, "ApiCall_vkCmdSetCoverageModulationTableNV" },
        { gfxrecon::format::ApiCall_vkCmdSetShadingRateImageEnableNV, "ApiCall_vkCmdSetShadingRateImageEnableNV" },
        { gfxrecon::format::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV, "ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV" },
        { gfxrecon::format::ApiCall_vkCmdSetCoverageReductionModeNV, "ApiCall_vkCmdSetCoverageReductionModeNV" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV, "ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV" },
        { gfxrecon::format::ApiCall_vkCreateOpticalFlowSessionNV, "ApiCall_vkCreateOpticalFlowSessionNV" },
        { gfxrecon::format::ApiCall_vkDestroyOpticalFlowSessionNV, "ApiCall_vkDestroyOpticalFlowSessionNV" },
        { gfxrecon::format::ApiCall_vkBindOpticalFlowSessionImageNV, "ApiCall_vkBindOpticalFlowSessionImageNV" },
        { gfxrecon::format::ApiCall_vkCmdOpticalFlowExecuteNV, "ApiCall_vkCmdOpticalFlowExecuteNV" },
        { gfxrecon::format::ApiCall_vkCmdDrawMeshTasksEXT, "ApiCall_vkCmdDrawMeshTasksEXT" },
        { gfxrecon::format::ApiCall_vkCmdDrawMeshTasksIndirectEXT, "ApiCall_vkCmdDrawMeshTasksIndirectEXT" },
        { gfxrecon::format::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT, "ApiCall_vkCmdDrawMeshTasksIndirectCountEXT" },
        { gfxrecon::format::ApiCall_vkReleaseSwapchainImagesEXT, "ApiCall_vkReleaseSwapchainImagesEXT" },
        { gfxrecon::format::ApiCall_vkCmdDrawClusterHUAWEI, "ApiCall_vkCmdDrawClusterHUAWEI" },
        { gfxrecon::format::ApiCall_vkCmdDrawClusterIndirectHUAWEI, "ApiCall_vkCmdDrawClusterIndirectHUAWEI" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR, "ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR, "ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR" },
        { gfxrecon::format::ApiCall_vkCreateVideoSessionKHR, "ApiCall_vkCreateVideoSessionKHR" },
        { gfxrecon::format::ApiCall_vkDestroyVideoSessionKHR, "ApiCall_vkDestroyVideoSessionKHR" },
        { gfxrecon::format::ApiCall_vkGetVideoSessionMemoryRequirementsKHR, "ApiCall_vkGetVideoSessionMemoryRequirementsKHR" },
        { gfxrecon::format::ApiCall_vkBindVideoSessionMemoryKHR, "ApiCall_vkBindVideoSessionMemoryKHR" },
        { gfxrecon::format::ApiCall_vkCreateVideoSessionParametersKHR, "ApiCall_vkCreateVideoSessionParametersKHR" },
        { gfxrecon::format::ApiCall_vkUpdateVideoSessionParametersKHR, "ApiCall_vkUpdateVideoSessionParametersKHR" },
        { gfxrecon::format::ApiCall_vkDestroyVideoSessionParametersKHR, "ApiCall_vkDestroyVideoSessionParametersKHR" },
        { gfxrecon::format::ApiCall_vkCmdBeginVideoCodingKHR, "ApiCall_vkCmdBeginVideoCodingKHR" },
        { gfxrecon::format::ApiCall_vkCmdEndVideoCodingKHR, "ApiCall_vkCmdEndVideoCodingKHR" },
        { gfxrecon::format::ApiCall_vkCmdControlVideoCodingKHR, "ApiCall_vkCmdControlVideoCodingKHR" },
        { gfxrecon::format::ApiCall_vkCmdDecodeVideoKHR, "ApiCall_vkCmdDecodeVideoKHR" },
        { gfxrecon::format::ApiCall_vkCmdEncodeVideoKHR, "ApiCall_vkCmdEncodeVideoKHR" },
        { gfxrecon::format::ApiCall_vkCmdSetDiscardRectangleEnableEXT, "ApiCall_vkCmdSetDiscardRectangleEnableEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetDiscardRectangleModeEXT, "ApiCall_vkCmdSetDiscardRectangleModeEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetExclusiveScissorEnableNV, "ApiCall_vkCmdSetExclusiveScissorEnableNV" },
        { gfxrecon::format::ApiCall_vkMapMemory2KHR, "ApiCall_vkMapMemory2KHR" },
        { gfxrecon::format::ApiCall_vkUnmapMemory2KHR, "ApiCall_vkUnmapMemory2KHR" },
        { gfxrecon::format::ApiCall_vkCreateShadersEXT, "ApiCall_vkCreateShadersEXT" },
        { gfxrecon::format::ApiCall_vkDestroyShaderEXT, "ApiCall_vkDestroyShaderEXT" },
        { gfxrecon::format::ApiCall_vkGetShaderBinaryDataEXT, "ApiCall_vkGetShaderBinaryDataEXT" },
        { gfxrecon::format::ApiCall_vkCmdBindShadersEXT, "ApiCall_vkCmdBindShadersEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetAttachmentFeedbackLoopEnableEXT, "ApiCall_vkCmdSetAttachmentFeedbackLoopEnableEXT" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR, "ApiCall_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR" },
        { gfxrecon::format::ApiCall_vkGetEncodedVideoSessionParametersKHR, "ApiCall_vkGetEncodedVideoSessionParametersKHR" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR, "ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR" },
        { gfxrecon::format::ApiCall_vkCmdSetDepthBias2EXT, "ApiCall_vkCmdSetDepthBias2EXT" },
        { gfxrecon::format::ApiCall_vkCopyMemoryToImageEXT, "ApiCall_vkCopyMemoryToImageEXT" },
        { gfxrecon::format::ApiCall_vkCopyImageToMemoryEXT, "ApiCall_vkCopyImageToMemoryEXT" },
        { gfxrecon::format::ApiCall_vkCopyImageToImageEXT, "ApiCall_vkCopyImageToImageEXT" },
        { gfxrecon::format::ApiCall_vkTransitionImageLayoutEXT, "ApiCall_vkTransitionImageLayoutEXT" },
        { gfxrecon::format::ApiCall_vkGetPipelineIndirectMemoryRequirementsNV, "ApiCall_vkGetPipelineIndirectMemoryRequirementsNV" },
        { gfxrecon::format::ApiCall_vkCmdUpdatePipelineIndirectBuffer, "ApiCall_vkCmdUpdatePipelineIndirectBuffer" },
        { gfxrecon::format::ApiCall_vkGetPipelineIndirectDeviceAddressNV, "ApiCall_vkGetPipelineIndirectDeviceAddressNV" },
        { gfxrecon::format::ApiCall_vkCmdUpdatePipelineIndirectBufferNV, "ApiCall_vkCmdUpdatePipelineIndirectBufferNV" },
        { gfxrecon::format::ApiCall_vkCmdBindIndexBuffer2KHR, "ApiCall_vkCmdBindIndexBuffer2KHR" },
        { gfxrecon::format::ApiCall_vkGetRenderingAreaGranularityKHR, "ApiCall_vkGetRenderingAreaGranularityKHR" },
        { gfxrecon::format::ApiCall_vkGetDeviceImageSubresourceLayoutKHR, "ApiCall_vkGetDeviceImageSubresourceLayoutKHR" },
        { gfxrecon::format::ApiCall_vkGetImageSubresourceLayout2KHR, "ApiCall_vkGetImageSubresourceLayout2KHR" },
        { gfxrecon::format::ApiCall_vkFrameBoundaryANDROID, "ApiCall_vkFrameBoundaryANDROID" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR, "ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR" },
        { gfxrecon::format::ApiCall_vkGetCalibratedTimestampsKHR, "ApiCall_vkGetCalibratedTimestampsKHR" },
        { gfxrecon::format::ApiCall_vkCmdBindDescriptorSets2KHR, "ApiCall_vkCmdBindDescriptorSets2KHR" },
        { gfxrecon::format::ApiCall_vkCmdPushConstants2KHR, "ApiCall_vkCmdPushConstants2KHR" },
        { gfxrecon::format::ApiCall_vkCmdPushDescriptorSet2KHR, "ApiCall_vkCmdPushDescriptorSet2KHR" },
        { gfxrecon::format::ApiCall_vkCmdPushDescriptorSetWithTemplate2KHR, "ApiCall_vkCmdPushDescriptorSetWithTemplate2KHR" },
        { gfxrecon::format::ApiCall_vkCmdSetDescriptorBufferOffsets2EXT, "ApiCall_vkCmdSetDescriptorBufferOffsets2EXT" },
        { gfxrecon::format::ApiCall_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT, "ApiCall_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT" },
        { gfxrecon::format::ApiCall_vkCmdSetRenderingAttachmentLocationsKHR, "ApiCall_vkCmdSetRenderingAttachmentLocationsKHR" },
        { gfxrecon::format::ApiCall_vkCmdSetRenderingInputAttachmentIndicesKHR, "ApiCall_vkCmdSetRenderingInputAttachmentIndicesKHR" },
        { gfxrecon::format::ApiCall_vkCmdSetLineStippleKHR, "ApiCall_vkCmdSetLineStippleKHR" },
        { gfxrecon::format::ApiCall_vkSetLatencySleepModeNV, "ApiCall_vkSetLatencySleepModeNV" },
        { gfxrecon::format::ApiCall_vkLatencySleepNV, "ApiCall_vkLatencySleepNV" },
        { gfxrecon::format::ApiCall_vkSetLatencyMarkerNV, "ApiCall_vkSetLatencyMarkerNV" },
        { gfxrecon::format::ApiCall_vkGetLatencyTimingsNV, "ApiCall_vkGetLatencyTimingsNV" },
        { gfxrecon::format::ApiCall_vkQueueNotifyOutOfBandNV, "ApiCall_vkQueueNotifyOutOfBandNV" },
        { gfxrecon::format::ApiCall_vkCreatePipelineBinariesKHR, "ApiCall_vkCreatePipelineBinariesKHR" },
        { gfxrecon::format::ApiCall_vkDestroyPipelineBinaryKHR, "ApiCall_vkDestroyPipelineBinaryKHR" },
        { gfxrecon::format::ApiCall_vkGetPipelineBinaryDataKHR, "ApiCall_vkGetPipelineBinaryDataKHR" },
        { gfxrecon::format::ApiCall_vkGetPipelineKeyKHR, "ApiCall_vkGetPipelineKeyKHR" },
        { gfxrecon::format::ApiCall_vkReleaseCapturedPipelineDataKHR, "ApiCall_vkReleaseCapturedPipelineDataKHR" },
        { gfxrecon::format::ApiCall_vkAntiLagUpdateAMD, "ApiCall_vkAntiLagUpdateAMD" },
        { gfxrecon::format::ApiCall_vkGetGeneratedCommandsMemoryRequirementsEXT, "ApiCall_vkGetGeneratedCommandsMemoryRequirementsEXT" },
        { gfxrecon::format::ApiCall_vkCmdPreprocessGeneratedCommandsEXT, "ApiCall_vkCmdPreprocessGeneratedCommandsEXT" },
        { gfxrecon::format::ApiCall_vkCmdExecuteGeneratedCommandsEXT, "ApiCall_vkCmdExecuteGeneratedCommandsEXT" },
        { gfxrecon::format::ApiCall_vkCreateIndirectCommandsLayoutEXT, "ApiCall_vkCreateIndirectCommandsLayoutEXT" },
        { gfxrecon::format::ApiCall_vkDestroyIndirectCommandsLayoutEXT, "ApiCall_vkDestroyIndirectCommandsLayoutEXT" },
        { gfxrecon::format::ApiCall_vkCreateIndirectExecutionSetEXT, "ApiCall_vkCreateIndirectExecutionSetEXT" },
        { gfxrecon::format::ApiCall_vkDestroyIndirectExecutionSetEXT, "ApiCall_vkDestroyIndirectExecutionSetEXT" },
        { gfxrecon::format::ApiCall_vkUpdateIndirectExecutionSetPipelineEXT, "ApiCall_vkUpdateIndirectExecutionSetPipelineEXT" },
        { gfxrecon::format::ApiCall_vkUpdateIndirectExecutionSetShaderEXT, "ApiCall_vkUpdateIndirectExecutionSetShaderEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetDepthClampRangeEXT, "ApiCall_vkCmdSetDepthClampRangeEXT" },
        { gfxrecon::format::ApiCall_vkCmdSetLineStipple, "ApiCall_vkCmdSetLineStipple" },
        { gfxrecon::format::ApiCall_vkMapMemory2, "ApiCall_vkMapMemory2" },
        { gfxrecon::format::ApiCall_vkUnmapMemory2, "ApiCall_vkUnmapMemory2" },
        { gfxrecon::format::ApiCall_vkCmdBindIndexBuffer2, "ApiCall_vkCmdBindIndexBuffer2" },
        { gfxrecon::format::ApiCall_vkGetRenderingAreaGranularity, "ApiCall_vkGetRenderingAreaGranularity" },
        { gfxrecon::format::ApiCall_vkGetDeviceImageSubresourceLayout, "ApiCall_vkGetDeviceImageSubresourceLayout" },
        { gfxrecon::format::ApiCall_vkGetImageSubresourceLayout2, "ApiCall_vkGetImageSubresourceLayout2" },
        { gfxrecon::format::ApiCall_vkCmdPushDescriptorSet, "ApiCall_vkCmdPushDescriptorSet" },
        { gfxrecon::format::ApiCall_vkCmdPushDescriptorSetWithTemplate, "ApiCall_vkCmdPushDescriptorSetWithTemplate" },
        { gfxrecon::format::ApiCall_vkCmdSetRenderingAttachmentLocations, "ApiCall_vkCmdSetRenderingAttachmentLocations" },
        { gfxrecon::format::ApiCall_vkCmdSetRenderingInputAttachmentIndices, "ApiCall_vkCmdSetRenderingInputAttachmentIndices" },
        { gfxrecon::format::ApiCall_vkCmdBindDescriptorSets2, "ApiCall_vkCmdBindDescriptorSets2" },
        { gfxrecon::format::ApiCall_vkCmdPushConstants2, "ApiCall_vkCmdPushConstants2" },
        { gfxrecon::format::ApiCall_vkCmdPushDescriptorSet2, "ApiCall_vkCmdPushDescriptorSet2" },
        { gfxrecon::format::ApiCall_vkCmdPushDescriptorSetWithTemplate2, "ApiCall_vkCmdPushDescriptorSetWithTemplate2" },
        { gfxrecon::format::ApiCall_vkCopyMemoryToImage, "ApiCall_vkCopyMemoryToImage" },
        { gfxrecon::format::ApiCall_vkCopyImageToMemory, "ApiCall_vkCopyImageToMemory" },
        { gfxrecon::format::ApiCall_vkCopyImageToImage, "ApiCall_vkCopyImageToImage" },
        { gfxrecon::format::ApiCall_vkTransitionImageLayout, "ApiCall_vkTransitionImageLayout" },
        { gfxrecon::format::ApiCall_vkGetImageViewHandle64NVX, "ApiCall_vkGetImageViewHandle64NVX" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV, "ApiCall_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceCooperativeVectorPropertiesNV, "ApiCall_vkGetPhysicalDeviceCooperativeVectorPropertiesNV" },
        { gfxrecon::format::ApiCall_vkConvertCooperativeVectorMatrixNV, "ApiCall_vkConvertCooperativeVectorMatrixNV" },
        { gfxrecon::format::ApiCall_vkCmdConvertCooperativeVectorMatrixNV, "ApiCall_vkCmdConvertCooperativeVectorMatrixNV" },
        { gfxrecon::format::ApiCall_vkCmdBuildPartitionedAccelerationStructuresNV, "ApiCall_vkCmdBuildPartitionedAccelerationStructuresNV" },
        { gfxrecon::format::ApiCall_vkGetPartitionedAccelerationStructuresBuildSizesNV, "ApiCall_vkGetPartitionedAccelerationStructuresBuildSizesNV" },
        { gfxrecon::format::ApiCall_vkGetMemoryMetalHandlePropertiesEXT, "ApiCall_vkGetMemoryMetalHandlePropertiesEXT" },
        { gfxrecon::format::ApiCall_vkGetMemoryMetalHandleEXT, "ApiCall_vkGetMemoryMetalHandleEXT" },
        { gfxrecon::format::ApiCall_vkCmdDispatchTileQCOM, "ApiCall_vkCmdDispatchTileQCOM" },
        { gfxrecon::format::ApiCall_vkCmdBeginPerTileExecutionQCOM, "ApiCall_vkCmdBeginPerTileExecutionQCOM" },
        { gfxrecon::format::ApiCall_vkCmdEndPerTileExecutionQCOM, "ApiCall_vkCmdEndPerTileExecutionQCOM" },
        { gfxrecon::format::ApiCall_vkCmdBindTileMemoryQCOM, "ApiCall_vkCmdBindTileMemoryQCOM" },
        { gfxrecon::format::ApiCall_vkCmdEndRendering2EXT, "ApiCall_vkCmdEndRendering2EXT" },
        { gfxrecon::format::ApiCall_vkBindTensorMemoryARM, "ApiCall_vkBindTensorMemoryARM" },
        { gfxrecon::format::ApiCall_vkCmdCopyTensorARM, "ApiCall_vkCmdCopyTensorARM" },
        { gfxrecon::format::ApiCall_vkCreateTensorARM, "ApiCall_vkCreateTensorARM" },
        { gfxrecon::format::ApiCall_vkCreateTensorViewARM, "ApiCall_vkCreateTensorViewARM" },
        { gfxrecon::format::ApiCall_vkDestroyTensorARM, "ApiCall_vkDestroyTensorARM" },
        { gfxrecon::format::ApiCall_vkDestroyTensorViewARM, "ApiCall_vkDestroyTensorViewARM" },
        { gfxrecon::format::ApiCall_vkGetDeviceTensorMemoryRequirementsARM, "ApiCall_vkGetDeviceTensorMemoryRequirementsARM" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceExternalTensorPropertiesARM, "ApiCall_vkGetPhysicalDeviceExternalTensorPropertiesARM" },
        { gfxrecon::format::ApiCall_vkGetTensorMemoryRequirementsARM, "ApiCall_vkGetTensorMemoryRequirementsARM" },
        { gfxrecon::format::ApiCall_vkGetTensorOpaqueCaptureDescriptorDataARM, "ApiCall_vkGetTensorOpaqueCaptureDescriptorDataARM" },
        { gfxrecon::format::ApiCall_vkGetTensorViewOpaqueCaptureDescriptorDataARM, "ApiCall_vkGetTensorViewOpaqueCaptureDescriptorDataARM" },
        { gfxrecon::format::ApiCall_vkBindDataGraphPipelineSessionMemoryARM, "ApiCall_vkBindDataGraphPipelineSessionMemoryARM" },
        { gfxrecon::format::ApiCall_vkCmdDispatchDataGraphARM, "ApiCall_vkCmdDispatchDataGraphARM" },
        { gfxrecon::format::ApiCall_vkCreateDataGraphPipelineSessionARM, "ApiCall_vkCreateDataGraphPipelineSessionARM" },
        { gfxrecon::format::ApiCall_vkCreateDataGraphPipelinesARM, "ApiCall_vkCreateDataGraphPipelinesARM" },
        { gfxrecon::format::ApiCall_vkDestroyDataGraphPipelineSessionARM, "ApiCall_vkDestroyDataGraphPipelineSessionARM" },
        { gfxrecon::format::ApiCall_vkGetDataGraphPipelineAvailablePropertiesARM, "ApiCall_vkGetDataGraphPipelineAvailablePropertiesARM" },
        { gfxrecon::format::ApiCall_vkGetDataGraphPipelinePropertiesARM, "ApiCall_vkGetDataGraphPipelinePropertiesARM" },
        { gfxrecon::format::ApiCall_vkGetDataGraphPipelineSessionBindPointRequirementsARM, "ApiCall_vkGetDataGraphPipelineSessionBindPointRequirementsARM" },
        { gfxrecon::format::ApiCall_vkGetDataGraphPipelineSessionMemoryRequirementsARM, "ApiCall_vkGetDataGraphPipelineSessionMemoryRequirementsARM" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM, "ApiCall_vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM" },
        { gfxrecon::format::ApiCall_vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM, "ApiCall_vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM" },
        { gfxrecon::format::ApiCall_CreateDXGIFactory, "ApiCall_CreateDXGIFactory" },
        { gfxrecon::format::ApiCall_CreateDXGIFactory1, "ApiCall_CreateDXGIFactory1" },
        { gfxrecon::format::ApiCall_IDXGIObject_SetPrivateData, "ApiCall_IDXGIObject_SetPrivateData" },
        { gfxrecon::format::ApiCall_IDXGIObject_SetPrivateDataInterface, "ApiCall_IDXGIObject_SetPrivateDataInterface" },
        { gfxrecon::format::ApiCall_IDXGIObject_GetPrivateData, "ApiCall_IDXGIObject_GetPrivateData" },
        { gfxrecon::format::ApiCall_IDXGIObject_GetParent, "ApiCall_IDXGIObject_GetParent" },
        { gfxrecon::format::ApiCall_IDXGIDeviceSubObject_GetDevice, "ApiCall_IDXGIDeviceSubObject_GetDevice" },
        { gfxrecon::format::ApiCall_IDXGIResource_GetSharedHandle, "ApiCall_IDXGIResource_GetSharedHandle" },
        { gfxrecon::format::ApiCall_IDXGIResource_GetUsage, "ApiCall_IDXGIResource_GetUsage" },
        { gfxrecon::format::ApiCall_IDXGIResource_SetEvictionPriority, "ApiCall_IDXGIResource_SetEvictionPriority" },
        { gfxrecon::format::ApiCall_IDXGIResource_GetEvictionPriority, "ApiCall_IDXGIResource_GetEvictionPriority" },
        { gfxrecon::format::ApiCall_IDXGIKeyedMutex_AcquireSync, "ApiCall_IDXGIKeyedMutex_AcquireSync" },
        { gfxrecon::format::ApiCall_IDXGIKeyedMutex_ReleaseSync, "ApiCall_IDXGIKeyedMutex_ReleaseSync" },
        { gfxrecon::format::ApiCall_IDXGISurface_GetDesc, "ApiCall_IDXGISurface_GetDesc" },
        { gfxrecon::format::ApiCall_IDXGISurface_Map, "ApiCall_IDXGISurface_Map" },
        { gfxrecon::format::ApiCall_IDXGISurface_Unmap, "ApiCall_IDXGISurface_Unmap" },
        { gfxrecon::format::ApiCall_IDXGISurface1_GetDC, "ApiCall_IDXGISurface1_GetDC" },
        { gfxrecon::format::ApiCall_IDXGISurface1_ReleaseDC, "ApiCall_IDXGISurface1_ReleaseDC" },
        { gfxrecon::format::ApiCall_IDXGIAdapter_EnumOutputs, "ApiCall_IDXGIAdapter_EnumOutputs" },
        { gfxrecon::format::ApiCall_IDXGIAdapter_GetDesc, "ApiCall_IDXGIAdapter_GetDesc" },
        { gfxrecon::format::ApiCall_IDXGIAdapter_CheckInterfaceSupport, "ApiCall_IDXGIAdapter_CheckInterfaceSupport" },
        { gfxrecon::format::ApiCall_IDXGIOutput_GetDesc, "ApiCall_IDXGIOutput_GetDesc" },
        { gfxrecon::format::ApiCall_IDXGIOutput_GetDisplayModeList, "ApiCall_IDXGIOutput_GetDisplayModeList" },
        { gfxrecon::format::ApiCall_IDXGIOutput_FindClosestMatchingMode, "ApiCall_IDXGIOutput_FindClosestMatchingMode" },
        { gfxrecon::format::ApiCall_IDXGIOutput_WaitForVBlank, "ApiCall_IDXGIOutput_WaitForVBlank" },
        { gfxrecon::format::ApiCall_IDXGIOutput_TakeOwnership, "ApiCall_IDXGIOutput_TakeOwnership" },
        { gfxrecon::format::ApiCall_IDXGIOutput_ReleaseOwnership, "ApiCall_IDXGIOutput_ReleaseOwnership" },
        { gfxrecon::format::ApiCall_IDXGIOutput_GetGammaControlCapabilities, "ApiCall_IDXGIOutput_GetGammaControlCapabilities" },
        { gfxrecon::format::ApiCall_IDXGIOutput_SetGammaControl, "ApiCall_IDXGIOutput_SetGammaControl" },
        { gfxrecon::format::ApiCall_IDXGIOutput_GetGammaControl, "ApiCall_IDXGIOutput_GetGammaControl" },
        { gfxrecon::format::ApiCall_IDXGIOutput_SetDisplaySurface, "ApiCall_IDXGIOutput_SetDisplaySurface" },
        { gfxrecon::format::ApiCall_IDXGIOutput_GetDisplaySurfaceData, "ApiCall_IDXGIOutput_GetDisplaySurfaceData" },
        { gfxrecon::format::ApiCall_IDXGIOutput_GetFrameStatistics, "ApiCall_IDXGIOutput_GetFrameStatistics" },
        { gfxrecon::format::ApiCall_IDXGISwapChain_Present, "ApiCall_IDXGISwapChain_Present" },
        { gfxrecon::format::ApiCall_IDXGISwapChain_GetBuffer, "ApiCall_IDXGISwapChain_GetBuffer" },
        { gfxrecon::format::ApiCall_IDXGISwapChain_SetFullscreenState, "ApiCall_IDXGISwapChain_SetFullscreenState" },
        { gfxrecon::format::ApiCall_IDXGISwapChain_GetFullscreenState, "ApiCall_IDXGISwapChain_GetFullscreenState" },
        { gfxrecon::format::ApiCall_IDXGISwapChain_GetDesc, "ApiCall_IDXGISwapChain_GetDesc" },
        { gfxrecon::format::ApiCall_IDXGISwapChain_ResizeBuffers, "ApiCall_IDXGISwapChain_ResizeBuffers" },
        { gfxrecon::format::ApiCall_IDXGISwapChain_ResizeTarget, "ApiCall_IDXGISwapChain_ResizeTarget" },
        { gfxrecon::format::ApiCall_IDXGISwapChain_GetContainingOutput, "ApiCall_IDXGISwapChain_GetContainingOutput" },
        { gfxrecon::format::ApiCall_IDXGISwapChain_GetFrameStatistics, "ApiCall_IDXGISwapChain_GetFrameStatistics" },
        { gfxrecon::format::ApiCall_IDXGISwapChain_GetLastPresentCount, "ApiCall_IDXGISwapChain_GetLastPresentCount" },
        { gfxrecon::format::ApiCall_IDXGIFactory_EnumAdapters, "ApiCall_IDXGIFactory_EnumAdapters" },
        { gfxrecon::format::ApiCall_IDXGIFactory_MakeWindowAssociation, "ApiCall_IDXGIFactory_MakeWindowAssociation" },
        { gfxrecon::format::ApiCall_IDXGIFactory_GetWindowAssociation, "ApiCall_IDXGIFactory_GetWindowAssociation" },
        { gfxrecon::format::ApiCall_IDXGIFactory_CreateSwapChain, "ApiCall_IDXGIFactory_CreateSwapChain" },
        { gfxrecon::format::ApiCall_IDXGIFactory_CreateSoftwareAdapter, "ApiCall_IDXGIFactory_CreateSoftwareAdapter" },
        { gfxrecon::format::ApiCall_IDXGIDevice_GetAdapter, "ApiCall_IDXGIDevice_GetAdapter" },
        { gfxrecon::format::ApiCall_IDXGIDevice_CreateSurface, "ApiCall_IDXGIDevice_CreateSurface" },
        { gfxrecon::format::ApiCall_IDXGIDevice_QueryResourceResidency, "ApiCall_IDXGIDevice_QueryResourceResidency" },
        { gfxrecon::format::ApiCall_IDXGIDevice_SetGPUThreadPriority, "ApiCall_IDXGIDevice_SetGPUThreadPriority" },
        { gfxrecon::format::ApiCall_IDXGIDevice_GetGPUThreadPriority, "ApiCall_IDXGIDevice_GetGPUThreadPriority" },
        { gfxrecon::format::ApiCall_IDXGIFactory1_EnumAdapters1, "ApiCall_IDXGIFactory1_EnumAdapters1" },
        { gfxrecon::format::ApiCall_IDXGIFactory1_IsCurrent, "ApiCall_IDXGIFactory1_IsCurrent" },
        { gfxrecon::format::ApiCall_IDXGIAdapter1_GetDesc1, "ApiCall_IDXGIAdapter1_GetDesc1" },
        { gfxrecon::format::ApiCall_IDXGIDevice1_SetMaximumFrameLatency, "ApiCall_IDXGIDevice1_SetMaximumFrameLatency" },
        { gfxrecon::format::ApiCall_IDXGIDevice1_GetMaximumFrameLatency, "ApiCall_IDXGIDevice1_GetMaximumFrameLatency" },
        { gfxrecon::format::ApiCall_IDXGIDisplayControl_IsStereoEnabled, "ApiCall_IDXGIDisplayControl_IsStereoEnabled" },
        { gfxrecon::format::ApiCall_IDXGIDisplayControl_SetStereoEnabled, "ApiCall_IDXGIDisplayControl_SetStereoEnabled" },
        { gfxrecon::format::ApiCall_IDXGIOutputDuplication_GetDesc, "ApiCall_IDXGIOutputDuplication_GetDesc" },
        { gfxrecon::format::ApiCall_IDXGIOutputDuplication_AcquireNextFrame, "ApiCall_IDXGIOutputDuplication_AcquireNextFrame" },
        { gfxrecon::format::ApiCall_IDXGIOutputDuplication_GetFrameDirtyRects, "ApiCall_IDXGIOutputDuplication_GetFrameDirtyRects" },
        { gfxrecon::format::ApiCall_IDXGIOutputDuplication_GetFrameMoveRects, "ApiCall_IDXGIOutputDuplication_GetFrameMoveRects" },
        { gfxrecon::format::ApiCall_IDXGIOutputDuplication_GetFramePointerShape, "ApiCall_IDXGIOutputDuplication_GetFramePointerShape" },
        { gfxrecon::format::ApiCall_IDXGIOutputDuplication_MapDesktopSurface, "ApiCall_IDXGIOutputDuplication_MapDesktopSurface" },
        { gfxrecon::format::ApiCall_IDXGIOutputDuplication_UnMapDesktopSurface, "ApiCall_IDXGIOutputDuplication_UnMapDesktopSurface" },
        { gfxrecon::format::ApiCall_IDXGIOutputDuplication_ReleaseFrame, "ApiCall_IDXGIOutputDuplication_ReleaseFrame" },
        { gfxrecon::format::ApiCall_IDXGISurface2_GetResource, "ApiCall_IDXGISurface2_GetResource" },
        { gfxrecon::format::ApiCall_IDXGIResource1_CreateSubresourceSurface, "ApiCall_IDXGIResource1_CreateSubresourceSurface" },
        { gfxrecon::format::ApiCall_IDXGIResource1_CreateSharedHandle, "ApiCall_IDXGIResource1_CreateSharedHandle" },
        { gfxrecon::format::ApiCall_IDXGIDevice2_OfferResources, "ApiCall_IDXGIDevice2_OfferResources" },
        { gfxrecon::format::ApiCall_IDXGIDevice2_ReclaimResources, "ApiCall_IDXGIDevice2_ReclaimResources" },
        { gfxrecon::format::ApiCall_IDXGIDevice2_EnqueueSetEvent, "ApiCall_IDXGIDevice2_EnqueueSetEvent" },
        { gfxrecon::format::ApiCall_IDXGISwapChain1_GetDesc1, "ApiCall_IDXGISwapChain1_GetDesc1" },
        { gfxrecon::format::ApiCall_IDXGISwapChain1_GetFullscreenDesc, "ApiCall_IDXGISwapChain1_GetFullscreenDesc" },
        { gfxrecon::format::ApiCall_IDXGISwapChain1_GetHwnd, "ApiCall_IDXGISwapChain1_GetHwnd" },
        { gfxrecon::format::ApiCall_IDXGISwapChain1_GetCoreWindow, "ApiCall_IDXGISwapChain1_GetCoreWindow" },
        { gfxrecon::format::ApiCall_IDXGISwapChain1_Present1, "ApiCall_IDXGISwapChain1_Present1" },
        { gfxrecon::format::ApiCall_IDXGISwapChain1_IsTemporaryMonoSupported, "ApiCall_IDXGISwapChain1_IsTemporaryMonoSupported" },
        { gfxrecon::format::ApiCall_IDXGISwapChain1_GetRestrictToOutput, "ApiCall_IDXGISwapChain1_GetRestrictToOutput" },
        { gfxrecon::format::ApiCall_IDXGISwapChain1_SetBackgroundColor, "ApiCall_IDXGISwapChain1_SetBackgroundColor" },
        { gfxrecon::format::ApiCall_IDXGISwapChain1_GetBackgroundColor, "ApiCall_IDXGISwapChain1_GetBackgroundColor" },
        { gfxrecon::format::ApiCall_IDXGISwapChain1_SetRotation, "ApiCall_IDXGISwapChain1_SetRotation" },
        { gfxrecon::format::ApiCall_IDXGISwapChain1_GetRotation, "ApiCall_IDXGISwapChain1_GetRotation" },
        { gfxrecon::format::ApiCall_IDXGIFactory2_IsWindowedStereoEnabled, "ApiCall_IDXGIFactory2_IsWindowedStereoEnabled" },
        { gfxrecon::format::ApiCall_IDXGIFactory2_CreateSwapChainForHwnd, "ApiCall_IDXGIFactory2_CreateSwapChainForHwnd" },
        { gfxrecon::format::ApiCall_IDXGIFactory2_CreateSwapChainForCoreWindow, "ApiCall_IDXGIFactory2_CreateSwapChainForCoreWindow" },
        { gfxrecon::format::ApiCall_IDXGIFactory2_GetSharedResourceAdapterLuid, "ApiCall_IDXGIFactory2_GetSharedResourceAdapterLuid" },
        { gfxrecon::format::ApiCall_IDXGIFactory2_RegisterStereoStatusWindow, "ApiCall_IDXGIFactory2_RegisterStereoStatusWindow" },
        { gfxrecon::format::ApiCall_IDXGIFactory2_RegisterStereoStatusEvent, "ApiCall_IDXGIFactory2_RegisterStereoStatusEvent" },
        { gfxrecon::format::ApiCall_IDXGIFactory2_UnregisterStereoStatus, "ApiCall_IDXGIFactory2_UnregisterStereoStatus" },
        { gfxrecon::format::ApiCall_IDXGIFactory2_RegisterOcclusionStatusWindow, "ApiCall_IDXGIFactory2_RegisterOcclusionStatusWindow" },
        { gfxrecon::format::ApiCall_IDXGIFactory2_RegisterOcclusionStatusEvent, "ApiCall_IDXGIFactory2_RegisterOcclusionStatusEvent" },
        { gfxrecon::format::ApiCall_IDXGIFactory2_UnregisterOcclusionStatus, "ApiCall_IDXGIFactory2_UnregisterOcclusionStatus" },
        { gfxrecon::format::ApiCall_IDXGIFactory2_CreateSwapChainForComposition, "ApiCall_IDXGIFactory2_CreateSwapChainForComposition" },
        { gfxrecon::format::ApiCall_IDXGIAdapter2_GetDesc2, "ApiCall_IDXGIAdapter2_GetDesc2" },
        { gfxrecon::format::ApiCall_IDXGIOutput1_GetDisplayModeList1, "ApiCall_IDXGIOutput1_GetDisplayModeList1" },
        { gfxrecon::format::ApiCall_IDXGIOutput1_FindClosestMatchingMode1, "ApiCall_IDXGIOutput1_FindClosestMatchingMode1" },
        { gfxrecon::format::ApiCall_IDXGIOutput1_GetDisplaySurfaceData1, "ApiCall_IDXGIOutput1_GetDisplaySurfaceData1" },
        { gfxrecon::format::ApiCall_IDXGIOutput1_DuplicateOutput, "ApiCall_IDXGIOutput1_DuplicateOutput" },
        { gfxrecon::format::ApiCall_CreateDXGIFactory2, "ApiCall_CreateDXGIFactory2" },
        { gfxrecon::format::ApiCall_DXGIGetDebugInterface1, "ApiCall_DXGIGetDebugInterface1" },
        { gfxrecon::format::ApiCall_IDXGIDevice3_Trim, "ApiCall_IDXGIDevice3_Trim" },
        { gfxrecon::format::ApiCall_IDXGISwapChain2_SetSourceSize, "ApiCall_IDXGISwapChain2_SetSourceSize" },
        { gfxrecon::format::ApiCall_IDXGISwapChain2_GetSourceSize, "ApiCall_IDXGISwapChain2_GetSourceSize" },
        { gfxrecon::format::ApiCall_IDXGISwapChain2_SetMaximumFrameLatency, "ApiCall_IDXGISwapChain2_SetMaximumFrameLatency" },
        { gfxrecon::format::ApiCall_IDXGISwapChain2_GetMaximumFrameLatency, "ApiCall_IDXGISwapChain2_GetMaximumFrameLatency" },
        { gfxrecon::format::ApiCall_IDXGISwapChain2_GetFrameLatencyWaitableObject, "ApiCall_IDXGISwapChain2_GetFrameLatencyWaitableObject" },
        { gfxrecon::format::ApiCall_IDXGISwapChain2_SetMatrixTransform, "ApiCall_IDXGISwapChain2_SetMatrixTransform" },
        { gfxrecon::format::ApiCall_IDXGISwapChain2_GetMatrixTransform, "ApiCall_IDXGISwapChain2_GetMatrixTransform" },
        { gfxrecon::format::ApiCall_IDXGIOutput2_SupportsOverlays, "ApiCall_IDXGIOutput2_SupportsOverlays" },
        { gfxrecon::format::ApiCall_IDXGIFactory3_GetCreationFlags, "ApiCall_IDXGIFactory3_GetCreationFlags" },
        { gfxrecon::format::ApiCall_IDXGIDecodeSwapChain_PresentBuffer, "ApiCall_IDXGIDecodeSwapChain_PresentBuffer" },
        { gfxrecon::format::ApiCall_IDXGIDecodeSwapChain_SetSourceRect, "ApiCall_IDXGIDecodeSwapChain_SetSourceRect" },
        { gfxrecon::format::ApiCall_IDXGIDecodeSwapChain_SetTargetRect, "ApiCall_IDXGIDecodeSwapChain_SetTargetRect" },
        { gfxrecon::format::ApiCall_IDXGIDecodeSwapChain_SetDestSize, "ApiCall_IDXGIDecodeSwapChain_SetDestSize" },
        { gfxrecon::format::ApiCall_IDXGIDecodeSwapChain_GetSourceRect, "ApiCall_IDXGIDecodeSwapChain_GetSourceRect" },
        { gfxrecon::format::ApiCall_IDXGIDecodeSwapChain_GetTargetRect, "ApiCall_IDXGIDecodeSwapChain_GetTargetRect" },
        { gfxrecon::format::ApiCall_IDXGIDecodeSwapChain_GetDestSize, "ApiCall_IDXGIDecodeSwapChain_GetDestSize" },
        { gfxrecon::format::ApiCall_IDXGIDecodeSwapChain_SetColorSpace, "ApiCall_IDXGIDecodeSwapChain_SetColorSpace" },
        { gfxrecon::format::ApiCall_IDXGIDecodeSwapChain_GetColorSpace, "ApiCall_IDXGIDecodeSwapChain_GetColorSpace" },
        { gfxrecon::format::ApiCall_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle, "ApiCall_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle" },
        { gfxrecon::format::ApiCall_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle, "ApiCall_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle" },
        { gfxrecon::format::ApiCall_IDXGISwapChainMedia_GetFrameStatisticsMedia, "ApiCall_IDXGISwapChainMedia_GetFrameStatisticsMedia" },
        { gfxrecon::format::ApiCall_IDXGISwapChainMedia_SetPresentDuration, "ApiCall_IDXGISwapChainMedia_SetPresentDuration" },
        { gfxrecon::format::ApiCall_IDXGISwapChainMedia_CheckPresentDurationSupport, "ApiCall_IDXGISwapChainMedia_CheckPresentDurationSupport" },
        { gfxrecon::format::ApiCall_IDXGIOutput3_CheckOverlaySupport, "ApiCall_IDXGIOutput3_CheckOverlaySupport" },
        { gfxrecon::format::ApiCall_IDXGISwapChain3_GetCurrentBackBufferIndex, "ApiCall_IDXGISwapChain3_GetCurrentBackBufferIndex" },
        { gfxrecon::format::ApiCall_IDXGISwapChain3_CheckColorSpaceSupport, "ApiCall_IDXGISwapChain3_CheckColorSpaceSupport" },
        { gfxrecon::format::ApiCall_IDXGISwapChain3_SetColorSpace1, "ApiCall_IDXGISwapChain3_SetColorSpace1" },
        { gfxrecon::format::ApiCall_IDXGISwapChain3_ResizeBuffers1, "ApiCall_IDXGISwapChain3_ResizeBuffers1" },
        { gfxrecon::format::ApiCall_IDXGIOutput4_CheckOverlayColorSpaceSupport, "ApiCall_IDXGIOutput4_CheckOverlayColorSpaceSupport" },
        { gfxrecon::format::ApiCall_IDXGIFactory4_EnumAdapterByLuid, "ApiCall_IDXGIFactory4_EnumAdapterByLuid" },
        { gfxrecon::format::ApiCall_IDXGIFactory4_EnumWarpAdapter, "ApiCall_IDXGIFactory4_EnumWarpAdapter" },
        { gfxrecon::format::ApiCall_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent, "ApiCall_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent" },
        { gfxrecon::format::ApiCall_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus, "ApiCall_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus" },
        { gfxrecon::format::ApiCall_IDXGIAdapter3_QueryVideoMemoryInfo, "ApiCall_IDXGIAdapter3_QueryVideoMemoryInfo" },
        { gfxrecon::format::ApiCall_IDXGIAdapter3_SetVideoMemoryReservation, "ApiCall_IDXGIAdapter3_SetVideoMemoryReservation" },
        { gfxrecon::format::ApiCall_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent, "ApiCall_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent" },
        { gfxrecon::format::ApiCall_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification, "ApiCall_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification" },
        { gfxrecon::format::ApiCall_IDXGIOutput5_DuplicateOutput1, "ApiCall_IDXGIOutput5_DuplicateOutput1" },
        { gfxrecon::format::ApiCall_IDXGISwapChain4_SetHDRMetaData, "ApiCall_IDXGISwapChain4_SetHDRMetaData" },
        { gfxrecon::format::ApiCall_IDXGIDevice4_OfferResources1, "ApiCall_IDXGIDevice4_OfferResources1" },
        { gfxrecon::format::ApiCall_IDXGIDevice4_ReclaimResources1, "ApiCall_IDXGIDevice4_ReclaimResources1" },
        { gfxrecon::format::ApiCall_IDXGIFactory5_CheckFeatureSupport, "ApiCall_IDXGIFactory5_CheckFeatureSupport" },
        { gfxrecon::format::ApiCall_DXGIDeclareAdapterRemovalSupport, "ApiCall_DXGIDeclareAdapterRemovalSupport" },
        { gfxrecon::format::ApiCall_IDXGIAdapter4_GetDesc3, "ApiCall_IDXGIAdapter4_GetDesc3" },
        { gfxrecon::format::ApiCall_IDXGIOutput6_GetDesc1, "ApiCall_IDXGIOutput6_GetDesc1" },
        { gfxrecon::format::ApiCall_IDXGIOutput6_CheckHardwareCompositionSupport, "ApiCall_IDXGIOutput6_CheckHardwareCompositionSupport" },
        { gfxrecon::format::ApiCall_IDXGIFactory6_EnumAdapterByGpuPreference, "ApiCall_IDXGIFactory6_EnumAdapterByGpuPreference" },
        { gfxrecon::format::ApiCall_IDXGIFactory7_RegisterAdaptersChangedEvent, "ApiCall_IDXGIFactory7_RegisterAdaptersChangedEvent" },
        { gfxrecon::format::ApiCall_IDXGIFactory7_UnregisterAdaptersChangedEvent, "ApiCall_IDXGIFactory7_UnregisterAdaptersChangedEvent" },
        { gfxrecon::format::ApiCall_IUnknown_QueryInterface, "ApiCall_IUnknown_QueryInterface" },
        { gfxrecon::format::ApiCall_IUnknown_AddRef, "ApiCall_IUnknown_AddRef" },
        { gfxrecon::format::ApiCall_IUnknown_Release, "ApiCall_IUnknown_Release" },
        { gfxrecon::format::ApiCall_D3D12SerializeRootSignature, "ApiCall_D3D12SerializeRootSignature" },
        { gfxrecon::format::ApiCall_D3D12CreateRootSignatureDeserializer, "ApiCall_D3D12CreateRootSignatureDeserializer" },
        { gfxrecon::format::ApiCall_D3D12SerializeVersionedRootSignature, "ApiCall_D3D12SerializeVersionedRootSignature" },
        { gfxrecon::format::ApiCall_D3D12CreateVersionedRootSignatureDeserializer, "ApiCall_D3D12CreateVersionedRootSignatureDeserializer" },
        { gfxrecon::format::ApiCall_D3D12CreateDevice, "ApiCall_D3D12CreateDevice" },
        { gfxrecon::format::ApiCall_D3D12GetDebugInterface, "ApiCall_D3D12GetDebugInterface" },
        { gfxrecon::format::ApiCall_D3D12EnableExperimentalFeatures, "ApiCall_D3D12EnableExperimentalFeatures" },
        { gfxrecon::format::ApiCall_ID3D12Object_GetPrivateData, "ApiCall_ID3D12Object_GetPrivateData" },
        { gfxrecon::format::ApiCall_ID3D12Object_SetPrivateData, "ApiCall_ID3D12Object_SetPrivateData" },
        { gfxrecon::format::ApiCall_ID3D12Object_SetPrivateDataInterface, "ApiCall_ID3D12Object_SetPrivateDataInterface" },
        { gfxrecon::format::ApiCall_ID3D12Object_SetName, "ApiCall_ID3D12Object_SetName" },
        { gfxrecon::format::ApiCall_ID3D12DeviceChild_GetDevice, "ApiCall_ID3D12DeviceChild_GetDevice" },
        { gfxrecon::format::ApiCall_ID3D12RootSignatureDeserializer_GetRootSignatureDesc, "ApiCall_ID3D12RootSignatureDeserializer_GetRootSignatureDesc" },
        { gfxrecon::format::ApiCall_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion, "ApiCall_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion" },
        { gfxrecon::format::ApiCall_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc, "ApiCall_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc" },
        { gfxrecon::format::ApiCall_ID3D12Heap_GetDesc, "ApiCall_ID3D12Heap_GetDesc" },
        { gfxrecon::format::ApiCall_ID3D12Resource_Map, "ApiCall_ID3D12Resource_Map" },
        { gfxrecon::format::ApiCall_ID3D12Resource_Unmap, "ApiCall_ID3D12Resource_Unmap" },
        { gfxrecon::format::ApiCall_ID3D12Resource_GetDesc, "ApiCall_ID3D12Resource_GetDesc" },
        { gfxrecon::format::ApiCall_ID3D12Resource_GetGPUVirtualAddress, "ApiCall_ID3D12Resource_GetGPUVirtualAddress" },
        { gfxrecon::format::ApiCall_ID3D12Resource_WriteToSubresource, "ApiCall_ID3D12Resource_WriteToSubresource" },
        { gfxrecon::format::ApiCall_ID3D12Resource_ReadFromSubresource, "ApiCall_ID3D12Resource_ReadFromSubresource" },
        { gfxrecon::format::ApiCall_ID3D12Resource_GetHeapProperties, "ApiCall_ID3D12Resource_GetHeapProperties" },
        { gfxrecon::format::ApiCall_ID3D12CommandAllocator_Reset, "ApiCall_ID3D12CommandAllocator_Reset" },
        { gfxrecon::format::ApiCall_ID3D12Fence_GetCompletedValue, "ApiCall_ID3D12Fence_GetCompletedValue" },
        { gfxrecon::format::ApiCall_ID3D12Fence_SetEventOnCompletion, "ApiCall_ID3D12Fence_SetEventOnCompletion" },
        { gfxrecon::format::ApiCall_ID3D12Fence_Signal, "ApiCall_ID3D12Fence_Signal" },
        { gfxrecon::format::ApiCall_ID3D12Fence1_GetCreationFlags, "ApiCall_ID3D12Fence1_GetCreationFlags" },
        { gfxrecon::format::ApiCall_ID3D12PipelineState_GetCachedBlob, "ApiCall_ID3D12PipelineState_GetCachedBlob" },
        { gfxrecon::format::ApiCall_ID3D12DescriptorHeap_GetDesc, "ApiCall_ID3D12DescriptorHeap_GetDesc" },
        { gfxrecon::format::ApiCall_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart, "ApiCall_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart" },
        { gfxrecon::format::ApiCall_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart, "ApiCall_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart" },
        { gfxrecon::format::ApiCall_ID3D12CommandList_GetType, "ApiCall_ID3D12CommandList_GetType" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_Close, "ApiCall_ID3D12GraphicsCommandList_Close" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_Reset, "ApiCall_ID3D12GraphicsCommandList_Reset" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_ClearState, "ApiCall_ID3D12GraphicsCommandList_ClearState" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_DrawInstanced, "ApiCall_ID3D12GraphicsCommandList_DrawInstanced" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_DrawIndexedInstanced, "ApiCall_ID3D12GraphicsCommandList_DrawIndexedInstanced" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_Dispatch, "ApiCall_ID3D12GraphicsCommandList_Dispatch" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_CopyBufferRegion, "ApiCall_ID3D12GraphicsCommandList_CopyBufferRegion" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_CopyTextureRegion, "ApiCall_ID3D12GraphicsCommandList_CopyTextureRegion" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_CopyResource, "ApiCall_ID3D12GraphicsCommandList_CopyResource" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_CopyTiles, "ApiCall_ID3D12GraphicsCommandList_CopyTiles" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_ResolveSubresource, "ApiCall_ID3D12GraphicsCommandList_ResolveSubresource" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_IASetPrimitiveTopology, "ApiCall_ID3D12GraphicsCommandList_IASetPrimitiveTopology" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_RSSetViewports, "ApiCall_ID3D12GraphicsCommandList_RSSetViewports" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_RSSetScissorRects, "ApiCall_ID3D12GraphicsCommandList_RSSetScissorRects" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_OMSetBlendFactor, "ApiCall_ID3D12GraphicsCommandList_OMSetBlendFactor" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_OMSetStencilRef, "ApiCall_ID3D12GraphicsCommandList_OMSetStencilRef" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_SetPipelineState, "ApiCall_ID3D12GraphicsCommandList_SetPipelineState" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_ResourceBarrier, "ApiCall_ID3D12GraphicsCommandList_ResourceBarrier" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_ExecuteBundle, "ApiCall_ID3D12GraphicsCommandList_ExecuteBundle" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_SetDescriptorHeaps, "ApiCall_ID3D12GraphicsCommandList_SetDescriptorHeaps" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_SetComputeRootSignature, "ApiCall_ID3D12GraphicsCommandList_SetComputeRootSignature" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootSignature, "ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootSignature" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable, "ApiCall_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable, "ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant, "ApiCall_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant, "ApiCall_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants, "ApiCall_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants, "ApiCall_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView, "ApiCall_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView, "ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView, "ApiCall_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView, "ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView, "ApiCall_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView, "ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_IASetIndexBuffer, "ApiCall_ID3D12GraphicsCommandList_IASetIndexBuffer" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_IASetVertexBuffers, "ApiCall_ID3D12GraphicsCommandList_IASetVertexBuffers" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_SOSetTargets, "ApiCall_ID3D12GraphicsCommandList_SOSetTargets" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_OMSetRenderTargets, "ApiCall_ID3D12GraphicsCommandList_OMSetRenderTargets" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_ClearDepthStencilView, "ApiCall_ID3D12GraphicsCommandList_ClearDepthStencilView" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_ClearRenderTargetView, "ApiCall_ID3D12GraphicsCommandList_ClearRenderTargetView" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint, "ApiCall_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat, "ApiCall_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_DiscardResource, "ApiCall_ID3D12GraphicsCommandList_DiscardResource" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_BeginQuery, "ApiCall_ID3D12GraphicsCommandList_BeginQuery" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_EndQuery, "ApiCall_ID3D12GraphicsCommandList_EndQuery" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_ResolveQueryData, "ApiCall_ID3D12GraphicsCommandList_ResolveQueryData" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_SetPredication, "ApiCall_ID3D12GraphicsCommandList_SetPredication" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_SetMarker, "ApiCall_ID3D12GraphicsCommandList_SetMarker" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_BeginEvent, "ApiCall_ID3D12GraphicsCommandList_BeginEvent" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_EndEvent, "ApiCall_ID3D12GraphicsCommandList_EndEvent" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList_ExecuteIndirect, "ApiCall_ID3D12GraphicsCommandList_ExecuteIndirect" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT, "ApiCall_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64, "ApiCall_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList1_OMSetDepthBounds, "ApiCall_ID3D12GraphicsCommandList1_OMSetDepthBounds" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList1_SetSamplePositions, "ApiCall_ID3D12GraphicsCommandList1_SetSamplePositions" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList1_ResolveSubresourceRegion, "ApiCall_ID3D12GraphicsCommandList1_ResolveSubresourceRegion" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList1_SetViewInstanceMask, "ApiCall_ID3D12GraphicsCommandList1_SetViewInstanceMask" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList2_WriteBufferImmediate, "ApiCall_ID3D12GraphicsCommandList2_WriteBufferImmediate" },
        { gfxrecon::format::ApiCall_ID3D12CommandQueue_UpdateTileMappings, "ApiCall_ID3D12CommandQueue_UpdateTileMappings" },
        { gfxrecon::format::ApiCall_ID3D12CommandQueue_CopyTileMappings, "ApiCall_ID3D12CommandQueue_CopyTileMappings" },
        { gfxrecon::format::ApiCall_ID3D12CommandQueue_ExecuteCommandLists, "ApiCall_ID3D12CommandQueue_ExecuteCommandLists" },
        { gfxrecon::format::ApiCall_ID3D12CommandQueue_SetMarker, "ApiCall_ID3D12CommandQueue_SetMarker" },
        { gfxrecon::format::ApiCall_ID3D12CommandQueue_BeginEvent, "ApiCall_ID3D12CommandQueue_BeginEvent" },
        { gfxrecon::format::ApiCall_ID3D12CommandQueue_EndEvent, "ApiCall_ID3D12CommandQueue_EndEvent" },
        { gfxrecon::format::ApiCall_ID3D12CommandQueue_Signal, "ApiCall_ID3D12CommandQueue_Signal" },
        { gfxrecon::format::ApiCall_ID3D12CommandQueue_Wait, "ApiCall_ID3D12CommandQueue_Wait" },
        { gfxrecon::format::ApiCall_ID3D12CommandQueue_GetTimestampFrequency, "ApiCall_ID3D12CommandQueue_GetTimestampFrequency" },
        { gfxrecon::format::ApiCall_ID3D12CommandQueue_GetClockCalibration, "ApiCall_ID3D12CommandQueue_GetClockCalibration" },
        { gfxrecon::format::ApiCall_ID3D12CommandQueue_GetDesc, "ApiCall_ID3D12CommandQueue_GetDesc" },
        { gfxrecon::format::ApiCall_ID3D12Device_GetNodeCount, "ApiCall_ID3D12Device_GetNodeCount" },
        { gfxrecon::format::ApiCall_ID3D12Device_CreateCommandQueue, "ApiCall_ID3D12Device_CreateCommandQueue" },
        { gfxrecon::format::ApiCall_ID3D12Device_CreateCommandAllocator, "ApiCall_ID3D12Device_CreateCommandAllocator" },
        { gfxrecon::format::ApiCall_ID3D12Device_CreateGraphicsPipelineState, "ApiCall_ID3D12Device_CreateGraphicsPipelineState" },
        { gfxrecon::format::ApiCall_ID3D12Device_CreateComputePipelineState, "ApiCall_ID3D12Device_CreateComputePipelineState" },
        { gfxrecon::format::ApiCall_ID3D12Device_CreateCommandList, "ApiCall_ID3D12Device_CreateCommandList" },
        { gfxrecon::format::ApiCall_ID3D12Device_CheckFeatureSupport, "ApiCall_ID3D12Device_CheckFeatureSupport" },
        { gfxrecon::format::ApiCall_ID3D12Device_CreateDescriptorHeap, "ApiCall_ID3D12Device_CreateDescriptorHeap" },
        { gfxrecon::format::ApiCall_ID3D12Device_GetDescriptorHandleIncrementSize, "ApiCall_ID3D12Device_GetDescriptorHandleIncrementSize" },
        { gfxrecon::format::ApiCall_ID3D12Device_CreateRootSignature, "ApiCall_ID3D12Device_CreateRootSignature" },
        { gfxrecon::format::ApiCall_ID3D12Device_CreateConstantBufferView, "ApiCall_ID3D12Device_CreateConstantBufferView" },
        { gfxrecon::format::ApiCall_ID3D12Device_CreateShaderResourceView, "ApiCall_ID3D12Device_CreateShaderResourceView" },
        { gfxrecon::format::ApiCall_ID3D12Device_CreateUnorderedAccessView, "ApiCall_ID3D12Device_CreateUnorderedAccessView" },
        { gfxrecon::format::ApiCall_ID3D12Device_CreateRenderTargetView, "ApiCall_ID3D12Device_CreateRenderTargetView" },
        { gfxrecon::format::ApiCall_ID3D12Device_CreateDepthStencilView, "ApiCall_ID3D12Device_CreateDepthStencilView" },
        { gfxrecon::format::ApiCall_ID3D12Device_CreateSampler, "ApiCall_ID3D12Device_CreateSampler" },
        { gfxrecon::format::ApiCall_ID3D12Device_CopyDescriptors, "ApiCall_ID3D12Device_CopyDescriptors" },
        { gfxrecon::format::ApiCall_ID3D12Device_CopyDescriptorsSimple, "ApiCall_ID3D12Device_CopyDescriptorsSimple" },
        { gfxrecon::format::ApiCall_ID3D12Device_GetResourceAllocationInfo, "ApiCall_ID3D12Device_GetResourceAllocationInfo" },
        { gfxrecon::format::ApiCall_ID3D12Device_GetCustomHeapProperties, "ApiCall_ID3D12Device_GetCustomHeapProperties" },
        { gfxrecon::format::ApiCall_ID3D12Device_CreateCommittedResource, "ApiCall_ID3D12Device_CreateCommittedResource" },
        { gfxrecon::format::ApiCall_ID3D12Device_CreateHeap, "ApiCall_ID3D12Device_CreateHeap" },
        { gfxrecon::format::ApiCall_ID3D12Device_CreatePlacedResource, "ApiCall_ID3D12Device_CreatePlacedResource" },
        { gfxrecon::format::ApiCall_ID3D12Device_CreateReservedResource, "ApiCall_ID3D12Device_CreateReservedResource" },
        { gfxrecon::format::ApiCall_ID3D12Device_CreateSharedHandle, "ApiCall_ID3D12Device_CreateSharedHandle" },
        { gfxrecon::format::ApiCall_ID3D12Device_OpenSharedHandle, "ApiCall_ID3D12Device_OpenSharedHandle" },
        { gfxrecon::format::ApiCall_ID3D12Device_OpenSharedHandleByName, "ApiCall_ID3D12Device_OpenSharedHandleByName" },
        { gfxrecon::format::ApiCall_ID3D12Device_MakeResident, "ApiCall_ID3D12Device_MakeResident" },
        { gfxrecon::format::ApiCall_ID3D12Device_Evict, "ApiCall_ID3D12Device_Evict" },
        { gfxrecon::format::ApiCall_ID3D12Device_CreateFence, "ApiCall_ID3D12Device_CreateFence" },
        { gfxrecon::format::ApiCall_ID3D12Device_GetDeviceRemovedReason, "ApiCall_ID3D12Device_GetDeviceRemovedReason" },
        { gfxrecon::format::ApiCall_ID3D12Device_GetCopyableFootprints, "ApiCall_ID3D12Device_GetCopyableFootprints" },
        { gfxrecon::format::ApiCall_ID3D12Device_CreateQueryHeap, "ApiCall_ID3D12Device_CreateQueryHeap" },
        { gfxrecon::format::ApiCall_ID3D12Device_SetStablePowerState, "ApiCall_ID3D12Device_SetStablePowerState" },
        { gfxrecon::format::ApiCall_ID3D12Device_CreateCommandSignature, "ApiCall_ID3D12Device_CreateCommandSignature" },
        { gfxrecon::format::ApiCall_ID3D12Device_GetResourceTiling, "ApiCall_ID3D12Device_GetResourceTiling" },
        { gfxrecon::format::ApiCall_ID3D12Device_GetAdapterLuid, "ApiCall_ID3D12Device_GetAdapterLuid" },
        { gfxrecon::format::ApiCall_ID3D12PipelineLibrary_StorePipeline, "ApiCall_ID3D12PipelineLibrary_StorePipeline" },
        { gfxrecon::format::ApiCall_ID3D12PipelineLibrary_LoadGraphicsPipeline, "ApiCall_ID3D12PipelineLibrary_LoadGraphicsPipeline" },
        { gfxrecon::format::ApiCall_ID3D12PipelineLibrary_LoadComputePipeline, "ApiCall_ID3D12PipelineLibrary_LoadComputePipeline" },
        { gfxrecon::format::ApiCall_ID3D12PipelineLibrary_GetSerializedSize, "ApiCall_ID3D12PipelineLibrary_GetSerializedSize" },
        { gfxrecon::format::ApiCall_ID3D12PipelineLibrary_Serialize, "ApiCall_ID3D12PipelineLibrary_Serialize" },
        { gfxrecon::format::ApiCall_ID3D12PipelineLibrary1_LoadPipeline, "ApiCall_ID3D12PipelineLibrary1_LoadPipeline" },
        { gfxrecon::format::ApiCall_ID3D12Device1_CreatePipelineLibrary, "ApiCall_ID3D12Device1_CreatePipelineLibrary" },
        { gfxrecon::format::ApiCall_ID3D12Device1_SetEventOnMultipleFenceCompletion, "ApiCall_ID3D12Device1_SetEventOnMultipleFenceCompletion" },
        { gfxrecon::format::ApiCall_ID3D12Device1_SetResidencyPriority, "ApiCall_ID3D12Device1_SetResidencyPriority" },
        { gfxrecon::format::ApiCall_ID3D12Device2_CreatePipelineState, "ApiCall_ID3D12Device2_CreatePipelineState" },
        { gfxrecon::format::ApiCall_ID3D12Device3_OpenExistingHeapFromAddress, "ApiCall_ID3D12Device3_OpenExistingHeapFromAddress" },
        { gfxrecon::format::ApiCall_ID3D12Device3_OpenExistingHeapFromFileMapping, "ApiCall_ID3D12Device3_OpenExistingHeapFromFileMapping" },
        { gfxrecon::format::ApiCall_ID3D12Device3_EnqueueMakeResident, "ApiCall_ID3D12Device3_EnqueueMakeResident" },
        { gfxrecon::format::ApiCall_ID3D12ProtectedSession_GetStatusFence, "ApiCall_ID3D12ProtectedSession_GetStatusFence" },
        { gfxrecon::format::ApiCall_ID3D12ProtectedSession_GetSessionStatus, "ApiCall_ID3D12ProtectedSession_GetSessionStatus" },
        { gfxrecon::format::ApiCall_ID3D12ProtectedResourceSession_GetDesc, "ApiCall_ID3D12ProtectedResourceSession_GetDesc" },
        { gfxrecon::format::ApiCall_ID3D12Device4_CreateCommandList1, "ApiCall_ID3D12Device4_CreateCommandList1" },
        { gfxrecon::format::ApiCall_ID3D12Device4_CreateProtectedResourceSession, "ApiCall_ID3D12Device4_CreateProtectedResourceSession" },
        { gfxrecon::format::ApiCall_ID3D12Device4_CreateCommittedResource1, "ApiCall_ID3D12Device4_CreateCommittedResource1" },
        { gfxrecon::format::ApiCall_ID3D12Device4_CreateHeap1, "ApiCall_ID3D12Device4_CreateHeap1" },
        { gfxrecon::format::ApiCall_ID3D12Device4_CreateReservedResource1, "ApiCall_ID3D12Device4_CreateReservedResource1" },
        { gfxrecon::format::ApiCall_ID3D12Device4_GetResourceAllocationInfo1, "ApiCall_ID3D12Device4_GetResourceAllocationInfo1" },
        { gfxrecon::format::ApiCall_ID3D12LifetimeOwner_LifetimeStateUpdated, "ApiCall_ID3D12LifetimeOwner_LifetimeStateUpdated" },
        { gfxrecon::format::ApiCall_ID3D12SwapChainAssistant_GetLUID, "ApiCall_ID3D12SwapChainAssistant_GetLUID" },
        { gfxrecon::format::ApiCall_ID3D12SwapChainAssistant_GetSwapChainObject, "ApiCall_ID3D12SwapChainAssistant_GetSwapChainObject" },
        { gfxrecon::format::ApiCall_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue, "ApiCall_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue" },
        { gfxrecon::format::ApiCall_ID3D12SwapChainAssistant_InsertImplicitSync, "ApiCall_ID3D12SwapChainAssistant_InsertImplicitSync" },
        { gfxrecon::format::ApiCall_ID3D12LifetimeTracker_DestroyOwnedObject, "ApiCall_ID3D12LifetimeTracker_DestroyOwnedObject" },
        { gfxrecon::format::ApiCall_ID3D12StateObjectProperties_GetShaderIdentifier, "ApiCall_ID3D12StateObjectProperties_GetShaderIdentifier" },
        { gfxrecon::format::ApiCall_ID3D12StateObjectProperties_GetShaderStackSize, "ApiCall_ID3D12StateObjectProperties_GetShaderStackSize" },
        { gfxrecon::format::ApiCall_ID3D12StateObjectProperties_GetPipelineStackSize, "ApiCall_ID3D12StateObjectProperties_GetPipelineStackSize" },
        { gfxrecon::format::ApiCall_ID3D12StateObjectProperties_SetPipelineStackSize, "ApiCall_ID3D12StateObjectProperties_SetPipelineStackSize" },
        { gfxrecon::format::ApiCall_ID3D12Device5_CreateLifetimeTracker, "ApiCall_ID3D12Device5_CreateLifetimeTracker" },
        { gfxrecon::format::ApiCall_ID3D12Device5_RemoveDevice, "ApiCall_ID3D12Device5_RemoveDevice" },
        { gfxrecon::format::ApiCall_ID3D12Device5_EnumerateMetaCommands, "ApiCall_ID3D12Device5_EnumerateMetaCommands" },
        { gfxrecon::format::ApiCall_ID3D12Device5_EnumerateMetaCommandParameters, "ApiCall_ID3D12Device5_EnumerateMetaCommandParameters" },
        { gfxrecon::format::ApiCall_ID3D12Device5_CreateMetaCommand, "ApiCall_ID3D12Device5_CreateMetaCommand" },
        { gfxrecon::format::ApiCall_ID3D12Device5_CreateStateObject, "ApiCall_ID3D12Device5_CreateStateObject" },
        { gfxrecon::format::ApiCall_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo, "ApiCall_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo" },
        { gfxrecon::format::ApiCall_ID3D12Device5_CheckDriverMatchingIdentifier, "ApiCall_ID3D12Device5_CheckDriverMatchingIdentifier" },
        { gfxrecon::format::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement, "ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement" },
        { gfxrecon::format::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement, "ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement" },
        { gfxrecon::format::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement, "ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement" },
        { gfxrecon::format::ApiCall_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement, "ApiCall_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement" },
        { gfxrecon::format::ApiCall_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput, "ApiCall_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput" },
        { gfxrecon::format::ApiCall_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput, "ApiCall_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput" },
        { gfxrecon::format::ApiCall_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1, "ApiCall_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1" },
        { gfxrecon::format::ApiCall_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1, "ApiCall_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1" },
        { gfxrecon::format::ApiCall_ID3D12Device6_SetBackgroundProcessingMode, "ApiCall_ID3D12Device6_SetBackgroundProcessingMode" },
        { gfxrecon::format::ApiCall_ID3D12ProtectedResourceSession1_GetDesc1, "ApiCall_ID3D12ProtectedResourceSession1_GetDesc1" },
        { gfxrecon::format::ApiCall_ID3D12Device7_AddToStateObject, "ApiCall_ID3D12Device7_AddToStateObject" },
        { gfxrecon::format::ApiCall_ID3D12Device7_CreateProtectedResourceSession1, "ApiCall_ID3D12Device7_CreateProtectedResourceSession1" },
        { gfxrecon::format::ApiCall_ID3D12Device8_GetResourceAllocationInfo2, "ApiCall_ID3D12Device8_GetResourceAllocationInfo2" },
        { gfxrecon::format::ApiCall_ID3D12Device8_CreateCommittedResource2, "ApiCall_ID3D12Device8_CreateCommittedResource2" },
        { gfxrecon::format::ApiCall_ID3D12Device8_CreatePlacedResource1, "ApiCall_ID3D12Device8_CreatePlacedResource1" },
        { gfxrecon::format::ApiCall_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView, "ApiCall_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView" },
        { gfxrecon::format::ApiCall_ID3D12Device8_GetCopyableFootprints1, "ApiCall_ID3D12Device8_GetCopyableFootprints1" },
        { gfxrecon::format::ApiCall_ID3D12Resource1_GetProtectedResourceSession, "ApiCall_ID3D12Resource1_GetProtectedResourceSession" },
        { gfxrecon::format::ApiCall_ID3D12Resource2_GetDesc1, "ApiCall_ID3D12Resource2_GetDesc1" },
        { gfxrecon::format::ApiCall_ID3D12Heap1_GetProtectedResourceSession, "ApiCall_ID3D12Heap1_GetProtectedResourceSession" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList3_SetProtectedResourceSession, "ApiCall_ID3D12GraphicsCommandList3_SetProtectedResourceSession" },
        { gfxrecon::format::ApiCall_ID3D12MetaCommand_GetRequiredParameterResourceSize, "ApiCall_ID3D12MetaCommand_GetRequiredParameterResourceSize" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList4_BeginRenderPass, "ApiCall_ID3D12GraphicsCommandList4_BeginRenderPass" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList4_EndRenderPass, "ApiCall_ID3D12GraphicsCommandList4_EndRenderPass" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList4_InitializeMetaCommand, "ApiCall_ID3D12GraphicsCommandList4_InitializeMetaCommand" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList4_ExecuteMetaCommand, "ApiCall_ID3D12GraphicsCommandList4_ExecuteMetaCommand" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure, "ApiCall_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo, "ApiCall_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure, "ApiCall_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList4_SetPipelineState1, "ApiCall_ID3D12GraphicsCommandList4_SetPipelineState1" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList4_DispatchRays, "ApiCall_ID3D12GraphicsCommandList4_DispatchRays" },
        { gfxrecon::format::ApiCall_ID3D12Tools_EnableShaderInstrumentation, "ApiCall_ID3D12Tools_EnableShaderInstrumentation" },
        { gfxrecon::format::ApiCall_ID3D12Tools_ShaderInstrumentationEnabled, "ApiCall_ID3D12Tools_ShaderInstrumentationEnabled" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList5_RSSetShadingRate, "ApiCall_ID3D12GraphicsCommandList5_RSSetShadingRate" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList5_RSSetShadingRateImage, "ApiCall_ID3D12GraphicsCommandList5_RSSetShadingRateImage" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList6_DispatchMesh, "ApiCall_ID3D12GraphicsCommandList6_DispatchMesh" },
        { gfxrecon::format::ApiCall_ID3D10Blob_GetBufferPointer, "ApiCall_ID3D10Blob_GetBufferPointer" },
        { gfxrecon::format::ApiCall_ID3D10Blob_GetBufferSize, "ApiCall_ID3D10Blob_GetBufferSize" },
        { gfxrecon::format::ApiCall_ID3DDestructionNotifier_RegisterDestructionCallback, "ApiCall_ID3DDestructionNotifier_RegisterDestructionCallback" },
        { gfxrecon::format::ApiCall_ID3DDestructionNotifier_UnregisterDestructionCallback, "ApiCall_ID3DDestructionNotifier_UnregisterDestructionCallback" },
        { gfxrecon::format::ApiCall_ID3D12Debug_EnableDebugLayer, "ApiCall_ID3D12Debug_EnableDebugLayer" },
        { gfxrecon::format::ApiCall_ID3D12Debug1_EnableDebugLayer, "ApiCall_ID3D12Debug1_EnableDebugLayer" },
        { gfxrecon::format::ApiCall_ID3D12Debug1_SetEnableGPUBasedValidation, "ApiCall_ID3D12Debug1_SetEnableGPUBasedValidation" },
        { gfxrecon::format::ApiCall_ID3D12Debug1_SetEnableSynchronizedCommandQueueValidation, "ApiCall_ID3D12Debug1_SetEnableSynchronizedCommandQueueValidation" },
        { gfxrecon::format::ApiCall_ID3D12Debug2_SetGPUBasedValidationFlags, "ApiCall_ID3D12Debug2_SetGPUBasedValidationFlags" },
        { gfxrecon::format::ApiCall_ID3D12Debug3_SetEnableGPUBasedValidation, "ApiCall_ID3D12Debug3_SetEnableGPUBasedValidation" },
        { gfxrecon::format::ApiCall_ID3D12Debug3_SetEnableSynchronizedCommandQueueValidation, "ApiCall_ID3D12Debug3_SetEnableSynchronizedCommandQueueValidation" },
        { gfxrecon::format::ApiCall_ID3D12Debug3_SetGPUBasedValidationFlags, "ApiCall_ID3D12Debug3_SetGPUBasedValidationFlags" },
        { gfxrecon::format::ApiCall_ID3D12DebugDevice1_SetDebugParameter, "ApiCall_ID3D12DebugDevice1_SetDebugParameter" },
        { gfxrecon::format::ApiCall_ID3D12DebugDevice1_GetDebugParameter, "ApiCall_ID3D12DebugDevice1_GetDebugParameter" },
        { gfxrecon::format::ApiCall_ID3D12DebugDevice1_ReportLiveDeviceObjects, "ApiCall_ID3D12DebugDevice1_ReportLiveDeviceObjects" },
        { gfxrecon::format::ApiCall_ID3D12DebugDevice_SetFeatureMask, "ApiCall_ID3D12DebugDevice_SetFeatureMask" },
        { gfxrecon::format::ApiCall_ID3D12DebugDevice_GetFeatureMask, "ApiCall_ID3D12DebugDevice_GetFeatureMask" },
        { gfxrecon::format::ApiCall_ID3D12DebugDevice_ReportLiveDeviceObjects, "ApiCall_ID3D12DebugDevice_ReportLiveDeviceObjects" },
        { gfxrecon::format::ApiCall_ID3D12DebugDevice2_SetDebugParameter, "ApiCall_ID3D12DebugDevice2_SetDebugParameter" },
        { gfxrecon::format::ApiCall_ID3D12DebugDevice2_GetDebugParameter, "ApiCall_ID3D12DebugDevice2_GetDebugParameter" },
        { gfxrecon::format::ApiCall_ID3D12DebugCommandQueue_AssertResourceState, "ApiCall_ID3D12DebugCommandQueue_AssertResourceState" },
        { gfxrecon::format::ApiCall_ID3D12DebugCommandList1_AssertResourceState, "ApiCall_ID3D12DebugCommandList1_AssertResourceState" },
        { gfxrecon::format::ApiCall_ID3D12DebugCommandList1_SetDebugParameter, "ApiCall_ID3D12DebugCommandList1_SetDebugParameter" },
        { gfxrecon::format::ApiCall_ID3D12DebugCommandList1_GetDebugParameter, "ApiCall_ID3D12DebugCommandList1_GetDebugParameter" },
        { gfxrecon::format::ApiCall_ID3D12DebugCommandList_AssertResourceState, "ApiCall_ID3D12DebugCommandList_AssertResourceState" },
        { gfxrecon::format::ApiCall_ID3D12DebugCommandList_SetFeatureMask, "ApiCall_ID3D12DebugCommandList_SetFeatureMask" },
        { gfxrecon::format::ApiCall_ID3D12DebugCommandList_GetFeatureMask, "ApiCall_ID3D12DebugCommandList_GetFeatureMask" },
        { gfxrecon::format::ApiCall_ID3D12DebugCommandList2_SetDebugParameter, "ApiCall_ID3D12DebugCommandList2_SetDebugParameter" },
        { gfxrecon::format::ApiCall_ID3D12DebugCommandList2_GetDebugParameter, "ApiCall_ID3D12DebugCommandList2_GetDebugParameter" },
        { gfxrecon::format::ApiCall_ID3D12SharingContract_Present, "ApiCall_ID3D12SharingContract_Present" },
        { gfxrecon::format::ApiCall_ID3D12SharingContract_SharedFenceSignal, "ApiCall_ID3D12SharingContract_SharedFenceSignal" },
        { gfxrecon::format::ApiCall_ID3D12SharingContract_BeginCapturableWork, "ApiCall_ID3D12SharingContract_BeginCapturableWork" },
        { gfxrecon::format::ApiCall_ID3D12SharingContract_EndCapturableWork, "ApiCall_ID3D12SharingContract_EndCapturableWork" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_SetMessageCountLimit, "ApiCall_ID3D12InfoQueue_SetMessageCountLimit" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_ClearStoredMessages, "ApiCall_ID3D12InfoQueue_ClearStoredMessages" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_GetMessage, "ApiCall_ID3D12InfoQueue_GetMessage" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_GetNumMessagesAllowedByStorageFilter, "ApiCall_ID3D12InfoQueue_GetNumMessagesAllowedByStorageFilter" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_GetNumMessagesDeniedByStorageFilter, "ApiCall_ID3D12InfoQueue_GetNumMessagesDeniedByStorageFilter" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_GetNumStoredMessages, "ApiCall_ID3D12InfoQueue_GetNumStoredMessages" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_GetNumStoredMessagesAllowedByRetrievalFilter, "ApiCall_ID3D12InfoQueue_GetNumStoredMessagesAllowedByRetrievalFilter" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_GetNumMessagesDiscardedByMessageCountLimit, "ApiCall_ID3D12InfoQueue_GetNumMessagesDiscardedByMessageCountLimit" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_GetMessageCountLimit, "ApiCall_ID3D12InfoQueue_GetMessageCountLimit" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_AddStorageFilterEntries, "ApiCall_ID3D12InfoQueue_AddStorageFilterEntries" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_GetStorageFilter, "ApiCall_ID3D12InfoQueue_GetStorageFilter" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_ClearStorageFilter, "ApiCall_ID3D12InfoQueue_ClearStorageFilter" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_PushEmptyStorageFilter, "ApiCall_ID3D12InfoQueue_PushEmptyStorageFilter" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_PushCopyOfStorageFilter, "ApiCall_ID3D12InfoQueue_PushCopyOfStorageFilter" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_PushStorageFilter, "ApiCall_ID3D12InfoQueue_PushStorageFilter" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_PopStorageFilter, "ApiCall_ID3D12InfoQueue_PopStorageFilter" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_GetStorageFilterStackSize, "ApiCall_ID3D12InfoQueue_GetStorageFilterStackSize" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_AddRetrievalFilterEntries, "ApiCall_ID3D12InfoQueue_AddRetrievalFilterEntries" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_GetRetrievalFilter, "ApiCall_ID3D12InfoQueue_GetRetrievalFilter" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_ClearRetrievalFilter, "ApiCall_ID3D12InfoQueue_ClearRetrievalFilter" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_PushEmptyRetrievalFilter, "ApiCall_ID3D12InfoQueue_PushEmptyRetrievalFilter" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_PushCopyOfRetrievalFilter, "ApiCall_ID3D12InfoQueue_PushCopyOfRetrievalFilter" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_PushRetrievalFilter, "ApiCall_ID3D12InfoQueue_PushRetrievalFilter" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_PopRetrievalFilter, "ApiCall_ID3D12InfoQueue_PopRetrievalFilter" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_GetRetrievalFilterStackSize, "ApiCall_ID3D12InfoQueue_GetRetrievalFilterStackSize" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_AddMessage, "ApiCall_ID3D12InfoQueue_AddMessage" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_AddApplicationMessage, "ApiCall_ID3D12InfoQueue_AddApplicationMessage" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_SetBreakOnCategory, "ApiCall_ID3D12InfoQueue_SetBreakOnCategory" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_SetBreakOnSeverity, "ApiCall_ID3D12InfoQueue_SetBreakOnSeverity" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_SetBreakOnID, "ApiCall_ID3D12InfoQueue_SetBreakOnID" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_GetBreakOnCategory, "ApiCall_ID3D12InfoQueue_GetBreakOnCategory" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_GetBreakOnSeverity, "ApiCall_ID3D12InfoQueue_GetBreakOnSeverity" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_GetBreakOnID, "ApiCall_ID3D12InfoQueue_GetBreakOnID" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_SetMuteDebugOutput, "ApiCall_ID3D12InfoQueue_SetMuteDebugOutput" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue_GetMuteDebugOutput, "ApiCall_ID3D12InfoQueue_GetMuteDebugOutput" },
        { gfxrecon::format::ApiCall_D3D12GetInterface, "ApiCall_D3D12GetInterface" },
        { gfxrecon::format::ApiCall_ID3D12DeviceRemovedExtendedData2_GetPageFaultAllocationOutput2, "ApiCall_ID3D12DeviceRemovedExtendedData2_GetPageFaultAllocationOutput2" },
        { gfxrecon::format::ApiCall_ID3D12DeviceRemovedExtendedData2_GetDeviceState, "ApiCall_ID3D12DeviceRemovedExtendedData2_GetDeviceState" },
        { gfxrecon::format::ApiCall_ID3D12ShaderCacheSession_FindValue, "ApiCall_ID3D12ShaderCacheSession_FindValue" },
        { gfxrecon::format::ApiCall_ID3D12ShaderCacheSession_StoreValue, "ApiCall_ID3D12ShaderCacheSession_StoreValue" },
        { gfxrecon::format::ApiCall_ID3D12ShaderCacheSession_SetDeleteOnDestroy, "ApiCall_ID3D12ShaderCacheSession_SetDeleteOnDestroy" },
        { gfxrecon::format::ApiCall_ID3D12ShaderCacheSession_GetDesc, "ApiCall_ID3D12ShaderCacheSession_GetDesc" },
        { gfxrecon::format::ApiCall_ID3D12Device9_CreateShaderCacheSession, "ApiCall_ID3D12Device9_CreateShaderCacheSession" },
        { gfxrecon::format::ApiCall_ID3D12Device9_ShaderCacheControl, "ApiCall_ID3D12Device9_ShaderCacheControl" },
        { gfxrecon::format::ApiCall_ID3D12Device9_CreateCommandQueue1, "ApiCall_ID3D12Device9_CreateCommandQueue1" },
        { gfxrecon::format::ApiCall_ID3D12SDKConfiguration_SetSDKVersion, "ApiCall_ID3D12SDKConfiguration_SetSDKVersion" },
        { gfxrecon::format::ApiCall_ID3D12Debug4_DisableDebugLayer, "ApiCall_ID3D12Debug4_DisableDebugLayer" },
        { gfxrecon::format::ApiCall_ID3D12Debug5_SetEnableAutoName, "ApiCall_ID3D12Debug5_SetEnableAutoName" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue1_UnregisterMessageCallback, "ApiCall_ID3D12InfoQueue1_UnregisterMessageCallback" },
        { gfxrecon::format::ApiCall_ID3D12InfoQueue1_RegisterMessageCallback, "ApiCall_ID3D12InfoQueue1_RegisterMessageCallback" },
        { gfxrecon::format::ApiCall_ID3D12Device10_CreateCommittedResource3, "ApiCall_ID3D12Device10_CreateCommittedResource3" },
        { gfxrecon::format::ApiCall_ID3D12Device10_CreatePlacedResource2, "ApiCall_ID3D12Device10_CreatePlacedResource2" },
        { gfxrecon::format::ApiCall_ID3D12Device10_CreateReservedResource2, "ApiCall_ID3D12Device10_CreateReservedResource2" },
        { gfxrecon::format::ApiCall_ID3D12Device11_CreateSampler2, "ApiCall_ID3D12Device11_CreateSampler2" },
        { gfxrecon::format::ApiCall_ID3D12VirtualizationGuestDevice_ShareWithHost, "ApiCall_ID3D12VirtualizationGuestDevice_ShareWithHost" },
        { gfxrecon::format::ApiCall_ID3D12VirtualizationGuestDevice_CreateFenceFd, "ApiCall_ID3D12VirtualizationGuestDevice_CreateFenceFd" },
        { gfxrecon::format::ApiCall_ID3D12SDKConfiguration1_CreateDeviceFactory, "ApiCall_ID3D12SDKConfiguration1_CreateDeviceFactory" },
        { gfxrecon::format::ApiCall_ID3D12SDKConfiguration1_FreeUnusedSDKs, "ApiCall_ID3D12SDKConfiguration1_FreeUnusedSDKs" },
        { gfxrecon::format::ApiCall_ID3D12DeviceFactory_InitializeFromGlobalState, "ApiCall_ID3D12DeviceFactory_InitializeFromGlobalState" },
        { gfxrecon::format::ApiCall_ID3D12DeviceFactory_ApplyToGlobalState, "ApiCall_ID3D12DeviceFactory_ApplyToGlobalState" },
        { gfxrecon::format::ApiCall_ID3D12DeviceFactory_SetFlags, "ApiCall_ID3D12DeviceFactory_SetFlags" },
        { gfxrecon::format::ApiCall_ID3D12DeviceFactory_GetFlags, "ApiCall_ID3D12DeviceFactory_GetFlags" },
        { gfxrecon::format::ApiCall_ID3D12DeviceFactory_GetConfigurationInterface, "ApiCall_ID3D12DeviceFactory_GetConfigurationInterface" },
        { gfxrecon::format::ApiCall_ID3D12DeviceFactory_EnableExperimentalFeatures, "ApiCall_ID3D12DeviceFactory_EnableExperimentalFeatures" },
        { gfxrecon::format::ApiCall_ID3D12DeviceFactory_CreateDevice, "ApiCall_ID3D12DeviceFactory_CreateDevice" },
        { gfxrecon::format::ApiCall_ID3D12DeviceConfiguration_GetDesc, "ApiCall_ID3D12DeviceConfiguration_GetDesc" },
        { gfxrecon::format::ApiCall_ID3D12DeviceConfiguration_GetEnabledExperimentalFeatures, "ApiCall_ID3D12DeviceConfiguration_GetEnabledExperimentalFeatures" },
        { gfxrecon::format::ApiCall_ID3D12DeviceConfiguration_SerializeVersionedRootSignature, "ApiCall_ID3D12DeviceConfiguration_SerializeVersionedRootSignature" },
        { gfxrecon::format::ApiCall_ID3D12DeviceConfiguration_CreateVersionedRootSignatureDeserializer, "ApiCall_ID3D12DeviceConfiguration_CreateVersionedRootSignatureDeserializer" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList7_Barrier, "ApiCall_ID3D12GraphicsCommandList7_Barrier" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList8_OMSetFrontAndBackStencilRef, "ApiCall_ID3D12GraphicsCommandList8_OMSetFrontAndBackStencilRef" },
        { gfxrecon::format::ApiCall_ID3D12DeviceRemovedExtendedDataSettings2_UseMarkersOnlyAutoBreadcrumbs, "ApiCall_ID3D12DeviceRemovedExtendedDataSettings2_UseMarkersOnlyAutoBreadcrumbs" },
        { gfxrecon::format::ApiCall_ID3D12Debug6_SetForceLegacyBarrierValidation, "ApiCall_ID3D12Debug6_SetForceLegacyBarrierValidation" },
        { gfxrecon::format::ApiCall_ID3D12DebugCommandQueue1_AssertResourceAccess, "ApiCall_ID3D12DebugCommandQueue1_AssertResourceAccess" },
        { gfxrecon::format::ApiCall_ID3D12DebugCommandQueue1_AssertTextureLayout, "ApiCall_ID3D12DebugCommandQueue1_AssertTextureLayout" },
        { gfxrecon::format::ApiCall_ID3D12DebugCommandList3_AssertResourceAccess, "ApiCall_ID3D12DebugCommandList3_AssertResourceAccess" },
        { gfxrecon::format::ApiCall_ID3D12DebugCommandList3_AssertTextureLayout, "ApiCall_ID3D12DebugCommandList3_AssertTextureLayout" },
        { gfxrecon::format::ApiCall_ID3D12Device12_GetResourceAllocationInfo3, "ApiCall_ID3D12Device12_GetResourceAllocationInfo3" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList9_RSSetDepthBias, "ApiCall_ID3D12GraphicsCommandList9_RSSetDepthBias" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList9_IASetIndexBufferStripCutValue, "ApiCall_ID3D12GraphicsCommandList9_IASetIndexBufferStripCutValue" },
        { gfxrecon::format::ApiCall_ID3D12DSRDeviceFactory_CreateDSRDevice, "ApiCall_ID3D12DSRDeviceFactory_CreateDSRDevice" },
        { gfxrecon::format::ApiCall_ID3D12ManualWriteTrackingResource_TrackWrite, "ApiCall_ID3D12ManualWriteTrackingResource_TrackWrite" },
        { gfxrecon::format::ApiCall_D3D12CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary, "ApiCall_D3D12CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary" },
        { gfxrecon::format::ApiCall_ID3D12StateObjectProperties1_GetProgramIdentifier, "ApiCall_ID3D12StateObjectProperties1_GetProgramIdentifier" },
        { gfxrecon::format::ApiCall_ID3D12WorkGraphProperties_GetNumWorkGraphs, "ApiCall_ID3D12WorkGraphProperties_GetNumWorkGraphs" },
        { gfxrecon::format::ApiCall_ID3D12WorkGraphProperties_GetProgramName, "ApiCall_ID3D12WorkGraphProperties_GetProgramName" },
        { gfxrecon::format::ApiCall_ID3D12WorkGraphProperties_GetWorkGraphIndex, "ApiCall_ID3D12WorkGraphProperties_GetWorkGraphIndex" },
        { gfxrecon::format::ApiCall_ID3D12WorkGraphProperties_GetNumNodes, "ApiCall_ID3D12WorkGraphProperties_GetNumNodes" },
        { gfxrecon::format::ApiCall_ID3D12WorkGraphProperties_GetNodeID, "ApiCall_ID3D12WorkGraphProperties_GetNodeID" },
        { gfxrecon::format::ApiCall_ID3D12WorkGraphProperties_GetNodeIndex, "ApiCall_ID3D12WorkGraphProperties_GetNodeIndex" },
        { gfxrecon::format::ApiCall_ID3D12WorkGraphProperties_GetNodeLocalRootArgumentsTableIndex, "ApiCall_ID3D12WorkGraphProperties_GetNodeLocalRootArgumentsTableIndex" },
        { gfxrecon::format::ApiCall_ID3D12WorkGraphProperties_GetNumEntrypoints, "ApiCall_ID3D12WorkGraphProperties_GetNumEntrypoints" },
        { gfxrecon::format::ApiCall_ID3D12WorkGraphProperties_GetEntrypointID, "ApiCall_ID3D12WorkGraphProperties_GetEntrypointID" },
        { gfxrecon::format::ApiCall_ID3D12WorkGraphProperties_GetEntrypointIndex, "ApiCall_ID3D12WorkGraphProperties_GetEntrypointIndex" },
        { gfxrecon::format::ApiCall_ID3D12WorkGraphProperties_GetEntrypointRecordSizeInBytes, "ApiCall_ID3D12WorkGraphProperties_GetEntrypointRecordSizeInBytes" },
        { gfxrecon::format::ApiCall_ID3D12WorkGraphProperties_GetWorkGraphMemoryRequirements, "ApiCall_ID3D12WorkGraphProperties_GetWorkGraphMemoryRequirements" },
        { gfxrecon::format::ApiCall_ID3D12WorkGraphProperties_GetEntrypointRecordAlignmentInBytes, "ApiCall_ID3D12WorkGraphProperties_GetEntrypointRecordAlignmentInBytes" },
        { gfxrecon::format::ApiCall_ID3D12Device13_OpenExistingHeapFromAddress1, "ApiCall_ID3D12Device13_OpenExistingHeapFromAddress1" },
        { gfxrecon::format::ApiCall_ID3D12Device14_CreateRootSignatureFromSubobjectInLibrary, "ApiCall_ID3D12Device14_CreateRootSignatureFromSubobjectInLibrary" },
        { gfxrecon::format::ApiCall_ID3D12Tools1_ReserveGPUVARangesAtCreate, "ApiCall_ID3D12Tools1_ReserveGPUVARangesAtCreate" },
        { gfxrecon::format::ApiCall_ID3D12Tools1_ClearReservedGPUVARangesList, "ApiCall_ID3D12Tools1_ClearReservedGPUVARangesList" },
        { gfxrecon::format::ApiCall_ID3D12PageableTools_GetAllocation, "ApiCall_ID3D12PageableTools_GetAllocation" },
        { gfxrecon::format::ApiCall_ID3D12DeviceTools_SetNextAllocationAddress, "ApiCall_ID3D12DeviceTools_SetNextAllocationAddress" },
        { gfxrecon::format::ApiCall_ID3D12DeviceConfiguration1_CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary, "ApiCall_ID3D12DeviceConfiguration1_CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList10_SetProgram, "ApiCall_ID3D12GraphicsCommandList10_SetProgram" },
        { gfxrecon::format::ApiCall_ID3D12GraphicsCommandList10_DispatchGraph, "ApiCall_ID3D12GraphicsCommandList10_DispatchGraph" },
        { gfxrecon::format::ApiCall_ID3D12GBVDiagnostics_GetGBVEntireSubresourceStatesData, "ApiCall_ID3D12GBVDiagnostics_GetGBVEntireSubresourceStatesData" },
        { gfxrecon::format::ApiCall_ID3D12GBVDiagnostics_GetGBVSubresourceState, "ApiCall_ID3D12GBVDiagnostics_GetGBVSubresourceState" },
        { gfxrecon::format::ApiCall_ID3D12GBVDiagnostics_GetGBVResourceUniformState, "ApiCall_ID3D12GBVDiagnostics_GetGBVResourceUniformState" },
        { gfxrecon::format::ApiCall_ID3D12GBVDiagnostics_GetGBVResourceInfo, "ApiCall_ID3D12GBVDiagnostics_GetGBVResourceInfo" },
        { gfxrecon::format::ApiCall_ID3D12GBVDiagnostics_GBVReserved0, "ApiCall_ID3D12GBVDiagnostics_GBVReserved0" },
        { gfxrecon::format::ApiCall_ID3D12GBVDiagnostics_GBVReserved1, "ApiCall_ID3D12GBVDiagnostics_GBVReserved1" },
        { gfxrecon::format::ApiCall_Ags_agsInitialize_6_0_1, "ApiCall_Ags_agsInitialize_6_0_1" },
        { gfxrecon::format::ApiCall_Ags_agsDeInitialize_6_0_1, "ApiCall_Ags_agsDeInitialize_6_0_1" },
        { gfxrecon::format::ApiCall_Ags_agsDriverExtensionsDX12_CreateDevice_6_0_1, "ApiCall_Ags_agsDriverExtensionsDX12_CreateDevice_6_0_1" },
        { gfxrecon::format::ApiCall_Ags_agsDriverExtensionsDX12_DestroyDevice_6_0_1, "ApiCall_Ags_agsDriverExtensionsDX12_DestroyDevice_6_0_1" },
        { gfxrecon::format::ApiCall_Ags_agsCheckDriverVersion_6_0_1, "ApiCall_Ags_agsCheckDriverVersion_6_0_1" },
        { gfxrecon::format::ApiCall_Ags_agsGetVersionNumber_6_0_1, "ApiCall_Ags_agsGetVersionNumber_6_0_1" },
        { gfxrecon::format::ApiCall_Ags_agsSetDisplayMode_6_0_1, "ApiCall_Ags_agsSetDisplayMode_6_0_1" },
        { gfxrecon::format::ApiCall_Ags_agsDriverExtensionsDX12_PushMarker_6_0_1, "ApiCall_Ags_agsDriverExtensionsDX12_PushMarker_6_0_1" },
        { gfxrecon::format::ApiCall_Ags_agsDriverExtensionsDX12_PopMarker_6_0_1, "ApiCall_Ags_agsDriverExtensionsDX12_PopMarker_6_0_1" },
        { gfxrecon::format::ApiCall_Ags_agsDriverExtensionsDX12_SetMarker_6_0_1, "ApiCall_Ags_agsDriverExtensionsDX12_SetMarker_6_0_1" },
        { gfxrecon::format::ApiCall_Ags_agsDriverExtensionsDX12_CreateDevice_6_2_0, "ApiCall_Ags_agsDriverExtensionsDX12_CreateDevice_6_2_0" },
        { gfxrecon::format::ApiCall_xrCreateInstance, "ApiCall_xrCreateInstance" },
        { gfxrecon::format::ApiCall_xrDestroyInstance, "ApiCall_xrDestroyInstance" },
        { gfxrecon::format::ApiCall_xrGetInstanceProcAddr, "ApiCall_xrGetInstanceProcAddr" },
        { gfxrecon::format::ApiCall_xrEnumerateApiLayerProperties, "ApiCall_xrEnumerateApiLayerProperties" },
        { gfxrecon::format::ApiCall_xrEnumerateInstanceExtensionProperties, "ApiCall_xrEnumerateInstanceExtensionProperties" },
        { gfxrecon::format::ApiCall_xrGetInstanceProperties, "ApiCall_xrGetInstanceProperties" },
        { gfxrecon::format::ApiCall_xrPollEvent, "ApiCall_xrPollEvent" },
        { gfxrecon::format::ApiCall_xrResultToString, "ApiCall_xrResultToString" },
        { gfxrecon::format::ApiCall_xrStructureTypeToString, "ApiCall_xrStructureTypeToString" },
        { gfxrecon::format::ApiCall_xrGetSystem, "ApiCall_xrGetSystem" },
        { gfxrecon::format::ApiCall_xrGetSystemProperties, "ApiCall_xrGetSystemProperties" },
        { gfxrecon::format::ApiCall_xrEnumerateEnvironmentBlendModes, "ApiCall_xrEnumerateEnvironmentBlendModes" },
        { gfxrecon::format::ApiCall_xrCreateSession, "ApiCall_xrCreateSession" },
        { gfxrecon::format::ApiCall_xrDestroySession, "ApiCall_xrDestroySession" },
        { gfxrecon::format::ApiCall_xrEnumerateReferenceSpaces, "ApiCall_xrEnumerateReferenceSpaces" },
        { gfxrecon::format::ApiCall_xrCreateReferenceSpace, "ApiCall_xrCreateReferenceSpace" },
        { gfxrecon::format::ApiCall_xrGetReferenceSpaceBoundsRect, "ApiCall_xrGetReferenceSpaceBoundsRect" },
        { gfxrecon::format::ApiCall_xrCreateActionSpace, "ApiCall_xrCreateActionSpace" },
        { gfxrecon::format::ApiCall_xrLocateSpace, "ApiCall_xrLocateSpace" },
        { gfxrecon::format::ApiCall_xrDestroySpace, "ApiCall_xrDestroySpace" },
        { gfxrecon::format::ApiCall_xrEnumerateViewConfigurations, "ApiCall_xrEnumerateViewConfigurations" },
        { gfxrecon::format::ApiCall_xrGetViewConfigurationProperties, "ApiCall_xrGetViewConfigurationProperties" },
        { gfxrecon::format::ApiCall_xrEnumerateViewConfigurationViews, "ApiCall_xrEnumerateViewConfigurationViews" },
        { gfxrecon::format::ApiCall_xrEnumerateSwapchainFormats, "ApiCall_xrEnumerateSwapchainFormats" },
        { gfxrecon::format::ApiCall_xrCreateSwapchain, "ApiCall_xrCreateSwapchain" },
        { gfxrecon::format::ApiCall_xrDestroySwapchain, "ApiCall_xrDestroySwapchain" },
        { gfxrecon::format::ApiCall_xrEnumerateSwapchainImages, "ApiCall_xrEnumerateSwapchainImages" },
        { gfxrecon::format::ApiCall_xrAcquireSwapchainImage, "ApiCall_xrAcquireSwapchainImage" },
        { gfxrecon::format::ApiCall_xrWaitSwapchainImage, "ApiCall_xrWaitSwapchainImage" },
        { gfxrecon::format::ApiCall_xrReleaseSwapchainImage, "ApiCall_xrReleaseSwapchainImage" },
        { gfxrecon::format::ApiCall_xrBeginSession, "ApiCall_xrBeginSession" },
        { gfxrecon::format::ApiCall_xrEndSession, "ApiCall_xrEndSession" },
        { gfxrecon::format::ApiCall_xrRequestExitSession, "ApiCall_xrRequestExitSession" },
        { gfxrecon::format::ApiCall_xrWaitFrame, "ApiCall_xrWaitFrame" },
        { gfxrecon::format::ApiCall_xrBeginFrame, "ApiCall_xrBeginFrame" },
        { gfxrecon::format::ApiCall_xrEndFrame, "ApiCall_xrEndFrame" },
        { gfxrecon::format::ApiCall_xrLocateViews, "ApiCall_xrLocateViews" },
        { gfxrecon::format::ApiCall_xrStringToPath, "ApiCall_xrStringToPath" },
        { gfxrecon::format::ApiCall_xrPathToString, "ApiCall_xrPathToString" },
        { gfxrecon::format::ApiCall_xrCreateActionSet, "ApiCall_xrCreateActionSet" },
        { gfxrecon::format::ApiCall_xrDestroyActionSet, "ApiCall_xrDestroyActionSet" },
        { gfxrecon::format::ApiCall_xrCreateAction, "ApiCall_xrCreateAction" },
        { gfxrecon::format::ApiCall_xrDestroyAction, "ApiCall_xrDestroyAction" },
        { gfxrecon::format::ApiCall_xrSuggestInteractionProfileBindings, "ApiCall_xrSuggestInteractionProfileBindings" },
        { gfxrecon::format::ApiCall_xrAttachSessionActionSets, "ApiCall_xrAttachSessionActionSets" },
        { gfxrecon::format::ApiCall_xrGetCurrentInteractionProfile, "ApiCall_xrGetCurrentInteractionProfile" },
        { gfxrecon::format::ApiCall_xrGetActionStateBoolean, "ApiCall_xrGetActionStateBoolean" },
        { gfxrecon::format::ApiCall_xrGetActionStateFloat, "ApiCall_xrGetActionStateFloat" },
        { gfxrecon::format::ApiCall_xrGetActionStateVector2f, "ApiCall_xrGetActionStateVector2f" },
        { gfxrecon::format::ApiCall_xrGetActionStatePose, "ApiCall_xrGetActionStatePose" },
        { gfxrecon::format::ApiCall_xrSyncActions, "ApiCall_xrSyncActions" },
        { gfxrecon::format::ApiCall_xrEnumerateBoundSourcesForAction, "ApiCall_xrEnumerateBoundSourcesForAction" },
        { gfxrecon::format::ApiCall_xrGetInputSourceLocalizedName, "ApiCall_xrGetInputSourceLocalizedName" },
        { gfxrecon::format::ApiCall_xrApplyHapticFeedback, "ApiCall_xrApplyHapticFeedback" },
        { gfxrecon::format::ApiCall_xrStopHapticFeedback, "ApiCall_xrStopHapticFeedback" },
        { gfxrecon::format::ApiCall_xrCreateApiLayerInstance, "ApiCall_xrCreateApiLayerInstance" },
        { gfxrecon::format::ApiCall_xrNegotiateLoaderRuntimeInterface, "ApiCall_xrNegotiateLoaderRuntimeInterface" },
        { gfxrecon::format::ApiCall_xrNegotiateLoaderApiLayerInterface, "ApiCall_xrNegotiateLoaderApiLayerInterface" },
        { gfxrecon::format::ApiCall_xrSetAndroidApplicationThreadKHR, "ApiCall_xrSetAndroidApplicationThreadKHR" },
        { gfxrecon::format::ApiCall_xrCreateSwapchainAndroidSurfaceKHR, "ApiCall_xrCreateSwapchainAndroidSurfaceKHR" },
        { gfxrecon::format::ApiCall_xrGetOpenGLGraphicsRequirementsKHR, "ApiCall_xrGetOpenGLGraphicsRequirementsKHR" },
        { gfxrecon::format::ApiCall_xrGetOpenGLESGraphicsRequirementsKHR, "ApiCall_xrGetOpenGLESGraphicsRequirementsKHR" },
        { gfxrecon::format::ApiCall_xrGetVulkanInstanceExtensionsKHR, "ApiCall_xrGetVulkanInstanceExtensionsKHR" },
        { gfxrecon::format::ApiCall_xrGetVulkanDeviceExtensionsKHR, "ApiCall_xrGetVulkanDeviceExtensionsKHR" },
        { gfxrecon::format::ApiCall_xrGetVulkanGraphicsDeviceKHR, "ApiCall_xrGetVulkanGraphicsDeviceKHR" },
        { gfxrecon::format::ApiCall_xrGetVulkanGraphicsRequirementsKHR, "ApiCall_xrGetVulkanGraphicsRequirementsKHR" },
        { gfxrecon::format::ApiCall_xrGetD3D11GraphicsRequirementsKHR, "ApiCall_xrGetD3D11GraphicsRequirementsKHR" },
        { gfxrecon::format::ApiCall_xrGetD3D12GraphicsRequirementsKHR, "ApiCall_xrGetD3D12GraphicsRequirementsKHR" },
        { gfxrecon::format::ApiCall_xrGetVisibilityMaskKHR, "ApiCall_xrGetVisibilityMaskKHR" },
        { gfxrecon::format::ApiCall_xrConvertWin32PerformanceCounterToTimeKHR, "ApiCall_xrConvertWin32PerformanceCounterToTimeKHR" },
        { gfxrecon::format::ApiCall_xrConvertTimeToWin32PerformanceCounterKHR, "ApiCall_xrConvertTimeToWin32PerformanceCounterKHR" },
        { gfxrecon::format::ApiCall_xrConvertTimespecTimeToTimeKHR, "ApiCall_xrConvertTimespecTimeToTimeKHR" },
        { gfxrecon::format::ApiCall_xrConvertTimeToTimespecTimeKHR, "ApiCall_xrConvertTimeToTimespecTimeKHR" },
        { gfxrecon::format::ApiCall_xrInitializeLoaderKHR, "ApiCall_xrInitializeLoaderKHR" },
        { gfxrecon::format::ApiCall_xrCreateVulkanInstanceKHR, "ApiCall_xrCreateVulkanInstanceKHR" },
        { gfxrecon::format::ApiCall_xrCreateVulkanDeviceKHR, "ApiCall_xrCreateVulkanDeviceKHR" },
        { gfxrecon::format::ApiCall_xrGetVulkanGraphicsDevice2KHR, "ApiCall_xrGetVulkanGraphicsDevice2KHR" },
        { gfxrecon::format::ApiCall_xrGetVulkanGraphicsRequirements2KHR, "ApiCall_xrGetVulkanGraphicsRequirements2KHR" },
        { gfxrecon::format::ApiCall_xrPerfSettingsSetPerformanceLevelEXT, "ApiCall_xrPerfSettingsSetPerformanceLevelEXT" },
        { gfxrecon::format::ApiCall_xrThermalGetTemperatureTrendEXT, "ApiCall_xrThermalGetTemperatureTrendEXT" },
        { gfxrecon::format::ApiCall_xrSetDebugUtilsObjectNameEXT, "ApiCall_xrSetDebugUtilsObjectNameEXT" },
        { gfxrecon::format::ApiCall_xrCreateDebugUtilsMessengerEXT, "ApiCall_xrCreateDebugUtilsMessengerEXT" },
        { gfxrecon::format::ApiCall_xrDestroyDebugUtilsMessengerEXT, "ApiCall_xrDestroyDebugUtilsMessengerEXT" },
        { gfxrecon::format::ApiCall_xrSubmitDebugUtilsMessageEXT, "ApiCall_xrSubmitDebugUtilsMessageEXT" },
        { gfxrecon::format::ApiCall_xrSessionBeginDebugUtilsLabelRegionEXT, "ApiCall_xrSessionBeginDebugUtilsLabelRegionEXT" },
        { gfxrecon::format::ApiCall_xrSessionEndDebugUtilsLabelRegionEXT, "ApiCall_xrSessionEndDebugUtilsLabelRegionEXT" },
        { gfxrecon::format::ApiCall_xrSessionInsertDebugUtilsLabelEXT, "ApiCall_xrSessionInsertDebugUtilsLabelEXT" },
        { gfxrecon::format::ApiCall_xrCreateSpatialAnchorMSFT, "ApiCall_xrCreateSpatialAnchorMSFT" },
        { gfxrecon::format::ApiCall_xrCreateSpatialAnchorSpaceMSFT, "ApiCall_xrCreateSpatialAnchorSpaceMSFT" },
        { gfxrecon::format::ApiCall_xrDestroySpatialAnchorMSFT, "ApiCall_xrDestroySpatialAnchorMSFT" },
        { gfxrecon::format::ApiCall_xrSetInputDeviceActiveEXT, "ApiCall_xrSetInputDeviceActiveEXT" },
        { gfxrecon::format::ApiCall_xrSetInputDeviceStateBoolEXT, "ApiCall_xrSetInputDeviceStateBoolEXT" },
        { gfxrecon::format::ApiCall_xrSetInputDeviceStateFloatEXT, "ApiCall_xrSetInputDeviceStateFloatEXT" },
        { gfxrecon::format::ApiCall_xrSetInputDeviceStateVector2fEXT, "ApiCall_xrSetInputDeviceStateVector2fEXT" },
        { gfxrecon::format::ApiCall_xrSetInputDeviceLocationEXT, "ApiCall_xrSetInputDeviceLocationEXT" },
        { gfxrecon::format::ApiCall_xrCreateSpatialGraphNodeSpaceMSFT, "ApiCall_xrCreateSpatialGraphNodeSpaceMSFT" },
        { gfxrecon::format::ApiCall_xrTryCreateSpatialGraphStaticNodeBindingMSFT, "ApiCall_xrTryCreateSpatialGraphStaticNodeBindingMSFT" },
        { gfxrecon::format::ApiCall_xrDestroySpatialGraphNodeBindingMSFT, "ApiCall_xrDestroySpatialGraphNodeBindingMSFT" },
        { gfxrecon::format::ApiCall_xrGetSpatialGraphNodeBindingPropertiesMSFT, "ApiCall_xrGetSpatialGraphNodeBindingPropertiesMSFT" },
        { gfxrecon::format::ApiCall_xrCreateHandTrackerEXT, "ApiCall_xrCreateHandTrackerEXT" },
        { gfxrecon::format::ApiCall_xrDestroyHandTrackerEXT, "ApiCall_xrDestroyHandTrackerEXT" },
        { gfxrecon::format::ApiCall_xrLocateHandJointsEXT, "ApiCall_xrLocateHandJointsEXT" },
        { gfxrecon::format::ApiCall_xrCreateHandMeshSpaceMSFT, "ApiCall_xrCreateHandMeshSpaceMSFT" },
        { gfxrecon::format::ApiCall_xrUpdateHandMeshMSFT, "ApiCall_xrUpdateHandMeshMSFT" },
        { gfxrecon::format::ApiCall_xrGetControllerModelKeyMSFT, "ApiCall_xrGetControllerModelKeyMSFT" },
        { gfxrecon::format::ApiCall_xrLoadControllerModelMSFT, "ApiCall_xrLoadControllerModelMSFT" },
        { gfxrecon::format::ApiCall_xrGetControllerModelPropertiesMSFT, "ApiCall_xrGetControllerModelPropertiesMSFT" },
        { gfxrecon::format::ApiCall_xrGetControllerModelStateMSFT, "ApiCall_xrGetControllerModelStateMSFT" },
        { gfxrecon::format::ApiCall_xrCreateSpatialAnchorFromPerceptionAnchorMSFT, "ApiCall_xrCreateSpatialAnchorFromPerceptionAnchorMSFT" },
        { gfxrecon::format::ApiCall_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT, "ApiCall_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT" },
        { gfxrecon::format::ApiCall_xrEnumerateReprojectionModesMSFT, "ApiCall_xrEnumerateReprojectionModesMSFT" },
        { gfxrecon::format::ApiCall_xrUpdateSwapchainFB, "ApiCall_xrUpdateSwapchainFB" },
        { gfxrecon::format::ApiCall_xrGetSwapchainStateFB, "ApiCall_xrGetSwapchainStateFB" },
        { gfxrecon::format::ApiCall_xrCreateBodyTrackerFB, "ApiCall_xrCreateBodyTrackerFB" },
        { gfxrecon::format::ApiCall_xrDestroyBodyTrackerFB, "ApiCall_xrDestroyBodyTrackerFB" },
        { gfxrecon::format::ApiCall_xrLocateBodyJointsFB, "ApiCall_xrLocateBodyJointsFB" },
        { gfxrecon::format::ApiCall_xrGetBodySkeletonFB, "ApiCall_xrGetBodySkeletonFB" },
        { gfxrecon::format::ApiCall_xrEnumerateSceneComputeFeaturesMSFT, "ApiCall_xrEnumerateSceneComputeFeaturesMSFT" },
        { gfxrecon::format::ApiCall_xrCreateSceneObserverMSFT, "ApiCall_xrCreateSceneObserverMSFT" },
        { gfxrecon::format::ApiCall_xrDestroySceneObserverMSFT, "ApiCall_xrDestroySceneObserverMSFT" },
        { gfxrecon::format::ApiCall_xrCreateSceneMSFT, "ApiCall_xrCreateSceneMSFT" },
        { gfxrecon::format::ApiCall_xrDestroySceneMSFT, "ApiCall_xrDestroySceneMSFT" },
        { gfxrecon::format::ApiCall_xrComputeNewSceneMSFT, "ApiCall_xrComputeNewSceneMSFT" },
        { gfxrecon::format::ApiCall_xrGetSceneComputeStateMSFT, "ApiCall_xrGetSceneComputeStateMSFT" },
        { gfxrecon::format::ApiCall_xrGetSceneComponentsMSFT, "ApiCall_xrGetSceneComponentsMSFT" },
        { gfxrecon::format::ApiCall_xrLocateSceneComponentsMSFT, "ApiCall_xrLocateSceneComponentsMSFT" },
        { gfxrecon::format::ApiCall_xrGetSceneMeshBuffersMSFT, "ApiCall_xrGetSceneMeshBuffersMSFT" },
        { gfxrecon::format::ApiCall_xrDeserializeSceneMSFT, "ApiCall_xrDeserializeSceneMSFT" },
        { gfxrecon::format::ApiCall_xrGetSerializedSceneFragmentDataMSFT, "ApiCall_xrGetSerializedSceneFragmentDataMSFT" },
        { gfxrecon::format::ApiCall_xrEnumerateDisplayRefreshRatesFB, "ApiCall_xrEnumerateDisplayRefreshRatesFB" },
        { gfxrecon::format::ApiCall_xrGetDisplayRefreshRateFB, "ApiCall_xrGetDisplayRefreshRateFB" },
        { gfxrecon::format::ApiCall_xrRequestDisplayRefreshRateFB, "ApiCall_xrRequestDisplayRefreshRateFB" },
        { gfxrecon::format::ApiCall_xrEnumerateViveTrackerPathsHTCX, "ApiCall_xrEnumerateViveTrackerPathsHTCX" },
        { gfxrecon::format::ApiCall_xrCreateFacialTrackerHTC, "ApiCall_xrCreateFacialTrackerHTC" },
        { gfxrecon::format::ApiCall_xrDestroyFacialTrackerHTC, "ApiCall_xrDestroyFacialTrackerHTC" },
        { gfxrecon::format::ApiCall_xrGetFacialExpressionsHTC, "ApiCall_xrGetFacialExpressionsHTC" },
        { gfxrecon::format::ApiCall_xrEnumerateColorSpacesFB, "ApiCall_xrEnumerateColorSpacesFB" },
        { gfxrecon::format::ApiCall_xrSetColorSpaceFB, "ApiCall_xrSetColorSpaceFB" },
        { gfxrecon::format::ApiCall_xrGetHandMeshFB, "ApiCall_xrGetHandMeshFB" },
        { gfxrecon::format::ApiCall_xrCreateSpatialAnchorFB, "ApiCall_xrCreateSpatialAnchorFB" },
        { gfxrecon::format::ApiCall_xrGetSpaceUuidFB, "ApiCall_xrGetSpaceUuidFB" },
        { gfxrecon::format::ApiCall_xrEnumerateSpaceSupportedComponentsFB, "ApiCall_xrEnumerateSpaceSupportedComponentsFB" },
        { gfxrecon::format::ApiCall_xrSetSpaceComponentStatusFB, "ApiCall_xrSetSpaceComponentStatusFB" },
        { gfxrecon::format::ApiCall_xrGetSpaceComponentStatusFB, "ApiCall_xrGetSpaceComponentStatusFB" },
        { gfxrecon::format::ApiCall_xrCreateFoveationProfileFB, "ApiCall_xrCreateFoveationProfileFB" },
        { gfxrecon::format::ApiCall_xrDestroyFoveationProfileFB, "ApiCall_xrDestroyFoveationProfileFB" },
        { gfxrecon::format::ApiCall_xrQuerySystemTrackedKeyboardFB, "ApiCall_xrQuerySystemTrackedKeyboardFB" },
        { gfxrecon::format::ApiCall_xrCreateKeyboardSpaceFB, "ApiCall_xrCreateKeyboardSpaceFB" },
        { gfxrecon::format::ApiCall_xrCreateTriangleMeshFB, "ApiCall_xrCreateTriangleMeshFB" },
        { gfxrecon::format::ApiCall_xrDestroyTriangleMeshFB, "ApiCall_xrDestroyTriangleMeshFB" },
        { gfxrecon::format::ApiCall_xrTriangleMeshGetVertexBufferFB, "ApiCall_xrTriangleMeshGetVertexBufferFB" },
        { gfxrecon::format::ApiCall_xrTriangleMeshGetIndexBufferFB, "ApiCall_xrTriangleMeshGetIndexBufferFB" },
        { gfxrecon::format::ApiCall_xrTriangleMeshBeginUpdateFB, "ApiCall_xrTriangleMeshBeginUpdateFB" },
        { gfxrecon::format::ApiCall_xrTriangleMeshEndUpdateFB, "ApiCall_xrTriangleMeshEndUpdateFB" },
        { gfxrecon::format::ApiCall_xrTriangleMeshBeginVertexBufferUpdateFB, "ApiCall_xrTriangleMeshBeginVertexBufferUpdateFB" },
        { gfxrecon::format::ApiCall_xrTriangleMeshEndVertexBufferUpdateFB, "ApiCall_xrTriangleMeshEndVertexBufferUpdateFB" },
        { gfxrecon::format::ApiCall_xrCreatePassthroughFB, "ApiCall_xrCreatePassthroughFB" },
        { gfxrecon::format::ApiCall_xrDestroyPassthroughFB, "ApiCall_xrDestroyPassthroughFB" },
        { gfxrecon::format::ApiCall_xrPassthroughStartFB, "ApiCall_xrPassthroughStartFB" },
        { gfxrecon::format::ApiCall_xrPassthroughPauseFB, "ApiCall_xrPassthroughPauseFB" },
        { gfxrecon::format::ApiCall_xrCreatePassthroughLayerFB, "ApiCall_xrCreatePassthroughLayerFB" },
        { gfxrecon::format::ApiCall_xrDestroyPassthroughLayerFB, "ApiCall_xrDestroyPassthroughLayerFB" },
        { gfxrecon::format::ApiCall_xrPassthroughLayerPauseFB, "ApiCall_xrPassthroughLayerPauseFB" },
        { gfxrecon::format::ApiCall_xrPassthroughLayerResumeFB, "ApiCall_xrPassthroughLayerResumeFB" },
        { gfxrecon::format::ApiCall_xrPassthroughLayerSetStyleFB, "ApiCall_xrPassthroughLayerSetStyleFB" },
        { gfxrecon::format::ApiCall_xrCreateGeometryInstanceFB, "ApiCall_xrCreateGeometryInstanceFB" },
        { gfxrecon::format::ApiCall_xrDestroyGeometryInstanceFB, "ApiCall_xrDestroyGeometryInstanceFB" },
        { gfxrecon::format::ApiCall_xrGeometryInstanceSetTransformFB, "ApiCall_xrGeometryInstanceSetTransformFB" },
        { gfxrecon::format::ApiCall_xrEnumerateRenderModelPathsFB, "ApiCall_xrEnumerateRenderModelPathsFB" },
        { gfxrecon::format::ApiCall_xrGetRenderModelPropertiesFB, "ApiCall_xrGetRenderModelPropertiesFB" },
        { gfxrecon::format::ApiCall_xrLoadRenderModelFB, "ApiCall_xrLoadRenderModelFB" },
        { gfxrecon::format::ApiCall_xrSetEnvironmentDepthEstimationVARJO, "ApiCall_xrSetEnvironmentDepthEstimationVARJO" },
        { gfxrecon::format::ApiCall_xrSetMarkerTrackingVARJO, "ApiCall_xrSetMarkerTrackingVARJO" },
        { gfxrecon::format::ApiCall_xrSetMarkerTrackingTimeoutVARJO, "ApiCall_xrSetMarkerTrackingTimeoutVARJO" },
        { gfxrecon::format::ApiCall_xrSetMarkerTrackingPredictionVARJO, "ApiCall_xrSetMarkerTrackingPredictionVARJO" },
        { gfxrecon::format::ApiCall_xrGetMarkerSizeVARJO, "ApiCall_xrGetMarkerSizeVARJO" },
        { gfxrecon::format::ApiCall_xrCreateMarkerSpaceVARJO, "ApiCall_xrCreateMarkerSpaceVARJO" },
        { gfxrecon::format::ApiCall_xrSetViewOffsetVARJO, "ApiCall_xrSetViewOffsetVARJO" },
        { gfxrecon::format::ApiCall_xrCreateSpaceFromCoordinateFrameUIDML, "ApiCall_xrCreateSpaceFromCoordinateFrameUIDML" },
        { gfxrecon::format::ApiCall_xrCreateMarkerDetectorML, "ApiCall_xrCreateMarkerDetectorML" },
        { gfxrecon::format::ApiCall_xrDestroyMarkerDetectorML, "ApiCall_xrDestroyMarkerDetectorML" },
        { gfxrecon::format::ApiCall_xrSnapshotMarkerDetectorML, "ApiCall_xrSnapshotMarkerDetectorML" },
        { gfxrecon::format::ApiCall_xrGetMarkerDetectorStateML, "ApiCall_xrGetMarkerDetectorStateML" },
        { gfxrecon::format::ApiCall_xrGetMarkersML, "ApiCall_xrGetMarkersML" },
        { gfxrecon::format::ApiCall_xrGetMarkerReprojectionErrorML, "ApiCall_xrGetMarkerReprojectionErrorML" },
        { gfxrecon::format::ApiCall_xrGetMarkerLengthML, "ApiCall_xrGetMarkerLengthML" },
        { gfxrecon::format::ApiCall_xrGetMarkerNumberML, "ApiCall_xrGetMarkerNumberML" },
        { gfxrecon::format::ApiCall_xrGetMarkerStringML, "ApiCall_xrGetMarkerStringML" },
        { gfxrecon::format::ApiCall_xrCreateMarkerSpaceML, "ApiCall_xrCreateMarkerSpaceML" },
        { gfxrecon::format::ApiCall_xrEnableLocalizationEventsML, "ApiCall_xrEnableLocalizationEventsML" },
        { gfxrecon::format::ApiCall_xrQueryLocalizationMapsML, "ApiCall_xrQueryLocalizationMapsML" },
        { gfxrecon::format::ApiCall_xrRequestMapLocalizationML, "ApiCall_xrRequestMapLocalizationML" },
        { gfxrecon::format::ApiCall_xrImportLocalizationMapML, "ApiCall_xrImportLocalizationMapML" },
        { gfxrecon::format::ApiCall_xrCreateExportedLocalizationMapML, "ApiCall_xrCreateExportedLocalizationMapML" },
        { gfxrecon::format::ApiCall_xrDestroyExportedLocalizationMapML, "ApiCall_xrDestroyExportedLocalizationMapML" },
        { gfxrecon::format::ApiCall_xrGetExportedLocalizationMapDataML, "ApiCall_xrGetExportedLocalizationMapDataML" },
        { gfxrecon::format::ApiCall_xrCreateSpatialAnchorStoreConnectionMSFT, "ApiCall_xrCreateSpatialAnchorStoreConnectionMSFT" },
        { gfxrecon::format::ApiCall_xrDestroySpatialAnchorStoreConnectionMSFT, "ApiCall_xrDestroySpatialAnchorStoreConnectionMSFT" },
        { gfxrecon::format::ApiCall_xrPersistSpatialAnchorMSFT, "ApiCall_xrPersistSpatialAnchorMSFT" },
        { gfxrecon::format::ApiCall_xrEnumeratePersistedSpatialAnchorNamesMSFT, "ApiCall_xrEnumeratePersistedSpatialAnchorNamesMSFT" },
        { gfxrecon::format::ApiCall_xrCreateSpatialAnchorFromPersistedNameMSFT, "ApiCall_xrCreateSpatialAnchorFromPersistedNameMSFT" },
        { gfxrecon::format::ApiCall_xrUnpersistSpatialAnchorMSFT, "ApiCall_xrUnpersistSpatialAnchorMSFT" },
        { gfxrecon::format::ApiCall_xrClearSpatialAnchorStoreMSFT, "ApiCall_xrClearSpatialAnchorStoreMSFT" },
        { gfxrecon::format::ApiCall_xrGetSceneMarkerRawDataMSFT, "ApiCall_xrGetSceneMarkerRawDataMSFT" },
        { gfxrecon::format::ApiCall_xrGetSceneMarkerDecodedStringMSFT, "ApiCall_xrGetSceneMarkerDecodedStringMSFT" },
        { gfxrecon::format::ApiCall_xrQuerySpacesFB, "ApiCall_xrQuerySpacesFB" },
        { gfxrecon::format::ApiCall_xrRetrieveSpaceQueryResultsFB, "ApiCall_xrRetrieveSpaceQueryResultsFB" },
        { gfxrecon::format::ApiCall_xrSaveSpaceFB, "ApiCall_xrSaveSpaceFB" },
        { gfxrecon::format::ApiCall_xrEraseSpaceFB, "ApiCall_xrEraseSpaceFB" },
        { gfxrecon::format::ApiCall_xrGetAudioOutputDeviceGuidOculus, "ApiCall_xrGetAudioOutputDeviceGuidOculus" },
        { gfxrecon::format::ApiCall_xrGetAudioInputDeviceGuidOculus, "ApiCall_xrGetAudioInputDeviceGuidOculus" },
        { gfxrecon::format::ApiCall_xrShareSpacesFB, "ApiCall_xrShareSpacesFB" },
        { gfxrecon::format::ApiCall_xrGetSpaceBoundingBox2DFB, "ApiCall_xrGetSpaceBoundingBox2DFB" },
        { gfxrecon::format::ApiCall_xrGetSpaceBoundingBox3DFB, "ApiCall_xrGetSpaceBoundingBox3DFB" },
        { gfxrecon::format::ApiCall_xrGetSpaceSemanticLabelsFB, "ApiCall_xrGetSpaceSemanticLabelsFB" },
        { gfxrecon::format::ApiCall_xrGetSpaceBoundary2DFB, "ApiCall_xrGetSpaceBoundary2DFB" },
        { gfxrecon::format::ApiCall_xrGetSpaceRoomLayoutFB, "ApiCall_xrGetSpaceRoomLayoutFB" },
        { gfxrecon::format::ApiCall_xrSetDigitalLensControlALMALENCE, "ApiCall_xrSetDigitalLensControlALMALENCE" },
        { gfxrecon::format::ApiCall_xrRequestSceneCaptureFB, "ApiCall_xrRequestSceneCaptureFB" },
        { gfxrecon::format::ApiCall_xrGetSpaceContainerFB, "ApiCall_xrGetSpaceContainerFB" },
        { gfxrecon::format::ApiCall_xrGetFoveationEyeTrackedStateMETA, "ApiCall_xrGetFoveationEyeTrackedStateMETA" },
        { gfxrecon::format::ApiCall_xrCreateFaceTrackerFB, "ApiCall_xrCreateFaceTrackerFB" },
        { gfxrecon::format::ApiCall_xrDestroyFaceTrackerFB, "ApiCall_xrDestroyFaceTrackerFB" },
        { gfxrecon::format::ApiCall_xrGetFaceExpressionWeightsFB, "ApiCall_xrGetFaceExpressionWeightsFB" },
        { gfxrecon::format::ApiCall_xrCreateEyeTrackerFB, "ApiCall_xrCreateEyeTrackerFB" },
        { gfxrecon::format::ApiCall_xrDestroyEyeTrackerFB, "ApiCall_xrDestroyEyeTrackerFB" },
        { gfxrecon::format::ApiCall_xrGetEyeGazesFB, "ApiCall_xrGetEyeGazesFB" },
        { gfxrecon::format::ApiCall_xrPassthroughLayerSetKeyboardHandsIntensityFB, "ApiCall_xrPassthroughLayerSetKeyboardHandsIntensityFB" },
        { gfxrecon::format::ApiCall_xrGetDeviceSampleRateFB, "ApiCall_xrGetDeviceSampleRateFB" },
        { gfxrecon::format::ApiCall_xrGetPassthroughPreferencesMETA, "ApiCall_xrGetPassthroughPreferencesMETA" },
        { gfxrecon::format::ApiCall_xrCreateVirtualKeyboardMETA, "ApiCall_xrCreateVirtualKeyboardMETA" },
        { gfxrecon::format::ApiCall_xrDestroyVirtualKeyboardMETA, "ApiCall_xrDestroyVirtualKeyboardMETA" },
        { gfxrecon::format::ApiCall_xrCreateVirtualKeyboardSpaceMETA, "ApiCall_xrCreateVirtualKeyboardSpaceMETA" },
        { gfxrecon::format::ApiCall_xrSuggestVirtualKeyboardLocationMETA, "ApiCall_xrSuggestVirtualKeyboardLocationMETA" },
        { gfxrecon::format::ApiCall_xrGetVirtualKeyboardScaleMETA, "ApiCall_xrGetVirtualKeyboardScaleMETA" },
        { gfxrecon::format::ApiCall_xrSetVirtualKeyboardModelVisibilityMETA, "ApiCall_xrSetVirtualKeyboardModelVisibilityMETA" },
        { gfxrecon::format::ApiCall_xrGetVirtualKeyboardModelAnimationStatesMETA, "ApiCall_xrGetVirtualKeyboardModelAnimationStatesMETA" },
        { gfxrecon::format::ApiCall_xrGetVirtualKeyboardDirtyTexturesMETA, "ApiCall_xrGetVirtualKeyboardDirtyTexturesMETA" },
        { gfxrecon::format::ApiCall_xrGetVirtualKeyboardTextureDataMETA, "ApiCall_xrGetVirtualKeyboardTextureDataMETA" },
        { gfxrecon::format::ApiCall_xrSendVirtualKeyboardInputMETA, "ApiCall_xrSendVirtualKeyboardInputMETA" },
        { gfxrecon::format::ApiCall_xrChangeVirtualKeyboardTextContextMETA, "ApiCall_xrChangeVirtualKeyboardTextContextMETA" },
        { gfxrecon::format::ApiCall_xrEnumerateExternalCamerasOCULUS, "ApiCall_xrEnumerateExternalCamerasOCULUS" },
        { gfxrecon::format::ApiCall_xrEnumeratePerformanceMetricsCounterPathsMETA, "ApiCall_xrEnumeratePerformanceMetricsCounterPathsMETA" },
        { gfxrecon::format::ApiCall_xrSetPerformanceMetricsStateMETA, "ApiCall_xrSetPerformanceMetricsStateMETA" },
        { gfxrecon::format::ApiCall_xrGetPerformanceMetricsStateMETA, "ApiCall_xrGetPerformanceMetricsStateMETA" },
        { gfxrecon::format::ApiCall_xrQueryPerformanceMetricsCounterMETA, "ApiCall_xrQueryPerformanceMetricsCounterMETA" },
        { gfxrecon::format::ApiCall_xrSaveSpaceListFB, "ApiCall_xrSaveSpaceListFB" },
        { gfxrecon::format::ApiCall_xrCreateSpaceUserFB, "ApiCall_xrCreateSpaceUserFB" },
        { gfxrecon::format::ApiCall_xrGetSpaceUserIdFB, "ApiCall_xrGetSpaceUserIdFB" },
        { gfxrecon::format::ApiCall_xrDestroySpaceUserFB, "ApiCall_xrDestroySpaceUserFB" },
        { gfxrecon::format::ApiCall_xrGetRecommendedLayerResolutionMETA, "ApiCall_xrGetRecommendedLayerResolutionMETA" },
        { gfxrecon::format::ApiCall_xrCreatePassthroughColorLutMETA, "ApiCall_xrCreatePassthroughColorLutMETA" },
        { gfxrecon::format::ApiCall_xrDestroyPassthroughColorLutMETA, "ApiCall_xrDestroyPassthroughColorLutMETA" },
        { gfxrecon::format::ApiCall_xrUpdatePassthroughColorLutMETA, "ApiCall_xrUpdatePassthroughColorLutMETA" },
        { gfxrecon::format::ApiCall_xrGetSpaceTriangleMeshMETA, "ApiCall_xrGetSpaceTriangleMeshMETA" },
        { gfxrecon::format::ApiCall_xrCreateFaceTracker2FB, "ApiCall_xrCreateFaceTracker2FB" },
        { gfxrecon::format::ApiCall_xrDestroyFaceTracker2FB, "ApiCall_xrDestroyFaceTracker2FB" },
        { gfxrecon::format::ApiCall_xrGetFaceExpressionWeights2FB, "ApiCall_xrGetFaceExpressionWeights2FB" },
        { gfxrecon::format::ApiCall_xrSetTrackingOptimizationSettingsHintQCOM, "ApiCall_xrSetTrackingOptimizationSettingsHintQCOM" },
        { gfxrecon::format::ApiCall_xrCreatePassthroughHTC, "ApiCall_xrCreatePassthroughHTC" },
        { gfxrecon::format::ApiCall_xrDestroyPassthroughHTC, "ApiCall_xrDestroyPassthroughHTC" },
        { gfxrecon::format::ApiCall_xrApplyFoveationHTC, "ApiCall_xrApplyFoveationHTC" },
        { gfxrecon::format::ApiCall_xrCreateSpatialAnchorHTC, "ApiCall_xrCreateSpatialAnchorHTC" },
        { gfxrecon::format::ApiCall_xrGetSpatialAnchorNameHTC, "ApiCall_xrGetSpatialAnchorNameHTC" },
        { gfxrecon::format::ApiCall_xrApplyForceFeedbackCurlMNDX, "ApiCall_xrApplyForceFeedbackCurlMNDX" },
        { gfxrecon::format::ApiCall_xrCreatePlaneDetectorEXT, "ApiCall_xrCreatePlaneDetectorEXT" },
        { gfxrecon::format::ApiCall_xrDestroyPlaneDetectorEXT, "ApiCall_xrDestroyPlaneDetectorEXT" },
        { gfxrecon::format::ApiCall_xrBeginPlaneDetectionEXT, "ApiCall_xrBeginPlaneDetectionEXT" },
        { gfxrecon::format::ApiCall_xrGetPlaneDetectionStateEXT, "ApiCall_xrGetPlaneDetectionStateEXT" },
        { gfxrecon::format::ApiCall_xrGetPlaneDetectionsEXT, "ApiCall_xrGetPlaneDetectionsEXT" },
        { gfxrecon::format::ApiCall_xrGetPlanePolygonBufferEXT, "ApiCall_xrGetPlanePolygonBufferEXT" },
        { gfxrecon::format::ApiCall_xrEnableUserCalibrationEventsML, "ApiCall_xrEnableUserCalibrationEventsML" },
        { gfxrecon::format::ApiCall_xrLocateSpacesKHR, "ApiCall_xrLocateSpacesKHR" },
        { gfxrecon::format::ApiCall_xrLocateSpaces, "ApiCall_xrLocateSpaces" },
        { gfxrecon::format::ApiCall_xrGetMetalGraphicsRequirementsKHR, "ApiCall_xrGetMetalGraphicsRequirementsKHR" },
        { gfxrecon::format::ApiCall_xrCreateEnvironmentDepthProviderMETA, "ApiCall_xrCreateEnvironmentDepthProviderMETA" },
        { gfxrecon::format::ApiCall_xrDestroyEnvironmentDepthProviderMETA, "ApiCall_xrDestroyEnvironmentDepthProviderMETA" },
        { gfxrecon::format::ApiCall_xrStartEnvironmentDepthProviderMETA, "ApiCall_xrStartEnvironmentDepthProviderMETA" },
        { gfxrecon::format::ApiCall_xrStopEnvironmentDepthProviderMETA, "ApiCall_xrStopEnvironmentDepthProviderMETA" },
        { gfxrecon::format::ApiCall_xrCreateEnvironmentDepthSwapchainMETA, "ApiCall_xrCreateEnvironmentDepthSwapchainMETA" },
        { gfxrecon::format::ApiCall_xrDestroyEnvironmentDepthSwapchainMETA, "ApiCall_xrDestroyEnvironmentDepthSwapchainMETA" },
        { gfxrecon::format::ApiCall_xrEnumerateEnvironmentDepthSwapchainImagesMETA, "ApiCall_xrEnumerateEnvironmentDepthSwapchainImagesMETA" },
        { gfxrecon::format::ApiCall_xrGetEnvironmentDepthSwapchainStateMETA, "ApiCall_xrGetEnvironmentDepthSwapchainStateMETA" },
        { gfxrecon::format::ApiCall_xrAcquireEnvironmentDepthImageMETA, "ApiCall_xrAcquireEnvironmentDepthImageMETA" },
        { gfxrecon::format::ApiCall_xrSetEnvironmentDepthHandRemovalMETA, "ApiCall_xrSetEnvironmentDepthHandRemovalMETA" },
        { gfxrecon::format::ApiCall_xrPollFutureEXT, "ApiCall_xrPollFutureEXT" },
        { gfxrecon::format::ApiCall_xrCancelFutureEXT, "ApiCall_xrCancelFutureEXT" },
    };
    // clang-format on
    auto find_it = kApiCallIdToString.find(call_id);
    if (find_it != kApiCallIdToString.cend())
    {
        return find_it->second;
    }
    return "UNKNOWN BLOCK_TYPE";
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
