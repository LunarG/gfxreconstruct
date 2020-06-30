/*
** Copyright (c) 2020 LunarG, Inc.
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

#ifdef ENABLE_ZSTD_COMPRESSION

#include "util/zstd_compressor.h"

#include "util/logging.h"

#include "zstd.h"

#include <cinttypes>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

size_t ZstdCompressor::Compress(const size_t          uncompressed_size,
                                const uint8_t*        uncompressed_data,
                                std::vector<uint8_t>* compressed_data)
{
    size_t data_size = 0;

    if (nullptr == compressed_data)
    {
        return 0;
    }

    size_t zstd_compressed_size = ZSTD_compressBound(uncompressed_size);

    if (zstd_compressed_size > compressed_data->size())
    {
        compressed_data->resize(zstd_compressed_size);
    }

    size_t compressed_size_generated = ZSTD_compress(reinterpret_cast<char*>(compressed_data->data()),
                                                     zstd_compressed_size,
                                                     reinterpret_cast<const char*>(uncompressed_data),
                                                     uncompressed_size,
                                                     1);

    if (!ZSTD_isError(compressed_size_generated))
    {
        data_size = compressed_size_generated;
    }
    else
    {
        GFXRECON_LOG_ERROR("Zstandard compression failed with error %" PRIdPTR, compressed_size_generated);
    }

    return data_size;
}

size_t ZstdCompressor::Decompress(const size_t                compressed_size,
                                  const std::vector<uint8_t>& compressed_data,
                                  const size_t                expected_uncompressed_size,
                                  std::vector<uint8_t>*       uncompressed_data)
{
    size_t data_size = 0;

    if (nullptr == uncompressed_data)
    {
        return 0;
    }

    size_t uncompressed_size_generated = ZSTD_decompress(reinterpret_cast<char*>(uncompressed_data->data()),
                                                         expected_uncompressed_size,
                                                         reinterpret_cast<const char*>(compressed_data.data()),
                                                         compressed_size);

    if (!ZSTD_isError(uncompressed_size_generated))
    {
        data_size = uncompressed_size_generated;
    }
    else
    {
        GFXRECON_LOG_ERROR("Zstandard decompression failed with error %" PRIdPTR, uncompressed_size_generated);
    }

    return data_size;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_ZSTD_COMPRESSION