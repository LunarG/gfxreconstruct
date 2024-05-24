/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
** Copyright (c) 2022 Advanced Micro Devices, Inc. All rights reserved.
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
        success                  = FileTransformer::Initialize(input_filename, output_filename, "compress");
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

bool CompressionConverter::ProcessMethodCall(const format::BlockHeader& block_header,
                                             format::ApiCallId          call_id,
                                             uint64_t                   block_index /*= 0*/)
{
    size_t           parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(call_id);
    uint64_t         uncompressed_size     = 0;
    format::HandleId object_id             = 0;
    format::ThreadId thread_id             = 0;

    bool success = ReadBytes(&object_id, sizeof(object_id));
    success      = success && ReadBytes(&thread_id, sizeof(thread_id));

    if (success)
    {
        parameter_buffer_size -= (sizeof(object_id) + sizeof(thread_id));

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
                                         "Failed to read compressed method call block data");
                }
            }
            else
            {
                HandleBlockReadError(kErrorReadingCompressedBlockHeader,
                                     "Failed to read compressed method call block header");
            }
        }
        else
        {
            success = ReadParameterBuffer(parameter_buffer_size);

            if (!success)
            {
                HandleBlockReadError(kErrorReadingBlockData, "Failed to read method call block data");
            }
        }

        if (success)
        {
            success = WriteMethodCall(call_id, object_id, thread_id, parameter_buffer_size);
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read method call block header");
    }

    return success;
}

