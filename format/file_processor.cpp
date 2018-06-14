/*
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

#include <cassert>

#include "format/file_processor.h"
#include "util/compressor.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

FileProcessor::FileProcessor() :
    file_descriptor_(nullptr),
    bytes_read_(0)
{
}

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

bool FileProcessor::Initialize(const std::string& file_name)
{
    bool success = false;

    file_descriptor_ = fopen(file_name.c_str(), "rb");

    if (file_descriptor_)
    {
        success = ReadFileHeader();

        if (!success)
        {
            fclose(file_descriptor_);
            file_descriptor_ = nullptr;
        }
    }

    return success;
}

bool FileProcessor::ProcessNextFrame()
{
    // TODO: Frame blocks in trace file.
    bool success = true;
    BlockHeader block_header;

    while (IsFileValid() && success)
    {
        success = ReadBlockHeader(&block_header);

        if (success)
        {
            // Process by block header type.
            if (block_header.type == BlockType::kFunctionCallBlock)
            {
                ApiCallId api_call_id;
                uint32_t thread_id = 0;
                uint32_t begin_time = 0;
                uint32_t end_time = 0;

                size_t parameter_buffer_size = block_header.size - sizeof(api_call_id);

                success = (ReadBytes(&api_call_id, sizeof(api_call_id)) == sizeof(api_call_id)) ? true : false;

                if (success && file_options_.record_thread_id)
                {
                    parameter_buffer_size -= sizeof(thread_id);
                    success = (ReadBytes(&thread_id, sizeof(thread_id)) == sizeof(thread_id)) ? true : false;
                }

                if (success && file_options_.record_begin_end_timestamp)
                {
                    parameter_buffer_size -= sizeof(begin_time) + sizeof(end_time);

                    success = (ReadBytes(&begin_time, sizeof(begin_time)) == sizeof(begin_time)) ? true : false;
                    if (success)
                    {
                        success = (ReadBytes(&end_time, sizeof(end_time)) == sizeof(end_time)) ? true : false;
                    }
                }

                if (success)
                {
                    success = ReadParameterBuffer(parameter_buffer_size);
                }

                if (success)
                {
                    ProcessFunctionCall(api_call_id, parameter_buffer_.data(), parameter_buffer_size);

                    // Break from loop on frame delimiter.
                    if (IsFrameDelimiter(api_call_id))
                    {
                        break;
                    }
                }
            }
            else if (block_header.type == BlockType::kCompressedFunctionCallBlock)
            {
                if (nullptr == compressor_)
                {
                    success = false;
                    break;
                }

                ApiCallId api_call_id;
                uint64_t expected_uncompressed_size = 0;
                uint32_t thread_id = 0;
                uint32_t begin_time = 0;
                uint32_t end_time = 0;

                success = (ReadBytes(&api_call_id, sizeof(api_call_id)) == sizeof(api_call_id)) ? true : false;
                success = (ReadBytes(&expected_uncompressed_size, sizeof(expected_uncompressed_size)) ==
                           sizeof(expected_uncompressed_size))
                              ? true
                              : false;

                size_t compressed_buffer_size =
                    block_header.size - sizeof(api_call_id) - sizeof(expected_uncompressed_size);

                if (success && file_options_.record_thread_id)
                {
                    compressed_buffer_size -= sizeof(thread_id);
                    success = (ReadBytes(&thread_id, sizeof(thread_id)) == sizeof(thread_id)) ? true : false;
                }

                if (success && file_options_.record_begin_end_timestamp)
                {
                    compressed_buffer_size -= sizeof(begin_time) + sizeof(end_time);

                    success = (ReadBytes(&begin_time, sizeof(begin_time)) == sizeof(begin_time)) ? true : false;
                    if (success)
                    {
                        success = (ReadBytes(&end_time, sizeof(end_time)) == sizeof(end_time)) ? true : false;
                    }
                }

                if (success)
                {
                    uint64_t uncompressed_size = 0;
                    success                    = ReadCompressedParameterBuffer(
                        compressed_buffer_size, expected_uncompressed_size, &uncompressed_size);
                }

                if (success)
                {
                    ProcessFunctionCall(api_call_id, parameter_buffer_.data(), expected_uncompressed_size);

                    // Break from loop on frame delimiter.
                    if (IsFrameDelimiter(api_call_id))
                    {
                        break;
                    }
                }
            }
            else if (block_header.type == BlockType::kMetaDataBlock)
            {
                // TODO
            }
        }
    }

    return success;
}

bool FileProcessor::ProcessAllFrames()
{
    bool success = true;

    while (IsFileValid() && success)
    {
        success = ProcessNextFrame();
    }

    return success;
}

bool FileProcessor::ReadFileHeader()
{
    bool success = false;

    if (ReadBytes(&file_header_, sizeof(file_header_)) == sizeof(file_header_))
    {
        std::vector<FileOptionPair> file_options(file_header_.num_options);

        size_t option_data_size = file_header_.num_options * sizeof(FileOptionPair);

        if (ReadBytes(file_options.data(), option_data_size) == option_data_size)
        {
            success = true;

            for (const auto& option : file_options)
            {
                switch (option.key)
                {
                case kCompressionType:
                    file_options_.compression_type = static_cast<util::CompressionType>(option.value);
                    break;
                case kHaveThreadId:
                    file_options_.record_thread_id = option.value ? true : false;
                    break;
                case kHaveBeginEndTimestamp:
                    file_options_.record_begin_end_timestamp = option.value ? true : false;
                    break;
                case kOmitTextures:
                    file_options_.omit_textures = option.value ? true : false;
                    break;
                case kOmitBuffers:
                    file_options_.omit_buffers = option.value ? true : false;
                    break;
                case kAddressEncodingSize:
                case kObjectEncodingSize:
                case kHandleEncodingSize:
                    // We currently assume all pointer/address values are encoded as 8 byte values.
                    break;
                default:
                    // TODO: Error logging.
                    break;
                }
            }
        }
    }

    compressor_ = util::Compressor::CreateCompressor(file_options_.compression_type);
    if ((nullptr == compressor_) && (util::kNone != file_options_.compression_type))
    {
        return false;
    }

    return success;
}

bool FileProcessor::ReadBlockHeader(BlockHeader* block_header)
{
    assert(block_header != nullptr);

    bool success = false;

    if (ReadBytes(block_header, sizeof(*block_header)) == sizeof(*block_header))
    {
        success = true;
    }

    return success;
}

bool FileProcessor::ReadFunctionCallHeader(FunctionCallHeader* function_call_header)
{
    assert(function_call_header != nullptr);

    bool success = false;

    if (ReadBytes(function_call_header, sizeof(*function_call_header)) == sizeof(*function_call_header))
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

    return (ReadBytes(parameter_buffer_.data(), buffer_size) == buffer_size) ? true : false;
}

bool FileProcessor::ReadCompressedParameterBuffer(size_t  compressed_buffer_size,
                                                  size_t  expected_uncompressed_size,
                                                  size_t* uncompressed_buffer_size)
{
    if (compressed_buffer_size > compressed_parameter_buffer_.size())
    {
        compressed_parameter_buffer_.resize(compressed_buffer_size);
    }

    if (ReadBytes(compressed_parameter_buffer_.data(), compressed_buffer_size) == compressed_buffer_size)
    {
        size_t uncompressed_size = compressor_->Decompress(compressed_buffer_size, compressed_parameter_buffer_, &parameter_buffer_);
        if ((0 < uncompressed_size) && (uncompressed_size == expected_uncompressed_size))
        {
            *uncompressed_buffer_size = uncompressed_size;
            return true;
        }
    }
    return false;
}

size_t FileProcessor::ReadBytes(void* buffer, size_t buffer_size)
{
    size_t bytes_read = fread(buffer, 1, buffer_size, file_descriptor_);
    bytes_read_ += bytes_read;
    return bytes_read;
}

void FileProcessor::ProcessFunctionCall(ApiCallId call_id, const uint8_t* parameter_buffer, size_t buffer_size)
{
    for (auto decoder : decoders_)
    {
        if (decoder->SupportsApiCall(call_id))
        {
            decoder->DecodeFunctionCall(call_id, parameter_buffer, buffer_size);
        }
    }
}

bool FileProcessor::IsFrameDelimiter(ApiCallId call_id) const
{
    // TODO: This information should be in the trace file header.
    return (call_id == ApiCallId_vkQueuePresentKHR) ? true : false;
}

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)
