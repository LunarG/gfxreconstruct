/*
** Copyright (c) 2018,2020 Valve Corporation
** Copyright (c) 2018,2020 LunarG, Inc.
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

#ifdef GFXRECON_ENABLE_LZ4_COMPRESSION

#include "util/lz4_compressor.h"

#include "util/logging.h"

#include "lz4.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

size_t Lz4Compressor::Compress(const size_t          uncompressed_size,
                               const uint8_t*        uncompressed_data,
                               std::vector<uint8_t>* compressed_data,
                               size_t                compressed_data_offset) const
{
    size_t data_size = 0;

    if (nullptr == compressed_data)
    {
        return 0;
    }

    size_t lz4_compressed_size = LZ4_COMPRESSBOUND(uncompressed_size);

    if ((compressed_data_offset + lz4_compressed_size) > compressed_data->size())
    {
        compressed_data->resize(compressed_data_offset + lz4_compressed_size);
    }

    int compressed_size_generated =
        LZ4_compress_fast(reinterpret_cast<const char*>(uncompressed_data),
                          reinterpret_cast<char*>(compressed_data->data() + compressed_data_offset),
                          static_cast<int32_t>(uncompressed_size),
                          static_cast<int32_t>(lz4_compressed_size),
                          1);

    if (compressed_size_generated > 0)
    {
        data_size = static_cast<size_t>(compressed_size_generated);
    }

    return data_size;
}

size_t Lz4Compressor::Decompress(const size_t                compressed_size,
                                 const std::vector<uint8_t>& compressed_data,
                                 const size_t                expected_uncompressed_size,
                                 std::vector<uint8_t>*       uncompressed_data) const
{
    size_t data_size = 0;

    if (nullptr == uncompressed_data)
    {
        return 0;
    }

    int uncompressed_size_generated = LZ4_decompress_safe(reinterpret_cast<const char*>(compressed_data.data()),
                                                          reinterpret_cast<char*>(uncompressed_data->data()),
                                                          static_cast<int32_t>(compressed_size),
                                                          static_cast<int32_t>(expected_uncompressed_size));

    if (uncompressed_size_generated > 0)
    {
        data_size = static_cast<size_t>(uncompressed_size_generated);
    }
    else
    {
        GFXRECON_LOG_ERROR("LZ4 decompression failed with error %d", uncompressed_size_generated);
    }

    return data_size;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENABLE_LZ4_COMPRESSION