bool CompressionConverter::ProcessMetaData(const format::BlockHeader& block_header, format::MetaDataId meta_data_id)
{
    // Only the meta data blocks that contain resource data support compression.  The rest of the meta data block types
    // can be copied directly to the new file.
    format::MetaDataType meta_data_type = format::GetMetaDataType(meta_data_id);
    if (meta_data_type == format::MetaDataType::kFillMemoryCommand)
    {
        return WriteFillMemoryMetaData(block_header, meta_data_id);
    }
    else if (meta_data_type == format::MetaDataType::kInitBufferCommand)
    {
        return WriteInitBufferMetaData(block_header, meta_data_id);
    }
    else if (meta_data_type == format::MetaDataType::kInitImageCommand)
    {
        return WriteInitImageMetaData(block_header, meta_data_id);
    }
    else if (meta_data_type == format::MetaDataType::kInitSubresourceCommand)
    {
        return WriteInitSubresourceMetaData(block_header, meta_data_id);
    }
    else if (meta_data_type == format::MetaDataType::kInitDx12AccelerationStructureCommand)
    {
        return WriteInitDx12AccelerationStructureMetaData(block_header, meta_data_id);
    }
    else if (meta_data_type == format::MetaDataType::kFillMemoryResourceValueCommand)
    {
        return WriteFillMemoryResourceValueMetaData(block_header, meta_data_id);
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

        return FileTransformer::ProcessMetaData(block_header, meta_data_id);
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
        size_t compressed_size   = target_compressor_->Compress(buffer_size, buffer.data(), &compressed_buffer, 0);

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

bool CompressionConverter::WriteMethodCall(format::ApiCallId call_id,
                                           format::HandleId  object_id,
                                           format::ThreadId  thread_id,
                                           size_t            buffer_size)
{
    bool        write_uncompressed = decompressing_;
    const auto& buffer             = GetParameterBuffer();

    if (!write_uncompressed)
    {
        GFXRECON_ASSERT(target_compressor_ != nullptr);

        // Compress the buffer with the new compression format and write to the new file.
        auto&  compressed_buffer = GetCompressedParameterBuffer();
        size_t packet_size       = 0;
        size_t compressed_size   = target_compressor_->Compress(buffer_size, buffer.data(), &compressed_buffer, 0);

        if (0 < compressed_size && compressed_size < buffer_size)
        {
            format::CompressedMethodCallHeader compressed_method_call_header = {};
            compressed_method_call_header.block_header.type = format::BlockType::kCompressedMethodCallBlock;
            compressed_method_call_header.api_call_id       = call_id;
            compressed_method_call_header.object_id         = object_id;
            compressed_method_call_header.thread_id         = thread_id;
            compressed_method_call_header.uncompressed_size = buffer_size;

            packet_size += sizeof(compressed_method_call_header.api_call_id) +
                           sizeof(compressed_method_call_header.object_id) +
                           sizeof(compressed_method_call_header.thread_id) +
                           sizeof(compressed_method_call_header.uncompressed_size) + compressed_size;

            compressed_method_call_header.block_header.size = packet_size;

            if (!WriteBytes(&compressed_method_call_header, sizeof(compressed_method_call_header)))
            {
                HandleBlockWriteError(kErrorWritingCompressedBlockHeader,
                                      "Failed to write compressed method call block header");
                return false;
            }

            if (!WriteBytes(compressed_buffer.data(), compressed_size))
            {
                HandleBlockWriteError(kErrorWritingCompressedBlockData,
                                      "Failed to write compressed method call block data");
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
        format::MethodCallHeader method_call_header = {};
        size_t                   packet_size        = 0;

        method_call_header.block_header.type = format::BlockType::kMethodCallBlock;
        method_call_header.api_call_id       = call_id;
        method_call_header.object_id         = object_id;
        method_call_header.thread_id         = thread_id;

        packet_size += sizeof(method_call_header.api_call_id) + sizeof(method_call_header.object_id) +
                       sizeof(method_call_header.thread_id) + buffer_size;

        method_call_header.block_header.size = packet_size;

        if (!WriteBytes(&method_call_header, sizeof(method_call_header)))
        {
            HandleBlockWriteError(kErrorWritingBlockHeader, "Failed to write method call block header");
            return false;
        }

        if (!WriteBytes(buffer.data(), buffer_size))
        {
            HandleBlockWriteError(kErrorWritingBlockData, "Failed to write method call block data");
            return false;
        }
    }

    return true;
}

bool CompressionConverter::WriteFillMemoryMetaData(const format::BlockHeader& block_header,
                                                   format::MetaDataId         meta_data_id)
{
    assert(format::GetMetaDataType(meta_data_id) == format::MetaDataType::kFillMemoryCommand);

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

        PrepMetadataBlock(fill_cmd.meta_header, meta_data_id, data_address, data_size);

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
                                                   format::MetaDataId         meta_data_id)
{
    assert(format::GetMetaDataType(meta_data_id) == format::MetaDataType::kInitBufferCommand);

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

        PrepMetadataBlock(init_cmd.meta_header, meta_data_id, data_address, data_size);

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
                                                  format::MetaDataId         meta_data_id)
{
    assert(format::GetMetaDataType(meta_data_id) == format::MetaDataType::kInitImageCommand);

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
        init_cmd.meta_header.meta_data_id      = meta_data_id;

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

            PrepMetadataBlock(init_cmd.meta_header, meta_data_id, data_address, data_size);

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

bool CompressionConverter::WriteInitSubresourceMetaData(const format::BlockHeader& block_header,
                                                        format::MetaDataId         meta_data_id)
{
    assert(format::GetMetaDataType(meta_data_id) == format::MetaDataType::kInitSubresourceCommand);

    format::InitSubresourceCommandHeader init_cmd;

    bool success = ReadBytes(&init_cmd.thread_id, sizeof(init_cmd.thread_id));
    success      = success && ReadBytes(&init_cmd.device_id, sizeof(init_cmd.device_id));
    success      = success && ReadBytes(&init_cmd.resource_id, sizeof(init_cmd.resource_id));
    success      = success && ReadBytes(&init_cmd.subresource, sizeof(init_cmd.subresource));
    success      = success && ReadBytes(&init_cmd.initial_state, sizeof(init_cmd.initial_state));
    success      = success && ReadBytes(&init_cmd.resource_state, sizeof(init_cmd.resource_state));
    success      = success && ReadBytes(&init_cmd.barrier_flags, sizeof(init_cmd.barrier_flags));
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
                HandleBlockReadError(kErrorReadingCompressedBlockData,
                                     "Failed to read init subresource meta-data block");
                return false;
            }

            assert(uncompressed_size == data_size);
        }
        else
        {
            if (!ReadParameterBuffer(data_size))
            {
                HandleBlockReadError(kErrorReadingBlockData, "Failed to read init subresource meta-data block");
                return false;
            }
        }

        const auto&    buffer       = GetParameterBuffer();
        const uint8_t* data_address = buffer.data();

        PrepMetadataBlock(init_cmd.meta_header, meta_data_id, data_address, data_size);

        // Calculate size of packet with compressed or uncompressed data size.
        init_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(init_cmd) + data_size;

        if (!WriteBytes(&init_cmd, sizeof(init_cmd)))
        {
            HandleBlockWriteError(kErrorWritingBlockHeader, "Failed to write init subresource meta-data block header");
            return false;
        }

        if (!WriteBytes(data_address, data_size))
        {
            HandleBlockWriteError(kErrorWritingBlockData, "Failed to write init subresource meta-data block");
            return false;
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read init subresource meta-data block header");
        return false;
    }

    return true;
}

bool CompressionConverter::WriteInitDx12AccelerationStructureMetaData(const format::BlockHeader& block_header,
                                                                      format::MetaDataId         meta_data_id)
{
    assert(format::GetMetaDataType(meta_data_id) == format::MetaDataType::kInitDx12AccelerationStructureCommand);

    format::InitDx12AccelerationStructureCommandHeader init_cmd;
    bool success = ReadBytes(&init_cmd.thread_id, sizeof(init_cmd.thread_id));
    success      = success &&
              ReadBytes(&init_cmd.dest_acceleration_structure_data, sizeof(init_cmd.dest_acceleration_structure_data));
    success = success && ReadBytes(&init_cmd.copy_source_gpu_va, sizeof(init_cmd.copy_source_gpu_va));
    success = success && ReadBytes(&init_cmd.copy_mode, sizeof(init_cmd.copy_mode));
    success = success && ReadBytes(&init_cmd.inputs_type, sizeof(init_cmd.inputs_type));
    success = success && ReadBytes(&init_cmd.inputs_flags, sizeof(init_cmd.inputs_flags));
    success = success && ReadBytes(&init_cmd.inputs_num_instance_descs, sizeof(init_cmd.inputs_num_instance_descs));
    success = success && ReadBytes(&init_cmd.inputs_num_geometry_descs, sizeof(init_cmd.inputs_num_geometry_descs));
    success = success && ReadBytes(&init_cmd.inputs_data_size, sizeof(init_cmd.inputs_data_size));

    // Parse geometry descs.

    std::vector<format::InitDx12AccelerationStructureGeometryDesc> geom_descs;
    if (success)
    {
        for (uint32_t i = 0; i < init_cmd.inputs_num_geometry_descs; ++i)
        {
            format::InitDx12AccelerationStructureGeometryDesc geom_desc;
            success = success && ReadBytes(&geom_desc.geometry_type, sizeof(geom_desc.geometry_type));
            success = success && ReadBytes(&geom_desc.geometry_flags, sizeof(geom_desc.geometry_flags));
            success = success && ReadBytes(&geom_desc.aabbs_count, sizeof(geom_desc.aabbs_count));
            success = success && ReadBytes(&geom_desc.aabbs_stride, sizeof(geom_desc.aabbs_stride));
            success =
                success && ReadBytes(&geom_desc.triangles_has_transform, sizeof(geom_desc.triangles_has_transform));
            success = success && ReadBytes(&geom_desc.triangles_index_format, sizeof(geom_desc.triangles_index_format));
            success =
                success && ReadBytes(&geom_desc.triangles_vertex_format, sizeof(geom_desc.triangles_vertex_format));
            success = success && ReadBytes(&geom_desc.triangles_index_count, sizeof(geom_desc.triangles_index_count));
            success = success && ReadBytes(&geom_desc.triangles_vertex_count, sizeof(geom_desc.triangles_vertex_count));
            success =
                success && ReadBytes(&geom_desc.triangles_vertex_stride, sizeof(geom_desc.triangles_vertex_stride));
            geom_descs.push_back(geom_desc);
        }
    }

    if (success)
    {
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, init_cmd.inputs_data_size);

        size_t data_size = static_cast<size_t>(init_cmd.inputs_data_size);

        if (format::IsBlockCompressed(block_header.type))
        {
            size_t uncompressed_size = 0;
            size_t compressed_size =
                static_cast<size_t>(block_header.size) -
                (sizeof(init_cmd) - sizeof(init_cmd.meta_header.block_header)) -
                (sizeof(format::InitDx12AccelerationStructureGeometryDesc) * init_cmd.inputs_num_geometry_descs);

            if (!ReadCompressedParameterBuffer(compressed_size, data_size, &uncompressed_size))
            {
                HandleBlockReadError(kErrorReadingCompressedBlockData,
                                     "Failed to read init DX12 acceleration structure meta-data block");
                return false;
            }

            assert(uncompressed_size == data_size);
        }
        else
        {
            if (!ReadParameterBuffer(data_size))
            {
                HandleBlockReadError(kErrorReadingBlockData,
                                     "Failed to read init DX12 acceleration structure meta-data block");
                return false;
            }
        }

        const auto&    buffer       = GetParameterBuffer();
        const uint8_t* data_address = buffer.data();

        PrepMetadataBlock(init_cmd.meta_header, meta_data_id, data_address, data_size);

        // Calculate size of packet with compressed or uncompressed data size.
        init_cmd.meta_header.block_header.size =
            format::GetMetaDataBlockBaseSize(init_cmd) + data_size +
            (sizeof(format::InitDx12AccelerationStructureGeometryDesc) * init_cmd.inputs_num_geometry_descs);

        if (!WriteBytes(&init_cmd, sizeof(init_cmd)))
        {
            HandleBlockWriteError(kErrorWritingBlockHeader,
                                  "Failed to write init DX12 acceleration structure meta-data block header");
            return false;
        }
        if (!WriteBytes(geom_descs.data(),
                        sizeof(format::InitDx12AccelerationStructureGeometryDesc) * geom_descs.size()))
        {
            HandleBlockWriteError(kErrorWritingBlockHeader,
                                  "Failed to write init DX12 acceleration structure geometry block");
            return false;
        }
        if (!WriteBytes(data_address, data_size))
        {
            HandleBlockWriteError(kErrorWritingBlockData,
                                  "Failed to write init DX12 acceleration structure meta-data block");
            return false;
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader,
                             "Failed to read init DX12 acceleration structure meta-data block header");
    }

    return true;
}

bool CompressionConverter::WriteFillMemoryResourceValueMetaData(const format::BlockHeader& block_header,
                                                                format::MetaDataId         meta_data_id)
{
    format::FillMemoryResourceValueCommandHeader rv_cmd;
    bool                                         success = ReadBytes(&rv_cmd.thread_id, sizeof(rv_cmd.thread_id));

    success = success && ReadBytes(&rv_cmd.resource_value_count, sizeof(rv_cmd.resource_value_count));

    if (success)
    {
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, rv_cmd.resource_value_count);
        size_t data_size =
            static_cast<size_t>(rv_cmd.resource_value_count * (sizeof(format::ResourceValueType) + sizeof(uint64_t)));

        if (format::IsBlockCompressed(block_header.type))
        {
            size_t uncompressed_size = 0;
            size_t compressed_size = static_cast<size_t>(block_header.size - format::GetMetaDataBlockBaseSize(rv_cmd));

            if (!ReadCompressedParameterBuffer(compressed_size, data_size, &uncompressed_size))
            {
                HandleBlockReadError(kErrorReadingCompressedBlockData,
                                     "Failed to read fill memory resource value meta-data block");
                return false;
            }

            assert(uncompressed_size == data_size);
        }
        else
        {
            if (!ReadParameterBuffer(data_size))
            {
                HandleBlockReadError(kErrorReadingBlockData,
                                     "Failed to read fill memory resource value meta-data block");
                return false;
            }
        }

        const auto&    buffer       = GetParameterBuffer();
        const uint8_t* data_address = buffer.data();

        PrepMetadataBlock(rv_cmd.meta_header, meta_data_id, data_address, data_size);

        // Calculate size of packet with compressed or uncompressed data size.
        rv_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(rv_cmd) + data_size;

        if (!WriteBytes(&rv_cmd, sizeof(rv_cmd)))
        {
            HandleBlockWriteError(kErrorWritingBlockHeader, "Failed to write fill memory meta-data block header");
            return false;
        }

        if (!WriteBytes(data_address, data_size))
        {
            HandleBlockWriteError(kErrorWritingBlockData, "Failed to read fill memory resource value meta-data block");
            return false;
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to write fill memory resource value meta-data block");
        return false;
    }

    return true;
}

void CompressionConverter::PrepMetadataBlock(format::MetaDataHeader& meta_data_header,
                                             format::MetaDataId      meta_data_id,
                                             const uint8_t*&         data_address,
                                             size_t&                 data_size)
{
    meta_data_header.block_header.type = format::kMetaDataBlock;
    meta_data_header.meta_data_id      = meta_data_id;

    if (!decompressing_)
    {
        assert(target_compressor_ != nullptr);

        auto&  compressed_buffer = GetCompressedParameterBuffer();
        size_t compressed_size   = target_compressor_->Compress(data_size, data_address, &compressed_buffer, 0);

        if ((compressed_size > 0) && (compressed_size < data_size))
        {
            meta_data_header.block_header.type = format::BlockType::kCompressedMetaDataBlock;

            data_address = compressed_buffer.data();
            data_size    = compressed_size;
        }
    }
}

GFXRECON_END_NAMESPACE(gfxrecon)
