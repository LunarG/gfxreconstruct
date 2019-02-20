/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#include "decode/file_processor.h"

#include "format/format_util.h"
#include "util/compressor.h"
#include "util/logging.h"
#include "util/platform.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

FileProcessor::FileProcessor() :
    file_descriptor_(nullptr), current_frame_number_(1), bytes_read_(0), compressor_(nullptr)
{}

FileProcessor::~FileProcessor()
{
    if (nullptr != compressor_)
    {
        delete compressor_;
        compressor_ = nullptr;
    }

    if (file_descriptor_)
    {
        fclose(file_descriptor_);
    }
}

bool FileProcessor::Initialize(const std::string& filename)
{
    bool success = false;

    int32_t result = util::platform::FileOpen(&file_descriptor_, filename.c_str(), "rb");

    if ((result == 0) && (file_descriptor_ != nullptr))
    {
        success = ProcessFileHeader();

        if (success)
        {
            filename_ = filename;
        }
        else
        {
            fclose(file_descriptor_);
            file_descriptor_ = nullptr;
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to open file %s", filename.c_str());
    }

    return success;
}

bool FileProcessor::ProcessNextFrame()
{
    // TODO: Frame blocks in capture file.
    bool                success = IsFileValid();
    format::BlockHeader block_header;

    while (success)
    {
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

                    // Break from loop on frame delimiter.
                    if (IsFrameDelimiter(api_call_id))
                    {
                        // Make sure to increment the frame number on the way out.
                        ++current_frame_number_;
                        break;
                    }
                }
                else
                {
                    GFXRECON_LOG_ERROR("Failed to read function call block header");
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
                    GFXRECON_LOG_ERROR("Failed to read meta-data block header");
                }
            }
            else
            {
                // Unrecognized block type.
                GFXRECON_LOG_WARNING("Skipping unrecognized file block with type %u", block_header.type);
                GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
                success = SkipBytes(static_cast<size_t>(block_header.size));
            }

            if (success)
            {
                // Check for EOF.
                success = IsFileValid();
            }
        }
        else
        {
            if (!feof(file_descriptor_))
            {
                GFXRECON_LOG_ERROR("Failed to read block header");
            }
        }
    }

    return success;
}

bool FileProcessor::ProcessAllFrames()
{
    bool success = IsFileValid();

    while (success)
    {
        success = ProcessNextFrame();
    }

    return success;
}

bool FileProcessor::ProcessFileHeader()
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

                compressor_ = format::CreateCompressor(enabled_options_.compression_type);

                if ((compressor_ == nullptr) && (enabled_options_.compression_type != format::CompressionType::kNone))
                {
                    GFXRECON_LOG_ERROR("Failed to initialized file compression module (type = %u); replay of "
                                       "compressed data will not be possible",
                                       enabled_options_.compression_type);
                    success = false;
                }
            }
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to read file header");
    }

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
    size_t bytes_read = util::platform::FileRead(buffer, 1, buffer_size, file_descriptor_);
    bytes_read_ += bytes_read;
    return (bytes_read == buffer_size);
}

bool FileProcessor::SkipBytes(size_t skip_size)
{
    bool success = util::platform::FileSeek(file_descriptor_, skip_size, util::platform::FileSeekCurrent);

    if (success)
    {
        // These technically count as bytes read/processed.
        bytes_read_ += skip_size;
    }

    return success;
}

bool FileProcessor::ProcessFunctionCall(const format::BlockHeader& block_header, format::ApiCallId call_id)
{
    size_t      parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(call_id);
    uint64_t    uncompressed_size     = 0;
    ApiCallInfo call_info             = {};

    bool success = ReadBytes(&call_info.thread_id, sizeof(call_info.thread_id));

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
                    GFXRECON_LOG_ERROR("Failed to read compressed function call block data");
                }
            }
            else
            {
                GFXRECON_LOG_ERROR("Failed to read compressed function call block header");
            }
        }
        else
        {
            success = ReadParameterBuffer(parameter_buffer_size);

            if (!success)
            {
                GFXRECON_LOG_ERROR("Failed to read function call block data");
            }
        }

        if (success)
        {
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsApiCall(call_id))
                {
                    decoder->DecodeFunctionCall(call_id, call_info, parameter_buffer_.data(), parameter_buffer_size);
                }
            }
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to read function call block header");
    }

    return success;
}

bool FileProcessor::ProcessMetaData(const format::BlockHeader& block_header, format::MetaDataType meta_type)
{
    bool success = false;

    if (meta_type == format::MetaDataType::kFillMemoryCommand)
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
                size_t compressed_size   = static_cast<size_t>(block_header.size) - sizeof(meta_type) -
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
                    decoder->DispatchFillMemoryCommand(header.thread_id,
                                                       header.memory_id,
                                                       header.memory_offset,
                                                       header.memory_size,
                                                       parameter_buffer_.data());
                }
            }
            else
            {
                GFXRECON_LOG_ERROR("Failed to read fill memory meta-data block");
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to read fill memory meta-data block header");
        }
    }
    else if (meta_type == format::MetaDataType::kResizeWindowCommand)
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
                decoder->DispatchResizeWindowCommand(command.thread_id, command.surface_id, command.width, command.height);
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to read resize window meta-data block");
        }
    }
    else if (meta_type == format::MetaDataType::kDisplayMessageCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::DisplayMessageCommandHeader header;

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));

        if (success)
        {
            uint64_t message_size = block_header.size - sizeof(meta_type) - sizeof(header.thread_id);

            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, message_size);

            success = ReadParameterBuffer(static_cast<size_t>(message_size));

            if (success)
            {
                std::string message(parameter_buffer_.begin(), parameter_buffer_.end());

                for (auto decoder : decoders_)
                {
                    decoder->DispatchDisplayMessageCommand(header.thread_id, message);
                }
            }
            else
            {
                GFXRECON_LOG_ERROR("Failed to read display message meta-data block");
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to read display message meta-data block header");
        }
    }
    else
    {
        // Unrecognized metadata type.
        GFXRECON_LOG_WARNING("Skipping unrecognized meta-data block with type %u", meta_type);
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);

        success = SkipBytes(static_cast<size_t>(block_header.size) - sizeof(meta_type));
    }

    return success;
}

bool FileProcessor::IsFrameDelimiter(format::ApiCallId call_id) const
{
    // TODO: IDs of API calls that were treated as frame delimiters by the GFXReconstruct layer should be in the capture
    // file header.
    return (call_id == format::ApiCallId::ApiCall_vkQueuePresentKHR);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
