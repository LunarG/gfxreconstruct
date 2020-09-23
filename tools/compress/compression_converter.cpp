/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#include "compression_converter.h"

#include "format/format_util.h"
#include "util/logging.h"

#include <cassert>
#include <numeric>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

CompressionConverter::CompressionConverter() :
    decompressing_(true), target_compression_type_(format::CompressionType::kNone)
{}

CompressionConverter::~CompressionConverter() {}

bool CompressionConverter::Initialize(const std::string&      input_filename,
                                      const std::string&      output_filename,
                                      format::CompressionType target_compression_type)
{
    bool success = CreateCompressor(target_compression_type, &target_compressor_);

    if (success)
    {
        // The target compression type needs to be set before FileTransformer::Initialize is called, because it invokes
        // WriteFileHeader, which depends on a valid target compression type.
        target_compression_type_ = target_compression_type;
        decompressing_           = (target_compression_type == format::CompressionType::kNone);
        success                  = FileTransformer::Initialize(input_filename, output_filename);
    }

    return success;
}

bool CompressionConverter::WriteFileHeader(const format::FileHeader&                  header,
                                           const std::vector<format::FileOptionPair>& options)
{
    std::vector<format::FileOptionPair> output_options(options);
    for (auto& option : output_options)
    {
        if (option.key == format::FileOption::kCompressionType)
        {
            option.value = static_cast<uint32_t>(target_compression_type_);
            break;
        }
    }

    return FileTransformer::WriteFileHeader(header, output_options);
}

