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

#ifdef GFXRECON_ENABLE_ZLIB_COMPRESSION

#include "util/zlib_compressor.h"

#include "zlib.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

size_t ZlibCompressor::Compress(const size_t          uncompressed_size,
                                const uint8_t*        uncompressed_data,
                                std::vector<uint8_t>* compressed_data,
                                size_t                compressed_data_offset) const
{
    size_t copy_size = 0;

    if (nullptr == compressed_data)
    {
        return 0;
    }

    if (compressed_data->size() < (compressed_data_offset + uncompressed_size))
    {
        compressed_data->resize(compressed_data_offset + uncompressed_size);
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
    compress_stream.next_out  = compressed_data->data() + compressed_data_offset;

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
                                  std::vector<uint8_t>*       uncompressed_data) const
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

#endif // GFXRECON_ENABLE_ZLIB_COMPRESSION
