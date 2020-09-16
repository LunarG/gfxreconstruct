/*
** Copyright (c) 2020 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#include "optimizing_file_processor.h"

#include "format/format_util.h"
#include "util/logging.h"
#include "util/platform.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

OptimizingFileProcessor::OptimizingFileProcessor(const std::unordered_set<format::HandleId>& unreferenced_ids) :
    unreferenced_ids_(unreferenced_ids), file_header_{}, input_file_(nullptr), output_file_(nullptr), bytes_read_(0),
    bytes_written_(0), error_state_(kErrorInvalidFileDescriptor), loading_state_(false)
{}

OptimizingFileProcessor::OptimizingFileProcessor(std::unordered_set<format::HandleId>&& unreferenced_ids) :
    unreferenced_ids_(std::move(unreferenced_ids)), file_header_{}, input_file_(nullptr), output_file_(nullptr),
    bytes_read_(0), bytes_written_(0), error_state_(kErrorInvalidFileDescriptor), loading_state_(false)
{}

OptimizingFileProcessor::~OptimizingFileProcessor()
{
    if (input_file_ != nullptr)
    {
        fclose(input_file_);
    }

    if (output_file_ != nullptr)
    {
        fclose(output_file_);
    }
}

bool OptimizingFileProcessor::Initialize(const std::string& input_filename, const std::string& output_filename)
{
    bool success = false;

    int32_t result = util::platform::FileOpen(&input_file_, input_filename.c_str(), "rb");

    if ((result == 0) && (input_file_ != nullptr))
    {
        result = util::platform::FileOpen(&output_file_, output_filename.c_str(), "wb");

        if ((result == 0) && (output_file_ != nullptr))
        {
            success = ProcessFileHeader();

            if (success)
            {
                error_state_ = kErrorNone;
            }
            else
            {
                fclose(input_file_);
                fclose(output_file_);
                input_file_  = nullptr;
                output_file_ = nullptr;
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to open output file %s", output_filename.c_str());
            error_state_ = kErrorOpeningFile;
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to open input file %s", input_filename.c_str());
        error_state_ = kErrorOpeningFile;
    }

    return success;
}

// Returns false if processing failed.  Use GetErrorState() to determine error condition for failure case.
bool OptimizingFileProcessor::Process()
{
    bool success = true;

    while (success)
    {
        success = ProcessNextBlock();
    }

    if (!success)
    {
        // If not EOF, determine reason for invalid state.
        if ((input_file_ == nullptr) || (output_file_ == nullptr))
        {
            error_state_ = kErrorInvalidFileDescriptor;
        }
        else if (ferror(input_file_))
        {
            error_state_ = kErrorReadingFile;
        }
        else if (ferror(output_file_))
        {
            error_state_ = kErrorWritingFile;
        }
    }

    return (error_state_ == kErrorNone);
}

bool OptimizingFileProcessor::ProcessFileHeader()
{
    bool success = false;

    if (ReadBytes(&file_header_, sizeof(file_header_)))
    {
        success = format::ValidateFileHeader(file_header_);

        if (success)
        {
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

                compressor_ =
                    std::unique_ptr<util::Compressor>(format::CreateCompressor(enabled_options_.compression_type));

                if ((compressor_ == nullptr) && (enabled_options_.compression_type != format::CompressionType::kNone))
                {
                    GFXRECON_LOG_ERROR("Failed to initialized file compression module (type = %u); processing of "
                                       "compressed data will not be possible",
                                       enabled_options_.compression_type);
                    success      = false;
                    error_state_ = kErrorUnsupportedCompressionType;
                }
            }

            if (success)
            {
                // Write header to output file.
                success = WriteBytes(&file_header_, sizeof(file_header_));
                success = success && WriteBytes(file_options_.data(), option_data_size);

                if (!success)
                {
                    GFXRECON_LOG_ERROR("Failed to write file header");
                    error_state_ = kErrorWritingFileHeader;
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

bool OptimizingFileProcessor::ProcessNextBlock()
{
    format::BlockHeader block_header;
    bool                success = true;

    success = ReadBlockHeader(&block_header);

    if (success)
    {
        if (format::RemoveCompressedBlockBit(block_header.type) == format::BlockType::kFunctionCallBlock)
        {
            format::ApiCallId api_call_id = format::ApiCallId::ApiCall_Unknown;

            success = ReadBytes(&api_call_id, sizeof(api_call_id));

            if (success)
            {
                success = ProcessFunctionCall(block_header, api_call_id);
            }
            else
            {
                HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read function call block header");
            }
        }
        else if (format::RemoveCompressedBlockBit(block_header.type) == format::BlockType::kMetaDataBlock)
        {
            format::MetaDataType meta_type = format::MetaDataType::kUnknownMetaDataType;

            success = ReadBytes(&meta_type, sizeof(meta_type));

            if (success)
            {
                success = ProcessMetaData(block_header, meta_type);
            }
            else
            {
                HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read meta-data block header");
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
        else
        {
            // Copy the block to the output file.
            success = WriteBlockHeader(block_header);

            if (success)
            {
                success = CopyBytes(block_header.size);

                if (!success)
                {
                    GFXRECON_LOG_ERROR("Failed to write block data");
                    error_state_ = kErrorWritingBlockData;
                }
            }
        }
    }
    else
    {
        if (!feof(input_file_))
        {
            // If we have not hit a normal EOF condition, report an error reading the block header.
            GFXRECON_LOG_ERROR("Failed to read block header");
            error_state_ = kErrorReadingBlockHeader;
        }
    }

    return success;
}

bool OptimizingFileProcessor::ReadBlockHeader(format::BlockHeader* block_header)
{
    assert(block_header != nullptr);

    if (ReadBytes(block_header, sizeof(*block_header)))
    {
        return true;
    }

    return false;
}

bool OptimizingFileProcessor::WriteBlockHeader(const format::BlockHeader& block_header)
{
    if (!WriteBytes(&block_header, sizeof(block_header)))
    {
        GFXRECON_LOG_ERROR("Failed to write block header");
        error_state_ = kErrorWritingBlockHeader;
        return false;
    }

    return true;
}

bool OptimizingFileProcessor::ReadParameterBuffer(size_t buffer_size)
{
    if (buffer_size > parameter_buffer_.size())
    {
        parameter_buffer_.resize(buffer_size);
    }

    return ReadBytes(parameter_buffer_.data(), buffer_size);
}

bool OptimizingFileProcessor::ReadCompressedParameterBuffer(size_t  compressed_buffer_size,
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

bool OptimizingFileProcessor::ReadBytes(void* buffer, size_t buffer_size)
{
    size_t bytes_read = util::platform::FileRead(buffer, 1, buffer_size, input_file_);
    bytes_read_ += bytes_read;
    return (bytes_read == buffer_size);
}

bool OptimizingFileProcessor::WriteBytes(const void* buffer, size_t buffer_size)
{
    size_t bytes_written = util::platform::FileWrite(buffer, 1, buffer_size, output_file_);
    bytes_written_ += bytes_written;
    return (bytes_written == buffer_size);
}

bool OptimizingFileProcessor::SkipBytes(uint64_t skip_size)
{
    bool success = util::platform::FileSeek(input_file_, skip_size, util::platform::FileSeekCurrent);

    if (success)
    {
        // These technically count as bytes read/processed.
        bytes_read_ += skip_size;
    }

    return success;
}

bool OptimizingFileProcessor::CopyBytes(uint64_t copy_size)
{
    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, copy_size);
    if (ReadParameterBuffer(static_cast<size_t>(copy_size)))
    {
        if (WriteBytes(parameter_buffer_.data(), static_cast<size_t>(copy_size)))
        {
            return true;
        }
    }

    return false;
}

void OptimizingFileProcessor::HandleBlockReadError(Error error_code, const char* error_message)
{
    // Report incomplete block at end of file as a warning, other I/O errors as an error.
    if (feof(input_file_) && !ferror(input_file_))
    {
        GFXRECON_LOG_WARNING("Incomplete block at end of file");
    }
    else
    {
        GFXRECON_LOG_ERROR("%s", error_message);
        error_state_ = error_code;
    }
}

bool OptimizingFileProcessor::ProcessFunctionCall(const format::BlockHeader& block_header, format::ApiCallId call_id)
{
    // This is currently only copying the API call data from the old to the new file.
    if (!WriteBlockHeader(block_header))
    {
        return false;
    }

    if (!WriteBytes(&call_id, sizeof(call_id)))
    {
        GFXRECON_LOG_ERROR("Failed to write function call block header");
        error_state_ = kErrorWritingBlockHeader;
        return false;
    }

    if (!CopyBytes(block_header.size - sizeof(call_id)))
    {
        GFXRECON_LOG_ERROR("Failed to copy function call block data");
        error_state_ = kErrorWritingBlockData;
        return false;
    }

    return true;
}

bool OptimizingFileProcessor::ProcessMetaData(const format::BlockHeader& block_header, format::MetaDataType meta_type)
{
    if (meta_type == format::MetaDataType::kInitBufferCommand)
    {
        return FilterInitBufferMetaData(block_header, meta_type);
    }
    else if (meta_type == format::MetaDataType::kInitImageCommand)
    {
        return FilterInitImageMetaData(block_header, meta_type);
    }
    else
    {
        // Copy the meta data block, if it was not filtered.
        if (!WriteBlockHeader(block_header))
        {
            return false;
        }

        if (!WriteBytes(&meta_type, sizeof(meta_type)))
        {
            GFXRECON_LOG_ERROR("Failed to write meta-data block header");
            error_state_ = kErrorWritingBlockHeader;
            return false;
        }

        if (!CopyBytes(block_header.size - sizeof(meta_type)))
        {
            GFXRECON_LOG_ERROR("Failed to copy meta-data block data");
            error_state_ = kErrorWritingBlockData;
            return false;
        }
    }

    return true;
}

bool OptimizingFileProcessor::ProcessStateMarker(const format::BlockHeader& block_header,
                                                 format::MarkerType         marker_type)
{
    uint64_t frame_number = 0;

    if (ReadBytes(&frame_number, sizeof(frame_number)))
    {
        if (marker_type == format::kBeginMarker)
        {
            loading_state_ = true;
        }
        else if (marker_type == format::kEndMarker)
        {
            loading_state_ = false;
        }

        format::Marker marker;
        marker.header       = block_header;
        marker.marker_type  = marker_type;
        marker.frame_number = frame_number;

        if (!WriteBytes(&marker, sizeof(marker)))
        {
            GFXRECON_LOG_ERROR("Failed to write state marker data");
            error_state_ = kErrorWritingBlockData;
            return false;
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to read state marker data");
        error_state_ = kErrorReadingBlockData;
        return false;
    }

    return true;
}

bool OptimizingFileProcessor::FilterInitBufferMetaData(const format::BlockHeader& block_header,
                                                       format::MetaDataType       meta_type)
{
    assert(meta_type == format::MetaDataType::kInitBufferCommand);

    format::InitBufferCommandHeader header;

    bool success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
    success      = success && ReadBytes(&header.device_id, sizeof(header.device_id));
    success      = success && ReadBytes(&header.buffer_id, sizeof(header.buffer_id));
    success      = success && ReadBytes(&header.data_size, sizeof(header.data_size));

    if (success)
    {
        // Total number of bytes remaining to be read for the current block.
        uint64_t unread_bytes = block_header.size - (sizeof(header) - sizeof(block_header));

        // If the buffer is in the unused list, omit its initialization data from the file.
        if (unreferenced_ids_.find(header.buffer_id) != unreferenced_ids_.end())
        {
            if (!SkipBytes(unread_bytes))
            {
                GFXRECON_LOG_ERROR("Failed to skip init buffer data meta-data block data");
                return false;
            }
        }
        else
        {
            // Copy the block from the input file to the output file.
            header.meta_header.block_header   = block_header;
            header.meta_header.meta_data_type = meta_type;

            if (!WriteBytes(&header, sizeof(header)))
            {
                GFXRECON_LOG_ERROR("Failed to write init buffer data meta-data block header");
                error_state_ = kErrorReadingBlockHeader;
                return false;
            }

            if (!CopyBytes(unread_bytes))
            {
                GFXRECON_LOG_ERROR("Failed to copy init buffer data meta-data block data");
                error_state_ = kErrorWritingBlockData;
                return false;
            }
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read init buffer data meta-data block header");
        return false;
    }

    return true;
}

bool OptimizingFileProcessor::FilterInitImageMetaData(const format::BlockHeader& block_header,
                                                      format::MetaDataType       meta_type)
{
    assert(meta_type == format::MetaDataType::kInitImageCommand);

    format::InitImageCommandHeader header;
    std::vector<uint64_t>          level_sizes;

    bool success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
    success      = success && ReadBytes(&header.device_id, sizeof(header.device_id));
    success      = success && ReadBytes(&header.image_id, sizeof(header.image_id));
    success      = success && ReadBytes(&header.data_size, sizeof(header.data_size));
    success      = success && ReadBytes(&header.aspect, sizeof(header.aspect));
    success      = success && ReadBytes(&header.layout, sizeof(header.layout));
    success      = success && ReadBytes(&header.level_count, sizeof(header.level_count));

    if (success)
    {
        // Total number of bytes remaining to be read for the current block.
        uint64_t unread_bytes = block_header.size - (sizeof(header) - sizeof(block_header));

        // If the image is in the unused list, omit its initialization data from the file.
        if (unreferenced_ids_.find(header.image_id) != unreferenced_ids_.end())
        {
            if (!SkipBytes(unread_bytes))
            {
                GFXRECON_LOG_ERROR("Failed to skip init image data meta-data block data");
                return false;
            }
        }
        else
        {
            // Copy the block from the input file to the output file.
            header.meta_header.block_header   = block_header;
            header.meta_header.meta_data_type = meta_type;

            if (!WriteBytes(&header, sizeof(header)))
            {
                GFXRECON_LOG_ERROR("Failed to write init image data meta-data block header");
                error_state_ = kErrorReadingBlockHeader;
                return false;
            }

            if (!CopyBytes(unread_bytes))
            {
                GFXRECON_LOG_ERROR("Failed to copy init image data meta-data block data");
                error_state_ = kErrorWritingBlockData;
                return false;
            }
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read init image data meta-data block header");
        return false;
    }

    return true;
}

GFXRECON_END_NAMESPACE(gfxrecon)
