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
#include <iostream>
#include <cassert>

#include "util/compressor.h"
#include "util/lz4_compressor.h"
#include "util/lz77_compressor.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(util)

Compressor* Compressor::CreateCompressor(CompressionType type)
{
    switch (type)
    {
        case kLz4:
#ifdef ENABLE_LZ4_COMPRESSION
            return new Lz4Compressor(type);
#endif // ENABLE_LZ4_COMPRESSION
            break;
        case kLz77:
#ifdef ENABLE_LZ77_COMPRESSION
            return new Lz77Compressor(type);
#endif // ENABLE_LZ77_COMPRESSION
            break;
        case kNone:
            // Nothing to do here.
            break;
        default:
            assert(false);
            std::cout << "ERROR: Unsupported compression format!\n";
            break;
    }

    // No supported compression, so return nullptr.
    return nullptr;
}

BRIMSTONE_END_NAMESPACE(util)
BRIMSTONE_END_NAMESPACE(brimstone)
