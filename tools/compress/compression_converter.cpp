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

bool CompressionConverter::ProcessFunctionCall(decode::ParsedBlock& parsed_block)
{
    // Decompress reports its own errors.
    bool success = parsed_block.Decompress(GetBlockParser());

    if (success)
    {
        const auto& args = parsed_block.Get<decode::FunctionCallArgs>(); // Asserts if !Holds.
        success          = WriteFunctionCall(args.call_id, args.call_info.thread_id, args.data_size, args.data);
    }

    return success;
}

bool CompressionConverter::ProcessMethodCall(decode::ParsedBlock& parsed_block)
{
    // Decompress reports its own errors.
    bool success = parsed_block.Decompress(GetBlockParser());

    if (success)
    {
        const auto& args = parsed_block.Get<decode::MethodCallArgs>(); // Asserts if !Holds.
        success = WriteMethodCall(args.call_id, args.object_id, args.call_info.thread_id, args.data_size, args.data);
    }

    return success;
}

bool CompressionConverter::ProcessMetaData(decode::ParsedBlock& parsed_block)
{
    // We can infer format::IsBlockCompressed from NeedsDecompression as long
    // as the DecompressionPolicy is "never".
    auto& block_parser = GetBlockParser();
    GFXRECON_ASSERT(block_parser.GetDecompressionPolicy() == decode::BlockParser::kNever);
    const bool compressed_block = parsed_block.NeedsDecompression();

    // Unconditional decompress the metadata block wastes no time as all compressible meta_data_id have non-trivial
    // overrides, and decompress fast returns on uncompressed blocks.
    bool success = parsed_block.Decompress(block_parser);
    if (success)
    {
        auto        visit_meta = [this](auto&& store) { return WriteMetaData(*store); };
        VisitResult result     = std::visit(visit_meta, parsed_block.GetArgs());

        if (result == kNeedsPassthrough)
        {
            if (!compressed_block)
            {
                success = FileTransformer::ProcessMetaData(parsed_block);
            }
            else
            {
                // Since this file transformer is converting compression formats, it cannot passthrough
                // NOTE: This condition should not occur, as all compressible meta_data_id *should* have non-trivial
                // overrides, indicating that the BlockParser recognized the block, but that the CompressionConverter
                // does not.
                GFXRECON_ASSERT(!compressed_block);
                HandleBlockWriteError(decode::kErrorUnsupportedBlockType,
                                      "Failed to process unrecognized compressed meta data block type.");
                success = false;
            }
        }
        else
        {
            success = result == kSuccess;
        }
    }
    return success;
}

bool CompressionConverter::WriteFunctionCall(format::ApiCallId call_id,
                                             format::ThreadId  thread_id,
                                             size_t            buffer_size,
                                             const uint8_t*    buffer)
{
    bool write_uncompressed = decompressing_;

    if (!write_uncompressed)
    {
        GFXRECON_ASSERT(target_compressor_ != nullptr);

        // Compress the buffer with the new compression format and write to the new file.
        auto&  compressed_buffer = GetCompressedParameterBuffer();
        size_t packet_size       = 0;
        size_t compressed_size   = target_compressor_->Compress(buffer_size, buffer, &compressed_buffer, 0);

        // Note: we not only have to compress smaller than uncompressed, we have to include the compression overhead.
        if ((0 < compressed_size) &&
            ((compressed_size + sizeof(format::CompressedFunctionCallHeader::uncompressed_size)) < buffer_size))
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
                HandleBlockWriteError(decode::kErrorWritingCompressedBlockHeader,
                                      "Failed to write compressed function call block header");
                return false;
            }

            if (!WriteBytes(compressed_buffer.data(), compressed_size))
            {
                HandleBlockWriteError(decode::kErrorWritingCompressedBlockData,
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
            HandleBlockWriteError(decode::kErrorWritingBlockHeader, "Failed to write function call block header");
            return false;
        }

        if (!WriteBytes(buffer, buffer_size))
        {
            HandleBlockWriteError(decode::kErrorWritingBlockData, "Failed to write function call block data");
            return false;
        }
    }

    return true;
}

