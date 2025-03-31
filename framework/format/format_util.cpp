/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#include "format/format_util.h"

#include "util/logging.h"
#include "util/lz4_compressor.h"
#include "util/zlib_compressor.h"
#include "util/zstd_compressor.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(format)

bool ValidateFileHeader(const FileHeader& header)
{
    bool valid = true;

    if (header.fourcc != GFXRECON_FOURCC)
    {
        GFXRECON_LOG_ERROR("Invalid file: File header does not contain the expected unrecognized four character code.");
        valid = false;
    }

    // TODO: Verify version is supported.

    return valid;
}

util::Compressor* CreateCompressor(CompressionType type)
{
    util::Compressor* compressor = nullptr;

    switch (type)
    {
        case kLz4:
#if defined(GFXRECON_ENABLE_LZ4_COMPRESSION)
            compressor = new util::Lz4Compressor();
#else
            GFXRECON_LOG_ERROR(
                "Failed to initialize compression module: Application was built with LZ4 compression disabled.");
#endif // GFXRECON_ENABLE_LZ4_COMPRESSION
            break;
        case kZlib:
#if defined(GFXRECON_ENABLE_ZLIB_COMPRESSION)
            compressor = new util::ZlibCompressor();
#else
            GFXRECON_LOG_ERROR(
                "Failed to initialize compression module: Application was built with zlib compression disabled.");
#endif // GFXRECON_ENABLE_ZLIB_COMPRESSION
            break;
        case kZstd:
#if defined(GFXRECON_ENABLE_ZSTD_COMPRESSION)
            compressor = new util::ZstdCompressor();
#else
            GFXRECON_LOG_ERROR(
                "Failed to initialize compression module: Application was built with Zstandard compression disabled.");
#endif // GFXRECON_ENABLE_ZSTD_COMPRESSION
            break;
        case kNone:
            // Nothing to do here.
            break;
        default:
            GFXRECON_LOG_ERROR("Failed to initialize compression module: Unrecognized compression type ID %d", type);
            break;
    }

    return compressor;
}

std::string GetCompressionTypeName(CompressionType type)
{
    switch (type)
    {
        case kLz4:
            return "LZ4";
        case kZlib:
            return "zlib";
        case kZstd:
            return "Zstandard";
        case kNone:
            return "None";
        default:
            break;
    }

    return "";
}

format::function_call_block_t CreateFunctionCallBlock(format::ApiCallId               call_id,
                                                      format::ThreadId                thread_id,
                                                      const util::MemoryOutputStream* parameter_buffer,
                                                      util::Compressor*               compressor,
                                                      std::vector<uint8_t>*           compressor_scratch_space)
{
    GFXRECON_ASSERT(parameter_buffer != nullptr);

    function_call_block_t result{};
    bool                  not_compressed    = true;
    size_t                uncompressed_size = parameter_buffer->GetDataSize();

    if (compressor != nullptr && compressor_scratch_space != nullptr)
    {
        size_t packet_size = 0;
        size_t compressed_size =
            compressor->Compress(uncompressed_size, parameter_buffer->GetData(), compressor_scratch_space, 0);

        if ((compressed_size > 0) && (compressed_size < uncompressed_size))
        {
            auto* compressed_header = reinterpret_cast<format::CompressedFunctionCallHeader*>(result.header);
            result.data             = reinterpret_cast<const void*>(compressor_scratch_space->data());
            result.data_size        = compressed_size;
            result.header_size      = sizeof(format::CompressedFunctionCallHeader);

            compressed_header->block_header.type = format::BlockType::kCompressedFunctionCallBlock;
            compressed_header->api_call_id       = call_id;
            compressed_header->thread_id         = thread_id;
            compressed_header->uncompressed_size = uncompressed_size;

            packet_size += sizeof(compressed_header->api_call_id) + sizeof(compressed_header->uncompressed_size) +
                           sizeof(compressed_header->thread_id) + compressed_size;

            compressed_header->block_header.size = packet_size;
            not_compressed                       = false;
        }
    }

    if (not_compressed)
    {
        auto* uncompressed_header = reinterpret_cast<format::FunctionCallHeader*>(result.header);
        result.data               = reinterpret_cast<const void*>(parameter_buffer->GetData());
        result.data_size          = uncompressed_size;
        result.header_size        = sizeof(format::FunctionCallHeader);

        uncompressed_header->block_header.type = format::BlockType::kFunctionCallBlock;
        uncompressed_header->api_call_id       = call_id;
        uncompressed_header->thread_id         = thread_id;

        size_t packet_size =
            sizeof(uncompressed_header->api_call_id) + sizeof(uncompressed_header->thread_id) + result.data_size;

        uncompressed_header->block_header.size = packet_size;
    }
    return result;
}

GFXRECON_END_NAMESPACE(format)
GFXRECON_END_NAMESPACE(gfxrecon)
