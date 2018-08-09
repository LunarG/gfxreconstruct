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

#include "format/decompress_decoder.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

bool DecompressDecoder::Initialize(std::string                        filename,
                                   const FileHeader&                  file_header,
                                   const std::vector<FileOptionPair>& option_list,
                                   util::CompressionType              target_compression_type)
{
    bool success = false;

    // Modify compression setting and write file header to a new file.
    filename_    = filename;
    file_stream_ = std::make_unique<util::FileOutputStream>(filename_);

    // Set the default for some other options
    write_thread_id_       = false;
    write_begin_end_times_ = false;

    if (util::kNone == target_compression_type)
    {
        decompress_mode_ = kDecompress;
        compressor_      = nullptr;
    }
    else
    {
        decompress_mode_ = kCompress;

        compressor_ = util::Compressor::CreateCompressor(target_compression_type);
        if (nullptr == compressor_)
        {
            return false;
        }
    }

    std::vector<FileOptionPair> new_option_list = option_list;
    for (auto& option : new_option_list)
    {
        switch (option.key)
        {
            case kCompressionType:
                // Change the file option to the new compression type
                option.value = static_cast<uint32_t>(target_compression_type);
                break;
            case kHaveThreadId:
                write_thread_id_ = (option.value != 0);
                break;
            case kHaveBeginEndTimestamp:
                write_begin_end_times_ = (option.value != 0);
                break;
            case kOmitTextures:
            case kOmitBuffers:
            case kAddressEncodingSize:
            case kObjectEncodingSize:
            case kHandleEncodingSize:
                // Don't touch these values from the original file
                break;
            default:
                // TODO: Error logging.
                break;
        }
    }

    if (file_stream_->IsValid())
    {
        bytes_written_ = 0;
        bytes_written_ += file_stream_->Write(&file_header, sizeof(file_header));
        bytes_written_ += file_stream_->Write(new_option_list.data(), new_option_list.size() * sizeof(FileOptionPair));
        success = true;
    }

    return success;
}

void DecompressDecoder::Destroy()
{
    if (nullptr != compressor_)
    {
        delete compressor_;
        compressor_ = nullptr;
    }
}

void DecompressDecoder::DecodeFunctionCall(ApiCallId             call_id,
                                           const ApiCallOptions& call_options,
                                           const uint8_t*        buffer,
                                           size_t                buffer_size)
{
    bool write_uncompressed = (decompress_mode_ == kDecompress);

    if (decompress_mode_ == kCompress)
    {
        // Compress the buffer with the new compression format and write to the new file.
        CompressedFunctionCallHeader compressed_func_call_header = {};
        size_t                       packet_size                 = 0;
        size_t                       compressed_size = compressor_->Compress(buffer_size, buffer, &compressed_buffer_);

        if (0 < compressed_size && compressed_size < buffer_size)
        {
            compressed_func_call_header.block_header.type = BlockType::kCompressedFunctionCallBlock;
            compressed_func_call_header.api_call_id       = call_id;
            compressed_func_call_header.uncompressed_size = buffer_size;

            packet_size += sizeof(compressed_func_call_header.api_call_id) +
                           sizeof(compressed_func_call_header.uncompressed_size) + compressed_size;

            if (write_thread_id_)
            {
                packet_size += sizeof(call_options.thread_id);
            }
            if (write_begin_end_times_)
            {
                packet_size += sizeof(call_options.begin_time) + sizeof(call_options.end_time);
            }

            compressed_func_call_header.block_header.size = packet_size;

            // Write compressed function call block header.
            bytes_written_ += file_stream_->Write(&compressed_func_call_header, sizeof(CompressedFunctionCallHeader));

            // Add optional call items
            if (write_thread_id_)
            {
                bytes_written_ += file_stream_->Write(&call_options.thread_id, sizeof(call_options.thread_id));
            }

            if (write_begin_end_times_)
            {
                bytes_written_ += file_stream_->Write(&call_options.begin_time, sizeof(call_options.begin_time));
                bytes_written_ += file_stream_->Write(&call_options.end_time, sizeof(call_options.end_time));
            }

            // Write parameter data.
            bytes_written_ += file_stream_->Write(compressed_buffer_.data(), compressed_size);
        }
        else
        {
            // It's bigger compressed than uncompressed, so only write the uncompressed data.
            write_uncompressed = true;
        }
    }

    if (write_uncompressed)
    {
        // Buffer is currently not compressed; it was decompressed prior to this call.
        FunctionCallHeader func_call_header = {};
        size_t             packet_size      = 0;

        func_call_header.block_header.type = BlockType::kFunctionCallBlock;
        func_call_header.api_call_id       = call_id;

        packet_size += sizeof(func_call_header.api_call_id) + buffer_size;

        if (write_thread_id_)
        {
            packet_size += sizeof(call_options.thread_id);
        }
        if (write_begin_end_times_)
        {
            packet_size += sizeof(call_options.begin_time) + sizeof(call_options.end_time);
        }

        func_call_header.block_header.size = packet_size;

        // Write compressed function call block header.
        bytes_written_ += file_stream_->Write(&func_call_header, sizeof(FunctionCallHeader));

        // Add optional call items
        if (write_thread_id_)
        {
            bytes_written_ += file_stream_->Write(&call_options.thread_id, sizeof(call_options.thread_id));
        }

        if (write_begin_end_times_)
        {
            bytes_written_ += file_stream_->Write(&call_options.begin_time, sizeof(call_options.begin_time));
            bytes_written_ += file_stream_->Write(&call_options.end_time, sizeof(call_options.end_time));
        }

        // Write parameter data.
        bytes_written_ += file_stream_->Write(buffer, buffer_size);
    }
}

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)