bool CompressionConverter::WriteMethodCall(format::ApiCallId call_id,
                                           format::HandleId  object_id,
                                           format::ThreadId  thread_id,
                                           size_t            buffer_size,
                                           const uint8_t*    buffer)
{
    bool write_uncompressed = decompressing_;

    if (!write_uncompressed)
    {
        GFXRECON_ASSERT(target_compressor_ != nullptr);

        // Compress the buffer with the new compression format and write to the new file.
        auto&  compressed_buffer = GetCompressedParameterBuffer();
        size_t packet_size       = 0;
        size_t compressed_size   = target_compressor_->Compress(buffer_size, buffer, &compressed_buffer, 0);

        // Note: we not only have to compress smaller than uncompressed, we have to include the compression overhead.
        if ((0 < compressed_size) &&
            ((compressed_size + sizeof(format::CompressedMethodCallHeader::uncompressed_size)) < buffer_size))
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
                HandleBlockWriteError(decode::kErrorWritingCompressedBlockHeader,
                                      "Failed to write compressed method call block header");
                return false;
            }

            if (!WriteBytes(compressed_buffer.data(), compressed_size))
            {
                HandleBlockWriteError(decode::kErrorWritingCompressedBlockData,
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
            HandleBlockWriteError(decode::kErrorWritingBlockHeader, "Failed to write method call block header");
            return false;
        }

        if (!WriteBytes(buffer, buffer_size))
        {
            HandleBlockWriteError(decode::kErrorWritingBlockData, "Failed to write method call block data");
            return false;
        }
    }

    return true;
}

decode::FileTransformer::VisitResult CompressionConverter::WriteMetaData(const decode::FillMemoryArgs& args)
{
    GFXRECON_ASSERT(format::GetMetaDataType(args.meta_data_id) == format::MetaDataType::kFillMemoryCommand);

    format::FillMemoryCommandHeader fill_cmd;

    fill_cmd.thread_id     = args.thread_id;
    fill_cmd.memory_id     = args.memory_id;
    fill_cmd.memory_offset = args.offset;
    fill_cmd.memory_size   = args.data_size;

    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, args.data_size);
    size_t         data_size    = static_cast<size_t>(args.data_size);
    const uint8_t* data_address = args.data;

    PrepMetadataBlock(fill_cmd.meta_header, args.meta_data_id, data_address, data_size);

    // Calculate size of packet with compressed or uncompressed data size.
    fill_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(fill_cmd) + data_size;

    if (!WriteBytes(&fill_cmd, sizeof(fill_cmd)))
    {
        HandleBlockWriteError(decode::kErrorWritingBlockHeader, "Failed to write fill memory meta-data block header");
        return kError;
    }

    if (!WriteBytes(data_address, data_size))
    {
        HandleBlockWriteError(decode::kErrorWritingBlockData, "Failed to write fill memory meta-data block");
        return kError;
    }

    return kSuccess;
}

decode::FileTransformer::VisitResult CompressionConverter::WriteMetaData(const decode::InitBufferArgs& args)
{
    GFXRECON_ASSERT(format::GetMetaDataType(args.meta_data_id) == format::MetaDataType::kInitBufferCommand);

    format::InitBufferCommandHeader init_cmd;

    init_cmd.thread_id = args.thread_id;
    init_cmd.device_id = args.device_id;
    init_cmd.buffer_id = args.buffer_id;
    init_cmd.data_size = args.data_size;

    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, init_cmd.data_size);
    size_t         data_size    = static_cast<size_t>(init_cmd.data_size);
    const uint8_t* data_address = args.data;

    PrepMetadataBlock(init_cmd.meta_header, args.meta_data_id, data_address, data_size);

    // Calculate size of packet with compressed or uncompressed data size.
    init_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(init_cmd) + data_size;

    if (!WriteBytes(&init_cmd, sizeof(init_cmd)))
    {
        HandleBlockWriteError(decode::kErrorWritingBlockHeader, "Failed to write init buffer meta-data block header");
        return kError;
    }

    if (!WriteBytes(data_address, data_size))
    {
        HandleBlockWriteError(decode::kErrorWritingBlockData, "Failed to write init buffer meta-data block");
        return kError;
    }

    return kSuccess;
}

