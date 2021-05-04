/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#ifndef GFXRECON_UTIL_COMPRESSOR_H
#define GFXRECON_UTIL_COMPRESSOR_H

#include "util/defines.h"

#include <cstddef>
#include <cstdint>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class Compressor
{
  public:
    Compressor() {}

    virtual ~Compressor() {}

    // If needed, compressed_data will be resized to fit the compressed data + compressed_data_offset.
    virtual size_t Compress(const size_t          uncompressed_size,
                            const uint8_t*        uncompressed_data,
                            std::vector<uint8_t>* compressed_data,
                            size_t                compressed_data_offset) = 0;

    virtual size_t Decompress(const size_t                compressed_size,
                              const std::vector<uint8_t>& compressed_data,
                              const size_t                expected_uncompressed_size,
                              std::vector<uint8_t>*       uncompressed_data) = 0;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_COMPRESSOR_H
