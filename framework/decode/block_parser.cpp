/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018-2025 LunarG, Inc.
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

#include "decode/block_parser.h"
#include "format/format_util.h"

#include <cstring>
#include <numeric>
#include <sstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Parse the block header and load the whole block into a block buffer
BlockIOError BlockParser::ReadBlockBuffer(FileInputStreamPtr& input_stream, BlockBuffer& block_buffer)
{
    using BlockSizeType = decltype(format::BlockHeader::size);
    BlockSizeType block_size;
    BlockIOError  status = kErrorNone;

    const size_t peeked_bytes = input_stream->PeekBytes(&block_size, sizeof(block_size));
    if (peeked_bytes == 0)
    {
        // We're at EOF without a single byte to read
        status = input_stream->IsError() ? kErrorReadingBlockHeader : kEndOfFile;
    }
    else if (peeked_bytes < sizeof(block_size))
    {
        // The file ended, but doesn't contain even a full header's information
        status = kErrorReadingBlockHeader;
    }

    if (status == kErrorNone)
    {
        // NOTE: If BlockSkippingFileProcessor performance is significantly harmed we could defer the data span read
        // here For 32bit size_t is << BlockSizeType ... but expecting support for > 4GB blocks on 32 bit platforms
        // isn't reasonable
        constexpr size_t        size_t_max        = std::numeric_limits<size_t>::max();
        constexpr BlockSizeType block_size_max    = std::numeric_limits<BlockSizeType>::max();
        constexpr bool          small_size        = size_t_max < std::numeric_limits<BlockSizeType>::max();
        constexpr size_t        block_header_size = sizeof(format::BlockHeader);

        GFXRECON_ASSERT(block_size <= (block_size_max - BlockSizeType(block_header_size)));
        const BlockSizeType total_block_size = block_size + sizeof(format::BlockHeader);
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, total_block_size);

        if constexpr (small_size)
        {
            if (total_block_size > size_t_max)
            {
                // This is a fatal error (caller will catch). SkipBytes takes size_t and fseek takes *long*,
                // which means we can't even skip this block on all 32 bit systems
                status = kErrorReadingBlockData;
            }
        }
        if (status == kErrorNone)
        {
            // Note this leave the BlockBuffer read position at the first byte following the header.
            bool success =
                input_stream->ReadOverwriteSpan(static_cast<size_t>(total_block_size), block_buffer.GetBlockStore());
            if (success)
            {
                block_buffer.InitBlockHeaderFromSpan();
            }
            else
            {
                status = kErrorReadingBlockData;
            }
        }
    }

    if (status != kErrorNone)
    {
        block_buffer.Reset();
    }

    return status;
}

void BlockParser::HandleBlockReadError(BlockIOError error_code, const char* error_message)
{
    GFXRECON_ASSERT(err_handler_);
    err_handler_(error_code, error_message);
}

bool BlockParser::ShouldDeferDecompression(size_t block_size)
{
    // NOTE: Using multiple ifs for clarity
    if (decompression_policy_ == kAlways)
    {
        return false;
    }
    else if (decompression_policy_ == kNever)
    {
        return true;
    }

    GFXRECON_ASSERT(decompression_policy_ == kQueueOptimized);
    return block_size > kDeferThreshold;
}

ParsedBlock::UncompressedStore BlockParser::DecompressSpan(const BlockBuffer::BlockSpan& compressed_span,
                                                           size_t                        expanded_size)
{
    GFXRECON_ASSERT(!compressed_span.empty());
    auto   uncompressed_buffer = pool_->Acquire(expanded_size);
    size_t uncompressed_size   = compressor_->Decompress(compressed_span.size(),
                                                       reinterpret_cast<const uint8_t*>(compressed_span.data()),
                                                       expanded_size,
                                                       uncompressed_buffer.GetAs<uint8_t>());
    if (uncompressed_size == expanded_size)
    {
        return uncompressed_buffer;
    }
    else
    {
        HandleBlockReadError(kErrorReadingCompressedBlockData, "Failed to decompress block data");
        return ParsedBlock::UncompressedStore();
    }
}

void BlockParser::WarnUnknownBlock(const BlockBuffer& block_buffer, const char* sub_type_label, uint32_t sub_type)
{
    const format::BlockHeader& block_header = block_buffer.Header();
    const format::BlockType    block_type   = block_header.type;

    const uint32_t type       = static_cast<uint32_t>(block_type);
    const char*    compressed = format::IsBlockCompressed(block_type) ? "compressed" : "uncompressed";

    std::stringstream message;
    if (nullptr != sub_type_label)
    {
        message << "Skipping unrecognized " << compressed << " " << sub_type_label << " with type " << sub_type;
    }
    else
    {
        message << "Skipping unrecognized %s file block with type " << block_type;
    }

    GFXRECON_LOG_WARNING(
        "%s (frame %" PRIu64 " block %" PRIu32 ")", message.str().c_str(), frame_number_, block_index_);
}

// Create a block that is compressible with correct handling of both compression state and decompression policy
template <typename ArgPayload>
[[nodiscard]] ParsedBlock BlockParser::MakeCompressibleParsedBlock(BlockBuffer&                            block_buffer,
                                                                   const BlockParser::ParameterReadResult& read_result,
                                                                   ArgPayload&&                            args)
{
    if (read_result.is_compressed)
    {
        if (ShouldDeferDecompression(block_buffer.GetData().size()))
        {
            return ParsedBlock(ParsedBlock::DeferredDecompressBlockTag{},
                               block_buffer,
                               block_reference_policy_,
                               std::forward<ArgPayload>(args));
        }
        else
        {
            UncompressedStore uncompressed_store = DecompressSpan(read_result.buffer, read_result.uncompressed_size);
            args.data                            = uncompressed_store.template GetAs<const uint8_t>();
            if (uncompressed_store.empty())
            {
                return ParsedBlock(ParsedBlock::InvalidBlockTag());
            }
            return ParsedBlock(ParsedBlock::DecompressedBlockTag{},
                               block_buffer,
                               block_reference_policy_,
                               std::move(uncompressed_store),
                               std::forward<ArgPayload>(args));
        }
    }
    else
    {
        return ParsedBlock(
            ParsedBlock::UncompressedBlockTag{}, block_buffer, block_reference_policy_, std::forward<ArgPayload>(args));
    }
}
// Create a block that is never compressed with correct handling of both compression state and decompression policy
template <typename ArgPayload>
[[nodiscard]] ParsedBlock
BlockParser::MakeIncompressibleParsedBlock(BlockBuffer& block_buffer, ArgPayload&& args, bool references_block_buffer)
{
    return ParsedBlock(ParsedBlock::IncompressibleBlockTag{ block_buffer },
                       block_buffer,
                       block_reference_policy_,
                       references_block_buffer,
                       std::forward<ArgPayload>(args));
}

