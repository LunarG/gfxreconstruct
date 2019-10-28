/*
** Copyright (c) 2018-2019 Valve Corporation
** Copyright (c) 2018-2019 LunarG, Inc.
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

#include "decode/compression_converter.h"
#include "format/format_util.h"
#include "util/logging.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

CompressionConverter::CompressionConverter() : bytes_written_(0), compressor_(nullptr), decompressing_(false) {}

CompressionConverter::~CompressionConverter()
{
    Destroy();
}

bool CompressionConverter::Initialize(std::string                                filename,
                                      const format::FileHeader&                  file_header,
                                      const std::vector<format::FileOptionPair>& option_list,
                                      format::CompressionType                    target_compression_type)
{
    bool success = false;

    // Modify compression setting and write file header to a new file.
    filename_    = filename;
    file_stream_ = std::make_unique<util::FileOutputStream>(filename_);

    if (format::CompressionType::kNone == target_compression_type)
    {
        decompressing_ = true;
        compressor_    = nullptr;
    }
    else
    {
        decompressing_ = false;
        compressor_    = format::CreateCompressor(target_compression_type);

        if (nullptr == compressor_)
        {
            GFXRECON_LOG_WARNING("Failed to initialized file compression module (type = %u)", target_compression_type);
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
            default:
                GFXRECON_LOG_WARNING("Ignoring unrecognized file header option %u", option.key);
                break;
        }
    }

    if (file_stream_->IsValid())
    {
        bytes_written_ = 0;
        bytes_written_ += file_stream_->Write(&file_header, sizeof(file_header));
        bytes_written_ +=
            file_stream_->Write(new_option_list.data(), new_option_list.size() * sizeof(format::FileOptionPair));
        success = true;
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to open file %s", filename_.c_str());
    }

    return success;
}

void CompressionConverter::Destroy()
{
    if (nullptr != compressor_)
    {
        delete compressor_;
        compressor_ = nullptr;
    }
}

void CompressionConverter::DecodeFunctionCall(format::ApiCallId  call_id,
                                              const ApiCallInfo& call_info,
                                              const uint8_t*     buffer,
                                              size_t             buffer_size)
{
    bool write_uncompressed = decompressing_;

    if (!decompressing_)
    {
        // Compress the buffer with the new compression format and write to the new file.
        format::CompressedFunctionCallHeader compressed_func_call_header = {};
        size_t                               packet_size                 = 0;
        size_t compressed_size = compressor_->Compress(buffer_size, buffer, &compressed_buffer_);

        if (0 < compressed_size && compressed_size < buffer_size)
        {
            compressed_func_call_header.block_header.type = format::BlockType::kCompressedFunctionCallBlock;
            compressed_func_call_header.api_call_id       = call_id;
            compressed_func_call_header.thread_id         = call_info.thread_id;
            compressed_func_call_header.uncompressed_size = buffer_size;

            packet_size += sizeof(compressed_func_call_header.api_call_id) +
                           sizeof(compressed_func_call_header.thread_id) +
                           sizeof(compressed_func_call_header.uncompressed_size) + compressed_size;

            compressed_func_call_header.block_header.size = packet_size;

            // Write compressed function call block header.
            bytes_written_ += file_stream_->Write(&compressed_func_call_header, sizeof(compressed_func_call_header));

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
        func_call_header.thread_id         = call_info.thread_id;

        packet_size += sizeof(func_call_header.api_call_id) + sizeof(func_call_header.thread_id) + buffer_size;

        func_call_header.block_header.size = packet_size;

        // Write compressed function call block header.
        bytes_written_ += file_stream_->Write(&func_call_header, sizeof(func_call_header));

        // Write parameter data.
        bytes_written_ += file_stream_->Write(buffer, buffer_size);
    }
}

void CompressionConverter::DispatchStateBeginMarker(uint64_t frame_number)
{
    format::Marker marker;
    marker.header.size  = sizeof(marker.marker_type) + sizeof(marker.frame_number);
    marker.header.type  = format::kStateMarkerBlock;
    marker.marker_type  = format::kBeginMarker;
    marker.frame_number = frame_number;

    bytes_written_ += file_stream_->Write(&marker, sizeof(marker));
}

void CompressionConverter::DispatchStateEndMarker(uint64_t frame_number)
{
    format::Marker marker;
    marker.header.size  = sizeof(marker.marker_type) + sizeof(marker.frame_number);
    marker.header.type  = format::kStateMarkerBlock;
    marker.marker_type  = format::kEndMarker;
    marker.frame_number = frame_number;

    bytes_written_ += file_stream_->Write(&marker, sizeof(marker));
}

void CompressionConverter::DispatchDisplayMessageCommand(format::ThreadId thread_id, const std::string& message)
{
    size_t                              message_length = message.size();
    format::DisplayMessageCommandHeader message_cmd;
    message_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    message_cmd.meta_header.block_header.size =
        sizeof(message_cmd.meta_header.meta_data_type) + sizeof(message_cmd.thread_id) + message_length;
    message_cmd.meta_header.meta_data_type = format::MetaDataType::kDisplayMessageCommand;
    message_cmd.thread_id                  = thread_id;

    bytes_written_ += file_stream_->Write(&message_cmd, sizeof(message_cmd));
    bytes_written_ += file_stream_->Write(message.c_str(), message_length);
}

void CompressionConverter::DispatchFillMemoryCommand(
    format::ThreadId thread_id, uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data)
{
    // NOTE: Don't apply the offset to the write_address here since it's coming from the file_processor
    //       at the start of the stream.  We only need to record the writing offset for future info.
    format::FillMemoryCommandHeader fill_cmd;
    const uint8_t*                  write_address = data;

    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);
    size_t write_size = static_cast<size_t>(size);

    fill_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    fill_cmd.meta_header.meta_data_type    = format::MetaDataType::kFillMemoryCommand;
    fill_cmd.thread_id                     = thread_id;
    fill_cmd.memory_id                     = memory_id;
    fill_cmd.memory_offset                 = offset;
    fill_cmd.memory_size                   = write_size;

    if ((!decompressing_) && (compressor_ != nullptr))
    {
        size_t compressed_size = compressor_->Compress(write_size, write_address, &compressed_buffer_);
        if ((compressed_size > 0) && (compressed_size < write_size))
        {
            // We don't have a special header for compressed fill commands because the header always includes
            // the uncompressed size, so we just change the type to indicate the data is compressed.
            fill_cmd.meta_header.block_header.type = format::BlockType::kCompressedMetaDataBlock;

            write_address = compressed_buffer_.data();
            write_size    = compressed_size;
        }
    }

    // Calculate size of packet with compressed or uncompressed data size.
    fill_cmd.meta_header.block_header.size = sizeof(fill_cmd.meta_header.meta_data_type) + sizeof(fill_cmd.thread_id) +
                                             sizeof(fill_cmd.memory_id) + sizeof(fill_cmd.memory_offset) +
                                             sizeof(fill_cmd.memory_size) + write_size;

    bytes_written_ += file_stream_->Write(&fill_cmd, sizeof(fill_cmd));
    bytes_written_ += file_stream_->Write(write_address, write_size);
}

void CompressionConverter::DispatchResizeWindowCommand(format::ThreadId thread_id,
                                                       format::HandleId surface_id,
                                                       uint32_t         width,
                                                       uint32_t         height)
{
    format::ResizeWindowCommand resize_cmd;
    resize_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    resize_cmd.meta_header.block_header.size = sizeof(resize_cmd.meta_header.meta_data_type) +
                                               sizeof(resize_cmd.thread_id) + sizeof(resize_cmd.surface_id) +
                                               sizeof(resize_cmd.width) + sizeof(resize_cmd.height);
    resize_cmd.meta_header.meta_data_type = format::MetaDataType::kResizeWindowCommand;
    resize_cmd.thread_id                  = thread_id;
    resize_cmd.surface_id                 = surface_id;
    resize_cmd.width                      = width;
    resize_cmd.height                     = height;

    bytes_written_ += file_stream_->Write(&resize_cmd, sizeof(resize_cmd));
}

void CompressionConverter::DispatchSetSwapchainImageStateCommand(
    format::ThreadId                                    thread_id,
    format::HandleId                                    device_id,
    format::HandleId                                    swapchain_id,
    uint32_t                                            last_presented_image,
    const std::vector<format::SwapchainImageStateInfo>& image_state)
{
    format::SetSwapchainImageStateCommandHeader header;
    size_t                                      image_count      = image_state.size();
    size_t                                      image_state_size = 0;

    // Initialize standard block header.
    header.meta_header.block_header.size = sizeof(header.meta_header.meta_data_type) + sizeof(header.thread_id) +
                                           sizeof(header.device_id) + sizeof(header.swapchain_id) +
                                           sizeof(header.last_presented_image) + sizeof(header.image_info_count);
    header.meta_header.block_header.type = format::kMetaDataBlock;

    if (image_count > 0)
    {
        image_state_size = image_count * sizeof(image_state[0]);
        header.meta_header.block_header.size += image_state_size;
    }

    // Initialize block data for set-swapchain-image-state meta-data command.
    header.meta_header.meta_data_type = format::kSetSwapchainImageStateCommand;
    header.thread_id                  = thread_id;
    header.device_id                  = device_id;
    header.swapchain_id               = swapchain_id;
    header.last_presented_image       = last_presented_image;
    header.image_info_count           = static_cast<uint32_t>(image_count);

    bytes_written_ += file_stream_->Write(&header, sizeof(header));
    bytes_written_ += file_stream_->Write(image_state.data(), image_state_size);
}

void CompressionConverter::DispatchBeginResourceInitCommand(format::ThreadId thread_id,
                                                            format::HandleId device_id,
                                                            uint64_t         max_resource_size,
                                                            uint64_t         max_copy_size)
{
    format::BeginResourceInitCommand begin_cmd;
    begin_cmd.meta_header.block_header.size = sizeof(begin_cmd) - sizeof(begin_cmd.meta_header.block_header);
    begin_cmd.meta_header.block_header.type = format::kMetaDataBlock;
    begin_cmd.meta_header.meta_data_type    = format::kBeginResourceInitCommand;
    begin_cmd.thread_id                     = thread_id;
    begin_cmd.device_id                     = device_id;
    begin_cmd.max_resource_size             = max_resource_size;
    begin_cmd.max_copy_size                 = max_copy_size;

    bytes_written_ += file_stream_->Write(&begin_cmd, sizeof(begin_cmd));
}

void CompressionConverter::DispatchEndResourceInitCommand(format::ThreadId thread_id, format::HandleId device_id)
{
    format::EndResourceInitCommand end_cmd;
    end_cmd.meta_header.block_header.size = sizeof(end_cmd) - sizeof(end_cmd.meta_header.block_header);
    end_cmd.meta_header.block_header.type = format::kMetaDataBlock;
    end_cmd.meta_header.meta_data_type    = format::kEndResourceInitCommand;
    end_cmd.thread_id                     = thread_id;
    end_cmd.device_id                     = device_id;

    bytes_written_ += file_stream_->Write(&end_cmd, sizeof(end_cmd));
}

void CompressionConverter::DispatchInitBufferCommand(format::ThreadId thread_id,
                                                     format::HandleId device_id,
                                                     format::HandleId buffer_id,
                                                     uint64_t         data_size,
                                                     const uint8_t*   data)
{
    const uint8_t* write_address = data;

    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, data_size);
    size_t write_size = static_cast<size_t>(data_size);

    format::InitBufferCommandHeader init_cmd;

    init_cmd.meta_header.block_header.type = format::kMetaDataBlock;
    init_cmd.meta_header.meta_data_type    = format::kInitBufferCommand;
    init_cmd.thread_id                     = thread_id;
    init_cmd.device_id                     = device_id;
    init_cmd.buffer_id                     = buffer_id;
    init_cmd.data_size                     = write_size; // Uncompressed data size.

    if (compressor_ != nullptr)
    {
        size_t compressed_size = compressor_->Compress(write_size, write_address, &compressed_buffer_);

        if ((compressed_size > 0) && (compressed_size < write_size))
        {
            init_cmd.meta_header.block_header.type = format::BlockType::kCompressedMetaDataBlock;

            write_address = compressed_buffer_.data();
            write_size    = compressed_size;
        }
    }

    // Calculate size of packet with compressed or uncompressed data size.
    init_cmd.meta_header.block_header.size =
        (sizeof(init_cmd) - sizeof(init_cmd.meta_header.block_header)) + write_size;

    bytes_written_ += file_stream_->Write(&init_cmd, sizeof(init_cmd));
    bytes_written_ += file_stream_->Write(write_address, write_size);
}

void CompressionConverter::DispatchInitImageCommand(format::ThreadId             thread_id,
                                                    format::HandleId             device_id,
                                                    format::HandleId             image_id,
                                                    uint64_t                     data_size,
                                                    uint32_t                     aspect,
                                                    uint32_t                     layout,
                                                    const std::vector<uint64_t>& level_sizes,
                                                    const uint8_t*               data)
{
    format::InitImageCommandHeader init_cmd;

    // Packet size without the resource data.
    init_cmd.meta_header.block_header.size = sizeof(init_cmd) - sizeof(init_cmd.meta_header.block_header);
    init_cmd.meta_header.block_header.type = format::kMetaDataBlock;
    init_cmd.meta_header.meta_data_type    = format::kInitImageCommand;
    init_cmd.thread_id                     = thread_id;
    init_cmd.device_id                     = device_id;
    init_cmd.image_id                      = image_id;
    init_cmd.aspect                        = aspect;
    init_cmd.layout                        = layout;

    if (data_size > 0)
    {
        assert(!level_sizes.empty());

        const uint8_t* write_address = data;

        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, data_size);
        size_t write_size = static_cast<size_t>(data_size);

        // Store uncompressed data size in packet.
        init_cmd.data_size   = write_size;
        init_cmd.level_count = static_cast<uint32_t>(level_sizes.size());

        if (compressor_ != nullptr)
        {
            size_t compressed_size = compressor_->Compress(write_size, write_address, &compressed_buffer_);

            if ((compressed_size > 0) && (compressed_size < write_size))
            {
                init_cmd.meta_header.block_header.type = format::BlockType::kCompressedMetaDataBlock;

                write_address = compressed_buffer_.data();
                write_size    = compressed_size;
            }
        }

        // Calculate size of packet with compressed or uncompressed data size.
        size_t levels_size = level_sizes.size() * sizeof(level_sizes[0]);

        init_cmd.meta_header.block_header.size += levels_size + write_size;

        bytes_written_ += file_stream_->Write(&init_cmd, sizeof(init_cmd));
        bytes_written_ += file_stream_->Write(level_sizes.data(), levels_size);
        bytes_written_ += file_stream_->Write(write_address, write_size);
    }
    else
    {
        // Write a packet without resource data; replay must still perform a layout transition at image
        // initialization.
        init_cmd.data_size   = 0;
        init_cmd.level_count = 0;

        bytes_written_ += file_stream_->Write(&init_cmd, sizeof(init_cmd));
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
