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

#ifdef ENABLE_ZLIB_COMPRESSION

#include "util/zlib_compressor.h"

#include "zlib.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

size_t ZlibCompressor::Compress(const size_t          uncompressed_size,
                                const uint8_t*        uncompressed_data,
                                std::vector<uint8_t>* compressed_data)
{
    size_t copy_size = 0;

    if (nullptr == compressed_data)
    {
        return 0;
    }

    if (compressed_data->size() < uncompressed_size)
    {
        compressed_data->resize(uncompressed_size);
    }

    z_stream compress_stream = {};
    compress_stream.zalloc   = Z_NULL;
    compress_stream.zfree    = Z_NULL;
    compress_stream.opaque   = Z_NULL;

    GFXRECON_CHECK_CONVERSION_DATA_LOSS(uInt, uncompressed_size);
    compress_stream.avail_in = static_cast<uInt>(uncompressed_size);
    compress_stream.next_in  = const_cast<Bytef*>(uncompressed_data);

    GFXRECON_CHECK_CONVERSION_DATA_LOSS(uInt, compressed_data->size());
    compress_stream.avail_out = static_cast<uInt>(compressed_data->size());
    compress_stream.next_out  = compressed_data->data();

    // Perform the compression (deflate the data).
    deflateInit(&compress_stream, Z_BEST_COMPRESSION);
    deflate(&compress_stream, Z_FINISH);
    deflateEnd(&compress_stream);

    // Determine the size of data from the stream
    copy_size = compress_stream.total_out;

    return copy_size;
}

size_t ZlibCompressor::Decompress(const size_t                compressed_size,
                                  const std::vector<uint8_t>& compressed_data,
                                  const size_t                expected_uncompressed_size,
                                  std::vector<uint8_t>*       uncompressed_data)
{
    size_t copy_size = 0;

    if (nullptr == uncompressed_data)
    {
        return 0;
    }

    z_stream decompress_stream = {};
    decompress_stream.zalloc   = Z_NULL;
    decompress_stream.zfree    = Z_NULL;
    decompress_stream.opaque   = Z_NULL;

    GFXRECON_CHECK_CONVERSION_DATA_LOSS(uInt, compressed_size);
    decompress_stream.avail_in = static_cast<uInt>(compressed_size);
    decompress_stream.next_in  = const_cast<Bytef*>(compressed_data.data());

    GFXRECON_CHECK_CONVERSION_DATA_LOSS(uInt, expected_uncompressed_size);
    decompress_stream.avail_out = static_cast<uInt>(expected_uncompressed_size);
    decompress_stream.next_out  = uncompressed_data->data();

    // Perform the decompression (inflate the data).
    inflateInit(&decompress_stream);
    inflate(&decompress_stream, Z_NO_FLUSH);
    inflateEnd(&decompress_stream);

    // Determine the size of data from the stream
    copy_size = decompress_stream.total_out;

    return copy_size;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_ZLIB_COMPRESSION