ParsedBlock BlockParser::ParseBlock(BlockBuffer& block_buffer)
{
    // Note that header parsing has been done by the BlockParser before this call is made.
    GFXRECON_ASSERT(block_buffer.ReadPos() == sizeof(format::BlockHeader));
    const format::BlockHeader& block_header = block_buffer.Header();
    format::BlockType          base_type    = format::RemoveCompressedBlockBit(block_header.type);
    switch (base_type)
    {
        case format::kFunctionCallBlock:
            return ParseFunctionCall(block_buffer);
            break;
        case format::kMethodCallBlock:
            return ParseMethodCall(block_buffer);
            break;
        case format::kMetaDataBlock:
            return ParseMetaData(block_buffer);
            break;
        case format::kFrameMarkerBlock:
            return ParseFrameMarker(block_buffer);
            break;
        case format::kStateMarkerBlock:
            return ParseStateMarker(block_buffer);
            break;
        case format::kAnnotation:
            return ParseAnnotation(block_buffer);
            break;
        case format::kUnknownBlock:
        default:
            WarnUnknownBlock(block_buffer);
            return ParsedBlock{ ParsedBlock::UnknownBlockTag(), block_buffer.ReleaseData() };
            break;
    }
}

// The parameter buffer always takes up the end of the block
// Default value for uncompressed_size is kReadSizeFromBuffer -- which is the behavior of Function and method call
BlockParser::ParameterReadResult
BlockParser::ReadParameterBuffer(const char* label, BlockBuffer& block_buffer, uint64_t uncompressed_size)
{
    ParameterReadResult result; // result.success initializes to true;

    auto error_string = [&result, label](const char* tag) {
        std::stringstream err;
        err << "Failed to read ";
        if (result.is_compressed)
        {
            err << "compressed ";
        }
        err << std::string(label);
        if (tag)
        {
            err << " " << tag;
        }
        return err;
    };

    result.is_compressed = format::IsBlockCompressed(block_buffer.Header().type);
    size_t buffer_size   = 0;
    if (result.is_compressed)
    {
        // The data size is encoded just ahead of the compressed buffer
        if (kReadSizeFromBuffer == uncompressed_size)
        {
            result.success = block_buffer.Read(uncompressed_size);
        }

        // For passed in uncompressed sizes this is always true, but it centralized the conversion loss path
        if (result.success)
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, uncompressed_size);
            result.uncompressed_size = static_cast<size_t>(uncompressed_size);
            buffer_size              = block_buffer.Remainder();
        }
        else
        {
            HandleBlockReadError(kErrorReadingCompressedBlockHeader, error_string("size").str().c_str());
            result.success = false;
        }
    }
    else
    {
        // For uncompressed blocks the data size is the parameter buffer size
        result.uncompressed_size = block_buffer.Remainder();
        buffer_size              = result.uncompressed_size;
    }

    if (result.success)
    {
        // We only try to read the buffer (span), if no previous errors have occurred, and if non-empty.
        if (buffer_size > 0)
        {
            result.buffer  = block_buffer.ReadSpan(buffer_size);
            result.success = result.buffer.size() == buffer_size;

            if (!result.success)
            {
                const BlockIOError error_code =
                    result.is_compressed ? kErrorReadingCompressedBlockData : kErrorReadingBlockData;
                HandleBlockReadError(error_code, error_string("data").str().c_str());
            }
        }
        else
        {
            // Shouldn't ever been a compressed parameter buffer with an empty remainder
            GFXRECON_ASSERT(!result.is_compressed);

            // Simplify compressed block handling, by never treating an empty span as compressed
            result.is_compressed = false;
        }
    }
    return result;
}

