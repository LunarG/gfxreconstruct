/*
** Copyright (c) 2020 LunarG, Inc.
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

#ifdef GFXRECON_ENABLE_ZSTD_COMPRESSION

#include "util/zstd_compressor.h"

#include "util/logging.h"

#include "zstd.h"

#include <cinttypes>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

size_t ZstdCompressor::Compress(const size_t          uncompressed_size,
                                const uint8_t*        uncompressed_data,
                                std::vector<uint8_t>* compressed_data,
                                size_t                compressed_data_offset) const
{
    size_t data_size = 0;

    if (nullptr == compressed_data)
    {
        return 0;
    }

    size_t zstd_compressed_size = ZSTD_compressBound(uncompressed_size);

    if ((compressed_data_offset + zstd_compressed_size) > compressed_data->size())
    {
        compressed_data->resize(compressed_data_offset + zstd_compressed_size);
    }

    size_t compressed_size_generated =
        ZSTD_compress(reinterpret_cast<char*>(compressed_data->data() + compressed_data_offset),
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

size_t ZstdCompressor::Decompress(const size_t          compressed_size,
                                  const uint8_t*        compressed_data,
                                  const size_t          expected_uncompressed_size,
                                  std::vector<uint8_t>* uncompressed_data) const
{
    size_t data_size = 0;

    if (nullptr == uncompressed_data)
    {
        return 0;
    }

    size_t uncompressed_size_generated = ZSTD_decompress(reinterpret_cast<char*>(uncompressed_data->data()),
                                                         expected_uncompressed_size,
                                                         reinterpret_cast<const char*>(compressed_data),
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

#endif // GFXRECON_ENABLE_ZSTD_COMPRESSION