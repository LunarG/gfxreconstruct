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
#ifdef ENABLE_LZ4_COMPRESSION
            compressor = new util::Lz4Compressor();
#else
            GFXRECON_LOG_ERROR("Failed to initialize compression module: LZ4 compression is disabled.");
            assert(false);
#endif // ENABLE_LZ4_COMPRESSION
            break;
        case kZlib:
#ifdef ENABLE_ZLIB_COMPRESSION
            compressor = new util::ZlibCompressor();
#else
            GFXRECON_LOG_ERROR("Failed to initialize compression module: zlib compression is disabled.");
            assert(false);
#endif // ENABLE_ZLIB_COMPRESSION
            break;
        case kZstd:
#ifdef ENABLE_ZSTD_COMPRESSION
            compressor = new util::ZstdCompressor();
#else
            GFXRECON_LOG_ERROR("Failed to initialize compression module: Zstandard compression is disabled.");
            assert(false);
#endif // ENABLE_ZSTD_COMPRESSION
            break;
        case kNone:
            // Nothing to do here.
            break;
        default:
            GFXRECON_LOG_ERROR("Failed to initialize compression module: Unrecognized compression type ID %d", type);
            assert(false);
            break;
    }

    return compressor;
}

GFXRECON_END_NAMESPACE(format)
GFXRECON_END_NAMESPACE(gfxrecon)
