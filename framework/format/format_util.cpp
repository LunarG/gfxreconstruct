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

// Utilities for format validation.
static bool VersionSupported(const FileHeader& header)
{
    auto file_version = GFXRECON_MAKE_FILE_VERSION(header.major_version, header.minor_version);
    return file_version <= GFXRECON_CURRENT_FILE_VERSION;
}

bool ValidateFileHeader(const FileHeader& header)
{
    bool valid = true;

    if (header.fourcc != GFXRECON_FOURCC)
    {
        GFXRECON_LOG_ERROR("Invalid file: File header does not contain the expected unrecognized four character code.");
        valid = false;
    }
    else if (!VersionSupported(header))
    {

        GFXRECON_LOG_ERROR("Invalid file: File format version %u.%u later than currently supported version %u.%",
                           header.major_version,
                           header.minor_version,
                           GFXRECON_CURRENT_FILE_MAJOR,
                           GFXRECON_CURRENT_FILE_MINOR);
        valid = false;
    }
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

const char* ToString(BlockType type)
{
    switch (type)
    {
        case kFrameMarkerBlock:
            return "frame marker";
        case kStateMarkerBlock:
            return "state marker";
        case kMetaDataBlock:
        case kCompressedMetaDataBlock:
            return "meta-data";
        case kFunctionCallBlock:
        case kCompressedFunctionCallBlock:
            return "function call";
        case kAnnotation:
            return "annotation";
        case kMethodCallBlock:
        case kCompressedMethodCallBlock:
            return "method call";
        case kUnknownBlock:
            return "unknown";
    }
    return "INVALID BLOCK TYPE";
}
GFXRECON_END_NAMESPACE(format)
GFXRECON_END_NAMESPACE(gfxrecon)
