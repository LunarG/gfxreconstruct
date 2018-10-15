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

#include "decode/decompress_decoder.h"
#include "util/logging.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(decode)

bool DecompressDecoder::Initialize(std::string                                filename,
                                   const format::FileHeader&                  file_header,
                                   const std::vector<format::FileOptionPair>& option_list,
                                   util::CompressionType                      target_compression_type)
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
            BRIMSTONE_LOG_WARNING("Failed to initialized file compression module (type = %u)",
                                  target_compression_type);
            return false;
        }
    }

    std::vector<format::FileOptionPair> new_option_list = option_list;
    for (auto& option : new_option_list)
    {
        switch (option.key)
        {
            case format::FileOption::kCompressionType:
                // Change the file option to the new compression type
                option.value = static_cast<uint32_t>(target_compression_type);
                break;
            case format::FileOption::kHaveThreadId:
                write_thread_id_ = (option.value != 0);
                break;
            case format::FileOption::kHaveBeginEndTimestamp:
                write_begin_end_times_ = (option.value != 0);
                break;
            case format::FileOption::kOmitTextures:
            case format::FileOption::kOmitBuffers:
            case format::FileOption::kAddressEncodingSize:
            case format::FileOption::kObjectEncodingSize:
            case format::FileOption::kHandleEncodingSize:
                // Don't touch these values from the original file
                break;
            default:
                BRIMSTONE_LOG_WARNING("Ignoring unrecognized file header option %u", option.key);
                break;
        }
    }

    if (file_stream_->IsValid())
    {
        bytes_written_ = 0;
        bytes_written_ += file_stream_->Write(&file_header, sizeof(file_header));
        bytes_written_ += file_stream_->Write(new_option_list.data(), new_option_list.size() * sizeof(format::FileOptionPair));
        success = true;
    }
    else
    {
        BRIMSTONE_LOG_ERROR("Failed to open file %s", filename_.c_str());
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

void DecompressDecoder::DecodeFunctionCall(format::ApiCallId             call_id,
                                           const format::ApiCallOptions& call_options,
                                           const uint8_t*                buffer,
                                           size_t                        buffer_size)
{
    bool write_uncompressed = (decompress_mode_ == kDecompress);

    if (decompress_mode_ == kCompress)
    {
        // Compress the buffer with the new compression format and write to the new file.
        format::CompressedFunctionCallHeader compressed_func_call_header = {};
        size_t                       packet_size                 = 0;
        size_t                       compressed_size = compressor_->Compress(buffer_size, buffer, &compressed_buffer_);

        if (0 < compressed_size && compressed_size < buffer_size)
        {
            compressed_func_call_header.block_header.type = format::BlockType::kCompressedFunctionCallBlock;
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
            bytes_written_ += file_stream_->Write(&compressed_func_call_header, sizeof(compressed_func_call_header));

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
        format::FunctionCallHeader func_call_header = {};
        size_t                     packet_size      = 0;

        func_call_header.block_header.type = format::BlockType::kFunctionCallBlock;
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
        bytes_written_ += file_stream_->Write(&func_call_header, sizeof(format::FunctionCallHeader));

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

void DecompressDecoder::DispatchDisplayMessageCommand(const std::string& message)
{
    size_t                              message_length = message.size();
    format::DisplayMessageCommandHeader message_cmd;
    message_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    message_cmd.meta_header.block_header.size =
        sizeof(message_cmd.meta_header.meta_data_type) + sizeof(message_cmd.message_size) + message_length;
    message_cmd.meta_header.meta_data_type = format::MetaDataType::kDisplayMessageCommand;
    message_cmd.message_size               = message_length;
    {
        bytes_written_ += file_stream_->Write(&message_cmd, sizeof(message_cmd));
        bytes_written_ += file_stream_->Write(message.c_str(), message_length);
    }
}

void DecompressDecoder::DispatchFillMemoryCommand(uint64_t       memory_id,
                                                  uint64_t       offset,
                                                  uint64_t       size,
                                                  const uint8_t* data)
{
    // NOTE: Don't apply the offset to the write_address here since it's coming from the file_processor
    //       at the start of the stream.  We only need to record the writing offset for future info.
    format::FillMemoryCommandHeader fill_cmd;
    const uint8_t*                  write_address = static_cast<const uint8_t*>(data);
    size_t                          write_size    = size;

    fill_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    fill_cmd.meta_header.meta_data_type    = format::MetaDataType::kFillMemoryCommand;
    fill_cmd.memory_id                     = memory_id;
    fill_cmd.memory_offset                 = offset;
    fill_cmd.memory_size                   = size;

    if ((decompress_mode_ == kCompress) && (compressor_ != nullptr))
    {
        size_t compressed_size = compressor_->Compress(size, write_address, &compressed_buffer_);
        if ((compressed_size > 0) && (compressed_size < size))
        {
            // We don't have a special header for compressed fill commands because the header always includes
            // the uncompressed size, so we just change the type to indicate the data is compressed.
            fill_cmd.meta_header.block_header.type = format::BlockType::kCompressedMetaDataBlock;

            write_address = compressed_buffer_.data();
            write_size    = compressed_size;
        }
    }

    // Calculate size of packet with compressed or uncompressed data size.
    fill_cmd.meta_header.block_header.size = sizeof(fill_cmd.meta_header.meta_data_type) +
                                                sizeof(fill_cmd.memory_id) + sizeof(fill_cmd.memory_offset) +
                                                sizeof(fill_cmd.memory_size) + write_size;

    {
        std::lock_guard<std::mutex> lock(file_lock_);

        bytes_written_ += file_stream_->Write(&fill_cmd, sizeof(fill_cmd));
        bytes_written_ += file_stream_->Write(write_address, write_size);
    }
}

void DecompressDecoder::DispatchResizeWindowCommand(format::HandleId surface_id, uint32_t width, uint32_t height)
{
    format::ResizeWindowCommand resize_cmd;
    resize_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    resize_cmd.meta_header.block_header.size = sizeof(resize_cmd.meta_header.meta_data_type) +
                                               sizeof(resize_cmd.surface_id) + sizeof(resize_cmd.width) +
                                               sizeof(resize_cmd.height);
    resize_cmd.meta_header.meta_data_type = format::MetaDataType::kResizeWindowCommand;
    resize_cmd.surface_id                 = surface_id;
    resize_cmd.width                      = width;
    resize_cmd.height                     = height;
    {
        std::lock_guard<std::mutex> lock(file_lock_);
        bytes_written_ += file_stream_->Write(&resize_cmd, sizeof(resize_cmd));
    }
}

BRIMSTONE_END_NAMESPACE(decode)
BRIMSTONE_END_NAMESPACE(brimstone)
