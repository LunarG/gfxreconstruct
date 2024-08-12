/*
** Copyright (c) 2018-2020,2022 Valve Corporation
** Copyright (c) 2018-2020,2022 LunarG, Inc.
** Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All rights reserved.
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
    current_frame_number_(kFirstFrame), error_state_(kErrorInvalidFileDescriptor), annotation_handler_(nullptr),
    compressor_(nullptr), block_index_(0), api_call_index_(0), block_limit_(0), capture_uses_frame_markers_(false),
    first_frame_(kFirstFrame + 1)
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

bool FileProcessor::Initialize(const std::string& filename,
                               const std::string* state_file,
                               const std::string* override_path)
{
    if (override_path != nullptr)
    {
        override_path_ = *override_path;
    }

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

    if (success && state_file != nullptr)
    {
        success = OpenFile(*state_file);
        if (success)
        {
            SetActiveFile(*state_file, true);
            success = success && ProcessFileHeader();
        }
    }

    return success;
}

std::string FileProcessor::ApplyOverrideFilePath(const std::string& file)
{
    if (override_path_.empty())
    {
        return file;
    }

    std::string  new_file       = file;
    const size_t slash_last_pos = new_file.find_last_of('/');
    if (slash_last_pos != std::string::npos)
    {
        new_file = new_file.substr(slash_last_pos);
        new_file = override_path_ + new_file;
    }

    return new_file;
}

bool FileProcessor::OpenFile(const std::string& filename)
{
    std::string new_filename = ApplyOverrideFilePath(filename);

    if (active_files_.find(new_filename) == active_files_.end())
    {
        FILE* fd;
        int   result = util::platform::FileOpen(&fd, new_filename.c_str(), "rb");
        if (result || fd == nullptr)
        {
            GFXRECON_LOG_ERROR("Failed to open file %s", new_filename.c_str());
            error_state_ = kErrorOpeningFile;
            return false;
        }
        else
        {
            active_files_.emplace(
                std::piecewise_construct, std::forward_as_tuple(new_filename), std::forward_as_tuple(fd));
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
    bool success = false;

    ActiveFiles& active_file = active_files_[file_stack_.top().filename];

    if (ReadBytes(&active_file.file_header, sizeof(active_file.file_header)))
    {
        success = format::ValidateFileHeader(active_file.file_header);

        if (success)
        {
            active_file.file_options.resize(active_file.file_header.num_options);

            size_t option_data_size = active_file.file_header.num_options * sizeof(format::FileOptionPair);

            success = ReadBytes(active_file.file_options.data(), option_data_size);

            if (success)
            {
                for (const auto& option : active_file.file_options)
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
    if (!file_stack_.size())
    {
        return;
    }

    ActiveFileContext& current_file = GetCurrentFile();

    if (!current_file.execute_till_eof)
    {
        --current_file.remaining_commands;
        if (current_file.remaining_commands == 0)
        {
            file_stack_.pop();
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
                    assert(file_stack_.size());

                    ActiveFileContext& current_file = GetCurrentFile();
                    if (current_file.execute_till_eof)
                    {
                        file_stack_.pop();
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
    auto file_entry = active_files_.find(file_stack_.top().filename);
    assert(file_entry != active_files_.end());

    if (util::platform::FileRead(buffer, buffer_size, file_entry->second.fd))
    {
        file_entry->second.bytes_read += buffer_size;
        return true;
    }
    return false;
}

bool FileProcessor::SkipBytes(size_t skip_size)
{
    auto file_entry = active_files_.find(file_stack_.top().filename);
    assert(file_entry != active_files_.end());

    bool success = util::platform::FileSeek(file_entry->second.fd, skip_size, util::platform::FileSeekCurrent);

    if (success)
    {
        // These technically count as bytes read/processed.
        file_entry->second.bytes_read += skip_size;
    }

    return success;
}

bool FileProcessor::SeekActiveFile(const std::string& filename, int64_t offset, util::platform::FileSeekOrigin origin)
{
    auto file_entry = active_files_.find(file_stack_.top().filename);
    assert(file_entry != active_files_.end());

    bool success = util::platform::FileSeek(file_entry->second.fd, offset, origin);

    if (success && origin == util::platform::FileSeekCurrent)
    {
        // These technically count as bytes read/processed.
        file_entry->second.bytes_read += offset;
    }

    return success;
}

bool FileProcessor::SeekActiveFile(int64_t offset, util::platform::FileSeekOrigin origin)
{
    return SeekActiveFile(file_stack_.top().filename, offset, origin);
}

bool FileProcessor::SetActiveFile(const std::string& filename, bool eteof)
{
    if (active_files_.find(filename) != active_files_.end())
    {
        file_stack_.emplace(filename, eteof);
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
                                  bool                           eteof)
{
    if (active_files_.find(filename) != active_files_.end())
    {
        file_stack_.emplace(filename, eteof);
        return SeekActiveFile(filename, offset, origin);
    }
    else
    {
        return false;
    }
}

void FileProcessor::HandleBlockReadError(Error error_code, const char* error_message)
{
    auto file_entry = active_files_.find(file_stack_.top().filename);
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
    else if (meta_data_type == format::MetaDataType::kExecuteBlocksFromFile)
    {
        format::ExecuteBlocksFromFile exec_from_file;
        success = ReadBytes(&exec_from_file.thread_id, sizeof(exec_from_file.thread_id));
        success = success && ReadBytes(&exec_from_file.n_blocks, sizeof(exec_from_file.n_blocks));
        success = success && ReadBytes(&exec_from_file.offset, sizeof(exec_from_file.offset));
        success = success && ReadBytes(&exec_from_file.filename_length, sizeof(exec_from_file.filename_length));

        std::vector<char> filename_c_str(exec_from_file.filename_length + 1);
        success = success && ReadBytes(filename_c_str.data(), exec_from_file.filename_length);
        if (success)
        {
            filename_c_str[exec_from_file.filename_length] = '\0';

            std::string filename = ApplyOverrideFilePath(std::string(filename_c_str.data()));
            success              = OpenFile(filename);
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
                file_stack_.top().remaining_commands = exec_from_file.n_blocks + 1;
            }
        }

        if (!success)
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read runtime info meta-data block");
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
        }
        else if (marker_type == format::kEndMarker)
        {
            GFXRECON_LOG_INFO("Finished loading state for captured frame %" PRId64, frame_number);
            first_frame_ = frame_number;
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
                (call_id == format::ApiCallId::ApiCall_IDXGISwapChain1_Present1));
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

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