ParsedBlock BlockParser::ParseFunctionCall(BlockBuffer& block_buffer)
{
    // The caller is responsible for reading the block and parsing the header
    GFXRECON_ASSERT(block_buffer.ReadPos() == sizeof(format::BlockHeader));
    const format::BlockHeader& block_header = block_buffer.Header();
    format::ApiCallId          api_call_id  = format::ApiCallId::ApiCall_Unknown;

    ApiCallInfo call_info{ GetBlockIndex() };

    bool success = block_buffer.Read(api_call_id);
    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
    success = success && block_buffer.Read(call_info.thread_id);

    if (success)
    {
        const char*         label       = "function call block";
        ParameterReadResult read_result = ReadParameterBuffer(label, block_buffer);

        if (read_result.success)
        {
            return MakeCompressibleParsedBlock(
                block_buffer,
                read_result,
                FunctionCallArgs{ api_call_id,
                                  call_info,
                                  reinterpret_cast<const uint8_t*>(read_result.buffer.data()),
                                  read_result.uncompressed_size });
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read function call block header");
    }

    return ParsedBlock(ParsedBlock::InvalidBlockTag());
}

ParsedBlock BlockParser::ParseMethodCall(BlockBuffer& block_buffer)
{
    // The caller is responsible for reading the block and parsing the header
    GFXRECON_ASSERT(block_buffer.ReadPos() == sizeof(format::BlockHeader));
    const format::BlockHeader& block_header = block_buffer.Header();
    format::ApiCallId          call_id      = format::ApiCallId::ApiCall_Unknown;
    bool                       success      = block_buffer.Read(call_id);

    format::HandleId object_id = 0;
    ApiCallInfo      call_info{ GetBlockIndex() };

    success = success && block_buffer.Read(object_id);
    success = success && block_buffer.Read(call_info.thread_id);

    if (success)
    {
        const char*         label       = "method call block";
        ParameterReadResult read_result = ReadParameterBuffer(label, block_buffer);
        if (read_result.success)
        {
            return MakeCompressibleParsedBlock(
                block_buffer,
                read_result,
                MethodCallArgs{ call_id,
                                object_id,
                                call_info,
                                reinterpret_cast<const uint8_t*>(read_result.buffer.data()),
                                read_result.uncompressed_size });
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read method call block header");
    }

    return ParsedBlock(ParsedBlock::InvalidBlockTag());
}

ParsedBlock BlockParser::ParseMetaData(BlockBuffer& block_buffer)
{
    // The caller is responsible for reading the block and parsing the header
    GFXRECON_ASSERT(block_buffer.ReadPos() == sizeof(format::BlockHeader));
    const format::BlockHeader& block_header = block_buffer.Header();
    format::ApiCallId          call_id      = format::ApiCallId::ApiCall_Unknown;
    format::MetaDataId         meta_data_id;
    bool                       success = block_buffer.Read(meta_data_id);

    if (!success)
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read function call block header");
        return ParsedBlock(ParsedBlock::InvalidBlockTag());
    }

    // Optional backing store for the various uncompressed metadata contents

    format::MetaDataType meta_data_type = format::GetMetaDataType(meta_data_id);

    if (meta_data_type == format::MetaDataType::kFillMemoryCommand)
    {
        format::FillMemoryCommandHeader header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.memory_id);
        success = success && block_buffer.Read(header.memory_offset);
        success = success && block_buffer.Read(header.memory_size);

        if (success)
        {
            const char*         label       = "fill memory meta-data block";
            ParameterReadResult read_result = ReadParameterBuffer(label, block_buffer, header.memory_size);
            if (read_result.success)
            {
                return MakeCompressibleParsedBlock(
                    block_buffer,
                    read_result,
                    FillMemoryArgs{ meta_data_id,
                                    header.thread_id,
                                    header.memory_id,
                                    header.memory_offset,
                                    header.memory_size,
                                    reinterpret_cast<const uint8_t*>(read_result.buffer.data()) });
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

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.resource_value_count);

        if (success)
        {
            // Uncompressed parameter_data size is computed and not encoded.
            uint64_t parameter_data_size =
                header.resource_value_count * (sizeof(format::ResourceValueType) + sizeof(uint64_t));

            const char*         label       = "memory resource value meta-data block";
            ParameterReadResult read_result = ReadParameterBuffer(label, block_buffer, parameter_data_size);

            if (read_result.success)
            {
                return MakeCompressibleParsedBlock(
                    block_buffer,
                    read_result,
                    // Note that both the meta_data_id and the data_size are not passed to the decoder in Dispatch
                    // but needed by the Dispatch and Decompression visitors respectively.
                    FillMemoryResourceValueArgs{ meta_data_id,
                                                 read_result.uncompressed_size,
                                                 header,
                                                 reinterpret_cast<const uint8_t*>(read_result.buffer.data()) });
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
        format::ResizeWindowCommand command;

        success = block_buffer.Read(command.thread_id);
        success = success && block_buffer.Read(command.surface_id);
        success = success && block_buffer.Read(command.width);
        success = success && block_buffer.Read(command.height);

        if (success)
        {
            // This command does not support compression
            return MakeIncompressibleParsedBlock(
                block_buffer,
                ResizeWindowArgs{ meta_data_id, command.thread_id, command.surface_id, command.width, command.height });
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read resize window meta-data block");
        }
    }
    else if (meta_data_type == format::MetaDataType::kResizeWindowCommand2)
    {

        format::ResizeWindowCommand2 command;

        success = block_buffer.Read(command.thread_id);
        success = success && block_buffer.Read(command.surface_id);
        success = success && block_buffer.Read(command.width);
        success = success && block_buffer.Read(command.height);
        success = success && block_buffer.Read(command.pre_transform);

        if (success)
        {
            // This command does not support compression.
            return MakeIncompressibleParsedBlock(block_buffer,
                                                 ResizeWindow2Args{ meta_data_id,
                                                                    command.thread_id,
                                                                    command.surface_id,
                                                                    command.width,
                                                                    command.height,
                                                                    command.pre_transform });
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read resize window 2 meta-data block");
        }
    }
    else if (meta_data_type == format::MetaDataType::kExeFileInfoCommand)
    {
        format::ExeFileInfoBlock header;
        success = block_buffer.Read(header.thread_id);

        success = success && block_buffer.ReadBytes(&header.info_record.ProductVersion,
                                                    gfxrecon::util::filepath::kMaxFilePropertySize);
        success = success && block_buffer.ReadBytes(&header.info_record.FileVersion,
                                                    gfxrecon::util::filepath::kMaxFilePropertySize);
        success = success && block_buffer.ReadBytes(&header.info_record.AppVersion,
                                                    sizeof(uint32_t) * gfxrecon::util::filepath::kFileVersionSize);
        success = success &&
                  block_buffer.ReadBytes(&header.info_record.AppName, gfxrecon::util::filepath::kMaxFilePropertySize);
        success = success && block_buffer.ReadBytes(&header.info_record.CompanyName,
                                                    gfxrecon::util::filepath::kMaxFilePropertySize);
        success = success && block_buffer.ReadBytes(&header.info_record.FileDescription,
                                                    gfxrecon::util::filepath::kMaxFilePropertySize);
        success = success && block_buffer.ReadBytes(&header.info_record.InternalName,
                                                    gfxrecon::util::filepath::kMaxFilePropertySize);
        success = success && block_buffer.ReadBytes(&header.info_record.OriginalFilename,
                                                    gfxrecon::util::filepath::kMaxFilePropertySize);
        success = success && block_buffer.ReadBytes(&header.info_record.ProductName,
                                                    gfxrecon::util::filepath::kMaxFilePropertySize);

        if (success)
        {
            // This command does not support compression.
            return MakeIncompressibleParsedBlock(block_buffer, ExeFileArgs{ meta_data_id, header.thread_id, header });
        }
    }
    else if (meta_data_type == format::MetaDataType::kDriverInfoCommand)
    {
        format::DriverInfoBlock header;
        success = block_buffer.Read(header.thread_id);

        success =
            success && block_buffer.ReadBytes(&header.driver_record, gfxrecon::util::filepath::kMaxDriverInfoSize);

        if (success)
        {
            // This command does not support compression.
            return MakeIncompressibleParsedBlock(block_buffer, DriverArgs{ meta_data_id, header.thread_id, header });
        }
    }
    else if (meta_data_type == format::MetaDataType::kDisplayMessageCommand)
    {
        format::DisplayMessageCommandHeader header;

        success = block_buffer.Read(header.thread_id);

        if (success)
        {
            uint64_t message_size = block_header.size - sizeof(meta_data_id) - sizeof(header.thread_id);

            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, message_size);
            const size_t           data_size      = static_cast<size_t>(message_size);
            BlockBuffer::BlockSpan parameter_data = block_buffer.ReadSpan(data_size);
            success                               = parameter_data.size() == data_size;

            if (success)
            {
                const char* message_start = reinterpret_cast<const char*>(parameter_data.data());
                std::string message(message_start, std::next(message_start, static_cast<size_t>(message_size)));

                // This command does not support compression.
                return MakeIncompressibleParsedBlock(
                    block_buffer, DisplayMessageArgs{ meta_data_id, header.thread_id, std::move(message) });
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

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.memory_id);
        success = success && block_buffer.Read(header.buffer_id);
        success = success && block_buffer.Read(header.format);
        success = success && block_buffer.Read(header.width);
        success = success && block_buffer.Read(header.height);
        success = success && block_buffer.Read(header.stride);
        success = success && block_buffer.Read(header.usage);
        success = success && block_buffer.Read(header.layers);
        success = success && block_buffer.Read(header.planes);

        if (success)
        {
            std::vector<format::HardwareBufferPlaneInfo> entries;

            for (uint64_t i = 0; i < header.planes; ++i)
            {
                format::HardwareBufferPlaneInfo entry;

                if (!block_buffer.Read(entry))
                {
                    success = false;
                    break;
                }

                entries.emplace_back(std::move(entry));
            }

            if (success)
            {
                // This command does not support compression.
                return MakeIncompressibleParsedBlock(block_buffer,
                                                     CreateHardwareBufferArgs{ meta_data_id,
                                                                               header.thread_id,
                                                                               0u,
                                                                               header.memory_id,
                                                                               header.buffer_id,
                                                                               header.format,
                                                                               header.width,
                                                                               header.height,
                                                                               header.stride,
                                                                               header.usage,
                                                                               header.layers,
                                                                               std::move(entries) });
            }
            else
            {
                HandleBlockReadError(kErrorReadingBlockData, "Failed to read create hardware buffer meta-data block");
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read create hardware buffer meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kCreateHardwareBufferCommand_deprecated2)
    {
        format::CreateHardwareBufferCommandHeader_deprecated2 header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.memory_id);
        success = success && block_buffer.Read(header.buffer_id);
        success = success && block_buffer.Read(header.format);
        success = success && block_buffer.Read(header.width);
        success = success && block_buffer.Read(header.height);
        success = success && block_buffer.Read(header.stride);
        success = success && block_buffer.Read(header.usage);
        success = success && block_buffer.Read(header.layers);
        success = success && block_buffer.Read(header.planes);

        if (success)
        {
            std::vector<format::HardwareBufferPlaneInfo> entries;

            for (uint64_t i = 0; i < header.planes; ++i)
            {
                format::HardwareBufferPlaneInfo entry;

                if (!block_buffer.Read(entry))
                {
                    success = false;
                    break;
                }

                entries.emplace_back(std::move(entry));
            }

            if (success)
            {
                // This command does not support compression.
                return MakeIncompressibleParsedBlock(block_buffer,
                                                     CreateHardwareBufferArgs{ meta_data_id,
                                                                               header.thread_id,
                                                                               0u,
                                                                               header.memory_id,
                                                                               header.buffer_id,
                                                                               header.format,
                                                                               header.width,
                                                                               header.height,
                                                                               header.stride,
                                                                               header.usage,
                                                                               header.layers,
                                                                               std::move(entries) });
            }
            else
            {
                HandleBlockReadError(kErrorReadingBlockData, "Failed to read create hardware buffer meta-data block");
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

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.device_id);
        success = success && block_buffer.Read(header.memory_id);
        success = success && block_buffer.Read(header.buffer_id);
        success = success && block_buffer.Read(header.format);
        success = success && block_buffer.Read(header.width);
        success = success && block_buffer.Read(header.height);
        success = success && block_buffer.Read(header.stride);
        success = success && block_buffer.Read(header.usage);
        success = success && block_buffer.Read(header.layers);
        success = success && block_buffer.Read(header.planes);

        if (success)
        {
            std::vector<format::HardwareBufferPlaneInfo> entries;

            for (uint64_t i = 0; i < header.planes; ++i)
            {
                format::HardwareBufferPlaneInfo entry;

                if (!block_buffer.Read(entry))
                {
                    success = false;
                    break;
                }

                entries.emplace_back(std::move(entry));
            }

            if (success)
            {
                // This command does not support compression.
                return MakeIncompressibleParsedBlock(block_buffer,
                                                     CreateHardwareBufferArgs{ meta_data_id,
                                                                               header.thread_id,
                                                                               header.device_id,
                                                                               header.memory_id,
                                                                               header.buffer_id,
                                                                               header.format,
                                                                               header.width,
                                                                               header.height,
                                                                               header.stride,
                                                                               header.usage,
                                                                               header.layers,
                                                                               std::move(entries) });
            }
            else
            {
                HandleBlockReadError(kErrorReadingBlockData, "Failed to read create hardware buffer meta-data block");
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

        success = block_buffer.Read(command.thread_id);
        success = success && block_buffer.Read(command.buffer_id);

        if (success)
        {
            // This command does not support compression.
            return MakeIncompressibleParsedBlock(
                block_buffer, DestroyHardwareBufferArgs{ meta_data_id, command.thread_id, command.buffer_id });
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read destroy hardware buffer meta-data block");
        }
    }
    else if (meta_data_type == format::MetaDataType::kCreateHeapAllocationCommand)
    {
        format::CreateHeapAllocationCommand header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.allocation_id);
        success = success && block_buffer.Read(header.allocation_size);

        if (success)
        {

            // This command does not support compression.
            return MakeIncompressibleParsedBlock(
                block_buffer,
                CreateHeapAllocationArgs{
                    meta_data_id, header.thread_id, header.allocation_id, header.allocation_size });
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read create heap allocation meta-data block");
        }
    }
    else if (meta_data_type == format::MetaDataType::kSetDevicePropertiesCommand)
    {
        format::SetDevicePropertiesCommand header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.physical_device_id);
        success = success && block_buffer.Read(header.api_version);
        success = success && block_buffer.Read(header.driver_version);
        success = success && block_buffer.Read(header.vendor_id);
        success = success && block_buffer.Read(header.device_id);
        success = success && block_buffer.Read(header.device_type);
        success = success && block_buffer.ReadBytes(&header.pipeline_cache_uuid, format::kUuidSize);
        success = success && block_buffer.Read(header.device_name_len);

        if (success)
        {
            char device_name[format::kMaxPhysicalDeviceNameSize];

            if (header.device_name_len < format::kMaxPhysicalDeviceNameSize)
            {
                success = success && block_buffer.ReadBytes(&device_name, header.device_name_len);
                device_name[header.device_name_len] = '\0';
            }

            if (success)
            {
                // This command does not support compression.
                return MakeIncompressibleParsedBlock(block_buffer,
                                                     SetDevicePropertiesArgs(meta_data_id,
                                                                             header.thread_id,
                                                                             header.physical_device_id,
                                                                             header.api_version,
                                                                             header.driver_version,
                                                                             header.vendor_id,
                                                                             header.device_id,
                                                                             header.device_type,
                                                                             header.pipeline_cache_uuid,
                                                                             device_name));
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
        format::SetDeviceMemoryPropertiesCommand header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.physical_device_id);
        success = success && block_buffer.Read(header.memory_type_count);
        success = success && block_buffer.Read(header.memory_heap_count);

        if (success)
        {
            std::vector<format::DeviceMemoryType> types;
            std::vector<format::DeviceMemoryHeap> heaps;

            for (uint32_t i = 0; i < header.memory_type_count; ++i)
            {
                format::DeviceMemoryType type;

                if (!block_buffer.Read(type))
                {
                    success = false;
                    break;
                }

                types.emplace_back(std::move(type));
            }

            for (uint32_t i = 0; i < header.memory_heap_count; ++i)
            {
                format::DeviceMemoryHeap heap;

                if (!block_buffer.Read(heap))
                {
                    success = false;
                    break;
                }

                heaps.emplace_back(std::move(heap));
            }

            if (success)
            {
                // This command does not support compression.
                return MakeIncompressibleParsedBlock(
                    block_buffer,
                    SetDeviceMemoryPropertiesArgs{
                        meta_data_id, header.thread_id, header.physical_device_id, types, std::move(heaps) });
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
        format::SetOpaqueAddressCommand header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.device_id);
        success = success && block_buffer.Read(header.object_id);
        success = success && block_buffer.Read(header.address);

        if (success)
        {
            // This command does not support compression.
            return MakeIncompressibleParsedBlock(
                block_buffer,
                SetOpaqueAddressArgs{
                    meta_data_id, header.thread_id, header.device_id, header.object_id, header.address });
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read set opaque address meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kSetRayTracingShaderGroupHandlesCommand)
    {
        format::SetRayTracingShaderGroupHandlesCommandHeader header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.device_id);
        success = success && block_buffer.Read(header.pipeline_id);
        success = success && block_buffer.Read(header.data_size);

        // Read variable size shader group handle data into parameter_data.
        BlockBuffer::BlockSpan parameter_data;
        if (success)
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, header.data_size);
            size_t data_size = static_cast<size_t>(header.data_size);
            parameter_data   = block_buffer.ReadSpan(data_size);
            success          = parameter_data.size() == data_size;
        }

        if (success)
        {
            // This command does not support compression.
            return MakeIncompressibleParsedBlock(
                block_buffer,
                SetRayTracingShaderGroupHandlesArgs{ meta_data_id,
                                                     header.thread_id,
                                                     header.device_id,
                                                     header.pipeline_id,
                                                     static_cast<size_t>(header.data_size),
                                                     reinterpret_cast<const uint8_t*>(parameter_data.data()) },
                true /* references block buffer */);
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read set ray tracing shader group handles meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kSetSwapchainImageStateCommand)
    {
        format::SetSwapchainImageStateCommandHeader header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.device_id);
        success = success && block_buffer.Read(header.swapchain_id);
        success = success && block_buffer.Read(header.last_presented_image);
        success = success && block_buffer.Read(header.image_info_count);

        if (success)
        {
            std::vector<format::SwapchainImageStateInfo> entries;

            for (uint32_t i = 0; i < header.image_info_count; ++i)
            {
                format::SwapchainImageStateInfo entry;

                if (!block_buffer.Read(entry))
                {
                    success = false;
                    break;
                }

                entries.emplace_back(std::move(entry));
            }

            if (success)
            {
                // This command does not support compression.
                return MakeIncompressibleParsedBlock(block_buffer,
                                                     SetSwapchainImageStateArgs{ meta_data_id,
                                                                                 header.thread_id,
                                                                                 header.device_id,
                                                                                 header.swapchain_id,
                                                                                 header.last_presented_image,
                                                                                 std::move(entries) });
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
        format::BeginResourceInitCommand header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.device_id);
        success = success && block_buffer.Read(header.total_copy_size);
        success = success && block_buffer.Read(header.max_copy_size);

        if (success)
        {
            // This command does not support compression.
            return MakeIncompressibleParsedBlock(
                block_buffer,
                BeginResourceInitArgs{
                    meta_data_id, header.thread_id, header.device_id, header.total_copy_size, header.max_copy_size });
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read begin resource init meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kEndResourceInitCommand)
    {
        format::EndResourceInitCommand header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.device_id);

        if (success)
        {
            // This command does not support compression.
            return MakeIncompressibleParsedBlock(
                block_buffer, EndResourceInitArgs{ meta_data_id, header.thread_id, header.device_id });
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read end resource init meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kInitBufferCommand)
    {
        format::InitBufferCommandHeader header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.device_id);
        success = success && block_buffer.Read(header.buffer_id);
        success = success && block_buffer.Read(header.data_size);

        if (success)
        {
            const char*         label       = "init buffer data meta-data block";
            ParameterReadResult read_result = ReadParameterBuffer(label, block_buffer, header.data_size);
            if (read_result.success)
            {
                return MakeCompressibleParsedBlock(
                    block_buffer,
                    read_result,
                    InitBufferArgs{ meta_data_id,
                                    header.thread_id,
                                    header.device_id,
                                    header.buffer_id,
                                    header.data_size,
                                    reinterpret_cast<const uint8_t*>(read_result.buffer.data()) });
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

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.device_id);
        success = success && block_buffer.Read(header.image_id);
        success = success && block_buffer.Read(header.data_size);
        success = success && block_buffer.Read(header.aspect);
        success = success && block_buffer.Read(header.layout);
        success = success && block_buffer.Read(header.level_count);

        if (success && (header.level_count > 0))
        {
            level_sizes.resize(header.level_count);
            success =
                success && block_buffer.ReadBytes(level_sizes.data(), header.level_count * sizeof(level_sizes[0]));
        }

        if (success)
        {
            const char*         label       = "init image data meta-data block";
            ParameterReadResult read_result = ReadParameterBuffer(label, block_buffer, header.data_size);
            assert(header.data_size == std::accumulate(level_sizes.begin(), level_sizes.end(), 0ull));

            if (read_result.success)
            {
                return MakeCompressibleParsedBlock(
                    block_buffer,
                    read_result,
                    InitImageArgs{ meta_data_id,
                                   header.thread_id,
                                   header.device_id,
                                   header.image_id,
                                   header.data_size,
                                   header.aspect,
                                   header.layout,
                                   level_sizes,
                                   reinterpret_cast<const uint8_t*>(read_result.buffer.data()) });
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read init image data meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kInitSubresourceCommand)
    {
        format::InitSubresourceCommandHeader header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.device_id);
        success = success && block_buffer.Read(header.resource_id);
        success = success && block_buffer.Read(header.subresource);
        success = success && block_buffer.Read(header.initial_state);
        success = success && block_buffer.Read(header.resource_state);
        success = success && block_buffer.Read(header.barrier_flags);
        success = success && block_buffer.Read(header.data_size);

        if (success)
        {
            const char*         label       = "init subresource data meta-data block";
            ParameterReadResult read_result = ReadParameterBuffer(label, block_buffer, header.data_size);

            if (read_result.success)
            {
                return MakeCompressibleParsedBlock(
                    block_buffer,
                    read_result,
                    InitSubresourceArgs{
                        meta_data_id, header, reinterpret_cast<const uint8_t*>(read_result.buffer.data()) });
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
        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.dest_acceleration_structure_data);
        success = success && block_buffer.Read(header.copy_source_gpu_va);
        success = success && block_buffer.Read(header.copy_mode);
        success = success && block_buffer.Read(header.inputs_type);
        success = success && block_buffer.Read(header.inputs_flags);
        success = success && block_buffer.Read(header.inputs_num_instance_descs);
        success = success && block_buffer.Read(header.inputs_num_geometry_descs);
        success = success && block_buffer.Read(header.inputs_data_size);

        // Parse geometry descs.
        std::vector<format::InitDx12AccelerationStructureGeometryDesc> geom_descs;
        if (success)
        {
            for (uint32_t i = 0; i < header.inputs_num_geometry_descs; ++i)
            {
                format::InitDx12AccelerationStructureGeometryDesc geom_desc;
                success = success && block_buffer.Read(geom_desc.geometry_type);
                success = success && block_buffer.Read(geom_desc.geometry_flags);
                success = success && block_buffer.Read(geom_desc.aabbs_count);
                success = success && block_buffer.Read(geom_desc.aabbs_stride);
                success = success && block_buffer.Read(geom_desc.triangles_has_transform);
                success = success && block_buffer.Read(geom_desc.triangles_index_format);
                success = success && block_buffer.Read(geom_desc.triangles_vertex_format);
                success = success && block_buffer.Read(geom_desc.triangles_index_count);
                success = success && block_buffer.Read(geom_desc.triangles_vertex_count);
                success = success && block_buffer.Read(geom_desc.triangles_vertex_stride);
                geom_descs.push_back(geom_desc);
            }
        }

        BlockBuffer::BlockSpan parameter_data;
        if (success)
        {
            const char*         label       = "init DX12 acceleration structure meta-data block";
            ParameterReadResult read_result = ReadParameterBuffer(label, block_buffer, header.inputs_data_size);
            if (read_result.success)
            {
                return MakeCompressibleParsedBlock(
                    block_buffer,
                    read_result,
                    InitDx12AccelerationStructureArgs{ meta_data_id,
                                                       read_result.uncompressed_size,
                                                       header,
                                                       geom_descs,
                                                       reinterpret_cast<const uint8_t*>(read_result.buffer.data()) });
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

        success = block_buffer.Read(adapter_info_header.thread_id);

        success = success && block_buffer.Read(adapter_info_header.adapter_desc.Description);
        success = success && block_buffer.Read(adapter_info_header.adapter_desc.VendorId);
        success = success && block_buffer.Read(adapter_info_header.adapter_desc.DeviceId);
        success = success && block_buffer.Read(adapter_info_header.adapter_desc.SubSysId);
        success = success && block_buffer.Read(adapter_info_header.adapter_desc.Revision);
        success = success && block_buffer.Read(adapter_info_header.adapter_desc.DedicatedVideoMemory);
        success = success && block_buffer.Read(adapter_info_header.adapter_desc.DedicatedSystemMemory);
        success = success && block_buffer.Read(adapter_info_header.adapter_desc.SharedSystemMemory);
        success = success && block_buffer.Read(adapter_info_header.adapter_desc.LuidLowPart);
        success = success && block_buffer.Read(adapter_info_header.adapter_desc.LuidHighPart);
        success = success && block_buffer.Read(adapter_info_header.adapter_desc.extra_info);

        if (success)
        {
            // This command does not support compression.
            return MakeIncompressibleParsedBlock(block_buffer, GetDxgiAdapterArgs{ meta_data_id, adapter_info_header });
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

        success = block_buffer.Read(dx12_runtime_info_header.thread_id);
        success = success && block_buffer.Read(dx12_runtime_info_header.runtime_info.version);
        success = success && block_buffer.Read(dx12_runtime_info_header.runtime_info.src);

        if (success)
        {
            // This command does not support compression.
            return MakeIncompressibleParsedBlock(block_buffer,
                                                 GetDx12RuntimeArgs{ meta_data_id, dx12_runtime_info_header });
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read runtime info meta-data block");
        }
    }
    else if (meta_data_type == format::MetaDataType::kParentToChildDependency)
    {
        format::ParentToChildDependencyHeader header;
        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.dependency_type);
        success = success && block_buffer.Read(header.parent_id);
        success = success && block_buffer.Read(header.child_count);

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
                        success = success && block_buffer.Read(blases[i]);
                    }

                    if (success)
                    {
                        // This command does not support compression.
                        return MakeIncompressibleParsedBlock(
                            block_buffer,
                            SetTlasToBlasDependencyArgs{ meta_data_id, header.parent_id, std::move(blases) });
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
        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.string_length);
        if (!success)
        {
            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read environment variable block header");
            return ParsedBlock(ParsedBlock::InvalidBlockTag());
        }

        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, header.string_length);
        const size_t           data_size      = static_cast<size_t>(header.string_length);
        BlockBuffer::BlockSpan parameter_data = block_buffer.ReadSpan(data_size);
        success                               = parameter_data.size() == data_size;

        if (!success)
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read environment variable block data");
            return ParsedBlock(ParsedBlock::InvalidBlockTag());
        }

        const char* env_string = reinterpret_cast<const char*>(parameter_data.data());
        // This command does not support compression.
        return MakeIncompressibleParsedBlock(block_buffer,
                                             SetEnvironmentVariablesArgs{ meta_data_id, header, env_string },
                                             true /* references block buffer */);
    }
    else if (meta_data_type == format::MetaDataType::kVulkanBuildAccelerationStructuresCommand)
    {
        format::VulkanMetaBuildAccelerationStructuresHeader header{};
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
        const size_t           parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(meta_data_id);
        BlockBuffer::BlockSpan parameter_data        = block_buffer.ReadSpan(parameter_buffer_size);
        success                                      = parameter_data.size() == parameter_buffer_size;

        if (success)
        {
            // This command does not support compression.
            return MakeIncompressibleParsedBlock(
                block_buffer,
                VulkanAccelerationStructuresBuildMetaArgs{
                    meta_data_id, reinterpret_cast<const uint8_t*>(parameter_data.data()), parameter_buffer_size },
                true /* references block buffer */);
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read acceleration structure init meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kVulkanCopyAccelerationStructuresCommand)
    {
        format::VulkanCopyAccelerationStructuresCommandHeader header{};
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
        const size_t           parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(meta_data_id);
        BlockBuffer::BlockSpan parameter_data        = block_buffer.ReadSpan(parameter_buffer_size);
        success                                      = parameter_data.size() == parameter_buffer_size;

        if (success)
        {
            // This command does not support compression.
            return MakeIncompressibleParsedBlock(
                block_buffer,
                VulkanAccelerationStructuresCopyMetaArgs{
                    meta_data_id, reinterpret_cast<const uint8_t*>(parameter_data.data()), parameter_buffer_size },
                true /* references block buffer */);
        }
    }
    else if (meta_data_type == format::MetaDataType::kVulkanWriteAccelerationStructuresPropertiesCommand)
    {
        format::VulkanCopyAccelerationStructuresCommandHeader header{};
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
        const size_t           parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(meta_data_id);
        BlockBuffer::BlockSpan parameter_data        = block_buffer.ReadSpan(parameter_buffer_size);
        success                                      = parameter_data.size() == parameter_buffer_size;

        if (success)
        {
            // This command does not support compression.
            return MakeIncompressibleParsedBlock(
                block_buffer,
                VulkanAccelerationStructuresWritePropertiesMetaArgs{
                    meta_data_id, reinterpret_cast<const uint8_t*>(parameter_data.data()), parameter_buffer_size },
                true /* references block buffer */);
        }
    }
    else if (meta_data_type == format::MetaDataType::kExecuteBlocksFromFile)
    {
        format::ExecuteBlocksFromFile exec_from_file;
        success = block_buffer.Read(exec_from_file.thread_id);
        success = success && block_buffer.Read(exec_from_file.n_blocks);
        success = success && block_buffer.Read(exec_from_file.offset);
        success = success && block_buffer.Read(exec_from_file.filename_length);

        if (success)
        {
            std::string filename_c_str(exec_from_file.filename_length, '\0');
            success = success && block_buffer.ReadBytes(filename_c_str.data(), exec_from_file.filename_length);
            if (success)
            {
                if (success)
                {
                    // This command does not support compression.
                    return MakeIncompressibleParsedBlock(block_buffer,
                                                         ExecuteBlocksFromFileArgs{ meta_data_id,
                                                                                    exec_from_file.thread_id,
                                                                                    exec_from_file.n_blocks,
                                                                                    exec_from_file.offset,
                                                                                    std::move(filename_c_str) });
                }
            }
        }

        if (!success)
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read runtime info meta-data block");
        }
    }
    else if (meta_data_type == format::MetaDataType::kViewRelativeLocation)
    {
        format::ViewRelativeLocation Location;
        format::ThreadId             thread_id;
        success = block_buffer.Read(thread_id);

        format::ViewRelativeLocation location;
        if (success)
        {
            success = block_buffer.Read(location);
        }

        if (success)
        {
            // This command does not support compression.
            return MakeIncompressibleParsedBlock(block_buffer,
                                                 ViewRelativeLocationArgs{ meta_data_id, thread_id, location });
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to ViewRelativeLocation meta-data block");
        }
    }
    else if (meta_data_type == format::MetaDataType::kInitializeMetaCommand)
    {
        format::InitializeMetaCommand header;

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.capture_id);
        success = success && block_buffer.Read(header.block_index);
        success = success && block_buffer.Read(header.total_number_of_initializemetacommand);
        success = success && block_buffer.Read(header.data_size);

        if (success)
        {
            const char*         label       = "init subresource data meta-data block";
            ParameterReadResult read_result = ReadParameterBuffer(label, block_buffer, header.data_size);

            if (read_result.success)
            {
                return MakeCompressibleParsedBlock(
                    block_buffer,
                    read_result,
                    InitializeMetaArgs{
                        meta_data_id, header, reinterpret_cast<const uint8_t*>(read_result.buffer.data()) });
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read init subresource data meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kSetOpaqueCaptureDescriptorDataCommand)
    {
        // This command does not support compression.
        GFXRECON_ASSERT(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::SetOpaqueDescriptorDataCommand header{};

        success = block_buffer.Read(header.thread_id);
        success = success && block_buffer.Read(header.device_id);
        success = success && block_buffer.Read(header.object_id);
        success = success && block_buffer.Read(header.data_size);

        if (success)
        {
            const char*         label       = "fill opaque descriptor-data block";
            ParameterReadResult read_result = ReadParameterBuffer(label, block_buffer, header.data_size);

            return MakeIncompressibleParsedBlock(
                block_buffer,
                SetOpaqueDescriptorDataArgs{ meta_data_id,
                                             header.thread_id,
                                             header.device_id,
                                             header.object_id,
                                             header.data_size,
                                             reinterpret_cast<const uint8_t*>(read_result.buffer.data()) },
                true /* references block buffer */);
        }

        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read set opaque address meta-data block header");
    }
    else
    {
        if (meta_data_type >= format::MetaDataType::kBeginExperimentalReservedRange ||
            meta_data_type == format::MetaDataType::kReserved23 || meta_data_type == format::MetaDataType::kReserved25)
        {
            // Only log a warning once if the capture file contains blocks that are a "reserved" meta data type.
            GFXRECON_LOG_WARNING_ONCE("This capture file contains meta-data block(s) with reserved type(s) that are "
                                      "not supported. Unsupported meta-data block types will be skipped.");
        }
        else
        {
            // Unrecognized metadata type.
            WarnUnknownBlock(block_buffer, "meta-data block", static_cast<uint32_t>(meta_data_type));
        }

        // Handle unsupported meta-data block.
        if (!format::IsBlockCompressed(block_header.type))
        {
            // Without the ability to parse the block, the uncompressed size cannot be determined, nor can the
            // beginning of the parameter buffer. Thus only uncompressed, unknown meta-data blocks can safely
            // be passed through, even as unknown.
            //
            // A warning has been generated above
            return ParsedBlock(ParsedBlock::UnknownBlockTag(), block_buffer.ReleaseData());
        }
        else
        {
            HandleBlockReadError(kErrorUnsupportedBlockType,
                                 "Unrecognized compressed meta-data block type is not supported");
        }
    }

    return ParsedBlock(ParsedBlock::InvalidBlockTag());
}

ParsedBlock BlockParser::ParseFrameMarker(BlockBuffer& block_buffer)
{
    // The caller is responsible for reading the block and parsing the header
    GFXRECON_ASSERT(block_buffer.ReadPos() == sizeof(format::BlockHeader));
    const format::BlockHeader& block_header = block_buffer.Header();
    format::MarkerType         marker_type  = format::MarkerType::kUnknownMarker;

    bool success = block_buffer.Read(marker_type);
    if (!success)
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read frame marker block header");
        return ParsedBlock(ParsedBlock::InvalidBlockTag());
    }

    // Read the rest of the frame marker data. Currently frame markers are not dispatched to decoders.
    uint64_t frame_number = 0;
    success               = success && block_buffer.Read(frame_number);

    if (success)
    {
        // Unlike most blocks, only one subtype results in a dispatchable command
        if (marker_type == format::kEndMarker)
        {
            // This command does not support compression.
            return MakeIncompressibleParsedBlock(block_buffer, FrameEndMarkerArgs{ frame_number });
        }
        else
        {
            WarnUnknownBlock(block_buffer, "frame marker", static_cast<uint32_t>(marker_type));
            return ParsedBlock(ParsedBlock::UnknownBlockTag(), block_buffer.ReleaseData());
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockData, "Failed to read frame marker data");
    }

    return ParsedBlock(ParsedBlock::InvalidBlockTag());
}

ParsedBlock BlockParser::ParseStateMarker(BlockBuffer& block_buffer)
{
    // The caller is responsible for reading the block and parsing the header
    GFXRECON_ASSERT(block_buffer.ReadPos() == sizeof(format::BlockHeader));
    const format::BlockHeader& block_header = block_buffer.Header();
    format::MarkerType         marker_type  = format::MarkerType::kUnknownMarker;

    bool success = block_buffer.Read(marker_type);
    if (!success)
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read state marker block header");
        return ParsedBlock(ParsedBlock::InvalidBlockTag());
    }

    uint64_t frame_number = 0;
    success               = success && block_buffer.Read(frame_number);

    if (success)
    {
        if (marker_type == format::kBeginMarker)
        {
            // This command does not support compression.
            return MakeIncompressibleParsedBlock(block_buffer, StateBeginMarkerArgs{ frame_number });
        }
        else if (marker_type == format::kEndMarker)
        {
            // This command does not support compression.
            return MakeIncompressibleParsedBlock(block_buffer, StateEndMarkerArgs{ frame_number });
        }
        else
        {
            WarnUnknownBlock(block_buffer, "state marker", static_cast<uint32_t>(marker_type));
            return ParsedBlock(ParsedBlock::UnknownBlockTag(), block_buffer.ReleaseData());
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockData, "Failed to read state marker data");
    }

    return ParsedBlock(ParsedBlock::InvalidBlockTag());
}

ParsedBlock BlockParser::ParseAnnotation(BlockBuffer& block_buffer)
{
    // The caller is responsible for reading the block and parsing the header
    GFXRECON_ASSERT(block_buffer.ReadPos() == sizeof(format::BlockHeader));
    const format::BlockHeader& block_header    = block_buffer.Header();
    format::AnnotationType     annotation_type = format::AnnotationType::kUnknown;

    bool success = block_buffer.Read(annotation_type);
    if (!success)
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read annotation block header");
        return ParsedBlock(ParsedBlock::InvalidBlockTag());
    }

    decltype(format::AnnotationHeader::label_length) label_length = 0;
    decltype(format::AnnotationHeader::data_length)  data_length  = 0;

    success = block_buffer.Read(label_length);
    success = success && block_buffer.Read(data_length);
    if (success)
    {
        if ((label_length > 0) || (data_length > 0))
        {
            std::string label;
            std::string data;
            const auto  size_sum = label_length + data_length;
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size_sum);
            const size_t total_length = static_cast<size_t>(size_sum);

            BlockBuffer::BlockSpan parameter_data = block_buffer.ReadSpan(total_length);
            success                               = parameter_data.size() == total_length;

            if (success)
            {
                if (label_length > 0)
                {
                    const char* label_start = reinterpret_cast<const char*>(parameter_data.data());
                    label.assign(label_start, std::next(label_start, label_length));
                }

                if (data_length > 0)
                {
                    const char* data_start =
                        std::next(reinterpret_cast<const char*>(parameter_data.data()), label_length);
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, data_length);
                    data.assign(data_start, std::next(data_start, static_cast<size_t>(data_length)));
                }

                // This command does not support compression.
                return MakeIncompressibleParsedBlock(
                    block_buffer, AnnotationArgs{ block_index_, annotation_type, std::move(label), std::move(data) });
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

    return ParsedBlock(ParsedBlock::InvalidBlockTag());
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
