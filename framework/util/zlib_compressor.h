/*
** Copyright (c) 2018-2019 Valve Corporation
** Copyright (c) 2018-2019 LunarG, Inc.
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

#ifndef GFXRECON_UTIL_ZLIB_COMPRESSOR_H
#define GFXRECON_UTIL_ZLIB_COMPRESSOR_H

#include "util/compressor.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class ZlibCompressor : public Compressor
{
  public:
    ZlibCompressor() {}

    virtual ~ZlibCompressor() override {}

    virtual size_t Compress(const size_t          uncompressed_size,
                            const uint8_t*        uncompressed_data,
                            std::vector<uint8_t>* compressed_data) override;

    virtual size_t Decompress(const size_t                compressed_size,
                              const std::vector<uint8_t>& compressed_data,
                              const size_t                expected_uncompressed_size,
                              std::vector<uint8_t>*       uncompressed_data) override;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_ZLIB_COMPRESSOR_H
