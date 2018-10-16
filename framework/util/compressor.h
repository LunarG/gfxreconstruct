/*
** Copyright (c) 2018 LunarG, Inc.
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

#ifndef BRIMSTONE_UTIL_COMPRESSOR_H
#define BRIMSTONE_UTIL_COMPRESSOR_H

#include <inttypes.h>
#include <vector>

#include "util/defines.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(util)

class Compressor
{
  public:
    Compressor() {}

    virtual ~Compressor() {}

    virtual size_t Compress(const size_t          uncompressed_size,
                            const uint8_t*        uncompressed_data,
                            std::vector<uint8_t>* compressed_data) = 0;

    virtual size_t Decompress(const size_t                compressed_size,
                              const std::vector<uint8_t>& compressed_data,
                              const size_t                expected_uncompressed_size,
                              std::vector<uint8_t>*       uncompressed_data) = 0;
};

BRIMSTONE_END_NAMESPACE(util)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_UTIL_COMPRESSOR_H