decode::FileTransformer::VisitResult CompressionConverter::WriteMetaData(const decode::InitImageArgs& args)
{
    GFXRECON_ASSERT(format::GetMetaDataType(args.meta_data_id) == format::MetaDataType::kInitImageCommand);

    format::InitImageCommandHeader init_cmd;
    std::vector<uint64_t>          level_sizes;
    size_t                         levels_size = 0;

    init_cmd.thread_id   = args.thread_id;
    init_cmd.device_id   = args.device_id;
    init_cmd.image_id    = args.image_id;
    init_cmd.data_size   = args.data_size;
    init_cmd.aspect      = args.aspect;
    init_cmd.layout      = args.layout;
    init_cmd.level_count = args.level_sizes.size();

    if (init_cmd.level_count > 0)
    {
        level_sizes = args.level_sizes;
        levels_size = init_cmd.level_count * sizeof(level_sizes[0]);
    }

    // Packet size without the resource data.
    init_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(init_cmd);
    init_cmd.meta_header.block_header.type = format::kMetaDataBlock;
    init_cmd.meta_header.meta_data_id      = args.meta_data_id;

    if (init_cmd.data_size > 0)
    {
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, init_cmd.data_size);
        size_t         data_size    = static_cast<size_t>(init_cmd.data_size);
        const uint8_t* data_address = args.data;

        PrepMetadataBlock(init_cmd.meta_header, args.meta_data_id, data_address, data_size);

        // Calculate size of packet with compressed or uncompressed data size.
        init_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(init_cmd) + levels_size + data_size;

        if (!WriteBytes(&init_cmd, sizeof(init_cmd)))
        {
            HandleBlockWriteError(decode::kErrorWritingBlockHeader,
                                  "Failed to write init image meta-data block header");
            return kError;
        }

        if (!WriteBytes(level_sizes.data(), levels_size))
        {
            HandleBlockWriteError(decode::kErrorWritingBlockHeader, "Failed to write init image meta-data block");
            return kError;
        }

        if (!WriteBytes(data_address, data_size))
        {
            HandleBlockWriteError(decode::kErrorWritingBlockData, "Failed to write init image meta-data block");
            return kError;
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
            HandleBlockWriteError(decode::kErrorWritingBlockHeader,
                                  "Failed to write init image meta-data block header");
            return kError;
        }
    }

    return kSuccess;
}

decode::FileTransformer::VisitResult CompressionConverter::WriteMetaData(const decode::InitSubresourceArgs& args)
{
    GFXRECON_ASSERT(format::GetMetaDataType(args.meta_data_id) == format::MetaDataType::kInitSubresourceCommand);

    // The header needs to be a copy as we are rewriting it below
    format::InitSubresourceCommandHeader init_cmd = args.command_header;

    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, init_cmd.data_size);
    size_t         data_size    = static_cast<size_t>(init_cmd.data_size);
    const uint8_t* data_address = args.data;

    PrepMetadataBlock(init_cmd.meta_header, args.meta_data_id, data_address, data_size);

    // Calculate size of packet with compressed or uncompressed data size.
    init_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(init_cmd) + data_size;

    if (!WriteBytes(&init_cmd, sizeof(init_cmd)))
    {
        HandleBlockWriteError(decode::kErrorWritingBlockHeader,
                              "Failed to write init subresource meta-data block header");
        return kError;
    }

    if (!WriteBytes(data_address, data_size))
    {
        HandleBlockWriteError(decode::kErrorWritingBlockData, "Failed to write init subresource meta-data block");
        return kError;
    }

    return kSuccess;
}