bool CompressionConverter::ProcessFunctionCall(const format::BlockHeader& block_header, format::ApiCallId call_id)
{
    size_t           parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(call_id);
    uint64_t         uncompressed_size     = 0;
    format::ThreadId thread_id             = 0;

    bool success = ReadBytes(&thread_id, sizeof(thread_id));

    if (success)
    {
        parameter_buffer_size -= sizeof(thread_id);

        if (format::IsBlockCompressed(block_header.type))
        {
            success = ReadBytes(&uncompressed_size, sizeof(uncompressed_size));

            if (success)
            {
                parameter_buffer_size -= sizeof(uncompressed_size);

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
            success = WriteFunctionCall(call_id, thread_id, parameter_buffer_size);
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read function call block header");
    }

    return success;
}

bool CompressionConverter::ProcessMetaData(const format::BlockHeader& block_header, format::MetaDataType meta_type)
{
    // Only the meta data blocks that contain resource data support compression.  The rest of the meta data block types
    // can be copied directly to the new file.
    if (meta_type == format::MetaDataType::kFillMemoryCommand)
    {
        return WriteFillMemoryMetaData(block_header, meta_type);
    }
    else if (meta_type == format::MetaDataType::kInitBufferCommand)
    {
        return WriteInitBufferMetaData(block_header, meta_type);
    }
    else if (meta_type == format::MetaDataType::kInitImageCommand)
    {
        return WriteInitImageMetaData(block_header, meta_type);
    }
    else
    {
        // The current block should not be compressed.  If it is compressed, it is most likely a new block type that is
        // not supported.
        if (format::IsBlockCompressed(block_header.type))
        {
            HandleBlockWriteError(kErrorUnsupportedBlockType,
                                  "Failed to process unrecognized compressed meta data block type.");
            return false;
        }

        return FileTransformer::ProcessMetaData(block_header, meta_type);
    }
}

bool CompressionConverter::WriteFunctionCall(format::ApiCallId call_id, format::ThreadId thread_id, size_t buffer_size)
{
    bool        write_uncompressed = decompressing_;
    const auto& buffer             = GetParameterBuffer();

    if (!write_uncompressed)
    {
        assert(target_compressor_ != nullptr);

        // Compress the buffer with the new compression format and write to the new file.
        auto&  compressed_buffer = GetCompressedParameterBuffer();
        size_t packet_size       = 0;
        size_t compressed_size   = target_compressor_->Compress(buffer_size, buffer.data(), &compressed_buffer);

        if (0 < compressed_size && compressed_size < buffer_size)
        {
            format::CompressedFunctionCallHeader compressed_func_call_header = {};
            compressed_func_call_header.block_header.type = format::BlockType::kCompressedFunctionCallBlock;
            compressed_func_call_header.api_call_id       = call_id;
            compressed_func_call_header.thread_id         = thread_id;
            compressed_func_call_header.uncompressed_size = buffer_size;

            packet_size += sizeof(compressed_func_call_header.api_call_id) +
                           sizeof(compressed_func_call_header.thread_id) +
                           sizeof(compressed_func_call_header.uncompressed_size) + compressed_size;

            compressed_func_call_header.block_header.size = packet_size;

            if (!WriteBytes(&compressed_func_call_header, sizeof(compressed_func_call_header)))
            {
                HandleBlockWriteError(kErrorWritingCompressedBlockHeader,
                                      "Failed to write compressed function call block header");
                return false;
            }

            if (!WriteBytes(compressed_buffer.data(), compressed_size))
            {
                HandleBlockWriteError(kErrorWritingCompressedBlockData,
                                      "Failed to write compressed function call block data");
                return false;
            }
        }
        else
        {
            // It's bigger compressed than uncompressed, so write the uncompressed data.
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
        func_call_header.thread_id         = thread_id;

        packet_size += sizeof(func_call_header.api_call_id) + sizeof(func_call_header.thread_id) + buffer_size;

        func_call_header.block_header.size = packet_size;

        if (!WriteBytes(&func_call_header, sizeof(func_call_header)))
        {
            HandleBlockWriteError(kErrorWritingBlockHeader, "Failed to write function call block header");
            return false;
        }

        if (!WriteBytes(buffer.data(), buffer_size))
        {
            HandleBlockWriteError(kErrorWritingBlockData, "Failed to write function call block data");
            return false;
        }
    }

    return true;
}

bool CompressionConverter::WriteFillMemoryMetaData(const format::BlockHeader& block_header,
                                                   format::MetaDataType       meta_type)
{
    assert(meta_type == format::MetaDataType::kFillMemoryCommand);

    format::FillMemoryCommandHeader fill_cmd;

    bool success = ReadBytes(&fill_cmd.thread_id, sizeof(fill_cmd.thread_id));
    success      = success && ReadBytes(&fill_cmd.memory_id, sizeof(fill_cmd.memory_id));
    success      = success && ReadBytes(&fill_cmd.memory_offset, sizeof(fill_cmd.memory_offset));
    success      = success && ReadBytes(&fill_cmd.memory_size, sizeof(fill_cmd.memory_size));

    if (success)
    {
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, fill_cmd.memory_size);

        size_t data_size = static_cast<size_t>(fill_cmd.memory_size);

        if (format::IsBlockCompressed(block_header.type))
        {
            size_t uncompressed_size = 0;
            size_t compressed_size =
                static_cast<size_t>(block_header.size - format::GetMetaDataBlockBaseSize(fill_cmd));

            if (!ReadCompressedParameterBuffer(compressed_size, data_size, &uncompressed_size))
            {
                HandleBlockReadError(kErrorReadingCompressedBlockData, "Failed to read fill memory meta-data block");
                return false;
            }

            assert(uncompressed_size == data_size);
        }
        else
        {
            if (!ReadParameterBuffer(data_size))
            {
                HandleBlockReadError(kErrorReadingBlockData, "Failed to read fill memory meta-data block");
                return false;
            }
        }

        const auto&    buffer       = GetParameterBuffer();
        const uint8_t* data_address = buffer.data();

        fill_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        fill_cmd.meta_header.meta_data_type    = meta_type;

        if (!decompressing_)
        {
            assert(target_compressor_ != nullptr);

            auto&  compressed_buffer = GetCompressedParameterBuffer();
            size_t compressed_size   = target_compressor_->Compress(data_size, data_address, &compressed_buffer);

            if ((compressed_size > 0) && (compressed_size < data_size))
            {
                // We don't have a special header for compressed fill commands because the header always includes
                // the uncompressed size, so we just change the type to indicate the data is compressed.
                fill_cmd.meta_header.block_header.type = format::BlockType::kCompressedMetaDataBlock;

                data_address = compressed_buffer.data();
                data_size    = compressed_size;
            }
        }

        // Calculate size of packet with compressed or uncompressed data size.
        fill_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(fill_cmd) + data_size;

        if (!WriteBytes(&fill_cmd, sizeof(fill_cmd)))
        {
            HandleBlockWriteError(kErrorWritingBlockHeader, "Failed to write fill memory meta-data block header");
            return false;
        }

        if (!WriteBytes(data_address, data_size))
        {
            HandleBlockWriteError(kErrorWritingBlockData, "Failed to write fill memory meta-data block");
            return false;
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read fill memory meta-data block header");
        return false;
    }

    return true;
}

bool CompressionConverter::WriteInitBufferMetaData(const format::BlockHeader& block_header,
                                                   format::MetaDataType       meta_type)
{
    assert(meta_type == format::MetaDataType::kInitBufferCommand);

    format::InitBufferCommandHeader init_cmd;

    bool success = ReadBytes(&init_cmd.thread_id, sizeof(init_cmd.thread_id));
    success      = success && ReadBytes(&init_cmd.device_id, sizeof(init_cmd.device_id));
    success      = success && ReadBytes(&init_cmd.buffer_id, sizeof(init_cmd.buffer_id));
    success      = success && ReadBytes(&init_cmd.data_size, sizeof(init_cmd.data_size));

    if (success)
    {
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, init_cmd.data_size);

        size_t data_size = static_cast<size_t>(init_cmd.data_size);

        if (format::IsBlockCompressed(block_header.type))
        {
            size_t uncompressed_size = 0;
            size_t compressed_size =
                static_cast<size_t>(block_header.size - format::GetMetaDataBlockBaseSize(init_cmd));

            if (!ReadCompressedParameterBuffer(compressed_size, data_size, &uncompressed_size))
            {
                HandleBlockReadError(kErrorReadingCompressedBlockData, "Failed to read init buffer meta-data block");
                return false;
            }

            assert(uncompressed_size == data_size);
        }
        else
        {
            if (!ReadParameterBuffer(data_size))
            {
                HandleBlockReadError(kErrorReadingBlockData, "Failed to read init buffer meta-data block");
                return false;
            }
        }

        const auto&    buffer       = GetParameterBuffer();
        const uint8_t* data_address = buffer.data();

        init_cmd.meta_header.block_header.type = format::kMetaDataBlock;
        init_cmd.meta_header.meta_data_type    = meta_type;

        if (!decompressing_)
        {
            assert(target_compressor_ != nullptr);

            auto&  compressed_buffer = GetCompressedParameterBuffer();
            size_t compressed_size   = target_compressor_->Compress(data_size, data_address, &compressed_buffer);

            if ((compressed_size > 0) && (compressed_size < data_size))
            {
                init_cmd.meta_header.block_header.type = format::BlockType::kCompressedMetaDataBlock;

                data_address = compressed_buffer.data();
                data_size    = compressed_size;
            }
        }

        // Calculate size of packet with compressed or uncompressed data size.
        init_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(init_cmd) + data_size;

        if (!WriteBytes(&init_cmd, sizeof(init_cmd)))
        {
            HandleBlockWriteError(kErrorWritingBlockHeader, "Failed to write init buffer meta-data block header");
            return false;
        }

        if (!WriteBytes(data_address, data_size))
        {
            HandleBlockWriteError(kErrorWritingBlockData, "Failed to write init buffer meta-data block");
            return false;
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read init buffer meta-data block header");
        return false;
    }

    return true;
}

bool CompressionConverter::WriteInitImageMetaData(const format::BlockHeader& block_header,
                                                  format::MetaDataType       meta_type)
{
    assert(meta_type == format::MetaDataType::kInitImageCommand);

    format::InitImageCommandHeader init_cmd;
    std::vector<uint64_t>          level_sizes;
    size_t                         levels_size = 0;

    bool success = ReadBytes(&init_cmd.thread_id, sizeof(init_cmd.thread_id));
    success      = success && ReadBytes(&init_cmd.device_id, sizeof(init_cmd.device_id));
    success      = success && ReadBytes(&init_cmd.image_id, sizeof(init_cmd.image_id));
    success      = success && ReadBytes(&init_cmd.data_size, sizeof(init_cmd.data_size));
    success      = success && ReadBytes(&init_cmd.aspect, sizeof(init_cmd.aspect));
    success      = success && ReadBytes(&init_cmd.layout, sizeof(init_cmd.layout));
    success      = success && ReadBytes(&init_cmd.level_count, sizeof(init_cmd.level_count));

    if (success && (init_cmd.level_count > 0))
    {
        level_sizes.resize(init_cmd.level_count);
        levels_size = init_cmd.level_count * sizeof(level_sizes[0]);
        success     = ReadBytes(level_sizes.data(), levels_size);
    }

    if (success)
    {
        // Packet size without the resource data.
        init_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(init_cmd);
        init_cmd.meta_header.block_header.type = format::kMetaDataBlock;
        init_cmd.meta_header.meta_data_type    = meta_type;

        if (init_cmd.data_size > 0)
        {
            assert(init_cmd.data_size == std::accumulate(level_sizes.begin(), level_sizes.end(), 0ull));
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, init_cmd.data_size);

            size_t data_size = static_cast<size_t>(init_cmd.data_size);

            if (format::IsBlockCompressed(block_header.type))
            {
                size_t uncompressed_size = 0;
                size_t compressed_size =
                    static_cast<size_t>(block_header.size - format::GetMetaDataBlockBaseSize(init_cmd)) - levels_size;

                if (!ReadCompressedParameterBuffer(compressed_size, data_size, &uncompressed_size))
                {
                    HandleBlockReadError(kErrorReadingCompressedBlockData, "Failed to read init image meta-data block");
                    return false;
                }

                assert(uncompressed_size == data_size);
            }
            else
            {
                if (!ReadParameterBuffer(data_size))
                {
                    HandleBlockReadError(kErrorReadingBlockData, "Failed to read init image meta-data block");
                    return false;
                }
            }

            const auto&    buffer       = GetParameterBuffer();
            const uint8_t* data_address = buffer.data();

            init_cmd.meta_header.block_header.type = format::kMetaDataBlock;
            init_cmd.meta_header.meta_data_type    = meta_type;

            if (!decompressing_)
            {
                assert(target_compressor_ != nullptr);

                auto&  compressed_buffer = GetCompressedParameterBuffer();
                size_t compressed_size   = target_compressor_->Compress(data_size, data_address, &compressed_buffer);

                if ((compressed_size > 0) && (compressed_size < data_size))
                {
                    init_cmd.meta_header.block_header.type = format::BlockType::kCompressedMetaDataBlock;

                    data_address = compressed_buffer.data();
                    data_size    = compressed_size;
                }
            }

            // Calculate size of packet with compressed or uncompressed data size.
            init_cmd.meta_header.block_header.size =
                format::GetMetaDataBlockBaseSize(init_cmd) + levels_size + data_size;

            if (!WriteBytes(&init_cmd, sizeof(init_cmd)))
            {
                HandleBlockWriteError(kErrorWritingBlockHeader, "Failed to write init image meta-data block header");
                return false;
            }

            if (!WriteBytes(level_sizes.data(), levels_size))
            {
                HandleBlockWriteError(kErrorWritingBlockHeader, "Failed to write init image meta-data block");
                return false;
            }

            if (!WriteBytes(data_address, data_size))
            {
                HandleBlockWriteError(kErrorWritingBlockData, "Failed to write init image meta-data block");
                return false;
            }
        }
        else
        {
            // Write a packet without resource data; replay must still perform a layout transition at image
            // initialization.
            init_cmd.data_size   = 0;
            init_cmd.level_count = 0;

            if (!WriteBytes(&init_cmd, sizeof(init_cmd)))
            {
                HandleBlockWriteError(kErrorWritingBlockHeader, "Failed to write init image meta-data block header");
                return false;
            }
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read init image meta-data block header");
        return false;
    }

    return true;
}

GFXRECON_END_NAMESPACE(gfxrecon)