decode::FileTransformer::VisitResult
CompressionConverter::WriteMetaData(const decode::InitDx12AccelerationStructureArgs& args)
{
    GFXRECON_ASSERT(format::GetMetaDataType(args.meta_data_id) ==
                    format::MetaDataType::kInitDx12AccelerationStructureCommand);

    // The header needs to be a copy as we are rewriting it below
    format::InitDx12AccelerationStructureCommandHeader                    init_cmd   = args.command_header;
    const std::vector<format::InitDx12AccelerationStructureGeometryDesc>& geom_descs = args.geometry_descs;
    GFXRECON_ASSERT(args.geometry_descs.size() == init_cmd.inputs_num_geometry_descs);

    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, init_cmd.data_size);
    size_t         data_size    = static_cast<size_t>(init_cmd.data_size);
    const uint8_t* data_address = args.data;

    PrepMetadataBlock(init_cmd.meta_header, args.meta_data_id, data_address, data_size);

    // Calculate size of packet with compressed or uncompressed data size.
    init_cmd.meta_header.block_header.size =
        format::GetMetaDataBlockBaseSize(init_cmd) + data_size +
        (sizeof(format::InitDx12AccelerationStructureGeometryDesc) * init_cmd.inputs_num_geometry_descs);

    if (!WriteBytes(&init_cmd, sizeof(init_cmd)))
    {
        HandleBlockWriteError(decode::kErrorWritingBlockHeader,
                              "Failed to write init DX12 acceleration structure meta-data block header");
        return kError;
    }
    if (!WriteBytes(geom_descs.data(), sizeof(format::InitDx12AccelerationStructureGeometryDesc) * geom_descs.size()))
    {
        HandleBlockWriteError(decode::kErrorWritingBlockHeader,
                              "Failed to write init DX12 acceleration structure geometry block");
        return kError;
    }
    if (!WriteBytes(data_address, data_size))
    {
        HandleBlockWriteError(decode::kErrorWritingBlockData,
                              "Failed to write init DX12 acceleration structure meta-data block");
        return kError;
    }

    return kSuccess;
}

decode::FileTransformer::VisitResult
CompressionConverter::WriteMetaData(const decode::FillMemoryResourceValueArgs& args)
{
    // The header needs to be a copy as we are rewriting it below
    format::FillMemoryResourceValueCommandHeader rv_cmd = args.command_header;
    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, args.data_size);
    size_t         data_size    = static_cast<size_t>(args.data_size);
    const uint8_t* data_address = args.data;

    PrepMetadataBlock(rv_cmd.meta_header, args.meta_data_id, data_address, data_size);

    // Calculate size of packet with compressed or uncompressed data size.
    rv_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(rv_cmd) + data_size;

    if (!WriteBytes(&rv_cmd, sizeof(rv_cmd)))
    {
        HandleBlockWriteError(decode::kErrorWritingBlockHeader, "Failed to write fill memory meta-data block header");
        return kError;
    }

    if (!WriteBytes(data_address, data_size))
    {
        HandleBlockWriteError(decode::kErrorWritingBlockData,
                              "Failed to read fill memory resource value meta-data block");
        return kError;
    }

    return kSuccess;
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
        GFXRECON_ASSERT(target_compressor_ != nullptr);

        auto&  compressed_buffer = GetCompressedParameterBuffer();
        size_t compressed_size   = target_compressor_->Compress(data_size, data_address, &compressed_buffer, 0);

        // Note: With MetaDataBlocks the uncompressed size is encoded (or computable from) other fields in the
        //       block, s.t. there is no data size overhead for using compressed_data
        if ((compressed_size > 0) && (compressed_size < data_size))
        {
            meta_data_header.block_header.type = format::BlockType::kCompressedMetaDataBlock;

            data_address = compressed_buffer.data();
            data_size    = compressed_size;
        }
    }
}

GFXRECON_END_NAMESPACE(gfxrecon)
